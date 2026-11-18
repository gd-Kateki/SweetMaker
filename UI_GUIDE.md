# UI editing guide and inventory

Updated 13 November 2026.

## Where to start

Upgrades uses `UI V3/Shop_Upgrade`, following `References/_0000_Shop_Upgrade.png`:
a gold frame/title plaque, cream scrolling cards, green purchase buttons, and the
red cancel icon. Both scenes use the same `UpgradeScreen.prefab` and nested
`UpgradeCard.prefab`. Use **Tools → Sweet Maker → UI → Edit Upgrade UI** or
**Edit Upgrade Card**, or select the existing UpgradeScreen instance in a scene.
All six upgrade definitions, prices, lock/max-level behavior and button actions
remain connected. `SU_RowSlice.asset` reuses a cream row region of the supplied
`SU_Backplate.png` texture so the six scrolling cards do not overlap four static
background plates. No replacement bitmap is generated.

Settings now uses the artwork in `Assets/_Game/Art/UI_Assets/UI V3/Settings_Screen/`:
gold backplate/title, cream section plates, red close button, and pink toggle/slider
elements. The shared editable design remains `SettingsArtwork.prefab`, used by
both MainBakery and Game. Open **Tools → Sweet Maker → UI → Edit Settings UI** or
select **UI Designs (Editor Only) → SettingsArtwork** in either scene.
The close icon is supplied by its sprite; its generated × caption stays empty.
Existing settings actions, values, account/cloud sections and scrolling are retained.

- **All generated designs:** Tools → Sweet Maker → UI Library. Search the 30
  visual prefabs, open one in Prefab Mode and edit without Play Mode. The same
  window links to the preview tools for existing scene panels.

- **Existing scene UI:** open `Assets/_Game/Scenes/MainBakery.unity` or `Game.unity`,
  select the UI in Hierarchy, and edit Images, TMP fonts, RectTransforms and the
  controller's serialized references normally.
- **Generated UI:** edit its visual prefab under
  `Assets/_Game/Resources/UI/VisualTemplates/`. The game creates and wires the real
  screen, then applies this prefab's appearance. The visual prefabs contain no
  gameplay controllers or button actions.
- **Shared styling:** select `Assets/_Game/Resources/UI/RuntimeUITheme.asset`.
  Assign a font, common button/panel sprites and optional color overrides.
  Empty fields/unchecked overrides preserve individual designs. Explicit shared
  overrides win over individual visual templates; leave them unset for per-screen
  artwork/fonts. The theme covers the registered generated views, not every
  unrelated scene graphic or dessert asset.
- **Tools → Sweet Maker → UI Designer** lists generated views and captures their
  visuals into editable prefabs. **UI → Create Missing Starter Templates** creates
  supported starter designs without signing in or changing player data; existing
  designs are preserved. Stop Play Mode before generating starter designs.
- **Tools → Sweet Maker → UI Panel Preview** temporarily opens existing scene
  panels for editing without permanently changing their active state.

The exact serialized scene hierarchy paths and controller locations are listed
in [the scene/prefab inventory](Docs/UI_SCENE_INVENTORY.md).

## Edit a runtime screen without changing code

1. Open its existing starter prefab in Prefab Mode. If no prefab exists yet, enter
   Play Mode, display the screen, then open UI Designer and capture that view.
2. Exit Play Mode. Save design changes to the prefab asset, not a temporary
   gameplay instance in the Hierarchy.
3. Replace Image sprites, use sliced images for nine-slice panels/buttons, change
   colors, TMP fonts/materials, text sizes, margins and alignment. Move/resize
   individual controls using RectTransforms where layout copying is enabled.
4. On each element, **Editable UI Visual** controls whether layout/visuals are
   copied. Button colors, transition type and state sprites are editable there.
   Dynamic icon sprites/colors can be excluded using the image-copy checkboxes.
5. Add decorative Image/TMP children under a bound element for borders, ribbons,
   illustrations, etc. Added artwork does not intercept clicks. Functional button
   actions remain on the game's real controls; adding a visual button does not
   create a new gameplay action.
6. Run again and exercise all states: loading, error, confirmation, disabled
   buttons and changing amounts. Check tall phones and safe areas.

Keep captured binding markers/target paths and bound hierarchy structure. Do not
delete bound functional elements. Runtime labels, cafe names, scores, currency,
legal disclosures and button captions come from the controller; prefab sample
text is preview content and is not used as live data. A generic skin must never
replace an order's live dessert icon with a captured sample icon.

Root canvas placement/order, safe areas, slider/toggle positioning and scroll
content sizing remain controlled by their runtime systems. Tutorial highlights
follow their target. Layout groups can also drive child positions. Use the
controller's serialized scene references for changing scene-level structure;
visual templates are for appearance/layout, not replacing logic.

Nested views normally have their own templates; a LeaderboardRow view is not
restyled by its ancestor. Settings deliberately owns its complete hierarchy,
including account, cloud, analytics and privacy sections, through SettingsArtwork. Disabled controls remain disabled,
listeners stay connected, and hidden screens retain their runtime visibility.

If a screen's hierarchy changes in future code, recapture its template and review
the design. Capture asks before replacing an existing design. Prefer editing the
existing prefab to recapturing a screen that already has customized decorations.

## Main scene UI

| UI | Location / how to edit |
| --- | --- |
| Home screen, Play, cash and cafe progression | MainBakery scene → `--- UI ---/MainCanvas`; use the exact paths in the scene inventory |
| Cafe profile card, details and cafe naming | Generated by `Scripts/UI/CafeProfileUI.cs`; templates below |
| Collection overlay | MainBakery → `MainCanvas/CollectionOverlay`; entry/reward prefabs below |
| Upgrades | **Tools → Sweet Maker → UI → Edit Upgrade UI** opens `Prefabs/UI/UpgradeScreen.prefab`, shared by Home and Gameplay. Use **Edit Upgrade Card** for the shared card design |
| Settings | Both scenes → canvas `SettingsOverlay`; `SettingsUI` and `SettingsScreenPresentation` |
| Settings artwork | **Tools → Sweet Maker → UI → Edit Settings UI** opens the complete shared SettingsArtwork prefab in Prefab Mode, without Play Mode. Edit this asset once for both scenes |
| Gameplay HUD, cash, energy | Game → `--- UI ---/GameplayCanvas`; EnergyHudUI's references identify the energy root |
| Customer cards | Game → GameplayCanvas → CustomerButtons; CustomerButtonUI references expose labels/icons |
| Order details / fulfillment | Game → GameplayCanvas → OrderDetailsOverlay |
| Rebirth | Game → GameplayCanvas → RebirthPanel and RebirthBackdrop |
| Campaign completion | Game → GameplayCanvas → CampaignCompletionOverlay |
| Recycle confirmation | Game → GameplayCanvas → RecycleConfirmationController → RecycleConfirmationOverlay |
| Spawn-pool selection / oven preview | Game → OvenManager and environment Oven hierarchy; see SpawnPoolSelectorUI / NextDessertPreview |
| Welcome/Loading backgrounds | Welcome.unity / Loading.unity; startup presenters add their runtime controls |

Hierarchy paths above omit separator parents for readability; use
[UI_SCENE_INVENTORY.md](Docs/UI_SCENE_INVENTORY.md) for exact paths.

## Reusable scene prefabs and world visuals

| Asset | Purpose |
| --- | --- |
| `Assets/_Game/Prefabs/UI/UpgradeScreen.prefab` | Complete shared upgrade screen, header/close, scroll viewport and six nested cards |
| `Assets/_Game/Prefabs/UI/UpgradeCard.prefab` | Shared upgrade card visuals and serialized labels/buttons |
| `Assets/_Game/Prefabs/UI/DessertCollectionEntry.prefab` | Collection item visuals |
| `Assets/_Game/Prefabs/UI/DessertCollectionRewardRow.prefab` | Collection milestone/reward row |
| `Assets/_Game/Prefabs/Gameplay/GridCell.prefab` | Board-cell visuals; preserve gameplay collider/references |
| `Assets/_Game/Prefabs/Desserts/Dessert.prefab` | Dessert rendering/drag object |
| `Assets/_Game/Data/Desserts/` and Resources/DessertCatalog.asset | Dessert content/art references, not UI skin sample icons |
| Game scene shelf/oven/environment SpriteRenderers | World-space art; edit in scene, preserve touch targets and camera-fitting references |

## Runtime UI templates

Player-facing progression wording is **Prestige**. Existing code/save field names
retain their identifiers for compatibility. Table dessert rows show icons and
available/required quantities without tiers; table headings and availability
badges remain in their authored positions.

The collection panel retains its artwork and controls. Its new **CollectionBounds**
parent preserves the existing screen margins, and an **AspectRatioFitter** on
CollectionPanel fits the whole UI to the background sprite's proportions. Adjust
the bounds to move/resize the screen without stretching its artwork.

### Edit from the scene Hierarchy

Each scene now has **UI Designs (Editor Only)**. Expand an entry to access its
linked visual prefab and edit colours, fonts, artwork and layout in the Inspector.
Select the entry's parent to use **Preview this UI**, **Hide UI previews**, or
**Save design to game**. Saving applies the prefab changes to the actual shared
design, so the game and other scenes using it receive those changes. Saving only
the scene keeps local preview overrides; use **Save design to game** for runtime
changes. Unity's normal prefab Overrides controls are also available.

For a hidden subpanel, select that child and use **Tools → Sweet Maker → UI →
Preview Selected Scene UI** to reveal its ancestors and frame it in Scene view.
Preview one design at a time. These copies are stripped when scenes are processed
for Play Mode/builds; they do not replace the wired gameplay controls.

| Scene | Designs in its editor group |
| --- | --- |
| MainBakery | Startup welcome/loading/recovery, café profile/naming, leaderboards/row, tutorial welcome/backdrop, collection introduction, shared account/privacy/cloud/energy UIs |
| Game | Tutorial instructions/recovery/highlight, rewarded cash, feature introductions, Test Lab/launcher, shared account/privacy/cloud/energy UIs |
| Welcome | Startup welcome, dependency recovery, cloud choice/restart |
| Loading | Development loading, dependency recovery, cloud choice/restart |

Shared groups include Settings, analytics consent, all four advertising-privacy
states, account deletion, cloud choice/restart, energy HUD/rewarded energy, and the
Android log console. Existing scene-authored UI (orders, rebirth, collection and
the wired UpgradeScreen instance with its cards) stays in its original canvas
hierarchy. Repeated collection rows use the linked source prefabs under
`Assets/_Game/Prefabs/UI/`.

The live bakery Energy HUD is at **MainCanvas → TopBar → EnergyHUD**. Edit its
placement in the scene and its shared appearance in the `EnergyHUD` visual design.
Both bakery and gameplay HUDs now contain a scene-authored **EnergyPlus** child.
It is visible before Play Mode and wired by EnergyHudUI at runtime; do not add
an extra button listener manually. The + offers the existing 50-energy rewarded ad.
The same energy offer opens when the player taps the Oven with zero energy.
Edit EnergyPlus and its children directly in each scene. Its scene-authored
artwork, button colours, size and position take priority over the shared HUD
design. Startup wires the ad action without replacing your custom visuals.

To edit sign-in, open MainBakery or Welcome and expand **UI Designs (Editor Only)
→ StartupWelcome**. Select the StartupWelcome entry and click **Preview sign-in
options** or **Preview Analytics screen**. Expand its linked visual to edit
**WelcomeScreen** (Google Play, Guest Play, retry/help controls) or
**PrivacyScreen** (analytics). Use **Save design to game** on the entry to apply
changes to the shared UI. The ordinary **Preview this UI** now opens sign-in by
default. Runtime startup ordering and button actions remain controlled by the game.
Google/Guest button captions are supplied by the artwork, so their generated text
labels stay empty. Sign-in child layouts use proportional anchors to retain the
authored arrangement across canvas resolutions and safe areas.

After a collection reward is claimed, its status label moves into the former
Claim button area on the right. Unclaimed rewards retain their original status
and button positions.

The live Home buttons are **MainCanvas → TopBar → Cafe Button** and
**MainCanvas → TopBar → Leaderboards Button**. Both are visible in the Editor.
Move/resize their RectTransforms and save MainBakery; those scene positions are
used during play. The Café controller reuses its assigned button, and the
leaderboard controller hides its fallback launcher when the scene button exists.
The leaderboard scene button follows the existing overlay/input blocking rules.

For the full screens, select **UI Designs (Editor Only) → CafeProfilePanel** or
**Leaderboards**, then click **Preview this UI**; the panel is now revealed and
framed automatically. Move the inner panel/controls, then **Save design to game**.

To rebuild missing entries after adding scenes/designs, use **Tools → Sweet Maker
→ UI → Add Scene UI Designs**. Existing entries and their overrides are preserved.

Template keys correspond to `<key>.prefab` inside
`Assets/_Game/Resources/UI/VisualTemplates/`. Starter templates are supplied for
the main account, ads, privacy, cloud-choice, profile, tutorial and leaderboard
screens. Additional views can be captured with UI Designer when displayed.

| Screen / template key | When / where | Controller under Assets/_Game/Scripts |
| --- | --- | --- |
| `RewardedEnergy` | Energy + → ad offer | Ads/AdOfferPopup.cs |
| `RewardedCash` | Timed cash-bonus offer | Ads/AdOfferPopup.cs |
| `AdvertisingPrivacy_Unknown` | Initial age-group selection | UI/PlayerPrivacyUI.cs |
| `AdvertisingPrivacy_Under13` | Under-13 information | UI/PlayerPrivacyUI.cs |
| `AdvertisingPrivacy_Teen` | Ages 13–17 limited-ad choice | UI/PlayerPrivacyUI.cs |
| `AdvertisingPrivacy_Adult` | Adult limited/personalized choices | UI/PlayerPrivacyUI.cs |
| `AccountDeletion` | Account/data deletion instructions and email action | UI/PlayerPrivacyUI.cs |
| `CloudProgressChoice` | Fresh-install restore/new-game, or later restore/keep-device conflict | Cloud/FreshInstallCloudChoiceUI.cs |
| `CloudRestoreRestart` | Restart notice after staged restore | Cloud/SimpleCloudPanel.cs |
| `Leaderboards` | Home launcher and two-category leaderboard panel | UI/CafeLeaderboardUI.cs |
| `LeaderboardRow` | Each loaded cafe entry; use test data to capture | UI/CafeLeaderboardUI.cs |
| `StartupWelcome` | Startup analytics privacy and account choice | UI/StartupPrivacyWelcomeUI.cs |
| `StartupLoading` | Home startup/loading/error/retry screen | UI/MainBakeryStartupUI.cs |
| `DevelopmentLoading` | Development Loading scene presenter | Startup/LoadingSceneStartupPresenter.cs |
| `StartupDependencyError` | Missing startup dependencies/retry fallback | Startup/StartupFlowIntegrationOwner.cs |
| `AnalyticsPrompt` | Standalone analytics consent prompt where applicable | Analytics/AnalyticsConsentUI.cs |
| `CafeProfileCard` | Home cafe summary card | UI/CafeProfileUI.cs |
| `CafeProfilePanel` | Cafe details/statistics panel | UI/CafeProfileUI.cs |
| `CafeNaming` | Cafe naming input and confirmation | UI/CafeProfileUI.cs |
| `FeatureIntroduction` | Upgrade/rebirth/collection introduction | UI/FeatureIntroductionPopup.cs |
| `TutorialWelcome` | Home tutorial start/welcome | Profile/HybridTutorialWelcomeUI.cs |
| `TutorialWelcomeBackdrop` | Full-screen tutorial welcome dimmer; runtime input blocking is preserved | Profile/HybridTutorialWelcomeUI.cs |
| `TutorialInstruction` | Gameplay tutorial instructions | Profile/HybridTutorialGameplayUI.cs |
| `TutorialRecovery` | Tutorial recovery/retry | Profile/HybridTutorialGameplayUI.cs |
| `TutorialHighlight` | Target-following tutorial highlight | Profile/HybridTutorialHighlightUI.cs |
| `EnergyHUD` | Scene energy HUD plus generated + button | UI/EnergyHudUI.cs |
| `SettingsArtwork` | Complete shared Settings screen, including account/cloud/privacy/analytics; editor-visible Canvas and section navigation | UI/SettingsScreenPresentation.cs + Editor/SettingsDesignerWindow.cs |
| `DeveloperCheatsV2` / `DeveloperButtonV2` | Test Lab and launcher; Editor/dev plus explicitly enabled production testing | Development/DeveloperCheatPanel.cs |
| `AndroidLogConsole` | Android development log/error console | Development/AndroidDevelopmentConsole.cs |

## Customization implementation

- Runtime: `Assets/_Game/Scripts/UI/Customization/`.
- Editor tools: `Assets/_Game/Editor/EditableUIEditor.cs`.
- Small independent assembly `SweetMerge.UI.Customization` lets account and
  analytics UI use the same visual system without circular gameplay dependencies.
- Resources load the chosen template once per key. Styles apply on creation,
  enable or explicit rebuild, not by rebuilding/scanning the UI every frame.
- Capture copies approved visual/layout components into a fresh object tree;
  it does not clone gameplay controllers or runtime button listeners.
- Theme/template changes do not need backend deployment. They do require a new
  game build for installed players.

Google Play Games sign-in dialogs, Android browser/email UI and the actual ad
creative/SDK-owned controls belong to their providers. They are not game-owned
prefabs; use the provider's supported dashboard/branding settings where available.


## Validation

669/669 Unity EditMode tests passed after integration. Coverage includes safe visual capture, correct template bindings, preserved button actions/interaction state, live text/rich-text protection, nested view styling and non-blocking artwork. Custom layouts still require visual checks on target devices.

## Settings layout (12 November 2026)

Both scenes use the same presentation. Rows use fixed canvas-unit heights rather
than percentages of the growing scroll content. The safe-area panel has a bounded
width, a fixed header/close button, and a clamped vertical scroll viewport. Account,
privacy and analytics each have their own background card. The original SettingsUI,
account, cloud and privacy actions remain connected.

Open **Tools → Sweet Maker → UI → Edit Settings UI**. The complete
`Assets/_Game/Resources/UI/VisualTemplates/SettingsArtwork.prefab` opens in Prefab
Mode. The **Settings UI** window lets you jump to sound/gameplay, account/cloud,
privacy/deletion or analytics and scroll the preview. No Play Mode is required.
Double-clicking this prefab also opens its visible world-space design Canvas.

Edit Image sprites/colors, TMP fonts/sizes, decorations and permitted positions,
then save. Changes apply to both scenes the next time Settings opens in Play Mode
or in a new build. Button fills use the Image color; interaction tints are on
Editable UI Visual. Keep bound names and markers. Player status, amounts, consent
state, disabled/hidden controls, toggle/slider state and button actions remain
owned by their game controllers. Sample labels are not player data. Preview scroll
position is not copied to the live scroll content.

The default surface is `Assets/_Game/Art/UI_Assets/SettingsRemake/SettingsSurface.png`
with 18-pixel nine-slice borders. Safe-area panel width, initial section placement
and total scroll height are managed by SettingsScreenPresentation. The master
prefab supplies their appearance and the permitted child layout overrides.

There is one required wired SettingsOverlay in MainBakery and one in Game; both
use this shared design. They are not separate old/new designs. Do not delete
these scene instances. The six superseded section visual prefabs were removed,
and the starter generator no longer recreates them. UI Designer and UI Panel
Preview provide a direct shortcut to the complete design.

Use Tools → Sweet Maker → UI → Render Settings Previews for visual-only PNGs in
`tmp/settings-<scene>-top.png` and `-bottom.png`. Rendering uses the shared prefab;
it does not sign in, load player saves or call cloud APIs.

## Upgrade screen (12 November 2026)

Open **Tools → Sweet Maker → UI → Edit Upgrade UI** to see the complete screen
in Prefab Mode without Play Mode. Its **Upgrade UI** window provides card
shortcuts and a preview scroll control. **Edit Upgrade Card** opens the common
card prefab; changing its artwork, text styling and layout updates all six cards
in both scenes. Save the prefab normally.

The shared screen is `Assets/_Game/Prefabs/UI/UpgradeScreen.prefab`. Its source is
visible for editing, while both scene instances start closed. The original screen
controller, close/open buttons, modal blocking and upgrade purchase rules remain
connected. Opening the shop resets its scroll to the top.

The cards use fixed preferred heights, readable current/next values and a
separate aligned price/purchase area. The maximum-level badge fits between the
heading and effect area. The panel uses the rounded nine-slice surface shared
with Settings; green purchase artwork retains a separate disabled tint.

Keep each card's UpgradeDefinition and UpgradeCardUI references. The six nested
cards have sample text for editor viewing; gameplay replaces it with the player's
actual levels, prices and unlock state. To edit every card consistently, edit
UpgradeCard itself rather than adding styling overrides to individual instances.

Use **Tools → Sweet Maker → UI → Render Upgrade Previews** for
`tmp/upgrades-top.png` and `tmp/upgrades-bottom.png`. This previews visuals without
loading a player save, signing in or purchasing anything.

## Tutorial panels (12 November 2026)

Use Tools → Sweet Maker → UI → Edit Tutorial Welcome, Edit Tutorial Instructions,
or Edit Tutorial Recovery. These open the complete panels in Prefab Mode without
Play Mode. They are TutorialWelcome.prefab, TutorialInstruction.prefab and
TutorialRecovery.prefab under Assets/_Game/Resources/UI/VisualTemplates/.
Edit artwork, fonts, colors and permitted child layout; retain the binding markers.
Live instruction/error text, Retry/Continue actions and tutorial progress remain
controlled by the tutorial system. Panels use the same rounded surface as Settings.

## First-time popups (12 November 2026)

Open Tools → Sweet Maker → UI → Edit First-Time Popups. Select the feature
introduction, startup welcome/privacy, café naming, cloud choice or age-specific
advertising privacy design. Each opens in Prefab Mode without Play Mode. The
window can switch welcome/privacy and naming/confirmation previews. Save edits
normally; source preview visibility never replaces live UI visibility.

Assets are FeatureIntroduction, StartupWelcome, CafeNaming, CloudProgressChoice
and AdvertisingPrivacy_Unknown/Teen/Adult/Under13 under
Assets/_Game/Resources/UI/VisualTemplates/. FeatureIntroduction is shared by the
first Upgrade, Rebirth and Collection explanations. Edit visuals and permitted
layout, keeping names and Editable UI Visual markers. Runtime copy, consent,
sign-in, naming, restore/new-game decisions and acknowledgements remain owned by
their original controllers. Decorative backgrounds stay behind functional UI.

## My Café and Leaderboards (12 November 2026)

Use Tools → Sweet Maker → UI → Edit My Cafe, Edit My Cafe Button,
Edit Leaderboards or Edit Leaderboard Row. These open the editable visual prefabs
without Play Mode. Assets are CafeProfilePanel, CafeProfileCard, Leaderboards and
LeaderboardRow under Assets/_Game/Resources/UI/VisualTemplates/.

My Café has separated portrait, café name, rating, earnings and completed-order
areas. Leaderboards retains its money/orders tabs, paging, refresh and status
messages. Row text and all scores remain live data. Your entry uses a pale green
highlight and a (You) suffix. The row root's Copy Image Color is off to preserve
that identity highlight; its sprite, typography and child layout remain editable.
Do not rename bound elements or remove their Editable UI Visual markers.

Leaderboard rows are created from live results, so edit their separate row design.
Editor-rendered PNGs in tmp/CafeProfilePanel-updated.png and
Leaderboards-updated.png use illustrative values without contacting UGS.

## Leaderboard overlay visibility (13 November 2026)

The leaderboard launcher appears only on the ready, unobstructed Home screen.
Settings, My Café, naming, Collection, startup and tutorial/introduction overlays
register their actual visible roots through HomeOverlayVisibility. Modal leases
also hide the launcher. An open leaderboard closes when another overlay or modal
needs the screen, and scene changes hide it immediately. Closing it releases only
its own input lease. LateUpdate enforces visibility after UI click handlers and
before rendering; the editable artwork and leaderboard data flow are unchanged.

When adding a custom home overlay in code, attach HomeOverlayVisibility to its
actual show/hide root, not to an always-active controller or launcher button.

## Remaining generated screens (13 November 2026)

The remaining UI pass covers rewarded energy/cash offers, account/data deletion,
Home loading, development loading, startup dependency errors, optional analytics
consent and the cloud-restore restart notice. They now use the same rounded
surfaces, readable text and consistent buttons as the other updated screens.
Status and feedback areas have dedicated space, and recovery instructions stay
inside their cards. Consent wording, player data and actions stay owned by the
original controllers. The obsolete loading note about automatic sign-in/cloud
was replaced with a short explanation of local progress and cloud backup.

Seven previously uncaptured designs are now available: AnalyticsPrompt,
DevelopmentLoading, StartupDependencyError, CloudRestoreRestart, EnergyHUD,
AndroidLogConsole and TutorialHighlight. The energy + button uses the shared
style; existing energy icons/artwork are preserved. The log console keeps its
dark theme and live severity colors, with editable button artwork. Tutorial
highlight styling is editable while its controller retains ownership of target
position and border geometry. Test Lab retains its existing dark design.

Use Tools → Sweet Maker → UI Library for all 30 generated designs. Select hidden
sections in Prefab Mode and use Show currently selected hidden panel to preview
them. Keep binding markers, bound names and the controls' hierarchy. Preview
visibility is never copied to live screens. Edit allowed styling/layout and save;
re-enter Play Mode or rebuild to load the changes. Actual button listeners,
interactable/hidden states, rich-text permissions and dynamic labels are preserved.

EnergyHUD deliberately excludes icon sprites/colors from copying. TutorialHighlight
deliberately excludes layout copying so gameplay targets stay correctly highlighted.
Shared theme overrides still take precedence over individual designs.

GeneratedUiPolish is a one-time editor migration/build helper, not a runtime UI
system or a tool for overwriting your later design work. Visual previews are
written to tmp/ui-library-<key>.png; the rendering tools do not sign in, send
analytics, restore saves or request ads.

### Title colours

Main headings use rainbow-inspired violet, berry, teal and blue gradients.
Section headings use a quieter violet-to-blue gradient. Destructive/deletion
titles keep a red-to-amber warning palette. Light and dark variants preserve
the existing title contrast. These are static colours, with no animated effects.

Edit a title's TextMeshPro component in its visual prefab (or the original
scene/prefab for scene-authored UI): use **Color Gradient** and its four corner
colours; keep Vertex Color white to avoid tinting the gradient. Turn off Color
Gradient for a solid colour. Generated UI copies these settings into the live
heading while preserving its actual text and actions.

**Tools → Sweet Maker → UI → Apply Title Colours** reapplies the default palette
across the current UI assets and Home/Game scenes. It overwrites custom title
colours, so use individual Inspector edits for later customization.
