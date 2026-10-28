// Future evidence-based commit classification. Do not infer this from SaveManager bool results.
public enum LocalCommitOutcome
{
    Unknown = 0,
    Committed = 1,
    NotCommitted = 2,
    CommitUncertain = 3,
    Rejected = 4
}
