using System;
using System.IO;
using System.Text;
using UnityEngine;
public class SaveManager : MonoBehaviour
{
    // Root JSON extension avoids changing the project's existing data classes.
    // It describes the MERGE SNAPSHOT, never the latest purchased progression.
    [Serializable]
    private class CustomerCapacityMetadata
    {
        public int mergeSessionCustomerCapacity;
    }
    private PlayerSaveData capacityLoadedData;
    private int loadedCustomerCapacity;
    private MergeSessionData capacitySession;
    private string capacityFingerprint;
    private int sessionCustomerCapacity;
    public void RecordSessionCustomerCapacity(MergeSessionData data, int capacity)
    {
        capacitySession = data;
        capacityFingerprint = RestorationVerification.Fingerprint(data);
        sessionCustomerCapacity = capacity;
    }
    public bool TryGetSessionCustomerCapacity(MergeSessionData data, int currentCapacity,
        out int capacity)
    {
        capacity = 0;
        if (ReferenceEquals(data, capacitySession) && string.Equals(capacityFingerprint,
            RestorationVerification.Fingerprint(data), StringComparison.Ordinal))
            capacity = sessionCustomerCapacity;
        // Legacy saves can be inferred only when ALL current slots are present.
        // A shorter prefix is ambiguous; it needs an explicit backup-based migration.
        if (capacity == 0 && data != null && data.customerOrders != null &&
            data.customerOrders.Count == currentCapacity)
            capacity = currentCapacity;
        return capacity >= 1 && capacity <= currentCapacity;
    }
    private static string SerializeWithCapacity(PlayerSaveData data, int capacity)
    {
        string json = JsonUtility.ToJson(data, false);
        return json.Substring(0, json.Length - 1) +
            ",\"mergeSessionCustomerCapacity\":" + capacity.ToString(System.Globalization.CultureInfo.InvariantCulture) + "}";
    }
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
    // Main-thread APIs. The guard covers capture, serialization, IO and logging.
    private bool saveInProgress;
    private bool loadInProgress;
    private bool lifecycleCallbackInProgress;
    private bool lifecycleSavingReady;
    private bool restorationFailed;
    private static readonly UTF8Encoding SaveEncoding = new UTF8Encoding(false, true);
    public bool IsLifecycleSavingReady => lifecycleSavingReady;
    private bool CanWriteCurrentState()
    {
        var startup = GameStartupCoordinator.Instance;
        return Instance == this && !restorationFailed && lifecycleSavingReady &&
            startup != null && startup.IsStartupComplete && startup.IsGameplayReady;
    }
    // Call before startup/reinitialization or before restoring live scene objects.
    public void SuspendLifecycleSaving()
    {
        lifecycleSavingReady = false;
    }
    // Call from the bootstrap coordinator AFTER all initialization and restoration,
    // including the live merge scene. Singleton existence alone is not readiness.
    public bool MarkGameplayReadyForLifecycleSaves()
    {
        var startup = GameStartupCoordinator.Instance;
        if (startup == null || !startup.IsStartupComplete || !startup.IsGameplayReady ||
            restorationFailed || Instance != this || saveInProgress || loadInProgress ||
            EconomyManager.Instance == null ||
            PlayerProgressionManager.Instance == null ||
            MergeSessionManager.Instance == null)
        {
            return false;
        }
        lifecycleSavingReady = true;
        return true;
    }
    private bool CanSaveFromLifecycle()
    {
        return CanWriteCurrentState() &&
            !saveInProgress && !loadInProgress && !lifecycleCallbackInProgress &&
            EconomyManager.Instance != null &&
            PlayerProgressionManager.Instance != null &&
            MergeSessionManager.Instance != null;
    }
    private void OnDestroy()
    {
        lifecycleSavingReady = false;
        if (Instance == this)
            Instance = null;
    }
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
    // ANDROID / MOBILE APPLICATION PAUSE
    // ==================================================
    private void OnApplicationPause(bool isPaused)
    {
        if (!CanSaveFromLifecycle())
            return;
        lifecycleCallbackInProgress = true;
        try { HandleApplicationPause(isPaused); }
        finally { lifecycleCallbackInProgress = false; }
    }
    private void HandleApplicationPause(bool isPaused)
    {
        // ----------------------------------------------
        // IGNORE RESUME
        // ----------------------------------------------
        if (!isPaused)
        {
            Debug.Log(
                "LIFECYCLE | Application resumed."
            );
            return;
        }
        // ----------------------------------------------
        // IGNORE DUPLICATE MANAGER
        // ----------------------------------------------
        if (Instance != this)
        {
            return;
        }
        // ----------------------------------------------
        // SAVE ON BACKGROUND
        // ----------------------------------------------
        bool saveSucceeded =
            SaveCurrentGame();
        if (!saveSucceeded)
        {
            Debug.LogError(
                "LIFECYCLE | Application pause save failed."
            );
            return;
        }
        Debug.Log(
            "LIFECYCLE | Application pause save completed."
        );
    }
    // ==================================================
    // APPLICATION QUIT SAVE FALLBACK
    // ==================================================
    private void OnApplicationQuit()
    {
        if (!CanSaveFromLifecycle())
            return;
        lifecycleCallbackInProgress = true;
        try { HandleApplicationQuit(); }
        finally { lifecycleCallbackInProgress = false; }
    }
    private void HandleApplicationQuit()
    {
        // ----------------------------------------------
        // IGNORE DUPLICATE SAVE MANAGER
        // ----------------------------------------------
        if (Instance != this)
        {
            return;
        }
        // ----------------------------------------------
        // ATTEMPT FINAL SAVE
        // ----------------------------------------------
        bool saveSucceeded =
            SaveCurrentGame();
        if (!saveSucceeded)
        {
            Debug.LogError(
                "LIFECYCLE | Application quit save failed."
            );
            return;
        }
        Debug.Log(
            "LIFECYCLE | Application quit save completed."
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
    // CAPTURE - LIVE MERGE GAMEPLAY
    // ==================================================
    private bool CaptureLiveMergeGameplayIfAvailable()
    {
        MergeSessionController mergeSessionController =
            FindFirstObjectByType<MergeSessionController>();
        /*
         * No MergeSessionController is expected while
         * the player is in MainBakery.
         *
         * In that case we preserve the existing
         * MergeSessionManager snapshot instead of
         * clearing it.
         */
        if (mergeSessionController == null)
        {
            Debug.Log(
                "SAVE CAPTURE | " +
                "No live MergeSessionController found. " +
                "Using existing merge session snapshot."
            );
            return true;
        }
        Debug.Log(
            "SAVE CAPTURE | " +
            "Live merge gameplay detected. " +
            "Capturing current gameplay state."
        );
        if (!mergeSessionController.TryCaptureSession())
        {
            Debug.LogError(
                "SAVE CAPTURE | " +
                "Live merge gameplay capture failed."
            );
            return false;
        }
        Debug.Log(
            "SAVE CAPTURE | " +
            "Live merge gameplay captured successfully."
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
        if (economyManager.CurrentCash != saveData.economy.cash) return false;
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
        if (!progressionManager.ValidateRestorationDefinitions(out string reason))
        {
            Debug.LogError("LOAD | " + reason);
            return false;
        }
        progressionManager.RestoreProgression(
            saveData.progression.ovenLevel,
            saveData.progression.boardSpaceLevel,
            saveData.progression.shelfLevel,
            saveData.progression.customerLevel,
            saveData.progression.moneyMultiplierLevel
        );
        int[] expectedLevels = { saveData.progression.ovenLevel,
            saveData.progression.boardSpaceLevel, saveData.progression.shelfLevel,
            saveData.progression.customerLevel, saveData.progression.moneyMultiplierLevel };
        UpgradeType[] types = { UpgradeType.Oven, UpgradeType.BoardSpace, UpgradeType.Shelf,
            UpgradeType.Customer, UpgradeType.MoneyMultiplier };
        for (int i = 0; i < types.Length; i++)
            if (progressionManager.GetLevel(types[i]) != Mathf.Clamp(expectedLevels[i], 1,
                    progressionManager.GetMaxLevel(types[i]))) return false;
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
        string expected = RestorationVerification.Fingerprint(saveData.mergeGameplay);
        if (!mergeSessionManager.RestoreFromSaveData(
                saveData.mergeGameplay))
        {
            Debug.LogError(
                "LOAD | Merge session restore failed."
            );
            return false;
        }
        var actual = new MergeGameplaySaveData();
        if (!mergeSessionManager.CaptureToSaveData(actual) ||
            !string.Equals(expected, RestorationVerification.Fingerprint(actual), StringComparison.Ordinal))
        {
            Debug.LogError("LOAD | Persistent merge session differs from the saved data.");
            return false;
        }
        RecordSessionCustomerCapacity(mergeSessionManager.SessionData,
            ReferenceEquals(saveData, capacityLoadedData) ? loadedCustomerCapacity : 0);
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
        // Silent rejection prevents recursive log handlers from recursing again.
        // Rejected callers receive false and must retry; no request is reported saved.
        if (!CanWriteCurrentState() || saveInProgress || loadInProgress)
            return false;
        saveInProgress = true;
        try
        {
            return SaveCurrentGameCore();
        }
        catch (Exception exception)
        {
            Debug.LogError($"SAVE | Current game save failed.\n{exception}");
            return false;
        }
        finally
        {
            saveInProgress = false;
        }
    }
    private bool SaveCurrentGameCore()
    {
        // ----------------------------------------------
        // LIVE MERGE GAMEPLAY
        // ----------------------------------------------
        /*
         * If live merge gameplay currently exists,
         * capture it before building PlayerSaveData.
         *
         * If we're in MainBakery, the existing
         * MergeSessionManager snapshot is preserved.
         */
        if (!CaptureLiveMergeGameplayIfAvailable())
        {
            Debug.LogError(
                "SAVE | Current game save aborted " +
                "because live merge gameplay capture failed."
            );
            return false;
        }
        // ----------------------------------------------
        // CREATE SAVE DATA
        // ----------------------------------------------
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
        if (!SaveCore(saveData))
        {
            Debug.LogError(
                "SAVE | Current game save failed " +
                "while writing the save file."
            );
            return false;
        }
        Debug.Log(
            "SAVE | Current game saved successfully."
        );
        return true;
    }
    // ==================================================
    // LOAD CURRENT GAME
    // ==================================================
    public bool LoadCurrentGame()
    {
        if (saveInProgress || loadInProgress)
            return false;
        // A failed/partial restore must never enable automatic saving.
        // The coordinator must explicitly mark ready again after scene restoration.
        SuspendLifecycleSaving();
        GameStartupCoordinator.Instance?.BeginPersistentReload();
        restorationFailed = true;
        loadInProgress = true;
        try
        {
            bool success = LoadCurrentGameCore();
            restorationFailed = !success;
            if (success) GameStartupCoordinator.Instance?.CompletePersistentReload();
            else GameStartupCoordinator.Instance?.ReportGameplayRestorationFailure("Persistent restoration failed.");
            return success;
        }
        catch (Exception exception)
        {
            GameStartupCoordinator.Instance?.ReportGameplayRestorationFailure("Persistent restoration threw an exception.");
            Debug.LogError($"LOAD | Current game restore failed.\n{exception}");
            return false;
        }
        finally
        {
            loadInProgress = false;
        }
    }
    private bool LoadCurrentGameCore()
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
    public bool Save(PlayerSaveData saveData)
    {
        // Explicit and debug writes obey the same restoration gate as lifecycle writes.
        if (!CanWriteCurrentState() || saveInProgress || loadInProgress)
            return false;
        saveInProgress = true;
        try
        {
            return SaveCore(saveData);
        }
        catch (Exception exception)
        {
            Debug.LogError($"SAVE | Failed to write save file.\n{exception}");
            return false;
        }
        finally
        {
            saveInProgress = false;
        }
    }
    // Only called while the outer public operation owns the save guard.
    private bool SaveCore(PlayerSaveData saveData)
    {
        if (saveData == null)
        {
            Debug.LogError("SAVE | Cannot save null PlayerSaveData.");
            return false;
        }
        // Preserve the original normalization and caller-data mutation behavior.
        SanitizeSaveData(saveData);
        saveData.saveVersion = CurrentSaveVersion;
        // One canonical serializer configuration for comparison AND writing.
        // Preserve list order and string whitespace; do not sort gameplay lists.
        int capacity = 0;
        if (saveData.mergeGameplay.hasSession)
        {
            var session = MergeSessionManager.Instance;
            var progression = PlayerProgressionManager.Instance;
            if (session == null || progression == null ||
                !TryGetSessionCustomerCapacity(session.SessionData, progression.ActiveCustomerOrders, out capacity))
            {
                Debug.LogError("SAVE | Customer capacity provenance is missing.");
                return false;
            }
            var snapshot = new MergeGameplaySaveData();
            if (!session.CaptureToSaveData(snapshot) || !string.Equals(
                RestorationVerification.Fingerprint(snapshot),
                RestorationVerification.Fingerprint(saveData.mergeGameplay), StringComparison.Ordinal))
                return false;
        }
        string json = SerializeWithCapacity(saveData, capacity);
        if (!IsValidSerializedSnapshot(json))
        {
            Debug.LogError("SAVE | Serialized snapshot failed validation.");
            return false;
        }
        byte[] expectedBytes = SaveEncoding.GetBytes(json);
        string path = SaveFilePath;
        // A disk file is trusted only if ALL bytes match the validated snapshot.
        // Never sanitize disk content into equality; never trust a memory cache,
        // file timestamp, length alone, or JsonUtility's missing-field defaults.
        if (DiskMatchesSnapshot(path, expectedBytes))
        {
            Debug.Log("SAVE | Unchanged validated disk content; write skipped.");
            return true;
        }
        // Step 12.8.8.1: only validated temporary bytes reach the primary path.
        WriteSnapshotAtomically(path, expectedBytes);
        if (!DiskMatchesSnapshot(path, expectedBytes))
        {
            Debug.LogError("SAVE | Written file could not be verified.");
            return false;
        }
        Debug.Log($"SAVE | Successfully wrote save file.\nPath: {path}");
        return true;
    }
    // The caller owns saveInProgress. One process/main-thread writer is required.
    // Temporary and primary files must stay in the same directory/filesystem.
    private void WriteSnapshotAtomically(string path, byte[] expectedBytes)
    {
        string temporaryPath = path + ".tmp";
        Directory.CreateDirectory(Path.GetDirectoryName(path));
        // A stale temp is never loaded or promoted. Only a fresh save may replace it.
        using (var stream = new FileStream(temporaryPath, FileMode.Create,
            FileAccess.Write, FileShare.None))
        {
            stream.Write(expectedBytes, 0, expectedBytes.Length);
            stream.Flush(true);
        }
        // Re-read the CLOSED file, compare every byte, then validate that actual JSON.
        // This preserves the metadata and canonical serialization checks, without
        // mutating capacityLoadedData or the live session's provenance.
        byte[] actualBytes = File.ReadAllBytes(temporaryPath);
        if (actualBytes.Length != expectedBytes.Length)
            throw new IOException("Temporary save length differs from the validated snapshot.");
        for (int i = 0; i < actualBytes.Length; i++)
            if (actualBytes[i] != expectedBytes[i])
                throw new IOException("Temporary save bytes differ from the validated snapshot.");
        if (!IsValidSerializedSnapshot(SaveEncoding.GetString(actualBytes)))
            throw new IOException("Temporary save JSON failed validation.");
        // No backup rotation here: an existing primary is not necessarily trustworthy.
        // In particular, never pass .bak to File.Replace or copy primary over .bak.
        // Backup validation/rotation/recovery is a later substep.
        CommitTemporaryFile(temporaryPath, path);
        // On failure, retain remaining .tmp for diagnosis. Never delete the primary
        // or try a copy/delete fallback. The outer Save operation reports failure.
    }
#if UNITY_EDITOR_WIN || UNITY_STANDALONE_WIN
    [System.Runtime.InteropServices.DllImport("kernel32.dll",
        EntryPoint = "MoveFileExW", CharSet = System.Runtime.InteropServices.CharSet.Unicode,
        ExactSpelling = true, SetLastError = true)]
    [return: System.Runtime.InteropServices.MarshalAs(System.Runtime.InteropServices.UnmanagedType.Bool)]
    private static extern bool MoveSaveFileWindows(string source, string destination, uint flags);
#elif UNITY_ANDROID && !UNITY_EDITOR
    [System.Runtime.InteropServices.DllImport("libc", EntryPoint = "rename",
        CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl,
        ExactSpelling = true, SetLastError = true)]
    private static extern int RenameSaveFileAndroid(byte[] source, byte[] destination);
#endif
    private static void CommitTemporaryFile(string temporaryPath, string path)
    {
#if UNITY_EDITOR_WIN || UNITY_STANDALONE_WIN
        // Same-volume rename, replace if present. Deliberately omit COPY_ALLOWED.
        const uint ReplaceExisting = 0x1;
        const uint WriteThrough = 0x8;
        if (!MoveSaveFileWindows(temporaryPath, path, ReplaceExisting | WriteThrough))
        {
            int error = System.Runtime.InteropServices.Marshal.GetLastWin32Error();
            throw new IOException("Save commit failed (Windows error " + error + ").");
        }
#elif UNITY_ANDROID && !UNITY_EDITOR
        // Explicit NUL-terminated UTF-8 paths avoid ANSI marshaling ambiguity.
        // POSIX rename replaces an existing destination without an unlink gap.
        if (RenameSaveFileAndroid(SaveEncoding.GetBytes(temporaryPath + "\0"),
                SaveEncoding.GetBytes(path + "\0")) != 0)
        {
            int error = System.Runtime.InteropServices.Marshal.GetLastWin32Error();
            throw new IOException("Save commit failed (Android errno " + error + ").");
        }
#else
        throw new PlatformNotSupportedException(
            "Atomic save commit is configured for Windows Editor/player and Android player only.");
#endif
    }
    private bool IsValidSerializedSnapshot(string json)
    {
        if (string.IsNullOrWhiteSpace(json))
            return false;
        PlayerSaveData check = JsonUtility.FromJson<PlayerSaveData>(json);
        if (check == null || !IsSupportedVersion(check.saveVersion) ||
            check.economy == null || check.progression == null ||
            check.mergeGameplay == null ||
            check.mergeGameplay.boardDesserts == null ||
            check.mergeGameplay.shelfDesserts == null ||
            check.mergeGameplay.customerOrders == null)
        {
            return false;
        }
        int capacity = JsonUtility.FromJson<CustomerCapacityMetadata>(json).mergeSessionCustomerCapacity;
        if (check.mergeGameplay.hasSession && (capacity < 1 || capacity > 4)) return false;
        if (!string.Equals(json, SerializeWithCapacity(check, capacity), StringComparison.Ordinal))
            return false;
        SanitizeSaveData(check);
        return string.Equals(json, SerializeWithCapacity(check, capacity), StringComparison.Ordinal);
    }
    private static bool DiskMatchesSnapshot(string path, byte[] expected)
    {
        try
        {
            // Read failures, missing files and partial files all force a write attempt.
            byte[] actual = File.ReadAllBytes(path);
            if (actual.Length != expected.Length)
                return false;
            for (int i = 0; i < actual.Length; i++)
            {
                if (actual[i] != expected[i])
                    return false;
            }
            return true;
        }
        catch (IOException) { return false; }
        catch (UnauthorizedAccessException) { return false; }
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
            // Do not discard invalid gameplay rows and then verify the reduced snapshot.
            // Missing lists and malformed entries are failures for an existing save.
            string originalGameplay = RestorationVerification.Fingerprint(loadedData.mergeGameplay);
            SanitizeSaveData(
                loadedData
            );
            if (!string.Equals(originalGameplay,
                    RestorationVerification.Fingerprint(loadedData.mergeGameplay), StringComparison.Ordinal))
            {
                Debug.LogError("LOAD | Gameplay data requires destructive sanitization. Save retained unchanged.");
                return false;
            }
            var metadata = JsonUtility.FromJson<CustomerCapacityMetadata>(json);
            if (metadata == null || metadata.mergeSessionCustomerCapacity < 0 ||
                metadata.mergeSessionCustomerCapacity > 4) return false;
            capacityLoadedData = loadedData;
            loadedCustomerCapacity = metadata.mergeSessionCustomerCapacity;
            saveData = loadedData;
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
        if (saveInProgress || loadInProgress)
            return;
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
    // ==================================================
    // DEBUG - SIMULATE APPLICATION PAUSE
    // ==================================================
    [ContextMenu("Debug Simulate Application Pause")]
    private void DebugSimulateApplicationPause()
    {
        OnApplicationPause(true);
    }
    // ==================================================
    // DEBUG - SIMULATE APPLICATION QUIT
    // ==================================================
    [ContextMenu("Debug Simulate Application Quit")]
    private void DebugSimulateApplicationQuit()
    {
        OnApplicationQuit();
    }
}
