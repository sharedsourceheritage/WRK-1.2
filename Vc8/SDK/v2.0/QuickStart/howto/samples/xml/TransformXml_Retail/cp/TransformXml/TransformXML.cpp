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
using namespace System::Xml::Xsl;

namespace MicrosoftSamplesXml
{
    public ref class TransformXMLSample
    {
    protected:
        static String^ document1 = L"books.xml";
        static String^ document2 = L"ProcessParametersA.xml";
        static String^ document3 = L"ProcessParametersB.xml";
        static String^ styleSheet1 = L"books.xsl";
        static String^ styleSheet2 = L"StyleSheetGenerator.xsl";
        static String^ output1 = L"table.html";
        static String^ output2 = L"transform2.xsl"; 
        static String^ output3 = L"transform3.xsl";    
        /** 
            add <?xml-stylesheet type="text/xsl" href="transform2.xsl" ?> to books.xml to view transform using transform2.xsl
            add <?xml-stylesheet type="text/xsl" href="transform3.xsl" ?> to books.xml to view transform using transform3.xsl
        **/

    public:
        void Main()
        {
            TransformXMLSample^ transformXMLSample = gcnew TransformXMLSample;
            Console::WriteLine("\n\n*********Output from the first transform:*********\n\n");

            array<String^>^args1 = {document1, styleSheet1,output1};
            transformXMLSample->Run(args1);

            Console::WriteLine("\n\n*********Output from the second transform:*********\n\n");
            array<String^>^args2 = {document2, styleSheet2,output2};
            transformXMLSample->Run(args2);

            Console::WriteLine("\n\n*********Output from the third transform:*********\n\n");
            array<String^>^args3 = {document3, styleSheet2,output3};
            transformXMLSample->Run(args3);
            Console::Write("Press Enter to Exit");
            Console::ReadLine();
        }

        void Run( array<String^>^args )
        {
            Console::WriteLine();
            Console::WriteLine("Read XML data file, transform and format display ...");
            Console::WriteLine();
            
            ReadTransform(args);

            Console::WriteLine();
            Console::WriteLine("Read XML data file, transform and write ...");
            Console::WriteLine();
            
            //+ReadTransformWrite(args);
            Console::WriteLine();
        }
      
        void ReadTransform(array<String^>^args )
        {
            XslCompiledTransform^ processor = gcnew XslCompiledTransform();
            processor->Load(args[1]);
            //Transform the file.
            processor->Transform(args[0], nullptr, Console::Out);
        }

        void ReadTransformWrite(array<String^>^args)
        {
            FileStream^ stream = nullptr;
            try
            {
                stream = File::Open(args[2],FileMode::Create);

                //Create XsltCommand and compile stylesheet.
                XslCompiledTransform^ processor = gcnew XslCompiledTransform;
                processor->Load(args[1]);
                //Transform the file.
                processor->Transform(args[0], nullptr, stream);    
            }
            finally
            {
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
   
    //Create the class
    TransformXMLSample^ transformXMLSample = gcnew TransformXMLSample;
    transformXMLSample->Main();
}

