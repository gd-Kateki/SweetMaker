using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using NUnit.Framework;
using Unity.Services.Core;
using UnityEngine.UnityConsent;

namespace SweetMerge.Analytics.Tests
{
    public sealed class UnityServicesInitializationCoordinatorTests
    {
        private sealed class FakeServicesRuntime :
            IUnityServicesInitializationRuntime
        {
            public string ApplicationIdentifier { get; set; }
            public ServicesInitializationState ServicesState { get; set; }
            public Task InitializationTask { get; set; } = Task.CompletedTask;
            public int InitializationCount { get; private set; }
            public string InitializedEnvironment { get; private set; }

            public async Task InitializeServicesAsync(string environmentName)
            {
                InitializationCount++;
                InitializedEnvironment = environmentName;
                await InitializationTask;
                ServicesState = ServicesInitializationState.Initialized;
            }
        }

        private sealed class FakeAnalyticsRuntime : IAnalyticsBootstrapRuntime
        {
            public ConsentState ConsentState { get; set; }

            public event Action<ConsentState> ConsentStateChanged;

            public ConsentState GetConsentState() => ConsentState;

            public void SetConsentState(ConsentState consentState)
            {
                ConsentState = consentState;
                ConsentStateChanged?.Invoke(consentState);
            }
        }

        private readonly List<string> warnings = new List<string>();
        private FakeServicesRuntime runtime;

        [SetUp]
        public void ClearWarnings()
        {
            warnings.Clear();
        }

        [TestCase(
            UnityServicesInitializationCoordinator.DevelopmentApplicationIdentifier,
            "development")]
        [TestCase(
            UnityServicesInitializationCoordinator.ProductionApplicationIdentifier,
            "production")]
        public async Task InitializesInExactResolvedEnvironment(
            string applicationIdentifier,
            string expectedEnvironment)
        {
            UnityServicesInitializationCoordinator coordinator =
                CreateCoordinator(applicationIdentifier);

            await coordinator.RequestInitializationAsync();

            Assert.AreEqual(1, runtime.InitializationCount);
            Assert.AreEqual(expectedEnvironment, runtime.InitializedEnvironment);
            Assert.AreEqual(
                ServicesInitializationState.Initialized,
                runtime.ServicesState);
        }

        [TestCase(null)]
        [TestCase("")]
        [TestCase("com.offcutstudios.dessertmergecafe.qa")]
        public void UnknownApplicationIdentifierFailsClosed(
            string applicationIdentifier)
        {
            UnityServicesInitializationCoordinator coordinator =
                CreateCoordinator(applicationIdentifier);

            Assert.ThrowsAsync<InvalidOperationException>(
                async () => await coordinator.RequestInitializationAsync());

            Assert.AreEqual(0, runtime.InitializationCount);
            Assert.AreEqual(1, warnings.Count);
            StringAssert.Contains(
                "unsupported application identifier",
                warnings[0]);
        }

        [Test]
        public async Task ConcurrentRequestsShareOneInitializationTask()
        {
            var completion = new TaskCompletionSource<bool>(
                TaskCreationOptions.RunContinuationsAsynchronously);
            UnityServicesInitializationCoordinator coordinator =
                CreateCoordinator();
            runtime.InitializationTask = completion.Task;

            Task first = coordinator.RequestInitializationAsync();
            Task second = coordinator.RequestInitializationAsync();

            Assert.AreSame(first, second);
            Assert.AreEqual(1, runtime.InitializationCount);

            completion.SetResult(true);
            await Task.WhenAll(first, second);
            Assert.AreEqual(1, runtime.InitializationCount);
        }

        [Test]
        public async Task InitializationFailureCanBeRetriedAfterCoreResets()
        {
            UnityServicesInitializationCoordinator coordinator =
                CreateCoordinator();
            runtime.InitializationTask = Task.FromException(
                new InvalidOperationException("initialization failure"));

            Assert.ThrowsAsync<InvalidOperationException>(
                async () => await coordinator.RequestInitializationAsync());
            Assert.AreEqual(
                ServicesInitializationState.Uninitialized,
                runtime.ServicesState);

            runtime.InitializationTask = Task.CompletedTask;
            await coordinator.RequestInitializationAsync();

            Assert.AreEqual(2, runtime.InitializationCount);
            Assert.AreEqual(
                ServicesInitializationState.Initialized,
                runtime.ServicesState);
        }

        [TestCase(ServicesInitializationState.Initializing)]
        [TestCase(ServicesInitializationState.Initialized)]
        public void ExistingExternalInitializationFailsClosed(
            ServicesInitializationState state)
        {
            UnityServicesInitializationCoordinator coordinator =
                CreateCoordinator();
            runtime.ServicesState = state;

            Assert.ThrowsAsync<InvalidOperationException>(
                async () => await coordinator.RequestInitializationAsync());

            Assert.AreEqual(0, runtime.InitializationCount);
            Assert.AreEqual(1, warnings.Count);
        }

        [Test]
        public async Task AuthenticationStyleRequestDoesNotGrantAnalyticsConsent()
        {
            UnityServicesInitializationCoordinator servicesInitializer =
                CreateCoordinator();
            var analyticsRuntime = new FakeAnalyticsRuntime
            {
                ConsentState = new ConsentState
                {
                    AnalyticsIntent = ConsentStatus.Denied,
                    AdsIntent = ConsentStatus.Unspecified
                }
            };
            using (var analytics = new AnalyticsBootstrapCoordinator(
                       analyticsRuntime,
                       servicesInitializer,
                       warnings.Add))
            {
                analytics.Start();
                await servicesInitializer.RequestInitializationAsync();

                Assert.AreEqual(1, runtime.InitializationCount);
                Assert.AreEqual(
                    ConsentStatus.Denied,
                    analyticsRuntime.ConsentState.AnalyticsIntent);
                Assert.IsFalse(analytics.IsAnalyticsReady);
            }
        }

        private UnityServicesInitializationCoordinator CreateCoordinator(
            string applicationIdentifier =
                UnityServicesInitializationCoordinator.DevelopmentApplicationIdentifier)
        {
            runtime = new FakeServicesRuntime
            {
                ApplicationIdentifier = applicationIdentifier,
                ServicesState = ServicesInitializationState.Uninitialized
            };
            return new UnityServicesInitializationCoordinator(
                runtime,
                warnings.Add);
        }
    }
}
