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

namespace Microsoft.Samples.Transactions.Quickstarts
{
	/// <summary>
	/// Shows how an application can obtain the outcome of a transaction, whether or not it
	/// is the one committing it.
	/// </summary>
	class TxOutcome
	{
		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		static void Main(string[] args)
		{
			try
			{
				//Create the transaction scope
				using (TransactionScope scope = new TransactionScope())
				{
					//Register for the transaction completed event for the current transaction
					Transaction.Current.TransactionCompleted += new TransactionCompletedEventHandler(Current_TransactionCompleted);

					//Call complete on the TransactionScope or not based on input
					ConsoleKeyInfo c;
					while (true)
					{
						Console.Write("Complete the transaction scope? [Y|N] ");
						c = Console.ReadKey();
						Console.WriteLine();

						if ((c.KeyChar == 'Y') || (c.KeyChar == 'y'))
						{
							scope.Complete();
							break;
						}
						else if ((c.KeyChar == 'N') || (c.KeyChar == 'n'))
						{
							break;
						}
					}

				}

			}
			catch (System.Transactions.TransactionException ex)
			{
				Console.WriteLine(ex);
			}
			catch
			{
				Console.WriteLine("Cannot complete transaction");
				throw;
			}
		}

		//Transaction completed event handler
		static void Current_TransactionCompleted(object sender, TransactionEventArgs e)
		{
			Console.WriteLine("A transaction has completed:");
			Console.WriteLine("ID:             {0}", e.Transaction.TransactionInformation.LocalIdentifier);
			Console.WriteLine("Distributed ID: {0}", e.Transaction.TransactionInformation.DistributedIdentifier);
			Console.WriteLine("Status:         {0}", e.Transaction.TransactionInformation.Status);
			Console.WriteLine("IsolationLevel: {0}", e.Transaction.IsolationLevel);
		}
	}
}