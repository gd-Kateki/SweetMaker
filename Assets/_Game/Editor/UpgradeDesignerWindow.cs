#if UNITY_EDITOR
using System.Linq;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;

internal sealed class UpgradeDesignerWindow : EditorWindow
{
    internal static void Open() => GetWindow<UpgradeDesignerWindow>("Upgrade UI").Show();
    private void OnGUI()
    {
        EditorGUILayout.HelpBox("This shared screen is used in Home and Gameplay. Edit its header and frame here. Edit UpgradeCard for the shared card style; keep each card's upgrade definition and controller references.", MessageType.Info);
        if (GUILayout.Button("Edit complete Upgrade screen")) UpgradeDesignerEditor.EditScreen();
        if (GUILayout.Button("Edit shared Upgrade card style")) UpgradeDesignerEditor.EditCard();
        var stage = PrefabStageUtility.GetCurrentPrefabStage();
        if (stage == null || stage.assetPath != UpgradeDesignerEditor.ScreenPath) return;
        var root = stage.prefabContentsRoot;
        var content = root.GetComponentsInChildren<RectTransform>(true).Single(t => t.name == "UpgradeContent");
        float max = Mathf.Max(0, content.rect.height - ((RectTransform)content.parent).rect.height);
        EditorGUILayout.LabelField("Preview cards", EditorStyles.boldLabel);
        if (GUILayout.Button("Top of screen")) content.anchoredPosition = Vector2.zero;
        foreach (Transform card in content)
            if (GUILayout.Button(card.name)) content.anchoredPosition = new Vector2(0, Mathf.Clamp(-((RectTransform)card).anchoredPosition.y, 0, max));
        float position = EditorGUILayout.Slider("Scroll preview", content.anchoredPosition.y, 0, max);
        if (!Mathf.Approximately(position, content.anchoredPosition.y)) content.anchoredPosition = new Vector2(0, position);
        if (GUILayout.Button("Frame screen in Scene view"))
        {
            Selection.activeGameObject = root;
            if (SceneView.lastActiveSceneView != null) { SceneView.lastActiveSceneView.in2DMode = true; SceneView.lastActiveSceneView.FrameSelected(); }
        }
        if (GUI.changed) SceneView.RepaintAll();
    }
}
#endif
