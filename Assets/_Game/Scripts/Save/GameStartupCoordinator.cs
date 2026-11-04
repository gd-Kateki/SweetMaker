using System;
using System.Collections;
using SweetMerge.Startup;
using UnityEngine;

public class GameStartupCoordinator : MonoBehaviour
{
    public static GameStartupCoordinator Instance { get; private set; }
    public enum StartupStatus { Waiting, Loading, NewGame, Loaded, Failed }
    public StartupStatus Status { get; private set; } = StartupStatus.Waiting;
    // Preserved meaning: persistent startup completed. Use IsGameplayReady for input.
    public bool IsStartupComplete => Status == StartupStatus.NewGame || Status == StartupStatus.Loaded;
    public bool IsStartupBlocked => Status == StartupStatus.Failed;
    internal bool StartupDecisionConfirmed => startupDecisionConfirmed;
    public bool IsGameplayReady => IsStartupComplete &&
        ((verifiedController != null && verifiedController.isActiveAndEnabled &&
          verifiedController.IsRestorationVerified) || verifiedSnapshotAvailable);
    public string LastFailureReason { get; private set; }
    public event Action StateChanged;

    private bool startupAttempted;
    private bool startupDecisionGateRequired;
    private bool startupDecisionConfirmed;
    private bool reloadLiveGameplay;
    private MergeSessionController verifiedController;
    private bool verifiedSnapshotAvailable;

    internal void BeginGameplayInitialization()
    {
        verifiedSnapshotAvailable = false;
        verifiedController = null;
        SaveManager.Instance?.SuspendLifecycleSaving();
        StateChanged?.Invoke();
    }

    // Called only after the departing Game has captured a complete session.
    // MainBakery can then save the verified persistent snapshot, as before.
    internal bool ReleaseVerifiedGameplay(MergeSessionController controller)
    {
        if (verifiedController != controller || !IsStartupComplete) return false;
        verifiedController = null;
        verifiedSnapshotAvailable = true;
        bool ready = SaveManager.Instance != null &&
            SaveManager.Instance.MarkGameplayReadyForLifecycleSaves();
        StateChanged?.Invoke();
        return ready;
    }

    private void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        if (StartupFlowIntegrationOwner.FeatureEnabled)
        {
            startupDecisionGateRequired = true;
            startupDecisionConfirmed = false;
            Status = StartupStatus.Waiting;
        }
        SaveManager.Instance?.SuspendLifecycleSaving();
        SweetMerge.Cloud.SimpleCloudFiles.RestorePendingChanged +=
            HandleRestorePendingChanged;
        StateChanged?.Invoke();
    }

    private IEnumerator Start()
    {
        if (StartupFlowIntegrationOwner.FeatureEnabled)
            RequireStartupDecisionGate();

        yield return null;
        if (StartupIntegrationPolicy.ShouldStartSaveInitialization(
                startupAttempted))
        {
            startupAttempted = true;
            InitializeStartup();
        }
    }

    private void InitializeStartup()
    {
        if (SweetMerge.Cloud.SimpleCloudFiles.RestorePending)
        {
            SaveManager.Instance?.SuspendLifecycleSaving();
            if (SweetMerge.Cloud.SimpleCloudFiles.StartupError != null)
            {
                FailStartup(
                    SweetMerge.Cloud.SimpleCloudFiles.StartupError);
                return;
            }

            Status = StartupStatus.Waiting;
            LastFailureReason = null;
            StateChanged?.Invoke();
            return;
        }

        if (StartupIntegrationPolicy.ShouldBlockSaveLoad(
                startupDecisionGateRequired,
                startupDecisionConfirmed))
        {
            Status = StartupStatus.Waiting;
            StateChanged?.Invoke();
            return;
        }

        if (SweetMerge.Cloud.SimpleCloudFiles.StartupError != null)
        { FailStartup(SweetMerge.Cloud.SimpleCloudFiles.StartupError); return; }
        Status = StartupStatus.Loading;
        StateChanged?.Invoke();
        var saveManager = SaveManager.Instance;
        saveManager?.SuspendLifecycleSaving();
        if (saveManager == null || EconomyManager.Instance == null ||
            PlayerProgressionManager.Instance == null || MergeSessionManager.Instance == null)
        { FailStartup("A required persistent manager is missing."); return; }
        try
        {
            if (!PlayerProgressionManager.Instance.ValidateRestorationDefinitions(out string reason))
            { FailStartup(reason); return; }
            if (!saveManager.SaveFileExists())
            {
                Status = StartupStatus.NewGame;
                StateChanged?.Invoke();
                Debug.Log("STARTUP | New game. Waiting for verified Game initialization.");
                return;
            }
            if (!saveManager.LoadCurrentGame())
            { FailStartup("Existing save could not be restored. Saving remains disabled."); return; }
            Status = StartupStatus.Loaded;
            StateChanged?.Invoke();
            Debug.Log("STARTUP | Persistent data verified. Waiting for Game restoration.");
        }
        catch (System.Exception exception) { FailStartup(exception.ToString()); }
    }

    internal void RetryStartup()
    {
        if (Status != StartupStatus.Failed)
            return;

        startupAttempted = true;
        InitializeStartup();
    }

    internal void RequireStartupDecisionGate()
    {
        if (startupAttempted || startupDecisionConfirmed)
            return;

        startupDecisionGateRequired = true;
        Status = StartupStatus.Waiting;
        StateChanged?.Invoke();
    }

    private void HandleRestorePendingChanged(bool restorePending)
    {
        if (restorePending)
        {
            SaveManager.Instance?.SuspendLifecycleSaving();
            if (SweetMerge.Cloud.SimpleCloudFiles.StartupError != null)
                FailStartup(SweetMerge.Cloud.SimpleCloudFiles.StartupError);
            else
            {
                Status = StartupStatus.Waiting;
                LastFailureReason = null;
                StateChanged?.Invoke();
            }
            return;
        }

        if (startupAttempted)
            InitializeStartup();
    }

    internal bool ConfirmStartupDecision(
        StartupPlayMode playMode,
        bool googleIdentityVerified)
    {
        if (!StartupIntegrationPolicy.CanConfirmStartupDecision(
                startupDecisionGateRequired,
                startupDecisionConfirmed,
                SweetMerge.Cloud.SimpleCloudFiles.StartupRestorePending,
                playMode,
                googleIdentityVerified))
        {
            return false;
        }

        startupDecisionConfirmed = true;
        startupAttempted = true;
        InitializeStartup();
        return true;
    }

    // SaveManager owns this transition; also used by the existing debug load tool.
    internal void BeginPersistentReload()
    {
        reloadLiveGameplay = IsStartupComplete;
        verifiedController?.InvalidateRestoration();
        verifiedController = null;
        verifiedSnapshotAvailable = false;
        Status = StartupStatus.Loading;
        SaveManager.Instance?.SuspendLifecycleSaving();
        StateChanged?.Invoke();
    }

    internal void CompletePersistentReload()
    {
        Status = StartupStatus.Loaded;
        LastFailureReason = null;
        StateChanged?.Invoke();
        if (reloadLiveGameplay) StartCoroutine(RestoreLiveAfterReload());
        reloadLiveGameplay = false;
    }

    internal bool BeginFreshDevelopmentGame()
    {
        if (!SavePathPolicy.IsDevelopmentSaveIsolationEnabled)
            return false;

        startupAttempted = true;
        reloadLiveGameplay = false;
        verifiedController = null;
        verifiedSnapshotAvailable = false;
        LastFailureReason = null;
        Status = StartupStatus.NewGame;
        SaveManager.Instance?.SuspendLifecycleSaving();
        StateChanged?.Invoke();
        return true;
    }

    private IEnumerator RestoreLiveAfterReload()
    {
        yield return null;
        var controller = FindAnyObjectByType<MergeSessionController>();
        if (controller != null && !controller.IsRestorationVerified)
            controller.TryRestoreSession();
    }

    public bool ConfirmGameplayRestoration(MergeSessionController controller)
    {
        if (!IsStartupComplete || controller == null || !controller.isActiveAndEnabled ||
            !controller.IsRestorationVerified || SaveManager.Instance == null)
            return false;
        if (FindObjectsByType<MergeSessionController>().Length != 1)
        { FailStartup("Exactly one active MergeSessionController is required."); return false; }
        verifiedController = controller;
        verifiedSnapshotAvailable = false;
        if (!SaveManager.Instance.MarkGameplayReadyForLifecycleSaves())
        { FailStartup("SaveManager refused readiness."); return false; }
        LastFailureReason = null;
        StateChanged?.Invoke();
        return true;
    }

    public void ReportGameplayRestorationFailure(string reason) { FailStartup(reason); }

    private void FailStartup(string reason)
    {
        Status = StartupStatus.Failed;
        LastFailureReason = reason;
        verifiedController?.InvalidateRestoration();
        verifiedController = null;
        verifiedSnapshotAvailable = false;
        SaveManager.Instance?.SuspendLifecycleSaving();
        StateChanged?.Invoke();
        Debug.LogError("STARTUP FAILED | " + reason);
    }

    private void OnDestroy()
    {
        if (Instance != this) return;
        SweetMerge.Cloud.SimpleCloudFiles.RestorePendingChanged -=
            HandleRestorePendingChanged;
        SaveManager.Instance?.SuspendLifecycleSaving();
        Instance = null;
    }
}
