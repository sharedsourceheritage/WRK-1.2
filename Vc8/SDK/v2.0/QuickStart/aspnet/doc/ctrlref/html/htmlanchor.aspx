<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.HtmlControls.HtmlAnchor" runat="server">
  HtmlAnchor
</Acme:TypeRef>
</h2>

The following sample illustrates using the <b>HtmlAnchor</b> control (<b>&lt;a&gt;</b>).  <b>HtmlAnchor</b> is used
to navigate from the client page to another page.

<br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlAnchor/HtmlAnchor1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlAnchor/HtmlAnchor1.src"
        Caption="C# HtmlAnchor1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlAnchor/HtmlAnchor1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlAnchor/HtmlAnchor1.src"
        Caption="VB HtmlAnchor1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<!--DataBound-->

<a name="databind"></a>
<h3>DataBinding HtmlAnchor</h3>

The <b>HtmlAnchor</b> control supports data binding to its <b>HRef</b> and
<b>InnerHtml</b> properties, as shown by the following example.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlAnchor/HtmlAnchor2_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlAnchor/HtmlAnchor2.src"
        Caption="C# HtmlAnchor2.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlAnchor/HtmlAnchor2_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlAnchor/HtmlAnchor2.src"
        Caption="VB HtmlAnchor2.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
