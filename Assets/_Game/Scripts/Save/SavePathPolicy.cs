using System;
using System.IO;
#if UNITY_EDITOR
using System.Diagnostics;
using System.Globalization;
using System.Runtime.InteropServices;
using System.Text;
#endif
using UnityEngine;

public static class SavePathPolicy
{
#if UNITY_EDITOR || (UNITY_ANDROID && DEVELOPMENT_BUILD)
    private const string DevelopmentSaveDirectoryName =
        "SweetMaker-Development";
#endif

#if UNITY_EDITOR
    private const string GuestQaSandboxOptInVariable =
        "SWEETMAKER_GUEST_QA_SANDBOX";
    private const string GuestQaSandboxRunIdVariable =
        "SWEETMAKER_GUEST_QA_RUN_ID";
    private const string GuestQaSandboxBaseDirectoryName =
        "SweetMaker-GuestQA";
    private const string GuestQaSandboxMarkerFileName =
        ".sweetmaker-guestqa-owner-v1";
    private const string GuestQaSandboxMarkerMagic =
        "SweetMaker-GuestQA-Sandbox";
    private const string GuestQaSandboxSessionMagic =
        "SweetMaker-GuestQA-Session";
    private static readonly UTF8Encoding StrictUtf8 =
        new UTF8Encoding(false, true);
    private static readonly object EditorSandboxSync = new object();

    private static bool editorSandboxResolutionAttempted;
    private static string editorSandboxRoot;
    private static Exception editorSandboxResolutionError;
#if UNITY_EDITOR_WIN
    private static IntPtr editorSandboxLockHandle;
#endif
#endif

    public static bool IsDevelopmentSaveIsolationEnabled
    {
        get
        {
#if UNITY_EDITOR || (UNITY_ANDROID && DEVELOPMENT_BUILD)
            return true;
#else
            return false;
#endif
        }
    }

    public static string ModeName =>
#if UNITY_EDITOR
        GetEditorSandboxRoot() != null
            ? "GUEST-QA-SANDBOX"
            :
#endif
        IsDevelopmentSaveIsolationEnabled
            ? "DEVELOPMENT-ISOLATED"
            : "RELEASE";

    public static string GetSaveDirectory()
    {
        return GetSaveDirectory(Application.persistentDataPath);
    }

    public static string GetSaveDirectory(string persistentDataPath)
    {
        if (string.IsNullOrWhiteSpace(persistentDataPath))
            throw new ArgumentException(
                "Persistent data path cannot be empty.",
                nameof(persistentDataPath));

#if UNITY_EDITOR
        string sandboxRoot = GetEditorSandboxRoot();
        if (sandboxRoot != null)
        {
            EnsureSandboxDoesNotOverlapSaveRoots(
                sandboxRoot,
                persistentDataPath);
            return sandboxRoot;
        }
#endif

#if UNITY_EDITOR || (UNITY_ANDROID && DEVELOPMENT_BUILD)
        return Path.Combine(
            persistentDataPath,
            DevelopmentSaveDirectoryName);
#else
        return persistentDataPath;
#endif
    }

#if UNITY_EDITOR
    private static string GetEditorSandboxRoot()
    {
        lock (EditorSandboxSync)
        {
            if (!editorSandboxResolutionAttempted)
            {
                editorSandboxResolutionAttempted = true;
                try
                {
                    editorSandboxRoot = ResolveEditorSandboxRoot();
                }
                catch (Exception exception)
                {
                    editorSandboxResolutionError = exception;
                }
            }

            if (editorSandboxResolutionError != null)
            {
                throw new InvalidOperationException(
                    "Guest QA sandbox was requested but could not be safely resolved. " +
                    "Save access is blocked; no normal save directory will be used.",
                    editorSandboxResolutionError);
            }

            return editorSandboxRoot;
        }
    }

    private static string ResolveEditorSandboxRoot()
    {
        string optIn = Environment.GetEnvironmentVariable(
            GuestQaSandboxOptInVariable);
        string configuredRunId = Environment.GetEnvironmentVariable(
            GuestQaSandboxRunIdVariable);
        if (optIn == null && configuredRunId == null)
            return null;

        if (!string.Equals(optIn, "1", StringComparison.Ordinal))
        {
            throw new InvalidOperationException(
                GuestQaSandboxOptInVariable +
                " must be exactly '1' when configured.");
        }

        if (!Guid.TryParseExact(configuredRunId, "D", out Guid runId))
        {
            throw new InvalidOperationException(
                GuestQaSandboxRunIdVariable +
                " must contain a GUID in D format.");
        }

        string normalizedRunId = runId.ToString("N");
        string sandboxBaseDirectory = Path.GetFullPath(Path.Combine(
            Path.GetTempPath(),
            GuestQaSandboxBaseDirectoryName));
        string sandboxRoot = Path.GetFullPath(Path.Combine(
            sandboxBaseDirectory,
            normalizedRunId));

        EnsureSandboxDoesNotOverlapSaveRoots(
            sandboxRoot,
            Application.persistentDataPath);

        Directory.CreateDirectory(sandboxBaseDirectory);
        EnsureNoReparsePointsInPath(sandboxBaseDirectory);
        AcquireEditorSandboxSessionLock(
            sandboxBaseDirectory,
            normalizedRunId);

        if (Directory.Exists(sandboxBaseDirectory))
        {
            FileAttributes baseAttributes =
                File.GetAttributes(sandboxBaseDirectory);
            if ((baseAttributes & FileAttributes.ReparsePoint) != 0)
            {
                throw new InvalidOperationException(
                    "Guest QA sandbox base directory cannot be a reparse point.");
            }
        }
        else if (File.Exists(sandboxBaseDirectory))
        {
            throw new InvalidOperationException(
                "Guest QA sandbox base path is an existing file.");
        }

        if (Directory.Exists(sandboxRoot))
        {
            ValidateExistingSandbox(sandboxRoot, normalizedRunId);
            return sandboxRoot;
        }

        if (File.Exists(sandboxRoot))
        {
            throw new InvalidOperationException(
                "Guest QA sandbox path already exists as a file.");
        }

        Directory.CreateDirectory(sandboxRoot);
        if (Directory.GetFileSystemEntries(sandboxRoot).Length != 0)
        {
            throw new InvalidOperationException(
                "New guest QA sandbox directory was not empty.");
        }

        string markerPath = Path.Combine(
            sandboxRoot,
            GuestQaSandboxMarkerFileName);
        using (var markerStream = new FileStream(
                   markerPath,
                   FileMode.CreateNew,
                   FileAccess.Write,
                   FileShare.None))
        using (var writer = new StreamWriter(markerStream, StrictUtf8))
        {
            writer.Write(GetExpectedMarkerContents(normalizedRunId));
            writer.Flush();
            markerStream.Flush();
        }

        ValidateExistingSandbox(sandboxRoot, normalizedRunId);
        return sandboxRoot;
    }

    private static void ValidateExistingSandbox(
        string sandboxRoot,
        string normalizedRunId)
    {
        FileAttributes rootAttributes = File.GetAttributes(sandboxRoot);
        if ((rootAttributes & FileAttributes.Directory) == 0 ||
            (rootAttributes & FileAttributes.ReparsePoint) != 0)
        {
            throw new InvalidOperationException(
                "Guest QA sandbox must be a normal directory, not a reparse point.");
        }

        string markerPath = Path.Combine(
            sandboxRoot,
            GuestQaSandboxMarkerFileName);
        string[] ownershipEntries = Directory.GetFileSystemEntries(sandboxRoot);
        int ownershipEntryCount = 0;
        foreach (string entry in ownershipEntries)
        {
            if (Path.GetFileName(entry).StartsWith(
                    ".sweetmaker-guestqa-owner",
                    StringComparison.OrdinalIgnoreCase))
            {
                ownershipEntryCount++;
                if (!string.Equals(
                        Path.GetFullPath(entry),
                        Path.GetFullPath(markerPath),
                        StringComparison.OrdinalIgnoreCase))
                {
                    throw new InvalidOperationException(
                        "Guest QA sandbox contains an unexpected ownership marker.");
                }
            }
        }

        if (ownershipEntryCount != 1 || !File.Exists(markerPath))
        {
            throw new InvalidOperationException(
                "Guest QA sandbox ownership marker is missing or ambiguous.");
        }

        FileAttributes markerAttributes = File.GetAttributes(markerPath);
        if ((markerAttributes & FileAttributes.ReparsePoint) != 0 ||
            (markerAttributes & FileAttributes.Directory) != 0)
        {
            throw new InvalidOperationException(
                "Guest QA sandbox ownership marker is not a regular file.");
        }

        string actualMarkerContents = File.ReadAllText(
            markerPath,
            StrictUtf8);
        string expectedMarkerContents =
            GetExpectedMarkerContents(normalizedRunId);
        if (!string.Equals(
                actualMarkerContents,
                expectedMarkerContents,
                StringComparison.Ordinal))
        {
            throw new InvalidOperationException(
                "Guest QA sandbox ownership marker is invalid or belongs to another run ID.");
        }
    }

    private static string GetExpectedMarkerContents(string normalizedRunId)
    {
        return GuestQaSandboxMarkerMagic + "\n" +
               "1\n" +
               normalizedRunId + "\n" +
               GuestQaSandboxBaseDirectoryName + "/" +
               normalizedRunId + "\n";
    }

    private static void AcquireEditorSandboxSessionLock(
        string sandboxBaseDirectory,
        string normalizedRunId)
    {
#if UNITY_EDITOR_WIN
        if (editorSandboxLockHandle != IntPtr.Zero)
            return;

        string lockPath = Path.Combine(
            sandboxBaseDirectory,
            normalizedRunId + ".lock");
        string identityPath = Path.Combine(
            sandboxBaseDirectory,
            normalizedRunId + ".session");
        string expectedSessionIdentity =
            GetExpectedSessionIdentity(normalizedRunId);

        IntPtr lockHandle = CreateFile(
            lockPath,
            GenericRead | GenericWrite,
            0,
            IntPtr.Zero,
            OpenAlways,
            FileFlagOpenReparsePoint,
            IntPtr.Zero);
        if (lockHandle != InvalidHandleValue)
        {
            try
            {
                EnsureLockFileIsNotReparsePoint(lockPath);
                WriteSessionIdentity(
                    identityPath,
                    expectedSessionIdentity);

                // Keep this native handle open. The OS owns it independently of
                // Unity's reloadable scripting domain and closes it at process exit.
                editorSandboxLockHandle = lockHandle;
                return;
            }
            catch
            {
                CloseHandle(lockHandle);
                throw;
            }
        }

        int lockOpenError = Marshal.GetLastWin32Error();
        if (lockOpenError != ErrorSharingViolation)
        {
            throw new IOException(
                "Guest QA sandbox session lock could not be acquired. " +
                "Save access is blocked. Win32 error: " +
                lockOpenError.ToString(CultureInfo.InvariantCulture));
        }

        try
        {
            EnsureLockFileIsNotReparsePoint(identityPath);
            string existingSessionIdentity =
                ReadSessionIdentity(identityPath);
            if (string.Equals(
                    existingSessionIdentity,
                    expectedSessionIdentity,
                    StringComparison.Ordinal))
            {
                // This is the same Editor process after a domain reload.
                // Its original native handle remains open and holds the lock.
                return;
            }
        }
        catch (Exception exception)
        {
            throw new IOException(
                "Guest QA sandbox session lock could not be verified after " +
                "ERROR_SHARING_VIOLATION (32). Save access is blocked. Close " +
                "other Editors using this run ID and retry.",
                exception);
        }

        throw new IOException(
            "Guest QA sandbox session lock is unavailable. Another Unity Editor " +
            "may be using this run ID, or the lock file could not be verified. " +
            "Close other Editors using this run ID and retry. Win32 error: " +
            lockOpenError.ToString(CultureInfo.InvariantCulture));
#else
        throw new PlatformNotSupportedException(
            "Guest QA sandbox is supported only by the Windows Unity Editor. " +
            "Sandbox configuration is present, so save access is blocked.");
#endif
    }

#if UNITY_EDITOR_WIN
    private const int ErrorSharingViolation = 32;

    private static string GetExpectedSessionIdentity(string normalizedRunId)
    {
        int processId;
        long processStartUtcTicks;
        using (Process currentProcess = Process.GetCurrentProcess())
        {
            processId = currentProcess.Id;
            processStartUtcTicks =
                currentProcess.StartTime.ToUniversalTime().Ticks;
        }

        return GuestQaSandboxSessionMagic + "\n" +
               "1\n" +
               normalizedRunId + "\n" +
               processId.ToString(CultureInfo.InvariantCulture) + "\n" +
               processStartUtcTicks.ToString(CultureInfo.InvariantCulture) +
               "\n" +
               GuestQaSandboxBaseDirectoryName + "/" +
               normalizedRunId + "\n";
    }

    private static void WriteSessionIdentity(
        string identityPath,
        string identity)
    {
        IntPtr identityHandle = CreateFile(
            identityPath,
            GenericRead | GenericWrite,
            0,
            IntPtr.Zero,
            OpenAlways,
            FileFlagOpenReparsePoint,
            IntPtr.Zero);
        if (identityHandle == InvalidHandleValue)
        {
            throw new IOException(
                "Could not open the guest QA sandbox session identity file. Win32 error: " +
                Marshal.GetLastWin32Error().ToString(
                    CultureInfo.InvariantCulture));
        }

        try
        {
            EnsureLockFileIsNotReparsePoint(identityPath);
            WriteLockContents(identityHandle, identity);
        }
        finally
        {
            CloseHandle(identityHandle);
        }
    }

    private static void EnsureLockFileIsNotReparsePoint(string lockPath)
    {
        FileAttributes attributes = File.GetAttributes(lockPath);
        if ((attributes & FileAttributes.ReparsePoint) != 0 ||
            (attributes & FileAttributes.Directory) != 0)
        {
            throw new IOException(
                "Guest QA sandbox lock path is not a regular file.");
        }
    }

    private static void WriteLockContents(
        IntPtr lockHandle,
        string contents)
    {
        byte[] bytes = StrictUtf8.GetBytes(contents);
        if (!SetFilePointerEx(lockHandle, 0, out _, FileBegin))
            throw new IOException("Could not seek to the start of the sandbox lock file.");

        if (!WriteFile(
                lockHandle,
                bytes,
                (uint)bytes.Length,
                out uint bytesWritten,
                IntPtr.Zero) ||
            bytesWritten != bytes.Length)
        {
            throw new IOException("Could not write the sandbox lock identity.");
        }

        if (!SetEndOfFile(lockHandle) || !FlushFileBuffers(lockHandle))
            throw new IOException("Could not durably write the sandbox lock identity.");
    }

    private static string ReadSessionIdentity(string identityPath)
    {
        IntPtr identityHandle = CreateFile(
            identityPath,
            GenericRead,
            0,
            IntPtr.Zero,
            OpenExisting,
            FileFlagOpenReparsePoint,
            IntPtr.Zero);
        if (identityHandle == InvalidHandleValue)
        {
            throw new IOException(
                "Could not open the guest QA sandbox session identity. Win32 error: " +
                Marshal.GetLastWin32Error().ToString(
                    CultureInfo.InvariantCulture));
        }

        try
        {
            EnsureLockFileIsNotReparsePoint(identityPath);
            using (var stream = new FileStream(
                       new Microsoft.Win32.SafeHandles.SafeFileHandle(
                           identityHandle,
                           ownsHandle: false),
                       FileAccess.Read))
            {
                if (stream.Length > 1024)
                {
                    throw new IOException(
                        "Guest QA sandbox lock identity exceeds the supported size.");
                }

                byte[] bytes = new byte[(int)stream.Length];
                int totalRead = 0;
                while (totalRead < bytes.Length)
                {
                    int bytesRead = stream.Read(
                        bytes,
                        totalRead,
                        bytes.Length - totalRead);
                    if (bytesRead == 0)
                        throw new IOException(
                            "Guest QA sandbox lock identity is incomplete.");
                    totalRead += bytesRead;
                }

                return StrictUtf8.GetString(bytes);
            }
        }
        finally
        {
            CloseHandle(identityHandle);
        }
    }

    private const uint GenericRead = 0x80000000;
    private const uint GenericWrite = 0x40000000;
    private const uint OpenExisting = 3;
    private const uint OpenAlways = 4;
    private const uint FileFlagOpenReparsePoint = 0x00200000;
    private const uint FileBegin = 0;
    private static readonly IntPtr InvalidHandleValue = new IntPtr(-1);

    [DllImport("kernel32.dll", EntryPoint = "CreateFileW",
        CharSet = CharSet.Unicode, SetLastError = true)]
    private static extern IntPtr CreateFile(
        string fileName,
        uint desiredAccess,
        uint shareMode,
        IntPtr securityAttributes,
        uint creationDisposition,
        uint flagsAndAttributes,
        IntPtr templateFile);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool SetFilePointerEx(
        IntPtr fileHandle,
        long distanceToMove,
        out long newFilePointer,
        uint moveMethod);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool SetEndOfFile(IntPtr fileHandle);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool WriteFile(
        IntPtr fileHandle,
        byte[] buffer,
        uint numberOfBytesToWrite,
        out uint numberOfBytesWritten,
        IntPtr overlapped);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool FlushFileBuffers(IntPtr fileHandle);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool CloseHandle(IntPtr handle);
#endif

    private static void EnsureSandboxDoesNotOverlapSaveRoots(
        string sandboxRoot,
        string persistentDataPath)
    {
        if (string.IsNullOrWhiteSpace(persistentDataPath))
        {
            throw new InvalidOperationException(
                "Persistent data path is unavailable; guest QA sandbox isolation cannot be verified.");
        }

        EnsureNoReparsePointsInPath(sandboxRoot);
        EnsureNoReparsePointsInPath(persistentDataPath);

        string normalizedSandboxRoot = NormalizeDirectoryPath(sandboxRoot);
        string releaseRoot = NormalizeDirectoryPath(persistentDataPath);
        string developmentRoot = NormalizeDirectoryPath(Path.Combine(
            persistentDataPath,
            DevelopmentSaveDirectoryName));

        if (PathsOverlap(normalizedSandboxRoot, releaseRoot) ||
            PathsOverlap(normalizedSandboxRoot, developmentRoot))
        {
            throw new InvalidOperationException(
                "Guest QA sandbox overlaps a DEV or RELEASE save root.");
        }
    }

    private static void EnsureNoReparsePointsInPath(string path)
    {
        string currentPath = NormalizeDirectoryPath(path);
        while (!string.IsNullOrEmpty(currentPath))
        {
            if (Directory.Exists(currentPath) || File.Exists(currentPath))
            {
                FileAttributes attributes = File.GetAttributes(currentPath);
                if ((attributes & FileAttributes.ReparsePoint) != 0)
                {
                    throw new InvalidOperationException(
                        "Guest QA sandbox isolation does not allow reparse points in save paths.");
                }
            }

            string parentPath = Path.GetDirectoryName(currentPath);
            if (string.IsNullOrEmpty(parentPath) ||
                string.Equals(parentPath, currentPath, StringComparison.Ordinal))
            {
                break;
            }

            currentPath = parentPath;
        }
    }

    private static string NormalizeDirectoryPath(string path)
    {
        string fullPath = Path.GetFullPath(path);
        string pathRoot = Path.GetPathRoot(fullPath);
        while (fullPath.Length > pathRoot.Length &&
               (fullPath[fullPath.Length - 1] == Path.DirectorySeparatorChar ||
                fullPath[fullPath.Length - 1] == Path.AltDirectorySeparatorChar))
        {
            fullPath = fullPath.Substring(0, fullPath.Length - 1);
        }

        return fullPath;
    }

    private static bool PathsOverlap(string firstPath, string secondPath)
    {
        StringComparison comparison = Path.DirectorySeparatorChar == '\\'
            ? StringComparison.OrdinalIgnoreCase
            : StringComparison.Ordinal;

        return IsSameOrNestedPath(firstPath, secondPath, comparison) ||
               IsSameOrNestedPath(secondPath, firstPath, comparison);
    }

    private static bool IsSameOrNestedPath(
        string path,
        string possibleParent,
        StringComparison comparison)
    {
        if (string.Equals(path, possibleParent, comparison))
            return true;

        string parentWithSeparator = possibleParent;
        if (parentWithSeparator[parentWithSeparator.Length - 1] !=
            Path.DirectorySeparatorChar &&
            parentWithSeparator[parentWithSeparator.Length - 1] !=
            Path.AltDirectorySeparatorChar)
        {
            parentWithSeparator += Path.DirectorySeparatorChar;
        }

        return path.StartsWith(parentWithSeparator, comparison);
    }
#endif
}
