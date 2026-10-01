using TMPro;
using UnityEngine;

public class CashUI : MonoBehaviour
{
    [Header("References")]
    [SerializeField]
    private EconomyManager economyManager;

    [SerializeField]
    private TMP_Text cashText;

    private void Start()
    {
        if (economyManager == null)
        {
            economyManager =
                FindFirstObjectByType<EconomyManager>();
        }

        if (cashText == null)
        {
            cashText =
                GetComponent<TMP_Text>();
        }

        if (economyManager == null)
        {
            Debug.LogError(
                "CashUI: EconomyManager " +
                "could not be found."
            );

            return;
        }

        if (cashText == null)
        {
            Debug.LogError(
                "CashUI: TMP_Text is missing."
            );

            return;
        }

        economyManager.CashChanged +=
            HandleCashChanged;

        Refresh();
    }

    private void OnDestroy()
    {
        if (economyManager != null)
        {
            economyManager.CashChanged -=
                HandleCashChanged;
        }
    }

    private void HandleCashChanged(
        int newCash)
    {
        UpdateText(
            newCash
        );
    }

    private void Refresh()
    {
        if (economyManager == null)
            return;

        UpdateText(
            economyManager.CurrentCash
        );
    }

    private void UpdateText(
        int amount)
    {
        if (cashText == null)
            return;

        cashText.text =
            $"${amount:N0}";
    }
}