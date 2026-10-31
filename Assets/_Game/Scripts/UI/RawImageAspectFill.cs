using UnityEngine;
using UnityEngine.UI;

[RequireComponent(typeof(RawImage))]
public sealed class RawImageAspectFill : MonoBehaviour
{
    private RawImage rawImage;
    private RectTransform rectTransform;

    private void Awake()
    {
        rawImage = GetComponent<RawImage>();
        rectTransform = GetComponent<RectTransform>();
    }

    private void OnEnable()
    {
        RefreshAspectFill();
    }

    private void OnRectTransformDimensionsChange()
    {
        RefreshAspectFill();
    }

    private void RefreshAspectFill()
    {
        if (rawImage == null || rectTransform == null)
            return;

        Texture texture = rawImage.texture;
        if (texture == null)
        {
            Debug.LogError(
                "BACKGROUND | RawImageAspectFill requires a texture.",
                this);
            enabled = false;
            return;
        }

        Rect bounds = rectTransform.rect;
        if (bounds.width <= 0f || bounds.height <= 0f)
            return;

        float textureAspect = (float)texture.width / texture.height;
        float boundsAspect = bounds.width / bounds.height;
        Rect uvRect = new Rect(0f, 0f, 1f, 1f);

        if (boundsAspect > textureAspect)
        {
            uvRect.height = textureAspect / boundsAspect;
            uvRect.y = (1f - uvRect.height) * 0.5f;
        }
        else if (boundsAspect < textureAspect)
        {
            uvRect.width = boundsAspect / textureAspect;
            uvRect.x = (1f - uvRect.width) * 0.5f;
        }

        rawImage.uvRect = uvRect;
    }
}
