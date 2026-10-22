using System;
using UnityEngine;

[Serializable]
public sealed class RebirthProgressionState
{
    private const int MaximumRebirthCount = 10;

    private static readonly int[] RequiredTiers =
    {
        7, 8, 11, 12, 15, 16, 19, 20, 24, 25
    };

    private static readonly int[] RequiredCash =
    {
        128, 278, 320, 1070, 960, 3960, 2880, 14880, 8000, 58000
    };

    [SerializeField, Range(0, MaximumRebirthCount)]
    private int currentRebirthCount;

    [SerializeField, Range(0, 30)]
    private int highestTierCreatedThisRun;

    [SerializeField]
    private bool campaignComplete;

    public int CurrentRebirthCount =>
        Mathf.Clamp(currentRebirthCount, 0, MaximumRebirthCount);

    public int RebirthUnlockedOvenLevel =>
        GetOvenLevelForRebirthCount(CurrentRebirthCount);

    public int HighestTierCreatedThisRun =>
        Mathf.Clamp(highestTierCreatedThisRun, 0, 30);

    public bool CampaignComplete =>
        campaignComplete;

    public bool HasNextRebirth =>
        CurrentRebirthCount < MaximumRebirthCount;

    public int NextRebirthNumber =>
        HasNextRebirth ? CurrentRebirthCount + 1 : 0;

    public int NextRequiredTier =>
        HasNextRebirth
            ? RequiredTiers[CurrentRebirthCount]
            : 0;

    public int NextRequiredCash =>
        HasNextRebirth
            ? RequiredCash[CurrentRebirthCount]
            : 0;

    public int NextOvenLevelUnlock =>
        HasNextRebirth && NextRebirthNumber % 2 == 0
            ? NextRebirthNumber / 2 + 1
            : 0;

    public RebirthProgressionState()
    {
    }

    public RebirthProgressionState(
        int initialRebirthCount,
        int initialHighestTierCreatedThisRun = 0)
    {
        currentRebirthCount =
            Mathf.Clamp(initialRebirthCount, 0, MaximumRebirthCount);
        highestTierCreatedThisRun =
            Mathf.Clamp(initialHighestTierCreatedThisRun, 0, 30);
    }

    public bool RegisterCreatedTier(int tier)
    {
        if (tier < 1 || tier > 30 ||
            tier <= highestTierCreatedThisRun)
        {
            return false;
        }

        highestTierCreatedThisRun = tier;
        if (CurrentRebirthCount == MaximumRebirthCount && tier == 30)
            campaignComplete = true;
        return true;
    }

    public bool Restore(
        int completedRebirthCount,
        int restoredHighestTierCreatedThisRun,
        bool restoredCampaignComplete)
    {
        if (completedRebirthCount < 0 ||
            completedRebirthCount > MaximumRebirthCount ||
            restoredHighestTierCreatedThisRun < 0 ||
            restoredHighestTierCreatedThisRun > 30 ||
            restoredCampaignComplete !=
                (completedRebirthCount == MaximumRebirthCount &&
                 restoredHighestTierCreatedThisRun == 30))
        {
            return false;
        }

        currentRebirthCount = completedRebirthCount;
        highestTierCreatedThisRun = restoredHighestTierCreatedThisRun;
        campaignComplete = restoredCampaignComplete;
        return true;
    }

    public bool CanRebirth(int cashHeld)
    {
        return HasNextRebirth &&
               HighestTierCreatedThisRun >= NextRequiredTier &&
               cashHeld >= NextRequiredCash;
    }

    public static int GetOvenLevelForRebirthCount(int rebirthCount)
    {
        return Mathf.Clamp(rebirthCount, 0, MaximumRebirthCount) / 2 + 1;
    }

    internal bool TryCommitRebirth(int cashHeld)
    {
        if (!CanRebirth(cashHeld))
            return false;

        currentRebirthCount++;
        highestTierCreatedThisRun = 0;
        return true;
    }
}
