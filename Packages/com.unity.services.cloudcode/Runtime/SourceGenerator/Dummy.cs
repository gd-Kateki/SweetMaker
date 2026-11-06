// This dummy class exists so the Unity.Services.CloudCode.SourceGenerator assembly contains
// at least one real C# type. An empty assembly is stripped by Unity at build time, which
// would prevent other assemblies from referencing it and running the Roslyn source generator
// (required by `RunOnlyOnAssembliesWithReference`). Remove this when we properly home
// SourceGenerator.dll.
namespace Unity.Services.CloudCode.SourceGenerator
{
    internal class Dummy
    {
        internal void DummyFunction() {}
    }
}
