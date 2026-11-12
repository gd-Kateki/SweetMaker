using System;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.UI;

public sealed class SettingsDesignerTests
{
    private const BindingFlags Private = BindingFlags.Instance | BindingFlags.NonPublic;
    private const string Folder = "Assets/_Game/Resources/UI/VisualTemplates/";
    private static Type Find(string name) => AppDomain.CurrentDomain.GetAssemblies().Select(a => a.GetType(name)).First(t => t != null);

    [Test]
    public void CompleteSettingsDesignIsVisibleInPrefabModeAndSupersedesOldSectionAssets()
    {
        var prefab = AssetDatabase.LoadAssetAtPath<GameObject>(Folder + "SettingsArtwork.prefab");
        Assert.IsNotNull(prefab);
        Assert.IsNotNull(prefab.GetComponent<Canvas>(), "The complete design needs an editor-visible canvas.");
        Assert.IsNotNull(prefab.GetComponent<Image>());
        Assert.IsEmpty(prefab.GetComponentsInChildren<Button>(true), "The design must not contain game actions.");
        foreach (var behaviour in prefab.GetComponentsInChildren<MonoBehaviour>(true))
            Assert.IsTrue(behaviour.GetType().FullName.StartsWith("TMPro.") || behaviour.GetType().Namespace == "UnityEngine.UI" || behaviour.GetType() == Find("EditableUIVisual"), behaviour.GetType().FullName);
        foreach (string old in new[] { "AccountSettings", "PrivacySettings", "AnalyticsSettings", "SettingsAccountV2", "SettingsPrivacyV2", "SettingsAnalyticsV2" })
            Assert.IsNull(AssetDatabase.LoadAssetAtPath<GameObject>(Folder + old + ".prefab"), old);
    }

    [TestCase("MainBakery")]
    [TestCase("Game")]
    public void EditingTheSharedDesignStylesEverySectionInBothScenesAndPreservesLiveState(string name)
    {
        var scene = EditorSceneManager.OpenPreviewScene("Assets/_Game/Scenes/" + name + ".unity");
        GameObject design = null;
        try
        {
            var presentationType = Find("SettingsScreenPresentation");
            var presentation = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren(presentationType, true)).Single();
            var content = (RectTransform)presentationType.GetField("contentRectTransform", Private).GetValue(presentation);
            var builder = Find("SettingsLayoutEditor").GetMethod("BuildSection", BindingFlags.Static | BindingFlags.NonPublic);
            builder.Invoke(null, new object[] { content, "AnalyticsPrivacySettings", Find("SweetMerge.Analytics.AnalyticsConsentSettingsControl") });
            var account = (RectTransform)builder.Invoke(null, new object[] { content, "GooglePlayGamesAccountSettings", Find("SweetMerge.Authentication.GooglePlayGamesAccountSettingsControl") });
            var title = presentationType.GetField("titleText", Private).GetValue(presentation);
            var font = title.GetType().GetProperty("font").GetValue(title);
            Find("SweetMerge.Cloud.SimpleCloudPanel").GetMethod("Attach").Invoke(null, new object[] { account, font });
            Find("PlayerPrivacyUI").GetMethod("AttachSettings").Invoke(null, new object[] { content, null });
            presentationType.GetMethod("ApplyLayout", Private).Invoke(presentation, null);
            var viewType = Find("EditableUIView");
            viewType.GetMethod("Attach").Invoke(null, new object[] { presentation.gameObject, "SettingsArtwork" });
            var owner = presentation.GetComponent(viewType);
            viewType.GetMethod("IncludeNestedViews").Invoke(owner, null);
            design = UnityEngine.Object.Instantiate(AssetDatabase.LoadAssetAtPath<GameObject>(Folder + "SettingsArtwork.prefab"));
            design.SetActive(false);
            design.GetComponentsInChildren<Image>(true).Single(i => i.name == "Advertising privacy").color = Color.cyan;
            var actualButton = content.GetComponentsInChildren<Button>(true).Single(b => b.name == "Advertising privacy");
            actualButton.interactable = false;
            viewType.GetMethod("ApplyTemplate", Private).Invoke(owner, new object[] { design.transform });
            Assert.AreEqual(Color.cyan, actualButton.GetComponent<Image>().color, "The shared design must own nested privacy styling.");
            Assert.IsFalse(actualButton.interactable);
            var resolve = viewType.GetMethod("Resolve", BindingFlags.Static | BindingFlags.NonPublic);
            var marker = Find("EditableUIVisual");
            foreach (var part in design.GetComponentsInChildren(marker, true))
            {
                string path = (string)marker.GetField("targetPath").GetValue(part);
                Assert.IsNotNull(resolve.Invoke(null, new object[] { presentation.transform, path }), name + ": " + path);
            }
            Assert.AreEqual(1, scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren(Find("SettingsUI"), true)).Count(), "Each scene needs exactly one wired settings controller.");
        }
        finally { if (design != null) UnityEngine.Object.DestroyImmediate(design); EditorSceneManager.ClosePreviewScene(scene); }
    }
}
