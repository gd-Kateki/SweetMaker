#if !UNITY_2023_2_OR_NEWER
using Unity.Services.CloudCode.Editor.Shared.EditorUtils;
using Unity.Services.CloudCode.Editor.Shared.Logging;
using UnityEditor;
#endif

namespace Unity.Services.CloudCode.Authoring.Editor.Analytics
{
    static class AnalyticsUtils
    {
        // On Unity 2023.2+ events self-register via the [AnalyticInfo] attribute on the
        // IAnalytic implementations, so explicit registration is only needed on older editors.
        public static void RegisterEventDefault(string eventName, int version = 1)
        {
#if !UNITY_2023_2_OR_NEWER
            Sync.RunNextUpdateOnMain(() =>
            {
                var result = EditorAnalytics.RegisterEventWithLimit(
                    eventName,
                    AnalyticsConstants.k_MaxEventPerHour,
                    AnalyticsConstants.k_MaxItems,
                    AnalyticsConstants.k_VendorKey,
                    version);

                Logger.LogVerbose($"Registered Analytics Event: {eventName}.v{version}. Result: {result}");
            });
#endif
        }
    }
}
