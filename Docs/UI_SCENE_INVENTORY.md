# Scene and prefab UI inventory

Hierarchy paths are relative to each scene/prefab. Runtime-only screens are listed in the root UI_GUIDE.md.

## Assets/_Game/Prefabs/UI/DessertCollectionEntry.prefab

| Hierarchy object | Controller | Source |
| --- | --- | --- |
| `DessertCollectionEntry` | `DessertCollectionEntryUI` | `Assets/_Game/Scripts/UI/DessertCollectionEntryUI.cs` |

## Assets/_Game/Prefabs/UI/DessertCollectionRewardRow.prefab

| Hierarchy object | Controller | Source |
| --- | --- | --- |
| `DessertCollectionRewardRow` | `DessertCollectionRewardRowUI` | `Assets/_Game/Scripts/UI/DessertCollectionRewardRowUI.cs` |

## Assets/_Game/Prefabs/UI/UpgradeCard.prefab

| Hierarchy object | Controller | Source |
| --- | --- | --- |
| `UpgradeCard` | `UpgradeCardUI` | `Assets/_Game/Scripts/UI/UpgradeCardUI.cs` |

## Assets/_Game/Scenes/Game.unity

| Hierarchy object | Controller | Source |
| --- | --- | --- |
| `--- ENVIRONMENT ---/Oven/OvenVisual/Oven/NextDessertPreview` | `NextDessertPreview` | `Assets/_Game/Scripts/UI/NextDessertPreview.cs` |
| `--- SYSTEMS ---/OvenManager` | `SpawnPoolSelectorUI` | `Assets/_Game/Scripts/UI/SpawnPoolSelectorUI.cs` |
| `--- UI ---/GameplayCanvas` | `CampaignCompletionUI` | `Assets/_Game/Scripts/UI/CampaignCompletionUI.cs` |
| `--- UI ---/GameplayCanvas` | `EnergyHudUI` | `Assets/_Game/Scripts/UI/EnergyHudUI.cs` |
| `--- UI ---/GameplayCanvas` | `OrderDetailsUI` | `Assets/_Game/Scripts/UI/OrderDetailsUI.cs` |
| `--- UI ---/GameplayCanvas` | `RebirthUI` | `Assets/_Game/Scripts/UI/RebirthUI.cs` |
| `--- UI ---/GameplayCanvas` | `UpgradeScreenUI` | `Assets/_Game/Scripts/UI/UpgradeScreenUI.cs` |
| `--- UI ---/GameplayCanvas/BottomNavigation` | `SafeAreaFitter` | `Assets/_Game/Scripts/UI/SafeAreaFitter.cs` |
| `--- UI ---/GameplayCanvas/BottomNavigation/HomeButton` | `HomeButtonUI` | `Assets/_Game/Scripts/UI/HomeButtonUI.cs` |
| `--- UI ---/GameplayCanvas/CashDisplay` | `CashDisplayUI` | `Assets/_Game/Scripts/UI/CashDisplayUI.cs` |
| `--- UI ---/GameplayCanvas/CashDisplay` | `SafeAreaFitter` | `Assets/_Game/Scripts/UI/SafeAreaFitter.cs` |
| `--- UI ---/GameplayCanvas/CashDisplayBackground` | `SafeAreaFitter` | `Assets/_Game/Scripts/UI/SafeAreaFitter.cs` |
| `--- UI ---/GameplayCanvas/CustomerButtons/CustomerButton_1` | `CustomerButtonUI` | `Assets/_Game/Scripts/UI/CustomerButtonUI.cs` |
| `--- UI ---/GameplayCanvas/CustomerButtons/CustomerButton_2` | `CustomerButtonUI` | `Assets/_Game/Scripts/UI/CustomerButtonUI.cs` |
| `--- UI ---/GameplayCanvas/CustomerButtons/CustomerButton_3` | `CustomerButtonUI` | `Assets/_Game/Scripts/UI/CustomerButtonUI.cs` |
| `--- UI ---/GameplayCanvas/OrderDetailsOverlay/OrderDetailsPanel/RequirementsContainer/RequirementRow_1` | `OrderRequirementRowUI` | `Assets/_Game/Scripts/UI/OrderRequirementRowUI.cs` |
| `--- UI ---/GameplayCanvas/OrderDetailsOverlay/OrderDetailsPanel/RequirementsContainer/RequirementRow_2` | `OrderRequirementRowUI` | `Assets/_Game/Scripts/UI/OrderRequirementRowUI.cs` |
| `--- UI ---/GameplayCanvas/OrderDetailsOverlay/OrderDetailsPanel/RequirementsContainer/RequirementRow_3` | `OrderRequirementRowUI` | `Assets/_Game/Scripts/UI/OrderRequirementRowUI.cs` |
| `--- UI ---/GameplayCanvas/OrderPanel` | `OrderUI` | `Assets/_Game/Scripts/UI/OrderUI.cs` |
| `--- UI ---/GameplayCanvas/RecycleConfirmationController` | `RecycleConfirmationController` | `Assets/_Game/Scripts/UI/RecycleConfirmationController.cs` |
| `--- UI ---/GameplayCanvas/RecycleConfirmationController/RecycleConfirmationOverlay/RecycleConfirmationPanel` | `SafeAreaFitter` | `Assets/_Game/Scripts/UI/SafeAreaFitter.cs` |
| `--- UI ---/GameplayCanvas/SettingsButton` | `SafeAreaFitter` | `Assets/_Game/Scripts/UI/SafeAreaFitter.cs` |
| `--- UI ---/GameplayCanvas/SettingsButton` | `SettingsOverlayCancelHandler` | `Assets/_Game/Scripts/UI/SettingsOverlayCancelHandler.cs` |
| `--- UI ---/GameplayCanvas/SettingsOverlay/SettingsSafeArea` | `SafeAreaFitter` | `Assets/_Game/Scripts/UI/SafeAreaFitter.cs` |
| `--- UI ---/GameplayCanvas/SettingsOverlay/SettingsSafeArea/SettingsPanel` | `SettingsScreenPresentation` | `Assets/_Game/Scripts/UI/SettingsScreenPresentation.cs` |
| `--- UI ---/GameplayCanvas/SettingsOverlay/SettingsSafeArea/SettingsPanel/SettingsScrollViewport/SettingsScrollContent/ConfirmImportantActionsToggle` | `SettingsToggleVisual` | `Assets/_Game/Scripts/UI/SettingsToggleVisual.cs` |
| `--- UI ---/GameplayCanvas/SettingsOverlay/SettingsSafeArea/SettingsPanel/SettingsScrollViewport/SettingsScrollContent/ReduceAnimationsToggle` | `SettingsToggleVisual` | `Assets/_Game/Scripts/UI/SettingsToggleVisual.cs` |
| `--- UI ---/GameplayCanvas/SettingsOverlay/SettingsSafeArea/SettingsPanel/SettingsScrollViewport/SettingsScrollContent/SfxEnabledToggle` | `SettingsToggleVisual` | `Assets/_Game/Scripts/UI/SettingsToggleVisual.cs` |
| `--- UI ---/GameplayCanvas/SettingsOverlay/SettingsSafeArea/SettingsPanel/SettingsScrollViewport/SettingsScrollContent/VibrationToggle` | `SettingsToggleVisual` | `Assets/_Game/Scripts/UI/SettingsToggleVisual.cs` |
| `--- UI ---/GameplayCanvas/SettingsUIController` | `SettingsUI` | `Assets/_Game/Scripts/UI/SettingsUI.cs` |
| `--- UI ---/GameplayCanvas/UpgradeScreen/UpgradeScrollView` | `UpgradeViewportRuntimeDiagnostic` | `Assets/_Game/Scripts/UI/UpgradeViewportRuntimeDiagnostic.cs` |

## Assets/_Game/Scenes/Loading.unity

| Hierarchy object | Controller | Source |
| --- | --- | --- |
| Scene art/layout | No custom UI controller serialized | Edit in Unity Hierarchy |

## Assets/_Game/Scenes/MainBakery.unity

| Hierarchy object | Controller | Source |
| --- | --- | --- |
| `--- UI ---/MainCanvas/CafeProgressionHud` | `CafeProgressionHudUI` | `Assets/_Game/Scripts/UI/CafeProgressionHudUI.cs` |
| `--- UI ---/MainCanvas/DessertCollectionIndexUI` | `DessertCollectionIndexUI` | `Assets/_Game/Scripts/UI/DessertCollectionIndexUI.cs` |
| `--- UI ---/MainCanvas/ImageBG` | `RawImageAspectFill` | `Assets/_Game/Scripts/UI/RawImageAspectFill.cs` |
| `--- UI ---/MainCanvas/MainNavigation` | `SafeAreaFitter` | `Assets/_Game/Scripts/UI/SafeAreaFitter.cs` |
| `--- UI ---/MainCanvas/MainNavigation/PlayButton` | `PlayButtonUI` | `Assets/_Game/Scripts/UI/PlayButtonUI.cs` |
| `--- UI ---/MainCanvas/SettingsOverlay/SettingsSafeArea` | `SafeAreaFitter` | `Assets/_Game/Scripts/UI/SafeAreaFitter.cs` |
| `--- UI ---/MainCanvas/SettingsOverlay/SettingsSafeArea/SettingsPanel` | `SettingsScreenPresentation` | `Assets/_Game/Scripts/UI/SettingsScreenPresentation.cs` |
| `--- UI ---/MainCanvas/SettingsOverlay/SettingsSafeArea/SettingsPanel/SettingsScrollViewport/SettingsScrollContent/ConfirmImportantActionsToggle` | `SettingsToggleVisual` | `Assets/_Game/Scripts/UI/SettingsToggleVisual.cs` |
| `--- UI ---/MainCanvas/SettingsOverlay/SettingsSafeArea/SettingsPanel/SettingsScrollViewport/SettingsScrollContent/ReduceAnimationsToggle` | `SettingsToggleVisual` | `Assets/_Game/Scripts/UI/SettingsToggleVisual.cs` |
| `--- UI ---/MainCanvas/SettingsOverlay/SettingsSafeArea/SettingsPanel/SettingsScrollViewport/SettingsScrollContent/SfxEnabledToggle` | `SettingsToggleVisual` | `Assets/_Game/Scripts/UI/SettingsToggleVisual.cs` |
| `--- UI ---/MainCanvas/SettingsOverlay/SettingsSafeArea/SettingsPanel/SettingsScrollViewport/SettingsScrollContent/VibrationToggle` | `SettingsToggleVisual` | `Assets/_Game/Scripts/UI/SettingsToggleVisual.cs` |
| `--- UI ---/MainCanvas/SettingsUIController` | `SettingsUI` | `Assets/_Game/Scripts/UI/SettingsUI.cs` |
| `--- UI ---/MainCanvas/TopBar` | `CafeProfileUI` | `Assets/_Game/Scripts/UI/CafeProfileUI.cs` |
| `--- UI ---/MainCanvas/TopBar` | `SafeAreaFitter` | `Assets/_Game/Scripts/UI/SafeAreaFitter.cs` |
| `--- UI ---/MainCanvas/TopBar/CoinsHudRoot` | `CashDisplayUI` | `Assets/_Game/Scripts/UI/CashDisplayUI.cs` |
| `--- UI ---/MainCanvas/UIController` | `UpgradeScreenUI` | `Assets/_Game/Scripts/UI/UpgradeScreenUI.cs` |
| `--- UI ---/MainCanvas/UpgradeScreen/UpgradeScrollView` | `UpgradeViewportRuntimeDiagnostic` | `Assets/_Game/Scripts/UI/UpgradeViewportRuntimeDiagnostic.cs` |

## Assets/_Game/Scenes/Welcome.unity

| Hierarchy object | Controller | Source |
| --- | --- | --- |
| Scene art/layout | No custom UI controller serialized | Edit in Unity Hierarchy |
