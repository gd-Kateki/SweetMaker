#if UNITY_EDITOR
using System;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Profile;
using UnityEditor.Build.Reporting;
using UnityEngine;

internal sealed class DevelopmentAndroidIdentityValidator :
    IPreprocessBuildWithReport
{
    internal const string DevelopmentIdentifier =
        "com.offcutstudios.dessertmergecafe.dev";
    internal const string ReleaseIdentifier =
        "com.offcutstudios.dessertmergecafe";
    internal const string DevelopmentProfilePath =
        "Assets/Settings/Build Profiles/Android Dev.asset";
    internal const string ReleaseProfilePath =
        "Assets/Settings/Build Profiles/Android Release.asset";

    public int callbackOrder => 0;

    public void OnPreprocessBuild(BuildReport report)
    {
        if (report == null)
            throw new BuildFailedException(
                "Android identity validation failed because the build report is missing.");

        if (report.summary.platform != BuildTarget.Android)
            return;

        BuildProfile activeProfile = BuildProfile.GetActiveBuildProfile();
        string profilePath = NormalizeAssetPath(
            AssetDatabase.GetAssetPath(activeProfile));
        bool isDevelopmentBuild =
            (report.summary.options & BuildOptions.Development) != 0;
        string expectedProfilePath = isDevelopmentBuild
            ? DevelopmentProfilePath
            : ReleaseProfilePath;
        string expectedIdentifier = isDevelopmentBuild
            ? DevelopmentIdentifier
            : ReleaseIdentifier;

        if (!string.Equals(
                profilePath,
                expectedProfilePath,
                StringComparison.Ordinal))
        {
            throw new BuildFailedException(
                "Android build used profile '" +
                (profilePath ?? "<none>") +
                "'; expected '" +
                expectedProfilePath +
                "'.");
        }

        string effectiveIdentifier;
        try
        {
            effectiveIdentifier =
                PlayerSettings.GetApplicationIdentifier(
                    NamedBuildTarget.Android);
        }
        catch (Exception exception)
        {
            throw new BuildFailedException(
                "Could not read the effective Android application ID: " +
                exception.Message);
        }

        if (!string.Equals(
                effectiveIdentifier,
                expectedIdentifier,
                StringComparison.Ordinal))
        {
            throw new BuildFailedException(
                "Android profile identity mismatch for '" +
                profilePath +
                "'. Expected '" +
                expectedIdentifier +
                "' but found '" +
                (effectiveIdentifier ?? "<null>") +
                "'.");
        }

        Debug.Log(
            (isDevelopmentBuild
                ? "DEVELOPMENT BUILD IDENTITY"
                : "RELEASE BUILD IDENTITY") +
            " | Profile: " +
            profilePath +
            " | Android application ID: " +
            effectiveIdentifier +
            (isDevelopmentBuild
                ? " | Save mode: " +
                    SavePathPolicy.ModeName +
                    " | Save directory: " +
                    SavePathPolicy.GetSaveDirectory()
                : string.Empty));
    }

    private static string NormalizeAssetPath(string path)
    {
        return string.IsNullOrWhiteSpace(path)
            ? null
            : path.Replace('\\', '/');
    }
}
#endif
