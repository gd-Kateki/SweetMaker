using System;
using UnityEngine;
using Unity.Services.LevelPlay;

// Local choices are deliberately separate from cloud saves and Analytics consent.
public static class AdvertisingPrivacy
{
    public enum AgeGroup { Unknown, Under13, Teen, Adult }
    public enum AdChoice { Unknown, Limited, Personalized }
    private const int PolicyVersion = 1;
    private static string Prefix => "dmc.ads.privacy." + SavePathPolicy.ModeName + ".";
    public static event Action Changed;
    public static bool DeferredForSession { get; private set; }
    public static void DeferForSession() => DeferredForSession = true;
    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
    private static void ResetSession() { DeferredForSession = false; Changed = null; }
    public static AgeGroup Age => (AgeGroup)PlayerPrefs.GetInt(Prefix + "age", 0);
    public static AdChoice Choice => PlayerPrefs.GetInt(Prefix + "version", 0) == PolicyVersion
        ? (AdChoice)PlayerPrefs.GetInt(Prefix + "choice", 0) : AdChoice.Unknown;
    public static bool Resolved => Age == AgeGroup.Under13 || IsEligible((int)Age, (int)Choice);
    public static bool CanRequestAds => IsEligible((int)Age, (int)Choice);
    public static bool Personalized => CanRequestAds && Age == AgeGroup.Adult && Choice == AdChoice.Personalized;

    internal static bool IsEligible(int age, int choice) =>
        (age == (int)AgeGroup.Teen && choice == (int)AdChoice.Limited) ||
        (age == (int)AgeGroup.Adult && (choice == (int)AdChoice.Limited || choice == (int)AdChoice.Personalized));

    public static void SelectAge(AgeGroup age)
    {
        if (age < AgeGroup.Under13 || age > AgeGroup.Adult) throw new ArgumentOutOfRangeException(nameof(age));
        PlayerPrefs.SetInt(Prefix + "age", (int)age);
        PlayerPrefs.SetInt(Prefix + "choice", 0);
        PlayerPrefs.Save();
        Changed?.Invoke();
    }

    public static void SelectChoice(AdChoice choice)
    {
        if (!IsEligible((int)Age, (int)choice)) throw new InvalidOperationException("Invalid advertising choice for this age group.");
        PlayerPrefs.SetInt(Prefix + "choice", (int)choice);
        PlayerPrefs.SetInt(Prefix + "version", PolicyVersion);
        PlayerPrefs.SetString(Prefix + "updatedUtc", DateTime.UtcNow.ToString("O"));
        PlayerPrefs.Save();
        Changed?.Invoke();
    }

    internal static void ApplySdkSignals()
    {
        // Restricted treatment for teens; no adult consent is inferred from their choice.
        LevelPlayPrivacySettings.SetGDPRConsent(Personalized);
        LevelPlayPrivacySettings.SetCCPA(!Personalized);
        LevelPlayPrivacySettings.SetCOPPA(Age != AgeGroup.Adult);
        LevelPlay.SetMetaData("is_deviceid_optout", Personalized ? "false" : "true");
    }
}
