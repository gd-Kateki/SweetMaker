
using UnityEngine;
using UnityEngine.UI;

public class HomeButtonUI : MonoBehaviour
{
    // ==================================================
    // REFERENCES
    // ==================================================

    [SerializeField]
    private Button homeButton;

    // ==================================================
    // STATE
    // ==================================================

    private bool isNavigating;

    // ==================================================
    // UNITY
    // ==================================================

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
        else
        {
            Debug.LogError(
                "HOME | Home Button reference " +
                "is missing."
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

    // ==================================================
    // HOME BUTTON
    // ==================================================

    private void HandleHomeClicked()
    {
        // ------------------------------------------
        // PREVENT DUPLICATE NAVIGATION
        // ------------------------------------------

        if (isNavigating)
        {
            return;
        }

        // ------------------------------------------
        // VALIDATE SAVE MANAGER
        // ------------------------------------------

        SaveManager saveManager =
            SaveManager.Instance;

        if (saveManager == null)
        {
            Debug.LogError(
                "HOME | Cannot return to MainBakery. " +
                "SaveManager is unavailable."
            );

            return;
        }

        // ------------------------------------------
        // VALIDATE NAVIGATION MANAGER
        // ------------------------------------------

        SceneNavigationManager navigationManager =
            SceneNavigationManager.Instance;

        if (navigationManager == null)
        {
            Debug.LogError(
                "HOME | Cannot return to MainBakery. " +
                "SceneNavigationManager is unavailable."
            );

            return;
        }

        // ------------------------------------------
        // SAVE CURRENT GAME
        // ------------------------------------------

        Debug.Log(
            "HOME | Saving current game " +
            "before returning to MainBakery."
        );

        bool saveSucceeded =
            saveManager.SaveCurrentGame();

        if (!saveSucceeded)
        {
            Debug.LogError(
                "HOME | Save failed. " +
                "Remaining in Game to protect progress."
            );

            return;
        }

        // ------------------------------------------
        // NAVIGATE TO MAIN BAKERY
        // ------------------------------------------

        UiClickSfx.TryPlay(homeButton);
        isNavigating = true;

        if (homeButton != null)
        {
            homeButton.interactable = false;
        }

        Debug.Log(
            "HOME | Save successful. " +
            "Returning to MainBakery."
        );

        navigationManager.GoToMainBakery();
    }
}
