using System.IO;
using Unity.Services.CloudCode.Authoring.Editor.Deployment;
using Unity.Services.CloudCode.Editor.Shared.Analytics;
using UnityEditor;
using UnityEngine.UIElements;
using DeploymentConfigInspectorFooter = Unity.Services.CloudCode.Editor.Shared.UI.DeploymentConfigInspectorFooter.DeploymentConfigInspectorFooter;
using Object = UnityEngine.Object;

namespace Unity.Services.CloudCode.Authoring.Editor.UI
{
    enum DeploymentDashboard
    {
        Module,
        Script
    }

    static class DeploymentFooterBinder
    {
        public static void Bind(VisualElement root, Object target, DeploymentDashboard dashboard)
        {
            var footer = root.Q<DeploymentConfigInspectorFooter>();
            var assetPath = AssetDatabase.GetAssetPath(target);
            var assetName = Path.GetFileNameWithoutExtension(assetPath);
            var services = CloudCodeAuthoringServices.Instance;

            footer.BindGUI(assetPath, services.GetService<ICommonAnalytics>(), "cloudcode");
            footer.DashboardLinkUrlGetter = () =>
            {
                var resolver = services.GetService<IDashboardUrlResolver>();
                return dashboard == DeploymentDashboard.Module
                    ? resolver.CloudCodeModule(assetName)
                    : resolver.CloudCodeScript(assetName);
            };
        }
    }
}
