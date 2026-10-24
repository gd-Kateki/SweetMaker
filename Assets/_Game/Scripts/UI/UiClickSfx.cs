using UnityEngine.UI;

internal static class UiClickSfx
{
    internal static bool TryPlay(Button button)
    {
        if (button == null ||
            !button.isActiveAndEnabled ||
            !button.IsInteractable())
        {
            return false;
        }

        return AudioManager.TryPlay(SfxId.UI_Click);
    }
}
