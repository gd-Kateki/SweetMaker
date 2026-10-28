// Inactive metadata only; does not observe, advance, or validate Energy.
internal sealed class FrozenEnergyMetadata
{
    public int CurrentEnergy { get; }
    public int MillisecondsUntilNextPoint { get; }
    public long SavedUtcTicks { get; }

    public FrozenEnergyMetadata(
        int currentEnergy,
        int millisecondsUntilNextPoint,
        long savedUtcTicks)
    {
        CurrentEnergy = currentEnergy;
        MillisecondsUntilNextPoint = millisecondsUntilNextPoint;
        SavedUtcTicks = savedUtcTicks;
    }
}
