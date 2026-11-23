Imports System
Imports System.Data
Imports System.Data.Sql
Imports System.Data.SqlClient
Imports System.Data.SqlTypes
Imports Microsoft.SqlServer.Server

'=====================================================================
'
'  File:    StoreCreator.vb for Adventure Works Cycles SQLCLR Layer Sample
'  Summary: The class which implements the insertion of various rows in various tables to 
'           create contact information for corporate customers of Adventure Works Cycles.
'  Date:    May 25, 2004
'
'---------------------------------------------------------------------
'
'  This file is part of the Microsoft SQL Server Code Samples.
'  Copyright (C) Microsoft Corporation.  All rights reserved.
'
' This source code is intended only as a supplement to Microsoft
' Development Tools and/or on-line documentation.  See these other
' materials for detailed information regarding Microsoft code samples.
'
' THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
' KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
' IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
' PARTICULAR PURPOSE.
'
'======================================================= 

''' <summary>
'''		Responsible for relating a contact to a store by inserting a row in the 
'''		Sales.StoreContact table.
''' </summary>
Public Class StoreCreator
    Inherits ContactCreator

    Public Overrides Sub Create()
        MyBase.Create()
        Using conn As New SqlConnection("context connection=true")

            Dim command As SqlCommand = conn.CreateCommand()

            command.CommandText = String.Format( _
                System.Globalization.CultureInfo.InvariantCulture, _
                "INSERT INTO Sales.StoreContact (CustomerID, ContactID, ContactTypeID) VALUES (@CustomerID, @ContactID, @ContactTypeID);")
            MaybeAddCommandParameter("CustomerID", command, SqlDbType.Int, True, String.Empty)
            MaybeAddCommandParameter("ContactID", command, SqlDbType.Int, True, String.Empty)
            MaybeAddCommandParameter("ContactTypeID", command, SqlDbType.TinyInt, True, String.Empty)
            conn.Open()
            command.ExecuteNonQuery()
        End Using
    End Sub
End Class
