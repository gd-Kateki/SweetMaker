#if UNITY_EDITOR
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEngine;

internal sealed class DevelopmentAndroidIdentityValidator :
    IPreprocessBuildWithReport
{
    internal const string DevelopmentIdentifier =
        AndroidBuildIdentityGuard.DevelopmentIdentifier;
    internal const string ReleaseIdentifier =
        AndroidBuildIdentityGuard.ReleaseIdentifier;
    internal const string DevelopmentProfilePath =
        AndroidBuildIdentityGuard.DevelopmentProfilePath;
    internal const string ReleaseProfilePath =
        AndroidBuildIdentityGuard.ReleaseProfilePath;

    public int callbackOrder => 0;

    public void OnPreprocessBuild(BuildReport report)
    {
        if (report == null)
            throw new BuildFailedException(
                "Android identity validation failed because the build report is missing.");

        if (report.summary.platform != BuildTarget.Android)
            return;

        bool isDevelopmentBuild =
            (report.summary.options & BuildOptions.Development) != 0;
        AndroidBuildIdentitySnapshot identity =
            AndroidBuildIdentityGuard.Validate(report);

        Debug.Log(
            (isDevelopmentBuild
                ? "DEVELOPMENT BUILD IDENTITY"
                : "RELEASE BUILD IDENTITY") +
            " | Profile: " +
            identity.ActiveProfilePath +
            " | Android application ID: " +
            identity.ApplicationIdentifier +
            (isDevelopmentBuild
                ? " | Save mode: " +
                    SavePathPolicy.ModeName +
                    " | Save directory: " +
                    SavePathPolicy.GetSaveDirectory()
                : string.Empty));
    }
}
#endif
