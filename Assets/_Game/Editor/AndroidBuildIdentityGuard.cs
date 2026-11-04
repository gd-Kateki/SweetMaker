#if UNITY_EDITOR
using System;
using System.Linq;
using GooglePlayGames;
using SweetMerge.Authentication;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Profile;
using UnityEditor.Build.Reporting;
using UnityEngine;

internal sealed class AndroidBuildIdentitySnapshot
{
    internal readonly string ActiveProfilePath;
    internal readonly string ApplicationIdentifier;
    internal readonly bool RequestedDevelopmentBuild;
    internal readonly bool? ProfileDevelopmentBuild;
    internal readonly string[] ScenePaths;
    internal readonly bool[] SceneEnabled;
    internal readonly bool[] SceneExists;
    internal readonly bool? UsesIl2Cpp;
    internal readonly bool? Arm64Enabled;
    internal readonly int? MinimumApiLevel;
    internal readonly bool? TargetApiIsAutomatic;
    internal readonly int? TargetApiLevel;

    internal AndroidBuildIdentitySnapshot(
        string activeProfilePath,
        string applicationIdentifier,
        bool requestedDevelopmentBuild,
        bool? profileDevelopmentBuild,
        string[] scenePaths,
        bool[] sceneEnabled,
        bool[] sceneExists,
        bool? usesIl2Cpp,
        bool? arm64Enabled,
        int? minimumApiLevel,
        bool? targetApiIsAutomatic,
        int? targetApiLevel)
    {
        ActiveProfilePath = activeProfilePath;
        ApplicationIdentifier = applicationIdentifier;
        RequestedDevelopmentBuild = requestedDevelopmentBuild;
        ProfileDevelopmentBuild = profileDevelopmentBuild;
        ScenePaths = scenePaths == null ? null : (string[])scenePaths.Clone();
        SceneEnabled = sceneEnabled == null ? null : (bool[])sceneEnabled.Clone();
        SceneExists = sceneExists == null ? null : (bool[])sceneExists.Clone();
        UsesIl2Cpp = usesIl2Cpp;
        Arm64Enabled = arm64Enabled;
        MinimumApiLevel = minimumApiLevel;
        TargetApiIsAutomatic = targetApiIsAutomatic;
        TargetApiLevel = targetApiLevel;
    }
}

internal static class AndroidBuildIdentityGuard
{
    internal const string DevelopmentIdentifier =
        "com.offcutstudios.dessertmergecafe.dev";
    internal const string ReleaseIdentifier =
        "com.offcutstudios.dessertmergecafe";
    internal const string DevelopmentProfilePath =
        "Assets/Settings/Build Profiles/Android Dev.asset";
    internal const string ReleaseProfilePath =
        "Assets/Settings/Build Profiles/Android Release.asset";

    private static readonly string[] DevelopmentScenes =
    {
        "Assets/_Game/Scenes/Welcome.unity",
        "Assets/_Game/Scenes/Loading.unity",
        "Assets/_Game/Scenes/MainBakery.unity",
        "Assets/_Game/Scenes/Game.unity"
    };

    private static readonly string[] ReleaseScenes =
    {
        "Assets/_Game/Scenes/MainBakery.unity",
        "Assets/_Game/Scenes/Game.unity"
    };

    internal static AndroidBuildIdentitySnapshot Validate(BuildReport report)
    {
        if (report == null)
            throw new BuildFailedException(
                "Android identity validation failed because the build report is missing.");

        if (report.summary.platform != BuildTarget.Android)
            throw new BuildFailedException(
                "Android identity validation was invoked for a non-Android build.");

        bool requestedDevelopmentBuild =
            (report.summary.options & BuildOptions.Development) != 0;
        AndroidBuildIdentitySnapshot snapshot;
        try
        {
            snapshot = CaptureSnapshot(requestedDevelopmentBuild);
        }
        catch (Exception exception)
        {
            throw new BuildFailedException(
                "Could not read effective Android Build Profile settings: " +
                exception.Message);
        }

        string validationError = ValidateSnapshot(
            snapshot,
            requestedDevelopmentBuild);
        if (validationError != null)
            throw new BuildFailedException(validationError);

        return snapshot;
    }

    internal static string ValidateSnapshot(
        AndroidBuildIdentitySnapshot snapshot,
        bool expectedDevelopmentBuild)
    {
        if (snapshot == null)
            return "Android identity validation failed because the settings snapshot is missing.";

        string expectedProfilePath = expectedDevelopmentBuild
            ? DevelopmentProfilePath
            : ReleaseProfilePath;
        string expectedIdentifier = expectedDevelopmentBuild
            ? DevelopmentIdentifier
            : ReleaseIdentifier;
        string[] expectedScenes = expectedDevelopmentBuild
            ? DevelopmentScenes
            : ReleaseScenes;

        if (string.IsNullOrWhiteSpace(snapshot.ActiveProfilePath))
            return "Android build has no active Build Profile.";

        if (!string.Equals(
                NormalizeAssetPath(snapshot.ActiveProfilePath),
                expectedProfilePath,
                StringComparison.Ordinal))
        {
            return "Android build used profile '" +
                snapshot.ActiveProfilePath +
                "'; expected '" +
                expectedProfilePath +
                "'.";
        }

        if (snapshot.RequestedDevelopmentBuild != expectedDevelopmentBuild)
            return "Android BuildOptions.Development does not match the requested build mode.";

        if (!snapshot.ProfileDevelopmentBuild.HasValue)
            return "Could not determine the Development mode of the active Android Build Profile.";

        if (snapshot.ProfileDevelopmentBuild.Value != expectedDevelopmentBuild ||
            snapshot.ProfileDevelopmentBuild.Value !=
                snapshot.RequestedDevelopmentBuild)
        {
            return "Android Build Profile Development mode does not match BuildOptions.Development.";
        }

        if (string.IsNullOrWhiteSpace(snapshot.ApplicationIdentifier))
            return "The effective Android application identifier is missing.";

        if (!string.Equals(
                snapshot.ApplicationIdentifier,
                expectedIdentifier,
                StringComparison.Ordinal))
        {
            return "Android profile identity mismatch. Expected '" +
                expectedIdentifier +
                "' but found '" +
                snapshot.ApplicationIdentifier +
                "'.";
        }

        string oauthConfigurationError =
            ValidateGooglePlayGamesOAuthConfiguration(
                snapshot.ApplicationIdentifier);
        if (oauthConfigurationError != null)
            return oauthConfigurationError;

        if (snapshot.ScenePaths == null ||
            snapshot.SceneEnabled == null ||
            snapshot.SceneExists == null)
        {
            return "Could not determine the effective Android Build Profile scene list.";
        }

        if (snapshot.ScenePaths.Length != expectedScenes.Length ||
            snapshot.SceneEnabled.Length != expectedScenes.Length ||
            snapshot.SceneExists.Length != expectedScenes.Length)
        {
            return "Android Build Profile must contain exactly the required scenes, with no missing or unexpected entries.";
        }

        for (int index = 0; index < expectedScenes.Length; index++)
        {
            if (!snapshot.SceneExists[index])
                return "Required Android scene is missing: " +
                    expectedScenes[index] +
                    ".";

            if (!snapshot.SceneEnabled[index])
                return "Required Android scene is not enabled: " +
                    expectedScenes[index] +
                    ".";

            if (!string.Equals(
                    NormalizeAssetPath(snapshot.ScenePaths[index]),
                    expectedScenes[index],
                    StringComparison.Ordinal))
            {
                return "Android Build Profile scenes are missing, unexpected, duplicated, or out of order.";
            }
        }

        if (!snapshot.UsesIl2Cpp.HasValue)
            return "Could not determine the effective Android scripting backend.";

        if (!snapshot.UsesIl2Cpp.Value)
            return "Android builds require the IL2CPP scripting backend.";

        if (!snapshot.Arm64Enabled.HasValue)
            return "Could not determine the effective Android target architectures.";

        if (!snapshot.Arm64Enabled.Value)
            return "Android builds require the ARM64 architecture.";

        if (!snapshot.MinimumApiLevel.HasValue)
            return "Could not determine the effective Android minimum API level.";

        if (!snapshot.TargetApiIsAutomatic.HasValue)
            return "Could not determine the effective Android target API setting.";

        return GooglePlayGamesAndroidBuildRequirements.ValidateApiLevels(
            snapshot.MinimumApiLevel.Value,
            snapshot.TargetApiIsAutomatic.Value,
            snapshot.TargetApiLevel,
            expectedDevelopmentBuild);
    }

    private static string ValidateGooglePlayGamesOAuthConfiguration(
        string applicationIdentifier)
    {
        PlayGamesSettings settings =
            AssetDatabase.LoadAssetAtPath<PlayGamesSettings>(
                "Assets/GooglePlayGames/Resources/PlayGamesSettings.asset");

        try
        {
            GooglePlayGamesWebClientResolver.Resolve(
                applicationIdentifier,
                settings == null ? null : settings.WebClientId,
                GooglePlayGamesWebClientResolver.ProductionWebClientId);
            return null;
        }
        catch (System.InvalidOperationException)
        {
            return "Android build is blocked because its Google Play Games Web OAuth client mapping is missing or invalid.";
        }
    }

    private static AndroidBuildIdentitySnapshot CaptureSnapshot(
        bool requestedDevelopmentBuild)
    {
        BuildProfile activeProfile = BuildProfile.GetActiveBuildProfile();
        string profilePath = NormalizeAssetPath(
            AssetDatabase.GetAssetPath(activeProfile));
        EditorBuildSettingsScene[] scenes = activeProfile == null
            ? null
            : activeProfile.GetScenesForBuild();

        string[] scenePaths = scenes == null
            ? null
            : scenes.Select(scene => scene == null ? null : scene.path).ToArray();
        bool[] sceneEnabled = scenes == null
            ? null
            : scenes.Select(scene => scene != null && scene.enabled).ToArray();
        bool[] sceneExists = scenes == null
            ? null
            : scenes.Select(scene =>
                scene != null &&
                AssetDatabase.LoadAssetAtPath<SceneAsset>(scene.path) != null)
                .ToArray();

        AndroidSdkVersions minimumApi = PlayerSettings.Android.minSdkVersion;
        AndroidSdkVersions targetApi = PlayerSettings.Android.targetSdkVersion;
        bool targetApiIsKnown = Enum.IsDefined(
            typeof(AndroidSdkVersions),
            targetApi);
        bool targetApiIsAutomatic = targetApiIsKnown &&
            targetApi == AndroidSdkVersions.AndroidApiLevelAuto;
        int? targetApiLevel = targetApiIsKnown && !targetApiIsAutomatic
            ? (int)targetApi
            : (int?)null;

        return new AndroidBuildIdentitySnapshot(
            profilePath,
            PlayerSettings.GetApplicationIdentifier(
                NamedBuildTarget.Android),
            requestedDevelopmentBuild,
            activeProfile == null
                ? (bool?)null
                : EditorUserBuildSettings.development,
            scenePaths,
            sceneEnabled,
            sceneExists,
            PlayerSettings.GetScriptingBackend(
                NamedBuildTarget.Android) == ScriptingImplementation.IL2CPP,
            (PlayerSettings.Android.targetArchitectures &
             AndroidArchitecture.ARM64) != 0,
            Enum.IsDefined(typeof(AndroidSdkVersions), minimumApi)
                ? (int?)minimumApi
                : null,
            targetApiIsKnown ? (bool?)targetApiIsAutomatic : null,
            targetApiLevel);
    }

    private static string NormalizeAssetPath(string path)
    {
        return string.IsNullOrWhiteSpace(path)
            ? null
            : path.Replace('\\', '/');
    }
}
#endif
