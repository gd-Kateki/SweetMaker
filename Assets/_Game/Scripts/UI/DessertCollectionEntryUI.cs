using TMPro;
using UnityEngine;
using UnityEngine.UI;

public sealed class DessertCollectionEntryUI : MonoBehaviour
{
    [SerializeField] private Image dessertIcon;
    [SerializeField] private TMP_Text tierText;
    [SerializeField] private TMP_Text nameText;
    [SerializeField] private TMP_Text stateText;

    public void Show(
        int tier,
        DessertDefinition definition,
        bool discovered)
    {
        if (tierText == null ||
            nameText == null ||
            stateText == null ||
            dessertIcon == null)
        {
            Debug.LogError(
                "DessertCollectionEntryUI is missing a serialized UI reference.",
                this);
            return;
        }

        tierText.text = $"TIER {tier}";
        if (discovered && definition != null)
        {
            dessertIcon.sprite = definition.Sprite;
            dessertIcon.enabled = definition.Sprite != null;
            nameText.text = definition.DisplayName;
            stateText.text = "DISCOVERED";
        }
        else
        {
            dessertIcon.sprite = null;
            dessertIcon.enabled = false;
            nameText.text = "Unknown dessert";
            stateText.text = "LOCKED";
        }
    }
}
