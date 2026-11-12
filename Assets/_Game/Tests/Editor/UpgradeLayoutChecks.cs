using System;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.UI;

// Behavioural layout checks replace old serialized pixel/sprite snapshots.
internal static class UpgradeLayoutChecks
{
    private const string CardPath = "Assets/_Game/Prefabs/UI/UpgradeCard.prefab";
    private const string ScreenPath = "Assets/_Game/Prefabs/UI/UpgradeScreen.prefab";
    private const BindingFlags Private = BindingFlags.Instance | BindingFlags.NonPublic;
    private static Type Find(string name) => AppDomain.CurrentDomain.GetAssemblies().Select(a => a.GetType(name)).First(t => t != null);
    private static GameObject LoadCard() => PrefabUtility.LoadPrefabContents(CardPath);

    internal static void Buttons()
    {
        var card = LoadCard();
        try
        {
            var button = card.GetComponentInChildren<Button>(true); var image = button.GetComponent<Image>();
            Assert.IsNotNull(image.sprite); StringAssert.Contains("SU_Upgrade", AssetDatabase.GetAssetPath(image.sprite));
            Assert.AreSame(image, button.targetGraphic); Assert.AreEqual(Color.white, button.colors.normalColor);
            Assert.GreaterOrEqual(button.colors.disabledColor.g, button.colors.disabledColor.r);
            var type = Find("UpgradeCardUI"); var controller = card.GetComponent(type);
            var definition = AssetDatabase.LoadMainAssetAtPath("Assets/_Game/Data/Upgrades/Upgrade_Oven.asset");
            type.GetField("upgradeDefinition", Private).SetValue(controller, definition);
            int max = (int)definition.GetType().GetProperty("MaxPurchasableLevel").GetValue(definition);
            var level = definition.GetType().GetMethod("GetLevel").Invoke(definition, new object[] { max });
            type.GetMethod("ShowMaxLevel", Private).Invoke(controller, new object[] { max, level });
            Assert.IsFalse(button.interactable);
            Assert.IsTrue(card.transform.Find("MaxLevelBadge").gameObject.activeSelf);
            Assert.AreEqual("MAX LEVEL", TextValue(card.transform.Find("BodyRow/CostActionGroup/PurchaseButton/ButtonText")));
        }
        finally { PrefabUtility.UnloadPrefabContents(card); }
    }

    internal static void CardLayout()
    {
        var card = LoadCard();
        try
        {
            var rect = (RectTransform)card.transform; rect.anchorMin = rect.anchorMax = new Vector2(.5f, .5f);
            foreach (float width in new[] { 640f, 820f, 1000f })
            {
                rect.sizeDelta = new Vector2(width, card.GetComponent<LayoutElement>().preferredHeight);
                foreach (string path in new[] { "HeaderRow/UpgradeNameText", "HeaderRow/LevelText", "BodyRow/InformationBox", "BodyRow/EffectLabelText", "BodyRow/ValueText", "BodyRow/CostActionGroup/PriceText", "BodyRow/CostActionGroup/PurchaseButton", "MaxLevelBadge" })
                    Inside(rect.rect, Bounds((RectTransform)card.transform.Find(path), rect), path);
                var info = Bounds((RectTransform)card.transform.Find("BodyRow/InformationBox"), rect);
                var button = Bounds((RectTransform)card.transform.Find("BodyRow/CostActionGroup/PurchaseButton"), rect);
                var price = Bounds((RectTransform)card.transform.Find("BodyRow/CostActionGroup/PriceText"), rect);
                Assert.GreaterOrEqual(button.xMin, info.xMax);
                Assert.GreaterOrEqual(price.yMin, button.yMax);
                Assert.GreaterOrEqual(button.height, 72);
                var name = Bounds((RectTransform)card.transform.Find("HeaderRow/UpgradeNameText"), rect);
                var badge = Bounds((RectTransform)card.transform.Find("MaxLevelBadge"), rect);
                var effect = Bounds((RectTransform)card.transform.Find("BodyRow/EffectLabelText"), rect);
                Assert.LessOrEqual(badge.yMax, name.yMin);
                Assert.GreaterOrEqual(badge.yMin, effect.yMax);
            }
        }
        finally { PrefabUtility.UnloadPrefabContents(card); }
    }

    internal static void Typography()
    {
        var card = LoadCard();
        try
        {
            foreach (var text in card.GetComponentsInChildren(Find("TMPro.TMP_Text"), true))
            {
                var type = text.GetType();
                Assert.IsNotNull(type.GetProperty("font").GetValue(text));
                Assert.GreaterOrEqual((float)type.GetProperty("fontSizeMin").GetValue(text), 20);
                Assert.GreaterOrEqual((float)type.GetProperty("fontSizeMax").GetValue(text), (float)type.GetProperty("fontSizeMin").GetValue(text));
                Assert.IsTrue((bool)type.GetProperty("isOrthographic").GetValue(text));
                Assert.IsFalse(((Graphic)text).raycastTarget);
            }
        }
        finally { PrefabUtility.UnloadPrefabContents(card); }
    }

    internal static void Header() => CheckScreen(false);
    internal static void Scroll() => CheckScreen(true);
    private static void CheckScreen(bool checkScroll)
    {
        var screen = PrefabUtility.LoadPrefabContents(ScreenPath); var parent = new GameObject("Layout surface", typeof(RectTransform));
        try
        {
            UnityEngine.SceneManagement.SceneManager.MoveGameObjectToScene(parent, screen.scene);
            screen.transform.SetParent(parent.transform, false); screen.SetActive(true);
            var scroll = screen.GetComponentInChildren<ScrollRect>(true); var panel = (RectTransform)scroll.transform;
            foreach (float height in new[] { 1280f, 1920f, 2400f, 2560f })
            {
                ((RectTransform)parent.transform).sizeDelta = new Vector2(1080, height);
                var header = (RectTransform)panel.Find("Header");
                var viewport = Bounds(scroll.viewport, panel); var headerBounds = Bounds(header, panel);
                Inside(panel.rect, viewport, "Viewport"); Inside(panel.rect, headerBounds, "Header");
                Assert.LessOrEqual(viewport.yMax, headerBounds.yMin);
                var close = (RectTransform)header.Find("CloseButton"); Inside(panel.rect, Bounds(close, panel), "Close");
                Assert.GreaterOrEqual(close.rect.height, 72);
                Assert.LessOrEqual(Bounds((RectTransform)header.Find("TitleText"), header).xMax, Bounds(close, header).xMin);
                if (checkScroll)
                {
                    Assert.IsFalse(scroll.horizontal); Assert.IsTrue(scroll.vertical);
                    Assert.AreEqual(ScrollRect.MovementType.Clamped, scroll.movementType);
                    Assert.AreEqual(new Vector2(0, 1), scroll.content.anchorMin); Assert.AreEqual(Vector2.one, scroll.content.anchorMax);
                    Assert.IsNotNull(scroll.viewport.GetComponent<RectMask2D>());
                    var layout = scroll.content.GetComponent<VerticalLayoutGroup>();
                    Assert.IsTrue(layout.childControlWidth); Assert.IsTrue(layout.childControlHeight); Assert.IsFalse(layout.childForceExpandHeight);
                    Assert.AreEqual(6, scroll.content.childCount);
                }
            }
        }
        finally { if (screen != null) screen.transform.SetParent(null); UnityEngine.Object.DestroyImmediate(parent); if (screen != null) PrefabUtility.UnloadPrefabContents(screen); }
    }

    internal static void Modal()
    {
        foreach (string name in new[] { "MainBakery", "Game" })
        {
            var scene = EditorSceneManager.OpenPreviewScene("Assets/_Game/Scenes/" + name + ".unity");
            try
            {
                var type = Find("UpgradeScreenUI"); var controller = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren(type, true)).Single();
                var screen = (GameObject)type.GetField("upgradeScreen", Private).GetValue(controller);
                Assert.AreEqual(ScreenPath, PrefabUtility.GetPrefabAssetPathOfNearestInstanceRoot(screen));
                Assert.IsFalse(screen.activeSelf);
                var blocker = screen.transform.Find("ModalInputBlocker"); Assert.AreEqual(0, blocker.GetSiblingIndex());
                Assert.IsTrue(blocker.GetComponent<Image>().raycastTarget);
                Assert.AreEqual(Vector2.zero, ((RectTransform)blocker).anchorMin); Assert.AreEqual(Vector2.one, ((RectTransform)blocker).anchorMax);
                var close = (Button)type.GetField("closeButton", Private).GetValue(controller); Assert.IsTrue(close.transform.IsChildOf(screen.transform));
                var cards = screen.GetComponentsInChildren(Find("UpgradeCardUI"), true); Assert.AreEqual(6, cards.Length);
                Assert.AreEqual(6, cards.Select(c => Find("UpgradeCardUI").GetField("upgradeDefinition", Private).GetValue(c)).Where(d => d != null).Distinct().Count());
            }
            finally { EditorSceneManager.ClosePreviewScene(scene); }
        }
    }
    private static string TextValue(Transform target)
    { var text = target.GetComponent(Find("TMPro.TMP_Text")); return (string)text.GetType().GetProperty("text").GetValue(text); }
    private static Rect Bounds(RectTransform target, RectTransform parent)
    {
        var corners = new Vector3[4]; target.GetWorldCorners(corners);
        var min = (Vector2)parent.InverseTransformPoint(corners[0]); var max = min;
        foreach (var corner in corners) { var p = (Vector2)parent.InverseTransformPoint(corner); min = Vector2.Min(min, p); max = Vector2.Max(max, p); }
        return Rect.MinMaxRect(min.x, min.y, max.x, max.y);
    }
    private static void Inside(Rect parent, Rect child, string message)
    { Assert.GreaterOrEqual(child.xMin, parent.xMin-.1f, message); Assert.LessOrEqual(child.xMax, parent.xMax+.1f, message); Assert.GreaterOrEqual(child.yMin, parent.yMin-.1f, message); Assert.LessOrEqual(child.yMax, parent.yMax+.1f, message); }
}
