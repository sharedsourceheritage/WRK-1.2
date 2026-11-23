<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.RadioButtonList" runat="server">
  RadioButtonList
</Acme:TypeRef>
</h2>

The <b>RadioButtonList</b> control provides a single-selection checked list.  Like other list controls, <b>RadioButtonList</b>
has an <b>Items</b> collection with members that correspond to each item in the list.  To determine which items are
selected, test the <b>Selected</b> property of each item.

<br /><br />

You can control the rendering of the list with the <b>RepeatLayout</b> and <b>RepeatDirection</b> properties.  If the value of 
<b>RepeatLayout</b> is <b>Table</b>, the list will be rendered in a table.  If it is set to <b>Flow</b>, the list will be rendered
without any table structure.  By default, the value of <b>RepeatDirection</b> is <b>Vertical</b>.  Setting this property to <b>Horizontal</b> 
causes the list to be rendered horizontally.

<br /><br />


The following sample illustrates using the <b>RadioButtonList</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/RadioButtonList/RadioButtonList1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/RadioButtonList/RadioButtonList1.src"
        Caption="C# RadioButtonList1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/RadioButtonList/RadioButtonList1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/RadioButtonList/RadioButtonList1.src"
        Caption="VB RadioButtonList1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
