using System.Text;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class OrderUI : MonoBehaviour
{
    [Header("References")]
    [SerializeField]
    private OrderManager orderManager;

    [SerializeField]
    private GridManager gridManager;

    [Header("UI")]
    [SerializeField]
    private TMP_Text orderNameText;

    [SerializeField]
    private TMP_Text requirementsText;

    [SerializeField]
    private TMP_Text rewardText;

    [SerializeField]
    private Button fulfillButton;

    private void Start()
    {
        ResolveReferences();

        if (orderManager == null)
        {
            Debug.LogError(
                "OrderUI: OrderManager " +
                "could not be found."
            );

            return;
        }

        if (gridManager == null)
        {
            Debug.LogError(
                "OrderUI: GridManager " +
                "could not be found."
            );

            return;
        }

        orderManager.ActiveOrderChanged +=
            HandleOrderChanged;

        orderManager.OrderStateChanged +=
            HandleOrderStateChanged;

        if (fulfillButton != null)
        {
            fulfillButton.onClick.AddListener(
                HandleFulfillClicked
            );
        }

        Refresh();
    }

    private void OnDestroy()
    {
        if (orderManager != null)
        {
            orderManager.ActiveOrderChanged -=
                HandleOrderChanged;

            orderManager.OrderStateChanged -=
                HandleOrderStateChanged;
        }

        if (fulfillButton != null)
        {
            fulfillButton.onClick.RemoveListener(
                HandleFulfillClicked
            );
        }
    }

    private void ResolveReferences()
    {
        if (orderManager == null)
        {
            orderManager =
                FindFirstObjectByType<OrderManager>();
        }

        if (gridManager == null)
        {
            gridManager =
                FindFirstObjectByType<GridManager>();
        }
    }

    private void HandleOrderChanged()
    {
        Refresh();
    }

    private void HandleOrderStateChanged()
    {
        Refresh();
    }

    private void HandleFulfillClicked()
    {
        if (orderManager == null)
            return;

        orderManager.TryFulfillActiveOrder();
    }

    private void Refresh()
    {
        if (orderManager == null ||
            gridManager == null)
        {
            return;
        }

        CustomerOrder order =
            orderManager.ActiveOrder;

        if (order == null ||
            !order.IsValid)
        {
            ShowNoOrder();
            return;
        }

        if (orderNameText != null)
        {
            orderNameText.text =
                order.DisplayName;
        }

        if (requirementsText != null)
        {
            requirementsText.text =
                BuildRequirementsText(
                    order
                );
        }

        if (rewardText != null)
        {
            rewardText.text =
                $"Reward: ${order.CashReward}";
        }

        if (fulfillButton != null)
        {
            fulfillButton.interactable =
                orderManager.CanFulfillActiveOrder;
        }
    }

    private string BuildRequirementsText(
        CustomerOrder order)
    {
        StringBuilder builder =
            new StringBuilder();

        foreach (
            OrderRequirement requirement
            in order.Definition.Requirements)
        {
            if (requirement == null ||
                requirement.Dessert == null)
            {
                continue;
            }

            int available =
                order.GetAvailableAmount(
                    gridManager,
                    requirement.Dessert
                );

            int displayedAvailable =
                Mathf.Min(
                    available,
                    requirement.Amount
                );

            builder.Append(
                requirement.Dessert.DisplayName
            );

            builder.Append("    ");

            builder.Append(
                displayedAvailable
            );

            builder.Append(" / ");

            builder.Append(
                requirement.Amount
            );

            builder.AppendLine();
        }

        return builder.ToString().TrimEnd();
    }

    private void ShowNoOrder()
    {
        if (orderNameText != null)
        {
            orderNameText.text =
                "No Active Order";
        }

        if (requirementsText != null)
        {
            requirementsText.text =
                string.Empty;
        }

        if (rewardText != null)
        {
            rewardText.text =
                "Reward: $0";
        }

        if (fulfillButton != null)
        {
            fulfillButton.interactable =
                false;
        }
    }
}