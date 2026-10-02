using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class HomeButtonUI : MonoBehaviour
{
    [SerializeField]
    private Button homeButton;

    private void Awake()
    {
        if (homeButton == null)
        {
            homeButton =
                GetComponent<Button>();
        }

        if (homeButton != null)
        {
            homeButton.onClick.AddListener(
                HandleHomeClicked
            );
        }
    }

    private void OnDestroy()
    {
        if (homeButton != null)
        {
            homeButton.onClick.RemoveListener(
                HandleHomeClicked
            );
        }
    }

    private void HandleHomeClicked()
    {
        if (SceneNavigationManager.Instance != null)
        {
            SceneNavigationManager.Instance
                .GoToMainBakery();

            return;
        }

        // Editor/direct-scene fallback.
        SceneManager.LoadScene(
            SceneNavigationManager
                .MainBakeryScene
        );
    }
}