<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>URL Mapping</h2>

The URL mapping feature uses configuration information stored in <code>web.config</code> to remap incoming requests to a different URL.  The remapping occurs prior to
any other processing for the inbound request.  Although the sample below demonstrates remapping a page request, any arbitrary file type can have its request remapped 
to a different URL.
<br />

<a name="remapping"></a>
<h3>Defining Remapped URLs</h3>

Configuration information for URL Mapping is stored in <code>web.config</code>.  Each <code>&lt;add&gt;</code> element nested within the <code>&lt;urlMappings
&gt;</code> element defines a rule for remapping an inbound url.  The <code>url</code> attribute defines the <b>exact</b> value of the inbound url that the URL
 Mapping feature will attempt to match.  If an <b>exact</b> match occurs, the inbound URL is rewritten to the value of the <code>mappedUrl</code> attribute.  Note that 
the feature does not support more advanced rules such as wildcard or regular expression based matches.
<br /><br />
The sample <code>web.config</code> defines mapping rules for a number of urls.  The <code>web.sitemap</code> file for the sample defines most of its nodes with URL values 
that will be remapped.  As a result, the combination of URL Mapping and Site Navigation allows a developer to define a navigation structure in 
terms of friendly urls, while using URL Mapping to rewrite requests to a different set of pages that perform the actual processing.
<br /><br />
When you run the sample, notice how the Menu and Treeview controls render navigation data based on the site structure defined in the <code>web.sitemap</code> file.  If you
 hover over any of the links in the Treeview control or the SiteMapPath control in the upper righthand corner, the url that is shown in the status bar is a friendly url. 
When you click on any of the navigation links, the actual page that runs is <code>Default.aspx</code>.  However, the navigation information in the Menu, Treeview and 
SiteMapPath controls continues to reflect the friendly URL structure. 
<br/><br/>
At the bottom of the page you can also see the values returned from <code>Request.Path</code>, <code>Request.QueryString["category"]</code>, and <code>Request.RawUrl</code>
 .  The values for <code>Request.Path</code> and <code>Request.QueryString["category"]</code> always reflect the results of remapping the inbound url.  However, the value 
for <code>Request.RawUrl</code> reflects the friendly url prior to remapping.  The Site Navigation feature always uses the <code>Request.RawUrl</code> when attempting to 
match url information to data contained in a <code>sitemap</code> file.  If a matching value is not found, then the <b>XmlSiteMapProvider</b> falls back and uses the 
<code>Request.Path</code> instead.  In this sample, all of the friendly urls have an entry in the <code>web.sitemap</code> file, so the controls that use Site Navigation 
always display and reference nodes based on the friendly url.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/navigation/urlmapping_cs/default.aspx"
        ViewSource="~/aspnet/samples/navigation/urlmapping.src"
        Caption="C# Url Mapping"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/navigation/urlmapping_vb/default.aspx"
        ViewSource="~/aspnet/samples/navigation/urlmapping.src"
        Caption="VB Url Mapping"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>


</asp:Content>

