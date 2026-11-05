#if UNITY_ANDROID || UNITY_EDITOR
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

// A readable replacement for the fixed-size native development console.
// Runtime gating also covers Unity versions that no longer define DEVELOPMENT_BUILD.
public sealed class AndroidDevelopmentConsole : MonoBehaviour
{
    private const int MaxEntries = 80;
    private readonly Queue<string> entries = new Queue<string>();
    private readonly object logLock = new object();
    private RectTransform safeArea;
    private GameObject panel;
    private TextMeshProUGUI output;
    private ScrollRect scroll;
    private GameplayModalInputGate.GameplayModalLease lease;
    private bool dirty, requestOpen, previousNativeEnabled;
    private float nextRefresh;

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
    private static void Install()
    {
        if (Application.platform == RuntimePlatform.Android && Debug.isDebugBuild)
            new GameObject("Android Development Console").AddComponent<AndroidDevelopmentConsole>();
    }

    private void Awake()
    {
        DontDestroyOnLoad(gameObject);
        previousNativeEnabled = Debug.developerConsoleEnabled;
        Debug.developerConsoleEnabled = false;
        Debug.developerConsoleVisible = false;
        Application.logMessageReceivedThreaded += ReceiveLog;
        BuildUi();
    }

    private void ReceiveLog(string message, string stack, LogType type)
    {
        bool error = type == LogType.Error || type == LogType.Exception || type == LogType.Assert;
        string value = "[" + type + "] " + message + (error ? "\n" + stack : "");
        if (value.Length > 3000) value = value.Substring(0, 3000) + "…";
        lock (logLock)
        {
            while (entries.Count >= MaxEntries) entries.Dequeue();
            entries.Enqueue(value);
            dirty = true;
            requestOpen |= error;
        }
    }

    private void Update()
    {
        Rect bounds = Screen.safeArea;
        safeArea.anchorMin = new Vector2(bounds.xMin / Screen.width, bounds.yMin / Screen.height);
        safeArea.anchorMax = new Vector2(bounds.xMax / Screen.width, bounds.yMax / Screen.height);
        bool open;
        lock (logLock) open = requestOpen;
        if (open) Open();
        if (!panel.activeSelf || Time.unscaledTime < nextRefresh) return;
        nextRefresh = Time.unscaledTime + 0.25f;
        bool follow = scroll.verticalNormalizedPosition <= 0.02f;
        lock (logLock)
        {
            if (!dirty) return;
            output.text = string.Join("\n\n", entries);
            dirty = false;
        }
        Canvas.ForceUpdateCanvases();
        if (follow) scroll.verticalNormalizedPosition = 0;
    }

    private void Open()
    {
        if (!panel.activeSelf)
        {
            if (!GameplayModalInputGate.TryAcquireBlockingModal(this, out lease)) return;
            if (!GameplayModalInputGate.IsSafeToOpen(lease))
            {
                lease.Dispose(); lease = null;
                return;
            }
            panel.SetActive(true);
            scroll.verticalNormalizedPosition = 0;
        }
        lock (logLock) requestOpen = false;
    }

    private void Close()
    {
        panel.SetActive(false);
        lease?.Dispose(); lease = null;
        lock (logLock) requestOpen = false;
    }

    private void BuildUi()
    {
        var canvas = gameObject.AddComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        canvas.sortingOrder = 32760;
        var scaler = gameObject.AddComponent<CanvasScaler>();
        scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(720, 1280);
        scaler.matchWidthOrHeight = 0.5f;
        gameObject.AddComponent<GraphicRaycaster>();
        safeArea = Rect("Safe Area", transform);
        Stretch(safeArea);
        var toggle = MakeButton("LOGS", safeArea, Open);
        toggle.anchorMin = toggle.anchorMax = new Vector2(0, 0.5f);
        toggle.pivot = new Vector2(0, 0.5f);
        toggle.anchoredPosition = new Vector2(8, 0);
        toggle.sizeDelta = new Vector2(120, 60);

        var card = Rect("Log Panel", safeArea);
        card.anchorMin = new Vector2(0, 0);
        card.anchorMax = new Vector2(1, 0.7f);
        card.offsetMin = new Vector2(8, 8);
        card.offsetMax = new Vector2(-8, 0);
        card.gameObject.AddComponent<Image>().color = new Color(0.06f, 0.07f, 0.09f, 0.98f);
        panel = card.gameObject;
        var close = MakeButton("CLOSE", card, Close);
        close.anchorMin = close.anchorMax = new Vector2(1, 1);
        close.pivot = Vector2.one;
        close.anchoredPosition = new Vector2(-8, -8);
        close.sizeDelta = new Vector2(140, 60);
        var title = Label("Development logs", card);
        title.fontSize = 26;
        var titleRect = title.rectTransform;
        titleRect.anchorMin = new Vector2(0, 1); titleRect.anchorMax = Vector2.one;
        titleRect.offsetMin = new Vector2(16, -68); titleRect.offsetMax = new Vector2(-160, -8);

        var viewport = Rect("Scroll View", card);
        Stretch(viewport);
        viewport.offsetMin = new Vector2(16, 16);
        viewport.offsetMax = new Vector2(-16, -80);
        viewport.gameObject.AddComponent<Image>().color = new Color(0, 0, 0, 0.1f);
        viewport.gameObject.AddComponent<RectMask2D>();
        scroll = viewport.gameObject.AddComponent<ScrollRect>();
        scroll.viewport = viewport;
        scroll.horizontal = false;
        scroll.movementType = ScrollRect.MovementType.Clamped;
        output = Label("", viewport);
        output.fontSize = 28;
        output.richText = false;
        output.alignment = TextAlignmentOptions.TopLeft;
        var content = output.rectTransform;
        content.anchorMin = new Vector2(0, 1); content.anchorMax = Vector2.one;
        content.pivot = new Vector2(0.5f, 1);
        content.sizeDelta = Vector2.zero;
        output.gameObject.AddComponent<ContentSizeFitter>().verticalFit = ContentSizeFitter.FitMode.PreferredSize;
        scroll.content = content;
        panel.SetActive(false);
    }

    private static RectTransform Rect(string name, Transform parent)
    {
        var rect = new GameObject(name, typeof(RectTransform)).GetComponent<RectTransform>();
        rect.SetParent(parent, false);
        return rect;
    }

    private static void Stretch(RectTransform rect)
    {
        rect.anchorMin = Vector2.zero; rect.anchorMax = Vector2.one;
        rect.offsetMin = rect.offsetMax = Vector2.zero;
    }

    private static TextMeshProUGUI Label(string text, Transform parent)
    {
        var rect = Rect("Text", parent);
        Stretch(rect);
        var label = rect.gameObject.AddComponent<TextMeshProUGUI>();
        label.font = TMP_Settings.defaultFontAsset;
        label.text = text; label.fontSize = 26;
        label.color = Color.white; label.raycastTarget = false;
        label.alignment = TextAlignmentOptions.MidlineLeft;
        return label;
    }

    private static RectTransform MakeButton(string text, Transform parent, UnityEngine.Events.UnityAction action)
    {
        var rect = Rect(text, parent);
        rect.gameObject.AddComponent<Image>().color = new Color(0.18f, 0.22f, 0.3f);
        rect.gameObject.AddComponent<Button>().onClick.AddListener(action);
        Label(text, rect).alignment = TextAlignmentOptions.Center;
        return rect;
    }

    private void OnDestroy()
    {
        Application.logMessageReceivedThreaded -= ReceiveLog;
        lease?.Dispose();
        Debug.developerConsoleEnabled = previousNativeEnabled;
    }
}
#endif
