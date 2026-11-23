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
Imports System.Data
Imports System.Data.SqlClient

Namespace Microsoft.Samples

	Public NotInheritable Class CommittableTxWithSQL

		Public Shared Sub Main()

			Dim tx As CommittableTransaction
			tx = Nothing

			Try
				tx = New CommittableTransaction

				Using myConnection As New SqlConnection("server=(local)\SQLExpress;Integrated Security=SSPI;database=northwind")
					Dim myCommand As New SqlCommand()

					'Open the SQL connection
					myConnection.Open()

					'Give the transaction to SQL to enlist with
					myConnection.EnlistTransaction(tx)

					myCommand.Connection = myConnection

					'Restore database to near it's original condition so sample will work correctly.
					myCommand.CommandText = "DELETE FROM Region WHERE (RegionID = 100) OR (RegionID = 101)"
					myCommand.ExecuteNonQuery()

					'Insert the first record.
					myCommand.CommandText = "Insert into Region (RegionID, RegionDescription) VALUES (100, 'MidWestern')"
					myCommand.ExecuteNonQuery()

					'Insert the second record.
					myCommand.CommandText = "Insert into Region (RegionID, RegionDescription) VALUES (101, 'MidEastern')"
					myCommand.ExecuteNonQuery()

					'Commit or rollback the transaction
					Dim c As ConsoleKeyInfo
					While (True)
            	        Console.Write("Commit or Rollback? [C|R] ")
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

				End Using
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
				Console.WriteLine("Cannot complete transaction")
				Throw
			End Try
		End Sub
	End Class
End Namespace