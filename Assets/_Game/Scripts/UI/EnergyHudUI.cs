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

    [SerializeField]
    private Button plusButton;

    [SerializeField]
    private TMP_Text plusText;

    private PlayerProgressionManager progressionManager;
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
        if (!ValidateHud())
        {
            enabled = false;
            return;
        }

        plusButton.gameObject.SetActive(true);
        plusButton.interactable = true;
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

    private bool ValidateHud()
    {
        if (hudRoot != null &&
            hudBackground != null &&
            energyText != null &&
            countdownText != null &&
            plusButton != null &&
            plusText != null)
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

        int currentEnergy = progressionManager.CurrentEnergy;
        int maximumEnergy = progressionManager.MaximumEnergy;
        energyText.text =
            $"{currentEnergy}/{maximumEnergy}";

        bool isFull = currentEnergy >= maximumEnergy;
        countdownText.gameObject.SetActive(!isFull);
        if (!isFull)
        {
            int remainingSeconds = Mathf.Clamp(
                Mathf.CeilToInt(progressionManager.SecondsUntilNextEnergy),
                0,
                progressionManager.MaximumEnergy * 60);
            countdownText.text =
                "Next +1  " +
                TimeSpan.FromSeconds(remainingSeconds).ToString(@"m\:ss");
        }
    }
}
