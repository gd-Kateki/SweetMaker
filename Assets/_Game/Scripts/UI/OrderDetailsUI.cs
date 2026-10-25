using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class OrderDetailsUI : MonoBehaviour
{
    [Header("Systems")]
    [SerializeField]
    private OrderManager orderManager;

    [SerializeField]
    private GridManager gridManager;

    [SerializeField]
    private ShelfManager shelfManager;

    [SerializeField]
    private EconomyManager economyManager;

    [SerializeField]
    private PlayerProgressionManager progressionManager;

    [Header("Panel")]
    [SerializeField]
    private GameObject overlay;

    [SerializeField]
    private GameObject inputBlocker;

    [Header("Header")]
    [SerializeField]
    private TMP_Text orderTitleText;

    [SerializeField]
    private TMP_Text orderNumberText;

    [SerializeField]
    private Button closeButton;

    [Header("Requirements")]
    [SerializeField]
    private OrderRequirementRowUI[]
        requirementRows;
        

    [Header("Reward")]
    [SerializeField]
    private TMP_Text rewardAmountText;

    [Header("Confirmation")]
    [SerializeField]
    private Button confirmButton;

    // -1 means no customer is currently selected.
    private int selectedCustomerIndex = -1;

    // ==================================================
    // PUBLIC STATE
    // ==================================================

    public bool IsOpen =>
        overlay != null &&
        overlay.activeSelf;

    public int SelectedCustomerIndex =>
        selectedCustomerIndex;

    // ==================================================
    // UNITY
    // ==================================================

    private void Awake()
    {
        if (closeButton != null)
        {
            closeButton.onClick.AddListener(
                HandleCloseClicked
            );
        }

        if (confirmButton != null)
        {
            confirmButton.onClick.AddListener(
                HandleConfirmClicked
            );
        }
    }

    private void Start()
    {
        ResolveReferences();
        SubscribeToEvents();

        // Order details should start closed.
        Close();
    }

    private void OnDestroy()
    {
        UnsubscribeFromEvents();

        if (closeButton != null)
        {
            closeButton.onClick.RemoveListener(
                HandleCloseClicked
            );
        }

        if (confirmButton != null)
        {
            confirmButton.onClick.RemoveListener(
                HandleConfirmClicked
            );
        }
    }

    // ==================================================
    // REFERENCES
    // ==================================================

    private void ResolveReferences()
    {
        if (orderManager == null)
        {
            orderManager =
                FindAnyObjectByType<
                    OrderManager>();
        }

        if (gridManager == null)
        {
            gridManager =
                FindAnyObjectByType<
                    GridManager>();
        }
        if (shelfManager == null)
        {
            shelfManager =
                FindAnyObjectByType<ShelfManager>();
        }

        if (economyManager == null)
        {
            economyManager =
                FindAnyObjectByType<
                    EconomyManager>();
        }

        if (progressionManager == null)
        {
            progressionManager =
                FindAnyObjectByType<
                    PlayerProgressionManager>();
        }
    }

    // ==================================================
    // EVENT SUBSCRIPTIONS
    // ==================================================

    private void SubscribeToEvents()
    {
        if (orderManager == null)
        {
            Debug.LogError(
                "OrderDetailsUI: " +
                "OrderManager could not be found."
            );
        }
        else
        {
            orderManager.OrderStateChanged +=
                HandleOrderStateChanged;

            orderManager.CustomerOrderChanged +=
                HandleCustomerOrderChanged;
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
            orderManager.OrderStateChanged -=
                HandleOrderStateChanged;

            orderManager.CustomerOrderChanged -=
                HandleCustomerOrderChanged;
        }

        if (progressionManager != null)
        {
            progressionManager
                .UpgradeLevelChanged -=
                    HandleUpgradeLevelChanged;
        }
    }

    // ==================================================
    // OPEN / CLOSE
    // ==================================================

    private void HandleCloseClicked()
    {
        if (!IsOpen)
            return;

        UiClickSfx.TryPlay(closeButton);
        Close();
    }

    public void OpenForCustomer(
        int customerIndex)
    {
        if (orderManager == null ||
            gridManager == null)
        {
            Debug.LogError(
                "OrderDetailsUI: Required " +
                "gameplay references are missing."
            );

            return;
        }

        if (inputBlocker == null)
        {
            Debug.LogError(
                "OrderDetailsUI: Full-screen " +
                "input blocker is not assigned."
            );
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
        {
            Debug.LogWarning(
                $"OrderDetailsUI: Customer " +
                $"{customerIndex + 1} " +
                "has no active order."
            );

            return;
        }

        selectedCustomerIndex =
            customerIndex;

        inputBlocker.SetActive(true);

        if (overlay != null)
        {
            overlay.SetActive(true);
        }

        Refresh();

        Debug.Log(
            $"ORDER DETAILS OPENED | " +
            $"Customer {customerIndex + 1} | " +
            $"Order #{order.OrderId}"
        );
    }

    public void Close()
    {
        selectedCustomerIndex = -1;

        if (overlay != null)
        {
            overlay.SetActive(false);
        }

        if (inputBlocker != null)
        {
            inputBlocker.SetActive(false);
        }
    }

    // ==================================================
    // REFRESH
    // ==================================================

    private void Refresh()
    {
        if (selectedCustomerIndex < 0)
            return;

        if (orderManager == null ||
            gridManager == null)
        {
            return;
        }

        CustomerOrder order =
            orderManager.GetOrderForCustomer(
                selectedCustomerIndex
            );

        if (order == null ||
            !order.IsValid)
        {
            Close();
            return;
        }

        // ----------------------------------------------
        // HEADER
        // ----------------------------------------------

        if (orderTitleText != null)
        {
            orderTitleText.text =
                order.DisplayName;
        }

        if (orderNumberText != null)
        {
            orderNumberText.text =
                $"Order #{order.OrderId}";
        }

        // ----------------------------------------------
        // REQUIREMENTS
        // ----------------------------------------------

        RefreshRequirements(
            order
        );

        // ----------------------------------------------
        // FINAL REWARD
        // ----------------------------------------------

        if (rewardAmountText != null)
        {
            int displayedReward =
                economyManager != null
                    ? economyManager
                        .CalculateOrderReward(
                            order
                        )
                    : order.CashReward;

            rewardAmountText.text =
                $"${displayedReward}";
        }

        // ----------------------------------------------
        // CONFIRM
        // ----------------------------------------------

        if (confirmButton != null)
        {
            confirmButton.interactable =
                orderManager
                    .CanFulfillOrderAtIndex(
                        selectedCustomerIndex
                    );
        }
    }

    private void RefreshRequirements(
        CustomerOrder order)
    {
        if (requirementRows == null)
            return;

        // Hide all available UI rows first.
        foreach (
            OrderRequirementRowUI row
            in requirementRows)
        {
            if (row != null)
            {
                row.Hide();
            }
        }

        if (order == null ||
            order.Requirements == null)
        {
            return;
        }

        var requirements =
            order.Requirements;

        int visibleCount =
            Mathf.Min(
                requirements.Count,
                requirementRows.Length
            );

        for (int i = 0;
             i < visibleCount;
             i++)
        {
            if (requirementRows[i] == null)
                continue;

            requirementRows[i].Show(
                requirements[i],
                order,
                shelfManager
            );
        }

        if (requirements.Count >
            requirementRows.Length)
        {
            Debug.LogWarning(
                $"Order #{order.OrderId} has " +
                $"{requirements.Count} " +
                $"requirements, but " +
                $"OrderDetailsUI only has " +
                $"{requirementRows.Length} " +
                $"requirement rows."
            );
        }
    }

    // ==================================================
    // ORDER EVENTS
    // ==================================================

    private void HandleOrderStateChanged()
    {
        if (!IsOpen)
            return;

        Refresh();
    }

    private void HandleCustomerOrderChanged(
        int customerIndex,
        CustomerOrder order)
    {
        if (!IsOpen)
            return;

        if (customerIndex !=
            selectedCustomerIndex)
        {
            return;
        }

        Refresh();
    }

    // ==================================================
    // PROGRESSION EVENTS
    // ==================================================

    private void HandleUpgradeLevelChanged(
        UpgradeType type,
        int newLevel)
    {
        if (type !=
            UpgradeType.MoneyMultiplier)
        {
            return;
        }

        if (!IsOpen)
            return;

        Refresh();

        Debug.Log(
            $"ORDER DETAILS | " +
            $"Money Multiplier upgraded " +
            $"to Level {newLevel} | " +
            $"Reward display refreshed."
        );
    }

    // ==================================================
    // CONFIRM
    // ==================================================

    private void HandleConfirmClicked()
    {
        if (selectedCustomerIndex < 0)
            return;

        if (orderManager == null)
            return;

        int customerIndex =
            selectedCustomerIndex;

        CustomerOrder order =
            orderManager.GetOrderForCustomer(
                customerIndex
            );

        if (order == null)
            return;

        int completedOrderId =
            order.OrderId;

        bool fulfilled =
            orderManager
                .TryFulfillOrderAtIndex(
                    customerIndex
                );

        if (!fulfilled)
        {
            Refresh();
            return;
        }

        Debug.Log(
            $"ORDER DETAILS CONFIRMED | " +
            $"Customer {customerIndex + 1} | " +
            $"Completed Order " +
            $"#{completedOrderId}"
        );

        Close();
    }
}