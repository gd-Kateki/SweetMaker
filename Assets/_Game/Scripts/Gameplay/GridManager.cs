using System;
using System.Collections.Generic;
using UnityEngine;

public class GridManager : MonoBehaviour
{
    [Header("Grid Settings")]
    [SerializeField]
    private int columns = 5;

    [SerializeField]
    private int rows = 6;

    [SerializeField]
    private float cellSize = 1.25f;

    [SerializeField]
    private float spacing = 0.1f;

    [Header("References")]
    [SerializeField]
    private GridCell cellPrefab;

    private readonly List<GridCell> cells =
        new List<GridCell>();

    public event Action BoardChanged;

    public IReadOnlyList<GridCell> Cells =>
        cells;

    public int CellCount =>
        cells.Count;

    public int OccupiedCellCount
    {
        get
        {
            int count = 0;

            foreach (GridCell cell in cells)
            {
                if (cell != null &&
                    !cell.IsEmpty)
                {
                    count++;
                }
            }

            return count;
        }
    }

    public int EmptyCellCount =>
        CellCount - OccupiedCellCount;

    public bool HasEmptyCell =>
        EmptyCellCount > 0;

    public bool IsFull =>
        CellCount > 0 &&
        EmptyCellCount == 0;

    private void Awake()
    {
        GenerateGrid();
    }

    private void GenerateGrid()
    {
        ClearGrid();

        float step =
            cellSize + spacing;

        float gridWidth =
            (columns - 1) * step;

        float gridHeight =
            (rows - 1) * step;

        Vector2 startPosition =
            new Vector2(
                -gridWidth / 2f,
                gridHeight / 2f
            );

        for (int row = 0;
             row < rows;
             row++)
        {
            for (int column = 0;
                 column < columns;
                 column++)
            {
                Vector2 position =
                    startPosition +
                    new Vector2(
                        column * step,
                        -row * step
                    );

                GridCell newCell =
                    Instantiate(
                        cellPrefab,
                        transform
                    );

                newCell.name =
                    $"Cell_{row + 1}_{column + 1}";

                newCell.transform.localPosition =
                    position;

                newCell.transform.localScale =
                    Vector3.one * cellSize;

                cells.Add(
                    newCell
                );
            }
        }
    }

    private void ClearGrid()
    {
        cells.Clear();

        for (int i =
                 transform.childCount - 1;
             i >= 0;
             i--)
        {
            Destroy(
                transform.GetChild(i).gameObject
            );
        }
    }

    public bool TryGetEmptyCell(
    out GridCell emptyCell)
{
    List<GridCell> emptyCells =
        new List<GridCell>();

    foreach (GridCell cell in cells)
    {
        if (cell != null &&
            cell.IsEmpty)
        {
            emptyCells.Add(
                cell
            );
        }
    }

    if (emptyCells.Count == 0)
    {
        emptyCell = null;
        return false;
    }

    int randomIndex =
        UnityEngine.Random.Range(
            0,
            emptyCells.Count
        );

    emptyCell =
        emptyCells[randomIndex];

    return true;
}

    public bool HasAvailableMerge()
    {
        for (int i = 0;
             i < cells.Count;
             i++)
        {
            GridCell firstCell =
                cells[i];

            if (firstCell == null ||
                firstCell.IsEmpty)
            {
                continue;
            }

            Dessert firstDessert =
                firstCell.CurrentDessert;

            if (firstDessert == null)
                continue;

            for (int j = i + 1;
                 j < cells.Count;
                 j++)
            {
                GridCell secondCell =
                    cells[j];

                if (secondCell == null ||
                    secondCell.IsEmpty)
                {
                    continue;
                }

                Dessert secondDessert =
                    secondCell.CurrentDessert;

                if (secondDessert == null)
                    continue;

                if (firstDessert.Tier ==
                    secondDessert.Tier)
                {
                    return true;
                }
            }
        }

        return false;
    }

    public void NotifyBoardChanged()
    {
        BoardChanged?.Invoke();
    }

    [ContextMenu("Debug Board State")]
    private void DebugBoardState()
    {
        Debug.Log(
            $"BOARD STATE | " +
            $"Cells: {CellCount} | " +
            $"Occupied: {OccupiedCellCount} | " +
            $"Empty: {EmptyCellCount} | " +
            $"Full: {IsFull} | " +
            $"Merge Available: " +
            $"{HasAvailableMerge()}"
        );
    }
}