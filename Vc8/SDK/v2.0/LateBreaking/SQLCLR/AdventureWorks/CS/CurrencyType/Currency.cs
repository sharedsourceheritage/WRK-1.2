using System;
using System.Globalization;
using System.Data.SqlTypes;
using Microsoft.SqlServer.Server;

/*=====================================================================

  File:      Currency.cs for Adventure Works Cycles SQLCLR Layer Sample
  Summary:   Defines a class for handing particular amounts of money in a 
			 particular culture's monetary system.  This class is exposed as 
			 a SQL Server UDT.
  Date:	     August 15, 2003

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
    ///		Defines a class for handing particular amounts of money in a 
    ///		particular culture's monetary system.  This class is exposed as 
    ///		a SQL Server UDT.
	/// 
	///		Note that we are implementing IComparable to affect comparison behavior 
	///		only within the CLR.  This does not affect how SQL Server will compare the
	///     the types.  How SQL Server will compare the type is determined by the Write 
	///		method on IBinarySerialize.
    /// </summary>
    [Serializable]
    [SqlUserDefinedType(Format.UserDefined, IsByteOrdered = true, MaxByteSize = 32)]
    [CLSCompliant(false)]
    public struct Currency : INullable, IComparable, IBinarySerialize
    {
        const string nullMarker = "\0\0\0\0\0\0\0\0\0\0";
        const int cultureNameMaxSize = 10;

        private string cultureName;		//Who issued the money (en-us, for example)

        private CultureInfo culture;	//The object which represents cultureName

        private decimal currencyValue;	//The amount of money

        // Public properties for private fields
        public CultureInfo Culture
        {
            get
            {
                //A culture name is required.  If not present the entire object is considered null.
                if (cultureName == null) return null;

                //If we've got a cached copy of the culture return it.
                if (culture != null) return culture;

                //Otherwise, set the cache and return the culture for the culture name specified.
                culture = CultureInfo.CreateSpecificCulture(cultureName);
                return culture;
            }
        }

        // Public property for the private field.
        public decimal CurrencyValue
        {
            get
            {
                return currencyValue;
            }
        }

        // Constructors for when we have the culture or the name of the culture

        public Currency(CultureInfo culture, decimal currencyValue)
        {
            this.cultureName = culture.Name;
            this.culture = culture;
            this.currencyValue = currencyValue;
        }

        public Currency(string cultureName, decimal currencyValue)
        {
            this.cultureName = cultureName;
            this.culture = null;
            this.currencyValue = currencyValue;
        }

        //Return the string representation for the currency, including the currency symbol.
        [SqlMethod(IsDeterministic = true,
            IsPrecise = true, DataAccess = DataAccessKind.None,
            SystemDataAccess = SystemDataAccessKind.None)]
        public override string ToString()
        {
            if (this.Culture == null) return "null";

            return String.Format(this.Culture, "{0:c}", currencyValue);
        }

        //The entire value of the currency is considered null if the culture name is null
        public bool IsNull
        {
            get
            {
                return cultureName == null;
            }
        }

        //The no-argument constructor makes a null currency.
        public static Currency Null
        {
            get
            {
                Currency h = new Currency((String)null, 0);

                return h;
            }
        }

        //Be sure to set the current UI culture before using this method! Even better, provide the culture
        //specifically (for the method after this one).
        [SqlMethod(IsDeterministic = true, IsPrecise = true, DataAccess = DataAccessKind.None, SystemDataAccess = SystemDataAccessKind.None)]
        public static Currency Parse(SqlString sqlString)
        {
            return ParseWithCulture(sqlString, CultureInfo.CurrentUICulture);
        }

        public static Currency ParseWithCulture(SqlString sqlString, CultureInfo culture)
        {
            if (sqlString.IsNull || sqlString.Value.ToLower(
                CultureInfo.InvariantCulture) == "null")
                return Currency.Null;

            int digitPos = -1;
            string stringValue = sqlString.Value;

            while (digitPos < stringValue.Length 
                && !Char.IsDigit(stringValue, ++digitPos))
            {
            }

            if (digitPos < stringValue.Length)
                return new Currency(culture, decimal.Parse(
                    stringValue.Substring(digitPos), culture));

            return Currency.Null;
        }

        public override int GetHashCode()
        {
            if (this.IsNull)
                return 0;

            return this.ToString().GetHashCode();
        }

		//Note: This only affects the behavior of CLR, not SQL Server.  Comparions
		//for SQL Server will be determined by the Write method below.
        public int CompareTo(object obj)
        {
            if (obj == null)
                return 1; //by definition

            if (obj == null || !(obj is Currency))
                throw new ArgumentException(
                    "the argument to compare is not a Currency");

            Currency c = (Currency)obj;

            if (this.IsNull)
            {
                if (c.IsNull)
                    return 0;

                return -1;
            }

            if (c.IsNull)
                return 1;

            string thisCultureName = this.Culture.Name;
            string otherCultureName = c.Culture.Name;
            if (!thisCultureName.Equals(otherCultureName))
                return thisCultureName.CompareTo(otherCultureName);
            return this.CurrencyValue.CompareTo(c.CurrencyValue);
        }
        // IBinarySerialize methods
        // The binary layout is as follow:
        //    Bytes 0 - 19:	Culture name, padded to the right with null characters, UTF-16 encoded
        //    Bytes 20+:	Decimal value of money
        // If the culture name is empty, the currency is null.
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2201:DoNotRaiseReservedExceptionTypes")]
        public void Write(System.IO.BinaryWriter w)
        {
            if (this.IsNull)
            {
                w.Write(nullMarker);
                w.Write((decimal)0);
                return;
            }

            if (cultureName.Length > cultureNameMaxSize)
            {
                throw new ApplicationException(string.Format(
                    CultureInfo.InvariantCulture, 
                    "{0} is an invalid culture name for currency as it is too long.", 
                    cultureNameMaxSize));
            }

            String paddedName = cultureName.PadRight(cultureNameMaxSize, '\0');
            for (int i = 0; i < cultureNameMaxSize; i++)
            {
                w.Write(paddedName[i]);
            }

            // Normalize decimal value to two places
            currencyValue = Decimal.Floor(currencyValue * 100) / 100;
            w.Write(currencyValue);
        }
        public void Read(System.IO.BinaryReader r)
        {
            char[] name = r.ReadChars(cultureNameMaxSize);
            int stringEnd = Array.IndexOf(name, '\0');

            if (stringEnd == 0)
            {
                cultureName = null;
                return;
            }

            cultureName = new String(name, 0, stringEnd);
            currencyValue = r.ReadDecimal();
        }
    }
}
