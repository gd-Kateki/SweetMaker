using System;
using UnityEngine;
using UnityEngine.SceneManagement;

public class EconomyManager : MonoBehaviour
{
    public static EconomyManager Instance
    {
        get;
        private set;
    }

    [Header("Economy")]
    [Min(0)]
    [SerializeField]
    private int startingCash = 0;

    [Header("References")]
    [SerializeField]
    private OrderManager orderManager;

    [SerializeField]
    private PlayerProgressionManager
        progressionManager;

    private int currentCash;

    private bool initialized;

    public event Action<int> CashChanged;

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

        DontDestroyOnLoad(gameObject);

        if (!initialized)
        {
            currentCash =
                Mathf.Max(
                    0,
                    startingCash
                );

            initialized = true;
        }
        SceneManager.sceneLoaded +=
    HandleSceneLoaded;
    }

    private void Start()
    {
        ResolveReferences();
        SubscribeToOrderManager();

        CashChanged?.Invoke(
            currentCash
        );
    }

    private void OnDestroy()
{
    SceneManager.sceneLoaded -=
        HandleSceneLoaded;

    UnsubscribeFromOrderManager();

    if (Instance == this)
    {
        Instance = null;
    }
    
}
private void HandleSceneLoaded(
    Scene scene,
    LoadSceneMode mode)
{
    UnsubscribeFromOrderManager();

    orderManager =
        FindFirstObjectByType<
            OrderManager>();

    progressionManager =
        FindFirstObjectByType<
            PlayerProgressionManager>();

    SubscribeToOrderManager();

    CashChanged?.Invoke(
        currentCash
    );

    Debug.Log(
        $"ECONOMY REBOUND | " +
        $"Scene: {scene.name} | " +
        $"Cash: ${currentCash} | " +
        $"OrderManager: " +
        $"{(orderManager != null)} | " +
        $"ProgressionManager: " +
        $"{(progressionManager != null)}"
    );
}

    // ==================================================
    // REFERENCES
    // ==================================================

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

    private void SubscribeToOrderManager()
    {
        if (orderManager == null)
            return;

        orderManager.OrderCompleted -=
            HandleOrderCompleted;

        orderManager.OrderCompleted +=
            HandleOrderCompleted;
    }

    private void UnsubscribeFromOrderManager()
    {
        if (orderManager == null)
            return;

        orderManager.OrderCompleted -=
            HandleOrderCompleted;
    }

    // ==================================================
    // ORDER REWARD
    // ==================================================

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

        currentCash += amount;

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

        currentCash -= amount;

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