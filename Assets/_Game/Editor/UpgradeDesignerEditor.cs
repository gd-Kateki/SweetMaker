#if UNITY_EDITOR
using System.IO;
using System.Linq;
using System.Reflection;
using TMPro;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.UI;
using Object = UnityEngine.Object;

internal static class UpgradeDesignerEditor
{
    internal const string ScreenPath = "Assets/_Game/Prefabs/UI/UpgradeScreen.prefab";
    internal const string CardPath = "Assets/_Game/Prefabs/UI/UpgradeCard.prefab";
    private const BindingFlags Private = BindingFlags.Instance | BindingFlags.NonPublic;
    private static readonly Color Ink = new Color(.22f, .16f, .29f);
    private static readonly Color Accent = new Color(.43f, .22f, .62f);
    private static Sprite Surface => AssetDatabase.LoadAssetAtPath<Sprite>("Assets/_Game/Art/UI_Assets/SettingsRemake/SettingsSurface.png");

    public static void UpgradeScenes()
    {
        var card = PrefabUtility.LoadPrefabContents(CardPath);
        try { StyleCard(card); PrefabUtility.SaveAsPrefabAsset(card, CardPath); }
        finally { PrefabUtility.UnloadPrefabContents(card); }
        foreach (string name in new[] { "MainBakery", "Game" })
        {
            var scene = EditorSceneManager.OpenScene("Assets/_Game/Scenes/" + name + ".unity", OpenSceneMode.Single);
            var controller = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren<UpgradeScreenUI>(true)).Single();
            var data = new SerializedObject(controller);
            var old = (GameObject)data.FindProperty("upgradeScreen").objectReferenceValue;
            GameObject screen;
            if (name == "MainBakery")
            {
                foreach (var item in old.GetComponentsInChildren<UpgradeCardUI>(true))
                {
                    var mods = PrefabUtility.GetPropertyModifications(item.gameObject);
                    PrefabUtility.SetPropertyModifications(item.gameObject, mods.Where(m => m.propertyPath == "upgradeDefinition" || m.propertyPath == "m_Name").ToArray());
                }
                StyleScreen(old);
                PopulateSamples(old);
                old.SetActive(true);
                PrefabUtility.SaveAsPrefabAssetAndConnect(old, ScreenPath, InteractionMode.AutomatedAction);
                screen = old;
            }
            else
            {
                var parent = old.transform.parent; int index = old.transform.GetSiblingIndex();
                screen = (GameObject)PrefabUtility.InstantiatePrefab(AssetDatabase.LoadAssetAtPath<GameObject>(ScreenPath), parent);
                screen.transform.SetSiblingIndex(index);
                data.FindProperty("upgradeScreen").objectReferenceValue = screen;
                data.FindProperty("closeButton").objectReferenceValue = screen.transform.Find("UpgradeScrollView/Header/CloseButton").GetComponent<Button>();
                data.ApplyModifiedPropertiesWithoutUndo();
                Object.DestroyImmediate(old);
            }
            screen.SetActive(false);
            PrefabUtility.RecordPrefabInstancePropertyModifications(screen);
            EditorSceneManager.MarkSceneDirty(scene); EditorSceneManager.SaveScene(scene);
        }
        AssetDatabase.SaveAssets();
        RenderPreviews();
    }

    private static void StyleScreen(GameObject root)
    {
        var blocker = root.transform.Find("ModalInputBlocker");
        blocker.GetComponent<Image>().color = new Color(.10f, .06f, .16f, .84f);
        blocker.SetAsFirstSibling();
        var panel = (RectTransform)root.transform.Find("UpgradeScrollView");
        panel.anchorMin = new Vector2(.03f, .03f); panel.anchorMax = new Vector2(.97f, .97f);
        panel.offsetMin = panel.offsetMax = Vector2.zero;
        if (panel.GetComponent<SafeAreaFitter>() == null) panel.gameObject.AddComponent<SafeAreaFitter>();
        var raw = panel.GetComponent<RawImage>(); if (raw != null) Object.DestroyImmediate(raw);
        var panelImage = panel.GetComponent<Image>() ?? panel.gameObject.AddComponent<Image>();
        Paint(panelImage, new Color(.97f, .94f, .99f));
        var scroll = panel.GetComponent<ScrollRect>();
        scroll.horizontal = false; scroll.vertical = true; scroll.movementType = ScrollRect.MovementType.Clamped;
        scroll.verticalScrollbarVisibility = ScrollRect.ScrollbarVisibility.AutoHide;
        var viewport = scroll.viewport;
        viewport.anchorMin = Vector2.zero; viewport.anchorMax = Vector2.one;
        viewport.offsetMin = new Vector2(20, 24); viewport.offsetMax = new Vector2(-36, -176);
        var oldMask = viewport.GetComponent<Mask>(); if (oldMask != null) Object.DestroyImmediate(oldMask);
        if (viewport.GetComponent<RectMask2D>() == null) viewport.gameObject.AddComponent<RectMask2D>();
        var viewportImage = viewport.GetComponent<Image>(); if (viewportImage != null) viewportImage.color = Color.clear;
        var bar = scroll.verticalScrollbar.GetComponent<RectTransform>();
        bar.anchorMin = new Vector2(1, 0); bar.anchorMax = Vector2.one;
        bar.offsetMin = new Vector2(-22, 32); bar.offsetMax = new Vector2(-12, -184);
        Paint(bar.GetComponent<Image>(), new Color(.89f, .84f, .93f));
        Paint(scroll.verticalScrollbar.handleRect.GetComponent<Image>(), Accent);
        scroll.content.anchorMin = new Vector2(0, 1); scroll.content.anchorMax = Vector2.one;
        scroll.content.pivot = new Vector2(.5f, 1); scroll.content.anchoredPosition = Vector2.zero;
        var layout = scroll.content.GetComponent<VerticalLayoutGroup>();
        layout.padding = new RectOffset(4, 4, 8, 8); layout.spacing = 20;
        layout.childControlWidth = layout.childControlHeight = true;
        layout.childForceExpandWidth = true; layout.childForceExpandHeight = false;
        var header = (RectTransform)panel.Find("Header");
        Place(header, 12, 144, 0, 0);
        var title = header.Find("TitleText").GetComponent<TMP_Text>();
        Place(title.rectTransform, 12, 60, 32, 132); Text(title, 36, 48, true); title.text = "Upgrades";
        var subtitle = header.Find("Subtitle");
        if (subtitle == null) { subtitle = new GameObject("Subtitle", typeof(RectTransform), typeof(TextMeshProUGUI)).transform; subtitle.SetParent(header, false); }
        var hint = subtitle.GetComponent<TMP_Text>();
        hint.font = title.font; hint.text = "Grow your café, one upgrade at a time.";
        Place(hint.rectTransform, 82, 42, 32, 32); Text(hint, 24, 28); hint.color = new Color(.46f, .39f, .52f);
        var close = (RectTransform)header.Find("CloseButton");
        close.anchorMin = close.anchorMax = new Vector2(1, 1); close.pivot = new Vector2(1, 1);
        close.anchoredPosition = new Vector2(-24, -12); close.sizeDelta = new Vector2(76, 76);
        Paint(close.GetComponent<Image>(), Accent);
        var label = close.GetComponentInChildren<TMP_Text>(true); label.text = "×";
        Text(label, 40, 48, true); label.color = Color.white; label.alignment = TextAlignmentOptions.Center;
        Stretch(label.rectTransform);
        label.gameObject.SetActive(false);
        if (close.Find("CloseIcon") == null)
        {
            var icon = new GameObject("CloseIcon", typeof(RectTransform)); icon.transform.SetParent(close, false);
            var iconRect = (RectTransform)icon.transform; iconRect.anchorMin = iconRect.anchorMax = new Vector2(.5f,.5f); iconRect.sizeDelta = new Vector2(36,36);
            foreach (float angle in new[] { -45f, 45f })
            {
                var stroke = new GameObject("Stroke", typeof(RectTransform), typeof(Image)); stroke.transform.SetParent(icon.transform, false);
                var strokeRect = (RectTransform)stroke.transform; strokeRect.anchorMin = strokeRect.anchorMax = new Vector2(.5f,.5f);
                strokeRect.sizeDelta = new Vector2(36,7); strokeRect.localRotation = Quaternion.Euler(0,0,angle);
                Paint(stroke.GetComponent<Image>(), Color.white); stroke.GetComponent<Image>().raycastTarget = false;
            }
        }
    }

    private static void StyleCard(GameObject root)
    {
        var rect = (RectTransform)root.transform;
        rect.anchorMin = new Vector2(0, 1); rect.anchorMax = Vector2.one; rect.pivot = new Vector2(.5f, 1);
        rect.anchoredPosition = Vector2.zero; rect.sizeDelta = new Vector2(0, 340);
        root.GetComponent<LayoutElement>().preferredHeight = 340;
        Paint(root.GetComponent<Image>(), Color.white);
        Region((RectTransform)root.transform.Find("HeaderRow"), .04f, .77f, .96f, .95f);
        Region((RectTransform)root.transform.Find("HeaderRow/UpgradeNameText"), 0, 0, .70f, 1);
        Region((RectTransform)root.transform.Find("HeaderRow/LevelText"), .72f, 0, 1, 1);
        var body = root.transform.Find("BodyRow"); Region((RectTransform)body, .04f, .06f, .96f, .71f);
        Region((RectTransform)body.Find("InformationBox"), .015f, .08f, .61f, .92f);
        Paint(body.Find("InformationBox").GetComponent<Image>(), new Color(.95f, .92f, .98f));
        Region((RectTransform)body.Find("EffectLabelText"), .045f, .55f, .58f, .87f);
        Region((RectTransform)body.Find("ValueText"), .045f, .14f, .58f, .48f);
        var action = (RectTransform)body.Find("CostActionGroup"); Region(action, .64f, .04f, .99f, .96f);
        var button = action.Find("PurchaseButton").GetComponent<Button>();
        var buttonRect = (RectTransform)button.transform;
        buttonRect.anchorMin = new Vector2(.05f, .5f); buttonRect.anchorMax = new Vector2(.95f, .5f);
        buttonRect.anchoredPosition = new Vector2(0, -40); buttonRect.sizeDelta = new Vector2(0, 84);
        var image = button.GetComponent<Image>(); image.color = Color.white;
        image.sprite = AssetDatabase.LoadAllAssetsAtPath(AssetDatabase.GUIDToAssetPath("9c680e7e11f4e7a4d8578168bb01d998")).OfType<Sprite>().First();
        image.type = Image.Type.Simple; image.preserveAspect = false;
        var colors = button.colors; colors.normalColor = Color.white; colors.disabledColor = new Color(.76f, .9f, .76f, .9f); button.colors = colors;
        var price = action.Find("PriceText").GetComponent<TMP_Text>();
        price.rectTransform.anchorMin = new Vector2(.05f, .5f); price.rectTransform.anchorMax = new Vector2(.95f, .5f);
        price.rectTransform.anchoredPosition = new Vector2(0, 60); price.rectTransform.sizeDelta = new Vector2(0, 44);
        foreach (var text in root.GetComponentsInChildren<TMP_Text>(true)) Text(text, 24, 28, true);
        Text(root.transform.Find("HeaderRow/UpgradeNameText").GetComponent<TMP_Text>(), 28, 38, true);
        var level = root.transform.Find("HeaderRow/LevelText").GetComponent<TMP_Text>(); level.alignment = TextAlignmentOptions.MidlineRight; level.color = Accent;
        Text(body.Find("ValueText").GetComponent<TMP_Text>(), 28, 36, true);
        Text(price, 26, 34, true); price.alignment = TextAlignmentOptions.Center; price.color = new Color(.23f, .48f, .30f);
        var buttonLabel = button.GetComponentInChildren<TMP_Text>(true); Stretch(buttonLabel.rectTransform);
        buttonLabel.margin = new Vector4(12, 4, 12, 4); buttonLabel.alignment = TextAlignmentOptions.Center; buttonLabel.color = new Color(.12f, .23f, .13f);
        var badge = (RectTransform)root.transform.Find("MaxLevelBadge");
        var cardData = new SerializedObject(root.GetComponent<UpgradeCardUI>());
        cardData.FindProperty("maxLevelBadge").objectReferenceValue = badge.gameObject;
        cardData.ApplyModifiedPropertiesWithoutUndo();
        badge.anchorMin = badge.anchorMax = new Vector2(.5f, 1); badge.pivot = new Vector2(.5f, 1);
        badge.anchoredPosition = new Vector2(0, -84); badge.sizeDelta = new Vector2(240, 34);
        var badgeImage = badge.GetComponentInChildren<Image>(true); Stretch(badgeImage.rectTransform); Paint(badgeImage, new Color(.28f, .55f, .37f));
        var badgeLabel = badge.GetComponentInChildren<TMP_Text>(true); Stretch(badgeLabel.rectTransform);
        Text(badgeLabel, 20, 24, true); badgeLabel.text = "MAX LEVEL"; badgeLabel.color = Color.white; badgeLabel.alignment = TextAlignmentOptions.Center;
        badge.gameObject.SetActive(false);
    }

    private static void PopulateSamples(GameObject root)
    {
        foreach (var card in root.GetComponentsInChildren<UpgradeCardUI>(true))
        {
            var data = new SerializedObject(card); var definition = (UpgradeDefinition)data.FindProperty("upgradeDefinition").objectReferenceValue;
            Label(data, "upgradeNameText").text = definition.DisplayName; Label(data, "levelText").text = "Level 1";
            Label(data, "effectLabelText").text = (string)typeof(UpgradeCardUI).GetMethod("GetEffectLabel", Private).Invoke(card, new object[] { definition.UpgradeType });
            string current = (string)typeof(UpgradeCardUI).GetMethod("GetFormattedValue", Private).Invoke(card, new object[] { definition.UpgradeType, definition.GetLevel(1) });
            string next = (string)typeof(UpgradeCardUI).GetMethod("GetFormattedValue", Private).Invoke(card, new object[] { definition.UpgradeType, definition.GetNextLevel(1) });
            Label(data, "valueText").text = current + " → " + next;
            Label(data, "priceText").text = (definition.UpgradeType == UpgradeType.Oven ? string.Empty : "$" + definition.GetNextLevel(1).UpgradeCost.ToString("N0"));
            Label(data, "buttonText").text = definition.UpgradeType == UpgradeType.Oven ? "REBIRTH" : "UPGRADE";
            var button = (Button)data.FindProperty("purchaseButton").objectReferenceValue; button.interactable = definition.UpgradeType != UpgradeType.Oven;
            foreach (var text in card.GetComponentsInChildren<TMP_Text>(true)) PrefabUtility.RecordPrefabInstancePropertyModifications(text);
            PrefabUtility.RecordPrefabInstancePropertyModifications(button);
        }
    }
    private static TMP_Text Label(SerializedObject data, string field) => (TMP_Text)data.FindProperty(field).objectReferenceValue;
    private static void Paint(Image image, Color color) { if (image == null) return; image.sprite = Surface; image.type = Image.Type.Sliced; image.color = color; image.preserveAspect = false; }
    private static void Text(TMP_Text text, float min, float max, bool bold = false)
    {
        text.fontSizeMin = min; text.fontSizeMax = max; text.fontSize = max; text.enableAutoSizing = true;
        text.fontStyle = bold ? FontStyles.Bold : FontStyles.Normal; text.fontWeight = bold ? FontWeight.Bold : FontWeight.Regular;
        text.color = Ink; text.alignment = TextAlignmentOptions.MidlineLeft; text.isOrthographic = true;
        text.textWrappingMode = TextWrappingModes.Normal; text.overflowMode = TextOverflowModes.Truncate; text.raycastTarget = false;
    }
    private static void Place(RectTransform rect, float top, float height, float left, float right)
    { rect.anchorMin = new Vector2(0, 1); rect.anchorMax = Vector2.one; rect.pivot = new Vector2(.5f, 1); rect.offsetMin = new Vector2(left, -top-height); rect.offsetMax = new Vector2(-right, -top); }
    private static void Region(RectTransform rect, float x, float y, float right, float top)
    { rect.anchorMin = new Vector2(x, y); rect.anchorMax = new Vector2(right, top); rect.offsetMin = rect.offsetMax = Vector2.zero; }
    private static void Stretch(RectTransform rect) => Region(rect, 0, 0, 1, 1);

    [MenuItem("Tools/Sweet Maker/UI/Edit Upgrade UI")]
    public static void EditScreen() { PrefabStageUtility.OpenPrefab(ScreenPath); UpgradeDesignerWindow.Open(); }
    [MenuItem("Tools/Sweet Maker/UI/Edit Upgrade Card")]
    public static void EditCard() => PrefabStageUtility.OpenPrefab(CardPath);

    public static void PolishSharedScreen()
    {
        var root = PrefabUtility.LoadPrefabContents(ScreenPath);
        try { StyleScreen(root); root.SetActive(true); PrefabUtility.SaveAsPrefabAsset(root, ScreenPath); }
        finally { PrefabUtility.UnloadPrefabContents(root); }
        foreach (string name in new[] { "MainBakery", "Game" })
        {
            var scene = EditorSceneManager.OpenScene("Assets/_Game/Scenes/" + name + ".unity", OpenSceneMode.Single);
            var controller = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren<UpgradeScreenUI>(true)).Single();
            var screen = (GameObject)new SerializedObject(controller).FindProperty("upgradeScreen").objectReferenceValue;
            screen.SetActive(false); PrefabUtility.RecordPrefabInstancePropertyModifications(screen);
            EditorSceneManager.MarkSceneDirty(scene); EditorSceneManager.SaveScene(scene);
        }
        RenderPreviews();
    }

    public static void FixCompletionBadge()
    {
        var card = PrefabUtility.LoadPrefabContents(CardPath);
        try
        {
            var data = new SerializedObject(card.GetComponent<UpgradeCardUI>());
            data.FindProperty("maxLevelBadge").objectReferenceValue = card.transform.Find("MaxLevelBadge").gameObject;
            data.ApplyModifiedPropertiesWithoutUndo();
            PrefabUtility.SaveAsPrefabAsset(card, CardPath);
        }
        finally { PrefabUtility.UnloadPrefabContents(card); }
    }

    [MenuItem("Tools/Sweet Maker/UI/Render Upgrade Previews")]
    public static void RenderPreviews()
    {
        var pipeline = GraphicsSettings.defaultRenderPipeline; var quality = QualitySettings.renderPipeline; var previous = RenderTexture.active;
        GameObject source = null, root = null, cameraRoot = null; RenderTexture target = null;
        try
        {
            GraphicsSettings.defaultRenderPipeline = null; QualitySettings.renderPipeline = null;
            source = (GameObject)PrefabUtility.InstantiatePrefab(AssetDatabase.LoadAssetAtPath<GameObject>(ScreenPath));
            root = new GameObject("Upgrade preview", typeof(RectTransform), typeof(Canvas));
            root.GetComponent<Canvas>().renderMode = RenderMode.WorldSpace; ((RectTransform)root.transform).sizeDelta = new Vector2(1080, 1920);
            var visual = EditableUIEditor.CopyVisualTree(source.transform, root.transform, source.transform); visual.SetActive(true);
            var content = visual.GetComponentsInChildren<RectTransform>(true).Single(t => t.name == "UpgradeContent");
            foreach (var t in root.GetComponentsInChildren<Transform>(true)) t.gameObject.layer = 31;
            cameraRoot = new GameObject("Upgrade preview camera", typeof(Camera)); var camera = cameraRoot.GetComponent<Camera>();
            camera.transform.position = new Vector3(0,0,-10); camera.orthographic = true; camera.orthographicSize = 960; camera.cullingMask = 1 << 31;
            camera.clearFlags = CameraClearFlags.SolidColor; camera.backgroundColor = new Color(.16f,.10f,.23f); root.GetComponent<Canvas>().worldCamera = camera;
            target = new RenderTexture(720,1280,24); target.Create(); camera.targetTexture = target; Directory.CreateDirectory("tmp");
            foreach (bool bottom in new[] { false, true })
            {
                Canvas.ForceUpdateCanvases(); LayoutRebuilder.ForceRebuildLayoutImmediate(content);
                content.anchoredPosition = new Vector2(0, bottom ? Mathf.Max(0,content.rect.height-((RectTransform)content.parent).rect.height) : 0);
                Canvas.ForceUpdateCanvases(); foreach(var text in visual.GetComponentsInChildren<TMP_Text>(true)) text.ForceMeshUpdate(true,true);
                camera.Render(); RenderTexture.active = target;
                var png = new Texture2D(720,1280,TextureFormat.RGBA32,false);
                try { png.ReadPixels(new Rect(0,0,720,1280),0,0); png.Apply(); File.WriteAllBytes("tmp/upgrades-"+(bottom?"bottom":"top")+".png",png.EncodeToPNG()); }
                finally { Object.DestroyImmediate(png); }
            }
        }
        finally
        {
            RenderTexture.active = previous; if(cameraRoot!=null)Object.DestroyImmediate(cameraRoot); if(root!=null)Object.DestroyImmediate(root); if(source!=null)Object.DestroyImmediate(source);
            if(target!=null){target.Release();Object.DestroyImmediate(target);} GraphicsSettings.defaultRenderPipeline=pipeline; QualitySettings.renderPipeline=quality;
        }
    }
}
#endif

