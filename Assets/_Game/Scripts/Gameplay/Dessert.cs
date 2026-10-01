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

    public DessertDefinition Definition =>
        definition;

    public int Tier =>
        definition != null
            ? definition.Tier
            : -1;

    public GridCell CurrentCell =>
        currentCell;

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

    public void Initialize(
        DessertDefinition newDefinition,
        GridCell cell)
    {
        definition = newDefinition;
        currentCell = cell;

        ResolveReferences();
        ApplyDefinition();
        ApplyNormalRendering();
    }

    public void SetCurrentCell(
        GridCell cell)
    {
        currentCell = cell;
    }

    public void ApplyNormalRendering()
    {
        if (spriteRenderer == null)
            return;

        spriteRenderer.enabled = true;

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

        spriteRenderer.enabled = true;

        spriteRenderer.sortingLayerName =
            sortingLayerName;

        spriteRenderer.sortingOrder =
            draggingOrder;
    }

    private void ResolveReferences()
    {
        if (visual == null)
        {
            Transform foundVisual =
                transform.Find("Visual");

            if (foundVisual != null)
            {
                visual = foundVisual;
            }
        }

        if (spriteRenderer == null &&
            visual != null)
        {
            spriteRenderer =
                visual.GetComponent<SpriteRenderer>();
        }

        if (spriteRenderer == null)
        {
            spriteRenderer =
                GetComponentInChildren<SpriteRenderer>(
                    true
                );
        }
    }

    private void ApplyDefinition()
    {
        if (definition == null)
        {
            Debug.LogError(
                $"{name}: DessertDefinition is missing."
            );

            return;
        }

        if (spriteRenderer == null)
        {
            Debug.LogError(
                $"{name}: Dessert SpriteRenderer is missing."
            );

            return;
        }

        if (definition.Sprite == null)
        {
            Debug.LogError(
                $"{definition.DisplayName} has no sprite assigned."
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
                $"{name}: Visual Transform is missing."
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

        // Keep all gameplay desserts on
        // the same Z plane.
        Vector3 position =
            transform.position;

        position.z = 0f;

        transform.position =
            position;

        name =
            $"Dessert_{definition.DisplayName}";
    }
}