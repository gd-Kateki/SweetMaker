using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public sealed class LeaderboardOverlayTests
{
    private const BindingFlags Private = BindingFlags.Instance | BindingFlags.NonPublic;
    private const BindingFlags StaticPrivate = BindingFlags.Static | BindingFlags.NonPublic;
    private Scene original, scene;
    private readonly List<GameObject> roots = new List<GameObject>();
    private readonly List<IDisposable> leases = new List<IDisposable>();
    private Component leaderboard;
    private object previousReadiness;
    private FieldInfo readinessField;
    private static Type Find(string name) => AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType(name)).First(t=>t!=null);
    private static object Get(object target,string name) => target.GetType().GetField(name,Private).GetValue(target);
    private static void Call(object target,string name) => target.GetType().GetMethod(name,Private).Invoke(target,null);
    private static void Reset(string type,string method) => Find(type).GetMethod(method,StaticPrivate).Invoke(null,null);

    [SetUp]
    public void SetUp()
    {
        original=SceneManager.GetActiveScene();
        scene=EditorSceneManager.OpenScene("Assets/_Game/Scenes/MainBakery.unity",OpenSceneMode.Additive);
        SceneManager.SetActiveScene(scene);
        Reset("HomeOverlayVisibility","ResetState"); Reset("GameplayModalInputGate","ResetRuntimeState");
        readinessField=Find("ApplicationReadinessCoordinator").GetField("<Instance>k__BackingField",StaticPrivate);
        previousReadiness=readinessField.GetValue(null); readinessField.SetValue(null,null);
        var root=Make("Leaderboard test",false);
        leaderboard=root.AddComponent(Find("CafeLeaderboardUI"));
        Call(leaderboard,"BuildInterface"); root.SetActive(true);
    }
    [TearDown]
    public void TearDown()
    {
        foreach(var lease in leases)lease.Dispose(); leases.Clear();
        foreach(var root in roots)if(root!=null)UnityEngine.Object.DestroyImmediate(root); roots.Clear();
        Reset("HomeOverlayVisibility","ResetState"); Reset("GameplayModalInputGate","ResetRuntimeState");
        readinessField.SetValue(null,previousReadiness);
        SceneManager.SetActiveScene(original); EditorSceneManager.CloseScene(scene,true);
    }
    private GameObject Make(string name,bool active=true)
    {var root=new GameObject(name,typeof(RectTransform));root.SetActive(active);roots.Add(root);return root;}
    private IDisposable Acquire(Component owner)
    {
        object[] args={owner,null};
        Assert.IsTrue((bool)Find("GameplayModalInputGate").GetMethod("TryAcquireBlockingModal").Invoke(null,args));
        var lease=(IDisposable)args[1];leases.Add(lease);return lease;
    }
    private Button Launcher => (Button)Get(leaderboard,"launcher");
    private GameObject Panel => (GameObject)Get(leaderboard,"panel");
    private void Late() => Call(leaderboard,"LateUpdate");
    private static void Mark(GameObject root) => Find("HomeOverlayVisibility").GetMethod("Attach").Invoke(null,new object[]{root});

    [Test]
    public void LauncherStartsHiddenAndOnlyAppearsOnUnobstructedHome()
    {
        Assert.IsFalse(Launcher.gameObject.activeSelf);
        Late(); Assert.IsTrue(Launcher.gameObject.activeSelf);
    }

    [Test]
    public void HomeOverlayHidesLauncherRejectsOpenAndAllowsReturnAfterClosing()
    {
        Late(); Assert.IsTrue(Launcher.gameObject.activeSelf);
        var overlay=Make("My cafe overlay",false);Mark(overlay);
        overlay.SetActive(true);Late();Assert.IsFalse(Launcher.gameObject.activeSelf);
        Call(leaderboard,"Open");Assert.IsFalse(Panel.activeSelf);
        overlay.SetActive(false);Late();Assert.IsTrue(Launcher.gameObject.activeSelf);
    }

    [Test]
    public void ForeignModalClosesLeaderboardAndKeepsItsOwnLease()
    {
        var own=Acquire(leaderboard);
        leaderboard.GetType().GetField("lease",Private).SetValue(leaderboard,own);
        Panel.SetActive(true);Late();Assert.IsTrue(Panel.activeSelf,"The leaderboard's own lease must not close it.");
        var other=Make("Reward modal").AddComponent<GameplayModalGateTestOwner>();var foreign=Acquire(other);
        Late();Assert.IsFalse(Panel.activeSelf);Assert.IsFalse(Launcher.gameObject.activeSelf);
        Assert.IsTrue((bool)foreign.GetType().GetProperty("IsActive").GetValue(foreign),"Closing leaderboards must not release the other popup's lease.");
        foreign.Dispose();Late();Assert.IsTrue(Launcher.gameObject.activeSelf);
    }

    [Test]
    public void HomeOverlayClosesAnAlreadyOpenLeaderboard()
    {
        var own=Acquire(leaderboard);leaderboard.GetType().GetField("lease",Private).SetValue(leaderboard,own);Panel.SetActive(true);
        Mark(Make("Naming overlay"));Late();Assert.IsFalse(Panel.activeSelf);Assert.IsFalse(Launcher.gameObject.activeSelf);
        Assert.IsFalse((bool)own.GetType().GetProperty("IsActive").GetValue(own));
    }

    [Test]
    public void SceneTransitionHidesLauncherImmediatelyAndRejectsStaleClicksOutsideHome()
    {
        Late();Assert.IsTrue(Launcher.gameObject.activeSelf);
        var other=EditorSceneManager.OpenScene("Assets/_Game/Scenes/Game.unity",OpenSceneMode.Additive);
        try
        {
            leaderboard.GetType().GetMethod("SceneChanged",Private).Invoke(leaderboard,new object[]{scene,other});
            Assert.IsFalse(Launcher.gameObject.activeSelf);
            SceneManager.SetActiveScene(other);
            Call(leaderboard,"Open");Assert.IsFalse(Panel.activeSelf);Late();Assert.IsFalse(Launcher.gameObject.activeSelf);
        }
        finally { SceneManager.SetActiveScene(scene);EditorSceneManager.CloseScene(other,true); }
    }

    [Test]
    public void HiddenParentsAndDestroyedOverlaysDoNotPermanentlyHideNavigation()
    {
        var parent=Make("Hidden overlay parent",false);var overlay=Make("Overlay");overlay.transform.SetParent(parent.transform,false);Mark(overlay);Mark(overlay);
        Late();Assert.IsTrue(Launcher.gameObject.activeSelf);
        parent.SetActive(true);Late();Assert.IsFalse(Launcher.gameObject.activeSelf);
        UnityEngine.Object.DestroyImmediate(parent);Late();Assert.IsTrue(Launcher.gameObject.activeSelf);
    }

    [TestCase("CafeProfileUI","CreatePanel","panelRoot")]
    [TestCase("CafeProfileUI","CreateNamingPopup","namingRoot")]
    [TestCase("MainBakeryStartupUI","BuildInterface","overlay")]
    [TestCase("StartupPrivacyWelcomeUI","BuildInterface","overlayRoot")]
    [TestCase("SweetMerge.Profile.HybridTutorialWelcomeUI","BuildPanel","panel")]
    public void RuntimeHomePanelsRegisterTheirActualOverlayRoot(string type,string build,string field)
    {
        var canvas=Make("Home canvas");canvas.AddComponent<Canvas>().renderMode=RenderMode.ScreenSpaceOverlay;
        var host=Make("Panel builder",false);host.transform.SetParent(canvas.transform,false);
        var component=host.AddComponent(Find(type));Call(component,build);
        var overlay=(GameObject)Get(component,field);
        Assert.IsNotNull(overlay.GetComponent(Find("HomeOverlayVisibility")),type+" must register the visible overlay, not its always-active controller.");
    }
}
