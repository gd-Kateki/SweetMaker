using System;
using System.Threading.Tasks;
using GooglePlayGames;
using GooglePlayGames.BasicApi;
using SweetMerge.Analytics;
using Unity.Services.Authentication;
using Unity.Services.Core;
using UnityEngine;

namespace SweetMerge.Authentication
{
    public enum GooglePlayGamesAuthenticationState
    {
        SignedOut,
        SigningIn,
        SignedIn,
        Failed,
        Cancelled,
        SignedInUnverified
    }

    public enum GooglePlayGamesAuthenticationFailure
    {
        None,
        UnityServicesInitialization,
        PlayGamesAuthentication,
        AuthorizationCodeUnavailable,
        UnityAuthentication,
        CachedSessionUnavailable,
        CachedSessionAvailable,
        SessionRestoration,
        SessionIdentityVerification
    }

    public enum GooglePlayGamesAuthenticationResult
    {
        SignedIn,
        Failed,
        Cancelled,
        Unverified
    }

    public enum GooglePlayGamesSessionStatus
    {
        Unavailable,
        NotConnected,
        PreviousSessionAvailable,
        RestoringSession,
        RestorationFailed,
        SignedInUnverified,
        GooglePlayGamesConnected
    }

    internal enum PlayGamesAuthenticationStatus
    {
        Success,
        Failed,
        Cancelled
    }

    internal interface IGooglePlayGamesAuthenticationRuntime
    {
        Task InitializeUnityServicesAsync();
        Task<GooglePlayGamesSessionStatus> RestoreCachedSessionAsync();
        Task<PlayGamesAuthenticationStatus> AuthenticateWithPlayGamesAsync();
        Task<string> RequestServerSideAccessAsync(bool forceRefreshToken);
        Task SignInWithUnityAuthenticationAsync(string authCode);
        bool HasCachedSessionToken { get; }
        Task<GooglePlayGamesSessionStatus> RefreshSessionStatusAsync();
    }

    public sealed class GooglePlayGamesAuthenticationCoordinator
    {
        private sealed class UnityAuthenticationRuntime :
            IGooglePlayGamesAuthenticationRuntime
        {
            public Task InitializeUnityServicesAsync() =>
                UnityServicesInitializer.InitializeAsync();

            public bool HasCachedSessionToken =>
                AuthenticationService.Instance.SessionTokenExists;

            public async Task<GooglePlayGamesSessionStatus>
                RestoreCachedSessionAsync()
            {
                IAuthenticationService authentication =
                    AuthenticationService.Instance;

                if (!authentication.IsAuthorized)
                {
                    if (!authentication.SessionTokenExists)
                    {
                        return GooglePlayGamesSessionStatus.NotConnected;
                    }

                    await authentication.SignInAnonymouslyAsync(
                        new SignInOptions { CreateAccount = false });
                }

                if (!authentication.IsSignedIn ||
                    !authentication.IsAuthorized)
                {
                    throw new InvalidOperationException(
                        "The cached authentication session could not be verified.");
                }

                PlayerInfo playerInfo =
                    await authentication.GetPlayerInfoAsync();
                return HasGooglePlayGamesIdentity(playerInfo)
                    ? GooglePlayGamesSessionStatus.GooglePlayGamesConnected
                    : GooglePlayGamesSessionStatus.SignedInUnverified;
            }

            public Task<PlayGamesAuthenticationStatus>
                AuthenticateWithPlayGamesAsync()
            {
                var completion =
                    new TaskCompletionSource<PlayGamesAuthenticationStatus>(
                        TaskCreationOptions.RunContinuationsAsynchronously);

                PlayGamesPlatform.Instance.ManuallyAuthenticate(status =>
                {
                    switch (status)
                    {
                        case SignInStatus.Success:
                            completion.TrySetResult(
                                PlayGamesAuthenticationStatus.Success);
                            break;
                        case SignInStatus.Canceled:
                            completion.TrySetResult(
                                PlayGamesAuthenticationStatus.Cancelled);
                            break;
                        default:
                            completion.TrySetResult(
                                PlayGamesAuthenticationStatus.Failed);
                            break;
                    }
                });

                return completion.Task;
            }

            public Task<string> RequestServerSideAccessAsync(
                bool forceRefreshToken)
            {
                var completion = new TaskCompletionSource<string>(
                    TaskCreationOptions.RunContinuationsAsynchronously);

                PlayGamesSettings settings = PlayGamesSettings.LoadInstance();
                GooglePlayGamesWebClientResolver.InvokeWithSelectedClient(
                    Application.identifier,
                    settings,
                    GooglePlayGamesWebClientResolver.ProductionWebClientId,
                    () => PlayGamesPlatform.Instance.RequestServerSideAccess(
                        forceRefreshToken,
                        authCode => completion.TrySetResult(authCode)));

                return completion.Task;
            }

            public Task SignInWithUnityAuthenticationAsync(string authCode) =>
                AuthenticationService.Instance
                    .SignInWithGooglePlayGamesAsync(authCode);

            public async Task<GooglePlayGamesSessionStatus>
                RefreshSessionStatusAsync()
            {
                if (UnityServices.State !=
                    ServicesInitializationState.Initialized)
                {
                    return GooglePlayGamesSessionStatus.Unavailable;
                }

                IAuthenticationService authentication =
                    AuthenticationService.Instance;
                if (!authentication.IsSignedIn)
                {
                    return authentication.SessionTokenExists
                        ? GooglePlayGamesSessionStatus
                            .PreviousSessionAvailable
                        : GooglePlayGamesSessionStatus.NotConnected;
                }

                if (!authentication.IsAuthorized)
                {
                    return authentication.SessionTokenExists
                        ? GooglePlayGamesSessionStatus
                            .PreviousSessionAvailable
                        : GooglePlayGamesSessionStatus.SignedInUnverified;
                }

                if (HasGooglePlayGamesIdentity(authentication.PlayerInfo))
                {
                    return GooglePlayGamesSessionStatus
                        .GooglePlayGamesConnected;
                }

                PlayerInfo playerInfo =
                    await authentication.GetPlayerInfoAsync();
                return HasGooglePlayGamesIdentity(playerInfo)
                    ? GooglePlayGamesSessionStatus.GooglePlayGamesConnected
                    : GooglePlayGamesSessionStatus.SignedInUnverified;
            }

            private static bool HasGooglePlayGamesIdentity(
                PlayerInfo playerInfo)
            {
                return playerInfo != null &&
                       !string.IsNullOrEmpty(
                           playerInfo.GetGooglePlayGamesId());
            }
        }

        private static readonly object InstanceGate = new object();
        private static GooglePlayGamesAuthenticationCoordinator instance;

        private readonly object gate = new object();
        private readonly IGooglePlayGamesAuthenticationRuntime runtime;
        private Task<GooglePlayGamesAuthenticationResult> activeAttempt;
        private int sessionOperationVersion;
        private GooglePlayGamesAuthenticationState state =
            GooglePlayGamesAuthenticationState.SignedOut;
        private GooglePlayGamesAuthenticationFailure failure =
            GooglePlayGamesAuthenticationFailure.None;
        private GooglePlayGamesSessionStatus sessionStatus =
            GooglePlayGamesSessionStatus.Unavailable;

        public event Action StateChanged;

        public static GooglePlayGamesAuthenticationCoordinator Instance
        {
            get
            {
                lock (InstanceGate)
                {
                    if (instance == null)
                    {
                        instance =
                            new GooglePlayGamesAuthenticationCoordinator(
                                new UnityAuthenticationRuntime());
                    }

                    return instance;
                }
            }
        }

        public GooglePlayGamesAuthenticationState State
        {
            get
            {
                lock (gate)
                    return state;
            }
        }

        public GooglePlayGamesAuthenticationFailure Failure
        {
            get
            {
                lock (gate)
                    return failure;
            }
        }

        public GooglePlayGamesSessionStatus SessionStatus
        {
            get
            {
                lock (gate)
                    return sessionStatus;
            }
        }

        internal GooglePlayGamesAuthenticationCoordinator(
            IGooglePlayGamesAuthenticationRuntime runtime)
        {
            this.runtime = runtime ??
                throw new ArgumentNullException(nameof(runtime));
        }

        [RuntimeInitializeOnLoadMethod(
            RuntimeInitializeLoadType.SubsystemRegistration)]
        private static void ResetInstance()
        {
            lock (InstanceGate)
                instance = null;
        }

        public Task<GooglePlayGamesAuthenticationResult> SignInAsync()
        {
            return BeginAttempt(restoreCachedSession: false);
        }

        public Task<GooglePlayGamesAuthenticationResult>
            RestoreSessionAsync()
        {
            return BeginAttempt(restoreCachedSession: true);
        }

        private Task<GooglePlayGamesAuthenticationResult> BeginAttempt(
            bool restoreCachedSession)
        {
            TaskCompletionSource<GooglePlayGamesAuthenticationResult> completion;

            lock (gate)
            {
                if (activeAttempt != null)
                    return activeAttempt;

                if (state == GooglePlayGamesAuthenticationState.SignedIn)
                {
                    return Task.FromResult(
                        GooglePlayGamesAuthenticationResult.SignedIn);
                }

                state = GooglePlayGamesAuthenticationState.SigningIn;
                failure = GooglePlayGamesAuthenticationFailure.None;
                if (restoreCachedSession)
                {
                    sessionStatus =
                        GooglePlayGamesSessionStatus.RestoringSession;
                }
                sessionOperationVersion++;
                completion =
                    new TaskCompletionSource<
                        GooglePlayGamesAuthenticationResult>(
                        TaskCreationOptions.RunContinuationsAsynchronously);
                activeAttempt = completion.Task;
            }

            NotifyStateChanged();
            _ = RunAttemptAsync(completion, restoreCachedSession);
            return completion.Task;
        }

        public async Task<GooglePlayGamesSessionStatus>
            RefreshSessionStatusAsync()
        {
            int operationVersion;
            lock (gate)
            {
                if (state == GooglePlayGamesAuthenticationState.SignedIn ||
                    state == GooglePlayGamesAuthenticationState.SigningIn ||
                    activeAttempt != null)
                {
                    return sessionStatus;
                }

                operationVersion = sessionOperationVersion;
            }

            GooglePlayGamesSessionStatus refreshedStatus;
            try
            {
                refreshedStatus =
                    await runtime.RefreshSessionStatusAsync();
            }
            catch (Exception)
            {
                Debug.LogWarning(
                    "Authentication status could not be refreshed. " +
                    "The Google Play Games connection was not verified.");
                refreshedStatus = GooglePlayGamesSessionStatus.Unavailable;
            }

            bool changed;
            lock (gate)
            {
                if (operationVersion != sessionOperationVersion ||
                    activeAttempt != null)
                {
                    return sessionStatus;
                }

                if (refreshedStatus ==
                    GooglePlayGamesSessionStatus.GooglePlayGamesConnected)
                {
                    state = GooglePlayGamesAuthenticationState.SignedIn;
                    failure = GooglePlayGamesAuthenticationFailure.None;
                }
                else if (refreshedStatus ==
                         GooglePlayGamesSessionStatus.SignedInUnverified)
                {
                    state =
                        GooglePlayGamesAuthenticationState.SignedInUnverified;
                }
                else if (refreshedStatus ==
                             GooglePlayGamesSessionStatus.NotConnected ||
                         refreshedStatus ==
                             GooglePlayGamesSessionStatus
                                 .PreviousSessionAvailable)
                {
                    state = GooglePlayGamesAuthenticationState.SignedOut;
                    failure = GooglePlayGamesAuthenticationFailure.None;
                }

                changed = sessionStatus != refreshedStatus;
                sessionStatus = refreshedStatus;
            }

            if (changed || refreshedStatus ==
                GooglePlayGamesSessionStatus.GooglePlayGamesConnected ||
                refreshedStatus ==
                GooglePlayGamesSessionStatus.SignedInUnverified)
            {
                NotifyStateChanged();
            }

            return refreshedStatus;
        }

        private async Task RunAttemptAsync(
            TaskCompletionSource<GooglePlayGamesAuthenticationResult>
                completion,
            bool restoreCachedSession)
        {
            try
            {
                try
                {
                    await runtime.InitializeUnityServicesAsync();
                }
                catch (Exception)
                {
                    CompleteAttempt(
                        completion,
                        GooglePlayGamesAuthenticationState.Failed,
                        GooglePlayGamesAuthenticationFailure
                            .UnityServicesInitialization,
                        GooglePlayGamesAuthenticationResult.Failed,
                        restoreCachedSession
                            ? GooglePlayGamesSessionStatus.RestorationFailed
                            : (GooglePlayGamesSessionStatus?)null);
                    return;
                }

                if (restoreCachedSession)
                {
                    await RestoreCachedSessionAsync(completion);
                    return;
                }

                GooglePlayGamesSessionStatus currentSessionStatus;
                try
                {
                    currentSessionStatus =
                        await runtime.RefreshSessionStatusAsync();
                }
                catch (Exception)
                {
                    CompleteAttempt(
                        completion,
                        GooglePlayGamesAuthenticationState.Failed,
                        GooglePlayGamesAuthenticationFailure
                            .SessionIdentityVerification,
                        GooglePlayGamesAuthenticationResult.Failed,
                        GooglePlayGamesSessionStatus.Unavailable);
                    return;
                }

                if (currentSessionStatus ==
                    GooglePlayGamesSessionStatus.PreviousSessionAvailable)
                {
                    CompleteAttempt(
                        completion,
                        GooglePlayGamesAuthenticationState.Failed,
                        GooglePlayGamesAuthenticationFailure
                            .CachedSessionAvailable,
                        GooglePlayGamesAuthenticationResult.Failed,
                        currentSessionStatus);
                    return;
                }

                if (currentSessionStatus ==
                    GooglePlayGamesSessionStatus.GooglePlayGamesConnected)
                {
                    CompleteAttempt(
                        completion,
                        GooglePlayGamesAuthenticationState.SignedIn,
                        GooglePlayGamesAuthenticationFailure.None,
                        GooglePlayGamesAuthenticationResult.SignedIn,
                        currentSessionStatus);
                    return;
                }

                if (currentSessionStatus ==
                    GooglePlayGamesSessionStatus.SignedInUnverified)
                {
                    CompleteAttempt(
                        completion,
                        GooglePlayGamesAuthenticationState
                            .SignedInUnverified,
                        GooglePlayGamesAuthenticationFailure.None,
                        GooglePlayGamesAuthenticationResult.Unverified,
                        currentSessionStatus);
                    return;
                }

                if (currentSessionStatus !=
                    GooglePlayGamesSessionStatus.NotConnected)
                {
                    CompleteAttempt(
                        completion,
                        GooglePlayGamesAuthenticationState.Failed,
                        GooglePlayGamesAuthenticationFailure
                            .SessionIdentityVerification,
                        GooglePlayGamesAuthenticationResult.Failed,
                        currentSessionStatus);
                    return;
                }

                PlayGamesAuthenticationStatus signInStatus;
                try
                {
                    signInStatus =
                        await runtime.AuthenticateWithPlayGamesAsync();
                }
                catch (Exception)
                {
                    CompleteAttempt(
                        completion,
                        GooglePlayGamesAuthenticationState.Failed,
                        GooglePlayGamesAuthenticationFailure
                            .PlayGamesAuthentication,
                        GooglePlayGamesAuthenticationResult.Failed);
                    return;
                }

                if (signInStatus == PlayGamesAuthenticationStatus.Cancelled)
                {
                    CompleteAttempt(
                        completion,
                        GooglePlayGamesAuthenticationState.Cancelled,
                        GooglePlayGamesAuthenticationFailure.None,
                        GooglePlayGamesAuthenticationResult.Cancelled);
                    return;
                }

                if (signInStatus != PlayGamesAuthenticationStatus.Success)
                {
                    CompleteAttempt(
                        completion,
                        GooglePlayGamesAuthenticationState.Failed,
                        GooglePlayGamesAuthenticationFailure
                            .PlayGamesAuthentication,
                        GooglePlayGamesAuthenticationResult.Failed);
                    return;
                }

                string authCode;
                try
                {
                    authCode =
                        await runtime.RequestServerSideAccessAsync(
                            forceRefreshToken: false);
                }
                catch (Exception)
                {
                    CompleteAttempt(
                        completion,
                        GooglePlayGamesAuthenticationState.Failed,
                        GooglePlayGamesAuthenticationFailure
                            .AuthorizationCodeUnavailable,
                        GooglePlayGamesAuthenticationResult.Failed);
                    return;
                }

                if (string.IsNullOrWhiteSpace(authCode))
                {
                    CompleteAttempt(
                        completion,
                        GooglePlayGamesAuthenticationState.Failed,
                        GooglePlayGamesAuthenticationFailure
                            .AuthorizationCodeUnavailable,
                        GooglePlayGamesAuthenticationResult.Failed);
                    return;
                }

                try
                {
                    await runtime.SignInWithUnityAuthenticationAsync(authCode);
                }
                catch (Exception)
                {
                    CompleteAttempt(
                        completion,
                        GooglePlayGamesAuthenticationState.Failed,
                        GooglePlayGamesAuthenticationFailure
                            .UnityAuthentication,
                        GooglePlayGamesAuthenticationResult.Failed);
                    return;
                }

                CompleteAttempt(
                    completion,
                    GooglePlayGamesAuthenticationState.SignedIn,
                    GooglePlayGamesAuthenticationFailure.None,
                    GooglePlayGamesAuthenticationResult.SignedIn,
                    GooglePlayGamesSessionStatus.GooglePlayGamesConnected);
            }
            catch (Exception)
            {
                CompleteAttempt(
                    completion,
                    GooglePlayGamesAuthenticationState.Failed,
                    GooglePlayGamesAuthenticationFailure.UnityAuthentication,
                    GooglePlayGamesAuthenticationResult.Failed,
                    restoreCachedSession
                        ? GooglePlayGamesSessionStatus.RestorationFailed
                        : GooglePlayGamesSessionStatus.Unavailable);
            }
        }

        private async Task RestoreCachedSessionAsync(
            TaskCompletionSource<GooglePlayGamesAuthenticationResult>
                completion)
        {
            if (!runtime.HasCachedSessionToken)
            {
                CompleteAttempt(
                    completion,
                    GooglePlayGamesAuthenticationState.Failed,
                    GooglePlayGamesAuthenticationFailure
                        .CachedSessionUnavailable,
                    GooglePlayGamesAuthenticationResult.Failed,
                    GooglePlayGamesSessionStatus.NotConnected);
                return;
            }

            GooglePlayGamesSessionStatus restoredStatus;
            try
            {
                restoredStatus = await runtime.RestoreCachedSessionAsync();
            }
            catch (Exception)
            {
                CompleteAttempt(
                    completion,
                    GooglePlayGamesAuthenticationState.Failed,
                    GooglePlayGamesAuthenticationFailure.SessionRestoration,
                    GooglePlayGamesAuthenticationResult.Failed,
                    GooglePlayGamesSessionStatus.RestorationFailed);
                return;
            }

            if (restoredStatus ==
                GooglePlayGamesSessionStatus.GooglePlayGamesConnected)
            {
                CompleteAttempt(
                    completion,
                    GooglePlayGamesAuthenticationState.SignedIn,
                    GooglePlayGamesAuthenticationFailure.None,
                    GooglePlayGamesAuthenticationResult.SignedIn,
                    restoredStatus);
                return;
            }

            if (restoredStatus ==
                GooglePlayGamesSessionStatus.SignedInUnverified)
            {
                CompleteAttempt(
                    completion,
                    GooglePlayGamesAuthenticationState.SignedInUnverified,
                    GooglePlayGamesAuthenticationFailure.None,
                    GooglePlayGamesAuthenticationResult.Unverified,
                    restoredStatus);
                return;
            }

            CompleteAttempt(
                completion,
                GooglePlayGamesAuthenticationState.Failed,
                GooglePlayGamesAuthenticationFailure.SessionRestoration,
                GooglePlayGamesAuthenticationResult.Failed,
                GooglePlayGamesSessionStatus.RestorationFailed);
        }

        private void CompleteAttempt(
            TaskCompletionSource<GooglePlayGamesAuthenticationResult>
                completion,
            GooglePlayGamesAuthenticationState completedState,
            GooglePlayGamesAuthenticationFailure completedFailure,
            GooglePlayGamesAuthenticationResult result,
            GooglePlayGamesSessionStatus? completedSessionStatus = null)
        {
            lock (gate)
            {
                state = completedState;
                failure = completedFailure;
                if (completedSessionStatus.HasValue)
                {
                    sessionStatus = completedSessionStatus.Value;
                }
                if (ReferenceEquals(activeAttempt, completion.Task))
                    activeAttempt = null;
                completion.TrySetResult(result);
            }

            NotifyStateChanged();
        }

        private void NotifyStateChanged()
        {
            Action listeners = StateChanged;
            if (listeners == null)
                return;

            foreach (Action listener in listeners.GetInvocationList())
            {
                try
                {
                    listener();
                }
                catch (Exception)
                {
                    Debug.LogWarning(
                        "An authentication state listener failed.");
                }
            }
        }
    }
}
