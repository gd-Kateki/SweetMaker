using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class OrderManager : MonoBehaviour
{
    private const int MaxCustomerSlots = 4;
    [Header("References")]
    [SerializeField]
    private GridManager gridManager;
    [SerializeField]
    private PlayerProgressionManager
        progressionManager;
    [Header("Order Pool")]
    [SerializeField]
    private CustomerOrderDefinition[] orderPool;
    // --------------------------------------------------
    // RUNTIME STATE
    // --------------------------------------------------
    // IMPORTANT:
    // This list always contains exactly four entries.
    //
    // Index 0 = Customer 1
    // Index 1 = Customer 2
    // Index 2 = Customer 3
    // Index 3 = Customer 4
    //
    // Locked / inactive slots contain null.
    private readonly List<CustomerOrder>
        customerOrders =
            new List<CustomerOrder>(
                MaxCustomerSlots
            );
    private readonly List<CustomerOrderDefinition>
        recentOrderDefinitions =
            new List<CustomerOrderDefinition>();
    private int nextOrderId = 1;
    private bool isFulfilling;
    // --------------------------------------------------
    // EVENTS
    // --------------------------------------------------
    public event Action
        ActiveOrderChanged;
    public event Action
        OrderStateChanged;
    public event Action
        ActiveOrdersChanged;
    public event Action<
        int,
        CustomerOrder>
        CustomerOrderChanged;
    public event Action<CustomerOrder>
        OrderFulfillmentStarted;
    public event Action<CustomerOrder>
        OrderCompleted;
    public event Action<CustomerOrder>
        OrderGenerated;
    // --------------------------------------------------
    // PUBLIC STATE
    // --------------------------------------------------
    public IReadOnlyList<CustomerOrder>
        CustomerOrders =>
            customerOrders;
    public int NextOrderId =>
    nextOrderId;
    // Alias useful for UI/general systems.
    public IReadOnlyList<CustomerOrder>
        ActiveOrders =>
            customerOrders;
    public int ActiveCustomerCount
    {
        get
        {
            if (progressionManager == null)
                return 1;
            return Mathf.Clamp(
                progressionManager
                    .ActiveCustomerOrders,
                1,
                MaxCustomerSlots
            );
        }
    }
    public int ActiveOrderCount
    {
        get
        {
            int count = 0;
            for (int i = 0;
                 i < ActiveCustomerCount;
                 i++)
            {
                if (customerOrders.Count > i &&
                    customerOrders[i] != null)
                {
                    count++;
                }
            }
            return count;
        }
    }
    public bool IsFulfilling =>
        isFulfilling;
    // --------------------------------------------------
    // TEMPORARY LEGACY COMPATIBILITY
    // --------------------------------------------------
    //
    // Existing single-order UI still sees
    // Customer 1 until we replace that UI.
    // --------------------------------------------------
    public CustomerOrder ActiveOrder =>
        GetOrderForCustomer(0);
    public bool HasActiveOrder =>
        ActiveOrder != null &&
        ActiveOrder.IsValid;
    public bool CanFulfillActiveOrder =>
        CanFulfillOrderAtIndex(0);
    // ==================================================
    // UNITY
    // ==================================================
    private void Awake()
    {
        InitializeCustomerSlots();
    }
    private IEnumerator Start()
    {
        // Do not consume IDs before persistent loading decides whether a session exists.
        yield return null;
        var coordinator = GameStartupCoordinator.Instance;
        while (coordinator != null && !coordinator.IsStartupComplete && !coordinator.IsStartupBlocked)
            yield return null;
        if (coordinator == null || !coordinator.IsStartupComplete) yield break;
        ResolveReferences();
        if (gridManager == null)
        {
            Debug.LogError(
                "OrderManager: GridManager " +
                "could not be found."
            );
            yield break;
        }
        if (progressionManager == null)
        {
            Debug.LogError(
                "OrderManager: " +
                "PlayerProgressionManager " +
                "could not be found."
            );
            yield break;
        }
        gridManager.BoardChanged +=
            HandleBoardChanged;
        progressionManager
            .UpgradeLevelChanged +=
                HandleUpgradeLevelChanged;
        // Saved orders belong to the restoration transaction; do not generate provisional IDs.
        if (MergeSessionManager.Instance == null || !MergeSessionManager.Instance.HasSession)
            RefreshCustomerSlots();
    }
    private void OnDestroy()
    {
        if (gridManager != null)
        {
            gridManager.BoardChanged -=
                HandleBoardChanged;
        }
        if (progressionManager != null)
        {
            progressionManager
                .UpgradeLevelChanged -=
                    HandleUpgradeLevelChanged;
        }
    }
    private void ResolveReferences()
{
    if (gridManager == null)
    {
        gridManager =
            FindFirstObjectByType<
                GridManager>();
    }
    /*
     * Always prefer the persistent progression
     * singleton carrying the player's purchased
     * upgrade levels.
     */
    if (PlayerProgressionManager.Instance != null)
    {
        progressionManager =
            PlayerProgressionManager.Instance;
    }
    else if (progressionManager == null)
    {
        progressionManager =
            FindFirstObjectByType<
                PlayerProgressionManager>();
    }
}
    private void InitializeCustomerSlots()
    {
        customerOrders.Clear();
        for (int i = 0;
             i < MaxCustomerSlots;
             i++)
        {
            customerOrders.Add(
                null
            );
        }
    }
    // ==================================================
    // CUSTOMER SLOTS
    // ==================================================
    public bool IsCustomerUnlocked(
        int customerIndex)
    {
        if (customerIndex < 0 ||
            customerIndex >=
                MaxCustomerSlots)
        {
            return false;
        }
        return customerIndex <
            ActiveCustomerCount;
    }
    public CustomerOrder GetOrderForCustomer(
        int customerIndex)
    {
        if (customerIndex < 0 ||
            customerIndex >=
                customerOrders.Count)
        {
            return null;
        }
        return customerOrders[
            customerIndex
        ];
    }
    private void RefreshCustomerSlots()
    {
        var controller = FindFirstObjectByType<MergeSessionController>();
        if (MergeSessionManager.Instance != null && MergeSessionManager.Instance.HasSession &&
            (controller == null || !controller.IsRestorationVerified)) return;
        int activeCustomers =
            ActiveCustomerCount;
        for (int i = 0;
             i < MaxCustomerSlots;
             i++)
        {
            if (i < activeCustomers)
            {
                // Already has an active order.
                // Never reroll it merely because
                // progression changed.
                if (customerOrders[i] != null)
                    continue;
                GenerateOrderForCustomer(
                    i
                );
            }
            else
            {
                // Progression currently only goes
                // upward, so normally these remain
                // null forever until unlocked.
                if (customerOrders[i] != null)
                {
                    Debug.LogWarning(
                        $"OrderManager: Customer " +
                        $"{i + 1} is locked but " +
                        "still has an order."
                    );
                }
            }
        }
        NotifyOrderCollectionsChanged();
    }
    // ==================================================
// SESSION RESTORATION
// ==================================================
// Validate every row before changing live state. Absent slots are not corrupt rows.
public bool ValidateSavedOrders(IReadOnlyList<CustomerOrderState> savedOrders,
    int savedNextOrderId, int savedCapacity, out string reason)
{
    ResolveReferences();
    reason = null;
    if (savedOrders == null || savedCapacity < 1 || savedCapacity > ActiveCustomerCount ||
        savedOrders.Count != savedCapacity || savedNextOrderId <= 0)
    { reason = "Saved customer capacity or order count is invalid."; return false; }
    var slots = new HashSet<int>();
    var ids = new HashSet<int>();
    foreach (var state in savedOrders)
    {
        if (state == null || state.customerIndex < 0 || state.customerIndex >= savedCapacity ||
            !slots.Add(state.customerIndex) || state.definition == null || !state.definition.IsValid ||
            state.orderId <= 0 || !ids.Add(state.orderId) || state.orderId >= savedNextOrderId)
        { reason = "Saved order has an invalid definition, slot, identity or counter."; return false; }
    }
    // Count plus unique indices in [0, savedCapacity) proves a complete prefix.
    return true;
}

// Compatibility entry point: no capacity expansion may be inferred from missing rows.
public bool RestoreCustomerOrders(IReadOnlyList<CustomerOrderState> savedOrders, int savedNextOrderId)
{
    ResolveReferences();
    return RestoreCustomerOrders(savedOrders, savedNextOrderId, ActiveCustomerCount);
}

public bool RestoreCustomerOrders(IReadOnlyList<CustomerOrderState> savedOrders,
    int savedNextOrderId, int savedCapacity)
{
    if (!ValidateSavedOrders(savedOrders, savedNextOrderId, savedCapacity, out string reason))
    { Debug.LogError("ORDER RESTORE FAILED | " + reason); return false; }
    if (nextOrderId > savedNextOrderId)
    { Debug.LogError("ORDER RESTORE FAILED | Restoring would rewind the live order counter."); return false; }
    var restored = new CustomerOrder[MaxCustomerSlots];
    foreach (var state in savedOrders)
        restored[state.customerIndex] = new CustomerOrder(state.orderId, state.definition);
    InitializeCustomerSlots();
    recentOrderDefinitions.Clear();
    nextOrderId = savedNextOrderId;
    isFulfilling = false;
    for (int i = 0; i < savedCapacity; i++)
    {
        customerOrders[i] = restored[i];
        TrackRecentDefinition(restored[i].Definition);
        CustomerOrderChanged?.Invoke(i, restored[i]);
    }
    NotifyOrderCollectionsChanged();
    return true;
}

// Only called after exact saved-state verification by the session controller.
public bool ExpandRestoredCustomerCapacity(int savedCapacity)
{
    if (savedCapacity < 1 || savedCapacity > ActiveCustomerCount) return false;
    int missing = ActiveCustomerCount - savedCapacity;
    if ((long)nextOrderId + missing > int.MaxValue) return false;
    for (int i = 0; i < savedCapacity; i++)
        if (customerOrders[i] == null) return false;
    for (int i = savedCapacity; i < MaxCustomerSlots; i++)
        if (customerOrders[i] != null) return false;
    for (int i = savedCapacity; i < ActiveCustomerCount; i++)
        if (!GenerateOrderForCustomer(i)) return false;
    NotifyOrderCollectionsChanged();
    return true;
}

    // ==================================================
    // ORDER GENERATION
    // ==================================================
    private bool GenerateOrderForCustomer(
        int customerIndex)
    {
        if (!IsCustomerUnlocked(
                customerIndex))
        {
            return false;
        }
        if (nextOrderId <= 0 || nextOrderId == int.MaxValue)
        {
            Debug.LogError("ORDER GENERATION FAILED | Order ID sequence exhausted.");
            return false;
        }
        CustomerOrderDefinition definition =
            GetRandomValidOrder();
        if (definition == null)
        {
            Debug.LogWarning(
                $"OrderManager: Could not " +
                $"generate an order for " +
                $"Customer {customerIndex + 1}. " +
                "No valid unlocked order exists."
            );
            return false;
        }
        int orderId =
            nextOrderId;
        nextOrderId++;
        CustomerOrder newOrder =
            new CustomerOrder(
                orderId,
                definition
            );
        customerOrders[
            customerIndex
        ] = newOrder;
        TrackRecentDefinition(
            definition
        );
        Debug.Log(
            $"ORDER GENERATED | " +
            $"Customer {customerIndex + 1} | " +
            $"Order #{newOrder.OrderId} | " +
            $"{newOrder.DisplayName}"
        );
        OrderGenerated?.Invoke(
            newOrder
        );
        CustomerOrderChanged?.Invoke(
            customerIndex,
            newOrder
        );
        return true;
    }
    // --------------------------------------------------
    // MANUAL GENERATION
    // --------------------------------------------------
    public bool GenerateNewOrderForCustomer(
        int customerIndex)
    {
        if (isFulfilling)
            return false;
        if (!IsCustomerUnlocked(
                customerIndex))
        {
            Debug.Log(
                $"ORDER | Customer " +
                $"{customerIndex + 1} " +
                "is not unlocked."
            );
            return false;
        }
        if (GetOrderForCustomer(
                customerIndex) != null)
        {
            Debug.Log(
                $"ORDER | Customer " +
                $"{customerIndex + 1} " +
                "already has an active order."
            );
            return false;
        }
        bool generated =
            GenerateOrderForCustomer(
                customerIndex
            );
        if (generated)
        {
            NotifyOrderCollectionsChanged();
        }
        return generated;
    }
    // Temporary compatibility with older
    // prototype/debug code.
    public void GenerateNewOrder()
    {
        GenerateNewOrderForCustomer(
            0
        );
    }
    // ==================================================
    // ORDER POOL
    // ==================================================
    private CustomerOrderDefinition
        GetRandomValidOrder()
    {
        if (orderPool == null ||
            orderPool.Length == 0)
        {
            return null;
        }
        List<CustomerOrderDefinition>
            eligibleOrders =
                new List<CustomerOrderDefinition>();
        foreach (
            CustomerOrderDefinition definition
            in orderPool)
        {
            if (definition == null)
                continue;
            if (!definition.IsValid)
                continue;
            if (!IsOrderUnlocked(
                    definition))
            {
                continue;
            }
            eligibleOrders.Add(
                definition
            );
        }
        if (eligibleOrders.Count == 0)
            return null;
        // ----------------------------------------------
        // Prefer definitions that are not currently
        // being used by another customer.
        // ----------------------------------------------
        if (eligibleOrders.Count > 1)
        {
            List<CustomerOrderDefinition>
                unusedOrders =
                    new List<
                        CustomerOrderDefinition>();
            foreach (
                CustomerOrderDefinition definition
                in eligibleOrders)
            {
                if (!IsDefinitionCurrentlyActive(
                        definition))
                {
                    unusedOrders.Add(
                        definition
                    );
                }
            }
            if (unusedOrders.Count > 0)
            {
                eligibleOrders =
                    unusedOrders;
            }
        }
        // ----------------------------------------------
        // Also avoid very recent definitions where
        // alternatives exist.
        // ----------------------------------------------
        if (eligibleOrders.Count > 1 &&
            recentOrderDefinitions.Count > 0)
        {
            List<CustomerOrderDefinition>
                lessRecentOrders =
                    new List<
                        CustomerOrderDefinition>();
            foreach (
                CustomerOrderDefinition definition
                in eligibleOrders)
            {
                if (!recentOrderDefinitions.Contains(
                        definition))
                {
                    lessRecentOrders.Add(
                        definition
                    );
                }
            }
            if (lessRecentOrders.Count > 0)
            {
                eligibleOrders =
                    lessRecentOrders;
            }
        }
        int randomIndex =
            UnityEngine.Random.Range(
                0,
                eligibleOrders.Count
            );
        return eligibleOrders[
            randomIndex
        ];
    }
    private bool IsOrderUnlocked(
        CustomerOrderDefinition definition)
    {
        if (definition == null ||
            !definition.IsValid)
        {
            return false;
        }
        if (progressionManager == null)
            return false;
        foreach (
            OrderRequirement requirement
            in definition.Requirements)
        {
            if (requirement == null ||
                requirement.Dessert == null)
            {
                return false;
            }
            if (!progressionManager
                    .IsDessertTierUnlocked(
                        requirement
                            .Dessert
                            .Tier))
            {
                return false;
            }
        }
        return true;
    }
    private bool IsDefinitionCurrentlyActive(
        CustomerOrderDefinition definition)
    {
        foreach (
            CustomerOrder order
            in customerOrders)
        {
            if (order == null)
                continue;
            if (order.Definition ==
                definition)
            {
                return true;
            }
        }
        return false;
    }
    private void TrackRecentDefinition(
        CustomerOrderDefinition definition)
    {
        if (definition == null)
            return;
        recentOrderDefinitions.Remove(
            definition
        );
        recentOrderDefinitions.Add(
            definition
        );
        const int historyLimit = 2;
        while (
            recentOrderDefinitions.Count >
            historyLimit)
        {
            recentOrderDefinitions
                .RemoveAt(0);
        }
    }
    // ==================================================
    // FULFILLMENT
    // ==================================================
    public bool CanFulfillOrderAtIndex(
        int customerIndex)
    {
        if (isFulfilling)
            return false;
        if (gridManager == null)
            return false;
        if (!IsCustomerUnlocked(
                customerIndex))
        {
            return false;
        }
        CustomerOrder order =
            GetOrderForCustomer(
                customerIndex
            );
        if (order == null ||
            !order.IsValid)
        {
            return false;
        }
        return order.CanFulfill(
            gridManager
        );
    }
    public bool TryFulfillActiveOrder()
    {
        return TryFulfillOrderAtIndex(
            0
        );
    }
    public bool TryFulfillOrderAtIndex(
        int customerIndex)
    {
        if (isFulfilling)
            return false;
        if (gridManager == null)
        {
            Debug.LogError(
                "OrderManager: GridManager " +
                "is missing."
            );
            return false;
        }
        if (!IsCustomerUnlocked(
                customerIndex))
        {
            Debug.Log(
                $"ORDER | Customer " +
                $"{customerIndex + 1} " +
                "is locked."
            );
            return false;
        }
        CustomerOrder orderToComplete =
            GetOrderForCustomer(
                customerIndex
            );
        if (orderToComplete == null ||
            !orderToComplete.IsValid)
        {
            return false;
        }
        if (!orderToComplete
                .TryGetDessertsForFulfillment(
                    gridManager,
                    out List<Dessert>
                        dessertsToConsume))
        {
            Debug.Log(
                $"ORDER | Customer " +
                $"{customerIndex + 1} | " +
                $"Order " +
                $"#{orderToComplete.OrderId} " +
                "cannot be fulfilled yet."
            );
            return false;
        }
        isFulfilling = true;
        OrderFulfillmentStarted?.Invoke(
            orderToComplete
        );
        // ----------------------------------------------
        // CONSUME BOARD INVENTORY
        // ----------------------------------------------
        foreach (
            Dessert dessert
            in dessertsToConsume)
        {
            if (dessert == null)
                continue;
            GridCell cell =
                dessert.CurrentCell;
            if (cell != null)
            {
                cell.RemoveDessert(
                    dessert
                );
            }
            dessert.ClearLocation();
        }
        foreach (
            Dessert dessert
            in dessertsToConsume)
        {
            if (dessert != null)
            {
                Destroy(
                    dessert.gameObject
                );
            }
        }
        // ----------------------------------------------
        // CLEAR EXACT CUSTOMER SLOT
        // ----------------------------------------------
        customerOrders[
            customerIndex
        ] = null;
        CustomerOrderChanged?.Invoke(
            customerIndex,
            null
        );
        gridManager
            .NotifyBoardChanged();
        Debug.Log(
            $"ORDER COMPLETED | " +
            $"Customer {customerIndex + 1} | " +
            $"Order #{orderToComplete.OrderId} | " +
            $"{orderToComplete.DisplayName} | " +
            $"Consumed: " +
            $"{dessertsToConsume.Count}"
        );
        // EconomyManager listens to this event.
        OrderCompleted?.Invoke(
            orderToComplete
        );
        // ----------------------------------------------
        // REPLACE ONLY THIS CUSTOMER'S ORDER
        // ----------------------------------------------
        GenerateOrderForCustomer(
            customerIndex
        );
        isFulfilling = false;
        NotifyOrderCollectionsChanged();
        return true;
    }
    // ==================================================
    // BOARD STATE
    // ==================================================
    private void HandleBoardChanged()
    {
        EvaluateOrders();
    }
    private void EvaluateOrders()
    {
        if (isFulfilling)
            return;
        for (int i = 0;
             i < ActiveCustomerCount;
             i++)
        {
            CustomerOrder order =
                GetOrderForCustomer(
                    i
                );
            if (order == null)
                continue;
            bool canFulfill =
                order.CanFulfill(
                    gridManager
                );
            Debug.Log(
                $"ORDER STATE | " +
                $"Customer {i + 1} | " +
                $"Order #{order.OrderId} | " +
                $"Can Fulfill: {canFulfill}"
            );
        }
        OrderStateChanged?.Invoke();
    }
    // ==================================================
    // PROGRESSION
    // ==================================================
    private void HandleUpgradeLevelChanged(
        UpgradeType type,
        int newLevel)
    {
        if (type == UpgradeType.Oven)
        {
            Debug.Log(
                $"ORDER PROGRESSION | " +
                $"Oven Level {newLevel} | " +
                $"Maximum Order Tier: " +
                $"T{progressionManager.MaxUnlockedDessertTier}"
            );
            // Existing orders remain unchanged.
            // Only future generated orders gain
            // access to newly unlocked tiers.
            return;
        }
        if (type == UpgradeType.Customer)
        {
            Debug.Log(
                $"CUSTOMER PROGRESSION | " +
                $"Level {newLevel} | " +
                $"Active Customers: " +
                $"{ActiveCustomerCount}"
            );
            RefreshCustomerSlots();
        }
    }
    // ==================================================
    // EVENTS
    // ==================================================
    private void NotifyOrderCollectionsChanged()
    {
        ActiveOrdersChanged?.Invoke();
        // Temporary compatibility for the old
        // single-order UI.
        ActiveOrderChanged?.Invoke();
        OrderStateChanged?.Invoke();
    }
    // ==================================================
    // DEBUG
    // ==================================================
    [ContextMenu("Debug Customer Orders")]
    private void DebugCustomerOrders()
    {
        Debug.Log(
            $"CUSTOMER ORDERS | " +
            $"Customer Level: " +
            $"{progressionManager.CustomerLevel} | " +
            $"Unlocked Customers: " +
            $"{ActiveCustomerCount} | " +
            $"Next Order ID: " +
            $"#{nextOrderId}"
        );
        for (int i = 0;
             i < MaxCustomerSlots;
             i++)
        {
            bool unlocked =
                IsCustomerUnlocked(i);
            CustomerOrder order =
                GetOrderForCustomer(i);
            if (!unlocked)
            {
                Debug.Log(
                    $"CUSTOMER {i + 1} | LOCKED"
                );
                continue;
            }
            if (order == null)
            {
                Debug.Log(
                    $"CUSTOMER {i + 1} | " +
                    "UNLOCKED | No Active Order"
                );
                continue;
            }
            Debug.Log(
                $"CUSTOMER {i + 1} | " +
                $"Order #{order.OrderId} | " +
                $"{order.DisplayName} | " +
                $"Reward: ${order.CashReward} | " +
                $"Can Fulfill: " +
                $"{CanFulfillOrderAtIndex(i)}"
            );
        }
    }
    [ContextMenu("Fulfill Customer 1")]
    private void DebugFulfillCustomer1()
    {
        TryFulfillOrderAtIndex(0);
    }
    [ContextMenu("Fulfill Customer 2")]
    private void DebugFulfillCustomer2()
    {
        TryFulfillOrderAtIndex(1);
    }
    [ContextMenu("Fulfill Customer 3")]
    private void DebugFulfillCustomer3()
    {
        TryFulfillOrderAtIndex(2);
    }
    [ContextMenu("Fulfill Customer 4")]
    private void DebugFulfillCustomer4()
    {
        TryFulfillOrderAtIndex(3);
    }
    [ContextMenu("Debug Eligible Orders")]
    private void DebugEligibleOrders()
    {
        if (orderPool == null ||
            orderPool.Length == 0)
        {
            Debug.Log(
                "ORDER POOL | Empty."
            );
            return;
        }
        Debug.Log(
            $"ORDER POOL | " +
            $"Maximum Tier: " +
            $"T{progressionManager.MaxUnlockedDessertTier}"
        );
        foreach (
            CustomerOrderDefinition definition
            in orderPool)
        {
            if (definition == null)
                continue;
            Debug.Log(
                $"ORDER POOL | " +
                $"{definition.DisplayName} | " +
                $"Eligible: " +
                $"{IsOrderUnlocked(definition)}"
            );
        }
    }
}
