// Inactive descriptive contract; assigning a value grants no ownership.
// SaveManager is the intended persistent publication owner in every bound case.
// Future enforcement must check the actual owner/dependency instances and exact
// candidate reference. Source/readiness flags and enum values are not credentials.
internal enum SessionPublicationOwnership
{
    None = 0,

    // Publication remains bound to the current authorized live controller.
    LiveControllerBound = 1,

    // Successful explicit departure retains the SAME publication under its
    // persistent owner. It does not assert that this is the latest live state.
    ReleasedSnapshotBound = 2,

    // Private staging bound to one transaction; never ordinary publication.
    TransactionBound = 3
}