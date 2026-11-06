using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;

namespace Unity.Services.CloudCode.Authoring.Editor.Scripts
{
    /// <summary>
    /// Sanitizes an arbitrary string into a valid C# namespace name. A namespace is a
    /// '.'-separated sequence of identifiers, so each dot-delimited segment is sanitized
    /// independently into a valid identifier and the segments are rejoined with '.'.
    /// </summary>
    static class NamespaceSanitizer
    {
        const string DefaultNamespace = "_DefaultNamespace";
        const string DefaultSegment = "_";

        public static string Sanitize(string input)
        {
            if (string.IsNullOrWhiteSpace(input))
            {
                return DefaultNamespace;
            }

            var segments = input
                .Split(new[] { '.' }, StringSplitOptions.RemoveEmptyEntries)
                .Where(s => !string.IsNullOrWhiteSpace(s))
                .Select(SanitizeSegment)
                .ToArray();

            return segments.Length == 0 ? DefaultNamespace : string.Join(".", segments);
        }

        static string SanitizeSegment(string segment)
        {
            // Firstly, Normalize to Unicode Normalization Form C
            segment = segment.Normalize(NormalizationForm.FormC);

            var sb = new StringBuilder();
            foreach (var c in segment)
            {
                // Drop cf characters so we fully normalize. Ex: foo\u200Dbar -> foobar.
                if (char.GetUnicodeCategory(c) != UnicodeCategory.Format)
                {
                    sb.Append(c);
                }
            }

            var normalized = sb.ToString();
            if (string.IsNullOrEmpty(normalized))
            {
                return DefaultSegment;
            }

            // Next we start addressing grammar legality. Here are some examples:
            // Illegal         -> Legal
            // 9lives          -> _9lives
            // My Namespaces   -> MyNamespace
            // Foo-Bar         -> FooBar
            // Foo+Bar         -> FooBar

            // Build a valid identifier from the segment.
            sb.Clear();
            for (var i = 0; i < normalized.Length; i++)
            {
                var c = normalized[i];
                var category = char.GetUnicodeCategory(c);

                if (i == 0)
                {
                    if (IsIdentifierStartCharacter(c, category))
                    {
                        sb.Append(c);
                    }
                    else if (IsIdentifierPartCharacter(c, category))
                    {
                        // Valid part but not a valid start - prefix with underscore.
                        sb.Append('_');
                        sb.Append(c);
                    }
                    else
                    {
                        sb.Append('_');
                    }
                }
                else if (IsIdentifierPartCharacter(c, category))
                {
                    sb.Append(c);
                }
                // Subsequent invalid characters are skipped.
            }

            var result = sb.ToString();
            if (string.IsNullOrEmpty(result) || result == "_")
            {
                return DefaultSegment;
            }

            // Escape reserved keywords with a verbatim '@' prefix.
            return IsReservedKeyword(result) ? "@" + result : result;
        }

        static bool IsIdentifierStartCharacter(char c, UnicodeCategory category)
        {
            return c == '_' || IsLetterCharacter(c, category);
        }

        static bool IsLetterCharacter(char c, UnicodeCategory category)
        {
            return (category >= UnicodeCategory.UppercaseLetter &&
                category <= UnicodeCategory.OtherLetter) ||
                category == UnicodeCategory.LetterNumber;
        }

        static bool IsIdentifierPartCharacter(char c, UnicodeCategory category)
        {
            return c == '_' ||
                IsLetterCharacter(c, category) ||
                category == UnicodeCategory.DecimalDigitNumber ||
                category == UnicodeCategory.ConnectorPunctuation ||
                category == UnicodeCategory.NonSpacingMark ||
                category == UnicodeCategory.SpacingCombiningMark;
        }

        static bool IsReservedKeyword(string identifier)
        {
            return ReservedKeywords.Contains(identifier);
        }

        static readonly HashSet<string> ReservedKeywords = new(StringComparer.Ordinal)
        {
            "abstract", "as", "base", "bool", "break", "byte", "case", "catch", "char",
            "checked", "class", "const", "continue", "decimal", "default", "delegate", "do",
            "double", "else", "enum", "event", "explicit", "extern", "false", "finally",
            "fixed", "float", "for", "foreach", "goto", "if", "implicit", "in", "int",
            "interface", "internal", "is", "lock", "long", "namespace", "new", "null",
            "object", "operator", "out", "override", "params", "private", "protected",
            "public", "readonly", "ref", "return", "sbyte", "sealed", "short", "sizeof",
            "stackalloc", "static", "string", "struct", "switch", "this", "throw", "true",
            "try", "typeof", "uint", "ulong", "unchecked", "unsafe", "ushort", "using",
            "virtual", "void", "volatile", "while"
        };
    }
}
