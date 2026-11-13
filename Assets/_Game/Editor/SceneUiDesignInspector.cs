#if UNITY_EDITOR
using UnityEditor;
using UnityEngine;

[CustomEditor(typeof(SceneUiDesign))]
internal sealed class SceneUiDesignInspector : Editor
{
    public override void OnInspectorGUI()
    {
        var design = (SceneUiDesign)target;
        EditorGUILayout.HelpBox("Expand this entry to edit its linked UI. Save the design to update the shared prefab used by the game. Shared screens update in every scene. Editing copies are excluded from builds.", MessageType.Info);
        EditorGUILayout.ObjectField("Shared design", AssetDatabase.LoadAssetAtPath<GameObject>(design.assetPath), typeof(GameObject), false);
        if (GUILayout.Button("Preview this UI")) SceneUiHierarchyEditor.Show(design, design.Design?.transform);
        if (GUILayout.Button("Hide UI previews")) design.transform.parent.gameObject.SetActive(false);
        using (new EditorGUI.DisabledScope(EditorApplication.isPlayingOrWillChangePlaymode || design.Design == null))
        {
            if (GUILayout.Button("Save design to game"))
            {
                PrefabUtility.ApplyPrefabInstance(design.Design, InteractionMode.UserAction);
                AssetDatabase.SaveAssets();
            }
            if (GUILayout.Button("Open shared prefab")) AssetDatabase.OpenAsset(AssetDatabase.LoadAssetAtPath<GameObject>(design.assetPath));
        }
    }
}
#endif
