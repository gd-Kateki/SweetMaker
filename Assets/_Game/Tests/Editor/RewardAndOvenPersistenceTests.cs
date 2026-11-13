using System;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;

public sealed class RewardAndOvenPersistenceTests
{
    private const BindingFlags Private = BindingFlags.Instance | BindingFlags.NonPublic;
    private static Type Find(string name) => AppDomain.CurrentDomain.GetAssemblies().Select(a => a.GetType(name)).First(t => t != null);
    private static object Get(object owner, string name) => owner.GetType().GetField(name, Private).GetValue(owner);
    private static void SetInstance(Type type, object value) => type.GetProperty("Instance").GetSetMethod(true).Invoke(null, new[] { value });

    [Test]
    public void ClaimedRewardHidesButtonAndRebindingAnUnclaimedRewardRestoresIt()
    {
        var root = UnityEngine.Object.Instantiate(AssetDatabase.LoadAssetAtPath<GameObject>("Assets/_Game/Prefabs/UI/DessertCollectionRewardRow.prefab"));
        try
        {
            var modelType = Find("DessertCollectionState");
            var model = Activator.CreateInstance(modelType);
            for (int tier = 1; tier <= 6; tier++) modelType.GetMethod("RecordDiscovery").Invoke(model, new object[] { tier });
            var type = Find("DessertCollectionRewardRowUI");
            var row = root.GetComponent(type);
            var statusRect = (RectTransform)((Component)Get(row, "statusText")).transform;
            Vector2 originalMin = statusRect.anchorMin, originalMax = statusRect.anchorMax;
            Action<int> onClaim = id => { };
            type.GetMethod("Bind").Invoke(row, new object[] { 1, model, onClaim });
            var button = (Button)Get(row, "claimButton");
            Assert.IsTrue(button.gameObject.activeSelf);
            Assert.IsTrue(button.interactable);
            Assert.IsTrue((bool)modelType.GetMethod("TryMarkMilestoneClaimedAfterPayment", Private).Invoke(model, new object[] { 1 }));
            type.GetMethod("Refresh").Invoke(row, new[] { model });
            Assert.IsFalse(button.gameObject.activeSelf);
            var text = Get(row, "statusText");
            Assert.AreEqual("CLAIMED", text.GetType().GetProperty("text").GetValue(text));
            var claimRect = (RectTransform)button.transform;
            Assert.AreEqual(claimRect.anchorMin, statusRect.anchorMin);
            Assert.AreEqual(claimRect.anchorMax, statusRect.anchorMax);
            Assert.AreEqual(claimRect.anchoredPosition, statusRect.anchoredPosition);
            Assert.IsTrue(((Component)text).gameObject.activeInHierarchy);
            type.GetMethod("Bind").Invoke(row, new object[] { 2, model, onClaim });
            Assert.IsTrue(button.gameObject.activeSelf);
            Assert.AreEqual(originalMin, statusRect.anchorMin);
            Assert.AreEqual(originalMax, statusRect.anchorMax);
            Assert.IsFalse(button.interactable, "An unearned reward stays locked.");
        }
        finally { UnityEngine.Object.DestroyImmediate(root); }
    }

    [TestCase(2, "P2")]
    [TestCase(4, "P3")]
    [TestCase(6, "P4")]
    public void NewGameplaySpawnerCannotOverwriteRememberedOvenTier(int prestige, string pool)
    {
        var saveType = Find("SaveManager"); var progressionType = Find("PlayerProgressionManager");
        var oldSave = saveType.GetProperty("Instance").GetValue(null);
        var oldProgression = progressionType.GetProperty("Instance").GetValue(null);
        var root = new GameObject("Oven tier return-to-game test"); root.SetActive(false);
        try
        {
            var save = root.AddComponent(saveType); SetInstance(saveType, save);
            var progression = root.AddComponent(progressionType); SetInstance(progressionType, progression);
            progressionType.GetField("ovenUpgrade", Private).SetValue(progression,
                AssetDatabase.LoadMainAssetAtPath("Assets/_Game/Data/Upgrades/Upgrade_Oven.asset"));
            Assert.IsTrue((bool)progressionType.GetMethod("RestoreRebirthProgression").Invoke(progression, new object[] { prestige, 0, false }));
            saveType.GetMethod("RecordSelectedSpawnPool").Invoke(save, new object[] { pool });
            var spawnerType = Find("DessertSpawner");
            var spawner = root.AddComponent(spawnerType);
            spawnerType.GetMethod("Start", Private).Invoke(spawner, null);
            Assert.AreEqual(pool, Get(save, "sessionSelectedSpawnPoolId"), "Startup must not save its temporary P1 default.");
            Assert.IsTrue((bool)saveType.GetMethod("RestoreSelectedSpawnPool").Invoke(save, new object[] { spawner }));
            Assert.AreEqual(pool, spawnerType.GetProperty("SelectedSpawnPoolId").GetValue(spawner));
            Assert.IsTrue((bool)spawnerType.GetMethod("TrySelectSpawnPool").Invoke(spawner, new object[] { "P1" }));
            Assert.AreEqual("P1", Get(save, "sessionSelectedSpawnPoolId"), "A deliberate new choice must still be remembered.");
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(root);
            SetInstance(saveType, oldSave); SetInstance(progressionType, oldProgression);
        }
    }
}
