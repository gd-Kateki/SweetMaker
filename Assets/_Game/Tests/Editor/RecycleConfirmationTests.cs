using System;
using System.Collections;
using System.Collections.Generic;
using System.Reflection;
using System.Runtime.ExceptionServices;
using NUnit.Framework;
using UnityEngine;
using UnityEngine.EventSystems;

public sealed class RecycleConfirmationTests
{
    private const BindingFlags InstanceMembers =
        BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic;
    private const BindingFlags StaticMembers =
        BindingFlags.Static | BindingFlags.Public | BindingFlags.NonPublic;

    private sealed class EventSubscription
    {
        public EventInfo Event;
        public object Source;
        public Delegate Handler;
    }

    private readonly List<GameObject> objects = new List<GameObject>();
    private readonly List<UnityEngine.Object> assets =
        new List<UnityEngine.Object>();
    private readonly List<EventSubscription> eventSubscriptions =
        new List<EventSubscription>();
    private object previousSettingsManager;
    private PropertyInfo settingsInstance;
    private MethodInfo settingsInstanceSetter;

    [SetUp]
    public void SetUp()
    {
        settingsInstance = GetRequiredType("SettingsManager").GetProperty(
            "Instance",
            StaticMembers);
        Assert.IsNotNull(settingsInstance, "SettingsManager.Instance is missing.");
        settingsInstanceSetter = settingsInstance.GetSetMethod(true);
        Assert.IsNotNull(
            settingsInstanceSetter,
            "SettingsManager.Instance setter is missing.");
        previousSettingsManager = settingsInstance.GetValue(null, null);
    }

    [TearDown]
    public void TearDown()
    {
        foreach (EventSubscription subscription in eventSubscriptions)
        {
            subscription.Event.RemoveEventHandler(
                subscription.Source,
                subscription.Handler);
        }
        eventSubscriptions.Clear();

        foreach (GameObject gameObject in objects)
        {
            if (gameObject != null)
                UnityEngine.Object.DestroyImmediate(gameObject);
        }
        objects.Clear();

        foreach (UnityEngine.Object asset in assets)
        {
            if (asset != null)
                UnityEngine.Object.DestroyImmediate(asset);
        }
        assets.Clear();

        InvokeMethod(
            settingsInstanceSetter,
            null,
            new[] { previousSettingsManager });
        Assert.IsFalse(IsGameplayInputBlocked());
    }

    [Test]
    public void ModalAdmissionIsExclusiveOwnerAwareAndIdempotent()
    {
        Component first = CreateOwner("First modal");
        Component second = CreateOwner("Second modal");

        Assert.IsTrue(TryReserve(first));
        Assert.IsTrue(TryReserve(first));
        Assert.IsTrue(IsReservedBy(first));
        Assert.IsFalse(TryReserve(second));

        Release(second);
        Assert.IsTrue(IsReservedBy(first));
        Release(first);
        Assert.IsTrue(TryReserve(second));
    }

    [Test]
    public void PendingBoardRecyclePreservesOwnershipAndCancelRestoresInput()
    {
        Component cell = CreateBoardCell();
        Component dessert = CreateDessert();
        PlaceDessert(cell, dessert);
        Component dragHandler = dessert.GetComponent(GetRequiredType("DessertDragHandler"));
        SetField(dragHandler, "isPendingRecycleConfirmation", true);
        Component controller = CreateController(
            out GameObject overlayRoot,
            null,
            null);
        int notifications = 0;
        Component gridManager = CreateGridManager();
        Subscribe(gridManager, "BoardChanged", () => notifications++);
        SetField(controller, "gridManager", gridManager);

        Assert.IsTrue(BeginPendingRecycle(
            controller,
            dragHandler,
            dessert,
            cell,
            null));
        Assert.AreSame(dessert, GetProperty(cell, "CurrentDessert"));
        Assert.AreSame(cell, GetProperty(dessert, "CurrentCell"));
        Assert.IsTrue(overlayRoot.activeSelf);
        Assert.IsTrue(IsGameplayInputBlocked());

        Invoke(
            controller,
            "OnCancel",
            new[] { typeof(BaseEventData) },
            new object[] { null });

        Assert.AreSame(dessert, GetProperty(cell, "CurrentDessert"));
        Assert.AreSame(cell, GetProperty(dessert, "CurrentCell"));
        Assert.IsFalse(overlayRoot.activeSelf);
        Assert.IsFalse(IsGameplayInputBlocked());
        Assert.IsFalse(IsReservedBy(controller));
        Assert.AreEqual(0, notifications);
    }

    [Test]
    public void ConfirmedBoardRecycleRemovesAndNotifiesExactlyOnce()
    {
        Component cell = CreateBoardCell();
        Component dessert = CreateDessert();
        PlaceDessert(cell, dessert);
        Component dragHandler = dessert.GetComponent(GetRequiredType("DessertDragHandler"));
        SetField(dragHandler, "isPendingRecycleConfirmation", true);
        Component gridManager = CreateGridManager();
        int notifications = 0;
        Subscribe(gridManager, "BoardChanged", () => notifications++);
        Component controller = CreateController(
            out _,
            gridManager,
            null);

        Assert.IsTrue(BeginPendingRecycle(
            controller,
            dragHandler,
            dessert,
            cell,
            null));

        Invoke(controller, "ConfirmPending", Type.EmptyTypes);
        Invoke(controller, "ConfirmPending", Type.EmptyTypes);

        Assert.IsNull(GetProperty(cell, "CurrentDessert"));
        Assert.IsNull(dessert == null ? null : GetProperty(dessert, "CurrentCell"));
        Assert.IsTrue(dessert == null);
        Assert.AreEqual(1, notifications);
        Assert.IsFalse(IsGameplayInputBlocked());
    }

    [Test]
    public void ServingPlateCancelPreservesSlotAndDessert()
    {
        Component slot = CreateShelfSlot();
        Component dessert = CreateDessert();
        Invoke(slot, "SetUnlocked", new[] { typeof(bool) }, true);
        Assert.IsTrue(StoreDessert(slot, dessert));
        Component dragHandler = dessert.GetComponent(GetRequiredType("DessertDragHandler"));
        SetField(dragHandler, "isPendingRecycleConfirmation", true);
        Component shelfManager = CreateShelfManager();
        Component controller = CreateController(out _, null, shelfManager);

        Assert.IsTrue(BeginPendingRecycle(
            controller,
            dragHandler,
            dessert,
            null,
            slot));
        Invoke(controller, "CancelPending", Type.EmptyTypes);

        Assert.AreSame(dessert, GetProperty(slot, "CurrentDessert"));
        Assert.AreSame(slot, GetProperty(dessert, "CurrentShelfSlot"));
        Assert.IsFalse(IsGameplayInputBlocked());
    }

    [Test]
    public void ConfirmedServingPlateRecycleRemovesAndNotifiesExactlyOnce()
    {
        Component slot = CreateShelfSlot();
        Component dessert = CreateDessert();
        Invoke(slot, "SetUnlocked", new[] { typeof(bool) }, true);
        Assert.IsTrue(StoreDessert(slot, dessert));
        Component dragHandler = dessert.GetComponent(GetRequiredType("DessertDragHandler"));
        SetField(dragHandler, "isPendingRecycleConfirmation", true);
        Component shelfManager = CreateShelfManager();
        int notifications = 0;
        Subscribe(shelfManager, "ShelfChanged", () => notifications++);
        Component controller = CreateController(out _, null, shelfManager);

        Assert.IsTrue(BeginPendingRecycle(
            controller,
            dragHandler,
            dessert,
            null,
            slot));

        Invoke(controller, "ConfirmPending", Type.EmptyTypes);
        Invoke(controller, "ConfirmPending", Type.EmptyTypes);

        Assert.IsNull(GetProperty(slot, "CurrentDessert"));
        Assert.IsTrue(dessert == null);
        Assert.AreEqual(1, notifications);
    }

    [Test]
    public void InvalidatedBoardOwnerDoesNotDestroyDessertOrReplaceNewOwner()
    {
        Component cell = CreateBoardCell();
        Component pendingDessert = CreateDessert();
        Component replacement = CreateDessert();
        PlaceDessert(cell, pendingDessert);
        Component dragHandler =
            pendingDessert.GetComponent(GetRequiredType("DessertDragHandler"));
        SetField(dragHandler, "isPendingRecycleConfirmation", true);
        Component controller = CreateController(
            out _,
            CreateGridManager(),
            null);

        Assert.IsTrue(BeginPendingRecycle(
            controller,
            dragHandler,
            pendingDessert,
            cell,
            null));
        Invoke(cell, "RemoveDessert", new[] { GetRequiredType("Dessert") }, pendingDessert);
        PlaceDessert(cell, replacement);
        Invoke(controller, "ConfirmPending", Type.EmptyTypes);

        Assert.IsTrue(pendingDessert != null);
        Assert.AreSame(replacement, GetProperty(cell, "CurrentDessert"));
        Assert.IsFalse(IsGameplayInputBlocked());
    }

    [Test]
    public void SessionCaptureDuringPendingRecycleRetainsBoardAndPlateEntries()
    {
        Type slotType = GetRequiredType("ShelfSlot");
        Component gridManager = CreateGridManager();
        Component shelfManager = CreateShelfManager();
        Component cell = CreateBoardCell();
        Component slot = CreateShelfSlot();
        Invoke(slot, "SetUnlocked", new[] { typeof(bool) }, true);
        Component boardDessert = CreateDessert();
        Component plateDessert = CreateDessert();
        SetField(boardDessert, "definition", CreateDefinition(4));
        SetField(plateDessert, "definition", CreateDefinition(6));
        PlaceDessert(cell, boardDessert);
        Assert.IsTrue(StoreDessert(slot, plateDessert));

        IList cells = (IList)GetField(gridManager, "cells");
        Assert.IsNotNull(cells, "GridManager.cells is missing.");
        cells.Add(cell);
        Array slots = Array.CreateInstance(slotType, 1);
        slots.SetValue(slot, 0);
        SetField(shelfManager, "slots", slots);

        GameObject sessionObject = Track(
            new GameObject("Merge session capture test"));
        sessionObject.SetActive(false);
        Component session = sessionObject.AddComponent(
            GetRequiredType("MergeSessionController"));
        SetField(session, "gridManager", gridManager);
        SetField(session, "shelfManager", shelfManager);

        Component controller = CreateController(
            out _,
            gridManager,
            shelfManager);
        Component boardHandler =
            boardDessert.GetComponent(GetRequiredType("DessertDragHandler"));
        SetField(boardHandler, "isPendingRecycleConfirmation", true);
        Assert.IsTrue(BeginPendingRecycle(
            controller,
            boardHandler,
            boardDessert,
            cell,
            null));

        object snapshot = Activator.CreateInstance(
            GetRequiredType("MergeSessionData"));
        Invoke(
            session,
            "CaptureBoard",
            new[] { snapshot.GetType() },
            snapshot);
        Invoke(
            session,
            "CaptureShelf",
            new[] { snapshot.GetType() },
            snapshot);
        IList boardStates = (IList)GetField(snapshot, "boardDesserts");
        IList shelfStates = (IList)GetField(snapshot, "shelfDesserts");
        Assert.AreEqual(1, boardStates.Count);
        Assert.AreEqual(4, GetField(boardStates[0], "dessertTier"));
        Assert.AreEqual(1, shelfStates.Count);
        Assert.AreEqual(6, GetField(shelfStates[0], "dessertTier"));
        Assert.AreSame(boardDessert, GetProperty(cell, "CurrentDessert"));
        Assert.AreSame(plateDessert, GetProperty(slot, "CurrentDessert"));

        Invoke(controller, "CancelPending", Type.EmptyTypes);
    }

    [Test]
    public void PauseAndFocusLossCancelPendingRecycleWithoutRemovingItem()
    {
        Component cell = CreateBoardCell();
        Component dessert = CreateDessert();
        PlaceDessert(cell, dessert);
        Component dragHandler = dessert.GetComponent(GetRequiredType("DessertDragHandler"));
        SetField(dragHandler, "isPendingRecycleConfirmation", true);
        Component controller = CreateController(
            out _,
            CreateGridManager(),
            null);

        Assert.IsTrue(BeginPendingRecycle(
            controller,
            dragHandler,
            dessert,
            cell,
            null));
        Invoke(controller, "OnApplicationPause", new[] { typeof(bool) }, true);
        Assert.AreSame(dessert, GetProperty(cell, "CurrentDessert"));
        Assert.IsFalse(IsGameplayInputBlocked());

        Assert.IsTrue(BeginPendingRecycle(
            controller,
            dragHandler,
            dessert,
            cell,
            null));
        Invoke(controller, "OnApplicationFocus", new[] { typeof(bool) }, false);
        Assert.AreSame(dessert, GetProperty(cell, "CurrentDessert"));
        Assert.IsFalse(IsGameplayInputBlocked());
    }

    [Test]
    public void ControllerDisableCancelsPendingRecycleAndReleasesBothLeases()
    {
        Component cell = CreateBoardCell();
        Component dessert = CreateDessert();
        PlaceDessert(cell, dessert);
        Component dragHandler = dessert.GetComponent(GetRequiredType("DessertDragHandler"));
        SetField(dragHandler, "isPendingRecycleConfirmation", true);
        Component controller = CreateController(
            out GameObject overlayRoot,
            CreateGridManager(),
            null);

        Assert.IsTrue(BeginPendingRecycle(
            controller,
            dragHandler,
            dessert,
            cell,
            null));
        Assert.That(controller, Is.InstanceOf<Behaviour>());
        ((Behaviour)controller).enabled = false;

        Assert.AreSame(dessert, GetProperty(cell, "CurrentDessert"));
        Assert.IsFalse(overlayRoot.activeSelf);
        Assert.IsFalse(IsGameplayInputBlocked());
        Assert.IsFalse(IsReservedBy(controller));
    }

    [Test]
    public void ControllerOnDisableCallbackCancelsPendingRecycleAndReleasesBothLeases()
    {
        Component cell = CreateBoardCell();
        Component dessert = CreateDessert();
        PlaceDessert(cell, dessert);
        Component dragHandler = dessert.GetComponent(GetRequiredType("DessertDragHandler"));
        SetField(dragHandler, "isPendingRecycleConfirmation", true);
        Component controller = CreateController(
            out GameObject overlayRoot,
            CreateGridManager(),
            null);

        Assert.IsTrue(BeginPendingRecycle(
            controller,
            dragHandler,
            dessert,
            cell,
            null));
        Assert.That(controller, Is.InstanceOf<Behaviour>());
        // EditMode unit coverage of cleanup; the separate disable test still
        // verifies callback delivery and must also be checked in Play Mode.
        Invoke(controller, "OnDisable", Type.EmptyTypes);
        Invoke(controller, "OnDisable", Type.EmptyTypes);

        Assert.AreSame(dessert, GetProperty(cell, "CurrentDessert"));
        Assert.IsFalse(overlayRoot.activeSelf);
        Assert.IsFalse(IsGameplayInputBlocked());
        Assert.IsFalse(IsReservedBy(controller));
    }

    [Test]
    public void DragHandlerDisableCancelsItsPendingRecycle()
    {
        Component cell = CreateBoardCell();
        Component dessert = CreateDessert();
        PlaceDessert(cell, dessert);
        Component dragHandler = dessert.GetComponent(GetRequiredType("DessertDragHandler"));
        SetField(dragHandler, "isPendingRecycleConfirmation", true);
        Component controller = CreateController(
            out GameObject overlayRoot,
            CreateGridManager(),
            null);
        SetField(dragHandler, "recycleConfirmationController", controller);

        Assert.IsTrue(BeginPendingRecycle(
            controller,
            dragHandler,
            dessert,
            cell,
            null));
        Assert.That(dragHandler, Is.InstanceOf<Behaviour>());
        ((Behaviour)dragHandler).enabled = false;

        Assert.AreSame(dessert, GetProperty(cell, "CurrentDessert"));
        Assert.IsFalse(overlayRoot.activeSelf);
        Assert.IsFalse(IsGameplayInputBlocked());
        Assert.IsFalse(IsReservedBy(controller));
    }

    [Test]
    public void DragHandlerOnDisableCallbackCancelsItsPendingRecycle()
    {
        Component cell = CreateBoardCell();
        Component dessert = CreateDessert();
        PlaceDessert(cell, dessert);
        Component dragHandler = dessert.GetComponent(GetRequiredType("DessertDragHandler"));
        SetField(dragHandler, "isPendingRecycleConfirmation", true);
        Component controller = CreateController(
            out GameObject overlayRoot,
            CreateGridManager(),
            null);
        SetField(dragHandler, "recycleConfirmationController", controller);

        Assert.IsTrue(BeginPendingRecycle(
            controller,
            dragHandler,
            dessert,
            cell,
            null));
        Assert.That(dragHandler, Is.InstanceOf<Behaviour>());
        // EditMode unit coverage of cleanup; the separate disable test still
        // verifies callback delivery and must also be checked in Play Mode.
        Invoke(dragHandler, "OnDisable", Type.EmptyTypes);
        Invoke(dragHandler, "OnDisable", Type.EmptyTypes);

        Assert.AreSame(dessert, GetProperty(cell, "CurrentDessert"));
        Assert.IsFalse(overlayRoot.activeSelf);
        Assert.IsFalse(IsGameplayInputBlocked());
        Assert.IsFalse(IsReservedBy(controller));
    }

    [Test]
    public void SettingsAndRecycleCannotReserveModalAdmissionTogether()
    {
        Component settingsOwner = CreateOwner("Settings owner");
        Component recycleOwner = CreateOwner("Recycle owner");

        Assert.IsTrue(TryReserve(settingsOwner));
        Assert.IsFalse(TryReserve(recycleOwner));
        Release(settingsOwner);
        Assert.IsTrue(TryReserve(recycleOwner));
    }

    [Test]
    public void DirectRecycleSettingOffRetainsImmediateRemovalPath()
    {
        ConfigureSettings(false);
        Component cell = CreateBoardCell();
        Component dessert = CreateDessert();
        PlaceDessert(cell, dessert);
        Component dragHandler = dessert.GetComponent(GetRequiredType("DessertDragHandler"));
        SetField(dragHandler, "originCell", cell);
        SetField(dragHandler, "dessert", dessert);
        SetField(dragHandler, "gridManager", CreateGridManager());

        Assert.IsFalse((bool)Invoke(
            dragHandler,
            "TryBeginRecycleConfirmation",
            Type.EmptyTypes));
        Assert.IsTrue((bool)Invoke(
            dragHandler,
            "TryRecycleDraggedDessert",
            Type.EmptyTypes));
        Assert.IsNull(GetProperty(cell, "CurrentDessert"));
    }

    [Test]
    public void ConfirmationSettingOnOpensPendingTransactionWithoutRemovingOwner()
    {
        ConfigureSettings(true);
        Component cell = CreateBoardCell();
        Component dessert = CreateDessert();
        PlaceDessert(cell, dessert);
        Component dragHandler = dessert.GetComponent(GetRequiredType("DessertDragHandler"));
        SetField(dragHandler, "originCell", cell);
        SetField(dragHandler, "dessert", dessert);
        SetField(dragHandler, "isPendingRecycleConfirmation", false);
        Component controller = CreateController(
            out GameObject overlayRoot,
            CreateGridManager(),
            null);
        SetField(dragHandler, "recycleConfirmationController", controller);

        Assert.IsTrue((bool)Invoke(
            dragHandler,
            "TryBeginRecycleConfirmation",
            Type.EmptyTypes));

        Assert.AreSame(dessert, GetProperty(cell, "CurrentDessert"));
        Assert.AreSame(cell, GetProperty(dessert, "CurrentCell"));
        Assert.IsTrue(overlayRoot.activeSelf);
        Invoke(controller, "CancelPending", Type.EmptyTypes);
        Assert.AreSame(dessert, GetProperty(cell, "CurrentDessert"));
    }

    [Test]
    public void DuplicatePointerUpCannotCommitPendingRecycle()
    {
        Component cell = CreateBoardCell();
        Component dessert = CreateDessert();
        PlaceDessert(cell, dessert);
        Component controller = CreateController(
            out _,
            CreateGridManager(),
            null);
        Component dragHandler = dessert.GetComponent(GetRequiredType("DessertDragHandler"));
        SetField(dragHandler, "isPendingRecycleConfirmation", true);

        Assert.IsTrue(BeginPendingRecycle(
            controller,
            dragHandler,
            dessert,
            cell,
            null));
        Invoke(
            dragHandler,
            "OnPointerUp",
            new[] { typeof(PointerEventData) },
            new object[] { null });
        Invoke(
            dragHandler,
            "OnPointerUp",
            new[] { typeof(PointerEventData) },
            new object[] { null });

        Assert.AreSame(dessert, GetProperty(cell, "CurrentDessert"));
        Assert.IsTrue((bool)GetProperty(controller, "IsOpenOrWaiting"));
        Invoke(controller, "CancelPending", Type.EmptyTypes);
        Invoke(
            dragHandler,
            "OnPointerUp",
            new[] { typeof(PointerEventData) },
            new object[] { null });
        Assert.AreSame(dessert, GetProperty(cell, "CurrentDessert"));
        Assert.IsFalse((bool)GetProperty(controller, "IsOpenOrWaiting"));
    }

    private Component CreateOwner(string objectName)
    {
        return Track(new GameObject(objectName))
            .AddComponent(GetRequiredType("RecycleConfirmationController"));
    }

    private Component CreateBoardCell()
    {
        return Track(new GameObject("Board cell"))
            .AddComponent(GetRequiredType("GridCell"));
    }

    private Component CreateShelfSlot()
    {
        return Track(new GameObject("Serving Plate slot"))
            .AddComponent(GetRequiredType("ShelfSlot"));
    }

    private Component CreateDessert()
    {
        GameObject gameObject = Track(new GameObject("Dessert"));
        Component dessert = gameObject.AddComponent(GetRequiredType("Dessert"));
        gameObject.AddComponent(GetRequiredType("DessertDragHandler"));
        return dessert;
    }

    private object CreateDefinition(int tier)
    {
        Type definitionType = GetRequiredType("DessertDefinition");
        UnityEngine.Object definition =
            ScriptableObject.CreateInstance(definitionType);
        SetField(definition, "tier", tier);
        assets.Add(definition);
        return definition;
    }

    private Component CreateGridManager()
    {
        GameObject gameObject = Track(new GameObject("Grid manager"));
        gameObject.SetActive(false);
        return gameObject.AddComponent(GetRequiredType("GridManager"));
    }

    private Component CreateShelfManager()
    {
        GameObject gameObject = Track(new GameObject("Shelf manager"));
        gameObject.SetActive(false);
        return gameObject.AddComponent(GetRequiredType("ShelfManager"));
    }

    private Component CreateController(
        out GameObject overlayRoot,
        Component gridManager,
        Component shelfManager)
    {
        GameObject controllerObject =
            Track(new GameObject("Recycle confirmation controller"));
        overlayRoot = Track(new GameObject("Recycle confirmation overlay"));
        overlayRoot.transform.SetParent(controllerObject.transform);
        overlayRoot.SetActive(false);

        Component controller = controllerObject.AddComponent(
            GetRequiredType("RecycleConfirmationController"));
        SetField(controller, "overlayRoot", overlayRoot);
        SetField(controller, "gridManager", gridManager);
        SetField(controller, "shelfManager", shelfManager);
        return controller;
    }

    private void ConfigureSettings(bool confirmImportantActions)
    {
        GameObject settingsObject = Track(new GameObject("Settings manager"));
        settingsObject.SetActive(false);
        Component settingsManager = settingsObject.AddComponent(
            GetRequiredType("SettingsManager"));
        Type profileType = GetRequiredType("SettingsProfileData");
        object settings = InvokeStatic(
            profileType,
            "CreateDefault",
            Type.EmptyTypes);
        SetField(settings, "confirmImportantActions", confirmImportantActions);
        SetField(settingsManager, "currentSettings", settings);
        object loadedStatus = Enum.Parse(
            GetRequiredType("SettingsPersistenceStatus"),
            "Loaded");
        SetField(settingsManager, "persistenceStatus", loadedStatus);
        InvokeMethod(
            settingsInstanceSetter,
            null,
            new object[] { settingsManager });
    }

    private GameObject Track(GameObject gameObject)
    {
        objects.Add(gameObject);
        return gameObject;
    }

    private static Type GetRequiredType(string typeName)
    {
        Type found = null;
        foreach (Assembly assembly in AppDomain.CurrentDomain.GetAssemblies())
        {
            if (assembly.GetName().Name != "Assembly-CSharp")
                continue;

            found = assembly.GetType(typeName, false);
            if (found != null)
                break;
        }

        Assert.IsNotNull(
            found,
            $"Required runtime type '{typeName}' was not found in Assembly-CSharp.");
        return found;
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
        Assert.IsNotNull(
            method,
            $"Missing static method {type.FullName}.{methodName}.");
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
                ExceptionDispatchInfo.Capture(exception.InnerException).Throw();
            throw;
        }
    }

    private static object GetProperty(object target, string propertyName)
    {
        Assert.IsNotNull(target, $"Cannot read {propertyName} from a null target.");
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
        Assert.IsNotNull(target, $"Cannot read {fieldName} from a null target.");
        FieldInfo field = target.GetType().GetField(fieldName, InstanceMembers);
        Assert.IsNotNull(
            field,
            $"Missing field {target.GetType().FullName}.{fieldName}.");
        return field.GetValue(target);
    }

    private static void SetField(object target, string fieldName, object value)
    {
        Assert.IsNotNull(target, $"Cannot set {fieldName} on a null target.");
        FieldInfo field = target.GetType().GetField(fieldName, InstanceMembers);
        Assert.IsNotNull(
            field,
            $"Missing field {target.GetType().FullName}.{fieldName}.");
        field.SetValue(target, value);
    }

    private void Subscribe(
        object source,
        string eventName,
        Action callback)
    {
        EventInfo eventInfo = source.GetType().GetEvent(
            eventName,
            InstanceMembers);
        Assert.IsNotNull(
            eventInfo,
            $"Missing event {source.GetType().FullName}.{eventName}.");
        Delegate handler = Delegate.CreateDelegate(
            eventInfo.EventHandlerType,
            callback.Target,
            callback.Method);
        eventInfo.AddEventHandler(source, handler);
        eventSubscriptions.Add(new EventSubscription
        {
            Event = eventInfo,
            Source = source,
            Handler = handler
        });
    }

    private bool TryReserve(Component owner)
    {
        return (bool)InvokeStatic(
            GetRequiredType("GameplayModalAdmission"),
            "TryReserve",
            new[] { typeof(MonoBehaviour) },
            owner);
    }

    private bool IsReservedBy(Component owner)
    {
        return (bool)InvokeStatic(
            GetRequiredType("GameplayModalAdmission"),
            "IsReservedBy",
            new[] { typeof(MonoBehaviour) },
            owner);
    }

    private void Release(Component owner)
    {
        InvokeStatic(
            GetRequiredType("GameplayModalAdmission"),
            "Release",
            new[] { typeof(MonoBehaviour) },
            owner);
    }

    private bool IsGameplayInputBlocked()
    {
        return (bool)GetStaticProperty(
            GetRequiredType("GameplayModalInputGate"),
            "IsGameplayInputBlocked");
    }

    private static object GetStaticProperty(Type type, string propertyName)
    {
        PropertyInfo property = type.GetProperty(propertyName, StaticMembers);
        Assert.IsNotNull(
            property,
            $"Missing static property {type.FullName}.{propertyName}.");
        return property.GetValue(null, null);
    }

    private static bool BeginPendingRecycle(
        Component controller,
        Component dragHandler,
        Component dessert,
        Component cell,
        Component slot)
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
            slot);
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

    private static bool StoreDessert(Component slot, Component dessert)
    {
        return (bool)Invoke(
            slot,
            "TryStoreDessert",
            new[] { GetRequiredType("Dessert"), typeof(bool) },
            dessert,
            true);
    }
}
