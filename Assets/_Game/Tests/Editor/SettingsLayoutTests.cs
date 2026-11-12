using System;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.UI;

public sealed class SettingsLayoutTests
{
    private const BindingFlags Private = BindingFlags.Instance | BindingFlags.NonPublic;
    private static Type Presentation => AppDomain.CurrentDomain.GetAssemblies().Select(a => a.GetType("SettingsScreenPresentation")).First(t => t != null);

    [TestCase("MainBakery", 1080, 1920)]
    [TestCase("Game", 1080, 2400)]
    [TestCase("MainBakery", 720, 1280)]
    [TestCase("Game", 1600, 2560)]
    public void GrowingCloudContentDoesNotMoveSoundRowsOrPushCloseOutsidePanel(string name, float width, float height)
    {
        var scene = EditorSceneManager.OpenPreviewScene("Assets/_Game/Scenes/" + name + ".unity");
        try
        {
            var view = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren(Presentation, true)).Single();
            var panel = (RectTransform)Presentation.GetField("panelRectTransform", Private).GetValue(view);
            var content = (RectTransform)Presentation.GetField("contentRectTransform", Private).GetValue(view);
            var parent = (RectTransform)panel.parent;
            parent.anchorMin = parent.anchorMax = Vector2.zero;
            parent.sizeDelta = new Vector2(width, height);
            Apply(view);
            var title = Presentation.GetField("titleText", Private).GetValue(view);
            Assert.IsTrue((bool)title.GetType().GetProperty("isOrthographic").GetValue(title), "Settings text must use consistent screen-space sizing in both scenes.");
            Assert.IsNotNull(content.Find("SettingsPersistenceFeedback"), "Save feedback must scroll inside its About card.");
            var toggle = (RectTransform)content.Find("SfxEnabledToggle");
            var before = toggle.anchoredPosition;
            var card = (RectTransform)content.Find("SettingsCard1");
            float cardHeight = card.rect.height;
            var section = new GameObject("GooglePlayGamesAccountSettings", typeof(RectTransform));
            section.transform.SetParent(content, false);
            ((RectTransform)section.transform).sizeDelta = new Vector2(0, 830);
            Apply(view);
            Assert.AreEqual(before, toggle.anchoredPosition, "Appending cloud controls must not redistribute existing rows.");
            Assert.AreEqual(cardHeight, card.rect.height);
            Assert.AreEqual(144, toggle.rect.width);
            Assert.AreEqual(64, toggle.rect.height);
            Assert.LessOrEqual(panel.rect.width, width - 48 + .1f);
            Assert.LessOrEqual(panel.rect.width, 1000);
            var close = ((Image)Presentation.GetField("closeButtonImage", Private).GetValue(view)).rectTransform;
            var corners = new Vector3[4]; close.GetWorldCorners(corners);
            foreach (var corner in corners) Assert.IsTrue(panel.rect.Contains(panel.InverseTransformPoint(corner)), "Close must stay inside the safe-area panel.");
            var account = (RectTransform)section.transform;
            Assert.GreaterOrEqual(content.rect.height, -account.anchoredPosition.y + account.rect.height);
            Assert.AreEqual(Image.Type.Sliced, panel.GetComponent<Image>().type);
            Assert.IsTrue(panel.GetComponent<Image>().sprite.border.sqrMagnitude > 0, "Panel artwork needs real slice borders.");
            Assert.AreEqual(ScrollRect.MovementType.Clamped, content.GetComponentInParent<ScrollRect>(true).movementType);
            int children = content.childCount;
            Apply(view);
            Assert.AreEqual(children, content.childCount, "Reopening must reuse cards.");
            Assert.AreEqual(before, toggle.anchoredPosition);
        }
        finally { EditorSceneManager.ClosePreviewScene(scene); }
    }
    private static void Apply(Component view) => Presentation.GetMethod("ApplyLayout", Private).Invoke(view, null);
}
