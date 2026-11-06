# Google Play internal testing

Use the Android Release profile, not Android Dev. Internal testing distributes the
release application through Google Play and uses the UGS **production** environment.

## Before building

- Use an Android version code greater than any code already uploaded to Play Console.
- Package: `com.offcutstudios.dessertmergecafe`; target API 36; minimum API 29;
  ARM64 and IL2CPP; development/profiler/script debugging disabled; signed AAB.
- Publish `SyncCafeLeaderboards` in production and deploy both leaderboard
  definitions and the access policy. Follow `Assets/_Game/Leaderboards/README.md`.
  Publishing in development does not publish in production.
- In UGS Authentication, verify the production Google Play Games provider uses the
  production Web OAuth client configured in `GooglePlayGamesWebClientResolver`.
- In Play Games Services, the Android credential must match the release package
  and **Google Play app-signing certificate SHA-1**. The upload-key certificate
  alone is not sufficient for apps installed from Play.
- Add testers to the internal track and authorize them in Play Games Services
  (tester emails or the internal release track). Verify the PGS configuration is
  available to those accounts.
- Verify LevelPlay's app/ad-unit settings and Unity Ads adapter are enabled for
  this release package. Register QA devices as test devices in the ad dashboard.

## Build and inspect

Enter signing passwords in Unity's Android Publishing Settings; keep them out of
source files and chat. Select **Tools > Build Android Release Bundle**.
The output path is written to `tmp/latest-release-build.txt`; progress/failure is
written to `tmp/release-build-status.txt`. The build folder includes `build-info.txt`.

Before uploading, run `Tools/verify_android_release.py` with the AAB, Unity's JDK,
the project's pinned bundletool 1.18.3, and the expected version code. It checks
bundle validity, package/version, target SDK, release manifest, JAR signature,
ARM64 libraries and 16 KB alignment. It writes a `.verification.json` receipt.
Passing these checks does not verify UGS/Play credentials or device behavior.

## Upload and test

1. Play Console > Test and release > Testing > Internal testing > Create new release.
2. Upload the new AAB, resolve Play's reported issues, add release notes, and roll
   out to internal testers. Distribute the opt-in link to the chosen testers.
3. Install via the Play opt-in link on a physical Android device.
4. Verify fresh Google sign-in, cafe naming/tutorial, automatic cloud backup, and
   subsequent money/order changes uploading without a false conflict.
5. Verify both leaderboards in production show the correct cafe, lifetime total,
   and current rebirth after a successful backup and the sync interval.
6. Verify Home interstitial timing, energy reward, dynamic cash reward, and no
   duplicate rewards. Use ad test devices. Confirm no DEV/log-console UI appears.
7. After confirming a successful cloud backup, verify reinstall restores the
   correct account and offers Restore/New Game. Exercise offline/reconnect and
   account switching with dedicated test accounts.

Release notes suggestion: "Adds cafe leaderboards for lifetime earnings and orders,
automatic cloud-save fixes, and rewarded/interstitial ads."

## Known release-validation limits

The project cannot prove dashboard settings or Play signing credentials from local
files. Cloud Code/policy deployment, real sign-in, ad delivery, device rendering,
and restore behavior must pass in the internal track before wider release.
Lifetime totals are still client-managed; the leaderboard is not cheat-proof.

References:
- https://developer.android.com/studio/publish/upload-bundle
- https://support.google.com/googleplay/android-developer/answer/9845334
- https://developer.android.com/games/pgs/console/setup
- https://developer.android.com/guide/practices/page-sizes
