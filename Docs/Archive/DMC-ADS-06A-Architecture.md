# DMC-ADS-06A — shared LevelPlay service (2026-10-31)

## Scope and wiring

`LevelPlayAdService` owns all application LevelPlay initialization, ad objects, load/show commands, readiness, and diagnostics. Initialization, load and display remain explicit; there are no automatic interstitial triggers, preload loops, payouts or save/auth changes.

`AdvertisingConsentProvider` is the production-facing contract. A provider must apply reviewed SDK privacy signals before publishing authorization, fail closed, and publish revocation synchronously. `AdvertisingPrivacyGate` implements that contract solely for the existing Android adult DEV test flow. Release explicitly rejects development-only providers. No production provider or automatic startup is supplied by this milestone: production delivery remains OFF.

The existing Game scene component at fileID 9200000000000200003 is migrated to the new service script GUID. Its serialized app key, units, placements and privacy reference are retained. Both `LevelPlayDevelopmentDebugOverlay` and `RewardedEnergyDevelopmentCoordinator` now consume this service. The old controller script remains an optional DEV-only forwarding facade with no SDK state or initialization call. No scene uses it. The overlay implementation and its service-side creation are Android DEVELOPMENT_BUILD-only. The energy test implementation is compiled out of release so it cannot disable the shared GameObject or alter the release energy button.

## Lifecycle and failures

A single active service owns the SDK; a process-wide latch permits only one native initialization attempt. Repeated buttons and duplicate scene objects cannot initialize it twice. Init errors/ambiguous attempts require an app restart. Successful init does not load or show anything automatically. Ad-load failures allow explicit retry; loaded ads are not redundantly loaded again. Show requires current consent and native readiness. A full-screen show blocks both formats until close/display failure. Exceptions clear relevant pending flags and report diagnostics.

Withdrawal, service disable and destruction invalidate/dispose ad objects and unsubscribe init events. Captured object identities and current consent reject stale callbacks, including callbacks queued during disposal. Destruction handles each native ad independently even if one throws. Reward callbacks remain diagnostics only; unexpected and duplicate callbacks are rejected. Late reward callbacks after close may be observed until the next show request; this is NOT a trusted reward transaction ledger and must not be used for payouts.

Conservative limitation: the service is scene-owned. Leaving/reloading Game after an initialization attempt requires restarting the app for another ad session. This avoids silently reopening a native SDK after losing its consent owner. Missing SDK callbacks stay pending with elapsed-time diagnostics; no timeout is treated as success and there is no blind retry. Persistent lifecycle/recovery and reward transaction correlation belong in later work before production launch.

## Saved configuration verified before and after

- App key: `29245cbbd`
- Interstitial: `4gx9bo96ocyr4hiz`, placement `BP_Interstitial_Android`
- Rewarded: `hg0kom1zfpm0no12`, placement `BP_Rewarded_Android`

No discrepancy: the saved Game scene already contains the corrected rewarded ID (including the `o` before `12`). The former typo from the prior chat is not present in the saved scene.

## Inspection and validation boundaries

Inspected installed LevelPlay 9.6.0 source in Library/PackageCache: init events, rewarded/interstitial constructors, LoadAd, ShowAd, IsAdReady and DestroyAd signatures. SDK auto-initializer requires a Resources LevelPlayMediationSettings asset with EnableIronsourceSDKInitAPI; no such settings asset was found under Assets. No SDK initializer scene component was found in the static scene/prefab scan. Keep SDK auto-init disabled: adding it would bypass this consent boundary.

Android Dev profile saves m_Development: 1 and com.offcutstudios.dessertmergecafe.dev; Release saves m_Development: 0 and com.offcutstudios.dessertmergecafe. Existing AndroidBuildIdentityGuard checks effective profile identity and BuildOptions.Development. Profiles, signing, SDK packages, Gradle files and dashboard settings were not changed here. Several of these files already have local changes; they are pre-existing and must not be reverted.

Only static inspection was performed: source/API review, preprocessor/brace checks, scene GUID/reference/ID checks, scoped baseline diffs and whitespace validation. No Unity import/compile, Unity/Android build, automated tests, device test or commit was run. Working DEV behavior is preserved by design, but requires an approved device regression before it is verified.

## Next milestone

First, approve a DEV regression: adult consent -> initialize -> load/show each format; energy test remains no-payout; duplicate clicks; load/display failure; withdrawal during pending operations; scene re-entry/restart behavior. Separately implement and verify a real production consent provider, including age/region requirements, SDK signals, withdrawal and persisted-choice validity. Only then wire consent-authorized automatic initialization/preloading (06B), with lifecycle/retry policy. Automatic gameplay interstitial triggers and trusted reward payouts remain later milestones.
