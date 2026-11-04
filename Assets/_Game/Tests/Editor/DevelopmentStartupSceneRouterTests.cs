using System;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEngine;

public sealed class DevelopmentStartupSceneRouterTests
{
    private const BindingFlags StaticNonPublic =
        BindingFlags.Static | BindingFlags.NonPublic;
    private const BindingFlags StaticPublicOrNonPublic =
        BindingFlags.Static | BindingFlags.Public | BindingFlags.NonPublic;

    [Test]
    public void PendingRestoreTakesPrecedenceOverSavedGuestAndGoogle()
    {
        AssertRoute(true, "Loaded", "Guest", "Welcome");
        AssertRoute(true, "Loaded", "Google", "Welcome");
    }

    [Test]
    public void MissingAndInvalidSelectionsRouteToWelcome()
    {
        AssertRoute(false, "Missing", "None", "Welcome");
        AssertRoute(false, "InvalidData", "None", "Welcome");
        AssertRoute(false, "ServiceError", "None", "Welcome");
    }

    [Test]
    public void ReturningGuestRoutesToLoadingAndGoogleReturnsToWelcomeForVerification()
    {
        AssertRoute(false, "Loaded", "Guest", "Loading");
        AssertRoute(false, "Loaded", "Google", "Welcome");
    }

    [Test]
    public void RoutePolicyNeverTargetsMainBakery()
    {
        string[] routes =
        {
            ResolveRoute(false, "Missing", "None"),
            ResolveRoute(false, "Loaded", "Guest"),
            ResolveRoute(false, "Loaded", "Google"),
            ResolveRoute(true, "Loaded", "Guest"),
            ResolveRoute(true, "Loaded", "Google")
        };

        foreach (string route in routes)
            Assert.That(
                route == "Welcome" || route == "Loading",
                Is.True,
                "Unexpected route destination: " + route);
    }

    [Test]
    public void SceneLoadRequestIsIdempotent()
    {
        Type policy = FindRuntimeType(
            "SweetMerge.Startup.DevelopmentStartupRoutePolicy");
        MethodInfo shouldRequest = policy.GetMethod(
            "ShouldRequestSceneLoad",
            StaticNonPublic);
        Assert.That(shouldRequest, Is.Not.Null);

        Assert.That(
            shouldRequest.Invoke(
                null,
                new object[] { "Welcome", "Loading", false }),
            Is.True);
        Assert.That(
            shouldRequest.Invoke(
                null,
                new object[] { "Loading", "Loading", false }),
            Is.False);
        Assert.That(
            shouldRequest.Invoke(
                null,
                new object[] { "Welcome", "Loading", true }),
            Is.False);
    }

    [Test]
    public void DuplicateOwnerDoesNotReplaceCurrentOwner()
    {
        Type routerType = FindRuntimeType(
            "SweetMerge.Startup.DevelopmentStartupSceneRouter");
        MethodInfo reset = routerType.GetMethod(
            "ResetStaticState",
            StaticNonPublic);
        MethodInfo awake = routerType.GetMethod(
            "Awake",
            BindingFlags.Instance | BindingFlags.NonPublic);
        PropertyInfo instanceProperty = routerType.GetProperty(
            "Instance",
            StaticPublicOrNonPublic);
        Assert.That(reset, Is.Not.Null);
        Assert.That(awake, Is.Not.Null);
        Assert.That(instanceProperty, Is.Not.Null);

        GameObject firstObject = null;
        GameObject duplicateObject = null;
        try
        {
            reset.Invoke(null, null);
            firstObject = new GameObject("DevelopmentStartupRouterTest");
            Component first = firstObject.AddComponent(routerType);
            if (!ReferenceEquals(instanceProperty.GetValue(null), first))
                awake.Invoke(first, null);

            duplicateObject =
                new GameObject("DuplicateDevelopmentStartupRouterTest");
            Component duplicate = duplicateObject.AddComponent(routerType);
            if (duplicateObject != null &&
                !ReferenceEquals(instanceProperty.GetValue(null), duplicate))
                awake.Invoke(duplicate, null);

            Assert.That(instanceProperty.GetValue(null), Is.SameAs(first));
            Assert.That(duplicateObject == null, Is.True);
        }
        finally
        {
            if (duplicateObject != null)
                UnityEngine.Object.DestroyImmediate(duplicateObject);
            if (firstObject != null)
                UnityEngine.Object.DestroyImmediate(firstObject);
            reset.Invoke(null, null);
        }
    }

    [Test]
    public void RouterRunsOnlyInDevelopmentPlayerNotEditor()
    {
        Type policy = FindRuntimeType(
            "SweetMerge.Startup.DevelopmentStartupRoutePolicy");
        MethodInfo shouldRun = policy.GetMethod(
            "ShouldRun",
            StaticNonPublic);
        Assert.That(shouldRun, Is.Not.Null);

        Assert.That(
            shouldRun.Invoke(null, new object[] { true, false }),
            Is.True);
        Assert.That(
            shouldRun.Invoke(null, new object[] { false, false }),
            Is.False);
        Assert.That(
            shouldRun.Invoke(null, new object[] { true, true }),
            Is.False);
    }

    [Test]
    public void WelcomeToLoadingRequiresValidSelectionAndResolvedRestore()
    {
        Type policy = FindRuntimeType(
            "SweetMerge.Startup.DevelopmentStartupRoutePolicy");
        MethodInfo canRequest = policy.GetMethod(
            "CanRequestLoadingFromWelcome",
            StaticNonPublic);
        Assert.That(canRequest, Is.Not.Null);
        Type modeType = FindRuntimeType(
            "SweetMerge.Startup.StartupPlayMode");
        object guest = Enum.Parse(modeType, "Guest");
        object google = Enum.Parse(modeType, "Google");

        Assert.That(
            canRequest.Invoke(
                null,
                new[] { (object)true, false, false, "Welcome", guest, false, false }),
            Is.True);
        Assert.That(
            canRequest.Invoke(
                null,
                new[] { (object)true, false, false, "Welcome", google, true, false }),
            Is.True);
        Assert.That(
            canRequest.Invoke(
                null,
                new[] { (object)true, false, false, "Welcome", google, false, false }),
            Is.False);
        Assert.That(
            canRequest.Invoke(
                null,
                new[] { (object)true, false, true, "Welcome", guest, false, false }),
            Is.False);
        Assert.That(
            canRequest.Invoke(
                null,
                new[] { (object)true, true, false, "Welcome", guest, false, false }),
            Is.False);
        Assert.That(
            canRequest.Invoke(
                null,
                new[] { (object)true, false, false, "MainBakery", guest, false, false }),
            Is.False);
        Assert.That(
            canRequest.Invoke(
                null,
                new[] { (object)true, false, false, "Welcome", guest, false, true }),
            Is.False);
    }

    private static void AssertRoute(
        bool restorePending,
        string selectionStatus,
        string selectedMode,
        string expectedRoute)
    {
        Assert.That(
            ResolveRoute(restorePending, selectionStatus, selectedMode),
            Is.EqualTo(expectedRoute));
    }

    private static string ResolveRoute(
        bool restorePending,
        string selectionStatus,
        string selectedMode)
    {
        Type policy = FindRuntimeType(
            "SweetMerge.Startup.DevelopmentStartupRoutePolicy");
        MethodInfo resolve = policy.GetMethod(
            "ResolveRoute",
            StaticNonPublic);
        Assert.That(resolve, Is.Not.Null);

        Type statusType = FindRuntimeType(
            "SweetMerge.Startup.StartupPlayModeLoadStatus");
        Type modeType = FindRuntimeType(
            "SweetMerge.Startup.StartupPlayMode");
        object status = Enum.Parse(statusType, selectionStatus);
        object mode = Enum.Parse(modeType, selectedMode);

        return resolve.Invoke(
            null,
            new[] { (object)restorePending, status, mode }).ToString();
    }

    private static Type FindRuntimeType(string fullName)
    {
        return AppDomain.CurrentDomain
            .GetAssemblies()
            .Select(assembly => assembly.GetType(fullName, false))
            .First(type => type != null);
    }
}
