using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using UnityEngine;

public enum SettingsPersistenceStatus
{
    NotInitialized,
    Loaded,
    DefaultsInUse,
    RecoveredFromBackup,
    UnsavedChanges,
    Saved,
    SaveFailed,
    UnsupportedFutureSchema,
    InvalidProfileProtected
}

public sealed class SettingsManager : MonoBehaviour
{
    private const int SupportedSchemaVersion = 1;
    private const int MaximumProfileBytes = 65536;
    private const string SettingsDirectoryName = "settings";
    private const string ProfileFileName = "settings_profile_v1.json";

    private static readonly UTF8Encoding StrictUtf8 =
        new UTF8Encoding(false, true);

    public static SettingsManager Instance { get; private set; }

    public event Action<SettingsProfileData> SettingsChanged;

    private SettingsProfileData currentSettings =
        SettingsProfileData.CreateDefault();

    private SettingsPersistenceStatus persistenceStatus =
        SettingsPersistenceStatus.NotInitialized;

    private string profilePath;
    private string backupPath;
    private string temporaryPath;
    private string backupTemporaryPath;
    private string lastPersistenceError;
    private bool initialized;
    private bool unsavedChanges;
    private bool persistenceBlocked;
    private SettingsPersistenceStatus blockedStatus;
    private string blockedReason;

    public SettingsProfileData CurrentSettings =>
        currentSettings.Copy();

    public SettingsPersistenceStatus PersistenceStatus =>
        persistenceStatus;

    public string LastPersistenceError =>
        lastPersistenceError;

    public bool HasUnsavedChanges =>
        unsavedChanges;

    public string ProfilePath =>
        profilePath;

    public string BackupPath =>
        backupPath;

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
    private static void ResetStaticState()
    {
        Instance = null;
    }

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
    private static void EnsureInitializedBeforeSceneLoad()
    {
        if (Instance != null)
            return;

        var managerObject = new GameObject(nameof(SettingsManager));
        managerObject.AddComponent<SettingsManager>();
    }

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            if (Application.isPlaying)
                Destroy(gameObject);
            else
                DestroyImmediate(gameObject);
            return;
        }

        Instance = this;
        if (Application.isPlaying)
            DontDestroyOnLoad(gameObject);

        InitializeProfile();
    }

    private void OnDestroy()
    {
        if (Instance == this)
            Instance = null;
    }

    public bool TryUpdate(
        SettingsProfileData proposedSettings,
        out string failureReason)
    {
        failureReason = null;
        if (!initialized)
        {
            failureReason = "Settings have not been initialized.";
            return false;
        }

        if (proposedSettings == null ||
            !proposedSettings.TryNormalize(
                out SettingsProfileData normalized,
                out failureReason))
        {
            if (failureReason == null)
                failureReason = "Proposed settings are missing.";
            return false;
        }

        if (SettingsEqual(currentSettings, normalized))
            return true;

        currentSettings = normalized;
        unsavedChanges = true;
        if (!persistenceBlocked)
            persistenceStatus = SettingsPersistenceStatus.UnsavedChanges;

        NotifySettingsChanged();
        return true;
    }

    public bool Save()
    {
        if (!initialized)
        {
            SetSaveFailure("Settings have not been initialized.");
            return false;
        }

        if (persistenceBlocked)
        {
            lastPersistenceError = blockedReason;
            persistenceStatus = blockedStatus;
            Debug.LogError(
                "SETTINGS | Save refused to protect the existing profile. " +
                blockedReason,
                this);
            return false;
        }

        if (!unsavedChanges &&
            (persistenceStatus == SettingsPersistenceStatus.Loaded ||
             persistenceStatus == SettingsPersistenceStatus.Saved))
        {
            return true;
        }

        if (!TryWriteProfile(currentSettings, out string failureReason))
        {
            SetSaveFailure(failureReason);
            return false;
        }

        unsavedChanges = false;
        lastPersistenceError = null;
        persistenceStatus = SettingsPersistenceStatus.Saved;
        Debug.Log("SETTINGS | Profile saved.", this);
        return true;
    }

    public bool RetrySave()
    {
        return Save();
    }

    private void InitializeProfile()
    {
        try
        {
            string saveDirectory = SavePathPolicy.GetSaveDirectory();
            string settingsDirectory = Path.Combine(
                saveDirectory,
                SettingsDirectoryName);

            profilePath = Path.Combine(
                settingsDirectory,
                ProfileFileName);
            backupPath = profilePath + ".bak";
            temporaryPath = profilePath + ".tmp";
            backupTemporaryPath = backupPath + ".tmp";
        }
        catch (Exception exception)
        {
            currentSettings = SettingsProfileData.CreateDefault();
            persistenceStatus = SettingsPersistenceStatus.SaveFailed;
            lastPersistenceError =
                "Settings profile path could not be resolved.";
            initialized = true;
            Debug.LogError(
                "SETTINGS | " + lastPersistenceError + "\n" + exception,
                this);
            return;
        }

        LoadProfile();
        initialized = true;
    }

    private void LoadProfile()
    {
        ProfileReadResult primary = ReadProfile(profilePath);
        ProfileReadResult backup = ReadProfile(backupPath);

        if (primary.FutureSchema)
        {
            BlockPersistence(
                SettingsPersistenceStatus.UnsupportedFutureSchema,
                primary.FailureReason);
            currentSettings = backup.IsValid
                ? backup.Profile
                : SettingsProfileData.CreateDefault();
            Debug.LogError(
                "SETTINGS | Future-schema primary profile was preserved; " +
                (backup.IsValid
                    ? "the validated backup is active. "
                    : "defaults are active. ") +
                primary.FailureReason,
                this);
            return;
        }

        if (backup.FutureSchema)
        {
            BlockPersistence(
                SettingsPersistenceStatus.UnsupportedFutureSchema,
                backup.FailureReason);
            if (primary.IsValid)
            {
                currentSettings = primary.Profile;
                Debug.LogWarning(
                    "SETTINGS | A future-schema backup was preserved; " +
                    "profile writes are disabled.",
                    this);
            }
            else
            {
                currentSettings = SettingsProfileData.CreateDefault();
                Debug.LogError(
                    "SETTINGS | Future-schema backup was preserved. " +
                    backup.FailureReason,
                    this);
            }
            return;
        }

        if (primary.IsProtected || backup.IsProtected)
        {
            ProfileReadResult protectedProfile =
                primary.IsProtected ? primary : backup;
            BlockPersistence(
                SettingsPersistenceStatus.InvalidProfileProtected,
                protectedProfile.FailureReason);

            if (primary.IsValid)
            {
                currentSettings = primary.Profile;
                Debug.LogError(
                    "SETTINGS | A protected profile file prevents writes. " +
                    protectedProfile.FailureReason,
                    this);
            }
            else if (backup.IsValid)
            {
                currentSettings = backup.Profile;
                Debug.LogError(
                    "SETTINGS | A protected profile file prevents writes; " +
                    "the validated backup is active. " +
                    protectedProfile.FailureReason,
                    this);
            }
            else
            {
                currentSettings = SettingsProfileData.CreateDefault();
                Debug.LogError(
                    "SETTINGS | A protected profile file prevents writes; " +
                    "defaults are active. " +
                    protectedProfile.FailureReason,
                    this);
            }
            return;
        }

        if (primary.IsValid)
        {
            currentSettings = primary.Profile;
            persistenceStatus = SettingsPersistenceStatus.Loaded;
            return;
        }

        if (backup.IsValid)
        {
            currentSettings = backup.Profile;
            persistenceStatus =
                SettingsPersistenceStatus.RecoveredFromBackup;
            lastPersistenceError = primary.FailureReason;
            Debug.LogWarning(
                "SETTINGS | Primary profile was unusable; the validated " +
                "backup was loaded. " + primary.FailureReason,
                this);
            return;
        }

        currentSettings = SettingsProfileData.CreateDefault();
        persistenceStatus = SettingsPersistenceStatus.DefaultsInUse;
        if (primary.Exists || backup.Exists)
        {
            lastPersistenceError =
                "No valid settings profile or backup was available. " +
                "Defaults are active; existing files were preserved.";
            Debug.LogError("SETTINGS | " + lastPersistenceError, this);
        }
        else
        {
            Debug.Log("SETTINGS | No profile exists; defaults are active.", this);
        }
    }

    private ProfileReadResult ReadProfile(string path)
    {
        if (string.IsNullOrEmpty(path) || !File.Exists(path))
            return ProfileReadResult.Missing();

        try
        {
            var fileInfo = new FileInfo(path);
            if (fileInfo.Length > MaximumProfileBytes)
            {
                return ProfileReadResult.Protected(
                    "Settings profile exceeds the supported size limit.");
            }

            byte[] bytes = File.ReadAllBytes(path);
            string json = StrictUtf8.GetString(bytes);

            if (SettingsJsonReader.TryReadRootSchemaVersion(
                    json,
                    out int schemaVersion) &&
                schemaVersion > SupportedSchemaVersion)
            {
                return ProfileReadResult.Future(
                    $"Settings schema version {schemaVersion} is newer than " +
                    $"supported version {SupportedSchemaVersion}.");
            }

            if (!SettingsJsonReader.TryDeserializeProfile(
                    json,
                    out SettingsProfileData profile,
                    out string parseFailure))
            {
                return ProfileReadResult.Invalid(parseFailure);
            }

            if (!profile.TryNormalize(
                    out SettingsProfileData normalized,
                    out string validationFailure))
            {
                return ProfileReadResult.Invalid(validationFailure);
            }

            return ProfileReadResult.Valid(normalized);
        }
        catch (Exception exception)
        {
            return ProfileReadResult.Invalid(
                $"Settings profile could not be read: {exception.Message}");
        }
    }

    private bool TryWriteProfile(
        SettingsProfileData settings,
        out string failureReason)
    {
        failureReason = null;
        try
        {
            ProfileReadResult existingBackup =
                ReadProfile(backupPath);
            if (existingBackup.FutureSchema ||
                existingBackup.IsProtected)
            {
                BlockPersistence(
                    existingBackup.FutureSchema
                        ? SettingsPersistenceStatus.UnsupportedFutureSchema
                        : SettingsPersistenceStatus.InvalidProfileProtected,
                    existingBackup.FailureReason);
                failureReason = existingBackup.FailureReason;
                return false;
            }

            string json = JsonUtility.ToJson(settings, false);
            if (!SettingsJsonReader.TryDeserializeProfile(
                    json,
                    out SettingsProfileData validated,
                    out failureReason) ||
                !SettingsEqual(settings, validated))
            {
                if (failureReason == null)
                    failureReason =
                        "Serialized settings did not pass full profile validation.";
                return false;
            }

            byte[] newBytes = StrictUtf8.GetBytes(json);
            Directory.CreateDirectory(Path.GetDirectoryName(profilePath));
            WriteAndVerifyTemporaryFile(temporaryPath, newBytes);

            if (File.Exists(profilePath))
            {
                ProfileReadResult existingPrimary =
                    ReadProfile(profilePath);
                if (existingPrimary.FutureSchema ||
                    existingPrimary.IsProtected)
                {
                    BlockPersistence(
                        existingPrimary.FutureSchema
                            ? SettingsPersistenceStatus.UnsupportedFutureSchema
                            : SettingsPersistenceStatus.InvalidProfileProtected,
                        existingPrimary.FailureReason);
                    failureReason = existingPrimary.FailureReason;
                    return false;
                }

                if (existingPrimary.IsValid)
                {
                    byte[] previousBytes = File.ReadAllBytes(profilePath);
                    WriteAndVerifyTemporaryFile(
                        backupTemporaryPath,
                        previousBytes);
                    PromoteFile(backupTemporaryPath, backupPath);
                    VerifyProfileFile(backupPath, existingPrimary.Profile);
                }
            }

            PromoteFile(temporaryPath, profilePath);
            VerifyProfileFile(profilePath, settings);
            return true;
        }
        catch (Exception exception)
        {
            if (TryVerifyProfileFile(profilePath, settings))
                return true;

            failureReason =
                "Settings profile could not be committed safely: " +
                exception.Message;
            return false;
        }
    }

    private static void WriteAndVerifyTemporaryFile(
        string path,
        byte[] expectedBytes)
    {
        using (var stream = new FileStream(
                   path,
                   FileMode.Create,
                   FileAccess.Write,
                   FileShare.None))
        {
            stream.Write(expectedBytes, 0, expectedBytes.Length);
            stream.Flush(true);
        }

        byte[] actualBytes = File.ReadAllBytes(path);
        if (!BytesEqual(expectedBytes, actualBytes))
            throw new IOException(
                "Staged settings bytes differ from the requested profile.");

        string json = StrictUtf8.GetString(actualBytes);
        if (!SettingsJsonReader.TryDeserializeProfile(
                json,
                out _,
                out string failureReason))
        {
            throw new IOException(
                "Staged settings profile failed validation: " +
                failureReason);
        }
    }

    private static void PromoteFile(
        string temporaryFile,
        string destinationFile)
    {
        if (File.Exists(destinationFile))
            File.Replace(temporaryFile, destinationFile, null);
        else
            File.Move(temporaryFile, destinationFile);
    }

    private void VerifyProfileFile(
        string path,
        SettingsProfileData expected)
    {
        if (!TryVerifyProfileFile(path, expected))
        {
            throw new IOException(
                "Committed settings profile failed read-back verification.");
        }
    }

    private static bool TryVerifyProfileFile(
        string path,
        SettingsProfileData expected)
    {
        try
        {
            ProfileReadResult actual = ReadProfileStatic(path);
            return actual.IsValid &&
                   SettingsEqual(actual.Profile, expected);
        }
        catch (Exception)
        {
            return false;
        }
    }

    private static ProfileReadResult ReadProfileStatic(string path)
    {
        if (!File.Exists(path))
            return ProfileReadResult.Missing();

        var fileInfo = new FileInfo(path);
        if (fileInfo.Length > MaximumProfileBytes)
        {
            return ProfileReadResult.Protected(
                "Settings profile exceeds the supported size limit.");
        }

        string json = StrictUtf8.GetString(File.ReadAllBytes(path));
        if (SettingsJsonReader.TryReadRootSchemaVersion(
                json,
                out int schemaVersion) &&
            schemaVersion > SupportedSchemaVersion)
        {
            return ProfileReadResult.Future(
                $"Settings schema version {schemaVersion} is newer than " +
                $"supported version {SupportedSchemaVersion}.");
        }

        if (!SettingsJsonReader.TryDeserializeProfile(
                json,
                out SettingsProfileData profile,
                out string failureReason) ||
            !profile.TryNormalize(
                out SettingsProfileData normalized,
                out failureReason))
        {
            return ProfileReadResult.Invalid(failureReason);
        }

        return ProfileReadResult.Valid(normalized);
    }

    private void NotifySettingsChanged()
    {
        Action<SettingsProfileData> handlers = SettingsChanged;
        if (handlers == null)
            return;

        foreach (Action<SettingsProfileData> handler
                 in handlers.GetInvocationList())
        {
            handler(currentSettings.Copy());
        }
    }

    private void SetSaveFailure(string reason)
    {
        lastPersistenceError = reason;
        if (!persistenceBlocked)
            persistenceStatus = SettingsPersistenceStatus.SaveFailed;
        Debug.LogError("SETTINGS | Save failed. " + reason, this);
    }

    private void BlockPersistence(
        SettingsPersistenceStatus status,
        string reason)
    {
        persistenceBlocked = true;
        blockedStatus = status;
        blockedReason = reason;
        persistenceStatus = status;
        lastPersistenceError = reason;
    }

    private static bool SettingsEqual(
        SettingsProfileData left,
        SettingsProfileData right)
    {
        return left != null &&
               right != null &&
               left.schemaVersion == right.schemaVersion &&
               left.musicEnabled == right.musicEnabled &&
               left.musicVolume.Equals(right.musicVolume) &&
               left.sfxEnabled == right.sfxEnabled &&
               left.sfxVolume.Equals(right.sfxVolume) &&
               left.vibrationEnabled == right.vibrationEnabled &&
               left.confirmImportantActions ==
                   right.confirmImportantActions &&
               left.reduceAnimations == right.reduceAnimations;
    }

    private static bool BytesEqual(byte[] left, byte[] right)
    {
        if (left == null || right == null || left.Length != right.Length)
            return false;

        for (int i = 0; i < left.Length; i++)
        {
            if (left[i] != right[i])
                return false;
        }

        return true;
    }

    private sealed class ProfileReadResult
    {
        public bool Exists;
        public bool IsValid;
        public bool FutureSchema;
        public bool IsProtected;
        public SettingsProfileData Profile;
        public string FailureReason;

        public static ProfileReadResult Missing()
        {
            return new ProfileReadResult();
        }

        public static ProfileReadResult Valid(SettingsProfileData profile)
        {
            return new ProfileReadResult
            {
                Exists = true,
                IsValid = true,
                Profile = profile
            };
        }

        public static ProfileReadResult Invalid(string reason)
        {
            return new ProfileReadResult
            {
                Exists = true,
                FailureReason = reason
            };
        }

        public static ProfileReadResult Future(string reason)
        {
            return new ProfileReadResult
            {
                Exists = true,
                FutureSchema = true,
                FailureReason = reason
            };
        }

        public static ProfileReadResult Protected(string reason)
        {
            return new ProfileReadResult
            {
                Exists = true,
                IsProtected = true,
                FailureReason = reason
            };
        }
    }

    private sealed class SettingsJsonReader
    {
        private readonly string json;
        private int position;

        private SettingsJsonReader(string json)
        {
            this.json = json;
        }

        public static bool TryDeserializeProfile(
            string json,
            out SettingsProfileData profile,
            out string failureReason)
        {
            profile = null;
            failureReason = null;
            if (json == null)
            {
                failureReason = "Settings JSON is null.";
                return false;
            }

            var reader = new SettingsJsonReader(json);
            if (!reader.TryReadProfile(
                    out profile,
                    out failureReason))
            {
                profile = null;
                return false;
            }

            return true;
        }

        public static bool TryReadRootSchemaVersion(
            string json,
            out int schemaVersion)
        {
            schemaVersion = 0;
            if (string.IsNullOrEmpty(json))
                return false;

            var reader = new SettingsJsonReader(json);
            return reader.TryReadSchemaVersion(out schemaVersion);
        }

        private bool TryReadProfile(
            out SettingsProfileData profile,
            out string failureReason)
        {
            profile = new SettingsProfileData();
            failureReason = null;
            var seen = new HashSet<string>(StringComparer.Ordinal);

            SkipWhitespace();
            if (!TryConsume('{'))
                return Fail("Settings JSON root must be an object.", out failureReason);

            SkipWhitespace();
            if (TryConsume('}'))
                return Fail("Settings JSON is missing required fields.", out failureReason);

            while (true)
            {
                if (!TryReadString(out string key))
                    return Fail("Settings JSON contains an invalid property name.", out failureReason);
                if (!seen.Add(key))
                    return Fail($"Settings JSON contains duplicate field '{key}'.", out failureReason);

                SkipWhitespace();
                if (!TryConsume(':'))
                    return Fail($"Settings field '{key}' has no value.", out failureReason);
                SkipWhitespace();

                switch (key)
                {
                    case "schemaVersion":
                        if (!TryReadInteger(out profile.schemaVersion))
                            return Fail("schemaVersion must be an integer.", out failureReason);
                        break;
                    case "musicEnabled":
                        if (!TryReadBoolean(out profile.musicEnabled))
                            return Fail("musicEnabled must be a boolean.", out failureReason);
                        break;
                    case "musicVolume":
                        if (!TryReadFiniteFloat(out profile.musicVolume))
                            return Fail("musicVolume must be a finite JSON number.", out failureReason);
                        break;
                    case "sfxEnabled":
                        if (!TryReadBoolean(out profile.sfxEnabled))
                            return Fail("sfxEnabled must be a boolean.", out failureReason);
                        break;
                    case "sfxVolume":
                        if (!TryReadFiniteFloat(out profile.sfxVolume))
                            return Fail("sfxVolume must be a finite JSON number.", out failureReason);
                        break;
                    case "vibrationEnabled":
                        if (!TryReadBoolean(out profile.vibrationEnabled))
                            return Fail("vibrationEnabled must be a boolean.", out failureReason);
                        break;
                    case "confirmImportantActions":
                        if (!TryReadBoolean(out profile.confirmImportantActions))
                            return Fail("confirmImportantActions must be a boolean.", out failureReason);
                        break;
                    case "reduceAnimations":
                        if (!TryReadBoolean(out profile.reduceAnimations))
                            return Fail("reduceAnimations must be a boolean.", out failureReason);
                        break;
                    default:
                        return Fail($"Unknown settings field '{key}'.", out failureReason);
                }

                SkipWhitespace();
                if (TryConsume('}'))
                    break;
                if (!TryConsume(','))
                    return Fail("Settings JSON properties are not comma-separated.", out failureReason);
                SkipWhitespace();
            }

            SkipWhitespace();
            if (position != json.Length)
                return Fail("Settings JSON contains trailing content.", out failureReason);

            string[] requiredFields =
            {
                "schemaVersion",
                "musicEnabled",
                "musicVolume",
                "sfxEnabled",
                "sfxVolume",
                "vibrationEnabled",
                "confirmImportantActions",
                "reduceAnimations"
            };
            foreach (string field in requiredFields)
            {
                if (!seen.Contains(field))
                    return Fail($"Settings JSON is missing required field '{field}'.", out failureReason);
            }

            return true;
        }

        private bool TryReadSchemaVersion(out int schemaVersion)
        {
            schemaVersion = 0;
            SkipWhitespace();
            if (!TryConsume('{'))
                return false;

            bool found = false;
            SkipWhitespace();
            if (TryConsume('}'))
                return false;

            while (true)
            {
                if (!TryReadString(out string key))
                    return false;
                SkipWhitespace();
                if (!TryConsume(':'))
                    return false;
                SkipWhitespace();

                if (key == "schemaVersion")
                {
                    if (found)
                    {
                        schemaVersion = int.MaxValue;
                        return true;
                    }

                    if (!TryReadNumberToken(out string versionToken) ||
                        !double.TryParse(
                            versionToken,
                            NumberStyles.Float,
                            CultureInfo.InvariantCulture,
                            out double parsedVersion))
                    {
                        return false;
                    }

                    found = true;
                    if (parsedVersion > SupportedSchemaVersion)
                    {
                        schemaVersion = int.MaxValue;
                        return true;
                    }

                    if (parsedVersion < int.MinValue ||
                        parsedVersion > int.MaxValue ||
                        parsedVersion != Math.Truncate(parsedVersion))
                    {
                        return false;
                    }

                    schemaVersion = (int)parsedVersion;
                }
                else if (!TrySkipValue(0))
                {
                    return false;
                }

                SkipWhitespace();
                if (TryConsume('}'))
                    break;
                if (!TryConsume(','))
                    return false;
                SkipWhitespace();
            }

            SkipWhitespace();
            return found && position == json.Length;
        }

        private bool TryReadBoolean(out bool value)
        {
            value = false;
            if (TryConsumeLiteral("true"))
            {
                value = true;
                return true;
            }

            return TryConsumeLiteral("false");
        }

        private bool TryReadInteger(out int value)
        {
            value = 0;
            if (!TryReadNumberToken(out string token) ||
                token.IndexOf('.') >= 0 ||
                token.IndexOf('e') >= 0 ||
                token.IndexOf('E') >= 0)
            {
                return false;
            }

            return int.TryParse(
                token,
                NumberStyles.AllowLeadingSign,
                CultureInfo.InvariantCulture,
                out value);
        }

        private bool TryReadFiniteFloat(out float value)
        {
            value = 0f;
            if (!TryReadNumberToken(out string token) ||
                !float.TryParse(
                    token,
                    NumberStyles.Float,
                    CultureInfo.InvariantCulture,
                    out value))
            {
                return false;
            }

            return !float.IsNaN(value) && !float.IsInfinity(value);
        }

        private bool TryReadNumberToken(out string token)
        {
            token = null;
            int start = position;
            if (TryPeek('-'))
                position++;

            if (TryPeek('0'))
            {
                position++;
                if (IsDigit(Peek()))
                    return false;
            }
            else
            {
                if (!IsDigitOneToNine(Peek()))
                    return false;
                while (IsDigit(Peek()))
                    position++;
            }

            if (TryPeek('.'))
            {
                position++;
                if (!IsDigit(Peek()))
                    return false;
                while (IsDigit(Peek()))
                    position++;
            }

            if (TryPeek('e') || TryPeek('E'))
            {
                position++;
                if (TryPeek('+') || TryPeek('-'))
                    position++;
                if (!IsDigit(Peek()))
                    return false;
                while (IsDigit(Peek()))
                    position++;
            }

            token = json.Substring(start, position - start);
            return token.Length > 0;
        }

        private bool TryReadString(out string value)
        {
            value = null;
            if (!TryConsume('"'))
                return false;

            var builder = new StringBuilder();
            while (position < json.Length)
            {
                char character = json[position++];
                if (character == '"')
                {
                    value = builder.ToString();
                    return true;
                }

                if (character < 0x20)
                    return false;
                if (character != '\\')
                {
                    builder.Append(character);
                    continue;
                }

                if (position >= json.Length)
                    return false;
                char escaped = json[position++];
                switch (escaped)
                {
                    case '"': builder.Append('"'); break;
                    case '\\': builder.Append('\\'); break;
                    case '/': builder.Append('/'); break;
                    case 'b': builder.Append('\b'); break;
                    case 'f': builder.Append('\f'); break;
                    case 'n': builder.Append('\n'); break;
                    case 'r': builder.Append('\r'); break;
                    case 't': builder.Append('\t'); break;
                    case 'u':
                        if (!TryReadUnicodeEscape(out char unicodeCharacter))
                            return false;
                        builder.Append(unicodeCharacter);
                        break;
                    default:
                        return false;
                }
            }

            return false;
        }

        private bool TryReadUnicodeEscape(out char value)
        {
            value = '\0';
            if (position + 4 > json.Length)
                return false;

            int codePoint = 0;
            for (int i = 0; i < 4; i++)
            {
                int digit = HexValue(json[position++]);
                if (digit < 0)
                    return false;
                codePoint = (codePoint << 4) | digit;
            }

            value = (char)codePoint;
            return true;
        }

        private bool TrySkipValue(int depth)
        {
            if (depth > 32)
                return false;

            SkipWhitespace();
            if (TryPeek('"'))
                return TryReadString(out _);
            if (TryPeek('{'))
                return TrySkipObject(depth + 1);
            if (TryPeek('['))
                return TrySkipArray(depth + 1);
            if (TryConsumeLiteral("true") ||
                TryConsumeLiteral("false") ||
                TryConsumeLiteral("null"))
            {
                return true;
            }

            return TryReadNumberToken(out _);
        }

        private bool TrySkipObject(int depth)
        {
            if (!TryConsume('{'))
                return false;
            SkipWhitespace();
            if (TryConsume('}'))
                return true;

            while (true)
            {
                if (!TryReadString(out _))
                    return false;
                SkipWhitespace();
                if (!TryConsume(':') || !TrySkipValue(depth))
                    return false;
                SkipWhitespace();
                if (TryConsume('}'))
                    return true;
                if (!TryConsume(','))
                    return false;
                SkipWhitespace();
            }
        }

        private bool TrySkipArray(int depth)
        {
            if (!TryConsume('['))
                return false;
            SkipWhitespace();
            if (TryConsume(']'))
                return true;

            while (true)
            {
                if (!TrySkipValue(depth))
                    return false;
                SkipWhitespace();
                if (TryConsume(']'))
                    return true;
                if (!TryConsume(','))
                    return false;
                SkipWhitespace();
            }
        }

        private bool TryConsumeLiteral(string literal)
        {
            if (position + literal.Length > json.Length ||
                string.Compare(
                    json,
                    position,
                    literal,
                    0,
                    literal.Length,
                    StringComparison.Ordinal) != 0)
            {
                return false;
            }

            position += literal.Length;
            return true;
        }

        private void SkipWhitespace()
        {
            while (position < json.Length)
            {
                char character = json[position];
                if (character != ' ' &&
                    character != '\t' &&
                    character != '\r' &&
                    character != '\n')
                {
                    break;
                }

                position++;
            }
        }

        private bool TryConsume(char expected)
        {
            if (!TryPeek(expected))
                return false;
            position++;
            return true;
        }

        private bool TryPeek(char expected)
        {
            return position < json.Length &&
                   json[position] == expected;
        }

        private char Peek()
        {
            return position < json.Length ? json[position] : '\0';
        }

        private static bool IsDigit(char character)
        {
            return character >= '0' && character <= '9';
        }

        private static bool IsDigitOneToNine(char character)
        {
            return character >= '1' && character <= '9';
        }

        private static int HexValue(char character)
        {
            if (character >= '0' && character <= '9')
                return character - '0';
            if (character >= 'a' && character <= 'f')
                return character - 'a' + 10;
            if (character >= 'A' && character <= 'F')
                return character - 'A' + 10;
            return -1;
        }

        private static bool Fail(
            string reason,
            out string failureReason)
        {
            failureReason = reason;
            return false;
        }
    }
}
