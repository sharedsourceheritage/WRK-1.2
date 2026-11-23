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
using namespace System::IO;
using namespace System::Xml;
using namespace System::Xml::Schema;

namespace MicrosoftSamplesXml
{
    public ref class XmlReadWriteSchemaSample
    {
    protected:
        static String^ document = L"sample.xsd";

    public:
        void Main()
        {
            XmlWriter^ writer = nullptr;
             
            //Create a stringwriter for output
            StringWriter^ stringWriter = gcnew StringWriter;
            
            try
            {
                //Create XmlWriter
                writer = XmlWriter::Create( stringWriter );
                 
                //Read the Schema
                Console::WriteLine( L"Reading schema {0} ...", document);
                Console::WriteLine();
                XmlSchema^ schema = XmlSchema::Read(XmlReader::Create( document ), nullptr );
                 
                //Write the Schema
                Console::WriteLine( L"Writing schema {0} ...", document );
                Console::WriteLine();
                schema->Write( writer );
                Console::WriteLine( stringWriter->ToString() );
            }
            finally
            {
                if (writer != nullptr)
                {
                    writer->Close();
                }
                if (stringWriter !=nullptr)
                {
                    stringWriter->Close();
                }

                Console::WriteLine("Press Enter to Exit");
                Console::ReadLine();
            }
        }
   };
}

void main()
{
    //Import the new package
    using namespace MicrosoftSamplesXml;

    //Create the XPathExpressionSample class
    XmlReadWriteSchemaSample^ xmlReadWriteSchemaSample = gcnew XmlReadWriteSchemaSample;
    xmlReadWriteSchemaSample->Main();
}

