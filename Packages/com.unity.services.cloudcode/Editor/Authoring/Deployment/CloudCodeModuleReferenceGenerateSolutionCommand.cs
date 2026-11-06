using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;
using Unity.Services.CloudCode.Authoring.Editor.Core.Logging;
using Unity.Services.CloudCode.Authoring.Editor.Core.Solution;
using Unity.Services.CloudCode.Authoring.Editor.Modules;
using Unity.Services.DeploymentApi.Editor;
using UnityEditor;

namespace Unity.Services.CloudCode.Authoring.Editor.Deployment
{
    class CloudCodeModuleReferenceGenerateSolutionCommand : Command<CloudCodeModuleReference>
    {
        public override string Name => L10n.Tr("Generate Solution");

        static CloudCodeModuleSolutionGenerator m_SolutionGenerator;
        static ILogger m_Logger;
        static Regex m_ValidNameRegex = new Regex("^[a-zA-Z][a-zA-Z_0-9]*$", RegexOptions.Compiled);

        public CloudCodeModuleReferenceGenerateSolutionCommand(CloudCodeModuleSolutionGenerator generator, ILogger logger)
        {
            m_SolutionGenerator = generator;
            m_Logger = logger;
        }

        public override Task ExecuteAsync(IEnumerable<CloudCodeModuleReference> items, CancellationToken cancellationToken = default)
        {
            List<Task> generationTasks = new List<Task>();
            foreach (var ccmr in items)
            {
                var name = Path.GetFileNameWithoutExtension(ccmr.ModulePath);
                var task = GenerateSolution(ccmr, cancellationToken);
                generationTasks.Add(task);
            }

            List<Exception> exceptions = new List<Exception>();
            foreach (var task in generationTasks)
            {
                if (task.IsFaulted)
                {
                    exceptions.Add(task.Exception);
                }
            }
            if (exceptions.Count > 0)
            {
                throw new AggregateException(exceptions);
            }
            return Task.CompletedTask;
        }

        public static async Task GenerateSolution(CloudCodeModuleReference ccmr, CancellationToken cancellationToken = default)
        {
            var referenceFileDir = Path.GetDirectoryName(Path.GetFullPath(ccmr.Path));
            var targetPath = Path.Combine(referenceFileDir, ccmr.ModulePath);
            targetPath = Path.GetFullPath(targetPath);

            var solutionName = Path.GetFileNameWithoutExtension(targetPath);
            if (!m_ValidNameRegex.IsMatch(solutionName))
            {
                var msg =
                    "Cloud Code Module will not be generated, selected 'Path' contains invalid characters. The solution name should only contain alphanumerical characters and underscores.";

                m_Logger.LogError(msg);
                throw new Exception(msg);
            }
            var solutionPath = Path.Combine(
                Path.GetDirectoryName(targetPath),
                Path.GetFileNameWithoutExtension(targetPath) + CloudCodeModuleReferenceResources.SolutionExtension);

            if (File.Exists(solutionPath))
            {
                throw new Exception($"File {solutionPath} already exists. You cannot override an existing solution.");
            }

            try
            {
                await m_SolutionGenerator.CreateSolutionWithProject(
                    Path.GetDirectoryName(targetPath),
                    Path.GetFileNameWithoutExtension(targetPath), cancellationToken);

                m_Logger.LogInfo($"Solution '{solutionName}' generated successfully.");
            }
            catch (Exception e)
            {
                m_Logger.LogError($"Failed to generate solution: {e}");
                throw;
            }
        }
    }
}
