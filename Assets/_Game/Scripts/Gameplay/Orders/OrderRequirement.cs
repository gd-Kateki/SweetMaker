using System;
using UnityEngine;

[Serializable]
public class OrderRequirement
{
    [SerializeField]
    private DessertDefinition dessert;

    [Min(1)]
    [SerializeField]
    private int amount = 1;

    public DessertDefinition Dessert =>
        dessert;

    public int Amount =>
        amount;

    public OrderRequirement(
        DessertDefinition dessert,
        int amount)
    {
        this.dessert = dessert;
        this.amount = amount;
    }
}