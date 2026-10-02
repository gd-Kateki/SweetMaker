using System;
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

            foreach (
                ShelfSlot slot
                in slots)
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

            foreach (
                ShelfSlot slot
                in slots)
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

        progressionManager
            .UpgradeLevelChanged +=
                HandleUpgradeLevelChanged;

        ApplyShelfProgression();
    }

    private void OnDestroy()
    {
        if (progressionManager != null)
        {
            progressionManager
                .UpgradeLevelChanged -=
                    HandleUpgradeLevelChanged;
        }
    }

    private void ResolveReferences()
    {
        if (progressionManager == null)
        {
            progressionManager =
                FindFirstObjectByType<
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

    private void HandleUpgradeLevelChanged(
        UpgradeType type,
        int newLevel)
    {
        if (type !=
            UpgradeType.Shelf)
        {
            return;
        }

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
        if (progressionManager == null ||
            slots == null)
        {
            return;
        }

        int requestedSlots =
            progressionManager
                .ShelfCapacity;

        int unlockedSlots =
            Mathf.Clamp(
                requestedSlots,
                0,
                slots.Length
            );

        for (int i = 0;
             i < slots.Length;
             i++)
        {
            ShelfSlot slot =
                slots[i];

            if (slot == null)
                continue;

            slot.SetUnlocked(
                i < unlockedSlots
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

    public ShelfSlot FindSlotAtPosition(
        Vector3 worldPosition)
    {
        Collider2D[] hits =
            Physics2D.OverlapPointAll(
                worldPosition
            );

        foreach (
            Collider2D hit
            in hits)
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

    public void NotifyShelfChanged()
    {
        ShelfChanged?.Invoke();
    }

    [ContextMenu("Debug Shelf State")]
    private void DebugShelfState()
    {
        Debug.Log(
            $"SHELF STATE | " +
            $"Total: {TotalSlotCount} | " +
            $"Unlocked: {UnlockedSlotCount} | " +
            $"Occupied: {OccupiedSlotCount} | " +
            $"Empty: {EmptySlotCount}"
        );
    }
}