using System;
using System.Linq;
using NUnit.Framework;
using UnityEditor;
using UnityEngine;

public sealed class SignInResponsiveLayoutTests
{
    [TestCase(720, 1280)]
    [TestCase(1080, 1920)]
    [TestCase(1080, 2400)]
    public void SignInArtworkUsesStableProportionsWithoutDuplicateCaptions(int width, int height)
    {
        var root = UnityEngine.Object.Instantiate(AssetDatabase.LoadAssetAtPath<GameObject>("Assets/_Game/Resources/UI/VisualTemplates/StartupWelcome.prefab"));
        try
        {
            root.SetActive(true);
            ((RectTransform)root.transform).sizeDelta = new Vector2(width, height);
            var all = root.GetComponentsInChildren<RectTransform>(true);
            var welcome = all.Single(t => t.name == "WelcomeScreen");
            var google = all.Single(t => t.name == "GoogleSignInButton");
            var guest = all.Single(t => t.name == "GuestPlayButton");
            Assert.Greater(google.anchorMin.y, guest.anchorMax.y, "Sign-in choices must not overlap.");
            foreach (var button in new[] { google, guest })
            {
                Assert.Less(button.offsetMin.sqrMagnitude, .0001f, "Allow subpixel RectTransform rounding.");
                Assert.Less(button.offsetMax.sqrMagnitude, .0001f, "Allow subpixel RectTransform rounding.");
                Assert.GreaterOrEqual(button.anchorMin.x, 0);
                Assert.LessOrEqual(button.anchorMax.x, 1);
                Assert.Greater(button.rect.width, 0);
                Assert.Greater(button.rect.height, 0);
                var textType = AppDomain.CurrentDomain.GetAssemblies().Select(a => a.GetType("TMPro.TMP_Text")).First(t => t != null);
                foreach (var label in button.GetComponentsInChildren(textType, true))
                    Assert.AreEqual(string.Empty, textType.GetProperty("text").GetValue(label));
                Assert.IsTrue(button.IsChildOf(welcome));
            }
        }
        finally { UnityEngine.Object.DestroyImmediate(root); }
    }
}
