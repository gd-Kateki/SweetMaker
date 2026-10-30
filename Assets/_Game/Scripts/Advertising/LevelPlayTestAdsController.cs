using UnityEngine;

namespace SweetMerge.Advertising
{
    [DisallowMultipleComponent]
    [RequireComponent(typeof(LevelPlayAdService))]
    public sealed class LevelPlayTestAdsController : MonoBehaviour
    {
        // Compatibility entry points for manual DEV callers. Scene consumers use the service.
        private LevelPlayAdService Service
        {
            get
            {
#if UNITY_ANDROID && DEVELOPMENT_BUILD && !UNITY_EDITOR
                return isActiveAndEnabled ? GetComponent<LevelPlayAdService>() : null;
#else
                return null;
#endif
            }
        }
        public void Initialize() => Service?.Initialize();
        public void LoadInterstitial() => Service?.LoadInterstitial();
        public void ShowInterstitial() => Service?.ShowInterstitial();
        public void LoadRewarded() => Service?.LoadRewarded();
        public void ShowRewarded() => Service?.ShowRewarded();
    }
}
