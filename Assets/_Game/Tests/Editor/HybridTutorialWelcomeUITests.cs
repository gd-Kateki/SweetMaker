using System;
using System.Reflection;
using NUnit.Framework;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public sealed class HybridTutorialWelcomeUITests
{
    private const BindingFlags StaticNonPublic =
        BindingFlags.Static | BindingFlags.NonPublic;
    private const BindingFlags InstanceNonPublic =
        BindingFlags.Instance | BindingFlags.NonPublic;
    private const string MainBakeryScenePath =
        "Assets/_Game/Scenes/MainBakery.unity";

    private Scene originalScene;
    private Scene testScene;
    private GameObject canvasObject;
    private GameObject controllerObject;
    private Type welcomeUiType;
    private Type controllerType;
    private object controller;
    private object previousController;
    private Sprite previousUiSprite;
    private bool previousControllerCaptured;

    [SetUp]
    public void SetUp()
    {
        welcomeUiType = FindRuntimeType(
            "SweetMerge.Profile.HybridTutorialWelcomeUI");
        FieldInfo uiSpriteField = welcomeUiType.GetField(
            "uiSprite",
            StaticNonPublic);
        previousUiSprite = (Sprite)uiSpriteField.GetValue(null);
        InvokeStatic(welcomeUiType, "ResetSceneLoadedHandler");

        originalScene = SceneManager.GetActiveScene();
        testScene = EditorSceneManager.OpenScene(
            MainBakeryScenePath,
            OpenSceneMode.Additive);
        Assert.That(testScene.IsValid() && testScene.isLoaded, Is.True);
        Assert.That(testScene.handle, Is.Not.EqualTo(originalScene.handle));
        Assert.That(SceneManager.SetActiveScene(testScene), Is.True);

        canvasObject = FindMainCanvas(testScene);
        Assert.That(canvasObject, Is.Not.Null);

        controllerType = FindRuntimeType(
            "SweetMerge.Profile.HybridTutorialController");
        previousController = controllerType.GetProperty(
                "Instance",
                BindingFlags.Public | BindingFlags.Static)
            .GetValue(null);
        previousControllerCaptured = true;

        controllerObject = new GameObject("TutorialControllerTestOwner");
        SceneManager.MoveGameObjectToScene(controllerObject, testScene);
        controller = controllerObject.AddComponent(controllerType);
        controllerType.GetProperty(
                "Instance",
                BindingFlags.Public | BindingFlags.Static)
            .GetSetMethod(true)
            .Invoke(null, new[] { controller });
    }

    [TearDown]
    public void TearDown()
    {
        if (welcomeUiType != null)
            InvokeStatic(welcomeUiType, "ResetSceneLoadedHandler");

        if (controllerType != null && previousControllerCaptured)
        {
            controllerType.GetProperty(
                    "Instance",
                    BindingFlags.Public | BindingFlags.Static)
                .GetSetMethod(true)
                .Invoke(null, new[] { previousController });
        }

        if (controllerObject != null)
            UnityEngine.Object.DestroyImmediate(controllerObject);

        if (originalScene.IsValid() && originalScene.isLoaded)
            SceneManager.SetActiveScene(originalScene);

        if (testScene.IsValid() &&
            testScene.isLoaded &&
            testScene.handle != originalScene.handle)
            EditorSceneManager.CloseScene(testScene, true);

        if (welcomeUiType != null)
        {
            FieldInfo uiSpriteField = welcomeUiType.GetField(
                "uiSprite",
                StaticNonPublic);
            Sprite currentUiSprite = (Sprite)uiSpriteField.GetValue(null);
            if (currentUiSprite != null &&
                currentUiSprite != previousUiSprite)
                UnityEngine.Object.DestroyImmediate(currentUiSprite);
            uiSpriteField.SetValue(null, previousUiSprite);
        }
    }

    [Test]
    public void MainBakerySceneLoadCreatesTutorialWelcomeUi()
    {
        InvokeStatic(
            welcomeUiType,
            "HandleSceneLoaded",
            testScene,
            LoadSceneMode.Single);

        Assert.That(GetWelcomeUi(), Is.Not.Null);
        Assert.That(GetPanel(), Is.Not.Null);
    }

    [Test]
    public void RegistersSceneLoadListenerForLaterMainBakeryActivation()
    {
        InvokeStatic(welcomeUiType, "RegisterSceneLoadedHandler");

        Assert.That(
            welcomeUiType.GetField(
                    "isListeningForSceneLoads",
                    StaticNonPublic)
                .GetValue(null),
            Is.True);
        Assert.That(GetWelcomeUi(), Is.Not.Null);
    }

    [Test]
    public void NewPlayerSeesWelcomeAfterProgressBecomesReady()
    {
        SetTutorialState("Welcome", ready: true);
        CreateWelcomeUi();
        Assert.That(GetPanel().activeSelf, Is.True);
    }

    [Test]
    public void WelcomeUiRefreshesAfterTutorialInitialization()
    {
        SetTutorialState("Welcome", ready: false);
        CreateWelcomeUi();
        Assert.That(GetPanel().activeSelf, Is.False);

        SetTutorialState("Welcome", ready: true);
        Invoke(controller, "SetLocalReady", true);

        Assert.That(GetPanel().activeSelf, Is.True);
    }

    [Test]
    public void CompletedTutorialDoesNotReplay()
    {
        SetTutorialState("Completed", ready: true);
        CreateWelcomeUi();

        Assert.That(GetPanel().activeSelf, Is.False);
    }

    [Test]
    public void IncompleteTutorialKeepsItsStageForResume()
    {
        SetTutorialState("Merge", ready: true);
        CreateWelcomeUi();

        Assert.That(GetPanel().activeSelf, Is.False);
        Assert.That(GetTutorialStage(), Is.EqualTo("Merge"));
    }

    [Test]
    public void LoadingHandoffDoesNotChangeTutorialProgress()
    {
        SetTutorialState("Welcome", ready: true);
        Type policy = FindRuntimeType(
            "SweetMerge.Startup.LoadingPresenterPolicy");
        MethodInfo canDismiss = policy.GetMethod(
            "CanDismiss",
            StaticNonPublic);
        Assert.That(canDismiss, Is.Not.Null);

        Assert.That(
            canDismiss.Invoke(
                null,
                new object[] { true, true, true, false, false }),
            Is.True);
        Assert.That(GetTutorialStage(), Is.EqualTo("Welcome"));
    }

    [Test]
    public void ReopeningMainBakeryDoesNotCreateDuplicateWelcomeUi()
    {
        InvokeStatic(
            welcomeUiType,
            "HandleSceneLoaded",
            testScene,
            LoadSceneMode.Single);
        InvokeStatic(
            welcomeUiType,
            "HandleSceneLoaded",
            testScene,
            LoadSceneMode.Single);

        Assert.That(
            canvasObject.GetComponentsInChildren(
                welcomeUiType,
                true).Length,
            Is.EqualTo(1));
    }

    private void CreateWelcomeUi()
    {
        InvokeStatic(
            welcomeUiType,
            "HandleSceneLoaded",
            testScene,
            LoadSceneMode.Single);
        EnsureUiLifecycle();
    }

    private Component GetWelcomeUi()
    {
        return canvasObject.GetComponentInChildren(welcomeUiType, true);
    }

    private static GameObject FindMainCanvas(Scene scene)
    {
        foreach (GameObject root in scene.GetRootGameObjects())
        {
            foreach (Canvas canvas in root.GetComponentsInChildren<Canvas>(true))
            {
                if (canvas.gameObject.name == "MainCanvas")
                    return canvas.gameObject;
            }
        }

        return null;
    }

    private GameObject GetPanel()
    {
        Component ui = GetWelcomeUi();
        Assert.That(ui, Is.Not.Null);
        EnsureUiLifecycle();
        return (GameObject)welcomeUiType
            .GetField("panel", InstanceNonPublic)
            .GetValue(ui);
    }

    private void EnsureUiLifecycle()
    {
        Component ui = GetWelcomeUi();
        if (ui == null)
            return;

        if (welcomeUiType.GetField("panel", InstanceNonPublic)
                .GetValue(ui) == null)
            Invoke(ui, "Awake");
        Invoke(ui, "OnEnable");
    }

    private void SetTutorialState(string stageName, bool ready)
    {
        Type stageType = FindRuntimeType(
            "SweetMerge.Profile.TutorialStage");
        Type statusType = FindRuntimeType(
            "SweetMerge.Profile.TutorialProgressStatus");
        Type stateType = FindRuntimeType(
            "SweetMerge.Profile.TutorialProgressState");
        ConstructorInfo constructor = stateType.GetConstructor(
            BindingFlags.Instance | BindingFlags.NonPublic,
            null,
            new[]
            {
                statusType,
                stageType,
                typeof(bool),
                typeof(string)
            },
            null);
        Assert.That(constructor, Is.Not.Null);

        object state = constructor.Invoke(new[]
        {
            Enum.Parse(statusType, "Valid"),
            Enum.Parse(stageType, stageName),
            (object)true,
            null
        });
        controllerType.GetField("state", InstanceNonPublic)
            .SetValue(controller, state);
        controllerType.GetField("localReady", InstanceNonPublic)
            .SetValue(controller, ready);
    }

    private string GetTutorialStage()
    {
        object state = controllerType.GetProperty("State")
            .GetValue(controller);
        return state.GetType().GetProperty("Stage")
            .GetValue(state)
            .ToString();
    }

    private static void InvokeStatic(
        Type type,
        string methodName,
        params object[] arguments)
    {
        MethodInfo method = type.GetMethod(methodName, StaticNonPublic);
        Assert.That(method, Is.Not.Null, methodName);
        method.Invoke(null, arguments);
    }

    private static void Invoke(
        object target,
        string methodName,
        params object[] arguments)
    {
        MethodInfo method = target.GetType().GetMethod(
            methodName,
            InstanceNonPublic);
        Assert.That(method, Is.Not.Null, methodName);
        method.Invoke(target, arguments);
    }

    private static Type FindRuntimeType(string typeName)
    {
        Type type = Type.GetType(typeName + ", Assembly-CSharp");
        Assert.That(type, Is.Not.Null, typeName);
        return type;
    }
}
