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

namespace MicrosoftSamplesXml
{
    public ref class ReadXmlStreamSample
    {
    public:
        void Main()
        {
            StringReader^ stream = nullptr;
            XmlReader^ reader = nullptr;
            XmlWriter^ writer = nullptr;
            Uri^ uri = nullptr;
            try
            {
                Console::WriteLine( "Initializing StringReader ..." );
                stream = gcnew StringReader( String::Concat( L"<?xml version='1.0'?>", L"<!-- This file represents a fragment of a book store inventory database -->", L"<bookstore>", L" <book genre=\"autobiography\" publicationdate=\"1981\" ISBN=\"1-861003-11-0\">", L"   <title>The Autobiography of Benjamin Franklin</title>", L"   <author>", L"       <first-name>Benjamin</first-name>", L"       <last-name>Franklin</last-name>", L"   </author>", L"   <price>8.99</price>", L" </book>", L" <book genre=\"novel\" publicationdate=\"1967\" ISBN=\"0-201-63361-2\">", L"   <title>The Confidence Man</title>", L"   <author>", L"       <first-name>Herman</first-name>", L"       <last-name>Melville</last-name>", L"   </author>", L"   <price>11.99</price>", L" </book>", L"  <book genre=\"philosophy\" publicationdate=\"1991\" ISBN=\"1-861001-57-6\">", L"   <title>The Gorgias</title>", L"   <author>", L"       <name>Plato</name>", L"   </author>", L"   <price>9.99</price>", L" </book>", L"</bookstore>" ) );
                
                // Create XmlReader and load reader from the stream
                uri = gcnew Uri( L"http://tempuri.org/unknown" );
                reader = XmlReader::Create( stream );
                
                //Output reader to console
                writer = XmlWriter::Create( Console::Out );
                writer->WriteNode( reader, true ); 
                writer->Flush();
            }
            finally
            {
                Console::WriteLine("Processing of stream complete.");
                Console::WriteLine("Press Enter to Exit");
                Console::ReadLine();
                // Finished with XmlReader
                if ( reader != nullptr )
                {
                    reader->Close();
                }
                if (writer != nullptr)
                {
                    writer->Close();
                }
                if (stream != nullptr)
                {
                    stream->Close();
                }
            }
        }
   };
}

void main()
{
   
   //Import the new package
   using namespace MicrosoftSamplesXml;
   
   //Create the ReadXmlStreamSample class
   ReadXmlStreamSample^ readXmlStreamSample = gcnew ReadXmlStreamSample;
   readXmlStreamSample->Main();
}

