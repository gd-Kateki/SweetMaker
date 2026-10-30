using UnityEngine;

namespace SweetMerge.Advertising
{
    [DisallowMultipleComponent]
    public sealed class LevelPlayDevelopmentDebugOverlay : MonoBehaviour
    {
#if UNITY_ANDROID && DEVELOPMENT_BUILD && !UNITY_EDITOR
        private const float TouchHeight = 56f;
        private GUISkin overlaySkin;
        private static LevelPlayDevelopmentDebugOverlay activeInstance;

        private LevelPlayAdService controller;
        private AdvertisingPrivacyGate privacyGate;
        private AutomaticInterstitialScheduler interstitialScheduler;
        private RewardedCoinsCoordinator coinsCoordinator;
        private Vector2 scrollPosition;
        private Vector2 togglePosition = new Vector2(float.NaN, float.NaN);
        private Vector2 toggleDragOffset;
        private bool draggingToggle;
        private bool toggleMoved;
        private bool expanded;

        private void OnEnable()
        {
            if (activeInstance != null && activeInstance != this)
            {
                Destroy(this);
                return;
            }

            activeInstance = this;
            RefreshReferences();
        }

        private void OnDisable()
        {
            if (activeInstance == this)
                activeInstance = null;
        }

        private void OnDestroy()
        {
            if (overlaySkin != null)
                Destroy(overlaySkin);
            if (activeInstance == this)
                activeInstance = null;
        }

        private void Update()
        {
            if (controller == null || privacyGate == null)
                RefreshReferences();
        }

        private void RefreshReferences()
        {
            if (controller == null)
                controller = GetComponent<LevelPlayAdService>();
            if (privacyGate == null)
                privacyGate = FindAnyObjectByType<AdvertisingPrivacyGate>();
            if (interstitialScheduler == null)
                interstitialScheduler = AutomaticInterstitialScheduler.Instance;
            if (coinsCoordinator == null)
                coinsCoordinator = FindAnyObjectByType<RewardedCoinsCoordinator>();
        }

        private void OnGUI()
        {
            if (activeInstance != this)
                return;
            if (controller == null || privacyGate == null)
                RefreshReferences();

            Rect pixels = Screen.safeArea;
            if (pixels.width <= 0f || pixels.height <= 0f)
                return;

            // A 400-unit short edge keeps text/touch sizes consistent across pixel densities.
            // Use the short edge so rotating the phone does not make the UI enormous.
            float scale = Mathf.Min(pixels.width, pixels.height) / 400f;
            Rect safe = new Rect(pixels.x / scale, (Screen.height - pixels.yMax) / scale,
                pixels.width / scale, pixels.height / scale);
            Matrix4x4 previousMatrix = GUI.matrix;
            GUISkin previousSkin = GUI.skin;
            bool previousEnabled = GUI.enabled;
            Color previousColor = GUI.color;
            Color previousBackground = GUI.backgroundColor;
            Color previousContent = GUI.contentColor;
            try
            {
                EnsureStyles();
                GUI.matrix = Matrix4x4.Scale(new Vector3(scale, scale, 1f));
                GUI.skin = overlaySkin;
                GUI.color = GUI.backgroundColor = GUI.contentColor = Color.white;

                GUI.enabled = true;
                // Keep the compact controls away from the top HUD; the Force Ads tab is draggable.
                float tabWidth = Mathf.Max(92f, (safe.width - 24f) / 2f);
                float tabsWidth = tabWidth * 2f + 8f;
                if (float.IsNaN(togglePosition.x))
                    togglePosition = new Vector2(safe.x + 8f, safe.y + safe.height - TouchHeight - 8f);
                togglePosition = ClampTogglePosition(togglePosition, safe, tabsWidth);
                Rect privacyTab = new Rect(togglePosition.x, togglePosition.y, tabWidth, TouchHeight);
                Rect forceTab = new Rect(togglePosition.x + tabWidth + 8f, togglePosition.y, tabWidth, TouchHeight);
                HandleToggleDrag(forceTab, safe, tabsWidth);
                if (GUI.Button(privacyTab, "Privacy (DEV)"))
                {
                    expanded = false;
                    if (privacyGate != null) privacyGate.OpenDevelopmentPrivacyPanel();
                    GUIUtility.ExitGUI();
                }
                if (GUI.Button(forceTab, "Force Ads (DEV)"))
                {
                    if (privacyGate != null) privacyGate.CloseDevelopmentPrivacyPanel();
                    expanded = true;
                    GUIUtility.ExitGUI();
                }
                if (!expanded || (privacyGate != null && privacyGate.DevelopmentPrivacyHasPriority))
                    return;

                float panelWidth = Mathf.Min(safe.width - 16f, 300f);
                float panelBottom = togglePosition.y - 8f;
                float panelTop = Mathf.Max(safe.y + 8f, panelBottom - Mathf.Min(safe.height - 88f, 420f));
                Rect panel = new Rect(safe.x + 8f, panelTop, panelWidth, panelBottom - panelTop);
                GUI.color = new Color(0.07f, 0.08f, 0.10f, 1f);
                GUI.DrawTexture(panel, Texture2D.whiteTexture);
                GUI.color = Color.white;
                GUILayout.BeginArea(panel, overlaySkin.box);
                GUILayout.Label("Force Ads / Android DEV", overlaySkin.box);
                if (GUILayout.Button("Collapse", GUILayout.MinHeight(TouchHeight)))
                {
                    expanded = false;
                    GUIUtility.ExitGUI();
                }
                GUILayout.Space(8f);

                // The header stays visible; all variable-height text lives in the scroll view.
                scrollPosition = GUILayout.BeginScrollView(scrollPosition, false, true);
                GUILayout.BeginVertical(GUILayout.ExpandWidth(true));
                GUILayout.Label("Manual SDK test controls. Consent and SDK readiness are required. No gameplay rewards.");
                DrawSdkSection();
                DrawInterstitialSection();
                DrawRewardedSection();
                DrawPrivacySection();
                DrawAdvertisingTimerSection();
                DrawDiagnosticsSection();
                GUILayout.EndVertical();
                GUILayout.EndScrollView();
                GUILayout.EndArea();
            }
            finally
            {
                GUI.matrix = previousMatrix;
                GUI.skin = previousSkin;
                GUI.enabled = previousEnabled;
                GUI.color = previousColor;
                GUI.backgroundColor = previousBackground;
                GUI.contentColor = previousContent;
            }
        }

        private void EnsureStyles()
        {
            if (overlaySkin != null)
                return;

            // Clone the skin so other IMGUI users keep their own fonts and control sizes.
            overlaySkin = Instantiate(GUI.skin);
            overlaySkin.label.fontSize = 14;
            overlaySkin.label.wordWrap = true;
            overlaySkin.label.richText = false;
            overlaySkin.label.stretchWidth = true;
            overlaySkin.label.normal.textColor = Color.white;
            overlaySkin.label.margin = new RectOffset(0, 0, 4, 8);
            overlaySkin.box.fontSize = 17;
            overlaySkin.box.fontStyle = FontStyle.Bold;
            overlaySkin.box.wordWrap = true;
            overlaySkin.box.normal.textColor = Color.white;
            overlaySkin.box.padding = new RectOffset(12, 12, 12, 12);
            overlaySkin.button.fontSize = 16;
            overlaySkin.button.wordWrap = true;
            overlaySkin.button.fixedHeight = 0f;
            overlaySkin.button.padding = new RectOffset(8, 8, 12, 12);
            overlaySkin.button.margin = new RectOffset(0, 0, 4, 8);
            overlaySkin.verticalScrollbar.fixedWidth = 40f;
            overlaySkin.verticalScrollbarThumb.fixedWidth = 40f;
            overlaySkin.verticalScrollbarThumb.fixedHeight = 0f;
            overlaySkin.verticalScrollbarThumb.padding = new RectOffset(0, 0, 24, 24);
            overlaySkin.verticalScrollbarUpButton.fixedWidth = 40f;
            overlaySkin.verticalScrollbarUpButton.fixedHeight = 40f;
            overlaySkin.verticalScrollbarDownButton.fixedWidth = 40f;
            overlaySkin.verticalScrollbarDownButton.fixedHeight = 40f;
        }

        private static Vector2 ClampTogglePosition(Vector2 position, Rect safe, float width)
        {
            return new Vector2(
                Mathf.Clamp(position.x, safe.x + 4f, safe.xMax - width - 4f),
                Mathf.Clamp(position.y, safe.y + 4f, safe.yMax - TouchHeight - 4f));
        }

        private void HandleToggleDrag(Rect dragRect, Rect safe, float width)
        {
            Event current = Event.current;
            if (current.type == EventType.MouseDown && dragRect.Contains(current.mousePosition))
            {
                draggingToggle = true;
                toggleMoved = false;
                toggleDragOffset = current.mousePosition - togglePosition;
            }
            else if (current.type == EventType.MouseDrag && draggingToggle)
            {
                if ((current.mousePosition - togglePosition - toggleDragOffset).sqrMagnitude > 9f)
                    toggleMoved = true;
                togglePosition = ClampTogglePosition(
                    current.mousePosition - toggleDragOffset, safe, width);
                if (toggleMoved)
                    current.Use();
            }
            else if (current.type == EventType.MouseUp && draggingToggle)
            {
                draggingToggle = false;
                if (toggleMoved)
                    current.Use();
                toggleMoved = false;
            }
        }

        private void DrawSdkSection()
        {
            GUILayout.Label("1 / Initialize", overlaySkin.box);
            GUILayout.Label(privacyGate == null ? "BLOCKED: Privacy gate missing." :
                privacyGate.IsAdvertisingAllowed ? "Privacy: authorized for this session." : "BLOCKED: " + privacyGate.AdvertisingBlockingReason);
            GUILayout.Label(controller != null ? "State: " + controller.InitializationState : "State: Controller missing");
            GUILayout.Label(controller != null
                ? "App Key: " + (string.IsNullOrWhiteSpace(controller.AppKey) ? "(missing)" : controller.AppKey)
                : "App Key: (missing)");
            GUILayout.Label("Initialization starts automatically after valid advertising consent.");
        }

        private void DrawPrivacySection()
        {
            GUILayout.Space(16f);
            GUILayout.Label("Privacy", overlaySkin.box);
            if (privacyGate == null)
            {
                GUILayout.Label("Gate: Missing");
                return;
            }

            if (GUILayout.Button("Review / withdraw ad consent", GUILayout.MinHeight(TouchHeight)))
            {
                expanded = false;
                privacyGate.OpenDevelopmentPrivacyPanel();
                GUIUtility.ExitGUI();
            }

            GUILayout.Label("State: " + (privacyGate.IsAdvertisingAllowed ? "Authorized" : "Blocked"));
            GUILayout.Label(privacyGate.AdvertisingBlockingReason, GUILayout.MinHeight(44f));
        }

        private void DrawInterstitialSection()
        {
            GUILayout.Space(16f);
            GUILayout.Label("2 / Interstitial", overlaySkin.box);
            GUILayout.Label(controller != null ? "State: " + controller.InterstitialState + " | Ready: " + controller.IsInterstitialAdReady : "State: Controller missing");
            GUILayout.Label(controller != null
                ? "Unit: " + (string.IsNullOrWhiteSpace(controller.InterstitialAdUnitId) ? "(missing)" : controller.InterstitialAdUnitId)
                : "Unit: (missing)");

            GUI.enabled = controller != null && privacyGate != null &&
                          privacyGate.IsAdvertisingAllowed && controller.IsInitialized && !controller.IsInterstitialLoading && !controller.IsAdShowing;
            if (GUILayout.Button("Load Interstitial", GUILayout.MinHeight(TouchHeight)))
                controller.LoadInterstitial();
            GUI.enabled = controller != null && privacyGate != null &&
                          privacyGate.IsAdvertisingAllowed && controller.IsInterstitialAdReady;
            if (GUILayout.Button("FORCE SHOW Interstitial", GUILayout.MinHeight(TouchHeight)))
                controller.ShowInterstitial();
            GUI.enabled = true;
        }

        private void DrawRewardedSection()
        {
            GUILayout.Space(16f);
            GUILayout.Label("3 / Rewarded", overlaySkin.box);
            GUILayout.Label(controller != null ? "State: " + controller.RewardedState + " | Ready: " + controller.IsRewardedAdReady : "State: Controller missing");
            GUILayout.Label(controller != null
                ? "Unit: " + (string.IsNullOrWhiteSpace(controller.RewardedAdUnitId) ? "(missing)" : controller.RewardedAdUnitId)
                : "Unit: (missing)");

            GUI.enabled = controller != null && privacyGate != null &&
                          privacyGate.IsAdvertisingAllowed && controller.IsInitialized && !controller.IsRewardedLoading && !controller.IsAdShowing;
            if (GUILayout.Button("Load Rewarded", GUILayout.MinHeight(TouchHeight)))
                controller.LoadRewarded();
            GUI.enabled = controller != null && privacyGate != null &&
                          privacyGate.IsAdvertisingAllowed && controller.IsRewardedAdReady;
            if (GUILayout.Button("FORCE SHOW Rewarded", GUILayout.MinHeight(TouchHeight)))
                controller.ShowRewarded();
            GUI.enabled = true;
        }

        private void DrawDiagnosticsSection()
        {
            GUILayout.Space(16f);
            GUILayout.Label("Diagnostics", overlaySkin.box);
            GUILayout.Label(controller != null ? controller.PendingOperationDiagnostic : "Controller missing");
            GUILayout.Label(controller != null ? "Last success: " + controller.LastSuccessfulOperation : "Last success: None");
            GUILayout.Label(controller != null ? "Last error: " + controller.LastError : "Last error: Controller missing");
            GUILayout.Label(controller != null ? "Status: " + controller.DebugStatus : "Status: Controller missing");
            GUILayout.Space(4f);
            GUILayout.Label(
                "No ad is verified ready until its load callback succeeds. If loading fails, verify App Key, ad-unit IDs, dashboard app/network setup, test-device registration, and network access.");
        }

        private void DrawAdvertisingTimerSection()
        {
            GUILayout.Space(16f);
            GUILayout.Label("Advertising timers / DEV cheats", overlaySkin.box);

            if (interstitialScheduler == null)
                interstitialScheduler = AutomaticInterstitialScheduler.Instance;
            if (coinsCoordinator == null)
                coinsCoordinator = FindAnyObjectByType<RewardedCoinsCoordinator>();

            string interstitialStatus = interstitialScheduler == null
                ? "Scheduler: Missing"
                : string.Format("Interstitial: {0} | Elapsed: {1:0}s / 300s",
                    interstitialScheduler.IsDevelopmentInterstitialEligible ? "ELIGIBLE" : "waiting",
                    interstitialScheduler.DevelopmentActiveGameplaySeconds);
            GUILayout.Label(interstitialStatus);

            GUI.enabled = interstitialScheduler != null;
            GUILayout.BeginHorizontal();
            if (GUILayout.Button("SKIP 5 MIN", GUILayout.MinHeight(TouchHeight)))
                interstitialScheduler.DevelopmentSkipFiveMinutes();
            if (GUILayout.Button("RESET TIMER", GUILayout.MinHeight(TouchHeight)))
                interstitialScheduler.DevelopmentResetTimer();
            GUILayout.EndHorizontal();

            string coinsStatus = coinsCoordinator == null
                ? "Coins cooldown: Coordinator missing"
                : coinsCoordinator.IsDevelopmentCooldownActive
                    ? "Coins cooldown: " + coinsCoordinator.DevelopmentCooldownRemainingSeconds + "s remaining"
                    : "Coins cooldown: ready";
            GUILayout.Label(coinsStatus);
            GUI.enabled = coinsCoordinator != null;
            if (GUILayout.Button("EXPIRE COINS COOLDOWN", GUILayout.MinHeight(TouchHeight)))
                coinsCoordinator.DevelopmentExpireCooldown();
            GUI.enabled = true;

            GUILayout.Label(controller == null
                ? "AD STATUS: Controller missing"
                : string.Format("AD STATUS: SDK {0}, Interstitial {1}, Rewarded {2}, Active rewarded {3}",
                    controller.InitializationState,
                    controller.IsInterstitialAdReady ? "READY" : "not ready",
                    controller.IsRewardedAdReady ? "READY" : "not ready",
                    controller.IsRewardedAdShowing ? "yes" : "no"));
            GUILayout.Label(controller == null ? "Rewarded blocker: Controller missing" :
                "Rewarded blocker: " + controller.RewardedAvailabilityReason);
            if (coinsCoordinator != null)
                GUILayout.Label("Coins offer: " + coinsCoordinator.DevelopmentAvailabilityReason);
            GUILayout.Label("SKIP 5 MIN uses the normal automatic Home navigation path; it does not show an ad directly.");
        }
#endif
    }
}
