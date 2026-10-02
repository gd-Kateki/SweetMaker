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
            }

            return true;
        }
    }

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
}