using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEngine;

public sealed class PlayerPrivacyTests
{
    private static Type Find(string name) => AppDomain.CurrentDomain.GetAssemblies()
        .Select(a => a.GetType(name)).First(t => t != null);
    private static Type Privacy => Find("AdvertisingPrivacy");

    [TestCase(0, 0, false)]
    [TestCase(0, 1, false)]
    [TestCase(1, 1, false)]
    [TestCase(1, 2, false)]
    [TestCase(2, 0, false)]
    [TestCase(2, 1, true)]
    [TestCase(2, 2, false)]
    [TestCase(3, 0, false)]
    [TestCase(3, 1, true)]
    [TestCase(3, 2, true)]
    [TestCase(99, 1, false)]
    [TestCase(3, 99, false)]
    public void UnresolvedAndUnderageChoicesNeverAuthorizeAdsAndTeensNeverPersonalize(int age, int choice, bool expected)
    {
        Assert.AreEqual(expected, Privacy.GetMethod("IsEligible", BindingFlags.Static | BindingFlags.NonPublic)
            .Invoke(null, new object[] { age, choice }));
    }

    [Test]
    public void AgeChangeRevokesOldAdultConsentAndLimitedChoiceWithdrawsPersonalization()
    {
        string mode = (string)Find("SavePathPolicy").GetProperty("ModeName").GetValue(null);
        string prefix = "dmc.ads.privacy." + mode + ".";
        var saved = new Dictionary<string, int?>();
        foreach (string key in new[] { "age", "choice", "version" })
            saved[key] = PlayerPrefs.HasKey(prefix + key) ? PlayerPrefs.GetInt(prefix + key) : (int?)null;
        string timestamp = PlayerPrefs.HasKey(prefix + "updatedUtc") ? PlayerPrefs.GetString(prefix + "updatedUtc") : null;
        var ageType = Privacy.GetNestedType("AgeGroup"); var choiceType = Privacy.GetNestedType("AdChoice");
        Action<string> age = value => Privacy.GetMethod("SelectAge").Invoke(null, new[] { Enum.Parse(ageType, value) });
        Action<string> choose = value => Privacy.GetMethod("SelectChoice").Invoke(null, new[] { Enum.Parse(choiceType, value) });
        Func<string, bool> flag = name => (bool)Privacy.GetProperty(name).GetValue(null);
        try
        {
            age("Adult"); Assert.IsFalse(flag("CanRequestAds"));
            Privacy.GetMethod("DeferForSession").Invoke(null, null);
            Assert.IsTrue(flag("DeferredForSession"));
            Assert.IsFalse(flag("CanRequestAds"), "Dismissing privacy must never fabricate consent.");
            choose("Personalized"); Assert.IsTrue(flag("Personalized"));
            choose("Limited"); Assert.IsFalse(flag("Personalized")); Assert.IsTrue(flag("CanRequestAds"));
            age("Teen"); Assert.IsFalse(flag("CanRequestAds"));
            Assert.Throws<TargetInvocationException>(() => choose("Personalized"));
            choose("Limited"); Assert.IsTrue(flag("CanRequestAds")); Assert.IsFalse(flag("Personalized"));
            PlayerPrefs.SetInt(prefix + "version", -1); Assert.IsFalse(flag("CanRequestAds"));
            age("Under13"); Assert.IsFalse(flag("CanRequestAds"));
        }
        finally
        {
            foreach (var item in saved)
                if (item.Value.HasValue) PlayerPrefs.SetInt(prefix + item.Key, item.Value.Value); else PlayerPrefs.DeleteKey(prefix + item.Key);
            if (timestamp != null) PlayerPrefs.SetString(prefix + "updatedUtc", timestamp); else PlayerPrefs.DeleteKey(prefix + "updatedUtc");
            PlayerPrefs.Save();
            Privacy.GetMethod("ResetSession", BindingFlags.NonPublic | BindingFlags.Static).Invoke(null, null);
        }
    }

    [Test]
    public void DeletionRequestPreservesIdentifiersAsEscapedBodyText()
    {
        var method = Find("PlayerPrivacyUI").GetMethod("CreateDeletionEmail", BindingFlags.NonPublic | BindingFlags.Static);
        string uri = (string)method.Invoke(null, new object[] { "player&bcc=someone@example.com" });
        StringAssert.StartsWith("mailto:studiosoffcut@gmail.com?subject=", uri);
        Assert.AreEqual(1, uri.Count(c => c == '&'));
        StringAssert.Contains("player%26bcc%3Dsomeone%40example.com", uri);
        string missingId = (string)method.Invoke(null, new object[] { null });
        StringAssert.Contains("help%20locating", missingId);
    }

    [TestCase(320)]
    [TestCase(480)]
    [TestCase(720)]
    public void PrivacyAndDeletionSettingsAreAppendedAndDoNotOverlapExistingContent(float width)
    {
        var root = new GameObject("Settings test", typeof(RectTransform));
        try
        {
            var content = root.GetComponent<RectTransform>(); content.sizeDelta = new Vector2(width, 1200);
            var method = Find("PlayerPrivacyUI").GetMethod("AttachSettings");
            method.Invoke(null, new object[] { content, null });
            method.Invoke(null, new object[] { content, null });
            Assert.AreEqual(1, content.childCount, "Repeated attachment must not duplicate privacy controls.");
            Assert.AreEqual(1580, content.sizeDelta.y);
            var section = content.GetChild(0) as RectTransform;
            Assert.LessOrEqual(section.anchoredPosition.y, -1200);
            foreach (RectTransform child in section)
            {
                Assert.GreaterOrEqual(child.anchorMin.y, 0);
                Assert.LessOrEqual(child.anchorMax.y, 1);
                Assert.Greater(child.rect.width, 100);
            }
        }
        finally { UnityEngine.Object.DestroyImmediate(root); }
    }
}
