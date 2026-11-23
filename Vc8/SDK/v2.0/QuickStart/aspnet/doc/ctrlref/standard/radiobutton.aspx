<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.RadioButton" runat="server">
  RadioButton
</Acme:TypeRef>
</h2>

The <b>RadioButton</b> control permits you to intersperse the radio buttons in a group with other content in
the page.  The buttons in the sample are grouped logically because they all share the same <b>GroupName</b>.

<br /><br />

The following sample illustrates using the <b>RadioButton</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/RadioButton/RadioButton1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/RadioButton/RadioButton1.src"
        Caption="C# RadioButton1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/RadioButton/RadioButton1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/RadioButton/RadioButton1.src"
        Caption="VB RadioButton1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
