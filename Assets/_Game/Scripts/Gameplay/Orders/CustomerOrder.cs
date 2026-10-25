using System.Collections.Generic;

public class CustomerOrder
{
    private const int MaximumGeneratedDessertTypes = 2;
    private const int MaximumGeneratedCopiesPerType = 3;
    private const int MaximumGeneratedTotal = 5;

    private readonly int orderId;
    private readonly CustomerOrderDefinition definition;
    private readonly string generatedDisplayName;
    private readonly int generatedCashReward;
    private readonly IReadOnlyList<OrderRequirement> generatedRequirements;

    public int OrderId =>
        orderId;

    public CustomerOrderDefinition Definition =>
        definition;

    public string DisplayName =>
        definition != null
            ? definition.DisplayName
            : generatedDisplayName ?? "Invalid Order";

    public IReadOnlyList<OrderRequirement> Requirements =>
        definition != null
            ? definition.Requirements
            : generatedRequirements;

    public int CashReward =>
        definition != null
            ? definition.CashReward
            : generatedCashReward;

    public bool IsValid =>
        definition != null
            ? definition.IsValid
            : IsGeneratedOrderValid();

    public CustomerOrder(
        int orderId,
        CustomerOrderDefinition definition)
    {
        this.orderId =
            orderId;

        this.definition =
            definition;
    }

    public CustomerOrder(
        int orderId,
        GeneratedCustomerOrder generatedOrder)
    {
        this.orderId = orderId;
        if (generatedOrder == null)
            return;

        generatedDisplayName =
            $"{generatedOrder.Difficulty} {generatedOrder.Shape} Order";
        generatedCashReward = generatedOrder.BaseReward;
        generatedRequirements = generatedOrder.Requirements;
    }

    internal CustomerOrder(
        int orderId,
        string displayName,
        int cashReward,
        IReadOnlyList<OrderRequirement> requirements)
    {
        this.orderId = orderId;
        generatedDisplayName = displayName;
        generatedCashReward = cashReward;
        generatedRequirements = requirements;
    }

    private bool IsGeneratedOrderValid()
    {
        if (string.IsNullOrWhiteSpace(generatedDisplayName) ||
            generatedCashReward < 0 ||
            generatedRequirements == null ||
            generatedRequirements.Count == 0)
        {
            return false;
        }

        var usedDesserts = new HashSet<DessertDefinition>();
        int totalAmount = 0;
        if (generatedRequirements.Count > MaximumGeneratedDessertTypes)
            return false;

        foreach (OrderRequirement requirement in generatedRequirements)
        {
            if (requirement == null ||
                requirement.Dessert == null ||
                requirement.Dessert.Tier < 1 ||
                requirement.Dessert.Tier > 30 ||
                requirement.Amount <= 0 ||
                requirement.Amount > MaximumGeneratedCopiesPerType ||
                !usedDesserts.Add(requirement.Dessert))
            {
                return false;
            }

            totalAmount += requirement.Amount;
        }

        return totalAmount <= MaximumGeneratedTotal;
    }

    internal bool IsValidForServingPlateCapacity(int capacity)
    {
        if (!IsValid || capacity < 1 || capacity > MaximumGeneratedTotal)
            return false;

        int totalAmount = 0;
        foreach (OrderRequirement requirement in Requirements)
            totalAmount += requirement.Amount;

        return totalAmount <= capacity;
    }

    // --------------------------------------------------
    // FULFILLMENT
    // --------------------------------------------------

    public bool CanFulfill(
        ShelfManager shelfManager)
    {
        if (!IsValid)
            return false;

        if (shelfManager == null)
            return false;

        foreach (
            OrderRequirement requirement
            in Requirements)
        {
            int availableAmount =
                CountDessertOnServingPlates(
                    shelfManager,
                    requirement.Dessert
                );

            if (availableAmount <
                requirement.Amount)
            {
                return false;
            }
        }

        return true;
    }

    public int GetAvailableAmount(
        ShelfManager shelfManager,
        DessertDefinition dessertDefinition)
    {
        return CountDessertOnServingPlates(
            shelfManager,
            dessertDefinition
        );
    }

    public bool TryGetDessertsForFulfillment(
        ShelfManager shelfManager,
        out List<Dessert> desserts)
    {
        desserts =
            new List<Dessert>();

        if (!CanFulfill(
                shelfManager))
        {
            return false;
        }

        foreach (
            OrderRequirement requirement
            in Requirements)
        {
            int remaining =
                requirement.Amount;

            foreach (
                ShelfSlot slot
                in shelfManager.Slots)
            {
                if (remaining <= 0)
                    break;

                if (slot == null ||
                    !slot.IsUnlocked ||
                    slot.IsEmpty)
                {
                    continue;
                }

                Dessert dessert =
                    slot.CurrentDessert;

                if (dessert == null)
                    continue;

                if (dessert.Definition !=
                    requirement.Dessert)
                {
                    continue;
                }

                if (desserts.Contains(
                        dessert))
                {
                    continue;
                }

                desserts.Add(
                    dessert
                );

                remaining--;
            }

            if (remaining > 0)
            {
                desserts.Clear();
                return false;
            }
        }

        return true;
    }

    // --------------------------------------------------
    // SERVING PLATE INVENTORY
    // --------------------------------------------------

    private int CountDessertOnServingPlates(
        ShelfManager shelfManager,
        DessertDefinition dessertDefinition)
    {
        if (shelfManager == null ||
            dessertDefinition == null)
        {
            return 0;
        }

        int count = 0;

        foreach (
            ShelfSlot slot
            in shelfManager.Slots)
        {
            if (slot == null ||
                !slot.IsUnlocked ||
                slot.IsEmpty)
            {
                continue;
            }

            Dessert dessert =
                slot.CurrentDessert;

            if (dessert == null)
                continue;

            if (dessert.Definition ==
                dessertDefinition)
            {
                count++;
            }
        }

        return count;
    }
}