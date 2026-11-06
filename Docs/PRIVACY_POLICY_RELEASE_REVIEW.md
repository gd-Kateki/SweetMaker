# Privacy and release declaration review

Reviewed 6 November 2026 against the published OffCut Studios Legal Center,
Dessert Merge Cafe privacy policy, data-deletion page, and this game's source.
This is a technical accuracy review and suggested wording, not legal certification.

## Current conclusion

The published policy is a review draft describing an older implementation. Update
it before relying on it for the current release. The home page and deletion page
also describe online functionality as planned and need matching updates.

## Play Console screen

The screenshot asks for app trader status and an optional Terms of Service URL.
A privacy policy is a separate document. Do not enter the privacy-policy URL as
Terms of Service. The field says "If available", so it can remain blank if there
are no published app terms. Confirm trader status according to the studio's actual
commercial activity; the game includes advertising monetization.

Use the direct app-specific privacy URL in the Privacy Policy field:
https://offcut-studios.github.io/offcutstudios-legal/dessert-merge-cafe/privacy-policy/

## Corrections required

| Existing disclosure | Needed correction |
| --- | --- |
| Completely offline; online services planned/unverified | Describe active Google Play Games/UGS authentication, automatic Cloud Save, Cloud Code and leaderboards |
| Saves stay strictly on the device | Explain local persistence plus account-linked cloud backups |
| Ads only manually triggered adult tests, without rewards | Describe active rewarded energy/cash offers and Home interstitials |
| No leaderboard disclosure | Explain public cafe name, lifetime totals and current rebirth |
| Declining/withdrawing advertising blocks SDK initialization and requests | Current SimpleAdManager initializes on Android automatically and has no advertising consent gate; implement and verify the promised controls or revise the disclosure to actual behavior and satisfy applicable consent requirements |
| Analytics Settings controls described as future | Check the shipped consent controls and document their actual operation |
| Deletion covers cloud and analytics only | Explicitly cover UGS authentication records, backups, summary fields and both leaderboard entries; coordinate provider deletion as applicable |
| Player IDs will become available later | Give instructions that work in the shipped version, including support for people who have already uninstalled |
| Status: Review Draft | Publish a reviewed effective policy with an accurate update date |

Do not treat analytics consent as advertising consent. Do not claim to collect
only the data accessed by custom C# scripts: SDK processing is also in scope.

## Suggested replacement text for the product/data sections

### Game saves and account services

Dessert Merge Cafe stores gameplay progress on your device. When you sign in with
Google Play Games, Google Play Games and Unity Authentication process identifiers
needed to identify your game account. The game automatically backs up eligible
progress to Unity Cloud Save and can restore it after reinstalling or changing
devices. Backups include saved gameplay state, currency and lifetime totals,
upgrades, energy, collection and order state, rebirth progress, cafe name and
tutorial progress. Cloud services also process technical information needed to
operate and secure requests. Deleting local app storage does not itself delete
cloud backups or the game account.

### Public leaderboards

Unity Cloud Code reads your saved progress to update Unity Leaderboards for
lifetime money earned and completed orders. Your cafe name, ranking, relevant
lifetime total and current rebirth can be viewed by other signed-in players.
Use a cafe name you are comfortable displaying publicly and avoid putting personal
information in it. The full saved board and account authentication credentials
are not displayed in leaderboard rows.

### Advertising

The game uses Unity LevelPlay and the Unity Ads network to display advertising.
Rewarded ads offer additional energy or a cash bonus after the reward condition
is met. Interstitial ads may appear when returning home. Advertising providers
may process advertising/device identifiers, including Android Advertising ID when
available, IP address, device and network information, ad interactions and
diagnostic information for ad delivery, measurement, fraud prevention and other
purposes described in their applicable privacy disclosures. Confirm the precise
categories, purposes, sharing and retention against the enabled SDKs and provider
configuration before publishing this section.

Advertising controls and regional consent wording must describe controls actually
implemented in the released app. Do not publish a promise that refusing consent
prevents SDK initialization until that behavior has been implemented and tested.

## Deletion implementation gap

No account-deletion action or link was found in the inspected game scripts.
The external email request page is useful, but the app also needs a discoverable
way to initiate a game-account deletion request if it permits account creation,
including account creation through sign-in. Google permits an in-app link to the
external deletion resource; an entirely automated client deletion API is not
required. Add the link in account Settings and verify the operational request
workflow. Clear local data/sign-out are not substitutes for deleting server data.

Verify ownership using more than knowledge of a public identifier before deleting
records. Ensure retained local progress does not silently recreate deleted cloud
data without a new, intentional account action. Explain any retained records and
the actual retention/deletion schedule; do not invent a deadline the studio cannot
meet. Deleting the game's account does not delete the player's Google account.

## Decisions needed before final publication

- Confirm target ages, markets and actual age/consent controls; the existing 13+
  statement must match the Play target-audience declaration and implementation.
- Confirm whether personalized ads are enabled, which ad networks are enabled,
  and the appropriate regional advertising consent flow.
- Confirm actual analytics collection and withdrawal behavior in the release.
- Set a workable retention and deletion-response policy and verify staff can
  fulfill requests across all services.
- Match Play Data safety and Advertising ID declarations to the final policy and
  actual SDK behavior. Advertising ID use has been verified in the merged Android
  release manifest.

## References

- Published policy: https://offcut-studios.github.io/offcutstudios-legal/dessert-merge-cafe/privacy-policy/
- Published deletion page: https://offcut-studios.github.io/offcutstudios-legal/dessert-merge-cafe/data-deletion/
- Google User Data requirements: https://support.google.com/googleplay/android-developer/answer/10144311
- Google account deletion guidance: https://support.google.com/googleplay/android-developer/answer/13327111

No website or Play Console changes were published during this review.
