using UnityEngine;
using UnityEngine.UI;

// Keep the reference's three portrait columns inside the available scroll width.
[ExecuteAlways, RequireComponent(typeof(GridLayoutGroup))]
public sealed class CollectionReferenceGrid : MonoBehaviour
{
    private void OnEnable() => Fit();
    private void OnRectTransformDimensionsChange() => Fit();
    private void Fit()
    {
        if (!isActiveAndEnabled) return;
        var grid = GetComponent<GridLayoutGroup>();
        if (grid == null) return;
        var rect = (RectTransform)transform;
        float width = (rect.rect.width - grid.padding.horizontal - grid.spacing.x * 2) / 3;
        // The reference shows two complete rows. Reserve their padding and gap,
        // so the second row's rounded bottom is not cut off on shorter screens.
        if (rect.parent is RectTransform viewport && viewport.rect.height > grid.padding.vertical + grid.spacing.y)
        {
            float rowHeight = (viewport.rect.height - grid.padding.vertical - grid.spacing.y) / 2;
            width = Mathf.Min(width, rowHeight * (218f / 236f));
        }
        if (width <= 0) return;
        var cell = new Vector2(width, width * (236f / 218f));
        if ((grid.cellSize - cell).sqrMagnitude < .01f) return;
        grid.constraint = GridLayoutGroup.Constraint.FixedColumnCount;
        grid.constraintCount = 3;
        grid.childAlignment = TextAnchor.UpperCenter;
        grid.cellSize = cell;
    }
}
