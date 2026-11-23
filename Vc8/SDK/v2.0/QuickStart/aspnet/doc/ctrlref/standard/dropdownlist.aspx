<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.DropDownList" runat="server">
  DropDownList
</Acme:TypeRef>
</h2>

The <b>DropDownList</b> control provides a single-select drop-down list.  The following sample illustrates using a simple <b>DropDownList</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/DropDownList/DropDownList1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/DropDownList/DropDownList1.src"
        Caption="C# DropDownList1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/DropDownList/DropDownList1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/DropDownList/DropDownList1.src"
        Caption="VB DropDownList1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

The following sample illustrates using data binding to a static ArrayList 
with a <b>DropDownList</b> control.

<br /><br />

<!--databinding-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/DropDownList/DropDownList2_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/DropDownList/DropDownList2.src"
        Caption="C# DropDownList2.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/DropDownList/DropDownList2_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/DropDownList/DropDownList2.src"
        Caption="VB DropDownList2.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

In addition to programmatically databinding, as shown in the example above, you can also
data bind a DropDownList declaratively to a data source control.  The following example 
shows a DropDownList bound to the Authors table in the Pubs database.

<br /><br />

<!--databinding-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/DropDownList/DropDownList3_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/DropDownList/DropDownList3.src"
        Caption="C# DropDownList3.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/DropDownList/DropDownList3_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/DropDownList/DropDownList3.src"
        Caption="VB DropDownList3.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

Note that the DropDownList includes DataTextField and DataValueField properties for
specifying the field value to render for the Text and Value properties of its list items, 
respectively.  The value of the currently selected item is exposed through the SelectedValue
property of DropDownList.  All controls that derive from ListControl (includes DropDownList)
follow this pattern.

</asp:Content>
