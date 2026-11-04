using System;
using System.Collections;
using System.IO;
using SweetMerge.Authentication;
using SweetMerge.Cloud;
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
    private StartupPlayMode selectedPlayMode;
    private string startupDecisionPlayerId;
    private bool freshGoogleNewGameCandidate;
    private string verifiedRestoreOwner;
    private bool ownershipEstablishmentAttempted;
    private GooglePlayGamesAuthenticationCoordinator subscribedAuthentication;
    private ApplicationReadinessCoordinator subscribedReadiness;

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
        SimpleCloudFiles.VerifiedRestorePromoted +=
            HandleVerifiedRestorePromoted;
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
        SubscribeToOwnershipReadiness(
            subscribeAuthentication: false);
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
            freshGoogleNewGameCandidate = false;
            verifiedRestoreOwner = null;
            ownershipEstablishmentAttempted = false;
            if (selectedPlayMode == StartupPlayMode.Google &&
                !string.IsNullOrWhiteSpace(startupDecisionPlayerId))
            {
                freshGoogleNewGameCandidate =
                    SweetMerge.Cloud.LocalSaveOwnership
                        .HasNoExistingProfileOrRecovery(
                            saveManager.SaveFilePath,
                            saveManager.LegacyV1SaveFilePath,
                            out _);
            }

            if (!saveManager.SaveFileExists())
            {
                Status = StartupStatus.NewGame;
                StateChanged?.Invoke();
                Debug.Log("STARTUP | New game. Waiting for verified Game initialization.");
                return;
            }
            freshGoogleNewGameCandidate = false;
            if (!saveManager.LoadCurrentGame())
            { FailStartup("Existing save could not be restored. Saving remains disabled."); return; }
            ownershipEstablishmentAttempted = false;
            Status = StartupStatus.Loaded;
            if (selectedPlayMode == StartupPlayMode.Google &&
                string.Equals(
                    SimpleCloudFiles.LastVerifiedRestoreOwner,
                    startupDecisionPlayerId,
                    StringComparison.Ordinal))
                verifiedRestoreOwner =
                    SimpleCloudFiles.LastVerifiedRestoreOwner;
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

        string playerId = null;
        if (playMode == StartupPlayMode.Google)
        {
            try
            {
                playerId =
                    SimpleCloudBackup.GetVerifiedCurrentOwnerId();
            }
            catch (Exception exception)
            {
                Debug.LogWarning(
                    "STARTUP | Google ownership could not be verified.\n" +
                    exception);
            }

            if (string.IsNullOrWhiteSpace(playerId))
                return false;
        }

        selectedPlayMode = playMode;
        startupDecisionPlayerId = playerId;
        freshGoogleNewGameCandidate = false;
        verifiedRestoreOwner = null;
        ownershipEstablishmentAttempted = false;
        SubscribeToOwnershipReadiness(
            subscribeAuthentication:
                playMode == StartupPlayMode.Google);

        startupDecisionConfirmed = true;
        startupAttempted = true;
        InitializeStartup();
        return true;
    }

    // SaveManager owns this transition; also used by the existing debug load tool.
    internal void BeginPersistentReload()
    {
        reloadLiveGameplay = IsStartupComplete;
        freshGoogleNewGameCandidate = false;
        verifiedRestoreOwner = null;
        ownershipEstablishmentAttempted = true;
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

        selectedPlayMode = StartupPlayMode.None;
        startupDecisionPlayerId = null;
        freshGoogleNewGameCandidate = false;
        verifiedRestoreOwner = null;
        ownershipEstablishmentAttempted = true;
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
        TryEstablishPendingOwnership();
        return true;
    }

    private void SubscribeToOwnershipReadiness(
        bool subscribeAuthentication)
    {
        ApplicationReadinessCoordinator readiness =
            ApplicationReadinessCoordinator.Instance;
        if (!ReferenceEquals(subscribedReadiness, readiness))
        {
            if (subscribedReadiness != null)
                subscribedReadiness.StateChanged -=
                    HandleApplicationReadinessChanged;
            subscribedReadiness = readiness;
            if (subscribedReadiness != null)
                subscribedReadiness.StateChanged +=
                    HandleApplicationReadinessChanged;
        }

        if (!subscribeAuthentication)
        {
            if (subscribedAuthentication != null)
                subscribedAuthentication.StateChanged -=
                    HandleAuthenticationStateChanged;
            subscribedAuthentication = null;
            return;
        }

        GooglePlayGamesAuthenticationCoordinator authentication =
            GooglePlayGamesAuthenticationCoordinator.Instance;
        if (!ReferenceEquals(subscribedAuthentication, authentication))
        {
            if (subscribedAuthentication != null)
                subscribedAuthentication.StateChanged -=
                    HandleAuthenticationStateChanged;
            subscribedAuthentication = authentication;
            subscribedAuthentication.StateChanged +=
                HandleAuthenticationStateChanged;
        }
    }

    private void HandleApplicationReadinessChanged(
        ApplicationReadinessState state)
    {
        if (state == ApplicationReadinessState.Ready)
            TryEstablishPendingOwnership();
    }

    private void HandleAuthenticationStateChanged()
    {
        if (selectedPlayMode != StartupPlayMode.Google ||
            string.IsNullOrEmpty(startupDecisionPlayerId))
            return;

        string currentPlayerId;
        try
        {
            currentPlayerId =
                SimpleCloudBackup.GetVerifiedCurrentOwnerId();
        }
        catch (Exception exception)
        {
            Debug.LogWarning(
                "SAVE OWNERSHIP | Current Google identity could not be " +
                "revalidated.\n" + exception);
            currentPlayerId = null;
        }
        if (string.Equals(
                currentPlayerId,
                startupDecisionPlayerId,
                StringComparison.Ordinal))
            return;

        freshGoogleNewGameCandidate = false;
        verifiedRestoreOwner = null;
        ownershipEstablishmentAttempted = true;
    }

    private void HandleVerifiedRestorePromoted(string playerId)
    {
        if (string.IsNullOrWhiteSpace(playerId) ||
            SimpleCloudFiles.RestorePending ||
            SimpleCloudFiles.StartupRestorePending)
            return;

        verifiedRestoreOwner = playerId;
    }

    private void TryEstablishPendingOwnership()
    {
        SaveManager saveManager = SaveManager.Instance;
        ApplicationReadinessCoordinator readiness =
            ApplicationReadinessCoordinator.Instance;
        if (ownershipEstablishmentAttempted ||
            !startupDecisionConfirmed ||
            selectedPlayMode != StartupPlayMode.Google ||
            string.IsNullOrWhiteSpace(startupDecisionPlayerId) ||
            !IsGameplayReady ||
            readiness == null ||
            !readiness.IsGameplayReady ||
            saveManager == null ||
            !saveManager.IsLifecycleSavingReady ||
            SimpleCloudFiles.RestorePending ||
            SimpleCloudFiles.StartupRestorePending ||
            SimpleCloudFiles.StartupError != null)
            return;

        string currentPlayerId;
        try
        {
            currentPlayerId =
                SimpleCloudBackup.GetVerifiedCurrentOwnerId();
        }
        catch (Exception exception)
        {
            Debug.LogWarning(
                "SAVE OWNERSHIP | Current Google identity could not be " +
                "verified.\n" + exception);
            currentPlayerId = null;
        }
        if (!string.Equals(
                currentPlayerId,
                startupDecisionPlayerId,
                StringComparison.Ordinal))
        {
            freshGoogleNewGameCandidate = false;
            verifiedRestoreOwner = null;
            ownershipEstablishmentAttempted = true;
            return;
        }

        bool samePlayerId = string.Equals(
            currentPlayerId,
            startupDecisionPlayerId,
            StringComparison.Ordinal);
        bool gameplayReady = IsGameplayReady &&
            readiness.IsGameplayReady &&
            saveManager.IsLifecycleSavingReady;
        bool restorePending = SimpleCloudFiles.RestorePending ||
            SimpleCloudFiles.StartupRestorePending;
        LocalSaveOwnershipEvidence evidence;
        if (freshGoogleNewGameCandidate &&
            Status == StartupStatus.NewGame)
        {
            if (!samePlayerId || restorePending ||
                !saveManager.SaveCurrentGame())
            {
                ownershipEstablishmentAttempted = true;
                freshGoogleNewGameCandidate = false;
                Debug.LogWarning(
                    "SAVE OWNERSHIP | Fresh Google progress was not linked " +
                    "because startup identity or the first local save was not verified.");
                return;
            }

            bool snapshotCommitted =
                File.Exists(saveManager.SaveFilePath) &&
                SaveManager.ValidateCloudSnapshot(
                    File.ReadAllText(saveManager.SaveFilePath));
            if (!LocalSaveOwnership.CanEstablishFreshGoogle(
                    selectedPlayMode == StartupPlayMode.Google,
                    !string.IsNullOrWhiteSpace(currentPlayerId),
                    freshGoogleNewGameCandidate,
                    snapshotCommitted,
                    gameplayReady,
                    samePlayerId,
                    restorePending))
            {
                ownershipEstablishmentAttempted = true;
                freshGoogleNewGameCandidate = false;
                return;
            }

            evidence =
                LocalSaveOwnershipEvidence.FreshVerifiedGoogleNewGame;
        }
        else if (!string.IsNullOrWhiteSpace(verifiedRestoreOwner) &&
                 Status == StartupStatus.Loaded &&
                 string.Equals(
                     verifiedRestoreOwner,
                     startupDecisionPlayerId,
                     StringComparison.Ordinal) &&
                 string.Equals(
                     SimpleCloudFiles.LastVerifiedRestoreOwner,
                     verifiedRestoreOwner,
                     StringComparison.Ordinal) &&
                 LocalSaveOwnership.CanEstablishVerifiedRestore(
                     selectedPlayMode == StartupPlayMode.Google,
                     string.Equals(
                         verifiedRestoreOwner,
                         startupDecisionPlayerId,
                         StringComparison.Ordinal),
                     string.Equals(
                         SimpleCloudFiles.LastVerifiedRestoreOwner,
                         verifiedRestoreOwner,
                         StringComparison.Ordinal),
                     Status == StartupStatus.Loaded &&
                         File.Exists(saveManager.SaveFilePath),
                     gameplayReady,
                     restorePending,
                     samePlayerId))
        {
            evidence = LocalSaveOwnershipEvidence.ActivatedVerifiedRestore;
        }
        else
        {
            return;
        }

        ownershipEstablishmentAttempted = true;

        string errorMessage = null;
        if (!SimpleCloudBackup.IsCurrentVerifiedOwner(
                startupDecisionPlayerId) ||
            !LocalSaveOwnership.TryEstablishForCurrentPlayer(
                saveManager.SaveFilePath,
                evidence,
                out errorMessage))
        {
            Debug.LogWarning(
                "SAVE OWNERSHIP | Startup completed without establishing " +
                "local account ownership. " +
                (errorMessage ?? "The verified account changed."));
            return;
        }

        SimpleCloudBackup.Instance?.NotifyLocalOwnershipEstablished();
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
        SimpleCloudFiles.VerifiedRestorePromoted -=
            HandleVerifiedRestorePromoted;
        SweetMerge.Cloud.SimpleCloudFiles.RestorePendingChanged -=
            HandleRestorePendingChanged;
        if (subscribedAuthentication != null)
            subscribedAuthentication.StateChanged -=
                HandleAuthenticationStateChanged;
        if (subscribedReadiness != null)
            subscribedReadiness.StateChanged -=
                HandleApplicationReadinessChanged;
        SaveManager.Instance?.SuspendLifecycleSaving();
        Instance = null;
    }
}
