using System.IO;
using UnityEditor.AssetImporters;
using UnityEngine;

namespace Unity.Services.CloudCode.Authoring.Editor.Modules
{
    [ScriptedImporter(1, CloudCodeModuleReferenceResources.FileExtension)]
    class CloudCodeModuleReferenceImporter : ScriptedImporter
    {
        public void OnValidate()
        {
            hideFlags = HideFlags.HideInInspector;
        }

        public override void OnImportAsset(AssetImportContext ctx)
        {
            var fileContent = File.ReadAllText(ctx.assetPath);
            var definition = ScriptableObject.CreateInstance<CloudCodeModuleReference>();

            if (!definition.FromJson(fileContent))
            {
                ctx.LogImportError($"Failed to import Cloud Code Module Reference at '{ctx.assetPath}'.");
                DestroyImmediate(definition);
                return;
            }

            ctx.AddObjectToAsset("MainAsset", definition);
            ctx.SetMainObject(definition);
        }
    }
}
