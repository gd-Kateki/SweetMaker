using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class CashDisplayUI : MonoBehaviour
{
    [SerializeField]
    private TMP_Text cashText;

    [SerializeField]
    private Graphic cashBackground;

    [SerializeField]
    private Button plusButton;

    private EconomyManager economyManager;

    private void Awake()
    {
        if (!(transform is RectTransform) ||
            !(transform.parent is RectTransform))
        {
            Debug.LogError(
                "CashDisplayUI: CashDisplay must be a RectTransform child of the gameplay Canvas.");
            enabled = false;
            return;
        }

        if (cashText == null)
        {
            Debug.LogError(
                "CashDisplayUI: Serialized cashText reference is missing.",
                this);
            enabled = false;
            return;
        }

        if (cashBackground == null)
        {
            Debug.LogError(
                "CashDisplayUI: Serialized cashBackground reference is missing.",
                this);
            enabled = false;
            return;
        }
    }

    private void Start()
    {
        if (plusButton != null)
        {
            plusButton.gameObject.SetActive(true);
            plusButton.interactable = true;
        }

        economyManager =
            EconomyManager.Instance;

        if (economyManager == null)
        {
            economyManager =
                FindAnyObjectByType<
                    EconomyManager>();
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