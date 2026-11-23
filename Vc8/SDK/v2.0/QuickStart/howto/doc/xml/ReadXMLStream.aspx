<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Read XML data from a stream?</h4>

<p>
This sample illustrates how to read XML from a stream using the XmlReader class. The stream could have come from a variety of sources, such as a byte stream from a server, a file, or a TextReader.
<p>
Note: This sample follows on from the <a target=content href="XmlReadWrite.aspx">How do I...Read XML from a file?</a> topic.

<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/ReadXmlStream/ReadXmlStream.src"
Icon="../../../images/genicon.gif"
Caption="C# ReadXmlStream.exe"
SamplePath="howto\samples\Xml\ReadXmlStream\"
CanBeHosted="false"
runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/Xml/ReadXmlStream/ReadXmlStream.src"
RunSample=""
Icon="../../../images/genicon.gif"
SamplePath="howto\samples\Xml\ReadXmlStream\"
CanBeHosted="false"
Caption="VB ReadXmlStream.exe"
runat="server" />
  </VbTemplate>
  <CpTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/Xml/ReadXmlStream/ReadXmlStream.src"
RunSample=""
Icon="../../../images/genicon.gif"
SamplePath="howto\samples\Xml\ReadXmlStream\"
CanBeHosted="false"
Caption="C++ ReadXmlStream.exe"
runat="server" />
  </CpTemplate>
<VjsTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/ReadXmlStream/ReadXmlStream.src"
Icon = "../../../images/genicon.gif"
Caption="J# ReadXmlStream.exe"
runat="server" 
/>
  </VjsTemplate>
</Acme:LangSwitch>

<p>
The static Create method on the XmlReader has different overloads to specify the location of the XML data. This sample creates the XmlReader and loads the data from a stream. A stream is an abstract representation of an input or output device that is the source of or destination for data (in this case, XML data). You can write to a stream and read from a stream, which is best visualized as a flow of bytes. A stream provides independence from the device and requires no program changes if, for example, the source of a stream changes.
<p>
This sample creates a StringReader class that builds up an XML string. Because this is purely a byte stream held in memory, you can get the XmlReader to parse this stream as XML. The memory stream has no particular specified encoding. 
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
//Create XmlReader and load reader from stream
reader = XmlReader.Create(stream);
</Tab>
<Tab Name="VB">
'Create XmlReader and load reader from stream
reader = XmlReader.Create(stream)
</Tab>
<Tab Name="C++">
//Create XmlReader and load reader from the stream
reader = XmlReader::Create(stream);
</Tab>
<Tab Name="J#">
//Create XmlReader and load reader from stream
reader = XmlReader.Create(stream);
</Tab>
</Acme:TabControl>
</asp:Content>

