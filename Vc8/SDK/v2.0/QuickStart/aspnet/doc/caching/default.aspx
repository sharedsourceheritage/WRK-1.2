<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix="Acme" Namespace="Acme" %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx" %>
<asp:Content ContentPlaceHolderID="MainBody" runat="Server">
    <h2>
        Caching For Performance</h2>

    <div class="new">
        <h3>
            What's New in 2.0</h3>

<ul>
<li><b>Flexible Development Features - </b> ASP.NET 2.0 includes new caching features such as
<a href="data.aspx#dependencies">Custom Dependencies</a>, the <a href="fragment.aspx#api">Fragment Caching API</a> and <a href="output.aspx#postcache">Post-cache Substitution</a>
to enable more scenarios and improve the overall development experience.
<br /><br />
<li><b>Increased Manageability - </b> ASP.NET 2.0 improves deployment and maintenance of caching functionality with 
features like <a href="config.aspx#profiles">Cache Profiles</a> and <a href="config.aspx">Cache Configuration</a>.
<br /><br />
<li><b>Better Performance and Scalability - </b> New features such as <a href="SQLInvalidation.aspx">Sql Cache Invalidation</a>
are aimed at building more performant sites.
</ul>

This section discusses these and other caching features in ASP.NET 2.0.
    </div>

        <br />

        Caching is a technique widely used in computing to increase performance by keeping
        frequently accessed or expensive data in memory. In the context of a Web application,
        caching is used to retain pages or data across HTTP requests and reuse them without
        the expense of recreating them.

        <br /><br />

        ASP.NET has several kinds of caching that can be used by Web applications:</p>

    <table class="table"><tr><td width="15%">
        <asp:HyperLink ID="HyperLink1" NavigateUrl="output.aspx" runat="server">Output Caching</asp:HyperLink>
    </td><td>
    
        Output caching is useful when the contents of an entire page can be cached. On a
        heavily accessed site, caching frequently accessed pages for even a minute at a
        time can result in substantial throughput gains. While a page is cached by the output
        cache, subsequent requests for that page are served from the output page without
        executing the code that created it.
    
    </td></tr><tr><td>
        <asp:HyperLink ID="HyperLink2" NavigateUrl="fragment.aspx" runat="server">Fragment Caching</asp:HyperLink>
    </td><td>

        Sometimes it is not practical to cache an entire page - perhaps portions of the
        page must be created or customized for each request. In this case, it is often worthwhile
        to identify objects or data that are expensive to construct and are eligible for
        caching. Once these items are identified, they can be created once and then cached
        for some period of time. Additionally, fragment caching can be used to cache regions
        of a page's output.

    </td></tr><tr><td>
        <asp:HyperLink ID="HyperLink3" NavigateUrl="data.aspx" runat="server">Data Caching</asp:HyperLink>
    </td><td>

        Choosing the time to cache an item can be an interesting decision. For some items,
        the data might be refreshed at regular intervals or the data is valid for a certain
        amount of time. In that case, the cache items can be given an expiration policy
        that causes them to be removed from the cache when they have expired. Code that
        accesses the cache item simply checks for the absence of the item and recreates
        it, if necessary.

        <br /><br />

        The ASP.NET cache supports file and cache key dependencies, allowing developers
        to make a cache item dependent on an external file or another cache item. This technique
        can be used to invalidate items when their underlying data source changes.

    </td></tr><tr><td>
        <asp:HyperLink ID="HyperLink4" NavigateUrl="config.aspx" runat="server">Cache Configuration</asp:HyperLink>
    </td><td>

        ASP.Net 2.0 includes some new features to help with cache configuration. Cache profiles
        enable you to configure cache profiles in the configuration system, and then use
        those profiles on pages. This enables changes to caching for sets of pages to be
        made on a global basis. More options for customizing the cache performance have
        also been added.

    </td></tr></table>

</asp:Content>
