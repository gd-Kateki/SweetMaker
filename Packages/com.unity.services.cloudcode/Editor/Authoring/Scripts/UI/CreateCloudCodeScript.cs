using System.IO;
using UnityEditor;
using Unity.Services.CloudCode.Authoring.Editor.Analytics;

#if UNITY_6000_4_OR_NEWER
using BaseClass = UnityEditor.ProjectWindowCallback.AssetCreationEndAction;
using ActionIdentifier = UnityEngine.EntityId;
#else
using BaseClass = UnityEditor.ProjectWindowCallback.EndNameEditAction;
using ActionIdentifier = System.Int32;
#endif

namespace Unity.Services.CloudCode.Authoring.Editor.Scripts.UI
{
    class CreateCloudCodeScript : BaseClass
    {
        const string k_TemplatePath = "Authoring/Scripts/Templates~/new_cloud_code_script.js.txt";
        static readonly string k_DefaultFileName = "new_cloud_code_script";

        [MenuItem("Assets/Create/Services/Cloud Code Js Script", false, 70)]
        public static void CreateScript()
        {
            CreateScriptInternal();
            CloudCodeAuthoringServices.Instance.GetService<CloudScriptCreationAnalytics>().SendCreatedEvent();
        }

        static void CreateScriptInternal()
        {
            var filePath = k_DefaultFileName + CloudCodeFileExtensions.Preferred();

#if UNITY_6000_4_OR_NEWER
            UnityEngine.EntityId instanceId = new UnityEngine.EntityId();
#else
            int instanceId = 0;
#endif

            ProjectWindowUtil.StartNameEditingIfProjectWindowExists(
                instanceId,
                CreateInstance<CreateCloudCodeScript>(),
                filePath,
                null,
                null);
        }

        public override void Action(ActionIdentifier instanceId, string pathName, string resourceFile)
        {
            var templatePath = Path.Combine(CloudCodePackage.EditorPath, k_TemplatePath);
            File.WriteAllText(pathName, File.ReadAllText(templatePath));
            AssetDatabase.Refresh();
        }
    }
}
