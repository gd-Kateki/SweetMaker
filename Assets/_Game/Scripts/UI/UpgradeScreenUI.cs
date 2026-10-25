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
        RestoreSpawnPoolSelector();
    }

    private void LateUpdate()
    {
        if (selectorVisibilityOverridden &&
            (upgradeScreen == null || !upgradeScreen.activeInHierarchy))
        {
            RestoreSpawnPoolSelector();
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

        HideSpawnPoolSelector();
        upgradeScreen.SetActive(
            true
        );

        Debug.Log(
            "UPGRADE SCREEN | Opened"
        );
    }

    public void Close()
    {
        if (upgradeScreen != null)
            upgradeScreen.SetActive(false);

        RestoreSpawnPoolSelector();

        Debug.Log(
            "UPGRADE SCREEN | Closed"
        );
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