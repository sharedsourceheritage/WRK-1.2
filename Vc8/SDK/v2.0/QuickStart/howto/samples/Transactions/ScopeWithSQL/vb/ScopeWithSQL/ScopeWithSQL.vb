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

	Public NotInheritable Class ScopeWithSQL

		Public Shared Sub Main()
			Try
				Using scope As TransactionScope = New TransactionScope()

					'Create and open the SQL connection.  The work done on this connection will be a part of the transaction created by the TransactionScope
					Using myConnection As New SqlConnection("server=(local)\SQLExpress;Integrated Security=SSPI;database=northwind")
						Dim myCommand As New SqlCommand()
						myConnection.Open()
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

					End Using

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