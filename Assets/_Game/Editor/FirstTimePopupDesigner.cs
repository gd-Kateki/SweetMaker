#if UNITY_EDITOR
using System.IO;
using System.Linq;
using TMPro;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.UI;
using Object = UnityEngine.Object;

internal sealed class FirstTimePopupDesigner : EditorWindow
{
    private const string Folder = "Assets/_Game/Resources/UI/VisualTemplates/";
    private static readonly string[] Keys = { "FeatureIntroduction", "StartupWelcome", "CafeNaming", "CloudProgressChoice", "AdvertisingPrivacy_Unknown", "AdvertisingPrivacy_Teen", "AdvertisingPrivacy_Adult", "AdvertisingPrivacy_Under13" };
    [MenuItem("Tools/Sweet Maker/UI/Edit First-Time Popups")]
    private static void Open() => GetWindow<FirstTimePopupDesigner>("First-time popups").Show();
    private void OnGUI()
    {
        EditorGUILayout.HelpBox("Open a design in Prefab Mode, edit its images, fonts and spacing, then save. Live wording, consent choices, account actions and progress stay controlled by the game.", MessageType.Info);
        foreach (string key in Keys)
            if (GUILayout.Button(ObjectNames.NicifyVariableName(key))) OpenDesign(key);
        var stage = PrefabStageUtility.GetCurrentPrefabStage(); if (stage == null || !Keys.Any(k => stage.assetPath == Folder+k+".prefab")) return;
        EditorGUILayout.Space(); EditorGUILayout.LabelField("View alternate screen", EditorStyles.boldLabel);
        foreach (string name in new[] { "WelcomeScreen", "PrivacyScreen", "NamingInputStep", "NamingConfirmationStep" })
        {
            var screen = stage.prefabContentsRoot.GetComponentsInChildren<Transform>(true).FirstOrDefault(t => t.name == name);
            if (screen == null || !GUILayout.Button("Show " + ObjectNames.NicifyVariableName(name))) continue;
            foreach (Transform sibling in screen.parent) sibling.gameObject.SetActive(sibling == screen);
            for (var current = screen; current != null && current != stage.prefabContentsRoot.transform; current = current.parent) current.gameObject.SetActive(true);
            SceneView.RepaintAll();
        }
    }
    private static void OpenDesign(string key)
    {
        var stage = PrefabStageUtility.OpenPrefab(Folder+key+".prefab");
        foreach (var item in stage.prefabContentsRoot.GetComponentsInChildren<Transform>(true))
        {
            if (item.name == "CafeNamingPopup" || item.name == "NamingInputStep" || item.name == "WelcomeScreen") item.gameObject.SetActive(true);
            if (item.name == "NamingConfirmationStep" || item.name == "PrivacyScreen") item.gameObject.SetActive(false);
        }
        Selection.activeGameObject = stage.prefabContentsRoot;
    }
    public static void ValidateEditablePreviews()
    {
        foreach (string key in Keys)
        {
            OpenDesign(key);
            if (PrefabStageUtility.GetCurrentPrefabStage().prefabContentsRoot.GetComponent<Canvas>() == null)
                throw new System.InvalidOperationException("Missing preview canvas: " + key);
        }
        StageUtility.GoToMainStage();
    }
    public static void ImproveVisuals()
    {
        var surface = AssetDatabase.LoadAssetAtPath<Sprite>("Assets/_Game/Art/UI_Assets/SettingsRemake/SettingsSurface.png");
        foreach (string key in Keys)
        {
            var root = PrefabUtility.LoadPrefabContents(Folder+key+".prefab");
            try
            {
                foreach (var part in root.GetComponentsInChildren<EditableUIVisual>(true))
                {
                    var image = part.GetComponent<Image>();
                    bool backdrop = part.targetPath == "" || part.name == "Background" || part.name == "Shade";
                    if (image != null)
                    {
                        if (part.copyButtonStyle)
                        {
                            image.sprite = surface; image.type = Image.Type.Sliced; image.color = new Color(.43f,.22f,.62f);
                            var colors = part.buttonColors; colors.normalColor = Color.white; colors.highlightedColor = new Color(.94f,.90f,1);
                            colors.pressedColor = new Color(.8f,.8f,.8f); colors.disabledColor = new Color(1,1,1,.45f); part.buttonColors = colors;
                        }
                        else if (backdrop) image.color = new Color(.10f,.06f,.16f,.88f);
                        else { image.sprite = surface; image.type = Image.Type.Sliced; image.color = new Color(.97f,.94f,.99f); }
                    }
                    var text = part.GetComponent<TMP_Text>(); if (text == null) continue;
                    bool buttonLabel = part.targetPath.Contains("Button") && part.name == "Label" || part.transform.parent.GetComponent<EditableUIVisual>()?.copyButtonStyle == true;
                    bool title = part.name == "Title";
                    text.color = buttonLabel ? Color.white : new Color(.22f,.16f,.29f);
                    text.isOrthographic = true; text.fontSizeMin = title ? 28 : 22; text.fontSizeMax = title ? 40 : 28;
                    text.fontSize = text.fontSizeMax; text.enableAutoSizing = true;
                    if (title || buttonLabel) text.fontStyle = FontStyles.Bold;
                }
                if (key == "FeatureIntroduction")
                {
                    var panel = root.GetComponentsInChildren<Transform>(true).Single(t => t.name == "FeatureIntroductionCard");
                    var layout = panel.GetComponent<VerticalLayoutGroup>(); layout.padding = new RectOffset(32,32,32,32); layout.spacing = 24; layout.childForceExpandHeight = false;
                    var cardRect = (RectTransform)panel; cardRect.anchorMin = new Vector2(.1f,.25f); cardRect.anchorMax = new Vector2(.9f,.75f); cardRect.offsetMin = cardRect.offsetMax = Vector2.zero;
                    var title = panel.Find("Title").GetComponent<TMP_Text>(); title.text = "Grow your café";
                    var body = panel.Find("Body").GetComponent<TMP_Text>(); body.text = "Invest your earnings in upgrades to make room for more desserts and serve more customers.\n\nEach improvement helps your café grow.";
                    body.alignment = TextAlignmentOptions.TopLeft;
                    panel.Find("Title").GetComponent<LayoutElement>().preferredHeight = 100;
                    var button = panel.Find("GotItButton"); button.GetComponent<LayoutElement>().preferredHeight = 80;
                }
                if (key.StartsWith("AdvertisingPrivacy_"))
                {
                    var content = root.GetComponentsInChildren<Transform>(true).Single(t => t.name == "Privacy content");
                    if (content.Find("PopupSurface") == null)
                    {
                        var background = new GameObject("PopupSurface",typeof(RectTransform),typeof(Image)); background.transform.SetParent(content,false);
                        var bounds = (RectTransform)background.transform; bounds.anchorMin = Vector2.zero; bounds.anchorMax = Vector2.one; bounds.offsetMin = bounds.offsetMax = Vector2.zero;
                        var image = background.GetComponent<Image>(); image.sprite = surface; image.type = Image.Type.Sliced; image.color = new Color(.97f,.94f,.99f); image.raycastTarget = false;
                        background.transform.SetAsFirstSibling();
                    }
                }
                var canvas = root.GetComponent<Canvas>(); if (canvas == null) canvas = root.AddComponent<Canvas>(); canvas.renderMode = RenderMode.WorldSpace;
                var rect = (RectTransform)root.transform; rect.anchorMin = rect.anchorMax = new Vector2(.5f,.5f); rect.anchoredPosition = Vector2.zero; rect.sizeDelta = new Vector2(720,1280);
                PrefabUtility.SaveAsPrefabAsset(root,Folder+key+".prefab");
            }
            finally { PrefabUtility.UnloadPrefabContents(root); }
        }
        RenderPreview();
    }
    public static void RenderPreview()
    {
        var pipeline = GraphicsSettings.defaultRenderPipeline; var quality = QualitySettings.renderPipeline; var previous = RenderTexture.active;
        try
        {
            GraphicsSettings.defaultRenderPipeline = null; QualitySettings.renderPipeline = null;
            foreach (string key in new[] { "FeatureIntroduction", "StartupWelcome" })
            {
                var root = Object.Instantiate(AssetDatabase.LoadAssetAtPath<GameObject>(Folder+key+".prefab"));
                var cameraObject = new GameObject("Popup preview camera",typeof(Camera)); var camera = cameraObject.GetComponent<Camera>();
                var target = new RenderTexture(720,1280,24); target.Create();
                try
                {
                    root.SetActive(true); root.transform.position = Vector3.zero;
                    if (key == "StartupWelcome") foreach (var t in root.GetComponentsInChildren<Transform>(true)) { if(t.name=="PrivacyScreen")t.gameObject.SetActive(false); if(t.name=="WelcomeScreen")t.gameObject.SetActive(true); }
                    foreach(var t in root.GetComponentsInChildren<Transform>(true))t.gameObject.layer=31;
                    camera.transform.position = new Vector3(0,0,-10); camera.orthographic=true; camera.orthographicSize=640; camera.cullingMask=1<<31;
                    camera.clearFlags=CameraClearFlags.SolidColor; camera.backgroundColor=new Color(.16f,.10f,.23f); camera.targetTexture=target;
                    root.GetComponent<Canvas>().worldCamera=camera; Canvas.ForceUpdateCanvases();
                    foreach(var text in root.GetComponentsInChildren<TMP_Text>(true))text.ForceMeshUpdate(true,true);
                    camera.Render(); RenderTexture.active=target; var png=new Texture2D(720,1280,TextureFormat.RGBA32,false);
                    try { png.ReadPixels(new Rect(0,0,720,1280),0,0); png.Apply(); Directory.CreateDirectory("tmp"); File.WriteAllBytes("tmp/"+key+"-updated.png",png.EncodeToPNG()); }
                    finally { Object.DestroyImmediate(png); }
                }
                finally { RenderTexture.active=previous; target.Release(); Object.DestroyImmediate(target); Object.DestroyImmediate(cameraObject); Object.DestroyImmediate(root); }
            }
        }
        finally { GraphicsSettings.defaultRenderPipeline=pipeline; QualitySettings.renderPipeline=quality; RenderTexture.active=previous; }
    }
}
#endif
