# Unity Ads + LevelPlay-only Android test integration

Implemented 2026-10-30. No compilation, resolver run, builds, tests or commits performed.
The prior Editor compile result predates this replacement.

## What changed

- Removed AndroidUmpConsent.cs and AdvertisingUmpDependencies.xml, including their .meta files.
- Replaced the UMP-dependent AdvertisingPrivacyGate with developer-managed, explicit consent for controlled adult test sessions. Its existing .meta/GUID and public review/withdraw entry points remain.
- Preserved LevelPlayTestAdsController byte-for-byte: app key 29245cbbd, manual initialize/load/show, no gameplay payout, no automatic interstitials.
- No scene/prefab, gameplay, analytics consent, Save V2, authentication, signing or build-profile changes.
- No AdMob adapter or application-ID metadata was found in the scanned source configuration. UMP was not present in resolved Gradle or resolver dependency state, so those files were not changed.
- Keep play-services-ads-identifier: it is a LevelPlay dependency, not the Google Mobile Ads SDK. Keep the SDK's network catalog entries: listing AdMob there does not install it.

## Compatible consent path and limitations

Unity documents developer consent and mediation consent sharing. The installed LevelPlay 9.6.0 C# API exposes SetGDPRConsent, SetCCPA and SetCOPPA. An explicit acceptance sends GDPR=true, sale/share opt-out=true, and COPPA=false before manual initialization. The last value is restricted to the resolved adult test cohort; it is not a claim that COPPA means under 18.

This is a custom developer-consent flow, not a certified CMP and not automatic worldwide privacy compliance. It does not rely on Unity's built-in ad prompt, which is unsuitable as a pre-initialization mediation consent gate. It does not invent TCF strings or claim anonymous/non-personalized ads. Refusal means NO ADS.

Unknown age and every under-18 band stay blocked without initializing the ad SDK. Selecting 18+ is self-declaration, NOT age proof. The app's intended 13–17 audience remains supported for gameplay, but teen ad serving is intentionally unresolved and disabled. Do not enable this test path for public distribution or treat a checkbox as resolving missing age/consent requirements.

Every process requires a fresh age choice and explicit consent. A withdrawal is persisted using the existing separate advertising key. No adult age, birthday, or positive consent grant is persisted or reused. A new explicit acceptance can clear prior withdrawal only in a fresh eligible session. Once permission has been exposed, changing age, reopening choices, disabling the gate, or withdrawing blocks further ads until a process restart. Withdrawing signals refusal to LevelPlay after a grant; the controller destroys loaded ads. This cannot undo prior processing, uninitialize the SDK, or necessarily dismiss an ad already showing.

The gate is false in Editor, non-Android platforms and non-development builds, including when its public Accept method is invoked. Configuration defaults are blocked; old cmpDashboardConfigured values do not migrate into approval.

## Exact remaining actions

1. Supply the real HTTPS app privacy-policy URL and a reviewed, versioned in-app advertising disclosure. Cover the publisher/contact, Unity Ads and LevelPlay/ironSource, actual data collected/accessed (including applicable device identifiers), purposes including any personalized advertising, sharing/retention, optional refusal, withdrawal, and privacy/data rights. A generic "accept ads" notice is insufficient. No placeholder notice is supplied as if legally complete.
2. Resolve age and regional consent requirements for the actual controlled adult testers. Until resolved, leave Adult Test Privacy Requirements Resolved OFF. This implementation does not establish age assurance, parental permission, jurisdiction, or all regional privacy signals. If the test region requires additional signals or a CMP, keep the gate closed until those are implemented. No teen advertising is authorized by an adult's acceptance.
3. Reuse the existing LevelPlay app/test device and Unity Ads configuration. Confirm Unity Ads is the sole enabled demand network for both ad units, the device is registered for test ads, and Unity Ads test mode is enabled. Disable any other demand source if present, including ironSource Ads demand; LevelPlay itself remains the mediator. Do not add an AdMob app or any CMP dashboard for this custom path.
4. Wire the Inspector as below. No automatic scene edits were made.
5. After separate approval, let Unity compile/import and run Android Resolver > Resolve if needed to reconcile dependencies. Then approve an Android Development Build/device test. Verify blocked default/minor/unknown/refusal paths, explicit adult acceptance, manual test ads, withdrawal/restart and actual signal propagation. Source inspection is not runtime verification.

Existing versions were preserved: Unity package 9.6.0; native LevelPlay XML/Gradle 9.7.0; Android Unity Ads adapter 5.15.0. Do not silently upgrade or downgrade these as part of privacy cleanup. Native dependency compatibility and actual test-ad delivery remain unverified.

## Unity Inspector and buttons

Use one development-only GameObject with one AdvertisingPrivacyGate and the existing LevelPlayTestAdsController.

AdvertisingPrivacyGate:
- Show Development Privacy Panel: ON for the provided scrollable age/consent panel.
- Privacy Policy Url: real published HTTPS app privacy-policy URL.
- Advertising Disclosure: reviewed full in-app notice, not an empty string.
- Disclosure Version: revision identifying that notice, e.g. your actual review date/version.
- Adult Test Privacy Requirements Resolved: OFF until actions 1–2 are genuinely resolved for the testers.
- Test Device Configured: ON only after action 3 is confirmed.

LevelPlayTestAdsController:
- Privacy Gate: drag the same object's AdvertisingPrivacyGate component into this field.
- App Key: 29245cbbd.
- Interstitial Ad Unit Id: copy the real LevelPlay interstitial ad-unit ID.
- Rewarded Ad Unit Id: copy the real LevelPlay rewarded ad-unit ID.
- Placement names: leave empty for default placement or use exact existing LevelPlay placement names. Do not substitute placement names or Unity Game IDs for ad-unit IDs.

Five separate development UI Button On Click events, each targeting the controller:
1. LevelPlayTestAdsController.Initialize()
2. LevelPlayTestAdsController.LoadInterstitial()
3. LevelPlayTestAdsController.ShowInterstitial()
4. LevelPlayTestAdsController.LoadRewarded()
5. LevelPlayTestAdsController.ShowRewarded()

The gate supplies its own age/review/accept/decline/withdraw GUI. If using custom UI instead, SelectAgeBand(int) values are Unknown=0, Under13=1, Age13To15=2, Age16To17=3, Adult18Plus=4. Bind Review to GatherAdvertisingPrivacy(), show the full configured disclosure/version and policy link, then bind separate equally accessible Accept/Decline buttons to AcceptAdvertisingPrivacy()/DeclineAdvertisingPrivacy(). Bind policy to OpenAdvertisingPrivacyPolicy() and withdrawal to WithdrawAdvertisingPrivacy(). Do not bind acceptance to the age button or Initialize button.

Approved device-test sequence: choose age -> review -> explicit acceptance -> Initialize -> wait for init success -> Load desired format -> wait for loaded callback -> Show. No rewards are paid. Editor cannot open the ad gate.

## Official references

- [LevelPlay privacy APIs and supported consent sharing](https://docs.unity.com/en-us/grow/levelplay/sdk/unity/regulation-advanced-settings)
- [Unity Ads TCF/non-TCF mediation consent](https://docs.unity.com/en-us/ads-android/4.18.0/privacy/gdpr/tcf-and-non-tcf-consent)
- [Unity Ads developer-consent responsibilities](https://docs.unity.com/en-us/ads-unity/4.21.0/privacy/developer-consent/solution/intro-to-dev-consent)

These document API compatibility and publisher responsibilities, not verification of this app's disclosures or installed Android runtime.
