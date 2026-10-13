using System;
using System.Collections;
using System.Collections.Generic;
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
    private bool restorationInProgress;
    private bool departurePrepared;
    public bool IsRestorationVerified { get; private set; }
    public string LastRestorationError { get; private set; }

    internal void InvalidateRestoration()
    {
        IsRestorationVerified = false;
        SaveManager.Instance?.SuspendLifecycleSaving();
    }

    private void Awake()
    {
        GameStartupCoordinator.Instance?.BeginGameplayInitialization();
        SaveManager.Instance?.SuspendLifecycleSaving();
    }

    private void OnEnable()
    {
        if (hasRestoredAutomatically)
        {
            GameStartupCoordinator.Instance?.BeginGameplayInitialization();
            StartCoroutine(RestoreAfterEnable());
        }
    }

    private IEnumerator RestoreAfterEnable()
    {
        yield return null;
        TryRestoreSession();
    }

    private void OnDisable()
    {
        bool released = departurePrepared;
        try
        {
            if (!released && IsRestorationVerified && !restorationInProgress && TryCaptureSession())
                released = GameStartupCoordinator.Instance != null &&
                    GameStartupCoordinator.Instance.ReleaseVerifiedGameplay(this);
        }
        catch (Exception exception) { FailRestoration(exception.ToString()); }
        IsRestorationVerified = false;
        if (!released) SaveManager.Instance?.SuspendLifecycleSaving();
    }

    // Call before unloading Game, while all gameplay dependencies still exist.
    public bool PrepareToLeaveGameplay()
    {
        if (!TryCaptureSession() || GameStartupCoordinator.Instance == null) return false;
        departurePrepared = GameStartupCoordinator.Instance.ReleaseVerifiedGameplay(this);
        return departurePrepared;
    }

    private bool FailRestoration(string reason)
    {
        IsRestorationVerified = false;
        LastRestorationError = reason;
        SaveManager.Instance?.SuspendLifecycleSaving();
        GameStartupCoordinator.Instance?.ReportGameplayRestorationFailure(reason);
        Debug.LogError("RESTORATION FAILED | " + reason);
        return false;
    }

    // ==================================================
    // UNITY
    // ==================================================

    private IEnumerator Start()
    {
        yield return null;
        if (GameStartupCoordinator.Instance == null)
        {
            FailRestoration("GameStartupCoordinator is missing.");
            yield break;
        }
        while (GameStartupCoordinator.Instance != null &&
               !GameStartupCoordinator.Instance.IsStartupComplete &&
               !GameStartupCoordinator.Instance.IsStartupBlocked)
            yield return null;

        // Also give consumers of restored progression a complete frame to initialize.
        yield return null;
        TryRestoreSessionAutomatically();
    }

    // ==================================================
    // AUTOMATIC RESTORATION
    // ==================================================

    private void TryRestoreSessionAutomatically()
    {
        if (hasRestoredAutomatically) return;
        hasRestoredAutomatically = TryRestoreSession();
    }

    // ==================================================
    // CAPTURE
    // ==================================================

    public void CaptureSession()
    {
        TryCaptureSession();
    }

    /// <summary>
    /// Captures the current live merge gameplay state
    /// into the persistent MergeSessionManager.
    ///
    /// Returns true only when the complete session
    /// was captured successfully.
    /// </summary>
    public bool TryCaptureSession()
    {
        if (restorationInProgress || !IsRestorationVerified ||
            GameStartupCoordinator.Instance == null ||
            !GameStartupCoordinator.Instance.IsStartupComplete)
            return false;
        if (!ValidateLiveState(out string reason))
            return FailRestoration(reason);
        ResolveReferences();

        // ----------------------------------------------
        // GAMEPLAY REFERENCES
        // ----------------------------------------------

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

            return false;
        }

        // ----------------------------------------------
        // SESSION MANAGER
        // ----------------------------------------------

        if (MergeSessionManager.Instance == null)
        {
            Debug.LogError(
                "MergeSessionController: " +
                "Cannot capture session because " +
                "MergeSessionManager does not exist."
            );

            return false;
        }

        // ----------------------------------------------
        // BUILD SESSION
        // ----------------------------------------------

        MergeSessionData data =
            new MergeSessionData();

        CaptureBoard(data);
        CaptureShelf(data);
        CaptureOrders(data);
        CaptureNextDessert(data);

        // ----------------------------------------------
        // STORE SESSION
        // ----------------------------------------------

        MergeSessionManager.Instance
            .SaveSession(data);

        Debug.Log(
            "MERGE SESSION CAPTURE COMPLETE | " +
            $"Board: {data.boardDesserts.Count} | " +
            $"Shelf: {data.shelfDesserts.Count} | " +
            $"Orders: {data.customerOrders.Count} | " +
            $"Next Order ID: #{data.nextOrderId} | " +
            $"Next Dessert: T{data.nextDessertTier}"
        );

        return true;
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
            data.nextDessertTier = -1;

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
        TryRestoreSession();
    }

    public bool TryRestoreSession()
    {
        if (restorationInProgress) return false;
        var coordinator = GameStartupCoordinator.Instance;
        if (coordinator == null || !coordinator.IsStartupComplete)
            return FailRestoration("Persistent startup has not succeeded.");

        SaveManager.Instance?.SuspendLifecycleSaving();
        IsRestorationVerified = false;
        LastRestorationError = null;
        restorationInProgress = true;
        departurePrepared = false;
        try
        {
            ResolveReferences();
            if (gridManager == null || shelfManager == null ||
                dessertSpawner == null || orderManager == null ||
                MergeSessionManager.Instance == null)
                return FailRestoration("A required gameplay reference is missing.");

            if (MergeSessionManager.Instance.HasSession)
            {
                var data = MergeSessionManager.Instance.SessionData;
                if (!ValidateExpectedState(data, out string reason))
                    return FailRestoration(reason);

                // Freeze the target before callbacks can mutate persistent state.
                string target = RestorationVerification.Fingerprint(data);
                RestoreBoard(data);
                RestoreShelf(data);
                RestoreOrders(data);
                RestoreNextDessert(data);
                gridManager.NotifyBoardChanged();
                shelfManager.NotifyShelfChanged();

                if (!ValidateLiveState(out reason)) return FailRestoration(reason);
                var actual = new MergeSessionData();
                CaptureBoard(actual);
                CaptureShelf(actual);
                CaptureOrders(actual);
                CaptureNextDessert(actual);
                if (!string.Equals(target, RestorationVerification.Fingerprint(actual),
                        StringComparison.Ordinal))
                    return FailRestoration("Live board, shelf, orders, order counter or next dessert differs from the saved session.");
            }
            else
            {
                if (!ValidateLiveState(out string reason)) return FailRestoration(reason);
                if (dessertSpawner.NextDessert == null)
                    return FailRestoration("A new game requires an initialized next dessert.");
            }

            IsRestorationVerified = true;
            if (!coordinator.ConfirmGameplayRestoration(this))
                return FailRestoration("The coordinator refused gameplay readiness.");
            hasRestoredAutomatically = true;
            Debug.Log("MERGE SESSION VERIFIED | Board, shelf, orders and next dessert are ready.");
            return true;
        }
        catch (Exception exception)
        {
            return FailRestoration(exception.ToString());
        }
        finally { restorationInProgress = false; }
    }

    private bool ValidateExpectedState(MergeSessionData data, out string reason)
    {
        reason = null;
        if (data == null || data.boardDesserts == null || data.shelfDesserts == null ||
            data.customerOrders == null || data.nextOrderId <= 0 ||
            (data.nextDessertTier != -1 && data.nextDessertTier <= 0))
        { reason = "Saved session contains missing or invalid data."; return false; }
        if (gridManager.Cells == null || shelfManager.Slots == null)
        { reason = "Board or shelf has not initialized."; return false; }
        var cells = new HashSet<int>();
        foreach (var state in data.boardDesserts)
        {
            if (state == null || state.dessertTier <= 0 || state.cellIndex < 0 ||
                state.cellIndex >= gridManager.Cells.Count || !cells.Add(state.cellIndex) ||
                gridManager.Cells[state.cellIndex] == null ||
                !gridManager.Cells[state.cellIndex].IsUnlocked)
            { reason = "Saved board contains an invalid, locked or duplicate cell."; return false; }
        }
        var slots = new HashSet<int>();
        foreach (var state in data.shelfDesserts)
        {
            if (state == null || state.dessertTier <= 0 || state.slotIndex < 0 ||
                state.slotIndex >= shelfManager.Slots.Count || !slots.Add(state.slotIndex) ||
                shelfManager.Slots[state.slotIndex] == null ||
                !shelfManager.Slots[state.slotIndex].IsUnlocked)
            { reason = "Saved shelf contains an invalid, locked or duplicate slot."; return false; }
        }
        foreach (var state in data.customerOrders)
            if (state == null)
            { reason = "Saved order is null."; return false; }
        return true;
    }

    private bool ValidateLiveState(out string reason)
    {
        reason = null;
        ResolveReferences();
        var progression = PlayerProgressionManager.Instance;
        if (gridManager == null || shelfManager == null || dessertSpawner == null ||
            orderManager == null || progression == null || gridManager.Cells == null ||
            shelfManager.Slots == null || orderManager.CustomerOrders == null)
        { reason = "Gameplay dependencies are not initialized."; return false; }
        if (!progression.ValidateRestorationDefinitions(out reason)) return false;

        var desserts = new HashSet<Dessert>();
        int unlockedCells = 0, unlockedSlots = 0, validOrders = 0;
        foreach (var cell in gridManager.Cells)
        {
            if (cell == null) { reason = "Board contains a null cell."; return false; }
            if (cell.IsUnlocked) unlockedCells++;
            var dessert = cell.CurrentDessert;
            if (cell.IsEmpty != (dessert == null) ||
                (dessert != null && (!cell.IsUnlocked || dessert.Definition == null ||
                 dessert.Definition.Tier <= 0 || !desserts.Add(dessert))))
            { reason = "Board occupancy, dessert definition or ownership is invalid."; return false; }
        }
        foreach (var slot in shelfManager.Slots)
        {
            if (slot == null) { reason = "Shelf contains a null slot."; return false; }
            if (slot.IsUnlocked) unlockedSlots++;
            var dessert = slot.CurrentDessert;
            if (slot.IsEmpty != (dessert == null) ||
                (dessert != null && (!slot.IsUnlocked || dessert.Definition == null ||
                 dessert.Definition.Tier <= 0 || !desserts.Add(dessert))))
            { reason = "Shelf occupancy, dessert definition or ownership is invalid."; return false; }
        }
        var orderIds = new HashSet<int>();
        foreach (var order in orderManager.CustomerOrders)
        {
            if (order == null) continue; // Locked customer positions may be empty.
            if (!order.IsValid || order.Definition == null || order.OrderId <= 0 ||
                !orderIds.Add(order.OrderId) || orderManager.NextOrderId <= order.OrderId)
            { reason = "Order definition, identity or next order counter is invalid."; return false; }
            validOrders++;
        }
        if (unlockedCells != progression.ActiveBoardCells ||
            unlockedSlots != progression.ShelfCapacity ||
            validOrders != progression.ActiveCustomerOrders || orderManager.NextOrderId <= 0)
        { reason = "Live capacities or active order count disagree with progression."; return false; }
        if (dessertSpawner.NextDessert != null &&
            !progression.IsDessertTierUnlocked(dessertSpawner.NextDessert.Tier))
        { reason = "Next dessert is not an unlocked tier."; return false; }
        return true;
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
                FindFirstObjectByType<GridManager>();
        }

        if (shelfManager == null)
        {
            shelfManager =
                FindFirstObjectByType<ShelfManager>();
        }

        if (dessertSpawner == null)
        {
            dessertSpawner =
                FindFirstObjectByType<DessertSpawner>();
        }

        if (orderManager == null)
        {
            orderManager =
                FindFirstObjectByType<OrderManager>();
        }
    }

    // ==================================================
    // DEBUG
    // ==================================================

    [ContextMenu("Debug Capture Session")]
    private void DebugCaptureSession()
    {
        bool success =
            TryCaptureSession();

        if (success)
        {
            Debug.Log(
                "SESSION DEBUG | " +
                "Live gameplay capture succeeded."
            );
        }
        else
        {
            Debug.LogError(
                "SESSION DEBUG | " +
                "Live gameplay capture failed."
            );
        }
    }

    [ContextMenu("Debug Restore Session")]
    private void DebugRestoreSession()
    {
        RestoreSession();
    }
}
