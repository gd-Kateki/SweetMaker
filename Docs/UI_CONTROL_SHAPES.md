# UI control shape pass

Checked all visual templates, UI prefabs, and the MainBakery/Game scenes.

Updated 118 control images across 19 prefab assets plus the two scenes. Counts include shared instances.

- Complete rounded caps now sit inside fixed nine-slice borders, instead of stretching with the center.
- Ordinary action buttons use smaller rendered corners. Settings service buttons use the existing gold button artwork rather than a stretched title plaque.
- Slider tracks retain their full interactive bounds and values. Circular handles, close icons, navigation artwork and custom energy + designs are preserved.
- No control listeners, saved values, modal gates or gameplay commands were replaced.

Edit the saved scene/prefab Image settings to customize these shapes. This tool never runs automatically.

## Verification

Android-target compilation succeeded. All 769 EditMode checks passed, including track-cap coverage and compact action-corner checks. Settings, Upgrades, tutorial, naming, privacy/cloud and other shared-control previews were rendered for inspection. No Android device playtest was performed.
