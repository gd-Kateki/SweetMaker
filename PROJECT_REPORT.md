# Dessert Merge Cafe — Project Report

Updated: 6 November 2026. Workspace: `D:/SweetMaker` (Unity project name: SweetMaker).

This report describes the source and configuration present in this checkout. It distinguishes implemented behavior from device/dashboard verification. It is a technical handover and project overview, not a guarantee that every possible runtime defect has been found. Credentials, signing passwords, and player data are intentionally excluded.

## 1. Project overview

Dessert Merge Cafe is a portrait Android, 2D merge-and-progression game. Players produce desserts, merge matching desserts into higher tiers, manage board and serving-shelf space, fulfill customer orders, earn cash, and purchase upgrades. Cafe progression, rebirths, collection rewards, and increasingly valuable orders provide longer-term goals. Google Play Games sign-in connects the player's local progress to Unity Gaming Services (UGS). Rewarded ads and Home-button interstitials provide the current advertising implementation.

The project has 30 dessert definition assets, a resource-loaded dessert catalog, upgrade definitions, serialized scenes, procedural customer orders, tutorial handling, and runtime UI. Asset presence alone does not establish that every asset is used in a release scene; test-named assets should not be deleted without checking serialized and runtime references.

## 2. Engine and release configuration

| Item | Current configuration |
|---|---|
| Unity | 6000.6.3f1, Unity 6.6 |
| Main target | Android portrait |
| Rendering/UI | Universal Render Pipeline, 2D sprites, uGUI and TextMesh Pro |
| Input | Unity Input System, touch-oriented gameplay |
| Release profile | `Assets/Settings/Build Profiles/Android Release.asset` |
| Release application ID | `com.offcutstudios.dessertmergecafe` |
| Release version / code | 0.09.0 / 6 |
| Minimum / target Android API | 29 / 36 |
| Backend / architecture | IL2CPP / ARM64 |
| Distribution | Signed Android App Bundle (AAB) |
| Release debug flags | Development, profiler and script debugging disabled |
| Release environment | UGS production |
| Release scenes | MainBakery, Game |

Version code 6 was prepared after the user identified 5 as the current uploaded code. Recheck Play Console before any later upload. The production UGS setup was reported complete by the user; this checkout cannot independently prove the deployed state. No newly signed release AAB was produced by the preceding validation work; the last build attempt required signing passwords.

## 3. Gameplay and progression

- **Oven and spawning:** oven controllers, spawner and spawn-pool selection produce desserts for the board.
- **Board:** `GridManager` builds a five-column, six-row grid. Progression controls usable capacity. Drag/merge interactions use explicit transaction and session state to protect against invalid mutations.
- **Shelves:** serving plates store desserts outside the board. Shelf capacity is upgradeable.
- **Orders:** `OrderManager` maintains customer slots and procedural requirements. Order fulfillment checks available desserts and credits gameplay earnings through `EconomyManager`.
- **Economy:** current wallet cash is distinct from lifetime money earned and lifetime orders completed. Earnings reject integer wallet overflow; lifetime counters use saturating arithmetic.
- **Upgrades:** assets exist for oven, board space, shelf, customers, money multiplier and luck. `PlayerProgressionManager` and `UpgradePurchaseManager` coordinate runtime progression and purchases; consult the assets/code for individual prices and unlock values.
- **Energy:** maximum 100; regeneration interval is 60 seconds. Rewarded energy adds up to 50, capped at 100. Save metadata supports restoring energy timing.
- **Rebirth/campaign:** cafe titles run from Humble Beginnings through Legendary Cafe. The progression catalog supports 0–10 completed rebirths and five regular star levels, unlocked at rebirth counts 0, 3, 5, 7 and 10. Saved run tier, campaign completion and collection state support progression presentation.
- **Collection/tutorial:** dessert collection UI, reward rows, introductory popups and tutorial state are implemented. Intro acknowledgements are included in save data.
- **Presentation:** cash, energy, customer previews, upgrade screens, rebirth, collection, Settings, audio and click effects are separate UI/controller components. Camera fitting adapts the world view to portrait aspect ratios; safe-area components support mobile UI.

## 4. Scene and startup flow

`MainBakery` is the release entry/home scene; `Game` contains merge gameplay. Development startup also has Welcome/Loading infrastructure. `StartupFlowCoordinator`, `StartupFlowIntegrationOwner`, `GameStartupCoordinator` and `ApplicationReadinessCoordinator` coordinate startup, account/privacy steps and gameplay readiness.

The release home flow handles account/privacy initialization without requiring the development Welcome scene. Gameplay saves and mutations depend on verified startup/session readiness. `HomeButtonUI` prepares and saves a verified gameplay departure before requesting an optional interstitial and navigating home. `GameplayModalInputGate` and modal admission prevent incompatible gameplay operations while blocking UI is open.

## 5. Architecture and source map

All paths below are relative to the project root.

| Area | Main location / responsibility |
|---|---|
| Game code | `Assets/_Game/Scripts/` |
| Core | Economy, navigation, audio, application readiness, merge-session ownership and transaction outcomes |
| Gameplay | Grid, desserts, drag/merge, oven, orders, progression, shelves, collection and modal input gate |
| Save | SaveManager, schema, discovery, freezing, validation, restoration and startup coordination |
| Startup | Account/privacy/startup flow and development scene routing |
| Authentication | Google Play Games sign-in, account controls and build-specific OAuth resolution |
| Profile | Local cafe profile/name persistence |
| Cloud | Backup envelope, ownership, sync journal, restore handling, dashboard statistics and leaderboards |
| Ads | SimpleAdManager, SimpleAdsSettings and AdOfferPopup |
| Analytics | UGS initialization and analytics consent/bootstrap |
| UI / Settings | Gameplay and home screens, overlays, safe areas, settings presentation |
| Development / Utilities | Cheat commands, Android development console and debugging tools |
| Content | `Assets/_Game/Data/`, `Resources/`, scenes and prefabs |
| Editor tooling | `Assets/_Game/Editor/`: build identity guards, release builder, reset/preview/diagnostic tools |
| Unity tests | `Assets/_Game/Tests/Editor/` |
| Backend deployment | `Assets/_Game/Leaderboards/` |
| CLI validation | `Tools/verify_android_release.py`, `Tools/Tests/cafe-leaderboards.test.cjs` |

Many runtime classes use persistent singleton managers; UI and scene-specific controllers bind to them. Runtime systems also create some UI/managers automatically, so absence from a scene hierarchy does not mean a class is unused. Serialized GUID references, Resources loading and reflection-based tests must be considered before deleting code/assets.

## 6. Player data and local persistence

The primary schema is `PlayerSaveData`, version 2, saved as `player_save_v2.json`. Legacy `player_save.json` discovery and validation paths remain. Save code uses prepared/frozen snapshots, validation, atomic-write/backup handling and restoration verification to avoid publishing partially captured gameplay.

Saved domains include wallet/lifetime economy, upgrade progression, completed rebirth count, highest tier this run, campaign completion, board desserts, shelf desserts, customer orders, sequential order state, collection state, energy metadata and feature-introduction acknowledgements. Cafe profile/name and tutorial information are also represented in the cloud envelope.

`SavePathPolicy` isolates data:

| Mode | Local root / meaning |
|---|---|
| RELEASE | `Application.persistentDataPath` |
| DEVELOPMENT-ISOLATED | `SweetMaker-Development` below the persistent-data root |
| GUEST-QA-SANDBOX | Explicitly enabled Windows Editor temporary sandbox, separate from ordinary saves |

`LocalSaveOwnership` binds local content to the verified account. `cloud-sync-v1.json` records the accepted cloud ancestor and write-lock history. Ordinary offline local saves preserve ownership. Restore staging and startup validation block unsafe writes while a restore is pending. User save files live outside the source checkout and were not touched by cleanup.

The guest QA setup is documented in [DMC-LOCAL-02F-Guest-QA-Sandbox.md](DMC-LOCAL-02F-Guest-QA-Sandbox.md).

## 7. Authentication and UGS environment

Google Play Games authentication feeds UGS Authentication. Cloud writes require a verified signed-in, authorized, linked Google Play Games owner; an anonymous/guest state does not establish ownership of an existing cloud save. Account changes invalidate synchronization authorization.

`GooglePlayGamesWebClientResolver` selects the appropriate OAuth configuration for the application identity. UGS initialization is shared through `UnityServicesInitializationCoordinator`, with release and development environment selection. Development and release data must be inspected in the corresponding Dashboard environment.

For Google Play installs, Play Games credentials must match the release package and Play app-signing certificate, not merely the local upload certificate. Tester access and dashboard provider configuration remain operational setup requirements.

## 8. Automatic cloud backup and restore

`SimpleCloudBackup` stores a validated envelope in UGS Cloud Save Player Data:

- Release key: `dmc_backup_v1_RELEASE`.
- Development key: `dmc_backup_v1_DEVELOPMENT-ISOLATED`.
- Envelope version 1 contains player ID, mode/environment, serialized V2 save, cafe name, tutorial stage and a Base64 SHA-256 content checksum.
- Eligible gameplay checks are scheduled on a five-second cadence. This is a foreground retry/check interval, not a guaranteed server update every five seconds under network errors, pauses, conflicts or missing authorization.
- Backup captures/flushed local progress automatically after verified sign-in; routine manual linking is not required.
- One operation runs at a time. Reads and cloud write locks protect against stale overwrites.
- The sync journal remembers the accepted cloud ancestor. Local gameplay advancing from that ancestor should upload automatically rather than trigger a false conflict.
- Genuine divergent cloud/local progress requires a user choice. A reinstall with existing cloud progress offers restore versus starting a new game; a new game is an explicit decision, not a silent overwrite.
- Restore is staged and validated before gameplay uses it. Pending restores prevent conflicting writes.
- Network errors retain local play and retry; Settings reports cloud state/errors.

The earlier false-conflict and cafe-name issues were addressed in this working tree and covered by regression tests. Cloud backup saves progress data; it does not upload the Android game binary to UGS.

### Dashboard summary fields

`PlayerStatisticsCloudSync` projects acknowledged backup data into separate Cloud Save fields for current money, lifetime earnings, lifetime completed orders, current rebirth count and cafe name. These summaries are throttled to a minimum 30-second upload interval and skip unchanged snapshots. They may therefore lag the backup key. The cafe-name field is `dmc_player_profile_v1_cafe_name`; statistics use the `dmc_player_stats_v1_` prefix.

## 9. Leaderboards

| Category | UGS leaderboard ID | Entry display |
|---|---|---|
| Lifetime money earned | `total_money_earned` | Cafe name, earned total, current rebirth |
| Lifetime orders completed | `total_orders_completed` | Cafe name, completed total, current rebirth |

The client sends only an acknowledged backup checksum to `SyncCafeLeaderboards` through Cloud Code. The server script reads the authenticated player's Cloud Save backup, validates ownership/environment/schema/totals and derives both leaderboard entries from it. A deployed access policy denies direct Player score writes to these two boards. Leaderboards are descending, keep-latest projections; they are not the source of restored progress.

Client synchronization has a minimum 30-second interval, unchanged-value suppression, account checks and failure backoff (30, 60, 120, 240, then 300 seconds). The UI uses pages of 25, cafe metadata, rebirth, pagination, self highlighting, a five-second refresh cooldown, a 15-second page cache and a 20-second visible loading timeout.

Deploy both `.lb` definitions, `SyncCafeLeaderboards.js` as a published **Cloud Code** script, and the access policy into the intended UGS environment. Merely creating a Cloud Save item is not script deployment. Development deployment does not publish production. Detailed instructions: [Leaderboards README](Assets/_Game/Leaderboards/README.md).

Limitations: the two category writes are not transactional; concurrent devices are last-write-wins. UGS numeric scores use doubles, so adjacent totals above 2^53 can rank identically; exact Int64 totals are retained as metadata strings for display. Cloud backups remain client-writable, so server-mediated publication is not authoritative anti-cheat protection.

## 10. Advertising

The active implementation is the small LevelPlay-based `SimpleAdManager`, configured by `Assets/_Game/Resources/SimpleAdsSettings.asset`. App/ad-unit IDs and placement names are stored there; do not replace them with example IDs when building.

| Format | Trigger / behavior |
|---|---|
| Interstitial | Eligible after five minutes, shown on Home interaction when loaded; navigation proceeds without an ad if unavailable |
| Energy rewarded | Energy plus button opens an offer; successful reward callback adds up to 50 energy, maximum 100 |
| Cash rewarded | Offer after five minutes of eligible gameplay; amount scales with current order rewards and progression, minimum 100 and maximum 1,000,000 |

Rewards are tied to an auction identity and a one-time claim ticket; completion callback, not offer acceptance, grants the reward. Reward application requests a local save. Ads run on Android devices; Editor does not simulate reward payouts. Loading failures retry, and unavailable ads must not prevent basic navigation.

SDK initialization failures now retry after 30 seconds while advertising remains eligible. Verify real ad callback order, rewarded payout, dismissals and connection recovery on a test device. The previous elaborate ad architecture was replaced. Archived ad design/privacy documents describe historical work and must not be treated as proof of the current production consent flow. Analytics consent and advertising consent are separate concerns; ads now wait for the age/privacy flow, and ad-provider privacy configuration still needs device/dashboard verification.

## 11. Analytics, settings and development tooling

The project includes analytics consent/bootstrap and startup privacy UI with a configured privacy-policy link. Settings provide account and backup interaction alongside local preferences. Existing analytics tests cover consent/bootstrap behavior; this does not independently establish dashboard data collection or advertising consent compliance.

The Android development log/error console and cheat panel are development features. They should not appear in a release build. Keep build identity guards and reset/diagnostic tooling: they help prevent mixing development and release accounts or saves. `MobileFrameRateController` adapts the target rate to the mobile display's available refresh rate.

## 12. Dependencies

The following service/tool versions are taken from `Packages/manifest.json`; the lockfile records resolved packages. Additional Unity 2D, renderer, UI, input, IDE and engine-module dependencies are retained.

| Package | Version |
|---|---|
| `com.unity.inputsystem` | 1.20.0 |
| `com.unity.render-pipelines.universal` | 17.6.0 |
| `com.unity.services.analytics` | 6.3.0 |
| `com.unity.services.authentication` | 3.8.1 |
| `com.unity.services.cloudsave` | 3.4.2 |
| `com.unity.services.cloudcode` | 2.10.4 |
| `com.unity.services.deployment` | 1.7.2 |
| `com.unity.services.levelplay` | 9.6.0 |
| `com.unity.services.leaderboards` | 2.3.4 |
| `com.unity.services.tooling` | 1.4.1 |
| `com.unity.test-framework` | 1.8.0 |
| `com.unity.ugui` | 2.6.0 |

Cloud Code 2.10.4 is embedded under `Packages/com.unity.services.cloudcode` with a small Editor compatibility patch for Unity 6 EntityId asset-opening callbacks. See its `LOCAL_PATCH.md` before upgrading; the embedded copy takes precedence over the registry dependency. Runtime service behavior is unchanged. The targeted CloudCodeAssetCallbackTests regression passed (1/1) after compilation on Unity 6000.6.3f1; evidence is in `tmp/cloudcode-callback-tests.xml`.

Google Play Games and External Dependency Manager are also present under Assets. Android Gradle templates, resolver dependencies and LevelPlay adapter settings are part of the build integration and were preserved. A package being installed is not proof that every feature it offers is used.

## 13. Build, signing and deployment

1. Open with Unity 6000.6.3f1 and Android SDK/NDK/OpenJDK support installed.
2. Select the Android Release profile. Check application ID, unused version code, target API 36, IL2CPP, ARM64 and disabled development flags.
3. Enter the existing upload-keystore and key-alias passwords in Unity Publishing Settings. Do not commit credentials or put them in this report.
4. Use **Tools > Build Android Release Bundle**. The helper remains named `ReleaseBuildTemporary.cs`, but it is currently useful release tooling and was retained.
5. The helper writes a timestamped AAB under `Builds/Android/Release/`, build information, and status/latest-output paths under `tmp/`.
6. Run `Tools/verify_android_release.py` with the generated AAB, Unity JDK, pinned bundletool and expected version code. It validates the bundle/manifest/signature, ARM64 and native 16 KB alignment, and writes a verification receipt.
7. Upload to Google Play internal testing and install through Play for real signing/authentication validation.

Full handover: [GOOGLE_PLAY_INTERNAL_TESTING.md](GOOGLE_PLAY_INTERNAL_TESTING.md). Local tools cannot verify whether a specific Dashboard policy or OAuth credential is actually deployed.

## 14. Tests and current verification status

The full Android-targeted Unity EditMode run on 6 November 2026 passed **639/639 tests**, with zero failures and zero skipped tests. The Cloud Code Node suite passed **16/16 tests** using mocked service transport. Retained evidence: `tmp/preproduction-tests.xml` and `tmp/preproduction-tests.log` (local generated files, now ignored by Git).

The prior review fixed customer preview labels extending beyond their card backgrounds. It also corrected a stale camera test to initialize the actual responsive camera fitter before asserting bounds across supported portrait aspect ratios. Cloud, authentication, save, leaderboard, ad calculation, progression and release-identity regression coverage passed in that run.

Run the backend checks with `node --test Tools/Tests/cafe-leaderboards.test.cjs`. Run Unity EditMode tests through Test Runner or batch mode with the project closed in the interactive Editor. Never launch a second batch editor against an already-open project.

These results do not prove release IL2CPP compilation, live SDK behavior, production dashboard state, visual quality on every device or store acceptance. Post-cleanup validation also passed: Unity batch-mode compilation for the Android target exited successfully with code 0 (`tmp/cleanup-compile.log`). Report links, cleanup manifest paths and diff whitespace were checked. The full suite was not repeated for this cleanup because gameplay code was unchanged.

### Internal-test acceptance checklist

- Fresh Google sign-in, cafe naming and tutorial completion.
- Automatic backup followed by further orders/earnings without a false conflict.
- Correct cafe name and summaries in the production environment.
- Both leaderboard categories updating after backup and synchronization delay.
- Reinstall restore/new-game choices, account switching, offline/reconnect and genuine conflict handling.
- Home interstitial eligibility, energy reward, dynamic cash reward, dismissals and duplicate-callback protection using ad test devices.
- Release build hides developer tools; UI remains readable on tall phones and around safe areas.
- Play signing, native-library compatibility and AAB verification pass.

## 15. Cleanup performed

Removed 29 files totaling 8,354,615 bytes (about 7.97 MiB): older temporary test/build logs and XML results, stale failed-build status messages, the one-off `AdsTestRunTemporary.cs` launcher and its `.meta`, and generated Python bytecode. Exact paths/sizes are recorded in [cleanup manifest](Docs/cleanup-manifest-2026-11-06.json).

The latest full test evidence was retained. Added ignore rules for root `tmp/`, Python caches, and generated bin/obj folders in the isolated Cloud Code prototype. Ignore rules do not remove files already tracked by Git.

Moved three historical ad architecture/privacy notes into `Docs/Archive/` and labelled that folder historical. Preserved gameplay assets, source, tests, SDK/vendor licenses, `.meta` GUIDs for retained assets, existing source changes, signing configuration, build archives, debug symbols and player data.

The following were deliberately retained:

- `BuildVerification/` and existing build outputs: old binaries, symbols and IL2CPP backup files can be necessary to diagnose shipped builds. Many are already tracked; deleting local copies would not remove repository history.
- `Library/`, `.utmp/` and other Unity caches: regenerable, but removal forces expensive reimports/builds and is unnecessary for source cleanup.
- `CloudCode/CafeProfileRegistrationPrototype/`: isolated development-only historical C# prototype, not called by gameplay. Its source and compiled artifacts remain; no project file was present at inspection, so rebuildability should be repaired before further prototype work.
- `output/pdf/` and `tmp/pdfs/`: unrelated existing document output/preview, retained as user-authored artifacts rather than assumed disposable game files.
- Test-named order definitions and unused-looking SDK/assets: names alone are insufficient evidence that removal is safe.

## 16. Maintenance priorities

First complete the Play internal-device checklist and production privacy/ad-provider review. Preserve the separation between acknowledged gameplay backups, dashboard summaries and leaderboard projections. For competitive or prize-based rankings, move authoritative economy/reward validation to trusted server logic. Keep this report, release version information, dependency lockfile and backend deployment instructions updated with future changes.


## Privacy implementation update — 6 November 2026

AdvertisingPrivacy and PlayerPrivacyUI now gate ad startup on a local age band and versioned choice. Ages 13–17 can use limited ads; adult personalization is optional. Settings provides Advertising privacy and an account/data deletion request screen with email and website routes. There is no general Disable Ads switch and no additional ad/CMP SDK. SDK inventory is cleared when privacy choices change; a build guard blocks SDK auto-initialization bypass. See [privacy operations](Docs/PRIVACY_OPERATIONS.md) for exact signals, manual fulfillment and remaining regional/device checks.

Updated policy/deletion text and three standalone HTML pages are prepared under Docs/Website. They have not been published to the external legal website. No production account deletion or live advertising verification was performed.


## Cloud-choice presentation fix — 6 November 2026

The fresh-install restore choice now uses the startup overlay priority and highest active UI sorting layer. The home loading overlay yields during that decision, and the account-startup view hides once it hands control to the cloud choice. The prompt waits for existing gameplay operations to finish before building its interactive UI.

A valid remote save that needs a decision after local startup now also opens the choice automatically instead of exposing the action only through Settings. Fresh-install choices are Restore/New Game; existing local progress gets Restore/Keep Device with explicit confirmation and existing owner/write-lock verification. Ordinary updates from an accepted cloud ancestor continue saving automatically. Restoring still stages the backup and asks the player to reopen the game. A fresh-install Android device test remains required after building the updated client.


## Editable UI update — 6 November 2026

Game-owned runtime views now support visual prefab overrides through the independent SweetMerge.UI.Customization assembly. The UI Designer exports visual/layout components without cloning gameplay controllers or button listeners. A shared RuntimeUITheme provides optional global artwork/font overrides; 21 starter visual prefabs are supplied under Assets/_Game/Resources/UI/VisualTemplates. Other registered runtime screens can be captured when displayed. Existing scene/prefab UI stays editable in Unity.

[UI_GUIDE.md](UI_GUIDE.md) lists all registered runtime views and editing instructions; [the serialized UI inventory](Docs/UI_SCENE_INVENTORY.md) gives exact scene/prefab hierarchy/controller paths. Provider-owned sign-in, Android dialogs and actual ad creatives remain outside the game's visual-prefab system.

Validation: full Unity EditMode suite passed 669/669 tests after integration, including capture/binding checks, preservation of button actions/live text and existing game regressions. These are automated checks; custom artwork still needs visual review on target devices.
