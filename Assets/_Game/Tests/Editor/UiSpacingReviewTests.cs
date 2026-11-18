using System;
using System.Collections.Generic;
using System.Linq;
using NUnit.Framework;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.UI;

public sealed class UiSpacingReviewTests
{
    [TestCase("AdvertisingPrivacy_Unknown",1280)]
    [TestCase("AdvertisingPrivacy_Unknown",1600)]
    [TestCase("AdvertisingPrivacy_Teen",1280)]
    [TestCase("AdvertisingPrivacy_Teen",1600)]
    [TestCase("AdvertisingPrivacy_Adult",1280)]
    [TestCase("AdvertisingPrivacy_Adult",1600)]
    [TestCase("AdvertisingPrivacy_Under13",1280)]
    [TestCase("AdvertisingPrivacy_Under13",1600)]
    [TestCase("AccountDeletion",1280)]
    [TestCase("AccountDeletion",1600)]
    [TestCase("AnalyticsPrompt",1280)]
    [TestCase("AnalyticsPrompt",1600)]
    public void DialogActionsStayOnScreenWithoutOverlapping(string key,int height)
    {
        var root=UnityEngine.Object.Instantiate(AssetDatabase.LoadAssetAtPath<GameObject>("Assets/_Game/Resources/UI/VisualTemplates/"+key+".prefab"));
        try
        {
            root.SetActive(true);root.transform.localScale=Vector3.one;root.transform.position=Vector3.zero;
            var bounds=(RectTransform)root.transform;bounds.sizeDelta=new Vector2(720,height);
            Canvas.ForceUpdateCanvases();bounds.ForceUpdateRectTransforms();
            var markerType=AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType("EditableUIVisual")).First(t=>t!=null);
            var actions=new List<KeyValuePair<string,Rect>>();
            foreach(var marker in root.GetComponentsInChildren(markerType,true))
            {
                if(!(bool)markerType.GetField("copyButtonStyle").GetValue(marker))continue;
                // The full-screen dismiss layer intentionally underlies all dialog actions.
                if(marker.name=="Backdrop")continue;
                bool visible=true;
                for(var t=marker.transform;t!=null;t=t.parent)visible&=t.gameObject.activeSelf;
                if(!visible)continue;
                var rect=(RectTransform)marker.transform;rect.ForceUpdateRectTransforms();
                var corners=new Vector3[4];rect.GetWorldCorners(corners);
                Vector2 min=Vector2.positiveInfinity,max=Vector2.negativeInfinity;
                foreach(var corner in corners)
                {
                    Vector2 local=bounds.InverseTransformPoint(corner);min=Vector2.Min(min,local);max=Vector2.Max(max,local);
                }
                var area=Rect.MinMaxRect(min.x,min.y,max.x,max.y);
                Assert.Greater(area.width,0,marker.name);Assert.Greater(area.height,0,marker.name);
                Assert.GreaterOrEqual(area.xMin,bounds.rect.xMin-.1f,marker.name);Assert.LessOrEqual(area.xMax,bounds.rect.xMax+.1f,marker.name);
                Assert.GreaterOrEqual(area.yMin,bounds.rect.yMin-.1f,marker.name);Assert.LessOrEqual(area.yMax,bounds.rect.yMax+.1f,marker.name);
                foreach(var other in actions)Assert.IsFalse(area.Overlaps(other.Value),marker.name+" overlaps "+other.Key);
                actions.Add(new KeyValuePair<string,Rect>(marker.name,area));
            }
            Assert.IsNotEmpty(actions,key);
            if(key=="AdvertisingPrivacy_Unknown")
            {
                var rows=actions.Where(a=>a.Key=="Under 13"||a.Key=="13–17"||a.Key=="18 or older").OrderByDescending(a=>a.Value.yMin).ToArray();
                Assert.AreEqual(3,rows.Length);
                Assert.AreEqual(rows[0].Value.yMin-rows[1].Value.yMax,rows[1].Value.yMin-rows[2].Value.yMax,.1f,"Age choices need equal gaps.");
                Assert.AreEqual(rows[0].Value.width,rows[2].Value.width,.1f);
            }
        }
        finally{UnityEngine.Object.DestroyImmediate(root);}
    }

    [Test]
    public void OrderDialogBackdropFillsTheCanvasWithoutChangingItsInputBlocker()
    {
        var scene=EditorSceneManager.OpenPreviewScene("Assets/_Game/Scenes/Game.unity");
        try
        {
            var all=scene.GetRootGameObjects().SelectMany(r=>r.GetComponentsInChildren<RectTransform>(true)).ToArray();
            var overlay=all.Single(t=>t.name=="OrderDetailsOverlay");
            Assert.AreEqual(Vector2.zero,overlay.anchorMin);Assert.AreEqual(Vector2.one,overlay.anchorMax);
            Assert.Less(overlay.offsetMin.sqrMagnitude,.001f);Assert.Less(overlay.offsetMax.sqrMagnitude,.001f);
            var shade=overlay.GetComponent<Image>();Assert.IsNotNull(shade);Assert.IsFalse(shade.raycastTarget);
            Assert.Greater(shade.color.a,0);Assert.Less(shade.color.a,1);
            var blocker=all.Single(t=>t.name=="OrderDetailsInputBlocker").GetComponent<Image>();
            Assert.IsTrue(blocker.raycastTarget);Assert.AreEqual(0,blocker.color.a);
        }
        finally{EditorSceneManager.ClosePreviewScene(scene);}
    }
}
