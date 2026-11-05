using System;
using System.Collections;
using System.Collections.Generic;
using Unity.Services.LevelPlay;
using UnityEngine;
using UnityEngine.SceneManagement;

public sealed class SimpleAdManager : MonoBehaviour
{
    public static SimpleAdManager Instance { get; private set; }
    private SimpleAdsSettings settings;
    private LevelPlayRewardedAd rewarded;
    private LevelPlayInterstitialAd interstitial;
    private string loadedAuction;
    private bool showing, loadingRewarded, loadingInterstitial, initialized;
    private float nextInterstitial, cashPlaySeconds, retryRewarded, retryInterstitial;
    private Action afterInterstitial;
    private GameplayModalInputGate.GameplayModalLease adLease;
    private readonly Dictionary<string, RewardTicket> rewards = new Dictionary<string, RewardTicket>();
    public bool RewardedReady => initialized && !showing && rewarded != null && rewarded.IsAdReady();
    public string Status { get; private set; } = "Ads are loading. Please try again shortly.";

    internal sealed class RewardTicket
    {
        internal readonly bool Energy;
        internal readonly int Amount;
        private bool claimed;
        internal RewardTicket(bool energy, int amount) { Energy = energy; Amount = amount; }
        internal bool TryClaim() { if (claimed) return false; claimed = true; return true; }
    }

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
    private static void Create()
    {
        if (Instance == null) new GameObject("Ads").AddComponent<SimpleAdManager>();
    }

    private void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        settings = Resources.Load<SimpleAdsSettings>("SimpleAdsSettings");
        if (settings == null) { enabled = false; Debug.LogError("ADS | Settings missing."); return; }
        nextInterstitial = Time.realtimeSinceStartup + settings.interstitialIntervalSeconds;
#if UNITY_ANDROID && !UNITY_EDITOR
        LevelPlay.OnInitSuccess += OnInitialized;
        LevelPlay.OnInitFailed += OnInitFailed;
        LevelPlay.Init(settings.androidAppKey);
#else
        Status = "Ads run on an Android device. No rewards are simulated in the Editor.";
#endif
    }

    private void OnInitFailed(LevelPlayInitError error)
    {
        Status = "Ads could not connect. Reopen the game to retry.";
        Debug.LogWarning("ADS | Initialization failed: " + error);
    }

    private void OnInitialized(LevelPlayConfiguration configuration)
    {
        if (initialized) return;
        initialized = true;
        rewarded = new LevelPlayRewardedAd(settings.rewardedAdUnitId);
        rewarded.OnAdLoaded += info => { loadingRewarded = false; loadedAuction = info.AuctionId; Status = "Ad ready."; };
        rewarded.OnAdLoadFailed += error => { loadingRewarded = false; retryRewarded = Time.realtimeSinceStartup + 30; Status = "No ad available yet. Please try again shortly."; };
        rewarded.OnAdRewarded += GrantReward;
        rewarded.OnAdClosed += info => { EndAd(); LoadRewarded(); };
        rewarded.OnAdDisplayFailed += (info, error) =>
        {
            if (!string.IsNullOrEmpty(info?.AuctionId)) rewards.Remove(info.AuctionId);
            Status = "The ad could not play. Please try again.";
            EndAd(); LoadRewarded();
        };
        interstitial = new LevelPlayInterstitialAd(settings.interstitialAdUnitId);
        interstitial.OnAdLoaded += info => loadingInterstitial = false;
        interstitial.OnAdLoadFailed += error => { loadingInterstitial = false; retryInterstitial = Time.realtimeSinceStartup + 30; };
        interstitial.OnAdDisplayed += info => nextInterstitial = Time.realtimeSinceStartup + settings.interstitialIntervalSeconds;
        interstitial.OnAdClosed += info => FinishHomeAd();
        interstitial.OnAdDisplayFailed += (info, error) => FinishHomeAd();
        LoadRewarded(); LoadInterstitial();
    }

    private void LoadRewarded()
    {
        if (!initialized || loadingRewarded || rewarded.IsAdReady()) return;
        loadingRewarded = true; rewarded.LoadAd();
    }
    private void LoadInterstitial()
    {
        if (!initialized || loadingInterstitial || interstitial.IsAdReady()) return;
        loadingInterstitial = true; interstitial.LoadAd();
    }

    private void Update()
    {
        if (!initialized || showing) return;
        if (Time.realtimeSinceStartup >= retryRewarded) LoadRewarded();
        if (Time.realtimeSinceStartup >= retryInterstitial) LoadInterstitial();
        if (SceneManager.GetActiveScene().name != "Game" || !GameplayReady() ||
            GameplayModalInputGate.IsGameplayInputBlocked) return;
        cashPlaySeconds += Time.unscaledDeltaTime;
        if (cashPlaySeconds >= settings.cashOfferIntervalSeconds && RewardedReady)
        {
            if (AdOfferPopup.Show(false, CashOffer())) cashPlaySeconds = 0;
        }
    }

    internal static int CalculateCashReward(long total, int count, float multiplier, int minimum)
    {
        double average = count > 0 ? (double)total / count : minimum;
        return (int)Math.Min(1000000, Math.Max(minimum, Math.Ceiling(average * multiplier)));
    }

    private int CashOffer()
    {
        long total = 0; int count = 0;
        var orders = FindAnyObjectByType<OrderManager>();
        if (orders != null)
            foreach (var order in orders.CustomerOrders)
                if (order != null && order.IsValid) { total += order.CashReward; count++; }
        float progression = PlayerProgressionManager.Instance?.MoneyMultiplier ?? 1;
        return CalculateCashReward(total, count, settings.cashRewardMultiplier * progression, settings.minimumCashReward);
    }

    private static bool GameplayReady() => SaveManager.Instance != null &&
        SaveManager.Instance.IsLifecycleSavingReady && GameStartupCoordinator.Instance != null &&
        GameStartupCoordinator.Instance.IsGameplayReady && !SweetMerge.Cloud.SimpleCloudFiles.RestorePending;

    public bool ShowRewarded(bool energy, int amount)
    {
        if (!RewardedReady || !GameplayReady() || amount <= 0 ||
            string.IsNullOrEmpty(loadedAuction) || GameplayModalInputGate.IsGameplayInputBlocked) return false;
        if (!BeginAd()) return false;
        rewards[loadedAuction] = new RewardTicket(energy, amount);
        try { rewarded.ShowAd(settings.rewardedPlacement); return true; }
        catch (Exception exception)
        {
            rewards.Remove(loadedAuction); EndAd();
            Status = "The ad could not play. Please try again.";
            Debug.LogWarning("ADS | " + exception.Message); return false;
        }
    }

    private void GrantReward(LevelPlayAdInfo info, LevelPlayReward reward)
    {
        // Auction identity keeps a late reward from paying the next ad's offer.
        if (string.IsNullOrEmpty(info?.AuctionId) || !rewards.TryGetValue(info.AuctionId, out var ticket) ||
            !GameplayReady() || !ticket.TryClaim()) return;
        rewards.Remove(info.AuctionId);
        if (ticket.Energy) PlayerProgressionManager.Instance.AddRewardedEnergy(ticket.Amount);
        else EconomyManager.Instance.TryAddGameplayEarnings(ticket.Amount, out _);
        if (!SaveManager.Instance.SaveCurrentGame())
            Debug.LogWarning("ADS | Reward applied in memory; local save will retry through the normal save flow.");
    }

    private bool BeginAd()
    {
        if (showing || !GameplayModalInputGate.TryAcquireBlockingModal(this, out adLease)) return false;
        if (!GameplayModalInputGate.IsSafeToOpen(adLease)) { adLease.Dispose(); adLease = null; return false; }
        showing = true;
        return true;
    }
    private void EndAd() { showing = false; adLease?.Dispose(); adLease = null; }

    public void ReturnHome(Action navigate) => StartCoroutine(HomeAd(navigate));
    private IEnumerator HomeAd(Action navigate)
    {
        yield return null; // Finish the Home button's save/departure operation first.
        if (!initialized || showing || Time.realtimeSinceStartup < nextInterstitial ||
            interstitial == null || !interstitial.IsAdReady() || !BeginAd())
        { navigate(); yield break; }
        afterInterstitial = navigate;
        try { interstitial.ShowAd(settings.interstitialPlacement); }
        catch (Exception exception) { Debug.LogWarning("ADS | " + exception.Message); FinishHomeAd(); }
    }
    private void FinishHomeAd()
    {
        EndAd();
        var navigate = afterInterstitial; afterInterstitial = null;
        LoadInterstitial(); navigate?.Invoke();
    }
    private void OnDestroy()
    {
        if (Instance != this) return;
        LevelPlay.OnInitSuccess -= OnInitialized;
        LevelPlay.OnInitFailed -= OnInitFailed;
        rewarded?.DestroyAd(); interstitial?.DestroyAd();
        EndAd(); Instance = null;
    }
}
