using TMPro;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

public sealed class RecycleConfirmationController :
    MonoBehaviour,
    ICancelHandler
{
    private sealed class PendingRecycle
    {
        public Dessert Dessert;
        public DessertDragHandler DragHandler;
        public GridCell OriginCell;
        public ShelfSlot OriginShelfSlot;
        public bool IsTerminal;
    }

    [SerializeField] private GameObject overlayRoot;
    [SerializeField] private Button cancelButton;
    [SerializeField] private Button recycleButton;
    [SerializeField] private TMP_Text titleLabel;
    [SerializeField] private TMP_Text bodyLabel;

    private PendingRecycle pending;
    private GameplayModalInputGate.GameplayModalLease gameplayModalLease;
    private bool waitingForSafeBoundary;
    private GameObject previousSelectedObject;
    private GridManager gridManager;
    private ShelfManager shelfManager;

    public bool IsOpenOrWaiting =>
        pending != null &&
        !pending.IsTerminal &&
        (waitingForSafeBoundary ||
         (overlayRoot != null && overlayRoot.activeSelf));

    private void Awake()
    {
        ResolveReferences();
        if (titleLabel != null)
            titleLabel.text = "Recycle Dessert?";
        if (bodyLabel != null)
        {
            bodyLabel.text =
                "Are you sure you want to recycle this dessert? " +
                "This action cannot be undone.";
        }
    }

    private void OnEnable()
    {
        if (cancelButton != null)
            cancelButton.onClick.AddListener(CancelPending);
        if (recycleButton != null)
            recycleButton.onClick.AddListener(ConfirmPending);
    }

    private void OnDisable()
    {
        if (cancelButton != null)
            cancelButton.onClick.RemoveListener(CancelPending);
        if (recycleButton != null)
            recycleButton.onClick.RemoveListener(ConfirmPending);
        CancelPending();
    }

    private void OnDestroy()
    {
        CancelPending();
    }

    private void OnApplicationPause(bool isPaused)
    {
        if (isPaused)
            CancelPending();
    }

    private void OnApplicationFocus(bool hasFocus)
    {
        if (!hasFocus)
            CancelPending();
    }

    public bool TryBeginPendingRecycle(
        DessertDragHandler dragHandler,
        Dessert dessert,
        GridCell originCell,
        ShelfSlot originShelfSlot)
    {
        if (pending != null ||
            dragHandler == null ||
            dessert == null ||
            ((originCell == null) == (originShelfSlot == null)))
        {
            return false;
        }

        ResolveReferences();
        if (!IsValidOwnership(dessert, originCell, originShelfSlot))
            return false;

        pending = new PendingRecycle
        {
            Dessert = dessert,
            DragHandler = dragHandler,
            OriginCell = originCell,
            OriginShelfSlot = originShelfSlot
        };
        previousSelectedObject = EventSystem.current != null
            ? EventSystem.current.currentSelectedGameObject
            : null;

        if (!GameplayModalAdmission.TryReserve(this))
        {
            CancelPending();
            return false;
        }

        if (!GameplayModalInputGate.TryAcquireBlockingModal(
                this,
                out gameplayModalLease))
        {
            CancelPending();
            return false;
        }

        if (GameplayModalInputGate.IsSafeToOpen(gameplayModalLease))
        {
            ShowOverlay();
            return true;
        }

        waitingForSafeBoundary = true;
        GameplayModalInputGate.SafeBoundaryReached -=
            HandleSafeBoundaryReached;
        GameplayModalInputGate.SafeBoundaryReached +=
            HandleSafeBoundaryReached;
        if (EventSystem.current != null)
            EventSystem.current.SetSelectedGameObject(gameObject);
        return true;
    }

    public void OnCancel(BaseEventData eventData)
    {
        if (!IsOpenOrWaiting)
            return;

        eventData?.Use();
        CancelPending();
    }

    public void ConfirmPending()
    {
        PendingRecycle transaction = pending;
        if (transaction == null ||
            transaction.IsTerminal ||
            waitingForSafeBoundary ||
            transaction.DragHandler == null ||
            !transaction.DragHandler.isActiveAndEnabled ||
            gameplayModalLease == null ||
            !gameplayModalLease.IsActive ||
            !IsValidOwnership(
                transaction.Dessert,
                transaction.OriginCell,
                transaction.OriginShelfSlot))
        {
            CancelPending();
            return;
        }

        ResolveReferences();
        if ((transaction.OriginCell != null && gridManager == null) ||
            (transaction.OriginShelfSlot != null && shelfManager == null))
        {
            Debug.LogError(
                "Recycle was canceled because its owner notification manager is unavailable.",
                this);
            CancelPending();
            return;
        }

        transaction.IsTerminal = true;
        Dessert dessert = transaction.Dessert;

        if (transaction.OriginCell != null)
        {
            transaction.OriginCell.RemoveDessert(dessert);
            if (transaction.OriginCell.CurrentDessert != null ||
                dessert.CurrentCell == transaction.OriginCell)
            {
                transaction.IsTerminal = false;
                CancelPending();
                return;
            }

        }
        else
        {
            transaction.OriginShelfSlot.RemoveDessert(dessert);
            if (transaction.OriginShelfSlot.CurrentDessert != null ||
                dessert.CurrentShelfSlot == transaction.OriginShelfSlot)
            {
                transaction.IsTerminal = false;
                CancelPending();
                return;
            }

        }

        try
        {
            if (transaction.OriginCell != null)
                gridManager.NotifyBoardChanged();
            else
                shelfManager.NotifyShelfChanged();
        }
        finally
        {
            transaction.DragHandler.CompletePendingRecycle(true);
            CloseAndRelease();
            if (Application.isPlaying)
                Destroy(dessert.gameObject);
            else
                DestroyImmediate(dessert.gameObject);
        }
    }

    public void CancelPending()
    {
        PendingRecycle transaction = pending;
        if (transaction == null || transaction.IsTerminal)
        {
            CloseAndRelease();
            return;
        }

        transaction.IsTerminal = true;
        if (transaction.DragHandler != null)
            transaction.DragHandler.CompletePendingRecycle(false);
        CloseAndRelease();
    }

    public void CancelForSource(DessertDragHandler source)
    {
        if (pending != null &&
            !pending.IsTerminal &&
            pending.DragHandler == source)
        {
            CancelPending();
        }
    }

    private void HandleSafeBoundaryReached()
    {
        if (!waitingForSafeBoundary)
            return;

        if (pending == null ||
            pending.IsTerminal ||
            gameplayModalLease == null ||
            !gameplayModalLease.IsActive ||
            !GameplayModalInputGate.IsSafeToOpen(gameplayModalLease))
        {
            CancelPending();
            return;
        }

        waitingForSafeBoundary = false;
        GameplayModalInputGate.SafeBoundaryReached -=
            HandleSafeBoundaryReached;
        ShowOverlay();
    }

    private void ShowOverlay()
    {
        if (pending == null ||
            pending.IsTerminal ||
            overlayRoot == null ||
            !IsValidOwnership(
                pending.Dessert,
                pending.OriginCell,
                pending.OriginShelfSlot))
        {
            if (overlayRoot == null)
            {
                Debug.LogError(
                    "Recycle confirmation overlay is not assigned.",
                    this);
            }
            CancelPending();
            return;
        }

        overlayRoot.SetActive(true);
        if (cancelButton != null && EventSystem.current != null)
            EventSystem.current.SetSelectedGameObject(cancelButton.gameObject);
    }

    private void CloseAndRelease()
    {
        if (overlayRoot != null)
            overlayRoot.SetActive(false);

        waitingForSafeBoundary = false;
        GameplayModalInputGate.SafeBoundaryReached -=
            HandleSafeBoundaryReached;
        gameplayModalLease?.Dispose();
        gameplayModalLease = null;
        GameplayModalAdmission.Release(this);
        pending = null;
        if (EventSystem.current != null)
        {
            EventSystem.current.SetSelectedGameObject(
                previousSelectedObject != null &&
                previousSelectedObject.activeInHierarchy
                    ? previousSelectedObject
                    : null);
        }
        previousSelectedObject = null;
    }

    private bool IsValidOwnership(
        Dessert dessert,
        GridCell originCell,
        ShelfSlot originShelfSlot)
    {
        if (dessert == null)
            return false;

        if (originCell != null)
        {
            if (!originCell.isActiveAndEnabled ||
                originCell.CurrentDessert != dessert ||
                dessert.CurrentCell != originCell ||
                dessert.CurrentShelfSlot != null)
            {
                return false;
            }

            return true;
        }

        return originShelfSlot != null &&
               originShelfSlot.isActiveAndEnabled &&
               originShelfSlot.CurrentDessert == dessert &&
               dessert.CurrentShelfSlot == originShelfSlot &&
               dessert.CurrentCell == null;
    }

    private void ResolveReferences()
    {
        if (gridManager == null)
            gridManager = FindAnyObjectByType<GridManager>();
        if (shelfManager == null)
            shelfManager = FindAnyObjectByType<ShelfManager>();
    }
}
