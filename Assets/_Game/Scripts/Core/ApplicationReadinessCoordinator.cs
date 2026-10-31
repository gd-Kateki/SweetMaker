using System;
using System.Threading.Tasks;
using SweetMerge.Analytics;
using SweetMerge.Authentication;
using SweetMerge.Profile;
using Unity.Services.Authentication;
using UnityEngine;
using UnityEngine.SceneManagement;

public enum ApplicationReadinessState
{
    Initializing,
    AuthenticationRequired,
    Authenticating,
    LoadingCloudProgress,
    Ready,
    RecoverableError
}

public sealed class ApplicationReadinessCoordinator : MonoBehaviour
{
    public static ApplicationReadinessCoordinator Instance { get; private set; }

    public ApplicationReadinessState State { get; private set; } =
        ApplicationReadinessState.Initializing;
    public bool IsReady =>
        State == ApplicationReadinessState.Ready;
    public string ErrorMessage { get; private set; }
    public event Action<ApplicationReadinessState> StateChanged;

    private GooglePlayGamesAuthenticationCoordinator authenticationCoordinator;
    private IAuthenticationService authentication;
    private HybridTutorialController tutorialController;
    private GameStartupCoordinator gameStartup;
    private bool servicesInitialized;
    private bool attemptInFlight;
    private bool subscribed;
    private int attemptGeneration;
    private string playerId;
    private bool destroyed;
    private GameplayModalInputGate.GameplayModalLease gameplayBlockLease;

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
    private static void CreateRuntimeOwner()
    {
        if (Instance != null)
            return;

        GameObject owner = new GameObject(
            nameof(ApplicationReadinessCoordinator));
        owner.AddComponent<ApplicationReadinessCoordinator>();
    }

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this;
        DontDestroyOnLoad(gameObject);
    }

    private void Start()
    {
        UpdateGameplayInputGate();
        _ = StartAttemptAsync();
    }

    public void Retry()
    {
        if (destroyed || attemptInFlight)
            return;

        if (tutorialController != null &&
            tutorialController.HasRecoverableError)
            tutorialController.RetryProgressRecovery();

        _ = StartAttemptAsync();
    }

    private async Task StartAttemptAsync()
    {
        if (destroyed || attemptInFlight)
            return;

        attemptInFlight = true;
        int generation = ++attemptGeneration;
        playerId = null;
        SetState(ApplicationReadinessState.Initializing, null);

        try
        {
            await UnityServicesInitializer.InitializeAsync();
            if (!IsCurrentAttempt(generation))
                return;

            servicesInitialized = true;
            SubscribeToAuthentication();
            authenticationCoordinator =
                GooglePlayGamesAuthenticationCoordinator.Instance;
            authenticationCoordinator.StateChanged -=
                HandleAuthenticationCoordinatorChanged;
            authenticationCoordinator.StateChanged +=
                HandleAuthenticationCoordinatorChanged;

            SetState(ApplicationReadinessState.Authenticating, null);
            GooglePlayGamesAuthenticationResult result =
                await authenticationCoordinator.RestoreSessionAsync();
            if (!IsCurrentAttempt(generation))
                return;

            if (result != GooglePlayGamesAuthenticationResult.SignedIn)
            {
                if (authenticationCoordinator.Failure ==
                    GooglePlayGamesAuthenticationFailure
                        .CachedSessionUnavailable)
                {
                    SetState(
                        ApplicationReadinessState.AuthenticationRequired,
                        "Authentication is required to continue.");
                }
                else
                {
                    SetState(
                        ApplicationReadinessState.RecoverableError,
                        "Authentication could not be restored.");
                }

                return;
            }

            if (!TryCaptureAuthenticatedAccount(out string signedInPlayerId))
            {
                SetState(
                    ApplicationReadinessState.RecoverableError,
                    "Authentication did not provide a valid account.");
                return;
            }

            playerId = signedInPlayerId;
            SetState(ApplicationReadinessState.LoadingCloudProgress, null);
            SubscribeToReadinessSources();
            EvaluateReadiness(generation);
        }
        catch (Exception exception)
        {
            if (IsCurrentAttempt(generation))
            {
                SetState(
                    ApplicationReadinessState.RecoverableError,
                    "Startup could not be completed: " + exception.Message);
            }
        }
        finally
        {
            if (generation == attemptGeneration)
                attemptInFlight = false;
        }
    }

    private void SubscribeToAuthentication()
    {
        if (!servicesInitialized || authentication != null)
            return;

        authentication = AuthenticationService.Instance;
        authentication.SignedIn += HandleUnityAuthenticationChanged;
        authentication.SignedOut += HandleUnityAuthenticationChanged;
    }

    private void SubscribeToReadinessSources()
    {
        if (subscribed)
            return;

        subscribed = true;
        SceneManager.sceneLoaded += HandleSceneLoaded;
        SubscribeToTutorial();
        SubscribeToGameStartup();
    }

    private void SubscribeToTutorial()
    {
        HybridTutorialController current =
            HybridTutorialController.Instance;
        if (ReferenceEquals(tutorialController, current))
            return;

        if (tutorialController != null)
        {
            tutorialController.StateChanged -= HandleTutorialStateChanged;
            tutorialController.RecoveryStateChanged -=
                HandleTutorialRecoveryStateChanged;
        }

        tutorialController = current;
        if (tutorialController != null)
        {
            tutorialController.StateChanged += HandleTutorialStateChanged;
            tutorialController.RecoveryStateChanged +=
                HandleTutorialRecoveryStateChanged;
        }
    }

    private void SubscribeToGameStartup()
    {
        GameStartupCoordinator current = GameStartupCoordinator.Instance;
        if (ReferenceEquals(gameStartup, current))
            return;

        if (gameStartup != null)
            gameStartup.StateChanged -= HandleGameStartupStateChanged;

        gameStartup = current;
        if (gameStartup != null)
            gameStartup.StateChanged += HandleGameStartupStateChanged;
    }

    private void HandleSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        if (destroyed)
            return;

        UpdateGameplayInputGate();
        SubscribeToTutorial();
        SubscribeToGameStartup();
        EvaluateReadiness(attemptGeneration);
    }

    private void HandleAuthenticationCoordinatorChanged()
    {
        if (destroyed || !servicesInitialized)
            return;

        if (authenticationCoordinator.State !=
            GooglePlayGamesAuthenticationState.SignedIn)
        {
            if (!TryCaptureAuthenticatedAccount(out _))
            {
                SetState(
                    ApplicationReadinessState.AuthenticationRequired,
                    "Authentication is required to continue.");
            }
            else
            {
                RevokeReadiness(
                    "Google Play Games authentication is no longer verified.");
            }
            return;
        }

        EvaluateReadiness(attemptGeneration);
    }

    private void HandleUnityAuthenticationChanged()
    {
        if (destroyed)
            return;

        if (!TryCaptureAuthenticatedAccount(out string currentPlayerId) ||
            (!string.IsNullOrEmpty(playerId) &&
             playerId != currentPlayerId))
        {
            playerId = null;
            SetState(
                ApplicationReadinessState.AuthenticationRequired,
                "Authentication is required to continue.");
            return;
        }

        playerId = currentPlayerId;
        EvaluateReadiness(attemptGeneration);
    }

    private void HandleTutorialStateChanged(TutorialProgressState nextState)
    {
        EvaluateReadiness(attemptGeneration);
    }

    private void HandleTutorialRecoveryStateChanged()
    {
        EvaluateReadiness(attemptGeneration);
    }

    private void HandleGameStartupStateChanged()
    {
        EvaluateReadiness(attemptGeneration);
    }

    private void EvaluateReadiness(int generation)
    {
        if (destroyed || generation != attemptGeneration)
            return;

        SubscribeToTutorial();
        SubscribeToGameStartup();

        if (!TryCaptureAuthenticatedAccount(out string currentPlayerId) ||
            string.IsNullOrWhiteSpace(playerId) ||
            playerId != currentPlayerId)
        {
            RevokeReadiness("Authentication is no longer verified.");
            return;
        }

        if (authenticationCoordinator == null ||
            authenticationCoordinator.State !=
                GooglePlayGamesAuthenticationState.SignedIn)
        {
            RevokeReadiness("Authentication is no longer verified.");
            return;
        }

        playerId = currentPlayerId;
        if (tutorialController != null &&
            tutorialController.HasRecoverableError)
        {
            SetState(
                ApplicationReadinessState.RecoverableError,
                "Tutorial progress could not be loaded.");
            return;
        }

        if (tutorialController == null ||
            !tutorialController.IsReady ||
            tutorialController.State.PlayerId != playerId)
        {
            SetState(ApplicationReadinessState.LoadingCloudProgress, null);
            return;
        }

        if (gameStartup == null || !gameStartup.IsStartupComplete)
        {
            SetState(ApplicationReadinessState.LoadingCloudProgress, null);
            return;
        }

        SetState(ApplicationReadinessState.Ready, null);
    }

    private bool TryCaptureAuthenticatedAccount(out string currentPlayerId)
    {
        currentPlayerId = null;
        if (!servicesInitialized || authentication == null ||
            !authentication.IsSignedIn ||
            !authentication.IsAuthorized ||
            string.IsNullOrWhiteSpace(authentication.PlayerId))
            return false;

        currentPlayerId = authentication.PlayerId;
        return true;
    }

    private void RevokeReadiness(string message)
    {
        if (State == ApplicationReadinessState.Initializing ||
            State == ApplicationReadinessState.AuthenticationRequired ||
            State == ApplicationReadinessState.Authenticating)
            return;

        SetState(ApplicationReadinessState.RecoverableError, message);
    }

    private bool IsCurrentAttempt(int generation)
    {
        return !destroyed && generation == attemptGeneration;
    }

    private void SetState(
        ApplicationReadinessState nextState,
        string errorMessage)
    {
        bool changed = State != nextState ||
            ErrorMessage != errorMessage;
        State = nextState;
        ErrorMessage = errorMessage;
        UpdateGameplayInputGate();
        if (changed && !destroyed)
            StateChanged?.Invoke(State);
    }

    private void UpdateGameplayInputGate()
    {
        if (destroyed)
            return;

        bool inGameplayScene =
            SceneManager.GetActiveScene().name ==
            SceneNavigationManager.MergeGameplayScene;
        bool shouldBlock = inGameplayScene && !IsReady;
        if (shouldBlock)
        {
            if (gameplayBlockLease == null ||
                !gameplayBlockLease.IsActive)
            {
                GameplayModalInputGate.TryAcquireBlockingModal(
                    this,
                    out gameplayBlockLease);
            }
        }
        else if (gameplayBlockLease != null)
        {
            gameplayBlockLease.Dispose();
            gameplayBlockLease = null;
        }
    }

    private void OnDestroy()
    {
        destroyed = true;
        attemptGeneration++;
        SceneManager.sceneLoaded -= HandleSceneLoaded;
        if (gameplayBlockLease != null)
            gameplayBlockLease.Dispose();
        Unsubscribe();
        if (Instance == this)
            Instance = null;
    }

    private void Unsubscribe()
    {
        if (authentication != null)
        {
            authentication.SignedIn -= HandleUnityAuthenticationChanged;
            authentication.SignedOut -= HandleUnityAuthenticationChanged;
            authentication = null;
        }

        if (authenticationCoordinator != null)
        {
            authenticationCoordinator.StateChanged -=
                HandleAuthenticationCoordinatorChanged;
            authenticationCoordinator = null;
        }

        if (tutorialController != null)
        {
            tutorialController.StateChanged -= HandleTutorialStateChanged;
            tutorialController.RecoveryStateChanged -=
                HandleTutorialRecoveryStateChanged;
        }
        if (gameStartup != null)
            gameStartup.StateChanged -= HandleGameStartupStateChanged;

        tutorialController = null;
        gameStartup = null;
        subscribed = false;
    }
}
