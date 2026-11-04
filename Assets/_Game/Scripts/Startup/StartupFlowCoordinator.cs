using System;
using System.Threading.Tasks;
using SweetMerge.Analytics;
using SweetMerge.Authentication;
using UnityEngine;
using UnityEngine.UnityConsent;

namespace SweetMerge.Startup
{
    public enum StartupFlowOutcome
    {
        Idle,
        WaitingForAuthentication,
        GuestReady,
        GoogleVerified,
        RecoverableFailure
    }

    public sealed class StartupFlowCoordinator : IDisposable
    {
        private readonly StartupFlowMachine flow;
        private readonly StartupPrivacyWelcomeUI view;
        private readonly Func<bool> hasPrivacyChoice;
        private readonly Func<bool, bool> persistAnalyticsChoice;
        private readonly Func<bool, Task<bool>> authenticateGoogle;

        private bool subscribed;
        private bool initialized;
        private bool disposed;
        private bool authenticationInProgress;
        private bool privacyChoiceCompleted;
        private bool retryAuthenticationRequiresRestore;
        private int operationVersion;

        public StartupFlowOutcome Outcome { get; private set; } =
            StartupFlowOutcome.Idle;
        public string ErrorMessage { get; private set; }
        public bool CanRetry =>
            !disposed &&
            initialized &&
            !authenticationInProgress &&
            (flow.State == StartupFlowState.RecoverableError ||
             (flow.State == StartupFlowState.PlayModeSelectionPending &&
              flow.SelectedPlayMode == StartupPlayMode.Google));
        public Task AuthenticationTask { get; private set; } =
            Task.CompletedTask;
        public event Action<StartupFlowOutcome> OutcomeChanged;

        public StartupFlowCoordinator(
            StartupFlowMachine flow,
            StartupPrivacyWelcomeUI view,
            IAnalyticsConsentProvider consentProvider,
            GooglePlayGamesAuthenticationCoordinator authentication)
            : this(
                flow,
                view,
                () => consentProvider != null &&
                    consentProvider.AnalyticsConsent !=
                        ConsentStatus.Unspecified,
                granted => PersistAnalyticsChoice(
                    consentProvider,
                    granted),
                restore => AuthenticateWithGoogle(
                    authentication,
                    restore))
        {
            if (consentProvider == null)
                throw new ArgumentNullException(nameof(consentProvider));
            if (authentication == null)
                throw new ArgumentNullException(nameof(authentication));
        }

        public StartupFlowCoordinator(
            StartupFlowMachine flow,
            StartupPrivacyWelcomeUI view,
            Func<bool> hasPrivacyChoice,
            Func<bool, bool> persistAnalyticsChoice,
            Func<bool, Task<bool>> authenticateGoogle)
        {
            this.flow = flow ??
                throw new ArgumentNullException(nameof(flow));
            this.view = view ??
                throw new ArgumentNullException(nameof(view));
            this.hasPrivacyChoice = hasPrivacyChoice ??
                throw new ArgumentNullException(nameof(hasPrivacyChoice));
            this.persistAnalyticsChoice = persistAnalyticsChoice ??
                throw new ArgumentNullException(nameof(persistAnalyticsChoice));
            this.authenticateGoogle = authenticateGoogle ??
                throw new ArgumentNullException(nameof(authenticateGoogle));
        }

        public bool Initialize()
        {
            if (disposed || initialized)
                return false;

            initialized = true;
            Subscribe();

            bool privacyIsChosen;
            try
            {
                privacyIsChosen = hasPrivacyChoice();
            }
            catch (Exception exception)
            {
                flow.Initialize(false);
                ShowPrivacyFailure(
                    "Privacy choice could not be checked. Please try again.",
                    exception);
                return false;
            }

            privacyChoiceCompleted = privacyIsChosen;
            flow.Initialize(privacyIsChosen);
            HandleCurrentState();
            return true;
        }

        public bool Retry()
        {
            if (disposed || !initialized || authenticationInProgress)
                return false;

            if (flow.State == StartupFlowState.PlayModeSelectionPending &&
                flow.SelectedPlayMode == StartupPlayMode.Google)
            {
                StartAuthentication(restoreCachedSession: true);
                return true;
            }

            if (!flow.Retry())
            {
                ShowRecoverableFailure(
                    flow.ErrorMessage ??
                    "Startup could not be retried.");
                return false;
            }

            ErrorMessage = null;
            if (flow.State == StartupFlowState.GoogleAuthenticationPending)
            {
                StartAuthentication(
                    flow.RequiresGoogleSessionRestoration ||
                    retryAuthenticationRequiresRestore);
                return true;
            }

            HandleCurrentState();
            return true;
        }

        public void Dispose()
        {
            if (disposed)
                return;

            disposed = true;
            operationVersion++;
            Unsubscribe();
            if (view != null)
                view.SetWelcomeActionsInteractable(true);
            OutcomeChanged = null;
        }

        private void Subscribe()
        {
            if (subscribed)
                return;

            view.AnalyticsAllowed += HandleAnalyticsAllowed;
            view.AnalyticsDeclined += HandleAnalyticsDeclined;
            view.GoogleSignInRequested += HandleGoogleSignInRequested;
            view.RetryGoogleRestorationRequested +=
                HandleRetryGoogleRestorationRequested;
            view.GuestPlayRequested += HandleGuestPlayRequested;
            view.LifecycleEnded += HandleViewLifecycleEnded;
            subscribed = true;
        }

        private void Unsubscribe()
        {
            if (!subscribed)
                return;

            if (view != null)
            {
                view.AnalyticsAllowed -= HandleAnalyticsAllowed;
                view.AnalyticsDeclined -= HandleAnalyticsDeclined;
                view.GoogleSignInRequested -= HandleGoogleSignInRequested;
                view.RetryGoogleRestorationRequested -=
                    HandleRetryGoogleRestorationRequested;
                view.GuestPlayRequested -= HandleGuestPlayRequested;
                view.LifecycleEnded -= HandleViewLifecycleEnded;
            }

            subscribed = false;
        }

        private void HandleViewLifecycleEnded()
        {
            Dispose();
        }

        private void HandleAnalyticsAllowed()
        {
            CompleteAnalyticsChoice(true);
        }

        private void HandleAnalyticsDeclined()
        {
            CompleteAnalyticsChoice(false);
        }

        private void CompleteAnalyticsChoice(bool granted)
        {
            if (!CanHandlePrivacyChoice())
                return;

            try
            {
                if (!persistAnalyticsChoice(granted))
                {
                    ShowPrivacyFailure(
                        "Your analytics choice could not be confirmed. " +
                        "Please try again.",
                        null);
                    return;
                }
            }
            catch (Exception exception)
            {
                ShowPrivacyFailure(
                    "Your analytics choice could not be saved. Please try again.",
                    exception);
                return;
            }

            if (!flow.CompletePrivacyChoice())
            {
                ShowPrivacyFailure(
                    "Startup could not continue after the privacy choice.",
                    null);
                return;
            }

            privacyChoiceCompleted = true;
            ErrorMessage = null;
            view.SetPrivacyFeedback(string.Empty);
            HandleCurrentState();
        }

        private bool CanHandlePrivacyChoice()
        {
            return !disposed &&
                   initialized &&
                   !authenticationInProgress &&
                   flow.State == StartupFlowState.PrivacyPending &&
                   view.IsVisible &&
                   view.VisibleScreen ==
                       StartupPrivacyWelcomeScreen.Privacy;
        }

        private void HandleGuestPlayRequested()
        {
            if (disposed ||
                !initialized ||
                authenticationInProgress ||
                flow.State != StartupFlowState.PlayModeSelectionPending ||
                !IsWelcomeVisible())
                return;

            if (!flow.SelectGuest())
            {
                ShowRecoverableFailure(
                    flow.ErrorMessage ??
                    "Guest Play could not be selected. Please try again.");
                return;
            }

            ErrorMessage = null;
            view.SetFeedback(string.Empty);
            view.Hide();
            SetOutcome(StartupFlowOutcome.GuestReady);
        }

        private void HandleGoogleSignInRequested()
        {
            if (disposed ||
                !initialized ||
                authenticationInProgress ||
                flow.State != StartupFlowState.PlayModeSelectionPending ||
                !IsWelcomeVisible())
                return;

            StartAuthentication(flow.RequiresGoogleSessionRestoration);
        }

        private void HandleRetryGoogleRestorationRequested()
        {
            if (disposed ||
                !initialized ||
                authenticationInProgress ||
                flow.State != StartupFlowState.PlayModeSelectionPending ||
                flow.SelectedPlayMode != StartupPlayMode.Google ||
                !IsWelcomeVisible())
                return;

            StartAuthentication(restoreCachedSession: true);
        }

        private void StartAuthentication(bool restoreCachedSession)
        {
            if (disposed || authenticationInProgress)
                return;

            if (!flow.BeginGoogleAuthentication())
            {
                ShowRecoverableFailure(
                    flow.ErrorMessage ??
                    "Google sign-in could not be started.");
                return;
            }

            retryAuthenticationRequiresRestore = restoreCachedSession;
            view.SetGoogleRecoveryActionsVisible(false);
            authenticationInProgress = true;
            int currentOperation = ++operationVersion;
            view.ShowWelcome();
            view.SetWelcomeActionsInteractable(false);
            view.SetFeedback(
                restoreCachedSession
                    ? "Restoring your Google Play Games session..."
                    : "Connecting to Google Play Games...");
            ErrorMessage = null;
            SetOutcome(StartupFlowOutcome.WaitingForAuthentication);
            AuthenticationTask = AuthenticateAndCompleteAsync(
                currentOperation,
                restoreCachedSession);
        }

        private async Task AuthenticateAndCompleteAsync(
            int currentOperation,
            bool restoreCachedSession)
        {
            bool verified;
            string failureMessage = null;
            try
            {
                verified = await authenticateGoogle(restoreCachedSession);
            }
            catch (Exception exception)
            {
                verified = false;
                failureMessage =
                    "Google Play Games could not be verified. " +
                    exception.Message;
            }

            if (disposed || currentOperation != operationVersion)
                return;

            authenticationInProgress = false;
            view.SetWelcomeActionsInteractable(true);

            if (verified)
            {
                if (flow.GoogleVerified())
                {
                    ErrorMessage = null;
                    view.Hide();
                    SetOutcome(StartupFlowOutcome.GoogleVerified);
                    return;
                }

                ShowRecoverableFailure(
                    flow.ErrorMessage ??
                    "Google was verified, but the startup selection " +
                    "could not be saved.");
                return;
            }

            flow.GoogleAuthenticationCancelledOrFailed();
            view.SetGoogleRecoveryActionsVisible(restoreCachedSession);
            string message = failureMessage ??
                "Google sign-in was cancelled or could not be verified. " +
                "Your saved play-mode selection was not cleared.";
            ShowRecoverableFailure(message);
        }

        private void HandleCurrentState()
        {
            if (disposed)
                return;

            switch (flow.State)
            {
                case StartupFlowState.PrivacyPending:
                    SetOutcome(StartupFlowOutcome.Idle);
                    view.ShowPrivacy();
                    break;

                case StartupFlowState.PlayModeSelectionPending:
                    view.ShowWelcome();
                    string selectionMessage = !string.IsNullOrEmpty(
                        ErrorMessage)
                        ? ErrorMessage
                        : flow.ErrorMessage;
                    if (!string.IsNullOrEmpty(selectionMessage))
                        view.SetFeedback(selectionMessage);
                    break;

                case StartupFlowState.GoogleAuthenticationPending:
                    StartAuthentication(
                        flow.RequiresGoogleSessionRestoration);
                    break;

                case StartupFlowState.LoadingRestorePending:
                    if (flow.SelectedPlayMode == StartupPlayMode.Guest)
                    {
                        SetOutcome(StartupFlowOutcome.GuestReady);
                        view.Hide();
                    }
                    else if (flow.SelectedPlayMode == StartupPlayMode.Google)
                    {
                        SetOutcome(StartupFlowOutcome.GoogleVerified);
                        view.Hide();
                    }
                    break;

                case StartupFlowState.RecoverableError:
                    if (!privacyChoiceCompleted)
                    {
                        ShowPrivacyFailure(
                            flow.ErrorMessage ??
                            "Startup needs attention. Please try again.",
                            null);
                    }
                    else
                    {
                        ShowRecoverableFailure(
                            flow.ErrorMessage ??
                            "Startup needs attention. Please try again.");
                    }
                    break;
            }
        }

        private bool IsWelcomeVisible()
        {
            return view.IsVisible &&
                   view.VisibleScreen ==
                       StartupPrivacyWelcomeScreen.Welcome;
        }

        private void ShowPrivacyFailure(
            string message,
            Exception exception)
        {
            ErrorMessage = message;
            if (exception != null)
            {
                Debug.LogWarning(
                    "STARTUP | " + message + "\n" + exception);
            }

            view.ShowPrivacy();
            view.SetPrivacyFeedback(message);
            SetOutcome(StartupFlowOutcome.RecoverableFailure);
        }

        private void ShowRecoverableFailure(string message)
        {
            ErrorMessage = message;
            view.ShowWelcome();
            view.SetFeedback(message);
            SetOutcome(StartupFlowOutcome.RecoverableFailure);
        }

        private void SetOutcome(StartupFlowOutcome outcome)
        {
            if (Outcome == outcome)
                return;

            Outcome = outcome;
            OutcomeChanged?.Invoke(outcome);
        }

        private static bool PersistAnalyticsChoice(
            IAnalyticsConsentProvider provider,
            bool granted)
        {
            if (provider == null)
                return false;

            provider.SetAnalyticsConsent(granted);
            ConsentStatus expected = granted
                ? ConsentStatus.Granted
                : ConsentStatus.Denied;
            return provider.AnalyticsConsent == expected;
        }

        private static async Task<bool> AuthenticateWithGoogle(
            GooglePlayGamesAuthenticationCoordinator authentication,
            bool restoreCachedSession)
        {
            if (authentication == null)
                return false;

            GooglePlayGamesAuthenticationResult result =
                restoreCachedSession
                    ? await authentication.RestoreSessionAsync()
                    : await authentication.SignInInteractivelyAsync();

            return result == GooglePlayGamesAuthenticationResult.SignedIn &&
                   authentication.SessionStatus ==
                       GooglePlayGamesSessionStatus
                           .GooglePlayGamesConnected;
        }
    }
}
