using UnityEngine;

public class DessertDebugTools : MonoBehaviour
{
    [SerializeField] private DessertSpawner dessertSpawner;
    [SerializeField] private GridManager gridManager;

    [Header("Debug")]
    [Range(1, 11)]
    [SerializeField] private int tierToSpawn = 1;

    [ContextMenu("Spawn Debug Dessert")]
    private void SpawnDebugDessert()
    {
        if (dessertSpawner == null ||
            gridManager == null)
        {
            Debug.LogError(
                "DessertDebugTools: Missing references."
            );

            return;
        }

        if (!gridManager.TryGetEmptyCell(out GridCell cell))
        {
            Debug.LogWarning(
                "DessertDebugTools: Grid is full."
            );

            return;
        }

        DessertDefinition definition =
            dessertSpawner.GetDefinitionByTier(tierToSpawn);

        if (definition == null)
        {
            Debug.LogError(
                $"No definition found for Tier {tierToSpawn}."
            );

            return;
        }

        dessertSpawner.SpawnDessert(
            definition,
            cell
        );

        Debug.Log(
            $"DEBUG: Spawned {definition.DisplayName}."
        );
    }
    
}