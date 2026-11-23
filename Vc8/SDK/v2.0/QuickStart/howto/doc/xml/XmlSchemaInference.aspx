<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Infer an XML Schema?</h4>

<p>
This sample illustrates how to infer an XML schema from a given XML document by using the XmlSchemaInference class.
An XmlSchemaInference object is used to infer an XML schema from a particular XML document, and then adds the inferred schema
to an XmlSchemaSet object. The inferred schema is further refined by using schemas inferred from additional XML documents. 
<p>
<Acme:LangSwitch runat="server">
  <CsTemplate>

<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XmlSchemaInference/XmlSchemaInference.src"
Icon = "/quickstart/images/genicon.gif"
Caption="C# XmlSchemaInference.exe"
SamplePath="howto\samples\Xml\XmlSchemaInference\"
CanBeHosted="false"
runat="server" />

  </CsTemplate>
  <VbTemplate>

<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XmlSchemaInference/XmlSchemaInference.src"
Icon = "/quickstart/images/genicon.gif"
Caption="VB XmlSchemaInference.exe"
SamplePath="howto\samples\Xml\XmlSchemaInference\"
CanBeHosted="false"
runat="server" />

  </VbTemplate>
  <CpTemplate>

<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XmlSchemaInference/XmlSchemaInference.src"
Icon = "/quickstart/images/genicon.gif"
Caption="C++ XmlSchemaInference.exe"
SamplePath="howto\samples\Xml\XmlSchemaInference\"
CanBeHosted="false"
runat="server" />

  </CpTemplate>
</Acme:LangSwitch>

<p>
The following code creates the XmlSchemaInference and XmlSchemaSet objects.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
XmlSchemaInference infer = new XmlSchemaInference();
XmlSchemaSet sc = new XmlSchemaSet();
</Tab>
<Tab Name="VB">
Dim infer As New XmlSchemaInference()
Dim sc As New XmlSchemaSet()
</Tab>
<tab name="C++">
XmlSchemaInference^ infer = gcnew XmlSchemaInference;
XmlSchemaSet^ sc = gcnew XmlSchemaSet();
</tab>
</Acme:TabControl>
<p>

<p>
The following code infers an XML schema from an XML document.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
sc = infer.InferSchema(new XmlTextReader("sample.xml"));
</Tab>
<Tab Name="VB">
sc = infer.InferSchema(new XmlTextReader("sample.xml"))
</Tab>
<tab name="C++">
sc = infer->InferSchema(gcnew XmlTextReader(L"sample.xml"));
</tab>
</Acme:TabControl>

</asp:Content>