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

        // Guard even explicit/debug saves against overwriting a file written
        // by a different game build. A failed load normally blocks saving, but
        // this check also protects against an out-of-band file replacement.
        // An unreadable/corrupt primary is handled by the existing recovery
        // path; only a positively identified unsupported version is blocked.
        if (File.Exists(path))
        {
            byte[] onDiskBytes = File.ReadAllBytes(path);
            int diskVersion;
            MigrationDecision diskDecision = EvaluateMigration(onDiskBytes, out diskVersion);
            if (IsMigrationBlocked(diskDecision))
            {
                Debug.LogError("SAVE VERSION | Refusing to overwrite unsupported or ambiguous " +
                    "on-disk save version (" + diskVersion + ").");
                return false;
            }
        }

        // A disk file is trusted only if ALL bytes match the validated snapshot.

        // Never sanitize disk content into equality; never trust a memory cache,

        // file timestamp, length alone, or JsonUtility's missing-field defaults.

        if (DiskMatchesSnapshot(path, expectedBytes))

        {

            Debug.Log("SAVE | Unchanged validated disk content; write skipped.");

            return true;

        }

        // Step 12.8.8.2: preserve a validated old primary before committing new bytes.

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

        // Backup the OLD primary, never the new snapshot or a stale temporary file.

        // A backup IO failure propagates before the primary can be replaced.

        CreateValidatedBackup(path);

        CommitTemporaryFile(temporaryPath, path);

        // On failure, retain remaining .tmp for diagnosis. Never delete the primary

        // or try a copy/delete fallback. The outer Save operation reports failure.

    }

    private void CreateValidatedBackup(string path)

    {

        byte[] primaryBytes;

        try

        {

            // Read once: validation and staging must use the same captured bytes.

            // File.Exists would hide access/IO errors and misclassify them as absence.

            primaryBytes = File.ReadAllBytes(path);

        }

        catch (FileNotFoundException)

        {

            // First save: there is no previous primary to back up.

            return;

        }

        if (!IsValidBackupCandidate(primaryBytes))

        {

            Debug.LogWarning("SAVE BACKUP | Existing primary failed strict backup validation; " +

                "backup retained unchanged.");

            return;

        }

        string backupPath = path + ".bak";

        string backupTemporaryPath = backupPath + ".tmp";

        if (DiskMatchesSnapshot(backupPath, primaryBytes))

            return; // Exact bytes of an independently validated primary already exist.

        // Never open .bak for writing. A stale .bak.tmp is never trusted.

        using (var stream = new FileStream(backupTemporaryPath, FileMode.Create,

            FileAccess.Write, FileShare.None))

        {

            stream.Write(primaryBytes, 0, primaryBytes.Length);

            stream.Flush(true);

        }

        byte[] stagedBytes = File.ReadAllBytes(backupTemporaryPath);

        if (!BytesEqual(stagedBytes, primaryBytes) || !IsValidBackupCandidate(stagedBytes))

            throw new IOException("Backup staging verification failed; primary was not committed.");

        // Defensive check; this does not replace the single-writer requirement.

        if (!DiskMatchesSnapshot(path, primaryBytes))

            throw new IOException("Primary changed while staging its backup; save aborted.");

        // Reuse the same-directory Windows/Android promotion, with no unlink gap

        // and no automatic backup side effect that could copy an unvalidated file.

        CommitTemporaryFile(backupTemporaryPath, backupPath);

        if (!DiskMatchesSnapshot(backupPath, primaryBytes))

            throw new IOException("Promoted backup could not be verified; primary was not committed.");

        Debug.Log("SAVE BACKUP | Validated previous primary preserved.");

    }

    // Pure inspection: never call TryLoad/Restore here or change capacity provenance.

    // Canonical JSON and a non-mutating sanitation round trip are deliberately

    // conservative: legacy, reformatted and unknown-schema files are not rotated.

    private bool IsValidBackupCandidate(byte[] bytes)

    {

        try

        {

            string json = SaveEncoding.GetString(bytes);

            if (!IsValidSerializedSnapshot(json))

                return false;

            var data = JsonUtility.FromJson<PlayerSaveData>(json);

            var metadata = JsonUtility.FromJson<CustomerCapacityMetadata>(json);

            if (metadata == null)

                return false;

            var gameplay = data.mergeGameplay;

            int capacity = metadata.mergeSessionCustomerCapacity;

            if (!gameplay.hasSession)

                return capacity == 0 && gameplay.boardDesserts.Count == 0 &&

                    gameplay.shelfDesserts.Count == 0 && gameplay.customerOrders.Count == 0;

            if (capacity < 1 || capacity > 4 || gameplay.customerOrders.Count != capacity)

                return false;

            var cells = new System.Collections.Generic.HashSet<int>();

            foreach (var dessert in gameplay.boardDesserts)

                if (!cells.Add(dessert.cellIndex))

                    return false;

            var shelves = new System.Collections.Generic.HashSet<int>();

            foreach (var dessert in gameplay.shelfDesserts)

                if (!shelves.Add(dessert.slotIndex))

                    return false;

            var customers = new System.Collections.Generic.HashSet<int>();

            var orderIds = new System.Collections.Generic.HashSet<int>();

            foreach (var order in gameplay.customerOrders)

                if (order.customerIndex >= capacity || !customers.Add(order.customerIndex) ||

                    !orderIds.Add(order.orderId) || order.orderId >= gameplay.nextOrderId)

                    return false;

            return true;

        }

        catch (ArgumentException)

        {

            // JsonUtility parse errors and strict UTF-8 decoding errors are invalid input.

            return false;

        }

    }

    private static bool BytesEqual(byte[] actual, byte[] expected)

    {

        if (actual.Length != expected.Length)

            return false;

        for (int i = 0; i < actual.Length; i++)

            if (actual[i] != expected[i])

                return false;

        return true;

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

    // Step 12.8.9.2 — non-destructive version preflight.
    // Version 1 remains the ONLY supported format. No V2 migration is invented.
    // An explicitly marked future version is never treated as corrupt V1:
    // downgrading from a backup could destroy progress made by a newer build.
    private enum SaveVersionClassification
    {
        MissingOrUnreadable,
        Current,
        UnsupportedOlder,
        UnsupportedFuture,
        Ambiguous
    }

    private static SaveVersionClassification ClassifySaveVersion(byte[] bytes, out int version)
    {
        version = 0;
        if (bytes == null) return SaveVersionClassification.MissingOrUnreadable;
        try
        {
            string json = SaveEncoding.GetString(bytes);
            // Check the literal field, not the JsonUtility default of 0 when absent.
            // Multiple saveVersion declarations are ambiguous and must not be loaded.
            var matches = System.Text.RegularExpressions.Regex.Matches(json,
                @"""saveVersion""\s*:\s*(-?\d+)");
            if (matches.Count > 1) return SaveVersionClassification.Ambiguous;
            if (matches.Count == 0) return SaveVersionClassification.MissingOrUnreadable;
            if (!int.TryParse(matches[0].Groups[1].Value,
                System.Globalization.NumberStyles.Integer,
                System.Globalization.CultureInfo.InvariantCulture, out version))
                return SaveVersionClassification.Ambiguous;
            if (version > CurrentSaveVersion) return SaveVersionClassification.UnsupportedFuture;
            if (version < CurrentSaveVersion) return SaveVersionClassification.UnsupportedOlder;
            return SaveVersionClassification.Current;
        }
        catch (ArgumentException)
        {
            return SaveVersionClassification.MissingOrUnreadable;
        }
    }

    // Step 12.8.9.3 — migration safety boundary.
    // There are deliberately NO registered migrations while V1 is current.
    // This coordinator is a pure decision gate: it never mutates the input,
    // touches a file, changes version numbers, or updates live managers.
    // When V2 is designed, implement an explicit V1 -> V2 transformer and
    // validate the detached result before adding a transactional disk commit.
    private enum MigrationDecision
    {
        LoadCurrent,
        MigrationNotRegistered,
        FutureVersionBlocked,
        AmbiguousVersionBlocked,
        UnreadableVersion
    }

    private static MigrationDecision EvaluateMigration(byte[] sourceBytes, out int sourceVersion)
    {
        SaveVersionClassification classification =
            ClassifySaveVersion(sourceBytes, out sourceVersion);

        switch (classification)
        {
            case SaveVersionClassification.Current:
                return MigrationDecision.LoadCurrent;
            case SaveVersionClassification.UnsupportedOlder:
                // No older-version migrations are registered. Do not reinterpret
                // old data as V1 or manufacture defaults for missing fields.
                return MigrationDecision.MigrationNotRegistered;
            case SaveVersionClassification.UnsupportedFuture:
                // A newer build may have written data this build cannot read.
                // Never roll it back to an older backup automatically.
                return MigrationDecision.FutureVersionBlocked;
            case SaveVersionClassification.Ambiguous:
                return MigrationDecision.AmbiguousVersionBlocked;
            default:
                // Only unreadable/missing versions can be considered corrupt
                // and eligible for existing validated-backup recovery.
                return MigrationDecision.UnreadableVersion;
        }
    }

    private static bool IsMigrationBlocked(MigrationDecision decision)
    {
        return decision == MigrationDecision.MigrationNotRegistered ||
               decision == MigrationDecision.FutureVersionBlocked ||
               decision == MigrationDecision.AmbiguousVersionBlocked;
    }

    // Step 12.8.8.3 — primary-first load with independently validated backup recovery.
    // This method only reads and recovers file bytes; gameplay restoration remains
    // the responsibility of LoadCurrentGameCore and the startup coordinator.
    public bool TryLoad(out PlayerSaveData saveData)
    {
        saveData = null;
        string primaryPath = SaveFilePath;
        byte[] primaryBytes = null;
        bool primaryExists = false;

        try
        {
            primaryBytes = File.ReadAllBytes(primaryPath);
            primaryExists = true;
        }
        catch (FileNotFoundException)
        {
            // No primary: a valid backup may still exist.
        }
        catch (DirectoryNotFoundException)
        {
            // Fresh installation or missing directory: check for backup below.
        }
        catch (Exception exception)
        {
            // Do not assume an unreadable primary is corrupt, and do not overwrite it.
            Debug.LogError("LOAD | Primary save could not be read; recovery was not attempted.\n" + exception);
            return false;
        }

        if (primaryExists)
        {
            int detectedVersion;
            MigrationDecision decision = EvaluateMigration(primaryBytes, out detectedVersion);
            if (IsMigrationBlocked(decision))
            {
                Debug.LogError("LOAD VERSION | Primary save version is unsupported or ambiguous (" +
                    detectedVersion + "). File and backup preserved; no downgrade/recovery attempted.");
                return false;
            }
        }

        if (primaryExists && IsStrictlyValidSaveFile(primaryBytes))
        {
            return TryParseValidatedBytes(primaryBytes, primaryPath, out saveData);
        }

        if (primaryExists)
            Debug.LogWarning("LOAD RECOVERY | Primary save failed strict validation. Checking backup.");
        else
            Debug.LogWarning("LOAD RECOVERY | Primary save is missing. Checking backup.");

        string backupPath = primaryPath + ".bak";
        byte[] backupBytes;
        try
        {
            backupBytes = File.ReadAllBytes(backupPath);
        }
        catch (FileNotFoundException)
        {
            Debug.LogWarning("LOAD RECOVERY | No backup exists. No save files were changed.");
            return false;
        }
        catch (DirectoryNotFoundException)
        {
            Debug.LogWarning("LOAD RECOVERY | No backup directory exists. No save files were changed.");
            return false;
        }
        catch (Exception exception)
        {
            Debug.LogError("LOAD RECOVERY | Backup could not be read. No save files were changed.\n" + exception);
            return false;
        }

        int backupVersion;
        if (EvaluateMigration(backupBytes, out backupVersion) != MigrationDecision.LoadCurrent)
        {
            Debug.LogError("LOAD VERSION | Backup is not a supported V1 save. No files changed.");
            return false;
        }

        if (!IsStrictlyValidSaveFile(backupBytes))
        {
            Debug.LogError("LOAD RECOVERY | Backup failed strict validation. No save files were changed.");
            return false;
        }

        // Verify the backup is deserializable before changing the primary path.
        if (!TryParseValidatedBytes(backupBytes, backupPath, out PlayerSaveData recoveredData))
            return false;

        try
        {
            RestorePrimaryFromBackup(primaryPath, backupBytes, primaryExists, primaryBytes);
        }
        catch (Exception exception)
        {
            Debug.LogError("LOAD RECOVERY | Failed to restore primary. Backup was preserved.\n" + exception);
            return false;
        }

        // Parse the verified bytes again, binding capacity metadata to the returned object.
        if (!TryParseValidatedBytes(backupBytes, primaryPath, out saveData))
            return false;

        Debug.LogWarning("LOAD RECOVERY | Validated backup restored to primary successfully.");
        return true;
    }

    // Strict, non-mutating validation; never silently sanitize a corrupt file.
    private bool IsStrictlyValidSaveFile(byte[] bytes)
    {
        try
        {
            return bytes != null && IsValidBackupCandidate(bytes);
        }
        catch (Exception exception)
        {
            Debug.LogWarning("LOAD | Candidate validation rejected file: " + exception.Message);
            return false;
        }
    }

    private bool TryParseValidatedBytes(byte[] bytes, string sourcePath, out PlayerSaveData data)
    {
        data = null;
        try
        {
            if (!IsStrictlyValidSaveFile(bytes))
                return false;

            string json = SaveEncoding.GetString(bytes);
            PlayerSaveData parsed = JsonUtility.FromJson<PlayerSaveData>(json);
            CustomerCapacityMetadata metadata = JsonUtility.FromJson<CustomerCapacityMetadata>(json);
            if (parsed == null || metadata == null)
                return false;

            // No mutation is necessary: the exact serialized bytes passed strict
            // canonical, structural and non-destructive sanitation validation.
            capacityLoadedData = parsed;
            loadedCustomerCapacity = metadata.mergeSessionCustomerCapacity;
            data = parsed;
            Debug.Log("LOAD | Successfully read validated save file.\nPath: " + sourcePath);
            return true;
        }
        catch (Exception exception)
        {
            Debug.LogError("LOAD | Failed to parse validated save.\n" + exception);
            return false;
        }
    }

    private void RestorePrimaryFromBackup(string primaryPath, byte[] backupBytes,
        bool primaryExists, byte[] originalPrimaryBytes)
    {
        string backupPath = primaryPath + ".bak";
        string recoveryTemporaryPath = primaryPath + ".recover.tmp";

        // Re-read backup immediately before staging; never promote a stale or
        // changed backup. A single main-thread writer is still required.
        if (!DiskMatchesSnapshot(backupPath, backupBytes))
            throw new IOException("Backup changed during recovery; refusing to proceed.");

        // Preserve damaged bytes for diagnosis if possible, without risking recovery
        // or overwriting any earlier diagnostic file. A failed diagnostic copy is
        // nonfatal because the validated backup remains untouched.
        if (primaryExists && originalPrimaryBytes != null)
        {
            string diagnosticPath = primaryPath + ".corrupt." + Guid.NewGuid().ToString("N");
            try
            {
                using (var stream = new FileStream(diagnosticPath, FileMode.CreateNew,
                    FileAccess.Write, FileShare.None))
                {
                    stream.Write(originalPrimaryBytes, 0, originalPrimaryBytes.Length);
                    stream.Flush(true);
                }
                if (!DiskMatchesSnapshot(diagnosticPath, originalPrimaryBytes))
                    Debug.LogWarning("LOAD RECOVERY | Diagnostic copy could not be verified.");
            }
            catch (Exception exception)
            {
                Debug.LogWarning("LOAD RECOVERY | Could not preserve diagnostic copy: " + exception.Message);
            }
        }

        Directory.CreateDirectory(Path.GetDirectoryName(primaryPath));
        using (var stream = new FileStream(recoveryTemporaryPath, FileMode.Create,
            FileAccess.Write, FileShare.None))
        {
            stream.Write(backupBytes, 0, backupBytes.Length);
            stream.Flush(true);
        }

        byte[] stagedBytes = File.ReadAllBytes(recoveryTemporaryPath);
        if (!BytesEqual(stagedBytes, backupBytes) || !IsStrictlyValidSaveFile(stagedBytes))
            throw new IOException("Recovery temporary file failed byte or JSON validation.");

        if (!DiskMatchesSnapshot(backupPath, backupBytes))
            throw new IOException("Backup changed before primary recovery commit.");

        // Reuse existing Windows/Android atomic rename. Critically, do NOT call
        // SaveCore or CreateValidatedBackup here: a damaged primary must never
        // replace the known-good .bak.
        CommitTemporaryFile(recoveryTemporaryPath, primaryPath);

        if (!DiskMatchesSnapshot(primaryPath, backupBytes))
            throw new IOException("Recovered primary failed post-commit verification.");
    }

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
