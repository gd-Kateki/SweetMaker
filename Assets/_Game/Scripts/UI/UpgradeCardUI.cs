using System.Collections;
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

    [SerializeField]
    private TMP_Text buttonText;

    [Header("State")]
    [SerializeField]
    private GameObject maxLevelBadge;

    [Header("Button")]
    [SerializeField]
    private Button purchaseButton;

    [Header("Feedback")]
    [Min(0.1f)]
    [SerializeField]
    private float feedbackDuration = 1.25f;

    private PlayerProgressionManager
        progressionManager;

    private UpgradePurchaseManager
        purchaseManager;

    private EconomyManager
        economyManager;

    private Coroutine feedbackCoroutine;

    private bool showingPurchaseFeedback;

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

        if (economyManager == null)
        {
            Debug.LogError(
                $"UpgradeCardUI ({name}): " +
                "EconomyManager not found."
            );

            return;
        }

        progressionManager.UpgradeLevelChanged +=
            HandleUpgradeLevelChanged;

        economyManager.CashChanged +=
            HandleCashChanged;

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

        if (economyManager != null)
        {
            economyManager.CashChanged -=
                HandleCashChanged;
        }

        if (purchaseButton != null)
        {
            purchaseButton.onClick.RemoveListener(
                HandlePurchaseClicked
            );
        }

        if (feedbackCoroutine != null)
        {
            StopCoroutine(
                feedbackCoroutine
            );

            feedbackCoroutine = null;
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

        /*
         * Capture affordability before attempting
         * the transaction so insufficient cash can
         * be distinguished from another failure.
         */
        bool couldAffordBeforePurchase =
            purchaseManager
                .CanAffordNextUpgrade(
                    type
                );

        bool purchased =
            purchaseManager.TryPurchaseUpgrade(
                type
            );

        // ------------------------------------------
        // FAILED PURCHASE
        // ------------------------------------------

        if (!purchased)
        {
            Debug.Log(
                $"UPGRADE CARD | " +
                $"Purchase not completed | " +
                $"{upgradeDefinition.DisplayName}"
            );

            if (!couldAffordBeforePurchase)
            {
                ShowInsufficientCashFeedback();
            }

            return;
        }

        // ------------------------------------------
        // SUCCESSFUL PURCHASE
        // ------------------------------------------

        /*
         * CashChanged and UpgradeLevelChanged have
         * already fired during the transaction.
         *
         * Refresh once more to guarantee the card
         * reflects its new progression state.
         */
        Refresh();

        /*
         * Show temporary success confirmation after
         * the new card state has been established.
         */
        ShowPurchaseSuccessFeedback();
    }

    // ==================================================
    // INSUFFICIENT CASH FEEDBACK
    // ==================================================

    private void ShowInsufficientCashFeedback()
    {
        if (feedbackCoroutine != null)
        {
            StopCoroutine(
                feedbackCoroutine
            );
        }

        feedbackCoroutine =
            StartCoroutine(
                InsufficientCashFeedbackRoutine()
            );
    }

    private IEnumerator
        InsufficientCashFeedbackRoutine()
    {
        showingPurchaseFeedback =
            true;

        if (buttonText != null)
        {
            buttonText.text =
                "NOT ENOUGH CASH";
        }

        yield return new WaitForSecondsRealtime(
            feedbackDuration
        );

        showingPurchaseFeedback =
            false;

        feedbackCoroutine =
            null;

        Refresh();
    }

    // ==================================================
    // PURCHASE SUCCESS FEEDBACK
    // ==================================================

    private void ShowPurchaseSuccessFeedback()
    {
        if (feedbackCoroutine != null)
        {
            StopCoroutine(
                feedbackCoroutine
            );
        }

        feedbackCoroutine =
            StartCoroutine(
                PurchaseSuccessFeedbackRoutine()
            );
    }

    private IEnumerator
        PurchaseSuccessFeedbackRoutine()
    {
        showingPurchaseFeedback =
            true;

        if (buttonText != null)
        {
            buttonText.text =
                "UPGRADED!";
        }

        yield return new WaitForSecondsRealtime(
            feedbackDuration
        );

        showingPurchaseFeedback =
            false;

        feedbackCoroutine =
            null;

        /*
         * Restore the correct final state.
         *
         * This will become either UPGRADE or
         * MAX LEVEL depending on progression.
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

        /*
         * Max level has priority over the normal
         * upgrade presentation.
         */
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
    // NORMAL UPGRADE DISPLAY
    // ==================================================

    private void ShowUpgrade(
        int currentLevel,
        UpgradeLevelData currentData,
        UpgradeLevelData nextData)
    {
        UpgradeType type =
            upgradeDefinition.UpgradeType;

        /*
         * A normal upgrade must never display the
         * completed-state badge.
         */
        if (maxLevelBadge != null)
        {
            maxLevelBadge.SetActive(
                false
            );
        }

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
            priceText.text = type == UpgradeType.Oven
                ? "REBIRTH"
                : $"${nextData.UpgradeCost:N0}";
        }

        /*
         * Preserve temporary feedback while it is
         * being displayed.
         */
        if (buttonText != null &&
            !showingPurchaseFeedback)
        {
            buttonText.text =
                "UPGRADE";
        }

        bool unlockedByRebirth = purchaseManager != null &&
            purchaseManager.IsNextUpgradeUnlockedByRebirth(type);

        if (purchaseButton != null)
        {
            purchaseButton.interactable =
                unlockedByRebirth;
        }

        if (buttonText != null && !showingPurchaseFeedback)
        {
            buttonText.text = unlockedByRebirth
                ? "UPGRADE"
                : type == UpgradeType.Oven ? "REBIRTH" : "LOCKED";
        }
    }

    // ==================================================
    // MAX LEVEL DISPLAY
    // ==================================================

    private void ShowMaxLevel(
        int currentLevel,
        UpgradeLevelData currentData)
    {
        UpgradeType type =
            upgradeDefinition.UpgradeType;

        /*
         * The dedicated badge communicates that
         * this upgrade has been fully completed.
         */
        if (maxLevelBadge != null)
        {
            maxLevelBadge.SetActive(
                true
            );
        }

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

        /*
         * Max-level cards display only their final
         * gameplay value rather than current → next.
         */
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

        /*
         * If the player just purchased the final
         * level, preserve UPGRADED! until its
         * feedback timer finishes.
         */
        if (buttonText != null &&
            !showingPurchaseFeedback)
        {
            buttonText.text =
                "MAX LEVEL";
        }

        /*
         * A max-level upgrade can never be
         * purchased again.
         */
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

            case UpgradeType.Luck:
                return "Bonus Dessert Chance";

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

            case UpgradeType.Luck:
                return
                    $"×{levelData.FloatValue:0.##}";

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

    private void HandleCashChanged(
        int newCash)
    {
        Refresh();
    }

    // ==================================================
    // REFERENCES
    // ==================================================

    private void ResolveReferences()
    {
        /*
         * PlayerProgressionManager persists between
         * scenes.
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
         * UpgradePurchaseManager belongs to the
         * Main Bakery scene.
         */
        if (purchaseManager == null)
        {
            purchaseManager =
                UpgradePurchaseManager.Instance;

            if (purchaseManager == null)
            {
                purchaseManager =
                    FindAnyObjectByType<
                        UpgradePurchaseManager>();
            }
        }

        /*
         * EconomyManager persists between scenes
         * and owns the shared cash balance.
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

    // ==================================================
    // DEBUG
    // ==================================================

    [ContextMenu("Debug Refresh Card")]
    private void DebugRefreshCard()
    {
        Refresh();
    }
}