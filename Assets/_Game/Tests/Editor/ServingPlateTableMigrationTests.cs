using System;
using System.Collections;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEditor;
using UnityEngine;

public class ServingPlateTableMigrationTests
{
    [Test]
    public void ServingPlateAndTableDefinitionsUseApprovedCapacitiesAndCosts()
    {
        Type definitionType = FindRuntimeType("UpgradeDefinition");
        Assert.IsNotNull(definitionType);
        object plates = AssetDatabase.LoadAssetAtPath(
            "Assets/_Game/Data/Upgrades/Upgrade_Shelf.asset",
            definitionType);
        object tables = AssetDatabase.LoadAssetAtPath(
            "Assets/_Game/Data/Upgrades/Upgrade_Customer.asset",
            definitionType);

        Assert.IsNotNull(plates);
        Assert.IsNotNull(tables);
        Assert.AreEqual("Serving Plates", GetProperty(plates, "DisplayName"));
        Assert.AreEqual("Tables", GetProperty(tables, "DisplayName"));
        AssertUpgradeLevels(plates, new[] { 2, 3, 4, 5 }, new[] { 0, 450, 1500, 5000 });
        AssertUpgradeLevels(tables, new[] { 1, 2, 3 }, new[] { 0, 250, 1500 });
    }

    [Test]
    public void ProceduralOrdersRespectPlateCapacityAcrossDeterministicSeeds()
    {
        Type dessertDefinitionType = FindRuntimeType("DessertDefinition");
        Type generatorType = FindRuntimeType("ProceduralCustomerOrderGenerator");
        var definitionList = new System.Collections.Generic.List<UnityEngine.Object>();
        for (int tier = 1; tier <= 30; tier++)
        {
            UnityEngine.Object definition = AssetDatabase.LoadAssetAtPath(
                $"Assets/_Game/Data/Desserts/Dessert_{tier:00}.asset",
                dessertDefinitionType);
            if (definition != null)
                definitionList.Add(definition);
        }

        Assert.Greater(definitionList.Count, 0);
        Array definitions = Array.CreateInstance(
            dessertDefinitionType,
            definitionList.Count);
        for (int i = 0; i < definitionList.Count; i++)
            definitions.SetValue(definitionList[i], i);
        MethodInfo tryGenerate = generatorType.GetMethods(
                BindingFlags.Public | BindingFlags.Static)
            .Single(method =>
                method.Name == "TryGenerateForPlateCapacity" &&
                method.GetParameters().Length == 6);

        foreach (int capacity in new[] { 2, 3, 4, 5 })
        {
            bool sawSingle = false;
            bool sawMixed = false;
            bool sawSimplerThanCapacityOrder = false;
            bool sawAtCapacityOrder = false;
            bool sawThreeCopies = false;
            foreach (int seed in new[] { 1, 7, 42, 1729, 8675309 })
            {
                var random = new System.Random(seed);
                for (int orderIndex = 0; orderIndex < 200; orderIndex++)
                {
                    object[] args =
                    {
                        definitions,
                        1,
                        8,
                        capacity,
                        random,
                        null
                    };
                    Assert.IsTrue(
                        (bool)tryGenerate.Invoke(null, args),
                        $"Generation failed at capacity {capacity}, seed {seed}, order {orderIndex}.");
                    object generated = args[5];
                    string shape = GetProperty(generated, "Shape").ToString();
                    sawSingle |= shape == "Single";
                    sawMixed |= shape == "Mixed";

                    var requirements = ((IEnumerable)GetProperty(
                            generated,
                            "Requirements"))
                        .Cast<object>()
                        .ToList();
                    Assert.GreaterOrEqual(requirements.Count, 1);
                    Assert.LessOrEqual(requirements.Count, 2);
                    Assert.AreEqual(
                        requirements.Count,
                        requirements.Select(requirement =>
                                GetProperty(requirement, "Dessert"))
                            .Distinct()
                            .Count(),
                        "An order cannot repeat a dessert type as separate rows.");

                    int totalQuantity = 0;
                    foreach (object requirement in requirements)
                    {
                        int amount = (int)GetProperty(requirement, "Amount");
                        int tier = (int)GetProperty(
                            GetProperty(requirement, "Dessert"),
                            "Tier");
                        Assert.GreaterOrEqual(amount, 1);
                        Assert.LessOrEqual(
                            amount,
                            3,
                            "A dessert type cannot exceed three copies.");
                        sawThreeCopies |= amount == 3;
                        Assert.LessOrEqual(
                            tier,
                            8,
                            "Generated tiers must remain within progression unlocks.");
                        totalQuantity += amount;
                    }

                    Assert.LessOrEqual(
                        totalQuantity,
                        capacity,
                        "An order cannot exceed unlocked plate capacity.");
                    sawAtCapacityOrder |= totalQuantity == capacity;
                    if (shape == "Mixed")
                    {
                        Assert.AreEqual(2, requirements.Count);
                        if (capacity == 2)
                            Assert.AreEqual(2, totalQuantity);
                    }
                    if (totalQuantity < capacity)
                        sawSimplerThanCapacityOrder = true;
                }
            }

            Assert.IsTrue(sawSingle, $"No single order generated at capacity {capacity}.");
            Assert.IsTrue(sawMixed, $"No mixed order generated at capacity {capacity}.");
            Assert.IsTrue(
                sawAtCapacityOrder,
                $"No order used all {capacity} unlocked plates.");
            if (capacity > 2)
            {
                Assert.IsTrue(
                    sawSimplerThanCapacityOrder,
                    $"Orders at capacity {capacity} should allow simpler quantities.");
                Assert.IsTrue(
                    sawThreeCopies,
                    $"Orders at capacity {capacity} should permit three copies of a dessert type.");
            }
        }
    }

    [Test]
    public void ProceduralOrderRollsRejectCapacityOutsidePlateProgression()
    {
        Type definitionType = FindRuntimeType("DessertDefinition");
        Type generatorType = FindRuntimeType("ProceduralCustomerOrderGenerator");
        var definitionList = new System.Collections.Generic.List<UnityEngine.Object>();
        for (int tier = 1; tier <= 30; tier++)
        {
            UnityEngine.Object definition = AssetDatabase.LoadAssetAtPath(
                $"Assets/_Game/Data/Desserts/Dessert_{tier:00}.asset",
                definitionType);
            if (definition != null)
                definitionList.Add(definition);
        }
        Array definitions = Array.CreateInstance(
            definitionType,
            definitionList.Count);
        for (int i = 0; i < definitionList.Count; i++)
            definitions.SetValue(definitionList[i], i);
        MethodInfo tryGenerateFromRolls = generatorType.GetMethods(
                BindingFlags.Public | BindingFlags.Static)
            .Single(method =>
                method.Name == "TryGenerateFromRollsForPlateCapacity" &&
                method.GetParameters().Length == 9);

        foreach (int capacity in new[] { 1, 6 })
        {
            object[] args =
            {
                definitions, 1, 8, 60, 0, 0, capacity, 50, null
            };
            Assert.IsFalse((bool)tryGenerateFromRolls.Invoke(null, args));
            Assert.IsNull(args[8]);
        }
    }

    [Test]
    public void FulfillmentSelectsOnlyRequiredDessertsFromServingPlates()
    {
        Type dessertDefinitionType = FindRuntimeType("DessertDefinition");
        Type dessertType = FindRuntimeType("Dessert");
        Type slotType = FindRuntimeType("ShelfSlot");
        Type managerType = FindRuntimeType("ShelfManager");
        Type requirementType = FindRuntimeType("OrderRequirement");
        Type orderType = FindRuntimeType("CustomerOrder");
        object requiredDefinition = AssetDatabase.LoadAssetAtPath(
            "Assets/_Game/Data/Desserts/Dessert_01.asset",
            dessertDefinitionType);
        object unrelatedDefinition = AssetDatabase.LoadAssetAtPath(
            "Assets/_Game/Data/Desserts/Dessert_02.asset",
            dessertDefinitionType);
        Assert.IsNotNull(requiredDefinition);
        Assert.IsNotNull(unrelatedDefinition);

        var objects = new System.Collections.Generic.List<GameObject>();
        try
        {
            Type requirementListType = typeof(System.Collections.Generic.List<>)
                .MakeGenericType(requirementType);
            IList requirements = (IList)Activator.CreateInstance(requirementListType);
            ConstructorInfo requirementConstructor = requirementType.GetConstructor(
                new[] { dessertDefinitionType, typeof(int) });
            requirements.Add(requirementConstructor.Invoke(
                new[] { requiredDefinition, (object)2 }));
            Type requirementReadOnlyListType = typeof(System.Collections.Generic.IReadOnlyList<>)
                .MakeGenericType(requirementType);
            ConstructorInfo orderConstructor = orderType.GetConstructor(
                BindingFlags.Instance | BindingFlags.NonPublic,
                null,
                new[]
                {
                    typeof(int),
                    typeof(string),
                    typeof(int),
                    requirementReadOnlyListType
                },
                null);
            Assert.IsNotNull(orderConstructor);
            object order = orderConstructor.Invoke(
                new object[] { 1, "Two desserts", 100, requirements });

            var slots = Array.CreateInstance(slotType, 3);
            for (int i = 0; i < slots.Length; i++)
            {
                var slotObject = new GameObject("Plate " + i);
                objects.Add(slotObject);
                object slot = slotObject.AddComponent(slotType);
                slotType.GetMethod("SetUnlocked").Invoke(
                    slot,
                    new object[] { true });
                slots.SetValue(slot, i);
            }
            var managerObject = new GameObject("Serving Plate manager");
            objects.Add(managerObject);
            object manager = managerObject.AddComponent(managerType);
            SetField(manager, "slots", slots);

            object boardDessert = CreateDessert(
                objects,
                dessertType,
                requiredDefinition);
            Type cellType = FindRuntimeType("GridCell");
            var cellObject = new GameObject("Board cell");
            objects.Add(cellObject);
            object cell = cellObject.AddComponent(cellType);
            dessertType.GetMethod("SetCurrentCell").Invoke(
                boardDessert,
                new[] { cell });
            Assert.IsFalse((bool)orderType.GetMethod("CanFulfill")
                .Invoke(order, new[] { manager }),
                "A matching board dessert must not fulfill an order.");

            object firstRequired = CreateDessert(
                objects,
                dessertType,
                requiredDefinition);
            object secondRequired = CreateDessert(
                objects,
                dessertType,
                requiredDefinition);
            object unrelated = CreateDessert(
                objects,
                dessertType,
                unrelatedDefinition);
            StoreDessert(slotType, slots.GetValue(0), firstRequired);
            Assert.AreEqual(
                1,
                orderType.GetMethod("GetAvailableAmount").Invoke(
                    order,
                    new[] { manager, requiredDefinition }));
            Assert.IsFalse((bool)orderType.GetMethod("CanFulfill")
                .Invoke(order, new[] { manager }),
                "A board dessert must not supplement an incomplete plate quantity.");
            StoreDessert(slotType, slots.GetValue(1), secondRequired);
            StoreDessert(slotType, slots.GetValue(2), unrelated);

            Assert.AreEqual(
                2,
                orderType.GetMethod("GetAvailableAmount").Invoke(
                    order,
                    new[] { manager, requiredDefinition }));
            Assert.IsTrue((bool)orderType.GetMethod("CanFulfill")
                .Invoke(order, new[] { manager }));
            Type dessertListType = typeof(System.Collections.Generic.List<>)
                .MakeGenericType(dessertType);
            object[] fulfillmentArgs =
            {
                manager,
                Activator.CreateInstance(dessertListType)
            };
            Assert.IsTrue((bool)orderType.GetMethod(
                "TryGetDessertsForFulfillment").Invoke(order, fulfillmentArgs));
            IList selected = (IList)fulfillmentArgs[1];
            Assert.AreEqual(2, selected.Count);
            Assert.AreSame(firstRequired, selected[0]);
            Assert.AreSame(secondRequired, selected[1]);
            Assert.AreNotSame(selected[0], selected[1]);
            Assert.AreSame(unrelated, GetProperty(slots.GetValue(2), "CurrentDessert"));
        }
        finally
        {
            foreach (GameObject instance in objects)
                if (instance != null)
                    UnityEngine.Object.DestroyImmediate(instance);
        }
    }

    [Test]
    public void LegacyShelfCapacitiesMapOnceAndKeepIndexedContents()
    {
        int[] expectedLevels = { 1, 1, 2, 3, 4 };
        Type saveType = FindRuntimeType("PlayerSaveData");
        Type shelfDessertType = FindRuntimeType("ShelfDessertSaveData");
        MethodInfo migrate = GetMigrationMethod();

        for (int legacyLevel = 1; legacyLevel <= 5; legacyLevel++)
        {
            object save = Activator.CreateInstance(saveType);
            object progression = GetField(save, "progression");
            SetField(progression, "shelfLevel", legacyLevel);

            object gameplay = GetField(save, "mergeGameplay");
            IList contents = GetList(gameplay, "shelfDesserts");
            object savedDessert = Activator.CreateInstance(
                shelfDessertType,
                new object[] { 0, legacyLevel });
            contents.Add(savedDessert);

            object[] args = { save, 0, 0, null, null };
            Assert.IsTrue((bool)migrate.Invoke(null, args), args[4] as string);
            Assert.AreEqual(
                expectedLevels[legacyLevel - 1],
                GetField(progression, "shelfLevel"));
            Assert.AreEqual(0, (int)args[3]);
            Assert.AreSame(savedDessert, contents[0]);
            Assert.AreEqual(0, GetField(savedDessert, "slotIndex"));

            int migratedLevel = (int)GetField(progression, "shelfLevel");
            object[] secondLoad = { save, 1, 0, null, null };
            Assert.IsTrue((bool)migrate.Invoke(null, secondLoad), secondLoad[4] as string);
            Assert.AreEqual(migratedLevel, GetField(progression, "shelfLevel"));
            Assert.AreSame(savedDessert, contents[0]);
        }
    }

    [Test]
    public void LegacyFourTableMigrationPreservesFirstThreeAndCounterBeforeRetirement()
    {
        object save = Activator.CreateInstance(FindRuntimeType("PlayerSaveData"));
        object progression = GetField(save, "progression");
        SetField(progression, "customerLevel", 4);

        object gameplay = GetField(save, "mergeGameplay");
        SetField(gameplay, "hasSession", true);
        SetField(gameplay, "nextOrderId", 50);
        IList plateContents = GetList(gameplay, "shelfDesserts");
        plateContents.Add(Activator.CreateInstance(
            FindRuntimeType("ShelfDessertSaveData"),
            new object[] { 0, 2 }));

        IList savedOrders = GetList(gameplay, "customerOrders");
        Type orderSaveType = FindRuntimeType("CustomerOrderSaveData");
        for (int i = 0; i < 4; i++)
        {
            savedOrders.Add(Activator.CreateInstance(
                orderSaveType,
                new object[] { i, 20 + i, "legacy-order-" + i }));
        }

        object[] args = { save, 0, 4, null, null };
        Assert.IsTrue(
            (bool)GetMigrationMethod().Invoke(null, args),
            args[4] as string);
        Assert.AreEqual(3, GetField(progression, "customerLevel"));
        Assert.AreEqual(4, (int)args[3],
            "The four saved rows remain intact until all order definitions are runtime-validated.");
        Assert.AreEqual(4, savedOrders.Count);
        Assert.AreEqual(50, GetField(gameplay, "nextOrderId"));
        Assert.AreEqual(0, GetField(plateContents[0], "slotIndex"));
    }

    [Test]
    public void LegacyFourthTableIsRetiredOnlyAfterEveryOrderIsValid()
    {
        Type definitionType = FindRuntimeType("CustomerOrderDefinition");
        object definition = AssetDatabase.LoadAssetAtPath(
            "Assets/_Game/Data/Orders/Order_01.asset",
            definitionType);
        Assert.IsNotNull(definition);
        Assert.IsTrue((bool)GetProperty(definition, "IsValid"));

        object session = Activator.CreateInstance(FindRuntimeType("MergeSessionData"));
        SetField(session, "nextOrderId", 50);
        IList orders = GetList(session, "customerOrders");
        Type orderStateType = FindRuntimeType("CustomerOrderState");
        ConstructorInfo orderStateConstructor = orderStateType.GetConstructor(
            new[] { typeof(int), typeof(int), definitionType });
        Assert.IsNotNull(orderStateConstructor);
        for (int i = 0; i < 4; i++)
        {
            orders.Add(orderStateConstructor.Invoke(
                new object[] { i, 20 + i, definition }));
        }

        var controllerObject = new GameObject("MigrationTestController");
        try
        {
            Type controllerType = FindRuntimeType("MergeSessionController");
            UnityEngine.Component controller =
                controllerObject.AddComponent(controllerType);
            MethodInfo retire = controllerType.GetMethod(
                "TryRetireLegacyFourthTable",
                BindingFlags.Instance | BindingFlags.NonPublic);
            Assert.IsNotNull(retire);
            object[] args = { session, null };
            Assert.IsTrue((bool)retire.Invoke(controller, args), args[1] as string);
            Assert.AreEqual(3, orders.Count);
            for (int i = 0; i < 3; i++)
            {
                Assert.AreEqual(i, GetField(orders[i], "customerIndex"));
                Assert.AreEqual(20 + i, GetField(orders[i], "orderId"));
            }
            Assert.AreEqual(50, GetField(session, "nextOrderId"));

            object invalidSession = Activator.CreateInstance(
                FindRuntimeType("MergeSessionData"));
            SetField(invalidSession, "nextOrderId", 50);
            IList invalidOrders = GetList(invalidSession, "customerOrders");
            for (int i = 0; i < 3; i++)
            {
                invalidOrders.Add(orderStateConstructor.Invoke(
                    new object[] { i, 20 + i, definition }));
            }
            invalidOrders.Add(orderStateConstructor.Invoke(
                new object[] { 3, 23, null }));
            object[] invalidArgs = { invalidSession, null };
            Assert.IsFalse((bool)retire.Invoke(controller, invalidArgs));
            Assert.AreEqual(4, invalidOrders.Count,
                "Invalid legacy data must not be discarded.");
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(controllerObject);
        }
    }

    [Test]
    public void NewSnapshotsCarryMigrationMarkerWhileLegacyV2SerializationDoesNot()
    {
        MethodInfo serializer = FindRuntimeType("SaveManager").GetMethod(
            "SerializeWithServingPlateVersion",
            BindingFlags.Static | BindingFlags.NonPublic);
        Assert.IsNotNull(serializer);
        object save = Activator.CreateInstance(FindRuntimeType("PlayerSaveData"));
        string newSnapshot = (string)serializer.Invoke(
            null, new object[] { save, 0, null, 1, 1 });
        string legacySnapshot = (string)serializer.Invoke(
            null, new object[] { save, 0, null, 1, 0 });

        StringAssert.Contains("\"servingPlateProgressionVersion\":1", newSnapshot);
        StringAssert.DoesNotContain("servingPlateProgressionVersion", legacySnapshot);
    }

    private static void AssertUpgradeLevels(
        object definition,
        int[] capacities,
        int[] costs)
    {
        IEnumerable levels = (IEnumerable)GetProperty(definition, "Levels");
        Assert.AreEqual(capacities.Length, levels.Cast<object>().Count());
        MethodInfo getLevel = definition.GetType().GetMethod("GetLevel");
        for (int i = 0; i < capacities.Length; i++)
        {
            object level = getLevel.Invoke(definition, new object[] { i + 1 });
            Assert.AreEqual(i + 1, GetProperty(level, "Level"));
            Assert.AreEqual(capacities[i], GetProperty(level, "IntValue"));
            Assert.AreEqual(costs[i], GetProperty(level, "UpgradeCost"));
        }
    }

    private static MethodInfo GetMigrationMethod()
    {
        MethodInfo method = FindRuntimeType("SaveManager").GetMethod(
            "TryMigrateLegacyProgression",
            BindingFlags.Static | BindingFlags.NonPublic);
        Assert.IsNotNull(method);
        return method;
    }

    private static Type FindRuntimeType(string typeName)
    {
        return AppDomain.CurrentDomain.GetAssemblies()
            .Select(assembly => assembly.GetType(typeName, false))
            .FirstOrDefault(type => type != null);
    }

    private static object GetProperty(object target, string propertyName)
    {
        return target.GetType().GetProperty(propertyName).GetValue(target);
    }

    private static object GetField(object target, string fieldName)
    {
        return target.GetType().GetField(
            fieldName,
            BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic)
            .GetValue(target);
    }

    private static void SetField(object target, string fieldName, object value)
    {
        target.GetType().GetField(
            fieldName,
            BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic)
            .SetValue(target, value);
    }

    private static IList GetList(object target, string fieldName)
    {
        return (IList)GetField(target, fieldName);
    }

    private static object CreateDessert(
        System.Collections.Generic.ICollection<GameObject> objects,
        Type dessertType,
        object definition)
    {
        var instance = new GameObject("Test dessert");
        objects.Add(instance);
        object dessert = instance.AddComponent(dessertType);
        SetField(dessert, "definition", definition);
        return dessert;
    }

    private static void StoreDessert(
        Type slotType,
        object slot,
        object dessert)
    {
        Assert.IsTrue((bool)slotType.GetMethod("TryStoreDessert").Invoke(
            slot,
            new[] { dessert, (object)false }));
    }
}
