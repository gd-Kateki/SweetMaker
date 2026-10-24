using TMPro;
using UnityEngine;
using UnityEngine.UI;

public sealed class CampaignCompletionUI : MonoBehaviour
{
    private const string CelebrationMessage =
        "<size=54><b>Campaign Complete!</b></size>\n\n" +
        "<size=42><color=#FFD176>Eternal Dragon's Dessert</color></size>\n\n" +
        "<size=28>Congratulations! You've completed the Sweet Merge campaign.</size>";

    private const string PendingMessage =
        "<size=40><b>Completion not saved</b></size>\n\n" +
        "Your T30 merge succeeded, but campaign progress could not be saved. " +
        "Please retry.";

    private const string RetryFailedMessage =
        "<size=40><b>Completion not saved</b></size>\n\n" +
        "Your T30 merge succeeded, but campaign progress could not be saved. " +
        "Try again when saving is available.";

    [SerializeField]
    private GameObject panelRoot;

    [SerializeField]
    private Button continueButton;

    [SerializeField]
    private TMP_Text messageText;

    [SerializeField]
    private TMP_Text continueButtonText;

    private bool hasShownCompletion;
    private bool retryInProgress;
    private PlayerProgressionManager progressionManager;

    public bool IsOpen =>
        panelRoot != null &&
        panelRoot.activeSelf;

    private void Awake()
    {
        if (panelRoot == null)
        {
            Debug.LogError(
                "CAMPAIGN UI | Completion panel reference is missing.",
                this);
        }
        else
        {
            panelRoot.SetActive(false);
        }

        if (continueButton == null)
        {
            Debug.LogError(
                "CAMPAIGN UI | Completion action button reference is missing.",
                this);
        }

        if (messageText == null)
            Debug.LogError("CAMPAIGN UI | Message text reference is missing.", this);

        if (continueButtonText == null)
            Debug.LogError("CAMPAIGN UI | Action button text reference is missing.", this);
    }

    private void OnEnable()
    {
        progressionManager = PlayerProgressionManager.Instance;
        if (progressionManager != null)
        {
            progressionManager.CampaignCompletionPersistenceChanged -=
                HandlePersistenceChanged;
            progressionManager.CampaignCompletionPersistenceChanged +=
                HandlePersistenceChanged;
        }

        GameplayEvents.CampaignCompleted -= HandleCampaignCompleted;
        GameplayEvents.CampaignCompleted += HandleCampaignCompleted;

        if (continueButton != null)
        {
            continueButton.onClick.RemoveListener(HandleActionClicked);
            continueButton.onClick.AddListener(HandleActionClicked);
        }

        RefreshPersistenceState();
    }

    private void OnDisable()
    {
        if (progressionManager != null)
        {
            progressionManager.CampaignCompletionPersistenceChanged -=
                HandlePersistenceChanged;
        }

        GameplayEvents.CampaignCompleted -= HandleCampaignCompleted;

        if (continueButton != null)
            continueButton.onClick.RemoveListener(HandleActionClicked);
    }

    private void HandleCampaignCompleted()
    {
        ShowCelebration();
    }

    private void HandlePersistenceChanged(
        CampaignCompletionPersistenceState state)
    {
        if (state == CampaignCompletionPersistenceState.Pending)
            ShowPendingSave(false);
        else if (state == CampaignCompletionPersistenceState.Incomplete &&
                 !hasShownCompletion &&
                 panelRoot != null)
            panelRoot.SetActive(false);
    }

    private void RefreshPersistenceState()
    {
        if (progressionManager == null)
        {
            if (panelRoot != null)
                panelRoot.SetActive(false);
            return;
        }

        CampaignCompletionPersistenceState state =
            progressionManager.CampaignCompletionPersistence;
        HandlePersistenceChanged(state);
        if (state == CampaignCompletionPersistenceState.Saved &&
            progressionManager.HasPendingCampaignCelebrationPresentation)
        {
            ShowCelebration();
        }
    }

    private void ShowCelebration()
    {
        if (hasShownCompletion)
            return;

        if (panelRoot == null || messageText == null ||
            continueButtonText == null)
        {
            Debug.LogError(
                "CAMPAIGN UI | Cannot show completion because a panel reference is missing.",
                this);
            return;
        }

        hasShownCompletion = true;
        messageText.text = CelebrationMessage;
        continueButtonText.text = "Continue Playing";
        if (continueButton != null)
            continueButton.interactable = true;
        progressionManager?.MarkCampaignCompletionCelebrationPresented();
        panelRoot.SetActive(true);
    }

    private void ShowPendingSave(bool retryFailed)
    {
        if (panelRoot == null || messageText == null ||
            continueButtonText == null)
        {
            Debug.LogError(
                "CAMPAIGN UI | Cannot show pending completion because a panel reference is missing.",
                this);
            return;
        }

        messageText.text = retryFailed ? RetryFailedMessage : PendingMessage;
        continueButtonText.text = "Retry Save";
        if (continueButton != null)
            continueButton.interactable = !retryInProgress;
        panelRoot.SetActive(true);
    }

    private void HandleActionClicked()
    {
        if (!IsOpen)
            return;

        if (progressionManager != null &&
            progressionManager.CampaignCompletionPersistence ==
                CampaignCompletionPersistenceState.Pending)
        {
            RetrySave();
            return;
        }

        UiClickSfx.TryPlay(continueButton);
        panelRoot.SetActive(false);
    }

    private void RetrySave()
    {
        if (retryInProgress)
            return;

        retryInProgress = true;
        if (continueButton != null)
            continueButton.interactable = false;

        bool saved = progressionManager != null &&
                     progressionManager.TryPersistCampaignCompletion();
        retryInProgress = false;

        if (!saved &&
            progressionManager != null &&
            progressionManager.CampaignCompletionPersistence ==
                CampaignCompletionPersistenceState.Pending)
        {
            ShowPendingSave(true);
        }
    }
}
