using System;
using System.Collections;
using System.Collections.Generic;
using System.Reflection;
using NUnit.Framework;
using UnityEngine;
using UnityEngine.TestTools;

public sealed class RecycleConfirmationLifecyclePlayModeTests
{
    private const BindingFlags InstanceMembers =
        BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic;
    private const BindingFlags StaticMembers =
        BindingFlags.Static | BindingFlags.Public | BindingFlags.NonPublic;

    private readonly List<GameObject> objects = new List<GameObject>();
    private object previousSettingsManager;
    private PropertyInfo settingsInstance;

    [SetUp]
    public void SetUp()
    {
        settingsInstance = GetRequiredType("SettingsManager").GetProperty(
            "Instance",
            StaticMembers);
        Assert.IsNotNull(settingsInstance, "SettingsManager.Instance is missing.");
        previousSettingsManager = settingsInstance.GetValue(null, null);
        AssertModalStateClear();
        Assert.IsFalse(
            IsGameplayInputBlocked(),
            "Recycle lifecycle tests require an unblocked gameplay input gate.");
    }

    [UnityTearDown]
    public IEnumerator TearDown()
    {
        foreach (GameObject gameObject in objects)
        {
            if (gameObject == null)
                continue;

            foreach (Behaviour behaviour in gameObject.GetComponents<Behaviour>())
            {
                if (behaviour != null && behaviour.enabled)
                    behaviour.enabled = false;
            }
        }

        for (int i = objects.Count - 1; i >= 0; i--)
        {
            if (objects[i] != null)
                UnityEngine.Object.Destroy(objects[i]);
        }
        objects.Clear();

        yield return null;

        AssertModalStateClear();
        Assert.IsFalse(
            IsGameplayInputBlocked(),
            "Recycle lifecycle test teardown left gameplay input blocked.");
        Assert.AreSame(
            previousSettingsManager,
            settingsInstance.GetValue(null, null),
            "Recycle lifecycle tests must not replace SettingsManager.Instance.");
    }

    [UnityTest]
    public IEnumerator ControllerDisableCancelsPendingRecycleAndReleasesBothLeases()
    {
        Component cell = CreateBoardCell();
        Component dessert = CreateDessert();
        PlaceDessert(cell, dessert);
        Component dragHandler =
            dessert.GetComponent(GetRequiredType("DessertDragHandler"));
        SetField(dragHandler, "isPendingRecycleConfirmation", true);
        Component controller = CreateController(out GameObject overlayRoot);

        Assert.IsTrue(BeginPendingRecycle(
            controller,
            dragHandler,
            dessert,
            cell));
        Assert.That(controller, Is.InstanceOf<Behaviour>());
        Assert.IsTrue(((Behaviour)controller).isActiveAndEnabled);
        Assert.IsTrue(controller.gameObject.activeInHierarchy);
        Assert.IsTrue(overlayRoot.activeSelf);
        Assert.IsTrue(IsGameplayInputBlocked());
        Assert.IsTrue(IsReservedBy(controller));

        ((Behaviour)controller).enabled = false;
        yield return null;

        Assert.IsFalse(((Behaviour)controller).enabled);
        Assert.AreSame(dessert, GetProperty(cell, "CurrentDessert"));
        Assert.AreSame(cell, GetProperty(dessert, "CurrentCell"));
        Assert.IsFalse(overlayRoot.activeSelf);
        Assert.IsFalse((bool)GetField(dragHandler, "isPendingRecycleConfirmation"));
        Assert.IsFalse((bool)GetProperty(controller, "IsOpenOrWaiting"));
        AssertModalStateClear();
        Assert.IsFalse(IsGameplayInputBlocked());
        Assert.IsFalse(IsReservedBy(controller));

        AssertSubsequentInteractionIsAdmitted(controller);
    }

    [UnityTest]
    public IEnumerator DragHandlerDisableCancelsItsPendingRecycle()
    {
        Component cell = CreateBoardCell();
        Component dessert = CreateDessert();
        PlaceDessert(cell, dessert);
        Component dragHandler =
            dessert.GetComponent(GetRequiredType("DessertDragHandler"));
        SetField(dragHandler, "isPendingRecycleConfirmation", true);
        Component controller = CreateController(out GameObject overlayRoot);
        SetField(dragHandler, "recycleConfirmationController", controller);

        Assert.IsTrue(BeginPendingRecycle(
            controller,
            dragHandler,
            dessert,
            cell));
        Assert.That(dragHandler, Is.InstanceOf<Behaviour>());
        Assert.IsTrue(((Behaviour)dragHandler).isActiveAndEnabled);
        Assert.IsTrue(dragHandler.gameObject.activeInHierarchy);
        Assert.IsTrue(overlayRoot.activeSelf);
        Assert.IsTrue(IsGameplayInputBlocked());
        Assert.IsTrue(IsReservedBy(controller));

        ((Behaviour)dragHandler).enabled = false;
        yield return null;

        Assert.IsFalse(((Behaviour)dragHandler).enabled);
        Assert.AreSame(dessert, GetProperty(cell, "CurrentDessert"));
        Assert.AreSame(cell, GetProperty(dessert, "CurrentCell"));
        Assert.IsFalse(overlayRoot.activeSelf);
        Assert.IsFalse((bool)GetField(dragHandler, "isPendingRecycleConfirmation"));
        Assert.IsFalse((bool)GetProperty(controller, "IsOpenOrWaiting"));
        AssertModalStateClear();
        Assert.IsFalse(IsGameplayInputBlocked());
        Assert.IsFalse(IsReservedBy(controller));

        AssertSubsequentInteractionIsAdmitted(controller);
    }

    private void AssertSubsequentInteractionIsAdmitted(Component disabledController)
    {
        Type gateType = GetRequiredType("GameplayModalInputGate");
        MethodInfo beginOperation = gateType.GetMethod(
            "TryBeginGameplayOperation",
            StaticMembers);
        Assert.IsNotNull(beginOperation);
        object[] operationArguments = { null };
        Assert.IsTrue(
            (bool)InvokeMethod(beginOperation, null, operationArguments),
            "Gameplay operations should be admitted after recycle cancellation.");
        Assert.IsNotNull(operationArguments[0]);
        try
        {
            Component nextModal = CreateController(out _);
            Assert.IsTrue(
                TryReserve(nextModal),
                "A subsequent modal should be admitted after recycle cancellation.");
            Release(nextModal);
        }
        finally
        {
            Invoke(operationArguments[0], "Dispose", Type.EmptyTypes);
        }

        AssertModalStateClear();
        Assert.IsFalse(IsReservedBy(disabledController));
    }

    private static void AssertModalStateClear()
    {
        IDictionary leases = (IDictionary)GetStaticField(
            GetRequiredType("GameplayModalInputGate"),
            "ModalLeases");
        Assert.AreEqual(0, leases.Count, "A gameplay modal lease remains active.");
        Assert.AreEqual(
            0,
            GetStaticField(
                GetRequiredType("GameplayModalInputGate"),
                "activeGameplayOperations"),
            "A gameplay operation lease remains active.");
        Assert.IsNull(
            GetStaticField(
                GetRequiredType("GameplayModalAdmission"),
                "activeOwner"),
            "Gameplay modal admission remains reserved.");
    }

    private Component CreateBoardCell()
    {
        return Track(new GameObject("Recycle lifecycle board cell"))
            .AddComponent(GetRequiredType("GridCell"));
    }

    private Component CreateDessert()
    {
        GameObject gameObject = Track(new GameObject("Recycle lifecycle dessert"));
        Component dessert = gameObject.AddComponent(GetRequiredType("Dessert"));
        gameObject.AddComponent(GetRequiredType("DessertDragHandler"));
        return dessert;
    }

    private Component CreateController(out GameObject overlayRoot)
    {
        GameObject controllerObject =
            Track(new GameObject("Recycle lifecycle controller"));
        overlayRoot = Track(new GameObject("Recycle lifecycle overlay"));
        overlayRoot.transform.SetParent(controllerObject.transform);
        overlayRoot.SetActive(false);

        Component controller = controllerObject.AddComponent(
            GetRequiredType("RecycleConfirmationController"));
        SetField(controller, "overlayRoot", overlayRoot);
        return controller;
    }

    private GameObject Track(GameObject gameObject)
    {
        objects.Add(gameObject);
        return gameObject;
    }

    private static bool BeginPendingRecycle(
        Component controller,
        Component dragHandler,
        Component dessert,
        Component cell)
    {
        return (bool)Invoke(
            controller,
            "TryBeginPendingRecycle",
            new[]
            {
                GetRequiredType("DessertDragHandler"),
                GetRequiredType("Dessert"),
                GetRequiredType("GridCell"),
                GetRequiredType("ShelfSlot")
            },
            dragHandler,
            dessert,
            cell,
            null);
    }

    private static void PlaceDessert(Component cell, Component dessert)
    {
        Invoke(
            cell,
            "PlaceDessert",
            new[] { GetRequiredType("Dessert"), typeof(bool) },
            dessert,
            true);
    }

    private static bool TryReserve(Component owner)
    {
        return (bool)InvokeStatic(
            GetRequiredType("GameplayModalAdmission"),
            "TryReserve",
            new[] { typeof(MonoBehaviour) },
            owner);
    }

    private static bool IsReservedBy(Component owner)
    {
        return (bool)InvokeStatic(
            GetRequiredType("GameplayModalAdmission"),
            "IsReservedBy",
            new[] { typeof(MonoBehaviour) },
            owner);
    }

    private static void Release(Component owner)
    {
        InvokeStatic(
            GetRequiredType("GameplayModalAdmission"),
            "Release",
            new[] { typeof(MonoBehaviour) },
            owner);
    }

    private static bool IsGameplayInputBlocked()
    {
        return (bool)GetStaticProperty(
            GetRequiredType("GameplayModalInputGate"),
            "IsGameplayInputBlocked");
    }

    private static object GetStaticProperty(Type type, string propertyName)
    {
        PropertyInfo property = type.GetProperty(propertyName, StaticMembers);
        Assert.IsNotNull(property, $"Missing property {type.FullName}.{propertyName}.");
        return property.GetValue(null, null);
    }

    private static object GetStaticField(Type type, string fieldName)
    {
        FieldInfo field = type.GetField(fieldName, StaticMembers);
        Assert.IsNotNull(field, $"Missing field {type.FullName}.{fieldName}.");
        return field.GetValue(null);
    }

    private static Type GetRequiredType(string typeName)
    {
        foreach (Assembly assembly in AppDomain.CurrentDomain.GetAssemblies())
        {
            if (assembly.GetName().Name != "Assembly-CSharp")
                continue;

            Type found = assembly.GetType(typeName, false);
            if (found != null)
                return found;
        }

        Assert.Fail(
            $"Required runtime type '{typeName}' was not found in Assembly-CSharp.");
        return null;
    }

    private static object InvokeStatic(
        Type type,
        string methodName,
        Type[] parameterTypes,
        params object[] arguments)
    {
        MethodInfo method = type.GetMethod(
            methodName,
            StaticMembers,
            null,
            parameterTypes,
            null);
        Assert.IsNotNull(method, $"Missing method {type.FullName}.{methodName}.");
        return InvokeMethod(method, null, arguments);
    }

    private static object Invoke(
        object target,
        string methodName,
        Type[] parameterTypes,
        params object[] arguments)
    {
        Assert.IsNotNull(target, $"Cannot invoke {methodName} on a null target.");
        MethodInfo method = target.GetType().GetMethod(
            methodName,
            InstanceMembers,
            null,
            parameterTypes,
            null);
        Assert.IsNotNull(
            method,
            $"Missing method {target.GetType().FullName}.{methodName}.");
        return InvokeMethod(method, target, arguments);
    }

    private static object InvokeMethod(
        MethodInfo method,
        object target,
        object[] arguments)
    {
        try
        {
            return method.Invoke(target, arguments);
        }
        catch (TargetInvocationException exception)
        {
            if (exception.InnerException != null)
                System.Runtime.ExceptionServices.ExceptionDispatchInfo
                    .Capture(exception.InnerException)
                    .Throw();
            throw;
        }
    }

    private static object GetProperty(object target, string propertyName)
    {
        PropertyInfo property = target.GetType().GetProperty(
            propertyName,
            InstanceMembers);
        Assert.IsNotNull(
            property,
            $"Missing property {target.GetType().FullName}.{propertyName}.");
        return property.GetValue(target, null);
    }

    private static object GetField(object target, string fieldName)
    {
        FieldInfo field = target.GetType().GetField(fieldName, InstanceMembers);
        Assert.IsNotNull(
            field,
            $"Missing field {target.GetType().FullName}.{fieldName}.");
        return field.GetValue(target);
    }

    private static void SetField(object target, string fieldName, object value)
    {
        FieldInfo field = target.GetType().GetField(fieldName, InstanceMembers);
        Assert.IsNotNull(
            field,
            $"Missing field {target.GetType().FullName}.{fieldName}.");
        field.SetValue(target, value);
    }
}
