/*=====================================================================

  File:      Catalog.cs for Product Catalog XML Example
  Summary:   Winform for displaying a product catalog stored in
			 the AdventureWorks OLTP database.
  Date:	     April 27, 2004

---------------------------------------------------------------------
  This file is part of the Microsoft SQL Server Code Samples.
  Copyright (C) Microsoft Corporation.  All rights reserved.

  This source code is intended only as a supplement to Microsoft
  Development Tools and/or on-line documentation.  See these other
  materials for detailed information regarding Microsoft code samples.

  THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
  PARTICULAR PURPOSE.
======================================================= */

using System;
using System.Windows.Forms;
using System.Net;
using System.Net.Cache;
using System.IO;
using System.Globalization;
using System.Xml;
using System.Xml.XPath;
using System.Xml.Xsl;
using System.Web;

namespace Microsoft.Samples.SqlServer
{
    /// <summary>
    /// Summary description for form.
    /// </summary>
    public partial class Catalog : System.Windows.Forms.Form
    {
        const string prettyXmlXsltFileName = "..\\..\\defaultss.xslt";
        const string descriptionXsltFileName = "..\\..\\ProductDescription.xsl";

        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        public Catalog()
        {
            InitializeComponent();
        }

        private static string GetSoapRequestXml(int productModelID)
        {
            return
            "<soap:Envelope xmlns:xsi='http://www.w3.org/2001/XMLSchema-instance' xmlns:xsd='http://www.w3.org/2001/XMLSchema' xmlns:soap='http://schemas.xmlsoap.org/soap/envelope/'>" +
            "  <soap:Body>" +
            "    <GetProductDescription xmlns='testns'>" +
            "      <ProductModelID>" + productModelID.ToString(CultureInfo.InvariantCulture) + "</ProductModelID>" +
            "    </GetProductDescription>" +
            "  </soap:Body>" +
            "</soap:Envelope>";
        }


        private static Stream PostSoapRequest(string requestXml)
        {
            HttpWebRequest webRequest = (HttpWebRequest)WebRequest.Create("http://localhost/ProductCatalog/");
            webRequest.Accept = "text/xml";
            webRequest.Headers.Add(HttpRequestHeader.AcceptEncoding, "identity, gzip;q=0");
            webRequest.ContentType = "text/xml";
            webRequest.CachePolicy = new RequestCachePolicy(RequestCacheLevel.NoCacheNoStore);
            webRequest.Headers.Add("SOAPAction", "");
            webRequest.Credentials = CredentialCache.DefaultCredentials;
            webRequest.Method = "POST";

            Stream webStream = webRequest.GetRequestStream();
            using (StreamWriter webWriter = new StreamWriter(webStream))
            {
                try
                {
                    webWriter.Write(requestXml);
                    webWriter.Flush();
                }
                finally
                {
                    webWriter.Close();
                }
            }

            WebResponse response = webRequest.GetResponse();
            return response.GetResponseStream();

        }


        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1031:DoNotCatchGeneralExceptionTypes")]
        private void ShowDescriptionButton_Click(object sender, System.EventArgs e)
        {
            try
            {
                int productModelID = int.Parse(ProductModelIDTextBox.Text,
                    CultureInfo.InvariantCulture);
                String requestXML = GetSoapRequestXml(productModelID);
                using (Stream webResponseStream = PostSoapRequest(requestXML))
                {
                    XslCompiledTransform xslt = new XslCompiledTransform();
                    using (StreamReader xsltStreamReader = File.OpenText(descriptionXsltFileName))
                    {
                        using (XmlReader xsltXmlReader = XmlReader.Create(xsltStreamReader))
                        {
                            xslt.Load(xsltXmlReader);
                        }
                    }

                    XPathDocument xmlResults = new XPathDocument(webResponseStream);
                    XPathNavigator navigator = xmlResults.CreateNavigator();
                    XmlNamespaceManager namespaces = new XmlNamespaceManager(navigator.NameTable);
                    namespaces.AddNamespace("z", "http://schemas.microsoft.com/sqlserver/2004/07/adventure-works/ProductModelDescription");

                    XPathExpression expr = navigator.Compile("//z:ProductDescription");
                    expr.SetContext(namespaces);
                    XPathNodeIterator iterator = navigator.Select(expr);
					if (iterator.Count == 0)
						webBrowser1.DocumentText = string.Format("<BODY>Product {0} not found.<BODY>",
							productModelID);
					else
					{
						StringWriter resultStringWriter = new StringWriter(CultureInfo.InvariantCulture);
						XmlTextWriter resultXmlWriter = new XmlTextWriter(resultStringWriter);
						try
						{

							if (iterator.MoveNext())
							{
								xslt.Transform(iterator.Current.Clone(), new XsltArgumentList(), resultXmlWriter);
							}

							resultXmlWriter.Flush();
						}
						finally
						{
							resultXmlWriter.Close();
						}

						webBrowser1.DocumentText = resultStringWriter.ToString();
					}
                }
            }
            catch (System.Exception exception)
            {
                webBrowser1.DocumentText = exception.ToString();
            }
        }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1031:DoNotCatchGeneralExceptionTypes")]
        private void ShowResponseButton_Click(object sender, System.EventArgs e)
        {
            try
            {
                int productModelID = int.Parse(ProductModelIDTextBox.Text,
                    CultureInfo.InvariantCulture);
                String requestXML = GetSoapRequestXml(productModelID);
                using (Stream webResponseStream = PostSoapRequest(requestXML))
                {

                    XPathDocument xmlResults = new XPathDocument(webResponseStream);
                    TransformAndBrowseDocument(xmlResults);
                }
            }
            catch (System.Exception exception)
            {
                webBrowser1.DocumentText = exception.ToString();
            }
        }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1031:DoNotCatchGeneralExceptionTypes")]
        private void ShowRequestButton_Click(object sender, System.EventArgs e)
        {
            try
            {
                int productModelID = int.Parse(ProductModelIDTextBox.Text,
                    CultureInfo.InvariantCulture);
                TransformAndBrowseDocument(GetSoapRequestXml(productModelID));
            }
            catch (System.Exception exception)
            {
                webBrowser1.DocumentText = exception.ToString();
            }

        }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1031:DoNotCatchGeneralExceptionTypes")]
        private void ShowXSLButton_Click(object sender, System.EventArgs e)
        {
            try
            {
                using (StreamReader fs = File.OpenText(descriptionXsltFileName))
                {
                    {
                        TransformAndBrowseDocument(fs.ReadToEnd());
                    }
                }
            }
            catch (System.Exception exception)
            {
                webBrowser1.DocumentText = exception.ToString();
            }
        }

        private void TransformAndBrowseDocument(String xmlDocument)
        {

            using (StringReader sr = new StringReader(xmlDocument))
            {
                using (XmlTextReader xtr = new XmlTextReader(sr))
                {
                    XPathDocument doc = new XPathDocument(xtr);
                    TransformAndBrowseDocument(doc);
                }
            }
        }

        private void TransformAndBrowseDocument(XPathDocument doc)
        {
            XslCompiledTransform xslt = new XslCompiledTransform();
            using (StreamReader xsltStreamReader = File.OpenText(prettyXmlXsltFileName))
            {
                using (XmlReader xsltXmlReader = XmlReader.Create(xsltStreamReader))
                {
                    xslt.Load(xsltXmlReader);
                }
            }

            StringWriter resultStringWriter = new StringWriter(CultureInfo.InvariantCulture);
            XmlTextWriter resultXmlWriter = new XmlTextWriter(resultStringWriter);

            try
            {
                xslt.Transform(doc, new XsltArgumentList(), resultXmlWriter);
                resultXmlWriter.Flush();
            }
            finally
            {
                resultXmlWriter.Close();
            }

            webBrowser1.DocumentText = resultStringWriter.ToString();
        }
    }
}

