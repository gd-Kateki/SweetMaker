using System;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEngine;
using UnityEngine.UI;
using UnityEditor.SceneManagement;

public sealed class SpawnPoolCanvasTests
{
    private static Type Selector => AppDomain.CurrentDomain.GetAssemblies()
        .Select(a => a.GetType("SpawnPoolSelectorUI")).First(t => t != null);

    [Test]
    public void AuthoredGameSelectorAndPanelBelongToTheResolvedCanvas()
    {
        var scene = EditorSceneManager.OpenPreviewScene("Assets/_Game/Scenes/Game.unity");
        try
        {
            var component = scene.GetRootGameObjects().SelectMany(root => root.GetComponentsInChildren(Selector, true)).Single();
            const BindingFlags fields = BindingFlags.NonPublic | BindingFlags.Instance;
            var button = (Button)Selector.GetField("selectorButtonReference", fields).GetValue(component);
            var panel = (RectTransform)Selector.GetField("selectionPanelRect", fields).GetValue(component);
            var canvas = (Canvas)Selector.GetMethod("ResolveGameplayCanvas", BindingFlags.Static | BindingFlags.NonPublic)
                .Invoke(null, new object[] { button });
            Assert.IsNotNull(canvas);
            Assert.AreEqual("GameplayCanvas", canvas.name);
            Assert.AreSame(canvas.transform, button.transform.parent);
            Assert.AreSame(canvas.transform, panel.parent);
            Assert.AreEqual(RenderMode.ScreenSpaceOverlay, canvas.renderMode);
        }
        finally { EditorSceneManager.ClosePreviewScene(scene); }
    }

    [TestCase(false)]
    [TestCase(true)]
    public void SelectorUsesItsOwnCanvasDespiteOtherOverlayCanvases(bool inactive)
    {
        var testing = new GameObject("TestingCanvas", typeof(RectTransform), typeof(Canvas));
        var leaderboard = new GameObject("Leaderboards", typeof(RectTransform), typeof(Canvas));
        var gameplay = new GameObject("GameplayCanvas", typeof(RectTransform), typeof(Canvas));
        try
        {
            var button = new GameObject("OvenTierSelectorButton", typeof(RectTransform), typeof(Button));
            button.transform.SetParent(gameplay.transform, false);
            gameplay.SetActive(!inactive);
            var result = Selector.GetMethod("ResolveGameplayCanvas", BindingFlags.Static | BindingFlags.NonPublic)
                .Invoke(null, new object[] { button.GetComponent<Button>() });
            Assert.AreSame(gameplay.GetComponent<Canvas>(), result);
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(testing); UnityEngine.Object.DestroyImmediate(leaderboard);
            UnityEngine.Object.DestroyImmediate(gameplay);
        }
    }

    [Test]
    public void MissingSelectorDoesNotFallBackToAnUnrelatedCanvas()
    {
        var testing = new GameObject("TestingCanvas", typeof(Canvas));
        try
        {
            Assert.IsNull(Selector.GetMethod("ResolveGameplayCanvas", BindingFlags.Static | BindingFlags.NonPublic)
                .Invoke(null, new object[] { null }));
        }
        finally { UnityEngine.Object.DestroyImmediate(testing); }
    }
}
