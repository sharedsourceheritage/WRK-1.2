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
using System.Xml.Xsl;

namespace Microsoft.Samples.Xml 
{
    class ExtensionObjectSample
    {
        static void Main()
        {
            string filename = @"..\..\number.xml";
            string stylesheet = @"..\..\circle.xsl";
            //Create XslCompiledTransform and compile stylesheet.
            XslCompiledTransform processor = new XslCompiledTransform();

            processor.Load(stylesheet);

            //Create an XsltArgumentList
            XsltArgumentList xslArg = new XsltArgumentList();

            //Add an object to calculate the circumference of the circle.
            Calculate obj = new Calculate();
            xslArg.AddExtensionObject("urn:myObj", obj);

            //Create an XmlWriter to output to the console.   
            using (XmlWriter writer = XmlWriter.Create(Console.Out))
            {
                //Transform the file.
                processor.Transform(filename, xslArg, writer);
            }
            Console.WriteLine("\n\nPress Enter to Exit");
            Console.ReadLine();
        }

        //Calculates the circumference of a circle given the radius.
        public class Calculate{
            public double Circumference(double radius)
            {
                return Math.PI * 2 * radius; ;
            }
        }
    }
}
