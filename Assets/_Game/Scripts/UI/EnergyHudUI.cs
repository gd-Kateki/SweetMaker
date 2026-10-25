using System;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public sealed class EnergyHudUI : MonoBehaviour
{
    private const float RefreshInterval = 0.25f;
    private const float MaximumEnergy = 30f;

    private PlayerProgressionManager progressionManager;
    private RectTransform hudRoot;
    private TMP_Text energyText;
    private TMP_Text countdownText;
    private float nextRefreshTime;
    private bool missingProgressionReported;

    private void OnEnable()
    {
        BindProgressionManager();
        if (hudRoot != null)
            hudRoot.gameObject.SetActive(true);
        Refresh();
    }

    private void Start()
    {
        BuildHud();
        BindProgressionManager();
        Refresh();
    }

    private void Update()
    {
        if (Time.unscaledTime < nextRefreshTime)
            return;

        nextRefreshTime = Time.unscaledTime + RefreshInterval;
        if (progressionManager == null)
            BindProgressionManager();

        Refresh();
    }

    private void OnDisable()
    {
        UnbindProgressionManager();
        if (hudRoot != null)
            hudRoot.gameObject.SetActive(false);
    }

    private void OnDestroy()
    {
        UnbindProgressionManager();
    }

    private void BindProgressionManager()
    {
        PlayerProgressionManager current =
            PlayerProgressionManager.Instance;
        if (current == progressionManager)
            return;

        UnbindProgressionManager();
        progressionManager = current;
        if (progressionManager == null)
        {
            if (!missingProgressionReported)
            {
                Debug.LogError(
                    "EnergyHudUI: PlayerProgressionManager is unavailable.");
                missingProgressionReported = true;
            }

            return;
        }

        missingProgressionReported = false;
        progressionManager.EnergyChanged += HandleEnergyChanged;
    }

    private void UnbindProgressionManager()
    {
        if (progressionManager != null)
            progressionManager.EnergyChanged -= HandleEnergyChanged;
        progressionManager = null;
    }

    private void HandleEnergyChanged()
    {
        Refresh();
    }

    private void BuildHud()
    {
        if (hudRoot != null)
            return;

        GameObject cashDisplay = GameObject.Find("CashDisplay");
        TMP_Text cashText = cashDisplay != null
            ? cashDisplay.GetComponent<TMP_Text>()
            : null;
        if (cashDisplay == null ||
            cashDisplay.transform.parent != transform ||
            cashText == null)
        {
            Debug.LogError(
                "EnergyHudUI: CashDisplay must be a TMP child of GameplayCanvas.");
            enabled = false;
            return;
        }

        GameObject root = new GameObject(
            "EnergyHUD",
            typeof(RectTransform));
        hudRoot = root.GetComponent<RectTransform>();
        hudRoot.SetParent(cashDisplay.transform, false);
        hudRoot.anchorMin = hudRoot.anchorMax =
            new Vector2(0f, 0.5f);
        hudRoot.pivot = new Vector2(1f, 0.5f);
        hudRoot.anchoredPosition = new Vector2(-8f, 0f);
        hudRoot.sizeDelta = new Vector2(245f, 64f);
        hudRoot.SetAsFirstSibling();

        energyText = CreateText(
            "EnergyValue",
            hudRoot,
            cashText,
            25f,
            TextAlignmentOptions.MidlineLeft);
        SetAnchors(
            energyText.rectTransform,
            new Vector2(0f, 0.42f),
            Vector2.one,
            Vector2.zero,
            new Vector2(-48f, 0f));

        countdownText = CreateText(
            "EnergyCountdown",
            hudRoot,
            cashText,
            15f,
            TextAlignmentOptions.MidlineLeft);
        SetAnchors(
            countdownText.rectTransform,
            Vector2.zero,
            new Vector2(1f, 0.42f),
            Vector2.zero,
            new Vector2(-48f, 0f));

        GameObject plusObject = new GameObject(
            "EnergyPlusPlaceholder",
            typeof(RectTransform),
            typeof(CanvasRenderer),
            typeof(Image),
            typeof(Button));
        RectTransform plusRect = plusObject.GetComponent<RectTransform>();
        plusRect.SetParent(hudRoot, false);
        plusRect.anchorMin = plusRect.anchorMax =
            new Vector2(1f, 0.5f);
        plusRect.pivot = new Vector2(1f, 0.5f);
        plusRect.anchoredPosition = new Vector2(-2f, 8f);
        plusRect.sizeDelta = new Vector2(38f, 38f);

        Image plusImage = plusObject.GetComponent<Image>();
        plusImage.color = new Color(0.32f, 0.25f, 0.4f, 0.65f);
        plusImage.raycastTarget = false;

        Button plusButton = plusObject.GetComponent<Button>();
        plusButton.interactable = false;
        plusButton.targetGraphic = plusImage;
        plusButton.transition = Selectable.Transition.None;
        plusButton.navigation = new Navigation
        {
            mode = Navigation.Mode.None
        };

        TMP_Text plusText = CreateText(
            "Label",
            plusRect,
            cashText,
            25f,
            TextAlignmentOptions.Center);
        SetAnchors(
            plusText.rectTransform,
            Vector2.zero,
            Vector2.one,
            Vector2.zero,
            Vector2.zero);
        plusText.text = "+";
    }

    private static TMP_Text CreateText(
        string objectName,
        Transform parent,
        TMP_Text styleSource,
        float fontSize,
        TextAlignmentOptions alignment)
    {
        GameObject textObject = new GameObject(
            objectName,
            typeof(RectTransform),
            typeof(CanvasRenderer),
            typeof(TextMeshProUGUI));
        textObject.transform.SetParent(parent, false);

        TextMeshProUGUI text =
            textObject.GetComponent<TextMeshProUGUI>();
        text.font = styleSource.font;
        text.fontSharedMaterial = styleSource.fontSharedMaterial;
        text.color = styleSource.color;
        text.fontSize = fontSize;
        text.alignment = alignment;
        text.raycastTarget = false;
        text.textWrappingMode = TextWrappingModes.NoWrap;
        return text;
    }

    private static void SetAnchors(
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

    private void Refresh()
    {
        if (energyText == null ||
            countdownText == null ||
            progressionManager == null)
        {
            return;
        }

        int currentEnergy = progressionManager.CurrentEnergy;
        int maximumEnergy = progressionManager.MaximumEnergy;
        energyText.text =
            $"ENERGY  {currentEnergy}/{maximumEnergy}";

        bool isFull = currentEnergy >= maximumEnergy;
        countdownText.gameObject.SetActive(!isFull);
        if (!isFull)
        {
            int remainingSeconds = Mathf.Clamp(
                Mathf.CeilToInt(progressionManager.SecondsUntilNextEnergy),
                0,
                (int)MaximumEnergy * 60);
            countdownText.text =
                "Next +1  " +
                TimeSpan.FromSeconds(remainingSeconds).ToString(@"m\:ss");
        }
    }
}
