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
using System.Xml.Schema;
using System.Xml.Serialization;

namespace Microsoft.Samples.Xml
{
    class XmlSchemaValidatorSample 
    {
        static string document = @"..\..\books.xml";
        static string xsdDocument = @"..\..\books.xsd";
        
        public static void Main(){
            XmlSchemaInfo schemaInfo = new XmlSchemaInfo();
            XmlSerializer serializer = null;
            Books myBooks = null;

            using (TextReader reader = new StreamReader(document))
            {
                serializer = new XmlSerializer(typeof(Books));
                myBooks = (Books)serializer.Deserialize(reader);
            }

            XmlSchemaValidator xsv = CreateValidator();
            xsv.Initialize();

            xsv.ValidateElement("books", "http://www.example.com/my-bookshelf", schemaInfo);

            xsv.ValidateEndOfAttributes(schemaInfo);

            foreach (BookType book in myBooks.book)
            {
                xsv.ValidateElement("book", "http://www.example.com/my-bookshelf", schemaInfo);

                if (book.publisher != null)
                {
                    xsv.ValidateAttribute("publisher", string.Empty, book.publisher, schemaInfo);
                }

                if (book.onloan != null)
                {
                    xsv.ValidateAttribute("on-loan", string.Empty, book.onloan, schemaInfo);
                }

                xsv.ValidateEndOfAttributes(schemaInfo);

                xsv.ValidateElement("title", "http://www.example.com/my-bookshelf", schemaInfo);
                xsv.ValidateEndElement(null, book.title);

                xsv.ValidateElement("author", "http://www.example.com/my-bookshelf", schemaInfo);
                xsv.ValidateEndElement(null, book.author);

                xsv.ValidateElement("publication-date", "http://www.example.com/my-bookshelf", schemaInfo);
                xsv.ValidateEndElement(null, book.publicationdate);

                xsv.ValidateEndElement(schemaInfo);
            }

            xsv.ValidateEndElement(schemaInfo);

            xsv.EndValidation();

            Console.WriteLine("Schema validated.");
            Console.WriteLine();
            Console.WriteLine("Press Enter to Exit");
            Console.ReadLine();
        }

      static XmlSchemaValidator CreateValidator()
      {
          NameTable nt = new NameTable();
          
          XmlSchemaSet schemaSet = new XmlSchemaSet();
          schemaSet.Add("http://www.example.com/my-bookshelf", xsdDocument);

          XmlNamespaceManager nsmgr = new XmlNamespaceManager(nt);

          XmlSchemaValidationFlags flags = XmlSchemaValidationFlags.None;

          return new XmlSchemaValidator(nt, schemaSet, nsmgr, flags);
      }

    }
     
    /// <remarks/>
    [System.Xml.Serialization.XmlRootAttribute("books", Namespace = "http://www.example.com/my-bookshelf", IsNullable = false)]
    public class Books
    {
        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("book")]
        public BookType[] book;
    }

    /// <remarks/>
    public class BookType
    {
        /// <remarks/>
        public string title;

        /// <remarks/>
        public string author;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("publication-date", DataType = "date")]
        public System.DateTime publicationdate;

        /// <remarks/>
        public System.Decimal price;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute("publisher")]
        public string publisher;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute("on-loan")]
        public string onloan;
    }
}
