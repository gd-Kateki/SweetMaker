using System.Collections.Generic;
using System.Threading.Tasks;
using Unity.Services.Authentication.Internal;
using Unity.Services.CloudCode.Internal;
using Unity.Services.CloudCode.Internal.Apis.CloudCode;
using Unity.Services.CloudCode.Internal.Http;
using Unity.Services.Core.Configuration.Internal;
using Unity.Services.Core.Device.Internal;
using Unity.Services.Core.Internal;
using Unity.Services.Wire.Internal;
using UnityEngine;

#if UNITY_EDITOR
using UnityEditor;
#endif

namespace Unity.Services.CloudCode
{
    class CloudCodeInitializer : IInitializablePackageV2
    {
        const string k_CloudEnvironmentKey = "com.unity.services.core.cloud-environment";
        const string k_StagingEnvironment = "staging";
        internal const ushort k_DefaultLocalCloudCodeServerPort = 5000;
        const string k_LocalCloudCodePidPrefs = "LOCAL_CLOUD_CODE_PID";
        const int k_ConfigurationReqTimeoutSec = 30;
        const string k_PackageName = "com.unity.services.cloudcode";

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
        static void InitializeOnLoad()
        {
            // Ensure Instance is reset to account for Fast Enter Play Mode
            CloudCodeService.Instance = null;
            var initializer = new CloudCodeInitializer();
            initializer.Register(CorePackageRegistry.Instance);
        }

        public void Register(CorePackageRegistry registry)
        {
            registry.Register(this)
                .DependsOn<ICloudProjectId>()
                .DependsOn<IPlayerId>()
                .DependsOn<IAccessToken>()
                .DependsOn<IInstallationId>()
                .DependsOn<IProjectConfiguration>()
                .DependsOn<IExternalUserId>()
                .OptionallyDependsOn<IWire>();
        }

        public Task Initialize(CoreRegistry registry)
        {
            CloudCodeService.Instance = InitializeService(registry);
            return Task.CompletedTask;
        }

        public Task InitializeInstanceAsync(CoreRegistry registry)
        {
            _ = InitializeService(registry);
            return Task.CompletedTask;
        }

        static ICloudCodeService InitializeService(CoreRegistry registry)
        {
            var cloudProjectId = registry.GetServiceComponent<ICloudProjectId>();
            var accessToken = registry.GetServiceComponent<IAccessToken>();
            var playerId = registry.GetServiceComponent<IPlayerId>();
            var installationId = registry.GetServiceComponent<IInstallationId>();
            var projectConfiguration = registry.GetServiceComponent<IProjectConfiguration>();
            var externalUserId = registry.GetServiceComponent<IExternalUserId>();
            var wire = registry.GetServiceComponent<IWire>();

            var configuration = new Configuration(GetHost(projectConfiguration), k_ConfigurationReqTimeoutSec, null, GetServiceHeaders(installationId, externalUserId));
            var packageVersion = projectConfiguration.GetString($"{k_PackageName}.version", "unknown");
            configuration.Headers["User-Agent"] = BuildUserAgent(k_PackageName, packageVersion);
            externalUserId.UserIdChanged += id => UpdateExternalUserId(configuration, id);

            ICloudCodeApiClient cloudCodeApiClient = new CloudCodeApiClient(
                new HttpClient(),
                accessToken,
                configuration);

            var service = new CloudCodeInternal(wire, cloudProjectId, cloudCodeApiClient, playerId, accessToken);
            registry.RegisterService<ICloudCodeService>(service);
            return service;
        }

        static Dictionary<string, string> GetServiceHeaders(IInstallationId installationIdProvider, IExternalUserId externalUserId)
        {
            var headers = new Dictionary<string, string>();

            var installationId = installationIdProvider.GetOrCreateIdentifier();
            var analyticsUserId = externalUserId.UserId;

            headers.Add("unity-installation-id", installationId);

            if (!string.IsNullOrEmpty(analyticsUserId))
            {
                headers.Add("analytics-user-id", analyticsUserId);
            }

            return headers;
        }

        static void UpdateExternalUserId(Configuration configuration, string userId)
        {
            if (string.IsNullOrEmpty(userId))
            {
                configuration.Headers.Remove("analytics-user-id");
            }
            else
            {
                configuration.Headers["analytics-user-id"] = userId;
            }
        }

        static int? GetTimeout()
        {
#if UNITY_EDITOR
            var cloudCodePid = EditorPrefs.GetInt(k_LocalCloudCodePidPrefs, -1);
            if (cloudCodePid != -1)
            {
                // For local Cloud Code debugging, override and ensure UnityWebRequest do not time out.
                return 0;
            }
#endif
            // Provide overrides for remote Cloud Code
            return k_ConfigurationReqTimeoutSec;
        }

        static string GetHost(IProjectConfiguration projectConfiguration)
        {
#if UNITY_EDITOR
            var cloudCodePid = EditorPrefs.GetInt(k_LocalCloudCodePidPrefs, -1);
            var cloudCodePort = EditorPrefs.GetInt("CLOUD_CODE_DEBUG_PORT", k_DefaultLocalCloudCodeServerPort);
            if (cloudCodePid != -1)
            {
                return "http://localhost:" + cloudCodePort;
            }
#endif
            var cloudEnvironment = projectConfiguration?.GetString(k_CloudEnvironmentKey);

            switch (cloudEnvironment)
            {
                case k_StagingEnvironment:
                    return "https://cloud-code-stg.services.api.unity.com";
                default:
                    return "https://cloud-code.services.api.unity.com";
            }
        }

        internal static string BuildUserAgent(string packageName, string packageVersion)
        {
            return $"UnityPlayer/{Application.unityVersion} ({packageName}/{packageVersion})";
        }
    }
}
