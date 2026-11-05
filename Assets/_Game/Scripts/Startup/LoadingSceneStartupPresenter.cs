using System;
using System.Collections.Generic;
using SweetMerge.Authentication;
using SweetMerge.Cloud;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

namespace SweetMerge.Startup
{
    internal static class LoadingPresenterPolicy
    {
        internal static bool ShouldRun(bool developmentBuild, bool editor)
        {
            return developmentBuild && !editor;
        }

        internal static bool ShouldInstall(
            bool developmentBuild,
            bool editor,
            string sceneName)
        {
            return ShouldRun(developmentBuild, editor) &&
                   sceneName == DevelopmentStartupSceneRouter.LoadingSceneName;
        }

        internal static bool ShouldPersistPresenter(
            bool developmentBuild,
            bool editor,
            bool loadingScene,
            bool transitioningToMainBakery)
        {
            return ShouldRun(developmentBuild, editor) &&
                   loadingScene &&
                   transitioningToMainBakery;
        }

        internal static bool CanDismiss(
            bool canBeginGameplay,
            bool saveStartupSucceeded,
            bool decisionConfirmed,
            bool restorePending,
            bool startupErrorUnresolved)
        {
            return DevelopmentStartupRoutePolicy.CanDismissLoading(
                canBeginGameplay,
                saveStartupSucceeded,
                decisionConfirmed,
                restorePending,
                startupErrorUnresolved);
        }

        internal static bool ShouldOfferRetry(
            bool timedOut,
            bool startupFailed,
            bool dependencyFailure)
        {
            return timedOut || startupFailed || dependencyFailure;
        }

        internal static bool ShouldUseLoadingEventSystem(
            bool mainBakeryLoaded,
            bool hasMainBakeryEventSystem)
        {
            return !mainBakeryLoaded || !hasMainBakeryEventSystem;
        }
    }

    [DefaultExecutionOrder(-1000)]
    public sealed class LoadingSceneStartupPresenter : MonoBehaviour
    {
        private const float StartupTimeoutSeconds = 45f;
        private const string LoadingCanvasName = "LoadingCanvas";

#if DEVELOPMENT_BUILD && !UNITY_EDITOR
        private const bool IsDevelopmentPlayer = true;
#else
        private const bool IsDevelopmentPlayer = false;
#endif

        private static LoadingSceneStartupPresenter instance;
        private Canvas loadingCanvas;
        private EventSystem loadingEventSystem;
        private EventSystem[] mainBakeryEventSystems =
            Array.Empty<EventSystem>();
        private GameObject overlayRoot;
        private Text titleText;
        private Text statusText;
        private Text retryLabel;
        private Button retryButton;
        private ApplicationReadinessCoordinator readiness;
        private GameStartupCoordinator gameStartup;
        private float mainBakeryWaitStartedAt;
        private bool mainBakeryActive;
        private bool transitionInProgress;
        private bool timedOut;

        internal static LoadingSceneStartupPresenter Instance => instance;

        internal static bool IsActiveForDevelopment =>
            LoadingPresenterPolicy.ShouldRun(
                IsDevelopmentPlayer,
                Application.isEditor) &&
            instance != null;

        [RuntimeInitializeOnLoadMethod(
            RuntimeInitializeLoadType.SubsystemRegistration)]
        private static void ResetStaticState()
        {
            SceneManager.sceneLoaded -= HandleSceneLoadedBeforeInstance;
            instance = null;
        }

        [RuntimeInitializeOnLoadMethod(
            RuntimeInitializeLoadType.BeforeSceneLoad)]
        private static void ListenForSceneLoads()
        {
            SceneManager.sceneLoaded -= HandleSceneLoadedBeforeInstance;
            SceneManager.sceneLoaded += HandleSceneLoadedBeforeInstance;
        }

        [RuntimeInitializeOnLoadMethod(
            RuntimeInitializeLoadType.AfterSceneLoad)]
        private static void InstallForActiveScene()
        {
            EnsureForScene(SceneManager.GetActiveScene());
        }

        private static void HandleSceneLoadedBeforeInstance(
            Scene scene,
            LoadSceneMode mode)
        {
            EnsureForScene(scene);
        }

        private static void EnsureForScene(Scene scene)
        {
            if (!LoadingPresenterPolicy.ShouldInstall(
                    IsDevelopmentPlayer,
                    Application.isEditor,
                    scene.name))
                return;

            if (instance != null)
                return;

            Canvas canvas = FindLoadingCanvas(scene);
            if (canvas == null)
            {
                canvas = CreateFallbackCanvas(scene);
                if (canvas == null)
                {
                    Debug.LogError(
                        "STARTUP LOADING | LoadingCanvas is missing and a " +
                        "blocking recovery canvas could not be created.");
                    return;
                }
            }

            LoadingSceneStartupPresenter presenter =
                canvas.GetComponent<LoadingSceneStartupPresenter>();
            if (presenter == null)
                presenter = canvas.gameObject
                    .AddComponent<LoadingSceneStartupPresenter>();
            instance = presenter;
        }

        private void Awake()
        {
            if (!LoadingPresenterPolicy.ShouldInstall(
                    IsDevelopmentPlayer,
                    Application.isEditor,
                    SceneManager.GetActiveScene().name))
            {
                enabled = false;
                return;
            }

            if (instance != null && instance != this)
            {
                Destroy(this);
                return;
            }

            instance = this;
            loadingCanvas = GetComponent<Canvas>();
            if (loadingCanvas == null ||
                loadingCanvas.rootCanvas.renderMode !=
                    RenderMode.ScreenSpaceOverlay)
            {
                ShowError(
                    "The Loading scene requires its Screen Space Overlay Canvas.");
                return;
            }

            BuildInterface();
            EnsureLoadingEventSystem();
            SceneManager.sceneLoaded += HandleSceneLoaded;
        }

        private System.Collections.IEnumerator Start()
        {
            yield return null;
            if (SceneManager.GetActiveScene().name ==
                DevelopmentStartupSceneRouter.LoadingSceneName)
                BeginMainBakeryTransition();
        }

        private void Update()
        {
            if (!mainBakeryActive)
            {
                if (!string.IsNullOrEmpty(
                        DevelopmentStartupSceneRouter.Instance == null
                            ? null
                            : DevelopmentStartupSceneRouter.Instance
                                .RouteErrorMessage))
                {
                    ShowError(
                        DevelopmentStartupSceneRouter.Instance
                            .RouteErrorMessage);
                }

                return;
            }

            BindReadinessSources();
            RefreshMainBakeryReadiness();
        }

        private void OnDestroy()
        {
            SceneManager.sceneLoaded -= HandleSceneLoaded;
            UnsubscribeReadinessSources();
            if (instance == this)
                instance = null;
        }

        private void HandleSceneLoaded(Scene scene, LoadSceneMode mode)
        {
            if (scene.name == DevelopmentStartupSceneRouter.LoadingSceneName)
            {
                transitionInProgress = false;
                mainBakeryActive = false;
                EnsureLoadingEventSystem();
                return;
            }

            if (scene.name == SceneNavigationManager.MainBakeryScene)
            {
                mainBakeryActive = true;
                transitionInProgress = false;
                mainBakeryWaitStartedAt = Time.realtimeSinceStartup;
                timedOut = false;
                TakeEventSystemOwnership(scene);
                BindReadinessSources();
                SetStatus(
                    "Preparing your cafe",
                    "Loading your local save and checking startup readiness...");
                return;
            }

            if (scene.name == DevelopmentStartupSceneRouter.WelcomeSceneName)
            {
                transitionInProgress = false;
                mainBakeryActive = false;
                ReleaseEventSystemForScene(scene);
                DestroyPresenterCanvas();
            }
        }

        private void BeginMainBakeryTransition()
        {
            if (transitionInProgress ||
                SceneManager.GetActiveScene().name !=
                    DevelopmentStartupSceneRouter.LoadingSceneName)
                return;

            DevelopmentStartupSceneRouter router =
                DevelopmentStartupSceneRouter.Instance;
            if (router == null)
            {
                ShowError(
                    "The startup scene router is unavailable. Retry startup.");
                return;
            }

            bool restorePending = SimpleCloudFiles.RefreshPendingState();
            if (restorePending)
            {
                ReturnToWelcome(
                    SimpleCloudFiles.StartupError ??
                    "A pending cloud restore must be verified before play.");
                return;
            }

            if (!router.HasConfirmedCurrentRunDecision)
            {
                ReturnToWelcome(
                    "Choose Guest Play or verify Google Sign-In before continuing.");
                return;
            }

            PrepareForSceneTransition();
            transitionInProgress = true;
            HideRetry();
            SetStatus(
                "Opening your cafe",
                "Loading your local save and preparing startup services...");
            if (!router.RequestMainBakeryFromLoading())
            {
                transitionInProgress = false;
                RestoreLoadingEventSystem();
                ShowError(
                    router.RouteErrorMessage ??
                    "MainBakery could not be loaded. Retry startup.");
            }
        }

        private void PrepareForSceneTransition()
        {
            if (loadingCanvas != null &&
                LoadingPresenterPolicy.ShouldPersistPresenter(
                    IsDevelopmentPlayer,
                    Application.isEditor,
                    SceneManager.GetActiveScene().name ==
                        DevelopmentStartupSceneRouter.LoadingSceneName,
                    transitioningToMainBakery: true))
            {
                if (loadingCanvas.transform.parent != null)
                    loadingCanvas.transform.SetParent(null, true);
                DontDestroyOnLoad(loadingCanvas.gameObject);
            }

            if (loadingEventSystem != null)
            {
                if (loadingEventSystem.transform.parent != null)
                    loadingEventSystem.transform.SetParent(null, true);
                DontDestroyOnLoad(loadingEventSystem.gameObject);
                SetEventSystemEnabled(loadingEventSystem, false);
            }
        }

        private void RefreshMainBakeryReadiness()
        {
            if (SimpleCloudFiles.StartupRestorePending ||
                SimpleCloudFiles.RestorePending)
            {
                ReturnToWelcome(
                    SimpleCloudFiles.StartupError ??
                    "A cloud restore is pending. Verify its Google account to continue.");
                return;
            }

            DevelopmentStartupSceneRouter router =
                DevelopmentStartupSceneRouter.Instance;
            if (router == null ||
                !router.HasConfirmedCurrentRunDecision)
            {
                ReturnToWelcome(
                    "The current play-mode selection could not be verified.");
                return;
            }

            if (router.TryGetCurrentRunDecision(
                    out StartupPlayMode playMode,
                    out bool googleIdentityVerified) &&
                playMode == StartupPlayMode.Google &&
                !IsCurrentGoogleIdentityVerified(googleIdentityVerified))
            {
                ReturnToWelcome(
                    "Google identity verification is no longer available. " +
                    "Sign in again before continuing.");
                return;
            }

            bool unresolvedError = GetStartupError(out string errorMessage);

            if (SimpleCloudBackup.Instance != null &&
                SimpleCloudBackup.Instance.FreshInstallChoicePending)
            {
                mainBakeryWaitStartedAt = Time.realtimeSinceStartup;
                SetStatus("Cloud progress", "Choose how you would like to continue.");
                HideRetry();
                return;
            }

            bool saveStartupSucceeded =
                gameStartup != null &&
                gameStartup.IsStartupComplete &&
                !gameStartup.IsStartupBlocked &&
                (gameStartup.Status == GameStartupCoordinator.StartupStatus
                    .Loaded ||
                 gameStartup.Status == GameStartupCoordinator.StartupStatus
                    .NewGame);
            bool decisionConfirmed =
                router.HasConfirmedCurrentRunDecision &&
                gameStartup != null &&
                gameStartup.StartupDecisionConfirmed;
            bool canBeginGameplay =
                readiness != null && readiness.CanBeginGameplay;

            if (LoadingPresenterPolicy.CanDismiss(
                    canBeginGameplay,
                    saveStartupSucceeded,
                    decisionConfirmed,
                    SimpleCloudFiles.StartupRestorePending,
                    unresolvedError))
            {
                DismissForGameplay();
                return;
            }

            bool startupFailed =
                (gameStartup != null && gameStartup.IsStartupBlocked) ||
                (readiness != null &&
                 readiness.State ==
                    ApplicationReadinessState.RecoverableError);
            bool dependencyFailure = !string.IsNullOrEmpty(
                StartupFlowIntegrationOwner.DependencyFailureMessage);
            if (LoadingPresenterPolicy.ShouldOfferRetry(
                    timedOut,
                    startupFailed,
                    dependencyFailure))
            {
                ShowError(errorMessage ??
                    "Startup needs attention. Your save remains protected.");
                return;
            }

            if (Time.realtimeSinceStartup - mainBakeryWaitStartedAt >=
                StartupTimeoutSeconds)
            {
                timedOut = true;
                ShowError(
                    "Startup is taking longer than expected. Your save remains protected; retry to check again.");
                return;
            }

            SetStatus(
                "Preparing your cafe",
                GetIndeterminateStatus());
            HideRetry();
        }

        private static bool IsCurrentGoogleIdentityVerified(
            bool decisionVerified)
        {
            if (!decisionVerified ||
                GooglePlayGamesAuthenticationCoordinator.Instance == null ||
                GooglePlayGamesAuthenticationCoordinator.Instance
                    .SessionStatus != GooglePlayGamesSessionStatus
                        .GooglePlayGamesConnected)
                return false;

            try
            {
                return !string.IsNullOrEmpty(
                    SimpleCloudBackup.GetVerifiedCurrentOwnerId());
            }
            catch (Exception exception)
            {
                Debug.LogWarning(
                    "STARTUP LOADING | Google identity could not be checked.\n" +
                    exception);
                return false;
            }
        }

        private bool GetStartupError(out string message)
        {
            message = StartupFlowIntegrationOwner.DependencyFailureMessage;
            if (!string.IsNullOrEmpty(message))
                return true;

            if (!string.IsNullOrEmpty(SimpleCloudFiles.StartupError))
            {
                message = SimpleCloudFiles.StartupError;
                return true;
            }

            if (gameStartup != null && gameStartup.IsStartupBlocked)
            {
                message = gameStartup.LastFailureReason ??
                    "Save startup failed. Saving remains disabled.";
                return true;
            }

            if (readiness != null &&
                readiness.State == ApplicationReadinessState.RecoverableError)
            {
                message = readiness.ErrorMessage ??
                    "Startup needs attention. Your save remains protected.";
                return true;
            }

            message = null;
            return false;
        }

        private string GetIndeterminateStatus()
        {
            if (gameStartup == null)
                return "Waiting for local startup services...";

            switch (gameStartup.Status)
            {
                case GameStartupCoordinator.StartupStatus.Waiting:
                    return "Waiting for the confirmed play-mode selection...";
                case GameStartupCoordinator.StartupStatus.Loading:
                    return "Verifying and loading your Save V2 data...";
                case GameStartupCoordinator.StartupStatus.NewGame:
                case GameStartupCoordinator.StartupStatus.Loaded:
                    if (readiness == null)
                        return "Waiting for application readiness services...";

                    switch (readiness.State)
                    {
                        case ApplicationReadinessState.TutorialProgressRequired:
                            return "Recovering your tutorial progress...";
                        case ApplicationReadinessState.GameplayRestoring:
                            return "Verifying your local game session...";
                        case ApplicationReadinessState.RecoverableError:
                            return readiness.ErrorMessage ??
                                "Startup needs attention.";
                        default:
                            return "Preparing your cafe profile and tutorial...";
                    }
                case GameStartupCoordinator.StartupStatus.Failed:
                    return gameStartup.LastFailureReason ??
                        "Save startup failed.";
                default:
                    return "Preparing local startup...";
            }
        }

        private void BindReadinessSources()
        {
            ApplicationReadinessCoordinator currentReadiness =
                ApplicationReadinessCoordinator.Instance;
            if (!ReferenceEquals(readiness, currentReadiness))
            {
                if (readiness != null)
                    readiness.StateChanged -= HandleReadinessChanged;
                readiness = currentReadiness;
                if (readiness != null)
                    readiness.StateChanged += HandleReadinessChanged;
            }

            GameStartupCoordinator currentGameStartup =
                GameStartupCoordinator.Instance;
            if (!ReferenceEquals(gameStartup, currentGameStartup))
            {
                if (gameStartup != null)
                    gameStartup.StateChanged -= HandleGameStartupChanged;
                gameStartup = currentGameStartup;
                if (gameStartup != null)
                    gameStartup.StateChanged += HandleGameStartupChanged;
            }
        }

        private void HandleReadinessChanged(ApplicationReadinessState state)
        {
            if (mainBakeryActive)
                RefreshMainBakeryReadiness();
        }

        private void HandleGameStartupChanged()
        {
            if (mainBakeryActive)
                RefreshMainBakeryReadiness();
        }

        private void UnsubscribeReadinessSources()
        {
            if (readiness != null)
                readiness.StateChanged -= HandleReadinessChanged;
            if (gameStartup != null)
                gameStartup.StateChanged -= HandleGameStartupChanged;
            readiness = null;
            gameStartup = null;
        }

        private void RetryStartup()
        {
            if (!mainBakeryActive)
            {
                DevelopmentStartupSceneRouter router =
                    DevelopmentStartupSceneRouter.Instance;
                PrepareForSceneTransition();
                transitionInProgress = true;
                if (router == null ||
                    !router.RetryMainBakeryFromLoading())
                {
                    transitionInProgress = false;
                    RestoreLoadingEventSystem();
                    ShowError(
                        router != null && !string.IsNullOrEmpty(
                            router.RouteErrorMessage)
                            ? router.RouteErrorMessage
                            : "MainBakery could not be loaded. Retry startup.");
                    return;
                }

                return;
            }

            timedOut = false;
            mainBakeryWaitStartedAt = Time.realtimeSinceStartup;
            ApplicationReadinessCoordinator.EnsureRuntimeOwner();
            BindReadinessSources();
            StartupFlowIntegrationOwner.ConfirmCurrentRunDecision();

            if (readiness != null)
                readiness.Retry();
            else if (gameStartup != null)
                gameStartup.RetryStartup();

            RefreshMainBakeryReadiness();
        }

        private void ReturnToWelcome(string message)
        {
            DevelopmentStartupSceneRouter router =
                DevelopmentStartupSceneRouter.Instance;
            if (router == null)
            {
                ShowError(message);
                return;
            }

            PrepareForSceneTransition();
            transitionInProgress = true;
            bool requested =
                SceneManager.GetActiveScene().name ==
                    DevelopmentStartupSceneRouter.LoadingSceneName
                    ? router.RequestWelcomeFromLoading(message)
                    : router.RequestWelcomeFromMainBakery(message);
            if (!requested)
            {
                transitionInProgress = false;
                RestoreLoadingEventSystem();
                ShowError(message);
            }
        }

        private void PrepareEventSystemForMainScene(Scene scene)
        {
            mainBakeryEventSystems = GetEventSystems(scene);
            foreach (EventSystem eventSystem in mainBakeryEventSystems)
                SetEventSystemEnabled(eventSystem, false);
            if (loadingEventSystem != null)
                SetEventSystemEnabled(loadingEventSystem, true);
        }

        private void TakeEventSystemOwnership(Scene scene)
        {
            PrepareEventSystemForMainScene(scene);
            if (loadingEventSystem == null)
                EnsureLoadingEventSystem();
            if (loadingEventSystem != null)
                SetEventSystemEnabled(loadingEventSystem, true);
        }

        private void ReleaseEventSystemForScene(Scene scene)
        {
            EventSystem[] destinationSystems = GetEventSystems(scene);
            EventSystem chosen = null;
            foreach (EventSystem eventSystem in destinationSystems)
            {
                if (eventSystem == null)
                    continue;

                if (chosen == null &&
                    eventSystem.GetComponent<BaseInputModule>() != null)
                    chosen = eventSystem;
            }

            if (chosen != null)
            {
                foreach (EventSystem eventSystem in destinationSystems)
                    SetEventSystemEnabled(eventSystem, eventSystem == chosen);
                DestroyLoadingEventSystem();
            }
            else if (loadingEventSystem != null)
            {
                SetEventSystemEnabled(loadingEventSystem, true);
            }
        }

        private void RestoreLoadingEventSystem()
        {
            if (loadingEventSystem != null)
                SetEventSystemEnabled(loadingEventSystem, true);
        }

        private void DismissForGameplay()
        {
            Scene mainScene = SceneManager.GetActiveScene();
            EventSystem mainEventSystem = null;
            foreach (EventSystem eventSystem in mainBakeryEventSystems)
            {
                if (eventSystem != null &&
                    eventSystem.GetComponent<BaseInputModule>() != null)
                {
                    mainEventSystem = eventSystem;
                    break;
                }
            }

            bool useLoadingEventSystem =
                LoadingPresenterPolicy.ShouldUseLoadingEventSystem(
                    mainBakeryLoaded: true,
                    hasMainBakeryEventSystem: mainEventSystem != null);
            if (!useLoadingEventSystem)
            {
                foreach (EventSystem eventSystem in mainBakeryEventSystems)
                    SetEventSystemEnabled(
                        eventSystem,
                        eventSystem == mainEventSystem);
                DestroyLoadingEventSystem();
            }
            else if (loadingEventSystem != null)
            {
                SetEventSystemEnabled(loadingEventSystem, true);
            }
            else
            {
                EnsureLoadingEventSystem();
            }

            if (overlayRoot != null)
                overlayRoot.SetActive(false);
            UnsubscribeReadinessSources();
            mainBakeryActive = false;
            GameObject canvasObject = loadingCanvas != null
                ? loadingCanvas.gameObject
                : gameObject;
            if (canvasObject != null)
                Destroy(canvasObject);
        }

        private void DestroyPresenterCanvas()
        {
            UnsubscribeReadinessSources();
            if (loadingCanvas != null)
                Destroy(loadingCanvas.gameObject);
            else if (gameObject != null)
                Destroy(gameObject);
        }

        private void DestroyLoadingEventSystem()
        {
            if (loadingEventSystem == null)
                return;

            GameObject eventSystemObject = loadingEventSystem.gameObject;
            loadingEventSystem = null;
            Destroy(eventSystemObject);
        }

        private void EnsureLoadingEventSystem()
        {
            EventSystem[] sceneSystems = GetEventSystems(
                SceneManager.GetActiveScene());
            EventSystem selected = null;
            foreach (EventSystem eventSystem in sceneSystems)
            {
                if (eventSystem == null || !eventSystem.isActiveAndEnabled)
                    continue;
                if (selected == null ||
                    eventSystem.gameObject.name == "EventSystem")
                    selected = eventSystem;
            }

            if (selected == null)
            {
                EventSystem[] allSystems = FindObjectsByType<EventSystem>(
                    FindObjectsInactive.Exclude,
                    FindObjectsSortMode.None);
                foreach (EventSystem eventSystem in allSystems)
                {
                    if (eventSystem != null &&
                        eventSystem.isActiveAndEnabled &&
                        (eventSystem.gameObject.scene.name ==
                             "DontDestroyOnLoad" ||
                         eventSystem.gameObject.scene.name ==
                             DevelopmentStartupSceneRouter.LoadingSceneName))
                    {
                        selected = eventSystem;
                        break;
                    }
                }
            }

            if (selected == null)
            {
                var eventSystemObject = new GameObject(
                    "LoadingEventSystem",
                    typeof(EventSystem));
                if (SceneManager.GetActiveScene().IsValid())
                    SceneManager.MoveGameObjectToScene(
                        eventSystemObject,
                        SceneManager.GetActiveScene());
                selected = eventSystemObject.GetComponent<EventSystem>();
                eventSystemObject.AddComponent<
                    UnityEngine.InputSystem.UI.InputSystemUIInputModule>();
            }
            else if (selected.GetComponent<BaseInputModule>() == null)
            {
                selected.gameObject.AddComponent<
                    UnityEngine.InputSystem.UI.InputSystemUIInputModule>();
            }

            BaseInputModule inputModule =
                selected.GetComponent<BaseInputModule>();
            if (inputModule != null)
                inputModule.enabled = true;
            selected.enabled = true;
            loadingEventSystem = selected;
            if (!HasUsableEventSystem(selected))
            {
                ShowError(
                    "A usable EventSystem could not be prepared. Retry startup.");
                return;
            }

            EventSystem[] allLoadedSystems = FindObjectsByType<EventSystem>(
                FindObjectsInactive.Exclude,
                FindObjectsSortMode.None);
            foreach (EventSystem eventSystem in allLoadedSystems)
            {
                if (eventSystem != null && eventSystem != selected)
                    SetEventSystemEnabled(eventSystem, false);
            }
        }

        private static bool HasUsableEventSystem(EventSystem eventSystem)
        {
            if (eventSystem == null)
                return false;

            bool hasEnabledInputModule = false;
            foreach (BaseInputModule module in
                     eventSystem.GetComponents<BaseInputModule>())
            {
                if (module != null && module.isActiveAndEnabled)
                {
                    hasEnabledInputModule = true;
                    break;
                }
            }

            return DevelopmentStartupRoutePolicy.IsEventSystemUsable(
                eventSystem.isActiveAndEnabled,
                hasEnabledInputModule);
        }

        private static void SetEventSystemEnabled(
            EventSystem eventSystem,
            bool enabled)
        {
            if (eventSystem == null)
                return;

            foreach (BaseInputModule module in
                     eventSystem.GetComponents<BaseInputModule>())
                module.enabled = enabled;
            eventSystem.enabled = enabled;
        }

        private static EventSystem[] GetEventSystems(Scene scene)
        {
            if (!scene.IsValid())
                return Array.Empty<EventSystem>();

            EventSystem[] allSystems = FindObjectsByType<EventSystem>(
                FindObjectsInactive.Include,
                FindObjectsSortMode.None);
            var result = new List<EventSystem>();
            foreach (EventSystem eventSystem in allSystems)
            {
                if (eventSystem != null &&
                    eventSystem.gameObject.scene == scene)
                    result.Add(eventSystem);
            }

            return result.ToArray();
        }

        private static Canvas FindLoadingCanvas(Scene scene)
        {
            if (!scene.IsValid())
                return null;

            foreach (GameObject root in scene.GetRootGameObjects())
            {
                foreach (Canvas canvas in
                         root.GetComponentsInChildren<Canvas>(true))
                {
                    if (canvas.name == LoadingCanvasName)
                        return canvas;
                }
            }

            return null;
        }

        private static Canvas CreateFallbackCanvas(Scene scene)
        {
            if (!scene.IsValid() || !scene.isLoaded)
                return null;

            var canvasObject = new GameObject(
                LoadingCanvasName,
                typeof(RectTransform),
                typeof(Canvas),
                typeof(CanvasScaler),
                typeof(GraphicRaycaster));
            SceneManager.MoveGameObjectToScene(canvasObject, scene);
            Canvas canvas = canvasObject.GetComponent<Canvas>();
            canvas.renderMode = RenderMode.ScreenSpaceOverlay;
            CanvasScaler scaler = canvasObject.GetComponent<CanvasScaler>();
            scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
            scaler.referenceResolution = new Vector2(1080f, 1920f);
            return canvas;
        }

        private void BuildInterface()
        {
            overlayRoot = new GameObject(
                "LoadingStartupOverlay",
                typeof(RectTransform),
                typeof(Canvas),
                typeof(GraphicRaycaster),
                typeof(Image));
            overlayRoot.transform.SetParent(transform, false);
            RectTransform rootRect =
                overlayRoot.GetComponent<RectTransform>();
            rootRect.anchorMin = Vector2.zero;
            rootRect.anchorMax = Vector2.one;
            rootRect.offsetMin = Vector2.zero;
            rootRect.offsetMax = Vector2.zero;

            Canvas overlayCanvas = overlayRoot.GetComponent<Canvas>();
            overlayCanvas.overrideSorting = true;
            overlayCanvas.sortingLayerID = loadingCanvas.sortingLayerID;
            overlayCanvas.sortingOrder = short.MaxValue;
            Image backdrop = overlayRoot.GetComponent<Image>();
            backdrop.color = new Color(0.035f, 0.025f, 0.02f, 0.98f);
            backdrop.raycastTarget = true;

            GameObject panel = new GameObject(
                "LoadingPanel",
                typeof(RectTransform),
                typeof(Image));
            panel.transform.SetParent(overlayRoot.transform, false);
            Image panelImage = panel.GetComponent<Image>();
            panelImage.color = new Color(0.18f, 0.12f, 0.08f, 1f);
            RectTransform panelRect = panel.GetComponent<RectTransform>();
            panelRect.anchorMin = new Vector2(0.08f, 0.34f);
            panelRect.anchorMax = new Vector2(0.92f, 0.68f);
            panelRect.offsetMin = Vector2.zero;
            panelRect.offsetMax = Vector2.zero;

            titleText = CreateText(
                panel.transform,
                "Title",
                "Opening your cafe",
                34f,
                new Vector2(0.08f, 0.62f),
                new Vector2(0.92f, 0.92f));
            titleText.fontStyle = FontStyle.Bold;
            statusText = CreateText(
                panel.transform,
                "Status",
                "Preparing local startup services...",
                22f,
                new Vector2(0.08f, 0.20f),
                new Vector2(0.92f, 0.61f));

            retryButton = CreateButton(panel.transform);
            retryButton.onClick.AddListener(RetryStartup);
            retryLabel = retryButton.GetComponentInChildren<Text>();
            retryButton.gameObject.SetActive(false);

            overlayRoot.transform.SetAsLastSibling();
        }

        private static Text CreateText(
            Transform parent,
            string objectName,
            string value,
            float fontSize,
            Vector2 anchorMin,
            Vector2 anchorMax)
        {
            var textObject = new GameObject(
                objectName,
                typeof(RectTransform),
                typeof(Text));
            textObject.transform.SetParent(parent, false);
            RectTransform rect = textObject.GetComponent<RectTransform>();
            rect.anchorMin = anchorMin;
            rect.anchorMax = anchorMax;
            rect.offsetMin = new Vector2(12f, 8f);
            rect.offsetMax = new Vector2(-12f, -8f);
            Text text = textObject.GetComponent<Text>();
            text.font = FindFont();
            text.fontSize = Mathf.RoundToInt(fontSize);
            text.alignment = TextAnchor.MiddleCenter;
            text.color = Color.white;
            text.horizontalOverflow = HorizontalWrapMode.Wrap;
            text.verticalOverflow = VerticalWrapMode.Truncate;
            text.raycastTarget = false;
            text.text = value;
            return text;
        }

        private static Button CreateButton(Transform parent)
        {
            var buttonObject = new GameObject(
                "RetryButton",
                typeof(RectTransform),
                typeof(Image),
                typeof(Button));
            buttonObject.transform.SetParent(parent, false);
            RectTransform rect = buttonObject.GetComponent<RectTransform>();
            rect.anchorMin = new Vector2(0.30f, 0.04f);
            rect.anchorMax = new Vector2(0.70f, 0.18f);
            rect.offsetMin = Vector2.zero;
            rect.offsetMax = Vector2.zero;
            Image image = buttonObject.GetComponent<Image>();
            image.color = new Color(0.85f, 0.55f, 0.2f, 1f);
            Button button = buttonObject.GetComponent<Button>();
            button.targetGraphic = image;

            var labelObject = new GameObject(
                "Label",
                typeof(RectTransform),
                typeof(Text));
            labelObject.transform.SetParent(buttonObject.transform, false);
            RectTransform labelRect = labelObject.GetComponent<RectTransform>();
            labelRect.anchorMin = Vector2.zero;
            labelRect.anchorMax = Vector2.one;
            labelRect.offsetMin = new Vector2(8f, 4f);
            labelRect.offsetMax = new Vector2(-8f, -4f);
            Text label = labelObject.GetComponent<Text>();
            label.font = FindFont();
            label.fontSize = 20;
            label.alignment = TextAnchor.MiddleCenter;
            label.color = new Color(0.12f, 0.07f, 0.03f, 1f);
            label.text = "Retry";
            label.raycastTarget = false;
            return button;
        }

        private static Font FindFont()
        {
            Font font = Resources.GetBuiltinResource<Font>(
                "LegacyRuntime.ttf");
            if (font == null)
                font = Resources.GetBuiltinResource<Font>("Arial.ttf");
            return font;
        }

        private void SetStatus(string title, string message)
        {
            if (titleText == null || statusText == null)
                return;

            titleText.text = title ?? string.Empty;
            statusText.text = message ?? string.Empty;
            if (overlayRoot != null)
                overlayRoot.SetActive(true);
        }

        private void ShowError(string message)
        {
            string error = string.IsNullOrWhiteSpace(message)
                ? "Startup could not continue. Retry when ready."
                : message;
            SetStatus("Startup needs attention", error);
            if (retryButton != null)
            {
                retryButton.gameObject.SetActive(true);
                retryButton.interactable = true;
                if (retryLabel != null)
                    retryLabel.text = "Retry";
            }
        }

        private void HideRetry()
        {
            if (retryButton != null)
                retryButton.gameObject.SetActive(false);
        }
    }
}
