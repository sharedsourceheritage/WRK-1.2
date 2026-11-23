<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Read and Write a Schema?</h4>

<p>
This sample illustrates how to read an XML Schema Definition language (XSD) file into the Schema Object Model (SOM). Then, the sample writes the XSD schema that has been loaded into memory to a StringWriter for display to the screen. The schema could also be written to a file by using an XmlWriter.

<p>
This SOM provides a set of classes that directly reflect the World Wide Web Consortium (W3C) XSD specification. The classes, methods, and properties of XmlSchema provide the ability to create an in-memory version of the schema that can be complied and used in validation through XmlSchemaSet.

<p>
XmlSchema can load and save valid XML Schemas. It also has strongly-typed classes that can be used to create in-memory schemas. For validation purposes, XmlSchema can be used by the XmlSchemaSet and XmlReader classes.

<p>

<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XmlReadWriteSchema/XmlReadWriteSchema.src"
Icon="../../../images/genicon.gif"
Caption="C# XmlReadWriteSchema.exe"
SamplePath="howto\samples\Xml\XmlReadWriteSchema\"
CanBeHosted="false"
runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/Xml/XmlReadWriteSchema/XmlReadWriteSchema.src"
RunSample=""
Icon="../../../images/genicon.gif"
Caption="VB XmlReadWriteSchema.exe"
SamplePath="howto\samples\Xml\XmlReadWriteSchema\"
CanBeHosted="false"
runat="server" />
  </VbTemplate>
  <CpTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/Xml/XmlReadWriteSchema/XmlReadWriteSchema.src"
RunSample=""
Icon="../../../images/genicon.gif"
Caption="C++ XmlReadWriteSchema.exe"
SamplePath="howto\samples\Xml\XmlReadWriteSchema\"
CanBeHosted="false"
runat="server" />
  </CpTemplate>
 <VjsTemplate>
<Acme:SourceRef 
ViewSource="~/howto/samples/Xml/XmlReadWriteSchema/XmlReadWriteSchema.src"
RunSample=""
Icon="../../../images/genicon.gif"
Caption="J# XmlReadWriteSchema.exe"
SamplePath="howto\samples\Xml\XmlReadWriteSchema\"
CanBeHosted="false"
runat="server" 
 />
  </VjsTemplate>
</Acme:LangSwitch>

<p>
Typically, you use the XmlSchema to load and/or create a valid schema. This sample simply loads a simple schema from a file.

<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
XmlSchema schema = XmlSchema.Read(XmlReader.Create(document), null);
</Tab>
<Tab Name="VB">
Dim schema as XmlSchema  = XmlSchema.Read(XmlReader.Create(document),Nothing)
</Tab>
<Tab Name="C++">
XmlSchema^ schema = XmlSchema::Read(XmlReader::Create(document), nullptr);
</Tab>
<Tab name="J#">
XmlSchema schema = XmlSchema.Read(XmlReader.Create(document), null);
</Tab>
</Acme:TabControl>
<p>

When loaded, the sample writes the schema to a StringWriter and displays the StringWriter on the screen.

<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
schema.Write(writer);
</Tab>
<Tab Name="VB">
schema.Write(writer)
</Tab>
<Tab Name="C++">
schema->Write(writer);
</Tab>
<tab name="J#">
schema.Write(writer);
</tab>
</Acme:TabControl>
<p>

<H4>Summary</H4>
<OL>
<LI>The Schema Object Model (SOM) provides a navigatable set of classes which directly reflect the W3C XSD specification.
<LI>A SOM is built for each of the imported and included schemas and these are held in the includes collection
<LI>The items collection is a list of all the schema element types at the schema level from the loaded schema. This is used for persistence.
<LI>Hashtables from Elements, Attributes, and so on, are built which reference all the schema element types at the schema level for all referenced schemas, as well as this one. This provides an easy lookup mechanism on the element name.
</OL>
<p>

</asp:Content>