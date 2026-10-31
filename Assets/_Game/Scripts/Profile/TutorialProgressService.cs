using System;
using System.Threading.Tasks;

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
        InvalidData,
        ServiceError
    }

    public sealed class TutorialProgressState
    {
        public TutorialProgressStatus Status { get; }
        public TutorialStage Stage { get; }
        public bool IsCompleted =>
            Stage == TutorialStage.Completed;
        public bool IsLocallyValidated { get; }
        public string ErrorMessage { get; }

        internal TutorialProgressState(
            TutorialProgressStatus status,
            TutorialStage stage,
            bool isLocallyValidated,
            string errorMessage)
        {
            Status = status;
            Stage = stage;
            IsLocallyValidated = isLocallyValidated;
            ErrorMessage = errorMessage;
        }

        public static TutorialProgressState Initial()
        {
            return new TutorialProgressState(
                TutorialProgressStatus.Unknown,
                TutorialStage.Welcome,
                false,
                null);
        }
    }

    public enum TutorialProgressOperation
    {
        Applied,
        AlreadyAtOrBeyond,
        DuplicateRequest,
        OutOfOrder,
        InvalidData,
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
        private TutorialProgressState state =
            TutorialProgressState.Initial();
        private bool operationInFlight;
        private bool disposed;

        public TutorialProgressState State => state;

        public event Action<TutorialProgressState> StateChanged;

        public void Initialize()
        {
            ThrowIfDisposed();
        }

        public Task<TutorialProgressResult> LoadAsync()
        {
            ThrowIfDisposed();
            if (!TryBeginOperation())
                return Completed(TutorialProgressOperation.DuplicateRequest);

            try
            {
                return Task.FromResult(LoadCore());
            }
            finally
            {
                operationInFlight = false;
            }
        }

        public Task<TutorialProgressResult> AdvanceToAsync(
            TutorialStage requestedStage)
        {
            ThrowIfDisposed();
            if (requestedStage == TutorialStage.Completed)
                return MarkCompletedAsync();
            if (!Enum.IsDefined(typeof(TutorialStage), requestedStage))
                return Completed(TutorialProgressOperation.OutOfOrder);
            if (!TryBeginOperation())
                return Completed(TutorialProgressOperation.DuplicateRequest);

            try
            {
                TutorialProgressResult loaded = EnsureLoaded();
                if (loaded != null)
                    return Task.FromResult(loaded);

                if ((int)requestedStage <= (int)state.Stage)
                    return Completed(
                        TutorialProgressOperation.AlreadyAtOrBeyond);
                if (requestedStage != NextStage(state.Stage))
                    return Completed(TutorialProgressOperation.OutOfOrder);

                return Task.FromResult(PersistStage(requestedStage));
            }
            finally
            {
                operationInFlight = false;
            }
        }

        public Task<TutorialProgressResult> MarkCompletedAsync()
        {
            ThrowIfDisposed();
            if (!TryBeginOperation())
                return Completed(TutorialProgressOperation.DuplicateRequest);

            try
            {
                TutorialProgressResult loaded = EnsureLoaded();
                if (loaded != null)
                    return Task.FromResult(loaded);

                if (state.IsCompleted)
                    return Completed(
                        TutorialProgressOperation.AlreadyAtOrBeyond);
                if (state.Stage != TutorialStage.Order)
                    return Completed(TutorialProgressOperation.OutOfOrder);

                return Task.FromResult(PersistStage(TutorialStage.Completed));
            }
            finally
            {
                operationInFlight = false;
            }
        }

        public void Dispose()
        {
            disposed = true;
        }

        private bool TryBeginOperation()
        {
            if (operationInFlight)
                return false;

            operationInFlight = true;
            return true;
        }

        private TutorialProgressResult LoadCore()
        {
            Publish(
                TutorialProgressStatus.Loading,
                state.Stage,
                false,
                null);

            TutorialProgressJournalLoadStatus loadStatus =
                TutorialProgressJournal.TryLoad(
                    out TutorialStage loadedStage,
                    out string errorMessage);

            switch (loadStatus)
            {
                case TutorialProgressJournalLoadStatus.Missing:
                    Publish(
                        TutorialProgressStatus.Missing,
                        TutorialStage.Welcome,
                        true,
                        null);
                    return Result(TutorialProgressOperation.Applied);
                case TutorialProgressJournalLoadStatus.Loaded:
                    Publish(
                        TutorialProgressStatus.Valid,
                        loadedStage,
                        true,
                        null);
                    return Result(TutorialProgressOperation.Applied);
                case TutorialProgressJournalLoadStatus.InvalidData:
                    Publish(
                        TutorialProgressStatus.InvalidData,
                        state.Stage,
                        false,
                        errorMessage);
                    return Result(TutorialProgressOperation.InvalidData);
                default:
                    Publish(
                        TutorialProgressStatus.ServiceError,
                        state.Stage,
                        false,
                        errorMessage);
                    return Result(TutorialProgressOperation.ServiceError);
            }
        }

        private TutorialProgressResult EnsureLoaded()
        {
            if (state.IsLocallyValidated)
                return null;

            if (state.Status == TutorialProgressStatus.InvalidData ||
                state.Status == TutorialProgressStatus.ServiceError)
                return ResultForState();

            TutorialProgressResult loaded = LoadCore();
            return loaded.Operation == TutorialProgressOperation.Applied
                ? null
                : loaded;
        }

        private TutorialProgressResult PersistStage(
            TutorialStage requestedStage)
        {
            TutorialProgressJournalSaveStatus saveStatus =
                TutorialProgressJournal.TrySave(
                    requestedStage,
                    out string errorMessage);

            if (saveStatus == TutorialProgressJournalSaveStatus.Saved)
            {
                Publish(
                    TutorialProgressStatus.Valid,
                    requestedStage,
                    true,
                    null);
                return Result(TutorialProgressOperation.Applied);
            }

            TutorialProgressStatus failureStatus =
                saveStatus == TutorialProgressJournalSaveStatus.InvalidData
                    ? TutorialProgressStatus.InvalidData
                    : TutorialProgressStatus.ServiceError;
            Publish(
                failureStatus,
                state.Stage,
                false,
                errorMessage);
            return ResultForState();
        }

        private void Publish(
            TutorialProgressStatus status,
            TutorialStage stage,
            bool isLocallyValidated,
            string errorMessage)
        {
            if (disposed)
                return;

            state = new TutorialProgressState(
                status,
                stage,
                isLocallyValidated,
                errorMessage);
            StateChanged?.Invoke(state);
        }

        private TutorialProgressResult Result(
            TutorialProgressOperation operation)
        {
            return new TutorialProgressResult(operation, state);
        }

        private TutorialProgressResult ResultForState()
        {
            return Result(
                state.Status == TutorialProgressStatus.InvalidData
                    ? TutorialProgressOperation.InvalidData
                    : TutorialProgressOperation.ServiceError);
        }

        private Task<TutorialProgressResult> Completed(
            TutorialProgressOperation operation)
        {
            return Task.FromResult(Result(operation));
        }

        private static TutorialStage NextStage(TutorialStage stage)
        {
            return (int)stage < (int)TutorialStage.Completed
                ? (TutorialStage)((int)stage + 1)
                : TutorialStage.Completed;
        }

        private void ThrowIfDisposed()
        {
            if (disposed)
                throw new ObjectDisposedException(
                    nameof(TutorialProgressService));
        }
    }
}
