using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class MergeSessionController : MonoBehaviour
{
    internal interface ILiveSessionCapacityEvidence
    {
        FrozenMergeSessionValues Session { get; }
        int CustomerCapacity { get; }
    }

    private sealed class LiveSessionCapacityEvidence :
        ILiveSessionCapacityEvidence
    {
        private readonly object issuerToken;

        public FrozenMergeSessionValues Session { get; }
        public int CustomerCapacity { get; }

        public LiveSessionCapacityEvidence(
            object issuerToken,
            FrozenMergeSessionValues session,
            int customerCapacity)
        {
            this.issuerToken = issuerToken;
            Session = session;
            CustomerCapacity = customerCapacity;
        }

        public bool WasIssuedBy(object expectedIssuerToken)
        {
            return ReferenceEquals(issuerToken, expectedIssuerToken);
        }
    }

    private sealed class DessertPlacement
    {
        public Dessert Dessert;
        public GridCell Cell;
        public ShelfSlot Slot;
    }

    [Header("References")]
    [SerializeField]
    private GridManager gridManager;
    [SerializeField]
    private ShelfManager shelfManager;
    [SerializeField]
    private DessertSpawner dessertSpawner;
    [SerializeField]
    private OrderManager orderManager;
    private readonly object liveEvidenceIssuerToken = new object();
    private bool hasRestoredAutomatically;
    private bool restorationInProgress;
    private bool allowVerifiedMigrationCapture;
    private bool replacementSessionPreparedForCommit;
    private bool departurePrepared;
    public bool IsRestorationVerified { get; private set; }
    public string LastRestorationError { get; private set; }
    internal bool IsPreparedFreshSessionForCommit =>
        restorationInProgress &&
        replacementSessionPreparedForCommit &&
        IsRestorationVerified;
    internal void InvalidateRestoration()
    {
        IsRestorationVerified = false;
        SaveManager.Instance?.SuspendLifecycleSaving();
    }
    private void Awake()
    {
        GameStartupCoordinator.Instance?.BeginGameplayInitialization();
        SaveManager.Instance?.SuspendLifecycleSaving();
    }
    private void OnEnable()
    {
        departurePrepared = false;
        if (hasRestoredAutomatically)
        {
            GameStartupCoordinator.Instance?.BeginGameplayInitialization();
            StartCoroutine(RestoreAfterEnable());
        }
    }
    private IEnumerator RestoreAfterEnable()
    {
        yield return null;
        TryRestoreSession();
    }
    private void OnDisable()
    {
        // Scene dependencies may already have been destroyed. Never capture,
        // validate, or report a startup failure from this teardown callback.
        // Only an explicit, successful departure can leave snapshot saving ready.
        bool released = departurePrepared && IsRestorationVerified &&
            !restorationInProgress;
        departurePrepared = false;
        IsRestorationVerified = false;
        if (!released) SaveManager.Instance?.SuspendLifecycleSaving();
    }
    // Call immediately before unloading Game, while dependencies still exist.
    // This captures and SAVES TO DISK before releasing the verified snapshot.
    // The caller must remain in Game if this returns false.
    public bool PrepareToLeaveGameplay()
    {
        if (departurePrepared) return IsRestorationVerified;
        if (!isActiveAndEnabled || restorationInProgress) return false;
        var coordinator = GameStartupCoordinator.Instance;
        var saveManager = SaveManager.Instance;
        if (coordinator == null || saveManager == null) return false;
        try
        {
            if (!TryCaptureSession()) return false;
            // SaveManager may capture again; that is safe while the scene is live.
            if (!saveManager.SaveCurrentGame()) return false;
            departurePrepared = coordinator.ReleaseVerifiedGameplay(this);
            if (!departurePrepared)
            {
                // Older coordinators can leave snapshot readiness set when
                // ReleaseVerifiedGameplay returns false. Clear it explicitly.
                coordinator.BeginGameplayInitialization();
                IsRestorationVerified = false;
                saveManager.SuspendLifecycleSaving();
            }
            return departurePrepared;
        }
        catch (Exception exception)
        {
            return FailRestoration(exception.ToString());
        }
    }
    // Call if navigation fails after PrepareToLeaveGameplay returned true.
    // Reverify the existing live state without spawning/restoring objects again.
    public bool CancelPreparedDeparture()
    {
        if (!departurePrepared) return false;
        departurePrepared = false;
        IsRestorationVerified = false;
        var coordinator = GameStartupCoordinator.Instance;
        coordinator?.BeginGameplayInitialization();
        SaveManager.Instance?.SuspendLifecycleSaving();
        if (!isActiveAndEnabled || coordinator == null) return false;
        try
        {
            if (!ValidateLiveState(out string reason)) return FailRestoration(reason);
            IsRestorationVerified = true;
            if (!coordinator.ConfirmGameplayRestoration(this))
                return FailRestoration("The coordinator refused gameplay readiness after cancelled departure.");
            return true;
        }
        catch (Exception exception)
        {
            return FailRestoration(exception.ToString());
        }
    }
    private bool FailRestoration(string reason)
    {
        IsRestorationVerified = false;
        LastRestorationError = reason;
        SaveManager.Instance?.SuspendLifecycleSaving();
        GameStartupCoordinator.Instance?.ReportGameplayRestorationFailure(reason);
        Debug.LogError("RESTORATION FAILED | " + reason);
        return false;
    }
    // ==================================================
    // UNITY
    // ==================================================
    private IEnumerator Start()
    {
        yield return null;
        if (GameStartupCoordinator.Instance == null)
        {
            FailRestoration("GameStartupCoordinator is missing.");
            yield break;
        }
        while (GameStartupCoordinator.Instance != null &&
               !GameStartupCoordinator.Instance.IsStartupComplete &&
               !GameStartupCoordinator.Instance.IsStartupBlocked)
            yield return null;
        while (ApplicationReadinessCoordinator.Instance != null &&
               !ApplicationReadinessCoordinator.Instance.IsReady)
            yield return null;
        if (ApplicationReadinessCoordinator.Instance == null)
        {
            FailRestoration("Application readiness coordinator is missing.");
            yield break;
        }
        // Also give consumers of restored progression a complete frame to initialize.
        yield return null;
        TryRestoreSessionAutomatically();
    }
    // ==================================================
    // AUTOMATIC RESTORATION
    // ==================================================
    private void TryRestoreSessionAutomatically()
    {
        if (hasRestoredAutomatically) return;
        hasRestoredAutomatically = TryRestoreSession();
    }
    // ==================================================
    // CAPTURE
    // ==================================================
    public void CaptureSession()
    {
        TryCaptureSession();
    }
    /// <summary>
    /// Captures the current live merge gameplay state
    /// into the persistent MergeSessionManager.
    ///
    /// Returns true only when the complete session
    /// was captured successfully.
    /// </summary>
    public bool TryCaptureSession()
    {
        if ((restorationInProgress && !allowVerifiedMigrationCapture) ||
            !IsRestorationVerified ||
            GameStartupCoordinator.Instance == null ||
            !GameStartupCoordinator.Instance.IsStartupComplete)
            return false;
        if (gridManager != null &&
            gridManager.IsMergeTransactionActive)
            return false;
        if (!ValidateLiveState(out string reason))
            return FailRestoration(reason);
        ResolveReferences();
        // ----------------------------------------------
        // GAMEPLAY REFERENCES
        // ----------------------------------------------
        if (gridManager == null ||
            shelfManager == null ||
            dessertSpawner == null ||
            orderManager == null)
        {
            Debug.LogError(
                "MergeSessionController: " +
                "Cannot capture session because " +
                "a required gameplay reference " +
                "is missing."
            );
            return false;
        }
        // ----------------------------------------------
        // SESSION MANAGER
        // ----------------------------------------------
        if (MergeSessionManager.Instance == null)
        {
            Debug.LogError(
                "MergeSessionController: " +
                "Cannot capture session because " +
                "MergeSessionManager does not exist."
            );
            return false;
        }
        // ----------------------------------------------
        // BUILD SESSION
        // ----------------------------------------------
        MergeSessionData data =
            new MergeSessionData();
        CaptureBoard(data);
        CaptureShelf(data);
        CaptureOrders(data);
        CaptureNextDessert(data);
        // ----------------------------------------------
        // STORE SESSION
        // ----------------------------------------------
        MergeSessionManager.Instance
            .SaveSession(data);
        SaveManager.Instance?.RecordSessionCustomerCapacity(
            MergeSessionManager.Instance.SessionData,
            orderManager.ActiveCustomerCount,
            dessertSpawner.SelectedSpawnPoolId);
        Debug.Log(
            "MERGE SESSION CAPTURE COMPLETE | " +
            $"Board: {data.boardDesserts.Count} | " +
            $"Shelf: {data.shelfDesserts.Count} | " +
            $"Orders: {data.customerOrders.Count} | " +
            $"Next Order ID: #{data.nextOrderId} | " +
            $"Next Dessert: T{data.nextDessertTier}"
        );
        return true;
    }

    internal bool TryCaptureLiveSessionCapacityEvidence(
        out ILiveSessionCapacityEvidence evidence,
        out SessionPublicationFailure failure)
    {
        evidence = null;
        failure = SessionPublicationFailure.None;

        GameStartupCoordinator coordinator =
            GameStartupCoordinator.Instance;
        if (coordinator == null ||
            PlayerProgressionManager.Instance == null)
        {
            failure = SessionPublicationFailure.OwnerUnavailable;
            return false;
        }

        if (!isActiveAndEnabled ||
            restorationInProgress ||
            departurePrepared ||
            !coordinator.IsStartupComplete ||
            !coordinator.IsGameplayReady ||
            !IsRestorationVerified)
        {
            failure = SessionPublicationFailure.IneligibleLifecycle;
            return false;
        }

        MergeSessionController[] controllers =
            FindObjectsByType<MergeSessionController>();
        if (controllers.Length != 1 ||
            !ReferenceEquals(controllers[0], this))
        {
            failure = SessionPublicationFailure.UnauthorizedSource;
            return false;
        }

        if (gridManager == null ||
            shelfManager == null ||
            dessertSpawner == null ||
            orderManager == null ||
            gridManager.IsMergeTransactionActive)
        {
            failure = SessionPublicationFailure.CaptureUnavailable;
            return false;
        }

        PlayerProgressionManager progression =
            PlayerProgressionManager.Instance;
        if (progression == null)
        {
            failure = SessionPublicationFailure.OwnerUnavailable;
            return false;
        }

        int customerCapacity = progression.ActiveCustomerOrders;
        if (customerCapacity < 1 || customerCapacity > 3)
        {
            failure = SessionPublicationFailure.CapacityEvidenceUnavailable;
            return false;
        }

        if (!ValidateLiveState(out _))
        {
            failure = SessionPublicationFailure.CaptureUnavailable;
            return false;
        }

        var saveData = new MergeGameplaySaveData
        {
            hasSession = true,
            nextOrderId = orderManager.NextOrderId,
            nextDessertTier = dessertSpawner.NextDessert != null
                ? dessertSpawner.NextDessert.Tier
                : -1
        };

        for (int i = 0; i < gridManager.Cells.Count; i++)
        {
            GridCell cell = gridManager.Cells[i];
            if (cell.IsEmpty)
                continue;

            Dessert dessert = cell.CurrentDessert;
            saveData.boardDesserts.Add(
                new BoardDessertSaveData(
                    i,
                    dessert.Definition.Tier));
        }

        for (int i = 0; i < shelfManager.Slots.Count; i++)
        {
            ShelfSlot slot = shelfManager.Slots[i];
            if (slot.IsEmpty)
                continue;

            Dessert dessert = slot.CurrentDessert;
            saveData.shelfDesserts.Add(
                new ShelfDessertSaveData(
                    i,
                    dessert.Definition.Tier));
        }

        for (int customerIndex = 0;
             customerIndex < customerCapacity;
             customerIndex++)
        {
            CustomerOrder order =
                orderManager.CustomerOrders[customerIndex];
            string definitionId;
            if (order.Definition != null)
            {
                definitionId = order.Definition.DefinitionId;
                if (string.IsNullOrWhiteSpace(definitionId))
                {
                    failure =
                        SessionPublicationFailure.InvalidFrozenValues;
                    return false;
                }
            }
            else if (!ProceduralCustomerOrderSaveCodec.TryEncode(
                         order.DisplayName,
                         order.CashReward,
                         order.Requirements,
                         out definitionId))
            {
                failure =
                    SessionPublicationFailure.InvalidFrozenValues;
                return false;
            }

            saveData.customerOrders.Add(
                new CustomerOrderSaveData(
                    customerIndex,
                    order.OrderId,
                    definitionId));
        }

        if (!StrictMergeSessionFreezer.TryFreeze(
                saveData,
                out FrozenMergeSessionValues frozen,
                out _))
        {
            failure = SessionPublicationFailure.InvalidFrozenValues;
            return false;
        }

        if (!HasExactLiveCustomerCoverage(
                frozen,
                customerCapacity))
        {
            failure = SessionPublicationFailure.CapacityEvidenceMismatch;
            return false;
        }

        evidence = new LiveSessionCapacityEvidence(
            liveEvidenceIssuerToken,
            frozen,
            customerCapacity);
        return true;
    }

    internal bool TryVerifyIssuedLiveEvidence(
        ILiveSessionCapacityEvidence evidence,
        FrozenMergeSessionValues expectedSession,
        out int customerCapacity,
        out SessionPublicationFailure failure)
    {
        customerCapacity = 0;
        failure = SessionPublicationFailure.UnauthorizedSource;
        if (evidence == null)
            return false;
        if (expectedSession == null)
        {
            failure = SessionPublicationFailure.InvalidFrozenValues;
            return false;
        }

        if (!(evidence is LiveSessionCapacityEvidence issuedEvidence) ||
            !issuedEvidence.WasIssuedBy(liveEvidenceIssuerToken))
        {
            return false;
        }

        if (!ReferenceEquals(issuedEvidence.Session, expectedSession))
        {
            failure = SessionPublicationFailure.PublicationIdentityMismatch;
            return false;
        }

        if (!HasExactLiveCustomerCoverage(
                issuedEvidence.Session,
                issuedEvidence.CustomerCapacity))
        {
            failure = SessionPublicationFailure.CapacityEvidenceMismatch;
            return false;
        }

        customerCapacity = issuedEvidence.CustomerCapacity;
        failure = SessionPublicationFailure.None;
        return true;
    }

    private static bool HasExactLiveCustomerCoverage(
        FrozenMergeSessionValues frozen,
        int customerCapacity)
    {
        if (frozen == null ||
            !frozen.HasSession ||
            customerCapacity < 1 ||
            customerCapacity > 3 ||
            frozen.CustomerOrders == null ||
            frozen.CustomerOrders.Count != customerCapacity ||
            frozen.NextOrderId < 1)
        {
            return false;
        }

        var coveredCustomers = new bool[customerCapacity];
        var orderIds = new HashSet<int>();
        foreach (FrozenCustomerOrderValue order in frozen.CustomerOrders)
        {
            if (order == null ||
                order.CustomerIndex < 0 ||
                order.CustomerIndex >= customerCapacity ||
                coveredCustomers[order.CustomerIndex] ||
                order.OrderId <= 0 ||
                order.OrderId >= frozen.NextOrderId ||
                !orderIds.Add(order.OrderId))
            {
                return false;
            }

            coveredCustomers[order.CustomerIndex] = true;
        }

        for (int i = 0; i < coveredCustomers.Length; i++)
            if (!coveredCustomers[i])
                return false;

        return true;
    }

    public bool TryReplaceWithFreshSession()
    {
        return TryReplaceWithFreshSession(null);
    }

    internal bool TryReplaceWithFreshSession(Func<bool> commitBeforeFinalizing)
    {
        if (!isActiveAndEnabled || restorationInProgress ||
            !IsRestorationVerified ||
            GameStartupCoordinator.Instance == null ||
            !GameStartupCoordinator.Instance.IsStartupComplete ||
            SaveManager.Instance == null ||
            MergeSessionManager.Instance == null)
            return false;

        ResolveReferences();
        string reason = null;
        if (gridManager == null || shelfManager == null ||
            dessertSpawner == null || orderManager == null ||
            !ValidateLiveState(out reason))
        {
            Debug.LogError(
                "SESSION REPLACEMENT FAILED | " +
                (reason ?? "A gameplay dependency is unavailable."));
            return false;
        }

        if (FindObjectsByType<MergeSessionController>().Length != 1)
        {
            Debug.LogError(
                "SESSION REPLACEMENT FAILED | " +
                "Exactly one active MergeSessionController is required.");
            return false;
        }

        if (!orderManager.TryPrepareFreshSessionOrders(
                out CustomerOrderState[] freshOrders,
                out int freshNextOrderId) ||
            !dessertSpawner.TryPrepareFreshSessionPreview(
                out DessertDefinition freshPreview))
        {
            Debug.LogError(
                "SESSION REPLACEMENT FAILED | " +
                "A valid order set or Oven preview could not be prepared.");
            return false;
        }

        var oldPlacements = CaptureDessertPlacements();
        var oldOrders = orderManager.CaptureSessionReplacementState();
        DessertDefinition oldPreview = dessertSpawner.NextDessert;
        MergeSessionData oldSession = new MergeSessionData();
        CaptureBoard(oldSession);
        CaptureShelf(oldSession);
        CaptureOrders(oldSession);
        CaptureNextDessert(oldSession);
        int oldCustomerCapacity = orderManager.ActiveCustomerCount;

        var coordinator = GameStartupCoordinator.Instance;
        var saveManager = SaveManager.Instance;
        restorationInProgress = true;
        replacementSessionPreparedForCommit = false;
        IsRestorationVerified = false;
        departurePrepared = false;
        coordinator.BeginGameplayInitialization();
        saveManager.SuspendLifecycleSaving();

        try
        {
            DetachAndDisableDesserts(oldPlacements);
            if (!orderManager.ApplyPreparedFreshSessionOrders(
                    freshOrders,
                    freshNextOrderId) ||
                !dessertSpawner.SetFreshSessionPreview(
                    freshPreview,
                    false) ||
                !ValidateLiveState(out reason))
            {
                TryRestorePreviousLiveSession(
                    oldPlacements,
                    oldOrders,
                    oldPreview,
                    oldSession,
                    oldCustomerCapacity,
                    coordinator,
                    saveManager);
                Debug.LogError(
                    "SESSION REPLACEMENT FAILED | " +
                    (reason ?? "Prepared state could not be applied."));
                return false;
            }

            var freshSession = new MergeSessionData();
            CaptureBoard(freshSession);
            CaptureShelf(freshSession);
            CaptureOrders(freshSession);
            CaptureNextDessert(freshSession);
            MergeSessionManager.Instance.SaveSession(freshSession);
            saveManager.RecordSessionCustomerCapacity(
                MergeSessionManager.Instance.SessionData,
                orderManager.ActiveCustomerCount,
                dessertSpawner.SelectedSpawnPoolId);
            replacementSessionPreparedForCommit = true;

            IsRestorationVerified = true;
            if (!coordinator.ConfirmGameplayRestoration(this))
            {
                TryRestorePreviousLiveSession(
                    oldPlacements,
                    oldOrders,
                    oldPreview,
                    oldSession,
                    oldCustomerCapacity,
                    coordinator,
                    saveManager);
                IsRestorationVerified = false;
                saveManager.SuspendLifecycleSaving();
                Debug.LogError(
                    "SESSION REPLACEMENT FAILED | " +
                    "Startup coordinator refused the completed session.");
                return false;
            }

            if (commitBeforeFinalizing != null)
            {
                bool committed;
                try
                {
                    committed = commitBeforeFinalizing();
                }
                catch (Exception exception)
                {
                    TryRestorePreviousLiveSession(
                        oldPlacements,
                        oldOrders,
                        oldPreview,
                        oldSession,
                        oldCustomerCapacity,
                        coordinator,
                        saveManager);
                    Debug.LogError(
                        "SESSION REPLACEMENT FAILED | " +
                        "The transaction commit callback threw before completion.\n" +
                        exception);
                    return false;
                }

                if (!committed)
                {
                    TryRestorePreviousLiveSession(
                        oldPlacements,
                        oldOrders,
                        oldPreview,
                        oldSession,
                        oldCustomerCapacity,
                        coordinator,
                        saveManager);
                    Debug.LogError(
                        "SESSION REPLACEMENT FAILED | " +
                        "The transaction commit callback rejected the fresh session.");
                    return false;
                }
            }

            foreach (DessertPlacement placement in oldPlacements)
                if (placement.Dessert != null)
                    DestroyDetachedDessert(placement.Dessert);

            hasRestoredAutomatically = true;
            try
            {
                gridManager.NotifyBoardChanged();
                shelfManager.NotifyShelfChanged();
                dessertSpawner.PublishNextDessertChanged();
                orderManager.PublishPreparedFreshSessionOrders();
            }
            catch (Exception exception)
            {
                Debug.LogError(
                    "SESSION REPLACEMENT COMMITTED | " +
                    "A post-commit gameplay notification failed.\n" +
                    exception);
            }
            return true;
        }
        finally
        {
            replacementSessionPreparedForCommit = false;
            restorationInProgress = false;
        }
    }

    private List<DessertPlacement> CaptureDessertPlacements()
    {
        var placements = new List<DessertPlacement>();
        foreach (GridCell cell in gridManager.Cells)
        {
            if (cell != null && cell.CurrentDessert != null)
            {
                placements.Add(new DessertPlacement
                {
                    Dessert = cell.CurrentDessert,
                    Cell = cell
                });
            }
        }

        foreach (ShelfSlot slot in shelfManager.Slots)
        {
            if (slot != null && slot.CurrentDessert != null)
            {
                placements.Add(new DessertPlacement
                {
                    Dessert = slot.CurrentDessert,
                    Slot = slot
                });
            }
        }

        return placements;
    }

    private static void DetachAndDisableDesserts(
        IReadOnlyList<DessertPlacement> placements)
    {
        foreach (DessertPlacement placement in placements)
        {
            if (placement.Dessert == null)
                continue;
            if (placement.Cell != null)
                placement.Cell.RemoveDessert(placement.Dessert);
            if (placement.Slot != null)
                placement.Slot.RemoveDessert(placement.Dessert);
            placement.Dessert.ClearLocation();
            placement.Dessert.gameObject.SetActive(false);
        }
    }

    private void RestorePreviousLiveSession(
        IReadOnlyList<DessertPlacement> oldPlacements,
        OrderManager.SessionReplacementState oldOrders,
        DessertDefinition oldPreview,
        MergeSessionData oldSession,
        int oldCustomerCapacity)
    {
        foreach (GridCell cell in gridManager.Cells)
        {
            Dessert dessert = cell != null ? cell.CurrentDessert : null;
            if (dessert == null)
                continue;
            cell.RemoveDessert(dessert);
            dessert.ClearLocation();
            dessert.gameObject.SetActive(false);
            DestroyDetachedDessert(dessert);
        }
        foreach (ShelfSlot slot in shelfManager.Slots)
        {
            Dessert dessert = slot != null ? slot.CurrentDessert : null;
            if (dessert == null)
                continue;
            slot.RemoveDessert(dessert);
            dessert.ClearLocation();
            dessert.gameObject.SetActive(false);
            DestroyDetachedDessert(dessert);
        }

        foreach (DessertPlacement placement in oldPlacements)
        {
            Dessert dessert = placement.Dessert;
            if (dessert == null)
                continue;
            dessert.gameObject.SetActive(true);
            if (placement.Cell != null)
                placement.Cell.PlaceDessert(dessert);
            else if (placement.Slot != null &&
                     !placement.Slot.TryStoreDessert(dessert))
                throw new InvalidOperationException(
                    "A prior shelf dessert could not be restored.");
        }

        orderManager.RestoreSessionReplacementState(oldOrders);
        if (!dessertSpawner.SetFreshSessionPreview(oldPreview, false))
            throw new InvalidOperationException(
                "The prior Oven preview could not be restored.");

        MergeSessionManager.Instance.SaveSession(oldSession);
        SaveManager.Instance.RecordSessionCustomerCapacity(
            MergeSessionManager.Instance.SessionData,
            oldCustomerCapacity);
    }

    private bool TryRestorePreviousLiveSession(
        IReadOnlyList<DessertPlacement> oldPlacements,
        OrderManager.SessionReplacementState oldOrders,
        DessertDefinition oldPreview,
        MergeSessionData oldSession,
        int oldCustomerCapacity,
        GameStartupCoordinator coordinator,
        SaveManager saveManager)
    {
        try
        {
            RestorePreviousLiveSession(
                oldPlacements,
                oldOrders,
                oldPreview,
                oldSession,
                oldCustomerCapacity);
            RestoreGameplayReadiness(coordinator, saveManager);
            return IsRestorationVerified;
        }
        catch (Exception exception)
        {
            IsRestorationVerified = false;
            saveManager.SuspendLifecycleSaving();
            coordinator.ReportGameplayRestorationFailure(
                "The previous merge session could not be restored after replacement failed.");
            Debug.LogError(
                "SESSION REPLACEMENT ROLLBACK FAILED | " +
                "Lifecycle saving was suspended.\n" +
                exception);
            return false;
        }
    }

    private void RestoreGameplayReadiness(
        GameStartupCoordinator coordinator,
        SaveManager saveManager)
    {
        IsRestorationVerified = true;
        if (!coordinator.ConfirmGameplayRestoration(this))
        {
            IsRestorationVerified = false;
            saveManager.SuspendLifecycleSaving();
            Debug.LogError(
                "SESSION REPLACEMENT ROLLBACK | " +
                "The prior session was restored, but startup readiness could not be re-established.");
        }
    }

    private void DestroyDetachedDessert(Dessert dessert)
    {
        if (Application.isPlaying)
            Destroy(dessert.gameObject);
        else
            DestroyImmediate(dessert.gameObject);
    }
    // ==================================================
    // CAPTURE BOARD
    // ==================================================
    private void CaptureBoard(
        MergeSessionData data)
    {
        var cells =
            gridManager.Cells;
        for (int i = 0;
             i < cells.Count;
             i++)
        {
            GridCell cell =
                cells[i];
            if (cell == null ||
                cell.IsEmpty)
            {
                continue;
            }
            Dessert dessert =
                cell.CurrentDessert;
            if (dessert == null ||
                dessert.Definition == null)
            {
                continue;
            }
            data.boardDesserts.Add(
                new BoardDessertState(
                    i,
                    dessert.Definition.Tier
                )
            );
        }
    }
    // ==================================================
    // CAPTURE SHELF
    // ==================================================
    private void CaptureShelf(
        MergeSessionData data)
    {
        var slots =
            shelfManager.Slots;
        for (int i = 0;
             i < slots.Count;
             i++)
        {
            ShelfSlot slot =
                slots[i];
            if (slot == null ||
                slot.IsEmpty)
            {
                continue;
            }
            Dessert dessert =
                slot.CurrentDessert;
            if (dessert == null ||
                dessert.Definition == null)
            {
                continue;
            }
            data.shelfDesserts.Add(
                new ShelfDessertState(
                    i,
                    dessert.Definition.Tier
                )
            );
        }
    }
    // ==================================================
    // CAPTURE ORDERS
    // ==================================================
    private void CaptureOrders(
        MergeSessionData data)
    {
        var orders =
            orderManager.CustomerOrders;
        for (int i = 0;
             i < orders.Count;
             i++)
        {
            CustomerOrder order =
                orders[i];
            if (order == null ||
                !order.IsValid)
            {
                continue;
            }
            data.customerOrders.Add(
                new CustomerOrderState(i, order)
            );
        }
        data.nextOrderId =
            orderManager.NextOrderId;
    }
    // ==================================================
    // CAPTURE NEXT DESSERT
    // ==================================================
    private void CaptureNextDessert(
        MergeSessionData data)
    {
        DessertDefinition nextDessert =
            dessertSpawner.NextDessert;
        if (nextDessert == null)
        {
            data.nextDessertTier = -1;
            Debug.LogWarning(
                "SESSION CAPTURE | " +
                "No Next Dessert currently exists."
            );
            return;
        }
        data.nextDessertTier =
            nextDessert.Tier;
        Debug.Log(
            $"SESSION NEXT DESSERT CAPTURED | " +
            $"{nextDessert.DisplayName} | " +
            $"Tier {nextDessert.Tier}"
        );
    }
    // ==================================================
    // RESTORE
    // ==================================================
    public void RestoreSession()
    {
        TryRestoreSession();
    }
    public bool TryRestoreSession()
    {
        if (!isActiveAndEnabled) return false;
        if (restorationInProgress) return false;
        ApplicationReadinessCoordinator applicationReadiness =
            ApplicationReadinessCoordinator.Instance;
        if (applicationReadiness == null ||
            !applicationReadiness.IsReady)
            return false;
        var coordinator = GameStartupCoordinator.Instance;
        if (coordinator == null || !coordinator.IsStartupComplete)
            return FailRestoration("Persistent startup has not succeeded.");
        SaveManager.Instance?.SuspendLifecycleSaving();
        IsRestorationVerified = false;
        LastRestorationError = null;
        restorationInProgress = true;
        departurePrepared = false;
        try
        {
            ResolveReferences();
            if (gridManager == null || shelfManager == null ||
                dessertSpawner == null || orderManager == null ||
                MergeSessionManager.Instance == null)
                return FailRestoration("A required gameplay reference is missing.");
            MergeSessionData verifiedSnapshot = null;
            if (MergeSessionManager.Instance.HasSession)
            {
                var data = MergeSessionManager.Instance.SessionData;
                if (!ValidateExpectedState(data, out string reason))
                    return FailRestoration(reason);
                if (SaveManager.Instance == null ||
                    !SaveManager.Instance.TryGetSessionCustomerCapacity(data, orderManager.ActiveCustomerCount,
                        out int savedCapacity))
                    return FailRestoration("Saved customer capacity is unknown. Migrate the legacy save using its verified backup capacity.");
                if (SaveManager.Instance.HasPendingCompatibilityMigration &&
                    savedCapacity == 4)
                {
                    data = CopySession(data);
                    if (!TryRetireLegacyFourthTable(data, out reason))
                        return FailRestoration(reason);
                    savedCapacity = 3;
                }
                if (!orderManager.ValidateSavedOrders(data.customerOrders, data.nextOrderId, savedCapacity, out reason))
                    return FailRestoration(reason);
                data = CopySession(data);
                int restoredCounter = data.nextOrderId;
                int currentCapacity = orderManager.ActiveCustomerCount;
                // Freeze the target before callbacks can mutate persistent state.
                string target = RestorationVerification.Fingerprint(data);
                RestoreBoard(data);
                RestoreShelf(data);
                if (!orderManager.RestoreCustomerOrders(data.customerOrders, data.nextOrderId, savedCapacity))
                    return FailRestoration("Exact order restoration failed.");
                if (!SaveManager.Instance.RestoreSelectedSpawnPool(dessertSpawner))
                    return FailRestoration("The selected Oven spawn pool could not be restored.");
                RestoreNextDessert(data);
                gridManager.NotifyBoardChanged();
                shelfManager.NotifyShelfChanged();
                if (!ValidateLiveState(out reason, savedCapacity)) return FailRestoration(reason);
                var actual = new MergeSessionData();
                CaptureBoard(actual);
                CaptureShelf(actual);
                CaptureOrders(actual);
                CaptureNextDessert(actual);
                if (!RestorationVerification.MatchesFingerprint(target, actual))
                    return FailRestoration(
                        "Live board, shelf, orders, order counter or next dessert differs " +
                        "from the saved session. " +
                        RestorationVerification.DescribeDifference(data, actual));
                // Expansion happens only after the entire saved snapshot matched exactly.
                if (!orderManager.ExpandRestoredCustomerCapacity(savedCapacity))
                    return FailRestoration("New customer slots could not be generated.");
                if (orderManager.ActiveCustomerCount != currentCapacity ||
                    !ValidateLiveState(out reason))
                    return FailRestoration(reason ?? "Customer capacity changed during restoration.");
                var expanded = new MergeSessionData();
                CaptureBoard(expanded);
                CaptureShelf(expanded);
                CaptureOrders(expanded);
                CaptureNextDessert(expanded);
                if ((long)expanded.nextOrderId != (long)restoredCounter + currentCapacity - savedCapacity)
                    return FailRestoration("Expansion changed the order counter unexpectedly.");
                foreach (var row in expanded.customerOrders)
                    if (row.customerIndex >= savedCapacity &&
                        (long)row.orderId != (long)restoredCounter + row.customerIndex - savedCapacity)
                        return FailRestoration("Expansion generated an unexpected order ID.");
                var projection = CopySession(expanded);
                projection.customerOrders.RemoveAll(row => row.customerIndex >= savedCapacity);
                projection.nextOrderId = restoredCounter;
                if (!string.Equals(target, RestorationVerification.Fingerprint(projection), StringComparison.Ordinal))
                    return FailRestoration("Expansion modified previously saved gameplay.");
                verifiedSnapshot = expanded;
            }
            else
            {
                if (!ValidateLiveState(out string reason)) return FailRestoration(reason);
                if (dessertSpawner.NextDessert == null)
                    return FailRestoration("A new game requires an initialized next dessert.");
            }
            IsRestorationVerified = true;
            if (!coordinator.ConfirmGameplayRestoration(this))
                return FailRestoration("The coordinator refused gameplay readiness.");
            if (verifiedSnapshot != null)
            {
                MergeSessionManager.Instance.SaveSession(verifiedSnapshot);
                SaveManager.Instance.RecordSessionCustomerCapacity(
                    MergeSessionManager.Instance.SessionData,
                    orderManager.ActiveCustomerCount,
                    dessertSpawner.SelectedSpawnPoolId);
            }
            if (SaveManager.Instance != null &&
                SaveManager.Instance.HasPendingCompatibilityMigration)
            {
                bool migrationSaveSucceeded =
                    TrySaveCompatibilityMigration(
                        SaveManager.Instance.SaveCurrentGame);
                if (!migrationSaveSucceeded)
                {
                    return FailRestoration(
                        "The migrated Save V2 snapshot could not be persisted through the validated save path.");
                }
            }
            hasRestoredAutomatically = true;
            Debug.Log("MERGE SESSION VERIFIED | Board, shelf, orders and next dessert are ready.");
            return true;
        }
        catch (Exception exception)
        {
            return FailRestoration(exception.ToString());
        }
        finally { restorationInProgress = false; }
    }

    private bool TrySaveCompatibilityMigration(Func<bool> saveMigration)
    {
        if (saveMigration == null)
            throw new ArgumentNullException(nameof(saveMigration));

        allowVerifiedMigrationCapture = true;
        try
        {
            return saveMigration();
        }
        finally
        {
            allowVerifiedMigrationCapture = false;
        }
    }

    private static MergeSessionData CopySession(MergeSessionData source)
    {
        var copy = new MergeSessionData();
        foreach (var row in source.boardDesserts)
            copy.boardDesserts.Add(new BoardDessertState(row.cellIndex, row.dessertTier));
        foreach (var row in source.shelfDesserts)
            copy.shelfDesserts.Add(new ShelfDessertState(row.slotIndex, row.dessertTier));
        foreach (var row in source.customerOrders)
            copy.customerOrders.Add(row.Clone());
        copy.nextOrderId = source.nextOrderId;
        copy.nextDessertTier = source.nextDessertTier;
        return copy;
    }

    private bool TryRetireLegacyFourthTable(
        MergeSessionData data,
        out string reason)
    {
        reason = null;
        if (data == null ||
            data.customerOrders == null ||
            data.customerOrders.Count != 4 ||
            data.nextOrderId <= 0)
        {
            reason = "Legacy four-Table session is incomplete.";
            return false;
        }

        var indices = new HashSet<int>();
        var orderIds = new HashSet<int>();
        foreach (CustomerOrderState state in data.customerOrders)
        {
            if (state == null ||
                state.customerIndex < 0 ||
                state.customerIndex >= 4 ||
                !indices.Add(state.customerIndex) ||
                state.orderId <= 0 ||
                state.orderId >= data.nextOrderId ||
                !orderIds.Add(state.orderId))
            {
                reason = "Legacy four-Table order identities are invalid.";
                return false;
            }

            CustomerOrder order =
                state.CreateOrder(dessertSpawner);
            if (order == null || !order.IsValid ||
                order.OrderId != state.orderId)
            {
                reason = "Legacy four-Table session contains an invalid order.";
                return false;
            }
        }

        data.customerOrders.RemoveAll(
            state => state.customerIndex == 3);
        if (data.customerOrders.Count != 3)
        {
            reason = "Legacy fourth Table could not be retired safely.";
            return false;
        }

        return true;
    }

    private bool ValidateExpectedState(MergeSessionData data, out string reason)
    {
        reason = null;
        if (data == null || data.boardDesserts == null || data.shelfDesserts == null ||
            data.customerOrders == null || data.nextOrderId <= 0 ||
            (data.nextDessertTier != -1 && data.nextDessertTier <= 0))
        { reason = "Saved session contains missing or invalid data."; return false; }
        if (gridManager.Cells == null || shelfManager.Slots == null)
        { reason = "Board or shelf has not initialized."; return false; }
        var cells = new HashSet<int>();
        foreach (var state in data.boardDesserts)
        {
            if (state == null || state.dessertTier <= 0 || state.cellIndex < 0 ||
                state.cellIndex >= gridManager.Cells.Count || !cells.Add(state.cellIndex) ||
                gridManager.Cells[state.cellIndex] == null ||
                !gridManager.Cells[state.cellIndex].IsUnlocked)
            { reason = "Saved board contains an invalid, locked or duplicate cell."; return false; }
        }
        var slots = new HashSet<int>();
        foreach (var state in data.shelfDesserts)
        {
            if (state == null || state.dessertTier <= 0 || state.slotIndex < 0 ||
                state.slotIndex >= shelfManager.Slots.Count || !slots.Add(state.slotIndex) ||
                shelfManager.Slots[state.slotIndex] == null ||
                !shelfManager.Slots[state.slotIndex].IsUnlocked)
            { reason = "Saved shelf contains an invalid, locked or duplicate slot."; return false; }
        }
        foreach (var state in data.customerOrders)
            if (state == null)
            { reason = "Saved order is null."; return false; }
        return true;
    }
    private bool ValidateLiveState(out string reason, int restoredCapacity = -1)
    {
        reason = null;
        ResolveReferences();
        var progression = PlayerProgressionManager.Instance;
        if (gridManager == null || shelfManager == null || dessertSpawner == null ||
            orderManager == null || progression == null || gridManager.Cells == null ||
            shelfManager.Slots == null || orderManager.CustomerOrders == null)
        { reason = "Gameplay dependencies are not initialized."; return false; }
        if (!progression.ValidateRestorationDefinitions(out reason)) return false;
        var desserts = new HashSet<Dessert>();
        int unlockedCells = 0, unlockedSlots = 0, validOrders = 0;
        foreach (var cell in gridManager.Cells)
        {
            if (cell == null) { reason = "Board contains a null cell."; return false; }
            if (cell.IsUnlocked) unlockedCells++;
            var dessert = cell.CurrentDessert;
            if (cell.IsEmpty != (dessert == null) ||
                (dessert != null && (!cell.IsUnlocked || dessert.Definition == null ||
                 dessert.Definition.Tier <= 0 || !desserts.Add(dessert))))
            { reason = "Board occupancy, dessert definition or ownership is invalid."; return false; }
        }
        foreach (var slot in shelfManager.Slots)
        {
            if (slot == null) { reason = "Shelf contains a null slot."; return false; }
            if (slot.IsUnlocked) unlockedSlots++;
            var dessert = slot.CurrentDessert;
            if (slot.IsEmpty != (dessert == null) ||
                (dessert != null && (!slot.IsUnlocked || dessert.Definition == null ||
                 dessert.Definition.Tier <= 0 || !desserts.Add(dessert))))
            { reason = "Shelf occupancy, dessert definition or ownership is invalid."; return false; }
        }
        var orderIds = new HashSet<int>();
        int expectedOrders = restoredCapacity < 0 ? progression.ActiveCustomerOrders : restoredCapacity;
        if (orderManager.CustomerOrders.Count != 3)
        { reason = "Order slot layout is invalid."; return false; }
        for (int i = 0; i < orderManager.CustomerOrders.Count; i++)
        {
            var order = orderManager.CustomerOrders[i];
            if ((i < expectedOrders) != (order != null))
            { reason = "Order is absent from an expected slot or present in a locked slot."; return false; }
            if (order == null) continue;
            if (!order.IsValid || order.OrderId <= 0 ||
                !orderIds.Add(order.OrderId) || orderManager.NextOrderId <= order.OrderId)
            { reason = "Order definition, identity or next order counter is invalid."; return false; }
            validOrders++;
        }
        if (unlockedCells != progression.ActiveBoardCells ||
            unlockedSlots != progression.ShelfCapacity ||
            validOrders != expectedOrders || orderManager.NextOrderId <= 0)
        { reason = "Live capacities or active order count disagree with progression."; return false; }
        if (dessertSpawner.NextDessert != null &&
            !progression.IsDessertTierUnlocked(dessertSpawner.NextDessert.Tier))
        { reason = "Next dessert is not an unlocked tier."; return false; }
        return true;
    }
    // ==================================================
    // RESTORE BOARD
    // ==================================================
    private void RestoreBoard(
        MergeSessionData data)
    {
        var cells =
            gridManager.Cells;
        foreach (
            BoardDessertState state
            in data.boardDesserts)
        {
            if (state == null)
                continue;
            if (state.cellIndex < 0 ||
                state.cellIndex >= cells.Count)
            {
                Debug.LogWarning(
                    $"RESTORE BOARD SKIPPED | " +
                    $"Invalid Cell Index " +
                    $"{state.cellIndex}."
                );
                continue;
            }
            GridCell cell =
                cells[state.cellIndex];
            if (cell == null)
                continue;
            if (!cell.IsUnlocked)
            {
                Debug.LogWarning(
                    $"RESTORE BOARD SKIPPED | " +
                    $"Cell {state.cellIndex} " +
                    "is currently locked."
                );
                continue;
            }
            if (!cell.IsEmpty)
            {
                Debug.LogWarning(
                    $"RESTORE BOARD SKIPPED | " +
                    $"Cell {state.cellIndex} " +
                    "is already occupied."
                );
                continue;
            }
            Dessert dessert =
                dessertSpawner
                    .SpawnDessertOnBoardForRestore(
                        state.dessertTier,
                        cell
                    );
            if (dessert == null)
            {
                Debug.LogWarning(
                    $"RESTORE BOARD FAILED | " +
                    $"Cell {state.cellIndex} | " +
                    $"Tier {state.dessertTier}"
                );
                continue;
            }
            Debug.Log(
                $"RESTORE BOARD | " +
                $"Cell {state.cellIndex} | " +
                $"Tier {state.dessertTier}"
            );
        }
    }
    // ==================================================
    // RESTORE SHELF
    // ==================================================
    private void RestoreShelf(
        MergeSessionData data)
    {
        var slots =
            shelfManager.Slots;
        foreach (
            ShelfDessertState state
            in data.shelfDesserts)
        {
            if (state == null)
                continue;
            if (state.slotIndex < 0 ||
                state.slotIndex >= slots.Count)
            {
                Debug.LogWarning(
                    $"RESTORE SHELF SKIPPED | " +
                    $"Invalid Slot Index " +
                    $"{state.slotIndex}."
                );
                continue;
            }
            ShelfSlot slot =
                slots[state.slotIndex];
            if (slot == null)
                continue;
            if (!slot.IsUnlocked)
            {
                Debug.LogWarning(
                    $"RESTORE SHELF SKIPPED | " +
                    $"Slot {state.slotIndex} " +
                    "is currently locked."
                );
                continue;
            }
            if (!slot.IsEmpty)
            {
                Debug.LogWarning(
                    $"RESTORE SHELF SKIPPED | " +
                    $"Slot {state.slotIndex} " +
                    "is already occupied."
                );
                continue;
            }
            Dessert dessert =
                dessertSpawner
                    .SpawnDessertOnShelfForRestore(
                        state.dessertTier,
                        slot
                    );
            if (dessert == null)
            {
                Debug.LogWarning(
                    $"RESTORE SHELF FAILED | " +
                    $"Slot {state.slotIndex} | " +
                    $"Tier {state.dessertTier}"
                );
                continue;
            }
            Debug.Log(
                $"RESTORE SHELF | " +
                $"Slot {state.slotIndex} | " +
                $"Tier {state.dessertTier}"
            );
        }
    }
    // ==================================================
    // RESTORE ORDERS
    // ==================================================
    private void RestoreOrders(
        MergeSessionData data)
    {
        orderManager.RestoreCustomerOrders(
            data.customerOrders,
            data.nextOrderId
        );
    }
    // ==================================================
    // RESTORE NEXT DESSERT
    // ==================================================
    private void RestoreNextDessert(
        MergeSessionData data)
    {
        if (data.nextDessertTier <= 0)
        {
            Debug.LogWarning(
                "NEXT DESSERT RESTORE SKIPPED | " +
                "No valid saved Next Dessert exists."
            );
            return;
        }
        dessertSpawner.RestoreNextDessert(
            data.nextDessertTier
        );
    }
    // ==================================================
    // REFERENCES
    // ==================================================
    private void ResolveReferences()
    {
        if (gridManager == null)
        {
            gridManager =
                FindAnyObjectByType<GridManager>();
        }
        if (shelfManager == null)
        {
            shelfManager =
                FindAnyObjectByType<ShelfManager>();
        }
        if (dessertSpawner == null)
        {
            dessertSpawner =
                FindAnyObjectByType<DessertSpawner>();
        }
        if (orderManager == null)
        {
            orderManager =
                FindAnyObjectByType<OrderManager>();
        }
    }
    // ==================================================
    // DEBUG
    // ==================================================
    [ContextMenu("Debug Capture Session")]
    private void DebugCaptureSession()
    {
        bool success =
            TryCaptureSession();
        if (success)
        {
            Debug.Log(
                "SESSION DEBUG | " +
                "Live gameplay capture succeeded."
            );
        }
        else
        {
            Debug.LogError(
                "SESSION DEBUG | " +
                "Live gameplay capture failed."
            );
        }
    }
    [ContextMenu("Debug Restore Session")]
    private void DebugRestoreSession()
    {
        RestoreSession();
    }
}
