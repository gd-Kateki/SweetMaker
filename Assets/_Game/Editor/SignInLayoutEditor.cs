#if UNITY_EDITOR
using System.Linq;
using TMPro;
using UnityEditor;
using UnityEngine;

internal static class SignInLayoutEditor
{
    public static void Apply()
    {
        const string path = "Assets/_Game/Resources/UI/VisualTemplates/StartupWelcome.prefab";
        var root = PrefabUtility.LoadPrefabContents(path);
        try
        {
            var welcome = root.GetComponentsInChildren<RectTransform>(true).Single(t => t.name == "WelcomeScreen");
            // Bake the current artwork positions into proportional anchors. This removes
            // reference-resolution pixel offsets without redesigning the authored screen.
            foreach (var rect in welcome.GetComponentsInChildren<RectTransform>(true).Reverse())
            {
                if (rect == welcome || !(rect.parent is RectTransform parent)) continue;
                Rect bounds = parent.rect;
                if (bounds.width <= 0 || bounds.height <= 0) continue;
                Vector3[] corners = new Vector3[4]; rect.GetWorldCorners(corners);
                Vector3 min = parent.InverseTransformPoint(corners[0]);
                Vector3 max = parent.InverseTransformPoint(corners[2]);
                rect.anchorMin = new Vector2((min.x - bounds.xMin) / bounds.width, (min.y - bounds.yMin) / bounds.height);
                rect.anchorMax = new Vector2((max.x - bounds.xMin) / bounds.width, (max.y - bounds.yMin) / bounds.height);
                rect.localScale = Vector3.one;
                rect.offsetMin = rect.offsetMax = Vector2.zero;
            }
            foreach (string name in new[] { "GoogleSignInButton", "GuestPlayButton" })
                foreach (var text in welcome.GetComponentsInChildren<TMP_Text>(true).Where(t => t.transform.parent.name == name))
                    text.text = string.Empty;
            PrefabUtility.SaveAsPrefabAsset(root, path);
        }
        finally { PrefabUtility.UnloadPrefabContents(root); }
        Debug.Log("SIGN-IN UI | Removed duplicate captions and normalized the existing screen layout.");
    }
}
#endif
