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
    public class XmlSchemaObjectModelSample
    {
        static XmlWriter writer = null;
        static XmlSchema xmlSchema = null;

        public static void Main()
        {
            Random random = new Random();
            
            //Schemas to read
            string sampleSchema1 = @"..\..\books.xsd";
            string sampleSchema2 = @"..\..\poschema.xsd";

            Console.WriteLine ("Creating Schema in the Schema Object Model...");
                    
            //Set writer properties with XmlWriterSettings
            XmlWriterSettings settings = new XmlWriterSettings();
            settings.Indent = true;
            settings.ConformanceLevel = ConformanceLevel.Fragment;

            //Create XmlWriter
            writer = XmlWriter.Create(Console.Out, settings);
            using (writer)
            {
                //Create an XmlNameTable
                XmlNameTable xmlNameTable = new NameTable();
                //Add the nametable to the XmlSchemaSet
                XmlSchemaSet xmlSchemaSet = new XmlSchemaSet(xmlNameTable);
                //Add some schemas to the XmlSchemaSet
                Console.WriteLine("Reading and adding {0} schema.", sampleSchema1);
                xmlSchemaSet.Add(null, sampleSchema1);
                Console.WriteLine("Reading and adding {0} schema.", sampleSchema2);
                xmlSchemaSet.Add(null, sampleSchema2);
                Console.WriteLine("Added schemas successfully ...");
                xmlSchemaSet.Compile();

                Console.WriteLine("Showing added schemas");

                foreach (XmlSchema tempXmlSchema in xmlSchemaSet.Schemas())
                {
                    xmlSchema = tempXmlSchema;
                    Console.WriteLine();
                    Console.WriteLine("Schema from: {0}", tempXmlSchema.SourceUri);
                    Console.WriteLine();
                    Console.WriteLine("=== Start of Schema ===");
                    Console.WriteLine();

                    // Write out the various schema parts
                    WriteXSDSchema();

                    Console.WriteLine();
                    Console.WriteLine();
                    Console.WriteLine("=== End of Schema ===");
                    Console.WriteLine();
                }
            }

            Console.WriteLine();
            Console.WriteLine("Press Enter to Exit");
            Console.ReadLine();
        }

        // Write out the XSD
        static void WriteXSDSchema()
        {
            writer.WriteStartElement("schema", XmlSchema.Namespace);
            writer.WriteAttributeString("targetNamespace", xmlSchema.TargetNamespace);
            foreach(XmlSchemaInclude include in xmlSchema.Includes)
            {
                writer.WriteStartElement("include", XmlSchema.Namespace);
                writer.WriteAttributeString("schemaLocation", include.SchemaLocation);
                writer.WriteEndElement();
            }

            foreach(object item in xmlSchema.Items)
            {
                if (item is XmlSchemaAttribute)
                    WriteXmlSchemaAttribute((XmlSchemaAttribute)item);      //attribute
                else if (item is XmlSchemaComplexType)
                    WriteXmlSchemaComplexType((XmlSchemaComplexType)item);  //complexType
                else if (item is XmlSchemaSimpleType)
                    WriteXmlSchemaSimpleType((XmlSchemaSimpleType)item);    //simpleType
                else if (item is XmlSchemaElement)
                    WriteXmlSchemaElement((XmlSchemaElement)item);          //element
                else if (item is XmlSchemaAnnotation)
                    WriteXmlSchemaAnnotation((XmlSchemaAnnotation)item);    //annotation
                else if (item is XmlSchemaAttributeGroup)
                    WriteXmlSchemaAttributeGroup((XmlSchemaAttributeGroup)item); //attributeGroup
                else if (item is XmlSchemaNotation)
                    WriteXmlSchemaNotation((XmlSchemaNotation)item);        //notation
                else if (item is XmlSchemaGroup)
                    WriteXmlSchemaGroup((XmlSchemaGroup)item);              //group
                else
                    Console.WriteLine("Not Implemented.");
            }
            writer.WriteEndElement();
            writer.Flush();
        }

        //XmlSchemaAttribute
        static void WriteXmlSchemaAttribute(XmlSchemaAttribute attribute)
        {
            writer.WriteStartElement("attribute", XmlSchema.Namespace);
            if (attribute.Name != null)
                writer.WriteAttributeString("name", attribute.Name);

            if (!attribute.RefName.IsEmpty)
            {
                writer.WriteStartAttribute("ref", null);
                writer.WriteQualifiedName(attribute.RefName.Name, attribute.RefName.Namespace);
                writer.WriteEndAttribute();
            }

            if (!attribute.SchemaTypeName.IsEmpty)
            {
                writer.WriteStartAttribute("type", null);
                writer.WriteQualifiedName(attribute.SchemaTypeName.Name, attribute.SchemaTypeName.Namespace);
                writer.WriteEndAttribute();
            }

            if (attribute.SchemaType != null)
                WriteXmlSchemaSimpleType(attribute.SchemaType);

            writer.WriteEndElement();
        }

        //XmlSchemaComplexType
        static void WriteXmlSchemaComplexType(XmlSchemaComplexType complexType)
        {
            writer.WriteStartElement("complexType", XmlSchema.Namespace);
            if (complexType.Name != null)
                writer.WriteAttributeString("name", complexType.Name);

            if (complexType.ContentModel != null)
                Console.WriteLine("Not Implemented for this ContentModel.");
            else
            {
                if (complexType.Particle != null)
                    WriteXmlSchemaParticle(complexType.Particle);
                foreach(object o in complexType.Attributes)
                {
                    if (o is XmlSchemaAttribute)
                        WriteXmlSchemaAttribute((XmlSchemaAttribute)o);
                }
            }
            writer.WriteEndElement();
        }

        //XmlSchemaSimpleType
        static void WriteXmlSchemaSimpleType(XmlSchemaSimpleType simpleType)
        {
            writer.WriteStartElement("simpleType", XmlSchema.Namespace);
            if (simpleType.Name != null)
                writer.WriteAttributeString("name", simpleType.Name);

            if (simpleType.Content is XmlSchemaSimpleTypeRestriction)
                writer.WriteStartElement("restriction", XmlSchema.Namespace);
            else if (simpleType.Content is XmlSchemaSimpleTypeList)
                writer.WriteStartElement("list", XmlSchema.Namespace);
            else
                writer.WriteStartElement("union", XmlSchema.Namespace);

            writer.WriteEndElement();
            writer.WriteEndElement();
        }

        //XmlSchemaParticle
        static void WriteXmlSchemaParticle(XmlSchemaParticle particle)
        {
            if (particle is XmlSchemaElement)
                WriteXmlSchemaElement((XmlSchemaElement)particle);
            else if (particle is XmlSchemaSequence)
            {
                writer.WriteStartElement("sequence", XmlSchema.Namespace);
                foreach(XmlSchemaParticle particle1 in ((XmlSchemaSequence)particle).Items)
                    WriteXmlSchemaParticle(particle1);

                writer.WriteEndElement();
            }
            else
                Console.WriteLine("Not Implemented for this type: {0}", particle.ToString());
        }

        // XmlSchemaElement
        static void WriteXmlSchemaElement(XmlSchemaElement element)
        {
            writer.WriteStartElement("element", XmlSchema.Namespace);
            if (element.Name != null)
                writer.WriteAttributeString("name", element.Name);

            if (!element.RefName.IsEmpty)
            {
                writer.WriteStartAttribute("ref", null);
                writer.WriteQualifiedName(element.RefName.Name, element.RefName.Namespace);
                writer.WriteEndAttribute();
            }

            if (!element.SchemaTypeName.IsEmpty)
            {
                writer.WriteStartAttribute("type", null);
                writer.WriteQualifiedName(element.SchemaTypeName.Name, element.SchemaTypeName.Namespace);
                writer.WriteEndAttribute();
            }

            if (element.SchemaType != null)
            {
                if (element.SchemaType is XmlSchemaComplexType)
                    WriteXmlSchemaComplexType((XmlSchemaComplexType)element.SchemaType);
                else
                    WriteXmlSchemaSimpleType((XmlSchemaSimpleType)element.SchemaType);
            }
            writer.WriteEndElement();
        }

        //XmlSchemaAnnotation
        static void WriteXmlSchemaAnnotation(XmlSchemaAnnotation annotation)
        {
            // Not a complete implementation
            writer.WriteStartElement("annotation", XmlSchema.Namespace);
            writer.WriteEndElement();
        }

        //XmlSchemaAttributeGroup
        static void WriteXmlSchemaAttributeGroup(XmlSchemaAttributeGroup attributeGroup)
        {
            // Not a complete implementation
            writer.WriteStartElement("attributeGroup", XmlSchema.Namespace);
            writer.WriteEndElement();
        }

        //XmlSchemaGroup
        static void WriteXmlSchemaGroup(XmlSchemaGroup group)
        {
            // Not a complete implementation
            writer.WriteStartElement("group", XmlSchema.Namespace);
            writer.WriteEndElement();
        }

        //XmlSchemaNotation
        static void WriteXmlSchemaNotation(XmlSchemaNotation notation)
        {
            // Not a complete implementation
            writer.WriteStartElement("notation", XmlSchema.Namespace);
            writer.WriteEndElement();
        }

    }
}