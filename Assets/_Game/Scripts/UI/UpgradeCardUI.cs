using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class UpgradeCardUI : MonoBehaviour
{
    [Header("Upgrade")]
    [SerializeField]
    private UpgradeDefinition upgradeDefinition;

    [Header("Text")]
    [SerializeField]
    private TMP_Text upgradeNameText;

    [SerializeField]
    private TMP_Text levelText;

    [SerializeField]
    private TMP_Text effectLabelText;

    [SerializeField]
    private TMP_Text valueText;

    [SerializeField]
    private TMP_Text priceText;

    [Header("Button")]
    [SerializeField]
    private Button purchaseButton;

    private PlayerProgressionManager
        progressionManager;

    private UpgradePurchaseManager
        purchaseManager;

    // ==================================================
    // UNITY
    // ==================================================

    private void Start()
    {
        ResolveReferences();

        if (upgradeDefinition == null)
        {
            Debug.LogError(
                $"UpgradeCardUI ({name}): " +
                "UpgradeDefinition is missing."
            );

            return;
        }

        if (progressionManager == null)
        {
            Debug.LogError(
                $"UpgradeCardUI ({name}): " +
                "PlayerProgressionManager not found."
            );

            return;
        }

        if (purchaseManager == null)
        {
            Debug.LogError(
                $"UpgradeCardUI ({name}): " +
                "UpgradePurchaseManager not found."
            );

            return;
        }

        progressionManager.UpgradeLevelChanged +=
            HandleUpgradeLevelChanged;

        if (purchaseButton != null)
        {
            purchaseButton.onClick.AddListener(
                HandlePurchaseClicked
            );
        }

        Refresh();
    }

    private void OnDestroy()
    {
        if (progressionManager != null)
        {
            progressionManager.UpgradeLevelChanged -=
                HandleUpgradeLevelChanged;
        }

        if (purchaseButton != null)
        {
            purchaseButton.onClick.RemoveListener(
                HandlePurchaseClicked
            );
        }
    }

    // ==================================================
    // PURCHASE
    // ==================================================

    private void HandlePurchaseClicked()
    {
        if (upgradeDefinition == null)
            return;

        ResolveReferences();

        if (purchaseManager == null)
        {
            Debug.LogError(
                $"UpgradeCardUI ({name}): " +
                "Cannot purchase because " +
                "UpgradePurchaseManager was not found."
            );

            return;
        }

        UpgradeType type =
            upgradeDefinition.UpgradeType;

        bool purchased =
            purchaseManager.TryPurchaseUpgrade(
                type
            );

        if (!purchased)
        {
            Debug.Log(
                $"UPGRADE CARD | " +
                $"Purchase not completed | " +
                $"{upgradeDefinition.DisplayName}"
            );
        }

        /*
         * Successful purchases already trigger
         * UpgradeLevelChanged through the progression
         * system, which refreshes this card.
         *
         * We still refresh here so the UI remains
         * correct after a failed attempt as well.
         */
        Refresh();
    }

    // ==================================================
    // REFRESH
    // ==================================================

    public void Refresh()
    {
        ResolveReferences();

        if (upgradeDefinition == null)
            return;

        if (!upgradeDefinition.IsValid)
        {
            Debug.LogError(
                $"UpgradeCardUI ({name}): " +
                $"{upgradeDefinition.name} " +
                "is not a valid upgrade definition."
            );

            return;
        }

        if (progressionManager == null)
            return;

        UpgradeType type =
            upgradeDefinition.UpgradeType;

        int currentLevel =
            progressionManager.GetLevel(
                type
            );

        UpgradeLevelData currentData =
            upgradeDefinition.GetLevel(
                currentLevel
            );

        if (currentData == null)
            return;

        if (upgradeDefinition.IsMaxLevel(
                currentLevel))
        {
            ShowMaxLevel(
                currentLevel,
                currentData
            );

            return;
        }

        UpgradeLevelData nextData =
            upgradeDefinition.GetNextLevel(
                currentLevel
            );

        if (nextData == null)
            return;

        ShowUpgrade(
            currentLevel,
            currentData,
            nextData
        );
    }

    // ==================================================
    // NORMAL DISPLAY
    // ==================================================

    private void ShowUpgrade(
        int currentLevel,
        UpgradeLevelData currentData,
        UpgradeLevelData nextData)
    {
        UpgradeType type =
            upgradeDefinition.UpgradeType;

        if (upgradeNameText != null)
        {
            upgradeNameText.text =
                upgradeDefinition.DisplayName;
        }

        if (levelText != null)
        {
            levelText.text =
                $"Level {currentLevel}";
        }

        if (effectLabelText != null)
        {
            effectLabelText.text =
                GetEffectLabel(type);
        }

        if (valueText != null)
        {
            string currentValue =
                GetFormattedValue(
                    type,
                    currentData
                );

            string nextValue =
                GetFormattedValue(
                    type,
                    nextData
                );

            valueText.text =
                $"{currentValue} → {nextValue}";
        }

        if (priceText != null)
        {
            priceText.text =
                $"${nextData.UpgradeCost:N0}";
        }

        if (purchaseButton != null)
        {
            /*
             * Affordability feedback will be handled
             * properly in 12.7.4.5.
             *
             * For this milestone, the button remains
             * available whenever there is a next level.
             * UpgradePurchaseManager itself safely
             * rejects unaffordable purchases.
             */
            purchaseButton.interactable =
                true;
        }
    }

    // ==================================================
    // MAX DISPLAY
    // ==================================================

    private void ShowMaxLevel(
        int currentLevel,
        UpgradeLevelData currentData)
    {
        UpgradeType type =
            upgradeDefinition.UpgradeType;

        if (upgradeNameText != null)
        {
            upgradeNameText.text =
                upgradeDefinition.DisplayName;
        }

        if (levelText != null)
        {
            levelText.text =
                $"Level {currentLevel}";
        }

        if (effectLabelText != null)
        {
            effectLabelText.text =
                GetEffectLabel(type);
        }

        if (valueText != null)
        {
            valueText.text =
                GetFormattedValue(
                    type,
                    currentData
                );
        }

        if (priceText != null)
        {
            priceText.text =
                "MAX";
        }

        if (purchaseButton != null)
        {
            purchaseButton.interactable =
                false;
        }
    }

    // ==================================================
    // EFFECT LABEL
    // ==================================================

    private string GetEffectLabel(
        UpgradeType type)
    {
        switch (type)
        {
            case UpgradeType.Oven:
                return "Max Dessert Tier";

            case UpgradeType.BoardSpace:
                return "Board Capacity";

            case UpgradeType.Shelf:
                return "Shelf Capacity";

            case UpgradeType.Customer:
                return "Active Customers";

            case UpgradeType.MoneyMultiplier:
                return "Money Multiplier";

            default:
                return "Upgrade Effect";
        }
    }

    // ==================================================
    // VALUE FORMATTING
    // ==================================================

    private string GetFormattedValue(
        UpgradeType type,
        UpgradeLevelData levelData)
    {
        if (levelData == null)
            return "-";

        switch (type)
        {
            case UpgradeType.Oven:
                return
                    $"T{levelData.IntValue}";

            case UpgradeType.BoardSpace:
                return
                    FormatCount(
                        levelData.IntValue,
                        "Cell",
                        "Cells"
                    );

            case UpgradeType.Shelf:
                return
                    FormatCount(
                        levelData.IntValue,
                        "Slot",
                        "Slots"
                    );

            case UpgradeType.Customer:
                return
                    FormatCount(
                        levelData.IntValue,
                        "Customer",
                        "Customers"
                    );

            case UpgradeType.MoneyMultiplier:
                return
                    $"×{levelData.FloatValue:0.0#}";

            default:
                return "-";
        }
    }

    private string FormatCount(
        int value,
        string singular,
        string plural)
    {
        string label =
            value == 1
                ? singular
                : plural;

        return
            $"{value} {label}";
    }

    // ==================================================
    // EVENTS
    // ==================================================

    private void HandleUpgradeLevelChanged(
        UpgradeType type,
        int newLevel)
    {
        if (upgradeDefinition == null)
            return;

        if (type !=
            upgradeDefinition.UpgradeType)
        {
            return;
        }

        Refresh();
    }

    // ==================================================
    // REFERENCES
    // ==================================================

    private void ResolveReferences()
    {
        if (progressionManager == null)
        {
            progressionManager =
                PlayerProgressionManager.Instance;

            if (progressionManager == null)
            {
                progressionManager =
                    FindFirstObjectByType<
                        PlayerProgressionManager>();
            }
        }

        if (purchaseManager == null)
        {
            purchaseManager =
                UpgradePurchaseManager.Instance;

            if (purchaseManager == null)
            {
                purchaseManager =
                    FindFirstObjectByType<
                        UpgradePurchaseManager>();
            }
        }
    }

    // ==================================================
    // DEBUG
    // ==================================================

    [ContextMenu("Debug Refresh Card")]
    private void DebugRefreshCard()
    {
        Refresh();
    }
}