using UnityEngine;

public class Dessert : MonoBehaviour
{
    [SerializeField] private DessertDefinition definition;

    private GridCell currentCell;

    public DessertDefinition Definition => definition;
    public int Tier => definition != null ? definition.Tier : -1;
    public GridCell CurrentCell => currentCell;

    public void Initialize(
        DessertDefinition newDefinition,
        GridCell cell)
    {
        definition = newDefinition;
        currentCell = cell;

        ApplyDefinition();
    }

    public void SetCurrentCell(GridCell cell)
    {
        currentCell = cell;
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

    SpriteRenderer spriteRenderer =
        GetComponent<SpriteRenderer>();

    if (spriteRenderer != null)
    {
        if (definition.Sprite != null)
        {
            spriteRenderer.sprite = definition.Sprite;
        }

        spriteRenderer.color = definition.Color;
    }

    name = $"Dessert_{definition.DisplayName}";
}
}