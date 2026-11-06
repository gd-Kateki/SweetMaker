using System.IO;
using Unity.Services.CloudCode.Authoring.Editor.Analytics;
using Unity.Services.CloudCode.Editor.Shared.Infrastructure.IO;
using UnityEditor;
using UnityEngine;

#if UNITY_6000_4_OR_NEWER
using BaseClass = UnityEditor.ProjectWindowCallback.AssetCreationEndAction;
using ActionIdentifier = UnityEngine.EntityId;
#else
using BaseClass = UnityEditor.ProjectWindowCallback.EndNameEditAction;
using ActionIdentifier = System.Int32;
#endif

namespace Unity.Services.CloudCode.Authoring.Editor.Modules.UI
{
    class CreateCloudCodeModuleReference : BaseClass
    {
        const string k_DefaultReferenceName = "new_module_reference";

        [MenuItem("Assets/Create/Services/Cloud Code C# Module Reference", false, 69)]
        public static void CreateModuleReferenceFile()
        {
            const string filePath = k_DefaultReferenceName + CloudCodeModuleReferenceResources.FileExtension;

            // We use ActionIdentifier so the alias automatically
            // resolves to the correct type based on the Unity version.
            // ReSharper disable once PreferConcreteValueOverDefault
            // ReSharper disable once ConvertToConstant.Local
            var instanceId = new ActionIdentifier();

            ProjectWindowUtil.StartNameEditingIfProjectWindowExists(
                instanceId,
                CreateInstance<CreateCloudCodeModuleReference>(),
                filePath,
                null,
                null);
        }

        public override void Action(ActionIdentifier instanceId, string pathName, string resourceFile)
        {
            var reference = CreateInstance<CloudCodeModuleReference>();
            reference.Name =  Path.GetFileName(pathName);
            reference.ModulePath =
                Path.Combine(
                    PathUtils.GetRelativePath(pathName, Application.dataPath),
                    Path.GetFileNameWithoutExtension(reference.Name));
            File.WriteAllText(pathName, reference.ToJson());

            CloudCodeAuthoringServices.Instance.GetService<CloudModuleCreationAnalytics>().SendReferenceCreatedEvent();

            AssetDatabase.Refresh();
        }
    }
}
