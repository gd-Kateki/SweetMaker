using System;

[Serializable]
public sealed class SettingsProfileData
{
    public int schemaVersion = 1;
    public bool musicEnabled = true;
    public float musicVolume = 0.70f;
    public bool sfxEnabled = true;
    public float sfxVolume = 0.85f;
    public bool vibrationEnabled = true;
    public bool confirmImportantActions = true;
    public bool reduceAnimations = false;
    public static SettingsProfileData CreateDefault()
    {
        return new SettingsProfileData();
    }

    public SettingsProfileData Copy()
    {
        return new SettingsProfileData
        {
            schemaVersion = schemaVersion,
            musicEnabled = musicEnabled,
            musicVolume = musicVolume,
            sfxEnabled = sfxEnabled,
            sfxVolume = sfxVolume,
            vibrationEnabled = vibrationEnabled,
            confirmImportantActions = confirmImportantActions,
            reduceAnimations = reduceAnimations
        };
    }

    internal bool TryNormalize(
        out SettingsProfileData normalized,
        out string failureReason)
    {
        normalized = null;
        failureReason = null;

        if (schemaVersion != 1)
        {
            failureReason =
                $"Settings schema version {schemaVersion} is unsupported.";
            return false;
        }

        if (float.IsNaN(musicVolume) ||
            float.IsInfinity(musicVolume) ||
            float.IsNaN(sfxVolume) ||
            float.IsInfinity(sfxVolume))
        {
            failureReason = "Settings volume values must be finite numbers.";
            return false;
        }

        normalized = Copy();
        normalized.musicVolume = ClampVolume(musicVolume);
        normalized.sfxVolume = ClampVolume(sfxVolume);
        return true;
    }

    private static float ClampVolume(float value)
    {
        if (value < 0f)
            return 0f;
        if (value > 1f)
            return 1f;
        return value;
    }
}
