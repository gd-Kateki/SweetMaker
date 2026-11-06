using System;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEngine;
using UnityEngine.UI;
using UnityEditor;

public sealed class EditableUITests
{
    private static Type Find(string name) => AppDomain.CurrentDomain.GetAssemblies()
        .Select(a => a.GetType(name)).First(t => t != null);
    private static Type View => Find("EditableUIView");
    private static Component Part(GameObject root, string path)
    {
        Type type = Find("EditableUIVisual");
        var part = root.AddComponent(type); type.GetField("targetPath").SetValue(part, path);
        return part;
    }
    private static void Apply(Component view, Transform template) => View.GetMethod("ApplyTemplate", BindingFlags.NonPublic | BindingFlags.Instance)
        .Invoke(view, new object[] { template });

    [Test]
    public void StarterVisualAssetsContainResolvableBindingsAndNoButtonActions()
    {
        string[] guids = AssetDatabase.FindAssets("t:Prefab", new[] { "Assets/_Game/Resources/UI/VisualTemplates" });
        Assert.GreaterOrEqual(guids.Length, 21);
        var partType = Find("EditableUIVisual");
        var resolve = View.GetMethod("Resolve", BindingFlags.Static | BindingFlags.NonPublic);
        foreach (string guid in guids)
        {
            string path = AssetDatabase.GUIDToAssetPath(guid);
            var prefab = AssetDatabase.LoadAssetAtPath<GameObject>(path);
            Assert.IsEmpty(prefab.GetComponentsInChildren<Button>(true), path);
            foreach (var part in prefab.GetComponentsInChildren(partType, true))
            {
                string binding = (string)partType.GetField("targetPath").GetValue(part);
                Assert.AreSame(part.transform, resolve.Invoke(null, new object[] { prefab.transform, binding }), path + ": " + binding);
            }
        }
    }

    [Test]
    public void CapturingVisualsNeverClonesActionsAndStylingPreservesLiveButtonState()
    {
        var live = new GameObject("Button", typeof(RectTransform), typeof(Image), typeof(Button));
        GameObject template = null;
        try
        {
            int clicks = 0; var button = live.GetComponent<Button>(); button.onClick.AddListener(() => clicks++);
            button.interactable = false;
            template = (GameObject)Find("EditableUIEditor").GetMethod("CopyVisualTree", BindingFlags.Static | BindingFlags.NonPublic)
                .Invoke(null, new object[] { live.transform, null, live.transform });
            Assert.IsNull(template.GetComponent<Button>(), "A visual export must not carry gameplay events or interaction components.");
            Assert.AreEqual(0, clicks);
            template.GetComponent<Image>().color = Color.magenta;
            var view = live.AddComponent(View); Apply(view, template.transform);
            Assert.AreEqual(Color.magenta, live.GetComponent<Image>().color);
            Assert.IsFalse(button.interactable);
            button.onClick.Invoke(); Assert.AreEqual(1, clicks, "The real action must remain connected exactly once.");
        }
        finally { if (template != null) UnityEngine.Object.DestroyImmediate(template); UnityEngine.Object.DestroyImmediate(live); }
    }

    [Test]
    public void TypographyChangesPreserveLiveValuesAndRichTextProtection()
    {
        Type textType = Find("TMPro.TextMeshProUGUI");
        var live = new GameObject("Live label", typeof(RectTransform), textType);
        var design = new GameObject("Design label", typeof(RectTransform), textType);
        try
        {
            var liveText = live.GetComponent(textType); var designText = design.GetComponent(textType);
            textType.GetProperty("text").SetValue(liveText, "Current money: 64");
            textType.GetProperty("richText").SetValue(liveText, false);
            textType.GetProperty("text").SetValue(designText, "Preview only: 32");
            textType.GetProperty("fontSize").SetValue(designText, 41f);
            var part = Part(design, "");
            View.GetMethod("CopyPart", BindingFlags.NonPublic | BindingFlags.Static).Invoke(null, new object[] { part, live.transform });
            Assert.AreEqual("Current money: 64", textType.GetProperty("text").GetValue(liveText));
            Assert.AreEqual(false, textType.GetProperty("richText").GetValue(liveText));
            Assert.AreEqual(41f, textType.GetProperty("fontSize").GetValue(liveText));
        }
        finally { UnityEngine.Object.DestroyImmediate(live); UnityEngine.Object.DestroyImmediate(design); }
    }

    [Test]
    public void NestedScreensKeepTheirOwnStylesAndAddedArtworkCannotBlockClicks()
    {
        var live = new GameObject("Root", typeof(RectTransform));
        var template = new GameObject("Root", typeof(RectTransform));
        try
        {
            var view = live.AddComponent(View); Part(template, "");
            var nested = new GameObject("Nested", typeof(RectTransform), typeof(Image)); nested.transform.SetParent(live.transform, false);
            nested.AddComponent(View); nested.GetComponent<Image>().color = Color.green;
            var nestedDesign = new GameObject("Nested", typeof(RectTransform), typeof(Image)); nestedDesign.transform.SetParent(template.transform, false);
            Part(nestedDesign, "Nested:0"); nestedDesign.GetComponent<Image>().color = Color.red;
            var decoration = new GameObject("Ribbon", typeof(RectTransform), typeof(Image)); decoration.transform.SetParent(template.transform, false);
            Apply(view, template.transform); Apply(view, template.transform);
            Assert.AreEqual(Color.green, nested.GetComponent<Image>().color);
            var ribbons = live.GetComponentsInChildren<Image>(true).Where(i => i.name.StartsWith("Ribbon")).ToArray();
            Assert.AreEqual(1, ribbons.Length, "Reapplying a visual design must not duplicate decorations.");
            Assert.IsFalse(ribbons[0].raycastTarget);
        }
        finally { UnityEngine.Object.DestroyImmediate(live); UnityEngine.Object.DestroyImmediate(template); }
    }

    [Test]
    public void DuplicateLabelBindingsAreDistinctAndEscapedNamesResolve()
    {
        var root = new GameObject("Root", typeof(RectTransform));
        try
        {
            var first = new GameObject("Label/with: punctuation", typeof(RectTransform)); first.transform.SetParent(root.transform);
            var second = new GameObject(first.name, typeof(RectTransform)); second.transform.SetParent(root.transform);
            var path = View.GetMethod("PathFor"); var resolve = View.GetMethod("Resolve", BindingFlags.Static | BindingFlags.NonPublic);
            string a = (string)path.Invoke(null, new object[] { root.transform, first.transform });
            string b = (string)path.Invoke(null, new object[] { root.transform, second.transform });
            Assert.AreNotEqual(a, b);
            Assert.AreSame(second.transform, resolve.Invoke(null, new object[] { root.transform, b }));
        }
        finally { UnityEngine.Object.DestroyImmediate(root); }
    }
}
