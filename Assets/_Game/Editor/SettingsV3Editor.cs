#if UNITY_EDITOR
using System.Linq;
using System.Reflection;
using TMPro;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.UI;

internal static class SettingsV3Editor
{
    internal const string Art = "Assets/_Game/Art/UI_Assets/UI V3/Settings_Screen/";
    private const BindingFlags Private = BindingFlags.NonPublic | BindingFlags.Instance;
    private static readonly Color Ink = new Color(.24f,.14f,.13f);
    private static Sprite Sprite(string name) => AssetDatabase.LoadAllAssetsAtPath(Art + name + ".png").OfType<Sprite>().First();
    private static void ImageStyle(Image image, string name, bool sliced = true)
    {
        image.sprite = Sprite(name); image.color = Color.white;
        image.type = sliced ? Image.Type.Sliced : Image.Type.Simple;
        image.preserveAspect = !sliced;
    }

    public static void Apply()
    {
        var root = PrefabUtility.LoadPrefabContents(SettingsLayoutEditor.DesignPath);
        try
        {
            foreach (var part in root.GetComponentsInChildren<EditableUIVisual>(true))
            {
                var image = part.GetComponent<Image>();
                if (image != null)
                {
                    if (string.IsNullOrEmpty(part.targetPath)) ImageStyle(image, "Settings_Backplate");
                    else if (part.name == "SettingsCloseButton") ImageStyle(image, "Settings_Cancel_Button", false);
                    else if (part.name.StartsWith("SettingsCard")) ImageStyle(image, "Settings_Plate_" + part.name.Last());
                    else if (part.name.EndsWith("Card")) ImageStyle(image, "Settings_Plate_1");
                    else if (part.targetPath.Contains("Toggle") && part.name.EndsWith("Knob")) ImageStyle(image, "Settings_On_Ellipse", false);
                    else if (part.name.EndsWith("Toggle")) ImageStyle(image, "Settings_On_Bar");
                    else if (part.targetPath.Contains("SfxVolumeSlider"))
                    {
                        ImageStyle(image, part.name == "Handle" ? "Settings_Slider_Bar_Ellipse" : "Settings_Slider_Bar", part.name != "Handle");
                        if (part.name == "SfxVolumeSlider") image.color = new Color(.65f,.55f,.72f);
                    }
                    else if (part.copyButtonStyle) ImageStyle(image, "Settings_Title");
                    if (part.copyButtonStyle)
                    {
                        var colors = part.buttonColors; colors.normalColor = Color.white;
                        colors.highlightedColor = Color.white; colors.pressedColor = new Color(.86f,.82f,.90f);
                        colors.disabledColor = new Color(.65f,.62f,.67f); part.buttonColors = colors;
                    }
                }
                var text = part.GetComponent<TMP_Text>();
                if (text != null)
                {
                    if (part.GetComponentsInParent<EditableUIVisual>(true).Any(p => p.copyButtonStyle))
                        text.enableVertexGradient = false;
                    text.color = text.enableVertexGradient ? Color.white : Ink;
                    if (part.name == "SettingsCloseLabel") text.text = string.Empty;
                }
            }
            var title = root.GetComponentsInChildren<TMP_Text>(true).Single(t => t.name == "SettingsTitle");
            var rect = title.rectTransform;
            rect.anchorMin = rect.anchorMax = new Vector2(0,1); rect.pivot = new Vector2(0,1);
            rect.anchoredPosition = new Vector2(42,-30); rect.sizeDelta = new Vector2(320,72);
            title.alignment = TextAlignmentOptions.Center;
            var plaque = root.transform.Find("V3SettingsTitlePlate");
            if (plaque == null)
            {
                plaque = new GameObject("V3SettingsTitlePlate", typeof(RectTransform), typeof(Image)).transform;
                plaque.SetParent(root.transform, false);
            }
            plaque.SetAsFirstSibling();
            var plateRect = (RectTransform)plaque;
            plateRect.anchorMin = plateRect.anchorMax = new Vector2(0,1); plateRect.pivot = new Vector2(0,1);
            plateRect.anchoredPosition = new Vector2(24,-20); plateRect.sizeDelta = new Vector2(360,110);
            ImageStyle(plaque.GetComponent<Image>(), "Settings_Title"); plaque.GetComponent<Image>().raycastTarget = false;
            var binding = plaque.GetComponent<EditableUIVisual>(); if (binding == null) binding = plaque.gameObject.AddComponent<EditableUIVisual>();
            binding.targetPath = "V3SettingsTitlePlate:0";
            PrefabUtility.SaveAsPrefabAsset(root, SettingsLayoutEditor.DesignPath);
        }
        finally { PrefabUtility.UnloadPrefabContents(root); }
        foreach (string name in new[] { "MainBakery", "Game" })
        {
            var scene = EditorSceneManager.OpenScene("Assets/_Game/Scenes/" + name + ".unity");
            var presentation = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren<SettingsScreenPresentation>(true)).Single();
            var data = new SerializedObject(presentation);
            data.FindProperty("panelSprite").objectReferenceValue = Sprite("Settings_Backplate");
            data.FindProperty("toggleTrackSprite").objectReferenceValue = Sprite("Settings_On_Bar");
            data.FindProperty("toggleKnobSprite").objectReferenceValue = Sprite("Settings_On_Ellipse");
            data.FindProperty("titlePlateSprite").objectReferenceValue = Sprite("Settings_Title");
            data.FindProperty("closeArtworkContainsIcon").boolValue = true;
            data.FindProperty("panelColor").colorValue = Color.white;
            data.FindProperty("cardColor").colorValue = Color.white;
            data.FindProperty("textColor").colorValue = Ink;
            data.ApplyModifiedPropertiesWithoutUndo();
            typeof(SettingsScreenPresentation).GetMethod("ApplyLayout", Private).Invoke(presentation, null);
            EditableUIView.Attach(presentation.gameObject, "SettingsArtwork");
            var owner = presentation.GetComponent<EditableUIView>(); owner.IncludeNestedViews();
            typeof(EditableUIView).GetMethod("ApplyTemplate", Private).Invoke(owner, new object[] { AssetDatabase.LoadAssetAtPath<GameObject>(SettingsLayoutEditor.DesignPath).transform });
            EditorSceneManager.MarkSceneDirty(scene); EditorSceneManager.SaveScene(scene);
        }
        SettingsLayoutEditor.RenderPreviews();
        Debug.Log("SETTINGS V3 | Updated shared artwork, both scenes, toggle states and slider visuals.");
    }
}
#endif
