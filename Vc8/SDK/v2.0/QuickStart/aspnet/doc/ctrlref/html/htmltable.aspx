<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.HtmlControls.HtmlTable" runat="server">
  HtmlTable
</Acme:TypeRef>
,
<Acme:TypeRef TypeName="System.Web.UI.HtmlControls.HtmlTableRow" runat="server">
  HtmlTableRow
</Acme:TypeRef>
, and
<Acme:TypeRef TypeName="System.Web.UI.HtmlControls.HtmlTableCell" runat="server">
  HtmlTableCell
</Acme:TypeRef>
</h2>

The <b>HtmlTable</b> control lets you build up a table programmatically by adding <b>HtmlTableRow</b> controls
to the table's Rows collection and <b>HtmlTableCell</b> controls to the row's Cells collection.  You can add content to a
table cell programmatically by adding controls to the cell's Controls collection.

<br /><br />

The following sample illustrates using the <b>HtmlTable</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlTable/HtmlTable1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlTable/HtmlTable1.src"
        Caption="C# HtmlTable1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlTable/HtmlTable1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlTable/HtmlTable1.src"
        Caption="VB HtmlTable1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
