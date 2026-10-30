using TMPro;
using UnityEngine;

public sealed class CafeProgressionHudUI : MonoBehaviour
{
    [SerializeField]
    private PlayerProgressionManager progressionManager;

    [SerializeField]
    private TMP_Text titleText;

    [SerializeField]
    private TMP_Text starText;

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
                titleText.text = cafeTitle;
        }
        else if (titleText != null)
        {
            titleText.text = string.Empty;
        }

        if (progressionManager.TryGetCafeStarLevel(out int starLevel))
        {
            if (starText != null)
                starText.text =
                    $"{starLevel}/{CafeProgressionCatalog.MaximumRegularStarLevel}";
        }
        else if (starText != null)
        {
            starText.text = string.Empty;
        }
    }

    private void RefreshUnavailable()
    {
        if (titleText != null)
            titleText.text = string.Empty;
        if (starText != null)
            starText.text = string.Empty;
    }
}
