#if UNITY_EDITOR
using System.IO;
using System.Reflection;
using UnityEditor;
using UnityEngine;
using UnityEngine.Rendering;
using TMPro;

internal static class DeveloperTestingEditor
{
    public static void RenderPreviews()
    {
        if (EditorApplication.isPlayingOrWillChangePlaymode) throw new System.InvalidOperationException("Stop Play Mode first.");
        var originalPipeline = GraphicsSettings.defaultRenderPipeline;
        var originalQualityPipeline = QualitySettings.renderPipeline;
        var staging = new GameObject("Test Lab preview staging"); staging.SetActive(false);
        GameObject canvas = null, cameraRoot = null;
        RenderTexture target = null;
        var previousTarget = RenderTexture.active;
        try
        {
            GraphicsSettings.defaultRenderPipeline = null; QualitySettings.renderPipeline = null;
            var parent = new GameObject("Preview parent", typeof(RectTransform), typeof(Canvas)); parent.transform.SetParent(staging.transform);
            var panel = staging.AddComponent<DeveloperCheatPanel>();
            const BindingFlags flags = BindingFlags.Instance | BindingFlags.NonPublic;
            var type = typeof(DeveloperCheatPanel);
            type.GetMethod("BuildUi", flags).Invoke(panel, new object[] { parent.transform });
            canvas = (GameObject)type.GetField("testingCanvasRoot", flags).GetValue(panel);
            canvas.GetComponent<UnityEngine.UI.CanvasScaler>().enabled = false;
            var worldCanvas = canvas.GetComponent<Canvas>(); worldCanvas.renderMode = RenderMode.WorldSpace;
            var rect = canvas.GetComponent<RectTransform>(); rect.sizeDelta = new Vector2(720, 1280); rect.position = Vector3.zero; rect.localScale = Vector3.one;
            foreach (Transform item in canvas.GetComponentsInChildren<Transform>(true)) item.gameObject.layer = 31;
            ((GameObject)type.GetField("overlayObject", flags).GetValue(panel)).SetActive(true);
            ((GameObject)type.GetField("devButtonObject", flags).GetValue(panel)).SetActive(false);
            type.GetMethod("RefreshSelectionLabels", flags).Invoke(panel, null);
            ((TMP_Text)type.GetField("summaryText", flags).GetValue(panel)).text = "$12,500   •   Energy 50/100   •   R2";
            ((TMP_Text)type.GetField("lifetimeStatisticsText", flags).GetValue(panel)).text = "Total Orders Completed: 42\nTotal Money Earned: $18,500";
            cameraRoot = new GameObject("Preview camera", typeof(Camera));
            var camera = cameraRoot.GetComponent<Camera>(); camera.transform.position = new Vector3(0, 0, -10);
            camera.orthographic = true; camera.orthographicSize = 640; camera.cullingMask = 1 << 31;
            camera.clearFlags = CameraClearFlags.SolidColor; camera.backgroundColor = new Color(0.025f, 0.04f, 0.07f);
            worldCanvas.worldCamera = camera;
            target = new RenderTexture(720, 1280, 24); target.Create(); camera.targetTexture = target;
            Directory.CreateDirectory("tmp");
            foreach (int page in new[] { 0, 3 })
            {
                type.GetMethod("SelectTab", flags).Invoke(panel, new object[] { page });
                ((TMP_Text)type.GetField("diagnosticsText", flags).GetValue(panel)).text = "Controls: READY\nCash: $12,500\nEnergy: 50/100\nRebirth: R2\nBoard: 12/30 occupied\nSave mode: RELEASE\nCloud: Cloud backup saved.\nAds: Ad ready.";
                Canvas.ForceUpdateCanvases();
                UnityEngine.UI.LayoutRebuilder.ForceRebuildLayoutImmediate(rect);
                foreach (var button in canvas.GetComponentsInChildren<UnityEngine.UI.Button>(true))
                    if (button.targetGraphic != null) button.targetGraphic.canvasRenderer.SetColor(button.interactable ? button.colors.normalColor : button.colors.disabledColor);
                camera.Render(); RenderTexture.active = target;
                var image = new Texture2D(720, 1280, TextureFormat.RGBA32, false);
                try { image.ReadPixels(new Rect(0, 0, 720, 1280), 0, 0); image.Apply(); File.WriteAllBytes("tmp/test-lab-" + (page == 0 ? "economy" : "services") + ".png", image.EncodeToPNG()); }
                finally { Object.DestroyImmediate(image); }
            }
        }
        finally
        {
            RenderTexture.active = previousTarget;
            if (cameraRoot != null) Object.DestroyImmediate(cameraRoot);
            if (target != null) { target.Release(); Object.DestroyImmediate(target); }
            if (canvas != null) Object.DestroyImmediate(canvas);
            Object.DestroyImmediate(staging);
            GraphicsSettings.defaultRenderPipeline = originalPipeline; QualitySettings.renderPipeline = originalQualityPipeline;
        }
    }
    [MenuItem("Tools/Sweet Maker/Testing/Enable Production Cheat Panel")]
    public static void EnableProductionTesting() => Configure(true);
    [MenuItem("Tools/Sweet Maker/Testing/Disable Production Cheat Panel")]
    public static void DisableProductionTesting() => Configure(false);

    private static void Configure(bool enabled)
    {
        const string path = "Assets/_Game/Resources/DeveloperTestingSettings.asset";
        var settings = AssetDatabase.LoadAssetAtPath<DeveloperTestingSettings>(path);
        if (settings == null) { settings = ScriptableObject.CreateInstance<DeveloperTestingSettings>(); AssetDatabase.CreateAsset(settings, path); }
        settings.enableProductionCheatPanel = enabled; EditorUtility.SetDirty(settings); AssetDatabase.SaveAssets();
        Debug.Log("Production cheat panel " + (enabled ? "ENABLED for testing." : "DISABLED."));
    }

    [MenuItem("Tools/Sweet Maker/Testing/Create Test Lab Visual Templates")]
    public static void CreateVisualTemplates() => SaveVisualTemplates(false);
    // Explicit batch helper for refreshing newly generated defaults during implementation.
    public static void RebuildGeneratedVisualTemplates() => SaveVisualTemplates(true);
    private static void SaveVisualTemplates(bool overwrite)
    {
        if (EditorApplication.isPlayingOrWillChangePlaymode) throw new System.InvalidOperationException("Stop Play Mode before generating preview templates.");
        var staging = new GameObject("Test Lab visual preview"); staging.SetActive(false);
        GameObject canvas = null;
        try
        {
            var panel = staging.AddComponent<DeveloperCheatPanel>();
            const BindingFlags flags = BindingFlags.Instance | BindingFlags.NonPublic;
            var previewParent = new GameObject("Preview canvas", typeof(RectTransform), typeof(Canvas)); previewParent.transform.SetParent(staging.transform);
            typeof(DeveloperCheatPanel).GetMethod("BuildUi", flags).Invoke(panel, new object[] { previewParent.transform });
            canvas = (GameObject)typeof(DeveloperCheatPanel).GetField("testingCanvasRoot", flags).GetValue(panel);
            Directory.CreateDirectory(EditableUIEditor.DirectoryPath);
            foreach (var view in canvas.GetComponentsInChildren<EditableUIView>(true))
            {
                string path = EditableUIEditor.DirectoryPath + "/" + view.TemplateKey + ".prefab";
                if (File.Exists(path) && !overwrite) continue;
                var clone = EditableUIEditor.CopyVisualTree(view.transform, null, view.transform);
                try { PrefabUtility.SaveAsPrefabAsset(clone, path); }
                finally { Object.DestroyImmediate(clone); }
            }
            AssetDatabase.SaveAssets();
        }
        finally { if (canvas != null) Object.DestroyImmediate(canvas); Object.DestroyImmediate(staging); }
    }
}
#endif
