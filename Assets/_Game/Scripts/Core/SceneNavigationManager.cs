using UnityEngine;
using UnityEngine.SceneManagement;
using SweetMerge.Advertising;

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
        if (GetComponent<AutomaticInterstitialScheduler>() == null)
            gameObject.AddComponent<AutomaticInterstitialScheduler>();
    }

    public void GoToMainBakery()
    {
        AutomaticInterstitialScheduler scheduler =
            AutomaticInterstitialScheduler.Instance;
        if (scheduler != null)
        {
            scheduler.NavigateToHome(
                () => LoadScene(MainBakeryScene));
            return;
        }

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
            applicationReadiness.IsReady)
            return true;

        Debug.LogWarning(
            "SCENE | Cannot enter Game until application readiness succeeds.");
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
