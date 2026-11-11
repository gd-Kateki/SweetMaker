using System;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEngine;
using UnityEngine.UI;

public sealed class DeveloperTestingTests
{
    private static Type Find(string name) => AppDomain.CurrentDomain.GetAssemblies().Select(a => a.GetType(name)).First(t => t != null);
    private const BindingFlags Instance = BindingFlags.Instance | BindingFlags.NonPublic;

    [TestCase(true, false, false, false, true)]
    [TestCase(false, true, true, false, true)]
    [TestCase(false, true, false, false, false)]
    [TestCase(false, true, false, true, true)]
    [TestCase(false, false, false, true, false)]
    public void ProductionTestingRequiresAnExplicitFlag(bool editor, bool android, bool development, bool flag, bool expected)
    {
        Assert.AreEqual(expected, Find("DeveloperCheatAccess").GetMethod("IsAllowed", BindingFlags.NonPublic | BindingFlags.Static)
            .Invoke(null, new object[] { editor, android, development, flag }));
    }

    [TestCase(320, 694)]
    [TestCase(480, 1040)]
    [TestCase(720, 1280)]
    public void TestLabCategoriesAndFeedbackStayWithinCardAndSwitchWithoutChangingGameState(float width, float height)
    {
        var owner = new GameObject("Test lab test"); owner.SetActive(false);
        var parent = new GameObject("Existing gameplay canvas", typeof(RectTransform), typeof(Canvas));
        GameObject canvas = null;
        try
        {
            Type type = Find("DeveloperCheatPanel"); var panel = owner.AddComponent(type);
            type.GetMethod("BuildUi", Instance).Invoke(panel, new object[] { parent.transform });
            canvas = (GameObject)type.GetField("testingCanvasRoot", Instance).GetValue(panel);
            canvas.GetComponent<Canvas>().renderMode = RenderMode.WorldSpace;
            canvas.GetComponent<CanvasScaler>().enabled = false;
            var rect = canvas.GetComponent<RectTransform>(); rect.sizeDelta = new Vector2(width, height);
            var card = canvas.transform.Find("SafeArea/Developer Cheat Overlay/Testing workspace") as RectTransform;
            Assert.IsNotNull(card);
            Canvas.ForceUpdateCanvases(); LayoutRebuilder.ForceRebuildLayoutImmediate(rect);
            foreach (string name in new[] { "Header", "Categories", "Cheat Scroll View", "Action feedback" })
            {
                var child = card.Find(name) as RectTransform;
                var corners = new Vector3[4]; child.GetWorldCorners(corners);
                foreach (var corner in corners)
                {
                    Vector3 local = card.InverseTransformPoint(corner);
                    Assert.GreaterOrEqual(local.x, card.rect.xMin - 0.1f, name);
                    Assert.LessOrEqual(local.x, card.rect.xMax + 0.1f, name);
                    Assert.GreaterOrEqual(local.y, card.rect.yMin - 0.1f, name);
                    Assert.LessOrEqual(local.y, card.rect.yMax + 0.1f, name);
                }
            }
            type.GetField("clearConfirmationPending", Instance).SetValue(panel, true);
            type.GetField("resetConfirmationPending", Instance).SetValue(panel, true);
            type.GetMethod("SelectTab", Instance).Invoke(panel, new object[] { 3 });
            Assert.IsFalse((bool)type.GetField("clearConfirmationPending", Instance).GetValue(panel));
            Assert.IsFalse((bool)type.GetField("resetConfirmationPending", Instance).GetValue(panel));
            var content = card.Find("Cheat Scroll View/Viewport/Content");
            Assert.AreEqual(4, content.childCount);
            Assert.AreEqual(1, content.Cast<Transform>().Count(t => t.gameObject.activeSelf));
            Assert.IsTrue(content.Find("Services").gameObject.activeSelf);
        }
        finally
        {
            if (canvas != null) UnityEngine.Object.DestroyImmediate(canvas);
            UnityEngine.Object.DestroyImmediate(owner); UnityEngine.Object.DestroyImmediate(parent);
        }
    }

    [Test]
    public void ClosingTestLabReleasesInputAndCancelsPendingConfirmations()
    {
        var owner = new GameObject("Test lab modal test"); owner.SetActive(false);
        var parent = new GameObject("Existing canvas", typeof(RectTransform), typeof(Canvas));
        Component panel = null; GameObject canvas = null;
        Type type = Find("DeveloperCheatPanel");
        try
        {
            panel = owner.AddComponent(type); type.GetMethod("BuildUi", Instance).Invoke(panel, new object[] { parent.transform });
            canvas = (GameObject)type.GetField("testingCanvasRoot", Instance).GetValue(panel);
            owner.SetActive(true);
            type.GetMethod("SetPanelOpen", Instance).Invoke(panel, new object[] { true });
            Assert.IsTrue((bool)Find("GameplayModalInputGate").GetProperty("IsGameplayInputBlocked").GetValue(null));
            type.GetField("resetConfirmationPending", Instance).SetValue(panel, true);
            type.GetMethod("SetPanelOpen", Instance).Invoke(panel, new object[] { false });
            Assert.IsFalse((bool)Find("GameplayModalInputGate").GetProperty("IsGameplayInputBlocked").GetValue(null));
            Assert.IsFalse((bool)type.GetField("resetConfirmationPending", Instance).GetValue(panel));
        }
        finally
        {
            if (panel != null) type.GetMethod("SetPanelOpen", Instance).Invoke(panel, new object[] { false });
            if (canvas != null) UnityEngine.Object.DestroyImmediate(canvas);
            UnityEngine.Object.DestroyImmediate(owner); UnityEngine.Object.DestroyImmediate(parent);
        }
    }
}
