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
using System.Xml.Schema;

namespace Microsoft.Samples.Xml 
{
    public class XmlReadWriteSchemaSample
    {
        public static void Main()
        {
            //Schema to read from
            string document = @"..\..\sample.xsd";
            XmlSchema schema = null;
            
            //Create a stringwriter for output
            using(StringWriter stringWriter = new StringWriter())
            {

            //Set writer properties with WriterSettings
            XmlWriterSettings settings = new XmlWriterSettings();
            settings.Indent = true;
            
                //Create XmlWriter         
                using (XmlWriter writer = XmlWriter.Create(stringWriter, settings))
                {
                    //Read the Schema
                    Console.WriteLine("Reading schema {0} ...", document);
                    Console.WriteLine();
                    schema = XmlSchema.Read(XmlReader.Create(document), null);

                    //Write the Schema
                    Console.WriteLine("Writing schema {0} ...", document);
                    Console.WriteLine();
                    schema.Write(writer);
                    Console.WriteLine(stringWriter.ToString());
                }

            }
            
            Console.WriteLine();
            Console.WriteLine("Press Enter to Exit");
            Console.ReadLine();
        }
    }
}
