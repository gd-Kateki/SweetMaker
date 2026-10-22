using UnityEngine;

[RequireComponent(typeof(RectTransform))]
public sealed class SafeAreaFitter : MonoBehaviour
{
    private RectTransform rectTransform;
    private Canvas rootCanvas;
    private Vector2 originalAnchorMin;
    private Vector2 originalAnchorMax;
    private Rect lastSafeArea;
    private Rect lastCanvasRect;
    private bool hasOriginalAnchors;
    private bool hasAppliedLayout;

    private void Awake()
    {
        rectTransform = GetComponent<RectTransform>();
        Canvas canvas = GetComponentInParent<Canvas>();
        rootCanvas = canvas != null ? canvas.rootCanvas : null;

        if (rootCanvas == null)
        {
            Debug.LogError(
                "SAFE AREA | A parent Canvas is required.",
                this);
            enabled = false;
            return;
        }

        if (rootCanvas.renderMode != RenderMode.ScreenSpaceOverlay)
        {
            Debug.LogError(
                "SAFE AREA | SafeAreaFitter only supports Screen Space Overlay canvases.",
                this);
            enabled = false;
            return;
        }

        originalAnchorMin = rectTransform.anchorMin;
        originalAnchorMax = rectTransform.anchorMax;
        hasOriginalAnchors = true;
    }

    private void OnEnable()
    {
        RefreshSafeArea();
    }

    private void Update()
    {
        RefreshSafeArea();
    }

    private void OnApplicationFocus(bool hasFocus)
    {
        if (hasFocus)
            RefreshSafeArea();
    }

    private void OnRectTransformDimensionsChange()
    {
        RefreshSafeArea();
    }

    private void RefreshSafeArea()
    {
        if (!enabled ||
            !hasOriginalAnchors ||
            rectTransform == null ||
            rootCanvas == null)
            return;

        Rect safeArea = Screen.safeArea;
        Rect canvasRect = rootCanvas.pixelRect;
        if (hasAppliedLayout &&
            safeArea == lastSafeArea &&
            canvasRect == lastCanvasRect)
            return;

        Vector4 anchors = CalculateSafeAreaAnchors(
            originalAnchorMin,
            originalAnchorMax,
            safeArea,
            canvasRect);
        lastSafeArea = safeArea;
        lastCanvasRect = canvasRect;
        hasAppliedLayout = true;
        rectTransform.anchorMin = new Vector2(anchors.x, anchors.y);
        rectTransform.anchorMax = new Vector2(anchors.z, anchors.w);
    }

    public static Vector4 CalculateSafeAreaAnchors(
        Vector2 baseAnchorMin,
        Vector2 baseAnchorMax,
        Rect safeArea,
        Rect canvasPixelRect)
    {
        if (canvasPixelRect.width <= 0f ||
            canvasPixelRect.height <= 0f)
            return new Vector4(
                baseAnchorMin.x,
                baseAnchorMin.y,
                baseAnchorMax.x,
                baseAnchorMax.y);

        Rect clippedSafeArea = Rect.MinMaxRect(
            Mathf.Max(safeArea.xMin, canvasPixelRect.xMin),
            Mathf.Max(safeArea.yMin, canvasPixelRect.yMin),
            Mathf.Min(safeArea.xMax, canvasPixelRect.xMax),
            Mathf.Min(safeArea.yMax, canvasPixelRect.yMax));
        if (clippedSafeArea.width <= 0f ||
            clippedSafeArea.height <= 0f)
            return new Vector4(
                baseAnchorMin.x,
                baseAnchorMin.y,
                baseAnchorMax.x,
                baseAnchorMax.y);

        Vector2 safeMin = new Vector2(
            (clippedSafeArea.xMin - canvasPixelRect.xMin) /
            canvasPixelRect.width,
            (clippedSafeArea.yMin - canvasPixelRect.yMin) /
            canvasPixelRect.height);
        Vector2 safeMax = new Vector2(
            (clippedSafeArea.xMax - canvasPixelRect.xMin) /
            canvasPixelRect.width,
            (clippedSafeArea.yMax - canvasPixelRect.yMin) /
            canvasPixelRect.height);
        Vector2 safeSize = safeMax - safeMin;
        Vector2 anchorMin = safeMin + Vector2.Scale(baseAnchorMin, safeSize);
        Vector2 anchorMax = safeMin + Vector2.Scale(baseAnchorMax, safeSize);
        return new Vector4(
            anchorMin.x,
            anchorMin.y,
            anchorMax.x,
            anchorMax.y);
    }
}
