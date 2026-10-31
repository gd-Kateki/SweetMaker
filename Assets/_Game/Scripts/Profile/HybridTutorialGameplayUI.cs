using System.Collections;
using TMPro;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

namespace SweetMerge.Profile
{
    public sealed class HybridTutorialGameplayUI : MonoBehaviour
    {
        private HybridTutorialController controller;
        private OrderManager orderManager;
        private GameObject instructionPanel;
        private TMP_Text instructionText;
        private GameObject recoveryPanel;
        private TMP_Text recoveryText;
        private Button retryButton;
        private bool subscribed;
        private bool completionDepartureStarted;
        private string completionError;
        private static Sprite uiSprite;

        [RuntimeInitializeOnLoadMethod(
            RuntimeInitializeLoadType.BeforeSceneLoad)]
        private static void RegisterSceneLoadedHandler()
        {
            SceneManager.sceneLoaded -= HandleSceneLoaded;
            SceneManager.sceneLoaded += HandleSceneLoaded;
            CreateForGame(SceneManager.GetActiveScene());
        }

        private static void HandleSceneLoaded(
            Scene scene,
            LoadSceneMode mode)
        {
            CreateForGame(scene);
        }

        private static void CreateForGame(Scene scene)
        {
            if (!scene.IsValid() ||
                scene.name !=
                    SceneNavigationManager.MergeGameplayScene)
                return;

            Canvas canvas = FindCanvas(
                scene,
                "GameplayCanvas");
            if (canvas == null ||
                canvas.GetComponentInChildren<
                    HybridTutorialGameplayUI>(true) != null)
                return;

            GameObject host = new GameObject(
                nameof(HybridTutorialGameplayUI),
                typeof(RectTransform));
            host.transform.SetParent(canvas.transform, false);
            host.AddComponent<HybridTutorialGameplayUI>();
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
            Refresh();
        }

        private void OnDisable()
        {
            Unsubscribe();
        }

        private void BuildPanel()
        {
            instructionPanel = CreatePanel(
                transform,
                "InstructionPanel",
                false);
            instructionText = CreateText(
                instructionPanel.transform,
                "InstructionText",
                "Tap the Oven to create a dessert.",
                26f,
                22f,
                28f);
            SetAnchors(
                instructionPanel.GetComponent<RectTransform>(),
                new Vector2(.08f, .77f),
                new Vector2(.92f, .91f));
            SetAnchors(
                instructionText.rectTransform,
                new Vector2(.035f, .08f),
                new Vector2(.965f, .92f));

            recoveryPanel = CreatePanel(
                transform,
                "RecoveryPanel",
                false);
            recoveryText = CreateText(
                recoveryPanel.transform,
                "RecoveryText",
                string.Empty,
                20f,
                17f,
                22f);
            SetAnchors(
                recoveryPanel.GetComponent<RectTransform>(),
                new Vector2(.06f, .13f),
                new Vector2(.94f, .3f));
            SetAnchors(
                recoveryText.rectTransform,
                new Vector2(.035f, .08f),
                new Vector2(.68f, .92f));
            retryButton = CreateButton(
                recoveryPanel.transform,
                "Retry",
                new Vector2(.72f, .16f),
                new Vector2(.96f, .84f));
            retryButton.onClick.AddListener(HandleRetryClicked);
        }

        private void HandleRetryClicked()
        {
            if (controller != null &&
                controller.State.IsCompleted &&
                !string.IsNullOrEmpty(completionError))
            {
                HandleTutorialCompleted();
                return;
            }

            controller?.RetryProgressRecovery();
            Refresh();
        }

        private void Subscribe()
        {
            BindOrderManager();
            if (subscribed)
                return;

            controller = HybridTutorialController.Instance;
            if (controller == null)
                return;

            controller.StateChanged += HandleChanged;
            controller.RecoveryStateChanged += HandleRecoveryChanged;
            controller.ReadinessChanged += HandleReadinessChanged;
            controller.TutorialOrderCompletionPersisted +=
                HandleTutorialCompleted;
            subscribed = true;
        }

        private void Unsubscribe()
        {
            UnbindOrderManager();
            if (!subscribed || controller == null)
                return;

            controller.StateChanged -= HandleChanged;
            controller.RecoveryStateChanged -= HandleRecoveryChanged;
            controller.ReadinessChanged -= HandleReadinessChanged;
            controller.TutorialOrderCompletionPersisted -=
                HandleTutorialCompleted;
            subscribed = false;
        }

        private void BindOrderManager()
        {
            OrderManager current = FindAnyObjectByType<OrderManager>();
            if (ReferenceEquals(orderManager, current))
                return;

            UnbindOrderManager();
            orderManager = current;
            if (orderManager != null)
                orderManager.CustomerOrderChanged += HandleCustomerOrderChanged;
        }

        private void UnbindOrderManager()
        {
            if (orderManager == null)
                return;

            orderManager.CustomerOrderChanged -= HandleCustomerOrderChanged;
            orderManager = null;
        }

        private void HandleCustomerOrderChanged(
            int customerIndex,
            CustomerOrder order)
        {
            Refresh();
        }

        private void HandleChanged(TutorialProgressState nextState)
        {
            Refresh();
        }

        private void HandleRecoveryChanged()
        {
            Refresh();
        }

        private void HandleReadinessChanged()
        {
            Refresh();
        }

        private void HandleTutorialCompleted()
        {
            if (completionDepartureStarted)
                return;

            completionDepartureStarted = true;
            completionError = null;
            StartCoroutine(ReturnToMainBakeryAfterCompletion());
        }

        private IEnumerator ReturnToMainBakeryAfterCompletion()
        {
            OrderManager orderManager =
                FindAnyObjectByType<OrderManager>();
            while (orderManager != null && orderManager.IsFulfilling)
                yield return null;

            controller = HybridTutorialController.Instance;
            if (controller == null ||
                !controller.IsReady ||
                !controller.State.IsCompleted)
            {
                FailCompletionDeparture(
                    "Tutorial completion could not be verified locally. Remain in Game and retry.");
                yield break;
            }

            EconomyManager economy = EconomyManager.Instance;
            if (economy == null ||
                !economy.TryCommitTutorialOrderReward())
            {
                FailCompletionDeparture(
                    "The tutorial order reward could not be committed. Progress was not sent to MainBakery.");
                yield break;
            }

            MergeSessionController[] controllers =
                FindObjectsByType<MergeSessionController>();
            if (controllers.Length != 1 ||
                controllers[0] == null ||
                !controllers[0].isActiveAndEnabled ||
                !controllers[0].PrepareToLeaveGameplay())
            {
                FailCompletionDeparture(
                    "The completed tutorial could not be saved safely. Remain in Game and retry.");
                yield break;
            }

            SceneNavigationManager navigation =
                SceneNavigationManager.Instance;
            if (navigation == null)
            {
                controllers[0].CancelPreparedDeparture();
                FailCompletionDeparture(
                    "Scene navigation is unavailable. The verified gameplay session was restored.");
                yield break;
            }

            navigation.GoToMainBakery();
        }

        private void FailCompletionDeparture(string message)
        {
            completionDepartureStarted = false;
            completionError = message;
            Refresh();
            Debug.LogError("TUTORIAL | " + message);
        }

        private void Refresh()
        {
            BindOrderManager();
            controller = HybridTutorialController.Instance;
            if (controller == null)
            {
                instructionPanel.SetActive(false);
                recoveryPanel.SetActive(false);
                return;
            }

            bool ready = controller.IsReady &&
                !controller.State.IsCompleted;
            instructionPanel.SetActive(ready &&
                controller.State.Stage != TutorialStage.Welcome);
            instructionText.text = GetInstruction(
                controller.State.Stage,
                orderManager != null &&
                orderManager.HasTutorialOrderForFirstCustomer);

            bool showRecovery = controller.HasRecoverableError ||
                !string.IsNullOrEmpty(completionError);
            recoveryPanel.SetActive(showRecovery);
            recoveryText.text = !string.IsNullOrEmpty(completionError)
                ? completionError
                : controller.RecoverableError;
        }

        private static string GetInstruction(
            TutorialStage stage,
            bool hasTutorialOrder)
        {
            switch (stage)
            {
                case TutorialStage.Spawn:
                    return "Tap the Oven to create a dessert.";
                case TutorialStage.Merge:
                    return hasTutorialOrder
                        ? "Drag matching desserts together to merge them."
                        : "Merge matching desserts. Complete your current order first; the tutorial request will appear next.";
                case TutorialStage.Order:
                    return hasTutorialOrder
                        ? "Make and place two Tier 3 desserts, then complete the tutorial customer's order."
                        : "Complete your current customer order to preserve it. Your Tier 3 tutorial order will appear next.";
                default:
                    return string.Empty;
            }
        }

        private static GameObject CreatePanel(
            Transform parent,
            string objectName,
            bool raycastTarget)
        {
            GameObject value = new GameObject(objectName);
            value.transform.SetParent(parent, false);
            Image image = value.AddComponent<Image>();
            image.sprite = GetUiSprite();
            image.color = new Color(0.12f, 0.08f, 0.05f, 0.86f);
            image.raycastTarget = raycastTarget;
            return value;
        }

        private static TMP_Text CreateText(
            Transform parent,
            string objectName,
            string value,
            float fontSize,
            float minimumFontSize,
            float maximumFontSize)
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
            string label,
            Vector2 anchorMin,
            Vector2 anchorMax)
        {
            GameObject value = new GameObject(
                label + "Button",
                typeof(RectTransform));
            value.transform.SetParent(parent, false);
            Image image = value.AddComponent<Image>();
            image.sprite = GetUiSprite();
            image.color = new Color(0.85f, 0.55f, 0.2f, 1f);
            image.raycastTarget = true;
            Button button = value.AddComponent<Button>();
            button.targetGraphic = image;
            SetAnchors(value.GetComponent<RectTransform>(), anchorMin, anchorMax);
            CreateText(
                value.transform,
                "Label",
                label,
                22f,
                19f,
                24f);
            return button;
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
