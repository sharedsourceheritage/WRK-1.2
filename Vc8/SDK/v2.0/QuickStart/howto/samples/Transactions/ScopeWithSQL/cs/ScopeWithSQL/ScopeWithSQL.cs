//---------------------------------------------------------------------
//  This file is part of the Microsoft .NET Framework SDK Code Samples.
// 
//  Copyright (C) Microsoft Corporation.  All rights reserved.
// 
//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.
// 
//THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.
//---------------------------------------------------------------------


using System;
using System.Transactions;
using System.Data;
using System.Data.SqlClient;

namespace Microsoft.Samples.Transactions.Quickstarts
{
	class ScopeWithSQL
	{
		static void Main(string[] args)
		{
			try
			{
				using (TransactionScope ts = new TransactionScope())
				{
					//Create and open the SQL connection.  The work done on this connection will be a part of the transaction created by the TransactionScope
					using (SqlConnection myConnection = new SqlConnection("server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind"))
					{
						SqlCommand myCommand = new SqlCommand();
						myConnection.Open();
						myCommand.Connection = myConnection;

						//Restore database to near it's original condition so sample will work correctly.
						myCommand.CommandText = "DELETE FROM Region WHERE (RegionID = 100) OR (RegionID = 101)";
						myCommand.ExecuteNonQuery();

						//Insert the first record.
						myCommand.CommandText = "Insert into Region (RegionID, RegionDescription) VALUES (100, 'MidWestern')";
						myCommand.ExecuteNonQuery();

						//Insert the second record.
						myCommand.CommandText = "Insert into Region (RegionID, RegionDescription) VALUES (101, 'MidEastern')";
						myCommand.ExecuteNonQuery();
					}

					//Call complete on the TransactionScope or not based on input
					ConsoleKeyInfo c;
					while (true)
					{
						Console.Write("Complete the transaction scope? [Y|N] ");
						c = Console.ReadKey();
						Console.WriteLine();

						if ((c.KeyChar == 'Y') || (c.KeyChar == 'y'))
						{
							// Commit the transaction
							ts.Complete();
							break;
						}
						else if ((c.KeyChar == 'N') || (c.KeyChar == 'n'))
						{
							break;
						}
					}

				}
			}
			catch(System.Transactions.TransactionException ex)
			{
				Console.WriteLine(ex);
			}
			catch
			{
				Console.WriteLine("Cannot complete transaction");
				throw;
			}
		}
	}
}
