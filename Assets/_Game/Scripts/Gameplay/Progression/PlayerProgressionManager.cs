using System;
using UnityEngine;

public class PlayerProgressionManager : MonoBehaviour
{
    public static PlayerProgressionManager Instance
    {
        get;
        private set;
    }

    // ==================================================
    // UPGRADE DEFINITIONS
    // ==================================================

    [Header("Upgrade Definitions")]

    [SerializeField]
    private UpgradeDefinition ovenUpgrade;

    [SerializeField]
    private UpgradeDefinition boardSpaceUpgrade;

    [SerializeField]
    private UpgradeDefinition shelfUpgrade;

    [SerializeField]
    private UpgradeDefinition customerUpgrade;

    [SerializeField]
    private UpgradeDefinition moneyMultiplierUpgrade;

    // ==================================================
    // RUNTIME LEVELS
    // ==================================================

    [Header("Runtime Levels")]

    [SerializeField]
    private int ovenLevel = 1;

    [SerializeField]
    private int boardSpaceLevel = 1;

    [SerializeField]
    private int shelfLevel = 1;

    [SerializeField]
    private int customerLevel = 1;

    [SerializeField]
    private int moneyMultiplierLevel = 1;

    [Header("Rebirth Progression")]
    [SerializeField]
    private RebirthProgressionState rebirthProgression =
        new RebirthProgressionState();

    // ==================================================
    // EVENTS
    // ==================================================

    public event Action<UpgradeType, int>
        UpgradeLevelChanged;

    // ==================================================
    // LEVEL PROPERTIES
    // ==================================================

    public int OvenLevel =>
        ovenLevel;

    public int BoardSpaceLevel =>
        boardSpaceLevel;

    public int ShelfLevel =>
        shelfLevel;

    public int CustomerLevel =>
        customerLevel;

    public int MoneyMultiplierLevel =>
        moneyMultiplierLevel;

    public int CurrentRebirthCount =>
        RebirthProgression.CurrentRebirthCount;

    public int HighestTierCreatedThisRun =>
        RebirthProgression.HighestTierCreatedThisRun;

    public bool CampaignComplete =>
        RebirthProgression.CampaignComplete;

    public int NextRebirthNumber =>
        RebirthProgression.NextRebirthNumber;

    public int NextRebirthRequiredTier =>
        RebirthProgression.NextRequiredTier;

    public int NextRebirthRequiredCash =>
        RebirthProgression.NextRequiredCash;

    public int NextRebirthOvenUnlockLevel =>
        RebirthProgression.NextOvenLevelUnlock;

    public bool IsEligibleForNextRebirth =>
        EconomyManager.Instance != null &&
        RebirthProgression.CanRebirth(
            EconomyManager.Instance.CurrentCash
        );

    // ==================================================
    // GAMEPLAY VALUES
    // ==================================================

    public int MaxUnlockedDessertTier =>
        GetIntValue(
            ovenUpgrade,
            ovenLevel
        );

    public int ActiveBoardCells =>
        GetIntValue(
            boardSpaceUpgrade,
            boardSpaceLevel
        );

    public int ShelfCapacity =>
        GetIntValue(
            shelfUpgrade,
            shelfLevel
        );

    public int ActiveCustomerOrders =>
        GetIntValue(
            customerUpgrade,
            customerLevel
        );

    public float MoneyMultiplier =>
        GetFloatValue(
            moneyMultiplierUpgrade,
            moneyMultiplierLevel
        );

    // ==================================================
    // UNITY
    // ==================================================

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this;

        DontDestroyOnLoad(gameObject);

        ValidateDefinitions();
        ClampRuntimeLevels();
    }

    private void OnEnable()
    {
        if (Instance != this)
            return;

        GameplayEvents.DessertSpawned -=
            HandleCreatedDessert;
        GameplayEvents.DessertSpawned +=
            HandleCreatedDessert;
        GameplayEvents.DessertMerged -=
            HandleCreatedDessert;
        GameplayEvents.DessertMerged +=
            HandleCreatedDessert;
    }

    private void OnDisable()
    {
        GameplayEvents.DessertSpawned -=
            HandleCreatedDessert;
        GameplayEvents.DessertMerged -=
            HandleCreatedDessert;
    }

    private RebirthProgressionState RebirthProgression
    {
        get
        {
            if (rebirthProgression == null)
                rebirthProgression = new RebirthProgressionState();

            return rebirthProgression;
        }
    }

    private void HandleCreatedDessert(int tier)
    {
        RebirthProgression.RegisterCreatedTier(tier);
    }

    public bool RestoreRebirthProgression(
        int completedRebirthCount,
        int highestTierCreatedThisRun,
        bool campaignComplete)
    {
        return RebirthProgression.Restore(
            completedRebirthCount,
            highestTierCreatedThisRun,
            campaignComplete
        );
    }

    // ==================================================
    // LEVEL LOOKUP
    // ==================================================

    public int GetLevel(
        UpgradeType type)
    {
        switch (type)
        {
            case UpgradeType.Oven:
                return ovenLevel;

            case UpgradeType.BoardSpace:
                return boardSpaceLevel;

            case UpgradeType.Shelf:
                return shelfLevel;

            case UpgradeType.Customer:
                return customerLevel;

            case UpgradeType.MoneyMultiplier:
                return moneyMultiplierLevel;

            default:
                return 1;
        }
    }

    public int GetMaxLevel(
        UpgradeType type)
    {
        UpgradeDefinition definition =
            GetDefinition(type);

        if (definition == null)
            return 0;

        return definition.MaxLevel;
    }

    public bool IsMaxLevel(
        UpgradeType type)
    {
        int maxLevel =
            GetMaxLevel(type);

        if (maxLevel <= 0)
            return true;

        return GetLevel(type) >=
            maxLevel;
    }

    // ==================================================
    // DEFINITION LOOKUP
    // ==================================================

    /// <summary>
    /// Returns the UpgradeDefinition associated with
    /// the supplied upgrade type.
    ///
    /// This is public so systems such as the
    /// UpgradePurchaseManager and future upgrade UI
    /// can query progression data without duplicating
    /// definition references.
    /// </summary>
    public UpgradeDefinition GetDefinition(
        UpgradeType type)
    {
        switch (type)
        {
            case UpgradeType.Oven:
                return ovenUpgrade;

            case UpgradeType.BoardSpace:
                return boardSpaceUpgrade;

            case UpgradeType.Shelf:
                return shelfUpgrade;

            case UpgradeType.Customer:
                return customerUpgrade;

            case UpgradeType.MoneyMultiplier:
                return moneyMultiplierUpgrade;

            default:
                return null;
        }
    }

    // ==================================================
    // NEXT LEVEL / COST LOOKUP
    // ==================================================

    public UpgradeLevelData GetNextLevelData(
        UpgradeType type)
    {
        UpgradeDefinition definition =
            GetDefinition(type);

        if (definition == null)
            return null;

        int currentLevel =
            GetLevel(type);

        return definition.GetNextLevel(
            currentLevel
        );
    }

    public int GetNextUpgradeCost(
        UpgradeType type)
    {
        UpgradeLevelData nextLevel =
            GetNextLevelData(type);

        if (nextLevel == null)
            return 0;

        return nextLevel.UpgradeCost;
    }

    // ==================================================
    // DESSERT PROGRESSION
    // ==================================================

    public bool IsDessertTierUnlocked(
        int tier)
    {
        if (tier <= 0)
            return false;

        return tier <=
            MaxUnlockedDessertTier;
    }

    // ==================================================
    // CONTROLLED LEVEL CHANGE
    // ==================================================

    /// <summary>
    /// Attempts to apply a valid progression level.
    ///
    /// This method does NOT spend cash.
    /// Purchase validation belongs to
    /// UpgradePurchaseManager.
    ///
    /// It is used after the purchase manager has
    /// successfully validated and paid for an upgrade.
    /// </summary>
    public bool TrySetLevel(
        UpgradeType type,
        int newLevel)
    {
        UpgradeDefinition definition =
            GetDefinition(type);

        if (definition == null ||
            !definition.IsValid)
        {
            Debug.LogWarning(
                $"PROGRESSION SET FAILED | " +
                $"{type} | " +
                "Missing or invalid definition."
            );

            return false;
        }

        int currentLevel =
            GetLevel(type);

        if (newLevel < 1 ||
            newLevel > definition.MaxLevel)
        {
            Debug.LogWarning(
                $"PROGRESSION SET FAILED | " +
                $"{definition.DisplayName} | " +
                $"Requested Level {newLevel} " +
                $"is outside valid range " +
                $"1-{definition.MaxLevel}."
            );

            return false;
        }

        if (newLevel == currentLevel)
        {
            return false;
        }

        SetLevel(
            type,
            newLevel
        );

        return true;
    }

    // ==================================================
    // DEBUG UPGRADE
    // ==================================================

    /// <summary>
    /// Developer-only upgrade path.
    ///
    /// This intentionally ignores upgrade costs.
    /// Use UpgradePurchaseManager for real purchases.
    /// </summary>
    public bool TryUpgradeForDebug(
        UpgradeType type)
    {
        UpgradeDefinition definition =
            GetDefinition(type);

        if (definition == null)
            return false;

        int currentLevel =
            GetLevel(type);

        if (currentLevel >=
            definition.MaxLevel)
        {
            Debug.Log(
                $"DEBUG UPGRADE | " +
                $"{definition.DisplayName} " +
                "is already at maximum level."
            );

            return false;
        }

        SetLevel(
            type,
            currentLevel + 1
        );

        return true;
    }

    // ==================================================
    // INTERNAL LEVEL APPLICATION
    // ==================================================

    private void SetLevel(
        UpgradeType type,
        int newLevel)
    {
        UpgradeDefinition definition =
            GetDefinition(type);

        if (definition == null)
            return;

        newLevel =
            Mathf.Clamp(
                newLevel,
                1,
                definition.MaxLevel
            );

        switch (type)
        {
            case UpgradeType.Oven:
                ovenLevel = newLevel;
                break;

            case UpgradeType.BoardSpace:
                boardSpaceLevel = newLevel;
                break;

            case UpgradeType.Shelf:
                shelfLevel = newLevel;
                break;

            case UpgradeType.Customer:
                customerLevel = newLevel;
                break;

            case UpgradeType.MoneyMultiplier:
                moneyMultiplierLevel =
                    newLevel;
                break;
        }

        UpgradeLevelChanged?.Invoke(
            type,
            newLevel
        );

        Debug.Log(
            $"UPGRADE | " +
            $"{definition.DisplayName} " +
            $"reached Level {newLevel}."
        );

        DebugCurrentProgression();
    }

    // ==================================================
    // GAMEPLAY VALUE LOOKUP
    // ==================================================

    private int GetIntValue(
        UpgradeDefinition definition,
        int level)
    {
        if (definition == null)
            return 0;

        UpgradeLevelData levelData =
            definition.GetLevel(level);

        if (levelData == null)
            return 0;

        return levelData.IntValue;
    }

    private float GetFloatValue(
        UpgradeDefinition definition,
        int level)
    {
        if (definition == null)
            return 1f;

        UpgradeLevelData levelData =
            definition.GetLevel(level);

        if (levelData == null)
            return 1f;

        return levelData.FloatValue;
    }

    // ==================================================
    // VALIDATION
    // ==================================================

    public bool ValidateRestorationDefinitions(out string reason)
    {
        foreach (UpgradeType type in new[] { UpgradeType.Oven, UpgradeType.BoardSpace,
            UpgradeType.Shelf, UpgradeType.Customer, UpgradeType.MoneyMultiplier })
        {
            var definition = GetDefinition(type);
            if (definition == null || !definition.IsValid || definition.UpgradeType != type ||
                definition.MaxLevel < 1 || definition.GetLevel(GetLevel(type)) == null)
            { reason = "Missing or invalid progression definition: " + type; return false; }
        }
        if (MaxUnlockedDessertTier <= 0 || ActiveBoardCells <= 0 || ShelfCapacity < 0 ||
            ActiveCustomerOrders <= 0 || float.IsNaN(MoneyMultiplier) ||
            float.IsInfinity(MoneyMultiplier) || MoneyMultiplier <= 0)
        { reason = "Progression gameplay values are invalid."; return false; }
        reason = null;
        return true;
    }

    private void ClampRuntimeLevels()
    {
        ovenLevel =
            ClampLevel(
                ovenLevel,
                ovenUpgrade
            );

        boardSpaceLevel =
            ClampLevel(
                boardSpaceLevel,
                boardSpaceUpgrade
            );

        shelfLevel =
            ClampLevel(
                shelfLevel,
                shelfUpgrade
            );

        customerLevel =
            ClampLevel(
                customerLevel,
                customerUpgrade
            );

        moneyMultiplierLevel =
            ClampLevel(
                moneyMultiplierLevel,
                moneyMultiplierUpgrade
            );
    }

    private int ClampLevel(
        int level,
        UpgradeDefinition definition)
    {
        if (definition == null ||
            definition.MaxLevel <= 0)
        {
            return 1;
        }

        return Mathf.Clamp(
            level,
            1,
            definition.MaxLevel
        );
    }

    private void ValidateDefinitions()
    {
        ValidateDefinition(
            ovenUpgrade,
            UpgradeType.Oven
        );

        ValidateDefinition(
            boardSpaceUpgrade,
            UpgradeType.BoardSpace
        );

        ValidateDefinition(
            shelfUpgrade,
            UpgradeType.Shelf
        );

        ValidateDefinition(
            customerUpgrade,
            UpgradeType.Customer
        );

        ValidateDefinition(
            moneyMultiplierUpgrade,
            UpgradeType.MoneyMultiplier
        );
    }

    private void ValidateDefinition(
        UpgradeDefinition definition,
        UpgradeType expectedType)
    {
        if (definition == null)
        {
            Debug.LogError(
                $"Progression: Missing " +
                $"{expectedType} definition."
            );

            return;
        }

        if (!definition.IsValid)
        {
            Debug.LogError(
                $"Progression: " +
                $"{definition.name} is invalid."
            );
        }

        if (definition.UpgradeType !=
            expectedType)
        {
            Debug.LogError(
                $"Progression: " +
                $"{definition.name} has " +
                $"type {definition.UpgradeType}, " +
                $"expected {expectedType}."
            );
        }
    }

    // ==================================================
    // DEBUG
    // ==================================================

    [ContextMenu("Debug Progression")]
    private void DebugCurrentProgression()
    {
        Debug.Log(
            "PROGRESSION | " +
            $"Oven L{ovenLevel} " +
            $"(Max T{MaxUnlockedDessertTier}) | " +
            $"Board L{boardSpaceLevel} " +
            $"({ActiveBoardCells} cells) | " +
            $"Shelf L{shelfLevel} " +
            $"({ShelfCapacity} slots) | " +
            $"Customer L{customerLevel} " +
            $"({ActiveCustomerOrders} orders) | " +
            $"Money L{moneyMultiplierLevel} " +
            $"(x{MoneyMultiplier:0.##})"
        );
    }

    [ContextMenu("Debug Upgrade Oven")]
    private void DebugUpgradeOven()
    {
        TryUpgradeForDebug(
            UpgradeType.Oven
        );
    }

    [ContextMenu("Debug Upgrade Board")]
    private void DebugUpgradeBoard()
    {
        TryUpgradeForDebug(
            UpgradeType.BoardSpace
        );
    }

    [ContextMenu("Debug Upgrade Shelf")]
    private void DebugUpgradeShelf()
    {
        TryUpgradeForDebug(
            UpgradeType.Shelf
        );
    }

    [ContextMenu("Debug Upgrade Customer")]
    private void DebugUpgradeCustomer()
    {
        TryUpgradeForDebug(
            UpgradeType.Customer
        );
    }

    [ContextMenu(
        "Debug Upgrade Money Multiplier"
    )]
    private void DebugUpgradeMoneyMultiplier()
    {
        TryUpgradeForDebug(
            UpgradeType.MoneyMultiplier
        );
    }

    // ==================================================
// PERSISTENCE
// ==================================================

public void RestoreProgression(
    int restoredOvenLevel,
    int restoredBoardSpaceLevel,
    int restoredShelfLevel,
    int restoredCustomerLevel,
    int restoredMoneyMultiplierLevel)
{
    /*
     * Save data is external state.
     *
     * Never trust its level values directly.
     * Each value is clamped against the
     * authoritative UpgradeDefinition.
     */

    ovenLevel =
        ClampLevel(
            restoredOvenLevel,
            ovenUpgrade
        );

    boardSpaceLevel =
        ClampLevel(
            restoredBoardSpaceLevel,
            boardSpaceUpgrade
        );

    shelfLevel =
        ClampLevel(
            restoredShelfLevel,
            shelfUpgrade
        );

    customerLevel =
        ClampLevel(
            restoredCustomerLevel,
            customerUpgrade
        );

    moneyMultiplierLevel =
        ClampLevel(
            restoredMoneyMultiplierLevel,
            moneyMultiplierUpgrade
        );

    /*
     * Notify every progression consumer.
     *
     * This is intentional even when a restored
     * level happens to equal the current level.
     * Loading establishes authoritative state,
     * so UI/gameplay systems must be given a
     * chance to refresh from that state.
     */

    UpgradeLevelChanged?.Invoke(
        UpgradeType.Oven,
        ovenLevel
    );

    UpgradeLevelChanged?.Invoke(
        UpgradeType.BoardSpace,
        boardSpaceLevel
    );

    UpgradeLevelChanged?.Invoke(
        UpgradeType.Shelf,
        shelfLevel
    );

    UpgradeLevelChanged?.Invoke(
        UpgradeType.Customer,
        customerLevel
    );

    UpgradeLevelChanged?.Invoke(
        UpgradeType.MoneyMultiplier,
        moneyMultiplierLevel
    );

    Debug.Log(
        "PROGRESSION RESTORED | " +
        $"Oven L{ovenLevel} | " +
        $"Board L{boardSpaceLevel} | " +
        $"Shelf L{shelfLevel} | " +
        $"Customer L{customerLevel} | " +
        $"Money L{moneyMultiplierLevel}"
    );

    DebugCurrentProgression();
}
[ContextMenu("Debug Restore Test Progression")]
private void DebugRestoreTestProgression()
{
    RestoreProgression(
        2,
        2,
        2,
        2,
        2
    );
}
}
