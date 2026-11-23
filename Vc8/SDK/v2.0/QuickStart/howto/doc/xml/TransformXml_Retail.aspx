<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Apply an XSL Transformation to XML?</h4>

<p>
This sample illustrates how to apply an Extensible Stylesheet Language Transformations (XSLT) file to an XML document using the XslCompiledTransform class. This class implements the World Wide Web Consortium (W3C) <A href="http://www.w3.org/TR/xslt">W3C XSL Transformations (XSLT) version 1.0</A> specification. For more information, see the <A href="http://www.w3.org/TR/xsl/">W3C Extensible Stylesheet Language (XSL) Version 1.0</A> specification.
<p>
<Acme:LangSwitch runat="server">
  <CsTemplate>

<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/TransformXML_Retail/TransformXML.src"
Icon = "/quickstart/images/genicon.gif"
Caption="C# TransformXML.exe"
SamplePath="howto\samples\Xml\TransformXML_Retail\"
CanBeHosted="false"
runat="server" />

  </CsTemplate>
  <VbTemplate>

<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/TransformXML_Retail/TransformXML.src"
Icon = "/quickstart/images/genicon.gif"
Caption="VB TransformXML.exe"
SamplePath="howto\samples\Xml\TransformXML_Retail\"
CanBeHosted="false"
runat="server" />

  </VbTemplate>
  <CpTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/TransformXML_Retail/TransformXML.src"
Icon = "/quickstart/images/genicon.gif"
Caption="C++ TransformXML.exe"
SamplePath="howto\samples\Xml\TransformXML_Retail\"
CanBeHosted="false"
runat="server" />

  </CpTemplate>
</Acme:LangSwitch>

<p>
XSLT is an XML-based language designed to transform one XML document into another XML document, or into any other structured document. XSLT uses the XML Path Language (XPath) to perform queries on an XML document in order to specify a particular part of the document. For more information about how to use XPath to query an XML document, see <a target=content href="XPathWithXPathDoc.aspx">How Do I...Query XML with an XPath expression?</a>.
<p>
Often, the structure of an XML document does not match the structure needed to process the XML data. To transform the existing structure into one that can be processed, you use an XSLT processor and an XSLT style sheet (or XSLT file) that defines how to do the transformation. The XSLT file consists of templates that specify how each node of the source XML document should appear in the destination XML document. Thus, the XSLT processor holds three trees:

<ol>
<LI>One tree for the source XML.
<LI>One tree for the destination structure.
<LI>One tree for the XSLT file.

<p>
The following diagram illustrates the transformation process: taking in an XML document, applying the XSLT file to the nodes of the XML document, and generating another document of the desired format.

<p>
<img border="0" alt="Diagram illustrating the XSLT transformation process." class="indent" src="XSL.gif" width="569" height="359">

<p>
This sample consists of two functions. The first function simply reads an XML document and then transforms the data using an XSLT file. The second function reads an XML document, transforms the data, and then writes a new XML document from the transformed data.
<p>
The sample applies these two functions to three sets of documents:
<ol>
<li>The documents in the first set are the XML document, books.xml, and the XSLT file, books.xsl. The XSLT file consists of templates that get all the books in the bookstore element and then, for each book element, get the values for the ISBN attribute and the price element. There is also a template that tells the XSLT processor to start processing from the root ("/") node.
<li>The documents in the second set are the XML document, ProcessParametersA.xml, and the XSLT file, StyleSheetGenerator.xsl. In this case, the sample reads the XML document to find out which of two style sheets contained in the XSLT file to use. The sample then generates the specified style sheet.
<li>The documents in the third set are the XML document, ProcessParametersB.xml, and the XSLT file, StyleSheetGenerator.xsl. The sample processes these documents in the same way that it processes the second set of documents. However, in this case, the sample generates a different style sheet.
</ol>

<p>
The following code transforms data and writes the results to the screen. The Load method loads and compiles the style sheet. The Transform method performs the transformation.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
XslCompiledTransform processor = new XslCompiledTransform();
processor.Load(args[1]);
//Transform the file.
processor.Transform(args[0], null, Console.Out);
</Tab>
<Tab Name="VB">
Dim processor As New XslCompiledTransform()
processor.Load(args(1))
'Transform the file.
processor.Transform(args(0), Nothing, Console.Out)
</Tab>
<Tab Name="C++">
XslCompiledTransform^ processor = gcnew XslCompiledTransform();
processor->Load(args[1]);
//Transform the file.
processor->Transform(args[0], nullptr, Console::Out);
</Tab>
</Acme:TabControl>
<p>
<H4>Summary</H4>
<OL>
<LI>XSLT is a language for transforming XML documents into other XML documents using XPath as the query language.
<LI>Use the Load method to compile an XSLT style sheet (or XSLT file).
<LI>The Transform method performs the transformation.
<LI>The XslCompiledTransform class can transform over any data that implements the IXPathNavigable interface. 
<LI>You can combine XSLT files to produce the required structure output format (for example, XML or HTML).
<LI>XSLT processors do not manipulate documents. They manipulate document structure.
</OL>
</asp:Content>


















