using System;
using System.Reflection;
using NUnit.Framework;
using TMPro;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.UnityConsent;

namespace SweetMerge.Analytics.Tests
{
    public sealed class AnalyticsConsentUITests
    {
        private sealed class FakeConsentProvider :
            IAnalyticsConsentProvider
        {
            public ConsentStatus AnalyticsConsent { get; set; }
            public ConsentStatus AdsConsent { get; set; }
            public int ConsentChangeListenerCount =>
                AnalyticsConsentChanged?.GetInvocationList().Length ?? 0;

            public event Action<ConsentStatus> AnalyticsConsentChanged;

            public void SetAnalyticsConsent(bool isGranted)
            {
                AnalyticsConsent = isGranted
                    ? ConsentStatus.Granted
                    : ConsentStatus.Denied;
                AnalyticsConsentChanged?.Invoke(AnalyticsConsent);
            }
        }

        private GameObject settingsViewportObject;
        private GameObject settingsContentObject;

        [TearDown]
        public void TearDown()
        {
            if (settingsViewportObject != null)
                UnityEngine.Object.DestroyImmediate(settingsViewportObject);
            else if (settingsContentObject != null)
                UnityEngine.Object.DestroyImmediate(settingsContentObject);
        }

        [Test]
        public void PromptIsOnlyShownForUnspecifiedConsentInMainBakery()
        {
            Assert.IsTrue(AnalyticsConsentPresentation.ShouldShowPrompt(
                "MainBakery",
                ConsentStatus.Unspecified,
                false));
            Assert.IsFalse(AnalyticsConsentPresentation.ShouldShowPrompt(
                "MainBakery",
                ConsentStatus.Granted,
                false));
            Assert.IsFalse(AnalyticsConsentPresentation.ShouldShowPrompt(
                "MainBakery",
                ConsentStatus.Denied,
                false));
            Assert.IsFalse(AnalyticsConsentPresentation.ShouldShowPrompt(
                "Game",
                ConsentStatus.Unspecified,
                false));
            Assert.IsFalse(AnalyticsConsentPresentation.ShouldShowPrompt(
                "MainBakery",
                ConsentStatus.Unspecified,
                true));
            Assert.IsTrue(AnalyticsConsentPresentation.ShouldShowPrompt(
                "MainBakery",
                ConsentStatus.Unspecified,
                false));
        }

        [TestCase(true, ConsentStatus.Granted)]
        [TestCase(false, ConsentStatus.Denied)]
        public void PromptChoicesUpdateOnlyAnalyticsConsent(
            bool isGranted,
            ConsentStatus expected)
        {
            var provider = new FakeConsentProvider
            {
                AnalyticsConsent = ConsentStatus.Unspecified,
                AdsConsent = ConsentStatus.Denied
            };

            AnalyticsConsentPresentation.ApplyChoice(provider, isGranted);

            Assert.AreEqual(expected, provider.AnalyticsConsent);
            Assert.AreEqual(ConsentStatus.Denied, provider.AdsConsent);
        }

        [Test]
        public void SettingsEnableDisableSynchronizeAndAvoidDuplicateListeners()
        {
            settingsViewportObject = new GameObject(
                "SettingsScrollViewport",
                typeof(RectTransform),
                typeof(ScrollRect));
            RectTransform viewportRect =
                settingsViewportObject.GetComponent<RectTransform>();
            viewportRect.sizeDelta = new Vector2(1000f, 1000f);

            settingsContentObject = new GameObject(
                "SettingsScrollContent",
                typeof(RectTransform));
            settingsContentObject.transform.SetParent(
                settingsViewportObject.transform,
                false);
            RectTransform contentRect =
                settingsContentObject.GetComponent<RectTransform>();
            contentRect.sizeDelta = new Vector2(1000f, 1450f);
            ScrollRect scrollRect =
                settingsViewportObject.GetComponent<ScrollRect>();
            scrollRect.viewport = viewportRect;
            scrollRect.content = contentRect;
            var provider = new FakeConsentProvider
            {
                AnalyticsConsent = ConsentStatus.Unspecified,
                AdsConsent = ConsentStatus.Denied
            };

            AnalyticsConsentSettingsControl control =
                AnalyticsConsentSettingsControl.Attach(
                    settingsContentObject.transform,
                    provider);

            Assert.AreEqual(1, provider.ConsentChangeListenerCount);
            Assert.AreEqual(
                "You have not chosen yet.",
                control.StatusText.text);
            Assert.IsNotNull(scrollRect.verticalScrollbar);
            Assert.AreEqual(
                ScrollRect.ScrollbarVisibility.Permanent,
                scrollRect.verticalScrollbarVisibility);
            Scrollbar createdScrollbar = scrollRect.verticalScrollbar;
            float expandedHeight = contentRect.sizeDelta.y;

            AnalyticsConsentSettingsControl.Attach(
                settingsContentObject.transform,
                provider);

            Assert.AreEqual(1, provider.ConsentChangeListenerCount);
            Assert.AreEqual(expandedHeight, contentRect.sizeDelta.y);
            Assert.AreSame(createdScrollbar, scrollRect.verticalScrollbar);

            control.EnableButton.onClick.Invoke();
            Assert.AreEqual(
                "Analytics is enabled.",
                control.StatusText.text);
            Assert.AreEqual(ConsentStatus.Denied, provider.AdsConsent);

            control.DisableButton.onClick.Invoke();
            Assert.AreEqual(
                "Analytics is disabled.",
                control.StatusText.text);
            Assert.AreEqual(ConsentStatus.Denied, provider.AdsConsent);

            typeof(AnalyticsConsentSettingsControl)
                .GetMethod("OnDisable", BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(control, null);
            Assert.AreEqual(0, provider.ConsentChangeListenerCount);
            typeof(AnalyticsConsentSettingsControl)
                .GetMethod("OnEnable", BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(control, null);
            Assert.AreEqual(1, provider.ConsentChangeListenerCount);
        }
    }
}
