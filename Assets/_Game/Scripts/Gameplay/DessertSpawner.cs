using System.Collections.Generic;
using UnityEngine;

public class DessertSpawner : MonoBehaviour
{
    [Header("References")]
    [SerializeField] private GridManager gridManager;

    [SerializeField] private Dessert dessertPrefab;

    [Header("Dessert Database")]
    [SerializeField]
    private DessertDefinition[] dessertDefinitions;

    public bool TrySpawnRandomDessert()
    {
        if (gridManager == null)
        {
            Debug.LogError(
                "DessertSpawner: GridManager is missing."
            );

            return false;
        }

        if (dessertPrefab == null)
        {
            Debug.LogError(
                "DessertSpawner: Dessert prefab is missing."
            );

            return false;
        }

        if (!gridManager.TryGetEmptyCell(out GridCell cell))
        {
            Debug.Log("The grid is full.");
            return false;
        }

        DessertDefinition definition =
            GetRandomOvenDessert();

        if (definition == null)
        {
            Debug.LogError(
                "DessertSpawner: No valid oven desserts found."
            );

            return false;
        }

        SpawnDessert(definition, cell);

        return true;
    }

    public Dessert SpawnDessert(
        DessertDefinition definition,
        GridCell cell)
    {
        if (definition == null || cell == null)
            return null;

        Dessert newDessert = Instantiate(dessertPrefab);

        newDessert.Initialize(
            definition,
            cell
        );

        cell.PlaceDessert(newDessert);

        return newDessert;
    }

    public DessertDefinition GetDefinitionByTier(int tier)
    {
        foreach (DessertDefinition definition in dessertDefinitions)
        {
            if (definition != null &&
                definition.Tier == tier)
            {
                return definition;
            }
        }

        return null;
    }

    private DessertDefinition GetRandomOvenDessert()
    {
        List<DessertDefinition> candidates = new();

        float totalWeight = 0f;

        foreach (DessertDefinition definition in dessertDefinitions)
        {
            if (definition == null)
                continue;

            if (!definition.CanSpawnFromOven)
                continue;

            if (definition.SpawnWeight <= 0f)
                continue;

            candidates.Add(definition);

            totalWeight += definition.SpawnWeight;
        }

        if (candidates.Count == 0 ||
            totalWeight <= 0f)
        {
            return null;
        }

        float roll = Random.Range(
            0f,
            totalWeight
        );

        float cumulativeWeight = 0f;

        foreach (DessertDefinition candidate in candidates)
        {
            cumulativeWeight += candidate.SpawnWeight;

            if (roll <= cumulativeWeight)
            {
                return candidate;
            }
        }

        return candidates[candidates.Count - 1];
    }

    public int MaxTier
{
    get
    {
        int maxTier = 0;

        foreach (DessertDefinition definition in dessertDefinitions)
        {
            if (definition != null &&
                definition.Tier > maxTier)
            {
                maxTier = definition.Tier;
            }
        }

        return maxTier;
    }
}
}