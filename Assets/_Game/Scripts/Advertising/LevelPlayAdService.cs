using System;
using UnityEngine;
using Unity.Services.LevelPlay;

namespace SweetMerge.Advertising
{
    [DisallowMultipleComponent]
    public sealed class LevelPlayAdService : MonoBehaviour
    {
        public event Action InitializationSucceeded;
        public event Action<string> InitializationFailed;
        public event Action InterstitialAdDisplayed;
        public event Action InterstitialAdClosed;
        public event Action<string> InterstitialAdDisplayFailed;
        public event Action RewardedAdLoaded;
        public event Action<string> RewardedAdLoadFailed;
        public event Action RewardedAdDisplayed;
        public event Action<string> RewardedAdDisplayFailed;
        public event Action RewardedAdRewarded;
        public event Action RewardedAdClosed;

        [SerializeField] private AdvertisingConsentProvider privacyGate;
        [SerializeField] private string appKey = "29245cbbd";
        [SerializeField] private string interstitialAdUnitId = "4gx9bo96ocyr4hiz";
        [SerializeField] private string rewardedAdUnitId = "hg0kom1zfpm0no12";
        [SerializeField] private string interstitialPlacementName;
        [SerializeField] private string rewardedPlacementName;

        private LevelPlayInterstitialAd interstitialAd;
        private LevelPlayRewardedAd rewardedAd;
        private bool initializationSubscribed;
        private bool initialized;
        private bool initializationRequested;
        private bool interstitialLoadRequested;
        private bool rewardedLoadRequested;
        private bool rewardedCallbackObserved;
        private bool interstitialAdLoaded;
        private bool rewardedAdLoaded;
        private string debugStatus = "Idle. Initialize LevelPlay first.";
        private string initializationState = "Not initialized";
        private string interstitialState = "Idle";
        private string rewardedState = "Idle";
        private string lastError = "None";
        private string lastSuccessfulOperation = "None";

        private bool adShowing;
        private float pendingSince;
        public bool IsAdShowing => adShowing;
        public bool IsRewardedAdShowing => rewardedShowRequested;
        public bool IsInterstitialLoading => interstitialLoadRequested;
        public bool IsRewardedLoading => rewardedLoadRequested;
        public string PendingOperationDiagnostic =>
            initializationRequested || interstitialLoadRequested || rewardedLoadRequested
                ? "Waiting for SDK callback (" + Mathf.FloorToInt(Time.realtimeSinceStartup - pendingSince) +
                  "s since latest request). If this persists, check network and Android logcat; do not assume success."
                : "No initialization/load callback pending.";
        public bool IsInitialized => initialized && ConsentAllowed;
        public bool IsRewardedAdReady =>
            IsInitialized && !adShowing && rewardedAdLoaded && rewardedAd != null && rewardedAd.IsAdReady();
        public bool IsInterstitialAdReady =>
            IsInitialized && !adShowing && interstitialAdLoaded && interstitialAd != null && interstitialAd.IsAdReady();
        public bool IsInitializationRequested => initializationRequested;
        public string InitializationState => initializationState;
        public string InterstitialState => interstitialState;
        public string RewardedState => rewardedState;
        public string LastError => lastError;
        public string LastSuccessfulOperation => lastSuccessfulOperation;
        public string DebugStatus => debugStatus;
        public string AppKey => appKey;
        public string InterstitialAdUnitId => interstitialAdUnitId;
        public string RewardedAdUnitId => rewardedAdUnitId;
        public static LevelPlayAdService Instance => owner;
        public string RewardedAvailabilityReason
        {
            get
            {
                if (!ConsentAllowed)
                    return privacyGate == null ? "Privacy provider missing." : privacyGate.AdvertisingBlockingReason;
                if (!initialized)
                    return initializationRequested ? "SDK initialization is in progress." : "SDK is not initialized.";
                if (adShowing)
                    return rewardedShowRequested ? "A rewarded ad is displaying." : "Another ad is displaying.";
                if (rewardedLoadRequested)
                    return "Rewarded ad is loading.";
                if (rewardedAd == null || !rewardedAdLoaded)
                    return "Rewarded ad has not completed its load callback.";
                if (!rewardedAd.IsAdReady())
                    return "Rewarded ad is not ready according to LevelPlay.";
                return "Ready.";
            }
        }

        // One native initialization attempt per process, including failed/ambiguous attempts.
        // Scene destruction or consent withdrawal cannot reset the native SDK safely.
        private static LevelPlayAdService owner;
        private static bool sdkInitializationAttempted;
        private bool sessionBlocked;
        private bool rewardedShowRequested;
        private bool rewardedReloadScheduled;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        private static void ResetSession()
        {
            owner = null;
            sdkInitializationAttempted = false;
        }

        private bool ConsentAllowed
        {
            get
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                if (!isActiveAndEnabled || owner != this || sessionBlocked ||
                    privacyGate == null || !privacyGate.isActiveAndEnabled)
                    return false;
#if !DEVELOPMENT_BUILD
                if (privacyGate.IsDevelopmentOnly ||
                    privacyGate.ConsentState != AdvertisingConsentState.Permitted ||
                    !privacyGate.IsPrivacyConfigurationApplied)
                    return false;
#endif
                return privacyGate.ConsentState == AdvertisingConsentState.Permitted &&
                    privacyGate.IsPrivacyConfigurationApplied &&
                    privacyGate.IsAdvertisingAllowed;
#else
                return false;
#endif
            }
        }

        private void Awake()
        {
            if (owner != null && owner != this)
            {
                enabled = false;
                return;
            }
            owner = this;
            DontDestroyOnLoad(gameObject);
#if UNITY_ANDROID && DEVELOPMENT_BUILD && !UNITY_EDITOR
            if (GetComponent<LevelPlayDevelopmentDebugOverlay>() == null)
                gameObject.AddComponent<LevelPlayDevelopmentDebugOverlay>();
#endif
        }

        private void OnEnable()
        {
            // Explicit scene reference: never discover or silently select a consent provider.
            if (privacyGate != null)
            {
                privacyGate.AdvertisingPrivacyChanged += HandleAdvertisingPrivacyChanged;
                if (privacyGate.IsAdvertisingAllowed)
                    Initialize();
            }
        }

        private void OnDisable()
        {
            if (privacyGate != null)
                privacyGate.AdvertisingPrivacyChanged -= HandleAdvertisingPrivacyChanged;
            if (owner == this) HandleAdvertisingPrivacyChanged(false);
        }

        private void OnDestroy()
        {
            UnsubscribeInitialization();
            DestroyAds();
            if (owner == this) owner = null;
        }

        public void Initialize()
        {
#if !UNITY_ANDROID || UNITY_EDITOR
            Debug.LogWarning(
                "LevelPlay service requires Android runtime outside the Editor.");
            return;
#else
            if (!Application.isMobilePlatform)
            {
                Debug.LogWarning("LevelPlay initialization is blocked outside Android.");
                return;
            }

            if (!CanInitialize())
                return;

            if (initialized)
            {
                Debug.Log("LevelPlay is already initialized.");
                return;
            }

            if (initializationRequested)
            {
                Debug.Log("LevelPlay initialization is already in progress.");
                return;
            }

            if (sdkInitializationAttempted)
            {
                lastError = debugStatus = "SDK initialization was already attempted. Restart the app before retrying.";
                initializationState = "Restart required";
                return;
            }

            SubscribeInitialization();
            initializationRequested = true;
            initializationState = "Initializing";
            lastError = "None";
            Debug.Log($"LevelPlay initialization requested. AppKey={appKey}");
            debugStatus = $"Initializing LevelPlay with AppKey {appKey}.";
            pendingSince = Time.realtimeSinceStartup;
            try
            {
#if DEVELOPMENT_BUILD
                LevelPlay.SetAdaptersDebug(true);
#endif
                sdkInitializationAttempted = true;
                LevelPlay.Init(appKey);
            }
            catch (Exception exception)
            {
                initializationRequested = false;
                initializationState = "Initialization exception; restart required";
                UnsubscribeInitialization();
                RecordException("Initialize", exception);
                InitializationFailed?.Invoke(lastError);
            }
#endif
        }

        public void LoadInterstitial()
        {
            if (!CanUseAds())
                return;

            if (string.IsNullOrWhiteSpace(interstitialAdUnitId))
            {
                Debug.LogError(
                    "Interstitial Ad Unit ID is missing. Configure it in the Inspector before loading.");
                lastError = debugStatus = "Interstitial blocked: Ad Unit ID is missing.";
                return;
            }

            if (interstitialLoadRequested || IsInterstitialAdReady || adShowing)
                return;

            try
            {
                EnsureInterstitialAd();
                interstitialLoadRequested = true;
                interstitialAdLoaded = false;
                interstitialState = "Loading";
                lastError = "None";
                Debug.Log($"LevelPlay interstitial load requested. AdUnit={interstitialAdUnitId}");
                debugStatus = $"Loading interstitial {interstitialAdUnitId}.";
                pendingSince = Time.realtimeSinceStartup;
                interstitialAd.LoadAd();
            }
            catch (Exception exception)
            {
                interstitialLoadRequested = false;
                interstitialAdLoaded = false;
                interstitialState = "Load exception";
                RecordException("Load interstitial", exception);
            }
        }

        public void ShowInterstitial()
        {
            if (!CanUseAds())
                return;

            if (interstitialAd == null)
            {
                Debug.LogWarning("Interstitial ad has not been created.");
                debugStatus = "Interstitial not created. Load it first.";
                return;
            }

            if (!IsInterstitialAdReady)
            {
                Debug.LogWarning("Interstitial ad is not ready.");
                debugStatus = "Interstitial is not loaded or ready.";
                return;
            }

            Debug.Log(
                $"LevelPlay interstitial display requested. Placement={GetPlacement(interstitialPlacementName)}");
            interstitialAdLoaded = false;
            debugStatus = "Showing interstitial.";
            adShowing = true;
            interstitialState = "Show requested; waiting for SDK";
            try { interstitialAd.ShowAd(interstitialPlacementName); }
            catch (Exception exception)
            {
                adShowing = false;
                interstitialState = "Display exception; reload required";
                RecordException("Show interstitial", exception);
            }
        }

        public void LoadRewarded()
        {
            if (!CanUseAds())
                return;

            if (string.IsNullOrWhiteSpace(rewardedAdUnitId))
            {
                Debug.LogError(
                    "Rewarded Ad Unit ID is missing. Configure it in the Inspector before loading.");
                lastError = debugStatus = "Rewarded blocked: Ad Unit ID is missing.";
                return;
            }

            if (rewardedLoadRequested || IsRewardedAdReady || adShowing)
                return;

            try
            {
                EnsureRewardedAd();
                rewardedLoadRequested = true;
                rewardedAdLoaded = false;
                rewardedState = "Loading";
                lastError = "None";
                Debug.Log($"LevelPlay rewarded load requested. AdUnit={rewardedAdUnitId}");
                debugStatus = $"Loading rewarded {rewardedAdUnitId}.";
                pendingSince = Time.realtimeSinceStartup;
                rewardedAd.LoadAd();
            }
            catch (Exception exception)
            {
                rewardedLoadRequested = false;
                rewardedAdLoaded = false;
                rewardedState = "Load exception";
                RecordException("Load rewarded", exception);
                RewardedAdLoadFailed?.Invoke(lastError);
                ScheduleRewardedReload();
            }
        }

        public void ShowRewarded()
        {
            if (!CanUseAds())
                return;

            if (rewardedAd == null)
            {
                Debug.LogWarning("Rewarded ad has not been created.");
                debugStatus = "Rewarded ad not created. Load it first.";
                return;
            }

            if (!IsRewardedAdReady)
            {
                Debug.LogWarning("Rewarded ad is not ready.");
                debugStatus = "Rewarded ad is not loaded or ready.";
                return;
            }

            Debug.Log(
                $"LevelPlay rewarded display requested. Placement={GetPlacement(rewardedPlacementName)}");
            rewardedAdLoaded = false;
            debugStatus = "Showing rewarded ad.";
            adShowing = true;
            rewardedCallbackObserved = false;
            rewardedShowRequested = true;
            rewardedState = "Show requested; waiting for SDK";
            try { rewardedAd.ShowAd(rewardedPlacementName); }
            catch (Exception exception)
            {
                adShowing = false;
                rewardedShowRequested = false;
                rewardedState = "Display exception; reload required";
                RecordException("Show rewarded", exception);
                RewardedAdDisplayFailed?.Invoke(lastError);
                LoadRewarded();
            }
        }

        private bool CanInitialize()
        {
            if (privacyGate == null)
            {
                Debug.LogWarning(
                    "LevelPlay initialization blocked: advertising consent provider is missing.");
                lastError = "Privacy gate is missing.";
                initializationState = "Blocked by privacy";
                return false;
            }

            if (!ConsentAllowed)
            {
                Debug.LogWarning(
                    "LevelPlay initialization blocked: advertising privacy prerequisites are unresolved.");
                lastError = privacyGate.IsDevelopmentOnly && !Debug.isDebugBuild
                    ? "Production consent provider is not implemented. Ads remain off."
                    : privacyGate.AdvertisingBlockingReason;
                initializationState = "Blocked by privacy";
                return false;
            }

            if (string.IsNullOrWhiteSpace(appKey))
            {
                Debug.LogError("LevelPlay initialization blocked: App Key is missing.");
                lastError = "App Key is missing.";
                initializationState = "Configuration error";
                return false;
            }

            return true;
        }

        private bool CanUseAds()
        {
            if (!initialized)
            {
                Debug.LogWarning("LevelPlay is not initialized.");
                lastError = "LevelPlay is not initialized.";
                return false;
            }

            if (!ConsentAllowed)
            {
                Debug.LogWarning("Advertising request blocked by advertising consent provider.");
                lastError = privacyGate == null
                    ? "advertising consent provider is missing."
                    : privacyGate.AdvertisingBlockingReason;
                return false;
            }

            return true;
        }

        private void SubscribeInitialization()
        {
            if (initializationSubscribed)
                return;

            initializationSubscribed = true;
            LevelPlay.OnInitSuccess += HandleInitSuccess;
            LevelPlay.OnInitFailed += HandleInitFailed;
        }

        private void UnsubscribeInitialization()
        {
            if (!initializationSubscribed)
                return;

            initializationSubscribed = false;
            LevelPlay.OnInitSuccess -= HandleInitSuccess;
            LevelPlay.OnInitFailed -= HandleInitFailed;
        }

        private void HandleInitSuccess(LevelPlayConfiguration configuration)
        {
            if (!initializationRequested || !ConsentAllowed) return;
            UnsubscribeInitialization();
            initialized = true;
            initializationRequested = false;
            initializationState = "Initialized";
            lastError = "None";
            lastSuccessfulOperation = "SDK initialization succeeded";
            Debug.Log("LevelPlay initialization succeeded.");
            debugStatus = "Initialized successfully.";
            InitializationSucceeded?.Invoke();
            LoadInterstitial();
            LoadRewarded();
        }

        private void HandleInitFailed(LevelPlayInitError error)
        {
            if (!initializationRequested || !ConsentAllowed) return;
            UnsubscribeInitialization();
            initialized = false;
            initializationRequested = false;
            initializationState = "Initialization failed; restart required";
            lastError = $"Code {error.ErrorCode}: {error.ErrorMessage}";
            Debug.LogError(
                $"LevelPlay initialization failed: {error}");
            debugStatus = lastError;
            InitializationFailed?.Invoke(error.ToString());
        }

        private void EnsureInterstitialAd()
        {
            if (interstitialAd != null)
                return;

            interstitialAd = new LevelPlayInterstitialAd(interstitialAdUnitId);
            var source = interstitialAd;
            interstitialAd.OnAdLoaded += info =>
            {
                if (source != interstitialAd || !ConsentAllowed) return;
                interstitialLoadRequested = false;
                interstitialAdLoaded = true;
                interstitialState = "Loaded and ready";
                lastError = "None";
                lastSuccessfulOperation = "Interstitial loaded";
                Debug.Log($"LevelPlay interstitial loaded: {info.AdUnitId}");
                debugStatus = "Interstitial loaded and ready.";
            };
            interstitialAd.OnAdLoadFailed += error =>
            {
                if (source != interstitialAd || !ConsentAllowed) return;
                interstitialLoadRequested = false;
                interstitialAdLoaded = false;
                interstitialState = "Load failed";
                lastError = $"Code {error.ErrorCode}: {error.ErrorMessage}";
                Debug.LogError(
                    $"LevelPlay interstitial load failed: {error.ErrorCode} {error.ErrorMessage}");
                debugStatus = $"Interstitial load failed: {lastError}";
            };
            interstitialAd.OnAdDisplayed += info =>
            {
                if (source != interstitialAd || !ConsentAllowed) return;
                interstitialAdLoaded = false;
                interstitialState = "Displaying";
                lastSuccessfulOperation = "Interstitial display started";
                Debug.Log($"LevelPlay interstitial displayed: {info.AdUnitId}");
                debugStatus = "Interstitial displayed.";
                InterstitialAdDisplayed?.Invoke();
            };
            interstitialAd.OnAdDisplayFailed += (info, error) =>
            {
                if (source != interstitialAd || !ConsentAllowed) return;
                adShowing = false;
                interstitialAdLoaded = false;
                interstitialState = "Display failed";
                lastError = $"Code {error.ErrorCode}: {error.ErrorMessage}";
                Debug.LogError(
                    $"LevelPlay interstitial display failed: {error.ErrorCode} {error.ErrorMessage}");
                debugStatus = $"Interstitial display failed: {lastError}";
                InterstitialAdDisplayFailed?.Invoke(lastError);
            };
            interstitialAd.OnAdClosed += info =>
            {
                if (source != interstitialAd || !ConsentAllowed) return;
                adShowing = false;
                interstitialState = "Closed; reload required";
                Debug.Log($"LevelPlay interstitial closed: {info.AdUnitId}");
                debugStatus = "Interstitial closed. Reload before showing again.";
                InterstitialAdClosed?.Invoke();
            };
        }

        private void EnsureRewardedAd()
        {
            if (rewardedAd != null)
                return;

            rewardedAd = new LevelPlayRewardedAd(rewardedAdUnitId);
            var source = rewardedAd;
            rewardedAd.OnAdLoaded += info =>
            {
                if (source != rewardedAd || !ConsentAllowed) return;
                rewardedLoadRequested = false;
                rewardedAdLoaded = true;
                rewardedState = "Loaded and ready";
                lastError = "None";
                lastSuccessfulOperation = "Rewarded loaded";
                Debug.Log($"LevelPlay rewarded loaded: {info.AdUnitId}");
                debugStatus = "Rewarded ad loaded and ready.";
                RewardedAdLoaded?.Invoke();
            };
            rewardedAd.OnAdLoadFailed += error =>
            {
                if (source != rewardedAd || !ConsentAllowed) return;
                rewardedLoadRequested = false;
                rewardedAdLoaded = false;
                rewardedState = "Load failed";
                lastError = $"Code {error.ErrorCode}: {error.ErrorMessage}";
                Debug.LogError(
                    $"LevelPlay rewarded load failed: {error.ErrorCode} {error.ErrorMessage}");
                debugStatus = $"Rewarded load failed: {lastError}";
                RewardedAdLoadFailed?.Invoke(
                    $"{error.ErrorCode} {error.ErrorMessage}");
                ScheduleRewardedReload();
            };
            rewardedAd.OnAdDisplayed += info =>
            {
                if (source != rewardedAd || !ConsentAllowed) return;
                rewardedAdLoaded = false;
                rewardedState = "Displaying";
                lastSuccessfulOperation = "Rewarded display started";
                Debug.Log($"LevelPlay rewarded displayed: {info.AdUnitId}");
                debugStatus = "Rewarded ad displayed.";
                RewardedAdDisplayed?.Invoke();
            };
            rewardedAd.OnAdDisplayFailed += (info, error) =>
            {
                if (source != rewardedAd || !ConsentAllowed) return;
                adShowing = false;
                rewardedAdLoaded = false;
                rewardedShowRequested = false;
                rewardedState = "Display failed";
                lastError = $"Code {error.ErrorCode}: {error.ErrorMessage}";
                Debug.LogError(
                    $"LevelPlay rewarded display failed: {error.ErrorCode} {error.ErrorMessage}");
                debugStatus = $"Rewarded display failed: {lastError}";
                RewardedAdDisplayFailed?.Invoke(
                    $"{error.ErrorCode} {error.ErrorMessage}");
                LoadRewarded();
            };
            rewardedAd.OnAdRewarded += (info, reward) =>
            {
                if (source != rewardedAd || !ConsentAllowed) return;
                if (!rewardedShowRequested || rewardedCallbackObserved)
                {
                    Debug.LogWarning(
                        $"Duplicate LevelPlay rewarded callback rejected for {info.AdUnitId}.");
                    return;
                }

                rewardedCallbackObserved = true;
                lastSuccessfulOperation = "Rewarded completion callback received; no payout";
                Debug.Log(
                    $"LevelPlay rewarded callback received: {reward.Name} x{reward.Amount}. No gameplay reward is granted.");
                debugStatus =
                    $"Reward callback received: {reward.Name} x{reward.Amount}. No gameplay reward.";
                RewardedAdRewarded?.Invoke();
            };
            rewardedAd.OnAdClosed += info =>
            {
                if (source != rewardedAd || !ConsentAllowed) return;
                adShowing = false;
                rewardedShowRequested = false;
                rewardedState = rewardedCallbackObserved
                    ? "Closed after reward callback; reload required"
                    : "Closed without reward callback; reload required";
                Debug.Log($"LevelPlay rewarded closed: {info.AdUnitId}");
                debugStatus =
                    rewardedCallbackObserved
                        ? "Rewarded ad closed after a reward callback. Reload before showing again."
                        : "Rewarded ad closed without a reward callback. Reload before showing again.";
                RewardedAdClosed?.Invoke();
                LoadRewarded();
            };
        }

        private void HandleAdvertisingPrivacyChanged(bool allowed)
        {
            if (allowed)
            {
                Initialize();
                return;
            }

            sessionBlocked |= sdkInitializationAttempted;
            DestroyAds();
            initialized = false;
            initializationRequested = false;
            UnsubscribeInitialization();
            debugStatus = "Advertising privacy withdrawn. SDK ads destroyed.";
            initializationState = "Blocked by privacy";
            interstitialState = "Unavailable";
            rewardedState = "Unavailable";
            lastError = "Advertising privacy was withdrawn.";
        }

        private void DestroyAds()
        {
            // Invalidate callbacks before native disposal, even if disposal throws.
            var oldInterstitial = interstitialAd;
            var oldRewarded = rewardedAd;
            interstitialAd = null;
            rewardedAd = null;
            adShowing = false;
            rewardedShowRequested = false;
            interstitialLoadRequested = false;
            rewardedLoadRequested = false;
            rewardedReloadScheduled = false;
            interstitialAdLoaded = false;
            rewardedAdLoaded = false;
            try { oldInterstitial?.DestroyAd(); }
            catch (Exception exception) { RecordException("Destroy interstitial", exception); }
            try { oldRewarded?.DestroyAd(); }
            catch (Exception exception) { RecordException("Destroy rewarded", exception); }
        }

        private void ScheduleRewardedReload()
        {
            if (rewardedReloadScheduled || !isActiveAndEnabled)
                return;

            rewardedReloadScheduled = true;
            Invoke(nameof(RetryRewardedLoad), 1f);
        }

        private void RetryRewardedLoad()
        {
            rewardedReloadScheduled = false;
            if (ConsentAllowed && initialized && !adShowing &&
                !rewardedLoadRequested && !IsRewardedAdReady)
                LoadRewarded();
        }

        private void RecordException(string operation, Exception exception)
        {
            lastError = operation + ": " + exception.GetType().Name + ": " + exception.Message;
            debugStatus = lastError;
            Debug.LogException(exception);
        }

        private static string GetPlacement(string placementName) =>
            string.IsNullOrWhiteSpace(placementName) ? "(default)" : placementName;
    }
}
