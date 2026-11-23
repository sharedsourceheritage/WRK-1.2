<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx" %>
<%@ Register TagPrefix="Acme" Namespace="Acme" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainBody" runat="Server">
    <h2>
        Page Output Caching</h2>
    <p>
        Output caching is a powerful technique that increases request/response throughput
        by caching the content generated from dynamic pages. Output caching is enabled by
        default, but output from any given response is not cached unless explicit action
        is taken to make the response cacheable.
    </p>
    <p>
        To make a response eligible for output caching, it must have a valid expiration/validation
        policy and public cache visibility. This can be done using either the low-level
        <b>OutputCache</b> API or the high-level <b>@ OutputCache</b> directive. When output
        caching is enabled, an output cache entry is created on the first <b>GET</b> request
        to the page. Subsequent <b>GET</b> or <b>HEAD</b> requests are served from the output
        cache entry until the cached request expires.

        The output cache also supports variations of cached <b>GET</b> or <b>POST</b> name/value
        pairs.
    </p>
    <p>
        The output cache respects the expiration and validation policies for pages. If a
        page is in the output cache and has been marked with an expiration policy that indicates
        that the page expires 60 minutes from the time it is cached, the page is removed
        from the output cache after 60 minutes. If another request is received after that
        time, the page code is executed and the page can be cached again. This type of expiration
        policy is called absolute expiration - a page is valid until a certain time.
    </p>
    <a name="outputcache"></a>
    <h3>
        The Output Cache Directive</h3>
    <p>
        The following example demonstrates a simple way to output cache responses using
        the <b>@ OutputCache</b> directive. The example simply displays the time when the
        response was generated. To see output caching in action, invoke the page and note
        the time at which the response was generated. Then refresh the page and note that
        the time has not changed, indicating that the second response is being served from
        the output cache.
    </p>
    <Acme:LangSwitch runat="server">
        <cstemplate>
<Acme:SourceRef
  RunSample="../../samples/caching/output/outputcache1_cs.aspx"
  ViewSource="~/aspnet/samples/caching/output/outputcache1.src"
  Caption="C# Output Cache"
  runat="server" />
  </cstemplate>
        <vbtemplate>
<Acme:SourceRef
 RunSample="../../samples/caching/output/outputcache1_vb.aspx"
  ViewSource="~/aspnet/samples/caching/output/outputcache1.src"
  Caption="VB Output Cache"
  runat="server" />
  </vbtemplate>
    </Acme:LangSwitch>
    <p>
        The following directive activates output caching on the response:
    </p>
    <pre class="code">
&lt;%@ OutputCache Duration="60" VaryByParam="none"%&gt;
</pre>
    <p>
        This directive simply indicates that the page should be cached for 60 seconds and
        that the page does not vary by any <b>GET</b> or <b>POST</b> parameters. Requests
        received while the page is still cached are satisfied from the cache. After 60 seconds,
        the page is removed from the cache; the next request is handled explicitly and caches
        the page again.
    </p>

    <p>
        Of course, in the previous example, very little work is saved by output caching.
        The following example shows the same technique for output caching, but queries a
        database and displays the results in a grid.
    </p>
    <Acme:LangSwitch runat="server">
        <cstemplate>
<Acme:SourceRef
  RunSample="../../samples/caching/output/outputcache2_cs.aspx"
  ViewSource="~/aspnet/samples/caching/output/outputcache2.src"
  Caption="C# Output Cache 2"
  runat="server" />
  </cstemplate>
        <vbtemplate>
<Acme:SourceRef
    RunSample="../../samples/caching/output/outputcache2_vb.aspx"
  ViewSource="~/aspnet/samples/caching/output/outputcache2.src"
  Caption="VB Output Cache 2"
  runat="server" />
  </vbtemplate>
    </Acme:LangSwitch>
    <a name="varyby"></a>
    <h3>
        Vary By Parameters</h3>
    <p>
        In this, the application is modified slightly to allow the user to selectively query
        for authors in various states. This example demonstrates caching requests varying
        by the name/value pairs in the query string using the <b>VaryByParam</b> attribute
        of the <b>@ OutputCache</b> directive.</p>
    <pre class="code">
&lt;%@ OutputCache Duration="60" VaryByParam="state" %&gt;</pre>
    <p>
        For each state in the data set, there is a link that passes the desired state as
        part of the query string. The application then constructs the appropriate database
        query and shows authors belonging only to the selected state.
    </p>
    <p>
        Note that the first time you click the link for a given state, it generates a new
        timestamp at the bottom of the page. Thereafter, whenever a request for that state
        is resubmitted within a minute, you get the original timestamp indicating that the
        request has been cached.
    </p>
    <Acme:LangSwitch ID="LangSwitch3" runat="server">
        <cstemplate>
<Acme:SourceRef
  RunSample="../../samples/caching/output/outputcache3_cs.aspx"
  ViewSource="~/aspnet/samples/caching/output/outputcache3.src"
  Caption="C# Output Cache VaryByParam"
  runat="server" />
  </cstemplate>
        <vbtemplate>
<Acme:SourceRef
  RunSample="../../samples/caching/output/outputcache3_vb.aspx"
  ViewSource="~/aspnet/samples/caching/output/outputcache3.src"
  Caption="VB Output Cache VaryByParam"
  runat="server" />
  </vbtemplate>
    </Acme:LangSwitch>
    <a name="sqlcache"></a>
    <h3>
        SQL Cache Notification <span class="newinline">New in 2.0</span></h3>
    <p>
        In the previous example, the data was cached for 60 seconds, regardless of whether
        the data has changed in the database. SQL cache invalidation enables you to make
        the cache entry dependent on the database, so the cache entry will only be cleared
        when data in the database is changed. See the <a href="SQLInvalidation.aspx">SQL Cache
            Notification page</a> for more details.
    </p>
    <a name="postcache"></a>
    <h3>
        Post-cache Substitution <span class="newinline">New in 2.0</span></h3>
    <p>In ASP.NET 1.0, pages that were mostly static but contained a small dynamic region,
    such as username or current time, were frequently forced to either not use caching
    or partition the page into multiple user controls cached with fragment caching.
    ASP.NET 2.0 enables these pages to take advantage of output caching, by allowing
    output cached pages to insert dynamic content on every request. </p>
    <p>
    In the example below,
    the output cached page inserts a dynamic callback to a static method that returns
    the current date with the <code>Response.WriteSubstitution</code> API. This callback
    executes on every request, and the result gets inserted into the cached response
    chain that is served from output cache.
    </p>
    <Acme:LangSwitch ID="LangSwitch1" runat="server">
        <cstemplate>
        <Acme:SourceRef
        RunSample="../../samples/caching/substitution/PostCacheSubstitution_cs.aspx"
        ViewSource="~/aspnet/samples/caching/substitution/PostCacheSubstitution.src"
        Caption="C# Post-Cache Substitution"
        runat="server" />
  </cstemplate>
        <vbtemplate>
        <Acme:SourceRef
        RunSample="../../samples/caching/substitution/PostCacheSubstitution_vb.aspx"
        ViewSource="~/aspnet/samples/caching/substitution/PostCacheSubstitution.src"
        Caption="VB Post-Cache Substitution"
        runat="server" />
  </vbtemplate>
    </Acme:LangSwitch>
    <p>
    The following sample performs the same action as the sample above, but uses a <code>asp:Substitution</code> control to insert the dynamic content.
    </p>
      <Acme:LangSwitch ID="LangSwitch4" runat="server">
        <cstemplate>
        <Acme:SourceRef
        RunSample="../../samples/caching/substitution/PostCacheSubstitution2_cs.aspx"
        ViewSource="~/aspnet/samples/caching/substitution/PostCacheSubstitution2.src"
        Caption="C# Substitution Control"
        runat="server" />
  </cstemplate>
        <vbtemplate>
        <Acme:SourceRef
        RunSample="../../samples/caching/substitution/PostCacheSubstitution2_vb.aspx"
        ViewSource="~/aspnet/samples/caching/substitution/PostCacheSubstitution2.src"
        Caption="VB Substitution Control"
        runat="server" />
  </vbtemplate>
    </Acme:LangSwitch>
    <a name="cacheapi"></a>
    <h3>
        Using the Cache API</h3>
    <p>
        Applications that want more control over the HTTP headers related to caching can
        use the functionality provided by the <b>System.Web.HttpCachePolicy</b> class. The
        following example shows the code equivalent to the page directives used in the previous
        samples.</p>
    <Acme:TabControl runat="server">
<Tab Name="C#">
Response.Cache.SetExpires(DateTime.Now.AddSeconds(60));
Response.Cache.SetCacheability(HttpCacheability.Public);
</Tab>

<Tab Name="VB">
Response.Cache.SetExpires(Now.AddSeconds(60))
Response.Cache.SetCacheability(HttpCacheability.Public)
</Tab>
    </Acme:TabControl>
    <p>
        To make this a sliding expiration policy, where the expiration time out resets each
        time the page is requested, set the <b>SlidingExpiration</b> property as shown in
        the following code.
    </p>
    <Acme:TabControl runat="server">
<Tab Name="C#">
Response.Cache.SetExpires(DateTime.Now.AddSeconds(60));
Response.Cache.SetCacheability(HttpCacheability.Public);
Response.Cache.SetSlidingExpiration(true);
</Tab>

<Tab Name="VB">
Response.Cache.SetExpires(Now.AddSeconds(60))
Response.Cache.SetCacheability(HttpCacheability.Public)
Response.Cache.SetSlidingExpiration(True)
</Tab>
    </Acme:TabControl>

<br />
        <b>Note:</b> When sliding expiration is enabled (<b>SetSlidingExpiration(true)</b>
        ), a request made to the origin server always generates a response. Sliding expiration
        is useful in scenarios where there are downstream caches that can satisfy client
        requests, if the content has not expired yet, without requesting the content from
        the origin server.


</asp:Content>
