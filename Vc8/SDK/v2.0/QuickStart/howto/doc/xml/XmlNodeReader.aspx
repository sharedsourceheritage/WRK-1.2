<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix="Acme" Namespace="Acme" %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx" %>

<asp:Content ID="Content1" ContentPlaceHolderID="MainBody" runat="Server">
    <h4>
        How Do I...Use an XmlNodeReader?</h4>
    <p>
        This sample illustrates how to create and use an XmlNodeReader. An XmlNodeReader
    is a reader that provides fast, non-cached, forward-only access to XML data in an
    XmlNode. It has the ability to read an entire XML DOM tree or read from just a subtree.
    However, the XmlNodeReader does not support Document Type Definition (DTD) or schema
    validation, and therefore does not validate the XML it is reading.
    <p>
        This sample loads the books.xml into an XmlDocument, and then uses an XmlNodeReader
    to select a node and display the node value to the screen.
    <p>
        <Acme:LangSwitch runat="server">
            <cstemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XmlNodeReader/XmlNodeReader.src"
Icon="../../../images/genicon.gif"
Caption="C# XmlNodeReader.exe"
SamplePath="howto\samples\Xml\XmlNodeReader\"
CanBeHosted="false"
runat="server"
/>
  </cstemplate>
            <vbtemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XmlNodeReader/XmlNodeReader.src"
Icon="../../../images/genicon.gif"
Caption="VB XmlNodeReader.exe"
SamplePath="howto\samples\Xml\XmlNodeReader\"
CanBeHosted="false"
runat="server"
/>
  </vbtemplate>
<cptemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XmlNodeReader/XmlNodeReader.src"
Icon="../../../images/genicon.gif"
Caption="C++ XmlNodeReader.exe"
SamplePath="howto\samples\Xml\XmlNodeReader\"
CanBeHosted="false"
runat="server"
/>
</cptemplate>

<VjsTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XmlNodeReader/XmlNodeReader.src"
Icon="../../../images/genicon.gif"
Caption="J# XmlNodeReader.exe"
SamplePath="howto\samples\Xml\XmlNodeReader\"
CanBeHosted="false"
runat="server"
/>
</VjsTemplate>
  
        </Acme:LangSwitch>
    <p>
        After creating and loading an XmlDocument with the books.xml file, the sample
    creates an XmlNodeReader that selects a single node from the XmlDocument and prints
    the node data to the screen. The sample then creates another XmlNodeReader that
    selects a different node to output to the screen.
    <p>
        <Acme:TabControl runat="server">
<tab name="C#">
XmlDocument xmlDocument = new XmlDocument();
xmlDocument.Load(document);
...
Console.WriteLine("Create an XmlNodeReader to show the third book ...");
using (XmlNodeReader xmlNodeReader = 
    new XmlNodeReader(xmlDocument.SelectSingleNode("bookstore/book[3]")))
{
...
XmlWriterSettings settings = new XmlWriterSettings();
settings.Indent = true;
    using (XmlWriter writer = XmlWriter.Create(Console.Out, settings))
    {
    writer.WriteNode(xmlNodeReader, true);
    }
}
</tab>
<tab name="VB">
Dim xmlDocument As New XmlDocument()
xmlDocument.Load(document)
...            
Console.WriteLine("Create an XmlNodeReader to show the third book ...")
Using xmlNodeReader As Xml.XmlNodeReader = New _
    Xml.XmlNodeReader(xmlDocument.SelectSingleNode("bookstore/book[3]"))
...            
Dim settings As New XmlWriterSettings()
settings.Indent = True
    Using writer As XmlWriter = XmlWriter.Create(Console.Out, settings)
        writer.WriteNode(xmlNodeReader, True)
    End Using
End Using
</tab>
            <tab name="C++">
XmlDocument^ xmlDocument = gcnew XmlDocument;
xmlDocument->Load( document );
...
Console::WriteLine( L"Create an XmlNodeReader to show the third book ..." );
xmlNodeReader = gcnew XmlNodeReader( xmlDocument->SelectSingleNode( L"bookstore/book[3]" ) );
...            
XmlWriter^ writer = XmlWriter::Create( Console::Out );
writer->WriteNode( xmlNodeReader, true );
writer->Flush();
</tab>
<tab name="J#">
XmlDocument xmlDocument = new XmlDocument();
xmlDocument.Load(document);
...
XmlWriter writer = XmlWriter.Create(Console.get_Out(), settings);
writer.WriteNode(xmlNodeReader, true);
writer.Flush();
</tab>>
        </Acme:TabControl>
    <p>
        <h4>
            Summary</h4>
        <ol>
            <li>
            XmlNodeReader is a fast, non-cached, forward-only reader to access XML data in an
            XmlNode.
            <li>
            Because an XmlNodeReader can be constructed with any XmlNode within the XmlDocument,
            XmlNodeReader provides a reader that reads only the subtree of a given node.
        </ol>
        <p>
</asp:Content>
