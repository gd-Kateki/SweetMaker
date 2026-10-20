using UnityEngine;

public class MergeSessionManager : MonoBehaviour
{
    public static MergeSessionManager Instance
    {
        get;
        private set;
    }

    // ==================================================
    // DATABASE
    // ==================================================

    [Header("Permanent Save References")]
    [SerializeField]
    private CustomerOrderDatabase customerOrderDatabase;

    // ==================================================
    // RUNTIME SESSION
    // ==================================================

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
    // PERMANENT SAVE CAPTURE
    // ==================================================

    public bool CaptureToSaveData(
        MergeGameplaySaveData saveData)
    {
        if (saveData == null)
        {
            Debug.LogError(
                "MERGE SAVE CAPTURE FAILED | " +
                "MergeGameplaySaveData is null."
            );

            return false;
        }

        // ----------------------------------------------
        // ENSURE COLLECTIONS
        // ----------------------------------------------

        if (saveData.boardDesserts == null)
        {
            saveData.boardDesserts =
                new System.Collections.Generic.List<
                    BoardDessertSaveData>();
        }

        if (saveData.shelfDesserts == null)
        {
            saveData.shelfDesserts =
                new System.Collections.Generic.List<
                    ShelfDessertSaveData>();
        }

        if (saveData.customerOrders == null)
        {
            saveData.customerOrders =
                new System.Collections.Generic.List<
                    CustomerOrderSaveData>();
        }

        // ----------------------------------------------
        // RESET DESTINATION
        // ----------------------------------------------

        saveData.boardDesserts.Clear();
        saveData.shelfDesserts.Clear();
        saveData.customerOrders.Clear();

        // ----------------------------------------------
        // NO EXISTING SESSION
        // ----------------------------------------------

        if (!HasSession ||
            sessionData == null)
        {
            saveData.hasSession =
                false;

            saveData.nextOrderId =
                1;

            saveData.nextDessertTier =
                -1;

            Debug.Log(
                "MERGE SAVE CAPTURE | " +
                "No runtime merge session exists."
            );

            return true;
        }

        // ----------------------------------------------
        // SESSION EXISTS
        // ----------------------------------------------

        saveData.hasSession =
            true;

        CaptureBoardToSaveData(
            saveData
        );

        CaptureShelfToSaveData(
            saveData
        );

        CaptureOrdersToSaveData(
            saveData
        );

        saveData.nextOrderId =
            Mathf.Max(
                1,
                sessionData.nextOrderId
            );

        saveData.nextDessertTier =
            sessionData.nextDessertTier;

        Debug.Log(
            "MERGE SAVE CAPTURE | " +
            $"Board Desserts: " +
            $"{saveData.boardDesserts.Count} | " +
            $"Shelf Desserts: " +
            $"{saveData.shelfDesserts.Count} | " +
            $"Customer Orders: " +
            $"{saveData.customerOrders.Count} | " +
            $"Next Order ID: " +
            $"#{saveData.nextOrderId} | " +
            $"Next Dessert Tier: " +
            $"T{saveData.nextDessertTier}"
        );

        return true;
    }

    // ==================================================
    // PERMANENT SAVE - BOARD
    // ==================================================

    private void CaptureBoardToSaveData(
        MergeGameplaySaveData saveData)
    {
        if (sessionData.boardDesserts ==
            null)
        {
            return;
        }

        foreach (
            BoardDessertState state
            in sessionData.boardDesserts)
        {
            if (state == null)
                continue;

            if (state.cellIndex < 0 ||
                state.dessertTier <= 0)
            {
                Debug.LogWarning(
                    "MERGE SAVE BOARD SKIPPED | " +
                    $"Cell {state.cellIndex} | " +
                    $"Tier {state.dessertTier}"
                );

                continue;
            }

            saveData.boardDesserts.Add(
                new BoardDessertSaveData(
                    state.cellIndex,
                    state.dessertTier
                )
            );
        }
    }

    // ==================================================
    // PERMANENT SAVE - SHELF
    // ==================================================

    private void CaptureShelfToSaveData(
        MergeGameplaySaveData saveData)
    {
        if (sessionData.shelfDesserts ==
            null)
        {
            return;
        }

        foreach (
            ShelfDessertState state
            in sessionData.shelfDesserts)
        {
            if (state == null)
                continue;

            if (state.slotIndex < 0 ||
                state.dessertTier <= 0)
            {
                Debug.LogWarning(
                    "MERGE SAVE SHELF SKIPPED | " +
                    $"Slot {state.slotIndex} | " +
                    $"Tier {state.dessertTier}"
                );

                continue;
            }

            saveData.shelfDesserts.Add(
                new ShelfDessertSaveData(
                    state.slotIndex,
                    state.dessertTier
                )
            );
        }
    }

    // ==================================================
    // PERMANENT SAVE - ORDERS
    // ==================================================

    private void CaptureOrdersToSaveData(
        MergeGameplaySaveData saveData)
    {
        if (sessionData.customerOrders ==
            null)
        {
            return;
        }

        foreach (
            CustomerOrderState state
            in sessionData.customerOrders)
        {
            if (state == null)
                continue;

            if (state.customerIndex < 0 ||
                state.orderId <= 0)
            {
                Debug.LogWarning(
                    "MERGE SAVE ORDER SKIPPED | " +
                    "Invalid customer index or " +
                    "order ID."
                );

                continue;
            }

            if (state.definition == null)
            {
                Debug.LogWarning(
                    "MERGE SAVE ORDER SKIPPED | " +
                    $"Customer " +
                    $"{state.customerIndex + 1} | " +
                    $"Order #{state.orderId} | " +
                    "Missing definition."
                );

                continue;
            }

            string definitionId =
                state.definition.DefinitionId;

            if (string.IsNullOrWhiteSpace(
                    definitionId))
            {
                Debug.LogWarning(
                    "MERGE SAVE ORDER SKIPPED | " +
                    $"Customer " +
                    $"{state.customerIndex + 1} | " +
                    $"Order #{state.orderId} | " +
                    "Definition has no stable ID."
                );

                continue;
            }

            saveData.customerOrders.Add(
                new CustomerOrderSaveData(
                    state.customerIndex,
                    state.orderId,
                    definitionId
                )
            );
        }
    }

    // ==================================================
    // PERMANENT SAVE RESTORE
    // ==================================================

    public bool RestoreFromSaveData(
        MergeGameplaySaveData saveData)
    {
        if (saveData == null)
        {
            Debug.LogError(
                "MERGE SAVE RESTORE FAILED | " +
                "MergeGameplaySaveData is null."
            );

            return false;
        }

        // ----------------------------------------------
        // NO SAVED SESSION
        // ----------------------------------------------

        if (!saveData.hasSession)
        {
            ClearSession();

            Debug.Log(
                "MERGE SAVE RESTORE | " +
                "Save contains no merge session."
            );

            return true;
        }

        // ----------------------------------------------
        // DATABASE
        // ----------------------------------------------

        if (customerOrderDatabase == null)
        {
            Debug.LogError(
                "MERGE SAVE RESTORE FAILED | " +
                "CustomerOrderDatabase is not assigned."
            );

            return false;
        }

        // ----------------------------------------------
        // BUILD RUNTIME SESSION
        // ----------------------------------------------

        MergeSessionData restoredData =
            new MergeSessionData();

        RestoreBoardFromSaveData(
            saveData,
            restoredData
        );

        RestoreShelfFromSaveData(
            saveData,
            restoredData
        );

        if (!RestoreOrdersFromSaveData(
            saveData,
            restoredData
        ))
        {
            return false;
        }

        restoredData.nextOrderId =
            Mathf.Max(
                1,
                saveData.nextOrderId
            );

        restoredData.nextDessertTier =
            saveData.nextDessertTier;

        // ----------------------------------------------
        // STORE RUNTIME SESSION
        // ----------------------------------------------

        SaveSession(
            restoredData
        );

        Debug.Log(
            "MERGE SAVE RESTORE | " +
            $"Board Desserts: " +
            $"{restoredData.boardDesserts.Count} | " +
            $"Shelf Desserts: " +
            $"{restoredData.shelfDesserts.Count} | " +
            $"Customer Orders: " +
            $"{restoredData.customerOrders.Count} | " +
            $"Next Order ID: " +
            $"#{restoredData.nextOrderId} | " +
            $"Next Dessert Tier: " +
            $"T{restoredData.nextDessertTier}"
        );

        return true;
    }

    // ==================================================
    // PERMANENT RESTORE - BOARD
    // ==================================================

    private void RestoreBoardFromSaveData(
        MergeGameplaySaveData saveData,
        MergeSessionData restoredData)
    {
        if (saveData.boardDesserts ==
            null)
        {
            return;
        }

        foreach (
            BoardDessertSaveData state
            in saveData.boardDesserts)
        {
            if (state == null)
                continue;

            if (state.cellIndex < 0 ||
                state.dessertTier <= 0)
            {
                Debug.LogWarning(
                    "MERGE LOAD BOARD SKIPPED | " +
                    $"Cell {state.cellIndex} | " +
                    $"Tier {state.dessertTier}"
                );

                continue;
            }

            restoredData.boardDesserts.Add(
                new BoardDessertState(
                    state.cellIndex,
                    state.dessertTier
                )
            );
        }
    }

    // ==================================================
    // PERMANENT RESTORE - SHELF
    // ==================================================

    private void RestoreShelfFromSaveData(
        MergeGameplaySaveData saveData,
        MergeSessionData restoredData)
    {
        if (saveData.shelfDesserts ==
            null)
        {
            return;
        }

        foreach (
            ShelfDessertSaveData state
            in saveData.shelfDesserts)
        {
            if (state == null)
                continue;

            if (state.slotIndex < 0 ||
                state.dessertTier <= 0)
            {
                Debug.LogWarning(
                    "MERGE LOAD SHELF SKIPPED | " +
                    $"Slot {state.slotIndex} | " +
                    $"Tier {state.dessertTier}"
                );

                continue;
            }

            restoredData.shelfDesserts.Add(
                new ShelfDessertState(
                    state.slotIndex,
                    state.dessertTier
                )
            );
        }
    }

    // ==================================================
    // PERMANENT RESTORE - ORDERS
    // ==================================================

    private bool RestoreOrdersFromSaveData(
        MergeGameplaySaveData saveData,
        MergeSessionData restoredData)
    {
        if (saveData.customerOrders ==
            null)
        {
            Debug.LogError("MERGE SAVE RESTORE FAILED | Saved customer orders are missing.");
            return false;
        }

        foreach (
            CustomerOrderSaveData state
            in saveData.customerOrders)
        {
            if (state == null)
            {
                Debug.LogError("MERGE SAVE RESTORE FAILED | Saved customer order is null.");
                return false;
            }

            if (state.customerIndex < 0 ||
                state.orderId <= 0 ||
                string.IsNullOrWhiteSpace(
                    state.definitionId))
            {
                Debug.LogError(
                    "MERGE SAVE RESTORE FAILED | " +
                    "Invalid saved order data."
                );

                return false;
            }

            if (!customerOrderDatabase.TryGetById(
                    state.definitionId,
                    out CustomerOrderDefinition definition))
            {
                Debug.LogError(
                    "MERGE SAVE RESTORE FAILED | " +
                    $"Customer " +
                    $"{state.customerIndex + 1} | " +
                    $"Order #{state.orderId} | " +
                    $"Unknown Definition ID: " +
                    $"{state.definitionId}"
                );

                return false;
            }

            restoredData.customerOrders.Add(
                new CustomerOrderState(
                    state.customerIndex,
                    state.orderId,
                    definition
                )
            );

            Debug.Log(
                "MERGE LOAD ORDER | " +
                $"Customer " +
                $"{state.customerIndex + 1} | " +
                $"Order #{state.orderId} | " +
                $"{definition.DisplayName}"
            );
        }
        return true;
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

    [ContextMenu("Debug Permanent Save Capture")]
    private void DebugPermanentSaveCapture()
    {
        MergeGameplaySaveData saveData =
            new MergeGameplaySaveData();

        if (!CaptureToSaveData(
                saveData))
        {
            Debug.LogError(
                "MERGE SAVE DEBUG | " +
                "Capture failed."
            );

            return;
        }

        Debug.Log(
            "========== MERGE SAVE CAPTURE ==========\n" +
            $"Has Session: {saveData.hasSession}\n" +
            $"Board Desserts: " +
            $"{saveData.boardDesserts.Count}\n" +
            $"Shelf Desserts: " +
            $"{saveData.shelfDesserts.Count}\n" +
            $"Customer Orders: " +
            $"{saveData.customerOrders.Count}\n" +
            $"Next Order ID: " +
            $"{saveData.nextOrderId}\n" +
            $"Next Dessert Tier: " +
            $"{saveData.nextDessertTier}\n" +
            "========================================"
        );

        foreach (
            BoardDessertSaveData state
            in saveData.boardDesserts)
        {
            Debug.Log(
                "MERGE SAVE BOARD | " +
                $"Cell {state.cellIndex} | " +
                $"Tier {state.dessertTier}"
            );
        }

        foreach (
            ShelfDessertSaveData state
            in saveData.shelfDesserts)
        {
            Debug.Log(
                "MERGE SAVE SHELF | " +
                $"Slot {state.slotIndex} | " +
                $"Tier {state.dessertTier}"
            );
        }

        foreach (
            CustomerOrderSaveData state
            in saveData.customerOrders)
        {
            Debug.Log(
                "MERGE SAVE ORDER | " +
                $"Customer " +
                $"{state.customerIndex + 1} | " +
                $"Order #{state.orderId} | " +
                $"Definition ID: " +
                $"{state.definitionId}"
            );
        }
    }

    // ==================================================
    // DEBUG PERMANENT ROUND TRIP
    // ==================================================

    [ContextMenu("Debug Permanent Round Trip")]
    private void DebugPermanentRoundTrip()
    {
        if (!HasSession)
        {
            Debug.LogWarning(
                "MERGE SAVE DEBUG | " +
                "No runtime session exists. " +
                "Capture gameplay first."
            );

            return;
        }

        MergeGameplaySaveData saveData =
            new MergeGameplaySaveData();

        if (!CaptureToSaveData(
                saveData))
        {
            Debug.LogError(
                "MERGE SAVE DEBUG | " +
                "Permanent capture failed."
            );

            return;
        }

        ClearSession();

        if (HasSession)
        {
            Debug.LogError(
                "MERGE SAVE DEBUG | " +
                "Session failed to clear."
            );

            return;
        }

        if (!RestoreFromSaveData(
                saveData))
        {
            Debug.LogError(
                "MERGE SAVE DEBUG | " +
                "Permanent restore failed."
            );

            return;
        }

        Debug.Log(
            "MERGE SAVE DEBUG | " +
            "Permanent round trip completed."
        );

        DebugSession();
    }
}
