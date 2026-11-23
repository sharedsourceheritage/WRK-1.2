<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Serialize an Object Graph</h2>

This sample shows how to serialize a graph of objects using the serialization infrastructure.

<h2>Example</h2>

<br /><br />


<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/serialization/serialize/serialize.src"
        Icon="../../images/console.gif"
        Caption="C# Serialize.exe"
	SamplePath="howto\samples\serialization\serialize\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/serialization/serialize/serialize.src"
        Icon="../../images/console.gif"
        Caption="VB Serialize.exe"
	SamplePath="howto\samples\serialization\serialize\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/serialization/serialize/serialize.src"
        Icon="../../images/console.gif"
        Caption="C++ Serialize.exe"
	SamplePath="howto\samples\serialization\serialize\"
        CanBeHosted="false"
        runat="server" />
  </CpTemplate>
  <VjsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/serialization/serialize/serialize.src"
        Icon="../../images/console.gif"
        Caption="J# Serialize.exe"
	SamplePath="howto\samples\serialization\serialize\"
        CanBeHosted="false"
        runat="server" />	
  </VjsTemplate>
</Acme:LangSwitch>
</asp:Content>

