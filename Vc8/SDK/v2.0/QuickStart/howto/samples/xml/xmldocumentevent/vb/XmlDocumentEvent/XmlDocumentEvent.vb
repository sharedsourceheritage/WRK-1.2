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

Public Class XmlDocumentEventSample
    Private Const document As String = "..\books.xml"

    Public Shared Sub Main()
        Dim xmlDocumentEventSample As New XmlDocumentEventSample()

        xmlDocumentEventSample.Run(document)
    End Sub

    Public Sub Run(ByVal args As String)
        Console.WriteLine()
        Console.WriteLine("Loading file {0} ...", args)

        Dim xmlDocument As New XmlDocument()

        ' Load the XML from file
        xmlDocument.Load(args)

        'Add MyEvent Handlers here
        AddHandler xmlDocument.NodeChanged, AddressOf Me.NodeChangedEvent
        AddHandler xmlDocument.NodeInserted, AddressOf Me.NodeInsertedEvent

        Console.WriteLine("XmlDocument loaded with XML data successfully ...")

        ' Increase all the book prices by 2%
        Console.WriteLine()
        Console.WriteLine("Increase all the book prices by 2% ...")
        Console.WriteLine()

        ' Create a list of the <book> nodes and change their values
        Dim xmlNodeList As XmlNodeList = xmlDocument.SelectNodes("descendant::book/price")

        Dim xmlNode As XmlNode
        For Each xmlNode In xmlNodeList
            Console.WriteLine("<" + xmlNode.Name + "> " + xmlNode.InnerText)
            Dim price As [Double] = [Double].Parse(xmlNode.InnerText)
            xmlNode.InnerText = (CType(price, [Double]) * 1.02).ToString("#.00")
        Next xmlNode

        Console.WriteLine()
        Console.WriteLine("Adding a new book to the XmlDocument ...")
        Console.WriteLine()

        ' Create a new book
        Dim newBook As XmlDocumentFragment = xmlDocument.CreateDocumentFragment()

        newBook.InnerXml = "<book genre="" Object-Orientated Technology "" publicationdate="" 1994 "" " + "ISBN=""0-201-63361-2"">" + "<title>Design Patterns - Elements of Reusable Object-Orientated Software</title>" + "<author>" + "<first-name>Eric</first-name>" + "<last-name>Gamma</last-name>" + "</author>" + "<price>49.95</price>" + "</book>"

        Dim rootXmlElement As XmlElement = xmlDocument.DocumentElement

        ' Add the new book to the XmlDocument
        rootXmlElement.InsertBefore(newBook, rootXmlElement.FirstChild)

        Console.WriteLine()
        Console.WriteLine("Cloning the first book node in the XmlDocument ...")
        Console.WriteLine()

        ' Clone the node and note that by cloning the node we
        ' are inserting it again into the XmlDocument
        Dim newBook2 As XmlNode = xmlDocument.DocumentElement.FirstChild.Clone()

        Console.WriteLine()
        Console.WriteLine("Press Enter to Exit")
        Console.ReadLine()
    End Sub

    ' Handle the Node Changed Event
    Public Sub NodeChangedEvent(ByVal src As [Object], ByVal args As XmlNodeChangedEventArgs)
        Console.Write("Node Changed Event: <" + args.Node.Name + "> changed")
        If Not (args.Node.Value Is Nothing) Then
            Console.WriteLine(" with value " + args.Node.Value)
        Else
            Console.WriteLine("")
        End If
    End Sub

    ' Handle the Node Inserted Event
    Public Sub NodeInsertedEvent(ByVal src As [Object], ByVal args As XmlNodeChangedEventArgs)
        Console.Write("Node Inserted Event: <" + args.Node.Name + "> inserted")
        If Not (args.Node.Value Is Nothing) Then
            Console.WriteLine(" with value " + args.Node.Value)
        Else
            Console.WriteLine("")
        End If
    End Sub
End Class