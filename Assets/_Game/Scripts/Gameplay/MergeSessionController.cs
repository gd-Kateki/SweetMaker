using System.Collections;
using UnityEngine;

public class MergeSessionController : MonoBehaviour
{
    [Header("References")]
    [SerializeField]
    private GridManager gridManager;

    [SerializeField]
    private ShelfManager shelfManager;

    [SerializeField]
    private DessertSpawner dessertSpawner;

    [SerializeField]
    private OrderManager orderManager;

    private bool hasRestoredAutomatically;

    // ==================================================
    // UNITY
    // ==================================================

    private IEnumerator Start()
    {
        /*
         * Wait until the next frame so the normal
         * gameplay Start() initialization has
         * completed before restoring saved state.
         */
        yield return null;

        TryRestoreSessionAutomatically();
    }

    // ==================================================
    // AUTOMATIC RESTORATION
    // ==================================================

    private void TryRestoreSessionAutomatically()
    {
        if (hasRestoredAutomatically)
            return;

        if (MergeSessionManager.Instance == null)
        {
            Debug.Log(
                "AUTO RESTORE | " +
                "MergeSessionManager does not exist."
            );

            return;
        }

        if (!MergeSessionManager.Instance.HasSession)
        {
            Debug.Log(
                "AUTO RESTORE | " +
                "No existing merge session. " +
                "Starting a fresh game."
            );

            return;
        }

        hasRestoredAutomatically =
            true;

        Debug.Log(
            "AUTO RESTORE | " +
            "Saved merge session found."
        );

        RestoreSession();

        Debug.Log(
            "AUTO RESTORE | " +
            "Merge session restoration complete."
        );
    }

    // ==================================================
    // CAPTURE
    // ==================================================

    public void CaptureSession()
    {
        ResolveReferences();

        if (gridManager == null ||
            shelfManager == null ||
            dessertSpawner == null ||
            orderManager == null)
        {
            Debug.LogError(
                "MergeSessionController: " +
                "Cannot capture session because " +
                "a required gameplay reference " +
                "is missing."
            );

            return;
        }

        if (MergeSessionManager.Instance == null)
        {
            Debug.LogError(
                "MergeSessionController: " +
                "MergeSessionManager does not exist."
            );

            return;
        }

        MergeSessionData data =
            new MergeSessionData();

        CaptureBoard(data);
        CaptureShelf(data);
        CaptureOrders(data);
        CaptureNextDessert(data);

        MergeSessionManager.Instance
            .SaveSession(data);
    }

    // ==================================================
    // CAPTURE BOARD
    // ==================================================

    private void CaptureBoard(
        MergeSessionData data)
    {
        var cells =
            gridManager.Cells;

        for (int i = 0;
             i < cells.Count;
             i++)
        {
            GridCell cell =
                cells[i];

            if (cell == null ||
                cell.IsEmpty)
            {
                continue;
            }

            Dessert dessert =
                cell.CurrentDessert;

            if (dessert == null ||
                dessert.Definition == null)
            {
                continue;
            }

            data.boardDesserts.Add(
                new BoardDessertState(
                    i,
                    dessert.Definition.Tier
                )
            );
        }
    }

    // ==================================================
    // CAPTURE SHELF
    // ==================================================

    private void CaptureShelf(
        MergeSessionData data)
    {
        var slots =
            shelfManager.Slots;

        for (int i = 0;
             i < slots.Count;
             i++)
        {
            ShelfSlot slot =
                slots[i];

            if (slot == null ||
                slot.IsEmpty)
            {
                continue;
            }

            Dessert dessert =
                slot.CurrentDessert;

            if (dessert == null ||
                dessert.Definition == null)
            {
                continue;
            }

            data.shelfDesserts.Add(
                new ShelfDessertState(
                    i,
                    dessert.Definition.Tier
                )
            );
        }
    }

    // ==================================================
    // CAPTURE ORDERS
    // ==================================================

    private void CaptureOrders(
        MergeSessionData data)
    {
        var orders =
            orderManager.CustomerOrders;

        for (int i = 0;
             i < orders.Count;
             i++)
        {
            CustomerOrder order =
                orders[i];

            if (order == null ||
                !order.IsValid ||
                order.Definition == null)
            {
                continue;
            }

            data.customerOrders.Add(
                new CustomerOrderState(
                    i,
                    order.OrderId,
                    order.Definition
                )
            );
        }

        data.nextOrderId =
            orderManager.NextOrderId;
    }

    // ==================================================
    // CAPTURE NEXT DESSERT
    // ==================================================

    private void CaptureNextDessert(
        MergeSessionData data)
    {
        DessertDefinition nextDessert =
            dessertSpawner.NextDessert;

        if (nextDessert == null)
        {
            data.nextDessertTier =
                -1;

            Debug.LogWarning(
                "SESSION CAPTURE | " +
                "No Next Dessert currently exists."
            );

            return;
        }

        data.nextDessertTier =
            nextDessert.Tier;

        Debug.Log(
            $"SESSION NEXT DESSERT CAPTURED | " +
            $"{nextDessert.DisplayName} | " +
            $"Tier {nextDessert.Tier}"
        );
    }

    // ==================================================
    // RESTORE
    // ==================================================

    public void RestoreSession()
    {
        ResolveReferences();

        if (gridManager == null ||
            shelfManager == null ||
            dessertSpawner == null ||
            orderManager == null)
        {
            Debug.LogError(
                "MergeSessionController: " +
                "Cannot restore session because " +
                "a required gameplay reference " +
                "is missing."
            );

            return;
        }

        if (MergeSessionManager.Instance == null)
        {
            Debug.LogWarning(
                "RESTORE SKIPPED | " +
                "MergeSessionManager does not exist."
            );

            return;
        }

        if (!MergeSessionManager.Instance.HasSession)
        {
            Debug.Log(
                "RESTORE SKIPPED | " +
                "No saved merge session exists."
            );

            return;
        }

        MergeSessionData data =
            MergeSessionManager.Instance
                .SessionData;

        if (data == null)
        {
            Debug.LogWarning(
                "RESTORE SKIPPED | " +
                "Session data is null."
            );

            return;
        }

        RestoreBoard(data);
        RestoreShelf(data);
        RestoreOrders(data);
        RestoreNextDessert(data);

        gridManager.NotifyBoardChanged();
        shelfManager.NotifyShelfChanged();

        Debug.Log(
            $"MERGE SESSION RESTORED | " +
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

    // ==================================================
    // RESTORE BOARD
    // ==================================================

    private void RestoreBoard(
        MergeSessionData data)
    {
        var cells =
            gridManager.Cells;

        foreach (
            BoardDessertState state
            in data.boardDesserts)
        {
            if (state == null)
                continue;

            if (state.cellIndex < 0 ||
                state.cellIndex >= cells.Count)
            {
                Debug.LogWarning(
                    $"RESTORE BOARD SKIPPED | " +
                    $"Invalid Cell Index " +
                    $"{state.cellIndex}."
                );

                continue;
            }

            GridCell cell =
                cells[state.cellIndex];

            if (cell == null)
                continue;

            if (!cell.IsUnlocked)
            {
                Debug.LogWarning(
                    $"RESTORE BOARD SKIPPED | " +
                    $"Cell {state.cellIndex} " +
                    "is currently locked."
                );

                continue;
            }

            if (!cell.IsEmpty)
            {
                Debug.LogWarning(
                    $"RESTORE BOARD SKIPPED | " +
                    $"Cell {state.cellIndex} " +
                    "is already occupied."
                );

                continue;
            }

            Dessert dessert =
                dessertSpawner
                    .SpawnDessertOnBoardForRestore(
                        state.dessertTier,
                        cell
                    );

            if (dessert == null)
            {
                Debug.LogWarning(
                    $"RESTORE BOARD FAILED | " +
                    $"Cell {state.cellIndex} | " +
                    $"Tier {state.dessertTier}"
                );

                continue;
            }

            Debug.Log(
                $"RESTORE BOARD | " +
                $"Cell {state.cellIndex} | " +
                $"Tier {state.dessertTier}"
            );
        }
    }

    // ==================================================
    // RESTORE SHELF
    // ==================================================

    private void RestoreShelf(
        MergeSessionData data)
    {
        var slots =
            shelfManager.Slots;

        foreach (
            ShelfDessertState state
            in data.shelfDesserts)
        {
            if (state == null)
                continue;

            if (state.slotIndex < 0 ||
                state.slotIndex >= slots.Count)
            {
                Debug.LogWarning(
                    $"RESTORE SHELF SKIPPED | " +
                    $"Invalid Slot Index " +
                    $"{state.slotIndex}."
                );

                continue;
            }

            ShelfSlot slot =
                slots[state.slotIndex];

            if (slot == null)
                continue;

            if (!slot.IsUnlocked)
            {
                Debug.LogWarning(
                    $"RESTORE SHELF SKIPPED | " +
                    $"Slot {state.slotIndex} " +
                    "is currently locked."
                );

                continue;
            }

            if (!slot.IsEmpty)
            {
                Debug.LogWarning(
                    $"RESTORE SHELF SKIPPED | " +
                    $"Slot {state.slotIndex} " +
                    "is already occupied."
                );

                continue;
            }

            Dessert dessert =
                dessertSpawner
                    .SpawnDessertOnShelfForRestore(
                        state.dessertTier,
                        slot
                    );

            if (dessert == null)
            {
                Debug.LogWarning(
                    $"RESTORE SHELF FAILED | " +
                    $"Slot {state.slotIndex} | " +
                    $"Tier {state.dessertTier}"
                );

                continue;
            }

            Debug.Log(
                $"RESTORE SHELF | " +
                $"Slot {state.slotIndex} | " +
                $"Tier {state.dessertTier}"
            );
        }
    }

    // ==================================================
    // RESTORE ORDERS
    // ==================================================

    private void RestoreOrders(
        MergeSessionData data)
    {
        orderManager.RestoreCustomerOrders(
            data.customerOrders,
            data.nextOrderId
        );
    }

    // ==================================================
    // RESTORE NEXT DESSERT
    // ==================================================

    private void RestoreNextDessert(
        MergeSessionData data)
    {
        if (data.nextDessertTier <= 0)
        {
            Debug.LogWarning(
                "NEXT DESSERT RESTORE SKIPPED | " +
                "No valid saved Next Dessert exists."
            );

            return;
        }

        dessertSpawner.RestoreNextDessert(
            data.nextDessertTier
        );
    }

    // ==================================================
    // REFERENCES
    // ==================================================

    private void ResolveReferences()
    {
        if (gridManager == null)
        {
            gridManager =
                FindFirstObjectByType<
                    GridManager>();
        }

        if (shelfManager == null)
        {
            shelfManager =
                FindFirstObjectByType<
                    ShelfManager>();
        }

        if (dessertSpawner == null)
        {
            dessertSpawner =
                FindFirstObjectByType<
                    DessertSpawner>();
        }

        if (orderManager == null)
        {
            orderManager =
                FindFirstObjectByType<
                    OrderManager>();
        }
    }

    // ==================================================
    // DEBUG
    // ==================================================

    [ContextMenu("Debug Capture Session")]
    private void DebugCaptureSession()
    {
        CaptureSession();
    }

    [ContextMenu("Debug Restore Session")]
    private void DebugRestoreSession()
    {
        RestoreSession();
    }
}