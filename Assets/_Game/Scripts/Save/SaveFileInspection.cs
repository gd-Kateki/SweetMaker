public sealed class SaveFileInspection
{
    private readonly byte[] capturedBytes;

    public string FilePath { get; }
    public SaveDiscoveryStatus Status { get; }
    public SaveDiscoveryVersionKind VersionKind { get; }
    public int? SaveVersion { get; }
    public string FailureReason { get; }
    public bool HasCapturedBytes => capturedBytes != null;

    public byte[] CapturedBytes =>
        capturedBytes == null
            ? null
            : (byte[])capturedBytes.Clone();

    internal SaveFileInspection(
        string filePath,
        SaveDiscoveryStatus status,
        SaveDiscoveryVersionKind versionKind,
        int? saveVersion,
        byte[] capturedBytes,
        string failureReason)
    {
        FilePath = filePath;
        Status = status;
        VersionKind = versionKind;
        SaveVersion = saveVersion;
        this.capturedBytes = capturedBytes == null
            ? null
            : (byte[])capturedBytes.Clone();
        FailureReason = failureReason;
    }
}
