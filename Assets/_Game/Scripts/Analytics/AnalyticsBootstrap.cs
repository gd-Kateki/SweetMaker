using System;
using System.Threading.Tasks;
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
        event Action<ConsentState> ConsentStateChanged;

        ConsentState GetConsentState();
        void SetConsentState(ConsentState consentState);
    }

    internal sealed class AnalyticsBootstrapCoordinator : IDisposable
    {
        private readonly IAnalyticsBootstrapRuntime runtime;
        private readonly UnityServicesInitializationCoordinator servicesInitializer;
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
            UnityServicesInitializationCoordinator servicesInitializer,
            Action<string> logWarning)
        {
            this.runtime = runtime ??
                throw new ArgumentNullException(nameof(runtime));
            this.servicesInitializer = servicesInitializer ??
                throw new ArgumentNullException(nameof(servicesInitializer));
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
            initializationTask = InitializeAndObserveAsync();
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

        private async Task InitializeAndObserveAsync()
        {
            try
            {
                await servicesInitializer.RequestInitializationAsync();
                initializationSucceeded = true;
            }
            catch (Exception exception)
            {
                logWarning(
                    "Analytics initialization failed; gameplay will continue without Analytics. " +
                    exception.Message);
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
            public event Action<ConsentState> ConsentStateChanged
            {
                add { EndUserConsent.consentStateChanged += value; }
                remove { EndUserConsent.consentStateChanged -= value; }
            }

            public ConsentState GetConsentState() =>
                EndUserConsent.GetConsentState();

            public void SetConsentState(ConsentState consentState) =>
                EndUserConsent.SetConsentState(consentState);
        }

        private static AnalyticsBootstrap instance;
        private AnalyticsBootstrapCoordinator coordinator;
        private IAnalyticsBootstrapRuntime runtime;

        public static AnalyticsBootstrap Instance => instance;
        public static bool StartupPrivacyPromptSuppressed { get; set; }

        public ConsentStatus AnalyticsConsent =>
            EndUserConsent.GetConsentState().AnalyticsIntent;

        public event Action<ConsentStatus> AnalyticsConsentChanged;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        private static void ResetStaticState()
        {
            instance = null;
            StartupPrivacyPromptSuppressed = false;
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
                UnityServicesInitializationCoordinator.Shared,
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
