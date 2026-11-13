#if UNITY_EDITOR
using System;
using System.Collections.Generic;
using TMPro;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;

// Bakes appearance into editable assets; no runtime scanning or animation.
internal static class TitleColourEditor
{
    private static readonly HashSet<string> Captions = new HashSet<string>(StringComparer.OrdinalIgnoreCase)
    {
        "Leaderboards", "Advertising privacy", "Cloud progress", "Account & data deletion",
        "A little cafe bonus!", "More energy?", "TEST LAB", "SWEET CAFE"
    };

    [MenuItem("Tools/Sweet Maker/UI/Apply Title Colours")]
    public static void Apply()
    {
        if (!Application.isBatchMode && !EditorSceneManager.SaveCurrentModifiedScenesIfUserWantsTo()) return;
        int count = 0;
        foreach (var guid in AssetDatabase.FindAssets("t:Prefab", new[] {
            "Assets/_Game/Resources/UI/VisualTemplates", "Assets/_Game/Prefabs/UI" }))
        {
            string path = AssetDatabase.GUIDToAssetPath(guid);
            var root = PrefabUtility.LoadPrefabContents(path);
            try
            {
                int changed = Style(root);
                if (changed > 0) PrefabUtility.SaveAsPrefabAsset(root, path);
                count += changed;
            }
            finally { PrefabUtility.UnloadPrefabContents(root); }
        }
        var previous = EditorSceneManager.GetSceneManagerSetup();
        try
        {
            foreach (string path in new[] { "Assets/_Game/Scenes/MainBakery.unity", "Assets/_Game/Scenes/Game.unity" })
            {
                var scene = EditorSceneManager.OpenScene(path);
                int changed = 0;
                foreach (var root in scene.GetRootGameObjects()) changed += Style(root, true);
                if (changed > 0) EditorSceneManager.SaveScene(scene);
                count += changed;
            }
        }
        finally
        {
            if (previous.Length > 0 && Array.TrueForAll(previous, s => !string.IsNullOrEmpty(s.path)))
                EditorSceneManager.RestoreSceneManagerSetup(previous);
            else
                EditorSceneManager.NewScene(NewSceneSetup.EmptyScene);
        }
        AssetDatabase.SaveAssets();
        Debug.Log("TITLE COLOURS | Styled " + count + " editable headings.");
    }

    public static void ApplyAndPreview()
    {
        Apply();
        CafeScreensDesigner.RenderPreviews();
    }

    private static int Style(GameObject root, bool skipPrefabInstances = false)
    {
        int count = 0;
        foreach (var text in root.GetComponentsInChildren<TMP_Text>(true))
        {
            if (skipPrefabInstances && PrefabUtility.IsPartOfPrefabInstance(text)) continue;
            string name = text.name;
            bool heading = name.IndexOf("Heading", StringComparison.OrdinalIgnoreCase) >= 0;
            bool title = name.IndexOf("Title", StringComparison.OrdinalIgnoreCase) >= 0 ||
                name == "UpgradeNameText" || name == "CafeName" || Captions.Contains(text.text.Trim());
            if (!heading && !title) continue;
            // Avoid colouring action captions just because a button repeats a title.
            if (text.GetComponentInParent<UnityEngine.UI.Selectable>(true) != null) continue;
            bool light = (text.enableVertexGradient ? text.colorGradient.topLeft : text.color).grayscale > .65f;
            bool warning = name.IndexOf("Recycle", StringComparison.OrdinalIgnoreCase) >= 0 ||
                text.text.IndexOf("deletion", StringComparison.OrdinalIgnoreCase) >= 0;
            Color a, b, c, d;
            if (warning)
            {
                a = Hex(light ? "FFBEA5" : "9A2538"); b = Hex(light ? "FFE0AF" : "A54A16"); c = a; d = b;
            }
            else if (heading)
            {
                // Subheadings use a quieter two-colour accent beneath the main title.
                a = Hex(light ? "DDD0FF" : "593184"); b = Hex(light ? "BFE7FF" : "254D85"); c = a; d = b;
            }
            else
            {
                // Four jewel tones create a rainbow-inspired gradient with readable contrast.
                a = Hex(light ? "E0C5FF" : "61319C"); b = Hex(light ? "FFBFD9" : "A02D6B");
                c = Hex(light ? "AAEADB" : "157269"); d = Hex(light ? "BEDCFF" : "285AA0");
            }
            text.color = Color.white;
            text.enableVertexGradient = true;
            text.colorGradientPreset = null;
            text.colorGradient = new VertexGradient(a, b, c, d);
            text.fontStyle |= FontStyles.Bold;
            EditorUtility.SetDirty(text);
            count++;
        }
        return count;
    }

    private static Color Hex(string value) { ColorUtility.TryParseHtmlString("#" + value, out var color); return color; }
}
#endif
