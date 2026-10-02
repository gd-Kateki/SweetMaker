using UnityEngine;
using UnityEngine.UI;

public class CustomerButtonUI : MonoBehaviour
{
    [Header("Customer")]
    [Tooltip(
        "Zero-based index. " +
        "Customer 1 = 0, " +
        "Customer 2 = 1, etc."
    )]
    [SerializeField]
    private int customerIndex;

    [Header("References")]
    [SerializeField]
    private Button button;

    [SerializeField]
    private OrderManager orderManager;

    [SerializeField]
    private OrderDetailsUI orderDetailsUI;

    private void Awake()
    {
        if (button == null)
        {
            button =
                GetComponent<Button>();
        }
    }

    private void Start()
    {
        ResolveReferences();

        if (button != null)
        {
            button.onClick.AddListener(
                HandleClicked
            );
        }

        Refresh();
    }

    private void OnDestroy()
    {
        if (button != null)
        {
            button.onClick.RemoveListener(
                HandleClicked
            );
        }
    }

    private void ResolveReferences()
    {
        if (orderManager == null)
        {
            orderManager =
                FindFirstObjectByType<
                    OrderManager>();
        }

        if (orderDetailsUI == null)
        {
            orderDetailsUI =
                FindFirstObjectByType<
                    OrderDetailsUI>();
        }
    }

    public void Refresh()
    {
        if (button == null ||
            orderManager == null)
        {
            return;
        }

        bool available =
            orderManager.IsCustomerUnlocked(
                customerIndex
            ) &&
            orderManager.GetOrderForCustomer(
                customerIndex
            ) != null;

        button.interactable =
            available;
    }

    private void HandleClicked()
    {
        if (orderManager == null ||
            orderDetailsUI == null)
        {
            return;
        }

        if (!orderManager.IsCustomerUnlocked(
                customerIndex))
        {
            return;
        }

        CustomerOrder order =
            orderManager.GetOrderForCustomer(
                customerIndex
            );

        if (order == null)
            return;

        orderDetailsUI.OpenForCustomer(
            customerIndex
        );
    }
}