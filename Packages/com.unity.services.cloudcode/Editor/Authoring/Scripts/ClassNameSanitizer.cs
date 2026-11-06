using System;
using System.Collections.Generic;
using System.Globalization;
using System.Text;

namespace Unity.Services.CloudCode.Authoring.Editor.Scripts
{
    /// <summary>
    /// Converts arbitrary text into a valid C# identifier suitable for use as a class name.
    /// Used by the Cloud Code module creation flow to derive class names from user-supplied input.
    /// </summary>
    static class ClassNameSanitizer
    {
        /// <summary>
        /// Sanitizes <paramref name="input"/> into a valid C# identifier.
        /// </summary>
        /// <remarks>
        /// The input is normalized to Unicode Normalization Form C and formatting characters
        /// (Unicode category <see cref="UnicodeCategory.Format"/>) are removed. Characters that are
        /// not valid identifier parts are stripped; if the first remaining character is valid only as
        /// an identifier part (not a start character), it is prefixed with an underscore. If the result
        /// matches a C# keyword, it is escaped with an <c>@</c> prefix.
        /// </remarks>
        /// <param name="input">The text to sanitize. May be null, empty, or whitespace.</param>
        /// <returns>
        /// A valid C# identifier. Returns <c>"_DefaultClass"</c> when <paramref name="input"/> is null,
        /// empty, whitespace, or reduces to no usable characters.
        /// </returns>
        public static string Sanitize(string input)
        {
            if (string.IsNullOrWhiteSpace(input))
            {
                return "_DefaultClass";
            }

            // Step 1: Normalize to Unicode Normalization Form C
            input = input.Normalize(NormalizationForm.FormC);

            // Step 2: Remove formatting characters (Unicode category Cf)
            var sb = new StringBuilder();
            foreach (var c in input)
            {
                if (char.GetUnicodeCategory(c) != UnicodeCategory.Format)
                {
                    sb.Append(c);
                }
            }

            var normalized = sb.ToString();
            if (string.IsNullOrEmpty(normalized))
            {
                return "_DefaultClass";
            }

            // Step 3: Build valid identifier
            sb.Clear();

            for (var i = 0; i < normalized.Length; i++)
            {
                var c = normalized[i];
                var category = char.GetUnicodeCategory(c);

                if (i == 0)
                {
                    // First character must be letter or underscore
                    if (IsIdentifierStartCharacter(c, category))
                    {
                        sb.Append(c);
                    }
                    else if (IsIdentifierPartCharacter(c, category))
                    {
                        // Valid part but not start - prefix with underscore
                        sb.Append('_');
                        sb.Append(c);
                    }
                    else
                    {
                        // Invalid character at start
                        sb.Append('_');
                    }
                }
                else
                {
                    // Subsequent characters
                    if (IsIdentifierPartCharacter(c, category))
                    {
                        sb.Append(c);
                    }
                    // Skip invalid characters
                }
            }

            var result = sb.ToString();

            // Ensure we have something
            if (string.IsNullOrEmpty(result) || result == "_")
            {
                result = "_DefaultClass";
            }

            // Step 4: Escape keywords with @ prefix
            if (IsKeyword(result))
            {
                result = "@" + result;
            }

            return result;
        }

        private static bool IsIdentifierStartCharacter(char c, UnicodeCategory category)
        {
            // Letter_Character: Category Letter (all subcategories) + category Number, subcategory LetterNumber
            // Plus underscore
            return c == '_' || IsLetterCharacter(c, category);
        }

        private static bool IsLetterCharacter(char c, UnicodeCategory category)
        {
            // \p{L} - All letters
            // \p{Nl} - Letter numbers
            return (category >= UnicodeCategory.UppercaseLetter &&
                category <= UnicodeCategory.OtherLetter) ||
                category == UnicodeCategory.LetterNumber;
        }

        private static bool IsIdentifierPartCharacter(char c, UnicodeCategory category)
        {
            return c == '_' ||
                IsLetterCharacter(c, category) ||
                category == UnicodeCategory.DecimalDigitNumber ||    // \p{Nd}
                category == UnicodeCategory.ConnectorPunctuation ||    // \p{Pc}
                category == UnicodeCategory.NonSpacingMark ||    // \p{Mn}
                category == UnicodeCategory.SpacingCombiningMark;    // \p{Mc}
        }

        private static bool IsKeyword(string identifier)
        {
            var keywords = new HashSet<string>(StringComparer.Ordinal)
            {
                "abstract",
                "as",
                "base",
                "bool",
                "break",
                "byte",
                "case",
                "catch",
                "char",
                "checked",
                "class",
                "const",
                "continue",
                "decimal",
                "default",
                "delegate",
                "do",
                "double",
                "else",
                "enum",
                "event",
                "explicit",
                "extern",
                "false",
                "finally",
                "fixed",
                "float",
                "for",
                "foreach",
                "goto",
                "if",
                "implicit",
                "in",
                "int",
                "interface",
                "internal",
                "is",
                "lock",
                "long",
                "namespace",
                "new",
                "null",
                "object",
                "operator",
                "out",
                "override",
                "params",
                "private",
                "protected",
                "public",
                "readonly",
                "ref",
                "return",
                "sbyte",
                "sealed",
                "short",
                "sizeof",
                "stackalloc",
                "static",
                "string",
                "struct",
                "switch",
                "this",
                "throw",
                "true",
                "try",
                "typeof",
                "uint",
                "ulong",
                "unchecked",
                "unsafe",
                "ushort",
                "using",
                "virtual",
                "void",
                "volatile",
                "while"
            };

            return keywords.Contains(identifier);
        }
    }
}
