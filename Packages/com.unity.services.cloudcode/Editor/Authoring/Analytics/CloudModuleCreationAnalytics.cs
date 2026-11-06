using UnityEditor;
#if UNITY_2023_2_OR_NEWER
using System;
using UnityEngine.Analytics;
#endif

namespace Unity.Services.CloudCode.Authoring.Editor.Analytics
{
    class CloudModuleCreationAnalytics
    {
        const string k_EventNameReferenceCreate = "cloudcode_referencecreated";
        const string k_EventNameCloudCodeModuleCreate = "cloudcode_nativemodulecreated";
        const string k_EventNameCloudCodeScriptAdded = "cloudcode_nativescriptadded";
        const int k_VersionCreate = 1;

        public CloudModuleCreationAnalytics()
        {
#if !UNITY_2023_2_OR_NEWER
            EditorAnalytics.RegisterEventWithLimit(k_EventNameReferenceCreate, AnalyticsConstants.k_MaxEventPerHour, AnalyticsConstants.k_MaxItems, AnalyticsConstants.k_VendorKey, k_VersionCreate);
            EditorAnalytics.RegisterEventWithLimit(k_EventNameCloudCodeModuleCreate, AnalyticsConstants.k_MaxEventPerHour, AnalyticsConstants.k_MaxItems, AnalyticsConstants.k_VendorKey, k_VersionCreate);
            EditorAnalytics.RegisterEventWithLimit(k_EventNameCloudCodeScriptAdded, AnalyticsConstants.k_MaxEventPerHour, AnalyticsConstants.k_MaxItems, AnalyticsConstants.k_VendorKey, k_VersionCreate);
#endif
        }

        public void SendReferenceCreatedEvent()
        {
#if UNITY_2023_2_OR_NEWER
            EditorAnalytics.SendAnalytic(new ReferenceCreatedAnalytic());
#else
            EditorAnalytics.SendEventWithLimit(k_EventNameReferenceCreate, null, k_VersionCreate);
#endif
        }

        public void SendCloudCodeModuleCreatedEvent()
        {
#if UNITY_2023_2_OR_NEWER
            EditorAnalytics.SendAnalytic(new CloudCodeModuleCreatedAnalytic());
#else
            EditorAnalytics.SendEventWithLimit(k_EventNameCloudCodeModuleCreate, null, k_VersionCreate);
#endif
        }

        public void SendCloudCodeScriptAddedEvent()
        {
#if UNITY_2023_2_OR_NEWER
            EditorAnalytics.SendAnalytic(new CloudCodeScriptAddedAnalytic());
#else
            EditorAnalytics.SendEventWithLimit(k_EventNameCloudCodeScriptAdded, null, k_VersionCreate);
#endif
        }

#if UNITY_2023_2_OR_NEWER
        [AnalyticInfo(
            eventName: k_EventNameReferenceCreate,
            vendorKey: AnalyticsConstants.k_VendorKey,
            version: k_VersionCreate)]
        class ReferenceCreatedAnalytic : IAnalytic
        {
            public bool TryGatherData(out IAnalytic.IData data, out Exception error)
            {
                error = null;
                data = null;
                return true;
            }
        }

        [AnalyticInfo(
            eventName: k_EventNameCloudCodeModuleCreate,
            vendorKey: AnalyticsConstants.k_VendorKey,
            version: k_VersionCreate)]
        class CloudCodeModuleCreatedAnalytic : IAnalytic
        {
            public bool TryGatherData(out IAnalytic.IData data, out Exception error)
            {
                error = null;
                data = null;
                return true;
            }
        }

        [AnalyticInfo(
            eventName: k_EventNameCloudCodeScriptAdded,
            vendorKey: AnalyticsConstants.k_VendorKey,
            version: k_VersionCreate)]
        class CloudCodeScriptAddedAnalytic : IAnalytic
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
