using System;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;

public sealed class RemainingGeneratedUiTests
{
    private const string Folder="Assets/_Game/Resources/UI/VisualTemplates/";
    private static GameObject Design(string key)=>AssetDatabase.LoadAssetAtPath<GameObject>(Folder+key+".prefab");
    private static Type Find(string name)=>AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType(name)).First(t=>t!=null);

    [Test]
    public void PreviouslyUncapturedRuntimeViewsHaveEditableNonFunctionalDesigns()
    {
        Find("GeneratedUiLibrary").GetMethod("ValidateLibrary").Invoke(null,null);
    }
    [TestCase("RewardedEnergy")]
    [TestCase("RewardedCash")]
    public void RewardedOffersSeparateExplanationStatusAndTouchTargets(string key)
    {
        var root=Design(key);var offer=(RectTransform)root.GetComponentsInChildren<Transform>(true).Single(t=>t.name=="Offer");
        var labels=offer.Cast<Transform>().Where(t=>t.GetComponent(Find("TMPro.TMP_Text"))!=null).Cast<RectTransform>().ToArray();
        Assert.AreEqual(3,labels.Length);
        var watch=(RectTransform)offer.Find("Watch Ad");var dismiss=(RectTransform)offer.Find("No thanks");
        foreach(var rect in labels.Concat(new[]{watch,dismiss}))Inside(offer.rect,Bounds(rect,offer));
        Assert.LessOrEqual(Bounds(labels[1],offer).yMax,Bounds(labels[0],offer).yMin);
        Assert.LessOrEqual(Bounds(labels[2],offer).yMax,Bounds(labels[1],offer).yMin);
        Assert.LessOrEqual(Bounds(watch,offer).yMax,Bounds(labels[2],offer).yMin);
        Assert.LessOrEqual(Bounds(dismiss,offer).yMax,Bounds(watch,offer).yMin);
        Assert.GreaterOrEqual(watch.rect.height,72);Assert.GreaterOrEqual(dismiss.rect.height,72);
    }
    [Test]
    public void RestoreInstructionsStayInsideTheirRecoveryCard()
    {
        var root=Design("CloudRestoreRestart");var parent=(RectTransform)root.transform.Find("Block input");
        var surface=(RectTransform)parent.Find("RecoverySurface");var text=(RectTransform)parent.Find("Cloud text");
        Inside(Bounds(surface,parent),Bounds(text,parent));
    }
    [Test]
    public void TutorialHighlightCannotCoverOrInterceptItsGameplayTarget()
    {
        var root=Design("TutorialHighlight");var bounds=((RectTransform)root.transform).rect;
        var images=root.GetComponentsInChildren<Image>(true);Assert.AreEqual(4,images.Length);
        foreach(var image in images)
        {
            Assert.IsFalse(image.raycastTarget);
            Assert.Less(image.rectTransform.rect.width*image.rectTransform.rect.height,bounds.width*bounds.height*.15f);
        }
        foreach(var part in root.GetComponentsInChildren(Find("EditableUIVisual"),true))
            Assert.IsFalse((bool)part.GetType().GetField("copyLayout").GetValue(part),"The target-following controller must retain geometry ownership.");
    }
    [Test]
    public void EnergyButtonFitsTheHudAndPreservesLiveArtwork()
    {
        var root=Design("EnergyHUD");var rect=(RectTransform)root.transform;var plus=(RectTransform)root.transform.Find("EnergyPlus");
        Inside(rect.rect,Bounds(plus,rect));
        Assert.GreaterOrEqual(plus.rect.height,44);
        foreach(var image in root.GetComponentsInChildren<Image>(true).Where(i=>i.name!="EnergyPlus"))
        {
            var part=image.GetComponent(Find("EditableUIVisual"));
            Assert.IsFalse((bool)part.GetType().GetField("copyImageSprite").GetValue(part));
        }
    }
    private static Rect Bounds(RectTransform target,RectTransform parent)
    {var corners=new Vector3[4];target.GetWorldCorners(corners);var min=(Vector2)parent.InverseTransformPoint(corners[0]);var max=min;foreach(var c in corners){var p=(Vector2)parent.InverseTransformPoint(c);min=Vector2.Min(min,p);max=Vector2.Max(max,p);}return Rect.MinMaxRect(min.x,min.y,max.x,max.y);}
    private static void Inside(Rect outer,Rect inner)
    {Assert.GreaterOrEqual(inner.xMin,outer.xMin-.1f);Assert.LessOrEqual(inner.xMax,outer.xMax+.1f);Assert.GreaterOrEqual(inner.yMin,outer.yMin-.1f);Assert.LessOrEqual(inner.yMax,outer.yMax+.1f);}
}
