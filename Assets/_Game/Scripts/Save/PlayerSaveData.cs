using System;
using System.Collections.Generic;

// ======================================================
// ROOT SAVE DATA
// ======================================================

[Serializable]
public class PlayerSaveData
{
    /*
     * Increment this whenever the permanent save
     * structure changes in a way that may require
     * migration.
     */
    public int saveVersion = 2;

    public int completedRebirthCount = 0;

    public int highestTierCreatedThisRun = 0;

    public bool campaignComplete = false;

    // This backward-compatible V2 extension defaults absent acknowledgement fields
    // to unseen; the strict validator permits only these specific omissions.
    public bool upgradesIntroSeen = false;

    public bool rebirthIntroSeen = false;

    public bool collectionIntroSeen = false;

    public EconomySaveData economy =
        new EconomySaveData();

    public ProgressionSaveData progression =
        new ProgressionSaveData();

    public MergeGameplaySaveData mergeGameplay =
        new MergeGameplaySaveData();

    public DessertCollectionSaveData dessertCollection =
        new DessertCollectionSaveData();

    public PlayerSaveData()
    {
    }
}

// ======================================================
// ECONOMY
// ======================================================

[Serializable]
public class EconomySaveData
{
    public int cash = 0;

    public long totalOrdersCompleted = 0;

    public long totalMoneyEarned = 0;

    public EconomySaveData()
    {
    }

    public EconomySaveData(int cash)
    {
        this.cash = cash;
    }
}

// ======================================================
// PROGRESSION
// ======================================================

[Serializable]
public class ProgressionSaveData
{
    public int ovenLevel = 1;

    public int boardSpaceLevel = 1;

    public int shelfLevel = 1;

    public int customerLevel = 1;

    public int moneyMultiplierLevel = 1;

    public ProgressionSaveData()
    {
    }
}

// ======================================================
// MERGE GAMEPLAY
// ======================================================

[Serializable]
public class MergeGameplaySaveData
{
    /*
     * True once a valid gameplay session has been
     * captured.
     *
     * This distinguishes:
     *
     * "The player has an empty board"
     *
     * from:
     *
     * "No merge session has ever been saved."
     */
    public bool hasSession = false;

    public List<BoardDessertSaveData> boardDesserts =
        new List<BoardDessertSaveData>();

    public List<ShelfDessertSaveData> shelfDesserts =
        new List<ShelfDessertSaveData>();

    public List<CustomerOrderSaveData> customerOrders =
        new List<CustomerOrderSaveData>();

    /*
     * Used to preserve sequential runtime order IDs.
     */
    public int nextOrderId = 1;

    /*
     * -1 means there is currently no valid
     * queued dessert.
     */
    public int nextDessertTier = -1;

    public MergeGameplaySaveData()
    {
    }
}

// ======================================================
// DESSERT COLLECTION
// ======================================================

[Serializable]
public class DessertCollectionSaveData
{
    public List<int> discoveredTierIds =
        new List<int>();

    public List<int> claimedMilestoneIds =
        new List<int>();

    public DessertCollectionSaveData()
    {
    }
}

// ======================================================
// BOARD DESSERT
// ======================================================

[Serializable]
public class BoardDessertSaveData
{
    public int cellIndex;

    public int dessertTier;

    public BoardDessertSaveData()
    {
    }

    public BoardDessertSaveData(
        int cellIndex,
        int dessertTier)
    {
        this.cellIndex = cellIndex;
        this.dessertTier = dessertTier;
    }
}

// ======================================================
// SHELF DESSERT
// ======================================================

[Serializable]
public class ShelfDessertSaveData
{
    public int slotIndex;

    public int dessertTier;

    public ShelfDessertSaveData()
    {
    }

    public ShelfDessertSaveData(
        int slotIndex,
        int dessertTier)
    {
        this.slotIndex = slotIndex;
        this.dessertTier = dessertTier;
    }
}

// ======================================================
// CUSTOMER ORDER
// ======================================================

[Serializable]
public class CustomerOrderSaveData
{
    /*
     * Which fixed customer slot owns this order.
     */
    public int customerIndex;

    /*
     * Runtime sequential order ID.
     */
    public int orderId;

    /*
     * Stable order reference: an asset definition ID or
     * a versioned procedural snapshot encoded in this field.
     *
     * IMPORTANT:
     *
     * We deliberately do NOT store a
     * CustomerOrderDefinition ScriptableObject here.
     */
    public string definitionId;

    public CustomerOrderSaveData()
    {
    }

    public CustomerOrderSaveData(
        int customerIndex,
        int orderId,
        string definitionId)
    {
        this.customerIndex =
            customerIndex;

        this.orderId =
            orderId;

        this.definitionId =
            definitionId;
    }
}