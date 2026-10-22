using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public sealed class SpawnPoolSelectorUI : MonoBehaviour
{
    private const float PanelWidth = 260f;
    private const float PanelHeight = 64f;
    private const float PreviewGap = 12f;
    private const float LayoutTolerance = 0.05f;

    [SerializeField]
    private Transform previewAnchor;

    private DessertSpawner dessertSpawner;
    private Canvas gameplayCanvas;
    private RectTransform canvasRect;
    private RectTransform panel;
    private SpriteRenderer previewRenderer;
    private Button previousButton;
    private Button nextButton;
    private TMP_Text poolText;
    private IReadOnlyList<string> unlockedPoolIds;
    private Rect lastPreviewBounds;
    private Rect lastUsableBounds;
    private Vector2 lastPanelSize;
    private Camera lastObservedCamera;
    private Rect lastObservedCameraPixelRect;
    private Rect lastObservedCanvasRect;
    private Rect lastObservedSafeArea;
    private Vector3 lastObservedCameraPosition;
    private Quaternion lastObservedCameraRotation;
    private float lastObservedOrthographicSize;
    private float lastObservedCameraAspect;
    private int lastObservedScreenWidth;
    private int lastObservedScreenHeight;
    private bool hasEvaluatedLayout;
    private bool hasObservedScreenLayout;
    private bool hasLoggedPlacementFailure;

    private void OnEnable()
    {
        GameplayEvents.NextDessertChanged += HandleNextDessertChanged;
    }

    private void Start()
    {
        dessertSpawner = FindAnyObjectByType<DessertSpawner>();
        gameplayCanvas = FindAnyObjectByType<Canvas>();
        if (dessertSpawner == null || gameplayCanvas == null)
        {
            Debug.LogError(
                "SPAWN POOL UI | DessertSpawner or gameplay Canvas is unavailable.");
            enabled = false;
            return;
        }

        gameplayCanvas = gameplayCanvas.rootCanvas;
        canvasRect = gameplayCanvas.transform as RectTransform;
        if (canvasRect == null ||
            gameplayCanvas.renderMode != RenderMode.ScreenSpaceOverlay)
        {
            Debug.LogError(
                "SPAWN POOL UI | A Screen Space Overlay Canvas is required.");
            enabled = false;
            return;
        }

        if (previewAnchor != null)
            previewRenderer = previewAnchor.GetComponentInChildren<SpriteRenderer>(true);

        CreateControls();
        dessertSpawner.SpawnPoolChanged += HandleSpawnPoolChanged;
        Refresh();
    }

    private void OnDestroy()
    {
        if (dessertSpawner != null)
            dessertSpawner.SpawnPoolChanged -= HandleSpawnPoolChanged;
    }

    private void OnDisable()
    {
        GameplayEvents.NextDessertChanged -= HandleNextDessertChanged;
        StopAllCoroutines();
    }

    private void Update()
    {
        if (HasScreenLayoutChanged())
            UpdatePosition();
    }

    private void HandleSpawnPoolChanged(string poolId, int firstTier, int highestTier)
    {
        Refresh();
    }

    private void HandleNextDessertChanged(DessertDefinition definition)
    {
        StartCoroutine(UpdatePositionAfterPreviewRefresh());
    }

    private IEnumerator UpdatePositionAfterPreviewRefresh()
    {
        yield return null;
        UpdatePosition();
    }

    private void OnApplicationFocus(bool hasFocus)
    {
        if (hasFocus)
            UpdatePosition();
    }

    private void OnApplicationPause(bool isPaused)
    {
        if (!isPaused)
            UpdatePosition();
    }

    private void CreateControls()
    {
        GameObject panelObject = new GameObject(
            "SpawnPoolSelector",
            typeof(RectTransform),
            typeof(Image));
        panel = panelObject.GetComponent<RectTransform>();
        panel.SetParent(gameplayCanvas.transform, false);
        panel.anchorMin = panel.anchorMax = new Vector2(0.5f, 0.5f);
        panel.pivot = new Vector2(0.5f, 0.5f);
        panel.sizeDelta = new Vector2(PanelWidth, PanelHeight);
        Image panelImage = panelObject.GetComponent<Image>();
        panelImage.raycastTarget = false;
        panelImage.color =
            new Color(0.16f, 0.12f, 0.2f, 0.9f);

        previousButton = CreateButton(panel, "PreviousPoolButton", "<");
        RectTransform previousRect = previousButton.GetComponent<RectTransform>();
        previousRect.anchorMin = previousRect.anchorMax = new Vector2(0, 0.5f);
        previousRect.pivot = new Vector2(0, 0.5f);
        previousRect.anchoredPosition = new Vector2(5f, 0);
        previousRect.sizeDelta = new Vector2(44f, 52f);
        previousButton.onClick.AddListener(SelectPreviousPool);

        nextButton = CreateButton(panel, "NextPoolButton", ">");
        RectTransform nextRect = nextButton.GetComponent<RectTransform>();
        nextRect.anchorMin = nextRect.anchorMax = new Vector2(1, 0.5f);
        nextRect.pivot = new Vector2(1, 0.5f);
        nextRect.anchoredPosition = new Vector2(-5f, 0);
        nextRect.sizeDelta = new Vector2(44f, 52f);
        nextButton.onClick.AddListener(SelectNextPool);

        poolText = CreateText(panel, "SelectedPoolLabel", 20f);
        RectTransform poolRect = poolText.rectTransform;
        poolRect.anchorMin = poolRect.anchorMax = new Vector2(0.5f, 0.5f);
        poolRect.pivot = new Vector2(0.5f, 0.5f);
        poolRect.anchoredPosition = Vector2.zero;
        poolRect.sizeDelta = new Vector2(156f, 46f);
    }

    private static Button CreateButton(Transform parent, string objectName, string label)
    {
        GameObject buttonObject = new GameObject(
            objectName,
            typeof(RectTransform),
            typeof(Image),
            typeof(Button));
        buttonObject.transform.SetParent(parent, false);
        Image image = buttonObject.GetComponent<Image>();
        image.color = new Color(0.43f, 0.27f, 0.48f, 1f);
        Button button = buttonObject.GetComponent<Button>();
        button.targetGraphic = image;

        TMP_Text text = CreateText(buttonObject.transform, "Label", 23f);
        text.text = label;
        RectTransform textRect = text.rectTransform;
        textRect.anchorMin = Vector2.zero;
        textRect.anchorMax = Vector2.one;
        textRect.offsetMin = Vector2.zero;
        textRect.offsetMax = Vector2.zero;
        return button;
    }

    private static TMP_Text CreateText(Transform parent, string objectName, float fontSize)
    {
        GameObject textObject = new GameObject(objectName, typeof(RectTransform));
        textObject.transform.SetParent(parent, false);
        TMP_Text text = textObject.AddComponent<TextMeshProUGUI>();
        text.font = TMP_Settings.defaultFontAsset;
        text.fontSize = fontSize;
        text.alignment = TextAlignmentOptions.Center;
        text.color = Color.white;
        text.raycastTarget = false;
        return text;
    }

    private void Refresh()
    {
        if (dessertSpawner == null || panel == null)
            return;

        unlockedPoolIds = dessertSpawner.UnlockedSpawnPoolIds;
        string selectedPoolId = dessertSpawner.SelectedSpawnPoolId;
        poolText.text =
            $"{selectedPoolId} | T{DessertSpawner.GetSpawnPoolFirstTier(selectedPoolId)}" +
            $"-T{DessertSpawner.GetSpawnPoolHighestTier(selectedPoolId)}";
        int selectedIndex = IndexOfSelectedPool();
        previousButton.interactable = unlockedPoolIds.Count > 1;
        nextButton.interactable = unlockedPoolIds.Count > 1;
        UpdatePosition();
    }

    private int IndexOfSelectedPool()
    {
        for (int i = 0; i < unlockedPoolIds.Count; i++)
            if (unlockedPoolIds[i] == dessertSpawner.SelectedSpawnPoolId)
                return i;
        return -1;
    }

    private void SelectPreviousPool()
    {
        if (unlockedPoolIds == null || unlockedPoolIds.Count < 2)
            return;

        int targetIndex = (IndexOfSelectedPool() - 1 + unlockedPoolIds.Count) %
                          unlockedPoolIds.Count;
        if (targetIndex >= 0)
            dessertSpawner.TrySelectSpawnPool(unlockedPoolIds[targetIndex]);
    }

    private void SelectNextPool()
    {
        if (unlockedPoolIds == null || unlockedPoolIds.Count < 2)
            return;

        int targetIndex = (IndexOfSelectedPool() + 1) % unlockedPoolIds.Count;
        if (targetIndex >= 0)
            dessertSpawner.TrySelectSpawnPool(unlockedPoolIds[targetIndex]);
    }

    private void UpdatePosition()
    {
        if (panel == null || canvasRect == null)
            return;

        Camera gameCamera = Camera.main;
        if (gameCamera == null)
            return;

        if (!TryGetPreviewCanvasBounds(gameCamera, out Rect previewBounds) ||
            !TryGetCanvasLocalRect(Screen.safeArea, out Rect usableBounds))
            return;

        CaptureScreenLayout(gameCamera);

        Vector2 panelSize = panel.rect.size;
        if (hasEvaluatedLayout &&
            Approximately(previewBounds, lastPreviewBounds) &&
            Approximately(usableBounds, lastUsableBounds) &&
            Approximately(panelSize, lastPanelSize))
            return;

        lastPreviewBounds = previewBounds;
        lastUsableBounds = usableBounds;
        lastPanelSize = panelSize;
        hasEvaluatedLayout = true;

        if (!TryCalculateSelectorBounds(
                previewBounds,
                usableBounds,
                panelSize,
                PreviewGap,
                out Rect selectorBounds))
        {
            panel.gameObject.SetActive(false);
            if (!hasLoggedPlacementFailure)
            {
                Debug.LogError(
                    "SPAWN POOL UI | Selector cannot fit below the preview inside the safe area.",
                    this);
                hasLoggedPlacementFailure = true;
            }
            return;
        }

        panel.anchoredPosition = selectorBounds.center;
        panel.gameObject.SetActive(true);
        hasLoggedPlacementFailure = false;
    }

    public static bool TryCalculateSelectorBounds(
        Rect previewBounds,
        Rect usableBounds,
        Vector2 panelSize,
        float gap,
        out Rect selectorBounds)
    {
        selectorBounds = default;
        if (panelSize.x <= 0f ||
            panelSize.y <= 0f ||
            gap < 0f ||
            usableBounds.width < panelSize.x)
            return false;

        float halfWidth = panelSize.x * 0.5f;
        float bottom = previewBounds.yMin - gap - panelSize.y;
        if (bottom < usableBounds.yMin ||
            previewBounds.yMin - gap > usableBounds.yMax)
            return false;

        float centerX = Mathf.Clamp(
            previewBounds.center.x,
            usableBounds.xMin + halfWidth,
            usableBounds.xMax - halfWidth);
        selectorBounds = new Rect(
            centerX - halfWidth,
            bottom,
            panelSize.x,
            panelSize.y);
        return true;
    }

    private bool HasScreenLayoutChanged()
    {
        if (!hasObservedScreenLayout ||
            canvasRect == null)
            return true;

        Camera gameCamera = Camera.main;
        return Screen.width != lastObservedScreenWidth ||
               Screen.height != lastObservedScreenHeight ||
               Screen.safeArea != lastObservedSafeArea ||
               canvasRect.rect != lastObservedCanvasRect ||
               gameCamera != lastObservedCamera ||
               (gameCamera != null &&
                (gameCamera.pixelRect != lastObservedCameraPixelRect ||
                 gameCamera.transform.position != lastObservedCameraPosition ||
                 gameCamera.transform.rotation != lastObservedCameraRotation ||
                 !Mathf.Approximately(
                     gameCamera.aspect,
                     lastObservedCameraAspect) ||
                 !Mathf.Approximately(
                     gameCamera.orthographicSize,
                     lastObservedOrthographicSize)));
    }

    private void CaptureScreenLayout(Camera gameCamera)
    {
        lastObservedScreenWidth = Screen.width;
        lastObservedScreenHeight = Screen.height;
        lastObservedSafeArea = Screen.safeArea;
        lastObservedCanvasRect = canvasRect.rect;
        lastObservedCamera = gameCamera;
        lastObservedCameraPixelRect = gameCamera.pixelRect;
        lastObservedCameraPosition = gameCamera.transform.position;
        lastObservedCameraRotation = gameCamera.transform.rotation;
        lastObservedOrthographicSize = gameCamera.orthographicSize;
        lastObservedCameraAspect = gameCamera.aspect;
        hasObservedScreenLayout = true;
    }

    private bool TryGetPreviewCanvasBounds(
        Camera gameCamera,
        out Rect localBounds)
    {
        Transform anchor = previewAnchor != null ? previewAnchor : transform;
        Bounds worldBounds = previewRenderer != null
            ? previewRenderer.bounds
            : new Bounds(anchor.position, Vector3.zero);

        Vector3 min = worldBounds.min;
        Vector3 max = worldBounds.max;
        Vector2 firstPoint = default;
        float minX = float.PositiveInfinity;
        float minY = float.PositiveInfinity;
        float maxX = float.NegativeInfinity;
        float maxY = float.NegativeInfinity;

        for (int x = 0; x < 2; x++)
        {
            for (int y = 0; y < 2; y++)
            {
                for (int z = 0; z < 2; z++)
                {
                    Vector3 worldPoint = new Vector3(
                        x == 0 ? min.x : max.x,
                        y == 0 ? min.y : max.y,
                        z == 0 ? min.z : max.z);
                    Vector2 screenPoint = gameCamera.WorldToScreenPoint(worldPoint);
                    if (!RectTransformUtility.ScreenPointToLocalPointInRectangle(
                            canvasRect,
                            screenPoint,
                            null,
                            out Vector2 localPoint))
                    {
                        localBounds = default;
                        return false;
                    }

                    if (float.IsPositiveInfinity(minX))
                        firstPoint = localPoint;
                    minX = Mathf.Min(minX, localPoint.x);
                    minY = Mathf.Min(minY, localPoint.y);
                    maxX = Mathf.Max(maxX, localPoint.x);
                    maxY = Mathf.Max(maxY, localPoint.y);
                }
            }
        }

        if (worldBounds.size == Vector3.zero)
        {
            minX = maxX = firstPoint.x;
            minY = maxY = firstPoint.y;
        }

        localBounds = Rect.MinMaxRect(minX, minY, maxX, maxY);
        return true;
    }

    private bool TryGetCanvasLocalRect(
        Rect screenRect,
        out Rect localRect)
    {
        Vector2 screenMin = new Vector2(screenRect.xMin, screenRect.yMin);
        Vector2 screenMax = new Vector2(screenRect.xMax, screenRect.yMax);
        if (!RectTransformUtility.ScreenPointToLocalPointInRectangle(
                canvasRect, screenMin, null, out Vector2 localMin) ||
            !RectTransformUtility.ScreenPointToLocalPointInRectangle(
                canvasRect, screenMax, null, out Vector2 localMax))
        {
            localRect = default;
            return false;
        }

        localRect = Rect.MinMaxRect(
            Mathf.Min(localMin.x, localMax.x),
            Mathf.Min(localMin.y, localMax.y),
            Mathf.Max(localMin.x, localMax.x),
            Mathf.Max(localMin.y, localMax.y));
        return true;
    }

    private static bool Approximately(Rect first, Rect second)
    {
        return Approximately(first.position, second.position) &&
               Approximately(first.size, second.size);
    }

    private static bool Approximately(Vector2 first, Vector2 second)
    {
        return Mathf.Abs(first.x - second.x) <= LayoutTolerance &&
               Mathf.Abs(first.y - second.y) <= LayoutTolerance;
    }
}
