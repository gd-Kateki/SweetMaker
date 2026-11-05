using System;
using System.IO;
using System.Reflection;
using NUnit.Framework;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.UnityConsent;

public sealed class StartupFlowIntegrationTests
{
    [TestCase(false, true, true)]
    [TestCase(true, true, true)]
    [TestCase(true, false, true)]
    [TestCase(false, false, false)]
    public void AndroidReleaseAlsoGatesNewGamesBehindAccountStartup(
        bool development, bool android, bool expected)
    {
        Assert.That(InvokePolicy("RequiresAccountStartup", development, android), Is.EqualTo(expected));
    }

    private const BindingFlags StaticNonPublic =
        BindingFlags.Static | BindingFlags.NonPublic;

    [TestCase(false, false, false)]
    [TestCase(false, true, false)]
    [TestCase(true, false, true)]
    [TestCase(true, true, false)]
    public void SaveLoadGateBlocksOnlyAnUnconfirmedEnabledFlow(
        bool gateRequired,
        bool decisionConfirmed,
        bool expected)
    {
        Assert.That(
            InvokePolicy(
                "ShouldBlockSaveLoad",
                gateRequired,
                decisionConfirmed),
            Is.EqualTo(expected));
    }

    [Test]
    public void StartupDecisionCannotReleaseSaveGateDuringPendingRestoreOrWithoutIdentity()
    {
        Type playModeType = FindRuntimeType(
            "SweetMerge.Startup.StartupPlayMode");
        object guest = Enum.Parse(playModeType, "Guest");
        object google = Enum.Parse(playModeType, "Google");

        Assert.That(
            InvokePolicy(
                "CanConfirmStartupDecision",
                true,
                false,
                false,
                guest,
                false),
            Is.True);
        Assert.That(
            InvokePolicy(
                "CanConfirmStartupDecision",
                true,
                false,
                false,
                google,
                true),
            Is.True);
        Assert.That(
            InvokePolicy(
                "CanConfirmStartupDecision",
                true,
                false,
                true,
                guest,
                false),
            Is.False);
        Assert.That(
            InvokePolicy(
                "CanConfirmStartupDecision",
                true,
                false,
                false,
                google,
                false),
            Is.False);
        Assert.That(
            InvokePolicy(
                "CanConfirmStartupDecision",
                true,
                true,
                false,
                guest,
                false),
            Is.False);
        Assert.That(
            InvokePolicy(
                "CanConfirmStartupDecision",
                false,
                false,
                false,
                guest,
                false),
            Is.False);
    }

    [Test]
    public void SaveInitializationStartsOnlyBeforeTheFirstAttempt()
    {
        Assert.That(
            InvokePolicy("ShouldStartSaveInitialization", false),
            Is.True);
        Assert.That(
            InvokePolicy("ShouldStartSaveInitialization", true),
            Is.False);
    }

    [Test]
    public void GameStartupStaysWaitingUntilSelectionAndVerifiedIdentity()
    {
        Type startupType = FindRuntimeType("GameStartupCoordinator");
        GameObject host = new GameObject("StartupDecisionGateTest");
        try
        {
            Component startup = host.AddComponent(startupType);
            startupType.GetMethod(
                    "RequireStartupDecisionGate",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(startup, null);
            startupType.GetMethod(
                    "InitializeStartup",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(startup, null);

            Assert.That(GetProperty(startup, "Status").ToString(),
                Is.EqualTo("Waiting"));
            Type playModeType = startupType.Assembly.GetType(
                "SweetMerge.Startup.StartupPlayMode",
                true);
            object googleMode = Enum.Parse(playModeType, "Google");
            bool confirmed = (bool)startupType.GetMethod(
                    "ConfirmStartupDecision",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(startup, new[] { googleMode, (object)false });

            Assert.That(confirmed, Is.False);
            Assert.That(GetProperty(startup, "Status").ToString(),
                Is.EqualTo("Waiting"));
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(host);
        }
    }

    [Test]
    public void GameStartupDoesNotLoadSaveWhileRestoreIsPending()
    {
        string root=Path.GetFullPath(Path.Combine(
            "Temp","StartupRestoreTests",Guid.NewGuid().ToString("N")));
        Directory.CreateDirectory(root);
        File.WriteAllText(
            Path.Combine(root,"cloud-restore.pending.json"),
            "pending");
        GameObject host=null;
        try
        {
            Type cloudFiles=FindRuntimeType("SweetMerge.Cloud.SimpleCloudFiles");
            MethodInfo refresh=cloudFiles.GetMethod(
                "RefreshPendingStateAtRoot",
                BindingFlags.Static | BindingFlags.NonPublic);
            Assert.That(refresh,Is.Not.Null);
            Assert.That(refresh.Invoke(null,new object[]{root}),Is.True);

            Type startupType=FindRuntimeType("GameStartupCoordinator");
            host=new GameObject("PendingRestoreSaveLoadGateTest");
            Component startup=host.AddComponent(startupType);
            startupType.GetMethod(
                    "InitializeStartup",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(startup,null);

            Assert.That(GetProperty(startup,"Status").ToString(),
                Is.EqualTo("Waiting"));
        }
        finally
        {
            if (host != null)
                UnityEngine.Object.DestroyImmediate(host);
            FindRuntimeType("SweetMerge.Cloud.SimpleCloudFiles")
                .GetMethod("ResetStateForTests",
                    BindingFlags.Static | BindingFlags.NonPublic)
                .Invoke(null,null);
            if (Directory.Exists(root))
                Directory.Delete(root,true);
        }
    }

    [TestCase(false, true)]
    [TestCase(true, false)]
    public void LegacyAnalyticsPromptIsSuppressedOnlyWhenStartupOwnsPrivacy(
        bool startupOwnsPrivacy,
        bool expected)
    {
        bool suppressed = InvokePolicy(
            "ShouldSuppressLegacyAnalyticsPrompt",
            startupOwnsPrivacy,
            "MainBakery");
        Assert.That(suppressed, Is.EqualTo(startupOwnsPrivacy));

        Type presentation = FindRuntimeType(
            "SweetMerge.Analytics.AnalyticsConsentPresentation");
        MethodInfo shouldShowPrompt = presentation.GetMethod(
            "ShouldShowPrompt",
            StaticNonPublic);
        Assert.That(shouldShowPrompt, Is.Not.Null);

        bool result = (bool)shouldShowPrompt.Invoke(
            null,
            new object[]
            {
                "MainBakery",
                ConsentStatus.Unspecified,
                false,
                suppressed
            });

        Assert.That(result, Is.EqualTo(expected));
    }

    [TestCase(false, false, true)]
    [TestCase(true, false, false)]
    [TestCase(false, true, false)]
    public void LoadingOverlayYieldsOnlyWhileStartupSelectionOwnsInput(
        bool readinessReady,
        bool selectionOwnsInput,
        bool expected)
    {
        Assert.That(
            InvokePolicy(
                "ShouldShowLoadingOverlay",
                readinessReady,
                selectionOwnsInput),
            Is.EqualTo(expected));
    }

    [TestCase(false, false, false, true)]
    [TestCase(true, false, true, false)]
    [TestCase(true, true, false, false)]
    [TestCase(true, true, true, true)]
    public void TutorialWelcomeWaitsForStartupSelectionAndLocalReadiness(
        bool integrationEnabled,
        bool decisionConfirmed,
        bool localStartupReady,
        bool expected)
    {
        Assert.That(
            InvokePolicy(
                "ShouldShowTutorialWelcome",
                integrationEnabled,
                decisionConfirmed,
                localStartupReady),
            Is.EqualTo(expected));
    }

    [TestCase(false, true, false, false)]
    [TestCase(true, false, false, false)]
    [TestCase(true, true, false, true)]
    [TestCase(true, true, true, false)]
    public void StartupFlowOnlyStartsInMainBakeryBeforeDecisionCompletion(
        bool integrationEnabled,
        bool isMainBakery,
        bool decisionConfirmed,
        bool expected)
    {
        Assert.That(
            InvokePolicy(
                "ShouldStartFlow",
                integrationEnabled,
                isMainBakery,
                decisionConfirmed),
            Is.EqualTo(expected));
    }

    [TestCase(true, true, false, true)]
    [TestCase(false, true, false, false)]
    [TestCase(true, false, false, false)]
    [TestCase(true, true, true, false)]
    public void WelcomeFlowStartsOnlyForAnUnconfirmedEnabledWelcome(
        bool integrationEnabled,
        bool isWelcome,
        bool decisionConfirmed,
        bool expected)
    {
        Assert.That(
            InvokePolicy(
                "ShouldStartWelcomeFlow",
                integrationEnabled,
                isWelcome,
                decisionConfirmed),
            Is.EqualTo(expected));
    }

    [Test]
    public void DevelopmentBuildEnablesIntegrationAndReleaseBuildDisablesIt()
    {
        Assert.That(
            InvokePolicy("IsFeatureEnabledByDefault", true),
            Is.True);
        Assert.That(
            InvokePolicy("IsFeatureEnabledByDefault", false),
            Is.False);

        Type owner = FindRuntimeType(
            "SweetMerge.Startup.StartupFlowIntegrationOwner");
        PropertyInfo enabled = owner.GetProperty(
            "FeatureEnabled",
            BindingFlags.Static | BindingFlags.NonPublic);
        Assert.That(enabled, Is.Not.Null);
        Assert.That(enabled.GetSetMethod(true), Is.Null,
            "Activation must not be changed at runtime.");
#if DEVELOPMENT_BUILD
        Assert.That(enabled.GetValue(null), Is.True);
#else
        Assert.That(enabled.GetValue(null), Is.False);
#endif
    }

    [Test]
    public void NormalBindingRequiresAllDependenciesAndCanRecoverOnRetry()
    {
        Assert.That(
            InvokePolicy(
                "AreRequiredDependenciesReady",
                false,
                true,
                true,
                true,
                true),
            Is.True);
        Assert.That(
            InvokePolicy(
                "AreRequiredDependenciesReady",
                false,
                true,
                false,
                true,
                true),
            Is.False);
        Assert.That(
            InvokePolicy(
                "AreRequiredDependenciesReady",
                false,
                true,
                true,
                false,
                true),
            Is.False);
        Assert.That(
            InvokePolicy(
                "AreRequiredDependenciesReady",
                false,
                true,
                true,
                true,
                false),
            Is.False);

        Assert.That(
            InvokePolicy(
                "AreRequiredDependenciesReady",
                false,
                true,
                true,
                true,
                true),
            Is.True,
            "A retry after dependencies appear can bind the normal flow.");
        Assert.That(
            InvokePolicy("ShouldBlockSaveLoad", true, false),
            Is.True,
            "Dependency failure must not release the Save V2 gate.");
        Assert.That(
            InvokePolicy("ShouldBlockSaveLoad", true, true),
            Is.False);
    }

    [Test]
    public void WelcomeBindingWaitsForPrivacyAndAuthenticationDependencies()
    {
        Assert.That(
            InvokePolicy(
                "AreWelcomeDependenciesReady",
                true,
                true,
                true),
            Is.True);
        Assert.That(
            InvokePolicy(
                "AreWelcomeDependenciesReady",
                false,
                true,
                true),
            Is.False);
        Assert.That(
            InvokePolicy(
                "AreWelcomeDependenciesReady",
                true,
                false,
                true),
            Is.False);
        Assert.That(
            InvokePolicy(
                "AreWelcomeDependenciesReady",
                true,
                true,
                false),
            Is.False);
        Assert.That(
            InvokePolicy("ShouldBlockSaveLoad", true, false),
            Is.True,
            "Missing Welcome dependencies must not open the Save V2 gate.");
    }

    [Test]
    public void DependencyWaitTimesOutAndRetryRechecksPendingRecoveryDependencies()
    {
        Assert.That(
            InvokePolicy("HasDependencyWaitExpired", 4.9f, 5f),
            Is.False);
        Assert.That(
            InvokePolicy("HasDependencyWaitExpired", 5f, 5f),
            Is.True);
        Assert.That(
            InvokePolicy("ShouldBindOwner", false, true),
            Is.True,
            "Pending recovery must bind when normal startup is disabled.");
        Assert.That(
            InvokePolicy(
                "AreRequiredDependenciesReady",
                true,
                true,
                true,
                false,
                false),
            Is.True,
            "Pending recovery must not depend on analytics or normal startup.");
        Assert.That(
            InvokePolicy(
                "AreRequiredDependenciesReady",
                true,
                false,
                true,
                false,
                false),
            Is.False,
            "Pending recovery must wait for its user-facing recovery UI.");
        Assert.That(
            InvokePolicy("ShouldBlockSaveLoad", true, false),
            Is.True);
    }

    [Test]
    public void DependencyFailureShowsBlockingRetryOverlay()
    {
        GameObject canvasObject = new GameObject(
            "MainCanvas",
            typeof(RectTransform),
            typeof(Canvas),
            typeof(GraphicRaycaster));
        GameObject host = null;
        PropertyInfo dependencyFailure = FindRuntimeType(
                "SweetMerge.Startup.StartupFlowIntegrationOwner")
            .GetProperty(
                "DependencyFailureMessage",
                BindingFlags.Static | BindingFlags.NonPublic);
        MethodInfo refresh = null;
        try
        {
            host = new GameObject(
                "StartupFailureOverlayTest",
                typeof(RectTransform));
            host.transform.SetParent(canvasObject.transform, false);
            host.SetActive(false);
            Type loadingType = FindRuntimeType("MainBakeryStartupUI");
            Component loading = host.AddComponent(loadingType);
            loadingType.GetMethod(
                    "Awake",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(loading, null);

            dependencyFailure.GetSetMethod(true).Invoke(
                null,
                new object[]
                {
                    "Required startup dependencies are unavailable."
                });
            refresh = loadingType.GetMethod(
                "Refresh",
                BindingFlags.Instance | BindingFlags.NonPublic);
            refresh.Invoke(loading, null);

            Assert.That(
                host.transform.Find("StartupOverlay").gameObject.activeSelf,
                Is.True);
            Assert.That(
                host.transform
                    .Find("StartupOverlay/SafeArea/StartupModalCard/RetryButton")
                    .gameObject.activeSelf,
                Is.True);
            Assert.That(
                host.transform
                    .Find("StartupOverlay/SafeArea/StartupModalCard/RetryButton")
                    .GetComponent<Button>().interactable,
                Is.True);
            Transform status = host.transform.Find(
                "StartupOverlay/SafeArea/StartupModalCard/Status");
            Type tmpTextType = FindRuntimeType("TMPro.TMP_Text");
            Component statusText = status.GetComponent(tmpTextType);
            Assert.That(
                tmpTextType.GetProperty("text").GetValue(statusText),
                Is.EqualTo(
                    "Required startup dependencies are unavailable."));
        }
        finally
        {
            dependencyFailure.GetSetMethod(true).Invoke(null, new object[] { null });
            if (canvasObject != null)
                UnityEngine.Object.DestroyImmediate(canvasObject);
        }
    }

    private static bool InvokePolicy(
        string methodName,
        params object[] arguments)
    {
        Type policy = FindRuntimeType(
            "SweetMerge.Startup.StartupIntegrationPolicy");
        MethodInfo method = policy.GetMethod(methodName, StaticNonPublic);
        Assert.That(method, Is.Not.Null, methodName);
        return (bool)method.Invoke(null, arguments);
    }

    private static object GetProperty(object target, string propertyName)
    {
        PropertyInfo property = target.GetType().GetProperty(
            propertyName,
            BindingFlags.Public | BindingFlags.Instance);
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

        Assert.Fail("Runtime type was not found: " + fullName);
        return null;
    }

}
