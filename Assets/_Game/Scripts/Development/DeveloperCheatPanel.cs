#if UNITY_EDITOR || UNITY_ANDROID
using System;
using System.Collections.Generic;
using System.Globalization;
using TMPro;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public sealed class DeveloperCheatPanel : MonoBehaviour
{
    private const string GameplaySceneName = "Game";
    private const string GameplayCanvasName = "GameplayCanvas";
    private const float RefreshInterval = 0.5f;

    private static DeveloperCheatPanel instance;
    private readonly List<Button> commandButtons = new List<Button>();

    private Canvas gameplayCanvas;
    private EventSystem gameplayEventSystem;
    private GameObject devButtonObject;
    private GameObject overlayObject;
    private TextMeshProUGUI rebirthSelectionText;
    private TextMeshProUGUI tierSelectionText;
    private TextMeshProUGUI clearButtonText;
    private TextMeshProUGUI diagnosticsText;
    private TextMeshProUGUI lifetimeStatisticsText;
    private TextMeshProUGUI cafeProgressionText;
    private TMP_InputField customCashInput;
    private Button clearBoardButton;
    private Button clearCancelButton;
    private Button resetProgressButton;
    private Button resetCancelButton;
    private Button refreshOrdersButton;
    private Button spawnDessertButton;
    private Button setRebirthButton;
    private DeveloperCheatCommandResult lastResult;
    private string lastCommandName = "None";
    private string localFailureReason;
    private int selectedRebirth;
    private int selectedTier = 1;
    private float nextRefreshTime;
    private bool clearConfirmationPending;
    private bool resetConfirmationPending;
    private bool missingSceneUiReported;
    private bool hasInitializedRebirthSelection;
    private readonly List<GameObject> tabs = new List<GameObject>();
    private readonly List<Button> tabButtons = new List<Button>();
    private TextMeshProUGUI summaryText, resultText;
    private ScrollRect bodyScroll;
    private GameplayModalInputGate.GameplayModalLease panelLease;
    private int selectedTab;
    private bool cloudCheckRunning;
    private GameObject testingCanvasRoot;

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
    private static void ResetStatics()
    {
        instance = null;
    }

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
    private static void Install()
    {
        if (instance != null || !DeveloperCheatAccess.Allowed)
            return;

        var bootstrap = new GameObject("Developer Cheat Panel");
        instance = bootstrap.AddComponent<DeveloperCheatPanel>();
        DontDestroyOnLoad(bootstrap);
    }

    private void Awake()
    {
        if (instance != null && instance != this)
        {
            Destroy(gameObject);
            return;
        }

        instance = this;
        SceneManager.sceneLoaded += HandleSceneLoaded;
    }

    private void Start()
    {
        TryAttachToGameplayCanvas();
    }

    private void OnDestroy()
    {
        panelLease?.Dispose();
        if (testingCanvasRoot != null)
        {
            if (Application.isPlaying) Destroy(testingCanvasRoot); else DestroyImmediate(testingCanvasRoot);
        }
        SceneManager.sceneLoaded -= HandleSceneLoaded;
        if (instance == this)
            instance = null;
    }

    private void OnDisable() { panelLease?.Dispose(); panelLease = null; }

    private void Update()
    {
        if (overlayObject != null && overlayObject.activeSelf && UnityEngine.InputSystem.Keyboard.current?.escapeKey.wasPressedThisFrame == true)
            SetPanelOpen(false);
        if (Time.unscaledTime < nextRefreshTime)
            return;

        nextRefreshTime = Time.unscaledTime + RefreshInterval;
        if (gameplayCanvas == null)
            TryAttachToGameplayCanvas();

        if (overlayObject != null && overlayObject.activeSelf) RefreshPanel();
        else if (devButtonObject != null) devButtonObject.GetComponent<Button>().interactable = DeveloperCheatAccess.Allowed && !GameplayModalInputGate.IsGameplayInputBlocked;
    }

    private void HandleSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        panelLease?.Dispose(); panelLease = null;
        commandButtons.Clear(); tabs.Clear(); tabButtons.Clear();
        testingCanvasRoot = null;
        hasInitializedRebirthSelection = false;
        gameplayCanvas = null;
        gameplayEventSystem = null;
        devButtonObject = null;
        overlayObject = null;
        missingSceneUiReported = false;
        clearConfirmationPending = false;
        resetConfirmationPending = false;

        if (scene.name == GameplaySceneName)
            TryAttachToGameplayCanvas();
    }

    private void TryAttachToGameplayCanvas()
    {
        Scene activeScene = SceneManager.GetActiveScene();
        if (activeScene.name != GameplaySceneName)
            return;

        GameObject canvasObject = GameObject.Find(GameplayCanvasName);
        Canvas canvas = canvasObject != null
            ? canvasObject.GetComponent<Canvas>()
            : null;
        EventSystem eventSystem = null;
        foreach (EventSystem candidate in FindObjectsByType<EventSystem>(
                     FindObjectsInactive.Include))
        {
            if (candidate.gameObject.scene == activeScene &&
                candidate.isActiveAndEnabled)
            {
                eventSystem = candidate;
                break;
            }
        }

        if (canvas == null ||
            canvas.gameObject.scene != activeScene ||
            canvas.GetComponent<GraphicRaycaster>() == null ||
            eventSystem == null)
        {
            if (!missingSceneUiReported)
            {
                Debug.LogWarning(
                    "DEVELOPER CHEAT PANEL | Game scene requires its " +
                    "existing GameplayCanvas, GraphicRaycaster, and EventSystem.");
                missingSceneUiReported = true;
            }

            return;
        }

        gameplayCanvas = canvas;
        gameplayEventSystem = eventSystem;
        BuildUi(canvas.transform);
        RefreshPanel();
    }

    private void BuildUi(Transform canvasTransform)
    {
        if (devButtonObject != null || overlayObject != null)
            return;

        testingCanvasRoot = new GameObject("TestingCanvas", typeof(RectTransform), typeof(Canvas), typeof(CanvasScaler), typeof(GraphicRaycaster));
        SceneManager.MoveGameObjectToScene(testingCanvasRoot, canvasTransform.gameObject.scene);
        var canvas = testingCanvasRoot.GetComponent<Canvas>(); canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        canvas.sortingOrder = 32030;
        var parentCanvas = canvasTransform.GetComponentInParent<Canvas>(true);
        if (parentCanvas != null) canvas.sortingLayerID = parentCanvas.sortingLayerID;
        var scaler = testingCanvasRoot.GetComponent<CanvasScaler>(); scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(720, 1280); scaler.matchWidthOrHeight = 0.5f;
        var safe = CreateRect("SafeArea", testingCanvasRoot.transform);
        SetStretch(safe.GetComponent<RectTransform>(), Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero);
        safe.AddComponent<SafeAreaFitter>();
        canvasTransform = safe.transform;

        devButtonObject = CreateButton(
            "TEST LAB",
            canvasTransform,
            new Vector2(1f, 1f),
            new Vector2(1f, 1f),
            new Vector2(-20f, -100f),
            new Vector2(170f, 62f),
            new Color(0.23f, 0.12f, 0.36f),
            TogglePanel);
        RectTransform devRect = devButtonObject.GetComponent<RectTransform>();
        devRect.pivot = new Vector2(1f, 1f);

        overlayObject = CreateRect("Developer Cheat Overlay", canvasTransform);
        SetStretch(overlayObject.GetComponent<RectTransform>(),
            Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero);
        Image overlayImage = overlayObject.AddComponent<Image>();
        overlayImage.color = new Color(0f, 0f, 0f, 0.72f);
        overlayImage.raycastTarget = true;
        overlayObject.SetActive(false);

        BuildPanelCard(overlayObject.transform);
        devButtonObject.transform.SetAsLastSibling();
        EditableUIView.Attach(overlayObject, "DeveloperCheatsV2");
        EditableUIView.Attach(devButtonObject, "DeveloperButtonV2");
    }

    private void BuildPanelCard(Transform overlay)
    {
        GameObject card = CreateRect("Testing workspace", overlay);
        SetStretch(card.GetComponent<RectTransform>(), new Vector2(0.025f, 0.025f), new Vector2(0.975f, 0.975f), Vector2.zero, Vector2.zero);
        card.AddComponent<Image>().color = new Color(0.055f, 0.075f, 0.12f, 0.99f);
        GameObject header = CreateRect("Header", card.transform);
        SetStretch(header.GetComponent<RectTransform>(), new Vector2(0, 1), Vector2.one, new Vector2(20, -88), new Vector2(-20, -12));
        var title = CreateText("TEST LAB", header.transform, 30, TextAlignmentOptions.MidlineLeft, new Color(0.65f, 0.85f, 1));
        title.rectTransform.offsetMax = new Vector2(-126, -4);
        var close = CreateButton("Close", header.transform, Vector2.one, Vector2.one, new Vector2(-4, -8), new Vector2(116, 60), new Color(0.2f, 0.25f, 0.36f), () => SetPanelOpen(false));
        close.GetComponent<RectTransform>().pivot = Vector2.one;
        GameObject banner = CreateRect("Build identity", card.transform);
        SetStretch(banner.GetComponent<RectTransform>(), new Vector2(0, 1), Vector2.one, new Vector2(20, -144), new Vector2(-20, -88));
        CreateText(Debug.isDebugBuild || Application.isEditor ? "DEVELOPMENT TESTING" : "PRODUCTION TEST • changes save and may cloud-sync", banner.transform, 21, TextAlignmentOptions.MidlineLeft, new Color(1, 0.76f, 0.35f));
        GameObject summary = CreateRect("Live summary", card.transform);
        SetStretch(summary.GetComponent<RectTransform>(), new Vector2(0, 1), Vector2.one, new Vector2(20, -204), new Vector2(-20, -146));
        summaryText = CreateText("Waiting for gameplay…", summary.transform, 24, TextAlignmentOptions.MidlineLeft, Color.white);
        GameObject navigation = CreateRect("Categories", card.transform);
        SetStretch(navigation.GetComponent<RectTransform>(), new Vector2(0, 1), Vector2.one, new Vector2(20, -278), new Vector2(-20, -210));
        var navLayout = navigation.AddComponent<HorizontalLayoutGroup>(); navLayout.spacing = 6;
        navLayout.childControlWidth = navLayout.childControlHeight = true;
        navLayout.childForceExpandWidth = navLayout.childForceExpandHeight = true;
        string[] names = { "Economy", "Progress", "Board", "Services" };
        for (int i = 0; i < names.Length; i++)
        {
            int index = i;
            tabButtons.Add(CreateButton(names[i], navigation.transform, Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero,
                new Color(0.12f, 0.19f, 0.3f), () => SelectTab(index)).GetComponent<Button>());
        }
        GameObject scrollObject = CreateRect("Cheat Scroll View", card.transform);
        SetStretch(scrollObject.GetComponent<RectTransform>(), Vector2.zero, Vector2.one, new Vector2(20, 128), new Vector2(-20, -292));
        bodyScroll = scrollObject.AddComponent<ScrollRect>(); bodyScroll.horizontal = false; bodyScroll.vertical = true;
        bodyScroll.movementType = ScrollRect.MovementType.Clamped; bodyScroll.scrollSensitivity = 42;
        GameObject viewport = CreateRect("Viewport", scrollObject.transform);
        SetStretch(viewport.GetComponent<RectTransform>(), Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero);
        viewport.AddComponent<Image>().color = new Color(0.08f, 0.11f, 0.17f); viewport.AddComponent<RectMask2D>();
        bodyScroll.viewport = viewport.GetComponent<RectTransform>();
        GameObject content = CreateRect("Content", viewport.transform);
        var contentRect = content.GetComponent<RectTransform>(); contentRect.anchorMin = new Vector2(0, 1); contentRect.anchorMax = Vector2.one;
        contentRect.pivot = new Vector2(0.5f, 1); contentRect.anchoredPosition = Vector2.zero; contentRect.sizeDelta = Vector2.zero;
        ConfigureColumn(content); content.AddComponent<ContentSizeFitter>().verticalFit = ContentSizeFitter.FitMode.PreferredSize;
        bodyScroll.content = contentRect;
        foreach (string name in names)
        {
            GameObject page = CreateRect(name, content.transform); ConfigureColumn(page); tabs.Add(page);
        }
        BuildCashSection(tabs[0].transform); BuildEnergySection(tabs[0].transform); BuildLifetimeStatisticsSection(tabs[0].transform);
        BuildTestCountersSection(tabs[0].transform);
        BuildCafeProgressionSection(tabs[1].transform); BuildRebirthSection(tabs[1].transform); BuildDessertSection(tabs[1].transform);
        BuildProfileSection(tabs[2].transform); BuildBoardSection(tabs[2].transform);
        BuildServicesSection(tabs[3].transform); BuildDiagnosticsSection(tabs[3].transform);
        GameObject footer = CreateRect("Action feedback", card.transform);
        SetStretch(footer.GetComponent<RectTransform>(), Vector2.zero, new Vector2(1, 0), new Vector2(20, 16), new Vector2(-20, 116));
        footer.AddComponent<Image>().color = new Color(0.11f, 0.16f, 0.24f);
        resultText = CreateText("Choose an action. Changes are saved immediately.", footer.transform, 22, TextAlignmentOptions.MidlineLeft, Color.white);
        SelectTab(0);
    }

    private static void ConfigureColumn(GameObject root)
    {
        var layout = root.AddComponent<VerticalLayoutGroup>(); layout.spacing = 12;
        layout.padding = new RectOffset(10, 10, 8, 16); layout.childControlWidth = layout.childControlHeight = true;
        layout.childForceExpandWidth = true; layout.childForceExpandHeight = false;
    }

    private void SelectTab(int index)
    {
        selectedTab = Mathf.Clamp(index, 0, tabs.Count - 1);
        for (int i = 0; i < tabs.Count; i++)
        {
            tabs[i].SetActive(i == selectedTab);
            tabButtons[i].interactable = i != selectedTab;
            var colors = tabButtons[i].colors; colors.disabledColor = new Color(0.13f, 0.42f, 0.6f);
            tabButtons[i].colors = colors;
        }
        CancelClearBoardConfirmation(); CancelResetProgressConfirmation();
        if (bodyScroll != null) { Canvas.ForceUpdateCanvases(); bodyScroll.verticalNormalizedPosition = 1; }
    }

    private void BuildTestCountersSection(Transform content)
    {
        AddSection(content, "LEADERBOARD TEST TOTALS");
        CreateRow(content,
            row => CreateButton("Earn +$1K", row, Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero, new Color(0.12f, 0.32f, 0.27f),
                () => RunCommand("Test gameplay earnings", () => DeveloperCheatCommands.AddGameplayEarnings(1000)), true),
            row => CreateButton("Orders +1", row, Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero, new Color(0.12f, 0.32f, 0.27f),
                () => RunCommand("Test lifetime order count", () => DeveloperCheatCommands.AddCompletedOrders(1)), true));
    }

    private void BuildServicesSection(Transform content)
    {
        AddSection(content, "SAVE & CLOUD");
        CreateRow(content,
            row => CreateButton("Save now", row, Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero, new Color(0.15f, 0.28f, 0.42f),
                () => RunCommand("Save now", DeveloperCheatCommands.SaveNow), true),
            row => CreateButton("Check cloud", row, Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero, new Color(0.15f, 0.28f, 0.42f),
                CheckCloud));
        CreateRow(content,
            row => CreateButton("Copy report", row, Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero, new Color(0.15f, 0.28f, 0.42f), CopyReport),
            row => CreateButton("Energy ad offer", row, Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero, new Color(0.15f, 0.28f, 0.42f),
                () => { SetPanelOpen(false); AdOfferPopup.Show(true, 50); }));
    }

    private async void CheckCloud()
    {
        if (cloudCheckRunning) return;
        var cloud = SweetMerge.Cloud.SimpleCloudBackup.Instance;
        if (cloud == null || cloud.Busy) { ReportRejectedCommand("Cloud check", "Cloud is unavailable or already busy."); return; }
        cloudCheckRunning = true;
        try
        {
            SetPanelOpen(false);
            await cloud.CheckAsync(true);
            lastCommandName = "Cloud check"; lastResult = new DeveloperCheatCommandResult(false, false, cloud.Status);
        }
        catch (Exception exception) { ReportRejectedCommand("Cloud check", exception.Message); }
        finally { cloudCheckRunning = false; }
    }

    private void CopyReport()
    {
        RefreshPanel();
        GUIUtility.systemCopyBuffer = "Dessert Merge Cafe " + Application.version + " | " + Application.identifier + "\n" +
            (diagnosticsText != null ? diagnosticsText.text : "Diagnostics unavailable.") + "\nCloud: " +
            (SweetMerge.Cloud.SimpleCloudBackup.Instance?.Status ?? "Unavailable");
        lastCommandName = "Copy report"; lastResult = new DeveloperCheatCommandResult(false, false, "Diagnostic report copied.");
        RefreshPanel();
    }

    private void BuildCashSection(Transform content)
    {
        AddSection(content, "CASH");
        CreateRow(content,
            row => CreateButton("+1K", row, Vector2.zero,
                Vector2.one, Vector2.zero, Vector2.zero,
                new Color(0.18f, 0.34f, 0.25f),
                () => RunCommand("Add cash +1K",
                    () => DeveloperCheatCommands.AddCash(1000)),
                true),
            row => CreateButton("+100K", row, Vector2.zero,
                Vector2.one, Vector2.zero, Vector2.zero,
                new Color(0.18f, 0.34f, 0.25f),
                () => RunCommand("Add cash +100K",
                    () => DeveloperCheatCommands.AddCash(100000)),
                true),
            row => CreateButton("+1M", row, Vector2.zero,
                Vector2.one, Vector2.zero, Vector2.zero,
                new Color(0.18f, 0.34f, 0.25f),
                () => RunCommand("Add cash +1M",
                    () => DeveloperCheatCommands.AddCash(1000000)),
                true));

        GameObject customRow = CreateLayoutRow(content, 66f);
        customCashInput = CreateIntegerInput(customRow.transform, "Amount > 0");
        CreateButton("ADD CUSTOM", customRow.transform,
            Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero,
            new Color(0.18f, 0.34f, 0.25f),
            AddCustomCash,
            true);
    }

    private void BuildLifetimeStatisticsSection(Transform content)
    {
        AddSection(content, "LIFETIME STATISTICS");
        lifetimeStatisticsText = CreateText(
            string.Empty,
            content,
            19f,
            TextAlignmentOptions.TopLeft,
            Color.white);
        lifetimeStatisticsText.textWrappingMode = TextWrappingModes.Normal;
        SetLayoutHeight(lifetimeStatisticsText.gameObject, 58f);
    }

    private void BuildCafeProgressionSection(Transform content)
    {
        AddSection(content, "CAFE PROGRESSION");
        cafeProgressionText = CreateText(
            string.Empty,
            content,
            19f,
            TextAlignmentOptions.TopLeft,
            Color.white);
        cafeProgressionText.textWrappingMode = TextWrappingModes.Normal;
        SetLayoutHeight(cafeProgressionText.gameObject, 108f);
    }

    private void BuildEnergySection(Transform content)
    {
        AddSection(content, "ENERGY");
        CreateRow(
            content,
            row => CreateButton("SET 50", row, Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero,
                new Color(0.2f, 0.3f, 0.4f), () => RunCommand("Set Energy to 50", () => DeveloperCheatCommands.SetEnergy(50)), true),
            row => CreateButton(
                "SET 0",
                row,
                Vector2.zero,
                Vector2.one,
                Vector2.zero,
                Vector2.zero,
                new Color(0.28f, 0.22f, 0.4f),
                () => RunCommand(
                    "Set Energy to 0",
                    DeveloperCheatCommands.SetEnergyToZero),
                true),
            row => CreateButton(
                "REFILL 100",
                row,
                Vector2.zero,
                Vector2.one,
                Vector2.zero,
                Vector2.zero,
                new Color(0.2f, 0.36f, 0.3f),
                () => RunCommand(
                    "Refill Energy",
                    DeveloperCheatCommands.RefillEnergy),
                true));
    }

    private void BuildRebirthSection(Transform content)
    {
        AddSection(content, "REBIRTH");
        GameObject row = CreateLayoutRow(content, 66f);
        CreateButton("-", row.transform, Vector2.zero, Vector2.one,
            Vector2.zero, Vector2.zero, new Color(0.27f, 0.27f, 0.34f),
            () => ChangeRebirth(-1));
        rebirthSelectionText = CreateText(
            string.Empty,
            row.transform,
            26f,
            TextAlignmentOptions.Center,
            Color.white);
        CreateButton("+", row.transform, Vector2.zero, Vector2.one,
            Vector2.zero, Vector2.zero, new Color(0.27f, 0.27f, 0.34f),
            () => ChangeRebirth(1));
        row = CreateLayoutRow(content, 66f);
        setRebirthButton = CreateButton(
            "APPLY REBIRTH",
            row.transform,
            Vector2.zero,
            Vector2.one,
            Vector2.zero,
            Vector2.zero,
            new Color(0.28f, 0.24f, 0.42f),
            () => RunCommand(
                "Set rebirth R" + selectedRebirth,
                () => DeveloperCheatCommands.SetRebirth(selectedRebirth)),
            true).GetComponent<Button>();
        CreateText(
            "Oven level and merge-tier cap are derived from rebirth. Cash is unchanged.",
            content,
            19f,
            TextAlignmentOptions.MidlineLeft,
            new Color(0.78f, 0.8f, 0.84f));
    }

    private void BuildDessertSection(Transform content)
    {
        AddSection(content, "DESSERT PLACEMENT");
        GameObject row = CreateLayoutRow(content, 66f);
        CreateButton("-", row.transform, Vector2.zero, Vector2.one,
            Vector2.zero, Vector2.zero, new Color(0.27f, 0.27f, 0.34f),
            () => ChangeTier(-1));
        tierSelectionText = CreateText(
            string.Empty,
            row.transform,
            26f,
            TextAlignmentOptions.Center,
            Color.white);
        CreateButton("+", row.transform, Vector2.zero, Vector2.one,
            Vector2.zero, Vector2.zero, new Color(0.27f, 0.27f, 0.34f),
            () => ChangeTier(1));
        row = CreateLayoutRow(content, 66f);
        spawnDessertButton = CreateButton(
            "PLACE DESSERT",
            row.transform,
            Vector2.zero,
            Vector2.one,
            Vector2.zero,
            Vector2.zero,
            new Color(0.22f, 0.34f, 0.42f),
            () => RunCommand(
                "Place dessert T" + selectedTier,
                () => DeveloperCheatCommands.SpawnDessert(selectedTier)),
            true).GetComponent<Button>();
    }

    private void BuildProfileSection(Transform content)
    {
        AddSection(content, "PROFILE & ORDERS");
        GameObject resetRow = CreateLayoutRow(content, 66f);
        resetProgressButton = CreateButton(
            "Reset All Progress",
            resetRow.transform,
            Vector2.zero,
            Vector2.one,
            Vector2.zero,
            Vector2.zero,
            new Color(0.45f, 0.19f, 0.2f),
            HandleResetProgressPressed,
            true).GetComponent<Button>();
        resetCancelButton = CreateButton(
            "CANCEL",
            resetRow.transform,
            Vector2.zero,
            Vector2.one,
            Vector2.zero,
            Vector2.zero,
            new Color(0.27f, 0.27f, 0.34f),
            CancelResetProgressConfirmation,
            true).GetComponent<Button>();
        resetCancelButton.gameObject.SetActive(false);

        GameObject refreshRow = CreateLayoutRow(content, 66f);
        refreshOrdersButton = CreateButton(
            "Refresh Customer Orders",
            refreshRow.transform,
            Vector2.zero,
            Vector2.one,
            Vector2.zero,
            Vector2.zero,
            new Color(0.18f, 0.34f, 0.25f),
            () => RunCommand(
                "Refresh customer orders",
                DeveloperCheatCommands.RefreshCustomerOrders),
            true).GetComponent<Button>();
    }

    private void BuildBoardSection(Transform content)
    {
        AddSection(content, "BOARD");
        GameObject row = CreateLayoutRow(content, 66f);
        clearBoardButton = CreateButton(
            "CLEAR BOARD DESSERTS",
            row.transform,
            Vector2.zero,
            Vector2.one,
            Vector2.zero,
            Vector2.zero,
            new Color(0.45f, 0.19f, 0.2f),
            HandleClearBoardPressed,
            true).GetComponent<Button>();
        clearButtonText =
            clearBoardButton.GetComponentInChildren<TextMeshProUGUI>();
        SetLayoutHeight(clearBoardButton.gameObject, 64f);
        clearCancelButton = CreateButton(
            "CANCEL",
            row.transform,
            Vector2.zero,
            Vector2.one,
            Vector2.zero,
            Vector2.zero,
            new Color(0.27f, 0.27f, 0.34f),
            CancelClearBoardConfirmation,
            true).GetComponent<Button>();
        SetLayoutHeight(clearCancelButton.gameObject, 64f);
        clearCancelButton.gameObject.SetActive(false);
    }

    private void BuildDiagnosticsSection(Transform content)
    {
        AddSection(content, "LIVE DIAGNOSTICS");
        diagnosticsText = CreateText(
            string.Empty,
            content,
            24f,
            TextAlignmentOptions.TopLeft,
            Color.white);
        diagnosticsText.textWrappingMode = TextWrappingModes.Normal;
        SetLayoutHeight(diagnosticsText.gameObject, 760f);
    }

    private void AddSection(Transform content, string title)
    {
        TextMeshProUGUI heading = CreateText(
            title,
            content,
            23f,
            TextAlignmentOptions.MidlineLeft,
            new Color(1f, 0.78f, 0.37f));
        SetLayoutHeight(heading.gameObject, 38f);
    }

    private void CreateRow(
        Transform parent,
        params Func<Transform, GameObject>[] children)
    {
        GameObject row = CreateLayoutRow(parent, 66f);
        foreach (Func<Transform, GameObject> createChild in children)
        {
            GameObject child = createChild(row.transform);
            SetStretch(child.GetComponent<RectTransform>(),
                Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero);
            SetLayoutHeight(child, 64f);
        }
    }

    private GameObject CreateLayoutRow(Transform parent, float height)
    {
        GameObject row = CreateRect("Control Row", parent);
        HorizontalLayoutGroup layout = row.AddComponent<HorizontalLayoutGroup>();
        layout.spacing = 8f;
        layout.childControlWidth = true;
        layout.childControlHeight = true;
        layout.childForceExpandWidth = true;
        layout.childForceExpandHeight = true;
        SetLayoutHeight(row, height);
        return row;
    }

    private GameObject CreateButton(
        string label,
        Transform parent,
        Vector2 anchorMin,
        Vector2 anchorMax,
        Vector2 anchoredPosition,
        Vector2 size,
        Color color,
        Action onClick,
        bool requiresCommandReady = false)
    {
        GameObject buttonObject = CreateRect(label, parent);
        RectTransform rect = buttonObject.GetComponent<RectTransform>();
        SetAnchored(rect, anchorMin, anchorMax, anchoredPosition, size);
        Image image = buttonObject.AddComponent<Image>();
        image.color = Color.white; // Selectable supplies the tint; avoid multiplying it twice.
        Button button = buttonObject.AddComponent<Button>();
        button.targetGraphic = image;
        var colors = button.colors; colors.normalColor = color; colors.highlightedColor = Color.Lerp(color, Color.white, 0.18f);
        colors.pressedColor = Color.Lerp(color, Color.black, 0.2f); colors.selectedColor = colors.highlightedColor;
        colors.disabledColor = new Color(0.13f, 0.16f, 0.22f, 0.7f); colors.fadeDuration = 0.08f; button.colors = colors;
        button.onClick.AddListener(() => onClick());
        if (requiresCommandReady)
            commandButtons.Add(button);
        CreateText(label, buttonObject.transform, 28f,
            TextAlignmentOptions.Center, Color.white);
        return buttonObject;
    }

    private TMP_InputField CreateIntegerInput(Transform parent, string placeholder)
    {
        GameObject inputObject = CreateRect("Custom Cash Amount", parent);
        Image image = inputObject.AddComponent<Image>();
        image.color = new Color(0.2f, 0.2f, 0.24f);
        TMP_InputField input = inputObject.AddComponent<TMP_InputField>();
        input.contentType = TMP_InputField.ContentType.IntegerNumber;
        input.characterLimit = 10;
        input.lineType = TMP_InputField.LineType.SingleLine;
        input.targetGraphic = image;

        TextMeshProUGUI text = CreateText(
            string.Empty,
            inputObject.transform,
            20f,
            TextAlignmentOptions.MidlineLeft,
            Color.white);
        text.margin = new Vector4(12f, 0f, 12f, 0f);
        input.textComponent = text;

        TextMeshProUGUI placeholderText = CreateText(
            placeholder,
            inputObject.transform,
            18f,
            TextAlignmentOptions.MidlineLeft,
            new Color(0.68f, 0.68f, 0.72f));
        placeholderText.margin = new Vector4(12f, 0f, 12f, 0f);
        input.placeholder = placeholderText;
        return input;
    }

    private TextMeshProUGUI CreateText(
        string value,
        Transform parent,
        float fontSize,
        TextAlignmentOptions alignment,
        Color color)
    {
        GameObject textObject = CreateRect("Text", parent);
        SetStretch(textObject.GetComponent<RectTransform>(),
            Vector2.zero, Vector2.one, new Vector2(8f, 4f),
            new Vector2(-8f, -4f));
        TextMeshProUGUI text = textObject.AddComponent<TextMeshProUGUI>();
        text.text = value;
        text.font = TMP_Settings.defaultFontAsset;
        text.fontSize = fontSize;
        text.enableAutoSizing = true; text.fontSizeMin = 18; text.fontSizeMax = fontSize; text.richText = false;
        text.alignment = alignment;
        text.color = color;
        text.raycastTarget = false;
        return text;
    }

    private GameObject CreateRect(string name, Transform parent)
    {
        var gameObject = new GameObject(
            name,
            typeof(RectTransform));
        gameObject.transform.SetParent(parent, false);
        return gameObject;
    }

    private void AddCustomCash()
    {
        if (!int.TryParse(
                customCashInput.text.Trim(),
                NumberStyles.None,
                CultureInfo.InvariantCulture,
                out int amount) ||
            amount <= 0)
        {
            ReportRejectedCommand(
                "Add custom cash",
                "Enter a positive whole-number cash amount.");
            return;
        }

        RunCommand(
            "Add custom cash",
            () => DeveloperCheatCommands.AddCash(amount));
    }

    private void ChangeRebirth(int delta)
    {
        selectedRebirth = Mathf.Clamp(selectedRebirth + delta, 0, 10);
        RefreshSelectionLabels();
    }

    private void ChangeTier(int delta)
    {
        selectedTier = Mathf.Clamp(selectedTier + delta, 1, 30);
        RefreshSelectionLabels();
    }

    private void HandleClearBoardPressed()
    {
        if (!clearConfirmationPending)
        {
            clearConfirmationPending = true;
            clearCancelButton.gameObject.SetActive(true);
            RefreshSelectionLabels();
            localFailureReason = "Press the clear button again to confirm.";
            return;
        }

        clearConfirmationPending = false;
        clearCancelButton.gameObject.SetActive(false);
        RunCommand(
            "Clear board desserts",
            DeveloperCheatCommands.ClearBoardDesserts);
    }

    private void HandleResetProgressPressed()
    {
        if (!resetConfirmationPending)
        {
            resetConfirmationPending = true;
            resetCancelButton.gameObject.SetActive(true);
            localFailureReason =
                "Confirmation required: press Reset All Progress again.";
            RefreshPanel();
            return;
        }

        resetConfirmationPending = false;
        resetCancelButton.gameObject.SetActive(false);
        RunCommand(
            "Reset all progress",
            DeveloperCheatCommands.ResetAllProgress);
    }

    private void CancelResetProgressConfirmation()
    {
        resetConfirmationPending = false;
        resetCancelButton.gameObject.SetActive(false);
        localFailureReason = null;
        RefreshPanel();
    }

    private void CancelClearBoardConfirmation()
    {
        clearConfirmationPending = false;
        clearCancelButton.gameObject.SetActive(false);
        localFailureReason = null;
        RefreshPanel();
    }

    private void RunCommand(
        string commandName,
        Func<DeveloperCheatCommandResult> command)
    {
        if (panelLease == null || !GameplayModalInputGate.IsSafeToOpen(panelLease))
        { ReportRejectedCommand(commandName, "Wait for a safe gameplay state and reopen the panel."); return; }
        clearConfirmationPending = false;
        resetConfirmationPending = false;
        clearCancelButton?.gameObject.SetActive(false);
        resetCancelButton?.gameObject.SetActive(false);
        localFailureReason = null;
        lastCommandName = commandName;
        try { lastResult = command(); }
        catch (Exception exception) { lastResult = new DeveloperCheatCommandResult(false, false, exception.Message); }
        if (!lastResult.Applied) localFailureReason = lastResult.Message;
        RefreshPanel();
    }

    private void ReportRejectedCommand(string commandName, string reason)
    {
        clearConfirmationPending = false;
        lastCommandName = commandName;
        localFailureReason = reason;
        lastResult = new DeveloperCheatCommandResult(false, false, reason);
        RefreshPanel();
    }

    private void TogglePanel()
    {
        SetPanelOpen(overlayObject != null && !overlayObject.activeSelf);
    }

    private void SetPanelOpen(bool isOpen)
    {
        if (overlayObject == null)
            return;

        if (isOpen && !overlayObject.activeSelf)
        {
            if (!DeveloperCheatAccess.Allowed || GameplayModalInputGate.IsGameplayInputBlocked ||
                !GameplayModalInputGate.TryAcquireBlockingModal(this, out panelLease)) return;
            if (!GameplayModalInputGate.IsSafeToOpen(panelLease)) { panelLease.Dispose(); panelLease = null; return; }
        }
        if (!isOpen)
        {
            panelLease?.Dispose(); panelLease = null;
            clearConfirmationPending = resetConfirmationPending = false;
            clearCancelButton?.gameObject.SetActive(false); resetCancelButton?.gameObject.SetActive(false);
        }

        overlayObject.SetActive(isOpen);
        if (devButtonObject != null) devButtonObject.SetActive(!isOpen);
        if (isOpen)
            overlayObject.transform.SetAsLastSibling();
        else if (devButtonObject != null)
            devButtonObject.transform.SetAsLastSibling();

        gameplayEventSystem?.SetSelectedGameObject(null);
        if (isOpen)
            RefreshPanel();
    }

    private void RefreshPanel()
    {
        if (gameplayCanvas == null ||
            gameplayEventSystem == null ||
            overlayObject == null)
        {
            return;
        }

        PlayerProgressionManager progression =
            PlayerProgressionManager.Instance;
        EconomyManager economy = EconomyManager.Instance;
        SaveManager save = SaveManager.Instance;
        GridManager grid = FindAnyObjectByType<GridManager>();
        string unavailableReason =
            DeveloperCheatCommands.GetAvailabilityMessage();
        bool ready = unavailableReason == null;
        if (summaryText != null) summaryText.text = economy != null && progression != null
            ? "$" + economy.CurrentCash.ToString("N0") + "   •   Energy " + progression.CurrentEnergy + "/" + progression.MaximumEnergy + "   •   R" + progression.CurrentRebirthCount
            : "Waiting for verified gameplay…";
        if (resultText != null)
        {
            resultText.text = localFailureReason ?? (lastResult != null ? lastCommandName + ": " + lastResult.Message : unavailableReason ?? "Choose an action. Changes are saved immediately.");
            resultText.color = localFailureReason != null ? new Color(1, 0.55f, 0.5f) : lastResult != null && lastResult.Applied && !lastResult.Saved
                ? new Color(1, 0.76f, 0.35f) : new Color(0.75f, 0.9f, 1);
        }

        if (ready && !hasInitializedRebirthSelection)
        {
            selectedRebirth = Mathf.Clamp(
                progression.CurrentRebirthCount,
                0,
                10);
            hasInitializedRebirthSelection = true;
        }

        foreach (Button button in commandButtons)
        {
            if (button != null)
                button.interactable = ready;
        }
        if (customCashInput != null)
            customCashInput.interactable = ready;
        if (setRebirthButton != null)
            setRebirthButton.interactable = ready;
        if (spawnDessertButton != null)
        {
            spawnDessertButton.interactable =
                ready &&
                progression != null &&
                selectedTier <= progression.MaxUnlockedDessertTier;
        }
        if (clearBoardButton != null)
            clearBoardButton.interactable = ready;
        if (resetProgressButton != null)
            resetProgressButton.interactable = ready && SavePathPolicy.IsDevelopmentSaveIsolationEnabled;
        if (refreshOrdersButton != null)
            refreshOrdersButton.interactable = ready;

        RefreshSelectionLabels();

        if (lifetimeStatisticsText != null)
        {
            lifetimeStatisticsText.text = economy == null
                ? "Total Orders Completed: Unavailable\nTotal Money Earned: Unavailable"
                : "Total Orders Completed: " +
                  economy.TotalOrdersCompleted.ToString("N0", CultureInfo.InvariantCulture) +
                  "\nTotal Money Earned: $" +
                  economy.TotalMoneyEarned.ToString("N0", CultureInfo.InvariantCulture);
        }

        if (cafeProgressionText != null)
        {
            string cafeTitle = null;
            int starLevel = 0;
            int? nextStarRebirth = null;
            bool hasCafeProgression = progression != null;
            if (hasCafeProgression)
                hasCafeProgression =
                    progression.TryGetCafeTitle(out cafeTitle);
            if (hasCafeProgression)
                hasCafeProgression =
                    progression.TryGetCafeStarLevel(out starLevel);
            if (hasCafeProgression)
            {
                hasCafeProgression =
                    progression.TryGetNextCafeStarRebirth(
                        out nextStarRebirth);
            }

            if (!hasCafeProgression)
            {
                cafeProgressionText.text =
                    "Completed Rebirths: " +
                    (progression != null
                        ? progression.CurrentRebirthCount.ToString(
                            "N0",
                            CultureInfo.InvariantCulture)
                        : "Unavailable") +
                    "\nCafe Title: Unavailable" +
                    "\nCafe Stars: Unavailable" +
                    "\nNext Star: Unavailable";
            }
            else
            {
                cafeProgressionText.text =
                    "Completed Rebirths: " +
                    progression.CurrentRebirthCount.ToString(
                        "N0",
                        CultureInfo.InvariantCulture) +
                    "\nCafe Title: " + cafeTitle +
                    "\nCafe Stars: " + starLevel + " / " +
                    CafeProgressionCatalog.MaximumRegularStarLevel +
                    "\nNext Star: " +
                    (nextStarRebirth.HasValue
                        ? "Rebirth " + nextStarRebirth.Value.ToString(
                            "N0",
                            CultureInfo.InvariantCulture)
                        : "MAX");
            }
        }

        if (diagnosticsText == null)
            return;

        string completion = progression == null
            ? "Unavailable"
            : progression.CampaignComplete
                ? "Complete / " + progression.CampaignCompletionPersistence
                : "Incomplete";
        string board = grid == null
            ? "Unavailable"
            : grid.OccupiedCellCount + "/" + grid.UnlockedCellCount +
              " occupied / unlocked";
        string saveMode = SavePathPolicy.ModeName;
        string saveDirectory = save != null
            ? save.SaveDirectory
            : SavePathPolicy.GetSaveDirectory();
        string commandStatus = lastResult == null
            ? "No command run"
            : "Applied=" + lastResult.Applied +
              ", Saved=" + lastResult.Saved +
              " — " + lastResult.Message;
        string state = ready
            ? "READY"
            : "DISABLED — " + unavailableReason;

        diagnosticsText.text =
            "Controls: " + state + "\n" +
            "Cash: " + (economy != null ? "$" + economy.CurrentCash : "Unavailable") + "\n" +
            "Energy: " + (progression != null
                ? progression.CurrentEnergy + "/" + progression.MaximumEnergy
                : "Unavailable") + "\n" +
            "Rebirth: " + (progression != null ? "R" + progression.CurrentRebirthCount : "Unavailable") + "\n" +
            "Oven: " + (progression != null ? "L" + progression.OvenLevel : "Unavailable") + "\n" +
            "Merge cap: " + (progression != null ? "T" + progression.MaxUnlockedDessertTier : "Unavailable") + "\n" +
            "Campaign: " + completion + "\n" +
            "Board: " + board + "\n" +
            "Save mode: " + saveMode + "\n" +
            "Save directory: " + saveDirectory + "\n" +
            "Cloud: " + (SweetMerge.Cloud.SimpleCloudBackup.Instance?.Status ?? "Unavailable") + "\n" +
            "Ads: " + (SimpleAdManager.Instance?.Status ?? "Unavailable") + "\n" +
            "Ad privacy: " + AdvertisingPrivacy.Age + " / " + AdvertisingPrivacy.Choice + "\n" +
            "Last command: " + lastCommandName + "\n" +
            "Result: " + commandStatus +
            (localFailureReason != null
                ? "\nFailure: " + localFailureReason
                : string.Empty);
    }

    private void RefreshSelectionLabels()
    {
        if (rebirthSelectionText != null)
        {
            int ovenLevel =
                RebirthProgressionState.GetOvenLevelForRebirthCount(
                    selectedRebirth);
            int tierCap = PlayerProgressionManager.Instance != null
                ? PlayerProgressionManager.Instance.MaxUnlockedDessertTier
                : 0;
            rebirthSelectionText.text =
                "R" + selectedRebirth +
                "  |  Oven L" + ovenLevel +
                "  |  Tier cap T" + tierCap;
        }

        if (tierSelectionText != null)
        {
            int tierCap = PlayerProgressionManager.Instance != null
                ? PlayerProgressionManager.Instance.MaxUnlockedDessertTier
                : 0;
            tierSelectionText.text =
                "T" + selectedTier +
                "  |  Cap T" + tierCap;
        }

        if (clearButtonText != null)
        {
            clearButtonText.text = clearConfirmationPending
                ? "CONFIRM CLEAR BOARD"
                : "CLEAR BOARD DESSERTS";
        }

        if (resetProgressButton != null)
        {
            TextMeshProUGUI label =
                resetProgressButton.GetComponentInChildren<TextMeshProUGUI>();
            if (label != null)
            {
                label.text = resetConfirmationPending
                    ? "CONFIRM RESET ALL PROGRESS"
                    : SavePathPolicy.IsDevelopmentSaveIsolationEnabled ? "Reset All Progress" : "Reset: isolated DEV only";
            }
        }
    }

    private void SetAnchored(
        RectTransform rect,
        Vector2 anchorMin,
        Vector2 anchorMax,
        Vector2 anchoredPosition,
        Vector2 size)
    {
        rect.anchorMin = anchorMin;
        rect.anchorMax = anchorMax;
        rect.anchoredPosition = anchoredPosition;
        rect.sizeDelta = size;
    }

    private void SetStretch(
        RectTransform rect,
        Vector2 anchorMin,
        Vector2 anchorMax,
        Vector2 offsetMin,
        Vector2 offsetMax)
    {
        rect.anchorMin = anchorMin;
        rect.anchorMax = anchorMax;
        rect.offsetMin = offsetMin;
        rect.offsetMax = offsetMax;
    }

    private void SetLayoutHeight(GameObject gameObject, float height)
    {
        LayoutElement layout = gameObject.GetComponent<LayoutElement>();
        if (layout == null)
            layout = gameObject.AddComponent<LayoutElement>();
        layout.minHeight = height;
        layout.preferredHeight = height;
    }
}
#endif
