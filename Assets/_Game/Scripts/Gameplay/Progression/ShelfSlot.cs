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
            0.25f,
            0.25f,
            0.25f,
            1f
        );

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
        if (slotRenderer == null)
        {
            slotRenderer =
                GetComponent<SpriteRenderer>();
        }

        RefreshVisualState();
    }

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

    public bool TryStoreDessert(
        Dessert dessert)
    {
        if (dessert == null)
            return false;

        if (!IsAvailable)
            return false;

        currentDessert =
            dessert;

        dessert.SetCurrentCell(
            null
        );

        dessert.transform.position =
            ContentPosition;

        dessert.ApplyNormalRendering();

        RefreshVisualState();

        return true;
    }

    public void RemoveDessert(
        Dessert dessert)
    {
        if (currentDessert != dessert)
            return;

        currentDessert = null;

        RefreshVisualState();
    }

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
            SetColor(
                unlockedColor
            );
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