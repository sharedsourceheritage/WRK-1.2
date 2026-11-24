//------------------------------------------------------------------------------
// <copyright from='2003' to='2004' company='Microsoft Corporation'>           
//  Copyright (c) Microsoft Corporation, All rights reserved.             
//  This code sample is provided "AS IS" without warranty of any kind, 
//  it is not recommended for use in a production environment.
// </copyright>                                                                
//------------------------------------------------------------------------------

using System;

namespace PackageWizard
{
    /// <summary>
    /// Helper class to handle the the constant strings in the supported languages.
    /// The main goal of this class is to escape the strings in such a way that the
    /// compiler will not complain at compiler time
    /// </summary>
    internal sealed class StringProcessor
    {
        private StringProcessor()
        {
            // The constructor is empty: this class exposes only static members.
            // As more the constructor is private so no instance of the class can be
            // created.
        }

        /// <summary>
        /// Enumeration of the languages known by the string processor
        /// </summary>
        public enum LanguageType
        {
            LanguageCpp,        // C++
            LanguageCs,         // C#
            LanguageResource,   // A resource file
            LanguageProject,    // A project file
            LanguageUnknown     // Anything else
        }

        /// <summary>
        /// Returns the language that is expected inside a file of the give extension
        /// </summary>
        /// <param name="Extension">The extension of the file</param>
        /// <returns></returns>
        public static LanguageType GetLanguageFromExtension(string Extension)
        {
            string ext = Extension.ToLower();
            if ( ext.Length == 0 )
            {
                return LanguageType.LanguageUnknown;
            }
            if ( ext[0] == '.' )
            {
                ext = ext.Substring(1, ext.Length-1);
            }

            if ( ext=="cs" )
            {
                return LanguageType.LanguageCs;
            }
            if ( (ext=="cpp") || (ext=="h") || (ext=="inl") )
            {
                return LanguageType.LanguageCpp;
            }
            if ( (ext=="rc") || (ext=="ctc") )
            {
                return LanguageType.LanguageResource;
            }
            if ( (ext=="vcproj") || (ext=="csproj") )
            {
                return LanguageType.LanguageProject;
            }
            
            return LanguageType.LanguageUnknown;
        }

        /// <summary>
        /// Returns a string with the special characters escaped
        /// </summary>
        /// <param name="InString">String to escape</param>
        /// <param name="LangType">Language to use to find out the special chars and the escape sequences</param>
        /// <returns></returns>
        public static string EscapeString(string InString, LanguageType LangType)
        {
            string escaped = InString;

            switch ( LangType )
            {
                case LanguageType.LanguageCpp:
                    escaped = escaped.Replace("\\", "\\\\");
                    escaped = escaped.Replace("\"", "\\\"");
                    escaped = escaped.Replace("\n", "\\n");
                    escaped = escaped.Replace("\r", "\\r");
                    break;

                case LanguageType.LanguageCs:
                    escaped = escaped.Replace("\\", "\\\\");
                    escaped = escaped.Replace("\"", "\\\"");
                    escaped = escaped.Replace("\n", "\\n");
                    escaped = escaped.Replace("\r", "\\r");
                    break;

                case LanguageType.LanguageResource:
                    escaped = escaped.Replace("\\", "\\\\");
                    escaped = escaped.Replace("\"", "\"\"");
                    escaped = escaped.Replace("\n", "\\n");
                    escaped = escaped.Replace("\r", "\\r");
                    break;

                case LanguageType.LanguageProject:
                    escaped = escaped.Replace("\"", "&quot;");
                    escaped = escaped.Replace("\n", "&#x0A;");
                    escaped = escaped.Replace("\r", "&#x0D;");
                    break;

                case LanguageType.LanguageUnknown:
                default:
                    // If the file type is unknown, don't change enything in the token string
                    break;
            }

            return escaped;
        }

    }
}
