using System;
using System.Collections.Generic;
using System.Reflection;
using NUnit.Framework;
using UnityEngine;
using UnityEditor;
using UnityEngine.TestTools;
using UnityEngine.UI;

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
    public void InitialTitleAndFiveVisualStarPositionsUseProgressionApis()
    {
        object progression = CreateProgression(3);
        object hud = CreateHud(progression);

        InvokeRefresh(hud);

        Assert.AreEqual("Rising Cafe", GetText(hud, "titleText"));
        AssertFiveStarVisuals(hud, 2);
    }

    [Test]
    public void ProgressionEventRefreshesTitleAndVisualStars()
    {
        object progression = CreateProgression(0);
        object hud = CreateHud(progression);
        Assert.AreEqual("Humble Beginnings", GetText(hud, "titleText"));
        AssertFiveStarVisuals(hud, 1);

        Assert.IsTrue(RestoreRebirthProgression(
            progression,
            5,
            0,
            false));

        Assert.AreEqual("Established Cafe", GetText(hud, "titleText"));
        AssertFiveStarVisuals(hud, 3);
    }

    [Test]
    public void SaveRestorationRefreshesDisplayedValues()
    {
        object progression = CreateProgression(0);
        object hud = CreateHud(progression);
        Assert.AreEqual("Humble Beginnings", GetText(hud, "titleText"));
        AssertFiveStarVisuals(hud, 1);

        Assert.IsTrue(RestoreRebirthProgression(
            progression,
            7,
            0,
            false));

        LogDiagnosticState(progression, hud);
        Assert.AreEqual("Renowned Cafe", GetText(hud, "titleText"));
        AssertFiveStarVisuals(hud, 4);
    }

    [TestCase(0, "Humble Beginnings", 1)]
    [TestCase(1, "Aspiring Baker", 1)]
    [TestCase(3, "Rising Cafe", 2)]
    [TestCase(5, "Established Cafe", 3)]
    [TestCase(7, "Renowned Cafe", 4)]
    [TestCase(10, "Legendary Cafe", 5)]
    public void ExistingTitleAndStarThresholdsRenderCorrectly(
        int rebirthCount,
        string expectedTitle,
        int expectedFilledStars)
    {
        object progression = CreateProgression(0);
        object hud = CreateHud(progression);

        Assert.IsTrue(RestoreRebirthProgression(
            progression,
            rebirthCount,
            0,
            false));

        Assert.AreEqual(expectedTitle, GetText(hud, "titleText"));
        AssertFiveStarVisuals(hud, expectedFilledStars);
    }

    [Test]
    public void MissingProgressionClearsDisplaySafely()
    {
        LogAssert.Expect(LogType.Error,
            "CafeProgressionHudUI: PlayerProgressionManager is unavailable.");
        object hud = CreateHud(null);

        InvokeRefresh(hud);

        Assert.AreEqual(string.Empty, GetText(hud, "titleText"));
        AssertFiveStarVisuals(hud, 0, false);
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
        AssertFiveStarVisuals(hud, 1);

        hudObject.SetActive(true);
        InvokeLifecycle(hud, "OnEnable");
        Assert.AreEqual("Rising Cafe", GetText(hud, "titleText"));
        AssertFiveStarVisuals(hud, 2);
    }

    [Test]
    public void ExistingCafeTitlesHaveDistinctAssignedColors()
    {
        string[] titles =
        {
            "Humble Beginnings",
            "Aspiring Baker",
            "Sweet Apprentice",
            "Rising Cafe",
            "Neighborhood Favorite",
            "Established Cafe",
            "Celebrated Baker",
            "Renowned Cafe",
            "Dessert Artisan",
            "Master of Sweets",
            "Legendary Cafe"
        };
        HashSet<Color32> colors = new HashSet<Color32>();

        Assert.AreEqual(11, titles.Length);
        foreach (string title in titles)
        {
            Color32 color = GetTitleColor(title);
            Assert.AreNotEqual(new Color32(255, 255, 255, 255), color,
                title + " should not fall back to the default title color.");
            Assert.IsTrue(colors.Add(color),
                title + " has a color shared with another Cafe Title.");
        }
        Assert.AreEqual(11, colors.Count);
    }

    [Test]
    public void TitleChangeAppliesExpectedCatalogColor()
    {
        object progression = CreateProgression(0);
        object hud = CreateHud(progression);

        AssertTitleColor(GetTextColor(hud),
            GetTitleColor("Humble Beginnings"));

        Assert.IsTrue(RestoreRebirthProgression(progression, 10, 0, false));
        Assert.AreEqual("Legendary Cafe", GetText(hud, "titleText"));
        AssertTitleColor(GetTextColor(hud),
            GetTitleColor("Legendary Cafe"));
        AssertFiveStarVisuals(hud, 5);
    }

    [Test]
    public void MissingTitleAndStarReferencesAreHandledGracefully()
    {
        LogAssert.Expect(LogType.Error,
            "CafeProgressionHudUI: PlayerProgressionManager is unavailable.");
        object hud = CreateHud(null, false);

        Assert.DoesNotThrow(() => InvokeRefresh(hud));
        Assert.IsNull(GetPrivateField(hud, "titleText"));
        Assert.IsNull(GetPrivateField(hud, "starImages"));
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
        return CreateHud(progression, true);
    }

    private object CreateHud(object progression, bool createVisualReferences)
    {
        Type hudType = FindType("CafeProgressionHudUI");
        Type tmpTextType = FindType("TMPro.TextMeshProUGUI");

        GameObject hudObject = new GameObject(
            "Cafe progression HUD test",
            typeof(RectTransform));
        hudObject.SetActive(false);
        createdObjects.Add(hudObject);
        object hud = hudObject.AddComponent(hudType);

        SetPrivateField(hud, "progressionManager", progression);
        if (createVisualReferences)
        {
            GameObject titleObject = new GameObject(
                "Title",
                typeof(RectTransform));
            titleObject.transform.SetParent(hudObject.transform, false);
            Component title = titleObject.AddComponent(
                tmpTextType);

            Type imageType = FindType("UnityEngine.UI.Image");
            Image[] stars = new Image[5];
            Sprite filledSprite = AssetDatabase.LoadAssetAtPath<Sprite>(
                "Assets/_Game/Art/UI_Assets/UI V1/Game_UI/CafeStarFilled.png");
            Sprite outlineSprite = AssetDatabase.LoadAssetAtPath<Sprite>(
                "Assets/_Game/Art/UI_Assets/UI V1/Game_UI/CafeStarOutline.png");
            Assert.IsNotNull(filledSprite, "Filled cafe star sprite must exist.");
            Assert.IsNotNull(outlineSprite, "Outline cafe star sprite must exist.");

            for (int i = 0; i < stars.Length; i++)
            {
                GameObject starObject = new GameObject(
                    "Star " + (i + 1),
                    typeof(RectTransform));
                starObject.transform.SetParent(hudObject.transform, false);
                stars[i] = (Image)starObject.AddComponent(imageType);
            }

            SetPrivateField(hud, "titleText", title);
            SetPrivateField(hud, "starImages", stars);
            SetPrivateField(hud, "filledStarSprite", filledSprite);
            SetPrivateField(hud, "outlineStarSprite", outlineSprite);
        }
        else
        {
            SetPrivateField(hud, "titleText", null);
            SetPrivateField(hud, "starImages", null);
        }
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

    private static void LogDiagnosticState(object progression, object hud)
    {
        string title = "<unavailable>";
        string starState = "<unavailable>";

        if (hud != null)
        {
            object titleComponent = GetPrivateField(hud, "titleText");
            if (titleComponent != null)
            {
                PropertyInfo textProperty = titleComponent.GetType().GetProperty(
                    "text",
                    BindingFlags.Instance | BindingFlags.Public);
                title = textProperty != null
                    ? (textProperty.GetValue(titleComponent) as string ?? "<null>")
                    : "<text unavailable>";
            }
            else
            {
                title = "<null titleText>";
            }

            object starField = GetPrivateField(hud, "starImages");
            if (starField is Image[] stars)
            {
                int filledCount = 0;
                for (int i = 0; i < stars.Length; i++)
                {
                    if (stars[i] != null &&
                        stars[i].sprite != null &&
                        stars[i].sprite == (Sprite)GetPrivateField(hud, "filledStarSprite"))
                    {
                        filledCount++;
                    }
                }

                starState = stars.Length + " positions, " +
                    filledCount + " filled";
            }
            else
            {
                starState = "<null starImages>";
            }
        }

        string rebirthState = "<unavailable>";
        if (progression != null)
        {
            PropertyInfo rebirthCountProperty = progression.GetType().GetProperty(
                "CurrentRebirthCount",
                BindingFlags.Instance | BindingFlags.Public);
            rebirthState = rebirthCountProperty != null
                ? (rebirthCountProperty.GetValue(progression)?.ToString() ?? "<null>")
                : "<CurrentRebirthCount unavailable>";
        }
        else
        {
            rebirthState = "<null progression>";
        }

        Debug.Log(
            "Cafe HUD save-restoration diagnostic: rebirth=" +
            rebirthState + ", title=" + title + ", stars=" + starState);
    }

    private static string GetText(object hud, string fieldName)
    {
        object textComponent = GetPrivateField(hud, fieldName);
        PropertyInfo textProperty = textComponent.GetType().GetProperty(
            "text",
            BindingFlags.Instance | BindingFlags.Public);
        return (string)textProperty.GetValue(textComponent);
    }

    private static Color GetTextColor(object hud)
    {
        object textComponent = GetPrivateField(hud, "titleText");
        PropertyInfo colorProperty = textComponent.GetType().GetProperty(
            "color",
            BindingFlags.Instance | BindingFlags.Public);
        return (Color)colorProperty.GetValue(textComponent);
    }

    private static Color32 GetTitleColor(string title)
    {
        Type hudType = FindType("CafeProgressionHudUI");
        MethodInfo method = hudType.GetMethod(
            "GetTitleColor",
            BindingFlags.Static | BindingFlags.NonPublic);
        Assert.IsNotNull(method, "Expected CafeProgressionHudUI.GetTitleColor.");
        return (Color32)method.Invoke(null, new object[] { title });
    }

    private static void AssertTitleColor(Color actual, Color32 expected32)
    {
        Color expected = new Color(
            expected32.r / 255f,
            expected32.g / 255f,
            expected32.b / 255f,
            expected32.a / 255f);

        Assert.That(actual.r, Is.EqualTo(expected.r).Within(0.001f));
        Assert.That(actual.g, Is.EqualTo(expected.g).Within(0.001f));
        Assert.That(actual.b, Is.EqualTo(expected.b).Within(0.001f));
        Assert.That(actual.a, Is.EqualTo(expected.a).Within(0.001f));
    }

    private static void AssertFiveStarVisuals(
        object hud,
        int expectedFilledCount,
        bool available = true)
    {
        Image[] stars = (Image[])GetPrivateField(hud, "starImages");
        Assert.IsNotNull(stars, "Five visual star positions must exist.");
        Assert.AreEqual(5, stars.Length, "HUD must have exactly five star positions.");

        Sprite filledSprite = (Sprite)GetPrivateField(hud, "filledStarSprite");
        Sprite outlineSprite = (Sprite)GetPrivateField(hud, "outlineStarSprite");
        Assert.IsNotNull(filledSprite, "Filled star sprite must exist.");
        Assert.IsNotNull(outlineSprite, "Outline star sprite must exist.");

        int filledCount = 0;
        int enabledCount = 0;
        for (int i = 0; i < stars.Length; i++)
        {
            Assert.IsNotNull(stars[i], "Star position " + (i + 1) + " must exist.");
            if (stars[i].enabled)
                enabledCount++;

            if (stars[i].sprite == filledSprite)
                filledCount++;
            else
                Assert.AreEqual(outlineSprite, stars[i].sprite,
                    "Star " + (i + 1) + " must use a filled or outline sprite.");
        }

        Assert.AreEqual(expectedFilledCount, filledCount,
            "Unexpected filled star count.");
        Assert.AreEqual(available ? 5 : 0, enabledCount,
            available
                ? "All five star positions should be enabled."
                : "Unavailable stars should remain disabled.");
        Assert.AreEqual(available ? 5 - expectedFilledCount : 5,
            CountOutlineStars(stars, outlineSprite),
            "Unexpected unfilled star count.");
    }

    private static int CountOutlineStars(Image[] stars, Sprite outlineSprite)
    {
        int count = 0;
        for (int i = 0; i < stars.Length; i++)
        {
            if (stars[i].sprite == outlineSprite)
                count++;
        }
        return count;
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
