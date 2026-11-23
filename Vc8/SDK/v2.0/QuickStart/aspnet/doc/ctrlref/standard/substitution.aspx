<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.Substitution" runat="server">
  Substitution
</Acme:TypeRef>
</h2>

ASP.NET v1.x introduced a powerful feature known as Partial Page Caching. This feature allowed developers to construct ASP.NET pages which were partly dynamic and partly cached.  Regions marked as dynamic are executed on each request while areas marked as cached are executed only once and cached until a specific dependency is enforced.  The cached regions are separated into user controls with appropriate cache directives, and the dynamic content either remains in the parent Page or is contained in user controls without cache directives.  
<br /><br />
This partial page caching approach works very well for scenarios where most of the page content is dynamic and/or it is easy to encapsulate cached content into isolated user controls.  It does not work as well for the inverse scenario, when the majority of page content should be cached and only a small portion is to be dynamic.  For example, consider a page of news stories extracted from a database, which contains a single rotating advertisement.  In this scenario, the news stories (and surrounding page header, footer, and site navigation interface) might be easily cached, since they change relatively infrequently.  However, the rotating advertisement should change on each page request, to display a random advertisement to each site visitor.
<br /><br />
ASP.NET Whidbey introduces a new feature called Post-Cache Substitution, which is aimed at optimizing the development experience for this mostly-cached page scenario.  Rather than requiring page developers to mark page regions (user controls) as cached, post-cache substitution allows them to output cache an entire page and then simply identify regions of the page that should be exempt from caching.  It also allows control developers to prevent their rendering from from being cached.  In the above example, an AdRotator control that takes advantage of post-cache substitution would be able to serve a different advertisement on each request even if its parent page were cached.
<br /><br />

<h3>Using the Substitution API</h3>

Page developers can easily take advantage of post-cache substitution in their output-cached pages.  A developer simply writes a method with a prescribed SubstitutionCallback signature that takes a single HttpContext parameter and returns a String, which is the content to substitute at a given location.  The developer then calls <code>Response.WriteSubstitution</code>, passing the callback method as a parameter.  The callback method can either be a static method on the containing Page or UserControl, or a static or instance method on another arbitrary object, and must be thread-safe.
<br /><br />

<pre class="code">
&lt;%@ OutputCache Duration="60" VaryByParam="none" %&gt;

&lt;script language="C#" runat="server"&gt;

  public static String GetCurrentDate (HttpContext context) {
    return DateTime.Now.ToString();
  }

&lt;/script&gt;

... cached content ...

&lt;form runat="server"&gt;
  &lt;% Response.WriteSubstitution (new HttpResponseSubstitutionCallback(GetCurrentDate)) %&gt; 
&lt;/form&gt;
</pre>

On the first request to the page, WriteSubstitution performs these steps:

<ol>
  <li>Calls the HttpResponseSubstitutionCallback delegate to produce the output.
  <li>Adds a substitution buffer to the response, which retains the delegate to call on future requests, as well as the first-time output from step 1.
  <li>Degrades client-side cacheability from public to server-only, so that the will not be cached on the client, ensuring future requests to the page re-invoke the delegate.
</ol>

On subsequent requests, the cache module intercepts incoming requests and retrieves the associated stored buffers.  When writing the substitution buffer, the delegate is invoked to produce new output, which is written to the response.
<br /><br />

<h3>Using the Substitution Control</h3> 

Alternatively, a developer can place a Substitution server control at the page location where content should be substituted, and set its MethodName property to the callback method.  Unlike <code>Response.WriteSubstitution</code>, which can accept a callback method on an arbitrary object, the Substitution server control's MethodName property must be set to a static method on the control's containing <b>Page</b> or <b>UserControl</b>. 
<br /><br />

<pre class="code">
&lt;%@ OutputCache Duration="60" VaryByParam="none" %&gt;

&lt;script language="C#" runat="server"&gt;

  public static String GetUserName (HttpContext context) {
    return context.User.Identity.Name;
  }

&lt;/script&gt;

... cached content ...

&lt;form runat="server"&gt;
  &lt;h2&gt;Welcome &lt;asp:Substitution MethodName="GetUserName" /&gt;!&lt;/h2&gt;
&lt;/form&gt;
</pre>

Note that the HttpContext parameter to the callback may be used to retrieve request parameters such as querystring variables, authentication info, or personalization details.  In the example above, it is used to retrieve the User.Identity.Name field.
The example below shows using the Substitution control from within a page.
<br /><br />

<Acme:LangSwitch ID="LangSwitch4" runat="server">
  <cstemplate>
    <Acme:SourceRef
      RunSample="../../../samples/caching/substitution/PostCacheSubstitution2_cs.aspx"
      ViewSource="~/aspnet/samples/caching/substitution/PostCacheSubstitution2.src"
      Caption="C# Substitution Control"
      runat="server" />
  </cstemplate>
  <vbtemplate>
    <Acme:SourceRef
      RunSample="../../../samples/caching/substitution/PostCacheSubstitution2_vb.aspx"
      ViewSource="~/aspnet/samples/caching/substitution/PostCacheSubstitution2.src"
      Caption="VB Substitution Control"
      runat="server" />
  </vbtemplate>
</Acme:LangSwitch>
<br />

<h3>AdRotator Support for Post-Cache Substitution</h3>

Although it is possible to insert dynamic content from user code as demonstrated in the examples above, the most common way that page developers will access post-cache substitution behavior is through ASP.NET server controls that implement direct support for it.  For example, the ASP.NET AdRotator control implements support for post-cache substitution in order to render unique Advertisements on each request, regardless of whether the parent page is cached.
<br />

<pre class="code">
&lt;%@ OutputCache Duration="60" VaryByParam="none" %&gt;

&lt;form runat="server"&gt;
  &lt;asp:AdRotator AdvertisementFile="Ads.xml" runat="server"/&gt;
&lt;/form&gt;
</pre>

Internally, the AdRotator creates a standalone in-memory object with a single callback method that can render Ad content, to be passed as the delegate to the <code>Response.WriteSubstitution</code> method.  This render object retains enough context for each of the AdRotator's user defined properties to be able to generate Ads independently of the page.  

</asp:Content>
