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

    [SerializeField]
    private PlayerProgressionManager
        progressionManager;

    private readonly List<GridCell>
        cells =
            new List<GridCell>();

    public event Action BoardChanged;

    public IReadOnlyList<GridCell> Cells =>
        cells;

    public int CellCount =>
        cells.Count;

    public int UnlockedCellCount
    {
        get
        {
            int count = 0;

            foreach (
                GridCell cell
                in cells)
            {
                if (cell != null &&
                    cell.IsUnlocked)
                {
                    count++;
                }
            }

            return count;
        }
    }

    public int LockedCellCount =>
        CellCount -
        UnlockedCellCount;

    public int OccupiedCellCount
    {
        get
        {
            int count = 0;

            foreach (
                GridCell cell
                in cells)
            {
                if (cell != null &&
                    cell.IsUnlocked &&
                    !cell.IsEmpty)
                {
                    count++;
                }
            }

            return count;
        }
    }

    public int EmptyCellCount =>
        UnlockedCellCount -
        OccupiedCellCount;

    public bool HasEmptyCell =>
        EmptyCellCount > 0;

    public bool IsFull =>
        UnlockedCellCount > 0 &&
        EmptyCellCount == 0;

    private void Awake()
    {
        GenerateGrid();
    }

    private void Start()
    {
        ResolveProgressionManager();

        if (progressionManager == null)
        {
            Debug.LogError(
                "GridManager: " +
                "PlayerProgressionManager " +
                "could not be found."
            );

            return;
        }

        progressionManager
            .UpgradeLevelChanged +=
                HandleUpgradeLevelChanged;

        ApplyBoardProgression();
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

    private void ResolveProgressionManager()
{
    /*
     * Always prefer the persistent singleton.
     *
     * This ensures the board uses the progression
     * state that survived the scene transition from
     * MainBakery.
     */
    if (PlayerProgressionManager.Instance != null)
    {
        progressionManager =
            PlayerProgressionManager.Instance;

        return;
    }

    /*
     * Emergency fallback for cases where the
     * singleton has not been established.
     */
    if (progressionManager == null)
    {
        progressionManager =
            FindAnyObjectByType<
                PlayerProgressionManager>();
    }
}

    // --------------------------------------------------
    // GRID GENERATION
    // --------------------------------------------------

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
                    $"Cell_{row + 1}_" +
                    $"{column + 1}";

                newCell.transform
                    .localPosition =
                        position;

                newCell.transform
                    .localScale =
                        Vector3.one *
                        cellSize;

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
                transform
                    .GetChild(i)
                    .gameObject
            );
        }
    }

    // --------------------------------------------------
    // BOARD PROGRESSION
    // --------------------------------------------------

    private void HandleUpgradeLevelChanged(
        UpgradeType type,
        int newLevel)
    {
        if (type !=
            UpgradeType.BoardSpace)
        {
            return;
        }

        ApplyBoardProgression();

        Debug.Log(
            $"BOARD UPGRADE | " +
            $"Level {newLevel} | " +
            $"Unlocked Cells: " +
            $"{UnlockedCellCount}"
        );
    }

    private void ApplyBoardProgression()
    {
        if (progressionManager == null)
            return;

        int requestedUnlockedCells =
            progressionManager
                .ActiveBoardCells;

        int unlockedCells =
            Mathf.Clamp(
                requestedUnlockedCells,
                0,
                cells.Count
            );

        for (int i = 0;
             i < cells.Count;
             i++)
        {
            GridCell cell =
                cells[i];

            if (cell == null)
                continue;

            bool shouldBeUnlocked =
                i < unlockedCells;

            cell.SetUnlocked(
                shouldBeUnlocked
            );
        }

        NotifyBoardChanged();

        Debug.Log(
            $"BOARD PROGRESSION | " +
            $"Level " +
            $"{progressionManager.BoardSpaceLevel} | " +
            $"Unlocked: " +
            $"{UnlockedCellCount}/{CellCount}"
        );
    }

    // --------------------------------------------------
    // EMPTY CELL LOOKUP
    // --------------------------------------------------

    public bool TryGetEmptyCell(
        out GridCell emptyCell)
    {
        List<GridCell> emptyCells =
            new List<GridCell>();

        foreach (
            GridCell cell
            in cells)
        {
            if (cell != null &&
                cell.IsAvailable)
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
            emptyCells[
                randomIndex
            ];

        return true;
    }

    // --------------------------------------------------
    // MERGE CHECK
    // --------------------------------------------------

    public bool HasAvailableMerge()
    {
        for (int i = 0;
             i < cells.Count;
             i++)
        {
            GridCell firstCell =
                cells[i];

            if (firstCell == null ||
                !firstCell.IsUnlocked ||
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
                    !secondCell.IsUnlocked ||
                    secondCell.IsEmpty)
                {
                    continue;
                }

                Dessert secondDessert =
                    secondCell
                        .CurrentDessert;

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

    // --------------------------------------------------
    // EVENTS
    // --------------------------------------------------

    public void NotifyBoardChanged()
    {
        BoardChanged?.Invoke();
    }

    // --------------------------------------------------
    // DEBUG
    // --------------------------------------------------

    [ContextMenu("Debug Board State")]
    private void DebugBoardState()
    {
        Debug.Log(
            $"BOARD STATE | " +
            $"Total: {CellCount} | " +
            $"Unlocked: {UnlockedCellCount} | " +
            $"Locked: {LockedCellCount} | " +
            $"Occupied: {OccupiedCellCount} | " +
            $"Empty: {EmptyCellCount} | " +
            $"Full: {IsFull} | " +
            $"Merge Available: " +
            $"{HasAvailableMerge()}"
        );
    }
}