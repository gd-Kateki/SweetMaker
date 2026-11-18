using System.Linq;
using NUnit.Framework;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;

public sealed class UiControlShapeTests
{
    [Test]
    public void SettingsTracksKeepTheirCurvesOutOfTheStretchingCenterAndHandlesStayRound()
    {
        var design=AssetDatabase.LoadAssetAtPath<GameObject>("Assets/_Game/Resources/UI/VisualTemplates/SettingsArtwork.prefab");
        var images=design.GetComponentsInChildren<Image>(true);
        var tracks=images.Where(i=>i.sprite!=null && (AssetDatabase.GetAssetPath(i.sprite).EndsWith("/Settings_Slider_Bar.png")||AssetDatabase.GetAssetPath(i.sprite).EndsWith("/Settings_On_Bar.png"))).ToArray();
        Assert.IsNotEmpty(tracks);
        foreach(var image in tracks)
        {
            Assert.AreEqual(Image.Type.Sliced,image.type);
            Assert.GreaterOrEqual(image.sprite.border.x,image.sprite.rect.height*.5f,"The complete rounded cap must be outside the stretched center.");
            Assert.GreaterOrEqual(image.pixelsPerUnitMultiplier,2.5f);
        }
        var handles=images.Where(i=>i.sprite!=null && AssetDatabase.GetAssetPath(i.sprite).Contains("Ellipse")).ToArray();
        Assert.IsNotEmpty(handles);
        foreach(var handle in handles){Assert.AreEqual(Image.Type.Simple,handle.type);Assert.IsTrue(handle.preserveAspect);}
    }

    [Test]
    public void OrdinaryActionCornersRemainCompactWhenTheirButtonsAreWide()
    {
        foreach(string key in new[]{"CafeNaming","TutorialWelcome","CloudProgressChoice","SettingsArtwork"})
        {
            var root=AssetDatabase.LoadAssetAtPath<GameObject>("Assets/_Game/Resources/UI/VisualTemplates/"+key+".prefab");
            var actions=root.GetComponentsInChildren<Image>(true).Where(i=>i.sprite!=null &&
                (AssetDatabase.GetAssetPath(i.sprite).Contains("/Shared/V3GoldButton.asset")||AssetDatabase.GetAssetPath(i.sprite).Contains("/Shared/V3GreenButton.asset")||AssetDatabase.GetAssetPath(i.sprite).EndsWith("/NYC_Cancel.png")||AssetDatabase.GetAssetPath(i.sprite).EndsWith("/CCN_Confirm.png"))).ToArray();
            Assert.IsNotEmpty(actions,key);
            foreach(var image in actions)
            {
                Assert.AreEqual(Image.Type.Sliced,image.type,key+" / "+image.name);
                Assert.Greater(image.sprite.border.x,0);
                Assert.LessOrEqual(image.sprite.border.x/image.pixelsPerUnitMultiplier,24f,"Corner size must not grow with a wide action button.");
            }
        }
    }
}
