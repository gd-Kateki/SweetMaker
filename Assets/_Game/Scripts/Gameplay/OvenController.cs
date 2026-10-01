using UnityEngine;

[RequireComponent(typeof(OvenAnimator))]
public class OvenController : MonoBehaviour
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

    private void OnMouseDown()
    {
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