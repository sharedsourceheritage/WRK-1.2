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
using System.Threading;

namespace Microsoft.Samples.Transactions.Dependent
{
	/// <summary>
	/// A simple usage of transactions with the using statement
	/// </summary>
	class DependentTx
	{
		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		static void Main(string[] args)
		{
			try
			{
				using (TransactionScope scope = new TransactionScope())
				{
					// Perform transactional work here.

					//Queue work item
					ThreadPool.QueueUserWorkItem(new WaitCallback(WorkerThread), Transaction.Current.DependentClone(DependentCloneOption.BlockCommitUntilComplete));

					//Print the transaction information
					Console.WriteLine("Transaction information:");
					Console.WriteLine("ID:             {0}", Transaction.Current.TransactionInformation.LocalIdentifier);
					Console.WriteLine("status:         {0}", Transaction.Current.TransactionInformation.Status);
					Console.WriteLine("isolationlevel: {0}", Transaction.Current.IsolationLevel);

					//Call complete on the TransactionScope or not based on input
					ConsoleKeyInfo c;
					while (true)
					{
						Console.Write("Complete the transaction scope? [Y|N] ");
						c = Console.ReadKey();
						Console.WriteLine();

						if ((c.KeyChar == 'Y') || (c.KeyChar == 'y'))
						{
							//Call complete on the scope
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

		private static void WorkerThread(object transaction)
		{
			//Create the DependentTransaction from the object passed to the WorkerThread
			DependentTransaction dTx = (DependentTransaction)transaction;

			//Sleep for 1 second to force the worker thread to delay
			Thread.Sleep(1000);

			//Pass the DependentTransaction to the scope so work done in the scope will be part of the transaction passed to the worker thread
			using (TransactionScope ts = new TransactionScope(dTx))
			{
				//Perform transactional work here.

				//Call complete on the transaction scope
				ts.Complete();
			}

			//Call complete on the dependent transaction
			dTx.Complete();
		}
	}
}
