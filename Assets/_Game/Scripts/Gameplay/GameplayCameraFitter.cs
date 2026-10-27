using UnityEngine;

[RequireComponent(typeof(Camera))]
public sealed class GameplayCameraFitter : MonoBehaviour
{
    private const int ExpectedBoardCellCount = 30;

    [Header("World Bounds")]
    [SerializeField]
    private GridManager gridManager;

    [SerializeField]
    private ShelfSlot[] servingPlates;

    [SerializeField]
    private SpriteRenderer ovenRenderer;

    [SerializeField]
    private SpriteRenderer backgroundRenderer;

    [SerializeField]
    private float minimumOrthographicSize = 8f;

    [SerializeField]
    private float worldPadding = 0.25f;

    private Camera gameplayCamera;
    private Bounds gameplayBounds;
    private Vector3 authoredCameraPosition;
    private Vector3 authoredBackgroundScale;
    private Vector3 authoredBackgroundPosition;
    private Vector2 authoredBackgroundBoundsSize;
    private Vector2 authoredBackgroundBoundsOffset;
    private bool hasObservedViewport;
    private int lastScreenWidth;
    private int lastScreenHeight;
    private float lastCameraAspect;

    private void Awake()
    {
        gameplayCamera = GetComponent<Camera>();
    }

    private void Start()
    {
        if (!ValidateReferences())
        {
            enabled = false;
            return;
        }

        authoredCameraPosition = gameplayCamera.transform.position;
        authoredBackgroundScale = backgroundRenderer.transform.localScale;
        authoredBackgroundPosition = backgroundRenderer.transform.position;
        authoredBackgroundBoundsSize = backgroundRenderer.bounds.size;
        authoredBackgroundBoundsOffset = new Vector2(
            backgroundRenderer.bounds.center.x - authoredBackgroundPosition.x,
            backgroundRenderer.bounds.center.y - authoredBackgroundPosition.y);

        if (authoredBackgroundBoundsSize.x <= 0f ||
            authoredBackgroundBoundsSize.y <= 0f)
        {
            Debug.LogError(
                "GameplayCameraFitter: GameBackground has no usable renderer bounds.",
                this);
            enabled = false;
            return;
        }

        if (!TryCalculateGameplayBounds(out gameplayBounds))
        {
            enabled = false;
            return;
        }

        ApplyResponsiveLayout();
        ObserveViewport();
    }

    private void Update()
    {
        if (!HasViewportChanged())
            return;

        ApplyResponsiveLayout();
        ObserveViewport();
    }

    private bool ValidateReferences()
    {
        if (gameplayCamera == null)
        {
            Debug.LogError(
                "GameplayCameraFitter: Camera component is missing.",
                this);
            return false;
        }

        if (!gameplayCamera.orthographic)
        {
            Debug.LogError(
                "GameplayCameraFitter: The gameplay camera must be orthographic.",
                this);
            return false;
        }

        if (gridManager == null)
        {
            Debug.LogError(
                "GameplayCameraFitter: GridManager reference is missing.",
                this);
            return false;
        }

        if (gridManager.Cells == null ||
            gridManager.Cells.Count != ExpectedBoardCellCount)
        {
            int cellCount = gridManager.Cells != null
                ? gridManager.Cells.Count
                : 0;
            Debug.LogError(
                $"GameplayCameraFitter: Expected {ExpectedBoardCellCount} generated board cells, found {cellCount}.",
                this);
            return false;
        }

        if (servingPlates == null ||
            servingPlates.Length != 5)
        {
            Debug.LogError(
                "GameplayCameraFitter: Exactly five Serving Plate references are required.",
                this);
            return false;
        }

        for (int i = 0; i < servingPlates.Length; i++)
        {
            if (servingPlates[i] == null)
            {
                Debug.LogError(
                    $"GameplayCameraFitter: Serving Plate reference {i + 1} is missing.",
                    this);
                return false;
            }
        }

        if (ovenRenderer == null)
        {
            Debug.LogError(
                "GameplayCameraFitter: Oven SpriteRenderer reference is missing.",
                this);
            return false;
        }

        if (backgroundRenderer == null)
        {
            Debug.LogError(
                "GameplayCameraFitter: GameBackground SpriteRenderer reference is missing.",
                this);
            return false;
        }

        if (minimumOrthographicSize <= 0f ||
            worldPadding < 0f)
        {
            Debug.LogError(
                "GameplayCameraFitter: Camera size must be positive and world padding cannot be negative.",
                this);
            return false;
        }

        return true;
    }

    private bool TryCalculateGameplayBounds(out Bounds bounds)
    {
        bounds = default;
        bool hasBounds = false;

        foreach (GridCell cell in gridManager.Cells)
        {
            if (cell == null)
            {
                Debug.LogError(
                    "GameplayCameraFitter: GridManager contains a missing board cell.",
                    this);
                return false;
            }

            SpriteRenderer cellRenderer =
                cell.GetComponent<SpriteRenderer>();
            if (cellRenderer == null)
            {
                Debug.LogError(
                    $"GameplayCameraFitter: {cell.name} has no SpriteRenderer.",
                    cell);
                return false;
            }

            EncapsulateRendererBounds(
                cellRenderer,
                ref bounds,
                ref hasBounds);
        }

        foreach (ShelfSlot plate in servingPlates)
        {
            SpriteRenderer plateRenderer =
                plate.GetComponent<SpriteRenderer>();
            if (plateRenderer == null)
            {
                Debug.LogError(
                    $"GameplayCameraFitter: {plate.name} has no SpriteRenderer.",
                    plate);
                return false;
            }

            EncapsulateRendererBounds(
                plateRenderer,
                ref bounds,
                ref hasBounds);
        }

        EncapsulateRendererBounds(
            ovenRenderer,
            ref bounds,
            ref hasBounds);

        if (!hasBounds)
        {
            Debug.LogError(
                "GameplayCameraFitter: No gameplay renderer bounds were found.",
                this);
            return false;
        }

        return true;
    }

    private static void EncapsulateRendererBounds(
        SpriteRenderer renderer,
        ref Bounds bounds,
        ref bool hasBounds)
    {
        if (!hasBounds)
        {
            bounds = renderer.bounds;
            hasBounds = true;
            return;
        }

        bounds.Encapsulate(renderer.bounds);
    }

    private void ApplyResponsiveLayout()
    {
        FitCamera();
        FitBackground();
    }

    private void FitCamera()
    {
        float aspect = gameplayCamera.aspect;
        if (aspect <= 0f)
        {
            Debug.LogError(
                "GameplayCameraFitter: Camera aspect must be greater than zero.",
                this);
            return;
        }

        Vector3 authoredCameraCenter = authoredCameraPosition;
        float halfWidth = Mathf.Max(
            Mathf.Abs(gameplayBounds.min.x - authoredCameraCenter.x),
            Mathf.Abs(gameplayBounds.max.x - authoredCameraCenter.x)) +
            worldPadding;
        float halfHeight = Mathf.Max(
            Mathf.Abs(gameplayBounds.min.y - authoredCameraCenter.y),
            Mathf.Abs(gameplayBounds.max.y - authoredCameraCenter.y)) +
            worldPadding;
        float orthographicSize = Mathf.Max(
            minimumOrthographicSize,
            halfHeight,
            halfWidth / aspect);

        gameplayCamera.orthographicSize = orthographicSize;
    }

    private void FitBackground()
    {
        float viewHeight = gameplayCamera.orthographicSize * 2f;
        float viewWidth = viewHeight * gameplayCamera.aspect;
        float coverScale = Mathf.Max(
            viewWidth / authoredBackgroundBoundsSize.x,
            viewHeight / authoredBackgroundBoundsSize.y);

        backgroundRenderer.transform.localScale =
            authoredBackgroundScale * coverScale;
        backgroundRenderer.transform.position = new Vector3(
            gameplayCamera.transform.position.x -
            authoredBackgroundBoundsOffset.x * coverScale,
            gameplayCamera.transform.position.y -
            authoredBackgroundBoundsOffset.y * coverScale,
            authoredBackgroundPosition.z);
    }

    private bool HasViewportChanged()
    {
        return !hasObservedViewport ||
               Screen.width != lastScreenWidth ||
               Screen.height != lastScreenHeight ||
               gameplayCamera.aspect != lastCameraAspect;
    }

    private void ObserveViewport()
    {
        lastScreenWidth = Screen.width;
        lastScreenHeight = Screen.height;
        lastCameraAspect = gameplayCamera.aspect;
        hasObservedViewport = true;
    }
}
