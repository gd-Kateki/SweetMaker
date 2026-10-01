using UnityEngine;

[RequireComponent(typeof(Dessert))]
[RequireComponent(typeof(Collider2D))]
public class DessertDragHandler : MonoBehaviour
{
    private Dessert dessert;
    private DessertSpawner dessertSpawner;
    private Camera mainCamera;
    private Collider2D dessertCollider;

    private GridCell originCell;
    private bool isDragging;

    private void Awake()
    {
        dessert = GetComponent<Dessert>();
        dessertCollider = GetComponent<Collider2D>();
        mainCamera = Camera.main;

        dessertSpawner = FindFirstObjectByType<DessertSpawner>();
    }

    private void OnMouseDown()
    {
        if (dessert.CurrentCell == null)
            return;

        originCell = dessert.CurrentCell;
        isDragging = true;

        // Remove the dessert from its parent visually,
        // but the origin cell still remembers it until
        // the drop has been resolved.
        transform.SetParent(null);

        // Prevent our own collider from interfering
        // with drop detection.
        dessertCollider.enabled = false;
    }

    private void OnMouseDrag()
    {
        if (!isDragging)
            return;

        Vector3 mousePosition =
            mainCamera.ScreenToWorldPoint(Input.mousePosition);

        mousePosition.z = 0f;

        transform.position = mousePosition;
    }

    private void OnMouseUp()
    {
        if (!isDragging)
            return;

        isDragging = false;

        TryDrop();

        // Re-enable after resolving the drop.
        if (dessertCollider != null)
        {
            dessertCollider.enabled = true;
        }
    }

    private void TryDrop()
    {
        GridCell targetCell = FindCellAtPosition(transform.position);

        // Dropped outside the grid.
        if (targetCell == null)
        {
            ReturnToOrigin();
            return;
        }

        // Dropped back onto the same cell.
        if (targetCell == originCell)
        {
            ReturnToOrigin();
            return;
        }

        // Empty cell = move.
        if (targetCell.IsEmpty)
        {
            MoveToCell(targetCell);
            return;
        }

        Dessert targetDessert = targetCell.CurrentDessert;

        // Same tier = merge.
        if (targetDessert != null &&
            targetDessert.Tier == dessert.Tier)
        {
            MergeWith(targetDessert, targetCell);
            return;
        }

        // Occupied by incompatible dessert.
        ReturnToOrigin();
    }

    private GridCell FindCellAtPosition(Vector2 worldPosition)
    {
        Collider2D[] hits = Physics2D.OverlapPointAll(worldPosition);

        foreach (Collider2D hit in hits)
        {
            GridCell cell = hit.GetComponent<GridCell>();

            if (cell == null)
            {
                cell = hit.GetComponentInParent<GridCell>();
            }

            if (cell != null)
            {
                return cell;
            }
        }

        return null;
    }

    private void MoveToCell(GridCell targetCell)
    {
        originCell.RemoveDessert(dessert);

        targetCell.PlaceDessert(dessert);

        originCell = null;
    }

    private void MergeWith(
    Dessert targetDessert,
    GridCell targetCell)
{
    if (dessertSpawner == null)
    {
        Debug.LogError(
            "DessertDragHandler: DessertSpawner is missing."
        );

        ReturnToOrigin();
        return;
    }
    if (dessert.Tier >= dessertSpawner.MaxTier)
{
    Debug.Log(
        $"{dessert.Definition.DisplayName} is already the maximum tier."
    );

    ReturnToOrigin();
    return;
}

    int newTier = dessert.Tier + 1;

    DessertDefinition nextDefinition =
        dessertSpawner.GetDefinitionByTier(newTier);

    if (nextDefinition == null)
    {
        Debug.Log(
            $"No dessert definition exists for Tier {newTier}."
        );

        ReturnToOrigin();
        return;
    }

    int sourceTier = dessert.Tier;

    originCell.RemoveDessert(dessert);
    targetCell.RemoveDessert(targetDessert);

    Destroy(targetDessert.gameObject);
    Destroy(gameObject);

    dessertSpawner.SpawnDessert(
        nextDefinition,
        targetCell
    );

    Debug.Log(
        $"Merged Tier {sourceTier} + Tier {sourceTier} " +
        $"into {nextDefinition.DisplayName} " +
        $"(Tier {newTier})."
    );

    originCell = null;
}

    private void ReturnToOrigin()
    {
        if (originCell != null)
        {
            originCell.PlaceDessert(dessert);
        }
    }
}