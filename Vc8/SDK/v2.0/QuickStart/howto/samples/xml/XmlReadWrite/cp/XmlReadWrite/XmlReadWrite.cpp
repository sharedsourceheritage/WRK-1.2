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
    public ref class XmlReadWriteSample
    {
    protected:
        static String^ xsd = L"bookstore.xsd";
        static String^ document = L"bookstore.xml";
        
    public:
        void Main()
        {   
            XmlReader^ reader = nullptr;
            XmlWriter^ writer = nullptr;
            XmlWriterSettings^ settings = gcnew XmlWriterSettings;
            settings->Indent = true;
            
            XmlReaderSettings^ readerSettings = gcnew XmlReaderSettings();
            readerSettings->IgnoreWhitespace = true;
            
            try
            {
                reader = XmlReader::Create(L"books.xml", readerSettings);
                writer = XmlWriter::Create(Console::Out, settings);

                while (!reader->EOF)
                {
                    if (reader->IsStartElement("price"))
                    {
                        //read the original value
                        double originalPrice = 0.0;
                        try
                        {
                            originalPrice = reader->ReadElementContentAsDouble();
                        }
                        catch (Exception^)
                        {
                            //catch invalid values <price/> and <price></price>
                            //set price to zero
                            originalPrice = 0.0;
                        }
                        double discountedPrice = originalPrice - (originalPrice * 0.25);
                        writer->WriteStartElement("price");
                        writer->WriteAttributeString("alternative", "25% discount");
                        writer->WriteAttributeString("originalPrice", originalPrice.ToString());
                        writer->WriteValue(discountedPrice);
                        writer->WriteEndElement();
                    }
                    else
                    {
                        WriteShallowNode(reader, writer);
                        reader->Read();
                    }
                }
            }
            finally
            {
                if (writer != nullptr)
                {
                    writer->Close();
                }
                if (reader != nullptr)
                {
                    reader->Close();
                }
            
                Console::WriteLine(L"\nPress Enter to Exit");
                Console::ReadLine();
            }
        }

        static void WriteShallowNode(XmlReader^ reader, XmlWriter^ writer)
        {
            if (reader == nullptr)
            {
                throw gcnew ArgumentNullException("reader");
            }
            if (writer == nullptr)
            {
                throw gcnew ArgumentNullException("writer");
            }

            switch (reader->NodeType)
            {
            case XmlNodeType::Element:
                    writer->WriteStartElement(reader->Prefix, reader->LocalName, reader->NamespaceURI);
                    writer->WriteAttributes(reader, true);
                    if (reader->IsEmptyElement)
                    {
                        writer->WriteEndElement();
                    }
                    break;
            case XmlNodeType::Text:
                    writer->WriteString(reader->Value);
                    break;
            case XmlNodeType::Whitespace:
            case XmlNodeType::SignificantWhitespace:
                    writer->WriteWhitespace(reader->Value);
                    break;
            case XmlNodeType::CDATA:
                    writer->WriteCData(reader->Value);
                    break;
            case XmlNodeType::EntityReference:
                    writer->WriteEntityRef(reader->Name);
                    break;
            case XmlNodeType::XmlDeclaration:
            case XmlNodeType::ProcessingInstruction:
                    writer->WriteProcessingInstruction(reader->Name, reader->Value);
                    break;
            case XmlNodeType::DocumentType:
                    writer->WriteDocType(reader->Name, reader->GetAttribute("PUBLIC"), reader->GetAttribute("SYSTEM"), reader->Value);
                    break;
            case XmlNodeType::Comment:
                    writer->WriteComment(reader->Value);
                    break;
            case XmlNodeType::EndElement:
                    writer->WriteFullEndElement();
                    break;
            }
        }
   };
}
void main()
{
    //Import the new package
    using namespace MicrosoftSamplesXml;

    //Create the class
    XmlReadWriteSample^ xmlReadWriteSample = gcnew XmlReadWriteSample;
    xmlReadWriteSample->Main();
}

