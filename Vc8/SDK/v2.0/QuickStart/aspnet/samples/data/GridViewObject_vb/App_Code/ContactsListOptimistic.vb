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
' Summary description for ContactsListOptimistic
' </summary>
Public Class ContactsListOptimistic

    Public Sub New()

        '
        ' TODO: Add constructor logic here
        '
    End Sub

    Public Function GetContacts() As List(Of Contact)

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
        Return list
    End Function

    Public Function GetContact(ByVal contactID As Integer) As Contact

        Dim connStr As String = ConfigurationManager.ConnectionStrings("Contacts").ConnectionString
        Dim s As SqlDataSource = New SqlDataSource(connStr, "select ContactID, ContactName from Contacts where ContactID = @ContactID")
        s.SelectParameters.Add(New Parameter("contactID", TypeCode.Int32, contactID.ToString()))
        Dim rows As IEnumerable = s.Select(DataSourceSelectArguments.Empty)

        Dim row As DataRowView
        Dim list As New List(Of Contact)
        For Each row In rows
            Return New Contact(row("ContactID"), row("ContactName"))
        Next
        Return Nothing
    End Function

    Public Function UpdateContact(ByVal contactName As String, ByVal original_contactID As Integer, ByVal original_contactName As String) As Integer

        ' Update the contact name
        Dim s As New SqlDataSource
        s.ConnectionString = ConfigurationManager.ConnectionStrings("Contacts").ConnectionString
        s.UpdateCommand = "UpdateContact"
        s.UpdateCommandType = SqlDataSourceCommandType.StoredProcedure

        s.UpdateParameters.Add(New Parameter("contactName", TypeCode.String, contactName))
        s.UpdateParameters.Add(New Parameter("original_contactID", TypeCode.Int32, original_contactID.ToString()))
        s.UpdateParameters.Add(New Parameter("original_contactName", TypeCode.String, original_contactName))

        Dim rowsAffected As Integer = s.Update()

        ' Return the number of rows affected
        Return rowsAffected
    End Function

    Public Function DeleteContact(ByVal original_contactID As Integer, ByVal original_contactName As String) As Integer

        ' Delete the contact
        Dim s As New SqlDataSource
        s.ConnectionString = ConfigurationManager.ConnectionStrings("Contacts").ConnectionString
        s.UpdateCommand = "DeleteContact"
        s.UpdateCommandType = SqlDataSourceCommandType.StoredProcedure

        s.DeleteParameters.Add(New Parameter("original_contactID", TypeCode.Int32, original_contactID.ToString()))
        s.DeleteParameters.Add(New Parameter("original_contactName", TypeCode.String, original_contactName))

        Dim rowsAffected As Integer = s.Delete()

        ' Return the number of rows affected
        Return rowsAffected
    End Function

    Public Function UpdateContact(ByVal c As Contact, ByVal original_c As Contact) As Integer

        HttpContext.Current.Response.Write("UpdateContact(Contact c, Contact original_c)")
        Return UpdateContact(c.ContactName, original_c.ContactID, original_c.ContactName)
    End Function

    Public Function DeleteContact(ByVal original_c As Contact) As Integer

        HttpContext.Current.Response.Write("DeleteContact(Contact original_c)")
        Return DeleteContact(original_c.ContactID, original_c.ContactName)
    End Function
End Class
