<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.CheckBox" runat="server">
  CheckBox
</Acme:TypeRef>
</h2>

The <b>CheckBox</b> server control accepts Boolean (<b>true</b> or <b>false</b>) input.  When selected, its <b>Checked</b> property is <b>true</b>.
Typically a check box is processed as one of several fields in a form; however, it can be used to trigger postback to
the server if its <b>AutoPostBack</b> property is <b>true</b>.  The following sample illustrates using the <b>CheckBox</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/checkBox/CheckBox1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/checkBox/CheckBox1.src"
        Caption="C# CheckBox1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/checkBox/CheckBox1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/checkBox/CheckBox1.src"
        Caption="VB CheckBox1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
