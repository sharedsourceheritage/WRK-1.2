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

Public Class ReadXmlStreamSample

    Shared Sub Main()

        Console.WriteLine("Using StringReader ...")

        Using stream As StringReader = New StringReader("<?xml version='1.0'?>" + _
            "<!-- This file represents a fragment of a book store inventory database -->" + _
            "<bookstore>" + _
            " <book genre=""autobiography"" publicationdate=""1981"" ISBN=""1-861003-11-0"">" + _
            "   <title>The Autobiography of Benjamin Franklin</title>" + "   <author>" + _
            "       <first-name>Benjamin</first-name>" + "       <last-name>Franklin</last-name>" + _
            "   </author>" + "   <price>8.99</price>" + " </book>" + _
            " <book genre=""novel"" publicationdate=""1967"" ISBN=""0-201-63361-2"">" + _
            "   <title>The Confidence Man</title>" + "   <author>" + _
            "       <first-name>Herman</first-name>" + _
            "       <last-name>Melville</last-name>" + "   </author>" + _
            "   <price>11.99</price>" + " </book>" + _
            "  <book genre=""philosophy"" publicationdate=""1991"" ISBN=""1-861001-57-6"">" + _
            "   <title>The Gorgias</title>" + "   <author>" + _
            "       <name>Plato</name>" + "   </author>" + "   <price>9.99</price>" + _
            " </book>" + "</bookstore>")

            'Create XmlReader and load reader from stream
            Using reader As XmlReader = XmlReader.Create(stream)
                'Output reader to console
                Using writer As XmlWriter = XmlWriter.Create(Console.Out)
                    writer.WriteNode(reader, True)
                End Using
            End Using
        End Using

        Console.WriteLine()
        Console.WriteLine("Processing of stream complete.")
        Console.WriteLine()
        Console.WriteLine("Press Enter to Exit")
        Console.ReadLine()
    End Sub
End Class