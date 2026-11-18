#if UNITY_EDITOR
using TMPro;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;

internal static class CafeProfilePolishEditor
{
    private const string Path="Assets/_Game/Resources/UI/VisualTemplates/CafeProfilePanel.prefab";
    private static void Region(Transform t,float left,float bottom,float right,float top)
    {
        var r=(RectTransform)t;r.anchorMin=new Vector2(left,bottom);r.anchorMax=new Vector2(right,top);
        r.offsetMin=r.offsetMax=Vector2.zero;
    }
    private static void Label(Transform t,float min,float max,TextAlignmentOptions alignment)
    {
        var text=t.GetComponent<TMP_Text>();text.enableAutoSizing=true;text.fontSizeMin=min;text.fontSizeMax=max;text.fontSize=max;
        text.alignment=alignment;text.characterSpacing=0;text.margin=new Vector4(8,2,8,2);text.isOrthographic=true;
        text.color=new Color(.25f,.16f,.12f);text.enableVertexGradient=false;
    }
    private static Transform Flat(Transform parent,string name,Color color)
    {
        var t=parent.Find(name);
        if(t==null){t=new GameObject(name,typeof(RectTransform),typeof(Image)).transform;t.SetParent(parent,false);}
        var image=t.GetComponent<Image>();image.sprite=null;image.type=Image.Type.Simple;image.color=color;image.raycastTarget=false;
        t.SetAsFirstSibling();return t;
    }
    public static void Apply()
    {
        var root=PrefabUtility.LoadPrefabContents(Path);
        try
        {
            var shade=root.GetComponent<Image>();shade.sprite=null;shade.color=new Color(.08f,.04f,.12f,.78f);
            var panel=root.transform.Find("CafeProfilePanel");
            Region(panel,.10f,.20f,.90f,.80f);
            var frame=AssetDatabase.LoadAssetAtPath<Sprite>("Assets/_Game/Art/UI_Assets/UI V3/Shared/V3ModalFrame.asset");
            if(frame==null)throw new System.InvalidOperationException("The shared V3 modal frame is missing.");
            var image=panel.GetComponent<Image>();image.sprite=frame;image.type=Image.Type.Sliced;
            image.color=Color.white;image.pixelsPerUnitMultiplier=2.5f;image.preserveAspect=false;
            foreach(string name in new[]{"EarningsCard","OrdersCard"})
            {
                var old=panel.Find(name);
                if(old!=null && old.GetComponent<EditableUIVisual>()==null)Object.DestroyImmediate(old.gameObject);
            }
            var stats=Flat(panel,"CafeStatsSurface",new Color(.98f,.94f,.79f));Region(stats,.08f,.10f,.92f,.35f);
            var rule=Flat(panel,"CafeStatsDivider",new Color(.77f,.62f,.27f,.55f));Region(rule,.12f,.221f,.88f,.223f);
            rule.SetAsLastSibling();
            Region(panel.Find("CafeName"),.08f,.81f,.92f,.92f);Label(panel.Find("CafeName"),26,38,TextAlignmentOptions.Center);
            Region(panel.Find("CafeTitle"),.08f,.74f,.92f,.81f);Label(panel.Find("CafeTitle"),20,26,TextAlignmentOptions.Center);
            panel.Find("CafeTitle").GetComponent<TMP_Text>().color=new Color(.39f,.19f,.55f);
            var portrait=(RectTransform)panel.Find("CafeImagePlaceholder");
            portrait.anchorMin=portrait.anchorMax=new Vector2(.5f,.59f);portrait.pivot=new Vector2(.5f,.5f);
            portrait.anchoredPosition=Vector2.zero;portrait.sizeDelta=new Vector2(144,144);
            var portraitImage=portrait.GetComponent<Image>();portraitImage.sprite=null;portraitImage.color=new Color(1,.86f,.53f);portraitImage.type=Image.Type.Simple;
            Region(panel.Find("CafeStars"),.08f,.41f,.92f,.48f);Label(panel.Find("CafeStars"),20,26,TextAlignmentOptions.Center);
            Region(panel.Find("MoneyEarned"),.12f,.235f,.88f,.315f);Label(panel.Find("MoneyEarned"),20,26,TextAlignmentOptions.MidlineLeft);
            Region(panel.Find("OrdersCompleted"),.12f,.13f,.88f,.21f);Label(panel.Find("OrdersCompleted"),20,26,TextAlignmentOptions.MidlineLeft);
            var close=(RectTransform)panel.Find("Close");
            close.anchorMin=close.anchorMax=Vector2.one;close.pivot=new Vector2(.5f,.5f);
            close.anchoredPosition=new Vector2(-14,-12);close.sizeDelta=new Vector2(72,80);
            close.GetComponent<Image>().preserveAspect=true;
            PrefabUtility.SaveAsPrefabAsset(root,Path);AssetDatabase.SaveAssets();
        }
        finally{PrefabUtility.UnloadPrefabContents(root);}
        CafeScreensDesigner.RenderPreviews();
        Debug.Log("My Cafe: compact sliced frame and flat statistics layout saved.");
    }
}
#endif
