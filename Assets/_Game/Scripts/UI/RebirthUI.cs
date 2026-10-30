using System.Collections;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public sealed class RebirthUI : MonoBehaviour
{
    private const string AvailableNotification =
        "Prestige Available! Tap Prestige to continue!";

    private const string FinalObjectiveText =
        "Final Objective: Create Tier 30 — Eternal Dragon's Dessert";

    private const string CampaignCompleteText =
        "Campaign Complete!\nEternal Dragon's Dessert created.";

    private const string CampaignCompletionPendingText =
        "Completion not saved\n" +
        "Tier 30 was created, but campaign progress could not be saved.";

    [SerializeField]
    private TMP_Text requirementsText;

    [SerializeField]
    private TMP_Text requiredDessertText;

    [SerializeField]
    private TMP_Text tierProgressText;

    [SerializeField]
    private TMP_Text cashRequirementText;

    [SerializeField]
    private TMP_Text eligibilityText;

    [SerializeField]
    private TMP_Text campaignStatusText;

    [SerializeField]
    private Button rebirthButton;

    [SerializeField]
    private TMP_Text rebirthButtonText;

    [SerializeField]
    private Button entryButton;

    [SerializeField]
    private TMP_Text entryButtonText;

    [SerializeField]
    private Image readyIndicator;

    [SerializeField]
    private GameObject modalPanel;

    [SerializeField]
    private GameObject modalBackdrop;

    [SerializeField]
    private Button closeButton;

    [SerializeField]
    private TMP_Text availabilityNotification;

    [SerializeField, Min(0.1f)]
    private float notificationDuration = 3f;

    private PlayerProgressionManager progressionManager;
    private EconomyManager economyManager;
    private DessertSpawner dessertSpawner;
    private bool rebirthClickInProgress;
    private bool hasEligibilityState;
    private bool wasEligible;
    private Coroutine notificationCoroutine;

    private void Awake()
    {
        Close();
        if (availabilityNotification != null)
            availabilityNotification.enabled = false;
    }

    private void Start()
    {
        ResolveReferences();

        if (progressionManager == null)
        {
            Debug.LogError("REBIRTH UI | PlayerProgressionManager is unavailable.");
            RefreshUnavailable();
            return;
        }

        if (economyManager == null)
        {
            Debug.LogError("REBIRTH UI | EconomyManager is unavailable.");
            RefreshUnavailable();
            return;
        }

        progressionManager.RebirthProgressionChanged += Refresh;
        progressionManager.CampaignCompletionPersistenceChanged +=
            HandleCampaignCompletionPersistenceChanged;
        GameplayEvents.CampaignCompleted += HandleCampaignCompleted;
        economyManager.CashChanged += HandleCashChanged;

        if (rebirthButton != null)
            rebirthButton.onClick.AddListener(HandleRebirthClicked);
        else
            Debug.LogError("REBIRTH UI | Rebirth button reference is missing.");

        if (entryButton != null)
            entryButton.onClick.AddListener(HandleOpenClicked);
        else
            Debug.LogError("REBIRTH UI | Entry button reference is missing.");

        if (closeButton != null)
            closeButton.onClick.AddListener(HandleCloseClicked);
        else
            Debug.LogError("REBIRTH UI | Close button reference is missing.");

        Refresh();
    }

    private void OnDestroy()
    {
        if (notificationCoroutine != null)
            StopCoroutine(notificationCoroutine);

        if (progressionManager != null)
        {
            progressionManager.RebirthProgressionChanged -= Refresh;
            progressionManager.CampaignCompletionPersistenceChanged -=
                HandleCampaignCompletionPersistenceChanged;
        }

        GameplayEvents.CampaignCompleted -= HandleCampaignCompleted;

        if (economyManager != null)
            economyManager.CashChanged -= HandleCashChanged;

        if (rebirthButton != null)
            rebirthButton.onClick.RemoveListener(HandleRebirthClicked);

        if (entryButton != null)
            entryButton.onClick.RemoveListener(HandleOpenClicked);

        if (closeButton != null)
            closeButton.onClick.RemoveListener(HandleCloseClicked);
    }

    private void HandleOpenClicked()
    {
        if (IsModalOpen() ||
            (modalPanel == null && modalBackdrop == null))
        {
            return;
        }

        UiClickSfx.TryPlay(entryButton);
        Open();
    }

    private void HandleCloseClicked()
    {
        if (!IsModalOpen())
            return;

        UiClickSfx.TryPlay(closeButton);
        Close();
    }

    private void ResolveReferences()
    {
        if (progressionManager == null)
            progressionManager = PlayerProgressionManager.Instance;
        if (progressionManager == null)
            progressionManager = FindAnyObjectByType<PlayerProgressionManager>();

        if (economyManager == null)
            economyManager = EconomyManager.Instance;
        if (economyManager == null)
            economyManager = FindAnyObjectByType<EconomyManager>();

        if (dessertSpawner == null)
            dessertSpawner = FindAnyObjectByType<DessertSpawner>();
    }

    private void HandleCashChanged(int cash)
    {
        Refresh();
    }

    private void HandleCampaignCompleted()
    {
        Refresh();
    }

    private void HandleCampaignCompletionPersistenceChanged(
        CampaignCompletionPersistenceState state)
    {
        Refresh();
    }

    private void HandleRebirthClicked()
    {
        if (rebirthClickInProgress || progressionManager == null)
            return;

        rebirthClickInProgress = true;
        if (rebirthButton != null)
            rebirthButton.interactable = false;

        try
        {
            if (!progressionManager.TryRebirth())
                Debug.LogWarning("REBIRTH UI | Rebirth transaction was not completed.");
            else
                Close();
        }
        finally
        {
            rebirthClickInProgress = false;
            Refresh();
        }
    }

    public void Refresh()
    {
        ResolveReferences();
        if (progressionManager == null || economyManager == null)
        {
            RefreshUnavailable();
            return;
        }

        if (progressionManager.CurrentRebirthCount >= 10)
        {
            if (requirementsText != null)
            {
                if (!progressionManager.CampaignComplete)
                {
                    requirementsText.text =
                        "All Rebirths Complete";
                    SetRequirementText(campaignStatusText, FinalObjectiveText);
                }
                else
                {
                    requirementsText.text =
                        progressionManager.CampaignCompletionPersistence ==
                        CampaignCompletionPersistenceState.Saved
                            ? "Campaign Complete!"
                            : "Completion not saved";
                    SetRequirementText(
                        campaignStatusText,
                        progressionManager.CampaignCompletionPersistence ==
                        CampaignCompletionPersistenceState.Saved
                            ? "Eternal Dragon's Dessert created."
                            : "Tier 30 was created, but campaign progress could not be saved.");
                }
            }
            else if (!progressionManager.CampaignComplete)
            {
                SetRequirementText(campaignStatusText, FinalObjectiveText);
            }
            else
            {
                SetRequirementText(
                    campaignStatusText,
                    progressionManager.CampaignCompletionPersistence ==
                    CampaignCompletionPersistenceState.Saved
                        ? "Eternal Dragon's Dessert created."
                        : "Tier 30 was created, but campaign progress could not be saved.");
            }
            SetRequirementText(requiredDessertText, string.Empty);
            SetRequirementText(tierProgressText, string.Empty);
            SetRequirementText(cashRequirementText, string.Empty);
            SetRequirementText(eligibilityText, string.Empty);

            SetButtonState(false, "COMPLETE");
            SetReadyIndicator(false);
            SetEntryButtonState("PRESTIGE COMPLETE");
            UpdateEligibilityState(false);
            return;
        }

        int requiredTier = progressionManager.NextRebirthRequiredTier;
        int createdTier = progressionManager.HighestTierCreatedThisRun;
        int cashHeld = economyManager.CurrentCash;
        int requiredCash = progressionManager.NextRebirthRequiredCash;

        string requiredDessertName = "Tier " + requiredTier;
        if (dessertSpawner != null)
        {
            DessertDefinition requiredDessert =
                dessertSpawner.GetDefinitionByTier(requiredTier);
            if (requiredDessert != null)
                requiredDessertName = requiredDessert.DisplayName;
        }

        bool tierReady = createdTier >= requiredTier;
        bool cashReady = cashHeld >= requiredCash;
        bool eligible = tierReady && cashReady &&
                        progressionManager.IsEligibleForNextRebirth;
        UpdateEligibilityState(eligible);
        SetReadyIndicator(eligible);
        SetEntryButtonState("PRESTIGE");

        if (requirementsText != null)
        {
            requirementsText.text =
                $"REBIRTH {progressionManager.NextRebirthNumber}";
        }
        SetRequirementText(
            requiredDessertText,
            $"Create T{requiredTier} {requiredDessertName}");
        SetRequirementText(
            tierProgressText,
            FormatTierProgress(createdTier, requiredTier, tierReady));
        SetRequirementText(
            cashRequirementText,
            $"Cash held: ${cashHeld:N0} / ${requiredCash:N0}");
        SetRequirementText(
            eligibilityText,
            $"Eligibility: {(eligible ? "READY" : "Requirements incomplete")}");
        SetRequirementText(campaignStatusText, string.Empty);

        SetButtonState(eligible && !rebirthClickInProgress, "REBIRTH");
    }

    public void Open()
    {
        if (entryButton != null)
            entryButton.interactable = false;
        if (modalBackdrop != null)
            modalBackdrop.SetActive(true);
        if (modalPanel != null)
            modalPanel.SetActive(true);
    }

    public void Close()
    {
        if (modalPanel != null)
            modalPanel.SetActive(false);
        if (modalBackdrop != null)
            modalBackdrop.SetActive(false);
        if (entryButton != null)
            entryButton.interactable = true;
    }

    private static string FormatTierProgress(int createdTier, int requiredTier, bool tierReady)
    {
        return tierReady
            ? $"T{createdTier} / T{requiredTier} - MET"
            : $"T{createdTier} / T{requiredTier}";
    }

    private static void SetRequirementText(TMP_Text text, string value)
    {
        if (text == null)
            return;

        text.text = value;
        text.gameObject.SetActive(!string.IsNullOrEmpty(value));
    }

    private void SetButtonState(bool interactable, string label)
    {
        if (rebirthButton != null)
            rebirthButton.interactable = interactable;
        if (rebirthButtonText != null)
            rebirthButtonText.text = label;
    }

    private void SetEntryButtonState(string label)
    {
        if (entryButtonText != null)
            entryButtonText.text = label;
        if (entryButton != null)
            entryButton.interactable = !IsModalOpen();
    }

    private bool IsModalOpen()
    {
        return (modalPanel != null && modalPanel.activeSelf) ||
               (modalBackdrop != null && modalBackdrop.activeSelf);
    }

    private void SetReadyIndicator(bool visible)
    {
        if (readyIndicator != null)
            readyIndicator.enabled = visible;
    }

    private void UpdateEligibilityState(bool eligible)
    {
        if (hasEligibilityState && !wasEligible && eligible)
            ShowAvailabilityNotification();

        hasEligibilityState = true;
        wasEligible = eligible;
    }

    private void ShowAvailabilityNotification()
    {
        if (availabilityNotification == null)
            return;

        if (notificationCoroutine != null)
            StopCoroutine(notificationCoroutine);

        availabilityNotification.text = AvailableNotification;
        availabilityNotification.enabled = true;
        if (Application.isPlaying)
            notificationCoroutine = StartCoroutine(HideNotificationAfterDelay());
    }

    private IEnumerator HideNotificationAfterDelay()
    {
        yield return new WaitForSecondsRealtime(notificationDuration);
        if (availabilityNotification != null)
            availabilityNotification.enabled = false;
        notificationCoroutine = null;
    }

    private void RefreshUnavailable()
    {
        if (requirementsText != null)
            requirementsText.text = "Rebirth unavailable";
        SetRequirementText(requiredDessertText, string.Empty);
        SetRequirementText(tierProgressText, string.Empty);
        SetRequirementText(cashRequirementText, string.Empty);
        SetRequirementText(eligibilityText, string.Empty);
        SetRequirementText(campaignStatusText, string.Empty);
        SetButtonState(false, "REBIRTH");
        SetReadyIndicator(false);
        SetEntryButtonState("PRESTIGE");
    }
}
