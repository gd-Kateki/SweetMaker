#if UNITY_EDITOR
using System;
using System.Collections.Generic;
using System.IO;
using System.Runtime.ExceptionServices;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Profile;
using UnityEditor.Build.Reporting;
using UnityEngine;

internal sealed class FirebaseResourceSnapshot
{
    private readonly List<FileSnapshot> files;
    private readonly string backupRoot;

    internal FirebaseResourceSnapshot(IEnumerable<string> paths)
        : this(paths, null)
    {
    }

    internal FirebaseResourceSnapshot(
        IEnumerable<string> paths,
        string backupRoot)
    {
        this.backupRoot = backupRoot;
        if (!string.IsNullOrEmpty(backupRoot))
        {
            if (Directory.Exists(backupRoot) ||
                File.Exists(backupRoot))
            {
                throw new IOException(
                    "The Firebase verification backup path already exists.");
            }

            Directory.CreateDirectory(backupRoot);
        }

        files = new List<FileSnapshot>();
        int index = 0;
        foreach (string path in paths)
        {
            files.Add(
                new FileSnapshot(
                    path,
                    string.IsNullOrEmpty(backupRoot)
                        ? null
                        : Path.Combine(
                            backupRoot,
                            index.ToString("D3") + ".bin")));
            index++;
        }
    }

    internal void Restore()
    {
        foreach (FileSnapshot file in files)
        {
            file.Restore();
        }
    }

    internal bool MatchesCurrentFiles()
    {
        foreach (FileSnapshot file in files)
        {
            if (!file.MatchesCurrentFile())
                return false;
        }

        return true;
    }

    internal void DeleteBackup()
    {
        if (!string.IsNullOrEmpty(backupRoot) &&
            Directory.Exists(backupRoot))
        {
            Directory.Delete(backupRoot, true);
        }
    }

    private sealed class FileSnapshot
    {
        private readonly string path;
        private readonly bool existed;
        private readonly byte[] contents;
        private readonly string backupPath;

        internal FileSnapshot(string path, string backupPath)
        {
            this.path = path;
            existed = File.Exists(path);
            contents = existed ? File.ReadAllBytes(path) : null;
            this.backupPath = backupPath;
            if (existed && !string.IsNullOrEmpty(backupPath))
                File.WriteAllBytes(backupPath, contents);
        }

        internal void Restore()
        {
            if (existed)
            {
                string directory = Path.GetDirectoryName(path);
                if (!string.IsNullOrEmpty(directory))
                    Directory.CreateDirectory(directory);
                File.WriteAllBytes(
                    path,
                    string.IsNullOrEmpty(backupPath)
                        ? contents
                        : File.ReadAllBytes(backupPath));
            }
            else if (File.Exists(path))
            {
                File.Delete(path);
            }
        }

        internal bool MatchesCurrentFile()
        {
            if (File.Exists(path) != existed)
                return false;
            if (!existed)
                return true;

            byte[] current = File.ReadAllBytes(path);
            if (current.Length != contents.Length)
                return false;
            for (int i = 0; i < current.Length; i++)
            {
                if (current[i] != contents[i])
                    return false;
            }

            return true;
        }
    }
}

public static class FirebaseBuildCoordinator
{
    private const string StagedJsonAssetPath =
        "Assets/google-services.json";
    private const string AndroidXmlAssetPath =
        "Assets/Plugins/Android/FirebaseApp.androidlib/res/values/google-services.xml";
    private const string DesktopJsonAssetPath =
        "Assets/StreamingAssets/google-services-desktop.json";

    private static FirebaseBuildEnvironment? authorizedEnvironment;

    internal static bool IsAuthorizedReleaseBuild
    {
        get
        {
            return authorizedEnvironment.HasValue &&
                authorizedEnvironment.Value == FirebaseBuildEnvironment.Release;
        }
    }

    [MenuItem("Build/Firebase/Build Android Development")]
    private static void BuildDevelopment()
    {
        BuildAndroid(FirebaseBuildEnvironment.Development);
    }

    [MenuItem("Build/Firebase/Build Android Release")]
    private static void BuildRelease()
    {
        BuildAndroid(FirebaseBuildEnvironment.Release);
    }

    [MenuItem("Build/Firebase/Verify Production Import and Restore (No Build)")]
    public static void VerifyProductionImportAndRestoreWithoutBuild()
    {
        FirebaseEnvironmentIdentity development =
            FirebaseEnvironmentIdentities.Development;
        FirebaseEnvironmentIdentity production =
            FirebaseEnvironmentIdentities.Release;

        FirebaseConfigurationValidator.ValidateSourceFile(
            production.SourcePath,
            production.DisplayName);
        FirebaseConfigurationValidator.ValidateCurrentAssets(
            development.DisplayName);

        BuildProfile activeProfile = BuildProfile.GetActiveBuildProfile();
        string activeProfilePath = NormalizeAssetPath(
            AssetDatabase.GetAssetPath(activeProfile));
        string activeAndroidIdentifier =
            PlayerSettings.GetApplicationIdentifier(NamedBuildTarget.Android);
        RequirePreflight(
            string.Equals(
                activeProfilePath,
                DevelopmentAndroidIdentityValidator.DevelopmentProfilePath,
                StringComparison.Ordinal),
            "The active Build Profile must be Development before verification.");
        RequirePreflight(
            string.Equals(
                activeAndroidIdentifier,
                development.AndroidPackage,
                StringComparison.Ordinal),
            "The active Android application ID must be Development before verification.");
        ValidateProfilePackage(
            DevelopmentAndroidIdentityValidator.DevelopmentProfilePath,
            development);
        ValidateProfilePackage(
            DevelopmentAndroidIdentityValidator.ReleaseProfilePath,
            production);

        string projectRoot =
            Directory.GetParent(Application.dataPath).FullName;
        string stagedJsonPath =
            Path.Combine(projectRoot, StagedJsonAssetPath);
        string androidXmlPath =
            Path.Combine(projectRoot, AndroidXmlAssetPath);
        string desktopJsonPath =
            Path.Combine(projectRoot, DesktopJsonAssetPath);
        string backupRoot = Path.Combine(
            Path.GetTempPath(),
            "SweetMakerFirebaseVerification-" +
            Guid.NewGuid().ToString("N"));
        FirebaseResourceSnapshot snapshot =
            new FirebaseResourceSnapshot(
                GetSnapshotPaths(
                    stagedJsonPath,
                    androidXmlPath,
                    desktopJsonPath),
                backupRoot);
        bool productionValidated = false;
        Exception transitionFailure = null;
        Exception restorationFailure = null;

        Debug.Log(
            "FIREBASE NO-BUILD VERIFICATION PREFLIGHT | Active profile: " +
            activeProfilePath +
            " | Android application ID: " +
            activeAndroidIdentifier +
            " | Backup: " +
            backupRoot);

        try
        {
            BuildProfile productionProfile = LoadProfile(
                DevelopmentAndroidIdentityValidator.ReleaseProfilePath);
            ActivateAndValidateProfile(productionProfile, production);
            StageAndImport(production);
            FirebaseConfigurationValidator.ValidateCurrentAssets(
                production.DisplayName);
            productionValidated = true;
            Debug.Log(
                "FIREBASE PRODUCTION IMPORT VERIFIED | Complete app ID: " +
                production.FirebaseAppId);
        }
        catch (Exception exception)
        {
            transitionFailure = exception;
        }
        finally
        {
            try
            {
                RestoreBuildProfile(
                    activeProfile,
                    activeProfilePath,
                    activeAndroidIdentifier);
            }
            catch (Exception exception)
            {
                restorationFailure = exception;
            }

            try
            {
                RestoreAndVerifyDevelopment(
                    snapshot,
                    development,
                    stagedJsonPath,
                    androidXmlPath,
                    desktopJsonPath);
            }
            catch (Exception exception)
            {
                restorationFailure = restorationFailure == null
                    ? exception
                    : new AggregateException(
                        restorationFailure,
                        exception);
            }

            try
            {
                VerifyProfileAndIdentifierUnchanged(
                    activeProfilePath,
                    activeAndroidIdentifier);
            }
            catch (Exception exception)
            {
                restorationFailure = restorationFailure == null
                    ? exception
                    : new AggregateException(
                        restorationFailure,
                        exception);
            }
        }

        if (restorationFailure != null)
        {
            string transitionMessage = transitionFailure == null
                ? string.Empty
                : "\nProduction transition failure:\n" + transitionFailure;
            throw new BuildFailedException(
                "Firebase no-build verification restoration failed. Backup retained at '" +
                backupRoot +
                "'.\n" +
                restorationFailure +
                transitionMessage);
        }

        if (transitionFailure != null)
        {
            try
            {
                snapshot.DeleteBackup();
            }
            catch (Exception exception)
            {
                throw new BuildFailedException(
                    "Development resources were restored, but the temporary backup could not be removed: " +
                    exception.Message);
            }

            ExceptionDispatchInfo.Capture(transitionFailure).Throw();
        }

        snapshot.DeleteBackup();
        if (!productionValidated)
        {
            throw new BuildFailedException(
                "Production Firebase resources were not verified.");
        }

        Debug.Log(
            "FIREBASE NO-BUILD VERIFICATION PASSED | Production import and Development restoration verified. No BuildPipeline call was made.");
    }

    internal static void ValidateBuildEnvironment(bool isDevelopmentBuild)
    {
        FirebaseBuildEnvironment requestedEnvironment = isDevelopmentBuild
            ? FirebaseBuildEnvironment.Development
            : FirebaseBuildEnvironment.Release;

        if (!isDevelopmentBuild &&
            (!authorizedEnvironment.HasValue ||
             authorizedEnvironment.Value != requestedEnvironment))
        {
            throw new BuildFailedException(
                "Release Firebase builds must be started by the explicit Firebase build coordinator.");
        }

        if (authorizedEnvironment.HasValue &&
            authorizedEnvironment.Value != requestedEnvironment)
        {
            throw new BuildFailedException(
                "The active Firebase build authorization does not match the Android build options.");
        }

        FirebaseConfigurationValidator.ValidateCurrentAssets(
            requestedEnvironment == FirebaseBuildEnvironment.Development
                ? "Development"
                : "Release");
    }

    private static void BuildAndroid(FirebaseBuildEnvironment environment)
    {
        FirebaseEnvironmentIdentity identity =
            FirebaseEnvironmentIdentities.Get(environment);
        string extension = environment == FirebaseBuildEnvironment.Release
            ? "aab"
            : "apk";
        string outputPath = EditorUtility.SaveFilePanel(
            "Build Android " + identity.DisplayName,
            Directory.GetParent(Application.dataPath).FullName,
            environment == FirebaseBuildEnvironment.Release
                ? "dessertmergecafe-release"
                : "dessertmergecafe-dev",
            extension);
        if (string.IsNullOrWhiteSpace(outputPath))
            return;

        FirebaseConfigurationValidator.ValidateSourceFile(
            identity.SourcePath,
            identity.DisplayName);
        FirebaseConfigurationValidator.ValidateCurrentAssets("Development");

        string projectRoot =
            Directory.GetParent(Application.dataPath).FullName;
        string stagedJsonPath =
            Path.Combine(projectRoot, StagedJsonAssetPath);
        string androidXmlPath =
            Path.Combine(projectRoot, AndroidXmlAssetPath);
        string desktopJsonPath =
            Path.Combine(projectRoot, DesktopJsonAssetPath);
        FirebaseResourceSnapshot snapshot = new FirebaseResourceSnapshot(
            GetSnapshotPaths(
                stagedJsonPath,
                androidXmlPath,
                desktopJsonPath));
        BuildProfile previousProfile = BuildProfile.GetActiveBuildProfile();
        string previousProfilePath = NormalizeAssetPath(
            AssetDatabase.GetAssetPath(previousProfile));
        string previousAndroidIdentifier =
            PlayerSettings.GetApplicationIdentifier(NamedBuildTarget.Android);
        RequirePreflight(
            string.Equals(
                previousProfilePath,
                DevelopmentAndroidIdentityValidator.DevelopmentProfilePath,
                StringComparison.Ordinal) &&
            string.Equals(
                previousAndroidIdentifier,
                FirebaseEnvironmentIdentities.Development.AndroidPackage,
                StringComparison.Ordinal),
            "The active Build Profile and Android application ID must be Development before a Firebase build.");
        Exception buildFailure = null;
        Exception restorationFailure = null;
        BuildReport report = null;

        try
        {
            BuildProfile profile = LoadProfile(
                environment == FirebaseBuildEnvironment.Development
                    ? DevelopmentAndroidIdentityValidator.DevelopmentProfilePath
                    : DevelopmentAndroidIdentityValidator.ReleaseProfilePath);
            ActivateAndValidateProfile(profile, identity);
            StageAndImport(identity);
            FirebaseConfigurationValidator.ValidateCurrentAssets(
                identity.DisplayName);

            authorizedEnvironment = environment;
            BuildOptions options =
                environment == FirebaseBuildEnvironment.Development
                    ? BuildOptions.Development
                    : BuildOptions.None;
            report = BuildPipeline.BuildPlayer(
                new BuildPlayerWithProfileOptions
                {
                    buildProfile = profile,
                    locationPathName = outputPath,
                    options = options
                });
            if (report == null ||
                report.summary.result != BuildResult.Succeeded)
            {
                throw new BuildFailedException(
                    identity.DisplayName +
                    " Android build did not complete successfully.");
            }
        }
        catch (Exception exception)
        {
            buildFailure = exception;
        }
        finally
        {
            authorizedEnvironment = null;

            try
            {
                RestoreBuildProfile(
                    previousProfile,
                    previousProfilePath,
                    previousAndroidIdentifier);
            }
            catch (Exception exception)
            {
                restorationFailure = exception;
            }

            try
            {
                RestoreAndVerifyDevelopment(
                    snapshot,
                    FirebaseEnvironmentIdentities.Development,
                    stagedJsonPath,
                    androidXmlPath,
                    desktopJsonPath);
            }
            catch (Exception exception)
            {
                restorationFailure = restorationFailure == null
                    ? exception
                    : new AggregateException(
                        restorationFailure,
                        exception);
            }
        }

        if (restorationFailure != null)
        {
            string originalFailure = buildFailure == null
                ? string.Empty
                : "\nBuild failure:\n" + buildFailure;
            throw new BuildFailedException(
                "Firebase build rollback could not be verified:\n" +
                restorationFailure +
                originalFailure);
        }

        if (buildFailure != null)
            ExceptionDispatchInfo.Capture(buildFailure).Throw();

        Debug.Log(
            identity.DisplayName +
            " Android build completed. Firebase resources and the prior Build Profile were restored.");
    }

    private static IEnumerable<string> GetSnapshotPaths(
        string stagedJsonPath,
        string androidXmlPath,
        string desktopJsonPath,
        params string[] additionalPaths)
    {
        string[] paths =
        {
            stagedJsonPath,
            stagedJsonPath + ".meta",
            androidXmlPath,
            androidXmlPath + ".meta",
            desktopJsonPath,
            desktopJsonPath + ".meta"
        };
        var allPaths = new List<string>(paths);
        allPaths.AddRange(additionalPaths);
        return allPaths;
    }

    private static void StageAndImport(
        FirebaseEnvironmentIdentity identity)
    {
        FirebaseConfigurationValidator.ValidateSourceFile(
            identity.SourcePath,
            identity.DisplayName);
        File.Copy(
            identity.SourcePath,
            Path.Combine(
                Directory.GetParent(Application.dataPath).FullName,
                StagedJsonAssetPath),
            true);
        ImportFirebaseConfiguration();
        WaitForResourceConvergence(identity);
    }

    private static void WaitForResourceConvergence(
        FirebaseEnvironmentIdentity identity)
    {
        var timer = System.Diagnostics.Stopwatch.StartNew();
        Exception lastValidationFailure = null;
        while (timer.Elapsed < TimeSpan.FromSeconds(30))
        {
            try
            {
                FirebaseConfigurationValidator.ValidateCurrentAssets(
                    identity.DisplayName);
                return;
            }
            catch (BuildFailedException exception)
            {
                lastValidationFailure = exception;
                System.Threading.Thread.Sleep(250);
            }
        }

        throw new BuildFailedException(
            identity.DisplayName +
            " Firebase resource generation did not converge within 30 seconds. Last validation failure: " +
            (lastValidationFailure == null
                ? "No validation result was produced."
                : lastValidationFailure.Message));
    }

    private static void RestoreAndVerifyDevelopment(
        FirebaseResourceSnapshot snapshot,
        FirebaseEnvironmentIdentity development,
        string stagedJsonPath,
        string androidXmlPath,
        string desktopJsonPath)
    {
        snapshot.Restore();
        string currentAndroidIdentifier =
            PlayerSettings.GetApplicationIdentifier(NamedBuildTarget.Android);
        if (!string.Equals(
                currentAndroidIdentifier,
                development.AndroidPackage,
                StringComparison.Ordinal))
        {
            throw new BuildFailedException(
                "The Development Android Build Profile must be active before restoring generated Firebase resources.");
        }

        ImportFirebaseConfiguration();
        WaitForResourceConvergence(development);
        snapshot.Restore();
        AssetDatabase.ImportAsset(
            DesktopJsonAssetPath,
            ImportAssetOptions.ForceSynchronousImport |
            ImportAssetOptions.ForceUpdate);
        AssetDatabase.ImportAsset(
            AndroidXmlAssetPath,
            ImportAssetOptions.ForceSynchronousImport |
            ImportAssetOptions.ForceUpdate);
        AssetDatabase.Refresh(ImportAssetOptions.ForceSynchronousImport);
        if (!snapshot.MatchesCurrentFiles())
        {
            throw new BuildFailedException(
                "Firebase resources did not match their pre-switch snapshot after reimport.");
        }

        FirebaseConfigurationValidator.ValidateFilesForEnvironment(
            Application.dataPath,
            stagedJsonPath,
            androidXmlPath,
            desktopJsonPath,
            development.DisplayName);
    }

    private static void ValidateProfilePackage(
        string profileAssetPath,
        FirebaseEnvironmentIdentity identity)
    {
        string projectRoot =
            Directory.GetParent(Application.dataPath).FullName;
        string fullPath = Path.Combine(projectRoot, profileAssetPath);
        if (!File.Exists(fullPath) ||
            File.ReadAllText(fullPath).IndexOf(
                identity.AndroidPackage,
                StringComparison.Ordinal) < 0)
        {
            throw new BuildFailedException(
                identity.DisplayName +
                " Android Build Profile does not contain its expected application ID.");
        }
    }

    private static void VerifyProfileAndIdentifierUnchanged(
        string expectedProfilePath,
        string expectedAndroidIdentifier)
    {
        string currentProfilePath = NormalizeAssetPath(
            AssetDatabase.GetAssetPath(
                BuildProfile.GetActiveBuildProfile()));
        string currentAndroidIdentifier =
            PlayerSettings.GetApplicationIdentifier(NamedBuildTarget.Android);
        if (!string.Equals(
                currentProfilePath,
                expectedProfilePath,
                StringComparison.Ordinal) ||
            !string.Equals(
                currentAndroidIdentifier,
                expectedAndroidIdentifier,
                StringComparison.Ordinal))
        {
            throw new BuildFailedException(
                "The active Build Profile or Android application ID changed during Firebase resource verification.");
        }
    }

    private static void RequirePreflight(bool condition, string message)
    {
        if (!condition)
            throw new BuildFailedException(
                "Firebase no-build verification preflight failed: " +
                message);
    }

    private static void ImportFirebaseConfiguration()
    {
        AssetDatabase.ImportAsset(
            StagedJsonAssetPath,
            ImportAssetOptions.ForceSynchronousImport |
            ImportAssetOptions.ForceUpdate);
        AssetDatabase.Refresh(ImportAssetOptions.ForceSynchronousImport);
        GenerateDesktopConfiguration();
        AssetDatabase.Refresh(ImportAssetOptions.ForceSynchronousImport);
    }

    private static void GenerateDesktopConfiguration()
    {
        string stagedPath = Path.Combine(
            Directory.GetParent(Application.dataPath).FullName,
            StagedJsonAssetPath);
        string desktopPath = Path.Combine(
            Directory.GetParent(Application.dataPath).FullName,
            DesktopJsonAssetPath);
        try
        {
            File.Copy(stagedPath, desktopPath, true);
            AssetDatabase.ImportAsset(
                DesktopJsonAssetPath,
                ImportAssetOptions.ForceSynchronousImport |
                ImportAssetOptions.ForceUpdate);
        }
        catch (Exception exception) when (
            exception is IOException ||
            exception is UnauthorizedAccessException)
        {
            throw new BuildFailedException(
                "Firebase desktop JSON staging failed: " +
                exception.Message);
        }
    }

    private static BuildProfile LoadProfile(string profileAssetPath)
    {
        BuildProfile profile =
            BuildProfile.GetBuildProfileAtPath(profileAssetPath);
        if (profile == null)
        {
            throw new BuildFailedException(
                "Required Android Build Profile was not found: " +
                profileAssetPath);
        }

        return profile;
    }

    private static void ActivateAndValidateProfile(
        BuildProfile profile,
        FirebaseEnvironmentIdentity identity)
    {
        BuildProfile.SetActiveBuildProfile(profile);
        string expectedProfilePath =
            identity.Environment == FirebaseBuildEnvironment.Development
                ? DevelopmentAndroidIdentityValidator.DevelopmentProfilePath
                : DevelopmentAndroidIdentityValidator.ReleaseProfilePath;
        string activeProfilePath = NormalizeAssetPath(
            AssetDatabase.GetAssetPath(
                BuildProfile.GetActiveBuildProfile()));
        if (!string.Equals(
                activeProfilePath,
                expectedProfilePath,
                StringComparison.Ordinal))
        {
            throw new BuildFailedException(
                "The active Android Build Profile does not match the selected Firebase environment.");
        }

        string effectiveIdentifier =
            PlayerSettings.GetApplicationIdentifier(NamedBuildTarget.Android);
        if (!string.Equals(
                effectiveIdentifier,
                identity.AndroidPackage,
                StringComparison.Ordinal))
        {
            throw new BuildFailedException(
                "The active Android application ID does not match the selected Firebase environment.");
        }
    }

    private static void RestoreBuildProfile(
        BuildProfile previousProfile,
        string previousProfilePath,
        string previousAndroidIdentifier)
    {
        BuildProfile.SetActiveBuildProfile(previousProfile);
        string restoredProfilePath = NormalizeAssetPath(
            AssetDatabase.GetAssetPath(
                BuildProfile.GetActiveBuildProfile()));
        if (!string.Equals(
                restoredProfilePath,
                previousProfilePath,
                StringComparison.Ordinal))
        {
            throw new BuildFailedException(
                "The previous Android Build Profile could not be restored.");
        }

        string restoredAndroidIdentifier =
            PlayerSettings.GetApplicationIdentifier(NamedBuildTarget.Android);
        if (!string.Equals(
                restoredAndroidIdentifier,
                previousAndroidIdentifier,
                StringComparison.Ordinal))
        {
            throw new BuildFailedException(
                "The Android application identity was not restored with the previous Build Profile.");
        }
    }

    private static string NormalizeAssetPath(string path)
    {
        return string.IsNullOrWhiteSpace(path)
            ? null
            : path.Replace('\\', '/');
    }
}
#endif
