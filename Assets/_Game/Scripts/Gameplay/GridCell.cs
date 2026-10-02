using UnityEngine;

public class GridCell : MonoBehaviour
{
    [Header("Content")]
    [SerializeField]
    private Transform contentPoint;

    [Header("Highlight")]
    [SerializeField]
    private SpriteRenderer cellRenderer;

    [SerializeField]
    private Color normalColor =
        Color.white;

    [SerializeField]
    private Color validColor =
        Color.green;

    [SerializeField]
    private Color mergeColor =
        Color.yellow;

    [SerializeField]
    private Color invalidColor =
        Color.red;

    [Header("Locked State")]
    [SerializeField]
    private Color lockedColor =
        new Color(
            0.25f,
            0.25f,
            0.25f,
            1f
        );

    [Header("Rendering")]
    [SerializeField]
    private string sortingLayerName =
        "Board";

    [SerializeField]
    private int sortingOrder = 0;

    private Dessert currentDessert;

    private bool isUnlocked = true;

    public bool IsEmpty =>
        currentDessert == null;

    public bool IsUnlocked =>
        isUnlocked;

    public bool IsAvailable =>
        isUnlocked &&
        IsEmpty;

    public Dessert CurrentDessert =>
        currentDessert;

    public Vector3 ContentPosition
    {
        get
        {
            Vector3 position =
                contentPoint != null
                    ? contentPoint.position
                    : transform.position;

            position.z = 0f;

            return position;
        }
    }

    private void Awake()
    {
        ResolveReferences();
        ApplyRendering();
        RefreshVisualState();
    }

    private void ResolveReferences()
    {
        if (cellRenderer == null)
        {
            cellRenderer =
                GetComponent<SpriteRenderer>();
        }
    }

    private void ApplyRendering()
    {
        if (cellRenderer == null)
            return;

        cellRenderer.enabled = true;

        cellRenderer.sortingLayerName =
            sortingLayerName;

        cellRenderer.sortingOrder =
            sortingOrder;
    }

    // --------------------------------------------------
    // LOCK STATE
    // --------------------------------------------------

    public void SetUnlocked(
        bool unlocked)
    {
        if (!unlocked &&
            currentDessert != null)
        {
            Debug.LogWarning(
                $"{name}: Cannot lock this " +
                "cell because it currently " +
                "contains a dessert."
            );

            return;
        }

        isUnlocked =
            unlocked;

        RefreshVisualState();
    }

    // --------------------------------------------------
    // DESSERT OCCUPANCY
    // --------------------------------------------------

    public void PlaceDessert(
        Dessert dessert,
        bool snapToCell = true)
    {
        if (dessert == null)
            return;

        if (!isUnlocked)
        {
            Debug.LogWarning(
                $"{name}: Cannot place a " +
                "dessert into a locked cell."
            );

            return;
        }

        if (!IsEmpty &&
            currentDessert != dessert)
        {
            Debug.LogWarning(
                $"{name} is already occupied."
            );

            return;
        }

        currentDessert =
            dessert;

        dessert.SetCurrentCell(
            this
        );

        if (snapToCell)
        {
            dessert.transform.position =
                ContentPosition;
        }

        dessert.ApplyNormalRendering();
    }

    public void RemoveDessert(
        Dessert dessert)
    {
        if (currentDessert != dessert)
            return;

        currentDessert = null;
    }

    // --------------------------------------------------
    // HIGHLIGHT
    // --------------------------------------------------

    public void ShowValidHighlight()
    {
        if (!isUnlocked)
            return;

        SetColor(
            validColor
        );
    }

    public void ShowMergeHighlight()
    {
        if (!isUnlocked)
            return;

        SetColor(
            mergeColor
        );
    }

    public void ShowInvalidHighlight()
    {
        if (!isUnlocked)
            return;

        SetColor(
            invalidColor
        );
    }

    public void ClearHighlight()
    {
        RefreshVisualState();
    }

    private void RefreshVisualState()
    {
        if (isUnlocked)
        {
            SetColor(
                normalColor
            );
        }
        else
        {
            SetColor(
                lockedColor
            );
        }
    }

    private void SetColor(
        Color color)
    {
        if (cellRenderer != null)
        {
            cellRenderer.color =
                color;
        }
    }
}