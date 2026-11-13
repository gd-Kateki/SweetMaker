using System;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.UI;

public sealed class BakeryHudTests
{
    private static Type Find(string name) => AppDomain.CurrentDomain.GetAssemblies()
        .Select(a => a.GetType(name)).First(t => t != null);

    [TestCase("MainBakery")]
    [TestCase("Game")]
    public void CustomSceneEnergyPlusSurvivesBindingAndSharedHudStyling(string name)
    {
        var scene = EditorSceneManager.OpenPreviewScene("Assets/_Game/Scenes/" + name + ".unity");
        try
        {
            var type = Find("EnergyHudUI");
            var ui = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren(type, true)).Single();
            var root = (RectTransform)new SerializedObject(ui).FindProperty("hudRoot").objectReferenceValue;
            var plus = (RectTransform)root.Find("EnergyPlus");
            plus.anchoredPosition = new Vector2(-11, 7);
            plus.sizeDelta = new Vector2(62, 38);
            var image = plus.GetComponent<Image>();
            image.sprite = null; image.color = Color.yellow;
            var button = plus.GetComponent<Button>();
            var colors = button.colors; colors.normalColor = Color.cyan; button.colors = colors;
            var artwork = new GameObject("My plus artwork", typeof(RectTransform), typeof(Image));
            artwork.transform.SetParent(plus, false); artwork.GetComponent<Image>().color = Color.green;
            button.targetGraphic = artwork.GetComponent<Image>();
            int children = plus.childCount;
            type.GetMethod("AddEnergyButton", BindingFlags.Instance | BindingFlags.NonPublic).Invoke(ui, null);
            var view = root.GetComponent(Find("EditableUIView"));
            Assert.IsNotNull(view);
            var template = AssetDatabase.LoadAssetAtPath<GameObject>("Assets/_Game/Resources/UI/VisualTemplates/EnergyHUD.prefab");
            view.GetType().GetMethod("ApplyTemplate", BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(view, new object[] { template.transform });
            Assert.AreEqual(new Vector2(-11, 7), plus.anchoredPosition);
            Assert.AreEqual(new Vector2(62, 38), plus.sizeDelta);
            Assert.IsNull(image.sprite);
            Assert.AreEqual(Color.yellow, image.color);
            Assert.AreEqual(Color.cyan, button.colors.normalColor);
            Assert.AreEqual(Color.green, artwork.GetComponent<Image>().color);
            Assert.AreSame(artwork.GetComponent<Image>(), button.targetGraphic);
            Assert.AreEqual(children, plus.childCount);
            Assert.IsTrue(image.raycastTarget, "The custom button must remain clickable.");
        }
        finally { EditorSceneManager.ClosePreviewScene(scene); }
    }

    [TestCase("MainBakery")]
    [TestCase("Game")]
    public void EnergyPlusIsVisibleInSceneAndRuntimeReusesTheAuthoredButton(string name)
    {
        var scene = EditorSceneManager.OpenPreviewScene("Assets/_Game/Scenes/" + name + ".unity");
        try
        {
            var type = Find("EnergyHudUI");
            var ui = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren(type, true)).Single();
            var root = (RectTransform)new SerializedObject(ui).FindProperty("hudRoot").objectReferenceValue;
            var plus = root.Find("EnergyPlus");
            Assert.IsNotNull(plus, "The + must be present before Play Mode.");
            Assert.IsTrue(plus.gameObject.activeInHierarchy);
            Assert.IsNotNull(plus.GetComponent<Button>());
            var rect = (RectTransform)plus;
            Vector2 position = rect.anchoredPosition, size = rect.sizeDelta, pivot = rect.pivot;
            var bind = type.GetMethod("AddEnergyButton", BindingFlags.Instance | BindingFlags.NonPublic);
            bind.Invoke(ui, null); bind.Invoke(ui, null);
            Assert.AreSame(plus, root.Find("EnergyPlus"));
            Assert.AreEqual(1, root.Cast<Transform>().Count(t => t.name == "EnergyPlus"));
            Assert.IsTrue(plus.GetComponent<Image>().raycastTarget);
            Assert.AreEqual(position, rect.anchoredPosition);
            Assert.AreEqual(size, rect.sizeDelta);
            Assert.AreEqual(pivot, rect.pivot);
        }
        finally { EditorSceneManager.ClosePreviewScene(scene); }
    }

    [Test]
    public void BakeryHasOneWorkingEnergyHudWithLocalReferences()
    {
        var scene = EditorSceneManager.OpenPreviewScene("Assets/_Game/Scenes/MainBakery.unity");
        try
        {
            var controller = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren(Find("EnergyHudUI"), true)).Single();
            var data = new SerializedObject(controller);
            var root = (RectTransform)data.FindProperty("hudRoot").objectReferenceValue;
            Assert.IsNotNull(root);
            Assert.AreEqual("TopBar", root.parent.name);
            Assert.IsTrue(root.gameObject.activeInHierarchy);
            Assert.IsNull(root.GetComponentInParent(Find("SceneUiDesign"), true));
            foreach (string field in new[] { "hudBackground", "energyText", "countdownText" })
            {
                var component = (Component)data.FindProperty(field).objectReferenceValue;
                Assert.IsNotNull(component, field);
                Assert.IsTrue(component.transform == root || component.transform.IsChildOf(root), field);
            }
        }
        finally { EditorSceneManager.ClosePreviewScene(scene); }
    }

    [Test]
    public void PrestigeEntryCaptionStaysEmptyWhenButtonStateRefreshes()
    {
        var scene = EditorSceneManager.OpenPreviewScene("Assets/_Game/Scenes/Game.unity");
        try
        {
            Type type = Find("RebirthUI");
            var ui = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren(type, true)).Single();
            var text = new SerializedObject(ui).FindProperty("entryButtonText").objectReferenceValue;
            Assert.IsNotNull(text);
            var property = text.GetType().GetProperty("text");
            Assert.AreEqual(string.Empty, property.GetValue(text));
            property.SetValue(text, "PRESTIGE");
            type.GetMethod("SetEntryButtonState", BindingFlags.Instance | BindingFlags.NonPublic).Invoke(ui, null);
            Assert.AreEqual(string.Empty, property.GetValue(text));
        }
        finally { EditorSceneManager.ClosePreviewScene(scene); }
    }
}
