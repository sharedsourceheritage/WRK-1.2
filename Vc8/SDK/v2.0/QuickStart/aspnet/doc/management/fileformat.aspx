<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Configuration File Format</h2>
<p>
ASP.NET configuration files are XML text files &mdash; each named <b>web.config</b> &mdash; that can
appear in any directory of an ASP.NET Web application.

<p>
Each web.config file applies configuration settings to the directory it is located in, 
and to all virtual child directories beneath it.   Settings in child directories can 
optionally override or modify settings specified in parent directories. 
A root configuration file &mdash; %windir%\Microsoft.NET\Framework\<i>version</i>\config\<b>machine.config</b>
&mdash; provides default configuration settings for all web applications
on the entire machine that run a specific version of ASP.NET.
ASP.NET configures IIS to prevent direct browser access to web.config files to ensure that their 
values cannot become public, and attempts to access them will cause ASP.NET to return
an "403: Access Forbidden" error.

<p>
At run time ASP.NET uses these web.config configuration files to hierarchically compute 
a unique collection of settings for each incoming URL request.
These settings are calculated only once and then cached across subsequent requests; ASP.NET automatically
watches for file changes and will invalidate the cache if any of the configuration files change.
<p>
For example, the configuration settings for the URL http://myserver/myapplication/mydir/page.aspx would be computed by applying
web.config file settings in the following order:
<p>
<pre class="code">
<b>1. Base configuration settings for machine.</b>
C:\WinNT\Microsoft.NET\Framework\v2.0.<i>xxxxx</i>\config\machine.config

<b>2. Root web configuration settings for machine.</b>
C:\WinNT\Microsoft.NET\Framework\v2.0.<i>xxxxx</i>\config\web.config

<b>3. Overridden by the configuration settings for the site (or the root application).</b>
C:\inetpub\wwwroot\web.config

<b>4. Overridden by application configuration settings.</b>
D:\MyApplication\web.config

<b>5. Overridden by subdirectory configuration settings.</b>
D:\MyApplication\MyDir\web.config
</pre>

<p>
If a web.config file is present at the root directory for a site, for example "Inetpub\wwwroot", its
configuration settings will apply to every application in that site.  The presence of a web.config
file within a given directory or application root is completely optional.  If a web.config file is not
present, all configuration settings for the directory are automatically inherited from the parent directory.

<a name="SectionsAndSectionGroups"></a>
<h3>Configuration Sections and Section Groups</h3>

A web.config file is an XML-based text file that can contain standard XML document elements,
including well-formed tags, comments, text, cdata, and so on. The file may be ANSI, UTF-8, or Unicode; the
system automatically detects the encoding.

The root element of a web.config file is always a <b>&lt;configuration&gt;</b> tag.  ASP.NET and end-user settings are
then encapsulated within the tag, as follows:
<br><br>
<pre class="code">
&lt;configuration&gt;
    &lt;!- Configuration settings would go here. --&gt;
&lt;/configuration&gt;</pre>
<br>
ASP.NET configuration settings are represented within configuration
tag sections, also nested within a <b>&lt;configuration&gt;</b> tag (and, optionally, within section group tags).
For example, in the sample below, the tag <b>&lt;pages&gt;</b> is the configuration section that defines
configuration settings for the ASP.NET page compiler.
Note: tag names in a configuration file are case-sensitive and must be typed exactly
as shown.  Various attributes and settings for ASP.NET are also case-sensitive and will not be examined by the
configuration runtime if the case does not match.
<p>
Configuration section groups allow hierarchical grouping of sections for organizational purposes.  
For example, all built-in ASP.NET sections belong in the <b>&lt;system.web&gt;</b>
section group. Section groups may appear inside other section groups.
<p>
In the following example, the configuration file contains configuration settings
for the built-in <b>&lt;pages&gt;</b> ASP.NET section. This section is contained within
the built in section group called <b>&lt;system.web&gt;</b>. 
<br><br>
<pre class="code">
&lt;configuration&gt;
    &lt;system.web&gt;
        &lt;pages enableSessionState="true" /&gt;
    &lt;/system.web&gt;
&lt;/configuration&gt;</pre>
<br>
<a name="AddingASection"></a>
<h3>Adding a Configuration Section</h3>
The ASP.NET configuration infrastructure makes no
assumptions regarding the file format or supported settings within a web.config file.  Instead, it delegates
the processing of web.config data to configuration section handlers, .NET Framework classes
that inherit from the <b>ConfigurationSection</b> class.  An individual
<b>ConfigurationSection</b> declaration needs to appear only once, typically in the machine.config file.
The web.config files in child directories automatically inherit this
declaration.  Configuration section handlers are declared within a web.config file using section
tag directives nested within a <b>&lt;configSections&gt;</b> tag.  Section tags may be further qualified
by section group tags to organize them into logical groups.  Each section tag
identifies a tag name denoting a specific section of configuration data and an associated
<b>ConfigurationSection</b>-based class that processes it.

<p>
In the following example, the configuration file declares a new section, called
<b>&lt;mySection&gt;</b>.
<br><br>
<pre class="code">
&lt;configuration&gt;
    &lt;configSections&gt;
        &lt;section name="mySection" type="SettingsClasses.MySectionSettings" /&gt;
    &lt;/configSections&gt;
    &lt;mySection .../&gt; 
&lt;/configuration&gt;</pre>
<br>

<a name="CollectionSettings"></a>
<h3>Collection Settings</h3>
Many of the configuration sections built into ASP.NET include settings that are collections
of elements. Examples of collection settings include HTTP handler and module mappings, 
and providers for application services. Like all other settings, collection settings are
hierarchically computed - an application's web.config, for example, can add to or remove from
a collection of settings applied at the machine level.
<p>
Most collection settings have a common syntax for adding and removing elements.
The <b>&lt;add&gt;</b> tag adds a new element to the collection. This tag usually includes
attributes to define the element.
The <b>&lt;remove&gt;</b> tag removes an existing element from the collection, and usually includes
attributes that uniquely identify the element to remove.
The <b>&lt;clear&gt;</b> tag clears the entire collection, removing any elements that
were hierarchically inherited by the current level.
<p>
In the following example, the configuration file adds a new HTTP handler mapping for the
".webservice" file type, and removes the existing handler for the ".asmx" file type.
<pre class="code">
&lt;configuration&gt;
    &lt;system.web&gt;
        &lt;httpHandlers&gt;
            &lt;add path="*.webservice" verb="GET, POST" 
                 type="MyHandlers.WebServiceHandler" /&gt;
            &lt;remove path="*.asmx" verb="GET, POST" /&gt;
        &lt;/httpHandlers&gt;
    &lt;/system.web&gt;
&lt;/configuration&gt;</pre>
<br>

<p>
<a name="UsingLocationAndPath"></a>
<h3>Using Location and Path</h3>
By default, all configuration settings defined within the top-level <b>&lt;configuration&gt;</b> tag are applied
to the current directory location of the containing web.config file and to all of the child paths
beneath it. You can optionally apply configuration settings to specific child paths under the current
config file by using the <b>&lt;location&gt;</b> tag with an appropriately constraining <b>path</b> attribute. If the
config file is the main machine.config or the root web.config file, you can apply settings to specific virtual directories or
applications and the virtual path needs to include the friendly name of the site like, 
&lt;location path="Default Web Site/EnglishPages/OneJapanesePage.aspx"&gt,
which is also shown in the example below. If the config file is a web.config file at a lower level,
you can apply settings to a specific file, child directory, virtual directory, or application.
<p>
<pre class="code">
&lt;configuration&gt;

  &lt;location path="EnglishPages"&gt;
    &lt;system.web&gt;
      &lt;globalization
        requestEncoding="iso-8859-1"
        responseEncoding="iso-8859-1"
      /&gt;
    &lt;/system.web&gt;
  &lt;/location&gt;

  &lt;location path="Default Web Site/EnglishPages/OneJapanesePage.aspx"&gt;
    &lt;system.web&gt;
      &lt;globalization
        requestEncoding="Shift-JIS"
        responseEncoding="Shift-JIS"
      /&gt;
    &lt;/system.web&gt;
  &lt;/location&gt;

&lt;/configuration&gt;
</pre>

<a name="LockingDown"></a>
<h3>Locking Down Configuration Settings</h3>
In addition to using the <b>&lt;location&gt;</b> tag to override configuration settings for individual paths, 
you can also use this tag to lock down settings at a higher level, 
so that settings cannot be overridden by another configuration file 
further down the configuration hierarchy.  To lock down a group of settings, you can specify an 
<b>allowOverride</b> attribute on the surrounding <b>&lt;location&gt;</b> tag and set it to false. 
The following configuration disables and locks down session state for two different applications.

<p>
<pre class="code">
&lt;configuration&gt;

  &lt;location path="app1" allowOverride="false"&gt;
    &lt;system.web&gt;
        &lt;sessionState enabled="false" /&gt;
    &lt;/system.web&gt;
  &lt;/location&gt;

  &lt;location path="app2" allowOverride="false"&gt;
    &lt;system.web&gt;
        &lt;sessionState enabled="false" /&gt;
    &lt;/system.web&gt;
  &lt;/location&gt;

&lt;/configuration&gt;
</pre>

<p>
If a user overrides these settings in another configuration file that is lower in the 
application configuration hierarchy, the configuration system will throw an error at 
runtime when the application is run.

<p>

The ASP.NET 2.0 configuration system now also includes a number of features to lock individual
elements and attributes of configuration, using the <b>lockItems</b> and 
<b>lockCollections</b> attributes. For more information, consult your product
documentation.


<p>
<a name="StandardSections"></a>
<h3>Standard ASP.NET Configuration Sections</h3>

ASP.NET ships with a number of standard configuration section handlers that are used to process
configuration settings within web.config files.  The following table provides an alphabetic list of the built-in sections, 
with brief descriptions and pointers to more information.
<p>

<table class="table" width="90%" cellpadding=3>
<tr>
<th width="200">Section Name</th><th width="*">Description</th>
</tr>
<tr>
<td><b>&lt;anonymousIdentification&gt;</b></td>
<td>Responsible for controlling how anonymous users are tracked in the system.
For more information, see the <a href="../profile/default.aspx">Storing User Profiles</a> section of this tutorial.</td>
</tr>
<tr>
<td><b>&lt;authentication&gt;</b></td>
<td>Responsible for controlling the authentication settings on the applications.
Applications can be configured to use Windows or Forms authentication.
For more information, see the <a href="../security/default.aspx">Securing Your Application</a> section of this tutorial.</td>
</tr>
<tr>
<td><b>&lt;authorization&gt;</b></td>
<td>Responsible for controlling access to individual URLs based on the authenticated user's privileges.
Typically, this setting is set at the individual file level using &lt;location&gt; tags.
For more information, see the <a href="../security/default.aspx">Securing Your Application</a> section of this tutorial.</td>
</tr>
<tr>
<td><b>&lt;browserCaps&gt;</b></td>
<td>Responsible for controlling the settings of the browser capabilities component.  
For more information, see the <a href="../extensibility.aspx">Extending ASP.NET</a> section of this tutorial.</td>
</tr>
<tr>
<td><b>&lt;caching&gt;</b></td>
<td>Section group responsible for controlling how the ASP.NET cache operates.
For more information, see the <a href="../caching/default.aspx">Caching for Performance</a> section of this tutorial.</td>
</tr>
<tr>
<td><b>&lt;compilation&gt;</b></td>
<td>Responsible for all compilation settings used by ASP.NET.  
For more information, see the <a href="../pages/default.aspx">Building a Web Application</a> section of this tutorial.</td>
</tr>
<tr>
<td><b>&lt;customErrors&gt;</b></td>
<td>Responsible for customizing error pages returned by the application to the browser.
</tr>
<tr>
<td><b>&lt;globalization&gt;</b></td>
<td>Responsible for configuring the globalization settings of an application.  
For more information, see the <a href="../localization/default.aspx">Internationalizing Your Application</a> section of this tutorial.</td>
</tr>
<tr>
<td><b>&lt;healthMonitoring&gt;</b></td>
<td>Responsible for controlling how the server monitors the application for exceptional events, and
how it handles them.
For more information, see the <a href="../monitoring/default.aspx">Monitoring Your Applications</a> section of this tutorial.</td>
</tr>
<tr>
<td><b>&lt;hostingEnvironment&gt;</b></td>
<td>Responsible for configuring the server environment that hosts ASP.NET applications.</td>
</tr>
<tr>
<td><b>&lt;httpCookies&gt;</b></td>
<td>Responsible for controlling how ASP.NET writes cookies for built-in features such
as forms authentication and session state.</td>
</tr>
<tr>
<td><b>&lt;httpModules&gt;</b></td>
<td>Responsible for configuring HTTP modules within an application. 
HTTP modules participate in the processing of every request into an application.  
Common uses include security and logging.</td>
</tr>
<tr>
<td><b>&lt;httpHandlers&gt;</b></td>
<td>Responsible for mapping incoming URLs to <b>IHttpHandler</b> classes. 
Also responsible for mapping incoming URLs to <b>IHttpHandlerFactory</b> classes.  
Data represented in <b>&lt;httpHandlers&gt;</b> sections are hierarchically inherited by subdirectories.  
For more information, see the <a href="../applications/httphandlers.aspx">Http Handlers and Factories</a> section of this tutorial.</td>
</tr>
<tr>
<td><b>&lt;httpRuntime&gt;</b></td>
<td>Responsible for configuring the ASP.NET HTTP runtime.</td>
</tr>
<tr>
<td><b>&lt;identity&gt;</b></td>
<td>Responsible for configuring the Windows user identity used to run an application, 
and for controlling user impersonation.</td> 
</tr>
<tr>
<td><b>&lt;machineKey&gt;</b></td>
<td>Responsible for configuring the encryption key used to encrypt secrets such
as forms authentication tickets.</td>
</tr>
<tr>
<td><b>&lt;membership&gt;</b></td>
<td>Responsible for configuring settings and providers for the ASP.NET membership
system. For more information on membership, see the
<a href="../security/membership.aspx">Using the Membership and Role Manager APIs</a> section of this tutorial.</td>
</tr>
<tr>
<td><b>&lt;mobileControls&gt;</b></td>
<td>Responsible for configuring mobile controls settings, such as adapter mappings for different mobile devices.</td>
</tr>
<tr>
<td><b>&lt;pages&gt;</b></td>
<td>Responsible for configuring settings for ASP.NET pages, including defaults for settings that can
be set from the &lt;%@ Page &gt; directive of a page, such as compilation language, session
state usage, and theme. 
</tr>
<tr>
<td><b>&lt;processModel&gt;</b></td>
<td>Responsible for configuring the ASP.NET process model 
settings on IIS Web server systems.  </td>
</tr>
<tr>
<td><b>&lt;profile&gt;</b></td>
<td>Responsible for configuring settings and providers for the ASP.NET user profile system.
For more information, see the <a href="../profile/default.aspx">Storing User Profiles</a> section of this tutorial.</td>
</tr>
<tr>
<td><b>&lt;roles&gt;</b></td>
<td>Responsible for configuring settings and providers for the ASP.NET role manager.
For more information on the ASP.NET role manager, see the
<a href="../security/membership.aspx">Using the Membership and Role Manager APIs</a> section of this tutorial.</td>
</tr>
<tr>
<td><b>&lt;sessionPageState&gt;</b></td>
<td>Responsible for configuring how session state can be used to save page viewstate, 
for small devices that have limited page size or bandwidth requirements.</td>
</tr>
<tr>
<td><b>&lt;sessionState&gt;</b></td>
<td>Responsible for configuring the session state HTTP module.  
For more information, see the <a href="../applications/state.aspx">Managing State</a> section of this tutorial.</td>
</tr>
<tr>
<td><b>&lt;siteMap&gt;</b></td>
<td>Responsible for configuring settings and providers for the ASP.NET site navigation system.
For more information, see the <a href="../navigation/default.aspx">Creating a Site Navigation Hierarchy</a> section of this tutorial.</td>
</tr>
<tr>
<td><b>&lt;trace&gt;</b></td>
<td>Responsible for configuring the ASP.NET trace service. 
For more information, see the <a href="../monitoring/tracing.aspx">Tracing</a> section of this tutorial.</td>
</tr>
<tr>
<td><b>&lt;trust&gt;</b></td>
<td>Responsible for configuring the trust level used to run an ASP.NET application. 
Applications running under limited-trust environments such as hosted servers can be configured to
run under a reduced trust level, with fewer capabilities than a fully trusted application.</td>
</tr>
<tr>
<td><b>&lt;urlMappings&gt;</b></td>
<td>Responsible for configuring URL mappings used by the ASP.NET site navigation system.
For more information, see the <a href="../navigation/default.aspx">Creating a Site Navigation Hierarchy</a> section of this tutorial.</td>
</tr>
<tr>
<td><b>&lt;webParts&gt;</b></td>
<td>Responsible for controlling settings used by ASP.NET web parts.
For more information, see the <a href="../webparts/default.aspx">Personalization Using Web Parts</a> section of this tutorial.</td>
</tr>
<tr>
<td><b>&lt;webServices&gt;</b></td>
<td>Responsible for configuring ASP.NET web services.
For more information, see the <a href="../../../webservices">ASP.NET Web Services</a> Quickstart tutorial.</td>
</tr>
<tr>
<td><b>&lt;xhtml11Conformance&gt;</b></td>
<td>Responsible for controlling XHTML conformance settings of ASP.NET controls.
You can use these settings to control whether an ASP.NET application renders XHTML conformant output,
or remains backward compatible with markup generated by earlier versions of ASP.NET.
</tr>
</table>

<p>
<b>Optional Attributes for Section Definitions</b> - 
The following attributes can be optionally specified in the <b>&lt;section&gt;</b> element defining
a configuration section, to control how the section can be configured.
These attributes are applicable only to ASP.NET applications,
and are ignored by the configuration system when running other types of applications.
<p>
<table class="table" width="90%" cellpadding=3>
<tr VALIGN="top">
<TH width=31%>Attribute</TH>
<TH>Description</TH>
</tr>
<tr VALIGN="top">
<td><b>allowDefinition</b></td>
<td>Specifies which configuration file the section can be used in. Use one of the following values:
<dl>
<dt><b>Everywhere</b></dt>

<dd>Allows the section to be used in any configuration file. This is the default.</dd>

<dt><b>MachineOnly</b></dt>

<dd>Allows the section to be used only in the machine configuration file (Machine.config).</dd>

<dt><b>MachineToApplication</b></dt>

<dd>Allows the section to be used in the machine configuration file, the root web.config file,
or the web.config file of any virtual directory defined to be an application.</dd>
<dt><b>MachineToWebRoot</b></dt>

<dd>Allows the section to be used in the machine configuration file or the root web.config file.</dd>
</dl>
</td>
</tr>
<tr VALIGN="top">
<td><b>allowLocation</b></td>
<td>Determines whether the section can be used within the <b>&lt;location&gt;</b> element. Use one of the following values:
<dl>
<dt><b>true</b></dt>

<dd>Allows the section to be used within the <b>&lt;location&gt;</b> element. This is the default.</dd>

<dt><b>false</b></dt>

<dd>Does not allow the section to be used within the <b>&lt;location&gt;</b> element.</dd>
</dl>
</td>
</tr>
</Table>
<br /><br />

</asp:Content>

