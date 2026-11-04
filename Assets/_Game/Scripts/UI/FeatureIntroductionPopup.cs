using System;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using SweetMerge.Profile;

public sealed class FeatureIntroductionPopup : MonoBehaviour
{
    private const string GameSceneName = "Game";
    private const string MainBakerySceneName = "MainBakery";
    private const string GameCanvasName = "GameplayCanvas";
    private const string MainBakeryCanvasName = "MainCanvas";

    private static bool isListeningForSceneLoads;

    private GameObject popupRoot;
    private TMP_Text titleText;
    private TMP_Text bodyText;
    private FeatureIntroduction configuredFeature;
    private bool isConfigured;
    private bool isDisplayed;
    private bool waitingForGameplayBoundary;
    private Func<FeatureIntroduction, bool> acknowledgementCommit;
    private GameplayModalInputGate.GameplayModalLease gameplayModalLease;

    public event Action<FeatureIntroduction> PopupDisplayed;
    public event Action<FeatureIntroduction> GotItPressed;
    public event Action<FeatureIntroduction> DismissedWithoutAcknowledgement;

    public bool IsDisplayed => isDisplayed;

    public FeatureIntroduction ConfiguredFeature
    {
        get
        {
            if (!isConfigured)
                throw new InvalidOperationException(
                    "Configure a feature introduction before reading it.");
            return configuredFeature;
        }
    }

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
    private static void ResetBootstrap()
    {
        SceneManager.sceneLoaded -= HandleSceneLoaded;
        isListeningForSceneLoads = false;
    }

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
    private static void ListenForSceneLoads()
    {
        if (isListeningForSceneLoads)
            return;

        SceneManager.sceneLoaded += HandleSceneLoaded;
        isListeningForSceneLoads = true;
    }

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
    private static void CreateForActiveScene()
    {
        CreateForScene(SceneManager.GetActiveScene());
    }

    private static void HandleSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        CreateForScene(scene);
    }

    private static void CreateForScene(Scene scene)
    {
        string canvasName;
        if (scene.name == GameSceneName)
            canvasName = GameCanvasName;
        else if (scene.name == MainBakerySceneName)
            canvasName = MainBakeryCanvasName;
        else
            return;

        GameObject[] roots = scene.GetRootGameObjects();
        foreach (GameObject root in roots)
        {
            Canvas[] canvases = root.GetComponentsInChildren<Canvas>(true);
            foreach (Canvas canvas in canvases)
            {
                if (canvas.name != canvasName)
                    continue;

                if (canvas.GetComponentInChildren<FeatureIntroductionPopup>(true) != null)
                    return;

                GameObject host = new GameObject(
                    "FeatureIntroductionPopupHost",
                    typeof(RectTransform));
                host.transform.SetParent(canvas.transform, false);
                SetFullRect(host.GetComponent<RectTransform>());
                host.AddComponent<FeatureIntroductionPopup>();
                host.transform.SetAsLastSibling();
                return;
            }
        }
    }

    private void Awake()
    {
        BuildInterface();
    }

    private void OnDisable()
    {
        if (isDisplayed)
        {
            FeatureIntroduction dismissedFeature = configuredFeature;
            HidePopup();
            DismissedWithoutAcknowledgement?.Invoke(dismissedFeature);
            return;
        }

        CancelPendingShow();
    }

    private void OnDestroy()
    {
        CancelPendingShow();
        ReleaseGameplayModalLease();
    }

    private void Update()
    {
        if (isDisplayed && Input.GetKeyDown(KeyCode.Escape))
            DismissWithoutAcknowledgement();
    }

    public void Configure(FeatureIntroduction feature)
    {
        if (isDisplayed || waitingForGameplayBoundary)
            throw new InvalidOperationException(
                "A visible or pending feature introduction cannot be reconfigured.");
        if (titleText == null || bodyText == null)
            throw new InvalidOperationException(
                "The feature introduction popup is not initialized under a Canvas.");

        string title;
        string body;
        GetContent(feature, out title, out body);
        configuredFeature = feature;
        isConfigured = true;
        titleText.text = title;
        bodyText.text = body;
    }

    public bool Show()
    {
        if (!isActiveAndEnabled || popupRoot == null)
        {
            Debug.LogError(
                "FEATURE INTRODUCTION | The popup is not initialized or active.",
                this);
            return false;
        }

        if (!isConfigured)
        {
            Debug.LogError(
                "FEATURE INTRODUCTION | Configure a feature before showing the popup.",
                this);
            return false;
        }

        if (isDisplayed || waitingForGameplayBoundary)
            return false;

        if (RequiresGameplayModalLease())
        {
            if (!GameplayModalInputGate.TryAcquireBlockingModal(
                    this,
                    out gameplayModalLease))
            {
                Debug.LogError(
                    "FEATURE INTRODUCTION | Could not acquire the gameplay input gate.",
                    this);
                return false;
            }

            if (!GameplayModalInputGate.IsSafeToOpen(gameplayModalLease))
            {
                waitingForGameplayBoundary = true;
                GameplayModalInputGate.SafeBoundaryReached +=
                    HandleGameplaySafeBoundaryReached;
                return true;
            }
        }

        DisplayPopup();
        return true;
    }

    public static bool TryShowForFeatureFrom(
        MonoBehaviour featureUi,
        FeatureIntroduction feature,
        bool noIncompatibleModal)
    {
        if (featureUi == null || !featureUi.isActiveAndEnabled)
            return false;

        Canvas canvas = featureUi.GetComponentInParent<Canvas>();
        if (canvas == null)
            return false;

        FeatureIntroductionPopup popup =
            canvas.GetComponentInChildren<FeatureIntroductionPopup>(true);
        return popup != null &&
               popup.TryShowForFeature(feature, noIncompatibleModal);
    }

    private bool TryShowForFeature(
        FeatureIntroduction feature,
        bool noIncompatibleModal)
    {
        if (isDisplayed ||
            waitingForGameplayBoundary ||
            !isActiveAndEnabled ||
            popupRoot == null ||
            !IsSupportedFeatureScene(feature, SceneManager.GetActiveScene().name))
            return false;

        ApplicationReadinessCoordinator readiness =
            ApplicationReadinessCoordinator.Instance;
        HybridTutorialController tutorial =
            HybridTutorialController.Instance;
        SaveManager saveManager = SaveManager.Instance;

        bool tutorialCompleted =
            tutorial != null &&
            tutorial.IsReady &&
            tutorial.State != null &&
            tutorial.State.IsLocallyValidated &&
            tutorial.State.IsCompleted;
        bool applicationReady =
            readiness != null && readiness.IsGameplayReady;
        bool saveReady =
            saveManager != null && saveManager.IsLifecycleSavingReady;
        if (!AreEligibilityConditionsMet(
                tutorialCompleted,
                applicationReady,
                saveReady,
                true,
                true,
                noIncompatibleModal))
            return false;

        PlayerSaveData selectedSave = null;
        bool selectedSnapshotValid =
            saveManager != null &&
            saveManager.SaveFileExists() &&
            saveManager.TryLoad(out selectedSave) &&
            selectedSave != null;
        bool featureUnseen =
            saveManager != null &&
            !saveManager.HasSeenFeatureIntroduction(feature) &&
            selectedSave != null &&
            !IsAcknowledgedInSnapshot(selectedSave, feature);

        if (!AreEligibilityConditionsMet(
                tutorialCompleted,
                applicationReady,
                saveReady,
                selectedSnapshotValid,
                featureUnseen,
                noIncompatibleModal))
            return false;

        Configure(feature);
        acknowledgementCommit = requestedFeature =>
            ReferenceEquals(SaveManager.Instance, saveManager) &&
            saveManager.TryAcknowledgeFeatureIntroduction(requestedFeature);

        if (Show())
            return true;

        acknowledgementCommit = null;
        return false;
    }

    public void DismissWithoutAcknowledgement()
    {
        if (waitingForGameplayBoundary)
        {
            CancelPendingShow();
            return;
        }

        if (!isDisplayed)
            return;

        FeatureIntroduction dismissedFeature = configuredFeature;
        HidePopup();
        DismissedWithoutAcknowledgement?.Invoke(dismissedFeature);
    }

    private void BuildInterface()
    {
        Canvas parentCanvas = GetComponentInParent<Canvas>();
        if (parentCanvas == null)
        {
            Debug.LogError(
                "FEATURE INTRODUCTION | A parent Canvas is required.",
                this);
            enabled = false;
            return;
        }

        if (parentCanvas.rootCanvas.renderMode != RenderMode.ScreenSpaceOverlay)
        {
            Debug.LogError(
                "FEATURE INTRODUCTION | A Screen Space Overlay Canvas is required for safe-area layout.",
                this);
            enabled = false;
            return;
        }

        popupRoot = new GameObject("FeatureIntroductionPopup", typeof(RectTransform));
        popupRoot.transform.SetParent(transform, false);
        SetFullRect(popupRoot.GetComponent<RectTransform>());

        Canvas popupCanvas = popupRoot.AddComponent<Canvas>();
        popupCanvas.overrideSorting = true;
        popupCanvas.sortingLayerID = parentCanvas.rootCanvas.sortingLayerID;
        popupCanvas.sortingOrder = short.MaxValue;
        popupCanvas.targetDisplay = parentCanvas.rootCanvas.targetDisplay;
        popupRoot.AddComponent<GraphicRaycaster>();

        Image backdrop = popupRoot.AddComponent<Image>();
        backdrop.color = new Color(0.035f, 0.025f, 0.02f, 0.78f);
        backdrop.raycastTarget = true;

        GameObject safeArea = new GameObject("SafeArea", typeof(RectTransform));
        safeArea.transform.SetParent(popupRoot.transform, false);
        SetFullRect(safeArea.GetComponent<RectTransform>());
        safeArea.AddComponent<SafeAreaFitter>();

        GameObject panel = new GameObject("FeatureIntroductionCard", typeof(RectTransform));
        panel.transform.SetParent(safeArea.transform, false);
        SetFullRect(panel.GetComponent<RectTransform>());
        RectTransform panelRect = panel.GetComponent<RectTransform>();
        panelRect.anchorMin = new Vector2(0.08f, 0.1f);
        panelRect.anchorMax = new Vector2(0.92f, 0.9f);

        Image panelImage = panel.AddComponent<Image>();
        panelImage.color = new Color(0.18f, 0.12f, 0.08f, 1f);

        VerticalLayoutGroup layout = panel.AddComponent<VerticalLayoutGroup>();
        layout.padding = new RectOffset(26, 26, 24, 24);
        layout.spacing = 16f;
        layout.childAlignment = TextAnchor.MiddleCenter;
        layout.childControlWidth = true;
        layout.childControlHeight = true;
        layout.childForceExpandWidth = true;
        layout.childForceExpandHeight = true;

        titleText = CreateText(panel.transform, "Title", 30f);
        titleText.fontStyle = FontStyles.Bold;
        titleText.enableAutoSizing = true;
        titleText.fontSizeMin = 22f;
        titleText.fontSizeMax = 32f;
        LayoutElement titleSizing = titleText.gameObject.AddComponent<LayoutElement>();
        titleSizing.minHeight = 48f;
        titleSizing.preferredHeight = 58f;

        bodyText = CreateText(panel.transform, "Body", 20f);
        bodyText.enableAutoSizing = true;
        bodyText.fontSizeMin = 15f;
        bodyText.fontSizeMax = 21f;
        LayoutElement bodySizing = bodyText.gameObject.AddComponent<LayoutElement>();
        bodySizing.minHeight = 100f;
        bodySizing.flexibleHeight = 1f;

        Button gotItButton = CreateButton(panel.transform);
        gotItButton.onClick.AddListener(HandleGotItPressed);
        popupRoot.SetActive(false);
    }

    private void DisplayPopup()
    {
        if (popupRoot == null)
            return;

        waitingForGameplayBoundary = false;
        isDisplayed = true;
        popupRoot.SetActive(true);
        popupRoot.transform.SetAsLastSibling();
        PopupDisplayed?.Invoke(configuredFeature);
    }

    private void HandleGotItPressed()
    {
        if (!isDisplayed)
            return;

        FeatureIntroduction acknowledgedFeature = configuredFeature;
        if (acknowledgementCommit != null)
        {
            bool committed;
            try
            {
                committed = acknowledgementCommit(acknowledgedFeature);
            }
            catch (Exception exception)
            {
                Debug.LogError(
                    "FEATURE INTRODUCTION | Acknowledgement persistence failed; the introduction remains open.\n" +
                    exception,
                    this);
                return;
            }

            if (!committed)
            {
                Debug.LogWarning(
                    "FEATURE INTRODUCTION | Acknowledgement was not persisted; the introduction remains available for retry.",
                    this);
                return;
            }
        }

        HidePopup();
        GotItPressed?.Invoke(acknowledgedFeature);
    }

    private void HandleGameplaySafeBoundaryReached()
    {
        if (!waitingForGameplayBoundary)
            return;

        if (gameplayModalLease == null ||
            !gameplayModalLease.IsActive)
        {
            CancelPendingShow();
            return;
        }

        if (!GameplayModalInputGate.IsSafeToOpen(gameplayModalLease))
            return;

        GameplayModalInputGate.SafeBoundaryReached -=
            HandleGameplaySafeBoundaryReached;
        DisplayPopup();
    }

    private void HidePopup()
    {
        isDisplayed = false;
        if (popupRoot != null)
            popupRoot.SetActive(false);
        CancelPendingShow();
        ReleaseGameplayModalLease();
        acknowledgementCommit = null;
    }

    private void CancelPendingShow()
    {
        if (waitingForGameplayBoundary)
        {
            GameplayModalInputGate.SafeBoundaryReached -=
                HandleGameplaySafeBoundaryReached;
            waitingForGameplayBoundary = false;
        }

        ReleaseGameplayModalLease();
    }

    private void ReleaseGameplayModalLease()
    {
        if (gameplayModalLease == null)
            return;

        gameplayModalLease.Dispose();
        gameplayModalLease = null;
    }

    private bool RequiresGameplayModalLease()
    {
        return RequiresGameplayModalLease(
            configuredFeature,
            SceneManager.GetActiveScene().name);
    }

    private static bool RequiresGameplayModalLease(
        FeatureIntroduction feature,
        string sceneName)
    {
        return feature == FeatureIntroduction.Collection &&
               sceneName == GameSceneName;
    }

    private static bool AreEligibilityConditionsMet(
        bool tutorialCompleted,
        bool applicationReady,
        bool saveReady,
        bool selectedSnapshotValid,
        bool featureUnseen,
        bool noIncompatibleModal)
    {
        return tutorialCompleted &&
               applicationReady &&
               saveReady &&
               selectedSnapshotValid &&
               featureUnseen &&
               noIncompatibleModal;
    }

    private static bool IsSupportedFeatureScene(
        FeatureIntroduction feature,
        string sceneName)
    {
        if (sceneName == GameSceneName)
            return true;

        return sceneName == MainBakerySceneName &&
               feature == FeatureIntroduction.Collection;
    }

    private static bool IsAcknowledgedInSnapshot(
        PlayerSaveData saveData,
        FeatureIntroduction feature)
    {
        switch (feature)
        {
            case FeatureIntroduction.Upgrades:
                return saveData.upgradesIntroSeen;
            case FeatureIntroduction.Rebirth:
                return saveData.rebirthIntroSeen;
            case FeatureIntroduction.Collection:
                return saveData.collectionIntroSeen;
            default:
                throw new ArgumentOutOfRangeException(nameof(feature));
        }
    }

    private static void GetContent(
        FeatureIntroduction feature,
        out string title,
        out string body)
    {
        switch (feature)
        {
            case FeatureIntroduction.Upgrades:
                title = "Grow Your Café!";
                body = "Spend cash to improve your café! Expand your board, serve more customers, increase your earnings, and unlock other improvements. Some upgrades require Rebirths, while higher Oven levels are earned through Rebirth progression.";
                return;
            case FeatureIntroduction.Rebirth:
                title = "A Fresh Start!";
                body = "Reach the required dessert tier during your current run and collect enough cash to Rebirth. Rebirth resets your cash, board, shelf, orders and current run, but keeps your non-Oven upgrades and Dessert Collection progress. Every second Rebirth increases your Oven level!";
                return;
            case FeatureIntroduction.Collection:
                title = "Discover Them All!";
                body = "Discover new dessert tiers by spawning and merging desserts. Find all 30 tiers and claim cash rewards at 6, 12, 18, 24 and 30 discoveries!";
                return;
            default:
                throw new ArgumentOutOfRangeException(nameof(feature));
        }
    }

    private static TMP_Text CreateText(
        Transform parent,
        string objectName,
        float fontSize)
    {
        GameObject textObject = new GameObject(objectName, typeof(RectTransform));
        textObject.transform.SetParent(parent, false);
        TMP_Text text = textObject.AddComponent<TextMeshProUGUI>();
        text.fontSize = fontSize;
        text.color = Color.white;
        text.alignment = TextAlignmentOptions.Center;
        text.textWrappingMode = TextWrappingModes.Normal;
        text.overflowMode = TextOverflowModes.Overflow;
        text.raycastTarget = false;
        return text;
    }

    private static Button CreateButton(Transform parent)
    {
        GameObject buttonObject = new GameObject(
            "GotItButton",
            typeof(RectTransform));
        buttonObject.transform.SetParent(parent, false);
        Image buttonImage = buttonObject.AddComponent<Image>();
        buttonImage.color = new Color(0.85f, 0.55f, 0.2f, 1f);

        Button button = buttonObject.AddComponent<Button>();
        button.targetGraphic = buttonImage;
        LayoutElement buttonSizing = buttonObject.AddComponent<LayoutElement>();
        buttonSizing.minHeight = 56f;
        buttonSizing.preferredHeight = 60f;

        TMP_Text label = CreateText(buttonObject.transform, "Label", 20f);
        label.color = new Color(0.12f, 0.07f, 0.03f, 1f);
        label.text = "Got It";
        SetFullRect(label.rectTransform);
        return button;
    }

    private static void SetFullRect(RectTransform rect)
    {
        rect.localScale = Vector3.one;
        rect.localRotation = Quaternion.identity;
        rect.pivot = new Vector2(0.5f, 0.5f);
        rect.anchorMin = Vector2.zero;
        rect.anchorMax = Vector2.one;
        rect.anchoredPosition3D = Vector3.zero;
        rect.sizeDelta = Vector2.zero;
    }
}
