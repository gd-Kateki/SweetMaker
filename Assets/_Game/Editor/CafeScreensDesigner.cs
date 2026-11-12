#if UNITY_EDITOR
using System.IO;
using System.Linq;
using TMPro;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.UI;
using Object = UnityEngine.Object;

internal static class CafeScreensDesigner
{
    private const string Folder = "Assets/_Game/Resources/UI/VisualTemplates/";
    private static Sprite Surface => AssetDatabase.LoadAssetAtPath<Sprite>("Assets/_Game/Art/UI_Assets/SettingsRemake/SettingsSurface.png");
    private static readonly Color Ink = new Color(.22f,.16f,.29f), Accent = new Color(.43f,.22f,.62f), Cream = new Color(.97f,.94f,.99f);
    [MenuItem("Tools/Sweet Maker/UI/Edit My Cafe")]
    private static void EditProfile() => Open("CafeProfilePanel");
    [MenuItem("Tools/Sweet Maker/UI/Edit My Cafe Button")]
    private static void EditCard() => Open("CafeProfileCard");
    [MenuItem("Tools/Sweet Maker/UI/Edit Leaderboards")]
    private static void EditBoards() => Open("Leaderboards");
    [MenuItem("Tools/Sweet Maker/UI/Edit Leaderboard Row")]
    private static void EditRow() => Open("LeaderboardRow");
    private static void Open(string key)
    {
        var stage = PrefabStageUtility.OpenPrefab(Folder+key+".prefab");
        foreach(var part in stage.prefabContentsRoot.GetComponentsInChildren<Transform>(true))
            if(part.name == "CafeProfilePanel" || part.name == "Leaderboards" && part.GetComponent<Button>() == null) part.gameObject.SetActive(true);
        Selection.activeGameObject = stage.prefabContentsRoot;
    }
    public static void ImproveVisuals()
    {
        foreach (string key in new[] { "CafeProfileCard", "CafeProfilePanel", "Leaderboards" })
        {
            var root = PrefabUtility.LoadPrefabContents(Folder+key+".prefab");
            try
            {
                foreach (var part in root.GetComponentsInChildren<EditableUIVisual>(true))
                {
                    var image = part.GetComponent<Image>();
                    if (image != null)
                    {
                        image.sprite = Surface; image.type = Image.Type.Sliced;
                        image.color = part.copyButtonStyle ? Accent : part.targetPath == "" && key == "CafeProfilePanel" ? new Color(.1f,.06f,.16f,.85f) : Cream;
                        if (part.name == "CafeImagePlaceholder") image.color = new Color(1,.86f,.53f);
                        if (part.copyButtonStyle)
                        {
                            var colors = part.buttonColors; colors.normalColor = Color.white; colors.highlightedColor = new Color(.94f,.9f,1);
                            colors.pressedColor = new Color(.8f,.8f,.8f); colors.disabledColor = new Color(.55f,.55f,.7f,1); part.buttonColors = colors;
                        }
                    }
                    var text = part.GetComponent<TMP_Text>(); if(text == null) continue;
                    bool button = part.transform.parent.GetComponent<EditableUIVisual>()?.copyButtonStyle == true;
                    Text(text, key == "CafeProfileCard" ? 14 : 22, key == "CafeProfileCard" ? 18 : 28);
                    text.color = button ? Color.white : Ink;
                }
                if (key == "CafeProfilePanel") StyleProfile(root);
                if (key == "Leaderboards") StyleBoards(root);
                var canvas = root.GetComponent<Canvas>(); if(canvas == null)canvas = root.AddComponent<Canvas>(); canvas.renderMode = RenderMode.WorldSpace;
                var rect = (RectTransform)root.transform; rect.anchorMin = rect.anchorMax = new Vector2(.5f,.5f); rect.anchoredPosition = Vector2.zero;
                rect.sizeDelta = key == "CafeProfileCard" ? new Vector2(96,96) : new Vector2(720,1280);
                PrefabUtility.SaveAsPrefabAsset(root, Folder+key+".prefab");
            }
            finally { PrefabUtility.UnloadPrefabContents(root); }
        }
        CreateRow(); RenderPreviews();
    }
    private static void StyleProfile(GameObject root)
    {
        var panel = root.transform.Find("CafeProfilePanel"); Position((RectTransform)panel,.08f,.14f,.92f,.86f);
        Position((RectTransform)panel.Find("CafeName"),.08f,.82f,.92f,.93f); Text(panel.Find("CafeName").GetComponent<TMP_Text>(),28,40,true);
        Position((RectTransform)panel.Find("CafeTitle"),.08f,.75f,.92f,.82f);
        panel.Find("CafeTitle").GetComponent<TMP_Text>().color = Accent;
        var portrait = (RectTransform)panel.Find("CafeImagePlaceholder"); portrait.anchorMin = portrait.anchorMax = new Vector2(.5f,.61f); portrait.anchoredPosition = Vector2.zero; portrait.sizeDelta = new Vector2(160,160);
        Position((RectTransform)panel.Find("CafeStars"),.08f,.43f,.92f,.52f);
        panel.Find("CafeStars").GetComponent<TMP_Text>().color = new Color(.68f,.45f,.04f);
        Position((RectTransform)panel.Find("MoneyEarned"),.10f,.29f,.90f,.39f);
        Position((RectTransform)panel.Find("OrdersCompleted"),.10f,.18f,.90f,.28f);
        Position((RectTransform)panel.Find("Close"),.18f,.055f,.82f,.135f);
        AddStatSurface(panel,"EarningsCard",.28f,.40f); AddStatSurface(panel,"OrdersCard",.17f,.28f);
    }
    private static void AddStatSurface(Transform parent,string name,float bottom,float top)
    {
        if(parent.Find(name)!=null)return;
        var go = new GameObject(name,typeof(RectTransform),typeof(Image)); go.transform.SetParent(parent,false);
        Position((RectTransform)go.transform,.06f,bottom,.94f,top);
        var image=go.GetComponent<Image>(); image.sprite=Surface; image.type=Image.Type.Sliced; image.color=new Color(.91f,.86f,.96f); image.raycastTarget=false; go.transform.SetAsFirstSibling();
    }
    private static void StyleBoards(GameObject root)
    {
        var panel = root.GetComponentsInChildren<EditableUIVisual>(true).Single(t=>t.targetPath.EndsWith("/Leaderboards:1")).transform;
        panel.gameObject.SetActive(true); Position((RectTransform)panel,0,0,1,1);
        var texts = panel.Cast<Transform>().Select(t=>t.GetComponent<TMP_Text>()).Where(t=>t!=null).ToArray();
        Text(texts[0],28,38,true); texts[0].text="Leaderboards";
        Place(texts[1].rectTransform,180,105,24,24); texts[1].text="Your all-time café achievements";
        Place(texts[2].rectTransform,302,44,24,300);
        var totals=texts[3].rectTransform; totals.anchorMin=new Vector2(.55f,1); totals.anchorMax=Vector2.one; totals.offsetMin=new Vector2(0,-346); totals.offsetMax=new Vector2(-24,-302);
        var scroll=(RectTransform)panel.Find("Scroll"); scroll.offsetMax=new Vector2(-24,-356);
        scroll.GetComponent<Image>().color=new Color(.91f,.86f,.96f);
        var layout=scroll.Find("Entries").GetComponent<VerticalLayoutGroup>(); layout.spacing=12; layout.childControlWidth=true; layout.childForceExpandWidth=true;
    }
    private static void CreateRow()
    {
        if(File.Exists(Folder+"LeaderboardRow.prefab")) return;
        var row = new GameObject("LeaderboardRow",typeof(RectTransform),typeof(Image),typeof(LayoutElement),typeof(Canvas));
        try
        {
            row.GetComponent<Canvas>().renderMode=RenderMode.WorldSpace; ((RectTransform)row.transform).sizeDelta=new Vector2(620,112);
            row.GetComponent<LayoutElement>().preferredHeight=112; row.GetComponent<Image>().sprite=Surface; row.GetComponent<Image>().type=Image.Type.Sliced;
            var marker=row.AddComponent<EditableUIVisual>(); marker.targetPath=""; marker.copyLayout=false; marker.copyImageColor=false;
            for(int i=0;i<2;i++)
            {
                var label=new GameObject("Text",typeof(RectTransform),typeof(TextMeshProUGUI)); label.transform.SetParent(row.transform,false);
                Position((RectTransform)label.transform,i==0?.025f:.57f,.08f,i==0?.55f:.975f,.92f);
                var text=label.GetComponent<TMP_Text>(); Text(text,20,26,i==0); text.text=i==0?"#1  Your Café (You)":"$8,500\nRebirth 2"; text.alignment=i==0?TextAlignmentOptions.MidlineLeft:TextAlignmentOptions.MidlineRight;
                label.AddComponent<EditableUIVisual>().targetPath="Text:"+i;
            }
            PrefabUtility.SaveAsPrefabAsset(row,Folder+"LeaderboardRow.prefab");
        }
        finally{Object.DestroyImmediate(row);}
    }
    private static void Text(TMP_Text text,float min,float max,bool bold=false)
    { if(text.font==null)text.font=TMP_Settings.defaultFontAsset; text.fontSizeMin=min; text.fontSizeMax=max; text.fontSize=max; text.enableAutoSizing=true; text.isOrthographic=true; text.color=Ink; if(bold)text.fontStyle=FontStyles.Bold; text.overflowMode=TextOverflowModes.Truncate; text.raycastTarget=false; }
    private static void Place(RectTransform rect,float top,float height,float left,float right)
    {rect.anchorMin=new Vector2(0,1);rect.anchorMax=Vector2.one;rect.offsetMin=new Vector2(left,-top-height);rect.offsetMax=new Vector2(-right,-top);}
    private static void Position(RectTransform r,float x,float y,float right,float top)
    {r.anchorMin=new Vector2(x,y);r.anchorMax=new Vector2(right,top);r.offsetMin=r.offsetMax=Vector2.zero;}
    public static void RenderPreviews()
    {
        var pipeline=GraphicsSettings.defaultRenderPipeline;var quality=QualitySettings.renderPipeline;var previous=RenderTexture.active;
        try
        {
            GraphicsSettings.defaultRenderPipeline=null;QualitySettings.renderPipeline=null;
            foreach(string key in new[]{"CafeProfilePanel","Leaderboards"})
            {
                var root=Object.Instantiate(AssetDatabase.LoadAssetAtPath<GameObject>(Folder+key+".prefab"));var cameraObject=new GameObject("Cafe preview camera",typeof(Camera));var target=new RenderTexture(720,1280,24);target.Create();
                try
                {
                    root.SetActive(true);root.transform.position=Vector3.zero;
                    foreach(var t in root.GetComponentsInChildren<Transform>(true))if(t.name=="CafeProfilePanel"||t.name=="Leaderboards"&&t.GetComponent<Button>()==null)t.gameObject.SetActive(true);
                    if(key=="CafeProfilePanel")
                    {
                        foreach(var t in root.GetComponentsInChildren<TMP_Text>(true))
                        {if(t.name=="CafeName")t.text="Moonlight Café";if(t.name=="CafeTitle")t.text="Growing Business";if(t.name=="CafeStars")t.text="3 / 5 stars";if(t.name=="MoneyEarned")t.text="Money earned   $12,500";if(t.name=="OrdersCompleted")t.text="Orders completed   42";}
                    }
                    else
                    {
                        var entries=root.GetComponentsInChildren<RectTransform>(true).Single(t=>t.name=="Entries");
                        for(int i=0;i<5;i++){var row=Object.Instantiate(AssetDatabase.LoadAssetAtPath<GameObject>(Folder+"LeaderboardRow.prefab"),entries);var labels=row.GetComponentsInChildren<TMP_Text>();labels[0].text="#"+(i+1)+"  "+(i==1?"Moonlight Café (You)":"Café "+(i+1));labels[1].text="$"+((5-i)*8500).ToString("N0")+"\nRebirth "+(5-i);row.GetComponent<Image>().color=i==1?new Color(.85f,.94f,.88f):Color.white;}
                    }
                    foreach(var t in root.GetComponentsInChildren<Transform>(true))t.gameObject.layer=31;
                    var camera=cameraObject.GetComponent<Camera>();camera.transform.position=new Vector3(0,0,-10);camera.orthographic=true;camera.orthographicSize=640;camera.cullingMask=1<<31;camera.clearFlags=CameraClearFlags.SolidColor;camera.backgroundColor=new Color(.16f,.10f,.23f);camera.targetTexture=target;root.GetComponent<Canvas>().worldCamera=camera;
                    Canvas.ForceUpdateCanvases();foreach(var text in root.GetComponentsInChildren<TMP_Text>(true))text.ForceMeshUpdate(true,true);camera.Render();RenderTexture.active=target;
                    var png=new Texture2D(720,1280,TextureFormat.RGBA32,false);try{png.ReadPixels(new Rect(0,0,720,1280),0,0);png.Apply();File.WriteAllBytes("tmp/"+key+"-updated.png",png.EncodeToPNG());}finally{Object.DestroyImmediate(png);}
                }
                finally{RenderTexture.active=previous;target.Release();Object.DestroyImmediate(target);Object.DestroyImmediate(cameraObject);Object.DestroyImmediate(root);}
            }
        }
        finally{GraphicsSettings.defaultRenderPipeline=pipeline;QualitySettings.renderPipeline=quality;RenderTexture.active=previous;}
    }
}
#endif
