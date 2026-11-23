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
    public class XmlDocumentEventSample
    {
        private const string document = @"..\..\books.xml";

        public static void Main()
        {
            XmlDocumentEventSample xmlDocumentEventSample = new XmlDocumentEventSample();

            xmlDocumentEventSample.Run(document);
        }

        public void Run(String args)
        {
            Console.WriteLine();
            Console.WriteLine("Loading file {0} ...", args);

            XmlDocument xmlDocument = new XmlDocument();
                
            // Load the XML from file
            xmlDocument.Load(args);

            //Add MyEvent Handlers here
            xmlDocument.NodeChanged += new XmlNodeChangedEventHandler(this.NodeChangedEvent);
            xmlDocument.NodeInserted += new XmlNodeChangedEventHandler(this.NodeInsertedEvent);

            Console.WriteLine("XmlDocument loaded with XML data successfully ...");

            // Increase all the book prices by 2%
            Console.WriteLine();
            Console.WriteLine("Increase all the book prices by 2% ...");
            Console.WriteLine();

            // Create a list of the <book> nodes and change their values
            XmlNodeList xmlNodeList = xmlDocument.SelectNodes("descendant::book/price");

            foreach (XmlNode xmlNode in xmlNodeList)
            {
                Console.WriteLine("<" + xmlNode.Name + "> " + xmlNode.InnerText);
                Double price = Double.Parse(xmlNode.InnerText);
                xmlNode.InnerText = (((Double)price * 1.02).ToString("#.00"));
            }

            Console.WriteLine();
            Console.WriteLine("Adding a new book to the XmlDocument ...");
            Console.WriteLine();

            // Create a new book
            XmlDocumentFragment newBook = xmlDocument.CreateDocumentFragment();

            newBook.InnerXml = ("<book genre=\" Object-Orientated Technology \" publicationdate=\" 1994 \" " +
                "ISBN=\"0-201-63361-2\">" +
                "<title>Design Patterns - Elements of Reusable Object-Orientated Software</title>" +
                "<author>" +
                "<first-name>Eric</first-name>" +
                "<last-name>Gamma</last-name>" +
                "</author>" +
                "<price>49.95</price>" +
                "</book>");

            XmlElement rootXmlElement = xmlDocument.DocumentElement;

            // Add the new book to the XmlDocument
            rootXmlElement.InsertBefore(newBook, rootXmlElement.FirstChild);

            Console.WriteLine();
            Console.WriteLine("Cloning the first book node in the XmlDocument ...");
            Console.WriteLine();


            // Clone the node and note that by cloning the node we
            // are inserting it again into the XmlDocument
            XmlNode newBook2 = xmlDocument.DocumentElement.FirstChild.Clone();
        
            Console.WriteLine();
            Console.WriteLine("Press Enter to Exit");
            Console.ReadLine();
        }

        // Handle the Node Changed Event
        public void NodeChangedEvent(Object src, XmlNodeChangedEventArgs args)
        {
            Console.Write("Node Changed Event: <" + args.Node.Name + "> changed");
            if (args.Node.Value != null)
            {
                Console.WriteLine(" with value " + args.Node.Value);
            }
            else
            {
                Console.WriteLine("");
            }
        }

        // Handle the Node Inserted Event
        public void NodeInsertedEvent(Object src, XmlNodeChangedEventArgs args)
        {
            Console.Write("Node Inserted Event: <" + args.Node.Name + "> inserted");
            if (args.Node.Value != null)
            {
                Console.WriteLine(" with value " + args.Node.Value);
            }
            else
            {
                Console.WriteLine("");
            }
        }
    } 
} 