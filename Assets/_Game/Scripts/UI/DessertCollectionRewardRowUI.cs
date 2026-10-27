using System;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public sealed class DessertCollectionRewardRowUI : MonoBehaviour
{
    [SerializeField] private TMP_Text titleText;
    [SerializeField] private TMP_Text requirementText;
    [SerializeField] private TMP_Text amountText;
    [SerializeField] private TMP_Text statusText;
    [SerializeField] private Button claimButton;

    private int milestoneId;
    private Action<int> claimHandler;
    private bool pending;
    private bool claimBlocked;

    private void Awake()
    {
        if (claimButton == null)
        {
            Debug.LogError(
                "DessertCollectionRewardRowUI is missing its Claim button.",
                this);
            return;
        }

        claimButton.onClick.AddListener(HandleClaimClicked);
        LogClaimDiagnostic(
            $"Listener registered. Button={claimButton.name}, " +
            $"active={claimButton.gameObject.activeInHierarchy}, " +
            $"interactable={claimButton.interactable}.");
    }

    private void OnDestroy()
    {
        if (claimButton != null)
            claimButton.onClick.RemoveListener(HandleClaimClicked);
    }

    public void Bind(
        int id,
        DessertCollectionState collection,
        Action<int> onClaim)
    {
        if (collection == null)
        {
            Debug.LogError(
                "Cannot bind a reward row without collection state.",
                this);
            SetUnavailable();
            return;
        }

        milestoneId = id;
        claimHandler = onClaim;
        if (titleText != null)
            titleText.text = $"REWARD {id}";
        if (requirementText != null)
        {
            requirementText.text =
                $"{collection.GetMilestoneRequirement(id)} discoveries";
        }

        if (amountText != null)
        {
            amountText.text =
                $"${collection.GetMilestoneCashAmount(id):N0}";
        }

        Refresh(collection);
    }

    public void Refresh(DessertCollectionState collection)
    {
        if (collection == null || claimButton == null)
        {
            SetUnavailable();
            return;
        }

        bool claimed = collection.IsMilestoneClaimed(milestoneId);
        bool eligible = collection.IsMilestoneEligible(milestoneId);
        if (statusText != null)
        {
            statusText.text = claimHandler == null
                ? "UNAVAILABLE"
                : claimBlocked
                ? "RELOAD REQUIRED"
                : claimed
                ? "CLAIMED"
                : eligible
                    ? pending ? "CLAIMING..." : "CLAIMABLE"
                    : "LOCKED";
        }

        claimButton.interactable =
            !pending && !claimBlocked && !claimed && eligible &&
            claimHandler != null;
        LogClaimDiagnostic(
            $"Refreshed milestone={milestoneId}, eligible={eligible}, " +
            $"claimed={claimed}, pending={pending}, blocked={claimBlocked}, " +
            $"handlerAssigned={claimHandler != null}, " +
            $"buttonInteractable={claimButton.interactable}.");
    }

    public void SetClaimBlocked(DessertCollectionState collection)
    {
        claimBlocked = true;
        Refresh(collection);
    }

    public void SetPending(
        bool isPending,
        DessertCollectionState collection)
    {
        pending = isPending;
        Refresh(collection);
    }

    private void HandleClaimClicked()
    {
        LogClaimDiagnostic(
            $"Button click received. Milestone={milestoneId}, " +
            $"pending={pending}, handlerAssigned={claimHandler != null}.");

        if (pending)
        {
            LogClaimDiagnostic(
                $"Click ignored because milestone {milestoneId} is pending.");
            return;
        }

        if (claimHandler == null)
        {
            LogClaimDiagnostic(
                $"Click ignored because milestone {milestoneId} has no " +
                "controller callback.");
            return;
        }

        LogClaimDiagnostic(
            $"Invoking controller callback for milestone {milestoneId}.");
        claimHandler(milestoneId);
    }

    private void SetUnavailable()
    {
        if (statusText != null)
            statusText.text = "UNAVAILABLE";
        if (claimButton != null)
            claimButton.interactable = false;
    }

    private void LogClaimDiagnostic(string message)
    {
#if UNITY_EDITOR || DEVELOPMENT_BUILD
        Debug.Log(
            $"COLLECTION CLAIM UI | {message}",
            this);
#endif
    }
}
