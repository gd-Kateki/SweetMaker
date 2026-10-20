using System;
using UnityEngine;

public class UpgradePurchaseManager : MonoBehaviour
{
    public static UpgradePurchaseManager Instance
    {
        get;
        private set;
    }

    [Header("References")]
    [SerializeField]
    private PlayerProgressionManager
        progressionManager;

    [SerializeField]
    private EconomyManager
        economyManager;

    // ==================================================
    // EVENTS
    // ==================================================

    public event Action<
        UpgradeType,
        int,
        int
    > UpgradePurchased;

    // type, new level, amount spent

    // ==================================================
    // UNITY
    // ==================================================

    private void Awake()
    {
        if (Instance != null &&
            Instance != this)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this;
    }

    private void Start()
    {
        ResolveReferences();

        if (progressionManager == null)
        {
            Debug.LogError(
                "UpgradePurchaseManager: " +
                "PlayerProgressionManager " +
                "could not be found."
            );
        }

        if (economyManager == null)
        {
            Debug.LogError(
                "UpgradePurchaseManager: " +
                "EconomyManager could not " +
                "be found."
            );
        }
    }

    private void OnDestroy()
    {
        if (Instance == this)
        {
            Instance = null;
        }
    }

    // ==================================================
    // REFERENCES
    // ==================================================

    private void ResolveReferences()
    {
        /*
         * PlayerProgressionManager is persistent.
         *
         * Always prefer the authoritative singleton
         * carrying the player's current progression.
         */
        if (PlayerProgressionManager.Instance != null)
        {
            progressionManager =
                PlayerProgressionManager.Instance;
        }
        else if (progressionManager == null)
        {
            progressionManager =
                FindAnyObjectByType<
                    PlayerProgressionManager>();
        }

        /*
         * EconomyManager is also persistent.
         *
         * Always prefer its singleton so this manager
         * never keeps a stale scene reference after
         * navigation.
         */
        if (EconomyManager.Instance != null)
        {
            economyManager =
                EconomyManager.Instance;
        }
        else if (economyManager == null)
        {
            economyManager =
                FindAnyObjectByType<
                    EconomyManager>();
        }
    }

    private bool EnsureReferences()
    {
        ResolveReferences();

        return progressionManager != null &&
               economyManager != null;
    }

    // ==================================================
    // QUERY
    // ==================================================

    public UpgradeDefinition GetDefinition(
        UpgradeType type)
    {
        ResolveReferences();

        if (progressionManager == null)
            return null;

        return progressionManager
            .GetDefinition(type);
    }

    public int GetCurrentLevel(
        UpgradeType type)
    {
        ResolveReferences();

        if (progressionManager == null)
            return 0;

        return progressionManager
            .GetLevel(type);
    }

    public UpgradeLevelData GetNextLevel(
        UpgradeType type)
    {
        UpgradeDefinition definition =
            GetDefinition(type);

        if (definition == null)
            return null;

        int currentLevel =
            GetCurrentLevel(type);

        return definition.GetNextLevel(
            currentLevel
        );
    }

    public int GetNextUpgradeCost(
        UpgradeType type)
    {
        UpgradeLevelData nextLevel =
            GetNextLevel(type);

        if (nextLevel == null)
            return 0;

        return nextLevel.UpgradeCost;
    }

    public bool IsMaxLevel(
        UpgradeType type)
    {
        ResolveReferences();

        if (progressionManager == null)
            return true;

        return progressionManager
            .IsMaxLevel(type);
    }

    public bool CanAffordNextUpgrade(
        UpgradeType type)
    {
        ResolveReferences();

        if (economyManager == null)
            return false;

        if (IsMaxLevel(type))
            return false;

        UpgradeLevelData nextLevel =
            GetNextLevel(type);

        if (nextLevel == null)
            return false;

        return economyManager.CanAfford(
            nextLevel.UpgradeCost
        );
    }

    public bool CanPurchaseUpgrade(
        UpgradeType type)
    {
        if (!EnsureReferences())
            return false;

        UpgradeDefinition definition =
            GetDefinition(type);

        if (definition == null ||
            !definition.IsValid)
        {
            return false;
        }

        if (IsMaxLevel(type))
            return false;

        UpgradeLevelData nextLevel =
            GetNextLevel(type);

        if (nextLevel == null)
            return false;

        return economyManager.CanAfford(
            nextLevel.UpgradeCost
        );
    }

    // ==================================================
    // PURCHASE
    // ==================================================

    public bool TryPurchaseUpgrade(
        UpgradeType type)
    {
        /*
         * Re-resolve immediately before every
         * transaction.
         *
         * This is important because EconomyManager
         * and PlayerProgressionManager survive scene
         * changes while this purchase manager is
         * scene-local.
         */
        if (!EnsureReferences())
        {
            Debug.LogWarning(
                $"UPGRADE PURCHASE FAILED | " +
                $"{type} | Missing manager. | " +
                $"Progression: " +
                $"{(progressionManager != null)} | " +
                $"Economy: " +
                $"{(economyManager != null)}"
            );

            return false;
        }

        UpgradeDefinition definition =
            GetDefinition(type);

        if (definition == null ||
            !definition.IsValid)
        {
            Debug.LogWarning(
                $"UPGRADE PURCHASE FAILED | " +
                $"{type} | Invalid definition."
            );

            return false;
        }

        int currentLevel =
            progressionManager.GetLevel(
                type
            );

        if (definition.IsMaxLevel(
                currentLevel))
        {
            Debug.Log(
                $"UPGRADE PURCHASE BLOCKED | " +
                $"{definition.DisplayName} | " +
                "Already at maximum level."
            );

            return false;
        }

        UpgradeLevelData nextLevel =
            definition.GetNextLevel(
                currentLevel
            );

        if (nextLevel == null)
        {
            Debug.LogWarning(
                $"UPGRADE PURCHASE FAILED | " +
                $"{definition.DisplayName} | " +
                "Next level could not be found."
            );

            return false;
        }

        int cost =
            nextLevel.UpgradeCost;

        if (!economyManager.CanAfford(cost))
        {
            Debug.Log(
                $"UPGRADE PURCHASE BLOCKED | " +
                $"{definition.DisplayName} | " +
                $"Cost: ${cost} | " +
                $"Cash: " +
                $"${economyManager.CurrentCash}"
            );

            return false;
        }

        // ----------------------------------------------
        // TRANSACTION
        // ----------------------------------------------

        if (!economyManager.TrySpendCash(
                cost))
        {
            return false;
        }

        bool upgraded =
            progressionManager.TrySetLevel(
                type,
                nextLevel.Level
            );

        if (!upgraded)
        {
            /*
             * The progression operation failed after
             * payment. Refund so the transaction does
             * not leave the player in a bad state.
             */
            economyManager.AddCash(
                cost
            );

            Debug.LogError(
                $"UPGRADE PURCHASE FAILED | " +
                $"{definition.DisplayName} | " +
                $"Progression rejected Level " +
                $"{nextLevel.Level}. " +
                $"${cost} refunded."
            );

            return false;
        }

        // ----------------------------------------------
        // SUCCESS
        // ----------------------------------------------

        UpgradePurchased?.Invoke(
            type,
            nextLevel.Level,
            cost
        );

        Debug.Log(
            $"UPGRADE PURCHASED | " +
            $"{definition.DisplayName} | " +
            $"Level {currentLevel} → " +
            $"Level {nextLevel.Level} | " +
            $"Cost: ${cost} | " +
            $"Remaining Cash: " +
            $"${economyManager.CurrentCash}"
        );

        return true;
    }

    // ==================================================
    // DEBUG PURCHASES
    // ==================================================

    [ContextMenu("Debug Purchase Oven")]
    private void DebugPurchaseOven()
    {
        TryPurchaseUpgrade(
            UpgradeType.Oven
        );
    }

    [ContextMenu("Debug Purchase Board")]
    private void DebugPurchaseBoard()
    {
        TryPurchaseUpgrade(
            UpgradeType.BoardSpace
        );
    }

    [ContextMenu("Debug Purchase Shelf")]
    private void DebugPurchaseShelf()
    {
        TryPurchaseUpgrade(
            UpgradeType.Shelf
        );
    }

    [ContextMenu("Debug Purchase Customer")]
    private void DebugPurchaseCustomer()
    {
        TryPurchaseUpgrade(
            UpgradeType.Customer
        );
    }

    [ContextMenu(
        "Debug Purchase Money Multiplier"
    )]
    private void
        DebugPurchaseMoneyMultiplier()
    {
        TryPurchaseUpgrade(
            UpgradeType.MoneyMultiplier
        );
    }

    [ContextMenu("Debug Purchase State")]
    private void DebugPurchaseState()
    {
        DebugUpgradeState(
            UpgradeType.Oven
        );

        DebugUpgradeState(
            UpgradeType.BoardSpace
        );

        DebugUpgradeState(
            UpgradeType.Shelf
        );

        DebugUpgradeState(
            UpgradeType.Customer
        );

        DebugUpgradeState(
            UpgradeType.MoneyMultiplier
        );
    }

    private void DebugUpgradeState(
        UpgradeType type)
    {
        UpgradeDefinition definition =
            GetDefinition(type);

        if (definition == null)
        {
            Debug.Log(
                $"PURCHASE STATE | " +
                $"{type} | No definition."
            );

            return;
        }

        int currentLevel =
            GetCurrentLevel(type);

        if (definition.IsMaxLevel(
                currentLevel))
        {
            Debug.Log(
                $"PURCHASE STATE | " +
                $"{definition.DisplayName} | " +
                $"Level {currentLevel} | MAX"
            );

            return;
        }

        UpgradeLevelData nextLevel =
            definition.GetNextLevel(
                currentLevel
            );

        if (nextLevel == null)
            return;

        Debug.Log(
            $"PURCHASE STATE | " +
            $"{definition.DisplayName} | " +
            $"Level {currentLevel} → " +
            $"{nextLevel.Level} | " +
            $"Cost: " +
            $"${nextLevel.UpgradeCost} | " +
            $"Affordable: " +
            $"{CanAffordNextUpgrade(type)}"
        );
    }
}