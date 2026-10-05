using System;
using System.IO;
using UnityEngine;

public class SaveManager : MonoBehaviour
{
    // ==================================================
    // SINGLETON
    // ==================================================

    public static SaveManager Instance
    {
        get;
        private set;
    }

    // ==================================================
    // SAVE CONFIGURATION
    // ==================================================

    private const string SaveFileName =
        "player_save.json";

    private const int CurrentSaveVersion = 1;

    // ==================================================
    // PUBLIC PROPERTIES
    // ==================================================

    public string SaveFilePath =>
        Path.Combine(
            Application.persistentDataPath,
            SaveFileName
        );

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

        DontDestroyOnLoad(
            gameObject
        );
    }

    // ==================================================
    // SAVE FILE QUERIES
    // ==================================================

    public bool SaveFileExists()
    {
        return File.Exists(
            SaveFilePath
        );
    }

    // ==================================================
    // NEW SAVE DATA
    // ==================================================

    public PlayerSaveData CreateNewSaveData()
    {
        PlayerSaveData saveData =
            new PlayerSaveData();

        saveData.saveVersion =
            CurrentSaveVersion;

        return saveData;
    }

    // ==================================================
    // CAPTURE - ECONOMY
    // ==================================================

    private bool CaptureEconomy(
        PlayerSaveData saveData)
    {
        if (saveData == null)
        {
            Debug.LogError(
                "SAVE | Cannot capture economy into " +
                "null PlayerSaveData."
            );

            return false;
        }

        EconomyManager economyManager =
            EconomyManager.Instance;

        if (economyManager == null)
        {
            Debug.LogError(
                "SAVE | EconomyManager is unavailable."
            );

            return false;
        }

        if (saveData.economy == null)
        {
            saveData.economy =
                new EconomySaveData();
        }

        saveData.economy.cash =
            economyManager.CurrentCash;

        Debug.Log(
            $"SAVE CAPTURE | Economy | " +
            $"Cash: ${saveData.economy.cash}"
        );

        return true;
    }

    // ==================================================
    // CAPTURE - PROGRESSION
    // ==================================================

    private bool CaptureProgression(
        PlayerSaveData saveData)
    {
        if (saveData == null)
        {
            Debug.LogError(
                "SAVE | Cannot capture progression into " +
                "null PlayerSaveData."
            );

            return false;
        }

        PlayerProgressionManager progressionManager =
            PlayerProgressionManager.Instance;

        if (progressionManager == null)
        {
            Debug.LogError(
                "SAVE | PlayerProgressionManager " +
                "is unavailable."
            );

            return false;
        }

        if (saveData.progression == null)
        {
            saveData.progression =
                new ProgressionSaveData();
        }

        saveData.progression.ovenLevel =
            progressionManager.OvenLevel;

        saveData.progression.boardSpaceLevel =
            progressionManager.BoardSpaceLevel;

        saveData.progression.shelfLevel =
            progressionManager.ShelfLevel;

        saveData.progression.customerLevel =
            progressionManager.CustomerLevel;

        saveData.progression.moneyMultiplierLevel =
            progressionManager.MoneyMultiplierLevel;

        Debug.Log(
            "SAVE CAPTURE | Progression | " +
            $"Oven L{saveData.progression.ovenLevel} | " +
            $"Board L{saveData.progression.boardSpaceLevel} | " +
            $"Shelf L{saveData.progression.shelfLevel} | " +
            $"Customer L{saveData.progression.customerLevel} | " +
            $"Money L" +
            $"{saveData.progression.moneyMultiplierLevel}"
        );

        return true;
    }

    // ==================================================
// CAPTURE - MERGE SESSION
// ==================================================

private bool CaptureMergeSession(
    PlayerSaveData saveData)
{
    if (saveData == null)
    {
        Debug.LogError(
            "SAVE | Cannot capture merge session into " +
            "null PlayerSaveData."
        );

        return false;
    }

    MergeSessionManager mergeSessionManager =
        MergeSessionManager.Instance;

    if (mergeSessionManager == null)
    {
        Debug.LogError(
            "SAVE | MergeSessionManager is unavailable."
        );

        return false;
    }

    if (saveData.mergeGameplay == null)
    {
        saveData.mergeGameplay =
            new MergeGameplaySaveData();
    }

    if (!mergeSessionManager.CaptureToSaveData(
            saveData.mergeGameplay))
    {
        Debug.LogError(
            "SAVE | Merge session capture failed."
        );

        return false;
    }

    Debug.Log(
        "SAVE CAPTURE | Merge Session | " +
        $"Has Session: " +
        $"{saveData.mergeGameplay.hasSession} | " +
        $"Board: " +
        $"{saveData.mergeGameplay.boardDesserts.Count} | " +
        $"Shelf: " +
        $"{saveData.mergeGameplay.shelfDesserts.Count} | " +
        $"Orders: " +
        $"{saveData.mergeGameplay.customerOrders.Count} | " +
        $"Next Order ID: " +
        $"#{saveData.mergeGameplay.nextOrderId} | " +
        $"Next Dessert: " +
        $"T{saveData.mergeGameplay.nextDessertTier}"
    );

    return true;
}

    // ==================================================
    // RESTORE - ECONOMY
    // ==================================================

    private bool RestoreEconomy(
        PlayerSaveData saveData)
    {
        if (saveData == null)
        {
            Debug.LogError(
                "LOAD | Cannot restore economy from " +
                "null PlayerSaveData."
            );

            return false;
        }

        if (saveData.economy == null)
        {
            Debug.LogError(
                "LOAD | Economy save data is missing."
            );

            return false;
        }

        EconomyManager economyManager =
            EconomyManager.Instance;

        if (economyManager == null)
        {
            Debug.LogError(
                "LOAD | EconomyManager is unavailable."
            );

            return false;
        }

        economyManager.RestoreCash(
            saveData.economy.cash
        );

        Debug.Log(
            $"LOAD RESTORE | Economy | " +
            $"Cash: ${economyManager.CurrentCash}"
        );

        return true;
    }

    // ==================================================
    // RESTORE - PROGRESSION
    // ==================================================

    private bool RestoreProgression(
        PlayerSaveData saveData)
    {
        if (saveData == null)
        {
            Debug.LogError(
                "LOAD | Cannot restore progression from " +
                "null PlayerSaveData."
            );

            return false;
        }

        if (saveData.progression == null)
        {
            Debug.LogError(
                "LOAD | Progression save data is missing."
            );

            return false;
        }

        PlayerProgressionManager progressionManager =
            PlayerProgressionManager.Instance;

        if (progressionManager == null)
        {
            Debug.LogError(
                "LOAD | PlayerProgressionManager " +
                "is unavailable."
            );

            return false;
        }

        progressionManager.RestoreProgression(
            saveData.progression.ovenLevel,
            saveData.progression.boardSpaceLevel,
            saveData.progression.shelfLevel,
            saveData.progression.customerLevel,
            saveData.progression.moneyMultiplierLevel
        );

        Debug.Log(
            "LOAD RESTORE | Progression | " +
            $"Oven L{progressionManager.OvenLevel} | " +
            $"Board L{progressionManager.BoardSpaceLevel} | " +
            $"Shelf L{progressionManager.ShelfLevel} | " +
            $"Customer L{progressionManager.CustomerLevel} | " +
            $"Money L{progressionManager.MoneyMultiplierLevel}"
        );

        return true;
    }
    // ==================================================
// RESTORE - MERGE SESSION
// ==================================================

private bool RestoreMergeSession(
    PlayerSaveData saveData)
{
    if (saveData == null)
    {
        Debug.LogError(
            "LOAD | Cannot restore merge session from " +
            "null PlayerSaveData."
        );

        return false;
    }

    if (saveData.mergeGameplay == null)
    {
        Debug.LogError(
            "LOAD | Merge gameplay save data is missing."
        );

        return false;
    }

    MergeSessionManager mergeSessionManager =
        MergeSessionManager.Instance;

    if (mergeSessionManager == null)
    {
        Debug.LogError(
            "LOAD | MergeSessionManager is unavailable."
        );

        return false;
    }

    if (!mergeSessionManager.RestoreFromSaveData(
            saveData.mergeGameplay))
    {
        Debug.LogError(
            "LOAD | Merge session restore failed."
        );

        return false;
    }

    Debug.Log(
        "LOAD RESTORE | Merge Session | " +
        $"Has Session: " +
        $"{mergeSessionManager.HasSession}"
    );

    return true;
}

    // ==================================================
    // SAVE CURRENT GAME
    // ==================================================

    public bool SaveCurrentGame()
{
    PlayerSaveData saveData =
        CreateNewSaveData();

    // ----------------------------------------------
    // ECONOMY
    // ----------------------------------------------

    if (!CaptureEconomy(
            saveData))
    {
        Debug.LogError(
            "SAVE | Current game save aborted " +
            "because economy capture failed."
        );

        return false;
    }

    // ----------------------------------------------
    // PROGRESSION
    // ----------------------------------------------

    if (!CaptureProgression(
            saveData))
    {
        Debug.LogError(
            "SAVE | Current game save aborted " +
            "because progression capture failed."
        );

        return false;
    }

    // ----------------------------------------------
    // MERGE SESSION
    // ----------------------------------------------

    if (!CaptureMergeSession(
            saveData))
    {
        Debug.LogError(
            "SAVE | Current game save aborted " +
            "because merge session capture failed."
        );

        return false;
    }

    // ----------------------------------------------
    // WRITE FILE
    // ----------------------------------------------

    return Save(
        saveData
    );
}

    // ==================================================
    // LOAD CURRENT GAME
    // ==================================================

    public bool LoadCurrentGame()
{
    if (!TryLoad(
            out PlayerSaveData saveData))
    {
        Debug.LogWarning(
            "LOAD | Current game load aborted " +
            "because no valid save could be loaded."
        );

        return false;
    }

    // ----------------------------------------------
    // ECONOMY
    // ----------------------------------------------

    if (!RestoreEconomy(
            saveData))
    {
        Debug.LogError(
            "LOAD | Current game load aborted " +
            "because economy restore failed."
        );

        return false;
    }

    // ----------------------------------------------
    // PROGRESSION
    // ----------------------------------------------

    if (!RestoreProgression(
            saveData))
    {
        Debug.LogError(
            "LOAD | Current game load aborted " +
            "because progression restore failed."
        );

        return false;
    }

    // ----------------------------------------------
    // MERGE SESSION
    // ----------------------------------------------

    if (!RestoreMergeSession(
            saveData))
    {
        Debug.LogError(
            "LOAD | Current game load aborted " +
            "because merge session restore failed."
        );

        return false;
    }

    Debug.Log(
        "LOAD | Current game restored successfully."
    );

    return true;
}

    // ==================================================
    // SAVE
    // ==================================================

    public bool Save(
        PlayerSaveData saveData)
    {
        if (saveData == null)
        {
            Debug.LogError(
                "SAVE | Cannot save null PlayerSaveData."
            );

            return false;
        }

        try
        {
            SanitizeSaveData(
                saveData
            );

            saveData.saveVersion =
                CurrentSaveVersion;

            string json =
                JsonUtility.ToJson(
                    saveData,
                    true
                );

            File.WriteAllText(
                SaveFilePath,
                json
            );

            Debug.Log(
                $"SAVE | Successfully wrote save file.\n" +
                $"Path: {SaveFilePath}"
            );

            return true;
        }
        catch (Exception exception)
        {
            Debug.LogError(
                $"SAVE | Failed to write save file.\n" +
                $"{exception}"
            );

            return false;
        }
    }

    // ==================================================
    // LOAD
    // ==================================================

    public bool TryLoad(
        out PlayerSaveData saveData)
    {
        saveData = null;

        if (!SaveFileExists())
        {
            Debug.LogWarning(
                "LOAD | No save file exists."
            );

            return false;
        }

        try
        {
            string json =
                File.ReadAllText(
                    SaveFilePath
                );

            if (string.IsNullOrWhiteSpace(
                    json))
            {
                Debug.LogError(
                    "LOAD | Save file is empty."
                );

                return false;
            }

            PlayerSaveData loadedData =
                JsonUtility.FromJson<
                    PlayerSaveData>(
                        json
                    );

            if (loadedData == null)
            {
                Debug.LogError(
                    "LOAD | JSON produced null " +
                    "PlayerSaveData."
                );

                return false;
            }

            if (!IsSupportedVersion(
                    loadedData.saveVersion))
            {
                Debug.LogError(
                    $"LOAD | Unsupported save version: " +
                    $"{loadedData.saveVersion}. " +
                    $"Current version: " +
                    $"{CurrentSaveVersion}."
                );

                return false;
            }

            SanitizeSaveData(
                loadedData
            );

            saveData =
                loadedData;

            Debug.Log(
                $"LOAD | Successfully read save file.\n" +
                $"Path: {SaveFilePath}"
            );

            return true;
        }
        catch (Exception exception)
        {
            Debug.LogError(
                $"LOAD | Failed to read save file.\n" +
                $"{exception}"
            );

            saveData = null;

            return false;
        }
    }

    // ==================================================
    // VERSION
    // ==================================================

    private bool IsSupportedVersion(
        int version)
    {
        return version ==
            CurrentSaveVersion;
    }

    // ==================================================
    // SANITIZATION
    // ==================================================

    private void SanitizeSaveData(
        PlayerSaveData saveData)
    {
        if (saveData == null)
            return;

        // ----------------------------------------------
        // ECONOMY
        // ----------------------------------------------

        if (saveData.economy == null)
        {
            saveData.economy =
                new EconomySaveData();
        }

        if (saveData.economy.cash < 0)
        {
            saveData.economy.cash =
                0;
        }

        // ----------------------------------------------
        // PROGRESSION
        // ----------------------------------------------

        if (saveData.progression == null)
        {
            saveData.progression =
                new ProgressionSaveData();
        }

        saveData.progression.ovenLevel =
            Mathf.Max(
                1,
                saveData.progression.ovenLevel
            );

        saveData.progression.boardSpaceLevel =
            Mathf.Max(
                1,
                saveData.progression.boardSpaceLevel
            );

        saveData.progression.shelfLevel =
            Mathf.Max(
                1,
                saveData.progression.shelfLevel
            );

        saveData.progression.customerLevel =
            Mathf.Max(
                1,
                saveData.progression.customerLevel
            );

        saveData.progression.moneyMultiplierLevel =
            Mathf.Max(
                1,
                saveData.progression
                    .moneyMultiplierLevel
            );

        // ----------------------------------------------
        // MERGE GAMEPLAY
        // ----------------------------------------------

        if (saveData.mergeGameplay == null)
        {
            saveData.mergeGameplay =
                new MergeGameplaySaveData();
        }

        if (saveData.mergeGameplay.boardDesserts ==
            null)
        {
            saveData.mergeGameplay.boardDesserts =
                new System.Collections.Generic.List<
                    BoardDessertSaveData>();
        }

        if (saveData.mergeGameplay.shelfDesserts ==
            null)
        {
            saveData.mergeGameplay.shelfDesserts =
                new System.Collections.Generic.List<
                    ShelfDessertSaveData>();
        }

        if (saveData.mergeGameplay.customerOrders ==
            null)
        {
            saveData.mergeGameplay.customerOrders =
                new System.Collections.Generic.List<
                    CustomerOrderSaveData>();
        }

        saveData.mergeGameplay.nextOrderId =
            Mathf.Max(
                1,
                saveData.mergeGameplay.nextOrderId
            );

        if (saveData.mergeGameplay.nextDessertTier <
            -1)
        {
            saveData.mergeGameplay.nextDessertTier =
                -1;
        }

        SanitizeBoardDesserts(
            saveData.mergeGameplay
                .boardDesserts
        );

        SanitizeShelfDesserts(
            saveData.mergeGameplay
                .shelfDesserts
        );

        SanitizeCustomerOrders(
            saveData.mergeGameplay
                .customerOrders
        );
    }

    private void SanitizeBoardDesserts(
        System.Collections.Generic.List<
            BoardDessertSaveData> desserts)
    {
        for (int i = desserts.Count - 1;
             i >= 0;
             i--)
        {
            BoardDessertSaveData dessert =
                desserts[i];

            if (dessert == null ||
                dessert.cellIndex < 0 ||
                dessert.dessertTier <= 0)
            {
                desserts.RemoveAt(i);
            }
        }
    }

    private void SanitizeShelfDesserts(
        System.Collections.Generic.List<
            ShelfDessertSaveData> desserts)
    {
        for (int i = desserts.Count - 1;
             i >= 0;
             i--)
        {
            ShelfDessertSaveData dessert =
                desserts[i];

            if (dessert == null ||
                dessert.slotIndex < 0 ||
                dessert.dessertTier <= 0)
            {
                desserts.RemoveAt(i);
            }
        }
    }

    private void SanitizeCustomerOrders(
        System.Collections.Generic.List<
            CustomerOrderSaveData> orders)
    {
        for (int i = orders.Count - 1;
             i >= 0;
             i--)
        {
            CustomerOrderSaveData order =
                orders[i];

            if (order == null ||
                order.customerIndex < 0 ||
                order.orderId <= 0 ||
                string.IsNullOrWhiteSpace(
                    order.definitionId))
            {
                orders.RemoveAt(i);
            }
        }
    }

    // ==================================================
    // DEBUG TEST SAVE
    // ==================================================

    [ContextMenu("Debug Write Test Save")]
    private void DebugWriteTestSave()
    {
        PlayerSaveData testData =
            CreateNewSaveData();

        testData.economy.cash =
            12345;

        testData.progression.ovenLevel =
            2;

        testData.progression.boardSpaceLevel =
            3;

        testData.progression.shelfLevel =
            2;

        testData.progression.customerLevel =
            2;

        testData.progression.moneyMultiplierLevel =
            2;

        testData.mergeGameplay.hasSession =
            true;

        testData.mergeGameplay.nextOrderId =
            42;

        testData.mergeGameplay.nextDessertTier =
            5;

        testData.mergeGameplay.boardDesserts.Add(
            new BoardDessertSaveData(
                0,
                2
            )
        );

        testData.mergeGameplay.boardDesserts.Add(
            new BoardDessertSaveData(
                4,
                7
            )
        );

        testData.mergeGameplay.shelfDesserts.Add(
            new ShelfDessertSaveData(
                0,
                3
            )
        );

        bool success =
            Save(testData);

        if (success)
        {
            Debug.Log(
                "SAVE TEST | Test PlayerSaveData " +
                "was serialized successfully."
            );
        }
    }

    // ==================================================
    // DEBUG TEST LOAD
    // ==================================================

    [ContextMenu("Debug Read Test Save")]
    private void DebugReadTestSave()
    {
        if (!TryLoad(
                out PlayerSaveData saveData))
        {
            Debug.LogError(
                "LOAD TEST | Could not load " +
                "PlayerSaveData."
            );

            return;
        }

        Debug.Log(
            "LOAD TEST | " +
            $"Version: {saveData.saveVersion} | " +
            $"Cash: {saveData.economy.cash} | " +
            $"Oven: L{saveData.progression.ovenLevel} | " +
            $"Board: L{saveData.progression.boardSpaceLevel} | " +
            $"Shelf: L{saveData.progression.shelfLevel} | " +
            $"Customer: L{saveData.progression.customerLevel} | " +
            $"Money: L{saveData.progression.moneyMultiplierLevel}"
        );

        Debug.Log(
            "LOAD TEST | " +
            $"Has Session: " +
            $"{saveData.mergeGameplay.hasSession} | " +
            $"Board Desserts: " +
            $"{saveData.mergeGameplay.boardDesserts.Count} | " +
            $"Shelf Desserts: " +
            $"{saveData.mergeGameplay.shelfDesserts.Count} | " +
            $"Customer Orders: " +
            $"{saveData.mergeGameplay.customerOrders.Count} | " +
            $"Next Order ID: " +
            $"{saveData.mergeGameplay.nextOrderId} | " +
            $"Next Dessert: T" +
            $"{saveData.mergeGameplay.nextDessertTier}"
        );
    }

    // ==================================================
    // DEBUG FILE TOOLS
    // ==================================================

    [ContextMenu("Debug Print Save Path")]
    private void DebugPrintSavePath()
    {
        Debug.Log(
            $"SAVE | Path: {SaveFilePath}"
        );
    }

    [ContextMenu("Debug Check Save File")]
    private void DebugCheckSaveFile()
    {
        Debug.Log(
            $"SAVE | File Exists: " +
            $"{SaveFileExists()}"
        );
    }

    // ==================================================
    // DEBUG SAVE MANAGEMENT
    // ==================================================

    [ContextMenu("Debug Create Fresh Save")]
    private void DebugCreateFreshSave()
    {
        PlayerSaveData freshSave =
            CreateNewSaveData();

        bool success =
            Save(freshSave);

        if (!success)
        {
            Debug.LogError(
                "SAVE DEBUG | Failed to create " +
                "fresh save."
            );

            return;
        }

        Debug.Log(
            "SAVE DEBUG | Fresh save created."
        );

        PrintSaveSummary(
            freshSave
        );
    }

    [ContextMenu("Debug Delete Save")]
    private void DebugDeleteSave()
    {
        if (!SaveFileExists())
        {
            Debug.Log(
                "SAVE DEBUG | No save file exists " +
                "to delete."
            );

            return;
        }

        try
        {
            File.Delete(
                SaveFilePath
            );

            Debug.Log(
                "SAVE DEBUG | Save file deleted."
            );
        }
        catch (Exception exception)
        {
            Debug.LogError(
                $"SAVE DEBUG | Failed to delete " +
                $"save file.\n{exception}"
            );
        }
    }

    [ContextMenu("Debug Print Save Summary")]
    private void DebugPrintSaveSummary()
    {
        if (!TryLoad(
                out PlayerSaveData saveData))
        {
            Debug.LogWarning(
                "SAVE DEBUG | No valid save data " +
                "could be summarized."
            );

            return;
        }

        PrintSaveSummary(
            saveData
        );
    }

    [ContextMenu("Debug Save Current Game")]
    private void DebugSaveCurrentGame()
    {
        bool success =
            SaveCurrentGame();

        if (success)
        {
            Debug.Log(
                "SAVE DEBUG | Current game " +
                "saved successfully."
            );
        }
        else
        {
            Debug.LogError(
                "SAVE DEBUG | Current game " +
                "save failed."
            );
        }
    }

    [ContextMenu("Debug Load Current Game")]
    private void DebugLoadCurrentGame()
    {
        bool success =
            LoadCurrentGame();

        if (success)
        {
            Debug.Log(
                "LOAD DEBUG | Current game " +
                "loaded successfully."
            );
        }
        else
        {
            Debug.LogWarning(
                "LOAD DEBUG | Current game " +
                "load failed."
            );
        }
    }

    private void PrintSaveSummary(
        PlayerSaveData saveData)
    {
        if (saveData == null)
        {
            Debug.LogWarning(
                "SAVE DEBUG | Save data is null."
            );

            return;
        }

        Debug.Log(
            "========== SAVE SUMMARY ==========\n" +
            $"Version: {saveData.saveVersion}\n" +
            $"Cash: ${saveData.economy.cash}\n" +
            "\n" +
            "PROGRESSION\n" +
            $"Oven: L{saveData.progression.ovenLevel}\n" +
            $"Board Space: " +
            $"L{saveData.progression.boardSpaceLevel}\n" +
            $"Shelf: L{saveData.progression.shelfLevel}\n" +
            $"Customer: " +
            $"L{saveData.progression.customerLevel}\n" +
            $"Money Multiplier: " +
            $"L{saveData.progression.moneyMultiplierLevel}\n" +
            "\n" +
            "MERGE SESSION\n" +
            $"Has Session: " +
            $"{saveData.mergeGameplay.hasSession}\n" +
            $"Board Desserts: " +
            $"{saveData.mergeGameplay.boardDesserts.Count}\n" +
            $"Shelf Desserts: " +
            $"{saveData.mergeGameplay.shelfDesserts.Count}\n" +
            $"Customer Orders: " +
            $"{saveData.mergeGameplay.customerOrders.Count}\n" +
            $"Next Order ID: " +
            $"{saveData.mergeGameplay.nextOrderId}\n" +
            $"Next Dessert Tier: " +
            $"{saveData.mergeGameplay.nextDessertTier}\n" +
            "=================================="
        );
    }
}