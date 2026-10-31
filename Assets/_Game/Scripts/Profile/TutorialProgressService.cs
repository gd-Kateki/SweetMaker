using System;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;
using Unity.Services.Authentication;
using Unity.Services.CloudSave;
using Unity.Services.CloudSave.Models;
using Unity.Services.CloudSave.Models.Data.Player;
using Unity.Services.Core;
using SweetMerge.Analytics;

namespace SweetMerge.Profile
{
    public enum TutorialStage
    {
        Welcome,
        Spawn,
        Merge,
        Order,
        Completed
    }

    public enum TutorialProgressStatus
    {
        Unknown,
        Loading,
        Missing,
        Valid,
        PendingWrite,
        InvalidData,
        AuthenticationUnavailable,
        ServiceError
    }

    public sealed class TutorialProgressState
    {
        public TutorialProgressStatus Status { get; }
        public string PlayerId { get; }
        public TutorialStage Stage { get; }
        public TutorialStage CloudConfirmedStage { get; }
        public bool IsCompleted { get; }
        public bool IsCloudConfirmed { get; }
        public bool HasPendingStageUpdate { get; }
        public TutorialStage? PendingStage { get; }
        public string ErrorMessage { get; }

        internal TutorialProgressState(
            TutorialProgressStatus status,
            string playerId,
            TutorialStage stage,
            TutorialStage cloudConfirmedStage,
            bool isCompleted,
            bool isCloudConfirmed,
            bool hasPendingStageUpdate,
            TutorialStage? pendingStage,
            string errorMessage)
        {
            Status = status;
            PlayerId = playerId;
            Stage = stage;
            CloudConfirmedStage = cloudConfirmedStage;
            IsCompleted = isCompleted;
            IsCloudConfirmed = isCloudConfirmed;
            HasPendingStageUpdate = hasPendingStageUpdate;
            PendingStage = pendingStage;
            ErrorMessage = errorMessage;
        }

        public static TutorialProgressState Initial()
        {
            return new TutorialProgressState(
                TutorialProgressStatus.Unknown,
                null,
                TutorialStage.Welcome,
                TutorialStage.Welcome,
                false,
                false,
                false,
                null,
                null);
        }
    }

    public enum TutorialProgressOperation
    {
        Applied,
        AlreadyAtOrBeyond,
        DuplicateRequest,
        Pending,
        InvalidData,
        AuthenticationUnavailable,
        ServiceError
    }

    public sealed class TutorialProgressResult
    {
        public TutorialProgressOperation Operation { get; }
        public TutorialProgressState State { get; }

        internal TutorialProgressResult(
            TutorialProgressOperation operation,
            TutorialProgressState state)
        {
            Operation = operation;
            State = state;
        }
    }

    public sealed class TutorialProgressService : IDisposable
    {
        public const string StageKey = "cafeTutorialStage";
        public const string CompletionKey = "cafeTutorialCompleted";

        private readonly SemaphoreSlim operationGate = new SemaphoreSlim(1, 1);
        private TutorialProgressState state =
            TutorialProgressState.Initial();
        private string activePlayerId;
        private string stageWriteLock;
        private string completionWriteLock;
        private TutorialStage? pendingStage;
        private int requestGeneration;
        private bool initialized;
        private bool disposed;
        private const int MaxCloudSaveAttempts = 2;

        public TutorialProgressState State => state;

        public event Action<TutorialProgressState> StateChanged;

        /// <summary>
        /// Subscribes to Unity Authentication account changes. The owner must
        /// call LoadAsync after initialization, then RetryPendingAsync when a
        /// pending journal is reported.
        /// </summary>
        public void Initialize()
        {
            ThrowIfDisposed();
            if (initialized)
                return;

            IAuthenticationService authentication =
                AuthenticationService.Instance;
            authentication.SignedIn += HandleSignedIn;
            authentication.SignedOut += HandleSignedOut;
            initialized = true;
            RefreshAuthenticationContext();
        }

        /// <summary>
        /// Loads both tutorial keys from Default Player Data.
        /// </summary>
        public async Task<TutorialProgressResult> LoadAsync()
        {
            ThrowIfDisposed();
            Initialize();

            if (!await operationGate.WaitAsync(0))
                return Result(TutorialProgressOperation.DuplicateRequest);

            try
            {
                return await LoadCoreAsync();
            }
            finally
            {
                operationGate.Release();
            }
        }

        /// <summary>
        /// Persists a non-completed stage if it advances the verified state.
        /// </summary>
        public async Task<TutorialProgressResult> AdvanceToAsync(
            TutorialStage requestedStage)
        {
            ThrowIfDisposed();
            Initialize();

            if (requestedStage == TutorialStage.Completed)
                return await MarkCompletedAsync();

            if (!await operationGate.WaitAsync(0))
                return Result(TutorialProgressOperation.DuplicateRequest);

            try
            {
                TutorialProgressResult loaded = await EnsureLoadedCoreAsync();
                if (loaded != null)
                    return loaded;

                if (state.IsCompleted ||
                    requestedStage <= state.Stage)
                {
                    return Result(
                        TutorialProgressOperation.AlreadyAtOrBeyond);
                }

                if (!IsCurrentPlayer(activePlayerId))
                    return AuthenticationUnavailableResult();

                return await PersistStageCoreAsync(requestedStage);
            }
            finally
            {
                operationGate.Release();
            }
        }

        /// <summary>
        /// Persists the Completed stage and completion flag, then rereads both.
        /// </summary>
        public async Task<TutorialProgressResult> MarkCompletedAsync()
        {
            ThrowIfDisposed();
            Initialize();

            if (!await operationGate.WaitAsync(0))
                return Result(TutorialProgressOperation.DuplicateRequest);

            try
            {
                TutorialProgressResult loaded = await EnsureLoadedCoreAsync();
                if (loaded != null)
                    return loaded;

                if (state.IsCompleted)
                    return Result(
                        TutorialProgressOperation.AlreadyAtOrBeyond);

                if (!IsCurrentPlayer(activePlayerId))
                    return AuthenticationUnavailableResult();

                return await PersistCompletionCoreAsync();
            }
            finally
            {
                operationGate.Release();
            }
        }

        /// <summary>
        /// Reconciles a pending stage or completion write by rereading, then
        /// retries if needed.
        /// </summary>
        public async Task<TutorialProgressResult> RetryPendingAsync()
        {
            ThrowIfDisposed();
            Initialize();

            if (!await operationGate.WaitAsync(0))
                return Result(TutorialProgressOperation.DuplicateRequest);

            try
            {
                if (!pendingStage.HasValue)
                    return Result(
                        TutorialProgressOperation.AlreadyAtOrBeyond);

                TutorialStage requestedStage = pendingStage.Value;
                TutorialProgressResult loaded = await LoadCoreAsync();
                if (loaded.Operation == TutorialProgressOperation.InvalidData ||
                    loaded.Operation == TutorialProgressOperation
                        .AuthenticationUnavailable ||
                    loaded.Operation == TutorialProgressOperation.ServiceError)
                {
                    return loaded;
                }

                bool pendingStageIsReconciled =
                    requestedStage == TutorialStage.Completed
                        ? state.IsCompleted
                        : state.IsCompleted ||
                          state.CloudConfirmedStage >= requestedStage;
                if (pendingStageIsReconciled)
                {
                    pendingStage = null;
                    PublishVerifiedState(
                        state.Status,
                        state.Stage,
                        state.IsCompleted,
                        null,
                        state.ErrorMessage);
                    return Result(TutorialProgressOperation.Applied);
                }

                return requestedStage == TutorialStage.Completed
                    ? await PersistCompletionCoreAsync()
                    : await PersistStageCoreAsync(requestedStage);
            }
            finally
            {
                operationGate.Release();
            }
        }

        public void Dispose()
        {
            if (disposed)
                return;

            disposed = true;
            requestGeneration++;
            if (initialized)
            {
                IAuthenticationService authentication =
                    AuthenticationService.Instance;
                authentication.SignedIn -= HandleSignedIn;
                authentication.SignedOut -= HandleSignedOut;
            }

        }

        private async Task<TutorialProgressResult> EnsureLoadedCoreAsync()
        {
            if (!IsCurrentPlayer(activePlayerId) ||
                state.Status == TutorialProgressStatus.Unknown)
            {
                return await LoadCoreAsync();
            }

            if (state.Status == TutorialProgressStatus.InvalidData ||
                state.Status == TutorialProgressStatus.ServiceError ||
                state.Status ==
                TutorialProgressStatus.AuthenticationUnavailable)
            {
                return ResultForState();
            }

            return null;
        }

        private async Task<TutorialProgressResult> LoadCoreAsync()
        {
            int operationGeneration = requestGeneration;
            string playerId = null;
            try
            {
                await UnityServicesInitializer.InitializeAsync();
                if (!TryGetAuthenticatedPlayerId(out playerId))
                    return AuthenticationUnavailableResult();

                activePlayerId = playerId;
                Publish(
                    new TutorialProgressState(
                        TutorialProgressStatus.Loading,
                        playerId,
                        state.Stage,
                        state.CloudConfirmedStage,
                        state.IsCompleted,
                        false,
                        pendingStage.HasValue,
                        pendingStage,
                        null));

                if (!IsRequestCurrent(
                        operationGeneration,
                        playerId))
                {
                    return AuthenticationUnavailableResult();
                }

                Dictionary<string, Item> data =
                    await CloudSaveService.Instance.Data.Player.LoadAsync(
                        new HashSet<string>
                        {
                            StageKey,
                            CompletionKey
                        },
                        new LoadOptions());

                if (!IsRequestCurrent(
                        operationGeneration,
                        playerId))
                {
                    return AuthenticationUnavailableResult();
                }

                TutorialProgressResult cloudResult =
                    ApplyCloudData(playerId, data);
                if (cloudResult.Operation != TutorialProgressOperation.Applied)
                    return cloudResult;

                if (!TutorialProgressJournal.TryLoad(
                        playerId,
                        out TutorialStage journalStage,
                        out string journalError))
                {
                    PublishServiceError(journalError);
                    return Result(TutorialProgressOperation.ServiceError);
                }

                if (journalStage > TutorialStage.Welcome)
                {
                    if (state.IsCompleted ||
                        (journalStage != TutorialStage.Completed &&
                         state.CloudConfirmedStage >= journalStage))
                    {
                        TutorialProgressJournal.TryClear(
                            playerId,
                            out _);
                        pendingStage = null;
                    }
                    else
                    {
                        pendingStage = journalStage;
                        PublishPendingState(journalStage, null);
                    }
                }

                return Result(TutorialProgressOperation.Applied);
            }
            catch (Exception exception)
            {
                if (disposed)
                    return AuthenticationUnavailableResult();

                if (!IsRequestCurrent(
                        operationGeneration,
                        playerId))
                {
                    return AuthenticationUnavailableResult();
                }

                PublishServiceError(exception.Message);
                return Result(TutorialProgressOperation.ServiceError);
            }
        }

        private TutorialProgressResult ApplyCloudData(
            string playerId,
            Dictionary<string, Item> data)
        {
            bool hasStage = data.TryGetValue(StageKey, out Item stageItem);
            bool hasCompletion =
                data.TryGetValue(CompletionKey, out Item completionItem);

            if (hasCompletion)
            {
                if (!TryReadBoolean(completionItem, out bool completion))
                {
                    PublishInvalidData(
                        playerId,
                        "The tutorial completion record is malformed.");
                    return Result(TutorialProgressOperation.InvalidData);
                }

                if (completion)
                {
                    completionWriteLock = completionItem.WriteLock;
                    stageWriteLock = hasStage
                        ? stageItem.WriteLock
                        : null;
                    pendingStage = null;
                    PublishVerifiedState(
                        TutorialProgressStatus.Valid,
                        TutorialStage.Completed,
                        true,
                        null,
                        null);
                    return Result(TutorialProgressOperation.Applied);
                }
            }

            TutorialStage stage = TutorialStage.Welcome;
            if (hasStage &&
                !TryReadStage(stageItem, out stage))
            {
                PublishInvalidData(
                    playerId,
                    "The tutorial stage record is malformed.");
                return Result(TutorialProgressOperation.InvalidData);
            }

            if (state.PlayerId == playerId &&
                state.CloudConfirmedStage > stage)
            {
                stage = state.CloudConfirmedStage;
            }

            stageWriteLock = hasStage ? stageItem.WriteLock : null;
            completionWriteLock = hasCompletion
                ? completionItem.WriteLock
                : null;
            pendingStage = pendingStage.HasValue &&
                pendingStage.Value > stage
                ? pendingStage
                : null;

            PublishVerifiedState(
                hasStage || hasCompletion
                    ? TutorialProgressStatus.Valid
                    : TutorialProgressStatus.Missing,
                stage,
                false,
                pendingStage,
                null);
            return Result(TutorialProgressOperation.Applied);
        }

        private async Task<TutorialProgressResult> PersistStageCoreAsync(
            TutorialStage requestedStage)
        {
            if (requestedStage == TutorialStage.Completed)
                return await PersistCompletionCoreAsync();

            pendingStage = requestedStage;
            int operationGeneration = requestGeneration;
            string playerId = activePlayerId;
            // The observer must call this immediately after its gameplay
            // commit; a process crash before this journal write cannot be
            // reconstructed without replaying gameplay.
            if (!TutorialProgressJournal.TrySave(
                    playerId,
                    requestedStage,
                    out string journalError))
            {
                pendingStage = null;
                PublishServiceError(journalError);
                return Result(TutorialProgressOperation.ServiceError);
            }

            PublishPendingState(requestedStage, null);
            try
            {
                for (int attempt = 0;
                     attempt < MaxCloudSaveAttempts;
                     attempt++)
                {
                    try
                    {
                        await CloudSaveService.Instance.Data.Player.SaveAsync(
                            new Dictionary<string, SaveItem>
                            {
                                [StageKey] = new SaveItem(
                                    requestedStage.ToString(),
                                    stageWriteLock)
                            },
                            new Unity.Services.CloudSave.Models.Data.Player.SaveOptions());

                        TutorialProgressResult verified = await LoadCoreAsync();
                        if (verified.Operation ==
                                TutorialProgressOperation.Applied &&
                            (state.IsCompleted ||
                             state.CloudConfirmedStage >= requestedStage))
                        {
                            pendingStage = null;
                            TutorialProgressJournal.TryClear(
                                playerId,
                                out _);
                            return Result(
                                TutorialProgressOperation.Applied);
                        }

                        if (verified.Operation !=
                            TutorialProgressOperation.Applied)
                            return verified;
                    }
                    catch (Exception exception)
                    {
                        if (!IsRequestCurrent(
                                operationGeneration,
                                playerId))
                            return AuthenticationUnavailableResult();

                        TutorialProgressResult reconciled =
                            await LoadCoreAsync();
                        if (reconciled.Operation !=
                                TutorialProgressOperation.Applied)
                            return reconciled;
                        if (state.IsCompleted ||
                            state.CloudConfirmedStage >= requestedStage)
                        {
                            pendingStage = null;
                            TutorialProgressJournal.TryClear(
                                playerId,
                                out _);
                            return Result(
                                TutorialProgressOperation.Applied);
                        }

                        if (attempt == MaxCloudSaveAttempts - 1)
                        {
                            PublishPendingState(
                                requestedStage,
                                exception.Message);
                            return Result(
                                TutorialProgressOperation.Pending);
                        }
                    }
                }
                return Result(TutorialProgressOperation.Pending);
            }
            catch (Exception exception)
            {
                if (!IsRequestCurrent(
                        operationGeneration,
                        playerId))
                {
                    return AuthenticationUnavailableResult();
                }

                PublishPendingState(requestedStage, exception.Message);
                return Result(TutorialProgressOperation.Pending);
            }
        }

        private async Task<TutorialProgressResult> PersistCompletionCoreAsync()
        {
            TutorialStage requestedStage = TutorialStage.Completed;
            pendingStage = requestedStage;
            int operationGeneration = requestGeneration;
            string playerId = activePlayerId;
            // The observer must call this immediately after its gameplay
            // commit; a process crash before this journal write cannot be
            // reconstructed without replaying gameplay.
            if (!TutorialProgressJournal.TrySave(
                    playerId,
                    requestedStage,
                    out string journalError))
            {
                pendingStage = null;
                PublishServiceError(journalError);
                return Result(TutorialProgressOperation.ServiceError);
            }

            PublishPendingState(requestedStage, null);
            try
            {
                for (int attempt = 0;
                     attempt < MaxCloudSaveAttempts;
                     attempt++)
                {
                    try
                    {
                        await CloudSaveService.Instance.Data.Player.SaveAsync(
                            new Dictionary<string, SaveItem>
                            {
                                [StageKey] = new SaveItem(
                                    requestedStage.ToString(),
                                    stageWriteLock),
                                [CompletionKey] = new SaveItem(
                                    true,
                                    completionWriteLock)
                            },
                            new Unity.Services.CloudSave.Models.Data.Player.SaveOptions());

                        TutorialProgressResult verified = await LoadCoreAsync();
                        if (verified.Operation ==
                                TutorialProgressOperation.Applied &&
                            state.IsCompleted)
                        {
                            pendingStage = null;
                            TutorialProgressJournal.TryClear(
                                playerId,
                                out _);
                            return Result(
                                TutorialProgressOperation.Applied);
                        }

                        if (verified.Operation !=
                            TutorialProgressOperation.Applied)
                            return verified;
                    }
                    catch (Exception exception)
                    {
                        if (!IsRequestCurrent(
                                operationGeneration,
                                playerId))
                            return AuthenticationUnavailableResult();

                        TutorialProgressResult reconciled =
                            await LoadCoreAsync();
                        if (reconciled.Operation !=
                                TutorialProgressOperation.Applied)
                            return reconciled;
                        if (state.IsCompleted)
                        {
                            pendingStage = null;
                            TutorialProgressJournal.TryClear(
                                playerId,
                                out _);
                            return Result(
                                TutorialProgressOperation.Applied);
                        }

                        if (attempt == MaxCloudSaveAttempts - 1)
                        {
                            PublishPendingState(
                                requestedStage,
                                exception.Message);
                            return Result(
                                TutorialProgressOperation.Pending);
                        }
                    }
                }
                return Result(TutorialProgressOperation.Pending);
            }
            catch (Exception exception)
            {
                if (!IsRequestCurrent(
                        operationGeneration,
                        playerId))
                {
                    return AuthenticationUnavailableResult();
                }

                PublishPendingState(requestedStage, exception.Message);
                return Result(TutorialProgressOperation.Pending);
            }
        }

        private void HandleSignedIn()
        {
            RefreshAuthenticationContext();
        }

        private void HandleSignedOut()
        {
            requestGeneration++;
            activePlayerId = null;
            stageWriteLock = null;
            completionWriteLock = null;
            pendingStage = null;
            Publish(
                new TutorialProgressState(
                    TutorialProgressStatus.AuthenticationUnavailable,
                    null,
                    TutorialStage.Welcome,
                    TutorialStage.Welcome,
                    false,
                    false,
                    false,
                    null,
                    "Authentication is unavailable."));
        }

        private void RefreshAuthenticationContext()
        {
            if (!TryGetAuthenticatedPlayerId(out string playerId))
                return;

            if (activePlayerId == playerId)
                return;

            requestGeneration++;
            activePlayerId = playerId;
            stageWriteLock = null;
            completionWriteLock = null;
            pendingStage = null;
            Publish(TutorialProgressState.Initial());
        }

        private bool TryGetAuthenticatedPlayerId(out string playerId)
        {
            playerId = null;
            if (UnityServices.State !=
                ServicesInitializationState.Initialized)
            {
                return false;
            }

            IAuthenticationService authentication =
                AuthenticationService.Instance;
            if (!authentication.IsSignedIn ||
                !authentication.IsAuthorized ||
                string.IsNullOrWhiteSpace(authentication.PlayerId))
            {
                return false;
            }

            playerId = authentication.PlayerId;
            return true;
        }

        private bool IsCurrentPlayer(string playerId)
        {
            return !string.IsNullOrWhiteSpace(playerId) &&
                TryGetAuthenticatedPlayerId(out string currentPlayerId) &&
                currentPlayerId == playerId;
        }

        private bool IsRequestCurrent(
            int operationGeneration,
            string playerId)
        {
            return !disposed &&
                operationGeneration == requestGeneration &&
                IsCurrentPlayer(playerId);
        }

        private static bool TryReadStage(
            Item item,
            out TutorialStage stage)
        {
            stage = TutorialStage.Welcome;
            if (item == null || item.Value == null)
                return false;

            string value = item.Value.GetAsString();
            return Enum.TryParse(
                value,
                true,
                out stage) &&
                Enum.IsDefined(typeof(TutorialStage), stage);
        }

        private static bool TryReadBoolean(
            Item item,
            out bool value)
        {
            value = false;
            if (item == null || item.Value == null)
                return false;

            try
            {
                value = item.Value.GetAs<bool>();
                return true;
            }
            catch
            {
                return bool.TryParse(
                    item.Value.GetAsString(),
                    out value);
            }
        }

        private void PublishPendingState(
            TutorialStage requestedStage,
            string errorMessage)
        {
            Publish(
                new TutorialProgressState(
                    TutorialProgressStatus.PendingWrite,
                    activePlayerId,
                    requestedStage,
                    state.CloudConfirmedStage,
                    state.IsCompleted,
                    false,
                    true,
                    requestedStage,
                    errorMessage));
        }

        private void PublishServiceError(string errorMessage)
        {
            Publish(
                new TutorialProgressState(
                    TutorialProgressStatus.ServiceError,
                    activePlayerId,
                    state.Stage,
                    state.CloudConfirmedStage,
                    state.IsCompleted,
                    false,
                    pendingStage.HasValue,
                    pendingStage,
                    errorMessage));
        }

        private void PublishInvalidData(
            string playerId,
            string errorMessage)
        {
            Publish(
                new TutorialProgressState(
                    TutorialProgressStatus.InvalidData,
                    playerId,
                    state.Stage,
                    state.CloudConfirmedStage,
                    state.IsCompleted,
                    false,
                    pendingStage.HasValue,
                    pendingStage,
                    errorMessage));
        }

        private void PublishVerifiedState(
            TutorialProgressStatus status,
            TutorialStage stage,
            bool isCompleted,
            TutorialStage? pending,
            string errorMessage)
        {
            Publish(
                new TutorialProgressState(
                    status,
                    activePlayerId,
                    stage,
                    stage,
                    isCompleted,
                    !pending.HasValue,
                    pending.HasValue,
                    pending,
                    errorMessage));
        }

        private void Publish(TutorialProgressState nextState)
        {
            if (disposed)
                return;

            state = nextState;
            StateChanged?.Invoke(state);
        }

        private TutorialProgressResult Result(
            TutorialProgressOperation operation)
        {
            return new TutorialProgressResult(operation, state);
        }

        private TutorialProgressResult ResultForState()
        {
            switch (state.Status)
            {
                case TutorialProgressStatus.InvalidData:
                    return Result(TutorialProgressOperation.InvalidData);
                case TutorialProgressStatus.AuthenticationUnavailable:
                    return Result(
                        TutorialProgressOperation.AuthenticationUnavailable);
                default:
                    return Result(TutorialProgressOperation.ServiceError);
            }
        }

        private TutorialProgressResult AuthenticationUnavailableResult()
        {
            Publish(
                new TutorialProgressState(
                    TutorialProgressStatus.AuthenticationUnavailable,
                    null,
                    TutorialStage.Welcome,
                    TutorialStage.Welcome,
                    false,
                    false,
                    false,
                    null,
                    "Authentication is unavailable."));
            return Result(
                TutorialProgressOperation.AuthenticationUnavailable);
        }

        private void ThrowIfDisposed()
        {
            if (disposed)
                throw new ObjectDisposedException(
                    nameof(TutorialProgressService));
        }
    }
}
