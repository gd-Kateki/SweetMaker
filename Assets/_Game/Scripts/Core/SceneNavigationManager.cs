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
        LoadScene(MainBakeryScene);
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
        var applicationReadiness = ApplicationReadinessCoordinator.Instance;
        if (startup != null &&
            startup.IsStartupComplete &&
            applicationReadiness != null &&
            applicationReadiness.CanBeginGameplay)
            return true;

        Debug.LogWarning(
            "SCENE | Cannot enter Game until local startup and tutorial readiness succeed.");
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
