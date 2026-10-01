using System;
using System.Collections.Generic;
using UnityEngine;

public class OrderManager : MonoBehaviour
{
    [Header("References")]
    [SerializeField]
    private GridManager gridManager;

    [Header("Prototype Order Pool")]
    [SerializeField]
    private CustomerOrderDefinition[] orderPool;

    private CustomerOrder activeOrder;

    private CustomerOrderDefinition
        previousOrderDefinition;

    private bool isFulfilling;

    public event Action ActiveOrderChanged;
    public event Action OrderStateChanged;

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

            return activeOrder.CanFulfill(
                gridManager
            );
        }
    }

    private void Start()
    {
        if (gridManager == null)
        {
            gridManager =
                FindFirstObjectByType<GridManager>();
        }

        if (gridManager == null)
        {
            Debug.LogError(
                "OrderManager: GridManager " +
                "could not be found."
            );

            return;
        }

        gridManager.BoardChanged +=
            HandleBoardChanged;

        GenerateNewOrder();
    }

    private void OnDestroy()
    {
        if (gridManager != null)
        {
            gridManager.BoardChanged -=
                HandleBoardChanged;
        }
    }

    public void GenerateNewOrder()
    {
        if (isFulfilling)
            return;

        CustomerOrderDefinition definition =
            GetRandomValidOrder();

        if (definition == null)
        {
            Debug.LogError(
                "OrderManager: No valid order " +
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

        if (!activeOrder.TryGetDessertsForFulfillment(
                gridManager,
                out List<Dessert> dessertsToConsume))
        {
            Debug.Log(
                $"ORDER | " +
                $"{activeOrder.DisplayName} " +
                $"cannot be fulfilled yet."
            );

            return false;
        }

        isFulfilling = true;

        CustomerOrder completedOrder =
            activeOrder;

        OrderFulfillmentStarted?.Invoke(
            completedOrder
        );

        /*
         * Logical board state is cleared first.
         * This keeps the grid authoritative even
         * if visual destruction happens later.
         */
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

        gridManager.NotifyBoardChanged();

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
                new List<CustomerOrderDefinition>();

        foreach (
            CustomerOrderDefinition definition
            in orderPool)
        {
            if (definition == null)
                continue;

            if (!definition.IsValid)
                continue;

            validOrders.Add(
                definition
            );
        }

        if (validOrders.Count == 0)
        {
            return null;
        }

        /*
         * If multiple valid orders exist,
         * avoid immediately repeating the
         * previous order.
         */
        if (validOrders.Count > 1 &&
            previousOrderDefinition != null)
        {
            validOrders.Remove(
                previousOrderDefinition
            );
        }

        if (validOrders.Count == 0)
        {
            return previousOrderDefinition;
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
            $"Reward: ${activeOrder.CashReward} | " +
            $"Can Fulfill: " +
            $"{CanFulfillActiveOrder}"
        );
    }
}