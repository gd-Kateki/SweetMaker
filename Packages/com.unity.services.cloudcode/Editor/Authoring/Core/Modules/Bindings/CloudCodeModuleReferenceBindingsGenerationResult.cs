using System;
using Unity.Services.CloudCode.Authoring.Editor.Core.Model;

namespace Unity.Services.CloudCode.Authoring.Editor.Core.Modules.Bindings
{
    class CloudCodeModuleReferenceBindingsGenerationResult
    {
        public ISolutionModuleItem ModuleItem { get; }
        public string OutputPath { get; set; }
        public bool IsSuccessful { get; }
        public Exception Exception { get; }

        public CloudCodeModuleReferenceBindingsGenerationResult(
            ISolutionModuleItem moduleItem,
            string outputPath,
            bool isSuccessful,
            Exception exception = null)
        {
            ModuleItem = moduleItem;
            OutputPath = outputPath;
            IsSuccessful = isSuccessful;
            Exception = exception;
        }
    }
}
