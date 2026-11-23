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
using System.Xml.XPath;

namespace Microsoft.Samples.Xml
{
    public class XPathWithXmlDocSample
    {
        public static void Main()
        {
            // Schema to read from
            string document = @"..\..\books.xml";
            String exprString = String.Empty;
            XmlDocument myXmlDocument = new XmlDocument();

            // Create a new XmlDocument for the specified source file and load it.
            myXmlDocument.Load(document);

            // Create an XmlNamespaceManager and add the namespaces for the document.
            XmlNamespaceManager nsmanager = new XmlNamespaceManager(myXmlDocument.NameTable);

            // Map namespaces to prefixes for querying purposes.
            nsmanager.AddNamespace("ns", "http://tempuri.org/myBooksNamespace");
            nsmanager.AddNamespace("myns", "http://tempuri.org/myBooksProcessornamespace");
            nsmanager.AddNamespace("yourns1", "http://tempuri.org/myBook1namespace");
            nsmanager.AddNamespace("yourns2", "http://tempuri.org/myBook2namespace");

            //SelectNodes ...
            XmlNodeList nodelist = myXmlDocument.SelectNodes("//yourns1:book", nsmanager);
            foreach (XmlNode xmlNode in nodelist)
            {
                DisplayTree(xmlNode);
            }

            nodelist = myXmlDocument.SelectNodes("//ns:book", nsmanager);
            foreach (XmlNode xmlNode in nodelist)
            {
                DisplayTree(xmlNode);
            }
            Console.WriteLine();
            Console.WriteLine("Press Enter to Exit");
            Console.ReadLine();
        }


        static void DisplayTree(XmlNode node)
        {
            if (node != null)
                Format(node);

            if (node.HasChildNodes)
            {
                node = node.FirstChild;
                while (node != null)
                {
                    DisplayTree(node);
                    node = node.NextSibling;
                }
            }
        }

        // Format the output
        static void Format(XmlNode node)
        {
            if (!node.HasChildNodes)
                Console.WriteLine("\t" + node.Value);

            else
            {
                Console.Write(node.Name);
                if (XmlNodeType.Element == node.NodeType)
                {
                    XmlNamedNodeMap map = node.Attributes;
                    foreach (XmlNode attrnode in map)
                        Console.Write(" " + attrnode.Name + "<" + attrnode.Value + "> ");
                }
            }
        }
    } 
} 

