using System;
using TMPro;
using UnityEngine;
using UnityEngine.UI;
using Unity.Services.Authentication;

public sealed class PlayerPrivacyUI : MonoBehaviour
{
    public const string PolicyUrl = "https://offcut-studios.github.io/offcutstudios-legal/dessert-merge-cafe/privacy-policy/";
    public const string DeletionUrl = "https://offcut-studios.github.io/offcutstudios-legal/dessert-merge-cafe/data-deletion/";
    private static PlayerPrivacyUI instance;
    private GameplayModalInputGate.GameplayModalLease lease;
    private RectTransform card;
    private bool deleting;

    public static bool ShowAdvertising() => Show(false);
    public static bool ShowDeletion() => Show(true);
    private static bool Show(bool deletion)
    {
        if (instance != null || GameplayModalInputGate.IsGameplayInputBlocked) return false;
        var go = new GameObject("Player privacy", typeof(Canvas), typeof(CanvasScaler), typeof(GraphicRaycaster));
        var view = go.AddComponent<PlayerPrivacyUI>();
        if (!GameplayModalInputGate.TryAcquireBlockingModal(view, out view.lease) ||
            !GameplayModalInputGate.IsSafeToOpen(view.lease)) { Destroy(go); return false; }
        instance = view; view.deleting = deletion;
        go.GetComponent<Canvas>().renderMode = RenderMode.ScreenSpaceOverlay;
        go.GetComponent<Canvas>().sortingOrder = 32010;
        var scaler = go.GetComponent<CanvasScaler>();
        scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(720, 1280); scaler.matchWidthOrHeight = 0.5f;
        var shade = new GameObject("Shade", typeof(RectTransform), typeof(Image));
        shade.transform.SetParent(go.transform, false);
        var rect = shade.GetComponent<RectTransform>(); rect.anchorMin = Vector2.zero; rect.anchorMax = Vector2.one;
        rect.offsetMin = rect.offsetMax = Vector2.zero;
        shade.GetComponent<Image>().color = new Color(0.08f, 0.04f, 0.02f, 0.95f);
        var safe = new GameObject("Safe area", typeof(RectTransform)); safe.transform.SetParent(shade.transform, false);
        rect = safe.GetComponent<RectTransform>();
        Rect area = Screen.safeArea;
        rect.anchorMin = new Vector2(area.xMin / Screen.width, area.yMin / Screen.height);
        rect.anchorMax = new Vector2(area.xMax / Screen.width, area.yMax / Screen.height);
        rect.offsetMin = rect.offsetMax = Vector2.zero;
        view.card = new GameObject("Privacy content", typeof(RectTransform)).GetComponent<RectTransform>();
        view.card.SetParent(rect, false); view.card.anchorMin = new Vector2(0.03f, 0.03f);
        view.card.anchorMax = new Vector2(0.97f, 0.97f); view.card.offsetMin = view.card.offsetMax = Vector2.zero;
        if (deletion) view.BuildDeletion(); else view.BuildAdvertising();
        return true;
    }

    private void Clear()
    {
        foreach (Transform child in card) { child.gameObject.SetActive(false); Destroy(child.gameObject); }
    }

    private void BuildAdvertising(AdvertisingPrivacy.AgeGroup? previewAge = null)
    {
        Clear();
        Label(card, "Advertising privacy", 0, 0.10f, 32);
        var age = previewAge ?? AdvertisingPrivacy.Age;
        if (age == AdvertisingPrivacy.AgeGroup.Unknown)
        {
            Label(card, "Choose your age group so we can apply appropriate ad settings. We store only this age group on your device, not your date of birth.\n\nThis choice does not affect your game progress.", 0.11f, 0.32f, 25);
            Action<AdvertisingPrivacy.AgeGroup> choose = value => { AdvertisingPrivacy.SelectAge(value); BuildAdvertising(); };
            Button(card, "Under 13", 0.48f, () => choose(AdvertisingPrivacy.AgeGroup.Under13));
            Button(card, "13–17", 0.59f, () => choose(AdvertisingPrivacy.AgeGroup.Teen));
            Button(card, "18 or older", 0.70f, () => choose(AdvertisingPrivacy.AgeGroup.Adult));
            Button(card, "Not now", 0.81f, Defer);
        }
        else if (age == AdvertisingPrivacy.AgeGroup.Under13)
        {
            Label(card, "Ads are unavailable for this age group.\n\nDessert Merge Cafe is intended for ages 13 and above. You can contact support if this selection was incorrect.", 0.12f, 0.38f, 25);
            Button(card, "Close", 0.64f, Close);
        }
        else
        {
            bool adult = age == AdvertisingPrivacy.AgeGroup.Adult;
            Label(card, "Unity LevelPlay and Unity Ads provide ads and rewarded bonuses. They may process IP address, device and network details, ad interactions and diagnostics.\n\nLimited ads: we request restricted processing, no personalized advertising, and no Advertising ID access. " +
                (adult ? "Personalized ads: allow device/ad identifiers and data use for personalized ads, measurement and ad sharing. This is optional." : "Ages 13–17 always use restricted ad settings.") +
                "\n\nYou can change your privacy choices in Settings. Analytics consent is separate.", 0.11f, 0.44f, 24);
            Button(card, "Use limited ads", 0.59f, () => Select(AdvertisingPrivacy.AdChoice.Limited));
            if (adult) Button(card, "Allow personalized ads", 0.70f, () => Select(AdvertisingPrivacy.AdChoice.Personalized));
            if (AdvertisingPrivacy.Resolved) Button(card, "Keep current choice", 0.81f, Close);
            else Button(card, "Not now", 0.81f, Defer);
        }
        Button(card, "Privacy policy", 0.92f, () => Application.OpenURL(PolicyUrl), 0.07f);
        EditableUIView.Attach(gameObject, "AdvertisingPrivacy_" + age);
    }

    private void Select(AdvertisingPrivacy.AdChoice choice) { AdvertisingPrivacy.SelectChoice(choice); Close(); }
    private void Defer() { AdvertisingPrivacy.DeferForSession(); Close(); }

    private void BuildDeletion()
    {
        Label(card, "Account & data deletion", 0, 0.10f, 32);
        string owner = CurrentPlayerId();
        Label(card, "Request deletion of your game account, cloud saves, summaries, leaderboard entries and applicable analytics records. Support verifies ownership before acting.\n\nDeleting cloud data can permanently remove progress. Signing out, clearing app storage and uninstalling do not delete cloud records. Your Google account is unaffected.\n\nPlayer ID: " + (owner ?? "Unavailable — support can help you locate it.") +
            "\n\nOpening email or the website does not submit a request or delete anything. Follow the instructions and send your request.", 0.11f, 0.45f, 24);
        Button(card, "Email deletion request", 0.60f, () => Application.OpenURL(CreateDeletionEmail(CurrentPlayerId())));
        Button(card, "Deletion instructions", 0.71f, () => Application.OpenURL(DeletionUrl));
        Button(card, "Close", 0.82f, Close);
        EditableUIView.Attach(gameObject, "AccountDeletion");
    }

    private static string CurrentPlayerId()
    {
        try { return AuthenticationService.Instance.IsSignedIn ? AuthenticationService.Instance.PlayerId : null; }
        catch { return null; }
    }

    internal static string CreateDeletionEmail(string playerId)
    {
        string body = "I request deletion of my Dessert Merge Cafe game account and associated cloud saves, summaries, leaderboard entries and applicable analytics data.\n\nUnity Player ID: " +
            (playerId ?? "I need help locating my account.") + "\n\nPlease advise how to verify account ownership and confirm completion.\n";
        return "mailto:studiosoffcut@gmail.com?subject=" + Uri.EscapeDataString("Dessert Merge Cafe - Account and Data Deletion") + "&body=" + Uri.EscapeDataString(body);
    }

    public static void AttachSettings(Transform parent, SettingsUI settings)
    {
        if (parent.Find("Player privacy settings") != null) return;
        var content = parent as RectTransform;
        if (content == null) return;
        float top = content.sizeDelta.y;
        var section = new GameObject("Player privacy settings", typeof(RectTransform)).GetComponent<RectTransform>();
        section.SetParent(parent, false); section.anchorMin = new Vector2(0.06f, 1); section.anchorMax = new Vector2(0.94f, 1);
        section.pivot = new Vector2(0.5f, 1); section.anchoredPosition = new Vector2(0, -top - 20); section.sizeDelta = new Vector2(0, 340);
        content.sizeDelta = new Vector2(content.sizeDelta.x, top + 380);
        Label(section, "PRIVACY & ACCOUNT DATA", 0, 0.18f, 27).color = new Color(0.25f, 0.12f, 0.07f);
        Button(section, "Advertising privacy", 0.23f, () => { settings.Close(); ShowAdvertising(); }, 0.20f);
        Button(section, "Request account / data deletion", 0.50f, () => { settings.Close(); ShowDeletion(); }, 0.20f);
        Button(section, "Privacy policy", 0.77f, () => Application.OpenURL(PolicyUrl), 0.20f);
        EditableUIView.Attach(section.gameObject, "PrivacySettings");
    }

    private void Close() { lease?.Dispose(); lease = null; instance = null; gameObject.SetActive(false); Destroy(gameObject); }
    private void OnDestroy() { lease?.Dispose(); if (instance == this) instance = null; }
    private void Update()
    {
        if (deleting && UnityEngine.InputSystem.Keyboard.current?.escapeKey.wasPressedThisFrame == true) Close();
    }
    private static TMP_Text Label(Transform parent, string text, float top, float height, int size)
    {
        var go = new GameObject("Label", typeof(RectTransform), typeof(TextMeshProUGUI)); go.transform.SetParent(parent, false);
        Place(go.GetComponent<RectTransform>(), top, height);
        var label = go.GetComponent<TextMeshProUGUI>(); label.font = TMP_Settings.defaultFontAsset;
        label.text = text; label.richText = false; label.fontSize = size; label.enableAutoSizing = true;
        label.fontSizeMin = 16; label.fontSizeMax = size; label.alignment = TextAlignmentOptions.Center;
        label.color = Color.white; label.raycastTarget = false; return label;
    }
    private static void Button(Transform parent, string text, float top, UnityEngine.Events.UnityAction action, float height = 0.08f)
    {
        var go = new GameObject(text, typeof(RectTransform), typeof(Image), typeof(Button)); go.transform.SetParent(parent, false);
        Place(go.GetComponent<RectTransform>(), top, height); go.GetComponent<Image>().color = new Color(0.32f, 0.19f, 0.11f);
        Label(go.transform, text, 0, 1, 25); go.GetComponent<Button>().onClick.AddListener(action);
    }
    private static void Place(RectTransform rect, float top, float height)
    {
        rect.anchorMin = new Vector2(0, 1 - top - height); rect.anchorMax = new Vector2(1, 1 - top);
        rect.offsetMin = new Vector2(8, 0); rect.offsetMax = new Vector2(-8, 0);
    }
}
