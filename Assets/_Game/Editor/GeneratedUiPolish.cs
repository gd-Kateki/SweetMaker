#if UNITY_EDITOR
using System;
using System.IO;
using System.Linq;
using System.Reflection;
using TMPro;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using Object = UnityEngine.Object;

// Builds design assets through pure UI builders, never through sign-in/ad/save actions.
internal static class GeneratedUiPolish
{
    internal const string Folder="Assets/_Game/Resources/UI/VisualTemplates/";
    private const BindingFlags Private=BindingFlags.Instance|BindingFlags.NonPublic;
    private static readonly Color Ink=new Color(.22f,.16f,.29f), Accent=new Color(.43f,.22f,.62f), Cream=new Color(.97f,.94f,.99f);
    private static Sprite Surface=>AssetDatabase.LoadAssetAtPath<Sprite>("Assets/_Game/Art/UI_Assets/SettingsRemake/SettingsSurface.png");
    private static Type Find(string name)=>AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType(name)).First(t=>t!=null);
    private static void Call(object owner,string method)=>owner.GetType().GetMethod(method,Private).Invoke(owner,null);
    private static GameObject Host(Transform parent,string name,Type type)
    {var root=new GameObject(name,typeof(RectTransform));root.SetActive(false);root.transform.SetParent(parent,false);root.AddComponent(type);return root;}
    private static GameObject CanvasHost(Transform parent,string name)
    {var root=new GameObject(name,typeof(RectTransform),typeof(Canvas),typeof(CanvasScaler));root.transform.SetParent(parent,false);root.GetComponent<Canvas>().renderMode=RenderMode.ScreenSpaceOverlay;root.GetComponent<CanvasScaler>().referenceResolution=new Vector2(1080,1920);return root;}

    public static void UpdateRemainingDesigns()
    {
        CreateMissingDesigns();
        foreach(string key in new[]{"RewardedEnergy","RewardedCash","AccountDeletion","StartupLoading","DevelopmentLoading","StartupDependencyError","AnalyticsPrompt","CloudRestoreRestart"}) Style(key);
        StyleEnergy();
        StyleHighlight();StyleConsole();
        AssetDatabase.SaveAssets();
        RenderPreviews();
    }
    private static void CreateMissingDesigns()
    {
        // Ensure fonts are loaded before invoking the standalone analytics visual builder.
        AssetDatabase.LoadAssetAtPath<TMP_FontAsset>("Assets/TextMesh Pro/Resources/Fonts & Materials/LiberationSans SDF.asset");
        var staging=new GameObject("Generated UI design staging");staging.SetActive(false);
        try
        {
            var parent=CanvasHost(staging.transform,"Design canvas");
            if(!File.Exists(Folder+"AnalyticsPrompt.prefab"))
            {var host=Host(parent.transform,"Analytics builder",Find("SweetMerge.Analytics.AnalyticsConsentPromptController"));Call(host.GetComponent(Find("SweetMerge.Analytics.AnalyticsConsentPromptController")),"TryCreatePrompt");CaptureViews(host);}
            if(!File.Exists(Folder+"DevelopmentLoading.prefab"))
            {
                var type=Find("SweetMerge.Startup.LoadingSceneStartupPresenter");var host=Host(parent.transform,"Loading builder",type);var view=host.GetComponent(type);
                type.GetField("loadingCanvas",Private).SetValue(view,parent.GetComponent<Canvas>());Call(view,"BuildInterface");CaptureViews(host);
            }
            if(!File.Exists(Folder+"AndroidLogConsole.prefab"))
            {var type=Find("AndroidDevelopmentConsole");var host=Host(staging.transform,"Log builder",type);Call(host.GetComponent(type),"BuildUi");CaptureViews(host);}
            if(!File.Exists(Folder+"TutorialHighlight.prefab"))
            {var type=Find("SweetMerge.Profile.HybridTutorialHighlightUI");var host=Host(parent.transform,"Highlight builder",type);Call(host.GetComponent(type),"Awake");CaptureViews(host);}
            if(!File.Exists(Folder+"CloudRestoreRestart.prefab"))
            {
                var root=CanvasHost(staging.transform,"Cloud restore restart");root.GetComponent<CanvasScaler>().referenceResolution=new Vector2(720,1280);
                var background=new GameObject("Block input",typeof(RectTransform),typeof(Image));background.transform.SetParent(root.transform,false);Full((RectTransform)background.transform);
                var label=new GameObject("Cloud text",typeof(RectTransform),typeof(TextMeshProUGUI));label.transform.SetParent(background.transform,false);
                Place((RectTransform)label.transform,350,500,8,8);var text=label.GetComponent<TextMeshProUGUI>();text.font=TMP_Settings.defaultFontAsset;text.fontSize=30;text.alignment=TextAlignmentOptions.Center;
                text.text="Cloud restore is ready.\n\nClose and reopen the game to finish.\n\nYour previous device progress has been preserved for recovery.";
                Capture(root.transform,"CloudRestoreRestart",new Vector2(720,1280));
            }
        }
        finally{Object.DestroyImmediate(staging);}
        CaptureFallback();CaptureEnergy();
    }
    private static void CaptureViews(GameObject host)
    {
        foreach(var view in host.GetComponentsInChildren<EditableUIView>(true))
        {
            if(File.Exists(Folder+view.TemplateKey+".prefab"))continue;
            var scaler=view.GetComponentInParent<CanvasScaler>(true);
            var size=scaler!=null?scaler.referenceResolution:new Vector2(720,1280);
            if(view.TemplateKey=="TutorialHighlight")size=new Vector2(160,160);
            Capture(view.transform,view.TemplateKey,size);
        }
    }
    private static void Capture(Transform source,string key,Vector2 size)
    {
        var clone=EditableUIEditor.CopyVisualTree(source,null,source);
        try
        {
            var canvas=clone.GetComponent<Canvas>();if(canvas==null)canvas=clone.AddComponent<Canvas>();canvas.renderMode=RenderMode.WorldSpace;
            var rect=(RectTransform)clone.transform;rect.anchorMin=rect.anchorMax=new Vector2(.5f,.5f);rect.pivot=new Vector2(.5f,.5f);rect.anchoredPosition=Vector2.zero;rect.sizeDelta=size;
            PrefabUtility.SaveAsPrefabAsset(clone,Folder+key+".prefab");
        }
        finally{Object.DestroyImmediate(clone);}
    }
    private static void CaptureFallback()
    {
        if(File.Exists(Folder+"StartupDependencyError.prefab"))return;
        var original=SceneManager.GetActiveScene();var scene=EditorSceneManager.OpenScene("Assets/_Game/Scenes/Welcome.unity",OpenSceneMode.Additive);
        try
        {
            SceneManager.SetActiveScene(scene);
            Find("SweetMerge.Startup.StartupFlowIntegrationOwner").GetMethod("ShowWelcomeDependencyFallback",BindingFlags.Static|BindingFlags.NonPublic).Invoke(null,new object[]{"Startup services are unavailable. Please retry to continue."});
            var view=scene.GetRootGameObjects().SelectMany(r=>r.GetComponentsInChildren<EditableUIView>(true)).Single(v=>v.TemplateKey=="StartupDependencyError");
            Capture(view.transform,view.TemplateKey,new Vector2(1080,1920));
        }
        finally{SceneManager.SetActiveScene(original);EditorSceneManager.CloseScene(scene,true);}
    }
    private static void CaptureEnergy()
    {
        if(File.Exists(Folder+"EnergyHUD.prefab"))return;
        var scene=EditorSceneManager.OpenPreviewScene("Assets/_Game/Scenes/Game.unity");
        try
        {
            var owner=scene.GetRootGameObjects().SelectMany(r=>r.GetComponentsInChildren<EnergyHudUI>(true)).Single();
            Call(owner,"AddEnergyButton");var root=(RectTransform)typeof(EnergyHudUI).GetField("hudRoot",Private).GetValue(owner);
            var size=root.rect.size;if(size.x<1||size.y<1)size=new Vector2(340,100);
            Capture(root,"EnergyHUD",size);
        }
        finally{EditorSceneManager.ClosePreviewScene(scene);}
    }
    private static void Style(string key)
    {
        var root=PrefabUtility.LoadPrefabContents(Folder+key+".prefab");
        try
        {
            foreach(var part in root.GetComponentsInChildren<EditableUIVisual>(true))
            {
                bool backdrop=part.targetPath==""||part.name=="Shade"||part.name=="Backdrop"||part.name=="Block input";
                var image=part.GetComponent<Image>();
                if(image!=null)
                {
                    if(backdrop)image.color=new Color(.1f,.06f,.16f,.88f);
                    else{image.sprite=Surface;image.type=Image.Type.Sliced;image.color=part.copyButtonStyle?Accent:Cream;}
                    if(part.copyButtonStyle)
                    {var colors=part.buttonColors;colors.normalColor=Color.white;colors.highlightedColor=new Color(.94f,.9f,1);colors.pressedColor=new Color(.8f,.8f,.8f);colors.disabledColor=new Color(.55f,.55f,.7f,1);part.buttonColors=colors;}
                }
                bool button=part.transform.parent!=null&&part.transform.parent.GetComponent<EditableUIVisual>()?.copyButtonStyle==true;
                var text=part.GetComponent<TMP_Text>();
                if(text!=null)
                {
                    bool title=part.name.Contains("Title")||part.name=="Label"&&part.targetPath.EndsWith("/Label:0")&&!button;
                    text.color=button?Color.white:Ink;text.isOrthographic=true;text.enableAutoSizing=true;
                    text.fontSizeMin=Mathf.Max(text.fontSizeMin,title?26:20);text.fontSizeMax=Mathf.Max(text.fontSize,title?36:28);text.fontSize=text.fontSizeMax;
                    if(title||button)text.fontStyle=FontStyles.Bold;
                }
                var legacy=part.GetComponent<Text>();if(legacy!=null){legacy.color=button?Color.white:Ink;legacy.resizeTextForBestFit=true;legacy.resizeTextMinSize=24;legacy.resizeTextMaxSize=legacy.fontSize=Mathf.Max(28,legacy.fontSize);}
            }
            if(key=="RewardedEnergy"||key=="RewardedCash")StyleReward(root);
            if(key=="AccountDeletion")AddSurface(root.GetComponentsInChildren<Transform>(true).Single(t=>t.name=="Privacy content"),"PanelSurface",0,0,1,1);
            if(key=="CloudRestoreRestart")AddSurface(root.transform.Find("Block input"),"RecoverySurface",.07f,.20f,.93f,.80f);
            if(key=="StartupDependencyError")AddSurface(root.transform,"RecoverySurface",.07f,.10f,.93f,.80f);
            if(key=="CloudRestoreRestart")
            {var label=root.GetComponentInChildren<TMP_Text>(true);Place(label.rectTransform,350,500,88,88);}
            if(key=="AccountDeletion")
            {
                var body=root.GetComponentsInChildren<EditableUIVisual>(true).Single(p=>p.targetPath.EndsWith("Privacy%20content:0/Label:1")).GetComponent<TMP_Text>();
                body.alignment=TextAlignmentOptions.TopLeft;body.margin=new Vector4(24,0,24,0);
            }
            if(key=="StartupLoading")
            {var note=root.GetComponentsInChildren<TMP_Text>(true).FirstOrDefault(t=>t.name=="InternetNote");if(note!=null)note.text="Your progress is stored on this device. Sign in to use cloud backup.";}
            if(key=="StartupDependencyError")
            {
                var surface=root.transform.Find("RecoverySurface") as RectTransform;surface.anchorMin=new Vector2(.1f,.28f);surface.anchorMax=new Vector2(.9f,.72f);
                var message=root.GetComponentsInChildren<Text>(true).Single(t=>t.name=="Status");message.rectTransform.anchorMin=new Vector2(.16f,.44f);message.rectTransform.anchorMax=new Vector2(.84f,.65f);message.rectTransform.offsetMin=message.rectTransform.offsetMax=Vector2.zero;message.fontSize=message.resizeTextMaxSize=40;message.resizeTextMinSize=28;
                var button=root.GetComponentsInChildren<EditableUIVisual>(true).Single(p=>p.copyButtonStyle);var rectButton=(RectTransform)button.transform;rectButton.anchorMin=new Vector2(.20f,.32f);rectButton.anchorMax=new Vector2(.80f,.40f);rectButton.offsetMin=rectButton.offsetMax=Vector2.zero;
            }
            var canvas=root.GetComponent<Canvas>();if(canvas==null)canvas=root.AddComponent<Canvas>();canvas.renderMode=RenderMode.WorldSpace;
            var rect=(RectTransform)root.transform;rect.anchorMin=rect.anchorMax=new Vector2(.5f,.5f);rect.anchoredPosition=Vector2.zero;
            if(rect.sizeDelta.x<1||rect.sizeDelta.y<1)rect.sizeDelta=new Vector2(720,1280);
            PrefabUtility.SaveAsPrefabAsset(root,Folder+key+".prefab");
        }
        finally{PrefabUtility.UnloadPrefabContents(root);}
    }
    private static void StyleReward(GameObject root)
    {
        var offer=root.GetComponentsInChildren<Transform>(true).Single(t=>t.name=="Offer");((RectTransform)offer).sizeDelta=new Vector2(620,520);
        var labels=offer.Cast<Transform>().Select(t=>t.GetComponent<TMP_Text>()).Where(t=>t!=null).ToArray();
        Place(labels[0].rectTransform,28,62,28,28);Place(labels[1].rectTransform,104,108,28,28);Place(labels[2].rectTransform,218,68,28,28);
        Place((RectTransform)offer.Find("Watch Ad"),308,80,32,32);Place((RectTransform)offer.Find("No thanks"),410,76,32,32);
        var secondary=offer.Find("No thanks");secondary.GetComponent<Image>().color=new Color(.87f,.82f,.93f);secondary.GetComponentInChildren<TMP_Text>().color=Ink;
    }
    private static void StyleEnergy()
    {
        var root=PrefabUtility.LoadPrefabContents(Folder+"EnergyHUD.prefab");
        try
        {
            ((RectTransform)root.transform).pivot=new Vector2(.5f,.5f);((RectTransform)root.transform).anchoredPosition=Vector2.zero;
            foreach(var image in root.GetComponentsInChildren<Image>(true))
            {var part=image.GetComponent<EditableUIVisual>();if(part!=null&&image.name!="EnergyPlus"){part.copyImageSprite=false;part.copyImageColor=false;}}
            var plus=root.transform.Find("EnergyPlus");var imagePlus=plus.GetComponent<Image>();imagePlus.sprite=Surface;imagePlus.type=Image.Type.Sliced;imagePlus.color=Accent;
            var rect=(RectTransform)plus;rect.pivot=new Vector2(1,.5f);rect.anchoredPosition=new Vector2(-6,0);rect.sizeDelta=new Vector2(48,48);
            plus.GetComponentInChildren<TMP_Text>().color=Color.white;
            PrefabUtility.SaveAsPrefabAsset(root,Folder+"EnergyHUD.prefab");
        }
        finally{PrefabUtility.UnloadPrefabContents(root);}
    }
    private static void StyleHighlight()
    {
        var root=PrefabUtility.LoadPrefabContents(Folder+"TutorialHighlight.prefab");
        try
        {
            for(int i=0;i<4;i++)
            {
                var rect=(RectTransform)root.transform.Find("Edge"+i);
                rect.anchorMin=i==0?new Vector2(0,1):i==3?new Vector2(1,0):Vector2.zero;
                rect.anchorMax=i==1?new Vector2(1,0):i==2?new Vector2(0,1):Vector2.one;
                rect.anchoredPosition=Vector2.zero;rect.sizeDelta=i<2?new Vector2(0,8):new Vector2(8,0);
            }
            foreach(var part in root.GetComponentsInChildren<EditableUIVisual>(true))part.copyLayout=false;
            PrefabUtility.SaveAsPrefabAsset(root,Folder+"TutorialHighlight.prefab");
        }
        finally{PrefabUtility.UnloadPrefabContents(root);}
    }
    private static void StyleConsole()
    {
        var root=PrefabUtility.LoadPrefabContents(Folder+"AndroidLogConsole.prefab");
        try
        {
            root.transform.Find("Safe Area/Log Panel").GetComponent<Image>().color=new Color(.06f,.07f,.09f,1);
            foreach(var part in root.GetComponentsInChildren<EditableUIVisual>(true))
            {
                if(!part.copyButtonStyle)continue;
                var image=part.GetComponent<Image>();image.sprite=Surface;image.type=Image.Type.Sliced;image.color=Accent;
                var label=part.GetComponentInChildren<TMP_Text>(true);if(label!=null)label.color=Color.white;
            }
            PrefabUtility.SaveAsPrefabAsset(root,Folder+"AndroidLogConsole.prefab");
        }
        finally{PrefabUtility.UnloadPrefabContents(root);}
    }
    private static void AddSurface(Transform parent,string name,float x,float y,float right,float top)
    {
        if(parent.Find(name)!=null)return;
        var go=new GameObject(name,typeof(RectTransform),typeof(Image));go.transform.SetParent(parent,false);
        var rect=(RectTransform)go.transform;rect.anchorMin=new Vector2(x,y);rect.anchorMax=new Vector2(right,top);rect.offsetMin=rect.offsetMax=Vector2.zero;
        var image=go.GetComponent<Image>();image.sprite=Surface;image.type=Image.Type.Sliced;image.color=Cream;image.raycastTarget=false;go.transform.SetAsFirstSibling();
    }
    private static void Full(RectTransform rect){rect.anchorMin=Vector2.zero;rect.anchorMax=Vector2.one;rect.offsetMin=rect.offsetMax=Vector2.zero;}
    private static void Place(RectTransform rect,float top,float height,float left,float right)
    {rect.anchorMin=new Vector2(0,1);rect.anchorMax=Vector2.one;rect.offsetMin=new Vector2(left,-top-height);rect.offsetMax=new Vector2(-right,-top);}
    public static void RenderPreviews()=>GeneratedUiLibrary.RenderPreviews();
}
#endif
