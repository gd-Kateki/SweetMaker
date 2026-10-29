using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Threading.Tasks;
using NUnit.Framework;
using Unity.Services.Core;
using UnityEngine.UnityConsent;

namespace SweetMerge.Analytics.Tests
{
    public sealed class AnalyticsBootstrapTests
    {
        private sealed class FakeRuntime : IAnalyticsBootstrapRuntime
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

        private sealed class FakeServicesRuntime :
            IUnityServicesInitializationRuntime
        {
            public string ApplicationIdentifier { get; set; }
            public ServicesInitializationState ServicesState { get; set; }
            public Task InitializationTask { get; set; } = Task.CompletedTask;
            public int InitializationCount { get; private set; }
            public string InitializedEnvironment { get; private set; }

            public Task InitializeServicesAsync(string environmentName)
            {
                InitializationCount++;
                InitializedEnvironment = environmentName;
                if (InitializationTask.Status == TaskStatus.RanToCompletion)
                    ServicesState = ServicesInitializationState.Initialized;
                return InitializationTask;
            }
        }

        private readonly List<string> warnings = new List<string>();
        private FakeServicesRuntime servicesRuntime;

        [SetUp]
        public void ClearWarnings()
        {
            warnings.Clear();
        }

        [Test]
        public async Task UnspecifiedConsentDoesNotInitializeOrChangeConsent()
        {
            var runtime = CreateRuntime(ConsentStatus.Unspecified);
            using (var coordinator = CreateCoordinator(runtime))
            {
                coordinator.Start();
                await coordinator.TryInitializeIfAuthorizedAsync();

                Assert.AreEqual(0, servicesRuntime.InitializationCount);
                Assert.AreEqual(
                    ConsentStatus.Unspecified,
                    runtime.ConsentState.AnalyticsIntent);
            }
        }

        [Test]
        public async Task DeniedConsentDoesNotInitializeOrChangeConsent()
        {
            var runtime = CreateRuntime(ConsentStatus.Denied);
            using (var coordinator = CreateCoordinator(runtime))
            {
                coordinator.Start();
                await coordinator.TryInitializeIfAuthorizedAsync();

                Assert.AreEqual(0, servicesRuntime.InitializationCount);
                Assert.AreEqual(ConsentStatus.Denied, runtime.ConsentState.AnalyticsIntent);
            }
        }

        [Test]
        public async Task GrantingConsentAfterStartupInitializesOnce()
        {
            var runtime = CreateRuntime(ConsentStatus.Unspecified);
            using (var coordinator = CreateCoordinator(runtime))
            {
                coordinator.Start();
                runtime.SetConsentState(CreateConsentState(ConsentStatus.Granted));
                await coordinator.TryInitializeIfAuthorizedAsync();

                Assert.AreEqual(1, servicesRuntime.InitializationCount);
                Assert.AreEqual(
                    "development",
                    servicesRuntime.InitializedEnvironment);
            }
        }

        [TestCase(
            UnityServicesInitializationCoordinator.DevelopmentApplicationIdentifier,
            "development")]
        [TestCase(
            UnityServicesInitializationCoordinator.ProductionApplicationIdentifier,
            "production")]
        public async Task GrantedConsentInitializesInResolvedEnvironment(
            string applicationIdentifier,
            string expectedEnvironment)
        {
            var runtime = CreateRuntime(ConsentStatus.Granted);
            using (var coordinator = CreateCoordinator(
                       runtime,
                       applicationIdentifier))
            {
                coordinator.Start();
                await coordinator.TryInitializeIfAuthorizedAsync();

                Assert.AreEqual(1, servicesRuntime.InitializationCount);
                Assert.AreEqual(
                    expectedEnvironment,
                    servicesRuntime.InitializedEnvironment);
                Assert.IsTrue(coordinator.IsAnalyticsReady);
            }
        }

        [TestCase(
            UnityServicesInitializationCoordinator.DevelopmentApplicationIdentifier,
            "development")]
        [TestCase(
            UnityServicesInitializationCoordinator.ProductionApplicationIdentifier,
            "production")]
        public void KnownApplicationIdentifiersResolveToExactEnvironment(
            string applicationIdentifier,
            string expectedEnvironment)
        {
            bool resolved =
                UnityServicesInitializationCoordinator.TryResolveEnvironment(
                applicationIdentifier,
                out string environmentName);

            Assert.IsTrue(resolved);
            Assert.AreEqual(expectedEnvironment, environmentName);
        }

        [TestCase(null)]
        [TestCase("")]
        [TestCase("com.offcutstudios.dessertmergecafe.dev.extra")]
        [TestCase("com.offcutstudios.dessertmergecafe.qa")]
        public async Task UnknownApplicationIdentifierFailsClosed(string identifier)
        {
            var runtime = CreateRuntime(ConsentStatus.Granted);
            using (var coordinator = CreateCoordinator(runtime, identifier))
            {
                coordinator.Start();
                await coordinator.TryInitializeIfAuthorizedAsync();

                Assert.AreEqual(0, servicesRuntime.InitializationCount);
                Assert.IsTrue(warnings.Exists(warning =>
                    warning.Contains("unsupported application identifier")));
            }
        }

        [Test]
        public async Task RepeatedStartAndConsentEventsDoNotDuplicateInitialization()
        {
            var runtime = CreateRuntime(ConsentStatus.Granted);
            using (var coordinator = CreateCoordinator(runtime))
            {
                coordinator.Start();
                coordinator.Start();
                runtime.SetConsentState(CreateConsentState(ConsentStatus.Granted));
                await coordinator.TryInitializeIfAuthorizedAsync();

                Assert.AreEqual(1, servicesRuntime.InitializationCount);
            }
        }

        [Test]
        public async Task WithdrawalDuringInitializationPreservesOtherConsentAndDoesNotRetry()
        {
            var completion = new TaskCompletionSource<bool>();
            var runtime = CreateRuntime(ConsentStatus.Granted);
            var servicesInitializer = CreateServicesInitializer();
            servicesRuntime.InitializationTask = completion.Task;

            using (var coordinator = CreateCoordinator(
                       runtime,
                       servicesInitializer))
            {
                coordinator.Start();
                Task initialization = coordinator.TryInitializeIfAuthorizedAsync();

                coordinator.WithdrawAnalyticsConsent();
                completion.SetResult(true);
                await initialization;
                await coordinator.TryInitializeIfAuthorizedAsync();

                Assert.AreEqual(ConsentStatus.Denied, runtime.ConsentState.AnalyticsIntent);
                Assert.AreEqual(ConsentStatus.Granted, runtime.ConsentState.AdsIntent);
                Assert.AreEqual(1, servicesRuntime.InitializationCount);
                Assert.IsFalse(coordinator.IsAnalyticsReady);
            }
        }

        [Test]
        public async Task WithdrawalAfterInitializationDisablesAnalyticsReadiness()
        {
            var runtime = CreateRuntime(ConsentStatus.Granted);
            using (var coordinator = CreateCoordinator(runtime))
            {
                coordinator.Start();
                await coordinator.TryInitializeIfAuthorizedAsync();

                Assert.IsTrue(coordinator.IsAnalyticsReady);
                coordinator.WithdrawAnalyticsConsent();

                Assert.AreEqual(
                    ConsentStatus.Denied,
                    runtime.ConsentState.AnalyticsIntent);
                Assert.IsFalse(coordinator.IsAnalyticsReady);
                Assert.AreEqual(1, servicesRuntime.InitializationCount);
            }
        }

        [Test]
        public void GrantingAnalyticsConsentPreservesOtherConsent()
        {
            var runtime = CreateRuntime(ConsentStatus.Unspecified);
            runtime.ConsentState = CreateConsentState(
                ConsentStatus.Unspecified,
                ConsentStatus.Denied);
            using (var coordinator = CreateCoordinator(runtime))
            {
                coordinator.SetAnalyticsConsent(true);

                Assert.AreEqual(
                    ConsentStatus.Granted,
                    runtime.ConsentState.AnalyticsIntent);
                Assert.AreEqual(
                    ConsentStatus.Denied,
                    runtime.ConsentState.AdsIntent);
            }
        }

        [Test]
        public async Task InitializationFailureIsBoundedAndNotRetried()
        {
            var runtime = CreateRuntime(ConsentStatus.Granted);
            var servicesInitializer = CreateServicesInitializer();
            servicesRuntime.InitializationTask = Task.FromException(
                new InvalidOperationException("test failure"));
            using (var coordinator = CreateCoordinator(
                       runtime,
                       servicesInitializer))
            {
                coordinator.Start();
                await coordinator.TryInitializeIfAuthorizedAsync();
                runtime.SetConsentState(CreateConsentState(ConsentStatus.Denied));
                runtime.SetConsentState(CreateConsentState(ConsentStatus.Granted));
                await coordinator.TryInitializeIfAuthorizedAsync();

                Assert.AreEqual(1, servicesRuntime.InitializationCount);
                Assert.IsTrue(warnings.Exists(warning =>
                    warning.Contains("gameplay will continue")));
            }
        }

        [Test]
        public async Task ExistingUnityServicesOwnerPreventsDuplicateInitialization()
        {
            var runtime = CreateRuntime(ConsentStatus.Granted);
            var servicesInitializer = CreateServicesInitializer(
                ServicesInitializationState.Initializing);
            using (var coordinator = CreateCoordinator(
                       runtime,
                       servicesInitializer))
            {
                coordinator.Start();
                await coordinator.TryInitializeIfAuthorizedAsync();

                Assert.AreEqual(0, servicesRuntime.InitializationCount);
                Assert.IsTrue(warnings.Exists(warning =>
                    warning.Contains("another initializer owns")));
            }
        }

        [Test]
        public void BootstrapAssemblyHasNoGameplayAssemblyDependency()
        {
            Assembly assembly = typeof(AnalyticsBootstrap).Assembly;
            string[] references = assembly.GetReferencedAssemblies()
                .Select(reference => reference.Name)
                .ToArray();

            CollectionAssert.DoesNotContain(references, "Assembly-CSharp");
            Assert.IsFalse(
                assembly.GetTypes().Any(type =>
                    type.Name.Contains("GameStartupCoordinator")));
        }

        private FakeRuntime CreateRuntime(ConsentStatus analyticsConsent)
        {
            return new FakeRuntime
            {
                ConsentState = CreateConsentState(analyticsConsent)
            };
        }

        private AnalyticsBootstrapCoordinator CreateCoordinator(
            FakeRuntime runtime,
            string applicationIdentifier =
                UnityServicesInitializationCoordinator.DevelopmentApplicationIdentifier)
        {
            return CreateCoordinator(
                runtime,
                CreateServicesInitializer(
                    applicationIdentifier:
                        applicationIdentifier));
        }

        private AnalyticsBootstrapCoordinator CreateCoordinator(
            FakeRuntime runtime,
            UnityServicesInitializationCoordinator servicesInitializer)
        {
            return new AnalyticsBootstrapCoordinator(
                runtime,
                servicesInitializer,
                warnings.Add);
        }

        private UnityServicesInitializationCoordinator CreateServicesInitializer(
            ServicesInitializationState servicesState =
                ServicesInitializationState.Uninitialized,
            string applicationIdentifier =
                UnityServicesInitializationCoordinator.DevelopmentApplicationIdentifier)
        {
            servicesRuntime = new FakeServicesRuntime
            {
                ApplicationIdentifier = applicationIdentifier,
                ServicesState = servicesState
            };
            return new UnityServicesInitializationCoordinator(
                servicesRuntime,
                warnings.Add);
        }

        private static ConsentState CreateConsentState(
            ConsentStatus analyticsConsent,
            ConsentStatus adsConsent = ConsentStatus.Granted)
        {
            return new ConsentState
            {
                AnalyticsIntent = analyticsConsent,
                AdsIntent = adsConsent
            };
        }
    }
}
