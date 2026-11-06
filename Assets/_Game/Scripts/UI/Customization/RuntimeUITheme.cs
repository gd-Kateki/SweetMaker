using TMPro;
using UnityEngine;

[CreateAssetMenu(menuName = "Sweet Merge/UI/Runtime UI Theme")]
public sealed class RuntimeUITheme : ScriptableObject
{
    public TMP_FontAsset font;
    public Sprite buttonSprite;
    public Sprite panelSprite;
    public bool overrideButtonColor;
    public Color buttonColor = Color.white;
    public bool overrideTextColor;
    public Color textColor = Color.white;
}
