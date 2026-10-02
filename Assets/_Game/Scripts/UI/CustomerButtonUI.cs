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

    [SerializeField]
    private PlayerProgressionManager
        progressionManager;

    [Header("Visibility")]
    [SerializeField]
    private CanvasGroup canvasGroup;

    public int CustomerIndex =>
        customerIndex;

    private void Awake()
    {
        if (button == null)
        {
            button =
                GetComponent<Button>();
        }

        if (canvasGroup == null)
        {
            canvasGroup =
                GetComponent<CanvasGroup>();

            if (canvasGroup == null)
            {
                canvasGroup =
                    gameObject.AddComponent<
                        CanvasGroup>();
            }
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

        SubscribeToEvents();

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

        UnsubscribeFromEvents();
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

        if (progressionManager == null)
        {
            progressionManager =
                FindFirstObjectByType<
                    PlayerProgressionManager>();
        }
    }

    // ==================================================
    // EVENTS
    // ==================================================

    private void SubscribeToEvents()
    {
        if (orderManager != null)
        {
            orderManager.CustomerOrderChanged +=
                HandleCustomerOrderChanged;

            orderManager.ActiveOrdersChanged +=
                HandleActiveOrdersChanged;
        }

        if (progressionManager != null)
        {
            progressionManager
                .UpgradeLevelChanged +=
                    HandleUpgradeLevelChanged;
        }
    }

    private void UnsubscribeFromEvents()
    {
        if (orderManager != null)
        {
            orderManager.CustomerOrderChanged -=
                HandleCustomerOrderChanged;

            orderManager.ActiveOrdersChanged -=
                HandleActiveOrdersChanged;
        }

        if (progressionManager != null)
        {
            progressionManager
                .UpgradeLevelChanged -=
                    HandleUpgradeLevelChanged;
        }
    }

    private void HandleCustomerOrderChanged(
        int changedCustomerIndex,
        CustomerOrder order)
    {
        if (changedCustomerIndex !=
            customerIndex)
        {
            return;
        }

        Refresh();
    }

    private void HandleActiveOrdersChanged()
    {
        Refresh();
    }

    private void HandleUpgradeLevelChanged(
        UpgradeType type,
        int newLevel)
    {
        if (type != UpgradeType.Customer)
            return;

        Refresh();
    }

    // ==================================================
    // VISIBILITY
    // ==================================================

    public void Refresh()
    {
        if (orderManager == null)
        {
            SetVisible(false);
            return;
        }

        bool unlocked =
            orderManager.IsCustomerUnlocked(
                customerIndex
            );

        SetVisible(
            unlocked
        );

        if (!unlocked)
            return;

        CustomerOrder order =
            orderManager.GetOrderForCustomer(
                customerIndex
            );

        if (button != null)
        {
            button.interactable =
                order != null;
        }
    }

    private void SetVisible(
        bool visible)
    {
        if (canvasGroup == null)
            return;

        canvasGroup.alpha =
            visible
                ? 1f
                : 0f;

        canvasGroup.interactable =
            visible;

        canvasGroup.blocksRaycasts =
            visible;
    }

    // ==================================================
    // CLICK
    // ==================================================

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