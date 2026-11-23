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
    class XmlDocumentValidationSample
    {
        private const string xsd = @"..\..\bookstore.xsd";
        private const string document = @"..\..\bookstore.xml";

        public static void Main()
        {
            //create XmlReader settings 
            XmlReaderSettings settings = new XmlReaderSettings();

            settings.Schemas.Add("urn:xmlns:25hoursaday-com:my-bookshelf", xsd);
            settings.ValidationEventHandler += new ValidationEventHandler(ValidationCallback);
            settings.ValidationType = ValidationType.Schema;

            // create an XML document and validate on load
            XmlDocument doc = new XmlDocument();
            doc.Load(XmlReader.Create(document, settings));

            XmlNamespaceManager nsmgr = new XmlNamespaceManager(new NameTable());
            nsmgr.AddNamespace("bk", "urn:xmlns:25hoursaday-com:my-bookshelf");

            //update part of the document with valid attribute
            XmlElement element = (XmlElement)doc.SelectSingleNode("//bk:book[bk:author='Adam Freeman']", nsmgr);
            element.SetAttribute("publisher", "MS Press");

            //validate the updated and add type information to underlying XmlDocument
            doc.Validate(new ValidationEventHandler(ValidationCallback), element.ParentNode);

            //update part of the document with invalid attribute
            element = (XmlElement)doc.SelectSingleNode("//bk:book[bk:author='Adam Freeman']", nsmgr);
            element.SetAttribute("Discount", "20 percent");

            //validate the updated and add type information to underlying XmlDocument should fail
            doc.Validate(new ValidationEventHandler(ValidationCallback), element.ParentNode);

            Console.WriteLine();
            Console.WriteLine("Press Enter to Exit");
            Console.ReadLine();
        }

        static void ValidationCallback(object sender, ValidationEventArgs args)
        {
            Console.WriteLine("Validating");

            if (args.Severity == XmlSeverityType.Warning)
            {
                Console.Write("WARNING: ");
            }
            else if (args.Severity == XmlSeverityType.Error)
            {
                Console.Write("ERROR: ");
            }

            Console.WriteLine(args.Message); // Print the error to the screen.
        }
    }
}




