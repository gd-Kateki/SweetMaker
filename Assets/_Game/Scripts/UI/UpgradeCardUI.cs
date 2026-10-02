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

        progressionManager.UpgradeLevelChanged +=
            HandleUpgradeLevelChanged;

        Refresh();
    }

    private void OnDestroy()
    {
        if (progressionManager != null)
        {
            progressionManager.UpgradeLevelChanged -=
                HandleUpgradeLevelChanged;
        }
    }

    // ==================================================
    // REFRESH
    // ==================================================

    public void Refresh()
    {
        ResolveReferences();

        if (upgradeDefinition == null)
        {
            Debug.LogWarning(
                $"UpgradeCardUI ({name}): " +
                "UpgradeDefinition is missing."
            );

            return;
        }

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
        {
            Debug.LogWarning(
                $"UpgradeCardUI ({name}): " +
                "PlayerProgressionManager not found."
            );

            return;
        }

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
        {
            Debug.LogError(
                $"UpgradeCardUI ({name}): " +
                $"No level data exists for " +
                $"{upgradeDefinition.DisplayName} " +
                $"Level {currentLevel}."
            );

            return;
        }

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
        {
            Debug.LogError(
                $"UpgradeCardUI ({name}): " +
                $"Next level data is missing for " +
                $"{upgradeDefinition.DisplayName}."
            );

            return;
        }

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
    // PROGRESSION EVENTS
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
        if (progressionManager != null)
            return;

        progressionManager =
            PlayerProgressionManager.Instance;

        if (progressionManager == null)
        {
            progressionManager =
                FindFirstObjectByType<
                    PlayerProgressionManager>();
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