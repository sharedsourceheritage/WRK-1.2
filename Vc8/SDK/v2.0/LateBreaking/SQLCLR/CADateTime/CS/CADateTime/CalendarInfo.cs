/*=====================================================================

  File:      CalendarInfo.cs for calendar aware data time Sample
  Summary:   Defines a utility class which contains static information 
             useful for representing, persisting, and manipulating calendar
             aware dates and times.
  Date:	     August 4, 2004

---------------------------------------------------------------------
  This file is part of the Microsoft SQL Server Code Samples.
  Copyright (C) Microsoft Corporation.  All rights reserved.

  This source code is intended only as a supplement to Microsoft
  Development Tools and/or on-line documentation.  See these other
  materials for detailed information regarding Microsoft code samples.

  THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
  PARTICULAR PURPOSE.
======================================================= */

using System;
using System.Data.Sql;
using System.Data.SqlTypes;
using System.Globalization;
using System.Resources;
using System.Reflection;
using System.Text;

namespace Microsoft.Samples.SqlServer
{
    public static class CalendarInfo
    {
        /// <summary>
        /// Initialize the calendar array, one for each possible calendar
        /// </summary>
        static CalendarInfo()
        {
            stringFormatChars = new char[] { 't' };

            ResourceManager rm = new ResourceManager("calendars", Assembly.GetExecutingAssembly());

            int numCalendars = int.Parse(rm.GetString("NumCalendars"), CultureInfo.CurrentUICulture);
            if (numCalendars > MaxCalendarId)
                throw new ArgumentOutOfRangeException("Does not support more than 255 calendars");

            calendars = new Calendar[numCalendars];
            for (int i = 0; i < numCalendars; i++)
            {
                string typeName = rm.GetString(i.ToString(CultureInfo.CurrentUICulture));
                calendars[i] = (Calendar)Activator.CreateInstance(Type.GetType(typeName, true));
            }

            defaultCalendarId = int.Parse(rm.GetString("DefaultCalendarID"), CultureInfo.CurrentUICulture);
            defaultCalendar = calendars[defaultCalendarId];
        }

        private static readonly Calendar defaultCalendar; // = new GregorianCalendar();
        public static Calendar DefaultCalendar
        {
            get
            {
                return CalendarInfo.defaultCalendar;
            }
        }

        private static readonly int defaultCalendarId;
        public static int DefaultCalendarId
        {
            get
            {
                return CalendarInfo.defaultCalendarId;
            }
        }

        private static readonly Calendar[] calendars;
        public static Calendar[] Calendars
        {
            get
            {
                return CalendarInfo.calendars;
            }
        }

        public const byte MaxCalendarId = 0xff;

        public static int GetCalendarId(string calendarName)
        {
            for (int i = 0; i < calendars.Length; i++)
            {
                if (calendars[i].GetType().Name == calendarName)
                    return i;
            }

            throw new ArgumentException("Unknown calendar: " + calendarName);
        }

        private readonly static char[] stringFormatChars; // = new char[] { 't' };

        // Returns a string suitable for use with string.Format which displays
        // either date or datetime components in a culture appropriate way.
        public static string SubstitutePositionForCharacters(Char[] characters, string pattern)
        {
            StringBuilder sb = new StringBuilder();
            char lastChar = ' ';
            for (int i = 0; i < pattern.Length; i++)
            {
                char c = pattern[i];
                int position = Array.IndexOf<char>(characters, c);
                if (position != -1)
                {
                    if (lastChar != c)
                    {
                        sb.Append('{');
                        sb.Append(position);
                        //If this isn't a string format char, it is a numeric format char.
                        //In that case we need to get the correct number of digits from
                        //the pattern.
                        if (Array.IndexOf<char>(stringFormatChars, c) == -1)
                        {
                            //Decimal number with the appropriate minimum number of digits
                            sb.AppendFormat(":d{0:d}", CountRun(c, pattern, i));
                        }
                        sb.Append('}');
                    }
                }
                else
                {
                    sb.Append(c);
                }

                lastChar = c;
            }

            return sb.ToString();
        }

        //Given that you have found character c in a pattern, count how many instances of that
        //character occur at that position before another character or the end of the string is reached.
        public static int CountRun(char chr, string pattern, int start)
        {
            int result = 1;
            for (int i = start + 1; i < pattern.Length; i++)
            {
                if (pattern[i] == chr)
                    result += 1;
                else
                    break;
            }

            return result;
        }
    }
}
