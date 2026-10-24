using System;

public static class GameplayEvents
{
    public static event Action<int>
        DessertSpawned;

    public static event Action
        DessertMoved;

    public static event Action<int>
        DessertMerged;

    public static event Action<int, bool>
        DessertMergeCommitted;

    public static event Action
        CampaignCompleted;

    public static event Action<DessertDefinition>
        NextDessertChanged;

    public static void RaiseDessertSpawned(
        int tier)
    {
        DessertSpawned?.Invoke(
            tier
        );
    }

    public static void RaiseDessertMoved()
    {
        DessertMoved?.Invoke();
    }

    public static void RaiseDessertMerged(
        int resultingTier)
    {
        DessertMerged?.Invoke(
            resultingTier
        );
    }

    public static void RaiseDessertMergeCommitted(
        int resultingTier,
        bool isNewHighestTier)
    {
        DessertMerged?.Invoke(
            resultingTier
        );
        DessertMergeCommitted?.Invoke(
            resultingTier,
            isNewHighestTier
        );
    }

    public static void RaiseCampaignCompleted()
    {
        CampaignCompleted?.Invoke();
    }

    internal static bool IsNewHighestTier(
        int resultingTier,
        int highestTierCreatedEarlier)
    {
        return resultingTier > highestTierCreatedEarlier;
    }

    public static void RaiseNextDessertChanged(
        DessertDefinition definition)
    {
        NextDessertChanged?.Invoke(
            definition
        );
    }
}