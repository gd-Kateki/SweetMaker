// WARNING: Auto generated code. Modifications will be lost!
// Original source 'com.unity.services.shared' @0.0.12.

using UnityEditor;

namespace Unity.Services.CloudCode.Editor.Shared.UI
{
    interface IDisplayDialog
    {
        bool Show(
            string title,
            string content,
            string ok = "Ok",
            string cancel = "Cancel",
            DialogOptOutDecisionType? dialogOptOutDecisionType = null,
            string dialogOptOutDecisionStorageKey = null);
    }
}
