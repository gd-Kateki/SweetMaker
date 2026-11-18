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

internal static class V3UiReferencePreview
{
    public static void Render()
    {
        var pipeline=GraphicsSettings.defaultRenderPipeline;var quality=QualitySettings.renderPipeline;
        try
        {
            GraphicsSettings.defaultRenderPipeline=null;QualitySettings.renderPipeline=null;
            foreach(string mode in new[]{"MainBakery","Collection","Game","Prestige","Recycle","Dropdown","CafeNaming"})RenderOne(mode);
        }
        finally{GraphicsSettings.defaultRenderPipeline=pipeline;QualitySettings.renderPipeline=quality;}
    }
    private static Transform Find(GameObject root,string name)=>root.GetComponentsInChildren<Transform>(true).FirstOrDefault(t=>t.name==name);
    private static void RenderOne(string mode)
    {
        bool home=mode=="MainBakery"||mode=="Collection";
        var scene=EditorSceneManager.OpenScene("Assets/_Game/Scenes/"+(home?"MainBakery":"Game")+".unity",OpenSceneMode.Single);
        var source=scene.GetRootGameObjects().SelectMany(r=>r.GetComponentsInChildren<Canvas>(true)).First(c=>c.name==(home?"MainCanvas":"GameplayCanvas"));
        var root=mode=="CafeNaming"?Object.Instantiate(AssetDatabase.LoadAssetAtPath<GameObject>("Assets/_Game/Resources/UI/VisualTemplates/CafeNaming.prefab")):EditableUIEditor.CopyVisualTree(source.transform,null,source.transform);
        var cameraRoot=new GameObject("V3 preview camera",typeof(Camera));var target=new RenderTexture(720,1280,24);target.Create();var previous=RenderTexture.active;
        try
        {
            var rect=(RectTransform)root.transform;rect.localScale=Vector3.one;rect.position=Vector3.zero;
            rect.sizeDelta=mode=="CafeNaming"?new Vector2(720,1280):new Vector2(1080,1920);
            root.SetActive(true);var canvas=root.GetComponent<Canvas>();canvas.renderMode=RenderMode.WorldSpace;
            foreach(var c in root.GetComponentsInChildren<Canvas>(true))c.overrideSorting=false;
            if(mode!="CafeNaming")
            {
                foreach(string name in new[]{"CollectionOverlay","RebirthBackdrop","RebirthPanel","RecycleConfirmationOverlay","OvenTierSelectionPanel","OrderDetailsOverlay","OrderDetailsInputBlocker","SettingsOverlay","UpgradeScreen"})
                {var t=Find(root,name);if(t!=null)t.gameObject.SetActive(false);}
                foreach(string name in mode=="Collection"?new[]{"CollectionOverlay"}:mode=="Prestige"?new[]{"RebirthBackdrop","RebirthPanel"}:mode=="Recycle"?new[]{"RecycleConfirmationOverlay"}:mode=="Dropdown"?new[]{"OvenTierSelectionPanel"}:new string[0])
                {var t=Find(root,name);if(t!=null)t.gameObject.SetActive(true);}
                if(!home)
                {
                    var sourceCamera=scene.GetRootGameObjects().SelectMany(r=>r.GetComponentsInChildren<Camera>(true)).First();
                    sourceCamera.aspect=720f/1280f;
                    var world=new GameObject("World artwork preview",typeof(RectTransform));world.transform.SetParent(root.transform,false);world.transform.SetAsFirstSibling();
                    var worldRect=(RectTransform)world.transform;worldRect.anchorMin=Vector2.zero;worldRect.anchorMax=Vector2.one;worldRect.offsetMin=worldRect.offsetMax=Vector2.zero;
                    foreach(var sr in scene.GetRootGameObjects().SelectMany(r=>r.GetComponentsInChildren<SpriteRenderer>(true)).Where(s=>s.gameObject.activeInHierarchy && s.sprite!=null).OrderBy(s=>s.sortingOrder))
                    {
                        var go=new GameObject("Preview "+sr.name,typeof(RectTransform),typeof(Image));go.transform.SetParent(world.transform,false);
                        var image=go.GetComponent<Image>();image.sprite=sr.sprite;image.color=sr.color;image.raycastTarget=false;
                        var r=(RectTransform)go.transform;Vector3 min=sourceCamera.WorldToViewportPoint(sr.bounds.min),max=sourceCamera.WorldToViewportPoint(sr.bounds.max);
                        r.anchorMin=new Vector2(min.x,min.y);r.anchorMax=new Vector2(max.x,max.y);r.offsetMin=r.offsetMax=Vector2.zero;
                    }
                }
                if(mode=="Collection")
                {
                    var content=Find(root,"CatalogContent");
                    if(content.GetComponent<CollectionReferenceGrid>()==null)content.gameObject.AddComponent<CollectionReferenceGrid>();
                    for(int i=1;i<=9;i++)
                    {
                        var entry=Object.Instantiate(AssetDatabase.LoadAssetAtPath<GameObject>("Assets/_Game/Prefabs/UI/DessertCollectionEntry.prefab"),content);
                        entry.GetComponent<DessertCollectionEntryUI>().Show(i,null,false);
                    }
                    var rewards=Find(root,"RewardContent");
                    for(int i=1;i<=5;i++)Object.Instantiate(AssetDatabase.LoadAssetAtPath<GameObject>("Assets/_Game/Prefabs/UI/DessertCollectionRewardRow.prefab"),rewards);
                }
            }
            else
            {
                Find(root,"NamingInputStep").gameObject.SetActive(true);Find(root,"NamingConfirmationStep").gameObject.SetActive(false);
            }
            foreach(var t in root.GetComponentsInChildren<Transform>(true))t.gameObject.layer=31;
            var camera=cameraRoot.GetComponent<Camera>();camera.transform.position=new Vector3(0,0,-10);camera.orthographic=true;camera.orthographicSize=rect.rect.height*.5f;camera.cullingMask=1<<31;
            camera.clearFlags=CameraClearFlags.SolidColor;camera.backgroundColor=new Color(.16f,.10f,.23f);camera.targetTexture=target;canvas.worldCamera=camera;
            Canvas.ForceUpdateCanvases();foreach(var text in root.GetComponentsInChildren<TMP_Text>(true)){text.isOrthographic=true;text.ForceMeshUpdate(true,true);}
            camera.Render();RenderTexture.active=target;var png=new Texture2D(720,1280,TextureFormat.RGBA32,false);
            try{png.ReadPixels(new Rect(0,0,720,1280),0,0);png.Apply();Directory.CreateDirectory("tmp");File.WriteAllBytes("tmp/v3-"+mode+".png",png.EncodeToPNG());}
            finally{Object.DestroyImmediate(png);}
        }
        finally{RenderTexture.active=previous;target.Release();Object.DestroyImmediate(target);Object.DestroyImmediate(cameraRoot);Object.DestroyImmediate(root);}
    }
}
#endif
