using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Newtonsoft.Json;
using Unity.Services.CloudCode.Apis;
using Unity.Services.CloudCode.Apis.Extensions;
using Unity.Services.CloudCode.Core;
using Unity.Services.CloudCode.Shared;
using Unity.Services.CloudSave.Model;

namespace CafeProfileRegistrationPrototype;

public sealed class ModuleConfig : ICloudCodeSetup
{
    public void Setup(ICloudCodeConfig config)
    {
        config.AddGameApiClient();
    }
}

public sealed class CafeProfileRegistrationModule
{
    private const string LedgerCustomId = "cafe-registration-ledger-prototype";
    private const string LedgerKey = "registrations";
    private const int MaxNameLength = 20;
    private const int MaxCasAttempts = 4;

    [CloudCodeFunction("RegisterCafeNamePrototype")]
    public async Task<RegistrationResponse> RegisterCafeName(
        IExecutionContext context,
        IGameApiClient gameApiClient,
        string name)
    {
        string? playerId = context.PlayerId;
        if (string.IsNullOrWhiteSpace(playerId))
        {
            return RegistrationResponse.AuthenticationUnavailable();
        }

        string? normalizedName = NormalizeName(name);
        if (normalizedName == null)
        {
            return RegistrationResponse.InvalidName();
        }

        for (int attempt = 1; attempt <= MaxCasAttempts; attempt++)
        {
            LedgerRead ledgerRead;
            try
            {
                ledgerRead = await ReadLedgerAsync(
                    context,
                    gameApiClient);
            }
            catch (Exception exception) when (exception is ApiException)
            {
                return RegistrationResponse.ServiceFailure(
                    "The registration ledger could not be read.");
            }
            catch (LedgerStateException)
            {
                return RegistrationResponse.LedgerInvalid();
            }

            if (ledgerRead.EntryByPlayerId.TryGetValue(
                    playerId,
                    out string? registeredName))
            {
                return RegistrationResponse.AlreadyRegistered(registeredName);
            }

            ledgerRead.EntryByPlayerId.Add(playerId, normalizedName);

            try
            {
                await gameApiClient.CloudSaveData.SetCustomItemAsync(
                    context,
                    context.ServiceToken,
                    context.ProjectId,
                    LedgerCustomId,
                    new SetItemBody(
                        LedgerKey,
                        new RegistrationLedger
                        {
                            Version = ledgerRead.Version,
                            Entries = ledgerRead.EntryByPlayerId
                        },
                        ledgerRead.WriteLock));

                return RegistrationResponse.Registered(normalizedName);
            }
            catch (ApiException exception) when (
                IsWriteLockConflict(exception))
            {
                if (attempt == MaxCasAttempts)
                {
                    return RegistrationResponse.Conflict();
                }

                await Task.Delay(
                    TimeSpan.FromMilliseconds(50 * attempt));
            }
            catch (ApiException)
            {
                return RegistrationResponse.UnknownWriteOutcome();
            }
            catch (Exception)
            {
                return RegistrationResponse.UnknownWriteOutcome();
            }
        }

        return RegistrationResponse.Conflict();
    }

    private async Task<LedgerRead> ReadLedgerAsync(
        IExecutionContext context,
        IGameApiClient gameApiClient)
    {
        var response = await gameApiClient.CloudSaveData.GetCustomItemsAsync(
            context,
            context.ServiceToken,
            context.ProjectId,
            LedgerCustomId,
            new List<string> { LedgerKey });

        var results = response.Data.Results;
        if (results == null || results.Count != 1)
        {
            throw new LedgerStateException(
                "The pre-provisioned registration ledger is missing.");
        }

        var item = results[0];
        if (item.Value == null ||
            string.IsNullOrWhiteSpace(item.WriteLock))
        {
            throw new LedgerStateException(
                "The registration ledger item is malformed.");
        }

        RegistrationLedger? ledger;
        try
        {
            ledger = JsonConvert.DeserializeObject<RegistrationLedger>(
                item.Value.ToString());
        }
        catch (JsonException exception)
        {
            throw new LedgerStateException(
                "The registration ledger value is malformed.",
                exception);
        }

        if (ledger == null ||
            ledger.Version != 1 ||
            ledger.Entries == null ||
            ledger.Entries.Keys.Any(string.IsNullOrWhiteSpace) ||
            ledger.Entries.Values.Any(value =>
                NormalizeName(value) == null))
        {
            throw new LedgerStateException(
                "The registration ledger value is invalid.");
        }

        return new LedgerRead(
            ledger.Version,
            new Dictionary<string, string>(ledger.Entries),
            item.WriteLock);
    }

    private static string? NormalizeName(string? name)
    {
        string normalized = name?.Trim() ?? string.Empty;
        return normalized.Length == 0 ||
               normalized.Length > MaxNameLength
            ? null
            : normalized;
    }

    private static bool IsWriteLockConflict(ApiException exception)
    {
        return exception.Response?.StatusCode == System.Net.HttpStatusCode.Conflict;
    }

    private sealed class LedgerRead
    {
        public LedgerRead(
            int version,
            Dictionary<string, string> entryByPlayerId,
            string writeLock)
        {
            Version = version;
            EntryByPlayerId = entryByPlayerId;
            WriteLock = writeLock;
        }

        public int Version { get; }
        public Dictionary<string, string> EntryByPlayerId { get; }
        public string WriteLock { get; }
    }

    private sealed class LedgerStateException : Exception
    {
        public LedgerStateException(string message)
            : base(message)
        {
        }

        public LedgerStateException(string message, Exception innerException)
            : base(message, innerException)
        {
        }
    }
}

public sealed class RegistrationLedger
{
    public int Version { get; set; }
    public Dictionary<string, string> Entries { get; set; } = new();
}

public enum RegistrationOutcome
{
    Registered,
    AlreadyRegistered,
    InvalidName,
    AuthenticationUnavailable,
    LedgerInvalid,
    Conflict,
    ServiceFailure,
    UnknownWriteOutcome
}

public sealed class RegistrationResponse
{
    private RegistrationResponse(
        RegistrationOutcome outcome,
        string? cafeName,
        string? message)
    {
        Outcome = outcome;
        CafeName = cafeName;
        Message = message;
    }

    public RegistrationOutcome Outcome { get; }
    public string? CafeName { get; }
    public string? Message { get; }

    public static RegistrationResponse Registered(string name) =>
        new(RegistrationOutcome.Registered, name, null);

    public static RegistrationResponse AlreadyRegistered(string name) =>
        new(RegistrationOutcome.AlreadyRegistered, name, null);

    public static RegistrationResponse InvalidName() =>
        new(RegistrationOutcome.InvalidName, null, "Name is invalid.");

    public static RegistrationResponse AuthenticationUnavailable() =>
        new(RegistrationOutcome.AuthenticationUnavailable, null, null);

    public static RegistrationResponse Conflict() =>
        new(RegistrationOutcome.Conflict, null, "Registration conflicted.");

    public static RegistrationResponse ServiceFailure(string message) =>
        new(RegistrationOutcome.ServiceFailure, null, message);

    public static RegistrationResponse LedgerInvalid() =>
        new(RegistrationOutcome.LedgerInvalid, null, null);

    public static RegistrationResponse UnknownWriteOutcome() =>
        new(RegistrationOutcome.UnknownWriteOutcome, null, null);
}
