using System.Collections;
using TMPro;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
using SweetMerge.Startup;

namespace SweetMerge.Profile
{
    public sealed class HybridTutorialWelcomeUI : MonoBehaviour
    {
        private HybridTutorialController controller;
        private GameObject panel;
        private TMP_Text titleText;
        private TMP_Text bodyText;
        private Button startButton;
        private bool subscribed;
        private bool subscribedToReadiness;
        private bool enterGameplayAfterDismiss;
        private static bool isListeningForSceneLoads;
        private static Sprite uiSprite;

        [RuntimeInitializeOnLoadMethod(
            RuntimeInitializeLoadType.SubsystemRegistration)]
        private static void ResetSceneLoadedHandler()
        {
            SceneManager.sceneLoaded -= HandleSceneLoaded;
            isListeningForSceneLoads = false;
        }

        [RuntimeInitializeOnLoadMethod(
            RuntimeInitializeLoadType.BeforeSceneLoad)]
        private static void RegisterSceneLoadedHandler()
        {
            if (isListeningForSceneLoads)
                return;

            SceneManager.sceneLoaded -= HandleSceneLoaded;
            SceneManager.sceneLoaded += HandleSceneLoaded;
            isListeningForSceneLoads = true;
            CreateForMainBakery(SceneManager.GetActiveScene());
        }

        private static void HandleSceneLoaded(
            Scene scene,
            LoadSceneMode mode)
        {
            CreateForMainBakery(scene);
        }

        private static void CreateForMainBakery(Scene scene)
        {
            if (!scene.IsValid() ||
                scene.name != SceneNavigationManager.MainBakeryScene)
                return;

            Canvas canvas = FindCanvas(
                scene,
                "MainCanvas");
            if (canvas == null ||
                canvas.GetComponentInChildren<
                    HybridTutorialWelcomeUI>(true) != null)
                return;

            GameObject host = new GameObject(
                nameof(HybridTutorialWelcomeUI),
                typeof(RectTransform));
            host.transform.SetParent(canvas.transform, false);
            host.AddComponent<HybridTutorialWelcomeUI>();
        }

        private void Awake()
        {
            SetFullStretch((RectTransform)transform);
            gameObject.AddComponent<SafeAreaFitter>();
            BuildPanel();
        }

        private void OnEnable()
        {
            Subscribe();
            SubscribeToReadiness();
            Refresh();
        }

        private void OnDisable()
        {
            Unsubscribe();
            UnsubscribeFromReadiness();
        }

        private void BuildPanel()
        {
            panel = CreatePanel(transform, "WelcomePanel");
            titleText = CreateText(
                panel.transform,
                "Title",
                "Welcome to your dessert\ncafé!",
                32f,
                27f,
                34f,
                FontStyles.Bold);
            bodyText = CreateText(
                panel.transform,
                "Body",
                "Let's bake your first dessert\nand serve your first customer.",
                21f,
                18f,
                22f,
                FontStyles.Normal);
            BuildCafeIllustration(panel.transform);
            startButton = CreateButton(panel.transform, "Continue");
            startButton.onClick.AddListener(HandleStartClicked);

            RectTransform root = panel.GetComponent<RectTransform>();
            SetAnchors(root, new Vector2(.06f, .16f), new Vector2(.94f, .84f));
            SetAnchors(
                titleText.rectTransform,
                new Vector2(.07f, .79f),
                new Vector2(.93f, .96f));
            SetAnchors(
                bodyText.rectTransform,
                new Vector2(.08f, .63f),
                new Vector2(.92f, .78f));
        }

        private void HandleStartClicked()
        {
            controller = HybridTutorialController.Instance;
            if (controller == null ||
                !controller.IsReady ||
                controller.State.Stage != TutorialStage.Welcome ||
                controller.State.IsCompleted)
                return;

            enterGameplayAfterDismiss = true;
            controller.DismissWelcome();
            Refresh();
        }

        private IEnumerator EnterGameplayAfterWelcome()
        {
            yield return null;

            controller = HybridTutorialController.Instance;
            if (SceneManager.GetActiveScene().name !=
                    SceneNavigationManager.MainBakeryScene ||
                controller == null ||
                !controller.IsReady ||
                controller.State.Stage != TutorialStage.Spawn ||
                !SceneNavigationManager.CanEnterMergeGameplay())
                yield break;

            if (SceneNavigationManager.Instance != null)
            {
                SceneNavigationManager.Instance.GoToMergeGameplay();
                yield break;
            }

            SceneManager.LoadScene(
                SceneNavigationManager.MergeGameplayScene);
        }

        private void Subscribe()
        {
            if (subscribed)
                return;

            controller = HybridTutorialController.Instance;
            if (controller == null)
                return;

            controller.StateChanged += HandleStateChanged;
            controller.RecoveryStateChanged += HandleRecoveryChanged;
            controller.ReadinessChanged += HandleReadinessChanged;
            controller.TutorialCompleted += HandleCompleted;
            subscribed = true;
        }

        private void SubscribeToReadiness()
        {
            ApplicationReadinessCoordinator readiness =
                ApplicationReadinessCoordinator.Instance;
            if (subscribedToReadiness || readiness == null)
                return;

            readiness.StateChanged += HandleApplicationReadinessChanged;
            subscribedToReadiness = true;
        }

        private void UnsubscribeFromReadiness()
        {
            if (!subscribedToReadiness)
                return;

            ApplicationReadinessCoordinator readiness =
                ApplicationReadinessCoordinator.Instance;
            if (readiness != null)
                readiness.StateChanged -= HandleApplicationReadinessChanged;
            subscribedToReadiness = false;
        }

        private void Unsubscribe()
        {
            if (!subscribed || controller == null)
                return;

            controller.StateChanged -= HandleStateChanged;
            controller.RecoveryStateChanged -= HandleRecoveryChanged;
            controller.ReadinessChanged -= HandleReadinessChanged;
            controller.TutorialCompleted -= HandleCompleted;
            subscribed = false;
        }

        private void HandleStateChanged(TutorialProgressState nextState)
        {
            Refresh();

            if (!enterGameplayAfterDismiss)
                return;

            if (nextState.IsLocallyValidated &&
                nextState.Stage == TutorialStage.Spawn)
            {
                enterGameplayAfterDismiss = false;
                StartCoroutine(EnterGameplayAfterWelcome());
            }
            else if (!nextState.IsLocallyValidated)
            {
                enterGameplayAfterDismiss = false;
            }
        }

        private void HandleRecoveryChanged()
        {
            Refresh();
        }

        private void HandleReadinessChanged()
        {
            Refresh();
        }

        private void HandleApplicationReadinessChanged(
            ApplicationReadinessState state)
        {
            Refresh();
        }

        private void HandleCompleted()
        {
            Refresh();
        }

        private void Refresh()
        {
            if (panel == null)
                return;

            controller = HybridTutorialController.Instance;
            bool visible = controller != null &&
                controller.IsReady &&
                StartupFlowIntegrationOwner.CanPresentTutorialWelcome &&
                controller.State.Stage == TutorialStage.Welcome &&
                !controller.State.IsCompleted;
            panel.SetActive(visible);
        }

        private static GameObject CreatePanel(
            Transform parent,
            string objectName)
        {
            GameObject value = new GameObject(objectName);
            value.transform.SetParent(parent, false);
            Image image = value.AddComponent<Image>();
            image.sprite = GetUiSprite();
            image.color = new Color(0.12f, 0.08f, 0.05f, 0.94f);
            image.raycastTarget = true;
            return value;
        }

        private static TMP_Text CreateText(
            Transform parent,
            string objectName,
            string value,
            float fontSize,
            float minimumFontSize,
            float maximumFontSize,
            FontStyles fontStyle = FontStyles.Normal)
        {
            GameObject textObject = new GameObject(
                objectName,
                typeof(RectTransform));
            textObject.transform.SetParent(parent, false);
            TMP_Text text = textObject.AddComponent<TextMeshProUGUI>();
            text.text = value;
            text.fontSize = fontSize;
            text.fontSizeMin = minimumFontSize;
            text.fontSizeMax = maximumFontSize;
            text.enableAutoSizing = true;
            text.textWrappingMode = TextWrappingModes.Normal;
            text.overflowMode = TextOverflowModes.Ellipsis;
            text.alignment = TextAlignmentOptions.Center;
            text.verticalAlignment = VerticalAlignmentOptions.Middle;
            text.fontStyle = fontStyle;
            text.color = Color.white;
            text.raycastTarget = false;
            text.margin = new Vector4(12f, 8f, 12f, 8f);
            SetAnchors(
                text.rectTransform,
                Vector2.zero,
                Vector2.one);
            return text;
        }

        private static Button CreateButton(
            Transform parent,
            string label)
        {
            GameObject value = new GameObject(
                "ContinueButton",
                typeof(RectTransform));
            value.transform.SetParent(parent, false);
            Image image = value.AddComponent<Image>();
            image.sprite = GetUiSprite();
            image.color = new Color(0.85f, 0.55f, 0.2f, 1f);
            image.raycastTarget = true;
            Button button = value.AddComponent<Button>();
            button.targetGraphic = image;
            RectTransform buttonRect = value.GetComponent<RectTransform>();
            SetAnchors(
                buttonRect,
                new Vector2(.22f, .055f),
                new Vector2(.78f, .205f));
            CreateText(
                value.transform,
                "Label",
                label,
                23f,
                20f,
                24f,
                FontStyles.Bold);
            return button;
        }

        private static void BuildCafeIllustration(Transform parent)
        {
            GameObject illustration = new GameObject(
                "CafeIllustration",
                typeof(RectTransform));
            illustration.transform.SetParent(parent, false);
            SetAnchors(
                illustration.GetComponent<RectTransform>(),
                new Vector2(.15f, .27f),
                new Vector2(.85f, .61f));

            CreateImage(
                illustration.transform,
                "IllustrationBackdrop",
                new Vector2(.12f, .02f),
                new Vector2(.88f, .98f),
                new Color(.97f, .82f, .62f, 1f));
            CreateImage(
                illustration.transform,
                "CafeFacade",
                new Vector2(.25f, .12f),
                new Vector2(.75f, .83f),
                new Color(.55f, .31f, .19f, 1f));
            CreateImage(
                illustration.transform,
                "CafeRoof",
                new Vector2(.2f, .73f),
                new Vector2(.8f, .88f),
                new Color(.35f, .19f, .14f, 1f));
            CreateImage(
                illustration.transform,
                "Awning",
                new Vector2(.23f, .53f),
                new Vector2(.77f, .72f),
                new Color(.98f, .9f, .75f, 1f));

            Color[] awningColors =
            {
                new Color(.88f, .32f, .3f, 1f),
                new Color(.98f, .9f, .75f, 1f),
                new Color(.88f, .32f, .3f, 1f),
                new Color(.98f, .9f, .75f, 1f),
                new Color(.88f, .32f, .3f, 1f),
                new Color(.98f, .9f, .75f, 1f)
            };
            for (int i = 0; i < awningColors.Length; i++)
            {
                float minimum = i / (float)awningColors.Length;
                float maximum = (i + 1) / (float)awningColors.Length;
                CreateImage(
                    illustration.transform,
                    "AwningStripe" + i,
                    new Vector2(.23f + .54f * minimum, .53f),
                    new Vector2(.23f + .54f * maximum, .72f),
                    awningColors[i]);
            }

            CreateImage(
                illustration.transform,
                "Window",
                new Vector2(.31f, .27f),
                new Vector2(.49f, .49f),
                new Color(.43f, .77f, .79f, 1f));
            CreateImage(
                illustration.transform,
                "Door",
                new Vector2(.56f, .16f),
                new Vector2(.7f, .5f),
                new Color(.38f, .21f, .15f, 1f));
            CreateImage(
                illustration.transform,
                "DoorHandle",
                new Vector2(.65f, .29f),
                new Vector2(.68f, .33f),
                new Color(1f, .77f, .3f, 1f));
            CreateImage(
                illustration.transform,
                "CafeSign",
                new Vector2(.38f, .82f),
                new Vector2(.62f, .96f),
                new Color(1f, .91f, .72f, 1f));
            TMP_Text signText = CreateText(
                illustration.transform,
                "CafeSignText",
                "SWEET CAFE",
                16f,
                12f,
                17f,
                FontStyles.Bold);
            SetAnchors(
                signText.rectTransform,
                new Vector2(.39f, .83f),
                new Vector2(.61f, .95f));
        }

        private static Image CreateImage(
            Transform parent,
            string objectName,
            Vector2 anchorMin,
            Vector2 anchorMax,
            Color color)
        {
            GameObject value = new GameObject(
                objectName,
                typeof(RectTransform));
            value.transform.SetParent(parent, false);
            Image image = value.AddComponent<Image>();
            image.sprite = GetUiSprite();
            image.color = color;
            image.raycastTarget = false;
            SetAnchors(
                value.GetComponent<RectTransform>(),
                anchorMin,
                anchorMax);
            return image;
        }

        private static Sprite GetUiSprite()
        {
            if (uiSprite == null)
            {
                uiSprite = Sprite.Create(
                    Texture2D.whiteTexture,
                    new Rect(0f, 0f, 1f, 1f),
                    new Vector2(.5f, .5f));
            }

            return uiSprite;
        }

        private static void SetAnchors(
            RectTransform rect,
            Vector2 minimum,
            Vector2 maximum)
        {
            rect.pivot = new Vector2(.5f, .5f);
            rect.anchorMin = minimum;
            rect.anchorMax = maximum;
            rect.offsetMin = Vector2.zero;
            rect.offsetMax = Vector2.zero;
        }

        private static void SetFullStretch(RectTransform rect)
        {
            rect.pivot = new Vector2(.5f, .5f);
            rect.anchorMin = Vector2.zero;
            rect.anchorMax = Vector2.one;
            rect.offsetMin = Vector2.zero;
            rect.offsetMax = Vector2.zero;
        }

        private static Canvas FindCanvas(
            Scene scene,
            string canvasName)
        {
            GameObject[] roots = scene.GetRootGameObjects();
            foreach (GameObject root in roots)
            {
                Canvas[] canvases =
                    root.GetComponentsInChildren<Canvas>(true);
                foreach (Canvas candidate in canvases)
                {
                    if (candidate.name == canvasName &&
                        candidate.gameObject.scene == scene)
                        return candidate;
                }
            }

            return null;
        }
    }
}
