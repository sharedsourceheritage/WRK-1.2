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
// The statements below needed for the ComVisible and AssemblyVersion Attributes
using System.Reflection;
using System.Runtime.InteropServices;
using System.EnterpriseServices;

[assembly: CLSCompliant(true)]
[assembly: ApplicationAccessControl(true)]
[assembly: AssemblyVersionAttribute("1.2.3.4")]

namespace Microsoft.Samples.Transactions.Quickstarts
{

	// Shows how to create a EnterpriseServices component using a System.Transactions
	class UsingBYOT
	{
		static void Main(string[] args)
		{
			System.EnterpriseServices.ITransaction estx = null;

			try
			{
				using (TransactionScope scope = new TransactionScope ())
				{
					// Convert the transaction object to make it compatible with EnterpriseService transactions (required for ADO.NET)
					estx = (System.EnterpriseServices.ITransaction) TransactionInterop.GetDtcTransaction(Transaction.Current);
					SvcComp sc = (SvcComp) BYOT.CreateWithTransaction(estx, typeof(SvcComp));

					sc.DisplayTransactionState();

					//Call complete or not based on input
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
			finally
			{
				estx = null;
			}
		}
	}


	//The service component
	[Transaction]
	public class SvcComp : ServicedComponent
	{
		public void DisplayTransactionState()
		{
			//Print information from ContextUtil
			Console.WriteLine("IsInTransaction   {0}", ContextUtil.IsInTransaction);
			Console.WriteLine("TransactionId     {0}", ContextUtil.TransactionId);
		}
	}
}
