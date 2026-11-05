using UnityEngine;

[CreateAssetMenu(menuName = "Sweet Merge/Ads Settings")]
public sealed class SimpleAdsSettings : ScriptableObject
{
    public string androidAppKey = "29245cbbd";
    public string rewardedAdUnitId = "hg0kom1zfpm0no12";
    public string interstitialAdUnitId = "4gx9bo96ocyr4hiz";
    public string rewardedPlacement = "BP_Rewarded_Android";
    public string interstitialPlacement = "BP_Interstitial_Android";
    [Min(30)] public float interstitialIntervalSeconds = 300;
    [Min(30)] public float cashOfferIntervalSeconds = 300;
    [Min(0.1f)] public float cashRewardMultiplier = 1;
    [Min(1)] public int minimumCashReward = 100;
}
