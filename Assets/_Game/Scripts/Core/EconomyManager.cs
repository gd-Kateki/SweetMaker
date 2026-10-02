using System;
using UnityEngine;

public class EconomyManager : MonoBehaviour
{
    public static EconomyManager Instance { get; private set; }

    [Header("Economy")]
    [Min(0)]
    [SerializeField]
    private int startingCash = 0;

    [Header("References")]
    [SerializeField]
    private OrderManager orderManager;

    [SerializeField]
    private PlayerProgressionManager progressionManager;

    private int currentCash;

    // ==================================================
    // EVENTS
    // ==================================================

    public event Action<int> CashChanged;

    // ==================================================
    // PUBLIC STATE
    // ==================================================

    public int CurrentCash =>
        currentCash;

    public float CurrentMoneyMultiplier =>
        progressionManager != null
            ? progressionManager.MoneyMultiplier
            : 1f;

    // ==================================================
    // UNITY
    // ==================================================

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
        ResolveReferences();

        if (orderManager == null)
        {
            Debug.LogError(
                "EconomyManager: OrderManager " +
                "could not be found."
            );

            return;
        }

        orderManager.OrderCompleted +=
            HandleOrderCompleted;

        CashChanged?.Invoke(
            currentCash
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

    private void ResolveReferences()
    {
        if (orderManager == null)
        {
            orderManager =
                FindFirstObjectByType<
                    OrderManager>();
        }

        if (progressionManager == null)
        {
            progressionManager =
                FindFirstObjectByType<
                    PlayerProgressionManager>();
        }
    }

    // ==================================================
    // ORDER REWARDS
    // ==================================================

    /// <summary>
    /// Calculates the actual amount of cash the player
    /// should receive for an order after applying the
    /// current Money Multiplier progression.
    ///
    /// CustomerOrder.CashReward always remains the
    /// unmodified base reward.
    /// </summary>
    public int CalculateOrderReward(
        CustomerOrder order)
    {
        if (order == null)
            return 0;

        float multiplier =
            CurrentMoneyMultiplier;

        float multipliedReward =
            order.CashReward *
            multiplier;

        return Mathf.RoundToInt(
            multipliedReward
        );
    }

    public float GetCurrentMoneyMultiplier()
    {
        return CurrentMoneyMultiplier;
    }

    private void HandleOrderCompleted(
        CustomerOrder order)
    {
        if (order == null)
            return;

        int finalReward =
            CalculateOrderReward(
                order
            );

        AddCash(
            finalReward
        );

        Debug.Log(
            $"ORDER REWARD | " +
            $"Order #{order.OrderId} | " +
            $"Base: ${order.CashReward} | " +
            $"Multiplier: " +
            $"x{CurrentMoneyMultiplier:0.##} | " +
            $"Final: ${finalReward}"
        );
    }

    // ==================================================
    // CASH
    // ==================================================

    public void AddCash(
        int amount)
    {
        if (amount <= 0)
            return;

        currentCash +=
            amount;

        CashChanged?.Invoke(
            currentCash
        );

        Debug.Log(
            $"CASH ADDED | " +
            $"+${amount} | " +
            $"Total: ${currentCash}"
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
        if (amount < 0)
            return false;

        if (!CanAfford(amount))
            return false;

        currentCash -=
            amount;

        CashChanged?.Invoke(
            currentCash
        );

        Debug.Log(
            $"CASH SPENT | " +
            $"-${amount} | " +
            $"Total: ${currentCash}"
        );

        return true;
    }

    // ==================================================
    // DEBUG
    // ==================================================

    [ContextMenu("Debug Economy")]
    private void DebugEconomy()
    {
        Debug.Log(
            $"ECONOMY | " +
            $"Cash: ${currentCash} | " +
            $"Money Multiplier: " +
            $"x{CurrentMoneyMultiplier:0.##}"
        );
    }

    [ContextMenu("Debug Add $100")]
    private void DebugAddCash()
    {
        AddCash(100);
    }
}