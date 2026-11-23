<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Creating a Site Navigation Hierarchy</h2>

<div class="new">

<h3>What's New in 2.0</h3>

<ul>
  <li><b>Site Navigation Provider - </b> The site navigation provider in ASP.NET 2.0 exposes navigation information to pages in your application, allowing you to define the structure of your site separately from the actual physical layout of pages.  The default site navigation provider is XML-based, but you may also expose this information from any backend by writing a custom provider for your site map.</li>
  <br /><br />
  <li><b>Site Navigation API - </b> The site navigation API provides access to site navigation information from code in your application, abstracting away the details about where navigation information in stored.  You can use the API to programmatically traverse the navigation nodes of your application. </li>
  <br /><br />
  <li><b>Navigation Controls - </b> The navigation controls provide common UI for navigating between pages in your site, such as treeviews, menus, and breadcrumbs. These controls use the site navigation service in ASP.NET 2.0 to retrieve the custom structure you have defined for your site.  The SiteMapDataSource control also enables you to bind other UI controls to site navigation data.</li>
</ul>
This section discusses these and other navigation features in ASP.NET 2.0. 
</div>

<br /><br />

Websites frequently need to display navigation data that guides users through a site.  The navigation features of ASP.NET allow developers to easily define navigation 
data and display UI based upon this information.
<br/><br />
The Site Navigation API is a provider-based programming abstraction
for accessing site navigation data.  The API stores navigation data in an XML file, and exposes this data as a set of <b>SiteMapNode</b> classes.  Application 
and control developers can consume <b>SiteMapNode</b> instances and use this information to render navigation UI.
<br /><br />
Navigation-oriented server controls include the <b>Menu</b>, <b>TreeView</b>, <b>SiteMapPath</b> and <b>SiteMapDataSource</b> controls.  These controls are built on top of the Site Navigation classes
and consume and display navigation data without being aware of data-store specific storage issues.  The <b>Menu</b> and <b>Treeview</b> controls can also consume data 
from XML files and from the <b>XMLDataSource</b> control.
<br /><br />
The Url mapping feature allows developers to define simple rules for re-mapping incoming requests to different URLs.  
<br />


</asp:Content>

