#if UNITY_EDITOR
using System;
using System.IO;
using System.Linq;
using System.Xml;
using UnityEditor;
using UnityEditor.Build;
using UnityEngine;

internal enum FirebaseBuildEnvironment
{
    Development,
    Release
}

internal sealed class FirebaseEnvironmentIdentity
{
    internal readonly FirebaseBuildEnvironment Environment;
    internal readonly string DisplayName;
    internal readonly string SourcePath;
    internal readonly string ProjectId;
    internal readonly string ProjectNumber;
    internal readonly string AndroidPackage;
    internal readonly string FirebaseAppId;

    internal FirebaseEnvironmentIdentity(
        FirebaseBuildEnvironment environment,
        string displayName,
        string sourcePath,
        string projectId,
        string projectNumber,
        string androidPackage,
        string firebaseAppId)
    {
        Environment = environment;
        DisplayName = displayName;
        SourcePath = sourcePath;
        ProjectId = projectId;
        ProjectNumber = projectNumber;
        AndroidPackage = androidPackage;
        FirebaseAppId = firebaseAppId;
    }
}

internal static class FirebaseEnvironmentIdentities
{
    internal static readonly FirebaseEnvironmentIdentity Development =
        new FirebaseEnvironmentIdentity(
            FirebaseBuildEnvironment.Development,
            "Development",
            @"D:\Projects\Goolge Jsons\Development\Development.json",
            "dessert-merge-cafe-dev",
            "887083604660",
            "com.offcutstudios.dessertmergecafe.dev",
            "1:887083604660:android:425e3ef1bf429c226e15e1");

    internal static readonly FirebaseEnvironmentIdentity Release =
        new FirebaseEnvironmentIdentity(
            FirebaseBuildEnvironment.Release,
            "Release",
            @"D:\Projects\Goolge Jsons\Release\Release.json",
            "dessert-merge-cafe-prod",
            "264102460103",
            "com.offcutstudios.dessertmergecafe",
            "1:264102460103:android:ef698d7a8231d8734bdce2");

    internal static FirebaseEnvironmentIdentity Get(
        FirebaseBuildEnvironment environment)
    {
        switch (environment)
        {
            case FirebaseBuildEnvironment.Development:
                return Development;
            case FirebaseBuildEnvironment.Release:
                return Release;
            default:
                throw new ArgumentOutOfRangeException(
                    nameof(environment),
                    environment,
                    "Unknown Firebase build environment.");
        }
    }

    internal static FirebaseEnvironmentIdentity Parse(string environmentName)
    {
        if (string.Equals(
                environmentName,
                "Development",
                StringComparison.Ordinal))
        {
            return Development;
        }

        if (string.Equals(
                environmentName,
                "Release",
                StringComparison.Ordinal))
        {
            return Release;
        }

        throw Failure("The requested Firebase environment is not supported.");
    }

    private static BuildFailedException Failure(string message)
    {
        return new BuildFailedException(
            "Firebase configuration validation failed: " + message);
    }
}

internal static class FirebaseConfigurationValidator
{
    internal static void ValidateSourceFile(
        string sourceJsonPath,
        string environmentName)
    {
        FirebaseEnvironmentIdentity identity =
            FirebaseEnvironmentIdentities.Parse(environmentName);
        RequireFile(
            sourceJsonPath,
            "The " + identity.DisplayName +
            " Firebase source JSON is missing.");
        ValidateConfiguration(
            ReadJson(sourceJsonPath),
            identity,
            identity.DisplayName + " source JSON");
    }

    internal static void ValidateCurrentAssets(string environmentName)
    {
        string assetsRoot = Application.dataPath;
        ValidateFilesForEnvironment(
            assetsRoot,
            Path.Combine(assetsRoot, "google-services.json"),
            Path.Combine(
                assetsRoot,
                "Plugins",
                "Android",
                "FirebaseApp.androidlib",
                "res",
                "values",
                "google-services.xml"),
            Path.Combine(
                assetsRoot,
                "StreamingAssets",
                "google-services-desktop.json"),
            environmentName);
    }

    internal static void ValidateFilesForEnvironment(
        string assetsRoot,
        string stagedJsonPath,
        string androidXmlPath,
        string desktopJsonPath,
        string environmentName)
    {
        FirebaseEnvironmentIdentity identity =
            FirebaseEnvironmentIdentities.Parse(environmentName);
        Require(
            Directory.Exists(assetsRoot),
            "The Unity Assets directory is missing.");

        string expectedStagedPath =
            Path.Combine(assetsRoot, "google-services.json");
        string expectedAndroidXmlPath = Path.Combine(
            assetsRoot,
            "Plugins",
            "Android",
            "FirebaseApp.androidlib",
            "res",
            "values",
            "google-services.xml");
        string expectedDesktopJsonPath = Path.Combine(
            assetsRoot,
            "StreamingAssets",
            "google-services-desktop.json");

        RequireSamePath(
            stagedJsonPath,
            expectedStagedPath,
            "The staged Firebase configuration path is unexpected.");
        RequireSamePath(
            androidXmlPath,
            expectedAndroidXmlPath,
            "The generated Android Firebase resource path is unexpected.");
        RequireSamePath(
            desktopJsonPath,
            expectedDesktopJsonPath,
            "The generated desktop Firebase configuration path is unexpected.");

        RequireUniqueJsonFiles(assetsRoot, stagedJsonPath, desktopJsonPath);
        RequireUniqueAndroidResource(assetsRoot, androidXmlPath);

        RequireFile(stagedJsonPath, "The staged Firebase JSON is missing.");
        RequireFile(
            stagedJsonPath + ".meta",
            "The staged Firebase JSON metadata is missing.");
        RequireFile(
            androidXmlPath,
            "The generated Android Firebase XML is missing.");
        RequireFile(
            desktopJsonPath,
            "The generated desktop Firebase JSON is missing.");

        FirebaseConfiguration staged = ReadJson(stagedJsonPath);
        FirebaseConfiguration desktop = ReadJson(desktopJsonPath);
        FirebaseClient stagedClient =
            ValidateConfiguration(staged, identity, "staged JSON");
        FirebaseClient desktopClient =
            ValidateConfiguration(desktop, identity, "desktop JSON");

        string stagedApiKey = GetSingleApiKey(stagedClient, "staged JSON");
        string desktopApiKey = GetSingleApiKey(desktopClient, "desktop JSON");
        Require(
            string.Equals(
                stagedApiKey,
                desktopApiKey,
                StringComparison.Ordinal),
            "The desktop Firebase configuration does not match the staged JSON.");

        ValidateAndroidXml(
            androidXmlPath,
            identity,
            stagedApiKey);
    }

    private static void RequireUniqueJsonFiles(
        string assetsRoot,
        string stagedJsonPath,
        string desktopJsonPath)
    {
        string[] candidates;
        try
        {
            candidates = Directory.GetFiles(
                assetsRoot,
                "google-services*.json",
                SearchOption.AllDirectories);
        }
        catch (IOException)
        {
            throw Failure("Firebase JSON files could not be enumerated.");
        }
        catch (UnauthorizedAccessException)
        {
            throw Failure("Firebase JSON files could not be enumerated.");
        }

        Require(
            candidates.Length == 2 &&
            ContainsPath(candidates, stagedJsonPath) &&
            ContainsPath(candidates, desktopJsonPath),
            "Firebase JSON files are missing, duplicated, or ambiguous in Assets.");
    }

    private static void RequireUniqueAndroidResource(
        string assetsRoot,
        string expectedAndroidXmlPath)
    {
        string androidPlugins = Path.Combine(
            assetsRoot,
            "Plugins",
            "Android");
        Require(
            Directory.Exists(androidPlugins),
            "The Android plugin directory is missing.");

        string[] generatedXmlFiles;
        string[] appLibraries;
        try
        {
            generatedXmlFiles = Directory.GetFiles(
                androidPlugins,
                "google-services.xml",
                SearchOption.AllDirectories);
            appLibraries = Directory.GetDirectories(
                androidPlugins,
                "FirebaseApp.androidlib",
                SearchOption.AllDirectories);
        }
        catch (IOException)
        {
            throw Failure("Firebase Android resources could not be enumerated.");
        }
        catch (UnauthorizedAccessException)
        {
            throw Failure("Firebase Android resources could not be enumerated.");
        }

        Require(
            generatedXmlFiles.Length == 1 &&
            ContainsPath(generatedXmlFiles, expectedAndroidXmlPath),
            "Android Firebase XML is missing, duplicated, or in an unexpected location.");
        Require(
            appLibraries.Length == 1 &&
            SamePath(
                appLibraries[0],
                Path.Combine(androidPlugins, "FirebaseApp.androidlib")),
            "Firebase Android app resources are missing, duplicated, or in an unexpected location.");
    }

    private static FirebaseConfiguration ReadJson(string path)
    {
        try
        {
            FirebaseConfiguration configuration =
                JsonUtility.FromJson<FirebaseConfiguration>(
                    File.ReadAllText(path));
            Require(configuration != null, "A Firebase JSON file is malformed.");
            return configuration;
        }
        catch (BuildFailedException)
        {
            throw;
        }
        catch (Exception exception) when (
            exception is ArgumentException ||
            exception is IOException ||
            exception is UnauthorizedAccessException)
        {
            throw Failure("A Firebase JSON file is malformed or unreadable.");
        }
    }

    private static FirebaseClient ValidateConfiguration(
        FirebaseConfiguration configuration,
        FirebaseEnvironmentIdentity identity,
        string sourceName)
    {
        Require(
            configuration.project_info != null &&
            string.Equals(
                configuration.project_info.project_id,
                identity.ProjectId,
                StringComparison.Ordinal) &&
            string.Equals(
                configuration.project_info.project_number,
                identity.ProjectNumber,
                StringComparison.Ordinal),
            "The " + sourceName +
            " has an unexpected Firebase project identity.");

        FirebaseClient[] clients = configuration.client;
        Require(
            clients != null,
            "The " + sourceName + " has no Firebase Android client.");

        FirebaseClient[] androidClients = clients
            .Where(client =>
                client != null &&
                client.client_info != null &&
                client.client_info.android_client_info != null)
            .ToArray();
        Require(
            androidClients.Length == 1,
            "The " + sourceName +
            " must contain exactly one Android client.");

        FirebaseClient selectedClient = androidClients[0];
        Require(
            string.Equals(
                selectedClient.client_info.android_client_info.package_name,
                identity.AndroidPackage,
                StringComparison.Ordinal) &&
            string.Equals(
                selectedClient.client_info.mobilesdk_app_id,
                identity.FirebaseAppId,
                StringComparison.Ordinal),
            "The " + sourceName +
            " does not match the " + identity.DisplayName +
            " Android application.");

        return selectedClient;
    }

    private static string GetSingleApiKey(
        FirebaseClient client,
        string sourceName)
    {
        Require(
            client.api_key != null &&
            client.api_key.Length == 1 &&
            client.api_key[0] != null &&
            !string.IsNullOrWhiteSpace(client.api_key[0].current_key),
            "The " + sourceName +
            " must contain exactly one Android API key.");
        return client.api_key[0].current_key;
    }

    private static void ValidateAndroidXml(
        string path,
        FirebaseEnvironmentIdentity identity,
        string stagedApiKey)
    {
        XmlDocument document = new XmlDocument
        {
            XmlResolver = null
        };
        try
        {
            document.Load(path);
        }
        catch (Exception exception) when (
            exception is XmlException ||
            exception is IOException ||
            exception is UnauthorizedAccessException)
        {
            throw Failure(
                "The generated Android Firebase XML is malformed or unreadable.");
        }

        RequireXmlValue(document, "project_id", identity.ProjectId);
        RequireXmlValue(document, "gcm_defaultSenderId", identity.ProjectNumber);
        RequireXmlValue(document, "google_app_id", identity.FirebaseAppId);
        RequireXmlValue(document, "google_api_key", stagedApiKey);
        RequireXmlValue(
            document,
            "google_crash_reporting_api_key",
            stagedApiKey);
    }

    private static void RequireXmlValue(
        XmlDocument document,
        string name,
        string expectedValue)
    {
        XmlNodeList nodes = document.SelectNodes(
            "/resources/string[@name='" + name + "']");
        Require(
            nodes != null &&
            nodes.Count == 1 &&
            string.Equals(
                nodes[0].InnerText,
                expectedValue,
                StringComparison.Ordinal),
            "The generated Android Firebase XML has a missing or mismatched " +
            name +
            " value.");
    }

    private static bool ContainsPath(string[] paths, string expectedPath)
    {
        return paths.Any(path => SamePath(path, expectedPath));
    }

    private static void RequireSamePath(
        string actualPath,
        string expectedPath,
        string message)
    {
        Require(SamePath(actualPath, expectedPath), message);
    }

    private static bool SamePath(string first, string second)
    {
        if (string.IsNullOrWhiteSpace(first) ||
            string.IsNullOrWhiteSpace(second))
        {
            return false;
        }

        return string.Equals(
            Path.GetFullPath(first),
            Path.GetFullPath(second),
            StringComparison.OrdinalIgnoreCase);
    }

    private static void RequireFile(string path, string message)
    {
        Require(File.Exists(path), message);
    }

    private static void Require(bool condition, string message)
    {
        if (!condition)
            throw Failure(message);
    }

    private static BuildFailedException Failure(string message)
    {
        return new BuildFailedException(
            "Firebase configuration validation failed: " + message);
    }

    [Serializable]
    private sealed class FirebaseConfiguration
    {
        public FirebaseProjectInfo project_info;
        public FirebaseClient[] client;
    }

    [Serializable]
    private sealed class FirebaseProjectInfo
    {
        public string project_id;
        public string project_number;
    }

    [Serializable]
    private sealed class FirebaseClient
    {
        public FirebaseClientInfo client_info;
        public FirebaseApiKey[] api_key;
    }

    [Serializable]
    private sealed class FirebaseClientInfo
    {
        public string mobilesdk_app_id;
        public FirebaseAndroidClientInfo android_client_info;
    }

    [Serializable]
    private sealed class FirebaseAndroidClientInfo
    {
        public string package_name;
    }

    [Serializable]
    private sealed class FirebaseApiKey
    {
        public string current_key;
    }
}

internal static class DevelopmentFirebaseConfigurationValidator
{
    internal const string ProjectId = "dessert-merge-cafe-dev";
    internal const string ProjectNumber = "887083604660";
    internal const string AndroidPackage =
        "com.offcutstudios.dessertmergecafe.dev";
    internal const string FirebaseAppId =
        "1:887083604660:android:425e3ef1bf429c226e15e1";

    internal static void ValidateCurrentAssets()
    {
        FirebaseConfigurationValidator.ValidateCurrentAssets("Development");
    }

    internal static void EnsureDevelopmentBuildOnly(bool isDevelopmentBuild)
    {
        if (!isDevelopmentBuild &&
            !FirebaseBuildCoordinator.IsAuthorizedReleaseBuild)
        {
            throw new BuildFailedException(
                "Production Firebase configuration not yet authorized; Release builds require the explicit Firebase build coordinator.");
        }
    }

    internal static void ValidateFiles(
        string assetsRoot,
        string stagedJsonPath,
        string androidXmlPath,
        string desktopJsonPath)
    {
        FirebaseConfigurationValidator.ValidateFilesForEnvironment(
            assetsRoot,
            stagedJsonPath,
            androidXmlPath,
            desktopJsonPath,
            "Development");
    }
}
#endif
