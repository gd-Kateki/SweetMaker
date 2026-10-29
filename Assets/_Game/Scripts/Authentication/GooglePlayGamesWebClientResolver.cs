using System;
using System.Text.RegularExpressions;
using GooglePlayGames;

namespace SweetMerge.Authentication
{
    public static class GooglePlayGamesWebClientResolver
    {
        public const string DevelopmentApplicationIdentifier =
            "com.offcutstudios.dessertmergecafe.dev";
        public const string ProductionApplicationIdentifier =
            "com.offcutstudios.dessertmergecafe";

        // Set only from the verified Production Web OAuth client configuration.
        public const string ProductionWebClientId = "264102460103-0q49b3h7bsqbgd04etbio72e5l3ndo9n.apps.googleusercontent.com";

        private static readonly Regex WebClientIdPattern = new Regex(
            @"\A[0-9]+-[A-Za-z0-9-]+\.apps\.googleusercontent\.com\z",
            RegexOptions.CultureInvariant);

        public static string Resolve(
            string applicationIdentifier,
            string developmentWebClientId,
            string productionWebClientId)
        {
            string clientId;
            switch (applicationIdentifier)
            {
                case DevelopmentApplicationIdentifier:
                    clientId = developmentWebClientId;
                    break;
                case ProductionApplicationIdentifier:
                    clientId = productionWebClientId;
                    break;
                default:
                    throw new InvalidOperationException(
                        "Google Play Games authentication is unsupported for this application identifier.");
            }

            if (!IsValidWebClientId(clientId))
            {
                throw new InvalidOperationException(
                    "The Google Play Games Web OAuth client configuration is missing or invalid.");
            }

            return clientId;
        }

        public static void InvokeWithSelectedClient(
            string applicationIdentifier,
            PlayGamesSettings settings,
            string productionWebClientId,
            Action requestServerSideAccess)
        {
            if (settings == null)
                throw new ArgumentNullException(nameof(settings));
            if (requestServerSideAccess == null)
                throw new ArgumentNullException(nameof(requestServerSideAccess));

            string originalClientId = settings.WebClientId;
            string selectedClientId = Resolve(
                applicationIdentifier,
                originalClientId,
                productionWebClientId);

            try
            {
                settings.WebClientId = selectedClientId;
                requestServerSideAccess();
            }
            finally
            {
                settings.WebClientId = originalClientId;
            }
        }

        public static bool IsValidWebClientId(string clientId)
        {
            return !string.IsNullOrWhiteSpace(clientId) &&
                   WebClientIdPattern.IsMatch(clientId);
        }
    }
}
