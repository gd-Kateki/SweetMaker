using System;
using System.Collections.Generic;
using UnityEngine;

public enum CustomerOrderDifficulty
{
    Easy,
    Standard,
    Hard
}

public enum CustomerOrderShape
{
    Single,
    Mixed
}

public sealed class GeneratedCustomerOrder
{
    private readonly IReadOnlyList<OrderRequirement> readOnlyRequirements;

    public string ReferencePoolId { get; }
    public CustomerOrderDifficulty Difficulty { get; }
    public CustomerOrderShape Shape { get; }
    public IReadOnlyList<OrderRequirement> Requirements =>
        readOnlyRequirements;
    public int BaseReward { get; }

    internal GeneratedCustomerOrder(
        string referencePoolId,
        CustomerOrderDifficulty difficulty,
        CustomerOrderShape shape,
        OrderRequirement[] requirements,
        int baseReward)
    {
        ReferencePoolId = referencePoolId;
        Difficulty = difficulty;
        Shape = shape;
        readOnlyRequirements = Array.AsReadOnly(requirements);
        BaseReward = baseReward;
    }
}

public static class ProceduralCustomerOrderGenerator
{
    private const int ChanceRange = 100;
    private const int MinimumServingPlateCapacity = 2;
    private const int MaximumServingPlateCapacity = 5;
    private const int MaximumDessertTypesPerOrder = 2;
    private const int MaximumCopiesPerDessertType = 3;

    private static readonly int[] ReferencePoolBaseValues =
    {
        8, 20, 60, 180, 500, 1500
    };

    public static bool TryGenerate(
        IReadOnlyList<DessertDefinition> dessertDefinitions,
        int ovenLevel,
        int maxUnlockedDessertTier,
        System.Random random,
        out GeneratedCustomerOrder order)
    {
        return TryGenerateForPlateCapacity(
            dessertDefinitions,
            ovenLevel,
            maxUnlockedDessertTier,
            MaximumServingPlateCapacity,
            random,
            out order);
    }

    public static bool TryGenerateForPlateCapacity(
        IReadOnlyList<DessertDefinition> dessertDefinitions,
        int ovenLevel,
        int maxUnlockedDessertTier,
        int servingPlateCapacity,
        System.Random random,
        out GeneratedCustomerOrder order)
    {
        order = null;
        if (random == null ||
            !TryGetReferencePoolWeightTotal(ovenLevel, out int poolWeightTotal))
        {
            return false;
        }

        return TryGenerateFromRollsForPlateCapacity(
            dessertDefinitions,
            ovenLevel,
            maxUnlockedDessertTier,
            random.Next(ChanceRange),
            random.Next(ChanceRange),
            random.Next(poolWeightTotal),
            servingPlateCapacity,
            random.Next(ChanceRange),
            out order);
    }

    public static bool TryGenerateFromRolls(
        IReadOnlyList<DessertDefinition> dessertDefinitions,
        int ovenLevel,
        int maxUnlockedDessertTier,
        int shapeRoll,
        int difficultyRoll,
        int referencePoolRoll,
        out GeneratedCustomerOrder order)
    {
        return TryGenerateFromRolls(
            dessertDefinitions,
            ovenLevel,
            maxUnlockedDessertTier,
            shapeRoll,
            difficultyRoll,
            referencePoolRoll,
            MaximumServingPlateCapacity,
            50,
            true,
            out order);
    }

    public static bool TryGenerateFromRollsForPlateCapacity(
        IReadOnlyList<DessertDefinition> dessertDefinitions,
        int ovenLevel,
        int maxUnlockedDessertTier,
        int shapeRoll,
        int difficultyRoll,
        int referencePoolRoll,
        int servingPlateCapacity,
        int quantityRoll,
        out GeneratedCustomerOrder order)
    {
        return TryGenerateFromRolls(
            dessertDefinitions,
            ovenLevel,
            maxUnlockedDessertTier,
            shapeRoll,
            difficultyRoll,
            referencePoolRoll,
            servingPlateCapacity,
            quantityRoll,
            false,
            out order);
    }

    private static bool TryGenerateFromRolls(
        IReadOnlyList<DessertDefinition> dessertDefinitions,
        int ovenLevel,
        int maxUnlockedDessertTier,
        int shapeRoll,
        int difficultyRoll,
        int referencePoolRoll,
        int servingPlateCapacity,
        int quantityRoll,
        bool preserveLegacyQuantities,
        out GeneratedCustomerOrder order)
    {
        order = null;
        if (dessertDefinitions == null ||
            ovenLevel < 1 ||
            ovenLevel > ReferencePoolBaseValues.Length ||
            maxUnlockedDessertTier < 1 ||
            maxUnlockedDessertTier > 30 ||
            servingPlateCapacity < MinimumServingPlateCapacity ||
            servingPlateCapacity > MaximumServingPlateCapacity ||
            shapeRoll < 0 ||
            shapeRoll >= ChanceRange ||
            difficultyRoll < 0 ||
            difficultyRoll >= ChanceRange ||
            quantityRoll < 0 ||
            quantityRoll >= ChanceRange ||
            !TrySelectReferencePool(
                ovenLevel,
                referencePoolRoll,
                out string poolId,
                out int poolBaseValue))
        {
            return false;
        }

        if (!TryBuildTierLookup(
                dessertDefinitions,
                out Dictionary<int, DessertDefinition> definitionsByTier))
        {
            return false;
        }

        int highestSpawnableTier = GetHighestSpawnableTier(
            poolId,
            maxUnlockedDessertTier,
            definitionsByTier);
        if (highestSpawnableTier < 1)
            return false;

        CustomerOrderShape shape = shapeRoll < 60
            ? CustomerOrderShape.Single
            : CustomerOrderShape.Mixed;
        CustomerOrderDifficulty difficulty =
            GetDifficulty(difficultyRoll);

        int firstTier;
        int secondTier = 0;
        int firstAmount = 1;
        int secondAmount = 0;
        if (shape == CustomerOrderShape.Single)
        {
            firstTier = highestSpawnableTier +
                        GetSingleTierOffset(difficulty);
            if (!preserveLegacyQuantities)
            {
                firstAmount = Mathf.Min(
                    GetSingleOrderAmount(quantityRoll),
                    servingPlateCapacity);
            }
        }
        else
        {
            firstTier = highestSpawnableTier +
                        GetMixedPrimaryTierOffset(difficulty);
            secondTier = highestSpawnableTier +
                         GetMixedSecondaryTierOffset(difficulty);
            if (preserveLegacyQuantities)
            {
                secondAmount = 2;
            }
            else
            {
                int totalAmount = Mathf.Min(
                    GetMixedOrderTotal(quantityRoll),
                    servingPlateCapacity);
                firstAmount = totalAmount / 2;
                secondAmount = totalAmount - firstAmount;
            }
        }

        if (!TryGetRequirement(
                definitionsByTier,
                firstTier,
                firstAmount,
                maxUnlockedDessertTier,
                out OrderRequirement firstRequirement))
        {
            return false;
        }

        OrderRequirement[] requirements;
        if (secondAmount == 0)
        {
            requirements = new[] { firstRequirement };
        }
        else
        {
            if (!TryGetRequirement(
                    definitionsByTier,
                    secondTier,
                    secondAmount,
                    maxUnlockedDessertTier,
                    out OrderRequirement secondRequirement))
            {
                return false;
            }

            requirements = new[] { firstRequirement, secondRequirement };
        }

        int totalDesserts = 0;
        if (requirements.Length > MaximumDessertTypesPerOrder)
            return false;
        foreach (OrderRequirement requirement in requirements)
        {
            if (requirement.Amount > MaximumCopiesPerDessertType)
                return false;
            totalDesserts += requirement.Amount;
        }
        if (totalDesserts > servingPlateCapacity)
            return false;

        float difficultyFactor = GetEffortFactor(difficulty);
        float rewardPremium = GetRewardPremium(difficulty);
        int reward = Mathf.RoundToInt(
            poolBaseValue * difficultyFactor * rewardPremium);

        order = new GeneratedCustomerOrder(
            poolId,
            difficulty,
            shape,
            requirements,
            reward);
        return true;
    }

    private static int GetSingleOrderAmount(int roll)
    {
        if (roll < 34)
            return 1;
        return roll < 67 ? 2 : MaximumCopiesPerDessertType;
    }

    private static int GetMixedOrderTotal(int roll)
    {
        if (roll < 25)
            return 2;
        if (roll < 50)
            return 3;
        if (roll < 75)
            return 4;
        return MaximumServingPlateCapacity;
    }

    private static bool TryGetReferencePoolWeightTotal(
        int ovenLevel,
        out int totalWeight)
    {
        totalWeight = 0;
        if (ovenLevel < 1 ||
            ovenLevel > ReferencePoolBaseValues.Length)
        {
            return false;
        }

        foreach (string poolId in DessertSpawner.GetUnlockedSpawnPoolIds(ovenLevel))
        {
            totalWeight += DessertSpawner.GetReferencePoolWeightForOvenLevel(
                ovenLevel,
                poolId);
        }

        return totalWeight > 0;
    }

    private static bool TrySelectReferencePool(
        int ovenLevel,
        int roll,
        out string poolId,
        out int poolBaseValue)
    {
        poolId = null;
        poolBaseValue = 0;
        if (!TryGetReferencePoolWeightTotal(ovenLevel, out int totalWeight) ||
            roll < 0 ||
            roll >= totalWeight)
        {
            return false;
        }

        int cumulativeWeight = 0;
        foreach (string candidatePoolId in
                 DessertSpawner.GetUnlockedSpawnPoolIds(ovenLevel))
        {
            int weight = DessertSpawner.GetReferencePoolWeightForOvenLevel(
                ovenLevel,
                candidatePoolId);
            cumulativeWeight += weight;
            if (roll >= cumulativeWeight)
                continue;

            int poolIndex = ParsePoolIndex(candidatePoolId);
            if (poolIndex < 0)
                return false;

            poolId = candidatePoolId;
            poolBaseValue = ReferencePoolBaseValues[poolIndex];
            return true;
        }

        return false;
    }

    private static int ParsePoolIndex(string poolId)
    {
        if (poolId == null ||
            poolId.Length != 2 ||
            poolId[0] != 'P' ||
            poolId[1] < '1' ||
            poolId[1] > '6')
        {
            return -1;
        }

        return poolId[1] - '1';
    }

    private static bool TryBuildTierLookup(
        IReadOnlyList<DessertDefinition> definitions,
        out Dictionary<int, DessertDefinition> definitionsByTier)
    {
        definitionsByTier = new Dictionary<int, DessertDefinition>();
        foreach (DessertDefinition definition in definitions)
        {
            if (definition == null ||
                definition.Tier < 1 ||
                definition.Tier > 30)
            {
                continue;
            }

            if (definitionsByTier.ContainsKey(definition.Tier))
            {
                definitionsByTier = null;
                return false;
            }

            definitionsByTier.Add(definition.Tier, definition);
        }

        return true;
    }

    private static int GetHighestSpawnableTier(
        string poolId,
        int maxUnlockedDessertTier,
        IReadOnlyDictionary<int, DessertDefinition> definitionsByTier)
    {
        int highestTier = 0;
        for (int tier = 1; tier <= maxUnlockedDessertTier; tier++)
        {
            if (DessertSpawner.GetSpawnPoolTierWeight(poolId, tier) <= 0 ||
                !definitionsByTier.TryGetValue(tier, out DessertDefinition definition) ||
                !definition.CanSpawnFromOven)
            {
                continue;
            }

            highestTier = tier;
        }

        return highestTier;
    }

    private static bool TryGetRequirement(
        IReadOnlyDictionary<int, DessertDefinition> definitionsByTier,
        int tier,
        int amount,
        int maxUnlockedDessertTier,
        out OrderRequirement requirement)
    {
        requirement = null;
        if (tier < 1 ||
            tier > 30 ||
            tier > maxUnlockedDessertTier ||
            amount < 1 ||
            !definitionsByTier.TryGetValue(tier, out DessertDefinition definition))
        {
            return false;
        }

        requirement = new OrderRequirement(definition, amount);
        return true;
    }

    private static CustomerOrderDifficulty GetDifficulty(int roll)
    {
        if (roll < 50)
            return CustomerOrderDifficulty.Easy;
        return roll < 85
            ? CustomerOrderDifficulty.Standard
            : CustomerOrderDifficulty.Hard;
    }

    private static int GetSingleTierOffset(CustomerOrderDifficulty difficulty)
    {
        switch (difficulty)
        {
            case CustomerOrderDifficulty.Easy: return 2;
            case CustomerOrderDifficulty.Standard: return 3;
            case CustomerOrderDifficulty.Hard: return 4;
            default: throw new ArgumentOutOfRangeException(nameof(difficulty));
        }
    }

    private static int GetMixedPrimaryTierOffset(CustomerOrderDifficulty difficulty)
    {
        switch (difficulty)
        {
            case CustomerOrderDifficulty.Easy: return 1;
            case CustomerOrderDifficulty.Standard: return 2;
            case CustomerOrderDifficulty.Hard: return 3;
            default: throw new ArgumentOutOfRangeException(nameof(difficulty));
        }
    }

    private static int GetMixedSecondaryTierOffset(CustomerOrderDifficulty difficulty)
    {
        switch (difficulty)
        {
            case CustomerOrderDifficulty.Easy: return 0;
            case CustomerOrderDifficulty.Standard: return 1;
            case CustomerOrderDifficulty.Hard: return 2;
            default: throw new ArgumentOutOfRangeException(nameof(difficulty));
        }
    }

    private static float GetEffortFactor(CustomerOrderDifficulty difficulty)
    {
        switch (difficulty)
        {
            case CustomerOrderDifficulty.Easy: return 4f;
            case CustomerOrderDifficulty.Standard: return 8f;
            case CustomerOrderDifficulty.Hard: return 16f;
            default: throw new ArgumentOutOfRangeException(nameof(difficulty));
        }
    }

    private static float GetRewardPremium(CustomerOrderDifficulty difficulty)
    {
        switch (difficulty)
        {
            case CustomerOrderDifficulty.Easy: return 1f;
            case CustomerOrderDifficulty.Standard: return 1.05f;
            case CustomerOrderDifficulty.Hard: return 1.15f;
            default: throw new ArgumentOutOfRangeException(nameof(difficulty));
        }
    }
}
