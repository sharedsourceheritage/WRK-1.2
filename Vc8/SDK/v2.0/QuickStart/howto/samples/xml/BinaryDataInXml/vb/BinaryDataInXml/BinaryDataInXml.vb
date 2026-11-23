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
Imports System.IO

Public Class BinaryDataInXmlSample   
    Shared Sub Main()
        Dim buffer2() As Byte
        Dim found As Integer

        ' First we create a binary blob of data in a byte array
        ' initializing the bytes to the values 1 through 10.
        Dim buffer() As Byte = New [Byte](9) {}
        Dim i As Integer
        For i = 0 To 9
            buffer(i) = System.Convert.ToByte(i)
        Next i
        ' Now we write an XML stream to a StringWriter using the
        ' WriteBase64 method on the XmlWriter.
        Using sw As StringWriter = New StringWriter()
            Using writer As XmlWriter = XmlWriter.Create(sw)
                writer.WriteStartElement("Test")
                writer.WriteAttributeString("Length", buffer.Length.ToString())
                writer.WriteCData(Convert.ToBase64String(buffer, 0, buffer.Length))
                writer.WriteEndElement()
            End Using

            ' This will produce the following output:
            ' <Test Length="10"><![CDATA[AAECAwQFBgcICQ==]]></Test>
            Console.WriteLine(sw.ToString())

            ' It looks like garbage - but it is correct base 64 encoding of the
            ' binary data.  To prove it, we'll read it back in using the XmlReader
            ' First position reader on <Test> element and get the Length attribute
            ' Next position reader on <Test> element and get the Length attribute
            Using reader As XmlReader = XmlReader.Create(New StringReader(sw.ToString()))
                reader.Read()
                reader.Read()
                reader.MoveToAttribute("Length")
                Dim len As Integer = reader.ReadContentAsInt()
                reader.MoveToElement()
                ' Allocate a buffer of the correct length and call ReadBase64.
                buffer2 = New Byte(len) {}
                found = reader.ReadElementContentAsBase64(buffer2, 0, len)
            End Using

            ' Now output the byte values and see what we get
            ' Notice this produces the correct result:
            '  "0,1,2,3,4,5,6,7,8,9"
            Dim j As Integer
            For j = 0 To found - 1
                Console.Write(buffer2(j))
                If j < found - 1 Then
                    Console.Write(",")
                End If
            Next j
        End Using

        Console.WriteLine()
        Console.WriteLine("Press Enter to Exit")
        Console.ReadLine()
    End Sub
End Class