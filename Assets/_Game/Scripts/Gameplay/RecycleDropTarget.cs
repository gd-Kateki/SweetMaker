using UnityEngine;
using UnityEngine.UI;

public class RecycleDropTarget : MonoBehaviour
{
    [SerializeField]
    private RectTransform hitArea;

    [SerializeField]
    private RectTransform excludedArea;

    [SerializeField]
    private Image targetImage;

    [SerializeField]
    private Color idleColor = new Color(0.55f, 0.2f, 0.25f, 0.95f);

    [SerializeField]
    private Color highlightedColor = new Color(1f, 0.35f, 0.35f, 1f);

    private Canvas parentCanvas;

    private void Awake()
    {
        if (hitArea == null)
            hitArea = transform as RectTransform;
        if (targetImage == null)
            targetImage = GetComponent<Image>();
        parentCanvas = GetComponentInParent<Canvas>();
        SetHighlighted(false);
    }

    public bool ContainsScreenPoint(Vector2 screenPoint)
    {
        if (hitArea == null)
            return false;

        Camera eventCamera = parentCanvas != null &&
                             parentCanvas.renderMode != RenderMode.ScreenSpaceOverlay
            ? parentCanvas.worldCamera
            : null;
        if (excludedArea != null &&
            RectTransformUtility.RectangleContainsScreenPoint(
                excludedArea,
                screenPoint,
                eventCamera))
            return false;

        return RectTransformUtility.RectangleContainsScreenPoint(
            hitArea,
            screenPoint,
            eventCamera);
    }

    public void SetHighlighted(bool highlighted)
    {
        if (targetImage != null)
            targetImage.color = highlighted ? highlightedColor : idleColor;
    }
}
