using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(
    fileName = "Order_",
    menuName = "Sweet Merge/Customer Order"
)]
public class CustomerOrderDefinition :
    ScriptableObject
{
    [Header("Identity")]
    [SerializeField]
    private string displayName =
        "Customer Order";

    [Header("Requirements")]
    [SerializeField]
    private OrderRequirement[] requirements;

    [Header("Prototype Reward")]
    [Min(0)]
    [SerializeField]
    private int cashReward = 10;

    public string DisplayName =>
        displayName;

    public IReadOnlyList<OrderRequirement>
        Requirements =>
            requirements;

    public int CashReward =>
        cashReward;

    public bool IsValid
    {
        get
        {
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

    private void OnValidate()
    {
        if (cashReward < 0)
        {
            cashReward = 0;
        }
    }
}