using Unity.Services.CloudCode.Editor.Shared.Assets;

namespace Unity.Services.CloudCode.Authoring.Editor.Modules
{
    class CloudCodeModuleReferenceCollection : ObservableAssets<CloudCodeModuleReference>
    {
        public CloudCodeModuleReferenceCollection()
            : base(new[] { CloudCodeModuleReferenceResources.FileExtension }, new AssetPostprocessorProxy(), true) {}
    }
}
