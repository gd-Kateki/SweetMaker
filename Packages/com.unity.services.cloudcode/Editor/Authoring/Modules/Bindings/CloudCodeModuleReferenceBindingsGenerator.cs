using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using Unity.Services.CloudCode.Authoring.Editor.Core.Deployment;
using Unity.Services.CloudCode.Authoring.Editor.Core.Deployment.ModuleGeneration;
using Unity.Services.CloudCode.Authoring.Editor.Core.Dotnet;
using Unity.Services.CloudCode.Authoring.Editor.Core.IO;
using Unity.Services.CloudCode.Authoring.Editor.Core.Logging;
using Unity.Services.CloudCode.Authoring.Editor.Core.Model;
using Unity.Services.CloudCode.Authoring.Editor.Core.Modules.Bindings;
using Unity.Services.CloudCode.Editor.Shared.Infrastructure.Collections;
using UnityEditor;
using Task = System.Threading.Tasks.Task;

namespace Unity.Services.CloudCode.Authoring.Editor.Modules.Bindings
{
    class CloudCodeModuleReferenceBindingsGenerator : ICloudCodeModuleReferenceBindingsGenerator
    {
        readonly IDotnetRunner m_DotnetRunner;
        readonly ISolutionPublisher m_SolutionPublisher;
        readonly IModuleProjectRetriever m_ModuleProjectRetriever;
        readonly IFileSystem m_FileSystem;
        readonly ILogger m_Logger;

        const string k_AssemblyDefinitionFileName = "Unity.Services.CloudCode.GeneratedBindings.asmdef";

        static readonly string k_BindingsOutputFolder =
            Path.Combine("Assets", "CloudCode", "GeneratedModuleBindings");

        public CloudCodeModuleReferenceBindingsGenerator(
            IDotnetRunner dotnetRunner,
            ISolutionPublisher solutionPublisher,
            IModuleProjectRetriever moduleProjectRetriever,
            IFileSystem fileSystem,
            ILogger logger)
        {
            m_DotnetRunner = dotnetRunner;
            m_SolutionPublisher = solutionPublisher;
            m_ModuleProjectRetriever = moduleProjectRetriever;
            m_FileSystem = fileSystem;
            m_Logger = logger;
        }

        public Task<List<CloudCodeModuleReferenceBindingsGenerationResult>> GenerateModuleBindings(
            IEnumerable<ISolutionModuleItem> moduleItems,
            CancellationToken cancellationToken = default)
            => GenerateModuleBindings(moduleItems, CompileAndGenerateModuleBindings, cancellationToken);

        async Task<List<CloudCodeModuleReferenceBindingsGenerationResult>> GenerateModuleBindings<T>(
            IEnumerable<T> moduleItems,
            Func<T, CancellationToken, Task<CloudCodeModuleReferenceBindingsGenerationResult>> compileAndGenerate,
            CancellationToken cancellationToken) where T : IModuleItem
        {
            var moduleItemsList = moduleItems.EnumerateOnce();
            if (!moduleItemsList.Any())
            {
                m_Logger.LogInfo("No Cloud Code Module Reference file was found in the project." +
                    " To create one right-click in the Project window, then select Create > Services > Cloud Code C# Module Reference.");
                return new List<CloudCodeModuleReferenceBindingsGenerationResult>();
            }

            m_Logger.LogInfo($"Generating Cloud Code Module Bindings for: {GetModuleItemNames(moduleItemsList)}.");

            // start module generations
            var generationTasks = new List<Task<CloudCodeModuleReferenceBindingsGenerationResult>>();
            foreach (var item in moduleItemsList)
            {
                generationTasks.Add(compileAndGenerate(item, cancellationToken));
            }

            var generationResults = await Task.WhenAll(generationTasks);
            try
            {
                await MoveCodeBindingsToEditorContext(generationResults.ToList());
                await GenerateAssemblyDefinition(k_BindingsOutputFolder, cancellationToken);
            }
            catch (Exception e)
            {
                m_Logger.LogError($"Failed to generate code bindings. Error: {e.Message}");
            }
            finally
            {
                AssetDatabase.Refresh();
            }

            var failed = generationResults
                .FirstOrDefault(res => !res.IsSuccessful);
            if (failed != null)
            {
                m_Logger.LogError($"Failed to generate code bindings. Error: {failed.Exception}");
            }

            return generationResults.ToList();
        }

        async Task MoveCodeBindingsToEditorContext(List<CloudCodeModuleReferenceBindingsGenerationResult> bindingsGenerationResults)
        {
            if (!bindingsGenerationResults.Any(x => x.IsSuccessful))
                return;

            await m_FileSystem.CreateDirectory(k_BindingsOutputFolder);

            // Move generated code to editor context
            foreach (var result in bindingsGenerationResults)
            {
                if (!result.IsSuccessful)
                {
                    m_Logger.LogError($"Failed to generate code bindings of {result.ModuleItem.Name}. Error: {result.Exception.Message}");
                    continue;
                }

                var outputFolder = GetModuleOutputFolder(result.ModuleItem);
                await MoveDirectoryToNewLocation(result.OutputPath, outputFolder);
                result.OutputPath = outputFolder;
                m_Logger.LogInfo($"Bindings of {result.ModuleItem.Name} generated successfully in {result.OutputPath}.");
            }
        }

        static string GetModuleItemNames<T>(IEnumerable<T> moduleItems) where T : IModuleItem
            => string.Join(", ", moduleItems.Select(item => item.Name));

        internal async Task<CloudCodeModuleReferenceBindingsGenerationResult> CompileAndGenerateModuleBindings(
            ISolutionModuleItem moduleItem,
            CancellationToken cancellationToken = default)
        {
            try
            {
                var moduleName = m_ModuleProjectRetriever.GetMainEntryProjectName(moduleItem.SolutionPath);
                var compilationOutputPath = GetSolutionCompilationOutputPath(moduleItem.SolutionPath);
                return await CompileAndGenerateBindings(
                    moduleItem,
                    moduleName,
                    compilationOutputPath,
                    async(tempFolder, ct) =>
                    {
                        await CompileSolution(moduleItem.SolutionPath, ct);
                        await GenerateBindings(moduleItem.SolutionPath, tempFolder, ct);
                    },
                    cancellationToken);
            }
            catch (Exception e)
            {
                return new CloudCodeModuleReferenceBindingsGenerationResult(moduleItem, "", false, e);
            }
        }

        async Task<CloudCodeModuleReferenceBindingsGenerationResult> CompileAndGenerateBindings(
            ISolutionModuleItem moduleItem,
            string moduleName,
            string compilationOutputPath,
            Func<string, CancellationToken, Task> compileAndGenerate,
            CancellationToken cancellationToken)
        {
            var tempFolder = GetBindingsGenerationOutputTempFolder(moduleName);
            try
            {
                await DeleteExistingDirectory(compilationOutputPath);
                await compileAndGenerate(tempFolder, cancellationToken);
            }
            finally
            {
                await DeleteExistingDirectory(compilationOutputPath);
            }

            return new CloudCodeModuleReferenceBindingsGenerationResult(moduleItem, tempFolder, true);
        }

        async Task DeleteExistingDirectory(string dirPath)
        {
            if (m_FileSystem.DirectoryExists(dirPath))
            {
                await m_FileSystem.DeleteDirectory(dirPath, true);
            }
        }

        async Task MoveDirectoryToNewLocation(string srcDirectoryPath, string dstDirectoryPath)
        {
            // Ensure that the source does exists.
            if (m_FileSystem.DirectoryExists(srcDirectoryPath))
            {
                // clear existing destination directory
                if (m_FileSystem.DirectoryExists(dstDirectoryPath))
                {
                    await m_FileSystem.DeleteDirectory(dstDirectoryPath, true);
                }

                m_FileSystem.MoveDirectory(srcDirectoryPath, dstDirectoryPath);
            }
            else
            {
                throw new Exception($"The source directory does not exist: {srcDirectoryPath}");
            }
        }

        internal async Task CompileSolution(string solutionPath, CancellationToken cancellationToken)
        {
            try
            {
                var solutionCompilationOutputPath = GetSolutionCompilationOutputPath(solutionPath);

                await m_SolutionPublisher.PublishSolutionCrossPlatform(
                    solutionPath,
                    solutionCompilationOutputPath,
                    cancellationToken);
            }
            catch (Exception e)
            {
                throw new FailedToCompileSolutionException(solutionPath, e);
            }
        }

        internal async Task GenerateBindings(
            string solutionPath,
            string bindingsOutputFolderPath,
            CancellationToken cancellationToken)
        {
            try
            {
                var moduleName = m_ModuleProjectRetriever.GetMainEntryProjectName(solutionPath);
                var moduleDllPath =
                    GetSolutionGeneratedDllPath(GetSolutionCompilationOutputPath(solutionPath), moduleName);

                await GenerateBindingsFromDll(moduleName, moduleDllPath, bindingsOutputFolderPath, cancellationToken);
            }
            catch (Exception e)
            {
                throw new FailedToGenerateBindingsException(solutionPath, e);
            }
        }

        async Task GenerateBindingsFromDll(
            string moduleName,
            string moduleDllPath,
            string bindingsOutputFolderPath,
            CancellationToken cancellationToken)
        {
            if (!m_FileSystem.FileExists(moduleDllPath))
            {
                throw new FileNotFoundException($"Generated binaries for the '{moduleName}' " +
                    $"solution were not found at the expected '${moduleDllPath}' path.");
            }

            await m_FileSystem.CreateDirectory(bindingsOutputFolderPath);

            var versionSelect = await GetVersionString(cancellationToken);

            await m_DotnetRunner.ExecuteDotnetAsync(
                new[] {$"{versionSelect}", $"\"{GetGeneratorPath()}\"", $"\"{moduleDllPath}\"", $"\"{bindingsOutputFolderPath}\""},
                cancellationToken);
        }

        async Task GenerateAssemblyDefinition(string bindingsOutputFolderPath, CancellationToken cancellationToken)
        {
            var assemblyDefPath = GetAssemblyDefinitionPath();

            if (!m_FileSystem.FileExists(assemblyDefPath))
            {
                await m_FileSystem.CreateDirectory(bindingsOutputFolderPath);
                var content = await m_FileSystem.ReadAllText(GetAsmdefContentPath(), cancellationToken);
                await m_FileSystem.WriteAllText(assemblyDefPath, content, cancellationToken);
            }
        }

        async Task<string> GetVersionString(CancellationToken cancellationToken)
        {
            #if !CLOUD_CODE_AUTHORING_DISABLE_VERSION_DETECT
            var versions = await m_DotnetRunner.GetAvailableCoreRuntimes(cancellationToken);
            var last = versions.LastOrDefault(v => v != null);
            string versionSelect = string.Empty;
            if (last == null)
                m_Logger.LogWarning("Failed to identify latest available SDK");
            else
                versionSelect = $"--fx-version {last}";
            return versionSelect;
            #else
            return string.Empty;
            #endif
        }

        internal static string GetGeneratorPath()
            => Path.GetFullPath(Path.Combine(
                "Packages", "com.unity.services.cloudcode", "Editor", ".CloudCodeBindingsGenerator",
                "CloudCodeBindingsGenerator.dll"));

        internal static string GetAsmdefContentPath()
            => Path.GetFullPath(Path.Combine(
                "Packages", "com.unity.services.cloudcode", "Editor", "Authoring", "Modules", "Bindings",
                "CloudCodeModuleReferenceBindingsAsmdefContent.json"));

        internal static string GetSolutionCompilationOutputPath(string solutionPath)
            => Path.Combine(Path.GetTempPath(), Path.GetFileNameWithoutExtension(solutionPath),
                "module-compilation-cross-platform");

        internal static string GetSolutionGeneratedDllPath(string solutionCompilationOutputPath, string moduleName)
            => Path.Combine(solutionCompilationOutputPath, moduleName + ".dll");

        internal static string GetAssemblyDefinitionPath()
            => Path.Combine(k_BindingsOutputFolder, k_AssemblyDefinitionFileName);

        internal static string GetBindingsGenerationOutputTempFolder(string moduleName)
            => Path.Combine(Path.GetTempPath(), "bindings-generation-" + moduleName);

        internal string GetModuleOutputFolder(ISolutionModuleItem moduleItem)
        {
            return Path.Combine(
                k_BindingsOutputFolder,
                m_ModuleProjectRetriever.GetMainEntryProjectName(moduleItem.SolutionPath));
        }
    }
}
