using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using Unity.Services.CloudCode.Authoring.Editor.Analytics;
using Unity.Services.CloudCode.Authoring.Editor.Core.Modules.Bindings;
using Unity.Services.CloudCode.Authoring.Editor.Modules;
using Unity.Services.CloudCode.Editor.Shared.UI;
using Unity.Services.DeploymentApi.Editor;
using UnityEditor;

namespace Unity.Services.CloudCode.Authoring.Editor.Deployment.Modules
{
    class CloudCodeModuleReferenceGenerateBindingsCommand : Command<CloudCodeModuleReference>
    {
        public override string Name => L10n.Tr("Generate Code Bindings");

        readonly ICloudCodeModuleReferenceBindingsGenerator m_ModuleReferenceBindingsGenerator;

        public CloudCodeModuleReferenceGenerateBindingsCommand(
            ICloudCodeModuleReferenceBindingsGenerator moduleReferenceBindingsGenerator)
        {
            m_ModuleReferenceBindingsGenerator = moduleReferenceBindingsGenerator;
        }

        public override async Task ExecuteAsync(
            IEnumerable<CloudCodeModuleReference> ccmrs,
            CancellationToken cancellationToken = default)
        {
            var results =
                await m_ModuleReferenceBindingsGenerator.GenerateModuleBindings(ccmrs, cancellationToken);

            var failedResults = results
                .Select(x => x.Exception)
                .Where(x => x != null).ToList();

            CloudCodeAuthoringServices.Instance.GetService<ICloudCodeModuleReferenceBindingsGenerationAnalytics>()
                .SendCodeGenerationFromCommandEvent(
                    failedResults.Any() ? new AggregateException(failedResults) : null);
        }
    }
}
