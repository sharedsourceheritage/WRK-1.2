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
    public class ValidationReadingXMLSample
    {
        private const string document1 = @"..\..\booksDTD.xml";
        private const string document2 = @"..\..\booksDTDFail.xml";
        private const string document3 = @"..\..\booksSchema.xml";
        private const string document4 = @"..\..\booksSchemaFail.xml";
        private const string document5 = @"..\..\schema.xsd";

        private Boolean Success = true;

        static void Main()
        {
            ValidationReadingXMLSample validationReadingXMLSample = new ValidationReadingXMLSample();
            validationReadingXMLSample.Run();
        }

        void Run()
        {
            Success = true;
            XmlReaderSettings settings = new XmlReaderSettings();
        
            settings.ValidationEventHandler += new ValidationEventHandler(this.ValidationEventHandler);

            //Validate the valid XML with the XSD 
            Console.WriteLine("Validating XML file booksSchema.xml with schema file schema.xsd ...");

            settings.ValidationType = ValidationType.Schema;
            settings.Schemas.Add("schema.xsd", XmlReader.Create(document5));

            using (XmlReader xmlValidatingReader = XmlReader.Create(document3, settings))
            {
                while (xmlValidatingReader.Read()) { }
            }
            Console.WriteLine("Validation finished. Validation {0}", (Success == true ? "successful" : "failed"));

            //Validate the invalid XML with the XSD 
            Console.WriteLine("Validating XML file booksSchema.xml with schema file schema.xsd ...");
            using (XmlReader xmlValidatingReader = XmlReader.Create(document4, settings))
            {
                while (xmlValidatingReader.Read()) { }
            }
        
            Console.WriteLine("Validation finished. Validation {0}", (Success == true ? "successful" : "failed"));
            Console.WriteLine();
            Console.WriteLine("Press Enter to Exit");
            Console.ReadLine();
        }

        void ValidationEventHandler(object sender, ValidationEventArgs args)
        {
            Success = false;

            Console.WriteLine("\tValidation error: " + args.Message);

            if (args.Severity == XmlSeverityType.Warning)
            {
                Console.WriteLine("No schema found to enforce validation.");
            }
            else
                if (args.Severity == XmlSeverityType.Error)
                {
                    Console.WriteLine("Error occurred during validation.");
                }

            if (args.Exception != null) // XSD schema validation error
            {
                Console.WriteLine(args.Exception.SourceUri + "," + args.Exception.LinePosition + "," + args.Exception.LineNumber);
            }
        }
    }
}

