using System;
using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;

public class DessertAnimator : MonoBehaviour
{
    [Header("Movement")]
    [SerializeField]
    private float moveDuration = 0.12f;

    [Header("Merge")]
    [SerializeField]
    private float mergeMoveDuration = 0.10f;

    [SerializeField]
    private float mergeSquishMultiplier = 0.85f;

    [Header("Merge Pop")]
    [SerializeField]
    private float mergePopMultiplier = 1.25f;

    [SerializeField]
    private float mergePopDuration = 0.15f;

    [Header("Spawn Pop")]
    [SerializeField]
    private float spawnStartMultiplier = 0.65f;

    [SerializeField]
    private float spawnPopMultiplier = 1.12f;

    [SerializeField]
    private float spawnPopDuration = 0.18f;

    private Coroutine movementCoroutine;
    private Coroutine scaleCoroutine;
    private SettingsManager subscribedSettingsManager;
    private Transform scaleVisual;
    private DessertDefinition scaleDefinition;
    private Vector3 stableVisualScale;
    private Vector3 movementTargetPosition;
    private Dessert movementDessert;
    private bool movementHadDessertOwner;
    private GridCell movementCell;
    private ShelfSlot movementShelfSlot;
    private Transform movementParent;
    private Action movementCompletion;
    private bool reduceAnimations;

    public void MoveTo(
        Vector3 targetPosition)
    {
        TryBindSettingsManager();
        StopMovement();
        targetPosition.z = 0f;

        if (reduceAnimations || moveDuration <= 0f)
        {
            transform.position = targetPosition;
            return;
        }

        BeginMovement(targetPosition, moveDuration, null);
    }

    public void MoveToForMerge(
        Vector3 targetPosition,
        Action onComplete)
    {
        TryBindSettingsManager();
        StopMovement();
        targetPosition.z = 0f;

        if (reduceAnimations || mergeMoveDuration <= 0f)
        {
            transform.position = targetPosition;
            onComplete?.Invoke();
            return;
        }

        BeginMovement(targetPosition, mergeMoveDuration, onComplete);
    }

    public void PlayMergeSquish()
    {
        TryBindSettingsManager();
        if (!TryGetScaleVisual(out Transform visual))
            return;

        StopScaleAnimation(true);
        if (reduceAnimations ||
            mergeMoveDuration * 0.5f <= 0f)
        {
            return;
        }

        scaleCoroutine =
            StartCoroutine(
                MergeSquishRoutine(
                    visual,
                    stableVisualScale));
    }

    public void PlayMergePop()
    {
        TryBindSettingsManager();
        if (!TryGetScaleVisual(out Transform visual))
            return;

        StopScaleAnimation(true);
        if (reduceAnimations || mergePopDuration <= 0f)
        {
            return;
        }

        scaleCoroutine =
            StartCoroutine(
                MergePopRoutine(
                    visual,
                    stableVisualScale));
    }

    public void PlaySpawnPop()
    {
        TryBindSettingsManager();
        if (!TryGetScaleVisual(out Transform visual))
            return;

        StopScaleAnimation(true);
        if (reduceAnimations || spawnPopDuration <= 0f)
        {
            return;
        }

        scaleCoroutine =
            StartCoroutine(
                SpawnPopRoutine(
                    visual,
                    stableVisualScale));
    }

    private void StopMovement()
    {
        CancelMovement(false);
    }

    private void BeginMovement(
        Vector3 targetPosition,
        float duration,
        Action onComplete)
    {
        movementTargetPosition = targetPosition;
        movementCompletion = onComplete;
        movementDessert = GetComponent<Dessert>();
        movementHadDessertOwner = movementDessert != null;
        movementCell = movementDessert != null
            ? movementDessert.CurrentCell
            : null;
        movementShelfSlot = movementDessert != null
            ? movementDessert.CurrentShelfSlot
            : null;
        movementParent = transform.parent;

        movementCoroutine =
            StartCoroutine(
                MoveRoutine(
                    targetPosition,
                    duration,
                    movementDessert,
                    movementHadDessertOwner,
                    movementCell,
                    movementShelfSlot,
                    movementParent,
                    onComplete));
    }

    private IEnumerator MoveRoutine(
        Vector3 targetPosition,
        float duration,
        Dessert owner,
        bool hadDessertOwner,
        GridCell cell,
        ShelfSlot shelfSlot,
        Transform parent,
        Action onComplete)
    {
        Vector3 startPosition =
            transform.position;

        float elapsed = 0f;

        while (elapsed < duration)
        {
            if (!HasMovementOwner(
                    owner,
                    hadDessertOwner,
                    cell,
                    shelfSlot,
                    parent))
            {
                ClearMovement();
                yield break;
            }

            elapsed += Time.deltaTime;

            float t =
                Mathf.Clamp01(
                    elapsed / duration
                );

            float easedT =
                1f -
                Mathf.Pow(
                    1f - t,
                    3f
                );

            transform.position =
                Vector3.LerpUnclamped(
                    startPosition,
                    targetPosition,
                    easedT);

            yield return null;
        }

        bool ownerUnchanged =
            HasMovementOwner(
                owner,
                hadDessertOwner,
                cell,
                shelfSlot,
                parent);
        if (ownerUnchanged)
            transform.position = targetPosition;

        ClearMovement();
        if (ownerUnchanged)
            onComplete?.Invoke();
    }

    private bool HasMovementOwner(
        Dessert owner,
        bool hadDessertOwner,
        GridCell cell,
        ShelfSlot shelfSlot,
        Transform parent)
    {
        if (this == null ||
            !isActiveAndEnabled ||
            transform.parent != parent)
        {
            return false;
        }

        Dessert currentDessert = GetComponent<Dessert>();
        if (hadDessertOwner &&
            (owner == null || currentDessert == null))
        {
            return false;
        }

        return currentDessert == owner &&
               (!hadDessertOwner ||
                (owner.CurrentCell == cell &&
                 owner.CurrentShelfSlot == shelfSlot));
    }

    private void CancelMovement(bool finishAtDestination)
    {
        if (movementCoroutine == null)
            return;

        Coroutine coroutine = movementCoroutine;
        movementCoroutine = null;

        Vector3 targetPosition = movementTargetPosition;
        Dessert owner = movementDessert;
        bool hadDessertOwner = movementHadDessertOwner;
        GridCell cell = movementCell;
        ShelfSlot shelfSlot = movementShelfSlot;
        Transform parent = movementParent;
        Action completion = movementCompletion;

        ClearMovementState();
        StopCoroutine(coroutine);

        if (!finishAtDestination ||
            !HasMovementOwner(
                owner,
                hadDessertOwner,
                cell,
                shelfSlot,
                parent))
        {
            return;
        }

        transform.position = targetPosition;
        completion?.Invoke();
    }

    private void ClearMovement()
    {
        movementCoroutine = null;
        ClearMovementState();
    }

    private void ClearMovementState()
    {
        movementDessert = null;
        movementHadDessertOwner = false;
        movementCell = null;
        movementShelfSlot = null;
        movementParent = null;
        movementCompletion = null;
    }

    private IEnumerator MergeSquishRoutine(
        Transform visual,
        Vector3 normalScale)
    {
        Vector3 squishScale =
            normalScale *
            mergeSquishMultiplier;

        float halfDuration =
            mergeMoveDuration * 0.5f;

        if (halfDuration <= 0f)
        {
            if (IsCurrentScaleVisual(visual))
                visual.localScale = normalScale;

            scaleCoroutine = null;

            yield break;
        }

        float elapsed = 0f;

        while (elapsed < halfDuration)
        {
            elapsed += Time.deltaTime;

            if (!IsCurrentScaleVisual(visual))
            {
                scaleCoroutine = null;
                yield break;
            }

            float t =
                Mathf.Clamp01(
                    elapsed / halfDuration
                );

            visual.localScale =
                Vector3.Lerp(
                    normalScale,
                    squishScale,
                    t
                );

            yield return null;
        }

        elapsed = 0f;

        while (elapsed < halfDuration)
        {
            elapsed += Time.deltaTime;

            if (!IsCurrentScaleVisual(visual))
            {
                scaleCoroutine = null;
                yield break;
            }

            float t =
                Mathf.Clamp01(
                    elapsed / halfDuration
                );

            visual.localScale =
                Vector3.Lerp(
                    squishScale,
                    normalScale,
                    t
                );

            yield return null;
        }

        if (IsCurrentScaleVisual(visual))
            visual.localScale = normalScale;

        scaleCoroutine = null;
    }

    private IEnumerator MergePopRoutine(
        Transform visual,
        Vector3 normalScale)
    {
        Vector3 popScale =
            normalScale *
            mergePopMultiplier;

        visual.localScale =
            popScale;

        if (mergePopDuration <= 0f)
        {
            if (IsCurrentScaleVisual(visual))
                visual.localScale = normalScale;

            scaleCoroutine = null;

            yield break;
        }

        float elapsed = 0f;

        while (elapsed < mergePopDuration)
        {
            elapsed += Time.deltaTime;

            if (!IsCurrentScaleVisual(visual))
            {
                scaleCoroutine = null;
                yield break;
            }

            float t =
                Mathf.Clamp01(
                    elapsed /
                    mergePopDuration
                );

            float easedT =
                1f -
                Mathf.Pow(
                    1f - t,
                    3f
                );

            visual.localScale =
                Vector3.LerpUnclamped(
                    popScale,
                    normalScale,
                    easedT
                );

            yield return null;
        }

        if (IsCurrentScaleVisual(visual))
            visual.localScale = normalScale;

        scaleCoroutine = null;
    }

    private IEnumerator SpawnPopRoutine(
        Transform visual,
        Vector3 normalScale)
    {
        Vector3 startScale =
            normalScale *
            spawnStartMultiplier;

        Vector3 popScale =
            normalScale *
            spawnPopMultiplier;

        visual.localScale =
            startScale;

        float firstDuration =
            spawnPopDuration * 0.65f;

        float secondDuration =
            spawnPopDuration * 0.35f;

        if (spawnPopDuration <= 0f)
        {
            visual.localScale =
                normalScale;

            scaleCoroutine = null;

            yield break;
        }

        float elapsed = 0f;

        while (elapsed < firstDuration)
        {
            elapsed += Time.deltaTime;

            if (!IsCurrentScaleVisual(visual))
            {
                scaleCoroutine = null;
                yield break;
            }

            float t =
                Mathf.Clamp01(
                    elapsed / firstDuration
                );

            float easedT =
                1f -
                Mathf.Pow(
                    1f - t,
                    3f
                );

            visual.localScale =
                Vector3.LerpUnclamped(
                    startScale,
                    popScale,
                    easedT
                );

            yield return null;
        }

        elapsed = 0f;

        while (elapsed < secondDuration)
        {
            elapsed += Time.deltaTime;

            if (!IsCurrentScaleVisual(visual))
            {
                scaleCoroutine = null;
                yield break;
            }

            float t =
                Mathf.Clamp01(
                    elapsed / secondDuration
                );

            visual.localScale =
                Vector3.Lerp(
                    popScale,
                    normalScale,
                    t
                );

            yield return null;
        }

        if (IsCurrentScaleVisual(visual))
            visual.localScale = normalScale;

        scaleCoroutine = null;
    }

    private bool TryGetScaleVisual(out Transform visual)
    {
        Dessert dessert = GetComponent<Dessert>();
        visual = dessert != null ? dessert.Visual : null;
        if (visual == null)
            return false;

        if (scaleVisual != visual ||
            scaleDefinition != dessert.Definition)
        {
            StopScaleAnimation(false);
            scaleVisual = visual;
            scaleDefinition = dessert.Definition;
            stableVisualScale = scaleDefinition != null
                ? Vector3.one * scaleDefinition.VisualScale
                : visual.localScale;
        }

        return true;
    }

    private bool IsCurrentScaleVisual(Transform visual)
    {
        if (visual == null ||
            visual != scaleVisual ||
            !isActiveAndEnabled)
        {
            return false;
        }

        Dessert dessert = GetComponent<Dessert>();
        return dessert != null &&
               dessert.Visual == visual &&
               dessert.Definition == scaleDefinition;
    }

    private void StopScaleAnimation(bool restoreStableScale)
    {
        if (scaleCoroutine != null)
        {
            Coroutine coroutine = scaleCoroutine;
            scaleCoroutine = null;
            StopCoroutine(coroutine);
        }

        if (restoreStableScale &&
            scaleVisual != null)
        {
            scaleVisual.localScale = stableVisualScale;
        }
    }

    private void FinishPresentationAnimations()
    {
        CancelMovement(true);

        Dessert dessert = GetComponent<Dessert>();
        if (dessert != null && dessert.Visual != null)
            TryGetScaleVisual(out _);

        StopScaleAnimation(true);
    }

    private void OnEnable()
    {
        SceneManager.sceneLoaded += HandleSceneLoaded;
        TryBindSettingsManager();
    }

    private void Start()
    {
        TryBindSettingsManager();
    }

    private void OnDisable()
    {
        SceneManager.sceneLoaded -= HandleSceneLoaded;
        UnbindSettingsManager();
        CancelMovement(false);
        StopScaleAnimation(true);
    }

    private void OnDestroy()
    {
        SceneManager.sceneLoaded -= HandleSceneLoaded;
        UnbindSettingsManager();
        CancelMovement(false);
        StopScaleAnimation(false);
    }

    private void HandleSceneLoaded(
        Scene scene,
        LoadSceneMode mode)
    {
        TryBindSettingsManager();
    }

    private void TryBindSettingsManager()
    {
        SettingsManager currentManager =
            SettingsManager.Instance;

        if (subscribedSettingsManager != currentManager)
        {
            UnbindSettingsManager();
            if (currentManager != null)
            {
                subscribedSettingsManager = currentManager;
                subscribedSettingsManager.SettingsChanged +=
                    HandleSettingsChanged;
            }
        }

        if (currentManager == null ||
            currentManager.PersistenceStatus ==
                SettingsPersistenceStatus.NotInitialized)
        {
            ApplyReduceAnimations(false);
            return;
        }

        ApplySettings(currentManager.CurrentSettings);
    }

    private void UnbindSettingsManager()
    {
        if (subscribedSettingsManager != null)
        {
            subscribedSettingsManager.SettingsChanged -=
                HandleSettingsChanged;
        }

        subscribedSettingsManager = null;
    }

    private void HandleSettingsChanged(SettingsProfileData settings)
    {
        ApplySettings(settings);
    }

    private void ApplySettings(SettingsProfileData settings)
    {
        if (settings != null)
            ApplyReduceAnimations(settings.reduceAnimations);
    }

    private void ApplyReduceAnimations(bool enabled)
    {
        bool wasEnabled = reduceAnimations;
        reduceAnimations = enabled;

        if (!wasEnabled && enabled)
            FinishPresentationAnimations();
    }
}