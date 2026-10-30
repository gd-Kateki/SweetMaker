using System;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace SweetMerge.Advertising
{
    [DisallowMultipleComponent]
    public sealed class AutomaticInterstitialScheduler : MonoBehaviour
    {
        private const float EligibilitySeconds = 300f;
        private static AutomaticInterstitialScheduler instance;

        private float activeGameplaySeconds;
        private bool interstitialEligible;
        private bool navigationPending;
        private bool subscribedToService;
        private Action continueNavigation;
        private LevelPlayAdService adsService;
        private AdvertisingConsentProvider consentProvider;

        public static AutomaticInterstitialScheduler Instance => instance;

#if UNITY_ANDROID && DEVELOPMENT_BUILD && !UNITY_EDITOR
        public bool IsDevelopmentInterstitialEligible => interstitialEligible;
        public float DevelopmentActiveGameplaySeconds => activeGameplaySeconds;

        public void DevelopmentSkipFiveMinutes()
        {
            activeGameplaySeconds = EligibilitySeconds;
            interstitialEligible = true;
        }

        public void DevelopmentResetTimer()
        {
            activeGameplaySeconds = 0f;
            interstitialEligible = false;
        }
#endif

        private void Awake()
        {
            if (instance != null && instance != this)
            {
                Destroy(this);
                return;
            }

            instance = this;
            DontDestroyOnLoad(gameObject);
            SceneManager.sceneLoaded += HandleSceneLoaded;
        }

        private void OnDestroy()
        {
            SceneManager.sceneLoaded -= HandleSceneLoaded;
            UnsubscribeFromService();
            if (instance == this)
                instance = null;
        }

        private void Update()
        {
            if (navigationPending || SceneManager.GetActiveScene().name != SceneNavigationManager.MergeGameplayScene)
                return;
            if (!Application.isFocused || GameplayModalInputGate.IsGameplayInputBlocked)
                return;
            if (GameManager.Instance == null || !GameManager.Instance.IsPlaying)
                return;

            activeGameplaySeconds += Time.unscaledDeltaTime;
            if (activeGameplaySeconds >= EligibilitySeconds)
                interstitialEligible = true;
        }

        public void NavigateToHome(Action navigation)
        {
            if (navigation == null)
                throw new ArgumentNullException(nameof(navigation));

            if (!interstitialEligible || !TryBindService() ||
                !adsService.IsInitialized || !adsService.IsInterstitialAdReady ||
                adsService.IsAdShowing)
            {
                navigation();
                return;
            }

            navigationPending = true;
            continueNavigation = navigation;
            SubscribeToService();
            adsService.ShowInterstitial();
        }

        private bool TryBindService()
        {
            if (adsService == null)
                adsService = LevelPlayAdService.Instance ?? FindAnyObjectByType<LevelPlayAdService>();
            if (consentProvider == null)
                consentProvider = AdvertisingPrivacyGate.Instance ??
                    FindAnyObjectByType<AdvertisingConsentProvider>();
            return adsService != null;
        }

        private void HandleSceneLoaded(Scene scene, LoadSceneMode mode)
        {
            if (scene.name != SceneNavigationManager.MergeGameplayScene)
            {
                UnsubscribeFromService();
                adsService = null;
                return;
            }

            TryBindService();
            SubscribeToService();
        }

        private void SubscribeToService()
        {
            if (subscribedToService || adsService == null)
                return;

            subscribedToService = true;
            adsService.InterstitialAdDisplayed += HandleInterstitialDisplayed;
            adsService.InterstitialAdClosed += HandleInterstitialClosed;
            adsService.InterstitialAdDisplayFailed += HandleInterstitialFailed;
            if (consentProvider != null)
                consentProvider.AdvertisingPrivacyChanged += HandleAdvertisingPrivacyChanged;
        }

        private void UnsubscribeFromService()
        {
            if (!subscribedToService || adsService == null)
                return;

            subscribedToService = false;
            adsService.InterstitialAdDisplayed -= HandleInterstitialDisplayed;
            adsService.InterstitialAdClosed -= HandleInterstitialClosed;
            adsService.InterstitialAdDisplayFailed -= HandleInterstitialFailed;
            if (consentProvider != null)
                consentProvider.AdvertisingPrivacyChanged -= HandleAdvertisingPrivacyChanged;
        }

        private void HandleInterstitialDisplayed()
        {
            if (!navigationPending)
                return;

            activeGameplaySeconds = 0f;
            interstitialEligible = false;
        }

        private void HandleInterstitialClosed()
        {
            if (!navigationPending)
                return;

            CompleteNavigation();
        }

        private void HandleInterstitialFailed(string error)
        {
            if (!navigationPending)
                return;

            Debug.LogWarning("Automatic interstitial display failed: " + error);
            CompleteNavigation();
        }

        private void HandleAdvertisingPrivacyChanged(bool allowed)
        {
            if (!allowed && navigationPending)
                CompleteNavigation();
        }

        private void CompleteNavigation()
        {
            Action navigation = continueNavigation;
            continueNavigation = null;
            navigationPending = false;
            UnsubscribeFromService();
            navigation?.Invoke();
        }
    }
}
