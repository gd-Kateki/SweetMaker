using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class OrderRequirementRowUI : MonoBehaviour
{
    [Header("References")]
    [SerializeField] private Image dessertIcon;
    [SerializeField] private TMP_Text dessertNameText;
    [SerializeField] private TMP_Text progressText;

    public void Show(
        OrderRequirement requirement,
        CustomerOrder order,
        GridManager gridManager)
    {
        if (requirement == null ||
            requirement.Dessert == null ||
            order == null ||
            gridManager == null)
        {
            Hide();
            return;
        }

        gameObject.SetActive(true);

        DessertDefinition dessert =
            requirement.Dessert;

        if (dessertIcon != null)
        {
            dessertIcon.sprite =
                dessert.Sprite;

            dessertIcon.color =
                Color.white;

            dessertIcon.enabled =
                dessert.Sprite != null;

            dessertIcon.preserveAspect =
                true;
        }

        if (dessertNameText != null)
        {
            dessertNameText.text =
                dessert.DisplayName;
        }

        int available =
            order.GetAvailableAmount(
                gridManager,
                dessert
            );

        int displayedAvailable =
            Mathf.Min(
                available,
                requirement.Amount
            );

        if (progressText != null)
        {
            progressText.text =
                $"{displayedAvailable} / " +
                $"{requirement.Amount}";
        }
    }

    public void Hide()
    {
        gameObject.SetActive(false);
    }
}