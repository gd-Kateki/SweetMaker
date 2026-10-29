using System;
using System.Threading.Tasks;
using Unity.Services.Core;
using Unity.Services.Core.Environments;
using UnityEngine;
using UnityEngine.UnityConsent;

namespace SweetMerge.Analytics
{
    public interface IAnalyticsConsentProvider
    {
        ConsentStatus AnalyticsConsent { get; }
        event Action<ConsentStatus> AnalyticsConsentChanged;

        void SetAnalyticsConsent(bool isGranted);
    }

    internal interface IAnalyticsBootstrapRuntime
    {
        string ApplicationIdentifier { get; }
        ServicesInitializationState ServicesState { get; }
        event Action<ConsentState> ConsentStateChanged;

        ConsentState GetConsentState();
        void SetConsentState(ConsentState consentState);
        Task InitializeServicesAsync(string environmentName);
    }

    internal sealed class AnalyticsBootstrapCoordinator : IDisposable
    {
        internal const string DevelopmentApplicationIdentifier =
            "com.offcutstudios.dessertmergecafe.dev";
        internal const string ProductionApplicationIdentifier =
            "com.offcutstudios.dessertmergecafe";

        private readonly IAnalyticsBootstrapRuntime runtime;
        private readonly Action<string> logWarning;
        private bool started;
        private bool disposed;
        private bool initializationAttempted;
        private bool initializationSucceeded;
        private Task initializationTask;

        internal bool IsAnalyticsReady =>
            initializationSucceeded &&
            !disposed &&
            runtime.GetConsentState().AnalyticsIntent == ConsentStatus.Granted;

        internal AnalyticsBootstrapCoordinator(
            IAnalyticsBootstrapRuntime runtime,
            Action<string> logWarning)
        {
            this.runtime = runtime ??
                throw new ArgumentNullException(nameof(runtime));
            this.logWarning = logWarning ??
                throw new ArgumentNullException(nameof(logWarning));
        }

        internal void Start()
        {
            if (started || disposed)
                return;

            started = true;
            runtime.ConsentStateChanged += HandleConsentStateChanged;
            _ = TryInitializeIfAuthorizedAsync();
        }

        internal Task TryInitializeIfAuthorizedAsync()
        {
            if (initializationAttempted || disposed)
                return initializationTask ?? Task.CompletedTask;

            if (runtime.GetConsentState().AnalyticsIntent != ConsentStatus.Granted)
                return Task.CompletedTask;

            initializationAttempted = true;
            if (!TryResolveEnvironment(
                    runtime.ApplicationIdentifier,
                    out string environmentName))
            {
                logWarning(
                    "Analytics bootstrap skipped: unsupported application identifier.");
                return Task.CompletedTask;
            }

            if (runtime.ServicesState != ServicesInitializationState.Uninitialized)
            {
                logWarning(
                    "Analytics bootstrap skipped: Unity Services already has an initialization owner.");
                return Task.CompletedTask;
            }

            initializationTask = InitializeAndObserveAsync(environmentName);
            return initializationTask;
        }

        internal void WithdrawAnalyticsConsent()
        {
            SetAnalyticsConsent(false);
        }

        internal void SetAnalyticsConsent(bool isGranted)
        {
            if (disposed)
                return;

            ConsentState consentState = runtime.GetConsentState();
            ConsentStatus requestedState = isGranted
                ? ConsentStatus.Granted
                : ConsentStatus.Denied;
            if (consentState.AnalyticsIntent == requestedState)
                return;

            consentState.AnalyticsIntent = requestedState;
            runtime.SetConsentState(consentState);
        }

        public void Dispose()
        {
            if (disposed)
                return;

            disposed = true;
            if (started)
                runtime.ConsentStateChanged -= HandleConsentStateChanged;
        }

        internal static bool TryResolveEnvironment(
            string applicationIdentifier,
            out string environmentName)
        {
            switch (applicationIdentifier)
            {
                case DevelopmentApplicationIdentifier:
                    environmentName = "development";
                    return true;
                case ProductionApplicationIdentifier:
                    environmentName = "production";
                    return true;
                default:
                    environmentName = null;
                    return false;
            }
        }

        private async Task InitializeAndObserveAsync(string environmentName)
        {
            try
            {
                await runtime.InitializeServicesAsync(environmentName);
                initializationSucceeded = true;
            }
            catch (Exception)
            {
                logWarning(
                    "Analytics initialization failed; gameplay will continue without Analytics.");
            }
        }

        private void HandleConsentStateChanged(ConsentState consentState)
        {
            if (consentState.AnalyticsIntent == ConsentStatus.Granted)
                _ = TryInitializeIfAuthorizedAsync();
        }
    }

    [DefaultExecutionOrder(-10000)]
    public sealed class AnalyticsBootstrap : MonoBehaviour,
        IAnalyticsConsentProvider
    {
        private sealed class UnityAnalyticsBootstrapRuntime :
            IAnalyticsBootstrapRuntime
        {
            public string ApplicationIdentifier => Application.identifier;

            public ServicesInitializationState ServicesState =>
                UnityServices.State;

            public event Action<ConsentState> ConsentStateChanged
            {
                add { EndUserConsent.consentStateChanged += value; }
                remove { EndUserConsent.consentStateChanged -= value; }
            }

            public ConsentState GetConsentState() =>
                EndUserConsent.GetConsentState();

            public void SetConsentState(ConsentState consentState) =>
                EndUserConsent.SetConsentState(consentState);

            public Task InitializeServicesAsync(string environmentName)
            {
                var options = new InitializationOptions()
                    .SetEnvironmentName(environmentName);
                return UnityServices.InitializeAsync(options);
            }
        }

        private static AnalyticsBootstrap instance;
        private AnalyticsBootstrapCoordinator coordinator;
        private IAnalyticsBootstrapRuntime runtime;

        public static AnalyticsBootstrap Instance => instance;

        public ConsentStatus AnalyticsConsent =>
            EndUserConsent.GetConsentState().AnalyticsIntent;

        public event Action<ConsentStatus> AnalyticsConsentChanged;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        private static void ResetStaticState()
        {
            instance = null;
        }

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
        private static void InstallBeforeSceneLoad()
        {
            if (instance != null)
                return;

            instance = FindAnyObjectByType<AnalyticsBootstrap>();
            if (instance != null)
                return;

            var bootstrapObject = new GameObject(nameof(AnalyticsBootstrap));
            bootstrapObject.AddComponent<AnalyticsBootstrap>();
        }

        private void Awake()
        {
            if (instance != null && instance != this)
            {
                Destroy(gameObject);
                return;
            }

            instance = this;
            DontDestroyOnLoad(gameObject);
            runtime = new UnityAnalyticsBootstrapRuntime();
            runtime.ConsentStateChanged += HandleConsentStateChanged;
            coordinator = new AnalyticsBootstrapCoordinator(
                runtime,
                Debug.LogWarning);
            coordinator.Start();
        }

        private void OnDestroy()
        {
            if (runtime != null)
                runtime.ConsentStateChanged -= HandleConsentStateChanged;
            coordinator?.Dispose();
            if (instance == this)
                instance = null;
        }

        public void SetAnalyticsConsent(bool isGranted)
        {
            coordinator?.SetAnalyticsConsent(isGranted);
        }

        public void WithdrawAnalyticsConsent()
        {
            coordinator?.WithdrawAnalyticsConsent();
        }

        private void HandleConsentStateChanged(ConsentState consentState)
        {
            AnalyticsConsentChanged?.Invoke(consentState.AnalyticsIntent);
        }
    }
}
