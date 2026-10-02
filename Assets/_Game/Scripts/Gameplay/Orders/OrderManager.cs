using System;
using System.Collections.Generic;
using UnityEngine;

public class OrderManager : MonoBehaviour
{
    [Header("References")]
    [SerializeField]
    private GridManager gridManager;

    [Header("Progression")]
    [SerializeField]
    private PlayerProgressionManager
        progressionManager;

    [Header("Prototype Order Pool")]
    [SerializeField]
    private CustomerOrderDefinition[]
        orderPool;

    private CustomerOrder activeOrder;

    private CustomerOrderDefinition
        previousOrderDefinition;

    private bool isFulfilling;

    public event Action
        ActiveOrderChanged;

    public event Action
        OrderStateChanged;

    public event Action<CustomerOrder>
        OrderFulfillmentStarted;

    public event Action<CustomerOrder>
        OrderCompleted;

    public event Action<CustomerOrder>
        OrderGenerated;

    public CustomerOrder ActiveOrder =>
        activeOrder;

    public bool HasActiveOrder =>
        activeOrder != null &&
        activeOrder.IsValid;

    public bool IsFulfilling =>
        isFulfilling;

    public bool CanFulfillActiveOrder
    {
        get
        {
            if (isFulfilling)
                return false;

            if (!HasActiveOrder)
                return false;

            if (gridManager == null)
                return false;

            return activeOrder
                .CanFulfill(
                    gridManager
                );
        }
    }

    private void Start()
    {
        ResolveReferences();

        if (gridManager == null)
        {
            Debug.LogError(
                "OrderManager: GridManager " +
                "could not be found."
            );

            return;
        }

        if (progressionManager == null)
        {
            Debug.LogError(
                "OrderManager: " +
                "PlayerProgressionManager " +
                "could not be found."
            );

            return;
        }

        gridManager.BoardChanged +=
            HandleBoardChanged;

        progressionManager
            .UpgradeLevelChanged +=
                HandleUpgradeLevelChanged;

        GenerateNewOrder();
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

        if (progressionManager == null)
        {
            progressionManager =
                FindFirstObjectByType<
                    PlayerProgressionManager>();
        }
    }

    // --------------------------------------------------
    // ORDER GENERATION
    // --------------------------------------------------

    public void GenerateNewOrder()
    {
        if (isFulfilling)
            return;

        CustomerOrderDefinition definition =
            GetRandomValidOrder();

        if (definition == null)
        {
            Debug.LogError(
                "OrderManager: No valid and " +
                "currently unlocked order " +
                "exists in the order pool."
            );

            activeOrder = null;

            ActiveOrderChanged?.Invoke();
            OrderStateChanged?.Invoke();

            return;
        }

        SetActiveOrder(
            definition
        );
    }

    public void SetActiveOrder(
        CustomerOrderDefinition definition)
    {
        if (isFulfilling)
            return;

        if (definition == null)
        {
            Debug.LogError(
                "OrderManager: Cannot set " +
                "a null order definition."
            );

            return;
        }

        if (!definition.IsValid)
        {
            Debug.LogError(
                $"OrderManager: " +
                $"{definition.name} is invalid."
            );

            return;
        }

        if (!IsOrderUnlocked(
                definition))
        {
            Debug.LogWarning(
                $"ORDER LOCKED | " +
                $"{definition.DisplayName} " +
                "requires dessert tiers " +
                "above the current Oven " +
                "progression."
            );

            return;
        }

        activeOrder =
            new CustomerOrder(
                definition
            );

        previousOrderDefinition =
            definition;

        Debug.Log(
            $"ORDER GENERATED | " +
            $"{activeOrder.DisplayName}"
        );

        OrderGenerated?.Invoke(
            activeOrder
        );

        ActiveOrderChanged?.Invoke();

        EvaluateActiveOrder();
    }

    private CustomerOrderDefinition
        GetRandomValidOrder()
    {
        if (orderPool == null ||
            orderPool.Length == 0)
        {
            return null;
        }

        List<CustomerOrderDefinition>
            validOrders =
                new List<
                    CustomerOrderDefinition>();

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

            validOrders.Add(
                definition
            );
        }

        if (validOrders.Count == 0)
        {
            return null;
        }

        // Avoid immediately repeating the
        // same order when alternatives exist.
        if (validOrders.Count > 1 &&
            previousOrderDefinition != null)
        {
            validOrders.Remove(
                previousOrderDefinition
            );
        }

        if (validOrders.Count == 0)
        {
            if (previousOrderDefinition != null &&
                IsOrderUnlocked(
                    previousOrderDefinition))
            {
                return
                    previousOrderDefinition;
            }

            return null;
        }

        int randomIndex =
            UnityEngine.Random.Range(
                0,
                validOrders.Count
            );

        return validOrders[
            randomIndex
        ];
    }

    // --------------------------------------------------
    // PROGRESSION FILTER
    // --------------------------------------------------

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

            int tier =
                requirement.Dessert.Tier;

            if (!progressionManager
                    .IsDessertTierUnlocked(
                        tier))
            {
                return false;
            }
        }

        return true;
    }

    private void HandleUpgradeLevelChanged(
        UpgradeType type,
        int newLevel)
    {
        if (type != UpgradeType.Oven)
            return;

        Debug.Log(
            $"ORDER PROGRESSION | " +
            $"Oven Level {newLevel} | " +
            $"Maximum Order Tier: " +
            $"T{progressionManager.MaxUnlockedDessertTier}"
        );

        // Existing customer remains untouched.
        // The expanded tier pool applies to
        // future generated orders.
    }

    // --------------------------------------------------
    // FULFILLMENT
    // --------------------------------------------------

    public bool TryFulfillActiveOrder()
    {
        if (isFulfilling)
        {
            Debug.Log(
                "ORDER | Fulfillment is " +
                "already in progress."
            );

            return false;
        }

        if (!HasActiveOrder)
        {
            Debug.Log(
                "ORDER | No active order " +
                "to fulfill."
            );

            return false;
        }

        if (gridManager == null)
        {
            Debug.LogError(
                "OrderManager: GridManager " +
                "is missing."
            );

            return false;
        }

        if (!activeOrder
                .TryGetDessertsForFulfillment(
                    gridManager,
                    out List<Dessert>
                        dessertsToConsume))
        {
            Debug.Log(
                $"ORDER | " +
                $"{activeOrder.DisplayName} " +
                "cannot be fulfilled yet."
            );

            return false;
        }

        isFulfilling = true;

        CustomerOrder completedOrder =
            activeOrder;

        OrderFulfillmentStarted?.Invoke(
            completedOrder
        );

        // Clear logical occupancy first.
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

            dessert.SetCurrentCell(
                null
            );
        }

        // Then remove the visual objects.
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

        activeOrder = null;

        gridManager
            .NotifyBoardChanged();

        Debug.Log(
            $"ORDER COMPLETED | " +
            $"{completedOrder.DisplayName} | " +
            $"Consumed: " +
            $"{dessertsToConsume.Count}"
        );

        OrderCompleted?.Invoke(
            completedOrder
        );

        ActiveOrderChanged?.Invoke();

        isFulfilling = false;

        GenerateNewOrder();

        return true;
    }

    // --------------------------------------------------
    // BOARD EVALUATION
    // --------------------------------------------------

    private void HandleBoardChanged()
    {
        EvaluateActiveOrder();
    }

    private void EvaluateActiveOrder()
    {
        if (isFulfilling)
            return;

        if (!HasActiveOrder ||
            gridManager == null)
        {
            return;
        }

        bool canFulfill =
            activeOrder.CanFulfill(
                gridManager
            );

        Debug.Log(
            $"ORDER | " +
            $"{activeOrder.DisplayName} | " +
            $"Can Fulfill: {canFulfill}"
        );

        OrderStateChanged?.Invoke();
    }

    // --------------------------------------------------
    // DEBUG
    // --------------------------------------------------

    [ContextMenu("Generate New Order")]
    private void DebugGenerateNewOrder()
    {
        GenerateNewOrder();
    }

    [ContextMenu("Fulfill Active Order")]
    private void DebugFulfillActiveOrder()
    {
        TryFulfillActiveOrder();
    }

    [ContextMenu("Debug Active Order")]
    private void DebugActiveOrder()
    {
        if (!HasActiveOrder)
        {
            Debug.Log(
                "ORDER | No active order."
            );

            return;
        }

        Debug.Log(
            $"ORDER | " +
            $"{activeOrder.DisplayName} | " +
            $"Reward: " +
            $"${activeOrder.CashReward} | " +
            $"Can Fulfill: " +
            $"{CanFulfillActiveOrder}"
        );
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
            $"Current Max Tier: " +
            $"T{progressionManager.MaxUnlockedDessertTier}"
        );

        foreach (
            CustomerOrderDefinition definition
            in orderPool)
        {
            if (definition == null)
            {
                Debug.Log(
                    "ORDER POOL | " +
                    "NULL | Eligible: False"
                );

                continue;
            }

            bool eligible =
                definition.IsValid &&
                IsOrderUnlocked(
                    definition
                );

            Debug.Log(
                $"ORDER POOL | " +
                $"{definition.DisplayName} | " +
                $"Eligible: {eligible}"
            );
        }
    }
}