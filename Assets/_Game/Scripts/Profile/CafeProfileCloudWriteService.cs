using System;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;
using Unity.Services.Authentication;
using Unity.Services.CloudSave;
using Unity.Services.CloudSave.Models;
using Unity.Services.Core;
using UnityEngine;
using SweetMerge.Analytics;

namespace SweetMerge.Profile
{
    public enum CafeProfileCloudWriteStatus
    {
        Confirmed,
        AlreadyRegistered,
        InvalidName,
        ExistingProfileInvalid,
        AuthenticationUnavailable,
        DuplicateRequest,
        StaleRequest,
        Uncertain,
        ServiceError
    }

    public sealed class CafeProfileCloudWriteResult
    {
        public CafeProfileCloudWriteStatus Status { get; }
        public CafeProfileCloudRecord Record { get; }
        public string ErrorMessage { get; }

        private CafeProfileCloudWriteResult(
            CafeProfileCloudWriteStatus status,
            CafeProfileCloudRecord record,
            string errorMessage)
        {
            Status = status;
            Record = record;
            ErrorMessage = errorMessage;
        }

        internal static CafeProfileCloudWriteResult Create(
            CafeProfileCloudWriteStatus status,
            CafeProfileCloudRecord record,
            string errorMessage)
        {
            return new CafeProfileCloudWriteResult(
                status,
                record,
                errorMessage);
        }
    }

    public sealed class CafeProfileCloudWriteService : IDisposable
    {
        private readonly CafeProfileCloudReadService readService =
            new CafeProfileCloudReadService();
        private readonly SemaphoreSlim writeGate =
            new SemaphoreSlim(1, 1);
        private int requestGeneration;
        private bool disposed;
        private bool authenticationSubscribed;

        public async Task<CafeProfileCloudWriteResult> RegisterAsync(
            string proposedName)
        {
            if (disposed)
                return Result(
                    CafeProfileCloudWriteStatus.ServiceError,
                    "Cafe Profile writer has been disposed.");

            if (!writeGate.Wait(0))
                return Result(
                    CafeProfileCloudWriteStatus.DuplicateRequest,
                    "A Cafe Profile registration is already in progress.");

            string requestPlayerId = null;
            int requestGeneration = -1;
            try
            {
                await UnityServicesInitializer.InitializeAsync();
                if (disposed)
                    return Result(
                        CafeProfileCloudWriteStatus.StaleRequest,
                        "The Cafe Profile writer was disposed.");

                SubscribeToAuthentication();
                string trimmedName = proposedName == null
                    ? string.Empty
                    : proposedName.Trim();
                if (trimmedName.Length == 0 ||
                    trimmedName.Length > 20)
                {
                    return Result(
                        CafeProfileCloudWriteStatus.InvalidName,
                        "Cafe names must contain 1 to 20 characters.");
                }

                if (!TryGetAuthenticatedPlayer(
                        out requestPlayerId,
                        out requestGeneration))
                {
                    return Result(
                        CafeProfileCloudWriteStatus.AuthenticationUnavailable,
                        "A verified Unity Authentication player is required.");
                }

                CafeProfileCloudReadResult existing =
                    await readService.LoadAsync();
                if (!IsCurrentAccount(
                        requestPlayerId,
                        requestGeneration))
                    return StaleResult();

                if (existing.Status ==
                    CafeProfileCloudReadStatus.Success)
                {
                    return CafeProfileCloudWriteResult.Create(
                        CafeProfileCloudWriteStatus.AlreadyRegistered,
                        existing.Record,
                        "A Cafe Profile is already registered.");
                }

                if (existing.Status ==
                    CafeProfileCloudReadStatus.InvalidProfileData)
                {
                    return Result(
                        CafeProfileCloudWriteStatus.ExistingProfileInvalid,
                        existing.ErrorMessage);
                }

                if (existing.Status !=
                    CafeProfileCloudReadStatus.RecordMissing)
                {
                    return Result(
                        CafeProfileCloudWriteStatus.ServiceError,
                        existing.ErrorMessage ??
                        "The existing Cafe Profile could not be verified.");
                }

                string profileJson = JsonUtility.ToJson(
                    new CafeProfileCloudRecordData
                    {
                        cafeName = trimmedName,
                        namingCompleted = true
                    });

                await CloudSaveService.Instance.Data.Player.SaveAsync(
                    new Dictionary<string, SaveItem>
                    {
                        [CafeProfileCloudReadService.CafeProfileKey] =
                            new SaveItem(profileJson, null)
                    },
                    new Unity.Services.CloudSave.Models.Data.Player.SaveOptions());

                if (!IsCurrentAccount(
                        requestPlayerId,
                        requestGeneration))
                    return StaleResult();

                CafeProfileCloudReadResult acknowledged =
                    await readService.LoadAsync();
                if (!IsCurrentAccount(
                        requestPlayerId,
                        requestGeneration))
                    return StaleResult();

                if (acknowledged.Status ==
                    CafeProfileCloudReadStatus.Success &&
                    acknowledged.Record != null)
                {
                    if (acknowledged.Record.CafeName.Trim() ==
                        trimmedName)
                    {
                        return CafeProfileCloudWriteResult.Create(
                            CafeProfileCloudWriteStatus.Confirmed,
                            acknowledged.Record,
                            null);
                    }

                    return CafeProfileCloudWriteResult.Create(
                        CafeProfileCloudWriteStatus.AlreadyRegistered,
                        acknowledged.Record,
                        "A different Cafe Profile is already registered.");
                }

                return Result(
                    CafeProfileCloudWriteStatus.Uncertain,
                    acknowledged.ErrorMessage ??
                    "Cafe Profile was saved but cloud acknowledgment is uncertain.");
            }
            catch (Exception exception)
            {
                if (!IsCurrentAccount(
                        requestPlayerId,
                        requestGeneration))
                {
                    return StaleResult();
                }

                return Result(
                    CafeProfileCloudWriteStatus.Uncertain,
                    "Cafe Profile save acknowledgment is uncertain: " +
                    exception.Message);
            }
            finally
            {
                writeGate.Release();
            }
        }

        public void Dispose()
        {
            if (disposed)
                return;

            disposed = true;
            requestGeneration++;
            if (authenticationSubscribed)
            {
                IAuthenticationService authentication =
                    AuthenticationService.Instance;
                authentication.SignedIn -= HandleAuthenticationChanged;
                authentication.SignedOut -= HandleAuthenticationChanged;
                authenticationSubscribed = false;
            }
        }

        private void SubscribeToAuthentication()
        {
            if (authenticationSubscribed)
                return;

            IAuthenticationService authentication =
                AuthenticationService.Instance;
            authentication.SignedIn += HandleAuthenticationChanged;
            authentication.SignedOut += HandleAuthenticationChanged;
            authenticationSubscribed = true;
        }

        private void HandleAuthenticationChanged()
        {
            requestGeneration++;
        }

        private bool TryGetAuthenticatedPlayer(
            out string playerId,
            out int generation)
        {
            playerId = null;
            generation = requestGeneration;
            IAuthenticationService authentication =
                AuthenticationService.Instance;
            if (!authentication.IsSignedIn ||
                !authentication.IsAuthorized ||
                string.IsNullOrWhiteSpace(authentication.PlayerId))
                return false;

            playerId = authentication.PlayerId;
            return true;
        }

        private bool IsCurrentAccount(
            string playerId,
            int generation)
        {
            if (disposed || generation != requestGeneration)
                return false;

            IAuthenticationService authentication =
                AuthenticationService.Instance;
            return authentication.IsSignedIn &&
                authentication.IsAuthorized &&
                authentication.PlayerId == playerId;
        }

        private static CafeProfileCloudWriteResult Result(
            CafeProfileCloudWriteStatus status,
            string message)
        {
            return CafeProfileCloudWriteResult.Create(
                status,
                null,
                message);
        }

        private static CafeProfileCloudWriteResult StaleResult()
        {
            return Result(
                CafeProfileCloudWriteStatus.StaleRequest,
                "The authenticated player changed during registration.");
        }

        [Serializable]
        private sealed class CafeProfileCloudRecordData
        {
            public string cafeName;
            public bool namingCompleted;
        }
    }
}
