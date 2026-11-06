using System;
#if UNITY_2023_2_OR_NEWER
using UnityEngine.Analytics;
#endif

namespace Unity.Services.CloudCode.Authoring.Editor.Analytics.Deployment
{
    [Serializable]
    struct PublishParameters
#if UNITY_2023_2_OR_NEWER
        : IAnalytic.IData
#endif
    {
        public string origin;
        public string environment;
        public string status;
        public string exception;
    }
}
