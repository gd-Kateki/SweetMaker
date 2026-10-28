using System.Collections.Generic;
using System.Globalization;

// Inactive, intrinsic Save V2 validation only. This grants no session authority.
// The caller must keep the source DTO, lists and entries stable during this call;
// reading fields into locals does not provide an atomic concurrent snapshot.
internal static class StrictMergeSessionFreezer
{
    internal static bool TryFreeze(
        MergeGameplaySaveData source,
        out FrozenMergeSessionValues frozen,
        out string failureReason)
    {
        frozen = null;
        failureReason = null;
        if (source == null)
            return Fail("source is null.", out failureReason);

        bool hasSession = source.hasSession;
        List<BoardDessertSaveData> boardDesserts = source.boardDesserts;
        List<ShelfDessertSaveData> shelfDesserts = source.shelfDesserts;
        List<CustomerOrderSaveData> customerOrders = source.customerOrders;
        int nextOrderId = source.nextOrderId;
        int nextDessertTier = source.nextDessertTier;

        if (boardDesserts == null)
            return Fail("boardDesserts is null.", out failureReason);
        if (shelfDesserts == null)
            return Fail("shelfDesserts is null.", out failureReason);
        if (customerOrders == null)
            return Fail("customerOrders is null.", out failureReason);
        if (nextOrderId < 1)
            return Fail("nextOrderId must be at least 1.", out failureReason);
        if (nextDessertTier != -1 && nextDessertTier <= 0)
            return Fail("nextDessertTier must be -1 or positive.", out failureReason);

        int boardCount = boardDesserts.Count;
        int shelfCount = shelfDesserts.Count;
        int orderCount = customerOrders.Count;
        if (!hasSession)
        {
            if (boardCount != 0)
                return Fail("boardDesserts must be empty when hasSession is false.", out failureReason);
            if (shelfCount != 0)
                return Fail("shelfDesserts must be empty when hasSession is false.", out failureReason);
            if (orderCount != 0)
                return Fail("customerOrders must be empty when hasSession is false.", out failureReason);
        }

        var frozenBoard = new FrozenBoardDessertValue[boardCount];
        var cells = new HashSet<int>();
        for (int i = 0; i < boardCount; i++)
        {
            BoardDessertSaveData entry = boardDesserts[i];
            if (entry == null)
                return FailRow("boardDesserts", i, "entry is null.", out failureReason);

            int cellIndex = entry.cellIndex;
            int dessertTier = entry.dessertTier;
            if (cellIndex < 0)
                return FailRow("boardDesserts", i, "cellIndex is negative.", out failureReason);
            if (!cells.Add(cellIndex))
                return FailRow("boardDesserts", i, "cellIndex is duplicated.", out failureReason);
            if (dessertTier <= 0)
                return FailRow("boardDesserts", i, "dessertTier must be positive.", out failureReason);

            frozenBoard[i] = new FrozenBoardDessertValue(cellIndex, dessertTier);
        }

        var frozenShelf = new FrozenShelfDessertValue[shelfCount];
        var slots = new HashSet<int>();
        for (int i = 0; i < shelfCount; i++)
        {
            ShelfDessertSaveData entry = shelfDesserts[i];
            if (entry == null)
                return FailRow("shelfDesserts", i, "entry is null.", out failureReason);

            int slotIndex = entry.slotIndex;
            int dessertTier = entry.dessertTier;
            if (slotIndex < 0)
                return FailRow("shelfDesserts", i, "slotIndex is negative.", out failureReason);
            if (!slots.Add(slotIndex))
                return FailRow("shelfDesserts", i, "slotIndex is duplicated.", out failureReason);
            if (dessertTier <= 0)
                return FailRow("shelfDesserts", i, "dessertTier must be positive.", out failureReason);

            frozenShelf[i] = new FrozenShelfDessertValue(slotIndex, dessertTier);
        }

        var frozenOrders = new FrozenCustomerOrderValue[orderCount];
        var customers = new HashSet<int>();
        var orderIds = new HashSet<int>();
        for (int i = 0; i < orderCount; i++)
        {
            CustomerOrderSaveData entry = customerOrders[i];
            if (entry == null)
                return FailRow("customerOrders", i, "entry is null.", out failureReason);

            int customerIndex = entry.customerIndex;
            int orderId = entry.orderId;
            string definitionId = entry.definitionId;
            if (customerIndex < 0)
                return FailRow("customerOrders", i, "customerIndex is negative.", out failureReason);
            if (!customers.Add(customerIndex))
                return FailRow("customerOrders", i, "customerIndex is duplicated.", out failureReason);
            if (orderId <= 0)
                return FailRow("customerOrders", i, "orderId must be positive.", out failureReason);
            if (!orderIds.Add(orderId))
                return FailRow("customerOrders", i, "orderId is duplicated.", out failureReason);
            if (orderId >= nextOrderId)
                return FailRow("customerOrders", i, "orderId must be less than nextOrderId.", out failureReason);
            if (string.IsNullOrWhiteSpace(definitionId))
                return FailRow("customerOrders", i, "definitionId is null, empty or whitespace-only.", out failureReason);

            // Recognition is ordinal and case-sensitive. Decode only to validate;
            // keep the original string, including its exact encoded representation.
            if (ProceduralCustomerOrderSaveCodec.IsProceduralDefinitionId(definitionId) &&
                !ProceduralCustomerOrderSaveCodec.TryDecode(
                    definitionId, out _, out string decodeReason))
            {
                return FailRow("customerOrders", i,
                    "definitionId: " + decodeReason, out failureReason);
            }

            frozenOrders[i] = new FrozenCustomerOrderValue(
                customerIndex, orderId, definitionId);
        }

        // Publish only after every row has passed. Constructors defensively copy
        // arrays, and entries contain only immutable scalar/string values.
        frozen = new FrozenMergeSessionValues(
            hasSession, frozenBoard, frozenShelf, frozenOrders,
            nextOrderId, nextDessertTier);
        return true;
    }

    private static bool Fail(string reason, out string failureReason)
    {
        failureReason = reason;
        return false;
    }

    private static bool FailRow(
        string collection, int index, string reason, out string failureReason)
    {
        return Fail(collection + "[" + index.ToString(CultureInfo.InvariantCulture) +
            "]: " + reason, out failureReason);
    }
}