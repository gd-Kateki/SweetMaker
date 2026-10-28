// Categories only, NOT evidence objects or authority tokens. No capacity is
// accepted or established here. A future verifier must bind independently
// established capacity to the exact frozen values and authorized source.
// Order count, index coverage, readiness and fingerprint equality cannot alone
// establish provenance. Loaded success alone cannot authorize publication.
internal enum SessionCapacityEvidenceKind
{
    None = 0,

    // Authorized controller validates actual slots and progression during
    // the same complete, nonrepairing capture.
    Live = 1,

    // Validated byte metadata bound to the exact detached loaded snapshot;
    // requires completed restoration checks before ordinary publication.
    Loaded = 2,

    // Independently verified capacity bound to one prepared transaction and
    // its exact staged values; cannot be reused for ordinary live publication.
    TransactionBound = 3
}
// No-session requires an explicit verified absent-session path with capacity
// zero and empty collections. Legacy capacity requires explicit migration
// evidence and completed retirement/restoration; neither is inferred here.