using System;
using System.Threading.Tasks;
using NUnit.Framework;

namespace SweetMerge.Authentication.Tests
{
    public sealed class GooglePlayGamesAuthenticationCoordinatorTests
    {
        private sealed class FakeRuntime :
            IGooglePlayGamesAuthenticationRuntime
        {
            public Task InitializationTask = Task.CompletedTask;
            public Task<PlayGamesAuthenticationStatus> PlayGamesTask =
                Task.FromResult(PlayGamesAuthenticationStatus.Success);
            public Task<string> AuthorizationCodeTask =
                Task.FromResult("test-authorization-code");
            public Task UnityAuthenticationTask = Task.CompletedTask;

            public int InitializationCount { get; private set; }
            public int PlayGamesAuthenticationCount { get; private set; }
            public int AuthorizationCodeRequestCount { get; private set; }
            public int UnityAuthenticationCount { get; private set; }
            public bool? ForceRefreshToken { get; private set; }

            public Task InitializeUnityServicesAsync()
            {
                InitializationCount++;
                return InitializationTask;
            }

            public Task<PlayGamesAuthenticationStatus>
                AuthenticateWithPlayGamesAsync()
            {
                PlayGamesAuthenticationCount++;
                return PlayGamesTask;
            }

            public Task<string> RequestServerSideAccessAsync(
                bool forceRefreshToken)
            {
                AuthorizationCodeRequestCount++;
                ForceRefreshToken = forceRefreshToken;
                return AuthorizationCodeTask;
            }

            public Task SignInWithUnityAuthenticationAsync(string authCode)
            {
                UnityAuthenticationCount++;
                return UnityAuthenticationTask;
            }
        }

        [Test]
        public void ConstructionDoesNotStartSignIn()
        {
            var runtime = new FakeRuntime();
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);

            Assert.AreEqual(
                GooglePlayGamesAuthenticationState.SignedOut,
                coordinator.State);
            Assert.AreEqual(0, runtime.InitializationCount);
            Assert.AreEqual(0, runtime.PlayGamesAuthenticationCount);
            Assert.AreEqual(0, runtime.AuthorizationCodeRequestCount);
            Assert.AreEqual(0, runtime.UnityAuthenticationCount);
        }

        [Test]
        public async Task ConcurrentRequestsShareOneAttempt()
        {
            var authenticationCompletion =
                new TaskCompletionSource<PlayGamesAuthenticationStatus>(
                    TaskCreationOptions.RunContinuationsAsynchronously);
            var runtime = new FakeRuntime
            {
                PlayGamesTask = authenticationCompletion.Task
            };
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);

            Task<GooglePlayGamesAuthenticationResult> first =
                coordinator.SignInAsync();
            Task<GooglePlayGamesAuthenticationResult> second =
                coordinator.SignInAsync();

            Assert.AreSame(first, second);
            Assert.AreEqual(
                GooglePlayGamesAuthenticationState.SigningIn,
                coordinator.State);
            Assert.AreEqual(1, runtime.InitializationCount);
            Assert.AreEqual(1, runtime.PlayGamesAuthenticationCount);
            Assert.AreEqual(0, runtime.AuthorizationCodeRequestCount);

            authenticationCompletion.SetResult(
                PlayGamesAuthenticationStatus.Success);

            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.SignedIn,
                await first);
            Assert.AreEqual(1, runtime.InitializationCount);
            Assert.AreEqual(1, runtime.PlayGamesAuthenticationCount);
            Assert.AreEqual(1, runtime.AuthorizationCodeRequestCount);
            Assert.AreEqual(false, runtime.ForceRefreshToken);
            Assert.AreEqual(1, runtime.UnityAuthenticationCount);
        }

        [Test]
        public async Task InitializationFailureCanBeRetried()
        {
            var runtime = new FakeRuntime
            {
                InitializationTask = Task.FromException(
                    new InvalidOperationException("initialization failed"))
            };
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);

            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.Failed,
                await coordinator.SignInAsync());
            Assert.AreEqual(
                GooglePlayGamesAuthenticationState.Failed,
                coordinator.State);
            Assert.AreEqual(
                GooglePlayGamesAuthenticationFailure
                    .UnityServicesInitialization,
                coordinator.Failure);
            Assert.AreEqual(0, runtime.PlayGamesAuthenticationCount);

            runtime.InitializationTask = Task.CompletedTask;

            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.SignedIn,
                await coordinator.SignInAsync());
            Assert.AreEqual(2, runtime.InitializationCount);
            Assert.AreEqual(1, runtime.PlayGamesAuthenticationCount);
        }

        [Test]
        public async Task PlayGamesAuthenticationFailureIsNonfatal()
        {
            var runtime = new FakeRuntime
            {
                PlayGamesTask = Task.FromResult(
                    PlayGamesAuthenticationStatus.Failed)
            };
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);

            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.Failed,
                await coordinator.SignInAsync());
            Assert.AreEqual(
                GooglePlayGamesAuthenticationFailure.PlayGamesAuthentication,
                coordinator.Failure);
            Assert.AreEqual(0, runtime.AuthorizationCodeRequestCount);
            Assert.AreEqual(0, runtime.UnityAuthenticationCount);
        }

        [Test]
        public async Task PlayGamesSdkExceptionIsNonfatalAndRetryable()
        {
            var runtime = new FakeRuntime
            {
                PlayGamesTask = Task.FromException<PlayGamesAuthenticationStatus>(
                    new InvalidOperationException("sign-in failed"))
            };
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);

            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.Failed,
                await coordinator.SignInAsync());
            Assert.AreEqual(
                GooglePlayGamesAuthenticationFailure.PlayGamesAuthentication,
                coordinator.Failure);

            runtime.PlayGamesTask = Task.FromResult(
                PlayGamesAuthenticationStatus.Success);

            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.SignedIn,
                await coordinator.SignInAsync());
            Assert.AreEqual(2, runtime.PlayGamesAuthenticationCount);
        }

        [TestCase(null)]
        [TestCase("")]
        [TestCase(" \t")]
        public async Task EmptyAuthorizationCodeIsRejected(string authCode)
        {
            var runtime = new FakeRuntime
            {
                AuthorizationCodeTask = Task.FromResult(authCode)
            };
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);

            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.Failed,
                await coordinator.SignInAsync());
            Assert.AreEqual(
                GooglePlayGamesAuthenticationFailure
                    .AuthorizationCodeUnavailable,
                coordinator.Failure);
            Assert.AreEqual(0, runtime.UnityAuthenticationCount);
        }

        [Test]
        public async Task AuthorizationCodeRequestFailureIsNonfatalAndRetryable()
        {
            var runtime = new FakeRuntime
            {
                AuthorizationCodeTask = Task.FromException<string>(
                    new InvalidOperationException("authorization-code request failed"))
            };
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);

            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.Failed,
                await coordinator.SignInAsync());
            Assert.AreEqual(
                GooglePlayGamesAuthenticationFailure
                    .AuthorizationCodeUnavailable,
                coordinator.Failure);
            Assert.AreEqual(0, runtime.UnityAuthenticationCount);

            runtime.AuthorizationCodeTask =
                Task.FromResult("test-authorization-code");

            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.SignedIn,
                await coordinator.SignInAsync());
            Assert.AreEqual(2, runtime.AuthorizationCodeRequestCount);
            Assert.AreEqual(1, runtime.UnityAuthenticationCount);
        }

        [Test]
        public async Task UnityAuthenticationFailureIsNonfatalAndRetryable()
        {
            var runtime = new FakeRuntime
            {
                UnityAuthenticationTask = Task.FromException(
                    new InvalidOperationException("exchange failed"))
            };
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);

            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.Failed,
                await coordinator.SignInAsync());
            Assert.AreEqual(
                GooglePlayGamesAuthenticationFailure.UnityAuthentication,
                coordinator.Failure);

            runtime.UnityAuthenticationTask = Task.CompletedTask;

            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.SignedIn,
                await coordinator.SignInAsync());
            Assert.AreEqual(2, runtime.PlayGamesAuthenticationCount);
            Assert.AreEqual(2, runtime.AuthorizationCodeRequestCount);
            Assert.AreEqual(2, runtime.UnityAuthenticationCount);
        }

        [Test]
        public async Task PlayGamesCancellationIsReportedAsCancelled()
        {
            var runtime = new FakeRuntime
            {
                PlayGamesTask = Task.FromResult(
                    PlayGamesAuthenticationStatus.Cancelled)
            };
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);

            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.Cancelled,
                await coordinator.SignInAsync());
            Assert.AreEqual(
                GooglePlayGamesAuthenticationState.Cancelled,
                coordinator.State);
            Assert.AreEqual(
                GooglePlayGamesAuthenticationFailure.None,
                coordinator.Failure);
            Assert.AreEqual(0, runtime.AuthorizationCodeRequestCount);
        }

        [Test]
        public async Task SignInDoesNotRequireAnalyticsConsentOrSaveRuntime()
        {
            var runtime = new FakeRuntime();
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);

            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.SignedIn,
                await coordinator.SignInAsync());

            Assert.AreEqual(1, runtime.InitializationCount);
            Assert.AreEqual(1, runtime.PlayGamesAuthenticationCount);
            Assert.AreEqual(1, runtime.UnityAuthenticationCount);
            Assert.AreEqual(
                GooglePlayGamesAuthenticationState.SignedIn,
                coordinator.State);
        }
    }
}
