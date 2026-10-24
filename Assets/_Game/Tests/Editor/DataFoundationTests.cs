using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text.RegularExpressions;
using NUnit.Framework;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.TestTools;

[ExecuteAlways]
public class ReplacementApplyFailureTrigger : MonoBehaviour
{
    public Action OnDisabled;

    private void OnDisable()
    {
        OnDisabled?.Invoke();
    }
}

public class DataFoundationTests
{
    private sealed class ShelfSlotSceneData
    {
        public readonly Collider2D Collider;
        public readonly SpriteRenderer Renderer;

        public ShelfSlotSceneData(
            Collider2D collider,
            SpriteRenderer renderer)
        {
            Collider = collider;
            Renderer = renderer;
        }
    }

    private sealed class RecycleFixture
    {
        public readonly List<GameObject> Objects = new List<GameObject>();
        public object Dessert;
        public object Cell;
        public object Slot;
        public object DragHandler;
        public object Target;
        public RectTransform ExcludedArea;
        public object Grid;
        public object Shelf;
    }

    private const string DessertFolder =
        "Assets/_Game/Data/Desserts";

    private static readonly string[] ExistingDessertGuids =
    {
        "b830d9759a5ae31448af52ad1f91df9f",
        "c9043fac70e94654993677ff17633c10",
        "b7c378e00b9c8ec438c7434dcca96987",
        "25fafe0a67a1cf94b8645c3899bfbaa6",
        "b61a078f842136d43b44620267b8101f",
        "b57b143b061794f4c966b0f3f5afd0be",
        "966a11f14affd6647b63ffd10889ccb8",
        "df5d2fc983d428f43b38a5fd604b6e7e",
        "4996ed25825fb1541b98b012b6edad69",
        "5fb4dfb478b98ae4cb2992bfc464f6e9",
        "d15530ced30e15548b3a659fe9fd089f"
    };

    private static readonly string[] ExistingOrderDefinitionIds =
    {
        "1a7f189febea4874a80fbb5e86c1d0e8",
        "abb4dc9f8b0fbd54b96d57551d46ba40",
        "7b7d4867f9d90db48bc92e4836301c1c"
    };

    [Test]
    public void DessertCatalogHasOneDefinitionForEveryTierFromOneToThirty()
    {
        var tierToAsset = new Dictionary<int, string>();

        for (int tier = 1; tier <= 30; tier++)
        {
            string path = $"{DessertFolder}/Dessert_{tier:00}.asset";
            Assert.IsTrue(File.Exists(path), $"Missing asset at {path}");

            var asset = AssetDatabase.LoadMainAssetAtPath(path);
            Assert.IsNotNull(asset, $"Unity could not load {path}");
            var serialized = new SerializedObject(asset);
            int serializedTier = serialized.FindProperty("tier").intValue;
            Assert.AreEqual(tier, serializedTier, path);
            Assert.IsFalse(tierToAsset.ContainsKey(serializedTier),
                $"Duplicate dessert tier {serializedTier}");
            tierToAsset.Add(serializedTier, path);
        }

        CollectionAssert.AreEqual(
            Enumerable.Range(1, 30),
            tierToAsset.Keys.OrderBy(tier => tier));

        for (int tier = 1; tier <= ExistingDessertGuids.Length; tier++)
        {
            string path = $"{DessertFolder}/Dessert_{tier:00}.asset";
            Assert.AreEqual(
                ExistingDessertGuids[tier - 1],
                AssetDatabase.AssetPathToGUID(path),
                $"Existing T{tier} asset identity changed.");
        }
    }

    [Test]
    public void DessertDefinitionsAreRegisteredAndOvenEligibilityMatchesPoolCoverage()
    {
        string scenePath = "Assets/_Game/Scenes/Game.unity";
        string sceneText = File.ReadAllText(scenePath);
        Match spawnerData = Regex.Match(
            sceneText,
            @"dessertDefinitions:\s*(?<items>[\s\S]*?)\r?\n\s*nextDessert:");
        Assert.IsTrue(spawnerData.Success, "Could not find serialized DessertSpawner catalog.");

        string[] referencedGuids = Regex.Matches(
                spawnerData.Groups["items"].Value,
                @"guid:\s*([0-9a-f]{32})")
            .Cast<Match>()
            .Select(match => match.Groups[1].Value)
            .ToArray();
        Assert.AreEqual(30, referencedGuids.Length,
            "The Game scene should register the complete catalog exactly once.");
        Assert.AreEqual(30, referencedGuids.Distinct().Count(),
            "The Game scene contains duplicate dessert asset references.");

        var spawnerType = FindPlayerType("DessertSpawner");
        var spawnerObject = new GameObject("DessertSpawner test");
        try
        {
            var spawner = spawnerObject.AddComponent(spawnerType);
            Type definitionType = FindPlayerType("DessertDefinition");
            Array definitions = Array.CreateInstance(
                definitionType,
                referencedGuids.Length);
            for (int i = 0; i < referencedGuids.Length; i++)
            {
                string path = AssetDatabase.GUIDToAssetPath(referencedGuids[i]);
                Assert.IsFalse(
                    string.IsNullOrEmpty(path),
                    $"Unresolved asset GUID {referencedGuids[i]}");
                definitions.SetValue(
                    AssetDatabase.LoadMainAssetAtPath(path),
                    i);
            }

            spawnerType.GetField(
                    "dessertDefinitions",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .SetValue(spawner, definitions);

            MethodInfo lookup = spawnerType.GetMethod(
                "GetDefinitionByTier",
                BindingFlags.Instance | BindingFlags.Public);
            for (int tier = 1; tier <= 30; tier++)
            {
                var definition = lookup.Invoke(spawner, new object[] { tier });
                Assert.IsNotNull(definition, $"Spawner cannot resolve T{tier}");
                var serialized = new SerializedObject((UnityEngine.Object)definition);
                Assert.AreEqual(tier, serialized.FindProperty("tier").intValue);
            }
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(spawnerObject);
        }

        for (int tier = 12; tier <= 30; tier++)
        {
            var asset = AssetDatabase.LoadMainAssetAtPath(
                $"{DessertFolder}/Dessert_{tier:00}.asset");
            var serialized = new SerializedObject(asset);
            Assert.AreEqual(
                tier <= 25,
                serialized.FindProperty("canSpawnFromOven").boolValue,
                $"T{tier} direct-spawn eligibility does not match the frozen catalog.");
            Assert.AreEqual(0f, serialized.FindProperty("spawnWeight").floatValue,
                $"T{tier} must use pool weights rather than a global spawn weight.");
            string displayName =
                serialized.FindProperty("displayName").stringValue;
            bool hasFinalDefinition = tier == 20;
            UnityEngine.Object sprite =
                serialized.FindProperty("sprite").objectReferenceValue;
            if (hasFinalDefinition)
            {
                Assert.AreEqual("Premium Mooncake", displayName);
                Assert.IsInstanceOf<Sprite>(sprite,
                    "The named T20 dessert must resolve to its approved sprite.");
                Assert.AreEqual(
                    "Assets/_Game/Art/Sprites/T20_Premium Mooncake.png",
                    AssetDatabase.GetAssetPath(sprite));
            }
            else
            {
                Assert.IsNotEmpty(displayName,
                    $"T{tier} must have a display name.");
                if (sprite != null)
                {
                    Assert.IsInstanceOf<Sprite>(sprite,
                        $"T{tier} sprite PPtr must resolve as a Sprite asset.");
                    StringAssert.StartsWith(
                        "Assets/_Game/Art/Sprites/",
                        AssetDatabase.GetAssetPath(sprite));
                }

                if (displayName.StartsWith(
                    $"Tier {tier} Placeholder",
                    StringComparison.Ordinal))
                {
                    StringAssert.Contains(
                        "Placeholder",
                        displayName,
                        $"T{tier} remains a placeholder until its definition is finalized.");
                }
                else
                {
                    Assert.IsInstanceOf<Sprite>(sprite,
                        $"Named T{tier} desserts must resolve to a sprite.");
                }
            }
        }
    }

    [Test]
    [Category("Step5C")]
    public void SpawnPoolWeightsAndUnlockLevelsMatchFrozenCandidate()
    {
        Type spawnerType = FindPlayerType("DessertSpawner");
        MethodInfo getWeight = spawnerType.GetMethod(
            "GetSpawnPoolTierWeight",
            BindingFlags.Public | BindingFlags.Static);
        MethodInfo isUnlocked = spawnerType.GetMethod(
            "IsSpawnPoolUnlocked",
            BindingFlags.Public | BindingFlags.Static);
        MethodInfo tierForRoll = spawnerType.GetMethod(
            "GetSpawnPoolTierForRoll",
            BindingFlags.Public | BindingFlags.Static);
        string[] poolIds = { "P1", "P2", "P3", "P4", "P5", "P6" };
        int[] unlockLevels = { 1, 2, 3, 4, 5, 6 };
        int[][] expectedWeights =
        {
            new[] { 60, 30, 10 },
            new[] { 40, 30, 20, 10 },
            new[] { 40, 30, 20, 10 },
            new[] { 40, 30, 20, 10 },
            new[] { 35, 25, 20, 12, 8 },
            new[] { 35, 25, 20, 12, 8 }
        };
        int[] firstTiers = { 1, 4, 8, 12, 16, 21 };

        for (int poolIndex = 0; poolIndex < poolIds.Length; poolIndex++)
        {
            int totalWeight = 0;
            for (int tier = 1; tier <= 30; tier++)
            {
                int expected = tier >= firstTiers[poolIndex] &&
                    tier < firstTiers[poolIndex] + expectedWeights[poolIndex].Length
                    ? expectedWeights[poolIndex][tier - firstTiers[poolIndex]]
                    : 0;
                int actual = (int)getWeight.Invoke(
                    null,
                    new object[] { poolIds[poolIndex], tier });
                Assert.AreEqual(
                    expected,
                    actual,
                    $"{poolIds[poolIndex]} T{tier} weight mismatch.");
                totalWeight += actual;
            }

            Assert.AreEqual(
                100,
                totalWeight,
                $"{poolIds[poolIndex]} must total 100.");
            for (int ovenLevel = 1; ovenLevel <= 6; ovenLevel++)
            {
                bool expectedUnlocked = ovenLevel >= unlockLevels[poolIndex];
                bool actualUnlocked = (bool)isUnlocked.Invoke(
                    null,
                    new object[] { poolIds[poolIndex], ovenLevel });
                Assert.AreEqual(
                    expectedUnlocked,
                    actualUnlocked,
                    $"{poolIds[poolIndex]} unlock mismatch at Oven L{ovenLevel}.");
            }
        }

        for (int tier = 26; tier <= 30; tier++)
        {
            foreach (string poolId in poolIds)
            {
                Assert.AreEqual(
                    0,
                    (int)getWeight.Invoke(null, new object[] { poolId, tier }),
                    $"T{tier} must never spawn directly.");
            }
        }

        Assert.AreEqual(1, tierForRoll.Invoke(null, new object[] { "P1", 0 }));
        Assert.AreEqual(1, tierForRoll.Invoke(null, new object[] { "P1", 59 }));
        Assert.AreEqual(2, tierForRoll.Invoke(null, new object[] { "P1", 60 }));
        Assert.AreEqual(3, tierForRoll.Invoke(null, new object[] { "P1", 90 }));
        Assert.AreEqual(0, tierForRoll.Invoke(null, new object[] { "P1", 100 }));
    }

    [Test]
    [Category("Step5C")]
    public void OvenReferencePoolMixturesMatchFrozenCandidate()
    {
        Type spawnerType = FindPlayerType("DessertSpawner");
        MethodInfo getWeight = spawnerType.GetMethod(
            "GetReferencePoolWeightForOvenLevel",
            BindingFlags.Public | BindingFlags.Static);
        int[][] expected =
        {
            new[] { 100, 0, 0, 0, 0, 0 },
            new[] { 25, 75, 0, 0, 0, 0 },
            new[] { 5, 20, 75, 0, 0, 0 },
            new[] { 3, 7, 15, 75, 0, 0 },
            new[] { 2, 4, 7, 12, 75, 0 },
            new[] { 1, 3, 4, 7, 10, 75 }
        };
        string[] poolIds = { "P1", "P2", "P3", "P4", "P5", "P6" };

        for (int ovenLevel = 1; ovenLevel <= 6; ovenLevel++)
        {
            int totalWeight = 0;
            for (int poolIndex = 0; poolIndex < poolIds.Length; poolIndex++)
            {
                int actual = (int)getWeight.Invoke(
                    null,
                    new object[] { ovenLevel, poolIds[poolIndex] });
                Assert.AreEqual(
                    expected[ovenLevel - 1][poolIndex],
                    actual,
                    $"Oven L{ovenLevel} / {poolIds[poolIndex]} mismatch.");
                totalWeight += actual;
            }

            Assert.AreEqual(100, totalWeight, $"Oven L{ovenLevel} mixture must total 100.");
        }
    }

    [Test]
    public void ProceduralOrdersHonorShapeAndDifficultyBoundaries()
    {
        Array definitions = LoadDessertDefinitions();
        int[] shapeRolls = { 0, 59, 60, 99 };
        string[] expectedShapes = { "Single", "Single", "Mixed", "Mixed" };
        int[] difficultyRolls = { 0, 49, 50, 84, 85, 99 };
        string[] expectedDifficulties =
        {
            "Easy", "Easy", "Standard", "Standard", "Hard", "Hard"
        };
        int[] singleTiers = { 5, 6, 7 };
        int[][] mixedTiers =
        {
            new[] { 4, 3 },
            new[] { 5, 4 },
            new[] { 6, 5 }
        };
        string[] difficultyNames = { "Easy", "Standard", "Hard" };
        int[] expectedRewards = { 32, 67, 147 };

        for (int shapeIndex = 0; shapeIndex < shapeRolls.Length; shapeIndex++)
        {
            for (int difficultyIndex = 0;
                 difficultyIndex < difficultyRolls.Length;
                 difficultyIndex++)
            {
                object order = GenerateProceduralOrder(
                    definitions,
                    1,
                    8,
                    shapeRolls[shapeIndex],
                    difficultyRolls[difficultyIndex],
                    0);
                Assert.AreEqual(
                    expectedShapes[shapeIndex],
                    GetPropertyValue(order, "Shape").ToString());
                Assert.AreEqual(
                    expectedDifficulties[difficultyIndex],
                    GetPropertyValue(order, "Difficulty").ToString());
                Assert.AreEqual("P1", GetPropertyValue(order, "ReferencePoolId"));
                Assert.AreEqual(
                    expectedRewards[difficultyIndex / 2],
                    GetPropertyValue(order, "BaseReward"));

                List<object> requirements = ((IEnumerable)GetPropertyValue(
                    order,
                    "Requirements")).Cast<object>().ToList();
                if (shapeIndex < 2)
                {
                    Assert.AreEqual(1, requirements.Count);
                    AssertRequirement(
                        requirements[0],
                        singleTiers[difficultyIndex / 2],
                        1);
                }
                else
                {
                    Assert.AreEqual(2, requirements.Count);
                    int[] tiers = mixedTiers[difficultyIndex / 2];
                    AssertRequirement(requirements[0], tiers[0], 1);
                    AssertRequirement(requirements[1], tiers[1], 2);
                }
            }
        }
    }

    [Test]
    public void ProceduralOrdersSelectOnlyWeightedReferencePoolsAndBaseRewards()
    {
        Array definitions = LoadDessertDefinitions();
        int[][] weights =
        {
            new[] { 100, 0, 0, 0, 0, 0 },
            new[] { 25, 75, 0, 0, 0, 0 },
            new[] { 5, 20, 75, 0, 0, 0 },
            new[] { 3, 7, 15, 75, 0, 0 },
            new[] { 2, 4, 7, 12, 75, 0 },
            new[] { 1, 3, 4, 7, 10, 75 }
        };
        int[] maxUnlockedTiers = { 8, 12, 16, 20, 25, 30 };
        int[][] expectedRewards =
        {
            new[] { 32, 67, 147 },
            new[] { 80, 168, 368 },
            new[] { 240, 504, 1104 },
            new[] { 720, 1512, 3312 },
            new[] { 2000, 4200, 9200 },
            new[] { 6000, 12600, 27600 }
        };
        int[] difficultyRolls = { 0, 50, 85 };
        string[] poolIds = { "P1", "P2", "P3", "P4", "P5", "P6" };

        for (int ovenLevel = 1; ovenLevel <= 6; ovenLevel++)
        {
            int poolRoll = 0;
            for (int poolIndex = 0; poolIndex < poolIds.Length; poolIndex++)
            {
                int weight = weights[ovenLevel - 1][poolIndex];
                if (weight == 0)
                    continue;

                for (int difficultyIndex = 0;
                     difficultyIndex < difficultyRolls.Length;
                     difficultyIndex++)
                {
                    object order = GenerateProceduralOrder(
                        definitions,
                        ovenLevel,
                        maxUnlockedTiers[ovenLevel - 1],
                        0,
                        difficultyRolls[difficultyIndex],
                        poolRoll);
                    Assert.AreEqual(
                        poolIds[poolIndex],
                        GetPropertyValue(order, "ReferencePoolId"));
                    Assert.AreEqual(
                        expectedRewards[poolIndex][difficultyIndex],
                        GetPropertyValue(order, "BaseReward"),
                        $"{poolIds[poolIndex]} difficulty index {difficultyIndex}.");
                }

                poolRoll += weight;
            }

            Assert.AreEqual(100, poolRoll,
                $"Oven L{ovenLevel} reference pool weights must total 100.");
        }
    }

    [Test]
    public void ProceduralOrderGeneratorRejectsInvalidRollsAndTierLimits()
    {
        Array definitions = LoadDessertDefinitions();
        Type generatorType = FindPlayerType("ProceduralCustomerOrderGenerator");
        MethodInfo generate = generatorType.GetMethod(
            "TryGenerateFromRolls",
            BindingFlags.Public | BindingFlags.Static);

        object[] invalidShapeRoll =
        {
            definitions, 1, 8, 100, 0, 0, null
        };
        Assert.IsFalse((bool)generate.Invoke(null, invalidShapeRoll));
        Assert.IsNull(invalidShapeRoll[6]);

        object[] invalidOven =
        {
            definitions, 7, 30, 0, 0, 0, null
        };
        Assert.IsFalse((bool)generate.Invoke(null, invalidOven));

        object[] aboveOvenTierLimit =
        {
            definitions, 1, 6, 0, 85, 0, null
        };
        Assert.IsFalse((bool)generate.Invoke(null, aboveOvenTierLimit),
            "An order cannot require a tier above the current Oven unlock.");

        object[] tierThirtyBoundary =
        {
            definitions, 6, 30, 0, 85, 25, null
        };
        Assert.IsTrue((bool)generate.Invoke(null, tierThirtyBoundary));
        object order = tierThirtyBoundary[6];
        AssertRequirement(
            ((IEnumerable)GetPropertyValue(order, "Requirements"))
                .Cast<object>()
                .Single(),
            29,
            1);
    }

    [Test]
    public void CustomerButtonPreviewBindsItsSlotAndRefreshesOnOrderStateChanges()
    {
        Array dessertDefinitions =
            LoadDessertDefinitions();
        Type orderType =
            FindPlayerType("CustomerOrder");
        Type orderManagerType =
            FindPlayerType("OrderManager");
        object singleOrder = Activator.CreateInstance(
            orderType,
            new object[]
            {
                101,
                GenerateProceduralOrder(
                    dessertDefinitions,
                    1,
                    8,
                    0,
                    0,
                    0)
            });
        object mixedOrder = Activator.CreateInstance(
            orderType,
            new object[]
            {
                102,
                GenerateProceduralOrder(
                    dessertDefinitions,
                    1,
                    8,
                    60,
                    0,
                    0)
            });

        GameObject orderManagerObject =
            new GameObject("Customer preview test orders");
        GameObject buttonObject = null;
        try
        {
            Component orderManager =
                orderManagerObject.AddComponent(orderManagerType);
            InvokeLifecycle(orderManager, "Awake");
            IList slots =
                (IList)GetPropertyValue(
                    orderManager,
                    "CustomerOrders");
            slots[0] = singleOrder;
            slots[1] = mixedOrder;

            buttonObject = new GameObject(
                "Customer preview test button",
                typeof(RectTransform),
                typeof(CanvasRenderer));
            Type imageType =
                FindPlayerType("UnityEngine.UI.Image");
            Type buttonType =
                FindPlayerType("UnityEngine.UI.Button");
            buttonObject.AddComponent(imageType);
            buttonObject.AddComponent(buttonType);
            GameObject labelObject = new GameObject(
                "CustomerText",
                typeof(RectTransform),
                typeof(CanvasRenderer));
            labelObject.AddComponent(
                FindPlayerType("TMPro.TextMeshProUGUI"));
            labelObject.transform.SetParent(
                buttonObject.transform,
                false);
            Component customerButton =
                buttonObject.AddComponent(
                    FindPlayerType("CustomerButtonUI"));
            InvokeLifecycle(customerButton, "Awake");
            SetPrivateField(
                customerButton,
                "orderManager",
                orderManager);

            customerButton.GetType()
                .GetMethod("Refresh")
                .Invoke(customerButton, null);
            customerButton.GetType()
                .GetMethod(
                    "SubscribeToEvents",
                    BindingFlags.Instance |
                    BindingFlags.NonPublic)
                .Invoke(customerButton, null);
            object label = buttonObject.GetComponentInChildren(
                FindPlayerType("TMPro.TMP_Text"),
                true);
            object firstIcon = buttonObject.transform
                .Find("OrderPreviewIcon_1")
                .GetComponent(imageType);
            object secondIcon = buttonObject.transform
                .Find("OrderPreviewIcon_2")
                .GetComponent(imageType);
            object firstRequirementLabel =
                buttonObject.transform
                    .Find("OrderPreviewRequirement_1")
                    .GetComponent(
                        FindPlayerType("TMPro.TMP_Text"));
            object secondRequirementLabel =
                buttonObject.transform
                    .Find("OrderPreviewRequirement_2")
                    .GetComponent(
                        FindPlayerType("TMPro.TMP_Text"));
            object readinessLabel =
                buttonObject.transform
                    .Find("OrderPreviewReadiness")
                    .GetComponent(
                        FindPlayerType("TMPro.TMP_Text"));

            object singleRequirement =
                ((IEnumerable)GetPropertyValue(
                    singleOrder,
                    "Requirements"))
                .Cast<object>()
                .First();
            object singleDessert =
                GetPropertyValue(singleRequirement, "Dessert");
            string labelText =
                (string)GetPropertyValue(label, "text");
            Assert.AreEqual("TABLE 1", labelText);
            StringAssert.Contains(
                $"T{GetPropertyValue(singleDessert, "Tier")} 0/1",
                (string)GetPropertyValue(
                    firstRequirementLabel,
                    "text"));
            Assert.IsFalse((bool)GetPropertyValue(
                    GetPropertyValue(
                        secondRequirementLabel,
                        "gameObject"),
                    "activeSelf"),
                "The unused requirement row is hidden for a single order.");
            Assert.AreEqual(
                "NEED DESSERTS",
                GetPropertyValue(readinessLabel, "text"));
            Assert.IsTrue((bool)GetPropertyValue(
                    buttonObject.GetComponent(buttonType),
                    "interactable"),
                "An active order remains clickable even when it is not ready.");
            Assert.AreEqual(
                GetPropertyValue(singleDessert, "Sprite"),
                GetPropertyValue(firstIcon, "sprite"));
            Assert.IsFalse((bool)GetPropertyValue(
                    secondIcon,
                    "enabled"),
                "The unused second icon is hidden for a single-dessert order.");
            AssertCustomerPreviewLayout(
                buttonObject.transform,
                firstIcon,
                firstRequirementLabel,
                secondIcon,
                secondRequirementLabel,
                label,
                readinessLabel);

            slots[0] = mixedOrder;
            orderManager.GetType()
                .GetMethod(
                    "EvaluateOrders",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(orderManager, null);

            object[] mixedRequirements =
                ((IEnumerable)GetPropertyValue(
                    mixedOrder,
                    "Requirements"))
                .Cast<object>()
                .ToArray();
            object secondDessert =
                GetPropertyValue(mixedRequirements[1], "Dessert");
            Assert.AreEqual(
                GetPropertyValue(secondDessert, "Sprite"),
                GetPropertyValue(secondIcon, "sprite"));
            Assert.AreEqual(
                GetPropertyValue(secondDessert, "Sprite") != null,
                GetPropertyValue(secondIcon, "enabled"));
            Assert.IsTrue((bool)GetPropertyValue(
                    GetPropertyValue(
                        secondRequirementLabel,
                        "gameObject"),
                    "activeSelf"),
                "Mixed orders show the second requirement row.");
            StringAssert.Contains(
                $"T{GetPropertyValue(secondDessert, "Tier")} 0/2",
                (string)GetPropertyValue(
                    secondRequirementLabel,
                    "text"));
            StringAssert.Contains(
                "NEED DESSERTS",
                (string)GetPropertyValue(readinessLabel, "text"));
        }
        finally
        {
            if (buttonObject != null)
                UnityEngine.Object.DestroyImmediate(buttonObject);
            UnityEngine.Object.DestroyImmediate(orderManagerObject);
        }
    }

    private static void AssertCustomerPreviewLayout(
        Transform buttonTransform,
        object firstIcon,
        object firstRequirementLabel,
        object secondIcon,
        object secondRequirementLabel,
        object headerLabel,
        object readinessLabel)
    {
        RectTransform firstIconRect =
            (RectTransform)GetPropertyValue(
                firstIcon,
                "rectTransform");
        RectTransform firstTextRect =
            (RectTransform)GetPropertyValue(
                firstRequirementLabel,
                "rectTransform");
        RectTransform secondIconRect =
            (RectTransform)GetPropertyValue(
                secondIcon,
                "rectTransform");
        RectTransform secondTextRect =
            (RectTransform)GetPropertyValue(
                secondRequirementLabel,
                "rectTransform");
        RectTransform headerRect =
            (RectTransform)GetPropertyValue(
                headerLabel,
                "rectTransform");
        RectTransform readinessRect =
            (RectTransform)GetPropertyValue(
                readinessLabel,
                "rectTransform");

        Assert.AreEqual(new Vector2(18f, 18f), firstIconRect.sizeDelta);
        Assert.AreEqual(new Vector2(190f, 22f), firstTextRect.sizeDelta);
        Assert.AreEqual(18f, GetPropertyValue(headerLabel, "fontSize"));
        Assert.AreEqual(16f,
            GetPropertyValue(firstRequirementLabel, "fontSize"));
        Assert.AreEqual(15f,
            GetPropertyValue(readinessLabel, "fontSize"));
        Assert.IsFalse((bool)GetPropertyValue(firstIcon, "raycastTarget"));
        Assert.IsFalse((bool)GetPropertyValue(
            firstRequirementLabel,
            "raycastTarget"));
        Assert.IsFalse((bool)GetPropertyValue(
            secondIcon,
            "raycastTarget"));
        Assert.IsFalse((bool)GetPropertyValue(
            secondRequirementLabel,
            "raycastTarget"));
        Assert.IsFalse((bool)GetPropertyValue(
            headerLabel,
            "raycastTarget"));
        Assert.IsFalse((bool)GetPropertyValue(
            readinessLabel,
            "raycastTarget"));

        float iconRight =
            firstIconRect.anchoredPosition.x +
            firstIconRect.sizeDelta.x / 2f;
        float textLeft =
            firstTextRect.anchoredPosition.x -
            firstTextRect.sizeDelta.x / 2f;
        Assert.Less(iconRight, textLeft,
            "Requirement icon and text bounds must not overlap.");
        Assert.Less(
            secondIconRect.anchoredPosition.x +
            secondIconRect.sizeDelta.x / 2f,
            secondTextRect.anchoredPosition.x -
            secondTextRect.sizeDelta.x / 2f,
            "The second requirement icon and text must not overlap.");
        Assert.LessOrEqual(
            firstTextRect.anchoredPosition.y +
            firstTextRect.sizeDelta.y / 2f,
            headerRect.anchoredPosition.y -
            headerRect.sizeDelta.y / 2f);
        Assert.LessOrEqual(
            secondTextRect.anchoredPosition.y +
            secondTextRect.sizeDelta.y / 2f,
            firstTextRect.anchoredPosition.y -
            firstTextRect.sizeDelta.y / 2f);
        Assert.LessOrEqual(
            readinessRect.anchoredPosition.y +
            readinessRect.sizeDelta.y / 2f,
            secondTextRect.anchoredPosition.y -
            secondTextRect.sizeDelta.y / 2f);
        Assert.LessOrEqual(
            headerRect.anchoredPosition.x +
            headerRect.sizeDelta.x / 2f,
            120f);
        Assert.GreaterOrEqual(
            firstIconRect.anchoredPosition.x -
            firstIconRect.sizeDelta.x / 2f,
            -120f);
        Assert.LessOrEqual(
            firstTextRect.anchoredPosition.x +
            firstTextRect.sizeDelta.x / 2f,
            120f);
        Assert.AreEqual(buttonTransform, firstIconRect.parent);
        Assert.AreEqual(buttonTransform, firstTextRect.parent);
    }

    [Test]
    [Category("Step5C")]
    public void SpawnPoolChoicesKeepGeneratedOrdersReachableAtEveryOvenLevel()
    {
        Array definitions = LoadDessertDefinitions();
        Type spawnerType = FindPlayerType("DessertSpawner");
        MethodInfo unlockedPools = spawnerType.GetMethod(
            "GetUnlockedSpawnPoolIds",
            BindingFlags.Public | BindingFlags.Static);
        MethodInfo getPoolFirstTier = spawnerType.GetMethod(
            "GetSpawnPoolFirstTier",
            BindingFlags.Public | BindingFlags.Static);
        MethodInfo getPoolHighestTier = spawnerType.GetMethod(
            "GetSpawnPoolHighestTier",
            BindingFlags.Public | BindingFlags.Static);
        MethodInfo generate = FindPlayerType("ProceduralCustomerOrderGenerator")
            .GetMethod("TryGenerateFromRolls", BindingFlags.Public | BindingFlags.Static);
        int[] caps = { 8, 12, 16, 20, 25, 30 };

        for (int ovenLevel = 1; ovenLevel <= 6; ovenLevel++)
        {
            bool[] reachable = new bool[caps[ovenLevel - 1] + 1];
            foreach (string poolId in (IEnumerable<string>)unlockedPools.Invoke(
                         null,
                         new object[] { ovenLevel }))
            {
                int firstTier = (int)getPoolFirstTier.Invoke(
                    null,
                    new object[] { poolId });
                int highestTier = (int)getPoolHighestTier.Invoke(
                    null,
                    new object[] { poolId });
                for (int tier = firstTier;
                     tier <= highestTier && tier < reachable.Length;
                     tier++)
                    reachable[tier] = true;
            }

            for (int tier = 1; tier < caps[ovenLevel - 1]; tier++)
                if (reachable[tier])
                    reachable[tier + 1] = true;

            for (int shapeRoll = 0; shapeRoll <= 60; shapeRoll += 60)
            for (int difficultyRoll = 0; difficultyRoll <= 85; difficultyRoll +=
                 difficultyRoll == 0 ? 50 : 35)
            for (int poolRoll = 0; poolRoll < 100; poolRoll++)
            {
                object[] args =
                {
                    definitions,
                    ovenLevel,
                    caps[ovenLevel - 1],
                    shapeRoll,
                    difficultyRoll,
                    poolRoll,
                    null
                };
                Assert.IsTrue((bool)generate.Invoke(null, args),
                    $"Could not generate an order at Oven L{ovenLevel}.");
                foreach (object requirement in ((IEnumerable)GetPropertyValue(
                             args[6],
                             "Requirements")).Cast<object>())
                {
                    int tier = (int)GetPropertyValue(
                        GetPropertyValue(requirement, "Dessert"),
                        "Tier");
                    Assert.IsTrue(tier < reachable.Length && reachable[tier],
                        $"Oven L{ovenLevel} cannot reach required T{tier}.");
                }
            }
        }
    }

    [Test]
    [Category("Step5C.1")]
    public void BonusDessertChanceAndBoardCapacityMatchApprovedRules()
    {
        Type spawnerType = FindPlayerType("DessertSpawner");
        MethodInfo chance = spawnerType.GetMethod(
            "GetBonusChancePerTenThousand",
            BindingFlags.Public | BindingFlags.Static);
        MethodInfo shouldSpawn = spawnerType.GetMethod(
            "ShouldSpawnBonus",
            BindingFlags.Public | BindingFlags.Static,
            null,
            new[] { typeof(int), typeof(int) },
            null);
        MethodInfo canFit = spawnerType.GetMethod(
            "CanFitBonusDessert",
            BindingFlags.Public | BindingFlags.Static);
        MethodInfo shouldAttempt = spawnerType.GetMethod(
            "ShouldAttemptBonus",
            BindingFlags.Public | BindingFlags.Static);
        int[] expectedThresholds = { 0, 50, 80, 100, 150, 200 };

        for (int ovenLevel = 1; ovenLevel <= 6; ovenLevel++)
        {
            int threshold = (int)chance.Invoke(null, new object[] { ovenLevel });
            Assert.AreEqual(expectedThresholds[ovenLevel - 1], threshold);
            Assert.IsFalse((bool)shouldSpawn.Invoke(
                null,
                new object[] { ovenLevel, threshold }));
            if (threshold > 0)
                Assert.IsTrue((bool)shouldSpawn.Invoke(
                    null,
                    new object[] { ovenLevel, threshold - 1 }));
        }

        Assert.IsFalse((bool)shouldSpawn.Invoke(null, new object[] { 7, 0 }));
        Assert.IsFalse((bool)shouldSpawn.Invoke(null, new object[] { 6, 10000 }));
        Assert.IsFalse((bool)canFit.Invoke(null, new object[] { 1 }));
        Assert.IsTrue((bool)canFit.Invoke(null, new object[] { 2 }));
        Assert.IsFalse((bool)shouldAttempt.Invoke(
            null,
            new object[] { 6, 0, 1 }));
        Assert.IsTrue((bool)shouldAttempt.Invoke(
            null,
            new object[] { 6, 0, 2 }));
    }

    [Test]
    [Category("Step5C.1")]
    public void BonusDessertsUseHighestUnlockedHigherPoolWeightsAndRespectCaps()
    {
        Type spawnerType = FindPlayerType("DessertSpawner");
        MethodInfo selectBonus = spawnerType.GetMethod(
            "TryGetBonusDessertDefinition",
            BindingFlags.Public | BindingFlags.Static);
        Array definitions = LoadDessertDefinitions();

        AssertSelectedBonus(selectBonus, definitions, "P1", 2, 12, 0, 4);
        AssertSelectedBonus(selectBonus, definitions, "P1", 4, 20, 0, 12);
        AssertSelectedBonus(selectBonus, definitions, "P1", 6, 30, 0, 21);
        AssertSelectedBonus(selectBonus, definitions, "P1", 6, 24, 91, 24);

        object[] noHigherPool =
        {
            definitions, "P6", 6, 30, 0, null
        };
        Assert.IsFalse((bool)selectBonus.Invoke(null, noHigherPool));
        Assert.IsNull(noHigherPool[5]);

        object[] poolNotUnlocked =
        {
            definitions, "P2", 2, 12, 0, null
        };
        Assert.IsFalse((bool)selectBonus.Invoke(null, poolNotUnlocked),
            "The selected pool itself and lower pools cannot supply a bonus.");

        object[] mergeOnlyCap =
        {
            definitions, "P1", 6, 30, 100, null
        };
        Assert.IsFalse((bool)selectBonus.Invoke(null, mergeOnlyCap),
            "T26-T30 must not be added as bonus candidates.");
    }

    private static void AssertSelectedBonus(
        MethodInfo selectBonus,
        Array definitions,
        string selectedPool,
        int ovenLevel,
        int maxTier,
        int roll,
        int expectedTier)
    {
        object[] args =
        {
            definitions,
            selectedPool,
            ovenLevel,
            maxTier,
            roll,
            null
        };
        Assert.IsTrue((bool)selectBonus.Invoke(null, args));
        Assert.AreEqual(expectedTier, GetPropertyValue(args[5], "Tier"));
        Assert.Greater(expectedTier, (int)spawnerPoolHighest(selectedPool));

        for (int currentRoll = 0; currentRoll < 100; currentRoll++)
        {
            args[4] = currentRoll;
            if (!(bool)selectBonus.Invoke(null, args))
                continue;
            int tier = (int)GetPropertyValue(args[5], "Tier");
            Assert.Greater(tier, (int)spawnerPoolHighest(selectedPool));
            Assert.LessOrEqual(tier, maxTier);
            Assert.LessOrEqual(tier, 25,
                "T26-T30 remain merge-only.");
        }
    }

    private static int spawnerPoolHighest(string poolId)
    {
        return (int)FindPlayerType("DessertSpawner")
            .GetMethod("GetSpawnPoolHighestTier",
                BindingFlags.Public | BindingFlags.Static)
            .Invoke(null, new object[] { poolId });
    }

    [Test]
    public void ProceduralOrderFingerprintMatchesCompactAndExpandedSnapshotsButRejectsChanges()
    {
        ReplacementFixture fixture = CreateReplacementFixture();
        UnityEngine.Object compactDefinition = null;
        try
        {
            IList liveOrderSlots = (IList)GetPropertyValue(
                fixture.Orders,
                "CustomerOrders");
            liveOrderSlots[0] = null;
            fixture.Orders.GetType().GetMethod(
                    "RefreshCustomerSlots",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(fixture.Orders, null);
            object order = ((Array)GetActiveOrders(fixture.Orders)).GetValue(0);

            object[] encodeArguments =
            {
                GetPropertyValue(order, "DisplayName"),
                GetPropertyValue(order, "CashReward"),
                GetPropertyValue(order, "Requirements"),
                null
            };
            Assert.IsTrue((bool)FindPlayerType("ProceduralCustomerOrderSaveCodec")
                .GetMethod("TryEncode")
                .Invoke(null, encodeArguments));

            Type definitionType = FindPlayerType("CustomerOrderDefinition");
            compactDefinition = ScriptableObject.CreateInstance(definitionType);
            var serializedDefinition = new SerializedObject(compactDefinition);
            serializedDefinition.FindProperty("definitionId").stringValue =
                (string)encodeArguments[3];
            serializedDefinition.ApplyModifiedPropertiesWithoutUndo();

            Type stateType = FindPlayerType("CustomerOrderState");
            Type orderType = FindPlayerType("CustomerOrder");
            ConstructorInfo compactConstructor = stateType.GetConstructor(
                new[] { typeof(int), typeof(int), definitionType });
            ConstructorInfo expandedConstructor = stateType.GetConstructor(
                new[] { typeof(int), orderType });
            object compactState = compactConstructor.Invoke(
                new object[] { 0, GetPropertyValue(order, "OrderId"), compactDefinition });
            object expandedState = expandedConstructor.Invoke(new[] { (object)0, order });

            Type sessionType = FindPlayerType("MergeSessionData");
            object compactSession = Activator.CreateInstance(sessionType);
            object expandedSession = Activator.CreateInstance(sessionType);
            Type stateListType = typeof(List<>).MakeGenericType(stateType);
            IList compactOrders = (IList)Activator.CreateInstance(stateListType);
            IList expandedOrders = (IList)Activator.CreateInstance(stateListType);
            compactOrders.Add(compactState);
            expandedOrders.Add(expandedState);
            SetField(compactSession, "customerOrders", compactOrders);
            SetField(expandedSession, "customerOrders", expandedOrders);

            MethodInfo fingerprint = FindPlayerType("RestorationVerification")
                .GetMethod("Fingerprint", new[] { sessionType });
            string compactFingerprint = (string)fingerprint.Invoke(null, new[] { compactSession });
            MethodInfo matchesFingerprint = FindPlayerType("RestorationVerification")
                .GetMethod("MatchesFingerprint", new[] { typeof(string), sessionType });
            Assert.IsTrue((bool)matchesFingerprint.Invoke(
                null,
                new[] { compactFingerprint, expandedSession }),
                "The encoded snapshot and expanded runtime order represent the same order.");

            object changedReward = expandedConstructor.Invoke(new[] { (object)0, order });
            SetField(changedReward, "cashReward",
                (int)GetPropertyValue(order, "CashReward") + 1);
            IList changedRewardOrders = (IList)Activator.CreateInstance(stateListType);
            changedRewardOrders.Add(changedReward);
            object changedRewardSession = Activator.CreateInstance(sessionType);
            SetField(changedRewardSession, "customerOrders", changedRewardOrders);
            Assert.IsFalse((bool)matchesFingerprint.Invoke(
                null,
                new[] { compactFingerprint, changedRewardSession }),
                "A changed procedural reward must fail verification.");

            object changedRequirement = expandedConstructor.Invoke(new[] { (object)0, order });
            Array requirements = (Array)GetField(changedRequirement, "requirements");
            object firstRequirement = requirements.GetValue(0);
            SetPrivateField(firstRequirement, "amount",
                (int)GetPropertyValue(firstRequirement, "Amount") + 1);
            IList changedRequirementOrders = (IList)Activator.CreateInstance(stateListType);
            changedRequirementOrders.Add(changedRequirement);
            object changedRequirementSession = Activator.CreateInstance(sessionType);
            SetField(changedRequirementSession, "customerOrders", changedRequirementOrders);
            Assert.IsFalse((bool)matchesFingerprint.Invoke(
                null,
                new[] { compactFingerprint, changedRequirementSession }),
                "Changed dessert quantities must fail verification.");

            object legacyDefinition = AssetDatabase.LoadAssetAtPath(
                "Assets/_Game/Data/Orders/Order_03.asset",
                definitionType);
            Assert.IsNotNull(legacyDefinition);
            ConstructorInfo definitionOrderConstructor = orderType.GetConstructor(
                new[] { typeof(int), definitionType });
            object legacyRuntimeOrder = definitionOrderConstructor.Invoke(
                new[] { (object)12, legacyDefinition });
            object legacyExpandedState = expandedConstructor.Invoke(
                new[] { (object)0, legacyRuntimeOrder });
            object legacyCompactState = compactConstructor.Invoke(
                new[] { (object)0, 12, legacyDefinition });
            IList legacyExpectedOrders = (IList)Activator.CreateInstance(stateListType);
            IList legacyActualOrders = (IList)Activator.CreateInstance(stateListType);
            legacyExpectedOrders.Add(legacyCompactState);
            legacyActualOrders.Add(legacyExpandedState);
            object legacyExpectedSession = Activator.CreateInstance(sessionType);
            object legacyActualSession = Activator.CreateInstance(sessionType);
            SetField(legacyExpectedSession, "customerOrders", legacyExpectedOrders);
            SetField(legacyActualSession, "customerOrders", legacyActualOrders);
            string legacyTarget = (string)fingerprint.Invoke(
                null,
                new[] { legacyExpectedSession });
            Assert.IsTrue((bool)matchesFingerprint.Invoke(
                null,
                new[] { legacyTarget, legacyActualSession }),
                "Definition-backed snapshots compare their authoritative order details.");

            object alteredLegacyOrder = definitionOrderConstructor.Invoke(
                new[] { (object)12, legacyDefinition });
            object alteredLegacyState = expandedConstructor.Invoke(
                new[] { (object)0, alteredLegacyOrder });
            SetField(alteredLegacyState, "cashReward",
                (int)GetPropertyValue(legacyDefinition, "CashReward") + 1);
            IList alteredLegacyOrders = (IList)Activator.CreateInstance(stateListType);
            alteredLegacyOrders.Add(alteredLegacyState);
            object alteredLegacySession = Activator.CreateInstance(sessionType);
            SetField(alteredLegacySession, "customerOrders", alteredLegacyOrders);
            Assert.IsFalse((bool)matchesFingerprint.Invoke(
                null,
                new[] { legacyTarget, alteredLegacySession }),
                "An expanded order that disagrees with its definition must fail verification.");
        }
        finally
        {
            if (compactDefinition != null)
                UnityEngine.Object.DestroyImmediate(compactDefinition);
            DestroyReplacementFixture(fixture);
        }
    }

    [Test]
    public void ProceduralOrderV2RoundTripPreservesSessionFingerprintAndRequirements()
    {
        ReplacementFixture fixture = CreateReplacementFixture();
        try
        {
            IList liveOrderSlots = (IList)GetPropertyValue(
                fixture.Orders,
                "CustomerOrders");
            liveOrderSlots[0] = null;
            fixture.Orders.GetType().GetMethod(
                    "RefreshCustomerSlots",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(fixture.Orders, null);

            Array orders = GetActiveOrders(fixture.Orders);
            Assert.AreEqual(1, orders.Length);
            object original = orders.GetValue(0);
            Assert.IsNull(GetPropertyValue(original, "Definition"));
            Assert.IsTrue((bool)GetPropertyValue(original, "IsValid"));
            AssertOrderRequirementsWithinTierCap(
                original,
                (int)GetPropertyValue(fixture.Progression, "MaxUnlockedDessertTier"));

            MethodInfo deterministicGenerate = fixture.Orders.GetType().GetMethod(
                "TryGenerateProceduralOrder",
                BindingFlags.Instance | BindingFlags.NonPublic);
            object[] firstArguments =
            {
                500, new System.Random(1729), null
            };
            object[] secondArguments =
            {
                500, new System.Random(1729), null
            };
            Assert.IsTrue((bool)deterministicGenerate.Invoke(
                fixture.Orders,
                firstArguments));
            Assert.IsTrue((bool)deterministicGenerate.Invoke(
                fixture.Orders,
                secondArguments));
            AssertOrdersEqual(firstArguments[2], secondArguments[2]);

            object economy = FindSingleton("EconomyManager");
            int baseReward = (int)GetPropertyValue(original, "CashReward");
            float multiplier = (float)GetPropertyValue(
                economy,
                "CurrentMoneyMultiplier");
            int expectedPaidReward = Mathf.RoundToInt(baseReward * multiplier);
            Assert.AreEqual(
                expectedPaidReward,
                economy.GetType().GetMethod("CalculateOrderReward")
                    .Invoke(economy, new[] { original }),
                "The existing reward pipeline applies the money multiplier once.");

            MethodInfo capture = fixture.Controller.GetType()
                .GetMethod("TryCaptureSession");
            Assert.IsTrue((bool)capture.Invoke(fixture.Controller, null));
            object saveData = Activator.CreateInstance(
                FindPlayerType("MergeGameplaySaveData"));
            Assert.IsTrue((bool)fixture.SessionManager.GetType()
                .GetMethod("CaptureToSaveData")
                .Invoke(fixture.SessionManager, new object[] { saveData }));
            IList savedOrders = GetPublicList(saveData, "customerOrders");
            Assert.AreEqual(1, savedOrders.Count);
            object saved = savedOrders[0];
            Assert.IsTrue(((string)GetField(saved, "definitionId"))
                .StartsWith("procedural-order-v1:", StringComparison.Ordinal));

            object saveSnapshot = Activator.CreateInstance(
                FindPlayerType("PlayerSaveData"));
            SetField(saveSnapshot, "mergeGameplay", saveData);
            Type saveManagerType = fixture.SaveManager.GetType();
            string json = (string)saveManagerType.GetMethod(
                    "SerializeWithCapacity",
                    BindingFlags.Static | BindingFlags.NonPublic)
                .Invoke(null, new object[] { saveSnapshot, 1 });
            Assert.IsTrue((bool)saveManagerType.GetMethod(
                    "IsValidSerializedSnapshot",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(fixture.SaveManager, new object[] { json }));
            object reloadedSave = JsonUtility.FromJson(
                json,
                FindPlayerType("PlayerSaveData"));
            object reloadedGameplay = GetField(reloadedSave, "mergeGameplay");

            Type sessionType = FindPlayerType("MergeSessionData");
            MethodInfo fingerprint = FindPlayerType("RestorationVerification")
                .GetMethod("Fingerprint", new[] { sessionType });
            object expectedSession = GetPropertyValue(
                fixture.SessionManager,
                "SessionData");
            string expectedFingerprint = (string)fingerprint.Invoke(
                null,
                new[] { expectedSession });
            Assert.IsTrue((bool)fixture.SessionManager.GetType()
                .GetMethod("RestoreFromSaveData")
                .Invoke(fixture.SessionManager, new[] { reloadedGameplay }));
            object v2RestoredSession = GetPropertyValue(
                fixture.SessionManager,
                "SessionData");
            string restoredFingerprint = (string)fingerprint.Invoke(
                null,
                new[] { v2RestoredSession });
            Assert.AreEqual(
                expectedFingerprint,
                restoredFingerprint,
                (string)FindPlayerType("RestorationVerification")
                    .GetMethod(
                        "DescribeDifference",
                        new[] { sessionType, sessionType })
                    .Invoke(
                        null,
                        new[]
                        {
                            expectedSession,
                            v2RestoredSession
                        }));

            object restoredSession = Activator.CreateInstance(
                sessionType);
            MethodInfo restoreOrders = fixture.SessionManager.GetType().GetMethod(
                "RestoreOrdersFromSaveData",
                BindingFlags.Instance | BindingFlags.NonPublic);
            Assert.IsTrue((bool)restoreOrders.Invoke(
                fixture.SessionManager,
                new[] { reloadedGameplay, restoredSession }));
            SetField(
                restoredSession,
                "nextOrderId",
                GetField(reloadedGameplay, "nextOrderId"));
            var restoreOrderManager = fixture.Orders.GetType().GetMethod(
                "RestoreCustomerOrders",
                BindingFlags.Instance | BindingFlags.Public,
                null,
                new[]
                {
                    typeof(IReadOnlyList<>).MakeGenericType(
                        FindPlayerType("CustomerOrderState")),
                    typeof(int),
                    typeof(int)
                },
                null);
            Assert.IsTrue((bool)restoreOrderManager.Invoke(
                fixture.Orders,
                new object[]
                {
                    GetField(restoredSession, "customerOrders"),
                    GetField(restoredSession, "nextOrderId"),
                    1
                }));
            object reloaded = ((Array)GetActiveOrders(fixture.Orders)).GetValue(0);
            AssertOrdersEqual(original, reloaded);

            List<object> requirements = ((IEnumerable)GetPropertyValue(
                reloaded,
                "Requirements")).Cast<object>().ToList();
            int requiredDesserts = requirements.Sum(
                row => (int)GetPropertyValue(row, "Amount"));
            Assert.LessOrEqual(
                requiredDesserts,
                fixture.Cells.Count - 1,
                "The test board must fit the generated order.");
            int cellIndex = 1;
            foreach (object requirement in requirements)
            {
                int amountRequired = (int)GetPropertyValue(requirement, "Amount");
                object dessertDefinition = GetPropertyValue(requirement, "Dessert");
                for (int amount = 0; amount < amountRequired; amount++)
                {
                    if ((UnityEngine.Object)GetPropertyValue(
                            dessertDefinition,
                            "Sprite") == null)
                    {
                        string dessertName = (string)GetPropertyValue(
                            dessertDefinition,
                            "DisplayName");
                        LogAssert.Expect(
                            LogType.Error,
                            $"{dessertName} has no sprite assigned.");
                    }

                    object dessert = AddRuntimeComponent(fixture, "Dessert");
                    dessert.GetType().GetMethod("Initialize").Invoke(
                        dessert,
                        new[] { dessertDefinition, fixture.Cells[cellIndex] });
                    fixture.Cells[cellIndex].GetType().GetMethod("PlaceDessert")
                        .Invoke(
                            fixture.Cells[cellIndex],
                            new[] { dessert, (object)true });
                    cellIndex++;
                }
            }

            int completedOrderId = (int)GetPropertyValue(reloaded, "OrderId");
            for (int i = 0; i < requiredDesserts; i++)
            {
                LogAssert.Expect(
                    LogType.Error,
                    new Regex("Destroy may not be called from edit mode"));
            }
            economy.GetType().GetMethod(
                    "ResolveReferences",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(economy, null);
            economy.GetType().GetMethod(
                    "SubscribeToOrderManager",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(economy, null);
            int cashBeforeCompletion = (int)GetPropertyValue(economy, "CurrentCash");
            Assert.IsTrue((bool)fixture.Orders.GetType()
                .GetMethod("TryFulfillOrderAtIndex")
                .Invoke(fixture.Orders, new object[] { 0 }));
            Assert.AreEqual(
                cashBeforeCompletion + expectedPaidReward,
                GetPropertyValue(economy, "CurrentCash"),
                "Order completion must pay the rounded multiplied reward exactly once.");
            object replacement = ((Array)GetActiveOrders(fixture.Orders)).GetValue(0);
            Assert.Greater((int)GetPropertyValue(replacement, "OrderId"), completedOrderId);
            Assert.IsTrue((bool)GetPropertyValue(replacement, "IsValid"));
            AssertOrderRequirementsWithinTierCap(
                replacement,
                (int)GetPropertyValue(fixture.Progression, "MaxUnlockedDessertTier"));
        }
        finally
        {
            DestroyReplacementFixture(fixture);
        }
    }

    [Test]
    [Category("Step6A.3.1")]
    public void ProceduralV2OrderRestoresWithoutSpawnerThenResolvesInGameplay()
    {
        ReplacementFixture fixture = CreateReplacementFixture();
        try
        {
            object sourceOrder = fixture.Orders.GetType()
                .GetMethod("GetOrderForCustomer")
                .Invoke(fixture.Orders, new object[] { 0 });
            object[] encodeArguments =
            {
                GetPropertyValue(sourceOrder, "DisplayName"),
                GetPropertyValue(sourceOrder, "CashReward"),
                GetPropertyValue(sourceOrder, "Requirements"),
                null
            };
            Assert.IsTrue((bool)FindPlayerType("ProceduralCustomerOrderSaveCodec")
                .GetMethod("TryEncode")
                .Invoke(null, encodeArguments));

            object saveData = Activator.CreateInstance(
                FindPlayerType("MergeGameplaySaveData"));
            SetField(saveData, "hasSession", true);
            SetField(saveData, "nextOrderId", 14);
            var savedOrders = GetPublicList(saveData, "customerOrders");
            Type saveOrderType = FindPlayerType("CustomerOrderSaveData");
            savedOrders.Add(Activator.CreateInstance(
                saveOrderType,
                new object[] { 0, 13, encodeArguments[3] }));

            SetPrivateField(fixture.SessionManager, "dessertSpawner", null);
            Assert.IsTrue((bool)fixture.SessionManager.GetType()
                .GetMethod("RestoreFromSaveData")
                .Invoke(fixture.SessionManager, new[] { saveData }),
                "A valid compact procedural order must not require a gameplay spawner during persistent loading.");

            var capturedData = Activator.CreateInstance(
                FindPlayerType("MergeGameplaySaveData"));
            Assert.IsTrue((bool)fixture.SessionManager.GetType()
                .GetMethod("CaptureToSaveData")
                .Invoke(fixture.SessionManager, new[] { capturedData }));
            object capturedOrder = GetPublicList(capturedData, "customerOrders")[0];
            Assert.AreEqual(13, GetField(capturedOrder, "orderId"));
            Assert.AreEqual(
                encodeArguments[3],
                GetField(capturedOrder, "definitionId"),
                "Persistent restore must preserve the compact order payload exactly.");
            object playerSave = Activator.CreateInstance(
                FindPlayerType("PlayerSaveData"));
            SetField(playerSave, "mergeGameplay", capturedData);
            Type saveManagerType = fixture.SaveManager.GetType();
            string json = (string)saveManagerType.GetMethod(
                    "SerializeWithCapacity",
                    BindingFlags.Static | BindingFlags.NonPublic)
                .Invoke(null, new object[] { playerSave, 1 });
            Assert.IsTrue((bool)saveManagerType.GetMethod(
                    "IsValidSerializedSnapshot",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(fixture.SaveManager, new object[] { json }),
                "The preserved compact procedural order remains a valid V2 snapshot.");

            object restoredSession = Activator.CreateInstance(
                FindPlayerType("MergeSessionData"));
            Assert.IsTrue((bool)fixture.SessionManager.GetType().GetMethod(
                    "RestoreOrdersFromSaveData",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(
                    fixture.SessionManager,
                    new[] { saveData, restoredSession }));
            object restoredState = GetField(restoredSession, "customerOrders");
            Assert.AreEqual(
                encodeArguments[3],
                GetField(((IList)restoredState)[0], "proceduralDefinitionId"));

            Assert.IsTrue((bool)fixture.Orders.GetType()
                .GetMethod(
                    "RestoreCustomerOrders",
                    new[]
                    {
                        typeof(IReadOnlyList<>).MakeGenericType(
                            FindPlayerType("CustomerOrderState")),
                        typeof(int),
                        typeof(int)
                    })
                .Invoke(
                    fixture.Orders,
                    new object[]
                    {
                        restoredState,
                        14,
                        1
                    }),
                "The gameplay spawner resolves compact tier requirements into dessert assets.");

            object resolvedOrder = fixture.Orders.GetType()
                .GetMethod("GetOrderForCustomer")
                .Invoke(fixture.Orders, new object[] { 0 });
            Assert.IsTrue((bool)GetPropertyValue(resolvedOrder, "IsValid"));
            Assert.AreEqual(13, GetPropertyValue(resolvedOrder, "OrderId"));
            Type orderType = FindPlayerType("CustomerOrder");
            object expectedOrder = orderType.GetConstructor(
                    BindingFlags.Instance | BindingFlags.NonPublic,
                    null,
                    new[]
                    {
                        typeof(int),
                        typeof(string),
                        typeof(int),
                        typeof(IReadOnlyList<>).MakeGenericType(
                            FindPlayerType("OrderRequirement"))
                    },
                    null)
                .Invoke(
                    new object[]
                    {
                        13,
                        GetPropertyValue(sourceOrder, "DisplayName"),
                        GetPropertyValue(sourceOrder, "CashReward"),
                        GetPropertyValue(sourceOrder, "Requirements")
                    });
            AssertOrdersEqual(expectedOrder, resolvedOrder);
        }
        finally
        {
            DestroyReplacementFixture(fixture);
        }
    }

    [Test]
    [Category("Step6A.3.1")]
    public void DefinitionBackedSavedOrdersStillRestoreNormally()
    {
        ReplacementFixture fixture = CreateReplacementFixture();
        try
        {
            var definition = (UnityEngine.Object)AssetDatabase.LoadAssetAtPath(
                "Assets/_Game/Data/Orders/Order_03.asset",
                FindPlayerType("CustomerOrderDefinition"));
            Assert.IsNotNull(definition);
            Assert.IsTrue((bool)GetPropertyValue(definition, "IsValid"));

            Type stateType = FindPlayerType("CustomerOrderState");
            object state = stateType.GetConstructor(
                    new[]
                    {
                        typeof(int),
                        typeof(int),
                        FindPlayerType("CustomerOrderDefinition")
                    })
                .Invoke(new object[] { 0, 12, definition });
            IList states = (IList)Activator.CreateInstance(
                typeof(List<>).MakeGenericType(stateType));
            states.Add(state);

            Assert.IsTrue((bool)fixture.Orders.GetType()
                .GetMethod(
                    "RestoreCustomerOrders",
                    new[]
                    {
                        typeof(IReadOnlyList<>).MakeGenericType(stateType),
                        typeof(int),
                        typeof(int)
                    })
                .Invoke(fixture.Orders, new object[] { states, 13, 1 }));
            object restored = fixture.Orders.GetType()
                .GetMethod("GetOrderForCustomer")
                .Invoke(fixture.Orders, new object[] { 0 });
            Assert.IsTrue((bool)GetPropertyValue(restored, "IsValid"));
            Assert.AreSame(
                definition,
                GetPropertyValue(restored, "Definition"));
            Assert.AreEqual(12, GetPropertyValue(restored, "OrderId"));
        }
        finally
        {
            DestroyReplacementFixture(fixture);
        }
    }

    [Test]
    [Category("Step6A.3")]
    public void FailedReplacementOrderRecoversWithoutRepeatingPayout()
    {
        ReplacementFixture fixture = CreateReplacementFixture();
        try
        {
            object order = fixture.Orders.GetType()
                .GetMethod("GetOrderForCustomer")
                .Invoke(fixture.Orders, new object[] { 0 });
            Assert.IsNotNull(order);
            int completedOrderId = (int)GetPropertyValue(order, "OrderId");
            int nextOrderId = (int)GetPropertyValue(fixture.Orders, "NextOrderId");

            List<object> requirements = ((IEnumerable)GetPropertyValue(
                order,
                "Requirements")).Cast<object>().ToList();
            int requiredDesserts = requirements.Sum(
                requirement => (int)GetPropertyValue(requirement, "Amount"));
            Assert.LessOrEqual(requiredDesserts, fixture.Cells.Count - 1);

            int cellIndex = 1;
            foreach (object requirement in requirements)
            {
                int amountRequired = (int)GetPropertyValue(requirement, "Amount");
                object definition = GetPropertyValue(requirement, "Dessert");
                for (int amount = 0; amount < amountRequired; amount++)
                {
                    if ((UnityEngine.Object)GetPropertyValue(definition, "Sprite") == null)
                    {
                        LogAssert.Expect(
                            LogType.Error,
                            $"{GetPropertyValue(definition, "DisplayName")} has no sprite assigned.");
                    }

                    object dessert = AddRuntimeComponent(fixture, "Dessert");
                    object cell = fixture.Cells[cellIndex++];
                    dessert.GetType().GetMethod("Initialize").Invoke(
                        dessert, new[] { definition, cell });
                    cell.GetType().GetMethod("PlaceDessert")
                        .Invoke(cell, new[] { dessert, (object)true });
                }
            }

            object economy = FindSingleton("EconomyManager");
            economy.GetType().GetMethod(
                    "ResolveReferences",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(economy, null);
            economy.GetType().GetMethod(
                    "SubscribeToOrderManager",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(economy, null);
            int cashBeforeCompletion = (int)GetPropertyValue(economy, "CurrentCash");
            int expectedReward = (int)economy.GetType()
                .GetMethod("CalculateOrderReward")
                .Invoke(economy, new[] { order });

            Array savedDefinitions = (Array)GetPropertyValue(
                fixture.Spawner,
                "DessertDefinitions");
            SetPrivateField(
                fixture.Spawner,
                "dessertDefinitions",
                Array.CreateInstance(savedDefinitions.GetType().GetElementType(), 0));
            for (int i = 0; i < requiredDesserts; i++)
            {
                LogAssert.Expect(
                    LogType.Error,
                    new Regex("Destroy may not be called from edit mode"));
            }
            LogAssert.Expect(
                LogType.Error,
                "ORDER GENERATION FAILED | Customer 1 | Procedural order generation found no valid order within the current Oven tier cap.");

            Assert.IsTrue((bool)fixture.Orders.GetType()
                .GetMethod("TryFulfillOrderAtIndex")
                .Invoke(fixture.Orders, new object[] { 0 }));
            Assert.AreEqual(cashBeforeCompletion + expectedReward,
                GetPropertyValue(economy, "CurrentCash"));
            Assert.IsNull(fixture.Orders.GetType()
                .GetMethod("GetOrderForCustomer")
                .Invoke(fixture.Orders, new object[] { 0 }));
            Assert.AreEqual(nextOrderId,
                GetPropertyValue(fixture.Orders, "NextOrderId"),
                "A failed generation must not consume an order ID.");

            Assert.IsFalse((bool)fixture.Orders.GetType()
                .GetMethod("TryFulfillOrderAtIndex")
                .Invoke(fixture.Orders, new object[] { 0 }),
                "An empty slot cannot pay out the completed order again.");
            Assert.AreEqual(cashBeforeCompletion + expectedReward,
                GetPropertyValue(economy, "CurrentCash"));

            SetPrivateField(
                fixture.Spawner,
                "dessertDefinitions",
                savedDefinitions);
            fixture.Orders.GetType().GetMethod(
                    "HandleUpgradeLevelChanged",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(
                    fixture.Orders,
                    new[]
                    {
                        Enum.Parse(FindPlayerType("UpgradeType"), "Oven"),
                        (object)GetPropertyValue(fixture.Progression, "OvenLevel")
                    });

            object replacement = fixture.Orders.GetType()
                .GetMethod("GetOrderForCustomer")
                .Invoke(fixture.Orders, new object[] { 0 });
            Assert.IsNotNull(replacement,
                "An Oven progression event retries the previously empty slot.");
            Assert.IsTrue((bool)GetPropertyValue(replacement, "IsValid"));
            Assert.Greater((int)GetPropertyValue(replacement, "OrderId"), completedOrderId);
            Assert.AreEqual(nextOrderId + 1,
                GetPropertyValue(fixture.Orders, "NextOrderId"));
            Assert.AreEqual(cashBeforeCompletion + expectedReward,
                GetPropertyValue(economy, "CurrentCash"),
                "Recovering the slot must not pay the completed order again.");
        }
        finally
        {
            DestroyReplacementFixture(fixture);
        }
    }

    [Test]
    public void OvenLevelSixHasT30CapButRemainsUnavailableForPurchase()
    {
        var asset = AssetDatabase.LoadMainAssetAtPath(
            "Assets/_Game/Data/Upgrades/Upgrade_Oven.asset");
        Assert.IsNotNull(asset);

        Type definitionType = FindPlayerType("UpgradeDefinition");
        Assert.AreEqual(6, definitionType.GetProperty("MaxLevel").GetValue(asset));
        Assert.AreEqual(
            5,
            definitionType.GetProperty("MaxPurchasableLevel").GetValue(asset));
        Assert.IsTrue((bool)definitionType.GetMethod("IsMaxLevel")
            .Invoke(asset, new object[] { 5 }));

        var serialized = new SerializedObject(asset);
        var levels = serialized.FindProperty("levels");
        Assert.AreEqual(30, levels.GetArrayElementAtIndex(5)
            .FindPropertyRelative("intValue").intValue);
        Assert.AreEqual(50000, levels.GetArrayElementAtIndex(5)
            .FindPropertyRelative("upgradeCost").intValue);
    }

    [Test]
    public void ExistingOrderDefinitionIdsRemainStable()
    {
        for (int i = 0; i < ExistingOrderDefinitionIds.Length; i++)
        {
            string path = $"Assets/_Game/Data/Orders/Order_{i + 1:00}.asset";
            var asset = AssetDatabase.LoadMainAssetAtPath(path);
            Assert.IsNotNull(asset, $"Missing production order asset: {path}");
            var serialized = new SerializedObject(asset);
            Assert.AreEqual(
                ExistingOrderDefinitionIds[i],
                serialized.FindProperty("definitionId").stringValue,
                $"Stable order definition ID changed: {path}");
        }
    }

    [Test]
    public void UpgradeDefinitionsHaveSequentialLevelsAndValidBaseLevel()
    {
        string[] paths =
        {
            "Assets/_Game/Data/Upgrades/Upgrade_Oven.asset",
            "Assets/_Game/Data/Upgrades/Upgrade_BoardSpace.asset",
            "Assets/_Game/Data/Upgrades/Upgrade_Shelf.asset",
            "Assets/_Game/Data/Upgrades/Upgrade_Customer.asset",
            "Assets/_Game/Data/Upgrades/Upgrade_MoneyMultiplier.asset",
            "Assets/_Game/Data/Upgrades/Upgrade_Luck.asset"
        };

        foreach (string path in paths)
        {
            var asset = AssetDatabase.LoadMainAssetAtPath(path);
            Assert.IsNotNull(asset, $"Missing upgrade definition: {path}");
            var serialized = new SerializedObject(asset);
            var levels = serialized.FindProperty("levels");
            Assert.Greater(levels.arraySize, 0, path);

            for (int i = 0; i < levels.arraySize; i++)
            {
                var level = levels.GetArrayElementAtIndex(i);
                Assert.AreEqual(i + 1, level.FindPropertyRelative("level").intValue,
                    $"Nonsequential upgrade level in {path}");
                Assert.GreaterOrEqual(
                    level.FindPropertyRelative("upgradeCost").intValue,
                    0,
                    $"Negative upgrade cost in {path}");
            }

            Assert.AreEqual(
                0,
                levels.GetArrayElementAtIndex(0)
                    .FindPropertyRelative("upgradeCost").intValue,
                $"Starting level must be free in {path}");
        }
    }

    [Test]
    public void SupportingUpgradePricesAndValuesMatchEconomyV1()
    {
        AssertUpgradeTable(
            "Assets/_Game/Data/Upgrades/Upgrade_BoardSpace.asset",
            new[] { 12, 15, 18, 21, 24, 27, 30 },
            new[] { 0f, 0f, 0f, 0f, 0f, 0f, 0f },
            new[] { 0, 100, 350, 900, 2500, 7000, 18000 });
        AssertUpgradeTable(
            "Assets/_Game/Data/Upgrades/Upgrade_Shelf.asset",
            new[] { 1, 2, 3, 4, 5 },
            new[] { 0f, 0f, 0f, 0f, 0f },
            new[] { 0, 120, 450, 1500, 5000 });
        AssertUpgradeTable(
            "Assets/_Game/Data/Upgrades/Upgrade_Customer.asset",
            new[] { 1, 2, 3, 4 },
            new[] { 0f, 0f, 0f, 0f },
            new[] { 0, 250, 1500, 8000 });
        AssertUpgradeTable(
            "Assets/_Game/Data/Upgrades/Upgrade_MoneyMultiplier.asset",
            new[] { 0, 0, 0, 0 },
            new[] { 1f, 1.2f, 1.5f, 2f },
            new[] { 0, 400, 2500, 15000 });
    }

    [Test]
    public void RebirthMilestonesAndOvenUnlocksMatchEconomyV1()
    {
        int[] requiredTiers = { 7, 8, 11, 12, 15, 16, 19, 20, 24, 25 };
        int[] requiredCash =
        {
            128, 278, 320, 1070, 960, 3960, 2880, 14880, 8000, 58000
        };
        int[] ovenLevels = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6 };

        for (int rebirthCount = 0; rebirthCount < 10; rebirthCount++)
        {
            object state = CreateRebirthState(rebirthCount);
            int nextRebirth = rebirthCount + 1;
            Assert.AreEqual(nextRebirth, GetRebirthProperty(state, "NextRebirthNumber"));
            Assert.AreEqual(requiredTiers[rebirthCount],
                GetRebirthProperty(state, "NextRequiredTier"));
            Assert.AreEqual(requiredCash[rebirthCount],
                GetRebirthProperty(state, "NextRequiredCash"));
            Assert.AreEqual(
                nextRebirth % 2 == 0 ? nextRebirth / 2 + 1 : 0,
                GetRebirthProperty(state, "NextOvenLevelUnlock"));
        }

        MethodInfo getOvenLevel = FindPlayerType("RebirthProgressionState")
            .GetMethod("GetOvenLevelForRebirthCount");
        for (int rebirthCount = 0; rebirthCount <= 10; rebirthCount++)
        {
            Assert.AreEqual(
                ovenLevels[rebirthCount],
                getOvenLevel.Invoke(null, new object[] { rebirthCount }),
                $"Incorrect Oven unlock at R{rebirthCount}.");
        }

        object completed = CreateRebirthState(10);
        Assert.IsFalse((bool)GetRebirthProperty(completed, "HasNextRebirth"));
        Assert.AreEqual(0, GetRebirthProperty(completed, "NextRebirthNumber"));
        Assert.AreEqual(0, GetRebirthProperty(completed, "NextRequiredTier"));
        Assert.AreEqual(0, GetRebirthProperty(completed, "NextRequiredCash"));
        Assert.AreEqual(0, GetRebirthProperty(completed, "NextOvenLevelUnlock"));
    }

    [Test]
    [Category("Step5C")]
    public void RebirthRestoreSynchronizesFreeOvenLevelAndSpawnPool()
    {
        var setup = CreateProgressionPurchaseTestSetup();
        var spawnerObject = new GameObject("Rebirth Oven spawn pool test");
        spawnerObject.SetActive(false);
        var saveManagerObject = new GameObject("Spawn pool restore save test");
        saveManagerObject.SetActive(false);
        object saveManager = saveManagerObject.AddComponent(
            FindPlayerType("SaveManager"));
        object spawner = spawnerObject.AddComponent(
            FindPlayerType("DessertSpawner"));
        SetPrivateField(spawner, "progressionManager", setup.Progression);
        Array dessertDefinitions = Array.CreateInstance(
            FindPlayerType("DessertDefinition"), 30);
        for (int tier = 1; tier <= 30; tier++)
        {
            dessertDefinitions.SetValue(
                AssetDatabase.LoadMainAssetAtPath(
                    $"{DessertFolder}/Dessert_{tier:00}.asset"),
                tier - 1);
        }
        SetPrivateField(spawner, "dessertDefinitions", dessertDefinitions);

        try
        {
            MethodInfo start = spawner.GetType().GetMethod(
                "Start",
                BindingFlags.Instance | BindingFlags.NonPublic);
            start.Invoke(spawner, null);
            int[] ovenLevels = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6 };

            for (int rebirthCount = 0; rebirthCount <= 10; rebirthCount++)
            {
                bool campaignComplete = rebirthCount == 10;
                Assert.IsTrue((bool)setup.Progression.GetType()
                    .GetMethod("RestoreRebirthProgression")
                    .Invoke(setup.Progression, new object[]
                    {
                        rebirthCount,
                        campaignComplete ? 30 : 0,
                        campaignComplete
                    }));
                setup.Progression.GetType()
                    .GetMethod(
                        "RestoreProgression",
                        new[]
                        {
                            typeof(int), typeof(int), typeof(int),
                            typeof(int), typeof(int)
                        })
                    .Invoke(setup.Progression, new object[] { 6, 3, 2, 1, 1 });

                Assert.AreEqual(
                    ovenLevels[rebirthCount],
                    setup.Progression.GetType()
                        .GetProperty("OvenLevel").GetValue(setup.Progression));
                Assert.AreEqual(
                    "P1",
                    spawner.GetType()
                        .GetProperty("SelectedSpawnPoolId").GetValue(spawner),
                    "Oven unlocks must preserve the player's valid pool selection.");
                Assert.AreEqual(
                    3,
                    setup.Progression.GetType()
                        .GetProperty("BoardSpaceLevel").GetValue(setup.Progression),
                    "A Rebirth must preserve purchased support levels.");
                Assert.AreEqual(
                    2,
                    setup.Progression.GetType()
                        .GetProperty("ShelfLevel").GetValue(setup.Progression),
                    "A Rebirth must preserve purchased support levels.");
                Assert.AreEqual(
                    100000,
                    setup.Economy.GetType()
                        .GetProperty("CurrentCash").GetValue(setup.Economy),
                    "Free Oven unlocks must not charge cash.");
            }

            Assert.IsTrue((bool)            setup.Progression.GetType()
                .GetMethod("RestoreRebirthProgression")
                .Invoke(setup.Progression, new object[] { 3, 0, false }));
            SetPrivateField(saveManager, "loadedSelectedSpawnPoolId", "P1");
            Assert.IsTrue((bool)saveManager.GetType()
                .GetMethod("RestoreSelectedSpawnPool")
                .Invoke(saveManager, new[] { spawner }));
            Assert.AreEqual(
                "P1",
                spawner.GetType().GetProperty("SelectedSpawnPoolId")
                    .GetValue(spawner),
                "A loaded valid P1 choice should survive Rebirth and restore.");
            int previewTier = (int)GetPropertyValue(
                spawner.GetType().GetProperty("NextDessert").GetValue(spawner),
                "Tier");
            Assert.That(previewTier, Is.InRange(1, 3),
                "P1 must produce an eligible low-tier preview.");
            MethodInfo tierForRoll = spawner.GetType().GetMethod(
                "GetSpawnPoolTierForRoll",
                BindingFlags.Public | BindingFlags.Static);
            MethodInfo getDefinition = spawner.GetType().GetMethod(
                "GetDessertDefinitionByTier",
                BindingFlags.Public | BindingFlags.Instance);
            foreach (int roll in new[] { 0, 60, 90 })
            {
                int tier = (int)tierForRoll.Invoke(
                    null,
                    new object[] { "P1", roll });
                object definition = getDefinition.Invoke(
                    spawner,
                    new object[] { tier });
                Assert.IsNotNull(definition,
                    $"P1 must resolve a dessert definition for T{tier}.");
                Assert.AreEqual(tier, GetPropertyValue(definition, "Tier"));
            }
            int cashBeforeSelection = (int)setup.Economy.GetType()
                .GetProperty("CurrentCash").GetValue(setup.Economy);
            Assert.IsTrue((bool)spawner.GetType()
                .GetMethod("TrySelectSpawnPool")
                .Invoke(spawner, new object[] { "P2" }),
                "R2 should allow switching to P2.");
            Assert.AreEqual(
                "P2",
                spawner.GetType().GetProperty("SelectedSpawnPoolId")
                    .GetValue(spawner));
            Assert.IsTrue((bool)spawner.GetType()
                .GetMethod("TrySelectSpawnPool")
                .Invoke(spawner, new object[] { "P1" }),
                "R3 and later should retain access to P1.");
            Assert.IsFalse((bool)spawner.GetType()
                .GetMethod("TrySelectSpawnPool")
                .Invoke(spawner, new object[] { "P3" }),
                "Locked pools must not be selectable.");
            Assert.AreEqual(
                cashBeforeSelection,
                setup.Economy.GetType().GetProperty("CurrentCash")
                    .GetValue(setup.Economy),
                "Changing spawn pools must not charge cash.");
            Assert.AreEqual(
                "P1",
                spawner.GetType().GetProperty("SelectedSpawnPoolId")
                    .GetValue(spawner));

            var saveManagerType = FindPlayerType("SaveManager");
            MethodInfo serializeWithPool = saveManagerType.GetMethod(
                "SerializeWithSpawnPool",
                BindingFlags.Static | BindingFlags.NonPublic,
                null,
                new[] { FindPlayerType("PlayerSaveData"), typeof(int), typeof(string) },
                null);
            var saveData = Activator.CreateInstance(
                FindPlayerType("PlayerSaveData"));
            string pooledJson = (string)serializeWithPool.Invoke(
                null,
                new[] { saveData, (object)0, "P1" });
            string legacyJson = (string)saveManagerType.GetMethod(
                    "SerializeWithCapacity",
                    BindingFlags.Static | BindingFlags.NonPublic,
                    null,
                    new[] { FindPlayerType("PlayerSaveData"), typeof(int) },
                    null)
                .Invoke(null, new[] { saveData, (object)0 });
            Assert.IsTrue(pooledJson.Contains("\"selectedSpawnPoolId\":\"P1\""));
            Assert.IsFalse(legacyJson.Contains("selectedSpawnPoolId"),
                "Older V2 root shape remains unchanged when pool metadata is absent.");
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(saveManagerObject);
            UnityEngine.Object.DestroyImmediate(spawnerObject);
            DestroyProgressionPurchaseTestSetup(setup);
        }
    }

    [Test]
    [Category("DEV01A2B")]
    public void RebirthRestoreWithInvalidOvenDefinitionDoesNotPartiallyMutateProgression()
    {
        GameObject progressionObject =
            new GameObject("Invalid Oven restore regression test");
        progressionObject.SetActive(false);
        object progression = progressionObject.AddComponent(
            FindPlayerType("PlayerProgressionManager"));
        Type progressionType = progression.GetType();
        Type levelType = FindPlayerType("UpgradeLevelData");
        Array levels = Array.CreateInstance(levelType, 2);
        for (int i = 0; i < levels.Length; i++)
        {
            object level = Activator.CreateInstance(levelType);
            SetPrivateField(level, "level", i + 1);
            SetPrivateField(level, "upgradeCost", 0);
            levels.SetValue(level, i);
        }

        UnityEngine.Object ovenDefinition =
            ScriptableObject.CreateInstance(
                FindPlayerType("UpgradeDefinition"));
        SetPrivateField(
            ovenDefinition,
            "upgradeType",
            Enum.Parse(FindPlayerType("UpgradeType"), "Oven"));
        SetPrivateField(ovenDefinition, "displayName", "Test Oven");
        SetPrivateField(ovenDefinition, "levels", levels);
        SetPrivateField(ovenDefinition, "maxPurchasableLevel", 2);
        SetPrivateField(progression, "ovenUpgrade", ovenDefinition);
        SetPrivateField(progression, "ovenLevel", 1);

        bool progressionChanged = false;
        Action onProgressionChanged = () => progressionChanged = true;
        EventInfo changedEvent =
            progressionType.GetEvent("RebirthProgressionChanged");
        changedEvent.AddEventHandler(progression, onProgressionChanged);

        try
        {
            SetPrivateField(progression, "ovenUpgrade", null);
            LogAssert.Expect(
                LogType.Error,
                "REBIRTH PROGRESSION | Cannot restore progression " +
                "without a valid Oven definition for the derived level.");

            bool restored = (bool)progressionType
                .GetMethod("RestoreRebirthProgression")
                .Invoke(progression, new object[] { 2, 0, false });

            Assert.IsFalse(restored);
            Assert.AreEqual(
                0,
                progressionType.GetProperty("CurrentRebirthCount")
                    .GetValue(progression));
            Assert.AreEqual(
                0,
                progressionType.GetProperty("HighestTierCreatedThisRun")
                    .GetValue(progression));
            Assert.IsFalse((bool)progressionType.GetProperty("CampaignComplete")
                .GetValue(progression));
            Assert.AreEqual(
                1,
                progressionType.GetProperty("OvenLevel")
                    .GetValue(progression));
            Assert.IsFalse(progressionChanged);
        }
        finally
        {
            changedEvent.RemoveEventHandler(progression, onProgressionChanged);
            UnityEngine.Object.DestroyImmediate(ovenDefinition);
            UnityEngine.Object.DestroyImmediate(progressionObject);
        }
    }

    [Test]
    public void SupportUpgradePurchasesRespectEveryRebirthGate()
    {
        var setup = CreateProgressionPurchaseTestSetup();
        GameObject managerObject = new GameObject("Support upgrade gate test");
        Type progressionType = setup.Progression.GetType();
        PropertyInfo instanceProperty = progressionType.GetProperty(
            "Instance",
            BindingFlags.Public | BindingFlags.Static);
        object previousInstance = instanceProperty.GetValue(null);
        try
        {
            SetPrivateStaticProperty(
                progressionType,
                "Instance",
                setup.Progression);
            managerObject.SetActive(false);
            object purchaseManager = managerObject.AddComponent(
                FindPlayerType("UpgradePurchaseManager"));
            SetPrivateField(purchaseManager, "progressionManager", setup.Progression);
            SetPrivateField(purchaseManager, "economyManager", setup.Economy);
            managerObject.SetActive(true);

            var gates = new (string type, int level, int rebirthCount)[]
            {
                ("BoardSpace", 2, 2),
                ("Shelf", 2, 2),
                ("Customer", 2, 2),
                ("MoneyMultiplier", 2, 2),
                ("BoardSpace", 3, 5),
                ("Shelf", 3, 5),
                ("Customer", 3, 5),
                ("MoneyMultiplier", 3, 5),
                ("BoardSpace", 4, 7),
                ("Shelf", 4, 7),
                ("Customer", 4, 7),
                ("MoneyMultiplier", 4, 7),
                ("BoardSpace", 5, 9),
                ("Shelf", 5, 9),
                ("BoardSpace", 6, 10),
                ("BoardSpace", 7, 10)
            };
            Type upgradeType = FindPlayerType("UpgradeType");

            MethodInfo restoreRebirth = setup.Progression.GetType()
                .GetMethod("RestoreRebirthProgression");
            MethodInfo setLevel = setup.Progression.GetType()
                .GetMethod("TrySetLevel");
            MethodInfo getLevel = setup.Progression.GetType()
                .GetMethod("GetLevel");
            MethodInfo canPurchase = purchaseManager.GetType()
                .GetMethod("CanPurchaseUpgrade");
            MethodInfo purchase = purchaseManager.GetType()
                .GetMethod("TryPurchaseUpgrade");
            MethodInfo requiredRebirth = purchaseManager.GetType()
                .GetMethod("GetRequiredRebirthCountForNextUpgrade");

            foreach (var gate in gates)
            {
                object type = Enum.Parse(upgradeType, gate.type);
                int requiredTier = gate.rebirthCount == 10 ? 30 : 0;
                bool completed = gate.rebirthCount == 10;
                Assert.IsTrue((bool)restoreRebirth.Invoke(
                    setup.Progression,
                    new object[] { gate.rebirthCount - 1, 0, false }));
                setLevel.Invoke(
                    setup.Progression,
                    new[] { type, (object)(gate.level - 1) });
                Assert.AreEqual(
                    gate.level - 1,
                    getLevel.Invoke(setup.Progression, new[] { type }));
                Assert.AreEqual(
                    gate.rebirthCount,
                    requiredRebirth.Invoke(purchaseManager, new[] { type }),
                    $"{gate.type} L{gate.level} should report its authoritative Rebirth gate.");

                int cashBefore = (int)setup.Economy.GetType()
                    .GetProperty("CurrentCash").GetValue(setup.Economy);
                Assert.IsFalse((bool)canPurchase.Invoke(
                    purchaseManager, new[] { type }),
                    $"{gate.type} L{gate.level} should be locked before R{gate.rebirthCount}.");
                Assert.IsFalse((bool)purchase.Invoke(
                    purchaseManager, new[] { type }),
                    $"{gate.type} L{gate.level} purchase should be rejected before its gate.");
                Assert.AreEqual(
                    cashBefore,
                    setup.Economy.GetType()
                        .GetProperty("CurrentCash").GetValue(setup.Economy),
                    "A rejected purchase must not charge cash.");

                Assert.IsTrue((bool)restoreRebirth.Invoke(
                    setup.Progression,
                    new object[] { gate.rebirthCount, requiredTier, completed }));
                Assert.IsTrue((bool)canPurchase.Invoke(
                    purchaseManager, new[] { type }),
                    $"{gate.type} L{gate.level} should unlock at R{gate.rebirthCount}.");
            }

            object ovenType = Enum.Parse(upgradeType, "Oven");
            Assert.IsFalse((bool)canPurchase.Invoke(
                purchaseManager, new[] { ovenType }),
                "Oven levels are Rebirth unlocks, not cash purchases.");
            int ovenCash = (int)setup.Economy.GetType()
                .GetProperty("CurrentCash").GetValue(setup.Economy);
            Assert.IsFalse((bool)purchase.Invoke(
                purchaseManager, new[] { ovenType }));
            Assert.AreEqual(
                ovenCash,
                setup.Economy.GetType()
                    .GetProperty("CurrentCash").GetValue(setup.Economy));
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(managerObject);
            SetPrivateStaticProperty(
                progressionType,
                "Instance",
                previousInstance);
            DestroyProgressionPurchaseTestSetup(setup);
        }
    }

    [Test]
    [Category("Step6C.4")]
    public void UpgradeCardGateLabelsAndButtonStatesAreDistinct()
    {
        Type upgradeType = FindPlayerType("UpgradeType");
        Type cardType = FindPlayerType("UpgradeCardUI");
        MethodInfo labelMethod = cardType.GetMethod(
            "GetPurchaseButtonLabel",
            BindingFlags.Static | BindingFlags.NonPublic);
        MethodInfo interactableMethod = cardType.GetMethod(
            "IsPurchaseButtonInteractable",
            BindingFlags.Static | BindingFlags.NonPublic);
        MethodInfo priceLabelMethod = cardType.GetMethod(
            "GetPriceLabel",
            BindingFlags.Static | BindingFlags.NonPublic);
        Assert.IsNotNull(labelMethod);
        Assert.IsNotNull(interactableMethod);
        Assert.IsNotNull(priceLabelMethod);

        object boardType = Enum.Parse(upgradeType, "BoardSpace");
        object ovenType = Enum.Parse(upgradeType, "Oven");

        Assert.AreEqual(
            "Requires Rebirth 5",
            labelMethod.Invoke(null, new object[]
            {
                boardType, false, 5, false
            }));
        Assert.AreEqual(
            "Requires Rebirth 10",
            labelMethod.Invoke(null, new object[]
            {
                boardType, false, 10, false
            }));
        Assert.AreEqual(
            "NEED CASH",
            labelMethod.Invoke(null, new object[]
            {
                boardType, true, 5, false
            }));
        Assert.AreEqual(
            "UPGRADE",
            labelMethod.Invoke(null, new object[]
            {
                boardType, true, 5, true
            }));
        Assert.AreEqual(
            "LOCKED",
            labelMethod.Invoke(null, new object[]
            {
                boardType, false, -1, false
            }));
        Assert.AreEqual(
            "REBIRTH",
            labelMethod.Invoke(null, new object[]
            {
                ovenType, false, -1, false
            }));
        Assert.AreEqual(
            string.Empty,
            priceLabelMethod.Invoke(null, new object[]
            {
                ovenType, 100
            }));
        Assert.IsNotEmpty((string)priceLabelMethod.Invoke(
            null,
            new object[] { boardType, 100 }));

        Assert.IsFalse((bool)interactableMethod.Invoke(null, new object[]
        {
            boardType, false, false
        }));
        Assert.IsFalse((bool)interactableMethod.Invoke(null, new object[]
        {
            boardType, true, false
        }));
        Assert.IsTrue((bool)interactableMethod.Invoke(null, new object[]
        {
            boardType, true, true
        }));
        Assert.IsFalse((bool)interactableMethod.Invoke(null, new object[]
        {
            ovenType, false, true
        }));
    }

    [Test]
    [Category("CustomUI_UI4_3_2")]
    public void UpgradeButtonsRetainGreenArtworkWhenUnavailable()
    {
        const string prefabPath =
            "Assets/_Game/Prefabs/UI/UpgradeCard.prefab";
        const string scenePath =
            "Assets/_Game/Scenes/MainBakery.unity";
        const string prefabGuid =
            "f57edfc7bd9b74a4c942b4e61bc5d7a6";
        const string upgradeSpriteGuid =
            "9c680e7e11f4e7a4d8578168bb01d998";
        const string disabledColor =
            "m_DisabledColor: {r: 0.76, g: 0.9, b: 0.76, a: 0.9}";

        string prefabText = File.ReadAllText(prefabPath);
        Match buttonImage = Regex.Match(
            prefabText,
            @"(?ms)^--- !u!114 &6606862767538336197\r?\n(.*?)(?=^--- !u!|\z)");
        Match button = Regex.Match(
            prefabText,
            @"(?ms)^--- !u!114 &9173353401447694653\r?\n(.*?)(?=^--- !u!|\z)");
        Assert.IsTrue(buttonImage.Success);
        Assert.IsTrue(button.Success);
        StringAssert.Contains("m_Color: {r: 1, g: 1, b: 1, a: 1}",
            buttonImage.Value);
        StringAssert.Contains("m_Transition: 1", button.Value,
            "The button must keep Color Tint transition.");
        StringAssert.Contains(
            "m_NormalColor: {r: 1, g: 1, b: 1, a: 1}",
            button.Value);
        StringAssert.Contains(disabledColor, button.Value);
        StringAssert.Contains(
            "m_TargetGraphic: {fileID: 6606862767538336197}",
            button.Value);
        StringAssert.Contains("m_Interactable: 1", button.Value);

        string sceneText = File.ReadAllText(scenePath);
        MatchCollection prefabInstances = Regex.Matches(
            sceneText,
            @"(?ms)^--- !u!1001 &-?\d+\r?\n(.*?)(?=^--- !u!|\z)");
        List<string> upgradeCards = prefabInstances
            .Cast<Match>()
            .Select(match => match.Value)
            .Where(instance => instance.Contains(
                $"m_SourcePrefab: {{fileID: 100100000, guid: {prefabGuid}, type: 3}}"))
            .ToList();
        Assert.AreEqual(6, upgradeCards.Count,
            "The Shop Upgrade scene must retain all six card instances.");

        foreach (string instance in upgradeCards)
        {
            Assert.IsTrue(Regex.IsMatch(
                instance,
                $@"target: \{{fileID: 6606862767538336197, guid: {prefabGuid}, type: 3\}}\r?\n\s+propertyPath: m_Type\r?\n\s+value: 0"),
                "Each card must preserve Simple image rendering.");
            StringAssert.Contains(
                $"objectReference: {{fileID: -1482606001489111098, guid: {upgradeSpriteGuid}, type: 3}}",
                instance,
                "Each card must retain SU_Upgrade.png.");
            Assert.IsFalse(instance.Contains(
                $"target: {{fileID: 9173353401447694653, guid: {prefabGuid}, type: 3}}"),
                "Scene instances inherit the shared button ColorBlock.");
        }

        GameObject card = PrefabUtility.LoadPrefabContents(prefabPath);
        try
        {
            Type buttonType = FindPlayerType("UnityEngine.UI.Button");
            Type imageType = FindPlayerType("UnityEngine.UI.Image");
            Type textType = FindPlayerType("TMPro.TextMeshProUGUI");
            Transform buttonTransform = card.transform.Find(
                "BodyRow/CostActionGroup/PurchaseButton");
            Assert.IsNotNull(buttonTransform);
            Component purchaseButton =
                buttonTransform.GetComponent(buttonType);
            Component image = buttonTransform.GetComponent(imageType);
            Assert.IsNotNull(purchaseButton);
            Assert.IsNotNull(image);
            Assert.AreEqual("ColorTint",
                buttonType.GetProperty("transition")
                    .GetValue(purchaseButton).ToString());
            Assert.AreSame(image,
                buttonType.GetProperty("targetGraphic")
                    .GetValue(purchaseButton));
            Assert.AreEqual(new Vector2(0, 84),
                ((RectTransform)buttonTransform).sizeDelta);

            object colors = buttonType.GetProperty("colors")
                .GetValue(purchaseButton);
            Type colorBlockType = colors.GetType();
            Assert.AreEqual(Color.white,
                colorBlockType.GetProperty("normalColor")
                    .GetValue(colors));
            Color disabledTint = (Color)colorBlockType
                .GetProperty("disabledColor")
                .GetValue(colors);
            Assert.AreEqual(0.76f, disabledTint.r, 0.001f);
            Assert.AreEqual(0.9f, disabledTint.g, 0.001f);
            Assert.AreEqual(0.76f, disabledTint.b, 0.001f);
            Assert.AreEqual(0.9f, disabledTint.a, 0.001f);

            Type cardType = FindPlayerType("UpgradeCardUI");
            MethodInfo labelMethod = cardType.GetMethod(
                "GetPurchaseButtonLabel",
                BindingFlags.Static | BindingFlags.NonPublic);
            MethodInfo interactableMethod = cardType.GetMethod(
                "IsPurchaseButtonInteractable",
                BindingFlags.Static | BindingFlags.NonPublic);
            Assert.IsNotNull(labelMethod);
            Assert.IsNotNull(interactableMethod);
            object boardType = Enum.Parse(
                FindPlayerType("UpgradeType"), "BoardSpace");
            object ovenType = Enum.Parse(
                FindPlayerType("UpgradeType"), "Oven");
            Assert.AreEqual("UPGRADE", labelMethod.Invoke(
                null, new object[] { boardType, true, 0, true }));
            Assert.AreEqual("NEED CASH", labelMethod.Invoke(
                null, new object[] { boardType, true, 0, false }));
            Assert.AreEqual("Requires Rebirth 10", labelMethod.Invoke(
                null, new object[] { boardType, false, 10, false }));
            Assert.AreEqual("REBIRTH", labelMethod.Invoke(
                null, new object[] { ovenType, false, -1, false }));
            Assert.IsFalse((bool)interactableMethod.Invoke(
                null, new object[] { boardType, false, false }));
            Assert.IsFalse((bool)interactableMethod.Invoke(
                null, new object[] { boardType, true, false }));
            Assert.IsTrue((bool)interactableMethod.Invoke(
                null, new object[] { boardType, true, true }));
            Assert.IsFalse((bool)interactableMethod.Invoke(
                null, new object[] { ovenType, false, true }));

            Component cardController =
                card.GetComponent(cardType);
            MethodInfo showMaxLevel = cardType.GetMethod(
                "ShowMaxLevel",
                BindingFlags.Instance | BindingFlags.NonPublic);
            object ovenDefinition = AssetDatabase.LoadMainAssetAtPath(
                "Assets/_Game/Data/Upgrades/Upgrade_Oven.asset");
            Type definitionType = FindPlayerType("UpgradeDefinition");
            int maxLevel = (int)definitionType
                .GetProperty("MaxLevel")
                .GetValue(ovenDefinition);
            object maxLevelData = definitionType
                .GetMethod("GetLevel")
                .Invoke(ovenDefinition, new object[] { maxLevel });
            Assert.IsNotNull(cardController);
            Assert.IsNotNull(showMaxLevel);
            Assert.IsNotNull(ovenDefinition);
            cardType.GetField(
                "upgradeDefinition",
                BindingFlags.Instance | BindingFlags.NonPublic)
                .SetValue(cardController, ovenDefinition);
            showMaxLevel.Invoke(cardController, new object[]
            {
                maxLevel,
                maxLevelData
            });

            Transform priceText = card.transform.Find(
                "BodyRow/CostActionGroup/PriceText");
            Transform buttonText = buttonTransform.Find("ButtonText");
            Assert.AreEqual("MAX",
                textType.GetProperty("text")
                    .GetValue(priceText.GetComponent(textType)));
            Assert.AreEqual("MAX LEVEL",
                textType.GetProperty("text")
                    .GetValue(buttonText.GetComponent(textType)));
            Assert.IsFalse((bool)buttonType.GetProperty("interactable")
                .GetValue(purchaseButton));
        }
        finally
        {
            PrefabUtility.UnloadPrefabContents(card);
        }
    }

    [Test]
    [Category("CustomUI_UI2")]
    public void UpgradeCardLayoutFitsParentAndAlignsRegions()
    {
        const string prefabPath =
            "Assets/_Game/Prefabs/UI/UpgradeCard.prefab";
        string prefabText = File.ReadAllText(prefabPath);
        long[] boundedTextIds =
        {
            1952818838986804043,
            5723161596120778220,
            4523219856188570108,
            9161292831575217704,
            3790715771410225071,
            2443458557906387767
        };

        foreach (long textComponentId in boundedTextIds)
        {
            Match text = Regex.Match(
                prefabText,
                $@"(?ms)^--- !u!114 &{textComponentId}\r?\n(.*?)(?=^--- !u!|\z)");
            Assert.IsTrue(text.Success);
            StringAssert.Contains("m_enableAutoSizing: 1", text.Value);
            StringAssert.Contains("m_overflowMode: 1", text.Value);
        }

        foreach (long textComponentId in new long[]
                 {
                     1952818838986804043,
                     4523219856188570108,
                     9161292831575217704
                 })
        {
            Match text = Regex.Match(
                prefabText,
                $@"(?ms)^--- !u!114 &{textComponentId}\r?\n(.*?)(?=^--- !u!|\z)");
            StringAssert.Contains("m_TextWrappingMode: 1", text.Value);
        }

        Match effectLabel = Regex.Match(
            prefabText,
            @"(?ms)^--- !u!114 &4523219856188570108\r?\n(.*?)(?=^--- !u!|\z)");
        StringAssert.Contains("m_fontSizeMin: 20", effectLabel.Value);
        StringAssert.Contains("m_fontSizeMax: 22", effectLabel.Value);

        GameObject prefab = AssetDatabase.LoadAssetAtPath<GameObject>(
            prefabPath);
        Assert.IsNotNull(prefab);
        GameObject card = PrefabUtility.InstantiatePrefab(prefab) as GameObject;
        Assert.IsNotNull(card);
        var layoutParent = new GameObject(
            "Upgrade card layout test parent",
            typeof(RectTransform));
        try
        {
            RectTransform cardRect =
                (RectTransform)card.transform;
            card.transform.SetParent(layoutParent.transform, false);
            cardRect.anchorMin = new Vector2(0.5f, 0.5f);
            cardRect.anchorMax = new Vector2(0.5f, 0.5f);
            cardRect.anchoredPosition = Vector2.zero;
            cardRect.sizeDelta = new Vector2(900, 360);

            Transform headerRow = card.transform.Find("HeaderRow");
            Transform bodyRow = card.transform.Find("BodyRow");
            Transform costActionGroup =
                card.transform.Find("BodyRow/CostActionGroup");
            Transform informationBox =
                card.transform.Find("BodyRow/InformationBox");
            Transform nameText =
                card.transform.Find("HeaderRow/UpgradeNameText");
            Transform levelText =
                card.transform.Find("HeaderRow/LevelText");
            Transform effectText =
                card.transform.Find("BodyRow/EffectLabelText");
            Transform valueText =
                card.transform.Find("BodyRow/ValueText");
            Transform priceText =
                card.transform.Find("BodyRow/CostActionGroup/PriceText");
            Transform purchaseButton =
                card.transform.Find("BodyRow/CostActionGroup/PurchaseButton");

            Assert.IsNotNull(headerRow);
            Assert.IsNotNull(bodyRow);
            Assert.IsNotNull(costActionGroup);
            Assert.IsNotNull(informationBox);
            Assert.IsNotNull(nameText);
            Assert.IsNotNull(levelText);
            Assert.IsNotNull(effectText);
            Assert.IsNotNull(valueText);
            Assert.IsNotNull(priceText);
            Assert.IsNotNull(purchaseButton);
            Assert.AreSame(headerRow, nameText.parent);
            Assert.AreSame(headerRow, levelText.parent);
            Assert.AreSame(bodyRow, informationBox.parent);
            Assert.AreSame(bodyRow, effectText.parent);
            Assert.AreSame(bodyRow, valueText.parent);
            Assert.AreSame(bodyRow, costActionGroup.parent);
            Assert.AreSame(costActionGroup, priceText.parent);
            Assert.AreSame(costActionGroup, purchaseButton.parent);

            Type imageType = FindPlayerType("UnityEngine.UI.Image");
            Component cardBackground = card.GetComponent(imageType);
            Assert.IsNotNull(cardBackground);
            Assert.AreEqual(1, card.GetComponents(imageType).Length);
            Color cardBackgroundColor = (Color)imageType
                .GetProperty("color")
                .GetValue(cardBackground);
            Assert.AreEqual(0.392f, cardBackgroundColor.a, 0.001f);

            Component informationImage =
                informationBox.GetComponent(imageType);
            Assert.IsNotNull(informationImage);
            Assert.IsNotNull(
                imageType.GetProperty("sprite").GetValue(informationImage));
            Assert.IsFalse((bool)imageType.GetProperty("raycastTarget")
                .GetValue(informationImage));
            Assert.Less(
                informationBox.GetSiblingIndex(),
                effectText.GetSiblingIndex());
            Assert.Less(
                informationBox.GetSiblingIndex(),
                valueText.GetSiblingIndex());

            RectTransform nameRect = (RectTransform)nameText;
            RectTransform levelRect = (RectTransform)levelText;
            RectTransform infoRect = (RectTransform)informationBox;
            RectTransform effectRect = (RectTransform)effectText;
            RectTransform valueRect = (RectTransform)valueText;
            RectTransform priceRect = (RectTransform)priceText;
            RectTransform buttonRect = (RectTransform)purchaseButton;
            Type layoutElementType =
                FindPlayerType("UnityEngine.UI.LayoutElement");
            Component cardLayout =
                card.GetComponent(layoutElementType);
            Assert.AreEqual(
                360,
                layoutElementType.GetProperty("preferredHeight")
                    .GetValue(cardLayout));
            Assert.AreEqual(Vector2.zero, infoRect.sizeDelta);
            Assert.AreEqual(new Vector2(0, 84), buttonRect.sizeDelta);
            Assert.AreEqual(new Vector2(0, 40), priceRect.sizeDelta);
            Rect parentBounds = cardRect.rect;
            Rect infoBounds = GetRectBoundsInParent(infoRect, cardRect);
            Rect nameBounds = GetRectBoundsInParent(nameRect, cardRect);
            Rect levelBounds = GetRectBoundsInParent(levelRect, cardRect);
            Rect effectBounds = GetRectBoundsInParent(effectRect, cardRect);
            Rect valueBounds = GetRectBoundsInParent(valueRect, cardRect);
            Rect priceBounds = GetRectBoundsInParent(priceRect, cardRect);
            Rect buttonBounds = GetRectBoundsInParent(buttonRect, cardRect);
            Rect actionGroupBounds =
                GetRectBoundsInParent((RectTransform)costActionGroup, cardRect);

            Assert.IsTrue(parentBounds.Contains(infoBounds.min));
            Assert.IsTrue(parentBounds.Contains(infoBounds.max));
            Assert.IsTrue(parentBounds.Contains(nameBounds.min));
            Assert.IsTrue(parentBounds.Contains(nameBounds.max));
            Assert.IsTrue(parentBounds.Contains(levelBounds.min));
            Assert.IsTrue(parentBounds.Contains(levelBounds.max));
            Assert.IsTrue(parentBounds.Contains(priceBounds.min));
            Assert.IsTrue(parentBounds.Contains(priceBounds.max));
            Assert.IsTrue(parentBounds.Contains(buttonBounds.min));
            Assert.IsTrue(parentBounds.Contains(buttonBounds.max));
            Assert.IsTrue(parentBounds.Contains(actionGroupBounds.min));
            Assert.IsTrue(parentBounds.Contains(actionGroupBounds.max));
            Assert.AreEqual(260f, buttonBounds.width, 1f);
            Assert.AreEqual(260f, priceBounds.width, 1f);
            Assert.GreaterOrEqual(
                infoBounds.xMin - parentBounds.xMin,
                24f);
            Assert.GreaterOrEqual(
                infoBounds.yMin - parentBounds.yMin,
                24f);
            Assert.LessOrEqual(
                effectBounds.xMin,
                infoBounds.xMin + 20f);
            Assert.GreaterOrEqual(
                effectBounds.xMax,
                infoBounds.xMax - 20f);
            Assert.AreEqual(
                infoBounds.xMin,
                valueBounds.xMin,
                0.1f,
                "ValueText shares the InformationBox left anchor.");
            Assert.AreEqual(
                infoBounds.xMax,
                valueBounds.xMax,
                0.1f,
                "ValueText shares the InformationBox right anchor.");
            Assert.LessOrEqual(
                effectBounds.yMax,
                infoBounds.yMax - 12f);
            Assert.GreaterOrEqual(
                effectBounds.yMin,
                valueBounds.yMax);
            Assert.GreaterOrEqual(
                valueBounds.yMin,
                infoBounds.yMin + 12f);
            Assert.GreaterOrEqual(
                nameBounds.yMin,
                effectBounds.yMax);
            Assert.AreEqual(nameBounds.center.y, levelBounds.center.y, 0.1f);
            Assert.LessOrEqual(nameBounds.xMax, levelBounds.xMin);
            Assert.GreaterOrEqual(
                buttonBounds.yMax,
                parentBounds.yMin + 40f);
            Assert.AreEqual(
                priceBounds.center.x,
                buttonBounds.center.x,
                0.1f);
            Assert.GreaterOrEqual(
                priceBounds.yMin,
                buttonBounds.yMax);
            Assert.AreEqual(0.05f, priceRect.anchorMin.x);
            Assert.AreEqual(0.95f, priceRect.anchorMax.x);
            Assert.AreEqual(priceRect.anchorMin.x, buttonRect.anchorMin.x);
            Assert.AreEqual(priceRect.anchorMax.x, buttonRect.anchorMax.x);

            cardRect.sizeDelta = new Vector2(820, 360);
            Canvas.ForceUpdateCanvases();
            parentBounds = cardRect.rect;
            infoBounds = GetRectBoundsInParent(infoRect, cardRect);
            nameBounds = GetRectBoundsInParent(nameRect, cardRect);
            levelBounds = GetRectBoundsInParent(levelRect, cardRect);
            priceBounds = GetRectBoundsInParent(priceRect, cardRect);
            buttonBounds = GetRectBoundsInParent(buttonRect, cardRect);
            actionGroupBounds =
                GetRectBoundsInParent((RectTransform)costActionGroup, cardRect);
            Assert.IsTrue(parentBounds.Contains(infoBounds.min));
            Assert.IsTrue(parentBounds.Contains(infoBounds.max));
            Assert.IsTrue(parentBounds.Contains(nameBounds.min));
            Assert.IsTrue(parentBounds.Contains(nameBounds.max));
            Assert.IsTrue(parentBounds.Contains(levelBounds.min));
            Assert.IsTrue(parentBounds.Contains(levelBounds.max));
            Assert.IsTrue(parentBounds.Contains(priceBounds.min));
            Assert.IsTrue(parentBounds.Contains(priceBounds.max));
            Assert.IsTrue(parentBounds.Contains(buttonBounds.min));
            Assert.IsTrue(parentBounds.Contains(buttonBounds.max));
            Assert.IsTrue(parentBounds.Contains(actionGroupBounds.min));
            Assert.IsTrue(parentBounds.Contains(actionGroupBounds.max));
            Assert.AreEqual(priceBounds.center.x, buttonBounds.center.x, 0.1f);
            Assert.Less(buttonBounds.width, 260f);
            Assert.Greater(buttonBounds.width, 230f);

            string sceneText = File.ReadAllText(
                "Assets/_Game/Scenes/MainBakery.unity");
            Match verticalLayout = Regex.Match(
                sceneText,
                @"(?ms)^--- !u!114 &793876650\r?\n(.*?)(?=^--- !u!|\z)");
            Match scrollRect = Regex.Match(
                sceneText,
                @"(?ms)^--- !u!114 &1616590803\r?\n(.*?)(?=^--- !u!|\z)");
            Match scrollPanel = Regex.Match(
                sceneText,
                @"(?ms)^--- !u!114 &1616590806\r?\n(.*?)(?=^--- !u!|\z)");
            Match contentSizeFitter = Regex.Match(
                sceneText,
                @"(?ms)^--- !u!114 &793876649\r?\n(.*?)(?=^--- !u!|\z)");
            Match viewportMask = Regex.Match(
                sceneText,
                @"(?ms)^--- !u!114 &886075659\r?\n(.*?)(?=^--- !u!|\z)");
            MatchCollection cardBackgroundOverrides = Regex.Matches(
                sceneText,
                @"(?ms)target: \{fileID: 6120017046181462189, guid: f57edfc7bd9b74a4c942b4e61bc5d7a6, type: 3\}\r?\n\s+propertyPath: m_Sprite\r?\n\s+value:\s*\r?\n\s+objectReference: \{fileID: 5001796004668800298, guid: bf31d7cdbb4903449b668faaaa28d2d2, type: 3\}");
            Assert.IsTrue(verticalLayout.Success);
            Assert.IsTrue(scrollRect.Success);
            Assert.IsTrue(contentSizeFitter.Success);
            Assert.IsTrue(viewportMask.Success);
            Assert.AreEqual(6, cardBackgroundOverrides.Count);
            StringAssert.Contains("m_ShowMaskGraphic: 0", viewportMask.Value);
            StringAssert.Contains("m_Spacing: 25", verticalLayout.Value);
            StringAssert.Contains("m_Horizontal: 0", scrollRect.Value);
            StringAssert.Contains("m_Vertical: 1", scrollRect.Value);
            StringAssert.Contains("m_VerticalFit: 2", contentSizeFitter.Value);
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(card);
            UnityEngine.Object.DestroyImmediate(layoutParent);
        }
    }

    [Test]
    [Category("CustomUI_UI4_1")]
    public void UpgradeCardTypographyUsesReadableConsistentHierarchy()
    {
        const string prefabPath =
            "Assets/_Game/Prefabs/UI/UpgradeCard.prefab";
        string prefabText = File.ReadAllText(prefabPath);
        long[] textComponentIds =
        {
            1952818838986804043,
            5723161596120778220,
            4523219856188570108,
            9161292831575217704,
            3790715771410225071,
            2443458557906387767,
            6141380343991927113
        };

        foreach (long textComponentId in textComponentIds)
        {
            Match text = Regex.Match(
                prefabText,
                $@"(?ms)^--- !u!114 &{textComponentId}\r?\n(.*?)(?=^--- !u!|\z)");
            Assert.IsTrue(text.Success, $"Missing TMP component {textComponentId}.");
            StringAssert.Contains(
                "guid: 8f586378b4e144a9851e7b34d9b748ee",
                text.Value);
            StringAssert.Contains("m_Material: {fileID: 0}", text.Value);
            StringAssert.Contains("m_enableAutoSizing: 1", text.Value);
            StringAssert.Contains("m_overflowMode: 1", text.Value);
        }

        long[] boldTextIds =
        {
            1952818838986804043,
            5723161596120778220,
            4523219856188570108,
            3790715771410225071,
            2443458557906387767,
            6141380343991927113
        };
        foreach (long textComponentId in boldTextIds)
        {
            Match text = Regex.Match(
                prefabText,
                $@"(?ms)^--- !u!114 &{textComponentId}\r?\n(.*?)(?=^--- !u!|\z)");
            StringAssert.Contains("m_fontWeight: 700", text.Value);
        }

        Match nameText = Regex.Match(
            prefabText,
            @"(?ms)^--- !u!114 &1952818838986804043\r?\n(.*?)(?=^--- !u!|\z)");
        Match levelText = Regex.Match(
            prefabText,
            @"(?ms)^--- !u!114 &5723161596120778220\r?\n(.*?)(?=^--- !u!|\z)");
        Match effectText = Regex.Match(
            prefabText,
            @"(?ms)^--- !u!114 &4523219856188570108\r?\n(.*?)(?=^--- !u!|\z)");
        Match valueText = Regex.Match(
            prefabText,
            @"(?ms)^--- !u!114 &9161292831575217704\r?\n(.*?)(?=^--- !u!|\z)");
        Match priceText = Regex.Match(
            prefabText,
            @"(?ms)^--- !u!114 &3790715771410225071\r?\n(.*?)(?=^--- !u!|\z)");
        Match buttonText = Regex.Match(
            prefabText,
            @"(?ms)^--- !u!114 &2443458557906387767\r?\n(.*?)(?=^--- !u!|\z)");
        Match maxLevelText = Regex.Match(
            prefabText,
            @"(?ms)^--- !u!114 &6141380343991927113\r?\n(.*?)(?=^--- !u!|\z)");
        Match cardController = Regex.Match(
            prefabText,
            @"(?ms)^--- !u!114 &655531135779920435\r?\n(.*?)(?=^--- !u!|\z)");

        Assert.IsTrue(nameText.Success);
        Assert.IsTrue(levelText.Success);
        Assert.IsTrue(effectText.Success);
        Assert.IsTrue(valueText.Success);
        Assert.IsTrue(priceText.Success);
        Assert.IsTrue(buttonText.Success);
        Assert.IsTrue(maxLevelText.Success);
        Assert.IsTrue(cardController.Success);
        StringAssert.Contains("m_fontColor: {r: 1, g: 1, b: 1, a: 1}",
            nameText.Value);
        StringAssert.Contains("m_fontColor: {r: 1, g: 1, b: 1, a: 1}",
            levelText.Value);
        StringAssert.Contains("m_fontSizeMin: 32", nameText.Value);
        StringAssert.Contains("m_fontSizeMax: 36", nameText.Value);
        StringAssert.Contains("m_TextWrappingMode: 1", nameText.Value);
        StringAssert.Contains("m_fontSizeMin: 22", levelText.Value);
        StringAssert.Contains("m_fontSizeMax: 26", levelText.Value);
        StringAssert.Contains("m_TextWrappingMode: 0", levelText.Value);
        StringAssert.Contains("m_fontSizeMin: 20", effectText.Value);
        StringAssert.Contains("m_fontSizeMax: 22", effectText.Value);
        StringAssert.Contains("m_fontColor: {r: 0.24705882, g: 0.12156863, b: 0.3372549, a: 1}",
            effectText.Value);
        StringAssert.Contains("m_margin: {x: 16, y: 6, z: 16, w: 6}",
            effectText.Value);
        StringAssert.Contains("m_fontWeight: 400", valueText.Value);
        StringAssert.Contains("m_fontSizeMin: 20", valueText.Value);
        StringAssert.Contains("m_fontSizeMax: 22", valueText.Value);
        StringAssert.Contains("m_fontColor: {r: 0.24705882, g: 0.12156863, b: 0.3372549, a: 1}",
            valueText.Value);
        StringAssert.Contains("m_margin: {x: 16, y: 8, z: 16, w: 8}",
            valueText.Value);
        StringAssert.Contains("m_fontSizeMin: 20", priceText.Value);
        StringAssert.Contains("m_fontSizeMax: 22", priceText.Value);
        StringAssert.Contains("m_TextWrappingMode: 0", priceText.Value);
        StringAssert.Contains("m_fontColor: {r: 1, g: 0.9607843, b: 0.9019608, a: 1}",
            priceText.Value);
        StringAssert.Contains("m_fontSizeMin: 18", buttonText.Value);
        StringAssert.Contains("m_fontSizeMax: 22", buttonText.Value);
        StringAssert.Contains("m_TextWrappingMode: 0", buttonText.Value);
        StringAssert.Contains("m_fontColor: {r: 1, g: 1, b: 1, a: 1}",
            buttonText.Value);
        StringAssert.Contains("m_fontSizeMin: 20", maxLevelText.Value);
        StringAssert.Contains("m_fontSizeMax: 22", maxLevelText.Value);
        StringAssert.Contains("m_TextWrappingMode: 0", maxLevelText.Value);
        StringAssert.Contains("m_text: MAX LEVEL", maxLevelText.Value);
        StringAssert.Contains("upgradeNameText: {fileID: 1952818838986804043}",
            cardController.Value);
        StringAssert.Contains("levelText: {fileID: 5723161596120778220}",
            cardController.Value);
        StringAssert.Contains("effectLabelText: {fileID: 4523219856188570108}",
            cardController.Value);
        StringAssert.Contains("valueText: {fileID: 9161292831575217704}",
            cardController.Value);
        StringAssert.Contains("priceText: {fileID: 3790715771410225071}",
            cardController.Value);
        StringAssert.Contains("buttonText: {fileID: 2443458557906387767}",
            cardController.Value);

        string sceneText = File.ReadAllText(
            "Assets/_Game/Scenes/MainBakery.unity");
        MatchCollection effectSizeOverrides = Regex.Matches(
            sceneText,
            @"(?ms)target: \{fileID: 4523219856188570108, guid: f57edfc7bd9b74a4c942b4e61bc5d7a6, type: 3\}\r?\n\s+propertyPath: m_fontSize\r?\n\s+value: 22");
        Assert.AreEqual(6, effectSizeOverrides.Count,
            "All six scene cards should use the same effect heading size.");
    }

    [Test]
    [Category("CustomUI_UI3_2")]
    public void ShopUpgradeHeaderAndCloseArePanelAnchoredAboveScrollViewport()
    {
        string sceneText = File.ReadAllText(
            "Assets/_Game/Scenes/MainBakery.unity");
        Match upgradeScreen = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &638951466\r?\n(.*?)(?=^--- !u!|\z)");
        Match scrollView = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &1616590802\r?\n(.*?)(?=^--- !u!|\z)");
        Match viewport = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &886075658\r?\n(.*?)(?=^--- !u!|\z)");
        Match viewportMask = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!114 &886075659\r?\n(.*?)(?=^--- !u!|\z)");
        Match viewportImage = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!114 &886075660\r?\n(.*?)(?=^--- !u!|\z)");
        Match scrollRect = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!114 &1616590803\r?\n(.*?)(?=^--- !u!|\z)");
        Match scrollbar = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &373026617\r?\n(.*?)(?=^--- !u!|\z)");
        Match scrollPanel = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!114 &1616590806\r?\n(.*?)(?=^--- !u!|\z)");
        Match contentTransform = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &793876648\r?\n(.*?)(?=^--- !u!|\z)");
        Match header = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &2065082387\r?\n(.*?)(?=^--- !u!|\z)");
        Match headerPosition = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &2065082387\r?\n.*?m_AnchoredPosition: \{x: -?\d+, y: (-?\d+)\}");
        Match headerSize = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &2065082387\r?\n.*?m_SizeDelta: \{x: 0, y: (\d+)\}");
        Match viewportPosition = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &886075658\r?\n.*?m_AnchoredPosition: \{x: 0, y: (-?\d+)\}");
        Match title = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &466511029\r?\n(.*?)(?=^--- !u!|\z)");
        Match titleText = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!114 &466511030\r?\n(.*?)(?=^--- !u!|\z)");
        Match closeButton = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &2117529018\r?\n(.*?)(?=^--- !u!|\z)");
        Match closeImage = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!114 &2117529020\r?\n(.*?)(?=^--- !u!|\z)");
        MatchCollection headerChildren = Regex.Matches(
            header.Value,
            @"(?m)^  - \{fileID: (-?\d+)\}$");
        MatchCollection scrollChildren = Regex.Matches(
            scrollView.Value,
            @"(?m)^  - \{fileID: (-?\d+)\}$");
        MatchCollection contentChildren = Regex.Matches(
            contentTransform.Value,
            @"(?m)^  - \{fileID: (-?\d+)\}$");

        Assert.IsTrue(upgradeScreen.Success);
        Assert.IsTrue(scrollView.Success);
        Assert.IsTrue(viewport.Success);
        Assert.IsTrue(viewportMask.Success);
        Assert.IsTrue(viewportImage.Success);
        Assert.IsTrue(scrollRect.Success);
        Assert.IsTrue(scrollbar.Success);
        Assert.IsTrue(scrollPanel.Success);
        Assert.IsTrue(header.Success);
        Assert.IsTrue(contentTransform.Success);
        Assert.IsTrue(title.Success);
        Assert.IsTrue(titleText.Success);
        Assert.IsTrue(closeButton.Success);
        Assert.IsTrue(closeImage.Success);

        Assert.IsTrue(Regex.IsMatch(
            upgradeScreen.Value,
            @"m_Children:\r?\n  - \{fileID: 2290013143\}\r?\n  - \{fileID: 1616590802\}"));
        StringAssert.Contains("m_Father: {fileID: 638951466}",
            scrollView.Value);
        StringAssert.Contains("m_Father: {fileID: 1616590802}",
            header.Value);
        Assert.AreEqual(3, scrollChildren.Count);
        Assert.AreEqual("373026617", scrollChildren[0].Groups[1].Value);
        Assert.AreEqual("886075658", scrollChildren[1].Groups[1].Value);
        Assert.AreEqual("2065082387", scrollChildren[2].Groups[1].Value);
        Assert.AreEqual(6, contentChildren.Count,
            "All six upgrade cards must remain in the scroll content.");
        Assert.AreEqual(2, headerChildren.Count);
        Assert.AreEqual("466511029", headerChildren[0].Groups[1].Value);
        Assert.AreEqual("2117529018", headerChildren[1].Groups[1].Value);
        StringAssert.Contains("m_AnchorMin: {x: 0, y: 0}", scrollView.Value);
        StringAssert.Contains("m_AnchorMax: {x: 1, y: 1}", scrollView.Value);
        StringAssert.Contains("m_AnchoredPosition: {x: 0, y: -70}",
            scrollView.Value);
        StringAssert.Contains("m_SizeDelta: {x: -80, y: -220}",
            scrollView.Value);
        StringAssert.Contains("guid: 3de7b6b8a96288744a69bba77fc7e655",
            scrollPanel.Value);
        StringAssert.Contains("m_RaycastTarget: 1", scrollPanel.Value);
        StringAssert.Contains("m_Horizontal: 0", scrollRect.Value);
        StringAssert.Contains("m_Vertical: 1", scrollRect.Value);
        StringAssert.Contains("m_Viewport: {fileID: 886075658}",
            scrollRect.Value);
        StringAssert.Contains("m_Content: {fileID: 793876648}",
            scrollRect.Value);
        StringAssert.Contains("m_VerticalScrollbar: {fileID: 373026618}",
            scrollRect.Value);
        StringAssert.Contains("m_AnchorMin: {x: 0, y: 0}",
            viewport.Value);
        StringAssert.Contains("m_AnchorMax: {x: 1, y: 1}",
            viewport.Value);
        StringAssert.Contains("m_AnchoredPosition: {x: 0, y: -230}",
            viewport.Value);
        StringAssert.Contains("m_SizeDelta: {x: -20, y: -230}",
            viewport.Value);
        StringAssert.Contains("m_Pivot: {x: 0, y: 1}", viewport.Value);
        StringAssert.Contains("m_Father: {fileID: 1616590802}",
            viewport.Value);
        StringAssert.Contains("m_ShowMaskGraphic: 0", viewportMask.Value);
        StringAssert.Contains("m_Enabled: 1", viewportMask.Value);
        StringAssert.Contains(
            "UnityEngine.UI::UnityEngine.UI.Image",
            viewportImage.Value);
        StringAssert.Contains("m_Enabled: 1", viewportImage.Value);
        StringAssert.Contains("m_AnchorMin: {x: 1, y: 0}",
            scrollbar.Value);
        StringAssert.Contains("m_AnchorMax: {x: 1, y: 1}",
            scrollbar.Value);
        StringAssert.Contains("m_AnchoredPosition: {x: 0, y: -230}",
            scrollbar.Value);
        StringAssert.Contains("m_SizeDelta: {x: 20, y: -230}",
            scrollbar.Value);

        StringAssert.Contains("m_AnchorMin: {x: 0, y: 1}", header.Value);
        StringAssert.Contains("m_AnchorMax: {x: 1, y: 1}", header.Value);
        StringAssert.Contains("m_AnchoredPosition: {x: 0, y: 0}",
            header.Value);
        StringAssert.Contains("m_SizeDelta: {x: 0, y: 220}", header.Value);
        StringAssert.Contains("m_Pivot: {x: 0.5, y: 1}", header.Value);
        Assert.IsTrue(headerPosition.Success);
        Assert.IsTrue(headerSize.Success);
        Assert.IsTrue(viewportPosition.Success);
        int headerBottomOffset = int.Parse(headerPosition.Groups[1].Value)
            - int.Parse(headerSize.Groups[1].Value);
        int viewportTopOffset = int.Parse(viewportPosition.Groups[1].Value);
        Assert.LessOrEqual(viewportTopOffset, headerBottomOffset - 10,
            "The viewport must start at least 10 units below the fixed header.");
        StringAssert.Contains("m_Father: {fileID: 2065082387}",
            title.Value);
        StringAssert.Contains("m_AnchorMin: {x: 0.5, y: 1}", title.Value);
        StringAssert.Contains("m_AnchorMax: {x: 0.5, y: 1}", title.Value);
        StringAssert.Contains("m_AnchoredPosition: {x: 0, y: -145}",
            title.Value);
        StringAssert.Contains("m_SizeDelta: {x: 600, y: 80}", title.Value);
        StringAssert.Contains("m_text: SHOP UPGRADE", titleText.Value);
        StringAssert.Contains("m_RaycastTarget: 0", titleText.Value);
        StringAssert.Contains(
            "m_fontColor: {r: 0.2, g: 0.07, b: 0.3, a: 1}",
            titleText.Value);
        StringAssert.Contains("m_enableAutoSizing: 1", titleText.Value);
        StringAssert.Contains("m_fontSizeMin: 36", titleText.Value);
        StringAssert.Contains("m_fontSizeMax: 48", titleText.Value);

        StringAssert.Contains("m_Father: {fileID: 2065082387}",
            closeButton.Value);
        StringAssert.Contains("m_AnchorMin: {x: 1, y: 1}",
            closeButton.Value);
        StringAssert.Contains("m_AnchorMax: {x: 1, y: 1}",
            closeButton.Value);
        StringAssert.Contains("m_AnchoredPosition: {x: -42, y: -35}",
            closeButton.Value);
        StringAssert.Contains("m_SizeDelta: {x: 100, y: 100}",
            closeButton.Value);
        StringAssert.Contains("guid: de114e40e1617b345a123664e4f16228",
            closeImage.Value);
        StringAssert.Contains("m_RaycastTarget: 1", closeImage.Value);
        Assert.AreEqual(32f, 40f - (50f - 42f));
        Assert.AreEqual(165f, 180f - (50f - 35f));
        Assert.Less(300f, 500f - 42f - 50f);

        Match upgradeScreenController = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!114 &910226780\r?\n(.*?)(?=^--- !u!|\z)");
        Assert.IsTrue(upgradeScreenController.Success);
        StringAssert.Contains("closeButton: {fileID: 2117529019}",
            upgradeScreenController.Value);
    }

    [Test]
    [Category("CustomUI_UI3_3_2")]
    public void ShopUpgradeModalBlockerCoversScreenBehindInteractivePanel()
    {
        string sceneText = File.ReadAllText(
            "Assets/_Game/Scenes/MainBakery.unity");
        Match upgradeScreen = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &638951466\r?\n(.*?)(?=^--- !u!|\z)");
        Match blockerObject = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!1 &2290013142\r?\n(.*?)(?=^--- !u!|\z)");
        Match blockerTransform = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &2290013143\r?\n(.*?)(?=^--- !u!|\z)");
        Match blockerImage = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!114 &2290013145\r?\n(.*?)(?=^--- !u!|\z)");
        Match scrollView = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &1616590802\r?\n(.*?)(?=^--- !u!|\z)");
        Match scrollRect = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!114 &1616590803\r?\n(.*?)(?=^--- !u!|\z)");
        Match scrollbar = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &373026617\r?\n(.*?)(?=^--- !u!|\z)");
        Match scrollbarControl = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!114 &373026618\r?\n(.*?)(?=^--- !u!|\z)");
        Match viewport = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &886075658\r?\n(.*?)(?=^--- !u!|\z)");
        Match content = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &793876648\r?\n(.*?)(?=^--- !u!|\z)");
        Match closeButton = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!114 &2117529019\r?\n(.*?)(?=^--- !u!|\z)");
        Match upgradeScreenController = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!114 &910226780\r?\n(.*?)(?=^--- !u!|\z)");

        Assert.IsTrue(upgradeScreen.Success);
        Assert.IsTrue(blockerObject.Success);
        Assert.IsTrue(blockerTransform.Success);
        Assert.IsTrue(blockerImage.Success);
        Assert.IsTrue(scrollView.Success);
        Assert.IsTrue(scrollRect.Success);
        Assert.IsTrue(scrollbar.Success);
        Assert.IsTrue(scrollbarControl.Success);
        Assert.IsTrue(viewport.Success);
        Assert.IsTrue(content.Success);
        Assert.IsTrue(closeButton.Success);
        Assert.IsTrue(upgradeScreenController.Success);

        MatchCollection rootChildren = Regex.Matches(
            upgradeScreen.Value,
            @"(?m)^  - \{fileID: (-?\d+)\}$");
        MatchCollection contentChildren = Regex.Matches(
            content.Value,
            @"(?m)^  - \{fileID: (-?\d+)\}$");
        Assert.AreEqual(2, rootChildren.Count);
        Assert.AreEqual("2290013143", rootChildren[0].Groups[1].Value,
            "The blocker must be the first child, behind the panel.");
        Assert.AreEqual("1616590802", rootChildren[1].Groups[1].Value);
        StringAssert.Contains("m_Name: ModalInputBlocker",
            blockerObject.Value);
        StringAssert.Contains("m_IsActive: 1", blockerObject.Value);
        StringAssert.Contains("m_Father: {fileID: 638951466}",
            blockerTransform.Value);
        StringAssert.Contains("m_AnchorMin: {x: 0, y: 0}",
            blockerTransform.Value);
        StringAssert.Contains("m_AnchorMax: {x: 1, y: 1}",
            blockerTransform.Value);
        StringAssert.Contains("m_AnchoredPosition: {x: 0, y: 0}",
            blockerTransform.Value);
        StringAssert.Contains("m_SizeDelta: {x: 0, y: 0}",
            blockerTransform.Value);
        StringAssert.Contains("m_Enabled: 1", blockerImage.Value);
        StringAssert.Contains("m_Color: {r: 1, g: 1, b: 1, a: 0}",
            blockerImage.Value);
        StringAssert.Contains("m_RaycastTarget: 1", blockerImage.Value);

        StringAssert.Contains("m_Father: {fileID: 638951466}",
            scrollView.Value);
        StringAssert.Contains("m_Horizontal: 0", scrollRect.Value);
        StringAssert.Contains("m_Vertical: 1", scrollRect.Value);
        StringAssert.Contains("m_Viewport: {fileID: 886075658}",
            scrollRect.Value);
        StringAssert.Contains("m_Content: {fileID: 793876648}",
            scrollRect.Value);
        StringAssert.Contains("m_Interactable: 1", scrollbarControl.Value);
        StringAssert.Contains("m_Interactable: 1", closeButton.Value);
        StringAssert.Contains("upgradeScreen: {fileID: 638951465}",
            upgradeScreenController.Value,
            "The controller toggles the blocker with its parent screen.");
        StringAssert.Contains("closeButton: {fileID: 2117529019}",
            upgradeScreenController.Value);
        StringAssert.Contains("m_Father: {fileID: 373026617}",
            viewport.Value,
            "Preserve the existing Viewport-under-Scrollbar hierarchy.");
        Assert.AreEqual(6, contentChildren.Count,
            "All six upgrade cards must remain in the scroll content.");
    }

    private static Rect GetRectBoundsInParent(
        RectTransform target,
        RectTransform parent)
    {
        Vector3[] corners = new Vector3[4];
        target.GetWorldCorners(corners);
        Vector3 min = parent.InverseTransformPoint(corners[0]);
        Vector3 max = min;

        for (int i = 1; i < corners.Length; i++)
        {
            Vector3 point = parent.InverseTransformPoint(corners[i]);
            min = Vector3.Min(min, point);
            max = Vector3.Max(max, point);
        }

        return Rect.MinMaxRect(min.x, min.y, max.x, max.y);
    }

    [Test]
    public void SupportUpgradeChargesOnceAndRemainsPurchasedAcrossRebirth()
    {
        var setup = CreateProgressionPurchaseTestSetup();
        var managerObject = new GameObject("Support upgrade purchase test");
        managerObject.SetActive(false);
        Type progressionType = setup.Progression.GetType();
        PropertyInfo instanceProperty = progressionType.GetProperty(
            "Instance",
            BindingFlags.Public | BindingFlags.Static);
        object previousInstance = instanceProperty.GetValue(null);
        object purchaseManager = managerObject.AddComponent(
            FindPlayerType("UpgradePurchaseManager"));
        SetPrivateField(purchaseManager, "progressionManager", setup.Progression);
        SetPrivateField(purchaseManager, "economyManager", setup.Economy);
        SetPrivateStaticProperty(
            progressionType,
            "Instance",
            setup.Progression);
        managerObject.SetActive(true);

        try
        {
            MethodInfo restoreRebirth = setup.Progression.GetType()
                .GetMethod("RestoreRebirthProgression");
            Assert.IsTrue((bool)restoreRebirth.Invoke(
                setup.Progression, new object[] { 2, 0, false }));

            MethodInfo purchase = purchaseManager.GetType()
                .GetMethod("TryPurchaseUpgrade");
            object boardSpace = Enum.Parse(
                FindPlayerType("UpgradeType"), "BoardSpace");
            Assert.IsTrue((bool)purchase.Invoke(
                purchaseManager, new[] { boardSpace }));
            Assert.AreEqual(
                99900,
                setup.Economy.GetType()
                    .GetProperty("CurrentCash").GetValue(setup.Economy));
            Assert.IsFalse((bool)purchase.Invoke(
                purchaseManager, new[] { boardSpace }),
                "A second purchase must respect the next level's R5 gate.");
            Assert.AreEqual(
                99900,
                setup.Economy.GetType()
                    .GetProperty("CurrentCash").GetValue(setup.Economy));

            Assert.IsTrue((bool)restoreRebirth.Invoke(
                setup.Progression, new object[] { 3, 0, false }));
            Assert.AreEqual(
                2,
                setup.Progression.GetType()
                    .GetProperty("BoardSpaceLevel").GetValue(setup.Progression));
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(managerObject);
            SetPrivateStaticProperty(
                progressionType,
                "Instance",
                previousInstance);
            DestroyProgressionPurchaseTestSetup(setup);
        }
    }

    [Test]
    [Category("Step5C.2")]
    public void LuckPurchasesUseApprovedCostsMultipliersAndStopAtMaximum()
    {
        var setup = CreateProgressionPurchaseTestSetup();
        var managerObject = new GameObject("Luck upgrade purchase test");
        managerObject.SetActive(false);
        object purchaseManager = managerObject.AddComponent(
            FindPlayerType("UpgradePurchaseManager"));
        SetPrivateField(purchaseManager, "progressionManager", setup.Progression);
        SetPrivateField(purchaseManager, "economyManager", setup.Economy);
        managerObject.SetActive(true);

        try
        {
            Type upgradeType = FindPlayerType("UpgradeType");
            object luckType = Enum.Parse(upgradeType, "Luck");
            object definition =
                setup.Progression.GetType().GetMethod("GetDefinition")
                    .Invoke(setup.Progression, new[] { luckType });
            int[] costs = { 600, 3500, 20000 };
            float[] multipliers = { 1.25f, 1.5f, 2f };

            Assert.AreEqual(1f, (float)setup.Progression.GetType()
                .GetProperty("LuckMultiplier").GetValue(setup.Progression));
            for (int i = 0; i < costs.Length; i++)
            {
                object next = definition.GetType().GetMethod("GetLevel")
                    .Invoke(definition, new object[] { i + 2 });
                Assert.AreEqual(costs[i], next.GetType().GetProperty("UpgradeCost")
                    .GetValue(next));
                Assert.AreEqual(multipliers[i], next.GetType()
                    .GetProperty("FloatValue").GetValue(next));
                int cashBefore = (int)setup.Economy.GetType()
                    .GetProperty("CurrentCash").GetValue(setup.Economy);

                Assert.IsTrue((bool)purchaseManager.GetType()
                    .GetMethod("TryPurchaseUpgrade")
                    .Invoke(purchaseManager, new[] { luckType }));
                Assert.AreEqual(cashBefore - costs[i],
                    setup.Economy.GetType().GetProperty("CurrentCash")
                        .GetValue(setup.Economy));
                Assert.AreEqual(i + 2, setup.Progression.GetType()
                    .GetProperty("LuckLevel").GetValue(setup.Progression));
                Assert.AreEqual(multipliers[i], (float)setup.Progression.GetType()
                    .GetProperty("LuckMultiplier").GetValue(setup.Progression));
            }

            int cashAtMax = (int)setup.Economy.GetType()
                .GetProperty("CurrentCash").GetValue(setup.Economy);
            Assert.IsTrue((bool)purchaseManager.GetType()
                .GetMethod("IsMaxLevel")
                .Invoke(purchaseManager, new[] { luckType }));
            Assert.IsFalse((bool)purchaseManager.GetType()
                .GetMethod("CanPurchaseUpgrade")
                .Invoke(purchaseManager, new[] { luckType }));
            Assert.IsFalse((bool)purchaseManager.GetType()
                .GetMethod("TryPurchaseUpgrade")
                .Invoke(purchaseManager, new[] { luckType }));
            Assert.AreEqual(cashAtMax, setup.Economy.GetType()
                .GetProperty("CurrentCash").GetValue(setup.Economy));

            Assert.IsTrue((bool)setup.Progression.GetType()
                .GetMethod("RestoreRebirthProgression")
                .Invoke(setup.Progression, new object[] { 1, 0, false }));
            Assert.AreEqual(4, setup.Progression.GetType()
                .GetProperty("LuckLevel").GetValue(setup.Progression),
                "Luck is permanent across Rebirth.");
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(managerObject);
            DestroyProgressionPurchaseTestSetup(setup);
        }
    }

    [Test]
    [Category("Step5C.2")]
    public void LuckScalesBonusChanceWithoutChangingPoolTierSelection()
    {
        Type spawnerType = FindPlayerType("DessertSpawner");
        MethodInfo effectiveChance = spawnerType.GetMethod(
            "GetEffectiveBonusChancePerHundredThousand",
            BindingFlags.Public | BindingFlags.Static);
        MethodInfo shouldSpawn = spawnerType.GetMethod(
            "ShouldSpawnBonus",
            BindingFlags.Public | BindingFlags.Static,
            null,
            new[] { typeof(int), typeof(float), typeof(int) },
            null);
        MethodInfo selectBonus = spawnerType.GetMethod(
            "TryGetBonusDessertDefinition",
            BindingFlags.Public | BindingFlags.Static);

        Assert.AreEqual(500,
            effectiveChance.Invoke(null, new object[] { 2, 1f }));
        Assert.AreEqual(625,
            effectiveChance.Invoke(null, new object[] { 2, 1.25f }));
        Assert.AreEqual(1200,
            effectiveChance.Invoke(null, new object[] { 3, 1.5f }));
        Assert.AreEqual(4000,
            effectiveChance.Invoke(null, new object[] { 6, 2f }));
        Assert.IsTrue((bool)shouldSpawn.Invoke(
            null,
            new object[] { 2, 1.25f, 624 }));
        Assert.IsFalse((bool)shouldSpawn.Invoke(
            null,
            new object[] { 2, 1.25f, 625 }));

        Array definitions = LoadDessertDefinitions();
        object[] first = { definitions, "P1", 6, 30, 27, null };
        object[] second = { definitions, "P1", 6, 30, 27, null };
        Assert.IsTrue((bool)selectBonus.Invoke(null, first));
        Assert.IsTrue((bool)selectBonus.Invoke(null, second));
        Assert.AreEqual(
            GetPropertyValue(first[5], "Tier"),
            GetPropertyValue(second[5], "Tier"),
            "Luck must not alter deterministic bonus tier selection.");
    }

    [Test]
    [Category("Step5D")]
    public void BoardDessertCanBeRecycledOnceWithoutRewardsOrMilestoneRegression()
    {
        RecycleFixture fixture = CreateRecycleFixture(false);
        int movementEvents = 0;
        Action countMovement = () => movementEvents++;
        EventInfo movementEvent = FindPlayerType("GameplayEvents")
            .GetEvent("DessertMoved", BindingFlags.Static | BindingFlags.Public);
        movementEvent.AddEventHandler(null, countMovement);
        Type rebirthStateType = FindPlayerType("RebirthProgressionState");
        object rebirthState = Activator.CreateInstance(rebirthStateType);
        rebirthStateType.GetMethod("RegisterCreatedTier")
            .Invoke(rebirthState, new object[] { 12 });

        try
        {
            Assert.AreEqual("Board",
                GetPropertyValue(fixture.Dessert, "LocationType").ToString());
            Assert.AreSame(fixture.Cell,
                GetPropertyValue(fixture.Dessert, "CurrentCell"));
            Assert.AreSame(fixture.Cell,
                fixture.DragHandler.GetType()
                    .GetField("originCell",
                        BindingFlags.Instance | BindingFlags.NonPublic)
                    .GetValue(fixture.DragHandler));
            MethodInfo recycle = fixture.DragHandler.GetType().GetMethod(
                "TryRecycleDraggedDessert",
                BindingFlags.Instance | BindingFlags.NonPublic);
            Assert.IsTrue((bool)recycle.Invoke(fixture.DragHandler, null));
            Assert.IsNull(GetPropertyValue(fixture.Cell, "CurrentDessert"));
            Assert.IsNull(GetPropertyValue(fixture.Dessert, "CurrentCell"));
            Assert.IsFalse((bool)recycle.Invoke(fixture.DragHandler, null),
                "A repeated removal must be rejected.");
            Assert.AreEqual(0, movementEvents,
                "Recycling is not a rewarded move.");
            Assert.AreEqual(12, GetPropertyValue(
                    rebirthState, "HighestTierCreatedThisRun"),
                "Recycling cannot undo a created-tier milestone.");
        }
        finally
        {
            movementEvent.RemoveEventHandler(null, countMovement);
            DestroyRecycleFixture(fixture);
        }
    }

    [Test]
    [Category("Step5D")]
    public void ShelfDessertCanBeRecycledOnce()
    {
        RecycleFixture fixture = CreateRecycleFixture(true);

        try
        {
            Assert.AreEqual("Shelf",
                GetPropertyValue(fixture.Dessert, "LocationType").ToString());
            Assert.AreSame(fixture.Slot,
                GetPropertyValue(fixture.Dessert, "CurrentShelfSlot"));
            Assert.AreSame(fixture.Slot,
                fixture.DragHandler.GetType()
                    .GetField("originShelfSlot",
                        BindingFlags.Instance | BindingFlags.NonPublic)
                    .GetValue(fixture.DragHandler));
            MethodInfo recycle = fixture.DragHandler.GetType().GetMethod(
                "TryRecycleDraggedDessert",
                BindingFlags.Instance | BindingFlags.NonPublic);
            Assert.IsTrue((bool)recycle.Invoke(fixture.DragHandler, null));
            Assert.IsNull(GetPropertyValue(fixture.Slot, "CurrentDessert"));
            Assert.IsNull(GetPropertyValue(fixture.Dessert, "CurrentShelfSlot"));
            Assert.IsFalse((bool)recycle.Invoke(fixture.DragHandler, null));
        }
        finally
        {
            DestroyRecycleFixture(fixture);
        }
    }

    [Test]
    [Category("Step5D")]
    public void DroppingOutsideRecycleBinPreservesBoardDessert()
    {
        RecycleFixture fixture = CreateRecycleFixture(false);

        try
        {
            SetPrivateField(fixture.DragHandler, "isDragging", true);
            Vector2 outsideBin = GetRecycleBinScreenPoint(fixture) +
                                 new Vector2(1000, 1000);
            fixture.DragHandler.GetType().GetMethod("OnPointerUp").Invoke(
                fixture.DragHandler,
                new object[]
                {
                    new UnityEngine.EventSystems.PointerEventData(null)
                    {
                        position = outsideBin
                    }
                });

            Assert.AreSame(fixture.Dessert,
                GetPropertyValue(fixture.Cell, "CurrentDessert"));
            Assert.AreSame(fixture.Cell,
                GetPropertyValue(fixture.Dessert, "CurrentCell"));
        }
        finally
        {
            DestroyRecycleFixture(fixture);
        }
    }

    [Test]
    [Category("Step5D")]
    public void DroppingBoardDessertOnRecycleBinRemovesIt()
    {
        RecycleFixture fixture = CreateRecycleFixture(false);

        try
        {
            SetPrivateField(fixture.DragHandler, "isDragging", true);
            Vector2 screenPoint = GetRecycleBinScreenPoint(fixture);
            Canvas canvas = ((Component)fixture.Target)
                .GetComponentInParent<Canvas>();
            Camera eventCamera = canvas.renderMode == RenderMode.ScreenSpaceOverlay
                ? null
                : canvas.worldCamera;
            Assert.IsFalse(RectTransformUtility.RectangleContainsScreenPoint(
                fixture.ExcludedArea,
                screenPoint,
                eventCamera),
                "The test pointer must be outside the excluded Home area.");
            Assert.IsTrue((bool)fixture.Target.GetType()
                .GetMethod("ContainsScreenPoint")
                .Invoke(fixture.Target, new object[]
                {
                    screenPoint
                }), "The pointer should be inside the recycle bin.");
            fixture.DragHandler.GetType().GetMethod("OnPointerUp").Invoke(
                fixture.DragHandler,
                new object[]
                {
                    new UnityEngine.EventSystems.PointerEventData(null)
                    {
                        position = screenPoint
                    }
                });

            Assert.IsNull(GetPropertyValue(fixture.Cell, "CurrentDessert"));
            Assert.IsTrue((UnityEngine.Object)fixture.Dessert == null);
        }
        finally
        {
            DestroyRecycleFixture(fixture);
        }
    }

    [Test]
    [Category("Step6B.2")]
    public void RecycleTargetExcludesHomeAreaEvenWhenRectanglesOverlap()
    {
        RecycleFixture fixture = CreateRecycleFixture(false);
        try
        {
            fixture.ExcludedArea.anchoredPosition = Vector2.zero;
            Vector2 homePoint = GetRecycleBinScreenPoint(fixture);
            Assert.IsFalse((bool)fixture.Target.GetType()
                .GetMethod("ContainsScreenPoint")
                .Invoke(fixture.Target, new object[] { homePoint }),
                "The Home button region takes priority over recycling.");

            SetPrivateField(fixture.DragHandler, "isDragging", true);
            fixture.DragHandler.GetType().GetMethod("OnPointerUp").Invoke(
                fixture.DragHandler,
                new object[]
                {
                    new UnityEngine.EventSystems.PointerEventData(null)
                    {
                        position = homePoint
                    }
                });

            Assert.AreSame(fixture.Dessert,
                GetPropertyValue(fixture.Cell, "CurrentDessert"),
                "Releasing over Home must not remove the Board dessert.");
            Assert.AreSame(fixture.Cell,
                GetPropertyValue(fixture.Dessert, "CurrentCell"));
        }
        finally
        {
            DestroyRecycleFixture(fixture);
        }
    }

    [Test]
    [Category("Step6B.2")]
    public void RightAnchoredBottomControlsStaySeparatedAcrossPortraitWidths()
    {
        GameObject canvasObject = new GameObject(
            "Bottom layout test canvas",
            typeof(RectTransform),
            typeof(Canvas));
        var createdObjects = new List<GameObject> { canvasObject };
        try
        {
            RectTransform canvasRect = canvasObject.GetComponent<RectTransform>();
            var navigationObject = new GameObject(
                "BottomNavigation",
                typeof(RectTransform));
            createdObjects.Add(navigationObject);
            RectTransform navigation = navigationObject.GetComponent<RectTransform>();
            navigation.SetParent(canvasRect, false);
            navigation.anchorMin = new Vector2(0, 0);
            navigation.anchorMax = new Vector2(1, 0);
            navigation.anchoredPosition = new Vector2(0, 50);
            navigation.sizeDelta = new Vector2(0, 100);

            RectTransform home = CreateLayoutRect(
                navigation,
                "HomeButton",
                new Vector2(1, 0),
                new Vector2(1, 0),
                new Vector2(-34.4f, 11.9f),
                new Vector2(125, 125),
                new Vector2(1, 0),
                createdObjects);
            RectTransform recycle = CreateLayoutRect(
                navigation,
                "RecycleBinDropTarget",
                new Vector2(1, 0),
                new Vector2(1, 0),
                new Vector2(-180, 11.9f),
                new Vector2(170, 78),
                new Vector2(1, 0),
                createdObjects);

            foreach (float width in new[] { 1080f, 1170f, 1200f })
            {
                canvasRect.sizeDelta = new Vector2(width, 1920);
                Canvas.ForceUpdateCanvases();
                Assert.IsFalse(RectanglesOverlap(home, recycle),
                    $"Home and recycle overlap at portrait width {width}.");
            }
        }
        finally
        {
            for (int i = createdObjects.Count - 1; i >= 0; i--)
                if (createdObjects[i] != null)
                    UnityEngine.Object.DestroyImmediate(createdObjects[i]);
        }
    }

    [Test]
    [Category("Step6B.3")]
    public void SafeAreaAnchorConversionFitsTopAndBottomUiIntoCanvasPixelRect()
    {
        Rect canvasRect = new Rect(100, 50, 1000, 1800);
        Rect safeArea = new Rect(120, 90, 950, 1700);

        Vector4 topBarAnchors = CalculateSafeAreaAnchors(
            new Vector2(0, 1),
            new Vector2(1, 1),
            safeArea,
            canvasRect);
        Assert.That(topBarAnchors.x, Is.EqualTo(0.02f).Within(0.0001f));
        Assert.That(topBarAnchors.y, Is.EqualTo(0.9666667f).Within(0.0001f));
        Assert.That(topBarAnchors.z, Is.EqualTo(0.97f).Within(0.0001f));
        Assert.That(topBarAnchors.w, Is.EqualTo(0.9666667f).Within(0.0001f));

        Vector4 bottomNavigationAnchors =
            CalculateSafeAreaAnchors(
                new Vector2(0, 0),
                new Vector2(1, 0),
                safeArea,
                canvasRect);
        Assert.That(bottomNavigationAnchors.x,
            Is.EqualTo(topBarAnchors.x).Within(0.0001f));
        Assert.That(bottomNavigationAnchors.y,
            Is.EqualTo(0.0222222f).Within(0.0001f));
        Assert.That(bottomNavigationAnchors.z,
            Is.EqualTo(topBarAnchors.z).Within(0.0001f));
        Assert.That(bottomNavigationAnchors.w,
            Is.EqualTo(0.0222222f).Within(0.0001f));
    }

    [Test]
    [Category("Step6C.2")]
    public void CashDisplayTopRightRectFitsWithinSafeArea()
    {
        const float width = 200f;
        const float height = 50f;
        Vector2 offset = new Vector2(-100.25f, -25.45f);
        Rect canvasRect = new Rect(0, 0, 1080, 1920);
        Rect[] safeAreas =
        {
            new Rect(0, 48, 1080, 1824),
            new Rect(0, 96, 1080, 1740),
            new Rect(0, 112, 1080, 1720)
        };

        foreach (Rect safeArea in safeAreas)
        {
            Vector4 anchors = CalculateSafeAreaAnchors(
                Vector2.one,
                Vector2.one,
                safeArea,
                canvasRect);
            Vector2 safeTopRight = new Vector2(
                canvasRect.xMin + anchors.x * canvasRect.width,
                canvasRect.yMin + anchors.y * canvasRect.height);
            Rect cashBounds = new Rect(
                safeTopRight.x + offset.x - width * 0.5f,
                safeTopRight.y + offset.y - height * 0.5f,
                width,
                height);

            Assert.GreaterOrEqual(cashBounds.xMin, safeArea.xMin);
            Assert.LessOrEqual(cashBounds.xMax, safeArea.xMax);
            Assert.GreaterOrEqual(cashBounds.yMin, safeArea.yMin);
            Assert.LessOrEqual(cashBounds.yMax, safeArea.yMax);
        }
    }

    [Test]
    [Category("Step6C.5.2")]
    public void RebirthEntryButtonFitsPortraitSafeAreas()
    {
        string sceneText = File.ReadAllText(
            "Assets/_Game/Scenes/Game.unity");
        Match buttonObject = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!1 &915782262\r?\n(.*?)(?=^--- !u!|\z)");
        Match buttonTransform = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &915782263\r?\n(.*?)(?=^--- !u!|\z)");
        Match safeAreaFitter = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!114 &2200000006\r?\n(.*?)(?=^--- !u!|\z)");

        Assert.IsTrue(buttonObject.Success);
        Assert.IsTrue(buttonTransform.Success);
        Assert.IsTrue(safeAreaFitter.Success);
        StringAssert.Contains(
            "- component: {fileID: 2200000006}",
            buttonObject.Value);
        StringAssert.Contains(
            "m_EditorClassIdentifier: Assembly-CSharp::SafeAreaFitter",
            safeAreaFitter.Value);
        StringAssert.Contains(
            "guid: a64a846354a844edba8d64814a12c990",
            safeAreaFitter.Value);
        StringAssert.Contains(
            "m_Father: {fileID: 1297646555}",
            buttonTransform.Value);

        Vector2 anchorMin = ReadSceneVector2(
            buttonTransform.Value,
            "m_AnchorMin");
        Vector2 anchorMax = ReadSceneVector2(
            buttonTransform.Value,
            "m_AnchorMax");
        Vector2 offset = ReadSceneVector2(
            buttonTransform.Value,
            "m_AnchoredPosition");
        Vector2 size = ReadSceneVector2(
            buttonTransform.Value,
            "m_SizeDelta");
        Assert.AreEqual(new Vector2(0.5f, 0f), anchorMin);
        Assert.AreEqual(anchorMin, anchorMax);

        float[] screenHeights = { 1920f, 2340f, 2400f };
        float[] bottomInsets = { 48f, 70f, 80f };
        float[] topInsets = { 48f, 70f, 80f };
        for (int i = 0; i < screenHeights.Length; i++)
        {
            float screenHeight = screenHeights[i];
            Rect canvasRect = new Rect(0f, 0f, 1080f, screenHeight);
            Rect safeArea = new Rect(
                0f,
                bottomInsets[i],
                1080f,
                screenHeight - bottomInsets[i] - topInsets[i]);
            Vector4 anchors = CalculateSafeAreaAnchors(
                anchorMin,
                anchorMax,
                safeArea,
                canvasRect);
            float scale = Mathf.Sqrt(screenHeight / 1920f);
            Vector2 safeAnchor = new Vector2(
                canvasRect.xMin + anchors.x * canvasRect.width,
                canvasRect.yMin + anchors.y * canvasRect.height);
            Rect buttonBounds = new Rect(
                safeAnchor.x + offset.x * scale - size.x * scale * 0.5f,
                safeAnchor.y + offset.y * scale,
                size.x * scale,
                size.y * scale);

            Assert.GreaterOrEqual(buttonBounds.xMin, safeArea.xMin);
            Assert.LessOrEqual(buttonBounds.xMax, safeArea.xMax);
            Assert.GreaterOrEqual(buttonBounds.yMin, safeArea.yMin);
            Assert.LessOrEqual(buttonBounds.yMax, safeArea.yMax);
        }
    }

    [Test]
    [Category("Step6C.5.3")]
    public void UpgradeScrollViewIsVerticalOnlyWithStretchWidthContent()
    {
        string sceneText = File.ReadAllText(
            "Assets/_Game/Scenes/MainBakery.unity");
        Match scrollRect = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!114 &1616590803\r?\n(.*?)(?=^--- !u!|\z)");
        Match contentTransform = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &793876648\r?\n(.*?)(?=^--- !u!|\z)");
        Match contentSizeFitter = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!114 &793876649\r?\n(.*?)(?=^--- !u!|\z)");
        Match verticalLayout = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!114 &793876650\r?\n(.*?)(?=^--- !u!|\z)");
        Match viewportTransform = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &886075658\r?\n(.*?)(?=^--- !u!|\z)");
        Match verticalScrollbarTransform = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &373026617\r?\n(.*?)(?=^--- !u!|\z)");

        Assert.IsTrue(scrollRect.Success);
        Assert.IsTrue(contentTransform.Success);
        Assert.IsTrue(contentSizeFitter.Success);
        Assert.IsTrue(verticalLayout.Success);
        Assert.IsTrue(viewportTransform.Success);
        Assert.IsTrue(verticalScrollbarTransform.Success);
        StringAssert.Contains("m_Horizontal: 0", scrollRect.Value);
        StringAssert.Contains("m_Vertical: 1", scrollRect.Value);
        StringAssert.Contains("m_Content: {fileID: 793876648}", scrollRect.Value);
        StringAssert.Contains("m_Viewport: {fileID: 886075658}", scrollRect.Value);
        StringAssert.Contains(
            "m_VerticalScrollbar: {fileID: 373026618}",
            scrollRect.Value);
        StringAssert.Contains("m_HorizontalFit: 0", contentSizeFitter.Value);
        StringAssert.Contains("m_VerticalFit: 2", contentSizeFitter.Value);
        StringAssert.Contains(
            "UnityEngine.UI::UnityEngine.UI.VerticalLayoutGroup",
            verticalLayout.Value);
        StringAssert.Contains("m_ChildForceExpandWidth: 1", verticalLayout.Value);
        StringAssert.Contains("m_ChildControlWidth: 1", verticalLayout.Value);
        StringAssert.Contains("m_Top: 20", verticalLayout.Value);
        StringAssert.Contains("m_AnchorMin: {x: 0, y: 1}", contentTransform.Value);
        StringAssert.Contains("m_AnchorMax: {x: 1, y: 1}", contentTransform.Value);
        StringAssert.Contains("m_Father: {fileID: 886075658}", contentTransform.Value);
        StringAssert.Contains("m_AnchorMin: {x: 0, y: 0}", viewportTransform.Value);
        StringAssert.Contains("m_AnchorMax: {x: 1, y: 1}", viewportTransform.Value);
        StringAssert.Contains("m_AnchoredPosition: {x: 0, y: -230}",
            viewportTransform.Value);
        StringAssert.Contains("m_SizeDelta: {x: -20, y: -230}",
            viewportTransform.Value);
        StringAssert.Contains("m_Father: {fileID: 1616590802}", viewportTransform.Value);
        StringAssert.Contains(
            "m_AnchorMin: {x: 1, y: 0}",
            verticalScrollbarTransform.Value);
        StringAssert.Contains(
            "m_AnchorMax: {x: 1, y: 1}",
            verticalScrollbarTransform.Value);
    }

    [Test]
    [Category("Step6C.3")]
    public void CustomerOrderTitleFitsItsSingleLineHeaderBounds()
    {
        string sceneText = File.ReadAllText(
            "Assets/_Game/Scenes/Game.unity");
        Match titleTransform = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &373534310\r?\n(.*?)(?=^--- !u!|\z)");
        Match orderNumberTransform = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &276639108\r?\n(.*?)(?=^--- !u!|\z)");
        Match titleText = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!114 &373534311\r?\n(.*?)(?=^--- !u!|\z)");

        Assert.IsTrue(titleTransform.Success);
        Assert.IsTrue(orderNumberTransform.Success);
        Assert.IsTrue(titleText.Success);
        StringAssert.Contains("m_enableAutoSizing: 1", titleText.Value);
        StringAssert.Contains("m_fontSize: 36", titleText.Value);
        StringAssert.Contains("m_fontSizeMin: 18", titleText.Value);
        StringAssert.Contains("m_fontSizeMax: 36", titleText.Value);
        StringAssert.Contains("m_TextWrappingMode: 0", titleText.Value);
        StringAssert.Contains("m_overflowMode: 1", titleText.Value);
        StringAssert.Contains(
            "m_margin: {x: 0, y: 0, z: 0, w: 0}",
            titleText.Value);

        Vector2 titlePosition = ReadSceneVector2(
            titleTransform.Value,
            "m_AnchoredPosition");
        Vector2 titleSize = ReadSceneVector2(
            titleTransform.Value,
            "m_SizeDelta");
        Vector2 orderNumberPosition = ReadSceneVector2(
            orderNumberTransform.Value,
            "m_AnchoredPosition");
        Vector2 orderNumberSize = ReadSceneVector2(
            orderNumberTransform.Value,
            "m_SizeDelta");

        float titleRight = titlePosition.x + titleSize.x * 0.5f;
        float orderNumberLeft =
            orderNumberPosition.x - orderNumberSize.x * 0.5f;
        foreach (float screenHeight in new[] { 1920f, 2340f, 2400f })
        {
            float canvasScale = Mathf.Sqrt(screenHeight / 1920f);
            Assert.Less(
                titleRight * canvasScale,
                orderNumberLeft * canvasScale,
                $"Order title overlaps its number at 1080x{screenHeight:0}.");
        }
    }

    [Test]
    [Category("Step6C.5.1")]
    public void RebirthRequirementsFitBetweenModalButtonsWithBoundedText()
    {
        string sceneText = File.ReadAllText(
            "Assets/_Game/Scenes/Game.unity");
        Match panelTransform = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &270310534\r?\n(.*?)(?=^--- !u!|\z)");
        Match requirementsTransform = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &505775532\r?\n(.*?)(?=^--- !u!|\z)");
        Match actionButtonTransform = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &1971709281\r?\n(.*?)(?=^--- !u!|\z)");
        Match closeButtonTransform = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!224 &1226504787\r?\n(.*?)(?=^--- !u!|\z)");
        Match requirementsText = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!114 &505775533\r?\n(.*?)(?=^--- !u!|\z)");
        Match backdrop = Regex.Match(
            sceneText,
            @"(?ms)^--- !u!114 &1812561283\r?\n(.*?)(?=^--- !u!|\z)");

        Assert.IsTrue(panelTransform.Success);
        Assert.IsTrue(requirementsTransform.Success);
        Assert.IsTrue(actionButtonTransform.Success);
        Assert.IsTrue(closeButtonTransform.Success);
        Assert.IsTrue(requirementsText.Success);
        Assert.IsTrue(backdrop.Success);

        Vector2 panelSize = ReadSceneVector2(
            panelTransform.Value,
            "m_SizeDelta");
        Vector2 requirementsOffset = ReadSceneVector2(
            requirementsTransform.Value,
            "m_AnchoredPosition");
        Vector2 requirementsSize = ReadSceneVector2(
            requirementsTransform.Value,
            "m_SizeDelta");
        Vector2 actionButtonOffset = ReadSceneVector2(
            actionButtonTransform.Value,
            "m_AnchoredPosition");
        Vector2 actionButtonSize = ReadSceneVector2(
            actionButtonTransform.Value,
            "m_SizeDelta");
        Vector2 closeButtonOffset = ReadSceneVector2(
            closeButtonTransform.Value,
            "m_AnchoredPosition");
        Vector2 closeButtonSize = ReadSceneVector2(
            closeButtonTransform.Value,
            "m_SizeDelta");

        Vector2 requirementsAnchorMin = ReadSceneVector2(
            requirementsTransform.Value,
            "m_AnchorMin");
        Vector2 requirementsAnchorMax = ReadSceneVector2(
            requirementsTransform.Value,
            "m_AnchorMax");
        float effectiveRequirementsWidth =
            panelSize.x *
            (requirementsAnchorMax.x - requirementsAnchorMin.x) +
            requirementsSize.x;
        float requirementsTop =
            panelSize.y * 0.5f + requirementsOffset.y;
        float requirementsBottom =
            requirementsTop - requirementsSize.y;
        float actionButtonTop =
            -panelSize.y * 0.5f + actionButtonOffset.y +
            actionButtonSize.y;
        float closeButtonBottom =
            panelSize.y * 0.5f + closeButtonOffset.y -
            closeButtonSize.y;

        Assert.Less(requirementsTop, panelSize.y * 0.5f);
        Assert.Greater(requirementsBottom, actionButtonTop);
        Assert.Less(requirementsTop, closeButtonBottom);
        Assert.Greater(effectiveRequirementsWidth, 0f);
        Assert.Greater(requirementsSize.y, 0f);
        StringAssert.Contains("m_enableAutoSizing: 1", requirementsText.Value);
        StringAssert.Contains("m_fontSize: 32", requirementsText.Value);
        StringAssert.Contains("m_fontSizeMin: 20", requirementsText.Value);
        StringAssert.Contains("m_fontSizeMax: 32", requirementsText.Value);
        StringAssert.Contains("m_TextWrappingMode: 1", requirementsText.Value);
        StringAssert.Contains("m_overflowMode: 1", requirementsText.Value);
        StringAssert.Contains("m_RaycastTarget: 1", backdrop.Value);
        StringAssert.Contains(
            "m_AnchorMin: {x: 0, y: 0}",
            Regex.Match(
                sceneText,
                @"(?ms)^--- !u!224 &1812561282\r?\n(.*?)(?=^--- !u!|\z)").Value);
        StringAssert.Contains(
            "m_AnchorMax: {x: 1, y: 1}",
            Regex.Match(
                sceneText,
                @"(?ms)^--- !u!224 &1812561282\r?\n(.*?)(?=^--- !u!|\z)").Value);
    }

    [Test]
    [Category("Step6B.3")]
    public void SafeAreaAnchorConversionPreservesBaseLayoutAndHandlesInvalidRectangles()
    {
        Vector2 baseMin = new Vector2(0.2f, 0.25f);
        Vector2 baseMax = new Vector2(0.8f, 0.75f);
        Rect fullSafeArea = new Rect(0, 0, 1080, 1920);
        Rect canvasRect = new Rect(0, 0, 1080, 1920);

        Vector4 anchors = CalculateSafeAreaAnchors(
            baseMin,
            baseMax,
            fullSafeArea,
            canvasRect);
        Assert.AreEqual(baseMin.x, anchors.x);
        Assert.AreEqual(baseMin.y, anchors.y);
        Assert.AreEqual(baseMax.x, anchors.z);
        Assert.AreEqual(baseMax.y, anchors.w);

        Vector4 invalidCanvasAnchors = CalculateSafeAreaAnchors(
            baseMin,
            baseMax,
            fullSafeArea,
            new Rect(0, 0, 0, 1920));
        Assert.AreEqual(anchors, invalidCanvasAnchors);
    }

    [Test]
    [Category("Step6B.5")]
    public void SpawnPoolSelectorFitsBelowPreviewInsidePortraitSafeAreas()
    {
        const float gap = 12f;
        Vector2 panelSize = new Vector2(260f, 64f);
        Rect previewBounds = new Rect(-40f, 620f, 80f, 80f);
        Rect[] safeAreas =
        {
            new Rect(-500f, -900f, 1000f, 1800f),
            new Rect(-540f, -900f, 1080f, 1800f),
            new Rect(-560f, -900f, 1120f, 1800f)
        };

        foreach (Rect safeArea in safeAreas)
        {
            Assert.IsTrue(TryCalculateSpawnPoolSelectorBounds(
                previewBounds,
                safeArea,
                panelSize,
                gap,
                out Rect selectorBounds));
            Assert.GreaterOrEqual(selectorBounds.xMin, safeArea.xMin);
            Assert.LessOrEqual(selectorBounds.xMax, safeArea.xMax);
            Assert.GreaterOrEqual(selectorBounds.yMin, safeArea.yMin);
            Assert.LessOrEqual(selectorBounds.yMax, safeArea.yMax);
            Assert.LessOrEqual(
                selectorBounds.yMax,
                previewBounds.yMin - gap);
            Assert.IsFalse(selectorBounds.Overlaps(previewBounds));
        }
    }

    [Test]
    [Category("Step6B.5")]
    public void SpawnPoolSelectorRejectsSafeAreasWithInsufficientSpace()
    {
        Assert.IsFalse(TryCalculateSpawnPoolSelectorBounds(
            new Rect(-40f, -50f, 80f, 80f),
            new Rect(-100f, -200f, 200f, 220f),
            new Vector2(260f, 64f),
            12f,
            out Rect unusedBounds));

        Assert.IsFalse(TryCalculateSpawnPoolSelectorBounds(
            new Rect(-40f, -50f, 80f, 80f),
            new Rect(-400f, -40f, 800f, 140f),
            new Vector2(260f, 64f),
            12f,
            out unusedBounds));
    }

    [Test]
    [Category("Step6B.4")]
    public void AllShelfSlotVisualsAndTouchAreasFitSupportedPortraitCameraBounds()
    {
        Scene previewScene = EditorSceneManager.OpenPreviewScene(
            "Assets/_Game/Scenes/Game.unity");

        try
        {
            Camera sceneCamera = null;
            ShelfSlotSceneData[] slotData =
                new ShelfSlotSceneData[5];

            foreach (GameObject root in previewScene.GetRootGameObjects())
            {
                Transform[] transforms =
                    root.GetComponentsInChildren<Transform>(true);

                foreach (Transform item in transforms)
                {
                    if (item.CompareTag("MainCamera"))
                        sceneCamera = item.GetComponent<Camera>();

                    int slotIndex = GetShelfSlotIndex(item.name);
                    if (slotIndex < 0)
                        continue;

                    slotData[slotIndex] = new ShelfSlotSceneData(
                        item.GetComponent<Collider2D>(),
                        item.GetComponent<SpriteRenderer>());
                }
            }

            Assert.IsNotNull(sceneCamera, "Game scene camera was not found.");
            Assert.IsTrue(sceneCamera.orthographic);

            float[] portraitAspects =
            {
                9f / 16f,
                9f / 19.5f,
                9f / 20f
            };

            foreach (float aspect in portraitAspects)
            {
                float halfWidth = sceneCamera.orthographicSize * aspect;
                float halfHeight = sceneCamera.orthographicSize;
                Bounds viewBounds = new Bounds(
                    sceneCamera.transform.position,
                    new Vector3(halfWidth * 2f, halfHeight * 2f, 100f));

                for (int i = 0; i < slotData.Length; i++)
                {
                    Assert.IsNotNull(slotData[i].Collider,
                        $"ShelfSlot_{i + 1} has no touch collider.");
                    Assert.IsNotNull(slotData[i].Renderer,
                        $"ShelfSlot_{i + 1} has no visible renderer.");
                    Assert.GreaterOrEqual(
                        slotData[i].Collider.bounds.size.x,
                        1f,
                        $"ShelfSlot_{i + 1} touch width is too small.");
                    Assert.GreaterOrEqual(
                        slotData[i].Collider.bounds.size.y,
                        1f,
                        $"ShelfSlot_{i + 1} touch height is too small.");
                    AssertBoundsContained(
                        viewBounds,
                        slotData[i].Collider.bounds,
                        $"ShelfSlot_{i + 1} touch area at aspect {aspect}.");
                    AssertBoundsContained(
                        viewBounds,
                        slotData[i].Renderer.bounds,
                        $"ShelfSlot_{i + 1} visual at aspect {aspect}.");
                }
            }
        }
        finally
        {
            EditorSceneManager.ClosePreviewScene(previewScene);
        }
    }

    [Test]
    [Category("Step6B.6")]
    public void GameSceneSerializedTransformHierarchyHasExactlyOneConsistentParent()
    {
        string sceneText = File.ReadAllText(
            "Assets/_Game/Scenes/Game.unity");
        MatchCollection transformMatches = Regex.Matches(
            sceneText,
            @"(?ms)^--- !u!(?:4|224) &(-?\d+)\r?\n(.*?)(?=^--- !u!|\z)");
        Dictionary<long, long> fathers = new Dictionary<long, long>();
        Dictionary<long, List<long>> children =
            new Dictionary<long, List<long>>();
        Dictionary<long, int> childReferenceCounts =
            new Dictionary<long, int>();

        foreach (Match transformMatch in transformMatches)
        {
            long transformId = long.Parse(transformMatch.Groups[1].Value);
            Match fatherMatch = Regex.Match(
                transformMatch.Groups[2].Value,
                @"(?m)^  m_Father: \{fileID: (-?\d+)\}");
            Assert.IsTrue(fatherMatch.Success,
                $"Transform {transformId} has no m_Father.");
            fathers.Add(
                transformId,
                long.Parse(fatherMatch.Groups[1].Value));

            Match childrenMatch = Regex.Match(
                transformMatch.Groups[2].Value,
                @"(?ms)^  m_Children:\r?\n((?:  - \{fileID: -?\d+\}\r?\n)*)");
            List<long> childIds = new List<long>();
            if (childrenMatch.Success)
            {
                foreach (Match childMatch in Regex.Matches(
                             childrenMatch.Groups[1].Value,
                             @"fileID: (-?\d+)"))
                {
                    long childId = long.Parse(childMatch.Groups[1].Value);
                    childIds.Add(childId);
                    childReferenceCounts.TryGetValue(childId, out int count);
                    childReferenceCounts[childId] = count + 1;
                }
            }
            children.Add(transformId, childIds);
            Assert.AreEqual(
                childIds.Count,
                childIds.Distinct().Count(),
                $"Transform {transformId} lists a child more than once.");
        }

        foreach (KeyValuePair<long, long> transform in fathers)
        {
            long transformId = transform.Key;
            long fatherId = transform.Value;
            if (fatherId == 0)
            {
                Assert.IsFalse(childReferenceCounts.ContainsKey(transformId),
                    $"Root transform {transformId} is listed as another transform's child.");
                continue;
            }

            Assert.IsTrue(children.ContainsKey(fatherId),
                $"Transform {transformId} references missing parent {fatherId}.");
            Assert.IsTrue(children[fatherId].Contains(transformId),
                $"Parent {fatherId} does not list child {transformId}.");
            Assert.AreEqual(
                1,
                childReferenceCounts[transformId],
                $"Transform {transformId} is listed under multiple parents.");
        }

        const long bottomNavigationTransformId = 705582561;
        const long homeButtonTransformId = 2047490582;
        const long recycleTargetTransformId = 2200000001;
        Assert.IsTrue(children[bottomNavigationTransformId]
            .Contains(homeButtonTransformId));
        Assert.IsTrue(children[bottomNavigationTransformId]
            .Contains(recycleTargetTransformId));
        Assert.AreEqual(bottomNavigationTransformId,
            fathers[homeButtonTransformId]);
        Assert.AreEqual(bottomNavigationTransformId,
            fathers[recycleTargetTransformId]);
    }

    [Test]
    [Category("Step6A.2")]
    public void MergeTransactionBlocksOvenDragAndRecycleMutations()
    {
        RecycleFixture fixture = CreateRecycleFixture(false);
        GameObject spawnerObject = new GameObject("Merge guard spawner");
        spawnerObject.SetActive(false);
        fixture.Objects.Add(spawnerObject);
        object spawner = spawnerObject.AddComponent(
            FindPlayerType("DessertSpawner"));
        SetPrivateField(spawner, "gridManager", fixture.Grid);

        object transactionOwner = new object();
        Type gridType = FindPlayerType("GridManager");
        MethodInfo beginTransaction = gridType.GetMethod("TryBeginMergeTransaction");
        MethodInfo endTransaction = gridType.GetMethod("EndMergeTransaction");
        try
        {
            Assert.IsTrue((bool)beginTransaction.Invoke(
                fixture.Grid,
                new[] { transactionOwner }));

            Assert.IsFalse((bool)spawner.GetType()
                .GetMethod("TrySpawnRandomDessert", Type.EmptyTypes)
                .Invoke(spawner, null),
                "Oven spawning must be rejected during a merge.");

            fixture.DragHandler.GetType().GetMethod("OnPointerDown").Invoke(
                fixture.DragHandler,
                new object[]
                {
                    new UnityEngine.EventSystems.PointerEventData(null)
                });
            Assert.IsFalse((bool)fixture.DragHandler.GetType()
                .GetField("isDragging",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .GetValue(fixture.DragHandler),
                "A new drag must not begin during a merge.");

            SetPrivateField(fixture.DragHandler, "isDragging", true);
            fixture.DragHandler.GetType().GetMethod("OnPointerUp").Invoke(
                fixture.DragHandler,
                new object[]
                {
                    new UnityEngine.EventSystems.PointerEventData(null)
                });
            Assert.AreSame(fixture.Dessert,
                GetPropertyValue(fixture.Cell, "CurrentDessert"),
                "A drag started before the merge must not transfer its dessert.");

            Assert.IsFalse((bool)fixture.DragHandler.GetType().GetMethod(
                    "TryRecycleDraggedDessert",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(fixture.DragHandler, null),
                "Recycling must be rejected during a merge.");
        }
        finally
        {
            endTransaction.Invoke(fixture.Grid, new[] { transactionOwner });
            DestroyRecycleFixture(fixture);
        }
    }

    [Test]
    [Category("Step6A.2")]
    public void MergeTransactionCompletionAndAbortReleaseSharedGuard()
    {
        RecycleFixture fixture = CreateRecycleFixture(false);
        object handler = fixture.DragHandler;
        Type gridType = FindPlayerType("GridManager");
        MethodInfo beginTransaction = gridType.GetMethod("TryBeginMergeTransaction");
        MethodInfo endTransaction = gridType.GetMethod("EndMergeTransaction");
        PropertyInfo active = gridType.GetProperty("IsMergeTransactionActive");
        try
        {
            Assert.IsTrue((bool)beginTransaction.Invoke(
                fixture.Grid, new[] { handler }));
            SetPrivateField(handler, "mergeTransactionActive", true);
            handler.GetType().GetMethod(
                    "AbortMergeTransaction",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(handler, null);
            Assert.IsFalse((bool)active.GetValue(fixture.Grid),
                "Abort must release the lock.");

            Assert.IsTrue((bool)beginTransaction.Invoke(
                fixture.Grid, new[] { handler }));
            SetPrivateField(handler, "mergeTransactionActive", true);
            handler.GetType().GetMethod(
                    "CompleteMergeTransaction",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(handler, null);
            Assert.IsFalse((bool)active.GetValue(fixture.Grid),
                "Successful completion must release the lock.");
        }
        finally
        {
            endTransaction.Invoke(fixture.Grid, new[] { handler });
            DestroyRecycleFixture(fixture);
        }
    }

    [Test]
    [Category("Step5C.2")]
    public void LuckLevelPersistsInOptionalV2MetadataAndLegacySavesDefaultToOne()
    {
        var setup = CreateProgressionPurchaseTestSetup();
        GameObject managerObject = new GameObject("Luck V2 persistence test");
        managerObject.SetActive(false);
        object saveManager = managerObject.AddComponent(FindPlayerType("SaveManager"));
        Type progressionType = setup.Progression.GetType();
        Type saveManagerType = saveManager.GetType();
        SetPrivateStaticProperty(progressionType, "Instance", setup.Progression);
        SetPrivateStaticProperty(saveManagerType, "Instance", saveManager);

        try
        {
            object save = Activator.CreateInstance(FindPlayerType("PlayerSaveData"));
            MethodInfo serializeWithLuck = saveManagerType.GetMethod(
                "SerializeWithLuck",
                BindingFlags.Static | BindingFlags.NonPublic);
            string json = (string)serializeWithLuck.Invoke(
                null,
                new[] { save, (object)0, null, 3 });
            StringAssert.Contains("\"luckLevel\":3", json);

            MethodInfo validate = saveManagerType.GetMethod(
                "IsValidSerializedSnapshot",
                BindingFlags.Instance | BindingFlags.NonPublic);
            Assert.IsTrue((bool)validate.Invoke(saveManager, new object[] { json }));
            object[] parseArgs =
            {
                System.Text.Encoding.UTF8.GetBytes(json),
                "Luck V2 persistence test",
                null
            };
            Assert.IsTrue((bool)saveManagerType.GetMethod(
                "TryParseValidatedBytes",
                BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(saveManager, parseArgs));
            Assert.IsTrue((bool)saveManagerType.GetMethod(
                "RestoreProgression",
                BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(saveManager, new[] { parseArgs[2] }));
            Assert.AreEqual(3, progressionType.GetProperty("LuckLevel")
                .GetValue(setup.Progression));

            string legacyJson = (string)saveManagerType.GetMethod(
                "SerializeWithCapacity",
                BindingFlags.Static | BindingFlags.NonPublic)
                .Invoke(null, new[] { save, (object)0 });
            Assert.IsTrue((bool)validate.Invoke(
                saveManager,
                new object[] { legacyJson }));
            object[] legacyArgs =
            {
                System.Text.Encoding.UTF8.GetBytes(legacyJson),
                "Legacy V2 persistence test",
                null
            };
            Assert.IsTrue((bool)saveManagerType.GetMethod(
                "TryParseValidatedBytes",
                BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(saveManager, legacyArgs));
            Assert.IsTrue((bool)saveManagerType.GetMethod(
                "RestoreProgression",
                BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(saveManager, new[] { legacyArgs[2] }));
            Assert.AreEqual(1, progressionType.GetProperty("LuckLevel")
                .GetValue(setup.Progression),
                "Legacy V2 saves without Luck metadata retain starting Luck.");
        }
        finally
        {
            SetPrivateStaticProperty(progressionType, "Instance", null);
            SetPrivateStaticProperty(saveManagerType, "Instance", null);
            UnityEngine.Object.DestroyImmediate(managerObject);
            DestroyProgressionPurchaseTestSetup(setup);
        }
    }

    [Test]
    public void RebirthUIReflectsRequirementsProgressAndCompletion()
    {
        var setup = CreateProgressionPurchaseTestSetup();
        SetPrivateStaticProperty(
            setup.Economy.GetType(),
            "Instance",
            setup.Economy);
        var spawnerObject = new GameObject("Rebirth UI dessert names");
        spawnerObject.SetActive(false);
        object spawner = spawnerObject.AddComponent(
            FindPlayerType("DessertSpawner"));
        Array dessertDefinitions = Array.CreateInstance(
            FindPlayerType("DessertDefinition"), 30);
        for (int tier = 1; tier <= 30; tier++)
        {
            dessertDefinitions.SetValue(
                AssetDatabase.LoadMainAssetAtPath(
                    $"{DessertFolder}/Dessert_{tier:00}.asset"),
                tier - 1);
        }
        SetPrivateField(spawner, "dessertDefinitions", dessertDefinitions);

        var uiObject = new GameObject("Rebirth UI state test");
        uiObject.SetActive(false);
        object ui = uiObject.AddComponent(FindPlayerType("RebirthUI"));
        var requirementTextObject = new GameObject("Requirements");
        requirementTextObject.SetActive(false);
        object requirementText = requirementTextObject.AddComponent(
            FindPlayerType("TMPro.TextMeshProUGUI"));
        var buttonObject = new GameObject("RebirthButton");
        buttonObject.SetActive(false);
        buttonObject.AddComponent<UnityEngine.UI.Image>();
        var button = buttonObject.AddComponent<UnityEngine.UI.Button>();
        var buttonTextObject = new GameObject("ButtonText");
        buttonTextObject.SetActive(false);
        object buttonText = buttonTextObject.AddComponent(
            FindPlayerType("TMPro.TextMeshProUGUI"));
        var entryButtonObject = new GameObject("RebirthEntryButton");
        entryButtonObject.SetActive(false);
        entryButtonObject.AddComponent<UnityEngine.UI.Image>();
        var entryButton = entryButtonObject.AddComponent<UnityEngine.UI.Button>();
        var entryButtonTextObject = new GameObject("EntryButtonText");
        entryButtonTextObject.SetActive(false);
        object entryButtonText = entryButtonTextObject.AddComponent(
            FindPlayerType("TMPro.TextMeshProUGUI"));
        var closeButtonObject = new GameObject("CloseButton");
        closeButtonObject.SetActive(false);
        closeButtonObject.AddComponent<UnityEngine.UI.Image>();
        var closeButton = closeButtonObject.AddComponent<UnityEngine.UI.Button>();
        var indicatorObject = new GameObject("ReadyIndicator");
        object readyIndicator = indicatorObject.AddComponent(
            typeof(UnityEngine.UI.Image));
        var modalPanel = new GameObject("RebirthPanel");
        var modalBackdrop = new GameObject("RebirthBackdrop");
        var notificationObject = new GameObject("AvailabilityNotification");
        object notification = notificationObject.AddComponent(
            FindPlayerType("TMPro.TextMeshProUGUI"));
        SetPrivateField(ui, "progressionManager", setup.Progression);
        SetPrivateField(ui, "economyManager", setup.Economy);
        SetPrivateField(ui, "dessertSpawner", spawner);
        SetPrivateField(ui, "requirementsText", requirementText);
        SetPrivateField(ui, "rebirthButton", button);
        SetPrivateField(ui, "rebirthButtonText", buttonText);
        SetPrivateField(ui, "entryButton", entryButton);
        SetPrivateField(ui, "entryButtonText", entryButtonText);
        SetPrivateField(ui, "readyIndicator", readyIndicator);
        SetPrivateField(ui, "modalPanel", modalPanel);
        SetPrivateField(ui, "modalBackdrop", modalBackdrop);
        SetPrivateField(ui, "closeButton", closeButton);
        SetPrivateField(ui, "availabilityNotification", notification);
        setup.Economy.GetType()
            .GetMethod("RestoreCash")
            .Invoke(setup.Economy, new object[] { 0 });

        try
        {
            ui.GetType().GetMethod(
                    "Awake",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(ui, null);
            Assert.IsFalse(modalPanel.activeSelf,
                "The Rebirth modal should start closed.");
            Assert.IsFalse(modalBackdrop.activeSelf,
                "The closed modal backdrop must not intercept gameplay.");

            MethodInfo start = ui.GetType().GetMethod(
                "Start",
                BindingFlags.Instance | BindingFlags.NonPublic);
            start.Invoke(ui, null);
            string text = (string)requirementText.GetType()
                .GetProperty("text").GetValue(requirementText);
            StringAssert.Contains("REBIRTH 1", text);
            StringAssert.Contains("Create T7", text);
            object requiredDessert = spawner.GetType()
                .GetMethod("GetDefinitionByTier")
                .Invoke(spawner, new object[] { 7 });
            StringAssert.Contains(
                (string)requiredDessert.GetType()
                    .GetProperty("DisplayName").GetValue(requiredDessert),
                text);
            StringAssert.Contains("$0 / $128", text);
            Assert.IsFalse(button.interactable);
            Assert.IsFalse(((UnityEngine.UI.Image)readyIndicator).enabled);
            Assert.IsFalse(((UnityEngine.Component)notification)
                .GetComponent<UnityEngine.UI.Graphic>().enabled);

            setup.Progression.GetType()
                .GetMethod("HandleCreatedDessert", BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(setup.Progression, new object[] { 7 });
            Assert.IsFalse(button.interactable,
                "Created-tier eligibility alone must not enable Rebirth.");

            setup.Economy.GetType()
                .GetMethod("RestoreCash")
                .Invoke(setup.Economy, new object[] { 128 });
            Assert.IsTrue(button.interactable,
                "The UI should refresh when cash completes the requirements.");
            Assert.IsTrue(((UnityEngine.UI.Image)readyIndicator).enabled);
            text = (string)requirementText.GetType()
                .GetProperty("text").GetValue(requirementText);
            StringAssert.Contains("Eligibility: READY", text);
            Assert.AreEqual(
                "Rebirth Available! Tap Rebirth to continue!",
                notification.GetType().GetProperty("text")
                    .GetValue(notification));
            Assert.IsTrue(((UnityEngine.Component)notification)
                .GetComponent<UnityEngine.UI.Graphic>().enabled);

            ui.GetType().GetMethod("Refresh").Invoke(ui, null);
            ((UnityEngine.Component)notification)
                .GetComponent<UnityEngine.UI.Graphic>().enabled = false;
            ui.GetType().GetMethod("Refresh").Invoke(ui, null);
            Assert.IsFalse(((UnityEngine.Component)notification)
                .GetComponent<UnityEngine.UI.Graphic>().enabled,
                "Repeated refreshes must not replay the same eligibility notification.");

            setup.Economy.GetType()
                .GetMethod("RestoreCash")
                .Invoke(setup.Economy, new object[] { 0 });
            Assert.IsFalse(((UnityEngine.UI.Image)readyIndicator).enabled);
            setup.Economy.GetType()
                .GetMethod("RestoreCash")
                .Invoke(setup.Economy, new object[] { 128 });
            Assert.IsTrue(((UnityEngine.Component)notification)
                .GetComponent<UnityEngine.UI.Graphic>().enabled,
                "A later false-to-true eligibility transition should notify again.");

            ((UnityEngine.Component)notification)
                .GetComponent<UnityEngine.UI.Graphic>().enabled = false;
            ui.GetType().GetMethod("Refresh").Invoke(ui, null);
            Assert.IsFalse(((UnityEngine.Component)notification)
                .GetComponent<UnityEngine.UI.Graphic>().enabled,
                "Repeated refreshes while eligible must not display it again.");

            entryButton.onClick.Invoke();
            Assert.IsTrue(modalPanel.activeSelf);
            Assert.IsTrue(modalBackdrop.activeSelf);
            Assert.IsFalse(
                entryButton.interactable,
                "The entry button must be disabled while the modal is open.");
            ui.GetType().GetMethod("Refresh").Invoke(ui, null);
            Assert.IsFalse(
                entryButton.interactable,
                "Refreshing requirements must not re-enable the open modal entry.");
            closeButton.onClick.Invoke();
            Assert.IsFalse(modalPanel.activeSelf);
            Assert.IsFalse(modalBackdrop.activeSelf);
            Assert.IsTrue(
                entryButton.interactable,
                "Closing the modal must restore entry-button interaction.");

            setup.Progression.GetType()
                .GetMethod("RestoreRebirthProgression")
                .Invoke(setup.Progression, new object[] { 10, 0, false });
            Assert.IsFalse(button.interactable);
            Assert.AreEqual(
                "All Rebirths Complete\nFinal Objective: Create Tier 30 — Eternal Dragon's Dessert",
                requirementText.GetType().GetProperty("text").GetValue(requirementText));
            Assert.AreEqual(
                "COMPLETE",
                buttonText.GetType().GetProperty("text").GetValue(buttonText));
            Assert.IsFalse(((UnityEngine.UI.Image)readyIndicator).enabled);
            Assert.AreEqual(
                "REBIRTH COMPLETE",
                entryButtonText.GetType().GetProperty("text").GetValue(entryButtonText));

            setup.Progression.GetType()
                .GetMethod("RestoreRebirthProgression")
                .Invoke(setup.Progression, new object[] { 10, 29, false });
            setup.Progression.GetType()
                .GetMethod(
                    "HandleCreatedDessert",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(setup.Progression, new object[] { 30 });
            setup.Progression.GetType().GetMethod(
                    "SetCampaignCompletionPersistenceState",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(setup.Progression, new object[]
                {
                    GetCampaignCompletionPersistenceState("Pending"),
                    false
                });
            Assert.AreEqual(
                "Completion not saved\n" +
                "Tier 30 was created, but campaign progress could not be saved.",
                requirementText.GetType().GetProperty("text").GetValue(requirementText),
                "Pending completion must be clearly presented as unsaved.");

            setup.Progression.GetType()
                .GetMethod("RestoreRebirthProgression")
                .Invoke(setup.Progression, new object[] { 10, 30, true });
            Assert.AreEqual(
                "Campaign Complete!\nEternal Dragon's Dessert created.",
                requirementText.GetType().GetProperty("text").GetValue(requirementText),
                "Restoring completed campaign state should refresh status without requiring a completion event.");

            setup.Progression.GetType()
                .GetMethod("RestoreRebirthProgression")
                .Invoke(setup.Progression, new object[] { 10, 29, false });
            setup.Progression.GetType().GetMethod(
                    "HandleCreatedDessert",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(setup.Progression, new object[] { 30 });
            setup.Progression.GetType().GetMethod(
                    "SetCampaignCompletionPersistenceState",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(setup.Progression, new object[]
                {
                    GetCampaignCompletionPersistenceState("Pending"),
                    false
                });
            requirementText.GetType().GetProperty("text")
                .SetValue(requirementText, "Stale status");
            setup.Progression.GetType().GetMethod(
                    "MarkCampaignCompletionSaved",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(setup.Progression, null);
            Assert.AreEqual(
                "Campaign Complete!\nEternal Dragon's Dessert created.",
                requirementText.GetType().GetProperty("text").GetValue(requirementText),
                "Successful persistence should refresh the final status.");
        }
        finally
        {
            SetPrivateStaticProperty(
                setup.Economy.GetType(),
                "Instance",
                null);
            UnityEngine.Object.DestroyImmediate(uiObject);
            UnityEngine.Object.DestroyImmediate(requirementTextObject);
            UnityEngine.Object.DestroyImmediate(buttonObject);
            UnityEngine.Object.DestroyImmediate(buttonTextObject);
            UnityEngine.Object.DestroyImmediate(entryButtonObject);
            UnityEngine.Object.DestroyImmediate(entryButtonTextObject);
            UnityEngine.Object.DestroyImmediate(closeButtonObject);
            UnityEngine.Object.DestroyImmediate(indicatorObject);
            UnityEngine.Object.DestroyImmediate(modalPanel);
            UnityEngine.Object.DestroyImmediate(modalBackdrop);
            UnityEngine.Object.DestroyImmediate(notificationObject);
            UnityEngine.Object.DestroyImmediate(spawnerObject);
            DestroyProgressionPurchaseTestSetup(setup);
        }
    }

    [Test]
    public void CampaignCompletionPanelIsHiddenAndBoundToTheGameplayCanvas()
    {
        string scene = File.ReadAllText("Assets/_Game/Scenes/Game.unity");
        StringAssert.Contains("m_Name: CampaignCompletionOverlay", scene);
        StringAssert.Contains("m_Name: CampaignCompletionPanel", scene);
        StringAssert.Contains("m_IsActive: 0", scene);
        StringAssert.Contains("Campaign Complete!", scene);
        StringAssert.Contains("Eternal Dragon's Dessert", scene);
        StringAssert.Contains(
            "Congratulations! You've completed the Sweet Merge campaign.",
            scene);
        StringAssert.Contains("m_text: Continue Playing", scene);
        StringAssert.Contains("messageText: {fileID: 1810000010}", scene);
        StringAssert.Contains(
            "continueButtonText: {fileID: 1810000019}",
            scene);
        StringAssert.Contains(
            "Assembly-CSharp::CampaignCompletionUI",
            scene);
        StringAssert.Contains(
            "panelRoot: {fileID: 1810000000}",
            scene);
        StringAssert.Contains(
            "continueButton: {fileID: 1810000014}",
            scene);

        Match overlay = Regex.Match(
            scene,
            @"(?ms)^--- !u!1 &1810000000\r?\n(.*?)(?=^--- !u!|\z)");
        Match overlayImage = Regex.Match(
            scene,
            @"(?ms)^--- !u!114 &1810000002\r?\n(.*?)(?=^--- !u!|\z)");
        Assert.IsTrue(overlay.Success);
        Assert.IsTrue(overlayImage.Success);
        StringAssert.Contains("m_IsActive: 0", overlay.Value);
        StringAssert.Contains(
            "m_EditorClassIdentifier: UnityEngine.UI::UnityEngine.UI.Image",
            overlayImage.Value);
    }

    [Test]
    public void CampaignCompletionUIShowsOnceAndUnsubscribesWhenDisabled()
    {
        Type uiType = FindPlayerType("CampaignCompletionUI");
        Type gameplayEventsType = FindPlayerType("GameplayEvents");
        MethodInfo raiseCompletion = gameplayEventsType.GetMethod(
            "RaiseCampaignCompleted",
            BindingFlags.Public | BindingFlags.Static);
        FieldInfo completionEvent = gameplayEventsType.GetField(
            "CampaignCompleted",
            BindingFlags.Static | BindingFlags.NonPublic);
        Assert.IsNotNull(completionEvent);

        var host = new GameObject("Campaign completion UI test");
        host.SetActive(false);
        var panel = new GameObject(
            "Campaign completion panel test",
            typeof(RectTransform),
            typeof(CanvasRenderer),
            typeof(UnityEngine.UI.Image));
        panel.SetActive(false);
        var buttonObject = new GameObject(
            "Continue Playing button test",
            typeof(RectTransform),
            typeof(CanvasRenderer),
            typeof(UnityEngine.UI.Image),
            typeof(UnityEngine.UI.Button));
        buttonObject.transform.SetParent(panel.transform, false);
        var messageObject = new GameObject(
            "Campaign completion message test",
            typeof(RectTransform),
            typeof(CanvasRenderer));
        var buttonTextObject = new GameObject(
            "Continue Playing label test",
            typeof(RectTransform),
            typeof(CanvasRenderer));
        buttonTextObject.transform.SetParent(buttonObject.transform, false);
        Component messageText = messageObject.AddComponent(
            FindPlayerType("TMPro.TextMeshProUGUI"));
        Component buttonText = buttonTextObject.AddComponent(
            FindPlayerType("TMPro.TextMeshProUGUI"));
        Component ui = host.AddComponent(uiType);
        UnityEngine.UI.Button button =
            buttonObject.GetComponent<UnityEngine.UI.Button>();
        SetPrivateField(ui, "panelRoot", panel);
        SetPrivateField(ui, "continueButton", button);
        SetPrivateField(ui, "messageText", messageText);
        SetPrivateField(ui, "continueButtonText", buttonText);

        try
        {
            host.SetActive(true);
            InvokeLifecycle(ui, "OnEnable");
            Assert.IsFalse(panel.activeSelf, "The celebration starts hidden.");

            raiseCompletion.Invoke(null, null);
            Assert.IsTrue(panel.activeSelf);
            Assert.AreEqual("Continue Playing",
                GetPropertyValue(buttonText, "text"));

            button.onClick.Invoke();
            Assert.IsFalse(panel.activeSelf,
                "Continue Playing should dismiss the panel.");

            raiseCompletion.Invoke(null, null);
            Assert.IsFalse(panel.activeSelf,
                "A repeated completion must not reopen a dismissed panel.");

            host.SetActive(false);
            InvokeLifecycle(ui, "OnDisable");
            Delegate subscribers = (Delegate)completionEvent.GetValue(null);
            Assert.IsFalse(
                subscribers != null &&
                subscribers.GetInvocationList().Any(
                    callback => callback.Target == ui),
                "Disabled UI must unsubscribe from the completion event.");

            raiseCompletion.Invoke(null, null);
            Assert.IsFalse(panel.activeSelf);

            host.SetActive(true);
            InvokeLifecycle(ui, "OnEnable");
            subscribers = (Delegate)completionEvent.GetValue(null);
            Assert.AreEqual(
                1,
                subscribers.GetInvocationList()
                    .Count(callback => callback.Target == ui),
                "Re-enabling the UI must not add duplicate subscriptions.");
            raiseCompletion.Invoke(null, null);
            Assert.IsFalse(panel.activeSelf,
                "Re-enabling or restoring must not replay a shown celebration.");
        }
        finally
        {
            host.SetActive(false);
            UnityEngine.Object.DestroyImmediate(host);
            UnityEngine.Object.DestroyImmediate(panel);
            UnityEngine.Object.DestroyImmediate(messageObject);
        }
    }

    [Test]
    public void GameSceneHasFunctionalRebirthPanelAndSerializedReferences()
    {
        string scene = File.ReadAllText("Assets/_Game/Scenes/Game.unity");
        StringAssert.Contains("m_Name: RebirthPanel", scene);
        StringAssert.Contains("Assembly-CSharp::RebirthUI", scene);
        StringAssert.Contains("m_Name: RebirthButton", scene);
        StringAssert.Contains("m_Name: RebirthEntryButton", scene);
        StringAssert.Contains("m_Name: RebirthBackdrop", scene);
        StringAssert.Contains("m_Name: CloseButton", scene);

        Match component = Regex.Match(
            scene,
            @"m_EditorClassIdentifier: Assembly-CSharp::RebirthUI\s+" +
            @"requirementsText: \{fileID: (?<text>\d+)\}\s+" +
            @"rebirthButton: \{fileID: (?<button>\d+)\}\s+" +
            @"rebirthButtonText: \{fileID: (?<label>\d+)\}\s+" +
            @"entryButton: \{fileID: (?<entry>\d+)\}\s+" +
            @"entryButtonText: \{fileID: (?<entryLabel>\d+)\}\s+" +
            @"readyIndicator: \{fileID: (?<indicator>\d+)\}\s+" +
            @"modalPanel: \{fileID: (?<panel>\d+)\}\s+" +
            @"modalBackdrop: \{fileID: (?<backdrop>\d+)\}\s+" +
            @"closeButton: \{fileID: (?<close>\d+)\}\s+" +
            @"availabilityNotification: \{fileID: (?<notification>\d+)\}");
        Assert.IsTrue(component.Success, "Rebirth UI references are not serialized.");
        foreach (string reference in new[]
                 {
                     "text", "button", "label", "entry", "entryLabel",
                     "indicator", "panel", "backdrop", "close", "notification"
                 })
            Assert.AreNotEqual("0", component.Groups[reference].Value, reference);
    }

    [Test]
    [Category("CustomerOrders_CO2_3")]
    public void OrderDetailsModalLayoutAndInputBlockerAreSerializedCorrectly()
    {
        string scene = File.ReadAllText("Assets/_Game/Scenes/Game.unity");
        Match canvasTransform = Regex.Match(
            scene,
            @"(?ms)^--- !u!224 &1297646555\r?\n(.*?)(?=^--- !u!|\z)");
        Match orderDetailsUI = Regex.Match(
            scene,
            @"(?ms)^--- !u!114 &1297646559\r?\n(.*?)(?=^--- !u!|\z)");
        Match blockerObject = Regex.Match(
            scene,
            @"(?ms)^--- !u!1 &2200000100\r?\n(.*?)(?=^--- !u!|\z)");
        Match blockerTransform = Regex.Match(
            scene,
            @"(?ms)^--- !u!224 &2200000101\r?\n(.*?)(?=^--- !u!|\z)");
        Match blockerImage = Regex.Match(
            scene,
            @"(?ms)^--- !u!114 &2200000103\r?\n(.*?)(?=^--- !u!|\z)");
        Match overlay = Regex.Match(
            scene,
            @"(?ms)^--- !u!1 &1395192558\r?\n(.*?)(?=^--- !u!|\z)");
        Match panel = Regex.Match(
            scene,
            @"(?ms)^--- !u!224 &121302785\r?\n(.*?)(?=^--- !u!|\z)");
        Match requirements = Regex.Match(
            scene,
            @"(?ms)^--- !u!224 &401750353\r?\n(.*?)(?=^--- !u!|\z)");
        Match title = Regex.Match(
            scene,
            @"(?ms)^--- !u!224 &373534310\r?\n(.*?)(?=^--- !u!|\z)");
        Match titleText = Regex.Match(
            scene,
            @"(?ms)^--- !u!114 &373534311\r?\n(.*?)(?=^--- !u!|\z)");
        Match orderNumber = Regex.Match(
            scene,
            @"(?ms)^--- !u!224 &276639108\r?\n(.*?)(?=^--- !u!|\z)");
        Match orderNumberText = Regex.Match(
            scene,
            @"(?ms)^--- !u!114 &276639109\r?\n(.*?)(?=^--- !u!|\z)");
        Match confirm = Regex.Match(
            scene,
            @"(?ms)^--- !u!224 &2028420272\r?\n(.*?)(?=^--- !u!|\z)");

        foreach (Match match in new[]
                 {
                     canvasTransform, orderDetailsUI, blockerObject,
                     blockerTransform, blockerImage, overlay, panel,
                     requirements, title, titleText, orderNumber,
                     orderNumberText, confirm
                 })
            Assert.IsTrue(match.Success, "Order details scene reference is missing.");

        StringAssert.Contains("inputBlocker: {fileID: 2200000100}",
            orderDetailsUI.Value);
        StringAssert.Contains("m_Name: OrderDetailsInputBlocker",
            blockerObject.Value);
        StringAssert.Contains("m_IsActive: 0", blockerObject.Value);
        StringAssert.Contains("m_Father: {fileID: 1297646555}",
            blockerTransform.Value);
        StringAssert.Contains("m_AnchorMin: {x: 0, y: 0}",
            blockerTransform.Value);
        StringAssert.Contains("m_AnchorMax: {x: 1, y: 1}",
            blockerTransform.Value);
        StringAssert.Contains("m_SizeDelta: {x: 0, y: 0}",
            blockerTransform.Value);
        StringAssert.Contains("m_Color: {r: 1, g: 1, b: 1, a: 0}",
            blockerImage.Value);
        StringAssert.Contains("m_RaycastTarget: 1", blockerImage.Value);
        StringAssert.Contains("m_IsActive: 0", overlay.Value);
        StringAssert.Contains("m_SizeDelta: {x: 750, y: 650}",
            panel.Value);

        MatchCollection canvasChildren = Regex.Matches(
            canvasTransform.Value,
            @"(?m)^  - \{fileID: (-?\d+)\}$");
        Assert.GreaterOrEqual(canvasChildren.Count, 2);
        string[] canvasChildIds = canvasChildren.Cast<Match>()
            .Select(child => child.Groups[1].Value)
            .ToArray();
        int blockerIndex = Array.IndexOf(canvasChildIds, "2200000101");
        int orderOverlayIndex = Array.IndexOf(canvasChildIds, "1395192559");
        int campaignOverlayIndex = Array.IndexOf(canvasChildIds, "1810000001");
        Assert.GreaterOrEqual(orderOverlayIndex, 0,
            "The order details overlay must remain a direct canvas child.");
        Assert.GreaterOrEqual(blockerIndex, 0,
            "The order input blocker must remain a direct canvas child.");
        Assert.GreaterOrEqual(campaignOverlayIndex, 0,
            "The campaign completion overlay must remain a direct canvas child.");
        Assert.Greater(orderOverlayIndex, blockerIndex,
            "The order details overlay must render above its input blocker.");
        Assert.Greater(campaignOverlayIndex, orderOverlayIndex,
            "The campaign celebration must render above the order details overlay.");

        StringAssert.Contains("m_AnchoredPosition: {x: 0, y: 155}",
            requirements.Value);
        StringAssert.Contains("m_SizeDelta: {x: 680, y: 210}",
            requirements.Value);
        StringAssert.Contains("m_AnchoredPosition: {x: 0, y: 365}",
            title.Value);
        StringAssert.Contains("m_AnchoredPosition: {x: 0, y: -125}",
            confirm.Value);
        StringAssert.Contains("m_Father: {fileID: 1504059926}",
            title.Value);
        StringAssert.Contains("m_Father: {fileID: 1504059926}",
            orderNumber.Value);
        StringAssert.Contains("m_AnchorMin: {x: 0.5, y: 0.5}",
            title.Value);
        StringAssert.Contains("m_AnchorMax: {x: 0.5, y: 0.5}",
            title.Value);
        StringAssert.Contains("m_AnchorMin: {x: 0.5, y: 0.5}",
            orderNumber.Value);
        StringAssert.Contains("m_AnchorMax: {x: 0.5, y: 0.5}",
            orderNumber.Value);

        Assert.AreEqual(
            "256",
            Regex.Match(
                titleText.Value,
                @"(?m)^  m_VerticalAlignment: (\d+)$").Groups[1].Value,
            "The order title uses vertically centered text.");
        Assert.AreEqual(
            "256",
            Regex.Match(
                orderNumberText.Value,
                @"(?m)^  m_VerticalAlignment: (\d+)$").Groups[1].Value,
            "The order number uses vertically centered text.");
        string titleFontGuid = Regex.Match(
            titleText.Value,
            @"(?m)^  m_fontAsset: \{fileID: \d+, guid: ([0-9a-f]{32}), type: 2\}")
            .Groups[1].Value;
        string orderNumberFontGuid = Regex.Match(
            orderNumberText.Value,
            @"(?m)^  m_fontAsset: \{fileID: \d+, guid: ([0-9a-f]{32}), type: 2\}")
            .Groups[1].Value;
        Assert.IsNotEmpty(titleFontGuid);
        Assert.AreEqual(titleFontGuid, orderNumberFontGuid,
            "Both labels use the same font metrics.");
        string fontAssetPath = AssetDatabase.GUIDToAssetPath(titleFontGuid);
        Assert.IsNotEmpty(fontAssetPath);
        string fontAsset = File.ReadAllText(fontAssetPath);
        float fontPointSize = ReadSceneFloat(fontAsset, "m_PointSize");
        float fontLineHeight = ReadSceneFloat(fontAsset, "m_LineHeight");
        Assert.Greater(fontPointSize, 0f);
        Assert.Greater(fontLineHeight, 0f);
        float titleFontSize = ReadSceneFloat(titleText.Value, "m_fontSize");
        float orderNumberFontSize =
            ReadSceneFloat(orderNumberText.Value, "m_fontSize");
        Vector2 titlePosition = ReadSceneVector2(
            title.Value,
            "m_AnchoredPosition");
        Vector2 titleSize = ReadSceneVector2(title.Value, "m_SizeDelta");
        Vector2 orderNumberPosition = ReadSceneVector2(
            orderNumber.Value,
            "m_AnchoredPosition");
        Vector2 orderNumberSize = ReadSceneVector2(
            orderNumber.Value,
            "m_SizeDelta");
        float titleLineHeight =
            fontLineHeight * titleFontSize / fontPointSize;
        float orderNumberLineHeight =
            fontLineHeight * orderNumberFontSize / fontPointSize;
        float titleTextMinY =
            titlePosition.y - Mathf.Min(titleSize.y, titleLineHeight) * 0.5f;
        float titleTextMaxY =
            titlePosition.y + Mathf.Min(titleSize.y, titleLineHeight) * 0.5f;
        float orderNumberTextMinY =
            orderNumberPosition.y -
            Mathf.Min(orderNumberSize.y, orderNumberLineHeight) * 0.5f;
        float orderNumberTextMaxY =
            orderNumberPosition.y +
            Mathf.Min(orderNumberSize.y, orderNumberLineHeight) * 0.5f;
        Assert.IsTrue(
            titleTextMinY >= orderNumberTextMaxY ||
            orderNumberTextMinY >= titleTextMaxY,
            "The title and Order Number text line bounds must not overlap.");

        foreach (int layoutId in new[] { 1434013344, 76114894, 173951686 })
        {
            Match rowLayout = Regex.Match(
                scene,
                $@"(?ms)^--- !u!114 &{layoutId}\r?\n(.*?)(?=^--- !u!|\z)");
            Assert.IsTrue(rowLayout.Success);
            StringAssert.Contains("m_ChildAlignment: 4", rowLayout.Value);
            StringAssert.Contains("m_Spacing: 24", rowLayout.Value);
            StringAssert.Contains("m_ChildForceExpandWidth: 0",
                rowLayout.Value);
            StringAssert.Contains("m_ChildForceExpandHeight: 0",
                rowLayout.Value);
        }

        foreach (int rowId in new[] { 1434013343, 76114892, 173951685 })
        {
            Match row = Regex.Match(
                scene,
                $@"(?ms)^--- !u!224 &{rowId}\r?\n(.*?)(?=^--- !u!|\z)");
            Assert.IsTrue(row.Success);
            StringAssert.Contains("m_SizeDelta: {x: 0, y: 80}", row.Value);
        }

        foreach (int iconId in new[] { 1485393869, 1843911900, 2142781157 })
        {
            Match icon = Regex.Match(
                scene,
                $@"(?ms)^--- !u!224 &{iconId}\r?\n(.*?)(?=^--- !u!|\z)");
            Assert.IsTrue(icon.Success);
            StringAssert.Contains("m_SizeDelta: {x: 64, y: 64}", icon.Value);
        }

        foreach (int nameId in new[] { 1440474416, 1037492925, 335092719 })
        {
            Match name = Regex.Match(
                scene,
                $@"(?ms)^--- !u!224 &{nameId}\r?\n(.*?)(?=^--- !u!|\z)");
            Assert.IsTrue(name.Success);
            StringAssert.Contains("m_SizeDelta: {x: 260, y: 60}", name.Value);
        }

        foreach (int progressId in new[] { 514563158, 1228486872, 379113128 })
        {
            Match progress = Regex.Match(
                scene,
                $@"(?ms)^--- !u!224 &{progressId}\r?\n(.*?)(?=^--- !u!|\z)");
            Assert.IsTrue(progress.Success);
            StringAssert.Contains("m_SizeDelta: {x: 160, y: 60}",
                progress.Value);
        }
    }

    [Test]
    public void RebirthEligibilityRequiresCreatedTierAndHeldCash()
    {
        object state = CreateRebirthState(0);
        Assert.IsFalse(CanRebirth(state, 128));
        Assert.IsTrue(RegisterCreatedTier(state, 7));
        Assert.IsFalse(CanRebirth(state, 127));
        Assert.IsTrue(CanRebirth(state, 128));

        object laterMilestone = CreateRebirthState(3, 12);
        Assert.IsFalse(CanRebirth(laterMilestone, 1069));
        Assert.IsTrue(CanRebirth(laterMilestone, 1070));
        Assert.IsFalse(CanRebirth(
            CreateRebirthState(10, 30),
            int.MaxValue));
    }

    [Test]
    public void RebirthCommitFailureIsNoOpAndSuccessResetsOnlyRunTier()
    {
        object state = CreateRebirthState(0, 7);
        string beforeFailure = JsonUtility.ToJson(state);
        MethodInfo commit = state.GetType().GetMethod(
            "TryCommitRebirth",
            BindingFlags.Instance | BindingFlags.NonPublic);

        Assert.IsFalse((bool)commit.Invoke(state, new object[] { 127 }));
        Assert.AreEqual(beforeFailure, JsonUtility.ToJson(state));

        Assert.IsTrue((bool)commit.Invoke(state, new object[] { 128 }));
        Assert.AreEqual(1, GetRebirthProperty(state, "CurrentRebirthCount"));
        Assert.AreEqual(0, GetRebirthProperty(state, "HighestTierCreatedThisRun"));
        Assert.IsFalse((bool)GetRebirthProperty(state, "CampaignComplete"));

        string afterCommit = JsonUtility.ToJson(state);
        Assert.IsFalse((bool)commit.Invoke(state, new object[] { int.MaxValue }));
        Assert.AreEqual(afterCommit, JsonUtility.ToJson(state),
            "A repeated call must not advance a second time without new-run eligibility.");
    }

    [Test]
    public void CreatedTierTrackingIsMonotonicAndRejectsInvalidTiers()
    {
        object state = CreateRebirthState(0);
        Assert.IsFalse(RegisterCreatedTier(state, 0));
        Assert.IsFalse(RegisterCreatedTier(state, 31));
        Assert.IsTrue(RegisterCreatedTier(state, 5));
        Assert.IsFalse(RegisterCreatedTier(state, 3));
        Assert.IsFalse(RegisterCreatedTier(state, 5));
        Assert.IsTrue(RegisterCreatedTier(state, 12));
        Assert.AreEqual(12, GetRebirthProperty(state, "HighestTierCreatedThisRun"));
        Assert.AreEqual(0, GetRebirthProperty(state, "CurrentRebirthCount"));
    }

    [Test]
    public void CampaignCompletionPendingUiShowsRetryAndRetainsFailureState()
    {
        ProgressionPurchaseTestSetup setup =
            CreateProgressionPurchaseTestSetup();
        Type progressionType = setup.Progression.GetType();
        Type saveManagerType = FindPlayerType("SaveManager");
        SetPrivateStaticProperty(progressionType, "Instance", setup.Progression);
        SetPrivateStaticProperty(saveManagerType, "Instance", null);
        Assert.IsTrue((bool)progressionType
            .GetMethod("RestoreRebirthProgression")
            .Invoke(setup.Progression, new object[] { 10, 29, false }));
        progressionType.GetMethod(
                "HandleCreatedDessert",
                BindingFlags.Instance | BindingFlags.NonPublic)
            .Invoke(setup.Progression, new object[] { 30 });
        progressionType.GetMethod(
                "SetCampaignCompletionPersistenceState",
                BindingFlags.Instance | BindingFlags.NonPublic)
            .Invoke(setup.Progression, new object[]
            {
                GetCampaignCompletionPersistenceState("Pending"),
                false
            });

        var host = new GameObject("Campaign pending UI test");
        host.SetActive(false);
        var panel = new GameObject(
            "Campaign pending panel test",
            typeof(RectTransform),
            typeof(CanvasRenderer),
            typeof(UnityEngine.UI.Image));
        panel.SetActive(false);
        var buttonObject = new GameObject(
            "Retry Save button test",
            typeof(RectTransform),
            typeof(CanvasRenderer),
            typeof(UnityEngine.UI.Image),
            typeof(UnityEngine.UI.Button));
        buttonObject.transform.SetParent(panel.transform, false);
        var messageObject = new GameObject(
            "Pending completion message test",
            typeof(RectTransform),
            typeof(CanvasRenderer));
        var labelObject = new GameObject(
            "Retry Save label test",
            typeof(RectTransform),
            typeof(CanvasRenderer));
        labelObject.transform.SetParent(buttonObject.transform, false);
        Component messageText = messageObject.AddComponent(
            FindPlayerType("TMPro.TextMeshProUGUI"));
        Component buttonText = labelObject.AddComponent(
            FindPlayerType("TMPro.TextMeshProUGUI"));
        Component ui = host.AddComponent(
            FindPlayerType("CampaignCompletionUI"));
        UnityEngine.UI.Button button =
            buttonObject.GetComponent<UnityEngine.UI.Button>();
        SetPrivateField(ui, "panelRoot", panel);
        SetPrivateField(ui, "continueButton", button);
        SetPrivateField(ui, "messageText", messageText);
        SetPrivateField(ui, "continueButtonText", buttonText);

        try
        {
            host.SetActive(true);
            InvokeLifecycle(ui, "OnEnable");
            Assert.IsTrue(panel.activeSelf);
            StringAssert.Contains(
                "Completion not saved",
                (string)messageText.GetType()
                    .GetProperty("text").GetValue(messageText));
            Assert.AreEqual(
                "Retry Save",
                buttonText.GetType().GetProperty("text").GetValue(buttonText));

            LogAssert.Expect(
                LogType.Error,
                "CAMPAIGN COMPLETE | SaveManager is unavailable; completion remains unsaved.");
            LogAssert.Expect(
                LogType.Error,
                "CAMPAIGN COMPLETE | V2 save did not succeed; completion remains pending and can be retried.");
            button.onClick.Invoke();
            StringAssert.Contains(
                "Try again when saving is available",
                (string)messageText.GetType()
                    .GetProperty("text").GetValue(messageText));
            Assert.AreEqual(
                GetCampaignCompletionPersistenceState("Pending").ToString(),
                GetPropertyValue(
                    setup.Progression,
                    "CampaignCompletionPersistence").ToString());

            progressionType.GetMethod(
                    "MarkCampaignCompletionSaved",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(setup.Progression, null);
            StringAssert.Contains(
                "Campaign Complete!",
                (string)messageText.GetType()
                    .GetProperty("text").GetValue(messageText));
            Assert.AreEqual(
                "Continue Playing",
                buttonText.GetType().GetProperty("text").GetValue(buttonText));
            Assert.IsFalse((bool)GetPropertyValue(
                setup.Progression,
                "HasPendingCampaignCelebrationPresentation"),
                "Showing the celebration consumes its session-level presentation token.");
            button.onClick.Invoke();
            Assert.IsFalse(panel.activeSelf,
                "The successful celebration action should dismiss the panel.");
        }
        finally
        {
            SetPrivateStaticProperty(saveManagerType, "Instance", null);
            SetPrivateStaticProperty(progressionType, "Instance", null);
            host.SetActive(false);
            UnityEngine.Object.DestroyImmediate(host);
            UnityEngine.Object.DestroyImmediate(panel);
            UnityEngine.Object.DestroyImmediate(messageObject);
            DestroyProgressionPurchaseTestSetup(setup);
        }
    }

    [Test]
    public void CampaignCompletionRequiresR10AndFirstT30Creation()
    {
        var setup = CreateProgressionPurchaseTestSetup();
        var saveManagerObject = new GameObject("Completed campaign save test");
        saveManagerObject.SetActive(false);
        Type saveManagerType = FindPlayerType("SaveManager");
        object saveManager = saveManagerObject.AddComponent(saveManagerType);
        try
        {
            MethodInfo restoreProgression = setup.Progression.GetType()
                .GetMethod("RestoreRebirthProgression");
            Assert.IsTrue((bool)restoreProgression.Invoke(
                setup.Progression,
                new object[] { 9, 0, false }));
            Assert.AreEqual(5, GetPropertyValue(
                setup.Progression,
                "OvenLevel"));
            Assert.IsFalse((bool)setup.Progression.GetType()
                .GetMethod("IsDessertTierUnlocked")
                .Invoke(setup.Progression, new object[] { 30 }),
                "T30 must remain locked before R10.");

            Assert.IsTrue((bool)restoreProgression.Invoke(
                setup.Progression,
                new object[] { 10, 0, false }));
            Assert.AreEqual(6, GetPropertyValue(
                setup.Progression,
                "OvenLevel"));
            Assert.IsTrue((bool)setup.Progression.GetType()
                .GetMethod("IsDessertTierUnlocked")
                .Invoke(setup.Progression, new object[] { 30 }));

            Assert.IsTrue((bool)restoreProgression.Invoke(
                setup.Progression,
                new object[] { 10, 30, true }));
            Assert.IsFalse((bool)GetPropertyValue(
                setup.Progression,
                "HasPendingCampaignCelebrationPresentation"),
                "A restored completed V2 save must not queue the live celebration.");
            SetPrivateStaticProperty(
                setup.Progression.GetType(),
                "Instance",
                setup.Progression);
            object save = Activator.CreateInstance(FindPlayerType("PlayerSaveData"));
            Assert.IsTrue((bool)saveManagerType.GetMethod(
                    "CaptureProgression",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(saveManager, new[] { save }));
            Assert.IsTrue((bool)GetField(save, "campaignComplete"));

            MethodInfo serialize = saveManagerType.GetMethod(
                "SerializeWithCapacity",
                BindingFlags.Static | BindingFlags.NonPublic);
            string saveJson = (string)serialize.Invoke(
                null,
                new[] { save, (object)0 });
            Assert.IsTrue((bool)saveManagerType.GetMethod(
                    "IsValidSerializedSnapshot",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(saveManager, new object[] { saveJson }));
            object restoredSave = JsonUtility.FromJson(
                saveJson,
                FindPlayerType("PlayerSaveData"));
            Assert.IsTrue((bool)GetField(restoredSave, "campaignComplete"));
            Assert.AreEqual(10, GetField(restoredSave, "completedRebirthCount"));
            Assert.AreEqual(30, GetField(restoredSave, "highestTierCreatedThisRun"));
        }
        finally
        {
            SetPrivateStaticProperty(saveManagerType, "Instance", null);
            SetPrivateStaticProperty(
                setup.Progression.GetType(),
                "Instance",
                null);
            UnityEngine.Object.DestroyImmediate(saveManagerObject);
            DestroyProgressionPurchaseTestSetup(setup);
        }

        object beforeFinalRebirth = CreateRebirthState(9);
        Assert.IsTrue(RegisterCreatedTier(beforeFinalRebirth, 30));
        Assert.IsFalse((bool)GetRebirthProperty(
            beforeFinalRebirth,
            "CampaignComplete"));

        object finalRebirth = CreateRebirthState(10);
        Assert.IsTrue(RegisterCreatedTier(finalRebirth, 29));
        Assert.IsTrue(RegisterCreatedTier(finalRebirth, 30));
        Assert.IsTrue((bool)GetRebirthProperty(
            finalRebirth,
            "CampaignComplete"));
        Assert.IsFalse(RegisterCreatedTier(finalRebirth, 30));

        string completedJson = JsonUtility.ToJson(finalRebirth);
        object restored = JsonUtility.FromJson(
            completedJson,
            finalRebirth.GetType());
        Assert.IsTrue((bool)GetRebirthProperty(restored, "CampaignComplete"));
        Assert.IsFalse(RegisterCreatedTier(restored, 30),
            "An already-completed save must not create another tier transition.");

    }

    [Test]
    public void CampaignCompletionSaveFailureStaysPendingUntilSavedOnce()
    {
        ProgressionPurchaseTestSetup setup =
            CreateProgressionPurchaseTestSetup();
        Type progressionType = setup.Progression.GetType();
        Type saveManagerType = FindPlayerType("SaveManager");
        Type gameplayEventsType = FindPlayerType("GameplayEvents");
        var saveManagerObject = new GameObject(
            "Campaign completion save retry test");
        saveManagerObject.SetActive(false);
        Component saveManager = saveManagerObject.AddComponent(saveManagerType);
        EventInfo completionEvent =
            gameplayEventsType.GetEvent("CampaignCompleted");
        int completionNotifications = 0;
        Action completionHandler = () => completionNotifications++;
        completionEvent.AddEventHandler(null, completionHandler);

        try
        {
            SetPrivateStaticProperty(progressionType, "Instance", setup.Progression);
            SetPrivateStaticProperty(saveManagerType, "Instance", null);
            Assert.IsTrue((bool)progressionType
                .GetMethod("RestoreRebirthProgression")
                .Invoke(setup.Progression, new object[] { 10, 29, false }));
            progressionType.GetMethod(
                    "HandleCreatedDessert",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(setup.Progression, new object[] { 30 });
            Assert.IsTrue((bool)GetPropertyValue(
                setup.Progression,
                "CampaignComplete"));

            LogAssert.Expect(
                LogType.Error,
                "CAMPAIGN COMPLETE | SaveManager is unavailable; completion remains unsaved.");
            LogAssert.Expect(
                LogType.Error,
                "CAMPAIGN COMPLETE | V2 save did not succeed; completion remains pending and can be retried.");
            Assert.IsFalse((bool)progressionType
                .GetMethod("TryPersistCampaignCompletion")
                .Invoke(setup.Progression, null));
            Assert.AreEqual(
                GetCampaignCompletionPersistenceState("Pending").ToString(),
                GetPropertyValue(
                    setup.Progression,
                    "CampaignCompletionPersistence").ToString());
            Assert.AreEqual(0, completionNotifications,
                "A missing SaveManager must not emit the celebration event.");

            SetPrivateStaticProperty(saveManagerType, "Instance", saveManager);
            LogAssert.Expect(
                LogType.Error,
                "CAMPAIGN COMPLETE | V2 save did not succeed; completion remains pending and can be retried.");
            Assert.IsFalse((bool)progressionType
                .GetMethod("TryPersistCampaignCompletion")
                .Invoke(setup.Progression, null),
                "An unavailable lifecycle save path must remain pending.");
            Assert.AreEqual(
                GetCampaignCompletionPersistenceState("Pending").ToString(),
                GetPropertyValue(
                    setup.Progression,
                    "CampaignCompletionPersistence").ToString());
            Assert.AreEqual(0, completionNotifications,
                "A rejected retry must not emit the celebration event.");

            progressionType.GetMethod(
                    "MarkCampaignCompletionSaved",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(setup.Progression, null);
            Assert.AreEqual(
                GetCampaignCompletionPersistenceState("Saved").ToString(),
                GetPropertyValue(
                    setup.Progression,
                    "CampaignCompletionPersistence").ToString());
            Assert.AreEqual(1, completionNotifications);
            Assert.IsTrue((bool)GetPropertyValue(
                setup.Progression,
                "HasPendingCampaignCelebrationPresentation"));

            progressionType.GetMethod(
                    "MarkCampaignCompletionSaved",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(setup.Progression, null);
            Assert.AreEqual(1, completionNotifications,
                "Repeated successful callbacks must not duplicate the event.");

            Assert.IsTrue((bool)progressionType
                .GetMethod("RestoreRebirthProgression")
                .Invoke(setup.Progression, new object[] { 10, 30, true }));
            Assert.AreEqual(1, completionNotifications,
                "Restoring a completed save must not replay the event.");
        }
        finally
        {
            completionEvent.RemoveEventHandler(null, completionHandler);
            SetPrivateStaticProperty(saveManagerType, "Instance", null);
            SetPrivateStaticProperty(progressionType, "Instance", null);
            UnityEngine.Object.DestroyImmediate(saveManagerObject);
            DestroyProgressionPurchaseTestSetup(setup);
        }
    }

    [Test]
    public void VersionTwoSaveDataRoundTripsExistingGameplayAndRebirthFields()
    {
        Type saveType = FindPlayerType("PlayerSaveData");
        Type economyType = FindPlayerType("EconomySaveData");
        Type progressionType = FindPlayerType("ProgressionSaveData");
        Type gameplayType = FindPlayerType("MergeGameplaySaveData");
        Type boardType = FindPlayerType("BoardDessertSaveData");
        Type shelfType = FindPlayerType("ShelfDessertSaveData");
        Type orderType = FindPlayerType("CustomerOrderSaveData");

        object save = Activator.CreateInstance(saveType);
        SetField(save, "saveVersion", 2);
        SetField(save, "completedRebirthCount", 3);
        SetField(save, "highestTierCreatedThisRun", 12);
        object economy = GetField(save, "economy");
        SetField(economy, "cash", 128);
        object progression = GetField(save, "progression");
        SetField(progression, "ovenLevel", 1);
        SetField(progression, "boardSpaceLevel", 2);
        SetField(progression, "shelfLevel", 1);
        SetField(progression, "customerLevel", 1);
        SetField(progression, "moneyMultiplierLevel", 1);

        object gameplay = GetField(save, "mergeGameplay");
        SetField(gameplay, "hasSession", true);
        SetField(gameplay, "nextOrderId", 8);
        SetField(gameplay, "nextDessertTier", 3);
        AddListItem(gameplay, "boardDesserts", boardType,
            CreateRow(boardType, ("cellIndex", 4), ("dessertTier", 2)));
        AddListItem(gameplay, "shelfDesserts", shelfType,
            CreateRow(shelfType, ("slotIndex", 0), ("dessertTier", 3)));
        AddListItem(gameplay, "customerOrders", orderType,
            CreateRow(orderType,
                ("customerIndex", 0),
                ("orderId", 7),
                ("definitionId", ExistingOrderDefinitionIds[0])));

        string json = JsonUtility.ToJson(save);
        StringAssert.Contains("\"saveVersion\":2", json);
        StringAssert.Contains("\"dessertTier\":2", json);
        StringAssert.Contains(ExistingOrderDefinitionIds[0], json);

        object restored = JsonUtility.FromJson(json, saveType);
        Assert.AreEqual(2, GetField(restored, "saveVersion"));
        Assert.AreEqual(3, GetField(restored, "completedRebirthCount"));
        Assert.AreEqual(12, GetField(restored, "highestTierCreatedThisRun"));
        Assert.IsFalse((bool)GetField(restored, "campaignComplete"));
        Assert.AreEqual(128, GetField(GetField(restored, "economy"), "cash"));
        object restoredGameplay = GetField(restored, "mergeGameplay");
        Assert.AreEqual(8, GetField(restoredGameplay, "nextOrderId"));
        Assert.AreEqual(3, GetField(restoredGameplay, "nextDessertTier"));
        Assert.AreEqual(json, JsonUtility.ToJson(restored),
            "V2 serialization should round-trip canonically.");

        Type managerType = FindPlayerType("SaveManager");
        var managerObject = new GameObject("Normal V2 validation test");
        try
        {
            object manager = managerObject.AddComponent(managerType);
            MethodInfo serialize = managerType.GetMethod(
                "SerializeWithCapacity",
                BindingFlags.Static | BindingFlags.NonPublic);
            MethodInfo validate = managerType.GetMethod(
                "IsValidSerializedSnapshot",
                BindingFlags.Instance | BindingFlags.NonPublic);
            string normalSnapshot = (string)serialize.Invoke(
                null,
                new[] { save, (object)1 });
            Assert.IsTrue((bool)validate.Invoke(
                manager,
                new object[] { normalSnapshot }),
                "The existing normal-save validator should accept this canonical V2 session.");
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(managerObject);
        }

        string[] rootFields =
        {
            "saveVersion", "completedRebirthCount",
            "highestTierCreatedThisRun", "campaignComplete",
            "economy", "progression", "mergeGameplay"
        };
        CollectionAssert.AreEquivalent(
            rootFields,
            saveType.GetFields(BindingFlags.Instance | BindingFlags.Public)
                .Select(field => field.Name));
    }

    [Test]
    [Category("Step5C")]
    public void DetachedV2SnapshotIsStrictlyValidatedAndDeepCloned()
    {
        Type saveType = FindPlayerType("PlayerSaveData");
        object proposed = Activator.CreateInstance(saveType);
        SetField(proposed, "completedRebirthCount", 4);
        SetField(proposed, "highestTierCreatedThisRun", 12);
        string originalJson = JsonUtility.ToJson(proposed);

        Type managerType = FindPlayerType("SaveManager");
        var managerObject = new GameObject("Detached snapshot validation test");
        try
        {
                object manager = managerObject.AddComponent(managerType);
                object[] args = { proposed, 0, null, null };
                bool prepared = (bool)managerType.GetMethod(
                        "TryPrepareDetachedSnapshot",
                        BindingFlags.Instance | BindingFlags.NonPublic)
                    .Invoke(manager, args);

                Assert.IsTrue(prepared, args[3] as string);
                object detached = args[2];
                Assert.IsNotNull(detached);
                Assert.AreNotSame(proposed, detached);
                Assert.AreNotSame(
                    GetField(proposed, "economy"),
                    GetField(detached, "economy"));
                Assert.AreNotSame(
                    GetField(proposed, "mergeGameplay"),
                    GetField(detached, "mergeGameplay"));
                Assert.AreEqual(originalJson, JsonUtility.ToJson(proposed),
                    "Preparation must not mutate the caller's proposal.");

                MethodInfo serializeWithPool = manager.GetType().GetMethod(
                    "SerializeWithSpawnPool",
                    BindingFlags.Static | BindingFlags.NonPublic,
                    null,
                    new[] { saveType, typeof(int), typeof(string) },
                    null);
                string pooledJson = (string)serializeWithPool.Invoke(
                    null,
                    new[] { detached, (object)0, "P1" });
                MethodInfo validate = manager.GetType().GetMethod(
                    "IsValidSerializedSnapshot",
                    BindingFlags.Instance | BindingFlags.NonPublic);
                Assert.IsTrue((bool)validate.Invoke(manager, new object[] { pooledJson }),
                    "Selected-pool metadata must remain canonical V2 data.");
                object[] parseArgs =
                {
                    System.Text.Encoding.UTF8.GetBytes(pooledJson),
                    "test",
                    null
                };
                Assert.IsTrue((bool)manager.GetType().GetMethod(
                    "TryParseValidatedBytes",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                    .Invoke(manager, parseArgs));
                Assert.AreEqual(
                    "P1",
                    manager.GetType().GetField(
                            "loadedSelectedSpawnPoolId",
                            BindingFlags.Instance | BindingFlags.NonPublic)
                        .GetValue(manager),
                    "Validated V2 loading must restore the optional pool metadata.");

                SetField(GetField(detached, "economy"), "cash", 500);
                Assert.AreEqual(0, GetField(GetField(proposed, "economy"), "cash"),
                    "The returned snapshot must not share mutable state with its input.");
        }
        finally
        {
                UnityEngine.Object.DestroyImmediate(managerObject);
        }
    }

    [Test]
    public void DetachedV2SnapshotRejectsInvalidDataWithoutMutation()
    {
        Type saveType = FindPlayerType("PlayerSaveData");
        object proposed = Activator.CreateInstance(saveType);
        SetField(proposed, "completedRebirthCount", 11);
        string originalJson = JsonUtility.ToJson(proposed);

        Type managerType = FindPlayerType("SaveManager");
        var managerObject = new GameObject("Invalid detached snapshot test");
        try
        {
                object manager = managerObject.AddComponent(managerType);
                object[] args = { proposed, 0, null, null };
                bool prepared = (bool)managerType.GetMethod(
                        "TryPrepareDetachedSnapshot",
                        BindingFlags.Instance | BindingFlags.NonPublic)
                    .Invoke(manager, args);

                Assert.IsFalse(prepared);
                Assert.IsNull(args[2]);
                Assert.IsNotNull(args[3] as string);
                Assert.AreEqual(originalJson, JsonUtility.ToJson(proposed),
                    "Rejecting an invalid proposal must not sanitize or mutate it.");

                object valid = Activator.CreateInstance(saveType);
                object[] invalidCapacityArgs = { valid, 1, null, null };
                Assert.IsFalse((bool)managerType.GetMethod(
                        "TryPrepareDetachedSnapshot",
                        BindingFlags.Instance | BindingFlags.NonPublic)
                    .Invoke(manager, invalidCapacityArgs),
                    "A no-session snapshot must not claim active-session capacity.");
        }
        finally
        {
                UnityEngine.Object.DestroyImmediate(managerObject);
        }
    }

    [Test]
    public void FreshV2SaveStartsAtR0AndUsesAnIsolatedPath()
    {
        Type saveType = FindPlayerType("PlayerSaveData");
        object save = Activator.CreateInstance(saveType);
        Assert.AreEqual(2, GetField(save, "saveVersion"));
        Assert.AreEqual(0, GetField(save, "completedRebirthCount"));
        Assert.AreEqual(0, GetField(save, "highestTierCreatedThisRun"));
        Assert.IsFalse((bool)GetField(save, "campaignComplete"));

        Type managerType = FindPlayerType("SaveManager");
        var managerObject = new GameObject("Save path test");
        try
        {
            object manager = managerObject.AddComponent(managerType);
            string v2Path = (string)managerType.GetProperty("SaveFilePath")
                .GetValue(manager);
            string v1Path = (string)managerType.GetProperty("LegacyV1SaveFilePath")
                .GetValue(manager);
            Assert.AreNotEqual(v1Path, v2Path);
            StringAssert.EndsWith("player_save_v2.json", v2Path);
            StringAssert.EndsWith("player_save.json", v1Path);
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(managerObject);
        }
    }

    [Test]
    public void V2ValidationRejectsInvalidRebirthState()
    {
        Type saveType = FindPlayerType("PlayerSaveData");
        object save = Activator.CreateInstance(saveType);
        Type managerType = FindPlayerType("SaveManager");
        MethodInfo serialize = managerType.GetMethod(
            "SerializeWithCapacity",
            BindingFlags.Static | BindingFlags.NonPublic);
        MethodInfo validate = managerType.GetMethod(
            "IsValidSerializedSnapshot",
            BindingFlags.Instance | BindingFlags.NonPublic);
        var managerObject = new GameObject("V2 validation test");
        try
        {
            object manager = managerObject.AddComponent(managerType);
            string validJson = (string)serialize.Invoke(null, new[] { save, (object)0 });
            Assert.IsTrue((bool)validate.Invoke(manager, new object[] { validJson }));

            string invalidCount = validJson.Replace(
                "\"completedRebirthCount\":0",
                "\"completedRebirthCount\":11");
            Assert.IsFalse((bool)validate.Invoke(manager, new object[] { invalidCount }));

            string invalidCampaign = validJson.Replace(
                "\"campaignComplete\":false",
                "\"campaignComplete\":true");
            Assert.IsFalse((bool)validate.Invoke(manager, new object[] { invalidCampaign }));
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(managerObject);
        }
    }

    [Test]
    public void V2BackupRecoveryPreservesBackupAndDamagedPrimary()
    {
        Type saveType = FindPlayerType("PlayerSaveData");
        object save = Activator.CreateInstance(saveType);
        Type managerType = FindPlayerType("SaveManager");
        MethodInfo serialize = managerType.GetMethod(
            "SerializeWithCapacity",
            BindingFlags.Static | BindingFlags.NonPublic);
        MethodInfo restore = managerType.GetMethod(
            "RestorePrimaryFromBackup",
            BindingFlags.Instance | BindingFlags.NonPublic);
        var managerObject = new GameObject("V2 backup recovery test");
        string directory = Path.Combine(
            Path.GetTempPath(),
            "SweetMergeSaveRecovery_" + Guid.NewGuid().ToString("N"));
        string primaryPath = Path.Combine(directory, "player_save_v2.json");
        byte[] backupBytes = System.Text.Encoding.UTF8.GetBytes(
            (string)serialize.Invoke(null, new[] { save, (object)0 }));
        byte[] corruptBytes = System.Text.Encoding.UTF8.GetBytes("{corrupt}");
        try
        {
            Directory.CreateDirectory(directory);
            File.WriteAllBytes(primaryPath, corruptBytes);
            File.WriteAllBytes(primaryPath + ".bak", backupBytes);
            restore.Invoke(
                managerObject.AddComponent(managerType),
                new object[] { primaryPath, backupBytes, true, corruptBytes });

            CollectionAssert.AreEqual(backupBytes, File.ReadAllBytes(primaryPath));
            CollectionAssert.AreEqual(backupBytes, File.ReadAllBytes(primaryPath + ".bak"));
            Assert.AreEqual(
                1,
                Directory.GetFiles(directory, "player_save_v2.json.corrupt.*").Length,
                "Corrupt primary bytes should be retained for diagnosis.");
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(managerObject);
            if (Directory.Exists(directory))
                Directory.Delete(directory, true);
        }
    }

    [Test]
    public void RebirthV2SnapshotPromotionAndBackupRollbackPreserveBothSnapshots()
    {
        Type saveType = FindPlayerType("PlayerSaveData");
        Type managerType = FindPlayerType("SaveManager");
        object prior = Activator.CreateInstance(saveType);
        SetField(prior, "highestTierCreatedThisRun", 7);
        SetField(GetField(prior, "economy"), "cash", 128);
        SetField(GetField(prior, "progression"), "boardSpaceLevel", 3);

        object proposed = Activator.CreateInstance(saveType);
        SetField(proposed, "completedRebirthCount", 1);
        SetField(proposed, "highestTierCreatedThisRun", 0);
        SetField(GetField(proposed, "economy"), "cash", 0);
        SetField(GetField(proposed, "progression"), "boardSpaceLevel", 3);

        MethodInfo serialize = managerType.GetMethod(
            "SerializeWithCapacity",
            BindingFlags.Static | BindingFlags.NonPublic);
        MethodInfo promote = managerType.GetMethod(
            "WriteSnapshotAtomically",
            BindingFlags.Instance | BindingFlags.NonPublic);
        MethodInfo restore = managerType.GetMethod(
            "RestorePrimaryFromBackup",
            BindingFlags.Instance | BindingFlags.NonPublic);
        byte[] priorBytes = System.Text.Encoding.UTF8.GetBytes(
            (string)serialize.Invoke(null, new[] { prior, (object)0 }));
        byte[] proposedBytes = System.Text.Encoding.UTF8.GetBytes(
            (string)serialize.Invoke(null, new[] { proposed, (object)0 }));
        var managerObject = new GameObject("Rebirth snapshot transaction test");
        string directory = Path.Combine(
            Path.GetTempPath(),
            "SweetMergeRebirthSave_" + Guid.NewGuid().ToString("N"));
        string primaryPath = Path.Combine(directory, "player_save_v2.json");

        try
        {
            Directory.CreateDirectory(directory);
            object manager = managerObject.AddComponent(managerType);
            promote.Invoke(manager, new object[] { primaryPath, priorBytes });
            promote.Invoke(manager, new object[] { primaryPath, proposedBytes });

            CollectionAssert.AreEqual(proposedBytes, File.ReadAllBytes(primaryPath));
            CollectionAssert.AreEqual(priorBytes, File.ReadAllBytes(primaryPath + ".bak"));

            restore.Invoke(
                manager,
                new object[] { primaryPath, priorBytes, true, proposedBytes });
            CollectionAssert.AreEqual(priorBytes, File.ReadAllBytes(primaryPath));
            CollectionAssert.AreEqual(priorBytes, File.ReadAllBytes(primaryPath + ".bak"));
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(managerObject);
            if (Directory.Exists(directory))
                Directory.Delete(directory, true);
        }
    }

    [Test]
    public void RebirthCommitUsesPreparedSessionWhenLiveCaptureIsBlocked()
    {
        RebirthTransactionTestSetup setup =
            CreateRebirthTransactionTestSetup();
        string directory = Path.Combine(
            Path.GetTempPath(),
            "SweetMergeRebirthCapture_" + Guid.NewGuid().ToString("N"));
        string snapshotPath = Path.Combine(directory, "player_save_v2.json");
        try
        {
            setup.SessionManager.GetType()
                .GetMethod("SaveSession")
                .Invoke(setup.SessionManager, new object[] { setup.FreshSession });
            setup.SaveManager.GetType()
                .GetMethod(
                    "RecordSessionCustomerCapacity",
                    new[]
                    {
                        FindPlayerType("MergeSessionData"),
                        typeof(int),
                        typeof(string)
                    })
                .Invoke(setup.SaveManager,
                    new object[] { setup.FreshSession, 1, null });

            MethodInfo capture = setup.Controller.GetType().GetMethod(
                "TryCaptureSession");
            Assert.IsFalse((bool)capture.Invoke(setup.Controller, null),
                "Live capture must remain blocked during replacement.");
            Assert.IsTrue((bool)setup.Controller.GetType()
                .GetProperty("IsPreparedFreshSessionForCommit",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .GetValue(setup.Controller));

            MethodInfo commit = GetRebirthSnapshotCommitMethod(
                setup.SaveManager);
            object[] arguments = { 1, snapshotPath, false };
            Assert.IsTrue((bool)commit.Invoke(setup.SaveManager, arguments));
            Assert.IsTrue((bool)arguments[2]);

            object committed = JsonUtility.FromJson(
                File.ReadAllText(snapshotPath),
                FindPlayerType("PlayerSaveData"));
            Assert.AreEqual(1, GetField(committed, "completedRebirthCount"));
            Assert.AreEqual(0, GetField(GetField(committed, "economy"), "cash"));
            Assert.AreEqual(
                0,
                GetField(committed, "highestTierCreatedThisRun"));
            object mergeGameplay = GetField(committed, "mergeGameplay");
            var committedOrders = (System.Collections.IList)GetField(
                mergeGameplay, "customerOrders");
            Assert.AreEqual(
                4,
                GetField(committedOrders[0], "orderId"),
                "The committed save must use the staged fresh session.");
        }
        finally
        {
            DestroyRebirthTransactionTestSetup(setup);
            if (Directory.Exists(directory))
                Directory.Delete(directory, true);
        }
    }

    [Test]
    public void FailedRebirthSnapshotCommitRestoresPreviousSessionAndCapacity()
    {
        RebirthTransactionTestSetup setup =
            CreateRebirthTransactionTestSetup();
        string directory = Path.Combine(
            Path.GetTempPath(),
            "SweetMergeRebirthRollback_" + Guid.NewGuid().ToString("N"));
        string blockingFile = Path.Combine(directory, "not-a-directory");
        string snapshotPath = Path.Combine(
            blockingFile,
            "player_save_v2.json");
        object previousSession = setup.PreviousSession;
        object previousOrders = setup.PreviousOrderState;
        object previousPreview = setup.PreviousPreview;

        try
        {
            Directory.CreateDirectory(directory);
            File.WriteAllText(blockingFile, "preserve");
            setup.SessionManager.GetType()
                .GetMethod("SaveSession")
                .Invoke(setup.SessionManager, new object[] { setup.FreshSession });
            setup.SaveManager.GetType()
                .GetMethod(
                    "RecordSessionCustomerCapacity",
                    new[]
                    {
                        FindPlayerType("MergeSessionData"),
                        typeof(int),
                        typeof(string)
                    })
                .Invoke(
                    setup.SaveManager,
                    new object[] { setup.FreshSession, 1, null });

            LogAssert.Expect(
                LogType.Error,
                new Regex("^REBIRTH SAVE \\| Snapshot commit failed\\."));
            MethodInfo commit = GetRebirthSnapshotCommitMethod(
                setup.SaveManager);
            object[] arguments = { 1, snapshotPath, false };
            Assert.IsFalse((bool)commit.Invoke(setup.SaveManager, arguments));
            Assert.IsFalse((bool)arguments[2]);

            Type controllerType = setup.Controller.GetType();
            Type placementType = controllerType.GetNestedType(
                "DessertPlacement",
                BindingFlags.NonPublic);
            object emptyPlacements = Activator.CreateInstance(
                typeof(List<>).MakeGenericType(placementType));
            MethodInfo rollback = controllerType.GetMethod(
                "TryRestorePreviousLiveSession",
                BindingFlags.Instance | BindingFlags.NonPublic);
            Assert.IsTrue((bool)rollback.Invoke(
                setup.Controller,
                new[]
                {
                    emptyPlacements,
                    previousOrders,
                    previousPreview,
                    previousSession,
                    (object)1,
                    setup.Coordinator,
                    setup.SaveManager
                }));

            Assert.AreSame(
                previousSession,
                setup.SessionManager.GetType()
                    .GetProperty("SessionData").GetValue(setup.SessionManager));
            object[] capacityArguments = { previousSession, 1, 0 };
            Assert.IsTrue((bool)setup.SaveManager.GetType()
                .GetMethod("TryGetSessionCustomerCapacity")
                .Invoke(setup.SaveManager, capacityArguments));
            Assert.AreEqual(1, capacityArguments[2]);
            Assert.AreEqual("preserve", File.ReadAllText(blockingFile));
            Assert.AreEqual(0, setup.Progression.GetType()
                .GetProperty("CurrentRebirthCount").GetValue(setup.Progression));
            Assert.AreEqual(128, setup.Economy.GetType()
                .GetProperty("CurrentCash").GetValue(setup.Economy));
        }
        finally
        {
            DestroyRebirthTransactionTestSetup(setup);
            if (Directory.Exists(directory))
                Directory.Delete(directory, true);
        }
    }

    [Test]
    public void InvalidV2PrimaryOrBackupIsNeverReplacedAutomatically()
    {
        object save = Activator.CreateInstance(FindPlayerType("PlayerSaveData"));
        Type managerType = FindPlayerType("SaveManager");
        MethodInfo serialize = managerType.GetMethod(
            "SerializeWithCapacity",
            BindingFlags.Static | BindingFlags.NonPublic);
        MethodInfo createBackup = managerType.GetMethod(
            "CreateValidatedBackup",
            BindingFlags.Instance | BindingFlags.NonPublic);
        var managerObject = new GameObject("Invalid V2 save preservation test");
        string directory = Path.Combine(
            Path.GetTempPath(),
            "SweetMergeInvalidSave_" + Guid.NewGuid().ToString("N"));
        byte[] validBytes = System.Text.Encoding.UTF8.GetBytes(
            (string)serialize.Invoke(null, new[] { save, (object)0 }));
        byte[] invalidBytes = System.Text.Encoding.UTF8.GetBytes("{invalid}");
        try
        {
            Directory.CreateDirectory(directory);
            object manager = managerObject.AddComponent(managerType);

            string invalidPrimary = Path.Combine(directory, "invalid-primary.json");
            File.WriteAllBytes(invalidPrimary, invalidBytes);
            Assert.Throws<TargetInvocationException>(() =>
                createBackup.Invoke(manager, new object[] { invalidPrimary }));
            CollectionAssert.AreEqual(invalidBytes, File.ReadAllBytes(invalidPrimary));
            Assert.IsFalse(File.Exists(invalidPrimary + ".bak"));

            string invalidBackup = Path.Combine(directory, "invalid-backup.json");
            File.WriteAllBytes(invalidBackup, validBytes);
            File.WriteAllBytes(invalidBackup + ".bak", invalidBytes);
            Assert.Throws<TargetInvocationException>(() =>
                createBackup.Invoke(manager, new object[] { invalidBackup }));
            CollectionAssert.AreEqual(validBytes, File.ReadAllBytes(invalidBackup));
            CollectionAssert.AreEqual(
                invalidBytes,
                File.ReadAllBytes(invalidBackup + ".bak"));
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(managerObject);
            if (Directory.Exists(directory))
                Directory.Delete(directory, true);
        }
    }

    [Test]
    public void FreshSessionOrdersAndPreviewReplaceWithoutPublishingIntermediateState()
    {
        Type progressionType = FindPlayerType("PlayerProgressionManager");
        Type upgradeType = FindPlayerType("UpgradeDefinition");
        Type orderType = FindPlayerType("OrderManager");
        Type orderDefinitionType = FindPlayerType("CustomerOrderDefinition");
        Type spawnerType = FindPlayerType("DessertSpawner");
        Type dessertDefinitionType = FindPlayerType("DessertDefinition");

        var progressionObject = new GameObject("Fresh-session progression");
        progressionObject.SetActive(false);
        object progression = progressionObject.AddComponent(progressionType);
        string[] upgradePaths =
        {
            "Assets/_Game/Data/Upgrades/Upgrade_Oven.asset",
            "Assets/_Game/Data/Upgrades/Upgrade_BoardSpace.asset",
            "Assets/_Game/Data/Upgrades/Upgrade_Shelf.asset",
            "Assets/_Game/Data/Upgrades/Upgrade_Customer.asset",
            "Assets/_Game/Data/Upgrades/Upgrade_MoneyMultiplier.asset",
            "Assets/_Game/Data/Upgrades/Upgrade_Luck.asset"
        };
        string[] upgradeFields =
        {
            "ovenUpgrade", "boardSpaceUpgrade", "shelfUpgrade",
            "customerUpgrade", "moneyMultiplierUpgrade", "luckUpgrade"
        };
        for (int i = 0; i < upgradePaths.Length; i++)
            SetPrivateField(
                progression,
                upgradeFields[i],
                AssetDatabase.LoadMainAssetAtPath(upgradePaths[i]));

        var orderObject = new GameObject("Fresh-session orders");
        orderObject.SetActive(false);
        object orders = orderObject.AddComponent(orderType);
        SetPrivateField(orders, "progressionManager", progression);
        Array definitions = Array.CreateInstance(orderDefinitionType, 3);
        for (int i = 0; i < ExistingOrderDefinitionIds.Length; i++)
        {
            string path = AssetDatabase.GUIDToAssetPath(
                ExistingOrderDefinitionIds[i]);
            definitions.SetValue(
                AssetDatabase.LoadMainAssetAtPath(path),
                i);
        }
        SetPrivateField(orders, "orderPool", definitions);

        var spawnerObject = new GameObject("Fresh-session Oven preview");
        spawnerObject.SetActive(false);
        object spawner = spawnerObject.AddComponent(spawnerType);
        SetPrivateField(spawner, "progressionManager", progression);
        Array desserts = Array.CreateInstance(dessertDefinitionType, 30);
        for (int tier = 1; tier <= 30; tier++)
            desserts.SetValue(
                AssetDatabase.LoadMainAssetAtPath(
                    $"{DessertFolder}/Dessert_{tier:00}.asset"),
                tier - 1);
        SetPrivateField(spawner, "dessertDefinitions", desserts);
        SetPrivateField(orders, "dessertSpawner", spawner);

        try
        {
            progressionObject.SetActive(true);
            orderObject.SetActive(true);
            spawnerObject.SetActive(true);
            MethodInfo prepareOrders = orderType.GetMethod(
                "TryPrepareFreshSessionOrders",
                BindingFlags.Instance | BindingFlags.NonPublic);
            MethodInfo applyOrders = orderType.GetMethod(
                "ApplyPreparedFreshSessionOrders",
                BindingFlags.Instance | BindingFlags.NonPublic);
            MethodInfo publishOrders = orderType.GetMethod(
                "PublishPreparedFreshSessionOrders",
                BindingFlags.Instance | BindingFlags.NonPublic);
            EventInfo generatedEvent = orderType.GetEvent("OrderGenerated");
            int generatedEvents = 0;
            Delegate generatedHandler = CreateCountingHandler(
                generatedEvent.EventHandlerType,
                nameof(RecordGeneratedEvent));
            activeGeneratedEventCount = 0;
            generatedEvent.AddEventHandler(orders, generatedHandler);

            object[] firstPlan = { null, 0 };
            Assert.IsTrue((bool)prepareOrders.Invoke(orders, firstPlan));
            Assert.IsTrue((bool)applyOrders.Invoke(
                orders,
                new[] { firstPlan[0], firstPlan[1] }));
            Array firstOrders = (Array)firstPlan[0];
            int firstOrderId = (int)GetField(firstOrders.GetValue(0), "orderId");

            object[] secondPlan = { null, 0 };
            Assert.IsTrue((bool)prepareOrders.Invoke(orders, secondPlan));
            Assert.IsTrue((bool)applyOrders.Invoke(
                orders,
                new[] { secondPlan[0], secondPlan[1] }));
            Assert.AreEqual(0, activeGeneratedEventCount,
                "Prepared replacements must not publish before the full session is ready.");
            Assert.AreEqual(
                1,
                orderType.GetProperty("ActiveOrderCount").GetValue(orders));
            Array secondOrders = (Array)secondPlan[0];
            Assert.AreNotEqual(
                firstOrderId,
                GetField(secondOrders.GetValue(0), "orderId"),
                "Replacement must not retain a prior order identity.");

            SetPrivateField(
                spawner,
                "nextDessert",
                ((UnityEngine.Object[])desserts)[29]);
            MethodInfo preparePreview = spawnerType.GetMethod(
                "TryPrepareFreshSessionPreview",
                BindingFlags.Instance | BindingFlags.NonPublic);
            object[] previewPlan = { null };
            Assert.IsTrue((bool)preparePreview.Invoke(spawner, previewPlan));
            MethodInfo setPreview = spawnerType.GetMethod(
                "SetFreshSessionPreview",
                BindingFlags.Instance | BindingFlags.NonPublic);
            Assert.IsTrue((bool)setPreview.Invoke(
                spawner,
                new[] { previewPlan[0], (object)false }));
            Assert.AreNotSame(
                ((UnityEngine.Object[])desserts)[29],
                spawnerType.GetProperty("NextDessert").GetValue(spawner),
                "The locked old preview must be replaced with a valid fresh preview.");

            publishOrders.Invoke(orders, null);
            Assert.AreEqual(1, activeGeneratedEventCount);
            generatedEvent.RemoveEventHandler(orders, generatedHandler);
            generatedEvents = activeGeneratedEventCount;
            Assert.AreEqual(1, generatedEvents);
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(spawnerObject);
            UnityEngine.Object.DestroyImmediate(orderObject);
            UnityEngine.Object.DestroyImmediate(progressionObject);
        }
    }

    [Test]
    public void FreshSessionReplacementClearsLiveStateAndPublishesOncePerReplacement()
    {
        ReplacementFixture fixture = CreateReplacementFixture();
        EventInfo boardChanged = fixture.Grid.GetType().GetEvent("BoardChanged");
        EventInfo shelfChanged = fixture.Shelf.GetType().GetEvent("ShelfChanged");
        EventInfo generated = fixture.Orders.GetType().GetEvent("OrderGenerated");
        EventInfo previewChanged = FindPlayerType("GameplayEvents")
            .GetEvent("NextDessertChanged");
        Delegate boardHandler = CreateCountingHandler(
            boardChanged.EventHandlerType, nameof(RecordBoardChanged));
        Delegate shelfHandler = CreateCountingHandler(
            shelfChanged.EventHandlerType, nameof(RecordShelfChanged));
        Delegate generatedHandler = CreateCountingHandler(
            generated.EventHandlerType, nameof(RecordGeneratedEvent));
        Delegate previewHandler = CreateCountingHandler(
            previewChanged.EventHandlerType, nameof(RecordPreviewChanged));
        boardChanged.AddEventHandler(fixture.Grid, boardHandler);
        shelfChanged.AddEventHandler(fixture.Shelf, shelfHandler);
        generated.AddEventHandler(fixture.Orders, generatedHandler);
        previewChanged.AddEventHandler(null, previewHandler);

        try
        {
            int boardCapacity = (int)fixture.Grid.GetType()
                .GetProperty("UnlockedCellCount").GetValue(fixture.Grid);
            int shelfCapacity = (int)fixture.Shelf.GetType()
                .GetProperty("UnlockedSlotCount").GetValue(fixture.Shelf);
            int customerCapacity = (int)fixture.Orders.GetType()
                .GetProperty("ActiveCustomerCount").GetValue(fixture.Orders);
            Assert.AreEqual(1, customerCapacity);

            for (int replacement = 0; replacement < 2; replacement++)
            {
                activeGeneratedEventCount = 0;
                activeBoardChangedCount = 0;
                activeShelfChangedCount = 0;
                activePreviewChangedCount = 0;
                Array previousOrders = GetActiveOrders(fixture.Orders);
                int previousNextOrderId = (int)fixture.Orders.GetType()
                    .GetProperty("NextOrderId").GetValue(fixture.Orders);

                Assert.IsTrue((bool)fixture.Controller.GetType()
                    .GetMethod("TryReplaceWithFreshSession")
                    .Invoke(fixture.Controller, null));

                Assert.AreEqual(0, (int)fixture.Grid.GetType()
                    .GetProperty("OccupiedCellCount").GetValue(fixture.Grid));
                Assert.AreEqual(0, (int)fixture.Shelf.GetType()
                    .GetProperty("OccupiedSlotCount").GetValue(fixture.Shelf));
                Assert.AreEqual(boardCapacity, (int)fixture.Grid.GetType()
                    .GetProperty("UnlockedCellCount").GetValue(fixture.Grid));
                Assert.AreEqual(shelfCapacity, (int)fixture.Shelf.GetType()
                    .GetProperty("UnlockedSlotCount").GetValue(fixture.Shelf));
                Assert.AreEqual(customerCapacity, (int)fixture.Orders.GetType()
                    .GetProperty("ActiveCustomerCount").GetValue(fixture.Orders));

                Array activeOrders = GetActiveOrders(fixture.Orders);
                Assert.AreEqual(customerCapacity, activeOrders.Length);
                for (int i = 0; i < activeOrders.Length; i++)
                {
                    object order = activeOrders.GetValue(i);
                    Assert.IsTrue((bool)order.GetType().GetProperty("IsValid")
                        .GetValue(order));
                    Assert.Greater((int)order.GetType().GetProperty("OrderId")
                        .GetValue(order), previousNextOrderId - 1);
                    Assert.AreNotSame(previousOrders.GetValue(i), order);
                }

                object preview = fixture.Spawner.GetType()
                    .GetProperty("NextDessert").GetValue(fixture.Spawner);
                Assert.IsNotNull(preview);
                if (replacement == 0)
                    Assert.AreNotSame(fixture.InitialPreview, preview);
                Assert.IsTrue((bool)fixture.Progression.GetType()
                    .GetMethod("IsDessertTierUnlocked")
                    .Invoke(fixture.Progression, new[]
                    {
                        preview.GetType().GetProperty("Tier").GetValue(preview)
                    }));
                Assert.IsTrue((bool)fixture.Controller.GetType()
                    .GetProperty("IsRestorationVerified").GetValue(fixture.Controller));
                Assert.IsTrue((bool)fixture.Coordinator.GetType()
                    .GetProperty("IsGameplayReady").GetValue(fixture.Coordinator));
                Assert.IsTrue((bool)fixture.SaveManager.GetType()
                    .GetProperty("IsLifecycleSavingReady").GetValue(fixture.SaveManager));
                Assert.AreEqual(1, activeBoardChangedCount);
                Assert.AreEqual(1, activeShelfChangedCount);
                Assert.AreEqual(customerCapacity, activeGeneratedEventCount);
                Assert.AreEqual(1, activePreviewChangedCount);

                object savedSession = fixture.SessionManager.GetType()
                    .GetProperty("SessionData").GetValue(fixture.SessionManager);
                Assert.AreEqual(0, GetPublicList(savedSession, "boardDesserts").Count);
                Assert.AreEqual(0, GetPublicList(savedSession, "shelfDesserts").Count);
                Assert.AreEqual(
                    customerCapacity,
                    GetPublicList(savedSession, "customerOrders").Count);
            }
        }
        finally
        {
            boardChanged.RemoveEventHandler(fixture.Grid, boardHandler);
            shelfChanged.RemoveEventHandler(fixture.Shelf, shelfHandler);
            generated.RemoveEventHandler(fixture.Orders, generatedHandler);
            previewChanged.RemoveEventHandler(null, previewHandler);
            DestroyReplacementFixture(fixture);
        }
    }

    [Test]
    public void FreshSessionReplacementApplyFailureRestoresOriginalLiveStateWithoutEvents()
    {
        ReplacementFixture fixture = CreateReplacementFixture();
        EventInfo boardChanged = fixture.Grid.GetType().GetEvent("BoardChanged");
        EventInfo shelfChanged = fixture.Shelf.GetType().GetEvent("ShelfChanged");
        EventInfo generated = fixture.Orders.GetType().GetEvent("OrderGenerated");
        EventInfo previewChanged = FindPlayerType("GameplayEvents")
            .GetEvent("NextDessertChanged");
        Delegate boardHandler = CreateCountingHandler(
            boardChanged.EventHandlerType, nameof(RecordBoardChanged));
        Delegate shelfHandler = CreateCountingHandler(
            shelfChanged.EventHandlerType, nameof(RecordShelfChanged));
        Delegate generatedHandler = CreateCountingHandler(
            generated.EventHandlerType, nameof(RecordGeneratedEvent));
        Delegate previewHandler = CreateCountingHandler(
            previewChanged.EventHandlerType, nameof(RecordPreviewChanged));
        boardChanged.AddEventHandler(fixture.Grid, boardHandler);
        shelfChanged.AddEventHandler(fixture.Shelf, shelfHandler);
        generated.AddEventHandler(fixture.Orders, generatedHandler);
        previewChanged.AddEventHandler(null, previewHandler);

        object originalBoardDessert = fixture.Cells[0].GetType()
            .GetProperty("CurrentDessert").GetValue(fixture.Cells[0]);
        object originalShelfDessert = fixture.Slots[0].GetType()
            .GetProperty("CurrentDessert").GetValue(fixture.Slots[0]);
        Array originalOrders = GetActiveOrders(fixture.Orders);
        object originalPreview = fixture.Spawner.GetType()
            .GetProperty("NextDessert").GetValue(fixture.Spawner);
        object originalSession = fixture.SessionManager.GetType()
            .GetProperty("SessionData").GetValue(fixture.SessionManager);
        int capacity = (int)fixture.Orders.GetType()
            .GetProperty("ActiveCustomerCount").GetValue(fixture.Orders);

        ReplacementApplyFailureTrigger failureTrigger =
            ((UnityEngine.Component)originalBoardDessert).gameObject
                .AddComponent<ReplacementApplyFailureTrigger>();
        failureTrigger.OnDisabled = () =>
        {
            SetPrivateField(fixture.Orders, "pendingFreshSessionOrders", null);
            SetPrivateField(fixture.Orders, "pendingFreshSessionNextOrderId", 0);
        };

        try
        {
            activeGeneratedEventCount = 0;
            activeBoardChangedCount = 0;
            activeShelfChangedCount = 0;
            activePreviewChangedCount = 0;
            LogAssert.Expect(
                LogType.Error,
                "SESSION REPLACEMENT FAILED | Prepared state could not be applied.");

            Assert.IsFalse((bool)fixture.Controller.GetType()
                .GetMethod("TryReplaceWithFreshSession")
                .Invoke(fixture.Controller, null));

            Assert.AreSame(originalBoardDessert, fixture.Cells[0].GetType()
                .GetProperty("CurrentDessert").GetValue(fixture.Cells[0]));
            Assert.AreSame(originalShelfDessert, fixture.Slots[0].GetType()
                .GetProperty("CurrentDessert").GetValue(fixture.Slots[0]));
            Assert.IsTrue(((UnityEngine.Component)originalBoardDessert).gameObject.activeSelf);
            Assert.IsTrue(((UnityEngine.Component)originalShelfDessert).gameObject.activeSelf);
            CollectionAssert.AreEqual(originalOrders, GetActiveOrders(fixture.Orders));
            Assert.AreSame(originalPreview, fixture.Spawner.GetType()
                .GetProperty("NextDessert").GetValue(fixture.Spawner));
            Assert.AreNotSame(
                originalSession,
                fixture.SessionManager.GetType().GetProperty("SessionData")
                    .GetValue(fixture.SessionManager),
                "Rollback should persist a fresh snapshot of the restored state.");

            object restoredSession = fixture.SessionManager.GetType()
                .GetProperty("SessionData").GetValue(fixture.SessionManager);
            Assert.AreEqual(1, GetPublicList(restoredSession, "boardDesserts").Count);
            Assert.AreEqual(1, GetPublicList(restoredSession, "shelfDesserts").Count);
            Assert.AreEqual(capacity, GetPublicList(restoredSession, "customerOrders").Count);
            object[] capacityArguments =
            {
                restoredSession,
                capacity,
                0
            };
            Assert.IsTrue((bool)fixture.SaveManager.GetType()
                .GetMethod("TryGetSessionCustomerCapacity")
                .Invoke(fixture.SaveManager, capacityArguments));
            Assert.AreEqual(capacity, capacityArguments[2]);
            Assert.IsTrue((bool)fixture.Controller.GetType()
                .GetProperty("IsRestorationVerified").GetValue(fixture.Controller));
            Assert.IsTrue((bool)fixture.Coordinator.GetType()
                .GetProperty("IsGameplayReady").GetValue(fixture.Coordinator));
            Assert.IsTrue((bool)fixture.SaveManager.GetType()
                .GetProperty("IsLifecycleSavingReady").GetValue(fixture.SaveManager));
            Assert.AreEqual(0, activeBoardChangedCount);
            Assert.AreEqual(0, activeShelfChangedCount);
            Assert.AreEqual(0, activeGeneratedEventCount);
            Assert.AreEqual(0, activePreviewChangedCount);
        }
        finally
        {
            failureTrigger.OnDisabled = null;
            boardChanged.RemoveEventHandler(fixture.Grid, boardHandler);
            shelfChanged.RemoveEventHandler(fixture.Shelf, shelfHandler);
            generated.RemoveEventHandler(fixture.Orders, generatedHandler);
            previewChanged.RemoveEventHandler(null, previewHandler);
            DestroyReplacementFixture(fixture);
        }
    }

    private sealed class ReplacementFixture
    {
        public readonly List<GameObject> Objects = new List<GameObject>();
        public readonly List<object> Cells = new List<object>();
        public readonly List<object> Slots = new List<object>();
        public object Progression;
        public object Grid;
        public object Shelf;
        public object Orders;
        public object Spawner;
        public object Controller;
        public object Coordinator;
        public object SaveManager;
        public object SessionManager;
        public object InitialPreview;
    }

    private ReplacementFixture CreateReplacementFixture()
    {
        var fixture = new ReplacementFixture();
        try
        {
            object saveManager = AddRuntimeComponent(fixture, "SaveManager");
            SetStaticPropertyBackingField("SaveManager", "Instance", saveManager);
            object economy = AddRuntimeComponent(fixture, "EconomyManager");
            SetStaticPropertyBackingField("EconomyManager", "Instance", economy);
            object progression = AddRuntimeComponent(
                fixture, "PlayerProgressionManager", false);
            SetProgressionDefinitions(progression);
            SetPrivateField(progression, "ovenLevel", 6);
            fixture.Progression = progression;
            ((UnityEngine.Component)progression).gameObject.SetActive(true);
            SetStaticPropertyBackingField(
                "PlayerProgressionManager", "Instance", progression);

            object coordinator = AddRuntimeComponent(
                fixture, "GameStartupCoordinator");
            SetStaticPropertyBackingField(
                "GameStartupCoordinator", "Instance", coordinator);
            SetPrivateField(
                coordinator,
                "<Status>k__BackingField",
                Enum.Parse(
                    coordinator.GetType().GetNestedType("StartupStatus"),
                    "NewGame"));
            object sessionManager = AddRuntimeComponent(
                fixture, "MergeSessionManager");
            SetStaticPropertyBackingField(
                "MergeSessionManager", "Instance", sessionManager);

            int boardCapacity = (int)progression.GetType()
                .GetProperty("ActiveBoardCells").GetValue(progression);
            int shelfCapacity = (int)progression.GetType()
                .GetProperty("ShelfCapacity").GetValue(progression);
            Assert.Greater(boardCapacity, 0);
            Assert.Greater(shelfCapacity, 0, "The integration fixture needs an unlocked shelf slot.");

            object grid = AddRuntimeComponent(fixture, "GridManager", false);
            SetPrivateField(grid, "columns", 0);
            SetPrivateField(grid, "rows", 0);
            SetPrivateField(grid, "progressionManager", progression);
            InvokeLifecycle(grid, "Awake");
            ((UnityEngine.Component)grid).gameObject.SetActive(true);
            fixture.Grid = grid;
            IList cellList = (IList)grid.GetType()
                .GetProperty("Cells").GetValue(grid);
            for (int i = 0; i < boardCapacity + 1; i++)
            {
                object cell = AddRuntimeComponent(fixture, "GridCell");
                cell.GetType().GetMethod("SetUnlocked")
                    .Invoke(cell, new object[] { i < boardCapacity });
                cellList.Add(cell);
                fixture.Cells.Add(cell);
            }

            object shelf = AddRuntimeComponent(fixture, "ShelfManager", false);
            SetPrivateField(shelf, "progressionManager", progression);
            Array slots = Array.CreateInstance(
                FindPlayerType("ShelfSlot"),
                shelfCapacity + 1);
            for (int i = 0; i < slots.Length; i++)
            {
                object slot = AddRuntimeComponent(fixture, "ShelfSlot");
                slot.GetType().GetMethod("SetUnlocked")
                    .Invoke(slot, new object[] { i < shelfCapacity });
                slots.SetValue(slot, i);
                fixture.Slots.Add(slot);
            }
            SetPrivateField(shelf, "slots", slots);
            ((UnityEngine.Component)shelf).gameObject.SetActive(true);
            fixture.Shelf = shelf;

            object orders = AddRuntimeComponent(fixture, "OrderManager", false);
            SetPrivateField(orders, "progressionManager", progression);
            SetPrivateField(orders, "gridManager", grid);
            SetPrivateField(orders, "orderPool", LoadOrderDefinitions());
            ((UnityEngine.Component)orders).gameObject.SetActive(true);
            InvokeLifecycle(orders, "Awake");
            fixture.Orders = orders;

            object spawner = AddRuntimeComponent(fixture, "DessertSpawner", false);
            SetPrivateField(spawner, "progressionManager", progression);
            SetPrivateField(spawner, "gridManager", grid);
            SetPrivateField(spawner, "dessertDefinitions", LoadDessertDefinitions());
            ((UnityEngine.Component)spawner).gameObject.SetActive(true);
            SetPrivateField(orders, "dessertSpawner", spawner);
            SetPrivateField(sessionManager, "dessertSpawner", spawner);
            fixture.InitialPreview = AssetDatabase.LoadMainAssetAtPath(
                $"{DessertFolder}/Dessert_30.asset");
            SetPrivateField(spawner, "nextDessert", fixture.InitialPreview);
            fixture.Spawner = spawner;

            SeedActiveOrders(orders);
            PlaceFixtureDessert(fixture, 0, 0, 1);

            object controller = AddRuntimeComponent(
                fixture, "MergeSessionController", false);
            SetPrivateField(controller, "gridManager", grid);
            SetPrivateField(controller, "shelfManager", shelf);
            SetPrivateField(controller, "orderManager", orders);
            SetPrivateField(controller, "dessertSpawner", spawner);
            ((UnityEngine.Component)controller).gameObject.SetActive(true);
            InvokeLifecycle(controller, "Awake");
            SetPrivateField(controller, "<IsRestorationVerified>k__BackingField", true);
            bool readinessConfirmed = (bool)coordinator.GetType()
                .GetMethod("ConfirmGameplayRestoration")
                .Invoke(coordinator, new[] { controller });
            Assert.IsTrue(
                readinessConfirmed,
                "Fixture readiness was rejected. Status=" +
                coordinator.GetType().GetProperty("Status").GetValue(coordinator) +
                ", save manager=" + (FindSingleton("SaveManager") != null) +
                ", economy=" + (FindSingleton("EconomyManager") != null));
            object[] validationArguments = { null, -1 };
            bool liveStateValid = (bool)controller.GetType()
                .GetMethod("ValidateLiveState", BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(controller, validationArguments);
            Assert.IsTrue(
                liveStateValid,
                "Fixture live-state validation failed: " +
                (validationArguments[0] ?? "no reason provided"));
            bool captured = (bool)controller.GetType()
                .GetMethod("TryCaptureSession").Invoke(controller, null);
            Assert.IsTrue(captured, "Controller could not capture the initialized fixture.");

            fixture.Controller = controller;
            fixture.Coordinator = coordinator;
            fixture.SaveManager = saveManager;
            fixture.SessionManager = sessionManager;
            Assert.AreSame(economy, FindSingleton("EconomyManager"));
            return fixture;
        }
        catch
        {
            DestroyReplacementFixture(fixture);
            throw;
        }
    }

    private object AddRuntimeComponent(
        ReplacementFixture fixture,
        string typeName,
        bool activate = true)
    {
        var gameObject = new GameObject(typeName + " integration test");
        fixture.Objects.Add(gameObject);
        gameObject.SetActive(activate);
        if (typeName == "Dessert")
        {
            var visual = new GameObject("Visual");
            visual.transform.SetParent(gameObject.transform, false);
            visual.AddComponent<SpriteRenderer>();
        }
        object component = gameObject.AddComponent(FindPlayerType(typeName));
        return component;
    }

    private static void InvokeLifecycle(object target, string methodName)
    {
        MethodInfo method = target.GetType().GetMethod(
            methodName,
            BindingFlags.Instance | BindingFlags.NonPublic);
        Assert.IsNotNull(method, $"Missing {methodName} on {target.GetType().Name}.");
        method.Invoke(target, null);
    }

    private static void SetStaticPropertyBackingField(
        string typeName,
        string propertyName,
        object value)
    {
        FieldInfo field = FindPlayerType(typeName).GetField(
            $"<{propertyName}>k__BackingField",
            BindingFlags.Static | BindingFlags.NonPublic);
        Assert.IsNotNull(
            field,
            $"Missing backing field for {typeName}.{propertyName}.");
        field.SetValue(null, value);
    }

    private void SetProgressionDefinitions(object progression)
    {
        string[] paths =
        {
            "Assets/_Game/Data/Upgrades/Upgrade_Oven.asset",
            "Assets/_Game/Data/Upgrades/Upgrade_BoardSpace.asset",
            "Assets/_Game/Data/Upgrades/Upgrade_Shelf.asset",
            "Assets/_Game/Data/Upgrades/Upgrade_Customer.asset",
            "Assets/_Game/Data/Upgrades/Upgrade_MoneyMultiplier.asset",
            "Assets/_Game/Data/Upgrades/Upgrade_Luck.asset"
        };
        string[] fields =
        {
            "ovenUpgrade", "boardSpaceUpgrade", "shelfUpgrade",
            "customerUpgrade", "moneyMultiplierUpgrade", "luckUpgrade"
        };
        for (int i = 0; i < paths.Length; i++)
        {
            UnityEngine.Object definition = AssetDatabase.LoadMainAssetAtPath(paths[i]);
            Assert.IsNotNull(definition, $"Missing upgrade definition: {paths[i]}");
            SetPrivateField(progression, fields[i], definition);
        }
    }

    private Array LoadOrderDefinitions()
    {
        Type definitionType = FindPlayerType("CustomerOrderDefinition");
        Array definitions = Array.CreateInstance(definitionType, ExistingOrderDefinitionIds.Length);
        for (int i = 0; i < ExistingOrderDefinitionIds.Length; i++)
        {
            string path = AssetDatabase.GUIDToAssetPath(ExistingOrderDefinitionIds[i]);
            UnityEngine.Object definition = AssetDatabase.LoadMainAssetAtPath(path);
            Assert.IsNotNull(definition, $"Missing order definition {ExistingOrderDefinitionIds[i]}");
            definitions.SetValue(definition, i);
        }
        return definitions;
    }

    private Array LoadDessertDefinitions()
    {
        Type definitionType = FindPlayerType("DessertDefinition");
        Array definitions = Array.CreateInstance(definitionType, 30);
        for (int tier = 1; tier <= 30; tier++)
        {
            UnityEngine.Object definition = AssetDatabase.LoadMainAssetAtPath(
                $"{DessertFolder}/Dessert_{tier:00}.asset");
            Assert.IsNotNull(definition, $"Missing dessert definition for tier {tier}");
            definitions.SetValue(definition, tier - 1);
        }
        return definitions;
    }

    private static object GenerateProceduralOrder(
        Array definitions,
        int ovenLevel,
        int maxUnlockedTier,
        int shapeRoll,
        int difficultyRoll,
        int referencePoolRoll)
    {
        Type generatorType = FindPlayerType("ProceduralCustomerOrderGenerator");
        MethodInfo generate = generatorType.GetMethod(
            "TryGenerateFromRolls",
            BindingFlags.Public | BindingFlags.Static);
        Assert.IsNotNull(generate, "Procedural order roll entry point is missing.");

        object[] arguments =
        {
            definitions,
            ovenLevel,
            maxUnlockedTier,
            shapeRoll,
            difficultyRoll,
            referencePoolRoll,
            null
        };
        Assert.IsTrue(
            (bool)generate.Invoke(null, arguments),
            $"Could not generate an order for Oven L{ovenLevel}.");
        Assert.IsNotNull(arguments[6]);
        return arguments[6];
    }

    private static object GetPropertyValue(object target, string propertyName)
    {
        PropertyInfo property = target.GetType().GetProperty(propertyName);
        Assert.IsNotNull(property, $"Missing property {propertyName}.");
        return property.GetValue(target);
    }

    private static void AssertRequirement(
        object requirement,
        int expectedTier,
        int expectedAmount)
    {
        object dessert = GetPropertyValue(requirement, "Dessert");
        Assert.AreEqual(expectedTier, GetPropertyValue(dessert, "Tier"));
        Assert.AreEqual(expectedAmount, GetPropertyValue(requirement, "Amount"));
    }

    private static void AssertOrdersEqual(object expected, object actual)
    {
        Assert.AreEqual(
            GetPropertyValue(expected, "OrderId"),
            GetPropertyValue(actual, "OrderId"));
        Assert.AreEqual(
            GetPropertyValue(expected, "DisplayName"),
            GetPropertyValue(actual, "DisplayName"));
        Assert.AreEqual(
            GetPropertyValue(expected, "CashReward"),
            GetPropertyValue(actual, "CashReward"));

        List<object> expectedRequirements = ((IEnumerable)GetPropertyValue(
                expected,
                "Requirements"))
            .Cast<object>().ToList();
        List<object> actualRequirements = ((IEnumerable)GetPropertyValue(
                actual,
                "Requirements"))
            .Cast<object>().ToList();
        Assert.AreEqual(expectedRequirements.Count, actualRequirements.Count);
        for (int i = 0; i < expectedRequirements.Count; i++)
        {
            Assert.AreEqual(
                GetPropertyValue(
                    GetPropertyValue(expectedRequirements[i], "Dessert"),
                    "Tier"),
                GetPropertyValue(
                    GetPropertyValue(actualRequirements[i], "Dessert"),
                    "Tier"));
            Assert.AreEqual(
                GetPropertyValue(expectedRequirements[i], "Amount"),
                GetPropertyValue(actualRequirements[i], "Amount"));
        }
    }

    private static void AssertOrderRequirementsWithinTierCap(
        object order,
        int maxUnlockedTier)
    {
        foreach (object requirement in (IEnumerable)GetPropertyValue(
                     order,
                     "Requirements"))
        {
            int tier = (int)GetPropertyValue(
                GetPropertyValue(requirement, "Dessert"),
                "Tier");
            Assert.That(tier, Is.InRange(1, maxUnlockedTier));
        }
    }

    private void SeedActiveOrders(object orders)
    {
        object[] plan = { null, 0 };
        Assert.IsTrue((bool)orders.GetType()
            .GetMethod("TryPrepareFreshSessionOrders", BindingFlags.Instance | BindingFlags.NonPublic)
            .Invoke(orders, plan));
        Assert.IsTrue((bool)orders.GetType()
            .GetMethod("ApplyPreparedFreshSessionOrders", BindingFlags.Instance | BindingFlags.NonPublic)
            .Invoke(orders, new[] { plan[0], plan[1] }));
    }

    private void PlaceFixtureDessert(
        ReplacementFixture fixture,
        int cellIndex,
        int slotIndex,
        int tier)
    {
        UnityEngine.Object definition = AssetDatabase.LoadMainAssetAtPath(
            $"{DessertFolder}/Dessert_{tier:00}.asset");
        object boardDessert = AddRuntimeComponent(fixture, "Dessert");
        boardDessert.GetType().GetMethod("Initialize").Invoke(
            boardDessert, new[] { definition, fixture.Cells[cellIndex] });
        fixture.Cells[cellIndex].GetType().GetMethod("PlaceDessert")
            .Invoke(fixture.Cells[cellIndex], new[] { boardDessert, (object)true });

        object shelfDessert = AddRuntimeComponent(fixture, "Dessert");
        shelfDessert.GetType().GetMethod("Initialize").Invoke(
            shelfDessert, new[] { definition, null });
        object slot = fixture.Slots[slotIndex];
        Assert.IsTrue((bool)slot.GetType().GetProperty("IsUnlocked").GetValue(slot),
            $"Fixture shelf slot {slotIndex} should be unlocked.");
        Assert.IsTrue((bool)slot.GetType().GetProperty("IsEmpty").GetValue(slot),
            $"Fixture shelf slot {slotIndex} should be empty.");
        Assert.IsTrue((bool)fixture.Slots[slotIndex].GetType()
            .GetMethod("TryStoreDessert")
            .Invoke(slot, new[] { shelfDessert, (object)true }),
            $"Fixture shelf slot {slotIndex} rejected tier {tier}.");
    }

    private static Array GetActiveOrders(object orderManager)
    {
        return ((IEnumerable)orderManager.GetType()
                .GetProperty("CustomerOrders").GetValue(orderManager))
            .Cast<object>()
            .Where(order => order != null)
            .ToArray();
    }

    private static IList GetPublicList(object target, string fieldName)
    {
        return (IList)target.GetType()
            .GetField(fieldName, BindingFlags.Instance | BindingFlags.Public)
            .GetValue(target);
    }

    private static object FindSingleton(string typeName)
    {
        return FindPlayerType(typeName).GetProperty(
            "Instance",
            BindingFlags.Static | BindingFlags.Public)
            .GetValue(null);
    }

    private static void DestroyReplacementFixture(ReplacementFixture fixture)
    {
        for (int i = fixture.Objects.Count - 1; i >= 0; i--)
            if (fixture.Objects[i] != null)
                UnityEngine.Object.DestroyImmediate(fixture.Objects[i]);
    }

    private int activeBoardChangedCount;
    private int activeShelfChangedCount;
    private int activePreviewChangedCount;

    private void RecordBoardChanged()
    {
        activeBoardChangedCount++;
    }

    private void RecordShelfChanged()
    {
        activeShelfChangedCount++;
    }

    private void RecordPreviewChanged()
    {
        activePreviewChangedCount++;
    }

    private static bool TryCalculateSpawnPoolSelectorBounds(
        Rect previewBounds,
        Rect safeAreaBounds,
        Vector2 panelSize,
        float gap,
        out Rect selectorBounds)
    {
        MethodInfo method = FindPlayerType("SpawnPoolSelectorUI").GetMethod(
            "TryCalculateSelectorBounds",
            BindingFlags.Public | BindingFlags.Static);
        Assert.IsNotNull(method,
            "SpawnPoolSelectorUI bounds method was not found.");
        object[] arguments =
        {
            previewBounds,
            safeAreaBounds,
            panelSize,
            gap,
            default(Rect)
        };
        bool fits = (bool)method.Invoke(null, arguments);
        selectorBounds = (Rect)arguments[4];
        return fits;
    }

    private static Type FindPlayerType(string typeName)
    {
        Type type = AppDomain.CurrentDomain.GetAssemblies()
            .Select(assembly => assembly.GetType(typeName, false))
            .FirstOrDefault(candidate => candidate != null);
        Assert.IsNotNull(type, $"Could not find runtime type {typeName}");
        return type;
    }

    private static int GetShelfSlotIndex(string objectName)
    {
        const string prefix = "ShelfSlot_";
        if (!objectName.StartsWith(prefix, StringComparison.Ordinal) ||
            !int.TryParse(objectName.Substring(prefix.Length), out int slotNumber) ||
            slotNumber < 1 ||
            slotNumber > 5)
            return -1;

        return slotNumber - 1;
    }

    private static void AssertBoundsContained(
        Bounds outer,
        Bounds inner,
        string message)
    {
        const float tolerance = 0.0001f;
        Assert.GreaterOrEqual(inner.min.x, outer.min.x - tolerance, message);
        Assert.LessOrEqual(inner.max.x, outer.max.x + tolerance, message);
        Assert.GreaterOrEqual(inner.min.y, outer.min.y - tolerance, message);
        Assert.LessOrEqual(inner.max.y, outer.max.y + tolerance, message);
    }

    private static Vector4 CalculateSafeAreaAnchors(
        Vector2 baseAnchorMin,
        Vector2 baseAnchorMax,
        Rect safeArea,
        Rect canvasPixelRect)
    {
        MethodInfo method = FindPlayerType("SafeAreaFitter").GetMethod(
            "CalculateSafeAreaAnchors",
            BindingFlags.Public | BindingFlags.Static);
        Assert.IsNotNull(method, "SafeAreaFitter conversion method was not found.");
        return (Vector4)method.Invoke(null, new object[]
        {
            baseAnchorMin,
            baseAnchorMax,
            safeArea,
            canvasPixelRect
        });
    }

    private static Vector2 ReadSceneVector2(
        string serializedObject,
        string fieldName)
    {
        Match match = Regex.Match(
            serializedObject,
            $@"(?m)^  {Regex.Escape(fieldName)}: \{{x: (-?[\d.]+), y: (-?[\d.]+)\}}");
        Assert.IsTrue(match.Success,
            $"Scene field {fieldName} was not found.");
        return new Vector2(
            float.Parse(
                match.Groups[1].Value,
                System.Globalization.CultureInfo.InvariantCulture),
            float.Parse(
                match.Groups[2].Value,
                System.Globalization.CultureInfo.InvariantCulture));
    }

    private static object GetCampaignCompletionPersistenceState(
        string stateName)
    {
        Type stateType = FindPlayerType(
            "CampaignCompletionPersistenceState");
        Assert.IsTrue(stateType.IsEnum,
            "Campaign completion persistence state must remain an enum.");
        return Enum.Parse(stateType, stateName);
    }

    private static float ReadSceneFloat(
        string serializedObject,
        string fieldName)
    {
        Match match = Regex.Match(
            serializedObject,
            $@"(?m)^[ \t]+{Regex.Escape(fieldName)}: (-?[\d.]+)\r?$");
        Assert.IsTrue(match.Success,
            $"Scene field {fieldName} was not found.");
        return float.Parse(
            match.Groups[1].Value,
            System.Globalization.CultureInfo.InvariantCulture);
    }

    private static object GetField(object target, string fieldName)
    {
        return target.GetType()
            .GetField(fieldName, BindingFlags.Instance | BindingFlags.Public)
            .GetValue(target);
    }

    private static void SetField(object target, string fieldName, object value)
    {
        target.GetType()
            .GetField(fieldName, BindingFlags.Instance | BindingFlags.Public)
            .SetValue(target, value);
    }

    private static void SetPrivateField(
        object target,
        string fieldName,
        object value)
    {
        target.GetType()
            .GetField(
                fieldName,
                BindingFlags.Instance |
                BindingFlags.Public |
                BindingFlags.NonPublic)
            .SetValue(target, value);
    }

    private static RecycleFixture CreateRecycleFixture(bool shelfOrigin)
    {
        var fixture = new RecycleFixture();

        GameObject canvasObject = new GameObject(
            "Recycle test canvas",
            typeof(RectTransform),
            typeof(Canvas));
        fixture.Objects.Add(canvasObject);
        Canvas canvas = canvasObject.GetComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        ((RectTransform)canvas.transform).sizeDelta =
            new Vector2(1080, 1920);

        GameObject targetObject = new GameObject(
            "Recycle test target",
            typeof(RectTransform),
            typeof(CanvasRenderer),
            typeof(UnityEngine.UI.Image));
        fixture.Objects.Add(targetObject);
        RectTransform targetRect = targetObject.GetComponent<RectTransform>();
        targetRect.SetParent(canvas.transform, false);
        targetRect.anchorMin = new Vector2(0.5f, 0.5f);
        targetRect.anchorMax = new Vector2(0.5f, 0.5f);
        targetRect.sizeDelta = new Vector2(170, 78);
        var excludedObject = new GameObject(
            "Recycle test Home exclusion",
            typeof(RectTransform));
        fixture.Objects.Add(excludedObject);
        fixture.ExcludedArea = excludedObject.GetComponent<RectTransform>();
        fixture.ExcludedArea.SetParent(canvas.transform, false);
        fixture.ExcludedArea.anchorMin = fixture.ExcludedArea.anchorMax =
            new Vector2(0.5f, 0.5f);
        fixture.ExcludedArea.anchoredPosition = new Vector2(250, 0);
        fixture.ExcludedArea.sizeDelta = new Vector2(100, 78);
        fixture.Target = targetObject.AddComponent(
            FindPlayerType("RecycleDropTarget"));
        SetPrivateField(
            fixture.Target,
            "excludedArea",
            fixture.ExcludedArea);
        InvokeLifecycle(fixture.Target, "Awake");

        GameObject gridObject = new GameObject("Recycle test grid");
        gridObject.SetActive(false);
        fixture.Objects.Add(gridObject);
        fixture.Grid = gridObject.AddComponent(FindPlayerType("GridManager"));

        GameObject shelfManagerObject = new GameObject(
            "Recycle test shelf manager");
        shelfManagerObject.SetActive(false);
        fixture.Objects.Add(shelfManagerObject);
        fixture.Shelf = shelfManagerObject.AddComponent(
            FindPlayerType("ShelfManager"));

        GameObject dessertObject = new GameObject("Recycle test dessert");
        fixture.Objects.Add(dessertObject);
        fixture.Dessert = dessertObject.AddComponent(
            FindPlayerType("Dessert"));

        if (shelfOrigin)
        {
            GameObject slotObject = new GameObject("Recycle test shelf slot");
            fixture.Objects.Add(slotObject);
            fixture.Slot = slotObject.AddComponent(
                FindPlayerType("ShelfSlot"));
            fixture.Slot.GetType().GetMethod("SetUnlocked")
                .Invoke(fixture.Slot, new object[] { true });
            Assert.IsTrue((bool)fixture.Slot.GetType()
                .GetMethod("TryStoreDessert")
                .Invoke(fixture.Slot, new[] { fixture.Dessert, (object)false }));
        }
        else
        {
            GameObject cellObject = new GameObject("Recycle test board cell");
            fixture.Objects.Add(cellObject);
            fixture.Cell = cellObject.AddComponent(FindPlayerType("GridCell"));
            fixture.Cell.GetType().GetMethod("SetUnlocked")
                .Invoke(fixture.Cell, new object[] { true });
            fixture.Cell.GetType().GetMethod("PlaceDessert")
                .Invoke(fixture.Cell, new[] { fixture.Dessert, (object)false });
        }

        fixture.DragHandler = dessertObject.AddComponent(
            FindPlayerType("DessertDragHandler"));
        InvokeLifecycle(fixture.DragHandler, "Awake");
        SetPrivateField(fixture.DragHandler, "gridManager", fixture.Grid);
        SetPrivateField(fixture.DragHandler, "shelfManager", fixture.Shelf);
        SetPrivateField(fixture.DragHandler, "recycleDropTarget", fixture.Target);
        SetPrivateField(fixture.DragHandler, "mainCamera", null);
        SetPrivateField(fixture.DragHandler, "originCell", fixture.Cell);
        SetPrivateField(fixture.DragHandler, "originShelfSlot", fixture.Slot);
        return fixture;
    }

    private static RectTransform CreateLayoutRect(
        RectTransform parent,
        string objectName,
        Vector2 anchorMin,
        Vector2 anchorMax,
        Vector2 anchoredPosition,
        Vector2 size,
        Vector2 pivot,
        List<GameObject> createdObjects)
    {
        var gameObject = new GameObject(objectName, typeof(RectTransform));
        createdObjects.Add(gameObject);
        RectTransform rect = gameObject.GetComponent<RectTransform>();
        rect.SetParent(parent, false);
        rect.anchorMin = anchorMin;
        rect.anchorMax = anchorMax;
        rect.anchoredPosition = anchoredPosition;
        rect.sizeDelta = size;
        rect.pivot = pivot;
        return rect;
    }

    private static bool RectanglesOverlap(
        RectTransform first,
        RectTransform second)
    {
        Vector3[] firstCorners = new Vector3[4];
        Vector3[] secondCorners = new Vector3[4];
        first.GetWorldCorners(firstCorners);
        second.GetWorldCorners(secondCorners);
        Rect firstRect = Rect.MinMaxRect(
            firstCorners[0].x,
            firstCorners[0].y,
            firstCorners[2].x,
            firstCorners[2].y);
        Rect secondRect = Rect.MinMaxRect(
            secondCorners[0].x,
            secondCorners[0].y,
            secondCorners[2].x,
            secondCorners[2].y);
        return firstRect.Overlaps(secondRect);
    }

    private static Vector2 GetRecycleBinScreenPoint(RecycleFixture fixture)
    {
        Component target = (Component)fixture.Target;
        Canvas canvas = target.GetComponentInParent<Canvas>();
        Camera eventCamera = canvas.renderMode == RenderMode.ScreenSpaceOverlay
            ? null
            : canvas.worldCamera;
        RectTransform targetRect = (RectTransform)target.transform;
        Vector3 worldCenter = targetRect.TransformPoint(targetRect.rect.center);
        return RectTransformUtility.WorldToScreenPoint(
            eventCamera,
            worldCenter);
    }

    private static void DestroyRecycleFixture(RecycleFixture fixture)
    {
        for (int i = fixture.Objects.Count - 1; i >= 0; i--)
        {
            if (fixture.Objects[i] != null)
                UnityEngine.Object.DestroyImmediate(fixture.Objects[i]);
        }
    }

    private static void SetPrivateStaticProperty(
        Type targetType,
        string propertyName,
        object value)
    {
        targetType.GetProperty(
                propertyName,
                BindingFlags.Static |
                BindingFlags.Public |
                BindingFlags.NonPublic)
            .GetSetMethod(true)
            .Invoke(null, new[] { value });
    }

    private int activeGeneratedEventCount;

    private void RecordGeneratedEvent()
    {
        activeGeneratedEventCount++;
    }

    private Delegate CreateCountingHandler(Type delegateType, string methodName)
    {
        var invoke = delegateType.GetMethod("Invoke");
        var parameters = invoke.GetParameters()
            .Select(parameter =>
                System.Linq.Expressions.Expression.Parameter(
                    parameter.ParameterType,
                    parameter.Name))
            .ToArray();
        var callback = typeof(DataFoundationTests).GetMethod(
            methodName,
            BindingFlags.Instance | BindingFlags.NonPublic);
        var body = System.Linq.Expressions.Expression.Call(
            System.Linq.Expressions.Expression.Constant(this),
            callback);
        return System.Linq.Expressions.Expression
            .Lambda(delegateType, body, parameters)
            .Compile();
    }

    private static object CreateRow(Type type, params (string name, object value)[] values)
    {
        object row = Activator.CreateInstance(type);
        foreach (var (name, value) in values)
            SetField(row, name, value);
        return row;
    }

    private static void AddListItem(
        object target,
        string fieldName,
        Type itemType,
        object item)
    {
        Type listType = typeof(List<>).MakeGenericType(itemType);
        object list = GetField(target, fieldName);
        Assert.IsInstanceOf(listType, list);
        listType.GetMethod("Add").Invoke(list, new[] { item });
    }

    private static void AssertUpgradeTable(
        string assetPath,
        int[] expectedIntValues,
        float[] expectedFloatValues,
        int[] expectedCosts)
    {
        var asset = AssetDatabase.LoadMainAssetAtPath(assetPath);
        Assert.IsNotNull(asset, $"Missing upgrade definition: {assetPath}");
        var levels = new SerializedObject(asset).FindProperty("levels");
        Assert.AreEqual(expectedCosts.Length, levels.arraySize, assetPath);

        for (int i = 0; i < levels.arraySize; i++)
        {
            var level = levels.GetArrayElementAtIndex(i);
            Assert.AreEqual(i + 1, level.FindPropertyRelative("level").intValue,
                $"Level mismatch in {assetPath}");
            Assert.AreEqual(expectedIntValues[i],
                level.FindPropertyRelative("intValue").intValue,
                $"Capacity mismatch in {assetPath} at L{i + 1}");
            Assert.AreEqual(expectedFloatValues[i],
                level.FindPropertyRelative("floatValue").floatValue,
                $"Multiplier mismatch in {assetPath} at L{i + 1}");
            Assert.AreEqual(expectedCosts[i],
                level.FindPropertyRelative("upgradeCost").intValue,
                $"Price mismatch in {assetPath} at L{i + 1}");
        }
    }

    private static object CreateRebirthState(
        int rebirthCount,
        int highestTierCreatedThisRun = 0)
    {
        Type stateType = FindPlayerType("RebirthProgressionState");
        return Activator.CreateInstance(
            stateType,
            new object[] { rebirthCount, highestTierCreatedThisRun });
    }

    private sealed class ProgressionPurchaseTestSetup
    {
        public GameObject ProgressionObject;
        public GameObject EconomyObject;
        public object Progression;
        public object Economy;
    }

    private sealed class RebirthTransactionTestSetup
    {
        public ProgressionPurchaseTestSetup ProgressionSetup;
        public List<GameObject> Objects = new List<GameObject>();
        public object Progression;
        public object Economy;
        public object SaveManager;
        public object SessionManager;
        public object Controller;
        public object Coordinator;
        public object PreviousSession;
        public object FreshSession;
        public object PreviousOrderState;
        public object PreviousPreview;
    }

    private static RebirthTransactionTestSetup
        CreateRebirthTransactionTestSetup()
    {
        var setup = new RebirthTransactionTestSetup
        {
            ProgressionSetup = CreateProgressionPurchaseTestSetup()
        };
        setup.Progression = setup.ProgressionSetup.Progression;
        setup.Economy = setup.ProgressionSetup.Economy;
        SetPrivateStaticProperty(
            setup.Progression.GetType(), "Instance", setup.Progression);
        SetPrivateStaticProperty(
            setup.Economy.GetType(), "Instance", setup.Economy);
        SetPrivateField(setup.Progression, "rebirthProgression",
            CreateRebirthState(0, 7));
        SetPrivateField(setup.Economy, "currentCash", 128);

        object orderDefinition = AssetDatabase.LoadMainAssetAtPath(
            AssetDatabase.GUIDToAssetPath(ExistingOrderDefinitionIds[0]));
        object freshOrderDefinition = AssetDatabase.LoadMainAssetAtPath(
            AssetDatabase.GUIDToAssetPath(ExistingOrderDefinitionIds[1]));
        object[] dessertDefinitions = Enumerable.Range(1, 30)
            .Select(tier => AssetDatabase.LoadMainAssetAtPath(
                $"{DessertFolder}/Dessert_{tier:00}.asset"))
            .ToArray();

        setup.SaveManager = AddInactiveComponent(
            setup, "Rebirth transaction save", "SaveManager");
        setup.SessionManager = AddInactiveComponent(
            setup, "Rebirth transaction session", "MergeSessionManager");
        setup.Coordinator = AddInactiveComponent(
            setup, "Rebirth transaction startup", "GameStartupCoordinator");
        object gridManager = AddInactiveComponent(
            setup, "Rebirth transaction board", "GridManager");
        object shelfManager = AddInactiveComponent(
            setup, "Rebirth transaction shelf", "ShelfManager");
        object orderManager = AddInactiveComponent(
            setup, "Rebirth transaction orders", "OrderManager");
        object dessertSpawner = AddInactiveComponent(
            setup, "Rebirth transaction preview", "DessertSpawner");
        setup.Controller = AddInactiveComponent(
            setup, "Rebirth transaction controller", "MergeSessionController");

        SetPrivateField(orderManager, "progressionManager", setup.Progression);
        orderManager.GetType().GetMethod(
                "InitializeCustomerSlots",
                BindingFlags.Instance | BindingFlags.NonPublic)
            .Invoke(orderManager, null);
        SetPrivateField(dessertSpawner, "progressionManager", setup.Progression);
        SetPrivateField(
            dessertSpawner,
            "dessertDefinitions",
            ConvertArray(dessertDefinitions, "DessertDefinition"));
        SetPrivateField(orderManager, "dessertSpawner", dessertSpawner);
        SetPrivateField(setup.SessionManager, "dessertSpawner", dessertSpawner);
        object preview = dessertDefinitions[0];
        SetPrivateField(dessertSpawner, "nextDessert", preview);
        SetPrivateField(
            shelfManager,
            "slots",
            Array.CreateInstance(FindPlayerType("ShelfSlot"), 0));

        SetPrivateField(setup.Controller, "gridManager", gridManager);
        SetPrivateField(setup.Controller, "shelfManager", shelfManager);
        SetPrivateField(setup.Controller, "orderManager", orderManager);
        SetPrivateField(setup.Controller, "dessertSpawner", dessertSpawner);

        setup.PreviousSession = CreateTestMergeSession(
            orderDefinition, 1, 1);
        setup.FreshSession = CreateTestMergeSession(
            freshOrderDefinition, 4, 2);
        setup.PreviousOrderState = orderManager.GetType().GetMethod(
                "CaptureSessionReplacementState",
                BindingFlags.Instance | BindingFlags.NonPublic)
            .Invoke(orderManager, null);
        setup.PreviousPreview = preview;
        setup.SessionManager.GetType().GetMethod("SaveSession")
            .Invoke(setup.SessionManager, new object[] { setup.PreviousSession });
        setup.SaveManager.GetType().GetMethod(
            "RecordSessionCustomerCapacity",
            new[]
            {
                FindPlayerType("MergeSessionData"),
                typeof(int),
                typeof(string)
            })
            .Invoke(setup.SaveManager,
                new object[] { setup.PreviousSession, 1, null });

        SetPrivateStaticProperty(
            setup.SaveManager.GetType(), "Instance", setup.SaveManager);
        SetPrivateStaticProperty(
            setup.SessionManager.GetType(), "Instance", setup.SessionManager);
        SetPrivateStaticProperty(
            setup.Coordinator.GetType(), "Instance", setup.Coordinator);

        GameObject controllerObject =
            setup.Controller is Component controllerComponent
                ? controllerComponent.gameObject
                : null;
        controllerObject.SetActive(true);
        SetPrivateField(setup.Controller, "restorationInProgress", true);
        SetPrivateField(
            setup.Controller,
            "replacementSessionPreparedForCommit",
            true);
        SetPropertyValue(
            setup.Controller,
            "IsRestorationVerified",
            true);

        SetPrivateField(
            setup.Coordinator,
            "verifiedController",
            setup.Controller);
        SetPropertyValue(
            setup.Coordinator,
            "Status",
            Enum.Parse(
                setup.Coordinator.GetType().GetProperty("Status").PropertyType,
                "NewGame"));
        SetPrivateField(setup.SaveManager, "lifecycleSavingReady", true);
        return setup;
    }

    private static object AddInactiveComponent(
        RebirthTransactionTestSetup setup,
        string objectName,
        string componentType)
    {
        var gameObject = new GameObject(objectName);
        gameObject.SetActive(false);
        setup.Objects.Add(gameObject);
        return gameObject.AddComponent(FindPlayerType(componentType));
    }

    private static Array ConvertArray(object[] values, string elementType)
    {
        Array result = Array.CreateInstance(
            FindPlayerType(elementType),
            values.Length);
        for (int i = 0; i < values.Length; i++)
            result.SetValue(values[i], i);
        return result;
    }

    private static object CreateTestMergeSession(
        object orderDefinition,
        int orderId,
        int nextDessertTier)
    {
        object session = Activator.CreateInstance(
            FindPlayerType("MergeSessionData"));
        SetField(session, "nextOrderId", orderId + 1);
        SetField(session, "nextDessertTier", nextDessertTier);
        object customerOrder = Activator.CreateInstance(
            FindPlayerType("CustomerOrderState"),
            new[] { (object)0, orderId, orderDefinition });
        ((System.Collections.IList)GetField(session, "customerOrders"))
            .Add(customerOrder);
        return session;
    }

    private static MethodInfo GetRebirthSnapshotCommitMethod(object saveManager)
    {
        return saveManager.GetType().GetMethod(
            "TryCommitRebirthSnapshot",
            BindingFlags.Instance | BindingFlags.NonPublic,
            null,
            new[] { typeof(int), typeof(string), typeof(bool).MakeByRefType() },
            null);
    }

    private static void SetPropertyValue(
        object target,
        string propertyName,
        object value)
    {
        target.GetType().GetProperty(
                propertyName,
                BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic)
            .GetSetMethod(true)
            .Invoke(target, new[] { value });
    }

    private static void DestroyRebirthTransactionTestSetup(
        RebirthTransactionTestSetup setup)
    {
        SetPrivateStaticProperty(
            setup.SaveManager.GetType(), "Instance", null);
        SetPrivateStaticProperty(
            setup.SessionManager.GetType(), "Instance", null);
        SetPrivateStaticProperty(
            setup.Coordinator.GetType(), "Instance", null);
        SetPrivateStaticProperty(
            setup.Progression.GetType(), "Instance", null);
        SetPrivateStaticProperty(
            setup.Economy.GetType(), "Instance", null);

        foreach (GameObject gameObject in setup.Objects)
            UnityEngine.Object.DestroyImmediate(gameObject);
        DestroyProgressionPurchaseTestSetup(setup.ProgressionSetup);
    }

    private static ProgressionPurchaseTestSetup CreateProgressionPurchaseTestSetup()
    {
        var setup = new ProgressionPurchaseTestSetup
        {
            ProgressionObject = new GameObject("Progression purchase test"),
            EconomyObject = new GameObject("Economy purchase test")
        };
        setup.ProgressionObject.SetActive(false);
        setup.EconomyObject.SetActive(false);

        Type progressionType = FindPlayerType("PlayerProgressionManager");
        setup.Progression =
            setup.ProgressionObject.AddComponent(progressionType);
        string[] upgradeTypes =
        {
            "Oven", "BoardSpace", "Shelf", "Customer", "MoneyMultiplier", "Luck"
        };
        string[] assetNames =
        {
            "Oven", "BoardSpace", "Shelf", "Customer", "MoneyMultiplier", "Luck"
        };
        string[] fieldNames =
        {
            "ovenUpgrade", "boardSpaceUpgrade", "shelfUpgrade",
            "customerUpgrade", "moneyMultiplierUpgrade", "luckUpgrade"
        };
        for (int i = 0; i < upgradeTypes.Length; i++)
        {
            object definition = AssetDatabase.LoadMainAssetAtPath(
                $"Assets/_Game/Data/Upgrades/Upgrade_{assetNames[i]}.asset");
            Assert.IsNotNull(definition);
            Assert.AreEqual(
                upgradeTypes[i],
                definition.GetType().GetProperty("UpgradeType")
                    .GetValue(definition).ToString());
            SetPrivateField(setup.Progression, fieldNames[i], definition);
        }

        setup.Economy = setup.EconomyObject.AddComponent(
            FindPlayerType("EconomyManager"));
        SetPrivateField(setup.Economy, "currentCash", 100000);
        SetPrivateField(setup.Economy, "initialized", true);
        return setup;
    }

    private static void DestroyProgressionPurchaseTestSetup(
        ProgressionPurchaseTestSetup setup)
    {
        UnityEngine.Object.DestroyImmediate(setup.ProgressionObject);
        UnityEngine.Object.DestroyImmediate(setup.EconomyObject);
    }

    private static object GetRebirthProperty(object state, string propertyName)
    {
        return state.GetType()
            .GetProperty(propertyName, BindingFlags.Instance | BindingFlags.Public)
            .GetValue(state);
    }

    private static bool RegisterCreatedTier(object state, int tier)
    {
        return (bool)state.GetType()
            .GetMethod("RegisterCreatedTier")
            .Invoke(state, new object[] { tier });
    }

    private static bool CanRebirth(object state, int cashHeld)
    {
        return (bool)state.GetType()
            .GetMethod("CanRebirth")
            .Invoke(state, new object[] { cashHeld });
    }
}
