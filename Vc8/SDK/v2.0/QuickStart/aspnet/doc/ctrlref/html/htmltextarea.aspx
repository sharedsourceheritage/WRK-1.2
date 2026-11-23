<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.HtmlControls.HtmlTextArea" runat="server">
  HtmltextArea
</Acme:TypeRef>
</h2>

The <b>HtmlTextArea</b> control is a multiline input control that lets the user enter text.  The display
width of <b>HtmlTextArea</b> is determined by its <b>Cols</b> property, and the display height is determined
by the <b>Rows</b> property.

<br /><br />

The following sample illustrates using the <b>HtmlTextArea</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlTextArea/HtmlTextArea1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlTextArea/HtmlTextArea1.src"
        Caption="C# HtmlTextArea1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlTextArea/HtmlTextArea1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlTextArea/HtmlTextArea1.src"
        Caption="VB HtmlTextArea1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
