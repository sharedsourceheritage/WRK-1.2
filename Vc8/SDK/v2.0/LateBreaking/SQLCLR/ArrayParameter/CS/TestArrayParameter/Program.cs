#region Using directives

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Data;
using System.Data.Sql;
using System.Data.SqlTypes;
using System.Data.SqlClient;
using Microsoft.Samples.SqlServer.Properties;


#endregion

/*=====================================================================

  File:      Program.cs for the ArrayParameter CLR Integration sample
  Summary:   A console application which demonstrates passing 
             an array of strings to the server.  This application ensures that all
             the contact type names provided on the command line are in the 
             Person.ContactType table. If any names are missing they are inserted.
             The list of contact type names is displayed before and after the inserts 
             (if any).
  Date:	     December 14, 2004

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
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length == 0)
            {
                Console.WriteLine("Usage: TestArrayParameter contactTypeName1 "
                    + "contactTypeName2 ... contactTypeNamen");
                return;
            }
            using (SqlConnection connection = new SqlConnection(Settings.Value.connectionString))
            {
                connection.Open();
                ShowTypeNames(connection, "before any inserts");

                SqlCommand command = connection.CreateCommand();
                command.CommandText = "usp_EnsureContactTypeNames";
                command.CommandType = CommandType.StoredProcedure;
                SqlParameter namesParameter = new SqlParameter("@names", SqlDbType.Udt);
                namesParameter.UdtTypeName = "ContactTypeNames";
                namesParameter.Value = new ContactTypeNames(args);
                command.Parameters.Add(namesParameter);
                command.ExecuteNonQuery();

                ShowTypeNames(connection, "after any inserts");

            }

        }

        private static void ShowTypeNames(SqlConnection connection, string whenRan)
        {
            SqlCommand command = connection.CreateCommand();
            command.CommandText = "SELECT Name FROM Person.ContactType ORDER BY Name";
            using (SqlDataReader reader = command.ExecuteReader())
            {
                Console.BackgroundColor = ConsoleColor.Blue;
                Console.Write("Contact type names {0}: ", whenRan);
                Console.ResetColor();
                bool first = true;
                while (reader.Read())
                {
                    if (!first) Console.Write(", ");
                    Console.Write(reader[0].ToString());
                    first = false;
                }
                Console.WriteLine("");
                Console.WriteLine("");
            }

        }
    }
}
