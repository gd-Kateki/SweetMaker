using System;
using System.Threading.Tasks;
using Unity.Services.Core;
using Unity.Services.Core.Environments;
using UnityEngine;

namespace SweetMerge.Analytics
{
    public static class UnityServicesInitializer
    {
        public static Task InitializeAsync()
        {
            return UnityServicesInitializationCoordinator.Shared
                .RequestInitializationAsync();
        }
    }

    internal interface IUnityServicesInitializationRuntime
    {
        string ApplicationIdentifier { get; }
        ServicesInitializationState ServicesState { get; }
        Task InitializeServicesAsync(string environmentName);
    }

    internal sealed class UnityServicesInitializationCoordinator
    {
        internal const string DevelopmentApplicationIdentifier =
            "com.offcutstudios.dessertmergecafe.dev";
        internal const string ProductionApplicationIdentifier =
            "com.offcutstudios.dessertmergecafe";

        private sealed class UnityServicesInitializationRuntime :
            IUnityServicesInitializationRuntime
        {
            public string ApplicationIdentifier => Application.identifier;

            public ServicesInitializationState ServicesState =>
                UnityServices.State;

            public Task InitializeServicesAsync(string environmentName)
            {
                var options = new InitializationOptions()
                    .SetEnvironmentName(environmentName);
                return UnityServices.InitializeAsync(options);
            }
        }

        private static readonly object sharedGate = new object();
        private static UnityServicesInitializationCoordinator shared;

        private readonly IUnityServicesInitializationRuntime runtime;
        private readonly Action<string> logWarning;
        private readonly object gate = new object();
        private Task initializationTask;
        private string initializationEnvironment;

        internal static UnityServicesInitializationCoordinator Shared
        {
            get
            {
                lock (sharedGate)
                {
                    if (shared == null)
                    {
                        shared = new UnityServicesInitializationCoordinator(
                            new UnityServicesInitializationRuntime(),
                            Debug.LogWarning);
                    }

                    return shared;
                }
            }
        }

        internal UnityServicesInitializationCoordinator(
            IUnityServicesInitializationRuntime runtime,
            Action<string> logWarning)
        {
            this.runtime = runtime ??
                throw new ArgumentNullException(nameof(runtime));
            this.logWarning = logWarning ??
                throw new ArgumentNullException(nameof(logWarning));
        }

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        private static void ResetShared()
        {
            lock (sharedGate)
                shared = null;
        }

        internal Task RequestInitializationAsync()
        {
            if (!TryResolveEnvironment(
                    runtime.ApplicationIdentifier,
                    out string environmentName))
            {
                return Fail(
                    "Unity Services initialization skipped: unsupported application identifier.");
            }

            TaskCompletionSource<bool> completion = null;
            lock (gate)
            {
                if (initializationTask != null)
                {
                    if (!initializationTask.IsFaulted &&
                        !initializationTask.IsCanceled)
                    {
                        if (initializationEnvironment != environmentName)
                        {
                            return Fail(
                                "Unity Services initialization rejected: the requested environment differs from the active initialization.");
                        }

                        return initializationTask;
                    }

                    if (runtime.ServicesState !=
                        ServicesInitializationState.Uninitialized)
                    {
                        return initializationTask;
                    }

                    initializationTask = null;
                    initializationEnvironment = null;
                }

                if (runtime.ServicesState ==
                    ServicesInitializationState.Initialized)
                {
                    return Fail(
                        "Unity Services initialization rejected: services were initialized outside the shared coordinator, so the environment cannot be verified.");
                }

                if (runtime.ServicesState ==
                    ServicesInitializationState.Initializing)
                {
                    return Fail(
                        "Unity Services initialization rejected: another initializer owns the in-progress operation.");
                }

                completion = new TaskCompletionSource<bool>(
                    TaskCreationOptions.RunContinuationsAsynchronously);
                initializationTask = completion.Task;
                initializationEnvironment = environmentName;
            }

            _ = CompleteInitializationAsync(environmentName, completion);
            return completion.Task;
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

        private async Task CompleteInitializationAsync(
            string environmentName,
            TaskCompletionSource<bool> completion)
        {
            try
            {
                await runtime.InitializeServicesAsync(environmentName);
                completion.TrySetResult(true);
            }
            catch (Exception exception)
            {
                lock (gate)
                {
                    if (ReferenceEquals(initializationTask, completion.Task) &&
                        runtime.ServicesState ==
                        ServicesInitializationState.Uninitialized)
                    {
                        initializationTask = null;
                        initializationEnvironment = null;
                    }
                }

                logWarning(
                    "Unity Services initialization failed for the " +
                    environmentName + " environment: " + exception.Message);
                completion.TrySetException(exception);
            }
        }

        private Task Fail(string message)
        {
            logWarning(message);
            return Task.FromException(new InvalidOperationException(message));
        }
    }
}
