#if UNITY_EDITOR
using System.Linq;
using System.Text.RegularExpressions;
using TMPro;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.UI;

internal static class ConsistentUiEditor
{
    private static string Wording(string text) => Regex.Replace(text, @"\b(Rebirths?|REBIRTHS?|rebirths?)\b", match =>
    {
        string word = match.Value.EndsWith("s", System.StringComparison.OrdinalIgnoreCase) ? "Prestiges" : "Prestige";
        return match.Value == match.Value.ToUpperInvariant() ? word.ToUpperInvariant() :
            match.Value == match.Value.ToLowerInvariant() ? word.ToLowerInvariant() : word;
    });

    private static bool UpdateText(GameObject root)
    {
        bool changed = false;
        foreach (var text in root.GetComponentsInChildren<TMP_Text>(true))
        {
            string value = Wording(text.text);
            if (value == text.text) continue;
            text.text = value; changed = true; EditorUtility.SetDirty(text);
        }
        foreach (var text in root.GetComponentsInChildren<Text>(true))
        {
            string value = Wording(text.text);
            if (value == text.text) continue;
            text.text = value; changed = true; EditorUtility.SetDirty(text);
        }
        return changed;
    }

    public static void Apply()
    {
        foreach (string guid in AssetDatabase.FindAssets("t:Prefab", new[] { "Assets/_Game/Resources/UI/VisualTemplates", "Assets/_Game/Prefabs/UI" }))
        {
            string path = AssetDatabase.GUIDToAssetPath(guid);
            var root = PrefabUtility.LoadPrefabContents(path);
            try { if (UpdateText(root)) PrefabUtility.SaveAsPrefabAsset(root, path); }
            finally { PrefabUtility.UnloadPrefabContents(root); }
        }
        foreach (string name in new[] { "MainBakery", "Game", "Welcome", "Loading" })
        {
            var scene = EditorSceneManager.OpenScene("Assets/_Game/Scenes/" + name + ".unity");
            foreach (var root in scene.GetRootGameObjects()) UpdateText(root);
            foreach (var customer in scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren<CustomerButtonUI>(true)))
            {
                var labels = new SerializedObject(customer).FindProperty("requirementLabels");
                for (int i = 0; i < labels.arraySize; i++)
                {
                    var text = labels.GetArrayElementAtIndex(i).objectReferenceValue as TMP_Text;
                    if (text != null) { text.text = Regex.Replace(text.text, @"\bT\d+\s+", ""); EditorUtility.SetDirty(text); }
                }
            }
            if (name == "MainBakery")
            {
                var panel = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren<RectTransform>(true)).Single(t => t.name == "CollectionPanel");
                var image = panel.GetComponent<Image>();
                if (panel.parent.name != "CollectionBounds")
                {
                    var bounds = new GameObject("CollectionBounds", typeof(RectTransform)).GetComponent<RectTransform>();
                    bounds.SetParent(panel.parent, false); bounds.SetSiblingIndex(panel.GetSiblingIndex());
                    bounds.anchorMin = panel.anchorMin; bounds.anchorMax = panel.anchorMax;
                    bounds.pivot = panel.pivot; bounds.sizeDelta = panel.sizeDelta; bounds.anchoredPosition = panel.anchoredPosition;
                    panel.SetParent(bounds, false);
                }
                var fitter = panel.GetComponent<AspectRatioFitter>(); if (fitter == null) fitter = panel.gameObject.AddComponent<AspectRatioFitter>();
                fitter.aspectRatio = image.sprite.rect.width / image.sprite.rect.height;
                fitter.aspectMode = AspectRatioFitter.AspectMode.FitInParent;
            }
            EditorSceneManager.MarkSceneDirty(scene); EditorSceneManager.SaveScene(scene);
        }
        Debug.Log("UI CONSISTENCY | Prestige wording, quantity-only table rows, and original collection artwork proportions applied.");
    }
}
#endif
