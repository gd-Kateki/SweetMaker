using System;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

namespace SweetMerge.Advertising
{
    public sealed class RewardedEnergyDevelopmentCoordinator : MonoBehaviour
    {
        [SerializeField] private Button energyPlusButton;
        [SerializeField] private TMP_Text energyPlusText;
        [SerializeField] private AdvertisingConsentProvider privacyGate;
        [SerializeField] private LevelPlayAdService adsController;

        private PlayerProgressionManager progression;
        private bool loadAndShowRequested;
        private bool displayInProgress;
        private bool displayObserved;
        private bool completionObserved;
        private float refreshAccumulator;

        private void OnEnable()
        {
            if (energyPlusButton != null)
                energyPlusButton.onClick.AddListener(RequestRewardedEnergyTest);

            Bind();
            RefreshOfferState();
        }

        private void OnDisable()
        {
            if (energyPlusButton != null)
                energyPlusButton.onClick.RemoveListener(RequestRewardedEnergyTest);
            Unbind();
        }

        private void OnDestroy()
        {
            if (energyPlusButton != null)
                energyPlusButton.onClick.RemoveListener(RequestRewardedEnergyTest);
            Unbind();
        }

        private void Update()
        {
            if (energyPlusButton == null)
            {
                enabled = false;
                return;
            }

            refreshAccumulator += Time.unscaledDeltaTime;
            if (refreshAccumulator < 0.25f)
                return;
            refreshAccumulator = 0f;
            RefreshOfferState();
        }

        private void Bind()
        {
            if (progression == null)
                progression = PlayerProgressionManager.Instance;
            if (progression != null)
                progression.EnergyChanged += HandleEnergyChanged;

            privacyGate = AdvertisingPrivacyGate.Instance ?? privacyGate;
            adsController = LevelPlayAdService.Instance ?? adsController;
            if (privacyGate == null)
                privacyGate = FindAnyObjectByType<AdvertisingConsentProvider>();
            if (adsController == null)
                adsController = FindAnyObjectByType<LevelPlayAdService>();

            if (privacyGate != null)
                privacyGate.AdvertisingPrivacyChanged += HandleAdvertisingPrivacyChanged;
            if (adsController != null)
            {
                adsController.InitializationSucceeded += RefreshOfferState;
                adsController.InitializationFailed += HandleInitializationFailed;
                adsController.RewardedAdLoaded += HandleRewardedAdLoaded;
                adsController.RewardedAdLoadFailed += HandleRewardedAdLoadFailed;
                adsController.RewardedAdDisplayed += HandleRewardedAdDisplayed;
                adsController.RewardedAdDisplayFailed += HandleRewardedAdDisplayFailed;
                adsController.RewardedAdRewarded += HandleRewardedAdRewarded;
                adsController.RewardedAdClosed += HandleRewardedAdClosed;
            }
        }

        private void Unbind()
        {
            if (progression != null)
                progression.EnergyChanged -= HandleEnergyChanged;

            if (privacyGate != null)
                privacyGate.AdvertisingPrivacyChanged -= HandleAdvertisingPrivacyChanged;
            if (adsController != null)
            {
                adsController.InitializationSucceeded -= RefreshOfferState;
                adsController.InitializationFailed -= HandleInitializationFailed;
                adsController.RewardedAdLoaded -= HandleRewardedAdLoaded;
                adsController.RewardedAdLoadFailed -= HandleRewardedAdLoadFailed;
                adsController.RewardedAdDisplayed -= HandleRewardedAdDisplayed;
                adsController.RewardedAdDisplayFailed -= HandleRewardedAdDisplayFailed;
                adsController.RewardedAdRewarded -= HandleRewardedAdRewarded;
                adsController.RewardedAdClosed -= HandleRewardedAdClosed;
            }
        }

        private void HandleEnergyChanged()
        {
            RefreshOfferState();
        }

        private void HandleAdvertisingPrivacyChanged(bool allowed)
        {
            if (!allowed)
                CancelPendingRequest("Advertising privacy was withdrawn.");
            RefreshOfferState();
        }

        private void HandleInitializationFailed(string error)
        {
            CancelPendingRequest("LevelPlay initialization failed: " + error);
        }

        private void HandleRewardedAdLoaded()
        {
            if (!loadAndShowRequested)
            {
                RefreshOfferState();
                return;
            }

            loadAndShowRequested = false;
            if (!CanShowOffer())
                return;

            displayInProgress = true;
            completionObserved = false;
            adsController.ShowRewarded();
            SetButtonState(false, "DISPLAYING");
        }

        private void HandleRewardedAdLoadFailed(string error)
        {
            CancelPendingRequest("Rewarded ad load failed: " + error);
        }

        private void HandleRewardedAdDisplayed()
        {
            displayObserved = true;
            completionObserved = false;
            Debug.Log("Rewarded Energy: rewarded ad displayed.");
            SetButtonState(false, "DISPLAYING");
        }

        private void HandleRewardedAdDisplayFailed(string error)
        {
            CancelPendingRequest("Rewarded ad display failed: " + error);
        }

        private void HandleRewardedAdRewarded()
        {
            if (!displayInProgress || !displayObserved || completionObserved)
            {
                Debug.LogWarning(
                    "Duplicate or unexpected rewarded callback ignored by Rewarded Energy coordinator.");
                return;
            }

            completionObserved = true;
            if (progression == null)
                progression = PlayerProgressionManager.Instance;

            if (progression == null ||
                !progression.TryGrantEnergyFromVerifiedReward(50))
            {
                Debug.LogWarning(
                    "Rewarded Energy: verified reward received but Energy could not be granted.");
                SetButtonState(false, "UNAVAILABLE");
                return;
            }

            Debug.Log("Rewarded Energy: verified reward granted +50 Energy, capped at 100.");
            SetButtonState(false, "ENERGY +50");
        }

        private void HandleRewardedAdClosed()
        {
            if (displayInProgress && !completionObserved)
            {
                Debug.Log(
                    "Rewarded Energy development test: ad closed without a completion callback. No payout.");
            }

            displayInProgress = false;
            displayObserved = false;
            completionObserved = false;
            loadAndShowRequested = false;
            RefreshOfferState();
        }

        public void RequestRewardedEnergyTest()
        {
#if !UNITY_ANDROID || UNITY_EDITOR
            Debug.LogWarning("Rewarded Energy offer blocked outside Android runtime.");
            return;
#else
            if (progression == null)
                progression = PlayerProgressionManager.Instance;

            if (progression == null || progression.CurrentEnergy >= progression.MaximumEnergy)
            {
                Debug.Log("Rewarded Energy offer unavailable because Energy is already full.");
                RefreshOfferState();
                return;
            }

            if (displayInProgress || loadAndShowRequested)
            {
                Debug.Log("Rewarded Energy request ignored while a request is in progress.");
                return;
            }

            if (privacyGate == null || !privacyGate.IsAdvertisingAllowed)
            {
                Debug.LogWarning(
                    "Rewarded Energy offer blocked by AdvertisingPrivacyGate.");
                RefreshOfferState();
                return;
            }

            if (adsController == null || !adsController.IsInitialized)
            {
                Debug.LogWarning(
                    "Rewarded Energy offer blocked because LevelPlay is not initialized.");
                RefreshOfferState();
                return;
            }

            if (adsController.IsRewardedAdReady)
            {
                displayInProgress = true;
                completionObserved = false;
                adsController.ShowRewarded();
                SetButtonState(false, "DISPLAYING");
                return;
            }

            loadAndShowRequested = true;
            SetButtonState(false, "LOADING");
            adsController.LoadRewarded();
#endif
        }

        private void CancelPendingRequest(string reason)
        {
            if (loadAndShowRequested || displayInProgress || completionObserved)
            {
                Debug.Log(reason);
            }
            loadAndShowRequested = false;
            displayInProgress = false;
            displayObserved = false;
            completionObserved = false;
            RefreshOfferState();
        }

        private bool CanShowOffer()
        {
            if (progression == null ||
                progression.CurrentEnergy >= progression.MaximumEnergy)
                return false;
            if (privacyGate == null || !privacyGate.IsAdvertisingAllowed)
                return false;
            if (adsController == null || !adsController.IsInitialized)
                return false;
            return adsController.IsRewardedAdReady;
        }

        private void RefreshOfferState()
        {
            if (progression == null)
                progression = PlayerProgressionManager.Instance;

            if (progression == null)
            {
                SetButtonState(false, "UNAVAILABLE");
                return;
            }

            if (progression.CurrentEnergy >= progression.MaximumEnergy)
            {
                SetButtonState(false, "FULL");
                return;
            }

            if (loadAndShowRequested)
            {
                SetButtonState(false, "LOADING");
                return;
            }

            if (displayInProgress)
            {
                SetButtonState(false, completionObserved ? "NO PAYOUT" : "DISPLAYING");
                return;
            }

            if (privacyGate == null || !privacyGate.IsAdvertisingAllowed)
            {
                SetButtonState(false, "PRIVACY");
                return;
            }

            if (adsController == null || !adsController.IsInitialized)
            {
                SetButtonState(false, "NOT INITIALIZED");
                return;
            }

            if (!adsController.IsRewardedAdReady)
            {
                SetButtonState(true, "LOAD AD");
                return;
            }

            SetButtonState(true, "TEST AD");
        }

        private void SetButtonState(bool interactable, string label)
        {
            if (energyPlusButton != null)
                energyPlusButton.interactable = interactable;
            if (energyPlusText != null)
                energyPlusText.text = label;
        }
    }
}
