using UnityEngine;

[CreateAssetMenu(
    fileName = "Dessert_",
    menuName = "Sweet Merge/Dessert Definition"
)]
public class DessertDefinition : ScriptableObject
{
    [Header("Identity")]
    [SerializeField] private int tier = 1;
    [SerializeField] private string displayName = "Dessert";

    [Header("Visual")]
    [SerializeField] private Sprite sprite;
    [SerializeField] private Color color = Color.white;

    [Range(0.1f, 2f)]
    [SerializeField] private float visualScale = 0.8f;

    [Header("Oven")]
    [SerializeField] private bool canSpawnFromOven = true;

    [Min(0f)]
    [SerializeField] private float spawnWeight = 1f;

    public int Tier => tier;
    public string DisplayName => displayName;

    public Sprite Sprite => sprite;
    public Color Color => color;
    public float VisualScale => visualScale;

    public bool CanSpawnFromOven => canSpawnFromOven;
    public float SpawnWeight => spawnWeight;
}