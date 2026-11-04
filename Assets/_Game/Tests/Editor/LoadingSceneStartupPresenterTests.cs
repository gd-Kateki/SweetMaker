using System;
using System.Linq;
using System.Reflection;
using NUnit.Framework;

public sealed class LoadingSceneStartupPresenterTests
{
    private const BindingFlags StaticNonPublic =
        BindingFlags.Static | BindingFlags.NonPublic;

    [Test]
    public void PresenterInstallsOnlyInDevelopmentPlayerLoadingScene()
    {
        AssertPolicy(
            "ShouldInstall",
            true,
            false,
            "Loading",
            true);
        AssertPolicy(
            "ShouldInstall",
            false,
            false,
            "Loading",
            false);
        AssertPolicy(
            "ShouldInstall",
            true,
            true,
            "Loading",
            false);
        AssertPolicy(
            "ShouldInstall",
            true,
            false,
            "MainBakery",
            false);
    }

    [Test]
    public void PresenterPersistsOnlyAcrossLoadingToMainBakeryHandoff()
    {
        AssertPolicy(
            "ShouldPersistPresenter",
            true,
            false,
            true,
            true,
            true);
        AssertPolicy(
            "ShouldPersistPresenter",
            true,
            false,
            true,
            false,
            false);
        AssertPolicy(
            "ShouldPersistPresenter",
            false,
            false,
            true,
            true,
            false);
        AssertPolicy(
            "ShouldPersistPresenter",
            true,
            true,
            true,
            true,
            false);
    }

    [Test]
    public void MainBakeryRequiresConfirmedSafeIdentityAndNoPendingRestore()
    {
        Type policy = FindRuntimeType(
            "SweetMerge.Startup.DevelopmentStartupRoutePolicy");
        MethodInfo canRequest = policy.GetMethod(
            "CanRequestMainBakery",
            StaticNonPublic);
        Assert.That(canRequest, Is.Not.Null);
        Type modeType = FindRuntimeType(
            "SweetMerge.Startup.StartupPlayMode");
        object guest = Enum.Parse(modeType, "Guest");
        object google = Enum.Parse(modeType, "Google");

        AssertRequest(canRequest, true, false, false, "Loading", true, guest, false, false, true);
        AssertRequest(canRequest, true, false, false, "Loading", true, google, true, false, true);
        AssertRequest(canRequest, true, false, false, "Loading", false, guest, false, false, false);
        AssertRequest(canRequest, true, false, true, "Loading", true, guest, false, false, false);
        AssertRequest(canRequest, true, false, false, "Loading", true, google, false, false, false);
        AssertRequest(canRequest, true, false, false, "MainBakery", true, guest, false, false, false);
        AssertRequest(canRequest, false, false, false, "Loading", true, guest, false, false, false);
        AssertRequest(canRequest, true, true, false, "Loading", true, guest, false, false, false);
        AssertRequest(canRequest, true, false, false, "Loading", true, guest, false, true, false);
    }

    [Test]
    public void MainBakerySceneLoadIsStartedAtMostOnce()
    {
        Type policy = FindRuntimeType(
            "SweetMerge.Startup.DevelopmentStartupRoutePolicy");
        MethodInfo shouldBegin = policy.GetMethod(
            "ShouldBeginMainBakeryRequest",
            StaticNonPublic);
        Assert.That(shouldBegin, Is.Not.Null);
        Assert.That(shouldBegin.IsStatic, Is.True);

        ParameterInfo[] parameters = shouldBegin.GetParameters();
        Assert.That(parameters.Length, Is.EqualTo(2));
        Assert.That(parameters[0].ParameterType, Is.EqualTo(typeof(bool)));
        Assert.That(parameters[1].ParameterType, Is.EqualTo(typeof(bool)));

        Assert.That(
            shouldBegin.Invoke(null, new object[] { false, false }),
            Is.True);
        Assert.That(
            shouldBegin.Invoke(null, new object[] { true, false }),
            Is.False);
        Assert.That(
            shouldBegin.Invoke(null, new object[] { false, true }),
            Is.False);
    }

    [Test]
    public void LoadingDismissalRequiresAllReadinessAndSafetyGates()
    {
        AssertPolicy(
            "CanDismiss",
            true,
            true,
            true,
            false,
            false,
            true);
        AssertPolicy(
            "CanDismiss",
            false,
            true,
            true,
            false,
            false,
            false);
        AssertPolicy(
            "CanDismiss",
            true,
            false,
            true,
            false,
            false,
            false);
        AssertPolicy(
            "CanDismiss",
            true,
            true,
            false,
            false,
            false,
            false);
        AssertPolicy(
            "CanDismiss",
            true,
            true,
            true,
            true,
            false,
            false);
        AssertPolicy(
            "CanDismiss",
            true,
            true,
            true,
            false,
            true,
            false);
    }

    [Test]
    public void EventSystemOwnershipKeepsLoadingInputUntilMainBakeryIsReady()
    {
        AssertPolicy("ShouldUseLoadingEventSystem", false, true, true);
        AssertPolicy("ShouldUseLoadingEventSystem", true, false, true);
        AssertPolicy("ShouldUseLoadingEventSystem", true, true, false);

        Type policy = FindRuntimeType(
            "SweetMerge.Startup.DevelopmentStartupRoutePolicy");
        MethodInfo isUsable = policy.GetMethod(
            "IsEventSystemUsable",
            StaticNonPublic);
        Assert.That(isUsable, Is.Not.Null);
        Assert.That(isUsable.Invoke(null, new object[] { true, true }), Is.True);
        Assert.That(isUsable.Invoke(null, new object[] { false, true }), Is.False);
        Assert.That(isUsable.Invoke(null, new object[] { true, false }), Is.False);
    }

    [Test]
    public void RetryIsOfferedOnlyForTimeoutOrRecoverableFailure()
    {
        AssertPolicy("ShouldOfferRetry", false, false, false, false);
        AssertPolicy("ShouldOfferRetry", true, false, false, true);
        AssertPolicy("ShouldOfferRetry", false, true, false, true);
        AssertPolicy("ShouldOfferRetry", false, false, true, true);
    }

    private static void AssertRequest(
        MethodInfo method,
        bool developmentBuild,
        bool editor,
        bool restorePending,
        string activeScene,
        bool decisionConfirmed,
        object playMode,
        bool googleIdentityVerified,
        bool loadPending,
        bool expected)
    {
        Assert.That(
            method.Invoke(
                null,
                new[]
                {
                    (object)developmentBuild,
                    editor,
                    restorePending,
                    activeScene,
                    decisionConfirmed,
                    playMode,
                    googleIdentityVerified,
                    loadPending
                }),
            Is.EqualTo(expected));
    }

    private static void AssertPolicy(
        string methodName,
        params object[] arguments)
    {
        object expected = arguments[arguments.Length - 1];
        object[] inputs = arguments.Take(arguments.Length - 1).ToArray();
        Type policy = FindRuntimeType(
            "SweetMerge.Startup.LoadingPresenterPolicy");
        MethodInfo method = policy.GetMethod(methodName, StaticNonPublic);
        Assert.That(method, Is.Not.Null, methodName);
        object result = method.Invoke(null, inputs);
        Assert.That(result, Is.EqualTo(expected));
    }

    private static Type FindRuntimeType(string fullName)
    {
        return AppDomain.CurrentDomain
            .GetAssemblies()
            .Select(assembly => assembly.GetType(fullName, false))
            .First(type => type != null);
    }
}
