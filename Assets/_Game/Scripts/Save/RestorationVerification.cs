using System;
using System.Collections.Generic;
using System.Text;
using UnityEngine;

// Canonical comparison only: never rewrites, sorts or sanitizes the source lists.
// Unity serializes OrderDefinition references by instance ID. Both sides here
// refer to objects in the same running process; this is not an on-disk hash.
public static class RestorationVerification
{
    public static string Fingerprint(MergeSessionData data)
    {
        if (data == null) throw new ArgumentNullException(nameof(data));
        return data.nextOrderId + ":" + data.nextDessertTier + ":" +
            Rows(data.boardDesserts) + Rows(data.shelfDesserts) + Rows(data.customerOrders);
    }

    public static string Fingerprint(MergeGameplaySaveData data)
    {
        if (data == null) throw new ArgumentNullException(nameof(data));
        return data.hasSession + ":" + data.nextOrderId + ":" + data.nextDessertTier + ":" +
            Rows(data.boardDesserts) + Rows(data.shelfDesserts) + Rows(data.customerOrders);
    }

    private static string Rows<T>(IEnumerable<T> source)
    {
        if (source == null) throw new ArgumentException("Snapshot list is null.");
        var rows = new List<string>();
        foreach (T item in source)
        {
            if (ReferenceEquals(item, null)) throw new ArgumentException("Snapshot entry is null.");
            string json = JsonUtility.ToJson(item, false);
            if (string.IsNullOrEmpty(json) || json == "{}")
                throw new ArgumentException("Snapshot entry has no serialized fields.");
            rows.Add(json);
        }
        rows.Sort(StringComparer.Ordinal);
        var result = new StringBuilder();
        result.Append(rows.Count).Append(':');
        foreach (string row in rows) result.Append(row.Length).Append(':').Append(row);
        return result.ToString();
    }
}
