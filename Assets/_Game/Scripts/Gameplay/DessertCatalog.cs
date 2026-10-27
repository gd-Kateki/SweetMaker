using System;
using UnityEngine;

[CreateAssetMenu(
    fileName = "DessertCatalog",
    menuName = "Sweet Merge/Dessert Catalog"
)]
public sealed class DessertCatalog : ScriptableObject
{
    public const int InitialTierCount = 30;
    private const string SharedResourceName = "DessertCatalog";

    [SerializeField] private DessertDefinition[] definitions;

    private static DessertCatalog sharedCatalog;

    public System.Collections.Generic.IReadOnlyList<DessertDefinition>
        Definitions =>
            definitions ??
            Array.Empty<DessertDefinition>();

    public static DessertCatalog LoadShared()
    {
        if (sharedCatalog == null)
            sharedCatalog =
                Resources.Load<DessertCatalog>(SharedResourceName);

        return sharedCatalog;
    }

    public DessertDefinition GetDefinitionByTier(int tier)
    {
        if (tier < 1 || tier > InitialTierCount ||
            definitions == null)
        {
            return null;
        }

        foreach (DessertDefinition definition in definitions)
        {
            if (definition != null &&
                definition.Tier == tier)
            {
                return definition;
            }
        }

        return null;
    }

    public bool TryValidate(out string failureReason)
    {
        failureReason = null;
        if (definitions == null ||
            definitions.Length != InitialTierCount)
        {
            failureReason =
                $"Catalog must contain exactly {InitialTierCount} dessert definitions.";
            return false;
        }

        var tiers = new bool[InitialTierCount + 1];
        foreach (DessertDefinition definition in definitions)
        {
            if (definition == null)
            {
                failureReason =
                    "Catalog contains a missing dessert definition.";
                return false;
            }

            int tier = definition.Tier;
            if (tier < 1 ||
                tier > InitialTierCount ||
                tiers[tier])
            {
                failureReason =
                    $"Catalog contains an invalid or duplicate tier ID ({tier}).";
                return false;
            }

            if (string.IsNullOrWhiteSpace(definition.DisplayName) ||
                definition.Sprite == null)
            {
                failureReason =
                    $"Tier {tier} is missing its display name or sprite.";
                return false;
            }

            tiers[tier] = true;
        }

        for (int tier = 1; tier <= InitialTierCount; tier++)
        {
            if (!tiers[tier])
            {
                failureReason =
                    $"Catalog is missing tier {tier}.";
                return false;
            }
        }

        return true;
    }

    private void OnValidate()
    {
        if (!TryValidate(out string failureReason))
        {
            Debug.LogError(
                "Dessert catalog validation failed: " +
                failureReason,
                this);
        }
    }
}
