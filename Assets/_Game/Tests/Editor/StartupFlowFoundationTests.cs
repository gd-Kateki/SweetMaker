using System;
using System.IO;
using System.Reflection;
using NUnit.Framework;

public sealed class StartupFlowFoundationTests
{
    private const BindingFlags PublicInstance =
        BindingFlags.Public | BindingFlags.Instance;
    private string temporaryRoot;
    private Type storeType;
    private Type machineType;

    [SetUp]
    public void SetUp()
    {
        temporaryRoot = Path.Combine(
            Path.GetTempPath(),
            "SweetMakerStartupTests",
            Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(temporaryRoot);
        Assembly runtimeAssembly =
            Type.GetType("SavePathPolicy, Assembly-CSharp", true).Assembly;
        storeType = runtimeAssembly.GetType(
            "SweetMerge.Startup.StartupPlayModeStore",
            true);
        machineType = runtimeAssembly.GetType(
            "SweetMerge.Startup.StartupFlowMachine",
            true);
    }

    [TearDown]
    public void TearDown()
    {
        if (Directory.Exists(temporaryRoot))
            Directory.Delete(temporaryRoot, true);
    }

    [Test]
    public void RestartWithoutPrivacyChoiceStartsAtPrivacy()
    {
        object machine = CreateMachine(NewStorePath());

        Call(machine, "Initialize", false);

        AssertState(machine, "PrivacyPending");
    }

    [Test]
    public void PrivacyChoicePrecedesPreviouslySelectedGuestLoading()
    {
        string path = NewStorePath();
        object guest = CreateMachine(path);
        Call(guest, "Initialize", true);
        Call(guest, "SelectGuest");

        object returningMachine = CreateMachine(path);
        Call(returningMachine, "Initialize", false);

        AssertState(returningMachine, "PrivacyPending");
        Assert.IsTrue((bool)Call(
            returningMachine,
            "CompletePrivacyChoice"));
        AssertState(returningMachine, "LoadingRestorePending");
    }

    [Test]
    public void ConsentWithoutSelectionStartsAtPlayModeSelection()
    {
        object machine = CreateMachine(NewStorePath());

        Call(machine, "Initialize", true);

        AssertState(machine, "PlayModeSelectionPending");
    }

    [Test]
    public void GuestSelectionPersistsBeforeLoadingAndSurvivesRestart()
    {
        string path = NewStorePath();
        object machine = CreateMachine(path);
        Call(machine, "Initialize", true);

        Assert.IsTrue((bool)Call(machine, "SelectGuest"));
        AssertState(machine, "LoadingRestorePending");

        object returningMachine = CreateMachine(path);
        Call(returningMachine, "Initialize", true);

        AssertState(returningMachine, "LoadingRestorePending");
        Assert.AreEqual("Guest", GetProperty(
            returningMachine,
            "SelectedPlayMode").ToString());
    }

    [Test]
    public void GoogleSelectionIsPersistedOnlyAfterVerifiedAuthentication()
    {
        string path = NewStorePath();
        object machine = CreateMachine(path);
        Call(machine, "Initialize", true);
        Call(machine, "BeginGoogleAuthentication");

        object store = CreateStore(path);
        Assert.AreEqual(
            "None",
            LoadMode(store).ToString(),
            "Starting authentication must not select Google.");
        Assert.AreEqual(
            "PlayModeSelectionPending",
            GetRestartState(path, true),
            "Interrupted first-time authentication must return to Welcome.");

        object retryingMachine = CreateMachine(path);
        Call(retryingMachine, "Initialize", true);
        Call(retryingMachine, "BeginGoogleAuthentication");
        Assert.IsTrue((bool)Call(retryingMachine, "GoogleVerified"));

        object verifiedStore = CreateStore(path);
        Assert.AreEqual("Google", LoadMode(verifiedStore).ToString());
        AssertState(retryingMachine, "LoadingRestorePending");
    }

    [Test]
    public void GoogleCancellationReturnsToSelectionAndDoesNotPersistGoogle()
    {
        string path = NewStorePath();
        object machine = CreateMachine(path);
        Call(machine, "Initialize", true);
        Call(machine, "BeginGoogleAuthentication");

        Assert.IsTrue((bool)Call(
            machine,
            "GoogleAuthenticationCancelledOrFailed"));
        AssertState(machine, "PlayModeSelectionPending");
        Assert.AreEqual("None", LoadMode(CreateStore(path)).ToString());
    }

    [Test]
    public void ReturningGoogleModeRequiresRestorationBeforeLoading()
    {
        string path = NewStorePath();
        object machine = CreateMachine(path);
        Call(machine, "Initialize", true);
        Call(machine, "BeginGoogleAuthentication");
        Call(machine, "GoogleVerified");

        object returningMachine = CreateMachine(path);
        Call(returningMachine, "Initialize", true);

        AssertState(returningMachine, "GoogleAuthenticationPending");
        Assert.IsTrue((bool)GetProperty(
            returningMachine,
            "RequiresGoogleSessionRestoration"));
        Assert.IsFalse((bool)Call(returningMachine, "LoadingCompleted"));
    }

    [Test]
    public void InterruptedReturningGoogleRestorationReturnsToSelection()
    {
        string path = NewStorePath();
        object machine = CreateMachine(path);
        Call(machine, "Initialize", true);
        Call(machine, "BeginGoogleAuthentication");
        Call(machine, "GoogleVerified");

        object returningMachine = CreateMachine(path);
        Call(returningMachine, "Initialize", true);
        Call(returningMachine, "BeginGoogleAuthentication");

        object afterInterruption = CreateMachine(path);
        Call(afterInterruption, "Initialize", true);

        AssertState(afterInterruption, "PlayModeSelectionPending");
        Assert.AreEqual("Google", GetProperty(
            afterInterruption,
            "SelectedPlayMode").ToString());
    }

    [Test]
    public void CorruptSelectionIsPreservedAndRequiresExplicitChoice()
    {
        string path = NewStorePath();
        File.WriteAllText(
            path,
            "{\"version\":1,\"mode\":\"Unexpected\",\"googleAuthenticationPending\":false}");
        object machine = CreateMachine(path);

        Call(machine, "Initialize", true);

        AssertState(machine, "PlayModeSelectionPending");
        Assert.AreEqual("None", GetProperty(
            machine,
            "SelectedPlayMode").ToString());
        StringAssert.Contains(
            "Unexpected",
            File.ReadAllText(path),
            "Reading corrupt data must not rewrite the saved record.");
    }

    [Test]
    public void SelectionWriteFailureIsRecoverableAndDoesNotEnterLoading()
    {
        string blocker = Path.Combine(temporaryRoot, "not-a-directory");
        File.WriteAllText(blocker, "block");
        string impossiblePath = Path.Combine(blocker, "play-mode-v1.json");
        object machine = CreateMachine(impossiblePath);
        Call(machine, "Initialize", true);

        Assert.IsFalse((bool)Call(machine, "SelectGuest"));

        AssertState(machine, "RecoverableError");
        Assert.IsFalse((bool)Call(machine, "Retry"));
        AssertState(machine, "RecoverableError");
    }

    [Test]
    public void GoogleVerificationPersistenceFailureDoesNotSelectGoogle()
    {
        string directory = Path.Combine(temporaryRoot, "profile");
        string path = Path.Combine(directory, "play-mode-v1.json");
        object machine = CreateMachine(path);
        Call(machine, "Initialize", true);
        Assert.IsTrue((bool)Call(machine, "BeginGoogleAuthentication"));

        File.Delete(path);
        Directory.Delete(directory);
        File.WriteAllText(directory, "block");

        Assert.IsFalse((bool)Call(machine, "GoogleVerified"));
        AssertState(machine, "RecoverableError");
        Assert.AreEqual("None", GetProperty(
            machine,
            "SelectedPlayMode").ToString());
    }

    [Test]
    public void LoadingFailureCanBeRetriedAndCompleted()
    {
        object machine = CreateMachine(NewStorePath());
        Call(machine, "Initialize", true);
        Call(machine, "SelectGuest");

        Assert.IsTrue((bool)Call(machine, "LoadingFailed", "load failed"));
        AssertState(machine, "RecoverableError");
        Assert.IsTrue((bool)Call(machine, "Retry"));
        AssertState(machine, "LoadingRestorePending");
        Assert.IsTrue((bool)Call(machine, "LoadingCompleted"));
        AssertState(machine, "ReadyForMainBakery");
    }

    private object CreateMachine(string path)
    {
        return Activator.CreateInstance(
            machineType,
            new[] { CreateStore(path) });
    }

    private object CreateStore(string path)
    {
        return Activator.CreateInstance(storeType, new object[] { path });
    }

    private string NewStorePath()
    {
        return Path.Combine(temporaryRoot, Guid.NewGuid() + ".json");
    }

    private string GetRestartState(string path, bool consent)
    {
        object machine = CreateMachine(path);
        Call(machine, "Initialize", consent);
        return GetProperty(machine, "State").ToString();
    }

    private object LoadMode(object store)
    {
        object[] arguments = { null, null, null };
        Call(store, "Load", arguments);
        return arguments[0];
    }

    private static object Call(
        object target,
        string methodName,
        params object[] arguments)
    {
        MethodInfo method = target.GetType().GetMethod(
            methodName,
            PublicInstance);
        Assert.IsNotNull(method, "Missing public method " + methodName);
        return method.Invoke(target, arguments);
    }

    private static object GetProperty(object target, string propertyName)
    {
        PropertyInfo property = target.GetType().GetProperty(
            propertyName,
            PublicInstance);
        Assert.IsNotNull(property, "Missing property " + propertyName);
        return property.GetValue(target);
    }

    private void AssertState(object machine, string expected)
    {
        Assert.AreEqual(expected, GetProperty(machine, "State").ToString());
    }
}
