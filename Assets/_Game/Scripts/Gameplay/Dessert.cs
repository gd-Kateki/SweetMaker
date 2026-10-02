using UnityEngine;

public class Dessert : MonoBehaviour
{
    [Header("Definition")]
    [SerializeField]
    private DessertDefinition definition;

    [Header("Visual")]
    [SerializeField]
    private Transform visual;

    [SerializeField]
    private SpriteRenderer spriteRenderer;

    [Header("Rendering")]
    [SerializeField]
    private string sortingLayerName = "Desserts";

    [SerializeField]
    private int normalSortingOrder = 10;

    private GridCell currentCell;
    private ShelfSlot currentShelfSlot;

    public DessertDefinition Definition =>
        definition;

    public int Tier =>
        definition != null
            ? definition.Tier
            : -1;

    public DessertLocationType LocationType
    {
        get
        {
            if (currentCell != null)
                return DessertLocationType.Board;

            if (currentShelfSlot != null)
                return DessertLocationType.Shelf;

            return DessertLocationType.None;
        }
    }

    public bool IsOnBoard =>
        LocationType ==
        DessertLocationType.Board;

    public bool IsOnShelf =>
        LocationType ==
        DessertLocationType.Shelf;

    public GridCell CurrentCell =>
        currentCell;

    public ShelfSlot CurrentShelfSlot =>
        currentShelfSlot;

    public Transform Visual =>
        visual;

    public SpriteRenderer SpriteRenderer =>
        spriteRenderer;

    public int NormalSortingOrder =>
        normalSortingOrder;

    private void Awake()
    {
        ResolveReferences();
    }

    // --------------------------------------------------
    // INITIALIZATION
    // --------------------------------------------------

    public void Initialize(
        DessertDefinition newDefinition,
        GridCell cell)
    {
        definition =
            newDefinition;

        SetCurrentCell(
            cell
        );

        ResolveReferences();
        ApplyDefinition();
        ApplyNormalRendering();
    }

    // --------------------------------------------------
    // LOCATION
    // --------------------------------------------------

    public void SetCurrentCell(
        GridCell cell)
    {
        currentCell =
            cell;

        if (cell != null)
        {
            currentShelfSlot =
                null;
        }
    }

    public void SetCurrentShelfSlot(
        ShelfSlot shelfSlot)
    {
        currentShelfSlot =
            shelfSlot;

        if (shelfSlot != null)
        {
            currentCell =
                null;
        }
    }

    public void ClearLocation()
    {
        currentCell = null;
        currentShelfSlot = null;
    }

    // --------------------------------------------------
    // RENDERING
    // --------------------------------------------------

    public void ApplyNormalRendering()
    {
        if (spriteRenderer == null)
            return;

        spriteRenderer.enabled =
            true;

        spriteRenderer.sortingLayerName =
            sortingLayerName;

        spriteRenderer.sortingOrder =
            normalSortingOrder;
    }

    public void ApplyDraggingRendering(
        int draggingOrder)
    {
        if (spriteRenderer == null)
            return;

        spriteRenderer.enabled =
            true;

        spriteRenderer.sortingLayerName =
            sortingLayerName;

        spriteRenderer.sortingOrder =
            draggingOrder;
    }

    // --------------------------------------------------
    // REFERENCES
    // --------------------------------------------------

    private void ResolveReferences()
    {
        if (visual == null)
        {
            Transform foundVisual =
                transform.Find("Visual");

            if (foundVisual != null)
            {
                visual =
                    foundVisual;
            }
        }

        if (spriteRenderer == null &&
            visual != null)
        {
            spriteRenderer =
                visual.GetComponent<
                    SpriteRenderer>();
        }

        if (spriteRenderer == null)
        {
            spriteRenderer =
                GetComponentInChildren<
                    SpriteRenderer>(true);
        }
    }

    // --------------------------------------------------
    // DEFINITION
    // --------------------------------------------------

    private void ApplyDefinition()
    {
        if (definition == null)
        {
            Debug.LogError(
                $"{name}: " +
                "DessertDefinition is missing."
            );

            return;
        }

        if (spriteRenderer == null)
        {
            Debug.LogError(
                $"{name}: " +
                "Dessert SpriteRenderer is missing."
            );

            return;
        }

        if (definition.Sprite == null)
        {
            Debug.LogError(
                $"{definition.DisplayName} " +
                "has no sprite assigned."
            );
        }
        else
        {
            spriteRenderer.sprite =
                definition.Sprite;
        }

        spriteRenderer.color =
            definition.Color;

        if (visual == null)
        {
            Debug.LogError(
                $"{name}: " +
                "Visual Transform is missing."
            );
        }
        else
        {
            visual.localPosition =
                Vector3.zero;

            visual.localRotation =
                Quaternion.identity;

            visual.localScale =
                Vector3.one *
                definition.VisualScale;
        }

        Vector3 position =
            transform.position;

        position.z = 0f;

        transform.position =
            position;

        name =
            $"Dessert_" +
            $"{definition.DisplayName}";
    }

    // --------------------------------------------------
    // DEBUG
    // --------------------------------------------------

    [ContextMenu("Debug Dessert Location")]
    private void DebugDessertLocation()
    {
        string locationName;

        switch (LocationType)
        {
            case DessertLocationType.Board:
                locationName =
                    currentCell != null
                        ? currentCell.name
                        : "Missing GridCell";
                break;

            case DessertLocationType.Shelf:
                locationName =
                    currentShelfSlot != null
                        ? currentShelfSlot.name
                        : "Missing ShelfSlot";
                break;

            default:
                locationName = "None";
                break;
        }

        Debug.Log(
            $"DESSERT LOCATION | " +
            $"{name} | " +
            $"Type: {LocationType} | " +
            $"Location: {locationName}"
        );
    }
}