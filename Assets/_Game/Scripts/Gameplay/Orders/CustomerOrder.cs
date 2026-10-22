using System.Collections.Generic;

public class CustomerOrder
{
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
        foreach (OrderRequirement requirement in generatedRequirements)
        {
            if (requirement == null ||
                requirement.Dessert == null ||
                requirement.Dessert.Tier < 1 ||
                requirement.Dessert.Tier > 30 ||
                requirement.Amount <= 0 ||
                !usedDesserts.Add(requirement.Dessert))
            {
                return false;
            }
        }

        return true;
    }

    // --------------------------------------------------
    // FULFILLMENT
    // --------------------------------------------------

    public bool CanFulfill(
        GridManager gridManager)
    {
        if (!IsValid)
            return false;

        if (gridManager == null)
            return false;

        foreach (
            OrderRequirement requirement
            in Requirements)
        {
            int availableAmount =
                CountDessertOnBoard(
                    gridManager,
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
        GridManager gridManager,
        DessertDefinition dessertDefinition)
    {
        return CountDessertOnBoard(
            gridManager,
            dessertDefinition
        );
    }

    public bool TryGetDessertsForFulfillment(
        GridManager gridManager,
        out List<Dessert> desserts)
    {
        desserts =
            new List<Dessert>();

        if (!CanFulfill(
                gridManager))
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
                GridCell cell
                in gridManager.Cells)
            {
                if (remaining <= 0)
                    break;

                if (cell == null ||
                    !cell.IsUnlocked ||
                    cell.IsEmpty)
                {
                    continue;
                }

                Dessert dessert =
                    cell.CurrentDessert;

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
    // BOARD INVENTORY
    // --------------------------------------------------

    private int CountDessertOnBoard(
        GridManager gridManager,
        DessertDefinition dessertDefinition)
    {
        if (gridManager == null ||
            dessertDefinition == null)
        {
            return 0;
        }

        int count = 0;

        foreach (
            GridCell cell
            in gridManager.Cells)
        {
            if (cell == null ||
                !cell.IsUnlocked ||
                cell.IsEmpty)
            {
                continue;
            }

            Dessert dessert =
                cell.CurrentDessert;

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