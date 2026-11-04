using System;
using System.Collections;
using SweetMerge.Analytics;
using SweetMerge.Authentication;
using SweetMerge.Cloud;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

namespace SweetMerge.Startup
{
    internal static class StartupIntegrationPolicy
    {
        internal static bool IsFeatureEnabledByDefault(
            bool isDevelopmentBuild)
        {
            return isDevelopmentBuild;
        }

        internal static bool ShouldBindOwner(
            bool featureEnabled,
            bool restorePending)
        {
            return featureEnabled || restorePending;
        }

        internal static bool AreRequiredDependenciesReady(
            bool restorePending,
            bool privacyUiAvailable,
            bool loadingUiAvailable,
            bool analyticsAvailable,
            bool gameStartupAvailable)
        {
            return privacyUiAvailable &&
                   loadingUiAvailable &&
                   (restorePending ||
                    (analyticsAvailable && gameStartupAvailable));
        }

        internal static bool HasDependencyWaitExpired(
            float elapsedSeconds,
            float timeoutSeconds)
        {
            return elapsedSeconds >= timeoutSeconds;
        }

        internal static bool ShouldBlockSaveLoad(
            bool gateRequired,
            bool decisionConfirmed)
        {
            return gateRequired && !decisionConfirmed;
        }

        internal static bool ShouldStartSaveInitialization(
            bool startupAttempted)
        {
            return !startupAttempted;
        }

        internal static bool CanConfirmStartupDecision(
            bool gateRequired,
            bool decisionConfirmed,
            bool restorePending,
            StartupPlayMode playMode,
            bool googleIdentityVerified)
        {
            return gateRequired &&
                   !decisionConfirmed &&
                   !restorePending &&
                   (playMode == StartupPlayMode.Guest
                       ? !googleIdentityVerified
                       : playMode == StartupPlayMode.Google &&
                         googleIdentityVerified);
        }

        internal static bool ShouldSuppressLegacyAnalyticsPrompt(
            bool integrationEnabled,
            string sceneName)
        {
            return integrationEnabled &&
                   sceneName == SceneNavigationManager.MainBakeryScene;
        }

        internal static bool ShouldShowLoadingOverlay(
            bool readinessReady,
            bool startupSelectionOwnsInput)
        {
            return !readinessReady && !startupSelectionOwnsInput;
        }

        internal static bool ShouldShowTutorialWelcome(
            bool integrationEnabled,
            bool startupDecisionConfirmed,
            bool localStartupReady)
        {
            return !integrationEnabled ||
                   (startupDecisionConfirmed && localStartupReady);
        }

        internal static bool ShouldStartFlow(
            bool integrationEnabled,
            bool isMainBakery,
            bool startupDecisionConfirmed)
        {
            return integrationEnabled &&
                   isMainBakery &&
                   !startupDecisionConfirmed;
        }

        internal static bool ShouldStartWelcomeFlow(
            bool integrationEnabled,
            bool isWelcome,
            bool startupDecisionConfirmed)
        {
            return integrationEnabled &&
                   isWelcome &&
                   !startupDecisionConfirmed;
        }

        internal static bool AreWelcomeDependenciesReady(
            bool viewAvailable,
            bool analyticsAvailable,
            bool authenticationAvailable)
        {
            return viewAvailable &&
                   analyticsAvailable &&
                   authenticationAvailable;
        }
    }

    public sealed class StartupFlowIntegrationOwner : MonoBehaviour
    {
        private const float DependencyWaitTimeoutSeconds = 5f;
#if DEVELOPMENT_BUILD
        private const bool IsDevelopmentBuild = true;
#else
        private const bool IsDevelopmentBuild = false;
#endif

        private static StartupFlowIntegrationOwner instance;
        private static bool selectionInputActive;
        private static GameObject welcomeDependencyFallback;

        internal static bool FeatureEnabled { get; } =
            StartupIntegrationPolicy.IsFeatureEnabledByDefault(
                IsDevelopmentBuild);
        internal static string DependencyFailureMessage { get; private set; }
        internal static bool SelectionInputActive =>
            selectionInputActive;
        internal static event Action<bool> SelectionInputChanged;

        private StartupPrivacyWelcomeUI startupView;
        private StartupFlowCoordinator flowCoordinator;
        private Coroutine bindingCoroutine;
        private bool startupDecisionConfirmed;
        private bool pendingRestoreMode;
        private bool pendingAuthenticationInProgress;
        private bool restoreResolvedAwaitingTransition;
        private int pendingAuthenticationVersion;

        [RuntimeInitializeOnLoadMethod(
            RuntimeInitializeLoadType.BeforeSceneLoad)]
        private static void InstallPendingRestoreOwner()
        {
            bool restorePending = SimpleCloudFiles.RefreshPendingState();
            if (!restorePending ||
                DevelopmentStartupSceneRouter.IsRoutingEnabledForThisPlayer)
                return;

            if (instance == null)
            {
                var ownerObject =
                    new GameObject(nameof(StartupFlowIntegrationOwner));
                ownerObject.AddComponent<StartupFlowIntegrationOwner>();
            }
        }

        public static bool CanPresentTutorialWelcome
        {
            get
            {
                if (!FeatureEnabled)
                    return true;

                StartupFlowIntegrationOwner current = instance;
                GameStartupCoordinator gameStartup =
                    GameStartupCoordinator.Instance;
                ApplicationReadinessCoordinator readiness =
                    ApplicationReadinessCoordinator.Instance;
                bool localStartupReady =
                    gameStartup != null &&
                    gameStartup.IsStartupComplete &&
                    readiness != null &&
                    readiness.CanBeginGameplay;
                return StartupIntegrationPolicy.ShouldShowTutorialWelcome(
                    true,
                    current != null &&
                        current.startupDecisionConfirmed,
                    localStartupReady);
            }
        }

        internal static bool ConfirmCurrentRunDecision()
        {
            StartupFlowIntegrationOwner current = instance;
            DevelopmentStartupSceneRouter router =
                DevelopmentStartupSceneRouter.Instance;
            if (current == null ||
                router == null ||
                SimpleCloudFiles.StartupRestorePending ||
                !router.TryGetCurrentRunDecision(
                    out StartupPlayMode playMode,
                    out bool googleIdentityVerified))
                return false;

            current.ConfirmStartupDecision(
                playMode,
                googleIdentityVerified);
            return current.startupDecisionConfirmed;
        }

        [RuntimeInitializeOnLoadMethod(
            RuntimeInitializeLoadType.SubsystemRegistration)]
        private static void ResetStaticState()
        {
            instance = null;
            selectionInputActive = false;
            SelectionInputChanged = null;
            DependencyFailureMessage = null;
        }

        [RuntimeInitializeOnLoadMethod(
            RuntimeInitializeLoadType.BeforeSceneLoad)]
        private static void ConfigureAnalyticsPrompt()
        {
            AnalyticsBootstrap.StartupPrivacyPromptSuppressed =
                StartupIntegrationPolicy.ShouldSuppressLegacyAnalyticsPrompt(
                    FeatureEnabled,
                    SceneNavigationManager.MainBakeryScene);
        }

        [RuntimeInitializeOnLoadMethod(
            RuntimeInitializeLoadType.AfterSceneLoad)]
        private static void InstallForStartupScene()
        {
            bool restorePending = SimpleCloudFiles.StartupRestorePending;
            string activeSceneName = SceneManager.GetActiveScene().name;
            bool isMainBakery = activeSceneName ==
                SceneNavigationManager.MainBakeryScene;
            bool isWelcome = activeSceneName ==
                DevelopmentStartupSceneRouter.WelcomeSceneName;
            bool startNormalFlow =
                StartupIntegrationPolicy.ShouldStartFlow(
                    FeatureEnabled,
                    isMainBakery,
                    instance != null &&
                        instance.startupDecisionConfirmed) ||
                StartupIntegrationPolicy.ShouldStartWelcomeFlow(
                    DevelopmentStartupSceneRouter
                        .IsRoutingEnabledForThisPlayer,
                    isWelcome,
                    instance != null &&
                        instance.startupDecisionConfirmed);
            if ((!isMainBakery && !isWelcome) ||
                (!restorePending && !startNormalFlow))
                return;

            if (instance == null)
            {
                var ownerObject =
                    new GameObject(nameof(StartupFlowIntegrationOwner));
                ownerObject.AddComponent<StartupFlowIntegrationOwner>();
                return;
            }

            instance.BindForCurrentScene();
        }

        private void Awake()
        {
            if (instance != null && instance != this)
            {
                Destroy(gameObject);
                return;
            }

            instance = this;
            DontDestroyOnLoad(gameObject);
            pendingRestoreMode = SimpleCloudFiles.StartupRestorePending;
            if (!FeatureEnabled && !pendingRestoreMode)
                return;

            if (FeatureEnabled)
            {
                AnalyticsBootstrap.StartupPrivacyPromptSuppressed = true;
                if (SceneManager.GetActiveScene().name ==
                    SceneNavigationManager.MainBakeryScene)
                    RequireStartupDecisionGate();
            }

            SceneManager.sceneLoaded += HandleSceneLoaded;
            SimpleCloudFiles.RestorePendingChanged +=
                HandleRestorePendingChanged;
        }

        private void Start()
        {
            if (FeatureEnabled || SimpleCloudFiles.StartupRestorePending)
                BindForCurrentScene();
        }

        private void OnDestroy()
        {
            SceneManager.sceneLoaded -= HandleSceneLoaded;
            SimpleCloudFiles.RestorePendingChanged -=
                HandleRestorePendingChanged;
            if (bindingCoroutine != null)
                StopCoroutine(bindingCoroutine);
            UnbindStartupFlow();
            SetSelectionInputActive(false);
            if (instance == this)
                instance = null;
        }

        private void HandleSceneLoaded(Scene scene, LoadSceneMode mode)
        {
            bool isMainBakery = scene.name ==
                SceneNavigationManager.MainBakeryScene;
            bool isWelcome = scene.name ==
                DevelopmentStartupSceneRouter.WelcomeSceneName;
            if (!isMainBakery && !isWelcome)
            {
                SetSelectionInputActive(false);
                return;
            }

            if (SimpleCloudFiles.StartupRestorePending)
            {
                pendingRestoreMode = true;
                if (isMainBakery)
                    RequireStartupDecisionGate();
                BindForCurrentScene();
                return;
            }

            if (isWelcome &&
                DevelopmentStartupSceneRouter.IsRoutingEnabledForThisPlayer)
            {
                BindForCurrentScene();
                return;
            }

            if (isMainBakery &&
                FeatureEnabled &&
                !startupDecisionConfirmed)
            {
                RequireStartupDecisionGate();
                if (!ConfirmCurrentRunDecision() &&
                    !LoadingSceneStartupPresenter.IsActiveForDevelopment)
                    BindForCurrentScene();
            }
        }

        private void RequireStartupDecisionGate()
        {
            GameStartupCoordinator gameStartup =
                GameStartupCoordinator.Instance;
            if (gameStartup == null)
            {
                Debug.LogError(
                    "STARTUP | GameStartupCoordinator is unavailable; " +
                    "startup selection remains gated.");
                return;
            }

            gameStartup.RequireStartupDecisionGate();
        }

        private void BindForCurrentScene()
        {
            string activeSceneName = SceneManager.GetActiveScene().name;
            bool supportedScene =
                activeSceneName == SceneNavigationManager.MainBakeryScene ||
                activeSceneName ==
                    DevelopmentStartupSceneRouter.WelcomeSceneName;
            if (!StartupIntegrationPolicy.ShouldBindOwner(
                    FeatureEnabled,
                    SimpleCloudFiles.StartupRestorePending) ||
                (startupDecisionConfirmed &&
                 !SimpleCloudFiles.StartupRestorePending) ||
                !supportedScene ||
                bindingCoroutine != null)
                return;

            bindingCoroutine = StartCoroutine(BindWhenAvailable());
        }

        private IEnumerator BindWhenAvailable()
        {
            float startedAt = Time.realtimeSinceStartup;
            bool restorePending;
            while (ShouldContinueBinding(out restorePending))
            {
                StartupPrivacyWelcomeUI view =
                    FindAnyObjectByType<StartupPrivacyWelcomeUI>();
                bool isWelcome = SceneManager.GetActiveScene().name ==
                    DevelopmentStartupSceneRouter.WelcomeSceneName;
                MainBakeryStartupUI loading = isWelcome
                    ? null
                    : FindAnyObjectByType<MainBakeryStartupUI>();
                bool dependenciesReady;
                if (isWelcome)
                {
                    dependenciesReady =
                        StartupIntegrationPolicy.AreWelcomeDependenciesReady(
                            view != null && view.isActiveAndEnabled,
                            AnalyticsBootstrap.Instance != null,
                            GooglePlayGamesAuthenticationCoordinator.Instance !=
                                null);
                }
                else
                {
                    dependenciesReady =
                        StartupIntegrationPolicy.AreRequiredDependenciesReady(
                            restorePending,
                            view != null && view.isActiveAndEnabled,
                            loading != null && loading.isActiveAndEnabled,
                            AnalyticsBootstrap.Instance != null,
                            GameStartupCoordinator.Instance != null);
                }

                if (dependenciesReady)
                {
                    ClearDependencyFailure();
                    if (restorePending)
                    {
                        BindPendingRestoreRecovery(view);
                    }
                    else
                        BindStartupFlow(view, loading);

                    bindingCoroutine = null;
                    yield break;
                }

                if (StartupIntegrationPolicy.HasDependencyWaitExpired(
                        Time.realtimeSinceStartup - startedAt,
                        DependencyWaitTimeoutSeconds))
                    break;

                yield return null;
            }

            bindingCoroutine = null;
            if (ShouldContinueBinding(out restorePending))
            {
                string message = restorePending
                    ? "Cloud restore recovery could not start because required startup UI is unavailable. Retry to check again; local progress remains protected."
                    : "Startup could not continue because required privacy/loading UI, local startup coordination, or analytics services are unavailable. Retry to check again; Save V2 remains blocked.";
                ShowDependencyFailure(message);
            }
        }

        private bool ShouldContinueBinding(out bool restorePending)
        {
            restorePending = SimpleCloudFiles.StartupRestorePending;
            string activeSceneName = SceneManager.GetActiveScene().name;
            return StartupIntegrationPolicy.ShouldBindOwner(
                       FeatureEnabled,
                       restorePending) &&
                   (!startupDecisionConfirmed || restorePending) &&
                   (activeSceneName ==
                        SceneNavigationManager.MainBakeryScene ||
                    activeSceneName ==
                        DevelopmentStartupSceneRouter.WelcomeSceneName);
        }

        internal static void RetryDependencyBinding()
        {
            if (instance == null)
                return;

            instance.BindForCurrentScene();
        }

        private static void ShowDependencyFailure(string message)
        {
            DependencyFailureMessage = message;
            Debug.LogError("STARTUP | " + message);
            if (SceneManager.GetActiveScene().name ==
                DevelopmentStartupSceneRouter.WelcomeSceneName)
            {
                StartupPrivacyWelcomeUI welcome =
                    StartupPrivacyWelcomeUI.EnsureForScene(
                        SceneManager.GetActiveScene());
                if (welcome != null && welcome.isActiveAndEnabled)
                {
                    bool restorePending =
                        SimpleCloudFiles.StartupRestorePending;
                    AnalyticsBootstrap analytics =
                        AnalyticsBootstrap.Instance;
                    bool consentResolved = false;
                    if (analytics != null)
                    {
                        try
                        {
                            consentResolved =
                                analytics.AnalyticsConsent !=
                                UnityEngine.UnityConsent.ConsentStatus
                                    .Unspecified;
                        }
                        catch (Exception exception)
                        {
                            Debug.LogWarning(
                                "STARTUP | Analytics consent could not be " +
                                "read while presenting recovery.\n" +
                                exception);
                        }
                    }

                    if (consentResolved)
                    {
                        welcome.ShowWelcome();
                        welcome.SetFeedback(message);
                    }
                    else
                    {
                        welcome.ShowPrivacy();
                        welcome.SetPrivacyFeedback(message);
                    }
                    if (restorePending)
                    {
                        welcome.SetGuestPlayVisible(false);
                        welcome.SetWelcomeActionsInteractable(false);
                    }
                    welcome.SetRetryStartupVisible(true);
                    welcome.SetPrivacyActionsInteractable(false);
                    SetSelectionInputActive(true);
                    return;
                }

                ShowWelcomeDependencyFallback(message);
                return;
            }

            MainBakeryStartupUI loading =
                FindAnyObjectByType<MainBakeryStartupUI>();
            if (loading == null || !loading.isActiveAndEnabled)
                loading = CreateLoadingUiFallback();

            if (loading == null)
            {
                Debug.LogError(
                    "STARTUP | No MainBakery startup error UI could be created. " +
                    "Startup remains gated.");
                return;
            }

            loading.ShowStartupDependencyFailure();
        }

        private static void ClearDependencyFailure()
        {
            if (DependencyFailureMessage == null)
                return;

            DependencyFailureMessage = null;
            RemoveWelcomeDependencyFallback();
            StartupPrivacyWelcomeUI welcome =
                FindAnyObjectByType<StartupPrivacyWelcomeUI>();
            if (welcome != null)
            {
                welcome.SetRetryStartupVisible(false);
                welcome.SetPrivacyActionsInteractable(true);
            }
            MainBakeryStartupUI loading =
                FindAnyObjectByType<MainBakeryStartupUI>();
            if (loading != null)
                loading.ClearStartupDependencyFailure();
        }

        private static void ShowWelcomeDependencyFallback(string message)
        {
            Scene scene = SceneManager.GetActiveScene();
            if (!scene.IsValid() ||
                scene.name != DevelopmentStartupSceneRouter.WelcomeSceneName)
            {
                Debug.LogError(
                    "STARTUP | Welcome dependency fallback was requested " +
                    "outside the Welcome scene.");
                return;
            }

            Canvas canvas = null;
            foreach (GameObject root in scene.GetRootGameObjects())
            {
                Canvas[] canvases = root.GetComponentsInChildren<Canvas>(true);
                foreach (Canvas candidate in canvases)
                {
                    if (candidate.name == "WelcomeCanvas")
                    {
                        canvas = candidate;
                        break;
                    }
                }

                if (canvas != null)
                    break;
            }

            if (canvas == null)
            {
                Debug.LogError(
                    "STARTUP | WelcomeCanvas is unavailable; startup " +
                    "remains blocked without a visible retry.");
                return;
            }

            if (welcomeDependencyFallback == null)
            {
                welcomeDependencyFallback = new GameObject(
                    "StartupDependencyFailureFallback",
                    typeof(RectTransform),
                    typeof(Canvas),
                    typeof(GraphicRaycaster),
                    typeof(Image));
                welcomeDependencyFallback.transform.SetParent(
                    canvas.transform,
                    false);
                RectTransform rootRect =
                    welcomeDependencyFallback.GetComponent<RectTransform>();
                rootRect.anchorMin = Vector2.zero;
                rootRect.anchorMax = Vector2.one;
                rootRect.offsetMin = Vector2.zero;
                rootRect.offsetMax = Vector2.zero;

                Canvas overlayCanvas =
                    welcomeDependencyFallback.GetComponent<Canvas>();
                overlayCanvas.overrideSorting = true;
                overlayCanvas.sortingLayerID =
                    canvas.rootCanvas.sortingLayerID;
                overlayCanvas.sortingOrder = short.MaxValue;
                Image backdrop =
                    welcomeDependencyFallback.GetComponent<Image>();
                backdrop.color = new Color(0.035f, 0.025f, 0.02f, 0.94f);
                backdrop.raycastTarget = true;

                Font fallbackFont =
                    Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
                if (fallbackFont == null)
                    fallbackFont =
                        Resources.GetBuiltinResource<Font>("Arial.ttf");
                if (fallbackFont == null)
                {
                    Debug.LogError(
                        "STARTUP | The built-in fallback font is unavailable; " +
                        "startup remains blocked.");
                    RemoveWelcomeDependencyFallback();
                    return;
                }

                GameObject statusObject = new GameObject(
                    "Status",
                    typeof(RectTransform),
                    typeof(Text));
                statusObject.transform.SetParent(
                    welcomeDependencyFallback.transform,
                    false);
                RectTransform statusRect =
                    statusObject.GetComponent<RectTransform>();
                statusRect.anchorMin = new Vector2(0.1f, 0.35f);
                statusRect.anchorMax = new Vector2(0.9f, 0.75f);
                statusRect.offsetMin = Vector2.zero;
                statusRect.offsetMax = Vector2.zero;
                Text status = statusObject.GetComponent<Text>();
                status.font = fallbackFont;
                status.fontSize = 24;
                status.alignment = TextAnchor.MiddleCenter;
                status.color = Color.white;
                status.horizontalOverflow = HorizontalWrapMode.Wrap;
                status.verticalOverflow = VerticalWrapMode.Truncate;
                status.raycastTarget = false;

                GameObject retryObject = new GameObject(
                    "RetryButton",
                    typeof(RectTransform),
                    typeof(Image),
                    typeof(Button));
                retryObject.transform.SetParent(
                    welcomeDependencyFallback.transform,
                    false);
                RectTransform retryRect =
                    retryObject.GetComponent<RectTransform>();
                retryRect.anchorMin = new Vector2(0.3f, 0.18f);
                retryRect.anchorMax = new Vector2(0.7f, 0.30f);
                retryRect.offsetMin = Vector2.zero;
                retryRect.offsetMax = Vector2.zero;
                Image retryImage = retryObject.GetComponent<Image>();
                retryImage.color = new Color(0.85f, 0.55f, 0.2f, 1f);
                Button retryButton = retryObject.GetComponent<Button>();
                retryButton.targetGraphic = retryImage;
                retryButton.onClick.AddListener(RetryDependencyBinding);

                GameObject labelObject = new GameObject(
                    "Label",
                    typeof(RectTransform),
                    typeof(Text));
                labelObject.transform.SetParent(retryObject.transform, false);
                RectTransform labelRect =
                    labelObject.GetComponent<RectTransform>();
                labelRect.anchorMin = Vector2.zero;
                labelRect.anchorMax = Vector2.one;
                labelRect.offsetMin = Vector2.zero;
                labelRect.offsetMax = Vector2.zero;
                Text label = labelObject.GetComponent<Text>();
                label.font = fallbackFont;
                label.fontSize = 20;
                label.alignment = TextAnchor.MiddleCenter;
                label.color = new Color(0.12f, 0.07f, 0.03f, 1f);
                label.text = "Retry Startup";
                label.raycastTarget = false;
            }

            Text statusText =
                welcomeDependencyFallback.GetComponentInChildren<Text>();
            if (statusText != null)
                statusText.text = message;
        }

        private static void RemoveWelcomeDependencyFallback()
        {
            if (welcomeDependencyFallback == null)
                return;

            if (Application.isPlaying)
                Destroy(welcomeDependencyFallback);
            else
                DestroyImmediate(welcomeDependencyFallback);
            welcomeDependencyFallback = null;
        }

        private static MainBakeryStartupUI CreateLoadingUiFallback()
        {
            Scene scene = SceneManager.GetActiveScene();
            if (!scene.IsValid() ||
                scene.name != SceneNavigationManager.MainBakeryScene)
                return null;

            foreach (GameObject root in scene.GetRootGameObjects())
            {
                foreach (Canvas canvas in
                         root.GetComponentsInChildren<Canvas>(true))
                {
                    if (canvas.name != "MainCanvas")
                        continue;

                    var host = new GameObject(
                        nameof(MainBakeryStartupUI),
                        typeof(RectTransform));
                    host.transform.SetParent(canvas.transform, false);
                    return host.AddComponent<MainBakeryStartupUI>();
                }
            }

            return null;
        }

        private void BindStartupFlow(
            StartupPrivacyWelcomeUI view,
            MainBakeryStartupUI loading)
        {
            if (startupView == view && flowCoordinator != null)
                return;

            UnbindStartupFlow();
            startupView = view;
            startupView.SetPrivacyActionsInteractable(true);
            startupView.LifecycleEnded += HandleStartupViewEnded;
            startupView.RetryStartupRequested += HandleRetryStartupRequested;

            var flow = new StartupFlowMachine(
                new StartupPlayModeStore());
            flowCoordinator = new StartupFlowCoordinator(
                flow,
                startupView,
                AnalyticsBootstrap.Instance,
                GooglePlayGamesAuthenticationCoordinator.Instance);
            flowCoordinator.OutcomeChanged += HandleOutcomeChanged;

            if (!flowCoordinator.Initialize())
            {
                Debug.LogError(
                    "STARTUP | Startup flow initialization failed.");
            }

            HandleOutcomeChanged(flowCoordinator.Outcome);
        }

        private void BindPendingRestoreRecovery(
            StartupPrivacyWelcomeUI view)
        {
            UnbindStartupFlow();
            pendingRestoreMode = true;
            startupView = view;
            startupView.SetPrivacyActionsInteractable(true);
            startupView.LifecycleEnded += HandleStartupViewEnded;
            startupView.GoogleSignInRequested +=
                HandlePendingInteractiveSignInRequested;
            startupView.RetryGoogleRestorationRequested +=
                HandlePendingCachedSessionRetryRequested;
            startupView.AnalyticsAllowed += HandlePendingAnalyticsAllowed;
            startupView.AnalyticsDeclined += HandlePendingAnalyticsDeclined;
            startupView.SwitchAccountRequested +=
                HandleSwitchAccountRequested;
            startupView.RetryStartupRequested += HandleRetryStartupRequested;
            startupView.SetGuestPlayVisible(false);
            startupView.SetGoogleRecoveryActionsVisible(false);
            startupView.SetSwitchAccountVisible(false);
            startupView.SetRetryStartupVisible(false);
            startupView.SetWelcomeActionsInteractable(true);
            SetSelectionInputActive(true);

            if (SimpleCloudFiles.StartupError != null)
            {
                startupView.ShowWelcome();
                startupView.SetGoogleRecoveryActionsVisible(true);
                startupView.SetCachedSessionRetryVisible(false);
                startupView.SetSwitchAccountVisible(true);
                startupView.SetRetryStartupVisible(true);
                startupView.SetFeedback(SimpleCloudFiles.StartupError);
                return;
            }

            ContinuePendingRestoreRecovery();
        }

        private void ContinuePendingRestoreRecovery()
        {
            if (startupView == null || !pendingRestoreMode)
                return;

            AnalyticsBootstrap analytics = AnalyticsBootstrap.Instance;
            UnityEngine.UnityConsent.ConsentStatus consent =
                UnityEngine.UnityConsent.ConsentStatus.Unspecified;
            if (analytics != null)
            {
                try
                {
                    consent = analytics.AnalyticsConsent;
                }
                catch (Exception exception)
                {
                    Debug.LogWarning(
                        "STARTUP | Analytics consent could not be read.\n" +
                        exception);
                    startupView.ShowPrivacy();
                    startupView.SetPrivacyFeedback(
                        "Privacy settings could not be read. Retry startup.");
                    startupView.SetRetryStartupVisible(true);
                    return;
                }
            }

            if (analytics == null ||
                consent == UnityEngine.UnityConsent.ConsentStatus.Unspecified)
            {
                startupView.ShowPrivacy();
                startupView.SetPrivacyFeedback(
                    analytics == null
                        ? "Privacy settings are unavailable. Retry startup."
                        : "Choose an analytics option before continuing " +
                          "with cloud recovery.");
                return;
            }

            startupView.ShowWelcome();
            startupView.SetFeedback(
                "A cloud restore is pending. Verify the Google account " +
                "that owns it to continue. Guest Play is unavailable.");
            BeginPendingRestoreAuthentication(
                restoreCachedSession: true);
        }

        private void CompletePendingPrivacyChoice(bool granted)
        {
            if (!pendingRestoreMode ||
                startupView == null ||
                !startupView.IsVisible ||
                startupView.VisibleScreen !=
                    StartupPrivacyWelcomeScreen.Privacy)
                return;

            AnalyticsBootstrap analytics = AnalyticsBootstrap.Instance;
            if (analytics == null)
            {
                startupView.SetPrivacyFeedback(
                    "Privacy settings are unavailable. Retry startup.");
                startupView.SetRetryStartupVisible(true);
                return;
            }

            try
            {
                analytics.SetAnalyticsConsent(granted);
                UnityEngine.UnityConsent.ConsentStatus expected = granted
                    ? UnityEngine.UnityConsent.ConsentStatus.Granted
                    : UnityEngine.UnityConsent.ConsentStatus.Denied;
                if (analytics.AnalyticsConsent != expected)
                {
                    startupView.SetPrivacyFeedback(
                        "Your analytics choice could not be confirmed. " +
                        "Please choose again.");
                    return;
                }
            }
            catch (Exception exception)
            {
                Debug.LogWarning(
                    "STARTUP | Analytics consent could not be saved.\n" +
                    exception);
                startupView.SetPrivacyFeedback(
                    "Your analytics choice could not be saved. " +
                    "Please choose again.");
                return;
            }

            startupView.SetPrivacyFeedback(string.Empty);
            ContinuePendingRestoreRecovery();
        }

        private void HandlePendingAnalyticsAllowed()
        {
            CompletePendingPrivacyChoice(true);
        }

        private void HandlePendingAnalyticsDeclined()
        {
            CompletePendingPrivacyChoice(false);
        }

        private void HandlePendingInteractiveSignInRequested()
        {
            BeginPendingRestoreAuthentication(
                restoreCachedSession: false);
        }

        private void HandlePendingCachedSessionRetryRequested()
        {
            BeginPendingRestoreAuthentication(
                restoreCachedSession: false);
        }

        private void HandleSwitchAccountRequested()
        {
            if (startupView == null || !pendingRestoreMode)
                return;

            startupView.SetFeedback(
                "To switch accounts, close the game and change the active " +
                "account in Google Play Games. Reopen the game, then use " +
                "Google Sign In to verify it. This action cannot switch " +
                "accounts inside the game.");
            startupView.SetRetryStartupVisible(false);
        }

        private void HandleRetryStartupRequested()
        {
            bool dependencyFailure =
                DependencyFailureMessage != null;
            if (restoreResolvedAwaitingTransition)
            {
                TryRequestLoading(StartupPlayMode.Google, true);
                return;
            }

            if (dependencyFailure)
            {
                BindForCurrentScene();
                return;
            }

            if (pendingRestoreMode)
            {
                if (SimpleCloudFiles.RestorePending)
                {
                    if (startupView != null &&
                        startupView.VisibleScreen ==
                            StartupPrivacyWelcomeScreen.Privacy)
                        ContinuePendingRestoreRecovery();
                    else
                        BeginPendingRestoreAuthentication(false);
                }
                else
                    ContinuePendingRestoreRecovery();
                return;
            }

            if (flowCoordinator != null && !flowCoordinator.Retry())
                HandleOutcomeChanged(flowCoordinator.Outcome);
        }

        private void BeginPendingRestoreAuthentication(
            bool restoreCachedSession)
        {
            if (!pendingRestoreMode ||
                pendingAuthenticationInProgress ||
                startupView == null ||
                !startupView.IsVisible ||
                startupView.VisibleScreen !=
                    StartupPrivacyWelcomeScreen.Welcome ||
                !SimpleCloudFiles.RestorePending)
                return;

            pendingAuthenticationInProgress = true;
            int operation = ++pendingAuthenticationVersion;
            startupView.SetGoogleRecoveryActionsVisible(false);
            startupView.SetSwitchAccountVisible(false);
            startupView.SetRetryStartupVisible(false);
            startupView.SetWelcomeActionsInteractable(false);
            startupView.SetFeedback(
                restoreCachedSession
                    ? "Verifying the saved Google Play Games session..."
                    : "Connecting to Google Play Games...");
            _ = CompletePendingRestoreAuthenticationAsync(
                operation,
                restoreCachedSession);
        }

        private async System.Threading.Tasks.Task
            CompletePendingRestoreAuthenticationAsync(
                int operation,
                bool restoreCachedSession)
        {
            string failureMessage = null;
            try
            {
                GooglePlayGamesAuthenticationCoordinator authentication =
                    GooglePlayGamesAuthenticationCoordinator.Instance;
                GooglePlayGamesAuthenticationResult result =
                    restoreCachedSession
                        ? await authentication.RestoreSessionAsync()
                        : await authentication.SignInInteractivelyAsync();

                if (operation != pendingAuthenticationVersion ||
                    !pendingRestoreMode ||
                    startupView == null)
                    return;

                if (result != GooglePlayGamesAuthenticationResult.SignedIn ||
                    authentication.SessionStatus !=
                        GooglePlayGamesSessionStatus
                            .GooglePlayGamesConnected)
                {
                    failureMessage =
                        "Google identity could not be verified. Retry the " +
                        "saved session or sign in interactively.";
                }
                else if (!new StartupPlayModeStore().TrySave(
                             StartupPlayMode.Google,
                             false,
                             out string selectionError))
                {
                    failureMessage = selectionError ??
                        "The verified Google selection could not be saved.";
                }
                else if (!SimpleCloudFiles.TryApplyPendingRestore(
                             out string restoreError))
                {
                    failureMessage = restoreError ??
                        "This Google account does not match the pending restore.";
                }
            }
            catch (Exception exception)
            {
                failureMessage =
                    "Google authentication or cloud restore failed: " +
                    exception.Message;
            }

            if (operation != pendingAuthenticationVersion ||
                !pendingRestoreMode ||
                startupView == null)
                return;

            pendingAuthenticationInProgress = false;
            startupView.SetWelcomeActionsInteractable(true);
            if (SimpleCloudFiles.RestorePending)
            {
                startupView.SetGoogleRecoveryActionsVisible(true);
                startupView.SetCachedSessionRetryVisible(false);
                startupView.SetSwitchAccountVisible(true);
                startupView.SetRetryStartupVisible(true);
                startupView.SetFeedback(
                    failureMessage ??
                    SimpleCloudFiles.StartupError ??
                    "The matching Google account is required. Guest play is unavailable until this restore is resolved.");
                return;
            }

            if (failureMessage != null)
            {
                restoreResolvedAwaitingTransition = true;
                startupView.SetGoogleRecoveryActionsVisible(false);
                startupView.SetSwitchAccountVisible(false);
                startupView.SetRetryStartupVisible(true);
                startupView.SetFeedback(failureMessage);
                return;
            }

            restoreResolvedAwaitingTransition = true;
            pendingRestoreMode = false;
            pendingAuthenticationVersion++;
            startupView.Hide();
            SetSelectionInputActive(false);
            if (SceneManager.GetActiveScene().name ==
                DevelopmentStartupSceneRouter.WelcomeSceneName)
                TryRequestLoading(StartupPlayMode.Google, true);
            else if (FeatureEnabled)
                BindForCurrentScene();
        }

        private void HandleRestorePendingChanged(bool restorePending)
        {
            if (restorePending)
            {
                if (!SimpleCloudFiles.StartupRestorePending)
                    return;

                pendingRestoreMode = true;
                if (SceneManager.GetActiveScene().name ==
                    SceneNavigationManager.MainBakeryScene)
                    BindForCurrentScene();
                return;
            }

            if (!pendingRestoreMode)
                return;

            if (pendingAuthenticationInProgress)
                return;

            pendingRestoreMode = false;
            pendingAuthenticationInProgress = false;
            pendingAuthenticationVersion++;
            SetSelectionInputActive(false);
            if (startupView != null)
                startupView.Hide();
            UnbindStartupFlow();

            if (FeatureEnabled)
                BindForCurrentScene();
        }

        private void HandleOutcomeChanged(StartupFlowOutcome outcome)
        {
            if (outcome == StartupFlowOutcome.GuestReady)
            {
                if (SceneManager.GetActiveScene().name ==
                    DevelopmentStartupSceneRouter.WelcomeSceneName)
                {
                    TryRequestLoading(StartupPlayMode.Guest, false);
                    return;
                }

                ConfirmStartupDecision(StartupPlayMode.Guest, false);
                return;
            }

            if (outcome == StartupFlowOutcome.GoogleVerified)
            {
                if (SceneManager.GetActiveScene().name ==
                    DevelopmentStartupSceneRouter.WelcomeSceneName)
                {
                    TryRequestLoading(StartupPlayMode.Google, true);
                    return;
                }

                ConfirmStartupDecision(StartupPlayMode.Google, true);
                return;
            }

            if (startupView != null)
                startupView.SetRetryStartupVisible(
                    outcome == StartupFlowOutcome.RecoverableFailure &&
                    flowCoordinator != null &&
                    flowCoordinator.CanRetry);
            bool selectionOwnsInput =
                startupView != null &&
                startupView.IsVisible &&
                (outcome == StartupFlowOutcome.Idle ||
                 outcome == StartupFlowOutcome.WaitingForAuthentication ||
                 outcome == StartupFlowOutcome.RecoverableFailure);
            SetSelectionInputActive(selectionOwnsInput);
        }

        private void TryRequestLoading(
            StartupPlayMode playMode,
            bool googleIdentityVerified)
        {
            DevelopmentStartupSceneRouter router =
                DevelopmentStartupSceneRouter.Instance;
            if (router != null &&
                router.RequestLoadingFromWelcome(
                    playMode,
                    googleIdentityVerified))
            {
                restoreResolvedAwaitingTransition = false;
                if (startupView != null)
                    startupView.SetRetryStartupVisible(false);
                SetSelectionInputActive(false);
                return;
            }

            if (startupView == null)
                return;

            startupView.ShowWelcome();
            startupView.SetRetryStartupVisible(true);
            startupView.SetFeedback(
                router != null &&
                !string.IsNullOrEmpty(router.RouteErrorMessage)
                    ? router.RouteErrorMessage
                    : "Startup could not continue safely. Retry when the " +
                      "required scene or verified account is available.");
            SetSelectionInputActive(true);
        }

        private void ConfirmStartupDecision(
            StartupPlayMode playMode,
            bool googleIdentityVerified)
        {
            if (startupDecisionConfirmed)
                return;

            GameStartupCoordinator gameStartup =
                GameStartupCoordinator.Instance;
            if (gameStartup == null)
            {
                Debug.LogError(
                    "STARTUP | Startup decision was confirmed, but the " +
                    "local startup coordinator is unavailable.");
                return;
            }

            startupDecisionConfirmed = true;
            SetSelectionInputActive(false);
            if (!gameStartup.ConfirmStartupDecision(
                    playMode,
                    googleIdentityVerified))
            {
                startupDecisionConfirmed = false;
                Debug.LogError(
                    "STARTUP | The verified startup decision could not " +
                    "release the local Save V2 load.");
                return;
            }
        }

        private void HandleStartupViewEnded()
        {
            pendingAuthenticationVersion++;
            pendingAuthenticationInProgress = false;
            SetSelectionInputActive(false);
            UnbindStartupFlow();
        }

        private void UnbindStartupFlow()
        {
            if (flowCoordinator != null)
            {
                flowCoordinator.OutcomeChanged -= HandleOutcomeChanged;
                flowCoordinator.Dispose();
                flowCoordinator = null;
            }

            if (startupView != null)
            {
                startupView.LifecycleEnded -= HandleStartupViewEnded;
                startupView.RetryStartupRequested -=
                    HandleRetryStartupRequested;
                startupView.GoogleSignInRequested -=
                    HandlePendingInteractiveSignInRequested;
                startupView.RetryGoogleRestorationRequested -=
                    HandlePendingCachedSessionRetryRequested;
                startupView.SwitchAccountRequested -=
                    HandleSwitchAccountRequested;
                startupView.AnalyticsAllowed -=
                    HandlePendingAnalyticsAllowed;
                startupView.AnalyticsDeclined -=
                    HandlePendingAnalyticsDeclined;
            }
            startupView = null;
        }

        private static void SetSelectionInputActive(bool active)
        {
            if (selectionInputActive == active)
                return;

            selectionInputActive = active;
            SelectionInputChanged?.Invoke(active);
        }
    }
}
