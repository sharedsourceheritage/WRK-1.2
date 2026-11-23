using System;
using System.Data;
using System.Data.Sql;
using System.Data.SqlTypes;
using System.Globalization;
using Microsoft.Samples.SqlServer;
using System.IO;
using System.Data.SqlClient;
using Microsoft.SqlServer.Server;

/*=====================================================================

  File:      CurrencyConverter.cs for Adventure Works Cycles SQLCLR Layer Sample
  Summary:   Defines the ConvertCurrency method which is exposed as a UDF in SQL Server.
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
    /// This class is used to compute the value of US money a given region.
    /// </summary>
    public sealed class CurrencyConverter
    {
        // Classes with only static members should not be instantiable
        private CurrencyConverter()
        {
        }

        private static readonly CultureInfo USCulture = CultureInfo.CreateSpecificCulture("en-us");

        /// <summary>
        ///		Computes the value of a certain amount of money in the USA in a different region.
        /// </summary>
        /// <param name="fromAmount">The quantity of money</param>
        /// <param name="toCultureName">A culture which is a member of the region of interest</param>
        /// <returns></returns>
        [Microsoft.SqlServer.Server.SqlFunction(IsDeterministic = true, DataAccess = Microsoft.SqlServer.Server.DataAccessKind.Read)]
        [CLSCompliant(false)]
        public static Microsoft.Samples.SqlServer.Currency ConvertCurrency(SqlMoney fromAmount, SqlString toCultureName, SqlDateTime when)
        {
            CultureInfo toCulture = CultureInfo.CreateSpecificCulture(toCultureName.Value);

            if (toCulture.Equals(USCulture))
            {
                Currency c = new Currency(USCulture, (decimal)fromAmount);
                return c;
            }

            String toCurrencyCode = new RegionInfo(toCulture.LCID).ISOCurrencySymbol;

            // Find the rate closest to the specified date

            using (SqlConnection conn = new SqlConnection("context connection=true"))
            {

                SqlCommand command = conn.CreateCommand();
                command.CommandType = CommandType.StoredProcedure;
                command.CommandText = "usp_LookupConversionRate";

                SqlParameter onDateParameter
                    = new SqlParameter("@OnDate", SqlDbType.DateTime);
                onDateParameter.Value = when;
                command.Parameters.Add(onDateParameter);

                SqlParameter toCurrencyCodeParameter
                    = new SqlParameter("@ToCurrencyCode", SqlDbType.NChar, 3);
                toCurrencyCodeParameter.Value = toCurrencyCode;
                command.Parameters.Add(toCurrencyCodeParameter);

                SqlParameter resultParameter
                    = new SqlParameter("@Result", SqlDbType.Decimal);
                resultParameter.Precision = 10;
                resultParameter.Scale = 4;
                resultParameter.Direction = ParameterDirection.Output;
                command.Parameters.Add(resultParameter);

                conn.Open();
                command.ExecuteNonQuery();

                decimal conversionFactor;

                if (resultParameter.Value is decimal)
                {
                    conversionFactor = (decimal)(resultParameter.Value);
                }
                else
                {
                    conversionFactor = 1.0M;
                    toCulture = USCulture;
                }

                return new Currency(toCulture, ((decimal)fromAmount * conversionFactor));
            }
        }
    }
}
