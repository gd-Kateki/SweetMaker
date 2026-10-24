using System;
using System.IO;
using UnityEngine;

public static class SavePathPolicy
{
#if UNITY_EDITOR || (UNITY_ANDROID && DEVELOPMENT_BUILD)
    private const string DevelopmentSaveDirectoryName =
        "SweetMaker-Development";
#endif

    public static bool IsDevelopmentSaveIsolationEnabled
    {
        get
        {
#if UNITY_EDITOR || (UNITY_ANDROID && DEVELOPMENT_BUILD)
            return true;
#else
            return false;
#endif
        }
    }

    public static string ModeName =>
        IsDevelopmentSaveIsolationEnabled
            ? "DEVELOPMENT-ISOLATED"
            : "RELEASE";

    public static string GetSaveDirectory()
    {
        return GetSaveDirectory(Application.persistentDataPath);
    }

    public static string GetSaveDirectory(string persistentDataPath)
    {
        if (string.IsNullOrWhiteSpace(persistentDataPath))
            throw new ArgumentException(
                "Persistent data path cannot be empty.",
                nameof(persistentDataPath));

#if UNITY_EDITOR || (UNITY_ANDROID && DEVELOPMENT_BUILD)
        return Path.Combine(
            persistentDataPath,
            DevelopmentSaveDirectoryName);
#else
        return persistentDataPath;
#endif
    }
}
