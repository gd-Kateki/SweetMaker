using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using Unity.Services.Authentication;
using Unity.Services.CloudSave;
using Unity.Services.CloudSave.Models;
using Unity.Services.CloudSave.Models.Data.Player;
using Unity.Services.Core;
using UnityEngine;
using SweetMerge.Analytics;

namespace SweetMerge.Profile
{
    public enum CafeProfileCloudReadStatus
    {
        Success,
        RecordMissing,
        AuthenticationUnavailable,
        InvalidProfileData,
        ServiceError
    }

    public sealed class CafeProfileCloudRecord
    {
        public string CafeName { get; }
        public bool NamingCompleted { get; }

        public CafeProfileCloudRecord(
            string cafeName,
            bool namingCompleted)
        {
            CafeName = cafeName;
            NamingCompleted = namingCompleted;
        }
    }

    public sealed class CafeProfileCloudReadResult
    {
        public CafeProfileCloudReadStatus Status { get; }
        public CafeProfileCloudRecord Record { get; }
        public string ErrorMessage { get; }

        private CafeProfileCloudReadResult(
            CafeProfileCloudReadStatus status,
            CafeProfileCloudRecord record,
            string errorMessage)
        {
            Status = status;
            Record = record;
            ErrorMessage = errorMessage;
        }

        public static CafeProfileCloudReadResult Success(
            CafeProfileCloudRecord record)
        {
            return new CafeProfileCloudReadResult(
                CafeProfileCloudReadStatus.Success,
                record,
                null);
        }

        public static CafeProfileCloudReadResult Missing()
        {
            return new CafeProfileCloudReadResult(
                CafeProfileCloudReadStatus.RecordMissing,
                null,
                null);
        }

        public static CafeProfileCloudReadResult AuthenticationUnavailable(
            string message)
        {
            return new CafeProfileCloudReadResult(
                CafeProfileCloudReadStatus.AuthenticationUnavailable,
                null,
                message);
        }

        public static CafeProfileCloudReadResult ServiceError(
            string message)
        {
            return new CafeProfileCloudReadResult(
                CafeProfileCloudReadStatus.ServiceError,
                null,
                message);
        }

        public static CafeProfileCloudReadResult InvalidProfileData(
            string message)
        {
            return new CafeProfileCloudReadResult(
                CafeProfileCloudReadStatus.InvalidProfileData,
                null,
                message);
        }
    }

    public sealed class CafeProfileCloudReadService
    {
        public const string CafeProfileKey = "cafeProfile";

        public async Task<CafeProfileCloudReadResult> LoadAsync()
        {
            try
            {
                await UnityServicesInitializer.InitializeAsync();
            }
            catch (Exception exception)
            {
                return ReportServiceError(
                    "Unity Services initialization failed.",
                    exception);
            }

            if (UnityServices.State != ServicesInitializationState.Initialized)
            {
                return CafeProfileCloudReadResult.AuthenticationUnavailable(
                    "Unity Services are not initialized.");
            }

            IAuthenticationService authentication =
                AuthenticationService.Instance;
            if (!authentication.IsSignedIn ||
                !authentication.IsAuthorized ||
                string.IsNullOrWhiteSpace(authentication.PlayerId))
            {
                return CafeProfileCloudReadResult
                    .AuthenticationUnavailable(
                        "A verified Unity Authentication player is required.");
            }

            try
            {
                Dictionary<string, Item> data =
                    await CloudSaveService.Instance.Data.Player.LoadAsync(
                        new HashSet<string> { CafeProfileKey },
                        new LoadOptions());

                if (!data.TryGetValue(CafeProfileKey, out var item))
                    return CafeProfileCloudReadResult.Missing();

                string profileJson = item.Value.GetAsString();
                if (string.IsNullOrWhiteSpace(profileJson))
                {
                    return ReportServiceError(
                        "The Cafe Profile record is empty.",
                        null);
                }

                CafeProfileCloudRecordData dataModel =
                    JsonUtility.FromJson<CafeProfileCloudRecordData>(
                        profileJson);
                if (dataModel == null ||
                    !dataModel.IsValid())
                {
                    return CafeProfileCloudReadResult.InvalidProfileData(
                        "The Cafe Profile record is malformed or incomplete.");
                }

                CafeProfileCloudRecord record = dataModel.ToRecord();
                return CafeProfileCloudReadResult.Success(record);
            }
            catch (Exception exception)
            {
                return ReportServiceError(
                    "Cafe Profile Cloud Save read failed.",
                    exception);
            }
        }

        private static CafeProfileCloudReadResult ReportServiceError(
            string message,
            Exception exception)
        {
            string detail = exception == null
                ? message
                : message + " " + exception.Message;
            Debug.LogError("CAFE PROFILE | " + detail);
            return CafeProfileCloudReadResult.ServiceError(detail);
        }

        [Serializable]
        private sealed class CafeProfileCloudRecordData
        {
            public string cafeName;
            public bool namingCompleted;

            public CafeProfileCloudRecord ToRecord()
            {
                return new CafeProfileCloudRecord(
                    cafeName,
                    namingCompleted);
            }

            public bool IsValid()
            {
                return namingCompleted &&
                       !string.IsNullOrWhiteSpace(cafeName) &&
                       cafeName.Trim().Length <= 20;
            }
        }
    }
}
