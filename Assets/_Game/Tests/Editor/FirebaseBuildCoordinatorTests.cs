using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using NUnit.Framework;

public sealed class FirebaseBuildCoordinatorTests
{
    private const string DevelopmentProjectId = "dessert-merge-cafe-dev";
    private const string DevelopmentProjectNumber = "887083604660";
    private const string DevelopmentPackage =
        "com.offcutstudios.dessertmergecafe.dev";
    private const string DevelopmentAppId =
        "1:887083604660:android:425e3ef1bf429c226e15e1";
    private const string ReleaseProjectId = "dessert-merge-cafe-prod";
    private const string ReleaseProjectNumber = "264102460103";
    private const string ReleasePackage =
        "com.offcutstudios.dessertmergecafe";
    private const string ReleaseAppId =
        "1:264102460103:android:ef698d7a8231d8734bdce2";
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
            "SweetMakerFirebaseCoordinatorTests",
            Guid.NewGuid().ToString("N"));
        assetsRoot = Path.Combine(tempRoot, "Assets");
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
        Directory.CreateDirectory(
            Path.GetDirectoryName(androidXmlPath));
        Directory.CreateDirectory(
            Path.GetDirectoryName(desktopPath));
        WriteFixture("Development");
        File.WriteAllText(
            stagedPath + ".meta",
            "guid: 0123456789abcdef0123456789abcdef");
    }

    [TearDown]
    public void TearDown()
    {
        if (Directory.Exists(tempRoot))
            Directory.Delete(tempRoot, true);
    }

    [Test]
    public void DevelopmentSourceIdentityPasses()
    {
        string source = Path.Combine(tempRoot, "Development.json");
        File.WriteAllText(
            source,
            CreateConfiguration(
                DevelopmentProjectId,
                DevelopmentProjectNumber,
                DevelopmentPackage,
                DevelopmentAppId));

        InvokeValidator(
            "ValidateSourceFile",
            new[] { typeof(string), typeof(string) },
            new object[] { source, "Development" });
    }

    [Test]
    public void ProductionSourceUsesTheCompleteAppId()
    {
        string source = Path.Combine(tempRoot, "Release.json");
        File.WriteAllText(
            source,
            CreateConfiguration(
                ReleaseProjectId,
                ReleaseProjectNumber,
                ReleasePackage,
                ReleaseAppId));

        InvokeValidator(
            "ValidateSourceFile",
            new[] { typeof(string), typeof(string) },
            new object[] { source, "Release" });
    }

    [Test]
    public void ProductionStagedAndGeneratedResourcesPass()
    {
        WriteFixture("Release");

        InvokeValidator(
            "ValidateFilesForEnvironment",
            new[]
            {
                typeof(string),
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
                desktopPath,
                "Release"
            });
    }

    [TestCase("dessert-merge-cafe-wrong", "887083604660", DevelopmentPackage, DevelopmentAppId, "unexpected Firebase project identity")]
    [TestCase(DevelopmentProjectId, "123", DevelopmentPackage, DevelopmentAppId, "unexpected Firebase project identity")]
    [TestCase(DevelopmentProjectId, DevelopmentProjectNumber, "wrong.package", DevelopmentAppId, "does not match the Development Android application")]
    [TestCase(DevelopmentProjectId, DevelopmentProjectNumber, DevelopmentPackage, "1:887083604660:android:wrong", "does not match the Development Android application")]
    public void SourceIdentityMismatchIsRejected(
        string projectId,
        string projectNumber,
        string packageName,
        string appId,
        string expectedMessage)
    {
        string source = Path.Combine(tempRoot, "mismatch.json");
        File.WriteAllText(
            source,
            CreateConfiguration(
                projectId,
                projectNumber,
                packageName,
                appId));

        AssertInvocationFails(
            "ValidateSourceFile",
            new[] { typeof(string), typeof(string) },
            new object[] { source, "Development" },
            expectedMessage);
    }

    [Test]
    public void MissingSourceFileIsRejected()
    {
        AssertInvocationFails(
            "ValidateSourceFile",
            new[] { typeof(string), typeof(string) },
            new object[]
            {
                Path.Combine(tempRoot, "missing.json"),
                "Development"
            },
            "source JSON is missing");
    }

    [Test]
    public void MalformedSourceFileIsRejected()
    {
        string source = Path.Combine(tempRoot, "malformed.json");
        File.WriteAllText(source, "{not-json");

        AssertInvocationFails(
            "ValidateSourceFile",
            new[] { typeof(string), typeof(string) },
            new object[] { source, "Development" },
            "malformed");
    }

    [Test]
    public void DuplicateAndroidClientsAreRejected()
    {
        string source = Path.Combine(tempRoot, "duplicate.json");
        string client = ClientJson(
            DevelopmentPackage,
            DevelopmentAppId);
        File.WriteAllText(
            source,
            "{\"project_info\":{\"project_id\":\"" +
            DevelopmentProjectId +
            "\",\"project_number\":\"" +
            DevelopmentProjectNumber +
            "\"},\"client\":[" +
            client +
            "," +
            client +
            "]}");

        AssertInvocationFails(
            "ValidateSourceFile",
            new[] { typeof(string), typeof(string) },
            new object[] { source, "Development" },
            "exactly one Android client");
    }

    [Test]
    public void AndroidClientWithoutPackageIsStillCountedAsDuplicate()
    {
        string source = Path.Combine(tempRoot, "duplicate-without-package.json");
        string validClient = ClientJson(
            DevelopmentPackage,
            DevelopmentAppId);
        string clientWithoutPackage = ClientJson(
            string.Empty,
            DevelopmentAppId + ":other");
        File.WriteAllText(
            source,
            "{\"project_info\":{\"project_id\":\"" +
            DevelopmentProjectId +
            "\",\"project_number\":\"" +
            DevelopmentProjectNumber +
            "\"},\"client\":[" +
            validClient +
            "," +
            clientWithoutPackage +
            "]}");

        AssertInvocationFails(
            "ValidateSourceFile",
            new[] { typeof(string), typeof(string) },
            new object[] { source, "Development" },
            "exactly one Android client");
    }

    [Test]
    public void MismatchedGeneratedAndroidResourceIsRejected()
    {
        WriteFixture("Development");
        File.WriteAllText(
            androidXmlPath,
            CreateAndroidXml(DevelopmentAppId + ":wrong"));

        AssertFilesFail("google_app_id");
    }

    [Test]
    public void MismatchedGeneratedDesktopResourceIsRejected()
    {
        WriteFixture("Development");
        File.WriteAllText(
            desktopPath,
            CreateConfiguration(
                ReleaseProjectId,
                ReleaseProjectNumber,
                ReleasePackage,
                ReleaseAppId));

        AssertFilesFail("desktop JSON");
    }

    [Test]
    public void MissingGeneratedDesktopResourceIsRejected()
    {
        File.Delete(desktopPath);

        AssertFilesFail("missing, duplicated, or ambiguous");
    }

    [Test]
    public void MalformedGeneratedAndroidResourceIsRejected()
    {
        File.WriteAllText(androidXmlPath, "<resources>");

        AssertFilesFail("malformed or unreadable");
    }

    [Test]
    public void FirebaseResourceSnapshotRestoresPriorFiles()
    {
        string existing = Path.Combine(tempRoot, "prior.json");
        string previouslyMissing = Path.Combine(tempRoot, "generated.xml");
        File.WriteAllText(existing, "prior");
        Type snapshotType = FindType("FirebaseResourceSnapshot");
        ConstructorInfo constructor = snapshotType.GetConstructor(
            BindingFlags.Instance | BindingFlags.NonPublic,
            null,
            new[] { typeof(IEnumerable<string>) },
            null);
        Assert.IsNotNull(constructor);
        object snapshot = constructor.Invoke(
            new object[] { new[] { existing, previouslyMissing } });

        File.WriteAllText(existing, "changed");
        File.WriteAllText(previouslyMissing, "new");
        snapshotType.GetMethod(
            "Restore",
            BindingFlags.Instance | BindingFlags.NonPublic)
            .Invoke(snapshot, null);

        Assert.AreEqual("prior", File.ReadAllText(existing));
        Assert.IsFalse(File.Exists(previouslyMissing));
        Assert.IsTrue(
            (bool)snapshotType.GetMethod(
                    "MatchesCurrentFiles",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(snapshot, null));
    }

    private void WriteFixture(string environment)
    {
        bool isRelease = string.Equals(
            environment,
            "Release",
            StringComparison.Ordinal);
        string projectId = isRelease
            ? ReleaseProjectId
            : DevelopmentProjectId;
        string projectNumber = isRelease
            ? ReleaseProjectNumber
            : DevelopmentProjectNumber;
        string packageName = isRelease
            ? ReleasePackage
            : DevelopmentPackage;
        string appId = isRelease ? ReleaseAppId : DevelopmentAppId;

        File.WriteAllText(
            stagedPath,
            CreateConfiguration(
                projectId,
                projectNumber,
                packageName,
                appId));
        File.WriteAllText(androidXmlPath, CreateAndroidXml(appId, projectId, projectNumber));
        File.WriteAllText(
            desktopPath,
            CreateConfiguration(
                projectId,
                projectNumber,
                packageName,
                appId));
    }

    private void AssertFilesFail(string expectedMessage)
    {
        AssertInvocationFails(
            "ValidateFilesForEnvironment",
            new[]
            {
                typeof(string),
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
                desktopPath,
                "Development"
            },
            expectedMessage);
    }

    private static void InvokeValidator(
        string methodName,
        Type[] parameterTypes,
        object[] arguments)
    {
        Exception exception = Invoke(
            "FirebaseConfigurationValidator",
            methodName,
            parameterTypes,
            arguments);
        if (exception != null)
            throw exception;
    }

    private static void AssertInvocationFails(
        string methodName,
        Type[] parameterTypes,
        object[] arguments,
        string expectedMessage)
    {
        Exception exception = Invoke(
            "FirebaseConfigurationValidator",
            methodName,
            parameterTypes,
            arguments);
        Assert.IsNotNull(exception);
        StringAssert.Contains(expectedMessage, exception.Message);
    }

    private static Exception Invoke(
        string typeName,
        string methodName,
        Type[] parameterTypes,
        object[] arguments)
    {
        Type type = FindType(typeName);
        MethodInfo method = type.GetMethod(
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

    private static Type FindType(string typeName)
    {
        return AppDomain.CurrentDomain
            .GetAssemblies()
            .Select(assembly => assembly.GetType(typeName))
            .First(type => type != null);
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
            "\"},\"client\":[" +
            ClientJson(packageName, appId) +
            "]}";
    }

    private static string ClientJson(string packageName, string appId)
    {
        return
            "{\"client_info\":{\"mobilesdk_app_id\":\"" + appId +
            "\",\"android_client_info\":{\"package_name\":\"" +
            packageName +
            "\"}},\"api_key\":[{\"current_key\":\"" + ApiKey + "\"}]}";
    }

    private static string CreateAndroidXml(
        string appId,
        string projectId = DevelopmentProjectId,
        string projectNumber = DevelopmentProjectNumber)
    {
        return
            "<resources>" +
            "<string name=\"project_id\">" + projectId + "</string>" +
            "<string name=\"gcm_defaultSenderId\">" + projectNumber +
            "</string>" +
            "<string name=\"google_app_id\">" + appId + "</string>" +
            "<string name=\"google_api_key\">" + ApiKey + "</string>" +
            "<string name=\"google_crash_reporting_api_key\">" + ApiKey +
            "</string></resources>";
    }
}
