using System;
using System.Data.Sql;
using System.Data.SqlTypes;
using System.Globalization;
using System.Resources;
using System.Text;
using System.Reflection;
using System.Collections.Generic;
using System.IO;
using System.Xml;
using System.Xml.Schema;
using System.Xml.Serialization;
using Microsoft.SqlServer.Server;

/*=====================================================================

  File:      calendarawaredatetime.cs for calendar aware data time Sample
  Summary:   Defines a CLR user defined time which represents dates and times for 
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
    /// A datetime value in the specified calendar system.
    /// </summary>
    [Serializable]
    [Microsoft.SqlServer.Server.SqlUserDefinedType(Microsoft.SqlServer.Server.Format.Native, IsByteOrdered = true, ValidationMethodName = "IsValid")]
    public struct CADateTime : INullable, IXmlSerializable
    {
        #region nullability
        // This type uses ticks == 0 as the way to designate a NULL value
        private const long nullTicks = 0;

        /// <summary>
        /// return the null value for this type
        /// </summary>
        /// <value></value>
        public static CADateTime Null
        {
            get
            {
                CADateTime dt = new CADateTime();
                dt.dtTicks = nullTicks;
                return dt;
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
                return this.Ticks == nullTicks;
            }
        }
        #endregion

        #region string conversion
        /// <summary>
        /// parse the given string and return a calendar aware datetime.
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        [Microsoft.SqlServer.Server.SqlMethod(DataAccess = Microsoft.SqlServer.Server.DataAccessKind.None, IsDeterministic = false, IsMutator = false, IsPrecise = true,
        SystemDataAccess = Microsoft.SqlServer.Server.SystemDataAccessKind.None)]
        public static CADateTime Parse(SqlString sqlString)
        {
            if (sqlString.IsNull)
                return Null;

            return new CADateTime(DateTime.Parse(sqlString.Value,
                DateTimeFormatInfo.CurrentInfo));
        }

        /// <summary>
        /// convert the datetime to string
        /// </summary>
        /// <returns></returns>
        public override string ToString()
        {
            if (this.IsNull)
                return null;

            bool afternoon = this.Hour >= 12;
            int twelveHour = this.Hour;
            if (twelveHour == 0)
                twelveHour = 12;
            else if (twelveHour > 12)
                twelveHour = twelveHour - 12;

            return string.Format(CultureInfo.CurrentCulture,
                DateTimeFormatString(), this.DayOfMonth, this.Month, this.Year,
                twelveHour, this.Hour, this.Minute, this.Second,
                afternoon ? CultureInfo.CurrentCulture.DateTimeFormat.PMDesignator
                    : CultureInfo.CurrentCulture.DateTimeFormat.AMDesignator);
        }

        /// <summary>
        /// Return a string representation of this DateTime, in the Gregorian calendar_id
        /// </summary>
        /// <returns></returns>
        public string ToGregorianString()
        {
            if (this.IsNull)
                return null;

            return this.DateTime.ToString(DateTimeFormatInfo.CurrentInfo);
        }

        /// <summary>
        /// Construct a CADateTime from the specified format, using the current culture
        /// </summary>
        /// <param name="data">the string to be parsed</param>
        /// <param name="format">the format string</param>
        /// <returns></returns>
        [Microsoft.SqlServer.Server.SqlMethod(DataAccess = Microsoft.SqlServer.Server.DataAccessKind.None, IsDeterministic = false, IsMutator = false, IsPrecise = true,
        SystemDataAccess = Microsoft.SqlServer.Server.SystemDataAccessKind.None)]
        public static CADateTime ParseUsingFormat(string data, string format)
        {
            if (data == null || format == null) 
                return Null;

            return new CADateTime(DateTime.ParseExact(data, format, DateTimeFormatInfo.CurrentInfo));
        }

        /// <summary>
        /// convert the datetime to string, using the specified format
        /// </summary>
        /// <param name="format"></param>
        /// <returns></returns>
        public string ToGregorianStringUsingFormat(string format)
        {
            if (this.IsNull)
                return null;

            return this.DateTime.ToString(format, DateTimeFormatInfo.CurrentInfo);
        }
        #endregion

        #region creating new values

        /// <summary>
        ///     Converts a DateTime instance and a calendar into a calendar aware datetime instance.
        /// </summary>
        /// <param name="dt">A specific point in time</param>
        /// <param name="calendar_id">A specific calendar system</param>
        private CADateTime(DateTime dt, int calendar_id)
        {
            this.dtTicks = dt.Ticks;
            this.calendar_id = (byte)calendar_id;
        }

        /// <summary>
        /// construct a CADateTime from the specified datetime using the default calendar.
        /// </summary>
        /// <param name="dt"></param>
        public CADateTime(DateTime dt)
            : this(dt, CalendarInfo.DefaultCalendarId)
        {
        }

        /// <summary>
        /// Construct a calendar aware datetime for the specified year/month/day using the default calendar
        /// </summary>
        /// <param name="year"></param>
        /// <param name="month"></param>
        /// <param name="day"></param>
        public CADateTime(int year, int month, int day)
            : this(new DateTime(year, month, day, CalendarInfo.DefaultCalendar))
        {
        }

        //the following static methods are callable from tsql

        /// <summary>
        /// the current CADateTime
        /// </summary>
        /// <value></value>
        public static CADateTime Now
        {
            get
            {
                return new CADateTime(DateTime.Now);
            }
        }

        /// <summary>
        /// Create a new CADateTime from a SqlDateTime
        /// </summary>
        /// <param name="d"></param>
        /// <returns></returns>
        [Microsoft.SqlServer.Server.SqlMethod(DataAccess = Microsoft.SqlServer.Server.DataAccessKind.None, IsDeterministic = false, IsMutator = false, IsPrecise = true,
        SystemDataAccess = Microsoft.SqlServer.Server.SystemDataAccessKind.None)]
        public static CADateTime FromSqlDateTime(SqlDateTime sqlDateTime)
        {
            if (sqlDateTime.IsNull)
                return Null;

            return new CADateTime(sqlDateTime.Value);
        }

        /// <summary>
        /// Creates a CADateTime from a Sql DateTime instance and a specific calendar.
        /// </summary>
        /// <param name="d">When</param>
        /// <param name="calendarName">The short name of the desired calendar</param>
        /// <returns></returns>
        [Microsoft.SqlServer.Server.SqlMethod(DataAccess = Microsoft.SqlServer.Server.DataAccessKind.None, IsDeterministic = true, IsMutator = false, IsPrecise = true,
        SystemDataAccess = Microsoft.SqlServer.Server.SystemDataAccessKind.None)]
        public static CADateTime FromSqlDateTimeAndCalendar(SqlDateTime sqlDateTime, string calendarName)
        {
            return new CADateTime(sqlDateTime.Value, CalendarInfo.GetCalendarId(calendarName));
        }

        /// <summary>
        /// Create a new CADateTime from the year/month/day
        /// </summary>
        /// <param name="year"></param>
        /// <param name="month"></param>
        /// <param name="day"></param>
        /// <returns></returns>
        [Microsoft.SqlServer.Server.SqlMethod(DataAccess = Microsoft.SqlServer.Server.DataAccessKind.None, IsDeterministic = false, IsMutator = false, IsPrecise = true,
        SystemDataAccess = Microsoft.SqlServer.Server.SystemDataAccessKind.None)]
        public static CADateTime FromYearMonthDay(int year, int month, int day)
        {
            return new CADateTime(year, month, day);
        }

        public bool IsValid()
        {
            return dtTicks >= 0;
        }

        #endregion

        #region public behaviors, date part

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

        public int Hour
        {
            [Microsoft.SqlServer.Server.SqlMethod(IsDeterministic = true, IsPrecise = true)]
            get
            {
                return this.Calendar.GetHour(this.DateTime);
            }
        }

        public int Minute
        {
            [Microsoft.SqlServer.Server.SqlMethod(IsDeterministic = true, IsPrecise = true)]
            get
            {
                return this.Calendar.GetMinute(this.DateTime);
            }
        }

        public int Second
        {
            [Microsoft.SqlServer.Server.SqlMethod(IsDeterministic = true, IsPrecise = true)]
            get
            {
                return this.Calendar.GetSecond(this.DateTime);
            }
        }

        /// <summary>
        /// Milliseconds
        /// </summary>
        /// <value></value>
        public double Milliseconds
        {
            [Microsoft.SqlServer.Server.SqlMethod(IsDeterministic = true, IsPrecise = true)]
            get
            {
                return this.Calendar.GetMilliseconds(this.DateTime);
            }
        }

        public long Ticks
        {
            [Microsoft.SqlServer.Server.SqlMethod(IsDeterministic = true, IsPrecise = true)]
            get
            {
                return this.dtTicks;
            }
        }

        /// <summary>
        /// convert to datetime
        /// </summary>
        /// <value></value>
        public DateTime DateTime
        {
            [Microsoft.SqlServer.Server.SqlMethod(IsDeterministic = true, IsPrecise = true)]
            get { return new DateTime(this.dtTicks); }
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
        public CADateTime AddYears(int years)
        {
            return new CADateTime(this.Calendar.AddYears(this.DateTime, years));
        }

        public CADateTime AddDays(int days)
        {
            return new CADateTime(this.Calendar.AddDays(this.DateTime, days));
        }

        public CADateTime AddMonths(int months)
        {
            return new CADateTime(this.Calendar.AddMonths(this.DateTime, months));
        }

        public CADateTime AddHours(int hours)
        {
            return new CADateTime(this.Calendar.AddHours(this.DateTime, hours));
        }

        public CADateTime AddMinutes(int minutes)
        {
            return new CADateTime(this.Calendar.AddMinutes(this.DateTime, minutes));
        }

        public CADateTime AddSeconds(int seconds)
        {
            return new CADateTime(this.Calendar.AddSeconds(this.DateTime, seconds));
        }

        public CADateTime AddMilliseconds(double millis)
        {
            return new CADateTime(this.Calendar.AddMilliseconds(this.DateTime, millis));
        }

        public double DiffDays(CADateTime other)
        {
            return this.DateTime.Subtract(other.DateTime).TotalDays;
        }

        public double DiffHours(CADateTime other)
        {
            return this.DateTime.Subtract(other.DateTime).TotalHours;
        }

        public double DiffMinutes(CADateTime other)
        {
            return this.DateTime.Subtract(other.DateTime).TotalMinutes;
        }

        public double DiffSeconds(CADateTime other)
        {
            return this.DateTime.Subtract(other.DateTime).TotalSeconds;
        }

        public double DiffMilliseconds(CADateTime other)
        {
            return this.DateTime.Subtract(other.DateTime).TotalMilliseconds;
        }
        #endregion

        #region private implementation details

        /// <summary>
        /// What date and time this is as ticks from midnight January 1, 1
        /// </summary>
        private long dtTicks;

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

        // Hash and comparison operators

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

        public static SqlBoolean operator ==(CADateTime xCADateTime, CADateTime yCADateTime)
        {
            if (xCADateTime.IsNull || yCADateTime.IsNull)
                return SqlBoolean.Null;

            return xCADateTime.DateTime == yCADateTime.DateTime;
        }

        public static SqlBoolean operator !=(CADateTime xCADateTime, CADateTime yCADateTime)
        {
            if (xCADateTime.IsNull || yCADateTime.IsNull)
                return SqlBoolean.Null;

            return xCADateTime.DateTime != yCADateTime.DateTime;
        }

        public static string CurrentCalendarName
        {
            get
            {
                return CalendarInfo.DefaultCalendar.GetType().Name;
            }
        }

        static readonly char[] datetimeChars = new char[] { 'd', 'M', 'y', 'h', 'H', 'm', 's', 't' };

        // Returns a string suitable for use with string.Format which displays
        // day, month, and year components in a culture appropriate way.
        private static string DateTimeFormatString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append(CultureInfo.CurrentCulture.DateTimeFormat.ShortDatePattern);
            sb.Append(" ");
            sb.Append(CultureInfo.CurrentCulture.DateTimeFormat.LongTimePattern);
            string cultureDatePattern = sb.ToString();

            return CalendarInfo.SubstitutePositionForCharacters(datetimeChars, cultureDatePattern);
        }


        #endregion

        #region XML Serialization

        const string CADateTimeSchema =
            "<xs:schema targetNamespace=\"http://schemas.microsoft.com/sqlserver/2004/08/CADateTime\" " +
                "xmlns=\"http://schemas.microsoft.com/sqlserver/2004/07/CADate\" " +
                "elementFormDefault=\"qualified\"" +
                "xmlns:xs=\"http://www.w3.org/2001/XMLSchema\" >" +
                "<xs:element name=\"CADate\" >" +
                    "<xs:complexType mixed=\"true\" >" +
                        "<xs:attribute name=\"IsNull\" use=\"required\" type=\"xs:boolean\" />" +
                        "<xs:attribute name=\"Year\" type=\"xs:int\"/>" +
                        "<xs:attribute name=\"Month\" type=\"xs:int\"/>" +
                        "<xs:attribute name=\"Day\" type=\"xs:int\"/>" +
                        "<xs:attribute name=\"Hour\" type=\"xs:int\">" +
                        "<xs:attribute name=\"Minute\" type=\"xs:int\">" +
                        "<xs:attribute name=\"Second\" type=\"xs:int\">" +
                        "<xs:attribute name=\"Calendar\" type=\"xs:string\"/>" +
                    "</xs:complexType>" +
                "</xs:element>" +
            "</xs:schema>";

        public XmlSchema GetSchema()
        {
            return XmlSchema.Read(new StringReader(CADateTimeSchema), new ValidationEventHandler(ValidationHandler));
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
                dtTicks = nullTicks;
            else
            {
                string calendarName = reader.GetAttribute("Calendar");
                Calendar requestedCalendar = CalendarInfo.Calendars[
                    CalendarInfo.GetCalendarId(calendarName)];

                dtTicks = (uint)(new DateTime(
                    int.Parse(reader.GetAttribute("Year"),
                        CultureInfo.CurrentCulture),
                    int.Parse(reader.GetAttribute("Month"),
                        CultureInfo.CurrentCulture),
                    int.Parse(reader.GetAttribute("Day"),
                        CultureInfo.CurrentCulture),
                    int.Parse(reader.GetAttribute("Hour"),
                        CultureInfo.CurrentCulture),
                    int.Parse(reader.GetAttribute("Minute"),
                        CultureInfo.CurrentCulture),
                    int.Parse(reader.GetAttribute("Second"),
                        CultureInfo.CurrentCulture),
                    requestedCalendar).Ticks);
            }
        }

        public void WriteXml(XmlWriter writer)
        {
            writer.WriteStartElement("CADate", "http://schemas.microsoft.com/sqlserver/2004/08/CADate");
            writer.WriteAttributeString("IsNull", IsNull.ToString());
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
