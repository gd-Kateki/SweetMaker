using System;

// Owns supplied bytes only; construction does not validate their contents
// or grant authority to publish, commit, or persist them.
internal sealed class PreparedSaveSnapshot
{
    private readonly byte[] bytes;

    public long ByteLength => bytes.LongLength;

    public PreparedSaveSnapshot(byte[] bytes)
    {
        if (bytes == null)
            throw new ArgumentNullException(nameof(bytes));

        this.bytes = (byte[])bytes.Clone();
    }

    public byte[] GetBytesCopy()
    {
        return (byte[])bytes.Clone();
    }
}
