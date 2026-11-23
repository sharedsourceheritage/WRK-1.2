//-----------------------------------------------------------------------
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
//-----------------------------------------------------------------------

using System;
using System.Text;
using System.Transactions;

namespace Microsoft.Samples.Transactions.TransactionScopeSample
{
	class TransactionScopeSample
	{
		static void Main(string[] args)
		{
			try
			{
				using (TransactionScope scope = new TransactionScope())
				{
					// Perform transactional work here.

					// Transaction information
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
	}
}
