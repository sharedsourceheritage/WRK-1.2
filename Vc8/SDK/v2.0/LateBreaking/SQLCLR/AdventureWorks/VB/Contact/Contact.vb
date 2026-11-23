Imports System
Imports System.Data
Imports System.Data.Sql
Imports System.Data.SqlClient
Imports System.Data.SqlTypes
Imports System.IO
Imports System.Xml
Imports System.Collections
Imports System.Collections.Generic
Imports System.Globalization
Imports Microsoft.SqlServer.Server

'=====================================================================
'
'  File:    Contact.vb for Adventure Works Cycles SQLCLR Layer Sample
'  Summary: Defines the contact creation methods which are exposed as 
'			a single stored procedure in SQL Server.
'  Date:    April 30, 2004
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
''' Utility class for creating contact information.  A row in the contact table
''' is inserted.  Additionally, rows in one or more other tables are inserted based on
''' the information provided in the XML document passed to the CreateContact function.
''' For individuals and employees, the contact record is one to one relationship with 
''' the respective tables so those rows are created when the contact record is created.
''' For stores and vendors, there is a one to many relationship for contacts, so a row is added to 
''' either the Sales.StoreContact or Purchasing.VendorContact table (as appropriate), but 
''' neither store or vendor rows are inserted into the database.
''' 
''' </summary>
Public NotInheritable Class ContactUtils
    Private Sub New()
    End Sub

    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1045:DoNotPassTypesByReference")> _
    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1045:DoNotPassTypesByReference")> _
    <Microsoft.SqlServer.Server.SqlProcedure()> _
    Public Shared Sub CreateContact(ByVal contactData As SqlString, ByRef contactId As SqlInt32, ByRef customerId As SqlInt32)
        ' TODO: When we can pass XML from T-SQL then contactData can be a SqlXmlReader
        Dim reader As XmlReader = XmlReader.Create(New StringReader(contactData.Value))

        reader.MoveToContent()
        EnsureEqual(reader.LocalName, "Contact")
        reader.MoveToContent()
        reader.ReadStartElement()

        Dim creator As ContactCreator = Nothing

        Select Case reader.LocalName
            Case "Individual"
                creator = New IndividualCreator()

            Case "Store"
                creator = New StoreCreator()

            Case "Vendor"
                creator = New VendorCreator()

            Case "Employee"
                creator = New EmployeeCreator()

            Case Else
        End Select

        If (creator IsNot Nothing) Then
            reader.ReadStartElement()
            reader.MoveToContent()
            creator.LoadDictionary(reader)
            reader.Close()
            creator.Create()
            contactId = creator.ContactID
            customerId = creator.CustomerID
        Else
            contactId = -1
            customerId = -1

            Throw New AWUtilsContactParseException("Individual | Store | Vendor | Employee", reader.LocalName)
        End If
    End Sub

    Public Shared Sub EnsureEqual(ByVal localName As String, ByVal desiredLocalName As String)
        If Not localName.Equals(desiredLocalName) Then
            Throw New AWUtilsContactParseException(desiredLocalName, localName)
        End If
    End Sub
End Class
