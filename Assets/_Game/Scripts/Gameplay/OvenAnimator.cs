using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;

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
    private SettingsManager subscribedSettingsManager;
    private bool reduceAnimations;

    private void Awake()
    {
        if (visual == null)
        {
            visual = transform;
        }

        baseScale =
            visual.localScale;
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
        StopAnimation(true);
    }

    private void OnDestroy()
    {
        SceneManager.sceneLoaded -= HandleSceneLoaded;
        UnbindSettingsManager();
        StopAnimation(false);
    }

    public void PlayPress()
    {
        TryBindSettingsManager();
        if (visual == null)
            return;

        StopAnimation(false);
        visual.localScale = baseScale;
        if (reduceAnimations)
        {
            return;
        }

        if (pressDuration <= 0f &&
            releaseDuration <= 0f)
        {
            return;
        }

        animationCoroutine = StartCoroutine(
            PressRoutine(visual, baseScale));
    }

    private IEnumerator PressRoutine(
        Transform animationVisual,
        Vector3 animationBaseScale)
    {
        Vector3 pressedScale =
            animationBaseScale *
            pressScaleMultiplier;

        yield return ScaleTo(
            animationVisual,
            animationBaseScale,
            pressedScale,
            pressDuration
        );

        yield return ScaleTo(
            animationVisual,
            pressedScale,
            animationBaseScale,
            releaseDuration
        );

        if (IsCurrentVisual(animationVisual))
            animationVisual.localScale = animationBaseScale;

        animationCoroutine = null;
    }

    private IEnumerator ScaleTo(
        Transform animationVisual,
        Vector3 startScale,
        Vector3 targetScale,
        float duration)
    {
        if (!IsCurrentVisual(animationVisual))
            yield break;

        if (duration <= 0f)
        {
            animationVisual.localScale = targetScale;

            yield break;
        }

        float elapsed = 0f;

        while (elapsed < duration)
        {
            if (!IsCurrentVisual(animationVisual))
                yield break;

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

            animationVisual.localScale = Vector3.LerpUnclamped(
                    startScale,
                    targetScale,
                    easedT);

            yield return null;
        }

        if (IsCurrentVisual(animationVisual))
            animationVisual.localScale = targetScale;
    }

    private bool IsCurrentVisual(Transform candidate)
    {
        return candidate != null && candidate == visual;
    }

    private void StopAnimation(bool restoreBaseScale)
    {
        if (animationCoroutine != null)
        {
            Coroutine coroutine = animationCoroutine;
            animationCoroutine = null;
            StopCoroutine(coroutine);
        }

        if (restoreBaseScale && visual != null)
            visual.localScale = baseScale;
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
            StopAnimation(true);
    }
}