using System;
using TMPro;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using UnityEngine.UnityConsent;

namespace SweetMerge.Analytics
{
    internal static class AnalyticsConsentPresentation
    {
        internal const string MainBakerySceneName = "MainBakery";
        internal const string PrivacyPolicyUrl =
            "https://offcut-studios.github.io/offcutstudios-legal/" +
            "dessert-merge-cafe/privacy-policy/";

        internal static bool ShouldShowPrompt(
            string sceneName,
            ConsentStatus status,
            bool dismissed)
        {
            return sceneName == MainBakerySceneName &&
                   status == ConsentStatus.Unspecified &&
                   !dismissed;
        }

        internal static void ApplyChoice(
            IAnalyticsConsentProvider provider,
            bool isGranted)
        {
            if (provider == null)
                throw new ArgumentNullException(nameof(provider));

            provider.SetAnalyticsConsent(isGranted);
        }

        internal static string GetStatusText(ConsentStatus status)
        {
            switch (status)
            {
                case ConsentStatus.Granted:
                    return "Analytics is enabled.";
                case ConsentStatus.Denied:
                    return "Analytics is disabled.";
                default:
                    return "You have not chosen yet.";
            }
        }
    }

    public sealed class AnalyticsConsentSettingsControl : MonoBehaviour
    {
        private const string ControlName = "AnalyticsPrivacySettings";
        private const string ScrollbarName = "SettingsVerticalScrollbar";
        private const float SectionHeight = 310f;
        private static readonly Color ButtonColor =
            new Color(0.35f, 0.18f, 0.58f, 1f);

        private IAnalyticsConsentProvider provider;
        private RectTransform section;
        private TMP_Text statusText;
        private Button enableButton;
        private Button disableButton;
        private Button privacyPolicyButton;
        private bool subscribed;

        internal TMP_Text StatusText => statusText;
        internal Button EnableButton => enableButton;
        internal Button DisableButton => disableButton;

        public static AnalyticsConsentSettingsControl Attach(
            Transform settingsContent,
            IAnalyticsConsentProvider consentProvider)
        {
            if (settingsContent == null)
                throw new ArgumentNullException(nameof(settingsContent));

            Transform existing = settingsContent.Find(ControlName);
            AnalyticsConsentSettingsControl control;
            if (existing != null)
            {
                control = existing.GetComponent<AnalyticsConsentSettingsControl>();
                if (control == null)
                {
                    Debug.LogError(
                        "Analytics settings content exists without its control.",
                        existing);
                    return null;
                }
            }
            else
            {
                var controlObject = new GameObject(
                    ControlName,
                    typeof(RectTransform));
                controlObject.transform.SetParent(settingsContent, false);
                control = controlObject.AddComponent<
                    AnalyticsConsentSettingsControl>();
                control.BuildControls();
                control.PositionAfterExistingContent(settingsContent);
            }

            control.SetProvider(consentProvider);
            EnsureVerticalScrollbar(settingsContent);
            return control;
        }

        private void OnEnable()
        {
            if (provider == null)
                SetProvider(AnalyticsBootstrap.Instance);
            else
                Subscribe();
        }

        private void OnDisable()
        {
            Unsubscribe();
        }

        private void OnDestroy()
        {
            Unsubscribe();
        }

        private void BuildControls()
        {
            if (section != null)
                return;

            section = GetComponent<RectTransform>();
            section.anchorMin = new Vector2(0.06f, 1f);
            section.anchorMax = new Vector2(0.94f, 1f);
            section.pivot = new Vector2(0.5f, 1f);
            section.sizeDelta = new Vector2(0f, SectionHeight);

            TMP_FontAsset font = FindFont();

            CreateText(
                "AnalyticsPrivacyHeading",
                "ANALYTICS PRIVACY",
                font,
                32f,
                FontStyles.Bold,
                new Vector2(0f, 1f),
                new Vector2(0f, -58f),
                new Vector2(1f, 1f),
                new Vector2(0f, -10f));
            statusText = CreateText(
                "AnalyticsConsentStatus",
                AnalyticsConsentPresentation.GetStatusText(
                    ConsentStatus.Unspecified),
                font,
                25f,
                FontStyles.Normal,
                new Vector2(0f, 1f),
                new Vector2(0f, -108f),
                new Vector2(1f, 1f),
                new Vector2(0f, -64f));
            CreateText(
                "AnalyticsWithdrawalDisclosure",
                "Turning Analytics off stops future collection. The SDK may send events already buffered.",
                font,
                19f,
                FontStyles.Normal,
                new Vector2(0f, 1f),
                new Vector2(0f, -160f),
                new Vector2(1f, 1f),
                new Vector2(0f, -110f));

            enableButton = CreateButton(
                "EnableAnalytics",
                "Enable Analytics",
                font,
                25f,
                new Vector2(0f, 1f),
                new Vector2(0f, -236f),
                new Vector2(0.49f, 1f),
                new Vector2(0f, -166f));
            disableButton = CreateButton(
                "DisableAnalytics",
                "Disable Analytics",
                font,
                25f,
                new Vector2(0.51f, 1f),
                new Vector2(0f, -236f),
                new Vector2(1f, 1f),
                new Vector2(0f, -166f));
            privacyPolicyButton = CreateButton(
                "AnalyticsPrivacyPolicy",
                "Privacy Policy",
                font,
                23f,
                new Vector2(0f, 1f),
                new Vector2(0f, -302f),
                new Vector2(0.55f, 1f),
                new Vector2(0f, -250f));

            enableButton.onClick.RemoveListener(EnableAnalytics);
            enableButton.onClick.AddListener(EnableAnalytics);
            disableButton.onClick.RemoveListener(DisableAnalytics);
            disableButton.onClick.AddListener(DisableAnalytics);
            privacyPolicyButton.onClick.RemoveListener(OpenPrivacyPolicy);
            privacyPolicyButton.onClick.AddListener(OpenPrivacyPolicy);
        }

        private void PositionAfterExistingContent(Transform settingsContent)
        {
            var contentRect = settingsContent as RectTransform;
            if (contentRect == null)
            {
                Debug.LogError(
                    "Analytics settings require a RectTransform scroll content.",
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
            var rect = textObject.GetComponent<RectTransform>();
            rect.anchorMin = anchorMin;
            rect.anchorMax = anchorMax;
            rect.offsetMin = offsetMin;
            rect.offsetMax = offsetMax;

            var text = textObject.GetComponent<TextMeshProUGUI>();
            text.font = font;
            text.text = value;
            text.fontSize = fontSize;
            text.fontStyle = fontStyle;
            text.color = Color.white;
            text.alignment = TextAlignmentOptions.MidlineLeft;
            text.textWrappingMode = TextWrappingModes.Normal;
            return text;
        }

        private static void CreateButtonLabel(
            string objectName,
            string value,
            TMP_FontAsset font,
            float fontSize,
            Transform parent)
        {
            var textObject = new GameObject(
                objectName,
                typeof(RectTransform),
                typeof(TextMeshProUGUI));
            textObject.transform.SetParent(parent, false);
            RectTransform textRect = textObject.GetComponent<RectTransform>();
            textRect.anchorMin = Vector2.zero;
            textRect.anchorMax = Vector2.one;
            textRect.offsetMin = Vector2.zero;
            textRect.offsetMax = Vector2.zero;
            var text = textObject.GetComponent<TextMeshProUGUI>();
            text.font = font;
            text.text = value;
            text.fontSize = fontSize;
            text.fontStyle = FontStyles.Bold;
            text.color = Color.white;
            text.alignment = TextAlignmentOptions.Center;
            text.textWrappingMode = TextWrappingModes.Normal;
        }

        private Button CreateButton(
            string objectName,
            string label,
            TMP_FontAsset font,
            float fontSize,
            Vector2 anchorMin,
            Vector2 offsetMin,
            Vector2 anchorMax,
            Vector2 offsetMax)
        {
            var buttonObject = new GameObject(
                objectName,
                typeof(RectTransform),
                typeof(Image),
                typeof(Button));
            buttonObject.transform.SetParent(transform, false);
            var image = buttonObject.GetComponent<Image>();
            image.color = ButtonColor;
            var button = buttonObject.GetComponent<Button>();
            button.targetGraphic = image;
            CreateButtonLabel(
                objectName + "Label",
                label,
                font,
                fontSize,
                buttonObject.transform);

            var buttonRect = buttonObject.GetComponent<RectTransform>();
            buttonRect.anchorMin = anchorMin;
            buttonRect.anchorMax = anchorMax;
            buttonRect.offsetMin = offsetMin;
            buttonRect.offsetMax = offsetMax;
            return button;
        }

        private void SetProvider(IAnalyticsConsentProvider consentProvider)
        {
            if (!ReferenceEquals(provider, consentProvider))
            {
                Unsubscribe();
                provider = consentProvider;
            }

            Subscribe();
            RefreshStatus();
        }

        private void Subscribe()
        {
            if (subscribed || provider == null)
                return;

            provider.AnalyticsConsentChanged += HandleConsentChanged;
            subscribed = true;
        }

        private void Unsubscribe()
        {
            if (!subscribed || provider == null)
                return;

            provider.AnalyticsConsentChanged -= HandleConsentChanged;
            subscribed = false;
        }

        private void HandleConsentChanged(ConsentStatus status)
        {
            RefreshStatus(status);
        }

        private void RefreshStatus()
        {
            if (provider != null)
                RefreshStatus(provider.AnalyticsConsent);
        }

        private void RefreshStatus(ConsentStatus status)
        {
            if (statusText != null)
            {
                statusText.text = provider == null
                    ? "Analytics controls unavailable."
                    : AnalyticsConsentPresentation.GetStatusText(status);
            }
            if (enableButton != null)
                enableButton.interactable = provider != null;
            if (disableButton != null)
                disableButton.interactable = provider != null;
        }

        private void EnableAnalytics()
        {
            if (provider != null)
                AnalyticsConsentPresentation.ApplyChoice(provider, true);
        }

        private void DisableAnalytics()
        {
            if (provider != null)
                AnalyticsConsentPresentation.ApplyChoice(provider, false);
        }

        private static void OpenPrivacyPolicy()
        {
            Application.OpenURL(AnalyticsConsentPresentation.PrivacyPolicyUrl);
        }

        private static void EnsureVerticalScrollbar(Transform settingsContent)
        {
            Transform viewport = settingsContent.parent;
            if (viewport == null)
                return;

            ScrollRect scrollRect = viewport.GetComponent<ScrollRect>();
            if (scrollRect == null)
                return;

            if (scrollRect.verticalScrollbar == null)
            {
                Transform existing = viewport.Find(ScrollbarName);
                Scrollbar scrollbar = existing != null
                    ? existing.GetComponent<Scrollbar>()
                    : CreateVerticalScrollbar(viewport);
                if (scrollbar == null)
                {
                    Debug.LogError(
                        "Analytics settings could not create a vertical scrollbar.",
                        viewport);
                    return;
                }

                scrollRect.verticalScrollbar = scrollbar;
            }

            scrollRect.verticalScrollbarVisibility =
                ScrollRect.ScrollbarVisibility.Permanent;
        }

        private static Scrollbar CreateVerticalScrollbar(Transform viewport)
        {
            var scrollbarObject = new GameObject(
                ScrollbarName,
                typeof(RectTransform),
                typeof(Image),
                typeof(Scrollbar));
            scrollbarObject.transform.SetParent(viewport, false);

            RectTransform scrollbarRect =
                scrollbarObject.GetComponent<RectTransform>();
            scrollbarRect.anchorMin = new Vector2(0.965f, 0.02f);
            scrollbarRect.anchorMax = new Vector2(0.995f, 0.98f);
            scrollbarRect.offsetMin = Vector2.zero;
            scrollbarRect.offsetMax = Vector2.zero;

            Image trackImage = scrollbarObject.GetComponent<Image>();
            trackImage.color = new Color(0.2f, 0.15f, 0.25f, 0.45f);
            trackImage.raycastTarget = true;

            var handleObject = new GameObject(
                "Handle",
                typeof(RectTransform),
                typeof(Image));
            handleObject.transform.SetParent(scrollbarObject.transform, false);
            RectTransform handleRect =
                handleObject.GetComponent<RectTransform>();
            handleRect.anchorMin = Vector2.zero;
            handleRect.anchorMax = Vector2.one;
            handleRect.offsetMin = new Vector2(2f, 2f);
            handleRect.offsetMax = new Vector2(-2f, -2f);

            Image handleImage = handleObject.GetComponent<Image>();
            handleImage.color = ButtonColor;
            handleImage.raycastTarget = true;

            Scrollbar scrollbar = scrollbarObject.GetComponent<Scrollbar>();
            scrollbar.handleRect = handleRect;
            scrollbar.targetGraphic = trackImage;
            scrollbar.direction = Scrollbar.Direction.BottomToTop;
            scrollbar.transition = Selectable.Transition.None;
            return scrollbar;
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

    internal sealed class AnalyticsConsentPromptController : MonoBehaviour
    {
        private static AnalyticsConsentPromptController instance;

        private IAnalyticsConsentProvider provider;
        private GameObject promptCanvas;
        private GameObject dismissButtonObject;
        private EventSystem promptEventSystem;
        private GameObject previouslySelectedObject;
        private ulong? dismissedSceneHandle;
        private ulong? displayedSceneHandle;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        private static void ResetStaticState()
        {
            instance = null;
        }

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
        private static void InstallAfterSceneLoad()
        {
            if (instance != null)
                return;

            instance = FindAnyObjectByType<AnalyticsConsentPromptController>();
            if (instance != null)
                return;

            var controllerObject =
                new GameObject(nameof(AnalyticsConsentPromptController));
            controllerObject.AddComponent<AnalyticsConsentPromptController>();
        }

        private void Awake()
        {
            if (instance != null && instance != this)
            {
                Destroy(gameObject);
                return;
            }

            instance = this;
            DontDestroyOnLoad(gameObject);
        }

        private void OnEnable()
        {
            SceneManager.sceneLoaded += HandleSceneLoaded;
            provider = AnalyticsBootstrap.Instance;
            if (provider == null)
            {
                Debug.LogError(
                    "Analytics consent prompt could not find AnalyticsBootstrap.",
                    this);
            }
            else
            {
                provider.AnalyticsConsentChanged += HandleConsentChanged;
            }

            HandleSceneLoaded(
                SceneManager.GetActiveScene(),
                LoadSceneMode.Single);
        }

        private void OnDisable()
        {
            SceneManager.sceneLoaded -= HandleSceneLoaded;
            if (provider != null)
                provider.AnalyticsConsentChanged -= HandleConsentChanged;
        }

        private void OnDestroy()
        {
            if (instance == this)
                instance = null;
        }

        private void HandleSceneLoaded(Scene scene, LoadSceneMode mode)
        {
            Scene activeScene = SceneManager.GetActiveScene();
            if (activeScene.name != AnalyticsConsentPresentation.MainBakerySceneName)
            {
                HidePrompt();
                return;
            }

            ulong activeSceneHandle = activeScene.handle.GetRawData();
            if (displayedSceneHandle != activeSceneHandle)
            {
                dismissedSceneHandle = null;
                displayedSceneHandle = activeSceneHandle;
            }

            RefreshPrompt(activeScene);
        }

        private void HandleConsentChanged(ConsentStatus status)
        {
            RefreshPrompt(SceneManager.GetActiveScene());
        }

        private void RefreshPrompt(Scene scene)
        {
            if (provider == null)
            {
                HidePrompt();
                return;
            }

            ConsentStatus status = provider.AnalyticsConsent;
            bool dismissed =
                dismissedSceneHandle == scene.handle.GetRawData();
            if (!AnalyticsConsentPresentation.ShouldShowPrompt(
                    scene.name,
                    status,
                    dismissed))
            {
                HidePrompt();
                return;
            }

            if (promptCanvas == null && !TryCreatePrompt())
                return;

            ShowPrompt();
        }

        private bool TryCreatePrompt()
        {
            TMP_FontAsset font = FindFont();
            if (font == null)
            {
                Debug.LogError(
                    "Analytics consent prompt could not find a loaded TextMeshPro font.",
                    this);
                return false;
            }

            promptCanvas = new GameObject(
                "AnalyticsConsentPromptCanvas",
                typeof(RectTransform),
                typeof(Canvas),
                typeof(CanvasScaler),
                typeof(GraphicRaycaster));
            promptCanvas.transform.SetParent(transform, false);

            Canvas canvas = promptCanvas.GetComponent<Canvas>();
            canvas.renderMode = RenderMode.ScreenSpaceOverlay;
            canvas.overrideSorting = true;
            canvas.sortingOrder = 30000;
            CanvasScaler scaler = promptCanvas.GetComponent<CanvasScaler>();
            scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
            scaler.referenceResolution = new Vector2(1080f, 1920f);
            scaler.matchWidthOrHeight = 0.5f;

            var backdrop = new GameObject(
                "Backdrop",
                typeof(RectTransform),
                typeof(Image),
                typeof(Button));
            backdrop.transform.SetParent(promptCanvas.transform, false);
            Stretch(backdrop.GetComponent<RectTransform>());
            backdrop.GetComponent<Image>().color =
                new Color(0f, 0f, 0f, 0.76f);
            Button backdropButton = backdrop.GetComponent<Button>();
            backdropButton.targetGraphic = backdrop.GetComponent<Image>();
            backdropButton.onClick.AddListener(DismissPrompt);

            var panelObject = new GameObject(
                "ConsentPanel",
                typeof(RectTransform),
                typeof(Image));
            panelObject.transform.SetParent(promptCanvas.transform, false);
            RectTransform panelRect = panelObject.GetComponent<RectTransform>();
            panelRect.anchorMin = new Vector2(0.08f, 0.5f);
            panelRect.anchorMax = new Vector2(0.92f, 0.5f);
            panelRect.pivot = new Vector2(0.5f, 0.5f);
            panelRect.sizeDelta = new Vector2(0f, 1040f);
            panelObject.GetComponent<Image>().color =
                new Color(0.13f, 0.1f, 0.18f, 1f);

            EventTrigger cancelTrigger =
                panelObject.AddComponent<EventTrigger>();
            var cancelEntry = new EventTrigger.Entry
            {
                eventID = EventTriggerType.Cancel
            };
            cancelEntry.callback.AddListener(_ => DismissPrompt());
            cancelTrigger.triggers.Add(cancelEntry);

            CreateText(
                panelObject.transform,
                "PromptTitle",
                "Help Improve Dessert Merge Cafe",
                font,
                54f,
                FontStyles.Bold,
                new Vector2(0.07f, 0.78f),
                new Vector2(0f, 0f),
                new Vector2(0.88f, 0.94f));
            CreateText(
                panelObject.transform,
                "PromptDescription",
                "Would you like to share optional game usage analytics to help us understand performance and improve the game?",
                font,
                37f,
                FontStyles.Normal,
                new Vector2(0.07f, 0.56f),
                new Vector2(0f, 0f),
                new Vector2(0.86f, 0.77f));
            CreateText(
                panelObject.transform,
                "PromptDisclosure",
                "Unity Analytics may process device information, installation identifiers, IP addresses, and session events. You can change your choice anytime in Settings. When you turn Analytics off, the SDK may send events already buffered.",
                font,
                28f,
                FontStyles.Normal,
                new Vector2(0.07f, 0.32f),
                new Vector2(0f, 0f),
                new Vector2(0.86f, 0.55f));

            CreateButton(
                panelObject.transform,
                "PrivacyPolicy",
                "Privacy Policy",
                font,
                29f,
                new Vector2(0.22f, 0.21f),
                Vector2.zero,
                new Vector2(0.78f, 0.29f),
                Vector2.zero,
                OpenPrivacyPolicy);
            CreateButton(
                panelObject.transform,
                "AllowAnalytics",
                "Allow Analytics",
                font,
                29f,
                new Vector2(0.06f, 0.07f),
                Vector2.zero,
                new Vector2(0.49f, 0.19f),
                Vector2.zero,
                AllowAnalytics);
            CreateButton(
                panelObject.transform,
                "DeclineAnalytics",
                "No Thanks",
                font,
                29f,
                new Vector2(0.51f, 0.07f),
                Vector2.zero,
                new Vector2(0.94f, 0.19f),
                Vector2.zero,
                DeclineAnalytics);
            Button dismissButton = CreateButton(
                panelObject.transform,
                "DismissPrompt",
                "X",
                font,
                34f,
                new Vector2(0.88f, 0.9f),
                Vector2.zero,
                new Vector2(0.97f, 0.98f),
                Vector2.zero,
                DismissPrompt);
            dismissButtonObject = dismissButton.gameObject;
            promptCanvas.SetActive(false);

            return true;
        }

        private void AllowAnalytics()
        {
            if (provider != null)
                AnalyticsConsentPresentation.ApplyChoice(provider, true);
        }

        private void DeclineAnalytics()
        {
            if (provider != null)
                AnalyticsConsentPresentation.ApplyChoice(provider, false);
        }

        private void DismissPrompt()
        {
            if (promptCanvas == null || !promptCanvas.activeSelf)
                return;

            dismissedSceneHandle =
                SceneManager.GetActiveScene().handle.GetRawData();
            HidePrompt();
        }

        private void ShowPrompt()
        {
            if (promptCanvas == null || promptCanvas.activeSelf)
                return;

            promptEventSystem = EventSystem.current;
            if (promptEventSystem != null)
                previouslySelectedObject =
                    promptEventSystem.currentSelectedGameObject;

            promptCanvas.SetActive(true);
            if (promptEventSystem != null && dismissButtonObject != null)
                promptEventSystem.SetSelectedGameObject(dismissButtonObject);
        }

        private void HidePrompt()
        {
            if (promptCanvas == null || !promptCanvas.activeSelf)
                return;

            promptCanvas.SetActive(false);
            if (promptEventSystem != null)
            {
                GameObject selection =
                    previouslySelectedObject != null &&
                    previouslySelectedObject.activeInHierarchy
                        ? previouslySelectedObject
                        : null;
                promptEventSystem.SetSelectedGameObject(selection);
            }

            promptEventSystem = null;
            previouslySelectedObject = null;
        }

        private static void OpenPrivacyPolicy()
        {
            Application.OpenURL(AnalyticsConsentPresentation.PrivacyPolicyUrl);
        }

        private static TMP_FontAsset FindFont()
        {
            TMP_FontAsset[] fonts =
                Resources.FindObjectsOfTypeAll<TMP_FontAsset>();
            return fonts.Length > 0
                ? fonts[0]
                : TMP_Settings.defaultFontAsset;
        }

        private static void Stretch(RectTransform rect)
        {
            rect.anchorMin = Vector2.zero;
            rect.anchorMax = Vector2.one;
            rect.offsetMin = Vector2.zero;
            rect.offsetMax = Vector2.zero;
        }

        private static TMP_Text CreateText(
            Transform parent,
            string objectName,
            string value,
            TMP_FontAsset font,
            float fontSize,
            FontStyles style,
            Vector2 anchorMin,
            Vector2 offsetMin,
            Vector2 anchorMax)
        {
            var textObject = new GameObject(
                objectName,
                typeof(RectTransform),
                typeof(TextMeshProUGUI));
            textObject.transform.SetParent(parent, false);
            RectTransform rect = textObject.GetComponent<RectTransform>();
            rect.anchorMin = anchorMin;
            rect.anchorMax = anchorMax;
            rect.offsetMin = offsetMin;
            rect.offsetMax = Vector2.zero;

            TMP_Text text = textObject.GetComponent<TextMeshProUGUI>();
            text.font = font;
            text.text = value;
            text.fontSize = fontSize;
            text.fontStyle = style;
            text.color = Color.white;
            text.alignment = TextAlignmentOptions.MidlineLeft;
            text.textWrappingMode = TextWrappingModes.Normal;
            return text;
        }

        private static Button CreateButton(
            Transform parent,
            string objectName,
            string label,
            TMP_FontAsset font,
            float fontSize,
            Vector2 anchorMin,
            Vector2 offsetMin,
            Vector2 anchorMax,
            Vector2 offsetMax,
            UnityEngine.Events.UnityAction onClick)
        {
            var buttonObject = new GameObject(
                objectName,
                typeof(RectTransform),
                typeof(Image),
                typeof(Button));
            buttonObject.transform.SetParent(parent, false);
            RectTransform rect = buttonObject.GetComponent<RectTransform>();
            rect.anchorMin = anchorMin;
            rect.anchorMax = anchorMax;
            rect.offsetMin = offsetMin;
            rect.offsetMax = offsetMax;

            Image image = buttonObject.GetComponent<Image>();
            image.color = ButtonColor;
            Button button = buttonObject.GetComponent<Button>();
            button.targetGraphic = image;
            button.onClick.AddListener(onClick);

            var textObject = new GameObject(
                objectName + "Label",
                typeof(RectTransform),
                typeof(TextMeshProUGUI));
            textObject.transform.SetParent(buttonObject.transform, false);
            Stretch(textObject.GetComponent<RectTransform>());
            TMP_Text text = textObject.GetComponent<TextMeshProUGUI>();
            text.font = font;
            text.text = label;
            text.fontSize = fontSize;
            text.fontStyle = FontStyles.Bold;
            text.color = Color.white;
            text.alignment = TextAlignmentOptions.Center;
            text.textWrappingMode = TextWrappingModes.Normal;
            return button;
        }

        private static readonly Color ButtonColor =
            new Color(0.35f, 0.18f, 0.58f, 1f);
    }
}
