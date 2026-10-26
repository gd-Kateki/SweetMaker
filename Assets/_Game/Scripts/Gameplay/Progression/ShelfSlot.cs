using UnityEngine;

public class ShelfSlot : MonoBehaviour
{
    [Header("Visual")]
    [SerializeField]
    private SpriteRenderer slotRenderer;

    [SerializeField]
    private Color unlockedColor =
        Color.white;

    [SerializeField]
    private Color lockedColor =
        new Color(
            0.38f,
            0.29f,
            0.22f,
            1f
        );

    private static readonly Color OccupiedColor =
        new Color32(255, 213, 139, 255);

    [SerializeField]
    private Color validColor =
        Color.green;

    [SerializeField]
    private Color invalidColor =
        Color.red;

    private Dessert currentDessert;
    private bool isUnlocked;

    public bool IsUnlocked =>
        isUnlocked;

    public bool IsEmpty =>
        currentDessert == null;

    public bool IsAvailable =>
        isUnlocked &&
        IsEmpty;

    public Dessert CurrentDessert =>
        currentDessert;

    public Vector3 ContentPosition
    {
        get
        {
            Vector3 position =
                transform.position;

            position.z = 0f;

            return position;
        }
    }

    private void Awake()
    {
        ResolveReferences();
        RefreshVisualState();
    }

    private void ResolveReferences()
    {
        if (slotRenderer == null)
        {
            slotRenderer =
                GetComponent<SpriteRenderer>();
        }
    }

    // --------------------------------------------------
    // PROGRESSION
    // --------------------------------------------------

    public void SetUnlocked(
        bool unlocked)
    {
        if (!unlocked &&
            currentDessert != null)
        {
            Debug.LogWarning(
                $"{name}: Cannot lock " +
                "an occupied Shelf slot."
            );

            return;
        }

        isUnlocked =
            unlocked;

        RefreshVisualState();
    }

    // --------------------------------------------------
    // STORAGE
    // --------------------------------------------------

    public bool TryStoreDessert(
        Dessert dessert,
        bool snapToSlot = true)
    {
        if (dessert == null)
            return false;

        if (!IsAvailable)
            return false;

        currentDessert =
            dessert;

        dessert.SetCurrentShelfSlot(
            this
        );

        if (snapToSlot)
        {
            dessert.transform.position =
                ContentPosition;
        }

        dessert.ApplyNormalRendering();

        RefreshVisualState();

        return true;
    }

    public void RemoveDessert(
        Dessert dessert)
    {
        if (currentDessert != dessert)
            return;

        currentDessert =
            null;

        if (dessert != null &&
            dessert.CurrentShelfSlot == this)
        {
            dessert.SetCurrentShelfSlot(
                null
            );
        }

        RefreshVisualState();
    }

    // --------------------------------------------------
    // HIGHLIGHT
    // --------------------------------------------------

    public void ShowValidHighlight()
    {
        if (!isUnlocked)
            return;

        SetColor(
            validColor
        );
    }

    public void ShowInvalidHighlight()
    {
        if (!isUnlocked)
            return;

        SetColor(
            invalidColor
        );
    }

    public void ClearHighlight()
    {
        RefreshVisualState();
    }

    private void RefreshVisualState()
    {
        if (isUnlocked)
        {
            SetColor(currentDessert != null
                ? OccupiedColor
                : unlockedColor);
        }
        else
        {
            SetColor(
                lockedColor
            );
        }
    }

    private void SetColor(
        Color color)
    {
        if (slotRenderer != null)
        {
            slotRenderer.color =
                color;
        }
    }
}