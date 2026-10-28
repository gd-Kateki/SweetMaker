using System;
using System.Collections.Generic;

// Pure DTO projection and value comparison only; supplied capacity is not
// independently authenticated evidence.
internal static class FrozenSessionProjection
{
    internal static bool TryProject(
        FrozenMergeSessionValues source,
        int customerCapacity,
        out MergeGameplaySaveData projected,
        out string failureReason)
    {
        projected = null;
        if (!TryValidateFrozenSession(
                source,
                customerCapacity,
                out failureReason))
        {
            return false;
        }

        var result = new MergeGameplaySaveData
        {
            hasSession = source.HasSession,
            nextOrderId = source.NextOrderId,
            nextDessertTier = source.NextDessertTier
        };

        for (int i = 0; i < source.BoardDesserts.Count; i++)
        {
            FrozenBoardDessertValue row = source.BoardDesserts[i];
            result.boardDesserts.Add(
                new BoardDessertSaveData(row.CellIndex, row.DessertTier));
        }

        for (int i = 0; i < source.ShelfDesserts.Count; i++)
        {
            FrozenShelfDessertValue row = source.ShelfDesserts[i];
            result.shelfDesserts.Add(
                new ShelfDessertSaveData(row.SlotIndex, row.DessertTier));
        }

        for (int i = 0; i < source.CustomerOrders.Count; i++)
        {
            FrozenCustomerOrderValue row = source.CustomerOrders[i];
            result.customerOrders.Add(
                new CustomerOrderSaveData(
                    row.CustomerIndex,
                    row.OrderId,
                    row.DefinitionId));
        }

        projected = result;
        failureReason = null;
        return true;
    }

    internal static bool MatchesFrozen(
        FrozenMergeSessionValues expected,
        int expectedCapacity,
        MergeGameplaySaveData actual,
        int actualCapacity,
        out string failureReason)
    {
        if (!TryValidateFrozenSession(
                expected,
                expectedCapacity,
                out failureReason))
        {
            return false;
        }

        if (actual == null)
            return Fail("actual session is null.", out failureReason);
        if (actualCapacity != expectedCapacity)
            return Fail("customer capacity differs.", out failureReason);
        if (actual.hasSession != expected.HasSession)
            return Fail("hasSession differs.", out failureReason);
        if (actual.boardDesserts == null ||
            actual.shelfDesserts == null ||
            actual.customerOrders == null)
        {
            return Fail("an actual session collection is null.", out failureReason);
        }
        if (actual.boardDesserts.Count != expected.BoardDesserts.Count)
            return Fail("board row count differs.", out failureReason);
        if (actual.shelfDesserts.Count != expected.ShelfDesserts.Count)
            return Fail("shelf row count differs.", out failureReason);
        if (actual.customerOrders.Count != expected.CustomerOrders.Count)
            return Fail("customer row count differs.", out failureReason);
        if (actual.nextOrderId != expected.NextOrderId)
            return Fail("nextOrderId differs.", out failureReason);
        if (actual.nextDessertTier != expected.NextDessertTier)
            return Fail("nextDessertTier differs.", out failureReason);

        for (int i = 0; i < expected.BoardDesserts.Count; i++)
        {
            FrozenBoardDessertValue expectedRow = expected.BoardDesserts[i];
            BoardDessertSaveData actualRow = actual.boardDesserts[i];
            if (actualRow == null ||
                actualRow.cellIndex != expectedRow.CellIndex ||
                actualRow.dessertTier != expectedRow.DessertTier)
            {
                return Fail(
                    "board row " + i + " differs.",
                    out failureReason);
            }
        }

        for (int i = 0; i < expected.ShelfDesserts.Count; i++)
        {
            FrozenShelfDessertValue expectedRow = expected.ShelfDesserts[i];
            ShelfDessertSaveData actualRow = actual.shelfDesserts[i];
            if (actualRow == null ||
                actualRow.slotIndex != expectedRow.SlotIndex ||
                actualRow.dessertTier != expectedRow.DessertTier)
            {
                return Fail(
                    "shelf row " + i + " differs.",
                    out failureReason);
            }
        }

        for (int i = 0; i < expected.CustomerOrders.Count; i++)
        {
            FrozenCustomerOrderValue expectedRow =
                expected.CustomerOrders[i];
            CustomerOrderSaveData actualRow = actual.customerOrders[i];
            if (actualRow == null ||
                actualRow.customerIndex != expectedRow.CustomerIndex ||
                actualRow.orderId != expectedRow.OrderId ||
                !string.Equals(
                    actualRow.definitionId,
                    expectedRow.DefinitionId,
                    StringComparison.Ordinal))
            {
                return Fail(
                    "customer row " + i + " differs.",
                    out failureReason);
            }
        }

        failureReason = null;
        return true;
    }

    private static bool TryValidateFrozenSession(
        FrozenMergeSessionValues source,
        int customerCapacity,
        out string failureReason)
    {
        failureReason = null;
        if (source == null)
            return Fail("frozen session is null.", out failureReason);
        if (source.BoardDesserts == null ||
            source.ShelfDesserts == null ||
            source.CustomerOrders == null)
        {
            return Fail("a frozen session collection is null.", out failureReason);
        }
        if (source.NextOrderId < 1)
            return Fail("nextOrderId must be positive.", out failureReason);
        if (source.NextDessertTier != -1 &&
            source.NextDessertTier <= 0)
        {
            return Fail(
                "nextDessertTier must be -1 or positive.",
                out failureReason);
        }

        if (!source.HasSession)
        {
            if (customerCapacity != 0)
                return Fail(
                    "no-session capacity must be zero.",
                    out failureReason);
            if (source.BoardDesserts.Count != 0 ||
                source.ShelfDesserts.Count != 0 ||
                source.CustomerOrders.Count != 0)
            {
                return Fail(
                    "no-session data must have empty collections.",
                    out failureReason);
            }
            return true;
        }

        if (customerCapacity < 1 || customerCapacity > 3)
            return Fail(
                "live session capacity must be between 1 and 3.",
                out failureReason);

        var boardIndices = new HashSet<int>();
        for (int i = 0; i < source.BoardDesserts.Count; i++)
        {
            FrozenBoardDessertValue row = source.BoardDesserts[i];
            if (row == null ||
                row.CellIndex < 0 ||
                row.DessertTier <= 0 ||
                !boardIndices.Add(row.CellIndex))
            {
                return Fail(
                    "board row " + i + " is invalid or duplicated.",
                    out failureReason);
            }
        }

        var shelfIndices = new HashSet<int>();
        for (int i = 0; i < source.ShelfDesserts.Count; i++)
        {
            FrozenShelfDessertValue row = source.ShelfDesserts[i];
            if (row == null ||
                row.SlotIndex < 0 ||
                row.DessertTier <= 0 ||
                !shelfIndices.Add(row.SlotIndex))
            {
                return Fail(
                    "shelf row " + i + " is invalid or duplicated.",
                    out failureReason);
            }
        }

        if (source.CustomerOrders.Count != customerCapacity)
            return Fail(
                "customer rows do not match capacity.",
                out failureReason);

        var coveredCustomers = new bool[customerCapacity];
        var orderIds = new HashSet<int>();
        for (int i = 0; i < source.CustomerOrders.Count; i++)
        {
            FrozenCustomerOrderValue row = source.CustomerOrders[i];
            if (row == null ||
                row.CustomerIndex < 0 ||
                row.CustomerIndex >= customerCapacity ||
                coveredCustomers[row.CustomerIndex] ||
                row.OrderId <= 0 ||
                row.OrderId >= source.NextOrderId ||
                !orderIds.Add(row.OrderId) ||
                string.IsNullOrWhiteSpace(row.DefinitionId))
            {
                return Fail(
                    "customer row " + i + " is invalid or duplicated.",
                    out failureReason);
            }

            if (ProceduralCustomerOrderSaveCodec.IsProceduralDefinitionId(
                    row.DefinitionId) &&
                !ProceduralCustomerOrderSaveCodec.TryDecode(
                    row.DefinitionId,
                    out _,
                    out string decodeReason))
            {
                return Fail(
                    "customer row " + i + " has invalid procedural data: " +
                    decodeReason,
                    out failureReason);
            }

            coveredCustomers[row.CustomerIndex] = true;
        }

        for (int i = 0; i < coveredCustomers.Length; i++)
        {
            if (!coveredCustomers[i])
                return Fail(
                    "customer slot " + i + " is missing.",
                    out failureReason);
        }

        return true;
    }

    private static bool Fail(string reason, out string failureReason)
    {
        failureReason = reason;
        return false;
    }
}
