using TMPro;
using SweetMerge.Profile;
using UnityEngine;
using UnityEngine.UI;

public sealed class CafeProfileUI : MonoBehaviour
{
    private const string DefaultCafeName = "My Cafe";
    private const int StarCount = 5;
    private const float ManagerRetryInterval = 0.5f;

    private string cafeName = DefaultCafeName;
    private readonly Color cardColor = new Color(0.12f, 0.08f, 0.16f, 0.96f);
    private readonly Color panelColor = new Color(0.08f, 0.05f, 0.11f, 0.98f);
    private readonly Color goldColor = new Color(1f, 0.78f, 0.25f, 1f);
    private readonly Color mutedStarColor = new Color(0.45f, 0.42f, 0.48f, 1f);

    private GameObject cardRoot;
    private GameObject panelRoot;
    private Button cardButton;
    private Button closeButton;
    private GameObject namingRoot;
    private GameObject namingInputStep;
    private GameObject namingConfirmationStep;
    private TMP_InputField namingInput;
    private TMP_Text namingErrorText;
    private TMP_Text namingConfirmationText;
    private Button retryLocalProfileButton;
    private Button namingContinueButton;
    private Button namingConfirmButton;
    private TMP_Text panelTitleText;
    private TMP_Text panelNameText;
    private TMP_Text panelStarsText;
    private TMP_Text moneyText;
    private TMP_Text ordersText;
    private PlayerProgressionManager progressionManager;
    private EconomyManager economyManager;
    private HybridTutorialController tutorialController;
    private CafeProfileLocalRecord localProfile;
    private CafeProfileLocalStatus localProfileStatus;
    private string localProfileError;
    private bool profileOperationInProgress;
    private bool tutorialSubscribed;
    private bool restoreGatePending;
    private bool localProfileInitialized;
    private float nextManagerRetryTime;

    private void Awake()
    {
        CreateCard();
        CreatePanel();
        CreateNamingPopup();
        SweetMerge.Cloud.SimpleCloudFiles.RestorePendingChanged +=
            HandleRestorePendingChanged;
        restoreGatePending =
            SweetMerge.Cloud.SimpleCloudFiles.RestorePending;
        if (restoreGatePending)
        {
            cardRoot.SetActive(false);
            namingRoot.SetActive(false);
            SetNamingButtonsInteractable(false);
        }
        else
        {
            LoadLocalCafeProfile();
            localProfileInitialized = true;
        }

        TryBindManagers();
        Refresh();
    }

    private void OnEnable()
    {
        TryBindManagers();
        Refresh();
        SubscribeToTutorial();
        RefreshNamingEligibility();
#if UNITY_EDITOR || DEVELOPMENT_BUILD
        TryShowAfterDevelopmentReset();
#endif
    }

    private void Update()
    {
        if (!tutorialSubscribed)
            SubscribeToTutorial();

        if (progressionManager == null || economyManager == null)
        {
            if (Time.unscaledTime >= nextManagerRetryTime)
            {
                nextManagerRetryTime = Time.unscaledTime + ManagerRetryInterval;
                TryBindManagers();
                Refresh();
            }
        }
    }

    private void OnDisable()
    {
        UnbindManagers();
        UnsubscribeFromTutorial();
        if (panelRoot != null)
            panelRoot.SetActive(false);
        if (namingRoot != null)
            namingRoot.SetActive(false);
    }

    private void OnDestroy()
    {
        SweetMerge.Cloud.SimpleCloudFiles.RestorePendingChanged -=
            HandleRestorePendingChanged;
        UnbindManagers();
        UnsubscribeFromTutorial();
    }

    private void HandleRestorePendingChanged(bool restorePending)
    {
        if (restorePending)
        {
            restoreGatePending = true;
            localProfileInitialized = false;
            localProfile = null;
            localProfileStatus = CafeProfileLocalStatus.Missing;
            localProfileError = null;
            if (cardRoot != null)
                cardRoot.SetActive(false);
            if (panelRoot != null)
                panelRoot.SetActive(false);
            if (namingRoot != null)
                namingRoot.SetActive(false);
            SetNamingButtonsInteractable(false);
            return;
        }

        if (!restoreGatePending)
            return;

        restoreGatePending = false;
        if (!localProfileInitialized)
        {
            LoadLocalCafeProfile();
            localProfileInitialized = true;
        }

        if (cardRoot != null)
            cardRoot.SetActive(true);
        Refresh();
        RefreshNamingEligibility();
    }

    private void LoadLocalCafeProfile()
    {
        if (restoreGatePending ||
            SweetMerge.Cloud.SimpleCloudFiles.RestorePending)
            return;

        localProfileStatus =
            CafeProfileLocalStore.Load(
                out localProfile,
                out localProfileError);

        if (localProfileStatus == CafeProfileLocalStatus.Loaded &&
            localProfile != null &&
            localProfile.NamingCompleted)
        {
            cafeName = localProfile.CafeName;
            CloseNamingPopup();
        }
        else if (localProfileStatus == CafeProfileLocalStatus.Missing)
        {
            localProfile = null;
            localProfileError = null;
            cafeName = DefaultCafeName;
            SetText(namingErrorText, string.Empty);
            if (retryLocalProfileButton != null)
                retryLocalProfileButton.gameObject.SetActive(false);
            SetNamingButtonsInteractable(true);
        }
        else if (localProfileStatus == CafeProfileLocalStatus.InvalidData ||
                 localProfileStatus == CafeProfileLocalStatus.ServiceError)
        {
            localProfile = null;
            Debug.LogError(
                "CAFE PROFILE | Local profile load failed: " +
                localProfileError);
        }
        else if (localProfileStatus == CafeProfileLocalStatus.Loaded)
        {
            localProfileStatus = CafeProfileLocalStatus.InvalidData;
            localProfileError =
                "The local cafe profile was incomplete. Existing files were preserved.";
            Debug.LogError("CAFE PROFILE | " + localProfileError);
        }
    }

    private void HandleLocalProfileRetry()
    {
        if (restoreGatePending ||
            SweetMerge.Cloud.SimpleCloudFiles.RestorePending ||
            profileOperationInProgress)
            return;

        profileOperationInProgress = true;
        SetNamingButtonsInteractable(false);
        if (retryLocalProfileButton != null)
            retryLocalProfileButton.interactable = false;

        LoadLocalCafeProfile();

        profileOperationInProgress = false;
        SetNamingButtonsInteractable(true);
        if (retryLocalProfileButton != null)
            retryLocalProfileButton.interactable = true;
        RefreshNamingEligibility();
    }

    private void CreateCard()
    {
        cardRoot = CreateRect("CafeProfileCard", transform);
        SetAnchors(cardRoot, new Vector2(0f, 0.5f), new Vector2(0f, 0.5f),
            new Vector2(18f, -48f), new Vector2(114f, 48f));

        Image background = cardRoot.AddComponent<Image>();
        background.color = cardColor;

        cardButton = cardRoot.AddComponent<Button>();
        cardButton.targetGraphic = background;
        cardButton.onClick.AddListener(Open);

        CreatePlaceholder(cardRoot.transform, Vector2.zero, 76f);
    }

    private void CreatePanel()
    {
        Canvas rootCanvas = GetComponentInParent<Canvas>();
        if (rootCanvas == null)
        {
            Debug.LogError("CafeProfileUI requires a parent Canvas.", this);
            enabled = false;
            return;
        }

        panelRoot = CreateRect("CafeProfileOverlay", rootCanvas.transform);
        SetFullRect(panelRoot);
        Image overlayImage = panelRoot.AddComponent<Image>();
        overlayImage.color = new Color(0f, 0f, 0f, 0.68f);
        panelRoot.SetActive(false);

        GameObject panel = CreateRect("CafeProfilePanel", panelRoot.transform);
        SetAnchors(panel, new Vector2(0.08f, 0.22f), new Vector2(0.92f, 0.78f),
            Vector2.zero, Vector2.zero);
        Image panelImage = panel.AddComponent<Image>();
        panelImage.color = panelColor;

        CreatePlaceholder(panel.transform, new Vector2(0f, 190f), 150f);
        panelNameText = CreateText(panel.transform, "CafeName", 30f,
            TextAlignmentOptions.Center, Color.white);
        SetAnchors(panelNameText.gameObject, new Vector2(0.1f, 0.69f),
            new Vector2(0.9f, 0.86f), Vector2.zero, Vector2.zero);

        panelTitleText = CreateText(panel.transform, "CafeTitle", 22f,
            TextAlignmentOptions.Center, new Color(1f, 0.84f, 0.5f, 1f));
        SetAnchors(panelTitleText.gameObject, new Vector2(0.08f, 0.57f),
            new Vector2(0.92f, 0.69f), Vector2.zero, Vector2.zero);

        panelStarsText = CreateText(panel.transform, "CafeStars", 26f,
            TextAlignmentOptions.Center, goldColor);
        SetAnchors(panelStarsText.gameObject, new Vector2(0.08f, 0.45f),
            new Vector2(0.92f, 0.57f), Vector2.zero, Vector2.zero);

        moneyText = CreateText(panel.transform, "MoneyEarned", 19f,
            TextAlignmentOptions.Center, Color.white);
        SetAnchors(moneyText.gameObject, new Vector2(0.08f, 0.29f),
            new Vector2(0.92f, 0.4f), Vector2.zero, Vector2.zero);

        ordersText = CreateText(panel.transform, "OrdersCompleted", 19f,
            TextAlignmentOptions.Center, Color.white);
        SetAnchors(ordersText.gameObject, new Vector2(0.08f, 0.2f),
            new Vector2(0.92f, 0.31f), Vector2.zero, Vector2.zero);

        closeButton = CreateButton(panel.transform, "Close", "CLOSE",
            new Vector2(0.25f, 0.06f), new Vector2(0.75f, 0.17f));
        closeButton.onClick.AddListener(Close);
    }

    private void CreateNamingPopup()
    {
        Canvas rootCanvas = GetComponentInParent<Canvas>();
        if (rootCanvas == null)
            return;

        namingRoot = CreateRect("CafeNamingOverlay", rootCanvas.transform);
        SetFullRect(namingRoot);
        Image overlay = namingRoot.AddComponent<Image>();
        overlay.color = new Color(0f, 0f, 0f, 0.72f);

        GameObject popup = CreateRect("CafeNamingPopup", namingRoot.transform);
        SetAnchors(popup, new Vector2(0.08f, 0.3f),
            new Vector2(0.92f, 0.7f), Vector2.zero, Vector2.zero);
        Image popupImage = popup.AddComponent<Image>();
        popupImage.color = panelColor;

        namingInputStep = CreateRect("NamingInputStep", popup.transform);
        SetFullRect(namingInputStep);
        CreateTextBlock(
            namingInputStep.transform,
            "Title",
            "Name Your Cafe",
            28f,
            new Vector2(0.08f, 0.7f),
            new Vector2(0.92f, 0.88f));
        CreateTextBlock(
            namingInputStep.transform,
            "Instructions",
            "Choose a permanent cafe name.",
            18f,
            new Vector2(0.08f, 0.56f),
            new Vector2(0.92f, 0.7f));

        namingInput = CreateInputField(
            namingInputStep.transform,
            new Vector2(0.1f, 0.4f),
            new Vector2(0.9f, 0.54f));
        namingInput.characterLimit = 20;
        namingInput.lineType = TMP_InputField.LineType.SingleLine;
        namingInput.onValueChanged.AddListener(HandleNamingInputChanged);

        namingErrorText = CreateTextBlock(
            namingInputStep.transform,
            "Error",
            string.Empty,
            16f,
            new Vector2(0.08f, 0.28f),
            new Vector2(0.92f, 0.4f));
        namingErrorText.color = new Color(1f, 0.45f, 0.4f, 1f);

        Button cancelButton = CreateButton(
            namingInputStep.transform,
            "Cancel",
            "CANCEL",
            new Vector2(0.12f, 0.1f),
            new Vector2(0.43f, 0.23f));
        cancelButton.onClick.AddListener(CloseNamingPopup);

        namingContinueButton = CreateButton(
            namingInputStep.transform,
            "Continue",
            "CONTINUE",
            new Vector2(0.57f, 0.1f),
            new Vector2(0.88f, 0.23f));
        namingContinueButton.onClick.AddListener(
            ShowNamingConfirmation);
        retryLocalProfileButton = CreateButton(
            namingInputStep.transform,
            "RetryLocalProfile",
            "RETRY LOCAL LOAD",
            new Vector2(0.2f, 0.02f),
            new Vector2(0.8f, 0.09f));
        retryLocalProfileButton.onClick.AddListener(
            HandleLocalProfileRetry);
        retryLocalProfileButton.gameObject.SetActive(false);

        namingConfirmationStep = CreateRect(
            "NamingConfirmationStep",
            popup.transform);
        SetFullRect(namingConfirmationStep);
        CreateTextBlock(
            namingConfirmationStep.transform,
            "Title",
            "Confirm Cafe Name",
            28f,
            new Vector2(0.08f, 0.72f),
            new Vector2(0.92f, 0.88f));
        namingConfirmationText = CreateTextBlock(
            namingConfirmationStep.transform,
            "Confirmation",
            string.Empty,
            19f,
            new Vector2(0.08f, 0.48f),
            new Vector2(0.92f, 0.7f));
        namingConfirmationText.textWrappingMode = TextWrappingModes.Normal;

        Button backButton = CreateButton(
            namingConfirmationStep.transform,
            "Back",
            "BACK",
            new Vector2(0.12f, 0.1f),
            new Vector2(0.43f, 0.23f));
        backButton.onClick.AddListener(ShowNamingInput);

        namingConfirmButton = CreateButton(
            namingConfirmationStep.transform,
            "Confirm",
            "CONFIRM",
            new Vector2(0.57f, 0.1f),
            new Vector2(0.88f, 0.23f));
        namingConfirmButton.onClick.AddListener(
            HandleNamingConfirmation);

        namingRoot.SetActive(false);
        namingConfirmationStep.SetActive(false);
    }

    private void ShowNamingConfirmation()
    {
        string proposedName = namingInput == null
            ? string.Empty
            : namingInput.text.Trim();
        if (string.IsNullOrEmpty(proposedName))
        {
            SetText(namingErrorText, "Enter a cafe name before continuing.");
            return;
        }

        if (proposedName.Length > 20)
        {
            SetText(namingErrorText, "Cafe names can be 20 characters maximum.");
            return;
        }

        namingInput.text = proposedName;
        SetText(namingErrorText, string.Empty);
        SetText(
            namingConfirmationText,
            $"Use \"{proposedName}\" as your permanent cafe name?\n\n" +
            "This name cannot be changed here.");
        namingInputStep.SetActive(false);
        namingConfirmationStep.SetActive(true);
    }

    private void ShowNamingInput()
    {
        namingConfirmationStep.SetActive(false);
        namingInputStep.SetActive(true);
    }

    private void HandleNamingInputChanged(string unusedValue)
    {
        if (localProfileStatus == CafeProfileLocalStatus.InvalidData ||
            localProfileStatus == CafeProfileLocalStatus.ServiceError)
            return;

        SetText(namingErrorText, string.Empty);
    }

    private void HandleNamingConfirmation()
    {
        if (restoreGatePending ||
            SweetMerge.Cloud.SimpleCloudFiles.RestorePending)
            return;

        if (profileOperationInProgress)
            return;

        if (!IsNamingEligible())
        {
            SetText(
                namingErrorText,
                "Cafe naming is unavailable until tutorial progress is confirmed.");
            namingConfirmationStep.SetActive(false);
            namingInputStep.SetActive(true);
            return;
        }

        string proposedName = namingInput == null
            ? string.Empty
            : namingInput.text.Trim();
        if (proposedName.Length == 0 || proposedName.Length > 20)
        {
            SetNamingError(
                "Cafe names must contain 1 to 20 characters.");
            return;
        }

        profileOperationInProgress = true;
        SetNamingButtonsInteractable(false);
        CafeProfileLocalSaveStatus saveStatus =
            CafeProfileLocalStore.Save(
                proposedName,
                out CafeProfileLocalRecord savedProfile,
                out string errorMessage);
        profileOperationInProgress = false;
        SetNamingButtonsInteractable(true);

        if (saveStatus == CafeProfileLocalSaveStatus.Saved ||
            saveStatus == CafeProfileLocalSaveStatus.AlreadyNamed)
        {
            ApplyLocalCafeProfile(savedProfile);
            return;
        }

        if (saveStatus == CafeProfileLocalSaveStatus.InvalidName)
        {
            SetNamingError(
                errorMessage ??
                "Cafe names must contain 1 to 20 characters.");
            return;
        }

        if (saveStatus == CafeProfileLocalSaveStatus.InvalidData)
            localProfileStatus = CafeProfileLocalStatus.InvalidData;
        else
            localProfileStatus = CafeProfileLocalStatus.ServiceError;
        localProfileError = errorMessage ??
            "Cafe profile could not be saved. Your existing files were preserved.";
        Debug.LogError("CAFE PROFILE | " + localProfileError);
        SetNamingError(localProfileError);
        retryLocalProfileButton.gameObject.SetActive(true);
        SetNamingButtonsInteractable(false);
        retryLocalProfileButton.interactable = true;
    }

    private void ApplyLocalCafeProfile(CafeProfileLocalRecord profile)
    {
        if (profile == null || !profile.NamingCompleted)
        {
            localProfileStatus = CafeProfileLocalStatus.InvalidData;
            localProfileError =
                "The local cafe profile response was incomplete.";
            SetNamingError(localProfileError);
            retryLocalProfileButton.gameObject.SetActive(true);
            SetNamingButtonsInteractable(false);
            retryLocalProfileButton.interactable = true;
            return;
        }

        localProfile = profile;
        localProfileStatus = CafeProfileLocalStatus.Loaded;
        localProfileError = null;
        cafeName = profile.CafeName;
        SetText(namingErrorText, string.Empty);
        CloseNamingPopup();
        Refresh();
    }

    private void CloseNamingPopup()
    {
        if (namingRoot != null)
            namingRoot.SetActive(false);
        if (namingInput != null)
            namingInput.text = string.Empty;
        SetText(namingErrorText, string.Empty);
        if (retryLocalProfileButton != null)
            retryLocalProfileButton.gameObject.SetActive(false);
    }

#if UNITY_EDITOR || DEVELOPMENT_BUILD
    [ContextMenu("Preview Cafe Naming Popup")]
    public void PreviewNamingPopup()
    {
        ShowNamingPopup();
    }

    private void TryShowAfterDevelopmentReset()
    {
        if (!DeveloperCheatCommands.ConsumeCafeNamingPrompt())
            return;

        ShowNamingPopup();
    }
#endif

    private void ShowNamingPopup()
    {
        if (restoreGatePending ||
            SweetMerge.Cloud.SimpleCloudFiles.RestorePending)
            return;

        if (namingRoot == null)
            CreateNamingPopup();
        if (namingRoot == null)
            return;

        if (panelRoot != null)
            panelRoot.SetActive(false);
        namingInputStep.SetActive(true);
        namingConfirmationStep.SetActive(false);
        namingInput.text = string.Empty;
        SetText(namingErrorText, string.Empty);
        namingRoot.SetActive(true);
        SetNamingButtonsInteractable(true);
    }

    private void SubscribeToTutorial()
    {
        HybridTutorialController current =
            HybridTutorialController.Instance;
        if (current == null || tutorialSubscribed)
            return;

        tutorialController = current;
        tutorialController.StateChanged +=
            HandleTutorialStateChanged;
        tutorialController.TutorialCompleted +=
            HandleTutorialCompleted;
        tutorialController.ReadinessChanged +=
            HandleTutorialReadinessChanged;
        tutorialSubscribed = true;
        RefreshNamingEligibility();
    }

    private void UnsubscribeFromTutorial()
    {
        if (!tutorialSubscribed || tutorialController == null)
            return;

        tutorialController.StateChanged -=
            HandleTutorialStateChanged;
        tutorialController.TutorialCompleted -=
            HandleTutorialCompleted;
        tutorialController.ReadinessChanged -=
            HandleTutorialReadinessChanged;
        tutorialSubscribed = false;
        tutorialController = null;
    }

    private void HandleTutorialStateChanged(
        TutorialProgressState nextState)
    {
        RefreshNamingEligibility();
    }

    private void HandleTutorialCompleted()
    {
        RefreshNamingEligibility();
    }

    private void HandleTutorialReadinessChanged()
    {
        RefreshNamingEligibility();
    }

    private bool IsNamingEligible()
    {
        if (UnityEngine.SceneManagement.SceneManager
                .GetActiveScene().name !=
                SceneNavigationManager.MainBakeryScene ||
            tutorialController == null ||
            !tutorialController.IsReady ||
            !tutorialController.State.IsCompleted ||
            localProfileStatus != CafeProfileLocalStatus.Missing ||
            profileOperationInProgress)
            return false;

        return true;
    }

    private void RefreshNamingEligibility()
    {
        if (restoreGatePending ||
            SweetMerge.Cloud.SimpleCloudFiles.RestorePending ||
            namingRoot == null)
            return;

        bool tutorialCompleted =
            UnityEngine.SceneManagement.SceneManager
                .GetActiveScene().name ==
                SceneNavigationManager.MainBakeryScene &&
            tutorialController != null &&
            tutorialController.IsReady &&
            tutorialController.State.IsCompleted;
        bool profileNeedsRecovery =
            localProfileStatus == CafeProfileLocalStatus.InvalidData ||
            localProfileStatus == CafeProfileLocalStatus.ServiceError;

        if (tutorialCompleted && profileNeedsRecovery)
        {
            if (!namingRoot.activeSelf)
                ShowNamingPopup();
            namingInputStep.SetActive(true);
            namingConfirmationStep.SetActive(false);
            SetText(
                namingErrorText,
                localProfileError ??
                "Local cafe profile needs recovery. Your files were preserved.");
            retryLocalProfileButton.gameObject.SetActive(true);
            SetNamingButtonsInteractable(false);
            retryLocalProfileButton.interactable = true;
            return;
        }

        if (IsNamingEligible())
        {
            if (!namingRoot.activeSelf)
                ShowNamingPopup();
            return;
        }

        namingRoot.SetActive(false);
    }

    private void SetNamingButtonsInteractable(bool interactable)
    {
        if (namingInput != null)
            namingInput.interactable = interactable;
        if (namingContinueButton != null)
            namingContinueButton.interactable = interactable;
        if (namingConfirmButton != null)
            namingConfirmButton.interactable = interactable;
        if (retryLocalProfileButton != null)
            retryLocalProfileButton.interactable = interactable;
    }

    private void SetNamingError(string message)
    {
        namingInputStep.SetActive(true);
        namingConfirmationStep.SetActive(false);
        SetText(namingErrorText, message);
    }

    private void Open()
    {
        TryBindManagers();
        Refresh();
        if (panelRoot != null)
            panelRoot.SetActive(true);
    }

    private void Close()
    {
        if (panelRoot != null)
            panelRoot.SetActive(false);
        CloseNamingPopup();
    }

    private void TryBindManagers()
    {
        PlayerProgressionManager currentProgression =
            PlayerProgressionManager.Instance;
        if (currentProgression != progressionManager)
        {
            UnbindManagers();
            progressionManager = currentProgression;
            economyManager = EconomyManager.Instance;

            if (progressionManager != null)
                progressionManager.RebirthProgressionChanged += Refresh;
            if (economyManager != null)
                economyManager.CashChanged += HandleCashChanged;
        }
        else if (economyManager == null)
        {
            economyManager = EconomyManager.Instance;
            if (economyManager != null)
                economyManager.CashChanged += HandleCashChanged;
        }
    }

    private void UnbindManagers()
    {
        if (progressionManager != null)
            progressionManager.RebirthProgressionChanged -= Refresh;
        if (economyManager != null)
            economyManager.CashChanged -= HandleCashChanged;
        progressionManager = null;
        economyManager = null;
    }

    private void HandleCashChanged(int unusedCash)
    {
        Refresh();
    }

    private void Refresh()
    {
        string title = "Cafe Title Unavailable";
        int starLevel = 0;
        if (progressionManager != null)
        {
            progressionManager.TryGetCafeTitle(out title);
            progressionManager.TryGetCafeStarLevel(out starLevel);
        }

        string stars = BuildStars(starLevel);
        SetText(panelNameText, cafeName);
        SetText(panelTitleText, title);
        SetText(panelStarsText, stars);
        SetText(moneyText, economyManager == null
            ? "Money Earned: --"
            : $"Money Earned: ${economyManager.TotalMoneyEarned:N0}");
        SetText(ordersText, economyManager == null
            ? "Orders Completed: --"
            : $"Orders Completed: {economyManager.TotalOrdersCompleted:N0}");
    }

    private string BuildStars(int filledCount)
    {
        filledCount = Mathf.Clamp(filledCount, 0, StarCount);
        string result = string.Empty;
        for (int i = 0; i < StarCount; i++)
            result += i < filledCount ? "<color=#FFD04A>★</color>" :
                $"<color=#{ColorUtility.ToHtmlStringRGB(mutedStarColor)}>☆</color>";
        return result;
    }

    private static GameObject CreateRect(string name, Transform parent)
    {
        GameObject gameObject = new GameObject(name,
            typeof(RectTransform));
        gameObject.transform.SetParent(parent, false);
        return gameObject;
    }

    private static void SetFullRect(GameObject gameObject)
    {
        RectTransform rect = gameObject.GetComponent<RectTransform>();
        rect.anchorMin = Vector2.zero;
        rect.anchorMax = Vector2.one;
        rect.offsetMin = Vector2.zero;
        rect.offsetMax = Vector2.zero;
    }

    private static void SetAnchors(GameObject gameObject, Vector2 anchorMin,
        Vector2 anchorMax, Vector2 offsetMin, Vector2 offsetMax)
    {
        RectTransform rect = gameObject.GetComponent<RectTransform>();
        rect.anchorMin = anchorMin;
        rect.anchorMax = anchorMax;
        rect.offsetMin = offsetMin;
        rect.offsetMax = offsetMax;
    }

    private static TMP_Text CreateText(Transform parent, string name,
        float fontSize, TextAlignmentOptions alignment, Color color)
    {
        GameObject gameObject = CreateRect(name, parent);
        TMP_Text text = gameObject.AddComponent<TextMeshProUGUI>();
        text.fontSize = fontSize;
        text.alignment = alignment;
        text.color = color;
        text.textWrappingMode = TextWrappingModes.NoWrap;
        text.raycastTarget = false;
        return text;
    }

    private static TMP_Text CreateTextBlock(
        Transform parent,
        string name,
        string value,
        float fontSize,
        Vector2 anchorMin,
        Vector2 anchorMax)
    {
        TMP_Text text = CreateText(
            parent,
            name,
            fontSize,
            TextAlignmentOptions.Center,
            Color.white);
        text.text = value;
        SetAnchors(text.gameObject, anchorMin, anchorMax,
            Vector2.zero, Vector2.zero);
        return text;
    }

    private static TMP_InputField CreateInputField(
        Transform parent,
        Vector2 anchorMin,
        Vector2 anchorMax)
    {
        GameObject inputObject = CreateRect("CafeNameInput", parent);
        SetAnchors(inputObject, anchorMin, anchorMax,
            Vector2.zero, Vector2.zero);
        Image background = inputObject.AddComponent<Image>();
        background.color = new Color(1f, 1f, 1f, 0.12f);
        TMP_InputField input = inputObject.AddComponent<TMP_InputField>();

        TMP_Text text = CreateText(
            inputObject.transform,
            "Text",
            22f,
            TextAlignmentOptions.Left,
            Color.white);
        SetAnchors(text.gameObject, Vector2.zero, Vector2.one,
            new Vector2(16f, 4f), new Vector2(-16f, -4f));
        input.textComponent = text;

        TMP_Text placeholder = CreateText(
            inputObject.transform,
            "Placeholder",
            20f,
            TextAlignmentOptions.Left,
            new Color(1f, 1f, 1f, 0.5f));
        placeholder.text = "Cafe name";
        SetAnchors(placeholder.gameObject, Vector2.zero, Vector2.one,
            new Vector2(16f, 4f), new Vector2(-16f, -4f));
        input.placeholder = placeholder;
        input.targetGraphic = background;
        return input;
    }

    private static void CreatePlaceholder(Transform parent, Vector2 position,
        float size)
    {
        GameObject imageObject = CreateRect("CafeImagePlaceholder", parent);
        RectTransform rect = imageObject.GetComponent<RectTransform>();
        rect.anchorMin = new Vector2(0.5f, 0.5f);
        rect.anchorMax = new Vector2(0.5f, 0.5f);
        rect.sizeDelta = new Vector2(size, size);
        rect.anchoredPosition = position;
        Image image = imageObject.AddComponent<Image>();
        image.color = new Color(0.82f, 0.48f, 0.3f, 1f);

        TMP_Text label = CreateText(imageObject.transform, "PlaceholderLabel",
            size * 0.18f, TextAlignmentOptions.Center, Color.white);
        SetFullRect(label.gameObject);
        label.text = "CAFE";
    }

    private static Button CreateButton(Transform parent, string name,
        string label, Vector2 anchorMin, Vector2 anchorMax)
    {
        GameObject buttonObject = CreateRect(name, parent);
        SetAnchors(buttonObject, anchorMin, anchorMax, Vector2.zero, Vector2.zero);
        Image image = buttonObject.AddComponent<Image>();
        image.color = new Color(0.75f, 0.42f, 0.2f, 1f);
        Button button = buttonObject.AddComponent<Button>();
        button.targetGraphic = image;
        TMP_Text text = CreateText(buttonObject.transform, "Label", 20f,
            TextAlignmentOptions.Center, Color.white);
        text.text = label;
        SetFullRect(text.gameObject);
        return button;
    }

    private static void SetText(TMP_Text text, string value)
    {
        if (text != null)
            text.text = value;
    }
}
