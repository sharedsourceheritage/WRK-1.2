<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.AccessDataSource" runat="server">
  AccessDataSource
</Acme:TypeRef>
</h2>

The <b>AccessDataSource</b> control is a data source control that represents a connection to a Microsoft&trade; Access database.  
The AccessDataSource control derives from SqlDataSource, but exposes a simple <b>DataFile</b> property for specifying the path to an MDB file, instead of the complete connection string.
Note that you may still connect to an Access database using the SqlDataSource if you need to specify additional properties of the connection string, such as a user name or password.
<br /><br />
It is not recommended to use an Access database in a production web application.  For production purposes, consider connecting to a Microsoft&trade; SQL Server database using the SqlDataSource or ObjectDataSource controls.
<br /><br />

</asp:Content>
