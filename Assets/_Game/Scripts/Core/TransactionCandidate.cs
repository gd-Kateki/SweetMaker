// Inactive descriptor for a future detached Save V2/RNG pair, not the payload.
// Stores supplied metadata only; it captures no live state, computes no hashes,
// validates no pairing, and grants no authority to publish or persist anything.
public sealed class TransactionCandidate
{
    public TransactionIdentity Identity { get; }

    // Opaque content-hash descriptors. Hash format and verification are deferred.
    public string SaveV2ContentHash { get; }
    public string RngContentHash { get; }

    public TransactionCandidate(
        TransactionIdentity identity,
        string saveV2ContentHash,
        string rngContentHash)
    {
        Identity = identity;
        SaveV2ContentHash = saveV2ContentHash;
        RngContentHash = rngContentHash;
    }
}
