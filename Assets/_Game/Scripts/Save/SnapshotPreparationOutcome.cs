// Preparation results only; no value grants commit or persistence authority.
internal enum SnapshotPreparationOutcome
{
    Unknown = 0,
    Prepared = 1,
    InvalidCandidate = 2,
    CaptureUnavailable = 3,
    SerializationFailed = 4,
    ValidationFailed = 5,
    UnexpectedFailure = 6
}
