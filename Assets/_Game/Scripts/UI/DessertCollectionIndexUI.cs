using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public sealed class DessertCollectionIndexUI : MonoBehaviour
{
    [Header("Panel")]
    [SerializeField] private GameObject overlay;
    [SerializeField] private Button openButton;
    [SerializeField] private Button closeButton;

    [Header("Progress")]
    [SerializeField] private TMP_Text discoveredCountText;
    [SerializeField] private TMP_Text completionText;
    [SerializeField] private TMP_Text cashText;
    [SerializeField] private Image progressFill;
    [SerializeField] private TMP_Text feedbackText;

    [Header("Catalog")]
    [SerializeField] private Transform entryContainer;
    [SerializeField] private DessertCollectionEntryUI entryPrefab;

    [Header("Rewards")]
    [SerializeField] private Transform rewardContainer;
    [SerializeField] private DessertCollectionRewardRowUI rewardPrefab;

    private readonly List<DessertCollectionEntryUI> entries =
        new List<DessertCollectionEntryUI>();

    private readonly List<DessertCollectionRewardRowUI> rewards =
        new List<DessertCollectionRewardRowUI>();

    private DessertCatalog catalog;
    private DessertCollectionState collection;
    private EconomyManager economy;
    private SaveManager saveManager;
    private bool claimPending;

    private void Awake()
    {
        if (overlay == null ||
            openButton == null ||
            closeButton == null ||
            entryContainer == null ||
            entryPrefab == null ||
            rewardContainer == null ||
            rewardPrefab == null)
        {
            Debug.LogError(
                "DessertCollectionIndexUI has missing Inspector references.",
                this);
            enabled = false;
            return;
        }

        openButton.onClick.AddListener(HandleOpenClicked);
        closeButton.onClick.AddListener(HandleCloseClicked);
        overlay.SetActive(false);
        catalog = DessertCatalog.LoadShared();
        if (catalog == null)
        {
            Debug.LogError(
                "Dessert Collection Index cannot load the shared DessertCatalog.",
                this);
        }
        else if (!catalog.TryValidate(out string reason))
        {
            Debug.LogError(
                "Dessert Collection Index catalog is invalid: " + reason,
                this);
            catalog = null;
        }

        CreateRows();
    }

    private void OnEnable()
    {
        SubscribeToEconomy();
        saveManager = SaveManager.Instance;
        collection = saveManager != null
            ? saveManager.DessertCollection
            : null;
    }

    private void Start()
    {
        SubscribeToEconomy();
        RefreshCash();
    }

    private void OnDisable()
    {
        if (economy != null)
            economy.CashChanged -= HandleCashChanged;

        economy = null;
    }

    private void OnDestroy()
    {
        if (openButton != null)
            openButton.onClick.RemoveListener(HandleOpenClicked);
        if (closeButton != null)
            closeButton.onClick.RemoveListener(HandleCloseClicked);
    }

    private void HandleOpenClicked()
    {
        UiClickSfx.TryPlay(openButton);
        Refresh();
        overlay.SetActive(true);
    }

    private void HandleCloseClicked()
    {
        UiClickSfx.TryPlay(closeButton);
        overlay.SetActive(false);
    }

    private void CreateRows()
    {
        if (catalog == null)
        {
            SetFeedback("Collection catalog is unavailable.");
            return;
        }

        if (catalog.Definitions.Count != DessertCatalog.InitialTierCount)
        {
            SetFeedback("Collection catalog is incomplete.");
            catalog = null;
            return;
        }

        for (int tier = 1; tier <= DessertCatalog.InitialTierCount; tier++)
        {
            DessertDefinition definition =
                catalog.GetDefinitionByTier(tier);
            if (definition == null)
            {
                Debug.LogError(
                    $"Dessert Collection Index is missing tier {tier}.",
                    this);
                SetFeedback($"Collection entry for tier {tier} is unavailable.");
                catalog = null;
                return;
            }

            DessertCollectionEntryUI entry =
                Instantiate(entryPrefab, entryContainer, false);
            entries.Add(entry);
        }

        for (int index = 0;
             index < DessertCollectionState.MilestoneCount;
             index++)
        {
            int milestoneId =
                DessertCollectionState.GetMilestoneIdAtIndex(index);
            DessertCollectionRewardRowUI row =
                Instantiate(rewardPrefab, rewardContainer, false);
            rewards.Add(row);
        }
    }

    private void Refresh()
    {
        LogClaimDiagnostic("Refreshing collection UI.");
        SubscribeToEconomy();
        saveManager = SaveManager.Instance;
        collection = saveManager != null
            ? saveManager.DessertCollection
            : null;

        if (collection == null)
        {
            SetFeedback("Collection data is unavailable. Try reopening after the profile loads.");
            if (discoveredCountText != null)
                discoveredCountText.text = "0 / 30 discovered";
            if (completionText != null)
                completionText.text = "0% complete";
            if (progressFill != null)
                progressFill.fillAmount = 0f;
            if (cashText != null)
                cashText.text = "Cash unavailable";
            RefreshRewards();
            return;
        }

        SetFeedback(catalog == null
            ? "Collection catalog is unavailable. Check the catalog configuration."
            : string.Empty);
        if (discoveredCountText != null)
        {
            discoveredCountText.text =
                $"{collection.DiscoveredCount} / {collection.TotalCount} discovered";
        }

        if (completionText != null)
        {
            completionText.text =
                $"{collection.CompletionPercentage:0}% complete";
        }

        if (progressFill != null)
        {
            progressFill.fillAmount =
                collection.DiscoveredCount / (float)collection.TotalCount;
        }

        RefreshCash();
        for (int tier = 1;
             catalog != null && tier <= entries.Count;
             tier++)
        {
            DessertDefinition definition =
                catalog.GetDefinitionByTier(tier);
            bool discovered = collection.IsDiscovered(tier);
            entries[tier - 1].Show(tier, definition, discovered);
        }

        RefreshRewards();
    }

    private void RefreshRewards()
    {
        for (int index = 0; index < rewards.Count; index++)
        {
            DessertCollectionRewardRowUI reward = rewards[index];
            if (reward == null)
                continue;

            if (collection == null)
            {
                reward.Refresh(null);
                continue;
            }

            int milestoneId =
                DessertCollectionState.GetMilestoneIdAtIndex(index);
            reward.Bind(
                milestoneId,
                collection,
                HandleClaimRequested);
        }
    }

    private void RefreshCash()
    {
        if (cashText == null)
            return;

        cashText.text = economy != null
            ? $"Cash: ${economy.CurrentCash:N0}"
            : "Cash unavailable";
    }

    private void SubscribeToEconomy()
    {
        EconomyManager currentEconomy =
            EconomyManager.Instance;
        if (currentEconomy == null)
        {
            currentEconomy =
                FindAnyObjectByType<EconomyManager>();
        }

        if (economy == currentEconomy)
            return;

        if (economy != null)
            economy.CashChanged -= HandleCashChanged;

        economy = currentEconomy;
        if (economy != null)
            economy.CashChanged += HandleCashChanged;
    }

    private void HandleCashChanged(int cash)
    {
        if (cashText != null)
            cashText.text = $"Cash: ${cash:N0}";

        LogClaimDiagnostic(
            $"Cash HUD refreshed from CashChanged: ${cash}.");
    }

    private void HandleClaimRequested(int milestoneId)
    {
        LogClaimDiagnostic(
            $"Controller claim handler entered for milestone {milestoneId}. " +
            $"pending={claimPending}.");

        if (claimPending)
        {
            SetFeedback(
                "A reward claim is already processing. Please wait.");
            return;
        }

        saveManager = SaveManager.Instance;
        collection = saveManager != null
            ? saveManager.DessertCollection
            : null;
        if (saveManager == null || collection == null)
        {
            SetFeedback("Reward claim unavailable: profile services are not ready.");
            RefreshRewards();
            return;
        }

        DessertCollectionRewardRowUI row =
            FindRewardRow(milestoneId);
        if (row == null)
        {
            SetFeedback(
                "Reward claim unavailable: the milestone row could not be found.");
            LogClaimDiagnostic(
                $"No reward row is registered for milestone {milestoneId}.");
            RefreshRewards();
            return;
        }

        claimPending = true;
        row.SetPending(true, collection);
        DessertCollectionClaimResult result =
            saveManager.TryClaimDessertCollectionReward(milestoneId);
        claimPending = false;
        row.SetPending(false, collection);
        LogClaimDiagnostic(
            $"SaveManager returned {result} for milestone {milestoneId}.");

        if (result == DessertCollectionClaimResult.Success)
        {
            Refresh();
            SetFeedback("Reward claimed and saved.");
            return;
        }

        if (result == DessertCollectionClaimResult.CommitUncertain)
        {
            foreach (DessertCollectionRewardRowUI reward in rewards)
            {
                if (reward != null)
                    reward.SetClaimBlocked(collection);
            }
        }

        string failureMessage =
            GetClaimFailureMessage(result);
        Refresh();
        SetFeedback(failureMessage);
    }

    private DessertCollectionRewardRowUI FindRewardRow(int milestoneId)
    {
        int index = milestoneId - 1;
        return index >= 0 && index < rewards.Count
            ? rewards[index]
            : null;
    }

    private string GetClaimFailureMessage(
        DessertCollectionClaimResult result)
    {
        switch (result)
        {
            case DessertCollectionClaimResult.InvalidMilestone:
                return "This reward is invalid. Reopen the Collection Index.";
            case DessertCollectionClaimResult.NotEligible:
                return "Discover more desserts before claiming this reward.";
            case DessertCollectionClaimResult.AlreadyClaimed:
                return "This reward has already been claimed.";
            case DessertCollectionClaimResult.CashOverflow:
                return "Claim blocked: spend Cash first, then try again.";
            case DessertCollectionClaimResult.SaveFailure:
                return "Reward was not claimed because saving failed. Try again later.";
            case DessertCollectionClaimResult.TransactionUnavailable:
                return "Reward claim is temporarily unavailable. Try again shortly.";
            case DessertCollectionClaimResult.CommitUncertain:
                return "Claim status is uncertain. Restart or reload the profile before retrying.";
            default:
                return "Reward claim could not be completed.";
        }
    }

    private void SetFeedback(string message)
    {
        if (feedbackText != null)
            feedbackText.text = message;
    }

    private void LogClaimDiagnostic(string message)
    {
#if UNITY_EDITOR || DEVELOPMENT_BUILD
        Debug.Log(
            $"COLLECTION CLAIM UI | {message}",
            this);
#endif
    }
}
