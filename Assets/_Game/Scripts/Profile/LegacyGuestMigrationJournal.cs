using System;
using System.Collections.Generic;
using System.Globalization;
using System.Security.Cryptography;
using System.Text;

namespace SweetMerge.Profile
{
    public enum LegacyGuestMigrationPhase
    {
        Prepared = 0,
        Staging = 1,
        StagedVerified = 2,
        Promoted = 3,
        Completed = 4,
        Deferred = 5
    }

    public enum LegacyGuestMigrationAttemptOutcome
    {
        Started = 0,
        SourceChanged = 1,
        Deferred = 2,
        Completed = 3
    }

    [Serializable]
    public sealed class LegacyGuestMigrationManifestEntry
    {
        public string relativePath;
        public long byteLength;
        public string sha256;
    }

    [Serializable]
    public sealed class LegacyGuestMigrationAttempt
    {
        public int attemptNumber;
        public string launchId;
        public string sourceManifestHash;
        public LegacyGuestMigrationAttemptOutcome outcome;
    }

    [Serializable]
    public sealed class LegacyGuestMigrationJournal
    {
        public int version;
        public string transactionId;
        public LegacyGuestMigrationPhase phase;
        public string environmentMode;
        public string environmentRootFingerprint;
        public string sourceKey;
        public string destinationKey;
        public string ownerProfileKey;
        public string ownerPlayerId;
        public LocalProfileKind ownerKind;
        public string ownerEnvironmentMode;
        public string ownerEnvironmentRootFingerprint;
        public string launchId;
        public string manifestHash;
        public int attemptsThisLaunch;
        public int cumulativeAttempts;
        public List<LegacyGuestMigrationManifestEntry> manifest =
            new List<LegacyGuestMigrationManifestEntry>();
        public List<LegacyGuestMigrationAttempt> attemptHistory =
            new List<LegacyGuestMigrationAttempt>();
        public string failureReason;
        public string deferReason;
    }

    public static class LegacyGuestMigrationJournalValidator
    {
        public const int CurrentVersion = 1;
        public const int MaximumAttemptsPerLaunch = 3;
        public const string LegacyRootSourceKey = "legacy-root";
        public const string GuestDestinationKey = "guest";
        private const int MaximumHistoryEntries = 10000;
        private const int MaximumRelativePathLength = 1024;
        private const int MaximumReasonLength = 2048;

        public static bool TryValidate(
            LegacyGuestMigrationJournal journal,
            LocalProfileEnvironmentIdentity expectedEnvironment,
            out string errorMessage)
        {
            errorMessage = null;
            if (journal == null)
                return Fail("Migration journal is missing.", out errorMessage);
            if (journal.version != CurrentVersion)
                return Fail("Migration journal version is unsupported.", out errorMessage);
            if (!IsCanonicalGuid(journal.transactionId))
                return Fail("Migration transaction ID is invalid.", out errorMessage);
            if (!IsValidPhase(journal.phase))
                return Fail("Migration journal phase is invalid.", out errorMessage);
            if (!string.Equals(
                    journal.sourceKey,
                    LegacyRootSourceKey,
                    StringComparison.Ordinal) ||
                !string.Equals(
                    journal.destinationKey,
                    GuestDestinationKey,
                    StringComparison.Ordinal))
                return Fail("Migration journal source or destination is invalid.", out errorMessage);
            if (expectedEnvironment == null)
                return Fail(
                    "Migration environment identity is missing.",
                    out errorMessage);
            if (!LocalProfileOwnerMetadataValidator.IsExpectedEnvironment(
                    journal.environmentMode,
                    journal.environmentRootFingerprint,
                    expectedEnvironment,
                    out string environmentError))
                return Fail(environmentError, out errorMessage);
            if (!string.Equals(
                    journal.ownerEnvironmentMode,
                    journal.environmentMode,
                    StringComparison.Ordinal) ||
                !string.Equals(
                    journal.ownerEnvironmentRootFingerprint,
                    journal.environmentRootFingerprint,
                    StringComparison.Ordinal) ||
                journal.ownerKind != LocalProfileKind.Guest ||
                !string.IsNullOrEmpty(journal.ownerPlayerId) ||
                !string.Equals(
                    journal.ownerProfileKey,
                    GuestDestinationKey,
                    StringComparison.Ordinal))
                return Fail("Migration owner binding is invalid.", out errorMessage);
            if (!IsCanonicalGuid(journal.launchId))
                return Fail("Migration launch ID is invalid.", out errorMessage);
            if (journal.attemptsThisLaunch < 0 ||
                journal.attemptsThisLaunch > MaximumAttemptsPerLaunch ||
                journal.cumulativeAttempts < 0 ||
                journal.attemptHistory == null ||
                journal.attemptHistory.Count > MaximumHistoryEntries ||
                journal.cumulativeAttempts != journal.attemptHistory.Count)
                return Fail("Migration attempt counters are inconsistent.", out errorMessage);
            if (journal.manifest == null ||
                !ValidateManifest(journal.manifest, out errorMessage))
                return false;
            if (!IsSha256(journal.manifestHash) ||
                !string.Equals(
                    journal.manifestHash,
                    ComputeManifestHash(journal.manifest),
                    StringComparison.Ordinal))
                return Fail("Migration manifest hash is invalid.", out errorMessage);
            if (!ValidateAttemptHistory(journal, out errorMessage))
                return false;
            if (!ValidatePhaseAttempt(journal, out errorMessage))
                return false;
            if (!ValidateReasons(journal, out errorMessage))
                return false;

            return true;
        }

        public static bool TryValidateTransition(
            LegacyGuestMigrationJournal previous,
            LegacyGuestMigrationJournal next,
            LocalProfileEnvironmentIdentity expectedEnvironment,
            out string errorMessage)
        {
            if (!TryValidate(previous, expectedEnvironment, out errorMessage) ||
                !TryValidate(next, expectedEnvironment, out errorMessage))
                return false;

            if (!SameTransaction(previous, next))
                return Fail("A journal transition cannot change transaction identity.", out errorMessage);
            if (previous.phase == LegacyGuestMigrationPhase.Completed)
            {
                if (!SameJournal(previous, next))
                    return Fail("A completed migration journal is immutable.", out errorMessage);
                return true;
            }

            bool launchChanged = !string.Equals(
                previous.launchId,
                next.launchId,
                StringComparison.Ordinal);
            if (launchChanged &&
                previous.phase == next.phase &&
                previous.phase != LegacyGuestMigrationPhase.Completed &&
                next.attemptsThisLaunch == 0 &&
                next.cumulativeAttempts == previous.cumulativeAttempts &&
                SameManifest(previous.manifest, next.manifest) &&
                IsAttemptHistoryPrefix(
                    previous.attemptHistory,
                    next.attemptHistory) &&
                SameTransaction(previous, next))
                return true;

            if (launchChanged &&
                (next.attemptsThisLaunch != 0 ||
                 next.cumulativeAttempts != previous.cumulativeAttempts ||
                 !IsAttemptHistoryPrefix(previous.attemptHistory, next.attemptHistory)))
                return Fail("Changing launch identity cannot reset cumulative history.", out errorMessage);

            if (next.cumulativeAttempts < previous.cumulativeAttempts ||
                next.attemptsThisLaunch < 0 ||
                (!launchChanged &&
                 next.attemptsThisLaunch < previous.attemptsThisLaunch))
                return Fail("Migration attempt counters cannot move backwards.", out errorMessage);

            if (!IsAllowedTransition(previous.phase, next.phase))
                return Fail("Migration phase transition is not allowed.", out errorMessage);

            if (next.cumulativeAttempts > previous.cumulativeAttempts + 1)
                return Fail("A transition cannot add multiple migration attempts.", out errorMessage);
            if (next.cumulativeAttempts == previous.cumulativeAttempts + 1 &&
                !IsAttemptHistoryPrefix(previous.attemptHistory, next.attemptHistory))
                return Fail("Migration attempt history must be append-only.", out errorMessage);
            if (next.cumulativeAttempts == previous.cumulativeAttempts &&
                !SameAttemptHistory(previous.attemptHistory, next.attemptHistory))
                return Fail("Migration attempt history changed without a new attempt.", out errorMessage);

            return true;
        }

        public static string ComputeManifestHash(
            IList<LegacyGuestMigrationManifestEntry> manifest)
        {
            if (manifest == null)
                throw new ArgumentNullException(nameof(manifest));

            StringBuilder canonical = new StringBuilder();
            for (int i = 0; i < manifest.Count; i++)
            {
                LegacyGuestMigrationManifestEntry entry = manifest[i];
                if (entry == null)
                    throw new ArgumentException("Manifest contains a null entry.", nameof(manifest));

                canonical.Append(entry.relativePath)
                    .Append('\n')
                    .Append(entry.byteLength.ToString(CultureInfo.InvariantCulture))
                    .Append('\n')
                    .Append(entry.sha256)
                    .Append('\n');
            }

            using (SHA256 sha256 = SHA256.Create())
            {
                byte[] hash = sha256.ComputeHash(
                    new UTF8Encoding(false, true).GetBytes(canonical.ToString()));
                const string Hex = "0123456789abcdef";
                char[] result = new char[hash.Length * 2];
                for (int i = 0; i < hash.Length; i++)
                {
                    result[i * 2] = Hex[hash[i] >> 4];
                    result[i * 2 + 1] = Hex[hash[i] & 0x0f];
                }

                return new string(result);
            }
        }

        private static bool ValidateManifest(
            IList<LegacyGuestMigrationManifestEntry> manifest,
            out string errorMessage)
        {
            errorMessage = null;
            string previousPath = null;
            var seenPaths = new HashSet<string>(
                StringComparer.OrdinalIgnoreCase);
            for (int i = 0; i < manifest.Count; i++)
            {
                LegacyGuestMigrationManifestEntry entry = manifest[i];
                if (entry == null ||
                    !IsValidRelativePath(entry.relativePath) ||
                    entry.byteLength < 0 ||
                    !IsSha256(entry.sha256) ||
                    !seenPaths.Add(entry.relativePath))
                    return Fail("Migration manifest entry is invalid.", out errorMessage);

                if (previousPath != null &&
                    string.CompareOrdinal(previousPath, entry.relativePath) >= 0)
                    return Fail("Migration manifest paths must be unique and ordinally sorted.", out errorMessage);

                previousPath = entry.relativePath;
            }

            return true;
        }

        private static bool ValidateAttemptHistory(
            LegacyGuestMigrationJournal journal,
            out string errorMessage)
        {
            errorMessage = null;
            int currentLaunchAttempts = 0;
            int expectedAttemptNumber = 0;
            string previousLaunch = null;
            for (int i = 0; i < journal.attemptHistory.Count; i++)
            {
                LegacyGuestMigrationAttempt attempt =
                    journal.attemptHistory[i];
                if (attempt == null ||
                    !IsCanonicalGuid(attempt.launchId) ||
                    !IsSha256(attempt.sourceManifestHash) ||
                    !Enum.IsDefined(
                        typeof(LegacyGuestMigrationAttemptOutcome),
                        attempt.outcome))
                    return Fail("Migration attempt history contains invalid data.", out errorMessage);

                if (!string.Equals(
                        previousLaunch,
                        attempt.launchId,
                        StringComparison.Ordinal))
                {
                    previousLaunch = attempt.launchId;
                    expectedAttemptNumber = 0;
                }

                expectedAttemptNumber++;
                if (attempt.attemptNumber != expectedAttemptNumber)
                    return Fail("Migration attempt numbers are not sequential per launch.", out errorMessage);

                if (string.Equals(
                        attempt.launchId,
                        journal.launchId,
                        StringComparison.Ordinal))
                    currentLaunchAttempts++;
            }

            if (currentLaunchAttempts != journal.attemptsThisLaunch)
                return Fail("Per-launch attempt count does not match the attempt history.", out errorMessage);

            return true;
        }

        private static bool ValidateReasons(
            LegacyGuestMigrationJournal journal,
            out string errorMessage)
        {
            errorMessage = null;
            if ((journal.phase == LegacyGuestMigrationPhase.Deferred) !=
                    !string.IsNullOrWhiteSpace(journal.deferReason) ||
                (journal.phase == LegacyGuestMigrationPhase.Completed &&
                 !string.IsNullOrEmpty(journal.failureReason)))
                return Fail("Migration failure/defer reason contradicts its phase.", out errorMessage);

            if (journal.failureReason != null &&
                    journal.failureReason.Length > MaximumReasonLength ||
                journal.deferReason != null &&
                    journal.deferReason.Length > MaximumReasonLength)
                return Fail("Migration reason exceeds the supported length.", out errorMessage);

            return true;
        }

        private static bool ValidatePhaseAttempt(
            LegacyGuestMigrationJournal journal,
            out string errorMessage)
        {
            errorMessage = null;
            if (journal.attemptsThisLaunch == 0)
                return true;

            LegacyGuestMigrationAttempt latest =
                journal.attemptHistory[
                    journal.attemptHistory.Count - 1];
            if (!string.Equals(
                    latest.launchId,
                    journal.launchId,
                    StringComparison.Ordinal))
                return Fail(
                    "Current-launch attempt history is not the latest history.",
                    out errorMessage);

            if (journal.phase == LegacyGuestMigrationPhase.Staging &&
                latest.outcome != LegacyGuestMigrationAttemptOutcome.Started)
                return Fail(
                    "Staging phase requires a started attempt.",
                    out errorMessage);

            if ((journal.phase == LegacyGuestMigrationPhase.StagedVerified ||
                 journal.phase == LegacyGuestMigrationPhase.Promoted ||
                 journal.phase == LegacyGuestMigrationPhase.Completed) &&
                latest.outcome != LegacyGuestMigrationAttemptOutcome.Completed)
                return Fail(
                    "Verified migration phases require a completed attempt.",
                    out errorMessage);

            if (journal.phase == LegacyGuestMigrationPhase.Deferred &&
                string.Equals(
                    journal.deferReason,
                    "source-changed",
                    StringComparison.Ordinal) &&
                latest.outcome != LegacyGuestMigrationAttemptOutcome.SourceChanged)
                return Fail(
                    "Source-change deferral requires a source-change attempt outcome.",
                    out errorMessage);

            if (journal.phase == LegacyGuestMigrationPhase.Deferred &&
                !string.Equals(
                    journal.deferReason,
                    "source-changed",
                    StringComparison.Ordinal) &&
                latest.outcome == LegacyGuestMigrationAttemptOutcome.Started)
                return Fail(
                    "Deferred migration cannot retain an unfinished attempt.",
                    out errorMessage);

            return true;
        }

        private static bool IsAllowedTransition(
            LegacyGuestMigrationPhase previous,
            LegacyGuestMigrationPhase next)
        {
            if (next == LegacyGuestMigrationPhase.Deferred)
                return previous != LegacyGuestMigrationPhase.Completed;

            switch (previous)
            {
                case LegacyGuestMigrationPhase.Prepared:
                    return next == LegacyGuestMigrationPhase.Staging;
                case LegacyGuestMigrationPhase.Staging:
                    return next == LegacyGuestMigrationPhase.StagedVerified;
                case LegacyGuestMigrationPhase.StagedVerified:
                    return next == LegacyGuestMigrationPhase.Promoted;
                case LegacyGuestMigrationPhase.Promoted:
                    return next == LegacyGuestMigrationPhase.Completed;
                case LegacyGuestMigrationPhase.Deferred:
                    return next == LegacyGuestMigrationPhase.Staging;
                default:
                    return false;
            }
        }

        private static bool SameTransaction(
            LegacyGuestMigrationJournal left,
            LegacyGuestMigrationJournal right)
        {
            return string.Equals(left.transactionId, right.transactionId, StringComparison.Ordinal) &&
                   string.Equals(left.environmentMode, right.environmentMode, StringComparison.Ordinal) &&
                   string.Equals(left.environmentRootFingerprint, right.environmentRootFingerprint, StringComparison.Ordinal) &&
                   string.Equals(left.sourceKey, right.sourceKey, StringComparison.Ordinal) &&
                   string.Equals(left.destinationKey, right.destinationKey, StringComparison.Ordinal) &&
                   string.Equals(left.ownerProfileKey, right.ownerProfileKey, StringComparison.Ordinal) &&
                   string.Equals(left.ownerPlayerId, right.ownerPlayerId, StringComparison.Ordinal) &&
                   left.ownerKind == right.ownerKind &&
                   string.Equals(left.ownerEnvironmentMode, right.ownerEnvironmentMode, StringComparison.Ordinal) &&
                   string.Equals(left.ownerEnvironmentRootFingerprint, right.ownerEnvironmentRootFingerprint, StringComparison.Ordinal);
        }

        private static bool SameJournal(
            LegacyGuestMigrationJournal left,
            LegacyGuestMigrationJournal right)
        {
            return SameTransaction(left, right) &&
                   left.version == right.version &&
                   left.phase == right.phase &&
                   string.Equals(left.launchId, right.launchId, StringComparison.Ordinal) &&
                   string.Equals(left.manifestHash, right.manifestHash, StringComparison.Ordinal) &&
                   left.attemptsThisLaunch == right.attemptsThisLaunch &&
                   left.cumulativeAttempts == right.cumulativeAttempts &&
                   string.Equals(left.failureReason, right.failureReason, StringComparison.Ordinal) &&
                   string.Equals(left.deferReason, right.deferReason, StringComparison.Ordinal) &&
                   SameManifest(left.manifest, right.manifest) &&
                   SameAttemptHistory(left.attemptHistory, right.attemptHistory);
        }

        private static bool SameManifest(
            IList<LegacyGuestMigrationManifestEntry> left,
            IList<LegacyGuestMigrationManifestEntry> right)
        {
            if (left == null || right == null || left.Count != right.Count)
                return false;
            for (int i = 0; i < left.Count; i++)
            {
                if (left[i] == null || right[i] == null ||
                    !string.Equals(left[i].relativePath, right[i].relativePath, StringComparison.Ordinal) ||
                    left[i].byteLength != right[i].byteLength ||
                    !string.Equals(left[i].sha256, right[i].sha256, StringComparison.Ordinal))
                    return false;
            }

            return true;
        }

        private static bool SameAttemptHistory(
            IList<LegacyGuestMigrationAttempt> left,
            IList<LegacyGuestMigrationAttempt> right)
        {
            if (left == null || right == null || left.Count != right.Count)
                return false;
            for (int i = 0; i < left.Count; i++)
            {
                if (!SameAttempt(left[i], right[i]))
                    return false;
            }

            return true;
        }

        private static bool IsAttemptHistoryPrefix(
            IList<LegacyGuestMigrationAttempt> prefix,
            IList<LegacyGuestMigrationAttempt> value)
        {
            if (prefix == null || value == null || prefix.Count > value.Count)
                return false;
            for (int i = 0; i < prefix.Count; i++)
            {
                if (!SameAttempt(prefix[i], value[i]))
                    return false;
            }

            return true;
        }

        private static bool SameAttempt(
            LegacyGuestMigrationAttempt left,
            LegacyGuestMigrationAttempt right)
        {
            return left != null && right != null &&
                   left.attemptNumber == right.attemptNumber &&
                   left.outcome == right.outcome &&
                   string.Equals(left.launchId, right.launchId, StringComparison.Ordinal) &&
                   string.Equals(left.sourceManifestHash, right.sourceManifestHash, StringComparison.Ordinal);
        }

        private static bool IsValidRelativePath(string path)
        {
            if (string.IsNullOrEmpty(path) ||
                path.Length > MaximumRelativePathLength ||
                path[0] == '/' ||
                path.IndexOf('\\') >= 0 ||
                path.IndexOf(':') >= 0)
                return false;

            string[] segments = path.Split('/');
            for (int i = 0; i < segments.Length; i++)
            {
                if (segments[i].Length == 0 ||
                    segments[i] == "." ||
                    segments[i] == "..")
                    return false;
            }

            for (int i = 0; i < path.Length; i++)
            {
                if (char.IsControl(path[i]))
                    return false;
            }

            return true;
        }

        private static bool IsCanonicalGuid(string value)
        {
            return Guid.TryParseExact(value, "N", out Guid parsed) &&
                   string.Equals(
                       value,
                       parsed.ToString("N"),
                       StringComparison.Ordinal);
        }

        private static bool IsSha256(string value)
        {
            return LocalProfileEnvironmentIdentity.IsValidFingerprint(value);
        }

        private static bool IsValidPhase(LegacyGuestMigrationPhase phase)
        {
            return Enum.IsDefined(typeof(LegacyGuestMigrationPhase), phase);
        }

        private static bool Fail(string message, out string errorMessage)
        {
            errorMessage = message;
            return false;
        }
    }
}
