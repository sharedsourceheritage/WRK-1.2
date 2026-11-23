<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Select XML Data Using XPath?</h4>

<p>
This sample illustrates how to select XML data in an XML document using the XPath selection methods  
of the XmlDocument class. An XmlDocument object is used to load the XML document and to select XML data using
XPath queries. An XmlNamespaceManager object is used to map namespaces to namespace prefixes used in the XPath 
queries. Finally, the SelectNodes method of the XmlDocument class is used to select XML data from the XML 
document using XPath queries.
<p>
<Acme:LangSwitch runat="server">
  <CsTemplate>

<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XPathWithXmlDoc/XPathWithXmlDoc.src"
Icon = "/quickstart/images/genicon.gif"
Caption="C# XPathWithXmlDoc.exe"
SamplePath="howto\samples\Xml\XPathWithXmlDoc\"
CanBeHosted="false"
runat="server" />

  </CsTemplate>
  <VbTemplate>

<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XPathWithXmlDoc/XPathWithXmlDoc.src"
Icon = "/quickstart/images/genicon.gif"
Caption="VB XPathWithXmlDoc.exe"
SamplePath="howto\samples\Xml\XPathWithXmlDoc\"
CanBeHosted="false"
runat="server" />

  </VbTemplate>
  <CpTemplate>

<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XPathWithXmlDoc/XPathWithXmlDoc.src"
Icon = "/quickstart/images/genicon.gif"
Caption="C++ XPathWithXmlDoc.exe"
SamplePath="howto\samples\Xml\XPathWithXmlDoc\"
CanBeHosted="false"
runat="server" />

  </CpTemplate>
</Acme:LangSwitch>

<p>
The following code creates the XmlDocument object and loads the XML document.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
XmlDocument myXmlDocument = new XmlDocument();
myXmlDocument.Load(document);
</Tab>
<Tab Name="VB">
Dim myXmlDocument As New XmlDocument()
myXmlDocument.Load(document)
</Tab>
<tab name="C++">
XmlDocument^ xmlDocument = gcnew XmlDocument();
xmlDocument->Load(document);
</tab>
</Acme:TabControl>
<p>

<p>
The following code creates the XmlNamespaceManager object and maps namespaces to namespace prefixes used in the XPath 
queries.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
XmlNamespaceManager nsmanager = new XmlNamespaceManager(myXmlDocument.NameTable);
nsmanager.AddNamespace("ns", "http://tempuri.org/myBooksNamespace");
nsmanager.AddNamespace("myns", "http://tempuri.org/myBooksProcessornamespace");
nsmanager.AddNamespace("yourns1", "http://tempuri.org/myBook1namespace");
nsmanager.AddNamespace("yourns2", "http://tempuri.org/myBook2namespace");
</Tab>
<Tab Name="VB">
Dim nsmanager As New XmlNamespaceManager(myXmlDocument.NameTable)
nsmanager.AddNamespace("ns", "http://tempuri.org/myBooksNamespace")
nsmanager.AddNamespace("myns", "http://tempuri.org/myBooksProcessornamespace")
nsmanager.AddNamespace("yourns1", "http://tempuri.org/myBook1namespace")
nsmanager.AddNamespace("yourns2", "http://tempuri.org/myBook2namespace")
</Tab>
<tab name="C++">
XmlNamespaceManager^ nsmanager = gcnew XmlNamespaceManager(xmlDocument->NameTable);
nsmanager->AddNamespace("ns", "http://tempuri.org/myBooksNamespace");
nsmanager->AddNamespace("myns", "http://tempuri.org/myBooksProcessornamespace");
nsmanager->AddNamespace("yourns1", "http://tempuri.org/myBook1namespace");
nsmanager->AddNamespace("yourns2", "http://tempuri.org/myBook2namespace");
</tab>
</Acme:TabControl>
<p>

<p>
The following code selects XML data using an XPath query.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
XmlNodeList nodelist = myXmlDocument.SelectNodes("//yourns1:book", nsmanager);
</Tab>
<Tab Name="VB">
Dim nodelist As XmlNodeList = myXmlDocument.SelectNodes("//yourns1:book", nsmanager)
</Tab>
<tab name="C++">
XmlNodeList^ nodelist = xmlDocument->SelectNodes("//yourns1:book", nsmanager);
</tab>
</Acme:TabControl>
</asp:Content>