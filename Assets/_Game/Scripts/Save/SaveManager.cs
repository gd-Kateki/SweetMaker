using System;

using System.Collections.Generic;

using System.IO;

using System.Text;
using UnityEngine;

public enum DessertCollectionClaimResult
{
    Success,
    InvalidMilestone,
    NotEligible,
    AlreadyClaimed,
    CashOverflow,
    SaveFailure,
    TransactionUnavailable,
    CommitUncertain
}

public enum FeatureIntroduction
{
    Upgrades,
    Rebirth,
    Collection
}

public class SaveManager : MonoBehaviour

{
    private void SanitizeCustomerOrders(System.Collections.Generic.List<CustomerOrderSaveData> orders) { SanitizeCustomerOrdersCore(orders); }
    private void SanitizeShelfDesserts(System.Collections.Generic.List<ShelfDessertSaveData> desserts) { SanitizeShelfDessertsCore(desserts); }
    private void SanitizeBoardDesserts(System.Collections.Generic.List<BoardDessertSaveData> desserts) { SanitizeBoardDessertsCore(desserts); }
    private void SanitizeSaveData(PlayerSaveData saveData) { SanitizeSaveDataCore(saveData); }
    private bool IsSupportedVersion(int version) { return IsSupportedVersionCore(version); }
    private bool IsValidSerializedSnapshot(string json) { return IsValidSerializedSnapshotCore(json); }
    private bool IsValidBackupCandidate(byte[] bytes) { return IsValidBackupCandidateCore(bytes); }

    // Root JSON extension avoids changing the project's existing data classes.

    // It describes the MERGE SNAPSHOT, never the latest purchased progression.

    [Serializable]

    private class CustomerCapacityMetadata

    {

        public int mergeSessionCustomerCapacity;
        public string selectedSpawnPoolId;
        public int luckLevel;
        public int servingPlateProgressionVersion;

    }

    [Serializable]
    private class EnergySaveMetadata
    {
        public int currentEnergy;
        public int energyMillisecondsUntilNextPoint;
        public long energySavedUtcTicks;
    }

    private sealed class SessionPublicationRecord
    {
        private readonly FrozenMergeSessionValues session;
        private readonly int customerCapacity;
        private readonly SessionPublicationOwnership ownership;
        private readonly SessionPublicationEligibility eligibility;
        private readonly object ownerIdentity;
        private readonly object publicationIdentity;
        private readonly MergeSessionController sourceController;
        private readonly SessionPublicationRevocationReason revocationReason;

        public FrozenMergeSessionValues Session => session;
        public int CustomerCapacity => customerCapacity;
        public SessionPublicationOwnership Ownership => ownership;
        public SessionPublicationEligibility Eligibility => eligibility;
        public object OwnerIdentity => ownerIdentity;
        public object PublicationIdentity => publicationIdentity;
        public MergeSessionController SourceController => sourceController;
        public SessionPublicationRevocationReason RevocationReason =>
            revocationReason;

        public SessionPublicationRecord(
            FrozenMergeSessionValues session,
            int customerCapacity,
            SessionPublicationOwnership ownership,
            SessionPublicationEligibility eligibility,
            object ownerIdentity,
            MergeSessionController sourceController,
            SessionPublicationRevocationReason revocationReason)
        {
            this.session = session;
            this.customerCapacity = customerCapacity;
            this.ownership = ownership;
            this.eligibility = eligibility;
            this.ownerIdentity = ownerIdentity;
            this.sourceController = sourceController;
            this.revocationReason = revocationReason;
            publicationIdentity = new object();
        }
    }

    private readonly object sessionPublicationOwnerIdentity = new object();
    private SessionPublicationRecord currentSessionPublication;

    private bool IsExpectedSessionPublication(
        SessionPublicationRecord publication,
        SessionPublicationRecord expectedPublication,
        object expectedPublicationIdentity,
        FrozenMergeSessionValues expectedSession)
    {
        return publication != null &&
               expectedPublication != null &&
               expectedSession != null &&
               ReferenceEquals(currentSessionPublication, publication) &&
               ReferenceEquals(publication, expectedPublication) &&
               ReferenceEquals(
                   publication.PublicationIdentity,
                   expectedPublicationIdentity) &&
               ReferenceEquals(
                   publication.OwnerIdentity,
                   sessionPublicationOwnerIdentity) &&
               ReferenceEquals(publication.Session, expectedSession) &&
               publication.Session != null &&
               publication.Session.HasSession &&
               IsSupportedSessionPublicationCapacity(
                   publication.CustomerCapacity) &&
               IsOrdinarySessionPublicationOwnership(publication.Ownership) &&
               publication.Eligibility ==
                   SessionPublicationEligibility.ActivePublication &&
               publication.RevocationReason ==
                   SessionPublicationRevocationReason.None;
    }

    private static bool IsSupportedSessionPublicationCapacity(int capacity)
    {
        return capacity >= 1 && capacity <= 3;
    }

    private static bool IsOrdinarySessionPublicationOwnership(
        SessionPublicationOwnership ownership)
    {
        return ownership == SessionPublicationOwnership.LiveControllerBound ||
               ownership == SessionPublicationOwnership.ReleasedSnapshotBound;
    }

    private PlayerSaveData capacityLoadedData;

    private int loadedCustomerCapacity;

    private MergeSessionData capacitySession;

    private string capacityFingerprint;

    private int sessionCustomerCapacity;
    private string loadedSelectedSpawnPoolId;
    private string sessionSelectedSpawnPoolId;
    private int loadedLuckLevel = 1;
    private int sessionLuckLevel = 1;
    private int loadedServingPlateProgressionVersion;
    private EnergySaveMetadata loadedEnergyMetadata;

    public void RecordSessionCustomerCapacity(
        MergeSessionData data,
        int capacity,
        string selectedPoolId = null)

    {

        capacitySession = data;

        capacityFingerprint = RestorationVerification.Fingerprint(data);

        sessionCustomerCapacity = capacity;
        if (selectedPoolId != null &&
            DessertSpawner.IsValidSpawnPoolId(selectedPoolId))
        {
            sessionSelectedSpawnPoolId = selectedPoolId;
        }

    }

    public void RecordSelectedSpawnPool(string poolId)
    {
        if (!DessertSpawner.IsValidSpawnPoolId(poolId))
        {
            Debug.LogError(
                $"SAVE | Refusing to record invalid Oven spawn pool '{poolId}'.");
            return;
        }

        sessionSelectedSpawnPoolId = poolId;
    }

    public bool RestoreSelectedSpawnPool(DessertSpawner spawner)
    {
        if (spawner == null)
        {
            Debug.LogError("LOAD | Cannot restore Oven spawn pool without DessertSpawner.");
            return false;
        }

        string selectedPool = sessionSelectedSpawnPoolId ??
                              loadedSelectedSpawnPoolId ??
                              "P1";
        return spawner.TryRestoreSpawnPool(selectedPool);
    }

    public bool TryGetSessionCustomerCapacity(MergeSessionData data, int currentCapacity,

        out int capacity)

    {

        capacity = 0;

        if (ReferenceEquals(data, capacitySession) && string.Equals(capacityFingerprint,

            RestorationVerification.Fingerprint(data), StringComparison.Ordinal))

            capacity = sessionCustomerCapacity;

        // Legacy saves can be inferred only when ALL current slots are present.

        // A shorter prefix is ambiguous; it needs an explicit backup-based migration.

        if (capacity == 0 && data != null && data.customerOrders != null &&

            data.customerOrders.Count == currentCapacity)

            capacity = currentCapacity;

        return capacity >= 1 &&
               (capacity <= currentCapacity ||
                (compatibilityMigrationPending &&
                 loadedCustomerCapacity == 4 &&
                 capacity == 4));

    }

    private static string SerializeWithCapacity(PlayerSaveData data, int capacity)

    {

        string json = JsonUtility.ToJson(data, false);

        return json.Substring(0, json.Length - 1) +

            ",\"mergeSessionCustomerCapacity\":" + capacity.ToString(System.Globalization.CultureInfo.InvariantCulture) + "}";

    }

    private static string SerializeWithSpawnPool(
        PlayerSaveData data,
        int capacity,
        string selectedPoolId)
    {
        string json = SerializeWithCapacity(data, capacity);
        if (string.IsNullOrWhiteSpace(selectedPoolId))
            return json;
        if (!DessertSpawner.IsValidSpawnPoolId(selectedPoolId))
            throw new ArgumentException(
                "Selected Oven spawn pool is invalid.",
                nameof(selectedPoolId));

        return json.Substring(0, json.Length - 1) +
               ",\"selectedSpawnPoolId\":\"" + selectedPoolId + "\"}";
    }

    private static string SerializeWithLuck(
        PlayerSaveData data,
        int capacity,
        string selectedPoolId,
        int luckLevel)
    {
        string json = SerializeWithSpawnPool(data, capacity, selectedPoolId);
        if (luckLevel <= 0)
            return json;
        if (luckLevel > 4)
            throw new ArgumentOutOfRangeException(
                nameof(luckLevel),
                "Luck level must be in the range 1-4.");

        return json.Substring(0, json.Length - 1) +
               ",\"luckLevel\":" +
               luckLevel.ToString(
                   System.Globalization.CultureInfo.InvariantCulture) +
               "}";
    }

    private static string SerializeWithServingPlateVersion(
        PlayerSaveData data,
        int capacity,
        string selectedPoolId,
        int luckLevel,
        int servingPlateVersion)
    {
        string json = SerializeWithLuck(
            data,
            capacity,
            selectedPoolId,
            luckLevel);
        if (servingPlateVersion <= 0)
            return json;

        return json.Substring(0, json.Length - 1) +
               ",\"servingPlateProgressionVersion\":" +
               servingPlateVersion.ToString(
                   System.Globalization.CultureInfo.InvariantCulture) +
               "}";
    }

    private static string SerializeWithEnergy(
        string json,
        EnergySaveMetadata energy)
    {
        if (energy == null)
            throw new ArgumentNullException(nameof(energy));

        return json.Substring(0, json.Length - 1) +
               ",\"currentEnergy\":" +
               energy.currentEnergy.ToString(
                   System.Globalization.CultureInfo.InvariantCulture) +
               ",\"energyMillisecondsUntilNextPoint\":" +
               energy.energyMillisecondsUntilNextPoint.ToString(
                   System.Globalization.CultureInfo.InvariantCulture) +
               ",\"energySavedUtcTicks\":" +
               energy.energySavedUtcTicks.ToString(
                   System.Globalization.CultureInfo.InvariantCulture) +
               "}";
    }

    private static bool TryParseEnergyMetadata(
        string json,
        out EnergySaveMetadata energy,
        out bool metadataPresent)
    {
        energy = null;
        metadataPresent = false;
        if (string.IsNullOrEmpty(json))
            return false;

        int currentEnergyCount = CountJsonProperty(json, "currentEnergy");
        int remainingTimeCount = CountJsonProperty(
            json,
            "energyMillisecondsUntilNextPoint");
        int savedTimeCount = CountJsonProperty(json, "energySavedUtcTicks");
        int propertyCount =
            currentEnergyCount + remainingTimeCount + savedTimeCount;
        if (propertyCount == 0)
            return true;

        metadataPresent = true;
        if (currentEnergyCount != 1 ||
            remainingTimeCount != 1 ||
            savedTimeCount != 1)
        {
            return false;
        }

        energy = JsonUtility.FromJson<EnergySaveMetadata>(json);
        if (energy == null ||
            energy.currentEnergy < 0 ||
            energy.currentEnergy >
                PlayerProgressionManager.MaximumEnergyValue ||
            energy.energySavedUtcTicks <= 0 ||
            energy.energySavedUtcTicks > DateTime.MaxValue.Ticks)
        {
            return false;
        }

        bool legacyThirtyZeroCountdown =
            energy.currentEnergy == 30 &&
            energy.energyMillisecondsUntilNextPoint == 0;
        if (legacyThirtyZeroCountdown)
        {
            energy.energyMillisecondsUntilNextPoint = 60000;
            return true;
        }

        return energy.currentEnergy ==
                   PlayerProgressionManager.MaximumEnergyValue
               ? energy.energyMillisecondsUntilNextPoint == 0
               : energy.energyMillisecondsUntilNextPoint >= 1 &&
                 energy.energyMillisecondsUntilNextPoint <= 60000;
    }

    private static bool TryCreateLegacyEnergyNormalizedJson(
        string json,
        out string normalizedJson)
    {
        normalizedJson = json;
        if (string.IsNullOrEmpty(json))
            return false;

        EnergySaveMetadata energy =
            JsonUtility.FromJson<EnergySaveMetadata>(json);
        if (energy == null ||
            energy.currentEnergy != 30 ||
            energy.energyMillisecondsUntilNextPoint != 0)
        {
            return false;
        }

        const string propertyPrefix =
            "\"energyMillisecondsUntilNextPoint\":";
        int propertyIndex = json.IndexOf(
            propertyPrefix,
            StringComparison.Ordinal);
        if (propertyIndex < 0 ||
            json.IndexOf(
                propertyPrefix,
                propertyIndex + propertyPrefix.Length,
                StringComparison.Ordinal) >= 0)
        {
            return false;
        }

        int valueIndex = propertyIndex + propertyPrefix.Length;
        int valueEnd = valueIndex;
        while (valueEnd < json.Length &&
               json[valueEnd] >= '0' &&
               json[valueEnd] <= '9')
        {
            valueEnd++;
        }

        if (valueEnd == valueIndex ||
            json.Substring(valueIndex, valueEnd - valueIndex) != "0")
        {
            return false;
        }

        normalizedJson =
            json.Substring(0, valueIndex) +
            "60000" +
            json.Substring(valueEnd);
        return true;
    }

    private static int CountJsonProperty(string json, string propertyName)
    {
        string property = "\"" + propertyName + "\":";
        int count = 0;
        int searchIndex = 0;
        while ((searchIndex = json.IndexOf(
                    property,
                    searchIndex,
                    StringComparison.Ordinal)) >= 0)
        {
            count++;
            searchIndex += property.Length;
        }

        return count;
    }

    private static bool TryRemoveZeroStatisticProperty(
        string json,
        string propertyName,
        out string result)
    {
        result = null;
        string property = ",\"" + propertyName + "\":0";
        int index = json.IndexOf(property, StringComparison.Ordinal);
        if (index < 0 ||
            json.LastIndexOf(property, StringComparison.Ordinal) != index)
        {
            return false;
        }

        result = json.Remove(index, property.Length);
        return true;
    }

    private static bool TryCreateLegacyV2CanonicalJson(
        string currentCanonicalJson,
        out string legacyCanonicalJson)
    {
        legacyCanonicalJson = null;
        if (!TryRemoveZeroStatisticProperty(
                currentCanonicalJson,
                "totalOrdersCompleted",
                out string withoutOrders) ||
            !TryRemoveZeroStatisticProperty(
                withoutOrders,
                "totalMoneyEarned",
                out legacyCanonicalJson))
        {
            legacyCanonicalJson = null;
            return false;
        }

        return true;
    }

    private static bool TryRemoveEmptyDessertCollectionProperty(
        string json,
        out string result)
    {
        result = null;
        const string property =
            ",\"dessertCollection\":{\"discoveredTierIds\":[]," +
            "\"claimedMilestoneIds\":[]}";
        int index = json.IndexOf(property, StringComparison.Ordinal);
        if (index < 0 ||
            json.LastIndexOf(property, StringComparison.Ordinal) != index)
        {
            return false;
        }

        result = json.Remove(index, property.Length);
        return true;
    }

    private static bool MatchesSupportedCanonicalShape(
        string json,
        string canonicalJson,
        bool collectionSectionPresent,
        bool statisticsAreZero)
    {
        if (MatchesCanonicalWithOptionalIntroFlags(
                json,
                canonicalJson))
        {
            return true;
        }

        string withoutCollection = null;
        bool hasWithoutCollection =
            !collectionSectionPresent &&
            TryRemoveEmptyDessertCollectionProperty(
                canonicalJson,
                out withoutCollection);
        if (hasWithoutCollection &&
            MatchesCanonicalWithOptionalIntroFlags(
                json,
                withoutCollection))
        {
            return true;
        }

        if (!statisticsAreZero ||
            !TryCreateLegacyV2CanonicalJson(
                canonicalJson,
                out string withoutStatistics))
        {
            return false;
        }

        if (MatchesCanonicalWithOptionalIntroFlags(
                json,
                withoutStatistics))
        {
            return true;
        }

        return hasWithoutCollection &&
               TryRemoveEmptyDessertCollectionProperty(
                   withoutStatistics,
                   out string withoutCollectionOrStatistics) &&
               MatchesCanonicalWithOptionalIntroFlags(
                   json,
                   withoutCollectionOrStatistics);
    }

    private static bool MatchesCanonicalWithOptionalIntroFlags(
        string json,
        string canonicalJson)
    {
        for (int omittedMask = 0;
             omittedMask < 1 << OptionalV2IntroFlagFields.Length;
             omittedMask++)
        {
            string candidate = canonicalJson;
            bool validShape = true;
            for (int index = 0;
                 index < OptionalV2IntroFlagFields.Length;
                 index++)
            {
                if ((omittedMask & (1 << index)) == 0)
                    continue;

                if (!TryRemoveBooleanProperty(
                        candidate,
                        OptionalV2IntroFlagFields[index],
                        out string candidateWithoutFlag))
                {
                    validShape = false;
                    break;
                }

                candidate = candidateWithoutFlag;
            }

            if (validShape &&
                string.Equals(json, candidate, StringComparison.Ordinal))
            {
                return true;
            }
        }

        return false;
    }

    private static bool TryRemoveBooleanProperty(
        string json,
        string propertyName,
        out string result)
    {
        result = null;
        if (CountJsonProperty(json, propertyName) != 1)
            return false;

        string prefix = ",\"" + propertyName + "\":";
        int index = json.IndexOf(prefix, StringComparison.Ordinal);
        if (index < 0 ||
            json.LastIndexOf(prefix, StringComparison.Ordinal) != index)
        {
            return false;
        }

        int valueIndex = index + prefix.Length;
        int valueLength;
        if (json.IndexOf("true", valueIndex, StringComparison.Ordinal) == valueIndex)
            valueLength = 4;
        else if (json.IndexOf("false", valueIndex, StringComparison.Ordinal) == valueIndex)
            valueLength = 5;
        else
            return false;

        int valueEnd = valueIndex + valueLength;
        if (valueEnd >= json.Length ||
            (json[valueEnd] != ',' && json[valueEnd] != '}'))
        {
            return false;
        }

        result = json.Remove(index, valueEnd - index);
        return true;
    }

    private string SerializeCurrentWithCapacity(PlayerSaveData data, int capacity)
    {
        DessertSpawner spawner = FindAnyObjectByType<DessertSpawner>();
        PlayerProgressionManager progression = PlayerProgressionManager.Instance;
        if (progression == null)
        {
            throw new InvalidOperationException(
                "PlayerProgressionManager is unavailable for Energy serialization.");
        }

        string selectedPool = spawner != null
            ? spawner.SelectedSpawnPoolId
            : sessionSelectedSpawnPoolId;
        int luckLevel = progression != null
            ? progression.LuckLevel
            : sessionLuckLevel;
        string json = SerializeWithServingPlateVersion(
            data,
            capacity,
            selectedPool,
            luckLevel,
            CurrentServingPlateProgressionVersion);
        progression.CaptureEnergySaveState(
            out int currentEnergy,
            out int millisecondsUntilNextPoint,
            out long savedUtcTicks);
        return SerializeWithEnergy(
            json,
            new EnergySaveMetadata
            {
                currentEnergy = currentEnergy,
                energyMillisecondsUntilNextPoint =
                    millisecondsUntilNextPoint,
                energySavedUtcTicks = savedUtcTicks
            });
    }

    internal bool TryPrepareDetachedSnapshot(
        PlayerSaveData proposed,
        int sessionCapacity,
        out PlayerSaveData detachedSnapshot,
        out string failureReason)
    {
        detachedSnapshot = null;
        failureReason = null;

        if (proposed == null)
        {
            failureReason = "Proposed save snapshot is null.";
            return false;
        }

        if (proposed.saveVersion != CurrentSaveVersion)
        {
            failureReason = "Proposed save snapshot is not V2.";
            return false;
        }

        if (proposed.mergeGameplay == null ||
            sessionCapacity < 0 || sessionCapacity > 4 ||
            (!proposed.mergeGameplay.hasSession && sessionCapacity != 0) ||
            (proposed.mergeGameplay.hasSession && sessionCapacity < 1))
        {
            failureReason = "Proposed session capacity is inconsistent.";
            return false;
        }

        try
        {
            string detachedJson = JsonUtility.ToJson(proposed, false);
            PlayerSaveData detached =
                JsonUtility.FromJson<PlayerSaveData>(detachedJson);

            if (detached == null)
            {
                failureReason = "Proposed save snapshot could not be cloned.";
                return false;
            }

            string serialized = SerializeCurrentWithCapacity(
                detached,
                sessionCapacity);
            if (!IsValidBackupCandidateCore(SaveEncoding.GetBytes(serialized)))
            {
                failureReason =
                    "Proposed save snapshot failed strict V2 validation.";
                return false;
            }

            detachedSnapshot = detached;
            return true;
        }
        catch (ArgumentException exception)
        {
            failureReason =
                "Proposed save snapshot could not be validated: " +
                exception.Message;
            return false;
        }
    }

    // ==================================================

    // SINGLETON

    // ==================================================

    public static SaveManager Instance

    {

        get;

        private set;

    }

    // ==================================================

    // SAVE CONFIGURATION

    // ==================================================

    private const string SaveFileName =
        "player_save_v2.json";

    private const int CurrentSaveVersion = 2;
    private const int CurrentServingPlateProgressionVersion = 1;
    private static readonly string[] OptionalV2IntroFlagFields =
    {
        "upgradesIntroSeen",
        "rebirthIntroSeen",
        "collectionIntroSeen"
    };
    private bool compatibilityMigrationPending;
    private bool loadedCollectionSectionPresent;
    private bool claimInProgress;
    private bool claimPersistenceUncertain;
    private bool upgradesIntroSeen;
    private bool rebirthIntroSeen;
    private bool collectionIntroSeen;
    private readonly DessertCollectionState dessertCollection =
        new DessertCollectionState();

    public DessertCollectionState DessertCollection =>
        dessertCollection;

    public bool HasSeenFeatureIntroduction(FeatureIntroduction feature)
    {
        switch (feature)
        {
            case FeatureIntroduction.Upgrades:
                return upgradesIntroSeen;
            case FeatureIntroduction.Rebirth:
                return rebirthIntroSeen;
            case FeatureIntroduction.Collection:
                return collectionIntroSeen;
            default:
                throw new ArgumentOutOfRangeException(nameof(feature));
        }
    }

    public bool TryAcknowledgeFeatureIntroduction(
        FeatureIntroduction feature)
    {
        if (saveInProgress || loadInProgress || claimInProgress ||
            !CanWriteCurrentState())
        {
            Debug.LogWarning(
                "FEATURE INTRO | Acknowledgement was not saved because gameplay is not ready for persistence.",
                this);
            return false;
        }

        saveInProgress = true;
        try
        {
            if (!TryLoad(out PlayerSaveData selectedSave))
            {
                Debug.LogError(
                    "FEATURE INTRO | No valid selected save is available; acknowledgement remains unseen.",
                    this);
                return false;
            }

            RestoreFeatureIntroductionAcknowledgements(selectedSave);
            if (IsFeatureIntroductionAcknowledged(selectedSave, feature))
                return true;

            string selectedJson = SaveEncoding.GetString(
                File.ReadAllBytes(SaveFilePath));
            if (!IsValidSerializedSnapshotCore(selectedJson) ||
                !TryBuildFeatureIntroductionSnapshot(
                    selectedJson,
                    feature,
                    out string candidateJson))
            {
                Debug.LogError(
                    "FEATURE INTRO | Selected save could not be safely updated; acknowledgement remains unseen.",
                    this);
                return false;
            }

            bool saved = TryWritePreparedSnapshot(
                candidateJson,
                SaveFilePath,
                out bool snapshotCommitted);
            if (!saved || !snapshotCommitted)
            {
                Debug.LogError(
                    "FEATURE INTRO | Acknowledgement commit was not confirmed; it remains unseen.",
                    this);
                return false;
            }

            SetFeatureIntroductionAcknowledged(feature);
            return true;
        }
        catch (Exception exception)
        {
            Debug.LogError(
                "FEATURE INTRO | Acknowledgement commit failed; it remains unseen.\n" +
                exception,
                this);
            return false;
        }
        finally
        {
            saveInProgress = false;
        }
    }

    private static bool IsFeatureIntroductionAcknowledged(
        PlayerSaveData saveData,
        FeatureIntroduction feature)
    {
        switch (feature)
        {
            case FeatureIntroduction.Upgrades:
                return saveData.upgradesIntroSeen;
            case FeatureIntroduction.Rebirth:
                return saveData.rebirthIntroSeen;
            case FeatureIntroduction.Collection:
                return saveData.collectionIntroSeen;
            default:
                throw new ArgumentOutOfRangeException(nameof(feature));
        }
    }

    private static bool TryBuildFeatureIntroductionSnapshot(
        string selectedJson,
        FeatureIntroduction feature,
        out string candidateJson)
    {
        candidateJson = null;
        string fieldName = GetFeatureIntroductionFieldName(feature);
        string candidate = selectedJson;

        for (int index = OptionalV2IntroFlagFields.Length - 1;
             index >= 0;
             index--)
        {
            string optionalField = OptionalV2IntroFlagFields[index];
            int propertyCount = CountJsonProperty(candidate, optionalField);
            if (propertyCount == 1)
                continue;
            if (propertyCount != 0)
                return false;

            string successor = "\"economy\":";
            for (int nextIndex = index + 1;
                 nextIndex < OptionalV2IntroFlagFields.Length;
                 nextIndex++)
            {
                string nextField = OptionalV2IntroFlagFields[nextIndex];
                if (CountJsonProperty(candidate, nextField) == 1)
                {
                    successor = "\"" + nextField + "\":";
                    break;
                }
            }

            int insertionIndex = candidate.IndexOf(
                successor,
                StringComparison.Ordinal);
            if (insertionIndex < 0)
                return false;

            candidate = candidate.Insert(
                insertionIndex,
                "\"" + optionalField + "\":false,");
        }

        string propertyPrefix = "\"" + fieldName + "\":";
        if (CountJsonProperty(candidate, fieldName) != 1)
            return false;
        int valueIndex = candidate.IndexOf(
            propertyPrefix,
            StringComparison.Ordinal) + propertyPrefix.Length;
        if (candidate.IndexOf("false", valueIndex, StringComparison.Ordinal) ==
            valueIndex)
        {
            candidate = candidate.Remove(valueIndex, 5)
                .Insert(valueIndex, "true");
        }
        else if (candidate.IndexOf("true", valueIndex, StringComparison.Ordinal) !=
                 valueIndex)
        {
            return false;
        }

        candidateJson = candidate;
        return true;
    }

    private static string GetFeatureIntroductionFieldName(
        FeatureIntroduction feature)
    {
        switch (feature)
        {
            case FeatureIntroduction.Upgrades:
                return "upgradesIntroSeen";
            case FeatureIntroduction.Rebirth:
                return "rebirthIntroSeen";
            case FeatureIntroduction.Collection:
                return "collectionIntroSeen";
            default:
                throw new ArgumentOutOfRangeException(nameof(feature));
        }
    }

    private void SetFeatureIntroductionAcknowledged(
        FeatureIntroduction feature)
    {
        switch (feature)
        {
            case FeatureIntroduction.Upgrades:
                upgradesIntroSeen = true;
                break;
            case FeatureIntroduction.Rebirth:
                rebirthIntroSeen = true;
                break;
            case FeatureIntroduction.Collection:
                collectionIntroSeen = true;
                break;
            default:
                throw new ArgumentOutOfRangeException(nameof(feature));
        }
    }

    public DessertDiscoveryRecordResult RecordDessertDiscovery(
        int tierId)
    {
        DessertDiscoveryRecordResult result =
            dessertCollection.RecordDiscovery(tierId);
        if (result ==
            DessertDiscoveryRecordResult.InvalidTier)
        {
            Debug.LogError(
                "COLLECTION | Rejected discovery for invalid dessert tier " +
                tierId +
                ". Valid initial catalog tiers are 1-30.");
        }

        return result;
    }

    public DessertCollectionClaimResult TryClaimDessertCollectionReward(
        int milestoneId)
    {
        if (milestoneId < 1 ||
            milestoneId > DessertCollectionState.MilestoneCount)
        {
            return DessertCollectionClaimResult.InvalidMilestone;
        }

        if (claimInProgress ||
            saveInProgress ||
            loadInProgress)
            return DessertCollectionClaimResult.TransactionUnavailable;
        if (claimPersistenceUncertain)
            return DessertCollectionClaimResult.CommitUncertain;

        if (dessertCollection.IsMilestoneClaimed(milestoneId))
            return DessertCollectionClaimResult.AlreadyClaimed;
        if (!dessertCollection.IsMilestoneEligible(milestoneId))
            return DessertCollectionClaimResult.NotEligible;
        if (!CanWriteCurrentState())
            return DessertCollectionClaimResult.TransactionUnavailable;

        EconomyManager economy = EconomyManager.Instance;
        if (economy == null || economy.CurrentCash < 0)
            return DessertCollectionClaimResult.TransactionUnavailable;

        int reward = dessertCollection.GetMilestoneCashAmount(
            milestoneId);
        int currentCash = economy.CurrentCash;
        int candidateCash;
        try
        {
            candidateCash = checked(currentCash + reward);
        }
        catch (OverflowException)
        {
            return DessertCollectionClaimResult.CashOverflow;
        }

        claimInProgress = true;
        saveInProgress = true;
        bool candidateSnapshotCommitted = false;
        try
        {
            if (!TryCaptureClaimCandidate(
                    milestoneId,
                    candidateCash,
                    out PlayerSaveData candidate,
                    out int sessionCapacity,
                    out string captureFailure))
            {
                Debug.LogError(
                    "COLLECTION CLAIM | Candidate capture failed. " +
                    captureFailure);
                return DessertCollectionClaimResult.SaveFailure;
            }

            if (!TryPrepareDetachedSnapshot(
                    candidate,
                    sessionCapacity,
                    out PlayerSaveData detached,
                    out string validationFailure))
            {
                Debug.LogError(
                    "COLLECTION CLAIM | Candidate snapshot failed validation. " +
                    validationFailure);
                return DessertCollectionClaimResult.SaveFailure;
            }

            string candidateJson =
                SerializeCurrentWithCapacity(
                    detached,
                    sessionCapacity);
            byte[] candidateBytes =
                SaveEncoding.GetBytes(candidateJson);
            if (!TryReadClaimPrimary(
                    out bool originalPrimaryExists,
                    out byte[] originalPrimaryBytes))
            {
                return DessertCollectionClaimResult.SaveFailure;
            }

            bool saved = false;
            bool snapshotCommitted = false;
            try
            {
                saved = TryWritePreparedSnapshot(
                    candidateJson,
                    SaveFilePath,
                    out snapshotCommitted);
            }
            catch (Exception exception)
            {
                Debug.LogError(
                    "COLLECTION CLAIM | Snapshot write threw an exception.\n" +
                    exception);
            }

            bool committed = saved && snapshotCommitted;
            if (!committed)
            {
                ClaimDiskState diskState =
                    ClassifyClaimDiskState(
                        candidateBytes,
                        originalPrimaryExists,
                        originalPrimaryBytes);
                if (diskState == ClaimDiskState.CandidateCommitted)
                {
                    committed = true;
                    Debug.LogWarning(
                        "COLLECTION CLAIM | Writer did not report success, " +
                        "but the exact candidate snapshot is present.");
                }
                else if (diskState == ClaimDiskState.Unchanged)
                {
                    return DessertCollectionClaimResult.SaveFailure;
                }
                else
                {
                    claimPersistenceUncertain = true;
                    Debug.LogError(
                        "COLLECTION CLAIM | Commit status cannot be established. " +
                        "Further saves and claims are blocked until a successful reload.");
                    return DessertCollectionClaimResult.CommitUncertain;
                }
            }

            candidateSnapshotCommitted = true;
            if (!dessertCollection.TryMarkMilestoneClaimedAfterPayment(
                    milestoneId))
            {
                claimPersistenceUncertain = true;
                Debug.LogError(
                    "COLLECTION CLAIM | Snapshot committed, but live claim state " +
                    "could not be applied. Reload is required before further saves.");
                return DessertCollectionClaimResult.CommitUncertain;
            }

            try
            {
                economy.RestoreCash(candidateCash);
            }
            catch (Exception exception)
            {
                Debug.LogError(
                    "COLLECTION CLAIM | Cash notification failed after commit.\n" +
                    exception);
            }

            if (economy.CurrentCash != candidateCash ||
                !dessertCollection.IsMilestoneClaimed(milestoneId))
            {
                claimPersistenceUncertain = true;
                Debug.LogError(
                    "COLLECTION CLAIM | Snapshot committed, but live Cash and claim " +
                    "state are inconsistent. Reload is required before further saves.");
                return DessertCollectionClaimResult.CommitUncertain;
            }

            loadedCollectionSectionPresent = true;
            compatibilityMigrationPending = false;
            try
            {
                PlayerProgressionManager.Instance?
                    .MarkCampaignCompletionSaved();
            }
            catch (Exception exception)
            {
                Debug.LogError(
                    "COLLECTION CLAIM | The claim committed, but campaign-save " +
                    "notification failed.\n" + exception);
            }

            Debug.Log(
                $"COLLECTION CLAIM | Milestone {milestoneId} committed for " +
                $"${reward}; Cash is now ${economy.CurrentCash}.");
            return DessertCollectionClaimResult.Success;
        }
        catch (Exception exception)
        {
            if (candidateSnapshotCommitted)
            {
                claimPersistenceUncertain = true;
                Debug.LogError(
                    "COLLECTION CLAIM | The candidate snapshot committed, but " +
                    "live state application did not complete. Reload is required.\n" +
                    exception);
                return DessertCollectionClaimResult.CommitUncertain;
            }

            Debug.LogError(
                "COLLECTION CLAIM | Transaction failed before completion.\n" +
                exception);
            return DessertCollectionClaimResult.SaveFailure;
        }
        finally
        {
            saveInProgress = false;
            claimInProgress = false;
        }
    }

    private bool TryCaptureClaimCandidate(
        int milestoneId,
        int candidateCash,
        out PlayerSaveData candidate,
        out int sessionCapacity,
        out string failureReason)
    {
        candidate = null;
        sessionCapacity = 0;
        failureReason = null;

        if (!CaptureLiveMergeGameplayIfAvailable())
        {
            failureReason = "Live merge gameplay capture failed.";
            return false;
        }

        candidate = CreateNewSaveData();
        if (!CaptureEconomy(candidate) ||
            !CaptureProgression(candidate) ||
            !CaptureMergeSession(candidate))
        {
            failureReason =
                "One or more current gameplay snapshots could not be captured.";
            return false;
        }

        if (candidate.economy == null ||
            candidate.dessertCollection == null ||
            candidate.dessertCollection.claimedMilestoneIds == null ||
            candidate.dessertCollection.claimedMilestoneIds.Contains(
                milestoneId))
        {
            failureReason =
                "Candidate collection data is missing or already contains the milestone.";
            return false;
        }

        candidate.economy.cash = candidateCash;
        candidate.dessertCollection.claimedMilestoneIds.Add(milestoneId);
        candidate.dessertCollection.claimedMilestoneIds.Sort();

        if (candidate.mergeGameplay == null)
        {
            failureReason = "Merge gameplay snapshot is missing.";
            return false;
        }

        if (candidate.mergeGameplay.hasSession)
        {
            MergeSessionManager session = MergeSessionManager.Instance;
            PlayerProgressionManager progression =
                PlayerProgressionManager.Instance;
            if (session == null ||
                progression == null ||
                !TryGetSessionCustomerCapacity(
                    session.SessionData,
                    progression.ActiveCustomerOrders,
                    out sessionCapacity))
            {
                failureReason =
                    "Saved customer capacity could not be verified.";
                return false;
            }
        }

        return true;
    }

    private enum ClaimDiskState
    {
        CandidateCommitted,
        Unchanged,
        Uncertain
    }

    private bool TryReadClaimPrimary(
        out bool exists,
        out byte[] bytes)
    {
        exists = false;
        bytes = null;
        try
        {
            bytes = File.ReadAllBytes(SaveFilePath);
            exists = true;
            return true;
        }
        catch (FileNotFoundException)
        {
            return true;
        }
        catch (DirectoryNotFoundException)
        {
            return true;
        }
        catch (Exception exception)
        {
            Debug.LogError(
                "COLLECTION CLAIM | Could not inspect the primary save.\n" +
                exception);
            return false;
        }
    }

    private ClaimDiskState ClassifyClaimDiskState(
        byte[] candidateBytes,
        bool originalPrimaryExists,
        byte[] originalPrimaryBytes)
    {
        if (!TryReadClaimPrimary(
                out bool currentPrimaryExists,
                out byte[] currentPrimaryBytes))
        {
            return ClaimDiskState.Uncertain;
        }

        if (currentPrimaryExists &&
            BytesEqual(currentPrimaryBytes, candidateBytes))
        {
            return ClaimDiskState.CandidateCommitted;
        }

        bool unchanged =
            originalPrimaryExists
                ? currentPrimaryExists &&
                  BytesEqual(currentPrimaryBytes, originalPrimaryBytes)
                : !currentPrimaryExists;
        return unchanged
            ? ClaimDiskState.Unchanged
            : ClaimDiskState.Uncertain;
    }

    // Main-thread APIs. The guard covers capture, serialization, IO and logging.

    private bool saveInProgress;

    private bool loadInProgress;

    private bool lifecycleCallbackInProgress;

    private bool lifecycleSavingReady;

    private bool restorationFailed;

    private static readonly UTF8Encoding SaveEncoding = new UTF8Encoding(false, true);

    internal static event Action ActiveSaveV2Committed;

    internal static void NotifyActiveSaveV2Committed()
    {
        Action handlers = ActiveSaveV2Committed;
        if (handlers == null)
            return;

        foreach (Action handler in handlers.GetInvocationList())
        {
            try
            {
                handler();
            }
            catch (Exception exception)
            {
                Debug.LogWarning(
                    "SAVE | A save-commit listener failed.\n" + exception);
            }
        }
    }

    public bool IsLifecycleSavingReady => lifecycleSavingReady;
    internal bool HasPendingCompatibilityMigration =>
        compatibilityMigrationPending;

    internal static bool ValidateCloudSnapshot(string json)
    {
        try { return json != null && IsValidBackupCandidateCore(SaveEncoding.GetBytes(json)); }
        catch (Exception) { return false; }
    }

    internal static void CommitCloudFile(string temporary, string path) => CommitTemporaryFile(temporary, path);

    private bool CanWriteCurrentState()

    {

        var startup = GameStartupCoordinator.Instance;

        return !SweetMerge.Cloud.SimpleCloudFiles.RestorePending &&
               SweetMerge.Cloud.SimpleCloudFiles.StartupError == null &&
               Instance == this && !restorationFailed &&
            !claimPersistenceUncertain && lifecycleSavingReady &&

            startup != null && startup.IsStartupComplete && startup.IsGameplayReady;

    }

    // Call before startup/reinitialization or before restoring live scene objects.

    public void SuspendLifecycleSaving()

    {

        lifecycleSavingReady = false;

    }

    // Call from the bootstrap coordinator AFTER all initialization and restoration,

    // including the live merge scene. Singleton existence alone is not readiness.

    public bool MarkGameplayReadyForLifecycleSaves()

    {

        var startup = GameStartupCoordinator.Instance;

        if (startup == null || !startup.IsStartupComplete || !startup.IsGameplayReady ||

            restorationFailed || Instance != this || saveInProgress || loadInProgress ||

            EconomyManager.Instance == null ||

            PlayerProgressionManager.Instance == null ||

            MergeSessionManager.Instance == null)

        {

            return false;

        }

        lifecycleSavingReady = true;

        return true;

    }

    private static bool TryMigrateLegacyProgression(
        PlayerSaveData saveData,
        int migrationVersion,
        int savedCustomerCapacity,
        out int migratedCustomerCapacity,
        out string reason)
    {
        migratedCustomerCapacity = savedCustomerCapacity;
        reason = null;

        if (migrationVersion == CurrentServingPlateProgressionVersion)
            return true;
        if (migrationVersion != 0)
        {
            reason = "The Serving Plate progression marker is unsupported.";
            return false;
        }
        if (saveData == null ||
            saveData.progression == null ||
            saveData.mergeGameplay == null)
        {
            reason = "Progression or merge-session data is missing.";
            return false;
        }

        ProgressionSaveData progression = saveData.progression;
        if (progression.shelfLevel < 1 ||
            progression.shelfLevel > 5 ||
            progression.customerLevel < 1 ||
            progression.customerLevel > 4)
        {
            reason = "Legacy Shelf or Customer upgrade level is out of range.";
            return false;
        }

        MergeGameplaySaveData gameplay = saveData.mergeGameplay;
        int legacyShelfCapacity = progression.shelfLevel;
        if (gameplay.shelfDesserts == null)
        {
            reason = "Legacy Serving Plate contents are missing.";
            return false;
        }

        var shelfSlots = new System.Collections.Generic.HashSet<int>();
        foreach (ShelfDessertSaveData dessert in gameplay.shelfDesserts)
        {
            if (dessert == null ||
                dessert.slotIndex < 0 ||
                dessert.slotIndex >= legacyShelfCapacity ||
                dessert.dessertTier <= 0 ||
                !shelfSlots.Add(dessert.slotIndex))
            {
                reason = "Legacy Shelf contents are invalid for the saved capacity.";
                return false;
            }
        }

        if (!gameplay.hasSession)
        {
            if (savedCustomerCapacity != 0 ||
                gameplay.customerOrders == null ||
                gameplay.customerOrders.Count != 0)
            {
                reason = "A no-session save contains customer-order session data.";
                return false;
            }
        }
        else
        {
            if (savedCustomerCapacity < 1 ||
                savedCustomerCapacity > 4 ||
                gameplay.customerOrders == null ||
                gameplay.customerOrders.Count != savedCustomerCapacity ||
                gameplay.nextOrderId <= 0)
            {
                reason = "Legacy customer capacity or order count is invalid.";
                return false;
            }

            var customerIndices =
                new System.Collections.Generic.HashSet<int>();
            var orderIds =
                new System.Collections.Generic.HashSet<int>();
            foreach (CustomerOrderSaveData order in gameplay.customerOrders)
            {
                if (order == null ||
                    order.customerIndex < 0 ||
                    order.customerIndex >= savedCustomerCapacity ||
                    !customerIndices.Add(order.customerIndex) ||
                    order.orderId <= 0 ||
                    order.orderId >= gameplay.nextOrderId ||
                    !orderIds.Add(order.orderId) ||
                    string.IsNullOrWhiteSpace(order.definitionId))
                {
                    reason = "Legacy customer-order rows are invalid or duplicated.";
                    return false;
                }
            }

        }

        switch (progression.shelfLevel)
        {
            case 1:
            case 2:
                progression.shelfLevel = 1;
                break;
            case 3:
                progression.shelfLevel = 2;
                break;
            case 4:
                progression.shelfLevel = 3;
                break;
            case 5:
                progression.shelfLevel = 4;
                break;
        }
        progression.customerLevel =
            Mathf.Min(progression.customerLevel, 3);

        return true;
    }

    private bool CanSaveFromLifecycle()

    {

        return CanWriteCurrentState() &&

            !saveInProgress && !loadInProgress && !lifecycleCallbackInProgress &&

            EconomyManager.Instance != null &&

            PlayerProgressionManager.Instance != null &&

            MergeSessionManager.Instance != null;

    }

    private void OnDestroy()

    {

        lifecycleSavingReady = false;

        if (Instance == this)

            Instance = null;

    }

    // ==================================================

    // PUBLIC PROPERTIES

    // ==================================================

    public string SaveDirectory =>
        SavePathPolicy.GetSaveDirectory();

    public string SaveFilePath =>

        Path.Combine(

            SaveDirectory,

            SaveFileName
        );

    public string LegacyV1SaveFilePath =>
        Path.Combine(
            SaveDirectory,
            "player_save.json"
        );

    public bool TryResetDevelopmentProfileFiles(out string message)
    {
        message = null;
        if (!SavePathPolicy.IsDevelopmentSaveIsolationEnabled ||
            saveInProgress || loadInProgress ||
            lifecycleCallbackInProgress || !CanWriteCurrentState() ||
            UnityEngine.SceneManagement.SceneManager.GetActiveScene().name != "Game")
        {
            message =
                "Development profile reset is unavailable outside a ready, isolated Game session.";
            return false;
        }

        EconomyManager economyManager = EconomyManager.Instance;
        if (economyManager == null)
        {
            message = "EconomyManager is unavailable; development statistics were not reset.";
            return false;
        }

        string expectedDirectory;
        string activeDirectory;
        try
        {
            expectedDirectory =
                Path.GetFullPath(SavePathPolicy.GetSaveDirectory());
            activeDirectory = Path.GetFullPath(SaveDirectory);
        }
        catch (Exception exception)
        {
            message = "Development save directory could not be verified.";
            Debug.LogError("SAVE RESET | " + message + "\n" + exception);
            return false;
        }

        if (!string.Equals(
                expectedDirectory,
                activeDirectory,
                StringComparison.OrdinalIgnoreCase))
        {
            message =
                "Active save directory is not the development-isolated profile.";
            return false;
        }

        var profileFiles = new List<string>
        {
            SaveFilePath,
            SweetMerge.Cloud.LocalSaveOwnership.MarkerPath(SaveFilePath),
            SaveFilePath + ".bak",
            SaveFilePath + ".tmp",
            SaveFilePath + ".bak.tmp",
            SaveFilePath + ".recover.tmp",
            LegacyV1SaveFilePath,
            LegacyV1SaveFilePath + ".bak",
            LegacyV1SaveFilePath + ".tmp"
        };

        string resetToken = Guid.NewGuid().ToString("N");
        var quarantined = new List<KeyValuePair<string, string>>();
        if (!SweetMerge.Cloud.LocalSaveOwnership.TryInvalidate(
                SaveFilePath,
                out string ownershipError))
        {
            message = ownershipError;
            return false;
        }

        SweetMerge.Cloud.PlayerStatisticsCloudSync.InvalidateAuthorization(
            "Statistics sync invalidated by a development profile reset.");
        try
        {
            if (Directory.Exists(activeDirectory))
            {
                profileFiles.AddRange(Directory.GetFiles(
                    activeDirectory,
                    Path.GetFileName(SaveFilePath) +
                        ".owner-v1.json.*.tmp",
                    SearchOption.TopDirectoryOnly));
                profileFiles.AddRange(Directory.GetFiles(
                    activeDirectory,
                    Path.GetFileName(SaveFilePath) + ".corrupt.*",
                    SearchOption.TopDirectoryOnly));
                profileFiles.AddRange(Directory.GetFiles(
                    activeDirectory,
                    Path.GetFileName(SaveFilePath) + ".bak.corrupt.*",
                    SearchOption.TopDirectoryOnly));
            }

            foreach (string source in profileFiles)
            {
                if (!File.Exists(source))
                    continue;

                string quarantine = source + ".reset-" + resetToken;
                File.Move(source, quarantine);
                quarantined.Add(
                    new KeyValuePair<string, string>(source, quarantine));
            }
        }
        catch (Exception exception)
        {
            bool rollbackSucceeded = true;
            for (int i = quarantined.Count - 1; i >= 0; i--)
            {
                try
                {
                    File.Move(
                        quarantined[i].Value,
                        quarantined[i].Key);
                }
                catch (Exception rollbackException)
                {
                    rollbackSucceeded = false;
                    Debug.LogError(
                        "SAVE RESET | Could not restore quarantined development profile file '" +
                        quarantined[i].Key + "'.\n" + rollbackException);
                }
            }

            message = rollbackSucceeded
                ? "Development profile files could not be reset; the original files were restored."
                : "Development profile reset failed and file rollback was incomplete. Check the development save directory.";
            Debug.LogError("SAVE RESET | " + message + "\n" + exception);
            return false;
        }

        bool cleanupSucceeded = true;
        foreach (KeyValuePair<string, string> entry in quarantined)
        {
            try
            {
                File.Delete(entry.Value);
            }
            catch (Exception exception)
            {
                cleanupSucceeded = false;
                Debug.LogWarning(
                    "SAVE RESET | Old development data remains quarantined under '" +
                    entry.Value + "' and cannot participate in recovery.\n" +
                    exception);
            }
        }

        capacityLoadedData = null;
        loadedCustomerCapacity = 0;
        capacitySession = null;
        capacityFingerprint = null;
        sessionCustomerCapacity = 0;
        loadedSelectedSpawnPoolId = null;
        sessionSelectedSpawnPoolId = null;
        loadedLuckLevel = 1;
        sessionLuckLevel = 1;
        loadedServingPlateProgressionVersion = 0;
        loadedEnergyMetadata = null;
        compatibilityMigrationPending = false;
        loadedCollectionSectionPresent = false;
        claimPersistenceUncertain = false;
        upgradesIntroSeen = false;
        rebirthIntroSeen = false;
        collectionIntroSeen = false;
        dessertCollection.Clear();
        economyManager.RestoreLifetimeStatistics(0, 0);

        message = cleanupSucceeded
            ? "Development profile and recognized recovery files were removed."
            : "Development profile reset; old files remain quarantined and cannot be restored automatically.";
        return true;
    }

    // ==================================================

    // UNITY

    // ==================================================

    private void Awake()

    {

        if (Instance != null &&

            Instance != this)

        {

            Destroy(gameObject);

            return;

        }

        Instance = this;

        DontDestroyOnLoad(

            gameObject

        );

        Debug.Log(
            "SAVE PATH POLICY | " +
            SavePathPolicy.ModeName +
            " | persistentDataPath: " +
            Application.persistentDataPath +
            " | save directory: " +
            SaveDirectory);

    }

    // ==================================================

    // ANDROID / MOBILE APPLICATION PAUSE

    // ==================================================

    private void OnApplicationPause(bool isPaused)

    {

        if (!CanSaveFromLifecycle())

            return;

        lifecycleCallbackInProgress = true;

        try { HandleApplicationPause(isPaused); }

        finally { lifecycleCallbackInProgress = false; }

    }

    private void HandleApplicationPause(bool isPaused)

    {

        // ----------------------------------------------

        // IGNORE RESUME

        // ----------------------------------------------

        if (!isPaused)

        {

            Debug.Log(

                "LIFECYCLE | Application resumed."

            );

            return;

        }

        // ----------------------------------------------

        // IGNORE DUPLICATE MANAGER

        // ----------------------------------------------

        if (Instance != this)

        {

            return;

        }

        // ----------------------------------------------

        // SAVE ON BACKGROUND

        // ----------------------------------------------

        bool saveSucceeded =

            SaveCurrentGame();

        if (!saveSucceeded)

        {

            Debug.LogError(

                "LIFECYCLE | Application pause save failed."

            );

            return;

        }

        Debug.Log(

            "LIFECYCLE | Application pause save completed."

        );

    }

    // ==================================================

    // APPLICATION QUIT SAVE FALLBACK

    // ==================================================

    private void OnApplicationQuit()

    {

        if (!CanSaveFromLifecycle())

            return;

        lifecycleCallbackInProgress = true;

        try { HandleApplicationQuit(); }

        finally { lifecycleCallbackInProgress = false; }

    }

    private void HandleApplicationQuit()

    {

        // ----------------------------------------------

        // IGNORE DUPLICATE SAVE MANAGER

        // ----------------------------------------------

        if (Instance != this)

        {

            return;

        }

        // ----------------------------------------------

        // ATTEMPT FINAL SAVE

        // ----------------------------------------------

        bool saveSucceeded =

            SaveCurrentGame();

        if (!saveSucceeded)

        {

            Debug.LogError(

                "LIFECYCLE | Application quit save failed."

            );

            return;

        }

        Debug.Log(

            "LIFECYCLE | Application quit save completed."

        );

    }

    // ==================================================

    // SAVE FILE QUERIES

    // ==================================================

    public bool SaveFileExists()

    {
        if (SweetMerge.Cloud.SimpleCloudFiles.RestorePending)
        {
            Debug.LogWarning(
                "SAVE | Save-file checks are blocked until the pending cloud restore is resolved.",
                this);
            return false;
        }

        string primaryPath = SaveFilePath;
        return File.Exists(primaryPath) ||
               File.Exists(primaryPath + ".bak");

    }

    // ==================================================

    // NEW SAVE DATA

    // ==================================================

    public PlayerSaveData CreateNewSaveData()

    {

        PlayerSaveData saveData =

            new PlayerSaveData();

        saveData.saveVersion =

            CurrentSaveVersion;

        saveData.economy.totalOrdersCompleted = 0;

        saveData.economy.totalMoneyEarned = 0;

        saveData.upgradesIntroSeen = upgradesIntroSeen;
        saveData.rebirthIntroSeen = rebirthIntroSeen;
        saveData.collectionIntroSeen = collectionIntroSeen;

        dessertCollection.CaptureTo(
            saveData.dessertCollection);

        return saveData;

    }

    // ==================================================

    // CAPTURE - ECONOMY

    // ==================================================

    private bool CaptureEconomy(

        PlayerSaveData saveData)

    {

        if (saveData == null)

        {

            Debug.LogError(

                "SAVE | Cannot capture economy into " +

                "null PlayerSaveData."

            );

            return false;

        }

        EconomyManager economyManager =

            EconomyManager.Instance;

        if (economyManager == null)

        {

            Debug.LogError(

                "SAVE | EconomyManager is unavailable."

            );

            return false;

        }

        if (saveData.economy == null)

        {

            saveData.economy =

                new EconomySaveData();

        }

        saveData.economy.cash =
            economyManager.CurrentCash;

        saveData.economy.totalOrdersCompleted =
            economyManager.TotalOrdersCompleted;

        saveData.economy.totalMoneyEarned =
            economyManager.TotalMoneyEarned;

        Debug.Log(

            $"SAVE CAPTURE | Economy | " +

            $"Cash: ${saveData.economy.cash}"

        );

        return true;

    }

    // ==================================================

    // CAPTURE - PROGRESSION

    // ==================================================

    private bool CaptureProgression(

        PlayerSaveData saveData)

    {

        if (saveData == null)

        {

            Debug.LogError(

                "SAVE | Cannot capture progression into " +

                "null PlayerSaveData."

            );

            return false;

        }

        PlayerProgressionManager progressionManager =

            PlayerProgressionManager.Instance;

        if (progressionManager == null)

        {

            Debug.LogError(

                "SAVE | PlayerProgressionManager " +

                "is unavailable."

            );

            return false;

        }

        if (saveData.progression == null)

        {

            saveData.progression =

                new ProgressionSaveData();

        }

        saveData.progression.ovenLevel =

            progressionManager.OvenLevel;

        saveData.progression.boardSpaceLevel =

            progressionManager.BoardSpaceLevel;

        saveData.progression.shelfLevel =

            progressionManager.ShelfLevel;

        saveData.progression.customerLevel =

            progressionManager.CustomerLevel;

        saveData.progression.moneyMultiplierLevel =

            progressionManager.MoneyMultiplierLevel;

        saveData.completedRebirthCount =
            progressionManager.CurrentRebirthCount;

        saveData.highestTierCreatedThisRun =
            progressionManager.HighestTierCreatedThisRun;

        saveData.campaignComplete =
            progressionManager.CampaignComplete;

        Debug.Log(

            "SAVE CAPTURE | Progression | " +

            $"Oven L{saveData.progression.ovenLevel} | " +

            $"Board L{saveData.progression.boardSpaceLevel} | " +

            $"Shelf L{saveData.progression.shelfLevel} | " +

            $"Customer L{saveData.progression.customerLevel} | " +

            $"Money L" +

            $"{saveData.progression.moneyMultiplierLevel} | " +

            $"Luck L{progressionManager.LuckLevel}"

        );

        return true;

    }

    // ==================================================

    // CAPTURE - LIVE MERGE GAMEPLAY

    // ==================================================

    private bool CaptureLiveMergeGameplayIfAvailable()

    {

        MergeSessionController mergeSessionController =

            FindAnyObjectByType<MergeSessionController>();

        /*

         * No MergeSessionController is expected while

         * the player is in MainBakery.

         *

         * In that case we preserve the existing

         * MergeSessionManager snapshot instead of

         * clearing it.

         */

        if (mergeSessionController == null)

        {

            Debug.Log(

                "SAVE CAPTURE | " +

                "No live MergeSessionController found. " +

                "Using existing merge session snapshot."

            );

            return true;

        }

        Debug.Log(

            "SAVE CAPTURE | " +

            "Live merge gameplay detected. " +

            "Capturing current gameplay state."

        );

        if (!mergeSessionController.TryCaptureSession())

        {

            Debug.LogError(

                "SAVE CAPTURE | " +

                "Live merge gameplay capture failed."

            );

            return false;

        }

        Debug.Log(

            "SAVE CAPTURE | " +

            "Live merge gameplay captured successfully."

        );

        return true;

    }

    // ==================================================

    // CAPTURE - MERGE SESSION

    // ==================================================

    private bool CaptureMergeSession(

        PlayerSaveData saveData)

    {

        if (saveData == null)

        {

            Debug.LogError(

                "SAVE | Cannot capture merge session into " +

                "null PlayerSaveData."

            );

            return false;

        }

        MergeSessionManager mergeSessionManager =

            MergeSessionManager.Instance;

        if (mergeSessionManager == null)

        {

            Debug.LogError(

                "SAVE | MergeSessionManager is unavailable."

            );

            return false;

        }

        if (saveData.mergeGameplay == null)

        {

            saveData.mergeGameplay =

                new MergeGameplaySaveData();

        }

        if (!mergeSessionManager.CaptureToSaveData(

                saveData.mergeGameplay))

        {

            Debug.LogError(

                "SAVE | Merge session capture failed."

            );

            return false;

        }

        Debug.Log(

            "SAVE CAPTURE | Merge Session | " +

            $"Has Session: " +

            $"{saveData.mergeGameplay.hasSession} | " +

            $"Board: " +

            $"{saveData.mergeGameplay.boardDesserts.Count} | " +

            $"Shelf: " +

            $"{saveData.mergeGameplay.shelfDesserts.Count} | " +

            $"Orders: " +

            $"{saveData.mergeGameplay.customerOrders.Count} | " +

            $"Next Order ID: " +

            $"#{saveData.mergeGameplay.nextOrderId} | " +

            $"Next Dessert: " +

            $"T{saveData.mergeGameplay.nextDessertTier}"

        );

        return true;

    }

    // ==================================================

    // RESTORE - ECONOMY

    // ==================================================

    private bool RestoreEconomy(

        PlayerSaveData saveData)

    {

        if (saveData == null)

        {

            Debug.LogError(

                "LOAD | Cannot restore economy from " +

                "null PlayerSaveData."

            );

            return false;

        }

        if (saveData.economy == null)

        {

            Debug.LogError(

                "LOAD | Economy save data is missing."

            );

            return false;

        }

        EconomyManager economyManager =

            EconomyManager.Instance;

        if (economyManager == null)

        {

            Debug.LogError(

                "LOAD | EconomyManager is unavailable."

            );

            return false;

        }

        economyManager.RestoreCash(
            saveData.economy.cash
        );

        if (economyManager.CurrentCash != saveData.economy.cash) return false;

        economyManager.RestoreLifetimeStatistics(
            saveData.economy.totalOrdersCompleted,
            saveData.economy.totalMoneyEarned
        );

        Debug.Log(

            $"LOAD RESTORE | Economy | " +

            $"Cash: ${economyManager.CurrentCash}"

        );

        return true;

    }

    // ==================================================

    // RESTORE - PROGRESSION

    // ==================================================

    private bool RestoreProgression(

        PlayerSaveData saveData)

    {

        if (saveData == null)

        {

            Debug.LogError(

                "LOAD | Cannot restore progression from " +

                "null PlayerSaveData."

            );

            return false;

        }

        if (saveData.progression == null)

        {

            Debug.LogError(

                "LOAD | Progression save data is missing."

            );

            return false;

        }

        PlayerProgressionManager progressionManager =

            PlayerProgressionManager.Instance;

        if (progressionManager == null)

        {

            Debug.LogError(

                "LOAD | PlayerProgressionManager " +

                "is unavailable."

            );

            return false;

        }

        if (!progressionManager.ValidateRestorationDefinitions(out string reason))

        {

            Debug.LogError("LOAD | " + reason);

            return false;

        }

        if (!progressionManager.RestoreRebirthProgression(
                saveData.completedRebirthCount,
                saveData.highestTierCreatedThisRun,
                saveData.campaignComplete))
        {
            Debug.LogError("LOAD | Rebirth progression data is invalid.");
            return false;
        }

        progressionManager.RestoreProgression(

            saveData.progression.ovenLevel,

            saveData.progression.boardSpaceLevel,

            saveData.progression.shelfLevel,

            saveData.progression.customerLevel,

            saveData.progression.moneyMultiplierLevel,

            loadedLuckLevel

        );

        UpgradeType[] types = { UpgradeType.Oven, UpgradeType.BoardSpace, UpgradeType.Shelf,

            UpgradeType.Customer, UpgradeType.MoneyMultiplier, UpgradeType.Luck };

        int[] expectedLevels = { saveData.progression.ovenLevel,

            saveData.progression.boardSpaceLevel, saveData.progression.shelfLevel,

            saveData.progression.customerLevel, saveData.progression.moneyMultiplierLevel,

            loadedLuckLevel };

        for (int i = 0; i < types.Length; i++)

            if (progressionManager.GetLevel(types[i]) != Mathf.Clamp(expectedLevels[i], 1,

                    progressionManager.GetMaxLevel(types[i]))) return false;

        if (loadedEnergyMetadata == null ||
            !progressionManager.RestoreEnergy(
                loadedEnergyMetadata.currentEnergy,
                loadedEnergyMetadata.energyMillisecondsUntilNextPoint,
                loadedEnergyMetadata.energySavedUtcTicks))
        {
            Debug.LogError("LOAD | Energy state could not be restored.");
            return false;
        }

        Debug.Log(

            "LOAD RESTORE | Progression | " +

            $"Oven L{progressionManager.OvenLevel} | " +

            $"Board L{progressionManager.BoardSpaceLevel} | " +

            $"Shelf L{progressionManager.ShelfLevel} | " +

            $"Customer L{progressionManager.CustomerLevel} | " +

            $"Money L{progressionManager.MoneyMultiplierLevel}"

        );

        return true;

    }

    // ==================================================

    // RESTORE - MERGE SESSION

    // ==================================================

    private bool RestoreMergeSession(

        PlayerSaveData saveData)

    {

        if (saveData == null)

        {

            Debug.LogError(

                "LOAD | Cannot restore merge session from " +

                "null PlayerSaveData."

            );

            return false;

        }

        if (saveData.mergeGameplay == null)

        {

            Debug.LogError(

                "LOAD | Merge gameplay save data is missing."

            );

            return false;

        }

        MergeSessionManager mergeSessionManager =

            MergeSessionManager.Instance;

        if (mergeSessionManager == null)

        {

            Debug.LogError(

                "LOAD | MergeSessionManager is unavailable."

            );

            return false;

        }

        string expected = RestorationVerification.Fingerprint(saveData.mergeGameplay);

        if (!mergeSessionManager.RestoreFromSaveData(

                saveData.mergeGameplay))

        {

            Debug.LogError(

                "LOAD | Merge session restore failed."

            );

            return false;

        }

        var actual = new MergeGameplaySaveData();

        if (!mergeSessionManager.CaptureToSaveData(actual) ||

            !string.Equals(expected, RestorationVerification.Fingerprint(actual), StringComparison.Ordinal))

        {

            Debug.LogError("LOAD | Persistent merge session differs from the saved data.");

            return false;

        }

        RecordSessionCustomerCapacity(mergeSessionManager.SessionData,

            ReferenceEquals(saveData, capacityLoadedData) ? loadedCustomerCapacity : 0);

        Debug.Log(

            "LOAD RESTORE | Merge Session | " +

            $"Has Session: " +

            $"{mergeSessionManager.HasSession}"

        );

        return true;

    }

    // ==================================================

    // SAVE CURRENT GAME

    // ==================================================

    public bool SaveCurrentGame()

    {

        // Silent rejection prevents recursive log handlers from recursing again.

        // Rejected callers receive false and must retry; no request is reported saved.

        if (!CanWriteCurrentState() || saveInProgress || loadInProgress)

            return false;

        saveInProgress = true;

        bool saveSucceeded = false;
        try

        {

            saveSucceeded = SaveCurrentGameCore();

        }

        catch (Exception exception)

        {

            Debug.LogError($"SAVE | Current game save failed.\n{exception}");

            return false;

        }

        finally

        {

            saveInProgress = false;

        }

        if (saveSucceeded)
        {
            compatibilityMigrationPending = false;
            PlayerProgressionManager.Instance?
                .MarkCampaignCompletionSaved();
        }

        return saveSucceeded;

    }

    private bool SaveCurrentGameCore()

    {

        // ----------------------------------------------

        // LIVE MERGE GAMEPLAY

        // ----------------------------------------------

        /*

         * If live merge gameplay currently exists,

         * capture it before building PlayerSaveData.

         *

         * If we're in MainBakery, the existing

         * MergeSessionManager snapshot is preserved.

         */

        if (!CaptureLiveMergeGameplayIfAvailable())

        {

            Debug.LogError(

                "SAVE | Current game save aborted " +

                "because live merge gameplay capture failed."

            );

            return false;

        }

        // ----------------------------------------------

        // CREATE SAVE DATA

        // ----------------------------------------------

        PlayerSaveData saveData =

            CreateNewSaveData();

        // ----------------------------------------------

        // ECONOMY

        // ----------------------------------------------

        if (!CaptureEconomy(

                saveData))

        {

            Debug.LogError(

                "SAVE | Current game save aborted " +

                "because economy capture failed."

            );

            return false;

        }

        // ----------------------------------------------

        // PROGRESSION

        // ----------------------------------------------

        if (!CaptureProgression(

                saveData))

        {

            Debug.LogError(

                "SAVE | Current game save aborted " +

                "because progression capture failed."

            );

            return false;

        }

        // ----------------------------------------------

        // MERGE SESSION

        // ----------------------------------------------

        if (!CaptureMergeSession(

                saveData))

        {

            Debug.LogError(

                "SAVE | Current game save aborted " +

                "because merge session capture failed."

            );

            return false;

        }

        // ----------------------------------------------

        // WRITE FILE

        // ----------------------------------------------

        if (!SaveCore(saveData))

        {

            Debug.LogError(

                "SAVE | Current game save failed " +

                "while writing the save file."

            );

            return false;

        }

        Debug.Log(

            "SAVE | Current game saved successfully."

        );

        return true;

    }

    internal bool TryCommitRebirthSnapshot(
        int nextRebirthCount,
        out bool snapshotCommitted)
    {
        return TryCommitRebirthSnapshot(
            nextRebirthCount,
            SaveFilePath,
            out snapshotCommitted);
    }

    internal bool TryCommitRebirthSnapshot(
        int nextRebirthCount,
        string snapshotPath,
        out bool snapshotCommitted)
    {
        snapshotCommitted = false;
        if (!CanWriteCurrentState() || saveInProgress || loadInProgress)
            return false;

        saveInProgress = true;
        try
        {
            var progression = PlayerProgressionManager.Instance;
            var economy = EconomyManager.Instance;
            if (progression == null || economy == null ||
                nextRebirthCount != progression.CurrentRebirthCount + 1 ||
                !progression.IsEligibleForNextRebirth)
            {
                Debug.LogError("REBIRTH SAVE | Current progression is no longer eligible.");
                return false;
            }

            MergeSessionController controller =
                FindAnyObjectByType<MergeSessionController>();
            if (controller == null ||
                !controller.IsPreparedFreshSessionForCommit)
            {
                Debug.LogError(
                    "REBIRTH SAVE | No verified fresh session is staged for commit.");
                return false;
            }

            var proposed = CreateNewSaveData();
            if (!CaptureEconomy(proposed) ||
                !CaptureProgression(proposed) ||
                !CaptureMergeSession(proposed))
            {
                Debug.LogError("REBIRTH SAVE | Current state capture failed.");
                return false;
            }

            proposed.economy.cash = 0;
            proposed.completedRebirthCount = nextRebirthCount;
            proposed.highestTierCreatedThisRun = 0;
            proposed.progression.ovenLevel =
                PlayerProgressionManager.GetOvenLevelForRebirthCount(nextRebirthCount);

            int capacity = 0;
            if (proposed.mergeGameplay.hasSession &&
                !TryGetSessionCustomerCapacity(
                    MergeSessionManager.Instance.SessionData,
                    progression.ActiveCustomerOrders,
                    out capacity))
            {
                Debug.LogError("REBIRTH SAVE | Fresh session capacity provenance is missing.");
                return false;
            }

            if (!TryPrepareDetachedSnapshot(
                    proposed,
                    capacity,
                    out PlayerSaveData detached,
                    out string failureReason))
            {
                Debug.LogError(
                    "REBIRTH SAVE | Proposed V2 snapshot was rejected. " +
                    failureReason);
                return false;
            }

            bool saved = TryWritePreparedSnapshot(
                detached,
                capacity,
                snapshotPath,
                out snapshotCommitted);
            if (!saved && snapshotCommitted)
            {
                Debug.LogError(
                    "REBIRTH SAVE | Atomic promotion completed, but post-write verification failed.");
                return true;
            }

            return saved;
        }
        catch (Exception exception)
        {
            Debug.LogError("REBIRTH SAVE | Snapshot commit failed.\n" + exception);
            return snapshotCommitted;
        }
        finally
        {
            saveInProgress = false;
        }
    }

    // ==================================================

    // LOAD CURRENT GAME

    // ==================================================

    public bool LoadCurrentGame()

    {
        if (SweetMerge.Cloud.SimpleCloudFiles.RestorePending)
        {
            Debug.LogWarning(
                "LOAD | Save V2 loading is blocked until the pending cloud restore is resolved.",
                this);
            return false;
        }

        if (saveInProgress || loadInProgress)

            return false;

        // A failed/partial restore must never enable automatic saving.

        // The coordinator must explicitly mark ready again after scene restoration.

        SuspendLifecycleSaving();

        GameStartupCoordinator.Instance?.BeginPersistentReload();

        restorationFailed = true;

        loadInProgress = true;

        try

        {

            bool success = LoadCurrentGameCore();

            restorationFailed = !success;

                if (success)
                {
                    claimPersistenceUncertain = false;
                    GameStartupCoordinator.Instance?.CompletePersistentReload();
                }

            else GameStartupCoordinator.Instance?.ReportGameplayRestorationFailure("Persistent restoration failed.");

            return success;

        }

        catch (Exception exception)

        {

            GameStartupCoordinator.Instance?.ReportGameplayRestorationFailure("Persistent restoration threw an exception.");

            Debug.LogError($"LOAD | Current game restore failed.\n{exception}");

            return false;

        }

        finally

        {

            loadInProgress = false;

        }

    }

    private bool LoadCurrentGameCore()

    {

        if (!TryLoad(
                out PlayerSaveData saveData))

        {

            Debug.LogWarning(

                "LOAD | Current game load aborted " +

                "because no valid save could be loaded."

            );

            return false;
        }

        if (!TryMigrateLegacyProgression(
                saveData,
                loadedServingPlateProgressionVersion,
                loadedCustomerCapacity,
                out int migratedCustomerCapacity,
                out string migrationFailure))
        {
            Debug.LogError(
                "LOAD MIGRATION | Compatibility migration failed. " +
                "The original save was not modified. " + migrationFailure);
            return false;
        }
        bool needsCollectionBackfill =
            !loadedCollectionSectionPresent;
        if (needsCollectionBackfill)
        {
            if (!DessertCollectionState.TryCreateLegacyBackfill(
                    saveData.mergeGameplay,
                    out DessertCollectionSaveData migratedCollection,
                    out string collectionMigrationFailure))
            {
                Debug.LogError(
                    "LOAD MIGRATION | Collection backfill failed. " +
                    "The original save was not modified. " +
                    collectionMigrationFailure);
                return false;
            }

            saveData.dessertCollection =
                migratedCollection;
        }
        if (loadedServingPlateProgressionVersion == 0)
        {
            loadedServingPlateProgressionVersion =
                CurrentServingPlateProgressionVersion;
            loadedCustomerCapacity =
                migratedCustomerCapacity;
            compatibilityMigrationPending = true;
        }

        // ----------------------------------------------

        // ECONOMY

        // ----------------------------------------------

        if (!RestoreEconomy(

                saveData))

        {

            Debug.LogError(

                "LOAD | Current game load aborted " +

                "because economy restore failed."

            );

            return false;

        }

        // ----------------------------------------------

        // PROGRESSION

        // ----------------------------------------------

        if (!RestoreProgression(

                saveData))

        {

            Debug.LogError(

                "LOAD | Current game load aborted " +

                "because progression restore failed."

            );

            return false;

        }

        // ----------------------------------------------

        // MERGE SESSION

        // ----------------------------------------------

        if (!RestoreMergeSession(

                saveData))

        {

            Debug.LogError(

                "LOAD | Current game load aborted " +

                "because merge session restore failed."

            );

            return false;

        }

        if (!dessertCollection.TryRestore(
                saveData.dessertCollection,
                out string collectionRestoreFailure))
        {
            Debug.LogError(
                "LOAD | Dessert collection restore failed. " +
                collectionRestoreFailure);
            return false;
        }
        if (needsCollectionBackfill)
            compatibilityMigrationPending = true;

        RestoreFeatureIntroductionAcknowledgements(saveData);

        Debug.Log(

            "LOAD | Current game restored successfully."

        );

        return true;

    }

    private void RestoreFeatureIntroductionAcknowledgements(
        PlayerSaveData saveData)
    {
        upgradesIntroSeen = saveData.upgradesIntroSeen;
        rebirthIntroSeen = saveData.rebirthIntroSeen;
        collectionIntroSeen = saveData.collectionIntroSeen;
    }

    // ==================================================

    // SAVE

    // ==================================================

    public bool Save(PlayerSaveData saveData)

    {

        // Explicit and debug writes obey the same restoration gate as lifecycle writes.

        if (!CanWriteCurrentState() || saveInProgress || loadInProgress)

            return false;

        SweetMerge.Cloud.PlayerStatisticsCloudSync.InvalidateAuthorization(
            "Statistics sync invalidated by an explicit Save V2 replacement.");
        if (!SweetMerge.Cloud.LocalSaveOwnership.TryInvalidate(
                SaveFilePath,
                out string ownershipError))
        {
            Debug.LogError(
                "SAVE | Explicit replacement was blocked because ownership " +
                "could not be invalidated: " + ownershipError,
                this);
            return false;
        }

        saveInProgress = true;

        try

        {

            return SaveCore(saveData);

        }

        catch (Exception exception)

        {

            Debug.LogError($"SAVE | Failed to write save file.\n{exception}");

            return false;

        }

        finally

        {

            saveInProgress = false;

        }

    }

    // Only called while the outer public operation owns the save guard.

    private bool SaveCore(PlayerSaveData saveData)

    {

        if (saveData == null)

        {

            Debug.LogError("SAVE | Cannot save null PlayerSaveData.");

            return false;

        }

        // Preserve the original normalization and caller-data mutation behavior.

        SanitizeSaveDataCore(saveData);

        saveData.saveVersion = CurrentSaveVersion;

        // One canonical serializer configuration for comparison AND writing.

        // Preserve list order and string whitespace; do not sort gameplay lists.

        int capacity = 0;

        if (saveData.mergeGameplay.hasSession)

        {

            var session = MergeSessionManager.Instance;

            var progression = PlayerProgressionManager.Instance;

            if (session == null || progression == null ||

                !TryGetSessionCustomerCapacity(session.SessionData, progression.ActiveCustomerOrders, out capacity))

            {

                Debug.LogError("SAVE | Customer capacity provenance is missing.");

                return false;

            }

            var snapshot = new MergeGameplaySaveData();

            if (!session.CaptureToSaveData(snapshot) || !string.Equals(

                RestorationVerification.Fingerprint(snapshot),

                RestorationVerification.Fingerprint(saveData.mergeGameplay), StringComparison.Ordinal))

                return false;

        }

        return TryWritePreparedSnapshot(saveData, capacity, out _);
    }

    private bool TryWritePreparedSnapshot(
        PlayerSaveData saveData,
        int capacity,
        out bool snapshotCommitted)
    {
        return TryWritePreparedSnapshot(
            saveData,
            capacity,
            SaveFilePath,
            out snapshotCommitted);
    }

    private bool TryWritePreparedSnapshot(
        PlayerSaveData saveData,
        int capacity,
        string path,
        out bool snapshotCommitted)
    {
        string json = SerializeCurrentWithCapacity(saveData, capacity);
        return TryWritePreparedSnapshot(
            json,
            path,
            out snapshotCommitted);
    }

    private bool TryWritePreparedSnapshot(
        string json,
        string path,
        out bool snapshotCommitted)
    {
        snapshotCommitted = false;
        bool isActiveSavePath = IsActiveSavePath(path);
        string previousOwner = isActiveSavePath
            ? GetCurrentVerifiedSaveOwner()
            : null;
        string environment = isActiveSavePath
            ? SavePathPolicy.ModeName
            : null;
        bool preserveOwnership = isActiveSavePath &&
            SweetMerge.Cloud.LocalSaveOwnership.IsOwnedBy(
                path,
                previousOwner,
                environment);

        if (!IsValidSerializedSnapshotCore(json))
        {
            Debug.LogError("SAVE | Serialized snapshot failed validation.");
            return false;
        }
        byte[] expectedBytes = SaveEncoding.GetBytes(json);
        if (File.Exists(path))
        {
            byte[] onDiskBytes = File.ReadAllBytes(path);
            int diskVersion;
            MigrationDecision diskDecision = EvaluateMigration(onDiskBytes, out diskVersion);
            if (IsMigrationBlocked(diskDecision))
            {
                Debug.LogError("SAVE VERSION | Refusing to overwrite unsupported or ambiguous " +
                    "on-disk save version (" + diskVersion + ").");
                return false;
            }

            if (!IsValidBackupCandidateCore(onDiskBytes))
            {
                Debug.LogError(
                    "SAVE | Refusing to overwrite an invalid V2 primary; " +
                    "load/recovery or manual diagnosis is required.");
                return false;
            }
        }

        if (DiskMatchesSnapshot(path, expectedBytes))
        {
            snapshotCommitted = true;
            if (isActiveSavePath)
                NotifyActiveSaveV2Committed();
            Debug.Log("SAVE | Unchanged validated disk content; write skipped.");
            return true;
        }

        WriteSnapshotAtomically(path, expectedBytes);
        snapshotCommitted = true;
        if (!DiskMatchesSnapshot(path, expectedBytes))
        {
            Debug.LogError("SAVE | Written file could not be verified.");
            return false;
        }

        if (preserveOwnership)
        {
            string currentOwner = GetCurrentVerifiedSaveOwner();
            if (!string.Equals(
                    previousOwner,
                    currentOwner,
                    StringComparison.Ordinal))
            {
                SweetMerge.Cloud.LocalSaveOwnership.TryInvalidate(
                    path,
                    out _);
                SweetMerge.Cloud.PlayerStatisticsCloudSync
                    .InvalidateAuthorization(
                        "Statistics sync invalidated because the verified " +
                        "account changed during a Save V2 update.");
                Debug.LogWarning(
                    "SAVE OWNERSHIP | Verified account changed during save; " +
                    "local ownership is now unknown.",
                    this);
            }
            else if (!SweetMerge.Cloud.LocalSaveOwnership.TryRefreshAfterSave(
                         path,
                         currentOwner,
                         environment,
                         true,
                         out string ownershipError))
            {
                SweetMerge.Cloud.PlayerStatisticsCloudSync
                    .InvalidateAuthorization(
                        "Statistics sync invalidated because local save " +
                        "ownership could not be refreshed.");
                Debug.LogWarning(
                    "SAVE OWNERSHIP | Save V2 committed, but ownership could " +
                    "not be refreshed. Cloud operations remain blocked. " +
                    ownershipError,
                    this);
            }
        }

        Debug.Log($"SAVE | Successfully wrote save file.\nPath: {path}");
        if (isActiveSavePath)
            NotifyActiveSaveV2Committed();
        return true;
    }

    private bool IsActiveSavePath(string path)
    {
        try
        {
            return string.Equals(
                Path.GetFullPath(path),
                Path.GetFullPath(SaveFilePath),
                StringComparison.OrdinalIgnoreCase);
        }
        catch (Exception exception)
        {
            Debug.LogWarning(
                "SAVE OWNERSHIP | Save path could not be compared; ownership " +
                "will not be preserved.\n" + exception,
                this);
            return false;
        }
    }

    private string GetCurrentVerifiedSaveOwner()
    {
        try
        {
            return SweetMerge.Cloud.SimpleCloudBackup
                .GetVerifiedCurrentOwnerId();
        }
        catch (Exception exception)
        {
            Debug.LogWarning(
                "SAVE OWNERSHIP | Verified account could not be checked; " +
                "ownership will not be preserved.\n" + exception,
                this);
            return null;
        }
    }

    // The caller owns saveInProgress. One process/main-thread writer is required.

    // Temporary and primary files must stay in the same directory/filesystem.

    private void WriteSnapshotAtomically(string path, byte[] expectedBytes)
    {
        WriteSnapshotAtomically(path, expectedBytes, null);
    }

    private void WriteSnapshotAtomically(
        string path,
        byte[] expectedBytes,
        string corruptBackupDiagnosticPath)

    {

        string temporaryPath = path + ".tmp";

        Directory.CreateDirectory(Path.GetDirectoryName(path));

        // A stale temp is never loaded or promoted. Only a fresh save may replace it.

        using (var stream = new FileStream(temporaryPath, FileMode.Create,

            FileAccess.Write, FileShare.None))

        {

            stream.Write(expectedBytes, 0, expectedBytes.Length);

            stream.Flush(true);

        }

        // Re-read the CLOSED file, compare every byte, then validate that actual JSON.

        // This preserves the metadata and canonical serialization checks, without

        // mutating capacityLoadedData or the live session's provenance.

        byte[] actualBytes = File.ReadAllBytes(temporaryPath);

        if (actualBytes.Length != expectedBytes.Length)

            throw new IOException("Temporary save length differs from the validated snapshot.");

        for (int i = 0; i < actualBytes.Length; i++)

            if (actualBytes[i] != expectedBytes[i])

                throw new IOException("Temporary save bytes differ from the validated snapshot.");

        if (!IsValidSerializedSnapshotCore(SaveEncoding.GetString(actualBytes)))

            throw new IOException("Temporary save JSON failed validation.");

        // Backup the OLD primary, never the new snapshot or a stale temporary file.

        // A backup IO failure propagates before the primary can be replaced.

        CreateValidatedBackup(path, corruptBackupDiagnosticPath);

        CommitTemporaryFile(temporaryPath, path);

        // On failure, retain remaining .tmp for diagnosis. Never delete the primary

        // or try a copy/delete fallback. The outer Save operation reports failure.

    }

    private void CreateValidatedBackup(string path)
    {
        CreateValidatedBackup(path, null);
    }

    private void CreateValidatedBackup(
        string path,
        string corruptBackupDiagnosticPath)

    {

        byte[] primaryBytes;

        try

        {

            // Read once: validation and staging must use the same captured bytes.

            // File.Exists would hide access/IO errors and misclassify them as absence.

            primaryBytes = File.ReadAllBytes(path);

        }

        catch (FileNotFoundException)

        {

            // First save: there is no previous primary to back up.

            return;

        }

        if (!IsValidBackupCandidateCore(primaryBytes))

        {

            throw new IOException(
                "Existing V2 primary failed strict validation; refusing to replace it."
            );

        }

        string backupPath = path + ".bak";
        string backupTemporaryPath = backupPath + ".tmp";

        if (File.Exists(backupPath))
        {
            byte[] existingBackup = File.ReadAllBytes(backupPath);
            if (!IsValidBackupCandidateCore(existingBackup))
            {
                string diagnosticPath = corruptBackupDiagnosticPath ??
                    backupPath + ".corrupt." + Guid.NewGuid().ToString("N");
                using (var stream = new FileStream(
                    diagnosticPath,
                    FileMode.CreateNew,
                    FileAccess.Write,
                    FileShare.None))
                {
                    stream.Write(existingBackup, 0, existingBackup.Length);
                    stream.Flush(true);
                }

                byte[] diagnosticBytes = File.ReadAllBytes(diagnosticPath);
                if (!BytesEqual(diagnosticBytes, existingBackup))
                    throw new IOException(
                        "Corrupt backup diagnostic copy failed byte verification; save aborted.");
            }
        }

        if (DiskMatchesSnapshot(backupPath, primaryBytes))
            return; // Exact bytes of an independently validated primary already exist.

        // Never open .bak for writing. A stale .bak.tmp is never trusted.

        using (var stream = new FileStream(backupTemporaryPath, FileMode.Create,

            FileAccess.Write, FileShare.None))

        {

            stream.Write(primaryBytes, 0, primaryBytes.Length);

            stream.Flush(true);

        }

        byte[] stagedBytes = File.ReadAllBytes(backupTemporaryPath);

        if (!BytesEqual(stagedBytes, primaryBytes) || !IsValidBackupCandidateCore(stagedBytes))

            throw new IOException("Backup staging verification failed; primary was not committed.");

        // Defensive check; this does not replace the single-writer requirement.

        if (!DiskMatchesSnapshot(path, primaryBytes))

            throw new IOException("Primary changed while staging its backup; save aborted.");

        // Reuse the same-directory Windows/Android promotion, with no unlink gap

        // and no automatic backup side effect that could copy an unvalidated file.

        CommitTemporaryFile(backupTemporaryPath, backupPath);

        if (!DiskMatchesSnapshot(backupPath, primaryBytes))

            throw new IOException("Promoted backup could not be verified; primary was not committed.");

        Debug.Log("SAVE BACKUP | Validated previous primary preserved.");

    }

    // Pure inspection: never call TryLoad/Restore here or change capacity provenance.

    // Canonical JSON and a non-mutating sanitation round trip are deliberately

    // conservative: legacy, reformatted and unknown-schema files are not rotated.

    private static bool IsValidBackupCandidateCore(byte[] bytes)

    {

        try

        {

            string json = SaveEncoding.GetString(bytes);

            if (!IsValidSerializedSnapshotCore(json))

                return false;

            var data = JsonUtility.FromJson<PlayerSaveData>(json);

            var metadata = JsonUtility.FromJson<CustomerCapacityMetadata>(json);

            if (metadata == null)
                return false;
            if (metadata.servingPlateProgressionVersion < 0 ||
                metadata.servingPlateProgressionVersion >
                    CurrentServingPlateProgressionVersion)
                return false;

            var gameplay = data.mergeGameplay;

            int capacity = metadata.mergeSessionCustomerCapacity;

            if (!gameplay.hasSession)

                return capacity == 0 && gameplay.boardDesserts.Count == 0 &&

                    gameplay.shelfDesserts.Count == 0 && gameplay.customerOrders.Count == 0;

            if (capacity < 1 || capacity > 4 ||
                (metadata.servingPlateProgressionVersion > 0 && capacity > 3) ||
                gameplay.customerOrders.Count != capacity)

                return false;

            var cells = new System.Collections.Generic.HashSet<int>();

            foreach (var dessert in gameplay.boardDesserts)

                if (!cells.Add(dessert.cellIndex))

                    return false;

            var shelves = new System.Collections.Generic.HashSet<int>();

            foreach (var dessert in gameplay.shelfDesserts)

                if (!shelves.Add(dessert.slotIndex))

                    return false;

            var customers = new System.Collections.Generic.HashSet<int>();

            var orderIds = new System.Collections.Generic.HashSet<int>();

            foreach (var order in gameplay.customerOrders)

                if (order.customerIndex >= capacity || !customers.Add(order.customerIndex) ||

                    !orderIds.Add(order.orderId) || order.orderId >= gameplay.nextOrderId)

                    return false;

            return true;

        }

        catch (ArgumentException)

        {

            // JsonUtility parse errors and strict UTF-8 decoding errors are invalid input.

            return false;

        }

    }

    private static bool BytesEqual(byte[] actual, byte[] expected)

    {

        if (actual.Length != expected.Length)

            return false;

        for (int i = 0; i < actual.Length; i++)

            if (actual[i] != expected[i])

                return false;

        return true;

    }

#if UNITY_EDITOR_WIN || UNITY_STANDALONE_WIN

    [System.Runtime.InteropServices.DllImport("kernel32.dll",

        EntryPoint = "MoveFileExW", CharSet = System.Runtime.InteropServices.CharSet.Unicode,

        ExactSpelling = true, SetLastError = true)]

    [return: System.Runtime.InteropServices.MarshalAs(System.Runtime.InteropServices.UnmanagedType.Bool)]

    private static extern bool MoveSaveFileWindows(string source, string destination, uint flags);

#elif UNITY_ANDROID && !UNITY_EDITOR

    [System.Runtime.InteropServices.DllImport("libc", EntryPoint = "rename",

        CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl,

        ExactSpelling = true, SetLastError = true)]

    private static extern int RenameSaveFileAndroid(byte[] source, byte[] destination);

#endif

    private static void CommitTemporaryFile(string temporaryPath, string path)

    {

#if UNITY_EDITOR_WIN || UNITY_STANDALONE_WIN

        // Same-volume rename, replace if present. Deliberately omit COPY_ALLOWED.

        const uint ReplaceExisting = 0x1;

        const uint WriteThrough = 0x8;

        if (!MoveSaveFileWindows(temporaryPath, path, ReplaceExisting | WriteThrough))

        {

            int error = System.Runtime.InteropServices.Marshal.GetLastWin32Error();

            throw new IOException("Save commit failed (Windows error " + error + ").");

        }

#elif UNITY_ANDROID && !UNITY_EDITOR

        // Explicit NUL-terminated UTF-8 paths avoid ANSI marshaling ambiguity.

        // POSIX rename replaces an existing destination without an unlink gap.

        if (RenameSaveFileAndroid(SaveEncoding.GetBytes(temporaryPath + "\0"),

                SaveEncoding.GetBytes(path + "\0")) != 0)

        {

            int error = System.Runtime.InteropServices.Marshal.GetLastWin32Error();

            throw new IOException("Save commit failed (Android errno " + error + ").");

        }

#else

        throw new PlatformNotSupportedException(

            "Atomic save commit is configured for Windows Editor/player and Android player only.");

#endif

    }

    private static bool IsValidSerializedSnapshotCore(string json)

    {

        if (string.IsNullOrWhiteSpace(json))

            return false;

        PlayerSaveData check = JsonUtility.FromJson<PlayerSaveData>(json);

        if (check == null || !IsSupportedVersionCore(check.saveVersion) ||
            check.economy == null || check.progression == null ||

            check.mergeGameplay == null ||

            check.mergeGameplay.boardDesserts == null ||

            check.mergeGameplay.shelfDesserts == null ||

            check.mergeGameplay.customerOrders == null)

        {

            return false;

        }

        int collectionSectionCount =
            CountJsonProperty(json, "dessertCollection");
        int discoveredTierListCount =
            CountJsonProperty(json, "discoveredTierIds");
        int claimedMilestoneListCount =
            CountJsonProperty(json, "claimedMilestoneIds");
        bool collectionSectionPresent =
            collectionSectionCount == 1;
        if (collectionSectionCount > 1)
            return false;
        if (!collectionSectionPresent)
        {
            if (discoveredTierListCount != 0 ||
                claimedMilestoneListCount != 0)
            {
                return false;
            }

            check.dessertCollection =
                new DessertCollectionSaveData();
        }
        else if (discoveredTierListCount != 1 ||
                 claimedMilestoneListCount != 1 ||
                 !DessertCollectionState.TryValidateSaveData(
                     check.dessertCollection,
                     out _))
        {
            return false;
        }

        if (check.economy.totalOrdersCompleted < 0 ||
            check.economy.totalMoneyEarned < 0)
        {
            return false;
        }

        if (!IsValidRebirthSaveState(
                check.completedRebirthCount,
                check.highestTierCreatedThisRun,
                check.campaignComplete))
        {
            return false;
        }

        CustomerCapacityMetadata metadata =
            JsonUtility.FromJson<CustomerCapacityMetadata>(json);
        if (metadata == null ||
            (!string.IsNullOrEmpty(metadata.selectedSpawnPoolId) &&
             !DessertSpawner.IsValidSpawnPoolId(metadata.selectedSpawnPoolId)) ||
            metadata.luckLevel < 0 ||
            metadata.luckLevel > 4 ||
            metadata.servingPlateProgressionVersion < 0 ||
            metadata.servingPlateProgressionVersion >
                CurrentServingPlateProgressionVersion)
            return false;
        if (!TryParseEnergyMetadata(
                json,
                out EnergySaveMetadata energy,
                out bool hasEnergyMetadata))
        {
            return false;
        }
        TryCreateLegacyEnergyNormalizedJson(
            json,
            out string normalizedComparableJson);
        string comparisonJson =
            normalizedComparableJson ?? json;
        int capacity = metadata.mergeSessionCustomerCapacity;

        if (check.mergeGameplay.hasSession &&
            (capacity < 1 || capacity > 4 ||
             (metadata.servingPlateProgressionVersion > 0 && capacity > 3)))
            return false;
        if (metadata.servingPlateProgressionVersion > 0 &&
            (check.progression.shelfLevel < 1 ||
             check.progression.shelfLevel > 4 ||
             check.progression.customerLevel < 1 ||
             check.progression.customerLevel > 3))
            return false;

        string canonicalJson =
            SerializeWithServingPlateVersion(
                check,
                capacity,
                metadata.selectedSpawnPoolId,
                metadata.luckLevel,
                metadata.servingPlateProgressionVersion);
        if (hasEnergyMetadata)
            canonicalJson = SerializeWithEnergy(canonicalJson, energy);
        bool statisticsAreZero =
            check.economy.totalOrdersCompleted == 0 &&
            check.economy.totalMoneyEarned == 0;
        if (!MatchesSupportedCanonicalShape(
                comparisonJson,
                canonicalJson,
                collectionSectionPresent,
                statisticsAreZero))
            return false;

        SanitizeSaveDataCore(check);

        canonicalJson =
            SerializeWithServingPlateVersion(
                check,
                capacity,
                metadata.selectedSpawnPoolId,
                metadata.luckLevel,
                metadata.servingPlateProgressionVersion);
        if (hasEnergyMetadata)
            canonicalJson = SerializeWithEnergy(canonicalJson, energy);
        return MatchesSupportedCanonicalShape(
            comparisonJson,
            canonicalJson,
            collectionSectionPresent,
            statisticsAreZero);

    }

    private static bool IsValidRebirthSaveState(
        int completedRebirthCount,
        int highestTierCreatedThisRun,
        bool campaignComplete)
    {
        if (completedRebirthCount < 0 || completedRebirthCount > 10 ||
            highestTierCreatedThisRun < 0 || highestTierCreatedThisRun > 30)
        {
            return false;
        }

        return campaignComplete ==
               (completedRebirthCount == 10 &&
                highestTierCreatedThisRun == 30);
    }

    private static bool DiskMatchesSnapshot(string path, byte[] expected)

    {

        try

        {

            // Read failures, missing files and partial files all force a write attempt.

            byte[] actual = File.ReadAllBytes(path);

            if (actual.Length != expected.Length)

                return false;

            for (int i = 0; i < actual.Length; i++)

            {

                if (actual[i] != expected[i])

                    return false;

            }

            return true;

        }

        catch (IOException) { return false; }

        catch (UnauthorizedAccessException) { return false; }

    }

    // ==================================================

    // LOAD

    // ==================================================

    // V2 is isolated on its own path; V1 files are never considered for loading.
    private enum SaveVersionClassification
    {
        MissingOrUnreadable,
        Current,
        UnsupportedOlder,
        UnsupportedFuture,
        Ambiguous
    }

    private static SaveVersionClassification ClassifySaveVersion(byte[] bytes, out int version)
    {
        version = 0;
        if (bytes == null) return SaveVersionClassification.MissingOrUnreadable;
        try
        {
            string json = SaveEncoding.GetString(bytes);
            // Check the literal field, not the JsonUtility default of 0 when absent.
            // Multiple saveVersion declarations are ambiguous and must not be loaded.
            var matches = System.Text.RegularExpressions.Regex.Matches(json,
                @"""saveVersion""\s*:\s*(-?\d+)");
            if (matches.Count > 1) return SaveVersionClassification.Ambiguous;
            if (matches.Count == 0) return SaveVersionClassification.MissingOrUnreadable;
            if (!int.TryParse(matches[0].Groups[1].Value,
                System.Globalization.NumberStyles.Integer,
                System.Globalization.CultureInfo.InvariantCulture, out version))
                return SaveVersionClassification.Ambiguous;
            if (version > CurrentSaveVersion) return SaveVersionClassification.UnsupportedFuture;
            if (version < CurrentSaveVersion) return SaveVersionClassification.UnsupportedOlder;
            return SaveVersionClassification.Current;
        }
        catch (ArgumentException)
        {
            return SaveVersionClassification.MissingOrUnreadable;
        }
    }

    // V2 has no migration path from the isolated V1 save.
    private enum MigrationDecision
    {
        LoadCurrent,
        MigrationNotRegistered,
        FutureVersionBlocked,
        AmbiguousVersionBlocked,
        UnreadableVersion
    }

    private static MigrationDecision EvaluateMigration(byte[] sourceBytes, out int sourceVersion)
    {
        SaveVersionClassification classification =
            ClassifySaveVersion(sourceBytes, out sourceVersion);

        switch (classification)
        {
            case SaveVersionClassification.Current:
                return MigrationDecision.LoadCurrent;
            case SaveVersionClassification.UnsupportedOlder:
                // No older-version migrations are registered. Do not reinterpret
                // old data as V1 or manufacture defaults for missing fields.
                return MigrationDecision.MigrationNotRegistered;
            case SaveVersionClassification.UnsupportedFuture:
                // A newer build may have written data this build cannot read.
                // Never roll it back to an older backup automatically.
                return MigrationDecision.FutureVersionBlocked;
            case SaveVersionClassification.Ambiguous:
                return MigrationDecision.AmbiguousVersionBlocked;
            default:
                // Only unreadable/missing versions can be considered corrupt
                // and eligible for existing validated-backup recovery.
                return MigrationDecision.UnreadableVersion;
        }
    }

    private static bool IsMigrationBlocked(MigrationDecision decision)
    {
        return decision == MigrationDecision.MigrationNotRegistered ||
               decision == MigrationDecision.FutureVersionBlocked ||
               decision == MigrationDecision.AmbiguousVersionBlocked;
    }

    internal SaveDiscoveryStatus InspectSaveBytesForDiscovery(
        byte[] bytes,
        out SaveDiscoveryVersionKind versionKind,
        out int version)
    {
        versionKind = SaveDiscoveryVersionKind.Unknown;
        version = 0;
        if (bytes == null)
            return SaveDiscoveryStatus.Unknown;

        SaveVersionClassification classification =
            ClassifySaveVersion(bytes, out version);
        switch (classification)
        {
            case SaveVersionClassification.Current:
                versionKind = SaveDiscoveryVersionKind.V2;
                return IsStrictlyValidSaveFile(bytes)
                    ? SaveDiscoveryStatus.ValidV2
                    : SaveDiscoveryStatus.Invalid;
            case SaveVersionClassification.UnsupportedOlder:
                versionKind = SaveDiscoveryVersionKind.UnsupportedOlder;
                return SaveDiscoveryStatus.UnsupportedVersion;
            case SaveVersionClassification.UnsupportedFuture:
                versionKind = SaveDiscoveryVersionKind.UnsupportedFuture;
                return SaveDiscoveryStatus.UnsupportedVersion;
            case SaveVersionClassification.Ambiguous:
                versionKind = SaveDiscoveryVersionKind.Ambiguous;
                version = 0;
                return SaveDiscoveryStatus.Unknown;
            default:
                version = 0;
                return SaveDiscoveryStatus.Invalid;
        }
    }

    // Step 12.8.8.3 — primary-first load with independently validated backup recovery.
    // This method only reads and recovers file bytes; gameplay restoration remains
    // the responsibility of LoadCurrentGameCore and the startup coordinator.
    public bool TryLoad(out PlayerSaveData saveData)
    {
        saveData = null;
        if (SweetMerge.Cloud.SimpleCloudFiles.RestorePending)
        {
            Debug.LogWarning(
                "LOAD | Save V2 reads are blocked until the pending cloud restore is resolved.",
                this);
            return false;
        }

        string primaryPath = SaveFilePath;
        byte[] primaryBytes = null;
        bool primaryExists = false;

        try
        {
            primaryBytes = File.ReadAllBytes(primaryPath);
            primaryExists = true;
        }
        catch (FileNotFoundException)
        {
            // No primary: a valid backup may still exist.
        }
        catch (DirectoryNotFoundException)
        {
            // Fresh installation or missing directory: check for backup below.
        }
        catch (Exception exception)
        {
            // Do not assume an unreadable primary is corrupt, and do not overwrite it.
            Debug.LogError("LOAD | Primary save could not be read; recovery was not attempted.\n" + exception);
            return false;
        }

        if (primaryExists)
        {
            int detectedVersion;
            MigrationDecision decision = EvaluateMigration(primaryBytes, out detectedVersion);
            if (IsMigrationBlocked(decision))
            {
                Debug.LogError("LOAD VERSION | Primary save version is unsupported or ambiguous (" +
                    detectedVersion + "). File and backup preserved; no downgrade/recovery attempted.");
                return false;
            }
        }

        if (primaryExists && IsStrictlyValidSaveFile(primaryBytes))
        {
            return TryParseValidatedBytes(primaryBytes, primaryPath, out saveData);
        }

        if (primaryExists)
            Debug.LogWarning("LOAD RECOVERY | Primary save failed strict validation. Checking backup.");
        else
            Debug.LogWarning("LOAD RECOVERY | Primary save is missing. Checking backup.");

        string backupPath = primaryPath + ".bak";
        byte[] backupBytes;
        try
        {
            backupBytes = File.ReadAllBytes(backupPath);
        }
        catch (FileNotFoundException)
        {
            Debug.LogWarning("LOAD RECOVERY | No backup exists. No save files were changed.");
            return false;
        }
        catch (DirectoryNotFoundException)
        {
            Debug.LogWarning("LOAD RECOVERY | No backup directory exists. No save files were changed.");
            return false;
        }
        catch (Exception exception)
        {
            Debug.LogError("LOAD RECOVERY | Backup could not be read. No save files were changed.\n" + exception);
            return false;
        }

        int backupVersion;
        if (EvaluateMigration(backupBytes, out backupVersion) != MigrationDecision.LoadCurrent)
        {
            Debug.LogError("LOAD VERSION | Backup is not a supported V2 save. No files changed.");
            return false;
        }

        if (!IsStrictlyValidSaveFile(backupBytes))
        {
            Debug.LogError("LOAD RECOVERY | Backup failed strict validation. No save files were changed.");
            return false;
        }

        // Verify the backup is deserializable before changing the primary path.
        if (!TryParseValidatedBytes(backupBytes, backupPath, out PlayerSaveData recoveredData))
            return false;

        try
        {
            RestorePrimaryFromBackup(primaryPath, backupBytes, primaryExists, primaryBytes);
        }
        catch (Exception exception)
        {
            Debug.LogError("LOAD RECOVERY | Failed to restore primary. Backup was preserved.\n" + exception);
            return false;
        }

        // Parse the verified bytes again, binding capacity metadata to the returned object.
        if (!TryParseValidatedBytes(backupBytes, primaryPath, out saveData))
            return false;

        Debug.LogWarning("LOAD RECOVERY | Validated backup restored to primary successfully.");
        return true;
    }

    // Strict, non-mutating validation; never silently sanitize a corrupt file.
    private bool IsStrictlyValidSaveFile(byte[] bytes)
    {
        try
        {
            return bytes != null && IsValidBackupCandidateCore(bytes);
        }
        catch (Exception exception)
        {
            Debug.LogWarning("LOAD | Candidate validation rejected file: " + exception.Message);
            return false;
        }
    }

    private bool TryParseValidatedBytes(byte[] bytes, string sourcePath, out PlayerSaveData data)
    {
        data = null;
        try
        {
            if (!IsStrictlyValidSaveFile(bytes))
                return false;

            string json = SaveEncoding.GetString(bytes);
            PlayerSaveData parsed = JsonUtility.FromJson<PlayerSaveData>(json);
            CustomerCapacityMetadata metadata = JsonUtility.FromJson<CustomerCapacityMetadata>(json);
            if (parsed == null ||
                metadata == null ||
                !TryParseEnergyMetadata(
                    json,
                    out EnergySaveMetadata energyMetadata,
                    out bool hasEnergyMetadata))
            {
                return false;
            }

            loadedCollectionSectionPresent =
                CountJsonProperty(json, "dessertCollection") == 1;
            if (!loadedCollectionSectionPresent)
                parsed.dessertCollection =
                    new DessertCollectionSaveData();

            if (!hasEnergyMetadata)
            {
                energyMetadata = new EnergySaveMetadata
                {
                    currentEnergy = 30,
                    energyMillisecondsUntilNextPoint = 60000,
                    energySavedUtcTicks = DateTime.UtcNow.Ticks
                };
                Debug.Log(
                    "LOAD | Legacy Save V2 profile has no Energy metadata; " +
                    "Energy balance retained at 30 with a 60000 ms countdown.");
            }

            // No mutation is necessary: the exact serialized bytes passed strict
            // canonical, structural and non-destructive sanitation validation.
            capacityLoadedData = parsed;
            loadedCustomerCapacity = metadata.mergeSessionCustomerCapacity;
            loadedSelectedSpawnPoolId = metadata.selectedSpawnPoolId;
            sessionSelectedSpawnPoolId = loadedSelectedSpawnPoolId;
            loadedLuckLevel = metadata.luckLevel > 0
                ? metadata.luckLevel
                : 1;
            loadedServingPlateProgressionVersion =
                metadata.servingPlateProgressionVersion;
            loadedEnergyMetadata = energyMetadata;
            compatibilityMigrationPending = false;
            sessionLuckLevel = loadedLuckLevel;
            data = parsed;
            Debug.Log("LOAD | Successfully read validated save file.\nPath: " + sourcePath);
            return true;
        }
        catch (Exception exception)
        {
            Debug.LogError("LOAD | Failed to parse validated save.\n" + exception);
            return false;
        }
    }

    private void RestorePrimaryFromBackup(string primaryPath, byte[] backupBytes,
        bool primaryExists, byte[] originalPrimaryBytes)
    {
        string backupPath = primaryPath + ".bak";
        string recoveryTemporaryPath = primaryPath + ".recover.tmp";

        // Re-read backup immediately before staging; never promote a stale or
        // changed backup. A single main-thread writer is still required.
        if (!DiskMatchesSnapshot(backupPath, backupBytes))
            throw new IOException("Backup changed during recovery; refusing to proceed.");

        // Preserve damaged bytes for diagnosis if possible, without risking recovery
        // or overwriting any earlier diagnostic file. A failed diagnostic copy is
        // nonfatal because the validated backup remains untouched.
        if (primaryExists && originalPrimaryBytes != null)
        {
            string diagnosticPath = primaryPath + ".corrupt." + Guid.NewGuid().ToString("N");
            try
            {
                using (var stream = new FileStream(diagnosticPath, FileMode.CreateNew,
                    FileAccess.Write, FileShare.None))
                {
                    stream.Write(originalPrimaryBytes, 0, originalPrimaryBytes.Length);
                    stream.Flush(true);
                }
                if (!DiskMatchesSnapshot(diagnosticPath, originalPrimaryBytes))
                    Debug.LogWarning("LOAD RECOVERY | Diagnostic copy could not be verified.");
            }
            catch (Exception exception)
            {
                Debug.LogWarning("LOAD RECOVERY | Could not preserve diagnostic copy: " + exception.Message);
            }
        }

        Directory.CreateDirectory(Path.GetDirectoryName(primaryPath));
        using (var stream = new FileStream(recoveryTemporaryPath, FileMode.Create,
            FileAccess.Write, FileShare.None))
        {
            stream.Write(backupBytes, 0, backupBytes.Length);
            stream.Flush(true);
        }

        byte[] stagedBytes = File.ReadAllBytes(recoveryTemporaryPath);
        if (!BytesEqual(stagedBytes, backupBytes) || !IsStrictlyValidSaveFile(stagedBytes))
            throw new IOException("Recovery temporary file failed byte or JSON validation.");

        if (!DiskMatchesSnapshot(backupPath, backupBytes))
            throw new IOException("Backup changed before primary recovery commit.");

        if (!SweetMerge.Cloud.LocalSaveOwnership.TryInvalidate(
                primaryPath,
                out string ownershipError))
        {
            throw new IOException(
                "Save ownership could not be invalidated before backup " +
                "recovery: " + ownershipError);
        }

        SweetMerge.Cloud.PlayerStatisticsCloudSync.InvalidateAuthorization(
            "Statistics sync invalidated by local save recovery.");
        // Reuse existing Windows/Android atomic rename. Critically, do NOT call
        // SaveCore or CreateValidatedBackup here: a damaged primary must never
        // replace the known-good .bak.
        CommitTemporaryFile(recoveryTemporaryPath, primaryPath);

        if (!DiskMatchesSnapshot(primaryPath, backupBytes))
            throw new IOException("Recovered primary failed post-commit verification.");
    }

    // ==================================================

    private static bool IsSupportedVersionCore(

        int version)

    {

        return version ==

            CurrentSaveVersion;

    }

    // ==================================================

    // SANITIZATION

    // ==================================================

    private static void SanitizeSaveDataCore(

        PlayerSaveData saveData)

    {

        if (saveData == null)

            return;

        // ----------------------------------------------

        // ECONOMY

        // ----------------------------------------------

        if (saveData.economy == null)

        {

            saveData.economy =

                new EconomySaveData();

        }

        if (saveData.economy.cash < 0)

        {

            saveData.economy.cash =

                0;

        }

        // ----------------------------------------------

        // PROGRESSION

        // ----------------------------------------------

        if (saveData.progression == null)

        {

            saveData.progression =

                new ProgressionSaveData();

        }

        saveData.progression.ovenLevel =

            Mathf.Max(

                1,

                saveData.progression.ovenLevel

            );

        saveData.progression.boardSpaceLevel =

            Mathf.Max(

                1,

                saveData.progression.boardSpaceLevel

            );

        saveData.progression.shelfLevel =

            Mathf.Max(

                1,

                saveData.progression.shelfLevel

            );

        saveData.progression.customerLevel =

            Mathf.Max(

                1,

                saveData.progression.customerLevel

            );

        saveData.progression.moneyMultiplierLevel =

            Mathf.Max(

                1,

                saveData.progression

                    .moneyMultiplierLevel

            );

        // ----------------------------------------------

        // MERGE GAMEPLAY

        // ----------------------------------------------

        if (saveData.mergeGameplay == null)

        {

            saveData.mergeGameplay =

                new MergeGameplaySaveData();

        }

        if (saveData.mergeGameplay.boardDesserts ==

            null)

        {

            saveData.mergeGameplay.boardDesserts =

                new System.Collections.Generic.List<

                    BoardDessertSaveData>();

        }

        if (saveData.mergeGameplay.shelfDesserts ==

            null)

        {

            saveData.mergeGameplay.shelfDesserts =

                new System.Collections.Generic.List<

                    ShelfDessertSaveData>();

        }

        if (saveData.mergeGameplay.customerOrders ==

            null)

        {

            saveData.mergeGameplay.customerOrders =

                new System.Collections.Generic.List<

                    CustomerOrderSaveData>();

        }

        saveData.mergeGameplay.nextOrderId =

            Mathf.Max(

                1,

                saveData.mergeGameplay.nextOrderId

            );

        if (saveData.mergeGameplay.nextDessertTier <

            -1)

        {

            saveData.mergeGameplay.nextDessertTier =

                -1;

        }

        SanitizeBoardDessertsCore(

            saveData.mergeGameplay

                .boardDesserts

        );

        SanitizeShelfDessertsCore(

            saveData.mergeGameplay

                .shelfDesserts

        );

        SanitizeCustomerOrdersCore(

            saveData.mergeGameplay

                .customerOrders

        );

    }

    private static void SanitizeBoardDessertsCore(

        System.Collections.Generic.List<

            BoardDessertSaveData> desserts)

    {

        for (int i = desserts.Count - 1;

             i >= 0;

             i--)

        {

            BoardDessertSaveData dessert =

                desserts[i];

            if (dessert == null ||

                dessert.cellIndex < 0 ||

                dessert.dessertTier <= 0)

            {

                desserts.RemoveAt(i);

            }

        }

    }

    private static void SanitizeShelfDessertsCore(

        System.Collections.Generic.List<

            ShelfDessertSaveData> desserts)

    {

        for (int i = desserts.Count - 1;

             i >= 0;

             i--)

        {

            ShelfDessertSaveData dessert =

                desserts[i];

            if (dessert == null ||

                dessert.slotIndex < 0 ||

                dessert.dessertTier <= 0)

            {

                desserts.RemoveAt(i);

            }

        }

    }

    private static void SanitizeCustomerOrdersCore(

        System.Collections.Generic.List<

            CustomerOrderSaveData> orders)

    {

        for (int i = orders.Count - 1;

             i >= 0;

             i--)

        {

            CustomerOrderSaveData order =

                orders[i];

            if (order == null ||

                order.customerIndex < 0 ||

                order.orderId <= 0 ||

                string.IsNullOrWhiteSpace(

                    order.definitionId))

            {

                orders.RemoveAt(i);

            }

        }

    }

    // ==================================================

    // DEBUG TEST SAVE

    // ==================================================

    [ContextMenu("Debug Write Test Save")]

    private void DebugWriteTestSave()

    {

        PlayerSaveData testData =

            CreateNewSaveData();

        testData.economy.cash =

            12345;

        testData.progression.ovenLevel =

            2;

        testData.progression.boardSpaceLevel =

            3;

        testData.progression.shelfLevel =

            2;

        testData.progression.customerLevel =

            2;

        testData.progression.moneyMultiplierLevel =

            2;

        testData.mergeGameplay.hasSession =

            true;

        testData.mergeGameplay.nextOrderId =

            42;

        testData.mergeGameplay.nextDessertTier =

            5;

        testData.mergeGameplay.boardDesserts.Add(

            new BoardDessertSaveData(

                0,

                2

            )

        );

        testData.mergeGameplay.boardDesserts.Add(

            new BoardDessertSaveData(

                4,

                7

            )

        );

        testData.mergeGameplay.shelfDesserts.Add(

            new ShelfDessertSaveData(

                0,

                3

            )

        );

        bool success =

            Save(testData);

        if (success)

        {

            Debug.Log(

                "SAVE TEST | Test PlayerSaveData " +

                "was serialized successfully."

            );

        }

    }

    // ==================================================

    // DEBUG TEST LOAD

    // ==================================================

    [ContextMenu("Debug Read Test Save")]

    private void DebugReadTestSave()

    {

        if (!TryLoad(

                out PlayerSaveData saveData))

        {

            Debug.LogError(

                "LOAD TEST | Could not load " +

                "PlayerSaveData."

            );

            return;

        }

        Debug.Log(

            "LOAD TEST | " +

            $"Version: {saveData.saveVersion} | " +

            $"Cash: {saveData.economy.cash} | " +

            $"Oven: L{saveData.progression.ovenLevel} | " +

            $"Board: L{saveData.progression.boardSpaceLevel} | " +

            $"Shelf: L{saveData.progression.shelfLevel} | " +

            $"Customer: L{saveData.progression.customerLevel} | " +

            $"Money: L{saveData.progression.moneyMultiplierLevel}"

        );

        Debug.Log(

            "LOAD TEST | " +

            $"Has Session: " +

            $"{saveData.mergeGameplay.hasSession} | " +

            $"Board Desserts: " +

            $"{saveData.mergeGameplay.boardDesserts.Count} | " +

            $"Shelf Desserts: " +

            $"{saveData.mergeGameplay.shelfDesserts.Count} | " +

            $"Customer Orders: " +

            $"{saveData.mergeGameplay.customerOrders.Count} | " +

            $"Next Order ID: " +

            $"{saveData.mergeGameplay.nextOrderId} | " +

            $"Next Dessert: T" +

            $"{saveData.mergeGameplay.nextDessertTier}"

        );

    }

    // ==================================================

    // DEBUG FILE TOOLS

    // ==================================================

    [ContextMenu("Debug Print Save Path")]

    private void DebugPrintSavePath()

    {

        Debug.Log(

            $"SAVE | Path: {SaveFilePath}"

        );

    }

    [ContextMenu("Debug Check Save File")]

    private void DebugCheckSaveFile()

    {

        Debug.Log(

            $"SAVE | File Exists: " +

            $"{SaveFileExists()}"

        );

    }

    // ==================================================

    // DEBUG SAVE MANAGEMENT

    // ==================================================

    [ContextMenu("Debug Create Fresh Save")]

    private void DebugCreateFreshSave()

    {

        PlayerSaveData freshSave =

            CreateNewSaveData();

        bool success =

            Save(freshSave);

        if (!success)

        {

            Debug.LogError(

                "SAVE DEBUG | Failed to create " +

                "fresh save."

            );

            return;

        }

        Debug.Log(

            "SAVE DEBUG | Fresh save created."

        );

        PrintSaveSummary(

            freshSave

        );

    }

    [ContextMenu("Debug Delete Save")]

    private void DebugDeleteSave()

    {

        if (saveInProgress || loadInProgress)

            return;

        if (!SaveFileExists())

        {

            Debug.Log(

                "SAVE DEBUG | No save file exists " +

                "to delete."

            );

            return;

        }

        try
        {
            SweetMerge.Cloud.PlayerStatisticsCloudSync.InvalidateAuthorization(
                "Statistics sync invalidated by a local save deletion.");
            if (!SweetMerge.Cloud.LocalSaveOwnership.TryInvalidate(
                    SaveFilePath,
                    out string ownershipError))
            {
                Debug.LogError(
                    "SAVE DEBUG | Save deletion was blocked because ownership " +
                    "could not be invalidated: " + ownershipError,
                    this);
                return;
            }

            File.Delete(

                SaveFilePath

            );

            Debug.Log(

                "SAVE DEBUG | Save file deleted."

            );

        }

        catch (Exception exception)

        {

            Debug.LogError(

                $"SAVE DEBUG | Failed to delete " +

                $"save file.\n{exception}"

            );

        }

    }

    [ContextMenu("Debug Print Save Summary")]

    private void DebugPrintSaveSummary()

    {

        if (!TryLoad(

                out PlayerSaveData saveData))

        {

            Debug.LogWarning(

                "SAVE DEBUG | No valid save data " +

                "could be summarized."

            );

            return;

        }

        PrintSaveSummary(

            saveData

        );

    }

    [ContextMenu("Debug Save Current Game")]

    private void DebugSaveCurrentGame()

    {

        bool success =

            SaveCurrentGame();

        if (success)

        {

            Debug.Log(

                "SAVE DEBUG | Current game " +

                "saved successfully."

            );

        }

        else

        {

            Debug.LogError(

                "SAVE DEBUG | Current game " +

                "save failed."

            );

        }

    }

    [ContextMenu("Debug Load Current Game")]

    private void DebugLoadCurrentGame()

    {

        bool success =

            LoadCurrentGame();

        if (success)

        {

            Debug.Log(

                "LOAD DEBUG | Current game " +

                "loaded successfully."

            );

        }

        else

        {

            Debug.LogWarning(

                "LOAD DEBUG | Current game " +

                "load failed."

            );

        }

    }

    private void PrintSaveSummary(

        PlayerSaveData saveData)

    {

        if (saveData == null)

        {

            Debug.LogWarning(

                "SAVE DEBUG | Save data is null."

            );

            return;

        }

        Debug.Log(

            "========== SAVE SUMMARY ==========\n" +

            $"Version: {saveData.saveVersion}\n" +

            $"Cash: ${saveData.economy.cash}\n" +

            "\n" +

            "PROGRESSION\n" +

            $"Oven: L{saveData.progression.ovenLevel}\n" +

            $"Board Space: " +

            $"L{saveData.progression.boardSpaceLevel}\n" +

            $"Shelf: L{saveData.progression.shelfLevel}\n" +

            $"Customer: " +

            $"L{saveData.progression.customerLevel}\n" +

            $"Money Multiplier: " +

            $"L{saveData.progression.moneyMultiplierLevel}\n" +

            "\n" +

            "MERGE SESSION\n" +

            $"Has Session: " +

            $"{saveData.mergeGameplay.hasSession}\n" +

            $"Board Desserts: " +

            $"{saveData.mergeGameplay.boardDesserts.Count}\n" +

            $"Shelf Desserts: " +

            $"{saveData.mergeGameplay.shelfDesserts.Count}\n" +

            $"Customer Orders: " +

            $"{saveData.mergeGameplay.customerOrders.Count}\n" +

            $"Next Order ID: " +

            $"{saveData.mergeGameplay.nextOrderId}\n" +

            $"Next Dessert Tier: " +

            $"{saveData.mergeGameplay.nextDessertTier}\n" +

            "=================================="

        );

    }

    // ==================================================

    // DEBUG - SIMULATE APPLICATION PAUSE

    // ==================================================

    [ContextMenu("Debug Simulate Application Pause")]

    private void DebugSimulateApplicationPause()

    {

        OnApplicationPause(true);

    }

    // ==================================================

    // DEBUG - SIMULATE APPLICATION QUIT

    // ==================================================

    [ContextMenu("Debug Simulate Application Quit")]

    private void DebugSimulateApplicationQuit()

    {

        OnApplicationQuit();

    }

}
