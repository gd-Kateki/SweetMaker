public sealed class SaveDiscoveryResult
{
    public SaveFileInspection Primary { get; }
    public SaveFileInspection Backup { get; }

    internal SaveDiscoveryResult(
        SaveFileInspection primary,
        SaveFileInspection backup)
    {
        Primary = primary;
        Backup = backup;
    }
}
