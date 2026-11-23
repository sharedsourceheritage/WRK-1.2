Imports System
Imports System.Data
Imports System.Data.Sql
Imports System.Data.SqlClient
Imports System.Data.SqlTypes
Imports Microsoft.SqlServer.Server
'=====================================================================
'
'  File:    CustomerCreator.vb for Adventure Works Cycles SQLCLR Layer Sample
'  Summary: The class which implements the insertion of various rows in various tables to 
'           create contact information for customers of Adventure Works Cycles.
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
'''		A base class based on ContactCreator which is responsible for inserting information about
'''		a customer by inserting a row in the 
'''		Sales.Customer table.  Currently only used by the IndividualCreator class, but
'''		it might be useful if there was a variant made of the StoreCreator which actually inserted
'''		a Sales.Store row. 
''' </summary>

Public MustInherit Class CustomerCreator
    Inherits ContactCreator

    Protected Sub New()
    End Sub

    Public Overrides Sub Create()
        MyBase.Create()
        Using conn As New SqlConnection("context connection=true")
            Dim command As SqlCommand = conn.CreateCommand()

            If Not contactDictionary.ContainsKey("CustomerType") Then
                contactDictionary("CustomerType") = "I"
            End If

            ResetCounters(0)

            Dim parameters As String = String.Format( _
                System.Globalization.CultureInfo.InvariantCulture, _
                "{0}{1}{2}", _
                MaybeParameter("SalesPersonID"), _
                MaybeParameter("TerritoryID"), _
                MaybeParameter("CustomerType"))
            ' CustomerType is always present, but we need to get the commas right
            Dim values As String = String.Format( _
                System.Globalization.CultureInfo.InvariantCulture, _
                "{0}{1}{2}", _
                MaybeValue("SalesPersonID"), _
                MaybeValue("TerritoryID"), _
                MaybeValue("CustomerType"))

            command.CommandText = String.Format( _
                System.Globalization.CultureInfo.InvariantCulture, _
                "INSERT INTO Sales.Customer ({0}) VALUES ({1}); SELECT CAST(SCOPE_IDENTITY() as Int);", _
                parameters, values)
            MaybeAddCommandParameter("SalesPersonID", command, SqlDbType.Int, False, Nothing)
            MaybeAddCommandParameter("TerritoryID", command, SqlDbType.Int, False, Nothing)
            MaybeAddCommandParameter("CustomerType", command, SqlDbType.NChar, 1, True, "I")
            conn.Open()
            Me.CustomerID = CType(command.ExecuteScalar(), Integer)
        End Using
    End Sub
End Class
