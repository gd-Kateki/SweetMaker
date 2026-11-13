using System;
using System.Linq;
using NUnit.Framework;
using UnityEditor.SceneManagement;
using UnityEngine.SceneManagement;

public sealed class SceneUiHierarchyTests
{
    private static Type Find(string name) => AppDomain.CurrentDomain.GetAssemblies()
        .Select(a => a.GetType(name)).First(t => t != null);

    [Test]
    public void AllGeneratedDesignsHaveLinkedSceneEntriesAndAreExcludedFromBuilds()
    {
        Find("SceneUiHierarchyEditor").GetMethod("Validate").Invoke(null, null);
    }

    [TestCase(true)]
    [TestCase(false)]
    public void StartupPreviewShowsOnlyTheChosenScreen(bool signIn)
    {
        var scene = EditorSceneManager.OpenPreviewScene("Assets/_Game/Scenes/Welcome.unity");
        try
        {
            var entryType = Find("SceneUiDesign");
            var entry = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren(entryType, true))
                .Single(e => ((string)entryType.GetField("assetPath").GetValue(e)).EndsWith("/StartupWelcome.prefab"));
            Find("SceneUiHierarchyEditor").GetMethod("ShowStartupScreen", System.Reflection.BindingFlags.Static | System.Reflection.BindingFlags.NonPublic)
                .Invoke(null, new object[] { entry, signIn });
            var transforms = entry.GetComponentsInChildren<UnityEngine.Transform>(true);
            Assert.AreEqual(signIn, transforms.Single(t => t.name == "WelcomeScreen").gameObject.activeInHierarchy);
            Assert.AreEqual(!signIn, transforms.Single(t => t.name == "PrivacyScreen").gameObject.activeInHierarchy);
        }
        finally { EditorSceneManager.ClosePreviewScene(scene); }
    }

    [TestCase("MainBakery")]
    [TestCase("Game")]
    [TestCase("Welcome")]
    [TestCase("Loading")]
    public void SceneProcessingRemovesDesignCopiesAndPreservesGameplayRoots(string name)
    {
        Scene scene = EditorSceneManager.OpenPreviewScene("Assets/_Game/Scenes/" + name + ".unity");
        try
        {
            var roots = scene.GetRootGameObjects();
            var group = roots.Single(r => r.name == "UI Designs (Editor Only)");
            var processorType = Find("SceneUiDesignBuildProcessor");
            processorType.GetMethod("OnProcessScene").Invoke(Activator.CreateInstance(processorType), new object[] { scene, null });
            Assert.IsTrue(group == null, "Editing copies must never survive scene processing.");
            Assert.AreEqual(roots.Length - 1, scene.GetRootGameObjects().Length);
            foreach (var root in roots.Where(r => r != null))
                Assert.IsTrue(scene.GetRootGameObjects().Contains(root));
        }
        finally { EditorSceneManager.ClosePreviewScene(scene); }
    }
}
