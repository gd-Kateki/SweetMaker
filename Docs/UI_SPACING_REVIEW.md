# UI spacing review

Reviewed Home, gameplay/HUD, collection, My CafÃ©, Settings (both scroll ends), Upgrades, leaderboards, naming, Prestige/recycle, rewarded offers, startup/sign-in, cloud decisions/recovery, age/privacy/deletion, analytics, tutorials, order/completion dialogs and developer/log screens.

## Adjustments

- Common inner gutters for privacy titles, body text and action buttons.
- More compact age/teen/under-13 prompts with consistent action spacing. The longer adult and deletion disclosures retain their needed reading area.
- Analytics title, descriptions, policy button, two-column actions and close icon now have separate padded regions.
- Compact centered startup/restart messages with consistent action clearance.
- Order details use a non-interactive dim backdrop. Existing input blocking remains unchanged.

Existing artwork, control shapes, custom energy + visuals, My CafÃ©'s flat statistics, callbacks, consent choices, and modal gates are preserved. Settings account/status areas and scrollable lists retain room for live/error states; partial rows at a scroll boundary are intentional.

All layouts remain editable in the existing visual-template prefabs and scene hierarchy. Editor previews and geometric checks cover portrait and tall layouts; they do not replace an Android device walkthrough.

## Verification

All 782 EditMode checks passed after the final adjustments. New checks cover dialog-action bounds and overlaps on 720×1280 and 720×1600 layouts, equal age-choice spacing, and a canvas-filling order backdrop with its separate input blocker preserved.
