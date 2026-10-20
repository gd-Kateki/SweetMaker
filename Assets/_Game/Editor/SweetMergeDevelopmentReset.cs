
#if UNITY_EDITOR
using System;
using System.Collections.Generic;
using System.IO;
using UnityEditor;
using UnityEngine;

public static class SweetMergeDevelopmentReset
{
    private const string SaveFileName = "player_save.json";

    private static readonly string[] ManagedSuffixes =
    {
        "",
        ".bak",
        ".tmp",
        ".bak.tmp",
        ".recover.tmp"
    };

    [MenuItem("Tools/Sweet Merge/Reset Development Progress")]
    private static void ResetDevelopmentProgress()
    {
        if (EditorApplication.isPlayingOrWillChangePlaymode)
        {
            EditorUtility.DisplayDialog(
                "Reset Not Allowed",
                "Stop Play Mode before resetting progress.",
                "OK");
            return;
        }

        string saveDirectory = Application.persistentDataPath;
        string primaryPath = Path.Combine(
            saveDirectory, SaveFileName);

        var filesToMove = new List<string>();

        foreach (string suffix in ManagedSuffixes)
        {
            string path = primaryPath + suffix;

            if (File.Exists(path))
                filesToMove.Add(path);
        }

        if (filesToMove.Count == 0)
        {
            EditorUtility.DisplayDialog(
                "No Save Files",
                "No managed save files were found.\n\n" +
                "The next launch should use fresh-game initialization.",
                "OK");
            return;
        }

        bool confirmed = EditorUtility.DisplayDialog(
            "Reset Sweet Merge Development Progress?",
            "This will remove the active development save " +
            "and its backup from the game's save directory.\n\n" +
            "The files will be moved into a recovery folder " +
            "so they can be restored manually.\n\n" +
            "This action affects the current Unity Editor " +
            "persistent-data location only.\n\n" +
            "Continue?",
            "Reset Development Progress",
            "Cancel");

        if (!confirmed)
            return;

        string archiveRoot = Path.Combine(
            saveDirectory, "DevelopmentResetArchives");

        string archiveDirectory = Path.Combine(
            archiveRoot,
            DateTime.UtcNow.ToString(
                "yyyyMMdd_HHmmss_fffffff") +
            "_" + Guid.NewGuid().ToString("N"));

        var movedFiles = new List<string>();

        try
        {
            Directory.CreateDirectory(archiveDirectory);

            foreach (string sourcePath in filesToMove)
            {
                string destinationPath = Path.Combine(
                    archiveDirectory,
                    Path.GetFileName(sourcePath));

                // File.Move fails if the destination exists.
                // Never overwrite archived save files.
                File.Move(sourcePath, destinationPath);
                movedFiles.Add(sourcePath);
            }

            // Verify that every managed active file is absent.
            foreach (string suffix in ManagedSuffixes)
            {
                if (File.Exists(primaryPath + suffix))
                {
                    throw new IOException(
                        "Managed save file remains after reset: " +
                        primaryPath + suffix);
                }
            }

            Debug.Log(
                "DEVELOPMENT RESET | Progress archived successfully.\n" +
                "Archive: " + archiveDirectory + "\n" +
                "Files archived: " + movedFiles.Count + "\n" +
                "The next game launch can initialize fresh progress.");

            EditorUtility.DisplayDialog(
                "Development Reset Complete",
                "Active development progress has been reset.\n\n" +
                "Archived files:\n" + archiveDirectory + "\n\n" +
                "Enter Play Mode to test fresh-game startup.",
                "OK");
        }
        catch (Exception exception)
        {
            // Best-effort rollback in reverse order.
            // Never overwrite a file created unexpectedly.
            var rollbackErrors = new List<string>();

            for (int i = movedFiles.Count - 1; i >= 0; i--)
            {
                string originalPath = movedFiles[i];

                string archivedPath = Path.Combine(
                    archiveDirectory,
                    Path.GetFileName(originalPath));

                try
                {
                    if (File.Exists(archivedPath))
                    {
                        if (File.Exists(originalPath))
                        {
                            rollbackErrors.Add(
                                "Destination already exists: " +
                                originalPath);
                        }
                        else
                        {
                            File.Move(archivedPath, originalPath);
                        }
                    }
                }
                catch (Exception rollbackException)
                {
                    rollbackErrors.Add(
                        originalPath + ": " +
                        rollbackException.Message);
                }
            }

            string details =
                "Reset failed:\n" + exception.Message +
                "\n\nArchive folder:\n" + archiveDirectory;

            if (rollbackErrors.Count > 0)
            {
                details +=
                    "\n\nRollback was incomplete. " +
                    "Do not start the game until the files " +
                    "have been inspected and restored manually.\n\n" +
                    string.Join("\n", rollbackErrors.ToArray());
            }
            else
            {
                details +=
                    "\n\nRollback was attempted. Verify the " +
                    "active save files before starting the game.";
            }

            Debug.LogError(
                "DEVELOPMENT RESET | Failed.\n" +
                exception + "\n" + details);

            EditorUtility.DisplayDialog(
                "Development Reset Failed",
                details,
                "OK");
        }
    }

    [MenuItem(
        "Tools/Sweet Merge/Reset Development Progress",
        true)]
    private static bool ValidateResetMenu()
    {
        return !EditorApplication.isPlayingOrWillChangePlaymode;
    }
}
#endif
