using System;
using System.IO;
using System.Security.Cryptography;
using System.Text;
using SweetMerge.Profile;
using UnityEngine;

namespace SweetMerge.Cloud
{
    // A single durable pending envelope lets an interrupted restore finish before any store loads.
    // Recovery folders and completed envelopes are retained; ordinary save/recovery remains unchanged.
    public static class SimpleCloudFiles
    {
        public static bool RestorePending { get; private set; }
        public static bool StartupRestorePending { get; private set; }
        public static string StartupError { get; private set; }
        public static event Action<bool> RestorePendingChanged;
        internal static event Action<string> VerifiedRestorePromoted;
        private static string Root => SavePathPolicy.GetSaveDirectory();
        private static string Pending => Path.Combine(Root, "cloud-restore.pending.json");
        public static string Hash(string value)
        {
            using (var sha = SHA256.Create())
                return Convert.ToBase64String(sha.ComputeHash(Encoding.UTF8.GetBytes(value)));
        }

        private static readonly string[] RelativeFiles = {
            "player_save_v2.json", "player_save_v2.json.bak", "player_save_v2.json.tmp",
            "CafeProfile/cafe-profile-v1.json", "CafeProfile/cafe-profile-v1.json.bak",
            "CafeProfile/cafe-profile-v1.json.tmp", "CafeProfile/cafe-profile-v1.json.recover.tmp",
            "CafeProfile/cafe-profile-v1.json.bak.tmp",
            "TutorialProgress/tutorial-progress-v1.json", "TutorialProgress/tutorial-progress-v1.json.bak",
            "TutorialProgress/tutorial-progress-v1.json.tmp", "TutorialProgress/tutorial-progress-v1.json.recover.tmp"
        };

        public static void StageRestore(CloudBackupEnvelope value)
        {
            try
            {
                StageRestoreAtRoot(Root, value);
                SetRestorePending(true);
            }
            finally
            {
                if (File.Exists(Pending))
                    SetRestorePending(true);
            }
        }

        private static void StageRestoreAtRoot(string root, CloudBackupEnvelope value)
        {
            if (value == null || !value.IsValid(value.playerId)) throw new InvalidDataException("Invalid restore.");
            string pending = Path.Combine(root, "cloud-restore.pending.json");
            if (File.Exists(pending)) throw new IOException("A restore is already pending.");
            string recovery = Path.Combine(root, "CloudRecovery", Guid.NewGuid().ToString("N"));
            foreach (string relative in RelativeFiles)
            {
                string source = Path.Combine(root, relative);
                if (!File.Exists(source)) continue;
                byte[] bytes = File.ReadAllBytes(source);
                string target = Path.Combine(recovery, relative);
                Directory.CreateDirectory(Path.GetDirectoryName(target));
                WriteNew(target, bytes);
                if (Convert.ToBase64String(File.ReadAllBytes(target)) != Convert.ToBase64String(bytes))
                    throw new IOException("Recovery copy verification failed.");
            }
            WriteAtomic(pending, JsonUtility.ToJson(value));
        }

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSplashScreen)]
        private static void DetectPendingBeforeSceneAwake()
        {
            RefreshPendingState();
        }

        internal static bool RefreshPendingState()
        {
            return RefreshPendingStateAtRoot(Root);
        }

        internal static bool RefreshPendingStateAtRoot(string root)
        {
            try
            {
                bool pending = DetectPendingAtRoot(root);
                StartupRestorePending = pending;
                SetRestorePending(pending);
                if (!pending)
                    StartupError = null;
                return pending;
            }
            catch (Exception)
            {
                StartupRestorePending = true;
                SetRestorePending(true);
                StartupError =
                    "Pending cloud restore status could not be checked. " +
                    "Startup is blocked to protect local data.";
                Debug.LogError(StartupError);
                return true;
            }
        }

        public static bool TryApplyPendingRestore(out string errorMessage)
        {
            errorMessage = null;
            try
            {
                if (!StartupRestorePending)
                {
                    errorMessage =
                        "A pending restore can only be applied before startup data is loaded.";
                    return false;
                }

                if (!FileExistsOrThrow(Pending))
                {
                    StartupRestorePending = false;
                    SetRestorePending(false);
                    StartupError = null;
                    return true;
                }

                SetRestorePending(true);
                string verifiedOwner =
                    SimpleCloudBackup.GetVerifiedCurrentOwnerId();
                if (string.IsNullOrEmpty(verifiedOwner))
                {
                    errorMessage =
                        "Connect and verify the Google Play Games account " +
                        "that owns this pending restore.";
                    return false;
                }

                ApplyPendingAtRoot(Root, verifiedOwner);
                StartupError = null;
                NotifyVerifiedRestorePromoted(verifiedOwner);
                StartupRestorePending = false;
                SetRestorePending(false);
                return true;
            }
            catch (Exception exception)
            {
                try
                {
                    bool pending = FileExistsOrThrow(Pending);
                    StartupRestorePending = pending;
                    SetRestorePending(pending);
                }
                catch (Exception statusException)
                {
                    Debug.LogError(
                        "CLOUD RESTORE | Pending status could not be checked.\n" +
                        statusException);
                    SetRestorePending(true);
                }
                StartupError =
                    "Cloud restore could not finish. Retry with the matching " +
                    "Google account. Previous files remain in CloudRecovery.";
                errorMessage = StartupError;
                Debug.LogError(StartupError + "\n" + exception);
                return false;
            }
        }

        private static void ApplyPendingAtRoot(
            string root,
            string verifiedOwner)
        {
                string pending = Path.Combine(root, "cloud-restore.pending.json");
                var value = JsonUtility.FromJson<CloudBackupEnvelope>(File.ReadAllText(pending));
                if (value == null || !value.IsValid(verifiedOwner))
                    throw new InvalidDataException("The pending cloud restore failed validation.");
                string cafe = JsonUtility.ToJson(new CafeProfileLocalRecordData {
                    version = 1, environment = value.environment, cafeName = value.cafeName, namingCompleted = true });
                string tutorial = JsonUtility.ToJson(new TutorialProgressJournalRecord {
                    version = 1, environment = value.environment, stage = value.tutorialStage,
                    completed = value.tutorialStage == (int)TutorialStage.Completed });
                foreach (string relative in RelativeFiles)
                {
                    // Replace all recovery candidates too, so a previous café or later tutorial cannot win.
                    string content = relative.StartsWith("CafeProfile/") ? cafe :
                        relative.StartsWith("TutorialProgress/") ? tutorial : value.saveJson;
                    WriteAtomic(Path.Combine(root, relative), content);
                }
                File.Move(pending, pending + ".completed." + Guid.NewGuid().ToString("N"));
        }

        internal static bool DetectPendingAtRoot(string root)
        {
            return FileExistsOrThrow(
                Path.Combine(root, "cloud-restore.pending.json"));
        }

        private static bool FileExistsOrThrow(string path)
        {
            try
            {
                File.GetAttributes(path);
                return true;
            }
            catch (FileNotFoundException)
            {
                return false;
            }
            catch (DirectoryNotFoundException)
            {
                return false;
            }
        }

        internal static void ResetStateForTests()
        {
            RestorePending = false;
            StartupRestorePending = false;
            StartupError = null;
            RestorePendingChanged = null;
            VerifiedRestorePromoted = null;
        }

        private static void SetRestorePending(bool pending)
        {
            if (RestorePending == pending)
                return;

            RestorePending = pending;
            Action<bool> listeners = RestorePendingChanged;
            if (listeners == null)
                return;

            foreach (Action<bool> listener in listeners.GetInvocationList())
            {
                try
                {
                    listener(pending);
                }
                catch (Exception exception)
                {
                    Debug.LogError(
                        "CLOUD RESTORE | A restore-state listener failed.\n" +
                        exception);
                }
            }
        }

        private static void NotifyVerifiedRestorePromoted(string ownerId)
        {
            Action<string> listeners = VerifiedRestorePromoted;
            if (listeners == null)
                return;

            foreach (Action<string> listener in listeners.GetInvocationList())
            {
                try
                {
                    listener(ownerId);
                }
                catch (Exception exception)
                {
                    Debug.LogError(
                        "CLOUD RESTORE | A restore completion listener failed.\n" +
                        exception);
                }
            }
        }

        private static void WriteNew(string path, byte[] bytes)
        {
            using (var stream = new FileStream(path, FileMode.CreateNew, FileAccess.Write, FileShare.None))
            { stream.Write(bytes, 0, bytes.Length); stream.Flush(true); }
        }

        private static void WriteAtomic(string path, string content)
        {
            Directory.CreateDirectory(Path.GetDirectoryName(path));
            string temporary = path + ".cloud." + Guid.NewGuid().ToString("N");
            byte[] bytes = new UTF8Encoding(false, true).GetBytes(content);
            WriteNew(temporary, bytes);
            if (File.ReadAllText(temporary, Encoding.UTF8) != content) throw new IOException("Staging failed.");
            SaveManager.CommitCloudFile(temporary, path);
            if (File.ReadAllText(path, Encoding.UTF8) != content) throw new IOException("Commit verification failed.");
        }
    }
}
