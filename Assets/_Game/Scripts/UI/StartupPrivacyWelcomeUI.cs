using System;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using SweetMerge.Startup;

public enum StartupPrivacyWelcomeScreen
{
    None,
    Privacy,
    Welcome
}

public sealed class StartupPrivacyWelcomeUI : MonoBehaviour
{
    private const string MainBakerySceneName = "MainBakery";
    private const string MainCanvasName = "MainCanvas";
    private const string WelcomeSceneName = "Welcome";
    private const string WelcomeCanvasName = "WelcomeCanvas";
    private const string PrivacyPolicyUrl =
        "https://offcut-studios.github.io/offcutstudios-legal/" +
        "dessert-merge-cafe/privacy-policy/";

    private static bool isListeningForSceneLoads;

    private GameObject overlayRoot;
    private GameObject privacyScreen;
    private GameObject welcomeScreen;
    private TMP_Text privacyFeedbackText;
    private TMP_Text feedbackText;
    private Button allowAnalyticsButton;
    private Button declineAnalyticsButton;
    private Button privacyPolicyButton;
    private Button googleSignInButton;
    private Button guestPlayButton;
    private Button retryGoogleRestorationButton;
    private Button switchAccountButton;
    private Button retryStartupButton;
    private Button retryPrivacyStartupButton;
    private bool initialized;

    public event Action AnalyticsAllowed;
    public event Action AnalyticsDeclined;
    public event Action GoogleSignInRequested;
    public event Action RetryGoogleRestorationRequested;
    public event Action SwitchAccountRequested;
    public event Action RetryStartupRequested;
    public event Action GuestPlayRequested;
    public event Action LifecycleEnded;

    public bool IsVisible =>
        initialized && overlayRoot.activeSelf;

    public StartupPrivacyWelcomeScreen VisibleScreen { get; private set; } =
        StartupPrivacyWelcomeScreen.None;

    [RuntimeInitializeOnLoadMethod(
        RuntimeInitializeLoadType.SubsystemRegistration)]
    private static void ResetSceneListener()
    {
        SceneManager.sceneLoaded -= HandleSceneLoaded;
        isListeningForSceneLoads = false;
    }

    [RuntimeInitializeOnLoadMethod(
        RuntimeInitializeLoadType.BeforeSceneLoad)]
    private static void ListenForSceneLoads()
    {
        if (isListeningForSceneLoads)
            return;

        SceneManager.sceneLoaded += HandleSceneLoaded;
        isListeningForSceneLoads = true;
    }

    [RuntimeInitializeOnLoadMethod(
        RuntimeInitializeLoadType.AfterSceneLoad)]
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
        if (!scene.IsValid() || !IsSupportedScene(scene.name))
            return;
        if (scene.name == MainBakerySceneName &&
            LoadingSceneStartupPresenter.IsActiveForDevelopment)
            return;

        if (!ShouldCreateView(
                true,
                scene.name,
                FindView(scene) != null))
            return;

        string canvasName = scene.name == MainBakerySceneName
            ? MainCanvasName
            : WelcomeCanvasName;

        Canvas canvas = FindCanvas(scene, canvasName);
        if (canvas == null)
        {
            Debug.LogError(
                "STARTUP UI | Startup canvas '" + canvasName +
                "' was not found in scene '" + scene.name + "'.");
            return;
        }

        GameObject host = new GameObject(
            nameof(StartupPrivacyWelcomeUI),
            typeof(RectTransform));
        host.transform.SetParent(canvas.transform, false);
        SetFullRect(host.GetComponent<RectTransform>());
        host.transform.SetAsLastSibling();
        host.AddComponent<StartupPrivacyWelcomeUI>();
    }

    internal static StartupPrivacyWelcomeUI EnsureForScene(Scene scene)
    {
        StartupPrivacyWelcomeUI existing = FindView(scene);
        if (existing != null)
            return existing;

        CreateForScene(scene);
        return FindView(scene);
    }

    internal static bool IsSupportedScene(string sceneName)
    {
        return sceneName == MainBakerySceneName ||
               sceneName == WelcomeSceneName;
    }

    internal static bool ShouldCreateView(
        bool sceneValid,
        string sceneName,
        bool viewAlreadyExists)
    {
        return sceneValid &&
               IsSupportedScene(sceneName) &&
               !viewAlreadyExists;
    }

    private void Awake()
    {
        BuildInterface();
    }

    private void OnDestroy()
    {
        RemoveButtonListeners();
        AnalyticsAllowed = null;
        AnalyticsDeclined = null;
        GoogleSignInRequested = null;
        RetryGoogleRestorationRequested = null;
        SwitchAccountRequested = null;
        RetryStartupRequested = null;
        GuestPlayRequested = null;
        LifecycleEnded?.Invoke();
        LifecycleEnded = null;
    }

    private void OnDisable()
    {
        Hide();
        LifecycleEnded?.Invoke();
    }

    public bool ShowPrivacy()
    {
        return Show(StartupPrivacyWelcomeScreen.Privacy);
    }

    public bool ShowWelcome()
    {
        return Show(StartupPrivacyWelcomeScreen.Welcome);
    }

    public void Hide()
    {
        if (!initialized)
            return;

        overlayRoot.SetActive(false);
        VisibleScreen = StartupPrivacyWelcomeScreen.None;
    }

    public void SetFeedback(string message)
    {
        if (!initialized)
        {
            Debug.LogError(
                "STARTUP UI | Cannot set feedback before the UI is initialized.",
                this);
            return;
        }

        feedbackText.text = message ?? string.Empty;
    }

    public void SetPrivacyFeedback(string message)
    {
        if (!initialized)
        {
            Debug.LogError(
                "STARTUP UI | Cannot set privacy feedback before the UI is initialized.",
                this);
            return;
        }

        privacyFeedbackText.text = message ?? string.Empty;
    }

    public void SetWelcomeActionsInteractable(bool interactable)
    {
        if (!initialized)
        {
            Debug.LogError(
                "STARTUP UI | Cannot update welcome actions before the UI is initialized.",
                this);
            return;
        }

        googleSignInButton.interactable = interactable;
        guestPlayButton.interactable = interactable;
        retryGoogleRestorationButton.interactable = interactable;
        switchAccountButton.interactable = interactable;
        retryStartupButton.interactable = interactable;
        retryPrivacyStartupButton.interactable = interactable;
    }

    public void SetPrivacyActionsInteractable(bool interactable)
    {
        if (!initialized)
        {
            Debug.LogError(
                "STARTUP UI | Cannot update privacy actions before the UI is initialized.",
                this);
            return;
        }

        allowAnalyticsButton.interactable = interactable;
        declineAnalyticsButton.interactable = interactable;
        privacyPolicyButton.interactable = interactable;
    }

    public void SetGoogleRecoveryActionsVisible(bool visible)
    {
        if (!initialized)
        {
            Debug.LogError(
                "STARTUP UI | Cannot update Google recovery actions before the UI is initialized.",
                this);
            return;
        }

        retryGoogleRestorationButton.gameObject.SetActive(visible);
    }

    public void SetSwitchAccountVisible(bool visible)
    {
        if (!initialized)
        {
            Debug.LogError(
                "STARTUP UI | Cannot update account-switch help before the UI is initialized.",
                this);
            return;
        }

        switchAccountButton.gameObject.SetActive(visible);
    }

    public void SetCachedSessionRetryVisible(bool visible)
    {
        if (!initialized)
        {
            Debug.LogError(
                "STARTUP UI | Cannot update cached-session retry before the UI is initialized.",
                this);
            return;
        }

        retryGoogleRestorationButton.gameObject.SetActive(visible);
    }

    public void SetRetryStartupVisible(bool visible)
    {
        if (!initialized)
        {
            Debug.LogError(
                "STARTUP UI | Cannot update retry actions before the UI is initialized.",
                this);
            return;
        }

        retryStartupButton.gameObject.SetActive(visible);
        retryPrivacyStartupButton.gameObject.SetActive(visible);
    }

    public void SetGuestPlayVisible(bool visible)
    {
        if (!initialized)
        {
            Debug.LogError(
                "STARTUP UI | Cannot update guest actions before the UI is initialized.",
                this);
            return;
        }

        guestPlayButton.gameObject.SetActive(visible);
    }

    private bool Show(StartupPrivacyWelcomeScreen screen)
    {
        if (!isActiveAndEnabled || !initialized)
        {
            Debug.LogError(
                "STARTUP UI | The privacy and welcome UI is not initialized or active.",
                this);
            return false;
        }

        privacyScreen.SetActive(
            screen == StartupPrivacyWelcomeScreen.Privacy);
        welcomeScreen.SetActive(
            screen == StartupPrivacyWelcomeScreen.Welcome);
        overlayRoot.transform.SetAsLastSibling();
        VisibleScreen = screen;
        overlayRoot.SetActive(true);
        return true;
    }

    private void BuildInterface()
    {
        if (initialized)
            return;

        Canvas parentCanvas = GetComponentInParent<Canvas>();
        if (parentCanvas == null ||
            parentCanvas.rootCanvas.renderMode !=
                RenderMode.ScreenSpaceOverlay)
        {
            Debug.LogError(
                "STARTUP UI | A Screen Space Overlay Canvas is required.",
                this);
            enabled = false;
            return;
        }

        TMP_FontAsset font = FindFont();
        if (font == null)
        {
            Debug.LogError(
                "STARTUP UI | A loaded TextMeshPro font is required.",
                this);
            enabled = false;
            return;
        }

        SetFullRect(GetComponent<RectTransform>());
        overlayRoot = new GameObject(
            "StartupPrivacyWelcomeOverlay",
            typeof(RectTransform));
        overlayRoot.transform.SetParent(transform, false);
        SetFullRect(overlayRoot.GetComponent<RectTransform>());

        Canvas overlayCanvas = overlayRoot.AddComponent<Canvas>();
        overlayCanvas.overrideSorting = true;
        overlayCanvas.sortingLayerID = parentCanvas.rootCanvas.sortingLayerID;
        overlayCanvas.sortingOrder = short.MaxValue;
        overlayCanvas.targetDisplay = parentCanvas.rootCanvas.targetDisplay;
        overlayRoot.AddComponent<GraphicRaycaster>();

        Image backdrop = overlayRoot.AddComponent<Image>();
        backdrop.color = new Color(0.035f, 0.025f, 0.02f, 0.82f);
        backdrop.raycastTarget = true;

        GameObject safeArea = new GameObject(
            "SafeArea",
            typeof(RectTransform));
        safeArea.transform.SetParent(overlayRoot.transform, false);
        SetFullRect(safeArea.GetComponent<RectTransform>());
        safeArea.AddComponent<SafeAreaFitter>();

        privacyScreen = CreateScreen(
            safeArea.transform,
            "PrivacyScreen",
            font,
            "Privacy Choices",
            "Optional Unity Analytics helps us understand game usage and " +
                "performance. Unity Analytics may process device information, " +
                "installation identifiers, IP addresses, and session events. " +
                "You can change this choice later in Settings.\n\n" +
                "Advertising is not currently active in Dessert Merge Cafe. " +
                "No advertising SDK or advertising consent is integrated. " +
                "When Analytics is turned off, the SDK may send events already " +
                "buffered.",
            out allowAnalyticsButton,
            out declineAnalyticsButton,
            out privacyPolicyButton,
            out privacyFeedbackText,
            out retryPrivacyStartupButton);
        welcomeScreen = CreateWelcomeScreen(
            safeArea.transform,
            font,
            out googleSignInButton,
            out guestPlayButton,
            out retryGoogleRestorationButton,
            out switchAccountButton,
            out retryStartupButton,
            out feedbackText);

        allowAnalyticsButton.onClick.AddListener(HandleAnalyticsAllowed);
        declineAnalyticsButton.onClick.AddListener(HandleAnalyticsDeclined);
        privacyPolicyButton.onClick.AddListener(OpenPrivacyPolicy);
        googleSignInButton.onClick.AddListener(HandleGoogleSignInRequested);
        retryGoogleRestorationButton.onClick.AddListener(
            HandleRetryGoogleRestorationRequested);
        switchAccountButton.onClick.AddListener(HandleSwitchAccountRequested);
        retryStartupButton.onClick.AddListener(HandleRetryStartupRequested);
        retryPrivacyStartupButton.onClick.AddListener(
            HandleRetryStartupRequested);
        guestPlayButton.onClick.AddListener(HandleGuestPlayRequested);

        privacyScreen.SetActive(false);
        welcomeScreen.SetActive(false);
        overlayRoot.SetActive(false);
        initialized = true;
    }

    private static GameObject CreateScreen(
        Transform parent,
        string objectName,
        TMP_FontAsset font,
        string title,
        string body,
        out Button primaryButton,
        out Button secondaryButton,
        out Button linkButton,
        out TMP_Text feedback,
        out Button retryButton)
    {
        GameObject screen = CreateCard(parent, objectName);
        CreateText(
            screen.transform,
            "Title",
            title,
            font,
            38f,
            FontStyles.Bold,
            new Vector2(0.07f, 0.82f),
            new Vector2(0.93f, 0.95f),
            27f,
            40f);
        CreateText(
            screen.transform,
            "PrivacyInformation",
            body,
            font,
            23f,
            FontStyles.Normal,
            new Vector2(0.08f, 0.31f),
            new Vector2(0.92f, 0.79f),
            17f,
            25f);
        feedback = CreateText(
            screen.transform,
            "PrivacyFeedback",
            string.Empty,
            font,
            16f,
            FontStyles.Normal,
            new Vector2(0.08f, 0.18f),
            new Vector2(0.92f, 0.22f),
            14f,
            17f);
        linkButton = CreateButton(
            screen.transform,
            "PrivacyPolicyButton",
            "Privacy Policy",
            font,
            new Vector2(0.22f, 0.22f),
            new Vector2(0.78f, 0.29f));
        retryButton = CreateButton(
            screen.transform,
            "RetryStartupButton",
            "Retry Startup",
            font,
            new Vector2(0.30f, 0.015f),
            new Vector2(0.70f, 0.075f));
        retryButton.gameObject.SetActive(false);
        primaryButton = CreateButton(
            screen.transform,
            "AllowAnalyticsButton",
            "Allow Analytics",
            font,
            new Vector2(0.06f, 0.08f),
            new Vector2(0.49f, 0.19f));
        secondaryButton = CreateButton(
            screen.transform,
            "DeclineAnalyticsButton",
            "No Thanks",
            font,
            new Vector2(0.51f, 0.08f),
            new Vector2(0.94f, 0.19f));
        return screen;
    }

    private GameObject CreateWelcomeScreen(
        Transform parent,
        TMP_FontAsset font,
        out Button signInButton,
        out Button guestButton,
        out Button retryRestorationButton,
        out Button switchAccount,
        out Button retryStartup,
        out TMP_Text status)
    {
        GameObject screen = CreateCard(parent, "WelcomeScreen");
        CreateText(
            screen.transform,
            "Title",
            "Dessert Merge Cafe",
            font,
            38f,
            FontStyles.Bold,
            new Vector2(0.06f, 0.78f),
            new Vector2(0.94f, 0.94f),
            27f,
            40f);
        signInButton = CreateButton(
            screen.transform,
            "GoogleSignInButton",
            "Google Sign In",
            font,
            new Vector2(0.12f, 0.65f),
            new Vector2(0.88f, 0.75f));
        guestButton = CreateButton(
            screen.transform,
            "GuestPlayButton",
            "Guest Play",
            font,
            new Vector2(0.12f, 0.50f),
            new Vector2(0.88f, 0.60f));
        retryRestorationButton = CreateButton(
            screen.transform,
            "RetryCachedGoogleSessionButton",
            "Retry Cached Session",
            font,
            new Vector2(0.12f, 0.35f),
            new Vector2(0.88f, 0.45f));
        retryRestorationButton.gameObject.SetActive(false);
        switchAccount = CreateButton(
            screen.transform,
            "SwitchAccountButton",
            "Switch Account Help",
            font,
            new Vector2(0.12f, 0.22f),
            new Vector2(0.88f, 0.32f));
        switchAccount.gameObject.SetActive(false);
        retryStartup = CreateButton(
            screen.transform,
            "RetryStartupButton",
            "Retry Startup",
            font,
            new Vector2(0.30f, 0.02f),
            new Vector2(0.70f, 0.09f));
        retryStartup.gameObject.SetActive(false);
        status = CreateText(
            screen.transform,
            "Feedback",
            string.Empty,
            font,
            20f,
            FontStyles.Normal,
            new Vector2(0.08f, 0.10f),
            new Vector2(0.92f, 0.20f),
            16f,
            23f);
        return screen;
    }

    private static GameObject CreateCard(Transform parent, string objectName)
    {
        GameObject card = new GameObject(
            objectName,
            typeof(RectTransform),
            typeof(Image));
        card.transform.SetParent(parent, false);
        RectTransform rect = card.GetComponent<RectTransform>();
        rect.anchorMin = new Vector2(0.06f, 0.06f);
        rect.anchorMax = new Vector2(0.94f, 0.94f);
        rect.offsetMin = Vector2.zero;
        rect.offsetMax = Vector2.zero;
        card.GetComponent<Image>().color =
            new Color(0.18f, 0.12f, 0.08f, 1f);
        return card;
    }

    private static TMP_Text CreateText(
        Transform parent,
        string objectName,
        string value,
        TMP_FontAsset font,
        float fontSize,
        FontStyles style,
        Vector2 anchorMin,
        Vector2 anchorMax,
        float minimumFontSize,
        float maximumFontSize)
    {
        GameObject textObject = new GameObject(
            objectName,
            typeof(RectTransform),
            typeof(TextMeshProUGUI));
        textObject.transform.SetParent(parent, false);
        TMP_Text text = textObject.GetComponent<TMP_Text>();
        text.font = font;
        text.text = value;
        text.fontSize = fontSize;
        text.fontSizeMin = minimumFontSize;
        text.fontSizeMax = maximumFontSize;
        text.enableAutoSizing = true;
        text.textWrappingMode = TextWrappingModes.Normal;
        text.overflowMode = TextOverflowModes.Ellipsis;
        text.alignment = TextAlignmentOptions.Center;
        text.verticalAlignment = VerticalAlignmentOptions.Middle;
        text.fontStyle = style;
        text.color = Color.white;
        text.raycastTarget = false;

        RectTransform rect = text.rectTransform;
        rect.anchorMin = anchorMin;
        rect.anchorMax = anchorMax;
        rect.offsetMin = new Vector2(8f, 4f);
        rect.offsetMax = new Vector2(-8f, -4f);
        return text;
    }

    private static Button CreateButton(
        Transform parent,
        string objectName,
        string label,
        TMP_FontAsset font,
        Vector2 anchorMin,
        Vector2 anchorMax)
    {
        GameObject buttonObject = new GameObject(
            objectName,
            typeof(RectTransform),
            typeof(Image),
            typeof(Button));
        buttonObject.transform.SetParent(parent, false);
        Image image = buttonObject.GetComponent<Image>();
        image.color = new Color(0.85f, 0.55f, 0.2f, 1f);
        Button button = buttonObject.GetComponent<Button>();
        button.targetGraphic = image;

        RectTransform rect = buttonObject.GetComponent<RectTransform>();
        rect.anchorMin = anchorMin;
        rect.anchorMax = anchorMax;
        rect.offsetMin = Vector2.zero;
        rect.offsetMax = Vector2.zero;

        TMP_Text buttonLabel = CreateText(
            buttonObject.transform,
            "Label",
            label,
            font,
            22f,
            FontStyles.Bold,
            Vector2.zero,
            Vector2.one,
            17f,
            23f);
        buttonLabel.color = new Color(0.12f, 0.07f, 0.03f, 1f);
        return button;
    }

    private void HandleAnalyticsAllowed()
    {
        if (IsVisible &&
            VisibleScreen == StartupPrivacyWelcomeScreen.Privacy)
            AnalyticsAllowed?.Invoke();
    }

    private void HandleAnalyticsDeclined()
    {
        if (IsVisible &&
            VisibleScreen == StartupPrivacyWelcomeScreen.Privacy)
            AnalyticsDeclined?.Invoke();
    }

    private void HandleGoogleSignInRequested()
    {
        if (IsVisible &&
            VisibleScreen == StartupPrivacyWelcomeScreen.Welcome)
            GoogleSignInRequested?.Invoke();
    }

    private void HandleRetryGoogleRestorationRequested()
    {
        if (IsVisible &&
            VisibleScreen == StartupPrivacyWelcomeScreen.Welcome)
            RetryGoogleRestorationRequested?.Invoke();
    }

    private void HandleSwitchAccountRequested()
    {
        if (IsVisible &&
            VisibleScreen == StartupPrivacyWelcomeScreen.Welcome)
            SwitchAccountRequested?.Invoke();
    }

    private void HandleRetryStartupRequested()
    {
        if (IsVisible)
            RetryStartupRequested?.Invoke();
    }

    private void HandleGuestPlayRequested()
    {
        if (IsVisible &&
            VisibleScreen == StartupPrivacyWelcomeScreen.Welcome)
            GuestPlayRequested?.Invoke();
    }

    private static void OpenPrivacyPolicy()
    {
        Application.OpenURL(PrivacyPolicyUrl);
    }

    private void RemoveButtonListeners()
    {
        if (allowAnalyticsButton != null)
            allowAnalyticsButton.onClick.RemoveListener(
                HandleAnalyticsAllowed);
        if (declineAnalyticsButton != null)
            declineAnalyticsButton.onClick.RemoveListener(
                HandleAnalyticsDeclined);
        if (privacyPolicyButton != null)
            privacyPolicyButton.onClick.RemoveListener(OpenPrivacyPolicy);
        if (googleSignInButton != null)
            googleSignInButton.onClick.RemoveListener(
                HandleGoogleSignInRequested);
        if (retryGoogleRestorationButton != null)
            retryGoogleRestorationButton.onClick.RemoveListener(
                HandleRetryGoogleRestorationRequested);
        if (switchAccountButton != null)
            switchAccountButton.onClick.RemoveListener(
                HandleSwitchAccountRequested);
        if (retryStartupButton != null)
            retryStartupButton.onClick.RemoveListener(
                HandleRetryStartupRequested);
        if (retryPrivacyStartupButton != null)
            retryPrivacyStartupButton.onClick.RemoveListener(
                HandleRetryStartupRequested);
        if (guestPlayButton != null)
            guestPlayButton.onClick.RemoveListener(
                HandleGuestPlayRequested);
    }

    private static TMP_FontAsset FindFont()
    {
        TMP_FontAsset[] fonts =
            Resources.FindObjectsOfTypeAll<TMP_FontAsset>();
        return fonts.Length > 0
            ? fonts[0]
            : TMP_Settings.defaultFontAsset;
    }

    private static Canvas FindCanvas(Scene scene, string canvasName)
    {
        GameObject[] roots = scene.GetRootGameObjects();
        foreach (GameObject root in roots)
        {
            Canvas[] canvases = root.GetComponentsInChildren<Canvas>(true);
            foreach (Canvas canvas in canvases)
            {
                if (canvas.name == canvasName)
                    return canvas;
            }
        }

        return null;
    }

    private static StartupPrivacyWelcomeUI FindView(Scene scene)
    {
        foreach (GameObject root in scene.GetRootGameObjects())
        {
            StartupPrivacyWelcomeUI view =
                root.GetComponentInChildren<StartupPrivacyWelcomeUI>(true);
            if (view != null)
                return view;
        }

        return null;
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
