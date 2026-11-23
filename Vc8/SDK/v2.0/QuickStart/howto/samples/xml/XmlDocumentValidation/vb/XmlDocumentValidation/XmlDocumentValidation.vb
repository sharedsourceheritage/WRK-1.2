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
Imports System.Xml
Imports System.Xml.Schema

Class XmlDocumentValidationSample
    Private Const xsd As String = "..\bookstore.xsd"
    Private Const document As String = "..\bookstore.xml"

    Public Shared Sub Main()
        'create XmlReader settings 
        Dim settings As New XmlReaderSettings()

        settings.Schemas.Add("urn:xmlns:25hoursaday-com:my-bookshelf", xsd)
        AddHandler settings.ValidationEventHandler, AddressOf ValidationCallback
        settings.ValidationType = ValidationType.Schema

        ' create an XML document and validate on load
        Dim doc As New XmlDocument()
        doc.Load(XmlReader.Create(document, settings))

        Dim nsmgr As New XmlNamespaceManager(New NameTable())
        nsmgr.AddNamespace("bk", "urn:xmlns:25hoursaday-com:my-bookshelf")

        'update part of the document with valid attribute
        Dim element As XmlElement = CType(doc.SelectSingleNode("//bk:book[bk:author='Adam Freeman']", nsmgr), XmlElement)
        element.SetAttribute("publisher", "MS Press")

        'validate the updated and add type information to underlying XmlDocument
        doc.Validate(New ValidationEventHandler(AddressOf ValidationCallback), element.ParentNode)

        'update part of the document with invalid attribute
        element = CType(doc.SelectSingleNode("//bk:book[bk:author='Adam Freeman']", nsmgr), XmlElement)
        element.SetAttribute("Discount", "20 percent")

        'validate the updated and add type information to underlying XmlDocument should fail
        doc.Validate(New ValidationEventHandler(AddressOf ValidationCallback), element.ParentNode)

        Console.WriteLine()
        Console.WriteLine("Press Enter to Exit")
        Console.ReadLine()
    End Sub

    Shared Sub ValidationCallback(ByVal sender As Object, ByVal args As ValidationEventArgs)
        Console.WriteLine("Validating")

        If args.Severity = XmlSeverityType.Warning Then
            Console.Write("WARNING: ")
        ElseIf args.Severity = XmlSeverityType.Error Then
            Console.Write("ERROR: ")
        End If
        Console.WriteLine(args.Message)
        ' Print the error to the screen.
    End Sub
End Class



