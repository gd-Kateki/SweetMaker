using System;
using SweetMerge.Authentication;
using SweetMerge.Cloud;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace SweetMerge.Startup
{
    internal enum DevelopmentStartupRoute
    {
        Welcome,
        Loading
    }

    internal static class DevelopmentStartupRoutePolicy
    {
        internal static DevelopmentStartupRoute ResolveRoute(
            bool restorePending,
            StartupPlayModeLoadStatus selectionStatus,
            StartupPlayMode selectedMode)
        {
            if (restorePending ||
                selectionStatus != StartupPlayModeLoadStatus.Loaded)
                return DevelopmentStartupRoute.Welcome;

            return selectedMode == StartupPlayMode.Guest
                ? DevelopmentStartupRoute.Loading
                : DevelopmentStartupRoute.Welcome;
        }

        internal static bool CanRequestMainBakery(
            bool developmentBuild,
            bool editor,
            bool restorePending,
            string activeSceneName,
            bool decisionConfirmed,
            StartupPlayMode playMode,
            bool googleIdentityVerified,
            bool loadPending)
        {
            if (!ShouldRun(developmentBuild, editor) ||
                restorePending ||
                activeSceneName != DevelopmentStartupSceneRouter.LoadingSceneName ||
                !decisionConfirmed ||
                loadPending)
                return false;

            return playMode == StartupPlayMode.Guest
                ? !googleIdentityVerified
                : playMode == StartupPlayMode.Google &&
                  googleIdentityVerified;
        }

        internal static bool ShouldBeginMainBakeryRequest(
            bool requestAlreadyAccepted,
            bool sceneLoadPending)
        {
            return !requestAlreadyAccepted && !sceneLoadPending;
        }

        internal static bool CanDismissLoading(
            bool canBeginGameplay,
            bool saveStartupSucceeded,
            bool decisionConfirmed,
            bool restorePending,
            bool startupErrorUnresolved)
        {
            return canBeginGameplay &&
                   saveStartupSucceeded &&
                   decisionConfirmed &&
                   !restorePending &&
                   !startupErrorUnresolved;
        }

        internal static bool ShouldSuppressLegacyLoadingOverlay(
            bool developmentBuild,
            bool editor,
            bool presenterActive)
        {
            return ShouldRun(developmentBuild, editor) && presenterActive;
        }

        internal static bool IsEventSystemUsable(
            bool eventSystemEnabled,
            bool hasEnabledInputModule)
        {
            return eventSystemEnabled && hasEnabledInputModule;
        }

        internal static bool ShouldRun(
            bool developmentBuild,
            bool editor)
        {
            return developmentBuild && !editor;
        }

        internal static bool ShouldRequestSceneLoad(
            string activeSceneName,
            string targetSceneName,
            bool loadPending)
        {
            return !loadPending &&
                   !string.Equals(
                       activeSceneName,
                       targetSceneName,
                       StringComparison.Ordinal);
        }

        internal static bool IsDuplicateOwner(
            bool hasOwner,
            bool isCurrentOwner)
        {
            return hasOwner && !isCurrentOwner;
        }

        internal static bool CanRequestLoadingFromWelcome(
            bool developmentBuild,
            bool editor,
            bool restorePending,
            string activeSceneName,
            StartupPlayMode playMode,
            bool googleIdentityVerified,
            bool loadingAlreadyRequested)
        {
            if (!ShouldRun(developmentBuild, editor) ||
                restorePending ||
                loadingAlreadyRequested ||
                activeSceneName != "Welcome")
                return false;

            return playMode == StartupPlayMode.Guest
                ? !googleIdentityVerified
                : playMode == StartupPlayMode.Google &&
                  googleIdentityVerified;
        }
    }

    public sealed class DevelopmentStartupSceneRouter : MonoBehaviour
    {
        internal const string WelcomeSceneName = "Welcome";
        internal const string LoadingSceneName = "Loading";

#if DEVELOPMENT_BUILD && !UNITY_EDITOR
        private const bool IsDevelopmentPlayer = true;
#else
        private const bool IsDevelopmentPlayer = false;
#endif

        private static DevelopmentStartupSceneRouter instance;
        private AsyncOperation sceneLoadOperation;
        private string pendingSceneName;
        private bool routeEvaluated;
        private bool sceneLoadPending;
        private bool loadingRequested;
        private bool mainBakeryRequested;
        private bool currentRunDecisionConfirmed;
        private StartupPlayMode currentRunPlayMode;
        private bool currentRunGoogleIdentityVerified;

        internal static DevelopmentStartupSceneRouter Instance => instance;

        internal static bool IsRoutingEnabledForThisPlayer =>
            DevelopmentStartupRoutePolicy.ShouldRun(
                IsDevelopmentPlayer,
                Application.isEditor);

        internal DevelopmentStartupRoute? InitialRoute { get; private set; }
        internal string RouteErrorMessage { get; private set; }
        internal bool HasConfirmedCurrentRunDecision =>
            currentRunDecisionConfirmed;

        internal bool TryGetCurrentRunDecision(
            out StartupPlayMode playMode,
            out bool googleIdentityVerified)
        {
            playMode = currentRunPlayMode;
            googleIdentityVerified = currentRunGoogleIdentityVerified;
            return currentRunDecisionConfirmed;
        }

        [RuntimeInitializeOnLoadMethod(
            RuntimeInitializeLoadType.SubsystemRegistration)]
        private static void ResetStaticState()
        {
            instance = null;
        }

        [RuntimeInitializeOnLoadMethod(
            RuntimeInitializeLoadType.BeforeSceneLoad)]
        private static void InstallDevelopmentOwner()
        {
            if (!IsRoutingEnabledForThisPlayer)
                return;

            SimpleCloudFiles.RefreshPendingState();

            if (instance == null)
                instance = FindAnyObjectByType<DevelopmentStartupSceneRouter>();

            if (instance == null)
            {
                var owner = new GameObject(
                    nameof(DevelopmentStartupSceneRouter));
                owner.AddComponent<DevelopmentStartupSceneRouter>();
            }
        }

        private void Awake()
        {
            if (DevelopmentStartupRoutePolicy.IsDuplicateOwner(
                    instance != null,
                    instance == this))
            {
                if (Application.isPlaying)
                    Destroy(gameObject);
                else
                    DestroyImmediate(gameObject);
                return;
            }

            instance = this;
            if (Application.isPlaying)
                DontDestroyOnLoad(gameObject);
            SceneManager.sceneLoaded += HandleSceneLoaded;
        }

        private void Start()
        {
            if (IsRoutingEnabledForThisPlayer)
                RouteFromStoredSelection();
        }

        private void OnDestroy()
        {
            SceneManager.sceneLoaded -= HandleSceneLoaded;
            if (instance == this)
                instance = null;
        }

        private void RouteFromStoredSelection()
        {
            if (routeEvaluated)
                return;

            routeEvaluated = true;
            bool restorePending = SimpleCloudFiles.RefreshPendingState();
            StartupPlayModeLoadStatus selectionStatus =
                new StartupPlayModeStore().Load(
                    out StartupPlayMode selectedMode,
                    out _,
                    out string selectionError);

            InitialRoute = DevelopmentStartupRoutePolicy.ResolveRoute(
                restorePending,
                selectionStatus,
                selectedMode);

            if (!restorePending &&
                selectionStatus == StartupPlayModeLoadStatus.Loaded &&
                selectedMode == StartupPlayMode.Guest)
            {
                ConfirmCurrentRunDecision(
                    StartupPlayMode.Guest,
                    googleIdentityVerified: false);
            }

            if (restorePending)
            {
                RouteErrorMessage = SimpleCloudFiles.StartupError;
            }
            else if (selectionStatus == StartupPlayModeLoadStatus.InvalidData ||
                     selectionStatus == StartupPlayModeLoadStatus.ServiceError)
            {
                RouteErrorMessage = selectionError ??
                    "The saved play-mode selection could not be read.";
            }

            string destination =
                InitialRoute == DevelopmentStartupRoute.Loading
                    ? LoadingSceneName
                    : WelcomeSceneName;
            RequestScene(destination);
        }

        internal bool RequestLoadingFromWelcome(
            StartupPlayMode playMode,
            bool googleIdentityVerified)
        {
            bool restorePending = SimpleCloudFiles.RefreshPendingState();
            if (!DevelopmentStartupRoutePolicy.CanRequestLoadingFromWelcome(
                    IsDevelopmentPlayer,
                    Application.isEditor,
                    restorePending,
                    SceneManager.GetActiveScene().name,
                    playMode,
                    googleIdentityVerified,
                    loadingRequested))
                return false;

            StartupPlayModeLoadStatus selectionStatus =
                new StartupPlayModeStore().Load(
                    out StartupPlayMode selectedMode,
                    out _,
                    out _);
            if (selectionStatus != StartupPlayModeLoadStatus.Loaded ||
                selectedMode != playMode)
                return false;

            if (playMode == StartupPlayMode.Google)
            {
                try
                {
                    if (GooglePlayGamesAuthenticationCoordinator.Instance ==
                            null ||
                        GooglePlayGamesAuthenticationCoordinator.Instance
                            .SessionStatus != GooglePlayGamesSessionStatus
                                .GooglePlayGamesConnected ||
                        string.IsNullOrEmpty(
                            SimpleCloudBackup.GetVerifiedCurrentOwnerId()))
                        return false;
                }
                catch (Exception exception)
                {
                    SetRouteError(
                        "The verified Google identity could not be checked: " +
                        exception.Message);
                    return false;
                }
            }

            ConfirmCurrentRunDecision(playMode, googleIdentityVerified);
            InitialRoute = DevelopmentStartupRoute.Loading;
            loadingRequested = true;
            if (!RequestScene(LoadingSceneName))
            {
                loadingRequested = false;
                return false;
            }

            RouteErrorMessage = null;
            return true;
        }

        internal bool RequestMainBakeryFromLoading()
        {
            if (!DevelopmentStartupRoutePolicy.ShouldBeginMainBakeryRequest(
                    mainBakeryRequested,
                    sceneLoadPending))
                return true;

            bool restorePending = SimpleCloudFiles.RefreshPendingState();
            if (!DevelopmentStartupRoutePolicy.CanRequestMainBakery(
                    IsDevelopmentPlayer,
                    Application.isEditor,
                    restorePending,
                    SceneManager.GetActiveScene().name,
                    currentRunDecisionConfirmed,
                    currentRunPlayMode,
                    currentRunGoogleIdentityVerified,
                    sceneLoadPending))
            {
                string message = restorePending
                    ? SimpleCloudFiles.StartupError ??
                      "A cloud restore must be resolved before opening the cafe."
                    : "A verified current-run play-mode selection is required " +
                      "before opening the cafe.";
                SetRouteError(message);
                return false;
            }

            StartupPlayModeLoadStatus selectionStatus =
                new StartupPlayModeStore().Load(
                    out StartupPlayMode storedMode,
                    out _,
                    out string selectionError);
            if (selectionStatus != StartupPlayModeLoadStatus.Loaded ||
                storedMode != currentRunPlayMode)
            {
                SetRouteError(selectionError ??
                    "The saved play-mode selection could not be verified.");
                return false;
            }

            if (currentRunPlayMode == StartupPlayMode.Google)
            {
                try
                {
                    if (!currentRunGoogleIdentityVerified ||
                        GooglePlayGamesAuthenticationCoordinator.Instance ==
                            null ||
                        GooglePlayGamesAuthenticationCoordinator.Instance
                            .SessionStatus != GooglePlayGamesSessionStatus
                                .GooglePlayGamesConnected ||
                        string.IsNullOrEmpty(
                            SimpleCloudBackup.GetVerifiedCurrentOwnerId()))
                    {
                        SetRouteError(
                            "Google identity is no longer verified. " +
                            "Sign in again before opening the cafe.");
                        return false;
                    }
                }
                catch (Exception exception)
                {
                    SetRouteError(
                        "Google identity could not be reverified: " +
                        exception.Message);
                    return false;
                }
            }

            mainBakeryRequested = true;
            if (!RequestScene(SceneNavigationManager.MainBakeryScene))
            {
                mainBakeryRequested = false;
                return false;
            }

            RouteErrorMessage = null;
            return true;
        }

        internal bool RetryMainBakeryFromLoading()
        {
            if (sceneLoadPending ||
                SceneManager.GetActiveScene().name != LoadingSceneName)
                return false;

            mainBakeryRequested = false;
            RouteErrorMessage = null;
            return RequestMainBakeryFromLoading();
        }

        internal bool RequestWelcomeFromLoading(string errorMessage)
        {
            if (!IsRoutingEnabledForThisPlayer ||
                SceneManager.GetActiveScene().name != LoadingSceneName ||
                sceneLoadPending)
                return false;

            mainBakeryRequested = false;
            currentRunDecisionConfirmed = false;
            RouteErrorMessage = errorMessage;
            InitialRoute = DevelopmentStartupRoute.Welcome;
            return RequestScene(WelcomeSceneName);
        }

        internal bool RequestWelcomeFromMainBakery(string errorMessage)
        {
            if (!IsRoutingEnabledForThisPlayer ||
                SceneManager.GetActiveScene().name !=
                    SceneNavigationManager.MainBakeryScene ||
                sceneLoadPending)
                return false;

            mainBakeryRequested = false;
            currentRunDecisionConfirmed = false;
            RouteErrorMessage = errorMessage;
            InitialRoute = DevelopmentStartupRoute.Welcome;
            return RequestScene(WelcomeSceneName);
        }

        private bool RequestScene(string sceneName)
        {
            if (!DevelopmentStartupRoutePolicy.ShouldRequestSceneLoad(
                    SceneManager.GetActiveScene().name,
                    sceneName,
                    sceneLoadPending))
                return SceneManager.GetActiveScene().name == sceneName;

            if (!Application.CanStreamedLevelBeLoaded(sceneName))
            {
                SetRouteError(
                    "Startup scene '" + sceneName +
                    "' is not available in this Development build.");
                return false;
            }

            try
            {
                sceneLoadOperation = SceneManager.LoadSceneAsync(
                    sceneName,
                    LoadSceneMode.Single);
            }
            catch (ArgumentException exception)
            {
                SetRouteError(
                    "Startup scene '" + sceneName +
                    "' could not be loaded: " + exception.Message);
                return false;
            }
            catch (UnityException exception)
            {
                SetRouteError(
                    "Startup scene '" + sceneName +
                    "' could not be loaded: " + exception.Message);
                return false;
            }

            if (sceneLoadOperation == null)
            {
                SetRouteError(
                    "Startup scene '" + sceneName +
                    "' could not be loaded.");
                return false;
            }

            sceneLoadPending = true;
            pendingSceneName = sceneName;
            sceneLoadOperation.completed += HandleSceneLoadCompleted;
            return true;
        }

        private void HandleSceneLoadCompleted(AsyncOperation operation)
        {
            if (!ReferenceEquals(sceneLoadOperation, operation))
                return;

            sceneLoadOperation = null;
            sceneLoadPending = false;
            string expectedScene = pendingSceneName;
            pendingSceneName = null;
            if (SceneManager.GetActiveScene().name != expectedScene)
            {
                loadingRequested = false;
                mainBakeryRequested = false;
                SetRouteError(
                    "Startup scene '" + expectedScene +
                    "' did not become active.");
            }
        }

        private void HandleSceneLoaded(Scene scene, LoadSceneMode mode)
        {
            if (sceneLoadPending &&
                scene.name == pendingSceneName)
            {
                sceneLoadPending = false;
            }

            if (scene.name == LoadingSceneName)
                loadingRequested = false;
            if (scene.name == SceneNavigationManager.MainBakeryScene)
                mainBakeryRequested = false;
        }

        private void ConfirmCurrentRunDecision(
            StartupPlayMode playMode,
            bool googleIdentityVerified)
        {
            currentRunPlayMode = playMode;
            currentRunGoogleIdentityVerified = googleIdentityVerified;
            currentRunDecisionConfirmed =
                playMode == StartupPlayMode.Guest
                    ? !googleIdentityVerified
                    : playMode == StartupPlayMode.Google &&
                      googleIdentityVerified;
        }

        private void SetRouteError(string message)
        {
            RouteErrorMessage = message;
            Debug.LogError("STARTUP ROUTER | " + message, this);
        }
    }
}
