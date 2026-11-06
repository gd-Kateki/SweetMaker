using System;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using Unity.Services.CloudCode.Authoring.Editor.Analytics;
using Unity.Services.CloudCode.Authoring.Editor.Core.Modules.Bindings;
using UnityEditor;
using UnityEngine.UIElements;
// ReSharper disable once RedundantUsingDirective
// Required for older unity versions.
// ReSharper disable RedundantUsingDirective
using UnityEditor.UIElements;
// ReSharper disable once RedundantUsingDirective
using UnityEngine;

namespace Unity.Services.CloudCode.Authoring.Editor.Modules.UI
{
    class CloudCodeModuleReferenceGenerateBindingsVisualElement : VisualElement
    {
        static readonly string k_Uxml =
            Path.Combine(
                CloudCodePackage.EditorPath,
                "Authoring", "Modules", "UI" ,
                "Assets", "CloudCodeModuleReferenceGenerateBindingsProjectSettings.uxml");

        static readonly string k_Uss =
            Path.Combine(CloudCodePackage.EditorPath,
                "Authoring", "Modules", "UI",
                "Assets", "CloudCodeModuleReferenceGenerateBindingsProjectSettings.uss");

        static readonly string k_ModuleBindingText = L10n.Tr("Modules Binding");
        static readonly string k_GenerateButtonText = L10n.Tr("Generate All Modules Bindings");
        static readonly string k_GenerateButtonTooltip = L10n.Tr("Generate the code bindings for all modules found in the current project.");

        /// <summary>
        /// The button to generate all modules bindings found in the current project.
        /// </summary>
        Button GenerateAllModulesBindingsButton { get; }
        Label ModuleBindingsLabel { get; }

        public CloudCodeModuleReferenceGenerateBindingsVisualElement()
        {
            var containerAsset = AssetDatabase.LoadAssetAtPath<VisualTreeAsset>(k_Uxml);
            if (containerAsset != null)
            {
                var containerUI = containerAsset.CloneTree().contentContainer;

                var styleSheet = AssetDatabase.LoadAssetAtPath<StyleSheet>(k_Uss);
                if (styleSheet != null)
                {
                    containerUI.styleSheets.Add(styleSheet);
                }
                else
                {
                    throw new Exception("Asset not found: " + k_Uss);
                }

                GenerateAllModulesBindingsButton = containerUI.Q<Button>("generate-bindings-btn");
                GenerateAllModulesBindingsButton.clicked += GenerateAllModulesBindingsClicked;
                GenerateAllModulesBindingsButton.text = k_GenerateButtonText;
                GenerateAllModulesBindingsButton.tooltip = k_GenerateButtonTooltip;

                ModuleBindingsLabel = containerUI.Q<Label>("module-bindings-text");
                ModuleBindingsLabel.text = k_ModuleBindingText;

                Add(containerUI);
            }
            else
            {
                throw new Exception("Asset not found: " + k_Uxml);
            }
        }

        async void GenerateAllModulesBindingsClicked()
        {
            await GenerateModuleBindingsAsync();
        }

        async Task GenerateModuleBindingsAsync()
        {
            SetEnabled(false);

            var ccmrs = CloudCodeAuthoringServices.Instance
                .GetService<CloudCodeModuleReferenceCollection>().ToList();

            var results = await CloudCodeAuthoringServices.Instance
                .GetService<ICloudCodeModuleReferenceBindingsGenerator>()
                    .GenerateModuleBindings(ccmrs);

            var failedResults = results
                .Select(x => x.Exception)
                .Where(x => x != null).ToList();

            CloudCodeAuthoringServices.Instance.GetService<ICloudCodeModuleReferenceBindingsGenerationAnalytics>()
                .SendCodeGenerationFromProjectSettingsEvent(
                    failedResults.Any() ? new AggregateException(failedResults) : null);

            SetEnabled(true);
        }
    }
}
