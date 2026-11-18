# V3 screen artwork and editing map

Updated 18 November 2026. Source artwork: `Assets/_Game/Art/UI_Assets/UI V3/`.
Reference compositions: the `References` subfolder. Live values, eligibility,
sign-in actions, privacy choices and reward delivery remain controlled by the game.

| Screen | V3 artwork folder / reference | Edit here |
| --- | --- | --- |
| Bakery / Home | Main_Menu / Main_Screen | MainBakery scene → MainCanvas; background, TopBar and MainNavigation |
| Gameplay | Play_Screen / Play_Screen | Game scene → GameplayCanvas; world artwork also under Gameplay and Environment groups |
| Oven tier dropdown | Drop_Down_Screen / Drop_Down | Game → GameplayCanvas → OvenTierSelectionPanel and OvenTierSelectorButton |
| Prestige | Rebirth_Screen / Rebirth | Game → GameplayCanvas → RebirthPanel; internal identifiers retain `Rebirth` for compatibility |
| Recycle confirmation | Recycle_Dessert_Screen / Recycle_Dessert- | Game → GameplayCanvas → RecycleConfirmationOverlay |
| Dessert collection | Dessert_Collection / Dessert_Collection | MainBakery → MainCanvas → CollectionOverlay → CollectionBounds → CollectionPanel |
| Collection dessert tile | Dessert_Collection/DC_Discovery_Plate | Assets/_Game/Prefabs/UI/DessertCollectionEntry.prefab |
| Collection reward row | Dessert_Collection/DC_Collection_Reward and DC_Claim_Button | Assets/_Game/Prefabs/UI/DessertCollectionRewardRow.prefab |
| Name / confirm café name | Name_Your_Cafe and Confirm_Cafe_Name / _0001_Confirm_Cafe_Name and _0002_Coins-copy | Resources/UI/VisualTemplates/CafeNaming.prefab; NamingInputStep and NamingConfirmationStep |
| Energy / cash ad offer | Cafe_Bonus / _0003_Coins | Resources/UI/VisualTemplates/RewardedEnergy.prefab and RewardedCash.prefab |
| Sign-in | Sign_In and Loading_Screen / _0004_Loading_SignIn | Resources/UI/VisualTemplates/StartupWelcome.prefab → SafeArea → WelcomeScreen |
| First analytics choice | Help_Improve_Dessert_Cafe | StartupWelcome.prefab → SafeArea → PrivacyScreen |
| Analytics settings prompt | Help_Improve_Dessert_Cafe | Resources/UI/VisualTemplates/AnalyticsPrompt.prefab |
| Loading / development loading | Loading_Screen / Loading | Resources/UI/VisualTemplates/StartupLoading.prefab and DevelopmentLoading.prefab |
| My Café | Shared V3 sliced gold frame, flat statistics section / _0005_Main_Screen | Resources/UI/VisualTemplates/CafeProfilePanel.prefab; launcher remains in MainBakery TopBar |
| Settings | Settings_Screen / Settings | Resources/UI/VisualTemplates/SettingsArtwork.prefab (previous V3 pass retained) |
| Upgrades | Shop_Upgrade / _0000_Shop_Upgrade | Assets/_Game/Prefabs/UI/UpgradeScreen.prefab and UpgradeCard.prefab (previous V3 pass retained) |

All Resources paths above start at `Assets/_Game/Resources/`.
Shared visual designs can also be opened from **UI Designs (Editor Only)** in
the scene hierarchy or **Tools → Sweet Maker → UI Library**. Edit the linked
prefab, or use the existing design-save workflow; changing an inspection copy
alone does not change the shared resource.

## Editing safely

- Keep binding markers and controller references. Decorative images can be changed freely.
- Sign-in Google and Guest artwork already contains its labels. The background
  already contains the cloud-save tip; do not add duplicate captions over them.
- Recovery/error controls remain separate from the normal sign-in choices.
- The loading bar is decorative, not a fabricated percentage of actual startup work.
- Collection retains its overall aspect-ratio fitter. `CollectionReferenceGrid`
  fits three portrait columns to the scroll width; change that component if
  intentionally changing the catalog's column count/proportions.
- Collection claimed states and the player's selected Oven tier keep their
  existing behavior. Dessert sprites and quantities remain supplied by gameplay.
- Custom EnergyPlus artwork and its children are deliberately preserved.
- Leaderboards, tutorials, cloud decisions and privacy-age variants now reuse
  the shared V3 artwork. Their integration and editing locations are documented
  in `REMAINING_UI_V3.md`; they have no separate supplied reference composition.

`V3UiReferenceEditor` is a manual migration tool, never an import/play-time
restyler. Do not rerun **Apply V3 Reference Artwork** after making your own
layout changes unless you intend to reapply this reference layout.

## Verification

The follow-up polish keeps the same V3 artwork. It centers the Settings header,
reduces the collection title plaque, fits two complete discovery rows, adds its
reference scrollbar, aligns
reward names/details/amounts/actions, improves Oven selector contrast, gives
sign-in errors a separate readable area, and regularizes popup/upgrade type
and button spacing. These are saved layout changes, not play-time restyling.

- Android-target Unity compilation completed successfully.
- Editor previews inspected for Home, gameplay, collection, Prestige, recycle,
  Oven dropdown, café naming, sign-in, loading, analytics and rewarded energy.
- All 764 EditMode cases passed in the full regression run after polishing.
  Visual tests allow artist-selected icon sizes and supported clipping modes,
  and check the Prestige heading against its raised plaque.
- This pass did not create an Android build or perform a device playtest.
