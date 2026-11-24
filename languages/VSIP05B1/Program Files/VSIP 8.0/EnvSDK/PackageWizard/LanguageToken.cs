//------------------------------------------------------------------------------
// <copyright from='2003' to='2004' company='Microsoft Corporation'>           
//  Copyright (c) Microsoft Corporation, All rights reserved.             
//  This code sample is provided "AS IS" without warranty of any kind, 
//  it is not recommended for use in a production environment.
// </copyright>                                                                
//------------------------------------------------------------------------------

using System;
using System.Globalization;

namespace PackageWizard
{
    /// <summary>
    /// This class is a token in the language definition.
    /// Its goal is to generate a cpp declaration of the TokenInfo structure
    /// </summary>
    public class LanguageToken
    {
        // The following class is used only to store the informations about the triggers
        private class TriggerInfo
        {
            public bool isSelected;
            public string triggerName;

            public TriggerInfo(string Name)
            {
                triggerName = Name;
                isSelected = false;
            }
        }

        private string m_strName;
        private string m_strDesc;
        private string m_strColorClass;
        private string m_strCharClass;
        private System.Collections.Hashtable hashTriggers;

        private const string m_strDefaultDescription = "";

        // This static array stores the color classes defined for the language.
        // It is initialized with the default color classes.
        static public string [] rgColorClasses = 
        {
            "ClassDefault",
            "ClassText",
            "ClassKeyword",
            "ClassComment",
            "ClassIdentifier",
            "ClassString",
            "ClassNumber"
        };

        // Definition of the char classes. 
        // This array is initialized with the defaults as defined in babelservice.h
        static public string [] rgCharClasses =
        {
            "CharDefault",
            "CharText",
            "CharKeyword",
            "CharIdentifier",
            "CharString",
            "CharLiteral",
            "CharOperator",
            "CharDelimiter",
            "CharEmbedded",
            "CharWhiteSpace",
            "CharLineComment",
            "CharComment"
        };

        static public string [] rgTriggerNames =
        {
            "TriggerMatchBraces",
            "TriggerParamStart",
            "TriggerParamNext",
            "TriggerParamEnd",
            "TriggerMemberSelect"
        };

        // This function validates a color class agains the static array of color classes.
        // If the color class is not found in the array an exception is thow, otherwise
        // the function will return the color class name with the right case.
        private static string ValidateColorClass(string ColorClass)
        {
            foreach (string s in rgColorClasses)
            {
                if (string.Compare(s, ColorClass, true, CultureInfo.CurrentCulture)==0)
                {
                    // The class is in the array. Return s because it has the right case
                    return s;
                }
            }

            // If we are here the class is not in the array, so throw an exception
            throw new Exception("Color class " + ColorClass + " is unknown");
        }

        private void Initialize(string strName, string strDesc, string strColorClass)
        {
            m_strName = strName;
            m_strDesc = strDesc;
            m_strColorClass = strColorClass;
            m_strCharClass = rgCharClasses[0];

            // Add the known triggers
            hashTriggers = new System.Collections.Hashtable();
            foreach (string t in rgTriggerNames)
            {
                hashTriggers.Add(t, new TriggerInfo(t) );
            }
        }

        public LanguageToken(string Name)
        {
            Initialize (Name, m_strDefaultDescription, rgColorClasses[0]);
        }

        // This class can be constructed only providing name and description.
        public LanguageToken(string Name, string Description, string ColorClass)
        {
            Initialize(Name, Description, ValidateColorClass(ColorClass));
        }

        public override string ToString()
        {
            return m_strName;
        }

        public string Name
        {
            get
            {
                return m_strName;
            }
            set
            {
                m_strName = value;
            }
        }

        public string Description
        {
            get
            {
                return m_strDesc;
            }
            set
            {
                m_strDesc = value;
            }
        }

        public string ColorClass
        {
            get 
            {
                return m_strColorClass;
            }
            set
            {
                m_strColorClass = ValidateColorClass(value);
            }
        }

        public string CharClass
        {
            get
            {
                return m_strCharClass;
            }
            set
            {
                m_strCharClass = value;
            }
        }

        public bool IsTriggerEnabled(string triggerName)
        {
            if ( !hashTriggers.Contains(triggerName) )
            {
                return false;
            }
            TriggerInfo trigger = (TriggerInfo)hashTriggers[triggerName];
            return trigger.isSelected;
        }

        public void SetTriggerStatus(string triggerName, bool isEnabled)
        {
            if ( !hashTriggers.Contains(triggerName) )
            {
                return;
            }
            TriggerInfo trigger = (TriggerInfo)hashTriggers[triggerName];
            trigger.isSelected = isEnabled;
        }

        // This is the property that will build the string that is the cpp declaration
        // of the TokenInfo structure that describes this token.
        public string TokenInfoDefinition
        {
            get
            {
                // Find the triggers to add to the definition
                string strTriggers = "";
                System.Collections.IDictionaryEnumerator triggers = 
                        (System.Collections.IDictionaryEnumerator)hashTriggers.GetEnumerator();
                while ( triggers.MoveNext() )
                {
                    TriggerInfo t = (TriggerInfo)triggers.Value;
                    if (t.isSelected )
                    {
                        if ( strTriggers.Length > 0 )
                        {
                            strTriggers += " | ";
                        }
                        strTriggers += t.triggerName;
                    }
                }

                string strCpp = "{ " + m_strName;
                strCpp += ", " + m_strColorClass;
                strCpp += ", \"" + StringProcessor.EscapeString(m_strDesc, StringProcessor.LanguageType.LanguageCpp) + "\"";
                strCpp += ", " + m_strCharClass;
                if ( strTriggers.Length > 0 )
                {
                    strCpp += ", " + strTriggers;
                }
                strCpp += " }";

                return strCpp;
            }
        }
    }
}
