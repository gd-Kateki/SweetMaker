using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public sealed class SpawnPoolSelectorUI : MonoBehaviour
{
    private const float PanelWidth = 260f;
    private const float PanelHeight = 64f;

    [SerializeField]
    private Transform previewAnchor;

    private DessertSpawner dessertSpawner;
    private Canvas gameplayCanvas;
    private RectTransform panel;
    private Button previousButton;
    private Button nextButton;
    private TMP_Text poolText;
    private IReadOnlyList<string> unlockedPoolIds;

    private void Start()
    {
        dessertSpawner = FindAnyObjectByType<DessertSpawner>();
        gameplayCanvas = FindAnyObjectByType<Canvas>();
        if (dessertSpawner == null || gameplayCanvas == null)
        {
            Debug.LogError(
                "SPAWN POOL UI | DessertSpawner or gameplay Canvas is unavailable.");
            enabled = false;
            return;
        }

        CreateControls();
        dessertSpawner.SpawnPoolChanged += HandleSpawnPoolChanged;
        Refresh();
    }

    private void OnDestroy()
    {
        if (dessertSpawner != null)
            dessertSpawner.SpawnPoolChanged -= HandleSpawnPoolChanged;
    }

    private void Update()
    {
        UpdatePosition();
    }

    private void HandleSpawnPoolChanged(string poolId, int firstTier, int highestTier)
    {
        Refresh();
    }

    private void CreateControls()
    {
        GameObject panelObject = new GameObject(
            "SpawnPoolSelector",
            typeof(RectTransform),
            typeof(Image));
        panel = panelObject.GetComponent<RectTransform>();
        panel.SetParent(gameplayCanvas.transform, false);
        panel.anchorMin = panel.anchorMax = new Vector2(0.5f, 0.5f);
        panel.pivot = new Vector2(0.5f, 0.5f);
        panel.sizeDelta = new Vector2(PanelWidth, PanelHeight);
        Image panelImage = panelObject.GetComponent<Image>();
        panelImage.raycastTarget = false;
        panelImage.color =
            new Color(0.16f, 0.12f, 0.2f, 0.9f);

        previousButton = CreateButton(panel, "PreviousPoolButton", "<");
        RectTransform previousRect = previousButton.GetComponent<RectTransform>();
        previousRect.anchorMin = previousRect.anchorMax = new Vector2(0, 0.5f);
        previousRect.pivot = new Vector2(0, 0.5f);
        previousRect.anchoredPosition = new Vector2(5f, 0);
        previousRect.sizeDelta = new Vector2(44f, 52f);
        previousButton.onClick.AddListener(SelectPreviousPool);

        nextButton = CreateButton(panel, "NextPoolButton", ">");
        RectTransform nextRect = nextButton.GetComponent<RectTransform>();
        nextRect.anchorMin = nextRect.anchorMax = new Vector2(1, 0.5f);
        nextRect.pivot = new Vector2(1, 0.5f);
        nextRect.anchoredPosition = new Vector2(-5f, 0);
        nextRect.sizeDelta = new Vector2(44f, 52f);
        nextButton.onClick.AddListener(SelectNextPool);

        poolText = CreateText(panel, "SelectedPoolLabel", 20f);
        RectTransform poolRect = poolText.rectTransform;
        poolRect.anchorMin = poolRect.anchorMax = new Vector2(0.5f, 0.5f);
        poolRect.pivot = new Vector2(0.5f, 0.5f);
        poolRect.anchoredPosition = Vector2.zero;
        poolRect.sizeDelta = new Vector2(156f, 46f);
    }

    private static Button CreateButton(Transform parent, string objectName, string label)
    {
        GameObject buttonObject = new GameObject(
            objectName,
            typeof(RectTransform),
            typeof(Image),
            typeof(Button));
        buttonObject.transform.SetParent(parent, false);
        Image image = buttonObject.GetComponent<Image>();
        image.color = new Color(0.43f, 0.27f, 0.48f, 1f);
        Button button = buttonObject.GetComponent<Button>();
        button.targetGraphic = image;

        TMP_Text text = CreateText(buttonObject.transform, "Label", 23f);
        text.text = label;
        RectTransform textRect = text.rectTransform;
        textRect.anchorMin = Vector2.zero;
        textRect.anchorMax = Vector2.one;
        textRect.offsetMin = Vector2.zero;
        textRect.offsetMax = Vector2.zero;
        return button;
    }

    private static TMP_Text CreateText(Transform parent, string objectName, float fontSize)
    {
        GameObject textObject = new GameObject(objectName, typeof(RectTransform));
        textObject.transform.SetParent(parent, false);
        TMP_Text text = textObject.AddComponent<TextMeshProUGUI>();
        text.font = TMP_Settings.defaultFontAsset;
        text.fontSize = fontSize;
        text.alignment = TextAlignmentOptions.Center;
        text.color = Color.white;
        text.raycastTarget = false;
        return text;
    }

    private void Refresh()
    {
        if (dessertSpawner == null || panel == null)
            return;

        unlockedPoolIds = dessertSpawner.UnlockedSpawnPoolIds;
        string selectedPoolId = dessertSpawner.SelectedSpawnPoolId;
        poolText.text =
            $"{selectedPoolId} | T{DessertSpawner.GetSpawnPoolFirstTier(selectedPoolId)}" +
            $"-T{DessertSpawner.GetSpawnPoolHighestTier(selectedPoolId)}";
        int selectedIndex = IndexOfSelectedPool();
        previousButton.interactable = unlockedPoolIds.Count > 1;
        nextButton.interactable = unlockedPoolIds.Count > 1;
        UpdatePosition();
    }

    private int IndexOfSelectedPool()
    {
        for (int i = 0; i < unlockedPoolIds.Count; i++)
            if (unlockedPoolIds[i] == dessertSpawner.SelectedSpawnPoolId)
                return i;
        return -1;
    }

    private void SelectPreviousPool()
    {
        if (unlockedPoolIds == null || unlockedPoolIds.Count < 2)
            return;

        int targetIndex = (IndexOfSelectedPool() - 1 + unlockedPoolIds.Count) %
                          unlockedPoolIds.Count;
        if (targetIndex >= 0)
            dessertSpawner.TrySelectSpawnPool(unlockedPoolIds[targetIndex]);
    }

    private void SelectNextPool()
    {
        if (unlockedPoolIds == null || unlockedPoolIds.Count < 2)
            return;

        int targetIndex = (IndexOfSelectedPool() + 1) % unlockedPoolIds.Count;
        if (targetIndex >= 0)
            dessertSpawner.TrySelectSpawnPool(unlockedPoolIds[targetIndex]);
    }

    private void UpdatePosition()
    {
        if (panel == null || gameplayCanvas == null)
            return;

        Camera gameCamera = Camera.main;
        if (gameCamera == null)
            return;

        Transform anchor = previewAnchor != null ? previewAnchor : transform;
        Vector2 screenPoint = RectTransformUtility.WorldToScreenPoint(
            gameCamera,
            anchor.position);
        screenPoint.x += 250f;
        screenPoint.y -= 105f;
        RectTransform canvasRect = gameplayCanvas.transform as RectTransform;
        if (canvasRect == null ||
            !RectTransformUtility.ScreenPointToLocalPointInRectangle(
                canvasRect,
                screenPoint,
                null,
                out Vector2 localPoint))
            return;

        Vector2 halfSize = canvasRect.rect.size * 0.5f;
        localPoint.x = Mathf.Clamp(
            localPoint.x,
            -halfSize.x + PanelWidth * 0.5f,
            halfSize.x - PanelWidth * 0.5f);
        localPoint.y = Mathf.Clamp(
            localPoint.y,
            -halfSize.y + PanelHeight * 0.5f,
            halfSize.y - PanelHeight * 0.5f);
        panel.anchoredPosition = localPoint;
    }
}
