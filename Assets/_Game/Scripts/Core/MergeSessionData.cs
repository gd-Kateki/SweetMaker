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