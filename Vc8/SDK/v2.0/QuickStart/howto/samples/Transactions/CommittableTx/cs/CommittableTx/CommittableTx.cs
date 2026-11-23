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

	// Shows how to create transactions using an explicit model.
	class CommittableTx
	{
		static void Main(string[] args)
		{
			CommittableTransaction tx = null;
			TransactionOptions options = new TransactionOptions();

			if (args.Length == 0)
			{
				Console.WriteLine("Usage CommittableTx <option [1-2]:");
				Console.WriteLine("1 - Transaction.Create()");
				Console.WriteLine("2 - Transaction.Create(...) with options");
				return;
			}
			try
			{
				switch (args[0])
				{
					case "1":
						tx = new CommittableTransaction();
						break;
					case "2":
						options.IsolationLevel = IsolationLevel.ReadCommitted;
						//30 second timeout
						options.Timeout = new TimeSpan(0, 0, 30);
						tx = new CommittableTransaction(options);
						break;
					default:
						Console.WriteLine("Usage CommittableTx <option [1-2]>:");
						Console.WriteLine("1 - new CommittableTransaction");
						Console.WriteLine("2 - new CommittableTransaction with options");
						return;
				}

				// Perform transactional work here

				// Transaction information
				Console.WriteLine("Transaction information:");
				Console.WriteLine("ID:             {0}", tx.TransactionInformation.LocalIdentifier);
				Console.WriteLine("Status:         {0}", tx.TransactionInformation.Status);
				Console.WriteLine("IsolationLevel: {0}", tx.IsolationLevel);

				// Commit or rollback the transaction
				while (true)
				{
					Console.Write("Commit or Rollback? [C|R] ");
					ConsoleKeyInfo c = Console.ReadKey();
					Console.WriteLine();

					if ((c.KeyChar == 'C') || (c.KeyChar == 'c'))
					{
						tx.Commit();
						break;
					}
					else if ((c.KeyChar == 'R') || (c.KeyChar == 'r'))
					{
						tx.Rollback();
						break;
					}
				}

				Console.WriteLine("Transaction Information:");
				Console.WriteLine("Status:         {0}", tx.TransactionInformation.Status);

				tx = null;

			}
			catch (System.Transactions.TransactionException ex)
			{
				//Call rollback inside the catch block
				if (tx != null)
					tx.Rollback();
				Console.WriteLine(ex);
			}
			catch
			{
				//Call rollback inside the catch block
				if (tx != null)
					tx.Rollback();
				Console.WriteLine("Cannot complete transaction");
				throw;
			}
		}
	}
}