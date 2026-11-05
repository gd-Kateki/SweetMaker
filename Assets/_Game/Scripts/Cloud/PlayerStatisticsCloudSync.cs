using System;
using System.Collections.Generic;
using System.IO;
using System.Threading.Tasks;
using SweetMerge.Authentication;
using SweetMerge.Startup;
using Unity.Services.CloudSave;
using Unity.Services.CloudSave.Models;
using Unity.Services.Core;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace SweetMerge.Cloud
{
    internal sealed class PlayerStatisticsSyncSession
    {
        internal const double MinimumUploadIntervalSeconds = 30;

        private readonly Func<string> getVerifiedOwner;
        private readonly Func<bool> isRestorePending;
        private readonly Func<bool> isGoogleRun;
        private readonly Func<bool> isGameplayReady;
        private readonly Func<bool> hasStartupFailure;
        private readonly Func<IDictionary<string, object>> captureSnapshot;
        private readonly Func<IDictionary<string, object>, Task> uploadSnapshot;
        private readonly Func<double> getTime;
        private readonly Func<bool> isAcceptedBackupCurrent;

        private string candidateOwner;
        private string authorizedOwner;
        private int generation;
        private bool hasUploadedSnapshot;
        private IDictionary<string, object> lastUploadedSnapshot;
        private bool uploading;
        private bool uploadQueued;
        private bool readinessConfirmed;
        private double lastUploadTime = double.NegativeInfinity;
        private Task activeUpload = Task.CompletedTask;

        internal string Status { get; private set; } =
            "Statistics sync is not authorized.";
        internal bool IsAuthorized => !string.IsNullOrEmpty(authorizedOwner);
        internal bool HasRestoreCandidate =>
            !string.IsNullOrEmpty(candidateOwner);

        internal PlayerStatisticsSyncSession(
            Func<string> getVerifiedOwner,
            Func<bool> isRestorePending,
            Func<bool> isGoogleRun,
            Func<bool> isGameplayReady,
            Func<bool> hasStartupFailure,
            Func<IDictionary<string, object>> captureSnapshot,
            Func<IDictionary<string, object>, Task> uploadSnapshot,
            Func<double> getTime)
            : this(
                getVerifiedOwner,
                isRestorePending,
                isGoogleRun,
                isGameplayReady,
                hasStartupFailure,
                captureSnapshot,
                uploadSnapshot,
                getTime,
                null)
        {
        }

        internal PlayerStatisticsSyncSession(
            Func<string> getVerifiedOwner,
            Func<bool> isRestorePending,
            Func<bool> isGoogleRun,
            Func<bool> isGameplayReady,
            Func<bool> hasStartupFailure,
            Func<IDictionary<string, object>> captureSnapshot,
            Func<IDictionary<string, object>, Task> uploadSnapshot,
            Func<double> getTime,
            Func<bool> isAcceptedBackupCurrent)
        {
            this.getVerifiedOwner = getVerifiedOwner ??
                throw new ArgumentNullException(nameof(getVerifiedOwner));
            this.isRestorePending = isRestorePending ??
                throw new ArgumentNullException(nameof(isRestorePending));
            this.isGoogleRun = isGoogleRun ??
                throw new ArgumentNullException(nameof(isGoogleRun));
            this.isGameplayReady = isGameplayReady ??
                throw new ArgumentNullException(nameof(isGameplayReady));
            this.hasStartupFailure = hasStartupFailure ??
                throw new ArgumentNullException(nameof(hasStartupFailure));
            this.captureSnapshot = captureSnapshot ??
                throw new ArgumentNullException(nameof(captureSnapshot));
            this.uploadSnapshot = uploadSnapshot ??
                throw new ArgumentNullException(nameof(uploadSnapshot));
            this.getTime = getTime ??
                throw new ArgumentNullException(nameof(getTime));
            this.isAcceptedBackupCurrent = isAcceptedBackupCurrent;
        }

        internal bool RegisterPromotedRestoreCandidate(
            bool restoreCompleted,
            string restoredOwner)
        {
            if (!restoreCompleted)
            {
                Invalidate("Statistics sync requires a completed cloud restore.");
                return false;
            }

            if (string.IsNullOrWhiteSpace(restoredOwner) ||
                !isGoogleRun() ||
                !string.Equals(
                    getVerifiedOwner(),
                    restoredOwner,
                    StringComparison.Ordinal))
            {
                Invalidate("Verified restore ownership could not be established.");
                return false;
            }

            Invalidate("A new verified restore was completed.");
            candidateOwner = restoredOwner;
            Status = "Verified restore recorded; waiting for startup readiness.";
            return true;
        }

        internal bool RegisterAcceptedBackupCandidate(string acceptedOwner)
        {
            if (string.IsNullOrWhiteSpace(acceptedOwner) ||
                isRestorePending() ||
                !isGoogleRun() ||
                hasStartupFailure() ||
                !isGameplayReady() ||
                !string.Equals(
                    getVerifiedOwner(),
                    acceptedOwner,
                    StringComparison.Ordinal))
                return false;

            if (!string.Equals(
                    authorizedOwner,
                    acceptedOwner,
                    StringComparison.Ordinal))
            {
                Invalidate("A newly accepted cloud backup authorized statistics sync.");
                authorizedOwner = acceptedOwner;
                readinessConfirmed = true;
            }

            candidateOwner = null;
            Status = "Accepted backup recorded; preparing statistics snapshot.";
            return true;
        }

        internal Task RequestUploadAsync()
        {
            if (!TryValidateSession(out string owner))
                return Task.CompletedTask;

            if (!isGameplayReady())
            {
                if (hasStartupFailure())
                    Invalidate("Startup failed before statistics sync became ready.");
                else if (IsAuthorized)
                    Invalidate("Statistics sync invalidated because startup readiness was lost.");
                else
                    Status = "Verified restore recorded; waiting for startup readiness.";
                return Task.CompletedTask;
            }

            if (string.IsNullOrEmpty(authorizedOwner))
            {
                if (string.IsNullOrEmpty(candidateOwner) ||
                    !string.Equals(
                        candidateOwner,
                        owner,
                        StringComparison.Ordinal))
                {
                    Invalidate("The restored profile owner is no longer verified.");
                    return Task.CompletedTask;
                }

                authorizedOwner = candidateOwner;
                candidateOwner = null;
                readinessConfirmed = true;
                generation++;
                Status = "Session-authorized; preparing statistics snapshot.";
            }

            if (uploading)
            {
                uploadQueued = true;
                Status = "Statistics upload in progress; checkpoint coalesced.";
                return activeUpload;
            }

            IDictionary<string, object> snapshot;
            try
            {
                snapshot = captureSnapshot();
            }
            catch (Exception exception)
            {
                Status = "Statistics snapshot could not be captured.";
                Debug.LogWarning(
                    "PLAYER STATISTICS | Snapshot capture failed; gameplay was not changed.\n" +
                    exception);
                return Task.CompletedTask;
            }
            if (hasUploadedSnapshot &&
                SnapshotsEqual(lastUploadedSnapshot, snapshot))
            {
                Status = "Statistics snapshot is unchanged.";
                return Task.CompletedTask;
            }

            double now = getTime();
            if (now - lastUploadTime < MinimumUploadIntervalSeconds)
            {
                Status = "Statistics upload throttled; waiting for a later checkpoint.";
                return Task.CompletedTask;
            }

            int requestGeneration = generation;
            uploading = true;
            lastUploadTime = now;
            activeUpload = UploadAsync(snapshot, requestGeneration);
            return activeUpload;
        }

        internal void Invalidate(string reason)
        {
            generation++;
            candidateOwner = null;
            authorizedOwner = null;
            hasUploadedSnapshot = false;
            lastUploadedSnapshot = null;
            uploadQueued = false;
            readinessConfirmed = false;
            lastUploadTime = double.NegativeInfinity;
            Status = string.IsNullOrWhiteSpace(reason)
                ? "Statistics sync authorization was invalidated."
                : reason;
        }

        internal void ValidateCurrentSession()
        {
            if (!HasRestoreCandidate && !IsAuthorized)
                return;

            if (TryValidateSession(out _) &&
                IsAuthorized &&
                !isGameplayReady())
            {
                Invalidate("Statistics sync invalidated because startup readiness was lost.");
            }
        }

        private bool TryValidateSession(out string owner)
        {
            owner = getVerifiedOwner();
            if (isRestorePending())
            {
                Invalidate("Statistics sync blocked by a pending cloud restore.");
                return false;
            }

            if (!isGoogleRun())
            {
                Invalidate("Statistics sync blocked because the active run is not Google-owned.");
                return false;
            }

            if (hasStartupFailure())
            {
                Invalidate("Statistics sync blocked by an unresolved startup failure.");
                return false;
            }

            string expectedOwner = authorizedOwner ?? candidateOwner;
            if (string.IsNullOrEmpty(expectedOwner) ||
                string.IsNullOrEmpty(owner) ||
                !string.Equals(
                    owner,
                    expectedOwner,
                    StringComparison.Ordinal))
            {
                Invalidate("Verified account no longer matches the restored profile.");
                return false;
            }

            if (isAcceptedBackupCurrent != null &&
                !isAcceptedBackupCurrent())
                return false;

            return true;
        }

        private async Task UploadAsync(
            IDictionary<string, object> snapshot,
            int requestGeneration)
        {
            string owner = authorizedOwner;
            try
            {
                if (!CanSend(owner, requestGeneration))
                    return;

                await uploadSnapshot(snapshot);

                if (!CanSend(owner, requestGeneration))
                    return;

                lastUploadedSnapshot =
                    new Dictionary<string, object>(snapshot);
                hasUploadedSnapshot = true;
                Status = "Statistics snapshot uploaded.";
            }
            catch (Exception exception)
            {
                if (requestGeneration == generation)
                {
                    Status = "Statistics upload failed; gameplay is unaffected.";
                    Debug.LogWarning(
                        "PLAYER STATISTICS | Upload failed; local gameplay was not changed.\n" +
                        exception);
                }
            }
            finally
            {
                uploading = false;
                if (uploadQueued)
                {
                    uploadQueued = false;
                    _ = RequestUploadAsync();
                }
            }
        }

        private bool CanSend(string owner, int requestGeneration)
        {
            if (requestGeneration != generation ||
                !string.Equals(
                    authorizedOwner,
                    owner,
                    StringComparison.Ordinal))
                return false;

            if (isAcceptedBackupCurrent != null &&
                !isAcceptedBackupCurrent())
                return false;

            if (isRestorePending() ||
                !isGoogleRun() ||
                hasStartupFailure() ||
                !string.Equals(
                    getVerifiedOwner(),
                    owner,
                    StringComparison.Ordinal))
            {
                Invalidate("Statistics sync authorization changed before upload.");
                return false;
            }

            if (!isGameplayReady())
            {
                if (readinessConfirmed)
                    Invalidate("Statistics sync invalidated because startup readiness was lost.");
                return false;
            }

            return true;
        }

        private static bool SnapshotsEqual(
            IDictionary<string, object> left,
            IDictionary<string, object> right)
        {
            if (left == null || right == null || left.Count != right.Count)
                return false;

            foreach (KeyValuePair<string, object> item in left)
            {
                if (!right.TryGetValue(item.Key, out object value) ||
                    !Equals(item.Value, value))
                    return false;
            }

            return true;
        }
    }

    public sealed class PlayerStatisticsCloudSync : MonoBehaviour
    {
        internal const string CurrentMoneyKey =
            "dmc_player_stats_v1_current_money";
        internal const string TotalMoneyEarnedKey =
            "dmc_player_stats_v1_total_money_earned";
        internal const string TotalOrdersCompletedKey =
            "dmc_player_stats_v1_total_orders_completed";
        internal const string CurrentRebirthCountKey =
            "dmc_player_stats_v1_current_rebirth_count";

        private static PlayerStatisticsCloudSync instance;
        private PlayerStatisticsSyncSession session;
        private bool subscribed;
        private bool initialUploadAttempted;
        private GameStartupCoordinator subscribedStartup;
        private ApplicationReadinessCoordinator subscribedReadiness;
        private GooglePlayGamesAuthenticationCoordinator subscribedAuthentication;
        private string acceptedBackupOwner;
        private string acceptedBackupEnvironment;
        private string acceptedBackupSaveJson;
        private string acceptedBackupChecksum;
        private bool acceptedBackupRequired;

        public string DiagnosticStatus =>
            session != null ? session.Status : "Statistics sync is unavailable.";

        [RuntimeInitializeOnLoadMethod(
            RuntimeInitializeLoadType.SubsystemRegistration)]
        private static void ResetSessionState()
        {
            if (instance != null)
            {
                instance.session?.Invalidate(
                    "Application session restarted.");
                instance.initialUploadAttempted = false;
            }

            instance = null;
        }

        [RuntimeInitializeOnLoadMethod(
            RuntimeInitializeLoadType.BeforeSceneLoad)]
        private static void InstallRuntimeOwner()
        {
            EnsureRuntimeOwner();
        }

        private static void EnsureRuntimeOwner()
        {
            if (instance != null)
                return;

            instance = FindAnyObjectByType<PlayerStatisticsCloudSync>();
            if (instance == null)
            {
                GameObject owner = new GameObject(
                    nameof(PlayerStatisticsCloudSync));
                owner.AddComponent<PlayerStatisticsCloudSync>();
            }
        }

        private void Awake()
        {
            if (instance != null && instance != this)
            {
                Destroy(gameObject);
                return;
            }

            instance = this;
            DontDestroyOnLoad(gameObject);
            session = CreateRuntimeSession();
            Subscribe();
        }

        internal static void InvalidateAuthorization(string reason)
        {
            if (instance == null || instance.session == null)
                return;

            instance.session.Invalidate(reason);
        }

        private PlayerStatisticsSyncSession CreateRuntimeSession()
        {
            return new PlayerStatisticsSyncSession(
                SimpleCloudBackup.GetVerifiedCurrentOwnerId,
                () => SimpleCloudFiles.RestorePending ||
                      SimpleCloudFiles.StartupRestorePending,
                IsGoogleRun,
                IsGameplayReady,
                HasStartupFailure,
                CaptureSnapshot,
                UploadSnapshotAsync,
                () => Time.realtimeSinceStartup,
                IsAcceptedBackupCurrent);
        }

        internal static void NotifyBackupAccepted(
            CloudBackupEnvelope envelope)
        {
            instance?.HandleBackupAccepted(envelope);
        }

        internal static bool TryCaptureSnapshotFromSaveV2(
            string saveJson,
            out IDictionary<string, object> snapshot)
        {
            snapshot = null;
            if (string.IsNullOrEmpty(saveJson) ||
                !SaveManager.ValidateCloudSnapshot(saveJson))
                return false;

            PlayerSaveData save =
                JsonUtility.FromJson<PlayerSaveData>(saveJson);
            if (save == null || save.economy == null ||
                save.completedRebirthCount < 0 ||
                save.economy.cash < 0 ||
                save.economy.totalMoneyEarned < 0 ||
                save.economy.totalOrdersCompleted < 0)
                return false;

            snapshot = new Dictionary<string, object>
            {
                [CurrentMoneyKey] = save.economy.cash,
                [TotalMoneyEarnedKey] = save.economy.totalMoneyEarned,
                [TotalOrdersCompletedKey] =
                    save.economy.totalOrdersCompleted,
                [CurrentRebirthCountKey] = save.completedRebirthCount
            };
            return true;
        }

        private void HandleBackupAccepted(CloudBackupEnvelope envelope)
        {
            if (envelope == null ||
                string.IsNullOrWhiteSpace(envelope.playerId) ||
                !envelope.IsValid(envelope.playerId) ||
                !IsAcceptedBackupCurrent(envelope))
                return;

            acceptedBackupOwner = envelope.playerId;
            acceptedBackupEnvironment = envelope.environment;
            acceptedBackupSaveJson = envelope.saveJson;
            acceptedBackupChecksum = envelope.checksum;
            acceptedBackupRequired = true;
            if (!session.RegisterAcceptedBackupCandidate(
                    envelope.playerId))
                return;

            _ = session.RequestUploadAsync();
        }

        private bool IsAcceptedBackupCurrent()
        {
            if (!acceptedBackupRequired)
                return true;

            return !string.IsNullOrWhiteSpace(acceptedBackupOwner) &&
                   IsAcceptedBackupCurrent(
                       acceptedBackupOwner,
                       acceptedBackupEnvironment,
                       acceptedBackupSaveJson,
                       acceptedBackupChecksum);
        }

        private bool IsAcceptedBackupCurrent(CloudBackupEnvelope envelope)
        {
            return envelope != null &&
                   IsAcceptedBackupCurrent(
                       envelope.playerId,
                       envelope.environment,
                       envelope.saveJson,
                       envelope.checksum) &&
                   envelope.IsValid(envelope.playerId) &&
                   string.Equals(
                       envelope.checksum,
                       envelope.ContentHash(),
                       StringComparison.Ordinal);
        }

        private static bool IsAcceptedBackupCurrent(
            string owner,
            string environment,
            string saveJson,
            string checksum)
        {
            SaveManager save = SaveManager.Instance;
            if (save == null ||
                !save.IsLifecycleSavingReady ||
                !IsGameplayReady() ||
                HasStartupFailure() ||
                SimpleCloudFiles.RestorePending ||
                SimpleCloudFiles.StartupRestorePending ||
                !string.Equals(
                    environment,
                    SavePathPolicy.ModeName,
                    StringComparison.Ordinal) ||
                !SimpleCloudBackup.IsCurrentVerifiedOwner(owner) ||
                !LocalSaveOwnership.IsOwnedByForCloudUpload(
                    save.SaveFilePath,
                    owner,
                    environment,
                    SimpleCloudBackup.GetVerifiedCurrentOwnerId) ||
                !SaveManager.ValidateCloudSnapshot(saveJson))
                return false;

            // Statistics describe the acknowledged backup. Legitimate local saves
            // during the network request must not invalidate that acknowledgement.
            return SimpleCloudBackup.Instance != null &&
                   SimpleCloudBackup.Instance.IsAcceptedBackup(
                       owner, environment, saveJson, checksum);
        }

        private void Subscribe()
        {
            if (!subscribed)
            {
                SimpleCloudFiles.RestorePendingChanged +=
                    HandleRestorePendingChanged;
                SimpleCloudFiles.VerifiedRestorePromoted +=
                    HandleVerifiedRestorePromoted;
                StartupPlayModeStore.SelectionSaved +=
                    HandlePlayModeSaved;
                SceneManager.sceneLoaded += HandleSceneLoaded;
                Application.quitting += HandleApplicationQuitting;
                subscribed = true;
            }

            BindReadinessSources();
        }

        private void Unsubscribe()
        {
            if (!subscribed)
                return;

            SimpleCloudFiles.RestorePendingChanged -= HandleRestorePendingChanged;
            SimpleCloudFiles.VerifiedRestorePromoted -=
                HandleVerifiedRestorePromoted;
            StartupPlayModeStore.SelectionSaved -= HandlePlayModeSaved;
            SceneManager.sceneLoaded -= HandleSceneLoaded;
            Application.quitting -= HandleApplicationQuitting;
            if (subscribedStartup != null)
                subscribedStartup.StateChanged -= HandleStartupStateChanged;
            if (subscribedReadiness != null)
                subscribedReadiness.StateChanged -= HandleReadinessStateChanged;
            if (subscribedAuthentication != null)
                subscribedAuthentication.StateChanged -=
                    HandleAuthenticationStateChanged;
            subscribedStartup = null;
            subscribedReadiness = null;
            subscribedAuthentication = null;
            subscribed = false;
        }

        private void BindReadinessSources()
        {
            GameStartupCoordinator startup = GameStartupCoordinator.Instance;
            if (subscribedStartup != startup)
            {
                if (subscribedStartup != null)
                    subscribedStartup.StateChanged -= HandleStartupStateChanged;
                subscribedStartup = startup;
                if (subscribedStartup != null)
                    subscribedStartup.StateChanged += HandleStartupStateChanged;
            }

            ApplicationReadinessCoordinator readiness =
                ApplicationReadinessCoordinator.Instance;
            if (subscribedReadiness != readiness)
            {
                if (subscribedReadiness != null)
                    subscribedReadiness.StateChanged -= HandleReadinessStateChanged;
                subscribedReadiness = readiness;
                if (subscribedReadiness != null)
                    subscribedReadiness.StateChanged += HandleReadinessStateChanged;
            }

            GooglePlayGamesAuthenticationCoordinator authentication =
                GooglePlayGamesAuthenticationCoordinator.Instance;
            if (subscribedAuthentication != authentication)
            {
                if (subscribedAuthentication != null)
                {
                    subscribedAuthentication.StateChanged -=
                        HandleAuthenticationStateChanged;
                }

                subscribedAuthentication = authentication;
                if (subscribedAuthentication != null)
                {
                    subscribedAuthentication.StateChanged +=
                        HandleAuthenticationStateChanged;
                }
            }
        }

        private void HandleRestorePendingChanged(bool pending)
        {
            if (pending)
                session?.Invalidate("Statistics sync invalidated by a pending cloud restore.");
            else
                HandleSessionSignal();
        }

        private void HandleVerifiedRestorePromoted(string ownerId)
        {
            initialUploadAttempted = false;
            session?.RegisterPromotedRestoreCandidate(true, ownerId);
        }

        private void HandleStartupStateChanged()
        {
            if (HasStartupFailure())
                session?.Invalidate("Statistics sync invalidated by startup failure.");
            else
                HandleSessionSignal();
        }

        private void HandleReadinessStateChanged(
            ApplicationReadinessState state)
        {
            if (HasStartupFailure())
                session?.Invalidate("Statistics sync invalidated by unresolved startup.");
            else
                HandleSessionSignal();
        }

        private void HandleAuthenticationStateChanged()
        {
            HandleSessionSignal();
        }

        private void HandlePlayModeSaved(
            StartupPlayMode mode,
            bool googleAuthenticationPending)
        {
            if (mode != StartupPlayMode.Google ||
                googleAuthenticationPending)
            {
                session?.Invalidate(
                    "Statistics sync invalidated by a non-Google or unverified play-mode selection.");
                return;
            }

            HandleSessionSignal();
        }

        private void HandleSceneLoaded(Scene scene, LoadSceneMode mode)
        {
            HandleSessionSignal();
        }

        private void HandleApplicationQuitting()
        {
            session?.Invalidate("Application session ended.");
        }

        private void RequestInitialUpload()
        {
            BindReadinessSources();
            if (session == null || !session.HasRestoreCandidate ||
                initialUploadAttempted)
                return;

            if (!IsGameplayReady())
            {
                _ = session.RequestUploadAsync();
                return;
            }

            initialUploadAttempted = true;
            _ = session.RequestUploadAsync();
        }

        private void HandleSessionSignal()
        {
            BindReadinessSources();
            if (session == null)
                return;

            if (initialUploadAttempted)
                session.ValidateCurrentSession();
            else
                RequestInitialUpload();
        }

        private static bool IsGoogleRun()
        {
            // A guest can sign in from Settings without restarting the game.
            // Only an acknowledged backup for the verified owner grants this path.
            if (instance != null && instance.acceptedBackupRequired &&
                instance.IsAcceptedBackupCurrent())
                return true;

            StartupPlayModeLoadStatus status =
                new StartupPlayModeStore().Load(
                    out StartupPlayMode storedMode,
                    out bool authenticationPending,
                    out _);
            return status == StartupPlayModeLoadStatus.Loaded &&
                   storedMode == StartupPlayMode.Google &&
                   !authenticationPending;
        }

        private static bool IsGameplayReady()
        {
            GameStartupCoordinator startup = GameStartupCoordinator.Instance;
            ApplicationReadinessCoordinator readiness =
                ApplicationReadinessCoordinator.Instance;
            return startup != null &&
                   startup.IsStartupComplete &&
                   !startup.IsStartupBlocked &&
                   startup.IsGameplayReady &&
                   readiness != null &&
                   readiness.IsGameplayReady;
        }

        private static bool HasStartupFailure()
        {
            GameStartupCoordinator startup = GameStartupCoordinator.Instance;
            return SimpleCloudFiles.StartupError != null ||
                   (startup != null && startup.IsStartupBlocked);
        }

        private static IDictionary<string, object> CaptureSnapshot()
        {
            if (instance != null && instance.acceptedBackupRequired)
            {
                if (!TryCaptureSnapshotFromSaveV2(
                        instance.acceptedBackupSaveJson,
                        out IDictionary<string, object> acceptedSnapshot))
                    throw new InvalidDataException(
                        "Accepted Save V2 statistics could not be captured.");
                return acceptedSnapshot;
            }

            EconomyManager economy = EconomyManager.Instance;
            PlayerProgressionManager progression =
                PlayerProgressionManager.Instance;
            if (economy == null || progression == null)
                throw new InvalidOperationException(
                    "Statistics managers are unavailable after startup readiness.");

            return new Dictionary<string, object>
            {
                [CurrentMoneyKey] = economy.CurrentCash,
                [TotalMoneyEarnedKey] = economy.TotalMoneyEarned,
                [TotalOrdersCompletedKey] = economy.TotalOrdersCompleted,
                [CurrentRebirthCountKey] =
                    progression.CurrentRebirthCount
            };
        }

        private static async Task UploadSnapshotAsync(
            IDictionary<string, object> snapshot)
        {
            if (UnityServices.State != ServicesInitializationState.Initialized)
                throw new InvalidOperationException(
                    "Unity Services are not initialized.");

            var items = new Dictionary<string, SaveItem>(snapshot.Count);
            foreach (KeyValuePair<string, object> item in snapshot)
                items.Add(item.Key, new SaveItem(item.Value, null));

            await CloudSaveService.Instance.Data.Player.SaveAsync(
                items,
                new Unity.Services.CloudSave.Models.Data.Player.SaveOptions());
        }

        private void OnDestroy()
        {
            Unsubscribe();
            session?.Invalidate("Statistics sync owner was destroyed.");
            if (instance == this)
                instance = null;
        }
    }
}
