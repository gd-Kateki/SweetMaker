using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

// Decorates the real, wired UI rather than replacing its controllers or events.
[DefaultExecutionOrder(20000)]
public sealed class EditableUIView : MonoBehaviour
{
    public const string TemplateFolder = "UI/VisualTemplates/";
    [SerializeField] private string templateKey;
    public string TemplateKey => templateKey;
    private bool dirty = true;
    private readonly List<GameObject> decorations = new List<GameObject>();
    private static RuntimeUITheme theme;
    private static bool themeLoaded;
    private static readonly Dictionary<string, GameObject> templates = new Dictionary<string, GameObject>();

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
    private static void ResetCache() { templates.Clear(); theme = null; themeLoaded = false; }

    public static void Attach(GameObject root, string key)
    {
        var view = root.GetComponent<EditableUIView>() ?? root.AddComponent<EditableUIView>();
        view.templateKey = key; view.dirty = true;
    }
    private void OnEnable() => dirty = true;
    private void LateUpdate()
    {
        if (!dirty || string.IsNullOrEmpty(templateKey)) return;
        dirty = false;
        if (!themeLoaded) { themeLoaded = true; theme = Resources.Load<RuntimeUITheme>("UI/RuntimeUITheme"); }
        if (!templates.TryGetValue(templateKey, out var template))
            templates[templateKey] = template = Resources.Load<GameObject>(TemplateFolder + templateKey);
        if (template != null) ApplyTemplate(template.transform);
        // Explicit shared-theme overrides win. Leave fields empty/unchecked to
        // use the individual visual prefabs' artwork and typography.
        ApplyTheme(transform, theme);
    }

    private static void ApplyTheme(Transform root, RuntimeUITheme skin)
    {
        if (skin == null) return;
        foreach (var text in root.GetComponentsInChildren<TMP_Text>(true))
        {
            if (text.GetComponentInParent<EditableUIView>(true)?.transform != root) continue;
            if (skin.font != null) text.font = skin.font;
            if (skin.overrideTextColor) text.color = skin.textColor;
        }
        foreach (var image in root.GetComponentsInChildren<Image>(true))
        {
            if (image.GetComponentInParent<EditableUIView>(true)?.transform != root) continue;
            bool button = image.GetComponent<Button>() != null;
            if (button && skin.buttonSprite != null) { image.sprite = skin.buttonSprite; image.type = Image.Type.Sliced; }
            if (button && skin.overrideButtonColor) image.color = skin.buttonColor;
            if (!button && image.sprite == null && skin.panelSprite != null &&
                (image.name.Contains("card") || image.name.Contains("Card") || image.name == "Offer"))
            { image.sprite = skin.panelSprite; image.type = Image.Type.Sliced; }
        }
    }

    internal void ApplyTemplate(Transform template)
    {
        foreach (var decoration in decorations)
            if (decoration != null)
            {
                decoration.SetActive(false);
                if (Application.isPlaying) Destroy(decoration); else DestroyImmediate(decoration);
            }
        decorations.Clear();
        foreach (var part in template.GetComponentsInChildren<EditableUIVisual>(true))
        {
            Transform target = Resolve(transform, part.targetPath);
            if (target == null) continue; // A newer screen can have additional elements.
            if (target.GetComponentInParent<EditableUIView>(true) != this) continue;
            CopyPart(part, target);
            // New artist-authored children are decorations, not functional controls.
            foreach (Transform child in part.transform)
            {
                if (child.GetComponent<EditableUIVisual>() != null) continue;
                var copy = Instantiate(child.gameObject, target, false);
                foreach (var graphic in copy.GetComponentsInChildren<Graphic>(true)) graphic.raycastTarget = false;
                decorations.Add(copy);
            }
        }
    }

    internal static void CopyPart(EditableUIVisual source, Transform target)
    {
        bool copyLayout = source.copyLayout && target.GetComponent<Canvas>() == null &&
            !target.name.Replace(" ", "").Equals("SafeArea", System.StringComparison.OrdinalIgnoreCase) &&
            target.GetComponentInParent<Slider>(true) == null && target.GetComponentInParent<Toggle>(true) == null;
        var parentScroll = target.GetComponentInParent<ScrollRect>(true);
        if (parentScroll != null && parentScroll.content == target) copyLayout = false;
        if (copyLayout && source.transform is RectTransform from && target is RectTransform to)
        {
            to.anchorMin = from.anchorMin; to.anchorMax = from.anchorMax; to.pivot = from.pivot;
            to.sizeDelta = from.sizeDelta; to.anchoredPosition3D = from.anchoredPosition3D;
            to.localRotation = from.localRotation; to.localScale = from.localScale;
        }
        if (!source.copyVisuals) return;
        var button = target.GetComponent<Button>();
        if (source.copyButtonStyle && button != null)
        {
            button.colors = source.buttonColors; button.spriteState = source.buttonSprites;
            button.transition = source.buttonTransition;
        }
        var image = source.GetComponent<Image>(); var targetImage = target.GetComponent<Image>();
        if (image != null && targetImage != null)
        {
            if (source.copyImageSprite) targetImage.sprite = image.sprite;
            if (source.copyImageColor) targetImage.color = image.color;
            targetImage.type = image.type;
            targetImage.material = image.material; targetImage.preserveAspect = image.preserveAspect;
            targetImage.pixelsPerUnitMultiplier = image.pixelsPerUnitMultiplier;
        }
        var raw = source.GetComponent<RawImage>(); var targetRaw = target.GetComponent<RawImage>();
        if (raw != null && targetRaw != null) { targetRaw.texture = raw.texture; targetRaw.color = raw.color; targetRaw.uvRect = raw.uvRect; targetRaw.material = raw.material; }
        var text = source.GetComponent<TMP_Text>(); var targetText = target.GetComponent<TMP_Text>();
        if (text != null && targetText != null)
        {
            targetText.font = text.font; targetText.fontSharedMaterial = text.fontSharedMaterial;
            targetText.color = text.color; targetText.fontSize = text.fontSize; targetText.fontStyle = text.fontStyle;
            targetText.enableAutoSizing = text.enableAutoSizing; targetText.fontSizeMin = text.fontSizeMin; targetText.fontSizeMax = text.fontSizeMax;
            targetText.alignment = text.alignment; targetText.margin = text.margin;
            targetText.characterSpacing = text.characterSpacing; targetText.lineSpacing = text.lineSpacing;
            // Never copy text, rich-text permission, active state, listeners or interaction state.
        }
        var legacy = source.GetComponent<Text>(); var targetLegacy = target.GetComponent<Text>();
        if (legacy != null && targetLegacy != null)
        {
            targetLegacy.font = legacy.font; targetLegacy.fontSize = legacy.fontSize;
            targetLegacy.color = legacy.color; targetLegacy.fontStyle = legacy.fontStyle;
            targetLegacy.alignment = legacy.alignment; targetLegacy.resizeTextForBestFit = legacy.resizeTextForBestFit;
            targetLegacy.resizeTextMinSize = legacy.resizeTextMinSize; targetLegacy.resizeTextMaxSize = legacy.resizeTextMaxSize;
        }
        var layout = source.GetComponent<LayoutElement>(); var targetLayout = target.GetComponent<LayoutElement>();
        if (copyLayout && layout != null && targetLayout != null)
        {
            targetLayout.minWidth = layout.minWidth; targetLayout.minHeight = layout.minHeight;
            targetLayout.preferredWidth = layout.preferredWidth; targetLayout.preferredHeight = layout.preferredHeight;
            targetLayout.flexibleWidth = layout.flexibleWidth; targetLayout.flexibleHeight = layout.flexibleHeight;
        }
        foreach (var effect in source.GetComponents<Shadow>())
        {
            var component = target.GetComponent(effect.GetType());
            if (component == null) component = target.gameObject.AddComponent(effect.GetType());
            var targetEffect = (Shadow)component;
            targetEffect.effectColor = effect.effectColor; targetEffect.effectDistance = effect.effectDistance;
            targetEffect.useGraphicAlpha = effect.useGraphicAlpha;
        }
        if (copyLayout)
        {
            var group = source.GetComponent<HorizontalOrVerticalLayoutGroup>();
            var targetGroup = target.GetComponent<HorizontalOrVerticalLayoutGroup>();
            if (group != null && targetGroup != null)
            {
                targetGroup.padding = new RectOffset(group.padding.left, group.padding.right, group.padding.top, group.padding.bottom);
                targetGroup.spacing = group.spacing; targetGroup.childAlignment = group.childAlignment;
                targetGroup.childControlWidth = group.childControlWidth; targetGroup.childControlHeight = group.childControlHeight;
                targetGroup.childForceExpandWidth = group.childForceExpandWidth; targetGroup.childForceExpandHeight = group.childForceExpandHeight;
            }
        }
    }

    // Names + sibling occurrence handle repeated Label children without depending
    // on all sibling indices. Do not rename/reparent captured binding elements.
    public static string PathFor(Transform root, Transform item)
    {
        if (item == root) return "";
        var parts = new List<string>();
        while (item != null && item != root)
        {
            int occurrence = 0;
            for (int i = 0; i < item.GetSiblingIndex(); i++)
                if (item.parent.GetChild(i).name == item.name) occurrence++;
            parts.Add(System.Uri.EscapeDataString(item.name) + ":" + occurrence);
            item = item.parent;
        }
        parts.Reverse(); return string.Join("/", parts);
    }
    private static Transform Resolve(Transform root, string path)
    {
        if (string.IsNullOrEmpty(path)) return root;
        foreach (string segment in path.Split('/'))
        {
            int separator = segment.LastIndexOf(':');
            if (separator < 0 || !int.TryParse(segment.Substring(separator + 1), out int occurrence)) return null;
            string name = System.Uri.UnescapeDataString(segment.Substring(0, separator));
            Transform found = null;
            foreach (Transform child in root)
                if (child.name == name && occurrence-- == 0) { found = child; break; }
            if (found == null) return null;
            root = found;
        }
        return root;
    }
}
