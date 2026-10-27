using UnityEngine;
using UnityEngine.EventSystems;

public sealed class SettingsOverlayCancelHandler :
    MonoBehaviour,
    ICancelHandler
{
    [SerializeField] private SettingsUI settingsUI;

    public void OnCancel(BaseEventData eventData)
    {
        if (settingsUI != null &&
            settingsUI.IsOpenOrWaitingForSafeGameplayBoundary)
        {
            settingsUI.Close();
        }
    }
}
