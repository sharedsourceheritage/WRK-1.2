Imports System
Imports System.Data
Imports System.Data.Sql
Imports System.Data.SqlTypes
Imports System.Data.SqlClient
Imports Microsoft.SqlServer.Server

'=====================================================================
'
'  File:    IndividualCreator.vb for Adventure Works Cycles SQLCLR Layer Sample
'  Summary: The class which implements the insertion of various rows in various tables to 
'           create contact information for non-corporate customers of Adventure Works Cycles.
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
'''		Responsible for adding information about an individual purchasing by 
'''		inserting a row in the Sales.Individual table.
''' </summary>

Public Class IndividualCreator
    Inherits CustomerCreator

    Public Overrides Sub Create()
        MyBase.Create()
        Using conn As New SqlConnection("context connection=true")
            Dim command As SqlCommand = conn.CreateCommand()

            ResetCounters(2)
            Dim parameters As String = String.Format( _
                System.Globalization.CultureInfo.InvariantCulture, _
                "CustomerID, ContactID{0}", MaybeParameter("Demographics"))
            Dim values As String = String.Format( _
                System.Globalization.CultureInfo.InvariantCulture, _
                "@CustomerID, @ContactID{0}", MaybeValue("Demographics"))
            command.CommandText = String.Format( _
                System.Globalization.CultureInfo.InvariantCulture, _
                "INSERT INTO Sales.Individual ({0}) VALUES ({1});", parameters, values)
            MaybeAddCommandParameter("CustomerID", command, SqlDbType.Int, True, String.Empty)
            MaybeAddCommandParameter("ContactID", command, SqlDbType.Int, True, String.Empty)
            MaybeAddCommandParameter("Demographics", command, SqlDbType.Xml, False, Nothing)
            conn.Open()
            command.ExecuteNonQuery()
        End Using
    End Sub
End Class
