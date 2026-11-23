<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Performing Data Access</h2>

<div class="new">
  <h3>What's New in 2.0</h3>

<ul>
  <li><b>Data Source Controls - </b> ASP.NET 2.0 introduces declarative data source controls that expose data from a backend store, such as a SQL database, middle-tier business object, or XML file, to data-bound UI controls on a page.  Data source controls also expose capabilities such as sorting, paging, caching, updating, inserting and deleting data that UI controls can automatically take advantage of without requiring code.</li>
  <br /><br />
  <li><b>New Data-bound Controls - </b> In addition to the data-bound controls in ASP.NET v1.x, ASP.NET includes new data-bound UI controls such as GridView, DetailsView, FormView, TreeView, and Menu, which can be customized to display data in a variety of formats.  The GridView, DetailsView, and FormView controls can also automatically take advantage of data source capabilities, making is easy to add sorting, paging, and update operations to data-driven pages.</li>
  <br /><br />
  <li><b>Data Control Parameters - </b> Data sources can accept input parameters from a variety of sources using the new data control parameter objects in ASP.NET 2.0.  These parameter objects allow you to easily supply server control property values, session, application, cookie and querystring fields, and user profile properties to parameterized data operations.  Using these parameters enables filtering and master-details scenarios with little or no custom code.</li>
  <br /><br />
  <li><b>Improved Data Binding Syntax - </b> The DataBinder.Eval data binding syntax in ASP.NET has been simplified for the common scenario of binding a control in a data-bound template.  It is also possible to associate a two-way data binding with control properties in a template, to allow values to be automatically passed to a data source update, insert, or delete operation.  For hierarchical XML data, ASP.NET 2.0 also includes an XPath-based data binding syntax.</li>
  <br /><br />
  <li><b>Local File Databases Using SQL Express - </b> For ease of development, ASP.NET 2.0 now supports the ability to connect to a SQL Express database as a local file in the application, eliminating the need to provision the database to a server just to perform development work.  Of course, you can still connect to server-based SQL databases as well.</li>
</ul>

This section describes these and other data access features in ASP.NET 2.0.
</div>

<br /><br />

Nearly every dynamic web application performs some kind of data access, and fortunately ASP.NET 2.0 makes this incredibly easy to do.  Unlike ASP.NET 1.0, which required developers to write custom code in order retrieve and bind data to server controls, ASP.NET 2.0 enables a declarative solution for data binding which requires no code at all for the most common data scenarios, such as:

<ul>
  <li>Selecting and displaying data</li>
  <li> Sorting, Paging and Caching Data</li>
  <li> Updating, Inserting and Deleting Data</li>
  <li> Filtering or Master-Details Using Parameters</li>
</ul>

ASP.NET 2.0 introduces two types of server controls that participate in this declarative data binding model.  These two types of data controls handle the complexity of the stateless Web model for data scenarios, so developers don't need to understand page request lifecycle events just to perform data binding.  Another benefit of this control-based model is that it can be easily extended to support additional data access storage providers.

<h3>Data Source Controls</h3>

Data source controls have no rendering, but instead represent a particular backend data store, for example a database, business object, XML file, or XML Web Service.  Data source controls also enable rich capabilities over data - such as sorting, paging, filtering, updating, deleting, and inserting - that data-bound UI controls can automatically use.  ASP.NET includes the following server controls out-of-the-box:
<br /><br />
<table class="table">
  <tr><th>Name</th><th>Description</th></tr>
  <tr><td><asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/data/sqldatasource.aspx" runat="server">SqlDataSource</asp:HyperLink></td><td>Enables binding to a SQL database represented by an ADO.NET provider, such as Microsoft&trade; SQL Server, OLEDB, ODBC, or Oracle.</td></tr>
  <tr><td><asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/data/objectdatasource.aspx" runat="server">ObjectDataSource</asp:HyperLink></td><td>Enables binding to a middle-tier object such as a data access layer or business component.</td></tr>
  <tr><td><asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/data/accessdatasource.aspx" runat="server">AccessDataSource</asp:HyperLink></td><td>Enables binding to a Microsoft&trade; Access (Jet) database.</td></tr>
  <tr><td><asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/data/sitemapdatasource.aspx" runat="server">SiteMapDataSource</asp:HyperLink></td><td>Enables binding to the hierarchy exposed by an ASP.NET 2.0 site navigation provider.</td></tr>
  <tr><td><asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/data/xmldatasource.aspx" runat="server">XmlDataSource</asp:HyperLink></td><td>Enables binding to an XML file or document.</td></tr>
</table>

<h3>Data-bound Controls</h3>

Data-bound controls are UI controls that render data as markup to the requesting client device or browser.  
A data-bound control can auto-bind to data exposed from a data source and will fetch data at the appropriate time in the page request lifecycle.
These controls can optionally take advantage of data source capabilities such as sorting, paging, filtering, updating, deleting, and inserting.
A data-bound control connects to a data source control through its <code>DataSourceID</code> property.  You may be familiar with some of the data-bound controls in ASP.NET v1.x, such as DataGrid, DataList, Repeater, and list controls like DropDownList.  ASP.NET 2.0 contains several new data-bound controls as well, such as:
<br /><br />
<table class="table">
  <tr><th>Name</th><th>Description</th></tr>
  <tr><td><asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/data/gridview.aspx" runat="server">GridView</asp:HyperLink></td><td>Renders data in a grid format.  This control is an evolution of the DataGrid control, and can automatically take advantage of data source capabilities.</td></tr>
  <tr><td><asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/data/detailsview.aspx" runat="server">DetailsView</asp:HyperLink></td><td>Renders a single data item in a table of label/value pairs, similar to the form view in Microsoft&trade; Access.  This control can also automatically take advantage of data source capabilities.</td></tr>
  <tr><td><asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/data/formview.aspx" runat="server">FormView</asp:HyperLink></td><td>Renders a single data item at a time in a form defined  by a custom template.  Renders a single data item in a table of label/value pairs, similar to the form view in Microsoft&trade; Access.  This control can also automatically take advantage of data source capabilities.</td></tr>
  <tr><td><asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/navigation/treeview.aspx" runat="server">TreeView</asp:HyperLink></td><td>Renders data in a hierarchical tree view of expandable nodes.</td></tr>
  <tr><td><asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/navigation/menu.aspx" runat="server">Menu</asp:HyperLink></td><td>Renders data in a hierarchical dynamic menu (including flyouts).</td></tr>
</table>
<br />

This section demonstrates these and other new data features in ASP.NET 2.0.

</asp:Content>

