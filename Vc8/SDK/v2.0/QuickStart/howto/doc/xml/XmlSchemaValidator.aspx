<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Validate XML using the XmlSchemaValidator Class?</h4>

<p>
This sample illustrates how to validate XML data by using the XmlSchemaValidator class. The 
XmlSchemaValidator class is useful in advanced scenarios. It lets you validate an XML infoset 
in-place without having to serialize it as an XML document, and then reparse the document by using a validating
XML reader. The sample deserializes XML data by using the XmlSerializer class, and then passes the XML data to 
the methods of the XmlSchemaValidator class.
<p>
<Acme:LangSwitch runat="server">
  <CsTemplate>

<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XmlSchemaValidator/XmlSchemaValidator.src"
Icon = "/quickstart/images/genicon.gif"
Caption="C# XmlSchemaValidator.exe"
SamplePath="howto\samples\Xml\XmlSchemaValidator\"
CanBeHosted="false"
runat="server" />

  </CsTemplate>
  <VbTemplate>


<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XmlSchemaValidator/XmlSchemaValidator.src"
Icon = "/quickstart/images/genicon.gif"
Caption="VB XmlSchemaValidator.exe"
SamplePath="howto\samples\Xml\XmlSchemaValidator\"
CanBeHosted="false"
runat="server" />

  </VbTemplate>

</Acme:LangSwitch>
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
XmlSerializer serializer = new XmlSerializer(typeof(books));
Books myBooks = (books)serializer.Deserialize(reader);
...
XmlSchemaValidator xsv = CreateValidator();
xsv.Initialize(); 
			
xsv.ValidateElement("books", "http://www.example.com/my-bookshelf", schemaInfo);
...
</Tab>
<Tab Name="VB">
Dim serializer As New XmlSerializer(GetType(books))     
Dim myBooks As Books = CType(serializer.Deserialize(reader), Books)
...
Dim xsv As XmlSchemaValidator = CreateValidator()
xsv.Initialize()
        
xsv.ValidateElement("books", "http://www.example.com/my-bookshelf", schemaInfo)
...
</Tab>

</Acme:TabControl>
</asp:Content>