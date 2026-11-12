#if UNITY_EDITOR
using System.Linq;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;

internal sealed class SettingsDesignerWindow : EditorWindow
{
    internal static void Open()
    {
        GetWindow<SettingsDesignerWindow>("Settings UI").Show();
        EditorApplication.delayCall += FrameDesign;
    }

    private void OnGUI()
    {
        EditorGUILayout.LabelField("Shared Settings design", EditorStyles.boldLabel);
        EditorGUILayout.HelpBox("Edit Images, fonts, colors and layout in Prefab Mode, then save. This design is used by both Home and Gameplay. Live player text and button actions stay connected.", MessageType.Info);
        var stage = PrefabStageUtility.GetCurrentPrefabStage();
        if (stage == null || stage.assetPath != SettingsLayoutEditor.DesignPath)
        {
            if (GUILayout.Button("Open complete Settings UI")) SettingsLayoutEditor.EditSettings();
            return;
        }
        var root = stage.prefabContentsRoot;
        var content = root.GetComponentsInChildren<RectTransform>(true).Single(r => r.name == "SettingsScrollContent");
        float limit = Mathf.Max(0, content.rect.height - ((RectTransform)content.parent).rect.height);
        EditorGUILayout.LabelField("View section", EditorStyles.boldLabel);
        if (GUILayout.Button("Sound, gameplay & accessibility")) Scroll(content, 0, limit);
        if (GUILayout.Button("Account & cloud backup")) ScrollTo(content, "GooglePlayGamesAccountSettings", limit);
        if (GUILayout.Button("Advertising privacy & deletion")) ScrollTo(content, "Player privacy settings", limit);
        if (GUILayout.Button("Analytics privacy")) ScrollTo(content, "AnalyticsPrivacySettings", limit);
        float position = EditorGUILayout.Slider("Scroll preview", content.anchoredPosition.y, 0, limit);
        if (!Mathf.Approximately(position, content.anchoredPosition.y)) Scroll(content, position, limit);
        if (GUILayout.Button("Frame screen in Scene view")) FrameDesign();
        EditorGUILayout.Space();
        EditorGUILayout.HelpBox("The canvas is a design preview. Keep the bound object names and Editable UI Visual markers. Button fills use Image color; pressed/disabled tints are under Editable UI Visual. Sample text is replaced with live game values.", MessageType.None);
    }

    private static void ScrollTo(RectTransform content, string name, float limit)
    {
        var section = content.Find(name) as RectTransform;
        if (section != null) Scroll(content, -section.anchoredPosition.y - 24, limit);
    }
    private static void Scroll(RectTransform content, float value, float limit)
    {
        content.anchoredPosition = new Vector2(0, Mathf.Clamp(value, 0, limit));
        SceneView.RepaintAll();
    }
    private static void FrameDesign()
    {
        var stage = PrefabStageUtility.GetCurrentPrefabStage();
        if (stage == null || stage.assetPath != SettingsLayoutEditor.DesignPath) return;
        Selection.activeGameObject = stage.prefabContentsRoot;
        var view = SceneView.lastActiveSceneView;
        if (view != null)
        {
            var rect = (RectTransform)stage.prefabContentsRoot.transform;
            view.in2DMode = true;
            view.LookAt(rect.TransformPoint(rect.rect.center), Quaternion.identity, rect.rect.height * .6f, true);
            view.Repaint();
        }
    }
}
#endif
