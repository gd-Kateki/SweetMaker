using System;
using System.Linq.Expressions;
using System.Reflection;
using NUnit.Framework;
using UnityEngine;
using UnityEngine.UI;

public sealed class FeatureIntroductionPopupTests
{
    private GameObject canvasObject;
    private GameObject hostObject;
    private Behaviour popup;
    private Type popupType;
    private Type featureType;
    private Type tmpTextType;

    [SetUp]
    public void SetUp()
    {
        popupType = FindRuntimeType("FeatureIntroductionPopup");
        featureType = FindRuntimeType("FeatureIntroduction");
        tmpTextType = FindRuntimeType("TMPro.TextMeshProUGUI");
        Assert.That(popupType, Is.Not.Null);
        Assert.That(featureType, Is.Not.Null);
        Assert.That(tmpTextType, Is.Not.Null);

        canvasObject = new GameObject(
            "TestCanvas",
            typeof(RectTransform),
            typeof(Canvas),
            typeof(GraphicRaycaster));
        canvasObject.GetComponent<Canvas>().renderMode = RenderMode.ScreenSpaceOverlay;

        hostObject = new GameObject("TestPopupHost", typeof(RectTransform));
        hostObject.transform.SetParent(canvasObject.transform, false);
        popup = hostObject.AddComponent(popupType) as Behaviour;
        Assert.That(popup, Is.Not.Null);

        MethodInfo awake = popupType.GetMethod(
            "Awake",
            BindingFlags.Instance | BindingFlags.NonPublic);
        Assert.That(awake, Is.Not.Null);
        awake.Invoke(popup, null);
    }

    [TearDown]
    public void TearDown()
    {
        if (canvasObject != null)
            UnityEngine.Object.DestroyImmediate(canvasObject);
    }

    [Test]
    public void PopupIsHiddenByDefaultAndUsesFullScreenInputBlocker()
    {
        Assert.That(GetProperty(popup, "IsDisplayed"), Is.False);

        Transform popupRoot = hostObject.transform.Find("FeatureIntroductionPopup");
        Assert.That(popupRoot, Is.Not.Null);
        Assert.That(popupRoot.gameObject.activeSelf, Is.False);

        Image blocker = popupRoot.GetComponent<Image>();
        Assert.That(blocker, Is.Not.Null);
        Assert.That(blocker.raycastTarget, Is.True);

        RectTransform blockerRect = blocker.rectTransform;
        Assert.That(blockerRect.anchorMin, Is.EqualTo(Vector2.zero));
        Assert.That(blockerRect.anchorMax, Is.EqualTo(Vector2.one));
        Assert.That(popupRoot.GetComponent<GraphicRaycaster>(), Is.Not.Null);
    }

    [TestCase("Upgrades", "Grow Your Café!", "Spend cash to improve your café! Expand your board, serve more customers, increase your earnings, and unlock other improvements. Some upgrades require Rebirths, while higher Oven levels are earned through Rebirth progression.")]
    [TestCase("Rebirth", "A Fresh Start!", "Reach the required dessert tier during your current run and collect enough cash to Rebirth. Rebirth resets your cash, board, shelf, orders and current run, but keeps your non-Oven upgrades and Dessert Collection progress. Every second Rebirth increases your Oven level!")]
    [TestCase("Collection", "Discover Them All!", "Discover new dessert tiers by spawning and merging desserts. Find all 30 tiers and claim cash rewards at 6, 12, 18, 24 and 30 discoveries!")]
    public void ConfigureUsesApprovedFeatureContent(
        string feature,
        string expectedTitle,
        string expectedBody)
    {
        Configure(feature);

        Transform popupRoot = hostObject.transform.Find("FeatureIntroductionPopup");
        Assert.That(GetText(popupRoot.Find(
            "SafeArea/FeatureIntroductionCard/Title")), Is.EqualTo(expectedTitle));
        Transform bodyTransform = popupRoot.Find(
            "SafeArea/FeatureIntroductionCard/Body");
        Assert.That(GetText(bodyTransform), Is.EqualTo(expectedBody));
        Assert.That(
            GetProperty(bodyTransform.GetComponent(tmpTextType), "textWrappingMode")
                .ToString(),
            Is.EqualTo("Normal"));
        Assert.That(
            GetProperty(bodyTransform.GetComponent(tmpTextType), "enableAutoSizing"),
            Is.True);
    }

    [Test]
    public void GotItFiresOnlyTheGotItEventAndDismissesPopup()
    {
        int displayedCount = 0;
        int gotItCount = 0;
        int dismissedCount = 0;
        Subscribe(popup, "PopupDisplayed", _ => displayedCount++);
        Subscribe(popup, "GotItPressed", feature =>
        {
            Assert.That(feature.ToString(), Is.EqualTo("Rebirth"));
            gotItCount++;
        });
        Subscribe(popup, "DismissedWithoutAcknowledgement", _ => dismissedCount++);

        Configure("Rebirth");
        Assert.That(Invoke(popup, "Show"), Is.True);
        Assert.That(GetProperty(popup, "IsDisplayed"), Is.True);
        hostObject.transform
            .Find("FeatureIntroductionPopup/SafeArea/FeatureIntroductionCard/GotItButton")
            .GetComponent<Button>().onClick.Invoke();

        Assert.That(displayedCount, Is.EqualTo(1));
        Assert.That(gotItCount, Is.EqualTo(1));
        Assert.That(dismissedCount, Is.Zero);
        Assert.That(GetProperty(popup, "IsDisplayed"), Is.False);
    }

    [Test]
    public void ExplicitDismissalIsDistinguishedFromGotIt()
    {
        int gotItCount = 0;
        int dismissedCount = 0;
        int persistenceAttempts = 0;
        SetAcknowledgementCommit(_ =>
        {
            persistenceAttempts++;
            return true;
        });
        Subscribe(popup, "GotItPressed", _ => gotItCount++);
        Subscribe(popup, "DismissedWithoutAcknowledgement", feature =>
        {
            Assert.That(feature.ToString(), Is.EqualTo("Collection"));
            dismissedCount++;
        });

        Configure("Collection");
        Assert.That(Invoke(popup, "Show"), Is.True);
        Invoke(popup, "DismissWithoutAcknowledgement");

        Assert.That(gotItCount, Is.Zero);
        Assert.That(dismissedCount, Is.EqualTo(1));
        Assert.That(persistenceAttempts, Is.Zero);
        Assert.That(GetProperty(popup, "IsDisplayed"), Is.False);
    }

    [Test]
    public void FailedAcknowledgementKeepsPopupOpenAndCanBeRetried()
    {
        int attempts = 0;
        int gotItCount = 0;
        bool commitSucceeds = false;
        Subscribe(popup, "GotItPressed", _ => gotItCount++);
        Configure("Rebirth");
        Assert.That(Invoke(popup, "Show"), Is.True);
        SetAcknowledgementCommit(_ =>
        {
            attempts++;
            return commitSucceeds;
        });

        GetGotItButton().onClick.Invoke();

        Assert.That(attempts, Is.EqualTo(1));
        Assert.That(gotItCount, Is.Zero);
        Assert.That(GetProperty(popup, "IsDisplayed"), Is.True);

        commitSucceeds = true;
        GetGotItButton().onClick.Invoke();

        Assert.That(attempts, Is.EqualTo(2));
        Assert.That(gotItCount, Is.EqualTo(1));
        Assert.That(GetProperty(popup, "IsDisplayed"), Is.False);
    }

    [Test]
    public void ReopeningPopupDoesNotDuplicateGotItCallbacks()
    {
        int gotItCount = 0;
        Subscribe(popup, "GotItPressed", _ => gotItCount++);
        Configure("Upgrades");

        Assert.That(Invoke(popup, "Show"), Is.True);
        GetGotItButton().onClick.Invoke();
        Assert.That(Invoke(popup, "Show"), Is.True);
        GetGotItButton().onClick.Invoke();

        Assert.That(gotItCount, Is.EqualTo(2));
    }

    [Test]
    public void RebirthOpenShowsPanelWithoutStartingTransactionAndReleasesGateOnClose()
    {
        popup.enabled = false;
        int initialLeaseCount = GetModalLeaseCount();
        Type rebirthType = FindRuntimeType("RebirthUI");
        Assert.That(rebirthType, Is.Not.Null);
        GameObject rebirthObject = new GameObject(
            "RebirthTestUI",
            typeof(RectTransform));
        rebirthObject.transform.SetParent(canvasObject.transform, false);
        Behaviour rebirth = rebirthObject.AddComponent(rebirthType) as Behaviour;
        Assert.That(rebirth, Is.Not.Null);

        GameObject backdrop = new GameObject(
            "Backdrop",
            typeof(RectTransform));
        backdrop.transform.SetParent(canvasObject.transform, false);
        GameObject panel = new GameObject(
            "Panel",
            typeof(RectTransform));
        panel.transform.SetParent(canvasObject.transform, false);
        SetField(rebirth, "modalBackdrop", backdrop);
        SetField(rebirth, "modalPanel", panel);
        InvokePrivate(rebirth, "Awake");

        Invoke(rebirth, "Open");

        Assert.That(backdrop.activeSelf, Is.True);
        Assert.That(panel.activeSelf, Is.True);
        Assert.That(GetField(rebirth, "rebirthClickInProgress"), Is.False);
        Assert.That(GetModalLeaseCount(), Is.EqualTo(initialLeaseCount + 1));

        Invoke(rebirth, "Close");

        Assert.That(backdrop.activeSelf, Is.False);
        Assert.That(panel.activeSelf, Is.False);
        Assert.That(GetModalLeaseCount(), Is.EqualTo(initialLeaseCount));
    }

    [TestCase(true, true, true, true, true, true, true)]
    [TestCase(false, true, true, true, true, true, false)]
    [TestCase(true, false, true, true, true, true, false)]
    [TestCase(true, true, false, true, true, true, false)]
    [TestCase(true, true, true, false, true, true, false)]
    [TestCase(true, true, true, true, false, true, false)]
    [TestCase(true, true, true, true, true, false, false)]
    public void EligibilityRequiresEveryReadinessCondition(
        bool tutorialCompleted,
        bool applicationReady,
        bool saveReady,
        bool selectedSnapshotValid,
        bool featureUnseen,
        bool noIncompatibleModal,
        bool expected)
    {
        MethodInfo method = popupType.GetMethod(
            "AreEligibilityConditionsMet",
            BindingFlags.Static | BindingFlags.NonPublic);
        Assert.That(method, Is.Not.Null);
        bool result = (bool)method.Invoke(
            null,
            new object[]
            {
                tutorialCompleted,
                applicationReady,
                saveReady,
                selectedSnapshotValid,
                featureUnseen,
                noIncompatibleModal
            });

        Assert.That(result, Is.EqualTo(expected));
    }

    [TestCase("Upgrades", "Game", true)]
    [TestCase("Rebirth", "Game", true)]
    [TestCase("Collection", "MainBakery", true)]
    [TestCase("Collection", "Game", true)]
    [TestCase("Upgrades", "MainBakery", false)]
    [TestCase("Rebirth", "MainBakery", false)]
    public void FeatureIsOnlyEligibleInSupportedScenes(
        string feature,
        string scene,
        bool expected)
    {
        MethodInfo method = popupType.GetMethod(
            "IsSupportedFeatureScene",
            BindingFlags.Static | BindingFlags.NonPublic);
        Assert.That(method, Is.Not.Null);
        bool result = (bool)method.Invoke(
            null,
            new[] { Enum.Parse(featureType, feature), scene });

        Assert.That(result, Is.EqualTo(expected));
    }

    [TestCase("Collection", "Game", true)]
    [TestCase("Collection", "MainBakery", false)]
    [TestCase("Upgrades", "Game", false)]
    [TestCase("Rebirth", "Game", false)]
    public void GameplayModalLeaseIsOnlyRequiredForGameCollection(
        string feature,
        string scene,
        bool expected)
    {
        MethodInfo method = popupType.GetMethod(
            "RequiresGameplayModalLease",
            BindingFlags.Static | BindingFlags.NonPublic,
            null,
            new[] { featureType, typeof(string) },
            null);
        Assert.That(method, Is.Not.Null);
        bool result = (bool)method.Invoke(
            null,
            new[] { Enum.Parse(featureType, feature), scene });

        Assert.That(result, Is.EqualTo(expected));
    }

    [TestCase(0.5625f, 1f)]
    [TestCase(0.75f, 1f)]
    [TestCase(0.4615f, 1f)]
    public void CardStaysInsideSafeAreaForPortraitCanvasRatios(
        float canvasWidth,
        float canvasHeight)
    {
        RectTransform canvasRect = canvasObject.GetComponent<RectTransform>();
        canvasRect.sizeDelta = new Vector2(canvasWidth * 1000f, canvasHeight * 1000f);
        Configure("Rebirth");

        RectTransform panel = hostObject.transform
            .Find("FeatureIntroductionPopup/SafeArea/FeatureIntroductionCard")
            .GetComponent<RectTransform>();
        Assert.That(panel.anchorMin.x, Is.GreaterThanOrEqualTo(0f));
        Assert.That(panel.anchorMax.x, Is.LessThanOrEqualTo(1f));
        Assert.That(panel.anchorMin.y, Is.GreaterThanOrEqualTo(0f));
        Assert.That(panel.anchorMax.y, Is.LessThanOrEqualTo(1f));
        Assert.That(panel.anchorMax.x - panel.anchorMin.x, Is.GreaterThan(0.8f));

        Component body = panel.Find("Body").GetComponent(tmpTextType);
        Assert.That((float)GetProperty(body, "fontSizeMin"), Is.GreaterThanOrEqualTo(15f));
        Assert.That(
            GetProperty(body, "textWrappingMode").ToString(),
            Is.EqualTo("Normal"));
    }

    private void Configure(string feature)
    {
        object featureValue = Enum.Parse(featureType, feature);
        popupType.GetMethod("Configure").Invoke(popup, new[] { featureValue });
    }

    private Button GetGotItButton()
    {
        return hostObject.transform
            .Find("FeatureIntroductionPopup/SafeArea/FeatureIntroductionCard/GotItButton")
            .GetComponent<Button>();
    }

    private void SetAcknowledgementCommit(Func<object, bool> callback)
    {
        Type commitType = typeof(Func<,>).MakeGenericType(
            featureType,
            typeof(bool));
        ParameterExpression featureParameter = Expression.Parameter(featureType);
        MethodCallExpression callbackCall = Expression.Call(
            Expression.Constant(callback),
            typeof(Func<object, bool>).GetMethod("Invoke"),
            Expression.Convert(featureParameter, typeof(object)));
        Delegate commit = Expression.Lambda(
            commitType,
            callbackCall,
            featureParameter).Compile();
        FieldInfo field = popupType.GetField(
            "acknowledgementCommit",
            BindingFlags.Instance | BindingFlags.NonPublic);
        Assert.That(field, Is.Not.Null);
        field.SetValue(popup, commit);
    }

    private static Type FindRuntimeType(string typeName)
    {
        foreach (Assembly assembly in AppDomain.CurrentDomain.GetAssemblies())
        {
            Type found = assembly.GetType(typeName, false);
            if (found != null)
                return found;
        }

        return null;
    }

    private static object Invoke(Component target, string methodName)
    {
        return target.GetType().GetMethod(methodName).Invoke(target, null);
    }

    private static void InvokePrivate(Component target, string methodName)
    {
        MethodInfo method = target.GetType().GetMethod(
            methodName,
            BindingFlags.Instance | BindingFlags.NonPublic);
        Assert.That(method, Is.Not.Null);
        method.Invoke(target, null);
    }

    private static int GetModalLeaseCount()
    {
        Type gateType = FindRuntimeType("GameplayModalInputGate");
        Assert.That(gateType, Is.Not.Null);
        FieldInfo leases = gateType.GetField(
            "ModalLeases",
            BindingFlags.Static | BindingFlags.NonPublic);
        Assert.That(leases, Is.Not.Null);
        return (int)leases.FieldType.GetProperty("Count").GetValue(
            leases.GetValue(null),
            null);
    }

    private static object GetField(Component target, string fieldName)
    {
        FieldInfo field = target.GetType().GetField(
            fieldName,
            BindingFlags.Instance | BindingFlags.NonPublic);
        Assert.That(field, Is.Not.Null);
        return field.GetValue(target);
    }

    private static void SetField(
        Component target,
        string fieldName,
        object value)
    {
        FieldInfo field = target.GetType().GetField(
            fieldName,
            BindingFlags.Instance | BindingFlags.NonPublic);
        Assert.That(field, Is.Not.Null);
        field.SetValue(target, value);
    }

    private static object GetProperty(object target, string propertyName)
    {
        return target.GetType().GetProperty(propertyName).GetValue(target, null);
    }

    private string GetText(Transform textTransform)
    {
        return (string)GetProperty(
            textTransform.GetComponent(tmpTextType),
            "text");
    }

    private static void Subscribe(
        Component source,
        string eventName,
        Action<object> callback)
    {
        EventInfo eventInfo = source.GetType().GetEvent(eventName);
        ParameterExpression featureParameter = Expression.Parameter(
            eventInfo.EventHandlerType.GetMethod("Invoke")
                .GetParameters()[0].ParameterType);
        MethodCallExpression callbackCall = Expression.Call(
            Expression.Constant(callback),
            typeof(Action<object>).GetMethod("Invoke"),
            Expression.Convert(featureParameter, typeof(object)));
        Delegate handler = Expression.Lambda(
            eventInfo.EventHandlerType,
            callbackCall,
            featureParameter).Compile();
        eventInfo.AddEventHandler(source, handler);
    }
}
