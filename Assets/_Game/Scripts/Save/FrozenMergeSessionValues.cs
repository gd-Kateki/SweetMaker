using System;
using System.Collections.Generic;

// Detached Save V2 values only, not a runtime session or proof of validation.
// Field meanings follow MergeGameplaySaveData and its three entry DTOs.
// Preserve sequence order, duplicates, nulls, identifiers and counters exactly.
// Future strict freezing must reject invalid input rather than repair it.
internal sealed class FrozenMergeSessionValues
{
    public bool HasSession { get; }
    public IReadOnlyList<FrozenBoardDessertValue> BoardDesserts { get; }
    public IReadOnlyList<FrozenShelfDessertValue> ShelfDesserts { get; }
    public IReadOnlyList<FrozenCustomerOrderValue> CustomerOrders { get; }
    public int NextOrderId { get; }
    public int NextDessertTier { get; }

    internal FrozenMergeSessionValues(
        bool hasSession,
        FrozenBoardDessertValue[] boardDesserts,
        FrozenShelfDessertValue[] shelfDesserts,
        FrozenCustomerOrderValue[] customerOrders,
        int nextOrderId,
        int nextDessertTier)
    {
        HasSession = hasSession;
        BoardDesserts = boardDesserts == null
            ? null
            : Array.AsReadOnly((FrozenBoardDessertValue[])boardDesserts.Clone());
        ShelfDesserts = shelfDesserts == null
            ? null
            : Array.AsReadOnly((FrozenShelfDessertValue[])shelfDesserts.Clone());
        CustomerOrders = customerOrders == null
            ? null
            : Array.AsReadOnly((FrozenCustomerOrderValue[])customerOrders.Clone());
        NextOrderId = nextOrderId;
        NextDessertTier = nextDessertTier;
    }
}

internal sealed class FrozenBoardDessertValue
{
    public int CellIndex { get; }
    public int DessertTier { get; }

    internal FrozenBoardDessertValue(int cellIndex, int dessertTier)
    {
        CellIndex = cellIndex;
        DessertTier = dessertTier;
    }
}

internal sealed class FrozenShelfDessertValue
{
    public int SlotIndex { get; }
    public int DessertTier { get; }

    internal FrozenShelfDessertValue(int slotIndex, int dessertTier)
    {
        SlotIndex = slotIndex;
        DessertTier = dessertTier;
    }
}

internal sealed class FrozenCustomerOrderValue
{
    public int CustomerIndex { get; }
    public int OrderId { get; }

    // Exact persisted asset ID or procedural-order-v1 encoded payload.
    // Never trim, decode/re-encode, or retain a CustomerOrderDefinition here.
    // Runtime display/reward/requirements resolution belongs to future freezing;
    // Save V2 persists those procedural values inside this string only.
    public string DefinitionId { get; }

    internal FrozenCustomerOrderValue(
        int customerIndex,
        int orderId,
        string definitionId)
    {
        CustomerIndex = customerIndex;
        OrderId = orderId;
        DefinitionId = definitionId;
    }
}
