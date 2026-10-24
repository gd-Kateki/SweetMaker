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
    public void UiClickSfxRequiresAnActiveInteractableButton()
    {
        GameObject managerObject = CreateManager(out Component manager);
        var buttonObject = new GameObject(
            "UI click test button",
            typeof(RectTransform),
            typeof(UnityEngine.UI.Image),
            typeof(UnityEngine.UI.Button));
        UnityEngine.UI.Button button =
            buttonObject.GetComponent<UnityEngine.UI.Button>();
        Type uiClickSfxType = FindPlayerType("UiClickSfx");
        MethodInfo tryPlay = uiClickSfxType.GetMethod(
            "TryPlay",
            BindingFlags.Static | BindingFlags.NonPublic);

        try
        {
            button.enabled = false;
            Assert.IsFalse((bool)tryPlay.Invoke(null, new object[] { button }));
            Assert.IsFalse(WasMissingClipWarned(manager, "UI_Click"));

            button.enabled = true;
            button.interactable = false;
            Assert.IsFalse((bool)tryPlay.Invoke(null, new object[] { button }));
            Assert.IsFalse(WasMissingClipWarned(manager, "UI_Click"));

            button.interactable = true;
            LogAssert.Expect(
                LogType.Warning,
                new Regex(
                    @"AudioManager: No AudioClip is assigned for SFX " +
                    @"'UI_Click'\."));
            Assert.IsFalse((bool)tryPlay.Invoke(null, new object[] { button }));
            Assert.IsTrue(WasMissingClipWarned(manager, "UI_Click"));
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(buttonObject);
            DestroyManager(managerObject);
        }
    }

    [Test]
    public void UiClickRoutingIsSingleAndExcludesActionSpecificControls()
    {
        AssertUiClickRequestCount(
            "Assets/_Game/Scripts/UI/PlayButtonUI.cs",
            "private void HandlePlayClicked()",
            1);
        AssertUiClickRequestCount(
            "Assets/_Game/Scripts/UI/HomeButtonUI.cs",
            "private void HandleHomeClicked()",
            1);
        AssertUiClickRequestCount(
            "Assets/_Game/Scripts/UI/UpgradeScreenUI.cs",
            "private void HandleOpenClicked()",
            1);
        AssertUiClickRequestCount(
            "Assets/_Game/Scripts/UI/UpgradeScreenUI.cs",
            "private void HandleCloseClicked()",
            1);
        AssertUiClickRequestCount(
            "Assets/_Game/Scripts/UI/CustomerButtonUI.cs",
            "private void HandleClicked()",
            1);
        AssertUiClickRequestCount(
            "Assets/_Game/Scripts/UI/OrderDetailsUI.cs",
            "private void HandleCloseClicked()",
            1);
        AssertUiClickRequestCount(
            "Assets/_Game/Scripts/UI/RebirthUI.cs",
            "private void HandleOpenClicked()",
            1);
        AssertUiClickRequestCount(
            "Assets/_Game/Scripts/UI/RebirthUI.cs",
            "private void HandleCloseClicked()",
            1);
        AssertUiClickRequestCount(
            "Assets/_Game/Scripts/UI/SpawnPoolSelectorUI.cs",
            "private void SelectPreviousPool()",
            1);
        AssertUiClickRequestCount(
            "Assets/_Game/Scripts/UI/SpawnPoolSelectorUI.cs",
            "private void SelectNextPool()",
            1);

        AssertUiClickRequestCount(
            "Assets/_Game/Scripts/UI/UpgradeCardUI.cs",
            "private void HandlePurchaseClicked()",
            0);
        AssertUiClickRequestCount(
            "Assets/_Game/Scripts/UI/OrderDetailsUI.cs",
            "private void HandleConfirmClicked()",
            0);
        AssertUiClickRequestCount(
            "Assets/_Game/Scripts/UI/RebirthUI.cs",
            "private void HandleRebirthClicked()",
            0);
        AssertUiClickRequestCount(
            "Assets/_Game/Scripts/UI/OrderUI.cs",
            "private void HandleFulfillClicked()",
            0);

        string playHandler = GetSourceMethod(
            "Assets/_Game/Scripts/UI/PlayButtonUI.cs",
            "private void HandlePlayClicked()");
        Assert.Less(
            playHandler.IndexOf("UiClickSfx.TryPlay", StringComparison.Ordinal),
            playHandler.IndexOf("GoToMergeGameplay", StringComparison.Ordinal));
        string homeHandler = GetSourceMethod(
            "Assets/_Game/Scripts/UI/HomeButtonUI.cs",
            "private void HandleHomeClicked()");
        Assert.Less(
            homeHandler.IndexOf("UiClickSfx.TryPlay", StringComparison.Ordinal),
            homeHandler.IndexOf("GoToMainBakery", StringComparison.Ordinal));
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
    public void OrderCompletionRoutesOnceAndUnsubscribesOnDestroy()
    {
        GameObject audioManagerObject = CreateManager(out Component audioManager);
        var orderManagerObject = new GameObject("Order manager event test");
        orderManagerObject.SetActive(false);
        Component orderManager = orderManagerObject.AddComponent(
            FindPlayerType("OrderManager"));

        try
        {
            Invoke(audioManager, "SubscribeToOrderManager", new object[]
            {
                orderManager
            });
            Invoke(audioManager, "SubscribeToOrderManager", new object[]
            {
                orderManager
            });

            object subscribers = GetPrivateField(orderManager, "OrderCompleted");
            Assert.AreEqual(
                1,
                ((Delegate)subscribers).GetInvocationList()
                    .Count(callback => callback.Target == audioManager));

            LogAssert.Expect(
                LogType.Warning,
                new Regex(
                    @"AudioManager: No AudioClip is assigned for SFX " +
                    @"'Order_Complete'\."));
            ((Delegate)subscribers).DynamicInvoke(new object[] { null });

            DestroyManager(audioManagerObject);
            audioManagerObject = null;

            subscribers = GetPrivateField(orderManager, "OrderCompleted");
            Assert.IsTrue(
                subscribers == null ||
                ((Delegate)subscribers).GetInvocationList()
                    .All(callback => callback.Target != audioManager));
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(orderManagerObject);
            if (audioManagerObject != null)
                DestroyManager(audioManagerObject);
        }
    }

    [Test]
    public void FailedOrderFulfillmentDoesNotRequestCompletionSfx()
    {
        GameObject audioManagerObject = CreateManager(out Component audioManager);
        var orderManagerObject = new GameObject("Failed order fulfillment test");
        orderManagerObject.SetActive(false);
        Component orderManager = orderManagerObject.AddComponent(
            FindPlayerType("OrderManager"));

        try
        {
            Invoke(audioManager, "SubscribeToOrderManager", new object[]
            {
                orderManager
            });
            LogAssert.Expect(
                LogType.Error,
                new Regex(@"OrderManager: GridManager is missing\."));

            Assert.IsFalse((bool)Invoke(
                orderManager,
                "TryFulfillOrderAtIndex",
                new object[] { 0 }));
            Assert.IsFalse(
                WasMissingClipWarned(audioManager, "Order_Complete"));
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(orderManagerObject);
            DestroyManager(audioManagerObject);
        }
    }

    [Test]
    public void UpgradePurchaseRoutesOnceAndUnsubscribesOnDestroy()
    {
        GameObject audioManagerObject = CreateManager(out Component audioManager);
        var upgradeManagerObject = new GameObject("Upgrade purchase event test");
        upgradeManagerObject.SetActive(false);
        Component upgradeManager = upgradeManagerObject.AddComponent(
            FindPlayerType("UpgradePurchaseManager"));

        try
        {
            Invoke(
                audioManager,
                "SubscribeToUpgradePurchaseManager",
                new object[] { upgradeManager });
            Invoke(
                audioManager,
                "SubscribeToUpgradePurchaseManager",
                new object[] { upgradeManager });

            object subscribers = GetPrivateField(
                upgradeManager,
                "UpgradePurchased");
            Assert.AreEqual(
                1,
                ((Delegate)subscribers).GetInvocationList()
                    .Count(callback => callback.Target == audioManager));

            object upgradeType = Enum.Parse(
                FindPlayerType("UpgradeType"),
                "BoardSpace");
            LogAssert.Expect(
                LogType.Warning,
                new Regex(
                    @"AudioManager: No AudioClip is assigned for SFX " +
                    @"'Upgrade_Success'\."));
            ((Delegate)subscribers).DynamicInvoke(
                new[] { upgradeType, (object)2, 100 });

            DestroyManager(audioManagerObject);
            audioManagerObject = null;

            subscribers = GetPrivateField(
                upgradeManager,
                "UpgradePurchased");
            Assert.IsTrue(
                subscribers == null ||
                ((Delegate)subscribers).GetInvocationList()
                    .All(callback => callback.Target != audioManager));
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(upgradeManagerObject);
            if (audioManagerObject != null)
                DestroyManager(audioManagerObject);
        }
    }

    [Test]
    public void RejectedUpgradePurchaseDoesNotRequestSuccessSfx()
    {
        GameObject audioManagerObject = CreateManager(out Component audioManager);
        var upgradeManagerObject = new GameObject("Rejected upgrade purchase test");
        upgradeManagerObject.SetActive(false);
        Component upgradeManager = upgradeManagerObject.AddComponent(
            FindPlayerType("UpgradePurchaseManager"));

        try
        {
            Invoke(
                audioManager,
                "SubscribeToUpgradePurchaseManager",
                new object[] { upgradeManager });

            bool previousIgnoreFailingMessages =
                LogAssert.ignoreFailingMessages;
            LogAssert.ignoreFailingMessages = true;
            try
            {
                object upgradeType = Enum.ToObject(
                    FindPlayerType("UpgradeType"),
                    -1);
                Assert.IsFalse((bool)Invoke(
                    upgradeManager,
                    "TryPurchaseUpgrade",
                    new[] { upgradeType }));
            }
            finally
            {
                LogAssert.ignoreFailingMessages =
                    previousIgnoreFailingMessages;
            }

            Assert.IsFalse(
                WasMissingClipWarned(audioManager, "Upgrade_Success"));
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(upgradeManagerObject);
            DestroyManager(audioManagerObject);
        }
    }

    [Test]
    public void RebirthSfxRequestsStayInsideSuccessfulTransactionBoundaries()
    {
        string progressionSource = System.IO.File.ReadAllText(
            "Assets/_Game/Scripts/Gameplay/Progression/PlayerProgressionManager.cs");
        int requestHelperStart = progressionSource.IndexOf(
            "private static void RequestSuccessfulRebirthAudio(",
            StringComparison.Ordinal);
        int requestHelperEnd = progressionSource.IndexOf(
            "private static",
            requestHelperStart + 1,
            StringComparison.Ordinal);
        int initialRejection = progressionSource.IndexOf(
            "!RebirthProgression.CanRebirth(economy.CurrentCash)",
            StringComparison.Ordinal);
        int snapshotRejection = progressionSource.IndexOf(
            "if (!saved && !committed)",
            StringComparison.Ordinal);
        Match successfulResultRequest = Regex.Match(
            progressionSource,
            @"if \(rebirthCompleted\)\s+RequestSuccessfulRebirthAudio\(" +
            @"previousOvenLevel,\s*newOvenLevel\);");
        int committedRecoveryRequest = progressionSource.IndexOf(
            "if (snapshotCommitted)",
            StringComparison.Ordinal);

        Assert.GreaterOrEqual(requestHelperStart, 0);
        Assert.Greater(requestHelperEnd, requestHelperStart);
        string requestHelper = progressionSource.Substring(
            requestHelperStart,
            requestHelperEnd - requestHelperStart);
        StringAssert.Contains(
            "AudioManager.Play(SfxId.Rebirth_Start)",
            requestHelper);
        StringAssert.Contains(
            "AudioManager.Play(SfxId.Rebirth_Complete)",
            requestHelper);
        Assert.Less(
            requestHelper.IndexOf(
                "AudioManager.Play(SfxId.Rebirth_Start)",
                StringComparison.Ordinal),
            requestHelper.IndexOf(
                "AudioManager.Play(SfxId.Rebirth_Complete)",
                StringComparison.Ordinal));
        Assert.AreEqual(
            1,
            Regex.Matches(
                requestHelper,
                @"AudioManager\.Play\(SfxId\.Rebirth_Start\)").Count);
        Assert.AreEqual(
            1,
            Regex.Matches(
                requestHelper,
                @"AudioManager\.Play\(SfxId\.Rebirth_Complete\)").Count);
        Assert.AreEqual(
            1,
            Regex.Matches(
                requestHelper,
                @"AudioManager\.Play\(SfxId\.Oven_Unlock\)").Count);
        StringAssert.Contains(
            "if (newOvenLevel > previousOvenLevel)",
            requestHelper);
        Assert.IsTrue(successfulResultRequest.Success);
        Assert.Greater(successfulResultRequest.Index, initialRejection);
        Assert.Greater(successfulResultRequest.Index, snapshotRejection);
        Assert.Greater(successfulResultRequest.Index, committedRecoveryRequest);
        StringAssert.Contains(
            "int previousOvenLevel = ovenLevel;",
            progressionSource);
        StringAssert.Contains(
            "int newOvenLevel = GetOvenLevelForRebirthCount(nextRebirthCount);",
            progressionSource);
        Assert.Greater(committedRecoveryRequest, initialRejection);
        Assert.AreEqual(
            1,
            Regex.Matches(
                progressionSource,
                @"RequestSuccessfulRebirthAudio\(previousOvenLevel,\s*" +
                @"newOvenLevel\);").Count,
            "Successful completion and committed recovery share one guarded request.");
        Assert.AreEqual(
            1,
            Regex.Matches(
                progressionSource,
                @"AudioManager\.Play\(SfxId\.Oven_Unlock\)").Count,
            "Oven unlock audio is requested only by the successful Rebirth helper.");

        string rebirthUiSource = System.IO.File.ReadAllText(
            "Assets/_Game/Scripts/UI/RebirthUI.cs");
        int clickHandlerStart = rebirthUiSource.IndexOf(
            "private void HandleRebirthClicked()",
            StringComparison.Ordinal);
        int refreshStart = rebirthUiSource.IndexOf(
            "public void Refresh()",
            clickHandlerStart,
            StringComparison.Ordinal);
        Assert.GreaterOrEqual(clickHandlerStart, 0);
        string clickHandler = rebirthUiSource.Substring(
            clickHandlerStart,
            refreshStart - clickHandlerStart);
        StringAssert.Contains("progressionManager.TryRebirth()", clickHandler);
        StringAssert.DoesNotContain("AudioManager.Play", clickHandler);

        int restoreStart = progressionSource.IndexOf(
            "public bool RestoreRebirthProgression(",
            StringComparison.Ordinal);
        int restoreEnd = progressionSource.IndexOf(
            "internal static int GetOvenLevelForRebirthCount",
            restoreStart,
            StringComparison.Ordinal);
        string restoration = progressionSource.Substring(
            restoreStart,
            restoreEnd - restoreStart);
        StringAssert.DoesNotContain("AudioManager.Play", restoration);
    }

    [Test]
    public void SuccessfulRebirthRequestsStartAndCompleteAsDistinctSfx()
    {
        GameObject managerObject = CreateManager(out Component manager);
        MethodInfo requestAudio = FindPlayerType("PlayerProgressionManager")
            .GetMethod(
                "RequestSuccessfulRebirthAudio",
                BindingFlags.Static | BindingFlags.NonPublic);

        try
        {
            LogAssert.Expect(
                LogType.Warning,
                new Regex(
                    @"AudioManager: No AudioClip is assigned for SFX " +
                    @"'Rebirth_Start'\."));
            LogAssert.Expect(
                LogType.Warning,
                new Regex(
                    @"AudioManager: No AudioClip is assigned for SFX " +
                    @"'Rebirth_Complete'\."));
            requestAudio.Invoke(null, new object[] { 1, 1 });

            Assert.IsTrue(WasMissingClipWarned(manager, "Rebirth_Start"));
            Assert.IsTrue(WasMissingClipWarned(manager, "Rebirth_Complete"));
            Assert.IsFalse(WasMissingClipWarned(manager, "Oven_Unlock"));
        }
        finally
        {
            DestroyManager(managerObject);
        }
    }

    [TestCase(1, 1, false)]
    [TestCase(1, 2, true)]
    [TestCase(2, 2, false)]
    [TestCase(2, 3, true)]
    [TestCase(3, 3, false)]
    [TestCase(3, 4, true)]
    [TestCase(4, 4, false)]
    [TestCase(4, 5, true)]
    [TestCase(5, 5, false)]
    [TestCase(5, 6, true)]
    [TestCase(6, 5, false)]
    public void RebirthOvenUnlockSfxRequiresAnActualLevelIncrease(
        int previousOvenLevel,
        int newOvenLevel,
        bool expectedUnlock)
    {
        GameObject managerObject = CreateManager(out Component manager);
        MethodInfo requestAudio = FindPlayerType("PlayerProgressionManager")
            .GetMethod(
                "RequestSuccessfulRebirthAudio",
                BindingFlags.Static | BindingFlags.NonPublic);

        try
        {
            LogAssert.Expect(
                LogType.Warning,
                new Regex(
                    @"AudioManager: No AudioClip is assigned for SFX " +
                    @"'Rebirth_Start'\."));
            if (expectedUnlock)
            {
                LogAssert.Expect(
                    LogType.Warning,
                    new Regex(
                        @"AudioManager: No AudioClip is assigned for SFX " +
                        @"'Oven_Unlock'\."));
            }
            LogAssert.Expect(
                LogType.Warning,
                new Regex(
                    @"AudioManager: No AudioClip is assigned for SFX " +
                    @"'Rebirth_Complete'\."));

            requestAudio.Invoke(
                null,
                new object[] { previousOvenLevel, newOvenLevel });

            Assert.AreEqual(
                expectedUnlock,
                WasMissingClipWarned(manager, "Oven_Unlock"));
            Assert.IsTrue(WasMissingClipWarned(manager, "Rebirth_Start"));
            Assert.IsTrue(WasMissingClipWarned(manager, "Rebirth_Complete"));
        }
        finally
        {
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
    public void FullBoardOvenTapRequestsInvalidOnce()
    {
        GameObject audioManagerObject = CreateManager(out _);
        var gridObject = new GameObject("Full board test grid");
        gridObject.SetActive(false);
        var spawnerObject = new GameObject("Full board test spawner");
        spawnerObject.SetActive(false);
        var occupiedCellObject = new GameObject("Occupied board cell");
        var occupiedDessertObject = new GameObject("Occupied dessert");
        var prefabObject = new GameObject("Dessert prefab");
        prefabObject.SetActive(false);
        var containerObject = new GameObject("Dessert container");
        var definition = ScriptableObject.CreateInstance(
            FindPlayerType("DessertDefinition"));
        var ovenManagerObject = new GameObject("Test oven manager");
        ovenManagerObject.SetActive(false);
        var ovenObject = new GameObject("Test oven");
        PropertyInfo gameManagerInstance = FindPlayerType("GameManager")
            .GetProperty(
                "Instance",
                BindingFlags.Public | BindingFlags.Static);
        object previousGameManager =
            gameManagerInstance.GetValue(null);

        try
        {
            gameManagerInstance.GetSetMethod(true)
                .Invoke(null, new object[] { null });

            Component gridManager = gridObject.AddComponent(
                FindPlayerType("GridManager"));
            Component cell = occupiedCellObject.AddComponent(
                FindPlayerType("GridCell"));
            Component occupiedDessert = occupiedDessertObject.AddComponent(
                FindPlayerType("Dessert"));
            Invoke(cell, "PlaceDessert", new object[] { occupiedDessert, false });
            ((IList)GetPrivateField(gridManager, "cells")).Add(cell);

            Component spawner = spawnerObject.AddComponent(
                FindPlayerType("DessertSpawner"));
            SetPrivateField(spawner, "gridManager", gridManager);
            SetPrivateField(
                spawner,
                "dessertPrefab",
                prefabObject.AddComponent(FindPlayerType("Dessert")));
            SetPrivateField(spawner, "dessertContainer", containerObject.transform);
            SetPrivateField(
                spawner,
                "dessertDefinitions",
                Array.CreateInstance(FindPlayerType("DessertDefinition"), 1));

            Component ovenManager = ovenManagerObject.AddComponent(
                FindPlayerType("OvenManager"));
            SetPrivateField(ovenManager, "dessertSpawner", spawner);

            Component ovenController = ovenObject.AddComponent(
                FindPlayerType("OvenController"));
            SetPrivateField(ovenController, "ovenManager", ovenManager);
            SetPrivateField(ovenController, "ovenAnimator", null);
            var pointerEvent = new UnityEngine.EventSystems.PointerEventData(null)
            {
                button = UnityEngine.EventSystems.PointerEventData.InputButton.Left
            };

            LogAssert.Expect(LogType.Log, "The grid is full.");
            LogAssert.Expect(LogType.Log, "OVEN | Spawn request failed.");
            LogAssert.Expect(
                LogType.Warning,
                new Regex(
                    @"AudioManager: No AudioClip is assigned for SFX " +
                    @"'Action_Invalid'\."));
            Invoke(ovenController, "OnPointerDown", new object[] { pointerEvent });

            Assert.IsTrue((bool)ovenManager.GetType()
                .GetProperty("LastRequestFailedForNoBoardSpace")
                .GetValue(ovenManager));

            object warningSet = GetPrivateField(
                GetManagerComponent(audioManagerObject),
                "missingClipWarnings");
            warningSet.GetType().GetMethod("Clear").Invoke(warningSet, null);
            LogAssert.Expect(LogType.Log, "The grid is full.");
            object[] spawnArguments = { false };
            Assert.IsFalse((bool)Invoke(
                spawner,
                "TrySpawnRandomDessert",
                spawnArguments));
            Assert.IsTrue((bool)spawnArguments[0]);
            Assert.IsFalse(WasMissingClipWarned(
                GetManagerComponent(audioManagerObject),
                "Action_Invalid"));
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(ovenObject);
            UnityEngine.Object.DestroyImmediate(ovenManagerObject);
            UnityEngine.Object.DestroyImmediate(containerObject);
            UnityEngine.Object.DestroyImmediate(prefabObject);
            UnityEngine.Object.DestroyImmediate(occupiedDessertObject);
            UnityEngine.Object.DestroyImmediate(occupiedCellObject);
            UnityEngine.Object.DestroyImmediate(spawnerObject);
            UnityEngine.Object.DestroyImmediate(gridObject);
            UnityEngine.Object.DestroyImmediate(definition);
            DestroyManager(audioManagerObject);
            gameManagerInstance.GetSetMethod(true)
                .Invoke(null, new[] { previousGameManager });
        }
    }

    [Test]
    public void DifferentTierOccupiedDropRequestsInvalidOnce()
    {
        GameObject audioManagerObject = CreateManager(out _);
        var originObject = new GameObject("Invalid drop origin");
        var targetObject = new GameObject("Invalid drop target");
        var sourceObject = new GameObject("Invalid drop source dessert");
        var targetDessertObject = new GameObject("Incompatible target dessert");
        var handlerObject = new GameObject("Invalid drop handler");
        var sourceDefinition = ScriptableObject.CreateInstance(
            FindPlayerType("DessertDefinition"));
        var targetDefinition = ScriptableObject.CreateInstance(
            FindPlayerType("DessertDefinition"));

        try
        {
            sourceDefinition.GetType().GetField(
                "tier",
                BindingFlags.Instance | BindingFlags.NonPublic)
                .SetValue(sourceDefinition, 1);
            targetDefinition.GetType().GetField(
                "tier",
                BindingFlags.Instance | BindingFlags.NonPublic)
                .SetValue(targetDefinition, 2);

            Component origin = originObject.AddComponent(
                FindPlayerType("GridCell"));
            Component target = targetObject.AddComponent(
                FindPlayerType("GridCell"));
            Component source = sourceObject.AddComponent(
                FindPlayerType("Dessert"));
            Component incompatible = targetDessertObject.AddComponent(
                FindPlayerType("Dessert"));
            Component handler = handlerObject.AddComponent(
                FindPlayerType("DessertDragHandler"));
            SetPrivateField(source, "definition", sourceDefinition);
            SetPrivateField(incompatible, "definition", targetDefinition);
            Invoke(origin, "PlaceDessert", new object[] { source, false });
            Invoke(target, "PlaceDessert", new object[] { incompatible, false });
            SetPrivateField(handler, "dessert", source);
            SetPrivateField(handler, "originCell", origin);

            LogAssert.Expect(
                LogType.Warning,
                new Regex(
                    @"AudioManager: No AudioClip is assigned for SFX " +
                    @"'Action_Invalid'\."));
            Invoke(handler, "TryDropOnBoard", new[] { target });

            Assert.AreSame(source, GetPrivateField(origin, "currentDessert"));
            Assert.AreSame(
                incompatible,
                GetPrivateField(target, "currentDessert"));
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(handlerObject);
            UnityEngine.Object.DestroyImmediate(sourceObject);
            UnityEngine.Object.DestroyImmediate(targetDessertObject);
            UnityEngine.Object.DestroyImmediate(originObject);
            UnityEngine.Object.DestroyImmediate(targetObject);
            UnityEngine.Object.DestroyImmediate(sourceDefinition);
            UnityEngine.Object.DestroyImmediate(targetDefinition);
            DestroyManager(audioManagerObject);
        }
    }

    [Test]
    public void CanceledDragDoesNotRequestInvalidAction()
    {
        GameObject audioManagerObject = CreateManager(out Component manager);
        var cellObject = new GameObject("Canceled drag cell");
        var dessertObject = new GameObject("Canceled drag dessert");
        try
        {
            Component cell = cellObject.AddComponent(
                FindPlayerType("GridCell"));
            Component dessert = dessertObject.AddComponent(
                FindPlayerType("Dessert"));
            Component handler = dessertObject.AddComponent(
                FindPlayerType("DessertDragHandler"));
            Invoke(cell, "PlaceDessert", new object[] { dessert, false });

            LogAssert.Expect(
                LogType.Warning,
                new Regex(
                    @"AudioManager: No AudioClip is assigned for SFX " +
                    @"'Dessert_Pickup'\."));
            Invoke(
                handler,
                "OnPointerDown",
                new object[] { new UnityEngine.EventSystems.PointerEventData(null) });
            GetPrivateField(manager, "missingClipWarnings")
                .GetType()
                .GetMethod("Clear")
                .Invoke(GetPrivateField(manager, "missingClipWarnings"), null);

            Invoke(
                handler,
                "OnPointerUp",
                new object[] { new UnityEngine.EventSystems.PointerEventData(null) });

            Assert.IsFalse(WasMissingClipWarned(manager, "Action_Invalid"));
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(dessertObject);
            UnityEngine.Object.DestroyImmediate(cellObject);
            DestroyManager(audioManagerObject);
        }
    }

    [Test]
    public void ProgrammaticSpawnAndRestoreDoNotRequestInvalidAction()
    {
        string ovenControllerSource = System.IO.File.ReadAllText(
            "Assets/_Game/Scripts/Gameplay/OvenController.cs");
        string ovenManagerSource = System.IO.File.ReadAllText(
            "Assets/_Game/Scripts/Gameplay/OvenManager.cs");
        string spawnerSource = System.IO.File.ReadAllText(
            "Assets/_Game/Scripts/Gameplay/DessertSpawner.cs");
        Assert.AreEqual(
            1,
            Regex.Matches(
                ovenControllerSource,
                @"AudioManager\.Play\(SfxId\.Action_Invalid\)").Count);
        StringAssert.DoesNotContain(
            "Action_Invalid",
            spawnerSource);
        StringAssert.DoesNotContain(
            "Action_Invalid",
            ovenManagerSource);

        string dragSource = System.IO.File.ReadAllText(
            "Assets/_Game/Scripts/Gameplay/DessertDragHandler.cs");
        Assert.AreEqual(
            1,
            Regex.Matches(
                dragSource,
                @"AudioManager\.Play\(SfxId\.Action_Invalid\)").Count);
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
            Assert.IsFalse(WasMissingClipWarned(manager, "Action_Invalid"));

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

    private static Component GetManagerComponent(GameObject managerObject)
    {
        return managerObject.GetComponent(AudioManagerType);
    }

    private static bool WasMissingClipWarned(Component manager, string id)
    {
        object warnings = GetPrivateField(manager, "missingClipWarnings");
        MethodInfo contains = warnings.GetType().GetMethod("Contains");
        object enumId = Enum.Parse(FindPlayerType("SfxId"), id);
        return (bool)contains.Invoke(warnings, new[] { enumId });
    }

    private static object Invoke(
        object target,
        string methodName,
        object[] arguments = null)
    {
        int parameterCount = arguments != null ? arguments.Length : 0;
        MethodInfo method = target.GetType()
            .GetMethods(
                BindingFlags.Instance |
                BindingFlags.Public |
                BindingFlags.NonPublic)
            .FirstOrDefault(candidate =>
                candidate.Name == methodName &&
                candidate.GetParameters().Length == parameterCount);
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

    private static void AssertUiClickRequestCount(
        string relativePath,
        string methodSignature,
        int expectedCount)
    {
        string methodSource = GetSourceMethod(relativePath, methodSignature);
        Assert.AreEqual(
            expectedCount,
            Regex.Matches(methodSource, @"UiClickSfx\.TryPlay\(").Count,
            $"{methodSignature} UI click request count.");
    }

    private static string GetSourceMethod(
        string relativePath,
        string methodSignature)
    {
        string source = System.IO.File.ReadAllText(relativePath);
        int methodStart = source.IndexOf(
            methodSignature,
            StringComparison.Ordinal);
        Assert.GreaterOrEqual(
            methodStart,
            0,
            $"Could not find {methodSignature} in {relativePath}.");

        int methodEnd = source.Length;
        int nextPrivateMethod = source.IndexOf(
            "\n    private ",
            methodStart + methodSignature.Length,
            StringComparison.Ordinal);
        int nextPublicMethod = source.IndexOf(
            "\n    public ",
            methodStart + methodSignature.Length,
            StringComparison.Ordinal);
        if (nextPrivateMethod >= 0)
            methodEnd = nextPrivateMethod;
        if (nextPublicMethod >= 0 && nextPublicMethod < methodEnd)
            methodEnd = nextPublicMethod;

        return source.Substring(methodStart, methodEnd - methodStart);
    }

    private static Type FindPlayerType(string name)
    {
        return AppDomain.CurrentDomain.GetAssemblies()
            .Select(assembly => assembly.GetType(name))
            .FirstOrDefault(type => type != null);
    }
}
