using System.IO;
using UnityEditor;
using UnityEditor.TestTools.TestRunner.Api;
using UnityEngine;
[InitializeOnLoad]
internal static class AdsTestRunTemporary
{
    private static TestRunnerApi api;
    static AdsTestRunTemporary() { EditorApplication.delayCall += Run; }
    private static void Run()
    {
        if (!File.Exists("tmp/run-ads-tests.request") || EditorApplication.isPlayingOrWillChangePlaymode) return;
        File.Delete("tmp/run-ads-tests.request");
        api = ScriptableObject.CreateInstance<TestRunnerApi>();
        api.RegisterCallbacks(new Results());
        api.Execute(new ExecutionSettings(new Filter { testMode = TestMode.EditMode, testNames = new[] { "SimpleAdsTests", "EnergyCapacityTests" } }));
    }
    private sealed class Results : ICallbacks
    {
        public void RunStarted(ITestAdaptor tests) { }
        public void TestStarted(ITestAdaptor test) { }
        public void TestFinished(ITestResultAdaptor result) { }
        public void RunFinished(ITestResultAdaptor result)
        {
            TestRunnerApi.SaveResultToFile(result, "D:/SweetMaker/tmp/ads-tests.xml");
            Debug.Log("ADS TESTS | " + result.TestStatus);
        }
    }
}
