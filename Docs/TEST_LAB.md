# Test Lab — production and development testing

The Game scene now has a **TEST LAB** button near the upper-right corner, below
the top HUD area. It opens a safe-area-aware, scrollable testing panel with four
tabs, a live wallet/energy/rebirth summary and persistent action feedback.
The panel uses its own 720 × 1280 UI scaling and the existing EventSystem.

## Production testing switch

`Assets/_Game/Resources/DeveloperTestingSettings.asset` contains
**Enable Production Cheat Panel**. It is currently **enabled**, as requested.
This admits the panel and commands in non-development Android builds. Editor
and normal Android development builds remain supported.

Menus:

- Tools → Sweet Maker → Testing → Enable Production Cheat Panel
- Tools → Sweet Maker → Testing → Disable Production Cheat Panel

The switch is a build-time asset setting, not a player preference. Rebuild the
app after changing it. Missing/disabled settings prevent the panel from being
installed in an ordinary release build and reject its mutation commands.

Production testing uses the existing **release save and UGS production account**.
It does not secretly switch environments or redirect saves. Changes can therefore
reach cloud backups and leaderboards through the normal sync flow. The panel
identifies production testing in its header. Use the intended QA accounts.

## Actions

| Tab | Tools |
| --- | --- |
| Economy | Wallet +1K/+100K/+1M, custom positive cash amount; energy 0/50/full; current lifetime statistics |
| Economy — leaderboard totals | Earn +$1K adds wallet and lifetime earnings; Orders +1 increments the lifetime counter for testing, without fulfilling a current board order |
| Progress | Cafe progression display, rebirth selection/apply, dessert tier selection and placement |
| Board | Refresh customer orders, clear board desserts, isolated development-profile reset |
| Services | Save Now, Check Cloud, Copy Report, normal energy rewarded-ad offer, live readiness/save/cloud/ad/privacy diagnostics |

Wallet-only cash cheats intentionally do not count as lifetime gameplay earnings.
Use **Earn +$1K** to test the money leaderboard. Test totals follow normal saving
and synchronization delays; leaderboard publication is not an instant direct write.

Set energy to 0 or 50 before testing a reward; energy still caps at 100.
The energy-ad test opens the ordinary offer and privacy flow. It does not simulate
an SDK reward or bypass completion. Cloud retry closes the panel so a real cloud
decision can become visible. Check the result in Settings or reopen Test Lab.
Copied reports exclude authentication/service tokens.

## Interaction and safety behavior

- Opening the panel blocks normal gameplay input and waits for a safe boundary.
- Commands remain unavailable until the active board and save session are verified.
- Clear board and development reset require a second confirmation; switching tabs,
  closing the panel or running another action cancels pending confirmations.
- Full profile reset stays disabled in production and rejects the call before
  mutating state. It is designed for isolated development saves.
- Commands retain overflow checks, restoration readiness and save-path validation.
- Save failures are distinguished from actions that applied and saved successfully.
- Closing/Escape and scene changes release the modal input lease.
- Diagnostics refresh twice per second while the panel is open.

## Visual editing

New prefabs:

- `Assets/_Game/Resources/UI/VisualTemplates/DeveloperCheatsV2.prefab`
- `Assets/_Game/Resources/UI/VisualTemplates/DeveloperButtonV2.prefab`

Use the existing UI Designer workflow to change artwork, fonts and colors. The
new keys avoid applying an older panel layout to the redesigned hierarchy.
Tools → Sweet Maker → Testing → Create Test Lab Visual Templates creates missing
defaults without overwriting customized designs. Runtime values and button
actions remain controlled by the panel.

## Before wider distribution

Disable production testing and create a new release bundle when the testing
period is finished. The signed release build helper records whether production
cheats were enabled in its build-info file. Verify the panel on a Play-installed
release build; automated Editor tests do not replace the device test.


## Validation

678/678 Unity EditMode tests passed after integration. Test Lab geometry was checked at three viewport sizes; access gating, input-lease cleanup and confirmation cancellation are covered. Rendered Economy/Services previews were reviewed. A signed Android release build and live service/ad checks were not performed in this change.
