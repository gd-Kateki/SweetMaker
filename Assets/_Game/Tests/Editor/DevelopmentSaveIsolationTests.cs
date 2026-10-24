using System;
using System.IO;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEngine;

public sealed class DevelopmentSaveIsolationTests
{
    [Test]
    public void EditorV2LegacyAndRecoveryPathsUseDevelopmentDirectory()
    {
        Type saveManagerType = AppDomain.CurrentDomain
            .GetAssemblies()
            .Select(assembly => assembly.GetType("SaveManager"))
            .First(type => type != null);

        GameObject managerObject = new GameObject("Development save path test");
        try
        {
            Component manager = managerObject.AddComponent(saveManagerType);
            string directory = (string)saveManagerType
                .GetProperty("SaveDirectory")
                .GetValue(manager);
            string primary = (string)saveManagerType
                .GetProperty("SaveFilePath")
                .GetValue(manager);
            string legacy = (string)saveManagerType
                .GetProperty("LegacyV1SaveFilePath")
                .GetValue(manager);
            string expectedDirectory = Path.GetFullPath(Path.Combine(
                Application.persistentDataPath,
                "SweetMaker-Development"));

            Assert.AreEqual(
                expectedDirectory,
                Path.GetFullPath(directory));
            Assert.AreEqual(
                Path.Combine(directory, "player_save_v2.json"),
                primary);
            Assert.AreEqual(
                Path.Combine(directory, "player_save.json"),
                legacy);
            Assert.AreNotEqual(
                Path.Combine(
                    Application.persistentDataPath,
                    "player_save_v2.json"),
                primary);

            foreach (string suffix in new[]
                     {
                         ".bak",
                         ".tmp",
                         ".bak.tmp",
                         ".recover.tmp",
                         ".corrupt.test"
                     })
            {
                string derivedPath = primary + suffix;
                StringAssert.StartsWith(
                    expectedDirectory + Path.DirectorySeparatorChar,
                    Path.GetFullPath(derivedPath));
            }
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(managerObject);
        }
    }

    [Test]
    public void DeveloperCommandsAreCompileGuardedAndHaveNoSceneEntryPoint()
    {
        string commandsPath = Path.Combine(
            Application.dataPath,
            "_Game",
            "Scripts",
            "Development",
            "DeveloperCheatCommands.cs");
        string source = File.ReadAllText(commandsPath);

        StringAssert.StartsWith(
            "#if UNITY_EDITOR || (UNITY_ANDROID && DEVELOPMENT_BUILD)",
            source.TrimStart());
        Assert.IsFalse(source.Contains("MenuItem("));
        Assert.IsFalse(source.Contains("CampaignCompleted"));
        Assert.IsFalse(source.Contains("RaiseCampaignCompleted"));
        Assert.IsFalse(source.Contains(".TryRebirth("));
        Assert.IsFalse(source.Contains(".TrySetLevel("));
        StringAssert.Contains(
            ".RestoreRebirthProgression(",
            source);
    }

    [Test]
    public void DeveloperCheatPanelIsGuardedAndUsesExistingGameplayUi()
    {
        string panelPath = Path.Combine(
            Application.dataPath,
            "_Game",
            "Scripts",
            "Development",
            "DeveloperCheatPanel.cs");
        string panelSource = File.ReadAllText(panelPath);
        string gameScenePath = Path.Combine(
            Application.dataPath,
            "_Game",
            "Scenes",
            "Game.unity");
        string gameSceneSource = File.ReadAllText(gameScenePath);

        StringAssert.StartsWith(
            "#if UNITY_EDITOR || (UNITY_ANDROID && DEVELOPMENT_BUILD)",
            panelSource.TrimStart());
        StringAssert.Contains("GameplayCanvas", panelSource);
        StringAssert.Contains("DeveloperCheatCommands.AddCash(", panelSource);
        StringAssert.Contains("DeveloperCheatCommands.SetRebirth(", panelSource);
        StringAssert.Contains("DeveloperCheatCommands.SpawnDessert(", panelSource);
        StringAssert.Contains(
            "DeveloperCheatCommands.ClearBoardDesserts",
            panelSource);
        Assert.IsFalse(panelSource.Contains("new EventSystem"));
        Assert.IsFalse(panelSource.Contains("SaveCurrentGame("));
        Assert.IsFalse(panelSource.Contains("CampaignCompleted"));
        Assert.IsFalse(panelSource.Contains("[SerializeField]"));
        Assert.IsFalse(gameSceneSource.Contains("DeveloperCheatPanel"));
    }

    [Test]
    public void DebugRebirthRangeMapsOnlyToDerivedOvenLevels()
    {
        Type stateType = AppDomain.CurrentDomain
            .GetAssemblies()
            .Select(assembly => assembly.GetType("RebirthProgressionState"))
            .First(type => type != null);
        MethodInfo restore = stateType.GetMethod("Restore");
        MethodInfo getOvenLevel =
            stateType.GetMethod("GetOvenLevelForRebirthCount");
        int[] expectedOvenLevels =
        {
            1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6
        };

        for (int rebirth = 0; rebirth <= 10; rebirth++)
        {
            object state = Activator.CreateInstance(stateType);
            Assert.IsTrue(
                (bool)restore.Invoke(
                    state,
                    new object[] { rebirth, 0, false }),
                "R" + rebirth + " must restore as a valid incomplete state.");
            Assert.AreEqual(
                expectedOvenLevels[rebirth],
                getOvenLevel.Invoke(null, new object[] { rebirth }));
            Assert.IsFalse(
                (bool)stateType.GetProperty("CampaignComplete").GetValue(state));
        }
    }
}
