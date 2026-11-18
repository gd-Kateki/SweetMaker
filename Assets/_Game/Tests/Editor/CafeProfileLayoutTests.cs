using NUnit.Framework;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;

public sealed class CafeProfileLayoutTests
{
    [TestCase(720,1280)]
    [TestCase(1080,2400)]
    [TestCase(1600,2560)]
    public void CafeProfileKeepsArtworkProportionsAndSeparatesItsStatistics(int width,int height)
    {
        var prefab=AssetDatabase.LoadAssetAtPath<GameObject>("Assets/_Game/Resources/UI/VisualTemplates/CafeProfilePanel.prefab");
        var root=Object.Instantiate(prefab);
        try
        {
            ((RectTransform)root.transform).sizeDelta=new Vector2(width,height);
            var panel=(RectTransform)root.transform.Find("CafeProfilePanel");
            var image=panel.GetComponent<Image>();
            Assert.AreEqual(Image.Type.Sliced,image.type,"Resize the frame's center rather than stretching its corners.");
            Assert.Greater(image.sprite.border.x,0);Assert.Greater(image.sprite.border.y,0);
            Assert.IsNull(root.GetComponent<Image>().sprite,"The screen shade must have no rounded graphic.");
            Assert.IsNull(panel.Find("EarningsCard"));Assert.IsNull(panel.Find("OrdersCard"));
            Assert.IsNull(panel.Find("CafeStatsSurface").GetComponent<Image>().sprite,"Statistics use a flat surface without stretched pill ends.");
            var portrait=(RectTransform)panel.Find("CafeImagePlaceholder");
            Assert.AreEqual(portrait.rect.width,portrait.rect.height,.01f);
            var close=(RectTransform)panel.Find("Close");Assert.AreEqual(new Vector2(72,80),close.sizeDelta);
            Assert.IsTrue(close.GetComponent<Image>().preserveAspect);
            var money=(RectTransform)panel.Find("MoneyEarned");var orders=(RectTransform)panel.Find("OrdersCompleted");
            Assert.Greater(money.anchorMin.y,orders.anchorMax.y,"Statistic rows must stay separate.");
            foreach(var row in new[]{money,orders})
            {
                Assert.GreaterOrEqual(row.anchorMin.x,.08f);Assert.LessOrEqual(row.anchorMax.x,.92f);
                Assert.GreaterOrEqual(row.anchorMin.y,.10f);Assert.LessOrEqual(row.anchorMax.y,.35f);
            }
        }
        finally{Object.DestroyImmediate(root);}
    }
}
