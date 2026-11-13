using UnityEngine;
using UnityEngine.UI;

// Scene-authored placement; the persistent leaderboard owns visibility and opening rules.
[RequireComponent(typeof(Button), typeof(CanvasGroup))]
public sealed class HomeLeaderboardButton : MonoBehaviour
{
    public static HomeLeaderboardButton Instance { get; private set; }
    private Button button;
    private CanvasGroup group;
    private void Awake()
    {
        Instance = this;
        button = GetComponent<Button>(); group = GetComponent<CanvasGroup>();
        SetVisible(false);
    }
    private void OnEnable() => GetComponent<Button>().onClick.AddListener(CafeLeaderboardUI.OpenFromHome);
    private void OnDisable() => GetComponent<Button>().onClick.RemoveListener(CafeLeaderboardUI.OpenFromHome);
    private void OnDestroy() { if (Instance == this) Instance = null; }
    public void SetVisible(bool visible)
    {
        if (button == null) button = GetComponent<Button>();
        if (group == null) group = GetComponent<CanvasGroup>();
        group.alpha = visible ? 1 : 0;
        group.interactable = group.blocksRaycasts = visible;
        button.interactable = visible;
    }
}
