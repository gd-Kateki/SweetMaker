using System.Collections.Generic;
using System.Linq;
using TMPro;
using UnityEngine;
using UnityEngine.Events;
using UnityEngine.UI;

public sealed class SpawnPoolSelectorUI : MonoBehaviour
{
    private const int PoolCount = 6;

    [SerializeField]
    private Button selectorButtonReference;

    [SerializeField]
    private TMP_Text selectorTextReference;

    [Header("Serialized Selection Panel")]
    [SerializeField]
    private RectTransform selectionPanelRect;

    [SerializeField]
    private Image selectionPanelBackground;

    [SerializeField]
    private TMP_Text selectionPanelTitle;

    [SerializeField]
    private Button closeButton;

    [SerializeField]
    private Image closeButtonBackground;

    [SerializeField]
    private TMP_Text closeButtonLabel;

    [SerializeField]
    private Button[] tierButtons = new Button[PoolCount];

    [SerializeField]
    private Image[] tierCardBackgrounds = new Image[PoolCount];

    [SerializeField]
    private TMP_Text[] tierCardLabels = new TMP_Text[PoolCount];

    private DessertSpawner dessertSpawner;
    private OrderDetailsUI orderDetailsUI;
    private Canvas gameplayCanvas;
    private RectTransform canvasRect;
    private RectTransform selectorButtonRect;
    private Button selectorButton;
    private TMP_Text selectorText;
    private IReadOnlyList<string> unlockedPoolIds;
    private UnityAction[] tierButtonListeners;
    private Vector3 authoredPanelScale;
    private bool hasCapturedPanelScale;
    private Rect lastObservedSafeArea;
    private Vector2 lastObservedCanvasSize;
    private int lastObservedScreenWidth;
    private int lastObservedScreenHeight;
    private bool hasObservedScreenLayout;
    private bool controlsVisible = true;
    private bool selectionPanelOpen;
    private bool tableModalOpen;

    public bool ControlsVisible => controlsVisible;

    public void SetControlsVisible(bool visible)
    {
        controlsVisible = visible;
        selectionPanelOpen = false;
        RestorePanelScale();
        ApplyVisibility();
    }

    private void OnEnable()
    {
        if (dessertSpawner != null)
        {
            dessertSpawner.SpawnPoolChanged += HandleSpawnPoolChanged;
            if (selectorButtonRect != null)
                Refresh();
        }
        ApplyVisibility();
    }

    private void Start()
    {
        dessertSpawner = FindAnyObjectByType<DessertSpawner>();
        orderDetailsUI = FindAnyObjectByType<OrderDetailsUI>();
        tableModalOpen = orderDetailsUI != null && orderDetailsUI.IsOpen;
        gameplayCanvas = FindAnyObjectByType<Canvas>();
        if (dessertSpawner == null || gameplayCanvas == null)
        {
            Debug.LogError(
                "SPAWN POOL UI | DessertSpawner or gameplay Canvas is unavailable.");
            enabled = false;
            return;
        }

        gameplayCanvas = gameplayCanvas.rootCanvas;
        canvasRect = gameplayCanvas.transform as RectTransform;
        if (canvasRect == null ||
            gameplayCanvas.renderMode != RenderMode.ScreenSpaceOverlay)
        {
            Debug.LogError(
                "SPAWN POOL UI | A Screen Space Overlay Canvas is required.");
            enabled = false;
            return;
        }

        if (selectorButtonReference == null)
        {
            Debug.LogError(
                "SPAWN POOL UI | Serialized Oven Tier selector button is missing.",
                this);
            enabled = false;
            return;
        }

        selectorButton = selectorButtonReference;
        selectorButtonRect = selectorButton.transform as RectTransform;
        if (selectorButtonRect == null ||
            selectorButton.transform.parent != gameplayCanvas.transform)
        {
            Debug.LogError(
                "SPAWN POOL UI | Oven Tier selector button must be a RectTransform child of GameplayCanvas.",
                this);
            enabled = false;
            return;
        }

        selectorText = selectorTextReference;
        if (selectorText == null ||
            selectionPanelRect == null ||
            selectionPanelRect.parent != gameplayCanvas.transform ||
            selectionPanelBackground == null ||
            selectionPanelBackground.transform != selectionPanelRect ||
            selectionPanelTitle == null ||
            closeButton == null ||
            closeButtonBackground == null ||
            closeButtonBackground.transform != closeButton.transform ||
            closeButtonLabel == null ||
            tierButtons == null ||
            tierButtons.Length != PoolCount ||
            tierCardBackgrounds == null ||
            tierCardBackgrounds.Length != PoolCount ||
            tierCardLabels == null ||
            tierCardLabels.Length != PoolCount)
        {
            Debug.LogError(
                "SPAWN POOL UI | Serialized selection panel references are incomplete.",
                this);
            enabled = false;
            return;
        }

        if (closeButtonLabel.transform.parent != closeButton.transform)
        {
            Debug.LogError(
                "SPAWN POOL UI | Close label must be a child of the Close button.",
                this);
            enabled = false;
            return;
        }

        if (closeButton.transform.parent != selectionPanelRect ||
            selectionPanelTitle.transform.parent != selectionPanelRect)
        {
            Debug.LogError(
                "SPAWN POOL UI | Close button and title must be children of the selection panel.",
                this);
            enabled = false;
            return;
        }

        for (int i = 0; i < PoolCount; i++)
        {
            if (tierButtons[i] == null ||
                tierCardBackgrounds[i] == null ||
                tierButtons[i].transform.parent != selectionPanelRect ||
                tierCardBackgrounds[i].transform != tierButtons[i].transform ||
                tierCardLabels[i] == null ||
                tierCardLabels[i].transform.parent != tierButtons[i].transform)
            {
                Debug.LogError(
                    $"SPAWN POOL UI | Serialized pool card {i + 1} references are incomplete.",
                    this);
                enabled = false;
                return;
            }
        }

        selectionPanelTitle.text = "Select Oven Tier";
        closeButtonLabel.text = "X";
        authoredPanelScale = selectionPanelRect.localScale;
        hasCapturedPanelScale = true;
        CaptureScreenLayout();
        selectionPanelOpen = false;
        ApplyVisibility();
        selectorButton.onClick.RemoveListener(OpenSelectionPanel);
        selectorButton.onClick.AddListener(OpenSelectionPanel);
        closeButton.onClick.RemoveListener(CloseSelectionPanel);
        dessertSpawner.SpawnPoolChanged += HandleSpawnPoolChanged;
        closeButton.onClick.AddListener(CloseSelectionPanel);
        tierButtonListeners = new UnityAction[PoolCount];
        for (int i = 0; i < PoolCount; i++)
        {
            int poolIndex = i;
            tierButtonListeners[i] = () => SelectPool(poolIndex);
            tierButtons[i].onClick.RemoveListener(tierButtonListeners[i]);
            tierButtons[i].onClick.AddListener(tierButtonListeners[i]);
        }
        Refresh();
    }

    private void OnDestroy()
    {
        if (selectorButton != null)
            selectorButton.onClick.RemoveListener(OpenSelectionPanel);
        if (closeButton != null)
            closeButton.onClick.RemoveListener(CloseSelectionPanel);
        if (tierButtons != null && tierButtonListeners != null)
        {
            for (int i = 0; i < tierButtons.Length &&
                            i < tierButtonListeners.Length; i++)
            {
                if (tierButtons[i] != null)
                    tierButtons[i].onClick.RemoveListener(
                        tierButtonListeners[i]);
            }
        }
        if (dessertSpawner != null)
            dessertSpawner.SpawnPoolChanged -= HandleSpawnPoolChanged;
    }

    private void OnDisable()
    {
        if (dessertSpawner != null)
            dessertSpawner.SpawnPoolChanged -= HandleSpawnPoolChanged;
        selectionPanelOpen = false;
        RestorePanelScale();
        ApplyVisibility();
    }

    private void Update()
    {
        bool modalOpen = orderDetailsUI != null && orderDetailsUI.IsOpen;
        if (modalOpen != tableModalOpen)
        {
            tableModalOpen = modalOpen;
            if (tableModalOpen)
            {
                selectionPanelOpen = false;
                RestorePanelScale();
            }
            ApplyVisibility();
        }

        if (HasScreenLayoutChanged() && selectionPanelOpen)
            ClampPanelToSafeArea();
    }

    private void HandleSpawnPoolChanged(string poolId, int firstTier, int highestTier)
    {
        Refresh();
    }

    private void OnApplicationFocus(bool hasFocus)
    {
        if (hasFocus && selectionPanelOpen)
            ClampPanelToSafeArea();
    }

    private void OnApplicationPause(bool isPaused)
    {
        if (!isPaused && selectionPanelOpen)
            ClampPanelToSafeArea();
    }

    private void Refresh()
    {
        if (dessertSpawner == null || selectorButtonRect == null)
            return;

        unlockedPoolIds = dessertSpawner.UnlockedSpawnPoolIds;
        string selectedPoolId = dessertSpawner.SelectedSpawnPoolId;
        int selectedIndex = IndexOfPool(selectedPoolId);
        selectorText.text = $"OVEN TIER {selectedIndex + 1}  v";

        for (int i = 0; i < PoolCount; i++)
        {
            string poolId = $"P{i + 1}";
            int firstTier = DessertSpawner.GetSpawnPoolFirstTier(poolId);
            int highestTier = DessertSpawner.GetSpawnPoolHighestTier(poolId);
            bool isSelected = poolId == selectedPoolId;
            bool isUnlocked = unlockedPoolIds.Contains(poolId);
            tierButtons[i].interactable = isUnlocked &&
                                          CanInteractWithSelector();
            tierCardLabels[i].text =
                $"Oven Tier {i + 1}\n" +
                $"Dessert T{firstTier}-T{highestTier}\n" +
                (isSelected ? "Selected" : isUnlocked ? "Available" : "Locked");
            tierCardLabels[i].color = isSelected
                ? new Color(0.24f, 0.14f, 0.08f, 1f)
                : Color.white;
            tierCardBackgrounds[i].color = isSelected
                ? new Color(0.94f, 0.69f, 0.31f, 1f)
                : isUnlocked
                    ? new Color(0.59f, 0.36f, 0.20f, 1f)
                    : new Color(0.32f, 0.29f, 0.27f, 1f);
        }
    }

    private static int IndexOfPool(string poolId)
    {
        return int.TryParse(poolId != null && poolId.Length > 1
                ? poolId.Substring(1)
                : string.Empty,
            out int tier)
            ? tier - 1
            : 0;
    }

    private bool CanInteractWithSelector()
    {
        return isActiveAndEnabled &&
               controlsVisible &&
               !tableModalOpen &&
               (orderDetailsUI == null || !orderDetailsUI.IsOpen) &&
               dessertSpawner != null;
    }

    private void OpenSelectionPanel()
    {
        if (!CanInteractWithSelector() || selectionPanelRect == null)
            return;

        selectionPanelOpen = true;
        ClampPanelToSafeArea();
        ApplyVisibility();
        UiClickSfx.TryPlay(selectorButton);
    }

    private void CloseSelectionPanel()
    {
        selectionPanelOpen = false;
        RestorePanelScale();
        ApplyVisibility();
        UiClickSfx.TryPlay(closeButton);
    }

    private void SelectPool(int index)
    {
        if (!CanInteractWithSelector() ||
            unlockedPoolIds == null ||
            index < 0 ||
            index >= PoolCount)
            return;

        string poolId = $"P{index + 1}";
        if (!unlockedPoolIds.Contains(poolId))
            return;

        if (poolId != dessertSpawner.SelectedSpawnPoolId &&
            dessertSpawner.TrySelectSpawnPool(poolId))
            UiClickSfx.TryPlay(tierButtons[index]);

        selectionPanelOpen = false;
        RestorePanelScale();
        ApplyVisibility();
    }

    private void ApplyVisibility()
    {
        bool visible = controlsVisible && !tableModalOpen &&
                       isActiveAndEnabled;
        if (selectorButtonRect != null)
            selectorButtonRect.gameObject.SetActive(visible);
        if (selectionPanelRect != null)
            selectionPanelRect.gameObject.SetActive(visible && selectionPanelOpen);
    }

    private void ClampPanelToSafeArea()
    {
        if (selectionPanelRect == null ||
            canvasRect == null)
            return;

        if (!TryGetCanvasLocalRect(Screen.safeArea, out Rect usableBounds))
            return;

        Vector3[] corners = new Vector3[4];
        selectionPanelRect.localScale = authoredPanelScale;
        selectionPanelRect.GetWorldCorners(corners);
        Vector2 bottomLeft = canvasRect.InverseTransformPoint(corners[0]);
        Vector2 topRight = canvasRect.InverseTransformPoint(corners[2]);
        Vector2 panelSize = topRight - bottomLeft;
        if (panelSize.x <= 0f || panelSize.y <= 0f)
            return;

        float fitScale = Mathf.Min(
            1f,
            usableBounds.width / panelSize.x,
            usableBounds.height / panelSize.y);
        selectionPanelRect.localScale = authoredPanelScale * fitScale;
        selectionPanelRect.GetWorldCorners(corners);
        bottomLeft = canvasRect.InverseTransformPoint(corners[0]);
        topRight = canvasRect.InverseTransformPoint(corners[2]);
        Vector2 offset = Vector2.zero;

        if (bottomLeft.x < usableBounds.xMin)
            offset.x = usableBounds.xMin - bottomLeft.x;
        else if (topRight.x > usableBounds.xMax)
            offset.x = usableBounds.xMax - topRight.x;

        if (bottomLeft.y < usableBounds.yMin)
            offset.y = usableBounds.yMin - bottomLeft.y;
        else if (topRight.y > usableBounds.yMax)
            offset.y = usableBounds.yMax - topRight.y;

        if (bottomLeft.x < usableBounds.xMin ||
            topRight.x > usableBounds.xMax ||
            bottomLeft.y < usableBounds.yMin ||
            topRight.y > usableBounds.yMax)
        {
            selectionPanelRect.position += canvasRect.TransformVector(offset);
        }
    }

    private void RestorePanelScale()
    {
        if (selectionPanelRect != null && hasCapturedPanelScale)
            selectionPanelRect.localScale = authoredPanelScale;
    }

    public static bool TryCalculateSelectorBounds(
        Rect previewBounds,
        Rect usableBounds,
        Vector2 panelSize,
        float gap,
        out Rect selectorBounds)
    {
        selectorBounds = default;
        if (panelSize.x <= 0f ||
            panelSize.y <= 0f ||
            gap < 0f ||
            usableBounds.width < panelSize.x)
            return false;

        float halfWidth = panelSize.x * 0.5f;
        float bottom = previewBounds.yMin - gap - panelSize.y;
        if (bottom < usableBounds.yMin ||
            previewBounds.yMin - gap > usableBounds.yMax)
            return false;

        float centerX = Mathf.Clamp(
            previewBounds.center.x,
            usableBounds.xMin + halfWidth,
            usableBounds.xMax - halfWidth);
        selectorBounds = new Rect(
            centerX - halfWidth,
            bottom,
            panelSize.x,
            panelSize.y);
        return true;
    }

    private bool HasScreenLayoutChanged()
    {
        bool changed = !hasObservedScreenLayout ||
                       Screen.width != lastObservedScreenWidth ||
                       Screen.height != lastObservedScreenHeight ||
                       Screen.safeArea != lastObservedSafeArea ||
                       canvasRect.rect.size != lastObservedCanvasSize;
        if (changed)
            CaptureScreenLayout();
        return changed;
    }

    private void CaptureScreenLayout()
    {
        lastObservedScreenWidth = Screen.width;
        lastObservedScreenHeight = Screen.height;
        lastObservedSafeArea = Screen.safeArea;
        lastObservedCanvasSize = canvasRect.rect.size;
        hasObservedScreenLayout = true;
    }

    private bool TryGetCanvasLocalRect(
        Rect screenRect,
        out Rect localRect)
    {
        Vector2 screenMin = new Vector2(screenRect.xMin, screenRect.yMin);
        Vector2 screenMax = new Vector2(screenRect.xMax, screenRect.yMax);
        if (!RectTransformUtility.ScreenPointToLocalPointInRectangle(
                canvasRect, screenMin, null, out Vector2 localMin) ||
            !RectTransformUtility.ScreenPointToLocalPointInRectangle(
                canvasRect, screenMax, null, out Vector2 localMax))
        {
            localRect = default;
            return false;
        }

        localRect = Rect.MinMaxRect(
            Mathf.Min(localMin.x, localMax.x),
            Mathf.Min(localMin.y, localMax.y),
            Mathf.Max(localMin.x, localMax.x),
            Mathf.Max(localMin.y, localMax.y));
        return true;
    }
}
