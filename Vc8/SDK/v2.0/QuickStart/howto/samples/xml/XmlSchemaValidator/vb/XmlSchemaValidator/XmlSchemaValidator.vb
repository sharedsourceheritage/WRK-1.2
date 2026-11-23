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
Imports System.Xml.Serialization
Imports System.IO
Imports System.Xml
Imports System.Xml.Schema

Class XmlSchemaValidatorSample
    Private Const document As String = "..\books.xml"
    Private Const xsdDocument As String = "..\books.xsd"

    Public Shared Sub Main() 
        Dim schemaInfo As New XmlSchemaInfo()
        Dim serializer As XmlSerializer = Nothing
        Dim myBooks As Books = Nothing

        Using reader As StreamReader = New StreamReader(document)
            serializer = New XmlSerializer(GetType(Books))
            myBooks = CType(serializer.Deserialize(reader), Books)
        End Using

        Dim xsv As XmlSchemaValidator = CreateValidator()
        xsv.Initialize()

        xsv.ValidateElement("books", "http://www.example.com/my-bookshelf", schemaInfo)

        xsv.ValidateEndOfAttributes(schemaInfo)

        Dim book As bookType
        For Each book In myBooks.book
            xsv.ValidateElement("book", "http://www.example.com/my-bookshelf", schemaInfo)

            If Not (book.publisher Is Nothing) Then
                xsv.ValidateAttribute("publisher", String.Empty, book.publisher, schemaInfo)
            End If
            If Not (book.onloan Is Nothing) Then
                xsv.ValidateAttribute("on-loan", String.Empty, book.onloan, schemaInfo)
            End If
            xsv.ValidateEndOfAttributes(schemaInfo)

            xsv.ValidateElement("title", "http://www.example.com/my-bookshelf", schemaInfo)
            xsv.ValidateEndElement(Nothing, book.title)

            xsv.ValidateElement("author", "http://www.example.com/my-bookshelf", schemaInfo)
            xsv.ValidateEndElement(Nothing, book.author)

            xsv.ValidateElement("publication-date", "http://www.example.com/my-bookshelf", schemaInfo)
            xsv.ValidateEndElement(Nothing, book.publicationdate)

            xsv.ValidateEndElement(schemaInfo)
        Next book

        xsv.ValidateEndElement(schemaInfo)

        xsv.EndValidation()

        Console.WriteLine("Schema validated.")
        Console.WriteLine()
        Console.WriteLine("Press Enter to Exit")
        Console.ReadLine()
    End Sub

    Public Shared Function CreateValidator() As XmlSchemaValidator 
        Dim nt As New NameTable()
        
        Dim schemaSet As New XmlSchemaSet()
        schemaSet.Add("http://www.example.com/my-bookshelf", xsdDocument)
        
        Dim nsmgr As New XmlNamespaceManager(nt)
        
        Dim flags As XmlSchemaValidationFlags = XmlSchemaValidationFlags.None
        
        Return New XmlSchemaValidator(nt, schemaSet, nsmgr, flags)
    
    End Function
End Class

<System.Xml.Serialization.XmlRootAttribute("books", [Namespace]:="http://www.example.com/my-bookshelf", IsNullable:=False)> _
Public Class Books
    <System.Xml.Serialization.XmlElementAttribute("book")> _
    Public book() As BookType
End Class

Public Class bookType

    Public title As String

    Public author As String

    <System.Xml.Serialization.XmlElementAttribute("publication-date", DataType:="date")> _
    Public publicationdate As System.DateTime

    Public price As System.Decimal

    <System.Xml.Serialization.XmlAttributeAttribute("publisher")> _
    Public publisher As String

    <System.Xml.Serialization.XmlAttributeAttribute("on-loan")> _
    Public onloan As String
End Class