using System;
using System.IO;
using UnityEngine;

namespace SweetMerge.Profile
{
    [Serializable]
    internal sealed class TutorialProgressJournalRecord
    {
        public int version;
        public string playerId;
        public string environment;
        public int pendingStage;
        public bool completionRequested;
    }

    internal static class TutorialProgressJournal
    {
        private const int CurrentVersion = 1;
        private const string FilePrefix = "tutorial-progress-";
        private const string FileSuffix = ".journal.json";

        internal static bool TryLoad(
            string playerId,
            out TutorialStage pendingStage,
            out string errorMessage)
        {
            pendingStage = TutorialStage.Welcome;
            errorMessage = null;
            if (!TryGetPaths(
                    playerId,
                    out string destination,
                    out string temporary,
                    out string backup,
                    out errorMessage))
                return false;

            try
            {
                string[] candidates =
                {
                    destination,
                    backup,
                    temporary
                };
                for (int index = 0; index < candidates.Length; index++)
                {
                    if (!File.Exists(candidates[index]))
                        continue;

                    try
                    {
                        string json = File.ReadAllText(candidates[index]);
                        TutorialProgressJournalRecord record =
                            JsonUtility.FromJson
                                <TutorialProgressJournalRecord>(json);
                        if (!IsValidRecord(record, playerId))
                            continue;

                        pendingStage =
                            (TutorialStage)record.pendingStage;
                        return true;
                    }
                    catch (Exception)
                    {
                        continue;
                    }
                }

                if (!File.Exists(destination) &&
                    !File.Exists(backup) &&
                    !File.Exists(temporary))
                    return true;

                errorMessage = "The tutorial progress journal is malformed.";
                return false;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "The tutorial progress journal could not be read: " +
                    exception.Message;
                return false;
            }
        }

        internal static bool TrySave(
            string playerId,
            TutorialStage pendingStage,
            out string errorMessage)
        {
            errorMessage = null;
            if (!TryGetPaths(
                    playerId,
                    out string destination,
                    out string temporary,
                    out string backup,
                    out errorMessage))
                return false;

            try
            {
                Directory.CreateDirectory(Path.GetDirectoryName(destination));
                TutorialProgressJournalRecord record =
                    new TutorialProgressJournalRecord
                    {
                        version = CurrentVersion,
                        playerId = playerId,
                        environment = SavePathPolicy.ModeName,
                        pendingStage = (int)pendingStage,
                        completionRequested =
                            pendingStage == TutorialStage.Completed
                    };
                string json = JsonUtility.ToJson(record, false);
                File.WriteAllText(temporary, json);

                if (File.Exists(destination))
                    File.Replace(temporary, destination, backup);
                else
                    File.Move(temporary, destination);

                return true;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "The tutorial progress journal could not be saved: " +
                    exception.Message;
                TryDelete(temporary);
                return false;
            }
        }

        internal static bool TryClear(
            string playerId,
            out string errorMessage)
        {
            errorMessage = null;
            if (!TryGetPaths(
                    playerId,
                    out string destination,
                    out string temporary,
                    out string backup,
                    out errorMessage))
                return false;

            try
            {
                TryDelete(destination);
                TryDelete(temporary);
                TryDelete(backup);
                return true;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "The tutorial progress journal could not be cleared: " +
                    exception.Message;
                return false;
            }
        }

        private static bool TryGetPaths(
            string playerId,
            out string destination,
            out string temporary,
            out string backup,
            out string errorMessage)
        {
            destination = null;
            temporary = null;
            backup = null;
            errorMessage = null;
            if (string.IsNullOrWhiteSpace(playerId))
            {
                errorMessage = "A valid player ID is required.";
                return false;
            }

            try
            {
                string directory = Path.Combine(
                    Application.persistentDataPath,
                    "TutorialProgress");
                string fileName = FilePrefix +
                    SavePathPolicy.ModeName.ToLowerInvariant() +
                    "-" +
                    SanitizePlayerId(playerId) +
                    FileSuffix;
                destination = Path.Combine(directory, fileName);
                temporary = destination + ".tmp";
                backup = destination + ".bak";
                return true;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "The tutorial progress journal path is unavailable: " +
                    exception.Message;
                return false;
            }
        }

        private static bool IsValidRecord(
            TutorialProgressJournalRecord record,
            string playerId)
        {
            return record != null &&
                record.version == CurrentVersion &&
                record.playerId == playerId &&
                record.environment == SavePathPolicy.ModeName &&
                record.completionRequested ==
                    (record.pendingStage == (int)TutorialStage.Completed) &&
                Enum.IsDefined(
                    typeof(TutorialStage),
                    record.pendingStage) &&
                record.pendingStage > (int)TutorialStage.Welcome;
        }

        private static string SanitizePlayerId(string playerId)
        {
            char[] characters = playerId.ToCharArray();
            for (int index = 0; index < characters.Length; index++)
            {
                if (!char.IsLetterOrDigit(characters[index]) &&
                    characters[index] != '-' &&
                    characters[index] != '_')
                    characters[index] = '_';
            }

            return new string(characters);
        }

        private static void TryDelete(string path)
        {
            if (File.Exists(path))
                File.Delete(path);
        }
    }
}
