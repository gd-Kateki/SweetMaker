using TMPro;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

namespace SweetMerge.Profile
{
    public sealed class HybridTutorialGameplayUI : MonoBehaviour
    {
        private HybridTutorialController controller;
        private GameObject instructionPanel;
        private TMP_Text instructionText;
        private GameObject recoveryPanel;
        private TMP_Text recoveryText;
        private Button retryButton;
        private bool subscribed;

        [RuntimeInitializeOnLoadMethod(
            RuntimeInitializeLoadType.AfterSceneLoad)]
        private static void CreateForGame()
        {
            Scene scene = SceneManager.GetActiveScene();
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
                nameof(HybridTutorialGameplayUI));
            host.transform.SetParent(canvas.transform, false);
            host.AddComponent<HybridTutorialGameplayUI>();
        }

        private void Awake()
        {
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
                26);
            SetAnchors(
                instructionPanel.GetComponent<RectTransform>(),
                new Vector2(.08f, .82f),
                new Vector2(.92f, .94f));
            SetAnchors(
                instructionText.rectTransform,
                Vector2.zero,
                Vector2.one);

            recoveryPanel = CreatePanel(
                transform,
                "RecoveryPanel",
                false);
            recoveryText = CreateText(
                recoveryPanel.transform,
                "RecoveryText",
                22);
            SetAnchors(
                recoveryPanel.GetComponent<RectTransform>(),
                new Vector2(.08f, .08f),
                new Vector2(.92f, .2f));
            SetAnchors(
                recoveryText.rectTransform,
                new Vector2(.04f, .35f),
                new Vector2(.96f, .95f));
            retryButton = CreateButton(
                recoveryPanel.transform,
                "Retry");
            retryButton.onClick.AddListener(HandleRetryClicked);
        }

        private void HandleRetryClicked()
        {
            controller?.RetryProgressRecovery();
            Refresh();
        }

        private void Subscribe()
        {
            if (subscribed)
                return;

            controller = HybridTutorialController.Instance;
            if (controller == null)
                return;

            controller.StateChanged += HandleChanged;
            controller.RecoveryStateChanged += HandleRecoveryChanged;
            subscribed = true;
        }

        private void Unsubscribe()
        {
            if (!subscribed || controller == null)
                return;

            controller.StateChanged -= HandleChanged;
            controller.RecoveryStateChanged -= HandleRecoveryChanged;
            subscribed = false;
        }

        private void HandleChanged(TutorialProgressState nextState)
        {
            Refresh();
        }

        private void HandleRecoveryChanged()
        {
            Refresh();
        }

        private void Refresh()
        {
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
                controller.State.Stage);

            bool showRecovery = controller.HasRecoverableError;
            recoveryPanel.SetActive(showRecovery);
            recoveryText.text = controller.RecoverableError;
        }

        private static string GetInstruction(TutorialStage stage)
        {
            switch (stage)
            {
                case TutorialStage.Spawn:
                    return "Tap the Oven to create a dessert.";
                case TutorialStage.Merge:
                    return "Drag matching desserts together to merge them.";
                case TutorialStage.Order:
                    return "Complete a customer's order.";
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
            image.color = new Color(0.12f, 0.08f, 0.05f, 0.86f);
            image.raycastTarget = raycastTarget;
            return value;
        }

        private static TMP_Text CreateText(
            Transform parent,
            string objectName,
            float fontSize)
        {
            GameObject value = new GameObject(objectName);
            value.transform.SetParent(parent, false);
            TMP_Text text = value.AddComponent<TextMeshProUGUI>();
            text.fontSize = fontSize;
            text.alignment = TextAlignmentOptions.Center;
            text.color = Color.white;
            text.raycastTarget = false;
            return text;
        }

        private static Button CreateButton(
            Transform parent,
            string label)
        {
            GameObject value = new GameObject(label);
            value.transform.SetParent(parent, false);
            Image image = value.AddComponent<Image>();
            image.color = new Color(0.85f, 0.55f, 0.2f, 1f);
            Button button = value.AddComponent<Button>();
            SetAnchors(
                value.GetComponent<RectTransform>(),
                new Vector2(.7f, .05f),
                new Vector2(.96f, .3f));
            TMP_Text text = CreateText(value.transform, "Label", 22);
            text.text = label;
            SetAnchors(
                text.rectTransform,
                Vector2.zero,
                Vector2.one);
            return button;
        }

        private static void SetAnchors(
            RectTransform rect,
            Vector2 minimum,
            Vector2 maximum)
        {
            rect.anchorMin = minimum;
            rect.anchorMax = maximum;
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
