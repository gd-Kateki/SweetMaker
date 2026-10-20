using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class PlayButtonUI : MonoBehaviour
{
    [SerializeField]
    private Button playButton;

    private void Awake()
    {
        if (playButton == null)
        {
            playButton = GetComponent<Button>();
        }

        if (playButton != null)
        {
            playButton.onClick.AddListener(
                HandlePlayClicked
            );
        }
    }

    private void OnDestroy()
    {
        if (playButton != null)
        {
            playButton.onClick.RemoveListener(
                HandlePlayClicked
            );
        }
    }

    private void HandlePlayClicked()
    {
        if (SceneNavigationManager.Instance != null)
        {
            SceneNavigationManager.Instance
                .GoToMergeGameplay();

            return;
        }

        // Direct-scene/editor fallback.
        if (!SceneNavigationManager.CanEnterMergeGameplay())
            return;

        SceneManager.LoadScene(
            SceneNavigationManager
                .MergeGameplayScene
        );
    }
}
