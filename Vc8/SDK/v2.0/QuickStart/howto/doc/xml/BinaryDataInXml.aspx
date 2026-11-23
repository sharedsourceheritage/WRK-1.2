<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>
<h4>How Do I...Write Binary Data?</h4>

<p>
This sample illustrates how to write binary data in an XML stream. The WriteBase64 method
encodes the specified binary bytes as Base64 and writes out the resulting text.

<p>After the binary data is written out, it is read into an XmlReader to ensure that the data is valid.
 
<p>
<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/BinaryDataInXml/BinaryDataInXml.src"
Icon = "../../../images/genicon.gif"
Caption="C# BinaryDataInXml.exe"
SamplePath="howto\samples\Xml\BinaryDataInXml\"
CanBeHosted="false"
runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/BinaryDataInXml/BinaryDataInXml.src"
Icon = "../../../images/genicon.gif"
Caption="VB BinaryDataInXml.exe"
SamplePath="howto\samples\Xml\BinaryDataInXml\"
CanBeHosted="false"
runat="server" />
  </VbTemplate>
  
</Acme:LangSwitch>

<p>
The following code writes the Base64 encoded data inside the <Test> element.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
using (StringWriter sw = new StringWriter())
{
    using (XmlWriter writer = XmlWriter.Create(sw))
    {
        writer.WriteStartElement("Test");
        writer.WriteAttributeString("Length", buffer.Length.ToString());
        writer.WriteCData(Convert.ToBase64String(buffer, 0, buffer.Length));
        writer.WriteEndElement();
    }
...
}
</Tab>
<Tab Name="VB">
Using sw As StringWriter = New StringWriter()
    Using writer As XmlWriter = XmlWriter.Create(sw)
        writer.WriteStartElement("Test")
        writer.WriteAttributeString("Length", buffer.Length.ToString())
        writer.WriteCData(Convert.ToBase64String(buffer, 0, buffer.Length))
        writer.WriteEndElement()
    End Using
...
End Using
</Tab>
</Acme:TabControl>
</asp:Content>















