using System;
using UnityEngine;
using Unity.Services.LevelPlay;

namespace SweetMerge.Advertising
{
    [DisallowMultipleComponent]
    public sealed class AdvertisingPrivacyGate : AdvertisingConsentProvider
    {
        public enum AgeBand { Unknown, Under13, Age13To15, Age16To17, Adult18Plus }
        private const string WithdrawalKey = "DMC.Advertising.Withdrawn.v1";

        [Tooltip("Only enable for a controlled adult test cohort after resolving applicable regional consent and age requirements. Self-declared 18+ is not age proof.")]
        [SerializeField] private bool adultTestPrivacyRequirementsResolved;
        [Tooltip("Confirm Unity Ads is the only enabled network and this device receives test ads in LevelPlay and Unity Ads.")]
        [SerializeField] private bool testDeviceConfigured;
        [Tooltip("Published app privacy notice covering Unity Ads and LevelPlay/ironSource processing, purposes, data, withdrawal and contact details.")]
        [SerializeField] private string privacyPolicyUrl;
        [Tooltip("Reviewed notice shown before consent. Must cover the actual test session, partners, data and purposes. Empty blocks ads.")]
        [TextArea(5, 14)]
        [SerializeField] private string advertisingDisclosure;
        [SerializeField] private string disclosureVersion;
        [SerializeField] private bool showDevelopmentPrivacyPanel;

        public override bool IsDevelopmentOnly => true;
        public override bool IsAdvertisingAllowed => SupportedSession && isActiveAndEnabled && resolved &&
            age == AgeBand.Adult18Plus && !Withdrawn && !restartRequired && ConfigurationReady;
        public override AdvertisingConsentState ConsentState
        {
            get
            {
                if (Withdrawn)
                    return AdvertisingConsentState.Withdrawn;
                if (IsAdvertisingAllowed)
                    return AdvertisingConsentState.Permitted;
                if (age != AgeBand.Unknown && age != AgeBand.Adult18Plus)
                    return AdvertisingConsentState.Restricted;
                return AdvertisingConsentState.Unresolved;
            }
        }
        public override bool IsPrivacyConfigurationApplied =>
            permissionExposed && ConsentState == AdvertisingConsentState.Permitted;
        public bool PrivacyOptionsRequired => true;
        public bool UsOptOut => true;
        public bool Withdrawn => PlayerPrefs.GetInt(WithdrawalKey, 0) != 0;
        public string Status { get; private set; } = "Advertising privacy is unresolved. Ads are off.";

        private AgeBand age;
        private bool resolved;
        private bool reviewing;
#if UNITY_ANDROID && DEVELOPMENT_BUILD && !UNITY_EDITOR
        private Vector2 scroll;
        private bool privacyPanelExpanded = true;
        private GUISkin privacySkin;
        private const float TouchHeight = 56f;

        public bool DevelopmentPrivacyHasPriority => isActiveAndEnabled &&
            showDevelopmentPrivacyPanel && privacyPanelExpanded;

        public void OpenDevelopmentPrivacyPanel()
        {
            showDevelopmentPrivacyPanel = true;
            privacyPanelExpanded = true;
            scroll = Vector2.zero;
        }

        public void CloseDevelopmentPrivacyPanel() => privacyPanelExpanded = false;
#endif
        // This is process-wide: scene reloads must not reopen an initialized SDK.
        private static bool permissionExposed;
        private static bool restartRequired;
        public static AdvertisingPrivacyGate Instance { get; private set; }

        private void Awake()
        {
            if (Instance != null && Instance != this)
            {
                enabled = false;
                return;
            }

            Instance = this;
            DontDestroyOnLoad(gameObject);
        }

        private static bool SupportedSession
        {
            get
            {
#if UNITY_ANDROID && DEVELOPMENT_BUILD && !UNITY_EDITOR
                return true;
#else
                return false;
#endif
            }
        }

        private bool ConfigurationReady => adultTestPrivacyRequirementsResolved && testDeviceConfigured &&
            Uri.TryCreate(privacyPolicyUrl, UriKind.Absolute, out var uri) &&
            uri.Scheme == Uri.UriSchemeHttps && !string.IsNullOrWhiteSpace(advertisingDisclosure) &&
            !string.IsNullOrWhiteSpace(disclosureVersion);

        public bool IsConfigurationReady => ConfigurationReady;

        public override string AdvertisingBlockingReason
        {
            get
            {
                if (!SupportedSession)
                    return "Ads require an Android Development Build outside the Unity Editor.";
                if (!isActiveAndEnabled)
                    return "The Advertising Privacy Gate is inactive.";
                string setup = "";
                if (!adultTestPrivacyRequirementsResolved)
                    setup += "adultTestPrivacyRequirementsResolved = OFF: verify the controlled adult cohort and privacy requirements.\n";
                if (!testDeviceConfigured)
                    setup += "testDeviceConfigured = OFF: verify this Android device receives TEST ads in LevelPlay and Unity Ads.\n";
                if (setup.Length > 0)
                    return "Game > DevelopmentAdsTesting > AdvertisingPrivacyGate:\n" + setup +
                        "Enable each Inspector flag only after verification, then rebuild/install. These are confirmations, not SDK test-mode switches.";
                if (!Uri.TryCreate(privacyPolicyUrl, UriKind.Absolute, out var uri) ||
                    uri.Scheme != Uri.UriSchemeHttps)
                    return "A valid HTTPS privacy policy URL is required.";
                if (string.IsNullOrWhiteSpace(advertisingDisclosure) ||
                    string.IsNullOrWhiteSpace(disclosureVersion))
                    return "The reviewed advertising disclosure and version are required.";
                if (age != AgeBand.Adult18Plus)
                    return "Explicit 18+ self-declaration is required for this development test.";
                if (Withdrawn)
                    return "Advertising consent was withdrawn.";
                if (restartRequired)
                    return "Privacy settings changed. Restart the app before another ad session.";
                if (!resolved)
                    return "Advertising consent has not been accepted for this session.";
                return IsAdvertisingAllowed ? "Authorized for this session." : "Advertising authorization is unresolved.";
            }
        }

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        private static void ResetSession()
        {
            permissionExposed = false;
            restartRequired = false;
        }

        public void SelectAgeBand(int value)
        {
            Block();
            age = Enum.IsDefined(typeof(AgeBand), value) ? (AgeBand)value : AgeBand.Unknown;
            Status = age == AgeBand.Adult18Plus
                ? "18+ self-declared, not verified. Review the advertising notice to continue."
                : "Ads are off for unknown age and everyone under 18 in this test integration.";
        }

        // Retain existing public entry points for any Inspector button wiring.
        public void GatherAdvertisingPrivacy()
        {
            Block();
            if (age != AgeBand.Adult18Plus || !ConfigurationReady)
            {
                Status = "Ads are off: adult test eligibility, reviewed notice and test-device setup are required.";
                return;
            }
            reviewing = true;
            Status = restartRequired
                ? "Review or withdraw below. Restart the app before another ad session."
                : "Read the notice and explicitly accept or decline. Declining keeps ads off.";
        }

        public void ShowAdvertisingPrivacyOptions() => GatherAdvertisingPrivacy();

        public void AcceptAdvertisingPrivacy()
        {
            if (!reviewing || !isActiveAndEnabled || age != AgeBand.Adult18Plus ||
                !ConfigurationReady || restartRequired || !SupportedSession)
            {
                Status = "Ads remain off. Complete privacy setup on an Android Development Build; restart if privacy changed.";
                return;
            }

            // Only an explicit, informed adult opt-in reaches this point. No cached grant
            // is reused. These are transport signals, not a CMP or an NPA guarantee.
            try
            {
#if UNITY_ANDROID && DEVELOPMENT_BUILD && !UNITY_EDITOR
                LevelPlayPrivacySettings.SetGDPRConsent(true);
                LevelPlayPrivacySettings.SetCCPA(true);
                LevelPlayPrivacySettings.SetCOPPA(false);
#endif
                PlayerPrefs.SetInt(WithdrawalKey, 0);
                PlayerPrefs.Save();
#if UNITY_ANDROID && DEVELOPMENT_BUILD && !UNITY_EDITOR
                privacyPanelExpanded = false;
#endif
                resolved = true;
                reviewing = false;
                permissionExposed = true;
                Status = "Consent recorded for this session. Initialize, load and show test ads manually.";
                NotifyAdvertisingPrivacyChanged(IsAdvertisingAllowed);
            }
            catch (Exception exception)
            {
                Block();
                restartRequired = true;
                Status = "Privacy signal failed; ads are off. Restart before retrying.";
                Debug.LogException(exception);
            }
        }

        public void DeclineAdvertisingPrivacy() => WithdrawAdvertisingPrivacy();

        public void WithdrawAdvertisingPrivacy()
        {
            // Close the gate before touching storage or SDKs.
            Block();
            restartRequired |= permissionExposed;
            PlayerPrefs.SetInt(WithdrawalKey, 1);
            PlayerPrefs.Save();
            if (permissionExposed)
            {
                try
                {
#if UNITY_ANDROID && DEVELOPMENT_BUILD && !UNITY_EDITOR
                    LevelPlayPrivacySettings.SetGDPRConsent(false);
                    LevelPlayPrivacySettings.SetCCPA(true);
#endif
                }
                catch (Exception exception) { Debug.LogException(exception); }
            }
            Status = "Advertising declined/withdrawn. Future ads are blocked; an ad already onscreen may finish.";
        }

        public void OpenAdvertisingPrivacyPolicy()
        {
            if (Uri.TryCreate(privacyPolicyUrl, UriKind.Absolute, out var uri) &&
                uri.Scheme == Uri.UriSchemeHttps)
                Application.OpenURL(privacyPolicyUrl);
        }

        private void Block()
        {
            restartRequired |= permissionExposed;
            resolved = false;
            reviewing = false;
            NotifyAdvertisingPrivacyChanged(false);
        }

        private void OnDisable() => Block();

        private void OnDestroy()
        {
#if UNITY_ANDROID && DEVELOPMENT_BUILD && !UNITY_EDITOR
            if (privacySkin != null)
                Destroy(privacySkin);
#endif
            if (Instance == this)
                Instance = null;
        }

#if UNITY_ANDROID && DEVELOPMENT_BUILD && !UNITY_EDITOR
        private void OnGUI()
        {
            if (!showDevelopmentPrivacyPanel || !privacyPanelExpanded) return;
            Rect pixels = Screen.safeArea;
            if (pixels.width <= 0f || pixels.height <= 0f) return;
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
                EnsurePrivacyStyles();
                GUI.matrix = Matrix4x4.Scale(new Vector3(scale, scale, 1f));
                GUI.skin = privacySkin;
                GUI.enabled = true;
                GUI.color = GUI.backgroundColor = GUI.contentColor = Color.white;
                Rect panel = new Rect(safe.x + 8f, safe.y + 80f, safe.width - 16f, safe.height - 88f);
                GUI.color = new Color(0.07f, 0.08f, 0.10f, 1f);
                GUI.DrawTexture(panel, Texture2D.whiteTexture);
                GUI.color = Color.white;
                GUILayout.BeginArea(panel, privacySkin.box);
                GUILayout.Label("Advertising privacy (DEV)", privacySkin.box);
                // Always reachable, even when the disclosure is long or the device rotates.
                if (GUILayout.Button("Continue playing / close", GUILayout.MinHeight(TouchHeight)))
                    privacyPanelExpanded = false;
                scroll = GUILayout.BeginScrollView(scroll, false, true);
                GUILayout.BeginVertical(GUILayout.ExpandWidth(true));
                GUILayout.Label("Closing this panel does not grant consent. Use Force Ads above to inspect blockers at any time.");
                GUILayout.Label(Status);
                if (!IsAdvertisingAllowed)
                    GUILayout.Label("Ads are off. " + AdvertisingBlockingReason);
                GUILayout.Label("Choose your age range. This is self-declaration, not age verification.");
                GUILayout.Label("Selected age: " + AgeLabel());
                if (GUILayout.Button("Under 13", GUILayout.MinHeight(TouchHeight))) SelectAgeBand((int)AgeBand.Under13);
                if (GUILayout.Button("13-15", GUILayout.MinHeight(TouchHeight))) SelectAgeBand((int)AgeBand.Age13To15);
                if (GUILayout.Button("16-17", GUILayout.MinHeight(TouchHeight))) SelectAgeBand((int)AgeBand.Age16To17);
                if (GUILayout.Button("18 or older", GUILayout.MinHeight(TouchHeight))) SelectAgeBand((int)AgeBand.Adult18Plus);
                GUILayout.Space(12f);
                GUILayout.Label("Advertising notice", privacySkin.box);
                GUILayout.Label("Notice version: " + disclosureVersion);
                GUILayout.Label(string.IsNullOrWhiteSpace(advertisingDisclosure)
                    ? "The advertising notice is unavailable. Ads remain off." : advertisingDisclosure);
                GUILayout.Label("Sale/share opt-out remains on. No anonymous or non-personalized-ad guarantee is made. No gameplay reward is granted.");
                if (GUILayout.Button("Open app privacy policy", GUILayout.MinHeight(TouchHeight))) OpenAdvertisingPrivacyPolicy();
                GUI.enabled = age == AgeBand.Adult18Plus && ConfigurationReady && !restartRequired;
                if (GUILayout.Button("Review advertising choices", GUILayout.MinHeight(TouchHeight))) GatherAdvertisingPrivacy();
                GUI.enabled = reviewing && age == AgeBand.Adult18Plus && ConfigurationReady && !restartRequired;
                if (GUILayout.Button("I consent to the disclosed advertising processing", GUILayout.MinHeight(TouchHeight))) AcceptAdvertisingPrivacy();
                GUI.enabled = true;
                if (GUILayout.Button("I decline / withdraw - keep ads off", GUILayout.MinHeight(TouchHeight))) DeclineAdvertisingPrivacy();
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

        private string AgeLabel()
        {
            switch (age)
            {
                case AgeBand.Under13: return "Under 13";
                case AgeBand.Age13To15: return "13-15";
                case AgeBand.Age16To17: return "16-17";
                case AgeBand.Adult18Plus: return "18 or older (self-declared)";
                default: return "Not selected";
            }
        }

        private void EnsurePrivacyStyles()
        {
            if (privacySkin != null) return;
            privacySkin = Instantiate(GUI.skin);
            privacySkin.label.fontSize = 18;
            privacySkin.label.wordWrap = true;
            privacySkin.label.richText = false;
            privacySkin.label.stretchWidth = true;
            privacySkin.label.normal.textColor = Color.white;
            privacySkin.label.margin = new RectOffset(0, 0, 4, 8);
            privacySkin.box.fontSize = 22;
            privacySkin.box.fontStyle = FontStyle.Bold;
            privacySkin.box.wordWrap = true;
            privacySkin.box.normal.textColor = Color.white;
            privacySkin.box.padding = new RectOffset(12, 12, 12, 12);
            privacySkin.button.fontSize = 20;
            privacySkin.button.wordWrap = true;
            privacySkin.button.fixedHeight = 0f;
            privacySkin.button.padding = new RectOffset(8, 8, 12, 12);
            privacySkin.button.margin = new RectOffset(0, 0, 4, 8);
            privacySkin.verticalScrollbar.fixedWidth = 40f;
            privacySkin.verticalScrollbarThumb.fixedWidth = 40f;
            privacySkin.verticalScrollbarThumb.fixedHeight = 0f;
            privacySkin.verticalScrollbarThumb.padding = new RectOffset(0, 0, 24, 24);
            privacySkin.verticalScrollbarUpButton.fixedWidth = 40f;
            privacySkin.verticalScrollbarUpButton.fixedHeight = 40f;
            privacySkin.verticalScrollbarDownButton.fixedWidth = 40f;
            privacySkin.verticalScrollbarDownButton.fixedHeight = 40f;
        }
#endif
    }
}
