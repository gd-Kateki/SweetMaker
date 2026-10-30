using System;
using System.Reflection;
using NUnit.Framework;
using UnityEngine;

public sealed class EnergyCapacityTests
{
    private GameObject progressionObject;
    private Component progression;

    [SetUp]
    public void SetUp()
    {
        progressionObject = new GameObject("Energy capacity test");
        progressionObject.SetActive(false);
        progression = progressionObject.AddComponent(
            FindType("PlayerProgressionManager"));
        progressionObject.SetActive(true);

        SetPrivateStaticProperty(
            FindType("PlayerProgressionManager"),
            "Instance",
            progression);
    }

    [TearDown]
    public void TearDown()
    {
        SetPrivateStaticProperty(
            FindType("PlayerProgressionManager"),
            "Instance",
            null);

        if (progressionObject != null)
            UnityEngine.Object.DestroyImmediate(progressionObject);
    }

    [Test]
    public void NewPlayerInitializesAt100Energy()
    {
        Assert.AreEqual(100, GetMaximumEnergy());
        Assert.AreEqual(100, GetCurrentEnergy());
        Assert.AreEqual(0f, GetSecondsUntilNextEnergy(), 0.001f);
    }

    [TestCase(0)]
    [TestCase(15)]
    [TestCase(30)]
    [TestCase(99)]
    [TestCase(100)]
    public void RestoreEnergyAcceptsSupportedBalances(int energy)
    {
        long savedTicks = DateTime.UtcNow.Ticks;
        int countdown = energy == 100 ? 0 : 60000;

        Assert.IsTrue(RestoreEnergy(energy, countdown, savedTicks));
        Assert.AreEqual(energy, GetCurrentEnergy());
    }

    [Test]
    public void RestoreEnergyRejectsBalancesOutsideRange()
    {
        long savedTicks = DateTime.UtcNow.Ticks;
        Assert.IsFalse(RestoreEnergy(-1, 60000, savedTicks));
        Assert.IsFalse(RestoreEnergy(101, 60000, savedTicks));
    }

    [Test]
    public void RegenerationAt99StopsAt100()
    {
        Assert.IsTrue(RestoreEnergy(
            99,
            60000,
            DateTime.UtcNow.AddSeconds(-60).Ticks));

        Assert.AreEqual(100, GetCurrentEnergy());
        Assert.AreEqual(0f, GetSecondsUntilNextEnergy(), 0.001f);
    }

    [Test]
    public void FullCapacityUsesZeroCountdown()
    {
        Assert.IsTrue(RestoreEnergy(
            100,
            0,
            DateTime.UtcNow.Ticks));

        Assert.AreEqual(0f, GetSecondsUntilNextEnergy(), 0.001f);
        MethodInfo observe = progression.GetType().GetMethod(
            "TryObserveFrozenEnergyMetadata",
            BindingFlags.Instance | BindingFlags.NonPublic);
        var observeArguments = new object[] { null };
        Assert.IsTrue((bool)observe.Invoke(
            progression,
            observeArguments));
        object metadata = observeArguments[0];
        Assert.AreEqual(100, GetProperty(metadata, "CurrentEnergy"));
        Assert.AreEqual(0, GetProperty(metadata, "MillisecondsUntilNextPoint"));
    }

    [Test]
    public void OfflineRegenerationUsesSavedUtcTimestamp()
    {
        Assert.IsTrue(RestoreEnergy(
            99,
            60000,
            DateTime.UtcNow.AddSeconds(-60).Ticks));

        Assert.AreEqual(100, GetCurrentEnergy());
    }

    [Test]
    public void ConsumptionAtAvailableAndZeroEnergyPreservesOnePointRules()
    {
        Assert.IsTrue(RestoreEnergy(1, 60000, DateTime.UtcNow.Ticks));
        Assert.IsTrue(TryConsumeEnergy());
        Assert.AreEqual(0, GetCurrentEnergy());

        Assert.IsFalse(TryConsumeEnergy());
        Assert.AreEqual(0, GetCurrentEnergy());
    }

    [TestCase(-1)]
    [TestCase(101)]
    public void SaveV2ValidationRejectsOutOfRangeEnergy(int energy)
    {
        Assert.IsFalse(TryParseEnergyMetadata(
            energy,
            60000,
            DateTime.UtcNow.Ticks));
    }

    [TestCase(0)]
    [TestCase(15)]
    [TestCase(30)]
    [TestCase(99)]
    [TestCase(100)]
    public void SaveV2ValidationAcceptsSupportedEnergyRoundTrips(int energy)
    {
        int countdown = energy == 100 ? 0 : 60000;
        Assert.IsTrue(TryParseEnergyMetadata(
            energy,
            countdown,
            DateTime.UtcNow.Ticks));
    }

    [Test]
    public void LegacyThirtyZeroNormalizesInMemoryAndPreservesUtc()
    {
        long savedTicks = DateTime.UtcNow.AddMinutes(-2).Ticks;
        MethodInfo parse = FindType("SaveManager").GetMethod(
            "TryParseEnergyMetadata",
            BindingFlags.Static | BindingFlags.NonPublic);
        var arguments = new object[]
        {
            "{\"currentEnergy\":30," +
            "\"energyMillisecondsUntilNextPoint\":0," +
            "\"energySavedUtcTicks\":" + savedTicks + "}",
            null,
            false
        };

        Assert.IsTrue((bool)parse.Invoke(null, arguments));
        Assert.IsTrue((bool)arguments[2]);
        object metadata = arguments[1];
        Assert.IsNotNull(metadata);
        Assert.AreEqual(30, GetProperty(metadata, "currentEnergy"));
        Assert.AreEqual(
            60000,
            GetProperty(metadata, "energyMillisecondsUntilNextPoint"));
        Assert.AreEqual(
            savedTicks,
            GetProperty(metadata, "energySavedUtcTicks"));
    }

    [TestCase(31, 0)]
    [TestCase(99, 0)]
    [TestCase(100, 60000)]
    public void SaveV2ValidationRejectsMalformedLegacyCountdownStates(
        int energy,
        int countdown)
    {
        Assert.IsFalse(TryParseEnergyMetadata(
            energy,
            countdown,
            DateTime.UtcNow.Ticks));
    }

    [Test]
    public void LegacyThirtyZeroDoesNotRefillAndPreservesOfflineRegeneration()
    {
        long savedTicks = DateTime.UtcNow.AddSeconds(-60).Ticks;
        Assert.IsTrue(RestoreEnergy(30, 60000, savedTicks));
        Assert.AreEqual(31, GetCurrentEnergy());

        Assert.IsFalse(RestoreEnergy(101, 60000, savedTicks));
    }

    [Test]
    public void SaveV2ValidationRejectsInvalidUtcTimestamps()
    {
        Assert.IsFalse(TryParseEnergyMetadata(30, 60000, 0));
        Assert.IsFalse(TryParseEnergyMetadata(
            30,
            60000,
            long.MaxValue));
    }

    [Test]
    public void SaveV2WithoutEnergyMetadataRemainsRecognizedAsLegacy()
    {
        MethodInfo parse = FindType("SaveManager").GetMethod(
            "TryParseEnergyMetadata",
            BindingFlags.Static | BindingFlags.NonPublic);
        var arguments = new object[]
        {
            "{}",
            null,
            false
        };

        Assert.IsTrue((bool)parse.Invoke(null, arguments));
        Assert.IsFalse((bool)arguments[2]);
        Assert.IsNull(arguments[1]);
    }

    private int GetMaximumEnergy()
    {
        return (int)progression.GetType()
            .GetProperty("MaximumEnergy")
            .GetValue(progression);
    }

    private int GetCurrentEnergy()
    {
        return (int)progression.GetType()
            .GetProperty("CurrentEnergy")
            .GetValue(progression);
    }

    private float GetSecondsUntilNextEnergy()
    {
        return (float)progression.GetType()
            .GetProperty("SecondsUntilNextEnergy")
            .GetValue(progression);
    }

    private bool RestoreEnergy(
        int energy,
        int millisecondsUntilNextEnergy,
        long savedUtcTicks)
    {
        return (bool)progression.GetType().GetMethod(
                "RestoreEnergy",
                BindingFlags.Instance | BindingFlags.NonPublic)
            .Invoke(progression, new object[]
            {
                energy,
                millisecondsUntilNextEnergy,
                savedUtcTicks
            });
    }

    private bool TryConsumeEnergy()
    {
        return (bool)progression.GetType().GetMethod(
                "TryConsumeEnergy",
                BindingFlags.Instance | BindingFlags.Public)
            .Invoke(progression, null);
    }

    private bool TryParseEnergyMetadata(
        int energy,
        int countdown,
        long savedUtcTicks)
    {
        MethodInfo parse = FindType("SaveManager").GetMethod(
            "TryParseEnergyMetadata",
            BindingFlags.Static | BindingFlags.NonPublic);
        var arguments = new object[]
        {
            "{\"currentEnergy\":" + energy + "," +
            "\"energyMillisecondsUntilNextPoint\":" + countdown + "," +
            "\"energySavedUtcTicks\":" + savedUtcTicks + "}",
            null,
            false
        };

        return (bool)parse.Invoke(null, arguments);
    }

    private static object GetProperty(object target, string propertyName)
    {
        Type targetType = target.GetType();
        PropertyInfo property = targetType.GetProperty(propertyName);
        if (property != null)
            return property.GetValue(target);

        FieldInfo field = targetType.GetField(
            propertyName,
            BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
        if (field != null)
            return field.GetValue(target);

        Assert.Fail("Could not find property or field '" + propertyName + "'.");
        return null;
    }

    private static Type FindType(string typeName)
    {
        foreach (Assembly assembly in AppDomain.CurrentDomain.GetAssemblies())
        {
            Type type = assembly.GetType(typeName, false);
            if (type != null)
                return type;
        }

        Assert.Fail("Could not find runtime type " + typeName);
        return null;
    }

    private static void SetPrivateStaticProperty(
        Type type,
        string propertyName,
        object value)
    {
        PropertyInfo property = type.GetProperty(
            propertyName,
            BindingFlags.Static | BindingFlags.Public | BindingFlags.NonPublic);
        property.GetSetMethod(true).Invoke(null, new[] { value });
    }
}
