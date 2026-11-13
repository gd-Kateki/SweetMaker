using System.Linq;
using NUnit.Framework;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.UI;

public sealed class CollectionAspectTests
{
    [TestCase(1080, 1920)]
    [TestCase(1080, 2400)]
    [TestCase(1600, 2560)]
    public void CollectionFitsAvailableSpaceWithoutStretchingItsOriginalArtwork(int width, int height)
    {
        var scene = EditorSceneManager.OpenPreviewScene("Assets/_Game/Scenes/MainBakery.unity");
        try
        {
            var panel = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren<RectTransform>(true)).Single(t => t.name == "CollectionPanel");
            var image = panel.GetComponent<Image>();
            Assert.IsNotNull(image.sprite);
            var fitter = panel.GetComponent<AspectRatioFitter>();
            Assert.IsNotNull(fitter);
            Assert.AreEqual(AspectRatioFitter.AspectMode.FitInParent, fitter.aspectMode);
            float ratio = image.sprite.rect.width / image.sprite.rect.height;
            Assert.AreEqual(ratio, fitter.aspectRatio, .0001f);
            var bounds = (RectTransform)panel.parent;
            Assert.AreEqual("CollectionBounds", bounds.name);
            for (var parent = panel.transform; parent != null; parent = parent.parent) parent.gameObject.SetActive(true);
            bounds.anchorMin = bounds.anchorMax = new Vector2(.5f, .5f);
            bounds.sizeDelta = new Vector2(width, height);
            fitter.aspectRatio = ratio + .001f; fitter.aspectRatio = ratio;
            Canvas.ForceUpdateCanvases();
            Assert.AreEqual(ratio, panel.rect.width / panel.rect.height, .001f);
            Assert.LessOrEqual(panel.rect.width, width + .1f);
            Assert.LessOrEqual(panel.rect.height, height + .1f);
        }
        finally { EditorSceneManager.ClosePreviewScene(scene); }
    }
}
