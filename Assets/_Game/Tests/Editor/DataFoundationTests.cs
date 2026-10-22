using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text.RegularExpressions;
using NUnit.Framework;
using UnityEditor;
using UnityEngine;

public class DataFoundationTests
{
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
            StringAssert.StartsWith(
                $"Tier {tier} Placeholder",
                serialized.FindProperty("displayName").stringValue);
            Assert.IsTrue(serialized.FindProperty("sprite").objectReferenceValue == null,
                $"T{tier} should not imply approved final artwork.");
        }
    }

    [Test]
    public void SpawnPoolWeightsAndUnlockLevelsMatchFrozenCandidate()
    {
        Type spawnerType = FindPlayerType("DessertSpawner");
        MethodInfo getWeight = spawnerType.GetMethod(
            "GetSpawnPoolTierWeight",
            BindingFlags.Public | BindingFlags.Static);
        MethodInfo isUnlocked = spawnerType.GetMethod(
            "IsSpawnPoolUnlocked",
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
    }

    [Test]
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
            "Assets/_Game/Data/Upgrades/Upgrade_MoneyMultiplier.asset"
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

        object completed = CreateRebirthState(10);
        Assert.IsFalse((bool)GetRebirthProperty(completed, "HasNextRebirth"));
        Assert.AreEqual(0, GetRebirthProperty(completed, "NextRebirthNumber"));
        Assert.AreEqual(0, GetRebirthProperty(completed, "NextRequiredTier"));
        Assert.AreEqual(0, GetRebirthProperty(completed, "NextRequiredCash"));
        Assert.AreEqual(0, GetRebirthProperty(completed, "NextOvenLevelUnlock"));
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
            "Assets/_Game/Data/Upgrades/Upgrade_MoneyMultiplier.asset"
        };
        string[] upgradeFields =
        {
            "ovenUpgrade", "boardSpaceUpgrade", "shelfUpgrade",
            "customerUpgrade", "moneyMultiplierUpgrade"
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

    private static Type FindPlayerType(string typeName)
    {
        Type type = AppDomain.CurrentDomain.GetAssemblies()
            .Select(assembly => assembly.GetType(typeName, false))
            .FirstOrDefault(candidate => candidate != null);
        Assert.IsNotNull(type, $"Could not find runtime type {typeName}");
        return type;
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
