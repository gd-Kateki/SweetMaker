using System;
using System.Threading.Tasks;
using SweetMerge.Authentication;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using System.Collections;

public sealed class MainBakeryStartupUI : MonoBehaviour
{
    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
    private static void CreateForMainBakery()
    {
        Scene scene = SceneManager.GetActiveScene();
        if (!scene.IsValid() ||
            scene.name != SceneNavigationManager.MainBakeryScene)
            return;

        Canvas canvas = FindCanvas(scene, "MainCanvas");
        if (canvas == null ||
            canvas.GetComponentInChildren<MainBakeryStartupUI>(true) != null)
            return;

        GameObject host = new GameObject(
            nameof(MainBakeryStartupUI), typeof(RectTransform));
        host.transform.SetParent(canvas.transform, false);
        host.AddComponent<MainBakeryStartupUI>();
    }

    private ApplicationReadinessCoordinator readinessCoordinator;
    private GooglePlayGamesAuthenticationCoordinator authenticationCoordinator;
    private GameObject overlay;
    private TMP_Text titleText;
    private TMP_Text messageText;
    private TMP_Text noteText;
    private Button signInButton;
    private Button retryButton;
    private TMP_Text signInLabel;
    private TMP_Text retryLabel;
    private bool subscribed;
    private bool authenticationInFlight;
    private Coroutine bindingCoroutine;

    private void Awake()
    {
        // Establish the full-canvas parent before any child layout is created.
        SetFullRect(GetComponent<RectTransform>());
        transform.SetAsLastSibling();
        BuildInterface();
    }

    private void OnEnable()
    {
        SceneManager.sceneLoaded += HandleSceneLoaded;
        Subscribe();
        if (!subscribed)
            bindingCoroutine = StartCoroutine(BindCoordinatorWhenAvailable());
        Refresh();
    }

    private void OnDisable()
    {
        SceneManager.sceneLoaded -= HandleSceneLoaded;
        if (bindingCoroutine != null)
            StopCoroutine(bindingCoroutine);
        bindingCoroutine = null;
        Unsubscribe();
    }

    private void HandleSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        if (scene.name != SceneNavigationManager.MainBakeryScene)
            return;

        Subscribe();
        Refresh();
    }

    private void Subscribe()
    {
        if (subscribed)
            return;

        readinessCoordinator = ApplicationReadinessCoordinator.Instance;
        if (readinessCoordinator == null)
            return;

        readinessCoordinator.StateChanged += HandleReadinessChanged;
        authenticationCoordinator =
            GooglePlayGamesAuthenticationCoordinator.Instance;
        authenticationCoordinator.StateChanged +=
            HandleAuthenticationChanged;
        subscribed = true;
        if (bindingCoroutine != null)
        {
            StopCoroutine(bindingCoroutine);
            bindingCoroutine = null;
        }
        Refresh();
    }

    private IEnumerator BindCoordinatorWhenAvailable()
    {
        const int maxAttempts = 20;
        for (int attempt = 0; attempt < maxAttempts && !subscribed; attempt++)
        {
            yield return null;
            Subscribe();
        }

        bindingCoroutine = null;
    }

    private void Unsubscribe()
    {
        if (!subscribed)
            return;

        if (readinessCoordinator != null)
            readinessCoordinator.StateChanged -= HandleReadinessChanged;
        if (authenticationCoordinator != null)
            authenticationCoordinator.StateChanged -=
                HandleAuthenticationChanged;
        readinessCoordinator = null;
        authenticationCoordinator = null;
        subscribed = false;
    }

    private void HandleReadinessChanged(ApplicationReadinessState state)
    {
        Refresh();
    }

    private void HandleAuthenticationChanged()
    {
        Refresh();
    }

    private void Refresh()
    {
        if (overlay == null)
            return;

        if (readinessCoordinator == null)
            readinessCoordinator = ApplicationReadinessCoordinator.Instance;

        bool ready = readinessCoordinator != null &&
            readinessCoordinator.IsReady;
        overlay.SetActive(!ready);
        if (ready)
            return;

        ApplicationReadinessState state = readinessCoordinator == null
            ? ApplicationReadinessState.Initializing
            : readinessCoordinator.State;
        titleText.text = GetTitle(state);
        messageText.text = GetMessage(
            state,
            authenticationCoordinator != null
                ? authenticationCoordinator.Failure
                : GooglePlayGamesAuthenticationFailure.None,
            authenticationCoordinator != null
                ? authenticationCoordinator.State
                : GooglePlayGamesAuthenticationState.SignedOut);
        bool canAuthenticate =
            state == ApplicationReadinessState.AuthenticationRequired ||
            state == ApplicationReadinessState.RecoverableError &&
            authenticationCoordinator != null &&
            authenticationCoordinator.State !=
                GooglePlayGamesAuthenticationState.SignedIn;
        bool canRetry = state == ApplicationReadinessState.RecoverableError;
        signInButton.gameObject.SetActive(canAuthenticate);
        retryButton.gameObject.SetActive(canRetry && !canAuthenticate);
        signInButton.interactable = !authenticationInFlight;
        retryButton.interactable = !authenticationInFlight;
        signInLabel.text = "Sign in with Google Play Games";
        retryLabel.text = "Try Again";
    }

    private void HandleActionClicked()
    {
        if (authenticationInFlight)
            return;

        if (readinessCoordinator == null)
            readinessCoordinator = ApplicationReadinessCoordinator.Instance;
        if (readinessCoordinator == null)
        {
            Refresh();
            return;
        }

        if (readinessCoordinator.State ==
            ApplicationReadinessState.AuthenticationRequired ||
            readinessCoordinator.State ==
                ApplicationReadinessState.RecoverableError &&
            authenticationCoordinator != null &&
            authenticationCoordinator.State !=
                GooglePlayGamesAuthenticationState.SignedIn)
        {
            _ = SignInAsync();
            return;
        }

        readinessCoordinator.Retry();
    }

    private async Task SignInAsync()
    {
        authenticationInFlight = true;
        Refresh();
        try
        {
            if (authenticationCoordinator == null)
                authenticationCoordinator =
                    GooglePlayGamesAuthenticationCoordinator.Instance;

            if (authenticationCoordinator == null)
                return;

            await authenticationCoordinator.SignInAsync();
            if (this == null)
                return;

            readinessCoordinator?.Retry();
        }
        catch (Exception)
        {
            if (this != null)
                Refresh();
        }
        finally
        {
            authenticationInFlight = false;
            if (this != null)
                Refresh();
        }
    }

    private void BuildInterface()
    {
        overlay = new GameObject("StartupOverlay", typeof(RectTransform));
        overlay.transform.SetParent(transform, false);
        SetFullRect(overlay.GetComponent<RectTransform>());
        Canvas parentCanvas = GetComponentInParent<Canvas>();
        Canvas overlayCanvas = overlay.AddComponent<Canvas>();
        overlayCanvas.overrideSorting = true;
        overlayCanvas.sortingLayerID = parentCanvas.sortingLayerID;
        overlayCanvas.sortingOrder = short.MaxValue;
        overlay.AddComponent<GraphicRaycaster>();
        Image overlayImage = overlay.AddComponent<Image>();
        overlayImage.color = new Color(0.03f, 0.02f, 0.05f, 0.86f);
        overlayImage.raycastTarget = true;

        GameObject safeArea = new GameObject("SafeArea", typeof(RectTransform));
        safeArea.transform.SetParent(overlay.transform, false);
        SetFullRect(safeArea.GetComponent<RectTransform>());
        // SafeAreaFitter captures its original anchors in Awake.
        safeArea.AddComponent<SafeAreaFitter>();

        GameObject panel = new GameObject("StartupModalCard", typeof(RectTransform));
        panel.transform.SetParent(safeArea.transform, false);
        Image panelImage = panel.AddComponent<Image>();
        panelImage.color = new Color(0.18f, 0.12f, 0.08f, 1f);
        RectTransform panelRect = panel.GetComponent<RectTransform>();
        panelRect.anchorMin = new Vector2(0.08f, 0.5f);
        panelRect.anchorMax = new Vector2(0.92f, 0.5f);
        panelRect.pivot = new Vector2(0.5f, 0.5f);
        panelRect.anchoredPosition = Vector2.zero;
        panelRect.sizeDelta = Vector2.zero;
        VerticalLayoutGroup layout = panel.AddComponent<VerticalLayoutGroup>();
        layout.padding = new RectOffset(24, 24, 24, 24);
        layout.spacing = 16f;
        layout.childAlignment = TextAnchor.MiddleCenter;
        layout.childControlWidth = true;
        layout.childControlHeight = true;
        layout.childForceExpandWidth = true;
        layout.childForceExpandHeight = false;
        panel.AddComponent<LayoutElement>().minHeight = 300f;
        ContentSizeFitter fitter = panel.AddComponent<ContentSizeFitter>();
        fitter.horizontalFit = ContentSizeFitter.FitMode.Unconstrained;
        fitter.verticalFit = ContentSizeFitter.FitMode.PreferredSize;

        titleText = CreateText(panel.transform, "Title", 26);
        titleText.fontStyle = FontStyles.Bold;
        titleText.text = "Preparing your cafe";

        messageText = CreateText(panel.transform, "Status", 18);
        messageText.text = "Please wait...";

        signInButton = CreateButton(panel.transform, "SignInButton");
        signInButton.onClick.AddListener(HandleActionClicked);
        signInLabel = signInButton.GetComponentInChildren<TMP_Text>();

        retryButton = CreateButton(panel.transform, "RetryButton");
        retryButton.onClick.AddListener(HandleActionClicked);
        retryLabel = retryButton.GetComponentInChildren<TMP_Text>();
        signInButton.gameObject.SetActive(false);
        retryButton.gameObject.SetActive(false);

        noteText = CreateText(panel.transform, "InternetNote", 16);
        noteText.text = "An internet connection is required.";
        noteText.color = new Color(0.88f, 0.84f, 0.8f, 1f);
    }

    private static TMP_Text CreateText(
        Transform parent,
        string objectName,
        float fontSize)
    {
        GameObject value = new GameObject(objectName, typeof(RectTransform));
        value.transform.SetParent(parent, false);
        TMP_Text text = value.AddComponent<TextMeshProUGUI>();
        text.fontSize = fontSize;
        text.alignment = TextAlignmentOptions.Center;
        text.color = Color.white;
        text.raycastTarget = false;
        text.textWrappingMode = TextWrappingModes.Normal;
        text.overflowMode = TextOverflowModes.Overflow;
        text.margin = Vector4.zero;
        return text;
    }

    private static Button CreateButton(Transform parent, string objectName)
    {
        GameObject value = new GameObject(objectName, typeof(RectTransform));
        value.transform.SetParent(parent, false);
        Image image = value.AddComponent<Image>();
        image.color = new Color(0.85f, 0.55f, 0.2f, 1f);
        Button button = value.AddComponent<Button>();
        LayoutElement sizing = value.AddComponent<LayoutElement>();
        sizing.minHeight = 56f;
        sizing.preferredHeight = 56f;
        TMP_Text label = CreateText(value.transform, "Label", 18);
        label.color = new Color(0.12f, 0.07f, 0.03f, 1f);
        label.margin = new Vector4(16f, 4f, 16f, 4f);
        label.text = "Try Again";
        SetFullRect(label.rectTransform);
        return button;
    }

    private static string GetTitle(ApplicationReadinessState state)
    {
        return state == ApplicationReadinessState.AuthenticationRequired
            ? "Sign in to continue"
            : state == ApplicationReadinessState.RecoverableError
                ? "Cafe startup needs attention"
                : "Preparing your cafe";
    }

    private static string GetMessage(
        ApplicationReadinessState state,
        GooglePlayGamesAuthenticationFailure failure,
        GooglePlayGamesAuthenticationState authenticationState)
    {
        return state == ApplicationReadinessState.AuthenticationRequired
            ? "Sign in with Google Play Games to load your cafe progress."
            : state == ApplicationReadinessState.RecoverableError
                ? GetRecoveryMessage(failure, authenticationState)
                : "Loading your cafe and tutorial progress...";
    }

    private static string GetRecoveryMessage(
        GooglePlayGamesAuthenticationFailure failure,
        GooglePlayGamesAuthenticationState authenticationState)
    {
        if (authenticationState ==
            GooglePlayGamesAuthenticationState.Cancelled)
            return "Sign-in was cancelled. You can try again when ready.";

        switch (failure)
        {
            case GooglePlayGamesAuthenticationFailure.PlayGamesAuthentication:
            case GooglePlayGamesAuthenticationFailure.SessionRestoration:
                return "Google Play Games could not sign you in. Try again.";
            case GooglePlayGamesAuthenticationFailure.UnityAuthentication:
                return "Account sign-in could not be completed. Try again.";
            case GooglePlayGamesAuthenticationFailure.AuthorizationCodeUnavailable:
                return "Google Play Games sign-in could not be verified. Try again.";
            default:
                return "We could not finish startup. Check your connection and try again.";
        }
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
}
