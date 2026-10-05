using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(
    fileName = "CustomerOrderDatabase",
    menuName = "Sweet Merge/Customer Order Database"
)]
public class CustomerOrderDatabase :
    ScriptableObject
{
    // ==================================================
    // DEFINITIONS
    // ==================================================

    [Header("Customer Orders")]
    [SerializeField]
    private CustomerOrderDefinition[] definitions;

    // ==================================================
    // RUNTIME LOOKUP
    // ==================================================

    private Dictionary<string, CustomerOrderDefinition>
        definitionLookup;

    // ==================================================
    // PUBLIC PROPERTIES
    // ==================================================

    public IReadOnlyList<CustomerOrderDefinition>
        Definitions =>
            definitions;

    // ==================================================
    // LOOKUP
    // ==================================================

    public CustomerOrderDefinition GetById(
        string definitionId)
    {
        if (string.IsNullOrWhiteSpace(
                definitionId))
        {
            return null;
        }

        EnsureLookup();

        if (definitionLookup.TryGetValue(
                definitionId,
                out CustomerOrderDefinition definition))
        {
            return definition;
        }

        return null;
    }

    public bool TryGetById(
        string definitionId,
        out CustomerOrderDefinition definition)
    {
        definition = null;

        if (string.IsNullOrWhiteSpace(
                definitionId))
        {
            return false;
        }

        EnsureLookup();

        return definitionLookup.TryGetValue(
            definitionId,
            out definition
        );
    }

    // ==================================================
    // LOOKUP BUILDING
    // ==================================================

    private void EnsureLookup()
    {
        if (definitionLookup != null)
            return;

        BuildLookup();
    }

    private void BuildLookup()
    {
        definitionLookup =
            new Dictionary<
                string,
                CustomerOrderDefinition>();

        if (definitions == null)
            return;

        foreach (
            CustomerOrderDefinition definition
            in definitions)
        {
            if (definition == null)
            {
                Debug.LogWarning(
                    $"CustomerOrderDatabase " +
                    $"({name}) contains an empty " +
                    $"definition reference."
                );

                continue;
            }

            string id =
                definition.DefinitionId;

            if (string.IsNullOrWhiteSpace(id))
            {
                Debug.LogError(
                    $"CustomerOrderDatabase ({name}): " +
                    $"{definition.name} has no " +
                    $"Definition ID."
                );

                continue;
            }

            if (definitionLookup.ContainsKey(id))
            {
                CustomerOrderDefinition existing =
                    definitionLookup[id];

                Debug.LogError(
                    $"CustomerOrderDatabase ({name}): " +
                    $"Duplicate Definition ID detected.\n" +
                    $"ID: {id}\n" +
                    $"First: {existing.name}\n" +
                    $"Duplicate: {definition.name}"
                );

                continue;
            }

            definitionLookup.Add(
                id,
                definition
            );
        }
    }

    // ==================================================
    // EDITOR VALIDATION
    // ==================================================

    private void OnValidate()
    {
        /*
         * Force the runtime lookup to rebuild after
         * the database is edited in the Inspector.
         */
        definitionLookup = null;

        ValidateDefinitions();
    }

    private void ValidateDefinitions()
    {
        if (definitions == null)
            return;

        HashSet<string> usedIds =
            new HashSet<string>();

        HashSet<CustomerOrderDefinition>
            usedDefinitions =
                new HashSet<CustomerOrderDefinition>();

        foreach (
            CustomerOrderDefinition definition
            in definitions)
        {
            if (definition == null)
                continue;

            /*
             * Detect the same asset being entered
             * more than once.
             */
            if (!usedDefinitions.Add(definition))
            {
                Debug.LogWarning(
                    $"CustomerOrderDatabase ({name}): " +
                    $"{definition.name} appears more " +
                    $"than once in the database."
                );
            }

            string id =
                definition.DefinitionId;

            if (string.IsNullOrWhiteSpace(id))
            {
                Debug.LogError(
                    $"CustomerOrderDatabase ({name}): " +
                    $"{definition.name} has no " +
                    $"Definition ID."
                );

                continue;
            }

            /*
             * Detect two different assets sharing
             * the same permanent ID.
             */
            if (!usedIds.Add(id))
            {
                Debug.LogError(
                    $"CustomerOrderDatabase ({name}): " +
                    $"Duplicate Definition ID detected: " +
                    $"{id}"
                );
            }
        }
    }

    // ==================================================
    // DEBUG
    // ==================================================

    [ContextMenu("Debug Validate Database")]
    private void DebugValidateDatabase()
    {
        definitionLookup = null;

        ValidateDefinitions();

        BuildLookup();

        Debug.Log(
            $"CUSTOMER ORDER DATABASE | " +
            $"Definitions: " +
            $"{definitionLookup.Count}"
        );
    }
}