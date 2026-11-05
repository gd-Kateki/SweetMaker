#if UNITY_EDITOR
using System;
using System.Collections.Generic;
using System.IO;
using UnityEditor;
using UnityEngine;

public static class GuestProgressReset
{
    private const string MenuPath =
        "Tools/Dessert Merge Cafe/Reset Guest Progress";
    private const string SandboxOptInVariable =
        "SWEETMAKER_GUEST_QA_SANDBOX";
    private const string SandboxRunIdVariable =
        "SWEETMAKER_GUEST_QA_RUN_ID";
    private const string DevelopmentSaveDirectoryName =
        "SweetMaker-Development";
    private const string SaveV2FileName =
        "player_save_v2.json";
    private const string LegacySaveFileName =
        "player_save.json";
    private const string CorruptSavePrefix =
        SaveV2FileName + ".corrupt.";
    private const string TutorialDirectoryName =
        "TutorialProgress";
    private const string TutorialFileName =
        "tutorial-progress-v1.json";
    private const string CafeProfileDirectoryName =
        "CafeProfile";
    private const string CafeProfileFileName =
        "cafe-profile-v1.json";

    private static readonly string[] ManagedSuffixes =
    {
        "",
        ".bak",
        ".tmp",
        ".bak.tmp",
        ".recover.tmp"
    };

    [MenuItem(MenuPath)]
    private static void ResetGuestProgress()
    {
        if (EditorApplication.isPlayingOrWillChangePlaymode)
        {
            EditorUtility.DisplayDialog(
                "Reset Not Allowed",
                "Stop Play Mode before resetting guest progress.",
                "OK");
            return;
        }

        string saveRoot;
        string error;
        if (!TryResolvePermittedSaveRoot(out saveRoot, out error))
        {
            EditorUtility.DisplayDialog(
                "Guest Progress Reset Refused",
                error,
                "OK");
            return;
        }

        List<string> filesToRemove;
        if (!TryGetProgressFiles(saveRoot, out filesToRemove, out error))
        {
            EditorUtility.DisplayDialog(
                "Guest Progress Reset Refused",
                error,
                "OK");
            return;
        }

        if (filesToRemove.Count == 0)
        {
            EditorUtility.DisplayDialog(
                "No Guest Progress Found",
                "No managed guest progression files were found in:\n\n" +
                saveRoot + "\n\nNo files were changed.",
                "OK");
            return;
        }

        string fileList = string.Join("\n", filesToRemove.ToArray());
        bool confirmed = EditorUtility.DisplayDialog(
            "Reset Guest Progress?",
            "Save root:\n" + saveRoot +
            "\n\nThe following guest progression files will be permanently " +
            "removed:\n" + fileList +
            "\n\nSettings, PlayerPrefs, analytics, consent, cloud data, and " +
            "other files will not be changed.",
            "Remove Guest Progress",
            "Cancel");
        if (!confirmed)
            return;

        string currentRoot;
        if (!TryResolvePermittedSaveRoot(out currentRoot, out error) ||
            !PathsEqual(saveRoot, currentRoot))
        {
            EditorUtility.DisplayDialog(
                "Guest Progress Reset Aborted",
                "The permitted save root changed or could no longer be " +
                "verified after confirmation. No files were removed.\n\n" +
                (error ?? "Previously verified: " + saveRoot +
                 "\nCurrent: " + currentRoot),
                "OK");
            return;
        }

        List<string> currentFiles;
        if (!TryGetProgressFiles(currentRoot, out currentFiles, out error) ||
            !ListsEqual(filesToRemove, currentFiles))
        {
            EditorUtility.DisplayDialog(
                "Guest Progress Reset Aborted",
                "The progression file inventory changed or could no longer " +
                "be verified after confirmation. No files were removed.\n\n" +
                (error ?? "Review the guest progression files and retry."),
                "OK");
            return;
        }

        var removedFiles = new List<string>();
        var failures = new List<string>();
        foreach (string filePath in currentFiles)
        {
            try
            {
                FileAttributes attributes = File.GetAttributes(filePath);
                if ((attributes & FileAttributes.ReparsePoint) != 0 ||
                    (attributes & FileAttributes.Directory) != 0)
                {
                    throw new IOException(
                        "The target is no longer a regular file.");
                }

                File.Delete(filePath);
                if (File.Exists(filePath))
                {
                    throw new IOException(
                        "The file still exists after deletion.");
                }

                removedFiles.Add(filePath);
            }
            catch (Exception exception)
            {
                failures.Add(filePath + "\n" + exception.Message);
            }
        }

        List<string> remainingFiles;
        if (!TryGetProgressFiles(currentRoot, out remainingFiles, out error))
        {
            failures.Add("Post-reset verification failed:\n" + error);
        }
        else if (remainingFiles.Count > 0)
        {
            failures.Add(
                "Progression files remain:\n" +
                string.Join("\n", remainingFiles.ToArray()));
        }

        if (failures.Count > 0)
        {
            string details =
                "PARTIAL RESET. A clean new-player state is not confirmed.\n\n" +
                "Removed:\n" +
                (removedFiles.Count == 0
                    ? "(none)"
                    : string.Join("\n", removedFiles.ToArray())) +
                "\n\nFailures:\n" +
                string.Join("\n\n", failures.ToArray());
            Debug.LogError("GUEST PROGRESS RESET | " + details);
            EditorUtility.DisplayDialog(
                "Guest Progress Reset Incomplete",
                details,
                "OK");
            return;
        }

        Debug.Log(
            "GUEST PROGRESS RESET | Managed guest progression files removed " +
            "from " + currentRoot);
        EditorUtility.DisplayDialog(
            "Guest Progress Reset Complete",
            "Managed guest progression files were removed from:\n\n" +
            currentRoot +
            "\n\nThe next Play Mode session can initialize as a fresh guest. " +
            "Tutorial behavior has not been runtime-tested.",
            "OK");
    }

    [MenuItem(MenuPath, true)]
    private static bool ValidateResetMenu()
    {
        return !EditorApplication.isPlayingOrWillChangePlaymode;
    }

    private static bool TryResolvePermittedSaveRoot(
        out string saveRoot,
        out string error)
    {
        saveRoot = null;
        error = null;

        if (Environment.GetEnvironmentVariable(SandboxOptInVariable) != null ||
            Environment.GetEnvironmentVariable(SandboxRunIdVariable) != null)
        {
            error =
                "Guest QA sandbox environment configuration is present or " +
                "ambiguous. Reset is permitted only in the normal development " +
                "test root.";
            return false;
        }

        try
        {
            if (!SavePathPolicy.IsDevelopmentSaveIsolationEnabled)
            {
                error =
                    "The active Editor is not using development save isolation.";
                return false;
            }

            string persistentDataPath =
                Path.GetFullPath(Application.persistentDataPath);
            string expectedDevelopmentRoot = Path.GetFullPath(Path.Combine(
                persistentDataPath,
                DevelopmentSaveDirectoryName));
            string expectedDevelopmentParent =
                Path.GetDirectoryName(expectedDevelopmentRoot);
            string activeSaveRoot = Path.GetFullPath(
                SavePathPolicy.GetSaveDirectory());

            if (!PathsEqual(persistentDataPath, expectedDevelopmentParent) ||
                !PathsEqual(activeSaveRoot, expectedDevelopmentRoot))
            {
                error =
                    "The active save root is not the exact permitted " +
                    "SweetMaker-Development directory.\n\nExpected:\n" +
                    expectedDevelopmentRoot + "\n\nResolved:\n" +
                    activeSaveRoot;
                return false;
            }

            EnsureNoReparsePointsInPath(expectedDevelopmentRoot);
            if (File.Exists(expectedDevelopmentRoot))
            {
                error =
                    "The permitted development save root exists as a file.";
                return false;
            }

            saveRoot = expectedDevelopmentRoot;
            return true;
        }
        catch (Exception exception)
        {
            error =
                "The active development save root could not be safely " +
                "verified. Reset was refused.\n\n" + exception;
            return false;
        }
    }

    private static bool TryGetProgressFiles(
        string saveRoot,
        out List<string> files,
        out string error)
    {
        files = new List<string>();
        error = null;

        try
        {
            FileAttributes rootAttributes;
            if (!TryGetAttributes(saveRoot, out rootAttributes))
                return true;

            if ((rootAttributes & FileAttributes.ReparsePoint) != 0 ||
                (rootAttributes & FileAttributes.Directory) == 0)
            {
                throw new IOException(
                    "The development save root is not a regular directory.");
            }

            var rootEntries = GetEntryMap(saveRoot);
            var rootFileNames = new HashSet<string>(
                StringComparer.OrdinalIgnoreCase);
            AddManagedFileNames(rootFileNames, SaveV2FileName);
            AddManagedFileNames(rootFileNames, LegacySaveFileName);
            AddManagedFileNames(rootFileNames, "cloud-sync-v1.json");

            foreach (KeyValuePair<string, string> entry in rootEntries)
            {
                if (rootFileNames.Contains(entry.Key))
                {
                    AddRegularFile(entry.Value, files);
                    continue;
                }

                if (entry.Key.StartsWith(
                        CorruptSavePrefix,
                        StringComparison.OrdinalIgnoreCase))
                {
                    string suffix = entry.Key.Substring(
                        CorruptSavePrefix.Length);
                    if (!Guid.TryParseExact(suffix, "N", out _))
                    {
                        throw new IOException(
                            "An unrecognized Save V2 diagnostic file exists: " +
                            entry.Value);
                    }

                    AddRegularFile(entry.Value, files);
                }
            }

            AddLocalStoreFiles(
                saveRoot,
                rootEntries,
                TutorialDirectoryName,
                TutorialFileName,
                files);
            AddLocalStoreFiles(
                saveRoot,
                rootEntries,
                CafeProfileDirectoryName,
                CafeProfileFileName,
                files);

            files.Sort(StringComparer.OrdinalIgnoreCase);
            return true;
        }
        catch (Exception exception)
        {
            files.Clear();
            error =
                "Guest progression files could not be identified safely. " +
                "No files were removed.\n\n" + exception;
            return false;
        }
    }

    private static void AddManagedFileNames(
        HashSet<string> names,
        string primaryFileName)
    {
        foreach (string suffix in ManagedSuffixes)
            names.Add(primaryFileName + suffix);
    }

    private static void AddLocalStoreFiles(
        string saveRoot,
        Dictionary<string, string> rootEntries,
        string directoryName,
        string primaryFileName,
        List<string> files)
    {
        string directoryPath = Path.Combine(saveRoot, directoryName);
        string actualDirectoryPath;
        if (!rootEntries.TryGetValue(directoryName, out actualDirectoryPath))
            return;

        FileAttributes directoryAttributes =
            File.GetAttributes(actualDirectoryPath);
        if ((directoryAttributes & FileAttributes.ReparsePoint) != 0 ||
            (directoryAttributes & FileAttributes.Directory) == 0)
        {
            throw new IOException(
                "The local progression directory is not a regular directory: " +
                actualDirectoryPath);
        }

        var allowedNames = new HashSet<string>(
            StringComparer.OrdinalIgnoreCase);
        AddManagedFileNames(allowedNames, primaryFileName);

        foreach (KeyValuePair<string, string> entry in GetEntryMap(directoryPath))
        {
            if (!allowedNames.Contains(entry.Key))
            {
                throw new IOException(
                    "An unexpected entry exists in the dedicated " +
                    "progression directory; reset cannot establish a clean " +
                    "state without risking unrelated data: " + entry.Value);
            }

            AddRegularFile(entry.Value, files);
        }
    }

    private static Dictionary<string, string> GetEntryMap(string directory)
    {
        var entries = new Dictionary<string, string>(
            StringComparer.OrdinalIgnoreCase);
        foreach (string path in Directory.GetFileSystemEntries(directory))
        {
            string name = Path.GetFileName(path);
            if (entries.ContainsKey(name))
            {
                throw new IOException(
                    "Ambiguous file names exist in a progression directory: " +
                    directory);
            }

            entries.Add(name, path);
        }

        return entries;
    }

    private static void AddRegularFile(string path, List<string> files)
    {
        FileAttributes attributes = File.GetAttributes(path);
        if ((attributes & FileAttributes.ReparsePoint) != 0 ||
            (attributes & FileAttributes.Directory) != 0)
        {
            throw new IOException(
                "A progression target is not a regular file: " + path);
        }

        files.Add(Path.GetFullPath(path));
    }

    private static bool TryGetAttributes(
        string path,
        out FileAttributes attributes)
    {
        try
        {
            attributes = File.GetAttributes(path);
            return true;
        }
        catch (FileNotFoundException)
        {
            attributes = 0;
            return false;
        }
        catch (DirectoryNotFoundException)
        {
            attributes = 0;
            return false;
        }
    }

    private static void EnsureNoReparsePointsInPath(string path)
    {
        string currentPath = Path.GetFullPath(path);
        while (!string.IsNullOrEmpty(currentPath))
        {
            FileAttributes attributes;
            if (TryGetAttributes(currentPath, out attributes) &&
                (attributes & FileAttributes.ReparsePoint) != 0)
            {
                throw new IOException(
                    "The permitted development save path contains a " +
                    "filesystem reparse point: " + currentPath);
            }

            string parentPath = Path.GetDirectoryName(currentPath);
            if (string.IsNullOrEmpty(parentPath) ||
                PathsEqual(parentPath, currentPath))
            {
                break;
            }

            currentPath = parentPath;
        }
    }

    private static bool PathsEqual(string first, string second)
    {
        return string.Equals(
            TrimEndingSeparators(Path.GetFullPath(first)),
            TrimEndingSeparators(Path.GetFullPath(second)),
            StringComparison.OrdinalIgnoreCase);
    }

    private static string TrimEndingSeparators(string path)
    {
        string root = Path.GetPathRoot(path);
        while (path.Length > root.Length &&
               (path[path.Length - 1] == Path.DirectorySeparatorChar ||
                path[path.Length - 1] == Path.AltDirectorySeparatorChar))
        {
            path = path.Substring(0, path.Length - 1);
        }

        return path;
    }

    private static bool ListsEqual(
        List<string> first,
        List<string> second)
    {
        if (first.Count != second.Count)
            return false;

        for (int i = 0; i < first.Count; i++)
        {
            if (!PathsEqual(first[i], second[i]))
                return false;
        }

        return true;
    }
}
#endif
