using System;
using UnityEngine;

public class PlayerProgressionManager : MonoBehaviour
{
    public static PlayerProgressionManager Instance
    {
        get;
        private set;
    }

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

    public event Action<UpgradeType, int>
        UpgradeLevelChanged;

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

    private void Awake()
    {
        if (Instance != null &&
            Instance != this)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this;

        ValidateDefinitions();
        ClampRuntimeLevels();
    }

    private void OnDestroy()
    {
        if (Instance == this)
        {
            Instance = null;
        }
    }

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

    // --------------------------------------------------
    // DESSERT PROGRESSION
    // --------------------------------------------------

    public bool IsDessertTierUnlocked(
        int tier)
    {
        if (tier <= 0)
            return false;

        return tier <=
            MaxUnlockedDessertTier;
    }

    // --------------------------------------------------
    // DEBUG UPGRADE
    // --------------------------------------------------

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
                $"UPGRADE | " +
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

    // --------------------------------------------------
    // DEFINITION LOOKUP
    // --------------------------------------------------

    private UpgradeDefinition GetDefinition(
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

    // --------------------------------------------------
    // VALIDATION
    // --------------------------------------------------

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

    // --------------------------------------------------
    // DEBUG
    // --------------------------------------------------

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

    [ContextMenu("Debug Upgrade Money Multiplier")]
    private void DebugUpgradeMoneyMultiplier()
    {
        TryUpgradeForDebug(
            UpgradeType.MoneyMultiplier
        );
    }
}