using System.Collections;
using System.Text;
using UnityEngine;
using UnityEngine.UI;

public sealed class UpgradeViewportRuntimeDiagnostic : MonoBehaviour
{
#if UNITY_EDITOR || DEVELOPMENT_BUILD
    private Coroutine pendingReport;

    private void OnEnable()
    {
        pendingReport = StartCoroutine(ReportAfterLayoutSettles());
    }

    private void OnDisable()
    {
        if (pendingReport == null)
            return;

        StopCoroutine(pendingReport);
        pendingReport = null;
    }

    private IEnumerator ReportAfterLayoutSettles()
    {
        yield return null;
        Canvas.ForceUpdateCanvases();
        yield return new WaitForEndOfFrame();
        Canvas.ForceUpdateCanvases();
        pendingReport = null;
        ReportRuntimeGeometry();
    }

    [ContextMenu("Log Runtime Geometry Now")]
    private void LogRuntimeGeometryNow()
    {
        ReportRuntimeGeometry();
    }

    private void ReportRuntimeGeometry()
    {
        ScrollRect scrollRect = GetComponent<ScrollRect>();
        RectTransform scrollView = transform as RectTransform;
        RectTransform header = transform.Find("Header") as RectTransform;
        RectTransform viewport = scrollRect != null
            ? scrollRect.viewport
            : null;
        RectTransform content = scrollRect != null
            ? scrollRect.content
            : null;
        RectTransform firstCard = content != null && content.childCount > 0
            ? content.GetChild(0) as RectTransform
            : null;
        RectTransform lastCard = content != null && content.childCount > 0
            ? content.GetChild(content.childCount - 1) as RectTransform
            : null;

        StringBuilder report = new StringBuilder(2048);
        Canvas canvas = GetComponentInParent<Canvas>();
        Canvas rootCanvas = canvas != null ? canvas.rootCanvas : null;
        CanvasScaler scaler = rootCanvas != null
            ? rootCanvas.GetComponent<CanvasScaler>()
            : null;

        report.AppendLine("UPGRADE VIEWPORT DIAGNOSTIC");
        report.AppendLine(
            $"Screen: {Screen.width}x{Screen.height}px");
        if (scaler != null)
        {
            report.AppendLine(
                $"CanvasScaler: mode={scaler.uiScaleMode}, " +
                $"referenceResolution={scaler.referenceResolution}, " +
                $"screenMatchMode={scaler.screenMatchMode}, " +
                $"matchWidthOrHeight={scaler.matchWidthOrHeight:F3}, " +
                $"scaleFactor={rootCanvas.scaleFactor:F4}, " +
                $"canvasPixelRect={rootCanvas.pixelRect}");
        }
        else
        {
            report.AppendLine(
                "CanvasScaler: missing on root Canvas.");
        }

        AppendRect(report, "UpgradeScrollView", scrollView);
        AppendRect(report, "Header", header);
        AppendRect(report, "Viewport", viewport);
        AppendRect(report, "UpgradeContent", content);
        AppendRect(report, "First upgrade card", firstCard);
        if (content != null && content.childCount > 1)
            AppendRect(report, "Last upgrade card", lastCard);

        if (viewport != null && firstCard != null)
        {
            Bounds viewportBounds = GetScreenBounds(viewport);
            Bounds cardBounds = GetScreenBounds(firstCard);
            float leftInset = cardBounds.min.x - viewportBounds.min.x;
            float rightInset = viewportBounds.max.x - cardBounds.max.x;
            bool extendsBeyondViewport =
                cardBounds.min.x < viewportBounds.min.x ||
                cardBounds.max.x > viewportBounds.max.x ||
                cardBounds.min.y < viewportBounds.min.y ||
                cardBounds.max.y > viewportBounds.max.y;
            report.AppendLine(
                $"First card vs Viewport (screen px): " +
                $"leftInset={leftInset:F2}, rightInset={rightInset:F2}, " +
                $"extendsBeyondViewport={extendsBeyondViewport}.");
        }
        else
        {
            report.AppendLine(
                "First card vs Viewport: unavailable (missing reference or card).");
        }

        if (header != null && viewport != null)
        {
            Bounds headerScreenBounds = GetScreenBounds(header);
            Bounds viewportScreenBounds = GetScreenBounds(viewport);
            float gap = viewportScreenBounds.max.y - headerScreenBounds.min.y;
            report.AppendLine(
                $"Viewport.top={viewportScreenBounds.max.y:F2}px, " +
                $"Header.bottom={headerScreenBounds.min.y:F2}px, " +
                $"top-minus-bottom={gap:F2}px; " +
                $"viewport is below header: {gap < 0f}.");
        }

        AppendScrollRect(report, scrollRect, viewport, content);
        AppendMask(report, viewport);
        Debug.Log(report.ToString(), this);
    }

    private static void AppendRect(
        StringBuilder report,
        string label,
        RectTransform rect)
    {
        if (rect == null)
        {
            report.AppendLine($"{label}: missing.");
            return;
        }

        Vector3[] worldCorners = new Vector3[4];
        rect.GetWorldCorners(worldCorners);
        Bounds screenBounds = GetScreenBounds(rect);
        UnityEngine.Object driver = rect.drivenByObject;
        report.AppendLine(
            $"{label}: path={GetHierarchyPath(rect)}, rect={rect.rect}, " +
            $"anchors=({rect.anchorMin}..{rect.anchorMax}), " +
            $"offsetMin={rect.offsetMin}, offsetMax={rect.offsetMax}, " +
            $"anchoredPosition={rect.anchoredPosition}, sizeDelta={rect.sizeDelta}, " +
            $"drivenBy={(driver != null ? driver.name : "none")}; " +
            $"worldCorners[BL,TL,TR,BR]=" +
            $"[{worldCorners[0]}, {worldCorners[1]}, " +
            $"{worldCorners[2]}, {worldCorners[3]}]; " +
            $"screenBounds={screenBounds}.");
    }

    private static void AppendScrollRect(
        StringBuilder report,
        ScrollRect scrollRect,
        RectTransform viewport,
        RectTransform content)
    {
        if (scrollRect == null)
        {
            report.AppendLine("ScrollRect: missing.");
            return;
        }

        Canvas[] nestedCanvases =
            scrollRect.GetComponentsInChildren<Canvas>(true);
        report.AppendLine(
            $"ScrollRect: enabled={scrollRect.enabled}, viewportMatches=" +
            $"{scrollRect.viewport == viewport}, contentMatches=" +
            $"{scrollRect.content == content}, contentParentMatches=" +
            $"{content != null && content.parent == viewport}, " +
            $"vertical={scrollRect.vertical}, nestedCanvases={nestedCanvases.Length}.");

        foreach (Canvas nestedCanvas in nestedCanvases)
        {
            report.AppendLine(
                $"Nested Canvas: path={GetHierarchyPath(nestedCanvas.transform)}, " +
                $"overrideSorting={nestedCanvas.overrideSorting}, " +
                $"sortingOrder={nestedCanvas.sortingOrder}, " +
                $"renderMode={nestedCanvas.renderMode}.");
        }
    }

    private static void AppendMask(
        StringBuilder report,
        RectTransform viewport)
    {
        if (viewport == null)
        {
            report.AppendLine("Mask: unavailable (Viewport missing).");
            return;
        }

        Mask mask = viewport.GetComponent<Mask>();
        Image image = viewport.GetComponent<Image>();
        RectMask2D[] rectMasks =
            viewport.GetComponentsInParent<RectMask2D>(true);
        bool maskUsesViewportGraphic =
            mask != null &&
            image != null &&
            mask.graphic == image &&
            image.rectTransform == viewport;

        report.AppendLine(
            $"Mask: enabled={(mask != null && mask.enabled)}, " +
            $"imageEnabled={(image != null && image.enabled)}, " +
            $"showMaskGraphic={(mask != null && mask.showMaskGraphic)}, " +
            $"maskGraphicMatchesViewportImage={maskUsesViewportGraphic}, " +
            $"imageType={(image != null ? image.type.ToString() : "missing")}, " +
            $"parentRectMask2DCount={rectMasks.Length}.");
    }

    private static Bounds GetScreenBounds(RectTransform rect)
    {
        Vector3[] worldCorners = new Vector3[4];
        rect.GetWorldCorners(worldCorners);
        Bounds bounds = new Bounds(
            RectTransformUtility.WorldToScreenPoint(null, worldCorners[0]),
            Vector3.zero);

        for (int i = 1; i < worldCorners.Length; i++)
        {
            bounds.Encapsulate(
                RectTransformUtility.WorldToScreenPoint(null, worldCorners[i]));
        }

        return bounds;
    }

    private static string GetHierarchyPath(Transform target)
    {
        string path = target.name;
        while (target.parent != null)
        {
            target = target.parent;
            path = target.name + "/" + path;
        }

        return path;
    }
#endif
}
