using System;
using System.Collections.Specialized;
using System.Linq;
using Unity.Services.CloudCode.Authoring.Editor.Deployment.Modules;
using Unity.Services.CloudCode.Authoring.Editor.Modules;
using Unity.Services.CloudCode.Editor.Shared.Infrastructure.Collections;
using Unity.Services.DeploymentApi.Editor;

namespace Unity.Services.CloudCode.Authoring.Editor.Deployment
{
    class CloudCodeModuleReferenceDeploymentProvider : DeploymentProvider
    {
        public override string Service => "Cloud Code";
        public override Command DeployCommand { get; }

        public CloudCodeModuleReferenceDeploymentProvider(
            CloudCodeModuleReferenceDeployCommand deployCommand,
            CloudCodeModuleReferenceGenerateSolutionCommand generateSolutionCommand,
            CloudCodeModuleReferenceGenerateBindingsCommand generateBindingsCommand,
            OpenModuleDashboardCommand openModuleDashboardCommand,
            CloudCodeModuleReferenceCollection scripts)
        {
            DeployCommand = deployCommand;
            Commands.Add(generateBindingsCommand);
            Commands.Add(generateSolutionCommand);
            Commands.Add(openModuleDashboardCommand);

            foreach (var script in scripts)
            {
                DeploymentItems.Add(script);
            }

            scripts.CollectionChanged += OnCollectionChanged;
        }

        void OnCollectionChanged(object sender, NotifyCollectionChangedEventArgs args)
        {
            var oldItems = args.OldItems?.Cast<CloudCodeModuleReference>() ?? Array.Empty<CloudCodeModuleReference>();
            var newItems = args.NewItems?.Cast<CloudCodeModuleReference>() ?? Array.Empty<CloudCodeModuleReference>();

            oldItems.ForEach(asset => DeploymentItems.Remove(asset));
            newItems.ForEach(asset => DeploymentItems.Add(asset));
        }
    }
}
