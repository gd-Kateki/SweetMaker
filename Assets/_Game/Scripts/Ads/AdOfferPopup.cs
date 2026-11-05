using TMPro;
using UnityEngine;
using UnityEngine.UI;

public sealed class AdOfferPopup : MonoBehaviour
{
    private static AdOfferPopup instance;
    private GameplayModalInputGate.GameplayModalLease lease;
    private Button watch;
    private TMP_Text feedback;
    private bool energy;
    private int amount;
    public static bool Show(bool energy, int amount)
    {
        if (instance != null || GameplayModalInputGate.IsGameplayInputBlocked) return false;
        var root = new GameObject("Watch ad offer", typeof(Canvas), typeof(CanvasScaler), typeof(GraphicRaycaster));
        var popup = root.AddComponent<AdOfferPopup>();
        if (!GameplayModalAdmission.TryReserve(popup) ||
            !GameplayModalInputGate.TryAcquireBlockingModal(popup, out popup.lease) ||
            !GameplayModalInputGate.IsSafeToOpen(popup.lease))
        { Destroy(root); return false; }
        instance = popup; popup.energy = energy; popup.amount = amount;
        root.GetComponent<Canvas>().renderMode = RenderMode.ScreenSpaceOverlay;
        root.GetComponent<Canvas>().sortingOrder = 32000;
        var scaler = root.GetComponent<CanvasScaler>();
        scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(720, 1280);
        var shade = new GameObject("Shade", typeof(RectTransform), typeof(Image));
        shade.transform.SetParent(root.transform, false);
        var rect = shade.GetComponent<RectTransform>();
        rect.anchorMin = Vector2.zero; rect.anchorMax = Vector2.one; rect.offsetMin = rect.offsetMax = Vector2.zero;
        shade.GetComponent<Image>().color = new Color(0.1f, 0.05f, 0.02f, 0.9f);
        var card = new GameObject("Offer", typeof(RectTransform), typeof(Image));
        card.transform.SetParent(shade.transform, false);
        rect = card.GetComponent<RectTransform>(); rect.sizeDelta = new Vector2(600, 430);
        card.GetComponent<Image>().color = new Color(1, 0.94f, 0.85f);
        Label(card.transform, energy ? "More energy?" : "A little cafe bonus!", 35, 60, 32);
        Label(card.transform, energy ? "Watch an ad for +50 energy.\nEnergy fills up to 100." :
            "Watch an ad to earn $" + amount.ToString("N0") + ".", 105, 85, 26);
        popup.feedback = Label(card.transform, "", 195, 55, 20);
        popup.watch = Button(card.transform, "Watch Ad", 265, popup.Watch);
        Button(card.transform, "No thanks", 340, popup.Close);
        return true;
    }
    private void Update()
    {
        var ads = SimpleAdManager.Instance;
        watch.interactable = ads != null && ads.RewardedReady;
        feedback.text = ads == null ? "Ads are not available yet." : ads.RewardedReady ? "" : ads.Status;
    }
    private void Watch()
    {
        bool isEnergy = energy; int reward = amount;
        Close();
        if (SimpleAdManager.Instance != null && !SimpleAdManager.Instance.ShowRewarded(isEnergy, reward))
            Debug.Log("ADS | Ad not ready; no reward granted.");
    }
    private void Close()
    {
        lease?.Dispose(); lease = null; GameplayModalAdmission.Release(this);
        instance = null; gameObject.SetActive(false); Destroy(gameObject);
    }
    private void OnDestroy()
    {
        lease?.Dispose(); GameplayModalAdmission.Release(this);
        if (instance == this) instance = null;
    }
    private static TMP_Text Label(Transform parent, string value, float top, float height, int size)
    {
        var go = new GameObject("Label", typeof(RectTransform), typeof(TextMeshProUGUI));
        go.transform.SetParent(parent, false); Place(go.GetComponent<RectTransform>(), top, height);
        var text = go.GetComponent<TextMeshProUGUI>(); text.font = TMP_Settings.defaultFontAsset;
        text.text = value; text.fontSize = size; text.alignment = TextAlignmentOptions.Center;
        text.color = new Color(0.28f, 0.13f, 0.08f); text.raycastTarget = false; return text;
    }
    private static Button Button(Transform parent, string value, float top, UnityEngine.Events.UnityAction action)
    {
        var go = new GameObject(value, typeof(RectTransform), typeof(Image), typeof(Button));
        go.transform.SetParent(parent, false); Place(go.GetComponent<RectTransform>(), top, 55);
        go.GetComponent<Image>().color = new Color(0.28f, 0.13f, 0.08f);
        Label(go.transform, value, 0, 55, 24).color = Color.white;
        var button = go.GetComponent<Button>(); button.onClick.AddListener(action); return button;
    }
    private static void Place(RectTransform rect, float top, float height)
    {
        rect.anchorMin = new Vector2(0, 1); rect.anchorMax = Vector2.one;
        rect.offsetMin = new Vector2(25, -top-height); rect.offsetMax = new Vector2(-25, -top);
    }
}
