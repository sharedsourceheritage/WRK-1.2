<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.WebParts.ImportCatalogPart" runat="server">
  ImportCatalogPart
</Acme:TypeRef>
</h2>

<p>The ImportCatalogPart control enables users to import a description file that describes settings on a WebPart control or server control that a user wants to add to a Web page. After the user has imported the description file, the WebPart control referenced in the file appears within the ImportCatalogPart control when the page is in catalog mode, and a user can then add the control to the page.</p>
<p>The most common and convenient way to add a ImportCatalogPart control to a page is by declaring it in page persistence format inside a <a href=CatalogZone.aspx>CatalogZone</a></p>
<p>To generate a description file select the export verb from the Web Part Verb Menu</p>
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/reference_cs/CatalogZone_ImportCatalogPart.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/CatalogZone_ImportCatalogPart.src"
        Caption="C# ImportCatalogPart Sample"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/reference_vb/CatalogZone_ImportCatalogPart.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/CatalogZone_ImportCatalogPart.src"
        Caption="VB ImportCatalogPart Sample"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
</asp:Content>
