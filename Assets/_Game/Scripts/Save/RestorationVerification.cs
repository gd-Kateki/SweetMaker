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

    public static bool MatchesFingerprint(
        string expectedFingerprint,
        MergeSessionData actual)
    {
        return string.Equals(
            expectedFingerprint,
            Fingerprint(actual),
            StringComparison.Ordinal);
    }

    public static string DescribeDifference(
        MergeSessionData expected,
        MergeSessionData actual)
    {
        if (expected.nextOrderId != actual.nextOrderId)
            return $"Next order ID: saved {expected.nextOrderId}, live {actual.nextOrderId}.";
        if (expected.nextDessertTier != actual.nextDessertTier)
            return $"Next dessert tier: saved {expected.nextDessertTier}, live {actual.nextDessertTier}.";

        string difference = DescribeRows(
            "Board",
            expected.boardDesserts,
            actual.boardDesserts,
            row => row.cellIndex);
        if (difference != null)
            return difference;

        difference = DescribeRows(
            "Shelf",
            expected.shelfDesserts,
            actual.shelfDesserts,
            row => row.slotIndex);
        if (difference != null)
            return difference;

        return DescribeRows(
            "Customer order",
            expected.customerOrders,
            actual.customerOrders,
            row => row.customerIndex);
    }

    private static string Rows<T>(IEnumerable<T> source)
    {
        if (source == null) throw new ArgumentException("Snapshot list is null.");
        var rows = new List<string>();
        foreach (T item in source)
        {
            if (ReferenceEquals(item, null)) throw new ArgumentException("Snapshot entry is null.");
            string json = CanonicalRow(item);
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

    private static string DescribeRows<T>(
        string label,
        IReadOnlyList<T> expected,
        IReadOnlyList<T> actual,
        Func<T, int> getIndex)
    {
        if (expected.Count != actual.Count)
            return $"{label} count: saved {expected.Count}, live {actual.Count}.";

        var actualByIndex = new Dictionary<int, T>();
        foreach (T row in actual)
            actualByIndex[getIndex(row)] = row;
        foreach (T row in expected)
        {
            int index = getIndex(row);
            string expectedJson = CanonicalRow(row);
            if (!actualByIndex.TryGetValue(index, out T actualRow))
                return $"{label} slot {index} is missing in the live session.";
            string actualJson = CanonicalRow(actualRow);
            if (!string.Equals(expectedJson, actualJson, StringComparison.Ordinal))
                return $"{label} slot {index} differs. Saved: " +
                    $"{JsonUtility.ToJson(row, false)}; live: " +
                    $"{JsonUtility.ToJson(actualRow, false)}.";
        }

        return null;
    }

    private static string CanonicalRow<T>(T row)
    {
        if (row is CustomerOrderState order &&
            TryGetOrderDetails(
                order,
                out string displayName,
                out int cashReward,
                out List<string> requirements))
        {
            var canonical = new StringBuilder();
            canonical.Append("order:")
                .Append(order.customerIndex).Append(':')
                .Append(order.orderId).Append(':');
            AppendToken(canonical, displayName);
            canonical.Append(cashReward).Append(':')
                .Append(requirements.Count).Append(':');
            foreach (string requirement in requirements)
                AppendToken(canonical, requirement);
            return canonical.ToString();
        }

        return JsonUtility.ToJson(row, false);
    }

    private static bool TryGetOrderDetails(
        CustomerOrderState order,
        out string displayName,
        out int cashReward,
        out List<string> requirements)
    {
        displayName = null;
        cashReward = 0;
        requirements = null;
        if (order == null)
            return false;

        bool hasExpandedDetails =
            !string.IsNullOrEmpty(order.displayName) ||
            order.cashReward != 0 ||
            (order.requirements != null && order.requirements.Length > 0);

        if (!string.IsNullOrEmpty(order.proceduralDefinitionId))
        {
            if (!ProceduralCustomerOrderSaveCodec.TryDecode(
                    order.proceduralDefinitionId,
                    out ProceduralCustomerOrderSaveData payload))
                return false;

            displayName = payload.displayName;
            cashReward = payload.cashReward;
            requirements = new List<string>(payload.requirements.Count);
            foreach (ProceduralCustomerOrderRequirementSaveData requirement in payload.requirements)
                requirements.Add($"{requirement.dessertTier}:{requirement.amount}");

            if (hasExpandedDetails &&
                (!TryGetExpandedDetails(
                        order.displayName,
                        order.cashReward,
                        order.requirements,
                        out string expandedName,
                        out int expandedReward,
                        out List<string> expandedRequirements) ||
                 !EquivalentDetails(
                     displayName,
                     cashReward,
                     requirements,
                     expandedName,
                     expandedReward,
                     expandedRequirements)))
                return false;
        }
        else if (order.definition != null)
        {
            string definitionId = order.definition.DefinitionId;
            if (ProceduralCustomerOrderSaveCodec.IsProceduralDefinitionId(definitionId))
            {
                if (!ProceduralCustomerOrderSaveCodec.TryDecode(
                        definitionId,
                        out ProceduralCustomerOrderSaveData payload))
                    return false;

                displayName = payload.displayName;
                cashReward = payload.cashReward;
                requirements = new List<string>(payload.requirements.Count);
                foreach (ProceduralCustomerOrderRequirementSaveData requirement in payload.requirements)
                    requirements.Add($"{requirement.dessertTier}:{requirement.amount}");
            }
            else if (!TryGetExpandedDetails(
                         order.definition.DisplayName,
                         order.definition.CashReward,
                         order.definition.Requirements,
                         out displayName,
                         out cashReward,
                         out requirements))
            {
                return false;
            }

            if (hasExpandedDetails)
            {
                if (!TryGetExpandedDetails(
                        order.displayName,
                        order.cashReward,
                        order.requirements,
                        out string expandedName,
                        out int expandedReward,
                        out List<string> expandedRequirements) ||
                    !EquivalentDetails(
                        displayName,
                        cashReward,
                        requirements,
                        expandedName,
                        expandedReward,
                        expandedRequirements))
                    return false;
            }
        }
        else if (!TryGetExpandedDetails(
                     order.displayName,
                     order.cashReward,
                     order.requirements,
                     out displayName,
                     out cashReward,
                     out requirements))
        {
            return false;
        }

        requirements.Sort(StringComparer.Ordinal);
        return true;
    }

    private static bool TryGetExpandedDetails(
        string name,
        int reward,
        IReadOnlyList<OrderRequirement> source,
        out string displayName,
        out int cashReward,
        out List<string> requirements)
    {
        displayName = name;
        cashReward = reward;
        requirements = null;
        if (string.IsNullOrWhiteSpace(name) ||
            reward < 0 ||
            source == null ||
            source.Count < 1 ||
            source.Count > 2)
            return false;

        requirements = new List<string>(source.Count);
        var tiers = new HashSet<int>();
        foreach (OrderRequirement requirement in source)
        {
            if (requirement == null ||
                requirement.Dessert == null ||
                requirement.Dessert.Tier < 1 ||
                requirement.Dessert.Tier > 30 ||
                requirement.Amount < 1 ||
                !tiers.Add(requirement.Dessert.Tier))
            {
                return false;
            }

            requirements.Add($"{requirement.Dessert.Tier}:{requirement.Amount}");
        }

        requirements.Sort(StringComparer.Ordinal);
        return true;
    }

    private static bool EquivalentDetails(
        string firstName,
        int firstReward,
        IReadOnlyList<string> firstRequirements,
        string secondName,
        int secondReward,
        IReadOnlyList<string> secondRequirements)
    {
        if (!string.Equals(firstName, secondName, StringComparison.Ordinal) ||
            firstReward != secondReward ||
            firstRequirements.Count != secondRequirements.Count)
            return false;

        var sortedFirst = new List<string>(firstRequirements);
        var sortedSecond = new List<string>(secondRequirements);
        sortedFirst.Sort(StringComparer.Ordinal);
        sortedSecond.Sort(StringComparer.Ordinal);
        for (int i = 0; i < sortedFirst.Count; i++)
            if (!string.Equals(sortedFirst[i], sortedSecond[i], StringComparison.Ordinal))
                return false;
        return true;
    }

    private static void AppendToken(StringBuilder builder, string value)
    {
        builder.Append(value.Length).Append(':').Append(value);
    }
}
