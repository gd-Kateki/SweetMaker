using System.Collections.Generic;
using UnityEngine;

public class DessertSpawner : MonoBehaviour
{
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

    public DessertDefinition NextDessert =>
        nextDessert;

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

        PrepareNextDessert();
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

        gridManager.NotifyBoardChanged();

        GameplayEvents.RaiseDessertSpawned(
            definitionToSpawn.Tier
        );

        Debug.Log(
            $"Spawned " +
            $"{definitionToSpawn.DisplayName} " +
            $"in {cell.name}."
        );

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

        GameplayEvents.RaiseNextDessertChanged(
            nextDessert
        );

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

        float totalWeight = 0f;

        if (dessertDefinitions == null)
            return null;

        /*
         * If progression exists, use the player's
         * current Oven progression limit.
         *
         * MaxTier is only an emergency fallback.
         */
        int maxUnlockedTier =
            progressionManager != null
                ? progressionManager
                    .MaxUnlockedDessertTier
                : MaxTier;

        foreach (
            DessertDefinition definition
            in dessertDefinitions)
        {
            if (definition == null)
                continue;

            /*
             * The dessert must explicitly be allowed
             * to spawn directly from the Oven.
             */
            if (!definition.CanSpawnFromOven)
                continue;

            /*
             * Zero or negative weight means it cannot
             * participate in Oven RNG.
             */
            if (definition.SpawnWeight <= 0f)
                continue;

            /*
             * Oven progression controls the maximum
             * dessert tier that can currently enter
             * the Oven RNG pool.
             */
            if (definition.Tier >
                maxUnlockedTier)
            {
                continue;
            }

            candidates.Add(
                definition
            );

            totalWeight +=
                definition.SpawnWeight;
        }

        if (candidates.Count == 0 ||
            totalWeight <= 0f)
        {
            Debug.LogWarning(
                $"OVEN RNG | " +
                $"No valid desserts available. | " +
                $"Max Unlocked Tier: " +
                $"T{maxUnlockedTier}"
            );

            return null;
        }

        float roll =
            Random.Range(
                0f,
                totalWeight
            );

        float cumulativeWeight = 0f;

        foreach (
            DessertDefinition candidate
            in candidates)
        {
            cumulativeWeight +=
                candidate.SpawnWeight;

            if (roll <= cumulativeWeight)
            {
                Debug.Log(
                    $"OVEN RNG | " +
                    $"Selected: " +
                    $"{candidate.DisplayName} | " +
                    $"Tier T{candidate.Tier} | " +
                    $"Max Unlocked: " +
                    $"T{maxUnlockedTier}"
                );

                return candidate;
            }
        }

        /*
         * Floating-point safety fallback.
         */
        DessertDefinition fallback =
            candidates[
                candidates.Count - 1
            ];

        Debug.Log(
            $"OVEN RNG | " +
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