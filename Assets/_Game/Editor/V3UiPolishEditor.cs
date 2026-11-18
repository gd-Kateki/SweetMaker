#if UNITY_EDITOR
using System;
using System.IO;
using System.Linq;
using System.Reflection;
using TMPro;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.UI;

// A manual layout pass; never reapplied during startup or import.
internal static class V3UiPolishEditor
{
    private const string Folder="Assets/_Game/Resources/UI/VisualTemplates/";
    private static readonly Color Ink=new Color(.25f,.16f,.12f);
    private static Transform Find(GameObject root,string name)=>root.GetComponentsInChildren<Transform>(true).FirstOrDefault(t=>t.name==name);
    private static void Region(Transform t,float x,float y,float right,float top)
    {if(t is RectTransform r){r.anchorMin=new Vector2(x,y);r.anchorMax=new Vector2(right,top);r.offsetMin=r.offsetMax=Vector2.zero;}}
    private static void Type(Transform t,float min,float max,bool bold=false,bool center=true)
    {
        if(t==null)return;
        foreach(var text in t.GetComponentsInChildren<TMP_Text>(true))
        {
            text.enableAutoSizing=true;text.fontSizeMin=min;text.fontSizeMax=max;text.fontSize=max;
            text.characterSpacing=0;text.lineSpacing=0;text.margin=new Vector4(6,2,6,2);
            text.isOrthographic=true;text.raycastTarget=false;
            if(bold)text.fontStyle|=FontStyles.Bold;
            if(center)text.alignment=TextAlignmentOptions.Center;
        }
    }
    private static void Prefab(string path,Action<GameObject> polish)
    {
        var root=PrefabUtility.LoadPrefabContents(path);
        try{polish(root);PrefabUtility.SaveAsPrefabAsset(root,path);}
        finally{PrefabUtility.UnloadPrefabContents(root);}
    }
    private static void CenterTop(Transform t,Vector2 position,Vector2 size)
    {
        if(!(t is RectTransform r))return;
        r.anchorMin=r.anchorMax=new Vector2(.5f,1);r.pivot=new Vector2(.5f,1);
        r.anchoredPosition=position;r.sizeDelta=size;
    }
    private static void CatalogScrollbar(GameObject root,Transform panel)
    {
        var scroll=Find(root,"CatalogScrollViewport").GetComponent<ScrollRect>();
        var content=scroll.content;var grid=content.GetComponent<GridLayoutGroup>();
        grid.padding=new RectOffset(grid.padding.left,grid.padding.right,grid.padding.top,0);
        var track=panel.Find("V3CatalogScrollbar");
        if(track==null){track=new GameObject("V3CatalogScrollbar",typeof(RectTransform),typeof(Image),typeof(Scrollbar)).transform;track.SetParent(panel,false);}
        Region(track,.943f,.46f,.971f,.775f);
        const string art="Assets/_Game/Art/UI_Assets/UI V3/Dessert_Collection/";
        track.GetComponent<Image>().sprite=AssetDatabase.LoadAllAssetsAtPath(art+"DC_Verticle_Slide.png").OfType<Sprite>().First();
        track.GetComponent<Image>().color=Color.white;
        var handle=track.Find("Handle");
        if(handle==null){handle=new GameObject("Handle",typeof(RectTransform),typeof(Image)).transform;handle.SetParent(track,false);}
        Region(handle,0,.66f,1,1);
        var image=handle.GetComponent<Image>();image.sprite=AssetDatabase.LoadAllAssetsAtPath(art+"DC_Verticle_Bar.png").OfType<Sprite>().First();image.color=Color.white;
        var bar=track.GetComponent<Scrollbar>();bar.direction=Scrollbar.Direction.BottomToTop;bar.handleRect=(RectTransform)handle;bar.targetGraphic=image;
        bar.transition=Selectable.Transition.None;scroll.verticalScrollbar=bar;scroll.verticalScrollbarVisibility=ScrollRect.ScrollbarVisibility.Permanent;
    }
    public static void Apply()
    {
        if(!Application.isBatchMode && !EditorSceneManager.SaveCurrentModifiedScenesIfUserWantsTo())return;
        var setup=EditorSceneManager.GetSceneManagerSetup();
        try
        {
            Prefab(Folder+"SettingsArtwork.prefab",root=>
            {
                CenterTop(Find(root,"V3SettingsTitlePlate"),new Vector2(0,-12),new Vector2(360,110));
                CenterTop(Find(root,"SettingsTitle"),new Vector2(0,-24),new Vector2(320,72));
                Type(Find(root,"SettingsTitle"),32,46,true);
            });
            Prefab(Folder+"CafeNaming.prefab",root=>
            {
                foreach(string name in new[]{"Cancel","Back"}){Region(Find(root,name),.12f,.14f,.43f,.247f);Type(Find(root,name),20,28,true);}
                foreach(string name in new[]{"Continue","Confirm"}){Region(Find(root,name),.57f,.14f,.88f,.247f);Type(Find(root,name),20,28,true);}
                Region(Find(root,"CafeNameInput"),.10f,.36f,.90f,.50f);
                Region(Find(root,"Error"),.10f,.25f,.90f,.35f);Type(Find(root,"Error"),18,22);
                foreach(var t in root.GetComponentsInChildren<TMP_Text>(true).Where(t=>t.name=="Title"))Type(t.transform,28,38,true);
            });
            foreach(string key in new[]{"RewardedEnergy","RewardedCash"})Prefab(Folder+key+".prefab",root=>
            {
                var card=Find(root,"Offer");var labels=card.GetComponentsInChildren<TMP_Text>(true).Where(t=>t.transform.parent==card).ToArray();
                if(labels.Length>0){Region(labels[0].transform,.10f,.78f,.90f,.92f);Type(labels[0].transform,28,38,true);}
                if(labels.Length>1){Region(labels[1].transform,.10f,.58f,.90f,.76f);Type(labels[1].transform,22,28);}
                if(labels.Length>2){Region(labels[2].transform,.10f,.50f,.90f,.57f);Type(labels[2].transform,18,22);}
                Region(Find(root,"Watch Ad"),.24f,.34f,.76f,.495f);Region(Find(root,"No thanks"),.24f,.17f,.76f,.325f);
                Type(Find(root,"Watch Ad"),22,30,true);Type(Find(root,"No thanks"),22,28);
            });
            Prefab(Folder+"StartupWelcome.prefab",root=>
            {
                var card=Find(root,"WelcomeScreen");var status=card.Find("Feedback");
                Region(status,.05f,-.48f,.95f,-.23f);Type(status,18,24);
                status.GetComponent<TMP_Text>().color=Color.white;
                foreach(string name in new[]{"RetryCachedGoogleSessionButton","SwitchAccountButton","RetryStartupButton"})Type(card.Find(name),18,24,true);
            });
            Prefab("Assets/_Game/Prefabs/UI/DessertCollectionRewardRow.prefab",root=>
            {
                Region(Find(root,"MilestoneTitle"),.035f,.50f,.34f,.88f);Type(Find(root,"MilestoneTitle"),18,24,true,false);
                Region(Find(root,"RequirementText"),.035f,.12f,.34f,.48f);Type(Find(root,"RequirementText"),16,20,false,false);
                Region(Find(root,"RewardAmount"),.36f,.15f,.55f,.85f);Type(Find(root,"RewardAmount"),20,26,true);
                Region(Find(root,"RewardStatus"),.56f,.15f,.75f,.85f);Type(Find(root,"RewardStatus"),16,20);
                Region(Find(root,"ClaimButton"),.77f,.20f,.97f,.80f);Type(Find(root,"ClaimButton"),18,24,true);
            });
            Prefab(UpgradeDesignerEditor.CardPath,root=>
            {
                Type(Find(root,"UpgradeNameText"),28,36,true,false);Type(Find(root,"LevelText"),22,28);
                Type(Find(root,"EffectLabelText"),22,28,false,false);Type(Find(root,"ValueText"),24,32,true,false);
                Type(Find(root,"ButtonText"),22,28,true);Type(Find(root,"PriceText"),24,30,true);
            });
            foreach(string sceneName in new[]{"MainBakery","Game"})
            {
                var scene=EditorSceneManager.OpenScene("Assets/_Game/Scenes/"+sceneName+".unity",OpenSceneMode.Single);
                var all=scene.GetRootGameObjects().Where(r=>!r.name.StartsWith("UI Designs")).ToArray();
                foreach(var root in all)
                {
                    var collection=Find(root,"CollectionPanel");
                    if(collection!=null)
                    {
                        Region(collection.parent,.07f,.09f,.93f,.91f);
                        Region(Find(root,"V3CollectionTitlePlate"),.28f,.94f,.72f,1.06f);
                        Region(Find(root,"CollectionTitle"),.29f,.967f,.71f,1.025f);Type(Find(root,"CollectionTitle"),22,30,true);
                        Type(Find(root,"CatalogHeading"),20,26,true,false);Type(Find(root,"RewardHeading"),20,26,true,false);
                        CatalogScrollbar(root,collection);
                    }
                    var dropdown=Find(root,"OvenTierSelectionPanel");
                    if(dropdown!=null)
                    {
                        var title=Find(dropdown.gameObject,"PanelTitle");Type(title,18,24,true);
                        if(title!=null){var text=title.GetComponent<TMP_Text>();text.color=Ink;text.enableVertexGradient=false;}
                        var close=Find(dropdown.gameObject,"CloseButton");
                        if(close!=null){close.GetComponent<Image>().color=Color.white;foreach(var t in close.GetComponentsInChildren<TMP_Text>(true))t.color=Color.clear;}
                    }
                    foreach(string name in new[]{"RebirthRequiredDessertText","RebirthTierProgressText","RebirthCashRequirementText","RebirthEligibilityText"})Type(Find(root,name),24,34);
                    Type(Find(root,"RebirthButton"),24,32,true);
                    var settings=root.GetComponentsInChildren<SettingsScreenPresentation>(true).FirstOrDefault();
                    if(settings!=null)
                    {
                        typeof(SettingsScreenPresentation).GetMethod("ApplyLayout",BindingFlags.Instance|BindingFlags.NonPublic).Invoke(settings,null);
                        var view=settings.GetComponent<EditableUIView>();
                        typeof(EditableUIView).GetMethod("ApplyTemplate",BindingFlags.Instance|BindingFlags.NonPublic).Invoke(view,new object[]{AssetDatabase.LoadAssetAtPath<GameObject>(Folder+"SettingsArtwork.prefab").transform});
                    }
                }
                EditorSceneManager.SaveScene(scene);
            }
            AssetDatabase.SaveAssets();
            V3UiReferencePreview.Render();FirstTimePopupDesigner.RenderPreview();GeneratedUiLibrary.RenderPreviews();
            CafeScreensDesigner.RenderPreviews();UpgradeDesignerEditor.RenderPreviews();SettingsLayoutEditor.RenderPreviews();
            Debug.Log("V3 UI polish: saved editable layouts and rendered previews.");
        }
        finally
        {
            var saved=setup.Where(s=>!string.IsNullOrEmpty(s.path)&&File.Exists(s.path)).ToArray();
            if(saved.Length>0)EditorSceneManager.RestoreSceneManagerSetup(saved);
        }
    }
}
#endif
