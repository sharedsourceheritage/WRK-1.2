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
Imports System.Xml.XPath

Public Class XPathWithXmlDocSample

    Public Shared Sub Main()
        ' Schema to read from
        Dim document As String = "..\books.xml"
        Dim exprString As String = String.Empty

        ' Create a new XmlDocument for the specified source file and load it.
        Dim myXmlDocument As New XmlDocument()

        myXmlDocument.Load(document)

        ' Create an XmlNamespaceManager and add the namespaces for the document.
        Dim nsmanager As New XmlNamespaceManager(myXmlDocument.NameTable)

        ' Map namespaces to prefixes for querying purposes.
        nsmanager.AddNamespace("ns", "http://tempuri.org/myBooksNamespace")
        nsmanager.AddNamespace("myns", "http://tempuri.org/myBooksProcessornamespace")
        nsmanager.AddNamespace("yourns1", "http://tempuri.org/myBook1namespace")
        nsmanager.AddNamespace("yourns2", "http://tempuri.org/myBook2namespace")

        'SelectNodes ...
        Dim nodelist As XmlNodeList = myXmlDocument.SelectNodes("//yourns1:book", nsmanager)
        Dim xmlNode As XmlNode
        For Each xmlNode In nodelist
            DisplayTree(xmlNode)
        Next xmlNode

        nodelist = myXmlDocument.SelectNodes("//ns:book", nsmanager)

        For Each xmlNode In nodelist
            DisplayTree(xmlNode)
        Next xmlNode

        Console.WriteLine()
        Console.WriteLine("Press Enter to Exit")
        Console.ReadLine()

    End Sub

    Shared Sub DisplayTree(ByVal node As XmlNode)
        If Not (node Is Nothing) Then
            Format(node)
        End If
        If node.HasChildNodes Then
            node = node.FirstChild
            While Not (node Is Nothing)
                DisplayTree(node)
                node = node.NextSibling
            End While
        End If

    End Sub

    Shared Sub Format(ByVal node As XmlNode)
        If Not node.HasChildNodes Then
            Console.WriteLine(vbTab + node.Value)

        Else
            Console.Write(node.Name)
            If XmlNodeType.Element = node.NodeType Then
                Dim map As XmlNamedNodeMap = node.Attributes
                Dim attrnode As XmlNode
                For Each attrnode In map
                    Console.Write(" " + attrnode.Name + "<" + attrnode.Value + "> ")
                Next attrnode
            End If
        End If
    End Sub
End Class
