<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.HtmlControls.HtmlSelect" runat="server">
  HtmlSelect
</Acme:TypeRef>
</h2>

The <b>HtmlSelect</b> control provides a drop-down list.  The following sample illustrates using the <b>HtmlSelect</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlSelect/HtmlSelect1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlSelect/HtmlSelect1.src"
        Caption="C# HtmlSelect1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlSelect/HtmlSelect1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlSelect/HtmlSelect1.src"
        Caption="VB HtmlSelect1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

The following sample illustrates using data binding with an <b>HtmlSelect</b> control.

<br /><br />

<!--databinding-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlSelect/HtmlSelect2_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlSelect/HtmlSelect2.src"
        Caption="C# HtmlSelect2.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlSelect/HtmlSelect2_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlSelect/HtmlSelect2.src"
        Caption="VB HtmlSelect2.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
