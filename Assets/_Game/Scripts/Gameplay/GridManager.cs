using System.Collections.Generic;
using UnityEngine;

public class GridManager : MonoBehaviour
{
    [Header("Grid Settings")]
    [SerializeField] private int columns = 5;
    [SerializeField] private int rows = 6;

    [SerializeField] private float cellSize = 1.25f;
    [SerializeField] private float spacing = 0.1f;

    [Header("References")]
    [SerializeField] private GridCell cellPrefab;

    private readonly List<GridCell> cells = new();

    public IReadOnlyList<GridCell> Cells => cells;

    private void Awake()
    {
        GenerateGrid();
    }

    private void GenerateGrid()
    {
        ClearGrid();

        float step = cellSize + spacing;

        float gridWidth = (columns - 1) * step;
        float gridHeight = (rows - 1) * step;

        Vector2 startPosition = new Vector2(
            -gridWidth / 2f,
            gridHeight / 2f
        );

        for (int row = 0; row < rows; row++)
        {
            for (int column = 0; column < columns; column++)
            {
                Vector2 position = startPosition + new Vector2(
                    column * step,
                    -row * step
                );

                GridCell newCell = Instantiate(
                    cellPrefab,
                    transform
                );

                newCell.name =
                    $"Cell_{row + 1}_{column + 1}";

                newCell.transform.localPosition = position;
                newCell.transform.localScale =
                    Vector3.one * cellSize;

                cells.Add(newCell);
            }
        }
    }

    private void ClearGrid()
    {
        cells.Clear();

        for (int i = transform.childCount - 1; i >= 0; i--)
        {
            Destroy(transform.GetChild(i).gameObject);
        }
    }

    public bool TryGetEmptyCell(out GridCell emptyCell)
    {
        List<GridCell> emptyCells = new();

        foreach (GridCell cell in cells)
        {
            if (cell != null && cell.IsEmpty)
            {
            emptyCells.Add(cell);
            }
        }

        if (emptyCells.Count == 0)
        {
            emptyCell = null;
            return false;
        }

    int randomIndex = Random.Range(
        0,
        emptyCells.Count
    );

    emptyCell = emptyCells[randomIndex];

    return true;
}   
}