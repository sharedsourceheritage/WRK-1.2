using System;
using System.Data.Sql;
using System.Data.SqlTypes;
using System.Globalization;
using System.Resources;
using System.Text;
using System.Reflection;
using System.Collections.Generic;
using System.Xml;
using System.Xml.Serialization;
using System.Xml.Schema;
using System.IO;

/*=====================================================================

  File:      calendarawaredate.cs for calendar aware data time Sample
  Summary:   Defines a CLR user defined time which represents dates  for 
             various calendar systems.
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

namespace Microsoft.Samples.SqlServer
{
    /// <summary>
    /// A date value in the specified calendar system.
    /// </summary>
    [Serializable]
    [Microsoft.SqlServer.Server.SqlUserDefinedType(Microsoft.SqlServer.Server.Format.Native, IsByteOrdered = true)]
    public struct CADate : INullable, IXmlSerializable
    {
        #region nullability
        // This type uses days == 0 as the way to designate a NULL value

        private const uint nullDay = 0;

        /// <summary>
        /// return the null value for this type
        /// </summary>
        /// <value></value>
        public static CADate Null
        {
            get
            {
                CADate caDate = new CADate();
                caDate.days = nullDay;
                return caDate;
            }
        }

        /// <summary>
        /// is this value null
        /// </summary>
        /// <value></value>
        public bool IsNull
        {
            get
            {
                return this.days == nullDay;
            }
        }
        #endregion

        #region string conversion
        /// <summary>
        /// parse the given string and return a calendar aware date.
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        [Microsoft.SqlServer.Server.SqlMethod(DataAccess = Microsoft.SqlServer.Server.DataAccessKind.None, IsDeterministic = false, IsMutator = false, IsPrecise = false,
        SystemDataAccess = Microsoft.SqlServer.Server.SystemDataAccessKind.None)]
        public static CADate Parse(SqlString sqlString)
        {
            if (sqlString.IsNull)
                return Null;

            return new CADate(DateTime.Parse(sqlString.Value, DateTimeFormatInfo.CurrentInfo));
        }

        /// <summary>
        /// convert the date to string
        /// </summary>
        /// <returns></returns>
        public override string ToString()
        {
            if (this.IsNull)
                return null;

            return string.Format(CultureInfo.CurrentUICulture,
                DayMonthYearFormatString(),
                this.DayOfMonth, this.Month, this.Year);
        }

        /// <summary>
        /// Return a string representation of this date, in the Gregorian calendar_id
        /// </summary>
        /// <returns></returns>
        public string ToGregorianString()
        {
            if (this.IsNull)
                return null;

            return this.DateTime.ToString("d", DateTimeFormatInfo.CurrentInfo);
        }

        /// <summary>
        /// Construct a CADate from the specified format, using the current culture
        /// </summary>
        /// <param name="data">the string to be parsed</param>
        /// <param name="format">the format string</param>
        /// <returns></returns>
        [Microsoft.SqlServer.Server.SqlMethod(DataAccess = Microsoft.SqlServer.Server.DataAccessKind.None, IsDeterministic = false, IsMutator = false, IsPrecise = true,
        SystemDataAccess = Microsoft.SqlServer.Server.SystemDataAccessKind.None)]
        public static CADate ParseUsingFormat(string data, string format)
        {
            if (data == null || format == null)
                return Null;

            return new CADate(DateTime.ParseExact(data,
                FilterDateFormat(format), DateTimeFormatInfo.CurrentInfo));
        }

        /// <summary>
        /// convert the date to string, using the specified format
        /// </summary>
        /// <param name="format"></param>
        /// <returns></returns>
        public string ToGregorianStringUsingFormat(string format)
        {
            if (this.IsNull)
                return null;

            return this.DateTime.ToString(FilterDateFormat(format),
                DateTimeFormatInfo.CurrentInfo);
        }

        #endregion

        #region creating new values

        /// <summary>
        ///     Each tick is 100 nanoseconds.  This conversion factor when multipled by the number of
        ///     days yields the number of ticks which make up that day.  Ticks are interesting as they
        ///     can be used to construct DateTime instances in order to perform various date based computations.
        /// </summary>
        private const long DaysToTicksConversionFactor = 10L * 1000L * 1000L * 60L * 60L * 24L;

        /// <summary>
        ///     Converts a DateTime instance and a calendar into a calendar aware date instance.
        /// </summary>
        /// <param name="dt">A specific point in time</param>
        /// <param name="calendar_id">A specific calendar system</param>
        private CADate(DateTime dt, int calendar_id)
        {
            this.days = (uint)(dt.Ticks / DaysToTicksConversionFactor);
            this.calendar_id = (byte)calendar_id;
        }

        /// <summary>
        /// construct a CADate from the specified datetime using the default calendar.
        /// </summary>
        /// <param name="dt"></param>
        public CADate(DateTime dt)
            : this(dt, CalendarInfo.DefaultCalendarId)
        {
        }

        /// <summary>
        /// Construct a calendar aware date for the specified year/month/day using the default calendar
        /// </summary>
        /// <param name="year"></param>
        /// <param name="month"></param>
        /// <param name="day"></param>
        public CADate(int year, int month, int day)
            : this(new DateTime(year, month, day, CalendarInfo.DefaultCalendar))
        {
        }

        //The following methods are intended to be callable from tsql.  That is why they are static.

        /// <summary>
        /// the current CADate
        /// </summary>
        /// <value></value>
        public static CADate Now
        {
            get
            {
                return new CADate(DateTime.Now);
            }
        }

        /// <summary>
        /// Create a new CADate from a SqlDateTime
        /// </summary>
        /// <param name="d"></param>
        /// <returns></returns>
        [Microsoft.SqlServer.Server.SqlMethod(DataAccess = Microsoft.SqlServer.Server.DataAccessKind.None, IsDeterministic = false, IsMutator = false, IsPrecise = false,
        SystemDataAccess = Microsoft.SqlServer.Server.SystemDataAccessKind.None)]
        public static CADate FromSqlDateTime(SqlDateTime sqlDateTime)
        {
            if (sqlDateTime.IsNull)
                return Null;

            return new CADate(sqlDateTime.Value);
        }

        /// <summary>
        /// Creates a CADateTime from a Sql DateTime instance and a specific calendar.
        /// </summary>
        /// <param name="d">When</param>
        /// <param name="calendarName">The short name of the desired calendar</param>
        /// <returns></returns>
        [Microsoft.SqlServer.Server.SqlMethod(DataAccess = Microsoft.SqlServer.Server.DataAccessKind.None, IsDeterministic = true, IsMutator = false, IsPrecise = false,
        SystemDataAccess = Microsoft.SqlServer.Server.SystemDataAccessKind.None)]
        public static CADate FromSqlDateTimeAndCalendar(SqlDateTime sqlDateTime, string calendarName)
        {
            return new CADate(sqlDateTime.Value, CalendarInfo.GetCalendarId(calendarName));
        }

        /// <summary>
        /// Create a new CADate from the year/month/day
        /// </summary>
        /// <param name="year"></param>
        /// <param name="month"></param>
        /// <param name="day"></param>
        /// <returns></returns>
        [Microsoft.SqlServer.Server.SqlMethod(DataAccess = Microsoft.SqlServer.Server.DataAccessKind.None, IsDeterministic = false, IsMutator = false, IsPrecise = true,
        SystemDataAccess = Microsoft.SqlServer.Server.SystemDataAccessKind.None)]
        public static CADate FromYearMonthDay(int year, int month, int day)
        {
            return new CADate(year, month, day);
        }



        #endregion

        #region public behaviors, date part

        // Accessors for parts of the date 

        public int Year
        {
            [Microsoft.SqlServer.Server.SqlMethod(IsDeterministic = true, IsPrecise = true)]
            get
            {
                return this.Calendar.GetYear(this.DateTime);
            }
        }

        public int Month
        {
            [Microsoft.SqlServer.Server.SqlMethod(IsDeterministic = true, IsPrecise = true)]
            get
            {
                return this.Calendar.GetMonth(this.DateTime);
            }
        }

        public int DayOfMonth
        {
            [Microsoft.SqlServer.Server.SqlMethod(IsDeterministic = true, IsPrecise = true)]
            get
            {
                return this.Calendar.GetDayOfMonth(this.DateTime);
            }
        }

        public int Day
        {
            [Microsoft.SqlServer.Server.SqlMethod(IsDeterministic = true, IsPrecise = true)]
            get
            {
                return this.Calendar.GetDayOfYear(this.DateTime);
            }
        }

        [CLSCompliant(false)]
        public uint Days
        {
            [Microsoft.SqlServer.Server.SqlMethod(IsDeterministic = true, IsPrecise = true)]
            get
            {
                return this.days;
            }
        }

        // Conversions to other representations of the date

        /// <summary>
        /// convert to datetime
        /// </summary>
        /// <value></value>
        public DateTime DateTime
        {
            [Microsoft.SqlServer.Server.SqlMethod(IsDeterministic = true, IsPrecise = true)]
            get { return new DateTime(this.Days * DaysToTicksConversionFactor); }
        }

        /// <summary>
        /// convert to sql datetime
        /// </summary>
        /// <returns></returns>
        public SqlDateTime ToSqlDateTime()
        {
            return new SqlDateTime(this.DateTime);
        }
        #endregion

        #region date arithmetic

        // Manipulation of date parts

        public CADate AddYears(int years)
        {
            return new CADate(this.Calendar.AddYears(this.DateTime, years));
        }

        public CADate AddDays(int daysToAdd)
        {
            return new CADate(this.Calendar.AddDays(this.DateTime, daysToAdd));
        }

        public CADate AddMonths(int months)
        {
            return new CADate(this.Calendar.AddMonths(this.DateTime, months));
        }

        public double DiffDays(CADate other)
        {
            return this.DateTime.Subtract(other.DateTime).TotalDays;
        }


        #endregion

        #region private implementation details

        /// <summary>
        /// The number of days since the calendar started (January 1, 1)
        /// </summary>
        private uint days;

        /// <summary>
        /// Which calendar is used for this date and time
        /// </summary>
        private byte calendar_id;

        public Calendar Calendar
        {
            get
            {
                return CalendarInfo.Calendars[calendar_id];
            }
        }

        public string CalendarName
        {
            get
            {
                return this.Calendar.GetType().Name;
            }
        }

        // Hashing and comparison methods

        public override int GetHashCode()
        {
            return this.DateTime.GetHashCode();
        }

        public override bool Equals(object obj)
        {
            if (!(obj is DateTime)) 
                return false;

            DateTime dt = (DateTime)obj;
            return this.DateTime.Equals(dt);
        }

        public static SqlBoolean operator ==(CADate xCADate, CADate yCADate)
        {
            if (xCADate.IsNull || yCADate.IsNull)
                return SqlBoolean.Null;

            return xCADate.DateTime == yCADate.DateTime;
        }

        public static SqlBoolean operator !=(CADate xCADate, CADate yCADate)
        {
            if (xCADate.IsNull || yCADate.IsNull)
                return SqlBoolean.Null;

            return xCADate.DateTime != yCADate.DateTime;
        }

        public static string CurrentCalendarName
        {
            get
            {
                return CalendarInfo.DefaultCalendar.GetType().Name;
            }
        }



        static readonly char[] allowedSinglePatternChars = new char[] { 'd', 'D', 'm', 'M', 'y', 'Y', '/', '%' };
        static readonly char[] allowedDoublePatternChars = new char[] { 'g', '\\' };

        //DateTime.ParseExact takes a "format" string which describes how to present the date and time.
        //This method filters out any formatting characters which conflict 
        private static string FilterDateFormat(string format)
        {
            StringBuilder sb = new StringBuilder(format.Length);
            for (int i = 0; i < format.Length; i++)
            {
                char element = format[i];
                bool doubled = (i + 1 < format.Length)
                    && (element.Equals(format[i + 1]) || element.Equals('\\'));
                if (Array.IndexOf<char>(allowedSinglePatternChars, element) > -1 ||
                    char.IsWhiteSpace(element))
                {
                    sb.Append(element);
                }
                else if (doubled && (Array.IndexOf<char>(allowedDoublePatternChars, element) > -1))
                {
                    sb.Append(element);
                    sb.Append(format[++i]);
                }
            }
            return sb.ToString();
        }

        static readonly char[] dateChars = new char[] { 'd', 'M', 'y' };

        // Returns a string suitable for use with string.Format which displays
        // day, month, and year components in a culture appropriate way.
        private static string DayMonthYearFormatString()
        {
            string cultureDatePattern = CultureInfo.CurrentCulture.DateTimeFormat.ShortDatePattern;
            return CalendarInfo.SubstitutePositionForCharacters(dateChars, cultureDatePattern);
        }


        #endregion

        #region XML Serialization

        const string CADateSchema =
            "<xs:schema targetNamespace=\"http://schemas.microsoft.com/sqlserver/2004/08/CADate\" " +
                "xmlns=\"http://schemas.microsoft.com/sqlserver/2004/07/CADate\" " +
                "elementFormDefault=\"qualified\"" +
                "xmlns:xs=\"http://www.w3.org/2001/XMLSchema\" >" +
                "<xs:element name=\"CADate\" >" +
                    "<xs:complexType mixed=\"true\" >" +
                        "<xs:attribute name=\"IsNull\" use=\"required\" type=\"xs:boolean\" />" +
                        "<xs:attribute name=\"Year\" type=\"xs:int\"/>" +
                        "<xs:attribute name=\"Month\" type=\"xs:int\"/>" +
                        "<xs:attribute name=\"Day\" type=\"xs:int\"/>" +
                        "<xs:attribute name=\"Calendar\" type=\"xs:string\"/>" +
                    "</xs:complexType>" +
                "</xs:element>" +
            "</xs:schema>";

        public XmlSchema GetSchema()
        {
            return XmlSchema.Read(new StringReader(CADateSchema), new ValidationEventHandler(ValidationHandler));
        }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2201:DoNotRaiseReservedExceptionTypes")]
        private void ValidationHandler(object sender, ValidationEventArgs args)
        {
            throw new ApplicationException(args.Message);
        }

        public void ReadXml(XmlReader reader)
        {
            reader.MoveToContent();
            if (reader.GetAttribute("IsNull").Equals("true"))
                this.days = nullDay;
            else
            {
                string calendarName = reader.GetAttribute("Calendar");
                Calendar requestedCalendar = CalendarInfo.Calendars[
                    CalendarInfo.GetCalendarId(calendarName)];

                days = (uint)(new DateTime(int.Parse(reader.GetAttribute("Year"),
                    CultureInfo.CurrentUICulture),
                    int.Parse(reader.GetAttribute("Month"),
                    CultureInfo.CurrentUICulture),
                    int.Parse(reader.GetAttribute("Day"),
                    CultureInfo.CurrentUICulture),
                    requestedCalendar).Ticks / DaysToTicksConversionFactor);
            }
        }

        public void WriteXml(XmlWriter writer)
        {
            writer.WriteStartElement("CADate",
                "http://schemas.microsoft.com/sqlserver/2004/08/CADate");
            writer.WriteAttributeString("IsNull",
                IsNull.ToString(CultureInfo.CurrentUICulture));
            if (!IsNull)
            {
                writer.WriteAttributeString("Year",
                    Year.ToString(CultureInfo.CurrentUICulture));
                writer.WriteAttributeString("Month",
                    Month.ToString(CultureInfo.CurrentUICulture));
                writer.WriteAttributeString("Day",
                    Day.ToString(CultureInfo.CurrentUICulture));
                writer.WriteAttributeString("Calendar",
                    Calendar.GetType().ToString());
            }

            writer.WriteEndElement();
        }

        #endregion
    }
}
