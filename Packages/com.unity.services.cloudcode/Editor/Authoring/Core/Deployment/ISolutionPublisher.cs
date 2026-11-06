using System.Threading;
using System.Threading.Tasks;

namespace Unity.Services.CloudCode.Authoring.Editor.Core.Deployment
{
    interface ISolutionPublisher
    {
        public Task PublishSolutionLinux64(string solutionPath, string outputPath, CancellationToken cancellationToken = default);
        public Task PublishSolutionCrossPlatform(string solutionPath, string outputPath, CancellationToken cancellationToken = default);
        public Task PublishSolutionForOperatingSystem(string solutionPath, string outputPath, string operatingSystem, string configuration, CancellationToken cancellationToken = default);
    }
}
