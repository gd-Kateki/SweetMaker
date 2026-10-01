using UnityEngine;

public class OvenController : MonoBehaviour
{
    [SerializeField] private DessertSpawner dessertSpawner;

    private void OnMouseDown()
    {
        if (dessertSpawner == null)
        {
            Debug.LogError("OvenController: DessertSpawner is not assigned.");
            return;
        }

        dessertSpawner.TrySpawnRandomDessert();
    }
}