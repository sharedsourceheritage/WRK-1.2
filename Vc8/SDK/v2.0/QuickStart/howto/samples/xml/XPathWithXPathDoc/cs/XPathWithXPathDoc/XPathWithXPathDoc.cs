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
using System.Xml.XPath;
using System.Globalization;

namespace Microsoft.Samples.Xml 
{
    public class XPathWithXPathDocSample 
    {
        public static void Main() 
        {
            string document = @"..\..\books.xml";
            string selectExpr = String.Empty;
            XPathExpression xPathExpr;

            Console.WriteLine();
            Console.WriteLine("XPathExpression started ...");
            Console.WriteLine();

            XPathDocument xPathDocument = new XPathDocument(document);
            
            //Create an XPathNavigator
            XPathNavigator xPathNavigator = xPathDocument.CreateNavigator();
            
            //Get the Book elements
            selectExpr = "bookstore/book";
            
            Console.WriteLine("XPath query: " + selectExpr);

            //Ensure we are at the root node
            xPathNavigator.MoveToRoot();

            xPathExpr = xPathNavigator.Compile(selectExpr);

            Console.WriteLine();
            Console.WriteLine("Original order ...");
            Console.WriteLine();

            //Create an XPathNodeIterator to walk over the selected nodes
            XPathNodeIterator xPathNodeIterator = xPathNavigator.Select(xPathExpr);
            
            FormatXml(xPathNodeIterator);
            
            // Ensure we are at the root node
            xPathNavigator.MoveToRoot();

            Console.WriteLine();
            Console.WriteLine("Sort by ISBN (using IComparer - Text ascending)...");
            Console.WriteLine();

            // Create comparision class for the ISBN number
            //Remove: ISBNCompare myISBNCompare = new ISBNCompare();
            //Remove: StringComparer.Create(CultureInfo.InvariantCulture, true)
            
            // Add a comparer to do a string compare on the ISBN number
            xPathExpr.AddSort("@ISBN", StringComparer.Create(CultureInfo.InvariantCulture, true));
            xPathNodeIterator = xPathNavigator.Select(xPathExpr);
            
            FormatXml(xPathNodeIterator);
            
            // Create Second XPathNavigator
            XPathNavigator xPathNavigator2 = xPathDocument.CreateNavigator();

            // Ensure we are at the root node
            xPathNavigator2.MoveToRoot();
            xPathExpr = xPathNavigator2.Compile(selectExpr);
            
            Console.WriteLine();
            Console.WriteLine("Sort by publication date (using XSLT expression - Text descending) ...");
            Console.WriteLine();

            // Add an XSLT based sort
            xPathExpr.AddSort("@publicationdate", XmlSortOrder.Descending, XmlCaseOrder.None, "", XmlDataType.Text);
            xPathNodeIterator = xPathNavigator2.Select(xPathExpr);

            FormatXml(xPathNodeIterator);

            XmlDocument doc = new XmlDocument();
            doc.Load(document);

            //Navigate with the DOM API
            XmlNodeList nodes = doc.ChildNodes;

            Console.WriteLine("Writing with Navigate with DOM APIs");
            NavigateWithDom(nodes);

            //create an XpathNavigator on XmlDocument
            XPathNavigator nav = doc.CreateNavigator();

            //Navigate with XpathNavigator API
            Console.WriteLine("Writing with Navigate with Navigator APIs");
            NavigateWithNavigator(nav);

            Console.WriteLine("Press Enter to Exit");
            Console.ReadLine();
        }
 
        static void FormatXml (XPathNodeIterator nav) 
        {
            // Loop getting information about each node
            while (nav.MoveNext()) 
            {
                switch (nav.Current.NodeType) 
                {
                    case XPathNodeType.ProcessingInstruction:
                        Format (nav, "ProcessingInstruction");
                        break;
                    case XPathNodeType.Comment:
                        Format (nav, "Comment");
                        break;
                    case XPathNodeType.Element:
                        Format (nav, "Element");
                        break;
                    case XPathNodeType.Text:
                        Format (nav, "Text");
                        break;
                    case XPathNodeType.Whitespace:
                        Format (nav, "Whitespace");
                        break;
                    }
                }
                
                Console.WriteLine();
            }

        // Format the output
        static void Format (XPathNodeIterator nav, String nodeType) 
            {
                if (nav.Current.HasAttributes) 
                {
                    Console.Write("<" + nav.Current.Name);
                    
                    nav.Current.MoveToFirstAttribute();
                    
                    Console.Write(" " + nav.Current.Name + "=" + nav.Current.Value);
                    
                    while (nav.Current.MoveToNextAttribute())
                        Console.Write(" " + nav.Current.Name + "=" + nav.Current.Value);
                    
                    Console.Write(">");
                }
                // Return to the 'Parent' node of the attributes
                nav.Current.MoveToParent();
                Console.WriteLine("");
            }

        static void NavigateWithDom(XmlNodeList children)
        {
            if (children != null)
            {
                for (int i = 0; i < children.Count; i++)
                {
                    XmlNode node = children[i];
                    String name = node.Name;
                    String value = node.Value;
                    
                    if (name.Equals("title") || name.Equals("author") || name.Equals("price"))
                    {
                        Console.Write(name + ": ");
                    }
                    else
                    {
                        Console.WriteLine(value);
                    }
                    
                    XmlAttributeCollection attributes = node.Attributes;
                    if (attributes != null)
                    {
                        for (int j = 0; j < attributes.Count; j++)
                        {
                            String attName = attributes[j].Name;
                            if (attName.Equals("publisher"))
                            {
                                Console.WriteLine(attName + ": " + attributes[j].Value);
                            }
                        }
                    }
                    NavigateWithDom(node.ChildNodes);
                }
            }
        }

        static void NavigateWithNavigator(XPathNavigator nav)
        {
            //move to the first non PI no comment element
            nav.MoveToChild(XPathNodeType.Element);

            //get all the books
            XPathNodeIterator booksNodeIt = nav.SelectChildren(XPathNodeType.Element);

            while (booksNodeIt.MoveNext())
            {
                XPathNavigator nav1 = booksNodeIt.Current;
                nav1.MoveToFirstAttribute();
                string publisher = nav1.Value;
                string attName = nav1.Name;
                nav1.MoveToParent();

                XPathNodeIterator nodeIt = nav1.SelectChildren(XPathNodeType.Element);
                
                while (nodeIt.MoveNext())
                {
                    Console.WriteLine(nodeIt.Current.Name + ": " + nodeIt.Current.Value + "\t");
                }

                Console.WriteLine(attName + ": " + publisher + "\n\n");
                }
        }
}
}

