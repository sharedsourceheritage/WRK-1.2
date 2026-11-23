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
using System.IO;

namespace Microsoft.Samples.Xml 
{
    public class BinaryDataInXmlSample
    {
        static void Main()
        {
            byte[] buffer2;
            int found;

            // First we create a binary blob of data in a byte array
            // initializing the bytes to the values 1 through 10.
            byte[] buffer = new Byte[10];
            for (int i = 0; i < 10; i++) buffer[i] = (byte)i;

            // Now we write an XML stream to a StringWriter using the
            // WriteBase64 method on the XmlWriter.
            using (StringWriter sw = new StringWriter())
            {
                using (XmlWriter writer = XmlWriter.Create(sw))
                {
                    writer.WriteStartElement("Test");
                    writer.WriteAttributeString("Length", buffer.Length.ToString());
                    writer.WriteCData(Convert.ToBase64String(buffer, 0, buffer.Length));
                    writer.WriteEndElement();
                }

                // This will produce the following output:
                // <Test Length="10"><![CDATA[AAECAwQFBgcICQ==]]></Test>
                Console.WriteLine(sw.ToString());

                // It looks like garbage - but it is correct base 64 encoding of the
                // binary data.  To prove it, we'll read it back in using the XmlReader

                // First position reader on <Test> element and get the Length attribute
                // Next position reader on <Test> element and get the Length attribute
                using (XmlReader reader = XmlReader.Create(new StringReader(sw.ToString())))
                {
                    reader.Read();
                    reader.Read();
                    reader.MoveToAttribute("Length");
                    int len = reader.ReadContentAsInt();
                    reader.MoveToElement();
                    // Allocate a buffer of the correct length and call ReadBase64.
                    buffer2 = new byte[len];
                    found = reader.ReadElementContentAsBase64(buffer2, 0, len);
                }

                // Now output the byte values and see what we get
                // Notice this produces the correct result:
                //  "0,1,2,3,4,5,6,7,8,9"
                for (int j = 0; j < found; j++)
                {
                    Console.Write(buffer2[j]);
                    if (j < found - 1) Console.Write(",");
                }
            }

            Console.WriteLine();
            Console.WriteLine("Press Enter to Exit");
            Console.ReadLine();
        }
    }
}