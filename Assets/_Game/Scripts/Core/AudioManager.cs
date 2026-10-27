using System;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

[Serializable]
public sealed class SfxClipEntry
{
    public SfxId id;
    public AudioClip clip;
    [Range(0f, 1f)]
    public float baseVolume = 1f;
    [Range(0f, 1f)]
    public float pitchVariation;
    [Min(0f)]
    public float minimumReplayInterval;
}

public sealed class AudioManager : MonoBehaviour
{
    private const int SourcePoolSize = 6;

    private static float ClampNormalized(float value, float fallback)
    {
        return float.IsNaN(value)
            ? fallback
            : Mathf.Clamp01(value);
    }

    public static AudioManager Instance
    {
        get;
        private set;
    }

    [Header("SFX Registry")]
    [SerializeField]
    private List<SfxClipEntry> clips = new List<SfxClipEntry>();

    [Header("Volume")]
    [SerializeField, Range(0f, 1f)]
    private float sfxVolume = 1f;

    [Header("Play Mode Test")]
    [SerializeField]
    private SfxId testSfxId;

    private readonly Dictionary<SfxId, SfxClipEntry> clipsById =
        new Dictionary<SfxId, SfxClipEntry>();
    private readonly Dictionary<SfxId, float> lastPlayedAt =
        new Dictionary<SfxId, float>();
    private readonly HashSet<SfxId> missingClipWarnings =
        new HashSet<SfxId>();
    private AudioSource[] audioSources = Array.Empty<AudioSource>();
    private SettingsManager subscribedSettingsManager;
    private bool sfxEnabled = true;
    private bool vibrationEnabled;
    private OrderManager subscribedOrderManager;
    private UpgradePurchaseManager subscribedUpgradePurchaseManager;

    public int SourcePoolCount => audioSources.Length;

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            if (Application.isPlaying)
                Destroy(gameObject);
            else
                DestroyImmediate(gameObject);
            return;
        }

        Instance = this;
        TryBindSettingsManager();
        GameplayEvents.DessertSpawned += HandleDessertSpawned;
        GameplayEvents.DessertMergeCommitted += HandleDessertMergeCommitted;
        SceneManager.sceneLoaded += HandleSceneLoaded;
        SubscribeToOrderManager(FindAnyObjectByType<OrderManager>());
        SubscribeToUpgradePurchaseManager(
            FindAnyObjectByType<UpgradePurchaseManager>());
        if (!Application.isPlaying)
            return;

        transform.SetParent(null, true);
        DontDestroyOnLoad(gameObject);
        InitializeRuntime();
    }

    private void Start()
    {
        TryBindSettingsManager();
    }

    private void OnDestroy()
    {
        GameplayEvents.DessertSpawned -= HandleDessertSpawned;
        GameplayEvents.DessertMergeCommitted -= HandleDessertMergeCommitted;
        SceneManager.sceneLoaded -= HandleSceneLoaded;
        UnbindSettingsManager();
        SubscribeToOrderManager(null);
        SubscribeToUpgradePurchaseManager(null);
        if (Instance == this)
            Instance = null;
    }

    private void HandleDessertSpawned(int tier)
    {
        Play(SfxId.Dessert_Spawn);
    }

    private void HandleDessertMergeCommitted(
        int resultingTier,
        bool isNewHighestTier)
    {
        Play(
            isNewHighestTier
                ? SfxId.Dessert_MergeSpecial
                : SfxId.Dessert_Merge);
        VibrateForGameplay();
    }

    private void HandleSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        TryBindSettingsManager();
        SubscribeToOrderManager(FindAnyObjectByType<OrderManager>());
        SubscribeToUpgradePurchaseManager(
            FindAnyObjectByType<UpgradePurchaseManager>());
    }

    private void TryBindSettingsManager()
    {
        SettingsManager currentManager = SettingsManager.Instance;
        if (currentManager == null)
            return;

        if (subscribedSettingsManager != currentManager)
        {
            UnbindSettingsManager();
            subscribedSettingsManager = currentManager;
            subscribedSettingsManager.SettingsChanged +=
                HandleSettingsChanged;
        }

        if (subscribedSettingsManager.PersistenceStatus ==
            SettingsPersistenceStatus.NotInitialized)
        {
            return;
        }

        ApplySettings(subscribedSettingsManager.CurrentSettings);
    }

    private void UnbindSettingsManager()
    {
        if (subscribedSettingsManager != null)
        {
            subscribedSettingsManager.SettingsChanged -=
                HandleSettingsChanged;
        }

        subscribedSettingsManager = null;
    }

    private void HandleSettingsChanged(SettingsProfileData settings)
    {
        ApplySettings(settings);
    }

    private void ApplySettings(SettingsProfileData settings)
    {
        if (settings == null)
            return;

        SetVolumeInternal(settings.sfxVolume);
        SetSfxEnabledInternal(settings.sfxEnabled);
        vibrationEnabled = settings.vibrationEnabled;
    }

    private bool ShouldVibrateForGameplay()
    {
        return vibrationEnabled;
    }

    private void VibrateForGameplay()
    {
        if (!ShouldVibrateForGameplay())
            return;

#if UNITY_ANDROID && !UNITY_EDITOR
        if (Application.platform == RuntimePlatform.Android &&
            SystemInfo.deviceType == DeviceType.Handheld)
        {
            Handheld.Vibrate();
        }
#endif
    }

    private void SubscribeToOrderManager(OrderManager orderManager)
    {
        if (subscribedOrderManager == orderManager)
            return;

        if (subscribedOrderManager != null)
        {
            subscribedOrderManager.OrderCompleted -= HandleOrderCompleted;
        }

        subscribedOrderManager = orderManager;
        if (subscribedOrderManager != null)
        {
            subscribedOrderManager.OrderCompleted += HandleOrderCompleted;
        }
    }

    private void HandleOrderCompleted(CustomerOrder order)
    {
        Play(SfxId.Order_Complete);
        VibrateForGameplay();
    }

    private void SubscribeToUpgradePurchaseManager(
        UpgradePurchaseManager upgradePurchaseManager)
    {
        if (subscribedUpgradePurchaseManager == upgradePurchaseManager)
            return;

        if (subscribedUpgradePurchaseManager != null)
        {
            subscribedUpgradePurchaseManager.UpgradePurchased -=
                HandleUpgradePurchased;
        }

        subscribedUpgradePurchaseManager = upgradePurchaseManager;
        if (subscribedUpgradePurchaseManager != null)
        {
            subscribedUpgradePurchaseManager.UpgradePurchased +=
                HandleUpgradePurchased;
        }
    }

    private void HandleUpgradePurchased(
        UpgradeType type,
        int newLevel,
        int amountSpent)
    {
        Play(SfxId.Upgrade_Success);
    }

    public static void Play(SfxId id)
    {
        TryPlay(id);
    }

    public static bool TryPlay(SfxId id)
    {
        return Instance != null && Instance.TryPlayInternal(id);
    }

    public static void SetSfxVolume(float normalizedVolume)
    {
        if (Instance != null)
            Instance.SetVolumeInternal(normalizedVolume);
    }

    public static float GetSfxVolume()
    {
        return Instance != null ? Instance.sfxVolume : 1f;
    }

    private void InitializeRuntime()
    {
        RebuildClipLookup();
        InitializeAudioSources();
        SetVolumeInternal(sfxVolume);
    }

    private void RebuildClipLookup()
    {
        clipsById.Clear();
        foreach (SfxClipEntry entry in clips)
        {
            if (entry == null)
                continue;

            if (clipsById.ContainsKey(entry.id))
            {
                Debug.LogWarning(
                    $"AudioManager: Duplicate SFX registry entry '{entry.id}'. " +
                    "The first entry will be used.",
                    this);
                continue;
            }

            clipsById.Add(entry.id, entry);
        }
    }

    private void InitializeAudioSources()
    {
        if (audioSources.Length == SourcePoolSize)
            return;

        var sources = new List<AudioSource>(SourcePoolSize);
        GetComponents(sources);
        if (sources.Count > SourcePoolSize)
            sources.RemoveRange(SourcePoolSize, sources.Count - SourcePoolSize);

        for (int i = 0; i < sources.Count; i++)
        {
            sources[i].playOnAwake = false;
            sources[i].loop = false;
            sources[i].spatialBlend = 0f;
        }

        while (sources.Count < SourcePoolSize)
            sources.Add(gameObject.AddComponent<AudioSource>());

        audioSources = sources.ToArray();
    }

    private bool TryPlayInternal(SfxId id)
    {
        if (!sfxEnabled)
            return false;

        if (!TryGetClipEntry(id, out SfxClipEntry entry))
        {
            WarnMissingClip(id);
            return false;
        }

        if (entry.clip == null)
        {
            WarnMissingClip(id);
            return false;
        }

        float now = Time.unscaledTime;
        float minimumInterval = float.IsNaN(entry.minimumReplayInterval)
            ? 0f
            : Mathf.Max(0f, entry.minimumReplayInterval);
        if (lastPlayedAt.TryGetValue(id, out float lastPlayed) &&
            now - lastPlayed < minimumInterval)
        {
            return false;
        }

        AudioSource source = FindAvailableSource();
        if (source == null)
        {
            // Keep the pool bounded; new effects are dropped rather than stealing a voice.
            return false;
        }

        float variation = ClampNormalized(entry.pitchVariation, 0f);
        source.pitch = UnityEngine.Random.Range(
            1f - variation,
            1f + variation);
        source.volume = sfxVolume;
        source.PlayOneShot(
            entry.clip,
            ClampNormalized(entry.baseVolume, 1f));
        lastPlayedAt[id] = now;
        return true;
    }

    private bool TryGetClipEntry(
        SfxId id,
        out SfxClipEntry entry)
    {
        return clipsById.TryGetValue(id, out entry);
    }

    private AudioSource FindAvailableSource()
    {
        foreach (AudioSource source in audioSources)
        {
            if (source != null && !source.isPlaying)
                return source;
        }

        return null;
    }

    private void SetVolumeInternal(float normalizedVolume)
    {
        sfxVolume = ClampNormalized(normalizedVolume, 1f);
        foreach (AudioSource source in audioSources)
        {
            if (source != null)
                source.volume = GetEffectiveVolume();
        }
    }

    private void SetSfxEnabledInternal(bool enabled)
    {
        if (sfxEnabled == enabled)
            return;

        sfxEnabled = enabled;
        foreach (AudioSource source in audioSources)
        {
            if (source == null)
                continue;

            if (!enabled)
                source.Stop();

            source.volume = GetEffectiveVolume();
        }
    }

    private float GetEffectiveVolume()
    {
        return sfxEnabled ? sfxVolume : 0f;
    }

    private void WarnMissingClip(SfxId id)
    {
        if (missingClipWarnings.Add(id))
        {
            Debug.LogWarning(
                $"AudioManager: No AudioClip is assigned for SFX '{id}'.",
                this);
        }
    }

    [ContextMenu("Test Selected SFX (Play Mode)")]
    private void TestSelectedSfx()
    {
        if (!Application.isPlaying)
        {
            Debug.LogWarning(
                "AudioManager: Enter Play Mode before testing an SFX.",
                this);
            return;
        }

        Play(testSfxId);
    }
}
