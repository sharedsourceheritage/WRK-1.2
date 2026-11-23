<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.ListBox" runat="server">
  ListBox
</Acme:TypeRef>
</h2>

The <b>ListBox</b> control provides a single-selection or multiple-selection list.  To enable multiple selection, set the <b>
SelectionMode</b> property to <b>Multiple</b>.

<br />

The following sample illustrates using a simple <b>ListBox</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/ListBox/ListBox1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/ListBox/ListBox1.src"
        Caption="C# ListBox1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/ListBox/ListBox1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/ListBox/ListBox1.src"
        Caption="VB ListBox1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

The following sample illustrates using data binding with a <b>ListBox</b> control.

<br /><br />

<!--DataBinding-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/ListBox/ListBox2_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/ListBox/ListBox2.src"
        Caption="C# ListBox2.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/ListBox/ListBox2_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/ListBox/ListBox2.src"
        Caption="VB ListBox2.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
