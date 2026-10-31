using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using Unity.Services.Authentication;
using UnityEngine;
using UnityEngine.SceneManagement;
using SweetMerge.Analytics;

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
            public int AccountGeneration;
            public string PlayerId;
        }

        private const int EventBufferCapacity = 8;
        private const int MaxRecoveryAttempts = 3;

        public static HybridTutorialController Instance { get; private set; }

        private TutorialProgressService progressService;
        private OrderManager subscribedOrderManager;
        private TutorialProgressState state =
            TutorialProgressState.Initial();
        private bool accountReady;
        private bool progressOperationInFlight;
        private bool progressLoadInFlight;
        private bool destroyed;
        private bool completionNotified;
        private int accountGeneration;
        private bool sceneTransitionInFlight;
        private bool drainInFlight;
        private bool recoveryExhausted;
        private string recoveryError;
        private bool servicesInitialized;
        private bool servicesInitializationInFlight;
        private TutorialStage? operationTargetStage;
        private readonly Queue<BufferedTutorialEvent> eventBuffer =
            new Queue<BufferedTutorialEvent>();

        public TutorialProgressState State => state;
        public bool IsReady => accountReady;
        public bool HasRecoverableError => recoveryExhausted;
        public string RecoverableError => recoveryError;
        public event Action<TutorialProgressState> StateChanged;
        public event Action RecoveryStateChanged;
        public event Action TutorialCompleted;

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
            _ = InitializeAfterUnityServicesAsync();
        }

        private async Task InitializeAfterUnityServicesAsync()
        {
            if (servicesInitializationInFlight || servicesInitialized)
                return;

            servicesInitializationInFlight = true;
            try
            {
                await UnityServicesInitializer.InitializeAsync();
            }
            catch (Exception exception)
            {
                SetRecoveryState(
                    true,
                    "Tutorial services could not initialize. Retry is available.");
                Debug.LogError(
                    "TUTORIAL | Unity Services initialization failed: " +
                    exception.Message);
                servicesInitializationInFlight = false;
                return;
            }

            if (destroyed)
            {
                servicesInitializationInFlight = false;
                return;
            }

            servicesInitializationInFlight = false;
            SetRecoveryState(false, null);
            servicesInitialized = true;
            progressService.Initialize();

            IAuthenticationService authentication =
                AuthenticationService.Instance;
            authentication.SignedIn += HandleSignedIn;
            authentication.SignedOut += HandleSignedOut;

            GameplayEvents.DessertSpawned += HandleDessertSpawned;
            GameplayEvents.DessertMergeCommitted +=
                HandleDessertMergeCommitted;
            SceneManager.sceneLoaded += HandleSceneLoaded;
            SceneManager.sceneUnloaded += HandleSceneUnloaded;

            BindOrderManager();
            _ = LoadAuthenticatedProgressAsync();
        }

        private void OnDestroy()
        {
            destroyed = true;
            accountGeneration++;

            if (servicesInitialized)
            {
                GameplayEvents.DessertSpawned -= HandleDessertSpawned;
                GameplayEvents.DessertMergeCommitted -=
                    HandleDessertMergeCommitted;
                SceneManager.sceneLoaded -= HandleSceneLoaded;
                SceneManager.sceneUnloaded -= HandleSceneUnloaded;
            }

            UnbindOrderManager();

            if (servicesInitialized)
            {
                IAuthenticationService authentication =
                    AuthenticationService.Instance;
                authentication.SignedIn -= HandleSignedIn;
                authentication.SignedOut -= HandleSignedOut;
            }

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
            if (destroyed || drainInFlight)
                return;

            SetRecoveryState(false, null);
            if (!servicesInitialized)
            {
                _ = InitializeAfterUnityServicesAsync();
                return;
            }

            _ = LoadAuthenticatedProgressAsync();
        }

        private void HandleSignedIn()
        {
            accountGeneration++;
            accountReady = false;
            completionNotified = false;
            ClearBufferedEvents();
            _ = LoadAuthenticatedProgressAsync();
        }

        private void HandleSignedOut()
        {
            accountGeneration++;
            accountReady = false;
            completionNotified = false;
            progressOperationInFlight = false;
            ClearBufferedEvents();
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
            if (!CanAdvance(TutorialStage.Spawn))
            {
                if (!CanBufferDuringOperation(TutorialEventKind.Spawn))
                    return;
            }

            EnqueueAndDrain(TutorialEventKind.Spawn);
        }

        private void HandleDessertMergeCommitted(
            int resultingTier,
            bool isNewHighestTier)
        {
            if (!CanAdvance(TutorialStage.Merge))
            {
                if (!CanBufferDuringOperation(TutorialEventKind.Merge))
                    return;
            }

            EnqueueAndDrain(TutorialEventKind.Merge);
        }

        private void HandleOrderCompleted(CustomerOrder order)
        {
            if (sceneTransitionInFlight ||
                subscribedOrderManager == null ||
                !subscribedOrderManager.isActiveAndEnabled)
                return;

            if (!CanAdvance(TutorialStage.Order))
            {
                if (!CanBufferDuringOperation(TutorialEventKind.Order))
                    return;
            }

            EnqueueAndDrain(TutorialEventKind.Order);
        }

        private async Task LoadAuthenticatedProgressAsync()
        {
            if (destroyed ||
                progressService == null ||
                progressLoadInFlight)
                return;

            IAuthenticationService authentication =
                AuthenticationService.Instance;
            if (!authentication.IsSignedIn ||
                !authentication.IsAuthorized ||
                string.IsNullOrWhiteSpace(authentication.PlayerId))
            {
                accountReady = false;
                return;
            }

            progressLoadInFlight = true;
            int loadGeneration = accountGeneration;
            string playerId = authentication.PlayerId;
            try
            {
                if (!IsCurrentAccount(loadGeneration, playerId))
                    return;

                TutorialProgressResult loaded =
                    await progressService.LoadAsync();
                if (!IsCurrentAccount(loadGeneration, playerId))
                    return;

                if (loaded.Operation != TutorialProgressOperation.Applied)
                {
                    accountReady = false;
                    return;
                }

                if (progressService.State.HasPendingStageUpdate)
                {
                    TutorialProgressResult retried =
                        await progressService.RetryPendingAsync();
                    if (!IsCurrentAccount(loadGeneration, playerId))
                        return;

                    if (retried.Operation !=
                            TutorialProgressOperation.Applied &&
                        retried.Operation !=
                            TutorialProgressOperation.AlreadyAtOrBeyond)
                    {
                        accountReady = false;
                        return;
                    }
                }

                accountReady = IsCurrentAccount(
                        loadGeneration,
                        playerId) &&
                    progressService.State.IsCloudConfirmed;
                if (accountReady)
                    _ = DrainEventsAsync();
            }
            finally
            {
                progressLoadInFlight = false;
            }
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
                       accountReady &&
                       !destroyed)
                {
                    BufferedTutorialEvent bufferedEvent =
                        eventBuffer.Peek();
                    if (!IsCurrentAccount(
                            bufferedEvent.AccountGeneration,
                            bufferedEvent.PlayerId))
                    {
                        eventBuffer.Dequeue();
                        continue;
                    }

                    TutorialStage requiredStage =
                        StageForEvent(bufferedEvent.Kind);
                    if (!CanAdvance(requiredStage))
                    {
                        if (progressOperationInFlight)
                            break;

                        eventBuffer.Dequeue();
                        continue;
                    }

                    eventBuffer.Dequeue();
                    TutorialProgressResult result =
                        await ProcessEventAsync(bufferedEvent);
                    if (result.Operation !=
                            TutorialProgressOperation.Applied &&
                        result.Operation !=
                            TutorialProgressOperation.AlreadyAtOrBeyond)
                    {
                        await RecoverPendingProgressAsync(
                            bufferedEvent);
                    }

                    operationTargetStage = null;
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
            }
        }

        private async Task RecoverPendingProgressAsync(
            BufferedTutorialEvent bufferedEvent)
        {
            int generation = bufferedEvent.AccountGeneration;
            string playerId = bufferedEvent.PlayerId;
            for (int attempt = 0; attempt < MaxRecoveryAttempts; attempt++)
            {
                if (!IsCurrentAccount(generation, playerId))
                    return;

                await Task.Delay(250 * (attempt + 1));
                TutorialProgressResult result =
                    await progressService.RetryPendingAsync();
                if (!IsCurrentAccount(generation, playerId))
                    return;

                if (result.Operation ==
                        TutorialProgressOperation.Applied ||
                    result.Operation ==
                        TutorialProgressOperation.AlreadyAtOrBeyond)
                {
                    accountReady = progressService.State.IsCloudConfirmed;
                    SetRecoveryState(false, null);
                    return;
                }
            }

            SetRecoveryState(
                true,
                "Tutorial progress could not be confirmed. Retry is available.");
            accountReady = false;
            if (!ContainsBufferedEvent(bufferedEvent))
                eventBuffer.Enqueue(bufferedEvent);
        }

        private bool ContainsBufferedEvent(
            BufferedTutorialEvent candidate)
        {
            foreach (BufferedTutorialEvent bufferedEvent in eventBuffer)
            {
                if (ReferenceEquals(bufferedEvent, candidate))
                    return true;
            }

            return false;
        }

        private bool TryBufferEvent(TutorialEventKind kind)
        {
            if (destroyed ||
                sceneTransitionInFlight ||
                !accountReady ||
                state.PlayerId == null)
                return false;

            if (eventBuffer.Count >= EventBufferCapacity)
            {
                SetRecoveryState(
                    true,
                    "Tutorial event buffer is full; retry is required.");
                return false;
            }

            foreach (BufferedTutorialEvent bufferedEvent in eventBuffer)
            {
                if (bufferedEvent.AccountGeneration == accountGeneration &&
                    bufferedEvent.PlayerId == state.PlayerId &&
                    bufferedEvent.Kind == kind)
                    return true;
            }

            eventBuffer.Enqueue(
                new BufferedTutorialEvent
                {
                    Kind = kind,
                    AccountGeneration = accountGeneration,
                    PlayerId = state.PlayerId
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

        private void ClearBufferedEvents()
        {
            eventBuffer.Clear();
            operationTargetStage = null;
            SetRecoveryState(false, null);
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

        private bool CanAdvance(TutorialStage expectedStage)
        {
            return accountReady &&
                !progressOperationInFlight &&
                !destroyed &&
                state.PlayerId != null &&
                !state.IsCompleted &&
                state.Stage == expectedStage;
        }

        private bool IsCurrentAccount(
            int expectedGeneration,
            string expectedPlayerId)
        {
            if (destroyed ||
                expectedGeneration != accountGeneration ||
                string.IsNullOrWhiteSpace(expectedPlayerId))
                return false;

            IAuthenticationService authentication =
                AuthenticationService.Instance;
            return authentication.IsSignedIn &&
                authentication.IsAuthorized &&
                authentication.PlayerId == expectedPlayerId;
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
                subscribedOrderManager.OrderCompleted +=
                    HandleOrderCompleted;
            }
        }

        private void UnbindOrderManager()
        {
            if (subscribedOrderManager == null)
                return;

            subscribedOrderManager.OrderCompleted -=
                HandleOrderCompleted;
            subscribedOrderManager = null;
        }
    }
}
