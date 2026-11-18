using TMPro;
using UnityEngine;
using UnityEngine.UI;

// Positions rows in canvas units, independently of the total scroll height.
// Existing controls and their listeners remain owned by SettingsUI.
public sealed class SettingsScreenPresentation : MonoBehaviour
{
    [SerializeField] private Image overlayImage;
    [SerializeField] private Image panelImage;
    [SerializeField] private RectTransform panelRectTransform;
    [SerializeField] private TMP_Text titleText;
    [SerializeField] private Image closeButtonImage;
    [SerializeField] private RectTransform contentRectTransform;
    [SerializeField] private Slider sfxVolumeSlider;
    [Header("Editable appearance — use a sprite with nine-slice borders")]
    [SerializeField] private Sprite panelSprite;
    [SerializeField] private Sprite toggleTrackSprite;
    [SerializeField] private Sprite toggleKnobSprite;
    [SerializeField] private Sprite titlePlateSprite;
    [SerializeField] private bool closeArtworkContainsIcon;
    [SerializeField] private Color panelColor = new Color(0.97f, 0.94f, 0.99f);
    [SerializeField] private Color cardColor = Color.white;
    [SerializeField] private Color accentColor = new Color(0.43f, 0.22f, 0.62f);
    [SerializeField] private Color textColor = new Color(0.21f, 0.16f, 0.28f);
    [SerializeField, Min(600)] private float maximumPanelWidth = 1000;
    private int lastChildCount = -1;
    private int lastServiceSections;
    private Vector2 lastParentSize;
    private bool initialized;

    private void OnEnable()
    {
        if (overlayImage == null || panelImage == null || panelRectTransform == null ||
            titleText == null || closeButtonImage == null || contentRectTransform == null || sfxVolumeSlider == null)
        {
            Debug.LogError("Settings presentation is missing a wired UI reference.", this);
            return;
        }
        initialized = true;
        ApplyLayout();
        EditableUIView.Attach(gameObject, "SettingsArtwork");
        GetComponent<EditableUIView>().IncludeNestedViews();
    }

    private void LateUpdate()
    {
        if (!initialized) return;
        // Account/privacy controls can be attached after the overlay is created.
        if (lastChildCount != contentRectTransform.childCount)
        {
            // Artist-added decorations must not cause a reset after their template applies.
            if (ServiceSections() != lastServiceSections) ApplyLayout();
            lastChildCount = contentRectTransform.childCount;
        }
        var parent = panelRectTransform.parent as RectTransform;
        if (parent != null && parent.rect.size != lastParentSize) ResizePanel();
    }

    private void ResizePanel()
    {
        var parent = panelRectTransform.parent as RectTransform;
        if (parent == null) return;
        lastParentSize = parent.rect.size;
        // Inactive scene views have no canvas geometry during editor previews.
        if (lastParentSize.x <= 1 || lastParentSize.y <= 1)
        {
            var scaler = panelRectTransform.GetComponentInParent<CanvasScaler>(true);
            lastParentSize = scaler != null ? scaler.referenceResolution : new Vector2(1080, 1920);
        }
        panelRectTransform.anchorMin = panelRectTransform.anchorMax = new Vector2(.5f, .5f);
        panelRectTransform.pivot = new Vector2(.5f, .5f);
        panelRectTransform.anchoredPosition = Vector2.zero;
        panelRectTransform.sizeDelta = new Vector2(Mathf.Min(maximumPanelWidth, Mathf.Max(1, lastParentSize.x - 48)), Mathf.Max(1, lastParentSize.y - 64));
    }

    private void ApplyLayout()
    {
        var persistence = panelRectTransform.Find("SettingsPersistenceFeedback");
        if (persistence != null) persistence.SetParent(contentRectTransform, false);
        ResizePanel();
        overlayImage.color = new Color(.10f, .06f, .16f, .82f);
        Surface(panelImage, panelColor);
        Place(titleText.rectTransform, 24, 72, 32, 120);
        titleText.text = "Settings";
        StyleText(titleText, 48, true);
        titleText.alignment = TextAlignmentOptions.MidlineLeft;
        var plaque = panelRectTransform.Find("SettingsTitlePlaque");
        if (plaque != null) plaque.gameObject.SetActive(false);
        if (titlePlateSprite != null)
        {
            var titlePlate = panelRectTransform.Find("V3SettingsTitlePlate");
            if (titlePlate == null)
            {
                titlePlate = new GameObject("V3SettingsTitlePlate", typeof(RectTransform), typeof(Image)).transform;
                titlePlate.SetParent(panelRectTransform, false);
            }
            titlePlate.SetAsFirstSibling();
            var plateRect = (RectTransform)titlePlate;
            plateRect.anchorMin = plateRect.anchorMax = new Vector2(.5f,1); plateRect.pivot = new Vector2(.5f,1);
            plateRect.anchoredPosition = new Vector2(0,-12); plateRect.sizeDelta = new Vector2(360,110);
            var image = titlePlate.GetComponent<Image>(); image.sprite = titlePlateSprite;
            image.type = Image.Type.Sliced; image.color = Color.white; image.raycastTarget = false;
            var heading = titleText.rectTransform;
            heading.anchorMin = heading.anchorMax = new Vector2(.5f,1); heading.pivot = new Vector2(.5f,1);
            heading.anchoredPosition = new Vector2(0,-24); heading.sizeDelta = new Vector2(320,72);
            titleText.alignment = TextAlignmentOptions.Center;
        }
        var close = closeButtonImage.rectTransform;
        close.anchorMin = close.anchorMax = new Vector2(1, 1);
        close.pivot = new Vector2(1, 1);
        close.anchoredPosition = new Vector2(-24, -24);
        close.sizeDelta = new Vector2(76, 76);
        Surface(closeButtonImage, accentColor);
        var closeLabel = closeButtonImage.GetComponentInChildren<TMP_Text>(true);
        if (closeLabel != null) { closeLabel.text = closeArtworkContainsIcon ? string.Empty : "×"; StyleText(closeLabel, 48, true); closeLabel.color = Color.white; closeLabel.alignment = TextAlignmentOptions.Center; }

        var viewport = contentRectTransform.parent as RectTransform;
        viewport.anchorMin = Vector2.zero; viewport.anchorMax = Vector2.one;
        viewport.offsetMin = new Vector2(20, 24); viewport.offsetMax = new Vector2(-20, -116);
        var scroll = contentRectTransform.GetComponentInParent<ScrollRect>(true);
        if (scroll != null)
        {
            scroll.horizontal = false; scroll.vertical = true;
            scroll.movementType = ScrollRect.MovementType.Clamped;
            if (scroll.verticalScrollbar != null)
            {
                var bar = scroll.verticalScrollbar.GetComponent<RectTransform>();
                bar.anchorMin = new Vector2(1, 0); bar.anchorMax = Vector2.one;
                bar.offsetMin = new Vector2(-10, 12); bar.offsetMax = new Vector2(-3, -12);
            }
        }
        contentRectTransform.anchorMin = new Vector2(0, 1); contentRectTransform.anchorMax = Vector2.one;
        contentRectTransform.pivot = new Vector2(.5f, 1);

        Card("SettingsCard1", 8, 290);
        Heading("AudioSectionHeading", 28, "SOUND");
        Row("SoundEffectsLabel", "SfxEnabledToggle", 86);
        Label("SfxVolumeLabel", 170, 44, "Volume");
        PlaceChild("SfxVolumePercentage", 170, 44, .75f, 1);
        var percent = FindText("SfxVolumePercentage"); if (percent != null) { StyleText(percent, 28); percent.alignment = TextAlignmentOptions.MidlineRight; }
        Place(sfxVolumeSlider.GetComponent<RectTransform>(), 224, 48, 40, 40);
        var track = sfxVolumeSlider.GetComponent<Image>(); if (track != null) Surface(track, new Color(.84f, .79f, .90f));
        if (sfxVolumeSlider.fillRect != null) Surface(sfxVolumeSlider.fillRect.GetComponent<Image>(), accentColor);
        if (sfxVolumeSlider.handleRect != null)
        {
            var handle = sfxVolumeSlider.handleRect;
            handle.sizeDelta = new Vector2(48, 0); handle.anchoredPosition = Vector2.zero;
            Surface(handle.GetComponent<Image>(), accentColor);
        }

        Card("SettingsCard2", 318, 282);
        Heading("GameplaySectionHeading", 338, "GAMEPLAY");
        Row("VibrationLabel", "VibrationToggle", 396);
        Row("ConfirmImportantActionsLabel", "ConfirmImportantActionsToggle", 494);
        Card("SettingsCard3", 620, 172);
        Heading("AccessibilitySectionHeading", 640, "ACCESSIBILITY");
        Row("ReduceAnimationsLabel", "ReduceAnimationsToggle", 698);
        Card("SettingsCard4", 812, 232);
        Heading("InformationSectionHeading", 832, "ABOUT");
        Label("GameVersionLabel", 886, 44, "Version");
        PlaceChild("GameVersionValue", 886, 44, .5f, 1);
        var version = FindText("GameVersionValue"); if (version != null) { StyleText(version, 28); version.alignment = TextAlignmentOptions.MidlineRight; }
        PlaceChild("SettingsPersistenceFeedback", 944, 76);
        var feedback = FindText("SettingsPersistenceFeedback"); if (feedback != null) StyleText(feedback, 26);

        float next = 1064;
        Section("GooglePlayGamesAccountSettings", ref next);
        Section("Player privacy settings", ref next);
        Section("AnalyticsPrivacySettings", ref next);
        contentRectTransform.sizeDelta = new Vector2(0, next + 12);
        lastChildCount = contentRectTransform.childCount;
        lastServiceSections = ServiceSections();
        // Reapply the artist's design if late-created account/privacy sections required a layout pass.
        if (GetComponent<EditableUIView>() != null) EditableUIView.Attach(gameObject, "SettingsArtwork");
    }

    private int ServiceSections() =>
        (contentRectTransform.Find("GooglePlayGamesAccountSettings") != null ? 1 : 0) |
        (contentRectTransform.Find("Player privacy settings") != null ? 2 : 0) |
        (contentRectTransform.Find("AnalyticsPrivacySettings") != null ? 4 : 0);

    private void Section(string name, ref float next)
    {
        var section = contentRectTransform.Find(name) as RectTransform;
        if (section == null) return;
        LayoutServiceSection(section);
        float height = section.sizeDelta.y;
        Card(name + "Card", next, height + 40);
        Place(section, next + 20, height, 36, 36);
        foreach (var text in section.GetComponentsInChildren<TMP_Text>(true))
        {
            StyleText(text, Mathf.Max(26, text.fontSize), (text.fontStyle & FontStyles.Bold) != 0);
            if (text.GetComponentInParent<Button>(true) != null) text.color = Color.white;
            else text.alignment = TextAlignmentOptions.TopLeft;
        }
        foreach (var button in section.GetComponentsInChildren<Button>(true))
        {
            Surface(button.GetComponent<Image>(), Color.white);
            var colors = button.colors;
            colors.normalColor = accentColor; colors.highlightedColor = accentColor * 1.12f;
            colors.pressedColor = accentColor * .85f;
            colors.disabledColor = new Color(.65f, .62f, .70f); colors.fadeDuration = .1f;
            button.colors = colors; button.transition = Selectable.Transition.ColorTint;
            var label = button.GetComponentInChildren<TMP_Text>(true);
            if (label != null)
            {
                label.rectTransform.anchorMin = Vector2.zero; label.rectTransform.anchorMax = Vector2.one;
                label.rectTransform.offsetMin = new Vector2(16, 4); label.rectTransform.offsetMax = new Vector2(-16, -4);
                label.alignment = TextAlignmentOptions.Center;
                label.enableAutoSizing = true; label.fontSizeMin = 20; label.fontSizeMax = 28;
            }
        }
        next += height + 60;
    }

    private static void LayoutServiceSection(RectTransform section)
    {
        if (section.name == "GooglePlayGamesAccountSettings")
        {
            section.sizeDelta = new Vector2(0, 1080);
            SetChild(section, "GooglePlayGamesLabel", 58, 42);
            SetChild(section, "GooglePlayGamesConnectionStatus", 106, 72);
            SetChild(section, "GooglePlayGamesAccountFeedback", 184, 80);
            SetChild(section, "ConnectWithGooglePlay", 280, 72);
            SetChild(section, "LocalProgressClarification", 368, 64);
            SetChild(section, "Cloud text", 448, 260);
            SetChild(section, "Check / retry backup", 728, 72);
            SetChild(section, "Keep Device Progress", 816, 72);
            SetChild(section, "Restore cloud & reopen game", 904, 72);
            SetChild(section, "Cancel", 992, 72);
        }
        else if (section.name == "AnalyticsPrivacySettings")
        {
            section.sizeDelta = new Vector2(0, 420);
            SetChild(section, "AnalyticsPrivacyHeading", 0, 48);
            SetChild(section, "AnalyticsConsentStatus", 58, 64);
            SetChild(section, "AnalyticsWithdrawalDisclosure", 130, 90);
            SetChild(section, "EnableAnalytics", 238, 76, 0, .49f);
            SetChild(section, "DisableAnalytics", 238, 76, .51f, 1);
            SetChild(section, "AnalyticsPrivacyPolicy", 330, 76);
        }
    }

    private static void SetChild(Transform section, string name, float top, float height, float left = 0, float right = 1)
    {
        RectTransform rect = null;
        // Button labels may contain '/', which Transform.Find treats as a path separator.
        foreach (Transform child in section)
            if (child.name == name) { rect = child as RectTransform; break; }
        if (rect == null) return;
        rect.anchorMin = new Vector2(left, 1); rect.anchorMax = new Vector2(right, 1);
        rect.pivot = new Vector2(.5f, 1);
        rect.offsetMin = new Vector2(0, -top - height); rect.offsetMax = new Vector2(0, -top);
    }

    private void Row(string labelName, string toggleName, float top)
    {
        PlaceChild(labelName, top, 80, 0, .69f);
        var label = FindText(labelName); if (label != null) StyleText(label, 32);
        var toggle = contentRectTransform.Find(toggleName) as RectTransform;
        if (toggle == null) return;
        toggle.anchorMin = toggle.anchorMax = new Vector2(1, 1); toggle.pivot = new Vector2(1, 1);
        toggle.anchoredPosition = new Vector2(-32, -top - 8); toggle.sizeDelta = new Vector2(144, 64);
        var visual = toggle.GetComponent<SettingsToggleVisual>();
        if (visual != null) visual.ApplyCompactAppearance(panelSprite, toggleTrackSprite, toggleKnobSprite);
    }

    private void Heading(string name, float top, string value)
    {
        PlaceChild(name, top, 42); var text = FindText(name);
        if (text != null) { text.text = value; StyleText(text, 27, true); text.color = accentColor; }
    }
    private void Label(string name, float top, float height, string value)
    {
        PlaceChild(name, top, height); var text = FindText(name);
        if (text != null) { text.text = value; StyleText(text, 30); }
    }
    private TMP_Text FindText(string name) => contentRectTransform.Find(name)?.GetComponent<TMP_Text>();
    private void PlaceChild(string name, float top, float height, float left = 0, float right = 1)
    {
        var rect = contentRectTransform.Find(name) as RectTransform;
        if (rect == null) return;
        rect.anchorMin = new Vector2(left, 1); rect.anchorMax = new Vector2(right, 1); rect.pivot = new Vector2(.5f, 1);
        rect.offsetMin = new Vector2(32, -top - height); rect.offsetMax = new Vector2(-32, -top);
    }
    private static void Place(RectTransform rect, float top, float height, float left, float right)
    {
        rect.anchorMin = new Vector2(0, 1); rect.anchorMax = Vector2.one; rect.pivot = new Vector2(.5f, 1);
        rect.offsetMin = new Vector2(left, -top - height); rect.offsetMax = new Vector2(-right, -top);
    }
    private void Card(string name, float top, float height)
    {
        var child = contentRectTransform.Find(name);
        var image = child != null ? child.GetComponent<Image>() : null;
        if (image == null)
        {
            var go = new GameObject(name, typeof(RectTransform), typeof(CanvasRenderer), typeof(Image));
            go.transform.SetParent(contentRectTransform, false); image = go.GetComponent<Image>();
        }
        Place(image.rectTransform, top, height, 8, 8);
        Surface(image, cardColor); image.raycastTarget = false; image.transform.SetAsFirstSibling();
    }
    private void Surface(Image image, Color color)
    {
        if (image == null) return;
        image.sprite = panelSprite; image.type = Image.Type.Sliced; image.color = color;
        image.preserveAspect = false; image.pixelsPerUnitMultiplier = 1;
    }
    private void StyleText(TMP_Text text, float size, bool bold = false)
    {
        // Keep valid font bounds and identical screen-space sizing in both scenes.
        text.fontSizeMin = 20; text.fontSizeMax = size;
        text.enableAutoSizing = false; text.fontSize = size;
        text.isOrthographic = true;
        text.fontStyle = bold ? FontStyles.Bold : FontStyles.Normal;
        text.color = textColor; text.alignment = TextAlignmentOptions.MidlineLeft;
        text.overflowMode = TextOverflowModes.Truncate; text.raycastTarget = false;
    }
}
