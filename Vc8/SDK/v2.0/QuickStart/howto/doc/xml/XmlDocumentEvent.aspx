<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Handle Events from XmlDocument?</h4>

<p>
This sample illustrates how to receive and handle events when nodes in an XML document change. In particular, this sample demonstrates how to catch the NodeChanged and NodeInserted events described in the following paragraphs.

<p>
Modifying an XmlDocument can result in one or more of the following events:
<UL>
<LI>The NodeInserted event occurs when any node belonging to XmlDocument has been inserted into another node. This includes all nodes that were created by this document, whether they are inside or outside the document tree, including attribute nodes.
<LI>The NodeRemoved event occurs when any node belonging to this document has been removed from its parent. This includes all nodes that were created by this document, whether they are inside or outside the document tree, including attribute nodes.
<LI>The NodeChanged event occurs when the Value property of any node belonging to this document has been changed. This applies only to nodes that have a Value property.
<LI>The NodeInserting, NodeRemoving, or NodeChanging events occur when any node belonging to this document is about to be inserted, removed, or changed.
</UL>
<p>
These events enable you to throw an exception if you want to stop the operation. The XmlDocument guarantees that, after throwing the exception, the document is in the state it was in before the operation was started.


<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XmlDocumentEvent/XmlDocumentEvent.src"
Icon="../../../images/genicon.gif"
Caption="C# XmlDocumentEvent.exe"
SamplePath="howto\samples\Xml\XmlDocumentEvent\"
CanBeHosted="false"
runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XmlDocumentEvent/XmlDocumentEvent.src"
Icon="../../../images/genicon.gif"
Caption="VB XmlDocumentEvent.exe"
SamplePath="howto\samples\Xml\XmlDocumentEvent\"
CanBeHosted="false"
runat="server" />
  </VbTemplate>
  <CpTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XmlDocumentEvent/XmlDocumentEvent.src"
Icon="../../../images/genicon.gif"
Caption="C++ XmlDocumentEvent.exe"
SamplePath="howto\samples\Xml\XmlDocumentEvent\"
CanBeHosted="false"
runat="server" />
  </CpTemplate>
  
 <VjsTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XmlDocumentEvent/XmlDocumentEvent.src"
Icon="../../../images/genicon.gif"
Caption="J# XmlDocumentEvent.exe"
SamplePath="howto\samples\Xml\XmlDocumentEvent\"
CanBeHosted="false"
runat="server" />
  </VjsTemplate>
  
</Acme:LangSwitch>

<p>
After loading the books.xml file into an XmlDocument, this sample application both modifies the price of the existing books within the document and adds new books to the document. These changes result in NodeChanged and NodeInserted events.
<p>
The following sample code constructs an XmlDocument and loads books.xml.

<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
XmlDocument xmlDocument = new XmlDocument();
xmlDocument.Load (args);
</Tab>
<Tab Name="VB">
Dim xmlDocument as XmlDocument  = new XmlDocument()
xmlDocument.Load (args)
</Tab>
<Tab Name="C++">
XmlDocument^ xmlDocument = gcnew XmlDocument();
xmlDocument->Load (args);
</Tab>
<Tab Name="J#">
XmlDocument xmlDocument = new XmlDocument();
xmlDocument.Load(args);
</Tab>
</Acme:TabControl>
<p>
When the sample loads books.xml, the sample adds the NodeChanged and a NodeInserted event handlers the XmlDocument. The code for these handlers appears later in this topic.

<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
xmlDocument.NodeChanged += new XmlNodeChangedEventHandler(this.NodeChangedEvent);
xmlDocument.NodeInserted += new XmlNodeChangedEventHandler(this.NodeInsertedEvent);
</Tab>
<Tab Name="VB">
AddHandler xmlDocument.NodeChanged, new XmlNodeChangedEventHandler(addressof NodeChangedEvent)
AddHandler xmlDocument.NodeInserted, new XmlNodeChangedEventHandler(addressof NodeInsertedEvent)
</Tab>
<Tab Name="C++">
xmlDocument->NodeChanged += gcnew XmlNodeChangedEventHandler
  (this,&XmlDocumentEventSample::NodeChangedEvent);
xmlDocument->NodeInserted += gcnew XmlNodeChangedEventHandler
  (this,&XmlDocumentEventSample::NodeInsertedEvent);
</Tab>
<Tab Name="J#">
xmlDocument.add_NodeChanged(new XmlNodeChangedEventHandler(
    this.MyNodeChangedEvent));
xmlDocument.add_NodeInserted(new XmlNodeChangedEventHandler(
    this.MyNodeInsertedEvent));
</Tab>
</Acme:TabControl>

<p>
The sample application changes data with the document by increasing the price of each book by 2%. To do this, the sample must first select the data to be changed by using the SelectNodes method of the XmlNode class. By using the XML Path Language (Xpath) expression "descendant::book/price", with the SelectNodes method, the sample selects the price child elements of all the book elements. The application then places these selected nodes into an XmlNodeList where they can be edited to reflect a 2% price increase. This price increase operation consists of getting the InnerText value of the price element, increasing it by 2%, and then inserting the modified value back into the element. Each time the price element changes, there is a NodeChanged event that writes the new price to the screen. The code for the NodeChanged event appears later in this topic.

<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
// Increase all the book prices by 2%
...
// Create a list of the <book> nodes and change their values
XmlNodeList xmlNodeList = xmlDocument.SelectNodes("descendant::book/price");

foreach (XmlNode xmlNode in xmlNodeList)
{
    Console.WriteLine("<" + xmlNode.Name + "> " + xmlNode.InnerText);
    Double price = Double.Parse(xmlNode.InnerText);
    xmlNode.InnerText = (((Double)price * 1.02).ToString("#.00"));
}
</Tab>
<Tab Name="VB">
' Increase all the book prices by 2%
...
' Create a list of the <book> nodes and change their values
Dim xmlNodeList As XmlNodeList = xmlDocument.SelectNodes("descendant::book/price")

Dim xmlNode As XmlNode
For Each xmlNode In xmlNodeList
    Console.WriteLine("<" + xmlNode.Name + "> " + xmlNode.InnerText)
    Dim price As [Double] = [Double].Parse(xmlNode.InnerText)
    xmlNode.InnerText = (CType(price, [Double]) * 1.02).ToString("#.00")
Next xmlNode
</Tab>
<Tab Name="C++">
// Increase all the book prices by 2%
...
// Create a list of the <book> nodes and change their values
XmlNodeList^ xmlNodeList = xmlDocument->SelectNodes("descendant::book/price");
			
for each (XmlNode^ xmlNode in xmlNodeList)
{
    Console::WriteLine("<" + xmlNode->Name + "> " + xmlNode->InnerText);
    Double price = Double::Parse(xmlNode->InnerText);
    Double newPrice = (Double)price * 1.02;
    xmlNode->InnerText = newPrice.ToString("#.00");
}
</Tab>
<Tab Name="J#">
// Create a list of the <book> nodes and change their values
XmlNodeList xmlNodeList = xmlDocument.SelectNodes("descendant::book/price");
for (int iCtr = 0; iCtr < xmlNodeList.get_Count(); iCtr++) {
    XmlNode xmlNode = xmlNodeList.get_ItemOf(iCtr);
    Console.WriteLine("<" + xmlNode.get_Name() + "> " 
        + xmlNode.get_InnerText());
    double price = System.Double.Parse(xmlNode.get_InnerText());
    xmlNode.set_InnerText(((
    System.Double)(price * 1.02)).ToString("#.00"));
}
</Tab>
</Acme:TabControl>
<p>
The sample application also inserts a node into the XmlDocument. A simple way to insert a new node is to create an XmlDocumentFragment, determine where in the document you want to insert the fragment, and then use the InsertBefore or InsertAfter methods of the XmlDocument. As shown in the following code, the sample creates the XmlDocumentFragment with a string of prepared XML and then inserts this fragment into myXmlDocument. By inserting a new node, there is a NodeInserted event that writes the new node information to the screen. The code for the NodeInserted event appears later in this topic.

<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
// Create a new book
XmlDocumentFragment newBook = xmlDocument.CreateDocumentFragment();

newBook.InnerXml = ("<book genre=\" Object-Orientated Technology \" publicationdate=\" 1994 \" " +
  "ISBN=\"0-201-63361-2\">" +
  "<title>Design Patterns - Elements of Reusable Object-Orientated Software</title>" +
  "<author>" +
  "<first-name>Eric</first-name>" +
  "<last-name>Gamma</last-name>" +
  "</author>" +
  "<price>49.95</price>" +
  "</book>");

XmlElement rootXmlElement = xmlDocument.DocumentElement;

// Add the new book to the XmlDocument
rootXmlElement.InsertBefore(newBook, rootXmlElement.FirstChild);
...
// Clone the node and note that by cloning the node we
// are inserting it again into the XmlDocument
XmlNode newBook2 = xmlDocument.DocumentElement.FirstChild.Clone();
</Tab>
<Tab Name="VB">
' Create a new book
Dim newBook as XmlDocumentFragment  = myXmlDocument.CreateDocumentFragment()

newBook.InnerXml = ("<book genre="" Object-Orientated Technology "" publicationdate="" 1994 "" " & _
  "ISBN=""0-201-63361-2"">" & _
  "<title>Design Patterns - Elements of Reusable Object-Orientated Software</title>" & _
  "<author>" & _
  "<first-name>Eric</first-name>" & _
  "<last-name>Gamma</last-name>" & _
  "</author>" & _
  "<price>49.95</price>" & _
  "</book>")

Dim rootXmlElement as XmlElement  = myXmlDocument.DocumentElement

' Add the new book to the XmlDocument
rootXmlElement.InsertBefore(newBook, rootXmlElement.FirstChild)
...
' Clone the node and note that by cloning the node we
' are inserting it again into the XmlDocument
Dim newBook2 as XmlNode  = xmlDocument.DocumentElement.FirstChild.Clone()
</Tab>
<Tab Name="C++">
// Create a new book
XmlDocumentFragment^ newBook = myXmlDocument->CreateDocumentFragment();

newBook->InnerXml = (String::Concat(S"<book genre=\" Object-Orientated Technology \" publicationdate=\" 1994 \" ",
  S"ISBN=\"0-201-63361-2\">",
  S"<title>Design Patterns - Elements of Reusable Object-Orientated Software</title>",
  S"<author>",
  S"<first-name>Eric</first-name>",
  S"<last-name>Gamma</last-name>",
  S"</author>",
  S"<price>49.95</price>",
  S"</book>"));

XmlElement^ rootXmlElement = xmlDocument->DocumentElement;

// Add the new book to the XmlDocument
rootXmlElement->InsertBefore(newBook, rootXmlElement->FirstChild);
...
// Clone the node and note that by cloning the node we
// are inserting it again into the XmlDocument
XmlNode^ newBook2 = myXmlDocument->DocumentElement->FirstChild->Clone();
</Tab>
<Tab Name="J#">
XmlDocumentFragment newBook = xmlDocument.CreateDocumentFragment();

newBook.set_InnerXml("<book genre=\" Object-Orientated Technology" 
  + " \" publicationdate=\" 1994 \" " + "ISBN=\"0-201-63361-2\">" 
  + "<title>Design Patterns - Elements of Reusable " 
  + "Object-Orientated Software</title>" + "<author>" 
  + "<first-name>Eric</first-name>" + "<last-name>Gamma</last-name>" 
  + "</author>" + "<price>49.95</price>" + "</book>");

XmlElement rootXmlElement = xmlDocument.get_DocumentElement();
// Add the new book to the XmlDocument
rootXmlElement.InsertBefore(newBook, 
...
XmlNode newBook2 = xmlDocument.get_DocumentElement().get_FirstChild().Clone();
</Tab>
</Acme:TabControl>

<p>
The following code describes  the functions that handle the NodeChanged and NodeInserted events.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
// Handle the Node Changed Event
public void NodeChangedEvent(Object src, XmlNodeChangedEventArgs args)
{
    Console.Write("Node Changed Event: <" + args.Node.Name + "> changed");
    if (args.Node.Value != null)
    {
        Console.WriteLine(" with value " + args.Node.Value);
    }
    else
        Console.WriteLine("");
}

// Handle the Node Inserted Event
public void NodeInsertedEvent(Object src, XmlNodeChangedEventArgs args)
{
    Console.Write("Node Inserted Event: <" + args.Node.Name + "> inserted");
    if (args.Node.Value != null)
    {
        Console.WriteLine(" with value " + args.Node.Value);
    }
    else
        Console.WriteLine("");
}
</Tab>
<Tab Name="VB">
' Handle the Node Changed Event
public sub NodeChangedEvent(src as Object , args as XmlNodeChangedEventArgs )
    Console.Write("Node Changed Event: <" + args.Node.Name + "> changed")
    if not (args.Node.Value is Nothing) then
        Console.WriteLine(" with value " + args.Node.Value)
    else
        Console.WriteLine("")
    end if
end sub

' Handle the Node Inserted Event
public sub NodeInsertedEvent(src as Object , args as XmlNodeChangedEventArgs )
    Console.Write("Node Inserted Event: <" + args.Node.Name + "> inserted")
    if not (args.Node.Value is Nothing) then
        Console.WriteLine(" with value " + args.Node.Value)
    else
        Console.WriteLine("")
    end if
end sub
</Tab>
<Tab Name="C++">
// Handle the Node Changed Event
void NodeChangedEvent(Object^ src, XmlNodeChangedEventArgs* args)
{
	Console::Write(String::Concat(S"Node Changed Event: <", args->Node->Name, S"> changed"));
	if (args->Node->Value != 0)
	{
	Console::WriteLine(String::Concat(S" with value ", args->Node->Value));
	}
	else
	Console::WriteLine(S"");
}

// Handle the Node Inserted Event
void NodeInsertedEvent(Object^ src, XmlNodeChangedEventArgs* args)
{
	Console::Write(String::Concat(S"Node Inserted Event: <", args->Node->Name, S"> inserted"));
	if (args->Node->Value != 0)
	{
	Console::WriteLine(String::Concat(S" with value ", args->Node->Value));
	}
	else
	Console::WriteLine("");
}
</Tab>
<Tab Name="J#">
// Handle the Node Changed Event
public void MyNodeChangedEvent(Object src, XmlNodeChangedEventArgs args)
{
    Console.Write("Node Changed Event: <" + args.get_Node().get_Name() 
        + "> changed");
    if (args.get_Node().get_Value() != null) {
        Console.WriteLine(" with value " + args.get_Node().get_Value());
    }
    else {
        Console.WriteLine("");
    }
} 

// Handle the Node Inserted Event
public void MyNodeInsertedEvent(Object src, XmlNodeChangedEventArgs args)
{
    Console.Write("Node Inserted Event: <" 
        + args.get_Node().get_Name() + "> inserted");
    if (args.get_Node().get_Value() != null) {
        Console.WriteLine(" with value " + args.get_Node().get_Value());
    }
    else {
        Console.WriteLine("");
    }
}

</Tab>
</Acme:TabControl>
<p>

<H4>Summary</H4>
<OL>
<LI>To edit node values, first use SelectNodes to select the nodes and then place the selected nodes into an XmlNodeList.
<LI>There are six node events that can be handled: NodeInserted, NodeRemoved, NodeChanged, NodeInserting, NodeRemoving, or NodeChanging.
<LI>To handle nodes, add the node handler to your instance of XmlDocument.
</OL>

<p>
</asp:Content>










































































































