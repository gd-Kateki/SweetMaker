#if UNITY_EDITOR
using System.Linq;
using TMPro;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.UI;

internal static class BakeryHudEditor
{
    public static void Apply()
    {
        var sourceScene = EditorSceneManager.OpenPreviewScene("Assets/_Game/Scenes/Game.unity");
        GameObject hud = null;
        try
        {
            var source = sourceScene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren<EnergyHudUI>(true)).Single();
            var data = new SerializedObject(source);
            var root = (RectTransform)data.FindProperty("hudRoot").objectReferenceValue;
            var scene = EditorSceneManager.OpenScene("Assets/_Game/Scenes/MainBakery.unity");
            var canvas = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren<Canvas>(true)).Single(c => c.name == "MainCanvas");
            if (!canvas.GetComponentsInChildren<EnergyHudUI>(true).Any())
            {
                hud = Object.Instantiate(root.gameObject);
                var topBar = (RectTransform)canvas.transform.Find("TopBar");
                hud.name = "EnergyHUD";
                hud.transform.SetParent(topBar, false);
                var rect = (RectTransform)hud.transform;
                rect.anchorMin = rect.anchorMax = new Vector2(.06f, .5f);
                rect.pivot = new Vector2(0, .5f);
                rect.anchoredPosition = new Vector2(0, -23);
                rect.sizeDelta = new Vector2(236, 66);
                var controller = hud.AddComponent<EnergyHudUI>();
                var target = new SerializedObject(controller);
                target.FindProperty("hudRoot").objectReferenceValue = rect;
                target.FindProperty("hudBackground").objectReferenceValue = hud.GetComponent<Image>();
                foreach (string field in new[] { "energyText", "countdownText" })
                {
                    var text = (TMP_Text)data.FindProperty(field).objectReferenceValue;
                    string path = AnimationUtility.CalculateTransformPath(text.transform, root);
                    target.FindProperty(field).objectReferenceValue = hud.transform.Find(path).GetComponent<TMP_Text>();
                }
                target.ApplyModifiedPropertiesWithoutUndo();
                hud = null; // Scene owns the new HUD.
                EditorSceneManager.MarkSceneDirty(scene);
                EditorSceneManager.SaveScene(scene);
            }
        }
        finally
        {
            if (hud != null) Object.DestroyImmediate(hud);
            EditorSceneManager.ClosePreviewScene(sourceScene);
        }
        var game = EditorSceneManager.OpenScene("Assets/_Game/Scenes/Game.unity");
        foreach (var ui in game.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren<RebirthUI>(true)))
        {
            var data = new SerializedObject(ui);
            var label = (TMP_Text)data.FindProperty("entryButtonText").objectReferenceValue;
            if (label != null) { label.text = string.Empty; EditorUtility.SetDirty(label); }
        }
        EditorSceneManager.MarkSceneDirty(game);
        EditorSceneManager.SaveScene(game);
        Debug.Log("BAKERY HUD | Added working Home energy HUD and removed the Prestige entry caption.");
    }
}
#endif
