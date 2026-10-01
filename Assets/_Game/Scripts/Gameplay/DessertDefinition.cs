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
    [SerializeField] private Color color = Color.white;
    [SerializeField] private Sprite sprite;

    [Header("Oven")]
    [SerializeField] private bool canSpawnFromOven = true;

    [Min(0f)]
    [SerializeField] private float spawnWeight = 1f;

    public int Tier => tier;
    public string DisplayName => displayName;
    public Sprite Sprite => sprite;
    public bool CanSpawnFromOven => canSpawnFromOven;
    public float SpawnWeight => spawnWeight;
    public Color Color => color;
}