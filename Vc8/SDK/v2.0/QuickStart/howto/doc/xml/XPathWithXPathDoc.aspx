<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>
<h4>How Do I...Process XML Data Using XPath?</h4>

<p>
This sample illustrates how to process XML data using the XPathNavigator class. An XPathDocument object is used to load the XML document, and to return an XPathNavigator object. The XPathNavigator object is then used to create a compiled XPath expression in an XPathExpression object. The selection methods of the XPathNavigator object then select XML data using the compiled XPath expression. Finally, the navigation methods of the XPathNavigator and XmlDocument classes are used to navigate the XML data in the XML document.
<p>
<Acme:LangSwitch runat="server">
  <CsTemplate>

<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XPathWithXPathDoc/XPathWithXPathDoc.src"
Icon = "/quickstart/images/genicon.gif"
Caption="C# XPathWithXPathDoc.exe"
SamplePath="howto\samples\Xml\BinaryDataInXml\"
CanBeHosted="false"
runat="server" />

  </CsTemplate>
  <VbTemplate>

<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XPathWithXPathDoc/XPathWithXPathDoc.src"
Icon = "/quickstart/images/genicon.gif"
Caption="VB XPathWithXPathDoc.exe"
SamplePath="howto\samples\Xml\BinaryDataInXml\"
CanBeHosted="false"
runat="server" />

  </VbTemplate>
 
</Acme:LangSwitch>

<p>
The following code creates the XPathDocument object and loads the XML document.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
XPathDocument xPathDocument = new XPathDocument(document);
</Tab>
<Tab Name="VB">
Dim xPathDocument As New XPathDocument(document)
</Tab>
</Acme:TabControl>
<p>

<p>
The following code returns an XPathNavigator object from the XPathDocument object.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
XPathNavigator xPathNavigator = xPathDocument.CreateNavigator();
</Tab>
<Tab Name="VB">
Dim xPathNavigator As XPathNavigator = xPathDocument.CreateNavigator()
</Tab>
</Acme:TabControl>
<p>

<p>
The following code creates a compiled XPath expression in an XPathExpression object using the XPathNavigator object.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
xPathExpr = xPathNavigator.Compile(selectExpr);
</Tab>
<Tab Name="VB">
xPathExpr = xPathNavigator.Compile(selectExpr)
</Tab>
</Acme:TabControl>
<p>

<p>
The following code selects XML data using the compiled XPath expression.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
XPathNodeIterator xPathNodeIterator = xPathNavigator.Select(xPathExpr);
</Tab>
<Tab Name="VB">
Dim xPathNodeIterator As XPathNodeIterator = xPathNavigator.Select(xPathExpr)
</Tab>
</Acme:TabControl>
</asp:Content>