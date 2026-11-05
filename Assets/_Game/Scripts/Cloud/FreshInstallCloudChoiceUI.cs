using System;
using System.Threading.Tasks;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

namespace SweetMerge.Cloud
{
    // A startup-only modal: local initialization is held by GameStartupCoordinator.
    public sealed class FreshInstallCloudChoiceUI : MonoBehaviour
    {
        private static FreshInstallCloudChoiceUI instance;
        private SimpleCloudBackup service;
        private TMP_Text title, description, newGameLabel, feedback;
        private Button restore, newGame, retry, cancel;
        private string approvedChecksum, approvedWriteLock;
        private GameplayModalInputGate.GameplayModalLease inputLease;

        internal static void Show(SimpleCloudBackup service)
        {
            if (instance != null) return;
            var root = new GameObject("Cloud progress choice", typeof(Canvas),
                typeof(CanvasScaler), typeof(GraphicRaycaster));
            DontDestroyOnLoad(root);
            instance = root.AddComponent<FreshInstallCloudChoiceUI>();
            instance.service = service;
            instance.Build();
            GameplayModalInputGate.TryAcquireBlockingModal(instance, out instance.inputLease);
        }

        internal static void Close()
        {
            if (instance == null) return;
            instance.inputLease?.Dispose();
            instance.gameObject.SetActive(false);
            Destroy(instance.gameObject);
            instance = null;
        }

        private void Build()
        {
            var canvas = GetComponent<Canvas>();
            canvas.renderMode = RenderMode.ScreenSpaceOverlay;
            canvas.sortingOrder = 32750;
            var scaler = GetComponent<CanvasScaler>();
            scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
            scaler.referenceResolution = new Vector2(720, 1280);
            scaler.matchWidthOrHeight = 0.5f;

            var shade = new GameObject("Background", typeof(RectTransform), typeof(Image));
            shade.transform.SetParent(transform, false);
            var shadeRect = shade.GetComponent<RectTransform>();
            shadeRect.anchorMin = Vector2.zero;
            shadeRect.anchorMax = Vector2.one;
            shadeRect.offsetMin = shadeRect.offsetMax = Vector2.zero;
            shade.GetComponent<Image>().color = new Color(0.12f, 0.07f, 0.05f, 0.96f);

            var card = new GameObject("Cloud choice card", typeof(RectTransform), typeof(Image));
            card.transform.SetParent(shade.transform, false);
            var rect = card.GetComponent<RectTransform>();
            rect.anchorMin = rect.anchorMax = new Vector2(0.5f, 0.5f);
            rect.sizeDelta = new Vector2(640, 610);
            card.GetComponent<Image>().color = new Color(1f, 0.95f, 0.87f);

            title = Label(card.transform, "Welcome back!", 25, 60, 34);
            description = Label(card.transform, "Checking for your saved cafe...", 95, 190, 24);
            restore = MakeButton(card.transform, "Restore Cloud Progress", 300, async () =>
            {
                await service.RestoreAsync();
                if (SimpleCloudFiles.RestorePending)
                {
                    Close();
                    SimpleCloudPanel.ShowRestartOverlay();
                }
            });
            newGame = MakeButton(card.transform, "Start New Game", 375, async () =>
            {
                if (approvedChecksum == null)
                {
                    approvedChecksum = service.Remote?.checksum;
                    approvedWriteLock = service.ReviewedCloudWriteLock;
                    return;
                }
                string checksum = approvedChecksum, writeLock = approvedWriteLock;
                ClearApproval();
                await service.StartFreshGameAsync(checksum, writeLock);
            });
            newGameLabel = newGame.GetComponentInChildren<TMP_Text>();
            cancel = MakeButton(card.transform, "Back", 450, () =>
            {
                ClearApproval();
                return Task.CompletedTask;
            });
            retry = MakeButton(card.transform, "Retry Cloud Check", 450,
                () => service.NeedsFreshInstallSignIn
                    ? service.ReconnectFreshInstallAsync() : service.CheckAsync(true));
            feedback = Label(card.transform, string.Empty, 525, 65, 18);
            Refresh();
        }

        private void Update() => Refresh();

        private void Refresh()
        {
            if (service == null) return;
            bool hasChoice = service.FreshInstallChoicePending && service.CanRestore &&
                !service.NeedsFreshInstallSignIn;
            if (service.NeedsFreshInstallSignIn) ClearApproval();
            if (approvedChecksum != service.Remote?.checksum ||
                approvedWriteLock != service.ReviewedCloudWriteLock)
                ClearApproval();
            bool confirming = approvedChecksum != null;
            title.text = confirming ? "Start a new cafe?" : hasChoice ? "Welcome back!" : "Cloud progress";
            description.text = confirming
                ? "Your saved cafe will be replaced when your new game is backed up. This cannot be undone.\n\nContinue with a new game?"
                : hasChoice
                    ? "We found your cafe: " + service.Remote.cafeName +
                      ".\n\nRestore your progress, or begin again. Restoring requires reopening the game."
                    : service.Status;
            restore.gameObject.SetActive(hasChoice && !confirming);
            newGame.gameObject.SetActive(hasChoice);
            cancel.gameObject.SetActive(confirming);
            retry.gameObject.SetActive(!hasChoice);
            retry.GetComponentInChildren<TMP_Text>().text = service.NeedsFreshInstallSignIn
                ? "Reconnect Google Play" : "Retry Cloud Check";
            newGameLabel.text = confirming ? "Confirm New Game" : "Start New Game";
            feedback.text = hasChoice ? service.Status : string.Empty;
            restore.interactable = newGame.interactable = retry.interactable =
                cancel.interactable = !service.Busy;
        }

        private void ClearApproval() { approvedChecksum = null; approvedWriteLock = null; }

        private void OnDestroy()
        {
            inputLease?.Dispose();
            if (instance == this) instance = null;
        }

        private Button MakeButton(Transform parent, string text, float top, Func<Task> action)
        {
            var root = new GameObject(text, typeof(RectTransform), typeof(Image), typeof(Button));
            root.transform.SetParent(parent, false);
            Place(root.GetComponent<RectTransform>(), top, 60);
            root.GetComponent<Image>().color = new Color(0.28f, 0.13f, 0.08f);
            var button = root.GetComponent<Button>();
            button.onClick.AddListener(async () =>
            {
                if (service == null || service.Busy) return;
                await action();
            });
            var label = Label(root.transform, text, 0, 60, 24);
            label.color = Color.white;
            return button;
        }

        private static TMP_Text Label(Transform parent, string value, float top, float height, float size)
        {
            var root = new GameObject("Label", typeof(RectTransform), typeof(TextMeshProUGUI));
            root.transform.SetParent(parent, false);
            Place(root.GetComponent<RectTransform>(), top, height);
            var label = root.GetComponent<TextMeshProUGUI>();
            label.font = TMP_Settings.defaultFontAsset;
            label.fontSize = size;
            label.color = new Color(0.28f, 0.13f, 0.08f);
            label.text = value;
            label.alignment = TextAlignmentOptions.Center;
            label.richText = false;
            label.raycastTarget = false;
            return label;
        }

        private static void Place(RectTransform rect, float top, float height)
        {
            rect.anchorMin = new Vector2(0, 1);
            rect.anchorMax = Vector2.one;
            rect.offsetMin = new Vector2(24, -top - height);
            rect.offsetMax = new Vector2(-24, -top);
        }
    }
}
