<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.Image" runat="server">
  Image
</Acme:TypeRef>
</h2>

The <b>Image</b> control displays the image defined by its <b>ImageUrl</b> property.  The following sample illustrates using the
<b>Image</b> control.

<br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Image/Image1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Image/Image1.src"
        Caption="C# Image1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Image/Image1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Image/Image1.src"
        Caption="VB Image1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
