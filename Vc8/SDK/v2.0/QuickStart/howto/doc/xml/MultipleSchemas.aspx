<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Merge Multiple Schemas into a Single Logical Schema?</h4>
<p>
The XmlSchemaSet class represents a cache of XML Schemas. It allows you to compile multiple schemas for the same target namespace into a single logical schema. 
</p>
<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/MultipleSchemas/MultipleSchemas.src"
Icon="../../../images/genicon.gif"
Caption="C# MultipleSchemas.exe"
SamplePath="howto\samples\Xml\MultipleSchemas\"
CanBeHosted="false"
runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/Xml/MultipleSchemas/MultipleSchemas.src"
RunSample=""
SamplePath="howto\samples\Xml\MultipleSchemas\"
CanBeHosted="false"
Icon="../../../images/genicon.gif"
Caption="VB MultipleSchemas.exe"
runat="server" />
  </VbTemplate>
  <CpTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/Xml/MultipleSchemas/MultipleSchemas.src"
RunSample=""
Icon="../../../images/genicon.gif"
SamplePath="howto\samples\Xml\MultipleSchemas\"
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
This sample adds two schemas with the same target namespace to the XmlSchemaSet. When the Compile method is called, the two physical schemas are compiled to form one logical schema. The logical schema can then be used for schema validation.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
schemaSet.Add("http://www.example.org", @"..\..\book.xsd");
schemaSet.Add("http://www.example.org", @"..\..\author.xsd");
schemaSet.Compile(); 
</Tab>
<Tab Name="VB">
schemaSet.Add("http://www.example.org", "..\book.xsd")
schemaSet.Add("http://www.example.org", "..\author.xsd")
schemaSet.Compile()
</Tab>
<Tab Name="C++">
schemaSet->Add(S"http://www.example.org", S"book.xsd");
schemaSet->Add(S"http://www.example.org", S"author.xsd");
schemaSet->Compile(); 
</Tab>
</Acme:TabControl>
</asp:Content>

