using System;
using System.Collections.Generic;
using System.IO;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using SweetMerge.Authentication;
using SweetMerge.Profile;
using Unity.Services.Authentication;
using Unity.Services.CloudSave;
using Unity.Services.CloudSave.Models;
using Unity.Services.Core;
using UnityEngine;

namespace SweetMerge.Cloud
{
    internal enum KeepDeviceConflictResult
    {
        Completed,
        Cancelled,
        ApprovalChanged,
        OwnershipBlocked,
        CloudCheckFailed,
        UploadFailed,
        OutcomeUnknown,
        RestoreSelected
    }

    internal enum CloudConflictChoice
    {
        KeepDevice,
        RestoreCloud,
        Cancel
    }

    [Serializable]
    public sealed class CloudBackupEnvelope
    {
        public int version = 1;
        public string environment;
        public string playerId;
        public string saveJson;
        public string cafeName;
        public int tutorialStage;
        public string checksum;

        public string ContentHash() => SimpleCloudFiles.Hash(
            JsonUtility.ToJson(new Content { save = saveJson, name = cafeName, stage = tutorialStage }));
        [Serializable] private sealed class Content { public string save; public string name; public int stage; }

        public bool IsValid(string owner)
        {
            return version == 1 && environment == SavePathPolicy.ModeName &&
                !string.IsNullOrEmpty(owner) && playerId == owner &&
                !string.IsNullOrWhiteSpace(cafeName) && cafeName == cafeName.Trim() &&
                cafeName.Length <= 20 && tutorialStage >= 0 && tutorialStage <= 4 &&
                saveJson != null && Encoding.UTF8.GetByteCount(saveJson) <= 350000 &&
                SaveManager.ValidateCloudSnapshot(saveJson) && checksum == ContentHash();
        }
    }

    // Local Save V2 is carried verbatim. This envelope is not a new gameplay schema.
    public sealed class SimpleCloudBackup : MonoBehaviour
    {
        private const float SaveBackupDebounceSeconds = 3f;

        private sealed class UploadAuthorizationException : IOException
        {
            public UploadAuthorizationException(string message)
                : base(message)
            {
            }
        }

        public static SimpleCloudBackup Instance { get; private set; }
        public string Status { get; private set; } = "Connect with Google Play to enable cloud backup.";
        public bool ChoiceRequired { get; private set; }
        public bool Busy { get; private set; }
        public bool CanRestore => ChoiceRequired && remote != null;
        public CloudBackupEnvelope Remote => remote;
        private CloudBackupEnvelope remote;
        private string owner, acceptedHash, writeLock;
        private float nextCheck;
        private int failures;
        private bool paused;
        private int identityEpoch;
        private bool saveBackupPending;
        private float saveBackupDue;
        private bool backgroundSaveAttempted;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
        private static void Create()
        {
            if (Instance == null) new GameObject("Cloud backup").AddComponent<SimpleCloudBackup>();
        }
        private void Awake()
        {
            Instance = this; DontDestroyOnLoad(gameObject);
            SaveManager.ActiveSaveV2Committed += HandleActiveSaveCommitted;
            if (SimpleCloudFiles.StartupError != null &&
                !SimpleCloudFiles.StartupRestorePending)
                SimpleCloudPanel.ShowRestartOverlay();
        }
        private void OnDestroy()
        {
            SaveManager.ActiveSaveV2Committed -= HandleActiveSaveCommitted;
            if (Instance == this) Instance = null;
        }

        internal static string GetVerifiedCurrentOwnerId()
        {
            if (SavePathPolicy.ModeName == "GUEST-QA-SANDBOX" ||
                UnityServices.State != ServicesInitializationState.Initialized) return null;
            var auth = AuthenticationService.Instance;
            if (!auth.IsSignedIn || !auth.IsAuthorized ||
                GooglePlayGamesAuthenticationCoordinator.Instance.SessionStatus !=
                GooglePlayGamesSessionStatus.GooglePlayGamesConnected) return null;
            return auth.PlayerInfo != null && !string.IsNullOrWhiteSpace(auth.PlayerInfo.GetGooglePlayGamesId())
                ? auth.PlayerId : null;
        }

        internal static bool IsCurrentVerifiedOwner(string playerId)
        {
            try
            {
                return !string.IsNullOrWhiteSpace(playerId) &&
                       string.Equals(
                           GetVerifiedCurrentOwnerId(),
                           playerId,
                           StringComparison.Ordinal);
            }
            catch (Exception exception)
            {
                Debug.LogWarning(
                    "CLOUD | Verified PlayerId could not be checked.\n" +
                    exception);
                return false;
            }
        }

        internal bool CanLinkCurrentDeviceProgress(out string playerId)
        {
            playerId = null;
            try
            {
                playerId = GetVerifiedCurrentOwnerId();
                SaveManager save = SaveManager.Instance;
                return !Busy &&
                       !(ChoiceRequired && Remote != null) &&
                       save != null &&
                       save.IsLifecycleSavingReady &&
                       !SimpleCloudFiles.RestorePending &&
                       !SimpleCloudFiles.StartupRestorePending &&
                       SimpleCloudFiles.StartupError == null &&
                       LocalSaveOwnership.CanExplicitlyLink(
                           save.SaveFilePath,
                           playerId,
                           SavePathPolicy.ModeName);
            }
            catch (Exception exception)
            {
                Debug.LogWarning(
                    "CLOUD | Local progress cannot be offered for linking.\n" +
                    exception);
                playerId = null;
                return false;
            }
        }

        internal bool TryLinkCurrentDeviceProgress(
            string confirmedPlayerId,
            bool explicitConsent,
            out string errorMessage)
        {
            errorMessage = null;
            bool canLink = CanLinkCurrentDeviceProgress(
                out string currentPlayerId);
            bool pendingRestore = SimpleCloudFiles.RestorePending ||
                SimpleCloudFiles.StartupRestorePending;
            if (!LocalSaveOwnership.CanEstablishGuestLink(
                    explicitConsent,
                    string.Equals(
                        currentPlayerId,
                        confirmedPlayerId,
                        StringComparison.Ordinal),
                    canLink,
                    canLink,
                    pendingRestore))
            {
                errorMessage =
                    "The verified account or local save changed. Review the link confirmation again.";
                return false;
            }

            SaveManager save = SaveManager.Instance;
            if (save == null ||
                !LocalSaveOwnership.TryEstablishForCurrentPlayer(
                    save.SaveFilePath,
                    LocalSaveOwnershipEvidence.ExplicitGuestLink,
                    out errorMessage))
                return false;

            NotifyLocalOwnershipEstablished();
            return true;
        }

        internal void NotifyLocalOwnershipEstablished()
        {
            paused = false;
            failures = 0;
            nextCheck = 0;
        }

        internal bool IsAcceptedBackup(
            string playerId,
            string environment,
            string saveJson,
            string checksum)
        {
            return !ChoiceRequired &&
                   remote != null &&
                   string.Equals(owner, playerId, StringComparison.Ordinal) &&
                   string.Equals(
                       acceptedHash,
                       remote.checksum,
                       StringComparison.Ordinal) &&
                   string.Equals(
                       remote.environment,
                       environment,
                       StringComparison.Ordinal) &&
                   string.Equals(remote.playerId, playerId, StringComparison.Ordinal) &&
                   string.Equals(remote.saveJson, saveJson, StringComparison.Ordinal) &&
                   string.Equals(
                       remote.checksum,
                       checksum,
                       StringComparison.Ordinal) &&
                   remote.IsValid(playerId);
        }

        internal static float GetSaveBackupDueTime(float now) =>
            now + SaveBackupDebounceSeconds;

        internal static float GetImmediateSaveBackupDueTime(float now) => now;

        internal static bool IsSaveBackupDue(
            bool pending,
            float now,
            float dueTime) =>
            pending && now >= dueTime;

        internal static async Task<bool> TryUploadAcceptedCopyAsync(
            int decision,
            Func<bool> authorizationIsCurrent,
            Func<Task> upload)
        {
            if (decision != 1 || !authorizationIsCurrent())
                return false;

            await upload();
            if (!authorizationIsCurrent())
                throw new OperationCanceledException();
            return true;
        }

        private void HandleActiveSaveCommitted()
        {
            if (owner == null ||
                ChoiceRequired ||
                SimpleCloudFiles.RestorePending ||
                SimpleCloudFiles.StartupRestorePending ||
                SimpleCloudFiles.StartupError != null)
                return;

            saveBackupPending = true;
            saveBackupDue = GetSaveBackupDueTime(Time.unscaledTime);
        }

        private void OnApplicationPause(bool isPaused)
        {
            if (isPaused)
                HandleApplicationBackgrounded();
            else
                HandleApplicationForegrounded();
        }

        private void OnApplicationFocus(bool hasFocus)
        {
            if (hasFocus)
                HandleApplicationForegrounded();
            else
                HandleApplicationBackgrounded();
        }

        private void HandleApplicationBackgrounded()
        {
            if (backgroundSaveAttempted)
                return;
            backgroundSaveAttempted = true;

            SaveManager save = SaveManager.Instance;
            if (save == null || !save.IsLifecycleSavingReady)
                return;

            if (!save.SaveCurrentGame())
            {
                Debug.LogWarning(
                    "CLOUD | Background save was not committed. " +
                    "Cloud upload was not started.");
                return;
            }

            if (owner == null || ChoiceRequired ||
                SimpleCloudFiles.RestorePending)
                return;

            saveBackupPending = true;
            saveBackupDue =
                GetImmediateSaveBackupDueTime(Time.unscaledTime);
            if (!Busy)
                _ = CheckAsync(false);
        }

        private void HandleApplicationForegrounded()
        {
            backgroundSaveAttempted = false;
            if (owner == null || ChoiceRequired ||
                SimpleCloudFiles.RestorePending)
                return;

            if (saveBackupPending)
                saveBackupDue =
                    GetImmediateSaveBackupDueTime(Time.unscaledTime);
            else
                nextCheck = Time.unscaledTime;
        }

        private static string CurrentOwner() =>
            GetVerifiedCurrentOwnerId();

        private void Update()
        {
            string current = CurrentOwner();
            if (owner != current)
            {
                owner = current; identityEpoch++; acceptedHash = null; remote = null;
                writeLock = null; ChoiceRequired = false; paused = false; failures = 0;
                saveBackupPending = false;
                Status = current == null ? "Offline/local play. Cloud backup is disconnected." : "Checking account backup…";
                nextCheck = 0;
            }
            bool localSaveDue = IsSaveBackupDue(
                saveBackupPending,
                Time.unscaledTime,
                saveBackupDue);
            bool periodicCheckDue =
                !saveBackupPending && Time.unscaledTime >= nextCheck;
            if (!Busy && !paused && owner != null && !ChoiceRequired &&
                !SimpleCloudFiles.RestorePending &&
                (localSaveDue || periodicCheckDue))
            {
                if (localSaveDue)
                    saveBackupPending = false;
                _ = CheckAsync(false);
            }
        }

        private bool StillCurrent(string id, int epoch) => owner == id &&
            identityEpoch == epoch && CurrentOwner() == id && !SimpleCloudFiles.RestorePending;
        private string Key => "dmc_backup_v1_" + SavePathPolicy.ModeName;

        internal bool TryGetKeepDeviceConfirmation(
            out string playerId,
            out string remoteChecksum,
            out string remoteWriteLock,
            out int approvedIdentityEpoch)
        {
            playerId = GetVerifiedCurrentOwnerId();
            remoteChecksum = null;
            remoteWriteLock = null;
            approvedIdentityEpoch = identityEpoch;
            if (Busy ||
                !ChoiceRequired ||
                remote == null ||
                string.IsNullOrWhiteSpace(writeLock) ||
                !string.Equals(owner, playerId, StringComparison.Ordinal) ||
                !IsCurrentVerifiedOwner(playerId) ||
                SimpleCloudFiles.RestorePending ||
                SimpleCloudFiles.StartupRestorePending ||
                SimpleCloudFiles.StartupError != null ||
                !remote.IsValid(playerId))
            {
                playerId = null;
                return false;
            }

            remoteChecksum = remote.checksum;
            remoteWriteLock = writeLock;
            return true;
        }

        internal bool TryGetFirstBackupConfirmation(
            out string playerId,
            out int approvedIdentityEpoch)
        {
            playerId = GetVerifiedCurrentOwnerId();
            approvedIdentityEpoch = identityEpoch;
            if (Busy ||
                !ChoiceRequired ||
                remote != null ||
                !string.Equals(owner, playerId, StringComparison.Ordinal) ||
                !IsCurrentVerifiedOwner(playerId) ||
                SimpleCloudFiles.RestorePending ||
                SimpleCloudFiles.StartupRestorePending ||
                SimpleCloudFiles.StartupError != null)
            {
                playerId = null;
                return false;
            }

            return true;
        }

        internal bool IsFirstBackupConfirmationCurrent(
            string playerId,
            int approvedIdentityEpoch)
        {
            return ChoiceRequired &&
                   remote == null &&
                   identityEpoch == approvedIdentityEpoch &&
                   string.Equals(owner, playerId, StringComparison.Ordinal) &&
                   IsCurrentVerifiedOwner(playerId) &&
                   !SimpleCloudFiles.RestorePending &&
                   !SimpleCloudFiles.StartupRestorePending &&
                   SimpleCloudFiles.StartupError == null;
        }

        internal bool IsKeepDeviceConfirmationCurrent(
            string playerId,
            string remoteChecksum,
            string remoteWriteLock,
            int approvedIdentityEpoch)
        {
            return remote != null &&
                   CanCommitKeepDeviceConfirmation(
                       explicitConfirmation: true,
                       choiceRequired: ChoiceRequired,
                       remoteAvailable: remote != null,
                       identityMatches:
                           string.Equals(
                               owner,
                               playerId,
                               StringComparison.Ordinal) &&
                           IsCurrentVerifiedOwner(playerId),
                       currentIdentityEpoch: identityEpoch,
                       approvedIdentityEpoch: approvedIdentityEpoch,
                       approvedChecksum: remoteChecksum,
                       currentChecksum: remote?.checksum,
                       approvedWriteLock: remoteWriteLock,
                       currentWriteLock: writeLock,
                       restorePending:
                           SimpleCloudFiles.RestorePending ||
                           SimpleCloudFiles.StartupRestorePending ||
                           SimpleCloudFiles.StartupError != null) &&
                   remote.IsValid(playerId);
        }

        internal static bool CanCommitKeepDeviceConfirmation(
            bool explicitConfirmation,
            bool choiceRequired,
            bool remoteAvailable,
            bool identityMatches,
            int currentIdentityEpoch,
            int approvedIdentityEpoch,
            string approvedChecksum,
            string currentChecksum,
            string approvedWriteLock,
            string currentWriteLock,
            bool restorePending)
        {
            return explicitConfirmation &&
                   choiceRequired &&
                   remoteAvailable &&
                   identityMatches &&
                   currentIdentityEpoch == approvedIdentityEpoch &&
                   !string.IsNullOrWhiteSpace(approvedChecksum) &&
                   string.Equals(
                       approvedChecksum,
                       currentChecksum,
                       StringComparison.Ordinal) &&
                   !string.IsNullOrWhiteSpace(approvedWriteLock) &&
                   string.Equals(
                       approvedWriteLock,
                       currentWriteLock,
                       StringComparison.Ordinal) &&
                   !restorePending;
        }

        internal static async Task<KeepDeviceConflictResult>
            RunKeepDeviceConflictAsync(
                CloudConflictChoice choice,
                bool explicitlyConfirmed,
                Func<bool> approvalIsCurrent,
                Func<Task<bool>> cloudStillMatchesApproval,
                Func<bool> ensureOwnership,
                Func<Task<bool>> upload,
                Func<bool> identityStillCurrent,
                Action<Exception> reportFailure)
        {
            if (choice == CloudConflictChoice.Cancel || !explicitlyConfirmed)
                return KeepDeviceConflictResult.Cancelled;
            if (choice != CloudConflictChoice.KeepDevice)
                return KeepDeviceConflictResult.RestoreSelected;
            if (!approvalIsCurrent())
                return KeepDeviceConflictResult.ApprovalChanged;

            bool cloudMatches;
            try
            {
                cloudMatches = await cloudStillMatchesApproval();
            }
            catch (Exception exception)
            {
                reportFailure?.Invoke(exception);
                return KeepDeviceConflictResult.CloudCheckFailed;
            }
            if (!cloudMatches || !approvalIsCurrent())
                return KeepDeviceConflictResult.ApprovalChanged;

            bool ownershipReady;
            try
            {
                ownershipReady = ensureOwnership();
            }
            catch (Exception exception)
            {
                reportFailure?.Invoke(exception);
                return KeepDeviceConflictResult.OwnershipBlocked;
            }
            if (!ownershipReady)
                return KeepDeviceConflictResult.OwnershipBlocked;
            if (!approvalIsCurrent())
                return KeepDeviceConflictResult.ApprovalChanged;

            bool uploaded;
            try
            {
                uploaded = await upload();
            }
            catch (Exception exception)
            {
                reportFailure?.Invoke(exception);
                try
                {
                    return identityStillCurrent()
                        ? KeepDeviceConflictResult.UploadFailed
                        : KeepDeviceConflictResult.OutcomeUnknown;
                }
                catch (Exception identityException)
                {
                    reportFailure?.Invoke(identityException);
                    return KeepDeviceConflictResult.OutcomeUnknown;
                }
            }
            if (!uploaded)
                return KeepDeviceConflictResult.UploadFailed;

            return identityStillCurrent()
                ? KeepDeviceConflictResult.Completed
                : KeepDeviceConflictResult.OutcomeUnknown;
        }

        internal static bool RequiresFreshCloudCheck(
            KeepDeviceConflictResult result)
        {
            return result == KeepDeviceConflictResult.ApprovalChanged ||
                   result == KeepDeviceConflictResult.CloudCheckFailed ||
                   result == KeepDeviceConflictResult.UploadFailed ||
                   result == KeepDeviceConflictResult.OutcomeUnknown;
        }

        internal static async Task<bool> TryCreateInitialBackupAsync(
            Func<Task<bool>> confirmRemoteAbsent,
            Func<bool> gameplayReady,
            Func<bool> authorizationIsCurrent,
            Func<Task> upload)
        {
            if (!await confirmRemoteAbsent())
                return false;
            if (!gameplayReady() || !authorizationIsCurrent())
                return false;

            await upload();
            if (!authorizationIsCurrent())
                throw new OperationCanceledException();
            return true;
        }

        // 0 = same copy, 1 = accepted remote with changed local data, 2 = player choice.
        public static int Decide(string localHash, string remoteHash, string accepted)
        {
            if (remoteHash != null && remoteHash == localHash) return 0;
            if (accepted != null && remoteHash != null && remoteHash == accepted) return 1;
            return 2;
        }

        private static bool IsGameplayReadyForInitialBackup()
        {
            ApplicationReadinessCoordinator readiness =
                ApplicationReadinessCoordinator.Instance;
            SaveManager save = SaveManager.Instance;
            return readiness != null &&
                   readiness.IsGameplayReady &&
                   save != null &&
                   save.IsLifecycleSavingReady &&
                   !SimpleCloudFiles.RestorePending &&
                   !SimpleCloudFiles.StartupRestorePending &&
                   SimpleCloudFiles.StartupError == null;
        }

        private CloudBackupEnvelope Capture(string id, bool flush)
        {
            var save = SaveManager.Instance;
            if (save == null || !save.IsLifecycleSavingReady ||
                (flush && !save.SaveCurrentGame())) throw new IOException("Local gameplay is not ready to back up.");
            if (CafeProfileLocalStore.Load(out var cafe, out _) != CafeProfileLocalStatus.Loaded)
                throw new IOException("Finish naming your café before creating a backup.");
            var result = TutorialProgressJournal.TryLoad(out var stage, out _);
            if (result != TutorialProgressJournalLoadStatus.Loaded)
                throw new IOException("Tutorial progress is not ready to back up.");
            var value = new CloudBackupEnvelope { environment = SavePathPolicy.ModeName,
                playerId = id, saveJson = File.ReadAllText(save.SaveFilePath, Encoding.UTF8),
                cafeName = cafe.CafeName, tutorialStage = (int)stage };
            value.checksum = value.ContentHash();
            if (!value.IsValid(id))
                throw new IOException(
                    "Local backup validation failed. Local files are unchanged.");
            RequireUploadAuthorization(
                value,
                id,
                identityEpoch,
                requireCurrentSnapshot: true);
            return value;
        }

        private void RequireUploadAuthorization(
            CloudBackupEnvelope local,
            string id,
            int epoch,
            bool requireCurrentSnapshot)
        {
            SaveManager save = SaveManager.Instance;
            string environment = SavePathPolicy.ModeName;
            if (!StillCurrent(id, epoch) ||
                SimpleCloudFiles.StartupRestorePending ||
                SimpleCloudFiles.StartupError != null ||
                save == null ||
                !save.IsLifecycleSavingReady ||
                !IsGameplayReadyForInitialBackup() ||
                local == null ||
                !string.Equals(
                    local.environment,
                    environment,
                    StringComparison.Ordinal) ||
                !local.IsValid(id) ||
                !LocalSaveOwnership.IsOwnedByForCloudUpload(
                    save.SaveFilePath,
                    id,
                    environment,
                    GetVerifiedCurrentOwnerId))
            {
                throw new UploadAuthorizationException(
                    "Cloud upload blocked: local Save V2 ownership could not " +
                    "be verified for the current Google account and environment.");
            }

            if (requireCurrentSnapshot)
            {
                try
                {
                    string currentSave = File.ReadAllText(
                        save.SaveFilePath,
                        Encoding.UTF8);
                    if (string.Equals(
                            currentSave,
                            local.saveJson,
                            StringComparison.Ordinal))
                        return;
                }
                catch (Exception exception)
                {
                    throw new UploadAuthorizationException(
                        "Cloud upload blocked: the active Save V2 could not " +
                        "be revalidated. " + exception.Message);
                }

                throw new UploadAuthorizationException(
                    "Cloud upload blocked: the local Save V2 changed. " +
                    "Check cloud progress again before retrying.");
            }
        }

        private async Task ReadAsync(string id, int epoch)
        {
            var data = await CloudSaveService.Instance.Data.Player.LoadAsync(
                new HashSet<string> { Key }, new Unity.Services.CloudSave.Models.Data.Player.LoadOptions());
            if (!StillCurrent(id, epoch)) throw new OperationCanceledException();
            remote = null; writeLock = null;
            if (!data.TryGetValue(Key, out var item)) return;
            var json = item.Value.GetAs<string>();
            if (json == null || Encoding.UTF8.GetByteCount(json) > 500000)
                throw new InvalidDataException("Cloud backup is too large or invalid.");
            var candidate = JsonUtility.FromJson<CloudBackupEnvelope>(json);
            if (candidate == null || !candidate.IsValid(id) || string.IsNullOrEmpty(item.WriteLock))
                throw new InvalidDataException("Cloud backup failed validation. Neither copy was replaced.");
            remote = candidate; writeLock = item.WriteLock;
        }

        public async Task CheckAsync(bool manual)
        {
            if (Busy || owner == null || SimpleCloudFiles.RestorePending) return;
            if (manual) { paused = false; failures = 0; }
            Busy = true;
            string id = owner; int epoch = identityEpoch;
            try
            {
                await ReadAsync(id, epoch);
                CloudBackupEnvelope local = null;
                string localMessage = null;
                try { local = Capture(id, manual); }
                catch (UploadAuthorizationException ex)
                {
                    localMessage = ex.Message;
                    paused = true;
                }
                catch (IOException ex) { localMessage = ex.Message; }
                if (!StillCurrent(id, epoch)) return;
                if (local == null)
                {
                    saveBackupPending = false;
                    acceptedHash = null; ChoiceRequired = remote != null;
                    Status = remote != null
                        ? "Cloud progress is available. You can restore it " +
                          "on this device. " + localMessage
                        : localMessage;
                    nextCheck = Time.unscaledTime + 30;
                    return;
                }

                if (remote == null && acceptedHash == null)
                {
                    bool uploaded = await TryCreateInitialBackupAsync(
                        confirmRemoteAbsent: async () =>
                        {
                            await ReadAsync(id, epoch);
                            return remote == null;
                        },
                        gameplayReady: IsGameplayReadyForInitialBackup,
                        authorizationIsCurrent: () =>
                        {
                            RequireUploadAuthorization(
                                local,
                                id,
                                epoch,
                                requireCurrentSnapshot: true);
                            return true;
                        },
                        upload: () => UploadAsync(local, id, epoch));

                    if (uploaded)
                    {
                        failures = 0;
                        nextCheck = Time.unscaledTime + 30;
                        return;
                    }

                    if (!StillCurrent(id, epoch))
                        return;
                    if (remote == null)
                    {
                        ChoiceRequired = false;
                        Status = "Cloud backup will start when gameplay is ready.";
                        nextCheck = Time.unscaledTime + 30;
                        return;
                    }
                }

                int decision = Decide(local.checksum, remote?.checksum, acceptedHash);
                if (decision == 0)
                {
                    acceptedHash = local.checksum; ChoiceRequired = false;
                    Status = "Cloud backup is up to date.";
                    PlayerStatisticsCloudSync.NotifyBackupAccepted(local);
                }
                else if (decision == 1)
                {
                    await TryUploadAcceptedCopyAsync(
                        decision,
                        authorizationIsCurrent: () =>
                        {
                            RequireUploadAuthorization(
                                local,
                                id,
                                epoch,
                                requireCurrentSnapshot: false);
                            return true;
                        },
                        upload: () => UploadAsync(local, id, epoch));
                }
                else
                {
                    saveBackupPending = false;
                    ChoiceRequired = true;
                    Status = remote == null ? "No backup for this account. Choose Back up this device." :
                        "Device and cloud progress differ. Choose which copy to keep.";
                }
                failures = 0; nextCheck = Time.unscaledTime + 30;
            }
            catch (OperationCanceledException) { }
            catch (UploadAuthorizationException ex)
            {
                BlockUpload(ex.Message);
            }
            catch (InvalidDataException ex) { paused = true; ChoiceRequired = false; Status = ex.Message; }
            catch (Exception) { Failed(); }
            finally { Busy = false; }
        }

        private void Failed()
        {
            // Every retry starts with a new cloud read; write locks reject stale writes.
            failures = Math.Min(failures + 1, 3);
            paused = false;
            nextCheck = Time.unscaledTime + 10 * failures;
            Status =
                "Cloud unavailable or progress changed. Local play continues; retrying automatically.";
        }

        private async Task UploadAsync(
            CloudBackupEnvelope local,
            string id,
            int epoch,
            bool reportSuccess = true)
        {
            RequireUploadAuthorization(
                local,
                id,
                epoch,
                requireCurrentSnapshot: true);
            // Null is used only for a confirmed absent key; every existing key uses its write lock.
            var locks = await CloudSaveService.Instance.Data.Player.SaveAsync(
                new Dictionary<string, SaveItem> { [Key] = new SaveItem(JsonUtility.ToJson(local), writeLock) },
                new Unity.Services.CloudSave.Models.Data.Player.SaveOptions());
            if (!StillCurrent(id, epoch)) throw new OperationCanceledException();
            try
            {
                RequireUploadAuthorization(
                    local,
                    id,
                    epoch,
                    requireCurrentSnapshot: false);
            }
            catch (UploadAuthorizationException exception)
            {
                throw new UploadAuthorizationException(
                    exception.Message +
                    " The cloud write may have completed; check cloud progress " +
                    "before retrying.");
            }
            if (!locks.TryGetValue(Key, out writeLock) || string.IsNullOrEmpty(writeLock))
                throw new IOException("Cloud write was not acknowledged.");
            remote = local; acceptedHash = local.checksum; ChoiceRequired = false;
            if (reportSuccess)
                Status = "Cloud backup saved.";
            PlayerStatisticsCloudSync.NotifyBackupAccepted(local);
        }

        public async Task KeepLocalAsync()
        {
            if (Busy || !ChoiceRequired || owner == null) return;
            Busy = true; string id = owner; int epoch = identityEpoch;
            string chosen = remote?.checksum;
            try
            {
                await ReadAsync(id, epoch);
                if (chosen != remote?.checksum) { Status = "Cloud changed. Review the choices again."; return; }
                await UploadAsync(Capture(id, true), id, epoch);
                failures = 0; nextCheck = Time.unscaledTime + 30;
            }
            catch (OperationCanceledException) { }
            catch (UploadAuthorizationException ex)
            {
                BlockUpload(ex.Message);
            }
            catch (Exception) { Failed(); }
            finally { Busy = false; }
        }

        internal async Task KeepLocalForConfirmedGuestConflictAsync(
            string confirmedPlayerId,
            string confirmedRemoteChecksum,
            string confirmedRemoteWriteLock,
            int approvedIdentityEpoch)
        {
            if (Busy ||
                !IsKeepDeviceConfirmationCurrent(
                    confirmedPlayerId,
                    confirmedRemoteChecksum,
                    confirmedRemoteWriteLock,
                    approvedIdentityEpoch))
                return;

            Busy = true;
            string id = confirmedPlayerId;
            int epoch = approvedIdentityEpoch;
            bool refreshCloudAfterFailure = false;
            try
            {
                KeepDeviceConflictResult result =
                    await RunKeepDeviceConflictAsync(
                        choice: CloudConflictChoice.KeepDevice,
                        explicitlyConfirmed: true,
                        approvalIsCurrent: () =>
                            IsKeepDeviceConfirmationCurrent(
                                id,
                                confirmedRemoteChecksum,
                                confirmedRemoteWriteLock,
                                epoch),
                        cloudStillMatchesApproval: async () =>
                        {
                            await ReadAsync(id, epoch);
                            return IsKeepDeviceConfirmationCurrent(
                                id,
                                confirmedRemoteChecksum,
                                confirmedRemoteWriteLock,
                                epoch);
                        },
                        ensureOwnership: () =>
                            EnsureOwnershipForConfirmedGuestConflict(
                                id,
                                confirmedRemoteChecksum,
                                confirmedRemoteWriteLock,
                                epoch),
                        upload: async () =>
                        {
                            CloudBackupEnvelope local = Capture(id, false);
                            if (!IsKeepDeviceConfirmationCurrent(
                                    id,
                                    confirmedRemoteChecksum,
                                    confirmedRemoteWriteLock,
                                    epoch))
                                return false;

                            await UploadAsync(
                                local,
                                id,
                                epoch,
                                reportSuccess: false);
                            return true;
                        },
                        identityStillCurrent: () =>
                            StillCurrent(id, epoch) &&
                            IsCurrentVerifiedOwner(id) &&
                            !SimpleCloudFiles.StartupRestorePending &&
                            SimpleCloudFiles.StartupError == null,
                        reportFailure: exception =>
                            Debug.LogWarning(
                                "CLOUD | Keep Device operation failed.\n" +
                                exception));

                switch (result)
                {
                    case KeepDeviceConflictResult.Completed:
                        failures = 0;
                        nextCheck = Time.unscaledTime + 30;
                        Status = "Cloud backup saved.";
                        break;
                    case KeepDeviceConflictResult.Cancelled:
                        Status = "Keep Device canceled. Local and cloud progress were unchanged.";
                        break;
                    case KeepDeviceConflictResult.ApprovalChanged:
                        ChoiceRequired = remote != null;
                        acceptedHash = null;
                        Status =
                            "Cloud progress or the account changed. Review " +
                            "the cloud choice again.";
                        break;
                    case KeepDeviceConflictResult.OwnershipBlocked:
                        BlockUpload(
                            "Guest progress could not be linked safely. " +
                            "Local and cloud progress were preserved.");
                        break;
                    case KeepDeviceConflictResult.CloudCheckFailed:
                    case KeepDeviceConflictResult.UploadFailed:
                        Failed();
                        break;
                    case KeepDeviceConflictResult.OutcomeUnknown:
                        acceptedHash = null;
                        paused = true;
                        ChoiceRequired = false;
                        Status =
                            "The cloud write may have completed, but the " +
                            "account or approval changed. Check cloud progress " +
                            "before trying again.";
                        break;
                    default:
                        throw new ArgumentOutOfRangeException();
                }
                refreshCloudAfterFailure =
                    RequiresFreshCloudCheck(result);
            }
            catch (OperationCanceledException) { }
            catch (UploadAuthorizationException exception)
            {
                BlockUpload(exception.Message);
            }
            catch (Exception)
            {
                Failed();
                refreshCloudAfterFailure = true;
            }
            finally
            {
                Busy = false;
            }

            if (refreshCloudAfterFailure && StillCurrent(id, epoch))
                await CheckAsync(true);
        }

        private bool EnsureOwnershipForConfirmedGuestConflict(
            string playerId,
            string confirmedRemoteChecksum,
            string confirmedRemoteWriteLock,
            int approvedIdentityEpoch)
        {
            SaveManager save = SaveManager.Instance;
            if (save == null || !save.IsLifecycleSavingReady)
                return false;

            if (LocalSaveOwnership.IsOwnedByForCloudUpload(
                    save.SaveFilePath,
                    playerId,
                    SavePathPolicy.ModeName,
                    GetVerifiedCurrentOwnerId))
                return true;

            if (!LocalSaveOwnership.CanExplicitlyLink(
                    save.SaveFilePath,
                    playerId,
                    SavePathPolicy.ModeName) ||
                !IsKeepDeviceConfirmationCurrent(
                    playerId,
                    confirmedRemoteChecksum,
                    confirmedRemoteWriteLock,
                    approvedIdentityEpoch))
                return false;

            return LocalSaveOwnership.TryEstablishForCurrentPlayer(
                save.SaveFilePath,
                LocalSaveOwnershipEvidence.ExplicitGuestLink,
                out _);
        }

        private void BlockUpload(string message)
        {
            acceptedHash = null;
            paused = true;
            ChoiceRequired = remote != null;
            nextCheck = Time.unscaledTime + 30;
            Status = message;
        }

        public async Task RestoreAsync()
        {
            if (Busy || !CanRestore || owner == null) return;
            Busy = true; string id = owner; int epoch = identityEpoch;
            string chosen = remote.checksum;
            try
            {
                await ReadAsync(id, epoch);
                if (chosen != remote?.checksum) { Status = "Cloud changed. Review the choices again."; return; }
                if (!StillCurrent(id, epoch)) return;
                var save = SaveManager.Instance;
                if (save != null && save.IsLifecycleSavingReady)
                {
                    if (!save.SaveCurrentGame()) throw new IOException("Local recovery save failed.");
                }
                else if (File.Exists(Path.Combine(SavePathPolicy.GetSaveDirectory(), "player_save_v2.json")))
                    throw new IOException("Wait for local gameplay to finish loading before restoring.");
                SimpleCloudFiles.StageRestore(remote);
                save?.SuspendLifecycleSaving();
                Time.timeScale = 0;
                Status = "Restore prepared. Close and reopen the game to finish. Your previous files are preserved.";
                ChoiceRequired = false; paused = true;
            }
            catch (OperationCanceledException) { }
            catch (Exception)
            {
                if (SimpleCloudFiles.RestorePending)
                {
                    SaveManager.Instance?.SuspendLifecycleSaving();
                    Time.timeScale = 0; paused = true;
                    Status = "Restore is pending. Close and reopen the game to finish.";
                }
                else Failed();
            }
            finally { Busy = false; }
        }
    }
}
