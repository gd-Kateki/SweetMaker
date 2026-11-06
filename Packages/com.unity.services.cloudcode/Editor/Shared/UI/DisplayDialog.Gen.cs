// WARNING: Auto generated code. Modifications will be lost!
// Original source 'com.unity.services.shared' @0.0.12.

using UnityEditor;

namespace Unity.Services.CloudCode.Editor.Shared.UI
{
    class DisplayDialog : IDisplayDialog
    {
        public bool Show(
            string title,
            string content,
            string ok,
            string cancel,
            DialogOptOutDecisionType? dialogOptOutDecisionType = null,
            string dialogOptOutDecisionStorageKey = null)
        {
            if (dialogOptOutDecisionType.HasValue)
            {
                return EditorUtility.DisplayDialog(
                    title,
                    content,
                    ok,
                    cancel,
                    dialogOptOutDecisionType.Value,
                    dialogOptOutDecisionStorageKey);
            }

            return EditorUtility.DisplayDialog(title, content, ok, cancel);
        }
    }
}
