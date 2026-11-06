#if UNITY_EDITOR
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEngine;

// The SDK's optional automatic initializer would bypass the game's age/privacy flow.
internal sealed class AdvertisingPrivacyBuildGuard : IPreprocessBuildWithReport
{
    public int callbackOrder => -100;
    public void OnPreprocessBuild(BuildReport report)
    {
        var settings = Resources.Load<LevelPlayMediationSettings>("LevelPlayMediationSettings");
        if (settings != null && (settings.EnableIronsourceSDKInitAPI || settings.EnableIntegrationHelper))
            throw new BuildFailedException("Disable LevelPlay automatic SDK initialization and Integration Helper in Ads Mediation settings. SimpleAdManager must initialize ads after the player's age/privacy choice.");
    }
}
#endif
