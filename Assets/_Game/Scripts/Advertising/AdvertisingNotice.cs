using TMPro;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

namespace SweetMerge.Advertising
{
    // Informational acknowledgement only. No consent, age, or SDK APIs belong here.
    public sealed class AdvertisingNotice : MonoBehaviour
    {
        public const string PolicyUrl = "https://offcut-studios.github.io/offcutstudios-legal/dessert-merge-cafe/privacy-policy/";
        private static AdvertisingNotice instance;
        private GameObject view, settingsOwner, previousSelection;
        private RectTransform safeRoot;
        private bool dismissedThisSession, fromSettings;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        private static void ResetStatics() => instance = null;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
        private static void Install()
        {
            if (instance != null) return;
            var host = new GameObject(nameof(AdvertisingNotice));
            instance = host.AddComponent<AdvertisingNotice>();
            DontDestroyOnLoad(host);
        }

        private void Update()
        {
            if (view != null)
            {
                if ((fromSettings && (settingsOwner == null || !settingsOwner.activeInHierarchy)) ||
                    (!fromSettings && SceneManager.GetActiveScene().name != "MainBakery"))
                { Close(); return; }
                Rect safe = Screen.safeArea;
                if (Screen.width > 0 && Screen.height > 0)
                {
                    safeRoot.anchorMin = new Vector2(safe.xMin / Screen.width, safe.yMin / Screen.height);
                    safeRoot.anchorMax = new Vector2(safe.xMax / Screen.width, safe.yMax / Screen.height);
                }
                return;
            }
            if (dismissedThisSession || SceneManager.GetActiveScene().name != "MainBakery" ||
                SettingsManager.Instance == null || SettingsManager.Instance.CurrentSettings.advertisingNoticeAcknowledged ||
                EventSystem.current == null) return;
            // Sequence after the existing analytics prompt, without changing its consent flow.
            if (GameObject.Find("AnalyticsConsentPromptCanvas") != null) return;
            foreach (SettingsUI settings in FindObjectsByType<SettingsUI>(FindObjectsSortMode.None))
                if (settings.IsOpenOrWaitingForSafeGameplayBoundary) return;
            Show(null);
        }

        public static void AttachSettings(Transform content, GameObject overlay)
        {
            if (content.Find("AdvertisingNoticeSettings") != null) return;
            var rect = content as RectTransform;
            if (rect == null) return;
            var section = Box(content, "AdvertisingNoticeSettings", new Vector2(0.06f, 1f), new Vector2(0.94f, 1f));
            var sectionRect = (RectTransform)section.transform;
            sectionRect.pivot = new Vector2(0.5f, 1f);
            sectionRect.anchoredPosition = new Vector2(0f, -(rect.sizeDelta.y + 20f));
            sectionRect.sizeDelta = new Vector2(0f, 160f);
            rect.sizeDelta += new Vector2(0f, 200f);
            MakeButton(section.transform, "About ads", 0.53f, 1f, () =>
            { if (instance != null) instance.Show(overlay); });
            MakeButton(section.transform, "Advertising & Privacy Policy", 0f, 0.47f, OpenPolicy);
        }

        private void Show(GameObject owner)
        {
            if (view != null) return;
            fromSettings = owner != null;
            settingsOwner = owner;
            previousSelection = EventSystem.current != null ? EventSystem.current.currentSelectedGameObject : null;
            view = new GameObject("AdvertisingNoticeCanvas", typeof(RectTransform), typeof(Canvas),
                typeof(CanvasScaler), typeof(GraphicRaycaster));
            view.transform.SetParent(transform, false);
            var canvas = view.GetComponent<Canvas>();
            canvas.renderMode = RenderMode.ScreenSpaceOverlay;
            canvas.sortingOrder = 31000;
            var scaler = view.GetComponent<CanvasScaler>();
            scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
            scaler.referenceResolution = new Vector2(1080f, 1920f);
            scaler.matchWidthOrHeight = 0.5f;
            Box(view.transform, "Backdrop", Vector2.zero, Vector2.one).AddComponent<Image>().color = new Color(0, 0, 0, 0.8f);
            safeRoot = (RectTransform)Box(view.transform, "SafeArea", Vector2.zero, Vector2.one).transform;
            var panel = Box(safeRoot, "Notice", new Vector2(0.06f, 0.06f), new Vector2(0.94f, 0.94f));
            panel.AddComponent<Image>().color = new Color(0.13f, 0.1f, 0.18f, 1f);
            Label(panel.transform, "A Little Note About Ads", 0.80f, 0.95f, 54f);
            Label(panel.transform, "Ads help keep Dessert Merge Cafe free to play.\n\nInterstitial ads appear at natural breaks. Rewarded ads are optional: you choose whether to watch them for an offered reward.", 0.40f, 0.78f, 38f);
            Label(panel.transform, "This is an advertising notice, not a request for consent. Any required privacy choices are handled separately. You can read this notice and our policy again in Settings.", 0.26f, 0.39f, 28f);
            var policy = MakeButton(panel.transform, "Advertising & Privacy Policy", 0.16f, 0.24f, OpenPolicy);
            var acknowledge = MakeButton(panel.transform, "I Understand", 0.04f, 0.14f, Acknowledge);
            LinkNavigation(policy, acknowledge);
            LinkNavigation(acknowledge, policy);
            if (EventSystem.current != null) EventSystem.current.SetSelectedGameObject(acknowledge.gameObject);
        }

        private static void LinkNavigation(Button button, Button other)
        {
            var navigation = new Navigation { mode = Navigation.Mode.Explicit,
                selectOnUp = other, selectOnDown = other, selectOnLeft = other, selectOnRight = other };
            button.navigation = navigation;
        }

        private void Acknowledge()
        {
            var manager = SettingsManager.Instance;
            if (manager != null)
            {
                var settings = manager.CurrentSettings;
                settings.advertisingNoticeAcknowledged = true;
                if (!manager.TryUpdate(settings, out string reason) || !manager.Save())
                    Debug.LogWarning("Advertising notice acknowledgement was not saved; it may appear next launch. " +
                        (reason ?? manager.LastPersistenceError), this);
            }
            else Debug.LogWarning("Advertising notice acknowledgement could not be saved: settings unavailable.", this);
            // Storage failure must not prevent playing. No privacy permission is granted.
            dismissedThisSession = true;
            Close();
        }

        private void Close()
        {
            if (view != null) { view.SetActive(false); Destroy(view); view = null; }
            if (EventSystem.current != null && previousSelection != null && previousSelection.activeInHierarchy)
                EventSystem.current.SetSelectedGameObject(previousSelection);
            previousSelection = null;
            settingsOwner = null;
        }
        private void OnDisable() => Close();
        private void OnDestroy() { if (instance == this) instance = null; }
        private static void OpenPolicy() => Application.OpenURL(PolicyUrl);

        private static GameObject Box(Transform parent, string name, Vector2 min, Vector2 max)
        {
            var go = new GameObject(name, typeof(RectTransform));
            go.transform.SetParent(parent, false);
            var rect = (RectTransform)go.transform;
            rect.anchorMin = min; rect.anchorMax = max;
            rect.offsetMin = rect.offsetMax = Vector2.zero;
            return go;
        }
        private static void Label(Transform parent, string value, float bottom, float top, float size)
        {
            var text = Box(parent, "Label", new Vector2(0.06f, bottom), new Vector2(0.94f, top)).AddComponent<TextMeshProUGUI>();
            text.font = TMP_Settings.defaultFontAsset;
            text.text = value; text.fontSize = size;
            text.enableAutoSizing = true; text.fontSizeMin = 18f; text.fontSizeMax = size;
            text.color = Color.white; text.alignment = TextAlignmentOptions.Center;
            text.textWrappingMode = TextWrappingModes.Normal; text.raycastTarget = false;
        }
        private static Button MakeButton(Transform parent, string label, float bottom, float top,
            UnityEngine.Events.UnityAction action)
        {
            var go = Box(parent, label, new Vector2(0.06f, bottom), new Vector2(0.94f, top));
            var image = go.AddComponent<Image>(); image.color = new Color(0.35f, 0.18f, 0.58f, 1f);
            var button = go.AddComponent<Button>(); button.targetGraphic = image;
            button.onClick.AddListener(action);
            Label(go.transform, label, 0.05f, 0.95f, 29f);
            return button;
        }
    }
}
