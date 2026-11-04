using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using NUnit.Framework;
using UnityEngine;
using UnityEngine.TestTools;

public sealed class PlayerStatisticsCloudSyncTests
{
    private sealed class Fixture
    {
        private readonly Type sessionType = Find(
            "SweetMerge.Cloud.PlayerStatisticsSyncSession");
        private readonly List<Dictionary<string, object>> uploads =
            new List<Dictionary<string, object>>();

        public string Owner = "player-a";
        public bool RestorePending;
        public bool GoogleRun = true;
        public bool GameplayReady = true;
        public bool StartupFailed;
        public bool AcceptedBackupCurrent = true;
        public double Time = 100;
        public int CaptureCount;
        public int UploadCount;
        public Action OnCapture;
        public Func<IDictionary<string, object>, Task> Upload =
            _ => Task.CompletedTask;
        public IDictionary<string, object> Values =
            new Dictionary<string, object>
            {
                ["dmc_player_stats_v1_current_money"] = 17,
                ["dmc_player_stats_v1_total_money_earned"] = 12345678901234567L,
                ["dmc_player_stats_v1_total_orders_completed"] = 9876543210987654L,
                ["dmc_player_stats_v1_current_rebirth_count"] = 4
            };
        public object Session { get; }
        public IReadOnlyList<Dictionary<string, object>> Uploads => uploads;

        public Fixture()
        {
            Type[] signature =
            {
                typeof(Func<string>),
                typeof(Func<bool>),
                typeof(Func<bool>),
                typeof(Func<bool>),
                typeof(Func<bool>),
                typeof(Func<IDictionary<string, object>>),
                typeof(Func<IDictionary<string, object>, Task>),
                typeof(Func<double>),
                typeof(Func<bool>)
            };
            ConstructorInfo constructor = sessionType.GetConstructor(
                BindingFlags.Instance | BindingFlags.NonPublic,
                null,
                signature,
                null);
            Assert.IsNotNull(constructor);

            Func<IDictionary<string, object>, Task> upload =
                async values =>
                {
                    UploadCount++;
                    uploads.Add(new Dictionary<string, object>(values));
                    await Upload(values);
                };
            Session = constructor.Invoke(new object[]
            {
                (Func<string>)(() => Owner),
                (Func<bool>)(() => RestorePending),
                (Func<bool>)(() => GoogleRun),
                (Func<bool>)(() => GameplayReady),
                (Func<bool>)(() => StartupFailed),
                (Func<IDictionary<string, object>>)(() =>
                {
                    CaptureCount++;
                    OnCapture?.Invoke();
                    return new Dictionary<string, object>(Values);
                }),
                upload,
                (Func<double>)(() => Time),
                (Func<bool>)(() => AcceptedBackupCurrent)
            });
        }

        public bool RegisterRestore(bool completed = true) =>
            (bool)Invoke(
                Session,
                "RegisterPromotedRestoreCandidate",
                completed,
                "player-a");

        public bool RegisterAcceptedBackup(string owner = "player-a") =>
            (bool)Invoke(
                Session,
                "RegisterAcceptedBackupCandidate",
                owner);

        public Task RequestUpload() =>
            (Task)Invoke(Session, "RequestUploadAsync");

        public bool IsAuthorized =>
            (bool)sessionType.GetProperty(
                    "IsAuthorized",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .GetValue(Session);

        public string Status =>
            (string)sessionType.GetProperty(
                    "Status",
                    BindingFlags.Instance | BindingFlags.NonPublic)
                .GetValue(Session);

        public void Invalidate(string reason) =>
            Invoke(Session, "Invalidate", reason);
    }

    [Test]
    public async Task VerifiedRestoreAuthorizesOnlyAfterSaveAndGameplayReadiness()
    {
        var fixture = new Fixture { GameplayReady = false };

        Assert.IsTrue(fixture.RegisterRestore());
        await fixture.RequestUpload();
        Assert.IsFalse(fixture.IsAuthorized);
        Assert.AreEqual(0, fixture.CaptureCount);
        Assert.AreEqual(0, fixture.UploadCount);

        fixture.GameplayReady = true;
        await fixture.RequestUpload();

        Assert.IsTrue(fixture.IsAuthorized);
        Assert.AreEqual(1, fixture.UploadCount);
    }

    [Test]
    public async Task StagedOrFailedRestoreDoesNotAuthorize()
    {
        var fixture = new Fixture();

        Assert.IsFalse(fixture.RegisterRestore(false));
        await fixture.RequestUpload();

        Assert.IsFalse(fixture.IsAuthorized);
        Assert.AreEqual(0, fixture.UploadCount);
    }

    [Test]
    public async Task GuestToGoogleLoginDoesNotAuthorizeUnownedProfile()
    {
        var fixture = new Fixture { GoogleRun = false };

        Assert.IsFalse(fixture.RegisterRestore());
        fixture.GoogleRun = true;
        await fixture.RequestUpload();

        Assert.IsFalse(fixture.IsAuthorized);
        Assert.AreEqual(0, fixture.UploadCount);
    }

    [Test]
    public async Task GuestRunSuppressesUpload()
    {
        var fixture = new Fixture { GoogleRun = false };

        Assert.IsFalse(fixture.RegisterRestore());
        await fixture.RequestUpload();

        Assert.IsFalse(fixture.IsAuthorized);
        Assert.AreEqual(0, fixture.UploadCount);
    }

    [Test]
    public async Task VerifiedIdentityWithoutRestoreDoesNotAuthorize()
    {
        var fixture = new Fixture();

        await fixture.RequestUpload();

        Assert.IsFalse(fixture.IsAuthorized);
        Assert.AreEqual(0, fixture.UploadCount);
    }

    [Test]
    public async Task StatisticsUploadRequiresAnAcceptedBackupCandidate()
    {
        var fixture = new Fixture();

        await fixture.RequestUpload();

        Assert.IsFalse(fixture.IsAuthorized);
        Assert.AreEqual(0, fixture.UploadCount);

        Assert.IsTrue(fixture.RegisterAcceptedBackup());
        await fixture.RequestUpload();
        Assert.IsTrue(fixture.IsAuthorized);
        Assert.AreEqual(1, fixture.UploadCount);
    }

    [Test]
    public async Task RejectedBackupCannotAuthorizeStatistics()
    {
        var fixture = new Fixture
        {
            AcceptedBackupCurrent = false
        };
        Assert.IsTrue(fixture.RegisterAcceptedBackup());

        await fixture.RequestUpload();

        Assert.AreEqual(0, fixture.UploadCount);
        fixture.AcceptedBackupCurrent = true;
        await fixture.RequestUpload();
        Assert.AreEqual(1, fixture.UploadCount);
    }

    [Test]
    public async Task BackupAcceptanceIsRecheckedBeforeStatisticsWrite()
    {
        var fixture = new Fixture();
        Assert.IsTrue(fixture.RegisterAcceptedBackup());
        fixture.OnCapture = () => fixture.AcceptedBackupCurrent = false;

        await fixture.RequestUpload();

        Assert.AreEqual(0, fixture.UploadCount);
        Assert.AreNotEqual("Statistics snapshot uploaded.", fixture.Status);
    }

    [Test]
    public async Task AcceptedBackupRequiresMatchingGoogleOwnerAndReadyGameplay()
    {
        var fixture = new Fixture { Owner = "player-b" };
        Assert.IsFalse(fixture.RegisterAcceptedBackup("player-a"));
        Assert.AreEqual(0, fixture.UploadCount);

        fixture.Owner = "player-a";
        fixture.GoogleRun = false;
        Assert.IsFalse(fixture.RegisterAcceptedBackup());
        fixture.GoogleRun = true;
        fixture.GameplayReady = false;
        Assert.IsFalse(fixture.RegisterAcceptedBackup());
        fixture.GameplayReady = true;
        fixture.RestorePending = true;
        Assert.IsFalse(fixture.RegisterAcceptedBackup());

        await fixture.RequestUpload();
        Assert.AreEqual(0, fixture.UploadCount);
    }

    [Test]
    public async Task AcceptedBackupUploadsLatestStatisticsSnapshot()
    {
        var fixture = new Fixture();
        Assert.IsTrue(fixture.RegisterAcceptedBackup());
        await fixture.RequestUpload();

        fixture.Time += 30;
        fixture.Values["dmc_player_stats_v1_current_money"] = 25;
        fixture.Values["dmc_player_stats_v1_total_money_earned"] =
            22345678901234567L;
        Assert.IsTrue(fixture.RegisterAcceptedBackup());
        await fixture.RequestUpload();

        Assert.AreEqual(2, fixture.UploadCount);
        Assert.AreEqual(
            25,
            fixture.Uploads.Last()["dmc_player_stats_v1_current_money"]);
        Assert.AreEqual(
            22345678901234567L,
            fixture.Uploads.Last()["dmc_player_stats_v1_total_money_earned"]);
    }

    [Test]
    public async Task PendingRestoreInvalidatesAndBlocksStatisticsUpload()
    {
        var fixture = new Fixture();
        Assert.IsTrue(fixture.RegisterRestore());
        fixture.RestorePending = true;

        await fixture.RequestUpload();

        Assert.IsFalse(fixture.IsAuthorized);
        Assert.AreEqual(0, fixture.UploadCount);
    }

    [Test]
    public void PromotedRestoreCandidateIsNotAuthorizationWhileRestoreIsPending()
    {
        var fixture = new Fixture { RestorePending = true };

        Assert.IsTrue(fixture.RegisterRestore());

        Assert.IsFalse(fixture.IsAuthorized);
        Assert.AreEqual(0, fixture.CaptureCount);
        Assert.AreEqual(0, fixture.UploadCount);
    }

    [Test]
    public async Task StartupFailureInvalidatesRestoreCandidate()
    {
        var fixture = new Fixture { GameplayReady = false };
        Assert.IsTrue(fixture.RegisterRestore());
        fixture.StartupFailed = true;

        await fixture.RequestUpload();

        Assert.IsFalse(fixture.IsAuthorized);
        Assert.AreEqual(0, fixture.UploadCount);
    }

    [Test]
    public async Task CorrectSnapshotPreservesIntAndLongPrecision()
    {
        var fixture = new Fixture();
        Assert.IsTrue(fixture.RegisterRestore());

        await fixture.RequestUpload();

        Dictionary<string, object> snapshot = fixture.Uploads.Single();
        Assert.AreEqual(17, snapshot["dmc_player_stats_v1_current_money"]);
        Assert.AreEqual(
            12345678901234567L,
            snapshot["dmc_player_stats_v1_total_money_earned"]);
        Assert.AreEqual(
            9876543210987654L,
            snapshot["dmc_player_stats_v1_total_orders_completed"]);
        Assert.AreEqual(
            4,
            snapshot["dmc_player_stats_v1_current_rebirth_count"]);
        Assert.IsInstanceOf<long>(
            snapshot["dmc_player_stats_v1_total_money_earned"]);
        Assert.IsInstanceOf<long>(
            snapshot["dmc_player_stats_v1_total_orders_completed"]);
    }

    [TestCase("reset")]
    [TestCase("recovery")]
    public async Task ResetOrRecoveryInvalidationPreventsFurtherUpload(
        string invalidation)
    {
        var fixture = new Fixture();
        Assert.IsTrue(fixture.RegisterRestore());
        await fixture.RequestUpload();
        fixture.Invalidate(invalidation);

        fixture.Time += 60;
        await fixture.RequestUpload();

        Assert.IsFalse(fixture.IsAuthorized);
        Assert.AreEqual(1, fixture.UploadCount);
    }

    [Test]
    public async Task AccountChangeInvalidatesAuthorization()
    {
        var fixture = new Fixture();
        Assert.IsTrue(fixture.RegisterRestore());
        await fixture.RequestUpload();
        fixture.Owner = "player-b";

        await fixture.RequestUpload();

        Assert.IsFalse(fixture.IsAuthorized);
        Assert.AreEqual(1, fixture.UploadCount);
    }

    [Test]
    public async Task AccountChangeInvalidatesQueuedUploadWork()
    {
        var completion = new TaskCompletionSource<bool>();
        var fixture = new Fixture
        {
            Upload = _ => completion.Task
        };
        Assert.IsTrue(fixture.RegisterRestore());

        Task first = fixture.RequestUpload();
        fixture.Owner = "player-b";
        await fixture.RequestUpload();
        completion.SetResult(true);
        await first;

        Assert.IsFalse(fixture.IsAuthorized);
        Assert.AreEqual(1, fixture.UploadCount);
    }

    [Test]
    public async Task NewSessionHasNoRestoreAuthorization()
    {
        var previousSession = new Fixture();
        Assert.IsTrue(previousSession.RegisterRestore());
        await previousSession.RequestUpload();

        var nextSession = new Fixture();
        await nextSession.RequestUpload();

        Assert.IsFalse(nextSession.IsAuthorized);
        Assert.AreEqual(0, nextSession.UploadCount);
    }

    [Test]
    public void StatisticsKeysAreDistinctFromBackupKey()
    {
        Type service = Find("SweetMerge.Cloud.PlayerStatisticsCloudSync");
        string[] keys =
        {
            (string)GetConstant(service, "CurrentMoneyKey"),
            (string)GetConstant(service, "TotalMoneyEarnedKey"),
            (string)GetConstant(service, "TotalOrdersCompletedKey"),
            (string)GetConstant(service, "CurrentRebirthCountKey")
        };

        Assert.AreEqual(4, keys.Distinct().Count());
        Assert.IsTrue(keys.All(key =>
            key.StartsWith("dmc_player_stats_v1_", StringComparison.Ordinal)));
        Assert.IsFalse(keys.Any(key =>
            key.StartsWith("dmc_backup_v1_", StringComparison.Ordinal)));
        Assert.IsFalse(keys.Contains("dmc_backup_v1_RELEASE"));
    }

    [Test]
    public void SaveV2StatisticsSchemaRemainsUnchanged()
    {
        Type playerSave = Find("PlayerSaveData");
        Type economySave = Find("EconomySaveData");

        Assert.AreEqual(typeof(int), playerSave.GetField(
            "completedRebirthCount").FieldType);
        Assert.AreEqual(typeof(int), economySave.GetField("cash").FieldType);
        Assert.AreEqual(
            typeof(long),
            economySave.GetField("totalMoneyEarned").FieldType);
        Assert.AreEqual(
            typeof(long),
            economySave.GetField("totalOrdersCompleted").FieldType);
    }

    [Test]
    public async Task UnchangedSnapshotIsSuppressed()
    {
        var fixture = new Fixture();
        Assert.IsTrue(fixture.RegisterRestore());
        await fixture.RequestUpload();

        fixture.Time += 60;
        await fixture.RequestUpload();

        Assert.AreEqual(1, fixture.UploadCount);
        StringAssert.Contains("unchanged", fixture.Status);
    }

    [Test]
    public async Task UploadsAreThrottledAndOnlyOneRequestIsInFlight()
    {
        var completion = new TaskCompletionSource<bool>();
        var fixture = new Fixture
        {
            Upload = _ => completion.Task
        };
        Assert.IsTrue(fixture.RegisterRestore());

        Task first = fixture.RequestUpload();
        Task second = fixture.RequestUpload();
        Assert.AreEqual(1, fixture.UploadCount);
        completion.SetResult(true);
        await Task.WhenAll(first, second);
        await Task.Yield();
        Assert.AreEqual(1, fixture.UploadCount);

        fixture.Values["dmc_player_stats_v1_current_money"] = 18;
        fixture.Time += 10;
        await fixture.RequestUpload();
        Assert.AreEqual(1, fixture.UploadCount);

        fixture.Time += 30;
        await fixture.RequestUpload();
        Assert.AreEqual(2, fixture.UploadCount);
    }

    [Test]
    public async Task NetworkFailureIsNonblockingAndReported()
    {
        var fixture = new Fixture
        {
            Upload = _ => Task.FromException(
                new IOException("test network failure"))
        };
        Assert.IsTrue(fixture.RegisterRestore());

        LogAssert.Expect(
            LogType.Warning,
            new Regex(
                "PLAYER STATISTICS \\| Upload failed; local gameplay was not changed\\."));
        await fixture.RequestUpload();

        Assert.IsTrue(fixture.IsAuthorized);
        StringAssert.Contains("failed", fixture.Status);
        Assert.AreEqual(1, fixture.UploadCount);
    }

    [Test]
    public async Task FailedStatisticsUploadRetriesOnlyAfterLaterAcceptedBackup()
    {
        bool fail = true;
        var fixture = new Fixture
        {
            Upload = _ => fail
                ? Task.FromException(new IOException("test network failure"))
                : Task.CompletedTask
        };
        Assert.IsTrue(fixture.RegisterAcceptedBackup());

        LogAssert.Expect(
            LogType.Warning,
            new Regex(
                "PLAYER STATISTICS \\| Upload failed; local gameplay was not changed\\."));
        await fixture.RequestUpload();
        Assert.AreEqual(1, fixture.UploadCount);

        fail = false;
        fixture.Time += 30;
        fixture.Values["dmc_player_stats_v1_current_money"] = 29;
        Assert.IsTrue(fixture.RegisterAcceptedBackup());
        await fixture.RequestUpload();

        Assert.AreEqual(2, fixture.UploadCount);
        Assert.AreEqual(
            29,
            fixture.Uploads.Last()["dmc_player_stats_v1_current_money"]);
    }

    [Test]
    public async Task NoStatisticsReadbackOrBackupWriteIsRequested()
    {
        var fixture = new Fixture();
        Assert.IsTrue(fixture.RegisterRestore());

        await fixture.RequestUpload();

        Assert.AreEqual(1, fixture.UploadCount);
        Assert.AreEqual(4, fixture.Uploads.Single().Count);
        Assert.IsFalse(fixture.Uploads.Single().Keys.Any(key =>
            key.StartsWith("dmc_backup_v1_", StringComparison.Ordinal)));
    }

    [Test]
    public void AcceptedSaveV2StatisticsKeepExactIntegerTypes()
    {
        Type saveType = Find("PlayerSaveData");
        Type economyType = Find("EconomySaveData");
        object save = Activator.CreateInstance(saveType);
        object economy = Activator.CreateInstance(
            economyType,
            new object[] { 23 });
        saveType.GetField("completedRebirthCount").SetValue(save, 6);
        economyType.GetField("totalMoneyEarned").SetValue(
            economy,
            22345678901234567L);
        economyType.GetField("totalOrdersCompleted").SetValue(
            economy,
            32345678901234567L);
        saveType.GetField("economy").SetValue(save, economy);
        string json = JsonUtility.ToJson(save);
        json = json.Substring(0, json.Length - 1) +
            ",\"mergeSessionCustomerCapacity\":0}";

        Type service = Find("SweetMerge.Cloud.PlayerStatisticsCloudSync");
        MethodInfo method = service.GetMethod(
            "TryCaptureSnapshotFromSaveV2",
            BindingFlags.Static | BindingFlags.NonPublic);
        object[] arguments = { json, null };

        Assert.IsTrue((bool)method.Invoke(null, arguments));
        var snapshot = (IDictionary<string, object>)arguments[1];
        Assert.AreEqual(23, snapshot["dmc_player_stats_v1_current_money"]);
        Assert.AreEqual(
            22345678901234567L,
            snapshot["dmc_player_stats_v1_total_money_earned"]);
        Assert.AreEqual(
            32345678901234567L,
            snapshot["dmc_player_stats_v1_total_orders_completed"]);
        Assert.AreEqual(
            6,
            snapshot["dmc_player_stats_v1_current_rebirth_count"]);
        Assert.IsInstanceOf<long>(
            snapshot["dmc_player_stats_v1_total_money_earned"]);
        Assert.IsInstanceOf<long>(
            snapshot["dmc_player_stats_v1_total_orders_completed"]);
    }

    private static Type Find(string fullName) =>
        AppDomain.CurrentDomain.GetAssemblies()
            .Select(assembly => assembly.GetType(fullName))
            .First(type => type != null);

    private static object Invoke(
        object instance,
        string method,
        params object[] arguments) =>
        instance.GetType().GetMethod(
                method,
                BindingFlags.Instance | BindingFlags.NonPublic)
            .Invoke(instance, arguments);

    private static object GetConstant(Type type, string name) =>
        type.GetField(name, BindingFlags.Static | BindingFlags.NonPublic)
            .GetRawConstantValue();
}
