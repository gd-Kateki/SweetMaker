// Inactive lifecycle vocabulary; no transition rules or runtime gate are implemented.
public enum GameplayTransactionState
{
    None = 0,
    Admission = 1,
    Preparation = 2,
    Checkpoint = 3,
    Publication = 4,
    Completed = 5,
    Failed = 6
}
