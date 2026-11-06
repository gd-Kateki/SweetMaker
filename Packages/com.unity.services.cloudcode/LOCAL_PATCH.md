# Local Unity 6 compatibility patch

Upstream package: Unity Cloud Code 2.10.4. Embedded on 6 November 2026.

`Editor/Authoring/Scripts/JsAssetHandler.cs` uses an EntityId OnOpenAsset
callback for UNITY_6000_4_OR_NEWER and resolves the actual supplied ID.
The previous implementation declared an int callback and resolved an empty
EntityId, causing Unity 6.6 asset-open validation errors (including opening scenes).
Older Unity versions retain the int callback. Runtime Cloud Code is unchanged.

The package is embedded so the fix is version-controlled and survives Library
regeneration. Unity prefers this package over the manifest registry entry.
When upgrading, check whether upstream fixes both issues before removing this
embedded copy. Keep the upstream license and metadata.

Regression coverage: CloudCodeAssetCallbackTests in the project's Editor tests.
