<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Modify XML with the XmlDocument Class? </h4>
<p>
This sample illustrates how to modify an XML document using classes based on the W3C Document Object Model (DOM). The DOM is an in-memory (cache) tree representation of an XML document and enables the navigation and editing of the document. This sample loads an XmlDocument object, modifies the XML data and saves the changes to an XML file.
<p>
<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/ModifyXmlDocument/ModifyXmlDocument.src"
Icon="../../../images/genicon.gif"
SamplePath="howto\samples\Xml\ModifyXmlDocument\"
CanBeHosted="false"
Caption="C# ModifyXmlDocument.exe"
runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/Xml/ModifyXmlDocument/ModifyXmlDocument.src"
RunSample=""
Icon="../../../images/genicon.gif"
SamplePath="howto\samples\Xml\ModifyXmlDocument\"
CanBeHosted="false"
Caption="VB ModifyXmlDocument.exe"
runat="server" />
  </VbTemplate>
  <CpTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/Xml/ModifyXmlDocument/ModifyXmlDocument.src"
RunSample=""
Icon="../../../images/genicon.gif"
SamplePath="howto\samples\Xml\ModifyXmlDocument\"
CanBeHosted="false"
Caption="C++ ModifyXmlDocument.exe"
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
<p>
The following code uses an XPath expression to identify an XML node. The node is then deleted.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
string xpath = "/bookstore/book[title='The Gorgias']";
XmlNode node = doc.SelectSingleNode(xpath);
node.ParentNode.RemoveChild(node);
</Tab>
<Tab Name="VB">
Dim xpath As String = "/bookstore/book[title='The Gorgias']"
Dim node As XmlNode = doc.SelectSingleNode(xpath)
node.ParentNode.RemoveChild(node)
</Tab>
<Tab Name="C++">
String^ xpath = "/bookstore/book[title='The Gorgias']";
XmlNode^ node = doc->SelectSingleNode(xpath);
node->ParentNode->RemoveChild(node);
</Tab>
</Acme:TabControl>
<p>
The following code shows how you can use the methods and properties on the XmlNode class to build a new sub-tree of nodes.
<Acme:TabControl runat="server">
<Tab Name="C#">
XmlNode bookstore = doc.DocumentElement;

XmlElement book = doc.CreateElement("book");
book.SetAttribute("genre", "novel");
book.SetAttribute("publicationdate", "1998");
book.SetAttribute("ISBN", "0-553-21311-03");

XmlElement title = doc.CreateElement("title"); 
title.InnerText  = "Moby Dick";
book.AppendChild(title);
...
bookstore.AppendChild(book); 
</Tab>
<Tab Name="VB">
Dim bookstore As XmlNode = doc.DocumentElement

Dim book As XmlElement = doc.CreateElement("book")
book.SetAttribute("genre", "novel")
book.SetAttribute("publicationdate", "1998")
book.SetAttribute("ISBN", "0-553-21311-03")

Dim title As XmlElement = doc.CreateElement("title")
title.InnerText = "Moby Dick"
book.AppendChild(title)
...
bookstore.AppendChild(book)
</Tab>
<Tab Name="C++">
XmlNode^ bookstore = doc->DocumentElement;

XmlElement^ book = doc->CreateElement("book");
book->SetAttribute("genre", "novel");
book->SetAttribute("publicationdate", "1998");
book->SetAttribute("ISBN", "0-553-21311-03");

XmlElement^ title = doc->CreateElement("title");
title->InnerText = "Moby Dick";
book->AppendChild(title);
...
bookstore->AppendChild(book);
</Tab>
</Acme:TabControl>
<p>
The following code increases the price for each book. The code shows how to use the XmlConvert.ToDouble method to convert the text value of the price element to Double  and calculate the new book price.
<Acme:TabControl runat="server">
<Tab Name="C#">
foreach (XmlNode node in doc.SelectNodes("//price"))
{
    node.InnerText = (XmlConvert.ToDouble(node.InnerText) * 1.2).ToString();
}

</Tab>
<Tab Name="VB">
Dim node As XmlNode
For Each node In doc.SelectNodes("//price")
    node.InnerText = XmlConvert.ToDouble(node.InnerText) * 1.2.ToString()
Next node
</Tab>
<Tab Name="C++">
XmlNodeList^ nodeList;
nodeList = doc->SelectNodes( L"//price" );
IEnumerator^ nodeListEnum = nodeList->GetEnumerator();
while (nodeListEnum->MoveNext())
{
    XmlNode^ node = safe_cast<XmlNode^>(nodeListEnum->Current);
    node->InnerText = XmlConvert::ToString((XmlConvert::ToDouble(node->InnerText) * 1.2));
}
</Tab>
</Acme:TabControl>
<h4>Summary</h4>
<ol>
<li>The XmlDocument, XmlNode and other classes implement the W3C Document Object Model Level 1 Core and the Core DOM Level 2 specifications.
<li>The XmlDocument is an in-memory (cache) tree representation of an XML document.
<li>There are different node types specializing from XmlNode to enable you to manipulate the XML document.
</ol>
<p>

</asp:Content>

