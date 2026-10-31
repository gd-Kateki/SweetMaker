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

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
        private static void Create()
        {
            if (Instance == null) new GameObject("Cloud backup").AddComponent<SimpleCloudBackup>();
        }
        private void Awake()
        {
            Instance = this; DontDestroyOnLoad(gameObject);
            if (SimpleCloudFiles.StartupError != null) SimpleCloudPanel.ShowRestartOverlay();
        }
        private void OnDestroy() { if (Instance == this) Instance = null; }

        private static string CurrentOwner()
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

        private void Update()
        {
            string current = CurrentOwner();
            if (owner != current)
            {
                owner = current; identityEpoch++; acceptedHash = null; remote = null;
                writeLock = null; ChoiceRequired = false; paused = false; failures = 0;
                Status = current == null ? "Offline/local play. Cloud backup is disconnected." : "Checking account backup…";
                nextCheck = 0;
            }
            if (!Busy && !paused && owner != null && !ChoiceRequired &&
                !SimpleCloudFiles.RestorePending && Time.unscaledTime >= nextCheck)
                _ = CheckAsync(false);
        }

        private bool StillCurrent(string id, int epoch) => owner == id &&
            identityEpoch == epoch && CurrentOwner() == id && !SimpleCloudFiles.RestorePending;
        private string Key => "dmc_backup_v1_" + SavePathPolicy.ModeName;

        // 0 = same copy, 1 = safe continuation of the accepted cloud copy, 2 = player choice.
        public static int Decide(string localHash, string remoteHash, string accepted)
        {
            if (remoteHash != null && remoteHash == localHash) return 0;
            if (accepted != null && remoteHash != null && remoteHash == accepted) return 1;
            return 2;
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
            if (!value.IsValid(id)) throw new IOException("Local backup validation failed. Local files are unchanged.");
            return value;
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
                catch (IOException ex) { localMessage = ex.Message; }
                if (!StillCurrent(id, epoch)) return;
                if (local == null)
                {
                    acceptedHash = null; ChoiceRequired = remote != null;
                    Status = remote != null ? "Cloud progress is available. You can restore it on this device." : localMessage;
                    nextCheck = Time.unscaledTime + 30;
                    return;
                }
                int decision = Decide(local.checksum, remote?.checksum, acceptedHash);
                if (decision == 0)
                {
                    acceptedHash = local.checksum; ChoiceRequired = false;
                    Status = "Cloud backup is up to date.";
                }
                else if (decision == 1)
                    await UploadAsync(local, id, epoch);
                else
                {
                    ChoiceRequired = true;
                    Status = remote == null ? "No backup for this account. Choose Back up this device." :
                        "Device and cloud progress differ. Choose which copy to keep.";
                }
                failures = 0; nextCheck = Time.unscaledTime + 30;
            }
            catch (OperationCanceledException) { }
            catch (InvalidDataException ex) { paused = true; ChoiceRequired = false; Status = ex.Message; }
            catch (Exception) { Failed(); }
            finally { Busy = false; }
        }

        private void Failed()
        {
            // A write may have succeeded even if its response was lost. Re-read before retrying.
            acceptedHash = null; ChoiceRequired = false;
            failures++; paused = failures >= 3;
            nextCheck = Time.unscaledTime + 10 * failures;
            Status = paused ? "Cloud backup paused. Local progress is safe. Tap Check / retry." :
                "Cloud unavailable or progress changed. Local play continues; checking again shortly.";
        }

        private async Task UploadAsync(CloudBackupEnvelope local, string id, int epoch)
        {
            if (!StillCurrent(id, epoch)) throw new OperationCanceledException();
            // Null is used only for a confirmed absent key; every existing key uses its write lock.
            var locks = await CloudSaveService.Instance.Data.Player.SaveAsync(
                new Dictionary<string, SaveItem> { [Key] = new SaveItem(JsonUtility.ToJson(local), writeLock) },
                new Unity.Services.CloudSave.Models.Data.Player.SaveOptions());
            if (!StillCurrent(id, epoch)) throw new OperationCanceledException();
            if (!locks.TryGetValue(Key, out writeLock) || string.IsNullOrEmpty(writeLock))
                throw new IOException("Cloud write was not acknowledged.");
            remote = local; acceptedHash = local.checksum; ChoiceRequired = false;
            Status = "Cloud backup saved.";
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
            catch (Exception) { Failed(); }
            finally { Busy = false; }
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
