// Gameplay completion is distinct from local commit completion.
public enum GameplayTransactionOutcome
{
    Unknown = 0,
    Success = 1,
    Rejected = 2,
    RecoveryRequired = 3
}
