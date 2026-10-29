namespace SweetMerge.Authentication
{
    public static class GooglePlayGamesAndroidBuildRequirements
    {
        public const int DevelopmentMinimumApiLevel = 32;
        public const int ProductionMinimumApiLevel = 29;
        public const int ProductionTargetApiLevel = 36;

        public static string ValidateApiLevels(
            int minimumApiLevel,
            bool targetApiIsAutomatic,
            int? targetApiLevel,
            bool developmentBuild)
        {
            int requiredMinimumApiLevel = developmentBuild
                ? DevelopmentMinimumApiLevel
                : ProductionMinimumApiLevel;
            if (minimumApiLevel != requiredMinimumApiLevel)
            {
                return developmentBuild
                    ? "Development Android builds require minimum API level " +
                        requiredMinimumApiLevel + "."
                    : "Release Android builds require minimum API level " +
                        requiredMinimumApiLevel + ".";
            }

            if (developmentBuild)
            {
                if (!targetApiIsAutomatic &&
                    (!targetApiLevel.HasValue || targetApiLevel.Value <= 0))
                {
                    return "The effective Development Android target API is unknown or invalid.";
                }

                return null;
            }

            if (!targetApiIsAutomatic &&
                (!targetApiLevel.HasValue ||
                 targetApiLevel.Value != ProductionTargetApiLevel))
            {
                return "Release Android builds require Automatic or target API level " +
                    ProductionTargetApiLevel + ".";
            }

            return null;
        }
    }
}
