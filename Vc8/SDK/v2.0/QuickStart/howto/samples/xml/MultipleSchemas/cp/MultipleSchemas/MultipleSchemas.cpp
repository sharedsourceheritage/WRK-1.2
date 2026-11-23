//-----------------------------------------------------------------------
//       file is part of the Microsoft .NET SDK Code Samples.
// 
//  Copyright (C) Microsoft Corporation.  All rights reserved.
// 
//     source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.
// 
//     CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.
//-----------------------------------------------------------------------
#using <System.Xml.Dll>

using namespace System;
using namespace System::Xml;
using namespace System::Xml::Schema;

namespace MicrosoftSamplesXml
{
   public ref class MultipleSchemas
   {
   protected:
      static String^ document = "books.xml";

   public:
      void Main()
      {
         XmlReader^ reader = nullptr;
         XmlWriter^ writer = nullptr;
         XmlSchemaSet^ schemaSet = gcnew XmlSchemaSet;
         try
         {
            schemaSet->Add( L"http://www.example.org", L"book.xsd" );
            schemaSet->Add( L"http://www.example.org", L"author.xsd" );
            
            //All schemas compiled into a single logical schema 
            schemaSet->Compile();
            
            // Process the supplied XML file
            Console::WriteLine( "Processing ..." );
            Console::WriteLine();
            XmlReaderSettings^ settings = gcnew XmlReaderSettings;
            settings->ValidationType = ValidationType::Schema;
            settings->Schemas = schemaSet;
            reader = XmlReader::Create( document, settings );
            
            //Input XML is validated then written out with the writer
            writer = XmlWriter::Create( Console::Out, gcnew XmlWriterSettings );
            writer->WriteNode( reader, true );
         }
         finally
         {
            // Finished with XmlReader
            if ( reader != nullptr )
            {
                reader->Close();
            }

            if (writer != nullptr)
            {
                writer->Close();
            }
            Console::WriteLine("Document successfully validated.");
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
   
   //Create the class
   MultipleSchemas^ readXmlFileSample = gcnew MultipleSchemas;
   readXmlFileSample->Main();
}
