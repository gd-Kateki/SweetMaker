using UnityEngine;

public class GameManager : MonoBehaviour
{
    public enum GameState
    {
        Playing,
        GameOver
    }

    public static GameManager Instance
    {
        get;
        private set;
    }

    [Header("References")]
    [SerializeField]
    private GridManager gridManager;

    [Header("State")]
    [SerializeField]
    private GameState currentState =
        GameState.Playing;

    public GameState CurrentState =>
        currentState;

    public bool IsPlaying =>
        currentState ==
        GameState.Playing;

    public bool IsGameOver =>
        currentState ==
        GameState.GameOver;

    private void Awake()
    {
        if (Instance != null &&
            Instance != this)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this;

        SetState(
            GameState.Playing
        );
    }

    private void Start()
    {
        if (gridManager == null)
        {
            gridManager =
                FindFirstObjectByType<GridManager>();
        }

        if (gridManager == null)
        {
            Debug.LogError(
                "GameManager: GridManager " +
                "could not be found."
            );

            return;
        }

        gridManager.BoardChanged +=
            HandleBoardChanged;

        EvaluateBoard();
    }

    private void OnDestroy()
    {
        if (gridManager != null)
        {
            gridManager.BoardChanged -=
                HandleBoardChanged;
        }

        if (Instance == this)
        {
            Instance = null;
        }
    }

    private void HandleBoardChanged()
    {
        EvaluateBoard();
    }

    private void EvaluateBoard()
    {
        if (gridManager == null)
            return;

        Debug.Log(
            $"BOARD UPDATED | " +
            $"Occupied: " +
            $"{gridManager.OccupiedCellCount}/" +
            $"{gridManager.CellCount} | " +
            $"Empty: " +
            $"{gridManager.EmptyCellCount} | " +
            $"Full: " +
            $"{gridManager.IsFull} | " +
            $"Merge Available: " +
            $"{gridManager.HasAvailableMerge()}"
        );

        /*
         * No Game Over logic here yet.
         *
         * Step 9 currently establishes
         * infrastructure only.
         *
         * Progression and failure rules
         * can be changed later without
         * rewriting the board system.
         */
    }

    public void TriggerGameOver()
    {
        if (currentState ==
            GameState.GameOver)
        {
            return;
        }

        SetState(
            GameState.GameOver
        );

        Debug.Log(
            "GAME OVER"
        );
    }

    private void SetState(
        GameState newState)
    {
        currentState =
            newState;

        Debug.Log(
            $"Game State → {currentState}"
        );
    }
}