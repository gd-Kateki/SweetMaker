#if UNITY_EDITOR
using System.Linq;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.UI;

internal static class HomeButtonAuthoringEditor
{
    public static void Apply()
    {
        var scene = EditorSceneManager.OpenScene("Assets/_Game/Scenes/MainBakery.unity");
        var profile = scene.GetRootGameObjects().SelectMany(r => r.GetComponentsInChildren<CafeProfileUI>(true)).Single();
        var data = new SerializedObject(profile);
        if (data.FindProperty("cardRoot").objectReferenceValue == null)
        {
            var card = Object.Instantiate(AssetDatabase.LoadAssetAtPath<GameObject>("Assets/_Game/Resources/UI/VisualTemplates/CafeProfileCard.prefab"), profile.transform);
            card.name = "Cafe Button";
            var canvas = card.GetComponent<Canvas>(); if (canvas != null) Object.DestroyImmediate(canvas);
            foreach (var marker in card.GetComponentsInChildren<EditableUIVisual>(true)) Object.DestroyImmediate(marker);
            var rect = (RectTransform)card.transform;
            rect.anchorMin = rect.anchorMax = new Vector2(0, .5f); rect.pivot = new Vector2(.5f, .5f);
            rect.anchoredPosition = new Vector2(66, -145); rect.sizeDelta = new Vector2(96,96);
            var button = card.AddComponent<Button>(); button.targetGraphic = card.GetComponent<Image>();
            card.GetComponent<Image>().raycastTarget = true;
            card.SetActive(true);
            data.FindProperty("cardRoot").objectReferenceValue = card;
            data.ApplyModifiedPropertiesWithoutUndo();
        }
        if (!profile.transform.GetComponentsInChildren<HomeLeaderboardButton>(true).Any())
        {
            var template = AssetDatabase.LoadAssetAtPath<GameObject>("Assets/_Game/Resources/UI/VisualTemplates/Leaderboards.prefab");
            var source = template.GetComponentsInChildren<EditableUIVisual>(true).Single(p => p.targetPath == "Safe%20area:0/Leaderboards:0");
            var card = Object.Instantiate(source.gameObject, profile.transform);
            card.name = "Leaderboards Button";
            var button = card.AddComponent<Button>(); button.targetGraphic = card.GetComponent<Image>();
            button.colors = source.buttonColors;
            foreach (var marker in card.GetComponentsInChildren<EditableUIVisual>(true)) Object.DestroyImmediate(marker);
            var rect = (RectTransform)card.transform;
            rect.anchorMin = rect.anchorMax = new Vector2(0, .5f); rect.pivot = new Vector2(0,.5f);
            rect.anchoredPosition = new Vector2(175,-145); rect.localScale = Vector3.one * 1.5f;
            card.GetComponent<Image>().raycastTarget = true;
            card.AddComponent<HomeLeaderboardButton>();
            card.SetActive(true);
        }
        EditorSceneManager.MarkSceneDirty(scene);
        EditorSceneManager.SaveScene(scene);
        Debug.Log("HOME UI | Café and Leaderboards buttons are scene-authored under MainCanvas/TopBar.");
    }
}
#endif
