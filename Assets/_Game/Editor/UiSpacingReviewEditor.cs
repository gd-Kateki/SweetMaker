#if UNITY_EDITOR
using System;
using System.IO;
using System.Linq;
using TMPro;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.UI;

// Scoped finishing pass. Does not rerun the artwork migrations or reset artist styling.
internal static class UiSpacingReviewEditor
{
    private const string Folder="Assets/_Game/Resources/UI/VisualTemplates/";
    private static Transform Find(GameObject root,string name)=>root.GetComponentsInChildren<Transform>(true).FirstOrDefault(t=>t.name==name);
    private static void Region(Transform t,float x,float y,float right,float top)
    {
        if(!(t is RectTransform r))return;
        r.anchorMin=new Vector2(x,y);r.anchorMax=new Vector2(right,top);r.offsetMin=r.offsetMax=Vector2.zero;
    }
    private static void Edit(string key,Action<GameObject> change)
    {
        var root=PrefabUtility.LoadPrefabContents(Folder+key+".prefab");
        try{change(root);PrefabUtility.SaveAsPrefabAsset(root,Folder+key+".prefab");}
        finally{PrefabUtility.UnloadPrefabContents(root);}
    }
    private static void Privacy(string key)
    {
        Edit(key,root=>
        {
            var panel=Find(root,"Privacy content");
            var labels=panel.Cast<Transform>().Where(t=>t.GetComponent<TMP_Text>()!=null).ToArray();
            // A common inner gutter for titles, paragraphs and actions.
            foreach(Transform t in panel)
            {
                var marker=t.GetComponent<EditableUIVisual>();
                if(t.GetComponent<TMP_Text>()==null && (marker==null||!marker.copyButtonStyle))continue;
                var rect=(RectTransform)t;var min=rect.anchorMin;var max=rect.anchorMax;
                Region(t,.10f,min.y,.90f,max.y);
            }
            if(key=="AccountDeletion")return; // Long ownership/deletion instructions need the existing tall panel.
            if(key.EndsWith("Adult"))
            {
                Region(panel,.055f,.065f,.945f,.935f);
                Region(panel.Find("Privacy policy"),.10f,.07f,.90f,.145f);
                return;
            }
            if(key.EndsWith("Unknown"))
            {
                Region(panel,.10f,.15f,.90f,.85f);
                Region(labels[0],.10f,.86f,.90f,.94f);Region(labels[1],.10f,.50f,.90f,.81f);
                Region(panel.Find("Under 13"),.10f,.40f,.90f,.48f);
                Region(panel.Find("13–17"),.10f,.295f,.90f,.375f);
                Region(panel.Find("18 or older"),.10f,.19f,.90f,.27f);
                Region(panel.Find("Privacy policy"),.10f,.07f,.90f,.15f);
            }
            if(key.EndsWith("Teen"))
            {
                Region(panel,.10f,.15f,.90f,.85f);
                Region(labels[0],.10f,.86f,.90f,.94f);Region(labels[1],.10f,.38f,.90f,.82f);
                Region(panel.Find("Use limited ads"),.10f,.235f,.90f,.32f);
                Region(panel.Find("Privacy policy"),.10f,.10f,.90f,.185f);
            }
            if(key.EndsWith("Under13"))
            {
                Region(panel,.10f,.22f,.90f,.78f);
                Region(labels[0],.10f,.84f,.90f,.94f);Region(labels[1],.10f,.45f,.90f,.79f);
                Region(panel.Find("Close"),.10f,.31f,.90f,.41f);
                Region(panel.Find("Privacy policy"),.10f,.12f,.90f,.22f);
            }
        });
    }
    public static void Apply()
    {
        if(!Application.isBatchMode&&!EditorSceneManager.SaveCurrentModifiedScenesIfUserWantsTo())return;
        var setup=EditorSceneManager.GetSceneManagerSetup();
        try
        {
            foreach(string key in new[]{"AdvertisingPrivacy_Unknown","AdvertisingPrivacy_Teen","AdvertisingPrivacy_Adult","AdvertisingPrivacy_Under13","AccountDeletion"})Privacy(key);
            Edit("AnalyticsPrompt",root=>
            {
                Region(Find(root,"PromptTitle"),.10f,.78f,.84f,.94f);
                Region(Find(root,"PromptDescription"),.10f,.54f,.90f,.75f);
                Region(Find(root,"PromptDisclosure"),.10f,.30f,.90f,.49f);
                Region(Find(root,"PrivacyPolicy"),.20f,.18f,.80f,.26f);
                Region(Find(root,"AllowAnalytics"),.10f,.065f,.485f,.16f);
                Region(Find(root,"DeclineAnalytics"),.515f,.065f,.90f,.16f);
                var close=(RectTransform)Find(root,"DismissPrompt");
                close.anchorMin=close.anchorMax=Vector2.one;close.pivot=Vector2.one;
                close.anchoredPosition=new Vector2(-16,-14);close.sizeDelta=new Vector2(64,70);
                close.GetComponent<Image>().preserveAspect=true;
            });
            foreach(string name in new[]{"StartupDependencyError","CloudRestoreRestart"})Edit(name,root=>
            {
                var surface=Find(root,"RecoverySurface");Region(surface,.10f,.30f,.90f,.70f);
                if(name=="CloudRestoreRestart")Region(Find(root,"Cloud text"),.16f,.36f,.84f,.64f);
                else
                {
                    Region(Find(root,"Status"),.16f,.48f,.84f,.64f);
                    Region(Find(root,"RetryButton"),.20f,.35f,.80f,.43f);
                }
            });
            // Use the same backdrop treatment as other blocking gameplay dialogs.
            var scene=EditorSceneManager.OpenScene("Assets/_Game/Scenes/Game.unity");
            var overlay=scene.GetRootGameObjects().SelectMany(r=>r.GetComponentsInChildren<Transform>(true)).First(t=>t.name=="OrderDetailsOverlay");
            // Remove legacy size/position offsets: they left the dim layer tiny
            // and placed the centered child panel below the canvas center.
            Region(overlay,0,0,1,1);
            var shade=overlay.GetComponent<Image>()??overlay.gameObject.AddComponent<Image>();
            shade.sprite=null;shade.color=new Color(.08f,.04f,.12f,.65f);shade.raycastTarget=false;
            EditorSceneManager.SaveScene(scene);AssetDatabase.SaveAssets();
            RemainingUiV3Editor.Render();GeneratedUiLibrary.RenderPreviews();
            SettingsLayoutEditor.RenderPreviews();UpgradeDesignerEditor.RenderPreviews();FirstTimePopupDesigner.RenderPreview();
            File.WriteAllText("Docs/UI_SPACING_REVIEW.md","# UI spacing review\n\nReviewed Home, gameplay/HUD, collection, My Café, Settings (both scroll ends), Upgrades, leaderboards, naming, Prestige/recycle, rewarded offers, startup/sign-in, cloud decisions/recovery, age/privacy/deletion, analytics, tutorials, order/completion dialogs and developer/log screens.\n\n## Adjustments\n\n- Common inner gutters for privacy titles, body text and action buttons.\n- More compact age/teen/under-13 prompts with consistent action spacing. The longer adult and deletion disclosures retain their needed reading area.\n- Analytics title, descriptions, policy button, two-column actions and close icon now have separate padded regions.\n- Compact centered startup/restart messages with consistent action clearance.\n- Order details use a non-interactive dim backdrop. Existing input blocking remains unchanged.\n\nExisting artwork, control shapes, custom energy + visuals, My Café's flat statistics, callbacks, consent choices, and modal gates are preserved. Settings account/status areas and scrollable lists retain room for live/error states; partial rows at a scroll boundary are intentional.\n\nAll layouts remain editable in the existing visual-template prefabs and scene hierarchy. Editor previews and geometric checks cover portrait and tall layouts; they do not replace an Android device walkthrough.\n");
            Debug.Log("UI spacing review: targeted layout adjustments saved; all screen previews refreshed.");
        }
        finally
        {
            var saved=setup.Where(s=>!string.IsNullOrEmpty(s.path)&&File.Exists(s.path)).ToArray();
            if(saved.Length>0)EditorSceneManager.RestoreSceneManagerSetup(saved);
        }
    }
}
#endif
