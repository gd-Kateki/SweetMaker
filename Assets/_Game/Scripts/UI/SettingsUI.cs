using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;
using SweetMerge.Analytics;
using SweetMerge.Authentication;

public sealed class SettingsUI : MonoBehaviour
{
    [Header("Overlay")]
    [SerializeField] private Button openButton;
    [SerializeField] private GameObject overlayRoot;
    [SerializeField] private Button closeButton;
    [SerializeField] private bool useGameplayModalInputGate;

    [Header("Settings")]
    [SerializeField] private Toggle sfxEnabledToggle;
    [SerializeField] private Slider sfxVolumeSlider;
    [SerializeField] private EventTrigger sfxVolumeEventTrigger;
    [SerializeField] private TMP_Text sfxVolumePercentageLabel;
    [SerializeField] private Toggle vibrationToggle;
    [SerializeField] private Toggle confirmImportantActionsToggle;
    [SerializeField] private Toggle reduceAnimationsToggle;

    [Header("Information")]
    [SerializeField] private TMP_Text gameVersionLabel;
    [SerializeField] private TMP_Text persistenceFeedbackLabel;

    private readonly List<EventTrigger.Entry> sliderCommitEntries =
        new List<EventTrigger.Entry>();

    private SettingsManager settingsManager;
    private bool pendingPersistence;
    private bool reportedMissingManager;
    private bool waitingForSafeGameplayBoundary;
    private bool hasGameplayModalAdmission;
    private GameplayModalInputGate.GameplayModalLease gameplayModalLease;

    public bool IsOpenOrWaitingForSafeGameplayBoundary =>
        waitingForSafeGameplayBoundary ||
        (overlayRoot != null && overlayRoot.activeSelf);

    private void Awake()
    {
        ValidateReferences();
        RefreshGameVersion();
        EnsureAnalyticsConsentControl();
        EnsureAccountSettingsControl();
    }

    private void OnEnable()
    {
        RegisterControlListeners();
        TryBindSettingsManager();
    }

    private void Start()
    {
        TryBindSettingsManager();
        RefreshControls();
    }

    private void OnDisable()
    {
        PersistPendingChanges(true);
        CloseOverlayAndReleaseGameplayModal();
        UnregisterControlListeners();
        UnbindSettingsManager();
    }

    private void OnDestroy()
    {
        CloseOverlayAndReleaseGameplayModal();
        UnregisterControlListeners();
        UnbindSettingsManager();
    }

    private void OnApplicationPause(bool isPaused)
    {
        if (isPaused)
            PersistPendingChanges(true);
    }

    private void OnApplicationFocus(bool hasFocus)
    {
        if (!hasFocus)
            PersistPendingChanges(true);
    }

    public void Open()
    {
        if (overlayRoot != null && overlayRoot.activeSelf)
            return;

        if (waitingForSafeGameplayBoundary)
        {
            CancelPendingGameplayModalOpen();
            return;
        }

        if (useGameplayModalInputGate)
        {
            RequestGameplayModalOpen();
            return;
        }

        ShowOverlay();
    }

    public void Close()
    {
        if (waitingForSafeGameplayBoundary)
        {
            CancelPendingGameplayModalOpen();
            return;
        }

        PersistPendingChanges(true);

        if (overlayRoot != null)
            overlayRoot.SetActive(false);

        ReleaseGameplayModalLease();
        ReleaseGameplayModalAdmission();
        RestoreOpenButtonSelection();
    }

    private void RequestGameplayModalOpen()
    {
        if (!GameplayModalAdmission.TryReserve(this))
        {
            SetFeedback("Another confirmation is open. Close it before opening Settings.");
            return;
        }

        hasGameplayModalAdmission = true;
        if (!GameplayModalInputGate.TryAcquireBlockingModal(
                this,
                out gameplayModalLease))
        {
            ReleaseGameplayModalAdmission();
            SetFeedback("Settings could not block gameplay input. Please try again.");
            return;
        }

        if (GameplayModalInputGate.IsSafeToOpen(gameplayModalLease))
        {
            ShowOverlay();
            return;
        }

        waitingForSafeGameplayBoundary = true;
        GameplayModalInputGate.SafeBoundaryReached -=
            HandleGameplaySafeBoundaryReached;
        GameplayModalInputGate.SafeBoundaryReached +=
            HandleGameplaySafeBoundaryReached;

        if (openButton != null && EventSystem.current != null)
            EventSystem.current.SetSelectedGameObject(openButton.gameObject);
    }

    private void HandleGameplaySafeBoundaryReached()
    {
        if (!waitingForSafeGameplayBoundary)
            return;

        if (gameplayModalLease == null ||
            !gameplayModalLease.IsActive)
        {
            CancelPendingGameplayModalOpen();
            return;
        }

        if (!GameplayModalInputGate.IsSafeToOpen(gameplayModalLease))
            return;

        waitingForSafeGameplayBoundary = false;
        GameplayModalInputGate.SafeBoundaryReached -=
            HandleGameplaySafeBoundaryReached;
        ShowOverlay();
    }

    private void CancelPendingGameplayModalOpen()
    {
        if (!waitingForSafeGameplayBoundary)
            return;

        waitingForSafeGameplayBoundary = false;
        GameplayModalInputGate.SafeBoundaryReached -=
            HandleGameplaySafeBoundaryReached;
        ReleaseGameplayModalLease();
        ReleaseGameplayModalAdmission();
        RestoreOpenButtonSelection();
    }

    private void ShowOverlay()
    {
        if (!TryBindSettingsManager())
            SetFeedback("Settings are unavailable. Please try again.");

        if (overlayRoot == null)
        {
            waitingForSafeGameplayBoundary = false;
            GameplayModalInputGate.SafeBoundaryReached -=
                HandleGameplaySafeBoundaryReached;
            ReleaseGameplayModalLease();
            ReleaseGameplayModalAdmission();
            return;
        }

        overlayRoot.SetActive(true);
        RefreshControls();

        if (closeButton != null && EventSystem.current != null)
            EventSystem.current.SetSelectedGameObject(closeButton.gameObject);
    }

    private void CloseOverlayAndReleaseGameplayModal()
    {
        if (overlayRoot != null)
            overlayRoot.SetActive(false);

        waitingForSafeGameplayBoundary = false;
        GameplayModalInputGate.SafeBoundaryReached -=
            HandleGameplaySafeBoundaryReached;
        ReleaseGameplayModalLease();
        ReleaseGameplayModalAdmission();
    }

    private void ReleaseGameplayModalLease()
    {
        if (gameplayModalLease == null)
            return;

        gameplayModalLease.Dispose();
        gameplayModalLease = null;
    }

    private void ReleaseGameplayModalAdmission()
    {
        if (!hasGameplayModalAdmission)
            return;

        GameplayModalAdmission.Release(this);
        hasGameplayModalAdmission = false;
    }

    private void RestoreOpenButtonSelection()
    {
        if (openButton != null &&
            openButton.isActiveAndEnabled &&
            EventSystem.current != null)
        {
            EventSystem.current.SetSelectedGameObject(openButton.gameObject);
        }
    }

    private void RegisterControlListeners()
    {
        if (openButton != null)
        {
            openButton.onClick.RemoveListener(Open);
            openButton.onClick.AddListener(Open);
        }

        if (closeButton != null)
        {
            closeButton.onClick.RemoveListener(Close);
            closeButton.onClick.AddListener(Close);
        }

        if (sfxEnabledToggle != null)
        {
            sfxEnabledToggle.onValueChanged.RemoveListener(
                HandleSfxEnabledChanged);
            sfxEnabledToggle.onValueChanged.AddListener(
                HandleSfxEnabledChanged);
        }

        if (sfxVolumeSlider != null)
        {
            sfxVolumeSlider.onValueChanged.RemoveListener(
                HandleSfxVolumeChanged);
            sfxVolumeSlider.onValueChanged.AddListener(
                HandleSfxVolumeChanged);
        }

        if (vibrationToggle != null)
        {
            vibrationToggle.onValueChanged.RemoveListener(
                HandleVibrationChanged);
            vibrationToggle.onValueChanged.AddListener(
                HandleVibrationChanged);
        }

        if (confirmImportantActionsToggle != null)
        {
            confirmImportantActionsToggle.onValueChanged.RemoveListener(
                HandleConfirmImportantActionsChanged);
            confirmImportantActionsToggle.onValueChanged.AddListener(
                HandleConfirmImportantActionsChanged);
        }

        if (reduceAnimationsToggle != null)
        {
            reduceAnimationsToggle.onValueChanged.RemoveListener(
                HandleReduceAnimationsChanged);
            reduceAnimationsToggle.onValueChanged.AddListener(
                HandleReduceAnimationsChanged);
        }

        RegisterSliderCommitEvents();
    }

    private void UnregisterControlListeners()
    {
        if (openButton != null)
            openButton.onClick.RemoveListener(Open);
        if (closeButton != null)
            closeButton.onClick.RemoveListener(Close);
        if (sfxEnabledToggle != null)
            sfxEnabledToggle.onValueChanged.RemoveListener(
                HandleSfxEnabledChanged);
        if (sfxVolumeSlider != null)
            sfxVolumeSlider.onValueChanged.RemoveListener(
                HandleSfxVolumeChanged);
        if (vibrationToggle != null)
            vibrationToggle.onValueChanged.RemoveListener(
                HandleVibrationChanged);
        if (confirmImportantActionsToggle != null)
            confirmImportantActionsToggle.onValueChanged.RemoveListener(
                HandleConfirmImportantActionsChanged);
        if (reduceAnimationsToggle != null)
            reduceAnimationsToggle.onValueChanged.RemoveListener(
                HandleReduceAnimationsChanged);

        UnregisterSliderCommitEvents();
    }

    private void RegisterSliderCommitEvents()
    {
        if (sfxVolumeEventTrigger == null)
            return;

        if (sfxVolumeEventTrigger.triggers == null)
            sfxVolumeEventTrigger.triggers =
                new List<EventTrigger.Entry>();

        AddSliderCommitEvent(EventTriggerType.PointerUp);
        AddSliderCommitEvent(EventTriggerType.EndDrag);
        AddSliderCommitEvent(EventTriggerType.Deselect);
        AddSliderCommitEvent(EventTriggerType.Submit);
    }

    private void AddSliderCommitEvent(EventTriggerType eventType)
    {
        var entry = new EventTrigger.Entry
        {
            eventID = eventType
        };
        entry.callback.AddListener(HandleSfxSliderInteractionEnded);
        sfxVolumeEventTrigger.triggers.Add(entry);
        sliderCommitEntries.Add(entry);
    }

    private void UnregisterSliderCommitEvents()
    {
        if (sfxVolumeEventTrigger != null &&
            sfxVolumeEventTrigger.triggers != null)
        {
            foreach (EventTrigger.Entry entry in sliderCommitEntries)
                sfxVolumeEventTrigger.triggers.Remove(entry);
        }

        sliderCommitEntries.Clear();
    }

    private void HandleSfxSliderInteractionEnded(BaseEventData eventData)
    {
        PersistPendingChanges(false);
    }

    private void HandleSfxEnabledChanged(bool isEnabled)
    {
        UpdateSetting(
            settings =>
            {
                settings.sfxEnabled = isEnabled;
            },
            true);
    }

    private void HandleSfxVolumeChanged(float volume)
    {
        if (!TryGetCurrentSettings(out SettingsProfileData settings))
            return;

        float normalizedVolume = Mathf.Clamp01(volume);
        if (Mathf.Approximately(settings.sfxVolume, normalizedVolume))
        {
            RefreshVolumeLabel(normalizedVolume);
            return;
        }

        settings.sfxVolume = normalizedVolume;
        if (!TryApplySettings(settings))
            return;

        pendingPersistence = true;
        RefreshVolumeLabel(normalizedVolume);
        RefreshPersistenceFeedback();
    }

    private void HandleVibrationChanged(bool isEnabled)
    {
        UpdateSetting(
            settings =>
            {
                settings.vibrationEnabled = isEnabled;
            },
            true);
    }

    private void HandleConfirmImportantActionsChanged(bool isEnabled)
    {
        UpdateSetting(
            settings =>
            {
                settings.confirmImportantActions = isEnabled;
            },
            true);
    }

    private void HandleReduceAnimationsChanged(bool isEnabled)
    {
        UpdateSetting(
            settings =>
            {
                settings.reduceAnimations = isEnabled;
            },
            true);
    }

    private void UpdateSetting(
        System.Action<SettingsProfileData> change,
        bool persistImmediately)
    {
        if (!TryGetCurrentSettings(out SettingsProfileData settings))
            return;

        change(settings);
        if (!TryApplySettings(settings))
            return;

        pendingPersistence = true;
        if (persistImmediately)
            PersistPendingChanges(false);
        else
            RefreshPersistenceFeedback();
    }

    private bool TryGetCurrentSettings(out SettingsProfileData settings)
    {
        if (!TryBindSettingsManager())
        {
            settings = null;
            SetFeedback("Settings are unavailable. Please try again.");
            return false;
        }

        settings = settingsManager.CurrentSettings;
        return settings != null;
    }

    private bool TryApplySettings(SettingsProfileData proposedSettings)
    {
        if (!TryBindSettingsManager())
        {
            SetFeedback("Settings are unavailable. Please try again.");
            return false;
        }

        if (!settingsManager.TryUpdate(
                proposedSettings,
                out string failureReason))
        {
            SetFeedback("Setting was not applied: " + failureReason);
            return false;
        }

        return true;
    }

    private bool TryBindSettingsManager()
    {
        SettingsManager currentManager = SettingsManager.Instance;
        if (currentManager == null)
        {
            if (!reportedMissingManager)
            {
                Debug.LogError(
                    "SettingsUI could not find the initialized SettingsManager.",
                    this);
                reportedMissingManager = true;
            }

            return false;
        }

        reportedMissingManager = false;
        if (settingsManager == currentManager)
            return true;

        UnbindSettingsManager();
        settingsManager = currentManager;
        settingsManager.SettingsChanged += HandleSettingsChanged;
        RefreshControls();
        return true;
    }

    private void UnbindSettingsManager()
    {
        if (settingsManager != null)
            settingsManager.SettingsChanged -= HandleSettingsChanged;

        settingsManager = null;
    }

    private void HandleSettingsChanged(SettingsProfileData settings)
    {
        ApplySettingsToControls(settings);
        RefreshPersistenceFeedback();
    }

    private void RefreshControls()
    {
        if (settingsManager == null)
            return;

        ApplySettingsToControls(settingsManager.CurrentSettings);
        RefreshPersistenceFeedback();
    }

    private void ApplySettingsToControls(SettingsProfileData settings)
    {
        if (settings == null)
            return;

        if (sfxEnabledToggle != null)
            sfxEnabledToggle.SetIsOnWithoutNotify(settings.sfxEnabled);
        if (sfxVolumeSlider != null)
            sfxVolumeSlider.SetValueWithoutNotify(settings.sfxVolume);
        if (vibrationToggle != null)
            vibrationToggle.SetIsOnWithoutNotify(settings.vibrationEnabled);
        if (confirmImportantActionsToggle != null)
        {
            confirmImportantActionsToggle.SetIsOnWithoutNotify(
                settings.confirmImportantActions);
        }
        if (reduceAnimationsToggle != null)
        {
            reduceAnimationsToggle.SetIsOnWithoutNotify(
                settings.reduceAnimations);
        }

        RefreshToggleVisual(sfxEnabledToggle);
        RefreshToggleVisual(vibrationToggle);
        RefreshToggleVisual(confirmImportantActionsToggle);
        RefreshToggleVisual(reduceAnimationsToggle);
        RefreshVolumeLabel(settings.sfxVolume);
    }

    private static void RefreshToggleVisual(Toggle toggle)
    {
        if (toggle == null)
            return;

        SettingsToggleVisual visual =
            toggle.GetComponent<SettingsToggleVisual>();
        if (visual == null)
        {
            Debug.LogError(
                "SettingsUI could not find a SettingsToggleVisual on " +
                toggle.name + ".",
                toggle);
            return;
        }

        visual.RefreshVisual();
    }

    private void RefreshVolumeLabel(float volume)
    {
        if (sfxVolumePercentageLabel != null)
        {
            sfxVolumePercentageLabel.text =
                Mathf.RoundToInt(Mathf.Clamp01(volume) * 100f) + "%";
        }
    }

    private void RefreshGameVersion()
    {
        if (gameVersionLabel != null)
            gameVersionLabel.text = Application.version;
    }

    private void PersistPendingChanges(bool retry)
    {
        if (!pendingPersistence)
        {
            RefreshPersistenceFeedback();
            return;
        }

        if (!TryBindSettingsManager())
        {
            SetFeedback("Changes are not saved. Settings are unavailable.");
            return;
        }

        bool saved = retry
            ? settingsManager.RetrySave()
            : settingsManager.Save();

        pendingPersistence = !saved;
        if (saved)
        {
            RefreshPersistenceFeedback();
            return;
        }

        string reason = settingsManager.LastPersistenceError;
        SetFeedback(string.IsNullOrEmpty(reason)
            ? "Changes are not saved. Close or leave Settings to retry."
            : "Changes are not saved: " + reason);
    }

    private void RefreshPersistenceFeedback()
    {
        if (persistenceFeedbackLabel == null)
            return;

        if (settingsManager == null)
        {
            persistenceFeedbackLabel.text = "Settings unavailable";
            return;
        }

        if (pendingPersistence || settingsManager.HasUnsavedChanges)
        {
            persistenceFeedbackLabel.text = "Unsaved changes";
            return;
        }

        if (settingsManager.PersistenceStatus ==
                SettingsPersistenceStatus.SaveFailed ||
            settingsManager.PersistenceStatus ==
                SettingsPersistenceStatus.UnsupportedFutureSchema ||
            settingsManager.PersistenceStatus ==
                SettingsPersistenceStatus.InvalidProfileProtected)
        {
            string error = settingsManager.LastPersistenceError;
            persistenceFeedbackLabel.text = string.IsNullOrEmpty(error)
                ? "Settings were not saved."
                : "Settings were not saved: " + error;
            return;
        }

        if (settingsManager.PersistenceStatus ==
            SettingsPersistenceStatus.DefaultsInUse)
        {
            persistenceFeedbackLabel.text = "Default settings";
            return;
        }

        if (settingsManager.PersistenceStatus ==
            SettingsPersistenceStatus.NotInitialized)
        {
            persistenceFeedbackLabel.text = "Settings are loading";
            return;
        }

        persistenceFeedbackLabel.text = "Saved";
    }

    private void SetFeedback(string message)
    {
        if (persistenceFeedbackLabel != null)
            persistenceFeedbackLabel.text = message;
    }

    private void ValidateReferences()
    {
        ReportMissing(openButton, nameof(openButton));
        ReportMissing(overlayRoot, nameof(overlayRoot));
        ReportMissing(closeButton, nameof(closeButton));
        ReportMissing(sfxEnabledToggle, nameof(sfxEnabledToggle));
        ReportMissing(sfxVolumeSlider, nameof(sfxVolumeSlider));
        ReportMissing(sfxVolumeEventTrigger, nameof(sfxVolumeEventTrigger));
        ReportMissing(sfxVolumePercentageLabel, nameof(sfxVolumePercentageLabel));
        ReportMissing(vibrationToggle, nameof(vibrationToggle));
        ReportMissing(
            confirmImportantActionsToggle,
            nameof(confirmImportantActionsToggle));
        ReportMissing(reduceAnimationsToggle, nameof(reduceAnimationsToggle));
        ReportMissing(gameVersionLabel, nameof(gameVersionLabel));
        ReportMissing(
            persistenceFeedbackLabel,
            nameof(persistenceFeedbackLabel));

        if (overlayRoot != null &&
            (transform == overlayRoot.transform ||
             transform.IsChildOf(overlayRoot.transform)))
        {
            Debug.LogError(
                "SettingsUI must be on an always-active object outside " +
                "overlayRoot so its Open button remains bound.",
                this);
        }

        if (sfxVolumeSlider != null &&
            sfxVolumeEventTrigger != null &&
            sfxVolumeSlider.gameObject != sfxVolumeEventTrigger.gameObject)
        {
            Debug.LogError(
                "SettingsUI SFX EventTrigger must be on the SFX volume slider.",
                this);
        }

        if (sfxVolumeSlider != null &&
            (!Mathf.Approximately(sfxVolumeSlider.minValue, 0f) ||
             !Mathf.Approximately(sfxVolumeSlider.maxValue, 1f)))
        {
            Debug.LogError(
                "SettingsUI SFX volume slider must use a 0 to 1 range.",
                this);
        }
    }

    private void ReportMissing(Object reference, string referenceName)
    {
        if (reference == null)
        {
            Debug.LogError(
                "SettingsUI is missing the Inspector reference '" +
                referenceName + "'.",
                this);
        }
    }

    private void EnsureAnalyticsConsentControl()
    {
        if (overlayRoot == null)
            return;

        Transform[] descendants =
            overlayRoot.GetComponentsInChildren<Transform>(true);
        Transform settingsContent = null;
        for (int i = 0; i < descendants.Length; i++)
        {
            if (descendants[i].name == "SettingsScrollContent")
            {
                settingsContent = descendants[i];
                break;
            }
        }

        if (settingsContent == null)
        {
            Debug.LogError(
                "SettingsUI could not find SettingsScrollContent for " +
                "Analytics privacy controls.",
                this);
            return;
        }

        AnalyticsConsentSettingsControl.Attach(
            settingsContent,
            AnalyticsBootstrap.Instance);
    }

    private void EnsureAccountSettingsControl()
    {
        if (overlayRoot == null)
            return;

        Transform[] descendants =
            overlayRoot.GetComponentsInChildren<Transform>(true);
        Transform settingsContent = null;
        for (int i = 0; i < descendants.Length; i++)
        {
            if (descendants[i].name == "SettingsScrollContent")
            {
                settingsContent = descendants[i];
                break;
            }
        }

        if (settingsContent == null)
        {
            Debug.LogError(
                "SettingsUI could not find SettingsScrollContent for " +
                "the account section.",
                this);
            return;
        }

        var accountControl = GooglePlayGamesAccountSettingsControl.Attach(
            settingsContent,
            GooglePlayGamesAuthenticationCoordinator.Instance);
        if (accountControl != null && accountControl.GetComponent<SweetMerge.Cloud.SimpleCloudPanel>() == null)
        {
            var label = accountControl.GetComponentInChildren<TMP_Text>(true);
            SweetMerge.Cloud.SimpleCloudPanel.Attach(accountControl.transform,
                label != null ? label.font : TMP_Settings.defaultFontAsset);
        }
    }
}
