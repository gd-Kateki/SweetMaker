// Descriptive states only; no value authorizes construction, use or persistence.
// A future owner must separately enforce identity, evidence and lifecycle rules.
// Unknown enum values must never be interpreted as eligible.
internal enum SessionPublicationEligibility
{
    Unavailable = 0,

    // Private transaction staging, unavailable to ordinary snapshot consumers.
    StagedTransaction = 1,

    // Describes the owner's exact current eligible candidate, not necessarily
    // the latest live gameplay. An enum comparison is not an identity check.
    ActivePublication = 2,

    // Retained immutable candidate references no longer confer eligibility.
    Revoked = 3
}