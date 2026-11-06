using System;
using System.IO;
using System.Threading;
using System.Threading.Tasks;
using Unity.Services.CloudCode.Authoring.Editor.Core.Dotnet;
using Unity.Services.CloudCode.Authoring.Editor.Core.IO;
using Unity.Services.CloudCode.Authoring.Editor.Core.Logging;

namespace Unity.Services.CloudCode.Authoring.Editor.Core.Solution
{
    class CloudCodeModuleSolutionGenerator
    {
        IFileSystem m_FileSystem;
        ITemplateInfo m_TemplateInfo;
        IDotnetRunner m_DotnetRunner;

        public CloudCodeModuleSolutionGenerator(
            IFileSystem fileSystem,
            ITemplateInfo templateInfo,
            IDotnetRunner dotnetRunner)
        {
            m_FileSystem = fileSystem;
            m_TemplateInfo = templateInfo;
            m_DotnetRunner = dotnetRunner;
        }

        public async Task CreateSolutionWithProject(string dstDirectory, string moduleName, CancellationToken cancellationToken)
        {
            await CopyFilesFromTemplate(dstDirectory, moduleName, cancellationToken);
            await UpdateProjectName(dstDirectory, moduleName, cancellationToken);
        }

        Task CopyFilesFromTemplate(string dstDirectory, string moduleName, CancellationToken cancellationToken)
        {
            var srcSlnFile = m_TemplateInfo.PathSolution;
            var srcDir = Path.GetDirectoryName(srcSlnFile);

            m_FileSystem.CopyDirectory(srcDir, dstDirectory);
            return Task.CompletedTask;
        }

        async Task UpdateProjectName(string dstDirectory, string moduleName, CancellationToken cancellationToken)
        {
            var srcSlnFile = m_FileSystem.Combine(dstDirectory, "Solution.sln");
            var solutionPath = m_FileSystem.Combine(dstDirectory, $"{moduleName}.sln");
            var projectDir = m_FileSystem.Combine(dstDirectory, "Project");
            var oldProjectPath = m_FileSystem.Combine(projectDir, "Project.csproj");
            var newProjectPath = m_FileSystem.Combine(projectDir, $"{moduleName!}.csproj");
            var testProjectPath = m_FileSystem.Combine(dstDirectory, "TestProject", "TestProject.csproj");

            // Rename sln
            m_FileSystem.FileMove(srcSlnFile, solutionPath);

            //Update module name
            await m_DotnetRunner.ExecuteDotnetAsync(
                new[] { $"sln \"{solutionPath}\" remove \"{oldProjectPath}\"" }, cancellationToken);
            m_FileSystem.FileMove(oldProjectPath, newProjectPath);
            await m_DotnetRunner.ExecuteDotnetAsync(
                new[] { $"sln \"{solutionPath}\" add \"{newProjectPath}\"" }, cancellationToken);

            // Update test project dependency
            string testProject = await m_FileSystem.ReadAllText(testProjectPath, cancellationToken);
            testProject = testProject.Replace("<ProjectReference Include=\"..\\Project\\Project.csproj\" />",
                $"<ProjectReference Include=\"..\\Project\\{moduleName!}.csproj\" />");
            await m_FileSystem.WriteAllText(testProjectPath, testProject, cancellationToken);
        }
    }
}
