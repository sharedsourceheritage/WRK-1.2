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
Imports System.Globalization
Imports System.Xml
Imports System.Xml.XPath

Public Class XPathWithXPathDocSample
    Private Const document As String = "..\books.xml"


    Public Shared Sub Main()
        Dim xPathExpressionSample As New XPathWithXPathDocSample()
        xPathExpressionSample.Run(document)

    End Sub 'Main


    Public Sub Run(ByVal args As String)

        Dim selectExpr As String = String.Empty

        Dim xPathExpr As XPathExpression

        Console.WriteLine()
        Console.WriteLine("XPathExpression started ...")
        Console.WriteLine()

        Dim xPathDocument As New XPathDocument(args)

        'Create an XPathNavigator
        Dim xPathNavigator As XPathNavigator = xPathDocument.CreateNavigator()

        'Get the Book elements
        selectExpr = "bookstore/book"

        Console.WriteLine("XPath query: " + selectExpr)

        'Ensure we are at the root node
        xPathNavigator.MoveToRoot()

        xPathExpr = xPathNavigator.Compile(selectExpr)

        Console.WriteLine()
        Console.WriteLine("Original order ...")
        Console.WriteLine()

        'Create an XPathNodeIterator to walk over the selected nodes
        Dim xPathNodeIterator As XPathNodeIterator = xPathNavigator.Select(xPathExpr)

        FormatXml(xPathNodeIterator)

        ' Ensure we are at the root node
        xPathNavigator.MoveToRoot()

        Console.WriteLine()
        Console.WriteLine("Sort by ISBN (using IComparer - Text ascending)...")
        Console.WriteLine()

        ' Add a comparer to do a string compare on the ISBN number
        xPathExpr.AddSort("@ISBN", StringComparer.Create(CultureInfo.InvariantCulture, True))
        xPathNodeIterator = xPathNavigator.Select(xPathExpr)

        FormatXml(xPathNodeIterator)

        ' Create Second XPathNavigator
        Dim xPathNavigator2 As XPathNavigator = xPathDocument.CreateNavigator()

        ' Ensure we are at the root node
        xPathNavigator2.MoveToRoot()
        xPathExpr = xPathNavigator2.Compile(selectExpr)

        Console.WriteLine()
        Console.WriteLine("Sort by publication date (using XSLT expression - Text descending) ...")
        Console.WriteLine()

        ' Add an XSLT based sort
        xPathExpr.AddSort("@publicationdate", XmlSortOrder.Descending, XmlCaseOrder.None, "", XmlDataType.Text)
        xPathNodeIterator = xPathNavigator2.Select(xPathExpr)

        FormatXml(xPathNodeIterator)

        Dim doc As New XmlDocument()
        doc.Load(args)

        'Navigate with the DOM API
        Dim nodes As XmlNodeList = doc.ChildNodes

        Console.WriteLine("Writing with Navigate with DOM APIs")
        NavigateWithDom(nodes)

        'create an XpathNavigator on XmlDocument
        Dim nav As XPathNavigator = doc.CreateNavigator()

        'Navigate with XpathNavigator API
        Console.WriteLine("Writing with Navigate with Navigator APIs")
        NavigateWithNavigator(nav)

        Console.WriteLine("Press Enter to Exit")
        Console.ReadLine()
    End Sub

    Private Sub FormatXml(ByVal nav As XPathNodeIterator)
        ' Loop getting information about each node
        While nav.MoveNext()
            Select Case nav.Current.NodeType
                Case XPathNodeType.ProcessingInstruction
                    Format(nav, "ProcessingInstruction")
                Case XPathNodeType.Comment
                    Format(nav, "Comment")
                Case XPathNodeType.Element
                    Format(nav, "Element")
                Case XPathNodeType.Text
                    Format(nav, "Text")
                Case XPathNodeType.Whitespace
                    Format(nav, "Whitespace")
            End Select
        End While

        Console.WriteLine()

    End Sub

    Private Sub Format(ByVal nav As XPathNodeIterator, ByVal nodeType As String)
        If nav.Current.HasAttributes Then
            Console.Write("<" + nav.Current.Name)

            nav.Current.MoveToFirstAttribute()

            Console.Write(" " + nav.Current.Name + "=" + nav.Current.Value)

            While nav.Current.MoveToNextAttribute()
                Console.Write(" " + nav.Current.Name + "=" + nav.Current.Value)
            End While
            Console.Write(">")
        End If
        ' Return to the 'Parent' node of the attributes
        nav.Current.MoveToParent()
        Console.WriteLine("")
    End Sub

    Public Shared Sub NavigateWithDom(ByVal children As XmlNodeList)
        If Not (children Is Nothing) Then
            Dim i As Integer
            While i < children.Count
                Dim node As XmlNode = children(i)
                Dim name As String = node.Name
                Dim value As String = node.Value

                If name.Equals("title") OrElse name.Equals("author") OrElse name.Equals("price") Then
                    Console.Write(name + ": ")
                Else
                    Console.WriteLine(value)
                End If

                Dim attributes As XmlAttributeCollection = node.Attributes
                If Not (attributes Is Nothing) Then
                    Dim j As Integer
                    While j < attributes.Count
                        Dim attName As String = attributes(j).Name
                        If attName.Equals("publisher") Then
                            Console.WriteLine(attName + ": " + attributes(j).Value)
                        End If
                        j = j + 1
                    End While
                End If
                NavigateWithDom(node.ChildNodes)
                i = i + 1
            End While
        End If
    End Sub

    Public Shared Sub NavigateWithNavigator(ByVal nav As XPathNavigator)
        'move to the first non PI no comment element
        nav.MoveToChild(XPathNodeType.Element)

        'get all the books
        Dim booksNodeIt As XPathNodeIterator = nav.SelectChildren(XPathNodeType.Element)

        While booksNodeIt.MoveNext()
            Dim nav1 As XPathNavigator = booksNodeIt.Current
            nav1.MoveToFirstAttribute()
            Dim publisher As String = nav1.Value
            Dim attName As String = nav1.Name
            nav1.MoveToParent()

            Dim nodeIt As XPathNodeIterator = nav1.SelectChildren(XPathNodeType.Element)

            While nodeIt.MoveNext()
                Console.WriteLine(nodeIt.Current.Name + ": " + nodeIt.Current.Value + vbTab)
            End While

            Console.WriteLine(attName + ": " + publisher + vbLf + vbLf)
        End While
    End Sub
End Class