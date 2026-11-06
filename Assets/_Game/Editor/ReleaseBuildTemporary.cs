#if UNITY_EDITOR
using System;
using System.IO;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Profile;
using UnityEditor.Build.Reporting;
using UnityEngine;

internal static class ReleaseBuildTemporary
{
    [InitializeOnLoadMethod]
    private static void CheckQueuedBuild()
    {
        EditorApplication.delayCall += () =>
        {
            const string request = "tmp/run-release-build.request";
            if (!File.Exists(request) || EditorApplication.isPlayingOrWillChangePlaymode) return;
            File.Delete(request);
            try { Run(); }
            catch (Exception exception)
            {
                File.WriteAllText("tmp/release-build-blocked.txt", exception.Message);
                Debug.LogException(exception);
            }
        };
    }

    [MenuItem("Tools/Build Android Release Bundle")]
    public static void Run()
    {
        Directory.CreateDirectory("tmp");
        File.WriteAllText("tmp/release-build-status.txt", "Preparing signed release build");
        try
        {
            Build();
        }
        catch (Exception exception)
        {
            File.WriteAllText("tmp/release-build-status.txt", "Failed: " + exception.Message);
            throw;
        }
    }

    private static void Build()
    {
        var profile = BuildProfile.GetBuildProfileAtPath("Assets/Settings/Build Profiles/Android Release.asset");
        if (profile == null) throw new BuildFailedException("Android Release profile is missing.");
        BuildProfile.SetActiveBuildProfile(profile);
        if (PlayerSettings.GetApplicationIdentifier(NamedBuildTarget.Android) != "com.offcutstudios.dessertmergecafe")
            throw new BuildFailedException("Release package identity is incorrect.");
        if (PlayerSettings.Android.targetSdkVersion != AndroidSdkVersions.AndroidApiLevel36)
            throw new BuildFailedException("Internal testing release must target Android API 36.");
        string storePassword = Environment.GetEnvironmentVariable("DMC_KEYSTORE_PASSWORD");
        string keyPassword = Environment.GetEnvironmentVariable("DMC_KEY_PASSWORD");
        if (!string.IsNullOrEmpty(storePassword)) PlayerSettings.Android.keystorePass = storePassword;
        if (!string.IsNullOrEmpty(keyPassword)) PlayerSettings.Android.keyaliasPass = keyPassword;
        if (!PlayerSettings.Android.useCustomKeystore ||
            !File.Exists(PlayerSettings.Android.keystoreName))
            throw new BuildFailedException("Release signing requires the configured upload keystore.");
        if (string.IsNullOrEmpty(PlayerSettings.Android.keystorePass) ||
            string.IsNullOrEmpty(PlayerSettings.Android.keyaliasPass))
            throw new BuildFailedException("RELEASE_SIGNING_PASSWORD_REQUIRED: Enter the keystore and alias passwords in Android Publishing Settings, then use Tools > Build Android Release Bundle.");

        string directory = Path.GetFullPath(Path.Combine("Builds", "Android", "Release",
            DateTime.UtcNow.ToString("yyyyMMdd-HHmmss")));
        Directory.CreateDirectory(directory);
        string output = Path.Combine(directory, "DessertMergeCafe-release.aab");
        File.WriteAllText("tmp/release-build-status.txt", "Building " + output);
        var report = BuildPipeline.BuildPlayer(new BuildPlayerWithProfileOptions
        {
            buildProfile = profile,
            locationPathName = output,
            options = BuildOptions.None
        });
        if (report == null || report.summary.result != BuildResult.Succeeded)
            throw new BuildFailedException("Android release build failed. See the Unity build log.");
        if ((report.summary.options & BuildOptions.Development) != 0)
            throw new BuildFailedException("The resulting build unexpectedly enabled development mode.");
        Debug.Log("RELEASE_BUILD_SUCCEEDED: " + output);
        File.WriteAllText("tmp/latest-release-build.txt", output);
        File.WriteAllText("tmp/release-build-status.txt", "Succeeded: " + output);
        File.WriteAllText(Path.Combine(directory, "build-info.txt"),
            "Package: " + PlayerSettings.GetApplicationIdentifier(NamedBuildTarget.Android) + "\n" +
            "Version: " + PlayerSettings.bundleVersion + "\nVersion code: " + PlayerSettings.Android.bundleVersionCode + "\n" +
            "Target SDK: " + PlayerSettings.Android.targetSdkVersion + "\n" +
            "Development build: false\nUGS environment: production\n" +
            "Upload track: Google Play internal testing\n");
    }
}
#endif
