using System.Collections;
using UnityEngine;
using UnityEngine.EventSystems;

[RequireComponent(typeof(Dessert))]
public class DessertDragHandler :
    MonoBehaviour,
    IPointerDownHandler,
    IDragHandler,
    IPointerUpHandler
{
    [Header("References")]
    [SerializeField]
    private DessertSpawner dessertSpawner;

    [SerializeField]
    private GridManager gridManager;

    [SerializeField]
    private ShelfManager shelfManager;

    [SerializeField]
    private PlayerProgressionManager progressionManager;

    [Header("Dragging")]
    [SerializeField]
    private int draggingSortingOrder = 100;

    private Dessert dessert;
    private DessertAnimator dessertAnimator;
    private Collider2D dessertCollider;
    private Camera mainCamera;

    // The location where this drag started.
    private GridCell originCell;
    private ShelfSlot originShelfSlot;

    // Current visual highlight.
    private GridCell highlightedCell;
    private ShelfSlot highlightedShelfSlot;

    private bool isDragging;
    private bool isInteractionLocked;

    private void Awake()
    {
        dessert =
            GetComponent<Dessert>();

        dessertAnimator =
            GetComponent<DessertAnimator>();

        dessertCollider =
            GetComponent<Collider2D>();

        mainCamera =
            Camera.main;

        ResolveReferences();
    }

    private void ResolveReferences()
    {
        if (dessertSpawner == null)
        {
            dessertSpawner =
                FindAnyObjectByType<DessertSpawner>();
        }

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

        /*
         * PlayerProgressionManager persists between
         * scenes, so always prefer the singleton
         * carrying the player's actual progression.
         */
        if (PlayerProgressionManager.Instance != null)
        {
            progressionManager =
                PlayerProgressionManager.Instance;
        }
        else if (progressionManager == null)
        {
            progressionManager =
                FindFirstObjectByType<
                    PlayerProgressionManager>();
        }
    }

    // ==================================================
    // POINTER INPUT
    // ==================================================

    public void OnPointerDown(
        PointerEventData eventData)
    {
        if (isInteractionLocked)
            return;

        if (dessert == null)
            return;

        // Capture the actual location at the
        // beginning of this drag.
        originCell = null;
        originShelfSlot = null;

        switch (dessert.LocationType)
        {
            case DessertLocationType.Board:
            {
                if (dessert.CurrentCell == null)
                    return;

                if (!dessert.CurrentCell.IsUnlocked)
                    return;

                originCell =
                    dessert.CurrentCell;

                break;
            }

            case DessertLocationType.Shelf:
            {
                if (dessert.CurrentShelfSlot == null)
                    return;

                if (!dessert.CurrentShelfSlot.IsUnlocked)
                    return;

                originShelfSlot =
                    dessert.CurrentShelfSlot;

                break;
            }

            default:
                return;
        }

        isDragging = true;

        ClearHighlights();

        dessert.ApplyDraggingRendering(
            draggingSortingOrder
        );
    }

    public void OnDrag(
        PointerEventData eventData)
    {
        if (!isDragging ||
            isInteractionLocked)
        {
            return;
        }

        Vector3 pointerPosition =
            GetWorldPointerPosition(
                eventData
            );

        transform.position =
            pointerPosition;

        UpdateTargetHighlight(
            pointerPosition
        );
    }

    public void OnPointerUp(
        PointerEventData eventData)
    {
        if (!isDragging ||
            isInteractionLocked)
        {
            return;
        }

        isDragging = false;

        Vector3 pointerPosition =
            GetWorldPointerPosition(
                eventData
            );

        GridCell targetCell =
            FindGridCellAtPosition(
                pointerPosition
            );

        ShelfSlot targetShelfSlot =
            FindShelfSlotAtPosition(
                pointerPosition
            );

        ClearHighlights();

        // Shelf gets priority if colliders happen
        // to overlap visually.
        if (targetShelfSlot != null)
        {
            TryDropOnShelf(
                targetShelfSlot
            );

            return;
        }

        if (targetCell != null)
        {
            TryDropOnBoard(
                targetCell
            );

            return;
        }

        ReturnToOrigin();
    }

    // ==================================================
    // POINTER POSITION
    // ==================================================

    private Vector3 GetWorldPointerPosition(
        PointerEventData eventData)
    {
        if (mainCamera == null)
        {
            mainCamera =
                Camera.main;
        }

        if (mainCamera == null)
        {
            return transform.position;
        }

        Vector3 screenPosition =
            eventData.position;

        Vector3 worldPosition =
            mainCamera.ScreenToWorldPoint(
                screenPosition
            );

        worldPosition.z = 0f;

        return worldPosition;
    }

    // ==================================================
    // TARGET DETECTION
    // ==================================================

    private GridCell FindGridCellAtPosition(
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

            GridCell cell =
                hit.GetComponent<GridCell>();

            if (cell != null)
                return cell;
        }

        return null;
    }

    private ShelfSlot FindShelfSlotAtPosition(
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
    // TARGET HIGHLIGHT
    // ==================================================

    private void UpdateTargetHighlight(
        Vector3 pointerPosition)
    {
        GridCell targetCell =
            FindGridCellAtPosition(
                pointerPosition
            );

        ShelfSlot targetShelfSlot =
            FindShelfSlotAtPosition(
                pointerPosition
            );

        // Shelf gets priority if both are detected.
        if (targetShelfSlot != null)
        {
            UpdateShelfHighlight(
                targetShelfSlot
            );

            return;
        }

        if (targetCell != null)
        {
            UpdateBoardHighlight(
                targetCell
            );

            return;
        }

        ClearHighlights();
    }

    private void UpdateBoardHighlight(
        GridCell targetCell)
    {
        if (highlightedCell == targetCell &&
            highlightedShelfSlot == null)
        {
            return;
        }

        ClearHighlights();

        if (targetCell == null)
            return;

        highlightedCell =
            targetCell;

        if (!targetCell.IsUnlocked)
            return;

        // Board-origin drag.
        if (originCell != null)
        {
            if (targetCell == originCell)
                return;

            if (targetCell.IsEmpty)
            {
                targetCell.ShowValidHighlight();
                return;
            }

            Dessert targetDessert =
                targetCell.CurrentDessert;

            if (targetDessert == null ||
                targetDessert == dessert)
            {
                return;
            }

            if (targetDessert.Tier ==
                dessert.Tier)
            {
                int resultingTier =
                    dessert.Tier + 1;

                if (IsMergeTierUnlocked(
                        resultingTier))
                {
                    targetCell
                        .ShowMergeHighlight();
                }
                else
                {
                    targetCell
                        .ShowInvalidHighlight();
                }

                return;
            }

            targetCell
                .ShowInvalidHighlight();

            return;
        }

        // Shelf-origin drag.
        //
        // Shelf desserts may only be returned
        // to an EMPTY board cell for now.
        if (originShelfSlot != null)
        {
            if (targetCell.IsEmpty)
            {
                targetCell
                    .ShowValidHighlight();
            }
            else
            {
                targetCell
                    .ShowInvalidHighlight();
            }
        }
    }

    private void UpdateShelfHighlight(
        ShelfSlot targetShelfSlot)
    {
        if (highlightedShelfSlot ==
                targetShelfSlot &&
            highlightedCell == null)
        {
            return;
        }

        ClearHighlights();

        if (targetShelfSlot == null)
            return;

        highlightedShelfSlot =
            targetShelfSlot;

        if (!targetShelfSlot.IsUnlocked)
            return;

        // Returning to the same Shelf slot.
        if (originShelfSlot ==
            targetShelfSlot)
        {
            return;
        }

        if (targetShelfSlot.IsEmpty)
        {
            targetShelfSlot
                .ShowValidHighlight();
        }
        else
        {
            targetShelfSlot
                .ShowInvalidHighlight();
        }
    }

    private void ClearHighlights()
    {
        if (highlightedCell != null)
        {
            highlightedCell
                .ClearHighlight();

            highlightedCell = null;
        }

        if (highlightedShelfSlot != null)
        {
            highlightedShelfSlot
                .ClearHighlight();

            highlightedShelfSlot = null;
        }
    }

    // ==================================================
    // DROP ON BOARD
    // ==================================================

    private void TryDropOnBoard(
        GridCell targetCell)
    {
        if (dessert == null)
            return;

        if (targetCell == null ||
            !targetCell.IsUnlocked)
        {
            ReturnToOrigin();
            return;
        }

        // ----------------------------------------------
        // BOARD -> BOARD
        // ----------------------------------------------

        if (originCell != null)
        {
            if (targetCell == originCell)
            {
                ReturnToOrigin();
                return;
            }

            if (targetCell.IsEmpty)
            {
                MoveBoardToBoard(
                    targetCell
                );

                return;
            }

            Dessert targetDessert =
                targetCell.CurrentDessert;

            if (targetDessert == null ||
                targetDessert == dessert)
            {
                ReturnToOrigin();
                return;
            }

            if (targetDessert.Tier !=
                dessert.Tier)
            {
                ReturnToOrigin();
                return;
            }

            int resultingTier =
                dessert.Tier + 1;

            if (!IsMergeTierUnlocked(
                    resultingTier))
            {
                Debug.Log(
                    $"MERGE LOCKED | " +
                    $"Tier {resultingTier} " +
                    "requires a higher Oven level."
                );

                ReturnToOrigin();
                return;
            }

            MergeWith(
                targetDessert,
                targetCell
            );

            return;
        }

        // ----------------------------------------------
        // SHELF -> BOARD
        // ----------------------------------------------

        if (originShelfSlot != null)
        {
            // Direct Shelf -> merge is intentionally
            // disabled for this version.
            if (!targetCell.IsEmpty)
            {
                ReturnToOrigin();
                return;
            }

            MoveShelfToBoard(
                targetCell
            );

            return;
        }

        ReturnToOrigin();
    }

    // ==================================================
    // DROP ON SHELF
    // ==================================================

    private void TryDropOnShelf(
        ShelfSlot targetShelfSlot)
    {
        if (dessert == null)
            return;

        if (targetShelfSlot == null ||
            !targetShelfSlot.IsUnlocked)
        {
            ReturnToOrigin();
            return;
        }

        if (originShelfSlot ==
            targetShelfSlot)
        {
            ReturnToOrigin();
            return;
        }

        if (!targetShelfSlot.IsEmpty)
        {
            ReturnToOrigin();
            return;
        }

        // ----------------------------------------------
        // BOARD -> SHELF
        // ----------------------------------------------

        if (originCell != null)
        {
            MoveBoardToShelf(
                targetShelfSlot
            );

            return;
        }

        // ----------------------------------------------
        // SHELF -> SHELF
        // ----------------------------------------------

        if (originShelfSlot != null)
        {
            MoveShelfToShelf(
                targetShelfSlot
            );

            return;
        }

        ReturnToOrigin();
    }

    // ==================================================
    // BOARD -> BOARD
    // ==================================================

    private void MoveBoardToBoard(
        GridCell targetCell)
    {
        if (originCell == null ||
            targetCell == null ||
            !targetCell.IsUnlocked ||
            !targetCell.IsEmpty)
        {
            ReturnToOrigin();
            return;
        }

        GridCell previousCell =
            originCell;

        previousCell.RemoveDessert(
            dessert
        );

        targetCell.PlaceDessert(
            dessert,
            false
        );

        originCell =
            targetCell;

        originShelfSlot =
            null;

        dessert.ApplyNormalRendering();

        MoveDessertVisualTo(
            targetCell.ContentPosition
        );

        if (gridManager != null)
        {
            gridManager
                .NotifyBoardChanged();
        }

        GameplayEvents
            .RaiseDessertMoved();
    }

    // ==================================================
    // BOARD -> SHELF
    // ==================================================

    private void MoveBoardToShelf(
        ShelfSlot targetShelfSlot)
    {
        if (originCell == null ||
            targetShelfSlot == null ||
            !targetShelfSlot.IsAvailable)
        {
            ReturnToOrigin();
            return;
        }

        GridCell previousCell =
            originCell;

        // Remove board ownership first.
        previousCell.RemoveDessert(
            dessert
        );

        bool stored =
            targetShelfSlot.TryStoreDessert(
                dessert,
                false
            );

        if (!stored)
        {
            // Transaction failed. Restore board state.
            previousCell.PlaceDessert(
                dessert,
                false
            );

            originCell =
                previousCell;

            originShelfSlot =
                null;

            ReturnToOrigin();

            return;
        }

        originCell =
            null;

        originShelfSlot =
            targetShelfSlot;

        dessert.ApplyNormalRendering();

        MoveDessertVisualTo(
            targetShelfSlot.ContentPosition
        );

        if (gridManager != null)
        {
            gridManager
                .NotifyBoardChanged();
        }

        if (shelfManager != null)
        {
            shelfManager
                .NotifyShelfChanged();
        }

        GameplayEvents
            .RaiseDessertMoved();

        Debug.Log(
            $"SHELF | Stored " +
            $"{dessert.Definition.DisplayName} " +
            $"in {targetShelfSlot.name}."
        );
    }

    // ==================================================
    // SHELF -> BOARD
    // ==================================================

    private void MoveShelfToBoard(
        GridCell targetCell)
    {
        if (originShelfSlot == null ||
            targetCell == null ||
            !targetCell.IsUnlocked ||
            !targetCell.IsEmpty)
        {
            ReturnToOrigin();
            return;
        }

        ShelfSlot previousShelfSlot =
            originShelfSlot;

        previousShelfSlot.RemoveDessert(
            dessert
        );

        targetCell.PlaceDessert(
            dessert,
            false
        );

        // Defensive transaction check.
        if (dessert.CurrentCell !=
            targetCell)
        {
            previousShelfSlot
                .TryStoreDessert(
                    dessert,
                    false
                );

            originCell =
                null;

            originShelfSlot =
                previousShelfSlot;

            ReturnToOrigin();

            return;
        }

        originCell =
            targetCell;

        originShelfSlot =
            null;

        dessert.ApplyNormalRendering();

        MoveDessertVisualTo(
            targetCell.ContentPosition
        );

        if (shelfManager != null)
        {
            shelfManager
                .NotifyShelfChanged();
        }

        if (gridManager != null)
        {
            gridManager
                .NotifyBoardChanged();
        }

        GameplayEvents
            .RaiseDessertMoved();

        Debug.Log(
            $"SHELF | Retrieved " +
            $"{dessert.Definition.DisplayName} " +
            $"to {targetCell.name}."
        );
    }

    // ==================================================
    // SHELF -> SHELF
    // ==================================================

    private void MoveShelfToShelf(
        ShelfSlot targetShelfSlot)
    {
        if (originShelfSlot == null ||
            targetShelfSlot == null ||
            !targetShelfSlot.IsAvailable)
        {
            ReturnToOrigin();
            return;
        }

        ShelfSlot previousShelfSlot =
            originShelfSlot;

        previousShelfSlot.RemoveDessert(
            dessert
        );

        bool stored =
            targetShelfSlot.TryStoreDessert(
                dessert,
                false
            );

        if (!stored)
        {
            previousShelfSlot
                .TryStoreDessert(
                    dessert,
                    false
                );

            originShelfSlot =
                previousShelfSlot;

            originCell =
                null;

            ReturnToOrigin();

            return;
        }

        originShelfSlot =
            targetShelfSlot;

        originCell =
            null;

        dessert.ApplyNormalRendering();

        MoveDessertVisualTo(
            targetShelfSlot.ContentPosition
        );

        if (shelfManager != null)
        {
            shelfManager
                .NotifyShelfChanged();
        }

        GameplayEvents
            .RaiseDessertMoved();
    }

    // ==================================================
    // VISUAL MOVEMENT
    // ==================================================

    private void MoveDessertVisualTo(
        Vector3 targetPosition)
    {
        if (dessertAnimator != null)
        {
            dessertAnimator.MoveTo(
                targetPosition
            );
        }
        else
        {
            transform.position =
                targetPosition;
        }
    }

    // ==================================================
    // RETURN
    // ==================================================

    private void ReturnToOrigin()
    {
        if (dessert == null)
            return;

        dessert.ApplyNormalRendering();

        if (originCell != null)
        {
            MoveDessertVisualTo(
                originCell.ContentPosition
            );

            return;
        }

        if (originShelfSlot != null)
        {
            MoveDessertVisualTo(
                originShelfSlot.ContentPosition
            );
        }
    }

    // ==================================================
    // MERGE
    // ==================================================

    private void MergeWith(
        Dessert targetDessert,
        GridCell targetCell)
    {
        if (targetDessert == null ||
            targetCell == null ||
            dessert == null)
        {
            ReturnToOrigin();
            return;
        }

        // Merging only exists on the Board.
        if (originCell == null)
        {
            ReturnToOrigin();
            return;
        }

        if (!originCell.IsUnlocked ||
            !targetCell.IsUnlocked)
        {
            ReturnToOrigin();
            return;
        }

        if (isInteractionLocked)
            return;

        int sourceTier =
            dessert.Tier;

        int resultingTier =
            sourceTier + 1;

        if (!IsMergeTierUnlocked(
                resultingTier))
        {
            Debug.Log(
                $"MERGE LOCKED | " +
                $"Tier {resultingTier} " +
                "requires a higher Oven level."
            );

            ReturnToOrigin();
            return;
        }

        if (dessertSpawner == null)
        {
            Debug.LogError(
                "DessertDragHandler: " +
                "DessertSpawner is missing."
            );

            ReturnToOrigin();
            return;
        }

        DessertDefinition nextDefinition =
            dessertSpawner
                .GetDefinitionByTier(
                    resultingTier
                );

        if (nextDefinition == null)
        {
            Debug.Log(
                $"MERGE | No dessert " +
                $"definition exists for " +
                $"Tier {resultingTier}."
            );

            ReturnToOrigin();
            return;
        }

        StartCoroutine(
            MergeRoutine(
                targetDessert,
                targetCell,
                nextDefinition,
                resultingTier
            )
        );
    }

    private IEnumerator MergeRoutine(
        Dessert targetDessert,
        GridCell targetCell,
        DessertDefinition nextDefinition,
        int resultingTier)
    {
        isInteractionLocked = true;

        GridCell sourceCell =
            dessert.CurrentCell;

        if (sourceCell == null ||
            targetCell == null ||
            targetDessert == null)
        {
            isInteractionLocked = false;
            ReturnToOrigin();
            yield break;
        }

        if (!sourceCell.IsUnlocked ||
            !targetCell.IsUnlocked)
        {
            isInteractionLocked = false;
            ReturnToOrigin();
            yield break;
        }

        // Clear logical board occupancy before
        // visual merge begins.
        sourceCell.RemoveDessert(
            dessert
        );

        targetCell.RemoveDessert(
            targetDessert
        );

        dessert.ClearLocation();
        targetDessert.ClearLocation();

        if (dessertCollider != null)
        {
            dessertCollider.enabled =
                false;
        }

        Collider2D targetCollider =
            targetDessert
                .GetComponent<Collider2D>();

        if (targetCollider != null)
        {
            targetCollider.enabled =
                false;
        }

        DessertAnimator targetAnimator =
            targetDessert
                .GetComponent<DessertAnimator>();

        if (targetAnimator != null)
        {
            targetAnimator
                .PlayMergeSquish();
        }

        if (dessertAnimator != null)
        {
            // Keep the Action parameter required
            // by the existing DessertAnimator.
            dessertAnimator
                .MoveToForMerge(
                    targetCell.ContentPosition,
                    null
                );
        }
        else
        {
            transform.position =
                targetCell.ContentPosition;
        }

        yield return new WaitForSeconds(
            0.1f
        );

        Dessert upgradedDessert =
            dessertSpawner.SpawnDessert(
                nextDefinition,
                targetCell
            );

        if (upgradedDessert == null)
        {
            Debug.LogError(
                "DessertDragHandler: " +
                "Failed to create merged dessert."
            );

            // Emergency recovery.
            targetCell.PlaceDessert(
                targetDessert
            );

            sourceCell.PlaceDessert(
                dessert
            );

            if (dessertCollider != null)
            {
                dessertCollider.enabled =
                    true;
            }

            if (targetCollider != null)
            {
                targetCollider.enabled =
                    true;
            }

            dessert.ApplyNormalRendering();

            targetDessert
                .ApplyNormalRendering();

            originCell =
                sourceCell;

            originShelfSlot =
                null;

            isInteractionLocked =
                false;

            yield break;
        }

        DessertAnimator upgradedAnimator =
            upgradedDessert
                .GetComponent<DessertAnimator>();

        if (upgradedAnimator != null)
        {
            upgradedAnimator
                .PlayMergePop();
        }

        Destroy(
            targetDessert.gameObject
        );

        Destroy(
            gameObject
        );

        if (gridManager != null)
        {
            gridManager
                .NotifyBoardChanged();
        }

        GameplayEvents
            .RaiseDessertMerged(
                resultingTier
            );
    }

    // ==================================================
    // OVEN PROGRESSION
    // ==================================================

    private bool IsMergeTierUnlocked(
        int resultingTier)
    {
        /*
         * Always prefer the persistent singleton.
         *
         * This prevents a Game-scene fallback
         * PlayerProgressionManager from supplying
         * stale/default Oven progression.
         */
        if (PlayerProgressionManager.Instance != null)
        {
            progressionManager =
                PlayerProgressionManager.Instance;
        }
        else if (progressionManager == null)
        {
            progressionManager =
                FindFirstObjectByType<
                    PlayerProgressionManager>();
        }

        if (progressionManager == null)
        {
            Debug.LogError(
                "DessertDragHandler: " +
                "PlayerProgressionManager " +
                "is missing."
            );

            return false;
        }

        bool unlocked =
            progressionManager
                .IsDessertTierUnlocked(
                    resultingTier
                );

        if (!unlocked)
        {
            Debug.Log(
                $"MERGE PROGRESSION | " +
                $"Tier T{resultingTier} locked | " +
                $"Oven Level: " +
                $"{progressionManager.OvenLevel} | " +
                $"Max Unlocked: " +
                $"T{progressionManager.MaxUnlockedDessertTier}"
            );
        }

        return unlocked;
    }
}