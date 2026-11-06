using UnityEditor;
#if UNITY_2023_2_OR_NEWER
using System;
using UnityEngine.Analytics;
#endif

namespace Unity.Services.CloudCode.Authoring.Editor.Analytics
{
    class CloudScriptCreationAnalytics
    {
        const string k_EventNameCreate = "cloudcode_filecreated";
        const int k_VersionCreate = 1;

        public CloudScriptCreationAnalytics()
        {
#if !UNITY_2023_2_OR_NEWER
            EditorAnalytics.RegisterEventWithLimit(k_EventNameCreate, AnalyticsConstants.k_MaxEventPerHour, AnalyticsConstants.k_MaxItems, AnalyticsConstants.k_VendorKey, k_VersionCreate);
#endif
        }

        public void SendCreatedEvent()
        {
#if UNITY_2023_2_OR_NEWER
            EditorAnalytics.SendAnalytic(new CloudScriptCreatedAnalytic());
#else
            EditorAnalytics.SendEventWithLimit(k_EventNameCreate, null, k_VersionCreate);
#endif
        }

#if UNITY_2023_2_OR_NEWER
        [AnalyticInfo(
            eventName: k_EventNameCreate,
            vendorKey: AnalyticsConstants.k_VendorKey,
            version: k_VersionCreate)]
        class CloudScriptCreatedAnalytic : IAnalytic
        {
            public bool TryGatherData(out IAnalytic.IData data, out Exception error)
            {
                error = null;
                data = null;
                return true;
            }
        }
#endif
    }
}
