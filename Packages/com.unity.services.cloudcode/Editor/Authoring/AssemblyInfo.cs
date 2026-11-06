using System.Runtime.CompilerServices;

// Test assemblies
#if UNITY_INCLUDE_TESTS
[assembly: InternalsVisibleTo("DynamicProxyGenAssembly2")]
[assembly: InternalsVisibleTo("GameIteration")]
[assembly: InternalsVisibleTo("Unity.Services.CloudCode.Authoring.Tests.Editor")]
[assembly: InternalsVisibleTo("Unity.Services.CloudCode.Editor")]
[assembly: InternalsVisibleTo("CloudCode.Runtime.Tests")]
[assembly: InternalsVisibleTo("CloudCode.Editor.Tests")]
#endif
