using TMPro;
using UnityEngine;
using UnityEngine.UI;

public sealed class CafeProgressionHudUI : MonoBehaviour
{
    [SerializeField]
    private PlayerProgressionManager progressionManager;

    [SerializeField]
    private TMP_Text titleText;

    [SerializeField]
    private Image[] starImages = new Image[CafeProgressionCatalog.MaximumRegularStarLevel];

    [SerializeField]
    private Sprite filledStarSprite;

    [SerializeField]
    private Sprite outlineStarSprite;

    private bool missingManagerReported;

    private void OnEnable()
    {
        BindProgressionManager();
        Refresh();
    }

    private void Start()
    {
        BindProgressionManager();
        Refresh();
    }

    private void OnDisable()
    {
        UnbindProgressionManager();
    }

    private void OnDestroy()
    {
        UnbindProgressionManager();
    }

    private void BindProgressionManager()
    {
        PlayerProgressionManager current =
            PlayerProgressionManager.Instance;
        if (current == null)
            current = progressionManager;
        if (current == null)
            current = FindFirstObjectByType<PlayerProgressionManager>();

        if (current == progressionManager &&
            progressionManager != null &&
            IsBound)
        {
            return;
        }

        UnbindProgressionManager();
        progressionManager = current;
        if (progressionManager == null)
        {
            if (!missingManagerReported)
            {
                Debug.LogError(
                    "CafeProgressionHudUI: PlayerProgressionManager is unavailable.",
                    this);
                missingManagerReported = true;
            }

            RefreshUnavailable();
            return;
        }

        missingManagerReported = false;
        progressionManager.RebirthProgressionChanged += Refresh;
        IsBound = true;
    }

    private void UnbindProgressionManager()
    {
        if (progressionManager != null && IsBound)
            progressionManager.RebirthProgressionChanged -= Refresh;

        IsBound = false;
    }

    private bool IsBound { get; set; }

    public void Refresh()
    {
        if (progressionManager == null)
        {
            RefreshUnavailable();
            return;
        }

        if (progressionManager.TryGetCafeTitle(out string cafeTitle))
        {
            if (titleText != null)
            {
                titleText.text = cafeTitle;
                titleText.color = GetTitleColor(cafeTitle);
            }
        }
        else if (titleText != null)
        {
            titleText.text = string.Empty;
        }

        bool starsAvailable = progressionManager.TryGetCafeStarLevel(out int starLevel);
        RenderStars(starsAvailable, starLevel);
    }

    private void RefreshUnavailable()
    {
        if (titleText != null)
            titleText.text = string.Empty;
        RenderStars(false, 0);
    }

    private void RenderStars(bool available, int starLevel)
    {
        if (starImages == null)
            return;

        for (int i = 0; i < starImages.Length; i++)
        {
            Image star = starImages[i];
            if (star == null)
                continue;

            Sprite sprite = i < starLevel ? filledStarSprite : outlineStarSprite;
            star.sprite = sprite;
            star.enabled = available && sprite != null &&
                i < CafeProgressionCatalog.MaximumRegularStarLevel;
        }
    }

    // Presentation only: the catalog remains authoritative for titles and progression.
    private static Color32 GetTitleColor(string cafeTitle)
    {
        switch (cafeTitle)
        {
            case "Humble Beginnings": return new Color32(255, 241, 207, 255);
            case "Aspiring Baker": return new Color32(255, 196, 154, 255);
            case "Sweet Apprentice": return new Color32(243, 245, 138, 255);
            case "Rising Cafe": return new Color32(151, 244, 195, 255);
            case "Neighborhood Favorite": return new Color32(157, 220, 255, 255);
            case "Established Cafe": return new Color32(255, 209, 102, 255);
            case "Celebrated Baker": return new Color32(255, 173, 173, 255);
            case "Renowned Cafe": return new Color32(255, 181, 222, 255);
            case "Dessert Artisan": return new Color32(136, 238, 232, 255);
            case "Master of Sweets": return new Color32(206, 242, 141, 255);
            case "Legendary Cafe": return new Color32(233, 237, 255, 255);
            default: return new Color32(255, 255, 255, 255);
        }
    }
}
