<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.Table" runat="server">
  Table
</Acme:TypeRef>
,
<Acme:TypeRef TypeName="System.Web.UI.WebControls.TableRow" runat="server">
  TableRow 
</Acme:TypeRef>
, and
<Acme:TypeRef TypeName="System.Web.UI.WebControls.TableCell" runat="server">
  TableCell 
</Acme:TypeRef>
</h2>

The <b>Table</b> control builds up a table programmatically by adding <b>TableRows</b>
to the <b>Rows</b> collection of the table, and <b>TableCells</b> to the <b>Cells</b> collection of the row.  You can add content to a
table cell programmatically by adding controls to the <b>Controls</b> collection of the cell.

<br /><br />

The following sample illustrates using the <b>Table</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Table/Table1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Table/Table1.src"
        Caption="C# Table1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Table/Table1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Table/Table1.src"
        Caption="VB Table1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
