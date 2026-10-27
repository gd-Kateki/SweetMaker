
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
        if (GameplayModalInputGate.IsGameplayInputBlocked)
            return;

        // ------------------------------------------
        // PREVENT DUPLICATE NAVIGATION
        // ------------------------------------------

        if (isNavigating)
        {
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
        // VALIDATE VERIFIED GAMEPLAY READINESS
        // ------------------------------------------

        GameStartupCoordinator startup =
            GameStartupCoordinator.Instance;
        MergeSessionController[] controllers =
            FindObjectsByType<MergeSessionController>();

        if (SaveManager.Instance == null ||
            startup == null ||
            !startup.IsStartupComplete ||
            !startup.IsGameplayReady ||
            !SaveManager.Instance.IsLifecycleSavingReady ||
            controllers.Length != 1 ||
            controllers[0] == null ||
            !controllers[0].isActiveAndEnabled ||
            !controllers[0].IsRestorationVerified)
        {
            Debug.LogError(
                "HOME | Cannot return to MainBakery. " +
                "Verified gameplay readiness or its controller is unavailable."
            );

            return;
        }

        if (!GameplayModalInputGate.TryBeginGameplayOperation(
                out GameplayModalInputGate.GameplayOperationLease operation))
        {
            return;
        }

        using (operation)
        {
            Debug.Log(
                "HOME | Preparing verified gameplay departure " +
                "before returning to MainBakery."
            );

            if (!controllers[0].PrepareToLeaveGameplay())
            {
                Debug.LogError(
                    "HOME | Gameplay departure preparation failed. " +
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
                "HOME | Verified gameplay departure prepared. " +
                "Returning to MainBakery."
            );

            navigationManager.GoToMainBakery();
        }
    }
}
