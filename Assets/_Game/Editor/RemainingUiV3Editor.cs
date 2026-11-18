#if UNITY_EDITOR
using System;
using System.IO;
using System.Linq;
using TMPro;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.UI;
using Object=UnityEngine.Object;

// One-shot art/layout migration. Gameplay actions, live text and modal ownership stay with their controllers.
internal static class RemainingUiV3Editor
{
    private const string Templates="Assets/_Game/Resources/UI/VisualTemplates/";
    private const string Art="Assets/_Game/Art/UI_Assets/UI V3/";
    private const string Shared=Art+"Shared/";
    private static readonly Color Ink=new Color(.25f,.16f,.12f), Purple=new Color(.39f,.19f,.55f), Shade=new Color(.08f,.04f,.12f,.78f);
    internal static readonly string[] Keys={"Leaderboards","LeaderboardRow","TutorialWelcome","TutorialWelcomeBackdrop","TutorialInstruction","TutorialRecovery","TutorialHighlight","CloudProgressChoice","CloudRestoreRestart","AccountDeletion","FeatureIntroduction","StartupDependencyError","AdvertisingPrivacy_Unknown","AdvertisingPrivacy_Teen","AdvertisingPrivacy_Adult","AdvertisingPrivacy_Under13","DeveloperCheatsV2","DeveloperButtonV2","AndroidLogConsole"};
    private static Sprite Sprite(string path)=>AssetDatabase.LoadAllAssetsAtPath(Art+path+".png").OfType<Sprite>().First();
    private static Sprite Slice(string name,string source,Vector4 border)
    {
        string path=Shared+name+".asset";var sprite=AssetDatabase.LoadAssetAtPath<Sprite>(path);
        if(sprite!=null)return sprite;
        var original=Sprite(source);
        sprite=UnityEngine.Sprite.Create(original.texture,original.rect,new Vector2(.5f,.5f),100,0,SpriteMeshType.FullRect,border);
        sprite.name=name;AssetDatabase.CreateAsset(sprite,path);return sprite;
    }
    private static Sprite Frame,Surface,Gold,Green,Red,Violet;
    private static void LoadArt()
    {
        if(!AssetDatabase.IsValidFolder(Shared.TrimEnd('/')))AssetDatabase.CreateFolder(Art.TrimEnd('/'),"Shared");
        Frame=Slice("V3ModalFrame","Name_Your_Cafe/NYC_Backplate",new Vector4(105,140,105,100));
        Surface=Slice("V3CreamPanel","Dessert_Collection/DC_Discovery_Plate",new Vector4(38,38,38,38));
        Gold=Slice("V3GoldButton","Cafe_Bonus/CB_Watch_Ad",new Vector4(24,34,24,24));
        Green=Slice("V3GreenButton","Confirm_Cafe_Name/CCN_Confirm",new Vector4(40,24,40,24));
        Red=Slice("V3RedButton","Name_Your_Cafe/NYC_Cancel",new Vector4(40,24,40,24));
        Violet=Slice("V3PurpleButton","Recycle_Dessert_Screen/RD_Cancel_Button",new Vector4(40,24,40,24));
    }
    private static void Paint(Image image,Sprite sprite,Color? tint=null)
    {
        if(image==null)return;
        image.sprite=sprite;image.type=Image.Type.Sliced;image.preserveAspect=false;
        image.pixelsPerUnitMultiplier=sprite==Frame?2.5f:2;image.color=tint??Color.white;
    }
    private static Transform Find(GameObject root,string name)=>root.GetComponentsInChildren<Transform>(true).FirstOrDefault(t=>t.name==name);
    private static void Region(Transform t,float x,float y,float right,float top)
    {if(t is RectTransform r){r.anchorMin=new Vector2(x,y);r.anchorMax=new Vector2(right,top);r.offsetMin=r.offsetMax=Vector2.zero;}}
    private static void Typography(TMP_Text text,bool button=false)
    {
        text.color=Ink;text.isOrthographic=true;text.characterSpacing=0;text.lineSpacing=0;text.raycastTarget=false;
        if(button){text.enableVertexGradient=false;text.alignment=TextAlignmentOptions.Center;text.margin=new Vector4(12,4,12,8);text.enableAutoSizing=true;text.fontSizeMin=18;text.fontSizeMax=26;}
    }
    private static void ButtonArt(Transform t,string key)
    {
        var marker=t.GetComponent<EditableUIVisual>();
        string name=t.name;
        bool destructive=name.IndexOf("Reset",StringComparison.OrdinalIgnoreCase)>=0 || name.Contains("CLEAR BOARD");
        bool positive=name.Contains("Restore Cloud")||name=="ContinueButton"||name=="GotItButton"||name=="RetryButton";
        Paint(t.GetComponent<Image>(),destructive?Red:positive?Green:name=="Back"||name=="Previous"?Violet:Gold);
        if(marker!=null)
        {
            var c=marker.buttonColors;c.normalColor=c.highlightedColor=Color.white;c.pressedColor=new Color(.85f,.84f,.80f);c.disabledColor=new Color(.65f,.63f,.60f,.8f);marker.buttonColors=c;
        }
        foreach(var text in t.GetComponentsInChildren<TMP_Text>(true))Typography(text,true);
        foreach(var text in t.GetComponentsInChildren<Text>(true)){text.color=Ink;text.alignment=TextAnchor.MiddleCenter;}
    }
    private static void Decor(Transform parent,string name,Sprite sprite,float x,float y,float right,float top)
    {
        var child=parent.Find(name);
        if(child==null){child=new GameObject(name,typeof(RectTransform),typeof(Image)).transform;child.SetParent(parent,false);}
        Paint(child.GetComponent<Image>(),sprite);child.GetComponent<Image>().raycastTarget=false;
        Region(child,x,y,right,top);child.SetAsFirstSibling();
    }
    private static void Style(string key)
    {
        var root=PrefabUtility.LoadPrefabContents(Templates+key+".prefab");
        try
        {
            bool lab=key=="DeveloperCheatsV2",console=key=="AndroidLogConsole";
            if(lab)
            {
                // Match the current control name; keep the command and its listeners on the live UI.
                foreach(var t in root.GetComponentsInChildren<Transform>(true))if(t.name=="APPLY REBIRTH")t.name="APPLY PRESTIGE";
                foreach(var part in root.GetComponentsInChildren<EditableUIVisual>(true))part.targetPath=part.targetPath.Replace("APPLY%20REBIRTH","APPLY%20PRESTIGE");
            }
            foreach(var text in root.GetComponentsInChildren<TMP_Text>(true))
            {
                if(console)continue;
                if(lab && text.GetComponentsInParent<Transform>(true).Any(t=>t.name=="Action feedback"))continue;
                Typography(text);
            }
            foreach(var marker in root.GetComponentsInChildren<EditableUIVisual>(true))
            {
                var image=marker.GetComponent<Image>();
                if(marker.copyButtonStyle){ButtonArt(marker.transform,key);continue;}
                if(image==null)continue;
                string name=marker.name;
                if(name=="Shade"||name=="Backdrop"||name=="Background"||name=="Block input"||(marker.targetPath=="" && (key=="FeatureIntroduction"||key=="DeveloperCheatsV2"||key=="TutorialWelcomeBackdrop")))
                {image.sprite=null;image.color=Shade;continue;}
                if(name=="PopupSurface"||name=="PanelSurface"||name=="RecoverySurface"||name=="Cloud choice card"||name=="FeatureIntroductionCard"||name=="Testing workspace")Paint(image,Frame);
                if(name=="Scroll" && key=="Leaderboards")Paint(image,Surface);
                if(key=="LeaderboardRow")Paint(image,Surface);
                if((key=="TutorialWelcome"||key=="TutorialRecovery") && marker.targetPath=="")Paint(image,Frame);
                if(key=="TutorialInstruction" && marker.targetPath=="")Paint(image,Surface);
                if(key=="TutorialHighlight" && name.StartsWith("Edge"))image.color=new Color(1,.85f,.25f);
                if(lab && name=="Custom Cash Amount")Paint(image,Surface);
            }
            // Some artist-authored background children are decorations rather than bindings.
            foreach(string name in new[]{"PopupSurface","PanelSurface","RecoverySurface"})
            {var t=Find(root,name);if(t!=null)Paint(t.GetComponent<Image>(),Frame);}
            if(key.StartsWith("AdvertisingPrivacy_")||key=="AccountDeletion")
            {
                var content=Find(root,"Privacy content");Region(content,.055f,.065f,.945f,.935f);
                foreach(Transform child in content)
                {
                    var part=child.GetComponent<EditableUIVisual>();
                    if(part==null)continue;
                    if(child.GetComponent<TMP_Text>()!=null||part.copyButtonStyle)
                    {
                        var r=(RectTransform)child;r.offsetMin=new Vector2(42,r.offsetMin.y);r.offsetMax=new Vector2(-42,r.offsetMax.y);
                    }
                }
                var title=content.Cast<Transform>().FirstOrDefault(t=>t.GetComponent<TMP_Text>()!=null);
                if(title!=null){Region(title,.10f,.895f,.90f,.96f);title.GetComponent<TMP_Text>().fontStyle|=FontStyles.Bold;title.GetComponent<TMP_Text>().color=Purple;}
                if(key.StartsWith("AdvertisingPrivacy_"))Region(content.Find("Privacy policy"),.07f,.055f,.93f,.12f);
            }
            if(key=="TutorialWelcome")
            {
                Region(Find(root,"ContinueButton"),.16f,.09f,.84f,.20f);
                var title=Find(root,"Title").GetComponent<TMP_Text>();title.color=Purple;
                var illustration=Find(root,"CafeIllustration");
                foreach(var graphic in illustration.GetComponentsInChildren<Graphic>(true))graphic.color=Color.clear;
                var oven=illustration.Find("V3OvenIllustration");
                if(oven==null){oven=new GameObject("V3OvenIllustration",typeof(RectTransform),typeof(Image)).transform;oven.SetParent(illustration,false);}
                var ovenImage=oven.GetComponent<Image>();ovenImage.sprite=Sprite("Play_Screen/PS_Oven");ovenImage.color=Color.white;ovenImage.preserveAspect=true;ovenImage.raycastTarget=false;
                Region(oven,.16f,0,.84f,1);
            }
            if(key=="TutorialInstruction")
            {var heading=Find(root,"TipHeading");if(heading!=null)heading.GetComponent<TMP_Text>().color=Purple;}
            if(key=="TutorialRecovery")
            {
                // This is a compact in-game banner, not a full modal; keep the retry inside its surface.
                Paint(root.GetComponent<Image>(),Surface);
                Region(Find(root,"RecoveryText"),.08f,.43f,.92f,.94f);
                Region(Find(root,"RetryButton"),.18f,.12f,.82f,.38f);
            }
            if(key=="FeatureIntroduction")
            {
                var card=Find(root,"FeatureIntroductionCard");var layout=card.GetComponent<VerticalLayoutGroup>();
                if(layout!=null){layout.padding=new RectOffset(42,42,38,64);layout.spacing=20;}
                Find(root,"Title").GetComponent<TMP_Text>().color=Purple;
            }
            if(key=="CloudProgressChoice")
            {
                var card=(RectTransform)Find(root,"Cloud choice card");
                card.anchorMin=new Vector2(.07f,.5f);card.anchorMax=new Vector2(.93f,.5f);card.sizeDelta=new Vector2(0,650);card.anchoredPosition=Vector2.zero;
                foreach(Transform child in card)
                {
                    var r=child as RectTransform;if(r==null)continue;
                    r.offsetMin=new Vector2(48,r.offsetMin.y);r.offsetMax=new Vector2(-48,r.offsetMax.y);
                }
            }
            if(key=="CloudRestoreRestart")
            {
                var text=Find(root,"Cloud text").GetComponent<TMP_Text>();Region(text.transform,.14f,.24f,.86f,.69f);text.fontSizeMin=22;text.fontSizeMax=30;text.enableAutoSizing=true;
            }
            if(key=="Leaderboards")Boards(root);
            if(lab)
            {
                var feedback=Find(root,"Action feedback");if(feedback!=null)feedback.GetComponent<Image>().color=new Color(.13f,.10f,.18f);
                var viewport=Find(root,"Viewport");if(viewport!=null)viewport.GetComponent<Image>().color=new Color(1,.96f,.78f,.4f);
            }
            if(console)
            {
                var panel=Find(root,"Log Panel");panel.GetComponent<Image>().color=new Color(.09f,.07f,.12f,.98f);
                // Keep the diagnostic text's severity colors on the dark log surface.
                var scroll=Find(root,"Scroll View");if(scroll!=null)scroll.GetComponent<Image>().color=new Color(.06f,.05f,.08f);
            }
            PrefabUtility.SaveAsPrefabAsset(root,Templates+key+".prefab");
        }
        finally{PrefabUtility.UnloadPrefabContents(root);}
    }
    private static void Boards(GameObject root)
    {
        var panel=root.GetComponentsInChildren<EditableUIVisual>(true).First(p=>p.name=="Leaderboards"&&p.GetComponent<Image>()!=null&&!p.copyButtonStyle&&p.targetPath!="").transform;
        panel.GetComponent<Image>().sprite=null;panel.GetComponent<Image>().color=Shade;
        Decor(panel,"V3LeaderboardFrame",Frame,.035f,.04f,.965f,.96f);
        var labels=panel.Cast<Transform>().Where(t=>t.GetComponent<TMP_Text>()!=null).ToArray();
        Region(labels[0],.10f,.86f,.78f,.93f);labels[0].GetComponent<TMP_Text>().color=Purple;
        Region(labels[1],.10f,.665f,.90f,.755f);
        Region(labels[2],.10f,.62f,.54f,.66f);Region(labels[3],.56f,.62f,.90f,.66f);
        Region(panel.Find("Money earned"),.09f,.77f,.49f,.83f);Region(panel.Find("Orders completed"),.51f,.77f,.91f,.83f);
        Region(panel.Find("Scroll"),.08f,.15f,.92f,.61f);
        Region(panel.Find("Previous"),.09f,.075f,.345f,.13f);Region(panel.Find("Refresh"),.372f,.075f,.627f,.13f);Region(panel.Find("Next"),.655f,.075f,.91f,.13f);
        var close=panel.Find("Close");Region(close,.84f,.86f,.94f,.93f);
        var image=close.GetComponent<Image>();image.sprite=Sprite("Dessert_Collection/DC_Cancel");image.type=Image.Type.Simple;image.preserveAspect=true;
        foreach(var text in close.GetComponentsInChildren<TMP_Text>(true))text.color=Color.clear;
    }
    public static void Apply()
    {
        if(!Application.isBatchMode&&!EditorSceneManager.SaveCurrentModifiedScenesIfUserWantsTo())return;
        LoadArt();foreach(string key in Keys)Style(key);
        foreach(string sceneName in new[]{"MainBakery","Game"})
        {
            var scene=EditorSceneManager.OpenScene("Assets/_Game/Scenes/"+sceneName+".unity");
            foreach(var root in scene.GetRootGameObjects().Where(r=>!r.CompareTag("EditorOnly")&&!r.name.StartsWith("UI Designs")))
            foreach(string name in new[]{"OrderDetailsPanel","CampaignCompletionPanel"})
            {
                var panel=Find(root,name);if(panel==null)continue;Paint(panel.GetComponent<Image>(),Frame);
                foreach(var text in panel.GetComponentsInChildren<TMP_Text>(true))Typography(text);
                foreach(var button in panel.GetComponentsInChildren<Button>(true))
                {
                    Paint(button.GetComponent<Image>(),button.name.Contains("Confirm")?Green:Gold);
                    var c=button.colors;c.normalColor=c.highlightedColor=Color.white;c.pressedColor=new Color(.85f,.84f,.8f);button.colors=c;
                    foreach(var text in button.GetComponentsInChildren<TMP_Text>(true))Typography(text,true);
                }
                if(name=="OrderDetailsPanel")
                {
                    var rect=(RectTransform)panel;rect.sizeDelta=new Vector2(750,900);
                    Paint(panel.GetComponent<Image>()??panel.gameObject.AddComponent<Image>(),Frame);
                    foreach(Transform child in panel)if(child.GetComponent<RawImage>() is RawImage paper)paper.enabled=false;
                    var requirements=(RectTransform)Find(panel.gameObject,"RequirementsContainer");requirements.anchoredPosition=new Vector2(0,85);requirements.sizeDelta=new Vector2(680,300);
                    ((RectTransform)Find(panel.gameObject,"RewardContainer")).anchoredPosition=new Vector2(0,-170);
                    ((RectTransform)Find(panel.gameObject,"ConfirmButton")).anchoredPosition=new Vector2(0,-330);
                    var close=Find(panel.gameObject,"CloseButton");var cr=(RectTransform)close;
                    cr.anchorMin=cr.anchorMax=new Vector2(.5f,.5f);cr.anchoredPosition=new Vector2(320,370);cr.sizeDelta=new Vector2(80,90);
                    close.GetComponent<Image>().sprite=Sprite("Dessert_Collection/DC_Cancel");close.GetComponent<Image>().type=Image.Type.Simple;close.GetComponent<Image>().preserveAspect=true;
                    foreach(var text in close.GetComponentsInChildren<TMP_Text>(true))text.color=Color.clear;
                }
                if(name=="CampaignCompletionPanel")
                {
                    var message=Find(panel.gameObject,"CampaignCompletionMessage").GetComponent<TMP_Text>();message.text=message.text.Replace("#FFD176","#6C3596");
                    Region(Find(panel.gameObject,"ContinuePlayingButton"),.28f,.12f,.72f,.24f);
                }
            }
            EditorSceneManager.SaveScene(scene);
        }
        AssetDatabase.SaveAssets();Render();Debug.Log("Remaining UIs: V3 integration saved and previews rendered.");
    }
    public static void Render()
    {
        var pipeline=GraphicsSettings.defaultRenderPipeline;var quality=QualitySettings.renderPipeline;
        try
        {
            GraphicsSettings.defaultRenderPipeline=null;QualitySettings.renderPipeline=null;
            foreach(string key in Keys.Where(k=>k!="TutorialHighlight"&&k!="TutorialWelcomeBackdrop"))RenderOne(key);
            RenderOne("DeveloperCheatsV2",true);CafeScreensDesigner.RenderPreviews();V3UiReferencePreview.Render();
        }
        finally{GraphicsSettings.defaultRenderPipeline=pipeline;QualitySettings.renderPipeline=quality;}
    }
    private static void RenderOne(string key,bool services=false)
    {
        var root=Object.Instantiate(AssetDatabase.LoadAssetAtPath<GameObject>(Templates+key+".prefab"));
        var cameraObject=new GameObject("Remaining UI preview",typeof(Camera));var target=new RenderTexture(720,1280,24);target.Create();var previous=RenderTexture.active;
        try
        {
            root.SetActive(true);root.transform.position=Vector3.zero;
            var canvas=root.GetComponent<Canvas>();
            if(canvas==null)canvas=root.AddComponent<Canvas>();canvas.renderMode=RenderMode.WorldSpace;
            var rootRect=(RectTransform)root.transform;
            if(rootRect.rect.width<1||rootRect.rect.height<1){rootRect.anchorMin=rootRect.anchorMax=new Vector2(.5f,.5f);rootRect.sizeDelta=new Vector2(720,1280);rootRect.anchoredPosition=Vector2.zero;}
            if(key=="AndroidLogConsole")Find(root,"Log Panel").gameObject.SetActive(true);
            if(key=="TutorialRecovery")Find(root,"RecoveryText").GetComponent<TMP_Text>().text="Your progress could not be saved. Please try again.";
            if(key=="DeveloperCheatsV2"&&services)
                foreach(var t in root.GetComponentsInChildren<Transform>(true).Where(t=>t.parent!=null&&t.parent.name=="Content"))t.gameObject.SetActive(t.name=="Services");
            if(key=="CloudProgressChoice")
            {
                Find(root,"Restore Cloud Progress").gameObject.SetActive(true);Find(root,"Start New Game").gameObject.SetActive(true);
                Find(root,"Retry Cloud Check").gameObject.SetActive(false);Find(root,"Back").gameObject.SetActive(false);
                var card=Find(root,"Cloud choice card");var labels=card.Cast<Transform>().Where(t=>t.GetComponent<TMP_Text>()!=null).Select(t=>t.GetComponent<TMP_Text>()).ToArray();
                labels[0].text="Welcome back!";labels[1].text="A saved café was found in the cloud.\n\nRestore your café, or choose a new game.";
            }
            if(key=="CloudRestoreRestart")Find(root,"Cloud text").GetComponent<TMP_Text>().text="Cloud restore is ready.\n\nClose and reopen the game to finish.\n\nYour previous device progress has been preserved for recovery.";
            foreach(var t in root.GetComponentsInChildren<Transform>(true))t.gameObject.layer=31;
            var size=((RectTransform)root.transform).rect.size;var camera=cameraObject.GetComponent<Camera>();
            camera.transform.position=new Vector3(0,0,-10);camera.orthographic=true;camera.orthographicSize=Mathf.Max(640,Mathf.Max(size.y,size.x/(720f/1280f))*.5f);camera.cullingMask=1<<31;
            camera.clearFlags=CameraClearFlags.SolidColor;camera.backgroundColor=new Color(.16f,.10f,.23f);camera.targetTexture=target;canvas.worldCamera=camera;
            Canvas.ForceUpdateCanvases();foreach(var t in root.GetComponentsInChildren<TMP_Text>(true)){t.isOrthographic=true;t.ForceMeshUpdate(true,true);}
            camera.Render();RenderTexture.active=target;var png=new Texture2D(720,1280,TextureFormat.RGBA32,false);
            try{png.ReadPixels(new Rect(0,0,720,1280),0,0);png.Apply();Directory.CreateDirectory("tmp");File.WriteAllBytes("tmp/remaining-v3-"+key+(services?"-services":"")+".png",png.EncodeToPNG());}
            finally{Object.DestroyImmediate(png);}
        }
        finally{RenderTexture.active=previous;cameraObject.GetComponent<Camera>().targetTexture=null;target.Release();Object.DestroyImmediate(target);Object.DestroyImmediate(cameraObject);Object.DestroyImmediate(root);}
    }
}
#endif
