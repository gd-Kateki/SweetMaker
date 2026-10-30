using System;
using System.Collections.Generic;
using System.Reflection;
using NUnit.Framework;
using UnityEngine;
using UnityEditor;
using UnityEngine.TestTools;

public class CafeProgressionHudUITests
{
    private readonly List<GameObject> createdObjects =
        new List<GameObject>();

    [TearDown]
    public void TearDown()
    {
        for (int i = createdObjects.Count - 1; i >= 0; i--)
        {
            GameObject createdObject = createdObjects[i];
            if (createdObject != null)
            {
                Component hud = createdObject.GetComponent(
                    FindType("CafeProgressionHudUI"));
                if (hud != null)
                    InvokeLifecycle(hud, "OnDisable");
                UnityEngine.Object.DestroyImmediate(createdObject);
            }
        }

        createdObjects.Clear();
        ClearInstance();
    }

    [Test]
    public void InitialTitleAndStarRenderingUsesProgressionApis()
    {
        object progression = CreateProgression(3);
        object hud = CreateHud(progression);

        InvokeRefresh(hud);

        Assert.AreEqual("Rising Cafe", GetText(hud, "titleText"));
        Assert.AreEqual("2/5", GetText(hud, "starText"));
    }

    [Test]
    public void ProgressionEventRefreshesTitleAndStars()
    {
        object progression = CreateProgression(0);
        object hud = CreateHud(progression);
        Assert.AreEqual("Humble Beginnings", GetText(hud, "titleText"));
        Assert.AreEqual("1/5", GetText(hud, "starText"));

        Assert.IsTrue(RestoreRebirthProgression(
            progression,
            5,
            0,
            false));

        Assert.AreEqual("Established Cafe", GetText(hud, "titleText"));
        Assert.AreEqual("3/5", GetText(hud, "starText"));
    }

    [Test]
    public void SaveRestorationRefreshesDisplayedValues()
    {
        object progression = CreateProgression(0);
        object hud = CreateHud(progression);
        Assert.AreEqual("Humble Beginnings", GetText(hud, "titleText"));
        Assert.AreEqual("1/5", GetText(hud, "starText"));

        Assert.IsTrue(RestoreRebirthProgression(
            progression,
            7,
            0,
            false));

        Assert.AreEqual("Renowned Cafe", GetText(hud, "titleText"));
        Assert.AreEqual("4/5", GetText(hud, "starText"));
    }

    [Test]
    public void MissingProgressionClearsDisplaySafely()
    {
        LogAssert.Expect(LogType.Error,
            "CafeProgressionHudUI: PlayerProgressionManager is unavailable.");
        object hud = CreateHud(null);

        InvokeRefresh(hud);

        Assert.AreEqual(string.Empty, GetText(hud, "titleText"));
        Assert.AreEqual(string.Empty, GetText(hud, "starText"));
    }

    [Test]
    public void DisabledHudUnsubscribesFromProgressionChanges()
    {
        object progression = CreateProgression(0);
        object hud = CreateHud(progression);
        GameObject hudObject = HudObject(hud);

        hudObject.SetActive(false);
        InvokeLifecycle(hud, "OnDisable");
        Assert.IsTrue(RestoreRebirthProgression(
            progression,
            3,
            0,
            false));

        Assert.AreEqual("Humble Beginnings", GetText(hud, "titleText"));
        Assert.AreEqual("1/5", GetText(hud, "starText"));

        hudObject.SetActive(true);
        InvokeLifecycle(hud, "OnEnable");
        Assert.AreEqual("Rising Cafe", GetText(hud, "titleText"));
        Assert.AreEqual("2/5", GetText(hud, "starText"));
    }

    private object CreateProgression(int rebirthCount)
    {
        Type progressionType = FindType(
            "PlayerProgressionManager");
        Type rebirthStateType = FindType(
            "RebirthProgressionState");

        GameObject managerObject = new GameObject(
            "Cafe HUD progression test");
        createdObjects.Add(managerObject);
        object progression = managerObject.AddComponent(
            progressionType);

        object rebirthState = Activator.CreateInstance(
            rebirthStateType,
            new object[] { rebirthCount, 0 });
        SetPrivateField(
            progression,
            "rebirthProgression",
            rebirthState);

        ScriptableObject ovenDefinition =
            AssetDatabase.LoadAssetAtPath<ScriptableObject>(
                "Assets/_Game/Data/Upgrades/Upgrade_Oven.asset");
        Assert.IsNotNull(
            ovenDefinition,
            "Oven upgrade definition must exist.");
        SetPrivateField(
            progression,
            "ovenUpgrade",
            ovenDefinition);

        return progression;
    }

    private object CreateHud(object progression)
    {
        Type hudType = FindType("CafeProgressionHudUI");
        Type tmpTextType = FindType("TMPro.TextMeshProUGUI");

        GameObject hudObject = new GameObject(
            "Cafe progression HUD test",
            typeof(RectTransform));
        hudObject.SetActive(false);
        createdObjects.Add(hudObject);
        object hud = hudObject.AddComponent(hudType);

        GameObject titleObject = new GameObject(
            "Title",
            typeof(RectTransform));
        titleObject.transform.SetParent(hudObject.transform, false);
        Component title = titleObject.AddComponent(
            tmpTextType);

        GameObject starObject = new GameObject(
            "Stars",
            typeof(RectTransform));
        starObject.transform.SetParent(hudObject.transform, false);
        Component stars = starObject.AddComponent(
            tmpTextType);

        SetPrivateField(hud, "progressionManager", progression);
        SetPrivateField(hud, "titleText", title);
        SetPrivateField(hud, "starText", stars);
        hudObject.SetActive(true);
        // EditMode does not dispatch lifecycle callbacks for this runtime
        // MonoBehaviour. Exercise the same subscription path as Play Mode.
        InvokeLifecycle(hud, "OnEnable");
        return hud;
    }

    private static void InvokeLifecycle(object target, string methodName)
    {
        MethodInfo method = target.GetType().GetMethod(
            methodName,
            BindingFlags.Instance | BindingFlags.NonPublic);
        Assert.IsNotNull(method, "Expected lifecycle callback: " + methodName);
        method.Invoke(target, null);
    }

    private static bool RestoreRebirthProgression(
        object progression,
        int rebirthCount,
        int highestTier,
        bool campaignComplete)
    {
        MethodInfo method = progression.GetType().GetMethod(
            "RestoreRebirthProgression",
            BindingFlags.Instance | BindingFlags.Public);
        return (bool)method.Invoke(
            progression,
            new object[]
            {
                rebirthCount,
                highestTier,
                campaignComplete
            });
    }

    private static void InvokeRefresh(object hud)
    {
        MethodInfo method = hud.GetType().GetMethod(
            "Refresh",
            BindingFlags.Instance | BindingFlags.Public);
        method.Invoke(hud, null);
    }

    private static string GetText(object hud, string fieldName)
    {
        object textComponent = GetPrivateField(hud, fieldName);
        PropertyInfo textProperty = textComponent.GetType().GetProperty(
            "text",
            BindingFlags.Instance | BindingFlags.Public);
        return (string)textProperty.GetValue(textComponent);
    }

    private static GameObject HudObject(object hud)
    {
        PropertyInfo gameObjectProperty = hud.GetType().GetProperty(
            "gameObject",
            BindingFlags.Instance | BindingFlags.Public);
        return (GameObject)gameObjectProperty.GetValue(hud);
    }

    private static object GetPrivateField(
        object target,
        string fieldName)
    {
        FieldInfo field = target.GetType().GetField(
            fieldName,
            BindingFlags.Instance | BindingFlags.NonPublic);
        return field.GetValue(target);
    }

    private static void SetPrivateField(
        object target,
        string fieldName,
        object value)
    {
        FieldInfo field = target.GetType().GetField(
            fieldName,
            BindingFlags.Instance | BindingFlags.NonPublic);
        Assert.IsNotNull(field, "Expected field: " + fieldName);
        field.SetValue(target, value);
    }

    private static void ClearInstance()
    {
        Type progressionType = FindType(
            "PlayerProgressionManager");
        FieldInfo backingField =
            progressionType.GetField(
                "<Instance>k__BackingField",
                BindingFlags.Static | BindingFlags.NonPublic);
        Assert.IsNotNull(
            backingField,
            "PlayerProgressionManager.Instance backing field must exist.");
        backingField.SetValue(null, null);
    }

    private static Type FindType(string typeName)
    {
        foreach (Assembly assembly in AppDomain.CurrentDomain.GetAssemblies())
        {
            Type type = assembly.GetType(typeName);
            if (type != null)
                return type;
        }

        Assert.Fail("Could not find type: " + typeName);
        return null;
    }
}
