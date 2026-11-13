using UnityEngine;

// Metadata for linked editing copies; its EditorOnly parent is stripped from play/build scenes.
[AddComponentMenu("")]
public sealed class SceneUiDesign : MonoBehaviour
{
    [HideInInspector] public string assetPath;
    public GameObject Design => transform.childCount == 1 ? transform.GetChild(0).gameObject : null;
}
