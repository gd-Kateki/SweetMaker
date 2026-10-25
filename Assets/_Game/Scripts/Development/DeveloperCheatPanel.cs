#if UNITY_EDITOR || (UNITY_ANDROID && DEVELOPMENT_BUILD)
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

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
    private static void ResetStatics()
    {
        instance = null;
    }

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
    private static void Install()
    {
        if (instance != null)
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
        SceneManager.sceneLoaded -= HandleSceneLoaded;
        if (instance == this)
            instance = null;
    }

    private void Update()
    {
        if (Time.unscaledTime < nextRefreshTime)
            return;

        nextRefreshTime = Time.unscaledTime + RefreshInterval;
        if (gameplayCanvas == null)
            TryAttachToGameplayCanvas();

        RefreshPanel();
    }

    private void HandleSceneLoaded(Scene scene, LoadSceneMode mode)
    {
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

        devButtonObject = CreateButton(
            "DEV",
            canvasTransform,
            new Vector2(1f, 1f),
            new Vector2(1f, 1f),
            new Vector2(-24f, -30f),
            new Vector2(150f, 64f),
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
    }

    private void BuildPanelCard(Transform overlay)
    {
        GameObject card = CreateRect("Developer Cheat Panel Card", overlay);
        SetStretch(card.GetComponent<RectTransform>(),
            new Vector2(0.035f, 0.025f),
            new Vector2(0.965f, 0.975f),
            Vector2.zero,
            Vector2.zero);
        Image cardImage = card.AddComponent<Image>();
        cardImage.color = new Color(0.12f, 0.12f, 0.16f, 0.99f);

        GameObject header = CreateRect("Header", card.transform);
        SetAnchored(header.GetComponent<RectTransform>(),
            new Vector2(0f, 1f),
            new Vector2(1f, 1f),
            new Vector2(0f, 1f),
            new Vector2(-24f, 86f));
        header.GetComponent<RectTransform>().offsetMax =
            new Vector2(-18f, -14f);
        header.GetComponent<RectTransform>().offsetMin =
            new Vector2(18f, -88f);

        CreateText(
            "Developer Cheats",
            header.transform,
            32f,
            TextAlignmentOptions.MidlineLeft,
            new Color(1f, 0.89f, 0.56f));
        GameObject closeButton = CreateButton(
            "CLOSE",
            header.transform,
            new Vector2(1f, 0.5f),
            new Vector2(1f, 0.5f),
            new Vector2(-4f, 0f),
            new Vector2(150f, 58f),
            new Color(0.34f, 0.18f, 0.19f),
            () => SetPanelOpen(false));
        closeButton.GetComponent<RectTransform>().pivot =
            new Vector2(1f, 0.5f);

        GameObject scrollObject = CreateRect("Cheat Scroll View", card.transform);
        SetAnchored(scrollObject.GetComponent<RectTransform>(),
            Vector2.zero,
            Vector2.one,
            Vector2.zero,
            Vector2.zero);
        RectTransform scrollRectTransform =
            scrollObject.GetComponent<RectTransform>();
        scrollRectTransform.offsetMin = new Vector2(22f, 18f);
        scrollRectTransform.offsetMax = new Vector2(-22f, -98f);

        ScrollRect scrollRect = scrollObject.AddComponent<ScrollRect>();
        scrollRect.horizontal = false;
        scrollRect.vertical = true;
        scrollRect.movementType = ScrollRect.MovementType.Clamped;
        scrollRect.scrollSensitivity = 42f;

        GameObject viewport = CreateRect("Viewport", scrollObject.transform);
        SetStretch(viewport.GetComponent<RectTransform>(),
            Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero);
        Image viewportImage = viewport.AddComponent<Image>();
        viewportImage.color = Color.white;
        viewportImage.raycastTarget = true;
        Mask mask = viewport.AddComponent<Mask>();
        mask.showMaskGraphic = false;
        scrollRect.viewport = viewport.GetComponent<RectTransform>();

        GameObject content = CreateRect("Content", viewport.transform);
        RectTransform contentRect = content.GetComponent<RectTransform>();
        contentRect.anchorMin = new Vector2(0f, 1f);
        contentRect.anchorMax = new Vector2(1f, 1f);
        contentRect.pivot = new Vector2(0.5f, 1f);
        contentRect.anchoredPosition = Vector2.zero;
        contentRect.sizeDelta = new Vector2(0f, 0f);
        VerticalLayoutGroup contentLayout =
            content.AddComponent<VerticalLayoutGroup>();
        contentLayout.spacing = 12f;
        contentLayout.padding = new RectOffset(4, 4, 4, 14);
        contentLayout.childControlWidth = true;
        contentLayout.childControlHeight = true;
        contentLayout.childForceExpandWidth = true;
        contentLayout.childForceExpandHeight = false;
        ContentSizeFitter fitter = content.AddComponent<ContentSizeFitter>();
        fitter.verticalFit = ContentSizeFitter.FitMode.PreferredSize;
        scrollRect.content = contentRect;

        BuildCashSection(content.transform);
        BuildEnergySection(content.transform);
        BuildRebirthSection(content.transform);
        BuildDessertSection(content.transform);
        BuildProfileSection(content.transform);
        BuildBoardSection(content.transform);
        BuildDiagnosticsSection(content.transform);
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

    private void BuildEnergySection(Transform content)
    {
        AddSection(content, "ENERGY");
        CreateRow(
            content,
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
                "REFILL 30",
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
        AddSection(content, "DESSERTS — DEBUG PLACEMENT (NOT OVEN SPAWNING)");
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
        AddSection(content, "DEVELOPMENT PROFILE");
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
            18f,
            TextAlignmentOptions.TopLeft,
            Color.white);
        diagnosticsText.textWrappingMode = TextWrappingModes.Normal;
        SetLayoutHeight(diagnosticsText.gameObject, 330f);
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
        image.color = color;
        Button button = buttonObject.AddComponent<Button>();
        button.targetGraphic = image;
        button.onClick.AddListener(() => onClick());
        if (requiresCommandReady)
            commandButtons.Add(button);
        CreateText(label, buttonObject.transform, 20f,
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
        clearConfirmationPending = false;
        resetConfirmationPending = false;
        clearCancelButton?.gameObject.SetActive(false);
        resetCancelButton?.gameObject.SetActive(false);
        localFailureReason = null;
        lastCommandName = commandName;
        lastResult = command();
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

        overlayObject.SetActive(isOpen);
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
            resetProgressButton.interactable = ready;
        if (refreshOrdersButton != null)
            refreshOrdersButton.interactable = ready;

        RefreshSelectionLabels();

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
                    : "Reset All Progress";
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
