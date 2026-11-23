<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Read and Write XML?</h4>

<p>
This sample illustrates how data can be streamed between components. XML data is parsed by using the XmlReader, and then written out by using the XmlWriter. 
<p>
<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XMLReadWrite/XMLReadWrite.src"
Icon="../../../images/genicon.gif"
SamplePath="howto\samples\Xml\XMLReadWrite\"
CanBeHosted="false"
Caption="C# XMLReadWrite.exe"
runat="server" 
/>
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XMLReadWrite/XMLReadWrite.src"
Icon="../../../images/genicon.gif"
SamplePath="howto\samples\Xml\XMLReadWrite\"
CanBeHosted="false"
Caption="VB XMLReadWrite.exe"
runat="server" 
/>
  </VbTemplate>
  <CpTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XMLReadWrite/XMLReadWrite.src"
Icon="../../../images/genicon.gif"
SamplePath="howto\samples\Xml\XMLReadWrite\"
CanBeHosted="false"
Caption="C++ XMLReadWrite.exe"
runat="server" 
/>
</CpTemplate>
</Acme:LangSwitch>

<p>
The following code reads the  book price, calculates a discounted price, and then writes a price element that includes the original and discounted prices. 
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
double originalPrice = 0.0;
originalPrice = reader.ReadElementContentAsDouble();
...
double discountedPrice = originalPrice - (originalPrice * 0.25);
writer.WriteStartElement("price");
writer.WriteAttributeString("alternative", "25% discount");
writer.WriteAttributeString("originalPrice", originalPrice.ToString());
writer.WriteValue(discountedPrice);
writer.WriteEndElement();
</Tab>
<Tab Name="VB">
Dim originalPrice As Double = 0.0
originalPrice = reader.ReadElementContentAsDouble()
...
Dim discountedPrice As Double = originalPrice - originalPrice * 0.25
writer.WriteStartElement("price")
writer.WriteAttributeString("alternative", "25% discount")
writer.WriteAttributeString("originalPrice", originalPrice.ToString())
writer.WriteValue(discountedPrice)
writer.WriteEndElement()
</Tab>
<Tab Name="C++">
double originalPrice = 0.0;
originalPrice = reader->ReadElementContentAsDouble();
...
double discountedPrice = originalPrice - (originalPrice * 0.25);
writer->WriteStartElement("price");
writer->WriteAttributeString("alternative", "25% discount");
writer->WriteAttributeString("originalPrice", originalPrice.ToString());
writer->WriteValue(discountedPrice);
writer->WriteEndElement();
</Tab>
</Acme:TabControl>
<p>
</asp:Content>

















