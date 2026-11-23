<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix="Acme" Namespace="Acme" %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx" %>
<asp:Content ContentPlaceHolderID="MainBody" runat="Server">
    <h2>
        New Caching Features in ASP.NET 2.0</h2>
    For most web applications, caching in some form can be a very effective strategy
    in improving performance and scalability. ASP.NET 1.0 offered several forms of caching
    that allowed web applications to minimize expensive processing, reduce network trips
    to the backend, and alleviate database load: generic data caching, output caching,
    and fragment caching. (To learn more about these features, please visit the ASP.NET
    1.0 Quickstarts).
    <br />
    <br />
    ASP.NET 2.0 has expanded on these features, making them more powerful, easier to
    use, and easier to manage. The following improvements are included:
    <br />
    <br />
    <table class="table">
        <tr>
            <th width="25%">
                Feature</th>
            <th>
                Description</th>
        </tr>
        <tr>
            <td colspan="2">
                <b>Data Cache</b></td>
        </tr>
        <tr>
            <td>
                Custom Cache Dependencies</td>
            <td>
                Ability to implement custom dependencies to enable efficient invalidation of cached
                objects based on changes to arbitrary resources.
            </td>
        </tr>
        <tr>
            <td>
                SQL Server Cache Dependency</td>
            <td>
                A dependency type to monitor changes of data in a SQL Server database. This dependency
                can be used programmatically, as well as declaratively for output cache and fragment
                cache.</td>
        </tr>
        <tr>
            <td>
                Cache Configuration</td>
            <td>
                Ability to control cache behavior from configuration.</td>
        </tr>
        <tr>
            <td colspan="2">
                <b>Output Caching</b></td>
        </tr>
        <tr>
            <td>
                Post-Cache Substitution</td>
            <td>
                API to insert dynamic regions into response for every request that returns an output
                cached page.</td>
        </tr>
        <tr>
            <td>
                Cache Profiles</td>
            <td>
                Ability to define and manage groups of output cache settings in configuration, instead
                of placing them in an individual page.</td>
        </tr>
        <tr>
            <td colspan="2">
                <b>Fragment Caching</b></td>
        </tr>
        <tr>
            <td>
                Fragment Caching API</td>
            <td>
                API to control caching settings for a user control programmatically.</td>
        </tr>
    </table>
    <br />
    <h3>
        Custom Cache Dependencies</h3>
    ASP.NET 2.0 opened the <b>System.Web.Caching.CacheDependency</b> class for derivation,
    enabling anyone to write their own implementation of a cache dependency. By developing
    your own cache dependency, you can take advantage of the cache invalidation mechanism
    to keep the cached content current with the data that was used to construct it.
    This is a more efficient and reliable way to ensure data validity, and enable cache
    synchronization across web farms, than using frequent expiration.
    <br />
    <br />
    ASP.NET provides two dependency types built on top of CacheDependency: <b>AggregateCacheDependency</b>,
    which allows multiple dependencies to be aggregated for complex content types that
    depend on more then one type of resource, and <b>SqlCacheDependency</b>, which is
    described below.
    <h3>
        SQL Server Cache Dependency</h3>
    The SqlCacheDependency implementation of a custom dependency enables users to invalidate
    cache content based on data changes in the SQL Server Database. Two types invalidation
    services provided:
    <ul>
        <li>
        Table-based, allowing to detect changes to data within one or more tables
        <li>
        Command-based, allowing to detect changes to result sets of arbitrary queries issued
        by one or more SqlCommand instances
    </ul>
    The SQL Server Cache Dependency can be used programmatically with the Cache API.
    Many of ASP.NET features, including output cache, fragment cache, and data source
    controls also enable use of SQL cache dependency declaratively.
    <br />
    <br />
    In the example below, an page that displays the contents of the Authors table in
    the Pubs database takes advantage of SQL cache dependency on the data source control
    to stay up to date with changes to the data. The page indicates the configured connection
    string and table to monitor for changes in the SqlCacheDependency proeprty of the
    data source control, using the syntax, <code>Pubs:Authors</code>.
    <br />
    <br />
    <Acme:LangSwitch runat="server">
        <cstemplate>
        <Acme:SourceRef
        RunSample="../../samples/caching/cachedependency/cachedependency_cs/CacheDependency.aspx"
        ViewSource="~/aspnet/samples/caching/cachedependency/CacheDependency.src"
        Caption="C# SqlCacheDependency"
        runat="server" />
  </cstemplate>
        <vbtemplate>
        <Acme:SourceRef
        RunSample="../../samples/caching/cachedependency/cachedependency_vb/CacheDependency.aspx"
        ViewSource="~/aspnet/samples/caching/cachedependency/CacheDependency.src"
        Caption="VB SqlCacheDependency"
        runat="server" />
  </vbtemplate>
    </Acme:LangSwitch>
    <br />
    The data source control caches the data indefinitely, avoiding the expense of database
    querying on every render. However, when you edit the data, either through the GridView
    edit functionality or externally, the cached response is invalidated and the data
    source control reloads the data.
    <h3>
        Cache Configuration</h3>
    ASP.NET 2.0 provides configuration settings to allow you to have more control over
    the cache behavior for the entire application. Armed with these settings, you can
    debug your application by turning specific cache features like expiration and dependencies
    on and off. You can also control the behavior of individual features such as SQL
    cache dependencies.
    <br />
    <br />
    The caching settings are located in the
    <caching> section group.
<br /><br />
<span class="subhead">Post Cache Substitution</span>
<br/><br/>
In ASP.NET 1.0, pages that were mostly static but contained a small dynamic region, such as username or current time, were frequently forced to either not use caching or partition the page into multiple user controls cached with fragment caching.  ASP.NET 2.0 enables these pages to take advantage of output caching, by allowing output cached pages to insert dynamic content on every request.  In the example below, the output cached page inserts a dynamic callback to a static method that returns the current date with the <code>Response.WriteSubstitution</code> API.  This callback executes on every request, and the result gets inserted into the cached response chain that is served from output cache.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/caching/substitution/PostCacheSubstitution_cs.aspx"
        ViewSource="~/aspnet/samples/caching/substitution/PostCacheSubstitution.src"
        Caption="C# Post-Cache Substitution"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/caching/substitution/PostCacheSubstitution_vb.aspx"
        ViewSource="~/aspnet/samples/caching/substitution/PostCacheSubstitution.src"
        Caption="VB Post-Cache Substitution"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<h3>Cache Profiles</h3>

Cache profiles allow cache settings for hundreds of pages to be deployed and managed centrally from configuration.  Individual pages can still override the settings in the profile by specifying them in the <code>&lt;%@ OutputCache %&gt;</code> directive, but for manageability purposes they can simply inherit most or all settings from a cache profile.  In the example below, the page uses a cache profile specified with a CacheProfile attribute, with the cache settings located in the profile entry in the <outputCacheSettings> section of the <caching> configuration section group.
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/caching/profiles/CacheProfiles_cs.aspx"
        ViewSource="~/aspnet/samples/caching/profiles/CacheProfiles.src"
        Caption="C# Cache Profiles"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/caching/profiles/CacheProfiles_vb.aspx"
        ViewSource="~/aspnet/samples/caching/profiles/CacheProfiles.src"
        Caption="VB Cache Profiles"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<h3>Fragment Caching API</h3>

The Fragment Caching ControlCachePolicy API allows the user control or page developer to programmatically control caching settings for a fragment cached user control.  A variety of advanced scenarios are made possible by this feature, which were not available in ASP.NET 1.0 that only allowed declarative specification of the cache settings for fragment cache.  In the example below, the user control can determine whether or not it should be cached based on a querystring parameter.  The control varies by the “cache” parameter, and programmatically disables its own caching via the <code>ControlCachePolicy.Enabled</code> property when the parameter has the value of “false”.
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/caching/controlcachepolicy/ControlCachePolicy_cs.aspx"
        ViewSource="~/aspnet/samples/caching/controlcachepolicy/ControlCachePolicy.src"
        Caption="C# Control Cache Policy"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/caching/controlcachepolicy/ControlCachePolicy_vb.aspx"
        ViewSource="~/aspnet/samples/caching/controlcachepolicy/ControlCachePolicy.src"
        Caption="VB Control Cache Policy"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
</asp:Content>
