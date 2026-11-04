using System;
using System.IO;
using System.Reflection;
using System.Security.Cryptography;
using System.Text;
using NUnit.Framework;
using UnityEngine;

public sealed class LocalSaveOwnershipTests
{
    private sealed class FakeIdentityProvider
    {
        public string VerifiedPlayerId = "player-a";
        public string Environment = "development";
    }

    private FakeIdentityProvider identity;
    private string testDirectory;
    private string savePath;
    private string markerPath;
    private bool previousRestorePending;
    private bool previousStartupRestorePending;

    [SetUp]
    public void SetUp()
    {
        identity = new FakeIdentityProvider();
        previousRestorePending = GetStaticPropertyBackingField(
            FindRuntimeType("SweetMerge.Cloud.SimpleCloudFiles"),
            "RestorePending");
        previousStartupRestorePending = GetStaticPropertyBackingField(
            FindRuntimeType("SweetMerge.Cloud.SimpleCloudFiles"),
            "StartupRestorePending");
        SetStaticPropertyBackingField(
            FindRuntimeType("SweetMerge.Cloud.SimpleCloudFiles"),
            "RestorePending",
            false);
        SetStaticPropertyBackingField(
            FindRuntimeType("SweetMerge.Cloud.SimpleCloudFiles"),
            "StartupRestorePending",
            false);
        testDirectory = Path.Combine(
            Path.GetTempPath(),
            "SweetMakerLocalSaveOwnershipTests",
            Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(testDirectory);
        savePath = Path.Combine(testDirectory, "player_save_v2.json");
        markerPath = (string)InvokeOwnership("MarkerPath", savePath);
        File.WriteAllBytes(savePath, CreateSaveBytes(1));
    }

    [TearDown]
    public void TearDown()
    {
        SetStaticPropertyBackingField(
            FindRuntimeType("SweetMerge.Cloud.SimpleCloudFiles"),
            "RestorePending",
            previousRestorePending);
        SetStaticPropertyBackingField(
            FindRuntimeType("SweetMerge.Cloud.SimpleCloudFiles"),
            "StartupRestorePending",
            previousStartupRestorePending);
        if (Directory.Exists(testDirectory))
            Directory.Delete(testDirectory, true);
    }

    [Test]
    public void OwnershipIsBoundToExactSaveBytes()
    {
        Assert.IsTrue(Establish("player-a", "development"));
        Assert.IsTrue(IsOwnedBy("player-a", "development"));

        File.WriteAllBytes(savePath, CreateSaveBytes(2));

        Assert.IsFalse(IsOwnedBy("player-a", "development"));
    }

    [Test]
    public void CorrectPlayerAndEnvironmentValidate()
    {
        Assert.IsTrue(Establish("player-a", "development"));

        Assert.IsTrue(IsOwnedBy("player-a", "development"));
    }

    [Test]
    public void WrongPlayerIdIsRejected()
    {
        Assert.IsTrue(Establish("player-a", "development"));

        Assert.IsFalse(IsOwnedBy("player-b", "development"));
    }

    [Test]
    public void WrongEnvironmentIsRejected()
    {
        Assert.IsTrue(Establish("player-a", "development"));

        Assert.IsFalse(IsOwnedBy("player-a", "production"));
    }

    [Test]
    public void CloudUploadAuthorizationAcceptsTheVerifiedOwner()
    {
        string environment = CurrentEnvironment();
        Assert.IsTrue(Establish("player-a", environment));

        Assert.IsTrue(IsOwnedForCloudUpload(
            "player-a",
            environment,
            () => identity.VerifiedPlayerId));
    }

    [Test]
    public void CloudUploadAuthorizationRejectsMissingMarker()
    {
        Assert.IsFalse(IsOwnedForCloudUpload(
            "player-a",
            CurrentEnvironment(),
            () => identity.VerifiedPlayerId));
    }

    [Test]
    public void CloudUploadAuthorizationRejectsWrongPlayerId()
    {
        string environment = CurrentEnvironment();
        Assert.IsTrue(Establish("player-a", environment));
        identity.VerifiedPlayerId = "player-b";

        Assert.IsFalse(IsOwnedForCloudUpload(
            "player-b",
            environment,
            () => identity.VerifiedPlayerId));
    }

    [Test]
    public void CloudUploadAuthorizationRejectsChangedSaveBytes()
    {
        string environment = CurrentEnvironment();
        Assert.IsTrue(Establish("player-a", environment));
        File.WriteAllBytes(savePath, CreateSaveBytes(8));

        Assert.IsFalse(IsOwnedForCloudUpload(
            "player-a",
            environment,
            () => identity.VerifiedPlayerId));
    }

    [Test]
    public void CloudUploadAuthorizationRejectsCorruptOwnershipMarker()
    {
        string environment = CurrentEnvironment();
        Assert.IsTrue(Establish("player-a", environment));
        File.WriteAllText(markerPath, "{corrupt");

        Assert.IsFalse(IsOwnedForCloudUpload(
            "player-a",
            environment,
            () => identity.VerifiedPlayerId));
    }

    [TestCase("RestorePending")]
    [TestCase("StartupRestorePending")]
    public void CloudUploadAuthorizationRejectsPendingRestore(
        string pendingProperty)
    {
        string environment = CurrentEnvironment();
        Assert.IsTrue(Establish("player-a", environment));
        SetStaticPropertyBackingField(
            FindRuntimeType("SweetMerge.Cloud.SimpleCloudFiles"),
            pendingProperty,
            true);

        Assert.IsFalse(IsOwnedForCloudUpload(
            "player-a",
            environment,
            () => identity.VerifiedPlayerId));
    }

    [Test]
    public void CloudUploadAuthorizationRejectsUnresolvedRecoveryFiles()
    {
        string environment = CurrentEnvironment();
        Assert.IsTrue(Establish("player-a", environment));
        File.WriteAllText(savePath + ".recover.tmp", "interrupted recovery");

        Assert.IsFalse(IsOwnedForCloudUpload(
            "player-a",
            environment,
            () => identity.VerifiedPlayerId));
    }

    [Test]
    public void AccountSwitchBetweenUploadChecksBlocksAuthorization()
    {
        string environment = CurrentEnvironment();
        Assert.IsTrue(Establish("player-a", environment));
        Assert.IsTrue(IsOwnedForCloudUpload(
            "player-a",
            environment,
            () => identity.VerifiedPlayerId));

        identity.VerifiedPlayerId = "player-b";

        Assert.IsFalse(IsOwnedForCloudUpload(
            "player-a",
            environment,
            () => identity.VerifiedPlayerId));
    }

    [Test]
    public void CloudUploadAuthorizationRejectsOtherEnvironment()
    {
        string environment = CurrentEnvironment();
        Assert.IsTrue(Establish("player-a", environment));

        Assert.IsFalse(IsOwnedForCloudUpload(
            "player-a",
            environment == "development" ? "production" : "development",
            () => identity.VerifiedPlayerId));
    }

    [Test]
    public void EstablishmentRequiresTheCurrentlyVerifiedPlayer()
    {
        identity.VerifiedPlayerId = "player-b";

        Assert.IsFalse(Establish("player-a", "development"));
        Assert.IsFalse(File.Exists(markerPath));
    }

    [Test]
    public void EstablishmentRequiresRecognizedOwnershipEvidence()
    {
        object evidence = Enum.ToObject(
            FindRuntimeType(
                "SweetMerge.Cloud.LocalSaveOwnershipEvidence"),
            999);
        Assert.IsFalse((bool)InvokeOwnership(
            "TryEstablish",
            savePath,
            "player-a",
            "development",
            evidence,
            (Func<string>)(() => identity.VerifiedPlayerId),
            null));
        Assert.IsFalse(File.Exists(markerPath));
    }

    [Test]
    public void FreshGoogleNewGameRequiresVerifiedSelectionAndCommittedSnapshot()
    {
        Assert.IsTrue((bool)InvokeOwnership(
            "CanEstablishFreshGoogle",
            true,
            true,
            true,
            true,
            true,
            true,
            false));
        Assert.IsFalse((bool)InvokeOwnership(
            "CanEstablishFreshGoogle",
            false,
            true,
            true,
            true,
            true,
            true,
            false));
        Assert.IsFalse((bool)InvokeOwnership(
            "CanEstablishFreshGoogle",
            true,
            false,
            true,
            true,
            true,
            true,
            false));
        Assert.IsFalse((bool)InvokeOwnership(
            "CanEstablishFreshGoogle",
            true,
            true,
            true,
            false,
            true,
            true,
            false));
    }

    [Test]
    public void ExistingSaveOrRecoveryBlocksFreshGoogleOwnership()
    {
        string freshDirectory = Path.Combine(testDirectory, "fresh");
        Directory.CreateDirectory(freshDirectory);
        string freshSave = Path.Combine(
            freshDirectory,
            "player_save_v2.json");
        string legacySave = Path.Combine(
            freshDirectory,
            "player_save.json");

        Assert.IsTrue((bool)InvokeOwnership(
            "HasNoExistingProfileOrRecovery",
            freshSave,
            legacySave,
            null));

        File.WriteAllBytes(freshSave, CreateSaveBytes(1));
        Assert.IsFalse((bool)InvokeOwnership(
            "HasNoExistingProfileOrRecovery",
            freshSave,
            legacySave,
            null));
        File.Delete(freshSave);
        File.WriteAllBytes(freshSave + ".bak", CreateSaveBytes(2));
        Assert.IsFalse((bool)InvokeOwnership(
            "HasNoExistingProfileOrRecovery",
            freshSave,
            legacySave,
            null));
    }

    [Test]
    public void GuestLinkRequiresExplicitConsentAndUnchangedVerifiedAccount()
    {
        byte[] saveBefore = File.ReadAllBytes(savePath);
        Assert.IsTrue((bool)InvokeOwnership(
            "CanEstablishGuestLink",
            true,
            true,
            true,
            true,
            false));
        Assert.IsFalse(File.Exists(markerPath));
        CollectionAssert.AreEqual(saveBefore, File.ReadAllBytes(savePath));
        Assert.IsFalse((bool)InvokeOwnership(
            "CanEstablishGuestLink",
            false,
            true,
            true,
            true,
            false));
        Assert.IsFalse((bool)InvokeOwnership(
            "CanEstablishGuestLink",
            true,
            false,
            true,
            true,
            false));
    }

    [Test]
    public void GuestLinkAfterConsentCreatesOnlyTheLocalOwnershipMarker()
    {
        byte[] saveBefore = File.ReadAllBytes(savePath);
        Assert.IsTrue((bool)InvokeOwnership(
            "CanEstablishGuestLink",
            true,
            true,
            true,
            true,
            false));

        Assert.IsTrue(Establish(
            "player-a",
            "development",
            "ExplicitGuestLink"));

        CollectionAssert.AreEqual(saveBefore, File.ReadAllBytes(savePath));
        Assert.IsTrue(IsOwnedBy("player-a", "development"));
    }

    [Test]
    public void VerifiedRestoreRequiresSuccessfulActivationAndClearedPendingState()
    {
        Assert.IsTrue((bool)InvokeOwnership(
            "CanEstablishVerifiedRestore",
            true,
            true,
            true,
            true,
            true,
            false,
            true));
        Assert.IsFalse((bool)InvokeOwnership(
            "CanEstablishVerifiedRestore",
            true,
            true,
            true,
            false,
            true,
            false,
            true));
        Assert.IsFalse((bool)InvokeOwnership(
            "CanEstablishVerifiedRestore",
            true,
            true,
            true,
            true,
            true,
            true,
            true));
        Assert.IsFalse((bool)InvokeOwnership(
            "CanEstablishVerifiedRestore",
            true,
            true,
            true,
            true,
            true,
            false,
            false));
    }

    [Test]
    public void EstablishmentCannotReplaceAnExistingOwnershipMarker()
    {
        Assert.IsTrue(Establish("player-a", "development"));
        identity.VerifiedPlayerId = "player-b";

        Assert.IsFalse(Establish("player-b", "development"));
        Assert.IsTrue(IsOwnedBy("player-a", "development"));
        Assert.IsFalse(IsOwnedBy("player-b", "development"));
    }

    [Test]
    public void PlayerSwitchDuringOwnershipEstablishmentCancelsMarker()
    {
        int identityReads = 0;
        Func<string> changingIdentity = () =>
            ++identityReads == 1 ? "player-a" : "player-b";
        Type evidenceType = FindRuntimeType(
            "SweetMerge.Cloud.LocalSaveOwnershipEvidence");
        object evidence = Enum.Parse(
            evidenceType,
            "ExplicitGuestLink");

        Assert.IsFalse((bool)InvokeOwnership(
            "TryEstablish",
            savePath,
            "player-a",
            "development",
            evidence,
            changingIdentity,
            null));
        Assert.IsFalse(File.Exists(markerPath));
    }

    [TestCase("RestorePending")]
    [TestCase("StartupRestorePending")]
    public void PendingRestoreBlocksValidationAndEstablishment(
        string pendingProperty)
    {
        Assert.IsTrue(Establish("player-a", "development"));
        SetStaticPropertyBackingField(
            FindRuntimeType("SweetMerge.Cloud.SimpleCloudFiles"),
            pendingProperty,
            true);

        Assert.IsFalse(IsOwnedBy("player-a", "development"));
        Assert.IsFalse(Establish("player-a", "development"));
    }

    [Test]
    public void MissingOrCorruptMarkerIsUnknown()
    {
        Assert.IsFalse(IsOwnedBy("player-a", "development"));
        File.WriteAllText(markerPath, "{not-json");

        Assert.IsFalse(IsOwnedBy("player-a", "development"));
        Assert.IsFalse(Establish("player-a", "development"));
        Assert.AreEqual("{not-json", File.ReadAllText(markerPath));
    }

    [Test]
    public void NormalSaveUpdateRefreshesExistingOwnership()
    {
        Assert.IsTrue(Establish("player-a", "development"));
        bool wasOwned = IsOwnedBy("player-a", "development");
        File.WriteAllBytes(savePath, CreateSaveBytes(3));

        Assert.IsTrue(Refresh(wasOwned));
        Assert.IsTrue(IsOwnedBy("player-a", "development"));
    }

    [Test]
    public void AccountSwitchDuringSaveDoesNotTransferOwnership()
    {
        Assert.IsTrue(Establish("player-a", "development"));
        bool wasOwned = IsOwnedBy("player-a", "development");
        File.WriteAllBytes(savePath, CreateSaveBytes(7));
        identity.VerifiedPlayerId = "player-b";

        Assert.IsFalse(Refresh(wasOwned, "player-a"));
        Assert.IsFalse(IsOwnedBy("player-a", "development"));
        Assert.IsFalse(IsOwnedBy("player-b", "development"));
    }

    [Test]
    public void MarkerWriteFailureLeavesOwnershipUnknown()
    {
        Assert.IsTrue(Establish("player-a", "development"));
        bool wasOwned = IsOwnedBy("player-a", "development");
        File.Delete(markerPath);
        Directory.CreateDirectory(markerPath);
        File.WriteAllBytes(savePath, CreateSaveBytes(4));

        Assert.IsFalse(Refresh(wasOwned));
        Assert.IsFalse(IsOwnedBy("player-a", "development"));
    }

    [Test]
    public void InterruptedSaveUpdateFailsClosedOnHashMismatch()
    {
        Assert.IsTrue(Establish("player-a", "development"));
        File.WriteAllBytes(savePath, CreateSaveBytes(5));

        Assert.IsFalse(IsOwnedBy("player-a", "development"));
    }

    [Test]
    public void ReplacementInvalidationDoesNotReassignOwnership()
    {
        Assert.IsTrue(Establish("player-a", "development"));
        Assert.IsTrue(Invalidate());
        File.WriteAllBytes(savePath, CreateSaveBytes(6));

        Assert.IsFalse(IsOwnedBy("player-a", "development"));
        Assert.IsFalse(IsOwnedBy("player-b", "development"));
    }

    [Test]
    public void ResetAndDeletionInvalidateOwnership()
    {
        Assert.IsTrue(Establish("player-a", "development"));
        Assert.IsTrue(Invalidate());
        File.Delete(savePath);

        Assert.IsFalse(IsOwnedBy("player-a", "development"));
    }

    [Test]
    public void BackupRecoveryInvalidatesOwnershipBeforeReplacement()
    {
        Assert.IsTrue(Establish("player-a", "development"));
        Assert.IsTrue(Invalidate());
        File.WriteAllBytes(savePath, CreateSaveBytes(1));

        Assert.IsFalse(IsOwnedBy("player-a", "development"));
    }

    [Test]
    public void UnknownOwnershipIsNotInferredFromExistingSave()
    {
        Assert.IsTrue(File.Exists(savePath));

        Assert.IsTrue(Refresh(false));
        Assert.IsFalse(IsOwnedBy("player-a", "development"));
    }

    [Test]
    public void EstablishmentDoesNotChangeSaveV2BytesOrSchema()
    {
        byte[] saveBefore = File.ReadAllBytes(savePath);
        string saveJson = JsonUtility.ToJson(
            Activator.CreateInstance(FindRuntimeType("PlayerSaveData")));

        Assert.IsTrue(Establish("player-a", "development"));

        CollectionAssert.AreEqual(saveBefore, File.ReadAllBytes(savePath));
        StringAssert.DoesNotContain("playerId", saveJson);
        StringAssert.DoesNotContain("saveSha256", saveJson);
        Assert.IsTrue(File.Exists(markerPath));
    }

    [Test]
    public void OwnershipEstablishmentChangesNoSaveBytes()
    {
        byte[] saveBefore = File.ReadAllBytes(savePath);

        Assert.IsTrue(Establish("player-a", "development"));

        CollectionAssert.AreEqual(saveBefore, File.ReadAllBytes(savePath));
        Assert.IsFalse(File.Exists(
            Path.Combine(testDirectory, "dmc_backup_v1.json")));
    }

    [Test]
    public void MarkerStoresSha256OfExactSaveBytes()
    {
        byte[] saveBytes = File.ReadAllBytes(savePath);
        Assert.IsTrue(Establish("player-a", "development"));
        Type recordType =
            FindRuntimeType("SweetMerge.Cloud.LocalSaveOwnershipRecord");
        object record = JsonUtility.FromJson(
            File.ReadAllText(markerPath),
            recordType);
        FieldInfo hashField = recordType.GetField("saveSha256");
        FieldInfo versionField = recordType.GetField("version");
        FieldInfo environmentField = recordType.GetField("environment");
        FieldInfo playerIdField = recordType.GetField("playerId");
        string expectedHash;
        using (SHA256 algorithm = SHA256.Create())
        {
            expectedHash = Convert.ToBase64String(
                algorithm.ComputeHash(saveBytes));
        }

        Assert.AreEqual(expectedHash, hashField.GetValue(record));
        Assert.AreEqual(1, versionField.GetValue(record));
        Assert.AreEqual("development", environmentField.GetValue(record));
        Assert.AreEqual("player-a", playerIdField.GetValue(record));
    }

    private bool Establish(string playerId, string environment)
    {
        return Establish(
            playerId,
            environment,
            "FreshVerifiedGoogleNewGame");
    }

    private bool Establish(
        string playerId,
        string environment,
        string evidenceName)
    {
        Type evidenceType = FindRuntimeType(
            "SweetMerge.Cloud.LocalSaveOwnershipEvidence");
        object evidence = Enum.Parse(
            evidenceType,
            evidenceName);
        return (bool)InvokeOwnership(
            "TryEstablish",
            savePath,
            playerId,
            environment,
            evidence,
            (Func<string>)(() => identity.VerifiedPlayerId),
            null);
    }

    private static byte[] CreateSaveBytes(int cash)
    {
        Type saveType = FindRuntimeType("PlayerSaveData");
        object save = Activator.CreateInstance(saveType);
        object economy = Activator.CreateInstance(
            FindRuntimeType("EconomySaveData"),
            new object[] { cash });
        saveType.GetField("economy").SetValue(save, economy);
        MethodInfo serialize = FindRuntimeType("SaveManager").GetMethod(
            "SerializeWithCapacity",
            BindingFlags.Static | BindingFlags.NonPublic);
        Assert.IsNotNull(serialize);
        string json = (string)serialize.Invoke(
            null,
            new object[] { save, 0 });
        Assert.IsTrue((bool)FindRuntimeType("SaveManager")
            .GetMethod(
                "ValidateCloudSnapshot",
                BindingFlags.Static | BindingFlags.NonPublic)
            .Invoke(null, new object[] { json }));
        return Encoding.UTF8.GetBytes(json);
    }

    private bool IsOwnedBy(string playerId, string environment)
    {
        return (bool)InvokeOwnership(
            "IsOwnedBy",
            savePath,
            playerId,
            environment);
    }

    private bool IsOwnedForCloudUpload(
        string playerId,
        string environment,
        Func<string> getVerifiedPlayerId)
    {
        return (bool)InvokeOwnership(
            "IsOwnedByForCloudUpload",
            savePath,
            playerId,
            environment,
            getVerifiedPlayerId);
    }

    private string CurrentEnvironment()
    {
        return (string)FindRuntimeType("SavePathPolicy")
            .GetProperty("ModeName")
            .GetValue(null);
    }

    private bool Refresh(bool wasOwned, string ownerId = null)
    {
        return (bool)InvokeOwnership(
            "TryRefreshAfterSave",
            savePath,
            ownerId ?? identity.VerifiedPlayerId,
            identity.Environment,
            wasOwned,
            (Func<string>)(() => identity.VerifiedPlayerId),
            null);
    }

    private bool Invalidate()
    {
        return (bool)InvokeOwnership(
            "TryInvalidate",
            savePath,
            null);
    }

    private static object InvokeOwnership(
        string methodName,
        params object[] arguments)
    {
        Type type = FindRuntimeType("SweetMerge.Cloud.LocalSaveOwnership");
        foreach (MethodInfo method in type.GetMethods(
                     BindingFlags.Static | BindingFlags.NonPublic))
        {
            if (method.Name != methodName ||
                method.GetParameters().Length != arguments.Length)
                continue;

            var invocationArguments = new object[arguments.Length];
            Array.Copy(arguments, invocationArguments, arguments.Length);
            ParameterInfo[] parameters = method.GetParameters();
            for (int index = 0; index < parameters.Length; index++)
            {
                if (parameters[index].IsOut)
                    invocationArguments[index] = null;
            }

            return method.Invoke(null, invocationArguments);
        }

        throw new MissingMethodException(type.FullName, methodName);
    }

    private static Type FindRuntimeType(string fullName)
    {
        foreach (Assembly assembly in AppDomain.CurrentDomain.GetAssemblies())
        {
            Type type = assembly.GetType(fullName);
            if (type != null)
                return type;
        }

        throw new TypeLoadException(
            "Runtime type could not be found: " + fullName);
    }

    private static void SetStaticPropertyBackingField(
        Type type,
        string propertyName,
        bool value)
    {
        FieldInfo field = type.GetField(
            "<" + propertyName + ">k__BackingField",
            BindingFlags.Static | BindingFlags.NonPublic);
        Assert.IsNotNull(field);
        field.SetValue(null, value);
    }

    private static bool GetStaticPropertyBackingField(
        Type type,
        string propertyName)
    {
        FieldInfo field = type.GetField(
            "<" + propertyName + ">k__BackingField",
            BindingFlags.Static | BindingFlags.NonPublic);
        Assert.IsNotNull(field);
        return (bool)field.GetValue(null);
    }
}
