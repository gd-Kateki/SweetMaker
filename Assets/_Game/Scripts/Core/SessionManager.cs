using System;
using UnityEngine;

public class SessionManager : MonoBehaviour
{
    public static SessionManager Instance
    {
        get;
        private set;
    }

    public event Action SessionStatsChanged;

    [Header("Session Statistics")]
    [SerializeField]
    private int ovenSpawns;

    [SerializeField]
    private int successfulMoves;

    [SerializeField]
    private int successfulMerges;

    [SerializeField]
    private int highestTierReached;

    public int OvenSpawns =>
        ovenSpawns;

    public int SuccessfulMoves =>
        successfulMoves;

    public int SuccessfulMerges =>
        successfulMerges;

    public int HighestTierReached =>
        highestTierReached;

    private void Awake()
    {
        if (Instance != null &&
            Instance != this)
        {
            Destroy(
                gameObject
            );

            return;
        }

        Instance = this;

        ResetSession();
    }

    private void OnEnable()
    {
        GameplayEvents.DessertSpawned +=
            HandleDessertSpawned;

        GameplayEvents.DessertMoved +=
            HandleDessertMoved;

        GameplayEvents.DessertMerged +=
            HandleDessertMerged;
    }

    private void OnDisable()
    {
        GameplayEvents.DessertSpawned -=
            HandleDessertSpawned;

        GameplayEvents.DessertMoved -=
            HandleDessertMoved;

        GameplayEvents.DessertMerged -=
            HandleDessertMerged;
    }

    private void OnDestroy()
    {
        if (Instance == this)
        {
            Instance = null;
        }
    }

    public void ResetSession()
    {
        ovenSpawns = 0;
        successfulMoves = 0;
        successfulMerges = 0;
        highestTierReached = 0;

        NotifyStatsChanged();

        Debug.Log(
            "SESSION | Session reset."
        );
    }

    private void HandleDessertSpawned(
        int spawnedTier)
    {
        ovenSpawns++;

        RegisterTier(
            spawnedTier
        );

        NotifyStatsChanged();

        Debug.Log(
            $"SESSION | Oven Spawns: " +
            $"{ovenSpawns}"
        );
    }

    private void HandleDessertMoved()
    {
        successfulMoves++;

        NotifyStatsChanged();

        Debug.Log(
            $"SESSION | Successful Moves: " +
            $"{successfulMoves}"
        );
    }

    private void HandleDessertMerged(
        int resultingTier)
    {
        successfulMerges++;

        RegisterTier(
            resultingTier
        );

        NotifyStatsChanged();

        Debug.Log(
            $"SESSION | Successful Merges: " +
            $"{successfulMerges} | " +
            $"Highest Tier: " +
            $"{highestTierReached}"
        );
    }

    private void RegisterTier(
        int tier)
    {
        if (tier <= highestTierReached)
            return;

        highestTierReached =
            tier;
    }

    private void NotifyStatsChanged()
    {
        SessionStatsChanged?.Invoke();
    }

    [ContextMenu("Debug Session Stats")]
    private void DebugSessionStats()
    {
        Debug.Log(
            $"SESSION STATS | " +
            $"Spawns: {ovenSpawns} | " +
            $"Moves: {successfulMoves} | " +
            $"Merges: {successfulMerges} | " +
            $"Highest Tier: " +
            $"{highestTierReached}"
        );
    }
}