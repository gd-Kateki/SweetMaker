using System;
using System.Linq;
using System.Reflection;
using NUnit.Framework;

public sealed class OnboardingPriorityTests
{
    private static Type Find(string name)=>AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType(name)).First(t=>t!=null);
    [TestCase(false,false,false,false)]
    [TestCase(false,false,true,true)]
    [TestCase(false,true,false,false)]
    [TestCase(false,true,true,false)]
    [TestCase(true,false,false,false)]
    [TestCase(true,false,true,false)]
    [TestCase(true,true,false,false)]
    [TestCase(true,true,true,false)]
    public void RestoreAndCloudDecisionsHavePriorityOverWelcomeAndNaming(bool restore,bool cloud,bool ready,bool expected)
    {
        var method=Find("SweetMerge.Startup.StartupIntegrationPolicy").GetMethod("CanPresentHomeOnboarding",BindingFlags.Static|BindingFlags.NonPublic);
        Assert.AreEqual(expected,method.Invoke(null,new object[]{restore,cloud,ready}));
    }
    [TestCase(false,false,false,false)]
    [TestCase(false,false,true,false)]
    [TestCase(false,true,false,false)]
    [TestCase(false,true,true,false)]
    [TestCase(true,false,false,false)]
    [TestCase(true,false,true,false)]
    [TestCase(true,true,false,true)]
    [TestCase(true,true,true,false)]
    public void AutomaticAdvertisingWaitsForTutorialCompletionAndAnUnobstructedScreen(bool ready,bool completed,bool blocked,bool expected)
    {
        var method=Find("SimpleAdManager").GetMethod("CanAutomaticallyOffer",BindingFlags.Static|BindingFlags.NonPublic);
        Assert.AreEqual(expected,method.Invoke(null,new object[]{ready,completed,blocked}));
    }
}
