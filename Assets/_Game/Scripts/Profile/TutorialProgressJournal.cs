using System;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;
using UnityEngine;

namespace SweetMerge.Profile
{
    [Serializable]
    internal sealed class TutorialProgressJournalRecord
    {
        public int version;
        public string environment;
        public int stage;
        public bool completed;
    }

    internal enum TutorialProgressJournalLoadStatus
    {
        Missing,
        Loaded,
        InvalidData,
        ServiceError
    }

    internal enum TutorialProgressJournalSaveStatus
    {
        Saved,
        InvalidData,
        ServiceError
    }

    internal static class TutorialProgressJournal
    {
        private const int CurrentVersion = 1;
        private const string DirectoryName = "TutorialProgress";
        private const string FileName = "tutorial-progress-v1.json";
        private const uint ReplaceExisting = 0x1;
        private const uint WriteThrough = 0x8;
        private static readonly UTF8Encoding Utf8 =
            new UTF8Encoding(false, true);

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

        private sealed class Candidate
        {
            public string Path;
            public byte[] Bytes;
            public TutorialProgressStageData Data;
        }

        private sealed class TutorialProgressStageData
        {
            public TutorialStage Stage;
        }

        internal static TutorialProgressJournalLoadStatus TryLoad(
            out TutorialStage stage,
            out string errorMessage)
        {
            stage = TutorialStage.Welcome;
            errorMessage = null;
            if (SweetMerge.Cloud.SimpleCloudFiles.RestorePending)
            {
                errorMessage =
                    "Tutorial progress loading is blocked until the pending cloud restore is resolved.";
                return TutorialProgressJournalLoadStatus.ServiceError;
            }

            if (!TryGetPaths(
                    out string primary,
                    out string backup,
                    out string temporary,
                    out string recoveryTemporary,
                    out errorMessage))
                return TutorialProgressJournalLoadStatus.ServiceError;

            string[] paths =
            {
                primary,
                backup,
                temporary,
                recoveryTemporary
            };
            Candidate best = null;
            bool anyFile = false;
            for (int index = 0; index < paths.Length; index++)
            {
                if (!TryReadCandidate(
                        paths[index],
                        out byte[] bytes,
                        out bool exists,
                        out errorMessage))
                    return TutorialProgressJournalLoadStatus.ServiceError;

                if (!exists)
                    continue;

                anyFile = true;
                if (!TryParseRecord(
                        bytes,
                        out TutorialProgressStageData parsed))
                    continue;

                if (best == null || parsed.Stage > best.Data.Stage)
                {
                    best = new Candidate
                    {
                        Path = paths[index],
                        Bytes = bytes,
                        Data = parsed
                    };
                }
            }

            if (best == null)
            {
                if (!anyFile)
                    return TutorialProgressJournalLoadStatus.Missing;

                errorMessage =
                    "Tutorial progress files exist, but none contains a valid record. Files were preserved.";
                return TutorialProgressJournalLoadStatus.InvalidData;
            }

            if (!string.Equals(
                    best.Path,
                    primary,
                    StringComparison.Ordinal))
            {
                if (!TryRecoverPrimary(
                        primary,
                        recoveryTemporary,
                        best,
                        out errorMessage))
                    return TutorialProgressJournalLoadStatus.ServiceError;
            }

            stage = best.Data.Stage;
            return TutorialProgressJournalLoadStatus.Loaded;
        }

        internal static TutorialProgressJournalSaveStatus TrySave(
            TutorialStage requestedStage,
            out string errorMessage)
        {
            errorMessage = null;
            if (SweetMerge.Cloud.SimpleCloudFiles.RestorePending)
            {
                errorMessage =
                    "Tutorial progress saving is blocked until the pending cloud restore is resolved.";
                return TutorialProgressJournalSaveStatus.ServiceError;
            }

            if (!Enum.IsDefined(typeof(TutorialStage), requestedStage))
            {
                errorMessage = "The requested tutorial stage is invalid.";
                return TutorialProgressJournalSaveStatus.InvalidData;
            }

            TutorialProgressJournalLoadStatus loadStatus =
                TryLoad(out TutorialStage currentStage, out errorMessage);
            if (loadStatus == TutorialProgressJournalLoadStatus.InvalidData)
                return TutorialProgressJournalSaveStatus.InvalidData;
            if (loadStatus == TutorialProgressJournalLoadStatus.ServiceError)
                return TutorialProgressJournalSaveStatus.ServiceError;
            if (loadStatus == TutorialProgressJournalLoadStatus.Missing)
                currentStage = TutorialStage.Welcome;

            if ((int)requestedStage < (int)currentStage)
            {
                errorMessage =
                    "Tutorial progress cannot move backwards; the existing record was preserved.";
                return TutorialProgressJournalSaveStatus.InvalidData;
            }

            if (requestedStage == currentStage)
                return TutorialProgressJournalSaveStatus.Saved;

            if ((int)requestedStage != (int)currentStage + 1)
            {
                errorMessage =
                    "Tutorial progress can advance only one stage at a time.";
                return TutorialProgressJournalSaveStatus.InvalidData;
            }

            if (!TryGetPaths(
                    out string primary,
                    out string backup,
                    out string temporary,
                    out _,
                    out errorMessage))
                return TutorialProgressJournalSaveStatus.ServiceError;

            try
            {
                Directory.CreateDirectory(Path.GetDirectoryName(primary));
                TutorialProgressJournalRecord record =
                    new TutorialProgressJournalRecord
                    {
                        version = CurrentVersion,
                        environment = SavePathPolicy.ModeName,
                        stage = (int)requestedStage,
                        completed = requestedStage == TutorialStage.Completed
                    };
                byte[] expectedBytes =
                    Utf8.GetBytes(JsonUtility.ToJson(record, false));

                WriteFlushed(temporary, expectedBytes);
                if (!BytesEqual(File.ReadAllBytes(temporary), expectedBytes) ||
                    !TryParseRecord(
                        File.ReadAllBytes(temporary),
                        out TutorialProgressStageData staged) ||
                    staged.Stage != requestedStage)
                {
                    errorMessage =
                        "The staged tutorial progress record failed validation.";
                    return TutorialProgressJournalSaveStatus.ServiceError;
                }

                TutorialStage latestStage = TutorialStage.Welcome;
                if (!TryReadCandidate(
                        primary,
                        out byte[] currentPrimaryBytes,
                        out bool primaryExists,
                        out errorMessage))
                    return TutorialProgressJournalSaveStatus.ServiceError;
                if (primaryExists)
                {
                    if (!TryParseRecord(
                            currentPrimaryBytes,
                            out TutorialProgressStageData currentPrimary))
                    {
                        errorMessage =
                            "The existing primary tutorial record is invalid; refusing to replace it.";
                        return TutorialProgressJournalSaveStatus.InvalidData;
                    }

                    latestStage = currentPrimary.Stage;
                }

                if ((int)requestedStage < (int)latestStage)
                {
                    errorMessage =
                        "A newer tutorial stage is already stored; the record was not replaced.";
                    return TutorialProgressJournalSaveStatus.InvalidData;
                }

                if (requestedStage == latestStage)
                    return TutorialProgressJournalSaveStatus.Saved;

                if ((int)requestedStage != (int)latestStage + 1)
                {
                    errorMessage =
                        "The staged tutorial record would skip a stage.";
                    return TutorialProgressJournalSaveStatus.InvalidData;
                }

                PromotePrimary(temporary, primary, backup);
                if (!TryReadCandidate(
                        primary,
                        out byte[] committedBytes,
                        out bool committedExists,
                        out errorMessage) ||
                    !committedExists ||
                    !BytesEqual(committedBytes, expectedBytes) ||
                    !TryParseRecord(
                        committedBytes,
                        out TutorialProgressStageData committed) ||
                    committed.Stage != requestedStage)
                {
                    if (string.IsNullOrEmpty(errorMessage))
                    {
                        errorMessage =
                            "The committed tutorial progress record failed verification.";
                    }

                    return TutorialProgressJournalSaveStatus.ServiceError;
                }

                return TutorialProgressJournalSaveStatus.Saved;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Tutorial progress could not be saved: " +
                    exception.Message;
                return TutorialProgressJournalSaveStatus.ServiceError;
            }
        }

        private static bool TryGetPaths(
            out string primary,
            out string backup,
            out string temporary,
            out string recoveryTemporary,
            out string errorMessage)
        {
            primary = null;
            backup = null;
            temporary = null;
            recoveryTemporary = null;
            errorMessage = null;
            try
            {
                string directory = Path.Combine(
                    SavePathPolicy.GetSaveDirectory(),
                    DirectoryName);
                primary = Path.Combine(directory, FileName);
                backup = primary + ".bak";
                temporary = primary + ".tmp";
                recoveryTemporary = primary + ".recover.tmp";
                return true;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "The local tutorial progress path is unavailable: " +
                    exception.Message;
                return false;
            }
        }

        private static bool TryReadCandidate(
            string path,
            out byte[] bytes,
            out bool exists,
            out string errorMessage)
        {
            bytes = null;
            exists = false;
            errorMessage = null;
            try
            {
                bytes = File.ReadAllBytes(path);
                exists = true;
                return true;
            }
            catch (FileNotFoundException)
            {
                return true;
            }
            catch (DirectoryNotFoundException)
            {
                return true;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Tutorial progress file could not be read: " +
                    exception.Message;
                return false;
            }
        }

        private static bool TryParseRecord(
            byte[] bytes,
            out TutorialProgressStageData parsed)
        {
            parsed = null;
            try
            {
                string json = Utf8.GetString(bytes);
                TutorialProgressJournalRecord record =
                    JsonUtility.FromJson<TutorialProgressJournalRecord>(json);
                if (record == null ||
                    record.version != CurrentVersion ||
                    record.environment != SavePathPolicy.ModeName ||
                    !Enum.IsDefined(typeof(TutorialStage), record.stage) ||
                    record.completed !=
                        (record.stage == (int)TutorialStage.Completed))
                    return false;

                parsed = new TutorialProgressStageData
                {
                    Stage = (TutorialStage)record.stage
                };
                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }

        private static bool TryRecoverPrimary(
            string primary,
            string recoveryTemporary,
            Candidate candidate,
            out string errorMessage)
        {
            errorMessage = null;
            try
            {
                Directory.CreateDirectory(Path.GetDirectoryName(primary));
                string sourcePath = candidate.Path;
                if (!string.Equals(
                        sourcePath,
                        recoveryTemporary,
                        StringComparison.Ordinal))
                {
                    WriteFlushed(recoveryTemporary, candidate.Bytes);
                    if (!BytesEqual(
                            File.ReadAllBytes(recoveryTemporary),
                            candidate.Bytes))
                        throw new IOException(
                            "The recovery staging file did not match its source.");
                    sourcePath = recoveryTemporary;
                }

                if (File.Exists(primary))
                {
                    string preservedPrimary = primary +
                        ".previous." + Guid.NewGuid().ToString("N");
                    byte[] primaryBytes = File.ReadAllBytes(primary);
                    WriteNewFlushed(preservedPrimary, primaryBytes);
                    if (!BytesEqual(
                            File.ReadAllBytes(preservedPrimary),
                            primaryBytes) ||
                        !BytesEqual(
                            File.ReadAllBytes(primary),
                            primaryBytes))
                        throw new IOException(
                            "The existing primary could not be preserved before recovery.");
                }

                AtomicReplaceFile(sourcePath, primary);

                if (!BytesEqual(
                        File.ReadAllBytes(primary),
                        candidate.Bytes))
                    throw new IOException(
                        "Recovered tutorial progress failed post-promotion verification.");

                return true;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "A validated tutorial progress record was found, but the primary file could not be recovered: " +
                    exception.Message;
                return false;
            }
        }

        private static void PromotePrimary(
            string temporary,
            string primary,
            string backup)
        {
            if (File.Exists(primary))
            {
                byte[] primaryBytes = File.ReadAllBytes(primary);
                if (!TryParseRecord(primaryBytes, out _))
                    throw new IOException(
                        "The existing primary tutorial record is invalid; refusing to replace it.");

                if (File.Exists(backup) &&
                    !TryParseRecord(File.ReadAllBytes(backup), out _))
                    throw new IOException(
                        "The existing tutorial backup is invalid; refusing to replace it.");

                if (!File.Exists(backup) ||
                    !BytesEqual(File.ReadAllBytes(backup), primaryBytes))
                {
                    string backupTemporary = backup + ".tmp";
                    WriteFlushed(backupTemporary, primaryBytes);
                    if (!BytesEqual(
                            File.ReadAllBytes(backupTemporary),
                            primaryBytes) ||
                        !TryParseRecord(
                            File.ReadAllBytes(backupTemporary),
                            out _))
                        throw new IOException(
                            "Tutorial backup staging failed validation.");

                    if (!BytesEqual(
                            File.ReadAllBytes(primary),
                            primaryBytes))
                        throw new IOException(
                            "The primary tutorial record changed while staging its backup.");

                    AtomicReplaceFile(backupTemporary, backup);
                }

                if (!BytesEqual(
                        File.ReadAllBytes(primary),
                        primaryBytes))
                    throw new IOException(
                        "The primary tutorial record changed before promotion.");
            }

            AtomicReplaceFile(temporary, primary);
        }

        private static void WriteFlushed(
            string path,
            byte[] bytes)
        {
            using (var stream = new FileStream(
                       path,
                       FileMode.Create,
                       FileAccess.Write,
                       FileShare.None))
            {
                stream.Write(bytes, 0, bytes.Length);
                stream.Flush(true);
            }
        }

        private static void WriteNewFlushed(
            string path,
            byte[] bytes)
        {
            using (var stream = new FileStream(
                       path,
                       FileMode.CreateNew,
                       FileAccess.Write,
                       FileShare.None))
            {
                stream.Write(bytes, 0, bytes.Length);
                stream.Flush(true);
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
                int error =
                    Marshal.GetLastWin32Error();
                throw new IOException(
                    "Tutorial progress commit failed (Windows error " +
                    error + ").");
            }
#elif UNITY_ANDROID && !UNITY_EDITOR
            if (RenameFileAndroid(
                    Utf8.GetBytes(source + "\0"),
                    Utf8.GetBytes(destination + "\0")) != 0)
            {
                int error =
                    Marshal.GetLastWin32Error();
                throw new IOException(
                    "Tutorial progress commit failed (Android errno " +
                    error + ").");
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
            if (left == null || right == null || left.Length != right.Length)
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
