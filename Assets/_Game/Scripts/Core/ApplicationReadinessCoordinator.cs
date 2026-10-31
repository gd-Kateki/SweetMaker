using System;
using SweetMerge.Profile;
using UnityEngine;
using UnityEngine.SceneManagement;

public enum ApplicationReadinessState
{
    Initializing,
    TutorialProgressRequired,
    GameplayRestoring,
    Ready,
    RecoverableError
}

public sealed class ApplicationReadinessCoordinator : MonoBehaviour
{
    public static ApplicationReadinessCoordinator Instance { get; private set; }

    public ApplicationReadinessState State { get; private set; } =
        ApplicationReadinessState.Initializing;
    public bool IsLocalStartupReady =>
        gameStartup != null && gameStartup.IsStartupComplete;
    public bool CanBeginGameplay =>
        IsLocalStartupReady &&
        !gameStartup.IsStartupBlocked &&
        tutorialController != null &&
        tutorialController.IsReady;
    public bool IsGameplayReady =>
        CanBeginGameplay && gameStartup.IsGameplayReady;
    public bool IsReady => IsGameplayReady;
    public string ErrorMessage { get; private set; }
    public event Action<ApplicationReadinessState> StateChanged;

    private HybridTutorialController tutorialController;
    private GameStartupCoordinator gameStartup;
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
        SceneManager.sceneLoaded += HandleSceneLoaded;
        SubscribeToReadinessSources();
        EvaluateReadiness();
    }

    public void Retry()
    {
        if (destroyed)
            return;

        SubscribeToReadinessSources();
        if (gameStartup != null && gameStartup.IsStartupBlocked)
            gameStartup.RetryStartup();
        else
            tutorialController?.RetryProgressRecovery();

        EvaluateReadiness();
    }

    private void SubscribeToReadinessSources()
    {
        GameStartupCoordinator currentStartup =
            GameStartupCoordinator.Instance;
        if (!ReferenceEquals(gameStartup, currentStartup))
        {
            if (gameStartup != null)
                gameStartup.StateChanged -= HandleGameStartupStateChanged;

            gameStartup = currentStartup;
            if (gameStartup != null)
                gameStartup.StateChanged += HandleGameStartupStateChanged;
        }

        HybridTutorialController currentTutorial =
            HybridTutorialController.Instance;
        if (!ReferenceEquals(tutorialController, currentTutorial))
        {
            if (tutorialController != null)
            {
                tutorialController.StateChanged -=
                    HandleTutorialStateChanged;
                tutorialController.RecoveryStateChanged -=
                    HandleTutorialRecoveryStateChanged;
                tutorialController.ReadinessChanged -=
                    HandleTutorialReadinessChanged;
            }

            tutorialController = currentTutorial;
            if (tutorialController != null)
            {
                tutorialController.StateChanged +=
                    HandleTutorialStateChanged;
                tutorialController.RecoveryStateChanged +=
                    HandleTutorialRecoveryStateChanged;
                tutorialController.ReadinessChanged +=
                    HandleTutorialReadinessChanged;
            }
        }

    }

    private void HandleSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        if (destroyed)
            return;

        SubscribeToReadinessSources();
        EvaluateReadiness();
    }

    private void HandleGameStartupStateChanged()
    {
        EvaluateReadiness();
    }

    private void HandleTutorialStateChanged(TutorialProgressState nextState)
    {
        EvaluateReadiness();
    }

    private void HandleTutorialRecoveryStateChanged()
    {
        EvaluateReadiness();
    }

    private void HandleTutorialReadinessChanged()
    {
        EvaluateReadiness();
    }

    private void EvaluateReadiness()
    {
        if (destroyed)
            return;

        SubscribeToReadinessSources();

        if (gameStartup == null)
        {
            SetState(ApplicationReadinessState.Initializing, null);
            return;
        }

        if (gameStartup.IsStartupBlocked)
        {
            SetState(
                ApplicationReadinessState.RecoverableError,
                gameStartup.LastFailureReason ??
                "Local save startup failed. Your save has not been overwritten.");
            return;
        }

        if (!gameStartup.IsStartupComplete)
        {
            SetState(ApplicationReadinessState.Initializing, null);
            return;
        }

        if (tutorialController == null || !tutorialController.IsReady)
        {
            bool hasTutorialError =
                tutorialController != null &&
                tutorialController.HasRecoverableError;
            SetState(
                hasTutorialError
                    ? ApplicationReadinessState.RecoverableError
                    : ApplicationReadinessState.Initializing,
                hasTutorialError
                    ? tutorialController.RecoverableError
                    : null);
            return;
        }

        if (!gameStartup.IsGameplayReady)
        {
            SetState(
                ApplicationReadinessState.GameplayRestoring,
                "Verifying the local merge session.");
            return;
        }

        SetState(ApplicationReadinessState.Ready, null);
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
        bool shouldBlock = inGameplayScene && !IsGameplayReady;
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
        SceneManager.sceneLoaded -= HandleSceneLoaded;
        if (gameplayBlockLease != null)
            gameplayBlockLease.Dispose();
        Unsubscribe();
        if (Instance == this)
            Instance = null;
    }

    private void Unsubscribe()
    {
        if (tutorialController != null)
        {
            tutorialController.StateChanged -= HandleTutorialStateChanged;
            tutorialController.RecoveryStateChanged -=
                HandleTutorialRecoveryStateChanged;
            tutorialController.ReadinessChanged -=
                HandleTutorialReadinessChanged;
        }

        if (gameStartup != null)
            gameStartup.StateChanged -= HandleGameStartupStateChanged;

        tutorialController = null;
        gameStartup = null;
    }
}
