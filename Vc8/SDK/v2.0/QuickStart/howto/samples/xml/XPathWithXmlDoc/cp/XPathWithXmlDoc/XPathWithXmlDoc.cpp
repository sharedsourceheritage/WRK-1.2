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
using namespace System::Xml::XPath;

namespace MicrosoftSamplesXml
{
    public ref class XPathWithXmlDocSample
    {
    protected:
        static String^ document = L"books.xml";
                   
    public:
        void Main()
        {
           
        String^ exprString = String::Empty;

        // Create a new XmlDocument for the specified source file and load it.
        XmlDocument^ xmlDocument = gcnew XmlDocument();

        xmlDocument->Load(document);

        // Create an XmlNamespaceManager and add the namespaces for the document.
        XmlNamespaceManager^ nsmanager = gcnew XmlNamespaceManager(xmlDocument->NameTable);

        // Map namespaces to prefixes for querying purposes.
        nsmanager->AddNamespace("ns", "http://tempuri.org/myBooksNamespace");
        nsmanager->AddNamespace("myns", "http://tempuri.org/myBooksProcessornamespace");
        nsmanager->AddNamespace("yourns1", "http://tempuri.org/myBook1namespace");
        nsmanager->AddNamespace("yourns2", "http://tempuri.org/myBook2namespace");

        //SelectNodes ...
        XmlNodeList^ nodelist = xmlDocument->SelectNodes("//yourns1:book", nsmanager);

        for each (XmlNode^ xmlNode in nodelist)
        {
            DisplayTree(xmlNode);
        }

        nodelist = xmlDocument->SelectNodes("//ns:book", nsmanager);
        
        for each (XmlNode^ xmlNode in nodelist)
        {
            DisplayTree(xmlNode);
        }

        Console::WriteLine();
        Console::WriteLine("Press Enter to Exit");
        Console::ReadLine();
    }

    void DisplayTree(XmlNode^ node)
    {
        if (node != nullptr)
            Format(node);

        if (node->HasChildNodes)
        {
            node = node->FirstChild;
            while (node != nullptr)
            {
                DisplayTree(node);
                node = node->NextSibling;
            }
        }
    }

    // Format the output
    void Format(XmlNode^ node)
    {
        if (!node->HasChildNodes)
            Console::WriteLine("\t" + node->Value);

        else
        {
            Console::Write(node->Name);
            if (XmlNodeType::Element == node->NodeType)
            {
                XmlNamedNodeMap^ map = node->Attributes;
                for each (XmlNode^ attrnode in map)
                    Console::Write(" " + attrnode->Name + "<" + attrnode->Value + "> ");
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
    XPathWithXmlDocSample^ xpathWithXmlDocSample = gcnew XPathWithXmlDocSample;
    xpathWithXmlDocSample->Main();
}

