using UnityEngine;
using UnityEngine.SceneManagement;

public class SceneNavigationManager : MonoBehaviour
{
    public static SceneNavigationManager Instance
    {
        get;
        private set;
    }

    public const string MainBakeryScene =
        "MainBakery";

    public const string MergeGameplayScene =
        "Game";

    private void Awake()
    {
        if (Instance != null &&
            Instance != this)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this;

        DontDestroyOnLoad(gameObject);
    }

    public void GoToMainBakery()
    {
        LoadScene(
            MainBakeryScene
        );
    }

    public void GoToMergeGameplay()
    {
        if (!CanEnterMergeGameplay())
            return;

        LoadScene(
            MergeGameplayScene
        );
    }

    public static bool CanEnterMergeGameplay()
    {
        var startup = GameStartupCoordinator.Instance;
        // Gameplay readiness is established inside Game; requiring it here would
        // prevent a new game or a restored persistent snapshot from entering.
        if (startup != null && startup.IsStartupComplete)
            return true;

        Debug.LogWarning(
            "SCENE | Cannot enter Game until persistent startup succeeds.");
        return false;
    }

    private void LoadScene(
        string sceneName)
    {
        if (string.IsNullOrWhiteSpace(
                sceneName))
        {
            Debug.LogError(
                "SceneNavigationManager: " +
                "Scene name is empty."
            );

            return;
        }

        if (SceneManager.GetActiveScene().name ==
            sceneName)
        {
            return;
        }

        Debug.Log(
            $"SCENE | Loading {sceneName}"
        );

        SceneManager.LoadScene(
            sceneName
        );
    }
}
