<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Using the Site Navigation API</h2>

The Site Navigation API is a programming abstraction for navigation data that accesses navigation data using configurable providers.  A site navigation provider separates
the data storage details of navigation data from the rest of the API.  The Site Navigation API exposes the navigation data through the <b>SiteMap</b> and <b>SiteMapNode</b> classes. 
The <b>SiteMap</b> class returns the <b>SiteMapNode</b> instance that corresponds to the current page.  It also provides access to the provider(s) that have been 
configured for the Site Navigation feature.  A <b>SiteMapProvider</b> has a rich API for performing the following tasks:
<ul>
  <li> Retrieving <b>SiteMapNode</b> instances based on the current HttpContext, or based on an arbitrary URL.
  <li> Retrieving the parent, or child nodes of a <b>SiteMapNode</b>
  <li> Accessing the <b>SiteMapNode</b> for the current page, as well as the root <b>SiteMapNode</b> of the entire navigation hierarchy
  <li> Enforcing authorization rules so that only nodes visible to user are returned by the provider.
</ul>
A <b>SiteMapNode</b> instance exposes basic navigation information and functionality including:
<ul>
  <li> URL, title, and description properties are available as well as any custom attributes a developer added to a <b>SiteMapNode</b>
  <li> Obtain a node's parent as well as a node's children
  <li> Navigate through the sibling nodes before and after a node
  <li> Obtain a reference to the <b>SiteMapProvider</b> instance that returned a node
</ul>
ASP.NET ships with a provider called the <b>XmlSiteMapProvider</b>.  This provider consumes data from an XML file (<code>web.sitemap</code>) and returns <b>SiteMapNode</b> 
instances based on this data.  The <b>XmlSiteMapProvider</b> also has the following functionality:
<ul>
  <li> Multiple <code>sitemap</code> files can be linked together to form a single "virtual" set of navigation data
  <li> Multiple <b>XmlSiteMapProvider</b> instances can be linked together to form a single "virtual" set of navigation data
  <li> The provider can optionally filter returned nodes based on the file authorization and URL authorization rules currently in effect for a website.
</ul>
When you have a reference to a <b>SiteMapProvider</b>, you can search the site navigation data for a specific node based on URL.  This allows you to obtain 
references to <b>SiteMapNode</b> instances anywhere in your site navigation data.  The combination of finding arbitrary <b>SiteMapNode</b> instances and the ability
to navigate through site navigation data from any <b>SiteMapNode</b> allows you to easily walk through your site's navigation data.
<br /><br />
As a developer, you can choose to store your navigational data in other data stores using other formats (for example - as relational data in a database).  You can
then author a custom provider that derives from <b>SiteMapProvider</b>.  
<br/><br/>
<a name="sitemap2"></a>
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
these attributes will be available using the default indexer on the <code>SiteMapNode</code> class.  For information on other attributes supported on the
<code>&lt;siteMapNode&gt;</code> element please see the .NET Framework documentation.
<br /><br />

<Acme:SourceRef
  RunSample="../../samples/navigation/Web.sitemap.xml"
  ViewSource="~/aspnet/samples/navigation/SiteMap.src"
  Caption="Web.sitemap Example"
  runat="server" />

<a name="api"></a>
<h3>Programming with Site Navigation Classes</h3>

You can obtain site navigation data programmatically in code.  The starting point for obtaining Site Navigation data programmatically is the <b>SiteMap</b> class.  There are a variety of static methods on this class, the most important one being
the <code>CurrentNode</code> property.  On any page in your website, you can call <code>SiteMap.CurrentNode</code> to reference a piece of navigation
data matching the currently executing page.  Navigation data is returned as an instance of a <b>SiteMapNode</b> - when you call <code>SiteMap.CurrentNode</code> the
property returns a <b>SiteMapNode</b> instance corresponding to the current page.  The Site Navigation feature determines the correct node to return based upon 
navigation data that is stored in an XML file.  
<br /><br />
The following sample demonstrates a user control with simple paging.  On the page that is displayed, the user control renders at the bottom center of the page.  
Initially there is link [Next Topic].  When you click on this link the user control calls the <b>SiteMap</b> object to 
determine whether or not there are sibling pages around the current page.  From the <code>SiteMap.CurrentNode</code> property, the code determines if there are 
previous siblings (<code>SiteMap.CurrentNode.PreviousSibling</code>) as well as following siblings (<code>SiteMap.CurrentNode.NextSibling</code>).  Based upon 
the existence of these siblings, the user control renders hyperlinks, setting each hyperlink's <code>NavigateUrl</code> property to the value of the sibling node's
<code>Url</code> property.  
<br /><br />
If you click the various Treeview links on the left-hand side of the page, also notice how the user control automatically displays the appropriate [Next Topic] and 
[Previous Topic] links.  The user control also renders a hyperlink that you can click on to return back to the home page.  If you look at the code for how this hyperlink 
is rendered, the control uses a custom attribute on the home page <code>&lt;siteMapNode&gt;</code> element called "customAttribute".  The control demonstrates how to use the
 <code>SiteMapNode</code>'s default indexer to retrieve the value of this custom attribute.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/navigation/sitemapapi_cs/sectionone/firstpage.aspx"
        ViewSource="~/aspnet/samples/navigation/sitemapapi.src"
        Caption="C# SiteMap API"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/navigation/sitemapapi_vb/sectionone/firstpage.aspx"
        ViewSource="~/aspnet/samples/navigation/sitemapapi.src"
        Caption="VB SiteMap API"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="security"></a>
<h3>Site Navigation Security</h3>

The Site Navigation feature can optionally filter the <b>SiteMapNode</b> instances returned by a provider based upon authorization rules.  The <b>XmlSiteMapProvider</b> 
can filter nodes based on the file and URL authorization rules that apply to the current website.  
<br /><br />
The following sample uses forms authentication with predefined user credentials stored in web.config.  In global.asax, roles are attached to the current request 
based on the username.  In <code>web.config</code>, the <code>&lt;add&gt;</code> element for sitemap providers
nested under the <code>&lt;siteMap&gt;</code> element has its <code>securityTrimmingEnabled</code> attribute set to <code>
true</code>.  Also the <code>web.config</code> file defines a number of URL authorization rules at the bottom of the file.  When you run the sample and log in, the 
<b>XmlSiteMapProvider</b>  will automatically perform an authorization check for each <b>SiteMapNode</b> based on the combination of the roles the user belongs to and 
the authorization rules defined in <code>web.config</code>.
<br /><br />
Try running the sample as one of the following three user accounts:
<ul>
  <li> Userid: SectionOne   &nbsp;&nbsp;&nbsp;Password: SectionOne
  <li> Userid: SectionTwo   &nbsp;&nbsp;&nbsp;Password: SectionTwo
  <li> Userid: AllSections  &nbsp;&nbsp;&nbsp;&nbsp;Password: AllSections
</ul>
There is a logout link in the upper right-hand corner of the page so that you can login and logout with different accounts. 
Notice how depending on which account you log in with, the navigation UI displayed in the Treeview and Menu controls automatically changes to reflect the URLs that 
each user is authorized to access.  The provider automatically filters the returned nodes - no extra code is required for this behavior. 
Logging in as the user "SectionOne" results in only links for "SectionOne" and outside links being shown in the left-hand Treeview control.   Logging in as 
the user "SectionTwo" results in only links for "SectionTwo" and outside links being shown  in the left-hand Treeview control.  Logging in as the user "AllSections"
 displays all links in the Treeview control.  The authorization rules in <code>web.config</code> are configured to selectively grant access to the "SectionOne" and
 "SectionTwo" URL hierarchies.
<br /><br />
This sample also demonstrates how security trimming works with URLs that lie outside of the directory scope for an application.  In the <code>web.sitemap</code> file 
the <code>roles</code> attribute is used on the nodes for external links.  The syntax <code>roles="*"</code> grants all users the right to retrieve and view that node 
in navigation controls.  The syntax <code>roles="Adminstrators,Regular Users"</code> allows only users in those roles the right to retrieve and view the nodes in 
navigation controls.  Since the <code>global.asax</code> file allocates the users in this sample to one of these two roles, you will always be able to view the external 
links.
<br /><br />
Developers have the option to use both file/URL authorization rules and the <code>roles</code> attribute to control access to <b>SiteMapNode</b> instances.  If both 
sets of information are available, a site navigation provider will attempt to authorize the current user based on <b>both</b> file/URL authorization rules as well as the
 roles in the <code>roles</code> attribute.  If the current user passes either set of authorization checks, then the current user is granted access to the node.
<br /><br />
If the default security trimming behavior is not suitable for your application, a developer can derive from <b>XmlSiteMapProvider</b> and override the <code>
IsAccessibleToUser</code> method with a custom implementation for node authorization.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/navigation/sitemapsecurity_cs/home.aspx"
        ViewSource="~/aspnet/samples/navigation/SiteMapSecurity.src"
        Caption="C# Site Navigation Security"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/navigation/sitemapsecurity_vb/home.aspx"
        ViewSource="~/aspnet/samples/navigation/SiteMapSecurity.src"
        Caption="VB Site Navigation Security"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="localization"></a>
<h3>Localizing Site Map Data</h3>

Navigation data stored in a <code>sitemap</code> file may need to be localized.  The URL, Title, and Description attributes on a <code>&lt;siteMapNode&gt;</code>
 element can all be localized.  In addition, any custom attributes that a developer places on a <code>&lt;siteMapNode&gt;</code> element can also be localized.
<br /><br />
The sample includes localized text for both the English and French languages.  The <code>web.sitemap</code> file uses two types of localization expressions to 
accomplish this:  implicit and explicit expressions.  For more details on localization in general, as well as background information on the two types of localization
 expressions see the topic "Localizing Your Application" in the Quickstart.  A <code>sitemap</code> file indicates that it uses localized data by the presence of 
<code>enableLocalization=true</code> on the root <code>siteMap</code> element.
<br /><br />
In a <code>sitemap</code> file implicit expressions make it easy for a developer to tag each <code>&lt;siteMapNode&gt;</code> element with a lookup key that will be used 
to retrieve resources from a resource file.  In the sample <code>web.sitemap</code>, implicit resource expressions are on every node except the first one.  The 
syntax looks like: <code>resourceKey="Autos"</code>.  When the <b>XmlSiteMapProvider</b> retrieves a <b>SiteMapNode</b> based on information in the <code>web.sitemap</code> 
file, it will look for a string resource based on a combination of the name of the <b>SiteMapNode</b> property, the <code>resourceKey</code> and the value of the 
<code>siteMapFile</code> attribute configured for the provider.  Using the "Autos" node as an example, the provider will look in a resource file that begins with 
"web.sitemap" based on the current culture.  This means for a browser that sends a french language header, the provider will look for a resource file called 
<code>web.sitemap.fr.resx</code>.  Within the resource file, the provider will look for a resource key whose name is based on <code>resourceKey</code> + "." + 
[name of the <b>SiteMapNode</b> property].  Using the Title property for the "Autos" node as an example, the provider will look a resource whose key is 
<code>Autos.Title</code> inside of the resource file called <code>web.sitemap.fr.resx</code>.
<br /><br />
Explicit expressions give the developer more control over the files that contain localized resources as well as the name of resource key.   In the sample 
<code>web.sitemap</code>, an explicit resource expression is used for the first <code>&lt;siteMapNode&gt;</code> element.  Explicit expressions are specified on a per-
attribute basis.  The first <code>&lt;siteMapNode&gt;</code> element uses an explicit expression for the <code>Title</code> attribute.  An explicit expression must always 
start with <code> $resource: </code>.  After this identifier, a developer must provide the root name for the resource file, as well as the resource key.  Optionally a 
developer can also supply a default value.  In the sample, the expression <code> $resources: Title, MyTitle , Home</code> indicates that the provider should look in 
a resource file that starts with "Title".  For a browser that sends a french language header, the provider would look for a resource file called <code>Title.fr.resx</code>.
The provider would then look for a resource whose key is <code>MyTitle</code>.  If the provider cannot find such a resource, it will fallback and use the string "Home" as 
the default value.
<br /><br />
To see the effects of sitemap localization, run the sample.  Browsers that indicate English as the default language will see English text returned.  If using IE, you
can change the default language by going to Tools-->Internet Options and selecting the "Languages" button on the "General" tab.  Press the "Add" button and choose to 
add "French (France) [fr]" as a language.  If necessary, select the option for the French language and press "Move Up" to make it the default language requested by IE.  After
changing the default language to French, refresh the sample page.  Note that the text in the Menu, Treeview and SiteMapPath controls automatically change to reflect the 
French text stored in the French resource files located in the <code>App_GlobalResources</code> directory.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/navigation/sitemaplocalization_cs/default.aspx"
        ViewSource="~/aspnet/samples/navigation/SiteMapLocalization.src"
        Caption="C# Sitemap Localization"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/navigation/sitemaplocalization_vb/default.aspx"
        ViewSource="~/aspnet/samples/navigation/SiteMapLocalization.src"
        Caption="VB Sitemap Localization"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="resolve"></a>
<h3>Modifying Site Navigation Data Returned by Providers</h3>

The navigation data contained in <code>web.sitemap</code> that is consumed by the <b>XmlSiteMapProvider</b> is static - the data is loaded into memory and stored as 
read-only data.  However, many sites have a navigation structure that is parameterized based on querystring values.  For example, a newsgroup site may have a well-defined 
structure of pages (e.g. a home page, a news category page, and a news article page), but the actual content will vary depending on identifiers in the querystring.  Although
it is possible to store every possible permutation of querystring values in <code>&lt;siteMapNode&gt;</code> elements, for even moderate numbers of querystring values 
a <code>sitemap</code> file could contain hundreds or thousands of <code>&lt;siteMapNode&gt;</code> elements.
<br /><br />
The Site Navigation feature exposes the <code>SiteMapResolve</code> event on the <code>SiteMapProvider</code> base class.  An event subscription can be made using either
<code>SiteMap.SiteMapResolve</code> or directly against individual providers using <code>SiteMap.Provider.SiteMapResolve</code>.  The return value from the event is a
 <code>SiteMapNode</code> instance.  In your event handler you can write custom logic to create a hierarchy of <code>SiteMapNode</code> instances.  This logic can modify 
the properties on each <code>SiteMapNode</code> so that properties like URL and Title reflect additional information based on data taken from the querystring.
<br /><br />
The sample below registers an event handler in <code>global.asax</code>.  The code for the event handler is in a class located in the <code>App_Code</code> directory.  The 
custom class makes a clone of the <code>SiteMapNode</code> instance corresponding the current page.  Since nodes from <b>XmlSiteMapProvider</b> are read-only, calling the
<code>Clone</code> method on a <code>SiteMapNode</code> returns a writeable instance of the node.  In the sample the <code>Clone</code> method is passed a value of <Code>
true</code>, which results in a writeable copy of the current <code>SiteMapNode</code> as well as all of the node's parents.  The remainder of the code in the class 
inspects the current page and the current page's querystring to determine where in the site hierarchy the current page is located.  The code fixes up the URL and Title
 properties by including additional information so that navigation UI rendered by the <b>SiteMapPath</b> control reflects the actual click-path the website user followed
 to reach the current page.
<br /><br />
When you run the sample you will initially be on the home page of the site.  The <code>SiteMapPath</code> control will reflect this as well.  Clicking on either of the 
links will bring you to a category page that displays links to news articles relevant to a specific news category.  Notice that if you hover over the last link in the
 <code>SiteMapPath</code> control, the URL displayed in the browser's status bar includes the querystring information specifying the type of news category.  Clicking on 
one of the posting links brings you to the news posting page.  If you hover over the links in the <code>SiteMapPath</code> control, notice that the last two links 
in the control have URLs and Titles that contain the correct querystring and descriptive information based on the clickpath.  If you navigate back to the home page of
 the site, try clicking the other set of newsgroup and content links, and again notice how the <code>SiteMapPath</code> control is updated to reflect the second set of 
links that you clicked.
<br/> <br />
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/navigation/sitemapresolve_cs/Home.aspx"
        ViewSource="~/aspnet/samples/navigation/SiteMapResolve.src"
        Caption="C# Using the SiteMapResolve Event"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/navigation/sitemapresolve_vb/Home.aspx"
        ViewSource="~/aspnet/samples/navigation/SiteMapResolve.src"
        Caption="VB Using the SiteMapResolve Event"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>

