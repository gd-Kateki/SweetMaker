#if UNITY_EDITOR
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text.RegularExpressions;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.UI;

// Manual visual migration only. Preserves control bounds, values, colors and listeners.
internal static class UiControlShapeEditor
{
    private const string Art="Assets/_Game/Art/UI_Assets/UI V3/";
    private static readonly HashSet<string> Caps=new HashSet<string>
    {
        "Shop_Upgrade/SU_Upgrade", "Confirm_Cafe_Name/CCN_Confirm", "Confirm_Cafe_Name/CCN_Cancel",
        "Name_Your_Cafe/NYC_Continue", "Name_Your_Cafe/NYC_Cancel", "Name_Your_Cafe/NYC_Insert_Name",
        "Recycle_Dessert_Screen/RD_Cancel_Button", "Recycle_Dessert_Screen/RD_Recycle_Button",
        "Dessert_Collection/DC_Claim_Button", "Settings_Screen/Settings_Slider_Bar", "Settings_Screen/Settings_On_Bar"
    };
    private static Sprite Load(string path)=>AssetDatabase.LoadAllAssetsAtPath(path).OfType<Sprite>().First();
    private static Vector4 Border(Rect rect)
    {
        // Capture the complete curved ends. A narrow slice leaves curves in the
        // stretching center, which produces long bowed ends on wide controls.
        return new Vector4(Mathf.Ceil(rect.height*.62f),Mathf.Floor(rect.height*.44f),Mathf.Ceil(rect.height*.62f),Mathf.Floor(rect.height*.44f));
    }
    private static string Vector(Vector4 value)=>"{x: "+value.x.ToString(CultureInfo.InvariantCulture)+", y: "+value.y.ToString(CultureInfo.InvariantCulture)+", z: "+value.z.ToString(CultureInfo.InvariantCulture)+", w: "+value.w.ToString(CultureInfo.InvariantCulture)+"}";
    private static void ImportCaps()
    {
        foreach(string relative in Caps)
        {
            string path=Art+relative+".png",meta=path+".meta";
            var border=Border(Load(path).rect);
            // Preserve multi-sprite internal IDs and all other importer settings.
            string text=File.ReadAllText(meta);
            text=Regex.Replace(text,@"(?m)^(\s*(?:spriteBorder|border): )\{[^\r\n]+\}",m=>m.Groups[1].Value+Vector(border));
            File.WriteAllText(meta,text);AssetDatabase.ImportAsset(path,ImportAssetOptions.ForceUpdate);
        }
        foreach(string name in new[]{"V3GreenButton","V3RedButton","V3PurpleButton"})
        {
            string path=Art+"Shared/"+name+".asset";
            var border=Border(AssetDatabase.LoadAssetAtPath<Sprite>(path).rect);
            string text=File.ReadAllText(path);
            text=Regex.Replace(text,@"(?m)^(  m_Border: )\{[^\r\n]+\}",m=>m.Groups[1].Value+Vector(border));
            File.WriteAllText(path,text);AssetDatabase.ImportAsset(path,ImportAssetOptions.ForceUpdate);
        }
    }
    private static bool Protected(Transform t)
    {
        for(;t!=null;t=t.parent)if(t.name=="EnergyPlus"||t.CompareTag("EditorOnly")||t.name.StartsWith("UI Designs"))return true;
        return false;
    }
    private static int Fix(GameObject root)
    {
        int count=0;
        foreach(var image in root.GetComponentsInChildren<Image>(true))
        {
            if(Protected(image.transform)||image.sprite==null)continue;
            var slider=image.GetComponentInParent<Slider>(true);
            if(slider!=null&&slider.handleRect!=null&&image.transform.IsChildOf(slider.handleRect))continue;
            var marker=image.GetComponent<EditableUIVisual>();
            bool button=image.GetComponent<Button>()!=null||(marker!=null&&marker.copyButtonStyle);
            string path=AssetDatabase.GetAssetPath(image.sprite);
            // A title plaque is not a service-action button. Keep page headings intact.
            if(button&&path==Art+"Settings_Screen/Settings_Title.png")
            {image.sprite=AssetDatabase.LoadAssetAtPath<Sprite>(Art+"Shared/V3GoldButton.asset");path=AssetDatabase.GetAssetPath(image.sprite);}
            bool cap=Caps.Any(p=>path==Art+p+".png")||new[]{"V3GreenButton","V3RedButton","V3PurpleButton"}.Any(n=>path==Art+"Shared/"+n+".asset");
            bool gold=button&&path==Art+"Shared/V3GoldButton.asset";
            if(!cap&&!gold)continue;
            image.type=Image.Type.Sliced;image.preserveAspect=false;
            image.pixelsPerUnitMultiplier=path.Contains("Settings_Screen")?2.5f:3f;
            count++;
        }
        return count;
    }
    public static void Apply()
    {
        if(!Application.isBatchMode&&!EditorSceneManager.SaveCurrentModifiedScenesIfUserWantsTo())return;
        ImportCaps();int assets=0,controls=0;
        foreach(string path in AssetDatabase.FindAssets("t:Prefab",new[]{"Assets/_Game/Resources/UI/VisualTemplates","Assets/_Game/Prefabs/UI"}).Select(AssetDatabase.GUIDToAssetPath))
        {
            var root=PrefabUtility.LoadPrefabContents(path);
            try{int changed=Fix(root);if(changed>0){PrefabUtility.SaveAsPrefabAsset(root,path);controls+=changed;assets++;}}
            finally{PrefabUtility.UnloadPrefabContents(root);}
        }
        foreach(string sceneName in new[]{"MainBakery","Game"})
        {
            var scene=EditorSceneManager.OpenScene("Assets/_Game/Scenes/"+sceneName+".unity");
            foreach(var root in scene.GetRootGameObjects())controls+=Fix(root);
            EditorSceneManager.SaveScene(scene);
        }
        AssetDatabase.SaveAssets();
        Directory.CreateDirectory("Docs");
        File.WriteAllText("Docs/UI_CONTROL_SHAPES.md","# UI control shape pass\n\nChecked all visual templates, UI prefabs, and the MainBakery/Game scenes.\n\nUpdated "+controls+" control images across "+assets+" prefab assets plus the two scenes. Counts include shared instances.\n\n- Complete rounded caps now sit inside fixed nine-slice borders, instead of stretching with the center.\n- Ordinary action buttons use smaller rendered corners. Settings service buttons use the existing gold button artwork rather than a stretched title plaque.\n- Slider tracks retain their full interactive bounds and values. Circular handles, close icons, navigation artwork and custom energy + designs are preserved.\n- No control listeners, saved values, modal gates or gameplay commands were replaced.\n\nEdit the saved scene/prefab Image settings to customize these shapes. This tool never runs automatically.\n");
        SettingsLayoutEditor.RenderPreviews();UpgradeDesignerEditor.RenderPreviews();
        RemainingUiV3Editor.Render();FirstTimePopupDesigner.RenderPreview();GeneratedUiLibrary.RenderPreviews();
        Debug.Log("UI control shapes: "+controls+" images adjusted; "+assets+" prefab assets updated.");
    }
}
#endif
