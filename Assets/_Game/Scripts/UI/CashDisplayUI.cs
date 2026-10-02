using TMPro;
using UnityEngine;

public class CashDisplayUI : MonoBehaviour
{
    [SerializeField]
    private TMP_Text cashText;

    private EconomyManager economyManager;

    private void Start()
    {
        economyManager =
            EconomyManager.Instance;

        if (economyManager == null)
        {
            economyManager =
                FindFirstObjectByType<
                    EconomyManager>();
        }

        if (cashText == null)
        {
            cashText =
                GetComponent<TMP_Text>();
        }

        if (economyManager == null)
        {
            Debug.LogError(
                "CashDisplayUI: " +
                "EconomyManager not found."
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
        int cash)
    {
        SetText(cash);
    }

    public void Refresh()
    {
        if (economyManager == null)
            return;

        SetText(
            economyManager.CurrentCash
        );
    }

    private void SetText(
        int cash)
    {
        if (cashText == null)
            return;

        cashText.text =
            $"${cash:N0}";
    }
}