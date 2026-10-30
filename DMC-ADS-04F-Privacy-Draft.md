# Dessert Merge Cafe — Privacy Policy Advertising and Service Update Draft

Draft version: `2026-10-30-draft-1`
Publisher: Offcut Studios
Status: Review draft only. Not published. Not a determination of legal compliance.

## Proposed advertising section

### Advertising

When advertising is available, Dessert Merge Cafe may display ads provided by Unity Ads and mediated by Unity LevelPlay. The current integration does not use Google AdMob or Google UMP.

Unity Ads and LevelPlay may process data such as advertising or device identifiers, IP address, network information, device and app information, approximate location derived from available information, ad request and display information, ad interactions, diagnostic information, and privacy/consent signals. The advertising provider or mediation platform may use this information to provide, measure, secure, and, where lawful and permitted, personalize or limit advertising.

The project itself does not grant any gameplay reward in the current development test integration. Development advertising is test-only, manual, and no gameplay reward is paid. Public advertising behavior and any rewarded economy have not been implemented.

The app is intended for players aged 13 and above. Advertising content should be suitable for a 13+ audience. The app does not use a proven age-validation system. Development advertising is restricted to an explicit adult self-declaration, while ages below 18 remain blocked by the current test gate. Under-18 ad serving is not authorized by the existing implementation. Exclusion of advertisements containing 18+ content requires verification in the Unity Ads dashboard and is pending dashboard verification.

Advertising collection and processing depends on advertising availability, applicable privacy choices, region, device configuration, and provider requirements. Declining advertising stops the advertising integration from initializing and prevents ad loads and shows through the current app gate. Declining or withdrawing advertising does not block normal gameplay.

Advertising privacy choices may be reviewed or withdrawn through the app privacy controls when these controls are available. Withdrawal blocks subsequent app-controlled advertising activity, including future LevelPlay initialization, ad loads, and ad displays. It cannot undo data processing that has already occurred or guarantee that an advertisement already displayed or being displayed will stop immediately.

For details about Unity's player/app-user privacy practices, see Unity's Privacy Policy and its ads and player privacy documentation. Also review the full Dessert Merge Cafe privacy policy at the Publisher Privacy Policy URL.

## Proposed advertising rights and withdrawal section

Depending on your location, you may have rights to access, correct, delete, restrict, object to, or obtain information about portability of personal information, and to appeal or opt out of sale or sharing where applicable. Submit privacy requests to the Publisher using the contact information in the published policy.

Do not state a retention period, response deadline, legal basis, certification, or legal guarantee unless it has been confirmed by the Publisher and supported by the applicable service and provider documentation.

## Preserve existing service information

The following draft language should be reviewed against the project's existing published policy and actual deployments.

### Google Play Games

The intended architecture is mandatory online authentication through Google Play Games and Unity Authentication for authenticated game features. This means that, when implemented, players would need a verified online sign-in session rather than optional offline progression.

Google Play Games sign-in and Unity Authentication integration currently exists in the project code. The implementation includes manual sign-in, cached-session restoration, Google Play Games status presentation, and Unity Authentication. It is implemented in the account settings control, but a startup-wide mandatory authentication gate has not been verified. Until mandatory startup enforcement and its gameplay behavior are verified, the policy draft should not claim that all players or gameplay are currently required to be online or that offline play is unavailable.

When Google Play Games or Unity Authentication is used, Google and Unity may process account, profile, authentication, and session data necessary to operate those services. Exact fields and retention periods are service-dependent and must be verified for the final deployed configuration. The current implementation does not establish a verified cloud save or synchronized backend; progress remains represented and saved through the project, while cloud functionality is separate and should not be claimed as implemented unless verified.

Firebase cloud functionality is planned rather than implemented. No Firebase package, application configuration, or source integration was verified in the inspected project files. The policy draft should preserve the distinction: Google Play Games and Unity Authentication are implemented services, while Firebase is not a current data processor.

### Unity Analytics

Unity Analytics is a separate optional service controlled by the app's Analytics consent prompt. When granted, the app may initialize Unity Services and may process usage, performance, device, installation, IP address, and session event information. Players can change Analytics consent in Settings.

Analytics consent is separate from advertising consent. Advertising consent must not be represented as Analytics consent and Analytics consent must not be represented as advertising consent.

### Local game data

The app stores game progress and preferences locally using device application storage. Development builds use an isolated development save directory. Do not add a claim that local saves are encrypted, cloud-backed, deleted automatically, retained for a fixed period, or transferred to another service unless verified.

### Firebase

Firebase cloud functionality is planned, but no Firebase package, application configuration, or source integration was verified in the inspected project files. The policy draft should distinguish current implemented services from this planned cloud functionality and should not include Firebase as a current processor unless a future implementation audit confirms one.

## Draft in-game advertising disclosure

Use this text as the proposed value of `AdvertisingPrivacyGate.advertisingDisclosure` after legal/product review:

> Dessert Merge Cafe, published by Offcut Studios, uses Unity Ads through Unity LevelPlay to display advertisements.
>
> When advertisements are requested or displayed, Unity Ads and LevelPlay may process information such as device or advertising identifiers, IP address, device and network information, approximate location, advertisement interactions, diagnostic information, and privacy choices.
>
> This information may be used to deliver, measure, secure, and, where permitted, personalize advertisements.
>
> The app is intended for players aged 13 and above. Advertising excluding 18+ content is pending Unity Ads dashboard verification.
>
> You can accept or decline advertising. Declining advertising does not prevent you from playing Dessert Merge Cafe.
>
> If you accept, you can withdraw your choice later. Withdrawal prevents subsequent advertising requests and displays controlled by the app, but cannot undo previous data processing or guarantee that an advertisement already showing will stop immediately.
>
> During development testing, advertisements are available only in controlled adult test sessions. No gameplay rewards are provided for watching test advertisements.
>
> Full Privacy Policy:
> [https://offcut-studios.github.io/offcutstudios-legal/dessert-merge-cafe/privacy-policy/](https://offcut-studios.github.io/offcutstudios-legal/dessert-merge-cafe/privacy-policy/)

### Disclosure version

Proposed identifier:
`DMC-ADS-DISCLOSURE-2026-10-30-DRAFT-1`

Do not enter this disclosure or version into the Inspector until reviewed and approved.

## Unsupported or unverified claims

The following should not appear in the published policy until independently verified:

- Exact advertising data categories collected by a specific SDK/network version.
- Advertising data retention periods.
- Whether an advertising identifier is always available or always used.
- Whether advertising is personalized, anonymous, or non-personalized in a particular region or for a particular user.
- Exact Unity Ads/LevelPlay server locations.
- App or provider data-sale certifications.
- Automatic GDPR, CCPA, COPPA, child-directed, or privacy-law compliance.
- A verified legal basis for advertising consent in every region.
- That UMP, a CMP, Google UMP Consent Form, or Google consent strings are installed or transmitted.
- That analytics consent is advertising consent or that advertising consent is analytics consent.
- That Google Play Games data is backed up to a cloud save system.
- That Firebase processes data in the implemented integration. Any Firebase functionality is planned unless separately verified.
- Any fixed privacy-request response period.
- Any claim that a withdrawal deletes previously processed data.

## Remaining actions before controlled Android advertising tests

1. Obtain legal/product review of the draft policy and disclosure.
2. Publish the final policy at the existing HTTPS privacy-policy URL.
3. Add a real contact and postal-email/privacy-request channel if required.
4. Confirm the actual Unity Ads data practices applicable to the installed LevelPlay adapter and dashboard configuration.
5. Confirm regional consent requirements, CMP needs, and tester eligibility.
6. Confirm that Unity Ads is the only enabled demand network and that test devices/ad units are configured.
7. Supply verified LevelPlay interstitial and rewarded ad-unit IDs.
8. Enter the approved disclosure and version into the gate Inspector.
9. Keep Adult Test Privacy Requirements Resolved and Test Device Configured off until separately approved.
