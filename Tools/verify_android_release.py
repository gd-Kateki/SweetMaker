"""Inspect the built bundle before handing it to Google Play internal testing."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import xml.etree.ElementTree as ET
import zipfile


def run(args):
    result = subprocess.run([str(arg) for arg in args], capture_output=True, text=True)
    if result.returncode:
        raise RuntimeError(result.stderr or result.stdout)
    return result.stdout


def verify(bundle, java_root, bundletool, version_code):
    expected_hash = "a099cfa1543f55593bc2ed16a70a7c67fe54b1747bb7301f37fdfd6d91028e29"
    if hashlib.sha256(bundletool.read_bytes()).hexdigest() != expected_hash:
        raise ValueError("Unexpected bundletool binary; expected the project's pinned 1.18.3 tool.")
    java = java_root / "bin/java.exe"
    run([java, "-jar", bundletool, "validate", "--bundle=" + str(bundle)])
    manifest = ET.fromstring(run([java, "-jar", bundletool, "dump", "manifest", "--bundle=" + str(bundle), "--module=base"]))
    android = "{http://schemas.android.com/apk/res/android}"
    if manifest.get("package") != "com.offcutstudios.dessertmergecafe":
        raise ValueError("Incorrect release package ID")
    if int(manifest.get(android + "versionCode")) != version_code:
        raise ValueError("Unexpected release version code")
    app = manifest.find("application")
    if app is None or app.get(android + "debuggable", "false") != "false":
        raise ValueError("Release is debuggable or has no application manifest")
    sdk = manifest.find("uses-sdk")
    if sdk is None or int(sdk.get(android + "targetSdkVersion")) != 36:
        raise ValueError("Expected target SDK 36")
    config = json.loads(run([java, "-jar", bundletool, "dump", "config", "--bundle=" + str(bundle)]))
    alignment = config.get("optimizations", {}).get("uncompressNativeLibraries", {}).get("alignment")
    if alignment != "PAGE_ALIGNMENT_16K":
        raise ValueError("Bundle does not declare 16 KB native-library ZIP alignment")
    signature = run([java_root / "bin/jarsigner.exe", "-J-Duser.language=en", "-verify", bundle])
    if "jar verified." not in signature:
        raise ValueError("Bundle signature was not verified")
    native_libraries = []
    with zipfile.ZipFile(bundle) as archive:
        for name in archive.namelist():
            if "/lib/" not in name or not name.endswith(".so"):
                continue
            if "/arm64-v8a/" not in name:
                raise ValueError("Unexpected architecture: " + name)
            blob = archive.read(name)
            if blob[:6] != b"\x7fELF\x02\x01":
                raise ValueError("Not a little-endian ELF64 library: " + name)
            offset = struct.unpack_from("<Q", blob, 32)[0]
            entry_size, count = struct.unpack_from("<HH", blob, 54)
            for index in range(count):
                header = offset + index * entry_size
                if struct.unpack_from("<I", blob, header)[0] != 1:
                    continue
                file_offset, virtual_address = struct.unpack_from("<QQ", blob, header + 8)
                segment_alignment = struct.unpack_from("<Q", blob, header + 48)[0]
                if segment_alignment < 16384 or (virtual_address - file_offset) % 16384:
                    raise ValueError("Native library lacks 16 KB LOAD alignment: " + name)
            native_libraries.append(name)
    if not native_libraries:
        raise ValueError("No ARM64 native libraries found")
    return {"bundle": str(bundle), "package": manifest.get("package"),
            "version": manifest.get(android + "versionName"), "versionCode": version_code,
            "targetSdk": 36, "debuggable": False, "signatureVerified": True,
            "nativeLibraries16K": native_libraries,
            "sha256": hashlib.sha256(bundle.read_bytes()).hexdigest()}


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("bundle", type=Path)
    parser.add_argument("--java-root", type=Path, required=True)
    parser.add_argument("--bundletool", type=Path, required=True)
    parser.add_argument("--version-code", type=int, required=True)
    args = parser.parse_args()
    result = verify(args.bundle.resolve(), args.java_root, args.bundletool, args.version_code)
    output = args.bundle.with_suffix(".verification.json")
    output.write_text(json.dumps(result, indent=2), encoding="utf-8")
    print(json.dumps(result, indent=2))
