#if UNITY_EDITOR
using System.IO;
using System.Linq;
using TMPro;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.UI;
using Object=UnityEngine.Object;

internal sealed class GeneratedUiLibrary : EditorWindow
{
    private Vector2 scroll;
    private string search="";
    [MenuItem("Tools/Sweet Maker/UI Library")]
    private static void Open()=>GetWindow<GeneratedUiLibrary>("UI Library").Show();
    private void OnGUI()
    {
        EditorGUILayout.HelpBox("Edit a generated design in Prefab Mode without running the game. Save artwork, typography and layout changes. Keep binding markers; live text, visibility and actions remain controlled by the game.",MessageType.Info);
        if(GUILayout.Button("Scene panels and manually authored UI"))GetWindow<UiPanelPreviewWindow>("UI Panel Preview").Show();
        search=EditorGUILayout.TextField("Find a design",search);
        scroll=EditorGUILayout.BeginScrollView(scroll);
        foreach(string path in AssetDatabase.FindAssets("t:Prefab",new[]{GeneratedUiPolish.Folder.TrimEnd('/')}).Select(AssetDatabase.GUIDToAssetPath).OrderBy(Path.GetFileNameWithoutExtension))
        {
            string key=Path.GetFileNameWithoutExtension(path);
            if(!string.IsNullOrWhiteSpace(search)&&key.IndexOf(search,System.StringComparison.OrdinalIgnoreCase)<0)continue;
            if(GUILayout.Button(ObjectNames.NicifyVariableName(key)))OpenDesign(path);
        }
        EditorGUILayout.EndScrollView();
        var stage=PrefabStageUtility.GetCurrentPrefabStage();if(stage==null)return;
        if(GUILayout.Button("Show currently selected hidden panel"))
        {
            var selected=Selection.activeTransform;
            if(selected!=null&&selected.gameObject.scene==stage.scene)
                for(var value=selected;value!=null;value=value.parent)value.gameObject.SetActive(true);
            SceneView.RepaintAll();
        }
    }
    private static void OpenDesign(string path)
    {
        var stage=PrefabStageUtility.OpenPrefab(path);var root=stage.prefabContentsRoot;
        foreach(var t in root.GetComponentsInChildren<Transform>(true))
        {
            if(new[]{"Log Panel","CafeProfilePanel","CafeNamingPopup","NamingInputStep","WelcomeScreen"}.Contains(t.name))t.gameObject.SetActive(true);
            if(t.name=="PrivacyScreen"||t.name=="NamingConfirmationStep")t.gameObject.SetActive(false);
            if(t.name=="Leaderboards"&&t.GetComponent<EditableUIVisual>()?.targetPath.EndsWith("/Leaderboards:1")==true)t.gameObject.SetActive(true);
        }
        Selection.activeGameObject=root;
    }
    public static void ValidateLibrary()
    {
        foreach(string key in new[]{"RewardedEnergy","RewardedCash","AccountDeletion","StartupLoading","DevelopmentLoading","StartupDependencyError","AnalyticsPrompt","CloudRestoreRestart","EnergyHUD","AndroidLogConsole","TutorialHighlight"})
        {
            var root=AssetDatabase.LoadAssetAtPath<GameObject>(GeneratedUiPolish.Folder+key+".prefab");
            if(root==null||root.GetComponent<Canvas>()==null)throw new System.InvalidOperationException("Missing editor-visible design: "+key);
            if(root.GetComponentsInChildren<Button>(true).Length>0)throw new System.InvalidOperationException("Design contains functional buttons: "+key);
        }
    }
    public static void RenderPreviews()
    {
        var pipeline=GraphicsSettings.defaultRenderPipeline;var quality=QualitySettings.renderPipeline;var previous=RenderTexture.active;
        try
        {
            GraphicsSettings.defaultRenderPipeline=null;QualitySettings.renderPipeline=null;
            foreach(string key in new[]{"RewardedEnergy","RewardedCash","AccountDeletion","StartupLoading","DevelopmentLoading","StartupDependencyError","AnalyticsPrompt","CloudRestoreRestart","EnergyHUD","AndroidLogConsole","TutorialHighlight"})
            {
                var root=Object.Instantiate(AssetDatabase.LoadAssetAtPath<GameObject>(GeneratedUiPolish.Folder+key+".prefab"));var cameraRoot=new GameObject("UI preview camera",typeof(Camera));var target=new RenderTexture(720,1280,24);target.Create();
                try
                {
                    root.SetActive(true);root.transform.position=Vector3.zero;
                    if(key=="AndroidLogConsole")foreach(var t in root.GetComponentsInChildren<Transform>(true))if(t.name=="Log Panel")t.gameObject.SetActive(true);
                    foreach(var t in root.GetComponentsInChildren<Transform>(true))t.gameObject.layer=31;
                    var size=((RectTransform)root.transform).rect.size;var camera=cameraRoot.GetComponent<Camera>();camera.transform.position=new Vector3(0,0,-10);camera.orthographic=true;camera.orthographicSize=Mathf.Max(size.y,size.x/(720f/1280f))*.5f;
                    camera.cullingMask=1<<31;camera.clearFlags=CameraClearFlags.SolidColor;camera.backgroundColor=new Color(.16f,.10f,.23f);camera.targetTexture=target;root.GetComponent<Canvas>().worldCamera=camera;
                    Canvas.ForceUpdateCanvases();foreach(var text in root.GetComponentsInChildren<TMP_Text>(true))text.ForceMeshUpdate(true,true);
                    camera.Render();RenderTexture.active=target;var png=new Texture2D(720,1280,TextureFormat.RGBA32,false);
                    try{png.ReadPixels(new Rect(0,0,720,1280),0,0);png.Apply();Directory.CreateDirectory("tmp");File.WriteAllBytes("tmp/ui-library-"+key+".png",png.EncodeToPNG());}finally{Object.DestroyImmediate(png);}
                }
                finally{RenderTexture.active=previous;target.Release();Object.DestroyImmediate(target);Object.DestroyImmediate(cameraRoot);Object.DestroyImmediate(root);}
            }
        }
        finally{GraphicsSettings.defaultRenderPipeline=pipeline;QualitySettings.renderPipeline=quality;RenderTexture.active=previous;}
    }
}
#endif
