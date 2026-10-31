using System;
using System.Linq;
using System.IO;
using System.Reflection;
using NUnit.Framework;
using UnityEngine;

public sealed class SimpleCloudBackupTests
{
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

    private static void FilesCall(string method, params object[] args) =>
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
        FilesCall("ApplyPendingAtRoot",root);
        Assert.AreEqual(Get(value,"saveJson"),File.ReadAllText(Path.Combine(root,files[0])));
        Assert.AreEqual(Get(value,"saveJson"),File.ReadAllText(Path.Combine(root,files[1])));
        StringAssert.Contains("Sunny Café",File.ReadAllText(Path.Combine(root,files[2])));
        StringAssert.Contains("\"completed\":true",File.ReadAllText(Path.Combine(root,files[3])));
        Assert.IsFalse(File.Exists(Path.Combine(root,"cloud-restore.pending.json")));
        Assert.AreEqual(1,Directory.GetFiles(root,"cloud-restore.pending.json.completed.*").Length);
        foreach(var file in files) Assert.AreEqual(old,File.ReadAllText(Path.Combine(recovery,file)));
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
}
