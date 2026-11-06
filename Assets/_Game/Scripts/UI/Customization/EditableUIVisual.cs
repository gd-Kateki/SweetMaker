using UnityEngine;
using UnityEngine.UI;

// Present only in visual templates. The target path is captured automatically.
public sealed class EditableUIVisual : MonoBehaviour
{
    [HideInInspector] public string targetPath;
    [Tooltip("Copy this element's anchors, position and size. Leave root layout off; its placement is managed by the screen.")]
    public bool copyLayout = true;
    public bool copyVisuals = true;
    [Tooltip("Disable for gameplay icons whose sprite is supplied by the current order/item.")]
    public bool copyImageSprite = true;
    public bool copyImageColor = true;
    public bool copyButtonStyle;
    public ColorBlock buttonColors = ColorBlock.defaultColorBlock;
    public SpriteState buttonSprites;
    public Selectable.Transition buttonTransition = Selectable.Transition.ColorTint;
}
