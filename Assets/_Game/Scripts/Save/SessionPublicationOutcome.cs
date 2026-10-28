// Inactive result vocabulary, distinct from SnapshotPreparationOutcome.
// Neither success labels nor failure labels grant authority or perform actions.
// Unknown means no conclusion, including no conclusion about disk commitment.
internal enum SessionPublicationOutcome
{
    Unknown = 0,
    Rejected = 1,
    Staged = 2,
    Published = 3,
    Revoked = 4,

    // Known failure before disk commitment; does not itself authorize rollback.
    FailedBeforeCommit = 5,
    CommittedAndFinalized = 6,

    // Disk commitment occurred; must not be treated as a pre-commit failure
    // or automatic permission to roll back because a later callback failed.
    CommittedFinalizationIncomplete = 7,

    // Commitment cannot be established; do not assume that nothing was written.
    CommitStateUnknown = 8
}

// Diagnostic categories only. None does not imply success or verified evidence.
internal enum SessionPublicationFailure
{
    None = 0,
    OwnerUnavailable = 1,
    UnauthorizedSource = 2,
    IneligibleLifecycle = 3,
    CaptureUnavailable = 4,
    InvalidFrozenValues = 5,
    CapacityEvidenceUnavailable = 6,
    CapacityEvidenceMismatch = 7,
    PublicationIdentityMismatch = 8,
    TransactionMismatch = 9,
    RestorationIncomplete = 10,
    MigrationIncomplete = 11,
    NoSessionMismatch = 12,
    Revoked = 13,
    CommitFailed = 14,
    FinalizationFailed = 15,
    RollbackFailed = 16,
    UnexpectedFailure = 17
}