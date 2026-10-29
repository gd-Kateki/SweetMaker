using System;
using System.IO;
using System.Linq;
using System.Reflection;
using NUnit.Framework;

public sealed class DevelopmentFirebaseConfigurationValidatorTests
{
    private const string ProjectId = "dessert-merge-cafe-dev";
    private const string ProjectNumber = "887083604660";
    private const string PackageName =
        "com.offcutstudios.dessertmergecafe.dev";
    private const string AppId =
        "1:887083604660:android:425e3ef1bf429c226e15e1";
    private const string ApiKey = "test-api-key-not-a-secret";

    private string tempRoot;
    private string assetsRoot;
    private string stagedPath;
    private string androidXmlPath;
    private string desktopPath;

    [SetUp]
    public void SetUp()
    {
        tempRoot = Path.Combine(
            Path.GetTempPath(),
            "SweetMakerFirebaseConfigTests",
            Guid.NewGuid().ToString("N"));
        assetsRoot = Path.Combine(tempRoot, "Assets");
        Directory.CreateDirectory(assetsRoot);

        stagedPath = Path.Combine(assetsRoot, "google-services.json");
        androidXmlPath = Path.Combine(
            assetsRoot,
            "Plugins",
            "Android",
            "FirebaseApp.androidlib",
            "res",
            "values",
            "google-services.xml");
        desktopPath = Path.Combine(
            assetsRoot,
            "StreamingAssets",
            "google-services-desktop.json");

        Directory.CreateDirectory(Path.GetDirectoryName(androidXmlPath));
        Directory.CreateDirectory(Path.GetDirectoryName(desktopPath));
        WriteStagedConfiguration();
        File.WriteAllText(stagedPath + ".meta", "guid: 0123456789abcdef0123456789abcdef");
        File.WriteAllText(androidXmlPath, CreateAndroidXml(AppId));
        File.WriteAllText(desktopPath, CreateConfiguration(ProjectId, ProjectNumber, PackageName, AppId));
    }

    [TearDown]
    public void TearDown()
    {
        if (Directory.Exists(tempRoot))
            Directory.Delete(tempRoot, true);
    }

    [Test]
    public void MatchingDevelopmentConfigurationPasses()
    {
        InvokeValidator();
    }

    [Test]
    public void MissingStagedMetadataIsRejected()
    {
        File.Delete(stagedPath + ".meta");

        AssertValidationFails("metadata is missing");
    }

    [Test]
    public void DuplicateFirebaseJsonIsRejected()
    {
        File.WriteAllText(
            Path.Combine(assetsRoot, "google-services-copy.json"),
            File.ReadAllText(stagedPath));

        AssertValidationFails("duplicated, or ambiguous");
    }

    [Test]
    public void MismatchedGeneratedAndroidAppIdIsRejected()
    {
        File.WriteAllText(
            androidXmlPath,
            CreateAndroidXml("1:887083604660:android:wrong"));

        AssertValidationFails("google_app_id");
    }

    [Test]
    public void MismatchedDesktopFirebaseIdentityIsRejected()
    {
        File.WriteAllText(
            desktopPath,
            CreateConfiguration(
                "dessert-merge-cafe-prod",
                ProjectNumber,
                PackageName,
                AppId));

        AssertValidationFails("desktop JSON");
    }

    [Test]
    public void ReleaseBuildIsRejectedUntilProductionIsAuthorized()
    {
        Exception exception = InvokeValidatorMethod(
            "EnsureDevelopmentBuildOnly",
            new[] { typeof(bool) },
            new object[] { false });

        StringAssert.Contains(
            "Production Firebase configuration not yet authorized",
            exception.Message);
    }

    private void WriteStagedConfiguration()
    {
        File.WriteAllText(
            stagedPath,
            CreateConfiguration(ProjectId, ProjectNumber, PackageName, AppId));
    }

    private void InvokeValidator()
    {
        Exception exception = InvokeValidatorMethod(
            "ValidateFiles",
            new[]
            {
                typeof(string),
                typeof(string),
                typeof(string),
                typeof(string)
            },
            new object[]
            {
                assetsRoot,
                stagedPath,
                androidXmlPath,
                desktopPath
            });
        if (exception != null)
            throw exception;
    }

    private void AssertValidationFails(string expectedMessage)
    {
        Exception exception = InvokeValidatorMethod(
            "ValidateFiles",
            new[]
            {
                typeof(string),
                typeof(string),
                typeof(string),
                typeof(string)
            },
            new object[]
            {
                assetsRoot,
                stagedPath,
                androidXmlPath,
                desktopPath
            });

        Assert.IsNotNull(exception);
        StringAssert.Contains(expectedMessage, exception.Message);
    }

    private static Exception InvokeValidatorMethod(
        string methodName,
        Type[] parameterTypes,
        object[] arguments)
    {
        Type validatorType = AppDomain.CurrentDomain
            .GetAssemblies()
            .Select(assembly =>
                assembly.GetType(
                    "DevelopmentFirebaseConfigurationValidator"))
            .First(type => type != null);
        MethodInfo method = validatorType.GetMethod(
            methodName,
            BindingFlags.Static | BindingFlags.NonPublic,
            null,
            parameterTypes,
            null);
        Assert.IsNotNull(method);

        try
        {
            method.Invoke(null, arguments);
            return null;
        }
        catch (TargetInvocationException exception)
        {
            return exception.InnerException ?? exception;
        }
    }

    private static string CreateConfiguration(
        string projectId,
        string projectNumber,
        string packageName,
        string appId)
    {
        return
            "{\"project_info\":{\"project_id\":\"" + projectId +
            "\",\"project_number\":\"" + projectNumber +
            "\"},\"client\":[{\"client_info\":{\"mobilesdk_app_id\":\"" +
            appId +
            "\",\"android_client_info\":{\"package_name\":\"" +
            packageName +
            "\"}},\"api_key\":[{\"current_key\":\"" + ApiKey +
            "\"}]}]}";
    }

    private static string CreateAndroidXml(string appId)
    {
        return
            "<resources>" +
            "<string name=\"project_id\">" + ProjectId + "</string>" +
            "<string name=\"gcm_defaultSenderId\">" + ProjectNumber +
            "</string>" +
            "<string name=\"google_app_id\">" + appId + "</string>" +
            "<string name=\"google_api_key\">" + ApiKey + "</string>" +
            "<string name=\"google_crash_reporting_api_key\">" + ApiKey +
            "</string></resources>";
    }
}
