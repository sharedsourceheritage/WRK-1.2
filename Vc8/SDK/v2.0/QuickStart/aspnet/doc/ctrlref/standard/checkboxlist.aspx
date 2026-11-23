<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.CheckBoxList" runat="server">
  CheckBoxList
</Acme:TypeRef>
</h2>

The <b>CheckBoxList</b> control provides a multiple-selection checked list.  Like other list controls, <b>CheckBoxList</b>
has an <b>Items</b> collection with members that correspond to each item in the list.  To determine which items are
selected, test the <b>Selected</b> property of each item.

<br /><br />

You can control the rendering of the list with the <b>RepeatLayout</b> and <b>RepeatDirection</b> properties.  If
<b>RepeatLayout</b> is <b>Table</b>, the list is rendered within a table.  If it is set to <b>Flow</b>, the list is rendered
without any table structure.  By default, <b>RepeatDirection</b> is <b>Vertical</b>.  Setting this property to <b>Horizontal</b> 
causes the list to be rendered horizontally.

<br /><br />

The following sample illustrates using the <b>CheckBoxList</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/checkBoxlist/CheckBoxList1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/checkBoxlist/CheckBoxList1.src"
        Caption="C# CheckBoxList1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/checkBoxlist/CheckBoxList1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/checkBoxlist/CheckBoxList1.src"
        Caption="VB CheckBoxList1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
