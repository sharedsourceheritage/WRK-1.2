<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.HtmlControls.HtmlInputCheckBox" runat="server">
  HtmlInputCheckBox
</Acme:TypeRef>
</h2>

The <b>HtmlInputCheckBox</b> control accepts Boolean (<b>true</b>/<b>false</b>) input.  When selected, its <b>Checked</b> property
is <b>true</b>. The following sample illustrates using the <b>HtmlInputCheckBox</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlInputCheckBox/HtmlInputCheckBox1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlInputCheckBox/HtmlInputCheckBox1.src"
        Caption="C# HtmlInputCheckBox1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlInputCheckBox/HtmlInputCheckBox1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlInputCheckBox/HtmlInputCheckBox1.src"
        Caption="VB HtmlInputCheckBox1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
