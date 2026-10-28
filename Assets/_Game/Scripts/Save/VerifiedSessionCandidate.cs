// Inactive contract: deliberately has no factory or accessible constructor.
// A future controlled creation path must establish strict freezing, authorized
// publication and matching capacity provenance before invoking this constructor.
// An order count or purchased capacity is not verification evidence.
// The published candidate object itself is its identity; no generation counter.
internal sealed class VerifiedSessionCandidate
{
    public FrozenMergeSessionValues Session { get; }
    public int CustomerCapacity { get; }

    private VerifiedSessionCandidate(
        FrozenMergeSessionValues session,
        int customerCapacity)
    {
        Session = session;
        CustomerCapacity = customerCapacity;
    }
}
