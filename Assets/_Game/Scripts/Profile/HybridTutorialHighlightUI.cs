using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

namespace SweetMerge.Profile
{
    public sealed class HybridTutorialHighlightUI : MonoBehaviour
    {
        private const float EdgeThickness = 5f;
        private const float Padding = 12f;

        private CanvasGroup canvasGroup;
        private RectTransform highlightRect;
        private Transform targetTransform;
        private TutorialStage cachedTargetStage;
        private SceneHandle cachedTargetSceneHandle;
        private bool hasCachedTarget;
        private Image[] edges;
        private HybridTutorialController controller;
        private bool subscribed;
        private readonly List<GameObject> rootObjects =
            new List<GameObject>();
        private readonly List<Transform> childTransforms =
            new List<Transform>();
        private readonly List<Renderer> childRenderers =
            new List<Renderer>();

        [RuntimeInitializeOnLoadMethod(
            RuntimeInitializeLoadType.AfterSceneLoad)]
        private static void CreateForGame()
        {
            Scene scene = SceneManager.GetActiveScene();
            if (!scene.IsValid() ||
                scene.name != SceneNavigationManager.MergeGameplayScene)
                return;

            Canvas canvas = FindCanvas(scene, "GameplayCanvas");
            if (canvas == null ||
                canvas.GetComponentInChildren<
                    HybridTutorialHighlightUI>(true) != null)
                return;

            GameObject host = new GameObject(
                nameof(HybridTutorialHighlightUI),
                typeof(RectTransform));
            host.transform.SetParent(canvas.transform, false);
            host.AddComponent<HybridTutorialHighlightUI>();
        }

        private void Awake()
        {
            RectTransform hostRect = GetComponent<RectTransform>();
            hostRect.anchorMin = Vector2.zero;
            hostRect.anchorMax = Vector2.one;
            hostRect.offsetMin = Vector2.zero;
            hostRect.offsetMax = Vector2.zero;

            canvasGroup = gameObject.AddComponent<CanvasGroup>();
            canvasGroup.blocksRaycasts = false;
            canvasGroup.interactable = false;
            canvasGroup.ignoreParentGroups = true;

            SafeAreaFitter safeAreaFitter =
                gameObject.AddComponent<SafeAreaFitter>();
            safeAreaFitter.enabled = true;

            highlightRect = CreateHighlightRect();
            edges = CreateEdges(highlightRect);
            HideHighlight();
            EditableUIView.Attach(highlightRect.gameObject, "TutorialHighlight");
        }

        private void OnEnable()
        {
            Subscribe();
            SceneManager.activeSceneChanged += HandleActiveSceneChanged;
            SceneManager.sceneUnloaded += HandleSceneUnloaded;
            Refresh();
        }

        private void OnDisable()
        {
            Unsubscribe();
            SceneManager.activeSceneChanged -= HandleActiveSceneChanged;
            SceneManager.sceneUnloaded -= HandleSceneUnloaded;
            InvalidateTargetCache();
            HideHighlight();
        }

        private void Update()
        {
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
            subscribed = true;
        }

        private void Unsubscribe()
        {
            if (!subscribed || controller == null)
                return;

            controller.StateChanged -= HandleStateChanged;
            controller.RecoveryStateChanged -= HandleRecoveryChanged;
            subscribed = false;
        }

        private void HandleStateChanged(
            TutorialProgressState nextState)
        {
            Refresh();
        }

        private void HandleRecoveryChanged()
        {
            Refresh();
        }

        private void HandleActiveSceneChanged(
            Scene previousScene,
            Scene nextScene)
        {
            InvalidateTargetCache();
            if (nextScene.name == SceneNavigationManager.MergeGameplayScene)
                Refresh();
            else
                HideHighlight();
        }

        private void HandleSceneUnloaded(Scene scene)
        {
            if (hasCachedTarget &&
                scene.handle == cachedTargetSceneHandle)
            {
                InvalidateTargetCache();
                HideHighlight();
            }
        }

        private void Refresh()
        {
            controller = HybridTutorialController.Instance;
            if (controller == null ||
                !controller.IsReady ||
                controller.State.IsCompleted)
            {
                HideHighlight();
                return;
            }

            TutorialStage stage = controller.State.Stage;
            if (!TryResolveTarget(stage, out Transform target))
            {
                HideHighlight();
                return;
            }

            targetTransform = target;
            if (!TryUpdateHighlightBounds())
                HideHighlight();
        }

        private bool TryResolveTarget(
            TutorialStage stage,
            out Transform target)
        {
            target = null;
            Scene scene = SceneManager.GetActiveScene();
            if (!scene.IsValid() ||
                scene.name != SceneNavigationManager.MergeGameplayScene)
            {
                InvalidateTargetCache();
                return false;
            }

            if (hasCachedTarget &&
                cachedTargetStage == stage &&
                cachedTargetSceneHandle == scene.handle &&
                targetTransform != null &&
                targetTransform.gameObject.scene == scene)
            {
                target = targetTransform;
                return true;
            }

            targetTransform = null;
            cachedTargetStage = stage;
            cachedTargetSceneHandle = scene.handle;
            hasCachedTarget = true;

            bool found;
            switch (stage)
            {
                case TutorialStage.Spawn:
                    found = TryFindComponentTransform<OvenController>(
                        scene, "Oven", out target);
                    break;
                case TutorialStage.Merge:
                    found = TryFindComponentTransform<GridManager>(
                        scene, "Grid", out target);
                    break;
                case TutorialStage.Order:
                    found = TryFindComponentTransform<OrderUI>(
                        scene, "OrderPanel", out target);
                    break;
                default:
                    return false;
            }

            if (found)
                targetTransform = target;
            return found;
        }

        private bool TryFindComponentTransform<T>(
            Scene scene,
            string objectName,
            out Transform target)
            where T : Component
        {
            target = null;
            rootObjects.Clear();
            scene.GetRootGameObjects(rootObjects);
            foreach (GameObject root in rootObjects)
            {
                childTransforms.Clear();
                root.GetComponentsInChildren(true, childTransforms);
                foreach (Transform candidate in childTransforms)
                {
                    if (candidate.name != objectName ||
                        candidate.gameObject.scene != scene ||
                        candidate.GetComponent<T>() == null)
                        continue;

                    target = candidate;
                    return true;
                }
            }

            return false;
        }

        private void InvalidateTargetCache()
        {
            targetTransform = null;
            hasCachedTarget = false;
        }

        private bool TryUpdateHighlightBounds()
        {
            if (targetTransform == null ||
                !targetTransform.gameObject.activeInHierarchy ||
                highlightRect == null)
                return false;

            if (!TryGetScreenBounds(
                    targetTransform,
                    out Rect screenBounds))
                return false;

            RectTransform parent =
                highlightRect.parent as RectTransform;
            if (parent == null)
                return false;

            Vector2 min;
            Vector2 max;
            if (!RectTransformUtility.ScreenPointToLocalPointInRectangle(
                    parent,
                    screenBounds.min,
                    null,
                    out min) ||
                !RectTransformUtility.ScreenPointToLocalPointInRectangle(
                    parent,
                    screenBounds.max,
                    null,
                    out max))
                return false;

            min -= Vector2.one * Padding;
            max += Vector2.one * Padding;
            highlightRect.anchoredPosition = (min + max) * 0.5f;
            highlightRect.sizeDelta = max - min;
            SetEdges(edges);
            canvasGroup.alpha = 1f;
            canvasGroup.gameObject.SetActive(true);
            return true;
        }

        private bool TryGetScreenBounds(
            Transform target,
            out Rect screenBounds)
        {
            screenBounds = default;
            RectTransform targetRect =
                target as RectTransform;
            if (targetRect != null)
            {
                targetRect.GetWorldCorners(worldCorners);
                Vector2 min = new Vector2(
                    float.PositiveInfinity,
                    float.PositiveInfinity);
                Vector2 max = new Vector2(
                    float.NegativeInfinity,
                    float.NegativeInfinity);

                for (int i = 0; i < worldCorners.Length; i++)
                {
                    Vector2 point = RectTransformUtility.WorldToScreenPoint(
                        null,
                        worldCorners[i]);
                    min = Vector2.Min(min, point);
                    max = Vector2.Max(max, point);
                }

                screenBounds = Rect.MinMaxRect(
                    min.x,
                    min.y,
                    max.x,
                    max.y);
                return screenBounds.width > 0f &&
                    screenBounds.height > 0f;
            }

            childRenderers.Clear();
            target.GetComponentsInChildren(true, childRenderers);
            Bounds bounds = default;
            bool hasBounds = false;
            foreach (Renderer renderer in childRenderers)
            {
                if (!renderer.enabled ||
                    !renderer.gameObject.activeInHierarchy)
                    continue;

                if (!hasBounds)
                {
                    bounds = renderer.bounds;
                    hasBounds = true;
                }
                else
                {
                    bounds.Encapsulate(renderer.bounds);
                }
            }

            Camera camera = Camera.main;
            if (!hasBounds || camera == null)
                return false;

            Vector3 center = bounds.center;
            Vector3 extents = bounds.extents;
            Vector2 minWorld = new Vector2(
                float.PositiveInfinity,
                float.PositiveInfinity);
            Vector2 maxWorld = new Vector2(
                float.NegativeInfinity,
                float.NegativeInfinity);
            for (int i = 0; i < 4; i++)
            {
                Vector3 worldPoint = center + new Vector3(
                    (i & 1) == 0 ? -extents.x : extents.x,
                    (i & 2) == 0 ? -extents.y : extents.y,
                    0f);
                Vector2 point = RectTransformUtility.WorldToScreenPoint(
                    camera,
                    worldPoint);
                minWorld = Vector2.Min(minWorld, point);
                maxWorld = Vector2.Max(maxWorld, point);
            }

            screenBounds = Rect.MinMaxRect(
                minWorld.x,
                minWorld.y,
                maxWorld.x,
                maxWorld.y);
            return screenBounds.width > 0f &&
                screenBounds.height > 0f;
        }

        private void HideHighlight()
        {
            if (canvasGroup != null)
                canvasGroup.alpha = 0f;
        }

        private RectTransform CreateHighlightRect()
        {
            GameObject value = new GameObject("Highlight");
            value.transform.SetParent(transform, false);
            RectTransform rect = value.AddComponent<RectTransform>();
            rect.anchorMin = new Vector2(.5f, .5f);
            rect.anchorMax = new Vector2(.5f, .5f);
            return rect;
        }

        private static Image[] CreateEdges(
            RectTransform parent)
        {
            Image[] values = new Image[4];
            for (int i = 0; i < values.Length; i++)
            {
                GameObject value = new GameObject("Edge" + i);
                value.transform.SetParent(parent, false);
                Image image = value.AddComponent<Image>();
                image.color = new Color(1f, .75f, .2f, .9f);
                image.raycastTarget = false;
                values[i] = image;
            }

            return values;
        }

        private static void SetEdges(Image[] values)
        {
            SetEdge(values[0].rectTransform, 0f, 1f, 1f, 1f);
            SetEdge(values[1].rectTransform, 0f, 0f, 1f, 0f);
            SetEdge(values[2].rectTransform, 0f, 0f, 0f, 1f);
            SetEdge(values[3].rectTransform, 1f, 0f, 1f, 1f);
            values[0].rectTransform.sizeDelta =
                new Vector2(0f, EdgeThickness);
            values[1].rectTransform.sizeDelta =
                new Vector2(0f, EdgeThickness);
            values[2].rectTransform.sizeDelta =
                new Vector2(EdgeThickness, 0f);
            values[3].rectTransform.sizeDelta =
                new Vector2(EdgeThickness, 0f);
        }

        private static void SetEdge(
            RectTransform rect,
            float minX,
            float minY,
            float maxX,
            float maxY)
        {
            rect.anchorMin = new Vector2(minX, minY);
            rect.anchorMax = new Vector2(maxX, maxY);
            rect.offsetMin = Vector2.zero;
            rect.offsetMax = Vector2.zero;
        }

        private static Canvas FindCanvas(
            Scene scene,
            string canvasName)
        {
            foreach (GameObject root in scene.GetRootGameObjects())
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

        private readonly Vector3[] worldCorners =
            new Vector3[4];
    }
}
