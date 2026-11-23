<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.HtmlControls.HtmlForm" runat="server">
  HtmlForm
</Acme:TypeRef>
</h2>

An <b>HtmlForm</b> control is required to process postback requests.  A Web Forms page might only
have one server side <b>&lt;form&gt;</b> tag; however, client forms (no <b>runat=server</b> attribute)
can also postback to server-side logic as long as a server-side form is present on the
page.

<br /><br />

The following sample illustrates using the <b>HtmlForm</b> control.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlForm/HtmlForm1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlForm/HtmlForm1.src"
        Caption="C# HtmlForm1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlForm/HtmlForm1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlForm/HtmlForm1.src"
        Caption="VB HtmlForm1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
