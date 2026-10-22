using TMPro;
using UnityEngine;
using UnityEngine.UI;

public sealed class RebirthUI : MonoBehaviour
{
    [SerializeField]
    private TMP_Text requirementsText;

    [SerializeField]
    private Button rebirthButton;

    [SerializeField]
    private TMP_Text rebirthButtonText;

    private PlayerProgressionManager progressionManager;
    private EconomyManager economyManager;
    private DessertSpawner dessertSpawner;
    private bool rebirthClickInProgress;

    private void Start()
    {
        ResolveReferences();

        if (progressionManager == null)
        {
            Debug.LogError("REBIRTH UI | PlayerProgressionManager is unavailable.");
            RefreshUnavailable();
            return;
        }

        if (economyManager == null)
        {
            Debug.LogError("REBIRTH UI | EconomyManager is unavailable.");
            RefreshUnavailable();
            return;
        }

        progressionManager.RebirthProgressionChanged += Refresh;
        economyManager.CashChanged += HandleCashChanged;

        if (rebirthButton != null)
            rebirthButton.onClick.AddListener(HandleRebirthClicked);
        else
            Debug.LogError("REBIRTH UI | Rebirth button reference is missing.");

        Refresh();
    }

    private void OnDestroy()
    {
        if (progressionManager != null)
            progressionManager.RebirthProgressionChanged -= Refresh;

        if (economyManager != null)
            economyManager.CashChanged -= HandleCashChanged;

        if (rebirthButton != null)
            rebirthButton.onClick.RemoveListener(HandleRebirthClicked);
    }

    private void ResolveReferences()
    {
        if (progressionManager == null)
            progressionManager = PlayerProgressionManager.Instance;
        if (progressionManager == null)
            progressionManager = FindAnyObjectByType<PlayerProgressionManager>();

        if (economyManager == null)
            economyManager = EconomyManager.Instance;
        if (economyManager == null)
            economyManager = FindAnyObjectByType<EconomyManager>();

        if (dessertSpawner == null)
            dessertSpawner = FindAnyObjectByType<DessertSpawner>();
    }

    private void HandleCashChanged(int cash)
    {
        Refresh();
    }

    private void HandleRebirthClicked()
    {
        if (rebirthClickInProgress || progressionManager == null)
            return;

        rebirthClickInProgress = true;
        if (rebirthButton != null)
            rebirthButton.interactable = false;

        try
        {
            if (!progressionManager.TryRebirth())
                Debug.LogWarning("REBIRTH UI | Rebirth transaction was not completed.");
        }
        finally
        {
            rebirthClickInProgress = false;
            Refresh();
        }
    }

    public void Refresh()
    {
        ResolveReferences();
        if (progressionManager == null || economyManager == null)
        {
            RefreshUnavailable();
            return;
        }

        if (progressionManager.CurrentRebirthCount >= 10)
        {
            if (requirementsText != null)
                requirementsText.text = "All Rebirths Complete";
            SetButtonState(false, "COMPLETE");
            return;
        }

        int requiredTier = progressionManager.NextRebirthRequiredTier;
        int createdTier = progressionManager.HighestTierCreatedThisRun;
        int cashHeld = economyManager.CurrentCash;
        int requiredCash = progressionManager.NextRebirthRequiredCash;

        string requiredDessertName = "Tier " + requiredTier;
        if (dessertSpawner != null)
        {
            DessertDefinition requiredDessert =
                dessertSpawner.GetDefinitionByTier(requiredTier);
            if (requiredDessert != null)
                requiredDessertName = requiredDessert.DisplayName;
        }

        bool tierReady = createdTier >= requiredTier;
        bool cashReady = cashHeld >= requiredCash;
        bool eligible = tierReady && cashReady &&
                        progressionManager.IsEligibleForNextRebirth;

        if (requirementsText != null)
        {
            requirementsText.text =
                $"REBIRTH {progressionManager.NextRebirthNumber}\n" +
                $"Create T{requiredTier} {requiredDessertName}: " +
                $"{FormatTierProgress(createdTier, requiredTier, tierReady)}\n" +
                $"Cash held: ${cashHeld:N0} / ${requiredCash:N0}\n" +
                $"Eligibility: {(eligible ? "READY" : "Requirements incomplete")}";
        }

        SetButtonState(eligible && !rebirthClickInProgress, "REBIRTH");
    }

    private static string FormatTierProgress(int createdTier, int requiredTier, bool tierReady)
    {
        return tierReady
            ? $"T{createdTier} / T{requiredTier} - MET"
            : $"T{createdTier} / T{requiredTier}";
    }

    private void SetButtonState(bool interactable, string label)
    {
        if (rebirthButton != null)
            rebirthButton.interactable = interactable;
        if (rebirthButtonText != null)
            rebirthButtonText.text = label;
    }

    private void RefreshUnavailable()
    {
        if (requirementsText != null)
            requirementsText.text = "Rebirth unavailable";
        SetButtonState(false, "REBIRTH");
    }
}
