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
Imports System.Xml.Xsl

Public Class TransformXMLSample
    Private Const document1 As String = "..\books.xml"
    Private Const document2 As String = "..\ProcessParametersA.xml"
    Private Const document3 As String = "..\ProcessParametersB.xml"
    Private Const styleSheet1 As String = "..\books.xsl"
    Private Const styleSheet2 As String = "..\StyleSheetGenerator.xsl"
    Private Const output1 As String = "..\table.html"
    Private Const output2 As String = "..\transform2.xsl"
    Private Const output3 As String = "..\transform3.xsl"

    ' 
    'add <?xml-stylesheet type="text/xsl" href="transform2.xsl" ?> to books.xml to view transform using transform2.xsl
    'add <?xml-stylesheet type="text/xsl" href="transform3.xsl" ?> to books.xml to view transform using transform3.xsl
    '

    Public Shared Sub Main()
        Dim transformXMLSample As New TransformXMLSample()
        Console.WriteLine(vbLf + vbLf + "*********Output from the first transform:*********" + vbLf + vbLf)
        Dim args1 As String() = {document1, styleSheet1, output1}
        transformXMLSample.Run(args1)

        Console.WriteLine(vbLf + vbLf + "*********Output from the second transform:*********" + vbLf + vbLf)
        Dim args2 As String() = {document2, styleSheet2, output2}
        transformXMLSample.Run(args2)

        Console.WriteLine(vbLf + vbLf + "*********Output from the third transform:*********" + vbLf + vbLf)
        Dim args3 As String() = {document3, styleSheet2, output3}
        transformXMLSample.Run(args3)
        Console.Write("Press Enter to Exit")
        Console.ReadLine()
    End Sub

    Public Sub Run(ByVal args() As String)
        Console.WriteLine()
        Console.WriteLine("Read XML data file, transform and format display ...")
        Console.WriteLine()

        ReadTransform(args)

        Console.WriteLine()
        Console.WriteLine("Read XML data file, transform and write ...")
        Console.WriteLine()

        ReadTransformWrite(args)
        Console.WriteLine()
    End Sub

    Public Sub ReadTransform(ByVal args() As String)
        Dim processor As New XslCompiledTransform(True)
        processor.Load(args(1))
        'Transform the file.
        processor.Transform(args(0), Nothing, Console.Out)
    End Sub

    Public Sub ReadTransformWrite(ByVal args() As String)
        Using stream As FileStream = File.Open(args(2), FileMode.Create)
            'Create XsltCommand and compile stylesheet.
            Dim processor As New XslCompiledTransform()
            processor.Load(args(1))
            'Transform the file.
            processor.Transform(args(0), Nothing, stream)
        End Using
    End Sub
End Class