# Guest QA Save Sandbox

The guest QA sandbox redirects all file-backed systems using `SavePathPolicy`
to a separate directory under the operating system's temporary directory. It
is opt-in, supported by the Windows Unity Editor, and is not included in Android
builds. If sandbox variables are present but invalid, save-path resolution
fails closed instead of selecting the normal save root.

## Enable a new sandbox

Close all Unity Editor and Unity Hub processes. In a dedicated PowerShell
window, create a fresh run ID, set process-scoped variables, and launch Unity
Hub or the Editor from that same window:

```powershell
$runId = [guid]::NewGuid().ToString()
$env:SWEETMAKER_GUEST_QA_SANDBOX = "1"
$env:SWEETMAKER_GUEST_QA_RUN_ID = $runId
Write-Host "Guest QA run ID: $runId"

$hub = Join-Path $env:ProgramFiles "Unity Hub\Unity Hub.exe"
if (-not (Test-Path $hub)) {
    throw "Unity Hub was not found at: $hub"
}
Start-Process -FilePath $hub
```

Alternatively, launch the Unity Editor directly from this PowerShell process:

```powershell
& "C:\Path\To\Unity\Editor\Unity.exe" -projectPath "C:\Path\To\SweetMaker"
```

The launched Hub or Editor inherits the sandbox variables. The derived path is:

```text
%TEMP%\SweetMaker-GuestQA\<run-id-without-hyphens>
```

The Editor acquires an exclusive Windows file-handle lock for the run ID before
validating or creating its sandbox. The lock is held by the operating system
across Unity scripting-domain reloads and is released when the Editor process
exits. A second Editor using the same run ID fails closed. Do not launch
multiple Editors with the same run ID.
The `.lock` file may remain after the Editor exits or crashes; it is not itself
proof that a session is active. The next Editor can reuse it only after it
successfully obtains the exclusive OS file handle. It is not deleted to recover
from a crash.

The application creates a run directory only when it does not already exist.
It writes `.sweetmaker-guestqa-owner-v1` with the marker version, run ID, and
expected sandbox identity. An existing directory is resumed only if that
marker exactly matches the configured run ID. Unexpected directories,
malformed configuration, invalid markers, and ambiguous ownership stop save
path resolution; they never fall back to DEV or RELEASE storage.

## Resume a sandbox

Close the sandbox-launched Editor. In a new dedicated PowerShell window, set
the same process-scoped variables using the run ID printed when the sandbox
was created, then launch Unity Hub or the Editor from that window. The same
GUID resumes that sandbox; a new GUID creates a separate sandbox.

## Disable sandbox mode

Close the sandbox-launched Editor and Unity Hub. Open Unity Hub normally, or
launch the Editor from a PowerShell process in which neither sandbox variable
is set. Process-scoped variables disappear when their PowerShell process exits;
no persistent User environment variables need to be removed. The normal Editor
save root is then `SweetMaker-Development`. Disabling the sandbox does not
delete its files.

## Isolation limits

This mechanism isolates files routed through `SavePathPolicy`, including
Save V2, tutorial progress, Cafe Naming, and settings. It does not isolate
`PlayerPrefs`, Unity/package-managed caches, or other persistence that does
not use `SavePathPolicy`. Avoid changing advertising privacy preferences or
using rewarded-ad flows during guest QA.
