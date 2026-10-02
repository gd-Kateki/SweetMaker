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

    private void Awake()
    {
        if (openButton != null)
        {
            openButton.onClick.AddListener(
                Open
            );
        }

        if (closeButton != null)
        {
            closeButton.onClick.AddListener(
                Close
            );
        }

        Close();
    }

    private void OnDestroy()
    {
        if (openButton != null)
        {
            openButton.onClick.RemoveListener(
                Open
            );
        }

        if (closeButton != null)
        {
            closeButton.onClick.RemoveListener(
                Close
            );
        }
    }

    public void Open()
    {
        if (upgradeScreen == null)
            return;

        upgradeScreen.SetActive(
            true
        );

        Debug.Log(
            "UPGRADE SCREEN | Opened"
        );
    }

    public void Close()
    {
        if (upgradeScreen == null)
            return;

        upgradeScreen.SetActive(
            false
        );

        Debug.Log(
            "UPGRADE SCREEN | Closed"
        );
    }
}