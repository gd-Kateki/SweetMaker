using UnityEngine;

public class MergeSessionManager : MonoBehaviour
{
    public static MergeSessionManager Instance
    {
        get;
        private set;
    }

    private MergeSessionData sessionData;

    public MergeSessionData SessionData =>
        sessionData;

    public bool HasSession =>
        sessionData != null;

    // ==================================================
    // UNITY
    // ==================================================

    private void Awake()
    {
        if (Instance != null &&
            Instance != this)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this;

        DontDestroyOnLoad(gameObject);
    }

    private void OnDestroy()
    {
        if (Instance == this)
        {
            Instance = null;
        }
    }

    // ==================================================
    // SESSION
    // ==================================================

    public void SaveSession(
        MergeSessionData data)
    {
        if (data == null)
            return;

        sessionData =
            data;

        Debug.Log(
            $"MERGE SESSION SAVED | " +
            $"Board Desserts: " +
            $"{data.boardDesserts.Count} | " +
            $"Shelf Desserts: " +
            $"{data.shelfDesserts.Count} | " +
            $"Customer Orders: " +
            $"{data.customerOrders.Count} | " +
            $"Next Order ID: " +
            $"#{data.nextOrderId} | " +
            $"Next Dessert Tier: " +
            $"T{data.nextDessertTier}"
        );
    }

    public void ClearSession()
    {
        sessionData =
            null;

        Debug.Log(
            "MERGE SESSION CLEARED"
        );
    }

    // ==================================================
    // DEBUG
    // ==================================================

    [ContextMenu("Debug Session")]
    private void DebugSession()
    {
        if (!HasSession)
        {
            Debug.Log(
                "MERGE SESSION | None"
            );

            return;
        }

        Debug.Log(
            $"MERGE SESSION | " +
            $"Board Desserts: " +
            $"{sessionData.boardDesserts.Count} | " +
            $"Shelf Desserts: " +
            $"{sessionData.shelfDesserts.Count} | " +
            $"Customer Orders: " +
            $"{sessionData.customerOrders.Count} | " +
            $"Next Order ID: " +
            $"#{sessionData.nextOrderId} | " +
            $"Next Dessert Tier: " +
            $"T{sessionData.nextDessertTier}"
        );

        // ----------------------------------------------
        // BOARD
        // ----------------------------------------------

        foreach (
            BoardDessertState state
            in sessionData.boardDesserts)
        {
            if (state == null)
                continue;

            Debug.Log(
                $"SESSION BOARD | " +
                $"Cell {state.cellIndex} | " +
                $"Tier {state.dessertTier}"
            );
        }

        // ----------------------------------------------
        // SHELF
        // ----------------------------------------------

        foreach (
            ShelfDessertState state
            in sessionData.shelfDesserts)
        {
            if (state == null)
                continue;

            Debug.Log(
                $"SESSION SHELF | " +
                $"Slot {state.slotIndex} | " +
                $"Tier {state.dessertTier}"
            );
        }

        // ----------------------------------------------
        // CUSTOMER ORDERS
        // ----------------------------------------------

        foreach (
            CustomerOrderState state
            in sessionData.customerOrders)
        {
            if (state == null)
                continue;

            string definitionName =
                state.definition != null
                    ? state.definition.DisplayName
                    : "Missing Definition";

            Debug.Log(
                $"SESSION ORDER | " +
                $"Customer " +
                $"{state.customerIndex + 1} | " +
                $"Order #{state.orderId} | " +
                $"{definitionName}"
            );
        }

        // ----------------------------------------------
        // ORDER SEQUENCE
        // ----------------------------------------------

        Debug.Log(
            $"SESSION ORDER SEQUENCE | " +
            $"Next Order ID: " +
            $"#{sessionData.nextOrderId}"
        );

        // ----------------------------------------------
        // NEXT DESSERT
        // ----------------------------------------------

        Debug.Log(
            $"SESSION NEXT DESSERT | " +
            $"Tier " +
            $"{sessionData.nextDessertTier}"
        );
    }
}