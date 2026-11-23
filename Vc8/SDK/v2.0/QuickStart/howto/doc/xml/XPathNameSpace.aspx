<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Handle Namespaces in XPath Queries with XmlNamespaceManager?</h4>

<p>This sample shows how to select namespace specific XML data from an XmlDocument. It demonstrates the use of the XmlNamespaceManager class. This class encapsulates a collection of namespaces and provides a variety of namespace management tasks, such as resolving, adding, and removing namespaces to a collection, and providing scope management for the namespaces. 
<p>
<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XPathNameSpace/XPathNameSpace.src"
Icon="../../../images/genicon.gif"
Caption="C# XPathNameSpace.exe"
SamplePath="howto\samples\Xml\XPathNameSpace\"
CanBeHosted="false"
runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/Xml/XPathNameSpace/XPathNameSpace.src"
RunSample=""
Icon="../../../images/genicon.gif"
SamplePath="howto\samples\Xml\XPathNameSpace\"
CanBeHosted="false"
Caption="VB XPathNameSpace.exe"
runat="server" />
  </VbTemplate>
  <CpTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/Xml/XPathNameSpace/XPathNameSpace.src"
RunSample=""
Icon="../../../images/genicon.gif"
SamplePath="howto\samples\Xml\XPathNameSpace\"
CanBeHosted="false"
Caption="C++ XPathNameSpace.exe"
runat="server" />
  </CpTemplate>
 <VjsTemplate>
       <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
        runat="server" />
  </VjsTemplate>
</Acme:LangSwitch>
<p>First, the sample creates an XmlDocument and loads the orders.xml file into the XmlDocument. 
<Acme:TabControl runat="server">
<Tab Name="C#">
XmlDocument myXmlDocument = new XmlDocument();
myXmlDocument.Load(args);
</Tab>
<Tab Name="VB">
Dim myXmlDocument As XmlDocument = New XmlDocument()
myXmlDocument.Load(args)
</Tab>
<Tab Name="C++">
XmlDocument* myXmlDocument = new XmlDocument();
myXmlDocument->Load(args);
</Tab>
</Acme:TabControl>
<p>To get all the item elements for the yourns1 namespace, the samples uses the following XPath expression: //yourns1:item. The sample also creates an XmlNamespaceManager that contains the prefixes and namespaces in the XML document. 
<p>
The orders.xml document defines two prefixes: myns for http://tempuri.org/myUSorderprocessornamespace and yourns1 for http://tempuri.org/USvendor1namespace. The document also has the default namespace of http://tempuri.org/myUSordersnamespace which we will map to the "ns" namespace. The reason for needing a prefix for the default namespace in our XPath query is due to the fact that in XPath, there is no concept of a default namespace. Instead elements and attributes that have a namespace require a prefix for matching while unprefixed names in queries can only be used for elements or that do not have a namespace (i.e. are in the null namespace). 
<Acme:TabControl runat="server">
<Tab Name="C#">
exprString = String.Format("// {0}:item", "yourns1");

// Create an XmlNamespaceManager and add the namespaces for the document.
XmlNamespaceManager nsmanager = new XmlNamespaceManager(myXmlDocument.NameTable);

// Map namespaces to prefixes for querying purposes.
nsmanager.AddNamespace("defaultns", "http://tempuri.org/myUSordersnamespace");
nsmanager.AddNamespace("myns", "http://tempuri.org/myUSorderprocessornamespace");
nsmanager.AddNamespace("yourns1", "http://tempuri.org/USvendor1namespace");
nsmanager.AddNamespace("yourns2", "http://tempuri.org/USvendor2namespace");
</Tab>
<Tab Name="VB">
exprString = String.Format("//{0}:item", "yourns1")

'Create an XmlNamespaceManager and add the namespaces for the document.
Dim nsmanager As XmlNamespaceManager = New XmlNamespaceManager(myXmlDocument.NameTable)

'Map namespaces to prefixes for querying purposes.
nsmanager.AddNamespace("defaultns", "http://tempuri.org/myUSordersnamespace")
nsmanager.AddNamespace("myns", "http://tempuri.org/myUSorderprocessornamespace")
nsmanager.AddNamespace("yourns1", "http://tempuri.org/USvendor1namespace")
nsmanager.AddNamespace("yourns2", "http://tempuri.org/USvendor2namespace")
</Tab>
<Tab Name="C++">
exprString = String::Format(S"//{0}:item", S"yourns1");

//Create an XmlNamespaceManager and add the namespaces for the document.
XmlNamespaceManager* nsmanager = new XmlNamespaceManager(myXmlDocument->NameTable);

//Map namespaces to prefixes for querying purposes.
nsmanager->AddNamespace(S"defaultns", S"http://tempuri.org/myUSordersnamespace");
nsmanager->AddNamespace(S"myns", S"http://tempuri.org/myUSorderprocessornamespace");
nsmanager->AddNamespace(S"yourns1", S"http://tempuri.org/USvendor1namespace");
nsmanager->AddNamespace(S"yourns2", S"http://tempuri.org/USvendor2namespace");
</Tab>
</Acme:TabControl>
<p>This sample then calls the SelectNodes method on the XmlDocument. In this case, the SelectNodes method finds all item nodes with a yourns1 prefix that resolves to the namespace, http://tempuri.org/USvendor1namespace. 

<p>The SelectNodes method returns an XmlNodeList. The sample then display this node list. 
<Acme:TabControl runat="server">
<Tab Name="C#">
XmlNodeList nodelist = myXmlDocument.SelectNodes(exprString, nsmanager);

foreach (XmlNode myXmlNode in nodelist)
{
   DisplayTree(myXmlNode);
}
</Tab>
<Tab Name="VB">
Dim nodelist As XmlNodeList = myXmlDocument.SelectNodes(exprString, nsmanager)

Dim myXmlNode As XmlNode
For Each myXmlNode In nodelist
  DisplayTree(myXmlNode)
Next
</Tab>
<Tab Name="C++">
XmlNodeList* nodelist = myXmlDocument->SelectNodes(exprString, nsmanager);

for (int i = 0; i < nodelist->Count; i++)
{
   DisplayTree(nodelist->Item(i));
}
</Tab>
</Acme:TabControl>
</asp:Content>

