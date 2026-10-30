using TMPro;
using UnityEngine;
using UnityEngine.UI;

namespace SweetMerge.Advertising
{
    [DisallowMultipleComponent]
    public sealed class RewardedCoinsCoordinator : MonoBehaviour
    {
        private const int RewardAmount = 200;
        private const long CooldownTicks = 15 * 60 * System.TimeSpan.TicksPerSecond;
        private const string CooldownKey = "DMC.Advertising.RewardedCoinsCooldownUtcTicks.v1";
        private const string LastObservedUtcKey = "DMC.Advertising.RewardedCoinsLastObservedUtcTicks.v1";

        [SerializeField] private Button coinsPlusButton;
        [SerializeField] private TMP_Text coinsPlusText;
        [SerializeField] private AdvertisingConsentProvider privacyGate;
        [SerializeField] private LevelPlayAdService adsService;

        private EconomyManager economy;
        private bool requestActive;
        private bool displayObserved;
        private bool rewardObserved;
        private long cooldownDeadlineUtcTicks;
        private long lastObservedUtcTicks;
        private float refreshAccumulator;

#if UNITY_ANDROID && DEVELOPMENT_BUILD && !UNITY_EDITOR
        public bool IsDevelopmentCooldownActive => IsCooldownActive();
        public int DevelopmentCooldownRemainingSeconds
        {
            get
            {
                long remainingTicks = cooldownDeadlineUtcTicks - System.DateTime.UtcNow.Ticks;
                return Mathf.Max(0, Mathf.CeilToInt(
                    (float)new System.TimeSpan(remainingTicks).TotalSeconds));
            }
        }

        public void DevelopmentExpireCooldown()
        {
            cooldownDeadlineUtcTicks = 0;
            lastObservedUtcTicks = System.DateTime.UtcNow.Ticks;
            PlayerPrefs.DeleteKey(CooldownKey);
            PlayerPrefs.SetString(LastObservedUtcKey, lastObservedUtcTicks.ToString());
            PlayerPrefs.Save();
            Refresh();
        }

        public string DevelopmentAvailabilityReason =>
            GetAvailabilityReason();
#endif

        private void OnEnable()
        {
            if (coinsPlusButton != null)
                coinsPlusButton.onClick.AddListener(RequestRewardedCoins);

            Bind();
            LoadCooldown();
            Refresh();
        }

        private void OnDisable()
        {
            if (coinsPlusButton != null)
                coinsPlusButton.onClick.RemoveListener(RequestRewardedCoins);
            Unbind();
        }

        private void OnDestroy()
        {
            if (coinsPlusButton != null)
                coinsPlusButton.onClick.RemoveListener(RequestRewardedCoins);
            Unbind();
        }

        private void OnApplicationPause(bool paused)
        {
            if (paused)
                PersistLastObservedTime();
        }

        private void Update()
        {
            if (coinsPlusButton == null)
            {
                enabled = false;
                return;
            }

            refreshAccumulator += Time.unscaledDeltaTime;
            if (refreshAccumulator < 0.25f)
                return;
            refreshAccumulator = 0f;
            Refresh();
        }

        private void Bind()
        {
            economy = EconomyManager.Instance;
            if (economy == null)
                economy = FindAnyObjectByType<EconomyManager>();
            privacyGate = AdvertisingPrivacyGate.Instance ?? privacyGate;
            adsService = LevelPlayAdService.Instance ?? adsService;
            if (privacyGate == null)
                privacyGate = FindAnyObjectByType<AdvertisingConsentProvider>();
            if (adsService == null)
                adsService = FindAnyObjectByType<LevelPlayAdService>();

            if (privacyGate != null)
                privacyGate.AdvertisingPrivacyChanged += HandlePrivacyChanged;
            if (adsService != null)
            {
                adsService.RewardedAdDisplayed += HandleRewardedDisplayed;
                adsService.RewardedAdDisplayFailed += HandleRewardedDisplayFailed;
                adsService.RewardedAdRewarded += HandleRewarded;
                adsService.RewardedAdClosed += HandleRewardedClosed;
                adsService.RewardedAdLoadFailed += HandleRewardedLoadFailed;
                adsService.InitializationFailed += HandleInitializationFailed;
            }
        }

        private void Unbind()
        {
            if (privacyGate != null)
                privacyGate.AdvertisingPrivacyChanged -= HandlePrivacyChanged;
            if (adsService != null)
            {
                adsService.RewardedAdDisplayed -= HandleRewardedDisplayed;
                adsService.RewardedAdDisplayFailed -= HandleRewardedDisplayFailed;
                adsService.RewardedAdRewarded -= HandleRewarded;
                adsService.RewardedAdClosed -= HandleRewardedClosed;
                adsService.RewardedAdLoadFailed -= HandleRewardedLoadFailed;
                adsService.InitializationFailed -= HandleInitializationFailed;
            }
        }

        public void RequestRewardedCoins()
        {
#if !UNITY_ANDROID || UNITY_EDITOR
            Debug.LogWarning("Rewarded Coins offer blocked outside Android runtime.");
            return;
#else
            if (requestActive || IsCooldownActive() ||
                privacyGate == null || !privacyGate.IsAdvertisingAllowed ||
                adsService == null || !adsService.IsInitialized)
            {
                Refresh();
                return;
            }

            requestActive = true;
            displayObserved = false;
            rewardObserved = false;
            if (adsService.IsRewardedAdReady)
                adsService.ShowRewarded();
            else
            {
                requestActive = false;
                Refresh();
            }
#endif
        }

        private void HandleRewardedDisplayed()
        {
            if (!requestActive)
                return;
            displayObserved = true;
            rewardObserved = false;
        }

        private void HandleRewarded()
        {
            if (!requestActive || !displayObserved || rewardObserved)
                return;

            rewardObserved = true;
            if (economy == null)
                economy = EconomyManager.Instance;
            if (economy == null || !economy.TryAddRewardedCoins(RewardAmount))
            {
                Debug.LogWarning("Rewarded Coins: verified reward could not be credited.");
                return;
            }

            cooldownDeadlineUtcTicks = System.DateTime.UtcNow.Ticks + CooldownTicks;
            PlayerPrefs.SetString(CooldownKey, cooldownDeadlineUtcTicks.ToString());
            lastObservedUtcTicks = System.DateTime.UtcNow.Ticks;
            PlayerPrefs.SetString(LastObservedUtcKey, lastObservedUtcTicks.ToString());
            PlayerPrefs.Save();
            Debug.Log("Rewarded Coins: verified reward granted +200 Coins.");
        }

        private void HandleRewardedClosed()
        {
            if (requestActive && !rewardObserved)
                Debug.Log("Rewarded Coins: ad closed without a reward. No Coins granted.");
            requestActive = false;
            displayObserved = false;
            rewardObserved = false;
            Refresh();
        }

        private void HandleRewardedDisplayFailed(string error)
        {
            Debug.LogWarning("Rewarded Coins display failed: " + error);
            requestActive = false;
            displayObserved = false;
            rewardObserved = false;
            Refresh();
        }

        private void HandleRewardedLoadFailed(string error) => Refresh();
        private void HandleInitializationFailed(string error) => Refresh();
        private void HandlePrivacyChanged(bool allowed)
        {
            if (!allowed)
            {
                requestActive = false;
                displayObserved = false;
                rewardObserved = false;
            }
            Refresh();
        }

        private bool IsCooldownActive()
        {
            long now = System.DateTime.UtcNow.Ticks;
            return cooldownDeadlineUtcTicks > now;
        }

        private void LoadCooldown()
        {
            string value = PlayerPrefs.GetString(CooldownKey, string.Empty);
            if (!long.TryParse(value, out cooldownDeadlineUtcTicks) ||
                cooldownDeadlineUtcTicks < 0 ||
                cooldownDeadlineUtcTicks > System.DateTime.MaxValue.Ticks)
                cooldownDeadlineUtcTicks = 0;
            value = PlayerPrefs.GetString(LastObservedUtcKey, string.Empty);
            if (!long.TryParse(value, out lastObservedUtcTicks) ||
                lastObservedUtcTicks < 0 ||
                lastObservedUtcTicks > System.DateTime.MaxValue.Ticks)
                lastObservedUtcTicks = 0;
        }

        private void Refresh()
        {
            if (coinsPlusButton == null)
                return;

            long nowUtcTicks = System.DateTime.UtcNow.Ticks;
            if (lastObservedUtcTicks > nowUtcTicks)
            {
                SetButtonState(false, "TIME INVALID");
                return;
            }
            lastObservedUtcTicks = nowUtcTicks;

            if (requestActive)
            {
                SetButtonState(false, "WATCHING");
                return;
            }

            if (IsCooldownActive())
            {
                long remainingTicks = cooldownDeadlineUtcTicks - System.DateTime.UtcNow.Ticks;
                int minutes = Mathf.CeilToInt(
                    (float)new System.TimeSpan(remainingTicks).TotalMinutes);
                SetButtonState(false, $"COINS {Mathf.Max(1, minutes)}m");
                return;
            }

            bool available = privacyGate != null && privacyGate.IsAdvertisingAllowed &&
                adsService != null && adsService.IsInitialized && adsService.IsRewardedAdReady;
            SetButtonState(available, available ? "WATCH +200" : "UNAVAILABLE");
        }

        private string GetAvailabilityReason()
        {
            if (requestActive)
                return "A Coins rewarded request is already active.";
            if (IsCooldownActive())
                return "Coins cooldown is active.";
            if (privacyGate == null || !privacyGate.IsAdvertisingAllowed)
                return privacyGate == null ? "Advertising privacy provider is missing." :
                    privacyGate.AdvertisingBlockingReason;
            if (adsService == null)
                return "LevelPlay service is missing.";
            if (!adsService.IsInitialized)
                return adsService.RewardedAvailabilityReason;
            if (!adsService.IsRewardedAdReady)
                return adsService.RewardedAvailabilityReason;
            return "Ready.";
        }

        private void SetButtonState(bool interactable, string label)
        {
            coinsPlusButton.interactable = interactable;
            if (coinsPlusText != null)
                coinsPlusText.text = label;
        }

        private void PersistLastObservedTime()
        {
            long nowUtcTicks = System.DateTime.UtcNow.Ticks;
            if (nowUtcTicks < lastObservedUtcTicks)
                return;
            lastObservedUtcTicks = nowUtcTicks;
            PlayerPrefs.SetString(LastObservedUtcKey, lastObservedUtcTicks.ToString());
            PlayerPrefs.Save();
        }
    }
}
