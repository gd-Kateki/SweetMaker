using UnityEngine;

[CreateAssetMenu(menuName = "Sweet Merge/Testing/Developer Testing Settings")]
public sealed class DeveloperTestingSettings : ScriptableObject
{
    [Tooltip("Include the cheat panel in non-development Android builds for QA. Turn off before public distribution.")]
    public bool enableProductionCheatPanel;
}

public static class DeveloperCheatAccess
{
    public static bool Allowed => IsAllowed(Application.isEditor, Application.platform == RuntimePlatform.Android,
        Debug.isDebugBuild, Resources.Load<DeveloperTestingSettings>("DeveloperTestingSettings")?.enableProductionCheatPanel == true);
    internal static bool IsAllowed(bool editor, bool android, bool development, bool productionEnabled) =>
        editor || (android && (development || productionEnabled));
}
