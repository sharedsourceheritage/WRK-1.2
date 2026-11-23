<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Creating a Layout Using Master Pages</h2>

<div class="new">

<h3>What's New in 2.0</h3>

<ul>
  <li><b>Master Pages - </b> The Master Pages feature provides the ability to define common structure and interface elements for your site, such as a page header, footer, or navigation bar, in a common location called a "master page", to be shared by many pages in your site. This improves the maintainability of your site and avoids unnecessary duplication of code for shared site structure or behavior.</li>
</ul>
This section discusses the Master Pages feature in ASP.NET 2.0. 
</div>

<br /><br />

Just as Themes and Skins allow you to factor out style definitions from your page code and maintain them in a common file, Master Pages do the same for page layout.  A <b>Master Page</b> is a page that contains markup and controls that should be shared across multiple pages in your site.  For example, if all of your pages should have the same header and footer banners or the same navigation menu, you could define this in a Master Page once, and then all pages associated to this Master Page would inherit those common elements.  The advantage of defining the header, footer, and navigation in a Master Page is that these elements need only be defined once, instead of multiple times in duplicate code across the pages in your site.
<br/>

<a name="content"></a>
<h3>Master and Content Pages</h3>

Defining a Master Page is just like defining a normal page.  Master Pages can contain markup, controls, or code, or any combination of these elements.  However, a Master Page can contain a special type of control, called a <b>ContentPlaceHolder</b> control.  A ContentPlaceHolder defines a region of the master page rendering that can be substituted with content from a page associated to the master.  A ContentPlaceHolder can also contain default content, just in case the derive page does not need to override this content.  The syntax of a ContentPlaceHolder control is given below:

<pre class="code">
<b>&lt;%-- ContentPlaceHolder control --%&gt;</b>
&lt;asp:contentplaceholder id="FlowerText" runat="server"/&gt;

<b>&lt;%-- ContentPlaceHolder with default content --%&gt;</b>
&lt;asp:contentplaceholder id="FlowerText" runat="server"&gt;
  &lt;h3&gt;Welcome to my florist website!&lt;/h3&gt;
&lt;/asp:contentplaceholder&gt;
</pre>

To differentiate a Master Page from a normal page, a Master Page is saved under the .master file extension.  A page can derive from a Master Page by defining a <code>MasterPageFile</code> attribute on its Page directive, as demonstrated below.  A page that is associated to a Master Page is called a <b>Content Page</b>.

<pre class="code">
&lt;%@ Page MasterPageFile="Site.master" %&gt;
</pre>

A Content Page can declare <b>Content</b> controls that specifically override content placeholder sections in the Master Page.  A Content control is associated to a particular ContentPlaceHolder control through its <code>ContentPlaceHolderID</code> property.  A Content Page may only contain markup and controls inside Content controls; it cannot have any top-level content of its own.  It can, however, have directives or server-side code.
<br/><br/>

<pre class="code">
&lt;%@ Page MasterPageFile="Site.master" %&gt;

&lt;asp:content id="Content1" contentplaceholderid="FlowerText" runat="server"&gt;
    With sunshine, water, and careful tending, roses will bloom several times in a season.
&lt;/asp:content&gt;
&lt;asp:content id="Content2" contentplaceholderid="FlowerPicture" runat="server"&gt;
    &lt;asp:Image id="image1" imageurl="~/images/rose.jpg" runat="server"/&gt;
&lt;/asp:content&gt;
</pre>

The following example demonstrates the relationship between Master and Content pages.  The Master Page in this case defines two ContentPlaceHolder regions, named <code>FlowerPicture</code> and <code>FlowerText</code>, along with some default content for those regions.  Individual content pages in the site inherit the common site layout and look-and-feel from the Master Page, but override the default content for the named ContentPlaceHolder regions with their own content.  Note that the Default.aspx page in this site does not define any Content controls, and so it just inherits the default content from the Master Page.
<br/><br/>


<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/masterpages/masterpages_cs/default.aspx"
        ViewSource="~/aspnet/samples/masterpages/masterpages.src"
        Caption="C# Master and Content Pages"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/masterpages/masterpages_vb/default.aspx"
        ViewSource="~/aspnet/samples/masterpages/masterpages.src"
        Caption="VB Master and Content Pages"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>


<a name="urls"></a>
<h3>URL Rebasing in a Master Page</h3>

One thing to notice about the preceding example is that there are several places in the Master Page that refer to URL resources like images or stylesheet or page references using a relative-path syntax, for example:

<pre class="code">
&lt;head&gt;
  &lt;link rel="stylesheet" href="StyleSheet.css" type="text/css" /&gt;
&lt;/head&gt;
...
&lt;a href="daffodil.aspx"&gt;Daffodil&lt;/a&gt;
...
&lt;img alt="water lilies" src="Images/waterlilies.jpg"/&gt;
</pre>

This works fine when the Master Page and Content Page are in the same directory, but when the Content Page is in a physically separate location, the relative path will not be correct.  To solve this problem, you may take one of the following approaches:

<ul>
  <li>Use absolute URL paths in the Master Page, for example &lt;img src="/myapplication/images/banner.gif" /&gt;
  <li>Use relative or application-relative URLs in server controls instead of static markup, for example &lt;asp:Image ImageUrl="~/images/banner.gif" runat="server" /&gt;
</ul>

The following example demonstrates this technique.  The Content Pages have been moved to a subdirectory "Pages" under the directory that contains the Master Page.  The Master Page has been updated to use server controls in place of HTML:

<pre class="code">
&lt;head runat="server"&gt;
  &lt;link rel="stylesheet" href="StyleSheet.css" type="text/css" /&gt;
&lt;/head&gt;
...
&lt;a id="A1" href="pages/daffodil.aspx" runat="server"&gt;Daffodil&lt;/a/&gt;
...
&lt;asp:Image ID="Image1" AlternateText="Water Lillies" ImageUrl="~/Images/Waterlilies.jpg" runat="server"/&gt;
</pre>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/masterpages/masterpages_cs/pages/default.aspx"
        ViewSource="~/aspnet/samples/masterpages/urlmapping.src"
        Caption="C# URL Mapping in Master Pages"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/masterpages/masterpages_vb/pages/default.aspx"
        ViewSource="~/aspnet/samples/masterpages/urlmapping.src"
        Caption="VB URL Mapping in Master Pages"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="code"></a>
<h3>Accessing a Master Page from Code</h3>

In addition to overriding content, it is possible for a Content Page to programmatically access its Master Page.  A Content Page creates a strongly-typed reference to the Master Page using the <code>&lt;%@ MasterType %&gt;</code> directive, specifying the virtual path to the master page:

<pre class="code">
&lt;%@ MasterType VirtualPath="Site.master" %&gt;
</pre>

The Content Page can then reference the Master Page using the <code>Master</code> property of the <b>Page</b> class:

<br/><br/>
<Acme:TabControl runat="server">

<Tab Name="C#">
Master.FooterText = "This is a custom footer";
AdRotator ad = (AdRotator)Master.FindControl("MyAdRotator");
</Tab>

<Tab Name="VB">
Master.FooterText = "This is a custom footer"
Dim ad As AdRotator = Master.FindControl("MyAdRotator")
</Tab>

</Acme:TabControl>
<br/><br/>

In the code example above, <code>FooterText</code> is a public property exposed on the Master Page, while <code>MyAdRotator</code> is a control on the Master Page.  The following example demonstrates this code in action:

<br/><br/>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/masterpages/masterpages_cs/pages/rosecode.aspx"
        ViewSource="~/aspnet/samples/masterpages/codeaccess.src"
        Caption="C# Accessing Master Pages in Code"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/masterpages/masterpages_vb/pages/rosecode.aspx"
        ViewSource="~/aspnet/samples/masterpages/codeaccess.src"
        Caption="VB Accessing Master Pages in Code"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="nested"></a>
<h3>Nesting Master Pages</h3>

Content Pages can also be Master Pages.  That is, it is possible to derive a Master page from another Master Page.  For example, you might have a top-level Master Page that represents the overall site header/footer and navigation of your site, and then separate Master Pages that derive from this Master in order to define different looks for the various sub-sections within your site.  Content Pages would then derive from the appropriate section master for the section the Content Page belongs to.  The following example demonstrates this idea, dividing the Florist example site into two sections, Annuals and Perrennials.

<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/masterpages/masterpages_cs/home.aspx"
        ViewSource="~/aspnet/samples/masterpages/nestedmasters.src"
        Caption="C# Nested Master Pages"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/masterpages/masterpages_vb/home.aspx"
        ViewSource="~/aspnet/samples/masterpages/nestedmasters.src"
        Caption="VB Nested Master Pages"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
