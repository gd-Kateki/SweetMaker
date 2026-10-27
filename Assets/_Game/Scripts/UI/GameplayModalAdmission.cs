using UnityEngine;

public static class GameplayModalAdmission
{
    private static MonoBehaviour activeOwner;

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
    private static void ResetRuntimeState()
    {
        activeOwner = null;
    }

    public static bool TryReserve(MonoBehaviour owner)
    {
        ReleaseInactiveOwner();
        if (owner == null || !owner.isActiveAndEnabled)
            return false;

        if (activeOwner == owner)
            return true;

        if (activeOwner != null)
            return false;

        activeOwner = owner;
        return true;
    }

    public static bool IsReservedBy(MonoBehaviour owner)
    {
        ReleaseInactiveOwner();
        return owner != null && activeOwner == owner;
    }

    public static void Release(MonoBehaviour owner)
    {
        ReleaseInactiveOwner();
        if (owner != null && activeOwner == owner)
            activeOwner = null;
    }

    private static void ReleaseInactiveOwner()
    {
        if (activeOwner == null || !activeOwner.isActiveAndEnabled)
            activeOwner = null;
    }
}
