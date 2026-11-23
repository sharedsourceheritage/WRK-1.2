<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.HyperLink" runat="server">
  HyperLink
</Acme:TypeRef>
</h2>

The <b>HyperLink</b> control is used to navigate from the client to another page.

<br /><br />

The following sample illustrates using a simple <b>HyperLink</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/HyperLink/HyperLink1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/HyperLink/HyperLink1.src"
        Caption="C# HyperLink1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/HyperLink/HyperLink1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/HyperLink/HyperLink1.src"
        Caption="VB HyperLink1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<!--DataBound-->

<a name="databind"></a>
<h3>Data Binding HyperLink</h3>

The <b>HyperLink</b> control supports data binding to its <b>Text</b> and
<b>NavigateUrl</b> properties, as shown by the following example.

<br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/HyperLink/HyperLink2_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/HyperLink/HyperLink2.src"
        Caption="C# HyperLink2.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/HyperLink/HyperLink2_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/HyperLink/HyperLink2.src"
        Caption="VB HyperLink2.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
