using System;
using UnityEngine;

public enum CampaignCompletionPersistenceState
{
    Incomplete,
    Pending,
    Saved
}

public class PlayerProgressionManager : MonoBehaviour
{
    private const int MaximumEnergyValue = 30;
    private const double EnergyRegenerationIntervalSeconds = 60d;

    public static PlayerProgressionManager Instance
    {
        get;
        private set;
    }

    // ==================================================
    // UPGRADE DEFINITIONS
    // ==================================================

    [Header("Upgrade Definitions")]

    [SerializeField]
    private UpgradeDefinition ovenUpgrade;

    [SerializeField]
    private UpgradeDefinition boardSpaceUpgrade;

    [SerializeField]
    private UpgradeDefinition shelfUpgrade;

    [SerializeField]
    private UpgradeDefinition customerUpgrade;

    [SerializeField]
    private UpgradeDefinition moneyMultiplierUpgrade;

    [SerializeField]
    private UpgradeDefinition luckUpgrade;

    // ==================================================
    // RUNTIME LEVELS
    // ==================================================

    [Header("Runtime Levels")]

    [SerializeField]
    private int ovenLevel = 1;

    [SerializeField]
    private int boardSpaceLevel = 1;

    [SerializeField]
    private int shelfLevel = 1;

    [SerializeField]
    private int customerLevel = 1;

    [SerializeField]
    private int moneyMultiplierLevel = 1;

    [SerializeField]
    private int luckLevel = 1;

    private int currentEnergy = MaximumEnergyValue;

    private double secondsUntilNextEnergy;
    private double lastEnergyRealtimeSeconds;
    private bool energyClockPaused;
    private long energyPauseUtcTicks;
    private long energyUtcAnchorTicks;

    [Header("Rebirth Progression")]
    [SerializeField]
    private RebirthProgressionState rebirthProgression =
        new RebirthProgressionState();

    private bool rebirthInProgress;
    private bool campaignCompletionSaveInProgress;
    private bool campaignCelebrationPendingPresentation;
    private CampaignCompletionPersistenceState
        campaignCompletionPersistenceState =
            CampaignCompletionPersistenceState.Incomplete;

    // ==================================================
    // EVENTS
    // ==================================================

    public event Action<UpgradeType, int>
        UpgradeLevelChanged;

    public event Action EnergyChanged;

    public event Action
        RebirthProgressionChanged;

    public event Action<CampaignCompletionPersistenceState>
        CampaignCompletionPersistenceChanged;

    // ==================================================
    // LEVEL PROPERTIES
    // ==================================================

    public int OvenLevel =>
        ovenLevel;

    public int BoardSpaceLevel =>
        boardSpaceLevel;

    public int ShelfLevel =>
        shelfLevel;

    public int CustomerLevel =>
        customerLevel;

    public int MoneyMultiplierLevel =>
        moneyMultiplierLevel;

    public int LuckLevel =>
        luckLevel;

    public int CurrentEnergy
    {
        get
        {
            AdvanceEnergyClock();
            return currentEnergy;
        }
    }

    public int MaximumEnergy =>
        MaximumEnergyValue;

    public float SecondsUntilNextEnergy
    {
        get
        {
            AdvanceEnergyClock();
            return (float)secondsUntilNextEnergy;
        }
    }

    public int CurrentRebirthCount =>
        RebirthProgression.CurrentRebirthCount;

    public bool TryGetCafeTitle(out string cafeTitle)
    {
        return CafeProgressionCatalog.TryGetCafeTitle(
            CurrentRebirthCount,
            out cafeTitle);
    }

    public bool TryGetCafeStarLevel(out int starLevel)
    {
        return CafeProgressionCatalog.TryGetRegularStarLevel(
            CurrentRebirthCount,
            out starLevel);
    }

    public bool TryGetNextCafeStarRebirth(out int? nextStarRebirth)
    {
        return CafeProgressionCatalog.TryGetNextRegularStarRebirth(
            CurrentRebirthCount,
            out nextStarRebirth);
    }

    public int HighestTierCreatedThisRun =>
        RebirthProgression.HighestTierCreatedThisRun;

    public bool CampaignComplete =>
        RebirthProgression.CampaignComplete;

    public CampaignCompletionPersistenceState
        CampaignCompletionPersistence =>
            campaignCompletionPersistenceState;

    public bool HasPendingCampaignCelebrationPresentation =>
        campaignCelebrationPendingPresentation;

    public int NextRebirthNumber =>
        RebirthProgression.NextRebirthNumber;

    public int NextRebirthRequiredTier =>
        RebirthProgression.NextRequiredTier;

    public int NextRebirthRequiredCash =>
        RebirthProgression.NextRequiredCash;

    public int NextRebirthOvenUnlockLevel =>
        RebirthProgression.NextOvenLevelUnlock;

    public bool IsEligibleForNextRebirth =>
        EconomyManager.Instance != null &&
        RebirthProgression.CanRebirth(
            EconomyManager.Instance.CurrentCash
        );

    // ==================================================
    // GAMEPLAY VALUES
    // ==================================================

    public int MaxUnlockedDessertTier =>
        GetIntValue(
            ovenUpgrade,
            ovenLevel
        );

    public int ActiveBoardCells =>
        GetIntValue(
            boardSpaceUpgrade,
            boardSpaceLevel
        );

    public int ShelfCapacity =>
        GetIntValue(
            shelfUpgrade,
            shelfLevel
        );

    public int ActiveCustomerOrders =>
        GetIntValue(
            customerUpgrade,
            customerLevel
        );

    public float MoneyMultiplier =>
        GetFloatValue(
            moneyMultiplierUpgrade,
            moneyMultiplierLevel
        );

    public float LuckMultiplier =>
        GetFloatValue(luckUpgrade, luckLevel);

    // ==================================================
    // UNITY
    // ==================================================

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this;

        DontDestroyOnLoad(gameObject);

        ValidateDefinitions();
        ClampRuntimeLevels();
        currentEnergy = MaximumEnergyValue;
        secondsUntilNextEnergy = 0d;
        lastEnergyRealtimeSeconds = Time.realtimeSinceStartupAsDouble;
        energyUtcAnchorTicks = DateTime.UtcNow.Ticks;
    }

    private void Update()
    {
        AdvanceEnergyClock();
    }

    private void OnApplicationPause(bool isPaused)
    {
        if (Instance != this)
            return;

        if (isPaused)
        {
            if (!energyClockPaused)
            {
                AdvanceEnergyClock();
                energyPauseUtcTicks = Math.Max(
                    energyUtcAnchorTicks,
                    DateTime.UtcNow.Ticks);
                energyClockPaused = true;
            }

            return;
        }

        if (!energyClockPaused)
            return;

        long nowUtcTicks = DateTime.UtcNow.Ticks;
        if (nowUtcTicks > energyPauseUtcTicks)
        {
            double elapsedSeconds =
                (nowUtcTicks - energyPauseUtcTicks) /
                (double)TimeSpan.TicksPerSecond;
            AdvanceEnergyBy(elapsedSeconds);
        }

        energyUtcAnchorTicks = Math.Max(
            energyPauseUtcTicks,
            nowUtcTicks);
        energyClockPaused = false;
        lastEnergyRealtimeSeconds = Time.realtimeSinceStartupAsDouble;
    }

    private void OnEnable()
    {
        if (Instance != this)
            return;

        GameplayEvents.DessertSpawned -=
            HandleCreatedDessert;
        GameplayEvents.DessertSpawned +=
            HandleCreatedDessert;
        GameplayEvents.DessertMerged -=
            HandleCreatedDessert;
        GameplayEvents.DessertMerged +=
            HandleCreatedDessert;
    }

    private void OnDisable()
    {
        GameplayEvents.DessertSpawned -=
            HandleCreatedDessert;
        GameplayEvents.DessertMerged -=
            HandleCreatedDessert;
    }

    public bool TryConsumeEnergy()
    {
        AdvanceEnergyClock();
        if (currentEnergy <= 0)
            return false;

        bool wasAtCapacity = currentEnergy == MaximumEnergyValue;
        currentEnergy--;
        if (wasAtCapacity)
            secondsUntilNextEnergy = EnergyRegenerationIntervalSeconds;

        EnergyChanged?.Invoke();
        return true;
    }

    public void ResetEnergy()
    {
        currentEnergy = MaximumEnergyValue;
        secondsUntilNextEnergy = 0d;
        energyClockPaused = false;
        energyPauseUtcTicks = 0;
        lastEnergyRealtimeSeconds = Time.realtimeSinceStartupAsDouble;
        energyUtcAnchorTicks = DateTime.UtcNow.Ticks;
        EnergyChanged?.Invoke();
    }

    internal bool SetEnergyForDevelopment(int energy)
    {
        if (energy < 0 || energy > MaximumEnergyValue)
            return false;

        currentEnergy = energy;
        secondsUntilNextEnergy = energy < MaximumEnergyValue
            ? EnergyRegenerationIntervalSeconds
            : 0d;
        energyClockPaused = false;
        energyPauseUtcTicks = 0;
        lastEnergyRealtimeSeconds = Time.realtimeSinceStartupAsDouble;
        energyUtcAnchorTicks = DateTime.UtcNow.Ticks;
        EnergyChanged?.Invoke();
        return true;
    }

    internal bool RestoreEnergy(
        int restoredEnergy,
        int millisecondsUntilNextEnergy,
        long savedUtcTicks)
    {
        if (restoredEnergy < 0 ||
            restoredEnergy > MaximumEnergyValue ||
            savedUtcTicks <= 0 ||
            savedUtcTicks > DateTime.MaxValue.Ticks ||
            (restoredEnergy == MaximumEnergyValue &&
             millisecondsUntilNextEnergy != 0) ||
            (restoredEnergy < MaximumEnergyValue &&
             (millisecondsUntilNextEnergy < 1 ||
              millisecondsUntilNextEnergy > 60000)))
        {
            return false;
        }

        currentEnergy = restoredEnergy;
        secondsUntilNextEnergy =
            millisecondsUntilNextEnergy / 1000d;
        energyClockPaused = false;

        long nowUtcTicks = DateTime.UtcNow.Ticks;
        if (nowUtcTicks > savedUtcTicks)
        {
            double elapsedSeconds =
                (nowUtcTicks - savedUtcTicks) /
                (double)TimeSpan.TicksPerSecond;
            AdvanceEnergyBy(elapsedSeconds);
        }

        energyUtcAnchorTicks = Math.Max(savedUtcTicks, nowUtcTicks);
        lastEnergyRealtimeSeconds = Time.realtimeSinceStartupAsDouble;
        EnergyChanged?.Invoke();
        return true;
    }

    internal void CaptureEnergySaveState(
        out int energy,
        out int millisecondsUntilNextEnergy,
        out long savedUtcTicks)
    {
        AdvanceEnergyClock();
        energy = currentEnergy;
        millisecondsUntilNextEnergy = currentEnergy == MaximumEnergyValue
            ? 0
            : Mathf.Clamp(
                (int)Math.Ceiling(secondsUntilNextEnergy * 1000d),
                1,
                60000);
        long nowUtcTicks = energyClockPaused
            ? energyPauseUtcTicks
            : DateTime.UtcNow.Ticks;
        energyUtcAnchorTicks = Math.Max(energyUtcAnchorTicks, nowUtcTicks);
        savedUtcTicks = energyUtcAnchorTicks;
    }

    private void AdvanceEnergyClock()
    {
        double now = Time.realtimeSinceStartupAsDouble;
        if (energyClockPaused)
        {
            lastEnergyRealtimeSeconds = now;
            return;
        }

        double elapsedSeconds = now - lastEnergyRealtimeSeconds;
        lastEnergyRealtimeSeconds = now;
        if (elapsedSeconds > 0d)
            AdvanceEnergyBy(elapsedSeconds);
    }

    private void AdvanceEnergyBy(double elapsedSeconds)
    {
        if (currentEnergy >= MaximumEnergyValue)
        {
            currentEnergy = MaximumEnergyValue;
            secondsUntilNextEnergy = 0d;
            return;
        }

        if (elapsedSeconds <= 0d)
            return;

        int previousEnergy = currentEnergy;
        double timeToCapacity =
            secondsUntilNextEnergy +
            (MaximumEnergyValue - currentEnergy - 1) *
            EnergyRegenerationIntervalSeconds;
        if (elapsedSeconds >= timeToCapacity)
        {
            currentEnergy = MaximumEnergyValue;
            secondsUntilNextEnergy = 0d;
        }
        else if (elapsedSeconds >= secondsUntilNextEnergy)
        {
            double elapsedAfterFirstPoint =
                elapsedSeconds - secondsUntilNextEnergy;
            int regeneratedPoints =
                1 + (int)(elapsedAfterFirstPoint /
                          EnergyRegenerationIntervalSeconds);
            currentEnergy += regeneratedPoints;
            secondsUntilNextEnergy =
                EnergyRegenerationIntervalSeconds -
                (elapsedAfterFirstPoint %
                 EnergyRegenerationIntervalSeconds);
        }
        else
        {
            secondsUntilNextEnergy -= elapsedSeconds;
        }

        if (currentEnergy > previousEnergy)
            EnergyChanged?.Invoke();
    }

    private RebirthProgressionState RebirthProgression
    {
        get
        {
            if (rebirthProgression == null)
                rebirthProgression = new RebirthProgressionState();

            return rebirthProgression;
        }
    }

    private void HandleCreatedDessert(int tier)
    {
        if (RebirthProgression.RegisterCreatedTier(tier))
            RebirthProgressionChanged?.Invoke();
    }

    public bool RestoreRebirthProgression(
        int completedRebirthCount,
        int highestTierCreatedThisRun,
        bool campaignComplete)
    {
        RebirthProgressionState restoredProgression =
            new RebirthProgressionState();
        if (!restoredProgression.Restore(
                completedRebirthCount,
                highestTierCreatedThisRun,
                campaignComplete))
        {
            return false;
        }

        int restoredOvenLevel =
            restoredProgression.RebirthUnlockedOvenLevel;
        UpgradeDefinition ovenDefinition =
            GetDefinition(UpgradeType.Oven);
        if (ovenDefinition == null ||
            !ovenDefinition.IsValid ||
            ovenDefinition.GetLevel(restoredOvenLevel) == null)
        {
            Debug.LogError(
                "REBIRTH PROGRESSION | Cannot restore progression " +
                "without a valid Oven definition for the derived level.");
            return false;
        }

        CampaignCompletionPersistenceState restoredPersistence =
            campaignComplete
                ? CampaignCompletionPersistenceState.Saved
                : CampaignCompletionPersistenceState.Incomplete;
        if (!RebirthProgression.Restore(
            completedRebirthCount,
            highestTierCreatedThisRun,
            campaignComplete
        ))
        {
            return false;
        }

        if (ovenLevel != restoredOvenLevel)
            SetLevel(UpgradeType.Oven, restoredOvenLevel);

        SetCampaignCompletionPersistenceState(restoredPersistence);
        RebirthProgressionChanged?.Invoke();
        return true;
    }

    public bool TryPersistCampaignCompletion()
    {
        if (!CampaignComplete ||
            campaignCompletionPersistenceState ==
                CampaignCompletionPersistenceState.Saved ||
            campaignCompletionSaveInProgress)
        {
            return campaignCompletionPersistenceState ==
                   CampaignCompletionPersistenceState.Saved;
        }

        campaignCompletionSaveInProgress = true;
        bool saved = false;
        try
        {
            SaveManager saveManager = SaveManager.Instance;
            if (saveManager == null)
            {
                Debug.LogError(
                    "CAMPAIGN COMPLETE | SaveManager is unavailable; " +
                    "completion remains unsaved.");
            }
            else
            {
                saved = saveManager.SaveCurrentGame();
            }
        }
        finally
        {
            campaignCompletionSaveInProgress = false;
        }

        if (!saved)
        {
            Debug.LogError(
                "CAMPAIGN COMPLETE | V2 save did not succeed; " +
                "completion remains pending and can be retried.");
            SetCampaignCompletionPersistenceState(
                CampaignCompletionPersistenceState.Pending,
                notifyEvenIfUnchanged: true);
        }

        return saved &&
               campaignCompletionPersistenceState ==
                   CampaignCompletionPersistenceState.Saved;
    }

    internal void MarkCampaignCompletionSaved()
    {
        if (!CampaignComplete ||
            campaignCompletionPersistenceState ==
                CampaignCompletionPersistenceState.Saved)
        {
            return;
        }

        campaignCelebrationPendingPresentation = true;
        SetCampaignCompletionPersistenceState(
            CampaignCompletionPersistenceState.Saved);
        GameplayEvents.RaiseCampaignCompleted();
    }

    public void MarkCampaignCompletionCelebrationPresented()
    {
        campaignCelebrationPendingPresentation = false;
    }

    private void SetCampaignCompletionPersistenceState(
        CampaignCompletionPersistenceState state,
        bool notifyEvenIfUnchanged = false)
    {
        if (!notifyEvenIfUnchanged &&
            campaignCompletionPersistenceState == state)
        {
            return;
        }

        campaignCompletionPersistenceState = state;
        CampaignCompletionPersistenceChanged?.Invoke(state);
    }

    internal static int GetOvenLevelForRebirthCount(int rebirthCount)
    {
        return RebirthProgressionState.GetOvenLevelForRebirthCount(rebirthCount);
    }

    private bool SynchronizeOvenLevelWithRebirth()
    {
        UpgradeDefinition definition = GetDefinition(UpgradeType.Oven);
        if (definition == null || !definition.IsValid)
        {
            Debug.LogError("REBIRTH PROGRESSION | A valid Oven definition is required.");
            return false;
        }

        int unlockedLevel = Mathf.Clamp(
            RebirthProgression.RebirthUnlockedOvenLevel,
            1,
            definition.MaxLevel);
        if (ovenLevel != unlockedLevel)
            SetLevel(UpgradeType.Oven, unlockedLevel);

        return ovenLevel == unlockedLevel;
    }

    public bool TryRebirth()
    {
        if (rebirthInProgress)
            return false;

        EconomyManager economy = EconomyManager.Instance;
        SaveManager saveManager = SaveManager.Instance;
        MergeSessionController[] sessionControllers =
            FindObjectsByType<MergeSessionController>();

        if (economy == null || saveManager == null ||
            sessionControllers.Length != 1 ||
            !RebirthProgression.CanRebirth(economy.CurrentCash))
        {
            return false;
        }

        int cashHeld = economy.CurrentCash;
        int nextRebirthCount = CurrentRebirthCount + 1;
        int previousOvenLevel = ovenLevel;
        int newOvenLevel = GetOvenLevelForRebirthCount(nextRebirthCount);
        bool snapshotCommitted = false;
        bool rebirthCompleted = false;
        rebirthInProgress = true;

        try
        {
            rebirthCompleted =
                sessionControllers[0].TryReplaceWithFreshSession(() =>
            {
                bool saved = saveManager.TryCommitRebirthSnapshot(
                    nextRebirthCount,
                    out bool committed);
                snapshotCommitted = committed;

                if (!saved && !committed)
                    return false;

                if (!RebirthProgression.TryCommitRebirth(cashHeld))
                {
                    if (!RestoreRebirthProgression(
                            nextRebirthCount,
                            0,
                            CampaignComplete))
                    {
                        Debug.LogError(
                            "REBIRTH COMMITTED | " +
                            "The persisted progression could not be applied in memory.");
                    }
                }
                else if (!SynchronizeOvenLevelWithRebirth())
                {
                    Debug.LogError(
                        "REBIRTH COMMITTED | " +
                        "The free Oven unlock could not be applied in memory.");
                }
                RebirthProgressionChanged?.Invoke();

                try
                {
                    economy.RestoreCash(0);
                }
                catch (Exception exception)
                {
                    Debug.LogError(
                        "REBIRTH COMMITTED | Cash reset notification failed.\n" +
                        exception);
                }

                return true;
            });
        }
        catch (Exception exception)
        {
            if (snapshotCommitted)
            {
                Debug.LogError(
                    "REBIRTH COMMITTED | " +
                    "A post-commit session operation failed.\n" +
                    exception);
                rebirthCompleted = true;
            }
            else
            {
                Debug.LogError("REBIRTH FAILED | Transaction was not committed.\n" + exception);
            }
        }
        finally
        {
            rebirthInProgress = false;
        }

        if (rebirthCompleted)
            RequestSuccessfulRebirthAudio(previousOvenLevel, newOvenLevel);

        return rebirthCompleted;
    }

    private static void RequestSuccessfulRebirthAudio(
        int previousOvenLevel,
        int newOvenLevel)
    {
        AudioManager.Play(SfxId.Rebirth_Start);
        if (newOvenLevel > previousOvenLevel)
            AudioManager.Play(SfxId.Oven_Unlock);
        AudioManager.Play(SfxId.Rebirth_Complete);
    }

    // ==================================================
    // LEVEL LOOKUP
    // ==================================================

    public int GetLevel(
        UpgradeType type)
    {
        switch (type)
        {
            case UpgradeType.Oven:
                return ovenLevel;

            case UpgradeType.BoardSpace:
                return boardSpaceLevel;

            case UpgradeType.Shelf:
                return shelfLevel;

            case UpgradeType.Customer:
                return customerLevel;

            case UpgradeType.MoneyMultiplier:
                return moneyMultiplierLevel;

            case UpgradeType.Luck:
                return luckLevel;

            default:
                return 1;
        }
    }

    public int GetMaxLevel(
        UpgradeType type)
    {
        UpgradeDefinition definition =
            GetDefinition(type);

        if (definition == null)
            return 0;

        return definition.MaxLevel;
    }

    public bool IsMaxLevel(
        UpgradeType type)
    {
        int maxLevel =
            GetMaxLevel(type);

        if (maxLevel <= 0)
            return true;

        return GetLevel(type) >=
            maxLevel;
    }

    // ==================================================
    // DEFINITION LOOKUP
    // ==================================================

    /// <summary>
    /// Returns the UpgradeDefinition associated with
    /// the supplied upgrade type.
    ///
    /// This is public so systems such as the
    /// UpgradePurchaseManager and future upgrade UI
    /// can query progression data without duplicating
    /// definition references.
    /// </summary>
    public UpgradeDefinition GetDefinition(
        UpgradeType type)
    {
        switch (type)
        {
            case UpgradeType.Oven:
                return ovenUpgrade;

            case UpgradeType.BoardSpace:
                return boardSpaceUpgrade;

            case UpgradeType.Shelf:
                return shelfUpgrade;

            case UpgradeType.Customer:
                return customerUpgrade;

            case UpgradeType.MoneyMultiplier:
                return moneyMultiplierUpgrade;

            case UpgradeType.Luck:
                return luckUpgrade;

            default:
                return null;
        }
    }

    // ==================================================
    // NEXT LEVEL / COST LOOKUP
    // ==================================================

    public UpgradeLevelData GetNextLevelData(
        UpgradeType type)
    {
        UpgradeDefinition definition =
            GetDefinition(type);

        if (definition == null)
            return null;

        int currentLevel =
            GetLevel(type);

        return definition.GetNextLevel(
            currentLevel
        );
    }

    public int GetNextUpgradeCost(
        UpgradeType type)
    {
        UpgradeLevelData nextLevel =
            GetNextLevelData(type);

        if (nextLevel == null)
            return 0;

        return nextLevel.UpgradeCost;
    }

    // ==================================================
    // DESSERT PROGRESSION
    // ==================================================

    public bool IsDessertTierUnlocked(
        int tier)
    {
        if (tier <= 0)
            return false;

        return tier <=
            MaxUnlockedDessertTier;
    }

    // ==================================================
    // CONTROLLED LEVEL CHANGE
    // ==================================================

    /// <summary>
    /// Attempts to apply a valid progression level.
    ///
    /// This method does NOT spend cash.
    /// Purchase validation belongs to
    /// UpgradePurchaseManager.
    ///
    /// It is used after the purchase manager has
    /// successfully validated and paid for an upgrade.
    /// </summary>
    public bool TrySetLevel(
        UpgradeType type,
        int newLevel)
    {
        UpgradeDefinition definition =
            GetDefinition(type);

        if (definition == null ||
            !definition.IsValid)
        {
            Debug.LogWarning(
                $"PROGRESSION SET FAILED | " +
                $"{type} | " +
                "Missing or invalid definition."
            );

            return false;
        }

        int currentLevel =
            GetLevel(type);

        if (newLevel < 1 ||
            newLevel > definition.MaxLevel)
        {
            Debug.LogWarning(
                $"PROGRESSION SET FAILED | " +
                $"{definition.DisplayName} | " +
                $"Requested Level {newLevel} " +
                $"is outside valid range " +
                $"1-{definition.MaxLevel}."
            );

            return false;
        }

        if (newLevel == currentLevel)
        {
            return false;
        }

        SetLevel(
            type,
            newLevel
        );

        return true;
    }

    // ==================================================
    // DEBUG UPGRADE
    // ==================================================

    /// <summary>
    /// Developer-only upgrade path.
    ///
    /// This intentionally ignores upgrade costs.
    /// Use UpgradePurchaseManager for real purchases.
    /// </summary>
    public bool TryUpgradeForDebug(
        UpgradeType type)
    {
        if (type == UpgradeType.Oven)
        {
            Debug.LogWarning(
                "DEBUG UPGRADE BLOCKED | Oven levels are unlocked by completed Rebirths.");
            return false;
        }

        UpgradeDefinition definition =
            GetDefinition(type);

        if (definition == null)
            return false;

        int currentLevel =
            GetLevel(type);

        if (currentLevel >=
            definition.MaxLevel)
        {
            Debug.Log(
                $"DEBUG UPGRADE | " +
                $"{definition.DisplayName} " +
                "is already at maximum level."
            );

            return false;
        }

        SetLevel(
            type,
            currentLevel + 1
        );

        return true;
    }

    // ==================================================
    // INTERNAL LEVEL APPLICATION
    // ==================================================

    private void SetLevel(
        UpgradeType type,
        int newLevel)
    {
        UpgradeDefinition definition =
            GetDefinition(type);

        if (definition == null)
            return;

        newLevel =
            Mathf.Clamp(
                newLevel,
                1,
                definition.MaxLevel
            );

        switch (type)
        {
            case UpgradeType.Oven:
                ovenLevel = newLevel;
                break;

            case UpgradeType.BoardSpace:
                boardSpaceLevel = newLevel;
                break;

            case UpgradeType.Shelf:
                shelfLevel = newLevel;
                break;

            case UpgradeType.Customer:
                customerLevel = newLevel;
                break;

            case UpgradeType.MoneyMultiplier:
                moneyMultiplierLevel =
                    newLevel;
                break;

            case UpgradeType.Luck:
                luckLevel = newLevel;
                break;
        }

        UpgradeLevelChanged?.Invoke(
            type,
            newLevel
        );

        Debug.Log(
            $"UPGRADE | " +
            $"{definition.DisplayName} " +
            $"reached Level {newLevel}."
        );

        DebugCurrentProgression();
    }

    // ==================================================
    // GAMEPLAY VALUE LOOKUP
    // ==================================================

    private int GetIntValue(
        UpgradeDefinition definition,
        int level)
    {
        if (definition == null)
            return 0;

        UpgradeLevelData levelData =
            definition.GetLevel(level);

        if (levelData == null)
            return 0;

        return levelData.IntValue;
    }

    private float GetFloatValue(
        UpgradeDefinition definition,
        int level)
    {
        if (definition == null)
            return 1f;

        UpgradeLevelData levelData =
            definition.GetLevel(level);

        if (levelData == null)
            return 1f;

        return levelData.FloatValue;
    }

    // ==================================================
    // VALIDATION
    // ==================================================

    public bool ValidateRestorationDefinitions(out string reason)
    {
        foreach (UpgradeType type in new[] { UpgradeType.Oven, UpgradeType.BoardSpace,
            UpgradeType.Shelf, UpgradeType.Customer, UpgradeType.MoneyMultiplier,
            UpgradeType.Luck })
        {
            var definition = GetDefinition(type);
            if (definition == null || !definition.IsValid || definition.UpgradeType != type ||
                definition.MaxLevel < 1 || definition.GetLevel(GetLevel(type)) == null)
            { reason = "Missing or invalid progression definition: " + type; return false; }
        }
        if (MaxUnlockedDessertTier <= 0 || ActiveBoardCells <= 0 || ShelfCapacity < 0 ||
            ActiveCustomerOrders <= 0 || float.IsNaN(MoneyMultiplier) ||
            float.IsInfinity(MoneyMultiplier) || MoneyMultiplier <= 0 ||
            float.IsNaN(LuckMultiplier) || float.IsInfinity(LuckMultiplier) ||
            LuckMultiplier <= 0)
        { reason = "Progression gameplay values are invalid."; return false; }
        reason = null;
        return true;
    }

    private void ClampRuntimeLevels()
    {
        ovenLevel =
            ClampLevel(
                ovenLevel,
                ovenUpgrade
            );

        boardSpaceLevel =
            ClampLevel(
                boardSpaceLevel,
                boardSpaceUpgrade
            );

        shelfLevel =
            ClampLevel(
                shelfLevel,
                shelfUpgrade
            );

        customerLevel =
            ClampLevel(
                customerLevel,
                customerUpgrade
            );

        moneyMultiplierLevel =
            ClampLevel(
                moneyMultiplierLevel,
                moneyMultiplierUpgrade
            );

        luckLevel = ClampLevel(luckLevel, luckUpgrade);
    }

    private int ClampLevel(
        int level,
        UpgradeDefinition definition)
    {
        if (definition == null ||
            definition.MaxLevel <= 0)
        {
            return 1;
        }

        return Mathf.Clamp(
            level,
            1,
            definition.MaxLevel
        );
    }

    private void ValidateDefinitions()
    {
        ValidateDefinition(
            ovenUpgrade,
            UpgradeType.Oven
        );

        ValidateDefinition(
            boardSpaceUpgrade,
            UpgradeType.BoardSpace
        );

        ValidateDefinition(
            shelfUpgrade,
            UpgradeType.Shelf
        );

        ValidateDefinition(
            customerUpgrade,
            UpgradeType.Customer
        );

        ValidateDefinition(
            moneyMultiplierUpgrade,
            UpgradeType.MoneyMultiplier
        );

        ValidateDefinition(luckUpgrade, UpgradeType.Luck);
    }

    private void ValidateDefinition(
        UpgradeDefinition definition,
        UpgradeType expectedType)
    {
        if (definition == null)
        {
            Debug.LogError(
                $"Progression: Missing " +
                $"{expectedType} definition."
            );

            return;
        }

        if (!definition.IsValid)
        {
            Debug.LogError(
                $"Progression: " +
                $"{definition.name} is invalid."
            );
        }

        if (definition.UpgradeType !=
            expectedType)
        {
            Debug.LogError(
                $"Progression: " +
                $"{definition.name} has " +
                $"type {definition.UpgradeType}, " +
                $"expected {expectedType}."
            );
        }
    }

    // ==================================================
    // DEBUG
    // ==================================================

    [ContextMenu("Debug Progression")]
    private void DebugCurrentProgression()
    {
        Debug.Log(
            "PROGRESSION | " +
            $"Oven L{ovenLevel} " +
            $"(Max T{MaxUnlockedDessertTier}) | " +
            $"Board L{boardSpaceLevel} " +
            $"({ActiveBoardCells} cells) | " +
            $"Shelf L{shelfLevel} " +
            $"({ShelfCapacity} slots) | " +
            $"Customer L{customerLevel} " +
            $"({ActiveCustomerOrders} orders) | " +
            $"Money L{moneyMultiplierLevel} " +
            $"(x{MoneyMultiplier:0.##})"
        );
    }

    [ContextMenu("Debug Upgrade Oven")]
    private void DebugUpgradeOven()
    {
        TryUpgradeForDebug(
            UpgradeType.Oven
        );
    }

    [ContextMenu("Debug Upgrade Board")]
    private void DebugUpgradeBoard()
    {
        TryUpgradeForDebug(
            UpgradeType.BoardSpace
        );
    }

    [ContextMenu("Debug Upgrade Shelf")]
    private void DebugUpgradeShelf()
    {
        TryUpgradeForDebug(
            UpgradeType.Shelf
        );
    }

    [ContextMenu("Debug Upgrade Customer")]
    private void DebugUpgradeCustomer()
    {
        TryUpgradeForDebug(
            UpgradeType.Customer
        );
    }

    [ContextMenu(
        "Debug Upgrade Money Multiplier"
    )]
    private void DebugUpgradeMoneyMultiplier()
    {
        TryUpgradeForDebug(
            UpgradeType.MoneyMultiplier
        );
    }

    // ==================================================
// PERSISTENCE
// ==================================================

public void RestoreProgression(
    int restoredOvenLevel,
    int restoredBoardSpaceLevel,
    int restoredShelfLevel,
    int restoredCustomerLevel,
    int restoredMoneyMultiplierLevel)
{
    RestoreProgression(
        restoredOvenLevel,
        restoredBoardSpaceLevel,
        restoredShelfLevel,
        restoredCustomerLevel,
        restoredMoneyMultiplierLevel,
        luckLevel);
}

public void RestoreProgression(
    int restoredOvenLevel,
    int restoredBoardSpaceLevel,
    int restoredShelfLevel,
    int restoredCustomerLevel,
    int restoredMoneyMultiplierLevel,
    int restoredLuckLevel)
{
    /*
     * Save data is external state.
     *
     * Never trust its level values directly.
     * Each value is clamped against the
     * authoritative UpgradeDefinition.
     */

    ovenLevel =
        ClampLevel(
            RebirthProgression.RebirthUnlockedOvenLevel,
            ovenUpgrade
        );

    boardSpaceLevel =
        ClampLevel(
            restoredBoardSpaceLevel,
            boardSpaceUpgrade
        );

    shelfLevel =
        ClampLevel(
            restoredShelfLevel,
            shelfUpgrade
        );

    customerLevel =
        ClampLevel(
            restoredCustomerLevel,
            customerUpgrade
        );

    moneyMultiplierLevel =
        ClampLevel(
            restoredMoneyMultiplierLevel,
            moneyMultiplierUpgrade
        );

    luckLevel = ClampLevel(restoredLuckLevel, luckUpgrade);

    /*
     * Notify every progression consumer.
     *
     * This is intentional even when a restored
     * level happens to equal the current level.
     * Loading establishes authoritative state,
     * so UI/gameplay systems must be given a
     * chance to refresh from that state.
     */

    UpgradeLevelChanged?.Invoke(
        UpgradeType.Oven,
        ovenLevel
    );

    UpgradeLevelChanged?.Invoke(
        UpgradeType.BoardSpace,
        boardSpaceLevel
    );

    UpgradeLevelChanged?.Invoke(
        UpgradeType.Shelf,
        shelfLevel
    );

    UpgradeLevelChanged?.Invoke(
        UpgradeType.Customer,
        customerLevel
    );

    UpgradeLevelChanged?.Invoke(
        UpgradeType.MoneyMultiplier,
        moneyMultiplierLevel
    );

    UpgradeLevelChanged?.Invoke(UpgradeType.Luck, luckLevel);

    Debug.Log(
        "PROGRESSION RESTORED | " +
        $"Oven L{ovenLevel} | " +
        $"Board L{boardSpaceLevel} | " +
        $"Shelf L{shelfLevel} | " +
        $"Customer L{customerLevel} | " +
        $"Money L{moneyMultiplierLevel}"
    );

    DebugCurrentProgression();
}
[ContextMenu("Debug Restore Test Progression")]
private void DebugRestoreTestProgression()
{
    RestoreProgression(
        2,
        2,
        2,
        2,
        2
    );
}
}
