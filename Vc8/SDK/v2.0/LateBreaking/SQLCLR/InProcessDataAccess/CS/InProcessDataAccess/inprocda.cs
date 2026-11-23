/*=====================================================================

  File:      inprocda.cs
  Summary:   Simple examples to demonstrate in-proc data access features
  Date:	     September 16, 2003

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
using System.Data;
using System.Data.Sql;
using System.Data.SqlTypes;
using System.Data.SqlClient;
using Microsoft.SqlServer.Server;

[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1020:AvoidNamespacesWithFewTypes", Scope = "namespace", Target = "Microsoft.Samples.SqlServer")]
namespace Microsoft.Samples.SqlServer
{
	public sealed class DataAccessDemo
	{
        private DataAccessDemo()
        {
        }

        /// <summary>
		/// Simple example to send a message to the client.
		/// </summary>
		public static void SendMessage(string msg)
		{
			SqlContext.Pipe.Send("Message from server: " + msg);
		}

		/// <summary>
		/// Simple example of performing data access within
		/// a function
		/// </summary>
		/// <returns></returns>
        [Microsoft.SqlServer.Server.SqlFunction(DataAccess = Microsoft.SqlServer.Server.DataAccessKind.Read)]
		public static string ReportSqlVersion()
		{
            using (SqlConnection conn = new SqlConnection("context connection=true"))
            {
                //create a command from the current context
                SqlCommand cmd = conn.CreateCommand();

                //execute something
                cmd.CommandText = "select @@version";

                conn.Open();
                //return results as scalar
                return (string)cmd.ExecuteScalar();
            }
		}


		/// <summary>
		/// Create a result set on the fly and send it to the client.
		/// </summary>
		public static void SendTransientResultSet()
		{
			//create the metadata for the columns
            Microsoft.SqlServer.Server.SqlMetaData[] columnSchema 
                = new Microsoft.SqlServer.Server.SqlMetaData[] {
				new Microsoft.SqlServer.Server.SqlMetaData("stringcol", SqlDbType.NVarChar, 128)
			};

			//create a record based on that metadata
            SqlDataRecord newRecord = new SqlDataRecord(columnSchema);

			//populate it
			newRecord.SetString(0, "Hello World!");

			//send it
			SqlContext.Pipe.Send(newRecord);
		}

		/// <summary>
		/// Execute a command and send the results to the client directly.
		/// </summary>
		public static void ExecuteToClient()
		{
            using (SqlConnection conn = new SqlConnection("context connection=true"))
            {
                SqlCommand cmd = conn.CreateCommand();

                cmd.CommandText = "select @@version";
                conn.Open();
                SqlContext.Pipe.ExecuteAndSend(cmd);
            }
		}

		/// <summary>
		/// Execute a command and send the resultig reader to the client
		/// </summary>
		public static void SendReaderToClient()
		{
            using (SqlConnection conn = new SqlConnection("context connection=true"))
            {
                SqlCommand cmd = conn.CreateCommand();

                cmd.CommandText = "select @@version";
                conn.Open();
                SqlDataReader rdr = cmd.ExecuteReader();
                try
                {
                    SqlContext.Pipe.Send(rdr);
                }
                finally
                {
                    rdr.Close();
                }
            }
		}

	};
}