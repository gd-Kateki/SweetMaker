using System;
using System.IO;
using System.Security.Cryptography;
using System.Text;

namespace SweetMerge.Profile
{
    public enum LocalProfileKind
    {
        Guest = 0,
        Account = 1
    }

    public sealed class LocalProfileEnvironmentIdentity
    {
        public const string ReleaseMode = "RELEASE";
        public const string DevelopmentMode = "DEVELOPMENT-ISOLATED";
        public const string GuestQaSandboxMode = "GUEST-QA-SANDBOX";

        public string Mode { get; }
        public string RootFingerprint { get; }

        private LocalProfileEnvironmentIdentity(
            string mode,
            string rootFingerprint)
        {
            Mode = mode;
            RootFingerprint = rootFingerprint;
        }

        public static LocalProfileEnvironmentIdentity Create(
            string mode,
            string environmentRoot)
        {
            if (!IsSupportedMode(mode))
                throw new ArgumentException(
                    "The save environment mode is not supported.",
                    nameof(mode));

            return new LocalProfileEnvironmentIdentity(
                mode,
                LocalProfilePathLayout.ComputeEnvironmentRootFingerprint(
                    mode,
                    environmentRoot));
        }

        internal static bool IsSupportedMode(string mode)
        {
            return mode == ReleaseMode ||
                   mode == DevelopmentMode ||
                   mode == GuestQaSandboxMode;
        }

        internal static bool IsValidFingerprint(string fingerprint)
        {
            if (fingerprint == null || fingerprint.Length != 64)
                return false;

            for (int i = 0; i < fingerprint.Length; i++)
            {
                char character = fingerprint[i];
                if (!((character >= '0' && character <= '9') ||
                      (character >= 'a' && character <= 'f')))
                    return false;
            }

            return true;
        }

        internal static LocalProfileEnvironmentIdentity CreateFromValidated(
            string mode,
            string rootFingerprint)
        {
            if (!IsSupportedMode(mode) ||
                !IsValidFingerprint(rootFingerprint))
            {
                throw new ArgumentException(
                    "The save environment identity is invalid.");
            }

            return new LocalProfileEnvironmentIdentity(
                mode,
                rootFingerprint);
        }
    }

    public sealed class LocalProfileIdentity
    {
        private const string GuestDirectoryKey = "guest";

        public LocalProfileKind Kind { get; }
        public string PlayerId { get; }
        public string EnvironmentMode { get; }
        public string EnvironmentRootFingerprint { get; }
        public string DirectoryKey { get; }

        private LocalProfileIdentity(
            LocalProfileKind kind,
            string playerId,
            LocalProfileEnvironmentIdentity environment)
        {
            Kind = kind;
            PlayerId = playerId;
            EnvironmentMode = environment.Mode;
            EnvironmentRootFingerprint = environment.RootFingerprint;
            DirectoryKey = kind == LocalProfileKind.Guest
                ? GuestDirectoryKey
                : "uid-" + LocalProfilePathLayout.ComputePlayerIdHash(
                    playerId);
        }

        public static LocalProfileIdentity CreateGuest(
            LocalProfileEnvironmentIdentity environment)
        {
            if (environment == null)
                throw new ArgumentNullException(nameof(environment));

            return new LocalProfileIdentity(
                LocalProfileKind.Guest,
                null,
                environment);
        }

        public static LocalProfileIdentity CreateAccount(
            string playerId,
            LocalProfileEnvironmentIdentity environment)
        {
            if (environment == null)
                throw new ArgumentNullException(nameof(environment));
            ValidatePlayerId(playerId, nameof(playerId));

            return new LocalProfileIdentity(
                LocalProfileKind.Account,
                playerId,
                environment);
        }

        internal static bool TryCreate(
            LocalProfileKind kind,
            string playerId,
            LocalProfileEnvironmentIdentity environment,
            out LocalProfileIdentity identity,
            out string errorMessage)
        {
            identity = null;
            errorMessage = null;
            if (environment == null)
            {
                errorMessage = "The save environment identity is missing.";
                return false;
            }

            if (kind == LocalProfileKind.Guest)
            {
                if (!string.IsNullOrEmpty(playerId))
                {
                    errorMessage =
                        "A guest profile cannot contain a Unity PlayerId.";
                    return false;
                }

                identity = CreateGuest(environment);
                return true;
            }

            if (kind != LocalProfileKind.Account)
            {
                errorMessage = "The local profile kind is invalid.";
                return false;
            }

            if (!IsValidPlayerId(playerId))
            {
                errorMessage =
                    "An account profile must contain a valid Unity PlayerId.";
                return false;
            }

            identity = CreateAccount(playerId, environment);
            return true;
        }

        private static void ValidatePlayerId(
            string playerId,
            string parameterName)
        {
            if (!IsValidPlayerId(playerId))
            {
                throw new ArgumentException(
                    "Unity PlayerId must be nonempty and have no surrounding whitespace.",
                    parameterName);
            }
        }

        private static bool IsValidPlayerId(string playerId)
        {
            return !string.IsNullOrWhiteSpace(playerId) &&
                   string.Equals(
                       playerId,
                       playerId.Trim(),
                       StringComparison.Ordinal);
        }
    }

    public static class LocalProfilePathLayout
    {
        private const string IdentityProfilesDirectoryName =
            "IdentityProfiles";
        private const string ProfileSelectionDirectoryName =
            "ProfileSelection";
        private static readonly UTF8Encoding StrictUtf8 =
            new UTF8Encoding(false, true);

        public static string ComputeEnvironmentRootFingerprint(
            string environmentMode,
            string environmentRoot)
        {
            if (!LocalProfileEnvironmentIdentity.IsSupportedMode(
                    environmentMode))
            {
                throw new ArgumentException(
                    "The save environment mode is not supported.",
                    nameof(environmentMode));
            }

            string normalizedRoot = NormalizeRoot(environmentRoot);
            string fingerprintInput =
                environmentMode + "\n" + normalizedRoot;
            return ComputeSha256Hex(StrictUtf8.GetBytes(fingerprintInput));
        }

        public static string ComputePlayerIdHash(string playerId)
        {
            if (string.IsNullOrWhiteSpace(playerId) ||
                !string.Equals(
                    playerId,
                    playerId.Trim(),
                    StringComparison.Ordinal))
            {
                throw new ArgumentException(
                    "Unity PlayerId must be nonempty and have no surrounding whitespace.",
                    nameof(playerId));
            }

            return ComputeSha256Hex(StrictUtf8.GetBytes(playerId));
        }

        public static string GetIdentityProfilesDirectory(
            string environmentRoot,
            LocalProfileEnvironmentIdentity environment)
        {
            ValidateEnvironmentRoot(environmentRoot, environment);
            return Path.Combine(
                NormalizeRoot(environmentRoot),
                IdentityProfilesDirectoryName);
        }

        public static string GetProfileDirectory(
            string environmentRoot,
            LocalProfileIdentity identity)
        {
            if (identity == null)
                throw new ArgumentNullException(nameof(identity));

            LocalProfileEnvironmentIdentity environment =
                LocalProfileEnvironmentIdentity.CreateFromValidated(
                    identity.EnvironmentMode,
                    identity.EnvironmentRootFingerprint);
            string profilesRoot = GetIdentityProfilesDirectory(
                environmentRoot,
                environment);
            string profileDirectory = Path.GetFullPath(
                Path.Combine(profilesRoot, identity.DirectoryKey));
            EnsureContainedPath(profilesRoot, profileDirectory);
            return profileDirectory;
        }

        public static string GetProfileOwnerMetadataPath(
            string environmentRoot,
            LocalProfileIdentity identity)
        {
            return Path.Combine(
                GetProfileDirectory(environmentRoot, identity),
                "profile-owner-v1.json");
        }

        public static string GetSelectionMarkerPath(
            string environmentRoot,
            LocalProfileEnvironmentIdentity environment)
        {
            ValidateEnvironmentRoot(environmentRoot, environment);
            return Path.Combine(
                NormalizeRoot(environmentRoot),
                ProfileSelectionDirectoryName,
                "profile-selection-v1.json");
        }

        private static void ValidateEnvironmentRoot(
            string environmentRoot,
            LocalProfileEnvironmentIdentity environment)
        {
            if (environment == null)
                throw new ArgumentNullException(nameof(environment));

            string fingerprint = ComputeEnvironmentRootFingerprint(
                environment.Mode,
                environmentRoot);
            if (!string.Equals(
                    fingerprint,
                    environment.RootFingerprint,
                    StringComparison.Ordinal))
            {
                throw new ArgumentException(
                    "The environment root does not match the profile identity.",
                    nameof(environmentRoot));
            }
        }

        private static string NormalizeRoot(string environmentRoot)
        {
            if (string.IsNullOrWhiteSpace(environmentRoot) ||
                !Path.IsPathRooted(environmentRoot))
            {
                throw new ArgumentException(
                    "The environment root must be a nonempty absolute path.",
                    nameof(environmentRoot));
            }

            string fullPath = Path.GetFullPath(environmentRoot);
            string root = Path.GetPathRoot(fullPath);
            while (fullPath.Length > root.Length &&
                   (fullPath[fullPath.Length - 1] ==
                        Path.DirectorySeparatorChar ||
                    fullPath[fullPath.Length - 1] ==
                        Path.AltDirectorySeparatorChar))
            {
                fullPath = fullPath.Substring(0, fullPath.Length - 1);
            }

#if UNITY_EDITOR_WIN || UNITY_STANDALONE_WIN || UNITY_WSA
            return fullPath.ToUpperInvariant();
#else
            return fullPath;
#endif
        }

        private static void EnsureContainedPath(
            string parentPath,
            string childPath)
        {
            string normalizedParent = Path.GetFullPath(parentPath);
            string parentPrefix = normalizedParent.EndsWith(
                    Path.DirectorySeparatorChar.ToString(),
                    StringComparison.Ordinal)
                ? normalizedParent
                : normalizedParent + Path.DirectorySeparatorChar;
            StringComparison comparison =
#if UNITY_EDITOR_WIN || UNITY_STANDALONE_WIN || UNITY_WSA
                StringComparison.OrdinalIgnoreCase;
#else
                StringComparison.Ordinal;
#endif
            if (!childPath.StartsWith(parentPrefix, comparison))
            {
                throw new ArgumentException(
                    "The profile path is outside the identity profiles directory.",
                    nameof(childPath));
            }
        }

        private static string ComputeSha256Hex(byte[] bytes)
        {
            using (SHA256 sha256 = SHA256.Create())
            {
                byte[] hash = sha256.ComputeHash(bytes);
                char[] result = new char[hash.Length * 2];
                const string Hex = "0123456789abcdef";
                for (int i = 0; i < hash.Length; i++)
                {
                    result[i * 2] = Hex[hash[i] >> 4];
                    result[i * 2 + 1] = Hex[hash[i] & 0x0f];
                }

                return new string(result);
            }
        }

    }

    [Serializable]
    public sealed class LocalProfileOwnerMetadata
    {
        public int version;
        public LocalProfileKind kind;
        public string playerId;
        public string environmentMode;
        public string environmentRootFingerprint;
        public string profileKey;
    }

    public static class LocalProfileOwnerMetadataValidator
    {
        public const int CurrentVersion = 1;

        public static bool TryValidate(
            LocalProfileOwnerMetadata metadata,
            LocalProfileEnvironmentIdentity expectedEnvironment,
            out LocalProfileIdentity identity,
            out string errorMessage)
        {
            identity = null;
            errorMessage = null;
            if (metadata == null)
            {
                errorMessage = "Profile owner metadata is missing.";
                return false;
            }

            if (metadata.version != CurrentVersion)
            {
                errorMessage =
                    "Profile owner metadata has an unsupported version.";
                return false;
            }

            if (!IsExpectedEnvironment(
                    metadata.environmentMode,
                    metadata.environmentRootFingerprint,
                    expectedEnvironment,
                    out errorMessage))
                return false;

            if (!LocalProfileIdentity.TryCreate(
                    metadata.kind,
                    metadata.playerId,
                    expectedEnvironment,
                    out identity,
                    out errorMessage))
                return false;

            if (!string.Equals(
                    metadata.profileKey,
                    identity.DirectoryKey,
                    StringComparison.Ordinal))
            {
                identity = null;
                errorMessage =
                    "Profile owner key does not match its profile identity.";
                return false;
            }

            return true;
        }

        internal static bool IsExpectedEnvironment(
            string mode,
            string rootFingerprint,
            LocalProfileEnvironmentIdentity expectedEnvironment,
            out string errorMessage)
        {
            errorMessage = null;
            if (expectedEnvironment == null)
            {
                errorMessage =
                    "The expected save environment identity is missing.";
                return false;
            }

            if (!LocalProfileEnvironmentIdentity.IsSupportedMode(mode) ||
                !LocalProfileEnvironmentIdentity.IsValidFingerprint(
                    rootFingerprint) ||
                !string.Equals(
                    mode,
                    expectedEnvironment.Mode,
                    StringComparison.Ordinal) ||
                !string.Equals(
                    rootFingerprint,
                    expectedEnvironment.RootFingerprint,
                    StringComparison.Ordinal))
            {
                errorMessage =
                    "Profile metadata belongs to a different or invalid save environment.";
                return false;
            }

            return true;
        }
    }

    [Serializable]
    public sealed class LocalProfileSelectionMarker
    {
        public int version;
        public string environmentMode;
        public string environmentRootFingerprint;
        public long generation;
        public LocalProfileKind activeKind;
        public string activePlayerId;
        public string activeProfileKey;
        public bool hasPendingProfile;
        public LocalProfileKind pendingKind;
        public string pendingPlayerId;
        public string pendingProfileKey;
        public string pendingRequestId;
        public string pendingSourceProfileKey;
    }

    public sealed class ValidatedLocalProfileSelection
    {
        public long Generation { get; }
        public LocalProfileIdentity ActiveProfile { get; }
        public LocalProfileIdentity PendingProfile { get; }
        public string PendingRequestId { get; }
        public string PendingSourceProfileKey { get; }

        internal ValidatedLocalProfileSelection(
            long generation,
            LocalProfileIdentity activeProfile,
            LocalProfileIdentity pendingProfile,
            string pendingRequestId,
            string pendingSourceProfileKey)
        {
            Generation = generation;
            ActiveProfile = activeProfile;
            PendingProfile = pendingProfile;
            PendingRequestId = pendingRequestId;
            PendingSourceProfileKey = pendingSourceProfileKey;
        }
    }

    public static class LocalProfileSelectionMarkerValidator
    {
        public const int CurrentVersion = 1;

        public static bool TryValidate(
            LocalProfileSelectionMarker marker,
            LocalProfileEnvironmentIdentity expectedEnvironment,
            out ValidatedLocalProfileSelection selection,
            out string errorMessage)
        {
            selection = null;
            errorMessage = null;
            if (marker == null)
            {
                errorMessage = "Profile selection marker is missing.";
                return false;
            }

            if (marker.version != CurrentVersion)
            {
                errorMessage =
                    "Profile selection marker has an unsupported version.";
                return false;
            }

            if (!LocalProfileOwnerMetadataValidator.IsExpectedEnvironment(
                    marker.environmentMode,
                    marker.environmentRootFingerprint,
                    expectedEnvironment,
                    out errorMessage))
                return false;

            if (marker.generation < 1)
            {
                errorMessage =
                    "Profile selection marker generation must be positive.";
                return false;
            }

            if (!LocalProfileIdentity.TryCreate(
                    marker.activeKind,
                    marker.activePlayerId,
                    expectedEnvironment,
                    out LocalProfileIdentity activeProfile,
                    out errorMessage))
                return false;

            if (!string.Equals(
                    marker.activeProfileKey,
                    activeProfile.DirectoryKey,
                    StringComparison.Ordinal))
            {
                errorMessage =
                    "Active profile key does not match its profile identity.";
                return false;
            }

            if (!marker.hasPendingProfile)
            {
                if (marker.pendingKind != LocalProfileKind.Guest ||
                    !string.IsNullOrEmpty(marker.pendingPlayerId) ||
                    !string.IsNullOrEmpty(marker.pendingProfileKey) ||
                    !string.IsNullOrEmpty(marker.pendingRequestId) ||
                    !string.IsNullOrEmpty(marker.pendingSourceProfileKey))
                {
                    errorMessage =
                        "Unmarked pending profile fields must be empty.";
                    return false;
                }

                selection = new ValidatedLocalProfileSelection(
                    marker.generation,
                    activeProfile,
                    null,
                    null,
                    null);
                return true;
            }

            if (marker.pendingKind != LocalProfileKind.Account ||
                !LocalProfileIdentity.TryCreate(
                    marker.pendingKind,
                    marker.pendingPlayerId,
                    expectedEnvironment,
                    out LocalProfileIdentity pendingProfile,
                    out errorMessage))
            {
                if (string.IsNullOrEmpty(errorMessage))
                {
                    errorMessage =
                        "A pending profile must be a valid account profile.";
                }

                return false;
            }

            if (!string.Equals(
                    marker.pendingProfileKey,
                    pendingProfile.DirectoryKey,
                    StringComparison.Ordinal) ||
                string.Equals(
                    pendingProfile.DirectoryKey,
                    activeProfile.DirectoryKey,
                    StringComparison.Ordinal) ||
                !string.Equals(
                    marker.pendingSourceProfileKey,
                    activeProfile.DirectoryKey,
                    StringComparison.Ordinal) ||
                !IsCanonicalRequestId(marker.pendingRequestId))
            {
                errorMessage =
                    "Pending profile fields do not match the active profile and account identity.";
                return false;
            }

            selection = new ValidatedLocalProfileSelection(
                marker.generation,
                activeProfile,
                pendingProfile,
                marker.pendingRequestId,
                marker.pendingSourceProfileKey);
            return true;
        }

        private static bool IsCanonicalRequestId(string requestId)
        {
            return Guid.TryParseExact(requestId, "N", out Guid parsed) &&
                   string.Equals(
                       requestId,
                       parsed.ToString("N"),
                       StringComparison.Ordinal);
        }
    }
}
