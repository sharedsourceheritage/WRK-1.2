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
using namespace System::IO;

namespace MicrosoftSamplesXml
{
   public ref class XmlSchemaInferenceSample
   {
           
    public:
        void Main()
        {
            //declare and instantiate a schema inferencer
            XmlSchemaInference^ infer = gcnew XmlSchemaInference;
            //declare and instantiate a schema set to hold the inferenced schema
            XmlSchemaSet^ sc = gcnew XmlSchemaSet();
            XmlWriter^ writer = nullptr;
            
            try
            {
                //XmlSchemaInference, given an XML fragment, infers the XML Schema and adds it to the Schema set
                sc = infer->InferSchema(gcnew XmlTextReader(L"sample.xml"));

                /* <!-- sample.xml -->
                * <?xml version="1.0" encoding="utf-8" ?> 
                * <item xmlns="urn:items" productID='123098'>
                *  <name>hammer</name>
                *  <price>9.95</price>
                *  <supplierID>1929</supplierID>
                * </item>
                * 
                */

                writer = XmlWriter::Create(gcnew StreamWriter(L"sampleSchema1.xsd"));
                
                for each (XmlSchema^ schema in sc->Schemas())
                {
                    schema->Write(writer);
                }
                Console::WriteLine("Created sampleSchema1.xsd");

                /*
                * <!-- generated sampleSchema1.xsd -->
                * 
                * <?xml version="1.0" encoding="utf-8"?>
                * <xs:schema attributeFormDefault="unqualified" elementFormDefault="qualified" targetNamespace="urn:items" xmlns:xs="http://www.w3.org/2001/XMLSchema">
                *     <xs:element name="item">
                *         <xs:complexType>
                *             <xs:sequence>
                *                 <xs:element name="name" type="xs:string" />
                *                 <xs:element name="price" type="xs:decimal" />
                *                 <xs:element name="supplierID" type="xs:unsignedShort" />
                *             </xs:sequence><xs:attribute name="productID" type="xs:unsignedInt" use="required" />
                *         </xs:complexType>
                *     </xs:element>
                * </xs:schema>
                * 
                */

                //update schema with another xml fragment
                sc = infer->InferSchema(XmlReader::Create(L"sample2.xml"), sc);

                /* 
                * <!-- sample2.xml -->
                * <item xmlns="urn:items" productID='A53-246'>
                *  <name>paint</name>
                *  <price>12.50</price>
                * </item>
                * 
                */

                //update the schema -- notice the supplierID element is missing in this XML fragment. This is interpreted
                //to mean that the supplierID element is an optional field

                //write the new schema to file
                writer = XmlWriter::Create(gcnew StreamWriter(L"sampleSchema2.xsd"));

                for each (XmlSchema^ schema in sc->Schemas())
                {
                    schema->Write(writer);
                }
                Console::WriteLine("Created sampleSchema2.xsd");

                /*
                * <!-- generated sampleSchema2.xsd -->
                * 
                * <?xml version="1.0" encoding="utf-8"?>
                * <xs:schema attributeFormDefault="unqualified" elementFormDefault="qualified" targetNamespace="urn:items" xmlns:xs="http://www.w3.org/2001/XMLSchema">
                *   <xs:element name="item">
                *     <xs:complexType>
                *       <xs:sequence>
                *         <xs:element name="name" type="xs:string" />
                *         <xs:element name="price" type="xs:decimal" />
                *         <xs:element minOccurs="0" name="supplierID" type="xs:unsignedShort" />
                *       </xs:sequence>
                *       <xs:attribute name="productID" type="xs:string" use="required" />
                *     </xs:complexType>
                *   </xs:element>
                * 
                */

                //set the occurrence inference option to relaxed and the schema sets the elements to optional
                //This opiton will generate the elements to be optional elements as opposed to required.
                //Compare sampleSchema1.xsd which had by default elements to be required and sampleSchema3.xsd where the 
                //elements are optional. This option is a global setting and cannot be used to set the option of each element

                infer->Occurrence=XmlSchemaInference::InferenceOption::Relaxed;
                
                //infer schema for sample 1 again
                sc = infer->InferSchema(XmlReader::Create(L"sample.xml"));
                            
                //write the new schema to file
                writer = XmlWriter::Create(gcnew StreamWriter(L"sampleSchema3.xsd"));
                
                for each (XmlSchema^ schema in sc->Schemas())
                {
                    schema->Write(writer);
                }
                Console::WriteLine("Created sampleSchema3.xsd");

                /*
                * Generated Schema sampleSchema3.xsd
                * 
                * <?xml version="1.0" encoding="utf-8"?>
                * <xs:schema attributeFormDefault="unqualified" elementFormDefault="qualified" targetNamespace="urn:items" xmlns:xs="http://www.w3.org/2001/XMLSchema">
                *   <xs:element name="item">
                *     <xs:complexType>
                *       <xs:sequence>
                *         <xs:element minOccurs="0" name="name" type="xs:string" />
                *         <xs:element minOccurs="0" name="price" type="xs:decimal" />
                *         <xs:element minOccurs="0" name="supplierID" type="xs:unsignedShort" />
                *       </xs:sequence>
                *       <xs:attribute name="productID" type="xs:unsignedInt" use="optional" />
                *     </xs:complexType>
                *   </xs:element>
                * 
                * 
                */
                //Set the type inference option to relaxed. If this option is set, the types default to string
                //as opposed to inference xsd datatypes
                
                infer->TypeInference = XmlSchemaInference::InferenceOption::Relaxed;
                //infer schema for sample 1 again
                sc = infer->InferSchema(gcnew XmlTextReader(L"sample.xml"));

                //write the new schema to file
                writer = XmlWriter::Create(gcnew StreamWriter(L"sampleSchema4.xsd"));

                for each (XmlSchema^ schema in sc->Schemas())
                {
                    schema->Write(writer);
                }
                Console::WriteLine("Created sampleSchema4.xsd");

                /* 
                * Generated Schema sampleSchema4.xsd
                * 
                *<?xml version="1.0" encoding="utf-8"?> 
                *<xs:schema attributeFormDefault="unqualified" elementFormDefault="qualified" targetNamespace="urn:items" xmlns:xs="http://www.w3.org/2001/XMLSchema"> 
                *  <xs:element name="item"> 
                *    <xs:complexType> 
                *      <xs:sequence> 
                *        <xs:element minOccurs="0" name="name" type="xs:string" /> 
                *        <xs:element minOccurs="0" name="price" type="xs:string" /> 
                *        <xs:element minOccurs="0" name="supplierID" type="xs:string" /> 
                *      </xs:sequence> 
                *      <xs:attribute name="productID" type="xs:string" use="optional" /> 
                *    </xs:complexType> 
                *  </xs:element> 
                *</xs:schema>
                * 
                * 
                */
            }
            finally
            {
                if (writer != nullptr)
                {
                    writer->Close();
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
   
   //Create the class
   XmlSchemaInferenceSample^ xmlSchemaInferenceSample = gcnew XmlSchemaInferenceSample;
   xmlSchemaInferenceSample->Main();
}

