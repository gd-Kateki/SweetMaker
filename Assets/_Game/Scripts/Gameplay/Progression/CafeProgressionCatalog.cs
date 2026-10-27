public static class CafeProgressionCatalog
{
    public const int MaximumCompletedRebirthCount = 10;
    public const int MaximumRegularStarLevel = 5;

    private static readonly string[] CafeTitles =
    {
        "Humble Beginnings",
        "Aspiring Baker",
        "Sweet Apprentice",
        "Rising Cafe",
        "Neighborhood Favorite",
        "Established Cafe",
        "Celebrated Baker",
        "Renowned Cafe",
        "Dessert Artisan",
        "Master of Sweets",
        "Legendary Cafe"
    };

    private static readonly int[] RegularStarUnlockRebirths =
    {
        0, 3, 5, 7, 10
    };

    public static bool TryGetCafeTitle(
        int completedRebirthCount,
        out string cafeTitle)
    {
        cafeTitle = null;
        if (!IsValidRebirthCount(completedRebirthCount))
            return false;

        cafeTitle = CafeTitles[completedRebirthCount];
        return true;
    }

    public static bool TryGetRegularStarLevel(
        int completedRebirthCount,
        out int starLevel)
    {
        starLevel = 0;
        if (!IsValidRebirthCount(completedRebirthCount))
            return false;

        for (int i = 0; i < RegularStarUnlockRebirths.Length; i++)
        {
            if (completedRebirthCount < RegularStarUnlockRebirths[i])
                break;

            starLevel++;
        }

        return true;
    }

    public static bool TryGetNextRegularStarRebirth(
        int completedRebirthCount,
        out int? nextStarRebirth)
    {
        nextStarRebirth = null;
        if (!IsValidRebirthCount(completedRebirthCount))
            return false;

        for (int i = 0; i < RegularStarUnlockRebirths.Length; i++)
        {
            if (RegularStarUnlockRebirths[i] > completedRebirthCount)
            {
                nextStarRebirth = RegularStarUnlockRebirths[i];
                break;
            }
        }

        return true;
    }

    private static bool IsValidRebirthCount(int completedRebirthCount)
    {
        return completedRebirthCount >= 0 &&
               completedRebirthCount <= MaximumCompletedRebirthCount;
    }
}
