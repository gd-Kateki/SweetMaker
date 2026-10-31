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
        public static string StartupError { get; private set; }
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
            try { StageRestoreAtRoot(Root, value); }
            finally { RestorePending = File.Exists(Pending); }
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
        private static void ApplyBeforeStoresLoad()
        {
            RestorePending = false; StartupError = null;
            try
            {
                if (!File.Exists(Pending)) return;
                RestorePending = true;
                ApplyPendingAtRoot(Root);
                RestorePending = false;
            }
            catch (Exception)
            {
                StartupError = "Cloud restore could not finish. Restart to retry. Previous files remain in CloudRecovery.";
                Debug.LogError(StartupError);
            }
        }

        private static void ApplyPendingAtRoot(string root)
        {
                string pending = Path.Combine(root, "cloud-restore.pending.json");
                var value = JsonUtility.FromJson<CloudBackupEnvelope>(File.ReadAllText(pending));
                if (value == null || !value.IsValid(value.playerId))
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
