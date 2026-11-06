using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEngine;

public sealed class CafeLeaderboardsTests
{
    private static Type Find(string name) => AppDomain.CurrentDomain.GetAssemblies()
        .Select(assembly => assembly.GetType(name)).First(type => type != null);
    private static Type Service => Find("SweetMerge.Cloud.CafeLeaderboards");

    [TestCase("LeaderboardNotFound", "not configured")]
    [TestCase("Unauthorized", "access was denied")]
    [TestCase("ScoreSubmissionRequired", "requires a saved score")]
    [TestCase("NoInternetConnection", "No connection")]
    public void ReadFailuresIdentifyServiceReasonWithoutExposingServerMessage(string reason, string expected)
    {
        Type failureType = Find("Unity.Services.Leaderboards.Exceptions.LeaderboardsException");
        Type reasonType = Find("Unity.Services.Leaderboards.Exceptions.LeaderboardsExceptionReason");
        var failure = (Exception)Activator.CreateInstance(failureType,
            BindingFlags.Instance | BindingFlags.NonPublic, null,
            new object[] { Enum.Parse(reasonType, reason), 27000, "private server details", null }, null);
        string message = (string)Service.GetMethod("ReadFailureMessage").Invoke(null, new object[] { failure });
        StringAssert.Contains(expected, message);
        StringAssert.Contains(reason, message);
        StringAssert.Contains("27000", message);
        StringAssert.DoesNotContain("private server details", message);
    }

    [Test]
    public void ClientRequestContainsOnlyTheAcknowledgedBackupChecksum()
    {
        string checksum = Convert.ToBase64String(new byte[32]);
        var result = (Dictionary<string, object>)Service.GetMethod("CreateSyncParameters",
            BindingFlags.NonPublic | BindingFlags.Static).Invoke(null,
            new object[] { checksum });
        Assert.AreEqual(1, result.Count);
        Assert.AreEqual(checksum, result["checksum"]);
    }

    [TestCase(null)]
    [TestCase("")]
    [TestCase("not-a-checksum")]
    public void InvalidBackupChecksumCannotBeSubmitted(string checksum)
    {
        var failure = Assert.Throws<TargetInvocationException>(() => Service.GetMethod("CreateSyncParameters",
            BindingFlags.NonPublic | BindingFlags.Static).Invoke(null, new object[] { checksum }));
        Assert.IsInstanceOf<ArgumentException>(failure.InnerException);
    }

    [TestCase(1, 30)]
    [TestCase(2, 60)]
    [TestCase(3, 120)]
    [TestCase(4, 240)]
    [TestCase(5, 300)]
    [TestCase(100, 300)]
    public void ServiceFailuresBackOffAndCapAtFiveMinutes(int attempts, double expected)
    {
        Assert.AreEqual(expected, Service.GetMethod("RetryDelay", BindingFlags.NonPublic | BindingFlags.Static)
            .Invoke(null, new object[] { attempts }));
    }

    [TestCase(320)]
    [TestCase(480)]
    [TestCase(720)]
    public void CategoryButtonsStayInsideNarrowScreensWithoutOverlapping(float width)
    {
        var parent = new GameObject("Layout test", typeof(RectTransform));
        try
        {
            parent.GetComponent<RectTransform>().sizeDelta = new Vector2(width, 1280);
            var method = Find("CafeLeaderboardUI").GetMethod("TopColumn", BindingFlags.Static | BindingFlags.NonPublic);
            var left = new GameObject("Left", typeof(RectTransform)).GetComponent<RectTransform>();
            var right = new GameObject("Right", typeof(RectTransform)).GetComponent<RectTransform>();
            left.SetParent(parent.transform, false); right.SetParent(parent.transform, false);
            method.Invoke(null, new object[] { left, 0f, 0.5f, 100f, 68f });
            method.Invoke(null, new object[] { right, 0.5f, 1f, 100f, 68f });
            var a = new Vector3[4]; var b = new Vector3[4];
            left.GetWorldCorners(a); right.GetWorldCorners(b);
            Assert.Greater(left.rect.width, 100);
            Assert.Greater(right.rect.width, 100);
            Assert.Less(a[2].x, b[0].x);
            Assert.GreaterOrEqual(a[0].x, -width / 2);
            Assert.LessOrEqual(b[2].x, width / 2);
        }
        finally { UnityEngine.Object.DestroyImmediate(parent); }
    }

    [TestCase(null)]
    [TestCase("")]
    [TestCase("not-json")]
    [TestCase("{}")]
    [TestCase("{\"cafeName\":\"Cafe\",\"rebirth\":-1}")]
    [TestCase("{\"cafeName\":\"Cafe\\nspoof\",\"rebirth\":1}")]
    public void MissingOrMalformedRemoteMetadataHasSafeFallback(string json)
    {
        Assert.IsNull(Service.GetMethod("ParseMetadata").Invoke(null, new object[] { json }));
    }

    [TestCase("total_money_earned")]
    [TestCase("total_orders_completed")]
    public void DeploymentAssetsDeserializeUsingUnitySdk(string id)
    {
        Type configType = Find("Unity.Services.Leaderboards.Editor.Authoring.Model.EditorLeaderboardConfig");
        object config = Activator.CreateInstance(configType, new object[] { id });
        configType.GetProperty("Path").SetValue(config, "Assets/_Game/Leaderboards/" + id + ".lb");
        Type serializerType = Find("Unity.Services.Leaderboards.Editor.Authoring.Model.LeaderboardsSerializer");
        object serializer = Activator.CreateInstance(serializerType);
        serializerType.GetMethod("DeserializeAndPopulate").Invoke(serializer, new[] { config });
        Assert.AreEqual(id, configType.GetProperty("Id").GetValue(config));
        Assert.AreEqual("Desc", configType.GetProperty("SortOrder").GetValue(config).ToString());
        Assert.AreEqual("KeepLatest", configType.GetProperty("UpdateType").GetValue(config).ToString());
        var states = (IEnumerable)configType.GetProperty("States").GetValue(config);
        Assert.AreEqual(0, states.Cast<object>().Count(), "SDK reported deployment configuration errors.");
    }
}
