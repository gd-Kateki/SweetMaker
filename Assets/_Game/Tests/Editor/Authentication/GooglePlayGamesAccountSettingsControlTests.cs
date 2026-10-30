using System;
using System.Reflection;
using System.Threading.Tasks;
using NUnit.Framework;
using UnityEngine;

namespace SweetMerge.Authentication.Tests
{
    public sealed class GooglePlayGamesAccountSettingsControlTests
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
            public Task<GooglePlayGamesSessionStatus> RestorationTask =
                Task.FromResult(
                    GooglePlayGamesSessionStatus.GooglePlayGamesConnected);
            public GooglePlayGamesSessionStatus SessionStatus =
                GooglePlayGamesSessionStatus.NotConnected;
            public bool CachedSessionTokenExists { get; set; }

            public int InitializationCount { get; private set; }
            public int CachedSessionRestorationCount { get; private set; }
            public int PlayGamesAuthenticationCount { get; private set; }
            public int AuthorizationCodeRequestCount { get; private set; }
            public int UnityAuthenticationCount { get; private set; }
            public int SessionStatusRefreshCount { get; private set; }

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
                Assert.IsFalse(forceRefreshToken);
                AuthorizationCodeRequestCount++;
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
                return Task.FromResult(SessionStatus);
            }
        }

        private GameObject settingsContentObject;
        private GooglePlayGamesAccountSettingsControl control;
        private FakeRuntime runtime;
        private GooglePlayGamesAuthenticationCoordinator coordinator;

        [TearDown]
        public void TearDown()
        {
            if (settingsContentObject != null)
                UnityEngine.Object.DestroyImmediate(settingsContentObject);
        }

        [Test]
        public async Task AttachDoesNotSignInAndShowsLocalProgressClarification()
        {
            await CreateControlAsync();

            Assert.AreEqual(0, runtime.InitializationCount);
            Assert.AreEqual(0, runtime.CachedSessionRestorationCount);
            Assert.AreEqual(0, runtime.PlayGamesAuthenticationCount);
            Assert.AreEqual(0, runtime.UnityAuthenticationCount);
            Assert.AreEqual("Not connected.", control.StatusText.text);
            StringAssert.Contains(
                "saved locally",
                control.LocalProgressText.text);
            Assert.IsTrue(control.ConnectButton.interactable);
        }

        [Test]
        public async Task ConnectButtonStartsSignInAndDisablesWhilePending()
        {
            var signInCompletion =
                new TaskCompletionSource<PlayGamesAuthenticationStatus>(
                    TaskCreationOptions.RunContinuationsAsynchronously);
            await CreateControlAsync();
            runtime.PlayGamesTask = signInCompletion.Task;

            control.ConnectButton.onClick.Invoke();

            Assert.AreEqual(1, runtime.InitializationCount);
            Assert.AreEqual(1, runtime.PlayGamesAuthenticationCount);
            Assert.AreEqual(
                "Connecting to Google Play Games...",
                control.StatusText.text);
            Assert.IsFalse(control.ConnectButton.interactable);

            signInCompletion.SetResult(PlayGamesAuthenticationStatus.Success);
            await control.InteractionTask;

            Assert.AreEqual(1, runtime.UnityAuthenticationCount);
            Assert.AreEqual(
                "Connected to Google Play Games.",
                control.StatusText.text);
            Assert.IsFalse(control.ConnectButton.interactable);
        }

        [Test]
        public async Task PreviousSessionIsRestoredAutomaticallyWhenSettingsOpens()
        {
            await CreateControlAsync(
                GooglePlayGamesSessionStatus.PreviousSessionAvailable,
                cachedSessionTokenExists: true);

            Assert.AreEqual(1, runtime.InitializationCount);
            Assert.AreEqual(1, runtime.CachedSessionRestorationCount);
            Assert.AreEqual(0, runtime.PlayGamesAuthenticationCount);
            Assert.AreEqual(0, runtime.UnityAuthenticationCount);
            Assert.AreEqual(
                "Connected to Google Play Games.",
                control.StatusText.text);
        }

        [Test]
        public async Task RestorationShowsProgressAndDisablesButton()
        {
            var restorationCompletion =
                new TaskCompletionSource<GooglePlayGamesSessionStatus>(
                    TaskCreationOptions.RunContinuationsAsynchronously);
            await CreateControlAsync(
                GooglePlayGamesSessionStatus.PreviousSessionAvailable,
                cachedSessionTokenExists: true,
                restorationTask: restorationCompletion.Task);

            Assert.AreEqual(
                "Restoring your previous session...",
                control.StatusText.text);
            Assert.AreEqual("Restoring...", control.ConnectButton
                .GetComponentInChildren<TMPro.TMP_Text>().text);
            Assert.IsFalse(control.ConnectButton.interactable);

            restorationCompletion.SetResult(
                GooglePlayGamesSessionStatus.GooglePlayGamesConnected);
            await coordinator.RestoreSessionAsync();
            Assert.AreEqual(
                "Connected to Google Play Games.",
                control.StatusText.text);
        }

        [Test]
        public async Task RestorationFailureCanBeRetriedFromAccountControl()
        {
            await CreateControlAsync(
                GooglePlayGamesSessionStatus.PreviousSessionAvailable,
                cachedSessionTokenExists: true,
                restorationTask: Task.FromException<
                    GooglePlayGamesSessionStatus>(
                    new InvalidOperationException("restore failed")));

            Assert.AreEqual(
                GooglePlayGamesSessionStatus.RestorationFailed,
                coordinator.SessionStatus);
            StringAssert.Contains("Could not reconnect", control.FeedbackText.text);
            Assert.AreEqual("Reconnect", control.ConnectButton
                .GetComponentInChildren<TMPro.TMP_Text>().text);
            Assert.IsTrue(control.ConnectButton.interactable);

            await control.RefreshAsync();
            Assert.AreEqual(
                GooglePlayGamesSessionStatus.RestorationFailed,
                coordinator.SessionStatus);
            StringAssert.Contains("Could not reconnect", control.FeedbackText.text);
            Assert.AreEqual(1, runtime.CachedSessionRestorationCount);

            runtime.RestorationTask = Task.FromResult(
                GooglePlayGamesSessionStatus.GooglePlayGamesConnected);
            control.ConnectButton.onClick.Invoke();
            await control.InteractionTask;

            Assert.AreEqual(2, runtime.CachedSessionRestorationCount);
            Assert.AreEqual(
                "Connected to Google Play Games.",
                control.StatusText.text);
        }

        [Test]
        public async Task RepeatedRefreshDoesNotDuplicateAutomaticRestoration()
        {
            var restorationCompletion =
                new TaskCompletionSource<GooglePlayGamesSessionStatus>(
                    TaskCreationOptions.RunContinuationsAsynchronously);
            await CreateControlAsync(
                GooglePlayGamesSessionStatus.PreviousSessionAvailable,
                cachedSessionTokenExists: true,
                restorationTask: restorationCompletion.Task);

            await control.RefreshAsync();
            await control.RefreshAsync();
            Assert.AreEqual(1, runtime.CachedSessionRestorationCount);
            Assert.AreEqual(0, runtime.PlayGamesAuthenticationCount);

            Task restoration = coordinator.RestoreSessionAsync();
            restorationCompletion.SetResult(
                GooglePlayGamesSessionStatus.GooglePlayGamesConnected);
            await restoration;
            await control.RefreshAsync();

            Assert.AreEqual(1, runtime.CachedSessionRestorationCount);
            Assert.AreEqual(0, runtime.PlayGamesAuthenticationCount);
            Assert.AreEqual(
                "Connected to Google Play Games.",
                control.StatusText.text);
        }

        [Test]
        public async Task FailureIsGenericAndCanBeRetried()
        {
            await CreateControlAsync();
            runtime.PlayGamesTask = Task.FromResult(
                PlayGamesAuthenticationStatus.Failed);

            control.ConnectButton.onClick.Invoke();
            await control.InteractionTask;

            Assert.AreEqual(
                "Could not connect. You can continue playing offline. Please try again.",
                control.FeedbackText.text);
            Assert.IsTrue(control.ConnectButton.interactable);

            runtime.PlayGamesTask = Task.FromResult(
                PlayGamesAuthenticationStatus.Success);
            control.ConnectButton.onClick.Invoke();
            await control.InteractionTask;

            Assert.AreEqual(
                "Connected to Google Play Games.",
                control.StatusText.text);
        }

        [Test]
        public async Task CancellationIsShownAndCanBeRetried()
        {
            await CreateControlAsync();
            runtime.PlayGamesTask = Task.FromResult(
                PlayGamesAuthenticationStatus.Cancelled);

            control.ConnectButton.onClick.Invoke();
            await control.InteractionTask;

            Assert.AreEqual(
                "Sign-in cancelled. You can continue playing offline.",
                control.FeedbackText.text);
            Assert.IsTrue(control.ConnectButton.interactable);
        }

        [Test]
        public async Task ConcurrentButtonInteractionsStartOnlyOneAttempt()
        {
            var signInCompletion =
                new TaskCompletionSource<PlayGamesAuthenticationStatus>(
                    TaskCreationOptions.RunContinuationsAsynchronously);
            await CreateControlAsync();
            runtime.PlayGamesTask = signInCompletion.Task;

            control.ConnectButton.onClick.Invoke();
            Task firstInteraction = control.InteractionTask;
            control.ConnectButton.onClick.Invoke();

            Assert.AreEqual(1, runtime.PlayGamesAuthenticationCount);
            Assert.IsTrue(control.InteractionTask.IsCompleted);

            signInCompletion.SetResult(PlayGamesAuthenticationStatus.Success);
            await firstInteraction;
        }

        [Test]
        public async Task SessionRefreshIsReadOnlyAndUnverifiedIsNotConnected()
        {
            await CreateControlAsync();
            runtime.SessionStatus =
                GooglePlayGamesSessionStatus.SignedInUnverified;

            await control.RefreshAsync();

            Assert.AreEqual(
                "Signed in; Google Play Games connection not verified.",
                control.StatusText.text);
            StringAssert.DoesNotContain("Connected to Google Play Games", control.StatusText.text);
            Assert.AreEqual(0, runtime.InitializationCount);
            Assert.AreEqual(0, runtime.PlayGamesAuthenticationCount);
            Assert.AreEqual(3, runtime.SessionStatusRefreshCount);
        }

        [Test]
        public void UnavailableSessionDoesNotClaimGooglePlayGamesConnection()
        {
            string statusText =
                GooglePlayGamesAccountPresentation.GetStatusText(
                    GooglePlayGamesAuthenticationState.SignedOut,
                    GooglePlayGamesSessionStatus.Unavailable);

            StringAssert.Contains("status unavailable", statusText);
            StringAssert.DoesNotContain("Connected to Google Play Games", statusText);
        }

        [Test]
        public void VerifiedRestoredSessionIsShownAsConnected()
        {
            string statusText =
                GooglePlayGamesAccountPresentation.GetStatusText(
                    GooglePlayGamesAuthenticationState.SignedOut,
                    GooglePlayGamesSessionStatus.GooglePlayGamesConnected);

            Assert.AreEqual(
                "Connected to Google Play Games.",
                statusText);
        }

        [Test]
        public async Task CoordinatorStateSubscriptionIsRemovedWhenControlDisables()
        {
            await CreateControlAsync();

            Assert.IsTrue(control.IsSubscribedToCoordinator);
            settingsContentObject.SetActive(false);
            if (control.IsSubscribedToCoordinator)
                InvokeLifecycleCallback("OnDisable");
            Assert.IsFalse(control.IsSubscribedToCoordinator);
        }

        private Task CreateControlAsync()
        {
            return CreateControlAsync(
                GooglePlayGamesSessionStatus.NotConnected,
                false);
        }

        private async Task CreateControlAsync(
            GooglePlayGamesSessionStatus sessionStatus,
            bool cachedSessionTokenExists,
            Task<GooglePlayGamesSessionStatus> restorationTask = null)
        {
            settingsContentObject = new GameObject(
                "SettingsScrollContent",
                typeof(RectTransform));
            settingsContentObject.GetComponent<RectTransform>().sizeDelta =
                new Vector2(0f, 1450f);

            runtime = new FakeRuntime();
            runtime.SessionStatus = sessionStatus;
            runtime.CachedSessionTokenExists = cachedSessionTokenExists;
            if (restorationTask != null)
                runtime.RestorationTask = restorationTask;
            coordinator =
                new GooglePlayGamesAuthenticationCoordinator(runtime);
            control = GooglePlayGamesAccountSettingsControl.Attach(
                settingsContentObject.transform,
                coordinator);

            if (!control.IsSubscribedToCoordinator)
                InvokeLifecycleCallback("OnEnable");

            await control.RefreshAsync();
        }

        private void InvokeLifecycleCallback(string callbackName)
        {
            MethodInfo callback = typeof(
                    GooglePlayGamesAccountSettingsControl)
                .GetMethod(
                    callbackName,
                    BindingFlags.Instance | BindingFlags.NonPublic);
            Assert.IsNotNull(callback, "Lifecycle callback was not found.");
            callback.Invoke(control, null);
        }
    }
}
