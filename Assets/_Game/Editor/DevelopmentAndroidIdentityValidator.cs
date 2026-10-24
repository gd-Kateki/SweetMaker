#if UNITY_EDITOR
using System;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEngine;

internal sealed class DevelopmentAndroidIdentityValidator :
    IPreprocessBuildWithReport
{
    private const string DevelopmentIdentifierSuffix = ".dev";

    public int callbackOrder => 0;

    public void OnPreprocessBuild(BuildReport report)
    {
        if (report == null ||
            report.summary.platform != BuildTarget.Android ||
            (report.summary.options & BuildOptions.Development) == 0)
        {
            return;
        }

        string identifier =
            PlayerSettings.GetApplicationIdentifier(
                NamedBuildTarget.Android);
        if (string.IsNullOrWhiteSpace(identifier) ||
            !identifier.EndsWith(
                DevelopmentIdentifierSuffix,
                StringComparison.OrdinalIgnoreCase))
        {
            throw new BuildFailedException(
                "Android Development Builds require a distinct application " +
                "identifier ending in '.dev'. The development save directory " +
                "is isolated, but a separate identifier prevents installing " +
                "the development build over the release app.");
        }

        Debug.Log(
            "DEVELOPMENT BUILD IDENTITY | Android application ID: " +
            identifier +
            " | Save mode: " +
            SavePathPolicy.ModeName +
            " | Save directory: " +
            SavePathPolicy.GetSaveDirectory());
    }
}
#endif
