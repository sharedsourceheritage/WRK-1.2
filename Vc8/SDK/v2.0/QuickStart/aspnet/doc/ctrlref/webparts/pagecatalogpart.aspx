<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.WebParts.PageCatalogPart" runat="server">
  PageCatalogPart
</Acme:TypeRef>
</h2>

<p>The PageCatalogPart class serves one very specific purpose on a Web Parts page: it acts as a page catalog to contain any controls previously added to the page that a user has closed, and that the user can add back to the page. Add a PageCatalogPart control to your page if you want to provide users with the flexibility of closing and reopening controls. If your page does not allow users to close controls at all, there is no need to add a PageCatalogPart control to your page. </p>
<p>The most common and convenient way to add a PageCatalogPart control to a page is by declaring it in page persistence format inside a <a href=CatalogZone.aspx>CatalogZone</a></p>
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/reference_cs/CatalogZone_PageCatalogPart.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/CatalogZone_PageCatalogPart.src"
        Caption="C# PageCatalogPart Sample"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/reference_vb/CatalogZone_PageCatalogPart.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/CatalogZone_PageCatalogPart.src"
        Caption="VB PageCatalogPart Sample"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
