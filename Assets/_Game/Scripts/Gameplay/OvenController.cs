using UnityEngine;

public class OvenController : MonoBehaviour
{
    [Header("References")]
    [SerializeField]
    private OvenManager ovenManager;

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

        ovenManager.RequestSpawn();
    }
}