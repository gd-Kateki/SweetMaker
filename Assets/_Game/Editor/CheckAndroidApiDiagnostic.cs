#if UNITY_EDITOR
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Profile;

internal static class CheckAndroidApiDiagnostic
{
    [MenuItem("Tools/DMC/Diagnostics/Check Android API")]
    private static void CheckAndroidApi()
    {
        BuildProfile activeProfile = BuildProfile.GetActiveBuildProfile();
        string profileName = activeProfile == null
            ? "<none>"
            : activeProfile.name;
        string profilePath = activeProfile == null
            ? "<none>"
            : AssetDatabase.GetAssetPath(activeProfile);

        AndroidSdkVersions minimumApi =
            PlayerSettings.Android.minSdkVersion;
        AndroidSdkVersions targetApi =
            PlayerSettings.Android.targetSdkVersion;

        string targetDescription;
        if (targetApi == AndroidSdkVersions.AndroidApiLevelAuto)
        {
            targetDescription = "Automatic";
        }
        else if (targetApi == AndroidSdkVersions.AndroidApiLevel36)
        {
            targetDescription = "Explicit API 36";
        }
        else
        {
            targetDescription = "Explicit/other (" + targetApi + ")";
        }

        UnityEngine.Debug.Log(
            "DMC Android API diagnostic | " +
            "Active Build Profile: " + profileName +
            " | Asset path: " + profilePath +
            " | Effective minimum API: " + minimumApi +
            " (" + (int)minimumApi + ")" +
            " | Effective target API: " + targetApi +
            " (" + (int)targetApi + ")" +
            " | Target classification: " + targetDescription +
            " | Customized Player Settings: not queried; no documented public BuildProfile API exposes this state.");
    }
}
#endif
