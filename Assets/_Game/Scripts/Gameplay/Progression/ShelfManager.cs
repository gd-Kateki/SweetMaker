using System;
using System.Collections.Generic;
using UnityEngine;

public class ShelfManager : MonoBehaviour
{
    [Header("References")]
    [SerializeField]
    private PlayerProgressionManager
        progressionManager;

    [SerializeField]
    private ShelfSlot[] slots;

    public event Action ShelfChanged;

    public IReadOnlyList<ShelfSlot> Slots =>
        slots;

    // ==================================================
    // COUNTS
    // ==================================================

    public int TotalSlotCount
    {
        get
        {
            if (slots == null)
                return 0;

            return slots.Length;
        }
    }

    public int UnlockedSlotCount
    {
        get
        {
            if (slots == null)
                return 0;

            int count = 0;

            foreach (ShelfSlot slot in slots)
            {
                if (slot != null &&
                    slot.IsUnlocked)
                {
                    count++;
                }
            }

            return count;
        }
    }

    public int OccupiedSlotCount
    {
        get
        {
            if (slots == null)
                return 0;

            int count = 0;

            foreach (ShelfSlot slot in slots)
            {
                if (slot != null &&
                    slot.IsUnlocked &&
                    !slot.IsEmpty)
                {
                    count++;
                }
            }

            return count;
        }
    }

    public int EmptySlotCount =>
        UnlockedSlotCount -
        OccupiedSlotCount;

    // ==================================================
    // UNITY
    // ==================================================

    private void Start()
    {
        ResolveReferences();

        if (progressionManager == null)
        {
            Debug.LogError(
                "ShelfManager: " +
                "PlayerProgressionManager " +
                "could not be found."
            );

            return;
        }

        progressionManager.UpgradeLevelChanged +=
            HandleUpgradeLevelChanged;

        ApplyShelfProgression();
    }

    private void OnDestroy()
    {
        if (progressionManager != null)
        {
            progressionManager.UpgradeLevelChanged -=
                HandleUpgradeLevelChanged;
        }
    }

    // ==================================================
    // REFERENCES
    // ==================================================

    private void ResolveReferences()
    {
        /*
         * Always prefer the singleton.
         *
         * This ensures the Shelf uses the persistent
         * progression manager that survived the scene
         * transition from MainBakery.
         */
        if (PlayerProgressionManager.Instance != null)
        {
            progressionManager =
                PlayerProgressionManager.Instance;
        }
        else if (progressionManager == null)
        {
            progressionManager =
                FindAnyObjectByType<
                    PlayerProgressionManager>();
        }

        if (slots == null ||
            slots.Length == 0)
        {
            slots =
                GetComponentsInChildren<
                    ShelfSlot>(true);
        }
    }

    // ==================================================
    // PROGRESSION
    // ==================================================

    private void HandleUpgradeLevelChanged(
        UpgradeType type,
        int newLevel)
    {
        if (type != UpgradeType.Shelf)
            return;

        ApplyShelfProgression();

        Debug.Log(
            $"SHELF UPGRADE | " +
            $"Level {newLevel} | " +
            $"Unlocked Slots: " +
            $"{UnlockedSlotCount}"
        );
    }

    private void ApplyShelfProgression()
    {
        if (progressionManager == null)
        {
            Debug.LogError(
                "SHELF PROGRESSION | " +
                "ProgressionManager is missing."
            );

            return;
        }

        if (slots == null ||
            slots.Length == 0)
        {
            Debug.LogError(
                "SHELF PROGRESSION | " +
                "No ShelfSlots were found."
            );

            return;
        }

        int requestedSlots =
            progressionManager.ShelfCapacity;

        int unlockedSlots =
            Mathf.Clamp(
                requestedSlots,
                0,
                slots.Length
            );

        Debug.Log(
            $"SHELF APPLY | " +
            $"Progression Level: " +
            $"{progressionManager.ShelfLevel} | " +
            $"Requested Capacity: " +
            $"{requestedSlots} | " +
            $"Physical Slots: " +
            $"{slots.Length}"
        );

        for (int i = 0;
             i < slots.Length;
             i++)
        {
            ShelfSlot slot =
                slots[i];

            if (slot == null)
                continue;

            bool shouldUnlock =
                i < unlockedSlots;

            slot.SetUnlocked(
                shouldUnlock
            );

            Debug.Log(
                $"SHELF SLOT {i + 1} | " +
                $"Unlocked: " +
                $"{shouldUnlock}"
            );
        }

        NotifyShelfChanged();

        Debug.Log(
            $"SHELF PROGRESSION | " +
            $"Level " +
            $"{progressionManager.ShelfLevel} | " +
            $"Unlocked: " +
            $"{UnlockedSlotCount}/" +
            $"{TotalSlotCount}"
        );
    }

    // ==================================================
    // SLOT LOOKUP
    // ==================================================

    public ShelfSlot FindSlotAtPosition(
        Vector3 worldPosition)
    {
        Collider2D[] hits =
            Physics2D.OverlapPointAll(
                worldPosition
            );

        foreach (Collider2D hit in hits)
        {
            if (hit == null)
                continue;

            ShelfSlot slot =
                hit.GetComponent<ShelfSlot>();

            if (slot != null)
                return slot;
        }

        return null;
    }

    // ==================================================
    // NOTIFICATION
    // ==================================================

    public void NotifyShelfChanged()
    {
        ShelfChanged?.Invoke();
    }

    // ==================================================
    // DEBUG
    // ==================================================

    [ContextMenu("Debug Shelf State")]
    private void DebugShelfState()
    {
        ResolveReferences();

        Debug.Log(
            $"SHELF STATE | " +
            $"Progression Level: " +
            $"{progressionManager?.ShelfLevel} | " +
            $"Requested Capacity: " +
            $"{progressionManager?.ShelfCapacity} | " +
            $"Total: {TotalSlotCount} | " +
            $"Unlocked: {UnlockedSlotCount} | " +
            $"Occupied: {OccupiedSlotCount} | " +
            $"Empty: {EmptySlotCount}"
        );
    }
}