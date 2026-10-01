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
    private Color normalColor = Color.white;

    [SerializeField]
    private Color validColor = Color.green;

    [SerializeField]
    private Color mergeColor = Color.yellow;

    [SerializeField]
    private Color invalidColor = Color.red;

    [Header("Rendering")]
    [SerializeField]
    private string sortingLayerName = "Board";

    [SerializeField]
    private int sortingOrder = 0;

    private Dessert currentDessert;

    public bool IsEmpty =>
        currentDessert == null;

    public Dessert CurrentDessert =>
        currentDessert;

    public Vector3 ContentPosition
    {
        get
        {
            Vector3 position;

            if (contentPoint != null)
            {
                position =
                    contentPoint.position;
            }
            else
            {
                position =
                    transform.position;
            }

            position.z = 0f;

            return position;
        }
    }

    private void Awake()
    {
        ResolveReferences();
        ApplyRendering();
        ClearHighlight();
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

    public void PlaceDessert(
    Dessert dessert,
    bool snapToCell = true)
{
    if (dessert == null)
        return;

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

    public void ShowValidHighlight()
    {
        SetColor(validColor);
    }

    public void ShowMergeHighlight()
    {
        SetColor(mergeColor);
    }

    public void ShowInvalidHighlight()
    {
        SetColor(invalidColor);
    }

    public void ClearHighlight()
    {
        SetColor(normalColor);
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