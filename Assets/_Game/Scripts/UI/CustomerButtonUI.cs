using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class CustomerButtonUI : MonoBehaviour
{
    private const int MaxPreviewIcons = 2;

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

    [Header("Preview")]
    [SerializeField]
    private GridManager gridManager;

    [SerializeField]
    private ShelfManager shelfManager;

    [Header("Visibility")]
    [SerializeField]
    private CanvasGroup canvasGroup;

    [Header("Serialized Preview UI")]
    [SerializeField]
    private TMP_Text customerLabel;

    [SerializeField]
    private TMP_Text readinessLabel;

    [SerializeField]
    private Image[] requirementIcons =
        new Image[MaxPreviewIcons];

    [SerializeField]
    private TMP_Text[] requirementLabels =
        new TMP_Text[MaxPreviewIcons];

    private Image cardBackground;

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
        }

        cardBackground = GetComponent<Image>();
        if (button == null ||
            canvasGroup == null ||
            cardBackground == null ||
            customerLabel == null ||
            readinessLabel == null ||
            requirementIcons == null ||
            requirementIcons.Length != MaxPreviewIcons ||
            requirementLabels == null ||
            requirementLabels.Length != MaxPreviewIcons)
        {
            Debug.LogError(
                $"{name}: Serialized Table preview references are incomplete.",
                this);
            enabled = false;
            return;
        }

        for (int i = 0; i < MaxPreviewIcons; i++)
        {
            if (requirementIcons[i] == null ||
                requirementLabels[i] == null)
            {
                Debug.LogError(
                    $"{name}: Serialized requirement preview slot {i + 1} is incomplete.",
                    this);
                enabled = false;
                return;
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
                FindAnyObjectByType<
                    OrderManager>();
        }

        if (orderDetailsUI == null)
        {
            orderDetailsUI =
                FindAnyObjectByType<
                    OrderDetailsUI>();
        }

        if (progressionManager == null)
        {
            progressionManager =
                FindAnyObjectByType<
                    PlayerProgressionManager>();
        }

        if (gridManager == null)
        {
            gridManager =
                FindAnyObjectByType<GridManager>();
        }
        if (shelfManager == null)
        {
            shelfManager =
                FindAnyObjectByType<ShelfManager>();
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

            orderManager.OrderStateChanged +=
                HandleOrderStateChanged;
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

            orderManager.OrderStateChanged -=
                HandleOrderStateChanged;
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

    private void HandleOrderStateChanged()
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
            ClearPreview("NO ORDER");
            return;
        }

        bool unlocked =
            orderManager.IsCustomerUnlocked(
                customerIndex
            );

        SetVisible(true);
        SetCardState(unlocked);

        if (!unlocked)
        {
            ClearPreview("LOCKED");
            if (button != null)
                button.interactable = false;
            return;
        }

        CustomerOrder order =
            orderManager.GetOrderForCustomer(
                customerIndex
            );

        RefreshPreview(order);

        if (button != null)
        {
            button.interactable =
                unlocked && order != null;
        }
    }

    private void RefreshPreview(CustomerOrder order)
    {
        if (customerLabel == null)
            return;

        if (order == null || !order.IsValid)
        {
            ClearPreview("NO ORDER");
            return;
        }

        customerLabel.text =
            $"TABLE {customerIndex + 1}";
        int iconIndex = 0;
        foreach (OrderRequirement requirement
                 in order.Requirements)
        {
            if (requirement == null ||
                requirement.Dessert == null)
            {
                continue;
            }

            if (iconIndex >= MaxPreviewIcons)
                break;

            int available = Mathf.Min(
                order.GetAvailableAmount(
                    shelfManager,
                    requirement.Dessert
                ),
                requirement.Amount
            );

            requirementLabels[iconIndex].text =
                $"T{requirement.Dessert.Tier} " +
                $"{available}/{requirement.Amount}";
            requirementLabels[iconIndex]
                .gameObject.SetActive(true);
            SetRequirementIcon(
                iconIndex,
                requirement.Dessert.Sprite
            );
            iconIndex++;
        }

        for (int i = iconIndex;
             i < MaxPreviewIcons;
             i++)
        {
            SetRequirementIcon(i, null);
            requirementLabels[i].text =
                string.Empty;
            requirementLabels[i]
                .gameObject.SetActive(false);
        }

        bool ready =
            orderManager.CanFulfillOrderAtIndex(
                customerIndex
            );
        readinessLabel.text =
            ready
                ? "READY"
                : "NEED DESSERTS";
    }

    private void SetRequirementIcon(
        int iconIndex,
        Sprite sprite)
    {
        Image icon = requirementIcons[iconIndex];
        if (icon == null)
            return;

        icon.sprite = sprite;
        icon.enabled = sprite != null;
    }

    private void ClearPreview(string status)
    {
        if (customerLabel != null)
        {
            customerLabel.text =
                $"TABLE {customerIndex + 1}";
        }

        if (readinessLabel != null)
        {
            readinessLabel.text = status;
        }

        for (int i = 0; i < requirementIcons.Length; i++)
        {
            SetRequirementIcon(i, null);
            if (requirementLabels[i] != null)
            {
                requirementLabels[i].text =
                    string.Empty;
                requirementLabels[i]
                    .gameObject.SetActive(false);
            }
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

    private void SetCardState(bool unlocked)
    {
        if (canvasGroup != null)
        {
            canvasGroup.alpha = unlocked ? 1f : 0.72f;
            canvasGroup.interactable = unlocked;
            canvasGroup.blocksRaycasts = unlocked;
        }
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
        if (orderDetailsUI.IsOpen &&
            orderDetailsUI.SelectedCustomerIndex == customerIndex)
        {
            UiClickSfx.TryPlay(button);
        }
    }
}