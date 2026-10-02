using System;
using UnityEngine;

[Serializable]
public class UpgradeLevelData
{
    [Min(1)]
    [SerializeField]
    private int level = 1;

    [SerializeField]
    private int intValue;

    [SerializeField]
    private float floatValue;

    public int Level =>
        level;

    public int IntValue =>
        intValue;

    public float FloatValue =>
        floatValue;
}