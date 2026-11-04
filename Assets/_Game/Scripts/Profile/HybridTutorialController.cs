using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace SweetMerge.Profile
{
    public sealed class HybridTutorialController : MonoBehaviour
    {
        private enum TutorialEventKind
        {
            WelcomeDismissed,
            Spawn,
            Merge,
            Order
        }

        private sealed class BufferedTutorialEvent
        {
            public TutorialEventKind Kind;
        }

        private const int EventBufferCapacity = 8;

        public static HybridTutorialController Instance { get; private set; }

        private TutorialProgressService progressService;
        private OrderManager subscribedOrderManager;
        private TutorialProgressState state =
            TutorialProgressState.Initial();
        private bool localReady;
        private bool progressOperationInFlight;
        private bool progressLoadInFlight;
        private bool destroyed;
        private bool initializationStarted;
        private bool gameplayEventsSubscribed;
        private bool completionNotified;
        private bool sceneTransitionInFlight;
        private bool drainInFlight;
        private bool recoveryExhausted;
        private string recoveryError;
        private TutorialStage? operationTargetStage;
        private readonly Queue<BufferedTutorialEvent> eventBuffer =
            new Queue<BufferedTutorialEvent>();

        public TutorialProgressState State => state;
        public bool IsReady => localReady;
        public bool HasRecoverableError => recoveryExhausted;
        public string RecoverableError => recoveryError;
        public event Action<TutorialProgressState> StateChanged;
        public event Action RecoveryStateChanged;
        public event Action ReadinessChanged;
        public event Action TutorialCompleted;
        public event Action TutorialOrderCompletionPersisted;

        [RuntimeInitializeOnLoadMethod(
            RuntimeInitializeLoadType.BeforeSceneLoad)]
        private static void CreateRuntimeOwner()
        {
            if (Instance != null)
                return;

            GameObject owner = new GameObject(
                nameof(HybridTutorialController));
            owner.AddComponent<HybridTutorialController>();
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

            progressService = new TutorialProgressService();
            progressService.StateChanged += HandleProgressStateChanged;
        }

        private void Start()
        {
            SweetMerge.Cloud.SimpleCloudFiles.RestorePendingChanged +=
                HandleRestorePendingChanged;
            if (SweetMerge.Cloud.SimpleCloudFiles.RestorePending)
                return;

            BeginLocalInitialization();
        }

        private void BeginLocalInitialization()
        {
            if (destroyed ||
                SweetMerge.Cloud.SimpleCloudFiles.RestorePending ||
                SweetMerge.Cloud.SimpleCloudFiles.StartupError != null)
                return;

            initializationStarted = true;
            GameplayEvents.DessertSpawned += HandleDessertSpawned;
            GameplayEvents.DessertMergeCommitted +=
                HandleDessertMergeCommitted;
            gameplayEventsSubscribed = true;
            SceneManager.sceneLoaded += HandleSceneLoaded;
            SceneManager.sceneUnloaded += HandleSceneUnloaded;
            BindOrderManager();
            _ = LoadLocalProgressAsync();
        }

        private void HandleRestorePendingChanged(bool restorePending)
        {
            if (destroyed)
                return;

            if (restorePending)
            {
                if (gameplayEventsSubscribed)
                {
                    GameplayEvents.DessertSpawned -=
                        HandleDessertSpawned;
                    GameplayEvents.DessertMergeCommitted -=
                        HandleDessertMergeCommitted;
                    gameplayEventsSubscribed = false;
                }

                UnbindOrderManager();
                eventBuffer.Clear();
                state = TutorialProgressState.Initial();
                SetLocalReady(false);
                return;
            }

            if (!initializationStarted)
            {
                BeginLocalInitialization();
                return;
            }

            GameplayEvents.DessertSpawned += HandleDessertSpawned;
            GameplayEvents.DessertMergeCommitted +=
                HandleDessertMergeCommitted;
            gameplayEventsSubscribed = true;
            BindOrderManager();
            _ = LoadLocalProgressAsync();
        }

        private void OnDestroy()
        {
            destroyed = true;
            SweetMerge.Cloud.SimpleCloudFiles.RestorePendingChanged -=
                HandleRestorePendingChanged;
            if (gameplayEventsSubscribed)
            {
                GameplayEvents.DessertSpawned -= HandleDessertSpawned;
                GameplayEvents.DessertMergeCommitted -=
                    HandleDessertMergeCommitted;
                gameplayEventsSubscribed = false;
            }
            SceneManager.sceneLoaded -= HandleSceneLoaded;
            SceneManager.sceneUnloaded -= HandleSceneUnloaded;
            UnbindOrderManager();

            if (progressService != null)
            {
                progressService.StateChanged -=
                    HandleProgressStateChanged;
                progressService.Dispose();
                progressService = null;
            }

            if (Instance == this)
                Instance = null;
        }

        public void DismissWelcome()
        {
            if (!CanAdvance(TutorialStage.Welcome))
                return;

            EnqueueAndDrain(TutorialEventKind.WelcomeDismissed);
        }

        public void RetryProgressRecovery()
        {
            if (destroyed ||
                SweetMerge.Cloud.SimpleCloudFiles.RestorePending ||
                progressLoadInFlight ||
                drainInFlight)
                return;

            SetRecoveryState(false, null);
            _ = LoadLocalProgressAsync();
        }

        private async Task LoadLocalProgressAsync()
        {
            if (destroyed ||
                progressService == null ||
                SweetMerge.Cloud.SimpleCloudFiles.RestorePending ||
                progressLoadInFlight)
                return;

            progressLoadInFlight = true;
            SetLocalReady(false);
            try
            {
                progressService.Initialize();
                TutorialProgressResult loaded =
                    await progressService.LoadAsync();
                if (destroyed ||
                    SweetMerge.Cloud.SimpleCloudFiles.RestorePending)
                {
                    SetLocalReady(false);
                    return;
                }

                if (loaded.Operation != TutorialProgressOperation.Applied ||
                    !loaded.State.IsLocallyValidated)
                {
                    string message = loaded.State.ErrorMessage ??
                        "Local tutorial progress could not be verified. Files were preserved.";
                    SetRecoveryState(true, message);
                    SetLocalReady(false);
                    return;
                }

                SetRecoveryState(false, null);
                SetLocalReady(true);
            }
            catch (Exception exception)
            {
                if (destroyed ||
                    SweetMerge.Cloud.SimpleCloudFiles.RestorePending)
                {
                    SetLocalReady(false);
                    return;
                }

                SetRecoveryState(
                    true,
                    "Local tutorial progress could not be loaded: " +
                    exception.Message);
                SetLocalReady(false);
                Debug.LogError(
                    "TUTORIAL | Local progress load failed: " +
                    exception);
            }
            finally
            {
                progressLoadInFlight = false;
            }

            if (localReady)
                _ = DrainEventsAsync();
        }

        private void HandleSceneLoaded(
            Scene scene,
            LoadSceneMode mode)
        {
            if (destroyed)
                return;

            sceneTransitionInFlight = false;
            BindOrderManager();
        }

        private void HandleSceneUnloaded(Scene scene)
        {
            sceneTransitionInFlight = true;
            UnbindOrderManager();
        }

        private void HandleDessertSpawned(int tier)
        {
            if (!CanAdvance(TutorialStage.Spawn) &&
                !CanBufferDuringOperation(TutorialEventKind.Spawn))
                return;

            EnqueueAndDrain(TutorialEventKind.Spawn);
        }

        private void HandleDessertMergeCommitted(
            int resultingTier,
            bool isNewHighestTier)
        {
            if (!CanAdvance(TutorialStage.Merge) &&
                !CanBufferDuringOperation(TutorialEventKind.Merge))
                return;

            EnqueueAndDrain(TutorialEventKind.Merge);
        }

        private void HandleOrderCompleted(CustomerOrder order)
        {
            if (sceneTransitionInFlight ||
                subscribedOrderManager == null ||
                !subscribedOrderManager.isActiveAndEnabled ||
                state.Stage != TutorialStage.Order ||
                !OrderManager.IsTutorialOrder(order))
                return;

            if (!CanAdvance(TutorialStage.Order) &&
                !CanBufferDuringOperation(TutorialEventKind.Order))
                return;

            EnqueueAndDrain(TutorialEventKind.Order);
        }

        private void EnqueueAndDrain(TutorialEventKind kind)
        {
            if (destroyed || !TryBufferEvent(kind))
                return;

            _ = DrainEventsAsync();
        }

        private async Task DrainEventsAsync()
        {
            if (drainInFlight || destroyed)
                return;

            drainInFlight = true;
            try
            {
                while (eventBuffer.Count > 0 &&
                       localReady &&
                       !destroyed)
                {
                    BufferedTutorialEvent bufferedEvent =
                        eventBuffer.Peek();
                    TutorialStage requiredStage =
                        StageForEvent(bufferedEvent.Kind);

                    if (state.IsCompleted ||
                        (int)requiredStage < (int)state.Stage)
                    {
                        eventBuffer.Dequeue();
                        continue;
                    }

                    if (requiredStage != state.Stage)
                    {
                        eventBuffer.Dequeue();
                        continue;
                    }

                    if (bufferedEvent.Kind == TutorialEventKind.Merge &&
                        (subscribedOrderManager == null ||
                         !OrderManager.IsTutorialOrder(
                             subscribedOrderManager.GetOrderForCustomer(0))))
                    {
                        break;
                    }

                    TutorialProgressResult result =
                        await ProcessEventAsync(bufferedEvent);
                    if (result.Operation ==
                            TutorialProgressOperation.Applied ||
                        result.Operation ==
                            TutorialProgressOperation.AlreadyAtOrBeyond)
                    {
                        if (eventBuffer.Count > 0 &&
                            ReferenceEquals(
                                eventBuffer.Peek(),
                                bufferedEvent))
                            eventBuffer.Dequeue();
                        if (bufferedEvent.Kind == TutorialEventKind.Order &&
                            state.IsCompleted)
                            TutorialOrderCompletionPersisted?.Invoke();
                        continue;
                    }

                    string message = result.State.ErrorMessage ??
                        "Tutorial progress could not be saved. Retry to recover; the gameplay event remains queued.";
                    SetRecoveryState(true, message);
                    SetLocalReady(false);
                    break;
                }
            }
            finally
            {
                drainInFlight = false;
            }
        }

        private async Task<TutorialProgressResult> ProcessEventAsync(
            BufferedTutorialEvent bufferedEvent)
        {
            progressOperationInFlight = true;
            operationTargetStage =
                bufferedEvent.Kind == TutorialEventKind.WelcomeDismissed
                    ? TutorialStage.Spawn
                    : bufferedEvent.Kind == TutorialEventKind.Spawn
                        ? TutorialStage.Merge
                        : bufferedEvent.Kind == TutorialEventKind.Merge
                            ? TutorialStage.Order
                            : TutorialStage.Completed;
            try
            {
                return bufferedEvent.Kind == TutorialEventKind.Order
                    ? await progressService.MarkCompletedAsync()
                    : await progressService.AdvanceToAsync(
                        operationTargetStage.Value);
            }
            finally
            {
                progressOperationInFlight = false;
                operationTargetStage = null;
            }
        }

        private bool TryBufferEvent(TutorialEventKind kind)
        {
            if (destroyed ||
                sceneTransitionInFlight ||
                !localReady ||
                !state.IsLocallyValidated ||
                state.IsCompleted)
                return false;

            foreach (BufferedTutorialEvent bufferedEvent in eventBuffer)
            {
                if (bufferedEvent.Kind == kind)
                    return true;
            }

            if (eventBuffer.Count >= EventBufferCapacity)
            {
                SetRecoveryState(
                    true,
                    "The tutorial event buffer is full. Retry local progress recovery.");
                SetLocalReady(false);
                return false;
            }

            eventBuffer.Enqueue(
                new BufferedTutorialEvent
                {
                    Kind = kind
                });
            return true;
        }

        private bool CanBufferDuringOperation(TutorialEventKind kind)
        {
            return (progressOperationInFlight || drainInFlight) &&
                operationTargetStage.HasValue &&
                StageForEvent(kind) == operationTargetStage.Value;
        }

        private static TutorialStage StageForEvent(
            TutorialEventKind kind)
        {
            return kind == TutorialEventKind.WelcomeDismissed
                ? TutorialStage.Welcome
                : kind == TutorialEventKind.Spawn
                    ? TutorialStage.Spawn
                    : kind == TutorialEventKind.Merge
                        ? TutorialStage.Merge
                        : TutorialStage.Order;
        }

        private void SetLocalReady(bool ready)
        {
            if (localReady == ready)
                return;

            localReady = ready;
            if (!destroyed)
                ReadinessChanged?.Invoke();
        }

        private void SetRecoveryState(
            bool nextExhausted,
            string nextError)
        {
            bool changed = recoveryExhausted != nextExhausted ||
                recoveryError != nextError;
            recoveryExhausted = nextExhausted;
            recoveryError = nextError;
            if (changed && !destroyed)
                RecoveryStateChanged?.Invoke();
        }

        private void HandleOrderGenerated(CustomerOrder order)
        {
            if (destroyed ||
                state.Stage != TutorialStage.Merge ||
                !OrderManager.IsTutorialOrder(order) ||
                subscribedOrderManager == null ||
                !OrderManager.IsTutorialOrder(
                    subscribedOrderManager.GetOrderForCustomer(0)))
                return;

            _ = DrainEventsAsync();
        }

        private bool CanAdvance(TutorialStage expectedStage)
        {
            return localReady &&
                !progressOperationInFlight &&
                !destroyed &&
                state.IsLocallyValidated &&
                !state.IsCompleted &&
                state.Stage == expectedStage;
        }

        private void HandleProgressStateChanged(
            TutorialProgressState nextState)
        {
            if (destroyed)
                return;

            state = nextState;
            StateChanged?.Invoke(state);

            if (state.IsCompleted && !completionNotified)
            {
                completionNotified = true;
                TutorialCompleted?.Invoke();
            }
        }

        private void BindOrderManager()
        {
            OrderManager current =
                FindAnyObjectByType<OrderManager>();
            if (subscribedOrderManager == current)
                return;

            UnbindOrderManager();
            subscribedOrderManager = current;
            if (subscribedOrderManager != null)
            {
                subscribedOrderManager.OrderCompleted -=
                    HandleOrderCompleted;
                subscribedOrderManager.OrderCompleted +=
                    HandleOrderCompleted;
                subscribedOrderManager.OrderGenerated -=
                    HandleOrderGenerated;
                subscribedOrderManager.OrderGenerated +=
                    HandleOrderGenerated;
            }
        }

        private void UnbindOrderManager()
        {
            if (subscribedOrderManager == null)
                return;

            subscribedOrderManager.OrderCompleted -=
                HandleOrderCompleted;
            subscribedOrderManager.OrderGenerated -=
                HandleOrderGenerated;
            subscribedOrderManager = null;
        }
    }
}
