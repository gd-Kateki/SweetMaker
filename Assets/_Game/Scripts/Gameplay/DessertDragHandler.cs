using UnityEngine;
using UnityEngine.EventSystems;

[RequireComponent(typeof(Dessert))]
[RequireComponent(typeof(Collider2D))]
[RequireComponent(typeof(DessertAnimator))]
public class DessertDragHandler :
    MonoBehaviour,
    IPointerDownHandler,
    IDragHandler,
    IPointerUpHandler
{
    [Header("Drag Feel")]
    [SerializeField]
    private float dragScaleMultiplier = 1.1f;

    [SerializeField]
    private float dragVerticalOffset = 0.75f;

    [SerializeField]
    private int draggingSortingOrder = 100;

    private Dessert dessert;
    private DessertAnimator dessertAnimator;
    private DessertSpawner dessertSpawner;
    private GridManager gridManager;

    private Camera mainCamera;

    private Transform dessertVisual;

    private GridCell originCell;
    private GridCell highlightedCell;

    private Vector3 originalVisualScale;

    private bool isDragging;
    private bool isMerging;

    private void Awake()
    {
        dessert =
            GetComponent<Dessert>();

        dessertAnimator =
            GetComponent<DessertAnimator>();

        mainCamera =
            Camera.main;

        dessertSpawner =
            FindFirstObjectByType<DessertSpawner>();

        gridManager =
            FindFirstObjectByType<GridManager>();

        dessertVisual =
            dessert.Visual;
    }

    public void OnPointerDown(
        PointerEventData eventData)
    {
        if (isMerging)
            return;

        if (isDragging)
            return;

        if (dessert.CurrentCell == null)
            return;

        originCell =
            dessert.CurrentCell;

        isDragging = true;

        dessertVisual =
            dessert.Visual;

        if (dessertVisual != null)
        {
            originalVisualScale =
                dessertVisual.localScale;

            dessertVisual.localScale =
                originalVisualScale *
                dragScaleMultiplier;
        }

        dessert.ApplyDraggingRendering(
            draggingSortingOrder
        );

        UpdateDragPosition(
            eventData
        );

        UpdateCellHighlight();
    }

    public void OnDrag(
        PointerEventData eventData)
    {
        if (!isDragging ||
            isMerging)
        {
            return;
        }

        UpdateDragPosition(
            eventData
        );

        UpdateCellHighlight();
    }

    public void OnPointerUp(
        PointerEventData eventData)
    {
        if (!isDragging ||
            isMerging)
        {
            return;
        }

        isDragging = false;

        ClearCurrentHighlight();

        RestoreDragVisual();

        TryDrop();
    }

    private void RestoreDragVisual()
    {
        if (dessertVisual != null)
        {
            dessertVisual.localScale =
                originalVisualScale;
        }

        dessert.ApplyNormalRendering();
    }

    private void UpdateDragPosition(
        PointerEventData eventData)
    {
        if (mainCamera == null)
            return;

        Vector3 screenPosition =
            new Vector3(
                eventData.position.x,
                eventData.position.y,
                -mainCamera.transform.position.z
            );

        Vector3 worldPosition =
            mainCamera.ScreenToWorldPoint(
                screenPosition
            );

        worldPosition.z = 0f;

        worldPosition.y +=
            dragVerticalOffset;

        transform.position =
            worldPosition;
    }

    private void UpdateCellHighlight()
    {
        GridCell cell =
            FindCellAtPosition(
                transform.position
            );

        if (cell == highlightedCell)
            return;

        ClearCurrentHighlight();

        if (cell == null)
            return;

        highlightedCell =
            cell;

        if (cell == originCell)
        {
            cell.ShowValidHighlight();
            return;
        }

        if (cell.IsEmpty)
        {
            cell.ShowValidHighlight();
            return;
        }

        Dessert targetDessert =
            cell.CurrentDessert;

        if (targetDessert != null &&
            targetDessert.Tier ==
            dessert.Tier)
        {
            cell.ShowMergeHighlight();
            return;
        }

        cell.ShowInvalidHighlight();
    }

    private void ClearCurrentHighlight()
    {
        if (highlightedCell == null)
            return;

        highlightedCell.ClearHighlight();

        highlightedCell = null;
    }

    private void TryDrop()
    {
        GridCell targetCell =
            FindCellAtPosition(
                transform.position
            );

        if (targetCell == null)
        {
            ReturnToOrigin();
            return;
        }

        if (targetCell == originCell)
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

        if (targetDessert != null &&
            targetDessert.Tier ==
            dessert.Tier)
        {
            MergeWith(
                targetDessert,
                targetCell
            );

            return;
        }

        ReturnToOrigin();
    }

    private GridCell FindCellAtPosition(
        Vector2 worldPosition)
    {
        Collider2D[] hits =
            Physics2D.OverlapPointAll(
                worldPosition
            );

        foreach (Collider2D hit in hits)
        {
            GridCell cell =
                hit.GetComponent<GridCell>();

            if (cell == null)
            {
                cell =
                    hit.GetComponentInParent<GridCell>();
            }

            if (cell != null)
            {
                return cell;
            }
        }

        return null;
    }

    private void MoveToCell(
        GridCell targetCell)
    {
        if (originCell == null ||
            targetCell == null)
        {
            ReturnToOrigin();
            return;
        }

        GridCell sourceCell =
            originCell;

        sourceCell.RemoveDessert(
            dessert
        );

        targetCell.PlaceDessert(
            dessert,
            false
        );

        originCell = null;

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

        NotifyBoardChanged();

GameplayEvents.RaiseDessertMoved();
    }

    private void MergeWith(
        Dessert targetDessert,
        GridCell targetCell)
    {
        if (isMerging)
            return;

        if (dessertSpawner == null)
        {
            Debug.LogError(
                "DessertDragHandler: " +
                "DessertSpawner is missing."
            );

            ReturnToOrigin();
            return;
        }

        if (originCell == null ||
            targetDessert == null ||
            targetCell == null)
        {
            ReturnToOrigin();
            return;
        }

        if (dessert.Tier >=
            dessertSpawner.MaxTier)
        {
            Debug.Log(
                $"{dessert.Definition.DisplayName} " +
                "is already the maximum tier."
            );

            ReturnToOrigin();
            return;
        }

        int sourceTier =
            dessert.Tier;

        int newTier =
            sourceTier + 1;

        DessertDefinition nextDefinition =
            dessertSpawner.GetDefinitionByTier(
                newTier
            );

        if (nextDefinition == null)
        {
            Debug.LogError(
                $"No dessert definition exists " +
                $"for Tier {newTier}."
            );

            ReturnToOrigin();
            return;
        }

        GridCell sourceCell =
            originCell;

        isMerging = true;

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

        SetColliderEnabled(
            dessert,
            false
        );

        SetColliderEnabled(
            targetDessert,
            false
        );

        DessertAnimator targetAnimator =
            targetDessert.GetComponent<DessertAnimator>();

        if (targetAnimator != null)
        {
            targetAnimator.PlayMergeSquish();
        }

        Vector3 mergePosition =
            targetCell.ContentPosition;

        if (dessertAnimator == null)
        {
            CompleteMerge(
                targetDessert,
                targetCell,
                sourceCell,
                nextDefinition,
                sourceTier
            );

            return;
        }

        dessertAnimator.MoveToForMerge(
            mergePosition,
            () =>
            {
                CompleteMerge(
                    targetDessert,
                    targetCell,
                    sourceCell,
                    nextDefinition,
                    sourceTier
                );
            }
        );
    }

    private void CompleteMerge(
        Dessert targetDessert,
        GridCell targetCell,
        GridCell sourceCell,
        DessertDefinition nextDefinition,
        int sourceTier)
    {
        if (!isMerging)
            return;

        if (targetDessert == null)
        {
            Debug.LogError(
                "Merge target disappeared " +
                "before merge completion."
            );

            RestoreFailedMerge(
                sourceCell
            );

            return;
        }

        if (targetCell == null)
        {
            Debug.LogError(
                "Merge target cell disappeared " +
                "before merge completion."
            );

            RestoreFailedMerge(
                sourceCell
            );

            return;
        }

        Dessert mergedDessert =
            dessertSpawner.SpawnDessert(
                nextDefinition,
                targetCell
            );

        if (mergedDessert == null)
        {
            Debug.LogError(
                "Failed to create upgraded dessert."
            );

            RestoreFailedMerge(
                sourceCell
            );

            if (targetCell.IsEmpty &&
                targetDessert != null)
            {
                targetCell.PlaceDessert(
                    targetDessert
                );

                SetColliderEnabled(
                    targetDessert,
                    true
                );
            }

            return;
        }

        DessertAnimator mergedAnimator =
            mergedDessert.GetComponent<DessertAnimator>();

        if (mergedAnimator != null)
        {
            mergedAnimator.PlayMergePop();
        }

        originCell = null;
        isMerging = false;

        NotifyBoardChanged();

GameplayEvents.RaiseDessertMerged(
    nextDefinition.Tier
);

        Destroy(
            targetDessert.gameObject
        );

        Destroy(
            gameObject
        );

        Debug.Log(
            $"Merged Tier {sourceTier} + " +
            $"Tier {sourceTier} into " +
            $"{nextDefinition.DisplayName}."
        );
    }

    private void RestoreFailedMerge(
        GridCell sourceCell)
    {
        isMerging = false;

        if (sourceCell != null &&
            sourceCell.IsEmpty)
        {
            sourceCell.PlaceDessert(
                dessert
            );

            originCell =
                sourceCell;
        }

        SetColliderEnabled(
            dessert,
            true
        );

        dessert.ApplyNormalRendering();
    }

    private void ReturnToOrigin()
    {
        if (originCell == null)
            return;

        dessert.SetCurrentCell(
            originCell
        );

        dessert.ApplyNormalRendering();

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

    private void NotifyBoardChanged()
    {
        if (gridManager != null)
        {
            gridManager.NotifyBoardChanged();
        }
    }

    private void SetColliderEnabled(
        Dessert targetDessert,
        bool enabled)
    {
        if (targetDessert == null)
            return;

        Collider2D targetCollider =
            targetDessert.GetComponent<Collider2D>();

        if (targetCollider != null)
        {
            targetCollider.enabled =
                enabled;
        }
    }
}