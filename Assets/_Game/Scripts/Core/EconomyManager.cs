using System;
using UnityEngine;

public class EconomyManager : MonoBehaviour
{
    public static EconomyManager Instance
    {
        get;
        private set;
    }

    [Header("Prototype Economy")]
    [SerializeField]
    private int startingCash = 0;

    [SerializeField]
    private OrderManager orderManager;

    [Header("Runtime")]
    [SerializeField]
    private int currentCash;

    public event Action<int> CashChanged;

    public int CurrentCash =>
        currentCash;

    private void Awake()
    {
        if (Instance != null &&
            Instance != this)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this;

        currentCash =
            Mathf.Max(
                0,
                startingCash
            );
    }

    private void Start()
    {
        if (orderManager == null)
        {
            orderManager =
                FindFirstObjectByType<OrderManager>();
        }

        if (orderManager == null)
        {
            Debug.LogError(
                "EconomyManager: OrderManager " +
                "could not be found."
            );
        }
        else
        {
            orderManager.OrderCompleted +=
                HandleOrderCompleted;
        }

        CashChanged?.Invoke(
            currentCash
        );

        Debug.Log(
            $"ECONOMY | Starting Cash: " +
            $"${currentCash}"
        );
    }

    private void OnDestroy()
    {
        if (orderManager != null)
        {
            orderManager.OrderCompleted -=
                HandleOrderCompleted;
        }

        if (Instance == this)
        {
            Instance = null;
        }
    }

    private void HandleOrderCompleted(
        CustomerOrder completedOrder)
    {
        if (completedOrder == null)
            return;

        int reward =
            completedOrder.CashReward;

        if (reward <= 0)
        {
            Debug.Log(
                $"ECONOMY | " +
                $"{completedOrder.DisplayName} " +
                "has no cash reward."
            );

            return;
        }

        AddCash(
            reward
        );
    }

    public void AddCash(
        int amount)
    {
        if (amount <= 0)
        {
            Debug.LogWarning(
                "EconomyManager: Cannot add " +
                "zero or negative cash."
            );

            return;
        }

        currentCash +=
            amount;

        CashChanged?.Invoke(
            currentCash
        );

        Debug.Log(
            $"ECONOMY | +${amount} | " +
            $"Balance: ${currentCash}"
        );
    }

    public bool CanAfford(
        int amount)
    {
        if (amount < 0)
            return false;

        return currentCash >=
            amount;
    }

    public bool TrySpendCash(
        int amount)
    {
        if (amount <= 0)
        {
            Debug.LogWarning(
                "EconomyManager: Spend amount " +
                "must be greater than zero."
            );

            return false;
        }

        if (!CanAfford(amount))
        {
            Debug.Log(
                $"ECONOMY | Cannot afford " +
                $"${amount}. " +
                $"Balance: ${currentCash}"
            );

            return false;
        }

        currentCash -=
            amount;

        CashChanged?.Invoke(
            currentCash
        );

        Debug.Log(
            $"ECONOMY | -${amount} | " +
            $"Balance: ${currentCash}"
        );

        return true;
    }

    [ContextMenu("Debug Cash")]
    private void DebugCash()
    {
        Debug.Log(
            $"ECONOMY | Current Cash: " +
            $"${currentCash}"
        );
    }

    [ContextMenu("Debug Add $100")]
    private void DebugAddCash()
    {
        AddCash(
            100
        );
    }

    [ContextMenu("Debug Spend $50")]
    private void DebugSpendCash()
    {
        TrySpendCash(
            50
        );
    }
}