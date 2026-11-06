using System;
using System.Threading.Tasks;
using SweetMerge.Cloud;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.InputSystem;
using UnityEngine.UI;

public sealed class CafeLeaderboardUI : MonoBehaviour
{
    private GameObject panel;
    private Button launcher, previous, next, moneyTab, ordersTab, refresh;
    private TMP_Text status, heading;
    private RectTransform rows, safeArea;
    private ScrollRect scroll;
    private GameplayModalInputGate.GameplayModalLease lease;
    private bool orders, loading;
    private int offset, generation;
    private string displayedOwner;
    private float nextRefresh;
    private static CafeLeaderboardUI instance;
    private SettingsUI settings;

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
    private static void Install()
    {
        if (instance == null) new GameObject("Cafe Leaderboard UI").AddComponent<CafeLeaderboardUI>();
    }

    private void Awake()
    {
        if (instance != null && instance != this) { Destroy(gameObject); return; }
        instance = this;
        DontDestroyOnLoad(gameObject);
        BuildInterface();
        SceneManager.activeSceneChanged += SceneChanged;
    }

    private void BuildInterface()
    {
        var canvas = GetComponent<Canvas>();
        if (canvas == null) canvas = gameObject.AddComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay; canvas.sortingOrder = 31000;
        var scaler = GetComponent<CanvasScaler>();
        if (scaler == null) scaler = gameObject.AddComponent<CanvasScaler>();
        scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(720, 1280); scaler.matchWidthOrHeight = 0.5f;
        if (GetComponent<GraphicRaycaster>() == null) gameObject.AddComponent<GraphicRaycaster>();
        safeArea = Rect("Safe area", transform); Stretch(safeArea);
        launcher = Button("Leaderboards", safeArea, Open);
        var launchRect = launcher.GetComponent<RectTransform>();
        launchRect.anchorMin = launchRect.anchorMax = new Vector2(0, 1);
        launchRect.pivot = new Vector2(0, 1); launchRect.anchoredPosition = new Vector2(24, -180);
        launchRect.sizeDelta = new Vector2(260, 60);

        var shade = Rect("Leaderboards", safeArea); Stretch(shade);
        shade.gameObject.AddComponent<Image>().color = new Color(0.12f, 0.07f, 0.04f, 0.98f);
        panel = shade.gameObject;
        heading = Label("Leaderboards", shade, 34);
        Place(heading.rectTransform, 20, 65, 24, 180);
        var close = Button("Close", shade, Close);
        var closeRect = close.GetComponent<RectTransform>();
        closeRect.anchorMin = closeRect.anchorMax = Vector2.one;
        closeRect.pivot = Vector2.one; closeRect.anchoredPosition = new Vector2(-24, -20);
        closeRect.sizeDelta = new Vector2(130, 65);
        moneyTab = Button("Money earned", shade, () => Select(false));
        ordersTab = Button("Orders completed", shade, () => Select(true));
        TopColumn(moneyTab.GetComponent<RectTransform>(), 0, 0.5f, 100, 68);
        TopColumn(ordersTab.GetComponent<RectTransform>(), 0.5f, 1, 100, 68);
        status = Label("", shade, 23);
        Place(status.rectTransform, 180, 90, 24, 24);
        var header = Label("Rank / Café", shade, 23);
        TopColumn(header.rectTransform, 0, 0.55f, 275, 45);
        var totalsHeader = Label("Total / Rebirth", shade, 23);
        TopColumn(totalsHeader.rectTransform, 0.55f, 1, 275, 45);
        totalsHeader.alignment = TextAlignmentOptions.MidlineRight;
        var viewport = Rect("Scroll", shade); Stretch(viewport);
        viewport.offsetMin = new Vector2(24, 110); viewport.offsetMax = new Vector2(-24, -325);
        viewport.gameObject.AddComponent<Image>().color = new Color(1, 1, 1, 0.02f);
        viewport.gameObject.AddComponent<RectMask2D>();
        scroll = viewport.gameObject.AddComponent<ScrollRect>();
        scroll.viewport = viewport; scroll.horizontal = false;
        scroll.movementType = ScrollRect.MovementType.Clamped;
        rows = Rect("Entries", viewport);
        rows.anchorMin = new Vector2(0, 1); rows.anchorMax = Vector2.one;
        rows.pivot = new Vector2(0.5f, 1); rows.sizeDelta = Vector2.zero;
        var layout = rows.gameObject.AddComponent<VerticalLayoutGroup>();
        layout.spacing = 8; layout.childControlHeight = true; layout.childForceExpandHeight = false;
        rows.gameObject.AddComponent<ContentSizeFitter>().verticalFit = ContentSizeFitter.FitMode.PreferredSize;
        scroll.content = rows;
        previous = Button("Previous", shade, () => { offset = Math.Max(0, offset - CafeLeaderboards.PageSize); Load(); });
        refresh = Button("Refresh", shade, () => Load());
        next = Button("Next", shade, () => { offset += CafeLeaderboards.PageSize; Load(); });
        Bottom(previous, 0, 1f / 3); Bottom(refresh, 1f / 3, 2f / 3); Bottom(next, 2f / 3, 1);
        panel.SetActive(false);
        EditableUIView.Attach(gameObject, "Leaderboards");
    }

    private void Update()
    {
        Rect bounds = Screen.safeArea;
        safeArea.anchorMin = new Vector2(bounds.xMin / Screen.width, bounds.yMin / Screen.height);
        safeArea.anchorMax = new Vector2(bounds.xMax / Screen.width, bounds.yMax / Screen.height);
        bool bakery = SceneManager.GetActiveScene().name == "MainBakery";
        if (bakery && settings == null) settings = FindAnyObjectByType<SettingsUI>();
        launcher.gameObject.SetActive(bakery && !panel.activeSelf &&
            (settings == null || !settings.IsOpenOrWaitingForSafeGameplayBoundary));
        launcher.interactable = !GameplayModalInputGate.IsGameplayInputBlocked;
        if (!panel.activeSelf) return;
        if (displayedOwner != SimpleCloudBackup.GetVerifiedCurrentOwnerId())
        {
            generation++; loading = false; offset = 0;
            Load();
        }
        refresh.interactable = !loading && Time.unscaledTime >= nextRefresh;
        if (Keyboard.current != null && Keyboard.current.escapeKey.wasPressedThisFrame) Close();
    }

    private void Open()
    {
        if (GameplayModalInputGate.IsGameplayInputBlocked ||
            !GameplayModalInputGate.TryAcquireBlockingModal(this, out lease)) return;
        if (!GameplayModalInputGate.IsSafeToOpen(lease)) { lease.Dispose(); lease = null; return; }
        panel.SetActive(true); offset = 0; Load();
    }

    private void Select(bool showOrders)
    {
        if (loading || orders == showOrders) return;
        orders = showOrders; offset = 0; Load();
    }

    private async void Load()
    {
        if (loading || !panel.activeSelf) return;
        int request = ++generation;
        displayedOwner = SimpleCloudBackup.GetVerifiedCurrentOwnerId();
        ClearRows();
        previous.interactable = next.interactable = false;
        heading.text = orders ? "Top orders" : "Top earnings";
        moneyTab.interactable = orders;
        ordersTab.interactable = !orders;
        if (displayedOwner == null)
        {
            status.text = "Sign in with Google Play in Settings to view the leaderboards.";
            return;
        }
        loading = true; nextRefresh = Time.unscaledTime + 5;
        moneyTab.interactable = ordersTab.interactable = false;
        status.text = "Loading cafés…";
        try
        {
            var pending = CafeLeaderboards.GetPageAsync(orders, offset);
            if (await Task.WhenAny(pending, Task.Delay(20000)) != pending)
            {
                _ = ObserveLateRequest(pending);
                throw new TimeoutException("Leaderboard request timed out.");
            }
            var page = await pending;
            if (this == null || request != generation || !panel.activeSelf) return;
            foreach (var entry in page.Results)
            {
                var data = CafeLeaderboards.ParseMetadata(entry.Metadata);
                string name = data?.cafeName ?? "Unnamed café";
                string rebirth = data == null ? "—" : data.rebirth.ToString();
                var row = Rect("Entry", rows);
                row.gameObject.AddComponent<Image>().color = entry.PlayerId == displayedOwner
                    ? new Color(0.4f, 0.27f, 0.1f) : new Color(0.23f, 0.16f, 0.11f);
                row.gameObject.AddComponent<LayoutElement>().preferredHeight = 100;
                var left = Label($"#{entry.Rank + 1}  {name}", row, 25);
                Stretch(left.rectTransform); left.rectTransform.anchorMax = new Vector2(0.55f, 1);
                left.rectTransform.offsetMin = new Vector2(12, 8);
                left.rectTransform.offsetMax = new Vector2(-8, -8);
                var right = Label((orders ? "" : "$") + CafeLeaderboards.FormatTotal(entry) + "\nRebirth " + rebirth, row, 23);
                Stretch(right.rectTransform); right.rectTransform.anchorMin = new Vector2(0.55f, 0);
                right.rectTransform.offsetMin = new Vector2(0, 8); right.rectTransform.offsetMax = new Vector2(-12, -8);
                right.alignment = TextAlignmentOptions.MidlineRight;
                EditableUIView.Attach(row.gameObject, "LeaderboardRow");
            }
            status.text = page.Results.Count == 0 ? "No cafés ranked here yet. Play and cloud-save to join!"
                : $"Ranks {offset + 1}–{offset + page.Results.Count} · Lifetime totals";
            previous.interactable = offset > 0;
            next.interactable = offset + page.Results.Count < page.Total;
            Canvas.ForceUpdateCanvases(); scroll.verticalNormalizedPosition = 1;
        }
        catch (Exception exception)
        {
            if (this != null && request == generation && panel.activeSelf)
            {
                status.text = CafeLeaderboards.ReadFailureMessage(exception);
                Debug.LogWarning("LEADERBOARDS | Read " + (orders ? CafeLeaderboards.OrdersId : CafeLeaderboards.MoneyId) +
                    " | " + SavePathPolicy.ModeName + " | " + status.text + " | " + exception.Message);
                previous.interactable = offset > 0;
            }
        }
        finally
        {
            if (this != null && request == generation)
            {
                loading = false;
                moneyTab.interactable = orders; ordersTab.interactable = !orders;
            }
        }
    }

    private void ClearRows()
    {
        foreach (Transform child in rows) { child.gameObject.SetActive(false); Destroy(child.gameObject); }
    }

    private void Close()
    {
        generation++; loading = false; panel.SetActive(false); ClearRows();
        lease?.Dispose(); lease = null;
    }
    private static async Task ObserveLateRequest(Task request)
    {
        try { await request; } catch { /* The visible request already reported a timeout. */ }
    }
    private void OnDisable()
    {
        if (panel != null) Close();
    }
    private void SceneChanged(Scene before, Scene after) { settings = null; Close(); }
    private void OnDestroy()
    {
        generation++; lease?.Dispose(); SceneManager.activeSceneChanged -= SceneChanged;
        if (instance == this) instance = null;
    }
    private static RectTransform Rect(string name, Transform parent)
    {
        var value = new GameObject(name, typeof(RectTransform)).GetComponent<RectTransform>();
        value.SetParent(parent, false); return value;
    }
    private static void Stretch(RectTransform rect)
    {
        rect.anchorMin = Vector2.zero; rect.anchorMax = Vector2.one;
        rect.offsetMin = rect.offsetMax = Vector2.zero;
    }
    private static void Place(RectTransform rect, float top, float height, float left, float right)
    {
        rect.anchorMin = new Vector2(0, 1); rect.anchorMax = Vector2.one;
        rect.offsetMin = new Vector2(left, -top - height); rect.offsetMax = new Vector2(-right, -top);
    }
    private static void Bottom(Button button, float left, float right)
    {
        var rect = button.GetComponent<RectTransform>();
        rect.anchorMin = new Vector2(left, 0); rect.anchorMax = new Vector2(right, 0);
        rect.offsetMin = new Vector2(left == 0 ? 24 : 5, 25);
        rect.offsetMax = new Vector2(right == 1 ? -24 : -5, 90);
    }
    private static void TopColumn(RectTransform rect, float left, float right, float top, float height)
    {
        rect.anchorMin = new Vector2(left, 1); rect.anchorMax = new Vector2(right, 1);
        rect.offsetMin = new Vector2(left == 0 ? 24 : 5, -top - height);
        rect.offsetMax = new Vector2(right == 1 ? -24 : -5, -top);
    }
    private static TMP_Text Label(string text, Transform parent, int size)
    {
        var rect = Rect("Text", parent); Stretch(rect);
        var value = rect.gameObject.AddComponent<TextMeshProUGUI>();
        value.font = TMP_Settings.defaultFontAsset; value.fontSize = size;
        value.enableAutoSizing = true; value.fontSizeMin = 16; value.fontSizeMax = size;
        value.overflowMode = TextOverflowModes.Ellipsis;
        value.text = text; value.richText = false; value.raycastTarget = false;
        value.color = new Color(1, 0.94f, 0.82f); value.alignment = TextAlignmentOptions.MidlineLeft;
        return value;
    }
    private static Button Button(string text, Transform parent, UnityEngine.Events.UnityAction action)
    {
        var rect = Rect(text, parent);
        rect.gameObject.AddComponent<Image>().color = new Color(0.36f, 0.21f, 0.12f);
        var button = rect.gameObject.AddComponent<Button>(); button.onClick.AddListener(action);
        Label(text, rect, 24).alignment = TextAlignmentOptions.Center;
        return button;
    }
}
