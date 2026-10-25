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
                if (!progression.TryConsumeEnergy())
                {
                    Debug.LogError(
                        "OVEN | Dessert spawned, but Energy could not be " +
                        "deducted after the successful request."
                    );
                }
                else if (SaveManager.Instance == null)
                {
                    Debug.LogError(
                        "OVEN | Energy was deducted, but SaveManager is " +
                        "unavailable; the Energy state was not persisted."
                    );
                }
                else if (!SaveManager.Instance.SaveCurrentGame())
                {
                    Debug.LogError(
                        "OVEN | Energy was deducted, but saving the Energy " +
                        "state failed."
                    );
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