using TMPro;
using UnityEngine;
using UnityEngine.UI;

public sealed class SettingsScreenPresentation : MonoBehaviour
{
    [SerializeField] private Image overlayImage;
    [SerializeField] private Image panelImage;
    [SerializeField] private RectTransform panelRectTransform;
    [SerializeField] private TMP_Text titleText;
    [SerializeField] private Image closeButtonImage;
    [SerializeField] private RectTransform contentRectTransform;
    [SerializeField] private Slider sfxVolumeSlider;
    [SerializeField] private Sprite panelSprite;
    [SerializeField] private Sprite titlePlaqueSprite;
    [SerializeField] private Sprite closeButtonSprite;
    [SerializeField] private Sprite cardOneSprite;
    [SerializeField] private Sprite cardTwoSprite;
    [SerializeField] private Sprite cardThreeSprite;
    [SerializeField] private Sprite cardFourSprite;
    [SerializeField] private Sprite toggleTrackSprite;
    [SerializeField] private Sprite toggleKnobSprite;
    [SerializeField] private Sprite sliderTrackSprite;
    [SerializeField] private Sprite sliderHandleSprite;

    private const float CardGap = 24f;
    private static readonly Color OverlayColor =
        new Color(0.25f, 0.07f, 0.32f, 0.82f);
    private static readonly Color TextColor =
        new Color(0.24f, 0.13f, 0.09f, 1f);
    private static readonly Vector2 CardAnchorMin =
        new Vector2(0.04f, 1f);
    private static readonly Vector2 CardAnchorMax =
        new Vector2(0.96f, 1f);

    private Image[] cardImages;
    private float lastContentHeight = -1f;

    private void OnEnable()
    {
        if (overlayImage == null ||
            panelImage == null ||
            panelRectTransform == null ||
            titleText == null ||
            closeButtonImage == null ||
            contentRectTransform == null ||
            sfxVolumeSlider == null ||
            panelSprite == null ||
            titlePlaqueSprite == null ||
            closeButtonSprite == null ||
            cardOneSprite == null ||
            cardTwoSprite == null ||
            cardThreeSprite == null ||
            cardFourSprite == null ||
            toggleTrackSprite == null ||
            toggleKnobSprite == null ||
            sliderTrackSprite == null ||
            sliderHandleSprite == null)
        {
            Debug.LogError(
                "SettingsScreenPresentation is missing required UI references or artwork.",
                this);
            return;
        }

        ApplyPopupArtwork();
        EnsureTitlePlaque();
        EnsureCardImages();
        ApplyControlArtwork();
        ApplyTextColor();
        UpdateCardLayout();
        EditableUIView.Attach(gameObject, "SettingsArtwork");
    }

    private void LateUpdate()
    {
        if (contentRectTransform != null &&
            !Mathf.Approximately(
                lastContentHeight,
                contentRectTransform.rect.height))
        {
            UpdateCardLayout();
        }
    }

    private void ApplyPopupArtwork()
    {
        if (overlayImage != null)
            overlayImage.color = OverlayColor;

        if (panelImage != null)
        {
            panelImage.sprite = panelSprite;
            panelImage.color = Color.white;
            panelImage.preserveAspect = false;
        }

        if (titleText != null)
        {
            RectTransform titleRect = titleText.rectTransform;
            titleRect.anchorMin = new Vector2(0.27f, 0.91f);
            titleRect.anchorMax = new Vector2(0.73f, 1.03f);
            titleRect.anchoredPosition = Vector2.zero;
            titleRect.sizeDelta = Vector2.zero;
            titleText.color = TextColor;
            titleText.fontSize = 56f;
            titleText.fontStyle = FontStyles.Bold;
            titleText.alignment = TextAlignmentOptions.Center;
            titleText.raycastTarget = false;
        }

        if (closeButtonImage != null)
        {
            closeButtonImage.sprite = closeButtonSprite;
            closeButtonImage.color = Color.white;
            closeButtonImage.preserveAspect = false;

            RectTransform closeRect = closeButtonImage.rectTransform;
            closeRect.anchorMin = new Vector2(0.95f, 1f);
            closeRect.anchorMax = new Vector2(0.95f, 1f);
            closeRect.anchoredPosition = Vector2.zero;
            closeRect.sizeDelta = new Vector2(184f, 184f);
            closeRect.pivot = new Vector2(0.5f, 0.5f);
        }
    }

    private void EnsureTitlePlaque()
    {
        if (panelRectTransform == null || titleText == null)
            return;

        const string plaqueName = "SettingsTitlePlaque";
        Transform existing = panelRectTransform.Find(plaqueName);
        Image plaqueImage;
        RectTransform plaqueRect;
        if (existing != null)
        {
            plaqueRect = existing as RectTransform;
            plaqueImage = existing.GetComponent<Image>();
        }
        else
        {
            var plaqueObject = new GameObject(
                plaqueName,
                typeof(RectTransform),
                typeof(CanvasRenderer),
                typeof(Image));
            plaqueObject.transform.SetParent(panelRectTransform, false);
            plaqueRect = plaqueObject.GetComponent<RectTransform>();
            plaqueImage = plaqueObject.GetComponent<Image>();
        }

        plaqueRect.anchorMin = new Vector2(0.25f, 0.9f);
        plaqueRect.anchorMax = new Vector2(0.75f, 1.02f);
        plaqueRect.anchoredPosition = Vector2.zero;
        plaqueRect.sizeDelta = Vector2.zero;
        plaqueImage.sprite = titlePlaqueSprite;
        plaqueImage.color = Color.white;
        plaqueImage.raycastTarget = false;
        int titleIndex = titleText.transform.GetSiblingIndex();
        if (plaqueRect.GetSiblingIndex() > titleIndex)
            plaqueRect.SetSiblingIndex(titleIndex);
    }

    private void EnsureCardImages()
    {
        if (contentRectTransform == null)
            return;

        Sprite[] sprites =
        {
            cardOneSprite,
            cardTwoSprite,
            cardThreeSprite,
            cardFourSprite
        };
        cardImages = new Image[sprites.Length];

        for (int i = 0; i < sprites.Length; i++)
        {
            string cardName = "SettingsCard" + (i + 1);
            Transform existing = contentRectTransform.Find(cardName);
            Image cardImage;
            RectTransform cardRect;
            if (existing != null)
            {
                cardRect = existing as RectTransform;
                cardImage = existing.GetComponent<Image>();
            }
            else
            {
                var cardObject = new GameObject(
                    cardName,
                    typeof(RectTransform),
                    typeof(CanvasRenderer),
                    typeof(Image));
                cardObject.transform.SetParent(
                    contentRectTransform,
                    false);
                cardRect = cardObject.GetComponent<RectTransform>();
                cardImage = cardObject.GetComponent<Image>();
            }

            cardImage.sprite = sprites[i];
            cardImage.color = Color.white;
            cardImage.raycastTarget = false;
            cardImage.maskable = true;
            cardRect.SetSiblingIndex(i);
            cardImages[i] = cardImage;
        }
    }

    private void ApplyControlArtwork()
    {
        if (contentRectTransform != null)
        {
            SettingsToggleVisual[] toggleVisuals =
                contentRectTransform.GetComponentsInChildren<
                    SettingsToggleVisual>(true);
            foreach (SettingsToggleVisual visual in toggleVisuals)
            {
                visual.ApplyAppearance(
                    toggleTrackSprite,
                    toggleKnobSprite,
                    TextColor);
            }
        }

        if (sfxVolumeSlider == null)
            return;

        Image background = sfxVolumeSlider.GetComponent<Image>();
        if (background != null)
            ApplySprite(background, sliderTrackSprite);

        if (sfxVolumeSlider.fillRect != null)
        {
            Image fill = sfxVolumeSlider.fillRect.GetComponent<Image>();
            if (fill != null)
                ApplySprite(fill, sliderTrackSprite);
        }

        if (sfxVolumeSlider.handleRect != null)
        {
            Image handle =
                sfxVolumeSlider.handleRect.GetComponent<Image>();
            if (handle != null)
                ApplySprite(handle, sliderHandleSprite);
        }
    }

    private static void ApplySprite(Image image, Sprite sprite)
    {
        image.sprite = sprite;
        image.color = Color.white;
    }

    private void ApplyTextColor()
    {
        if (contentRectTransform == null)
            return;

        TMP_Text[] texts =
            contentRectTransform.GetComponentsInChildren<TMP_Text>(true);
        foreach (TMP_Text text in texts)
        {
            if (text.GetComponentInParent<Button>() == null)
                text.color = TextColor;
        }
    }

    private void UpdateCardLayout()
    {
        if (contentRectTransform == null ||
            cardImages == null ||
            cardImages.Length == 0)
            return;

        float contentHeight = contentRectTransform.rect.height;
        if (contentHeight <= 0f)
            return;

        float cardHeight =
            (contentHeight - CardGap * (cardImages.Length + 1)) /
            cardImages.Length;
        if (cardHeight <= 0f)
            return;

        for (int i = 0; i < cardImages.Length; i++)
        {
            RectTransform cardRect = cardImages[i].rectTransform;
            cardRect.anchorMin = CardAnchorMin;
            cardRect.anchorMax = CardAnchorMax;
            cardRect.pivot = new Vector2(0.5f, 1f);
            cardRect.anchoredPosition = new Vector2(
                0f,
                -CardGap - i * (cardHeight + CardGap));
            cardRect.sizeDelta = new Vector2(0f, cardHeight);
        }

        lastContentHeight = contentHeight;
    }
}
