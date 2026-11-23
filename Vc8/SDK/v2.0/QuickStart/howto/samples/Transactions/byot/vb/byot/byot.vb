'-----------------------------------------------------------------------
'  This file is part of the Microsoft .NET Framework SDK Code Samples.
' 
'  Copyright (C) Microsoft Corporation.  All rights reserved.
' 
'This source code is intended only as a supplement to Microsoft
'Development Tools and/or on-line documentation.  See these other
'materials for detailed information regarding Microsoft code samples.
' 
'THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
'KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
'IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A 
'PARTICULAR PURPOSE.
'-----------------------------------------------------------------------

Imports System
Imports System.Transactions
Imports System.EnterpriseServices
Imports System.Runtime.InteropServices

Namespace Microsoft.Samples

	Public NotInheritable Class UsingBYOT

		Public Shared Sub Main()
			Dim estx As System.EnterpriseServices.ITransaction

			Try
				Using scope As TransactionScope = New TransactionScope

					'Convert the transaction object to make it compatible with EnterpriseService transactions (required for ADO.NET)
					estx = CType(TransactionInterop.GetDtcTransaction(Transaction.Current), System.EnterpriseServices.ITransaction)
					Dim sc As SvcComp = New SvcComp
					System.EnterpriseServices.BYOT.CreateWithTransaction(estx, sc.GetType)

					sc.DisplayTransactionState()

					'Call complete or not based on input
					Dim c As ConsoleKeyInfo
					While (True)

						Console.Write("Complete the transaction scope? [Y|N] ")
						c = Console.ReadKey()
						Console.WriteLine()
						If (c.KeyChar = "Y") Or (c.KeyChar = "y") Then
							scope.Complete()
							Exit While
						ElseIf ((c.KeyChar = "N") Or (c.KeyChar = "n")) Then
							Exit While
						End If
					End While
				End Using
			Catch ex As TransactionException
				Console.WriteLine(ex)
			Catch
				Console.WriteLine("Cannot complete transaction")
				Throw
			Finally
				estx = nothing
			End Try
		End Sub
	End Class

	<Transaction()> Public Class SvcComp
	Inherits ServicedComponent

		Public Sub DisplayTransactionState()
			Console.WriteLine("IsInTransaction   {0}", ContextUtil.IsInTransaction)
			Console.WriteLine("TransactionId     {0}", ContextUtil.TransactionId)
		End Sub
	End Class
End Namespace
