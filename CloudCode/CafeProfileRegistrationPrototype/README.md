# Cafe Profile Registration Prototype

This isolated Cloud Code C# module is not referenced by Unity gameplay and is
intended for Development-only testing. It treats a pre-provisioned Private
Game Data Custom Item as the authoritative registration ledger. Protected
Player Data is intentionally not written by this prototype.

## Deployment checklist

| Setting | Value |
|---|---|
| Module/project name | `CafeProfileRegistrationPrototype` |
| Exported function | `RegisterCafeNamePrototype` |
| Cloud Code language | C# module |
| Target environment | `development` only |
| Game Data access class | Private Game Data |
| Custom Item ID | `cafe-registration-ledger-prototype` |
| Ledger key | `registrations` |
| Ledger version | `1` |
| Name limit | 1-20 characters after trimming |

Before deployment:

1. Confirm the Unity Dashboard project is the Dessert Merge Cafe project.
2. Select the `development` environment in the Dashboard environment
   selector. Do not select `production`.
3. Confirm the source contains no production project ID, environment name,
   service credential, or player ID parameter.
4. Confirm the test account is authenticated for Development.

The source passes `context.ProjectId` to the Game Data API. It does not
hard-code a project or environment, so deploying the same source to the wrong
Dashboard environment would target that environment. Environment selection is
therefore an operational deployment gate, not a code-level guard.

## Dependencies

The project references:

- `Com.Unity.Services.CloudCode.Apis` `0.0.27`
- `Com.Unity.Services.CloudCode.Core` `0.0.7`
- `Newtonsoft.Json` `13.0.3`

The module registers `IGameApiClient` with
`ICloudCodeConfig.AddGameApiClient()`.

## Unity Dashboard ledger provisioning

Dashboard labels can vary slightly by UGS Dashboard revision. In the
development environment:

1. Open **Cloud Save** for the project and select **Game Data**.
2. Select the **Private** access class.
3. Open **Custom Items** and choose **Create Custom Item**.
4. Set the Custom Item ID to `cafe-registration-ledger-prototype`.
5. Add one item with key `registrations`.
6. Enter this JSON value exactly:

   ```json
   {"version":1,"entries":{}}
   ```

7. Save/create the item.
8. Reopen it and verify that a nonempty write lock is visible. Do not edit
   the item after reading the lock; an edit invalidates the old lock.

Do not create the item under Public, Protected, or Player Data. The module
rejects a missing, empty, malformed, or lockless ledger and never creates it.

## Deploying to UGS Development

Use the Cloud Code **Modules** page for the same project and keep the
environment selector set to `development`:

1. Choose **Create module** or **Deploy module** for an existing module.
2. Set the module name to `CafeProfileRegistrationPrototype`.
3. Select **C#** and upload/select the compiled module package from this
   directory.
4. Confirm the module dependencies listed above are included/resolvable.
5. Deploy and wait for the module status to become ready.
6. Open the function list and verify `RegisterCafeNamePrototype` is exported.
7. Invoke only from a Development-authenticated test client or Development
   function tester with an authenticated player context.

Do not deploy from or switch to Production. Do not reuse a Production test
account or production ledger. Re-check the Dashboard environment selector
before every function invocation.

## Function behavior

`RegisterCafeNamePrototype`:

1. Uses `IExecutionContext.PlayerId`; no client player ID is accepted.
2. Trims and validates the name to 1-20 characters.
3. Reads the existing ledger and its write lock with the Cloud Code service
   token.
4. Returns `AlreadyRegistered` for an existing player entry.
5. Updates the ledger with `SetItemBody(key, value, writeLock)`.
6. Retries only HTTP 409 write-lock conflicts, rereading on each attempt.
7. Returns `UnknownWriteOutcome` for non-conflict write failures and never
   claims registration success after an uncertain write.

The ledger is authoritative. Projection repair into Protected Player Data is
deliberately out of scope for this prototype.

## Isolated test plan

Record the initial ledger JSON and write lock from the Development Dashboard
before each independent scenario. Use a fresh authenticated player identity or
reset the Development ledger only between scenarios.

### Concurrent first registration

1. Authenticate the same Unity player on two Development clients/devices.
2. Submit calls as close together as possible with different names, such as
   `Cafe Alpha` and `Cafe Beta`.
3. Expect exactly one committed name: one call returns `Registered`; the
   other either retries to `AlreadyRegistered` with that name or returns
   `Conflict` after its bounded retry budget.
4. The losing request must never return `Registered`.
5. Inspect the ledger and verify exactly one entry exists for that player.
6. Retry both calls and confirm the committed name never changes.

### Duplicate-name scenarios

- Two different players submitting the same name are expected to register
  independently. This prototype does **not** enforce global name uniqueness.
- The same player submitting the same name again must receive
  `AlreadyRegistered`.
- The same player submitting a different name must receive
  `AlreadyRegistered` with the original name.

### Validation and ledger-state scenarios

- Blank or whitespace-only name: `InvalidName`.
- More than 20 characters after trimming: `InvalidName`.
- Missing Custom Item, wrong access class, wrong key, malformed JSON, invalid
  version, or empty write lock: `LedgerInvalid`.

### Timeout and retry scenarios

1. Invoke registration while interrupting the client connection or allowing
   the caller timeout to expire.
2. Treat the result as uncertain unless the function explicitly returns a
   known outcome. Non-conflict write failures return `UnknownWriteOutcome`.
3. Reconnect and invoke again with the same player.
4. Inspect the ledger first. If the name committed, the retry must return
   `AlreadyRegistered`; otherwise a new attempt may return `Registered`.
5. Do not manually edit the ledger during a live request. Use concurrent calls
   so the service supplies the real write-lock conflict.

The bounded CAS policy is four attempts with delays of 50 ms, 100 ms, and
150 ms between conflict retries. A final unresolved conflict returns
`Conflict`.

## Inspecting the authoritative ledger

After each scenario, in the **development** Cloud Save Game Data view:

1. Open **Private** access class and custom item
   `cafe-registration-ledger-prototype`.
2. Read key `registrations`.
3. Verify the JSON has `version` 1 and inspect `entries`.
4. Confirm the expected player has at most one entry and its value never
   changes after first registration.
5. Note the new write lock after a successful update; never use a stale lock
   for a later manual edit.

Do not use Protected Player Data to judge success. This prototype does not
write a projection there.

## Remaining blockers

- Dashboard access, project permissions, and the current Dashboard upload
  workflow must be confirmed by the operator.
- The module has not been deployed or remotely tested in this task.
- Concurrent behavior, timeout outcomes, and the actual Game Data conflict
  response require Development environment testing.
- The prototype does not enforce globally unique cafe names.
- Production deployment and any Protected Player Data projection remain out
  of scope.

## Local validation status

The isolated project restores and compiles locally with zero warnings and zero
errors. In the installed Cloud Code APIs package, `ApiException` exposes the
HTTP status through `ApiException.Response.StatusCode`; the prototype treats
`HttpStatusCode.Conflict` as a write-lock conflict.
