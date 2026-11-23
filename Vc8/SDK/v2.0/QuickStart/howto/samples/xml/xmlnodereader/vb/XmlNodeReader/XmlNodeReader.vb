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

Public Class XmlNodeReaderSample

    Public Shared Sub Main()
        Dim document As String = "..\books.xml"

        ' Load the XML from file
        Console.WriteLine()
        Console.WriteLine("Loading file {0} ...", document)

        Dim xmlDocument As New XmlDocument()
        xmlDocument.Load(document)

        Console.WriteLine("XmlDocument loaded with XML data successfully ...")

        Console.WriteLine()
        Console.WriteLine("Create an XmlNodeReader to show the third book ...")
        Console.WriteLine()

        Using xmlNodeReader As Xml.XmlNodeReader = New _
            Xml.XmlNodeReader(xmlDocument.SelectSingleNode("bookstore/book[3]"))

            'Output reader to console
            Dim settings As New XmlWriterSettings()
            settings.Indent = True
            Using writer As XmlWriter = XmlWriter.Create(Console.Out, settings)
                writer.WriteNode(xmlNodeReader, True)
            End Using
        End Using

        Console.WriteLine()
        Console.WriteLine("Create an XmlNodeReader to show the second book ... ")
        Console.WriteLine()

        Using xmlNodeReader As Xml.XmlNodeReader = New _
            Xml.XmlNodeReader(xmlDocument.SelectSingleNode("bookstore/book[2]"))

            xmlNodeReader.Read()
            Console.WriteLine(xmlNodeReader.ReadInnerXml())
        End Using
        
        Console.WriteLine()
        Console.WriteLine("Press Enter to Exit")
        Console.ReadLine()
    End Sub
End Class