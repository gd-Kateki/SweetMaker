using UnityEngine;
using UnityEngine.UI;

public class UpgradeScreenUI : MonoBehaviour
{
    [Header("References")]
    [SerializeField]
    private GameObject upgradeScreen;

    [SerializeField]
    private Button openButton;

    [SerializeField]
    private Button closeButton;

    [SerializeField]
    private SpawnPoolSelectorUI spawnPoolSelector;

    private GameplayModalInputGate.GameplayModalLease gameplayModalLease;
    private bool selectorVisibilityOverridden;
    private bool selectorWasVisible;

    private void Awake()
    {
        if (openButton != null)
        {
            openButton.onClick.AddListener(
                HandleOpenClicked
            );
        }

        if (closeButton != null)
        {
            closeButton.onClick.AddListener(
                HandleCloseClicked
            );
        }

        Close();
    }

    private void OnDestroy()
    {
        RestoreSpawnPoolSelector();
        ReleaseGameplayModalLease();

        if (openButton != null)
        {
            openButton.onClick.RemoveListener(
                HandleOpenClicked
            );
        }

        if (closeButton != null)
        {
            closeButton.onClick.RemoveListener(
                HandleCloseClicked
            );
        }
    }

    private void OnDisable()
    {
        Close();
    }

    private void LateUpdate()
    {
        if (selectorVisibilityOverridden &&
            (upgradeScreen == null || !upgradeScreen.activeInHierarchy))
        {
            RestoreSpawnPoolSelector();
            ReleaseGameplayModalLease();
        }
    }

    private void HandleOpenClicked()
    {
        if (upgradeScreen == null || upgradeScreen.activeSelf)
            return;

        UiClickSfx.TryPlay(openButton);
        Open();
    }

    private void HandleCloseClicked()
    {
        if (upgradeScreen == null || !upgradeScreen.activeSelf)
            return;

        UiClickSfx.TryPlay(closeButton);
        Close();
    }

    public void Open()
    {
        if (upgradeScreen == null)
            return;

        if (upgradeScreen.activeSelf)
            return;

        bool noIncompatibleModal =
            !GameplayModalInputGate.IsGameplayInputBlocked;
        if (!GameplayModalInputGate.TryAcquireBlockingModal(
                this,
                out gameplayModalLease))
        {
            Debug.LogError(
                "UPGRADE SCREEN | Could not acquire the gameplay modal input gate.",
                this);
            return;
        }

        HideSpawnPoolSelector();
        upgradeScreen.transform.SetAsLastSibling();
        upgradeScreen.SetActive(true);
        FeatureIntroductionPopup.TryShowForFeatureFrom(
            this,
            FeatureIntroduction.Upgrades,
            noIncompatibleModal);

        Debug.Log(
            "UPGRADE SCREEN | Opened"
        );
    }

    public void Close()
    {
        if (upgradeScreen != null)
            upgradeScreen.SetActive(false);

        RestoreSpawnPoolSelector();
        ReleaseGameplayModalLease();

        Debug.Log(
            "UPGRADE SCREEN | Closed"
        );
    }

    private void ReleaseGameplayModalLease()
    {
        if (gameplayModalLease == null)
            return;

        gameplayModalLease.Dispose();
        gameplayModalLease = null;
    }

    private void HideSpawnPoolSelector()
    {
        if (spawnPoolSelector == null)
            return;

        if (!selectorVisibilityOverridden)
        {
            selectorWasVisible = spawnPoolSelector.ControlsVisible;
            selectorVisibilityOverridden = true;
        }

        spawnPoolSelector.SetControlsVisible(false);
    }

    private void RestoreSpawnPoolSelector()
    {
        if (!selectorVisibilityOverridden)
            return;

        if (spawnPoolSelector != null)
            spawnPoolSelector.SetControlsVisible(selectorWasVisible);

        selectorVisibilityOverridden = false;
    }
}