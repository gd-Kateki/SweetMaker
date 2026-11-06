# Privacy operations and release checks

Updated 6 November 2026. Uses only the installed Unity LevelPlay/Unity Ads stack.
No AdMob, UMP or other CMP was added.

## Implemented behavior

- Ads wait for an age group and valid, versioned privacy choice. Under-13 and
  unresolved states cannot initialize, load or show ads through SimpleAdManager.
- Ages 13–17 use limited ads: GDPR consent false, CCPA opt-out true, conservative
  COPPA-restricted treatment, and `is_deviceid_optout=true`. Adult limited mode
  uses the same restrictions except COPPA=false. Adult personalized mode requires
  an explicit choice; a teen personalized state is rejected.
- Settings exposes Advertising privacy, not a general remove-ads switch.
- Changing choices destroys loaded ad inventory and applies new SDK signals.
  There is no SDK shutdown API here: withdrawing personalization does not promise
  to stop every existing network operation or erase prior provider data.
- Dismissing the first privacy prompt defers it for the current session, permits
  gameplay, and never creates an ad consent. Settings or an ad offer can reopen it.
- Age/choice stay local and are not included in the cloud save. Policy version
  changes require a fresh choice. Initial unknown states block ads.
- A build guard rejects LevelPlay automatic initialization/Integration Helper,
  which would bypass the flow. Do not add SDK initializer components.
- Settings opens a deletion-request screen, an email composer with the signed-in
  Unity ID when available, and the external deletion page. Sending the email and
  administrative fulfillment are required; no automatic deletion is claimed.

## Backend deletion procedure

Operator checklist, not completed live verification. Prove this workflow with a
dedicated test account before handling real requests.

1. Receive the request at studiosoffcut@gmail.com. Record scope and environment.
   Verify control of the account through support; a public cafe name/player ID
   alone is not proof. Never request passwords or bearer tokens.
2. Ask the requester not to keep playing during fulfillment. Explain permanence,
   local/cloud separation and any justified retention exception.
3. Locate the verified player in the correct UGS project/environment. Record
   necessary identifiers securely before removing account records.
4. Remove that player's scores/metadata from both `total_money_earned` and
   `total_orders_completed`. Do not assume Authentication deletion removes scores.
5. Remove player Cloud Save data: backup envelopes, summary/profile keys and other
   records in scope. Check all applicable access classes.
6. Submit applicable Analytics erasure using correct analytics/installation IDs.
   An Authentication ID alone may not identify every analytics installation.
   Coordinate other provider erasure requests as applicable.
7. Delete the UGS Authentication game account using authorized Dashboard/admin
   operations. Do not delete unrelated Google accounts or other players' records.
8. Verify records/entries are gone and provider requests are completed/tracked.
   Check the active game cannot republish old data under a deleted identity.
9. Confirm the outcome and explain retained exceptions/pending provider processing.
   Securely retain only the necessary fulfillment record.

No real account or production data was deleted during implementation. Do not
claim live verification until the dedicated-account test passes.

## Website publication

Replacement HTML pages under `Docs/Website/` mirror the existing GitHub Pages
paths. Copy them into the offcutstudios-legal repository and publish through its
GitHub Pages process. This Unity project's Git remote is a different repository;
authenticated website publishing access was not available here. No website
changes have been published by this implementation.

Update the home page, app privacy policy and deletion page together. Source text:
`DESSERT_MERGE_CAFE_PRIVACY_POLICY.md` and `DATA_DELETION.md`. Match Play Data safety
and policy URLs to the final publication.

## External verification required

The manual UI and SDK signals are not a certified CMP or legal certification.
Review suitability for actual markets, audience and enabled networks; some
configurations/regions require a compatible consent framework. Do not claim this
implementation meets every regional requirement by itself.

In LevelPlay/Unity Ads verify the 13+ audience, age-appropriate creatives,
restricted/non-personalized delivery, no Advertising ID access in limited mode,
and that enabled networks match the disclosure. Adding another network requires
reviewing its consent/age handling. Flags do not prove actual network behavior.

Device checks: no saved choice; each age band; teen limited rewarded/interstitial
ads; adult limited/personalized; changing choice after ads load; restart/offline/
reconnect; gameplay without a completed choice; deletion email with/without a
mail client; external deletion after uninstall; and administrative fulfillment.
Verify no ad request precedes the choice. Use ad test devices.

References:
- https://docs.unity.com/en-us/grow/levelplay/sdk/unity/regulation-advanced-settings
- https://support.google.com/googleplay/android-developer/answer/13327111


Validation: the full EditMode suite passed 661/661 tests after integration. The final focused run passed 23/23 tests covering privacy dismissal, age transitions, limited/personalized choices, Settings layout and deletion-email escaping. Device and backend checks above remain outstanding.
