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
    private PlayerProgressionManager
        progressionManager;

    [Header("Dragging")]
    [SerializeField]
    private int draggingSortingOrder = 100;

    private Dessert dessert;
    private DessertAnimator dessertAnimator;
    private Collider2D dessertCollider;

    private Camera mainCamera;

    private GridCell originCell;
    private GridCell highlightedCell;

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
                FindFirstObjectByType<
                    DessertSpawner>();
        }

        if (gridManager == null)
        {
            gridManager =
                FindFirstObjectByType<
                    GridManager>();
        }

        if (progressionManager == null)
        {
            progressionManager =
                FindFirstObjectByType<
                    PlayerProgressionManager>();
        }
    }

    // --------------------------------------------------
    // POINTER INPUT
    // --------------------------------------------------

    public void OnPointerDown(
        PointerEventData eventData)
    {
        if (isInteractionLocked)
            return;

        if (dessert == null)
            return;

        if (dessert.CurrentCell == null)
            return;

        // 12.3 safety:
        // Desserts inside locked cells should never
        // be interactable.
        if (!dessert.CurrentCell.IsUnlocked)
            return;

        isDragging = true;

        originCell =
            dessert.CurrentCell;

        ClearHighlightedCell();

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

        GridCell targetCell =
            FindCellAtPosition(
                pointerPosition
            );

        UpdateTargetHighlight(
            targetCell
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
            FindCellAtPosition(
                pointerPosition
            );

        ClearHighlightedCell();

        TryDrop(
            targetCell
        );
    }

    // --------------------------------------------------
    // POINTER POSITION
    // --------------------------------------------------

    private Vector3 GetWorldPointerPosition(
        PointerEventData eventData)
    {
        if (mainCamera == null)
        {
            mainCamera =
                Camera.main;
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

    // --------------------------------------------------
    // TARGET DETECTION
    // --------------------------------------------------

    private GridCell FindCellAtPosition(
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

            GridCell cell =
                hit.GetComponent<GridCell>();

            if (cell != null)
                return cell;
        }

        return null;
    }

    // --------------------------------------------------
    // HIGHLIGHT
    // --------------------------------------------------

    private void UpdateTargetHighlight(
        GridCell targetCell)
    {
        if (targetCell ==
            highlightedCell)
        {
            return;
        }

        ClearHighlightedCell();

        if (targetCell == null)
            return;

        highlightedCell =
            targetCell;

        if (targetCell ==
            originCell)
        {
            return;
        }

        // --------------------------------------------------
        // 12.3 BOARD PROGRESSION
        // Locked cells are not valid gameplay targets.
        // --------------------------------------------------

        if (!targetCell.IsUnlocked)
        {
            return;
        }

        if (targetCell.IsEmpty)
        {
            targetCell
                .ShowValidHighlight();

            return;
        }

        Dessert targetDessert =
            targetCell.CurrentDessert;

        if (targetDessert == null)
        {
            targetCell
                .ShowInvalidHighlight();

            return;
        }

        if (targetDessert ==
            dessert)
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
    }

    private void ClearHighlightedCell()
    {
        if (highlightedCell != null)
        {
            highlightedCell
                .ClearHighlight();

            highlightedCell = null;
        }
    }

    // --------------------------------------------------
    // DROP
    // --------------------------------------------------

    private void TryDrop(
        GridCell targetCell)
    {
        if (dessert == null ||
            originCell == null)
        {
            return;
        }

        if (targetCell == null)
        {
            ReturnToOrigin();
            return;
        }

        if (targetCell ==
            originCell)
        {
            ReturnToOrigin();
            return;
        }

        // --------------------------------------------------
        // 12.3 BOARD PROGRESSION
        // Never allow movement or merging into a
        // locked GridCell.
        // --------------------------------------------------

        if (!targetCell.IsUnlocked)
        {
            ReturnToOrigin();
            return;
        }

        if (targetCell.IsEmpty)
        {
            MoveToCell(
                targetCell
            );

            return;
        }

        Dessert targetDessert =
            targetCell.CurrentDessert;

        if (targetDessert == null)
        {
            ReturnToOrigin();
            return;
        }

        if (targetDessert ==
            dessert)
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
                "requires a higher " +
                "Oven level."
            );

            ReturnToOrigin();
            return;
        }

        MergeWith(
            targetDessert,
            targetCell
        );
    }

    // --------------------------------------------------
    // MOVE
    // --------------------------------------------------

    private void MoveToCell(
        GridCell targetCell)
    {
        if (targetCell == null ||
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

        dessert.ApplyNormalRendering();

        if (dessertAnimator != null)
        {
            dessertAnimator.MoveTo(
                targetCell.ContentPosition
            );
        }
        else
        {
            transform.position =
                targetCell.ContentPosition;
        }

        if (gridManager != null)
        {
            gridManager
                .NotifyBoardChanged();
        }

        GameplayEvents
            .RaiseDessertMoved();
    }

    // --------------------------------------------------
    // RETURN
    // --------------------------------------------------

    private void ReturnToOrigin()
    {
        if (dessert == null)
            return;

        dessert.ApplyNormalRendering();

        if (originCell == null)
            return;

        if (dessertAnimator != null)
        {
            dessertAnimator.MoveTo(
                originCell.ContentPosition
            );
        }
        else
        {
            transform.position =
                originCell.ContentPosition;
        }
    }

    // --------------------------------------------------
    // MERGE
    // --------------------------------------------------

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

        // 12.3 safety:
        // The transaction itself also refuses
        // locked cells.
        if (!targetCell.IsUnlocked)
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

        // 12.2 Oven progression protection.
        if (!IsMergeTierUnlocked(
                resultingTier))
        {
            Debug.Log(
                $"MERGE LOCKED | " +
                $"Tier {resultingTier} " +
                "requires a higher " +
                "Oven level."
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

        // Final 12.3 transaction safety.
        if (!sourceCell.IsUnlocked ||
            !targetCell.IsUnlocked)
        {
            isInteractionLocked = false;
            ReturnToOrigin();
            yield break;
        }

        // Clear logical occupancy before
        // the visual merge begins.
        sourceCell.RemoveDessert(
            dessert
        );

        targetCell.RemoveDessert(
            targetDessert
        );

        dessert.SetCurrentCell(
            null
        );

        targetDessert.SetCurrentCell(
            null
        );

        // Prevent original desserts from
        // receiving additional input.
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
                .GetComponent<
                    DessertAnimator>();

        if (targetAnimator != null)
        {
            targetAnimator
                .PlayMergeSquish();
        }

        if (dessertAnimator != null)
        {
            // Important:
            // Your DessertAnimator requires
            // Vector3 + Action.
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

        // Preserve the prototype merge timing.
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
                "Failed to create merged " +
                "dessert."
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

            isInteractionLocked = false;

            yield break;
        }

        DessertAnimator upgradedAnimator =
            upgradedDessert
                .GetComponent<
                    DessertAnimator>();

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

    // --------------------------------------------------
    // PROGRESSION
    // --------------------------------------------------

    private bool IsMergeTierUnlocked(
        int resultingTier)
    {
        if (progressionManager == null)
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

        return progressionManager
            .IsDessertTierUnlocked(
                resultingTier
            );
    }
}