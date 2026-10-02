using System.Collections.Generic;

public class CustomerOrder
{
    private readonly int orderId;
    private readonly CustomerOrderDefinition definition;

    public int OrderId =>
        orderId;

    public CustomerOrderDefinition Definition =>
        definition;

    public string DisplayName =>
        definition != null
            ? definition.DisplayName
            : "Invalid Order";

    public int CashReward =>
        definition != null
            ? definition.CashReward
            : 0;

    public bool IsValid =>
        definition != null &&
        definition.IsValid;

    public CustomerOrder(
        int orderId,
        CustomerOrderDefinition definition)
    {
        this.orderId =
            orderId;

        this.definition =
            definition;
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
            in definition.Requirements)
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
            in definition.Requirements)
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