using TMPro;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

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

        [RuntimeInitializeOnLoadMethod(
            RuntimeInitializeLoadType.AfterSceneLoad)]
        private static void CreateForMainBakery()
        {
            Scene scene = SceneManager.GetActiveScene();
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
                nameof(HybridTutorialWelcomeUI));
            host.transform.SetParent(canvas.transform, false);
            host.AddComponent<HybridTutorialWelcomeUI>();
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
            panel = CreatePanel(transform, "WelcomePanel");
            titleText = CreateText(panel.transform, "Title", 42);
            titleText.text = "Welcome to your dessert café!";
            bodyText = CreateText(panel.transform, "Body", 28);
            bodyText.text = "Let's bake your first dessert.";
            startButton = CreateButton(panel.transform, "Start Baking");
            startButton.onClick.AddListener(HandleStartClicked);

            RectTransform root = panel.GetComponent<RectTransform>();
            root.anchorMin = new Vector2(.1f, .25f);
            root.anchorMax = new Vector2(.9f, .75f);
            root.offsetMin = Vector2.zero;
            root.offsetMax = Vector2.zero;
            SetAnchors(
                titleText.rectTransform,
                new Vector2(.08f, .62f),
                new Vector2(.92f, .84f));
            SetAnchors(
                bodyText.rectTransform,
                new Vector2(.08f, .46f),
                new Vector2(.92f, .62f));
        }

        private void HandleStartClicked()
        {
            controller?.DismissWelcome();
            Refresh();
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
            controller.TutorialCompleted += HandleCompleted;
            subscribed = true;
        }

        private void Unsubscribe()
        {
            if (!subscribed || controller == null)
                return;

            controller.StateChanged -= HandleStateChanged;
            controller.RecoveryStateChanged -= HandleRecoveryChanged;
            controller.TutorialCompleted -= HandleCompleted;
            subscribed = false;
        }

        private void HandleStateChanged(TutorialProgressState nextState)
        {
            Refresh();
        }

        private void HandleRecoveryChanged()
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
            image.color = new Color(0.12f, 0.08f, 0.05f, 0.94f);
            image.raycastTarget = false;
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
            RectTransform rect = value.GetComponent<RectTransform>();
            rect.anchorMin = new Vector2(.08f, .65f);
            rect.anchorMax = new Vector2(.92f, .9f);
            rect.offsetMin = Vector2.zero;
            rect.offsetMax = Vector2.zero;
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
            RectTransform buttonRect = value.GetComponent<RectTransform>();
            buttonRect.anchorMin = new Vector2(.25f, .12f);
            buttonRect.anchorMax = new Vector2(.75f, .3f);
            buttonRect.offsetMin = Vector2.zero;
            buttonRect.offsetMax = Vector2.zero;
            TMP_Text text = CreateText(value.transform, "Label", 24);
            text.text = label;
            RectTransform textRect = text.rectTransform;
            textRect.anchorMin = Vector2.zero;
            textRect.anchorMax = Vector2.one;
            textRect.offsetMin = Vector2.zero;
            textRect.offsetMax = Vector2.zero;
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
