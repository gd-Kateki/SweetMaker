using System;
using System.Collections;
using System.Reflection;
using NUnit.Framework;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.TestTools;

public sealed class HybridTutorialHighlightInitializationPlayModeTests
{
    private Scene originalScene;
    private Scene testScene;

    [UnityTest]
    public IEnumerator InitializerCreatesRectTransformHostBeforeAwake()
    {
        originalScene = SceneManager.GetActiveScene();
        testScene = SceneManager.CreateScene("Game");

        GameObject canvasObject = new GameObject(
            "GameplayCanvas",
            typeof(RectTransform),
            typeof(Canvas));
        SceneManager.MoveGameObjectToScene(canvasObject, testScene);
        canvasObject.GetComponent<Canvas>().renderMode =
            RenderMode.ScreenSpaceOverlay;
        Assert.IsTrue(SceneManager.SetActiveScene(testScene));

        Type highlightType = FindRuntimeType(
            "SweetMerge.Profile.HybridTutorialHighlightUI");
        MethodInfo createForGame = highlightType.GetMethod(
            "CreateForGame",
            BindingFlags.NonPublic | BindingFlags.Static);
        Assert.IsNotNull(createForGame);

        createForGame.Invoke(null, null);

        Transform host = canvasObject.transform.Find(
            "HybridTutorialHighlightUI");
        Assert.IsNotNull(host);
        RectTransform hostRect = host.GetComponent<RectTransform>();
        Assert.IsNotNull(hostRect);
        Assert.IsNotNull(host.GetComponent(highlightType));
        Assert.AreEqual(Vector2.zero, hostRect.anchorMin);
        Assert.AreEqual(Vector2.one, hostRect.anchorMax);
        Assert.AreEqual(Vector2.zero, hostRect.offsetMin);
        Assert.AreEqual(Vector2.zero, hostRect.offsetMax);
        Assert.AreEqual(1, host.childCount);
        Assert.AreEqual(4, host.GetChild(0).childCount);

        yield return null;
    }

    [UnityTest]
    public IEnumerator TargetResolutionReusesAndReplacesCachedTarget()
    {
        originalScene = SceneManager.GetActiveScene();
        testScene = SceneManager.CreateScene("Game");
        Assert.IsTrue(SceneManager.SetActiveScene(testScene));

        Type highlightType = FindRuntimeType(
            "SweetMerge.Profile.HybridTutorialHighlightUI");
        Type stageType = FindRuntimeType(
            "SweetMerge.Profile.TutorialStage");
        GameObject canvasObject = new GameObject(
            "GameplayCanvas",
            typeof(RectTransform),
            typeof(Canvas));
        canvasObject.GetComponent<Canvas>().renderMode =
            RenderMode.ScreenSpaceOverlay;
        GameObject host = new GameObject(
            "HighlightHost",
            typeof(RectTransform));
        host.transform.SetParent(canvasObject.transform, false);
        host.AddComponent(highlightType);

        GameObject firstOven = CreateOven();
        object stage = System.Enum.Parse(stageType, "Spawn");
        MethodInfo resolveTarget = highlightType.GetMethod(
            "TryResolveTarget",
            BindingFlags.NonPublic | BindingFlags.Instance);
        Assert.IsNotNull(resolveTarget);

        object[] arguments = { stage, null };
        Assert.IsTrue((bool)resolveTarget.Invoke(host.GetComponent(
            highlightType), arguments));
        Assert.AreSame(firstOven.transform, arguments[1]);

        firstOven.name = "RenamedOven";
        arguments = new object[] { stage, null };
        Assert.IsTrue((bool)resolveTarget.Invoke(host.GetComponent(
            highlightType), arguments));
        Assert.AreSame(firstOven.transform, arguments[1]);
        firstOven.name = "Oven";

        GameObject replacementOven = CreateOven();
        UnityEngine.Object.Destroy(firstOven);
        yield return null;

        arguments = new object[] { stage, null };
        Assert.IsTrue((bool)resolveTarget.Invoke(host.GetComponent(
            highlightType), arguments));
        Assert.AreSame(replacementOven.transform, arguments[1]);
    }

    [UnityTearDown]
    public IEnumerator RestoreScene()
    {
        if (originalScene.IsValid() && originalScene.isLoaded)
            SceneManager.SetActiveScene(originalScene);

        if (testScene.IsValid() && testScene.isLoaded)
            yield return SceneManager.UnloadSceneAsync(testScene);
    }

    private static Type FindRuntimeType(string typeName)
    {
        Type type = Type.GetType($"{typeName}, Assembly-CSharp");
        Assert.IsNotNull(type, $"Required runtime type '{typeName}' was not found.");
        return type;
    }

    private static GameObject CreateOven()
    {
        GameObject oven = new GameObject("Oven");
        Type ovenControllerType = FindRuntimeType("OvenController");
        oven.AddComponent(ovenControllerType);
        return oven;
    }
}
