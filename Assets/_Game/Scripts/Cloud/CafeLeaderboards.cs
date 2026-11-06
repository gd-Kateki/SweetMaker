using System;
using System.Collections.Generic;
using System.Globalization;
using System.Threading.Tasks;
using Unity.Services.Leaderboards;
using Unity.Services.Leaderboards.Models;
using Unity.Services.CloudCode;
using Unity.Services.Core;
using Unity.Services.Leaderboards.Exceptions;
using UnityEngine;
using UnityEngine.Scripting;

namespace SweetMerge.Cloud
{
    public sealed class CafeLeaderboards : MonoBehaviour
    {
        public const string MoneyId = "total_money_earned";
        public const string OrdersId = "total_orders_completed";
        public const int PageSize = 25;
        private static CafeLeaderboards instance;
        private CloudBackupEnvelope accepted;
        private PlayerStatisticsSyncSession session;
        private float nextCheck;
        private double retryAfter;
        private int failures;
        private static readonly Dictionary<string, CachedPage> pages = new Dictionary<string, CachedPage>();
        private static readonly Dictionary<string, Task<LeaderboardScoresPage>> reads = new Dictionary<string, Task<LeaderboardScoresPage>>();
        private static string cacheOwner;
        private sealed class CachedPage { public double Expires; public LeaderboardScoresPage Value; }
        [Preserve]
        public sealed class SyncResult { public bool uploaded; public string checksum; }

        [Serializable]
        public sealed class EntryMetadata
        {
            public string cafeName;
            public int rebirth;
            // Preserve the exact integer for display; UGS ranking uses doubles.
            public string total;
        }

        internal static void AcceptBackup(CloudBackupEnvelope envelope)
        {
            if (envelope == null || !envelope.IsValid(envelope.playerId)) return;
            if (instance == null)
                instance = new GameObject("Cafe Leaderboards").AddComponent<CafeLeaderboards>();
            if (instance.accepted?.playerId != envelope.playerId)
            {
                instance.failures = 0;
                instance.retryAfter = 0;
            }
            instance.accepted = envelope;
            if (instance.session.RegisterAcceptedBackupCandidate(envelope.playerId) &&
                Time.realtimeSinceStartupAsDouble >= instance.retryAfter)
                _ = instance.session.RequestUploadAsync();
        }

        private void Awake()
        {
            if (instance != null && instance != this) { Destroy(gameObject); return; }
            instance = this;
            DontDestroyOnLoad(gameObject);
            session = new PlayerStatisticsSyncSession(
                SimpleCloudBackup.GetVerifiedCurrentOwnerId,
                () => SimpleCloudFiles.RestorePending || SimpleCloudFiles.StartupRestorePending,
                () => SimpleCloudBackup.GetVerifiedCurrentOwnerId() != null,
                () => GameStartupCoordinator.Instance != null && GameStartupCoordinator.Instance.IsGameplayReady,
                () => SimpleCloudFiles.StartupError != null,
                Capture, UploadAsync, () => Time.realtimeSinceStartup, IsAccepted);
        }

        private bool IsAccepted() => accepted != null &&
            PlayerStatisticsCloudSync.IsAcceptedBackupCurrent(accepted.playerId,
                accepted.environment, accepted.saveJson, accepted.checksum);

        private IDictionary<string, object> Capture()
        {
            if (!IsAccepted() || !PlayerStatisticsCloudSync.TryCaptureSnapshotFromSaveV2(
                    accepted.saveJson, accepted.cafeName, out var snapshot))
                throw new InvalidOperationException("An acknowledged cloud backup is required for leaderboards.");
            // Current wallet changes don't affect lifetime rankings.
            snapshot.Remove(PlayerStatisticsCloudSync.CurrentMoneyKey);
            return snapshot;
        }

        private void Update()
        {
            if (Time.unscaledTime < nextCheck) return;
            nextCheck = Time.unscaledTime + 5;
            session.ValidateCurrentSession();
            if (Time.realtimeSinceStartupAsDouble >= retryAfter)
                _ = session.RequestUploadAsync();
        }

        internal static Dictionary<string, object> CreateSyncParameters(string checksum)
        {
            if (checksum == null ||
                !System.Text.RegularExpressions.Regex.IsMatch(checksum, "\\A[A-Za-z0-9+/]{43}=\\z"))
                throw new ArgumentException("Invalid backup checksum.");
            return new Dictionary<string, object> { ["checksum"] = checksum };
        }

        internal static double RetryDelay(int failureCount) => Math.Min(300, 30 * Math.Pow(2, Math.Min(4, Math.Max(0, failureCount - 1))));

        public static string ReadFailureMessage(Exception exception)
        {
            if (exception is TimeoutException)
                return "Connection timed out. Tap Refresh to try again.";
            if (exception is OperationCanceledException)
                return "Account changed. Sign in and tap Refresh.";
            if (exception is LeaderboardsException failure)
            {
                string message;
                switch (failure.Reason)
                {
                    case LeaderboardsExceptionReason.LeaderboardNotFound:
                        message = "This leaderboard is not configured in the active environment."; break;
                    case LeaderboardsExceptionReason.Unauthorized:
                        message = "Leaderboard access was denied. Check sign-in and service permissions."; break;
                    case LeaderboardsExceptionReason.NoInternetConnection:
                        message = "No connection. Reconnect and tap Refresh."; break;
                    case LeaderboardsExceptionReason.ScoreSubmissionRequired:
                        message = "This board requires a saved score before it can be viewed."; break;
                    case LeaderboardsExceptionReason.TooManyRequests:
                        message = "Too many requests. Wait a moment and tap Refresh."; break;
                    default:
                        message = "Leaderboards could not load. Tap Refresh to retry."; break;
                }
                return message + "\n" + failure.Reason + " (" + failure.ErrorCode + ")";
            }
            if (exception is RequestFailedException request)
                return "Leaderboards could not load. Error " + request.ErrorCode + ". Tap Refresh to retry.";
            return "Leaderboard display failed. Tap Refresh to retry. (" + exception.GetType().Name + ")";
        }

        private static void RequireOwner(string owner)
        {
            if (owner == null || !SimpleCloudBackup.IsCurrentVerifiedOwner(owner) ||
                SimpleCloudFiles.RestorePending || SimpleCloudFiles.StartupRestorePending)
                throw new OperationCanceledException("Leaderboard account changed.");
        }

        private async Task UploadAsync(IDictionary<string, object> snapshot)
        {
            string owner = SimpleCloudBackup.GetVerifiedCurrentOwnerId();
            string checksum = accepted.checksum;
            RequireOwner(owner);
            try
            {
                var result = await CloudCodeService.Instance.CallEndpointAsync<SyncResult>(
                    "SyncCafeLeaderboards", CreateSyncParameters(checksum));
                RequireOwner(owner);
                if (result == null || !result.uploaded || result.checksum != checksum)
                    throw new InvalidOperationException("Leaderboard sync was not acknowledged.");
                failures = 0; retryAfter = 0;
            }
            catch
            {
                if (this != null && SimpleCloudBackup.IsCurrentVerifiedOwner(owner))
                    retryAfter = Time.realtimeSinceStartupAsDouble + RetryDelay(++failures);
                throw;
            }
        }

        public static async Task<LeaderboardScoresPage> GetPageAsync(bool orders, int offset)
        {
            string owner = SimpleCloudBackup.GetVerifiedCurrentOwnerId();
            RequireOwner(owner);
            if (owner != cacheOwner) { pages.Clear(); reads.Clear(); cacheOwner = owner; }
            string key = owner + ":" + orders + ":" + Math.Max(0, offset);
            if (pages.TryGetValue(key, out var cached) && cached.Expires > Time.realtimeSinceStartupAsDouble)
                return cached.Value;
            if (!reads.TryGetValue(key, out var pending))
            {
                pending = ReadPageAsync(owner, key, orders, offset);
                reads[key] = pending;
            }
            var result = await pending;
            RequireOwner(owner);
            return result;
        }

        private static async Task<LeaderboardScoresPage> ReadPageAsync(string owner, string key, bool orders, int offset)
        {
            // Ensure the caller registers the task before completion/cleanup.
            await Task.Yield();
            try
            {
                RequireOwner(owner);
                var result = await LeaderboardsService.Instance.GetScoresAsync(orders ? OrdersId : MoneyId,
                    new GetScoresOptions { Offset = Math.Max(0, offset), Limit = PageSize, IncludeMetadata = true });
                RequireOwner(owner);
                if (pages.Count >= 8) pages.Clear();
                pages[key] = new CachedPage { Value = result, Expires = Time.realtimeSinceStartupAsDouble + 15 };
                return result;
            }
            finally { reads.Remove(key); }
        }

        public static EntryMetadata ParseMetadata(string json)
        {
            if (string.IsNullOrEmpty(json) || json.Length > 4096) return null;
            try
            {
                var value = JsonUtility.FromJson<EntryMetadata>(json);
                return value != null && !string.IsNullOrWhiteSpace(value.cafeName) &&
                    value.cafeName.Length <= 20 && value.cafeName == value.cafeName.Trim() &&
                    !System.Text.RegularExpressions.Regex.IsMatch(value.cafeName, "[\\x00-\\x1f\\x7f]") &&
                    value.rebirth >= 0 ? value : null;
            }
            catch (ArgumentException) { return null; }
        }

        public static string FormatTotal(LeaderboardEntry entry)
        {
            var metadata = ParseMetadata(entry.Metadata);
            return long.TryParse(metadata?.total, NumberStyles.None, CultureInfo.InvariantCulture, out long total) &&
                (double)total == entry.Score
                ? total.ToString("N0") : entry.Score.ToString("N0");
        }

        private void OnDestroy()
        {
            session?.Invalidate("Leaderboard sync stopped.");
            if (instance == this) instance = null;
        }
    }
}
