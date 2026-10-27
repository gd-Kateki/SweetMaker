using UnityEngine;

public class OvenManager : MonoBehaviour
{
    [Header("References")]
    [SerializeField]
    private DessertSpawner dessertSpawner;

    private bool isProcessingRequest;

    public bool LastRequestFailedForNoBoardSpace { get; private set; }

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
        LastRequestFailedForNoBoardSpace = false;

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

        PlayerProgressionManager progression =
            PlayerProgressionManager.Instance;
        if (progression == null)
        {
            Debug.LogError(
                "OvenManager: PlayerProgressionManager is unavailable; " +
                "player spawning is blocked."
            );
            return;
        }

        if (progression.CurrentEnergy <= 0)
        {
            Debug.Log("OVEN | Spawn request rejected: no Energy.");
            return;
        }

        isProcessingRequest = true;
        bool spawned;
        try
        {
            spawned = dessertSpawner.TrySpawnRandomDessert(
                out bool failedForNoBoardSpace);
            LastRequestFailedForNoBoardSpace =
                failedForNoBoardSpace;

            if (spawned)
            {
                bool energyConsumed =
                    progression.TryConsumeEnergy();
                if (!energyConsumed)
                {
                    Debug.LogError(
                        "OVEN | Dessert spawned, but Energy could not be " +
                        "deducted after the successful request."
                    );
                }

                bool discoveryAdded =
                    dessertSpawner.LastSpawnAddedDiscovery;
                if (energyConsumed || discoveryAdded)
                {
                    SaveManager saveManager =
                        SaveManager.Instance;
                    if (saveManager == null)
                    {
                        if (energyConsumed)
                        {
                            Debug.LogError(
                                "OVEN | Energy was deducted, but SaveManager is " +
                                "unavailable; the Energy state was not persisted."
                            );
                        }

                        if (discoveryAdded)
                        {
                            Debug.LogError(
                                "COLLECTION | Oven discovery was added in memory, " +
                                "but SaveManager is unavailable; it was not persisted."
                            );
                        }
                    }
                    else if (!saveManager.SaveCurrentGame())
                    {
                        if (energyConsumed)
                        {
                            Debug.LogError(
                                "OVEN | Energy was deducted, but saving the Energy " +
                                "state failed."
                            );
                        }

                        if (discoveryAdded)
                        {
                            Debug.LogError(
                                "COLLECTION | Oven discovery was added in memory, " +
                                "but the immediate save failed; a later save must retry it."
                            );
                        }
                    }
                }
            }
        }
        finally
        {
            isProcessingRequest = false;
        }

        Debug.Log(
            spawned
                ? "OVEN | Spawn request successful."
                : "OVEN | Spawn request failed."
        );
    }
}