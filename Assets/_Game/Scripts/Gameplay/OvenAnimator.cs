using System.Collections;
using UnityEngine;

public class OvenAnimator : MonoBehaviour
{
    [Header("Press")]
    [SerializeField]
    private Transform visual;

    [SerializeField]
    private float pressScaleMultiplier = 0.92f;

    [SerializeField]
    private float pressDuration = 0.07f;

    [SerializeField]
    private float releaseDuration = 0.10f;

    private Coroutine animationCoroutine;

    private Vector3 baseScale;

    private void Awake()
    {
        if (visual == null)
        {
            visual = transform;
        }

        baseScale =
            visual.localScale;
    }

    public void PlayPress()
    {
        if (visual == null)
            return;

        if (animationCoroutine != null)
        {
            StopCoroutine(
                animationCoroutine
            );
        }

        visual.localScale =
            baseScale;

        animationCoroutine =
            StartCoroutine(
                PressRoutine()
            );
    }

    private IEnumerator PressRoutine()
    {
        Vector3 pressedScale =
            baseScale *
            pressScaleMultiplier;

        yield return ScaleTo(
            baseScale,
            pressedScale,
            pressDuration
        );

        yield return ScaleTo(
            pressedScale,
            baseScale,
            releaseDuration
        );

        visual.localScale =
            baseScale;

        animationCoroutine = null;
    }

    private IEnumerator ScaleTo(
        Vector3 startScale,
        Vector3 targetScale,
        float duration)
    {
        if (duration <= 0f)
        {
            visual.localScale =
                targetScale;

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

            float easedT =
                1f -
                Mathf.Pow(
                    1f - t,
                    3f
                );

            visual.localScale =
                Vector3.LerpUnclamped(
                    startScale,
                    targetScale,
                    easedT
                );

            yield return null;
        }

        visual.localScale =
            targetScale;
    }
}