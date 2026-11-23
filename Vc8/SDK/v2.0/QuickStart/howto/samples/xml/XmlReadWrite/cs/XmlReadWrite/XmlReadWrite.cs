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

namespace Microsoft.Samples.Xml
{
    class XmlReadWriteSample
    {
        static void Main()
        {
            XmlWriterSettings writerSettings = new XmlWriterSettings();
            writerSettings.Indent = true;

            XmlReaderSettings readerSettings = new XmlReaderSettings();
            readerSettings.IgnoreWhitespace = true;

            using (XmlWriter writer = XmlWriter.Create(Console.Out, writerSettings))
            {
                using (XmlReader reader = XmlReader.Create(@"../../books.xml", readerSettings))
                {
                    while (!reader.EOF)
                    {
                        if (reader.IsStartElement("price"))
                        {
                            //read the original value
                            double originalPrice = 0.0;
                            try
                            {
                                originalPrice = reader.ReadElementContentAsDouble();
                            }
                            catch (Exception)
                            {
                                //Catch invalid values <price/> and <price></price>
                                //set price to zero
                                originalPrice = 0.0;
                            }
                            double discountedPrice = originalPrice - (originalPrice * 0.25);
                            writer.WriteStartElement("price");
                            writer.WriteAttributeString("alternative", "25% discount");
                            writer.WriteAttributeString("originalPrice", originalPrice.ToString());
                            writer.WriteValue(discountedPrice);
                            writer.WriteEndElement();
                        }
                        else
                        {
                            WriteShallowNode(reader, writer);
                            reader.Read();
                        }
                    }
                }
            }
            Console.WriteLine();
            Console.WriteLine("Press Enter to Exit");
            Console.ReadLine();

        }

        //This method is useful for streaming transformation with the 
        //XmlReader and the XmlWriter. It pushes through single nodes in the stream
        static void WriteShallowNode(XmlReader reader, XmlWriter writer)
        {
            if (reader == null)
            {
                throw new ArgumentNullException("reader");
            }
            if (writer == null)
            {
                throw new ArgumentNullException("writer");
            }

            switch (reader.NodeType)
            {
                case XmlNodeType.Element:
                    writer.WriteStartElement(reader.Prefix, reader.LocalName, reader.NamespaceURI);
                    writer.WriteAttributes(reader, true);
                    if (reader.IsEmptyElement)
                    {
                        writer.WriteEndElement();
                    }
                    break;
                case XmlNodeType.Text:
                    writer.WriteString(reader.Value);
                    break;
                case XmlNodeType.Whitespace:
                case XmlNodeType.SignificantWhitespace:
                    writer.WriteWhitespace(reader.Value);
                    break;
                case XmlNodeType.CDATA:
                    writer.WriteCData(reader.Value);
                    break;
                case XmlNodeType.EntityReference:
                    writer.WriteEntityRef(reader.Name);
                    break;
                case XmlNodeType.XmlDeclaration:
                case XmlNodeType.ProcessingInstruction:
                    writer.WriteProcessingInstruction(reader.Name, reader.Value);
                    break;
                case XmlNodeType.DocumentType:
                    writer.WriteDocType(reader.Name, reader.GetAttribute("PUBLIC"), reader.GetAttribute("SYSTEM"), reader.Value);
                    break;
                case XmlNodeType.Comment:
                    writer.WriteComment(reader.Value);
                    break;
                case XmlNodeType.EndElement:
                    writer.WriteFullEndElement();
                    break;
            }
        }
    }
}
