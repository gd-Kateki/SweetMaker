#if UNITY_EDITOR
using System;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEngine;

internal sealed class DevelopmentAndroidIdentityValidator :
    IPreprocessBuildWithReport,
    IPostprocessBuildWithReport
{
    private const string DevelopmentIdentifier =
        "com.offcutstudios.dessertmergecafe.dev";
    private const string ReleaseIdentifier =
        "com.offcutstudios.dessertmergecafe";

    public int callbackOrder => 0;

    public void OnPreprocessBuild(BuildReport report)
    {
        if (report == null)
            throw new BuildFailedException(
                "Android application identity could not be selected because the build report is missing.");

        if (report.summary.platform != BuildTarget.Android)
        {
            return;
        }

        bool isDevelopmentBuild =
            (report.summary.options & BuildOptions.Development) != 0;
        string expectedIdentifier = isDevelopmentBuild
            ? DevelopmentIdentifier
            : ReleaseIdentifier;

        try
        {
            SetAndValidateIdentifier(expectedIdentifier);
        }
        catch (BuildFailedException selectionException)
        {
            try
            {
                SetAndValidateIdentifier(DevelopmentIdentifier);
            }
            catch (BuildFailedException restorationException)
            {
                throw new BuildFailedException(
                    selectionException.Message +
                    " Restoring the development application ID also failed: " +
                    restorationException.Message);
            }

            throw;
        }

        if (isDevelopmentBuild)
        {
            Debug.Log(
                "DEVELOPMENT BUILD IDENTITY | Android application ID: " +
                expectedIdentifier +
                " | Save mode: " +
                SavePathPolicy.ModeName +
                " | Save directory: " +
                SavePathPolicy.GetSaveDirectory());
        }
        else
        {
            Debug.Log(
                "RELEASE BUILD IDENTITY | Android application ID: " +
                expectedIdentifier);
        }
    }

    public void OnPostprocessBuild(BuildReport report)
    {
        if (report == null ||
            report.summary.platform != BuildTarget.Android)
        {
            return;
        }

        SetAndValidateIdentifier(DevelopmentIdentifier);
    }

    private static void SetAndValidateIdentifier(string expectedIdentifier)
    {
        try
        {
            PlayerSettings.SetApplicationIdentifier(
                NamedBuildTarget.Android,
                expectedIdentifier);

            string actualIdentifier =
                PlayerSettings.GetApplicationIdentifier(
                    NamedBuildTarget.Android);
            if (!string.Equals(
                    actualIdentifier,
                    expectedIdentifier,
                    StringComparison.Ordinal))
            {
                throw new BuildFailedException(
                    "Android application ID configuration mismatch. Expected '" +
                    expectedIdentifier +
                    "' but found '" +
                    (actualIdentifier ?? "<null>") +
                    "'.");
            }
        }
        catch (BuildFailedException)
        {
            throw;
        }
        catch (Exception exception)
        {
            throw new BuildFailedException(
                "Could not configure Android application ID '" +
                expectedIdentifier +
                "': " +
                exception.Message);
        }
    }
}
#endif
