using System.Collections.Generic;
using UnityEngine;

// Tracks the actual overlay root, including home panels that do not take a gameplay lease.
public sealed class HomeOverlayVisibility : MonoBehaviour
{
    private static readonly HashSet<HomeOverlayVisibility> overlays = new HashSet<HomeOverlayVisibility>();

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
    private static void ResetState() => overlays.Clear();

    public static void Attach(GameObject root)
    {
        if (root == null) return;
        var view = root.GetComponent<HomeOverlayVisibility>();
        if (view == null) view = root.AddComponent<HomeOverlayVisibility>();
        overlays.Add(view);
    }

    public static bool IsAnyVisible
    {
        get
        {
            overlays.RemoveWhere(view => view == null);
            foreach (var view in overlays)
                if (view != null && view.isActiveAndEnabled) return true;
            return false;
        }
    }

    private void OnEnable() => overlays.Add(this);
    private void OnDestroy() => overlays.Remove(this);
}
