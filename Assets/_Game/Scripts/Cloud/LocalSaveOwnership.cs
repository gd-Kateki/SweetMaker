using System;
using System.IO;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using UnityEngine;

namespace SweetMerge.Cloud
{
    internal enum LocalSaveOwnershipEvidence
    {
        FreshVerifiedGoogleNewGame,
        ActivatedVerifiedRestore,
        ExplicitGuestLink
    }

    [Serializable]
    internal sealed class LocalSaveOwnershipRecord
    {
        public int version;
        public string environment;
        public string playerId;
        public string saveSha256;
    }

    internal static class LocalSaveOwnership
    {
        private const int CurrentVersion = 1;
        private const int MaximumRecordBytes = 4096;
        private const uint ReplaceExisting = 0x1;
        private const uint WriteThrough = 0x8;
        private static readonly UTF8Encoding Utf8 =
            new UTF8Encoding(false, true);

        internal static bool CanEstablishFreshGoogle(
            bool googleModeSelected,
            bool googleIdentityVerified,
            bool noPriorProfileOrRecovery,
            bool snapshotCommitted,
            bool gameplayReady,
            bool samePlayerId,
            bool restorePending)
        {
            return googleModeSelected &&
                   googleIdentityVerified &&
                   noPriorProfileOrRecovery &&
                   snapshotCommitted &&
                   gameplayReady &&
                   samePlayerId &&
                   !restorePending;
        }

        internal static bool CanEstablishVerifiedRestore(
            bool googleModeSelected,
            bool envelopeVerifiedForPlayer,
            bool promotionSucceeded,
            bool saveLoaded,
            bool gameplayReady,
            bool restorePending,
            bool samePlayerId)
        {
            return googleModeSelected &&
                   envelopeVerifiedForPlayer &&
                   promotionSucceeded &&
                   saveLoaded &&
                   gameplayReady &&
                   !restorePending &&
                   samePlayerId;
        }

        internal static bool CanEstablishGuestLink(
            bool explicitConsent,
            bool confirmedPlayerMatches,
            bool localSaveValid,
            bool markerAbsent,
            bool restorePending)
        {
            return explicitConsent &&
                   confirmedPlayerMatches &&
                   localSaveValid &&
                   markerAbsent &&
                   !restorePending;
        }

#if UNITY_EDITOR_WIN || UNITY_STANDALONE_WIN
        [DllImport(
            "kernel32.dll",
            EntryPoint = "MoveFileExW",
            CharSet = CharSet.Unicode,
            ExactSpelling = true,
            SetLastError = true)]
        [return: MarshalAs(UnmanagedType.Bool)]
        private static extern bool MoveFileWindows(
            string source,
            string destination,
            uint flags);
#elif UNITY_ANDROID && !UNITY_EDITOR
        [DllImport(
            "libc",
            EntryPoint = "rename",
            CallingConvention = CallingConvention.Cdecl,
            ExactSpelling = true,
            SetLastError = true)]
        private static extern int RenameFileAndroid(
            byte[] source,
            byte[] destination);
#endif

        internal static string MarkerPath(string saveFilePath)
        {
            if (string.IsNullOrWhiteSpace(saveFilePath))
                throw new ArgumentException(
                    "The Save V2 path is required.",
                    nameof(saveFilePath));

            return Path.GetFullPath(saveFilePath) + ".owner-v1.json";
        }

        internal static bool HasNoExistingProfileOrRecovery(
            string saveFilePath,
            string legacySaveFilePath,
            out string errorMessage)
        {
            errorMessage = null;
            try
            {
                string directory = Path.GetDirectoryName(
                    Path.GetFullPath(saveFilePath));
                string[] paths =
                {
                    saveFilePath,
                    saveFilePath + ".bak",
                    saveFilePath + ".tmp",
                    saveFilePath + ".bak.tmp",
                    saveFilePath + ".recover.tmp",
                    MarkerPath(saveFilePath),
                    MarkerPath(saveFilePath) + ".tmp",
                    legacySaveFilePath,
                    legacySaveFilePath + ".bak",
                    legacySaveFilePath + ".tmp",
                    Path.Combine(directory, "cloud-restore.pending.json")
                };
                foreach (string path in paths)
                {
                    if (File.Exists(path) || Directory.Exists(path))
                    {
                        errorMessage =
                            "Existing save or recovery data was found.";
                        return false;
                    }
                }

                if (Directory.Exists(Path.Combine(directory, "CloudRecovery")) &&
                    Directory.GetFileSystemEntries(
                        Path.Combine(directory, "CloudRecovery")).Length > 0)
                {
                    errorMessage =
                        "A cloud recovery archive already exists.";
                    return false;
                }

                if (Directory.Exists(directory) &&
                    (Directory.GetFiles(
                         directory,
                         Path.GetFileName(saveFilePath) + ".corrupt.*",
                         SearchOption.TopDirectoryOnly).Length > 0 ||
                     Directory.GetFiles(
                         directory,
                         Path.GetFileName(saveFilePath) + ".owner-v1.json.*.tmp",
                         SearchOption.TopDirectoryOnly).Length > 0))
                {
                    errorMessage =
                        "Unresolved save recovery files were found.";
                    return false;
                }

                return true;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Save history could not be verified: " +
                    exception.Message;
                return false;
            }
        }

        internal static bool CanExplicitlyLink(
            string saveFilePath,
            string playerId,
            string environment)
        {
            if (string.IsNullOrWhiteSpace(playerId) ||
                string.IsNullOrWhiteSpace(environment) ||
                SimpleCloudFiles.RestorePending ||
                SimpleCloudFiles.StartupRestorePending ||
                SimpleCloudFiles.StartupError != null)
                return false;

            try
            {
                string markerPath = MarkerPath(saveFilePath);
                if (File.Exists(markerPath) ||
                    Directory.Exists(markerPath) ||
                    !File.Exists(saveFilePath) ||
                    HasUnresolvedRecoveryFiles(saveFilePath))
                    return false;

                return SaveManager.ValidateCloudSnapshot(
                    File.ReadAllText(saveFilePath, Utf8)) &&
                    string.Equals(
                        SimpleCloudBackup.GetVerifiedCurrentOwnerId(),
                        playerId,
                        StringComparison.Ordinal);
            }
            catch (Exception exception)
            {
                Debug.LogWarning(
                    "SAVE OWNERSHIP | Guest-link eligibility could not be " +
                    "verified.\n" + exception);
                return false;
            }
        }

        internal static bool IsOwnedBy(
            string saveFilePath,
            string playerId,
            string environment)
        {
            if (string.IsNullOrWhiteSpace(playerId) ||
                string.IsNullOrWhiteSpace(environment) ||
                SimpleCloudFiles.RestorePending ||
                SimpleCloudFiles.StartupRestorePending)
                return false;

            try
            {
                string markerPath = MarkerPath(saveFilePath);
                if (!File.Exists(saveFilePath) ||
                    !File.Exists(markerPath))
                    return false;

                byte[] saveBytes = File.ReadAllBytes(saveFilePath);
                byte[] recordBytes = File.ReadAllBytes(markerPath);
                if (recordBytes.Length <= 0 ||
                    recordBytes.Length > MaximumRecordBytes)
                    return false;

                LocalSaveOwnershipRecord record =
                    JsonUtility.FromJson<LocalSaveOwnershipRecord>(
                        Utf8.GetString(recordBytes));
                return record != null &&
                       record.version == CurrentVersion &&
                       string.Equals(
                           record.environment,
                           environment,
                           StringComparison.Ordinal) &&
                       string.Equals(
                           record.playerId,
                           playerId,
                           StringComparison.Ordinal) &&
                       string.Equals(
                           record.saveSha256,
                           Hash(saveBytes),
                           StringComparison.Ordinal);
            }
            catch (Exception exception)
            {
                Debug.LogWarning(
                    "SAVE OWNERSHIP | Marker validation failed closed.\n" +
                    exception);
                return false;
            }
        }

        internal static bool IsOwnedByForCloudUpload(
            string saveFilePath,
            string playerId,
            string environment,
            Func<string> getVerifiedPlayerId)
        {
            if (getVerifiedPlayerId == null ||
                string.IsNullOrWhiteSpace(playerId) ||
                !string.Equals(
                    environment,
                    SavePathPolicy.ModeName,
                    StringComparison.Ordinal) ||
                SimpleCloudFiles.RestorePending ||
                SimpleCloudFiles.StartupRestorePending ||
                SimpleCloudFiles.StartupError != null)
                return false;

            try
            {
                if (!string.Equals(
                        getVerifiedPlayerId(),
                        playerId,
                        StringComparison.Ordinal) ||
                    HasUnresolvedRecoveryFiles(saveFilePath))
                    return false;

                return IsOwnedBy(
                    saveFilePath,
                    playerId,
                    environment);
            }
            catch (Exception exception)
            {
                Debug.LogWarning(
                    "SAVE OWNERSHIP | Cloud upload authorization failed closed.\n" +
                    exception);
                return false;
            }
        }

        private static bool HasUnresolvedRecoveryFiles(string saveFilePath)
        {
            string fullPath = Path.GetFullPath(saveFilePath);
            string directory = Path.GetDirectoryName(fullPath);
            string fileName = Path.GetFileName(fullPath);
            if (File.Exists(fullPath + ".tmp") ||
                File.Exists(fullPath + ".bak.tmp") ||
                File.Exists(fullPath + ".recover.tmp") ||
                File.Exists(Path.Combine(
                    directory,
                    "cloud-restore.pending.json")))
                return true;

            if (!Directory.Exists(directory))
                return false;

            return Directory.GetFiles(
                       directory,
                       fileName + ".corrupt.*",
                       SearchOption.TopDirectoryOnly).Length > 0 ||
                   Directory.GetFiles(
                       directory,
                       fileName + ".bak.corrupt.*",
                       SearchOption.TopDirectoryOnly).Length > 0 ||
                   Directory.GetFiles(
                       directory,
                       fileName + ".owner-v1.json.*.tmp",
                       SearchOption.TopDirectoryOnly).Length > 0;
        }

        internal static bool TryEstablishForCurrentPlayer(
            string saveFilePath,
            LocalSaveOwnershipEvidence evidence,
            out string errorMessage)
        {
            string playerId;
            try
            {
                playerId =
                    SimpleCloudBackup.GetVerifiedCurrentOwnerId();
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Verified Google ownership could not be checked: " +
                    exception.Message;
                return false;
            }

            return TryEstablish(
                saveFilePath,
                playerId,
                SavePathPolicy.ModeName,
                evidence,
                SimpleCloudBackup.GetVerifiedCurrentOwnerId,
                out errorMessage);
        }

        internal static bool TryEstablish(
            string saveFilePath,
            string playerId,
            string environment,
            LocalSaveOwnershipEvidence evidence,
            Func<string> getVerifiedPlayerId,
            out string errorMessage)
        {
            errorMessage = null;
            if (string.IsNullOrWhiteSpace(playerId) ||
                string.IsNullOrWhiteSpace(environment) ||
                getVerifiedPlayerId == null ||
                !Enum.IsDefined(
                    typeof(LocalSaveOwnershipEvidence),
                    evidence))
            {
                errorMessage =
                    "A verified PlayerId, environment, and ownership event are required.";
                return false;
            }

            try
            {
                if (SimpleCloudFiles.RestorePending ||
                    SimpleCloudFiles.StartupRestorePending)
                    throw new InvalidOperationException(
                        "Ownership cannot be established during a pending restore.");

                string markerPath = MarkerPath(saveFilePath);
                if (File.Exists(markerPath) ||
                    Directory.Exists(markerPath))
                    throw new InvalidOperationException(
                        "Ownership is already present or unknown; it cannot be reassigned.");

                if (!string.Equals(
                        getVerifiedPlayerId(),
                        playerId,
                        StringComparison.Ordinal))
                    throw new InvalidOperationException(
                        "The supplied PlayerId is not the currently verified owner.");

                if (!TryWriteAndValidate(
                    saveFilePath,
                    playerId,
                    environment,
                    out errorMessage))
                    return false;

                if (!string.Equals(
                        getVerifiedPlayerId(),
                        playerId,
                        StringComparison.Ordinal))
                {
                    TryInvalidate(saveFilePath, out _);
                    errorMessage =
                        "The verified account changed during ownership establishment.";
                    return false;
                }

                return true;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Save ownership could not be established: " +
                    exception.Message;
                return false;
            }
        }

        internal static bool TryRefreshAfterSave(
            string saveFilePath,
            string playerId,
            string environment,
            bool wasOwned,
            out string errorMessage)
        {
            return TryRefreshAfterSave(
                saveFilePath,
                playerId,
                environment,
                wasOwned,
                SimpleCloudBackup.GetVerifiedCurrentOwnerId,
                out errorMessage);
        }

        internal static bool TryRefreshAfterSave(
            string saveFilePath,
            string playerId,
            string environment,
            bool wasOwned,
            Func<string> getVerifiedPlayerId,
            out string errorMessage)
        {
            errorMessage = null;
            if (!wasOwned)
                return true;

            if (string.IsNullOrWhiteSpace(playerId) ||
                string.IsNullOrWhiteSpace(environment))
            {
                errorMessage =
                    "The verified owner is unavailable after the save.";
                TryInvalidate(saveFilePath, out _);
                return false;
            }

            try
            {
                if (SimpleCloudFiles.RestorePending ||
                    SimpleCloudFiles.StartupRestorePending)
                    throw new InvalidOperationException(
                        "Ownership cannot be refreshed during a pending restore.");

                if (!string.Equals(
                        getVerifiedPlayerId(),
                        playerId,
                        StringComparison.Ordinal))
                    throw new InvalidOperationException(
                        "The verified account changed during the Save V2 update.");

                return TryWriteAndValidate(
                    saveFilePath,
                    playerId,
                    environment,
                    out errorMessage);
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Save ownership could not be refreshed: " +
                    exception.Message;
                TryInvalidate(saveFilePath, out _);
                return false;
            }
        }

        private static bool TryWriteAndValidate(
            string saveFilePath,
            string playerId,
            string environment,
            out string errorMessage)
        {
            errorMessage = null;
            try
            {
                byte[] saveBytes = File.ReadAllBytes(saveFilePath);
                if (!SaveManager.ValidateCloudSnapshot(Utf8.GetString(saveBytes)))
                    throw new InvalidDataException(
                        "The active file is not a valid Save V2 snapshot.");

                var record = new LocalSaveOwnershipRecord
                {
                    version = CurrentVersion,
                    environment = environment,
                    playerId = playerId,
                    saveSha256 = Hash(saveBytes)
                };
                byte[] recordBytes = Utf8.GetBytes(
                    JsonUtility.ToJson(record, false));
                WriteMarkerAtomically(
                    MarkerPath(saveFilePath),
                    recordBytes);

                if (!IsOwnedBy(saveFilePath, playerId, environment))
                    throw new IOException(
                        "The committed ownership marker did not validate.");

                return true;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Save ownership marker could not be committed: " +
                    exception.Message;
                if (!TryInvalidate(saveFilePath, out string invalidationError))
                    errorMessage +=
                        " The previous marker could not be removed: " +
                        invalidationError;
                return false;
            }
        }

        internal static bool TryInvalidate(
            string saveFilePath,
            out string errorMessage)
        {
            errorMessage = null;
            try
            {
                string markerPath = MarkerPath(saveFilePath);
                if (Directory.Exists(markerPath))
                {
                    errorMessage =
                        "The ownership marker path is occupied by a directory.";
                    return false;
                }

                if (File.Exists(markerPath))
                    File.Delete(markerPath);

                return !File.Exists(markerPath) &&
                       !Directory.Exists(markerPath);
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Save ownership marker could not be invalidated: " +
                    exception.Message;
                return false;
            }
        }

        private static string Hash(byte[] bytes)
        {
            using (SHA256 algorithm = SHA256.Create())
                return Convert.ToBase64String(algorithm.ComputeHash(bytes));
        }

        private static void WriteMarkerAtomically(
            string markerPath,
            byte[] expectedBytes)
        {
            string directory = Path.GetDirectoryName(markerPath);
            Directory.CreateDirectory(directory);
            string temporaryPath = markerPath + "." +
                Guid.NewGuid().ToString("N") + ".tmp";

            try
            {
                using (var stream = new FileStream(
                    temporaryPath,
                    FileMode.CreateNew,
                    FileAccess.Write,
                    FileShare.None))
                {
                    stream.Write(expectedBytes, 0, expectedBytes.Length);
                    stream.Flush(true);
                }

                if (!BytesEqual(
                        File.ReadAllBytes(temporaryPath),
                        expectedBytes))
                    throw new IOException(
                        "The staged ownership marker failed byte verification.");

                AtomicReplaceFile(temporaryPath, markerPath);
                if (!BytesEqual(
                        File.ReadAllBytes(markerPath),
                        expectedBytes))
                    throw new IOException(
                        "The committed ownership marker failed byte verification.");
            }
            finally
            {
                if (File.Exists(temporaryPath))
                {
                    try
                    {
                        File.Delete(temporaryPath);
                    }
                    catch (Exception exception)
                    {
                        Debug.LogWarning(
                            "SAVE OWNERSHIP | Temporary marker cleanup failed: " +
                            exception.Message);
                    }
                }
            }
        }

        private static void AtomicReplaceFile(
            string source,
            string destination)
        {
#if UNITY_EDITOR_WIN || UNITY_STANDALONE_WIN
            if (!MoveFileWindows(
                    source,
                    destination,
                    ReplaceExisting | WriteThrough))
            {
                throw new IOException(
                    "Ownership marker commit failed (Windows error " +
                    Marshal.GetLastWin32Error() + ").");
            }
#elif UNITY_ANDROID && !UNITY_EDITOR
            if (RenameFileAndroid(
                    Utf8.GetBytes(source + "\0"),
                    Utf8.GetBytes(destination + "\0")) != 0)
            {
                throw new IOException(
                    "Ownership marker commit failed (Android errno " +
                    Marshal.GetLastWin32Error() + ").");
            }
#else
            if (File.Exists(destination))
                File.Replace(source, destination, null);
            else
                File.Move(source, destination);
#endif
        }

        private static bool BytesEqual(byte[] left, byte[] right)
        {
            if (left == null || right == null ||
                left.Length != right.Length)
                return false;

            for (int index = 0; index < left.Length; index++)
            {
                if (left[index] != right[index])
                    return false;
            }

            return true;
        }
    }
}
