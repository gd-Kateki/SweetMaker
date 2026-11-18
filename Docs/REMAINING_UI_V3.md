# Remaining UI integration — 18 November 2026

The remaining screens reuse the existing UI V3 artwork. No new bitmap artwork,
ad service, sign-in provider or game-data format was added.

## Where to edit

Open **Tools → Sweet Maker → UI Library**, or the linked designs under
**UI Designs (Editor Only)** in the scene hierarchy. Shared templates live in
`Assets/_Game/Resources/UI/VisualTemplates/`.

| Screen | Shared template or scene location |
| --- | --- |
| Leaderboards and ranking rows | Leaderboards.prefab, LeaderboardRow.prefab |
| Tutorial welcome | TutorialWelcome.prefab, TutorialWelcomeBackdrop.prefab |
| Tutorial instruction, recovery and target highlight | TutorialInstruction.prefab, TutorialRecovery.prefab, TutorialHighlight.prefab |
| First-time feature explanations | FeatureIntroduction.prefab |
| Restore cloud / start new game / reconnect and confirmation states | CloudProgressChoice.prefab |
| Cloud restore restart message | CloudRestoreRestart.prefab |
| Startup service error and retry | StartupDependencyError.prefab |
| Age selection | AdvertisingPrivacy_Unknown.prefab |
| Teen, adult and under-13 advertising privacy | AdvertisingPrivacy_Teen.prefab, AdvertisingPrivacy_Adult.prefab, AdvertisingPrivacy_Under13.prefab |
| Account/data deletion instructions | AccountDeletion.prefab |
| Test Lab and its launcher | DeveloperCheatsV2.prefab, DeveloperButtonV2.prefab |
| Android log console | AndroidLogConsole.prefab |
| Order details | Game scene → GameplayCanvas → OrderDetailsOverlay → OrderDetailsPanel |
| Campaign completion | Game scene → GameplayCanvas → CampaignCompletionOverlay → CampaignCompletionPanel |

The existing Settings, Upgrades, Café, collection, gameplay, loading, sign-in,
naming and ad-offer designs retain their earlier V3 updates.

## Shared artwork

`Assets/_Game/Art/UI_Assets/UI V3/Shared/` contains reusable sliced sprites for
the gold frame, cream surface and gold/green/red/purple buttons. These reference
the existing V3 textures; resizing them preserves their edges without duplicating
bitmap files. Replace these sprite assets or edit a screen's Image to customize it.

Text and actions remain live. Keep binding markers, controller references and
modal input blockers. Template editing does not replace cloud decisions, consent
choices, saved data or testing commands. The tutorial's new Oven illustration is
decorative; it uses the same Oven artwork as gameplay.

The log console and Test Lab feedback retain dark surfaces for readable log
severity and result colors. Active player highlighting on leaderboard rows remains
controlled by the leaderboard controller. Previously customized energy + buttons
are outside this migration.

`RemainingUiV3Editor.Apply` is a manual migration, never an import or startup hook.
Reapplying it intentionally restores the layouts/style described here, so edit the
saved scene/prefab assets for subsequent custom visual work.

## Verification

Unity compiled for the Android target. The full EditMode suite passed 764/764;
final editable-binding checks passed 6/6 and tutorial checks passed 27/27.
Rendered previews were inspected for leaderboards, tutorials/recovery, cloud
choices, privacy/deletion prompts, Test Lab, logs, order details and completion.
The order layout check verifies that its requirements, reward and confirmation
stay inside the enlarged panel without overlap. No Android build or device
playtest was performed in this UI pass.
