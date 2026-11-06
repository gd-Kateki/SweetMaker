using System;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEngine;

public sealed class CloudChoicePresentationTests
{
    private static Type Find(string name) => AppDomain.CurrentDomain.GetAssemblies()
        .Select(a => a.GetType(name)).First(t => t != null);
    private const BindingFlags PrivateInstance = BindingFlags.Instance | BindingFlags.NonPublic;

    [Test]
    public void CloudChoiceWaitsForAnExistingGameplayOperationToFinish()
    {
        Type gate = Find("GameplayModalInputGate");
        object[] operationArgs = { null };
        Assert.IsTrue((bool)gate.GetMethod("TryBeginGameplayOperation").Invoke(null, operationArgs));
        var operation = (IDisposable)operationArgs[0];
        var root = new GameObject("Cloud safe boundary test"); root.SetActive(false);
        var cloud = Find("SweetMerge.Cloud.SimpleCloudBackup");
        var ui = Find("SweetMerge.Cloud.FreshInstallCloudChoiceUI");
        Component view = null;
        try
        {
            var service = root.AddComponent(cloud);
            cloud.GetField("freshInstallOwner", PrivateInstance).SetValue(service, "player-test");
            ui.GetMethod("Show", BindingFlags.NonPublic | BindingFlags.Static).Invoke(null, new object[] { service });
            view = (Component)ui.GetField("instance", BindingFlags.NonPublic | BindingFlags.Static).GetValue(null);
            Assert.IsFalse((bool)ui.GetField("built", PrivateInstance).GetValue(view));
            operation.Dispose(); operation = null;
            ui.GetMethod("Update", PrivateInstance).Invoke(view, null);
            Assert.IsTrue((bool)ui.GetField("built", PrivateInstance).GetValue(view));
        }
        finally
        {
            operation?.Dispose();
            if (view != null) UnityEngine.Object.DestroyImmediate(view.gameObject);
            UnityEngine.Object.DestroyImmediate(root);
        }
    }

    [Test]
    public void FreshInstallCloudChoiceRendersAtStartupOverlayPriorityAndBlocksInput()
    {
        var root = new GameObject("Cloud presentation test"); root.SetActive(false);
        var type = Find("SweetMerge.Cloud.SimpleCloudBackup");
        var service = root.AddComponent(type);
        var uiType = Find("SweetMerge.Cloud.FreshInstallCloudChoiceUI");
        var show = uiType.GetMethod("Show", BindingFlags.NonPublic | BindingFlags.Static);
        try
        {
            type.GetField("freshInstallOwner", PrivateInstance).SetValue(service, "player-test");
            show.Invoke(null, new object[] { service });
            var view = (Component)uiType.GetField("instance", BindingFlags.Static | BindingFlags.NonPublic).GetValue(null);
            Assert.IsNotNull(view);
            Assert.AreEqual(short.MaxValue, view.GetComponent<Canvas>().sortingOrder,
                "A lower priority hides the restore choice behind startup's full-screen overlays.");
            Assert.IsTrue((bool)Find("GameplayModalInputGate").GetProperty("IsGameplayInputBlocked").GetValue(null));
        }
        finally
        {
            var view = (Component)uiType.GetField("instance", BindingFlags.Static | BindingFlags.NonPublic).GetValue(null);
            if (view != null) UnityEngine.Object.DestroyImmediate(view.gameObject);
            UnityEngine.Object.DestroyImmediate(root);
        }
    }

    [Test]
    public void BakeryLoadingOverlayYieldsWhileFreshInstallDecisionIsPending()
    {
        Type cloudType = Find("SweetMerge.Cloud.SimpleCloudBackup");
        FieldInfo singleton = cloudType.GetField("<Instance>k__BackingField", BindingFlags.Static | BindingFlags.NonPublic);
        object previous = singleton.GetValue(null);
        var serviceRoot = new GameObject("Cloud service test"); serviceRoot.SetActive(false);
        var loadingRoot = new GameObject("Loading test", typeof(RectTransform)); loadingRoot.SetActive(false);
        var overlay = new GameObject("Loading overlay");
        try
        {
            var service = serviceRoot.AddComponent(cloudType);
            cloudType.GetField("freshInstallOwner", PrivateInstance).SetValue(service, "player-test");
            singleton.SetValue(null, service);
            Type loadingType = Find("MainBakeryStartupUI");
            var loading = loadingRoot.AddComponent(loadingType);
            loadingType.GetField("overlay", PrivateInstance).SetValue(loading, overlay);
            loadingType.GetMethod("Refresh", PrivateInstance).Invoke(loading, null);
            Assert.IsFalse(overlay.activeSelf, "Loading must not cover the interactive cloud choice.");
        }
        finally
        {
            singleton.SetValue(null, previous);
            UnityEngine.Object.DestroyImmediate(overlay);
            UnityEngine.Object.DestroyImmediate(loadingRoot);
            UnityEngine.Object.DestroyImmediate(serviceRoot);
        }
    }
}
