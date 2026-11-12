#if UNITY_EDITOR
using System;
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

internal static class SettingsLayoutEditor
{
    private const string SurfacePath = "Assets/_Game/Art/UI_Assets/SettingsRemake/SettingsSurface.png";
    internal const string DesignPath = EditableUIEditor.DirectoryPath + "/SettingsArtwork.prefab";
    private const BindingFlags Private = BindingFlags.Instance | BindingFlags.NonPublic;

    // Run once to upgrade the two existing, wired scene views without replacing their controllers.
    public static void UpgradeScenes()
    {
        AssetDatabase.ImportAsset(SurfacePath);
        var importer = (TextureImporter)AssetImporter.GetAtPath(SurfacePath);
        importer.textureType = TextureImporterType.Sprite; importer.spriteImportMode = SpriteImportMode.Single;
        importer.spriteBorder = new Vector4(18, 18, 18, 18); importer.spritePixelsPerUnit = 100;
        importer.mipmapEnabled = false; importer.alphaIsTransparency = true; importer.SaveAndReimport();
        foreach (string name in new[] { "MainBakery", "Game" })
        {
            var scene = EditorSceneManager.OpenScene("Assets/_Game/Scenes/" + name + ".unity", OpenSceneMode.Single);
            var view = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren<SettingsScreenPresentation>(true)).Single();
            var serialized = new SerializedObject(view);
            serialized.FindProperty("panelSprite").objectReferenceValue = AssetDatabase.LoadAssetAtPath<Sprite>(SurfacePath);
            serialized.ApplyModifiedPropertiesWithoutUndo();
            Canvas.ForceUpdateCanvases(); Invoke(view, "ApplyLayout");
            EditorSceneManager.MarkSceneDirty(scene); EditorSceneManager.SaveScene(scene);
        }
        AssetDatabase.SaveAssets();
        EnsureDesignPrefab();
        GeneratePreviews();
    }

    [MenuItem("Tools/Sweet Maker/UI/Render Settings Previews")]
    public static void RenderPreviews() { EnsureDesignPrefab(); GeneratePreviews(); }

    private static void GeneratePreviews()
    {
        var pipeline = GraphicsSettings.defaultRenderPipeline;
        var quality = QualitySettings.renderPipeline;
        var previousTarget = RenderTexture.active;
        try
        {
            GraphicsSettings.defaultRenderPipeline = null; QualitySettings.renderPipeline = null;
            Directory.CreateDirectory("tmp");
            foreach (string name in new[] { "MainBakery", "Game" })
            {
                var scene = EditorSceneManager.OpenPreviewScene("Assets/_Game/Scenes/" + name + ".unity");
                GameObject canvasRoot = null, cameraRoot = null;
                RenderTexture target = null;
                try
                {
                    var view = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren<SettingsScreenPresentation>(true)).Single();
                    var content = (RectTransform)typeof(SettingsScreenPresentation).GetField("contentRectTransform", Private).GetValue(view);
                    // Build only settings controls; no sign-in, save, ad or gameplay services are started.
                    BuildSection(content, "AnalyticsPrivacySettings", typeof(SweetMerge.Analytics.AnalyticsConsentSettingsControl));
                    var account = BuildSection(content, "GooglePlayGamesAccountSettings", typeof(SweetMerge.Authentication.GooglePlayGamesAccountSettingsControl));
                    SweetMerge.Cloud.SimpleCloudPanel.Attach(account, TMP_Settings.defaultFontAsset);
                    PlayerPrivacyUI.AttachSettings(content, null);
                    Invoke(view, "ApplyLayout");
                    EditableUIView.Attach(view.gameObject, "SettingsArtwork");
                    var owner = view.GetComponent<EditableUIView>(); owner.IncludeNestedViews();
                    typeof(EditableUIView).GetMethod("ApplyTemplate", Private).Invoke(owner,
                        new object[] { AssetDatabase.LoadAssetAtPath<GameObject>(DesignPath).transform });
                    canvasRoot = new GameObject("Settings visual preview", typeof(RectTransform), typeof(Canvas));
                    var canvas = canvasRoot.GetComponent<Canvas>(); canvas.renderMode = RenderMode.WorldSpace;
                    var rootRect = canvasRoot.GetComponent<RectTransform>(); rootRect.sizeDelta = new Vector2(1080, 1920);
                    var visual = EditableUIEditor.CopyVisualTree(view.transform, canvasRoot.transform, view.transform);
                    visual.SetActive(true);
                    visual.GetComponentsInChildren<TMP_Text>(true).Single(t => t.name == "GameVersionValue").text = "v" + Application.version;
                    visual.GetComponentsInChildren<TMP_Text>(true).Single(t => t.name == "SettingsPersistenceFeedback").text = "Saved";
                    foreach (var part in visual.GetComponentsInChildren<EditableUIVisual>(true))
                        if (part.copyButtonStyle && part.GetComponent<Image>() != null)
                            part.GetComponent<Image>().color *= part.buttonColors.normalColor;
                    cameraRoot = new GameObject("Settings preview camera", typeof(Camera));
                    var camera = cameraRoot.GetComponent<Camera>(); camera.transform.position = new Vector3(0, 0, -10);
                    camera.orthographic = true; camera.orthographicSize = 960; camera.cullingMask = 1 << 31;
                    camera.clearFlags = CameraClearFlags.SolidColor; camera.backgroundColor = new Color(.16f, .10f, .23f);
                    canvas.worldCamera = camera;
                    foreach (var t in canvasRoot.GetComponentsInChildren<Transform>(true)) t.gameObject.layer = 31;
                    target = new RenderTexture(720, 1280, 24); target.Create(); camera.targetTexture = target;
                    var visualContent = visual.GetComponentsInChildren<RectTransform>(true).Single(r => r.name == "SettingsScrollContent");
                    foreach (bool bottom in new[] { false, true })
                    {
                        Canvas.ForceUpdateCanvases();
                        visualContent.anchoredPosition = new Vector2(0, bottom ? visualContent.rect.height - ((RectTransform)visualContent.parent).rect.height : 0);
                        Canvas.ForceUpdateCanvases();
                        foreach (var text in visual.GetComponentsInChildren<TMP_Text>(true))
                        {
                            text.SetAllDirty();
                            text.ForceMeshUpdate(true, true);
                        }
                        Canvas.ForceUpdateCanvases();
                        foreach (var button in canvasRoot.GetComponentsInChildren<Button>(true))
                            if (button.targetGraphic != null) button.targetGraphic.canvasRenderer.SetColor(button.colors.normalColor);
                        camera.Render(); RenderTexture.active = target;
                        var png = new Texture2D(720, 1280, TextureFormat.RGBA32, false);
                        try { png.ReadPixels(new Rect(0, 0, 720, 1280), 0, 0); png.Apply(); File.WriteAllBytes("tmp/settings-" + name + (bottom ? "-bottom" : "-top") + ".png", png.EncodeToPNG()); }
                        finally { Object.DestroyImmediate(png); }
                    }
                }
                finally
                {
                    RenderTexture.active = previousTarget;
                    if (cameraRoot != null) Object.DestroyImmediate(cameraRoot);
                    if (canvasRoot != null) Object.DestroyImmediate(canvasRoot);
                    if (target != null) { target.Release(); Object.DestroyImmediate(target); }
                    EditorSceneManager.ClosePreviewScene(scene);
                }
            }
        }
        finally { GraphicsSettings.defaultRenderPipeline = pipeline; QualitySettings.renderPipeline = quality; RenderTexture.active = previousTarget; }
    }
    [MenuItem("Tools/Sweet Maker/UI/Edit Settings UI")]
    public static void EditSettings()
    {
        EnsureDesignPrefab();
        UnityEditor.SceneManagement.PrefabStageUtility.OpenPrefab(DesignPath);
        SettingsDesignerWindow.Open();
    }

    public static void EnsureDesignPrefab()
    {
        if (AssetDatabase.LoadAssetAtPath<GameObject>(DesignPath) != null) return;
        var scene = EditorSceneManager.OpenPreviewScene("Assets/_Game/Scenes/MainBakery.unity");
        GameObject canvasRoot = null;
        try
        {
            var view = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren<SettingsScreenPresentation>(true)).Single();
            var content = (RectTransform)typeof(SettingsScreenPresentation).GetField("contentRectTransform", Private).GetValue(view);
            BuildSection(content, "AnalyticsPrivacySettings", typeof(SweetMerge.Analytics.AnalyticsConsentSettingsControl));
            var account = BuildSection(content, "GooglePlayGamesAccountSettings", typeof(SweetMerge.Authentication.GooglePlayGamesAccountSettingsControl));
            SweetMerge.Cloud.SimpleCloudPanel.Attach(account, TMP_Settings.defaultFontAsset);
            PlayerPrivacyUI.AttachSettings(content, null);
            Invoke(view, "ApplyLayout");
            canvasRoot = EditableUIEditor.CopyVisualTree(view.transform, null, view.transform);
            canvasRoot.name = "SettingsArtwork";
            var visual = canvasRoot;
            MakeDesignVisible(visual);
            visual.GetComponentsInChildren<TMP_Text>(true).Single(t => t.name == "GameVersionValue").text = "v" + Application.version;
            visual.GetComponentsInChildren<TMP_Text>(true).Single(t => t.name == "SettingsPersistenceFeedback").text = "Saved";
            PrefabUtility.SaveAsPrefabAsset(canvasRoot, DesignPath);
        }
        finally { if (canvasRoot != null) Object.DestroyImmediate(canvasRoot); EditorSceneManager.ClosePreviewScene(scene); }
    }

    internal static void MakeDesignVisible(GameObject visual)
    {
        var canvas = visual.GetComponent<Canvas>() ?? visual.AddComponent<Canvas>();
        canvas.renderMode = RenderMode.WorldSpace;
        foreach (var part in visual.GetComponentsInChildren<EditableUIVisual>(true))
        {
            if (!part.copyButtonStyle || part.GetComponent<Image>() == null) continue;
            // Show button fills without functional Buttons in the design asset.
            part.GetComponent<Image>().color *= part.buttonColors.normalColor;
            var colors = part.buttonColors;
            colors.normalColor = Color.white; colors.highlightedColor = new Color(.95f, .91f, 1);
            colors.pressedColor = new Color(.8f, .8f, .8f); colors.disabledColor = new Color(1, 1, 1, .45f);
            part.buttonColors = colors;
        }
    }

    public static void ConsolidateSettingsDesign()
    {
        EnsureDesignPrefab();
        // These former section templates are superseded by the complete shared design.
        foreach (string name in new[] { "AccountSettings", "PrivacySettings", "AnalyticsSettings",
            "SettingsAccountV2", "SettingsPrivacyV2", "SettingsAnalyticsV2" })
        {
            string path = EditableUIEditor.DirectoryPath + "/" + name + ".prefab";
            if (AssetDatabase.LoadAssetAtPath<GameObject>(path) != null) AssetDatabase.DeleteAsset(path);
        }
        AssetDatabase.SaveAssets();
        GeneratePreviews();
    }

    private static RectTransform BuildSection(Transform content, string name, Type type)
    {
        var root = new GameObject(name, typeof(RectTransform)); root.transform.SetParent(content, false);
        var component = root.AddComponent(type); Invoke(component, "BuildControls"); return (RectTransform)root.transform;
    }
    private static void Invoke(object target, string method) => target.GetType().GetMethod(method, Private).Invoke(target, null);
}
#endif
