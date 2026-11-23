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
	// A simple usage of transactions with the using statement
	class VolatileEnlist
	{
		static void Main(string[] args)
		{
			try
			{
				using (TransactionScope scope = new TransactionScope())
				{
					//Create an enlistment object
					myEnlistmentClass myElistment = new myEnlistmentClass();

					//Enlist on the current transaction with the enlistment object
					Transaction.Current.EnlistVolatile(myElistment, EnlistmentOptions.None);

					//Perform transactional work here.

					//Call complete on the TransactionScope or not based on inputt
					ConsoleKeyInfo c;
					while(true)
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

		class myEnlistmentClass : IEnlistmentNotification
		{
			public void Prepare(PreparingEnlistment preparingEnlistment)
			{
				Console.WriteLine("Prepare notification received");

				//Do work to be included in the transaction

				//If work finished correctly, reply prepared
				preparingEnlistment.Prepared();
			}

			public void Commit(Enlistment enlistment)
			{
				Console.WriteLine("Commit notification received");

				//Do any work needed when receiving commit notification

				//Declare done on the enlistment
				enlistment.Done();
			}

			public void Rollback(Enlistment enlistment)
			{
				Console.WriteLine("Rollback notification received");

				//Do any work needed when receiving a rollback notification

				//Declare done on the enlistment
				enlistment.Done();
			}

			public void InDoubt(Enlistment enlistment)
			{
				Console.WriteLine("In doubt notification received");

				//Do any work needed in case of in doubt notification
				
				//Declare done on the enlistment
				enlistment.Done();
			}
		}
	}
}
