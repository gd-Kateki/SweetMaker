using System;
using System.Collections;
using System.Linq;
using System.Reflection;
using System.Text.RegularExpressions;
using NUnit.Framework;
using UnityEngine;
using UnityEngine.TestTools;

public class AudioManagerTests
{
    private const string ApprovedIds =
        "Dessert_Spawn,Dessert_Pickup,Dessert_Merge,Dessert_MergeSpecial," +
        "Dessert_Drop,UI_Click,Rebirth_Start,Oven_Unlock,Upgrade_Success," +
        "Order_Complete,Action_Invalid,Rebirth_Complete";

    private static Type AudioManagerType =>
        FindPlayerType("AudioManager");

    [Test]
    public void SfxIdContainsExactlyTheApprovedIdentifiers()
    {
        string[] names = Enum.GetNames(FindPlayerType("SfxId"));
        CollectionAssert.AreEqual(ApprovedIds.Split(','), names);
    }

    [Test]
    public void RegistryLookupAndMissingClipAreSafe()
    {
        GameObject managerObject = CreateManager(out Component manager);
        try
        {
            Type idType = FindPlayerType("SfxId");
            Type entryType = FindPlayerType("SfxClipEntry");
            object configuredId = Enum.Parse(idType, "Dessert_Spawn");
            object entry = Activator.CreateInstance(entryType);
            entryType.GetField("id").SetValue(entry, configuredId);

            IList entries = (IList)Activator.CreateInstance(
                typeof(System.Collections.Generic.List<>)
                    .MakeGenericType(entryType));
            entries.Add(entry);
            AudioManagerType.GetField(
                    "clips",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .SetValue(manager, entries);

            Invoke(manager, "RebuildClipLookup");

            object[] lookupArguments = { configuredId, null };
            bool found = (bool)Invoke(
                manager,
                "TryGetClipEntry",
                lookupArguments);
            Assert.IsTrue(found);
            Assert.AreSame(entry, lookupArguments[1]);
            Assert.IsNull(entryType.GetField("clip").GetValue(entry));

            object missingId = Enum.Parse(idType, "Dessert_Pickup");
            object[] missingArguments = { missingId, null };
            Assert.IsFalse((bool)Invoke(
                manager,
                "TryGetClipEntry",
                missingArguments));

            LogAssert.Expect(
                LogType.Warning,
                new Regex(
                    @"AudioManager: No AudioClip is assigned for SFX " +
                    @"'Dessert_Spawn'\."));
            Assert.IsFalse((bool)Invoke(
                manager,
                "TryPlayInternal",
                new[] { configuredId }));
        }
        finally
        {
            DestroyManager(managerObject);
        }
    }

    [Test]
    public void SfxVolumeClampsToNormalizedRange()
    {
        GameObject managerObject = CreateManager(out _);
        try
        {
            MethodInfo setVolume = AudioManagerType.GetMethod(
                "SetSfxVolume",
                BindingFlags.Public | BindingFlags.Static);
            MethodInfo getVolume = AudioManagerType.GetMethod(
                "GetSfxVolume",
                BindingFlags.Public | BindingFlags.Static);

            setVolume.Invoke(null, new object[] { -1f });
            Assert.AreEqual(0f, (float)getVolume.Invoke(null, null));

            setVolume.Invoke(null, new object[] { 1.5f });
            Assert.AreEqual(1f, (float)getVolume.Invoke(null, null));

            setVolume.Invoke(null, new object[] { 0.4f });
            Assert.AreEqual(0.4f, (float)getVolume.Invoke(null, null));

            setVolume.Invoke(null, new object[] { float.NaN });
            Assert.AreEqual(1f, (float)getVolume.Invoke(null, null));
        }
        finally
        {
            DestroyManager(managerObject);
        }
    }

    [Test]
    public void PlaybackIsSafeWhenNoManagerExists()
    {
        PropertyInfo instanceProperty = AudioManagerType.GetProperty(
            "Instance",
            BindingFlags.Public | BindingFlags.Static);
        instanceProperty.GetSetMethod(true).Invoke(null, new object[] { null });

        MethodInfo tryPlay = AudioManagerType.GetMethod(
            "TryPlay",
            BindingFlags.Public | BindingFlags.Static);
        object id = Enum.Parse(
            FindPlayerType("SfxId"),
            "UI_Click");

        Assert.IsFalse((bool)tryPlay.Invoke(null, new[] { id }));
    }

    [Test]
    public void DuplicateManagerDoesNotReplaceThePersistentInstance()
    {
        GameObject primaryObject = CreateManager(out Component primary);
        GameObject duplicateObject = new GameObject("Duplicate AudioManager test");
        duplicateObject.SetActive(false);
        Component duplicate = duplicateObject.AddComponent(AudioManagerType);
        try
        {
            Invoke(duplicate, "Awake");

            Assert.IsTrue(duplicate == null);
            Assert.AreSame(
                primary,
                AudioManagerType.GetProperty(
                        "Instance",
                        BindingFlags.Public | BindingFlags.Static)
                    .GetValue(null));
        }
        finally
        {
            if (duplicateObject != null)
                UnityEngine.Object.DestroyImmediate(duplicateObject);
            DestroyManager(primaryObject);
        }
    }

    [Test]
    public void AudioSourcePoolIsFixedAndReusable()
    {
        GameObject managerObject = CreateManager(out Component manager);
        try
        {
            Invoke(manager, "InitializeAudioSources");
            Assert.AreEqual(6, AudioManagerType.GetProperty("SourcePoolCount")
                .GetValue(manager));
            Assert.AreEqual(6, manager.GetComponents<AudioSource>().Length);

            Invoke(manager, "InitializeAudioSources");
            Assert.AreEqual(6, AudioManagerType.GetProperty("SourcePoolCount")
                .GetValue(manager));
            Assert.AreEqual(6, manager.GetComponents<AudioSource>().Length);
        }
        finally
        {
            DestroyManager(managerObject);
        }
    }

    [Test]
    public void DessertSpawnEventRoutesToAudioManagerAndUnsubscribesOnDestroy()
    {
        GameObject managerObject = CreateManager(out Component manager);
        Type gameplayEventsType = FindPlayerType("GameplayEvents");
        FieldInfo spawnedEvent = gameplayEventsType.GetField(
            "DessertSpawned",
            BindingFlags.Static | BindingFlags.NonPublic);

        try
        {
            Delegate subscribers = (Delegate)spawnedEvent.GetValue(null);
            Assert.AreEqual(
                1,
                subscribers.GetInvocationList()
                    .Count(callback => callback.Target == manager));

            LogAssert.Expect(
                LogType.Warning,
                new Regex(
                    @"AudioManager: No AudioClip is assigned for SFX " +
                    @"'Dessert_Spawn'\."));
            gameplayEventsType.GetMethod("RaiseDessertSpawned")
                .Invoke(null, new object[] { 1 });

            DestroyManager(managerObject);
            managerObject = null;

            subscribers = (Delegate)spawnedEvent.GetValue(null);
            Assert.IsTrue(
                subscribers == null ||
                subscribers.GetInvocationList()
                    .All(callback => callback.Target != manager));
        }
        finally
        {
            if (managerObject != null)
                DestroyManager(managerObject);
        }
    }

    [Test]
    public void SuccessfulMergeCommitClassifiesAgainstPreviousHighestOnce()
    {
        Type gameplayEventsType = FindPlayerType("GameplayEvents");
        EventInfo mergedEvent = gameplayEventsType.GetEvent("DessertMerged");
        EventInfo committedEvent =
            gameplayEventsType.GetEvent("DessertMergeCommitted");
        var legacyTiers = new System.Collections.Generic.List<int>();
        var classifications = new System.Collections.Generic.List<string>();
        Action<int> legacyHandler = tier => legacyTiers.Add(tier);
        Action<int, bool> committedHandler = (tier, special) =>
            classifications.Add($"{tier}:{special}");

        mergedEvent.AddEventHandler(null, legacyHandler);
        committedEvent.AddEventHandler(null, committedHandler);
        try
        {
            MethodInfo raiseCommit = gameplayEventsType.GetMethod(
                "RaiseDessertMergeCommitted",
                BindingFlags.Public | BindingFlags.Static);
            MethodInfo classify = gameplayEventsType.GetMethod(
                "IsNewHighestTier",
                BindingFlags.Static | BindingFlags.NonPublic);

            bool isNewHighest = (bool)classify.Invoke(
                null,
                new object[] { 4, 4 });
            raiseCommit.Invoke(null, new object[] { 4, isNewHighest });
            isNewHighest = (bool)classify.Invoke(
                null,
                new object[] { 6, 5 });
            raiseCommit.Invoke(null, new object[] { 6, isNewHighest });
            isNewHighest = (bool)classify.Invoke(
                null,
                new object[] { 5, 5 });
            raiseCommit.Invoke(null, new object[] { 5, isNewHighest });

            CollectionAssert.AreEqual(
                new[] { 4, 6, 5 },
                legacyTiers);
            CollectionAssert.AreEqual(
                new[] { "4:False", "6:True", "5:False" },
                classifications);
        }
        finally
        {
            mergedEvent.RemoveEventHandler(null, legacyHandler);
            committedEvent.RemoveEventHandler(null, committedHandler);
        }
    }

    [Test]
    public void AudioManagerRoutesEachMergeClassificationToOneSfx()
    {
        GameObject managerObject = CreateManager(out Component manager);
        Type gameplayEventsType = FindPlayerType("GameplayEvents");
        FieldInfo committedEvent = gameplayEventsType.GetField(
            "DessertMergeCommitted",
            BindingFlags.Static | BindingFlags.NonPublic);

        try
        {
            Delegate subscribers = (Delegate)committedEvent.GetValue(null);
            Assert.AreEqual(
                1,
                subscribers.GetInvocationList()
                    .Count(callback => callback.Target == manager));

            LogAssert.Expect(
                LogType.Warning,
                new Regex(
                    @"AudioManager: No AudioClip is assigned for SFX " +
                    @"'Dessert_Merge'\."));
            gameplayEventsType.GetMethod("RaiseDessertMergeCommitted")
                .Invoke(null, new object[] { 5, false });

            LogAssert.Expect(
                LogType.Warning,
                new Regex(
                    @"AudioManager: No AudioClip is assigned for SFX " +
                    @"'Dessert_MergeSpecial'\."));
            gameplayEventsType.GetMethod("RaiseDessertMergeCommitted")
                .Invoke(null, new object[] { 6, true });
        }
        finally
        {
            DestroyManager(managerObject);
        }
    }

    [Test]
    public void MergeAudioCommitIsAfterCreationAndAbsentFromRestorePaths()
    {
        string handlerSource = System.IO.File.ReadAllText(
            "Assets/_Game/Scripts/Gameplay/DessertDragHandler.cs");
        int failedCreationCheck = handlerSource.IndexOf(
            "if (upgradedDessert == null)",
            StringComparison.Ordinal);
        Assert.GreaterOrEqual(failedCreationCheck, 0);

        int failedCreationExit = handlerSource.IndexOf(
            "yield break;",
            failedCreationCheck,
            StringComparison.Ordinal);
        int commitNotification = handlerSource.IndexOf(
            "GameplayEvents.RaiseDessertMergeCommitted(",
            StringComparison.Ordinal);

        Assert.Greater(commitNotification, failedCreationExit);
        Assert.AreEqual(
            1,
            Regex.Matches(
                handlerSource,
                @"GameplayEvents\.RaiseDessertMergeCommitted\(").Count);

        string spawnerSource = System.IO.File.ReadAllText(
            "Assets/_Game/Scripts/Gameplay/DessertSpawner.cs");
        StringAssert.DoesNotContain(
            "RaiseDessertMergeCommitted",
            spawnerSource);
    }

    [Test]
    public void PickupSoundRequiresAValidDragStart()
    {
        GameObject managerObject = CreateManager(out _);
        var cellObject = new GameObject("Pickup test cell");
        var dessertObject = new GameObject("Pickup test dessert");
        try
        {
            Component cell = cellObject.AddComponent(
                FindPlayerType("GridCell"));
            Component dessert = dessertObject.AddComponent(
                FindPlayerType("Dessert"));
            Component handler = dessertObject.AddComponent(
                FindPlayerType("DessertDragHandler"));

            Invoke(handler, "OnPointerDown", new object[] { null });
            Assert.IsFalse((bool)GetPrivateField(handler, "isDragging"));

            Invoke(cell, "PlaceDessert", new object[] { dessert, false });
            LogAssert.Expect(
                LogType.Warning,
                new Regex(
                    @"AudioManager: No AudioClip is assigned for SFX " +
                    @"'Dessert_Pickup'\."));
            Invoke(handler, "OnPointerDown", new object[] { null });
            Assert.IsTrue((bool)GetPrivateField(handler, "isDragging"));

            Invoke(handler, "OnPointerDown", new object[] { null });
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(dessertObject);
            UnityEngine.Object.DestroyImmediate(cellObject);
            DestroyManager(managerObject);
        }
    }

    [Test]
    public void DropSoundPlaysOnlyAfterACompletedBoardMove()
    {
        GameObject managerObject = CreateManager(out Component manager);
        var originObject = new GameObject("Drop origin cell");
        var targetObject = new GameObject("Drop target cell");
        var blockedTargetObject = new GameObject("Blocked drop target cell");
        var dessertObject = new GameObject("Drop test dessert");
        var blockerObject = new GameObject("Drop blocker dessert");
        try
        {
            Component origin = originObject.AddComponent(
                FindPlayerType("GridCell"));
            Component target = targetObject.AddComponent(
                FindPlayerType("GridCell"));
            Component blockedTarget = blockedTargetObject.AddComponent(
                FindPlayerType("GridCell"));
            Component dessert = dessertObject.AddComponent(
                FindPlayerType("Dessert"));
            Component handler = dessertObject.AddComponent(
                FindPlayerType("DessertDragHandler"));

            Invoke(origin, "PlaceDessert", new object[] { dessert, false });
            SetPrivateField(handler, "originCell", origin);

            LogAssert.Expect(
                LogType.Warning,
                new Regex(
                    @"AudioManager: No AudioClip is assigned for SFX " +
                    @"'Dessert_Drop'\."));
            Invoke(handler, "MoveBoardToBoard", new object[] { target });
            Assert.AreSame(
                target,
                GetPrivateField(dessert, "currentCell"));

            Invoke(blockedTarget, "PlaceDessert", new object[]
            {
                blockerObject.AddComponent(FindPlayerType("Dessert")),
                false
            });
            GetPrivateField(manager, "missingClipWarnings")
                .GetType()
                .GetMethod("Clear")
                .Invoke(GetPrivateField(manager, "missingClipWarnings"), null);

            SetPrivateField(handler, "originCell", target);
            Invoke(
                handler,
                "MoveBoardToBoard",
                new object[] { blockedTarget });
            Assert.AreSame(
                target,
                GetPrivateField(dessert, "currentCell"));
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(blockerObject);
            UnityEngine.Object.DestroyImmediate(dessertObject);
            UnityEngine.Object.DestroyImmediate(originObject);
            UnityEngine.Object.DestroyImmediate(targetObject);
            UnityEngine.Object.DestroyImmediate(blockedTargetObject);
            DestroyManager(managerObject);
        }
    }

    [Test]
    public void MainBakeryHasOneRootAudioManagerAndTwelveUnassignedEntries()
    {
        string scene = System.IO.File.ReadAllText(
            "Assets/_Game/Scenes/MainBakery.unity");
        Match managerObject = Regex.Match(
            scene,
            @"(?ms)^--- !u!1 &2200000200\r?\n(.*?)(?=^--- !u!|\z)");
        Match managerTransform = Regex.Match(
            scene,
            @"(?ms)^--- !u!4 &2200000201\r?\n(.*?)(?=^--- !u!|\z)");
        Match managerComponent = Regex.Match(
            scene,
            @"(?ms)^--- !u!114 &2200000202\r?\n(.*?)(?=^--- !u!|\z)");
        Match sceneRoots = Regex.Match(
            scene,
            @"(?ms)^--- !u!1660057539 &9223372036854775807\r?\n(.*?)(?=^--- !u!|\z)");

        Assert.IsTrue(managerObject.Success);
        Assert.IsTrue(managerTransform.Success);
        Assert.IsTrue(managerComponent.Success);
        Assert.IsTrue(sceneRoots.Success);
        StringAssert.Contains("m_Name: AudioManager", managerObject.Value);
        StringAssert.Contains("m_IsActive: 1", managerObject.Value);
        StringAssert.Contains("m_Father: {fileID: 0}", managerTransform.Value);
        StringAssert.Contains(
            "guid: 19f54824a0a24e89b87c5d5f847f1137",
            managerComponent.Value);
        StringAssert.Contains("sfxVolume: 1", managerComponent.Value);
        Assert.AreEqual(
            12,
            Regex.Matches(managerComponent.Value, @"(?m)^  - id: \d+$").Count);
        Assert.AreEqual(
            12,
            Regex.Matches(managerComponent.Value, @"clip: \{fileID: 0\}").Count);
        StringAssert.Contains(
            "- {fileID: 2200000201}",
            sceneRoots.Value);
        Assert.AreEqual(
            1,
            Regex.Matches(scene, @"(?m)^AudioListener:$").Count);
    }

    private static GameObject CreateManager(out Component manager)
    {
        var managerObject = new GameObject("AudioManager test");
        managerObject.SetActive(false);
        manager = managerObject.AddComponent(AudioManagerType);
        Invoke(manager, "Awake");
        return managerObject;
    }

    private static void DestroyManager(GameObject managerObject)
    {
        if (managerObject == null)
            return;

        Component manager = managerObject.GetComponent(AudioManagerType);
        if (manager != null)
            Invoke(manager, "OnDestroy");
        UnityEngine.Object.DestroyImmediate(managerObject);
    }

    private static object Invoke(
        object target,
        string methodName,
        object[] arguments = null)
    {
        MethodInfo method = target.GetType().GetMethod(
            methodName,
            BindingFlags.Instance |
            BindingFlags.Public |
            BindingFlags.NonPublic);
        Assert.IsNotNull(method, $"Missing test target {methodName}.");
        return method.Invoke(target, arguments);
    }

    private static object GetPrivateField(
        object target,
        string fieldName)
    {
        FieldInfo field = target.GetType().GetField(
            fieldName,
            BindingFlags.Instance | BindingFlags.NonPublic);
        Assert.IsNotNull(field, $"Missing test field {fieldName}.");
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
        Assert.IsNotNull(field, $"Missing test field {fieldName}.");
        field.SetValue(target, value);
    }

    private static Type FindPlayerType(string name)
    {
        return AppDomain.CurrentDomain.GetAssemblies()
            .Select(assembly => assembly.GetType(name))
            .FirstOrDefault(type => type != null);
    }
}
