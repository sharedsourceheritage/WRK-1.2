<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.Panel" runat="server">
  Panel
</Acme:TypeRef>
</h2>

The <b>Panel</b> control is a container for other controls.  It is especially useful when you want to
generate controls programmatically or hide or show a group of controls, as shown in the following example.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Panel/Panel1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Panel/Panel1.src"
        Caption="C# Panel1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Panel/Panel1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Panel/Panel1.src"
        Caption="VB Panel1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
