#if UNITY_EDITOR || (UNITY_ANDROID && DEVELOPMENT_BUILD)
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using UnityEngine.SceneManagement;

internal sealed class DeveloperCheatCommandResult
{
    internal bool Applied { get; }
    internal bool Saved { get; }
    internal string Message { get; }

    internal DeveloperCheatCommandResult(
        bool applied,
        bool saved,
        string message)
    {
        Applied = applied;
        Saved = saved;
        Message = message;
    }
}

internal static class DeveloperCheatCommands
{
    internal static DeveloperCheatCommandResult AddCash(int amount)
    {
        if (!TryGetReadyManagers(
                out PlayerProgressionManager progression,
                out EconomyManager economy,
                out SaveManager save,
                out GridManager grid,
                out DessertSpawner spawner,
                out string unavailableReason))
        {
            return Failure(unavailableReason);
        }

        if (amount <= 0 ||
            economy.CurrentCash > int.MaxValue - amount)
        {
            return Failure("Cash amount must be positive and cannot overflow.");
        }

        economy.AddCash(amount);
        return AppliedAndSaved(save, "Cash added.");
    }

    internal static DeveloperCheatCommandResult SetEnergyToZero()
    {
        if (!TryGetReadyManagers(
                out PlayerProgressionManager progression,
                out _,
                out SaveManager save,
                out _,
                out _,
                out string unavailableReason))
        {
            return Failure(unavailableReason);
        }

        if (!progression.SetEnergyForDevelopment(0))
            return Failure("Energy rejected the requested zero value.");

        return AppliedAndSaved(save, "Energy set to 0/30.");
    }

    internal static DeveloperCheatCommandResult RefillEnergy()
    {
        if (!TryGetReadyManagers(
                out PlayerProgressionManager progression,
                out _,
                out SaveManager save,
                out _,
                out _,
                out string unavailableReason))
        {
            return Failure(unavailableReason);
        }

        progression.ResetEnergy();
        return AppliedAndSaved(
            save,
            $"Energy refilled to {progression.MaximumEnergy}/{progression.MaximumEnergy}.");
    }

    internal static DeveloperCheatCommandResult SetRebirth(int rebirthCount)
    {
        if (!TryGetReadyManagers(
                out PlayerProgressionManager progression,
                out EconomyManager economy,
                out SaveManager save,
                out GridManager grid,
                out DessertSpawner spawner,
                out string unavailableReason))
        {
            return Failure(unavailableReason);
        }

        if (rebirthCount < 0 || rebirthCount > 10)
            return Failure("Rebirth must be between R0 and R10.");

        if (!progression.RestoreRebirthProgression(
                rebirthCount,
                rebirthCount == 10 ? 29 : 0,
                false))
        {
            return Failure("Progression rejected the requested rebirth state.");
        }

        return AppliedAndSaved(
            save,
            "Rebirth set to R" + rebirthCount +
            "; Oven derived as L" + progression.OvenLevel +
            "; run tier reset; cash unchanged.");
    }

    internal static DeveloperCheatCommandResult SpawnDessert(int tier)
    {
        if (!TryGetReadyManagers(
                out PlayerProgressionManager progression,
                out EconomyManager economy,
                out SaveManager save,
                out GridManager grid,
                out DessertSpawner spawner,
                out string unavailableReason))
        {
            return Failure(unavailableReason);
        }

        if (!progression.IsDessertTierUnlocked(tier))
            return Failure("Requested tier exceeds the current merge-tier cap.");

        DessertDefinition definition =
            spawner.GetDessertDefinitionByTier(tier);
        if (definition == null || definition.Tier != tier)
            return Failure("No registered dessert definition exists for that tier.");

        if (!grid.TryGetEmptyCell(out GridCell cell))
            return Failure("No unlocked empty board cell is available.");

        Dessert dessert = spawner.SpawnDessert(definition, cell);
        if (dessert == null ||
            cell.CurrentDessert != dessert ||
            dessert.CurrentCell != cell)
        {
            return Failure("Dessert placement failed board registration.");
        }

        grid.NotifyBoardChanged();
        return AppliedAndSaved(
            save,
            "Placed T" + tier +
            " without raising dessert-created or merge events.");
    }

    internal static DeveloperCheatCommandResult ClearBoardDesserts()
    {
        if (!TryGetReadyManagers(
                out PlayerProgressionManager progression,
                out EconomyManager economy,
                out SaveManager save,
                out GridManager grid,
                out DessertSpawner spawner,
                out string unavailableReason))
        {
            return Failure(unavailableReason);
        }

        var occupiedCells = new List<GridCell>();
        foreach (GridCell cell in grid.Cells)
        {
            if (cell == null)
                return Failure("Board contains an invalid cell.");

            Dessert dessert = cell.CurrentDessert;
            if (dessert == null)
                continue;

            if (dessert.CurrentCell != cell ||
                dessert.LocationType != DessertLocationType.Board)
            {
                return Failure(
                    "Board occupancy is inconsistent; nothing was cleared.");
            }

            occupiedCells.Add(cell);
        }

        foreach (GridCell cell in occupiedCells)
        {
            Dessert dessert = cell.CurrentDessert;
            cell.RemoveDessert(dessert);
            Object.Destroy(dessert.gameObject);
        }

        grid.NotifyBoardChanged();
        return AppliedAndSaved(save, "Board desserts cleared.");
    }

    internal static DeveloperCheatCommandResult ResetAllProgress()
    {
        if (!TryGetReadyManagers(
                out PlayerProgressionManager progression,
                out EconomyManager economy,
                out SaveManager save,
                out GridManager grid,
                out DessertSpawner spawner,
                out string unavailableReason))
        {
            return Failure(unavailableReason);
        }

        GameStartupCoordinator startup = GameStartupCoordinator.Instance;
        if (startup == null || MergeSessionManager.Instance == null)
            return Failure("A required reset dependency is unavailable.");
        if (!progression.ValidateRestorationDefinitions(out string reason))
            return Failure(reason);

        if (!progression.RestoreRebirthProgression(0, 0, false))
            return Failure("Progression rejected the fresh-game reset.");

        progression.RestoreProgression(1, 1, 1, 1, 1, 1);
        progression.ResetEnergy();
        economy.RestoreCash(0);
        MergeSessionManager.Instance.ClearSession();
        SessionManager.Instance?.ResetSession();

        if (!save.TryResetDevelopmentProfileFiles(out string resetMessage))
        {
            bool restored = save.LoadCurrentGame();
            return Failure(
                resetMessage +
                (restored
                    ? " The previous development profile was reloaded."
                    : " The previous profile could not be reloaded; startup recovery is required."));
        }

        if (!startup.BeginFreshDevelopmentGame())
        {
            startup.ReportGameplayRestorationFailure(
                "Development profile files were reset, but fresh-game startup could not be prepared.");
            return Failure(
                "Profile files were reset, but the game could not prepare a fresh startup. Restart the development app.");
        }

        UnityEngine.SceneManagement.SceneManager.LoadScene("Game");
        return new DeveloperCheatCommandResult(
            true,
            true,
            "Progress reset to a fresh development profile. " + resetMessage);
    }

    internal static DeveloperCheatCommandResult RefreshCustomerOrders()
    {
        if (!TryGetReadyManagers(
                out PlayerProgressionManager progression,
                out EconomyManager economy,
                out SaveManager save,
                out GridManager grid,
                out DessertSpawner spawner,
                out string unavailableReason))
        {
            return Failure(unavailableReason);
        }

        OrderManager orders = Object.FindAnyObjectByType<OrderManager>();
        MergeSessionController controller =
            Object.FindAnyObjectByType<MergeSessionController>();
        if (orders == null || controller == null ||
            !controller.IsRestorationVerified)
        {
            return Failure(
                "Order refresh requires a verified gameplay session.");
        }

        if (!orders.TryPrepareOrderRefresh(
                out CustomerOrderState[] preparedOrders,
                out int preparedNextOrderId,
                out string reason))
        {
            return Failure(reason);
        }

        OrderManager.SessionReplacementState previousState =
            orders.CaptureSessionReplacementState();
        if (!orders.ApplyPreparedOrderRefresh(
                preparedOrders,
                preparedNextOrderId))
        {
            return Failure(
                "Prepared replacement orders could not be applied.");
        }

        if (!save.SaveCurrentGame())
        {
            orders.RestoreSessionReplacementState(previousState);
            bool sessionRestored = controller.TryCaptureSession();
            return Failure(
                sessionRestored
                    ? "Order refresh save failed; the previous orders and order ID sequence were restored."
                    : "Order refresh save failed; orders were restored in memory, but the session snapshot could not be recaptured.");
        }

        orders.PublishOrderRefresh();
        return new DeveloperCheatCommandResult(
            true,
            true,
            "All unlocked Table orders were refreshed and saved.");
    }

    private static bool TryGetReadyManagers(
        out PlayerProgressionManager progression,
        out EconomyManager economy,
        out SaveManager save,
        out GridManager grid,
        out DessertSpawner spawner,
        out string unavailableReason)
    {
        unavailableReason = GetUnavailableReason(
            out progression,
            out economy,
            out save,
            out grid,
            out spawner);
        return unavailableReason == null;
    }

    internal static string GetAvailabilityMessage()
    {
        return GetUnavailableReason(
            out _,
            out _,
            out _,
            out _,
            out _);
    }

    private static string GetUnavailableReason(
        out PlayerProgressionManager progression,
        out EconomyManager economy,
        out SaveManager save,
        out GridManager grid,
        out DessertSpawner spawner)
    {
        progression = PlayerProgressionManager.Instance;
        economy = EconomyManager.Instance;
        save = SaveManager.Instance;
        grid = Object.FindAnyObjectByType<GridManager>();
        spawner = Object.FindAnyObjectByType<DessertSpawner>();

        if (!SavePathPolicy.IsDevelopmentSaveIsolationEnabled)
            return "Development save isolation is disabled.";

#if UNITY_ANDROID && DEVELOPMENT_BUILD
        if (!Application.identifier.EndsWith(
                ".dev",
                System.StringComparison.OrdinalIgnoreCase))
        {
            return "Android development application ID must end in '.dev'.";
        }
#endif

        if (save != null &&
            !string.Equals(
                Path.GetFullPath(save.SaveDirectory),
                Path.GetFullPath(SavePathPolicy.GetSaveDirectory()),
                System.StringComparison.OrdinalIgnoreCase))
        {
            return "Active save directory does not match the development-isolated path.";
        }

        if (SceneManager.GetActiveScene().name != "Game")
            return "Open the Game scene to use development commands.";
        if (progression == null ||
            economy == null ||
            save == null ||
            grid == null ||
            spawner == null)
        {
            return "A required gameplay manager is not available.";
        }
        if (grid.IsMergeTransactionActive)
            return "Wait for the active merge transaction to finish.";
        if (GameStartupCoordinator.Instance == null ||
            !GameStartupCoordinator.Instance.IsGameplayReady ||
            !save.IsLifecycleSavingReady)
        {
            return GameStartupCoordinator.Instance != null &&
                   GameStartupCoordinator.Instance.LastFailureReason != null
                ? GameStartupCoordinator.Instance.LastFailureReason
                : "Gameplay restoration is not ready.";
        }

        MergeSessionController[] controllers =
            Object.FindObjectsByType<MergeSessionController>();
        if (controllers.Length != 1 ||
            !controllers[0].IsRestorationVerified)
        {
            return "The active board restoration is not verified.";
        }

        if (progression.CampaignComplete &&
            progression.CampaignCompletionPersistence !=
                CampaignCompletionPersistenceState.Saved)
        {
            return "Campaign completion persistence is pending.";
        }

        return null;
    }

    private static DeveloperCheatCommandResult AppliedAndSaved(
        SaveManager save,
        string successMessage)
    {
        bool saved = save.SaveCurrentGame();
        return new DeveloperCheatCommandResult(
            true,
            saved,
            saved
                ? successMessage + " Development V2 save validated and written."
                : successMessage + " State changed in memory, but the V2 save failed.");
    }

    private static DeveloperCheatCommandResult Failure(string message)
    {
        return new DeveloperCheatCommandResult(false, false, message);
    }
}
#endif
