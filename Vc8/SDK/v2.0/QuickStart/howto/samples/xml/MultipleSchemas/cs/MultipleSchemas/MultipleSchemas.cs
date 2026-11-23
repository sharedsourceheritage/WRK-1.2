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
using System.Xml.Schema;

namespace Microsoft.Samples.Xml
{
    public class MultipleSchemasSample
    {
        static void Main()
        {
            string document = @"..\..\books.xml";
            XmlSchemaSet schemaSet = new XmlSchemaSet();

            schemaSet.Add("http://www.example.org", @"..\..\book.xsd");
            schemaSet.Add("http://www.example.org", @"..\..\author.xsd");

            //Compile all schemas into a single logical schema 
            schemaSet.Compile(); 

            //Create XmlReader
            XmlReaderSettings settings = new XmlReaderSettings();
            settings.ValidationType = ValidationType.Schema;
            settings.Schemas = schemaSet;

            using (XmlReader reader = XmlReader.Create(document, settings))
            {
                //Input XML is validated then written out with the writer
                using (XmlWriter writer = XmlWriter.Create(Console.Out))
                {
                    writer.WriteNode(reader, true);
                }
            }
        
            Console.WriteLine("Document successfully validated.");
            Console.WriteLine();
            Console.WriteLine("Press Enter to Exit");
            Console.ReadLine(); 
        }
    }
}