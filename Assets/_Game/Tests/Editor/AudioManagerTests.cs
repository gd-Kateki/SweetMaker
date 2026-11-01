using System;
using System.Collections;
using System.Linq;
using System.Reflection;
using System.Text.RegularExpressions;
using NUnit.Framework;
using UnityEditor;
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
    public void LoadedAudioPreferencesApplyAtStartupWithoutUsingMusicPreferences()
    {
        Component settingsManager;
        object previousSettingsManager;
        GameObject settingsObject = CreateSettingsManager(
            false,
            0.42f,
            false,
            0f,
            true,
            out settingsManager,
            out previousSettingsManager);
        GameObject audioManagerObject = null;

        try
        {
            audioManagerObject = CreateManager(out Component audioManager);
            Invoke(audioManager, "InitializeRuntime");

            Assert.AreEqual(
                0.42f,
                (float)AudioManagerType.GetMethod(
                        "GetSfxVolume",
                        BindingFlags.Public | BindingFlags.Static)
                    .Invoke(null, null));
            Assert.IsFalse((bool)GetPrivateField(audioManager, "sfxEnabled"));
            Assert.IsTrue((bool)GetPrivateField(audioManager, "vibrationEnabled"));
            Assert.IsNotEmpty(audioManager.GetComponents<AudioSource>());
            foreach (AudioSource source in audioManager.GetComponents<AudioSource>())
                Assert.AreEqual(0f, source.volume);
        }
        finally
        {
            if (audioManagerObject != null)
                DestroyManager(audioManagerObject);
            DestroySettingsManager(
                settingsObject,
                settingsManager,
                previousSettingsManager);
        }
    }

    [Test]
    public void UninitializedSettingsWaitForTheLoadedSnapshot()
    {
        Component settingsManager;
        object previousSettingsManager;
        GameObject settingsObject = CreateSettingsManager(
            false,
            0.25f,
            true,
            0.7f,
            false,
            out settingsManager,
            out previousSettingsManager);
        GameObject audioManagerObject = null;

        try
        {
            SetPrivateField(
                settingsManager,
                "persistenceStatus",
                Enum.Parse(
                    FindPlayerType("SettingsPersistenceStatus"),
                    "NotInitialized"));
            audioManagerObject = CreateManager(out Component audioManager);
            Invoke(audioManager, "InitializeRuntime");

            Assert.IsTrue((bool)GetPrivateField(audioManager, "sfxEnabled"));
            Assert.IsFalse((bool)GetPrivateField(audioManager, "vibrationEnabled"));
            Assert.AreEqual(
                1f,
                (float)AudioManagerType.GetMethod(
                    "GetSfxVolume",
                    BindingFlags.Public | BindingFlags.Static)
                    .Invoke(null, null));

            SetPrivateField(
                settingsManager,
                "persistenceStatus",
                Enum.Parse(
                    FindPlayerType("SettingsPersistenceStatus"),
                    "Loaded"));
            Invoke(audioManager, "TryBindSettingsManager");

            Assert.IsFalse((bool)GetPrivateField(audioManager, "sfxEnabled"));
            Assert.IsFalse((bool)GetPrivateField(audioManager, "vibrationEnabled"));
            Assert.AreEqual(
                0.25f,
                (float)AudioManagerType.GetMethod(
                    "GetSfxVolume",
                    BindingFlags.Public | BindingFlags.Static)
                    .Invoke(null, null));
            Assert.IsNotEmpty(audioManager.GetComponents<AudioSource>());
            foreach (AudioSource source in audioManager.GetComponents<AudioSource>())
                Assert.AreEqual(0f, source.volume);
        }
        finally
        {
            if (audioManagerObject != null)
                DestroyManager(audioManagerObject);
            DestroySettingsManager(
                settingsObject,
                settingsManager,
                previousSettingsManager);
        }
    }

    [Test]
    public void SettingsChangesMuteAndRestoreSfxAndPreserveSavedVolume()
    {
        Component settingsManager;
        object previousSettingsManager;
        GameObject settingsObject = CreateSettingsManager(
            true,
            0.7f,
            true,
            0.9f,
            true,
            out settingsManager,
            out previousSettingsManager);
        GameObject audioManagerObject = null;
        AudioClip clip = null;

        try
        {
            audioManagerObject = CreateManager(out Component audioManager);
            Invoke(audioManager, "InitializeRuntime");
            clip = AudioClip.Create("SFX settings test", 441, 1, 44100, false);
            ConfigureClipEntry(audioManager, "Dessert_Spawn", clip, 0.5f);

            SetSettingsValues(settingsManager, true, 0.7f, false, 0f, true);
            RaiseSettingsChanged(settingsManager);
            Assert.IsTrue((bool)GetPrivateField(audioManager, "sfxEnabled"));
            Assert.AreEqual(0.7f, (float)AudioManagerType.GetMethod(
                "GetSfxVolume",
                BindingFlags.Public | BindingFlags.Static).Invoke(null, null));
            foreach (AudioSource source in audioManager.GetComponents<AudioSource>())
                Assert.AreEqual(0.7f, source.volume);

            object sfxId = Enum.Parse(
                FindPlayerType("SfxId"),
                "Dessert_Spawn");
            Assert.IsTrue((bool)Invoke(
                audioManager,
                "TryPlayInternal",
                new[] { sfxId }));

            SetSettingsValues(settingsManager, false, 0.7f, false, 0f, true);
            RaiseSettingsChanged(settingsManager);
            Assert.IsFalse((bool)GetPrivateField(audioManager, "sfxEnabled"));
            Assert.AreEqual(0.7f, (float)AudioManagerType.GetMethod(
                "GetSfxVolume",
                BindingFlags.Public | BindingFlags.Static).Invoke(null, null));
            foreach (AudioSource source in audioManager.GetComponents<AudioSource>())
            {
                Assert.AreEqual(0f, source.volume);
                Assert.IsFalse(source.isPlaying);
            }

            Assert.IsFalse((bool)Invoke(
                audioManager,
                "TryPlayInternal",
                new[] { sfxId }));

            SetSettingsValues(settingsManager, false, 0.35f, true, 1f, true);
            RaiseSettingsChanged(settingsManager);
            Assert.AreEqual(0.35f, (float)AudioManagerType.GetMethod(
                "GetSfxVolume",
                BindingFlags.Public | BindingFlags.Static).Invoke(null, null));
            Assert.IsNotEmpty(audioManager.GetComponents<AudioSource>());
            foreach (AudioSource source in audioManager.GetComponents<AudioSource>())
                Assert.AreEqual(0f, source.volume);

            SetSettingsValues(settingsManager, true, 0.35f, true, 1f, true);
            RaiseSettingsChanged(settingsManager);
            Assert.IsTrue((bool)GetPrivateField(audioManager, "sfxEnabled"));
            Assert.AreEqual(0.35f, (float)AudioManagerType.GetMethod(
                "GetSfxVolume",
                BindingFlags.Public | BindingFlags.Static).Invoke(null, null));
            Assert.IsTrue((bool)Invoke(
                audioManager,
                "TryPlayInternal",
                new[] { sfxId }));
            foreach (AudioSource source in audioManager.GetComponents<AudioSource>())
                Assert.AreEqual(0.35f, source.volume);
        }
        finally
        {
            if (clip != null)
                UnityEngine.Object.DestroyImmediate(clip);
            if (audioManagerObject != null)
                DestroyManager(audioManagerObject);
            DestroySettingsManager(settingsObject, settingsManager, previousSettingsManager);
        }
    }

    [Test]
    public void SettingsSubscriptionIsIdempotentAndRemovedOnDestroy()
    {
        Component settingsManager;
        object previousSettingsManager;
        GameObject settingsObject = CreateSettingsManager(
            true,
            0.5f,
            true,
            0.7f,
            true,
            out settingsManager,
            out previousSettingsManager);
        GameObject audioManagerObject = null;
        Component audioManager = null;

        try
        {
            audioManagerObject = CreateManager(out audioManager);
            Invoke(audioManager, "TryBindSettingsManager");
            Invoke(audioManager, "TryBindSettingsManager");

            Delegate listeners = (Delegate)GetPrivateField(
                settingsManager,
                "SettingsChanged");
            Assert.AreEqual(
                1,
                listeners.GetInvocationList()
                    .Count(callback => callback.Target == audioManager));

            DestroyManager(audioManagerObject);
            audioManagerObject = null;

            listeners = (Delegate)GetPrivateField(
                settingsManager,
                "SettingsChanged");
            Assert.IsTrue(
                listeners == null ||
                listeners.GetInvocationList()
                    .All(callback => callback.Target != audioManager));
        }
        finally
        {
            if (audioManagerObject != null)
                DestroyManager(audioManagerObject);
            DestroySettingsManager(settingsObject, settingsManager, previousSettingsManager);
        }
    }

    [Test]
    public void ZeroVolumeIsSilentAndClipVolumeScalingRemainsConfigured()
    {
        Component settingsManager;
        object previousSettingsManager;
        GameObject settingsObject = CreateSettingsManager(
            true,
            0f,
            true,
            1f,
            true,
            out settingsManager,
            out previousSettingsManager);
        GameObject audioManagerObject = null;
        AudioClip clip = null;

        try
        {
            audioManagerObject = CreateManager(out Component audioManager);
            Invoke(audioManager, "InitializeRuntime");
            clip = AudioClip.Create("SFX volume test", 441, 1, 44100, false);
            object entry = ConfigureClipEntry(
                audioManager,
                "Dessert_Spawn",
                clip,
                0.35f);

            Assert.IsTrue((bool)Invoke(
                audioManager,
                "TryPlayInternal",
                new[]
                {
                    Enum.Parse(FindPlayerType("SfxId"), "Dessert_Spawn")
                }));
            Assert.AreEqual(0f, (float)AudioManagerType.GetMethod(
                "GetSfxVolume",
                BindingFlags.Public | BindingFlags.Static).Invoke(null, null));
            Assert.IsNotEmpty(audioManager.GetComponents<AudioSource>());
            foreach (AudioSource source in audioManager.GetComponents<AudioSource>())
                Assert.AreEqual(0f, source.volume);

            SetSettingsValues(settingsManager, true, 0.6f, false, 0f, true);
            RaiseSettingsChanged(settingsManager);
            Assert.AreEqual(0.6f, (float)AudioManagerType.GetMethod(
                "GetSfxVolume",
                BindingFlags.Public | BindingFlags.Static).Invoke(null, null));
            Assert.AreEqual(0.35f, GetPublicField(entry, "baseVolume"));
            foreach (AudioSource source in audioManager.GetComponents<AudioSource>())
                Assert.AreEqual(0.6f, source.volume);
        }
        finally
        {
            if (clip != null)
                UnityEngine.Object.DestroyImmediate(clip);
            if (audioManagerObject != null)
                DestroyManager(audioManagerObject);
            DestroySettingsManager(settingsObject, settingsManager, previousSettingsManager);
        }
    }

    [Test]
    public void LiveVibrationPreferenceUpdatesTheGameplayHapticDecision()
    {
        Component settingsManager;
        object previousSettingsManager;
        GameObject settingsObject = CreateSettingsManager(
            true,
            0.8f,
            true,
            0.7f,
            true,
            out settingsManager,
            out previousSettingsManager);
        GameObject audioManagerObject = null;

        try
        {
            audioManagerObject = CreateManager(out Component audioManager);
            Assert.IsTrue((bool)Invoke(audioManager, "ShouldVibrateForGameplay"));

            SetSettingsValues(
                settingsManager,
                true,
                0.8f,
                true,
                0.7f,
                false);
            RaiseSettingsChanged(settingsManager);
            Assert.IsFalse((bool)Invoke(audioManager, "ShouldVibrateForGameplay"));

            SetSettingsValues(
                settingsManager,
                true,
                0.8f,
                true,
                0.7f,
                true);
            RaiseSettingsChanged(settingsManager);
            Assert.IsTrue((bool)Invoke(audioManager, "ShouldVibrateForGameplay"));
        }
        finally
        {
            if (audioManagerObject != null)
                DestroyManager(audioManagerObject);
            DestroySettingsManager(
                settingsObject,
                settingsManager,
                previousSettingsManager);
        }
    }

    [Test]
    public void SfxAndVibrationPreferencesAreIndependent()
    {
        Component settingsManager;
        object previousSettingsManager;
        GameObject settingsObject = CreateSettingsManager(
            false,
            0.65f,
            true,
            0.2f,
            true,
            out settingsManager,
            out previousSettingsManager);
        GameObject audioManagerObject = null;
        AudioClip clip = null;

        try
        {
            audioManagerObject = CreateManager(out Component audioManager);
            Invoke(audioManager, "InitializeRuntime");
            clip = AudioClip.Create(
                "SFX haptics independence test",
                441,
                1,
                44100,
                false);
            ConfigureClipEntry(audioManager, "Dessert_Spawn", clip, 1f);

            Assert.IsTrue((bool)Invoke(audioManager, "ShouldVibrateForGameplay"));
            Assert.IsFalse((bool)Invoke(
                audioManager,
                "TryPlayInternal",
                new[]
                {
                    Enum.Parse(FindPlayerType("SfxId"), "Dessert_Spawn")
                }));

            SetSettingsValues(
                settingsManager,
                true,
                0.65f,
                true,
                0.2f,
                false);
            RaiseSettingsChanged(settingsManager);

            Assert.IsFalse((bool)Invoke(audioManager, "ShouldVibrateForGameplay"));
            Assert.IsTrue((bool)Invoke(
                audioManager,
                "TryPlayInternal",
                new[]
                {
                    Enum.Parse(FindPlayerType("SfxId"), "Dessert_Spawn")
                }));
        }
        finally
        {
            if (clip != null)
                UnityEngine.Object.DestroyImmediate(clip);
            if (audioManagerObject != null)
                DestroyManager(audioManagerObject);
            DestroySettingsManager(
                settingsObject,
                settingsManager,
                previousSettingsManager);
        }
    }

    [Test]
    public void GameplayHapticsRouteOnceFromSuccessHandlersAndAreEditorNoOp()
    {
        string source = System.IO.File.ReadAllText(
            "Assets/_Game/Scripts/Core/AudioManager.cs");
        string mergeHandler = GetSourceMethod(
            "Assets/_Game/Scripts/Core/AudioManager.cs",
            "private void HandleDessertMergeCommitted(");
        string orderHandler = GetSourceMethod(
            "Assets/_Game/Scripts/Core/AudioManager.cs",
            "private void HandleOrderCompleted(");
        string vibrationMethod = GetSourceMethod(
            "Assets/_Game/Scripts/Core/AudioManager.cs",
            "private void VibrateForGameplay(");

        Assert.AreEqual(
            1,
            Regex.Matches(mergeHandler, @"VibrateForGameplay\(\)").Count);
        Assert.AreEqual(
            1,
            Regex.Matches(orderHandler, @"VibrateForGameplay\(\)").Count);
        StringAssert.Contains(
            "GameplayEvents.DessertMergeCommitted += HandleDessertMergeCommitted;",
            source);
        StringAssert.DoesNotContain(
            "GameplayEvents.DessertMerged += ",
            source);
        StringAssert.Contains(
            "#if UNITY_ANDROID && !UNITY_EDITOR",
            vibrationMethod);
        StringAssert.Contains(
            "Application.platform == RuntimePlatform.Android",
            vibrationMethod);
        StringAssert.Contains(
            "SystemInfo.deviceType == DeviceType.Handheld",
            vibrationMethod);
        StringAssert.Contains("Handheld.Vibrate();", vibrationMethod);
        StringAssert.DoesNotContain("sfxEnabled", vibrationMethod);

        GameObject audioManagerObject = CreateManager(out Component audioManager);
        try
        {
            Type gameplayEventsType = FindPlayerType("GameplayEvents");
            Delegate mergeSubscribers = (Delegate)gameplayEventsType.GetField(
                "DessertMergeCommitted",
                BindingFlags.Static | BindingFlags.NonPublic)
                .GetValue(null);
            Assert.AreEqual(
                1,
                mergeSubscribers.GetInvocationList()
                    .Count(callback => callback.Target == audioManager));

            FieldInfo mergedEvent = gameplayEventsType.GetField(
                "DessertMerged",
                BindingFlags.Static | BindingFlags.NonPublic);
            Delegate mergedSubscribers =
                (Delegate)mergedEvent.GetValue(null);
            Assert.IsTrue(
                mergedSubscribers == null ||
                mergedSubscribers.GetInvocationList()
                    .All(callback => callback.Target != audioManager));

            SetPrivateField(audioManager, "vibrationEnabled", true);
            Assert.IsTrue((bool)Invoke(audioManager, "ShouldVibrateForGameplay"));
            Assert.DoesNotThrow(() => Invoke(audioManager, "VibrateForGameplay"));
        }
        finally
        {
            DestroyManager(audioManagerObject);
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
            "private void OpenSelectionPanel()",
            1);
        AssertUiClickRequestCount(
            "Assets/_Game/Scripts/UI/SpawnPoolSelectorUI.cs",
            "private void CloseSelectionPanel()",
            1);
        AssertUiClickRequestCount(
            "Assets/_Game/Scripts/UI/SpawnPoolSelectorUI.cs",
            "private void SelectPool(int index)",
            1);
        string selectorSource = System.IO.File.ReadAllText(
            "Assets/_Game/Scripts/UI/SpawnPoolSelectorUI.cs");
        StringAssert.Contains("() => SelectPool(poolIndex)", selectorSource);
        StringAssert.Contains(
            "tierButtons[i].onClick.AddListener(tierButtonListeners[i])",
            selectorSource);

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
        int requestHelperEnd;
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
        int helperBodyStart = progressionSource.IndexOf(
            '{',
            requestHelperStart);
        Assert.Greater(helperBodyStart, requestHelperStart);
        int braceDepth = 0;
        requestHelperEnd = -1;
        for (int i = helperBodyStart; i < progressionSource.Length; i++)
        {
            if (progressionSource[i] == '{')
            {
                braceDepth++;
            }
            else if (progressionSource[i] == '}')
            {
                braceDepth--;
                if (braceDepth == 0)
                {
                    requestHelperEnd = i + 1;
                    break;
                }
            }
        }
        Assert.Greater(requestHelperEnd, helperBodyStart);
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
    public void CampaignCompletionSaveAndNotificationFollowClosedSuccessfulMerge()
    {
        string handlerSource = System.IO.File.ReadAllText(
            "Assets/_Game/Scripts/Gameplay/DessertDragHandler.cs");
        int failedCreationCheck = handlerSource.IndexOf(
            "if (upgradedDessert == null)",
            StringComparison.Ordinal);
        int failedCreationExit = handlerSource.IndexOf(
            "yield break;",
            failedCreationCheck,
            StringComparison.Ordinal);
        int mergeCommit = handlerSource.IndexOf(
            "GameplayEvents.RaiseDessertMergeCommitted(",
            StringComparison.Ordinal);
        int transactionClosed = handlerSource.IndexOf(
            "CompleteMergeTransaction();",
            mergeCommit,
            StringComparison.Ordinal);
        int completionSave = handlerSource.IndexOf(
            "activeProgressionManager.TryPersistCampaignCompletion()",
            transactionClosed,
            StringComparison.Ordinal);

        Assert.Greater(failedCreationExit, failedCreationCheck);
        Assert.Greater(mergeCommit, failedCreationExit);
        Assert.Greater(transactionClosed, mergeCommit);
        Assert.Greater(completionSave, transactionClosed);
        StringAssert.DoesNotContain(
            "RaiseCampaignCompleted",
            handlerSource,
            "The merge handler must not announce completion before save confirmation.");
        StringAssert.Contains("resultingTier == 30", handlerSource);
        StringAssert.Contains("!campaignWasComplete", handlerSource);
        StringAssert.Contains(
            "activeProgressionManager.CampaignComplete",
            handlerSource);

        string saveManagerSource = System.IO.File.ReadAllText(
            "Assets/_Game/Scripts/Save/SaveManager.cs");
        int saveCore = saveManagerSource.IndexOf(
            "saveSucceeded = SaveCurrentGameCore();",
            StringComparison.Ordinal);
        int saveConfirmation = saveManagerSource.IndexOf(
            "MarkCampaignCompletionSaved();",
            saveCore,
            StringComparison.Ordinal);
        Assert.Greater(saveConfirmation, saveCore,
            "Persistence state must change only after the save core succeeds.");
        int coreStart = saveManagerSource.IndexOf(
            "private bool SaveCurrentGameCore()",
            StringComparison.Ordinal);
        int coreFailure = saveManagerSource.IndexOf(
            "if (!SaveCore(saveData))",
            coreStart,
            StringComparison.Ordinal);
        int coreSuccess = saveManagerSource.IndexOf(
            "return true;",
            coreFailure,
            StringComparison.Ordinal);
        Assert.Greater(coreFailure, coreStart);
        Assert.Greater(coreSuccess, coreFailure,
            "Completion persistence is confirmed only after SaveCore succeeds.");
        StringAssert.Contains("saveData.campaignComplete =", saveManagerSource);

        string restoreSource = System.IO.File.ReadAllText(
            "Assets/_Game/Scripts/Gameplay/MergeSessionController.cs");
        StringAssert.DoesNotContain("RaiseCampaignCompleted", restoreSource);
    }

    [Test]
    public void SaveManagerRejectsInvalidSnapshotBeforeCreatingFiles()
    {
        GameObject managerObject = new GameObject(
            "Invalid save snapshot validation test");
        managerObject.SetActive(false);
        object saveManager = managerObject.AddComponent(
            FindPlayerType("SaveManager"));
        string testDirectory = System.IO.Path.Combine(
            System.IO.Path.GetTempPath(),
            "SweetMaker.SaveValidation." + Guid.NewGuid().ToString("N"));
        string snapshotPath = System.IO.Path.Combine(
            testDirectory,
            "snapshot.json");

        try
        {
            MethodInfo writeSnapshot = saveManager.GetType().GetMethod(
                "TryWritePreparedSnapshot",
                BindingFlags.Instance | BindingFlags.NonPublic,
                null,
                new[]
                {
                    typeof(string),
                    typeof(string),
                    typeof(bool).MakeByRefType()
                },
                null);
            Assert.IsNotNull(writeSnapshot);

            object[] arguments = { "{}", snapshotPath, false };
            LogAssert.Expect(
                LogType.Error,
                "SAVE | Serialized snapshot failed validation.");
            bool saved = (bool)writeSnapshot.Invoke(
                saveManager,
                arguments);

            Assert.IsFalse(saved,
                "A non-V2 snapshot must not be written.");
            Assert.IsFalse((bool)arguments[2],
                "An invalid snapshot must not be reported as committed.");
            Assert.IsFalse(System.IO.Directory.Exists(testDirectory),
                "Validation must reject the snapshot before creating its directory.");
        }
        finally
        {
            if (System.IO.Directory.Exists(testDirectory))
                System.IO.Directory.Delete(testDirectory, true);
            UnityEngine.Object.DestroyImmediate(managerObject);
        }
    }

    [Test]
    public void FullBoardOvenTapRequestsInvalidOnce()
    {
        GameObject audioManagerObject = CreateManager(out _);
        var progressionObject = new GameObject("Full board test progression");
        progressionObject.SetActive(false);
        PropertyInfo progressionInstance = FindPlayerType("PlayerProgressionManager")
            .GetProperty("Instance", BindingFlags.Public | BindingFlags.Static);
        object previousProgression = progressionInstance.GetValue(null);
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

            // OvenManager requires the authoritative progression singleton before
            // it can reach the full-board rejection path.
            Component progression = progressionObject.AddComponent(
                FindPlayerType("PlayerProgressionManager"));
            progressionInstance.GetSetMethod(true).Invoke(null, new object[] { progression });
            Invoke(progression, "ResetEnergy", null);
            int energyBefore = (int)progression.GetType()
                .GetProperty("CurrentEnergy").GetValue(progression);
            Assert.Greater(energyBefore, 0);
            Assert.AreSame(progression, progressionInstance.GetValue(null));

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
                "dessertCatalog",
                AssetDatabase.LoadMainAssetAtPath(
                    "Assets/_Game/Resources/DessertCatalog.asset"));

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
            Assert.AreEqual(energyBefore, progression.GetType()
                .GetProperty("CurrentEnergy").GetValue(progression),
                "A full-board rejection must not consume Energy.");

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
            UnityEngine.Object.DestroyImmediate(progressionObject);
            progressionInstance.GetSetMethod(true)
                .Invoke(null, new[] { previousProgression });
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
            Invoke(handler, "Awake");
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

            Invoke(handler, "Awake");
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

            Invoke(handler, "Awake");
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
    public void MainBakeryHasOneRootAudioManagerAndTwelveAssignedApprovedEntries()
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
        MatchCollection entries = Regex.Matches(
            managerComponent.Value,
            @"(?m)^  - id: (?<id>\d+)\r?\n" +
            @"(?<fields>(?:^    .*\r?\n?)*)");
        CollectionAssert.AreEqual(
            Enumerable.Range(0, 12).Select(id => id.ToString()).ToArray(),
            entries.Cast<Match>()
                .Select(entry => entry.Groups["id"].Value)
                .ToArray(),
            "The scene must configure each approved SfxId exactly once.");
        Assert.AreEqual(12, entries.Count);
        foreach (Match entry in entries)
        {
            Match clip = Regex.Match(
                entry.Groups["fields"].Value,
                @"(?m)^    clip: \{fileID: (?<fileId>\d+), " +
                @"guid: (?<guid>[0-9a-f]{32}), type: 3\}\r?$");
            Assert.IsTrue(clip.Success,
                $"SFX id {entry.Groups["id"].Value} needs an AudioClip reference.");
            Assert.AreNotEqual("0", clip.Groups["fileId"].Value);
            string assetPath = AssetDatabase.GUIDToAssetPath(
                clip.Groups["guid"].Value);
            Assert.IsNotEmpty(assetPath,
                $"SFX id {entry.Groups["id"].Value} references an unknown asset GUID.");
            Assert.IsNotNull(AssetDatabase.LoadAssetAtPath<AudioClip>(assetPath),
                $"SFX id {entry.Groups["id"].Value} must resolve to an AudioClip.");
        }
        StringAssert.Contains(
            "- {fileID: 2200000201}",
            sceneRoots.Value);
        Assert.AreEqual(
            1,
            Regex.Matches(scene, @"(?m)^AudioListener:\r?$").Count);
    }

    private static GameObject CreateSettingsManager(
        bool sfxEnabled,
        float sfxVolume,
        bool musicEnabled,
        float musicVolume,
        bool vibrationEnabled,
        out Component settingsManager,
        out object previousInstance)
    {
        Type settingsManagerType = FindPlayerType("SettingsManager");
        PropertyInfo instanceProperty = settingsManagerType.GetProperty(
            "Instance",
            BindingFlags.Public | BindingFlags.Static);
        previousInstance = instanceProperty.GetValue(null);

        var settingsObject = new GameObject("SettingsManager test");
        settingsObject.SetActive(false);
        settingsManager = settingsObject.AddComponent(settingsManagerType);

        Type profileType = FindPlayerType("SettingsProfileData");
        object profile = Activator.CreateInstance(profileType);
        profileType.GetField("sfxEnabled").SetValue(profile, sfxEnabled);
        profileType.GetField("sfxVolume").SetValue(profile, sfxVolume);
        profileType.GetField("musicEnabled").SetValue(profile, musicEnabled);
        profileType.GetField("musicVolume").SetValue(profile, musicVolume);
        profileType.GetField("vibrationEnabled").SetValue(profile, vibrationEnabled);
        SetPrivateField(settingsManager, "currentSettings", profile);
        SetPrivateField(
            settingsManager,
            "persistenceStatus",
            Enum.Parse(
                FindPlayerType("SettingsPersistenceStatus"),
                "Loaded"));
        instanceProperty.GetSetMethod(true).Invoke(
            null,
            new[] { settingsManager });
        return settingsObject;
    }

    private static void SetSettingsValues(
        Component settingsManager,
        bool sfxEnabled,
        float sfxVolume,
        bool musicEnabled,
        float musicVolume,
        bool vibrationEnabled)
    {
        object profile = GetPrivateField(settingsManager, "currentSettings");
        Type profileType = profile.GetType();
        profileType.GetField("sfxEnabled").SetValue(profile, sfxEnabled);
        profileType.GetField("sfxVolume").SetValue(profile, sfxVolume);
        profileType.GetField("musicEnabled").SetValue(profile, musicEnabled);
        profileType.GetField("musicVolume").SetValue(profile, musicVolume);
        profileType.GetField("vibrationEnabled").SetValue(profile, vibrationEnabled);
    }

    private static void RaiseSettingsChanged(Component settingsManager)
    {
        Delegate listeners = (Delegate)GetPrivateField(
            settingsManager,
            "SettingsChanged");
        if (listeners == null)
            return;

        listeners.DynamicInvoke(
            GetPrivateField(settingsManager, "currentSettings"));
    }

    private static object ConfigureClipEntry(
        Component manager,
        string id,
        AudioClip clip,
        float baseVolume)
    {
        Type entryType = FindPlayerType("SfxClipEntry");
        object entry = Activator.CreateInstance(entryType);
        entryType.GetField("id").SetValue(
            entry,
            Enum.Parse(FindPlayerType("SfxId"), id));
        entryType.GetField("clip").SetValue(entry, clip);
        entryType.GetField("baseVolume").SetValue(entry, baseVolume);

        Type listType = typeof(System.Collections.Generic.List<>)
            .MakeGenericType(entryType);
        IList entries = (IList)Activator.CreateInstance(listType);
        entries.Add(entry);
        SetPrivateField(manager, "clips", entries);
        Invoke(manager, "RebuildClipLookup");
        return entry;
    }

    private static void DestroySettingsManager(
        GameObject settingsObject,
        Component settingsManager,
        object previousInstance)
    {
        if (settingsManager != null)
            Invoke(settingsManager, "OnDestroy");
        if (settingsObject != null)
            UnityEngine.Object.DestroyImmediate(settingsObject);

        FindPlayerType("SettingsManager")
            .GetProperty("Instance", BindingFlags.Public | BindingFlags.Static)
            .GetSetMethod(true)
            .Invoke(null, new[] { previousInstance });
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

    private static object GetPublicField(
        object target,
        string fieldName)
    {
        FieldInfo field = target.GetType().GetField(
            fieldName,
            BindingFlags.Instance | BindingFlags.Public);
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
