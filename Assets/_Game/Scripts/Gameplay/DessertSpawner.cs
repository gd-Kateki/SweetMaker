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

    [Header("Dessert Database")]
    [SerializeField]
    private DessertDefinition[] dessertDefinitions;

    [Header("Next Dessert")]
    [SerializeField]
    private DessertDefinition nextDessert;

    public DessertDefinition NextDessert =>
        nextDessert;

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

    private void Start()
    {
        PrepareNextDessert();
    }

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
            dessert.GetComponent<DessertAnimator>();

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

        PrepareNextDessert();

        return true;
    }

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

    private DessertDefinition
        GetRandomOvenDessert()
    {
        List<DessertDefinition> candidates =
            new List<DessertDefinition>();

        float totalWeight = 0f;

        if (dessertDefinitions == null)
            return null;

        foreach (
            DessertDefinition definition
            in dessertDefinitions)
        {
            if (definition == null)
                continue;

            if (!definition.CanSpawnFromOven)
                continue;

            if (definition.SpawnWeight <= 0f)
                continue;

            candidates.Add(
                definition
            );

            totalWeight +=
                definition.SpawnWeight;
        }

        if (candidates.Count == 0 ||
            totalWeight <= 0f)
        {
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
                return candidate;
            }
        }

        return candidates[
            candidates.Count - 1
        ];
    }

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