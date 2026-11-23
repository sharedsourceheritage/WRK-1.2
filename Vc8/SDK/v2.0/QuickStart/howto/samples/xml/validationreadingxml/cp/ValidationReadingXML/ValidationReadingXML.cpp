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
#using <System.Xml.Dll>

using namespace System;
using namespace System::Xml;
using namespace System::Xml::Schema;

namespace MicrosoftSamplesXML
{
    public ref class ValidationReadingXMLSample
    {
    protected:
        static String^ document1 = L"booksDTD.xml";
        static String^ document2 = L"booksDTDFail.xml";
        static String^ document3 = L"booksSchema.xml";
        static String^ document4 = L"booksSchemaFail.xml";
        static String^ document5 = L"schema.xsd";
        static Boolean Success = true;

   public:
        void Main()
        {
            Success = true;
            XmlReader^ xmlValidatingReader = nullptr;

            try
            {
                XmlReaderSettings^ settings = gcnew XmlReaderSettings(); 
                settings->ValidationEventHandler += gcnew ValidationEventHandler(this, &ValidationReadingXMLSample::MyValidationEventHandler);        

                //Validate the valid XML with the XSD 
                Console::WriteLine("Validating XML file booksSchema.xml with schema file schema.xsd ...");
                    
                settings->ValidationType = ValidationType::Schema;
                settings->Schemas->Add("schema.xsd", XmlReader::Create(document5));

                xmlValidatingReader = XmlReader::Create(document3, settings);
                while (xmlValidatingReader->Read()) { }
                Console::WriteLine("Validation finished. Validation {0}", (Success == true ? "successful" : "failed"));

                //Validate the invalid XML with the XSD 
                Console::WriteLine("Validating XML file booksSchema.xml with schema file schema.xsd ...");
                xmlValidatingReader = XmlReader::Create(document4, settings);
                while (xmlValidatingReader->Read()) { }
            }
            finally
            {
                if (xmlValidatingReader != nullptr)
                {
                    xmlValidatingReader->Close();
                }

                Console::WriteLine("Validation finished. Validation {0}", (Success == true ? "successful" : "failed"));
                Console::WriteLine("Press Enter to Exit");
                Console::ReadLine(); 
            }
        }
    
        void MyValidationEventHandler (Object^ sender, ValidationEventArgs^ args)
        {
            Success = false;

            Console::WriteLine("\tValidation error: " + args->Message);

            if (args->Severity == XmlSeverityType::Warning)
            {
                Console::WriteLine("No schema found to enforce validation.");
            } else
                if (args->Severity == XmlSeverityType::Error)
                {
                    Console::WriteLine("Error occurred during validation.");
                } 

            if (args->Exception != nullptr) // XSD schema validation error
            {
                Console::WriteLine(args->Exception->SourceUri + "," +  args->Exception->LinePosition + "," +  args->Exception->LineNumber);
            }
        }     
   };
}

void main()
{
    //Import the new package
    using namespace MicrosoftSamplesXML;

    //Create the ValidationReadingXMLSample class
    ValidationReadingXMLSample ^ validationReadingXMLSample = gcnew ValidationReadingXMLSample;
    validationReadingXMLSample->Main();
}

