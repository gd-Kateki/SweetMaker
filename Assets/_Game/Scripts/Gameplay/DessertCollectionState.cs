using System;
using System.Collections.Generic;

public enum DessertDiscoveryRecordResult
{
    Added,
    AlreadyDiscovered,
    InvalidTier
}

public sealed class DessertCollectionState
{
    public const int InitialTierCount =
        DessertCatalog.InitialTierCount;

    private static readonly int[] MilestoneRequirements =
    {
        6, 12, 18, 24, 30
    };

    private static readonly int[] MilestoneCashAmounts =
    {
        100, 300, 750, 1500, 3500
    };

    private readonly HashSet<int> discoveredTierIds =
        new HashSet<int>();

    private readonly HashSet<int> claimedMilestoneIds =
        new HashSet<int>();

    public int DiscoveredCount =>
        discoveredTierIds.Count;

    public int TotalCount =>
        InitialTierCount;

    public float CompletionPercentage =>
        DiscoveredCount * 100f / InitialTierCount;

    public static int MilestoneCount =>
        MilestoneRequirements.Length;

    public bool IsDiscovered(int tierId)
    {
        ValidateTierId(tierId);
        return discoveredTierIds.Contains(tierId);
    }

    public DessertDiscoveryRecordResult RecordDiscovery(int tierId)
    {
        if (!IsValidTierId(tierId))
            return DessertDiscoveryRecordResult.InvalidTier;

        return discoveredTierIds.Add(tierId)
            ? DessertDiscoveryRecordResult.Added
            : DessertDiscoveryRecordResult.AlreadyDiscovered;
    }

    public int GetMilestoneRequirement(int milestoneId)
    {
        return MilestoneRequirements[
            GetMilestoneIndex(milestoneId)];
    }

    public int GetMilestoneCashAmount(int milestoneId)
    {
        return MilestoneCashAmounts[
            GetMilestoneIndex(milestoneId)];
    }

    public bool IsMilestoneEligible(int milestoneId)
    {
        return DiscoveredCount >=
               GetMilestoneRequirement(milestoneId);
    }

    public bool IsMilestoneClaimed(int milestoneId)
    {
        GetMilestoneIndex(milestoneId);
        return claimedMilestoneIds.Contains(milestoneId);
    }

    public static int GetMilestoneIdAtIndex(int index)
    {
        if (index < 0 ||
            index >= MilestoneRequirements.Length)
        {
            throw new ArgumentOutOfRangeException(nameof(index));
        }

        return index + 1;
    }

    internal bool TryRestore(
        DessertCollectionSaveData saveData,
        out string failureReason)
    {
        failureReason = null;
        if (!TryValidateSaveData(saveData, out failureReason))
            return false;

        var restoredDiscovered =
            new HashSet<int>(saveData.discoveredTierIds);
        var restoredClaimed =
            new HashSet<int>(saveData.claimedMilestoneIds);

        discoveredTierIds.Clear();
        discoveredTierIds.UnionWith(restoredDiscovered);
        claimedMilestoneIds.Clear();
        claimedMilestoneIds.UnionWith(restoredClaimed);
        return true;
    }

    internal bool TryMarkMilestoneClaimedAfterPayment(
        int milestoneId)
    {
        int index;
        try
        {
            index = GetMilestoneIndex(milestoneId);
        }
        catch (ArgumentOutOfRangeException)
        {
            return false;
        }

        return DiscoveredCount >= MilestoneRequirements[index] &&
               claimedMilestoneIds.Add(milestoneId);
    }

    internal void CaptureTo(DessertCollectionSaveData saveData)
    {
        if (saveData == null)
            throw new ArgumentNullException(nameof(saveData));

        saveData.discoveredTierIds.Clear();
        foreach (int tierId in discoveredTierIds)
            saveData.discoveredTierIds.Add(tierId);
        saveData.discoveredTierIds.Sort();

        saveData.claimedMilestoneIds.Clear();
        foreach (int milestoneId in claimedMilestoneIds)
            saveData.claimedMilestoneIds.Add(milestoneId);
        saveData.claimedMilestoneIds.Sort();
    }

    internal void Clear()
    {
        discoveredTierIds.Clear();
        claimedMilestoneIds.Clear();
    }

    internal static bool TryCreateLegacyBackfill(
        MergeGameplaySaveData gameplay,
        out DessertCollectionSaveData saveData,
        out string failureReason)
    {
        saveData = null;
        failureReason = null;
        if (gameplay == null ||
            gameplay.boardDesserts == null ||
            gameplay.shelfDesserts == null)
        {
            failureReason =
                "Legacy merge session is missing dessert data.";
            return false;
        }

        var discovered = new HashSet<int>();
        foreach (BoardDessertSaveData dessert in gameplay.boardDesserts)
        {
            if (dessert == null ||
                !IsValidTierId(dessert.dessertTier))
            {
                failureReason =
                    "Legacy board contains an invalid dessert tier.";
                return false;
            }

            discovered.Add(dessert.dessertTier);
        }

        foreach (ShelfDessertSaveData dessert in gameplay.shelfDesserts)
        {
            if (dessert == null ||
                !IsValidTierId(dessert.dessertTier))
            {
                failureReason =
                    "Legacy shelf contains an invalid dessert tier.";
                return false;
            }

            discovered.Add(dessert.dessertTier);
        }

        saveData = new DessertCollectionSaveData();
        saveData.discoveredTierIds.AddRange(discovered);
        saveData.discoveredTierIds.Sort();
        return true;
    }

    internal static bool TryValidateSaveData(
        DessertCollectionSaveData saveData,
        out string failureReason)
    {
        failureReason = null;
        if (saveData == null ||
            saveData.discoveredTierIds == null ||
            saveData.claimedMilestoneIds == null)
        {
            failureReason =
                "Collection data or one of its ID lists is missing.";
            return false;
        }

        var discovered = new HashSet<int>();
        int previousTierId = 0;
        foreach (int tierId in saveData.discoveredTierIds)
        {
            if (!IsValidTierId(tierId) ||
                tierId <= previousTierId ||
                !discovered.Add(tierId))
            {
                failureReason =
                    $"Collection contains an invalid, duplicate, or unordered tier ID ({tierId}).";
                return false;
            }

            previousTierId = tierId;
        }

        var claimed = new HashSet<int>();
        int previousMilestoneId = 0;
        foreach (int milestoneId in saveData.claimedMilestoneIds)
        {
            if (!IsValidMilestoneId(milestoneId) ||
                milestoneId <= previousMilestoneId ||
                !claimed.Add(milestoneId) ||
                discovered.Count <
                    MilestoneRequirements[milestoneId - 1])
            {
                failureReason =
                    $"Collection contains an invalid, duplicate, unordered, or ineligible claimed reward ID ({milestoneId}).";
                return false;
            }

            previousMilestoneId = milestoneId;
        }

        return true;
    }

    private static bool IsValidTierId(int tierId)
    {
        return tierId >= 1 && tierId <= InitialTierCount;
    }

    private static bool IsValidMilestoneId(int milestoneId)
    {
        return milestoneId >= 1 &&
               milestoneId <= MilestoneRequirements.Length;
    }

    private static void ValidateTierId(int tierId)
    {
        if (!IsValidTierId(tierId))
            throw new ArgumentOutOfRangeException(nameof(tierId));
    }

    private static int GetMilestoneIndex(int milestoneId)
    {
        if (!IsValidMilestoneId(milestoneId))
            throw new ArgumentOutOfRangeException(nameof(milestoneId));

        return milestoneId - 1;
    }
}
