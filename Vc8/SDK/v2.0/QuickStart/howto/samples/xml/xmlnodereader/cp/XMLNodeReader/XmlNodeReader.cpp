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

namespace MicrosoftSamplesXml
{
    public ref class XmlNodeReaderSample
    {
    protected:
        static String^ document = "books.xml";

    public:
        void Main()
        {
            XmlNodeReader^ xmlNodeReader = nullptr;
            XmlWriter^ writer = nullptr;
            try
            {
                
                // Load the XML from file
                Console::WriteLine();
                Console::WriteLine( L"Loading file {0} ... \r\n", document );
                XmlDocument^ xmlDocument = gcnew XmlDocument;
                xmlDocument->Load( document );
                Console::WriteLine( L"XmlDocument loaded with XML data successfully ... " );
                Console::WriteLine();
                Console::WriteLine( L"Create an XmlNodeReader to show the third book ..." );
                Console::WriteLine();
                xmlNodeReader = gcnew XmlNodeReader( xmlDocument->SelectSingleNode( L"bookstore/book[3]" ) );
                
                //Output reader to console
                writer = XmlWriter::Create( Console::Out );
                writer->WriteNode( xmlNodeReader, true );
                writer->Flush();
                Console::WriteLine();
                Console::WriteLine( L"Create an XmlNodeReader to show the second book ... " );
                Console::WriteLine();
                xmlNodeReader = gcnew XmlNodeReader( xmlDocument->SelectSingleNode( L"bookstore/book[2]" ) );
                xmlNodeReader->Read();
                Console::WriteLine( xmlNodeReader->ReadInnerXml() );
            }
            finally
            {
                if (writer !=nullptr)
                {
                    writer->Close();
                }
                if(xmlNodeReader != nullptr)
                {
                    xmlNodeReader->Close();
                }

                Console::WriteLine();
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
    XmlNodeReaderSample^ xmlNodeReaderSample = gcnew XmlNodeReaderSample;
    xmlNodeReaderSample->Main();
}

