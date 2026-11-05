using TMPro;
using UnityEngine;
using UnityEngine.UI;

namespace SweetMerge.Cloud
{
    public sealed class SimpleCloudPanel : MonoBehaviour
    {
        private TMP_Text status;
        private Button check, local, cloud, cancelOwnershipLink;
        private string confirmation;
        private string confirmedHash;
        private string confirmedLocalPlayerId;
        private string confirmedLocalWriteLock;
        private int confirmedLocalIdentityEpoch;
        private string ownershipLinkFeedback;
        private TMP_FontAsset font;
        private SimpleCloudBackup renderedService;
        private CloudBackupEnvelope renderedRemote;
        private string renderedServiceStatus;
        private string renderedCafeName;
        private string renderedConfirmation;
        private string renderedOwnershipLinkFeedback;
        private int renderedTutorialStage;
        private bool hasRenderedStatus;

        public static void Attach(Transform parent, TMP_FontAsset font)
        {
            var panel = parent.gameObject.AddComponent<SimpleCloudPanel>();
            panel.font = font;
            panel.status = Text(parent, font, "Cloud backup", 350, 135);
            panel.status.color = new Color(0.25f, 0.12f, 0.07f);
            panel.check = panel.MakeButton("Check / retry backup", 495, async () => {
                panel.ClearConflictConfirmation();
                panel.ownershipLinkFeedback = null;
                if (SimpleCloudBackup.Instance != null) await SimpleCloudBackup.Instance.CheckAsync(true);
            });
            panel.local = panel.MakeButton(
                "Keep Device Progress",
                555,
                async () => await panel.HandleKeepDeviceClicked());
            panel.cloud = panel.MakeButton("Restore cloud & reopen game", 615, async () => {
                var service = SimpleCloudBackup.Instance;
                if (service == null) return;
                if (panel.confirmation != "cloud" ||
                    panel.confirmedHash != service.Remote?.checksum)
                {
                    panel.ClearConflictConfirmation();
                    panel.confirmation = "cloud";
                    panel.confirmedHash = service.Remote?.checksum;
                    panel.ownershipLinkFeedback = null;
                    return;
                }
                panel.confirmation = null; await service.RestoreAsync();
                if (SimpleCloudFiles.RestorePending) ShowRestartOverlay();
            });
            panel.cancelOwnershipLink = panel.MakeButton(
                "Cancel",
                675,
                () => panel.HandleCancelClicked());
            panel.cancelOwnershipLink.gameObject.SetActive(false);
        }

        private void OnDisable()
        {
            confirmation = null;
            ClearKeepDeviceApproval();
            ownershipLinkFeedback = null;
        }

        private void Update()
        {
            var service = SimpleCloudBackup.Instance;
            if (service == null) return;
            if ((confirmation == "local" ||
                 confirmation == "local-first") &&
                service != null &&
                (confirmation == "local"
                    ? !service.IsKeepDeviceConfirmationCurrent(
                        confirmedLocalPlayerId,
                        confirmedHash,
                        confirmedLocalWriteLock,
                        confirmedLocalIdentityEpoch)
                    : !service.IsFirstBackupConfirmationCurrent(
                        confirmedLocalPlayerId,
                        confirmedLocalIdentityEpoch)))
            {
                ClearConflictConfirmation();
                ownershipLinkFeedback =
                    "The account or cloud state changed. Check cloud progress again.";
            }

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
                renderedConfirmation != confirmation ||
                renderedOwnershipLinkFeedback != ownershipLinkFeedback)
            {
                string text = ownershipLinkFeedback != null
                    ? ownershipLinkFeedback
                    : confirmation == "local" ?
                    "Keep this device's progress for verified Unity Player ID " +
                    confirmedLocalPlayerId +
                    "?\n\nThis will replace the cloud backup for " +
                    remote?.cafeName + " (" +
                    (remote != null && remote.tutorialStage == 4
                        ? "tutorial complete"
                        : "tutorial in progress") +
                    ", reviewed version " + GetShortFingerprint(confirmedHash) +
                    "). " +
                    "If it changes before the write, the operation will stop. " +
                    "Tap Keep Device Progress again to confirm." :
                    confirmation == "local-first" ?
                    "Back up this device's progress for verified Unity Player ID " +
                    confirmedLocalPlayerId +
                    "?\n\nTap again to confirm the existing manual first-backup action." :
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
                renderedOwnershipLinkFeedback = ownershipLinkFeedback;
                hasRenderedStatus = true;
            }

            cancelOwnershipLink.gameObject.SetActive(
                confirmation == "local" ||
                confirmation == "local-first");
            SetButtonLabel(
                cancelOwnershipLink,
                confirmation == "local" || confirmation == "local-first"
                    ? "Cancel Keep Device"
                    : "Cancel");
            SetButtonLabel(
                local,
                confirmation == "local-first"
                    ? "Confirm First Backup"
                    : confirmation == "local"
                    ? "Confirm Keep Device"
                    : "Keep Device Progress");
            SetInteractable(
                check,
                !service.Busy && !SimpleCloudFiles.RestorePending);
            SetInteractable(local, !service.Busy && service.ChoiceRequired);
            SetInteractable(cloud, !service.Busy && service.CanRestore);
        }

        private async System.Threading.Tasks.Task HandleKeepDeviceClicked()
        {
            SimpleCloudBackup service = SimpleCloudBackup.Instance;
            if (service == null)
                return;

            if (confirmation == "local-first")
            {
                if (!service.IsFirstBackupConfirmationCurrent(
                        confirmedLocalPlayerId,
                        confirmedLocalIdentityEpoch))
                {
                    ClearConflictConfirmation();
                    ownershipLinkFeedback =
                        "The account or cloud state changed. Check cloud progress again.";
                    return;
                }

                ClearConflictConfirmation();
                await service.KeepLocalAsync();
                return;
            }

            if (confirmation != "local")
            {
                if (service.Remote == null)
                {
                    if (!service.TryGetFirstBackupConfirmation(
                            out string firstBackupPlayerId,
                            out int firstBackupIdentityEpoch))
                    {
                        ownershipLinkFeedback =
                            "A verified account and a confirmed cloud check " +
                            "are required before backing up this device.";
                        return;
                    }

                    ClearConflictConfirmation();
                    confirmation = "local-first";
                    confirmedLocalPlayerId = firstBackupPlayerId;
                    confirmedLocalIdentityEpoch =
                        firstBackupIdentityEpoch;
                    ownershipLinkFeedback = null;
                    return;
                }

                if (!service.TryGetKeepDeviceConfirmation(
                        out string playerId,
                        out string checksum,
                        out string writeLock,
                        out int identityEpoch))
                {
                    ownershipLinkFeedback =
                        "A verified account and current cloud conflict are " +
                        "required before choosing device progress.";
                    return;
                }

                ClearConflictConfirmation();
                confirmation = "local";
                confirmedLocalPlayerId = playerId;
                confirmedHash = checksum;
                confirmedLocalWriteLock = writeLock;
                confirmedLocalIdentityEpoch = identityEpoch;
                ownershipLinkFeedback = null;
                return;
            }

            if (!service.IsKeepDeviceConfirmationCurrent(
                    confirmedLocalPlayerId,
                    confirmedHash,
                    confirmedLocalWriteLock,
                    confirmedLocalIdentityEpoch))
            {
                ClearConflictConfirmation();
                ownershipLinkFeedback =
                    "The account or cloud version changed. Review the cloud choice again.";
                return;
            }

            string player = confirmedLocalPlayerId;
            string checksumApproved = confirmedHash;
            string lockApproved = confirmedLocalWriteLock;
            int approvedEpoch = confirmedLocalIdentityEpoch;
            ClearConflictConfirmation();
            await service.KeepLocalForConfirmedGuestConflictAsync(
                player,
                checksumApproved,
                lockApproved,
                approvedEpoch);
        }

        private void HandleCancelClicked()
        {
            if (confirmation == "local" ||
                confirmation == "local-first")
            {
                ClearConflictConfirmation();
                ownershipLinkFeedback =
                    "Keep Device canceled. Local and cloud progress were unchanged.";
                return;
            }

            CancelOwnershipLink();
        }

        private void ClearConflictConfirmation()
        {
            confirmation = null;
            confirmedHash = null;
            ClearKeepDeviceApproval();
        }

        private void ClearKeepDeviceApproval()
        {
            confirmedLocalPlayerId = null;
            confirmedLocalWriteLock = null;
            confirmedLocalIdentityEpoch = 0;
        }

        private void CancelOwnershipLink()
        {
            ownershipLinkFeedback =
                "Progress linking canceled. Local ownership and cloud data were unchanged.";
        }

        private static void SetInteractable(Button button, bool value)
        {
            if (button.interactable != value)
                button.interactable = value;
        }

        private static void SetButtonLabel(Button button, string value)
        {
            TMP_Text label = button.GetComponentInChildren<TMP_Text>();
            if (label != null && label.text != value)
                label.text = value;
        }

        private static string GetShortFingerprint(string checksum)
        {
            if (string.IsNullOrEmpty(checksum))
                return "unavailable";
            return checksum.Substring(
                0,
                Mathf.Min(8, checksum.Length));
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
