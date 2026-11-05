using System;
using System.Linq;
using System.Reflection;
using NUnit.Framework;

public sealed class SimpleAdsTests
{
    private static Type Manager => AppDomain.CurrentDomain.GetAssemblies().Select(a => a.GetType("SimpleAdManager")).First(t => t != null);
    [TestCase(0L, 0, 1f, 100, 100)]
    [TestCase(900L, 3, 1f, 100, 300)]
    [TestCase(900L, 3, 2f, 100, 600)]
    [TestCase(60L, 3, 1f, 100, 100)]
    [TestCase(6000000L, 1, 2f, 100, 1000000)]
    public void CashOfferScalesWithOrdersAndMultiplier(long total, int count, float multiplier, int minimum, int expected)
    {
        Assert.AreEqual(expected, Manager.GetMethod("CalculateCashReward", BindingFlags.Static | BindingFlags.NonPublic)
            .Invoke(null, new object[] { total, count, multiplier, minimum }));
    }
    [Test]
    public void EachAdRewardCanBeClaimedOnlyOnce()
    {
        var type = Manager.GetNestedType("RewardTicket", BindingFlags.NonPublic);
        var ticket = Activator.CreateInstance(type, BindingFlags.Instance | BindingFlags.NonPublic, null, new object[] { true, 50 }, null);
        var claim = type.GetMethod("TryClaim", BindingFlags.Instance | BindingFlags.NonPublic);
        Assert.AreEqual(true, claim.Invoke(ticket, null));
        Assert.AreEqual(false, claim.Invoke(ticket, null));
    }
}
