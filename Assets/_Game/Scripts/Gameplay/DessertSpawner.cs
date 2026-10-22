using System.Collections.Generic;
using System;
using UnityEngine;

public class DessertSpawner : MonoBehaviour
{
    private static readonly string[] SpawnPoolIds =
    {
        "P1", "P2", "P3", "P4", "P5", "P6"
    };

    private static readonly int[] SpawnPoolUnlockLevels =
    {
        1, 2, 3, 4, 5, 6
    };

    private static readonly int[] SpawnPoolFirstTiers =
    {
        1, 4, 8, 12, 16, 21
    };

    private static readonly int[] SpawnPoolHighestTiers =
    {
        3, 7, 11, 15, 20, 25
    };

    private static readonly int[] BonusChancePerTenThousand =
    {
        0, 50, 80, 100, 150, 200
    };

    private static readonly int[][] SpawnPoolTierWeights =
    {
        new[] { 60, 30, 10 },
        new[] { 40, 30, 20, 10 },
        new[] { 40, 30, 20, 10 },
        new[] { 40, 30, 20, 10 },
        new[] { 35, 25, 20, 12, 8 },
        new[] { 35, 25, 20, 12, 8 }
    };

    private static readonly int[][] ReferencePoolWeightsByOvenLevel =
    {
        new[] { 100, 0, 0, 0, 0, 0 },
        new[] { 25, 75, 0, 0, 0, 0 },
        new[] { 5, 20, 75, 0, 0, 0 },
        new[] { 3, 7, 15, 75, 0, 0 },
        new[] { 2, 4, 7, 12, 75, 0 },
        new[] { 1, 3, 4, 7, 10, 75 }
    };

    [Header("References")]
    [SerializeField]
    private GridManager gridManager;

    [SerializeField]
    private Dessert dessertPrefab;

    [SerializeField]
    private Transform dessertContainer;

    [SerializeField]
    private PlayerProgressionManager
        progressionManager;

    [Header("Dessert Database")]
    [SerializeField]
    private DessertDefinition[] dessertDefinitions;

    [Header("Next Dessert")]
    [SerializeField]
    private DessertDefinition nextDessert;

    private string selectedSpawnPoolId = "P1";

    public event Action<string, int, int> SpawnPoolChanged;

    public DessertDefinition NextDessert =>
        nextDessert;

    public string SelectedSpawnPoolId =>
        selectedSpawnPoolId;

    public IReadOnlyList<DessertDefinition> DessertDefinitions =>
        dessertDefinitions;

    public int CurrentOvenLevel
    {
        get
        {
            ResolveProgressionManager();
            return progressionManager != null
                ? progressionManager.OvenLevel
                : 1;
        }
    }

    public int MaxUnlockedDessertTier
    {
        get
        {
            ResolveProgressionManager();
            return progressionManager != null
                ? progressionManager.MaxUnlockedDessertTier
                : 0;
        }
    }

    public DessertDefinition GetDessertDefinitionByTier(int tier)
    {
        return GetDefinitionByTier(tier);
    }

    public IReadOnlyList<string> UnlockedSpawnPoolIds
    {
        get
        {
            ResolveProgressionManager();
            int ovenLevel = progressionManager != null
                ? progressionManager.OvenLevel
                : 1;
            return GetUnlockedSpawnPoolIds(ovenLevel);
        }
    }

    // ==================================================
    // DATABASE MAX TIER
    // ==================================================

    public int MaxTier
    {
        get
        {
            int maxTier = 0;

            if (dessertDefinitions == null)
                return maxTier;

            foreach (
                DessertDefinition definition
                in dessertDefinitions)
            {
                if (definition == null)
                    continue;

                if (definition.Tier > maxTier)
                {
                    maxTier =
                        definition.Tier;
                }
            }

            return maxTier;
        }
    }

    // ==================================================
    // UNITY
    // ==================================================

    private void Start()
    {
        ResolveProgressionManager();

        if (progressionManager == null)
        {
            Debug.LogError(
                "DessertSpawner: " +
                "PlayerProgressionManager " +
                "could not be found."
            );
        }
        else
        {
            progressionManager.UpgradeLevelChanged -=
                HandleUpgradeLevelChanged;
            progressionManager.UpgradeLevelChanged +=
                HandleUpgradeLevelChanged;
            if (!IsSpawnPoolUnlocked(
                    selectedSpawnPoolId,
                    progressionManager.OvenLevel))
            {
                selectedSpawnPoolId = "P1";
            }
        }

        PrepareNextDessert();
        PublishSpawnPoolChanged();
    }

    private void OnDestroy()
    {
        if (progressionManager != null)
        {
            progressionManager.UpgradeLevelChanged -=
                HandleUpgradeLevelChanged;
        }
    }

    private void HandleUpgradeLevelChanged(
        UpgradeType type,
        int newLevel)
    {
        if (type != UpgradeType.Oven)
            return;

        if (!IsSpawnPoolUnlocked(selectedSpawnPoolId, newLevel))
            selectedSpawnPoolId = "P1";
        PublishSpawnPoolChanged();
    }

    public bool TrySelectSpawnPool(string poolId)
    {
        ResolveProgressionManager();

        if (progressionManager == null)
        {
            Debug.LogError(
                "DessertSpawner: Cannot select a spawn pool " +
                "without PlayerProgressionManager."
            );
            return false;
        }

        if (!IsSpawnPoolUnlocked(
                poolId,
                progressionManager.OvenLevel))
        {
            Debug.LogWarning(
                $"SPAWN POOL SELECTION REJECTED | {poolId} | " +
                $"Oven L{progressionManager.OvenLevel}"
            );
            return false;
        }

        if (selectedSpawnPoolId == poolId)
            return true;

        selectedSpawnPoolId = poolId;
        PrepareNextDessert();
        PublishSpawnPoolChanged();
        return true;
    }

    public bool TryRestoreSpawnPool(string poolId)
    {
        ResolveProgressionManager();
        int ovenLevel = progressionManager != null
            ? progressionManager.OvenLevel
            : 1;
        string restoredPool = IsSpawnPoolUnlocked(poolId, ovenLevel)
            ? poolId
            : "P1";
        bool wasValid = restoredPool == poolId;
        selectedSpawnPoolId = restoredPool;
        PublishSpawnPoolChanged();
        if (!wasValid)
        {
            Debug.LogWarning(
                $"SPAWN POOL RESTORE | Invalid or locked pool '{poolId}'; " +
                "falling back to P1.");
        }

        return IsSpawnPoolUnlocked(selectedSpawnPoolId, ovenLevel);
    }

    public static bool IsValidSpawnPoolId(string poolId)
    {
        return GetSpawnPoolIndex(poolId) >= 0;
    }

    public static int GetSpawnPoolFirstTier(string poolId)
    {
        int index = GetSpawnPoolIndex(poolId);
        return index >= 0 ? SpawnPoolFirstTiers[index] : 0;
    }

    public static int GetSpawnPoolHighestTier(string poolId)
    {
        int index = GetSpawnPoolIndex(poolId);
        return index >= 0 ? SpawnPoolHighestTiers[index] : 0;
    }

    public static int GetSpawnPoolTierForRoll(string poolId, int roll)
    {
        int index = GetSpawnPoolIndex(poolId);
        if (index < 0)
            return 0;

        int totalWeight = 0;
        foreach (int weight in SpawnPoolTierWeights[index])
            totalWeight += weight;
        if (roll < 0 || roll >= totalWeight)
            return 0;

        int cumulativeWeight = 0;
        for (int tierIndex = 0;
             tierIndex < SpawnPoolTierWeights[index].Length;
             tierIndex++)
        {
            cumulativeWeight += SpawnPoolTierWeights[index][tierIndex];
            if (roll < cumulativeWeight)
                return SpawnPoolFirstTiers[index] + tierIndex;
        }

        return 0;
    }

    public static int GetBonusChancePerTenThousand(int ovenLevel)
    {
        return ovenLevel >= 1 &&
               ovenLevel <= BonusChancePerTenThousand.Length
            ? BonusChancePerTenThousand[ovenLevel - 1]
            : 0;
    }

    public static int GetEffectiveBonusChancePerHundredThousand(
        int ovenLevel,
        float luckMultiplier)
    {
        if (float.IsNaN(luckMultiplier) ||
            float.IsInfinity(luckMultiplier) ||
            luckMultiplier <= 0)
            return 0;

        return Mathf.RoundToInt(
            GetBonusChancePerTenThousand(ovenLevel) *
            10f *
            luckMultiplier);
    }

    public static bool ShouldSpawnBonus(
        int ovenLevel,
        float luckMultiplier,
        int roll)
    {
        return roll >= 0 &&
               roll < 100000 &&
               roll < GetEffectiveBonusChancePerHundredThousand(
                   ovenLevel,
                   luckMultiplier);
    }

    public static bool ShouldSpawnBonus(int ovenLevel, int roll)
    {
        if (roll < 0 || roll >= 10000)
            return false;

        return roll < GetBonusChancePerTenThousand(ovenLevel);
    }

    public static bool CanFitBonusDessert(int emptyCellCount)
    {
        return emptyCellCount >= 2;
    }

    public static bool ShouldAttemptBonus(
        int ovenLevel,
        int roll,
        int emptyCellCount)
    {
        return CanFitBonusDessert(emptyCellCount) &&
               ShouldSpawnBonus(ovenLevel, roll);
    }

    public static bool TryGetBonusDessertDefinition(
        DessertDefinition[] definitions,
        string selectedPoolId,
        int ovenLevel,
        int maxTier,
        int roll,
        out DessertDefinition bonusDefinition)
    {
        bonusDefinition = null;
        int selectedPoolIndex = GetSpawnPoolIndex(selectedPoolId);
        if (definitions == null ||
            selectedPoolIndex < 0 ||
            ovenLevel < 1 ||
            ovenLevel > SpawnPoolIds.Length ||
            maxTier < 1)
            return false;

        int selectedPoolHighestTier =
            SpawnPoolHighestTiers[selectedPoolIndex];
        int preferredPoolIndex = Math.Min(ovenLevel, SpawnPoolIds.Length) - 1;
        for (int poolIndex = preferredPoolIndex;
             poolIndex > selectedPoolIndex;
             poolIndex--)
        {
            if (SpawnPoolUnlockLevels[poolIndex] > ovenLevel)
                continue;

            int firstTier = Math.Max(
                SpawnPoolFirstTiers[poolIndex],
                selectedPoolHighestTier + 1);
            int lastTier = Math.Min(
                SpawnPoolHighestTiers[poolIndex],
                maxTier);
            int totalWeight = 0;

            for (int tier = firstTier; tier <= lastTier; tier++)
            {
                int weight = GetSpawnPoolTierWeight(
                    SpawnPoolIds[poolIndex],
                    tier);
                DessertDefinition definition = FindDefinition(definitions, tier);
                if (weight > 0 && definition != null && definition.CanSpawnFromOven)
                    totalWeight += weight;
            }

            if (totalWeight == 0)
                continue;
            if (roll < 0 || roll >= totalWeight)
                return false;

            int cumulativeWeight = 0;
            for (int tier = firstTier; tier <= lastTier; tier++)
            {
                int weight = GetSpawnPoolTierWeight(
                    SpawnPoolIds[poolIndex],
                    tier);
                DessertDefinition definition = FindDefinition(definitions, tier);
                if (weight <= 0 || definition == null || !definition.CanSpawnFromOven)
                    continue;

                cumulativeWeight += weight;
                if (roll < cumulativeWeight)
                {
                    bonusDefinition = definition;
                    return true;
                }
            }

            return false;
        }

        return false;
    }

    private static DessertDefinition FindDefinition(
        DessertDefinition[] definitions,
        int tier)
    {
        foreach (DessertDefinition definition in definitions)
            if (definition != null && definition.Tier == tier)
                return definition;
        return null;
    }

    private void PublishSpawnPoolChanged()
    {
        string poolId = selectedSpawnPoolId;
        SaveManager.Instance?.RecordSelectedSpawnPool(poolId);
        SpawnPoolChanged?.Invoke(
            poolId,
            GetSpawnPoolFirstTier(poolId),
            GetSpawnPoolHighestTier(poolId));
    }

    public static IReadOnlyList<string> GetUnlockedSpawnPoolIds(
        int ovenLevel)
    {
        var unlockedPools = new List<string>();
        for (int i = 0; i < SpawnPoolIds.Length; i++)
        {
            if (SpawnPoolUnlockLevels[i] <= ovenLevel)
                unlockedPools.Add(SpawnPoolIds[i]);
        }

        return unlockedPools;
    }

    public static bool IsSpawnPoolUnlocked(
        string poolId,
        int ovenLevel)
    {
        int poolIndex = GetSpawnPoolIndex(poolId);
        return poolIndex >= 0 &&
               SpawnPoolUnlockLevels[poolIndex] <= ovenLevel;
    }

    public static int GetSpawnPoolTierWeight(
        string poolId,
        int tier)
    {
        int poolIndex = GetSpawnPoolIndex(poolId);
        if (poolIndex < 0)
            return 0;

        int tierIndex = tier - SpawnPoolFirstTiers[poolIndex];
        if (tierIndex < 0 ||
            tierIndex >= SpawnPoolTierWeights[poolIndex].Length)
        {
            return 0;
        }

        return SpawnPoolTierWeights[poolIndex][tierIndex];
    }

    public static int GetReferencePoolWeightForOvenLevel(
        int ovenLevel,
        string poolId)
    {
        int poolIndex = GetSpawnPoolIndex(poolId);
        if (poolIndex < 0 ||
            ovenLevel < 1 ||
            ovenLevel > ReferencePoolWeightsByOvenLevel.Length)
        {
            return 0;
        }

        return ReferencePoolWeightsByOvenLevel[ovenLevel - 1][poolIndex];
    }

    private static string GetPoolIdForOvenLevel(int ovenLevel)
    {
        int poolIndex = Mathf.Clamp(
            ovenLevel - 1,
            0,
            SpawnPoolIds.Length - 1
        );
        return SpawnPoolIds[poolIndex];
    }

    private static int GetSpawnPoolIndex(string poolId)
    {
        for (int i = 0; i < SpawnPoolIds.Length; i++)
        {
            if (SpawnPoolIds[i] == poolId)
                return i;
        }

        return -1;
    }

    // ==================================================
    // REFERENCES
    // ==================================================

    private void ResolveProgressionManager()
    {
        /*
         * Always prefer the persistent progression
         * singleton.
         */
        if (PlayerProgressionManager.Instance != null)
        {
            progressionManager =
                PlayerProgressionManager.Instance;

            return;
        }

        /*
         * Emergency fallback.
         */
        if (progressionManager == null)
        {
            progressionManager =
                FindAnyObjectByType<
                    PlayerProgressionManager>();
        }
    }

    // ==================================================
    // NORMAL OVEN SPAWN
    // ==================================================

    public bool TrySpawnRandomDessert()
    {
        if (!ValidateReferences())
            return false;

        if (!gridManager.TryGetEmptyCell(
                out GridCell cell))
        {
            Debug.Log(
                "The grid is full."
            );

            return false;
        }

        if (nextDessert == null)
        {
            PrepareNextDessert();
        }

        if (nextDessert == null)
        {
            Debug.LogError(
                "DessertSpawner: " +
                "Could not prepare the next dessert."
            );

            return false;
        }

        DessertDefinition definitionToSpawn =
            nextDessert;

        int emptyCellsBeforeSpawn = gridManager.EmptyCellCount;
        Dessert dessert =
            SpawnDessert(
                definitionToSpawn,
                cell
            );

        if (dessert == null)
            return false;

        DessertAnimator dessertAnimator =
            dessert.GetComponent<
                DessertAnimator>();

        if (dessertAnimator != null)
        {
            dessertAnimator.PlaySpawnPop();
        }

        GameplayEvents.RaiseDessertSpawned(
            definitionToSpawn.Tier
        );

        Debug.Log(
            $"Spawned " +
            $"{definitionToSpawn.DisplayName} " +
            $"in {cell.name}."
        );

        int bonusRoll = CanFitBonusDessert(emptyCellsBeforeSpawn)
            ? UnityEngine.Random.Range(0, 100000)
            : -1;
        if (CanFitBonusDessert(emptyCellsBeforeSpawn) &&
            ShouldSpawnBonus(
                CurrentOvenLevel,
                progressionManager != null
                    ? progressionManager.LuckMultiplier
                    : 1f,
                bonusRoll) &&
            TryGetBonusDessertDefinition(
                dessertDefinitions,
                selectedSpawnPoolId,
                CurrentOvenLevel,
                MaxUnlockedDessertTier,
                UnityEngine.Random.Range(0, 100),
                out DessertDefinition bonusDefinition))
        {
            if (gridManager.TryGetEmptyCell(out GridCell bonusCell))
            {
                Dessert bonusDessert = SpawnDessert(bonusDefinition, bonusCell);
                if (bonusDessert != null)
                {
                    DessertAnimator bonusAnimator =
                        bonusDessert.GetComponent<DessertAnimator>();
                    if (bonusAnimator != null)
                        bonusAnimator.PlaySpawnPop();

                    GameplayEvents.RaiseDessertSpawned(
                        bonusDefinition.Tier);
                    Debug.Log(
                        $"OVEN BONUS | Spawned {bonusDefinition.DisplayName} " +
                        $"(T{bonusDefinition.Tier}) in {bonusCell.name}.");
                }
            }
        }

        gridManager.NotifyBoardChanged();

        /*
         * The saved/restored dessert has now
         * actually been consumed by the Oven.
         *
         * Roll the following dessert normally.
         */
        PrepareNextDessert();

        return true;
    }

    // ==================================================
    // STANDARD BOARD SPAWN
    // ==================================================

    public Dessert SpawnDessert(
        DessertDefinition definition,
        GridCell cell)
    {
        if (definition == null)
        {
            Debug.LogError(
                "DessertSpawner: Definition is null."
            );

            return null;
        }

        if (cell == null)
        {
            Debug.LogError(
                "DessertSpawner: Cell is null."
            );

            return null;
        }

        if (dessertPrefab == null)
        {
            Debug.LogError(
                "DessertSpawner: " +
                "Dessert prefab is missing."
            );

            return null;
        }

        if (dessertContainer == null)
        {
            Debug.LogError(
                "DessertSpawner: " +
                "Dessert container is missing."
            );

            return null;
        }

        if (!cell.IsEmpty)
        {
            Debug.LogWarning(
                $"DessertSpawner: {cell.name} " +
                "is already occupied."
            );

            return null;
        }

        Dessert newDessert =
            Instantiate(
                dessertPrefab,
                dessertContainer,
                false
            );

        Transform dessertTransform =
            newDessert.transform;

        dessertTransform.localPosition =
            Vector3.zero;

        dessertTransform.localRotation =
            Quaternion.identity;

        dessertTransform.localScale =
            Vector3.one;

        newDessert.Initialize(
            definition,
            cell
        );

        cell.PlaceDessert(
            newDessert
        );

        newDessert.ApplyNormalRendering();

        return newDessert;
    }

    // ==================================================
    // SESSION RESTORATION - BOARD
    // ==================================================

    public Dessert SpawnDessertOnBoardForRestore(
        int tier,
        GridCell cell)
    {
        if (cell == null)
        {
            Debug.LogWarning(
                "RESTORE BOARD FAILED | " +
                "GridCell is null."
            );

            return null;
        }

        DessertDefinition definition =
            GetDefinitionByTier(tier);

        if (definition == null)
        {
            Debug.LogError(
                $"RESTORE BOARD FAILED | " +
                $"No DessertDefinition exists " +
                $"for Tier {tier}."
            );

            return null;
        }

        return SpawnDessert(
            definition,
            cell
        );
    }

    // ==================================================
    // SESSION RESTORATION - SHELF
    // ==================================================

    public Dessert SpawnDessertOnShelfForRestore(
        int tier,
        ShelfSlot slot)
    {
        if (slot == null)
        {
            Debug.LogWarning(
                "RESTORE SHELF FAILED | " +
                "ShelfSlot is null."
            );

            return null;
        }

        if (!slot.IsUnlocked)
        {
            Debug.LogWarning(
                $"RESTORE SHELF FAILED | " +
                $"{slot.name} is locked."
            );

            return null;
        }

        if (!slot.IsEmpty)
        {
            Debug.LogWarning(
                $"RESTORE SHELF FAILED | " +
                $"{slot.name} is already occupied."
            );

            return null;
        }

        DessertDefinition definition =
            GetDefinitionByTier(tier);

        if (definition == null)
        {
            Debug.LogError(
                $"RESTORE SHELF FAILED | " +
                $"No DessertDefinition exists " +
                $"for Tier {tier}."
            );

            return null;
        }

        if (dessertPrefab == null)
        {
            Debug.LogError(
                "RESTORE SHELF FAILED | " +
                "Dessert prefab is missing."
            );

            return null;
        }

        if (dessertContainer == null)
        {
            Debug.LogError(
                "RESTORE SHELF FAILED | " +
                "Dessert container is missing."
            );

            return null;
        }

        Dessert newDessert =
            Instantiate(
                dessertPrefab,
                dessertContainer,
                false
            );

        Transform dessertTransform =
            newDessert.transform;

        dessertTransform.localPosition =
            Vector3.zero;

        dessertTransform.localRotation =
            Quaternion.identity;

        dessertTransform.localScale =
            Vector3.one;

        newDessert.Initialize(
            definition,
            null
        );

        bool stored =
            slot.TryStoreDessert(
                newDessert,
                true
            );

        if (!stored)
        {
            Debug.LogWarning(
                $"RESTORE SHELF FAILED | " +
                $"Could not store Tier {tier} " +
                $"in {slot.name}."
            );

            Destroy(
                newDessert.gameObject
            );

            return null;
        }

        newDessert.ApplyNormalRendering();

        return newDessert;
    }

    // ==================================================
    // NEXT DESSERT RESTORATION
    // ==================================================

    public bool RestoreNextDessert(
        int tier)
    {
        DessertDefinition definition =
            GetDefinitionByTier(tier);

        if (definition == null)
        {
            Debug.LogWarning(
                $"NEXT DESSERT RESTORE FAILED | " +
                $"No DessertDefinition exists " +
                $"for Tier {tier}."
            );

            return false;
        }

        nextDessert =
            definition;

        /*
         * Tell the existing preview UI that the
         * queued dessert changed.
         */
        GameplayEvents.RaiseNextDessertChanged(
            nextDessert
        );

        Debug.Log(
            $"NEXT DESSERT RESTORED | " +
            $"{nextDessert.DisplayName} | " +
            $"Tier {nextDessert.Tier}"
        );

        return true;
    }

    internal bool TryPrepareFreshSessionPreview(
        out DessertDefinition preparedPreview)
    {
        preparedPreview = GetRandomOvenDessert();
        return preparedPreview != null &&
               progressionManager != null &&
               progressionManager.IsDessertTierUnlocked(
                   preparedPreview.Tier);
    }

    internal bool SetFreshSessionPreview(
        DessertDefinition preparedPreview,
        bool notify)
    {
        if (preparedPreview == null ||
            GetDefinitionByTier(preparedPreview.Tier) != preparedPreview ||
            progressionManager == null ||
            !progressionManager.IsDessertTierUnlocked(preparedPreview.Tier))
            return false;

        nextDessert = preparedPreview;
        if (notify)
            PublishNextDessertChanged();
        return true;
    }

    internal void PublishNextDessertChanged()
    {
        GameplayEvents.RaiseNextDessertChanged(nextDessert);
    }

    // ==================================================
    // DEFINITION LOOKUP
    // ==================================================

    public DessertDefinition GetDefinitionByTier(
        int tier)
    {
        if (dessertDefinitions == null)
            return null;

        foreach (
            DessertDefinition definition
            in dessertDefinitions)
        {
            if (definition == null)
                continue;

            if (definition.Tier == tier)
            {
                return definition;
            }
        }

        return null;
    }

    // ==================================================
    // NEXT DESSERT GENERATION
    // ==================================================

    private void PrepareNextDessert()
    {
        nextDessert =
            GetRandomOvenDessert();

        if (nextDessert == null)
        {
            Debug.LogError(
                "DessertSpawner: " +
                "No valid next dessert " +
                "could be prepared."
            );

            return;
        }

        PublishNextDessertChanged();

        Debug.Log(
            $"OVEN PREVIEW | Next dessert: " +
            $"{nextDessert.DisplayName} " +
            $"(Tier {nextDessert.Tier})"
        );
    }

    // ==================================================
    // OVEN RNG
    // ==================================================

    private DessertDefinition
        GetRandomOvenDessert()
    {
        ResolveProgressionManager();

        List<DessertDefinition> candidates =
            new List<DessertDefinition>();

        List<int> candidateWeights =
            new List<int>();

        int totalWeight = 0;

        if (dessertDefinitions == null)
            return null;

        int maxUnlockedTier =
            progressionManager != null
                ? progressionManager
                    .MaxUnlockedDessertTier
                : SpawnPoolHighestTiers[
                    GetSpawnPoolIndex(selectedSpawnPoolId) < 0
                        ? 0
                        : GetSpawnPoolIndex(selectedSpawnPoolId)
                ];

        int selectedPoolIndex =
            GetSpawnPoolIndex(selectedSpawnPoolId);

        if (selectedPoolIndex < 0 ||
            !IsSpawnPoolUnlocked(
                selectedSpawnPoolId,
                progressionManager != null
                    ? progressionManager.OvenLevel
                    : 1))
        {
            selectedSpawnPoolId = "P1";
            selectedPoolIndex =
                GetSpawnPoolIndex(selectedSpawnPoolId);
        }

        for (
            int tier = SpawnPoolFirstTiers[selectedPoolIndex];
            tier <= SpawnPoolHighestTiers[selectedPoolIndex];
            tier++)
        {
            int weight =
                GetSpawnPoolTierWeight(
                    selectedSpawnPoolId,
                    tier
                );
            if (weight <= 0 ||
                tier > maxUnlockedTier)
            {
                continue;
            }

            DessertDefinition definition =
                GetDefinitionByTier(tier);
            if (definition == null ||
                !definition.CanSpawnFromOven)
            {
                continue;
            }

            candidates.Add(definition);
            candidateWeights.Add(weight);
            totalWeight += weight;
        }

        if (candidates.Count == 0 || totalWeight <= 0)
        {
            Debug.LogWarning(
                $"OVEN RNG | No valid desserts in " +
                $"{selectedSpawnPoolId}. | " +
                $"Max Unlocked Tier: T{maxUnlockedTier}"
            );
            return null;
        }

        int roll =
            UnityEngine.Random.Range(
                0,
                totalWeight
            );

        int cumulativeWeight = 0;
        for (int i = 0; i < candidates.Count; i++)
        {
            cumulativeWeight +=
                candidateWeights[i];

            if (roll < cumulativeWeight)
            {
                DessertDefinition candidate =
                    candidates[i];
                Debug.Log(
                    $"OVEN RNG | " +
                    $"Pool {selectedSpawnPoolId} | " +
                    $"Selected: " +
                    $"{candidate.DisplayName} | " +
                    $"Tier T{candidate.Tier} | " +
                    $"Max Unlocked: " +
                    $"T{maxUnlockedTier}"
                );

                return candidate;
            }
        }

        DessertDefinition fallback =
            candidates[
                candidates.Count - 1
            ];

        Debug.Log(
            $"OVEN RNG | " +
            $"Pool {selectedSpawnPoolId} | " +
            $"Selected fallback: " +
            $"{fallback.DisplayName} | " +
            $"Tier T{fallback.Tier} | " +
            $"Max Unlocked: " +
            $"T{maxUnlockedTier}"
        );

        return fallback;
    }

    // ==================================================
    // VALIDATION
    // ==================================================

    private bool ValidateReferences()
    {
        if (gridManager == null)
        {
            Debug.LogError(
                "DessertSpawner: " +
                "GridManager is missing."
            );

            return false;
        }

        if (dessertPrefab == null)
        {
            Debug.LogError(
                "DessertSpawner: " +
                "Dessert prefab is missing."
            );

            return false;
        }

        if (dessertContainer == null)
        {
            Debug.LogError(
                "DessertSpawner: " +
                "Dessert container is missing."
            );

            return false;
        }

        if (dessertDefinitions == null ||
            dessertDefinitions.Length == 0)
        {
            Debug.LogError(
                "DessertSpawner: " +
                "No dessert definitions assigned."
            );

            return false;
        }

        return true;
    }
}