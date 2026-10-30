using System;
using System.Threading.Tasks;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

namespace SweetMerge.Authentication
{
    internal static class GooglePlayGamesAccountPresentation
    {
        internal static string GetStatusText(
            GooglePlayGamesAuthenticationState state,
            GooglePlayGamesSessionStatus sessionStatus)
        {
            if (state == GooglePlayGamesAuthenticationState.SigningIn)
            {
                return sessionStatus ==
                       GooglePlayGamesSessionStatus.RestoringSession
                    ? "Restoring your previous session..."
                    : "Connecting to Google Play Games...";
            }

            if (state == GooglePlayGamesAuthenticationState.SignedIn ||
                sessionStatus ==
                    GooglePlayGamesSessionStatus.GooglePlayGamesConnected)
            {
                return "Connected to Google Play Games.";
            }

            if (state ==
                    GooglePlayGamesAuthenticationState.SignedInUnverified ||
                sessionStatus ==
                    GooglePlayGamesSessionStatus.SignedInUnverified)
            {
                return "Signed in; Google Play Games connection not verified.";
            }

            switch (sessionStatus)
            {
                case GooglePlayGamesSessionStatus.NotConnected:
                    return "Not connected.";
                case GooglePlayGamesSessionStatus.PreviousSessionAvailable:
                    return "Previous session available. Reconnect to verify.";
                case GooglePlayGamesSessionStatus.RestoringSession:
                    return "Restoring your previous session...";
                case GooglePlayGamesSessionStatus.RestorationFailed:
                    return "Could not restore the previous session.";
                default:
                    return "Account status unavailable. Offline play is available.";
            }
        }

        internal static string GetFeedbackText(
            GooglePlayGamesAuthenticationState state,
            GooglePlayGamesSessionStatus sessionStatus)
        {
            if (sessionStatus ==
                GooglePlayGamesSessionStatus.RestorationFailed)
            {
                return "Could not reconnect. You can continue playing offline. Please try again.";
            }

            if (sessionStatus ==
                GooglePlayGamesSessionStatus.PreviousSessionAvailable)
            {
                return "Reconnect to verify your saved sign-in. Progress remains local.";
            }

            if (state ==
                    GooglePlayGamesAuthenticationState.SignedInUnverified ||
                sessionStatus ==
                    GooglePlayGamesSessionStatus.SignedInUnverified)
            {
                return "Google Play Games could not be verified. Progress remains saved locally.";
            }

            switch (state)
            {
                case GooglePlayGamesAuthenticationState.SigningIn:
                    return "Please wait while sign-in completes.";
                case GooglePlayGamesAuthenticationState.Cancelled:
                    return "Sign-in cancelled. You can continue playing offline.";
                case GooglePlayGamesAuthenticationState.Failed:
                    return "Could not connect. You can continue playing offline. Please try again.";
                case GooglePlayGamesAuthenticationState.SignedIn:
                    return "Your progress remains saved locally on this device.";
                default:
                    return "Your progress remains saved locally on this device.";
            }
        }

        internal static string GetButtonText(
            GooglePlayGamesAuthenticationState state,
            GooglePlayGamesSessionStatus sessionStatus)
        {
            if (state == GooglePlayGamesAuthenticationState.SigningIn)
            {
                return sessionStatus ==
                       GooglePlayGamesSessionStatus.RestoringSession
                    ? "Restoring..."
                    : "Connecting...";
            }

            switch (sessionStatus)
            {
                case GooglePlayGamesSessionStatus.PreviousSessionAvailable:
                case GooglePlayGamesSessionStatus.RestorationFailed:
                    return "Reconnect";
                case GooglePlayGamesSessionStatus.RestoringSession:
                    return "Restoring...";
                case GooglePlayGamesSessionStatus.GooglePlayGamesConnected:
                    return "Connected";
                case GooglePlayGamesSessionStatus.SignedInUnverified:
                    return "Check Connection";
                default:
                    return "Connect with Google Play";
            }
        }

        internal static bool IsConnectEnabled(
            GooglePlayGamesAuthenticationState state,
            GooglePlayGamesSessionStatus sessionStatus)
        {
            return state != GooglePlayGamesAuthenticationState.SigningIn &&
                   state != GooglePlayGamesAuthenticationState.SignedIn &&
                   sessionStatus !=
                       GooglePlayGamesSessionStatus.GooglePlayGamesConnected &&
                   sessionStatus !=
                       GooglePlayGamesSessionStatus.RestoringSession;
        }
    }

    public sealed class GooglePlayGamesAccountSettingsControl : MonoBehaviour
    {
        private const string ControlName = "GooglePlayGamesAccountSettings";
        private const float SectionHeight = 340f;
        private static readonly Color ButtonColor =
            new Color(0.35f, 0.18f, 0.58f, 1f);

        private GooglePlayGamesAuthenticationCoordinator coordinator;
        private RectTransform section;
        private TMP_Text statusText;
        private TMP_Text feedbackText;
        private TMP_Text localProgressText;
        private TMP_Text connectButtonLabel;
        private Button connectButton;
        private Task interactionTask = Task.CompletedTask;
        private bool subscribed;
        private bool built;
        private bool automaticRestorationAttempted;
        private bool restorationFailureAwaitingManualRetry;

        internal TMP_Text StatusText => statusText;
        internal TMP_Text FeedbackText => feedbackText;
        internal TMP_Text LocalProgressText => localProgressText;
        internal Button ConnectButton => connectButton;
        internal Task InteractionTask => interactionTask;
        internal bool IsSubscribedToCoordinator => subscribed;

        public static GooglePlayGamesAccountSettingsControl Attach(
            Transform settingsContent,
            GooglePlayGamesAuthenticationCoordinator coordinator)
        {
            if (settingsContent == null)
                throw new ArgumentNullException(nameof(settingsContent));
            if (coordinator == null)
                throw new ArgumentNullException(nameof(coordinator));

            Transform existing = settingsContent.Find(ControlName);
            GooglePlayGamesAccountSettingsControl control;
            if (existing != null)
            {
                control =
                    existing.GetComponent<
                        GooglePlayGamesAccountSettingsControl>();
                if (control == null)
                {
                    Debug.LogError(
                        "Account settings content exists without its control.",
                        existing);
                    return null;
                }
            }
            else
            {
                var controlObject = new GameObject(
                    ControlName,
                    typeof(RectTransform));
                controlObject.SetActive(false);
                controlObject.transform.SetParent(settingsContent, false);
                control = controlObject.AddComponent<
                    GooglePlayGamesAccountSettingsControl>();
                control.BuildControls();
                control.PositionAfterExistingContent(settingsContent);
            }

            control.SetCoordinator(coordinator);
            if (!control.gameObject.activeSelf)
                control.gameObject.SetActive(true);
            return control;
        }

        private void OnEnable()
        {
            if (coordinator == null)
                coordinator = GooglePlayGamesAuthenticationCoordinator.Instance;

            Subscribe();
            _ = RefreshAsync();
        }

        private void OnDisable()
        {
            Unsubscribe();
        }

        private void OnDestroy()
        {
            Unsubscribe();
            if (connectButton != null)
                connectButton.onClick.RemoveListener(HandleConnectClicked);
        }

        internal Task RefreshAsync()
        {
            if (coordinator == null)
                return Task.CompletedTask;

            return RefreshAndRenderAsync();
        }

        internal Task ConnectAsync()
        {
            if (!isActiveAndEnabled ||
                coordinator == null ||
                coordinator.State ==
                    GooglePlayGamesAuthenticationState.SigningIn ||
                coordinator.State ==
                    GooglePlayGamesAuthenticationState.SignedIn ||
                !GooglePlayGamesAccountPresentation.IsConnectEnabled(
                    coordinator.State,
                    coordinator.SessionStatus))
            {
                return Task.CompletedTask;
            }

            if (connectButton != null)
                connectButton.interactable = false;
            Render();

            if (RequiresSessionRestoration(coordinator.SessionStatus))
            {
                restorationFailureAwaitingManualRetry = false;
                return RestoreSessionAndRenderAsync();
            }

            return SignInAndRenderAsync();
        }

        private void BuildControls()
        {
            if (built)
                return;

            built = true;
            section = GetComponent<RectTransform>();
            section.anchorMin = new Vector2(0.06f, 1f);
            section.anchorMax = new Vector2(0.94f, 1f);
            section.pivot = new Vector2(0.5f, 1f);
            section.sizeDelta = new Vector2(0f, SectionHeight);

            TMP_FontAsset font = FindFont();
            CreateText(
                "AccountHeading",
                "ACCOUNT",
                font,
                32f,
                FontStyles.Bold,
                new Vector2(0f, 1f),
                new Vector2(0f, -54f),
                new Vector2(1f, 1f),
                new Vector2(0f, -8f));
            CreateText(
                "GooglePlayGamesLabel",
                "Google Play Games",
                font,
                25f,
                FontStyles.Bold,
                new Vector2(0f, 1f),
                new Vector2(0f, -100f),
                new Vector2(1f, 1f),
                new Vector2(0f, -58f));
            statusText = CreateText(
                "GooglePlayGamesConnectionStatus",
                "Account status unavailable. Offline play is available.",
                font,
                22f,
                FontStyles.Normal,
                new Vector2(0f, 1f),
                new Vector2(0f, -145f),
                new Vector2(1f, 1f),
                new Vector2(0f, -104f));
            feedbackText = CreateText(
                "GooglePlayGamesAccountFeedback",
                "Your progress remains saved locally on this device.",
                font,
                19f,
                FontStyles.Normal,
                new Vector2(0f, 1f),
                new Vector2(0f, -198f),
                new Vector2(1f, 1f),
                new Vector2(0f, -150f));
            localProgressText = CreateText(
                "LocalProgressClarification",
                "Progress remains saved locally on this device.",
                font,
                18f,
                FontStyles.Normal,
                new Vector2(0f, 1f),
                new Vector2(0f, -330f),
                new Vector2(1f, 1f),
                new Vector2(0f, -288f));
            connectButton = CreateButton(
                "ConnectWithGooglePlay",
                "Connect with Google Play",
                font);
            connectButtonLabel =
                connectButton.GetComponentInChildren<TMP_Text>();
            connectButton.onClick.RemoveListener(HandleConnectClicked);
            connectButton.onClick.AddListener(HandleConnectClicked);
        }

        private void PositionAfterExistingContent(Transform settingsContent)
        {
            RectTransform contentRect = settingsContent as RectTransform;
            if (contentRect == null)
            {
                Debug.LogError(
                    "Account settings require a RectTransform scroll content.",
                    settingsContent);
                return;
            }

            float originalHeight = contentRect.sizeDelta.y;
            section.anchoredPosition = new Vector2(
                0f,
                -(originalHeight + 20f));
            contentRect.sizeDelta = new Vector2(
                contentRect.sizeDelta.x,
                originalHeight + SectionHeight + 40f);
        }

        private TMP_Text CreateText(
            string objectName,
            string value,
            TMP_FontAsset font,
            float fontSize,
            FontStyles fontStyle,
            Vector2 anchorMin,
            Vector2 offsetMin,
            Vector2 anchorMax,
            Vector2 offsetMax)
        {
            var textObject = new GameObject(
                objectName,
                typeof(RectTransform),
                typeof(TextMeshProUGUI));
            textObject.transform.SetParent(transform, false);
            RectTransform rect = textObject.GetComponent<RectTransform>();
            rect.anchorMin = anchorMin;
            rect.anchorMax = anchorMax;
            rect.offsetMin = offsetMin;
            rect.offsetMax = offsetMax;

            TextMeshProUGUI text = textObject.GetComponent<TextMeshProUGUI>();
            text.font = font;
            text.text = value;
            text.fontSize = fontSize;
            text.fontStyle = fontStyle;
            text.color = Color.white;
            text.alignment = TextAlignmentOptions.MidlineLeft;
            text.textWrappingMode = TextWrappingModes.Normal;
            return text;
        }

        private Button CreateButton(
            string objectName,
            string label,
            TMP_FontAsset font)
        {
            var buttonObject = new GameObject(
                objectName,
                typeof(RectTransform),
                typeof(Image),
                typeof(Button));
            buttonObject.transform.SetParent(transform, false);
            Image image = buttonObject.GetComponent<Image>();
            image.color = ButtonColor;

            Button button = buttonObject.GetComponent<Button>();
            button.targetGraphic = image;

            var labelObject = new GameObject(
                objectName + "Label",
                typeof(RectTransform),
                typeof(TextMeshProUGUI));
            labelObject.transform.SetParent(buttonObject.transform, false);
            RectTransform labelRect =
                labelObject.GetComponent<RectTransform>();
            labelRect.anchorMin = Vector2.zero;
            labelRect.anchorMax = Vector2.one;
            labelRect.offsetMin = Vector2.zero;
            labelRect.offsetMax = Vector2.zero;

            TextMeshProUGUI labelText =
                labelObject.GetComponent<TextMeshProUGUI>();
            labelText.font = font;
            labelText.text = label;
            labelText.fontSize = 23f;
            labelText.fontStyle = FontStyles.Bold;
            labelText.color = Color.white;
            labelText.alignment = TextAlignmentOptions.Center;
            labelText.textWrappingMode = TextWrappingModes.Normal;

            RectTransform buttonRect =
                buttonObject.GetComponent<RectTransform>();
            buttonRect.anchorMin = new Vector2(0f, 1f);
            buttonRect.anchorMax = new Vector2(1f, 1f);
            buttonRect.offsetMin = new Vector2(0f, -278f);
            buttonRect.offsetMax = new Vector2(0f, -218f);
            return button;
        }

        private void SetCoordinator(
            GooglePlayGamesAuthenticationCoordinator value)
        {
            if (!ReferenceEquals(coordinator, value))
            {
                Unsubscribe();
                coordinator = value;
                automaticRestorationAttempted = false;
                restorationFailureAwaitingManualRetry = false;
            }

            if (isActiveAndEnabled)
            {
                Subscribe();
                _ = RefreshAsync();
            }
            else
            {
                Render();
            }
        }

        private void Subscribe()
        {
            if (subscribed || coordinator == null)
                return;

            coordinator.StateChanged += HandleStateChanged;
            subscribed = true;
        }

        private void Unsubscribe()
        {
            if (!subscribed || coordinator == null)
                return;

            coordinator.StateChanged -= HandleStateChanged;
            subscribed = false;
        }

        private async Task RefreshAndRenderAsync()
        {
            if (restorationFailureAwaitingManualRetry)
            {
                if (this != null && isActiveAndEnabled)
                    Render();
                return;
            }

            await coordinator.RefreshSessionStatusAsync();
            if (this == null || !isActiveAndEnabled)
                return;

            if (!automaticRestorationAttempted &&
                coordinator.SessionStatus ==
                    GooglePlayGamesSessionStatus.PreviousSessionAvailable)
            {
                automaticRestorationAttempted = true;
                await coordinator.RestoreSessionAsync();
                if (this == null)
                    return;
                restorationFailureAwaitingManualRetry =
                    coordinator.SessionStatus ==
                    GooglePlayGamesSessionStatus.RestorationFailed;
                if (!isActiveAndEnabled)
                    return;
            }

            Render();
        }

        private async Task SignInAndRenderAsync()
        {
            await coordinator.SignInAsync();
            if (this == null || !isActiveAndEnabled)
                return;

            Render();
        }

        private async Task RestoreSessionAndRenderAsync()
        {
            await coordinator.RestoreSessionAsync();
            if (this == null)
                return;

            restorationFailureAwaitingManualRetry =
                coordinator.SessionStatus ==
                GooglePlayGamesSessionStatus.RestorationFailed;
            if (!isActiveAndEnabled)
                return;
            Render();
        }

        private void HandleConnectClicked()
        {
            interactionTask = ConnectAsync();
        }

        private void HandleStateChanged()
        {
            if (this != null && isActiveAndEnabled)
                Render();
        }

        private void Render()
        {
            if (coordinator == null)
                return;

            GooglePlayGamesAuthenticationState currentState =
                coordinator.State;
            if (statusText != null)
            {
                statusText.text =
                    GooglePlayGamesAccountPresentation.GetStatusText(
                        currentState,
                        coordinator.SessionStatus);
            }

            if (feedbackText != null)
            {
                feedbackText.text =
                    GooglePlayGamesAccountPresentation.GetFeedbackText(
                        currentState,
                        coordinator.SessionStatus);
            }

            if (connectButton != null)
            {
                connectButton.interactable =
                    GooglePlayGamesAccountPresentation.IsConnectEnabled(
                        currentState,
                        coordinator.SessionStatus);
            }

            if (connectButtonLabel != null)
            {
                connectButtonLabel.text =
                    GooglePlayGamesAccountPresentation.GetButtonText(
                        currentState,
                        coordinator.SessionStatus);
            }
        }

        private static bool RequiresSessionRestoration(
            GooglePlayGamesSessionStatus status)
        {
            return status ==
                       GooglePlayGamesSessionStatus.PreviousSessionAvailable ||
                   status == GooglePlayGamesSessionStatus.RestorationFailed ||
                   status == GooglePlayGamesSessionStatus.SignedInUnverified;
        }

        private static TMP_FontAsset FindFont()
        {
            TMP_FontAsset[] fonts =
                Resources.FindObjectsOfTypeAll<TMP_FontAsset>();
            return fonts.Length > 0
                ? fonts[0]
                : TMP_Settings.defaultFontAsset;
        }
    }
}
