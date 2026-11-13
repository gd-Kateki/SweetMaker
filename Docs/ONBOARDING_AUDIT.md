# Onboarding audit

Reviewed: 13 November 2026.

## Intended flow

1. Resolve the analytics privacy choice when no choice is saved.
2. Choose Google Play sign-in or guest play. Returning accounts may restore a cached session.
3. Resolve an existing cloud save before allowing conflicting local progress to upload. A pending restore or cloud-choice decision takes priority over home onboarding. Follow the restart notice when a restore requires it.
4. Once startup and local data are ready, show the tutorial welcome on Home. Starting it enters gameplay.
5. Guide the player through spawning, merging, and completing the tutorial order. Preserve tutorial progress across sessions; completed tutorials do not replay.
6. On returning Home after the tutorial, offer café naming if the profile still needs a name. Keep the permanent-name confirmation.
7. Allow automatic advertising privacy prompts and cash offers after tutorial completion, when no blocking screen is open. Explicit energy-reward requests still use the existing advertising privacy checks.

## Problems found and fixed

| Finding | Change |
| --- | --- |
| Automatic ad/privacy prompts and cash offers could interrupt the first tutorial; a Home interstitial could interrupt its return transition. | Automatic offers now require a ready, completed tutorial and an unobstructed screen. |
| The tutorial welcome card left surrounding Home controls clickable. | Added a raycast-blocking dimmer and a modal input lease. Both are released on dismissal or disable. Stale Start clicks are rejected. |
| Welcome/naming eligibility did not explicitly reject every pending cloud restore/choice state. | Shared onboarding eligibility now prioritizes pending restore and cloud decisions. Naming refreshes when that eligibility changes. |
| The welcome could remain visible alongside another blocking modal. | It yields to other modal owners and returns when they close, if still eligible. |
| Tutorial instructions and highlights could remain visible behind blocking dialogs; instructions could compete with the tutorial recovery card. | Hide normal hints during recovery and blocking dialogs; hide highlights while input is blocked. |
| Cached-session recovery presented two sign-in actions, and account-switch help looked like a direct account switch. | Show one sign-in action for the recovery mode. Use clearer labels: “Retry sign-in,” “How to change account,” and “Try again.” |

## Editing the visuals

Use **Tools → Sweet Maker → UI Library** to open the editable designs. Relevant keys include `StartupWelcome`, `CloudProgressChoice`, `CloudRestoreRestart`, `TutorialWelcome`, `TutorialWelcomeBackdrop`, `TutorialInstruction`, `TutorialRecovery`, `TutorialHighlight`, `CafeNaming`, and the `AdvertisingPrivacy_*` designs.

The new welcome backdrop is an appearance-only prefab at `Assets/_Game/Resources/UI/VisualTemplates/TutorialWelcomeBackdrop.prefab`. Its runtime controller retains input blocking and layout behavior. See `UI_GUIDE.md` for the full inventory.

## Verification and limits

Automated checks cover cloud/startup priority combinations, automatic-ad eligibility combinations, welcome input blocking/release, modal yielding/resumption, and recovery-action visibility. The full EditMode suite also exercises existing startup, restoration, tutorial, profile, and overlay behavior.

Result: **729/729 EditMode tests passed** with the Android build target. Results: `tmp/onboarding-audit-tests.xml`.

This audit reviews code and automated scene/UI behavior. It does not establish a live Android Google Play sign-in, fresh-install cloud restore, native keyboard layout, ad-consent round trip, or every device aspect ratio. Before release, exercise fresh guest play, fresh signed-in play with and without a cloud save, cancelled/offline sign-in, restore/relaunch, and a returning completed-tutorial account on a device. Check the keyboard and small-screen text while naming the café.
