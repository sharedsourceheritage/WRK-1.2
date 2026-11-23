<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4></h4>


<p>
<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
RunSample="/howto/samples/Xml/XmlBulkLoad/CS/XmlBulkLoad/bin/debug"
ViewSource="~/howto/samples/Xml/XmlBulkLoad/XmlBulkLoad.src"
Icon="../../../images/genicon.gif"
SamplePath="howto\samples\Xml\XmlBulkLoad\"
CanBeHosted="false"
Caption="C# XmlBulkLoad.exe"
runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/Xml/XmlBulkLoad/XmlBulkLoad.src"
RunSample="/howto/samples/Xml/XmlBulkLoad/VB/XmlBulkLoad/bin"
Icon="../../../images/genicon.gif"
SamplePath="howto\samples\Xml\XmlBulkLoad\"
CanBeHosted="false"
Caption="VB XmlBulkLoad.exe"
runat="server" />
  </VbTemplate>
 <VjsTemplate>
       <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
        CanBeHosted="false"
        runat="server" />
  </VjsTemplate>
 <CpTemplate>
       <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
        CanBeHosted="false"
        runat="server" />
  </CpTemplate>
</Acme:LangSwitch>

<p>
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">

</Tab>
<Tab Name="VB">

</Tab>
<Tab Name="C++">

</Tab>
</Acme:TabControl>
</asp:Content>


