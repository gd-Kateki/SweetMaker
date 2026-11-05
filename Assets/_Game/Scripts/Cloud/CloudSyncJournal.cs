using System;
using System.IO;
using System.Text;
using UnityEngine;

namespace SweetMerge.Cloud
{
    [Serializable]
    internal sealed class CloudSyncRecord
    {
        public int version = 1;
        public string playerId, environment, acceptedHash, writeLock;
        public bool newGameApproved;
    }

    // This is synchronization history, not proof of local-save ownership.
    // Uploads still require the separately validated ownership marker.
    internal static class CloudSyncJournal
    {
        internal const string FileName = "cloud-sync-v1.json";

        internal static CloudSyncRecord Read(string root, string playerId, string environment)
        {
            string path = Path.Combine(root, FileName);
            if (!File.Exists(path)) return null;
            var record = JsonUtility.FromJson<CloudSyncRecord>(File.ReadAllText(path));
            if (record == null || record.version != 1 ||
                string.IsNullOrWhiteSpace(record.acceptedHash) ||
                (record.newGameApproved && string.IsNullOrWhiteSpace(record.writeLock)))
                throw new InvalidDataException("Cloud sync history is invalid. Neither save was replaced.");
            return record.playerId == playerId && record.environment == environment ? record : null;
        }

        internal static void Write(string root, string playerId, string environment,
            string acceptedHash, string writeLock, bool newGameApproved)
        {
            if (string.IsNullOrWhiteSpace(playerId) || string.IsNullOrWhiteSpace(environment) ||
                string.IsNullOrWhiteSpace(acceptedHash) ||
                (newGameApproved && string.IsNullOrWhiteSpace(writeLock)))
                throw new InvalidDataException("Incomplete cloud sync history.");
            Directory.CreateDirectory(root);
            string path = Path.Combine(root, FileName);
            string temp = path + ".tmp";
            string json = JsonUtility.ToJson(new CloudSyncRecord {
                playerId = playerId, environment = environment, acceptedHash = acceptedHash,
                writeLock = writeLock, newGameApproved = newGameApproved });
            byte[] bytes = new UTF8Encoding(false, true).GetBytes(json);
            using (var stream = new FileStream(temp, FileMode.Create, FileAccess.Write, FileShare.None))
            {
                stream.Write(bytes, 0, bytes.Length);
                stream.Flush(true);
            }
            SaveManager.CommitCloudFile(temp, path);
            if (File.ReadAllText(path) != json) throw new IOException("Cloud sync history was not persisted.");
        }
    }
}
