using System;
using System.IO;
using System.Linq;
using UnityEditor;
using UnityEditorInternal;
using UnityEngine;

namespace Unity.Services.CloudCode.Authoring.Editor.Scripts
{
    // A serializable class to hold the relevant JSON data from the .asmdef file
    [Serializable]
    class AsmdefJsonData
    {
        public string name;
        public string rootNamespace;
        public string[] references;
        public string[] includePlatforms;
        public string[] excludePlatforms;
        public bool allowUnsafeCode;
        public bool overrideReferences;
        public string[] precompiledReferences;
        public bool autoReferenced;
        public string[] defineConstraints;
        public VersionDefine[] versionDefines;
        public bool noEngineReferences;

        [Serializable]
        internal class VersionDefine
        {
            public string name;
            public string expression;
            public string define;
        }

        internal static AsmdefJsonData ParseAssemblyDefinitionAsset(AssemblyDefinitionAsset asmdefAsset)
        {
            if (asmdefAsset == null)
                return null;

            // Grab the path for a given Assembly definition asset.
            string assetPath = AssetDatabase.GetAssetPath(asmdefAsset);
            return DeserializeFromPath(assetPath);
        }

        internal static AsmdefJsonData DeserializeFromPath(string assetPath)
        {
            if (string.IsNullOrEmpty(assetPath))
                return null;

            // Read the JSON content from the file
            string jsonText = File.ReadAllText(assetPath);

            // Parse the JSON into our serializable structure
            return JsonUtility.FromJson<AsmdefJsonData>(jsonText);
        }

        internal void SerializeToPath(string assetPath)
        {
            File.WriteAllText(assetPath, JsonUtility.ToJson(this));
        }

        internal void AddAssemblyReferenceAtPath(string asmdefPath)
        {
            string newReference;
            if (ReferencesUseGUIDs())
            {
                newReference = AssetDatabase.AssetPathToGUID(asmdefPath);

                if (string.IsNullOrEmpty(newReference))
                {
                    throw new FileNotFoundException($"Failed to find GUID for asset at path: {asmdefPath}. Ensure the asset has been imported.");
                }

                newReference = $"GUID:{newReference}";
            }
            else
            {
                var referenceToAdd = DeserializeFromPath(asmdefPath);
                newReference = referenceToAdd.name;
            }

            references = references.Append(newReference).ToArray();
        }

        private bool ReferencesUseGUIDs()
        {
            // Default to false if no references have yet been set.
            if (references == null || references.Length == 0)
                return false;

            return references[0].Contains("GUID");
        }

        internal bool HasAssemblyReferenceAtPath(string asmdefPath)
        {
            string newReference;
            if (ReferencesUseGUIDs())
                newReference = $"GUID:{AssetDatabase.AssetPathToGUID(asmdefPath)}";
            else
                newReference = Path.GetFileNameWithoutExtension(asmdefPath);

            if (string.IsNullOrEmpty(newReference))
                return false;

            bool found = false;
            foreach (var reference in references)
            {
                if (reference.ToLowerInvariant() == newReference.ToLowerInvariant())
                    found = true;
            }

            return found;
        }

        internal bool HasNameThatMatches(AssemblyDefinitionAsset asmdefAsset)
        {
            if (string.IsNullOrEmpty(name))
                return false;

            var parsed = ParseAssemblyDefinitionAsset(asmdefAsset);
            return parsed != null && string.Equals(name, parsed.name, StringComparison.Ordinal);
        }
    }
}
