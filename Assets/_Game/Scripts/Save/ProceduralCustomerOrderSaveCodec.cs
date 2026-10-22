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
        definitionId = null;
        if (string.IsNullOrWhiteSpace(displayName) ||
            cashReward < 0 ||
            requirements == null ||
            requirements.Count < 1 ||
            requirements.Count > 2)
        {
            return false;
        }

        var payload = new ProceduralCustomerOrderSaveData
        {
            displayName = displayName,
            cashReward = cashReward
        };
        var tiers = new HashSet<int>();
        foreach (OrderRequirement requirement in requirements)
        {
            if (requirement == null ||
                requirement.Dessert == null ||
                requirement.Dessert.Tier < 1 ||
                requirement.Dessert.Tier > 30 ||
                requirement.Amount < 1 ||
                requirement.Amount > 2 ||
                !tiers.Add(requirement.Dessert.Tier))
            {
                return false;
            }

            payload.requirements.Add(
                new ProceduralCustomerOrderRequirementSaveData
                {
                    dessertTier = requirement.Dessert.Tier,
                    amount = requirement.Amount
                });
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
        payload = null;
        if (!IsProceduralDefinitionId(definitionId))
        {
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
            return false;
        }
        catch (ArgumentException)
        {
            return false;
        }

        if (payload == null ||
            string.IsNullOrWhiteSpace(payload.displayName) ||
            payload.cashReward < 0 ||
            payload.requirements == null ||
            payload.requirements.Count < 1 ||
            payload.requirements.Count > 2)
        {
            payload = null;
            return false;
        }

        var tiers = new HashSet<int>();
        foreach (ProceduralCustomerOrderRequirementSaveData requirement
                 in payload.requirements)
        {
            if (requirement == null ||
                requirement.dessertTier < 1 ||
                requirement.dessertTier > 30 ||
                requirement.amount < 1 ||
                requirement.amount > 2 ||
                !tiers.Add(requirement.dessertTier))
            {
                payload = null;
                return false;
            }
        }

        return true;
    }
}
