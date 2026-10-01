using System;
using System.Collections;
using UnityEngine;

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

    private Coroutine movementCoroutine;
    private Coroutine popCoroutine;
    private Coroutine squishCoroutine;

    public void MoveTo(
        Vector3 targetPosition)
    {
        StopMovement();

        movementCoroutine =
            StartCoroutine(
                MoveRoutine(
                    targetPosition,
                    moveDuration,
                    null
                )
            );
    }

    public void MoveToForMerge(
        Vector3 targetPosition,
        Action onComplete)
    {
        StopMovement();

        movementCoroutine =
            StartCoroutine(
                MoveRoutine(
                    targetPosition,
                    mergeMoveDuration,
                    onComplete
                )
            );
    }

    public void PlayMergeSquish()
    {
        Dessert dessert =
            GetComponent<Dessert>();

        if (dessert == null ||
            dessert.Visual == null)
        {
            return;
        }

        if (squishCoroutine != null)
        {
            StopCoroutine(
                squishCoroutine
            );
        }

        squishCoroutine =
            StartCoroutine(
                MergeSquishRoutine(
                    dessert.Visual
                )
            );
    }

    public void PlayMergePop()
    {
        Dessert dessert =
            GetComponent<Dessert>();

        if (dessert == null ||
            dessert.Visual == null)
        {
            return;
        }

        if (popCoroutine != null)
        {
            StopCoroutine(
                popCoroutine
            );
        }

        popCoroutine =
            StartCoroutine(
                MergePopRoutine(
                    dessert.Visual
                )
            );
    }

    private void StopMovement()
    {
        if (movementCoroutine == null)
            return;

        StopCoroutine(
            movementCoroutine
        );

        movementCoroutine = null;
    }

    private IEnumerator MoveRoutine(
        Vector3 targetPosition,
        float duration,
        Action onComplete)
    {
        Vector3 startPosition =
            transform.position;

        targetPosition.z = 0f;

        if (duration <= 0f)
        {
            transform.position =
                targetPosition;

            movementCoroutine = null;

            onComplete?.Invoke();

            yield break;
        }

        float elapsed = 0f;

        while (elapsed < duration)
        {
            elapsed += Time.deltaTime;

            float t =
                Mathf.Clamp01(
                    elapsed / duration
                );

            // Cubic ease-out.
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
                    easedT
                );

            yield return null;
        }

        transform.position =
            targetPosition;

        movementCoroutine = null;

        onComplete?.Invoke();
    }

    private IEnumerator MergeSquishRoutine(
        Transform visual)
    {
        Vector3 normalScale =
            visual.localScale;

        Vector3 squishScale =
            normalScale *
            mergeSquishMultiplier;

        float halfDuration =
            mergeMoveDuration * 0.5f;

        if (halfDuration <= 0f)
        {
            visual.localScale =
                normalScale;

            squishCoroutine = null;

            yield break;
        }

        float elapsed = 0f;

        while (elapsed < halfDuration)
        {
            elapsed += Time.deltaTime;

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

        visual.localScale =
            normalScale;

        squishCoroutine = null;
    }

    private IEnumerator MergePopRoutine(
        Transform visual)
    {
        Vector3 normalScale =
            visual.localScale;

        Vector3 popScale =
            normalScale *
            mergePopMultiplier;

        visual.localScale =
            popScale;

        if (mergePopDuration <= 0f)
        {
            visual.localScale =
                normalScale;

            popCoroutine = null;

            yield break;
        }

        float elapsed = 0f;

        while (elapsed < mergePopDuration)
        {
            elapsed += Time.deltaTime;

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

        visual.localScale =
            normalScale;

        popCoroutine = null;
    }
}