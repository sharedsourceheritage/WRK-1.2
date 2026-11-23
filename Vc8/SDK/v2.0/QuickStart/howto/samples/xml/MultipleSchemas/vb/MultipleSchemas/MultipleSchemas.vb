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

Public Class MultipleSchemasSample
    Public Shared Sub Main()
        Dim document As String = "..\books.xml"
        Dim schemaSet As New XmlSchemaSet()

        schemaSet.Add("http://www.example.org", "..\book.xsd")
        schemaSet.Add("http://www.example.org", "..\author.xsd")

        'Compile all schemas into a single logical schema 
        schemaSet.Compile()

        'Create XmlReader
        Dim settings As New XmlReaderSettings()
        settings.ValidationType = ValidationType.Schema
        settings.Schemas = schemaSet

        Using reader As XmlReader = XmlReader.Create(document, settings)
            'Input XML is validated then written out with the writer
            Using writer As XmlWriter = XmlWriter.Create(Console.Out)
                writer.WriteNode(reader, True)
            End Using
        End Using

        Console.WriteLine("Document successfully validated.")
        Console.WriteLine()
        Console.WriteLine("Press Enter to Exit")
        Console.ReadLine()

    End Sub
End Class