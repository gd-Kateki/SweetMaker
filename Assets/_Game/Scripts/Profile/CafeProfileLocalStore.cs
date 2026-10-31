using System;
using System.Collections.Generic;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;
using UnityEngine;

namespace SweetMerge.Profile
{
    public enum CafeProfileLocalStatus
    {
        Missing,
        Loaded,
        InvalidData,
        ServiceError
    }

    public enum CafeProfileLocalSaveStatus
    {
        Saved,
        AlreadyNamed,
        InvalidName,
        InvalidData,
        ServiceError
    }

    public sealed class CafeProfileLocalRecord
    {
        public string CafeName { get; }
        public bool NamingCompleted { get; }

        internal CafeProfileLocalRecord(
            string cafeName,
            bool namingCompleted)
        {
            CafeName = cafeName;
            NamingCompleted = namingCompleted;
        }
    }

    [Serializable]
    internal sealed class CafeProfileLocalRecordData
    {
        public int version;
        public string environment;
        public string cafeName;
        public bool namingCompleted;
    }

    public static class CafeProfileLocalStore
    {
        private const int CurrentVersion = 1;
        private const string DirectoryName = "CafeProfile";
        private const string FileName = "cafe-profile-v1.json";
        private const uint ReplaceExisting = 0x1;
        private const uint WriteThrough = 0x8;
        private static readonly object WriteLock = new object();
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
            public CafeProfileLocalRecord Record;
        }

        public static CafeProfileLocalStatus Load(
            out CafeProfileLocalRecord record,
            out string errorMessage)
        {
            record = null;
            errorMessage = null;
            if (!TryGetPaths(
                    out string primary,
                    out string backup,
                    out string temporary,
                    out string recoveryTemporary,
                    out string error))
            {
                errorMessage = error;
                return CafeProfileLocalStatus.ServiceError;
            }

            string[] paths =
            {
                primary,
                backup,
                temporary,
                recoveryTemporary
            };
            Candidate best = null;
            bool anyFile = false;
            List<Candidate> validCandidates = new List<Candidate>();

            foreach (string path in paths)
            {
                if (!TryReadCandidate(
                        path,
                        out byte[] bytes,
                        out bool exists,
                        out errorMessage))
                    return CafeProfileLocalStatus.ServiceError;

                if (!exists)
                    continue;

                anyFile = true;
                if (!TryParseRecord(
                        bytes,
                        out CafeProfileLocalRecord parsed))
                    continue;

                Candidate candidate = new Candidate
                {
                    Path = path,
                    Bytes = bytes,
                    Record = parsed
                };
                validCandidates.Add(candidate);
                if (best == null || path == primary)
                    best = candidate;
            }

            if (best == null)
            {
                if (!anyFile)
                    return CafeProfileLocalStatus.Missing;

                errorMessage =
                    "Cafe profile files exist, but none contains a valid record. Files were preserved.";
                return CafeProfileLocalStatus.InvalidData;
            }

            foreach (Candidate candidate in validCandidates)
            {
                if (!string.Equals(
                        candidate.Record.CafeName,
                        best.Record.CafeName,
                        StringComparison.Ordinal))
                {
                    errorMessage =
                        "Conflicting valid cafe profile records were found. No record was selected or overwritten.";
                    return CafeProfileLocalStatus.InvalidData;
                }
            }

            if (!string.Equals(
                    best.Path,
                    primary,
                    StringComparison.Ordinal) &&
                !TryRecoverPrimary(
                    primary,
                    recoveryTemporary,
                    best,
                    out errorMessage))
                return CafeProfileLocalStatus.ServiceError;

            record = best.Record;
            return CafeProfileLocalStatus.Loaded;
        }

        public static CafeProfileLocalSaveStatus Save(
            string proposedName,
            out CafeProfileLocalRecord record,
            out string errorMessage)
        {
            lock (WriteLock)
            {
                return SaveCore(
                    proposedName,
                    out record,
                    out errorMessage);
            }
        }

        private static CafeProfileLocalSaveStatus SaveCore(
            string proposedName,
            out CafeProfileLocalRecord record,
            out string errorMessage)
        {
            record = null;
            errorMessage = null;
            string trimmedName = proposedName == null
                ? string.Empty
                : proposedName.Trim();
            if (trimmedName.Length == 0 || trimmedName.Length > 20)
            {
                errorMessage =
                    "Cafe names must contain 1 to 20 characters.";
                return CafeProfileLocalSaveStatus.InvalidName;
            }

            CafeProfileLocalStatus currentStatus =
                Load(out record, out errorMessage);
            if (currentStatus == CafeProfileLocalStatus.Loaded)
                return CafeProfileLocalSaveStatus.AlreadyNamed;
            if (currentStatus == CafeProfileLocalStatus.InvalidData)
                return CafeProfileLocalSaveStatus.InvalidData;
            if (currentStatus == CafeProfileLocalStatus.ServiceError)
                return CafeProfileLocalSaveStatus.ServiceError;

            if (!TryGetPaths(
                    out string primary,
                    out string backup,
                    out string temporary,
                    out _,
                    out errorMessage))
                return CafeProfileLocalSaveStatus.ServiceError;

            try
            {
                Directory.CreateDirectory(Path.GetDirectoryName(primary));
                CafeProfileLocalRecordData data =
                    new CafeProfileLocalRecordData
                    {
                        version = CurrentVersion,
                        environment = SavePathPolicy.ModeName,
                        cafeName = trimmedName,
                        namingCompleted = true
                    };
                byte[] expectedBytes =
                    Utf8.GetBytes(JsonUtility.ToJson(data, false));
                WriteFlushed(temporary, expectedBytes);
                if (!BytesEqual(
                        File.ReadAllBytes(temporary),
                        expectedBytes) ||
                    !TryParseRecord(
                        File.ReadAllBytes(temporary),
                        out CafeProfileLocalRecord staged) ||
                    !RecordsEqual(staged, trimmedName))
                {
                    errorMessage =
                        "The staged cafe profile failed validation.";
                    return CafeProfileLocalSaveStatus.ServiceError;
                }

                if (!TryReadCandidate(
                        primary,
                        out _,
                        out bool primaryExists,
                        out errorMessage))
                    return CafeProfileLocalSaveStatus.ServiceError;
                if (primaryExists)
                {
                    errorMessage =
                        "An unrecognized primary cafe profile exists; refusing to replace it.";
                    return CafeProfileLocalSaveStatus.InvalidData;
                }
                if (!TryReadCandidate(
                        backup,
                        out _,
                        out bool backupExists,
                        out errorMessage))
                    return CafeProfileLocalSaveStatus.ServiceError;
                if (backupExists)
                {
                    errorMessage =
                        "A cafe profile backup appeared during registration; refusing to replace it.";
                    return CafeProfileLocalSaveStatus.InvalidData;
                }

                AtomicReplaceFile(temporary, primary);
                if (!TryReadCandidate(
                        primary,
                        out byte[] committedBytes,
                        out bool committedExists,
                        out errorMessage) ||
                    !committedExists ||
                    !BytesEqual(committedBytes, expectedBytes) ||
                    !TryParseRecord(
                        committedBytes,
                        out CafeProfileLocalRecord committed) ||
                    !RecordsEqual(committed, trimmedName))
                {
                    if (string.IsNullOrEmpty(errorMessage))
                        errorMessage =
                            "The committed cafe profile failed verification.";
                    return CafeProfileLocalSaveStatus.ServiceError;
                }

                EnsureBackup(committedBytes, backup);
                record = committed;
                return CafeProfileLocalSaveStatus.Saved;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Cafe profile could not be saved: " +
                    exception.Message;
                return CafeProfileLocalSaveStatus.ServiceError;
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
                    "The local cafe profile path is unavailable: " +
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
                    "Cafe profile file could not be read: " +
                    exception.Message;
                return false;
            }
        }

        private static bool TryParseRecord(
            byte[] bytes,
            out CafeProfileLocalRecord record)
        {
            record = null;
            try
            {
                string json = Utf8.GetString(bytes);
                CafeProfileLocalRecordData data =
                    JsonUtility.FromJson<CafeProfileLocalRecordData>(json);
                if (data == null ||
                    data.version != CurrentVersion ||
                    data.environment != SavePathPolicy.ModeName ||
                    !data.namingCompleted ||
                    string.IsNullOrWhiteSpace(data.cafeName) ||
                    data.cafeName != data.cafeName.Trim() ||
                    data.cafeName.Length > 20)
                    return false;

                record = new CafeProfileLocalRecord(
                    data.cafeName,
                    data.namingCompleted);
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
                if (File.Exists(primary))
                {
                    byte[] primaryBytes = File.ReadAllBytes(primary);
                    string preservedPrimary = primary +
                        ".previous." + Guid.NewGuid().ToString("N");
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

                if (File.Exists(recoveryTemporary))
                {
                    byte[] existingRecoveryBytes =
                        File.ReadAllBytes(recoveryTemporary);
                    if (!BytesEqual(
                            existingRecoveryBytes,
                            candidate.Bytes))
                    {
                        string preservedRecovery = recoveryTemporary +
                            ".previous." + Guid.NewGuid().ToString("N");
                        WriteNewFlushed(
                            preservedRecovery,
                            existingRecoveryBytes);
                        if (!BytesEqual(
                                File.ReadAllBytes(preservedRecovery),
                                existingRecoveryBytes))
                            throw new IOException(
                                "The existing recovery staging file could not be preserved.");
                    }
                }

                WriteFlushed(recoveryTemporary, candidate.Bytes);
                if (!BytesEqual(
                        File.ReadAllBytes(recoveryTemporary),
                        candidate.Bytes) ||
                    !TryParseRecord(
                        File.ReadAllBytes(recoveryTemporary),
                        out CafeProfileLocalRecord staged) ||
                    !RecordsEqual(staged, candidate.Record.CafeName))
                    throw new IOException(
                        "The recovery staging file failed validation.");

                AtomicReplaceFile(recoveryTemporary, primary);
                if (!BytesEqual(
                        File.ReadAllBytes(primary),
                        candidate.Bytes))
                    throw new IOException(
                        "Recovered cafe profile failed post-promotion verification.");

                return true;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "A valid cafe profile was found, but the primary file could not be recovered: " +
                    exception.Message;
                return false;
            }
        }

        private static void EnsureBackup(
            byte[] committedBytes,
            string backup)
        {
            if (File.Exists(backup))
            {
                byte[] backupBytes = File.ReadAllBytes(backup);
                if (!TryParseRecord(backupBytes, out _))
                    throw new IOException(
                        "The existing cafe profile backup is invalid; refusing to replace it.");
                if (!BytesEqual(backupBytes, committedBytes))
                    throw new IOException(
                        "The cafe profile backup conflicts with the committed record.");
                return;
            }

            string backupTemporary = backup + ".tmp";
            if (File.Exists(backupTemporary))
            {
                byte[] existingTemporary =
                    File.ReadAllBytes(backupTemporary);
                if (!BytesEqual(existingTemporary, committedBytes))
                {
                    string preservedTemporary = backupTemporary +
                        ".previous." + Guid.NewGuid().ToString("N");
                    WriteNewFlushed(
                        preservedTemporary,
                        existingTemporary);
                    if (!BytesEqual(
                            File.ReadAllBytes(preservedTemporary),
                            existingTemporary))
                        throw new IOException(
                            "The existing backup staging file could not be preserved.");
                }
            }

            WriteFlushed(backupTemporary, committedBytes);
            if (!BytesEqual(
                    File.ReadAllBytes(backupTemporary),
                    committedBytes) ||
                !TryParseRecord(
                    File.ReadAllBytes(backupTemporary),
                    out _))
                throw new IOException(
                    "Cafe profile backup staging failed validation.");

            AtomicReplaceFile(backupTemporary, backup);
            if (!BytesEqual(File.ReadAllBytes(backup), committedBytes))
                throw new IOException(
                    "Cafe profile backup failed post-promotion verification.");
        }

        private static bool RecordsEqual(
            CafeProfileLocalRecord record,
            string cafeName)
        {
            return record != null &&
                record.NamingCompleted &&
                string.Equals(
                    record.CafeName,
                    cafeName,
                    StringComparison.Ordinal);
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
                int error = Marshal.GetLastWin32Error();
                throw new IOException(
                    "Cafe profile commit failed (Windows error " +
                    error + ").");
            }
#elif UNITY_ANDROID && !UNITY_EDITOR
            if (RenameFileAndroid(
                    Utf8.GetBytes(source + "\0"),
                    Utf8.GetBytes(destination + "\0")) != 0)
            {
                int error = Marshal.GetLastWin32Error();
                throw new IOException(
                    "Cafe profile commit failed (Android errno " +
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
