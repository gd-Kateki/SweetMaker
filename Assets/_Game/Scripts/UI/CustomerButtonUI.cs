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

    [Header("Visibility")]
    [SerializeField]
    private CanvasGroup canvasGroup;

    private TMP_Text customerLabel;
    private TMP_Text readinessLabel;
    private readonly Image[] requirementIcons =
        new Image[MaxPreviewIcons];
    private readonly TMP_Text[] requirementLabels =
        new TMP_Text[MaxPreviewIcons];

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

        customerLabel =
            GetComponentInChildren<TMP_Text>(true);
        ConfigureCustomerLabel();
        CreateRequirementIcons();
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

        SetVisible(
            unlocked
        );

        if (!unlocked)
        {
            ClearPreview("LOCKED");
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
                order != null;
        }
    }

    private void ConfigureCustomerLabel()
    {
        if (customerLabel == null)
            return;

        ConfigureText(
            customerLabel,
            new Vector2(0f, 43f),
            new Vector2(220f, 22f),
            18f,
            TextAlignmentOptions.Center
        );
        customerLabel.fontStyle = FontStyles.Bold;
        customerLabel.color =
            new Color32(50, 50, 50, 255);
        customerLabel.text =
            $"TABLE {customerIndex + 1}";
        readinessLabel =
            CreateText(
                "OrderPreviewReadiness",
                new Vector2(0f, -44f),
                new Vector2(220f, 20f),
                15f,
                TextAlignmentOptions.Center
            );
        readinessLabel.fontStyle = FontStyles.Bold;
        readinessLabel.color =
            new Color32(154, 58, 51, 255);
    }

    private TMP_Text CreateText(
        string objectName,
        Vector2 position,
        Vector2 size,
        float fontSize,
        TextAlignmentOptions alignment)
    {
        Transform existing =
            transform.Find(objectName);
        TMP_Text text =
            existing != null
                ? existing.GetComponent<TMP_Text>()
                : null;

        if (text == null)
        {
            GameObject textObject =
                new GameObject(
                    objectName,
                    typeof(RectTransform),
                    typeof(CanvasRenderer),
                    typeof(TextMeshProUGUI)
                );
            textObject.transform.SetParent(
                transform,
                false
            );
            text =
                textObject.GetComponent<TMP_Text>();
        }

        ConfigureText(
            text,
            position,
            size,
            fontSize,
            alignment
        );
        return text;
    }

    private static void ConfigureText(
        TMP_Text text,
        Vector2 position,
        Vector2 size,
        float fontSize,
        TextAlignmentOptions alignment)
    {
        RectTransform textRect =
            text.rectTransform;
        textRect.anchorMin =
            new Vector2(0.5f, 0.5f);
        textRect.anchorMax =
            new Vector2(0.5f, 0.5f);
        textRect.pivot =
            new Vector2(0.5f, 0.5f);
        textRect.anchoredPosition =
            position;
        textRect.sizeDelta =
            size;

        text.fontSize = fontSize;
        text.enableAutoSizing = false;
        text.alignment = alignment;
        text.margin = Vector4.zero;
        text.textWrappingMode =
            TextWrappingModes.NoWrap;
        text.overflowMode =
            TextOverflowModes.Ellipsis;
        text.raycastTarget = false;
    }

    private void CreateRequirementIcons()
    {
        for (int i = 0; i < requirementIcons.Length; i++)
        {
            string iconName =
                $"OrderPreviewIcon_{i + 1}";
            Transform existingIcon =
                transform.Find(iconName);

            if (existingIcon != null)
            {
                requirementIcons[i] =
                    existingIcon.GetComponent<Image>();
            }
            else
            {
                GameObject iconObject =
                    new GameObject(
                        iconName,
                        typeof(RectTransform),
                        typeof(CanvasRenderer),
                        typeof(Image)
                    );
                iconObject.transform.SetParent(
                    transform,
                    false
                );
                requirementIcons[i] =
                    iconObject.GetComponent<Image>();
            }

            Image icon = requirementIcons[i];
            if (icon == null)
                continue;

            RectTransform iconRect =
                icon.rectTransform;
            iconRect.anchorMin =
                new Vector2(0.5f, 0.5f);
            iconRect.anchorMax =
                new Vector2(0.5f, 0.5f);
            iconRect.pivot =
                new Vector2(0.5f, 0.5f);
            iconRect.anchoredPosition =
                new Vector2(-96f, i == 0 ? 16f : -11f);
            iconRect.sizeDelta =
                new Vector2(18f, 18f);
            icon.raycastTarget = false;
            icon.preserveAspect = true;
            icon.enabled = false;

            requirementLabels[i] =
                CreateText(
                    $"OrderPreviewRequirement_{i + 1}",
                    new Vector2(15f, i == 0 ? 16f : -11f),
                    new Vector2(190f, 22f),
                    16f,
                    TextAlignmentOptions.MidlineLeft
                );
            requirementLabels[i].color =
                new Color32(50, 50, 50, 255);
            requirementLabels[i].text = string.Empty;
            requirementLabels[i].gameObject.SetActive(false);
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
                    gridManager,
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
        readinessLabel.color =
            ready
                ? new Color32(37, 140, 55, 255)
                : new Color32(154, 58, 51, 255);
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
            readinessLabel.color =
                new Color32(154, 58, 51, 255);
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