<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Using Site Navigation Controls</h2>

The Menu, TreeView, SiteMapPath and SiteMapDataSource controls generate navigation UI based on navigation data.  This data can be stored in XML files, or it can be 
stored using the provider-based storage capabilities of the Site Navigation feature.  The samples below demonstrate using the different controls in conjunction
with the Site Navigation feature.
<br />

<a name="sitemap"></a>
<h3>Creating an Application Site Map</h3>

The navigation structures for the Site Navigation QuickStart samples are represented in <b>Web.sitemap</b> files.
In the sitemap file that you can view below, the navigational structure for the entire QuickStart is shown.  A <b>Web.sitemap</b> file contains a single 
top-level <code>&lt;siteMap&gt;</code> element.  Nested within the <code>&lt;siteMap&gt;</code> element is at least one <code>&lt;siteMapNode&gt;</code> element.
There must always be a top-level <code>&lt;siteMapNode&gt;</code> within a site map.  The Site Navigation feature requires a single root <code>&lt;siteMapNode&gt;</code> 
to ensure that walking up a hierarchy of nodes is guaranteed to eventually converge on a single well-known node.  You can nest as many 
<code>&lt;siteMapNode&gt;</code> elements beneath the root <code>&lt;siteMapNode&gt;</code> element as needed.  Additionally, you can nest 
<code>&lt;siteMapNode&gt;</code> elements to any arbitrary depth.
<br /><br />
An individual <code>&lt;siteMapNode&gt;</code> element usually contains a <code>Url</code>, <code>Title</code> and <code>Description</code> attribute.  The
<code>Url</code> attribute can indicate a virtual path that corresponds to a page in your application.  It can also contain paths to pages in other applications, 
or URLs that point at completely different web sites.  In the sample below, all of the <code>Url</code> attributes use application-relative syntax to reference
paths located within the QuickStart application.  The <code>Title</code> attribute is used as display text when rendering UI for navigational data.  For example,
the SiteMapPath control uses the <code>Title</code> attribute to render the text of the hyperlinks in the control.  If a <code>Description</code> attribute is 
present, server controls may use this information to display tooltips or ALT text.  A developer can also add custom attributes to a <code>&lt;siteMapNode&gt;</code> and
these attributes will be available using the default indexer on the <code>SiteMapNode</code> class.    For information on other attributes supported on the
<code>&lt;siteMapNode&gt;</code> element please see the .NET Framework documentation.
<br /><br />

<Acme:SourceRef
  RunSample="../../samples/navigation/Web.sitemap.xml"
  ViewSource="~/aspnet/samples/navigation/SiteMap.src"
  Caption="Web.sitemap Example"
  runat="server" />

<a name="controls"></a>
<h3>Using the Site Navigation Controls</h3>

An easy way to provide site navigation on your web page is to use one of the site graphical site navigation controls: SiteMapPath, TreeView and Menu.  
<br/><br/>
<ul>
<li><asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/navigation/sitemappath.aspx" runat="server">SiteMapPath</asp:HyperLink> - A breadcrumb control that retrieves the user current page and displays the hierarchy of pages. This enables the users to navigate back to other pages in the hierarchy.  SiteMapPath works exclusively with the SiteMapProvider which can be set via the SiteMapProvider property on the control.  
<br/><br/>
<li><asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/navigation/treeview.aspx" runat="server">TreeView</asp:HyperLink> - Provides the vertical user interface to expand and collapse selected nodes on a web page as well as providing check box functionality for selected items. The TreeView control supports declarative and programmatic settings of data elements and data source controls. If you use the SiteMapDataSource control, databinding will be automatic. 
<br/><br/>
<li><asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/navigation/menu.aspx" runat="server">Menu</asp:HyperLink> - Provides a horizontal or vertical user interface that “pops-out” additional sub-menu's when a user hovers over an item. . The Menu control supports declarative and programmatic settings of data elements and data source controls. If you use the SiteMapDataSource control, databinding will be automatic.
</ul>

NOTE: Both TreeView and Menu controls can be used for non-navigational scenarios. 
<br/><br/>
Here is a table highlighting some of the differences between TreeView and Menu to help you choose the right control for your particular scenario.
<br/><br/>

<table class="table">
  <tr>
    <th width="30%">Feature</th><th width="35%">Menu</th><th width="35%">TreeView</th>
  </tr>
  <tr>
    <td>Expansion</td><td>PopOut</td><td>Expand in place</td>
  </tr>
  <tr>
    <td>Download on Demand</td><td>No</td><td>Yes</td>
  </tr>
  <tr>
    <td>Checkboxes</td><td>No</td><td>Yes</td>
  </tr>
  <tr>
    <td>Templates</td><td>Yes</td><td>No</td>
  </tr>
  <tr>
    <td>Layout</td><td>Horizontal & Vertical</td><td>Vertical</td>
  </tr>
  <tr>
    <td>Style Options</td><td>Yes</td><td>Yes</td>
  </tr>
  <tr>
    <td>Selection Model</td><td>Static, Dynamic Level</td><td>Level or Parent/Root/Leaf, or by data item</td>
  </tr>
</table>
<br/>

In this sample you see TreeView and Menu controls with various style properties configured for different areas and actions (for example, <code>NodeStyle</code> and <code>HoverNodeStyle</code>). The TreeView and Menu controls are both connected to the same SiteMapDataSource control on the page.  The SiteMapPath control is accessing the same data via the default SiteMapProvider which is set in the Web.config file. 
<br/><br/>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/navigation/sitemapcontrols_cs/Home.aspx"
        ViewSource="~/aspnet/samples/navigation/sitemapcontrols.src"
        Caption="C# Navigation Controls"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/navigation/sitemapcontrols_vb/Home.aspx"
        ViewSource="~/aspnet/samples/navigation/sitemapcontrols.src"
        Caption="VB Navigation Controls"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br/><br />

</asp:Content>

