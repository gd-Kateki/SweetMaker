// Inactive identity descriptor only. Supplied values do not prove authentication,
// ownership, session validity, or permission to mutate or commit a save.
// A future trusted authentication/session boundary must establish those guarantees.
public sealed class TransactionIdentity
{
    public string OperationId { get; }
    public string Uid { get; }
    public string Environment { get; }
    public long SessionGeneration { get; }

    // Opaque expected-authority token; its format and validation are deferred.
    public string ExpectedAuthority { get; }

    public TransactionIdentity(
        string operationId,
        string uid,
        string environment,
        long sessionGeneration,
        string expectedAuthority)
    {
        OperationId = operationId;
        Uid = uid;
        Environment = environment;
        SessionGeneration = sessionGeneration;
        ExpectedAuthority = expectedAuthority;
    }
}
