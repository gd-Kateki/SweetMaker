using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using UnityEngine;

namespace SweetMerge.Profile
{
    public enum LegacyGuestMigrationJournalLoadResult
    {
        Missing,
        Loaded,
        Failed
    }

    public enum LegacyGuestMigrationRunStatus
    {
        Completed,
        AlreadyCompleted,
        Deferred,
        Blocked
    }

    public sealed class LegacyGuestMigrationRunResult
    {
        public LegacyGuestMigrationRunStatus Status { get; }
        public string Message { get; }

        internal LegacyGuestMigrationRunResult(
            LegacyGuestMigrationRunStatus status,
            string message)
        {
            Status = status;
            Message = message;
        }
    }

    public interface ILegacyGuestMigrationEnvironment
    {
        string EnvironmentRoot { get; }
        LocalProfileEnvironmentIdentity Identity { get; }
        string LaunchId { get; }
    }

    public interface ILegacyGuestMigrationQuiescence
    {
        // The lease must exclude every save/profile writer and concurrent migration
        // for its lifetime, not only report that no write is currently in progress.
        bool TryAcquire(
            out IDisposable lease,
            out string errorMessage);
    }

    public interface ILegacyGuestMigrationSemanticValidator
    {
        bool ValidateSource(
            LegacyGuestMigrationInventory inventory,
            out string errorMessage);

        bool ValidateStaged(
            string stagedDirectory,
            IList<LegacyGuestMigrationManifestEntry> manifest,
            out string errorMessage);
    }

    public interface ILegacyGuestMigrationJournalStore
    {
        string JournalPath { get; }

        LegacyGuestMigrationJournalLoadResult Load(
            out LegacyGuestMigrationJournal journal,
            out string errorMessage);

        // A successful return must mean the complete validated journal is durable.
        bool SaveDurably(
            LegacyGuestMigrationJournal journal,
            out string errorMessage);
    }

    [Serializable]
    internal sealed class LegacyGuestMigrationReceipt
    {
        public int version;
        public string transactionId;
        public string manifestHash;
        public string environmentMode;
        public string environmentRootFingerprint;
    }

    public sealed class LegacyGuestProfileMigrator
    {
        private const int ReceiptVersion = 1;
        private const string ReceiptFileName =
            ".legacy-migration-receipt-v1.json";
        private const string OwnerFileName = "profile-owner-v1.json";
        private const string JournalDirectoryName = "LegacyGuestMigration";
        private const string JournalFileName =
            "legacy-guest-migration-v1.json";
        private const string SourceChangedReason = "source-changed";
        private const string RecoveryRequiredReason = "recovery-required";
        private const string ValidationFailedReason = "semantic-validation-failed";
        private const string DestinationConflictReason = "destination-conflict";
        private const string AttemptLimitReason = "attempt-limit-reached";
        private static readonly UTF8Encoding StrictUtf8 =
            new UTF8Encoding(false, true);

        private readonly ILegacyGuestMigrationEnvironment environment;
        private readonly ILegacyGuestMigrationQuiescence quiescence;
        private readonly ILegacyGuestMigrationSemanticValidator validator;
        private readonly ILegacyGuestMigrationJournalStore journalStore;

        public LegacyGuestProfileMigrator(
            ILegacyGuestMigrationEnvironment environment,
            ILegacyGuestMigrationQuiescence quiescence,
            ILegacyGuestMigrationSemanticValidator validator,
            ILegacyGuestMigrationJournalStore journalStore)
        {
            this.environment = environment;
            this.quiescence = quiescence;
            this.validator = validator;
            this.journalStore = journalStore;
        }

        public LegacyGuestMigrationRunResult RunOrRecover()
        {
            if (environment == null ||
                quiescence == null ||
                validator == null ||
                journalStore == null)
            {
                return Result(
                    LegacyGuestMigrationRunStatus.Blocked,
                    "Required migration dependencies are unavailable.");
            }

            if (!TryValidateEnvironment(out string error))
                return Result(
                    LegacyGuestMigrationRunStatus.Blocked,
                    error);

            IDisposable lease;
            try
            {
                if (!quiescence.TryAcquire(out lease, out error) ||
                    lease == null)
                {
                    if (lease != null)
                        lease.Dispose();
                    return Result(
                        LegacyGuestMigrationRunStatus.Deferred,
                        error ?? "Cross-store migration quiescence was not acquired.");
                }
            }
            catch (Exception exception)
            {
                return Result(
                    LegacyGuestMigrationRunStatus.Deferred,
                    "Cross-store migration quiescence failed: " +
                    exception.Message);
            }

            using (lease)
            {
                return RunWhileQuiescent();
            }
        }

        private LegacyGuestMigrationRunResult RunWhileQuiescent()
        {
            if (!TryValidateEnvironment(out string error))
                return Result(
                    LegacyGuestMigrationRunStatus.Blocked,
                    error);

            if (!TryValidateJournalPath(out error))
                return Result(
                    LegacyGuestMigrationRunStatus.Blocked,
                    error);

            LegacyGuestMigrationJournalLoadResult loadResult;
            LegacyGuestMigrationJournal journal;
            try
            {
                loadResult = journalStore.Load(out journal, out error);
            }
            catch (Exception exception)
            {
                return Result(
                    LegacyGuestMigrationRunStatus.Blocked,
                    "Migration journal load failed: " + exception.Message);
            }

            if (loadResult == LegacyGuestMigrationJournalLoadResult.Failed)
                return Result(
                    LegacyGuestMigrationRunStatus.Blocked,
                    error ?? "Migration journal could not be read safely.");

            if (loadResult == LegacyGuestMigrationJournalLoadResult.Missing)
            {
                journal = CreateJournal();
                if (!Persist(journal, out error))
                    return Result(
                        LegacyGuestMigrationRunStatus.Blocked,
                        error);
            }
            else if (!LegacyGuestMigrationJournalValidator.TryValidate(
                         journal,
                         environment.Identity,
                         out error))
            {
                return Result(
                    LegacyGuestMigrationRunStatus.Blocked,
                    "Migration journal validation failed: " + error);
            }

            if (journal.phase == LegacyGuestMigrationPhase.Completed)
                return Result(
                    LegacyGuestMigrationRunStatus.AlreadyCompleted,
                    null);

            if (!TryGetPaths(
                    journal,
                    out string profilesRoot,
                    out string destination,
                    out error))
                return Result(
                    LegacyGuestMigrationRunStatus.Blocked,
                    error);

            if (!PrepareLaunch(journal, out error))
                return Result(
                    LegacyGuestMigrationRunStatus.Blocked,
                    error);

            if (journal.phase == LegacyGuestMigrationPhase.Promoted)
            {
                if (!VerifyPromotedDestination(
                        destination,
                        journal,
                        out error))
                    return Defer(
                        journal,
                        RecoveryRequiredReason,
                        error);

                if (!Transition(
                        journal,
                        LegacyGuestMigrationPhase.Completed,
                        null,
                        null,
                        out error))
                    return Result(
                        LegacyGuestMigrationRunStatus.Blocked,
                        error);

                return Result(LegacyGuestMigrationRunStatus.Completed, null);
            }

            if (journal.phase == LegacyGuestMigrationPhase.StagedVerified)
                return PromoteVerifiedStage(
                    profilesRoot,
                    destination,
                    journal);

            if (journal.phase == LegacyGuestMigrationPhase.Staging)
                return RecoverStaging(
                    profilesRoot,
                    destination,
                    journal);

            if (journal.phase == LegacyGuestMigrationPhase.Deferred)
                return ResumeDeferred(
                    profilesRoot,
                    destination,
                    journal);

            if (journal.phase == LegacyGuestMigrationPhase.Prepared)
                return BeginAttempt(
                    profilesRoot,
                    destination,
                    journal);

            return Result(
                LegacyGuestMigrationRunStatus.Blocked,
                "Migration journal is in an unsupported state.");
        }

        private LegacyGuestMigrationRunResult ResumeDeferred(
            string profilesRoot,
            string destination,
            LegacyGuestMigrationJournal journal)
        {
            if (!string.Equals(
                    journal.deferReason,
                    SourceChangedReason,
                    StringComparison.Ordinal))
                return Result(
                    LegacyGuestMigrationRunStatus.Deferred,
                    journal.deferReason);

            if (!TryCreateSourceInventory(
                    out LegacyGuestMigrationInventory current,
                    out string error))
                return Result(
                    LegacyGuestMigrationRunStatus.Deferred,
                    error);

            if (string.Equals(
                    journal.manifestHash,
                    current.ComputeManifestHash(),
                    StringComparison.Ordinal))
                return Result(
                    LegacyGuestMigrationRunStatus.Deferred,
                    "Source has not changed since the deferred attempt.");

            if (journal.attemptsThisLaunch >=
                LegacyGuestMigrationJournalValidator.MaximumAttemptsPerLaunch)
                return Result(
                    LegacyGuestMigrationRunStatus.Deferred,
                    AttemptLimitReason);

            return BeginAttempt(
                profilesRoot,
                destination,
                journal,
                current);
        }

        private LegacyGuestMigrationRunResult BeginAttempt(
            string profilesRoot,
            string destination,
            LegacyGuestMigrationJournal journal,
            LegacyGuestMigrationInventory inventory = null)
        {
            if (journal.attemptsThisLaunch >=
                LegacyGuestMigrationJournalValidator.MaximumAttemptsPerLaunch)
                return Defer(
                    journal,
                    AttemptLimitReason,
                    "The maximum migration attempts for this launch has been reached.");

            if (inventory == null &&
                !TryCreateSourceInventory(out inventory, out string inventoryError))
                return Defer(
                    journal,
                    RecoveryRequiredReason,
                    inventoryError);

            if (!ValidateSource(inventory, out string validationError))
                return Defer(
                    journal,
                    ValidationFailedReason,
                    validationError);

            string stagingDirectory = GetStagingDirectory(
                profilesRoot,
                journal,
                journal.cumulativeAttempts + 1);
            if (Directory.Exists(stagingDirectory) ||
                File.Exists(stagingDirectory))
            {
                return Defer(
                    journal,
                    RecoveryRequiredReason,
                    "A transaction staging path already exists; it was preserved.");
            }

            AddAttempt(journal, inventory, LegacyGuestMigrationAttemptOutcome.Started);
            SetManifest(journal, inventory);
            if (!Transition(
                    journal,
                    LegacyGuestMigrationPhase.Staging,
                    null,
                    null,
                    out string persistError))
                return Result(
                    LegacyGuestMigrationRunStatus.Blocked,
                    persistError);

            for (;;)
            {
                if (!TryEnsureSafePath(stagingDirectory, profilesRoot, out string pathError))
                    return Defer(
                        journal,
                        RecoveryRequiredReason,
                        pathError);

                try
                {
                    Directory.CreateDirectory(stagingDirectory);
                }
                catch (Exception exception)
                {
                    return Defer(
                        journal,
                        RecoveryRequiredReason,
                        "Could not create transaction staging directory: " +
                        exception.Message);
                }

                if (!WriteStage(
                        stagingDirectory,
                        inventory,
                        journal,
                        out string stageError))
                    return Defer(
                        journal,
                        RecoveryRequiredReason,
                        stageError);

                if (!TryCreateSourceInventory(
                        out LegacyGuestMigrationInventory afterCopy,
                        out string reInventoryError))
                    return Defer(
                        journal,
                        RecoveryRequiredReason,
                        reInventoryError);

                if (!inventory.HasSameManifest(afterCopy))
                {
                    MarkLastAttempt(
                        journal,
                        LegacyGuestMigrationAttemptOutcome.SourceChanged);
                    if (!Transition(
                            journal,
                            LegacyGuestMigrationPhase.Deferred,
                            "Source changed while staging.",
                            SourceChangedReason,
                            out persistError))
                        return Result(
                            LegacyGuestMigrationRunStatus.Blocked,
                            persistError);

                    if (journal.attemptsThisLaunch >=
                        LegacyGuestMigrationJournalValidator
                            .MaximumAttemptsPerLaunch)
                        return Result(
                            LegacyGuestMigrationRunStatus.Deferred,
                            "Source changed during all allowed attempts; migration was deferred.");

                    if (!TryCreateSourceInventory(
                            out inventory,
                            out reInventoryError))
                        return Defer(
                            journal,
                            RecoveryRequiredReason,
                            reInventoryError);
                    if (!ValidateSource(inventory, out validationError))
                        return Defer(
                            journal,
                            ValidationFailedReason,
                            validationError);

                    stagingDirectory = GetStagingDirectory(
                        profilesRoot,
                        journal,
                        journal.cumulativeAttempts + 1);
                    if (Directory.Exists(stagingDirectory) ||
                        File.Exists(stagingDirectory))
                        return Defer(
                            journal,
                            RecoveryRequiredReason,
                            "A retry staging path already exists; it was preserved.");

                    AddAttempt(
                        journal,
                        inventory,
                        LegacyGuestMigrationAttemptOutcome.Started);
                    SetManifest(journal, inventory);
                    if (!Transition(
                            journal,
                            LegacyGuestMigrationPhase.Staging,
                            null,
                            null,
                            out persistError))
                        return Result(
                            LegacyGuestMigrationRunStatus.Blocked,
                            persistError);
                    continue;
                }

                if (!VerifyStage(
                        stagingDirectory,
                        journal,
                        out stageError))
                    return Defer(
                        journal,
                        RecoveryRequiredReason,
                        stageError);
                if (!validator.ValidateStaged(
                        stagingDirectory,
                        journal.manifest,
                        out validationError))
                    return Defer(
                        journal,
                        ValidationFailedReason,
                        validationError);

                MarkLastAttempt(
                    journal,
                    LegacyGuestMigrationAttemptOutcome.Completed);
                if (!Transition(
                        journal,
                        LegacyGuestMigrationPhase.StagedVerified,
                        null,
                        null,
                        out persistError))
                    return Result(
                        LegacyGuestMigrationRunStatus.Blocked,
                        persistError);

                return PromoteVerifiedStage(
                    profilesRoot,
                    destination,
                    journal);
            }
        }

        private LegacyGuestMigrationRunResult RecoverStaging(
            string profilesRoot,
            string destination,
            LegacyGuestMigrationJournal journal)
        {
            if (!TryCreateSourceInventory(
                    out LegacyGuestMigrationInventory current,
                    out string error))
                return Defer(journal, RecoveryRequiredReason, error);

            string currentHash = current.ComputeManifestHash();
            if (!string.Equals(
                    currentHash,
                    journal.manifestHash,
                    StringComparison.Ordinal))
            {
                MarkLastAttempt(
                    journal,
                    LegacyGuestMigrationAttemptOutcome.SourceChanged);
                if (!Transition(
                        journal,
                        LegacyGuestMigrationPhase.Deferred,
                        "Source changed during recovery.",
                        SourceChangedReason,
                        out error))
                    return Result(
                        LegacyGuestMigrationRunStatus.Blocked,
                        error);

                if (journal.attemptsThisLaunch >=
                    LegacyGuestMigrationJournalValidator.MaximumAttemptsPerLaunch)
                    return Result(
                        LegacyGuestMigrationRunStatus.Deferred,
                        "Source changed during all allowed attempts; staging was preserved.");

                return BeginAttempt(
                    profilesRoot,
                    destination,
                    journal,
                    current);
            }

            string stagingDirectory = GetStagingDirectory(
                profilesRoot,
                journal,
                journal.cumulativeAttempts);
            if (!VerifyStage(
                    stagingDirectory,
                    journal,
                    out error) ||
                !validator.ValidateStaged(
                    stagingDirectory,
                    journal.manifest,
                    out error))
                return Defer(
                    journal,
                    RecoveryRequiredReason,
                    error ?? "Incomplete staging was preserved for recovery.");

            MarkLastAttempt(
                journal,
                LegacyGuestMigrationAttemptOutcome.Completed);
            if (!Transition(
                    journal,
                    LegacyGuestMigrationPhase.StagedVerified,
                    null,
                    null,
                    out error))
                return Result(
                    LegacyGuestMigrationRunStatus.Blocked,
                    error);

            return PromoteVerifiedStage(
                profilesRoot,
                destination,
                journal);
        }

        private LegacyGuestMigrationRunResult PromoteVerifiedStage(
            string profilesRoot,
            string destination,
            LegacyGuestMigrationJournal journal)
        {
            string stagingDirectory = GetStagingDirectory(
                profilesRoot,
                journal,
                journal.cumulativeAttempts);
            if (!TryCreateSourceInventory(
                    out LegacyGuestMigrationInventory sourceNow,
                    out string error))
                return Defer(journal, RecoveryRequiredReason, error);

            if (!string.Equals(
                    sourceNow.ComputeManifestHash(),
                    journal.manifestHash,
                    StringComparison.Ordinal))
            {
                if (journal.attemptHistory.Count > 0)
                    MarkLastAttempt(
                        journal,
                        LegacyGuestMigrationAttemptOutcome.SourceChanged);
                if (!Transition(
                        journal,
                        LegacyGuestMigrationPhase.Deferred,
                        "Source changed before promotion.",
                        SourceChangedReason,
                        out error))
                    return Result(
                        LegacyGuestMigrationRunStatus.Blocked,
                        error);
                if (journal.attemptsThisLaunch >=
                    LegacyGuestMigrationJournalValidator.MaximumAttemptsPerLaunch)
                    return Result(
                        LegacyGuestMigrationRunStatus.Deferred,
                        "Source changed before promotion; migration was deferred.");
                return BeginAttempt(
                    profilesRoot,
                    destination,
                    journal,
                    sourceNow);
            }

            if (!TryEnsureSafePath(destination, profilesRoot, out error))
                return Defer(
                    journal,
                    RecoveryRequiredReason,
                    error);

            if (Directory.Exists(destination) || File.Exists(destination))
            {
                if (!VerifyPromotedDestination(
                        destination,
                        journal,
                        out error))
                    return Defer(
                        journal,
                        DestinationConflictReason,
                        "A guest destination already exists and is not this verified transaction.");

                if (!validator.ValidateStaged(
                        destination,
                        journal.manifest,
                        out error))
                    return Defer(
                        journal,
                        ValidationFailedReason,
                        error);
            }
            else
            {
                if (!VerifyStage(
                        stagingDirectory,
                        journal,
                        out error) ||
                    !validator.ValidateStaged(
                        stagingDirectory,
                        journal.manifest,
                        out error))
                    return Defer(
                        journal,
                        RecoveryRequiredReason,
                        error ?? "Verified staging no longer matches the journal.");

                try
                {
                    Directory.Move(stagingDirectory, destination);
                }
                catch (IOException)
                {
                    if (!VerifyPromotedDestination(
                            destination,
                            journal,
                            out error))
                        return Defer(
                            journal,
                            DestinationConflictReason,
                            "Non-overwriting guest promotion failed; existing artifacts were preserved.");
                }
                catch (Exception exception)
                {
                    return Defer(
                        journal,
                        RecoveryRequiredReason,
                        "Guest profile promotion failed: " +
                        exception.Message);
                }
            }

            if (!VerifyPromotedDestination(
                    destination,
                    journal,
                    out error))
                return Defer(
                    journal,
                    RecoveryRequiredReason,
                    error);

            if (!Transition(
                    journal,
                    LegacyGuestMigrationPhase.Promoted,
                    null,
                    null,
                    out error))
                return Result(
                    LegacyGuestMigrationRunStatus.Blocked,
                    error);

            if (!Transition(
                    journal,
                    LegacyGuestMigrationPhase.Completed,
                    null,
                    null,
                    out error))
                return Result(
                    LegacyGuestMigrationRunStatus.Blocked,
                    error);

            return Result(
                LegacyGuestMigrationRunStatus.Completed,
                null);
        }

        private bool WriteStage(
            string stagingDirectory,
            LegacyGuestMigrationInventory inventory,
            LegacyGuestMigrationJournal journal,
            out string errorMessage)
        {
            errorMessage = null;
            try
            {
                foreach (LegacyGuestMigrationInventoryEntry entry in
                         inventory.Entries)
                {
                    string destination = ResolveContainedPath(
                        stagingDirectory,
                        entry.RelativePath);
                    string parent = Path.GetDirectoryName(destination);
                    if (!string.IsNullOrEmpty(parent))
                        Directory.CreateDirectory(parent);
                    if (!TryEnsureSafePath(
                            destination,
                            stagingDirectory,
                            out errorMessage))
                        return false;
                    WriteNewFlushed(destination, entry.CopyBytes());
                }

                LocalProfileOwnerMetadata owner =
                    CreateGuestOwnerMetadata();
                string ownerJson = JsonUtility.ToJson(owner, false);
                string ownerPath = ResolveContainedPath(
                    stagingDirectory,
                    OwnerFileName);
                if (!TryEnsureSafePath(
                        ownerPath,
                        stagingDirectory,
                        out errorMessage))
                    return false;
                WriteNewFlushed(
                    ownerPath,
                    StrictUtf8.GetBytes(ownerJson));

                var receipt = new LegacyGuestMigrationReceipt
                {
                    version = ReceiptVersion,
                    transactionId = journal.transactionId,
                    manifestHash = journal.manifestHash,
                    environmentMode = journal.environmentMode,
                    environmentRootFingerprint =
                        journal.environmentRootFingerprint
                };
                string receiptPath = ResolveContainedPath(
                    stagingDirectory,
                    ReceiptFileName);
                if (!TryEnsureSafePath(
                        receiptPath,
                        stagingDirectory,
                        out errorMessage))
                    return false;
                WriteNewFlushed(
                    receiptPath,
                    StrictUtf8.GetBytes(
                        JsonUtility.ToJson(receipt, false)));
                return true;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Migration staging failed; staged artifacts were preserved: " +
                    exception.Message;
                return false;
            }
        }

        private bool VerifyStage(
            string directory,
            LegacyGuestMigrationJournal journal,
            out string errorMessage)
        {
            return VerifyDirectoryContents(
                directory,
                journal,
                out errorMessage);
        }

        private bool VerifyPromotedDestination(
            string directory,
            LegacyGuestMigrationJournal journal,
            out string errorMessage)
        {
            return VerifyDirectoryContents(
                directory,
                journal,
                out errorMessage);
        }

        private bool VerifyDirectoryContents(
            string directory,
            LegacyGuestMigrationJournal journal,
            out string errorMessage)
        {
            errorMessage = null;
            if (!Directory.Exists(directory) ||
                !LegacyGuestMigrationInventory.IsSafeDirectoryTree(
                    directory,
                    Path.GetDirectoryName(directory),
                    out errorMessage))
            {
                if (string.IsNullOrEmpty(errorMessage))
                    errorMessage = "Migration directory is missing.";
                return false;
            }

            try
            {
                var expected = new HashSet<string>(
                    StringComparer.OrdinalIgnoreCase);
                foreach (LegacyGuestMigrationManifestEntry entry in
                         journal.manifest)
                {
                    string fullPath = ResolveContainedPath(
                        directory,
                        entry.relativePath);
                    if (!File.Exists(fullPath) ||
                        !LegacyGuestMigrationInventory
                            .TryEnsureNoReparsePointsInPath(
                                fullPath,
                                out errorMessage))
                        return false;

                    byte[] bytes = File.ReadAllBytes(fullPath);
                    if (bytes.LongLength != entry.byteLength ||
                        !string.Equals(
                            LegacyGuestMigrationInventory.ComputeSha256(bytes),
                            entry.sha256,
                            StringComparison.Ordinal))
                    {
                        errorMessage =
                            "Staged migration file differs from its manifest: " +
                            entry.relativePath;
                        return false;
                    }

                    expected.Add(entry.relativePath);
                }

                string ownerPath = Path.Combine(directory, OwnerFileName);
                string receiptPath = Path.Combine(directory, ReceiptFileName);
                if (!VerifyOwner(ownerPath, out errorMessage) ||
                    !VerifyReceipt(receiptPath, journal, out errorMessage))
                    return false;
                expected.Add(OwnerFileName);
                expected.Add(ReceiptFileName);

                var actual = new HashSet<string>(
                    StringComparer.OrdinalIgnoreCase);
                if (!CollectDirectoryFiles(
                        directory,
                        directory,
                        actual,
                        out errorMessage))
                    return false;

                return SetEquals(expected, actual, out errorMessage);
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Migration directory verification failed: " +
                    exception.Message;
                return false;
            }
        }

        private bool VerifyOwner(
            string ownerPath,
            out string errorMessage)
        {
            errorMessage = null;
            try
            {
                if (!LegacyGuestMigrationInventory
                        .TryEnsureNoReparsePointsInPath(
                            ownerPath,
                            out errorMessage))
                    return false;
                byte[] bytes = File.ReadAllBytes(ownerPath);
                LocalProfileOwnerMetadata metadata =
                    JsonUtility.FromJson<LocalProfileOwnerMetadata>(
                        StrictUtf8.GetString(bytes));
                if (!LocalProfileOwnerMetadataValidator.TryValidate(
                        metadata,
                        environment.Identity,
                        out LocalProfileIdentity identity,
                        out errorMessage) ||
                    identity.Kind != LocalProfileKind.Guest ||
                    !string.Equals(
                        identity.DirectoryKey,
                        LegacyGuestMigrationJournalValidator
                            .GuestDestinationKey,
                        StringComparison.Ordinal))
                {
                    if (string.IsNullOrEmpty(errorMessage))
                        errorMessage = "Staged guest owner metadata is invalid.";
                    return false;
                }

                return true;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Staged guest owner metadata could not be read: " +
                    exception.Message;
                return false;
            }
        }

        private bool VerifyReceipt(
            string receiptPath,
            LegacyGuestMigrationJournal journal,
            out string errorMessage)
        {
            errorMessage = null;
            try
            {
                if (!LegacyGuestMigrationInventory
                        .TryEnsureNoReparsePointsInPath(
                            receiptPath,
                            out errorMessage))
                    return false;
                LegacyGuestMigrationReceipt receipt =
                    JsonUtility.FromJson<LegacyGuestMigrationReceipt>(
                        StrictUtf8.GetString(
                            File.ReadAllBytes(receiptPath)));
                if (receipt == null ||
                    receipt.version != ReceiptVersion ||
                    !string.Equals(
                        receipt.transactionId,
                        journal.transactionId,
                        StringComparison.Ordinal) ||
                    !string.Equals(
                        receipt.manifestHash,
                        journal.manifestHash,
                        StringComparison.Ordinal) ||
                    !string.Equals(
                        receipt.environmentMode,
                        journal.environmentMode,
                        StringComparison.Ordinal) ||
                    !string.Equals(
                        receipt.environmentRootFingerprint,
                        journal.environmentRootFingerprint,
                        StringComparison.Ordinal))
                {
                    errorMessage =
                        "Migration receipt does not match the journal.";
                    return false;
                }

                return true;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Migration receipt could not be read: " +
                    exception.Message;
                return false;
            }
        }

        private bool CollectDirectoryFiles(
            string root,
            string current,
            HashSet<string> files,
            out string errorMessage)
        {
            errorMessage = null;
            foreach (string path in Directory.GetFileSystemEntries(
                         current,
                         "*",
                         SearchOption.TopDirectoryOnly))
            {
                if (!LegacyGuestMigrationInventory
                        .TryEnsureNoReparsePointsInPath(
                            path,
                            out errorMessage))
                    return false;

                FileAttributes attributes = File.GetAttributes(path);
                if ((attributes & FileAttributes.Directory) != 0)
                {
                    string name = Path.GetFileName(path);
                    if (!string.Equals(name, "CafeProfile", StringComparison.Ordinal) &&
                        !string.Equals(name, "TutorialProgress", StringComparison.Ordinal))
                    {
                        errorMessage =
                            "Unexpected directory in migration staging.";
                        return false;
                    }

                    if (!CollectDirectoryFiles(
                            root,
                            path,
                            files,
                            out errorMessage))
                        return false;
                    continue;
                }

                string relative = Path.GetRelativePath(root, path)
                    .Replace(Path.DirectorySeparatorChar, '/');
                if (!LegacyGuestMigrationInventory
                        .IsCanonicalRelativePath(relative) ||
                    !files.Add(relative))
                {
                    errorMessage =
                        "Migration directory contains an ambiguous path.";
                    return false;
                }
            }

            return true;
        }

        private bool TryCreateSourceInventory(
            out LegacyGuestMigrationInventory inventory,
            out string errorMessage)
        {
            if (!LegacyGuestMigrationInventory.TryCreate(
                    environment.EnvironmentRoot,
                    out inventory,
                    out errorMessage))
                return false;

            return true;
        }

        private bool ValidateSource(
            LegacyGuestMigrationInventory inventory,
            out string errorMessage)
        {
            try
            {
                return validator.ValidateSource(
                    inventory,
                    out errorMessage);
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Non-mutating source validation failed: " +
                    exception.Message;
                return false;
            }
        }

        private bool TryValidateEnvironment(out string errorMessage)
        {
            errorMessage = null;
            if (environment.Identity == null ||
                !Guid.TryParseExact(
                    environment.LaunchId,
                    "N",
                    out Guid launchId) ||
                !string.Equals(
                    environment.LaunchId,
                    launchId.ToString("N"),
                    StringComparison.Ordinal))
            {
                errorMessage =
                    "Migration environment or launch identity is invalid.";
                return false;
            }

            try
            {
                string fingerprint =
                    LocalProfilePathLayout.ComputeEnvironmentRootFingerprint(
                        environment.Identity.Mode,
                        environment.EnvironmentRoot);
                if (!string.Equals(
                        fingerprint,
                        environment.Identity.RootFingerprint,
                        StringComparison.Ordinal))
                {
                    errorMessage =
                        "Migration environment root does not match its identity.";
                    return false;
                }

                return LegacyGuestMigrationInventory
                    .TryEnsureNoReparsePointsInPath(
                        environment.EnvironmentRoot,
                        out errorMessage);
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Migration environment could not be validated: " +
                    exception.Message;
                return false;
            }
        }

        private LegacyGuestMigrationJournal CreateJournal()
        {
            LocalProfileIdentity guest =
                LocalProfileIdentity.CreateGuest(environment.Identity);
            return new LegacyGuestMigrationJournal
            {
                version = LegacyGuestMigrationJournalValidator.CurrentVersion,
                transactionId = Guid.NewGuid().ToString("N"),
                phase = LegacyGuestMigrationPhase.Prepared,
                environmentMode = environment.Identity.Mode,
                environmentRootFingerprint =
                    environment.Identity.RootFingerprint,
                sourceKey =
                    LegacyGuestMigrationJournalValidator.LegacyRootSourceKey,
                destinationKey =
                    LegacyGuestMigrationJournalValidator.GuestDestinationKey,
                ownerProfileKey = guest.DirectoryKey,
                ownerPlayerId = null,
                ownerKind = LocalProfileKind.Guest,
                ownerEnvironmentMode = environment.Identity.Mode,
                ownerEnvironmentRootFingerprint =
                    environment.Identity.RootFingerprint,
                launchId = environment.LaunchId,
                attemptsThisLaunch = 0,
                cumulativeAttempts = 0,
                manifest = new List<LegacyGuestMigrationManifestEntry>(),
                manifestHash =
                    LegacyGuestMigrationJournalValidator.ComputeManifestHash(
                        new List<LegacyGuestMigrationManifestEntry>()),
                attemptHistory = new List<LegacyGuestMigrationAttempt>()
            };
        }

        private bool PrepareLaunch(
            LegacyGuestMigrationJournal journal,
            out string errorMessage)
        {
            errorMessage = null;
            if (string.Equals(
                    journal.launchId,
                    environment.LaunchId,
                    StringComparison.Ordinal))
                return true;

            LegacyGuestMigrationJournal previous = Clone(journal);
            journal.launchId = environment.LaunchId;
            journal.attemptsThisLaunch = 0;
            if (!LegacyGuestMigrationJournalValidator.TryValidateTransition(
                    previous,
                    journal,
                    environment.Identity,
                    out errorMessage))
                return false;
            return Persist(journal, out errorMessage);
        }

        private bool Transition(
            LegacyGuestMigrationJournal journal,
            LegacyGuestMigrationPhase nextPhase,
            string failureReason,
            string deferReason,
            out string errorMessage)
        {
            LegacyGuestMigrationJournal previous = Clone(journal);
            journal.phase = nextPhase;
            journal.failureReason = LimitReason(failureReason);
            journal.deferReason = LimitReason(deferReason);
            if (!LegacyGuestMigrationJournalValidator.TryValidateTransition(
                    previous,
                    journal,
                    environment.Identity,
                    out errorMessage))
            {
                CopyJournal(previous, journal);
                return false;
            }

            if (!Persist(journal, out errorMessage))
            {
                CopyJournal(previous, journal);
                return false;
            }

            return true;
        }

        private LegacyGuestMigrationRunResult Defer(
            LegacyGuestMigrationJournal journal,
            string reasonCode,
            string detail)
        {
            string reason = LimitReason(reasonCode + ": " +
                (detail ?? "Migration was deferred."));
            if (journal.phase == LegacyGuestMigrationPhase.Completed)
                return Result(
                    LegacyGuestMigrationRunStatus.Blocked,
                    "Completed migration cannot be deferred.");

            if (journal.phase == LegacyGuestMigrationPhase.Deferred)
            {
                journal.deferReason = reason;
                if (!Persist(journal, out string persistError))
                    return Result(
                        LegacyGuestMigrationRunStatus.Blocked,
                        persistError);
            }
            else
            {
                if (!string.Equals(
                        reasonCode,
                        SourceChangedReason,
                        StringComparison.Ordinal))
                    MarkLastAttempt(
                        journal,
                        LegacyGuestMigrationAttemptOutcome.Deferred);

                if (!Transition(
                        journal,
                        LegacyGuestMigrationPhase.Deferred,
                        detail,
                        reason,
                        out string error))
                    return Result(
                        LegacyGuestMigrationRunStatus.Blocked,
                        error);
            }

            return Result(
                LegacyGuestMigrationRunStatus.Deferred,
                reason);
        }

        private bool Persist(
            LegacyGuestMigrationJournal journal,
            out string errorMessage)
        {
            errorMessage = null;
            if (!LegacyGuestMigrationJournalValidator.TryValidate(
                    journal,
                    environment.Identity,
                    out errorMessage))
                return false;

            try
            {
                return journalStore.SaveDurably(
                    journal,
                    out errorMessage);
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Durable migration journal write failed: " +
                    exception.Message;
                return false;
            }
        }

        private bool TryGetPaths(
            LegacyGuestMigrationJournal journal,
            out string profilesRoot,
            out string destination,
            out string errorMessage)
        {
            profilesRoot = null;
            destination = null;
            errorMessage = null;
            try
            {
                profilesRoot =
                    LocalProfilePathLayout.GetIdentityProfilesDirectory(
                        environment.EnvironmentRoot,
                        environment.Identity);
                LocalProfileIdentity guest =
                    LocalProfileIdentity.CreateGuest(environment.Identity);
                destination =
                    LocalProfilePathLayout.GetProfileDirectory(
                        environment.EnvironmentRoot,
                        guest);

                if (!LegacyGuestMigrationInventory.IsContained(
                        environment.EnvironmentRoot,
                        profilesRoot) ||
                    !LegacyGuestMigrationInventory.IsContained(
                        profilesRoot,
                        destination) ||
                    !string.Equals(
                        journal.destinationKey,
                        guest.DirectoryKey,
                        StringComparison.Ordinal))
                {
                    errorMessage =
                        "Migration destination escaped the validated guest profile root.";
                    return false;
                }

                if (!LegacyGuestMigrationInventory
                        .TryEnsureNoReparsePointsInPath(
                            profilesRoot,
                            out errorMessage))
                    return false;

                return true;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Migration paths could not be validated: " +
                    exception.Message;
                return false;
            }
        }

        private bool TryValidateJournalPath(out string errorMessage)
        {
            errorMessage = null;
            try
            {
                string expectedPath = Path.GetFullPath(Path.Combine(
                    environment.EnvironmentRoot,
                    JournalDirectoryName,
                    JournalFileName));
                string providedPath = Path.GetFullPath(
                    journalStore.JournalPath);
                if (!PathEquals(expectedPath, providedPath) ||
                    !LegacyGuestMigrationInventory.IsContained(
                        environment.EnvironmentRoot,
                        providedPath) ||
                    !LegacyGuestMigrationInventory
                        .TryEnsureNoReparsePointsInPath(
                            providedPath,
                            out errorMessage))
                {
                    if (string.IsNullOrEmpty(errorMessage))
                        errorMessage =
                            "Migration journal must use its dedicated environment-root path.";
                    return false;
                }

                return true;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Migration journal path could not be validated: " +
                    exception.Message;
                return false;
            }
        }

        private static bool PathEquals(string left, string right)
        {
#if UNITY_EDITOR_WIN || UNITY_STANDALONE_WIN || UNITY_WSA
            return string.Equals(
                left,
                right,
                StringComparison.OrdinalIgnoreCase);
#else
            return string.Equals(
                left,
                right,
                StringComparison.Ordinal);
#endif
        }

        private bool TryEnsureSafePath(
            string path,
            string parent,
            out string errorMessage)
        {
            return LegacyGuestMigrationInventory.IsSafeDirectoryTree(
                path,
                parent,
                out errorMessage);
        }

        private string GetStagingDirectory(
            string profilesRoot,
            LegacyGuestMigrationJournal journal,
            int attemptOrdinal)
        {
            return Path.Combine(
                profilesRoot,
                ".legacy-guest-" + journal.transactionId +
                "-attempt-" + attemptOrdinal.ToString("D6"));
        }

        private LocalProfileOwnerMetadata CreateGuestOwnerMetadata()
        {
            return new LocalProfileOwnerMetadata
            {
                version = LocalProfileOwnerMetadataValidator.CurrentVersion,
                kind = LocalProfileKind.Guest,
                playerId = null,
                environmentMode = environment.Identity.Mode,
                environmentRootFingerprint =
                    environment.Identity.RootFingerprint,
                profileKey =
                    LegacyGuestMigrationJournalValidator.GuestDestinationKey
            };
        }

        private static void SetManifest(
            LegacyGuestMigrationJournal journal,
            LegacyGuestMigrationInventory inventory)
        {
            journal.manifest = inventory.CreateManifest();
            journal.manifestHash = inventory.ComputeManifestHash();
        }

        private static void AddAttempt(
            LegacyGuestMigrationJournal journal,
            LegacyGuestMigrationInventory inventory,
            LegacyGuestMigrationAttemptOutcome outcome)
        {
            int launchAttemptNumber = journal.attemptsThisLaunch + 1;
            journal.attemptsThisLaunch = launchAttemptNumber;
            journal.cumulativeAttempts++;
            journal.attemptHistory.Add(
                new LegacyGuestMigrationAttempt
                {
                    attemptNumber = launchAttemptNumber,
                    launchId = journal.launchId,
                    sourceManifestHash = inventory.ComputeManifestHash(),
                    outcome = outcome
                });
        }

        private static void MarkLastAttempt(
            LegacyGuestMigrationJournal journal,
            LegacyGuestMigrationAttemptOutcome outcome)
        {
            if (journal.attemptHistory.Count == 0)
                return;
            journal.attemptHistory[
                journal.attemptHistory.Count - 1].outcome = outcome;
        }

        private static string ResolveContainedPath(
            string root,
            string relativePath)
        {
            if (!LegacyGuestMigrationInventory
                    .IsCanonicalRelativePath(relativePath))
                throw new ArgumentException(
                    "Migration relative path is invalid.",
                    nameof(relativePath));

            string path = Path.GetFullPath(Path.Combine(
                root,
                relativePath.Replace(
                    '/',
                    Path.DirectorySeparatorChar)));
            if (!LegacyGuestMigrationInventory.IsContained(root, path) ||
                string.Equals(
                    Path.GetFullPath(root),
                    path,
                    StringComparison.Ordinal))
                throw new IOException(
                    "Migration path escapes its approved directory.");
            return path;
        }

        private static bool SetEquals(
            HashSet<string> expected,
            HashSet<string> actual,
            out string errorMessage)
        {
            errorMessage = null;
            if (expected.SetEquals(actual))
                return true;

            errorMessage =
                "Migration directory has missing or unrecognized files.";
            return false;
        }

        private static void WriteNewFlushed(string path, byte[] bytes)
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

        private static LegacyGuestMigrationJournal Clone(
            LegacyGuestMigrationJournal source)
        {
            string json = JsonUtility.ToJson(source, false);
            return JsonUtility.FromJson<LegacyGuestMigrationJournal>(json);
        }

        private static void CopyJournal(
            LegacyGuestMigrationJournal source,
            LegacyGuestMigrationJournal destination)
        {
            destination.version = source.version;
            destination.transactionId = source.transactionId;
            destination.phase = source.phase;
            destination.environmentMode = source.environmentMode;
            destination.environmentRootFingerprint =
                source.environmentRootFingerprint;
            destination.sourceKey = source.sourceKey;
            destination.destinationKey = source.destinationKey;
            destination.ownerProfileKey = source.ownerProfileKey;
            destination.ownerPlayerId = source.ownerPlayerId;
            destination.ownerKind = source.ownerKind;
            destination.ownerEnvironmentMode =
                source.ownerEnvironmentMode;
            destination.ownerEnvironmentRootFingerprint =
                source.ownerEnvironmentRootFingerprint;
            destination.launchId = source.launchId;
            destination.manifestHash = source.manifestHash;
            destination.attemptsThisLaunch =
                source.attemptsThisLaunch;
            destination.cumulativeAttempts =
                source.cumulativeAttempts;
            destination.manifest = source.manifest;
            destination.attemptHistory = source.attemptHistory;
            destination.failureReason = source.failureReason;
            destination.deferReason = source.deferReason;
        }

        private static LegacyGuestMigrationRunResult Result(
            LegacyGuestMigrationRunStatus status,
            string message)
        {
            return new LegacyGuestMigrationRunResult(status, message);
        }

        private static string LimitReason(string value)
        {
            const int MaximumReasonLength = 2048;
            if (value == null || value.Length <= MaximumReasonLength)
                return value;
            return value.Substring(0, MaximumReasonLength);
        }
    }
}
