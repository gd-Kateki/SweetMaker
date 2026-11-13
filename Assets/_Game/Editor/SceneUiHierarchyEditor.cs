#if UNITY_EDITOR
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEngine;
using UnityEngine.SceneManagement;

[InitializeOnLoad]
internal static class SceneUiHierarchyEditor
{
    internal const string GroupName = "UI Designs (Editor Only)";
    private const string Folder = "Assets/_Game/Resources/UI/VisualTemplates/";
    private static readonly string[] Shared = {
        "SettingsArtwork", "AccountDeletion", "AdvertisingPrivacy_Unknown", "AdvertisingPrivacy_Under13",
        "AdvertisingPrivacy_Teen", "AdvertisingPrivacy_Adult", "AnalyticsPrompt", "CloudProgressChoice",
        "CloudRestoreRestart", "EnergyHUD", "RewardedEnergy", "AndroidLogConsole"
    };
    private static readonly Dictionary<string, string[]> Screens = new Dictionary<string, string[]> {
        { "MainBakery", Shared.Concat(new[] { "StartupWelcome", "StartupLoading", "StartupDependencyError",
            "CafeProfileCard", "CafeProfilePanel", "CafeNaming", "Leaderboards", "LeaderboardRow",
            "TutorialWelcome", "TutorialWelcomeBackdrop", "FeatureIntroduction" }).ToArray() },
        { "Game", Shared.Concat(new[] { "RewardedCash", "FeatureIntroduction", "TutorialInstruction",
            "TutorialRecovery", "TutorialHighlight", "DeveloperCheatsV2", "DeveloperButtonV2" }).ToArray() },
        { "Welcome", new[] { "StartupWelcome", "StartupDependencyError", "CloudProgressChoice", "CloudRestoreRestart" } },
        { "Loading", new[] { "DevelopmentLoading", "StartupDependencyError", "CloudProgressChoice", "CloudRestoreRestart" } }
    };

    static SceneUiHierarchyEditor()
    {
        EditorApplication.playModeStateChanged += state => {
            if (state != PlayModeStateChange.ExitingEditMode) return;
            // EditorOnly removes these in builds; also hide them for Editor Play Mode.
            foreach (var entry in Resources.FindObjectsOfTypeAll<SceneUiDesign>())
                if (entry.gameObject.scene.IsValid() && entry.transform.parent != null && entry.transform.parent.CompareTag("EditorOnly"))
                    entry.transform.parent.gameObject.SetActive(false);
        };
    }

    [MenuItem("Tools/Sweet Maker/UI/Add Scene UI Designs")]
    public static void Install()
    {
        if (!Application.isBatchMode && !EditorSceneManager.SaveCurrentModifiedScenesIfUserWantsTo()) return;
        var previous = EditorSceneManager.GetSceneManagerSetup();
        try
        {
            foreach (var pair in Screens)
            {
                var scene = EditorSceneManager.OpenScene("Assets/_Game/Scenes/" + pair.Key + ".unity");
                var group = scene.GetRootGameObjects().FirstOrDefault(r => r.name == GroupName);
                if (group == null) group = new GameObject(GroupName);
                group.tag = "EditorOnly";
                group.SetActive(false);
                foreach (var key in pair.Value) Add(group.transform, Folder + key + ".prefab");
                EditorSceneManager.MarkSceneDirty(scene);
                EditorSceneManager.SaveScene(scene);
            }
            Validate();
            Debug.Log("SCENE UI | Installed linked, editor-only UI designs in all four scenes.");
        }
        finally
        {
            if (previous.Length > 0 && Array.TrueForAll(previous, s => !string.IsNullOrEmpty(s.path)))
                EditorSceneManager.RestoreSceneManagerSetup(previous);
            else EditorSceneManager.NewScene(NewSceneSetup.EmptyScene);
        }
    }

    private static void Add(Transform group, string path)
    {
        if (group.GetComponentsInChildren<SceneUiDesign>(true).Any(e => e.assetPath == path)) return;
        var asset = AssetDatabase.LoadAssetAtPath<GameObject>(path);
        if (asset == null) throw new InvalidOperationException("Missing UI design: " + path);
        var wrapper = new GameObject(Path.GetFileNameWithoutExtension(path));
        wrapper.transform.SetParent(group, false);
        wrapper.SetActive(false);
        wrapper.AddComponent<SceneUiDesign>().assetPath = path;
        PrefabUtility.InstantiatePrefab(asset, wrapper.transform);
    }

    [MenuItem("Tools/Sweet Maker/UI/Preview Selected Scene UI")]
    private static void PreviewSelected()
    {
        var selected = Selection.activeTransform;
        var entry = selected != null ? selected.GetComponentInParent<SceneUiDesign>(true) : null;
        if (entry != null) Show(entry, selected == entry.transform ? entry.Design?.transform : selected);
    }

    internal static void Show(SceneUiDesign entry, Transform selected)
    {
        if (EditorApplication.isPlayingOrWillChangePlaymode || selected == null) return;
        Undo.RegisterFullObjectHierarchyUndo(entry.transform.parent.gameObject, "Preview UI design");
        foreach (Transform sibling in entry.transform.parent) sibling.gameObject.SetActive(sibling == entry.transform);
        entry.transform.parent.gameObject.SetActive(true);
        for (var value = selected; value != null && value != entry.transform.parent; value = value.parent)
            value.gameObject.SetActive(true);
        Selection.activeGameObject = selected.gameObject;
        SceneView.lastActiveSceneView?.FrameSelected();
        SceneView.RepaintAll();
    }

    public static void Validate()
    {
        var covered = new HashSet<string>();
        foreach (var pair in Screens)
        {
            var scene = EditorSceneManager.OpenPreviewScene("Assets/_Game/Scenes/" + pair.Key + ".unity");
            try
            {
                var group = scene.GetRootGameObjects().Single(r => r.name == GroupName);
                if (!group.CompareTag("EditorOnly") || group.activeSelf) throw new InvalidOperationException("Unsafe UI preview group: " + pair.Key);
                var entries = group.GetComponentsInChildren<SceneUiDesign>(true);
                if (entries.Select(e => e.assetPath).Distinct().Count() != entries.Length) throw new InvalidOperationException("Duplicate UI designs: " + pair.Key);
                foreach (var key in pair.Value)
                    if (!entries.Any(e => e.assetPath == Folder + key + ".prefab")) throw new InvalidOperationException("Missing scene UI: " + key);
                foreach (var entry in entries)
                {
                    if (entry.Design == null || PrefabUtility.GetPrefabAssetPathOfNearestInstanceRoot(entry.Design) != entry.assetPath)
                        throw new InvalidOperationException("Broken design link: " + entry.name);
                    covered.Add(entry.assetPath);
                }
            }
            finally { EditorSceneManager.ClosePreviewScene(scene); }
        }
        foreach (var guid in AssetDatabase.FindAssets("t:Prefab", new[] { Folder.TrimEnd('/') }))
            if (!covered.Contains(AssetDatabase.GUIDToAssetPath(guid))) throw new InvalidOperationException("Unassigned UI design: " + AssetDatabase.GUIDToAssetPath(guid));
    }
}

// Also strips design copies when scenes are loaded for Editor Play Mode.
internal sealed class SceneUiDesignBuildProcessor : IProcessSceneWithReport
{
    public int callbackOrder => -10000;
    public void OnProcessScene(Scene scene, BuildReport report)
    {
        foreach (var root in scene.GetRootGameObjects())
            if (root.name == SceneUiHierarchyEditor.GroupName && root.CompareTag("EditorOnly"))
                UnityEngine.Object.DestroyImmediate(root);
    }
}
#endif
