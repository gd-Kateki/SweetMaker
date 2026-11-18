using System;
using System.Linq;
using NUnit.Framework;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.UI;

public sealed class UpgradeV3Tests
{
    private const string Art = "Assets/_Game/Art/UI_Assets/UI V3/Shop_Upgrade/";
    private const string Screen = "Assets/_Game/Prefabs/UI/UpgradeScreen.prefab";
    private static Type Find(string name) => AppDomain.CurrentDomain.GetAssemblies().Select(a => a.GetType(name)).First(t => t != null);

    [Test]
    public void UpgradeScreenUsesReferenceArtworkWithSeparateScrollableCreamRows()
    {
        var screen = AssetDatabase.LoadAssetAtPath<GameObject>(Screen);
        var images = screen.GetComponentsInChildren<Image>(true);
        foreach (string name in new[] { "SU_Backplate", "SU_Board", "SU_Bar", "SU_Cancel", "SU_Upgrade" })
            Assert.IsTrue(images.Any(i => AssetDatabase.GetAssetPath(i.sprite) == Art + name + ".png"), name);
        var frame = images.Single(i => i.name == "V3GoldFrame");
        Assert.IsFalse(frame.fillCenter, "Baked static row backgrounds must not remain behind scrolling rows.");
        Assert.Greater(frame.sprite.border.sqrMagnitude, 0);
        var row = AssetDatabase.LoadAssetAtPath<Sprite>(Art + "SU_RowSlice.asset");
        Assert.AreEqual(Art + "SU_Backplate.png", AssetDatabase.GetAssetPath(row.texture));
        Assert.Greater(row.border.sqrMagnitude, 0);
        var close = screen.GetComponentsInChildren<Button>(true).Single(b => b.name == "CloseButton");
        Assert.IsFalse(close.transform.Find("CloseIcon").gameObject.activeSelf, "Use the V3 cancel sprite without duplicate strokes.");
    }

    [TestCase("MainBakery")]
    [TestCase("Game")]
    public void BothScenesKeepTheSharedScreenAndAllSixAssignedUpgrades(string name)
    {
        var scene = EditorSceneManager.OpenPreviewScene("Assets/_Game/Scenes/" + name + ".unity");
        try
        {
            var controller = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren(Find("UpgradeScreenUI"), true)).Single();
            var data = new SerializedObject(controller);
            var root = (GameObject)data.FindProperty("upgradeScreen").objectReferenceValue;
            Assert.AreEqual(Screen, PrefabUtility.GetPrefabAssetPathOfNearestInstanceRoot(root));
            var close = (Button)data.FindProperty("closeButton").objectReferenceValue;
            Assert.IsTrue(close.transform.IsChildOf(root.transform));
            var cards = root.GetComponentsInChildren(Find("UpgradeCardUI"), true);
            Assert.AreEqual(6, cards.Length);
            var definitions = cards.Select(c => new SerializedObject(c).FindProperty("upgradeDefinition").objectReferenceValue).ToArray();
            Assert.IsTrue(definitions.All(d => d != null));
            Assert.AreEqual(6, definitions.Distinct().Count());
            foreach (var card in cards)
                Assert.IsNotNull(new SerializedObject(card).FindProperty("purchaseButton").objectReferenceValue);
        }
        finally { EditorSceneManager.ClosePreviewScene(scene); }
    }
}
