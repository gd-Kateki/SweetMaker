using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEngine;

public sealed class GameplayModalGateTestOwner : MonoBehaviour
{
}

public sealed class GameplayModalInputGateTests
{
    private const BindingFlags InstancePrivate =
        BindingFlags.Instance | BindingFlags.NonPublic;

    private readonly List<GameObject> testObjects =
        new System.Collections.Generic.List<GameObject>();
    private readonly List<IDisposable> leases =
        new List<IDisposable>();

    private Type gateType;
    private Type modalLeaseType;

    [SetUp]
    public void SetUp()
    {
        gateType = FindPlayerType("GameplayModalInputGate");
        Assert.IsNotNull(gateType);
        modalLeaseType = gateType.GetNestedType(
            "GameplayModalLease",
            BindingFlags.Public);
        Assert.IsNotNull(modalLeaseType);
    }

    [TearDown]
    public void TearDown()
    {
        for (int i = leases.Count - 1; i >= 0; i--)
            leases[i].Dispose();
        leases.Clear();

        foreach (GameObject testObject in testObjects)
        {
            if (testObject != null)
                UnityEngine.Object.DestroyImmediate(testObject);
        }

        testObjects.Clear();
        Assert.IsFalse(IsBlocked());
    }

    [Test]
    public void AcquiringModalBlocksAndReleasingFinalLeaseUnblocks()
    {
        GameplayModalGateTestOwner owner = CreateOwner("Modal owner");
        object lease = Acquire(owner);

        Assert.IsTrue(IsBlocked());
        Assert.IsTrue(IsLeaseActive(lease));

        Dispose(lease);

        Assert.IsFalse(IsBlocked());
        Assert.IsFalse(IsLeaseActive(lease));
    }

    [Test]
    public void DuplicateAcquisitionReturnsSameLease()
    {
        GameplayModalGateTestOwner owner = CreateOwner("Duplicate owner");
        object firstLease = Acquire(owner);
        object secondLease = Acquire(owner);

        Assert.AreSame(firstLease, secondLease);
        Assert.IsTrue(IsBlocked());

        Dispose(firstLease);
        Assert.IsFalse(IsBlocked());
    }

    [Test]
    public void ReleasingOneOfTwoOwnersKeepsGateBlocked()
    {
        object leaseA = Acquire(CreateOwner("Owner A"));
        object leaseB = Acquire(CreateOwner("Owner B"));

        Dispose(leaseA);

        Assert.IsFalse(IsLeaseActive(leaseA));
        Assert.IsTrue(IsLeaseActive(leaseB));
        Assert.IsTrue(IsBlocked());

        Dispose(leaseB);
        Assert.IsFalse(IsBlocked());
    }

    [Test]
    public void DisablingOwnerReleasesItsLeaseOnNextGateQuery()
    {
        GameplayModalGateTestOwner owner = CreateOwner("Disabled owner");
        object lease = Acquire(owner);

        owner.enabled = false;

        Assert.IsFalse(IsBlocked());
        Assert.IsFalse(IsLeaseActive(lease));
    }

    [Test]
    public void DestroyingOwnerReleasesItsLeaseOnNextGateQuery()
    {
        GameplayModalGateTestOwner owner = CreateOwner("Destroyed owner");
        object lease = Acquire(owner);

        UnityEngine.Object.DestroyImmediate(owner.gameObject);

        Assert.IsFalse(IsBlocked());
        Assert.IsFalse(IsLeaseActive(lease));
    }

    [Test]
    public void IsSafeToOpenWaitsForActiveOperationLease()
    {
        object operation = BeginOperation();
        object modalLease = Acquire(CreateOwner("Operation modal"));

        Assert.IsFalse(IsSafeToOpen(modalLease));

        Dispose(operation);

        Assert.IsTrue(IsSafeToOpen(modalLease));
        Dispose(modalLease);
    }

    [Test]
    public void SafeBoundaryReachedFiresOnlyAfterFinalOperationLeaseEnds()
    {
        object operationA = BeginOperation();
        object operationB = BeginOperation();
        object modalLease = Acquire(CreateOwner("Boundary modal"));
        int boundaryEvents = 0;
        bool safeWhenEventFired = false;
        Action handler = () =>
        {
            boundaryEvents++;
            safeWhenEventFired = IsSafeToOpen(modalLease);
        };
        EventInfo boundaryEvent = gateType.GetEvent(
            "SafeBoundaryReached",
            BindingFlags.Public | BindingFlags.Static);
        boundaryEvent.AddEventHandler(null, handler);

        try
        {
            Dispose(operationA);
            Assert.AreEqual(0, boundaryEvents);
            Assert.IsFalse(IsSafeToOpen(modalLease));

            Dispose(operationB);

            Assert.AreEqual(1, boundaryEvents);
            Assert.IsTrue(safeWhenEventFired);
        }
        finally
        {
            boundaryEvent.RemoveEventHandler(null, handler);
            Dispose(operationA);
            Dispose(operationB);
            Dispose(modalLease);
        }
    }

    [Test]
    public void BlockedOvenAndOrderEntryPointsRejectNewActions()
    {
        object modalLease = Acquire(CreateOwner("Input blocker"));
        Assert.IsFalse(TryBeginWhileBlocked());

        GameObject ovenObject = CreateObject("Blocked oven");
        Component oven = ovenObject.AddComponent(
            FindPlayerType("OvenController"));
        InvokeOne(oven, "OnPointerDown", null);

        GameObject orderObject = CreateObject("Blocked order manager");
        Component orderManager = orderObject.AddComponent(
            FindPlayerType("OrderManager"));
        object result = orderManager.GetType().GetMethod(
                "TryFulfillOrderAtIndex",
                BindingFlags.Public | BindingFlags.Instance)
            .Invoke(orderManager, new object[] { 0 });

        Assert.IsFalse((bool)result);
        Assert.IsTrue(IsBlocked());

        GameObject homeObject = CreateObject("Blocked home button");
        homeObject.AddComponent(typeof(RectTransform));
        homeObject.AddComponent(typeof(CanvasRenderer));
        homeObject.AddComponent(FindPlayerType("UnityEngine.UI.Image"));
        homeObject.AddComponent(FindPlayerType("UnityEngine.UI.Button"));
        Component homeButton = homeObject.AddComponent(
            FindPlayerType("HomeButtonUI"));
        InvokeNoArgs(homeButton, "HandleHomeClicked");

        Assert.IsTrue(IsBlocked());
        Dispose(modalLease);
    }

    [Test]
    public void BlockingModalCancelsUncommittedDragAndLaterPointerUpCannotCommit()
    {
        GameObject cellObject = CreateObject("Drag origin cell");
        Component cell = cellObject.AddComponent(FindPlayerType("GridCell"));
        GameObject dessertObject = CreateObject("Dragged dessert");
        Component dessert = dessertObject.AddComponent(FindPlayerType("Dessert"));
        Component dragHandler = dessertObject.AddComponent(
            FindPlayerType("DessertDragHandler"));

        InvokeNoArgs(dessert, "Awake");
        InvokeNoArgs(dragHandler, "Awake");
        InvokeNoArgs(dragHandler, "OnEnable");
        InvokeArgs(cell, "PlaceDessert", new object[] { dessert, false });

        Vector3 originalPosition = dessertObject.transform.position;
        dessertObject.transform.position = originalPosition + Vector3.right * 4f;
        SetPrivateField(dragHandler, "isDragging", true);
        SetPrivateField(dragHandler, "originCell", cell);

        object modalLease = Acquire(CreateOwner("Drag blocker"));

        Assert.IsFalse((bool)GetPrivateField(dragHandler, "isDragging"));
        Assert.AreSame(cell, GetProperty(dessert, "CurrentCell"));
        Assert.AreSame(dessert, GetProperty(cell, "CurrentDessert"));
        Assert.AreEqual(originalPosition, dessertObject.transform.position);

        InvokeOne(dragHandler, "OnPointerUp", null);

        Assert.IsFalse((bool)GetPrivateField(dragHandler, "isDragging"));
        Assert.AreSame(cell, GetProperty(dessert, "CurrentCell"));
        Assert.AreSame(dessert, GetProperty(cell, "CurrentDessert"));
        Assert.AreEqual(originalPosition, dessertObject.transform.position);

        Dispose(modalLease);
        InvokeNoArgs(dragHandler, "OnDisable");
    }

    private GameplayModalGateTestOwner CreateOwner(string objectName)
    {
        GameObject ownerObject = CreateObject(objectName);
        return ownerObject.AddComponent<GameplayModalGateTestOwner>();
    }

    private GameObject CreateObject(string objectName)
    {
        var testObject = new GameObject(objectName);
        testObjects.Add(testObject);
        return testObject;
    }

    private object Acquire(MonoBehaviour owner)
    {
        object[] arguments = { owner, null };
        bool acquired = (bool)gateType.GetMethod(
                "TryAcquireBlockingModal",
                BindingFlags.Public | BindingFlags.Static)
            .Invoke(null, arguments);

        Assert.IsTrue(acquired);
        Assert.IsNotNull(arguments[1]);
        leases.Add((IDisposable)arguments[1]);
        return arguments[1];
    }

    private object BeginOperation()
    {
        object[] arguments = { null };
        bool began = (bool)gateType.GetMethod(
                "TryBeginGameplayOperation",
                BindingFlags.Public | BindingFlags.Static)
            .Invoke(null, arguments);

        Assert.IsTrue(began);
        Assert.IsNotNull(arguments[0]);
        leases.Add((IDisposable)arguments[0]);
        return arguments[0];
    }

    private bool TryBeginWhileBlocked()
    {
        object[] arguments = { null };
        bool began = (bool)gateType.GetMethod(
                "TryBeginGameplayOperation",
                BindingFlags.Public | BindingFlags.Static)
            .Invoke(null, arguments);

        Assert.IsNull(arguments[0]);
        return began;
    }

    private bool IsBlocked()
    {
        return (bool)gateType.GetProperty(
                "IsGameplayInputBlocked",
                BindingFlags.Public | BindingFlags.Static)
            .GetValue(null);
    }

    private bool IsSafeToOpen(object lease)
    {
        return (bool)gateType.GetMethod(
                "IsSafeToOpen",
                BindingFlags.Public | BindingFlags.Static)
            .Invoke(null, new[] { lease });
    }

    private bool IsLeaseActive(object lease)
    {
        return (bool)modalLeaseType.GetProperty(
                "IsActive",
                BindingFlags.Public | BindingFlags.Instance)
            .GetValue(lease);
    }

    private static void Dispose(object lease)
    {
        if (lease is IDisposable disposable)
            disposable.Dispose();
    }

    private static void InvokeNoArgs(Component component, string methodName)
    {
        component.GetType().GetMethod(
                methodName,
                InstancePrivate | BindingFlags.Public)
            .Invoke(component, null);
    }

    private static void InvokeOne(
        Component component,
        string methodName,
        object argument)
    {
        component.GetType().GetMethod(
                methodName,
                InstancePrivate | BindingFlags.Public)
            .Invoke(component, new[] { argument });
    }

    private static void InvokeArgs(
        Component component,
        string methodName,
        object[] arguments)
    {
        component.GetType().GetMethod(
                methodName,
                InstancePrivate | BindingFlags.Public)
            .Invoke(component, arguments);
    }

    private static object GetPrivateField(Component component, string fieldName)
    {
        return component.GetType().GetField(fieldName, InstancePrivate)
            .GetValue(component);
    }

    private static void SetPrivateField(
        Component component,
        string fieldName,
        object value)
    {
        component.GetType().GetField(fieldName, InstancePrivate)
            .SetValue(component, value);
    }

    private static object GetProperty(Component component, string propertyName)
    {
        return component.GetType().GetProperty(
                propertyName,
                BindingFlags.Public | BindingFlags.Instance)
            .GetValue(component);
    }

    private static Type FindPlayerType(string typeName)
    {
        return AppDomain.CurrentDomain.GetAssemblies()
            .Select(assembly => assembly.GetType(typeName))
            .FirstOrDefault(type => type != null);
    }
}
