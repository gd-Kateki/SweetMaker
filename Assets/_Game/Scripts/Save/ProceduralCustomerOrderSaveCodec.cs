using System;
using System.Collections.Generic;
using System.Text;
using UnityEngine;

[Serializable]
public class ProceduralCustomerOrderSaveData
{
    public string displayName;
    public int cashReward;
    public List<ProceduralCustomerOrderRequirementSaveData> requirements =
        new List<ProceduralCustomerOrderRequirementSaveData>();
}

[Serializable]
public class ProceduralCustomerOrderRequirementSaveData
{
    public int dessertTier;
    public int amount;
}

public static class ProceduralCustomerOrderSaveCodec
{
    private const string Prefix = "procedural-order-v1:";
    private const int MaximumRequirementCount = 2;
    private const int MaximumCopiesPerDessertType = 3;
    private const int MaximumTotalDesserts = 5;

    public static bool IsProceduralDefinitionId(string definitionId)
    {
        return !string.IsNullOrWhiteSpace(definitionId) &&
               definitionId.StartsWith(Prefix, StringComparison.Ordinal);
    }

    public static bool TryEncode(
        string displayName,
        int cashReward,
        IReadOnlyList<OrderRequirement> requirements,
        out string definitionId)
    {
        return TryEncode(
            displayName,
            cashReward,
            requirements,
            out definitionId,
            out _);
    }

    public static bool TryEncode(
        string displayName,
        int cashReward,
        IReadOnlyList<OrderRequirement> requirements,
        out string definitionId,
        out string reason)
    {
        definitionId = null;
        reason = null;
        if (string.IsNullOrWhiteSpace(displayName) ||
            cashReward < 0 ||
            requirements == null ||
            requirements.Count < 1 ||
            requirements.Count > MaximumRequirementCount)
        {
            reason =
                "Order display name, reward, or distinct dessert count is invalid.";
            return false;
        }

        var payload = new ProceduralCustomerOrderSaveData
        {
            displayName = displayName,
            cashReward = cashReward
        };
        var tiers = new HashSet<int>();
        int totalAmount = 0;
        foreach (OrderRequirement requirement in requirements)
        {
            if (requirement == null ||
                requirement.Dessert == null ||
                requirement.Dessert.Tier < 1 ||
                requirement.Dessert.Tier > 30 ||
                requirement.Amount < 1 ||
                requirement.Amount > MaximumCopiesPerDessertType ||
                !tiers.Add(requirement.Dessert.Tier))
            {
                reason =
                    "A requirement has an invalid dessert tier, duplicate dessert type, or quantity outside 1-3.";
                return false;
            }

            totalAmount += requirement.Amount;
            payload.requirements.Add(
                new ProceduralCustomerOrderRequirementSaveData
                {
                    dessertTier = requirement.Dessert.Tier,
                    amount = requirement.Amount
                });
        }

        if (totalAmount > MaximumTotalDesserts)
        {
            reason = "Total order quantity exceeds the five-plate maximum.";
            return false;
        }

        string json = JsonUtility.ToJson(payload);
        definitionId = Prefix + Convert.ToBase64String(
            Encoding.UTF8.GetBytes(json));
        return true;
    }

    public static bool TryDecode(
        string definitionId,
        out ProceduralCustomerOrderSaveData payload)
    {
        return TryDecode(definitionId, out payload, out _);
    }

    public static bool TryDecode(
        string definitionId,
        out ProceduralCustomerOrderSaveData payload,
        out string reason)
    {
        payload = null;
        reason = null;
        if (!IsProceduralDefinitionId(definitionId))
        {
            reason = "Definition ID does not have the procedural order prefix.";
            return false;
        }

        try
        {
            string json = Encoding.UTF8.GetString(
                Convert.FromBase64String(definitionId.Substring(Prefix.Length)));
            payload = JsonUtility.FromJson<ProceduralCustomerOrderSaveData>(json);
        }
        catch (FormatException)
        {
            reason = "Procedural order payload is not valid Base64.";
            return false;
        }
        catch (ArgumentException)
        {
            reason = "Procedural order payload contains invalid encoded text.";
            return false;
        }

        if (payload == null ||
            string.IsNullOrWhiteSpace(payload.displayName) ||
            payload.cashReward < 0 ||
            payload.requirements == null ||
            payload.requirements.Count < 1 ||
            payload.requirements.Count > MaximumRequirementCount)
        {
            reason =
                "Procedural order metadata or distinct dessert count is invalid.";
            payload = null;
            return false;
        }

        var tiers = new HashSet<int>();
        int totalAmount = 0;
        foreach (ProceduralCustomerOrderRequirementSaveData requirement
                 in payload.requirements)
        {
            if (requirement == null ||
                requirement.dessertTier < 1 ||
                requirement.dessertTier > 30 ||
                requirement.amount < 1 ||
                requirement.amount > MaximumCopiesPerDessertType ||
                !tiers.Add(requirement.dessertTier))
            {
                reason =
                    "A procedural requirement has an invalid dessert tier, duplicate dessert type, or quantity outside 1-3.";
                payload = null;
                return false;
            }

            totalAmount += requirement.amount;
        }

        if (totalAmount > MaximumTotalDesserts)
        {
            reason = "Total procedural order quantity exceeds the five-plate maximum.";
            payload = null;
            return false;
        }

        return true;
    }
}
