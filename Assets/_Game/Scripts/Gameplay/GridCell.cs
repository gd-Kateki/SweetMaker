using UnityEngine;

public class GridCell : MonoBehaviour
{
    [SerializeField] private Transform contentPoint;

    private Dessert currentDessert;

    public bool IsEmpty => currentDessert == null;
    public Dessert CurrentDessert => currentDessert;

    public void PlaceDessert(Dessert dessert)
    {
        if (dessert == null)
            return;

        if (!IsEmpty && currentDessert != dessert)
        {
            Debug.LogWarning($"{name} is already occupied.");
            return;
        }

        currentDessert = dessert;

        Transform target = contentPoint != null
            ? contentPoint
            : transform;

        dessert.transform.SetParent(transform);
        dessert.transform.position = target.position;

        dessert.SetCurrentCell(this);
    }

    public void RemoveDessert(Dessert dessert)
    {
        if (currentDessert != dessert)
            return;

        currentDessert = null;
    }
}