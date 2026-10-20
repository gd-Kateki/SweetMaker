using UnityEngine;
using UnityEngine.EventSystems;

[RequireComponent(typeof(OvenAnimator))]
public class OvenController : MonoBehaviour, IPointerDownHandler
{
    [Header("References")]
    [SerializeField]
    private OvenManager ovenManager;

    private OvenAnimator ovenAnimator;

    private void Awake()
    {
        ovenAnimator =
            GetComponent<OvenAnimator>();
    }

    public void OnPointerDown(PointerEventData eventData)
    {
        if (eventData.button != PointerEventData.InputButton.Left)
        {
            return;
        }

        if (ovenManager == null)
        {
            Debug.LogError(
                "OvenController: OvenManager " +
                "is not assigned."
            );

            return;
        }

        if (!ovenManager.CanUseOven)
        {
            return;
        }

        if (ovenAnimator != null)
        {
            ovenAnimator.PlayPress();
        }

        ovenManager.RequestSpawn();
    }
}