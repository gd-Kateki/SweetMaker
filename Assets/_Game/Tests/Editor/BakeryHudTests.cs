using System;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;

public sealed class BakeryHudTests
{
    private static Type Find(string name) => AppDomain.CurrentDomain.GetAssemblies()
        .Select(a => a.GetType(name)).First(t => t != null);

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
