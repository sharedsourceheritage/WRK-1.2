#region Using directives

using System;
using System.Collections.Generic;
using System.Text;
using System.Data;
using System.Data.SqlClient;
using System.Globalization;

#endregion

/*=====================================================================

  File:      Program.cs
  Summary:   A simple test client app which uses a Format.Native UDT that represents a complex number
  Date:	     Sep 23, 2003

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
            if (args.Length != 1)
            {
                Console.WriteLine("usage: clientsample.exe databaseName");
                return;
            }
            string dbName = args[0];
            using (SqlConnection c = new SqlConnection(string.Format(CultureInfo.InvariantCulture, "server=localhost; database={0}; integrated security=true", dbName)))
            {
                c.Open();

                // select some UDT values and dump them the console
                SqlCommand cmd = new SqlCommand("select convert(ComplexNumber, '(1,2i)')", c);
                object obj = cmd.ExecuteScalar();
                Console.WriteLine("got back a value of type " + obj.GetType());
                Console.WriteLine("calling to string on value " + obj.ToString());

                // cast the value to the UDT
                //ComplexNumber cn = (ComplexNumber)obj;

                // send a UDT parameter back to the server
                // and get it back
                cmd.CommandText = "select @v";

                // create a parameter of type Udt
                SqlParameter p = cmd.Parameters.Add("@v", SqlDbType.Udt);
                p.UdtTypeName = "ComplexNumber";
                p.Value = new ComplexNumber(45, 32);

                object o2 = cmd.ExecuteScalar();
                Console.WriteLine("got back " + o2);
            }
        }
	}
}
