// Stores supplied metadata only; does not validate it or grant save authority.
internal sealed class FrozenSaveRootMetadata
{
    public int CustomerCapacity { get; }
    public string SelectedSpawnPoolId { get; }
    public int LuckLevel { get; }
    public int ServingPlateProgressionVersion { get; }
    public FrozenEnergyMetadata Energy { get; }

    public FrozenSaveRootMetadata(
        int customerCapacity,
        string selectedSpawnPoolId,
        int luckLevel,
        int servingPlateProgressionVersion,
        FrozenEnergyMetadata energy)
    {
        CustomerCapacity = customerCapacity;
        SelectedSpawnPoolId = selectedSpawnPoolId;
        LuckLevel = luckLevel;
        ServingPlateProgressionVersion = servingPlateProgressionVersion;
        Energy = energy;
    }
}
