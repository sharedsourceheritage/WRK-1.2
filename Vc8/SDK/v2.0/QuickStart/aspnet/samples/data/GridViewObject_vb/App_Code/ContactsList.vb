'-----------------------------------------------------------------------
'  This file is part of the Microsoft .NET SDK Code Samples.
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
Imports System.Data
Imports System.Configuration
Imports System.Web
Imports System.Web.Security
Imports System.Web.UI
Imports System.Web.UI.WebControls
Imports System.Web.UI.WebControls.WebParts
Imports System.Web.UI.HtmlControls
Imports System.Collections
Imports System.Collections.Generic

' <summary>
' Summary description for ContactsList
' </summary>
Public Class ContactsList

    Public Sub New()

        '
        ' TODO: Add constructor logic here
        '
    End Sub

    Public Function GetContacts(ByRef totalCount As Integer) As List(Of Contact)

        Dim connStr As String = ConfigurationManager.ConnectionStrings("Contacts").ConnectionString
        Dim s As SqlDataSource = New SqlDataSource(connStr, "select ContactID, ContactName from Contacts")
        Dim rows As IEnumerable = s.Select(DataSourceSelectArguments.Empty)

        Dim row As DataRowView
        Dim list As New List(Of Contact)
        For Each row In rows

            Dim Name As String = ""
            If Not row("ContactName") Is DBNull.Value Then
                Name = row("ContactName")
            End If

            list.Add(New Contact(row("ContactID"), Name))
        Next
        totalCount = list.Count
        Return list
    End Function

    Public Function UpdateContact(ByVal contactName As String, ByVal contactID As Integer) As Integer

        ' Update the contact name
        Dim s As New SqlDataSource
        s.ConnectionString = ConfigurationManager.ConnectionStrings("Contacts").ConnectionString
        s.UpdateCommand = "UpdateContactName"
        s.UpdateCommandType = SqlDataSourceCommandType.StoredProcedure
        s.UpdateParameters.Add(New Parameter("ID", TypeCode.Int32, contactID.ToString()))
        s.UpdateParameters.Add(New Parameter("Name", TypeCode.String, contactName))

        Dim rowsAffected As Integer = s.Update()

        ' Return the number of rows affected
        Return rowsAffected
    End Function
End Class


