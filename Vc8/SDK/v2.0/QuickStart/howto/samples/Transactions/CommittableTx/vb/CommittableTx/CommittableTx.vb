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

Namespace Microsoft.Samples

	Public NotInheritable Class CommittableTx

		Public Shared Sub Main()

			Dim arguments As [String]() = Environment.GetCommandLineArgs()

			If arguments.Length <= 1 Then
				Console.WriteLine("Usage CreateTx <option [1-2]>:")
				Console.WriteLine("1 - new CommittableTransaction")
				Console.WriteLine("2 - new CommittableTransaction with options")
				Exit Sub
			End If

			Dim tx As CommittableTransaction
			tx = Nothing	    

			Dim options As New TransactionOptions()

			Try
				Select Case arguments(1)
					Case "1"
						tx = New CommittableTransaction()
					Case "2"
						options.IsolationLevel = IsolationLevel.ReadCommitted
						'30 second timeout
						options.Timeout = New TimeSpan(0, 0, 30)
						tx = New CommittableTransaction(options)
					Case Else
						Console.WriteLine("Usage CommittableTx <option [1-2]:")
						Console.WriteLine("1 - Transaction.Create()")
						Console.WriteLine("2 - Transaction.Create(...) with options")
						Exit Sub
				End Select

				'Perform transactional work here

				'Transaction information
				Console.WriteLine("Transaction information:")
				Console.WriteLine("ID:             {0}", tx.TransactionInformation.LocalIdentifier)
				Console.WriteLine("Status:         {0}", tx.TransactionInformation.Status)
				Console.WriteLine("IsolationLevel: {0}", tx.IsolationLevel)

				'Commit or rollback the transaction
				Dim c As ConsoleKeyInfo
				While (True)
					Console.Write("Commit or Rollback? [C|R]")
					c = Console.ReadKey()
					Console.WriteLine()

					If (c.KeyChar = "C") Or (c.KeyChar = "c") Then
						tx.Commit()
						Exit While
					ElseIf ((c.KeyChar = "R") Or (c.KeyChar = "r")) Then
						tx.Rollback()
						Exit While
					End If

				End While

				Console.WriteLine("Transaction Information:")
				Console.WriteLine("Status:         {0}", tx.TransactionInformation.Status)

				tx = Nothing

			Catch ex As TransactionException
				'Call rollback inside the catch block
				If tx <> Nothing Then
				tx.Rollback()
				End If
				Console.WriteLine(ex)

			Catch
				'Call rollback inside the catch block
				If tx <> Nothing Then
				tx.Rollback()
				End If
				Throw
			End Try
		End Sub
	End Class
End Namespace