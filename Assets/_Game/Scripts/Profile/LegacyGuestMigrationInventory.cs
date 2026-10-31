using System;
using System.Collections.Generic;
using System.IO;
using System.Security.Cryptography;

namespace SweetMerge.Profile
{
    public sealed class LegacyGuestMigrationInventoryEntry
    {
        private readonly byte[] bytes;

        public string RelativePath { get; }
        public long ByteLength => bytes.Length;
        public string Sha256 { get; }

        internal LegacyGuestMigrationInventoryEntry(
            string relativePath,
            byte[] content)
        {
            RelativePath = relativePath;
            bytes = (byte[])content.Clone();
            Sha256 = LegacyGuestMigrationInventory.ComputeSha256(bytes);
        }

        public byte[] CopyBytes()
        {
            return (byte[])bytes.Clone();
        }
    }

    public sealed class LegacyGuestMigrationInventory
    {
        private const int MaximumRelativePathLength = 1024;
        private const string SaveV2FileName = "player_save_v2.json";
        private const string SaveV1FileName = "player_save.json";
        private const string CafeDirectoryName = "CafeProfile";
        private const string CafeFileName = "cafe-profile-v1.json";
        private const string TutorialDirectoryName = "TutorialProgress";
        private const string TutorialFileName = "tutorial-progress-v1.json";
        private readonly List<LegacyGuestMigrationInventoryEntry> entries;

        public string EnvironmentRoot { get; }
        public IList<LegacyGuestMigrationInventoryEntry> Entries =>
            entries.AsReadOnly();

        private LegacyGuestMigrationInventory(
            string environmentRoot,
            List<LegacyGuestMigrationInventoryEntry> entries)
        {
            EnvironmentRoot = environmentRoot;
            this.entries = entries;
        }

        public static bool TryCreate(
            string environmentRoot,
            out LegacyGuestMigrationInventory inventory,
            out string errorMessage)
        {
            inventory = null;
            errorMessage = null;
            if (!TryNormalizeAndValidateRoot(
                    environmentRoot,
                    out string normalizedRoot,
                    out errorMessage))
                return false;

            var collected = new List<LegacyGuestMigrationInventoryEntry>();
            var seenPaths = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            try
            {
                foreach (string path in Directory.GetFileSystemEntries(
                             normalizedRoot,
                             "*",
                             SearchOption.TopDirectoryOnly))
                {
                    if (!TryEnsureNotReparsePoint(path, out errorMessage))
                        return false;

                    FileAttributes attributes = File.GetAttributes(path);
                    bool isDirectory =
                        (attributes & FileAttributes.Directory) != 0;
                    string name = Path.GetFileName(path);
                    if (isDirectory)
                    {
                        if (IsReservedDirectory(name))
                            continue;
                        if (string.Equals(
                                name,
                                CafeDirectoryName,
                                StringComparison.Ordinal))
                        {
                            if (!TryAddFamilyDirectory(
                                    normalizedRoot,
                                    name,
                                    CafeFileName,
                                    collected,
                                    seenPaths,
                                    out errorMessage))
                                return false;
                            continue;
                        }

                        if (string.Equals(
                                name,
                                TutorialDirectoryName,
                                StringComparison.Ordinal))
                        {
                            if (!TryAddFamilyDirectory(
                                    normalizedRoot,
                                    name,
                                    TutorialFileName,
                                    collected,
                                    seenPaths,
                                    out errorMessage))
                                return false;
                            continue;
                        }

                        errorMessage =
                            "An unrecognized directory exists in the legacy save root: " +
                            name;
                        return false;
                    }

                    if (!IsSaveCandidate(name))
                    {
                        errorMessage =
                            "An unrecognized file exists in the legacy save root: " +
                            name;
                        return false;
                    }

                    if (!TryAddFile(
                            normalizedRoot,
                            name,
                            collected,
                            seenPaths,
                            out errorMessage))
                        return false;
                }

                collected.Sort((left, right) =>
                    string.CompareOrdinal(
                        left.RelativePath,
                        right.RelativePath));
                inventory = new LegacyGuestMigrationInventory(
                    normalizedRoot,
                    collected);
                return true;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Legacy migration inventory could not be read: " +
                    exception.Message;
                return false;
            }
        }

        public List<LegacyGuestMigrationManifestEntry> CreateManifest()
        {
            var manifest =
                new List<LegacyGuestMigrationManifestEntry>(entries.Count);
            foreach (LegacyGuestMigrationInventoryEntry entry in entries)
            {
                manifest.Add(new LegacyGuestMigrationManifestEntry
                {
                    relativePath = entry.RelativePath,
                    byteLength = entry.ByteLength,
                    sha256 = entry.Sha256
                });
            }

            return manifest;
        }

        public string ComputeManifestHash()
        {
            return LegacyGuestMigrationJournalValidator.ComputeManifestHash(
                CreateManifest());
        }

        internal bool HasSameManifest(
            LegacyGuestMigrationInventory other)
        {
            if (other == null || entries.Count != other.entries.Count)
                return false;

            for (int i = 0; i < entries.Count; i++)
            {
                LegacyGuestMigrationInventoryEntry left = entries[i];
                LegacyGuestMigrationInventoryEntry right = other.entries[i];
                if (!string.Equals(
                        left.RelativePath,
                        right.RelativePath,
                        StringComparison.Ordinal) ||
                    left.ByteLength != right.ByteLength ||
                    !string.Equals(
                        left.Sha256,
                        right.Sha256,
                        StringComparison.Ordinal))
                    return false;
            }

            return true;
        }

        internal static string ComputeSha256(byte[] bytes)
        {
            using (SHA256 sha256 = SHA256.Create())
            {
                byte[] hash = sha256.ComputeHash(bytes);
                const string Hex = "0123456789abcdef";
                char[] result = new char[hash.Length * 2];
                for (int i = 0; i < hash.Length; i++)
                {
                    result[i * 2] = Hex[hash[i] >> 4];
                    result[i * 2 + 1] = Hex[hash[i] & 0x0f];
                }

                return new string(result);
            }
        }

        internal static bool IsCanonicalRelativePath(string path)
        {
            if (string.IsNullOrEmpty(path) ||
                path.Length > MaximumRelativePathLength ||
                path[0] == '/' ||
                path.IndexOf('\\') >= 0 ||
                path.IndexOf(':') >= 0)
                return false;

            string[] segments = path.Split('/');
            for (int i = 0; i < segments.Length; i++)
            {
                if (segments[i].Length == 0 ||
                    segments[i] == "." ||
                    segments[i] == "..")
                    return false;
            }

            for (int i = 0; i < path.Length; i++)
            {
                if (char.IsControl(path[i]))
                    return false;
            }

            return true;
        }

        internal static bool IsSafeDirectoryTree(
            string path,
            string requiredParent,
            out string errorMessage)
        {
            errorMessage = null;
            string fullPath = Path.GetFullPath(path);
            string parentPath = Path.GetFullPath(requiredParent);
            if (!IsContained(parentPath, fullPath))
            {
                errorMessage =
                    "Migration path escapes its approved parent directory.";
                return false;
            }

            if (!TryEnsureNoReparsePointsInPath(
                    parentPath,
                    out errorMessage) ||
                !TryEnsureNoReparsePointsInPath(
                    fullPath,
                    out errorMessage))
                return false;

            return true;
        }

        internal static bool IsContained(string parent, string child)
        {
            string normalizedParent = Path.GetFullPath(parent);
            string normalizedChild = Path.GetFullPath(child);
            string prefix = normalizedParent.EndsWith(
                    Path.DirectorySeparatorChar.ToString(),
                    StringComparison.Ordinal)
                ? normalizedParent
                : normalizedParent + Path.DirectorySeparatorChar;
#if UNITY_EDITOR_WIN || UNITY_STANDALONE_WIN || UNITY_WSA
            return normalizedChild.StartsWith(
                       prefix,
                       StringComparison.OrdinalIgnoreCase) ||
                   string.Equals(
                       normalizedParent,
                       normalizedChild,
                       StringComparison.OrdinalIgnoreCase);
#else
            return normalizedChild.StartsWith(
                       prefix,
                       StringComparison.Ordinal) ||
                   string.Equals(
                       normalizedParent,
                       normalizedChild,
                       StringComparison.Ordinal);
#endif
        }

        internal static bool TryEnsureNoReparsePointsInPath(
            string path,
            out string errorMessage)
        {
            errorMessage = null;
            try
            {
                string current = Path.GetFullPath(path);
                while (!string.IsNullOrEmpty(current))
                {
                    if (File.Exists(current) || Directory.Exists(current))
                    {
                        FileAttributes attributes =
                            File.GetAttributes(current);
                        if ((attributes & FileAttributes.ReparsePoint) != 0)
                        {
                            errorMessage =
                                "Migration paths cannot contain links or reparse points.";
                            return false;
                        }
                    }

                    string parent = Path.GetDirectoryName(current);
                    if (string.IsNullOrEmpty(parent) ||
                        string.Equals(
                            parent,
                            current,
                            StringComparison.Ordinal))
                        break;
                    current = parent;
                }

                return true;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Migration path safety could not be verified: " +
                    exception.Message;
                return false;
            }
        }

        private static bool TryNormalizeAndValidateRoot(
            string root,
            out string normalizedRoot,
            out string errorMessage)
        {
            normalizedRoot = null;
            errorMessage = null;
            try
            {
                if (string.IsNullOrWhiteSpace(root) ||
                    !Path.IsPathRooted(root))
                {
                    errorMessage =
                        "Legacy environment root must be an absolute path.";
                    return false;
                }

                normalizedRoot = Path.GetFullPath(root);
                if (!Directory.Exists(normalizedRoot))
                {
                    errorMessage =
                        "Legacy environment root does not exist.";
                    return false;
                }

                return TryEnsureNoReparsePointsInPath(
                    normalizedRoot,
                    out errorMessage);
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Legacy environment root is invalid: " +
                    exception.Message;
                return false;
            }
        }

        private static bool IsReservedDirectory(string name)
        {
            return string.Equals(name, "IdentityProfiles", StringComparison.Ordinal) ||
                   string.Equals(name, "ProfileSelection", StringComparison.Ordinal) ||
                   string.Equals(name, "LegacyGuestMigration", StringComparison.Ordinal);
        }

        private static bool TryAddFamilyDirectory(
            string root,
            string directoryName,
            string primaryFileName,
            List<LegacyGuestMigrationInventoryEntry> collected,
            HashSet<string> seenPaths,
            out string errorMessage)
        {
            errorMessage = null;
            string familyDirectory = Path.Combine(root, directoryName);
            if (!TryEnsureNotReparsePoint(
                    familyDirectory,
                    out errorMessage))
                return false;

            foreach (string path in Directory.GetFileSystemEntries(
                         familyDirectory,
                         "*",
                         SearchOption.TopDirectoryOnly))
            {
                if (!TryEnsureNotReparsePoint(path, out errorMessage))
                    return false;
                if ((File.GetAttributes(path) & FileAttributes.Directory) != 0)
                {
                    errorMessage =
                        "Nested directories are not allowed in a migration profile family.";
                    return false;
                }

                string name = Path.GetFileName(path);
                if (!IsFamilyCandidate(name, primaryFileName))
                {
                    errorMessage =
                        "An unrecognized file exists in " +
                        directoryName + ": " + name;
                    return false;
                }

                string relativePath = directoryName + "/" + name;
                if (!TryAddFile(
                        root,
                        relativePath,
                        collected,
                        seenPaths,
                        out errorMessage))
                    return false;
            }

            return true;
        }

        private static bool TryAddFile(
            string root,
            string relativePath,
            List<LegacyGuestMigrationInventoryEntry> collected,
            HashSet<string> seenPaths,
            out string errorMessage)
        {
            errorMessage = null;
            if (!IsCanonicalRelativePath(relativePath))
            {
                errorMessage =
                    "Migration inventory contains an unsafe relative path.";
                return false;
            }

            string fullPath = Path.GetFullPath(Path.Combine(
                root,
                relativePath.Replace(
                    '/',
                    Path.DirectorySeparatorChar)));
            if (!IsContained(root, fullPath))
            {
                errorMessage =
                    "Migration source path escapes the legacy root.";
                return false;
            }

            if (!TryEnsureNotReparsePoint(fullPath, out errorMessage))
                return false;
            if (!seenPaths.Add(relativePath))
            {
                errorMessage =
                    "Migration inventory contains an ambiguous duplicate path.";
                return false;
            }

            byte[] bytes = File.ReadAllBytes(fullPath);
            collected.Add(
                new LegacyGuestMigrationInventoryEntry(
                    relativePath,
                    bytes));
            return true;
        }

        private static bool TryEnsureNotReparsePoint(
            string path,
            out string errorMessage)
        {
            errorMessage = null;
            try
            {
                FileAttributes attributes = File.GetAttributes(path);
                if ((attributes & FileAttributes.ReparsePoint) != 0)
                {
                    errorMessage =
                        "Migration inventory cannot include links or reparse points.";
                    return false;
                }

                return true;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "Migration inventory path could not be inspected: " +
                    exception.Message;
                return false;
            }
        }

        private static bool IsSaveCandidate(string name)
        {
            return IsKnownCandidate(name, SaveV2FileName) ||
                   IsKnownCandidate(name, SaveV1FileName);
        }

        private static bool IsFamilyCandidate(
            string name,
            string primaryFileName)
        {
            return IsKnownCandidate(name, primaryFileName);
        }

        private static bool IsKnownCandidate(
            string name,
            string primaryFileName)
        {
            string[] baseNames =
            {
                primaryFileName,
                primaryFileName + ".bak",
                primaryFileName + ".tmp",
                primaryFileName + ".bak.tmp",
                primaryFileName + ".recover.tmp"
            };

            for (int i = 0; i < baseNames.Length; i++)
            {
                if (string.Equals(
                        name,
                        baseNames[i],
                        StringComparison.Ordinal) ||
                    HasPreviousSuffix(name, baseNames[i]))
                    return true;
            }

            return HasCorruptSuffix(name, primaryFileName);
        }

        private static bool HasPreviousSuffix(
            string name,
            string baseName)
        {
            string prefix = baseName + ".previous.";
            if (!name.StartsWith(prefix, StringComparison.Ordinal))
                return false;

            return IsCanonicalGuidN(name.Substring(prefix.Length));
        }

        private static bool HasCorruptSuffix(
            string name,
            string primaryFileName)
        {
            string prefix = primaryFileName + ".corrupt.";
            if (!name.StartsWith(prefix, StringComparison.Ordinal))
                return false;

            return IsCanonicalGuidN(name.Substring(prefix.Length));
        }

        private static bool IsCanonicalGuidN(string value)
        {
            return Guid.TryParseExact(value, "N", out Guid parsed) &&
                   string.Equals(
                       value,
                       parsed.ToString("N"),
                       StringComparison.Ordinal);
        }
    }
}
