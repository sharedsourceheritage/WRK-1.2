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
using System.IO;
using System.Xml;

namespace Microsoft.Samples.Xml 
{
    public class ReadXmlStreamSample
    {
        static void Main()
        {
            Console.WriteLine("Using StringReader ...");

            using (StringReader stream = new StringReader("<?xml version='1.0'?>" +
                "<!-- This file represents a fragment of a book store inventory database -->" +
                "<bookstore>" +
                " <book genre=\"autobiography\" publicationdate=\"1981\" ISBN=\"1-861003-11-0\">" +
                "   <title>The Autobiography of Benjamin Franklin</title>" +
                "   <author>" +
                "       <first-name>Benjamin</first-name>" +
                "       <last-name>Franklin</last-name>" +
                "   </author>" +
                "   <price>8.99</price>" +
                " </book>" +
                " <book genre=\"novel\" publicationdate=\"1967\" ISBN=\"0-201-63361-2\">" +
                "   <title>The Confidence Man</title>" +
                "   <author>" +
                "       <first-name>Herman</first-name>" +
                "       <last-name>Melville</last-name>" +
                "   </author>" +
                "   <price>11.99</price>" +
                " </book>" +
                "  <book genre=\"philosophy\" publicationdate=\"1991\" ISBN=\"1-861001-57-6\">" +
                "   <title>The Gorgias</title>" +
                "   <author>" +
                "       <name>Plato</name>" +
                "   </author>" +
                "   <price>9.99</price>" +
                " </book>" +
                "</bookstore>")
                )
            {

                //Create XmlReader and load reader from stream
                using (XmlReader reader = XmlReader.Create(stream))
                {
                    //Output reader to console
                    using (XmlWriter writer = XmlWriter.Create(Console.Out))
                    {
                        writer.WriteNode(reader, true);
                    }
                }
            }
            Console.WriteLine();
            Console.WriteLine("Processing of stream complete.");
            Console.WriteLine();
            Console.WriteLine("Press Enter to Exit");
            Console.ReadLine();
        }
    }
}
