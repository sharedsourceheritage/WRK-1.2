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
Imports System.Xml.Xsl

Class ExtensionObjectSample
    Public Shared Sub Main()
        Dim filename As String = "..\number.xml"
        Dim stylesheet As String = "..\circle.xsl"
        'Create XslCompiledTransform and compile stylesheet.
        Dim processor As New XslCompiledTransform()

        processor.Load(stylesheet)

        'Create an XsltArgumentList
        Dim xslArg As New XsltArgumentList()

        'Add an object to calculate the circumference of the circle.
        Dim obj As New Calculate()
        xslArg.AddExtensionObject("urn:myObj", obj)

        'Create an XmlWriter to output to the console.   
        Using writer As XmlWriter = XmlWriter.Create(Console.Out)
            'Transform the file.
            processor.Transform(filename, xslArg, writer)
        End Using

        Console.WriteLine(vbLf + vbLf + "Press Enter to Exit")
        Console.ReadLine()
    End Sub

    'Calculates the circumference of a circle given the radius.
    Public Class Calculate
        Public Function Circumference(ByVal radius As Double) As Double
            Return Math.PI * 2 * radius
        End Function
    End Class
End Class