<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>
<h4>How Do I...Validate an XML Document?</h4>

<p>
This sample illustrates how to validate an XML document by using a validating XML reader and the 
Validate method of the XmlDocument class. A validating XML reader is used to create the XmlDocument object
that contains the XML document to validate. The XmlReaderSettings object used to create the validating XmlReader object
contains the schema used to validate the XML document, and specifies the ValidationEventHandler used to handle 
schema validation warnings and errors.
<p>
<Acme:LangSwitch runat="server">
  <CsTemplate>

<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XmlDocumentValidation/XmlDocumentValidation.src"
Icon = "/quickstart/images/genicon.gif"
Caption="C# XmlDocumentValidation.exe"
SamplePath="howto\samples\Xml\XmlDocumentValidation\"
CanBeHosted="false"
runat="server" />

  </CsTemplate>
  <VbTemplate>

<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XmlDocumentValidation/XmlDocumentValidation.src"
Icon = "/quickstart/images/genicon.gif"
Caption="VB XmlDocumentValidation.exe"
SamplePath="howto\samples\Xml\XmlDocumentValidation\"
CanBeHosted="false"
runat="server" />

  </VbTemplate>

</Acme:LangSwitch>

<p>
The following code creates the XmlReaderSettings object.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
XmlReaderSettings settings = new XmlReaderSettings();
settings.Schemas.Add("urn:xmlns:25hoursaday-com:my-bookshelf", xsd);
settings.ValidationEventHandler += new ValidationEventHandler(ValidationCallback);
settings.ValidationType = ValidationType.Schema;
</Tab>
<Tab Name="VB">
Dim settings As New XmlReaderSettings()
settings.Schemas.Add("urn:xmlns:25hoursaday-com:my-bookshelf", xsd)
AddHandler settings.ValidationEventHandler, AddressOf ValidationCallback
settings.ValidationType = ValidationType.Schema
</Tab>
</Acme:TabControl>
<p>

<p>
The following code creates the validating XmlReader object and the XmlDocument object.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
XmlDocument doc = new XmlDocument();
doc.Load(XmlReader.Create(document, settings));
</Tab>
<Tab Name="VB">
Dim doc As New XmlDocument()
doc.Load(XmlReader.Create(document, settings))
</Tab>
</Acme:TabControl>
<p>

<p>
The following code validates the changes made to the XML document.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
doc.Validate(new ValidationEventHandler(ValidationCallback), element.ParentNode);
</Tab>
<Tab Name="VB">
doc.Validate(New ValidationEventHandler(AddressOf ValidationCallback), element.ParentNode)
</Tab>
</Acme:TabControl>
</asp:Content>