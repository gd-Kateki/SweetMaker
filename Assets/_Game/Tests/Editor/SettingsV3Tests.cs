using System;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.UI;

public sealed class SettingsV3Tests
{
    private const string Art = "Assets/_Game/Art/UI_Assets/UI V3/Settings_Screen/";
    private const BindingFlags Private = BindingFlags.Instance | BindingFlags.NonPublic;
    private static Type Find(string name) => AppDomain.CurrentDomain.GetAssemblies().Select(a => a.GetType(name)).First(t => t != null);

    [Test]
    public void SharedSettingsUsesEveryV3ElementAndPreservesSliceBorders()
    {
        var design = AssetDatabase.LoadAssetAtPath<GameObject>("Assets/_Game/Resources/UI/VisualTemplates/SettingsArtwork.prefab");
        var images = design.GetComponentsInChildren<Image>(true);
        foreach (var name in new[] { "Settings_Backplate", "Settings_Title", "Settings_Cancel_Button", "Settings_Plate_1", "Settings_Plate_2", "Settings_Plate_3", "Settings_Plate_4", "Settings_On_Bar", "Settings_On_Ellipse", "Settings_Slider_Bar", "Settings_Slider_Bar_Ellipse" })
            Assert.IsTrue(images.Any(i => AssetDatabase.GetAssetPath(i.sprite) == Art + name + ".png"), name);
        foreach (var image in images.Where(i => i.type == Image.Type.Sliced && AssetDatabase.GetAssetPath(i.sprite).StartsWith(Art)))
            Assert.Greater(image.sprite.border.sqrMagnitude, 0, image.name);
        Assert.IsEmpty(design.GetComponentsInChildren<Button>(true), "Artwork must not replace the wired controls.");
        var textType = Find("TMPro.TMP_Text"); var markerType = Find("EditableUIVisual");
        foreach (var label in design.GetComponentsInChildren(textType, true))
        {
            bool buttonLabel = label.GetComponentsInParent(markerType, true).Any(p => (bool)markerType.GetField("copyButtonStyle").GetValue(p));
            if (!buttonLabel || label.name == "SettingsCloseLabel") continue;
            Assert.IsFalse((bool)textType.GetProperty("enableVertexGradient").GetValue(label), label.name);
            Assert.Less(((Color)textType.GetProperty("color").GetValue(label)).grayscale, .4f, label.name + " needs dark text on yellow artwork.");
        }
    }

    [TestCase("MainBakery")]
    [TestCase("Game")]
    public void ToggleStateChangesKeepV3SpritesAndMoveTheirKnobs(string sceneName)
    {
        var scene = EditorSceneManager.OpenPreviewScene("Assets/_Game/Scenes/" + sceneName + ".unity");
        try
        {
            var type = Find("SettingsScreenPresentation");
            var owner = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren(type, true)).Single();
            type.GetMethod("ApplyLayout", Private).Invoke(owner, null);
            var visuals = owner.GetComponentsInChildren(Find("SettingsToggleVisual"), true);
            Assert.IsNotEmpty(visuals);
            foreach (var visual in visuals)
            {
                var data = new SerializedObject(visual);
                var toggle = (Toggle)data.FindProperty("toggle").objectReferenceValue;
                var track = (Image)data.FindProperty("trackImage").objectReferenceValue;
                var knob = (RectTransform)data.FindProperty("knobRectTransform").objectReferenceValue;
                var knobImage = (Image)data.FindProperty("knobImage").objectReferenceValue;
                toggle.SetIsOnWithoutNotify(false); visual.GetType().GetMethod("RefreshVisual").Invoke(visual, null);
                var off = knob.anchoredPosition;
                toggle.SetIsOnWithoutNotify(true); visual.GetType().GetMethod("RefreshVisual").Invoke(visual, null);
                Assert.AreNotEqual(off, knob.anchoredPosition);
                Assert.AreEqual(Art + "Settings_On_Bar.png", AssetDatabase.GetAssetPath(track.sprite));
                Assert.AreEqual(Art + "Settings_On_Ellipse.png", AssetDatabase.GetAssetPath(knobImage.sprite));
                Assert.AreEqual(Color.white, track.color);
            }
        }
        finally { EditorSceneManager.ClosePreviewScene(scene); }
    }
}
