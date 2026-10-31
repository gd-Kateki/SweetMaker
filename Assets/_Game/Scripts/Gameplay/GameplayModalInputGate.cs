using System;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public static class GameplayModalInputGate
{
    private static readonly Dictionary<EntityId, GameplayModalLease> ModalLeases =
        new Dictionary<EntityId, GameplayModalLease>();

    private static int activeGameplayOperations;

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
    private static void ResetRuntimeState()
    {
        ModalLeases.Clear();
        activeGameplayOperations = 0;
        BlockingStateChanged = null;
        SafeBoundaryReached = null;
    }

    /// <summary>Raised when blocking modal ownership starts or ends.</summary>
    public static event Action BlockingStateChanged;

    /// <summary>
    /// Raised when a committed gameplay operation reaches its safe boundary.
    /// Check IsSafeToOpen with the current modal lease in the callback.
    /// </summary>
    public static event Action SafeBoundaryReached;

    /// <summary>True while at least one active modal lease blocks gameplay.</summary>
    public static bool IsGameplayInputBlocked
    {
        get
        {
            ReleaseDestroyedOwners();
            if (SceneManager.GetActiveScene().name ==
                    SceneNavigationManager.MergeGameplayScene &&
                (ApplicationReadinessCoordinator.Instance == null ||
                 !ApplicationReadinessCoordinator.Instance.IsReady))
                return true;
            return ModalLeases.Count > 0;
        }
    }

    /// <summary>
    /// Acquires an idempotent blocking lease for an owner. Dispose the lease
    /// when that modal closes or its owner is disabled or destroyed.
    /// </summary>
    public static bool TryAcquireBlockingModal(
        MonoBehaviour owner,
        out GameplayModalLease lease)
    {
        lease = null;
        if (owner == null || !owner.isActiveAndEnabled)
            return false;

        ReleaseDestroyedOwners();
        EntityId ownerId = owner.GetEntityId();
        if (ModalLeases.TryGetValue(ownerId, out lease))
        {
            if (ReferenceEquals(lease.Owner, owner))
                return true;

            Release(lease);
        }

        bool wasBlocked = ModalLeases.Count > 0;
        lease = new GameplayModalLease(ownerId, owner);
        ModalLeases.Add(ownerId, lease);
        if (!wasBlocked)
            BlockingStateChanged?.Invoke();

        return true;
    }

    /// <summary>
    /// Returns true only for the current owner's lease and when all
    /// committed gameplay operations have reached their safe boundary.
    /// </summary>
    public static bool IsSafeToOpen(GameplayModalLease lease)
    {
        ReleaseDestroyedOwners();
        return IsActive(lease) && activeGameplayOperations == 0;
    }

    /// <summary>
    /// Begins a short-lived committed gameplay operation. New operations
    /// are rejected while any blocking modal owns a lease.
    /// </summary>
    public static bool TryBeginGameplayOperation(
        out GameplayOperationLease operation)
    {
        operation = null;
        if (IsGameplayInputBlocked)
            return false;

        activeGameplayOperations++;
        operation = new GameplayOperationLease();
        return true;
    }

    private static bool IsActive(GameplayModalLease lease)
    {
        return lease != null &&
               ModalLeases.TryGetValue(lease.OwnerId, out GameplayModalLease active) &&
               ReferenceEquals(active, lease);
    }

    private static void ReleaseDestroyedOwners()
    {
        if (ModalLeases.Count == 0)
            return;

        List<GameplayModalLease> destroyedLeases = null;
        foreach (GameplayModalLease lease in ModalLeases.Values)
        {
            if (lease.Owner == null ||
                !lease.Owner.isActiveAndEnabled)
            {
                if (destroyedLeases == null)
                    destroyedLeases = new List<GameplayModalLease>();
                destroyedLeases.Add(lease);
            }
        }

        if (destroyedLeases == null)
            return;

        foreach (GameplayModalLease lease in destroyedLeases)
            Release(lease);
    }

    private static void Release(GameplayModalLease lease)
    {
        if (!IsActive(lease))
            return;

        ModalLeases.Remove(lease.OwnerId);
        lease.MarkReleased();
        if (ModalLeases.Count == 0)
            BlockingStateChanged?.Invoke();
    }

    private static void EndGameplayOperation()
    {
        if (activeGameplayOperations <= 0)
        {
            Debug.LogError(
                "GameplayModalInputGate received an unmatched operation release.");
            return;
        }

        activeGameplayOperations--;
        if (activeGameplayOperations == 0)
            SafeBoundaryReached?.Invoke();
    }

    public sealed class GameplayModalLease : IDisposable
    {
        private bool isReleased;

        internal EntityId OwnerId { get; }
        internal MonoBehaviour Owner { get; }

        internal GameplayModalLease(EntityId ownerId, MonoBehaviour owner)
        {
            OwnerId = ownerId;
            Owner = owner;
        }

        public bool IsActive =>
            !isReleased && GameplayModalInputGate.IsActive(this);

        public void Dispose()
        {
            GameplayModalInputGate.Release(this);
        }

        internal void MarkReleased()
        {
            isReleased = true;
        }
    }

    public sealed class GameplayOperationLease : IDisposable
    {
        private bool isReleased;

        public void Dispose()
        {
            if (isReleased)
                return;

            isReleased = true;
            EndGameplayOperation();
        }
    }
}
