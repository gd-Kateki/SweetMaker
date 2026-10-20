using System.Collections;
using UnityEngine;

public class GameStartupCoordinator : MonoBehaviour
{
    public static GameStartupCoordinator Instance { get; private set; }
    public enum StartupStatus { Waiting, Loading, NewGame, Loaded, Failed }
    public StartupStatus Status { get; private set; } = StartupStatus.Waiting;
    // Preserved meaning: persistent startup completed. Use IsGameplayReady for input.
    public bool IsStartupComplete => Status == StartupStatus.NewGame || Status == StartupStatus.Loaded;
    public bool IsStartupBlocked => Status == StartupStatus.Failed;
    public bool IsGameplayReady => IsStartupComplete &&
        ((verifiedController != null && verifiedController.isActiveAndEnabled &&
          verifiedController.IsRestorationVerified) || verifiedSnapshotAvailable);
    public string LastFailureReason { get; private set; }

    private bool startupAttempted;
    private bool reloadLiveGameplay;
    private MergeSessionController verifiedController;
    private bool verifiedSnapshotAvailable;

    internal void BeginGameplayInitialization()
    {
        verifiedSnapshotAvailable = false;
        verifiedController = null;
        SaveManager.Instance?.SuspendLifecycleSaving();
    }

    // Called only after the departing Game has captured a complete session.
    // MainBakery can then save the verified persistent snapshot, as before.
    internal bool ReleaseVerifiedGameplay(MergeSessionController controller)
    {
        if (verifiedController != controller || !IsStartupComplete) return false;
        verifiedController = null;
        verifiedSnapshotAvailable = true;
        return SaveManager.Instance != null && SaveManager.Instance.MarkGameplayReadyForLifecycleSaves();
    }

    private void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        SaveManager.Instance?.SuspendLifecycleSaving();
    }

    private IEnumerator Start()
    {
        yield return null;
        if (!startupAttempted)
        {
            startupAttempted = true;
            InitializeStartup();
        }
    }

    private void InitializeStartup()
    {
        Status = StartupStatus.Loading;
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
                Debug.Log("STARTUP | New game. Waiting for verified Game initialization.");
                return;
            }
            if (!saveManager.LoadCurrentGame())
            { FailStartup("Existing save could not be restored. Saving remains disabled."); return; }
            Status = StartupStatus.Loaded;
            Debug.Log("STARTUP | Persistent data verified. Waiting for Game restoration.");
        }
        catch (System.Exception exception) { FailStartup(exception.ToString()); }
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
    }

    internal void CompletePersistentReload()
    {
        Status = StartupStatus.Loaded;
        LastFailureReason = null;
        if (reloadLiveGameplay) StartCoroutine(RestoreLiveAfterReload());
        reloadLiveGameplay = false;
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
        Debug.LogError("STARTUP FAILED | " + reason);
    }

    private void OnDestroy()
    {
        if (Instance != this) return;
        SaveManager.Instance?.SuspendLifecycleSaving();
        Instance = null;
    }
}
