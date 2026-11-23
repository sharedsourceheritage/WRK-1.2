//-----------------------------------------------------------------------
//  This file is part of the Microsoft .NET SDK Code Samples.
// 
//  Copyright (C) Microsoft Corporation.  All rights reserved.
// 
//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.
// 
//THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.
//-----------------------------------------------------------------------

using System;
using System.Xml;

namespace Microsoft.Samples.Xml 
{
    class ModifyXmlDocumentSample
    {
        static void Main()
        {
            XmlDocument doc = new XmlDocument();
            
            //Load XML file
            doc.Load("../../books.xml");
            Console.WriteLine("books.xml:");
            doc.Save(Console.Out);
                        
            //delete the individual with book with title=The Gorgias
            DeleteBook(doc);
            Console.WriteLine("After Delete:");
            doc.Save(Console.Out);

            //add a new individual with book with title='Moby Dick'
            InsertBook(doc);
            Console.WriteLine("After Insert:");
            doc.Save(Console.Out);

            //increase the price of all books by 20%
            ModifyPrice(doc);
            Console.WriteLine("After Modify:");
            doc.Save(Console.Out);

            //Save as a new xml file
            doc.Save("books.new.xml");

            Console.WriteLine();
            Console.WriteLine("Press Enter to Exit");
            Console.ReadLine();
        }

        static void ModifyPrice(XmlDocument doc)
        {
            foreach (XmlNode node in doc.SelectNodes("//price"))
            {
                node.InnerText = (XmlConvert.ToDouble(node.InnerText) * 1.2).ToString();
            }
        }

        static void DeleteBook(XmlDocument doc)
        {
            string xpath = "/bookstore/book[title='The Gorgias']";
            XmlNode node = doc.SelectSingleNode(xpath);
            node.ParentNode.RemoveChild(node);
        }

        static void InsertBook(XmlDocument doc)
        {
            XmlNode bookstore = doc.DocumentElement;

            XmlElement book = doc.CreateElement("book");
            book.SetAttribute("genre", "novel");
            book.SetAttribute("publicationdate", "1998");
            book.SetAttribute("ISBN", "0-553-21311-03");

            XmlElement title = doc.CreateElement("title");
            title.InnerText = "Moby Dick";
            book.AppendChild(title);

            XmlElement author = doc.CreateElement("author");
            XmlElement firstname = doc.CreateElement("first-name");
            firstname.InnerText = "Herman";
            XmlElement lastname = doc.CreateElement("last-name");
            lastname.InnerText = "Melville";
            author.AppendChild(firstname);
            author.AppendChild(lastname);
            book.AppendChild(author);

            XmlElement price = doc.CreateElement("price");
            price.InnerText = "12.99";
            book.AppendChild(price);

            bookstore.AppendChild(book);
        }
    }
}
