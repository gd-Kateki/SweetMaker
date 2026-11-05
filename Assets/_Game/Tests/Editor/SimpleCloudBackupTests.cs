using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Reflection;
using System.Threading.Tasks;
using NUnit.Framework;
using UnityEngine;

public sealed class SimpleCloudBackupTests
{
    [TestCase(true, "save-a", "lock-a", "save-a", "lock-a", true)]
    [TestCase(false, "save-a", "lock-a", "save-a", "lock-a", false)]
    [TestCase(true, "save-a", "lock-a", "save-b", "lock-b", false)]
    [TestCase(true, "save-a", "lock-a", "save-a", "lock-b", false)]
    [TestCase(true, "save-a", "lock-a", null, null, false)]
    [TestCase(true, null, null, null, null, false)]
    public void FreshGameRequiresTheSameVerifiedAccountAndReviewedCloudVersion(
        bool identityCurrent, string reviewedHash, string reviewedLock,
        string currentHash, string currentLock, bool expected)
    {
        var method = Find("SweetMerge.Cloud.SimpleCloudBackup").GetMethod(
            "CanStartFreshGame", BindingFlags.Static | BindingFlags.NonPublic);
        Assert.AreEqual(expected, method.Invoke(null, new object[]
        {
            identityCurrent, reviewedHash, reviewedLock, currentHash, currentLock
        }));
    }

    private sealed class FakeConflictOperations
    {
        public string PlayerId = "google-player-a";
        public string ApprovedPlayerId = "google-player-a";
        public string CloudChecksum = "cloud-v1";
        public string ApprovedChecksum = "cloud-v1";
        public string CloudWriteLock = "lock-v1";
        public string ApprovedWriteLock = "lock-v1";
        public string LocalProgress = "guest-progress";
        public string CloudProgress = "cloud-progress";
        public string OwnerMarkerPlayerId;
        public bool LocalSaveValid = true;
        public bool UploadSucceeds = true;
        public bool ChangeCloudDuringRead;
        public bool ChangeCloudBeforeUpload;
        public bool SwitchAccountDuringRead;
        public bool SwitchAccountDuringUpload;
        public bool FailCloudRead;
        public bool SwitchAccountOnIdentityCheck;
        public int IdentityChecks;
        public int CloudReads;
        public int Uploads;
        public string UploadedPlayerId;
        public string UploadedWriteLock;
        public string Failure;
        public int SwitchAccountOnIdentityCheckNumber = 4;
        public readonly List<string> Events = new List<string>();

        public bool ApprovalIsCurrent()
        {
            return CurrentPlayerId() == ApprovedPlayerId &&
                   CloudChecksum == ApprovedChecksum &&
                   CloudWriteLock == ApprovedWriteLock;
        }

        public string CurrentPlayerId()
        {
            IdentityChecks++;
            if (SwitchAccountOnIdentityCheck &&
                IdentityChecks >= SwitchAccountOnIdentityCheckNumber)
                PlayerId = "google-player-b";
            return PlayerId;
        }

        public Task<bool> ReadCloudAsync()
        {
            CloudReads++;
            Events.Add("cloud-check");
            if (FailCloudRead)
                throw new IOException("Fake cloud check failure.");
            if (SwitchAccountDuringRead)
                PlayerId = "google-player-b";
            if (ChangeCloudDuringRead)
            {
                CloudChecksum = "cloud-v2";
                CloudWriteLock = "lock-v2";
                CloudProgress = "other-device-progress";
            }
            return Task.FromResult(true);
        }

        public bool EnsureOwnership()
        {
            string playerId = CurrentPlayerId();
            if (playerId != ApprovedPlayerId ||
                !LocalSaveValid ||
                OwnerMarkerPlayerId != null)
                return false;
            OwnerMarkerPlayerId = playerId;
            Events.Add("ownership-linked");
            if (CurrentPlayerId() != playerId)
            {
                OwnerMarkerPlayerId = null;
                Events.RemoveAt(Events.Count - 1);
                return false;
            }

            return true;
        }

        public Task<bool> UploadAsync()
        {
            Uploads++;
            Events.Add("upload");
            UploadedPlayerId = CurrentPlayerId();
            UploadedWriteLock = ApprovedWriteLock;
            if (ChangeCloudBeforeUpload)
            {
                CloudChecksum = "cloud-v2";
                CloudWriteLock = "lock-v2";
                CloudProgress = "other-device-progress";
            }
            if (SwitchAccountDuringUpload)
                PlayerId = "google-player-b";
            if (UploadedWriteLock != CloudWriteLock)
                throw new IOException("Fake cloud write-lock conflict.");
            if (!UploadSucceeds)
                throw new IOException("Fake Cloud Save write failure.");

            CloudProgress = LocalProgress;
            CloudChecksum = "cloud-after-upload";
            CloudWriteLock = "lock-after-upload";
            return Task.FromResult(true);
        }
    }

    private static Type Find(string name) => AppDomain.CurrentDomain.GetAssemblies()
        .Select(a => a.GetType(name)).First(t => t != null);
    private static void Set(object o, string name, object value) => o.GetType().GetField(name).SetValue(o, value);
    private static object Get(object o, string name) => o.GetType().GetField(name).GetValue(o);
    private static bool Valid(object value, string owner = "player-a") =>
        (bool)value.GetType().GetMethod("IsValid").Invoke(value, new object[] { owner });

    private object Envelope()
    {
        var value = Activator.CreateInstance(Find("SweetMerge.Cloud.CloudBackupEnvelope"));
        var save = Activator.CreateInstance(Find("PlayerSaveData"));
        string json = JsonUtility.ToJson(save);
        json = json.Substring(0, json.Length - 1) + ",\"mergeSessionCustomerCapacity\":0}";
        Set(value, "saveJson", json);
        Set(value, "environment", Find("SavePathPolicy").GetProperty("ModeName").GetValue(null));
        Set(value, "playerId", "player-a"); Set(value, "cafeName", "Sunny Café"); Set(value, "tutorialStage", 4);
        Seal(value);
        return value;
    }
    private static void Seal(object value) => Set(value, "checksum", value.GetType().GetMethod("ContentHash").Invoke(value, null));

    [Test] public void ExactV2AndProfileRoundTrip()
    {
        var value = Envelope(); Assert.IsTrue(Valid(value));
        var copy = JsonUtility.FromJson(JsonUtility.ToJson(value), value.GetType());
        Assert.IsTrue(Valid(copy)); Assert.AreEqual(Get(value,"saveJson"), Get(copy,"saveJson"));
        Assert.AreEqual("Sunny Café", Get(copy,"cafeName")); Assert.AreEqual(4, Get(copy,"tutorialStage"));
    }
    [Test] public void OtherAccountCannotRestore() => Assert.IsFalse(Valid(Envelope(), "player-b"));
    [Test] public void OtherEnvironmentCannotRestore()
    { var value=Envelope(); Set(value,"environment","other"); Assert.IsFalse(Valid(value)); }
    [Test] public void ChangedSaveWithoutChecksumIsRejected()
    { var value=Envelope(); Set(value,"saveJson",((string)Get(value,"saveJson")).Replace("\"cash\":0","\"cash\":10")); Assert.IsFalse(Valid(value)); }
    [Test] public void FutureSaveVersionIsRejectedEvenWithChecksum()
    { var value=Envelope(); Set(value,"saveJson",((string)Get(value,"saveJson")).Replace("\"saveVersion\":2","\"saveVersion\":3")); Seal(value); Assert.IsFalse(Valid(value)); }
    [Test] public void NegativeCashIsRejectedEvenWithChecksum()
    { var value=Envelope(); Set(value,"saveJson",((string)Get(value,"saveJson")).Replace("\"cash\":0","\"cash\":-1")); Seal(value); Assert.IsFalse(Valid(value)); }
    [TestCase(-1)] [TestCase(5)] public void InvalidTutorialRejected(int stage)
    { var value=Envelope(); Set(value,"tutorialStage",stage); Seal(value); Assert.IsFalse(Valid(value)); }
    [TestCase("")] [TestCase("  café")] [TestCase("123456789012345678901")]
    public void InvalidCafeNameRejected(string name)
    { var value=Envelope(); Set(value,"cafeName",name); Seal(value); Assert.IsFalse(Valid(value)); }
    [TestCase("local","cloud",null,2)]
    [TestCase("local",null,null,2)]
    [TestCase("same","same",null,0)]
    [TestCase("local","cloud","cloud",1)]
    [TestCase("local","other-device","previous",2)]
    [TestCase("local",null,"deleted-cloud",2)]
    public void SyncDecisionRequiresConsentUnlessCloudIsAccepted(string local,string remote,string accepted,int expected)
    { Assert.AreEqual(expected, Find("SweetMerge.Cloud.SimpleCloudBackup").GetMethod("Decide").Invoke(null,new object[]{local,remote,accepted})); }

    private sealed class FakeInitialBackupOperations
    {
        public string PlayerId = "google-player-a";
        public string OwnedPlayerId = "google-player-a";
        public string Environment = "production";
        public string OwnedEnvironment = "production";
        public bool RemoteExists;
        public bool InvalidRemote;
        public bool GameplayReady = true;
        public bool PendingRestore;
        public bool OwnershipValid = true;
        public bool FailUpload;
        public bool CreateRemoteBeforeFailure;
        public bool SwitchAccountDuringUpload;
        public int CloudReads;
        public int Uploads;
        public string LocalProgress = "owned-local-progress";

        public Task<bool> ConfirmRemoteAbsentAsync()
        {
            CloudReads++;
            if (InvalidRemote)
                throw new InvalidDataException("Fake remote envelope is invalid.");
            return Task.FromResult(!RemoteExists);
        }

        public bool AuthorizationIsCurrent()
        {
            return OwnershipValid &&
                   PlayerId == OwnedPlayerId &&
                   Environment == OwnedEnvironment &&
                   !PendingRestore;
        }

        public bool LinkGuestProgress(bool confirmed)
        {
            if (!confirmed || OwnedPlayerId != null)
                return false;
            OwnedPlayerId = PlayerId;
            return true;
        }

        public Task UploadAsync()
        {
            Uploads++;
            if (CreateRemoteBeforeFailure)
                RemoteExists = true;
            if (SwitchAccountDuringUpload)
                PlayerId = "google-player-b";
            if (FailUpload || CreateRemoteBeforeFailure)
                throw new IOException("Fake upload failure.");

            RemoteExists = true;
            return Task.FromResult(true);
        }
    }

    private static async Task<bool> RunInitialBackupAsync(
        FakeInitialBackupOperations operations)
    {
        MethodInfo method = Find("SweetMerge.Cloud.SimpleCloudBackup")
            .GetMethod(
                "TryCreateInitialBackupAsync",
                BindingFlags.Static | BindingFlags.NonPublic);
        Assert.IsNotNull(method);
        var task = (Task)method.Invoke(
            null,
            new object[]
            {
                (Func<Task<bool>>)operations.ConfirmRemoteAbsentAsync,
                (Func<bool>)(() => operations.GameplayReady),
                (Func<bool>)operations.AuthorizationIsCurrent,
                (Func<Task>)operations.UploadAsync
            });
        await task;
        return (bool)task.GetType().GetProperty("Result").GetValue(task);
    }

    [Test]
    public async Task FreshGooglePlayerAutomaticallyCreatesFirstBackupAfterReadiness()
    {
        var operations = new FakeInitialBackupOperations
        {
            GameplayReady = false
        };

        Assert.IsFalse(await RunInitialBackupAsync(operations));
        Assert.AreEqual(0, operations.Uploads);
        Assert.IsFalse(operations.RemoteExists);

        operations.GameplayReady = true;
        Assert.IsTrue(await RunInitialBackupAsync(operations));
        Assert.AreEqual(2, operations.CloudReads);
        Assert.AreEqual(1, operations.Uploads);
        Assert.IsTrue(operations.RemoteExists);
        Assert.AreEqual("owned-local-progress", operations.LocalProgress);
    }

    [Test]
    public async Task ReturningOwnedPlayerCanCreateMissingFirstBackup()
    {
        var operations = new FakeInitialBackupOperations();

        Assert.IsTrue(await RunInitialBackupAsync(operations));
        Assert.AreEqual(1, operations.CloudReads);
        Assert.AreEqual(1, operations.Uploads);
    }

    [Test]
    public async Task ApprovedGuestLinkCanBackUpButCancellationCannot()
    {
        var approved = new FakeInitialBackupOperations
        {
            OwnedPlayerId = null
        };
        Assert.IsTrue(approved.LinkGuestProgress(confirmed: true));
        Assert.IsTrue(await RunInitialBackupAsync(approved));
        Assert.AreEqual(1, approved.Uploads);

        var cancelled = new FakeInitialBackupOperations
        {
            OwnedPlayerId = null
        };
        Assert.IsFalse(cancelled.LinkGuestProgress(confirmed: false));
        Assert.IsFalse(await RunInitialBackupAsync(cancelled));
        Assert.AreEqual(0, cancelled.Uploads);
        Assert.IsFalse(cancelled.RemoteExists);
    }

    [Test]
    public async Task ExistingRemoteBackupIsNeverAutomaticallyOverwritten()
    {
        var operations = new FakeInitialBackupOperations
        {
            RemoteExists = true
        };

        Assert.IsFalse(await RunInitialBackupAsync(operations));
        Assert.AreEqual(1, operations.CloudReads);
        Assert.AreEqual(0, operations.Uploads);
    }

    [Test]
    public async Task InvalidOwnershipPendingRestoreAndEnvironmentMismatchBlockFirstBackup()
    {
        foreach (FakeInitialBackupOperations operations in new[]
                 {
                     new FakeInitialBackupOperations
                     {
                         OwnedPlayerId = "google-player-b"
                     },
                     new FakeInitialBackupOperations
                     {
                         OwnedEnvironment = "staging"
                     },
                     new FakeInitialBackupOperations
                     {
                         PendingRestore = true
                     },
                     new FakeInitialBackupOperations
                     {
                         OwnershipValid = false
                     }
                 })
        {
            Assert.IsFalse(await RunInitialBackupAsync(operations));
            Assert.AreEqual(0, operations.Uploads);
        }
    }

    [Test]
    public void InvalidRemoteEnvelopeIsNotTreatedAsAbsent()
    {
        var operations = new FakeInitialBackupOperations
        {
            InvalidRemote = true
        };

        Assert.ThrowsAsync<InvalidDataException>(
            async () => await RunInitialBackupAsync(operations));
        Assert.AreEqual(1, operations.CloudReads);
        Assert.AreEqual(0, operations.Uploads);
    }

    [Test]
    public void AccountSwitchDuringFirstUploadDoesNotReportSuccess()
    {
        var operations = new FakeInitialBackupOperations
        {
            SwitchAccountDuringUpload = true
        };

        Assert.CatchAsync<OperationCanceledException>(
            async () => await RunInitialBackupAsync(operations));
        Assert.AreEqual(1, operations.Uploads);
        Assert.AreEqual("owned-local-progress", operations.LocalProgress);
    }

    [Test]
    public async Task FailedOrAmbiguousFirstUploadRequiresFreshCloudCheckBeforeRetry()
    {
        var operations = new FakeInitialBackupOperations
        {
            CreateRemoteBeforeFailure = true
        };

        Assert.ThrowsAsync<IOException>(
            async () => await RunInitialBackupAsync(operations));
        Assert.AreEqual(1, operations.Uploads);

        Assert.IsFalse(await RunInitialBackupAsync(operations));
        Assert.AreEqual(2, operations.CloudReads);
        Assert.AreEqual(1, operations.Uploads);
    }

    [Test]
    public async Task FailedFirstUploadCanRetryOnlyAfterAnotherFreshAbsentCheck()
    {
        var operations = new FakeInitialBackupOperations
        {
            FailUpload = true
        };

        Assert.ThrowsAsync<IOException>(
            async () => await RunInitialBackupAsync(operations));
        Assert.AreEqual(1, operations.CloudReads);
        Assert.AreEqual(1, operations.Uploads);

        operations.FailUpload = false;
        Assert.IsTrue(await RunInitialBackupAsync(operations));
        Assert.AreEqual(2, operations.CloudReads);
        Assert.AreEqual(2, operations.Uploads);
    }

    private sealed class FakeOngoingBackupOperations
    {
        public string PlayerId = "google-player-a";
        public string OwnedPlayerId = "google-player-a";
        public string Environment = "production";
        public string OwnedEnvironment = "production";
        public string LocalSnapshot = "local-v1";
        public string CloudSnapshot = "local-v1";
        public string AcceptedSnapshot = "local-v1";
        public string CloudWriteLock = "lock-v1";
        public bool Connected = true;
        public bool OwnershipValid = true;
        public bool GameplayReady = true;
        public bool RestorePending;
        public bool ChoiceRequired;
        public bool ChangeLockBeforeWrite;
        public bool FailUpload;
        public bool SwitchAccountDuringUpload;
        public bool SaveBackupPending;
        public float SaveBackupDue;
        public int CloudReads;
        public int Uploads;
        public int SuccessfulUploads;
        public int ConflictPrompts;
        public string UploadedSnapshot;

        public bool AuthorizationIsCurrent() =>
            Connected &&
            OwnershipValid &&
            GameplayReady &&
            !RestorePending &&
            PlayerId == OwnedPlayerId &&
            Environment == OwnedEnvironment;

        public void Commit(float time, string snapshot)
        {
            LocalSnapshot = snapshot;
            if (!SaveBackupPending)
                SaveBackupDue = SaveBackupDueTime(time);
            SaveBackupPending = true;
        }

        public async Task<bool> RunScheduledCheckAsync(float time)
        {
            if (!IsSaveBackupDue(
                    SaveBackupPending,
                    time,
                    SaveBackupDue))
                return false;

            SaveBackupPending = false;
            return await CheckAndUploadAsync();
        }

        public async Task<bool> CheckAndUploadAsync()
        {
            CloudReads++;
            if (!AuthorizationIsCurrent() || ChoiceRequired)
                return false;

            int decision = (int)Find("SweetMerge.Cloud.SimpleCloudBackup")
                .GetMethod("Decide")
                .Invoke(
                    null,
                    new object[]
                    {
                        LocalSnapshot,
                        CloudSnapshot,
                        AcceptedSnapshot
                    });
            if (decision == 0)
            {
                AcceptedSnapshot = LocalSnapshot;
                return false;
            }
            if (decision == 2)
            {
                ChoiceRequired = true;
                ConflictPrompts++;
                return false;
            }

            string reviewedWriteLock = CloudWriteLock;
            bool uploaded = await RunAcceptedCopyBackupAsync(
                decision,
                this,
                async () =>
                {
                    if (ChangeLockBeforeWrite)
                        CloudWriteLock = "lock-from-another-device";
                    if (!AuthorizationIsCurrent())
                        throw new OperationCanceledException();
                    if (CloudWriteLock != reviewedWriteLock)
                        throw new IOException("Cloud write lock conflict.");
                    Uploads++;
                    if (FailUpload)
                        throw new IOException("Fake network failure.");
                    SuccessfulUploads++;
                    if (SwitchAccountDuringUpload)
                        PlayerId = "google-player-b";
                    UploadedSnapshot = LocalSnapshot;
                    CloudSnapshot = LocalSnapshot;
                    CloudWriteLock = "lock-v2";
                });
            if (uploaded)
                AcceptedSnapshot = CloudSnapshot;
            return uploaded;
        }
    }

    private static float SaveBackupDueTime(float now, bool immediate = false)
    {
        string methodName = immediate
            ? "GetImmediateSaveBackupDueTime"
            : "GetSaveBackupDueTime";
        return (float)Find("SweetMerge.Cloud.SimpleCloudBackup")
            .GetMethod(methodName, BindingFlags.Static | BindingFlags.NonPublic)
            .Invoke(null, new object[] { now });
    }

    private static bool IsSaveBackupDue(bool pending, float now, float due)
    {
        return (bool)Find("SweetMerge.Cloud.SimpleCloudBackup")
            .GetMethod("IsSaveBackupDue", BindingFlags.Static | BindingFlags.NonPublic)
            .Invoke(null, new object[] { pending, now, due });
    }

    private static async Task<bool> RunAcceptedCopyBackupAsync(
        int decision,
        FakeOngoingBackupOperations operations,
        Func<Task> upload)
    {
        MethodInfo method = Find("SweetMerge.Cloud.SimpleCloudBackup")
            .GetMethod(
                "TryUploadAcceptedCopyAsync",
                BindingFlags.Static | BindingFlags.NonPublic);
        Assert.IsNotNull(method);
        var task = (Task)method.Invoke(
            null,
            new object[]
            {
                decision,
                (Func<bool>)operations.AuthorizationIsCurrent,
                upload
            });
        await task;
        return (bool)task.GetType().GetProperty("Result").GetValue(task);
    }

    [Test]
    public void RepeatedSaveEventsDoNotPostponePendingBackup()
    {
        Type type = Find("SweetMerge.Cloud.SimpleCloudBackup");
        var gameObject = new GameObject("Cloud backup scheduling test");
        try
        {
            var service = gameObject.AddComponent(type);
            const BindingFlags flags = BindingFlags.Instance | BindingFlags.NonPublic;
            type.GetField("owner", flags).SetValue(service, "player-a");
            MethodInfo committed = type.GetMethod("HandleActiveSaveCommitted", flags);
            committed.Invoke(service, null);
            float firstDue = (float)type.GetField("saveBackupDue", flags).GetValue(service);
            Assert.AreEqual(5f, SaveBackupDueTime(0f));
            // An already scheduled deadline must survive subsequent commits.
            type.GetField("saveBackupDue", flags).SetValue(service, firstDue - 1f);
            committed.Invoke(service, null);
            Assert.AreEqual(firstDue - 1f,
                type.GetField("saveBackupDue", flags).GetValue(service));
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(gameObject);
        }
    }

    [Test]
    public async Task SaveCommitWaitsFiveSecondsAndCombinesQuickSaves()
    {
        var operations = new FakeOngoingBackupOperations
        {
            LocalSnapshot = "local-v1",
            CloudSnapshot = "local-v1",
            AcceptedSnapshot = "local-v1"
        };
        Assert.IsFalse(await operations.RunScheduledCheckAsync(10f));
        Assert.AreEqual(0, operations.CloudReads);

        operations.Commit(10f, "local-v2");
        operations.Commit(11f, "local-v3");
        Assert.IsFalse(await operations.RunScheduledCheckAsync(14.9f));
        Assert.AreEqual(0, operations.Uploads);
        Assert.IsTrue(await operations.RunScheduledCheckAsync(15f));
        Assert.AreEqual(1, operations.Uploads);
        Assert.AreEqual("local-v3", operations.UploadedSnapshot);
    }

    [Test]
    public async Task AcceptedCloudCopyUploadsLatestCommittedSnapshot()
    {
        var operations = new FakeOngoingBackupOperations
        {
            LocalSnapshot = "local-v2",
            CloudSnapshot = "local-v1",
            AcceptedSnapshot = "local-v1"
        };

        Assert.IsTrue(await operations.CheckAndUploadAsync());
        Assert.AreEqual(1, operations.Uploads);
        Assert.AreEqual("local-v2", operations.UploadedSnapshot);
        Assert.AreEqual("local-v2", operations.CloudSnapshot);
        Assert.AreEqual(0, operations.ConflictPrompts);
    }

    [Test]
    public async Task OfflineBackupRetriesAfterConnectivityReturns()
    {
        var operations = new FakeOngoingBackupOperations
        {
            Connected = false,
            LocalSnapshot = "local-v2",
            CloudSnapshot = "local-v1",
            AcceptedSnapshot = "local-v1"
        };

        Assert.IsFalse(await operations.CheckAndUploadAsync());
        Assert.AreEqual(0, operations.Uploads);
        operations.Connected = true;
        Assert.IsTrue(await operations.CheckAndUploadAsync());
        Assert.AreEqual(1, operations.Uploads);
        Assert.AreEqual("local-v2", operations.UploadedSnapshot);
    }

    [Test]
    public async Task AccountSwitchInvalidOwnershipAndPendingRestoreBlockAutomaticUpload()
    {
        foreach (FakeOngoingBackupOperations operations in new[]
                 {
                     new FakeOngoingBackupOperations
                     {
                         PlayerId = "google-player-b",
                         LocalSnapshot = "local-v2",
                         CloudSnapshot = "local-v1",
                         AcceptedSnapshot = "local-v1"
                     },
                     new FakeOngoingBackupOperations
                     {
                         OwnershipValid = false,
                         LocalSnapshot = "local-v2",
                         CloudSnapshot = "local-v1",
                         AcceptedSnapshot = "local-v1"
                     },
                     new FakeOngoingBackupOperations
                     {
                         Environment = "staging",
                         LocalSnapshot = "local-v2",
                         CloudSnapshot = "local-v1",
                         AcceptedSnapshot = "local-v1"
                     },
                     new FakeOngoingBackupOperations
                     {
                         RestorePending = true,
                         LocalSnapshot = "local-v2",
                         CloudSnapshot = "local-v1",
                         AcceptedSnapshot = "local-v1"
                     }
                 })
        {
            Assert.IsFalse(await operations.CheckAndUploadAsync());
            Assert.AreEqual(0, operations.Uploads);
        }
    }

    [Test]
    public void RemoteWriteLockConflictDoesNotOverwriteCloud()
    {
        var operations = new FakeOngoingBackupOperations
        {
            LocalSnapshot = "local-v2",
            CloudSnapshot = "local-v1",
            AcceptedSnapshot = "local-v1",
            ChangeLockBeforeWrite = true
        };

        Assert.ThrowsAsync<IOException>(
            async () => await operations.CheckAndUploadAsync());
        Assert.AreEqual(0, operations.Uploads);
        Assert.AreEqual("local-v1", operations.CloudSnapshot);
    }

    [Test]
    public async Task TransientUploadFailureKeepsAcceptedCopyAndRetriesFreshly()
    {
        var operations = new FakeOngoingBackupOperations
        {
            LocalSnapshot = "local-v2",
            CloudSnapshot = "local-v1",
            AcceptedSnapshot = "local-v1",
            FailUpload = true
        };

        Assert.ThrowsAsync<IOException>(
            async () => await operations.CheckAndUploadAsync());
        Assert.AreEqual("local-v1", operations.AcceptedSnapshot);
        Assert.AreEqual("local-v1", operations.CloudSnapshot);

        operations.FailUpload = false;
        Assert.IsTrue(await operations.CheckAndUploadAsync());
        Assert.AreEqual(2, operations.CloudReads);
        Assert.AreEqual(2, operations.Uploads);
        Assert.AreEqual(1, operations.SuccessfulUploads);
        Assert.AreEqual("local-v2", operations.CloudSnapshot);
        Assert.AreEqual("local-v2", operations.AcceptedSnapshot);

        Assert.IsFalse(await operations.CheckAndUploadAsync());
        Assert.AreEqual(3, operations.CloudReads);
        Assert.AreEqual(2, operations.Uploads);
        Assert.AreEqual(1, operations.SuccessfulUploads);
    }

    [Test]
    public async Task ExternalCloudChangeRequiresChoiceInsteadOfRepeatedPrompts()
    {
        var operations = new FakeOngoingBackupOperations
        {
            LocalSnapshot = "local-v2",
            CloudSnapshot = "local-v1",
            AcceptedSnapshot = "local-v1"
        };

        Assert.IsTrue(await operations.CheckAndUploadAsync());
        operations.LocalSnapshot = "local-v3";
        Assert.IsTrue(await operations.CheckAndUploadAsync());
        Assert.AreEqual(2, operations.Uploads);
        Assert.AreEqual(0, operations.ConflictPrompts);

        operations.LocalSnapshot = "local-v4";
        operations.CloudSnapshot = "other-device-v1";
        Assert.IsFalse(await operations.CheckAndUploadAsync());
        Assert.IsTrue(operations.ChoiceRequired);
        Assert.AreEqual(1, operations.ConflictPrompts);
        Assert.AreEqual(2, operations.Uploads);
    }

    [Test]
    public async Task UnchangedProgressDoesNotUploadAndAccountSwitchDuringWriteIsNotSuccess()
    {
        var unchanged = new FakeOngoingBackupOperations();
        Assert.IsFalse(await unchanged.CheckAndUploadAsync());
        Assert.AreEqual(0, unchanged.Uploads);

        var switched = new FakeOngoingBackupOperations
        {
            LocalSnapshot = "local-v2",
            CloudSnapshot = "local-v1",
            AcceptedSnapshot = "local-v1",
            SwitchAccountDuringUpload = true
        };
        Assert.CatchAsync<OperationCanceledException>(
            async () => await switched.CheckAndUploadAsync());
        Assert.AreEqual("google-player-a", switched.OwnedPlayerId);
        Assert.AreEqual(1, switched.Uploads);
    }

    [Test]
    public void BackgroundAndResumeCanScheduleAnImmediateCheck()
    {
        float backgroundDue = SaveBackupDueTime(20f, immediate: true);
        Assert.IsTrue(IsSaveBackupDue(true, 20f, backgroundDue));
        float resumeDue = SaveBackupDueTime(30f, immediate: true);
        Assert.IsTrue(IsSaveBackupDue(true, 30f, resumeDue));
    }

    [Test]
    public void SaveManagerCanNotifyCommittedActiveSaveListeners()
    {
        Type saveManager = Find("SaveManager");
        EventInfo committed = saveManager.GetEvent(
            "ActiveSaveV2Committed",
            BindingFlags.Static | BindingFlags.NonPublic);
        Assert.IsNotNull(committed);
        int notifications = 0;
        Action listener = () => notifications++;
        MethodInfo add = committed.GetAddMethod(nonPublic: true);
        MethodInfo remove = committed.GetRemoveMethod(nonPublic: true);
        Assert.IsNotNull(add);
        Assert.IsNotNull(remove);
        add.Invoke(null, new object[] { listener });
        try
        {
            saveManager.GetMethod(
                    "NotifyActiveSaveV2Committed",
                    BindingFlags.Static | BindingFlags.NonPublic)
                .Invoke(null, null);
            Assert.AreEqual(1, notifications);
        }
        finally
        {
            remove.Invoke(null, new object[] { listener });
        }
    }

    private static bool CanCommitKeepDevice(
        bool explicitConfirmation = true,
        bool choiceRequired = true,
        bool remoteAvailable = true,
        bool identityMatches = true,
        int currentEpoch = 4,
        int approvedEpoch = 4,
        string approvedChecksum = "reviewed-checksum",
        string currentChecksum = "reviewed-checksum",
        string approvedWriteLock = "reviewed-lock",
        string currentWriteLock = "reviewed-lock",
        bool restorePending = false)
    {
        MethodInfo method = Find("SweetMerge.Cloud.SimpleCloudBackup")
            .GetMethod(
                "CanCommitKeepDeviceConfirmation",
                BindingFlags.Static | BindingFlags.NonPublic);
        Assert.IsNotNull(method);
        return (bool)method.Invoke(
            null,
            new object[]
            {
                explicitConfirmation,
                choiceRequired,
                remoteAvailable,
                identityMatches,
                currentEpoch,
                approvedEpoch,
                approvedChecksum,
                currentChecksum,
                approvedWriteLock,
                currentWriteLock,
                restorePending
            });
    }

    [Test]
    public void KeepDeviceRequiresExplicitConfirmation()
    {
        Assert.IsTrue(CanCommitKeepDevice());
        Assert.IsFalse(CanCommitKeepDevice(explicitConfirmation: false));
    }

    [Test]
    public void KeepDeviceConfirmationRejectsChangedAccountOrEpoch()
    {
        Assert.IsFalse(CanCommitKeepDevice(identityMatches: false));
        Assert.IsFalse(CanCommitKeepDevice(currentEpoch: 5));
    }

    [Test]
    public void KeepDeviceConfirmationRejectsChangedCloudVersionOrLock()
    {
        Assert.IsFalse(CanCommitKeepDevice(
            currentChecksum: "new-cloud-checksum"));
        Assert.IsFalse(CanCommitKeepDevice(
            currentWriteLock: "new-cloud-lock"));
        Assert.IsFalse(CanCommitKeepDevice(
            approvedWriteLock: null));
    }

    [Test]
    public void KeepDeviceConfirmationRejectsMissingConflictOrPendingRestore()
    {
        Assert.IsFalse(CanCommitKeepDevice(choiceRequired: false));
        Assert.IsFalse(CanCommitKeepDevice(remoteAvailable: false));
        Assert.IsFalse(CanCommitKeepDevice(restorePending: true));
    }

    [Test]
    public void KeepDeviceCancellationDoesNotAuthorizeAWrite()
    {
        Assert.IsFalse(CanCommitKeepDevice(explicitConfirmation: false));
    }

    [Test]
    public void CloudWriteLockChangesInvalidateTheReviewedChoice()
    {
        Assert.IsFalse(CanCommitKeepDevice(
            currentWriteLock: "new-lock"));
    }

    private static async Task<string> RunKeepDeviceFlowAsync(
        FakeConflictOperations operations,
        string choice = "KeepDevice",
        bool explicitlyConfirmed = true)
    {
        MethodInfo method = Find("SweetMerge.Cloud.SimpleCloudBackup")
            .GetMethod(
                "RunKeepDeviceConflictAsync",
                BindingFlags.Static | BindingFlags.NonPublic);
        Assert.IsNotNull(method);
        Type choiceType = Find("SweetMerge.Cloud.CloudConflictChoice");
        object selectedChoice = Enum.Parse(choiceType, choice);

        var task = (Task)method.Invoke(
            null,
            new object[]
            {
                selectedChoice,
                explicitlyConfirmed,
                (Func<bool>)operations.ApprovalIsCurrent,
                (Func<Task<bool>>)operations.ReadCloudAsync,
                (Func<bool>)operations.EnsureOwnership,
                (Func<Task<bool>>)operations.UploadAsync,
                (Func<bool>)(() =>
                    operations.CurrentPlayerId() ==
                    operations.ApprovedPlayerId),
                (Action<Exception>)(exception =>
                    operations.Failure = exception.Message)
            });
        await task;
        return task.GetType().GetProperty("Result").GetValue(task).ToString();
    }

    [Test]
    public async Task ConfirmedKeepDeviceLinksGuestAndWritesReviewedLock()
    {
        var operations = new FakeConflictOperations();
        string localBefore = operations.LocalProgress;

        string result = await RunKeepDeviceFlowAsync(operations);

        Assert.AreEqual("Completed", result);
        Assert.AreEqual(1, operations.CloudReads);
        Assert.AreEqual(1, operations.Uploads);
        Assert.AreEqual("google-player-a", operations.OwnerMarkerPlayerId);
        Assert.AreEqual("google-player-a", operations.UploadedPlayerId);
        Assert.AreEqual("lock-v1", operations.UploadedWriteLock);
        CollectionAssert.AreEqual(
            new[] { "cloud-check", "ownership-linked", "upload" },
            operations.Events);
        Assert.AreEqual(localBefore, operations.LocalProgress);
        Assert.AreEqual(localBefore, operations.CloudProgress);
        Assert.IsNull(operations.Failure);
    }

    [Test]
    public async Task ChangedCloudVersionRequiresFreshReviewAndDoesNotLinkOrUpload()
    {
        var operations = new FakeConflictOperations
        {
            ChangeCloudDuringRead = true
        };
        string cloudBefore = operations.CloudProgress;

        string result = await RunKeepDeviceFlowAsync(operations);

        Assert.AreEqual("ApprovalChanged", result);
        Assert.AreEqual(1, operations.CloudReads);
        Assert.AreEqual(0, operations.Uploads);
        Assert.IsNull(operations.OwnerMarkerPlayerId);
        Assert.AreEqual("other-device-progress", operations.CloudProgress);
        Assert.AreNotEqual(cloudBefore, operations.CloudProgress);
    }

    [Test]
    public async Task CloudCheckFailureCannotLinkGuestOrUpload()
    {
        var operations = new FakeConflictOperations
        {
            FailCloudRead = true
        };

        string result = await RunKeepDeviceFlowAsync(operations);

        Assert.AreEqual("CloudCheckFailed", result);
        Assert.AreEqual(1, operations.CloudReads);
        Assert.AreEqual(0, operations.Uploads);
        Assert.IsNull(operations.OwnerMarkerPlayerId);
        StringAssert.Contains("Fake cloud check failure", operations.Failure);
    }

    [Test]
    public async Task AccountSwitchDuringConfirmationOrCloudReadPreventsUpload()
    {
        var confirmationOperations = new FakeConflictOperations
        {
            PlayerId = "google-player-b"
        };
        string confirmationResult =
            await RunKeepDeviceFlowAsync(confirmationOperations);
        Assert.AreEqual("ApprovalChanged", confirmationResult);
        Assert.AreEqual(0, confirmationOperations.CloudReads);
        Assert.AreEqual(0, confirmationOperations.Uploads);

        var readOperations = new FakeConflictOperations
        {
            SwitchAccountDuringRead = true
        };
        string readResult = await RunKeepDeviceFlowAsync(readOperations);
        Assert.AreEqual("ApprovalChanged", readResult);
        Assert.AreEqual(0, readOperations.Uploads);
        Assert.IsNull(readOperations.OwnerMarkerPlayerId);
    }

    [Test]
    public async Task AccountSwitchDuringOwnershipEstablishmentCannotTransferGuestSave()
    {
        var operations = new FakeConflictOperations
        {
            SwitchAccountOnIdentityCheck = true
        };

        string result = await RunKeepDeviceFlowAsync(operations);

        Assert.AreEqual("OwnershipBlocked", result);
        Assert.AreEqual(0, operations.Uploads);
        Assert.IsNull(operations.OwnerMarkerPlayerId);
    }

    [Test]
    public async Task AccountSwitchDuringWriteDoesNotReportSuccessfulBackup()
    {
        var operations = new FakeConflictOperations
        {
            SwitchAccountDuringUpload = true
        };
        string localBefore = operations.LocalProgress;

        string result = await RunKeepDeviceFlowAsync(operations);

        Assert.AreEqual("OutcomeUnknown", result);
        Assert.AreEqual(1, operations.Uploads);
        Assert.AreEqual("google-player-a", operations.UploadedPlayerId);
        Assert.AreEqual(localBefore, operations.LocalProgress);
        Assert.IsNull(operations.Failure);
    }

    [Test]
    public async Task FailedUploadPreservesLocalProgressAndOwnershipAndReportsFailure()
    {
        var operations = new FakeConflictOperations
        {
            UploadSucceeds = false
        };
        string localBefore = operations.LocalProgress;
        string cloudBefore = operations.CloudProgress;

        string result = await RunKeepDeviceFlowAsync(operations);

        Assert.AreEqual("UploadFailed", result);
        Assert.AreEqual(1, operations.Uploads);
        Assert.AreEqual(localBefore, operations.LocalProgress);
        Assert.AreEqual(cloudBefore, operations.CloudProgress);
        Assert.AreEqual("google-player-a", operations.OwnerMarkerPlayerId);
        StringAssert.Contains("Fake Cloud Save write failure", operations.Failure);
    }

    [Test]
    public async Task WriteLockRaceDoesNotOverwriteNewCloudVersion()
    {
        var operations = new FakeConflictOperations
        {
            ChangeCloudBeforeUpload = true
        };

        string result = await RunKeepDeviceFlowAsync(operations);

        Assert.AreEqual("UploadFailed", result);
        Assert.AreEqual(1, operations.Uploads);
        Assert.AreEqual("other-device-progress", operations.CloudProgress);
        Assert.AreEqual("google-player-a", operations.OwnerMarkerPlayerId);
        StringAssert.Contains("write-lock conflict", operations.Failure);
    }

    [Test]
    public void UploadAndAmbiguousResultsRequireFreshCloudCheck()
    {
        Type resultType = Find("SweetMerge.Cloud.KeepDeviceConflictResult");
        MethodInfo method = Find("SweetMerge.Cloud.SimpleCloudBackup")
            .GetMethod(
                "RequiresFreshCloudCheck",
                BindingFlags.Static | BindingFlags.NonPublic);
        Assert.IsNotNull(method);

        foreach (string resultName in new[]
                 {
                     "ApprovalChanged",
                     "CloudCheckFailed",
                     "UploadFailed",
                     "OutcomeUnknown"
                 })
        {
            Assert.IsTrue((bool)method.Invoke(
                null,
                new[] { Enum.Parse(resultType, resultName) }));
        }

        foreach (string resultName in new[]
                 {
                     "Completed",
                     "Cancelled",
                     "OwnershipBlocked",
                     "RestoreSelected"
                 })
        {
            Assert.IsFalse((bool)method.Invoke(
                null,
                new[] { Enum.Parse(resultType, resultName) }));
        }
    }

    [Test]
    public async Task CancelAndRestoreChoiceDoNotReadLinkOrUpload()
    {
        var canceled = new FakeConflictOperations();
        string canceledLocalBefore = canceled.LocalProgress;
        string canceledCloudBefore = canceled.CloudProgress;
        var restored = new FakeConflictOperations();
        string restoredLocalBefore = restored.LocalProgress;
        string restoredCloudBefore = restored.CloudProgress;

        string result = await RunKeepDeviceFlowAsync(
            canceled,
            choice: "Cancel");
        string restoreResult = await RunKeepDeviceFlowAsync(
            restored,
            choice: "RestoreCloud");

        Assert.AreEqual("Cancelled", result);
        Assert.AreEqual(0, canceled.CloudReads);
        Assert.AreEqual(0, canceled.Uploads);
        Assert.IsNull(canceled.OwnerMarkerPlayerId);
        Assert.AreEqual(canceledLocalBefore, canceled.LocalProgress);
        Assert.AreEqual(canceledCloudBefore, canceled.CloudProgress);

        var unconfirmed = new FakeConflictOperations();
        string unconfirmedResult = await RunKeepDeviceFlowAsync(
            unconfirmed,
            explicitlyConfirmed: false);
        Assert.AreEqual("Cancelled", unconfirmedResult);
        Assert.AreEqual(0, unconfirmed.CloudReads);
        Assert.AreEqual(0, unconfirmed.Uploads);
        Assert.IsNull(unconfirmed.OwnerMarkerPlayerId);

        Assert.AreEqual("RestoreSelected", restoreResult);
        Assert.AreEqual(0, restored.CloudReads);
        Assert.AreEqual(0, restored.Uploads);
        Assert.IsNull(restored.OwnerMarkerPlayerId);
        Assert.AreEqual(restoredLocalBefore, restored.LocalProgress);
        Assert.AreEqual(restoredCloudBefore, restored.CloudProgress);
    }

    [Test]
    public async Task RestoreChoiceClearsKeepDeviceApprovalWithoutUploadingGuestSave()
    {
        var operations = new FakeConflictOperations();
        string keepResult = await RunKeepDeviceFlowAsync(operations);
        Assert.AreEqual("Completed", keepResult);
        Assert.AreEqual("google-player-a", operations.OwnerMarkerPlayerId);

        var restoreSelection = new FakeConflictOperations();
        string result = await RunKeepDeviceFlowAsync(
            restoreSelection,
            choice: "RestoreCloud");

        Assert.AreEqual("RestoreSelected", result);
        Assert.AreEqual(0, restoreSelection.Uploads);
        Assert.IsNull(restoreSelection.OwnerMarkerPlayerId);
    }

    [Test]
    public async Task InvalidLocalProgressCannotBeLinkedOrUploaded()
    {
        var operations = new FakeConflictOperations
        {
            LocalSaveValid = false
        };

        string result = await RunKeepDeviceFlowAsync(operations);

        Assert.AreEqual("OwnershipBlocked", result);
        Assert.AreEqual(0, operations.Uploads);
        Assert.IsNull(operations.OwnerMarkerPlayerId);
    }

    private static object FilesCall(string method, params object[] args) =>
        Find("SweetMerge.Cloud.SimpleCloudFiles").GetMethod(method, BindingFlags.NonPublic | BindingFlags.Static).Invoke(null,args);

    [Test] public void RestorePreservesOriginalsAndFinishesAnInterruptedPromotion()
    {
        string root=Path.GetFullPath(Path.Combine("Temp","CloudSaveTests",Guid.NewGuid().ToString("N")));
        Directory.CreateDirectory(Path.Combine(root,"CafeProfile"));
        Directory.CreateDirectory(Path.Combine(root,"TutorialProgress"));
        var value=Envelope();
        string old=(string)Get(value,"saveJson");
        string[] files={"player_save_v2.json","player_save_v2.json.bak","CafeProfile/cafe-profile-v1.json","TutorialProgress/tutorial-progress-v1.json"};
        foreach(var file in files) File.WriteAllText(Path.Combine(root,file),old);
        Set(value,"saveJson",old.Replace("\"cash\":0","\"cash\":123")); Seal(value);
        FilesCall("StageRestoreAtRoot",root,value);
        Assert.AreEqual(old,File.ReadAllText(Path.Combine(root,files[0])),"Staging must not overwrite active gameplay.");
        string recovery=Directory.GetDirectories(Path.Combine(root,"CloudRecovery")).Single();
        foreach(var file in files) Assert.AreEqual(old,File.ReadAllText(Path.Combine(recovery,file)));
        // Simulate a process exit after only the first file was promoted.
        File.WriteAllText(Path.Combine(root,files[0]),(string)Get(value,"saveJson"));
        FilesCall("ApplyPendingAtRoot",root,"player-a");
        Assert.AreEqual(Get(value,"saveJson"),File.ReadAllText(Path.Combine(root,files[0])));
        Assert.AreEqual(Get(value,"saveJson"),File.ReadAllText(Path.Combine(root,files[1])));
        StringAssert.Contains("Sunny Café",File.ReadAllText(Path.Combine(root,files[2])));
        StringAssert.Contains("\"completed\":true",File.ReadAllText(Path.Combine(root,files[3])));
        Assert.IsFalse(File.Exists(Path.Combine(root,"cloud-restore.pending.json")));
        Assert.AreEqual(1,Directory.GetFiles(root,"cloud-restore.pending.json.completed.*").Length);
        foreach(var file in files) Assert.AreEqual(old,File.ReadAllText(Path.Combine(recovery,file)));
    }

    [Test]
    public void PendingDetectionDoesNotApplyOrOverwriteActiveSave()
    {
        string root=Path.GetFullPath(Path.Combine(
            "Temp","CloudSaveTests",Guid.NewGuid().ToString("N")));
        Directory.CreateDirectory(root);
        string savePath=Path.Combine(root,"player_save_v2.json");
        const string original="existing local progress";
        File.WriteAllText(savePath,original);
        try
        {
            FilesCall("StageRestoreAtRoot",root,Envelope());

            Assert.IsTrue(
                (bool)FilesCall("RefreshPendingStateAtRoot",root));
            Assert.IsTrue(
                (bool)Find("SweetMerge.Cloud.SimpleCloudFiles")
                    .GetProperty("StartupRestorePending")
                    .GetValue(null));
            Assert.AreEqual(original,File.ReadAllText(savePath));
            Assert.IsTrue(File.Exists(
                Path.Combine(root,"cloud-restore.pending.json")));
            Assert.AreEqual(0,Directory.GetFiles(
                root,"cloud-restore.pending.json.completed.*").Length);
        }
        finally
        {
            FilesCall("ResetStateForTests");
            if (Directory.Exists(root))
                Directory.Delete(root,true);
        }
    }

    [Test]
    public void MismatchedOwnerCannotApplyPendingRestore()
    {
        string root=Path.GetFullPath(Path.Combine(
            "Temp","CloudSaveTests",Guid.NewGuid().ToString("N")));
        Directory.CreateDirectory(root);
        string savePath=Path.Combine(root,"player_save_v2.json");
        const string original="existing local progress";
        File.WriteAllText(savePath,original);
        try
        {
            FilesCall("StageRestoreAtRoot",root,Envelope());

            Assert.Throws<TargetInvocationException>(
                ()=>FilesCall("ApplyPendingAtRoot",root,"player-b"));
            Assert.AreEqual(original,File.ReadAllText(savePath));
            Assert.IsTrue(File.Exists(
                Path.Combine(root,"cloud-restore.pending.json")));
            Assert.AreEqual(0,Directory.GetFiles(
                root,"cloud-restore.pending.json.completed.*").Length);
        }
        finally
        {
            FilesCall("ResetStateForTests");
            if (Directory.Exists(root))
                Directory.Delete(root,true);
        }
    }

    [Test]
    public void ProfileAndTutorialStoresRefuseReadsAndWritesWhilePending()
    {
        string root=Path.GetFullPath(Path.Combine(
            "Temp","CloudSaveTests",Guid.NewGuid().ToString("N")));
        Directory.CreateDirectory(root);
        File.WriteAllText(
            Path.Combine(root,"cloud-restore.pending.json"),
            "pending");
        try
        {
            Assert.IsTrue(
                (bool)FilesCall("RefreshPendingStateAtRoot",root));

            object[] cafeArguments={null,null};
            object cafeStatus=Find("SweetMerge.Profile.CafeProfileLocalStore")
                .GetMethod("Load")
                .Invoke(null,cafeArguments);
            Assert.AreEqual("ServiceError",cafeStatus.ToString());

            Type tutorialType=Find("SweetMerge.Profile.TutorialProgressJournal");
            Type stageType=Find("SweetMerge.Profile.TutorialStage");
            object[] loadArguments={Enum.ToObject(stageType,0),null};
            object loadStatus=tutorialType.GetMethod("TryLoad",
                BindingFlags.NonPublic | BindingFlags.Static)
                .Invoke(null,loadArguments);
            Assert.AreEqual("ServiceError",loadStatus.ToString());

            object[] saveArguments={Enum.ToObject(stageType,1),null};
            object saveStatus=tutorialType.GetMethod("TrySave",
                BindingFlags.NonPublic | BindingFlags.Static)
                .Invoke(null,saveArguments);
            Assert.AreEqual("ServiceError",saveStatus.ToString());
        }
        finally
        {
            FilesCall("ResetStateForTests");
            if (Directory.Exists(root))
                Directory.Delete(root,true);
        }
    }

    [Test] public void InvalidRestoreDoesNotTouchExistingFiles()
    {
        string root=Path.GetFullPath(Path.Combine("Temp","CloudSaveTests",Guid.NewGuid().ToString("N")));
        Directory.CreateDirectory(root);
        string primary=Path.Combine(root,"player_save_v2.json"); File.WriteAllText(primary,"preserve me");
        var value=Envelope(); Set(value,"checksum","bad");
        Assert.Throws<TargetInvocationException>(()=>FilesCall("StageRestoreAtRoot",root,value));
        Assert.AreEqual("preserve me",File.ReadAllText(primary));
        Assert.AreEqual(1,Directory.GetFiles(root,"*",SearchOption.AllDirectories).Length);
    }

    [Test] public void CloudRestorePreservesNewAndLegacyIntroductionFlags()
    {
        Type saveType = Find("PlayerSaveData");
        MethodInfo validateCloud = Find("SaveManager").GetMethod(
            "ValidateCloudSnapshot",
            BindingFlags.Static | BindingFlags.NonPublic);
        foreach (bool legacy in new[] { true, false })
        {
            string root=Path.GetFullPath(Path.Combine(
                "Temp",
                "CloudSaveTests",
                Guid.NewGuid().ToString("N")));
            Directory.CreateDirectory(root);
            try
            {
                var value=Envelope();
                string json=(string)Get(value,"saveJson");
                if (legacy)
                {
                    foreach (string field in new[]
                    {
                        "upgradesIntroSeen",
                        "rebirthIntroSeen",
                        "collectionIntroSeen"
                    })
                        json=json.Replace(",\""+field+"\":false",string.Empty);
                }
                else
                {
                    json=json.Replace(
                        "\"upgradesIntroSeen\":false",
                        "\"upgradesIntroSeen\":true");
                    json=json.Replace(
                        "\"collectionIntroSeen\":false",
                        "\"collectionIntroSeen\":true");
                }
                Set(value,"saveJson",json);
                Seal(value);
                Assert.IsTrue(Valid(value));

                FilesCall("StageRestoreAtRoot",root,value);
                FilesCall("ApplyPendingAtRoot",root,"player-a");
                string restoredJson=File.ReadAllText(
                    Path.Combine(root,"player_save_v2.json"));
                Assert.IsTrue((bool)validateCloud.Invoke(
                    null,new object[]{restoredJson}));
                object restored=JsonUtility.FromJson(restoredJson,saveType);
                Assert.AreEqual(!legacy,Get(restored,"upgradesIntroSeen"));
                Assert.IsFalse((bool)Get(restored,"rebirthIntroSeen"));
                Assert.AreEqual(!legacy,Get(restored,"collectionIntroSeen"));
            }
            finally
            {
                if (Directory.Exists(root))
                    Directory.Delete(root,true);
            }
        }
    }
}


public sealed class CloudSyncJournalTests
{
    private string root;
    private static Type Runtime(string name) => AppDomain.CurrentDomain.GetAssemblies()
        .Select(a => a.GetType("SweetMerge.Cloud." + name)).First(t => t != null);
    private static object Call(string method, params object[] args) => Runtime("CloudSyncJournal")
        .GetMethod(method, BindingFlags.Static | BindingFlags.NonPublic).Invoke(null, args);
    private object Read(string player = "player-a", string mode = "test") => Call("Read", root, player, mode);
    private void Write(bool newGame = false) => Call("Write", root, "player-a", "test", "cloud-v1", "lock-v1", newGame);

    [SetUp]
    public void SetUp() { root = Path.Combine(Path.GetTempPath(), "CloudJournalTests", Guid.NewGuid().ToString("N")); }
    [TearDown]
    public void TearDown() { if (Directory.Exists(root)) Directory.Delete(root, true); }

    [Test]
    public void RestartWithNewEnergyTimestampUsesPersistedCommonAncestor()
    {
        Write();
        object record = Read();
        string ancestor = (string)record.GetType().GetField("acceptedHash").GetValue(record);
        object decision = Runtime("SimpleCloudBackup").GetMethod("Decide").Invoke(null,
            new object[] { "local-with-new-energy-time", "cloud-v1", ancestor });
        Assert.AreEqual(1, decision);
        Assert.AreEqual(2, Runtime("SimpleCloudBackup").GetMethod("Decide").Invoke(null,
            new object[] { "local-with-new-energy-time", "other-device-save", ancestor }));
    }

    [Test]
    public void NewGameApprovalSurvivesRestartAndIsAccountScoped()
    {
        Write(true);
        object record = Read();
        Assert.AreEqual(true, record.GetType().GetField("newGameApproved").GetValue(record));
        Assert.AreEqual("lock-v1", record.GetType().GetField("writeLock").GetValue(record));
        Assert.IsNull(Read("player-b"));
        Assert.IsNull(Read("player-a", "other-environment"));
    }

    [Test]
    public void AcceptedBackupClearsNewGameApproval()
    {
        Write(true);
        Call("Write", root, "player-a", "test", "cloud-v2", "lock-v2", false);
        object record = Read();
        Assert.AreEqual(false, record.GetType().GetField("newGameApproved").GetValue(record));
        Assert.AreEqual("cloud-v2", record.GetType().GetField("acceptedHash").GetValue(record));
    }

    [Test]
    public void InterruptedStagingDoesNotReplaceCommittedHistory()
    {
        Write();
        File.WriteAllText(Path.Combine(root, "cloud-sync-v1.json.tmp"), "interrupted");
        object record = Read();
        Assert.AreEqual("cloud-v1", record.GetType().GetField("acceptedHash").GetValue(record));
    }

    [Test]
    public void CorruptHistoryFailsClosed()
    {
        Write();
        File.WriteAllText(Path.Combine(root, "cloud-sync-v1.json"), "{}");
        var failure = Assert.Throws<TargetInvocationException>(() => Read());
        Assert.IsInstanceOf<InvalidDataException>(failure.InnerException);
    }
}
