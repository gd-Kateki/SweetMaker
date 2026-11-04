using System;
using System.IO;
using System.Reflection;
using System.Threading.Tasks;
using NUnit.Framework;
using UnityEngine;
using UnityEngine.UI;

public sealed class StartupFlowCoordinatorTests
{
    private const BindingFlags PublicInstance =
        BindingFlags.Public | BindingFlags.Instance;
    private GameObject canvasObject;
    private GameObject hostObject;
    private Component view;
    private Type viewType;
    private Type machineType;
    private Type coordinatorType;
    private string temporaryRoot;
    private bool consentChosen;
    private bool lastConsentGranted;
    private bool consentPersistenceSucceeds = true;
    private int consentWriteCount;
    private int authenticationCallCount;
    private bool authenticationVerified;
    private bool lastAuthenticationWasRestore;
    private TaskCompletionSource<bool> pendingAuthentication;

    [SetUp]
    public void SetUp()
    {
        consentChosen = false;
        lastConsentGranted = false;
        consentPersistenceSucceeds = true;
        consentWriteCount = 0;
        authenticationCallCount = 0;
        authenticationVerified = false;
        lastAuthenticationWasRestore = false;
        pendingAuthentication = null;
        temporaryRoot = Path.Combine(
            Path.GetTempPath(),
            "SweetMakerStartupCoordinatorTests",
            Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(temporaryRoot);

        viewType = FindRuntimeType("StartupPrivacyWelcomeUI");
        Assert.That(viewType, Is.Not.Null);
        machineType = viewType.Assembly.GetType(
            "SweetMerge.Startup.StartupFlowMachine",
            true);
        coordinatorType = viewType.Assembly.GetType(
            "SweetMerge.Startup.StartupFlowCoordinator",
            true);

        canvasObject = new GameObject(
            "StartupCoordinatorTestCanvas",
            typeof(RectTransform),
            typeof(Canvas),
            typeof(GraphicRaycaster));
        canvasObject.GetComponent<Canvas>().renderMode =
            RenderMode.ScreenSpaceOverlay;
        hostObject = new GameObject(
            "StartupCoordinatorTestHost",
            typeof(RectTransform));
        hostObject.transform.SetParent(canvasObject.transform, false);
        view = hostObject.AddComponent(viewType);

        MethodInfo awake = viewType.GetMethod(
            "Awake",
            BindingFlags.Instance | BindingFlags.NonPublic);
        Assert.That(awake, Is.Not.Null);
        awake.Invoke(view, null);
    }

    [TearDown]
    public void TearDown()
    {
        if (Directory.Exists(temporaryRoot))
            Directory.Delete(temporaryRoot, true);
        if (canvasObject != null)
            UnityEngine.Object.DestroyImmediate(canvasObject);
    }

    [TestCase("AllowAnalyticsButton", true)]
    [TestCase("DeclineAnalyticsButton", false)]
    public void PrivacyChoiceUsesPersistenceAndAdvancesOnlyWhenConfirmed(
        string buttonName,
        bool granted)
    {
        object coordinator = CreateCoordinator(NewStorePath());
        Assert.That((bool)Call(coordinator, "Initialize"), Is.True);
        Assert.That(GetProperty(view, "IsVisible"), Is.True);
        Assert.That(consentWriteCount, Is.Zero);

        Click("PrivacyScreen/" + buttonName);

        Assert.That(consentWriteCount, Is.EqualTo(1));
        Assert.That(lastConsentGranted, Is.EqualTo(granted));
        Assert.That(GetProperty(view, "VisibleScreen").ToString(),
            Is.EqualTo("Welcome"));
        Assert.That(GetProperty(coordinator, "Outcome").ToString(),
            Is.EqualTo("Idle"));
    }

    [Test]
    public void UnconfirmedPrivacyChoiceStaysOnPrivacyScreen()
    {
        consentPersistenceSucceeds = false;
        object coordinator = CreateCoordinator(NewStorePath());
        Assert.That((bool)Call(coordinator, "Initialize"), Is.True);

        Click("PrivacyScreen/AllowAnalyticsButton");

        Assert.That(GetProperty(view, "VisibleScreen").ToString(),
            Is.EqualTo("Privacy"));
        Assert.That(GetProperty(view, "IsVisible"), Is.True);
        Assert.That(GetProperty(coordinator, "Outcome").ToString(),
            Is.EqualTo("RecoverableFailure"));
        Assert.That(consentChosen, Is.False);
        Assert.That(consentWriteCount, Is.EqualTo(1));
    }

    [Test]
    public void FirstLaunchMovesFromPrivacyToWelcomeToLoadingDecision()
    {
        object coordinator = CreateCoordinator(NewStorePath());
        Call(coordinator, "Initialize");

        Assert.That(GetProperty(view, "VisibleScreen").ToString(),
            Is.EqualTo("Privacy"));
        Click("PrivacyScreen/AllowAnalyticsButton");
        Assert.That(GetProperty(view, "VisibleScreen").ToString(),
            Is.EqualTo("Welcome"));

        Click("WelcomeScreen/GuestPlayButton");
        Assert.That(GetProperty(coordinator, "Outcome").ToString(),
            Is.EqualTo("GuestReady"));
        Assert.That(GetProperty(view, "IsVisible"), Is.False);
    }

    [Test]
    public void GuestSelectionPersistsBeforeGuestReadyWithoutAuthentication()
    {
        string path = NewStorePath();
        object coordinator = CreateCoordinator(path);
        Call(coordinator, "Initialize");
        Click("PrivacyScreen/AllowAnalyticsButton");
        Click("WelcomeScreen/GuestPlayButton");

        Assert.That(authenticationCallCount, Is.Zero);
        Assert.That(GetProperty(coordinator, "Outcome").ToString(),
            Is.EqualTo("GuestReady"));
        Assert.That(GetProperty(view, "IsVisible"), Is.False);

        object store = CreateStore(path);
        Assert.That(LoadMode(store).ToString(), Is.EqualTo("Guest"));
    }

    [Test]
    public async Task VerifiedGoogleAuthenticationPersistsSelection()
    {
        authenticationVerified = true;
        string path = NewStorePath();
        object coordinator = CreateCoordinator(path);
        Call(coordinator, "Initialize");
        Click("PrivacyScreen/AllowAnalyticsButton");
        Click("WelcomeScreen/GoogleSignInButton");
        await (Task)GetProperty(coordinator, "AuthenticationTask");

        Assert.That(authenticationCallCount, Is.EqualTo(1));
        Assert.That(lastAuthenticationWasRestore, Is.False);
        Assert.That(GetProperty(coordinator, "Outcome").ToString(),
            Is.EqualTo("GoogleVerified"));
        Assert.That(GetProperty(view, "IsVisible"), Is.False);
        Assert.That(LoadMode(CreateStore(path)).ToString(),
            Is.EqualTo("Google"));
    }

    [TestCase(false)]
    [TestCase(true)]
    public async Task CancelledOrFailedGoogleAuthenticationReturnsToWelcome(
        bool returnFailureMessage)
    {
        authenticationVerified = false;
        pendingAuthentication = new TaskCompletionSource<bool>();
        object coordinator = CreateCoordinator(NewStorePath());
        Call(coordinator, "Initialize");
        Click("PrivacyScreen/AllowAnalyticsButton");
        Click("WelcomeScreen/GoogleSignInButton");

        if (returnFailureMessage)
        {
            pendingAuthentication.SetException(
                new InvalidOperationException("test authentication failure"));
        }
        else
        {
            pendingAuthentication.SetResult(false);
        }

        await (Task)GetProperty(coordinator, "AuthenticationTask");

        Assert.That(GetProperty(coordinator, "Outcome").ToString(),
            Is.EqualTo("RecoverableFailure"));
        Assert.That(GetProperty(view, "VisibleScreen").ToString(),
            Is.EqualTo("Welcome"));
        Assert.That(authenticationCallCount, Is.EqualTo(1));
        Assert.That(GetProperty(view, "IsVisible"), Is.True);
    }

    [Test]
    public async Task FailedReturningSessionKeepsGoogleSelectionAndCanRetry()
    {
        string path = NewStorePath();
        SeedGoogleSelection(path);
        object coordinator = CreateCoordinator(path, true);

        Call(coordinator, "Initialize");
        await (Task)GetProperty(coordinator, "AuthenticationTask");

        Assert.That(LoadMode(CreateStore(path)).ToString(),
            Is.EqualTo("Google"));
        Assert.That(GetProperty(coordinator, "Outcome").ToString(),
            Is.EqualTo("RecoverableFailure"));
        Assert.That(GetProperty(view, "VisibleScreen").ToString(),
            Is.EqualTo("Welcome"));

        authenticationVerified = true;
        Assert.That((bool)Call(coordinator, "Retry"), Is.True);
        await (Task)GetProperty(coordinator, "AuthenticationTask");

        Assert.That(authenticationCallCount, Is.EqualTo(2));
        Assert.That(lastAuthenticationWasRestore, Is.True);
        Assert.That(GetProperty(coordinator, "Outcome").ToString(),
            Is.EqualTo("GoogleVerified"));
        Assert.That(LoadMode(CreateStore(path)).ToString(),
            Is.EqualTo("Google"));
    }

    [Test]
    public async Task ReturningGoogleAutomaticallyUsesCachedSessionRestoration()
    {
        string path = NewStorePath();
        SeedGoogleSelection(path);
        pendingAuthentication = new TaskCompletionSource<bool>();
        object coordinator = CreateCoordinator(path, true);

        Assert.That((bool)Call(coordinator, "Initialize"), Is.True);
        Assert.That(GetProperty(coordinator, "Outcome").ToString(),
            Is.EqualTo("WaitingForAuthentication"));
        pendingAuthentication.SetResult(true);
        await (Task)GetProperty(coordinator, "AuthenticationTask");

        Assert.That(authenticationCallCount, Is.EqualTo(1));
        Assert.That(lastAuthenticationWasRestore, Is.True);
        Assert.That(GetProperty(coordinator, "Outcome").ToString(),
            Is.EqualTo("GoogleVerified"));
    }

    [Test]
    public void ReturningGuestSkipsWelcomeAndAuthentication()
    {
        string path = NewStorePath();
        SeedGuestSelection(path);
        consentChosen = true;
        object coordinator = CreateCoordinator(path, true);

        Call(coordinator, "Initialize");

        Assert.That(GetProperty(coordinator, "Outcome").ToString(),
            Is.EqualTo("GuestReady"));
        Assert.That(GetProperty(view, "IsVisible"), Is.False);
        Assert.That(authenticationCallCount, Is.Zero);
        Assert.That(LoadMode(CreateStore(path)).ToString(),
            Is.EqualTo("Guest"));
    }

    [Test]
    public async Task FailedReturningSessionOffersCachedRetry()
    {
        pendingAuthentication = new TaskCompletionSource<bool>();
        object coordinator = CreateCoordinatorForReturningGoogle(
            NewStorePath());
        Call(coordinator, "Initialize");
        pendingAuthentication.SetResult(false);
        await (Task)GetProperty(coordinator, "AuthenticationTask");

        Transform retryButton = hostObject.transform.Find(
            "StartupPrivacyWelcomeOverlay/SafeArea/WelcomeScreen/" +
            "RetryCachedGoogleSessionButton");
        Assert.That(retryButton, Is.Not.Null);
        Assert.That(retryButton.gameObject.activeSelf, Is.True);

        pendingAuthentication = new TaskCompletionSource<bool>();
        Click("WelcomeScreen/RetryCachedGoogleSessionButton");
        Assert.That(authenticationCallCount, Is.EqualTo(2));
        Assert.That(lastAuthenticationWasRestore, Is.True);

        pendingAuthentication.SetResult(true);
        await (Task)GetProperty(coordinator, "AuthenticationTask");
        Assert.That(GetProperty(coordinator, "Outcome").ToString(),
            Is.EqualTo("GoogleVerified"));
    }

    [Test]
    public async Task FailedReturningSessionOffersInteractiveSignIn()
    {
        pendingAuthentication = new TaskCompletionSource<bool>();
        object coordinator = CreateCoordinatorForReturningGoogle(
            NewStorePath());
        Call(coordinator, "Initialize");
        pendingAuthentication.SetResult(false);
        await (Task)GetProperty(coordinator, "AuthenticationTask");

        pendingAuthentication = new TaskCompletionSource<bool>();
        Click("WelcomeScreen/GoogleSignInButton");
        Assert.That(authenticationCallCount, Is.EqualTo(2));
        Assert.That(lastAuthenticationWasRestore, Is.False);

        pendingAuthentication.SetResult(true);
        await (Task)GetProperty(coordinator, "AuthenticationTask");
        Assert.That(GetProperty(coordinator, "Outcome").ToString(),
            Is.EqualTo("GoogleVerified"));
    }

    [Test]
    public async Task RepeatedGoogleInputCannotStartDuplicateAuthentication()
    {
        pendingAuthentication = new TaskCompletionSource<bool>();
        object coordinator = CreateCoordinator(NewStorePath());
        Call(coordinator, "Initialize");
        Click("PrivacyScreen/AllowAnalyticsButton");
        Click("WelcomeScreen/GoogleSignInButton");
        Click("WelcomeScreen/GoogleSignInButton");

        Assert.That(authenticationCallCount, Is.EqualTo(1));
        Assert.That(lastAuthenticationWasRestore, Is.False);
        pendingAuthentication.SetResult(true);
        await (Task)GetProperty(coordinator, "AuthenticationTask");
        Assert.That(GetProperty(coordinator, "Outcome").ToString(),
            Is.EqualTo("GoogleVerified"));
    }

    [Test]
    public async Task DisablingViewInvalidatesPendingAuthenticationCallback()
    {
        pendingAuthentication = new TaskCompletionSource<bool>();
        string path = NewStorePath();
        object coordinator = CreateCoordinator(path);
        Call(coordinator, "Initialize");
        Click("PrivacyScreen/AllowAnalyticsButton");
        Click("WelcomeScreen/GoogleSignInButton");
        Assert.That(authenticationCallCount, Is.EqualTo(1));

        hostObject.SetActive(false);
        MethodInfo onDisable = viewType.GetMethod(
            "OnDisable",
            BindingFlags.Instance | BindingFlags.NonPublic);
        Assert.That(onDisable, Is.Not.Null);
        onDisable.Invoke(view, null);
        hostObject.SetActive(true);
        Call(view, "ShowWelcome");
        pendingAuthentication.SetResult(true);
        await (Task)GetProperty(coordinator, "AuthenticationTask");

        Assert.That(GetProperty(coordinator, "Outcome").ToString(),
            Is.EqualTo("WaitingForAuthentication"));
        Assert.That(LoadMode(CreateStore(path)).ToString(),
            Is.EqualTo("None"));
        Assert.That(consentWriteCount, Is.EqualTo(1));
    }

    [Test]
    public async Task InterruptedGoogleSetupReturnsToWelcomeAndCanRetry()
    {
        string path = NewStorePath();
        pendingAuthentication = new TaskCompletionSource<bool>();
        object firstCoordinator = CreateCoordinator(path);
        Call(firstCoordinator, "Initialize");
        Click("PrivacyScreen/AllowAnalyticsButton");
        Click("WelcomeScreen/GoogleSignInButton");
        Call(firstCoordinator, "Dispose");
        pendingAuthentication.SetResult(false);
        await (Task)GetProperty(firstCoordinator, "AuthenticationTask");

        pendingAuthentication = null;
        authenticationVerified = true;
        object retryCoordinator = CreateCoordinator(path, true);
        Call(retryCoordinator, "Initialize");

        Assert.That(authenticationCallCount, Is.EqualTo(1));
        Assert.That(GetProperty(view, "VisibleScreen").ToString(),
            Is.EqualTo("Welcome"));
        Click("WelcomeScreen/GoogleSignInButton");
        await (Task)GetProperty(retryCoordinator, "AuthenticationTask");

        Assert.That(authenticationCallCount, Is.EqualTo(2));
        Assert.That(GetProperty(retryCoordinator, "Outcome").ToString(),
            Is.EqualTo("GoogleVerified"));
    }

    [Test]
    public void DisposeUnsubscribesFromPrivacyAndWelcomeButtonEvents()
    {
        object coordinator = CreateCoordinator(NewStorePath());
        Call(coordinator, "Initialize");
        Call(coordinator, "Dispose");
        Click("PrivacyScreen/AllowAnalyticsButton");

        Assert.That(consentWriteCount, Is.Zero);
        Assert.That(GetProperty(coordinator, "Outcome").ToString(),
            Is.EqualTo("Idle"));
    }

    private object CreateCoordinator(
        string path,
        bool hasConsent = false)
    {
        consentChosen = hasConsent;
        object store = CreateStore(path);
        object flow = Activator.CreateInstance(
            machineType,
            new[] { store });
        var consentQuery = (Func<bool>)CreateDelegate(
            typeof(Func<bool>),
            nameof(HasPrivacyChoice));
        var consentWriter = (Func<bool, bool>)CreateDelegate(
            typeof(Func<bool, bool>),
            nameof(PersistConsentChoice));
        var googleAuthentication =
            (Func<bool, Task<bool>>)CreateDelegate(
                typeof(Func<bool, Task<bool>>),
                nameof(AuthenticateGoogle));

        return Activator.CreateInstance(
            coordinatorType,
            new object[]
            {
                flow,
                view,
                consentQuery,
                consentWriter,
                googleAuthentication
            });
    }

    private bool HasPrivacyChoice()
    {
        return consentChosen;
    }

    private bool PersistConsentChoice(bool granted)
    {
        consentWriteCount++;
        lastConsentGranted = granted;
        if (consentPersistenceSucceeds)
            consentChosen = true;
        return consentPersistenceSucceeds;
    }

    private Task<bool> AuthenticateGoogle(bool restore)
    {
        authenticationCallCount++;
        lastAuthenticationWasRestore = restore;
        if (pendingAuthentication != null)
            return pendingAuthentication.Task;
        return Task.FromResult(authenticationVerified);
    }

    private Delegate CreateDelegate(Type delegateType, string methodName)
    {
        MethodInfo method = GetType().GetMethod(
            methodName,
            BindingFlags.Instance | BindingFlags.NonPublic);
        Assert.That(method, Is.Not.Null, methodName);
        return Delegate.CreateDelegate(delegateType, this, method);
    }

    private void SeedGoogleSelection(string path)
    {
        object flow = Activator.CreateInstance(
            machineType,
            new[] { CreateStore(path) });
        Call(flow, "Initialize", true);
        Call(flow, "BeginGoogleAuthentication");
        Assert.That((bool)Call(flow, "GoogleVerified"), Is.True);
    }

    private void SeedGuestSelection(string path)
    {
        object flow = Activator.CreateInstance(
            machineType,
            new[] { CreateStore(path) });
        Call(flow, "Initialize", true);
        Assert.That((bool)Call(flow, "SelectGuest"), Is.True);
    }

    private object CreateCoordinatorForReturningGoogle(string path)
    {
        SeedGoogleSelection(path);
        consentChosen = true;
        return CreateCoordinator(path, true);
    }

    private object CreateStore(string path)
    {
        Type storeType = viewType.Assembly.GetType(
            "SweetMerge.Startup.StartupPlayModeStore",
            true);
        return Activator.CreateInstance(storeType, new object[] { path });
    }

    private string NewStorePath()
    {
        return Path.Combine(temporaryRoot, Guid.NewGuid() + ".json");
    }

    private static object LoadMode(object store)
    {
        object[] arguments = { null, null, null };
        Call(store, "Load", arguments);
        return arguments[0];
    }

    private void Click(string relativePath)
    {
        Transform buttonTransform = hostObject.transform.Find(
            "StartupPrivacyWelcomeOverlay/SafeArea/" + relativePath);
        Assert.That(buttonTransform, Is.Not.Null, relativePath);
        Button button = buttonTransform.GetComponent<Button>();
        Assert.That(button, Is.Not.Null, relativePath);
        button.onClick.Invoke();
    }

    private static object Call(
        object target,
        string methodName,
        params object[] arguments)
    {
        MethodInfo method = target.GetType().GetMethod(
            methodName,
            PublicInstance);
        Assert.That(method, Is.Not.Null, methodName);
        return method.Invoke(target, arguments);
    }

    private static object GetProperty(object target, string propertyName)
    {
        PropertyInfo property = target.GetType().GetProperty(
            propertyName,
            PublicInstance);
        Assert.That(property, Is.Not.Null, propertyName);
        return property.GetValue(target);
    }

    private static Type FindRuntimeType(string fullName)
    {
        foreach (Assembly assembly in AppDomain.CurrentDomain.GetAssemblies())
        {
            Type found = assembly.GetType(fullName, false);
            if (found != null)
                return found;
        }

        return null;
    }
}
