#if UNITY_EDITOR
using System.Linq;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.UI;

internal static class EnergyPlusAuthoringEditor
{
    public static void Apply()
    {
        var template = AssetDatabase.LoadAssetAtPath<GameObject>("Assets/_Game/Resources/UI/VisualTemplates/EnergyHUD.prefab");
        var source = template.GetComponentsInChildren<EditableUIVisual>(true).Single(p => p.targetPath == "EnergyPlus:0");
        foreach (string name in new[] { "MainBakery", "Game" })
        {
            var scene = EditorSceneManager.OpenScene("Assets/_Game/Scenes/" + name + ".unity");
            var owner = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren<EnergyHudUI>(true)).Single();
            var root = (RectTransform)new SerializedObject(owner).FindProperty("hudRoot").objectReferenceValue;
            if (root.Find("EnergyPlus") == null)
            {
                var plus = Object.Instantiate(source.gameObject, root);
                plus.name = "EnergyPlus";
                var button = plus.AddComponent<Button>(); button.colors = source.buttonColors;
                button.targetGraphic = plus.GetComponent<Image>(); plus.GetComponent<Image>().raycastTarget = true;
                foreach (var marker in plus.GetComponentsInChildren<EditableUIVisual>(true)) Object.DestroyImmediate(marker);
                plus.SetActive(true); plus.transform.SetAsLastSibling();
            }
            var authoredPlus = root.Find("EnergyPlus");
            if (authoredPlus.GetComponent<EditableUIView>() == null)
                authoredPlus.gameObject.AddComponent<EditableUIView>();
            // Apply the existing visual layout now so the editor matches runtime, including text space beside +.
            var view = root.GetComponent<EditableUIView>(); if (view == null) view = root.gameObject.AddComponent<EditableUIView>();
            EditableUIView.Attach(root.gameObject, "EnergyHUD");
            typeof(EditableUIView).GetMethod("ApplyTemplate", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance)
                .Invoke(view, new object[] { template.transform });
            EditorSceneManager.MarkSceneDirty(scene); EditorSceneManager.SaveScene(scene);
        }
        Debug.Log("ENERGY UI | Visible, wired EnergyPlus buttons added to bakery and gameplay HUDs.");
    }
}
#endif
