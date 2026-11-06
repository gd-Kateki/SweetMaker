# Cafe leaderboards

The bakery has a Leaderboards button with Money earned and Orders completed tabs.
Each page shows 25 entries: rank, cafe name, lifetime total, and current rebirth.
Google Play sign-in is required. Guest progress is not published.

## One-time UGS setup

Use Unity's Services > Deployment window, starting in **development**. Deploy in this
order, test on Android, then repeat in **production**:

1. The two `.lb` assets below.
2. `SyncCafeLeaderboards.js` (publish the script). Its only required String parameter
   is `checksum`; the Deployment importer reads this from `module.exports.params`.
3. `leaderboard-writes.ac`. Merge these two deny statements with any existing project
   access policy; do not remove unrelated statements. This denies direct Player writes
   to these two boards while allowing Cloud Code's service token to publish.
4. Install a new build with the Cloud Code client integration. An older build that
   submits directly cannot update these boards after the policy is enabled.

Dashboard leaderboard settings, if creating the boards manually:

| ID | Display name | Sort | Update strategy |
| --- | --- | --- | --- |
| total_money_earned | Total Money Earned | Descending | Latest Score |
| total_orders_completed | Total Orders Completed | Descending | Latest Score |

Use all-time leaderboards with no scheduled resets, buckets, or tiers.
Latest Score accepts the complete lifetime total and refreshes cafe/rebirth metadata
even when a score stays the same. Do not select Total Score: retries would add the
whole lifetime total again. Both environments must have the same IDs.

No remote deployment is performed by adding these files to the project. This client
intentionally has no fallback to direct score writes if Cloud Code is unavailable.
Do not release until the script and policy have been tested in the live environment.

## Sync and verification

### Diagnosing a deployed script that does not publish scores

An invocation log showing only `Script parameters` and `Authenticated within the
following context` does not prove a score was written. Those statements are not
in this repository's script. Check the **published** production script against
`SyncCafeLeaderboards.js`, especially when the Dashboard script was first created
manually: the starter template does not synchronize leaderboards. Replace the
entire script with this file, configure required String parameter `checksum`, and
publish it (saving a draft alone is insufficient). The expected response is
`{ uploaded: true, checksum: ... }` after both writes complete.

Do not log the complete Cloud Code context: it contains access and service tokens.
For troubleshooting, share the error message with credentials removed. A working
Orders read and a failing Money read still require separate investigation of the
Money board; a script publishing issue alone does not explain every read failure.

An acknowledged, owned cloud backup authorizes publication. The existing sync
session provides account checks, one request at a time, unchanged-snapshot suppression,
and a 30-second minimum upload interval. Leaderboard failures retry independently of
Cloud Save. The client sends only the acknowledged backup checksum to Cloud Code.
The script determines the player and environment from its authenticated context,
loads that player's saved backup, validates the owner/schema/totals, and derives both
scores and metadata from that backup. Client-provided scores, names, IDs, and rebirth
values are not used. Both submissions use the same backup snapshot.

Failed uploads back off at 30, 60, 120, 240, then 300 seconds. Switching accounts
resets the retry delay. Reads coalesce overlapping requests and cache up to eight
pages for 15 seconds per account. The UI recovers from a request taking over 20 seconds,
ignores late responses after closing/account changes, and releases modal input on disable.

After deploying, sign in on Android, finish naming/tutorial, earn money and complete
an order, then allow a successful backup and up to 30 seconds for publication.
Open both tabs and verify the totals, name, and rebirth. Verify a later rebirth/name
change updates metadata, and another account cannot see the previous player's local
data as its own. Verify pagination, close/reopen during loading, guest sign-in prompt,
and offline retry. Refresh has a five-second cooldown; cached pages can be 15 seconds old.

Also verify these launch checks with live service credentials:

- A direct Player-token score write is denied; reading still works.
- Cloud Code can update both boards with its service token.
- Another player's ID or a score supplied as a script parameter cannot affect entries.
- Missing backup, wrong checksum, wrong owner, and negative totals cause no writes.
- A failure on the second board retries absolute totals without double counting.
- Reinstall/restore, switching accounts, and a genuine cloud conflict retain their
  existing protections. Ordinary cloud backup must continue during a leaderboard outage.
- Review concurrent-device behavior: the two board writes are not a transaction,
  and Latest Score submissions are last-write-wins. Leaderboard entries are a display
  projection, never a source of restored gameplay progress.

Local checks: Unity EditMode `CafeLeaderboardsTests` and existing cloud suites;
`node --test Tools/Tests/cafe-leaderboards.test.cjs` for the Cloud Code handler with
mocked UGS transport. These do not replace live policy/SDK/device verification.

UGS scores use double precision. Exact 64-bit totals are included as string metadata
for display; at totals above 2^53, adjacent integers can share a ranking score.
The backup remains client-writable. Server-mediated publication prevents arbitrary
direct score submissions but does **not** prove the saved earnings were legitimately
earned. For prizes or cheat-resistant competitive rankings, migrate reward validation
and lifetime totals to authoritative server logic/protected storage before launch.

References:
- https://docs.unity.com/en-us/leaderboards/get-started
- https://docs.unity.com/en-us/leaderboards/tutorials/unity-sdk/add-new-score
- https://docs.unity.com/en-us/leaderboards/tutorials/unity-sdk/get-score
- https://docs.unity.com/en-us/cloud-code/3.0.0/server-access-control
- https://docs.unity.com/en-us/cloud-code/3.0.0/scripts/how-to-guides/script-structure
