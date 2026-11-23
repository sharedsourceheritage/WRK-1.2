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

Class ModifyXmlDocumentSample 
    Shared Sub Main()
        Dim doc As New XmlDocument()

        'Load XML file
        doc.Load("../books.xml")
        Console.WriteLine("books.xml:")
        doc.Save(Console.Out)

        'delete the individual with book with title=The Gorgias
        DeleteBook(doc)
        Console.WriteLine("After Delete:")
        doc.Save(Console.Out)

        'add a new individual with book with title='Moby Dick'
        InsertBook(doc)
        Console.WriteLine("After Insert:")
        doc.Save(Console.Out)

        'increase the price of all books by 20%
        ModifyPrice(doc)
        Console.WriteLine("After Modify:")
        doc.Save(Console.Out)

        'Save as a new xml file
        doc.Save("books.new.xml")

        Console.WriteLine()
        Console.WriteLine("Press Enter to Exit")
        Console.ReadLine()
    End Sub

    Shared Sub ModifyPrice(ByVal doc As XmlDocument)
        Dim node As XmlNode
        For Each node In doc.SelectNodes("//price")
            node.InnerText = (XmlConvert.ToDouble(node.InnerText) * 1.2).ToString()
        Next node
    End Sub

    Shared Sub DeleteBook(ByVal doc As XmlDocument)
        Dim xpath As String = "/bookstore/book[title='The Gorgias']"
        Dim node As XmlNode = doc.SelectSingleNode(xpath)
        node.ParentNode.RemoveChild(node)
    End Sub

    Shared Sub InsertBook(ByVal doc As XmlDocument)
        Dim bookstore As XmlNode = doc.DocumentElement

        Dim book As XmlElement = doc.CreateElement("book")
        book.SetAttribute("genre", "novel")
        book.SetAttribute("publicationdate", "1998")
        book.SetAttribute("ISBN", "0-553-21311-03")

        Dim title As XmlElement = doc.CreateElement("title")
        title.InnerText = "Moby Dick"
        book.AppendChild(title)

        Dim author As XmlElement = doc.CreateElement("author")
        Dim firstname As XmlElement = doc.CreateElement("first-name")
        firstname.InnerText = "Herman"
        Dim lastname As XmlElement = doc.CreateElement("last-name")
        lastname.InnerText = "Melville"
        author.AppendChild(firstname)
        author.AppendChild(lastname)
        book.AppendChild(author)

        Dim price As XmlElement = doc.CreateElement("price")
        price.InnerText = "12.99"
        book.AppendChild(price)

        bookstore.AppendChild(book)
    End Sub
End Class