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

Imports System.Transactions
Imports System

Namespace Microsoft.Samples

	Public NotInheritable Class TransactionScopeSample

		Public Shared Sub Main()

			Try
				Using scope As TransactionScope = New TransactionScope()
					'Perform transactional work here.

					'Transaction information
					Console.WriteLine("Transaction information:")
					Console.WriteLine("ID:             {0}", Transaction.Current.TransactionInformation.LocalIdentifier)
					Console.WriteLine("status:         {0}", Transaction.Current.TransactionInformation.Status)
					Console.WriteLine("isolationlevel: {0}", Transaction.Current.IsolationLevel)

					'Call complete on the TransactionScope or not based on input
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
			End Try
		End Sub
	End Class
End Namespace