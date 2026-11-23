<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.LinkButton" runat="server">
  LinkButton
</Acme:TypeRef>
</h2>

Like the <b>Button</b> control, <b>LinkButton</b> is used to post a Web Forms page back to the server.  For additional button
examples, see <asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/standard/button.aspx" runat="server">
Button</asp:HyperLink> and <asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/standard/imagebutton.aspx" runat="server">
ImageButton</asp:HyperLink>.  For a control that navigates to another page, see <asp:HyperLink 
NavigateUrl="~/aspnet/doc/ctrlref/standard/hyperlink.aspx" runat="server">
HyperLink</asp:HyperLink>.

<br /><br />

The following sample illustrates using the <b>LinkButton</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/LinkButton/LinkButton1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/LinkButton/LinkButton1.src"
        Caption="C# LinkButton1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/LinkButton/LinkButton1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/LinkButton/LinkButton1.src"
        Caption="VB LinkButton1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
