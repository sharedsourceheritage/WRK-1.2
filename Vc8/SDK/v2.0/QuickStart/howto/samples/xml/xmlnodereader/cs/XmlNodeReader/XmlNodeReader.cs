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
    public class XmlNodeReaderSample
    {
        public static void Main()
        {
            string document = @"..\..\books.xml";

            // Load the XML from file
            Console.WriteLine();
            Console.WriteLine("Loading file {0} ...", document);

            XmlDocument xmlDocument = new XmlDocument();
            xmlDocument.Load(document);

            Console.WriteLine("XmlDocument loaded with XML data successfully ...");

            Console.WriteLine();
            Console.WriteLine("Create an XmlNodeReader to show the third book ...");
            Console.WriteLine();

            using (XmlNodeReader xmlNodeReader = 
                new XmlNodeReader(xmlDocument.SelectSingleNode("bookstore/book[3]")))
            {
                //Output reader to console
                XmlWriterSettings settings = new XmlWriterSettings();
                settings.Indent = true;

                using (XmlWriter writer = XmlWriter.Create(Console.Out, settings))
                {
                    writer.WriteNode(xmlNodeReader, true);
                }
            }

            Console.WriteLine();
            Console.WriteLine("Create an XmlNodeReader to show the second book ... ");
            Console.WriteLine();

            using (XmlNodeReader xmlNodeReader = 
                new XmlNodeReader(xmlDocument.SelectSingleNode("bookstore/book[2]")))
            {
                xmlNodeReader.Read();
                Console.WriteLine(xmlNodeReader.ReadInnerXml());
            }

            Console.WriteLine();
            Console.WriteLine("Press Enter to Exit");
            Console.ReadLine();
        }
    }
}
