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
using System.IO;
using System.Xml;
using System.Xml.Xsl;

namespace Microsoft.Samples.Xml
{
    public class TransformXMLSample
    {
        private const string document1 = @"..\..\books.xml";
        private const string document2 = @"..\..\ProcessParametersA.xml";
        private const string document3 = @"..\..\ProcessParametersB.xml";
        private const string styleSheet1 = @"..\..\books.xsl";
        private const string styleSheet2 = @"..\..\StyleSheetGenerator.xsl";
        private const string output1 = @"..\..\table.html";
        private const string output2 = @"..\..\transform2.xsl"; //linked by books-t2.xml
        private const string output3 = @"..\..\transform3.xsl";    //linked by books-t3.xml
        /** 
            add <?xml-stylesheet type="text/xsl" href="transform2.xsl" ?> to books.xml to view transform using transform2.xsl
            add <?xml-stylesheet type="text/xsl" href="transform3.xsl" ?> to books.xml to view transform using transform3.xsl
        **/

        public static void Main()
        {
            TransformXMLSample transformXMLSample = new TransformXMLSample();
            Console.WriteLine("\n\n*********Output from the first transform:*********\n\n");
            String[] args1 = {document1, styleSheet1,output1};
            transformXMLSample.Run(args1);

            Console.WriteLine("\n\n*********Output from the second transform:*********\n\n");
            String[] args2 = {document2, styleSheet2,output2};
            transformXMLSample.Run(args2);

            Console.WriteLine("\n\n*********Output from the third transform:*********\n\n");
            String[] args3 = {document3, styleSheet2,output3};
            transformXMLSample.Run(args3);
            Console.Write("Press Enter to Exit");
            Console.ReadLine();
        }

        public void Run(String[] args)
        {
            Console.WriteLine();
            Console.WriteLine("Read XML data file, transform and format display ...");
            Console.WriteLine();

            ReadTransform(args);

            Console.WriteLine();
            Console.WriteLine("Read XML data file, transform and write ...");
            Console.WriteLine();

            ReadTransformWrite(args);
            Console.WriteLine();
        }

        public void ReadTransform(String[] args)
        {
            XslCompiledTransform processor = new XslCompiledTransform();
            processor.Load(args[1]);
            //Transform the file.
            processor.Transform(args[0], null, Console.Out);
           }

        public void ReadTransformWrite(String[] args)
        
        {
            using (FileStream stream = File.Open(args[2], FileMode.Create))
            {
                //Create XsltCommand and compile stylesheet.
                XslCompiledTransform processor = new XslCompiledTransform();
                processor.Load(args[1]);
                //Transform the file.
                processor.Transform(args[0], null, stream);
            }
        }
    } 
} 
