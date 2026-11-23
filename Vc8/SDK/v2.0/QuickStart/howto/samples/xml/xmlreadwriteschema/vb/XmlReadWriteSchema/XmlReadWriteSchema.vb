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
Imports System.IO
Imports System.Xml
Imports System.Xml.Schema

Public Class XmlReadWriteSchemaSample

    Public Shared Sub Main()
        'Schema to read from
        Dim document As String = "..\sample.xsd"
        Dim schema As XmlSchema = Nothing

        'Set writer properties with WriterSettings
        Dim settings As New XmlWriterSettings()
        settings.Indent = True

        Using stringWriter As StringWriter = New StringWriter()
            'Create XmlWriter 		
            Using writer As XmlWriter = XmlWriter.Create(stringWriter, settings)

                'Read the Schema
                Console.WriteLine("Reading schema {0} ...", document)
                Console.WriteLine()
                schema = XmlSchema.Read(XmlReader.Create(document), Nothing)

                'Write the Schema
                Console.WriteLine("Writing schema {0} ...", document)
                Console.WriteLine()
                schema.Write(writer)
                Console.WriteLine(stringWriter.ToString())
            End Using
        End Using

        Console.WriteLine()
        Console.WriteLine("Press Enter to Exist")
        Console.ReadLine()
    End Sub
End Class