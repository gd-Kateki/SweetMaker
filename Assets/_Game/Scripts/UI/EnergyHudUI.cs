using System;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public sealed class EnergyHudUI : MonoBehaviour
{
    private const float RefreshInterval = 0.25f;
    [SerializeField]
    private RectTransform hudRoot;

    [SerializeField]
    private Image hudBackground;

    [SerializeField]
    private TMP_Text energyText;

    [SerializeField]
    private TMP_Text countdownText;

    private PlayerProgressionManager progressionManager;
    private float nextRefreshTime;
    private bool missingProgressionReported;
    private TMP_Text cachedEnergyText;
    private TMP_Text cachedCountdownText;
    private int lastDisplayedEnergy;
    private int lastDisplayedMaximumEnergy;
    private string lastEnergyDisplay;
    private bool hasEnergyDisplay;
    private int lastCountdownMinutes;
    private int lastCountdownSeconds;
    private string lastCountdownDisplay;
    private bool hasCountdownDisplay;

    private void OnEnable()
    {
        BindProgressionManager();
        if (hudRoot != null)
            hudRoot.gameObject.SetActive(true);
        Refresh();
    }

    private void Start()
    {
        if (!ValidateHud())
        {
            enabled = false;
            return;
        }

        BindProgressionManager();
        AddEnergyButton();
        Refresh();
    }

    private void AddEnergyButton()
    {
        if (hudRoot == null || hudRoot.Find("EnergyPlus") != null) return;
        var go = new GameObject("EnergyPlus", typeof(RectTransform), typeof(Image), typeof(Button));
        go.transform.SetParent(hudRoot, false);
        var rect = go.GetComponent<RectTransform>();
        rect.anchorMin = rect.anchorMax = new Vector2(1, 0.5f);
        rect.anchoredPosition = new Vector2(-8, 0); rect.sizeDelta = new Vector2(44, 44);
        go.GetComponent<Image>().color = new Color(0.28f, 0.13f, 0.08f);
        var label = new GameObject("Plus", typeof(RectTransform), typeof(TextMeshProUGUI));
        label.transform.SetParent(go.transform, false);
        var labelRect = label.GetComponent<RectTransform>();
        labelRect.anchorMin = Vector2.zero; labelRect.anchorMax = Vector2.one;
        labelRect.offsetMin = labelRect.offsetMax = Vector2.zero;
        var text = label.GetComponent<TextMeshProUGUI>(); text.font = energyText.font;
        text.text = "+"; text.fontSize = 32; text.alignment = TextAlignmentOptions.Center; text.raycastTarget = false;
        go.GetComponent<Button>().onClick.AddListener(() =>
        {
            if (progressionManager != null && progressionManager.CurrentEnergy < progressionManager.MaximumEnergy)
                AdOfferPopup.Show(true, 50);
        });
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
        hasEnergyDisplay = false;
        hasCountdownDisplay = false;
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

    private bool ValidateHud()
    {
        if (hudRoot != null &&
            hudBackground != null &&
            energyText != null &&
            countdownText != null)
        {
            return true;
        }

        Debug.LogError(
            "EnergyHudUI: One or more serialized HUD references are missing.",
            this);
        return false;
    }

    private void Refresh()
    {
        if (energyText == null ||
            countdownText == null ||
            progressionManager == null)
        {
            return;
        }

        if (cachedEnergyText != energyText ||
            cachedCountdownText != countdownText)
        {
            cachedEnergyText = energyText;
            cachedCountdownText = countdownText;
            hasEnergyDisplay = false;
            hasCountdownDisplay = false;
        }

        int currentEnergy = progressionManager.CurrentEnergy;
        int maximumEnergy = progressionManager.MaximumEnergy;
        if (!hasEnergyDisplay ||
            lastDisplayedEnergy != currentEnergy ||
            lastDisplayedMaximumEnergy != maximumEnergy)
        {
            lastEnergyDisplay = $"{currentEnergy}/{maximumEnergy}";
            lastDisplayedEnergy = currentEnergy;
            lastDisplayedMaximumEnergy = maximumEnergy;
            hasEnergyDisplay = true;
        }

        if (energyText.text != lastEnergyDisplay)
            energyText.text = lastEnergyDisplay;

        bool isFull = currentEnergy >= maximumEnergy;
        countdownText.gameObject.SetActive(!isFull);
        if (!isFull)
        {
            int remainingSeconds = Mathf.Clamp(
                Mathf.CeilToInt(progressionManager.SecondsUntilNextEnergy),
                0,
                progressionManager.MaximumEnergy * 60);
            TimeSpan remainingTime = TimeSpan.FromSeconds(remainingSeconds);
            if (!hasCountdownDisplay ||
                lastCountdownMinutes != remainingTime.Minutes ||
                lastCountdownSeconds != remainingTime.Seconds)
            {
                lastCountdownDisplay =
                    "Next +1  " + remainingTime.ToString(@"m\:ss");
                lastCountdownMinutes = remainingTime.Minutes;
                lastCountdownSeconds = remainingTime.Seconds;
                hasCountdownDisplay = true;
            }

            if (countdownText.text != lastCountdownDisplay)
                countdownText.text = lastCountdownDisplay;
        }
    }
}
