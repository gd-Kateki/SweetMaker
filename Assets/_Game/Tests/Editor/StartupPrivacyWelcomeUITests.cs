using System;
using System.Reflection;
using NUnit.Framework;
using UnityEngine;
using UnityEngine.UI;

public sealed class StartupPrivacyWelcomeUITests
{
    private const BindingFlags PublicInstance =
        BindingFlags.Public | BindingFlags.Instance;
    private GameObject canvasObject;
    private GameObject hostObject;
    private Component controller;
    private Type controllerType;

    [SetUp]
    public void SetUp()
    {
        controllerType = FindRuntimeType("StartupPrivacyWelcomeUI");
        Assert.That(controllerType, Is.Not.Null);

        canvasObject = new GameObject(
            "StartupUITestCanvas",
            typeof(RectTransform),
            typeof(Canvas),
            typeof(GraphicRaycaster));
        canvasObject.GetComponent<Canvas>().renderMode =
            RenderMode.ScreenSpaceOverlay;

        hostObject = new GameObject(
            "StartupUITestHost",
            typeof(RectTransform));
        hostObject.transform.SetParent(canvasObject.transform, false);
        controller = hostObject.AddComponent(controllerType);
        Assert.That(controller, Is.Not.Null);

        MethodInfo awake = controllerType.GetMethod(
            "Awake",
            BindingFlags.Instance | BindingFlags.NonPublic);
        Assert.That(awake, Is.Not.Null);
        awake.Invoke(controller, null);
    }

    [TearDown]
    public void TearDown()
    {
        if (canvasObject != null)
            UnityEngine.Object.DestroyImmediate(canvasObject);
    }

    [Test]
    public void StartsHiddenWithNoVisibleScreen()
    {
        Assert.That(GetProperty(controller, "IsVisible"), Is.False);
        Assert.That(
            GetProperty(controller, "VisibleScreen").ToString(),
            Is.EqualTo("None"));

        GameObject overlay = hostObject.transform
            .Find("StartupPrivacyWelcomeOverlay").gameObject;
        Assert.That(overlay.activeSelf, Is.False);
    }

    [Test]
    public void PrivacyAndWelcomeCanBeShownAndHiddenExplicitly()
    {
        Assert.That((bool)Invoke("ShowPrivacy"), Is.True);
        Assert.That(GetProperty(controller, "IsVisible"), Is.True);
        Assert.That(
            GetProperty(controller, "VisibleScreen").ToString(),
            Is.EqualTo("Privacy"));
        Assert.That(Find("PrivacyScreen").gameObject.activeSelf, Is.True);
        Assert.That(Find("WelcomeScreen").gameObject.activeSelf, Is.False);

        Assert.That((bool)Invoke("ShowWelcome"), Is.True);
        Assert.That(
            GetProperty(controller, "VisibleScreen").ToString(),
            Is.EqualTo("Welcome"));
        Assert.That(Find("PrivacyScreen").gameObject.activeSelf, Is.False);
        Assert.That(Find("WelcomeScreen").gameObject.activeSelf, Is.True);
        Assert.That(GetText("WelcomeScreen/Title"),
            Is.EqualTo("Dessert Merge Cafe"));

        Invoke("Hide");
        Assert.That(GetProperty(controller, "IsVisible"), Is.False);
        Assert.That(
            GetProperty(controller, "VisibleScreen").ToString(),
            Is.EqualTo("None"));
    }

    [Test]
    public void PrivacyButtonsDispatchEventsWithoutAutomaticallyDismissing()
    {
        int allowed = 0;
        int declined = 0;
        Subscribe("AnalyticsAllowed", () => allowed++);
        Subscribe("AnalyticsDeclined", () => declined++);

        Invoke("ShowPrivacy");
        Click("PrivacyScreen/AllowAnalyticsButton");
        Assert.That(allowed, Is.EqualTo(1));
        Assert.That(declined, Is.Zero);
        Assert.That(GetProperty(controller, "IsVisible"), Is.True);

        Click("PrivacyScreen/DeclineAnalyticsButton");
        Assert.That(allowed, Is.EqualTo(1));
        Assert.That(declined, Is.EqualTo(1));
        Assert.That(GetProperty(controller, "IsVisible"), Is.True);
    }

    [Test]
    public void WelcomeButtonsDispatchEventsAndFeedbackCanBeUpdated()
    {
        int googleRequests = 0;
        int guestRequests = 0;
        Subscribe("GoogleSignInRequested", () => googleRequests++);
        Subscribe("GuestPlayRequested", () => guestRequests++);

        Invoke("ShowWelcome");
        Click("WelcomeScreen/GoogleSignInButton");
        Click("WelcomeScreen/GuestPlayButton");

        Assert.That(googleRequests, Is.EqualTo(1));
        Assert.That(guestRequests, Is.EqualTo(1));
        Assert.That(GetProperty(controller, "IsVisible"), Is.True);

        Invoke("SetFeedback", "Sign-in cancelled. Choose an option.");
        Assert.That(
            GetText("WelcomeScreen/Feedback"),
            Is.EqualTo("Sign-in cancelled. Choose an option."));
    }

    [Test]
    public void CachedSessionRetryIsHiddenUntilEnabledAndDispatches()
    {
        int retryRequests = 0;
        Subscribe(
            "RetryGoogleRestorationRequested",
            () => retryRequests++);
        Invoke("ShowWelcome");

        Transform retryButton = Find(
            "WelcomeScreen/RetryCachedGoogleSessionButton");
        Assert.That(retryButton.gameObject.activeSelf, Is.False);
        Invoke("SetGoogleRecoveryActionsVisible", true);
        Assert.That(retryButton.gameObject.activeSelf, Is.True);

        Click("WelcomeScreen/RetryCachedGoogleSessionButton");

        Assert.That(retryRequests, Is.EqualTo(1));
    }

    [Test]
    public void SwitchAccountHelpCanBeShownAndDispatches()
    {
        int switchRequests = 0;
        Subscribe("SwitchAccountRequested", () => switchRequests++);
        Invoke("ShowWelcome");

        Transform switchButton = Find("WelcomeScreen/SwitchAccountButton");
        Assert.That(switchButton.gameObject.activeSelf, Is.False);
        Invoke("SetGoogleRecoveryActionsVisible", true);
        Assert.That(switchButton.gameObject.activeSelf, Is.False);
        Invoke("SetSwitchAccountVisible", true);
        Assert.That(switchButton.gameObject.activeSelf, Is.True);

        Click("WelcomeScreen/SwitchAccountButton");

        Assert.That(switchRequests, Is.EqualTo(1));
    }

    [Test]
    public void StartupRetryCanBePresentedOnPrivacyOrWelcome()
    {
        int retries = 0;
        Subscribe("RetryStartupRequested", () => retries++);

        Invoke("ShowPrivacy");
        Invoke("SetRetryStartupVisible", true);
        Assert.That(
            Find("PrivacyScreen/RetryStartupButton").gameObject.activeSelf,
            Is.True);
        Click("PrivacyScreen/RetryStartupButton");

        Invoke("ShowWelcome");
        Assert.That(
            Find("WelcomeScreen/RetryStartupButton").gameObject.activeSelf,
            Is.True);
        Click("WelcomeScreen/RetryStartupButton");

        Assert.That(retries, Is.EqualTo(2));
    }

    [Test]
    public void PrivacyChoicesCanBeDisabledUntilDependenciesRecover()
    {
        Invoke("ShowPrivacy");
        Invoke("SetPrivacyActionsInteractable", false);

        Assert.That(
            Find("PrivacyScreen/AllowAnalyticsButton")
                .GetComponent<Button>().interactable,
            Is.False);
        Assert.That(
            Find("PrivacyScreen/DeclineAnalyticsButton")
                .GetComponent<Button>().interactable,
            Is.False);

        Invoke("SetPrivacyActionsInteractable", true);
        Assert.That(
            Find("PrivacyScreen/AllowAnalyticsButton")
                .GetComponent<Button>().interactable,
            Is.True);
    }

    [Test]
    public void WelcomeSceneUsesTheExistingPrivacyWelcomeView()
    {
        MethodInfo isSupportedScene = controllerType.GetMethod(
            "IsSupportedScene",
            BindingFlags.Static | BindingFlags.NonPublic);
        Assert.That(isSupportedScene, Is.Not.Null);
        Assert.That(
            isSupportedScene.Invoke(null, new object[] { "Welcome" }),
            Is.True);
        Assert.That(
            isSupportedScene.Invoke(null, new object[] { "MainBakery" }),
            Is.True);
        Assert.That(
            isSupportedScene.Invoke(null, new object[] { "Loading" }),
            Is.False);

        MethodInfo shouldCreate = controllerType.GetMethod(
            "ShouldCreateView",
            BindingFlags.Static | BindingFlags.NonPublic);
        Assert.That(shouldCreate, Is.Not.Null);
        Assert.That(
            shouldCreate.Invoke(
                null,
                new object[] { true, "Welcome", false }),
            Is.True);
        Assert.That(
            shouldCreate.Invoke(
                null,
                new object[] { true, "Welcome", true }),
            Is.False);
        Assert.That(
            shouldCreate.Invoke(
                null,
                new object[] { true, "Loading", false }),
            Is.False);
    }

    [Test]
    public void PendingRestoreRecoveryHidesGuestButKeepsGoogleSignIn()
    {
        Invoke("ShowWelcome");
        Invoke("SetGuestPlayVisible", false);
        Invoke("SetGoogleRecoveryActionsVisible", true);
        Invoke("SetSwitchAccountVisible", true);

        Assert.That(
            Find("WelcomeScreen/GuestPlayButton").gameObject.activeSelf,
            Is.False);
        Assert.That(
            Find("WelcomeScreen/GoogleSignInButton").gameObject.activeSelf,
            Is.True);
        Assert.That(
            Find("WelcomeScreen/RetryCachedGoogleSessionButton")
                .gameObject.activeSelf,
            Is.True);
        Assert.That(
            Find("WelcomeScreen/SwitchAccountButton").gameObject.activeSelf,
            Is.True);
    }

    [Test]
    public void PrivacyHasNoDismissControlAndBackdropBlocksInput()
    {
        Transform overlay = hostObject.transform.Find(
            "StartupPrivacyWelcomeOverlay");
        Assert.That(overlay, Is.Not.Null);
        Image backdrop = overlay.GetComponent<Image>();
        Assert.That(backdrop, Is.Not.Null);
        Assert.That(backdrop.raycastTarget, Is.True);
        Assert.That(overlay.GetComponent<GraphicRaycaster>(), Is.Not.Null);
        Assert.That(
            backdrop.rectTransform.anchorMin,
            Is.EqualTo(Vector2.zero));
        Assert.That(
            backdrop.rectTransform.anchorMax,
            Is.EqualTo(Vector2.one));
        Assert.That(overlay.GetComponent<Button>(), Is.Null);

        Invoke("ShowPrivacy");
        Assert.That(
            Find("PrivacyScreen").Find("AllowAnalyticsButton"),
            Is.Not.Null);
        Assert.That(
            Find("PrivacyScreen").Find("DeclineAnalyticsButton"),
            Is.Not.Null);
        Assert.That(Find("PrivacyScreen").Find("Dismiss"), Is.Null);
        Assert.That(Find("PrivacyScreen").Find("Close"), Is.Null);
        Assert.That(
            Find("PrivacyScreen/PrivacyInformation").GetComponent<Graphic>()
                .raycastTarget,
            Is.False);
    }

    [Test]
    public void LayoutUsesSafeAreaAndKeepsPortraitContentWithinCard()
    {
        Assert.That(
            hostObject.transform
                .Find("StartupPrivacyWelcomeOverlay/SafeArea")
                .GetComponent("SafeAreaFitter"),
            Is.Not.Null);
        RectTransform card =
            Find("PrivacyScreen").GetComponent<RectTransform>();
        Assert.That(card.anchorMin.x, Is.GreaterThanOrEqualTo(0.06f));
        Assert.That(card.anchorMax.x, Is.LessThanOrEqualTo(0.94f));
        Assert.That(card.anchorMin.y, Is.GreaterThanOrEqualTo(0.06f));
        Assert.That(card.anchorMax.y, Is.LessThanOrEqualTo(0.94f));
        Assert.That(
            GetText("PrivacyScreen/PrivacyInformation"),
            Does.Contain("Advertising is not currently active"));
        Assert.That(
            Find("PrivacyScreen/PrivacyPolicyButton").GetComponent<Button>(),
            Is.Not.Null);
    }

    [Test]
    public void RepeatedShowHideDoesNotDuplicateButtonCallbacks()
    {
        int guestRequests = 0;
        Subscribe("GuestPlayRequested", () => guestRequests++);

        for (int attempt = 0; attempt < 3; attempt++)
        {
            Assert.That((bool)Invoke("ShowWelcome"), Is.True);
            Click("WelcomeScreen/GuestPlayButton");
            Invoke("Hide");
            Assert.That((bool)Invoke("ShowPrivacy"), Is.True);
            Invoke("Hide");
        }

        Assert.That(guestRequests, Is.EqualTo(3));
    }

    [Test]
    public void DestroyingControllerClearsExternalEventSubscriptions()
    {
        Subscribe("GuestPlayRequested", () => { });
        Assert.That(
            controllerType.GetField(
                "GuestPlayRequested",
                BindingFlags.Instance | BindingFlags.NonPublic)
                .GetValue(controller),
            Is.Not.Null);

        MethodInfo onDestroy = controllerType.GetMethod(
            "OnDestroy",
            BindingFlags.Instance | BindingFlags.NonPublic);
        Assert.That(onDestroy, Is.Not.Null);
        onDestroy.Invoke(controller, null);
        UnityEngine.Object.DestroyImmediate(hostObject);
        hostObject = null;

        Assert.That(
            controllerType.GetField(
                "GuestPlayRequested",
                BindingFlags.Instance | BindingFlags.NonPublic)
                .GetValue(controller),
            Is.Null);
    }

    private Transform Find(string relativePath)
    {
        Transform transform = hostObject.transform.Find(
            "StartupPrivacyWelcomeOverlay/SafeArea/" + relativePath);
        Assert.That(transform, Is.Not.Null, relativePath);
        return transform;
    }

    private void Click(string relativePath)
    {
        Button button = Find(relativePath).GetComponent<Button>();
        Assert.That(button, Is.Not.Null, relativePath);
        button.onClick.Invoke();
    }

    private string GetText(string relativePath)
    {
        Component text = Find(relativePath).GetComponent(
            FindRuntimeType("TMPro.TextMeshProUGUI"));
        Assert.That(text, Is.Not.Null, relativePath);
        return (string)text.GetType().GetProperty("text").GetValue(text);
    }

    private object Invoke(string methodName, params object[] arguments)
    {
        MethodInfo method = controllerType.GetMethod(
            methodName,
            PublicInstance);
        Assert.That(method, Is.Not.Null, methodName);
        return method.Invoke(controller, arguments);
    }

    private void Subscribe(string eventName, Action callback)
    {
        EventInfo eventInfo = controllerType.GetEvent(eventName);
        Assert.That(eventInfo, Is.Not.Null, eventName);
        eventInfo.AddEventHandler(controller, callback);
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
