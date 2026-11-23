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

Public Class ValidationReadingXMLSample
    Private Const document1 As String = "..\booksDTD.xml"
    Private Const document2 As String = "..\booksDTDFail.xml"
    Private Const document3 As String = "..\booksSchema.xml"
    Private Const document4 As String = "..\booksSchemaFail.xml"
    Private Const document5 As String = "..\schema.xsd"
    Private Success As Boolean = True

    Public Shared Sub Main()
        Dim validationReadingXMLSample As New ValidationReadingXMLSample()
        validationReadingXMLSample.Run()
    End Sub

    Public Sub Run()
        Success = True
        Dim settings As New XmlReaderSettings()

        AddHandler settings.ValidationEventHandler, AddressOf Me.ValidationEventHandler

        'Validate the valid XML with the XSD 
        Console.WriteLine("Validating XML file booksSchema.xml with schema file schema.xsd ...")

        settings.ValidationType = ValidationType.Schema
        settings.Schemas.Add("schema.xsd", XmlReader.Create(document5))

        Using XmlValidatingReader As XmlReader = XmlReader.Create(document3, settings)
            While XmlValidatingReader.Read()
            End While
        End Using

        Console.WriteLine("Validation finished. Validation {0}", IIf(Success = True, "successful", "failed")) 'TODO: For performance reasons this should be changed to nested IF statements

        'Validate the invalid XML with the XSD 
        Console.WriteLine("Validating XML file booksSchema.xml with schema file schema.xsd ...")
        Using XmlValidatingReader As XmlReader = XmlReader.Create(document4, settings)
            While XmlValidatingReader.Read()
            End While
        End Using

        Console.WriteLine("Validation finished. Validation {0}", IIf(Success = True, "successful", "failed")) 'TODO: For performance reasons this should be changed to nested IF statements
        Console.WriteLine()
        Console.WriteLine("Press Enter to Exit")
        Console.ReadLine()
    End Sub

    Public Sub ValidationEventHandler(ByVal sender As Object, ByVal args As ValidationEventArgs)
        Success = False

        Console.WriteLine(vbTab + "Validation error: " + args.Message)

        If args.Severity = XmlSeverityType.Warning Then
            Console.WriteLine("No schema found to enforce validation.")
        ElseIf args.Severity = XmlSeverityType.Error Then
            Console.WriteLine("Error occurred during validation.")
        End If

        If Not (args.Exception Is Nothing) Then ' XSD schema validation error
            Console.WriteLine(args.Exception.SourceUri + "," & args.Exception.LinePosition & "," & args.Exception.LineNumber)
        End If
    End Sub
End Class
