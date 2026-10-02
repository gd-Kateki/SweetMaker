using System;
using UnityEngine;

[Serializable]
public class UpgradeLevelData
{
    [Header("Level")]
    [Min(1)]
    [SerializeField]
    private int level = 1;

    [Header("Gameplay Value")]
    [SerializeField]
    private int intValue;

    [SerializeField]
    private float floatValue;

    [Header("Purchase")]
    [Min(0)]
    [SerializeField]
    private int upgradeCost = 0;

    // ==================================================
    // PUBLIC DATA
    // ==================================================

    public int Level =>
        level;

    public int IntValue =>
        intValue;

    public float FloatValue =>
        floatValue;

    /// <summary>
    /// Cash required to reach this level.
    ///
    /// Level 1 should normally have a cost of 0
    /// because it is the starting level.
    /// </summary>
    public int UpgradeCost =>
        upgradeCost;
}