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

Class XmlReadWriteSample

    Shared Sub Main()
        Dim writerSettings As New XmlWriterSettings()
        writerSettings.Indent = True

        Dim readerSettings As New XmlReaderSettings()
        readerSettings.IgnoreWhitespace = True

        Using writer As XmlWriter = XmlWriter.Create(Console.Out, writerSettings)
            Using reader As XmlReader = XmlReader.Create("../books.xml", readerSettings)
                While Not reader.EOF
                    If reader.IsStartElement("price") Then
                        'read the original value
                        Dim originalPrice As Double = 0.0
                        Try
                            originalPrice = reader.ReadElementContentAsDouble()
                        Catch
                            'catch invalid values <price/> and <price></price>
                            'set price to zero
                            originalPrice = 0.0
                        End Try
                        Dim discountedPrice As Double = originalPrice - originalPrice * 0.25
                        writer.WriteStartElement("price")
                        writer.WriteAttributeString("alternative", "25% discount")
                        writer.WriteAttributeString("originalPrice", originalPrice.ToString())
                        writer.WriteValue(discountedPrice)
                        writer.WriteEndElement()
                    Else
                        WriteShallowNode(reader, writer)
                        reader.Read()
                    End If
                End While
            End Using
        End Using

        Console.WriteLine()
        Console.WriteLine("Press Enter to Exit")
        Console.ReadLine()

    End Sub

    'This method is useful for streaming transformation with the 
    'XmlReader and the XmlWriter. It pushes through single nodes in the stream
    Shared Sub WriteShallowNode(ByVal reader As XmlReader, ByVal writer As XmlWriter)
        If reader Is Nothing Then
            Throw New ArgumentNullException("reader")
        End If
        If writer Is Nothing Then
            Throw New ArgumentNullException("writer")
        End If

        Select Case reader.NodeType
            Case XmlNodeType.Element
                writer.WriteStartElement(reader.Prefix, reader.LocalName, reader.NamespaceURI)
                writer.WriteAttributes(reader, True)
                If reader.IsEmptyElement Then
                    writer.WriteEndElement()
                End If
            Case XmlNodeType.Text
                writer.WriteString(reader.Value)
            Case XmlNodeType.Whitespace, XmlNodeType.SignificantWhitespace
                writer.WriteWhitespace(reader.Value)
            Case XmlNodeType.CDATA
                writer.WriteCData(reader.Value)
            Case XmlNodeType.EntityReference
                writer.WriteEntityRef(reader.Name)
            Case XmlNodeType.XmlDeclaration, XmlNodeType.ProcessingInstruction
                writer.WriteProcessingInstruction(reader.Name, reader.Value)
            Case XmlNodeType.DocumentType
                writer.WriteDocType(reader.Name, reader.GetAttribute("PUBLIC"), reader.GetAttribute("SYSTEM"), reader.Value)
            Case XmlNodeType.Comment
                writer.WriteComment(reader.Value)
            Case XmlNodeType.EndElement
                writer.WriteFullEndElement()
        End Select

    End Sub
End Class