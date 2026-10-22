using System;
using System.Collections.Generic;

[Serializable]
public class BoardDessertState
{
    public int cellIndex;
    public int dessertTier;

    public BoardDessertState(
        int cellIndex,
        int dessertTier)
    {
        this.cellIndex =
            cellIndex;

        this.dessertTier =
            dessertTier;
    }
}

[Serializable]
public class ShelfDessertState
{
    public int slotIndex;
    public int dessertTier;

    public ShelfDessertState(
        int slotIndex,
        int dessertTier)
    {
        this.slotIndex =
            slotIndex;

        this.dessertTier =
            dessertTier;
    }
}

[Serializable]
public class CustomerOrderState
{
    public int customerIndex;
    public int orderId;

    public CustomerOrderDefinition
        definition;
    public string displayName;
    public int cashReward;
    public OrderRequirement[] requirements;

    public CustomerOrderState(
        int customerIndex,
        int orderId,
        CustomerOrderDefinition definition)
    {
        this.customerIndex =
            customerIndex;

        this.orderId =
            orderId;

        this.definition =
            definition;
    }

    public CustomerOrderState(
        int customerIndex,
        CustomerOrder order)
    {
        this.customerIndex = customerIndex;
        orderId = order != null ? order.OrderId : 0;
        definition = order != null ? order.Definition : null;
        displayName = order != null ? order.DisplayName : null;
        cashReward = order != null ? order.CashReward : 0;

        if (order == null || order.Requirements == null)
            return;

        requirements = new OrderRequirement[order.Requirements.Count];
        for (int i = 0; i < requirements.Length; i++)
        {
            OrderRequirement source = order.Requirements[i];
            requirements[i] = source == null
                ? null
                : new OrderRequirement(source.Dessert, source.Amount);
        }
    }

    public CustomerOrderState Clone()
    {
        var clone = new CustomerOrderState(customerIndex, orderId, definition)
        {
            displayName = displayName,
            cashReward = cashReward
        };
        if (requirements != null)
        {
            clone.requirements = new OrderRequirement[requirements.Length];
            for (int i = 0; i < requirements.Length; i++)
            {
                OrderRequirement requirement = requirements[i];
                clone.requirements[i] = requirement == null
                    ? null
                    : new OrderRequirement(
                        requirement.Dessert,
                        requirement.Amount);
            }
        }

        return clone;
    }

    public CustomerOrder CreateOrder()
    {
        if (definition != null)
            return new CustomerOrder(orderId, definition);
        return new CustomerOrder(
            orderId,
            displayName,
            cashReward,
            requirements);
    }
}

[Serializable]
public class MergeSessionData
{
    public List<BoardDessertState>
        boardDesserts =
            new List<BoardDessertState>();

    public List<ShelfDessertState>
        shelfDesserts =
            new List<ShelfDessertState>();

    public List<CustomerOrderState>
        customerOrders =
            new List<CustomerOrderState>();

    public int nextOrderId = 1;

    /*
     * -1 means that no valid Next Dessert
     * has been captured.
     */
    public int nextDessertTier = -1;

    public void Clear()
    {
        boardDesserts.Clear();
        shelfDesserts.Clear();
        customerOrders.Clear();

        nextOrderId = 1;
        nextDessertTier = -1;
    }
}