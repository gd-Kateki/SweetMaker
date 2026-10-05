using System;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(
    fileName = "Order_",
    menuName = "Sweet Merge/Customer Order"
)]
public class CustomerOrderDefinition :
    ScriptableObject
{
    // ==================================================
    // IDENTITY
    // ==================================================

    [Header("Identity")]
    [SerializeField]
    private string definitionId;

    [SerializeField]
    private string displayName =
        "Customer Order";

    // ==================================================
    // REQUIREMENTS
    // ==================================================

    [Header("Requirements")]
    [SerializeField]
    private OrderRequirement[] requirements;

    // ==================================================
    // REWARD
    // ==================================================

    [Header("Prototype Reward")]
    [Min(0)]
    [SerializeField]
    private int cashReward = 10;

    // ==================================================
    // PUBLIC PROPERTIES
    // ==================================================

    public string DefinitionId =>
        definitionId;

    public string DisplayName =>
        displayName;

    public IReadOnlyList<OrderRequirement>
        Requirements =>
            requirements;

    public int CashReward =>
        cashReward;

    // ==================================================
    // VALIDATION
    // ==================================================

    public bool IsValid
    {
        get
        {
            if (string.IsNullOrWhiteSpace(
                    definitionId))
            {
                return false;
            }

            if (requirements == null ||
                requirements.Length == 0)
            {
                return false;
            }

            HashSet<DessertDefinition>
                usedDesserts =
                    new HashSet<DessertDefinition>();

            foreach (
                OrderRequirement requirement
                in requirements)
            {
                if (requirement == null)
                    return false;

                if (requirement.Dessert == null)
                    return false;

                if (requirement.Amount <= 0)
                    return false;

                if (!usedDesserts.Add(
                        requirement.Dessert))
                {
                    return false;
                }
            }

            return true;
        }
    }

    // ==================================================
    // UNITY EDITOR VALIDATION
    // ==================================================

    private void OnValidate()
    {
        /*
         * Every CustomerOrderDefinition needs a
         * permanent unique ID for save/load.
         *
         * Once generated, this value should remain
         * unchanged for the lifetime of the asset.
         */
        if (string.IsNullOrWhiteSpace(
                definitionId))
        {
            definitionId =
                Guid.NewGuid().ToString("N");

#if UNITY_EDITOR
            UnityEditor.EditorUtility.SetDirty(
                this
            );
#endif
        }

        /*
         * Preserve the existing reward validation.
         */
        if (cashReward < 0)
        {
            cashReward = 0;
        }
    }
}