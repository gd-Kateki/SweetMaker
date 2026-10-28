// Inactive reason vocabulary; assigning a reason performs no revocation.
// Future integration must revoke before mutation and reject retained references.
// A successful rollback needs revalidation and a new publication identity.
internal enum SessionPublicationRevocationReason
{
    None = 0,
    Superseded = 1,
    SessionReplaced = 2,
    SessionCleared = 3,
    RestorationStarted = 4,
    RestorationFailed = 5,
    PersistentReloadStarted = 6,
    TransactionStarted = 7,
    TransactionAbandoned = 8,
    RollbackStarted = 9,
    RollbackFailed = 10,

    // Except where explicit departure already transferred the same publication.
    ControllerUnavailable = 11,
    OwnerOrDependencyDestroyed = 12,
    DevelopmentReset = 13
}