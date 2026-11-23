<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix="Acme" Namespace="Acme" %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainBody" runat="Server">
    <h2>
        Cache Configuration
    </h2>
    ASP.NET 2.0 includes new features for configuring the cache.
    <a name="profiles"></a>
    <h3>
        Cache Profiles</h3>
    Cache profiles allow cache settings for hundreds of pages to be deployed and managed
    centrally from configuration. Individual pages can still override the settings in
    the profile by specifying them in the <code>&lt;%@ OutputCache %&gt;</code> directive,
    but for manageability purposes they can simply inherit most or all settings from
    a cache profile. In the example below, the page uses a cache profile specified with
    a CacheProfile attribute, with the cache settings located in the profile entry in
    the <code>&lt;outputcachesettings&gt;</code> section of the <code>&lt;caching&gt;</code> configuration section
    group.
    <br />
    <br />
    <Acme:LangSwitch runat="server">
        <cstemplate>
        <Acme:SourceRef
        RunSample="../../samples/caching/profiles/CacheProfiles_cs.aspx"
        ViewSource="~/aspnet/samples/caching/profiles/CacheProfiles.src"
        Caption="C# Cache Profiles"
        runat="server" />
  </cstemplate>
        <vbtemplate>
        <Acme:SourceRef
        RunSample="../../samples/caching/profiles/CacheProfiles_vb.aspx"
        ViewSource="~/aspnet/samples/caching/profiles/CacheProfiles.src"
        Caption="VB Cache Profiles"
        runat="server" />
  </vbtemplate>
    </Acme:LangSwitch>
    <a name="properties"></a>
    <h3>
        Cache Properties in Configuration</h3>
    <p>
        ASP.NET 2.0 now includes support for configuring the resource allocation for the
        cache. The caching configuration sections are separated into 3 top-level sections,
        all contained within the <code>&lt;caching&gt;</code> section group, which is included under <code>&lt;system.web&gt;</code>:</p>
    <ul type="disc">
        <li><b>cache</b>. Contains application settings pertaining to the cache, including limiting the memory usage and disabling features. </li>
        <li><b>outputCache</b>. Contains application settings pertaining to the output cache, including disabling output or fragment caching.</li>
        <li><b>outputCacheSettings</b>. Contains cache settings that can be used by individual
            pages/controls within the app and can be declared at any level.</li>
    </ul>
    For more details on the cache configuration see the ASP.Net 2.0 documentation.
</asp:Content>
