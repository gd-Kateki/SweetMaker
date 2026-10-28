using System;
using System.IO;
using System.Security;

public sealed class ReadOnlySaveDiscovery
{
    private readonly SaveManager saveManager;

    public ReadOnlySaveDiscovery(SaveManager saveManager)
    {
        this.saveManager = saveManager ??
            throw new ArgumentNullException(nameof(saveManager));
    }

    public SaveDiscoveryResult Inspect()
    {
        string primaryPath = saveManager.SaveFilePath;
        return new SaveDiscoveryResult(
            InspectFile(primaryPath),
            InspectFile(primaryPath + ".bak"));
    }

    private SaveFileInspection InspectFile(string path)
    {
        byte[] bytes;
        try
        {
            bytes = File.ReadAllBytes(path);
        }
        catch (FileNotFoundException)
        {
            return CreateInspection(
                path,
                SaveDiscoveryStatus.Missing,
                "The save file does not exist.");
        }
        catch (DirectoryNotFoundException)
        {
            return CreateInspection(
                path,
                SaveDiscoveryStatus.Missing,
                "The save directory does not exist.");
        }
        catch (UnauthorizedAccessException exception)
        {
            return CreateInspection(
                path,
                SaveDiscoveryStatus.Unreadable,
                exception.Message);
        }
        catch (SecurityException exception)
        {
            return CreateInspection(
                path,
                SaveDiscoveryStatus.Unreadable,
                exception.Message);
        }
        catch (IOException exception)
        {
            return CreateInspection(
                path,
                SaveDiscoveryStatus.Unreadable,
                exception.Message);
        }
        catch (ArgumentException exception)
        {
            return CreateInspection(
                path,
                SaveDiscoveryStatus.Unknown,
                exception.Message);
        }
        catch (NotSupportedException exception)
        {
            return CreateInspection(
                path,
                SaveDiscoveryStatus.Unknown,
                exception.Message);
        }

        SaveDiscoveryStatus status =
            saveManager.InspectSaveBytesForDiscovery(
                bytes,
                out SaveDiscoveryVersionKind versionKind,
                out int version);

        int? saveVersion =
            versionKind == SaveDiscoveryVersionKind.Unknown ||
            versionKind == SaveDiscoveryVersionKind.Ambiguous
                ? (int?)null
                : version;

        return new SaveFileInspection(
            path,
            status,
            versionKind,
            saveVersion,
            bytes,
            null);
    }

    private static SaveFileInspection CreateInspection(
        string path,
        SaveDiscoveryStatus status,
        string failureReason)
    {
        return new SaveFileInspection(
            path,
            status,
            SaveDiscoveryVersionKind.Unknown,
            null,
            null,
            failureReason);
    }
}
