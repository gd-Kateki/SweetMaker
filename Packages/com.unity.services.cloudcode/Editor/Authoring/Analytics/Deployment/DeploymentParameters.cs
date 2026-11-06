using System;
#if UNITY_2023_2_OR_NEWER
using UnityEngine.Analytics;
#endif

namespace Unity.Services.CloudCode.Authoring.Editor.Analytics.Deployment
{
    // Lowercase to match the naming schema
    [Serializable]
    struct DeploymentParameters
#if UNITY_2023_2_OR_NEWER
        : IAnalytic.IData
#endif
    {
        public string origin;
        public string environment;
        public string status;
        public string exception;
        public float duration;
        public int size;
        public string fileType;
    }
}
