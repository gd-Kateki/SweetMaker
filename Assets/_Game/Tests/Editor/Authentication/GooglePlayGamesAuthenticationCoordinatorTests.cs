using System;
using System.Threading.Tasks;
using GooglePlayGames;
using NUnit.Framework;
using UnityEditor;
using UnityEngine;

namespace SweetMerge.Authentication.Tests
{
    public sealed class GooglePlayGamesAuthenticationCoordinatorTests
    {
        private const string DevelopmentWebClientId =
            "123456789012-testdevelopment.apps.googleusercontent.com";
        private const string ProductionWebClientId =
            "123456789012-testproduction.apps.googleusercontent.com";

        private sealed class FakeRuntime :
            IGooglePlayGamesAuthenticationRuntime
        {
            public Task InitializationTask = Task.CompletedTask;
            public Task<PlayGamesAuthenticationStatus> PlayGamesTask =
                Task.FromResult(PlayGamesAuthenticationStatus.Success);
            public Task<string> AuthorizationCodeTask =
                Task.FromResult("test-authorization-code");
            public Task UnityAuthenticationTask = Task.CompletedTask;
            public Task<GooglePlayGamesSessionStatus> RestorationTask =
                Task.FromResult(
                    GooglePlayGamesSessionStatus.GooglePlayGamesConnected);
            public Task<GooglePlayGamesSessionStatus> SessionRefreshTask;
            public GooglePlayGamesSessionStatus SessionStatus =
                GooglePlayGamesSessionStatus.NotConnected;
            public bool CachedSessionTokenExists { get; set; }

            public int InitializationCount { get; private set; }
            public int CachedSessionRestorationCount { get; private set; }
            public int PlayGamesAuthenticationCount { get; private set; }
            public int AuthorizationCodeRequestCount { get; private set; }
            public int UnityAuthenticationCount { get; private set; }
            public int SessionStatusRefreshCount { get; private set; }
            public bool? ForceRefreshToken { get; private set; }

            public Task InitializeUnityServicesAsync()
            {
                InitializationCount++;
                return InitializationTask;
            }

            public bool HasCachedSessionToken =>
                CachedSessionTokenExists;

            public Task<GooglePlayGamesSessionStatus>
                RestoreCachedSessionAsync()
            {
                CachedSessionRestorationCount++;
                return RestorationTask;
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

            public Task<GooglePlayGamesSessionStatus>
                RefreshSessionStatusAsync()
            {
                SessionStatusRefreshCount++;
                if (SessionStatusRefreshCount == 1 &&
                    SessionRefreshTask != null)
                {
                    return SessionRefreshTask;
                }

                return Task.FromResult(SessionStatus);
            }
        }

        [Test]
        public void WebClientResolverUsesExactDevelopmentPackageMapping()
        {
            Assert.AreEqual(
                DevelopmentWebClientId,
                GooglePlayGamesWebClientResolver.Resolve(
                    GooglePlayGamesWebClientResolver
                        .DevelopmentApplicationIdentifier,
                    DevelopmentWebClientId,
                    ProductionWebClientId));
        }

        [Test]
        public void WebClientResolverUsesExactProductionPackageMapping()
        {
            Assert.AreEqual(
                ProductionWebClientId,
                GooglePlayGamesWebClientResolver.Resolve(
                    GooglePlayGamesWebClientResolver
                        .ProductionApplicationIdentifier,
                    DevelopmentWebClientId,
                    ProductionWebClientId));
        }

        [Test]
        public void WebClientResolverRejectsUnknownPackage()
        {
            Assert.Throws<InvalidOperationException>(() =>
                GooglePlayGamesWebClientResolver.Resolve(
                    "com.example.unknown",
                    DevelopmentWebClientId,
                    ProductionWebClientId));
        }

        [TestCase(null)]
        [TestCase("")]
        [TestCase("not-a-client-id")]
        public void WebClientResolverRejectsMissingOrMalformedDevelopmentId(
            string clientId)
        {
            Assert.Throws<InvalidOperationException>(() =>
                GooglePlayGamesWebClientResolver.Resolve(
                    GooglePlayGamesWebClientResolver
                        .DevelopmentApplicationIdentifier,
                    clientId,
                    ProductionWebClientId));
        }

        [TestCase(null)]
        [TestCase("")]
        [TestCase("not-a-client-id")]
        public void WebClientResolverRejectsMissingOrMalformedProductionId(
            string clientId)
        {
            Assert.Throws<InvalidOperationException>(() =>
                GooglePlayGamesWebClientResolver.Resolve(
                    GooglePlayGamesWebClientResolver
                        .ProductionApplicationIdentifier,
                    DevelopmentWebClientId,
                    clientId));
        }

        [Test]
        public void SelectedClientIsAppliedOnlyDuringServerSideRequest()
        {
            PlayGamesSettings settings =
                ScriptableObject.CreateInstance<PlayGamesSettings>();
            settings.WebClientId = DevelopmentWebClientId;
            string selectedClientId = null;
            bool wasDirty = EditorUtility.IsDirty(settings);
            bool wasPersistent = AssetDatabase.Contains(settings);
            Assert.IsFalse(wasPersistent);

            try
            {
                GooglePlayGamesWebClientResolver.InvokeWithSelectedClient(
                    GooglePlayGamesWebClientResolver
                        .ProductionApplicationIdentifier,
                    settings,
                    ProductionWebClientId,
                    () => selectedClientId = settings.WebClientId);

                Assert.AreEqual(ProductionWebClientId, selectedClientId);
                Assert.AreEqual(
                    DevelopmentWebClientId,
                    settings.WebClientId);
                Assert.AreEqual(wasDirty, EditorUtility.IsDirty(settings));
                Assert.AreEqual(
                    wasPersistent,
                    AssetDatabase.Contains(settings));
            }
            finally
            {
                UnityEngine.Object.DestroyImmediate(settings);
            }
        }

        [Test]
        public void SelectedClientIsRestoredWhenServerSideRequestThrows()
        {
            PlayGamesSettings settings =
                ScriptableObject.CreateInstance<PlayGamesSettings>();
            settings.WebClientId = DevelopmentWebClientId;

            try
            {
                Assert.Throws<InvalidOperationException>(() =>
                    GooglePlayGamesWebClientResolver.InvokeWithSelectedClient(
                        GooglePlayGamesWebClientResolver
                            .ProductionApplicationIdentifier,
                        settings,
                        ProductionWebClientId,
                        () => throw new InvalidOperationException()));
                Assert.AreEqual(
                    DevelopmentWebClientId,
                    settings.WebClientId);
            }
            finally
            {
                UnityEngine.Object.DestroyImmediate(settings);
            }
        }

        [TestCase(29, false, 36, false, null)]
        [TestCase(28, false, 36, false,
            "Release Android builds require minimum API level 29.")]
        [TestCase(29, true, null, false, null)]
        [TestCase(29, false, 35, false,
            "Release Android builds require Automatic or target API level 36.")]
        [TestCase(29, false, 37, false,
            "Release Android builds require Automatic or target API level 36.")]
        [TestCase(32, true, null, true, null)]
        [TestCase(32, false, 33, true, null)]
        public void AndroidBuildRequirementsValidateMinimumAndTargetApi(
            int minimumApiLevel,
            bool targetApiIsAutomatic,
            int? targetApiLevel,
            bool developmentBuild,
            string expectedError)
        {
            Assert.AreEqual(
                expectedError,
                GooglePlayGamesAndroidBuildRequirements.ValidateApiLevels(
                    minimumApiLevel,
                    targetApiIsAutomatic,
                    targetApiLevel,
                    developmentBuild));
        }

        [Test]
        public void UnconfiguredProductionClientFailsClosed()
        {
            Assert.Throws<InvalidOperationException>(() =>
                GooglePlayGamesWebClientResolver.Resolve(
                    GooglePlayGamesWebClientResolver
                        .ProductionApplicationIdentifier,
                    DevelopmentWebClientId,
                    null));
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

        [Test]
        public async Task RefreshingSessionDoesNotInitializeOrSignIn()
        {
            var runtime = new FakeRuntime
            {
                SessionStatus =
                    GooglePlayGamesSessionStatus.SignedInUnverified
            };
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);
            int stateChangeCount = 0;
            coordinator.StateChanged += () => stateChangeCount++;

            GooglePlayGamesSessionStatus status =
                await coordinator.RefreshSessionStatusAsync();

            Assert.AreEqual(
                GooglePlayGamesSessionStatus.SignedInUnverified,
                status);
            Assert.AreEqual(status, coordinator.SessionStatus);
            Assert.AreEqual(0, runtime.InitializationCount);
            Assert.AreEqual(0, runtime.PlayGamesAuthenticationCount);
            Assert.AreEqual(1, runtime.SessionStatusRefreshCount);
            Assert.AreEqual(1, stateChangeCount);
        }

        [Test]
        public async Task SuccessfulSignInNotifiesStateListeners()
        {
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(
                    new FakeRuntime());
            int stateChangeCount = 0;
            coordinator.StateChanged += () => stateChangeCount++;

            await coordinator.SignInAsync();

            Assert.AreEqual(2, stateChangeCount);
            Assert.AreEqual(
                GooglePlayGamesSessionStatus.GooglePlayGamesConnected,
                coordinator.SessionStatus);
        }

        [Test]
        public async Task CachedSessionIsDetectedWithoutAutomaticRestoration()
        {
            var runtime = new FakeRuntime
            {
                SessionStatus =
                    GooglePlayGamesSessionStatus.PreviousSessionAvailable
            };
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);

            Assert.AreEqual(
                GooglePlayGamesSessionStatus.PreviousSessionAvailable,
                await coordinator.RefreshSessionStatusAsync());
            Assert.AreEqual(0, runtime.InitializationCount);
            Assert.AreEqual(0, runtime.CachedSessionRestorationCount);
            Assert.AreEqual(0, runtime.PlayGamesAuthenticationCount);
        }

        [Test]
        public async Task ManualSignInDoesNotReplaceCachedUnitySession()
        {
            var runtime = new FakeRuntime
            {
                CachedSessionTokenExists = true,
                SessionStatus =
                    GooglePlayGamesSessionStatus.PreviousSessionAvailable
            };
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);

            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.Failed,
                await coordinator.SignInAsync());

            Assert.AreEqual(
                GooglePlayGamesAuthenticationFailure.CachedSessionAvailable,
                coordinator.Failure);
            Assert.AreEqual(
                GooglePlayGamesSessionStatus.PreviousSessionAvailable,
                coordinator.SessionStatus);
            Assert.AreEqual(0, runtime.CachedSessionRestorationCount);
            Assert.AreEqual(0, runtime.PlayGamesAuthenticationCount);
        }

        [Test]
        public async Task RestorationRequiresCachedTokenAndCannotCreateAccount()
        {
            var runtime = new FakeRuntime();
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);

            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.Failed,
                await coordinator.RestoreSessionAsync());

            Assert.AreEqual(
                GooglePlayGamesAuthenticationFailure.CachedSessionUnavailable,
                coordinator.Failure);
            Assert.AreEqual(
                GooglePlayGamesSessionStatus.NotConnected,
                coordinator.SessionStatus);
            Assert.AreEqual(1, runtime.InitializationCount);
            Assert.AreEqual(0, runtime.CachedSessionRestorationCount);
            Assert.AreEqual(0, runtime.PlayGamesAuthenticationCount);
            Assert.AreEqual(0, runtime.UnityAuthenticationCount);
        }

        [Test]
        public async Task ExplicitRestorationCanVerifyCachedPlayGamesSession()
        {
            var runtime = new FakeRuntime
            {
                CachedSessionTokenExists = true,
                SessionStatus =
                    GooglePlayGamesSessionStatus.PreviousSessionAvailable
            };
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);

            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.SignedIn,
                await coordinator.RestoreSessionAsync());

            Assert.AreEqual(
                GooglePlayGamesSessionStatus.GooglePlayGamesConnected,
                coordinator.SessionStatus);
            Assert.AreEqual(1, runtime.InitializationCount);
            Assert.AreEqual(1, runtime.CachedSessionRestorationCount);
            Assert.AreEqual(0, runtime.PlayGamesAuthenticationCount);
            Assert.AreEqual(0, runtime.UnityAuthenticationCount);
        }

        [Test]
        public async Task RestoredSessionWithUnknownProviderRemainsUnverified()
        {
            var runtime = new FakeRuntime
            {
                CachedSessionTokenExists = true,
                SessionStatus =
                    GooglePlayGamesSessionStatus.PreviousSessionAvailable,
                RestorationTask = Task.FromResult(
                    GooglePlayGamesSessionStatus.SignedInUnverified)
            };
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);

            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.Unverified,
                await coordinator.RestoreSessionAsync());
            Assert.AreEqual(
                GooglePlayGamesAuthenticationState.SignedInUnverified,
                coordinator.State);
            Assert.AreEqual(
                GooglePlayGamesSessionStatus.SignedInUnverified,
                coordinator.SessionStatus);
            Assert.AreEqual(0, runtime.PlayGamesAuthenticationCount);
        }

        [Test]
        public async Task RestorationFailureCanBeRetried()
        {
            var runtime = new FakeRuntime
            {
                CachedSessionTokenExists = true,
                SessionStatus =
                    GooglePlayGamesSessionStatus.PreviousSessionAvailable,
                RestorationTask = Task.FromException<
                    GooglePlayGamesSessionStatus>(
                    new InvalidOperationException("restore failed"))
            };
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);

            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.Failed,
                await coordinator.RestoreSessionAsync());
            Assert.AreEqual(
                GooglePlayGamesSessionStatus.RestorationFailed,
                coordinator.SessionStatus);

            runtime.RestorationTask = Task.FromResult(
                GooglePlayGamesSessionStatus.GooglePlayGamesConnected);

            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.SignedIn,
                await coordinator.RestoreSessionAsync());
            Assert.AreEqual(2, runtime.CachedSessionRestorationCount);
        }

        [Test]
        public async Task RestoreAndManualSignInShareOneActiveAttempt()
        {
            var restorationCompletion =
                new TaskCompletionSource<GooglePlayGamesSessionStatus>(
                    TaskCreationOptions.RunContinuationsAsynchronously);
            var runtime = new FakeRuntime
            {
                CachedSessionTokenExists = true,
                SessionStatus =
                    GooglePlayGamesSessionStatus.PreviousSessionAvailable,
                RestorationTask = restorationCompletion.Task
            };
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);

            Task<GooglePlayGamesAuthenticationResult> restoration =
                coordinator.RestoreSessionAsync();
            Task<GooglePlayGamesAuthenticationResult> manualSignIn =
                coordinator.SignInAsync();

            Assert.AreSame(restoration, manualSignIn);
            Assert.AreEqual(1, runtime.CachedSessionRestorationCount);
            Assert.AreEqual(0, runtime.PlayGamesAuthenticationCount);

            restorationCompletion.SetResult(
                GooglePlayGamesSessionStatus.GooglePlayGamesConnected);
            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.SignedIn,
                await restoration);
        }

        [Test]
        public async Task StaleRefreshCannotOverwriteSignIn()
        {
            var refreshCompletion =
                new TaskCompletionSource<GooglePlayGamesSessionStatus>(
                    TaskCreationOptions.RunContinuationsAsynchronously);
            var runtime = new FakeRuntime
            {
                SessionStatus =
                    GooglePlayGamesSessionStatus.GooglePlayGamesConnected,
                SessionRefreshTask = refreshCompletion.Task
            };
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);

            Task<GooglePlayGamesSessionStatus> refresh =
                coordinator.RefreshSessionStatusAsync();
            runtime.SessionStatus = GooglePlayGamesSessionStatus
                .GooglePlayGamesConnected;
            Task<GooglePlayGamesAuthenticationResult> signIn =
                coordinator.SignInAsync();

            refreshCompletion.SetResult(
                GooglePlayGamesSessionStatus.PreviousSessionAvailable);
            Assert.AreEqual(
                GooglePlayGamesAuthenticationResult.SignedIn,
                await signIn);
            Assert.AreEqual(
                GooglePlayGamesSessionStatus.GooglePlayGamesConnected,
                await refresh);
            Assert.AreEqual(
                GooglePlayGamesSessionStatus.GooglePlayGamesConnected,
                coordinator.SessionStatus);
        }
        [Test]
        public async Task RefreshSessionStatusPreservesFailedStateWhenNotConnected()
        {
            var runtime = new FakeRuntime
            {
                PlayGamesTask = Task.FromResult(
                    PlayGamesAuthenticationStatus.Failed),
                SessionStatus = GooglePlayGamesSessionStatus.NotConnected
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
                GooglePlayGamesAuthenticationFailure.PlayGamesAuthentication,
                coordinator.Failure);

            GooglePlayGamesSessionStatus refreshedStatus =
                await coordinator.RefreshSessionStatusAsync();

            Assert.AreEqual(
                GooglePlayGamesSessionStatus.NotConnected,
                refreshedStatus);
            Assert.AreEqual(
                GooglePlayGamesAuthenticationState.Failed,
                coordinator.State);
            Assert.AreEqual(
                GooglePlayGamesAuthenticationFailure.PlayGamesAuthentication,
                coordinator.Failure);
        }

        [Test]
        public async Task RefreshSessionStatusPreservesCancelledStateWhenNotConnected()
        {
            var runtime = new FakeRuntime
            {
                PlayGamesTask = Task.FromResult(
                    PlayGamesAuthenticationStatus.Cancelled),
                SessionStatus = GooglePlayGamesSessionStatus.NotConnected
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

            GooglePlayGamesSessionStatus refreshedStatus =
                await coordinator.RefreshSessionStatusAsync();

            Assert.AreEqual(
                GooglePlayGamesSessionStatus.NotConnected,
                refreshedStatus);
            Assert.AreEqual(
                GooglePlayGamesAuthenticationState.Cancelled,
                coordinator.State);
            Assert.AreEqual(
                GooglePlayGamesAuthenticationFailure.None,
                coordinator.Failure);
        }

        [Test]
        public async Task RefreshSessionStatusTransitionsSignedInUnverifiedToSignedOutWhenNotConnected()
        {
            var runtime = new FakeRuntime
            {
                SessionStatus =
                    GooglePlayGamesSessionStatus.SignedInUnverified
            };
            var coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);

            Assert.AreEqual(
                GooglePlayGamesSessionStatus.SignedInUnverified,
                await coordinator.RefreshSessionStatusAsync());
            Assert.AreEqual(
                GooglePlayGamesAuthenticationState.SignedInUnverified,
                coordinator.State);

            runtime.SessionStatus = GooglePlayGamesSessionStatus.NotConnected;

            GooglePlayGamesSessionStatus refreshedStatus =
                await coordinator.RefreshSessionStatusAsync();

            Assert.AreEqual(
                GooglePlayGamesSessionStatus.NotConnected,
                refreshedStatus);
            Assert.AreEqual(
                GooglePlayGamesAuthenticationState.SignedOut,
                coordinator.State);
            Assert.AreEqual(
                GooglePlayGamesAuthenticationFailure.None,
                coordinator.Failure);
        }
    }
}
