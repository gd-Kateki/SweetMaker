using System;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using UnityEditor;
using UnityEditor.Callbacks;
using UnityEngine;

public sealed class CloudCodeAssetCallbackTests
{
    [Test]
    public void CloudCodeAssetCallbackUsesSupportedIdentityAndIgnoresScenes()
    {
        var type = AppDomain.CurrentDomain.GetAssemblies()
            .Select(a => a.GetType("Unity.Services.CloudCode.Authoring.Editor.Scripts.JsAssetHandler"))
            .FirstOrDefault(t => t != null);
        Assert.IsNotNull(type);
        var callback = type.GetMethod("OpenAsset", BindingFlags.Static | BindingFlags.NonPublic);
        Assert.IsNotNull(callback);
        Assert.IsNotNull(callback.GetCustomAttribute<OnOpenAssetAttribute>());
        Assert.AreEqual(typeof(bool), callback.ReturnType);
        var scene = AssetDatabase.LoadAssetAtPath<SceneAsset>("Assets/_Game/Scenes/MainBakery.unity");
        Assert.IsNotNull(scene);
#if UNITY_6000_4_OR_NEWER
        Assert.AreEqual(typeof(EntityId), callback.GetParameters()[0].ParameterType);
        object identity = scene.GetEntityId();
#else
        Assert.AreEqual(typeof(int), callback.GetParameters()[0].ParameterType);
        object identity = scene.GetInstanceID();
#endif
        Assert.IsFalse((bool)callback.Invoke(null, new[] { identity, (object)1 }),
            "Cloud Code must leave scene opening to Unity.");
    }
}
