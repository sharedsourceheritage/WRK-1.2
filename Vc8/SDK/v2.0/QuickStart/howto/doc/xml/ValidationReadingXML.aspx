<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Apply Validation When Reading XML?</h4>

<p>
This sample illustrates how to apply validation when reading and parsing XML data using the XmlReader class. Validation is the process of enforcing rules on the XML content either via a Document Type Definition (DTD) or a XML Schema Definition language (XSD) schema.
<p>
<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/ValidationReadingXml/ValidationReadingXML.src"
Icon="../../../images/genicon.gif"
Caption="C# ValidationReadingXML.exe"
SamplePath="howto\samples\Xml\ValidationReadingXml\"
CanBeHosted="false"
runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/ValidationReadingXml/ValidationReadingXML.src"
Icon="../../../images/genicon.gif"
SamplePath="howto\samples\Xml\ValidationReadingXml\"
CanBeHosted="false"
Caption="VB ValidationReadingXML.exe"
runat="server" />
  </VbTemplate>
  <CpTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/ValidationReadingXml/ValidationReadingXML.src"
Icon="../../../images/genicon.gif"
SamplePath="howto\samples\Xml\ValidationReadingXml\"
CanBeHosted="false"
Caption="C++ ValidationReadingXML.exe"
runat="server" />
  </CpTemplate>
 <VjsTemplate>
<Acme:SourceRef
 RunSample=""
ViewSource="~/howto/samples/Xml/ValidationReadingXml/ValidationReadingXML.src"
Icon="../../../images/genicon.gif"
SamplePath="howto\samples\Xml\ValidationReadingXml\"
CanBeHosted="false"
Caption="J# ValidationReadingXML.exe"
runat="server" 
/>
  </VjsTemplate>
</Acme:LangSwitch>

<p>
The XmlReader class can provide validation of a DTD or an XML Schema when parsing the document. XmlReader objects are created with the Create method. Settings on the XmlReaderSettings class determine what features are supported on the XmlReader object.
<p>
This sample validates several XML files using XML Schema validation. It shows validation successes and failures.
<p>
The following code sets a ValidationEventHandler to handle validation error results. If a handler is not provided, an XmlSchemaException is thrown when a validation error occurs.
<p>

<Acme:TabControl runat="server">
<Tab Name="C#">
XmlReaderSettings settings = new XmlReaderSettings(); 
settings.ValidationEventHandler += 
    new ValidationEventHandler(this.ValidationEventHandler);
</Tab>
<Tab Name="VB">
Dim settings As New XmlReaderSettings()
AddHandler settings.ValidationEventHandler, AddressOf Me.ValidationEventHandler
</Tab>
<Tab Name="C++">
XmlReaderSettings^ settings = new XmlReaderSettings(); 
settings->ValidationEventHandler += 
  gcnew ValidationEventHandler 
  (this, &ValidationReadingXMLSample::ValidationEventHandle);
</Tab>
<Tab Name="J#">
XmlReaderSettings settings = new XmlReaderSettings();
settings.add_ValidationEventHandler
  (new ValidationEventHandler(this.ValidationEventHandler));
</Tab>
</Acme:TabControl>
<p>
The validation settings are specified with the ValidationType.DTD or ValidationType.Schema properties on the XmlReaderSettings class. The default setting for both properties is ValidationType.None so the XmlReader does not validate. The following code creates a DTD validating XmlReader object for the Validate subroutine.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
settings.ValidationType = ValidationType.Schema;
settings.Schemas.Add("schema.xsd", XmlReader.Create(document5));

using (XmlReader xmlValidatingReader = XmlReader.Create(document3, settings))
{
    while (xmlValidatingReader.Read()) { }
}
</Tab>
<Tab Name="VB">
settings.ValidationType = ValidationType.Schema
settings.Schemas.Add("schema.xsd", XmlReader.Create(document5))

Using XmlValidatingReader As XmlReader = XmlReader.Create(document3, settings)
    While XmlValidatingReader.Read()
    End While
End Using
</Tab>
<Tab Name="C++">
settings->ValidationType = ValidationType::Schema;
settings->Schemas->Add("schema.xsd", XmlReader::Create(document5));

xmlValidatingReader = XmlReader::Create(document3, settings);
while (xmlValidatingReader->Read()) { }
</Tab>
<Tab Name="J#">
settings.set_ValidationType(ValidationType.Schema);
settings.get_Schemas().Add("schema.xsd", XmlReader.Create(document5));
xmlValidatingReader = XmlReader.Create(document3, settings);
while (xmlValidatingReader.Read()) {}
</Tab>
</Acme:TabControl>
<p>
As the XmlReader parses the XML document, it calls the validation event handler when it encounters a validation error. The parser only stops if the parser finds data that is not well-formed. By not stopping for validation errors, you are able to find all the validation errors in one pass without having to repeatedly parse the XML document. 
<p>
<p>
<H4>Summary</H4>
<OL>
<LI>Validation can either be against a DTD or an XML Schema. The validation setting is specified with the DtdValidate or the XsdValidate properties on the XmlReaderSettings class.
<LI>Validation is performed during the read and parsing operations.
<LI>A ValidationEventHandler must be set to receive notification of validation errors.
<LI>Validation errors do not stop parsing. Parsing only stops if there is an error when the file is not well-formed XML. This enables all errors to be discovered in a single pass.
</LI></OL>

</asp:Content>