using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;
using Unity.Services.CloudCode.Authoring.Editor.Core.Model;

namespace Unity.Services.CloudCode.Authoring.Editor.Core.Modules.Bindings
{
    interface ICloudCodeModuleReferenceBindingsGenerator
    {
        public Task<List<CloudCodeModuleReferenceBindingsGenerationResult>> GenerateModuleBindings(
            IEnumerable<ISolutionModuleItem> moduleItems,
            CancellationToken cancellationToken = default);
    }
}
