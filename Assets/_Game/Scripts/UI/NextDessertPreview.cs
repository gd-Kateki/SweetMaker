using UnityEngine;

public class NextDessertPreview : MonoBehaviour
{
    [Header("References")]
    [SerializeField]
    private DessertSpawner dessertSpawner;

    [SerializeField]
    private SpriteRenderer previewRenderer;

    [Header("Visual")]
    [SerializeField]
    private float previewScaleMultiplier = 0.75f;

    private void OnEnable()
    {
        GameplayEvents.NextDessertChanged +=
            HandleNextDessertChanged;
    }

    private void Start()
    {
        if (dessertSpawner == null)
        {
            dessertSpawner =
                FindFirstObjectByType<DessertSpawner>();
        }

        if (previewRenderer == null)
        {
            previewRenderer =
                GetComponentInChildren<SpriteRenderer>();
        }

        if (dessertSpawner == null)
        {
            Debug.LogError(
                "NextDessertPreview: " +
                "DessertSpawner could not be found."
            );

            return;
        }

        if (previewRenderer == null)
        {
            Debug.LogError(
                "NextDessertPreview: " +
                "Preview SpriteRenderer is missing."
            );

            return;
        }

        DessertDefinition currentNext =
            dessertSpawner.NextDessert;

        if (currentNext != null)
        {
            UpdatePreview(
                currentNext
            );
        }
    }

    private void OnDisable()
    {
        GameplayEvents.NextDessertChanged -=
            HandleNextDessertChanged;
    }

    private void HandleNextDessertChanged(
        DessertDefinition definition)
    {
        UpdatePreview(
            definition
        );
    }

    private void UpdatePreview(
        DessertDefinition definition)
    {
        if (definition == null ||
            previewRenderer == null)
        {
            return;
        }

        previewRenderer.sprite =
            definition.Sprite;

        previewRenderer.color =
            definition.Color;

        previewRenderer.transform.localScale =
            Vector3.one *
            definition.VisualScale *
            previewScaleMultiplier;

        previewRenderer.enabled = true;
    }
}