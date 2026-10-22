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

    [SerializeField]
    private RecycleDropTarget recycleDropTarget;

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
    private bool hasBeenRecycled;
    private bool mergeTransactionActive;
    private bool sourceColliderWasEnabled;
    private bool targetColliderWasEnabled;
    private GridCell mergeSourceCell;
    private GridCell mergeTargetCell;
    private Dessert mergeTargetDessert;
    private Collider2D mergeTargetCollider;

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

    private void OnDisable()
    {
        if (mergeTransactionActive)
            AbortMergeTransaction();
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

        if (recycleDropTarget == null)
        {
            recycleDropTarget =
                FindAnyObjectByType<RecycleDropTarget>();
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
                FindAnyObjectByType<
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

        if (gridManager != null &&
            gridManager.IsMergeMutationBlocked(this))
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
            pointerPosition,
            eventData.position
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
        if (gridManager != null &&
            gridManager.IsMergeMutationBlocked(this))
        {
            ClearHighlights();
            ReturnToOrigin();
            return;
        }

        Vector3 pointerPosition =
            GetWorldPointerPosition(
                eventData
            );

        if (recycleDropTarget != null &&
            recycleDropTarget.ContainsScreenPoint(
                eventData.position))
        {
            ClearHighlights();
            if (TryRecycleDraggedDessert())
            {
                if (Application.isPlaying)
                    Destroy(gameObject);
                else
                    DestroyImmediate(gameObject);
            }
            else
                ReturnToOrigin();
            return;
        }

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
        Vector3 pointerPosition,
        Vector2 screenPosition)
    {
        if (recycleDropTarget != null &&
            recycleDropTarget.ContainsScreenPoint(
                screenPosition))
        {
            ClearHighlights();
            recycleDropTarget.SetHighlighted(true);
            return;
        }

        if (recycleDropTarget != null)
            recycleDropTarget.SetHighlighted(false);

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
        if (recycleDropTarget != null)
            recycleDropTarget.SetHighlighted(false);

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

    private bool TryRecycleDraggedDessert()
    {
        if (hasBeenRecycled || dessert == null)
            return false;

        if (gridManager != null &&
            gridManager.IsMergeTransactionActive)
            return false;

        if (originCell != null &&
            dessert.LocationType == DessertLocationType.Board &&
            dessert.CurrentCell == originCell &&
            originCell.CurrentDessert == dessert)
        {
            originCell.RemoveDessert(dessert);
            if (gridManager != null)
                gridManager.NotifyBoardChanged();
        }
        else if (originShelfSlot != null &&
                 dessert.LocationType == DessertLocationType.Shelf &&
                 dessert.CurrentShelfSlot == originShelfSlot &&
                 originShelfSlot.CurrentDessert == dessert)
        {
            originShelfSlot.RemoveDessert(dessert);
            if (shelfManager != null)
                shelfManager.NotifyShelfChanged();
        }
        else
        {
            return false;
        }

        hasBeenRecycled = true;
        originCell = null;
        originShelfSlot = null;
        if (dessertCollider != null)
            dessertCollider.enabled = false;
        return true;
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
        GridCell sourceCell =
            dessert.CurrentCell;

        if (sourceCell == null ||
            targetCell == null ||
            targetDessert == null)
        {
            ReturnToOrigin();
            yield break;
        }

        if (!sourceCell.IsUnlocked ||
            !targetCell.IsUnlocked)
        {
            ReturnToOrigin();
            yield break;
        }

        if (gridManager == null ||
            !gridManager.TryBeginMergeTransaction(this))
        {
            ReturnToOrigin();
            yield break;
        }

        mergeTransactionActive = true;
        mergeSourceCell = sourceCell;
        mergeTargetCell = targetCell;
        mergeTargetDessert = targetDessert;
        sourceColliderWasEnabled =
            dessertCollider != null && dessertCollider.enabled;
        mergeTargetCollider =
            targetDessert.GetComponent<Collider2D>();
        targetColliderWasEnabled =
            mergeTargetCollider != null && mergeTargetCollider.enabled;
        isInteractionLocked = true;

        try
        {
            DessertAnimator targetAnimator =
                targetDessert.GetComponent<DessertAnimator>();
            if (targetAnimator != null)
                targetAnimator.PlayMergeSquish();

            if (dessertAnimator != null)
            {
                dessertAnimator.MoveToForMerge(
                    targetCell.ContentPosition,
                    null);
            }
            else
            {
                transform.position = targetCell.ContentPosition;
            }

            yield return new WaitForSeconds(0.1f);

            if (!mergeTransactionActive ||
                !sourceCell.IsUnlocked ||
                !targetCell.IsUnlocked ||
                sourceCell.CurrentDessert != dessert ||
                targetCell.CurrentDessert != targetDessert)
                yield break;

            if (dessertCollider != null)
                dessertCollider.enabled = false;
            if (mergeTargetCollider != null)
                mergeTargetCollider.enabled = false;

            sourceCell.RemoveDessert(dessert);
            targetCell.RemoveDessert(targetDessert);
            dessert.ClearLocation();
            targetDessert.ClearLocation();

            Dessert upgradedDessert =
                dessertSpawner.SpawnDessertForMerge(
                    nextDefinition,
                    targetCell,
                    this);

            if (upgradedDessert == null)
            {
                Debug.LogError(
                    "DessertDragHandler: Failed to create merged dessert.");
                RestoreMergeParticipants();
                yield break;
            }

            DessertAnimator upgradedAnimator =
                upgradedDessert.GetComponent<DessertAnimator>();
            if (upgradedAnimator != null)
                upgradedAnimator.PlayMergePop();

            if (gridManager != null)
                gridManager.NotifyBoardChanged();

            GameplayEvents.RaiseDessertMerged(resultingTier);
            CompleteMergeTransaction();

            Destroy(targetDessert.gameObject);
            Destroy(gameObject);
        }
        finally
        {
            if (mergeTransactionActive)
                AbortMergeTransaction();
        }
    }

    private void RestoreMergeParticipants()
    {
        if (mergeSourceCell == null || mergeTargetCell == null ||
            dessert == null || mergeTargetDessert == null)
            return;

        bool sourceRestored =
            RestoreMergeDessert(dessert, mergeSourceCell);
        bool targetRestored =
            RestoreMergeDessert(mergeTargetDessert, mergeTargetCell);
        if (!sourceRestored || !targetRestored)
        {
            Debug.LogError(
                "MERGE ABORTED | Could not restore both desserts to available Board cells.");
        }

        if (dessertCollider != null)
            dessertCollider.enabled = sourceColliderWasEnabled;
        if (mergeTargetCollider != null)
            mergeTargetCollider.enabled = targetColliderWasEnabled;

        if (dessert.CurrentCell != null)
            dessert.transform.position = dessert.CurrentCell.ContentPosition;
        if (mergeTargetDessert.CurrentCell != null)
            mergeTargetDessert.transform.position =
                mergeTargetDessert.CurrentCell.ContentPosition;
        dessert.ApplyNormalRendering();
        mergeTargetDessert.ApplyNormalRendering();
        originCell = dessert.CurrentCell;
        originShelfSlot = null;
    }

    private bool RestoreMergeDessert(
        Dessert dessertToRestore,
        GridCell preferredCell)
    {
        if (dessertToRestore == null || gridManager == null)
            return false;

        GridCell destination = preferredCell != null &&
                               preferredCell.IsUnlocked &&
                               (preferredCell.IsEmpty ||
                                preferredCell.CurrentDessert == dessertToRestore)
            ? preferredCell
            : null;
        if (destination == null &&
            !gridManager.TryGetEmptyCell(out destination))
            return false;

        if (dessertToRestore.CurrentCell != null &&
            dessertToRestore.CurrentCell != destination &&
            dessertToRestore.CurrentCell.CurrentDessert == dessertToRestore)
        {
            dessertToRestore.CurrentCell.RemoveDessert(dessertToRestore);
        }

        destination.PlaceDessert(dessertToRestore);
        return dessertToRestore.CurrentCell == destination &&
               destination.CurrentDessert == dessertToRestore;
    }

    private void CompleteMergeTransaction()
    {
        if (gridManager != null)
            gridManager.EndMergeTransaction(this);
        ClearMergeTransactionState();
    }

    private void AbortMergeTransaction()
    {
        if (!mergeTransactionActive)
            return;

        try
        {
            RestoreMergeParticipants();
        }
        finally
        {
            if (gridManager != null)
                gridManager.EndMergeTransaction(this);

            ClearMergeTransactionState();

            if (gridManager != null)
                gridManager.NotifyBoardChanged();
        }
    }

    private void ClearMergeTransactionState()
    {
        mergeTransactionActive = false;
        isInteractionLocked = false;
        mergeSourceCell = null;
        mergeTargetCell = null;
        mergeTargetDessert = null;
        mergeTargetCollider = null;
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
                FindAnyObjectByType<
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