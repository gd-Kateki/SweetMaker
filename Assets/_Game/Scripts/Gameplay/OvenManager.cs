using UnityEngine;

public class OvenManager : MonoBehaviour
{
    [Header("References")]
    [SerializeField]
    private DessertSpawner dessertSpawner;

    private bool isProcessingRequest;

    public bool CanUseOven
    {
        get
        {
            if (isProcessingRequest)
                return false;

            if (GameManager.Instance == null)
                return true;

            return GameManager.Instance.IsPlaying;
        }
    }

    public void RequestSpawn()
    {
        if (!CanUseOven)
        {
            Debug.Log(
                "OVEN | Spawn request rejected."
            );

            return;
        }

        if (dessertSpawner == null)
        {
            Debug.LogError(
                "OvenManager: DessertSpawner " +
                "is not assigned."
            );

            return;
        }

        isProcessingRequest = true;

        bool spawned =
            dessertSpawner.TrySpawnRandomDessert();

        isProcessingRequest = false;

        if (spawned)
{
    Debug.Log(
        "OVEN | Spawn request successful."
    );
}
else
{
    Debug.Log(
        "OVEN | Spawn request failed."
    );
}
    }
}