#if UNITY_EDITOR
using System;
using System.IO;
using System.Linq;
using System.Reflection;
using TMPro;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;

internal sealed class EditableUIEditor : EditorWindow
{
    internal const string DirectoryPath = "Assets/_Game/Resources/UI/VisualTemplates";
    private Vector2 scroll;
    [MenuItem("Tools/Sweet Maker/UI Designer")]
    private static void Open() => GetWindow<EditableUIEditor>("UI Designer");

    [MenuItem("Tools/Sweet Maker/UI/Create or Select Shared Theme")]
    public static void CreateTheme()
    {
        const string path = "Assets/_Game/Resources/UI/RuntimeUITheme.asset";
        Directory.CreateDirectory(Path.GetDirectoryName(path));
        var theme = AssetDatabase.LoadAssetAtPath<RuntimeUITheme>(path);
        if (theme == null) { theme = CreateInstance<RuntimeUITheme>(); AssetDatabase.CreateAsset(theme, path); AssetDatabase.SaveAssets(); }
        Selection.activeObject = theme;
    }

    [MenuItem("Tools/Sweet Maker/UI/Create Missing Starter Templates")]
    public static void CreateStarterTemplates()
    {
        CreateTheme();
        // Only pure visual builders are invoked, on inactive temporary objects.
        // No Awake/Start, player-pref changes, authentication, saving or ad SDK calls.
        var staging = new GameObject("UI design staging"); staging.SetActive(false);
        try
        {
            var cloud = new GameObject("Cloud preview service"); cloud.transform.SetParent(staging.transform);
            var service = cloud.AddComponent<SweetMerge.Cloud.SimpleCloudBackup>();
            typeof(SweetMerge.Cloud.SimpleCloudBackup).GetField("freshInstallOwner", BindingFlags.Instance | BindingFlags.NonPublic).SetValue(service, "preview");
            var choice = MakeCanvas(staging.transform, "Cloud progress choice");
            var choiceUI = choice.AddComponent<SweetMerge.Cloud.FreshInstallCloudChoiceUI>();
            Set(choiceUI, "service", service); Call(choiceUI, "Build");
            foreach (bool energy in new[] { true, false })
            {
                var root = MakeCanvas(staging.transform, "Watch ad offer"); var popup = root.AddComponent<AdOfferPopup>();
                Set(popup, "energy", energy); Set(popup, "amount", energy ? 50 : 100); Call(popup, "Build", root);
            }
            var leaderboard = MakeCanvas(staging.transform, "Cafe Leaderboard UI");
            Call(leaderboard.AddComponent<CafeLeaderboardUI>(), "BuildInterface");
            foreach (var age in Enum.GetValues(typeof(AdvertisingPrivacy.AgeGroup)))
            {
                var view = PrivacyCanvas(staging.transform); Call(view, "BuildAdvertising", age);
            }
            Call(PrivacyCanvas(staging.transform), "BuildDeletion");
            MakeView(staging.transform, typeof(StartupPrivacyWelcomeUI), "BuildInterface");
            MakeView(staging.transform, typeof(MainBakeryStartupUI), "BuildInterface");
            MakeView(staging.transform, typeof(FeatureIntroductionPopup), "BuildInterface");
            MakeView(staging.transform, typeof(SweetMerge.Profile.HybridTutorialWelcomeUI), "BuildPanel");
            MakeView(staging.transform, typeof(SweetMerge.Profile.HybridTutorialGameplayUI), "BuildPanel");
            var profileRoot = MakeCanvas(staging.transform, "Cafe profile preview");
            var profile = profileRoot.AddComponent<CafeProfileUI>();
            Call(profile, "CreateCard"); Call(profile, "CreatePanel"); Call(profile, "CreateNamingPopup");
            var accountRoot = MakeCanvas(staging.transform, "Account section");
            var account = accountRoot.AddComponent<SweetMerge.Authentication.GooglePlayGamesAccountSettingsControl>();
            Call(account, "BuildControls");
            SweetMerge.Cloud.SimpleCloudPanel.Attach(accountRoot.transform, TMP_Settings.defaultFontAsset);
            PlayerPrivacyUI.AttachSettings(accountRoot.transform, null); // No button is invoked in the preview.
            var analyticsRoot = MakeCanvas(staging.transform, "Analytics section");
            Call(analyticsRoot.AddComponent<SweetMerge.Analytics.AnalyticsConsentSettingsControl>(), "BuildControls");
            EditableUIView.Attach(analyticsRoot, "AnalyticsSettings");
            foreach (var view in staging.GetComponentsInChildren<EditableUIView>(true))
            {
                string path = DirectoryPath + "/" + view.TemplateKey + ".prefab";
                if (File.Exists(path)) continue;
                Directory.CreateDirectory(DirectoryPath);
                var visual = CopyVisualTree(view.transform, null, view.transform);
                try { PrefabUtility.SaveAsPrefabAsset(visual, path); }
                finally { DestroyImmediate(visual); }
            }
            AssetDatabase.SaveAssets();
            Debug.Log("Starter UI visual templates created. Existing designs were preserved.");
        }
        finally { DestroyImmediate(staging); }
    }

    private static GameObject MakeCanvas(Transform parent, string name)
    {
        var root = new GameObject(name, typeof(RectTransform), typeof(Canvas), typeof(CanvasScaler));
        root.transform.SetParent(parent, false);
        root.GetComponent<Canvas>().renderMode = RenderMode.ScreenSpaceOverlay;
        var scaler = root.GetComponent<CanvasScaler>(); scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(720, 1280);
        root.GetComponent<RectTransform>().sizeDelta = new Vector2(720, 1280);
        return root;
    }
    private static PlayerPrivacyUI PrivacyCanvas(Transform parent)
    {
        var root = MakeCanvas(parent, "Player privacy");
        Transform current = root.transform;
        foreach (string name in new[] { "Shade", "Safe area", "Privacy content" })
        {
            var child = new GameObject(name, typeof(RectTransform)); child.transform.SetParent(current, false);
            var rect = child.GetComponent<RectTransform>(); rect.anchorMin = Vector2.zero; rect.anchorMax = Vector2.one; rect.offsetMin = rect.offsetMax = Vector2.zero;
            current = child.transform;
        }
        var view = root.AddComponent<PlayerPrivacyUI>(); Set(view, "card", current); return view;
    }
    private static void MakeView(Transform parent, Type type, string builder)
    {
        var root = MakeCanvas(parent, type.Name); Call(root.AddComponent(type), builder);
    }
    private static void Set(object target, string field, object value) => target.GetType().GetField(field, BindingFlags.Instance | BindingFlags.NonPublic).SetValue(target, value);
    private static void Call(object target, string method, params object[] args) => target.GetType().GetMethod(method, BindingFlags.Instance | BindingFlags.NonPublic).Invoke(target, args);

    private void OnGUI()
    {
        EditorGUILayout.HelpBox("Scene UIs: edit their scene/prefab normally. Runtime UIs: enter Play Mode, open the screen, then capture its visual prefab below. Exit Play Mode and edit the prefab. Only visuals/layout are applied; real button actions and live text stay wired by the game. See UI_GUIDE.md.", MessageType.Info);
        if (GUILayout.Button("Create / select shared fonts and artwork theme")) CreateTheme();
        scroll = EditorGUILayout.BeginScrollView(scroll);
        foreach (var view in Resources.FindObjectsOfTypeAll<EditableUIView>()
            .Where(v => v != null && !EditorUtility.IsPersistent(v) && v.gameObject.scene.IsValid())
            .OrderBy(v => v.TemplateKey))
        {
            EditorGUILayout.LabelField(view.TemplateKey, EditorStyles.boldLabel);
            EditorGUILayout.ObjectField(view.gameObject, typeof(GameObject), true);
            if (GUILayout.Button("Capture editable visual prefab")) Capture(view);
        }
        EditorGUILayout.EndScrollView();
    }

    [MenuItem("Tools/Sweet Maker/UI/Capture Selected Runtime View")]
    private static void CaptureSelection()
    {
        var view = Selection.activeGameObject != null ? Selection.activeGameObject.GetComponentInParent<EditableUIView>(true) : null;
        if (view == null) { Debug.LogWarning("Select a generated UI root or one of its children with an EditableUIView ancestor."); return; }
        Capture(view);
    }

    private static void Capture(EditableUIView view)
    {
        string key = view.TemplateKey;
        if (string.IsNullOrEmpty(key) || key.Any(c => !char.IsLetterOrDigit(c) && c != '_' && c != '-'))
            throw new InvalidOperationException("Visual template key must contain letters, digits, '-' or '_'.");
        Directory.CreateDirectory(DirectoryPath);
        string path = DirectoryPath + "/" + key + ".prefab";
        if (File.Exists(path) && !EditorUtility.DisplayDialog("Replace visual template?", "This replaces existing design edits in " + path + ".", "Replace", "Cancel")) return;
        var clone = CopyVisualTree(view.transform, null, view.transform);
        try
        {
            PrefabUtility.SaveAsPrefabAsset(clone, path);
            AssetDatabase.SaveAssets(); Selection.activeObject = AssetDatabase.LoadAssetAtPath<GameObject>(path);
            Debug.Log("Editable UI visual template saved: " + path);
        }
        finally { DestroyImmediate(clone); }
    }

    // Build a new tree without cloning game controllers: capturing a view must
    // never execute sign-in, rewards, saving, network calls or runtime listeners.
    internal static GameObject CopyVisualTree(Transform source, Transform parent, Transform sourceRoot)
    {
        var copy = new GameObject(source.name, typeof(RectTransform));
        if (parent != null) copy.transform.SetParent(parent, false);
        if (source is RectTransform rect)
        {
            var destination = copy.GetComponent<RectTransform>();
            destination.anchorMin = rect.anchorMin; destination.anchorMax = rect.anchorMax; destination.pivot = rect.pivot;
            destination.sizeDelta = rect.sizeDelta; destination.anchoredPosition3D = rect.anchoredPosition3D;
            destination.localScale = rect.localScale; destination.localRotation = rect.localRotation;
        }
        foreach (var component in source.GetComponents<Component>())
        {
            if (component == null || component is Transform || component is CanvasRenderer) continue;
            Type type = component.GetType();
            if (!(component is Image || component is RawImage || component is Text || component is TextMeshProUGUI || component is Canvas ||
                component is CanvasScaler || component is LayoutElement || component is LayoutGroup ||
                component is ContentSizeFitter || component is AspectRatioFitter || component is RectMask2D ||
                component is Mask || component is Shadow)) continue;
            var destination = copy.GetComponent(type);
            if (destination == null) destination = copy.AddComponent(type);
            EditorUtility.CopySerialized(component, destination);
            if (destination is Graphic graphic) graphic.raycastTarget = false;
        }
        var part = copy.AddComponent<EditableUIVisual>();
        part.targetPath = EditableUIView.PathFor(sourceRoot, source);
        part.copyLayout = source != sourceRoot && source.name != "Safe area";
        if (source.GetComponentInParent<Slider>(true) != null || source.GetComponentInParent<Toggle>(true) != null)
            part.copyLayout = false; // Keep live slider/toggle values in control of positioning.
        var scroll = source.GetComponentInParent<ScrollRect>(true);
        if (scroll != null && scroll.content == source) part.copyLayout = false;
        string lowerName = source.name.ToLowerInvariant();
        if (source.GetComponent<Image>() != null && (lowerName.Contains("icon") || lowerName.Contains("star") || lowerName.Contains("requirement")))
        { part.copyImageSprite = false; part.copyImageColor = false; }
        var button = source.GetComponent<Button>();
        if (button != null)
        {
            part.copyButtonStyle = true; part.buttonColors = button.colors;
            part.buttonSprites = button.spriteState; part.buttonTransition = button.transition;
        }
        foreach (Transform child in source) CopyVisualTree(child, copy.transform, sourceRoot);
        copy.SetActive(source == sourceRoot || source.gameObject.activeSelf);
        return copy;
    }
}
#endif
