#if UNITY_EDITOR
using System;
using System.IO;
using System.Linq;
using TMPro;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.UI;

// Explicit, one-shot art migration. Never runs automatically on import or play.
internal static class V3UiReferenceEditor
{
    private const string Art = "Assets/_Game/Art/UI_Assets/UI V3/";
    private const string Templates = "Assets/_Game/Resources/UI/VisualTemplates/";
    private static readonly Color Ink = new Color(.25f,.16f,.12f);
    private static Sprite Sprite(string path) => AssetDatabase.LoadAllAssetsAtPath(Art+path+".png").OfType<Sprite>().First();
    private static Transform Find(GameObject root, string name) => root.GetComponentsInChildren<Transform>(true).FirstOrDefault(t=>t.name==name);
    private static bool Protected(Transform t)
    {
        for (;t!=null;t=t.parent)
            if(t.name=="EnergyPlus" || t.name.StartsWith("UI Designs") || t.CompareTag("EditorOnly")) return true;
        return false;
    }
    private static UnityEngine.Object Replacement(UnityEngine.Object old, bool texture=false)
    {
        if(old==null)return null;
        string path=AssetDatabase.GetAssetPath(old);
        foreach(string version in new[]{"UI V1/","UI V2/"})
        {
            int index=path.IndexOf(version,StringComparison.Ordinal);
            if(index<0)continue;
            string candidate=Art+path.Substring(index+version.Length);
            if(File.Exists(candidate))return texture ? AssetDatabase.LoadAssetAtPath<Texture>(candidate) : AssetDatabase.LoadAllAssetsAtPath(candidate).OfType<Sprite>().FirstOrDefault();
        }
        return null;
    }
    private static void Swap(GameObject root)
    {
        foreach(var image in root.GetComponentsInChildren<Image>(true))
            if(!Protected(image.transform) && Replacement(image.sprite) is Sprite sprite)image.sprite=sprite;
        foreach(var image in root.GetComponentsInChildren<RawImage>(true))
            if(!Protected(image.transform) && Replacement(image.texture,true) is Texture texture)image.texture=texture;
        foreach(var image in root.GetComponentsInChildren<SpriteRenderer>(true))
            if(!Protected(image.transform) && Replacement(image.sprite) is Sprite sprite)image.sprite=sprite;
    }
    private static void Paint(Transform t,string path)
    {
        if(t==null)return;
        var image=t.GetComponent<Image>();if(image==null)return;
        image.sprite=Sprite(path);image.color=Color.white;image.type=Image.Type.Simple;
        // Matched reference regions retain the source aspect; exact-size HUD sprites retain their authored layout.
        image.preserveAspect=false;
        var marker=t.GetComponent<EditableUIVisual>();
        if(marker!=null && marker.copyButtonStyle)
        {
            var c=marker.buttonColors;c.normalColor=c.highlightedColor=Color.white;
            c.pressedColor=new Color(.85f,.85f,.85f);c.disabledColor=new Color(.65f,.65f,.65f);
            marker.buttonColors=c;
        }
    }
    private static void Region(Transform t,float x,float y,float right,float top)
    {
        if(!(t is RectTransform r))return;
        r.anchorMin=new Vector2(x,y);r.anchorMax=new Vector2(right,top);r.offsetMin=r.offsetMax=Vector2.zero;
    }
    private static void TextInk(Transform t)
    {
        if(t==null)return;
        foreach(var text in t.GetComponentsInChildren<TMP_Text>(true))
        {
            if(text.name.IndexOf("Error",StringComparison.OrdinalIgnoreCase)>=0)continue;
            text.color=Ink;text.enableVertexGradient=false;text.isOrthographic=true;
        }
    }
    private static void HideLabel(Transform t)
    {
        if(t==null)return;
        foreach(var label in t.GetComponentsInChildren<TMP_Text>(true))label.color=Color.clear;
    }
    private static Transform Decoration(Transform parent,string name,string sprite,float x,float y,float right,float top)
    {
        var child=parent.Find(name);
        if(child==null){child=new GameObject(name,typeof(RectTransform),typeof(Image)).transform;child.SetParent(parent,false);}
        child.gameObject.SetActive(true);child.GetComponent<Image>().raycastTarget=false;
        Paint(child,sprite);Region(child,x,y,right,top);return child;
    }
    private static void Template(string key)
    {
        string path=Templates+key+".prefab";
        var root=PrefabUtility.LoadPrefabContents(path);
        try
        {
            Swap(root);
            if(key=="CafeNaming")
            {
                var card=Find(root,"CafeNamingPopup");Paint(card,"Name_Your_Cafe/NYC_Backplate");Region(card,.08f,.285f,.92f,.715f);TextInk(card);
                Paint(Find(root,"CafeNameInput"),"Name_Your_Cafe/NYC_Insert_Name");
                foreach(string name in new[]{"Cancel","Back"})Paint(Find(root,name),"Name_Your_Cafe/NYC_Cancel");
                foreach(string name in new[]{"Continue","Confirm"})Paint(Find(root,name),"Confirm_Cafe_Name/CCN_Confirm");
            }
            if(key.StartsWith("Rewarded"))
            {
                var card=Find(root,"Offer");Paint(card,"Cafe_Bonus/CB_Rebirth--copy");Region(card,.08f,.285f,.92f,.715f);TextInk(card);
                var watch=Find(root,"Watch Ad");var dismiss=Find(root,"No thanks");
                Paint(watch,"Cafe_Bonus/CB_Watch_Ad");Paint(dismiss,"Cafe_Bonus/CB_No_Thanks");
                Region(watch,.22f,.27f,.78f,.43f);Region(dismiss,.22f,.09f,.78f,.25f);
                var labels=card.GetComponentsInChildren<TMP_Text>(true).Where(t=>t.transform.parent==card).ToArray();
                if(labels.Length>0)Region(labels[0].transform,.10f,.78f,.90f,.93f);
                if(labels.Length>1)Region(labels[1].transform,.10f,.56f,.90f,.77f);
                if(labels.Length>2)Region(labels[2].transform,.10f,.44f,.90f,.55f);
            }
            if(key=="AnalyticsPrompt" || key=="StartupWelcome")
            {
                var panel=Find(root,key=="AnalyticsPrompt"?"ConsentPanel":"PrivacyScreen");
                Paint(panel,"Help_Improve_Dessert_Cafe/HIP_Sign_In-copy");TextInk(panel);
                foreach(string name in new[]{"AllowAnalytics","AllowAnalyticsButton"})Paint(Find(root,name),"Help_Improve_Dessert_Cafe/HIP_Allow_Analytics");
                foreach(string name in new[]{"DeclineAnalytics","DeclineAnalyticsButton"})Paint(Find(root,name),"Help_Improve_Dessert_Cafe/HIP_No_Thanks");
                foreach(string name in new[]{"PrivacyPolicy","PrivacyPolicyButton"})Paint(Find(root,name),"Help_Improve_Dessert_Cafe/HIP_Privacy_Policy");
                var close=Find(root,"DismissPrompt");Paint(close,"Help_Improve_Dessert_Cafe/HIP_Cancel-");HideLabel(close);
            }
            if(key=="StartupWelcome")
            {
                Paint(root.transform,"Loading_Screen/Loading_BG");
                var card=Find(root,"WelcomeScreen");Paint(card,"Sign_In/SI_Backplate");Region(card,.12f,.24f,.88f,.51f);TextInk(card);
                var google=Find(root,"GoogleSignInButton");var guest=Find(root,"GuestPlayButton");
                Paint(google,"Sign_In/SI_Google_Sign_In_Button");Paint(guest,"Sign_In/SI_Guest_Sign_In_Button");
                Region(google,.05f,.08f,.49f,.36f);Region(guest,.51f,.08f,.95f,.36f);HideLabel(google);HideLabel(guest);
                // Obsolete unbound sign-in illustrations belonged to the old large card.
                foreach(Transform child in card)
                    if(child.GetComponent<Image>()!=null && child.GetComponent<EditableUIVisual>()==null)child.gameObject.SetActive(false);
                Decoration(card,"V3SignInTitle","Sign_In/SI_Sign_In",.22f,.84f,.78f,1.19f);
                var title=card.Find("Title");if(title!=null)title.GetComponent<TMP_Text>().color=Color.clear;
                Region(card.Find("Feedback"),.08f,.36f,.92f,.45f);
                Region(card.Find("RetryCachedGoogleSessionButton"),.05f,.08f,.49f,.36f);
                Region(card.Find("SwitchAccountButton"),.05f,-.20f,.60f,-.02f);
                Region(card.Find("RetryStartupButton"),.63f,-.20f,.95f,-.02f);
                foreach(string name in new[]{"RetryCachedGoogleSessionButton","SwitchAccountButton","RetryStartupButton"})
                    Paint(card.Find(name),"Cafe_Bonus/CB_Watch_Ad");
                // SI_Backplate already contains the tip; do not draw its older duplicate image.
            }
            if(key=="StartupLoading" || key=="DevelopmentLoading")
            {
                Paint(root.transform,"Loading_Screen/Loading_BG");
                var panel=Find(root,key=="StartupLoading"?"StartupModalCard":"LoadingPanel");
                // Keep the status/retry layout, including its variable-height error state.
                if(panel!=null)
                {
                    var image=panel.GetComponent<Image>();if(image!=null){image.sprite=null;image.color=Color.clear;}
                    var rect=(RectTransform)panel;rect.pivot=new Vector2(.5f,0);
                    Region(panel,.08f,.23f,.92f,key=="StartupLoading"?.23f:.43f);
                    foreach(var text in panel.GetComponentsInChildren<TMP_Text>(true))
                    {text.color=Color.white;text.enableVertexGradient=false;text.isOrthographic=true;}
                }
                Decoration(root.transform,"V3LoadingBar","Loading_Screen/Loading_Bar",.20f,.14f,.80f,.20f);
            }
            if(key=="CafeProfilePanel")
            {
                var card=root.GetComponentsInChildren<Transform>(true).FirstOrDefault(t=>t!=root.transform && t.name=="CafeProfilePanel");
                Paint(card,"Help_Improve_Dessert_Cafe/HIP_Sign_In-copy");TextInk(card);
                var close=Find(root,"Close");Paint(close,"Dessert_Collection/DC_Cancel");HideLabel(close);Region(close,.88f,.94f,1.04f,1.04f);
                foreach(string name in new[]{"EarningsCard","OrdersCard"})Paint(Find(root,name),"Drop_Down_Screen/DD_Plate");
            }
            PrefabUtility.SaveAsPrefabAsset(root,path);
        }
        finally{PrefabUtility.UnloadPrefabContents(root);}
    }
    private static void ScenePanels(GameObject root)
    {
        var collection=Find(root,"CollectionPanel");
        if(collection!=null)
        {
            Paint(collection,"Dessert_Collection/DC_Backplate");TextInk(collection);
            Paint(Find(collection.gameObject,"CloseButton"),"Dessert_Collection/DC_Cancel");
            Paint(Find(collection.gameObject,"CatalogScrollViewport"),"Dessert_Collection/DC_Plate_1");
            Paint(Find(collection.gameObject,"RewardScrollViewport"),"Dessert_Collection/DC_Plate_2");
            Decoration(collection,"V3CatalogPlate","Dessert_Collection/DC_Plate_1",.04f,.43f,.96f,.80f).SetAsFirstSibling();
            Decoration(collection,"V3RewardsPlate","Dessert_Collection/DC_Plate_2",.04f,.07f,.96f,.42f).SetAsFirstSibling();
            Decoration(collection,"V3ProgressPlate","Dessert_Collection/DC_Plate_3",.04f,.815f,.96f,.90f).SetAsFirstSibling();
            Decoration(collection,"V3CollectionTitlePlate","Dessert_Collection/DC_Title",.22f,.91f,.78f,1.04f).SetAsFirstSibling();
            var title=Find(collection.gameObject,"CollectionTitle");Region(title,.24f,.945f,.76f,1.00f);
            var titleText=title.GetComponent<TMP_Text>();titleText.alignment=TextAlignmentOptions.Center;titleText.enableAutoSizing=true;titleText.fontSizeMin=22;titleText.fontSizeMax=32;
            Region(Find(collection.gameObject,"DiscoveredCount"),.07f,.86f,.49f,.89f);
            Region(Find(collection.gameObject,"CompletionPercentage"),.52f,.86f,.75f,.89f);
            Region(Find(collection.gameObject,"CashBalance"),.76f,.86f,.94f,.89f);
            Region(Find(collection.gameObject,"ProgressTrack"),.07f,.827f,.93f,.853f);
            Region(Find(collection.gameObject,"CatalogHeading"),.07f,.782f,.93f,.812f);
            Region(Find(collection.gameObject,"CatalogScrollViewport"),.07f,.45f,.93f,.78f);
            Region(Find(collection.gameObject,"RewardHeading"),.07f,.39f,.93f,.42f);
            Region(Find(collection.gameObject,"RewardScrollViewport"),.06f,.09f,.94f,.39f);
            var content=Find(collection.gameObject,"CatalogContent");
            if(content!=null && content.GetComponent<CollectionReferenceGrid>()==null)content.gameObject.AddComponent<CollectionReferenceGrid>();
        }
        var prestige=Find(root,"RebirthPanel");
        if(prestige!=null)
        {
            TextInk(prestige);
            Region(Find(root,"RebirthRequiredDessertText"),.10f,.62f,.90f,.75f);
            Region(Find(root,"RebirthTierProgressText"),.10f,.51f,.90f,.61f);
            Region(Find(root,"RebirthCashRequirementText"),.10f,.40f,.90f,.50f);
            Region(Find(root,"RebirthEligibilityText"),.10f,.30f,.90f,.39f);
            Region(Find(root,"RebirthCampaignStatusText"),.10f,.38f,.90f,.72f);
            Region(Find(root,"RebirthButton"),.32f,.13f,.68f,.26f);
            Region(Find(root,"R_Title"),.27f,.94f,.73f,1.18f);
            Region(Find(root,"RebirthTitleText"),.28f,.99f,.72f,1.12f);
            var backdrop=Find(root,"RebirthBackdrop");if(backdrop!=null)backdrop.SetAsLastSibling();
            prestige.SetAsLastSibling();
        }
        var recycle=Find(root,"RecycleConfirmationPanel");
        if(recycle!=null)
        {
            Region(recycle,.09f,.28f,.91f,.70f);TextInk(recycle);
            Region(Find(root,"RecycleConfirmationTitle"),.15f,.94f,.85f,1.08f);
            Region(Find(root,"RD_Title"),.27f,.88f,.73f,1.13f);
            Region(Find(root,"RecycleCancelButton"),.10f,.12f,.47f,.255f);
            Region(Find(root,"RecycleConfirmButton"),.53f,.12f,.90f,.255f);
        }
        var lower=Find(root,"LowerBG");Paint(lower,"Main_Menu/HS_LowerPannel_Backplate");
    }
    [MenuItem("Tools/Sweet Maker/UI/Apply V3 Reference Artwork")]
    public static void Apply()
    {
        if(!Application.isBatchMode && !EditorSceneManager.SaveCurrentModifiedScenesIfUserWantsTo())return;
        var setup=EditorSceneManager.GetSceneManagerSetup();
        try
        {
            foreach(string path in AssetDatabase.FindAssets("t:Prefab",new[]{Templates.TrimEnd('/'),"Assets/_Game/Prefabs/UI"}).Select(AssetDatabase.GUIDToAssetPath))
            {
                if(path.EndsWith("SettingsArtwork.prefab") || path.Contains("Upgrade"))continue;
                var prefab=PrefabUtility.LoadPrefabContents(path);
                try
                {
                    Swap(prefab);
                    if(path.EndsWith("DessertCollectionEntry.prefab"))
                    {
                        Paint(prefab.transform,"Dessert_Collection/DC_Discovery_Plate");TextInk(prefab.transform);
                        Region(Find(prefab,"TierText"),.08f,.81f,.92f,.95f);
                        Region(Find(prefab,"DessertIcon"),.20f,.32f,.80f,.79f);
                        Region(Find(prefab,"DessertName"),.06f,.15f,.94f,.32f);
                        Region(Find(prefab,"DiscoveryState"),.06f,.04f,.94f,.15f);
                    }
                    if(path.EndsWith("DessertCollectionRewardRow.prefab"))
                    {
                        Paint(prefab.transform,"Dessert_Collection/DC_Collection_Reward");Paint(Find(prefab,"ClaimButton"),"Dessert_Collection/DC_Claim_Button");TextInk(prefab.transform);
                        foreach(var text in prefab.GetComponentsInChildren<TMP_Text>(true)){text.enableAutoSizing=true;text.fontSizeMin=16;text.fontSizeMax=24;text.fontSize=22;}
                    }
                    PrefabUtility.SaveAsPrefabAsset(prefab,path);
                }
                finally{PrefabUtility.UnloadPrefabContents(prefab);}
            }
            foreach(string key in new[]{"CafeNaming","RewardedCash","RewardedEnergy","AnalyticsPrompt","StartupWelcome","StartupLoading","DevelopmentLoading","CafeProfilePanel"})Template(key);
            foreach(string name in new[]{"MainBakery","Game","Welcome","Loading"})
            {
                string path="Assets/_Game/Scenes/"+name+".unity";
                var scene=EditorSceneManager.OpenScene(path,OpenSceneMode.Single);
                foreach(var root in scene.GetRootGameObjects()){Swap(root);ScenePanels(root);}
                EditorSceneManager.SaveScene(scene);
            }
            AssetDatabase.SaveAssets();
            Debug.Log("V3 reference artwork migration completed.");
        }
        finally
        {
            // A batch launch may contain an unsaved initialization scene with no asset path.
            var saved=setup.Where(s=>!string.IsNullOrEmpty(s.path) && File.Exists(s.path)).ToArray();
            if(saved.Length>0)EditorSceneManager.RestoreSceneManagerSetup(saved);
        }
        FirstTimePopupDesigner.RenderPreview();GeneratedUiLibrary.RenderPreviews();CafeScreensDesigner.RenderPreviews();
        V3UiReferencePreview.Render();
    }
}
#endif
