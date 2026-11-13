using System;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;

public sealed class HomeButtonAuthoringTests
{
    private static Type Find(string name) => AppDomain.CurrentDomain.GetAssemblies().Select(a => a.GetType(name)).First(t => t != null);
    [Test]
    public void AuthoredCafeButtonRetainsItsScenePositionWhenRuntimeBindsIt()
    {
        var scene = EditorSceneManager.OpenPreviewScene("Assets/_Game/Scenes/MainBakery.unity");
        try
        {
            var type = Find("CafeProfileUI");
            var ui = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren(type, true)).Single();
            var card = (GameObject)new SerializedObject(ui).FindProperty("cardRoot").objectReferenceValue;
            Assert.IsNotNull(card);
            var rect = (RectTransform)card.transform;
            rect.anchoredPosition = new Vector2(123,-234);
            int children = ui.transform.childCount;
            type.GetMethod("CreateCard", BindingFlags.Instance | BindingFlags.NonPublic).Invoke(ui, null);
            Assert.AreEqual(new Vector2(123,-234), rect.anchoredPosition);
            Assert.AreEqual(children, ui.transform.childCount);
            Assert.IsNotNull(rect.GetComponentInParent<Canvas>());
            var launcher = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren(Find("HomeLeaderboardButton"), true)).Single();
            Assert.AreEqual("TopBar", launcher.transform.parent.name);
            Assert.IsTrue(launcher.gameObject.activeInHierarchy);
        }
        finally { EditorSceneManager.ClosePreviewScene(scene); }
    }
}
