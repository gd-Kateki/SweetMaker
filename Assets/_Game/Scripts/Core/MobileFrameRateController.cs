using System.Collections;
using UnityEngine;

public sealed class MobileFrameRateController : MonoBehaviour
{
    private static MobileFrameRateController instance;
    private bool hasAppliedRate;
    private uint lastNumerator;
    private uint lastDenominator;

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
    private static void InitializeBeforeSceneLoad()
    {
        if (!Application.isMobilePlatform || instance != null)
            return;

        var controllerObject = new GameObject(nameof(MobileFrameRateController));
        controllerObject.AddComponent<MobileFrameRateController>();
    }

    private void Awake()
    {
        if (instance != null && instance != this)
        {
            Destroy(gameObject);
            return;
        }

        instance = this;
        DontDestroyOnLoad(gameObject);
        ApplyAvailableRefreshRate();
        StartCoroutine(MonitorRefreshRateChanges());
    }

    private void OnApplicationFocus(bool hasFocus)
    {
        if (hasFocus)
            ApplyAvailableRefreshRate();
    }

    private void OnApplicationPause(bool isPaused)
    {
        if (!isPaused)
            ApplyAvailableRefreshRate();
    }

    private void OnDestroy()
    {
        if (instance == this)
            instance = null;
    }

    private IEnumerator MonitorRefreshRateChanges()
    {
        var wait = new WaitForSecondsRealtime(5f);
        while (true)
        {
            yield return wait;
            if (Application.isFocused)
                ApplyAvailableRefreshRate();
        }
    }

    private void ApplyAvailableRefreshRate()
    {
        RefreshRate refreshRate = Screen.currentResolution.refreshRateRatio;
        if (refreshRate.numerator == 0 || refreshRate.denominator == 0)
        {
            if (!hasAppliedRate)
                Debug.LogWarning("Mobile frame rate unchanged: display refresh rate is unavailable.");
            return;
        }

        if (hasAppliedRate &&
            refreshRate.numerator == lastNumerator &&
            refreshRate.denominator == lastDenominator)
            return;

        double detectedRate = refreshRate.value;
        int requestedFps = Mathf.RoundToInt((float)detectedRate);
        if (requestedFps <= 0)
        {
            Debug.LogWarning(
                $"Mobile frame rate unchanged: invalid display refresh rate {detectedRate} Hz.");
            return;
        }

        Application.targetFrameRate = requestedFps;
        lastNumerator = refreshRate.numerator;
        lastDenominator = refreshRate.denominator;
        hasAppliedRate = true;
        Debug.Log(
            $"Mobile display refresh rate: {detectedRate:0.##} Hz; " +
            $"requested FPS: {requestedFps}.");
    }
}
