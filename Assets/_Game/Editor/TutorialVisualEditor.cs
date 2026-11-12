#if UNITY_EDITOR
using System.IO;
using TMPro;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.UI;
using Object = UnityEngine.Object;

internal static class TutorialVisualEditor
{
    private const string Folder = "Assets/_Game/Resources/UI/VisualTemplates/";
    [MenuItem("Tools/Sweet Maker/UI/Edit Tutorial Welcome")]
    private static void EditWelcome() => PrefabStageUtility.OpenPrefab(Folder + "TutorialWelcome.prefab");
    [MenuItem("Tools/Sweet Maker/UI/Edit Tutorial Instructions")]
    private static void EditInstructions() => PrefabStageUtility.OpenPrefab(Folder + "TutorialInstruction.prefab");
    [MenuItem("Tools/Sweet Maker/UI/Edit Tutorial Recovery")]
    private static void EditRecovery() => PrefabStageUtility.OpenPrefab(Folder + "TutorialRecovery.prefab");

    public static void ImproveVisuals()
    {
        var surface = AssetDatabase.LoadAssetAtPath<Sprite>("Assets/_Game/Art/UI_Assets/SettingsRemake/SettingsSurface.png");
        foreach (string key in new[] { "TutorialWelcome", "TutorialInstruction", "TutorialRecovery" })
        {
            var root = PrefabUtility.LoadPrefabContents(Folder + key + ".prefab");
            try
            {
                var background = root.GetComponent<Image>(); background.sprite = surface; background.type = Image.Type.Sliced;
                background.color = new Color(.97f,.94f,.99f); background.raycastTarget = key == "TutorialWelcome";
                foreach (var text in root.GetComponentsInChildren<TMP_Text>(true))
                {
                    text.color = new Color(.22f,.16f,.29f); text.isOrthographic = true; text.raycastTarget = false;
                    text.fontSizeMin = key == "TutorialRecovery" ? 20 : 24;
                    text.fontSizeMax = key == "TutorialInstruction" ? 30 : 28;
                    text.fontSize = text.fontSizeMax; text.enableAutoSizing = true;
                    text.overflowMode = TextOverflowModes.Truncate;
                }
                foreach (var part in root.GetComponentsInChildren<EditableUIVisual>(true))
                {
                    if (!part.copyButtonStyle) continue;
                    var image = part.GetComponent<Image>(); image.sprite = surface; image.type = Image.Type.Sliced;
                    image.color = new Color(.43f,.22f,.62f);
                    var colors = part.buttonColors; colors.normalColor = Color.white; colors.highlightedColor = new Color(.94f,.90f,1);
                    colors.pressedColor = new Color(.8f,.8f,.8f); colors.disabledColor = new Color(1,1,1,.45f); part.buttonColors = colors;
                    var label = part.GetComponentInChildren<TMP_Text>(true); label.color = Color.white; label.fontStyle = FontStyles.Bold;
                }
                if (key == "TutorialWelcome")
                {
                    var title = root.transform.Find("Title").GetComponent<TMP_Text>(); title.fontSizeMin = 30; title.fontSizeMax = title.fontSize = 38;
                    title.fontStyle = FontStyles.Bold;
                    Position(title.rectTransform,.07f,.80f,.93f,.96f);
                    Position((RectTransform)root.transform.Find("Body"),.08f,.63f,.92f,.79f);
                    Position((RectTransform)root.transform.Find("ContinueButton"),.10f,.06f,.90f,.19f);
                }
                else if (key == "TutorialInstruction")
                {
                    Position((RectTransform)root.transform.Find("InstructionText"),.06f,.10f,.94f,.68f);
                    var heading = new GameObject("TipHeading",typeof(RectTransform),typeof(TextMeshProUGUI)); heading.transform.SetParent(root.transform,false);
                    var text = heading.GetComponent<TMP_Text>(); text.text = "QUICK TIP"; text.fontSize = 18; text.fontStyle = FontStyles.Bold;
                    text.font = root.GetComponentInChildren<TMP_Text>().font; text.color = new Color(.43f,.22f,.62f); text.raycastTarget = false;
                    Position(text.rectTransform,.06f,.73f,.94f,.94f);
                }
                else
                {
                    Position((RectTransform)root.transform.Find("RecoveryText"),.06f,.39f,.94f,.94f);
                    Position((RectTransform)root.transform.Find("RetryButton"),.18f,.07f,.82f,.32f);
                }
                // The design canvas makes each complete panel visible in Prefab Mode.
                var canvas = root.GetComponent<Canvas>(); if (canvas == null) canvas = root.AddComponent<Canvas>(); canvas.renderMode = RenderMode.WorldSpace;
                var rect = (RectTransform)root.transform; rect.anchorMin = rect.anchorMax = new Vector2(.5f,.5f);
                rect.anchoredPosition = Vector2.zero; rect.sizeDelta = key == "TutorialWelcome" ? new Vector2(634,870) : key == "TutorialInstruction" ? new Vector2(605,179) : new Vector2(634,218);
                PrefabUtility.SaveAsPrefabAsset(root,Folder+key+".prefab");
            }
            finally { PrefabUtility.UnloadPrefabContents(root); }
        }
        RenderPreviews();
    }
    private static void Position(RectTransform rect,float x,float y,float right,float top)
    { rect.anchorMin = new Vector2(x,y); rect.anchorMax = new Vector2(right,top); rect.offsetMin = rect.offsetMax = Vector2.zero; }

    public static void RenderPreviews()
    {
        var pipeline = GraphicsSettings.defaultRenderPipeline; var quality = QualitySettings.renderPipeline; var previous = RenderTexture.active;
        try
        {
            GraphicsSettings.defaultRenderPipeline = null; QualitySettings.renderPipeline = null;
            foreach (string key in new[] { "TutorialWelcome", "TutorialInstruction", "TutorialRecovery" })
            {
                var root = Object.Instantiate(AssetDatabase.LoadAssetAtPath<GameObject>(Folder+key+".prefab"));
                var cameraObject = new GameObject("Tutorial preview camera",typeof(Camera)); var camera = cameraObject.GetComponent<Camera>();
                var target = new RenderTexture(720,1280,24); target.Create();
                try
                {
                    root.SetActive(true); root.transform.position = Vector3.zero; foreach(var t in root.GetComponentsInChildren<Transform>(true))t.gameObject.layer = 31;
                    if (key == "TutorialRecovery") root.transform.Find("RecoveryText").GetComponent<TMP_Text>().text = "Your progress could not be saved. Check your connection, then try again.";
                    camera.transform.position = new Vector3(0,0,-10); camera.orthographic = true; camera.orthographicSize = 640; camera.cullingMask = 1 << 31;
                    camera.clearFlags = CameraClearFlags.SolidColor; camera.backgroundColor = new Color(.16f,.10f,.23f); camera.targetTexture = target;
                    root.GetComponent<Canvas>().worldCamera = camera; Canvas.ForceUpdateCanvases();
                    foreach(var text in root.GetComponentsInChildren<TMP_Text>(true))text.ForceMeshUpdate(true,true);
                    camera.Render(); RenderTexture.active = target; var png = new Texture2D(720,1280,TextureFormat.RGBA32,false);
                    try { png.ReadPixels(new Rect(0,0,720,1280),0,0); png.Apply(); Directory.CreateDirectory("tmp"); File.WriteAllBytes("tmp/"+key+".png",png.EncodeToPNG()); }
                    finally { Object.DestroyImmediate(png); }
                }
                finally { RenderTexture.active = previous; target.Release(); Object.DestroyImmediate(target); Object.DestroyImmediate(cameraObject); Object.DestroyImmediate(root); }
            }
        }
        finally { GraphicsSettings.defaultRenderPipeline = pipeline; QualitySettings.renderPipeline = quality; RenderTexture.active = previous; }
    }
}
#endif
