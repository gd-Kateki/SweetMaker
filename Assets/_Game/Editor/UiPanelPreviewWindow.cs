#if UNITY_EDITOR
using System;
using System.Collections.Generic;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.SceneManagement;

internal sealed class UiPanelPreviewWindow : EditorWindow
{
    private const string MainBakeryScene =
        "Assets/_Game/Scenes/MainBakery.unity";
    private const string GameScene =
        "Assets/_Game/Scenes/Game.unity";

    private static readonly PreviewGroup[] Groups =
    {
        new PreviewGroup(
            "Collection overlay",
            MainBakeryScene,
            "MainCanvas/CollectionOverlay"),
        new PreviewGroup(
            "Upgrade screen",
            MainBakeryScene,
            "MainCanvas/UpgradeScreen"),
        new PreviewGroup(
            "Settings overlay",
            MainBakeryScene,
            "MainCanvas/SettingsOverlay"),
        new PreviewGroup(
            "Rebirth panel and backdrop",
            GameScene,
            "GameplayCanvas/RebirthPanel",
            "GameplayCanvas/RebirthBackdrop"),
        new PreviewGroup(
            "Order details overlay",
            GameScene,
            "GameplayCanvas/OrderDetailsOverlay"),
        new PreviewGroup(
            "Campaign completion overlay",
            GameScene,
            "GameplayCanvas/CampaignCompletionOverlay"),
        new PreviewGroup(
            "Upgrade screen",
            GameScene,
            "GameplayCanvas/UpgradeScreen"),
        new PreviewGroup(
            "Recycle confirmation overlay",
            GameScene,
            "GameplayCanvas/RecycleConfirmationController/RecycleConfirmationOverlay"),
        new PreviewGroup(
            "Settings overlay",
            GameScene,
            "GameplayCanvas/SettingsOverlay")
    };

    private string statusMessage;
    private MessageType statusType = MessageType.Info;

    [MenuItem("Tools/Sweet Maker/UI Panel Preview")]
    private static void OpenWindow()
    {
        GetWindow<UiPanelPreviewWindow>("UI Panel Preview");
    }

    private void OnDisable()
    {
        UiPanelPreviewLifecycle.RestoreAll();
    }

    private void OnGUI()
    {
        EditorGUILayout.LabelField("Temporary UI Panel Preview", EditorStyles.boldLabel);
        EditorGUILayout.HelpBox(
            "Preview states are temporary. Saving, closing, switching scenes, " +
            "entering Play Mode, closing this window, assembly reload, or Editor " +
            "shutdown restores the original active states. Edit child layout " +
            "normally; the preview controls own each approved root's active state. " +
            "Unity may leave the scene marked modified after a preview; save it to " +
            "preserve layout edits.",
            MessageType.Warning);

        Scene activeScene = SceneManager.GetActiveScene();
        EditorGUILayout.LabelField(
            "Scene being edited",
            activeScene.IsValid() && activeScene.isLoaded
                ? activeScene.path
                : "No active scene");

        bool canPreview =
            activeScene.IsValid() &&
            activeScene.isLoaded &&
            !EditorApplication.isPlayingOrWillChangePlaymode;

        using (new EditorGUI.DisabledScope(!canPreview))
        {
            using (new EditorGUILayout.HorizontalScope())
            {
                if (GUILayout.Button("Hide All"))
                    RunAction(() => UiPanelPreviewLifecycle.HideAll(activeScene));

                if (GUILayout.Button("Restore All"))
                    RunAction(() =>
                    {
                        UiPanelPreviewLifecycle.RestoreAll();
                        return null;
                    });
            }

            bool hasSceneGroups = false;
            foreach (PreviewGroup group in Groups)
            {
                if (group.ScenePath != activeScene.path)
                    continue;

                hasSceneGroups = true;
                EditorGUILayout.Space(4);
                DrawGroup(group, activeScene);
            }

            if (!hasSceneGroups)
            {
                EditorGUILayout.HelpBox(
                    "The active scene is not an approved preview scene.",
                    MessageType.Info);
            }
        }

        if (!string.IsNullOrEmpty(statusMessage))
            EditorGUILayout.HelpBox(statusMessage, statusType);
    }

    private void DrawGroup(PreviewGroup group, Scene scene)
    {
        bool isVisible = UiPanelPreviewLifecycle.IsVisible(group.Id);
        using (new EditorGUILayout.HorizontalScope())
        {
            EditorGUILayout.LabelField(group.Label, EditorStyles.boldLabel);
            GUILayout.FlexibleSpace();
            if (GUILayout.Button(isVisible ? "Preview Off" : "Preview On", GUILayout.Width(100)))
            {
                RunAction(() =>
                    UiPanelPreviewLifecycle.SetVisible(
                        group,
                        scene,
                        !isVisible));
            }
        }

        foreach (string hierarchyPath in group.HierarchyPaths)
        {
            EditorGUILayout.LabelField(
                "  " + GetDisplayPath(hierarchyPath),
                EditorStyles.miniLabel);
        }
    }

    private static string GetDisplayPath(string path)
    {
        return path.StartsWith("--- UI ---/", StringComparison.Ordinal)
            ? path.Substring("--- UI ---/".Length)
            : path;
    }

    private void RunAction(Func<string> action)
    {
        statusMessage = action();
        statusType = string.IsNullOrEmpty(statusMessage)
            ? MessageType.Info
            : MessageType.Warning;
        Repaint();
    }

    private sealed class PreviewGroup
    {
        internal readonly string Id;
        internal readonly string Label;
        internal readonly string ScenePath;
        internal readonly string[] HierarchyPaths;

        internal PreviewGroup(
            string label,
            string scenePath,
            params string[] relativePaths)
        {
            Id = scenePath + "|" + label;
            Label = label;
            ScenePath = scenePath;
            HierarchyPaths = new string[relativePaths.Length];
            for (int i = 0; i < relativePaths.Length; i++)
                HierarchyPaths[i] = "--- UI ---/" + relativePaths[i];
        }
    }

    [InitializeOnLoad]
    private static class UiPanelPreviewLifecycle
    {
        private sealed class TargetState
        {
            internal GameObject GameObject;
            internal bool OriginalActiveSelf;
        }

        private sealed class GroupState
        {
            internal Scene Scene;
            internal bool PreviewVisible;
            internal readonly List<TargetState> Targets =
                new List<TargetState>();
        }

        private static readonly Dictionary<string, GroupState> ActivePreviews =
            new Dictionary<string, GroupState>();

        static UiPanelPreviewLifecycle()
        {
            EditorApplication.playModeStateChanged += HandlePlayModeStateChanged;
            EditorApplication.quitting += RestoreAll;
            AssemblyReloadEvents.beforeAssemblyReload += RestoreAll;
            EditorSceneManager.sceneSaving += HandleSceneSaving;
            EditorSceneManager.sceneClosing += HandleSceneClosing;
            EditorSceneManager.activeSceneChangedInEditMode +=
                HandleActiveSceneChanged;
        }

        internal static bool IsVisible(string groupId)
        {
            return ActivePreviews.TryGetValue(
                       groupId,
                       out GroupState state) &&
                   state.PreviewVisible;
        }

        internal static string SetVisible(
            PreviewGroup group,
            Scene scene,
            bool visible)
        {
            if (EditorApplication.isPlayingOrWillChangePlaymode)
                return "Panel preview is available only in Edit Mode.";

            if (visible)
            {
                if (!ActivePreviews.TryGetValue(group.Id, out GroupState state))
                {
                    if (!TryCapture(group, scene, out state, out string error))
                        return error;

                    ActivePreviews.Add(group.Id, state);
                }

                SetTargetsActive(state, true);
                state.PreviewVisible = true;
                return null;
            }

            if (ActivePreviews.TryGetValue(group.Id, out GroupState existing))
                RestoreGroup(group.Id, existing);

            return null;
        }

        internal static string HideAll(Scene scene)
        {
            if (EditorApplication.isPlayingOrWillChangePlaymode)
                return "Panel preview is available only in Edit Mode.";

            List<KeyValuePair<PreviewGroup, GroupState>> pending =
                new List<KeyValuePair<PreviewGroup, GroupState>>();

            foreach (PreviewGroup group in Groups)
            {
                if (group.ScenePath != scene.path ||
                    ActivePreviews.ContainsKey(group.Id))
                {
                    continue;
                }

                if (!TryCapture(group, scene, out GroupState state, out string error))
                    return error;

                pending.Add(new KeyValuePair<PreviewGroup, GroupState>(group, state));
            }

            foreach (KeyValuePair<PreviewGroup, GroupState> entry in pending)
                ActivePreviews.Add(entry.Key.Id, entry.Value);

            foreach (PreviewGroup group in Groups)
            {
                if (group.ScenePath != scene.path ||
                    !ActivePreviews.TryGetValue(group.Id, out GroupState state))
                {
                    continue;
                }

                SetTargetsActive(state, false);
                state.PreviewVisible = false;
            }

            return null;
        }

        internal static void RestoreAll()
        {
            if (ActivePreviews.Count == 0)
                return;

            string[] ids = new string[ActivePreviews.Count];
            ActivePreviews.Keys.CopyTo(ids, 0);
            foreach (string id in ids)
            {
                if (ActivePreviews.TryGetValue(id, out GroupState state))
                    RestoreGroup(id, state);
            }
        }

        private static bool TryCapture(
            PreviewGroup group,
            Scene scene,
            out GroupState state,
            out string error)
        {
            state = null;
            error = null;
            if (!scene.IsValid() ||
                !scene.isLoaded ||
                scene.path != group.ScenePath)
            {
                error = "The approved scene is not the active loaded scene.";
                return false;
            }

            var targets = new List<GameObject>(group.HierarchyPaths.Length);
            foreach (string path in group.HierarchyPaths)
            {
                if (!TryResolvePath(scene, path, out GameObject target, out error))
                    return false;
                targets.Add(target);
            }

            state = new GroupState { Scene = scene };
            foreach (GameObject target in targets)
            {
                state.Targets.Add(new TargetState
                {
                    GameObject = target,
                    OriginalActiveSelf = target.activeSelf
                });
            }

            return true;
        }

        private static bool TryResolvePath(
            Scene scene,
            string path,
            out GameObject target,
            out string error)
        {
            target = null;
            error = null;
            string[] names = path.Split('/');
            GameObject[] roots = scene.GetRootGameObjects();
            Transform current = null;

            foreach (GameObject root in roots)
            {
                if (root.name != names[0])
                    continue;

                if (current != null)
                {
                    error = "The approved hierarchy path is ambiguous: " + path;
                    return false;
                }

                current = root.transform;
            }

            if (current == null)
            {
                error = "Could not find the approved hierarchy path: " + path;
                return false;
            }

            for (int i = 1; i < names.Length; i++)
            {
                Transform child = null;
                for (int childIndex = 0; childIndex < current.childCount; childIndex++)
                {
                    Transform candidate = current.GetChild(childIndex);
                    if (candidate.name != names[i])
                        continue;

                    if (child != null)
                    {
                        error = "The approved hierarchy path is ambiguous: " + path;
                        return false;
                    }

                    child = candidate;
                }

                if (child == null)
                {
                    error = "Could not find the approved hierarchy path: " + path;
                    return false;
                }

                current = child;
            }

            target = current.gameObject;
            return true;
        }

        private static void SetTargetsActive(GroupState state, bool active)
        {
            foreach (TargetState target in state.Targets)
            {
                if (target.GameObject != null)
                    target.GameObject.SetActive(active);
            }
        }

        private static void RestoreGroup(string id, GroupState state)
        {
            foreach (TargetState target in state.Targets)
            {
                if (target.GameObject == null)
                {
                    Debug.LogWarning(
                        "UI Panel Preview could not restore a target that no longer exists.");
                    continue;
                }

                target.GameObject.SetActive(target.OriginalActiveSelf);
            }

            ActivePreviews.Remove(id);
        }

        private static void HandlePlayModeStateChanged(PlayModeStateChange state)
        {
            if (state == PlayModeStateChange.ExitingEditMode)
                RestoreAll();
        }

        private static void HandleSceneSaving(Scene scene, string path)
        {
            RestoreScene(scene);
        }

        private static void HandleSceneClosing(Scene scene, bool removingScene)
        {
            RestoreScene(scene);
        }

        private static void HandleActiveSceneChanged(Scene previous, Scene next)
        {
            RestoreAll();
        }

        private static void RestoreScene(Scene scene)
        {
            if (!scene.IsValid() || ActivePreviews.Count == 0)
                return;

            var ids = new List<string>();
            foreach (KeyValuePair<string, GroupState> entry in ActivePreviews)
            {
                if (entry.Value.Scene.handle == scene.handle)
                    ids.Add(entry.Key);
            }

            foreach (string id in ids)
            {
                if (ActivePreviews.TryGetValue(id, out GroupState state))
                    RestoreGroup(id, state);
            }
        }
    }
}
#endif
