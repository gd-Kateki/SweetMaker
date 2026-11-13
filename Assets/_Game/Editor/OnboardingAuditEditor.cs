#if UNITY_EDITOR
using System.IO;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;

internal static class OnboardingAuditEditor
{
    public static void PrepareBackdropDesign()
    {
        const string path="Assets/_Game/Resources/UI/VisualTemplates/TutorialWelcomeBackdrop.prefab";
        if(File.Exists(path))return;
        var root=new GameObject("TutorialWelcomeBackdrop",typeof(RectTransform),typeof(Canvas),typeof(Image));
        try
        {
            root.GetComponent<Canvas>().renderMode=RenderMode.WorldSpace;
            ((RectTransform)root.transform).sizeDelta=new Vector2(720,1280);
            root.GetComponent<Image>().color=new Color(.10f,.06f,.16f,.82f);root.GetComponent<Image>().raycastTarget=false;
            var marker=root.AddComponent<EditableUIVisual>();marker.targetPath="";marker.copyLayout=false;
            PrefabUtility.SaveAsPrefabAsset(root,path);
        }
        finally{Object.DestroyImmediate(root);}
    }
}
#endif
