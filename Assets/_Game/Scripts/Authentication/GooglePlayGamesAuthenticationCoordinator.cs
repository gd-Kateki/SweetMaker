using System;
using System.Threading.Tasks;
using GooglePlayGames;
using GooglePlayGames.BasicApi;
using SweetMerge.Analytics;
using Unity.Services.Authentication;
using UnityEngine;

namespace SweetMerge.Authentication
{
    public enum GooglePlayGamesAuthenticationState
    {
        SignedOut,
        SigningIn,
        SignedIn,
        Failed,
        Cancelled
    }

    public enum GooglePlayGamesAuthenticationFailure
    {
        None,
        UnityServicesInitialization,
        PlayGamesAuthentication,
        AuthorizationCodeUnavailable,
        UnityAuthentication
    }

    public enum GooglePlayGamesAuthenticationResult
    {
        SignedIn,
        Failed,
        Cancelled
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
        Task<PlayGamesAuthenticationStatus> AuthenticateWithPlayGamesAsync();
        Task<string> RequestServerSideAccessAsync(bool forceRefreshToken);
        Task SignInWithUnityAuthenticationAsync(string authCode);
    }

    public sealed class GooglePlayGamesAuthenticationCoordinator
    {
        private sealed class UnityAuthenticationRuntime :
            IGooglePlayGamesAuthenticationRuntime
        {
            public Task InitializeUnityServicesAsync() =>
                UnityServicesInitializer.InitializeAsync();

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

                PlayGamesPlatform.Instance.RequestServerSideAccess(
                    forceRefreshToken,
                    authCode => completion.TrySetResult(authCode));

                return completion.Task;
            }

            public Task SignInWithUnityAuthenticationAsync(string authCode) =>
                AuthenticationService.Instance
                    .SignInWithGooglePlayGamesAsync(authCode);
        }

        private static readonly object InstanceGate = new object();
        private static GooglePlayGamesAuthenticationCoordinator instance;

        private readonly object gate = new object();
        private readonly IGooglePlayGamesAuthenticationRuntime runtime;
        private Task<GooglePlayGamesAuthenticationResult> activeAttempt;
        private GooglePlayGamesAuthenticationState state =
            GooglePlayGamesAuthenticationState.SignedOut;
        private GooglePlayGamesAuthenticationFailure failure =
            GooglePlayGamesAuthenticationFailure.None;

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
                completion =
                    new TaskCompletionSource<
                        GooglePlayGamesAuthenticationResult>(
                        TaskCreationOptions.RunContinuationsAsynchronously);
                activeAttempt = completion.Task;
            }

            _ = RunAttemptAsync(completion);
            return completion.Task;
        }

        private async Task RunAttemptAsync(
            TaskCompletionSource<GooglePlayGamesAuthenticationResult>
                completion)
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
                        GooglePlayGamesAuthenticationResult.Failed);
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
                    GooglePlayGamesAuthenticationResult.SignedIn);
            }
            catch (Exception)
            {
                CompleteAttempt(
                    completion,
                    GooglePlayGamesAuthenticationState.Failed,
                    GooglePlayGamesAuthenticationFailure.UnityAuthentication,
                    GooglePlayGamesAuthenticationResult.Failed);
            }
        }

        private void CompleteAttempt(
            TaskCompletionSource<GooglePlayGamesAuthenticationResult>
                completion,
            GooglePlayGamesAuthenticationState completedState,
            GooglePlayGamesAuthenticationFailure completedFailure,
            GooglePlayGamesAuthenticationResult result)
        {
            lock (gate)
            {
                state = completedState;
                failure = completedFailure;
                if (ReferenceEquals(activeAttempt, completion.Task))
                    activeAttempt = null;
                completion.TrySetResult(result);
            }
        }
    }
}
