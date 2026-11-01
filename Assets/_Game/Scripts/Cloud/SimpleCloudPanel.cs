using TMPro;
using UnityEngine;
using UnityEngine.UI;

namespace SweetMerge.Cloud
{
    public sealed class SimpleCloudPanel : MonoBehaviour
    {
        private TMP_Text status;
        private Button check, local, cloud;
        private string confirmation;
        private string confirmedHash;
        private TMP_FontAsset font;
        private SimpleCloudBackup renderedService;
        private CloudBackupEnvelope renderedRemote;
        private string renderedServiceStatus;
        private string renderedCafeName;
        private string renderedConfirmation;
        private int renderedTutorialStage;
        private bool hasRenderedStatus;

        public static void Attach(Transform parent, TMP_FontAsset font)
        {
            var panel = parent.gameObject.AddComponent<SimpleCloudPanel>();
            panel.font = font;
            panel.status = Text(parent, font, "Cloud backup", 350, 135);
            panel.status.color = new Color(0.25f, 0.12f, 0.07f);
            panel.check = panel.MakeButton("Check / retry backup", 495, async () => {
                panel.confirmation = null;
                if (SimpleCloudBackup.Instance != null) await SimpleCloudBackup.Instance.CheckAsync(true);
            });
            panel.local = panel.MakeButton("Back up this device", 555, async () => {
                var service = SimpleCloudBackup.Instance;
                if (service == null) return;
                if (panel.confirmation != "local" || panel.confirmedHash != service.Remote?.checksum)
                { panel.confirmation = "local"; panel.confirmedHash = service.Remote?.checksum; return; }
                panel.confirmation = null; await service.KeepLocalAsync();
            });
            panel.cloud = panel.MakeButton("Restore cloud & reopen game", 615, async () => {
                var service = SimpleCloudBackup.Instance;
                if (service == null) return;
                if (panel.confirmation != "cloud" || panel.confirmedHash != service.Remote?.checksum)
                { panel.confirmation = "cloud"; panel.confirmedHash = service.Remote?.checksum; return; }
                panel.confirmation = null; await service.RestoreAsync();
                if (SimpleCloudFiles.RestorePending) ShowRestartOverlay();
            });
        }

        private void OnDisable() { confirmation = null; }
        private void Update()
        {
            var service = SimpleCloudBackup.Instance;
            if (service == null) return;
            var remote = service.Remote;
            string serviceStatus = service.Status;
            string cafeName = remote == null ? null : remote.cafeName;
            int tutorialStage = remote == null ? 0 : remote.tutorialStage;
            if (!hasRenderedStatus ||
                renderedService != service ||
                renderedRemote != remote ||
                renderedServiceStatus != serviceStatus ||
                renderedCafeName != cafeName ||
                renderedTutorialStage != tutorialStage ||
                renderedConfirmation != confirmation)
            {
                string text = confirmation == "local" ?
                    "Tap Back up this device again to replace this account's cloud backup with current device progress." :
                    confirmation == "cloud" ?
                    "Tap Restore again, then close and reopen the game. Current device files will be kept for recovery." :
                    serviceStatus + (remote == null ? "" :
                        "\nCloud café: " + cafeName +
                        (tutorialStage == 4 ? " · Tutorial complete" : " · Tutorial in progress"));
                if (status.text != text)
                    status.text = text;

                renderedService = service;
                renderedRemote = remote;
                renderedServiceStatus = serviceStatus;
                renderedCafeName = cafeName;
                renderedTutorialStage = tutorialStage;
                renderedConfirmation = confirmation;
                hasRenderedStatus = true;
            }

            SetInteractable(
                check,
                !service.Busy && !SimpleCloudFiles.RestorePending);
            SetInteractable(local, !service.Busy && service.ChoiceRequired);
            SetInteractable(cloud, !service.Busy && service.CanRestore);
        }

        private static void SetInteractable(Button button, bool value)
        {
            if (button.interactable != value)
                button.interactable = value;
        }

        private Button MakeButton(string label, float top, UnityEngine.Events.UnityAction action)
        {
            var go = new GameObject(label, typeof(RectTransform), typeof(Image), typeof(Button));
            go.transform.SetParent(transform, false);
            Place(go.GetComponent<RectTransform>(), top, 50);
            go.GetComponent<Image>().color = new Color(0.28f, 0.13f, 0.08f);
            var button = go.GetComponent<Button>();
            button.onClick.AddListener(action);
            var text = Text(go.transform, font, label, 0, 50);
            text.alignment = TextAlignmentOptions.Center;
            return button;
        }

        private static TMP_Text Text(Transform parent, TMP_FontAsset font, string value, float top, float height)
        {
            var go = new GameObject("Cloud text", typeof(RectTransform), typeof(TextMeshProUGUI));
            go.transform.SetParent(parent, false);
            Place(go.GetComponent<RectTransform>(), top, height);
            var text = go.GetComponent<TextMeshProUGUI>();
            text.font = font; text.fontSize = 20; text.color = Color.white;
            text.text = value; text.richText = false; text.raycastTarget = false;
            return text;
        }

        private static void Place(RectTransform rect, float top, float height)
        {
            rect.anchorMin = new Vector2(0, 1); rect.anchorMax = new Vector2(1, 1);
            rect.offsetMin = new Vector2(8, -top - height); rect.offsetMax = new Vector2(-8, -top);
        }

        public static void ShowRestartOverlay()
        {
            if (GameObject.Find("Cloud restore restart") != null) return;
            var go = new GameObject("Cloud restore restart", typeof(Canvas), typeof(CanvasScaler), typeof(GraphicRaycaster));
            DontDestroyOnLoad(go);
            var canvas = go.GetComponent<Canvas>(); canvas.renderMode = RenderMode.ScreenSpaceOverlay;
            canvas.sortingOrder = 32760;
            var scaler = go.GetComponent<CanvasScaler>(); scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
            scaler.referenceResolution = new Vector2(720, 1280);
            var background = new GameObject("Block input", typeof(RectTransform), typeof(Image));
            background.transform.SetParent(go.transform, false);
            var rect = background.GetComponent<RectTransform>(); rect.anchorMin = Vector2.zero; rect.anchorMax = Vector2.one;
            rect.offsetMin = rect.offsetMax = Vector2.zero;
            background.GetComponent<Image>().color = new Color(0.12f, 0.07f, 0.05f, 0.98f);
            var text = Text(background.transform, TMP_Settings.defaultFontAsset,
                SimpleCloudFiles.StartupError ?? "Cloud restore is ready.\n\nClose and reopen the game to finish.\n\nYour previous device progress has been preserved for recovery.", 350, 500);
            text.fontSize = 30; text.alignment = TextAlignmentOptions.Center;
        }
    }
}
