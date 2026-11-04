#if UNITY_EDITOR
using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.ExceptionServices;
using System.Security.Cryptography;
using System.Text.RegularExpressions;
using UnityEditor;
using UnityEditor.Android;
using UnityEditor.Build;
using UnityEditor.Build.Profile;
using UnityEditor.Build.Reporting;
using UnityEngine;
using Debug = UnityEngine.Debug;

public static class AndroidIdentityBuildVerification
{
    private const string BundletoolSha256 =
        "a099cfa1543f55593bc2ed16a70a7c67fe54b1747bb7301f37fdfd6d91028e29";
    private const string BundletoolVersion = "1.18.3";

    public static void BuildAndVerify()
    {
        Exception verificationFailure = null;
        try
        {
            RunVerification();
        }
        catch (Exception exception)
        {
            verificationFailure = exception;
        }
        finally
        {
            try
            {
                ActivateAndVerifyProfile(
                    DevelopmentAndroidIdentityValidator.DevelopmentProfilePath,
                    DevelopmentAndroidIdentityValidator.DevelopmentIdentifier);
            }
            catch (Exception restorationException)
            {
                if (verificationFailure != null)
                {
                    throw new BuildFailedException(
                        "Android identity verification failed:\n" +
                        verificationFailure +
                        "\nDEV profile restoration also failed:\n" +
                        restorationException);
                }

                throw new BuildFailedException(
                    "DEV profile restoration failed:\n" +
                    restorationException);
            }
        }

        if (verificationFailure != null)
            ExceptionDispatchInfo.Capture(verificationFailure).Throw();
    }

    private static void RunVerification()
    {
        string[] developmentScenes = GetProfileScenes(
            DevelopmentAndroidIdentityValidator.DevelopmentProfilePath);
        string[] releaseScenes = GetProfileScenes(
            DevelopmentAndroidIdentityValidator.ReleaseProfilePath);
        ValidateProfileScenes(
            DevelopmentAndroidIdentityValidator.DevelopmentProfilePath,
            developmentScenes,
            new[]
            {
                "Assets/_Game/Scenes/Welcome.unity",
                "Assets/_Game/Scenes/Loading.unity",
                "Assets/_Game/Scenes/MainBakery.unity",
                "Assets/_Game/Scenes/Game.unity"
            });
        ValidateProfileScenes(
            DevelopmentAndroidIdentityValidator.ReleaseProfilePath,
            releaseScenes,
            new[]
            {
                "Assets/_Game/Scenes/MainBakery.unity",
                "Assets/_Game/Scenes/Game.unity"
            });

        string aaptPath = FindAapt(
            AndroidExternalToolsSettings.sdkRootPath);
        string javaPath = FindUnityJava();
        string bundletoolPath = FindAndVerifyBundletool();
        VerifyBundletoolVersion(javaPath, bundletoolPath);

        string projectRoot =
            Directory.GetParent(Application.dataPath).FullName;
        string runDirectory = Path.Combine(
            projectRoot,
            "BuildVerification",
            "Android",
            DateTime.UtcNow.ToString("yyyyMMdd_HHmmss_fff"));
        if (Directory.Exists(runDirectory))
            throw new BuildFailedException(
                "Android verification output directory already exists: " +
                runDirectory);
        Directory.CreateDirectory(runDirectory);

        BuildAndVerifyOne(
            DevelopmentAndroidIdentityValidator.DevelopmentProfilePath,
            Path.Combine(runDirectory, "dessertmergecafe-dev.apk"),
            BuildOptions.Development,
            DevelopmentAndroidIdentityValidator.DevelopmentIdentifier,
            ArtifactKind.Apk,
            aaptPath,
            javaPath,
            bundletoolPath);
        BuildAndVerifyOne(
            DevelopmentAndroidIdentityValidator.ReleaseProfilePath,
            Path.Combine(runDirectory, "dessertmergecafe-release.aab"),
            BuildOptions.None,
            DevelopmentAndroidIdentityValidator.ReleaseIdentifier,
            ArtifactKind.AppBundle,
            aaptPath,
            javaPath,
            bundletoolPath);

        Debug.Log(
            "ANDROID IDENTITY VERIFICATION PASSED | Outputs: " +
            runDirectory);
    }

    private static BuildProfile LoadProfile(string assetPath)
    {
        BuildProfile profile;
        try
        {
            profile = BuildProfile.GetBuildProfileAtPath(assetPath);
        }
        catch (Exception exception)
        {
            Debug.LogError(
                "ANDROID PROFILE LOAD FAILED | Asset path: " +
                assetPath +
                " | " +
                exception);
            throw new BuildFailedException(
                "Could not load Android Build Profile at '" +
                assetPath +
                "': " +
                exception.Message);
        }

        if (profile == null)
        {
            Debug.LogError(
                "ANDROID PROFILE LOAD FAILED | Asset path: " +
                assetPath);
            throw new BuildFailedException(
                "Required Android Build Profile was not found: " +
                assetPath);
        }

        return profile;
    }

    private static string[] GetProfileScenes(string profilePath)
    {
        BuildProfile profile = LoadProfile(profilePath);
        var scenes = profile.GetScenesForBuild();
        if (scenes == null)
            throw new BuildFailedException(
                "Could not read build scenes from profile '" +
                AssetDatabase.GetAssetPath(profile) +
                "'.");

        string[] enabledScenes = scenes
            .Where(scene => scene != null && scene.enabled)
            .Select(scene => scene.path)
            .ToArray();
        if (enabledScenes.Length == 0)
            throw new BuildFailedException(
                "Build Profile has no enabled scenes: " +
                AssetDatabase.GetAssetPath(profile));

        return enabledScenes;
    }

    private static void ValidateProfileScenes(
        string profilePath,
        string[] actualScenes,
        string[] expectedScenes)
    {
        if (!actualScenes.SequenceEqual(
                expectedScenes,
                StringComparer.Ordinal))
        {
            throw new BuildFailedException(
                "Android Build Profile '" +
                profilePath +
                "' must contain exactly these enabled scenes, in order: " +
                string.Join(", ", expectedScenes) +
                ".");
        }
    }

    private static void BuildAndVerifyOne(
        string profileAssetPath,
        string outputPath,
        BuildOptions options,
        string expectedIdentifier,
        ArtifactKind artifactKind,
        string aaptPath,
        string javaPath,
        string bundletoolPath)
    {
        BuildProfile profile = LoadProfile(profileAssetPath);
        ActivateAndVerifyProfile(profileAssetPath, expectedIdentifier, profile);

        string profilePath = NormalizeAssetPath(
            profileAssetPath);
        var buildOptions = new BuildPlayerWithProfileOptions
        {
            buildProfile = profile,
            locationPathName = outputPath,
            options = options
        };
        BuildReport report = BuildPipeline.BuildPlayer(buildOptions);
        if (report == null ||
            report.summary.result != BuildResult.Succeeded)
        {
            throw new BuildFailedException(
                "Android build did not succeed for profile '" +
                profilePath +
                "'.");
        }

        BuildReportSummary buildSummary;
        if (!BuildHistory.TryGetBuildSummaryForOutputPath(
                report.summary.outputPath,
                out buildSummary))
        {
            throw new BuildFailedException(
                "Build history did not contain profile information for '" +
                profilePath +
                "'.");
        }

        string reportProfilePath = NormalizeAssetPath(
            buildSummary.BuildProfilePath);
        if (!string.Equals(
                reportProfilePath,
                profilePath,
                StringComparison.Ordinal))
        {
            throw new BuildFailedException(
                "Build report profile mismatch. Expected '" +
                profilePath +
                "' but found '" +
                (reportProfilePath ?? "<none>") +
                "'.");
        }

        bool reportIsDevelopment =
            (report.summary.options & BuildOptions.Development) != 0;
        bool expectedDevelopment =
            (options & BuildOptions.Development) != 0;
        if (reportIsDevelopment != expectedDevelopment)
        {
            throw new BuildFailedException(
                "Build report Development option did not match profile build mode for '" +
                profilePath +
                "'.");
        }

        string effectiveIdentifier =
            PlayerSettings.GetApplicationIdentifier(
                NamedBuildTarget.Android);
        if (!string.Equals(
                effectiveIdentifier,
                expectedIdentifier,
                StringComparison.Ordinal))
        {
            throw new BuildFailedException(
                "Effective Android application ID changed during build. Expected '" +
                expectedIdentifier +
                "' but found '" +
                (effectiveIdentifier ?? "<null>") +
                "'.");
        }

        if (artifactKind == ArtifactKind.Apk)
        {
            VerifyApkIdentifier(
                outputPath,
                expectedIdentifier,
                aaptPath);
        }
        else
        {
            VerifyAppBundleIdentifier(
                outputPath,
                expectedIdentifier,
                javaPath,
                bundletoolPath);
        }

        Debug.Log(
            "ANDROID ARTIFACT ID VERIFIED | " +
            Path.GetFileName(outputPath) +
            " | " +
            expectedIdentifier +
            " | Profile: " +
            profilePath);
    }

    private static void ActivateAndVerifyProfile(
        string profileAssetPath,
        string expectedIdentifier,
        BuildProfile loadedProfile = null)
    {
        BuildProfile profile = loadedProfile ?? LoadProfile(profileAssetPath);
        string expectedProfilePath = NormalizeAssetPath(
            AssetDatabase.GetAssetPath(profile));

        try
        {
            BuildProfile.SetActiveBuildProfile(profile);
        }
        catch (Exception exception)
        {
            Debug.LogError(
                "ANDROID PROFILE ACTIVATION FAILED | Asset path: " +
                expectedProfilePath +
                " | SetActiveBuildProfile threw: " +
                exception);
            throw new BuildFailedException(
                "Could not activate Android Build Profile '" +
                expectedProfilePath +
                "': " +
                exception.Message);
        }

        string activeProfilePath = NormalizeAssetPath(
            AssetDatabase.GetAssetPath(
                BuildProfile.GetActiveBuildProfile()));
        if (!string.Equals(
                activeProfilePath,
                expectedProfilePath,
                StringComparison.Ordinal))
        {
            Debug.LogError(
                "ANDROID PROFILE ACTIVATION VALIDATION FAILED | Expected: " +
                expectedProfilePath +
                " | Active: " +
                (activeProfilePath ?? "<none>"));
            throw new BuildFailedException(
                "Active Android Build Profile mismatch. Expected '" +
                expectedProfilePath +
                "' but found '" +
                (activeProfilePath ?? "<none>") +
                "'.");
        }

        string effectiveIdentifier =
            PlayerSettings.GetApplicationIdentifier(
                NamedBuildTarget.Android);
        if (!string.Equals(
                effectiveIdentifier,
                expectedIdentifier,
                StringComparison.Ordinal))
        {
            Debug.LogError(
                "ANDROID PROFILE ID VALIDATION FAILED | Profile: " +
                expectedProfilePath +
                " | Expected ID: " +
                expectedIdentifier +
                " | Effective ID: " +
                (effectiveIdentifier ?? "<null>"));
            throw new BuildFailedException(
                "Effective Android application ID mismatch for profile '" +
                expectedProfilePath +
                "'. Expected '" +
                expectedIdentifier +
                "' but found '" +
                (effectiveIdentifier ?? "<null>") +
                "'.");
        }
    }

    private static string FindAapt(string sdkRoot)
    {
        if (string.IsNullOrWhiteSpace(sdkRoot))
            throw new BuildFailedException(
                "Unity's configured Android SDK path is empty.");

        string buildToolsPath = Path.Combine(sdkRoot, "build-tools");
        if (!Directory.Exists(buildToolsPath))
            throw new BuildFailedException(
                "Android SDK build-tools were not found in Unity's configured SDK.");

        var candidates = Directory.GetDirectories(buildToolsPath)
            .Select(path => new
            {
                Path = Path.Combine(path, "aapt.exe"),
                Version = ParseBuildToolsVersion(path)
            })
            .Where(candidate => File.Exists(candidate.Path))
            .OrderByDescending(candidate => candidate.Version)
            .ToArray();
        if (candidates.Length == 0)
            throw new BuildFailedException(
                "No aapt.exe was found in Unity's configured Android SDK build-tools.");

        return candidates[0].Path;
    }

    private static Version ParseBuildToolsVersion(string path)
    {
        Version version;
        return Version.TryParse(
            Path.GetFileName(path),
            out version)
            ? version
            : new Version(0, 0);
    }

    private static string FindUnityJava()
    {
        string javaPath = Path.Combine(
            EditorApplication.applicationContentsPath,
            "PlaybackEngines",
            "AndroidPlayer",
            "OpenJDK",
            "bin",
            "java.exe");
        if (!File.Exists(javaPath))
            throw new BuildFailedException(
                "Unity-bundled Java was not found at: " + javaPath);

        return javaPath;
    }

    private static string FindAndVerifyBundletool()
    {
        string bundletoolPath = Path.Combine(
            Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData),
            "Android",
            "bundletool",
            "bundletool-all-1.18.3.jar");
        if (!File.Exists(bundletoolPath))
            throw new BuildFailedException(
                "Google bundletool 1.18.3 was not found at: " +
                bundletoolPath);

        string actualHash;
        using (SHA256 sha256 = SHA256.Create())
        using (FileStream stream = File.OpenRead(bundletoolPath))
        {
            actualHash = BitConverter.ToString(
                sha256.ComputeHash(stream))
                .Replace("-", string.Empty)
                .ToLowerInvariant();
        }

        if (!string.Equals(
                actualHash,
                BundletoolSha256,
                StringComparison.Ordinal))
        {
            throw new BuildFailedException(
                "Bundletool SHA-256 mismatch; refusing to inspect AABs.");
        }

        return bundletoolPath;
    }

    private static void VerifyBundletoolVersion(
        string javaPath,
        string bundletoolPath)
    {
        string output = RunProcess(
            javaPath,
            "-jar " +
            QuoteArgument(bundletoolPath) +
            " version",
            "bundletool version");
        if (!string.Equals(
                output.Trim(),
                BundletoolVersion,
                StringComparison.Ordinal))
        {
            throw new BuildFailedException(
                "Unexpected bundletool version output: '" +
                output.Trim() +
                "'.");
        }
    }

    private static void VerifyApkIdentifier(
        string apkPath,
        string expectedIdentifier,
        string aaptPath)
    {
        if (!File.Exists(apkPath))
            throw new BuildFailedException(
                "Android build succeeded but the expected APK is missing.");

        string output = RunProcess(
            aaptPath,
            "dump badging " + QuoteArgument(apkPath),
            "aapt APK inspection");
        Match match = Regex.Match(
            output,
            @"^package:\s+name='([^']+)'",
            RegexOptions.Multiline);
        string actualIdentifier = match.Success
            ? match.Groups[1].Value
            : null;
        VerifyInspectedIdentifier(
            actualIdentifier,
            expectedIdentifier,
            "APK");
    }

    private static void VerifyAppBundleIdentifier(
        string appBundlePath,
        string expectedIdentifier,
        string javaPath,
        string bundletoolPath)
    {
        if (!File.Exists(appBundlePath))
            throw new BuildFailedException(
                "Android build succeeded but the expected AAB is missing.");

        string output = RunProcess(
            javaPath,
            "-jar " +
            QuoteArgument(bundletoolPath) +
            " dump manifest --bundle=" +
            QuoteArgument(appBundlePath) +
            " --xpath=/manifest/@package",
            "bundletool AAB manifest inspection");
        VerifyInspectedIdentifier(
            output.Trim(),
            expectedIdentifier,
            "AAB");
    }

    private static void VerifyInspectedIdentifier(
        string actualIdentifier,
        string expectedIdentifier,
        string artifactType)
    {
        if (!string.Equals(
                actualIdentifier,
                expectedIdentifier,
                StringComparison.Ordinal))
        {
            throw new BuildFailedException(
                artifactType +
                " application ID mismatch. Expected '" +
                expectedIdentifier +
                "' but found '" +
                (actualIdentifier ?? "<unavailable>") +
                "'.");
        }
    }

    private static string RunProcess(
        string executablePath,
        string arguments,
        string operation)
    {
        var startInfo = new ProcessStartInfo
        {
            FileName = executablePath,
            Arguments = arguments,
            UseShellExecute = false,
            CreateNoWindow = true,
            RedirectStandardOutput = true,
            RedirectStandardError = true
        };
        Process startedProcess;
        try
        {
            startedProcess = Process.Start(startInfo);
        }
        catch (Exception exception)
        {
            throw new BuildFailedException(
                "Could not start " +
                operation +
                ": " +
                exception.Message);
        }

        if (startedProcess == null)
            throw new BuildFailedException(
                "Could not start " + operation + ".");

        using (Process process = startedProcess)
        {
            var standardOutput = process.StandardOutput.ReadToEndAsync();
            var standardError = process.StandardError.ReadToEndAsync();
            process.WaitForExit();
            string output = standardOutput.Result;
            string error = standardError.Result;
            if (process.ExitCode != 0)
                throw new BuildFailedException(
                    operation +
                    " failed with exit code " +
                    process.ExitCode +
                    (string.IsNullOrWhiteSpace(error)
                        ? "."
                        : ": " + error.Trim()));

            return output;
        }
    }

    private static string QuoteArgument(string value)
    {
        return "\"" + value.Replace("\"", "\\\"") + "\"";
    }

    private static string NormalizeAssetPath(string path)
    {
        return string.IsNullOrWhiteSpace(path)
            ? null
            : path.Replace('\\', '/');
    }

    private enum ArtifactKind
    {
        Apk,
        AppBundle
    }
}
#endif
