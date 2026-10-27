#if UNITY_EDITOR
using System;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

public sealed class GameplayModalInputGateDiagnostics : EditorWindow
{
    private const int EventHistoryLimit = 8;

    private readonly List<string> eventHistory = new List<string>();
    private MonoBehaviour ownerA;
    private MonoBehaviour ownerB;
    private MonoBehaviour leasedOwnerA;
    private MonoBehaviour leasedOwnerB;
    private GameplayModalInputGate.GameplayModalLease leaseA;
    private GameplayModalInputGate.GameplayModalLease leaseB;
    private bool isSubscribed;
    private bool isBlocked;
    private string lastAction = "No diagnostic action performed.";

    [MenuItem("Tools/Sweet Merge/Gameplay Modal Gate Diagnostics")]
    private static void OpenWindow()
    {
        GetWindow<GameplayModalInputGateDiagnostics>(
            "Modal Gate Diagnostics");
    }

    private void OnEnable()
    {
        EditorApplication.playModeStateChanged += HandlePlayModeStateChanged;
        if (EditorApplication.isPlaying)
            SubscribeToGateEvents();
    }

    private void OnDisable()
    {
        EditorApplication.playModeStateChanged -= HandlePlayModeStateChanged;
        UnsubscribeFromGateEvents();
    }

    private void OnInspectorUpdate()
    {
        if (EditorApplication.isPlaying)
            RefreshGateState();

        Repaint();
    }

    private void OnGUI()
    {
        EditorGUILayout.LabelField(
            "Gameplay Modal Input Gate",
            EditorStyles.boldLabel);

        if (!EditorApplication.isPlaying)
        {
            EditorGUILayout.HelpBox(
                "Enter Play Mode to inspect or acquire modal leases. " +
                "The harness never acquires leases automatically.",
                MessageType.Info);
            return;
        }

        RefreshGateState();
        EditorGUILayout.LabelField("Gate blocked", isBlocked ? "YES" : "NO");

        DrawOwnerControls(
            "Owner A",
            ref ownerA,
            ref leasedOwnerA,
            ref leaseA);
        DrawOwnerControls(
            "Owner B",
            ref ownerB,
            ref leasedOwnerB,
            ref leaseB);

        EditorGUILayout.Space();
        EditorGUILayout.LabelField(
            "Operation count",
            "Not publicly exposed; use IsSafeToOpen during an in-flight operation.");
        EditorGUILayout.LabelField(
            "Last action",
            lastAction,
            EditorStyles.wordWrappedLabel);

        EditorGUILayout.Space();
        EditorGUILayout.LabelField("Recent gate events", EditorStyles.boldLabel);
        if (eventHistory.Count == 0)
        {
            EditorGUILayout.LabelField("No gate events observed this Play Mode session.");
        }
        else
        {
            for (int i = eventHistory.Count - 1; i >= 0; i--)
                EditorGUILayout.LabelField(eventHistory[i]);
        }

        EditorGUILayout.HelpBox(
            "Owner cleanup test: acquire a lease for a safe, inert " +
            "MonoBehaviour, disable that component in the Inspector, then " +
            "observe the lease become inactive and the gate unblock. Do not " +
            "disable a gameplay component needed by the current test.",
            MessageType.Warning);
    }

    private void DrawOwnerControls(
        string label,
        ref MonoBehaviour owner,
        ref MonoBehaviour leasedOwner,
        ref GameplayModalInputGate.GameplayModalLease lease)
    {
        EditorGUILayout.Space();
        EditorGUILayout.LabelField(label, EditorStyles.boldLabel);

        bool leaseActive = lease != null && lease.IsActive;
        using (new EditorGUI.DisabledScope(leaseActive))
        {
            owner = (MonoBehaviour)EditorGUILayout.ObjectField(
                "Owner component",
                owner,
                typeof(MonoBehaviour),
                true);
        }

        DrawLeaseStatus(leasedOwner, lease);

        using (new EditorGUILayout.HorizontalScope())
        {
            using (new EditorGUI.DisabledScope(
                       !IsValidOwner(owner) || leaseActive))
            {
                if (GUILayout.Button("Acquire " + label))
                    AcquireOwner(label, owner, ref leasedOwner, ref lease);
            }

            using (new EditorGUI.DisabledScope(!leaseActive))
            {
                if (GUILayout.Button("Release " + label))
                    ReleaseOwner(label, lease);
            }
        }

        if (label == "Owner A")
        {
            using (new EditorGUI.DisabledScope(!leaseActive))
            {
                if (GUILayout.Button("Test duplicate acquisition for Owner A"))
                    TestDuplicateOwnerAAcquisition();
            }
        }
    }

    private void DrawLeaseStatus(
        MonoBehaviour leasedOwner,
        GameplayModalInputGate.GameplayModalLease lease)
    {
        if (lease == null)
        {
            EditorGUILayout.LabelField("Lease", "Not acquired");
            return;
        }

        bool active = lease.IsActive;
        EditorGUILayout.LabelField("Lease", active ? "Active" : "Inactive");
        EditorGUILayout.LabelField(
            "IsSafeToOpen",
            GameplayModalInputGate.IsSafeToOpen(lease) ? "YES" : "NO");

        if (leasedOwner != null)
            EditorGUILayout.LabelField("Lease owner", leasedOwner.name);

    }

    private void AcquireOwner(
        string label,
        MonoBehaviour owner,
        ref MonoBehaviour leasedOwner,
        ref GameplayModalInputGate.GameplayModalLease lease)
    {
        if (!GameplayModalInputGate.TryAcquireBlockingModal(
                owner,
                out GameplayModalInputGate.GameplayModalLease acquiredLease))
        {
            lastAction = label + " acquisition was rejected by the gate.";
            RefreshGateState();
            return;
        }

        leasedOwner = owner;
        lease = acquiredLease;
        lastAction = label + " lease acquired or returned idempotently.";
        RefreshGateState();
    }

    private void ReleaseOwner(
        string label,
        GameplayModalInputGate.GameplayModalLease lease)
    {
        lease.Dispose();
        lastAction = label + " lease disposed.";
        RefreshGateState();
    }

    private void TestDuplicateOwnerAAcquisition()
    {
        if (leasedOwnerA == null || leaseA == null || !leaseA.IsActive)
            return;

        bool acquired = GameplayModalInputGate.TryAcquireBlockingModal(
            leasedOwnerA,
            out GameplayModalInputGate.GameplayModalLease duplicateLease);
        bool sameLease = acquired && ReferenceEquals(leaseA, duplicateLease);

        lastAction = sameLease
            ? "Owner A duplicate acquisition returned the same lease (PASS)."
            : "Owner A duplicate acquisition did not return the held lease (FAIL).";
        RefreshGateState();
    }

    private void RefreshGateState()
    {
        isBlocked = GameplayModalInputGate.IsGameplayInputBlocked;
    }

    private void SubscribeToGateEvents()
    {
        if (isSubscribed || !EditorApplication.isPlaying)
            return;

        GameplayModalInputGate.BlockingStateChanged += HandleBlockingStateChanged;
        GameplayModalInputGate.SafeBoundaryReached += HandleSafeBoundaryReached;
        isSubscribed = true;
        RefreshGateState();
    }

    private void UnsubscribeFromGateEvents()
    {
        if (!isSubscribed)
            return;

        GameplayModalInputGate.BlockingStateChanged -= HandleBlockingStateChanged;
        GameplayModalInputGate.SafeBoundaryReached -= HandleSafeBoundaryReached;
        isSubscribed = false;
    }

    private void HandleBlockingStateChanged()
    {
        AddEvent("BlockingStateChanged; blocked=" +
                 GameplayModalInputGate.IsGameplayInputBlocked);
    }

    private void HandleSafeBoundaryReached()
    {
        AddEvent("SafeBoundaryReached");
    }

    private void AddEvent(string eventName)
    {
        eventHistory.Add(DateTime.Now.ToString("HH:mm:ss") + " " + eventName);
        if (eventHistory.Count > EventHistoryLimit)
            eventHistory.RemoveAt(0);

        RefreshGateState();
        Repaint();
    }

    private void HandlePlayModeStateChanged(PlayModeStateChange state)
    {
        if (state == PlayModeStateChange.EnteredPlayMode)
        {
            eventHistory.Clear();
            lastAction = "No diagnostic action performed.";
            SubscribeToGateEvents();
            return;
        }

        if (state == PlayModeStateChange.ExitingPlayMode ||
            state == PlayModeStateChange.EnteredEditMode)
        {
            UnsubscribeFromGateEvents();
            leaseA = null;
            leaseB = null;
            leasedOwnerA = null;
            leasedOwnerB = null;
            isBlocked = false;
            Repaint();
        }
    }

    private static bool IsValidOwner(MonoBehaviour owner)
    {
        return owner != null && owner.isActiveAndEnabled;
    }
}
#endif
