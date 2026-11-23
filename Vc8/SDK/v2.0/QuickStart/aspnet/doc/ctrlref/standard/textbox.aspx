<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.TextBox" runat="server">
  TextBox
</Acme:TypeRef>
</h2>

The <b>TextBox</b> control enables the user to enter text. By default, the <b>TextMode</b>
of <b>TextBox</b> is SingleLine, but you can modify the behavior of <b>TextBox</b> by setting the <b>TextMode</b> to Password or MultiLine.

<br /><br />

The display width of <b>TextBox</b> is determined by its <b>Columns</b> property.  If <b>TextMode</b> is MutliLine, the
display height of <b>TextBox</b> is determined by the <b>Rows</b> property.

<br /><br />

The following sample illustrates using the <b>TextBox</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/TextBox/TextBox1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/TextBox/TextBox1.src"
        Caption="C# TextBox1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/TextBox/TextBox1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/TextBox/TextBox1.src"
        Caption="VB TextBox1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
