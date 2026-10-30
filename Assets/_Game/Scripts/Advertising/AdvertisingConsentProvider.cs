using System;
using UnityEngine;

namespace SweetMerge.Advertising
{
    public enum AdvertisingConsentState
    {
        Unresolved,
        Permitted,
        Restricted,
        Withdrawn
    }

    // Future CMP integrations implement this contract by applying verified SDK
    // privacy signals before exposing a permitted state.
    public interface IAdvertisingConsentSource
    {
        AdvertisingConsentState ConsentState { get; }
        bool IsPrivacyConfigurationApplied { get; }
        string AdvertisingBlockingReason { get; }
    }

    // Contract for a reviewed privacy implementation, not a consent UI or an SDK initializer.
    // Apply required SDK privacy signals BEFORE allowing ads and publishing true.
    // Publish false synchronously on withdrawal/invalidation; fail closed on errors.
    // Providers must report false while disabled and must never initialize the SDK.
    public abstract class AdvertisingConsentProvider : MonoBehaviour, IAdvertisingConsentSource
    {
        public event Action<bool> AdvertisingPrivacyChanged;
        public abstract bool IsAdvertisingAllowed { get; }
        public abstract bool IsDevelopmentOnly { get; }
        public abstract AdvertisingConsentState ConsentState { get; }
        public abstract bool IsPrivacyConfigurationApplied { get; }
        public abstract string AdvertisingBlockingReason { get; }
        protected void NotifyAdvertisingPrivacyChanged(bool allowed) =>
            AdvertisingPrivacyChanged?.Invoke(allowed);
    }
}
