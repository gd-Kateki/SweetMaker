using System;
using System.IO;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEngine;

public sealed class AndroidBuildIdentityGuardTests
{
    private const string DevelopmentProfile =
        "Assets/Settings/Build Profiles/Android Dev.asset";
    private const string ReleaseProfile =
        "Assets/Settings/Build Profiles/Android Release.asset";
    private const string DevelopmentIdentifier =
        "com.offcutstudios.dessertmergecafe.dev";
    private const string ReleaseIdentifier =
        "com.offcutstudios.dessertmergecafe";
    private const string MainBakeryScene =
        "Assets/_Game/Scenes/MainBakery.unity";
    private const string GameScene =
        "Assets/_Game/Scenes/Game.unity";

    [Test]
    public void CorrectDevelopmentProfileAndPackageAreAccepted()
    {
        AssertAccepted(CreateSnapshot(true), true);
    }

    [Test]
    public void CorrectReleaseProfileAndPackageAreAccepted()
    {
        AssertAccepted(CreateSnapshot(false), false);
    }

    [Test]
    public void DevelopmentPackageIsRejectedInReleaseMode()
    {
        AssertRejected(CreateSnapshot(
            false,
            applicationIdentifier: DevelopmentIdentifier), false);
    }

    [Test]
    public void ReleasePackageIsRejectedInDevelopmentMode()
    {
        AssertRejected(CreateSnapshot(
            true,
            applicationIdentifier: ReleaseIdentifier), true);
    }

    [Test]
    public void IncorrectActiveBuildProfileIsRejected()
    {
        AssertRejected(CreateSnapshot(
            true,
            activeProfilePath: ReleaseProfile), true);
    }

    [Test]
    public void MissingBuildProfileIsRejected()
    {
        AssertRejected(CreateSnapshot(true, activeProfilePath: string.Empty), true);
    }

    [Test]
    public void DevelopmentFlagMismatchIsRejected()
    {
        AssertRejected(CreateSnapshot(
            true,
            profileDevelopmentBuild: false), true);
    }

    [Test]
    public void BuildOptionsDevelopmentMismatchIsRejected()
    {
        AssertRejected(CreateSnapshot(
            true,
            requestedDevelopmentBuild: false), true);
    }

    [Test]
    public void MissingApplicationIdentifierIsRejected()
    {
        AssertRejected(CreateSnapshot(
            true,
            applicationIdentifier: string.Empty), true);
    }

    [Test]
    public void MissingSceneIsRejected()
    {
        AssertRejected(CreateSnapshot(
            true,
            scenePaths: new[] { MainBakeryScene },
            sceneEnabled: new[] { true },
            sceneExists: new[] { true }), true);
    }

    [Test]
    public void MissingSceneAssetIsRejected()
    {
        AssertRejected(CreateSnapshot(
            true,
            sceneExists: new[] { true, false }), true);
    }

    [Test]
    public void ReorderedScenesAreRejected()
    {
        AssertRejected(CreateSnapshot(
            true,
            scenePaths: new[] { GameScene, MainBakeryScene }), true);
    }

    [Test]
    public void DuplicateSceneIsRejected()
    {
        AssertRejected(CreateSnapshot(
            true,
            scenePaths: new[] { MainBakeryScene, MainBakeryScene }), true);
    }

    [Test]
    public void UnexpectedSceneIsRejected()
    {
        AssertRejected(CreateSnapshot(
            true,
            scenePaths: new[] { MainBakeryScene, "Assets/Unexpected.unity" }), true);
    }

    [Test]
    public void MonoScriptingBackendIsRejected()
    {
        AssertRejected(CreateSnapshot(true, usesIl2Cpp: false), true);
    }

    [Test]
    public void MissingArm64ArchitectureIsRejected()
    {
        AssertRejected(CreateSnapshot(true, arm64Enabled: false), true);
    }

    [Test]
    public void IncorrectMinimumApiIsRejected()
    {
        AssertRejected(CreateSnapshot(true, minimumApiLevel: 31), true);
    }

    [Test]
    public void ReleaseTargetApiBelow36IsRejected()
    {
        AssertRejected(CreateSnapshot(
            false,
            targetApiIsAutomatic: false,
            targetApiLevel: 35), false);
    }

    [Test]
    public void AutomaticReleaseTargetApiIsRejected()
    {
        AssertRejected(CreateSnapshot(
            false,
            targetApiIsAutomatic: true,
            targetApiLevel: null), false);
    }

    [Test]
    public void MissingEffectiveSettingsAreRejected()
    {
        AssertRejected(CreateSnapshot(
            true,
            profileDevelopmentBuild: null,
            scenePaths: null,
            sceneEnabled: null,
            sceneExists: null,
            usesIl2Cpp: null,
            arm64Enabled: null,
            minimumApiLevel: null,
            targetApiIsAutomatic: null,
            targetApiLevel: null,
            profileModeAvailable: false,
            scenesAvailable: false,
            androidSettingsAvailable: false,
            targetApiAvailable: false), true);
    }

    [Test]
    public void IndependentIdentityGuardRemainsWiredIntoPrebuild()
    {
        string validatorPath = Path.Combine(
            Application.dataPath,
            "_Game",
            "Editor",
            "DevelopmentAndroidIdentityValidator.cs");
        string source = File.ReadAllText(validatorPath);
        StringAssert.Contains(
            "AndroidBuildIdentityGuard.Validate(report)",
            source);
    }

    private static object CreateSnapshot(
        bool development,
        string activeProfilePath = null,
        string applicationIdentifier = null,
        bool? profileDevelopmentBuild = null,
        bool? requestedDevelopmentBuild = null,
        string[] scenePaths = null,
        bool[] sceneEnabled = null,
        bool[] sceneExists = null,
        bool? usesIl2Cpp = true,
        bool? arm64Enabled = true,
        int? minimumApiLevel = 32,
        bool? targetApiIsAutomatic = null,
        int? targetApiLevel = null,
        bool profileModeAvailable = true,
        bool scenesAvailable = true,
        bool androidSettingsAvailable = true,
        bool targetApiAvailable = true)
    {
        bool expectedTargetAutomatic = development;
        if (activeProfilePath == null)
            activeProfilePath = development ? DevelopmentProfile : ReleaseProfile;
        if (applicationIdentifier == null)
            applicationIdentifier = development
                ? DevelopmentIdentifier
                : ReleaseIdentifier;
        if (!profileDevelopmentBuild.HasValue && profileModeAvailable)
            profileDevelopmentBuild = development;
        if (!requestedDevelopmentBuild.HasValue)
            requestedDevelopmentBuild = development;
        if (scenePaths == null && scenesAvailable)
            scenePaths = new[] { MainBakeryScene, GameScene };
        if (sceneEnabled == null && scenesAvailable)
            sceneEnabled = new[] { true, true };
        if (sceneExists == null && scenesAvailable)
            sceneExists = new[] { true, true };
        if (!androidSettingsAvailable)
        {
            usesIl2Cpp = null;
            arm64Enabled = null;
            minimumApiLevel = null;
        }
        if (!targetApiIsAutomatic.HasValue && targetApiAvailable)
            targetApiIsAutomatic = expectedTargetAutomatic;
        if (!targetApiLevel.HasValue &&
            targetApiAvailable &&
            !expectedTargetAutomatic &&
            targetApiIsAutomatic == false)
        {
            targetApiLevel = 36;
        }
        if (!targetApiAvailable)
        {
            targetApiIsAutomatic = null;
            targetApiLevel = null;
        }

        Type snapshotType = GetEditorType("AndroidBuildIdentitySnapshot");
        ConstructorInfo constructor = snapshotType.GetConstructor(
            BindingFlags.Instance | BindingFlags.NonPublic,
            null,
            new[]
            {
                typeof(string),
                typeof(string),
                typeof(bool),
                typeof(bool?),
                typeof(string[]),
                typeof(bool[]),
                typeof(bool[]),
                typeof(bool?),
                typeof(bool?),
                typeof(int?),
                typeof(bool?),
                typeof(int?)
            },
            null);
        Assert.IsNotNull(constructor);
        return constructor.Invoke(new object[]
        {
            activeProfilePath,
            applicationIdentifier,
            requestedDevelopmentBuild,
            profileDevelopmentBuild,
            scenePaths,
            sceneEnabled,
            sceneExists,
            usesIl2Cpp,
            arm64Enabled,
            minimumApiLevel,
            targetApiIsAutomatic,
            targetApiLevel
        });
    }

    private static void AssertAccepted(object snapshot, bool development)
    {
        Assert.IsNull(ValidateSnapshot(snapshot, development));
    }

    private static void AssertRejected(object snapshot, bool development)
    {
        Assert.IsNotNull(ValidateSnapshot(snapshot, development));
    }

    private static string ValidateSnapshot(object snapshot, bool development)
    {
        Type guardType = GetEditorType("AndroidBuildIdentityGuard");
        MethodInfo method = guardType.GetMethod(
            "ValidateSnapshot",
            BindingFlags.Static | BindingFlags.NonPublic);
        Assert.IsNotNull(method);
        return (string)method.Invoke(null, new[] { snapshot, (object)development });
    }

    private static Type GetEditorType(string typeName)
    {
        return AppDomain.CurrentDomain
            .GetAssemblies()
            .Select(assembly => assembly.GetType(typeName, false))
            .First(type => type != null);
    }
}
