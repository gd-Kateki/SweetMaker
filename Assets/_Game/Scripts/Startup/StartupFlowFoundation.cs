using System;
using System.IO;
using System.Text;
using UnityEngine;

namespace SweetMerge.Startup
{
    public enum StartupPlayMode
    {
        None,
        Guest,
        Google
    }

    public enum StartupFlowState
    {
        PrivacyPending,
        PlayModeSelectionPending,
        GoogleAuthenticationPending,
        LoadingRestorePending,
        ReadyForMainBakery,
        RecoverableError
    }

    public enum StartupPlayModeLoadStatus
    {
        Missing,
        Loaded,
        InvalidData,
        ServiceError
    }

    [Serializable]
    internal sealed class StartupPlayModeRecord
    {
        public int version;
        public string mode;
        public bool googleAuthenticationPending;
    }

    public sealed class StartupPlayModeStore
    {
        private const int CurrentVersion = 1;
        private const int MaximumRecordBytes = 1024;
        private static readonly UTF8Encoding StrictUtf8 =
            new UTF8Encoding(false, true);

        internal static event Action<StartupPlayMode, bool> SelectionSaved;

        private readonly string filePath;

        public StartupPlayModeStore()
            : this(Path.Combine(
                SavePathPolicy.GetSaveDirectory(),
                "Startup",
                "play-mode-v1.json"))
        {
        }

        public StartupPlayModeStore(string filePath)
        {
            if (string.IsNullOrWhiteSpace(filePath) ||
                !Path.IsPathRooted(filePath))
            {
                throw new ArgumentException(
                    "The startup selection path must be absolute.",
                    nameof(filePath));
            }

            this.filePath = Path.GetFullPath(filePath);
        }

        public StartupPlayModeLoadStatus Load(
            out StartupPlayMode mode,
            out bool googleAuthenticationPending,
            out string errorMessage)
        {
            mode = StartupPlayMode.None;
            googleAuthenticationPending = false;
            errorMessage = null;

            try
            {
                byte[] bytes;
                try
                {
                    bytes = File.ReadAllBytes(filePath);
                }
                catch (FileNotFoundException)
                {
                    return StartupPlayModeLoadStatus.Missing;
                }
                catch (DirectoryNotFoundException)
                {
                    return StartupPlayModeLoadStatus.Missing;
                }

                if (bytes.Length <= 0 ||
                    bytes.Length > MaximumRecordBytes)
                {
                    errorMessage =
                        "The saved startup selection has an invalid size.";
                    return StartupPlayModeLoadStatus.InvalidData;
                }

                string json;
                try
                {
                    json = StrictUtf8.GetString(bytes);
                }
                catch (DecoderFallbackException exception)
                {
                    errorMessage =
                        "The saved startup selection is not valid UTF-8: " +
                        exception.Message;
                    return StartupPlayModeLoadStatus.InvalidData;
                }

                StartupPlayModeRecord record;
                try
                {
                    record =
                        JsonUtility.FromJson<StartupPlayModeRecord>(json);
                }
                catch (ArgumentException exception)
                {
                    errorMessage =
                        "The saved startup selection is malformed: " +
                        exception.Message;
                    return StartupPlayModeLoadStatus.InvalidData;
                }
                if (record == null ||
                    record.version != CurrentVersion ||
                    !TryParseMode(record.mode, out mode))
                {
                    errorMessage =
                        "The saved startup selection is invalid or unsupported.";
                    return StartupPlayModeLoadStatus.InvalidData;
                }

                googleAuthenticationPending =
                    record.googleAuthenticationPending;
                return StartupPlayModeLoadStatus.Loaded;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "The saved startup selection could not be read: " +
                    exception.Message;
                return StartupPlayModeLoadStatus.ServiceError;
            }
        }

        public bool TrySave(
            StartupPlayMode mode,
            bool googleAuthenticationPending,
            out string errorMessage)
        {
            errorMessage = null;
            if (!Enum.IsDefined(typeof(StartupPlayMode), mode))
            {
                errorMessage = "The startup play mode is invalid.";
                return false;
            }

            string temporaryPath = filePath + "." +
                Guid.NewGuid().ToString("N") + ".tmp";
            try
            {
                Directory.CreateDirectory(Path.GetDirectoryName(filePath));
                var record = new StartupPlayModeRecord
                {
                    version = CurrentVersion,
                    mode = mode.ToString(),
                    googleAuthenticationPending =
                        googleAuthenticationPending
                };
                byte[] expected = StrictUtf8.GetBytes(
                    JsonUtility.ToJson(record, false));
                using (var stream = new FileStream(
                    temporaryPath,
                    FileMode.CreateNew,
                    FileAccess.Write,
                    FileShare.None))
                {
                    stream.Write(expected, 0, expected.Length);
                    stream.Flush(true);
                }

                if (File.Exists(filePath))
                    File.Replace(temporaryPath, filePath, null);
                else
                    File.Move(temporaryPath, filePath);
                StartupPlayModeLoadStatus status = Load(
                    out StartupPlayMode committedMode,
                    out bool committedAuthenticationPending,
                    out string verificationError);
                if (status != StartupPlayModeLoadStatus.Loaded ||
                    committedMode != mode ||
                    committedAuthenticationPending !=
                        googleAuthenticationPending)
                {
                    errorMessage = string.IsNullOrEmpty(verificationError)
                        ? "The saved startup selection could not be verified."
                        : verificationError;
                    return false;
                }

                NotifySelectionSaved(mode, googleAuthenticationPending);
                return true;
            }
            catch (Exception exception)
            {
                errorMessage =
                    "The startup selection could not be saved: " +
                    exception.Message;
                return false;
            }
            finally
            {
                if (File.Exists(temporaryPath))
                {
                    try
                    {
                        File.Delete(temporaryPath);
                    }
                    catch (Exception exception)
                    {
                        Debug.LogWarning(
                            "STARTUP | Temporary selection file could not " +
                            "be removed: " + exception.Message);
                    }
                }
            }
        }

        private static void NotifySelectionSaved(
            StartupPlayMode mode,
            bool googleAuthenticationPending)
        {
            Action<StartupPlayMode, bool> listeners = SelectionSaved;
            if (listeners == null)
                return;

            foreach (Action<StartupPlayMode, bool> listener in
                     listeners.GetInvocationList())
            {
                try
                {
                    listener(mode, googleAuthenticationPending);
                }
                catch (Exception exception)
                {
                    Debug.LogError(
                        "STARTUP | A play-mode selection listener failed.\n" +
                        exception);
                }
            }
        }

        private static bool TryParseMode(
            string value,
            out StartupPlayMode mode)
        {
            switch (value)
            {
                case "None":
                    mode = StartupPlayMode.None;
                    return true;
                case "Guest":
                    mode = StartupPlayMode.Guest;
                    return true;
                case "Google":
                    mode = StartupPlayMode.Google;
                    return true;
                default:
                    mode = StartupPlayMode.None;
                    return false;
            }
        }
    }

    public sealed class StartupFlowMachine
    {
        private enum RetryOperation
        {
            None,
            LoadSelection,
            SaveGuestSelection,
            MarkGoogleAuthenticationPending,
            SaveGoogleSelection,
            LoadGame
        }

        private readonly StartupPlayModeStore store;
        private bool privacyChoiceCompleted;
        private bool googleAuthenticationStarted;
        private bool requiresGoogleSessionRestoration;
        private bool googleAuthenticationPending;
        private RetryOperation retryOperation;

        public StartupFlowState State { get; private set; } =
            StartupFlowState.PrivacyPending;
        public StartupPlayMode SelectedPlayMode { get; private set; } =
            StartupPlayMode.None;
        public string ErrorMessage { get; private set; }
        public bool RequiresGoogleSessionRestoration =>
            requiresGoogleSessionRestoration;

        public StartupFlowMachine(StartupPlayModeStore store)
        {
            this.store = store ??
                throw new ArgumentNullException(nameof(store));
        }

        public void Initialize(bool hasPrivacyChoice)
        {
            privacyChoiceCompleted = hasPrivacyChoice;
            retryOperation = RetryOperation.None;
            googleAuthenticationStarted = false;
            requiresGoogleSessionRestoration = false;
            googleAuthenticationPending = false;
            SelectedPlayMode = StartupPlayMode.None;
            ErrorMessage = null;

            StartupPlayModeLoadStatus loadStatus = store.Load(
                out StartupPlayMode loadedMode,
                out googleAuthenticationPending,
                out string loadError);
            if (loadStatus == StartupPlayModeLoadStatus.ServiceError)
            {
                EnterRecoverableError(
                    loadError,
                    RetryOperation.LoadSelection);
                return;
            }

            SelectedPlayMode =
                loadStatus == StartupPlayModeLoadStatus.Loaded
                    ? loadedMode
                    : StartupPlayMode.None;

            if (loadStatus == StartupPlayModeLoadStatus.InvalidData)
            {
                SelectedPlayMode = StartupPlayMode.None;
                googleAuthenticationPending = false;
                ErrorMessage = loadError;
            }
            else if (loadStatus == StartupPlayModeLoadStatus.Missing)
            {
                googleAuthenticationPending = false;
            }

            RouteAfterPrivacyChoice();
        }

        public bool CompletePrivacyChoice()
        {
            if (State != StartupFlowState.PrivacyPending)
                return false;

            privacyChoiceCompleted = true;
            RouteAfterPrivacyChoice();
            return true;
        }

        public bool SelectGuest()
        {
            if (State != StartupFlowState.PlayModeSelectionPending)
                return false;

            if (!store.TrySave(
                    StartupPlayMode.Guest,
                    false,
                    out string error))
            {
                EnterRecoverableError(
                    error,
                    RetryOperation.SaveGuestSelection);
                return false;
            }

            SelectedPlayMode = StartupPlayMode.Guest;
            googleAuthenticationPending = false;
            requiresGoogleSessionRestoration = false;
            ErrorMessage = null;
            State = StartupFlowState.LoadingRestorePending;
            return true;
        }

        public bool BeginGoogleAuthentication()
        {
            if (State != StartupFlowState.PlayModeSelectionPending &&
                State != StartupFlowState.GoogleAuthenticationPending)
            {
                return false;
            }

            if (!store.TrySave(
                    SelectedPlayMode,
                    true,
                    out string error))
            {
                EnterRecoverableError(
                    error,
                    RetryOperation.MarkGoogleAuthenticationPending);
                return false;
            }

            googleAuthenticationPending = true;
            googleAuthenticationStarted = true;
            ErrorMessage = null;
            State = StartupFlowState.GoogleAuthenticationPending;
            return true;
        }

        public bool GoogleVerified()
        {
            if (State != StartupFlowState.GoogleAuthenticationPending ||
                !googleAuthenticationStarted)
            {
                return false;
            }

            if (!store.TrySave(
                    StartupPlayMode.Google,
                    false,
                    out string error))
            {
                EnterRecoverableError(
                    error,
                    RetryOperation.SaveGoogleSelection);
                return false;
            }

            SelectedPlayMode = StartupPlayMode.Google;
            googleAuthenticationPending = false;
            googleAuthenticationStarted = false;
            requiresGoogleSessionRestoration = false;
            ErrorMessage = null;
            State = StartupFlowState.LoadingRestorePending;
            return true;
        }

        public bool GoogleAuthenticationCancelledOrFailed()
        {
            if (State != StartupFlowState.GoogleAuthenticationPending ||
                !googleAuthenticationStarted)
            {
                return false;
            }

            googleAuthenticationStarted = false;
            requiresGoogleSessionRestoration = false;
            State = StartupFlowState.PlayModeSelectionPending;
            return true;
        }

        public bool LoadingCompleted()
        {
            if (State != StartupFlowState.LoadingRestorePending)
                return false;

            ErrorMessage = null;
            State = StartupFlowState.ReadyForMainBakery;
            return true;
        }

        public bool LoadingFailed(string errorMessage)
        {
            if (State != StartupFlowState.LoadingRestorePending)
                return false;

            EnterRecoverableError(
                string.IsNullOrWhiteSpace(errorMessage)
                    ? "Startup loading failed."
                    : errorMessage,
                RetryOperation.LoadGame);
            return true;
        }

        public bool Retry()
        {
            switch (retryOperation)
            {
                case RetryOperation.LoadSelection:
                    Initialize(privacyChoiceCompleted);
                    return State != StartupFlowState.RecoverableError;

                case RetryOperation.SaveGuestSelection:
                    if (!store.TrySave(
                            StartupPlayMode.Guest,
                            false,
                            out string guestError))
                    {
                        EnterRecoverableError(
                            guestError,
                            RetryOperation.SaveGuestSelection);
                        return false;
                    }

                    SelectedPlayMode = StartupPlayMode.Guest;
                    googleAuthenticationPending = false;
                    requiresGoogleSessionRestoration = false;
                    State = StartupFlowState.LoadingRestorePending;
                    ErrorMessage = null;
                    retryOperation = RetryOperation.None;
                    return true;

                case RetryOperation.MarkGoogleAuthenticationPending:
                    if (!store.TrySave(
                            SelectedPlayMode,
                            true,
                            out string authenticationError))
                    {
                        EnterRecoverableError(
                            authenticationError,
                            RetryOperation.MarkGoogleAuthenticationPending);
                        return false;
                    }

                    googleAuthenticationPending = true;
                    googleAuthenticationStarted = true;
                    State = StartupFlowState.GoogleAuthenticationPending;
                    ErrorMessage = null;
                    retryOperation = RetryOperation.None;
                    return true;

                case RetryOperation.SaveGoogleSelection:
                    if (!store.TrySave(
                            StartupPlayMode.Google,
                            false,
                            out string googleError))
                    {
                        EnterRecoverableError(
                            googleError,
                            RetryOperation.SaveGoogleSelection);
                        return false;
                    }

                    SelectedPlayMode = StartupPlayMode.Google;
                    googleAuthenticationPending = false;
                    googleAuthenticationStarted = false;
                    requiresGoogleSessionRestoration = false;
                    State = StartupFlowState.LoadingRestorePending;
                    ErrorMessage = null;
                    retryOperation = RetryOperation.None;
                    return true;

                case RetryOperation.LoadGame:
                    State = StartupFlowState.LoadingRestorePending;
                    ErrorMessage = null;
                    retryOperation = RetryOperation.None;
                    return true;

                default:
                    return false;
            }
        }

        private void RouteAfterPrivacyChoice()
        {
            if (!privacyChoiceCompleted)
            {
                State = StartupFlowState.PrivacyPending;
                return;
            }

            if (googleAuthenticationPending)
            {
                State = StartupFlowState.PlayModeSelectionPending;
                return;
            }

            switch (SelectedPlayMode)
            {
                case StartupPlayMode.Guest:
                    State = StartupFlowState.LoadingRestorePending;
                    break;
                case StartupPlayMode.Google:
                    requiresGoogleSessionRestoration = true;
                    State = StartupFlowState.GoogleAuthenticationPending;
                    break;
                default:
                    State = StartupFlowState.PlayModeSelectionPending;
                    break;
            }
        }

        private void EnterRecoverableError(
            string errorMessage,
            RetryOperation operation)
        {
            ErrorMessage = string.IsNullOrWhiteSpace(errorMessage)
                ? "Startup could not be completed."
                : errorMessage;
            retryOperation = operation;
            State = StartupFlowState.RecoverableError;
        }
    }
}
