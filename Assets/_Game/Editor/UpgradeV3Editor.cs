#if UNITY_EDITOR
using System.Linq;
using TMPro;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;

internal static class UpgradeV3Editor
{
    internal const string Art = "Assets/_Game/Art/UI_Assets/UI V3/Shop_Upgrade/";
    internal const string RowPath = Art + "SU_RowSlice.asset";
    private static readonly Color Ink = new Color(.25f,.16f,.12f);
    private static Sprite Sprite(string name) => AssetDatabase.LoadAllAssetsAtPath(Art + name + ".png").OfType<Sprite>().First();
    private static void Paint(Image image, Sprite sprite, bool sliced = true)
    {
        image.sprite = sprite; image.type = sliced ? Image.Type.Sliced : Image.Type.Simple;
        image.color = Color.white; image.preserveAspect = !sliced;
    }
    private static RectTransform Child(Transform parent, string name)
    {
        var child = parent.Find(name) as RectTransform;
        if (child == null)
        {
            child = new GameObject(name, typeof(RectTransform), typeof(Image)).GetComponent<RectTransform>();
            child.SetParent(parent, false); child.GetComponent<Image>().raycastTarget = false;
        }
        return child;
    }
    private static void Stretch(RectTransform rect, Vector2 min, Vector2 max)
    { rect.anchorMin = Vector2.zero; rect.anchorMax = Vector2.one; rect.offsetMin = min; rect.offsetMax = max; }
    private static void Region(RectTransform rect, Vector2 min, Vector2 max)
    { rect.anchorMin = min; rect.anchorMax = max; rect.offsetMin = rect.offsetMax = Vector2.zero; }

    public static void Apply()
    {
        // Reuse the first cream row directly from the supplied backplate texture.
        // No replacement artwork or additional bitmap is generated.
        if (AssetDatabase.LoadAssetAtPath<Sprite>(RowPath) == null)
        {
            var row = UnityEngine.Sprite.Create(Sprite("SU_Backplate").texture,
                new Rect(56,1156,774,326), new Vector2(.5f,.5f), 100, 0, SpriteMeshType.FullRect, new Vector4(40,40,40,40));
            row.name = "SU_RowSlice"; AssetDatabase.CreateAsset(row, RowPath);
        }
        var card = PrefabUtility.LoadPrefabContents(UpgradeDesignerEditor.CardPath);
        try
        {
            Paint(card.GetComponent<Image>(), AssetDatabase.LoadAssetAtPath<Sprite>(RowPath));
            card.GetComponent<LayoutElement>().preferredHeight = 326;
            var cardRect = (RectTransform)card.transform; cardRect.sizeDelta = new Vector2(cardRect.sizeDelta.x,326);
            var info = (RectTransform)card.transform.Find("BodyRow/InformationBox");
            Region(info, new Vector2(.015f,.13f), new Vector2(.61f,.49f));
            Paint(info.GetComponent<Image>(), Sprite("SU_Bar"));
            var button = card.GetComponentInChildren<Button>(true);
            Paint(button.GetComponent<Image>(), Sprite("SU_Upgrade"));
            var colors = button.colors; colors.normalColor = Color.white; colors.highlightedColor = Color.white;
            colors.pressedColor = new Color(.83f,.91f,.80f); colors.disabledColor = new Color(.62f,.68f,.62f);
            button.colors = colors; button.targetGraphic = button.GetComponent<Image>();
            foreach (var text in card.GetComponentsInChildren<TMP_Text>(true))
            {
                text.color = text.enableVertexGradient ? Color.white : Ink;
                if (text.transform.IsChildOf(button.transform))
                { text.enableVertexGradient = false; text.color = new Color(.10f,.24f,.10f); }
            }
            var badge = card.transform.Find("MaxLevelBadge");
            Paint(badge.GetComponentInChildren<Image>(true), Sprite("SU_Bar"));
            badge.GetComponentInChildren<TMP_Text>(true).color = Ink;
            PrefabUtility.SaveAsPrefabAsset(card, UpgradeDesignerEditor.CardPath);
        }
        finally { PrefabUtility.UnloadPrefabContents(card); }

        var screen = PrefabUtility.LoadPrefabContents(UpgradeDesignerEditor.ScreenPath);
        try
        {
            screen.SetActive(true);
            screen.transform.Find("ModalInputBlocker").GetComponent<Image>().color = new Color(.08f,.04f,.12f,.68f);
            var panel = (RectTransform)screen.transform.Find("UpgradeScrollView");
            panel.anchorMin = new Vector2(.03f,.05f); panel.anchorMax = new Vector2(.97f,.95f);
            panel.offsetMin = panel.offsetMax = Vector2.zero;
            var panelImage = panel.GetComponent<Image>(); panelImage.sprite = null; panelImage.color = Color.clear;
            var frame = Child(panel, "V3GoldFrame"); frame.SetAsFirstSibling();
            Stretch(frame, new Vector2(68,48), new Vector2(-68,-100));
            Paint(frame.GetComponent<Image>(), Sprite("SU_Backplate"));
            // The source contains four baked row plates. Render its frame only;
            // individual scrolling cards reuse its cream row slice instead.
            frame.GetComponent<Image>().fillCenter = false;
            var center = Child(frame, "GoldInterior");
            Stretch(center, new Vector2(48,110), new Vector2(-48,-110));
            center.GetComponent<Image>().sprite = null;
            center.GetComponent<Image>().color = new Color32(244,215,81,255);
            var scroll = panel.GetComponent<ScrollRect>();
            scroll.horizontal = false; scroll.vertical = true; scroll.movementType = ScrollRect.MovementType.Clamped;
            Stretch(scroll.viewport, new Vector2(122,144), new Vector2(-122,-220));
            scroll.viewport.GetComponent<Image>().color = Color.clear;
            var layout = scroll.content.GetComponent<VerticalLayoutGroup>();
            layout.padding = new RectOffset(0,0,0,0); layout.spacing = 20;
            layout.childControlWidth = layout.childControlHeight = true;
            layout.childForceExpandHeight = false;
            scroll.content.anchoredPosition = Vector2.zero;
            if (scroll.verticalScrollbar != null)
            {
                Stretch((RectTransform)scroll.verticalScrollbar.transform, new Vector2(0,56), new Vector2(0,-224));
                var bar = (RectTransform)scroll.verticalScrollbar.transform;
                bar.anchorMin = new Vector2(1,0); bar.anchorMax = Vector2.one;
                bar.offsetMin = new Vector2(-102,150); bar.offsetMax = new Vector2(-90,-224);
                Paint(bar.GetComponent<Image>(), Sprite("SU_Bar"));
                Paint(scroll.verticalScrollbar.handleRect.GetComponent<Image>(), Sprite("SU_Bar"));
                scroll.verticalScrollbar.handleRect.GetComponent<Image>().color = new Color(.68f,.53f,.14f,.8f);
            }
            var header = (RectTransform)panel.Find("Header");
            header.anchorMin = new Vector2(0,1); header.anchorMax = Vector2.one; header.pivot = new Vector2(.5f,1);
            header.anchoredPosition = Vector2.zero; header.sizeDelta = new Vector2(0,180);
            var plaque = Child(header, "V3TitlePlate"); plaque.SetAsFirstSibling();
            plaque.anchorMin = plaque.anchorMax = new Vector2(.5f,1); plaque.pivot = new Vector2(.5f,1);
            plaque.anchoredPosition = Vector2.zero; plaque.sizeDelta = new Vector2(400,176);
            Paint(plaque.GetComponent<Image>(), Sprite("SU_Board"));
            var title = header.Find("TitleText").GetComponent<TMP_Text>();
            title.rectTransform.anchorMin = title.rectTransform.anchorMax = new Vector2(.5f,1);
            title.rectTransform.pivot = new Vector2(.5f,1); title.rectTransform.anchoredPosition = new Vector2(0,-22);
            title.rectTransform.sizeDelta = new Vector2(340,100); title.text = "Upgrades"; title.alignment = TextAlignmentOptions.Center;
            var subtitle = header.Find("Subtitle"); if (subtitle != null) subtitle.gameObject.SetActive(false);
            var close = (RectTransform)header.Find("CloseButton");
            close.anchorMin = close.anchorMax = Vector2.one; close.pivot = Vector2.one;
            close.anchoredPosition = new Vector2(-16,-4); close.sizeDelta = new Vector2(160,180);
            Paint(close.GetComponent<Image>(), Sprite("SU_Cancel"), false);
            var closeButton = close.GetComponent<Button>(); var closeColors = closeButton.colors;
            closeColors.normalColor = closeColors.highlightedColor = Color.white;
            closeColors.pressedColor = new Color(.86f,.82f,.82f); closeButton.colors = closeColors;
            foreach (var text in close.GetComponentsInChildren<TMP_Text>(true)) { text.text = string.Empty; text.gameObject.SetActive(false); }
            var oldIcon = close.Find("CloseIcon"); if (oldIcon != null) oldIcon.gameObject.SetActive(false);
            foreach (var item in screen.GetComponentsInChildren<UpgradeCardUI>(true))
            {
                var mods = PrefabUtility.GetPropertyModifications(item.gameObject);
                if (mods != null) PrefabUtility.SetPropertyModifications(item.gameObject,
                    mods.Where(m => m.propertyPath == "upgradeDefinition" || m.propertyPath == "m_Name" || m.propertyPath == "m_text" || m.propertyPath == "m_Interactable").ToArray());
                var labels = item.GetComponentsInChildren<TMP_Text>(true);
                foreach (var text in labels.Where(t => t.text == "REBIRTH"))
                { text.text = "PRESTIGE"; PrefabUtility.RecordPrefabInstancePropertyModifications(text); }
            }
            PrefabUtility.SaveAsPrefabAsset(screen, UpgradeDesignerEditor.ScreenPath);
        }
        finally { PrefabUtility.UnloadPrefabContents(screen); }
        AssetDatabase.SaveAssets(); UpgradeDesignerEditor.RenderPreviews();
        Debug.Log("UPGRADES V3 | Shop reference artwork applied to the shared screen and all upgrade cards.");
    }
}
#endif
