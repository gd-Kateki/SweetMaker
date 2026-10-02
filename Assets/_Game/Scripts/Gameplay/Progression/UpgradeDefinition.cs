using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(
    fileName = "Upgrade_",
    menuName = "Sweet Merge/Upgrade Definition"
)]
public class UpgradeDefinition :
    ScriptableObject
{
    [Header("Identity")]
    [SerializeField]
    private UpgradeType upgradeType;

    [SerializeField]
    private string displayName =
        "Upgrade";

    [Header("Levels")]
    [SerializeField]
    private UpgradeLevelData[] levels;

    // ==================================================
    // PUBLIC DATA
    // ==================================================

    public UpgradeType UpgradeType =>
        upgradeType;

    public string DisplayName =>
        displayName;

    public IReadOnlyList<UpgradeLevelData>
        Levels =>
            levels;

    public int MaxLevel
    {
        get
        {
            if (levels == null)
                return 0;

            return levels.Length;
        }
    }

    // ==================================================
    // VALIDATION
    // ==================================================

    public bool IsValid
    {
        get
        {
            if (levels == null ||
                levels.Length == 0)
            {
                return false;
            }

            for (int i = 0;
                 i < levels.Length;
                 i++)
            {
                UpgradeLevelData level =
                    levels[i];

                if (level == null)
                    return false;

                int expectedLevel =
                    i + 1;

                if (level.Level !=
                    expectedLevel)
                {
                    return false;
                }

                if (level.UpgradeCost < 0)
                    return false;

                // Level 1 is the starting level.
                // It should never require a purchase.
                if (expectedLevel == 1 &&
                    level.UpgradeCost != 0)
                {
                    return false;
                }
            }

            return true;
        }
    }

    // ==================================================
    // LEVEL LOOKUP
    // ==================================================

    public UpgradeLevelData GetLevel(
        int level)
    {
        if (levels == null)
            return null;

        if (level < 1 ||
            level > levels.Length)
        {
            return null;
        }

        return levels[
            level - 1
        ];
    }

    public UpgradeLevelData GetNextLevel(
        int currentLevel)
    {
        return GetLevel(
            currentLevel + 1
        );
    }

    // ==================================================
    // MAX LEVEL
    // ==================================================

    public bool IsMaxLevel(
        int currentLevel)
    {
        if (MaxLevel <= 0)
            return true;

        return currentLevel >=
            MaxLevel;
    }

    // ==================================================
    // COST
    // ==================================================

    /// <summary>
    /// Returns the cash required to upgrade from the
    /// supplied current level to the next level.
    ///
    /// Returns 0 when there is no next level.
    /// </summary>
    public int GetNextUpgradeCost(
        int currentLevel)
    {
        UpgradeLevelData nextLevel =
            GetNextLevel(
                currentLevel
            );

        if (nextLevel == null)
            return 0;

        return nextLevel.UpgradeCost;
    }

    // ==================================================
    // DEBUG
    // ==================================================

    [ContextMenu("Debug Upgrade Definition")]
    private void DebugUpgradeDefinition()
    {
        Debug.Log(
            $"UPGRADE DEFINITION | " +
            $"{displayName} | " +
            $"Type: {upgradeType} | " +
            $"Levels: {MaxLevel} | " +
            $"Valid: {IsValid}"
        );

        if (levels == null)
            return;

        foreach (
            UpgradeLevelData level
            in levels)
        {
            if (level == null)
            {
                Debug.LogWarning(
                    $"{displayName} contains " +
                    "a null level."
                );

                continue;
            }

            Debug.Log(
                $"{displayName} | " +
                $"Level {level.Level} | " +
                $"Int Value: " +
                $"{level.IntValue} | " +
                $"Float Value: " +
                $"{level.FloatValue:0.##} | " +
                $"Cost: ${level.UpgradeCost}"
            );
        }
    }
}